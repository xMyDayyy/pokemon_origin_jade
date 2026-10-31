#!/usr/bin/env python3
"""Shared data layer for Origin Jade analysis tools (jade build, POKEMON_HNS).

Loads maps, layouts, metatile behaviours, map sections, item data and the
event scripts exactly as far as the static tools need them. Nothing here
changes the repository. Standard library only; needs a host C compiler
(cc, or $CC) for the constant values, like tools/check_flags.py.

Main entry points:
    world = World()                 # maps, layouts, tilesets, map sections
    scripts = ScriptDB(world.macros)  # data/event_scripts.s, preprocessed
    grid = world.grid(map_id)       # collision, elevation, behaviour per tile

Usage from another tool (run with python3 -I, so add tools/ to sys.path):
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import oj_world
"""

import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from array import array

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CPP_DEFINES = ["-DPOKEMON_HNS", "-DMODERN=1", "-DTESTING=0"]

# Map game_version of the maps the jade build uses (D-018).
ACTIVE_GAME_VERSION = "hns"


def repo_path(*parts):
    return os.path.join(REPO, *parts)


def rel(path):
    return os.path.relpath(path, REPO)


def source_revision():
    """Commit of the checked tree, the newest commit with game data (outside
    tools/) if older, and the count of changed tracked files outside tools/,
    e.g. "a91b54ee0a (Daten wie 3525d22e71) + 2 geänderte Dateien"."""
    git = shutil.which("git")
    if not git:
        return "unbekannt (kein git)"
    try:
        head = subprocess.run([git, "-C", REPO, "rev-parse", "--short=10", "HEAD"],
                              capture_output=True, text=True, timeout=30)
        if head.returncode != 0:
            return "unbekannt (kein Git-Baum)"
        data = subprocess.run([git, "-C", REPO, "log", "-1", "--format=%h", "--abbrev=10",
                               "--", ".", ":(exclude)tools"], capture_output=True, text=True, timeout=60)
        status = subprocess.run([git, "-C", REPO, "status", "--porcelain", "--untracked-files=no"],
                                capture_output=True, text=True, timeout=120)
    except (OSError, subprocess.SubprocessError):
        return "unbekannt"
    changed = [ln for ln in status.stdout.splitlines() if ln[3:] and not ln[3:].startswith("tools/")]
    rev = head.stdout.strip()
    data_rev = data.stdout.strip()
    if data_rev and data_rev != rev:
        rev += " (Daten wie %s)" % data_rev
    return rev + (" + %d geänderte Dateien" % len(changed) if changed else "")


# ---------------------------------------------------------------------------
# C macros and constant expressions
# ---------------------------------------------------------------------------

def compiler():
    cc = os.environ.get("CC") or shutil.which("cc") or shutil.which("gcc") or shutil.which("clang")
    if not cc:
        sys.exit("This tool needs a host C compiler (cc/gcc/clang or $CC).")
    return cc


_TOKEN = re.compile(r"\s*(0[xX][0-9a-fA-F]+[uUlL]*|\d+[uUlL]*|[A-Za-z_]\w*|<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%()<>!~&|^?:,])")


class Macros:
    """Object-like macros of the jade build plus gas symbols from asm/macros.

    Generated headers that only exist after a build are replaced by empty
    stubs, so a fresh checkout works.
    """

    def __init__(self, headers):
        self.defs = {}
        self._cache = {}
        self._load_cpp(headers)
        self._load_enums(headers)
        self._load_gas_symbols()

    def _load_cpp(self, headers):
        cc = compiler()
        with tempfile.TemporaryDirectory() as tmp:
            stubs = os.path.join(tmp, "stubs")
            os.makedirs(stubs)
            src = os.path.join(tmp, "macros.c")
            with open(src, "w") as fh:
                fh.write("#define TRUE 1\n#define FALSE 0\n")
                for h in headers:
                    fh.write('#include "%s"\n' % h)
            out = None
            for _ in range(40):
                out = subprocess.run([cc, "-E", "-dM", "-x", "c", "-iquote", "include", "-iquote", stubs]
                                     + CPP_DEFINES + [src], cwd=REPO, capture_output=True, text=True)
                missing = re.search(r"fatal error: ([\w/.]+): No such file", out.stderr)
                if out.returncode == 0 or not missing:
                    break
                stub = os.path.join(stubs, missing.group(1))
                os.makedirs(os.path.dirname(stub), exist_ok=True)
                open(stub, "w").close()
            if out.returncode != 0:
                sys.exit("Preprocessing the constant headers failed:\n" + out.stderr[:2000])
        for line in out.stdout.splitlines():
            m = re.match(r"#define (\w+)(\(.*?\))? ?(.*)$", line)
            if m and not m.group(2):
                self.defs[m.group(1)] = m.group(3).strip()

    def _load_enums(self, headers):
        """Simple enums of the given headers (NAME or NAME = expr entries)."""
        for h in headers:
            p = repo_path("include", h)
            if not os.path.exists(p):
                continue
            text = open(p, encoding="utf-8", errors="replace").read()
            text = re.sub(r"//[^\n]*|/\*.*?\*/", "", text, flags=re.S)
            for m in re.finditer(r"\benum\b[^{;]*\{(.*?)\}", text, re.S):
                nxt = 0
                for entry in m.group(1).split(","):
                    entry = entry.strip()
                    if not entry or entry.startswith("#"):
                        continue
                    em = re.match(r"([A-Za-z_]\w*)\s*(?:=\s*(.+))?$", entry, re.S)
                    if not em:
                        break
                    if em.group(2) is not None:
                        v = self.eval(em.group(2))
                        if v is None:
                            break
                        nxt = v
                    if em.group(1) not in self.defs:
                        self.defs[em.group(1)] = str(nxt)
                    nxt += 1

    def _load_gas_symbols(self):
        for name in sorted(os.listdir(repo_path("asm", "macros"))):
            if not name.endswith(".inc"):
                continue
            for line in open(repo_path("asm", "macros", name), encoding="utf-8", errors="replace"):
                m = re.match(r"\s*(\w+)\s*=\s*([^@\n]+)", line)
                if m and m.group(1) not in self.defs:
                    self.defs[m.group(1)] = m.group(2).strip()

    def defined(self, name):
        return name in self.defs

    def value(self, name):
        """Integer value of a macro, or None."""
        if name in self._cache:
            return self._cache[name]
        self._cache[name] = None  # recursion guard
        v = None
        if name in self.defs:
            v = self.eval(self.defs[name])
        self._cache[name] = v
        return v

    def eval(self, text, unknown=None, is_defined=None):
        """Evaluates a C/gas constant expression. Unknown names give `unknown`
        (None aborts the evaluation)."""
        tokens = []
        pos = 0
        text = text.strip()
        while pos < len(text):
            m = _TOKEN.match(text, pos)
            if not m:
                return None
            tokens.append(m.group(1))
            pos = m.end()
        out = []
        i = 0
        while i < len(tokens):
            t = tokens[i]
            if t == "defined":
                if i + 1 < len(tokens) and tokens[i + 1] == "(":
                    name = tokens[i + 2]
                    i += 4
                else:
                    name = tokens[i + 1]
                    i += 2
                d = is_defined(name) if is_defined else self.defined(name)
                out.append("1" if d else "0")
                continue
            if re.match(r"\d", t):
                out.append(str(int(t.rstrip("uUlL"), 0)))
            elif re.match(r"[A-Za-z_]", t):
                v = self.value(t)
                if v is None:
                    if unknown is None:
                        return None
                    v = unknown
                out.append(str(v))
            elif t == "&&":
                out.append(" and ")
            elif t == "||":
                out.append(" or ")
            elif t == "!":
                out.append(" not ")
            elif t == "/":
                out.append("//")
            elif t in ("?", ":"):
                return None
            else:
                out.append(t)
            i += 1
        try:
            return int(eval("".join(out), {"__builtins__": {}}, {}))
        except Exception:
            return None


# ---------------------------------------------------------------------------
# Metatile behaviours
# ---------------------------------------------------------------------------

class Behaviors:
    """MB_* values and the behaviour predicates of src/metatile_behavior.c."""

    def __init__(self):
        text = open(repo_path("include", "constants", "metatile_behaviors.h")).read()
        body = re.search(r"enum\s*\{(.*?)\}", text, re.S).group(1)
        self.value = {}
        i = 0
        for line in body.split("\n"):
            line = line.split("//")[0].strip().rstrip(",")
            if not line:
                continue
            if "=" in line:
                n, v = [s.strip() for s in line.split("=")]
                i = int(v, 0)
            else:
                n = line
            self.value[n] = i
            i += 1
        self.name = {v: k for k, v in self.value.items()}
        src = open(repo_path("src", "metatile_behavior.c")).read()
        self.surfable = set()
        table = re.search(r"sTileBitAttributes\[[^\]]*\]\s*=\s*\{(.*?)\};", src, re.S).group(1)
        for m in re.finditer(r"\[(MB_\w+)\]\s*=\s*([^,\n]+)", table):
            if "TILE_FLAG_SURFABLE" in m.group(2) and m.group(1) in self.value:
                self.surfable.add(self.value[m.group(1)])
        self.preds = {}
        for m in re.finditer(r"\bbool\d*\s+MetatileBehavior_(\w+)\s*\(\s*u\d+\s+\w+\s*\)\s*\{", src):
            start = m.end()
            depth = 1
            j = start
            while depth and j < len(src):
                if src[j] == "{":
                    depth += 1
                elif src[j] == "}":
                    depth -= 1
                j += 1
            body = re.sub(r"#ifdef BUGFIX.*?#endif", "", src[start:j], flags=re.S)
            names = re.findall(r"\b(MB_\w+)\b", body)
            self.preds[m.group(1)] = {self.value[n] for n in names if n in self.value}

    def is_(self, pred, behavior):
        return behavior in self.preds.get(pred, ())

    def set_of(self, *preds):
        out = set()
        for p in preds:
            out |= self.preds.get(p, set())
        return out


# ---------------------------------------------------------------------------
# Tilesets, layouts and grids
# ---------------------------------------------------------------------------

class Tilesets:
    def __init__(self):
        hdr = open(repo_path("src", "data", "tilesets", "headers.h")).read()
        self.attr_symbol = {}
        for m in re.finditer(r"const struct Tileset (\w+)\s*=\s*\{(.*?)\};", hdr, re.S):
            a = re.search(r"\.metatileAttributes\s*=\s*(\w+)", m.group(2))
            if a:
                self.attr_symbol[m.group(1)] = a.group(1)
        mt = open(repo_path("src", "data", "tilesets", "metatiles.h")).read()
        self.attr_file = {}
        for m in re.finditer(r"(\w+)\[\]\s*=\s*INCBIN_U(16|32)\(\"([^\"]+)\"\)", mt):
            self.attr_file[m.group(1)] = (m.group(3), int(m.group(2)))
        self._cache = {}

    def attributes(self, tileset, bits):
        """Raw attribute values of a tileset (list of ints), [] if unknown.

        The engine reads the array as u32 for FRLG layouts and as u16 for
        all others (src/fieldmap.c), whatever INCBIN width declares it.
        """
        sym = self.attr_symbol.get(tileset)
        if sym is None or sym not in self.attr_file:
            return []
        key = (sym, bits)
        if key not in self._cache:
            path, _ = self.attr_file[sym]
            data = open(repo_path(path), "rb").read()
            n = len(data) // (bits // 8)
            fmt = "<%d%s" % (n, "H" if bits == 16 else "I")
            self._cache[key] = list(struct.unpack(fmt, data[:n * (bits // 8)]))
        return self._cache[key]


class Grid:
    """One map's block data: metatile, collision, elevation, behaviour."""

    def __init__(self, layout, tilesets, blockdata_path=None):
        self.layout = layout
        self.w = layout["width"]
        self.h = layout["height"]
        path = blockdata_path or repo_path(layout["blockdata_filepath"])
        raw = array("H")
        raw.frombytes(open(path, "rb").read())
        if sys.byteorder != "little":
            raw.byteswap()
        self.blocks = raw
        version = layout.get("layout_version", "emerald")
        self.version = version
        self.num_primary = 640 if version in ("frlg", "hns") else 512
        bits = 32 if version == "frlg" else 16
        self.primary = tilesets.attributes(layout["primary_tileset"], bits)
        self.secondary = tilesets.attributes(layout["secondary_tileset"], bits)
        self.mask = 0x1FF if version == "frlg" else 0xFF

    def inside(self, x, y):
        return 0 <= x < self.w and 0 <= y < self.h

    def block(self, x, y):
        return self.blocks[x + y * self.w]

    def metatile(self, x, y):
        return self.blocks[x + y * self.w] & 0x3FF

    def collision(self, x, y):
        return (self.blocks[x + y * self.w] >> 10) & 3

    def elevation(self, x, y):
        return self.blocks[x + y * self.w] >> 12

    def behavior_of_metatile(self, mt):
        """Behaviour as the engine's u8 predicates see it."""
        if mt < self.num_primary:
            attrs, idx = self.primary, mt
        else:
            attrs, idx = self.secondary, mt - self.num_primary
        if idx >= len(attrs):
            return 0
        return (attrs[idx] & self.mask) & 0xFF

    def behavior(self, x, y):
        return self.behavior_of_metatile(self.metatile(x, y))


# ---------------------------------------------------------------------------
# Map sections and regions
# ---------------------------------------------------------------------------

class MapSections:
    """MAPSEC numbers of the HnS build and the region rules of
    include/regions.h, src/field_move.c, src/johto_permits.c and
    src/level_scaling.c (IsHoennMapsec)."""

    ARRIVAL_CORRIDOR = ("MAPSEC_ROUTE_26", "MAPSEC_ROUTE_27", "MAPSEC_TOHJO_FALLS")
    HOENN_EXTRA = ("MAPSEC_VICTORY_ROAD", "MAPSEC_SAFARI_ZONE", "MAPSEC_ABANDONED_SHIP", "MAPSEC_LILYCOVE_CITY")

    def __init__(self):
        data = json.load(open(repo_path("src", "data", "region_map", "region_map_sections.json")))
        self.number = {}
        self.display = {}
        for sec in data["map_sections"]:
            self.number.setdefault(sec["id"], 0)
            self.display[sec["id"]] = sec.get("name", sec["id"])
        for i, sec in enumerate(data["hns_map_sections"]):
            self.number[sec["id"]] = i + 1
            if "name" in sec:
                self.display[sec["id"]] = sec["name"]
        self.none = len(data["hns_map_sections"]) + 1
        n = self.number
        self.kanto = (n["MAPSEC_PALLET_TOWN"], n["MAPSEC_SPECIAL_AREA"])
        self.johto = (n["MAPSEC_NEW_BARK_TOWN"], n["MAPSEC_WHIRL_ISLANDS"])
        self.alola = (n["MAPSEC_MELEMELE_ISLAND"], n["MAPSEC_ULAULA_CAVE_2"])
        self.hisui = (n["MAPSEC_SNOWSWEPT_CAVERN"], n["MAPSEC_SINJOH_RUINS"])
        self.littleroot = n["MAPSEC_LITTLEROOT_TOWN"]
        self.hoenn_extra = {n[s] for s in self.HOENN_EXTRA if s in n}
        self.corridor = {n[s] for s in self.ARRIVAL_CORRIDOR if s in n}

    def num(self, mapsec):
        return self.number.get(mapsec, 0)

    def is_hoenn(self, mapsec):
        v = self.num(mapsec)
        return self.littleroot <= v < self.none or v in self.hoenn_extra

    def in_range(self, mapsec, rng):
        v = self.num(mapsec)
        return rng[0] <= v <= rng[1]

    def field_rules(self, mapsec):
        """'kanto', 'hoenn', 'johto' or 'default' (HnS badge thresholds)."""
        if self.in_range(mapsec, self.kanto):
            return "kanto"
        if self.is_hoenn(mapsec):
            return "hoenn"
        if self.in_range(mapsec, self.johto) and self.num(mapsec) not in self.corridor:
            return "johto"
        return "default"

    def region(self, mapsec):
        """Region for reports: Kanto, Johto, Hoenn, Alola, Hisui or Sonder."""
        if mapsec in ("MAPSEC_DYNAMIC", "MAPSEC_NONE"):
            return "Sonder"
        if self.in_range(mapsec, self.hisui):
            return "Hisui"
        if self.in_range(mapsec, self.johto):
            return "Johto"
        if self.in_range(mapsec, self.kanto):
            return "Kanto"
        if self.in_range(mapsec, self.alola):
            return "Alola"
        if self.is_hoenn(mapsec):
            return "Hoenn"
        return "Sonder"


# ---------------------------------------------------------------------------
# Maps
# ---------------------------------------------------------------------------

class Map:
    def __init__(self, data, dirname):
        self.data = data
        self.dir = dirname
        self.id = data["id"]
        self.name = data["name"]
        self.layout_id = data.get("layout")
        self.mapsec = data.get("region_map_section", "MAPSEC_NONE")
        self.map_type = data.get("map_type", "")
        self.active = data.get("game_version", ACTIVE_GAME_VERSION) == ACTIVE_GAME_VERSION
        self.connections = data.get("connections") or []
        self.warps = data.get("warp_events") or []
        self.coord_events = data.get("coord_events") or []
        self.bg_events = data.get("bg_events") or []
        self.objects = [o for o in (data.get("object_events") or [])]
        # Local ID names and numbers -> object index (numbers are 1-based).
        self.local_ids = {}
        for i, o in enumerate(self.objects):
            self.local_ids[str(i + 1)] = i
            if o.get("local_id"):
                self.local_ids[o["local_id"]] = i

    @property
    def scripts_file(self):
        return "data/maps/%s/scripts.inc" % self.dir

    def object_index(self, local_id):
        return self.local_ids.get(str(local_id))


class World:
    """All maps, layouts and tilesets of the repository."""

    # Headers whose macros the script tools need (event_scripts.s includes).
    def __init__(self, macros=None):
        self.macros = macros or Macros(event_script_headers())
        self.behaviors = Behaviors()
        self.tilesets = Tilesets()
        self.mapsecs = MapSections()
        layouts = json.load(open(repo_path("data", "layouts", "layouts.json")))["layouts"]
        self.layouts = {l["id"]: l for l in layouts if "id" in l}
        self.layout_list = [l.get("id") for l in layouts]
        self.maps = {}
        for d in sorted(os.listdir(repo_path("data", "maps"))):
            p = repo_path("data", "maps", d, "map.json")
            if os.path.exists(p):
                m = Map(json.load(open(p)), d)
                if m.id in self.maps and not m.active:
                    continue
                self.maps[m.id] = m
        self.by_name = {m.name: m for m in self.maps.values()}
        self.by_dir = {m.dir: m for m in self.maps.values()}
        self._grids = {}
        self.blockdata_override = {}

    def active_maps(self):
        return [m for m in self.maps.values() if m.active]

    def c_map_refs(self):
        """Map and layout ids named anywhere in src/ (.c and .h): warps, fly
        spots, checks and layouts that C code may use for a map."""
        if getattr(self, "_c_refs", None) is None:
            refs = set()
            pat = re.compile(r"\b(?:MAP|LAYOUT)_[A-Z0-9_]+\b")
            for root, _, files in os.walk(repo_path("src")):
                for f in files:
                    if f.endswith((".c", ".h")):
                        with open(os.path.join(root, f), encoding="utf-8", errors="replace") as fh:
                            refs.update(pat.findall(fh.read()))
            self._c_refs = refs & (set(self.maps) | set(self.layouts))
        return self._c_refs

    def grid(self, map_id, layout_id=None):
        m = self.maps[map_id]
        lid = layout_id or m.layout_id
        if lid not in self._grids:
            layout = self.layouts.get(lid)
            if layout is None:
                return None
            self._grids[lid] = Grid(layout, self.tilesets, self.blockdata_override.get(lid))
        return self._grids[lid]

    def region(self, map_id):
        return self.mapsecs.region(self.maps[map_id].mapsec)


def event_script_headers():
    """The #include lines at the top of data/event_scripts.s."""
    out = []
    for line in open(repo_path("data", "event_scripts.s"), encoding="utf-8", errors="replace"):
        m = re.match(r'\s*#include\s+"([^"]+)"', line)
        if m:
            out.append(m.group(1))
    return out


# ---------------------------------------------------------------------------
# Items
# ---------------------------------------------------------------------------

HM_ORDER = ["CUT", "FLY", "SURF", "STRENGTH", "FLASH", "ROCK_SMASH", "WATERFALL", "WHIRLPOOL", "DIVE"]


def canonical_item(name):
    """ITEM_HM01 -> ITEM_HM_CUT; other names unchanged."""
    m = re.match(r"ITEM_HM0?(\d)$", name or "")
    if m and 1 <= int(m.group(1)) <= len(HM_ORDER):
        return "ITEM_HM_" + HM_ORDER[int(m.group(1)) - 1]
    return name


class Items:
    """Pocket, importance and display name of every item (src/data/items.h)."""

    def __init__(self):
        text = open(repo_path("src", "data", "items.h"), encoding="utf-8", errors="replace").read()
        self.pocket = {}
        self.important = set()
        self.display = {}
        for m in re.finditer(r"\[(ITEM_\w+)\]\s*=\s*\{(.*?)\n    \},", text, re.S):
            body = m.group(2)
            p = re.search(r"\.pocket\s*=\s*(\w+)", body)
            if p:
                self.pocket[m.group(1)] = p.group(1)
            if re.search(r"\.importance\s*=\s*[1-9]", body):
                self.important.add(m.group(1))
            n = re.search(r'\.name\s*=\s*(?:ITEM_NAME|_)\("([^"]*)"\)', body)
            if n:
                self.display[m.group(1)] = n.group(1)

    def is_key(self, item):
        return self.pocket.get(item) == "POCKET_KEY_ITEMS" or item in self.important

    def is_hm(self, item):
        return (item or "").startswith("ITEM_HM_")


# ---------------------------------------------------------------------------
# Event scripts
# ---------------------------------------------------------------------------

class Instr:
    __slots__ = ("cmd", "args", "file", "line")

    def __init__(self, cmd, args, file, line):
        self.cmd = cmd
        self.args = args
        self.file = file
        self.line = line

    def where(self):
        return "%s:%d" % (self.file, self.line)

    def __repr__(self):
        return "%s %s (%s)" % (self.cmd, ", ".join(self.args), self.where())


def split_args(text):
    """Splits macro arguments at top-level commas (gas also allows spaces
    between simple arguments, e.g. `finditem VAR_RESULT VAR_0x8009`)."""
    args, depth, cur = [], 0, ""
    for ch in text:
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        if ch == "," and depth == 0:
            args.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        args.append(cur.strip())
    out = []
    for a in args:
        parts = a.split()
        if len(parts) > 1 and all(re.match(r"^[\w.]+$", p) for p in parts):
            out.extend(parts)
        else:
            out.append(a)
    return out


def strip_comment(line):
    """Removes @ and // comments outside string literals."""
    out = []
    in_str = False
    i = 0
    while i < len(line):
        ch = line[i]
        if ch == '"':
            in_str = not in_str
        elif not in_str and (ch == "@" or line.startswith("//", i)):
            break
        out.append(ch)
        i += 1
    return "".join(out)


class ScriptDB:
    """data/event_scripts.s with every .include inlined and every #if/.if
    evaluated for the jade build.

    instrs: flat list of Instr; labels: name -> index of the next instruction.
    Execution falls through from one label into the next, like the game.
    """

    DATA_DIRECTIVES = (".byte", ".2byte", ".4byte", ".string", ".align", ".braille", ".hword",
                       ".word", ".global", ".section", ".balign", ".space")

    def __init__(self, macros):
        self.macros = macros
        self.instrs = []
        self.labels = {}
        self.label_where = {}
        self.duplicates = []
        self.warnings = []
        self.aliases = {}
        self._load(repo_path("data", "event_scripts.s"))

    # -- preprocessing --------------------------------------------------
    def _cond(self, expr, cpp):
        expr = expr.strip()
        if cpp:
            v = self.macros.eval(expr, unknown=0)
        else:
            v = self.macros.eval(self._subst(expr), unknown=0,
                                 is_defined=lambda n: n in self.aliases or self.macros.defined(n))
        if v is None:
            self.warnings.append("unevaluated condition: %s" % expr)
            return False
        return bool(v)

    def _subst(self, text):
        if not self.aliases:
            return text
        return re.sub(r"\b[A-Za-z_]\w*\b", lambda m: self.aliases.get(m.group(0), m.group(0)), text)

    def _lines(self, path):
        """Yields (text, relpath, lineno) after .include and conditionals."""
        stack = []  # entries: [active, taken, parent_active]

        def active():
            return all(e[0] for e in stack)

        def walk(p):
            relp = rel(p)
            in_macro = False
            for no, raw in enumerate(open(p, encoding="utf-8", errors="replace"), 1):
                line = raw.rstrip("\n")
                s = line.strip()
                m = re.match(r"#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)", s)
                gm = re.match(r"\.(if|ifdef|ifndef|ifnb|ifb|elseif|else|endif)\b(.*)", s)
                if in_macro:
                    if re.match(r"\.endm\b", s):
                        in_macro = False
                    continue
                if m or gm:
                    kind = (m or gm).group(1)
                    expr = (m or gm).group(2)
                    cpp = m is not None
                    if kind in ("if", "ifdef", "ifndef", "ifnb", "ifb"):
                        par = active()
                        if not par:
                            val = False
                        elif kind == "ifdef":
                            val = self.macros.defined(expr.strip()) or expr.strip() in self.aliases
                        elif kind == "ifndef":
                            val = not (self.macros.defined(expr.strip()) or expr.strip() in self.aliases)
                        elif kind == "ifnb":
                            val = bool(expr.strip())
                        elif kind == "ifb":
                            val = not expr.strip()
                        else:
                            val = self._cond(expr, cpp)
                        stack.append([val, val, par])
                    elif kind in ("elif", "elseif"):
                        if stack:
                            e = stack[-1]
                            if e[1] or not e[2]:
                                e[0] = False
                            else:
                                e[0] = self._cond(expr, cpp)
                                e[1] = e[0]
                    elif kind == "else":
                        if stack:
                            e = stack[-1]
                            e[0] = e[2] and not e[1]
                            e[1] = True
                    elif kind == "endif":
                        if stack:
                            stack.pop()
                    continue
                if not active():
                    continue
                if s.startswith("#"):
                    continue
                if re.match(r"\.macro\b", s):
                    in_macro = True
                    continue
                inc = re.match(r'\.include\s+"([^"]+)"', s)
                if inc:
                    target = repo_path(inc.group(1))
                    if os.path.exists(target):
                        yield from walk(target)
                    else:
                        self.warnings.append("missing include %s (%s:%d)" % (inc.group(1), relp, no))
                    continue
                yield line, relp, no

        yield from walk(path)

    def _load(self, path):
        for line, relp, no in self._lines(path):
            text = strip_comment(line).strip()
            if not text:
                continue
            if re.match(r"\w+\s*=", text):
                continue
            m = re.match(r"\.(set|equ|equiv)\s+(\w+)\s*,\s*(.+)$", text)
            if m:
                self.aliases[m.group(2)] = self._subst(m.group(3).strip())
                continue
            while True:
                lm = re.match(r"([A-Za-z_][\w.]*)::?\s*(.*)$", text)
                if not lm:
                    break
                name = lm.group(1)
                if name in self.labels:
                    self.duplicates.append((name, "%s:%d" % (relp, no)))
                else:
                    self.labels[name] = len(self.instrs)
                    self.label_where[name] = "%s:%d" % (relp, no)
                text = lm.group(2).strip()
            if not text:
                continue
            parts = text.split(None, 1)
            cmd = parts[0].lower()  # gas macro names are case-insensitive
            if cmd.startswith("."):
                if cmd in (".byte", ".2byte", ".4byte", ".string", ".braille"):
                    self.instrs.append(Instr("." + cmd.lstrip("."), split_args(parts[1]) if len(parts) > 1 else [], relp, no))
                continue
            args = split_args(self._subst(parts[1])) if len(parts) > 1 else []
            self.instrs.append(Instr(cmd, args, relp, no))

    # -- lookups --------------------------------------------------------
    def index(self, label):
        return self.labels.get(label)

    def map_scripts(self, map_name):
        """[(type, label)] from <map>_MapScripts."""
        i = self.labels.get(map_name + "_MapScripts")
        out = []
        if i is None:
            return out
        while i < len(self.instrs) and self.instrs[i].cmd == "map_script":
            a = self.instrs[i].args
            if len(a) >= 2:
                out.append((a[0], a[1]))
            i += 1
        return out

    def frame_table(self, label):
        """[(var, value, script)] of an ON_FRAME/ON_WARP_INTO table."""
        i = self.labels.get(label)
        out = []
        if i is None:
            return out
        while i < len(self.instrs) and self.instrs[i].cmd == "map_script_2":
            a = self.instrs[i].args
            if len(a) >= 3:
                out.append((a[0], a[1], a[2]))
            i += 1
        return out

    def label_file(self, label):
        w = self.label_where.get(label)
        return w.split(":")[0] if w else None


# ---------------------------------------------------------------------------
# Special functions in C
# ---------------------------------------------------------------------------

class CFunctions:
    """Bodies of C functions under src/, for a shallow effect scan of
    specials and callnatives (FlagSet/FlagClear/VarSet and gSpecialVar_Result)."""

    def __init__(self):
        self.bodies = {}
        self.where = {}
        self._effects = {}
        func = re.compile(r"^[A-Za-z_][\w \t\*]*?\b([A-Za-z_]\w*)\s*\(([^;{}]*)\)\s*\n?\{", re.M)
        for root, _, files in os.walk(repo_path("src")):
            for f in files:
                if not f.endswith(".c"):
                    continue
                p = os.path.join(root, f)
                if "/data/" in p.replace("\\", "/"):
                    continue
                text = open(p, encoding="utf-8", errors="replace").read()
                for m in func.finditer(text):
                    name = m.group(1)
                    if name in ("if", "while", "for", "switch", "return"):
                        continue
                    start = m.end()
                    depth = 1
                    j = start
                    while depth and j < len(text):
                        c = text[j]
                        if c == "{":
                            depth += 1
                        elif c == "}":
                            depth -= 1
                        j += 1
                    if name not in self.bodies:
                        self.bodies[name] = text[start:j]
                        self.where[name] = "%s:%d" % (rel(p), text.count("\n", 0, m.start()) + 1)

    def effects(self, name, depth=2, seen=None):
        """{'set': flags, 'clear': flags, 'vars': vars, 'result': bool}.
        Top-level results are cached; treat them as read-only."""
        if seen is None:
            key = (name, depth)
            if key not in self._effects:
                self._effects[key] = self.effects(name, depth, set())
            return self._effects[key]
        out = {"set": set(), "clear": set(), "vars": set(), "result": False, "found": name in self.bodies}
        if name in seen or name not in self.bodies:
            return out
        seen.add(name)
        body = re.sub(r"//[^\n]*|/\*.*?\*/", "", self.bodies[name], flags=re.S)
        out["set"] |= set(re.findall(r"\bFlagSet\(\s*(FLAG_\w+)\s*\)", body))
        out["clear"] |= set(re.findall(r"\bFlagClear\(\s*(FLAG_\w+)\s*\)", body))
        out["vars"] |= set(re.findall(r"\bVarSet\(\s*(VAR_\w+)\s*,", body))
        if re.search(r"gSpecialVar_Result\s*=[^=]", body):
            out["result"] = True
        if depth > 0:
            for callee in set(re.findall(r"\b([A-Z]\w+)\s*\(", body)):
                if callee in ("FlagSet", "FlagClear", "VarSet", "FlagGet", "VarGet"):
                    continue
                sub = self.effects(callee, depth - 1, seen)
                out["set"] |= sub["set"]
                out["clear"] |= sub["clear"]
                out["vars"] |= sub["vars"]
        return out
