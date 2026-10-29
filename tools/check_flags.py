#!/usr/bin/env python3
"""Resolves every flag and var of the Origin Jade build and reports clashes.

Checks:
  1. Numbers with more than one name referenced by scripts, maps or C code.
  2. Trainer flags (TrainerIdToFlagId) and the match call registration window
     must not land on a named flag.
  3. The daily window holds only FLAG_DAILY_*.
  4. Every flag and var number has storage behind it.
  5. Item-ball and hidden-item flags are unique across all maps.
  6. Names defined by several region headers and used by maps of more than
     one region.

Values come from the C preprocessor (POKEMON_HNS build). Needs a host C
compiler (cc, or $CC).

Usage:
    python3 tools/check_flags.py            # short report
    python3 tools/check_flags.py --verbose  # every finding with its source
    python3 tools/check_flags.py --free     # also list free windows

Run it after every HnS merge and whenever flags, vars or trainers change.
Exit status 1 if anything was found that is not listed as a known alias.
"""

import argparse
import collections
import glob
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFINES = ["-DPOKEMON_HNS", "-DMODERN=1", "-DTESTING=0"]

# Emerald and FRLG names for the same flag. Not reported.
KNOWN_ALIASES = {
    frozenset({"FLAG_SYS_CYCLING_ROAD", "FLAG_SYS_ON_CYCLING_ROAD"}),
    frozenset({"FLAG_SYS_MYSTERY_EVENT_ENABLE", "FLAG_SYS_MYSTERY_GIFT_ENABLE"}),
    frozenset({"FLAG_SYS_PC_BILL", "FLAG_SYS_PC_LANETTE"}),
}

# Shared item-ball/hidden-item flags on HnS maps Origin Jade never reaches. Not reported.
KNOWN_SHARED_ITEM_FLAGS = {
    "FLAG_ITEM_VIRIDIANFOREST_ELIXIR",
    "FLAG_ITEM_VIRIDIANFOREST_MAX_POTION",
    "FLAG_ITEM_VIRIDIANFOREST_REVIVE",
    "FLAG_HIDE_CONTEST_POKE_BALL",
}

# Name prefixes that are aliases by construction: temp slots, placeholders,
# landmark numbers and the match call window.
ALIAS_PREFIXES = (
    "FLAG_TEMP_",
    "VAR_TEMP_",
    "FLAG_UNUSED",
    "VAR_UNUSED",
    "FLAG_SPECIAL_FLAG_UNUSED",
    "FLAG_LANDMARK_",
    "FLAG_REGISTERED_",
)

# Block anchor suffixes; an anchor shares its number with the block's first entry.
ANCHOR_SUFFIXES = ("_START", "_END", "_COUNT", "_BASE", "_SIZE")

# Header files whose definitions this tool checks; uses inside them do not
# count as references.
CONSTANT_HEADERS = re.compile(r"include/constants/(flags|vars)[a-z_]*\.h$")

# Region headers, in include order. Used by check 6.
REGION_HEADERS = [
    "flags_hns.h", "flags_hoenn_de.h", "flags_frlg_hns.h", "flags_origin_jade.h",
    "vars_hns.h", "vars_hoenn_de.h", "vars_frlg_hns.h", "vars_origin_jade.h",
]

# Anchors and window bounds the checks need besides the flags and vars.
EXTRA_MACROS = [
    "FLAGS_COUNT", "SPECIAL_FLAGS_START", "SPECIAL_FLAGS_END",
    "FRLG_FLAGS_START", "FRLG_FLAGS_END",
    "FRLG_TRAINER_FLAGS_START", "FRLG_TRAINER_FLAGS_END",
    "HNS_REMATCH_TIER_FLAGS_START", "HNS_REMATCH_TIER_FLAGS_END",
    "OJ_FLAGS_START", "OJ_FLAGS_END", "OJ_VARS_START", "OJ_VARS_END",
    "OJ_TRAINER_FLAGS_DAILY", "OJ_TRAINER_FLAGS_ENGINE",
    "DAILY_FLAGS_START", "DAILY_FLAGS_END", "ENGINE_FLAGS_START", "ENGINE_FLAGS_END",
    "TRAINER_FLAGS_START", "TRAINER_REGISTERED_FLAGS_START", "REMATCH_TABLE_ENTRIES",
    "FRLG_TRAINER_OFFSET", "FRLG_TRAINERS_END", "HNS_REMATCH_TIERS_START", "HNS_REMATCH_TIERS_END",
    "VARS_START", "VARS_END", "FRLG_VARS_START", "FRLG_VARS_END",
    "SPECIAL_VARS_START", "SPECIAL_VARS_END", "FLAG_HIDDEN_ITEMS_START",
]

PRELUDE = """#include <stdio.h>
#define TRUE 1
#define FALSE 0
#include "config/general.h"
#include "constants/global.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/rematches.h"
"""


def compiler():
    cc = os.environ.get("CC") or shutil.which("cc") or shutil.which("gcc") or shutil.which("clang")
    if not cc:
        sys.exit("check_flags.py needs a host C compiler (cc/gcc/clang or $CC).")
    return cc


def macro_names(cc, workdir):
    """All object-like macros visible after including the flag/var headers."""
    src = os.path.join(workdir, "macros.c")
    with open(src, "w") as fh:
        fh.write(PRELUDE)
    out = subprocess.run([cc, "-E", "-dM", "-Iinclude"] + DEFINES + [src],
                         cwd=REPO, capture_output=True, text=True)
    if out.returncode != 0:
        sys.exit("Preprocessing the flag headers failed:\n" + out.stderr)
    names = []
    for line in out.stdout.splitlines():
        m = re.match(r"#define (\w+) ", line)
        if m:
            names.append(m.group(1))
    return names


def evaluate(cc, workdir, names):
    """Compiles a program that prints every macro in `names` as a number.

    Macros that do not evaluate to an integer are dropped and the program is
    rebuilt until it compiles.
    """
    src = os.path.join(workdir, "dump.c")
    exe = os.path.join(workdir, "dump")
    names = list(names)
    for _ in range(100):
        with open(src, "w") as fh:
            fh.write(PRELUDE + "int main(void)\n{\n")
            for name in names:
                fh.write('    printf("%%s %%lld\\n", "%s", (long long)(%s));\n' % (name, name))
            fh.write("    return 0;\n}\n")
        out = subprocess.run([cc, "-w", "-Iinclude"] + DEFINES + [src, "-o", exe],
                             cwd=REPO, capture_output=True, text=True)
        if out.returncode == 0:
            break
        lines = open(src).read().split("\n")
        bad = set()
        for m in re.finditer(r"dump\.c:(\d+):\d+: (?:error|note: in expansion)", out.stderr):
            hit = re.search(r'"(\w+)", \(long long\)', lines[int(m.group(1)) - 1])
            if hit:
                bad.add(hit.group(1))
        if not bad:
            sys.exit("Could not evaluate the flag/var macros:\n" + out.stderr[:2000])
        names = [n for n in names if n not in bad]
    values = {}
    for line in subprocess.run([exe], capture_output=True, text=True).stdout.splitlines():
        name, value = line.split()
        values[name] = int(value)
    return values


def resolve_all():
    cc = compiler()
    with tempfile.TemporaryDirectory() as workdir:
        names = macro_names(cc, workdir)
        wanted = [n for n in names
                  if n.startswith(("FLAG_", "VAR_", "TRAINER_")) or n in EXTRA_MACROS]
        # Some bounds are enum values (REMATCH_TABLE_ENTRIES), not macros.
        wanted += [n for n in EXTRA_MACROS if n not in wanted]
        return evaluate(cc, workdir, wanted)


def source_files():
    """Script, map and C files whose references count as 'used'."""
    files = glob.glob(os.path.join(REPO, "data/maps/*/scripts.inc"))
    files += glob.glob(os.path.join(REPO, "data/maps/*/map.json"))
    files += glob.glob(os.path.join(REPO, "data/scripts/*.inc"))
    files += glob.glob(os.path.join(REPO, "data/*.s"))
    files += glob.glob(os.path.join(REPO, "src/**/*.[ch]"), recursive=True)
    files += glob.glob(os.path.join(REPO, "include/**/*.h"), recursive=True)
    return [f for f in files if not CONSTANT_HEADERS.search(os.path.relpath(f, REPO))]


def collect_references():
    """name -> set of map region tags ('hns', 'frlg', 'hoenn', 'common')."""
    token = re.compile(r"\b((?:FLAG|VAR)_\w+)\b")
    refs = collections.defaultdict(set)
    for path in source_files():
        rel = os.path.relpath(path, REPO)
        m = re.match(r"data/maps/([^/]+)/", rel)
        if m:
            d = m.group(1)
            region = "hns" if d.endswith("_hns") else "frlg" if d.endswith("_Frlg") else "hoenn"
        else:
            region = "common"
        text = open(path, encoding="utf-8", errors="replace").read()
        if path.endswith((".c", ".h")):
            text = re.sub(r"//[^\n]*", "", text)
            text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
        else:
            text = re.sub(r"@[^\n]*", "", text)
        for name in set(token.findall(text)):
            refs[name].add(region)
    return refs


def is_alias_name(name):
    return name.startswith(ALIAS_PREFIXES) or name.endswith(ANCHOR_SUFFIXES)


class Report:
    def __init__(self, verbose):
        self.verbose = verbose
        self.problems = 0

    def section(self, title, items, show=10):
        if not items:
            print("  ok   " + title)
            return
        self.problems += len(items)
        print("  FAIL %s: %d" % (title, len(items)))
        for item in (items if self.verbose else items[:show]):
            print("         " + item)
        if not self.verbose and len(items) > show:
            print("         ... %d more, --verbose shows all" % (len(items) - show))


def check_names(kind, prefix, values, refs, report):
    """Check 1: one number, several referenced names."""
    by_value = collections.defaultdict(list)
    for name, value in values.items():
        if name.startswith(prefix) and value > 0:
            by_value[value].append(name)
    clashes = []
    for value, names in sorted(by_value.items()):
        real = sorted(n for n in names if not is_alias_name(n) and n in refs)
        if len(real) > 1 and frozenset(real) not in KNOWN_ALIASES:
            clashes.append("0x%04X: %s" % (value, ", ".join(real)))
    report.section("%s: numbers used under more than one name" % kind, clashes)
    return by_value


def trainer_ids(values):
    ids = {}
    for party in ("src/data/trainers.party", "src/data/trainers_hns.party", "src/data/trainers_frlg.party"):
        path = os.path.join(REPO, party)
        if not os.path.exists(path):
            continue
        for line in open(path, encoding="utf-8"):
            m = re.match(r"^=== (TRAINER_\w+) ===", line)
            if m and m.group(1) in values:
                ids[m.group(1)] = values[m.group(1)]
    return ids


def trainer_flag(tid, v):
    """Mirror of TrainerIdToFlagId (src/battle_setup.c). Keep both in sync."""
    if v["FRLG_TRAINER_OFFSET"] < tid <= v["FRLG_TRAINERS_END"]:
        return v["FRLG_TRAINER_FLAGS_START"] + (tid - (v["FRLG_TRAINER_OFFSET"] + 1))
    if v["HNS_REMATCH_TIERS_START"] <= tid <= v["HNS_REMATCH_TIERS_END"]:
        return v["HNS_REMATCH_TIER_FLAGS_START"] + (tid - v["HNS_REMATCH_TIERS_START"])
    flag = v["TRAINER_FLAGS_START"] + tid
    if "OJ_TRAINER_FLAGS_DAILY" not in v:
        return flag
    if v["DAILY_FLAGS_START"] <= flag <= v["DAILY_FLAGS_END"]:
        return v["OJ_TRAINER_FLAGS_DAILY"] + (flag - v["DAILY_FLAGS_START"])
    if v["ENGINE_FLAGS_START"] <= flag <= v["ENGINE_FLAGS_END"]:
        return v["OJ_TRAINER_FLAGS_ENGINE"] + (flag - v["ENGINE_FLAGS_START"])
    return flag


def check_windows(values, flag_by_value, report):
    """Checks 2-4: computed windows and storage."""
    v = values
    named = {}
    for value, names in flag_by_value.items():
        real = [n for n in names if not is_alias_name(n)]
        if real:
            named[value] = real

    trainers = trainer_ids(values)
    hits = []
    seen = {}
    for name, tid in sorted(trainers.items(), key=lambda x: x[1]):
        flag = trainer_flag(tid, v)
        if flag in named:
            hits.append("%s (id %d) -> 0x%04X = %s" % (name, tid, flag, ", ".join(named[flag])))
        if flag in seen and seen[flag] != tid:
            hits.append("%s and %s share trainer flag 0x%04X" % (seen[flag], name, flag))
        seen.setdefault(flag, name)
    for i in range(v["REMATCH_TABLE_ENTRIES"]):
        flag = v["TRAINER_REGISTERED_FLAGS_START"] + i
        if flag in named:
            hits.append("match call registration #%d -> 0x%04X = %s" % (i, flag, ", ".join(named[flag])))
    report.section("flags written indirectly (trainer flags, match call window)", hits)

    daily = []
    for flag in range(v["DAILY_FLAGS_START"], v["DAILY_FLAGS_END"] + 1):
        for name in named.get(flag, []):
            if not name.startswith("FLAG_DAILY_"):
                daily.append("0x%04X %s is cleared every day" % (flag, name))
    report.section("daily window holds only FLAG_DAILY_*", daily)

    flag_windows = [
        (1, v["FLAGS_COUNT"] - 1),
        (v["FRLG_FLAGS_START"], v["FRLG_FLAGS_END"]),
        (v["FRLG_TRAINER_FLAGS_START"], v["FRLG_TRAINER_FLAGS_END"]),
        (v["HNS_REMATCH_TIER_FLAGS_START"], v["HNS_REMATCH_TIER_FLAGS_END"]),
        (v["OJ_FLAGS_START"], v["OJ_FLAGS_END"]),
        (v["SPECIAL_FLAGS_START"], v["SPECIAL_FLAGS_END"]),
    ]
    var_windows = [
        (v["VARS_START"], v["VARS_END"]),
        (v["FRLG_VARS_START"], v["FRLG_VARS_END"]),
        (v["OJ_VARS_START"], v["OJ_VARS_END"]),
        (v["SPECIAL_VARS_START"], v["SPECIAL_VARS_END"]),
    ]
    storage = []
    for name, value in sorted(values.items()):
        if value <= 0 or is_alias_name(name):
            continue
        if name.startswith("FLAG_"):
            windows = flag_windows
        elif name.startswith("VAR_"):
            windows = var_windows
        else:
            continue
        if not any(lo <= value <= hi for lo, hi in windows):
            storage.append("%s = 0x%04X has no storage" % (name, value))
    for name, tid in trainers.items():
        flag = trainer_flag(tid, v)
        if not any(lo <= flag <= hi for lo, hi in flag_windows):
            storage.append("%s (id %d) -> trainer flag 0x%04X has no storage" % (name, tid, flag))
    report.section("every flag and var has storage", storage)


def check_map_flags(values, report):
    """Check 5: item balls and hidden items need a flag of their own."""
    owners = collections.defaultdict(list)
    for path in sorted(glob.glob(os.path.join(REPO, "data/maps/*/map.json"))):
        d = os.path.basename(os.path.dirname(path))
        data = json.load(open(path, encoding="utf-8"))
        # Retired maps are not built.
        if data.get("game_version") != "hns":
            continue
        for obj in data.get("object_events") or []:
            flag = obj.get("flag", "0")
            if flag in KNOWN_SHARED_ITEM_FLAGS:
                continue
            if flag in values and values[flag] > 0 and "ITEM_BALL" in obj.get("graphics_id", ""):
                owners[values[flag]].append("%s item ball (%s)" % (d, flag))
        for bg in data.get("bg_events") or []:
            if bg.get("flag") in KNOWN_SHARED_ITEM_FLAGS:
                continue
            if bg.get("type") == "hidden_item" and bg.get("flag") in values:
                owners[values[bg["flag"]]].append("%s hidden item (%s)" % (d, bg["flag"]))
    shared = ["0x%04X: %s" % (k, "; ".join(o)) for k, o in sorted(owners.items()) if len(o) > 1]
    report.section("item-ball and hidden-item flags are unique", shared)


def check_region_headers(refs, report):
    """Check 6: a name redefined by a later region header, used by two regions."""
    defined_in = collections.defaultdict(set)
    for header in REGION_HEADERS:
        path = os.path.join(REPO, "include/constants", header)
        for line in open(path, encoding="utf-8"):
            m = re.match(r"#define\s+((?:FLAG|VAR)_\w+)\s", line)
            if m:
                defined_in[m.group(1)].add(header)
    shared = []
    for name, headers in sorted(defined_in.items()):
        regions = refs.get(name, set()) - {"common"}
        if len(headers) > 1 and len(regions) > 1:
            shared.append("%s: defined in %s, used by %s maps"
                          % (name, ", ".join(sorted(headers)), "/".join(sorted(regions))))
    # Info only, not an error.
    print("  info names redefined across region headers and used by several regions: %d" % len(shared))
    for item in shared:
        print("         " + item)


def list_free(kind, prefix, values):
    used = sorted(set(v for n, v in values.items() if n.startswith(prefix) and v > 0))
    if not used:
        return
    used_set = set(used)
    gaps, run = [], None
    for i in range(used[0], used[-1] + 1):
        if i not in used_set:
            if run is None:
                run = i
        elif run is not None:
            gaps.append((run, i - 1))
            run = None
    big = [g for g in gaps if g[1] - g[0] >= 7]
    print("  %s: free windows of at least 8 slots: %d" % (kind, len(big)))
    for a, b in big[:20]:
        print("         0x%04X-0x%04X (%d)" % (a, b, b - a + 1))
    print("         Note: windows that are filled at runtime (trainer flags,")
    print("         match call registration) look free here.")


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--verbose", action="store_true", help="every finding with its source")
    parser.add_argument("--free", action="store_true", help="also list free windows")
    args = parser.parse_args()

    values = resolve_all()
    refs = collect_references()
    report = Report(args.verbose)

    print("Origin Jade flag/var check (%d flags, %d vars resolved)" % (
        sum(n.startswith("FLAG_") for n in values), sum(n.startswith("VAR_") for n in values)))
    flag_by_value = check_names("flags", "FLAG_", values, refs, report)
    check_names("vars", "VAR_", values, refs, report)
    check_windows(values, flag_by_value, report)
    check_map_flags(values, report)
    check_region_headers(refs, report)
    if args.free:
        list_free("flags", "FLAG_", values)
        list_free("vars", "VAR_", values)

    print("\n%d problem(s) found" % report.problems)
    return 1 if report.problems else 0


if __name__ == "__main__":
    sys.exit(main())
