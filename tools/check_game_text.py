#!/usr/bin/env python3
"""Measures the game text of the jade build in the sources, line by line.

Every text the build uses is read from the sources after the C preprocessor
has resolved #if GERMAN, IS_HNS and the other switches (cpp with the jade
flags), so each result points at the file and line to edit. No build needed;
generated headers that are missing are replaced by empty stubs.

Scope:
  maps    scripts.inc of every map with game_version "hns", by region of its
          map section (Kanto, Johto, Hoenn; Sinjoh and Alola count as locked)
  common  data/event_scripts.s and every data/scripts, data/text file it
          includes
  src     every _("...") and COMPOUND_STRING("...") in src/*.c and the
          headers they include
  names   trainer names of src/data/*.party (English check only)

Each displayed line (split at \\n, \\l, \\p) is measured like the text printer
does: FONT_NORMAL unless the text switches fonts, glyph widths from
src/fonts.c indexed by glyph id, characters from charmap.txt. A message box
line may be 208 px wide (convention); the window itself is 216 px.

Placeholders are estimated with realistic maximum lengths: {PLAYER} and
{RIVAL} 7 characters, Pokemon nicknames 12, {STR_VAR_n} from the buffer
commands that run before the message in the same script or in the scripts
that jump to it (exact for a constant argument, else the longest value of
that kind). Battle placeholders use the longest name of their kind plus the
longest prefix; battle paragraphs without \\n or \\l are wrapped by the game
(BreakStringAutomatic) and not checked. Source texts with their own windows
(Pokedex, item and move descriptions, berry tags, ...) are not checked.

Visibility comes from the map events and map scripts that reach a text;
a text reached from a trigger or map script, or from a script that gives a
badge, an HM or a starter or fights a boss, counts as story path. A debug
text or a text of a locked or retired map that an active map shows counts
for that map. Scripts reached only through a jump on VAR_SINJOH_STORYLINE
count as locked (Sinjoh, D-019).
English text is found with a word list heuristic (English and German
function words); texts of locked and retired maps are listed apart. A
trainer name still in upstream capitals counts as English; it is rated by
the map scripts that fight the trainer (rematch tiers by the first tier of
their REMATCH row in the compiled C code).

Usage (from the repository root):
    python3 -I tools/check_game_text.py                  # summary
    python3 -I tools/check_game_text.py --list           # lines over --limit
    python3 -I tools/check_game_text.py --english        # English leftovers
    python3 -I tools/check_game_text.py --out DIR        # CSV and MD per region
    python3 -I tools/check_game_text.py --out DIR --all-lines   # plus every line
    python3 -I tools/check_game_text.py --repo PATH      # another checkout

Exit status 1 if a line of active content is proven wider than --limit.
"""

import argparse
import bisect
import collections
import concurrent.futures
import csv
import glob
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import threading

LIMIT = 208           # message box line, convention
WINDOW = 216          # message box window: 27 tiles
CHAR_PX = 6           # width of most letters in FONT_NORMAL
PLAYER_CHARS = 7      # PLAYER_NAME_LENGTH
MON_CHARS = 12        # POKEMON_NAME_LENGTH
NUMBER_DIGITS = 5     # buffernumberstring with a variable
TRAINER_CHARS = 10    # TRAINER_NAME_LENGTH
BOX_CHARS = 8         # BOX_NAME_LENGTH

CPP_FLAGS = ["-iquote", "include", "-I", "include", "-iquote", ".",
             "-Wno-trigraphs", "-DMODERN=1", "-DTESTING=0", "-DPOKEMON_HNS",
             "-std=gnu17", "-w"]

STRING_RE = re.compile(r'"((?:[^"\\\n]|\\.)*)"')
LABEL_RE = re.compile(r"^\s*(\w+)::?(?=\s|$|@)")
INCLUDE_RE = re.compile(r'^\s*\.include\s+"([^"]+)"')
MARKER_RE = re.compile(r'^# (\d+) "([^"]*)"')
MISSING_RE = re.compile(r'fatal error: ([^:\s]+): No such file')

# Text printer control codes: number of argument bytes after FC <code>.
EXT_ARGS = {0x01: 1, 0x02: 1, 0x03: 1, 0x04: 3, 0x05: 1, 0x06: 1, 0x08: 1,
            0x0B: 2, 0x0C: 1, 0x0D: 1, 0x0E: 1, 0x10: 2, 0x11: 1, 0x12: 1,
            0x13: 1, 0x14: 1, 0x19: 1, 0x1A: 1, 0x1B: 1, 0x1C: 3}

BREAKS = {0xFE: "\\n", 0xFA: "\\l", 0xFB: "\\p"}

BUFFER_KINDS = {
    "bufferspeciesname": "species", "bufferleadmonspeciesname": "species",
    "bufferpartymonnick": "nick", "bufferlivemonnickname": "nick",
    "bufferitemname": "item", "bufferitemnameplural": "itemplural",
    "bufferdecorationname": "decor", "buffermovename": "move",
    "buffernumberstring": "number", "bufferstdstring": "std",
    "bufferstring": "string", "buffertrainerclassname": "trainerclass",
    "buffertrainername": "trainer", "bufferboxname": "box",
    "buffermoncategory": "category", "buffercontestname": "contest",
}

# Script commands after which a block does not fall through to the next label.
BLOCK_ENDS = {"end", "return", "goto", "step_end", "releaseall_end", "warp",
              "warpsilent", "warpdoor", "warphole", "warpteleport",
              "warpspinenter", "goto_if_set_end"}

STORY_CLASS_RE = re.compile(
    r"Leader|Elite|Champion|Rival|Admin|Boss|Executive|Protag|Rocket|Magma|Aqua|Pkmn Trainer")
STORY_CMD_RE = re.compile(
    r"^(setflag\s+FLAG_(BADGE\w*|RECEIVED_HM\w*|SYS_POKEDEX_GET|SYS_POKEMON_GET|SYS_POKENAV_GET)"
    r"|giveitem\s+ITEM_HM\w*|givemon\b|setvar\s+VAR_\w*(STATE|STORY|PROGRESS)\w*)")

# Common script files every player sees often.
FREQUENT_COMMON = {
    "data/scripts/obtain_item.inc", "data/text/obtain_item.inc",
    "data/scripts/pkmn_center_nurse.inc", "data/text/pkmn_center_nurse.inc",
    "data/scripts/pc.inc", "data/text/pc.inc", "data/scripts/surf.inc",
    "data/text/surf.inc", "data/scripts/field_move_scripts.inc",
    "data/text/save.inc", "data/scripts/white_out.inc", "data/scripts/repel.inc",
    "data/text/mart_clerk.inc", "data/scripts/trainer_battle.inc",
    "data/scripts/std_msgbox.inc", "data/event_scripts.s",
}

# Source texts shown in their own windows, not in a message box; their
# widths are not checked against --limit.
SRC_OWN_WINDOW = ("src/data/pokemon/", "src/data/items.h", "src/data/moves_info.h",
                  "src/data/abilities.h", "src/data/decoration/", "src/berry.c",
                  "src/data/text/ribbon_descriptions.h", "src/data/credits",
                  "src/data/text/gift_ribbon_descriptions.h", "src/naming_screen.c",
                  "src/data/union_room.h", "src/sliding_puzzle.c", "src/data/contest_moves.h",
                  "src/data/trade.h", "src/data/easy_chat/")
# Source texts whose window was checked: 26 tiles = 208 px, text at x = 0.
SRC_CHECKED_WINDOW = {"src/battle_message.c": "Kampf-Textfenster (B_WIN_MSG, 26 Kacheln)",
                      "src/data/help_window.h": "Hilfefenster (26 Kacheln)"}
# Texts that BreakStringAutomatic wraps to 208 px when a paragraph has no \n or \l.
AUTO_WRAP_FILES = {"src/battle_message.c"}
# Font of a struct field that is not FONT_NORMAL when no <field>Font is given.
SRC_FIELD_FONT = {("src/data/help_window.h", "desc"): "FONT_SMALL"}
DEBUG_FILES = ("data/scripts/debug.inc", "data/scripts/config.inc", "src/debug.c",
               "src/pokemon_sprite_visualizer.c", "src/battle_debug.c",
               "src/data/debug_trainers.party")
# Generated trainer data and the party files it comes from.
TRAINER_DATA = ("src/data/trainers", "src/data/battle_partners", "src/data/debug_trainers")
# Region of a party file's trainers when no map script fights them.
PARTY_REGION = {"trainers_hns.party": "johto", "trainers_frlg.party": "kanto",
                "trainers.party": "hoenn"}
# Trainer name left in upstream capitals (German names are mixed case).
CAPS_NAME_RE = re.compile(r"[A-Z][A-Z0-9 .&'-]*[A-Z]")
ACTIVE_REGIONS = ("kanto", "johto", "hoenn")
INACTIVE_REGIONS = ("gesperrt", "stillgelegt")
# Script conditions on locked content (D-019); a jump on them leads to locked content.
LOCKED_GATE_RE = re.compile(r"\bVAR_SINJOH_STORYLINE\b")
LOCKED_VIS = "gesperrt (Sinjoh-Bedingung)"

EN_WORDS = set("""
the you your you're i i'm it's is are was were this that these those what with
have has had would can can't don't didn't doesn't won't isn't aren't wasn't
not and or but for from of to on at my me we our they their there here be
been do does did get got if just some any please thank thanks yes hello let's
let go now want like know see come very really good great about into out up
one more it a as by he she his her him who how why when where which than then
only too again still i've i'll you've you'll we're they're that's there's
what's let me look time way new day back over after before because could
should every something nothing anything someone people use used using
""".split())
EN_AMBIGUOUS = {"in", "so", "an", "was", "will", "also", "man", "die", "bin",
                "war", "hat", "oh", "no", "hi", "rot", "gift", "art", "kind",
                "a", "i", "us", "am", "on", "to", "be", "time"}
DE_WORDS = set("""
der die das und ist du ich nicht ein eine einen einem einer mit zu sie es wir
auf für dem den des hast bist sind mir mich dich dir dein deine mein meine auch
noch schon aber oder wenn wie was wo hier da jetzt kann kannst habe haben wird
werden vom von zum zur im ins beim nur sehr gut ja nein bitte danke hallo mal
doch sich uns euch ihr ihre sein seine kein keine alle viel mehr gibt geht nach
aus bei über unter vor gegen ohne um dass weil ob als wieder immer heute diese
dieser dieses etwas nichts willst möchtest
""".split())


def strip_c_comments(text):
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


def strip_asm_comment(line):
    """Removes an @ comment that is not inside a string."""
    in_str = False
    for i, c in enumerate(line):
        if c == '"' and (i == 0 or line[i - 1] != "\\"):
            in_str = not in_str
        elif c == "@" and not in_str:
            return line[:i]
    return line


def parse_byte(token):
    """A number inside {..}: 0x.. or two hex digits as hex, else decimal."""
    if re.fullmatch(r"[0-9A-Fa-f]{2}", token) and not token.isdigit() or re.fullmatch(r"0\d", token):
        return int(token, 16)
    return int(token, 0) & 0xFF


class Repo:
    def __init__(self, root):
        self.root = os.path.abspath(root)

    def path(self, rel):
        return os.path.join(self.root, rel)

    def read(self, rel):
        with open(self.path(rel), encoding="utf-8", errors="replace") as fh:
            return fh.read()

    def exists(self, rel):
        return os.path.exists(self.path(rel))


# ---------------------------------------------------------------- preprocessor

class Cpp:
    """Runs cpp with the jade flags; missing generated headers become stubs."""

    def __init__(self, repo):
        self.repo = repo
        self.exe = shutil.which("arm-none-eabi-cpp") or shutil.which("cpp")
        if not self.exe:
            sys.exit("no C preprocessor found (arm-none-eabi-cpp or cpp)")
        self.stub_dir = tempfile.mkdtemp(prefix="oj_text_stubs_")
        self.stubs = []
        self.lock = threading.Lock()

    def close(self):
        shutil.rmtree(self.stub_dir, ignore_errors=True)

    def run(self, source=None, stdin_text=None):
        """Preprocessed text of a file (path relative to the repo) or of stdin."""
        args = [self.exe] + CPP_FLAGS + ["-iquote", self.stub_dir, "-I", self.stub_dir]
        args.append(source if source else "-")
        tried = set()
        for _ in range(50):
            res = subprocess.run(args, cwd=self.repo.root, input=stdin_text,
                                 capture_output=True, text=True, encoding="utf-8",
                                 errors="replace")
            if res.returncode == 0:
                return res.stdout
            missing = MISSING_RE.search(res.stderr)
            if not missing or missing.group(1) in tried:
                raise RuntimeError("cpp failed for %s:\n%s" % (source or "stdin", res.stderr[-2000:]))
            tried.add(missing.group(1))
            with self.lock:
                stub = os.path.join(self.stub_dir, missing.group(1))
                if not os.path.exists(stub):
                    os.makedirs(os.path.dirname(stub), exist_ok=True)
                    open(stub, "w").close()
                    self.stubs.append(missing.group(1))
        raise RuntimeError("too many missing headers for %s" % source)


def cpp_lines(output):
    """[(file, line, text)] of cpp output, file relative and normalized."""
    result = []
    cur_file, cur_line = "", 0
    for raw in output.split("\n"):
        m = MARKER_RE.match(raw)
        if m:
            cur_line = int(m.group(1))
            cur_file = os.path.normpath(m.group(2)) if m.group(2) and not m.group(2).startswith("<") else m.group(2)
            continue
        result.append((cur_file, cur_line, raw))
        cur_line += 1
    return result


# ---------------------------------------------------------------- fonts, charmap

class Font:
    def __init__(self, repo):
        fonts_c = strip_c_comments(repo.read("src/fonts.c"))
        enum = re.search(r"enum\s*\{\s*(FONT_SMALL,.*?)\}", repo.read("include/text.h"), re.S).group(1)
        names = re.findall(r"^\s*(FONT_\w+)", enum, re.M)
        self.tables = {}
        for font_id, name in enumerate(names):
            camel = "".join(p.capitalize() for p in re.sub(r"_COPY_\d", "", name)[5:].split("_"))
            m = re.search(r"gFont%sLatinGlyphWidths\[\]\s*=\s*\{(.*?)\};" % camel, fonts_c, re.S)
            if m:
                self.tables[font_id] = [int(x, 0) for x in re.findall(r"0x[0-9A-Fa-f]+|\d+", m.group(1))]
        self.normal = names.index("FONT_NORMAL")
        self.ids = {name: i for i, name in enumerate(names)}
        if len(self.tables[self.normal]) < 0x200:
            sys.exit("gFontNormalLatinGlyphWidths has %d entries, expected 512" % len(self.tables[self.normal]))
        chars_h = repo.read("include/constants/characters.h")
        char_values = {m.group(1): int(m.group(2), 0) for m in
                       re.finditer(r"#define\s+(CHAR_\w+)\s+(0x[0-9A-Fa-f]+|\d+)", chars_h)}
        self.keypad = {}
        for m in re.finditer(r"\[(CHAR_\w+)\]\s*=\s*\{\s*(\w+),\s*(\d+),\s*(\d+)\s*\}", repo.read("src/text.c")):
            if m.group(1) in char_values:
                self.keypad[char_values[m.group(1)]] = int(m.group(3))

    def glyph(self, table, b):
        t = self.tables.get(table) or self.tables[self.normal]
        return t[b] if b < len(t) else CHAR_PX


class Charmap:
    def __init__(self, repo):
        self.chars, self.consts = {}, {}
        for raw in repo.read("charmap.txt").splitlines():
            line = raw.strip()
            if not line or line.startswith("@"):
                continue
            m = re.match(r"^'((?:\\.|[^'\\])+)'\s*=\s*((?:[0-9A-Fa-f]{2}(?:\s+|$))+)", line)
            if m:
                key = m.group(1)
                if len(key) == 2 and key[0] == "\\" and key[1] not in "nlp":
                    key = key[1]
                seq = [int(b, 16) for b in m.group(2).split()]
                self.chars.setdefault(key, seq)
                continue
            m = re.match(r"^(\w+)\s*=\s*((?:[0-9A-Fa-f]{2}(?:\s+|$))+)", line)
            if m:
                self.consts.setdefault(m.group(1), [int(b, 16) for b in m.group(2).split()])

    def encode(self, body, unknown):
        """Atoms of one string literal: (kind, value, source snippet)."""
        atoms = []
        i = 0
        while i < len(body):
            c = body[i]
            if c == "{":
                j = body.find("}", i)
                if j < 0:
                    unknown.add(body[i:])
                    break
                parts = body[i + 1:j].split()
                snippet = body[i:j + 1]
                seq = self.consts.get(parts[0]) if parts else None
                if seq is None:
                    try:
                        seq = [parse_byte(parts[0])]
                    except (ValueError, IndexError):
                        unknown.add(snippet)
                        atoms.append(("ph", "?" + body[i + 1:j], snippet))
                        i = j + 1
                        continue
                if len(seq) == 2 and seq[0] == 0xFD:
                    atoms.append(("ph", parts[0], snippet))
                else:
                    for p in parts[1:]:
                        if p in self.consts:
                            seq = seq + self.consts[p]
                        else:
                            try:
                                seq = seq + [parse_byte(p)]
                            except ValueError:
                                unknown.add(snippet)
                    atoms.extend(self.byte_atoms(seq, snippet))
                i = j + 1
            elif c == "\\" and i + 1 < len(body):
                seq = self.chars.get(body[i:i + 2]) or self.chars.get(body[i + 1])
                if seq is None:
                    unknown.add(body[i:i + 2])
                    seq = []
                atoms.extend(self.byte_atoms(seq, body[i:i + 2]))
                i += 2
            else:
                seq = self.chars.get(c)
                if seq is None:
                    unknown.add(c)
                    atoms.append(("g", None, c))
                else:
                    atoms.extend(self.byte_atoms(seq, c))
                i += 1
        return atoms

    @staticmethod
    def byte_atoms(seq, snippet):
        atoms = []
        k = 0
        while k < len(seq):
            b = seq[k]
            snip = snippet if k == 0 else ""
            if b in BREAKS:
                atoms.append(("br", b, snip))
            elif b == 0xFF:
                atoms.append(("eos", b, snip))
            elif b == 0xFC and k + 1 < len(seq):
                n = EXT_ARGS.get(seq[k + 1], 0)
                atoms.append(("ctl", tuple(seq[k + 1:k + 2 + n]), snip))
                k += 1 + n
            elif b in (0xF7, 0xFD) and k + 1 < len(seq):
                atoms.append(("ph", "%02X_%02X" % (b, seq[k + 1]), snip))
                k += 1
            elif b in (0xF8, 0xF9) and k + 1 < len(seq):
                atoms.append(("key" if b == 0xF8 else "sym", seq[k + 1], snip))
                k += 1
            else:
                atoms.append(("g", b, snip))
            k += 1
        return atoms


# ---------------------------------------------------------------- text items

class Text:
    """One text: a label with its string literals."""

    def __init__(self, origin, label, file, line, kind):
        self.origin = origin      # "script" or "c"
        self.label = label
        self.file = file
        self.line = line
        self.kind = kind          # file-level area
        self.literals = []        # [(line, body)]
        self.lines = []           # [DisplayLine]
        self.font = None          # font id at the start, None = FONT_NORMAL
        self.shown_in = []        # active maps whose events reach a script that shows it
        self.locked = False       # shown only behind a LOCKED_GATE_RE condition
        self.home = None          # region when the file does not tell it (trainer names)
        self.c_refs = []          # C files that use a trainer
        self.rematch_of = None    # first trainer of a rematch row

    def plain(self):
        return " ".join(re.sub(r"\{[^}]*\}|\\[nlp]|\$", " ", b) for _, b in self.literals)


class DisplayLine:
    def __init__(self, line_no):
        self.line_no = line_no
        self.width = 0
        self.notes = []
        self.text = []
        self.exact = True
        self.worst_cases = 0      # placeholders that took the widest of several constants
        self.end = None           # break byte that ends the line
        self.auto_wrap = False    # paragraph without \n or \l


def measure(text, charmap, font, estimate, unknown):
    """Splits a text into display lines and measures each one."""
    lines = []
    cur = None
    table = font.normal if text.font is None else text.font
    min_width = 0
    done = False
    for line_no, body in text.literals:
        if done:
            break
        for kind, value, snip in charmap.encode(body, unknown):
            if cur is None:
                cur = DisplayLine(line_no)
            if kind == "br":
                cur.end = value
                lines.append(cur)
                cur = None
                continue
            if kind == "eos":
                done = True
                break
            cur.text.append(snip)
            if kind == "g":
                w = CHAR_PX if value is None else font.glyph(table, value)
                cur.width += max(w, min_width)
            elif kind == "ph":
                px, note, exact = estimate(value)
                cur.width += px
                if note:
                    cur.notes.append(note)
                if exact is None:
                    cur.worst_cases += 1
                    if cur.worst_cases > 1:
                        cur.exact = False
                elif not exact:
                    cur.exact = False
            elif kind == "key":
                cur.width += font.keypad.get(value, 8)
            elif kind == "sym":
                cur.width += font.glyph(table, value | 0x100)
            elif kind == "ctl":
                code = value[0]
                arg = value[1] if len(value) > 1 else 0
                if code == 0x06:
                    table = arg if arg in font.tables else table
                elif code == 0x07:
                    table = font.normal if text.font is None else text.font
                elif code == 0x0C:
                    cur.width += font.glyph(table, arg)
                elif code == 0x11:
                    cur.width += arg
                elif code in (0x0D, 0x12):
                    cur.width = arg
                elif code == 0x13:
                    cur.width = max(cur.width, arg)
                elif code == 0x14:
                    min_width = arg
    if cur is not None and cur.text:
        lines.append(cur)
    paragraph = []
    for ln in lines + [None]:
        if ln is not None:
            paragraph.append(ln)
        if ln is None or ln.end == 0xFB:
            manual = any(p.end in (0xFE, 0xFA) for p in paragraph)
            for p in paragraph:
                p.auto_wrap = not manual
            paragraph = []
    text.lines = [ln for ln in lines if ln.text]


def text_width(text_bodies, charmap, font):
    """Widest line of a list of literals, placeholders counted as 0 (for names)."""
    t = Text("c", "", "", 0, "")
    t.literals = [(0, b) for b in text_bodies]
    measure(t, charmap, font, lambda name: (0, None, True), set())
    return max([ln.width for ln in t.lines] or [0])


# ---------------------------------------------------------------- maps, regions

class Maps:
    def __init__(self, repo):
        sections = json.loads(repo.read("src/data/region_map/region_map_sections.json"))
        order = [s["id"] for s in sections.get("hns_map_sections", [])]
        index = {mapsec: i for i, mapsec in enumerate(order)}

        def span(first, last):
            if first in index and last in index:
                return set(order[index[first]:index[last] + 1])
            return set()

        kanto = span("MAPSEC_PALLET_TOWN", "MAPSEC_SPECIAL_AREA")
        johto = span("MAPSEC_NEW_BARK_TOWN", "MAPSEC_WHIRL_ISLANDS")
        hisui = span("MAPSEC_SNOWSWEPT_CAVERN", "MAPSEC_SINJOH_RUINS")
        alola = span("MAPSEC_MELEMELE_ISLAND", "MAPSEC_ULAULA_CAVE_2")
        self.locked_mapsecs = hisui | alola
        self.by_dir = {}
        for path in sorted(glob.glob(repo.path("data/maps/*/map.json"))):
            with open(path, encoding="utf-8") as fh:
                data = json.load(fh)
            d = os.path.basename(os.path.dirname(path))
            mapsec = data.get("region_map_section", "")
            if data.get("game_version", "emerald") != "hns":
                region = "stillgelegt"
            elif mapsec in self.locked_mapsecs:
                region = "gesperrt"
            elif mapsec in kanto:
                region = "kanto"
            elif mapsec in johto:
                region = "johto"
            else:
                region = "hoenn"
            entries = collections.defaultdict(set)
            for key, kind in (("object_events", "npc"), ("coord_events", "trigger"),
                              ("bg_events", "sign")):
                for ev in data.get(key) or []:
                    if ev.get("script") and ev["script"] != "0x0":
                        entries[ev["script"]].add(kind)
            self.by_dir[d] = {"region": region, "mapsec": mapsec, "entries": entries,
                              "name": data.get("name", d)}

    def region_of(self, rel):
        m = re.match(r"data/maps/([^/]+)/", rel)
        if m:
            info = self.by_dir.get(m.group(1))
            return info["region"] if info else "stillgelegt"
        base = os.path.basename(rel).lower()
        if "_frlg" in base:
            return "kanto"
        if "_hns" in base:
            return "johto"
        if rel.startswith("src/"):
            return "src"
        return "gemeinsam"


# ---------------------------------------------------------------- name data

def german_lines(text):
    """Source lines of a data header with the non-German #if GERMAN branches removed."""
    out = []
    stack = []                # [(is a language switch, branch active)]
    for line in text.split("\n"):
        s = line.strip()
        if re.match(r"#\s*if", s):
            is_lang = "GERMAN" in s
            stack.append((is_lang, not is_lang or not re.search(r"!\s*GERMAN", s)))
        elif re.match(r"#\s*(else|elif)", s) and stack:
            is_lang, active = stack[-1]
            stack[-1] = (is_lang, not active if is_lang else active)
        elif re.match(r"#\s*endif", s) and stack:
            stack.pop()
        elif all(active for _, active in stack):
            out.append(line)
            continue
        out.append("")
    return out


class Names:
    """Longest and per-constant widths of names that fill the string buffers."""

    def __init__(self, repo, charmap, font, ctexts):
        self.charmap, self.font = charmap, font
        # name lengths: POKEMON_NAME_LENGTH, ITEM_NAME_LENGTH, MOVE_NAME_LENGTH (no Z-Moves)
        self.species = self.collect(repo, ["src/data/pokemon/species_info/*.h"], "speciesName", "SPECIES_", 12)
        self.items = self.collect(repo, ["src/data/items.h"], "name", "ITEM_", 20)
        self.item_plurals = self.collect(repo, ["src/data/items.h"], "pluralName", "ITEM_", 22)
        self.moves = self.collect(repo, ["src/data/moves_info.h"], "name", "MOVE_", 16)
        self.abilities = self.collect(repo, ["src/data/abilities.h"], "name", "ABILITY_", 16)
        self.decor = self.collect(repo, ["src/data/decoration/header.h"], "name", "DECOR_", 16)
        for const, width in self.items.items():
            self.item_plurals.setdefault(const, width)
        self.std = {}
        if repo.exists("src/data/script_menu.h"):
            block = repo.read("src/data/script_menu.h")
            m = re.search(r"gStdStrings\[\]\s*=\s*\{(.*?)\};", block, re.S)
            if m:
                for const, sym in re.findall(r"\[(STDSTRING_\w+)\]\s*=\s*(\w+)", m.group(1)):
                    if sym in ctexts:
                        self.std[const] = max([ln.width for ln in ctexts[sym].lines] or [0])
        self.max = {k: max(v.values() or [MON_CHARS * CHAR_PX]) for k, v in (
            ("species", self.species), ("item", self.items), ("itemplural", self.item_plurals),
            ("move", self.moves), ("ability", self.abilities), ("decor", self.decor),
            ("std", self.std))}

    def collect(self, repo, patterns, field, prefix, max_chars):
        result = {}
        files = []
        for p in patterns:
            files += sorted(glob.glob(repo.path(p)))
        for path in files:
            with open(path, encoding="utf-8", errors="replace") as fh:
                lines = german_lines(fh.read())
            current = None
            for line in lines:
                m = re.match(r"\s*\[(%s\w+)\]\s*=" % prefix, line)
                if m:
                    current = m.group(1)
                m = re.search(r"\.%s\s*=\s*[A-Z_]*\(?\s*_?\(?\s*\"((?:[^\"\\]|\\.)*)\"" % field, line)
                if m and current and current not in result:
                    plain = re.sub(r"\{[^}]*\}", "", m.group(1))
                    if len(plain) <= max_chars:
                        result[current] = text_width([m.group(1)], self.charmap, self.font)
        return result


# ---------------------------------------------------------------- script data

class Block:
    def __init__(self, label, file, line):
        self.label, self.file, self.line = label, file, line
        self.cmds = []            # [(line, cmd, args)]
        self.next = None
        self.refs = []            # [(text label, buffers)]
        self.story = False


def parse_script_lines(lines, texts, blocks, includes, area_of, source):
    """Collects texts, script blocks and .include paths from cpp output lines.

    Commands are read from the source line, because cpp replaces constants
    such as FLAG_ and SPECIES_ by numbers."""
    current_label = None
    current_text = None
    block = None
    prev_block = None
    unnamed = collections.Counter()
    for file, line_no, raw in lines:
        if not file.startswith("data/"):
            continue
        code = strip_asm_comment(raw)
        if not code.strip():
            continue
        m = INCLUDE_RE.match(code)
        if m:
            includes.append(m.group(1))
            continue
        m = LABEL_RE.match(code)
        if m:
            current_label = m.group(1)
            current_text = None
            block = Block(current_label, file, line_no)
            if prev_block is not None and prev_block.file == file and (
                    not prev_block.cmds or prev_block.cmds[-1][1] not in BLOCK_ENDS):
                prev_block.next = current_label
            blocks.setdefault(current_label, block)
            prev_block = block
            rest = code[m.end():].strip()
            if not rest:
                continue
            code = rest
        s = code.strip()
        if s.startswith(".string"):
            bodies = STRING_RE.findall(s)
            if current_text is None:
                label = current_label or "?"
                if label in texts:
                    unnamed[label] += 1
                    label = "%s+%d" % (label, unnamed[label])
                current_text = Text("script", label, file, line_no, area_of(file))
                texts[label] = current_text
            for body in bodies:
                current_text.literals.append((line_no, body))
                if "$" in body.replace("\\$", ""):
                    current_text = None
                    break
            continue
        if s.startswith("."):
            current_text = None
            if block is not None and re.match(r"\.(4byte|2byte|byte|word)\b", s):
                orig = strip_asm_comment(source(file, line_no)).strip()
                if orig.split(None, 1)[:1] == s.split(None, 1)[:1]:
                    s = orig
                block.cmds.append((line_no, s.split()[0], [a.strip() for a in s.split(None, 1)[1].split(",")]
                                   if len(s.split(None, 1)) > 1 else []))
            continue
        current_text = None
        if block is not None:
            orig = strip_asm_comment(source(file, line_no)).strip()
            m = LABEL_RE.match(orig)
            if m:
                orig = orig[m.end():].strip()
            if orig.split(None, 1)[:1] == s.split(None, 1)[:1]:
                s = orig
            parts = s.split(None, 1)
            args = [a.strip() for a in parts[1].split(",")] if len(parts) > 1 else []
            block.cmds.append((line_no, parts[0], args))


def analyse_blocks(texts, blocks, maps, trainer_story, ctexts):
    """Links texts to the scripts that show them: buffers before and visibility."""
    refs = collections.defaultdict(list)        # text label -> [(block, buffers)]
    file_buffers = collections.defaultdict(lambda: collections.defaultdict(set))
    entries = collections.defaultdict(set)      # block label -> entry kinds
    entry_maps = collections.defaultdict(set)   # block label -> map dirs it is an entry of
    for d, info in maps.by_dir.items():
        for label, kinds in info["entries"].items():
            entries[label] |= kinds
            entry_maps[label].add(d)
    edges = collections.defaultdict(set)
    locked_edges = collections.defaultdict(set)  # jumps on a LOCKED_GATE_RE condition
    jumps = collections.defaultdict(list)       # block label -> [(target, buffers)]
    for block in blocks.values():
        buffers = {}
        m = re.match(r"data/maps/([^/]+)/", block.file)
        block_map = m.group(1) if m else None
        for line_no, cmd, args in block.cmds:
            if cmd in BUFFER_KINDS and len(args) >= 1:
                arg = args[1] if len(args) > 1 else ""
                buffers[args[0]] = (BUFFER_KINDS[cmd], arg)
                file_buffers[block.file][args[0]].add((BUFFER_KINDS[cmd], arg))
            if cmd in ("map_script", "map_script_2"):
                for a in args:
                    if a in blocks:
                        entries[a].add("mapscript")
                        if block_map:
                            entry_maps[a].add(block_map)
            if STORY_CMD_RE.match(cmd + " " + " ".join(args)):
                block.story = True
            if cmd.startswith("trainerbattle") and any(a in trainer_story for a in args):
                block.story = True
            gated = cmd.startswith(("goto_if", "call_if")) and any(LOCKED_GATE_RE.search(a) for a in args)
            for a in args:
                a = a.strip()
                if a in texts or a in ctexts:
                    refs[a].append((block, dict(buffers)))
                # text labels are data: no control flow into or through them
                if a in blocks and a != block.label and a not in texts:
                    (locked_edges if gated else edges)[block.label].add(a)
                    if cmd.startswith(("goto", "call")):
                        jumps[block.label].append((a, dict(buffers)))
        if block.next and block.label not in texts and block.next not in texts:
            edges[block.label].add(block.next)
            jumps[block.label].append((block.next, dict(buffers)))
    # buffers that are set before a block is entered (goto/call/fall-through)
    incoming = collections.defaultdict(list)
    for _ in range(4):
        changed = False
        for label, targets in jumps.items():
            for target, local in targets:
                for state in incoming.get(label) or [{}]:
                    new = dict(state)
                    new.update(local)
                    if new and new not in incoming[target] and len(incoming[target]) < 40:
                        incoming[target].append(new)
                        changed = True
        if not changed:
            break
    def walk(start, *edge_maps):
        seen = {start}
        todo = [start]
        while todo:
            b = todo.pop()
            for em in edge_maps:
                for n in em.get(b, ()):
                    if n not in seen and n in blocks:
                        seen.add(n)
                        todo.append(n)
        return seen

    # visibility of each block: reached from which entry kinds and maps, story chain
    reach = collections.defaultdict(set)
    reach_maps = collections.defaultdict(set)
    story_reach = set()
    locked = set()                              # reached only through a locked condition
    for start, kinds in entries.items():
        if start not in blocks:
            continue
        seen = walk(start, edges)
        chain_story = any(blocks[b].story for b in seen)
        for b in seen:
            reach[b] |= kinds
            reach_maps[b] |= entry_maps[start]
            if chain_story:
                story_reach.add(b)
        if any(b in locked_edges for b in seen):
            locked |= walk(start, edges, locked_edges)
    locked -= set(reach)
    return refs, file_buffers, reach, story_reach, incoming, reach_maps, locked


# ---------------------------------------------------------------- C strings

def c_strings(cpp, rel):
    """Texts of one C file after cpp: [(file, line, label, [bodies])]."""
    out = cpp.run(rel)
    lines = cpp_lines(out)
    flat = []
    origins = []
    for file, line_no, raw in lines:
        flat.append(raw)
        origins.append((file, line_no))
    starts = []
    pos = 0
    for raw in flat:
        starts.append(pos)
        pos += len(raw) + 1
    text = "\n".join(flat)
    result = []
    for m in re.finditer(r"(?<![\w.])_\s*\(\s*\"", text):
        i = m.end() - 1
        bodies = []
        while True:
            sm = STRING_RE.match(text, i)
            if not sm:
                break
            bodies.append(sm.group(1))
            i = sm.end()
            ws = re.match(r"\s*", text[i:i + 200])
            i += ws.end()
            if i >= len(text) or text[i] != '"':
                break
        if not bodies:
            continue
        k = bisect.bisect_right(starts, m.start()) - 1
        file, line_no = origins[k]
        if not file.startswith("src/"):
            continue
        label = c_label(text, m.start()) or "%s:%d" % (os.path.basename(file), line_no)
        result.append((file, line_no, label, bodies))
    idents = set()
    live = collections.defaultdict(set)         # src file -> lines that are compiled
    for (file, line_no), raw in zip(origins, flat):
        if file.startswith("src/"):
            idents.update(re.findall(r"\b[A-Za-z_]\w{3,}\b", STRING_RE.sub("", raw)))
            if raw.strip():
                live[file].add(line_no)
    return result, idents, live


def c_trainer_refs(repo, live):
    """TRAINER_ constants on compiled C lines: ({id: {file}}, {rematch tier id: first id})."""
    refs = collections.defaultdict(set)
    first_of = {}
    for file, nums in live.items():
        if file.startswith(TRAINER_DATA + DEBUG_FILES):
            continue
        lines = repo.read(file).split("\n")
        for n in nums:
            raw = lines[n - 1] if 0 < n <= len(lines) else ""
            if "TRAINER_" not in raw:
                continue
            for tid in re.findall(r"\bTRAINER_\w+", raw):
                refs[tid].add(file)
            m = re.search(r"\bREMATCH\(\s*(TRAINER_\w+)((?:\s*,\s*TRAINER_\w+)*)", raw)
            if m:
                for tier in re.findall(r"TRAINER_\w+", m.group(2)):
                    first_of[tier] = m.group(1)
    return refs, first_of


def party_names(repo):
    """Trainer names of the party files: [(file, line, trainer id, name)]."""
    out = []
    for path in sorted(glob.glob(repo.path("src/data/*.party"))):
        rel = os.path.relpath(path, repo.root)
        current = None
        with open(path, encoding="utf-8", errors="replace") as fh:
            for no, line in enumerate(fh, 1):
                m = re.match(r"===\s*((?:TRAINER|PARTNER)_\w+)\s*===", line)
                if m:
                    current = None if m.group(1).endswith("_NONE") else m.group(1)
                elif current and line.startswith("Name:"):
                    out.append((rel, no, current, line[len("Name:"):].strip()))
    return out


CAST = r"(?:\(\s*const\s+u8\s*\[[^\]]*\]\s*\)\s*)?"


def c_label(text, pos):
    """Name of the variable, designator or field a string literal initializes."""
    before = text[max(0, pos - 400):pos]
    fm = re.search(r"\.(\w+)\s*=\s*" + CAST + "$", before)
    if fm:
        dm = re.findall(r"\[\s*([^\]=]+?)\s*\]\s*=\s*\{", text[max(0, pos - 3000):pos])
        return "%s.%s" % (re.sub(r"\s+", "", dm[-1]) if dm else "?", fm.group(1))
    dm = re.search(r"\[\s*([^\]=]+?)\s*\]\s*=\s*" + CAST + "$", before)
    if dm:
        return re.sub(r"\s+", "", dm.group(1))
    vm = re.search(r"(\w+)\s*(?:\[[^\]]*\])*\s*=\s*" + CAST + "$", before)
    if vm:
        return vm.group(1)
    return None


def place_literals(repo, file, line_no, bodies, cache):
    """Source line of each literal, searched from the line cpp reports."""
    if file not in cache:
        try:
            cache[file] = repo.read(file).split("\n")
        except OSError:
            cache[file] = []
    src = cache[file]
    placed = []
    cur = line_no
    for body in bodies:
        needle = '"%s"' % body
        found = None
        for k in range(cur - 1, min(len(src), cur + 60)):
            if k >= 0 and needle in src[k]:
                found = k + 1
                break
        if found is None:
            found = cur
        placed.append((found, body))
        cur = found
    return placed


def field_font(t, cache, font):
    """Font id of a struct field text with a sibling <field>Font, else None."""
    if "." not in t.label:
        return None
    field = t.label.rsplit(".", 1)[1]
    src = cache.get(t.file, [])
    start = t.literals[-1][0] if t.literals else t.line
    name = SRC_FIELD_FONT.get((t.file, field))
    for k in range(start, min(len(src), start + 15)):
        if re.match(r"\s*\[[^\]]+\]\s*=", src[k]):
            break
        m = re.search(r"\.%sFont\s*=\s*(FONT_\w+)" % field, src[k])
        if m:
            name = m.group(1)
            break
    return font.ids.get(name) if name else None


# ---------------------------------------------------------------- English

def english_score(plain):
    words = re.findall(r"[A-Za-zÄÖÜäöüßéÉ']+", plain)
    lower = [w.lower().strip("'") for w in words]
    en = [w for w in lower if w in EN_WORDS and w not in EN_AMBIGUOUS]
    de = [w for w in lower if w in DE_WORDS]
    umlaut = bool(re.search(r"[ÄÖÜäöüß]", plain))
    return en, de, umlaut, len(words)


def is_german(plain):
    en, de, umlaut, n = english_score(plain)
    return umlaut or len(de) >= 2 or (de and not en)


def is_english(plain):
    en, de, umlaut, n = english_score(plain)
    if n < 2:
        return None
    if len(en) >= 2 and not de and not umlaut:
        return en
    if len(en) >= 4 and len(en) >= 3 * max(1, len(de)):
        return en
    return None


# ---------------------------------------------------------------- main analysis

class Estimator:
    def __init__(self, names, ctexts, stexts, charmap, font):
        self.names, self.ctexts, self.stexts = names, ctexts, stexts
        self.charmap, self.font = charmap, font
        fixed = {}
        for sym, key in (("gText_ExpandedPlaceholder_Emerald", "VERSION"),
                         ("gText_ExpandedPlaceholder_Aqua", "AQUA"),
                         ("gText_ExpandedPlaceholder_Magma", "MAGMA"),
                         ("gText_ExpandedPlaceholder_Archie", "ARCHIE"),
                         ("gText_ExpandedPlaceholder_Maxie", "MAXIE"),
                         ("gText_ExpandedPlaceholder_Kyogre", "KYOGRE"),
                         ("gText_ExpandedPlaceholder_Groudon", "GROUDON")):
            if sym in ctexts:
                fixed[key] = max([ln.width for ln in ctexts[sym].lines] or [0])
        fixed["REGION"] = max([max([ln.width for ln in ctexts[s].lines] or [0])
                               for s in ("gText_Kanto", "gText_Johto", "gText_Hoenn") if s in ctexts] or [30])
        fixed["KUN"] = 0
        self.fixed = fixed
        self.prefix = 0
        for sym, t in ctexts.items():
            if re.search(r"PkmnPrefix(Lower|\d)?$", sym) and t.file == "src/battle_message.c":
                self.prefix = max([self.prefix] + [ln.width for ln in t.lines])
        if not self.prefix:
            self.prefix = 16 * CHAR_PX

    def value_width(self, kind, arg):
        """(px, note, exact) of one buffer value."""
        n = self.names
        table = {"species": n.species, "item": n.items, "itemplural": n.item_plurals,
                 "move": n.moves, "decor": n.decor, "std": n.std}.get(kind)
        if table is not None:
            if arg in table:
                return table[arg], "%s=%s" % (kind, arg), True
            return n.max[kind], "%s max" % kind, False
        if kind == "nick":
            return MON_CHARS * CHAR_PX, "Spitzname 12", False
        if kind == "number":
            if re.fullmatch(r"\d+", arg or ""):
                return len(arg) * CHAR_PX, "Zahl %s" % arg, True
            return NUMBER_DIGITS * CHAR_PX, "Zahl %d Stellen" % NUMBER_DIGITS, False
        if kind == "string":
            t = self.stexts.get(arg) or self.ctexts.get(arg)
            if t is not None and t.lines:
                return max(ln.width for ln in t.lines), "Text %s" % arg, True
            return MON_CHARS * CHAR_PX, "Text ?", False
        if kind in ("trainer", "trainerclass", "contest", "category"):
            return MON_CHARS * CHAR_PX, kind + " 12", False
        if kind == "box":
            return BOX_CHARS * CHAR_PX, "Box 8", False
        return MON_CHARS * CHAR_PX, "unbekannt 12", False

    def make(self, buffers_options):
        """Estimator for one text; buffers_options: STR_VAR -> [(kind, arg)]."""
        def estimate(name):
            if name in ("PLAYER", "RIVAL", "B_PLAYER_NAME", "B_LINK_PLAYER_NAME",
                        "B_LINK_PARTNER_NAME", "B_LINK_OPPONENT1_NAME",
                        "B_LINK_OPPONENT2_NAME", "B_LINK_SCR_TRAINER_NAME"):
                return PLAYER_CHARS * CHAR_PX, "%s 7" % name, False
            if name in self.fixed:
                return self.fixed[name], None, name != "REGION"
            if name.startswith("STR_VAR_"):
                options = buffers_options.get(name)
                if not options:
                    return MON_CHARS * CHAR_PX, "%s ? 12" % name, False
                best = max((self.value_width(k, a) for k, a in options), key=lambda v: v[0])
                if len(options) > 1:
                    return best[0], "%s %s (max. von %d)" % (name, best[1], len(options)), False
                return best[0], "%s %s" % (name, best[1]), best[2]
            if name.startswith("B_"):
                return self.battle(name)
            return MON_CHARS * CHAR_PX, "%s ? 12" % name, False
        return estimate

    def battle(self, name):
        n = self.names
        mon = MON_CHARS * CHAR_PX
        if "WITH_PREFIX" in name:
            return (max(self.prefix + n.max["species"], mon),
                    "%s Präfix+längste Art" % name, False)
        if "MOVE" in name:
            return n.max["move"], "%s längste Attacke" % name, False
        if "ITEM" in name:
            return n.max["item"], "%s längstes Item" % name, False
        if "ABILITY" in name:
            return n.max["ability"], "%s längste Fähigkeit" % name, False
        if name.endswith("_TEXT"):
            return 0, "%s eigener Text" % name, False
        if "CLASS" in name or "TRAINER" in name:
            return TRAINER_CHARS * CHAR_PX + mon, "%s Klasse+Name" % name, False
        if "PREFIX" in name:
            return self.prefix, "%s Präfix" % name, False
        return mon, "%s 12" % name, False


def collect(repo, threads):
    charmap = Charmap(repo)
    font = Font(repo)
    maps = Maps(repo)
    cpp = Cpp(repo)
    unknown = set()
    try:
        # C sources
        c_files = sorted(os.path.relpath(p, repo.root) for p in glob.glob(repo.path("src/*.c")))
        ctexts = {}
        src_cache = {}
        with concurrent.futures.ThreadPoolExecutor(max_workers=threads) as pool:
            results = list(pool.map(lambda f: c_strings(cpp, f), c_files))
        seen = set()
        c_idents = set()
        c_live = collections.defaultdict(set)
        for items, idents, live in results:
            c_idents |= idents
            for file, nums in live.items():
                c_live[file] |= nums
            for file, line_no, label, bodies in items:
                key = (file, line_no, tuple(bodies))
                if key in seen:
                    continue
                seen.add(key)
                name = label
                k = 1
                while name in ctexts:
                    k += 1
                    name = "%s#%d" % (label, k)
                t = Text("c", name, file, line_no, "src")
                t.literals = place_literals(repo, file, line_no, bodies, src_cache)
                t.font = field_font(t, src_cache, font)
                ctexts[name] = t
        for t in ctexts.values():
            measure(t, charmap, font, lambda n: (MON_CHARS * CHAR_PX, None, False), unknown)

        # Script data: event_scripts.s and everything it includes
        ev_src = repo.read("data/event_scripts.s")
        header = "\n".join(l for l in ev_src.split("\n") if re.match(r"\s*#\s*(include|define)\b", l))
        texts, blocks, includes = {}, {}, []
        area = maps.region_of
        src_lines = {}

        def source(file, line_no):
            if file not in src_lines:
                try:
                    src_lines[file] = repo.read(file).split("\n")
                except OSError:
                    src_lines[file] = []
            lines = src_lines[file]
            return lines[line_no - 1] if 0 < line_no <= len(lines) else ""

        parse_script_lines(cpp_lines(cpp.run("data/event_scripts.s")), texts, blocks, includes, area, source)
        done = set()
        todo = [i for i in includes if i.endswith(".inc")]
        while todo:
            batch = [p for p in dict.fromkeys(todo) if p not in done and repo.exists(p)]
            todo = []
            if not batch:
                break
            done.update(batch)
            wrapper = header + "\n" + "\n".join('#include "%s"' % p for p in batch) + "\n"
            new_includes = []
            parse_script_lines(cpp_lines(cpp.run(stdin_text=wrapper)), texts, blocks, new_includes, area, source)
            todo = [i for i in new_includes if i.endswith(".inc")]

        trainer_story = set()
        for path in glob.glob(repo.path("src/data/*.party")):
            with open(path, encoding="utf-8", errors="replace") as fh:
                current = None
                for line in fh:
                    m = re.match(r"===\s*(TRAINER_\w+)\s*===", line)
                    if m:
                        current = m.group(1)
                    elif current and (line.startswith("Mugshot:") or
                                      (line.startswith("Class:") and STORY_CLASS_RE.search(line))):
                        trainer_story.add(current)

        refs, file_buffers, reach, story_reach, incoming, reach_maps, locked = analyse_blocks(
            texts, blocks, maps, trainer_story, ctexts)

        def rate(t, ref_blocks):
            """Sets reach, story path, active maps and locked state from the showing scripts."""
            kinds, story, shown = set(), False, set()
            for block in ref_blocks:
                kinds |= reach.get(block.label, set())
                story = story or block.label in story_reach
                shown |= reach_maps.get(block.label, set())
            t.reach = kinds
            t.story = story or bool(kinds & {"trigger", "mapscript"})
            t.shown_in = sorted(d for d in shown if maps.by_dir[d]["region"] in ACTIVE_REGIONS)
            t.locked = bool(ref_blocks) and all(b.label in locked for b in ref_blocks)

        names = Names(repo, charmap, font, ctexts)
        est = Estimator(names, ctexts, texts, charmap, font)

        # re-measure C texts now that names are known; battle placeholders
        for t in ctexts.values():
            measure(t, charmap, font, est.make({}), unknown)
        for label, t in texts.items():
            # one buffer context per script that shows the text; the widest wins
            contexts = []
            for block, buffers in refs.get(label, []):
                for state in incoming.get(block.label) or [{}]:
                    state = dict(state)
                    state.update(buffers)
                    options = {}
                    for var in ("STR_VAR_1", "STR_VAR_2", "STR_VAR_3"):
                        if var in state:
                            options[var] = {state[var]}
                        else:
                            options[var] = set(file_buffers[block.file].get(var, set()))
                    if options not in contexts:
                        contexts.append(options)
            if not contexts:
                contexts.append({var: set(vals) for var, vals in file_buffers[t.file].items()})
            best = None
            for options in contexts:
                measure(t, charmap, font, est.make(options), unknown)
                if best is None:
                    best = t.lines
                    continue
                for i, ln in enumerate(t.lines):
                    if i < len(best) and (ln.width, ln.exact) > (best[i].width, best[i].exact):
                        best[i] = ln
            t.lines = best
            rate(t, [b for b, _ in refs.get(label, [])])
            t.referenced = bool(refs.get(label)) or label in c_idents
        for t in ctexts.values():
            t.reach, t.story, t.referenced = set(), False, True

        # trainer names: shown in battle, rated by the scripts that fight them
        trainer_blocks = collections.defaultdict(list)
        for block in blocks.values():
            for _, cmd, args in block.cmds:
                for a in args:
                    if a.startswith(("TRAINER_", "PARTNER_")):
                        trainer_blocks[a].append(block)
        c_refs, first_of = c_trainer_refs(repo, c_live)
        party = []
        for file, line_no, tid, name in party_names(repo):
            t = Text("party", tid, file, line_no, "party")
            t.literals = [(line_no, name)]
            fights = trainer_blocks.get(tid, []) + trainer_blocks.get(first_of.get(tid), [])
            rate(t, fights)
            t.referenced = bool(fights) or tid in c_refs
            t.c_refs = sorted(c_refs.get(tid, ()))
            t.rematch_of = first_of.get(tid)
            regions = [maps.region_of(b.file) for b in fights if b.file.startswith("data/maps/")]
            regions.sort(key=lambda r: r not in ACTIVE_REGIONS)
            t.home = regions[0] if regions else PARTY_REGION.get(os.path.basename(file), "gemeinsam")
            party.append(t)
        return texts, ctexts, party, maps, unknown, cpp.stubs
    finally:
        cpp.close()


def visibility(t, borrowed=False):
    """(category in German, story path?) of a text.

    borrowed: a debug text or a text of a locked or retired map that an
    active map shows; it is rated like a text of that map."""
    if t.locked:
        return LOCKED_VIS, False
    if t.file.startswith(DEBUG_FILES) and not borrowed:
        return "Debug", False
    if t.origin == "party" and not borrowed:
        if t.c_refs:
            return "Quelltext (%s)" % ", ".join(t.c_refs[:2]), False
        if t.referenced:
            return "Skript (Einstieg unbekannt)", False
        return "nicht referenziert", False
    if t.origin == "c":
        if t.file in SRC_CHECKED_WINDOW:
            return SRC_CHECKED_WINDOW[t.file], t.file == "src/battle_message.c"
        if t.file.startswith(SRC_OWN_WINDOW):
            return "eigenes Fenster", False
        return "Quelltext, Fenster ungeprüft", False
    if not t.file.startswith("data/maps/") and not borrowed:
        if t.file in FREQUENT_COMMON:
            return "gemeinsam, häufig", True
        return "gemeinsam", False
    if t.reach & {"trigger", "mapscript"}:
        vis, story = "Auslöser/Kartenskript", True
    elif t.story:
        vis, story = "Story-NPC", True
    elif "npc" in t.reach:
        vis, story = "NPC", False
    elif "sign" in t.reach:
        vis, story = "Schild", False
    elif t.referenced:
        vis, story = "Skript/C (Einstieg unbekannt)", False
    else:
        vis, story = "nicht referenziert", False
    if borrowed and t.origin == "party":
        vis += " (Kampf auf %s%s)" % (", ".join(t.shown_in[:3]),
                                      ", Rückkampf von %s" % t.rematch_of if t.rematch_of else "")
    elif borrowed:
        vis += " (gezeigt auf %s)" % ", ".join(t.shown_in[:3])
    return vis, story


def rows_for(texts, limit, maps):
    over, english, stats = [], [], collections.defaultdict(collections.Counter)
    # files with English texts and no German one: their short texts are English too
    english_files = collections.Counter()
    german_files = set()
    for t in texts:
        if t.origin == "party":
            continue
        if is_english(t.plain()):
            english_files[t.file] += 1
        elif is_german(t.plain()):
            german_files.add(t.file)
    for t in texts:
        home = t.home or (maps.region_of(t.file) if t.origin == "script" else "src")
        borrowed = bool(t.shown_in) and (t.origin == "party" or t.file.startswith(DEBUG_FILES)
                                         or home in INACTIVE_REGIONS)
        region = maps.by_dir[t.shown_in[0]]["region"] if borrowed else home
        t.region = region
        s = stats[region]
        vis, story = visibility(t, borrowed)
        if t.origin == "party":
            name = t.plain().strip()
            if CAPS_NAME_RE.fullmatch(name):
                s["englisch"] += 1
                english.append((region, t, ["Name in Großbuchstaben"], vis, story))
            continue
        s["texte"] += 1
        own_window = t.origin == "c" and t.file.startswith(SRC_OWN_WINDOW)
        for ln in t.lines:
            s["zeilen"] += 1
            if ln.auto_wrap and t.file in AUTO_WRAP_FILES:
                continue
            if ln.width > limit and not own_window:
                key = "über %d exakt" % limit if ln.exact else "über %d geschätzt" % limit
                s[key] += 1
                if ln.width > WINDOW:
                    s["über %d%s" % (WINDOW, "" if ln.exact else " geschätzt")] += 1
                over.append((region, t, ln, vis, story))
        en = is_english(t.plain())
        if (not en and english_files[t.file] >= 3 and t.file not in german_files
                and len(re.findall(r"[A-Za-z]{2,}", t.plain())) >= 1):
            en = ["(Datei ohne deutschen Text)"]
        if en:
            s["englisch"] += 1
            english.append((region, t, en, vis, story))
    return over, english, stats


def severity(region, vis, story):
    if region in INACTIVE_REGIONS or vis in ("Debug", "nicht referenziert", LOCKED_VIS):
        return "optional"
    return "wichtig" if story else "klein"


def classify_width(region, t, ln, vis, story):
    if region in ("gesperrt", "stillgelegt"):
        return "ungeprueft", "optional"
    if not ln.exact or (t.origin == "c" and t.file not in SRC_CHECKED_WINDOW):
        return "verdacht", severity(region, vis, story)
    return "nachgewiesen", severity(region, vis, story)


def classify_english(region, t, vis, story):
    if region in ("gesperrt", "stillgelegt"):
        return "ungeprueft", "optional"
    return "nachgewiesen", severity(region, vis, story)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--repo", default=os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                    help="checkout to measure (default: this one)")
    ap.add_argument("--limit", type=int, default=LIMIT, help="line width in px (208)")
    ap.add_argument("--list", action="store_true", help="print every line over the limit")
    ap.add_argument("--english", action="store_true", help="print English texts")
    ap.add_argument("--out", help="write CSV and MD files per region into this directory")
    ap.add_argument("--all-lines", action="store_true", help="with --out: also write every measured line")
    ap.add_argument("--threads", type=int, default=os.cpu_count() or 2, help="parallel cpp runs")
    args = ap.parse_args()

    repo = Repo(args.repo)
    texts, ctexts, party, maps, unknown, stubs = collect(repo, args.threads)
    all_texts = list(texts.values()) + list(ctexts.values()) + party
    over, english, stats = rows_for(all_texts, args.limit, maps)

    print("Text widths, limit %d px (window %d px), repo %s" % (args.limit, WINDOW, repo.root))
    cols = ["texte", "zeilen", "über %d exakt" % args.limit, "über %d geschätzt" % args.limit,
            "über %d" % WINDOW, "über %d geschätzt" % WINDOW, "englisch"]
    print("%-12s" % "bereich" + "".join("%21s" % c for c in cols))
    for region in sorted(stats):
        print("%-12s" % region + "".join("%21d" % stats[region][c] for c in cols))
    if stubs:
        print("stubs for missing generated headers: %s" % ", ".join(sorted(set(stubs))))
    if unknown:
        print("characters not in charmap: %s" % " ".join(sorted(unknown)[:40]))

    if args.list:
        for region, t, ln, vis, story in sorted(over, key=lambda r: (r[0], r[1].file, r[2].line_no)):
            mark = " " if ln.exact else "~"
            print("%s%4d px  %s:%d  %s  [%s]\n         %s%s" % (
                mark, ln.width, t.file, ln.line_no, t.label, vis, "".join(ln.text),
                ("   (" + "; ".join(ln.notes) + ")") if ln.notes else ""))
    if args.english:
        for region, t, en, vis, story in sorted(english, key=lambda r: (r[0], r[1].file, r[1].line)):
            print("EN %s:%d  %s  [%s]  %s" % (t.file, t.line, t.label, vis, t.plain()[:100]))
    if args.out:
        write_reports(args.out, over, english, stats, cols, all_texts, args, repo, maps)

    bad = sum(1 for region, t, ln, vis, story in over
              if classify_width(region, t, ln, vis, story)[0] == "nachgewiesen")
    return 1 if bad else 0


def write_reports(out, over, english, stats, cols, all_texts, args, repo, maps):
    os.makedirs(out, exist_ok=True)
    regions = sorted(stats)
    head = ["bereich", "datei", "zeile", "label", "breite_px", "grenze_px", "art",
            "annahmen", "sichtbarkeit", "status", "schwere", "text"]
    for region in regions:
        rows = [r for r in over if r[0] == region]
        rows.sort(key=lambda r: (-r[2].width, r[1].file, r[2].line_no))
        with open(os.path.join(out, "breite_%s.csv" % region), "w", newline="", encoding="utf-8") as fh:
            w = csv.writer(fh, delimiter=";")
            w.writerow(head)
            for _, t, ln, vis, story in rows:
                status, sev = classify_width(region, t, ln, vis, story)
                w.writerow([region, t.file, ln.line_no, t.label, ln.width, args.limit,
                            "exakt" if ln.exact else "geschätzt", "; ".join(ln.notes),
                            vis, status, sev, "".join(ln.text)])
        en_rows = [r for r in english if r[0] == region]
        en_rows.sort(key=lambda r: (r[1].file, r[1].line))
        with open(os.path.join(out, "englisch_%s.csv" % region), "w", newline="", encoding="utf-8") as fh:
            w = csv.writer(fh, delimiter=";")
            w.writerow(["bereich", "datei", "zeile", "label", "sichtbarkeit", "status",
                        "schwere", "englische_woerter", "text"])
            for _, t, en, vis, story in en_rows:
                status, sev = classify_english(region, t, vis, story)
                w.writerow([region, t.file, t.line, t.label, vis, status, sev,
                            " ".join(sorted(set(en))[:8]), t.plain()[:300]])
        with open(os.path.join(out, "bericht_%s.md" % region), "w", encoding="utf-8") as fh:
            fh.write("# Textbreiten und englische Reste: %s\n\n" % region)
            s = stats[region]
            fh.write("Texte %d, Zeilen %d, über %d px exakt %d, geschätzt %d, über %d px exakt %d, "
                     "englisch %d.\n\n" % (s["texte"], s["zeilen"], args.limit,
                                          s["über %d exakt" % args.limit],
                                          s["über %d geschätzt" % args.limit], WINDOW,
                                          s["über %d" % WINDOW], s["englisch"]))
            fh.write("## Zeilen über %d px\n\n" % args.limit)
            fh.write("| Datei:Zeile | Label | px | Art | Sichtbarkeit | Status | Schwere | Text |\n")
            fh.write("|---|---|---|---|---|---|---|---|\n")
            for _, t, ln, vis, story in rows:
                status, sev = classify_width(region, t, ln, vis, story)
                fh.write("| %s:%d | %s | %d | %s | %s | %s | %s | %s |\n" % (
                    t.file, ln.line_no, t.label, ln.width, "exakt" if ln.exact else "geschätzt",
                    vis, status, sev, md_escape("".join(ln.text))))
            fh.write("\n## Englische Texte\n\n")
            fh.write("| Datei:Zeile | Label | Sichtbarkeit | Status | Schwere | Text |\n")
            fh.write("|---|---|---|---|---|---|\n")
            for _, t, en, vis, story in en_rows:
                status, sev = classify_english(region, t, vis, story)
                fh.write("| %s:%d | %s | %s | %s | %s | %s |\n" % (
                    t.file, t.line, t.label, vis, status, sev, md_escape(t.plain()[:160])))
    with open(os.path.join(out, "zusammenfassung.md"), "w", encoding="utf-8") as fh:
        fh.write("# Zusammenfassung Textmessung\n\nRepo: %s, Grenze %d px, Fenster %d px.\n\n"
                 % (repo.root, args.limit, WINDOW))
        fh.write("| Bereich | " + " | ".join(cols) + " |\n|---|" + "---|" * len(cols) + "\n")
        for region in regions:
            fh.write("| %s | " % region + " | ".join(str(stats[region][c]) for c in cols) + " |\n")
    if args.all_lines:
        with open(os.path.join(out, "alle_zeilen.tsv"), "w", encoding="utf-8") as fh:
            fh.write("bereich\tdatei\tzeile\tlabel\tbreite_px\tart\ttext\n")
            for t in all_texts:
                for ln in t.lines:
                    fh.write("%s\t%s\t%d\t%s\t%d\t%s\t%s\n" % (
                        t.region, t.file, ln.line_no, t.label, ln.width,
                        "exakt" if ln.exact else "geschätzt", "".join(ln.text).replace("\t", " ")))


def md_escape(s):
    return s.replace("|", "\\|")


if __name__ == "__main__":
    sys.exit(main())
