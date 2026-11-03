#!/usr/bin/env python3
"""Static checks of save safety and core game state for the jade build.

Reads scripts, map events and C sources; builds nothing. Each check prints
its findings in German with status, severity and file:line evidence.

Checks:
  gifts       Gift and trade scripts that change story state although the
              item may not have reached the bag (giveitem or
              giveitem_norandom without a VAR_RESULT check,
              giveitem_msg/additem without checkitemspace,
              removeitem before a gift).
  pockets     Distinct obtainable items per bag pocket against the pocket
              size (BAG_*_COUNT), without and with the item randomizer
              (its whitelist adds items); key items that are never held
              together (EXCLUSIVE_KEY_ITEMS) take one slot.
  newgame     Game state stored in ChallengeSettings: NewGameInitData keeps
              ChallengeSettings across ClearSav3, so such state must be
              cleared on the way into a new game (new game speech).
  migrations  Origin Jade save migrations in LoadGameSave: each flag lies in
              the Origin Jade block and is set by new games (D-017).
  hof         Hall of Fame team limits of all implementations and the title
              scripts (setrespawn before the Hall of Fame special, nothing
              but waitstate/release/end after it).
  rtc         Content that needs a running RTC and the default RTC type.
  link        Link, Union Room and Mystery Gift features on active maps.

Active maps are those with game_version "hns" in map.json (D-018). Maps of
locked content (LOCKED_MAPSECS) and, with --maps-json, maps the map checker
cannot reach are left out of gifts and pockets.

Usage:
    python3 -I tools/check_save_safety.py                 # all checks
    python3 -I tools/check_save_safety.py --check gifts   # one check
    python3 -I tools/check_save_safety.py --repo DIR      # other checkout
    python3 -I tools/check_save_safety.py --json out.json # also as JSON
    python3 -I tools/check_save_safety.py --maps-json alle.json
        # skip maps that tools/check_maps.py --json reports as K-UNERREICHBAR

Exit status 1 if a finding of severity "blocker" or "kritisch" was found.
"""

import argparse
import collections
import glob
import json
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Preprocessor symbols of the jade build as scripts see them.
PP_SYMBOLS = {"IS_HNS": 1, "IS_FRLG": 0, "IS_EMERALD": 0, "GERMAN": 1,
              "TRUE": 1, "FALSE": 0, "MODERN": 1, "TESTING": 0}
PP_DEFINED = {"POKEMON_HNS"}

SEVERITY_ORDER = ["blocker", "kritisch", "wichtig", "klein", "optional"]

# Map sections of locked content: config switch that unlocks it (None: no entrance at all).
LOCKED_MAPSECS = {
    "MAPSEC_NEW_SINJOH": "SINJOH_CONTENT_AVAILABLE", "MAPSEC_ROUTE_49": "SINJOH_CONTENT_AVAILABLE",
    "MAPSEC_ROUTE_50": "SINJOH_CONTENT_AVAILABLE", "MAPSEC_SINJOH_RUINS": "SINJOH_CONTENT_AVAILABLE",
    "MAPSEC_SNOWSWEPT_CAVERN": "SINJOH_CONTENT_AVAILABLE",
    "MAPSEC_MELEMELE_ISLAND": None, "MAPSEC_AKALA_ISLAND": None, "MAPSEC_AKALA_CAVE": None,
    "MAPSEC_AKALA_FOREST": None, "MAPSEC_ULAULA_ISLAND": None, "MAPSEC_ALOLA_OCEAN": None,
}

# Script files that only run in debug or on a fresh save.
SKIP_COMMON_SCRIPTS = {"debug.inc", "new_game.inc"}

# Vars and flags that do not keep story state.
TEMP_VAR_RE = re.compile(r"^VAR_(TEMP_|0x|RESULT$|FACING$|ITEM_ID$|LAST_TALKED$|SPECIAL_)")
TEMP_FLAG_RE = re.compile(r"^FLAG_(TEMP_|SYS_CTRL_OBJ_DELETE$|HIDE_MAP_NAME_POPUP$)")

# Script commands that overwrite VAR_RESULT, besides check* and get*.
RESULT_WRITERS = {"yesnobox", "multichoice", "multichoicedefault", "multichoicegrid",
                  "dynmultichoice", "giveitem", "giveitem_norandom", "giveitem_msg", "giveitem_unless_owned",
                  "additem", "removeitem", "givemon", "giveegg", "random", "trainerbattle",
                  "dofieldeffect"}

GIFT_OPS = {"giveitem", "giveitem_norandom", "giveitem_unless_owned", "giveitem_msg", "additem"}

# Key items a player never holds at the same time; each group takes one slot.
# Mach and Acro Bike: Rydel swaps them (MauvilleCity_BikeShop, removeitem before giveitem).
EXCLUSIVE_KEY_ITEMS = [("ITEM_MACH_BIKE", "ITEM_ACRO_BIKE")]
SILENT_GIFT_OPS = {"giveitem_msg", "additem"}


class Finding:
    """One result line; status and severity follow the audit scale."""

    def __init__(self, check, status, severity, title, evidence, text):
        self.check = check
        self.status = status
        self.severity = severity
        self.title = title
        self.evidence = evidence
        self.text = text

    def as_dict(self):
        return {"check": self.check, "status": self.status, "severity": self.severity,
                "title": self.title, "evidence": self.evidence, "text": self.text}


# ---------------------------------------------------------------- repository

class Repo:
    """File access, active maps and parsed scripts of one checkout."""

    def __init__(self, root):
        self.root = os.path.abspath(root)
        self._lines = {}
        self._scripts = {}
        self.active_maps = set()
        self.map_json = {}
        for path in glob.glob(os.path.join(self.root, "data/maps/*/map.json")):
            name = os.path.basename(os.path.dirname(path))
            with open(path, encoding="utf-8") as f:
                data = json.load(f)
            self.map_json[name] = data
            if data.get("game_version") == "hns":
                self.active_maps.add(name)
        self.config = self._read_config_symbols()
        self.locked = set()
        for name in self.active_maps:
            mapsec = self.map_json[name].get("region_map_section")
            if mapsec in LOCKED_MAPSECS and not self.config.get(LOCKED_MAPSECS[mapsec] or "", 0):
                self.locked.add(name)
        self.unreachable = set()
        self.labels = {}
        self.refs = collections.defaultdict(list)
        for rel in self.script_files():
            for idx, entry in enumerate(self.script(rel)):
                if entry[0] == "label":
                    self.labels.setdefault(entry[1], (rel, idx))
                elif entry[1] in ("goto", "call") and entry[2]:
                    self.refs[entry[2][0]].append((rel, idx))
                elif entry[1].startswith(("goto_if", "call_if")) and entry[2]:
                    self.refs[entry[2][-1]].append((rel, idx))

    def path(self, rel):
        return os.path.join(self.root, rel)

    def exists(self, rel):
        return os.path.exists(self.path(rel))

    def lines(self, rel):
        if rel not in self._lines:
            with open(self.path(rel), encoding="utf-8", errors="replace") as f:
                self._lines[rel] = f.read().split("\n")
        return self._lines[rel]

    def text(self, rel):
        return "\n".join(self.lines(rel))

    def _read_config_symbols(self):
        symbols = dict(PP_SYMBOLS)
        for rel in ("include/config/randomizer.h", "include/config/general.h",
                    "include/config/item.h"):
            if not self.exists(rel):
                continue
            for m in re.finditer(r"^#define\s+(\w+)\s+(TRUE|FALSE|\d+)\b",
                                 self.text(rel), re.M):
                value = m.group(2)
                symbols[m.group(1)] = PP_SYMBOLS[value] if value in PP_SYMBOLS else int(value)
        return symbols

    def map_scripts(self):
        """Active map script files, sorted."""
        out = []
        for name in sorted(self.active_maps):
            rel = "data/maps/%s/scripts.inc" % name
            if self.exists(rel):
                out.append(rel)
        return out

    def map_of(self, rel):
        """Map name of a map script file, None for common scripts."""
        m = re.match(r"data/maps/([^/]+)/", rel)
        return m.group(1) if m else None

    def reachable_file(self, rel):
        name = self.map_of(rel)
        return name not in self.unreachable and name not in self.locked

    def common_scripts(self):
        out = []
        for path in sorted(glob.glob(self.path("data/scripts/*.inc"))):
            if os.path.basename(path) not in SKIP_COMMON_SCRIPTS:
                out.append(os.path.relpath(path, self.root))
        return out

    def script_files(self):
        return self.map_scripts() + self.common_scripts()

    def pp_lines(self, rel):
        """Lines with inactive #if branches blanked."""
        key = ("pp", rel)
        if key not in self._lines:
            self._lines[key] = preprocess(self.lines(rel), self.config)
        return self._lines[key]

    def script(self, rel):
        """Parsed script file: [("label", name, line) | ("op", op, args, line)]."""
        if rel not in self._scripts:
            self._scripts[rel] = parse_script(self.pp_lines(rel))
        return self._scripts[rel]


# --------------------------------------------------------- script parsing

def eval_condition(expr, symbols):
    """Evaluates an #if expression; None if it uses unknown symbols."""
    expr = re.sub(r"@.*$", "", expr).strip()
    expr = re.sub(r"defined\s*\(\s*(\w+)\s*\)",
                  lambda m: "1" if m.group(1) in PP_DEFINED or m.group(1) in symbols else "0", expr)
    unknown = False

    def repl(m):
        nonlocal unknown
        word = m.group(0)
        if word in symbols and symbols[word] is not None:
            return str(symbols[word])
        if word in ("and", "or", "not"):
            return word
        unknown = True
        return "0"

    expr = re.sub(r"[A-Za-z_]\w*", repl, expr)
    if unknown:
        return None
    expr = expr.replace("&&", " and ").replace("||", " or ")
    expr = re.sub(r"!(?!=)", " not ", expr)
    try:
        return bool(eval(expr, {"__builtins__": {}}, {}))  # only digits and operators remain
    except Exception:
        return None


def preprocess(lines, symbols):
    """Blanks lines of inactive #if branches; keeps line numbers.

    Unknown conditions keep the #if branch and drop the #else branch."""
    out = []
    stack = []  # [parent_active, branch_taken, this_active]
    for line in lines:
        s = line.strip()
        m = re.match(r"#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)", s)
        if not m:
            active = all(frame[2] for frame in stack)
            out.append(line if active else "")
            continue
        kind, rest = m.group(1), m.group(2)
        parent = all(frame[2] for frame in stack)
        if kind in ("if", "ifdef", "ifndef"):
            if kind == "if":
                value = eval_condition(rest, symbols)
            else:
                name = rest.split()[0] if rest.split() else ""
                value = name in PP_DEFINED or (name in symbols and symbols[name] is not None)
                if kind == "ifndef":
                    value = not value
            value = True if value is None else value
            stack.append([parent, value, value])
        elif kind == "elif" and stack:
            frame = stack[-1]
            value = eval_condition(rest, symbols)
            value = False if value is None else value
            frame[2] = (not frame[1]) and value
            frame[1] = frame[1] or value
        elif kind == "else" and stack:
            frame = stack[-1]
            frame[2] = not frame[1]
            frame[1] = True
        elif kind == "endif" and stack:
            stack.pop()
        out.append("")
    return out


LABEL_RE = re.compile(r"^([A-Za-z_]\w*)::?\s*(@.*)?$")
OP_RE = re.compile(r"^\s+([A-Za-z_]\w*)\b(.*)$")


def parse_script(lines):
    entries = []
    for no, line in enumerate(lines, 1):
        if not line.strip():
            continue
        m = LABEL_RE.match(line)
        if m:
            entries.append(("label", m.group(1), no))
            continue
        m = OP_RE.match(line)
        if not m or m.group(1).startswith("."):
            continue
        args = re.sub(r"\s@.*$", "", m.group(2)).strip()
        entries.append(("op", m.group(1), [a.strip() for a in args.split(",")] if args else [], no))
    return entries


def is_state_change(op, args):
    """True for commands that keep story state in the save."""
    if op in ("setflag", "settrainerflag") and args:
        return not TEMP_FLAG_RE.match(args[0])
    if op in ("setvar", "addvar", "subvar", "copyvar") and args:
        return not TEMP_VAR_RE.match(args[0])
    return op in ("removeitem", "removemoney", "setrespawn")


def is_result_check(op, args):
    return op.startswith(("goto_if", "call_if")) and args and args[0] == "VAR_RESULT"


def writes_result(op, args):
    if op in RESULT_WRITERS or op.startswith(("check", "get")):
        return True
    if op == "msgbox" and any("YESNO" in a for a in args):
        return True
    return op in ("specialvar", "setvar", "copyvar") and bool(args) and args[0] == "VAR_RESULT"


# ------------------------------------------------------------------- items

def load_item_pockets(repo):
    """ITEM_* -> pocket name (TMs and HMs by name)."""
    pockets = {}
    rel = "src/data/items.h"
    if not repo.exists(rel):
        return pockets
    text = repo.text(rel)
    for m in re.finditer(r"^    \[(ITEM_\w+)\]\s*=\s*\{?(.*?)^    \},", text, re.S | re.M):
        pm = re.search(r"\.pocket\s*=\s*(POCKET_\w+)", m.group(2))
        if pm:
            pockets[m.group(1)] = pm.group(1)
    return pockets


def load_item_aliases(repo):
    """Old item names -> current ones (ITEM_X = ITEM_Y in the item enum)."""
    aliases = {}
    rel = "include/constants/items.h"
    if repo.exists(rel):
        for m in re.finditer(r"^\s*(ITEM_\w+)\s*=\s*(ITEM_\w+)\s*,", repo.text(rel), re.M):
            aliases[m.group(1)] = m.group(2)
    return aliases


def pocket_of(item, pockets):
    if re.match(r"ITEM_(TM|HM)\w*$", item):
        return "POCKET_TM_HM"
    return pockets.get(item)


def combined_pocket(pocket, combined):
    if combined and pocket == "POCKET_TREASURES":
        return "POCKET_ITEMS"
    if combined and pocket == "POCKET_BATTLE_ITEMS":
        return "POCKET_MEDICINE"
    return pocket


def pocket_sizes(repo):
    """Pocket -> slot count for the active I_COMBINE_BAG_POCKETS branch."""
    combined = bool(repo.config.get("I_COMBINE_BAG_POCKETS", 0))
    text = repo.text("include/constants/global.h")
    block = re.search(r"#if I_COMBINE_BAG_POCKETS == TRUE(.*?)#else(.*?)#endif", text, re.S)
    body = block.group(1) if combined else block.group(2)
    sizes = {}
    names = {"ITEMS": "POCKET_ITEMS", "KEYITEMS": "POCKET_KEY_ITEMS",
             "POKEBALLS": "POCKET_POKE_BALLS", "TMHM": "POCKET_TM_HM",
             "BERRIES": "POCKET_BERRIES", "MEDICINE": "POCKET_MEDICINE",
             "BATTLE_ITEMS": "POCKET_BATTLE_ITEMS", "TREASURES": "POCKET_TREASURES"}
    for m in re.finditer(r"#define BAG_(\w+)_COUNT\s+\(?([\d\s+]+)\)?", body):
        if m.group(1) in names:
            sizes[names[m.group(1)]] = sum(int(x) for x in m.group(2).split("+"))
    return sizes, combined


def obtainable_items(repo):
    """ITEM_* -> [source] for gifts, item balls, hidden items, marts and C code."""
    sources = collections.defaultdict(list)
    marts = set()
    for rel in repo.script_files():
        for entry in repo.script(rel):
            if entry[0] == "op" and entry[1] == "pokemart" and entry[2]:
                marts.add(entry[2][0])
        for entry in repo.script(rel):
            if entry[0] != "op":
                continue
            _, op, args, no = entry
            item = None
            if op in ("giveitem", "giveitem_norandom", "giveitem_unless_owned", "finditem",
                      "additem") and args:
                item = args[0]
            elif op == "giveitem_msg" and len(args) > 1:
                item = args[1]
            if item and item.startswith("ITEM_") and repo.reachable_file(rel):
                sources[item].append("%s:%d" % (rel, no))
    for rel in repo.script_files():
        if not repo.reachable_file(rel):
            continue
        lines = repo.pp_lines(rel)
        for no, line in enumerate(lines, 1):
            m = LABEL_RE.match(line)
            if not m or m.group(1) not in marts:
                continue
            for no2 in range(no, len(lines)):
                s2 = lines[no2].strip()
                if not s2:
                    continue
                m2 = re.match(r"\.2byte\s+(ITEM_\w+)", s2)
                if not m2 or m2.group(1) == "ITEM_NONE":
                    break
                sources[m2.group(1)].append("%s:%d (Laden)" % (rel, no2 + 1))
    for name in sorted(repo.active_maps - repo.locked - repo.unreachable):
        data = repo.map_json[name]
        for e in data.get("bg_events", []):
            if e.get("type") == "hidden_item" and str(e.get("item", "")).startswith("ITEM_"):
                sources[e["item"]].append("data/maps/%s/map.json (versteckt %s,%s)"
                                          % (name, e.get("x"), e.get("y")))
        for e in data.get("object_events", []):
            item = e.get("trainer_sight_or_berry_tree_id")
            if isinstance(item, str) and item.startswith("ITEM_") \
                    and "ITEM_BALL" in str(e.get("graphics_id", "")):
                sources[item].append("data/maps/%s/map.json (Ball %s,%s)" % (name, e.get("x"), e.get("y")))
    for path in glob.glob(repo.path("src/*.c")):
        rel = os.path.relpath(path, repo.root)
        if os.path.basename(rel) in ("debug.c",):
            continue
        for no, line in enumerate(repo.lines(rel), 1):
            m = re.search(r"\bAddBagItem\(\s*(ITEM_\w+)", line)
            if m:
                sources[m.group(1)].append("%s:%d" % (rel, no))
    return sources


# ------------------------------------------------------------- check: gifts

def follow(repo, rel, idx, depth=0, seen=None):
    """Yields ops on the fallthrough path from entry idx; follows goto and call."""
    if seen is None:
        seen = set()
    entries = repo.script(rel)
    while idx < len(entries):
        entry = entries[idx]
        idx += 1
        if entry[0] == "label":
            if (rel, entry[1]) in seen:
                return
            seen.add((rel, entry[1]))
            continue
        _, op, args, no = entry
        yield rel, op, args, no
        if op in ("end", "return"):
            return
        if op in ("goto", "call") and args and depth < 4:
            target = repo.labels.get(args[0])
            if target:
                sub = follow(repo, target[0], target[1], depth + 1, seen)
                for item in sub:
                    yield item
                    if item[1] == "end" and op == "call":
                        return
            if op == "goto":
                return


def block_before(repo, rel, idx):
    """Ops of the same label block before entry idx, nearest first."""
    entries = repo.script(rel)
    j = idx - 1
    while j >= 0 and entries[j][0] == "op":
        yield entries[j]
        j -= 1


def every_path_has(repo, rel, idx, pred, depth=0, seen=None):
    """True if every way into entry idx passes an op matching pred first.

    Walks back through the label block, then through fall-through and every
    goto/call to the block's labels (up to depth 4)."""
    if seen is None:
        seen = set()
    entries = repo.script(rel)
    j = idx - 1
    while j >= 0 and entries[j][0] == "op":
        if pred(entries[j]):
            return True
        j -= 1
    if j < 0 or depth >= 4:
        return False
    starts = []
    labels = []
    while j >= 0 and entries[j][0] == "label":
        labels.append(entries[j][1])
        j -= 1
    if j >= 0 and entries[j][1] not in ("end", "return", "goto"):
        starts.append((rel, j + 1))
    for label in labels:
        starts += repo.refs.get(label, [])
    if not starts:
        return False
    result = True
    for start in starts:
        if start in seen:
            continue
        seen.add(start)
        result = result and every_path_has(repo, start[0], start[1], pred, depth + 1, seen)
    return result


def check_gifts(repo, ctx):
    findings = []
    pockets = ctx["pockets"]
    sizes, combined = ctx["pocket_sizes"]
    for rel in repo.script_files():
        entries = repo.script(rel)
        for idx, entry in enumerate(entries):
            if entry[0] != "op" or entry[1] not in GIFT_OPS:
                continue
            _, op, args, no = entry
            item = args[1] if op == "giveitem_msg" and len(args) > 1 else (args[0] if args else "")
            if not item.startswith(("ITEM_", "VAR_")):
                continue
            if not repo.reachable_file(rel):
                ctx["skipped_unreachable"].add(repo.map_of(rel))
                continue
            prechecked = every_path_has(repo, rel, idx, lambda e: e[1] == "checkitemspace")
            traded = None
            for prev in block_before(repo, rel, idx):
                if prev[1] == "checkitemspace":
                    break
                if prev[1] == "removeitem" and traded is None:
                    traded = prev
            problem = None
            if traded is not None and not prechecked:
                problem = ("Tausch", traded[3], "removeitem %s" % ", ".join(traded[2]))
            elif not prechecked:
                result_live = True
                for frel, fop, fargs, fno in follow(repo, rel, idx + 1):
                    if result_live and is_result_check(fop, fargs):
                        break
                    if is_state_change(fop, fargs):
                        problem = ("Zustand", fno, "%s %s" % (fop, ", ".join(fargs)), frel)
                        break
                    if writes_result(fop, fargs):
                        # A later VAR_RESULT check no longer refers to the gift.
                        result_live = False
            if not problem:
                continue
            real = ctx["aliases"].get(item, item)
            pocket = combined_pocket(pocket_of(real, pockets), combined) if item.startswith("ITEM_") else None
            where = "%s:%d" % (rel, no)
            if problem[0] == "Tausch":
                evidence = "%s (%s in Zeile %d)" % (where, problem[2], problem[1])
                title = "Tausch ohne Platzprüfung: %s" % item
                text = ("Das Skript nimmt dem Spieler zuerst ein Item ab und gibt dann %s, ohne vorher "
                        "checkitemspace zu prüfen. Ist das Fach voll, ist das abgegebene Item weg und "
                        "das neue nicht im Beutel." % item)
            else:
                state_file = problem[3] if len(problem) > 3 else rel
                evidence = "%s -> %s:%d (%s)" % (where, state_file, problem[1], problem[2])
                how = "ohne Meldung (%s)" % op if op in SILENT_GIFT_OPS else "mit „Beutel voll“-Meldung"
                title = "Geschenk ohne Prüfung auf vollen Beutel: %s" % item
                text = ("%s wird %s gegeben; danach wird Spielzustand gesetzt, bevor VAR_RESULT "
                        "geprüft wird. Bei vollem Fach (oder 999 Stück) ist das Geschenk verloren "
                        "und lässt sich nicht erneut holen." % (item, how))
            if pocket is None:
                # Item from a variable: any pocket.
                safe = all(p in ctx["pocket_fits_random"] for p in sizes)
                plain = all(p in ctx["pocket_fits"] for p in sizes)
            else:
                safe = pocket in ctx["pocket_fits_random"]
                plain = pocket in ctx["pocket_fits"]
            if safe:
                status, severity = "vorschlag", "optional"
                text += (" Das Fach %s (%d Plätze) fasst alle erhältlichen Items (Prüfung pockets); "
                         "voll wird es nur bei 999 Stück." % (pocket, sizes.get(pocket, 0)))
            elif plain:
                status, severity = "vorschlag", "optional"
                text += (" Ohne Randomizer fasst das Fach alle erhältlichen Items; nur mit "
                         "Item-Randomizer kann es voll werden (Prüfung pockets).")
            else:
                status, severity = "nachgewiesen", "klein"
                if pocket:
                    text += " Fach: %s (%d Plätze)." % (pocket, sizes.get(pocket, 0))
            findings.append(Finding("gifts", status, severity, title, evidence, text))
    return findings


# ----------------------------------------------------------- check: pockets

def held_at_once(pocket, items):
    """Most items of the set a player can hold at once in the pocket."""
    count = len(items)
    if pocket == "POCKET_KEY_ITEMS":
        for group in EXCLUSIVE_KEY_ITEMS:
            count -= max(0, len(items & set(group)) - 1)
    return count


def check_pockets(repo, ctx):
    findings = []
    pockets = ctx["pockets"]
    sizes, combined = ctx["pocket_sizes"]
    sources = ctx["sources"]
    removed = set()
    for rel in repo.script_files():
        for entry in repo.script(rel):
            if entry[0] == "op" and entry[1] == "removeitem" and entry[2]:
                removed.add(ctx["aliases"].get(entry[2][0], entry[2][0]))
    by_pocket = collections.defaultdict(set)
    unknown = []
    for item in sources:
        if item == "ITEM_NONE":
            continue
        item = ctx["aliases"].get(item, item)
        pocket = pocket_of(item, pockets)
        if pocket is None:
            unknown.append(item)
            continue
        by_pocket[combined_pocket(pocket, combined)].add(item)
    lines = []
    for pocket in sorted(sizes):
        items = by_pocket.get(pocket, set())
        held = held_at_once(pocket, items)
        if held != len(items):
            lines.append("%s: %d erhältlich, höchstens %d gleichzeitig, %d Plätze"
                         % (pocket, len(items), held, sizes[pocket]))
        else:
            lines.append("%s: %d erhältlich, %d Plätze" % (pocket, len(items), sizes[pocket]))
        if held > sizes[pocket]:
            findings.append(Finding(
                "pockets", "verdacht", "klein",
                "Fach %s kann voll werden" % pocket,
                "include/constants/global.h (BAG_*_COUNT); %d verschiedene Items" % len(items),
                "Im Spiel gibt es %d verschiedene Items für %s (höchstens %d gleichzeitig), das Fach "
                "hat %d Plätze. Ein Spieler, der alles sammelt, füllt es; Geschenke ohne Prüfung "
                "(Prüfung gifts) gehen dann verloren, Fundbälle bleiben liegen."
                % (len(items), pocket, held, sizes[pocket])))
    ctx["pocket_fits"] = {p: held_at_once(p, by_pocket.get(p, set())) for p in sizes
                          if held_at_once(p, by_pocket.get(p, set())) <= sizes[p]}
    # The item randomizer turns found and given items into whitelist items.
    whitelist = set()
    rel = "src/data/randomizer/item_whitelist.h"
    if repo.config.get("RANDOMIZER_AVAILABLE") and repo.exists(rel):
        whitelist = set(re.findall(r"^\s*(ITEM_\w+),", repo.text(rel), re.M))
    ctx["pocket_fits_random"] = {}
    for pocket in sorted(sizes):
        extra = {i for i in whitelist
                 if combined_pocket(pocket_of(ctx["aliases"].get(i, i), pockets), combined) == pocket}
        total = len(by_pocket.get(pocket, set()) | extra)
        if pocket in ("POCKET_KEY_ITEMS", "POCKET_TM_HM"):
            total = held_at_once(pocket, by_pocket.get(pocket, set()))  # key items and TMs stay in kind
        lines.append("%s mit Item-Randomizer: bis %d verschiedene" % (pocket, total))
        if total <= sizes[pocket]:
            ctx["pocket_fits_random"][pocket] = total
        elif pocket in ctx["pocket_fits"]:
            findings.append(Finding(
                "pockets", "verdacht", "klein",
                "Mit Item-Randomizer kann %s voll werden" % pocket,
                "%s (%d Einträge); include/constants/global.h BAG_*_COUNT" % (rel, len(whitelist)),
                "Ohne Randomizer gibt es %d verschiedene Items für %s, mit dem Item-Randomizer bis "
                "zu %d (Positivliste), das Fach hat %d Plätze. Wer viel sammelt, füllt es; dann "
                "gehen Geschenke ohne Platzprüfung verloren (Prüfung gifts)."
                % (len(by_pocket.get(pocket, ())), pocket, total, sizes[pocket])))
    key = by_pocket.get("POCKET_KEY_ITEMS", set())
    kept = sorted(key - removed)
    margin = sizes.get("POCKET_KEY_ITEMS", 0) - held_at_once("POCKET_KEY_ITEMS", key)
    if 0 <= margin < 10:
        findings.append(Finding(
            "pockets", "vorschlag", "optional",
            "Basis-Fach: nur %d Plätze Reserve" % margin,
            "include/constants/global.h BAG_KEYITEMS_COUNT %d; %d Basis-Items erhältlich, "
            "höchstens %d gleichzeitig (EXCLUSIVE_KEY_ITEMS)"
            % (sizes["POCKET_KEY_ITEMS"], len(key), held_at_once("POCKET_KEY_ITEMS", key)),
            "Drei Regionen geben %d verschiedene Basis-Items aus, %d davon behält der Spieler für "
            "immer. Neue Basis-Items (z. B. weitere Regionen-Tickets) sollten das Fach im Blick "
            "behalten; die Zählung sieht nur Skripte und AddBagItem im C-Code." % (len(key), len(kept))))
    ctx["pocket_lines"] = lines
    ctx["key_items"] = (sorted(key), kept)
    ctx["unknown_items"] = sorted(unknown)
    return findings


# ----------------------------------------------------------- check: newgame

def struct_members(text, name):
    """[(member, is_array)] of a struct in a header."""
    m = re.search(r"^struct %s\s*\{(.*?)^\};" % name, text, re.S | re.M)
    if not m:
        return []
    members = []
    for line in m.group(1).split("\n"):
        line = re.sub(r"//.*", "", line).strip()
        mm = re.match(r"(?:\w+\s+)+\**(\w+)\s*(\[[^\]]*\])?\s*(:\s*\d+)?\s*;", line)
        if mm:
            members.append((mm.group(1), bool(mm.group(2))))
    return members


def check_newgame(repo, ctx):
    """Arrays in ChallengeSettings written through a pointer are game state, not settings.

    NewGameInitData keeps ChallengeSettings; such state must be cleared on the way
    into a new game (a memset in the new game speech that does not restore it)."""
    findings = []
    members = struct_members(repo.text("include/global.h"), "ChallengeSettings")
    owners = {"src/challenge_menu.c", "src/new_game.c", "src/debug.c"}
    new_game = repo.text("src/new_game.c")
    init = re.search(r"void NewGameInitData\(void\)\s*\{(.*?)^\}", new_game, re.S | re.M)
    keeps = bool(init) and "savedChallenge" in init.group(1)
    resets = []
    for path in sorted(glob.glob(repo.path("src/oak_speech*.c"))):
        rel = os.path.relpath(path, repo.root)
        for no, line in enumerate(repo.lines(rel), 1):
            if re.search(r"memset\(\s*&gSaveBlock3Ptr->challengeSettings\s*,\s*0\b", line):
                resets.append((rel, no))
    for member, is_array in members:
        writers = []
        address = re.compile(r"(?:^|[=(,]|return)\s*&\s*gSaveBlock3Ptr->challengeSettings\.%s\b" % member)
        indexed = re.compile(r"challengeSettings\.%s\s*\[[^\]]*\]\s*([-+|&^]?=)(?!=)" % member)
        for path in sorted(glob.glob(repo.path("src/*.c"))):
            rel = os.path.relpath(path, repo.root)
            if rel in owners:
                continue
            for no, line in enumerate(repo.lines(rel), 1):
                if address.search(line) or (is_array and indexed.search(line)):
                    writers.append("%s:%d" % (rel, no))
        if not writers or not keeps:
            continue
        restore = re.compile(r"challengeSettings\.%s\s*=\s*saved\w*\.%s\b" % (member, member))
        cleared_by = [r for r in resets if not any(restore.search(l) for l in repo.lines(r[0]))]
        if init and re.search(r"\b%s\b" % member, init.group(1)):
            continue
        if cleared_by:
            ctx["notes"].append("newgame: Spielzustand ChallengeSettings.%s wird beim neuen Spiel in %s "
                                "genullt (Weg über das Challenge-Menü)"
                                % (member, ", ".join("%s:%d" % r for r in cleared_by)))
            continue
        findings.append(Finding(
            "newgame", "nachgewiesen", "wichtig",
            "Neues Spiel übernimmt %s aus dem alten Spielstand" % member,
            "src/new_game.c NewGameInitData (savedChallenge); geschrieben in %s" % ", ".join(writers[:4]),
            "ChallengeSettings.%s ist Spielzustand (im Spiel über einen Zeiger geschrieben), liegt "
            "aber in den Einstellungen, die NewGameInitData über ClearSav3 hinweg rettet, und kein "
            "Schritt des neuen Spiels setzt ihn zurück. Wer im Titelmenü ein neues Spiel über einem "
            "bestehenden Spielstand beginnt, erbt diesen Zustand." % member))
    return findings


# -------------------------------------------------------- check: migrations

def check_migrations(repo, ctx):
    findings = []
    save = repo.text("src/save.c")
    flags = sorted(set(re.findall(r"FlagGet\((FLAG_MIGRATED_\w+)\)", save)))
    oj_rel = "include/constants/flags_origin_jade.h"
    oj = repo.text(oj_rel) if repo.exists(oj_rel) else ""
    new_game = repo.text("data/scripts/new_game.inc")
    for flag in flags:
        if not re.search(r"#define\s+%s\b" % flag, oj):
            findings.append(Finding("migrations", "nachgewiesen", "wichtig",
                                    "Migrations-Flag %s nicht im Origin-Jade-Block" % flag,
                                    "src/save.c", "D-017 verlangt ein Flag aus flags_origin_jade.h."))
        if not re.search(r"setflag\s+%s\b" % flag, new_game):
            findings.append(Finding("migrations", "nachgewiesen", "wichtig",
                                    "Neues Spiel setzt %s nicht" % flag,
                                    "data/scripts/new_game.inc",
                                    "Ohne das Flag läuft die Migration beim ersten Laden eines neuen "
                                    "Spielstands und verändert frischen Zustand (D-017)."))
    ctx["notes"].append("migrations: %d Migrations-Flags geprüft (%s)" % (len(flags), ", ".join(flags)))
    return findings


# --------------------------------------------------------------- check: hof

HOF_SPECIALS = ("GameClear", "GameClearNoCredits", "EnterHallOfFame")


def check_hof(repo, ctx):
    findings = []
    limits = {}
    for path in sorted(glob.glob(repo.path("src/hall_of_fame*.c"))):
        rel = os.path.relpath(path, repo.root)
        for no, line in enumerate(repo.lines(rel), 1):
            m = re.match(r"#define HALL_OF_FAME_MAX_TEAMS\s+(\d+)", line)
            if m:
                limits[rel] = (int(m.group(1)), no)
    viewer = None
    if repo.exists("src/hof_pc.c"):
        text = repo.text("src/hof_pc.c")
        # The jade build is not IS_FRLG: take the else branch if there is one.
        m = re.search(r"if \(IS_FRLG\)\s*SetMainCallback2\(\w+\);\s*else\s*SetMainCallback2\((\w+)\)", text) \
            or re.search(r"SetMainCallback2\((\w+)\)", text)
        if m:
            for rel in limits:
                if re.search(r"^void %s\(void\)" % m.group(1), repo.text(rel), re.M):
                    viewer = (m.group(1), rel)
    if len({v[0] for v in limits.values()}) > 1:
        ev = ", ".join("%s:%d = %d" % (rel, no, n) for rel, (n, no) in sorted(limits.items()))
        text = ("Die Ruhmeshallen-Implementierungen teilen dieselben Save-Sektoren und dieselbe "
                "struct HallofFameTeam, rechnen aber mit verschiedenen Teamzahlen. Die Kanto-Ruhmeshalle "
                "(FRLG-Code) schreibt bis zur größeren Zahl; die Johto-/Hoenn-Ruhmeshalle und die "
                "PC-Anzeige sehen nur die kleinere. Sind mehr Kanto-Teams gespeichert, zeigt der PC "
                "die neuesten nicht, und der Emerald-Code schiebt nur die ersten Plätze weiter, "
                "die Einträge dahinter bleiben stehen.")
        if viewer:
            text += " PC-Anzeige: %s (%s)." % viewer
        findings.append(Finding("hof", "nachgewiesen", "klein",
                                "Ruhmeshalle: unterschiedliche Teamgrenzen", ev, text))
    for rel in repo.map_scripts():
        entries = repo.script(rel)
        for idx, entry in enumerate(entries):
            if entry[0] != "op" or entry[1] != "special" or not entry[2] or entry[2][0] not in HOF_SPECIALS:
                continue
            no = entry[3]
            has_respawn = every_path_has(repo, rel, idx, lambda e: e[1] == "setrespawn")
            if not has_respawn:
                findings.append(Finding("hof", "verdacht", "wichtig",
                                        "Ruhmeshalle ohne setrespawn davor",
                                        "%s:%d" % (rel, no),
                                        "Im HnS-Build übernimmt GameClear lastHealLocation als "
                                        "Fortsetzungspunkt; ohne setrespawn auf jedem Weg davor geht "
                                        "es beim Fortsetzen am letzten Pokémon-Center weiter."))
            for frel, fop, fargs, fno in follow(repo, rel, idx + 1):
                if fop in ("waitstate", "releaseall", "release", "end"):
                    continue
                if is_state_change(fop, fargs) or fop == "clearflag":
                    findings.append(Finding("hof", "nachgewiesen", "wichtig",
                                            "Zustand nach dem Ruhmeshallen-Speichern gesetzt",
                                            "%s:%d -> %s:%d" % (rel, no, frel, fno),
                                            "%s %s steht nach der Ruhmeshalle; der Spielstand ist "
                                            "da schon geschrieben." % (fop, ", ".join(fargs))))
                break
    ctx["hof_limits"] = limits
    ctx["notes"].append("hof: Teamgrenzen %s"
                        % ", ".join("%s=%d" % (r, n) for r, (n, _) in sorted(limits.items())))
    return findings


# --------------------------------------------------------------- check: rtc

def check_rtc(repo, ctx):
    findings = []
    weekday_maps = []
    time_maps = []
    for rel in repo.map_scripts():
        text = repo.text(rel)
        if re.search(r"\bGetWeekday\b", text):
            weekday_maps.append(rel.split("/")[2])
        if re.search(r"\b(gettime|GetTimeOfDay|dotimebasedevents)\b", text):
            time_maps.append(rel.split("/")[2])
    per_day = []
    if repo.exists("src/clock.c"):
        body = re.search(r"^static void UpdatePerDay\([^;{]*\)\s*\{(.*?)\n\}", repo.text("src/clock.c"),
                         re.S | re.M)
        if body:
            per_day = re.findall(r"^\s+(\w+)\((?:daysSince)?\);", body.group(1), re.M)
    defaults = repo.text("src/new_game.c")
    m = re.search(r"void SetDefaultChallengeSettings\(void\)\s*\{(.*?)^\}", defaults, re.S | re.M)
    rtc_default = "tx_Features_RTCType" in (m.group(1) if m else "")
    menu_callers = []
    for path in sorted(glob.glob(repo.path("src/*.c"))):
        rel = os.path.relpath(path, repo.root)
        if rel == "src/challenge_menu.c":
            continue
        for no, line in enumerate(repo.lines(rel), 1):
            if "CB2_InitChallengeMenu" in line:
                menu_callers.append("%s:%d" % (rel, no))
    dummy = re.search(r"sRtcDummy\s*=\s*\{([^}]*)\}", repo.text("src/rtc.c"))
    text = ("Ohne funktionierende RTC liefert RtcGetInfo immer sRtcDummy (%s); die Uhrzeit steht "
            "still, es gibt keinen Tageswechsel. UpdatePerDay läuft nie: %s. Wochentagsinhalte "
            "(special GetWeekday) sehen immer denselben Tag: %s. Uhrzeitabhängige Skripte: %d Karten. "
            % ((dummy.group(1).strip() if dummy else "?"), ", ".join(per_day) or "?",
               ", ".join(weekday_maps) or "keine", len(time_maps)))
    text += ("Der RTC-Typ steht in ChallengeSettings.tx_Features_RTCType; SetDefaultChallengeSettings "
             "%s (Standard 0: Hardware-RTC), änderbar nur im Challenge-Menü des neuen Spiels (%s)."
             % ("setzt ihn" if rtc_default else "setzt ihn nicht", ", ".join(menu_callers) or "?"))
    findings.append(Finding("rtc", "nachgewiesen", "wichtig",
                            "Ohne RTC: kein Tageswechsel, Wochentag fest",
                            "src/rtc.c RtcGetInfo/sRtcDummy; src/clock.c UpdatePerDay; src/new_game.c "
                            "SetDefaultChallengeSettings", text))
    ctx["rtc"] = {"weekday_maps": weekday_maps, "time_maps": time_maps, "per_day": per_day}
    return findings


# -------------------------------------------------------------- check: link

LINK_SCRIPT_RE = re.compile(r"CableClub|UnionRoom|WirelessClub|DirectCorner|RecordCorner|TradeCenter|"
                            r"Colosseum|MysteryGift|MysteryEvent|LinkContest|WonderNews|RecordMix")
LINK_SPECIAL_RE = re.compile(r"\bspecial\s+(TryTradeLinkup|TryBattleLinkup|TryBecomeLinkLeader|"
                             r"TryJoinLinkGroup|TryRecordMixLinkup|TryContest\w*Linkup|DoCableClubWarp|"
                             r"TrySetBattleTowerLinkType|EnableMysteryGift|EnableMysteryEvent)\b")


def check_link(repo, ctx):
    findings = []
    attendants = collections.defaultdict(list)
    for name in sorted(repo.active_maps):
        data = repo.map_json[name]
        for e in data.get("object_events", []) + data.get("bg_events", []):
            script = str(e.get("script", ""))
            if LINK_SCRIPT_RE.search(script) and not name.startswith(("UnionRoom", "TradeCenter",
                                                                     "BattleColosseum", "RecordCorner")):
                attendants[script].append("%s (%s,%s)" % (name, e.get("x"), e.get("y")))
    specials = []
    mg_enable = []
    for rel in repo.map_scripts():
        for no, line in enumerate(repo.lines(rel), 1):
            m = LINK_SPECIAL_RE.search(line)
            if m:
                target = mg_enable if m.group(1).startswith("Enable") else specials
                target.append("%s:%d %s" % (rel, no, m.group(1)))
            if re.search(r"setflag\s+FLAG_SYS_MYSTERY_(GIFT|EVENT)_ENABLE", line):
                mg_enable.append("%s:%d" % (rel, no))
    if attendants or specials:
        ev = "; ".join("%s: %d Karten, z. B. %s" % (s, len(v), v[0]) for s, v in sorted(attendants.items()))
        text = ("Auf aktiven Karten erreichbar: %s. Dazu Link-Specials: %s. Mystery-Gift-Freischaltung "
                "auf aktiven Karten: %s." % (ev, "; ".join(specials) or "keine",
                                             "; ".join(mg_enable) or "keine (Menüpunkt nur per Debug)"))
        evidence = "%d Ansprechpartner-Skripte, %d Link-Specials" % (len(attendants), len(specials))
        findings.append(Finding("link", "nachgewiesen", "optional",
                                "Link-Funktionen im Jade-Build erreichbar", evidence, text))
    ctx["link"] = {"attendants": dict(attendants), "specials": specials,
                   "mg_enable": mg_enable}
    return findings


# ------------------------------------------------------------------- driver

CHECKS = [("pockets", check_pockets), ("gifts", check_gifts), ("newgame", check_newgame),
          ("migrations", check_migrations), ("hof", check_hof), ("rtc", check_rtc),
          ("link", check_link)]


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--repo", default=REPO, help="checkout to read (default: this one)")
    parser.add_argument("--check", action="append", choices=[c[0] for c in CHECKS],
                        help="run only this check (repeatable)")
    parser.add_argument("--json", help="also write the findings as JSON to this file")
    parser.add_argument("--maps-json", help="check_maps.py JSON; its K-UNERREICHBAR maps are skipped")
    args = parser.parse_args()

    repo = Repo(args.repo)
    if args.maps_json:
        with open(args.maps_json, encoding="utf-8") as f:
            repo.unreachable = {e["map"] for e in json.load(f) if e.get("code") == "K-UNERREICHBAR"}
    ctx = {"pockets": load_item_pockets(repo), "pocket_sizes": pocket_sizes(repo),
           "aliases": load_item_aliases(repo), "skipped_unreachable": set(), "notes": []}
    ctx["sources"] = obtainable_items(repo)
    wanted = set(args.check or [c[0] for c in CHECKS])
    # pockets tells gifts which pockets can fill up, so it always runs first.
    findings = check_pockets(repo, ctx)
    if "pockets" not in wanted:
        findings = []
    for name, func in CHECKS:
        if name != "pockets" and name in wanted:
            findings += func(repo, ctx)

    findings.sort(key=lambda f: (SEVERITY_ORDER.index(f.severity), f.check, f.evidence))
    print("Prüfung Speicherkern: %s" % repo.root)
    print("Aktive Karten: %d, Skriptdateien: %d" % (len(repo.active_maps), len(repo.script_files())))
    if "pockets" in wanted:
        print("\nTaschen (verschiedene erhältliche Items / Plätze):")
        for line in ctx["pocket_lines"]:
            print("  " + line)
        key, kept = ctx["key_items"]
        print("  Basis-Items: %d erhältlich, %d werden nie abgegeben" % (len(key), len(kept)))
        if ctx["unknown_items"]:
            print("  Ohne Fach in items.h: %s" % ", ".join(ctx["unknown_items"]))
    if repo.locked:
        print("\nGesperrte Inhalte (LOCKED_MAPSECS), nicht geprüft: %d Karten" % len(repo.locked))
    if ctx["skipped_unreachable"]:
        print("Übersprungen (laut Kartenprüfung unerreichbar): %s"
              % ", ".join(sorted(ctx["skipped_unreachable"] - repo.locked)))
    for note in ctx["notes"]:
        print(note)
    counts = collections.Counter(f.severity for f in findings)
    summary = ", ".join("%s %d" % (s, counts[s]) for s in SEVERITY_ORDER if counts[s])
    print("\nBefunde: %d (%s)" % (len(findings), summary))
    for f in findings:
        print("\n[%s] %s/%s: %s" % (f.check, f.status, f.severity, f.title))
        print("  Beleg: %s" % f.evidence)
        print("  %s" % f.text)
    if args.json:
        with open(args.json, "w", encoding="utf-8") as out:
            json.dump({"repo": repo.root, "findings": [f.as_dict() for f in findings],
                       "pockets": ctx.get("pocket_lines"), "key_items": ctx.get("key_items"),
                       "hof_limits": ctx.get("hof_limits"), "rtc": ctx.get("rtc"),
                       "link": ctx.get("link")}, out, ensure_ascii=False, indent=1)
    return 1 if any(f.severity in ("blocker", "kritisch") for f in findings) else 0


if __name__ == "__main__":
    sys.exit(main())
