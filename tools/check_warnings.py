#!/usr/bin/env python3
"""Compares the compiler warnings of a build log with the known baseline.

Counts the warnings per file and kind ([-W...]) in the log of a full build
and compares them with tools/warnings_baseline.txt. A file/kind pair above
its baseline count, or not in the baseline at all, is a new warning.

Usage:
    make -O -j4 2>&1 | tee build.log            # full build: make clean first
    python3 tools/check_warnings.py build.log
    python3 tools/check_warnings.py build.log --update   # rewrite the baseline

Exit status 1 if new warnings were found. Fewer warnings than the baseline
are only reported; lower the baseline with --update.
"""

import argparse
import collections
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASELINE = os.path.join(REPO, "tools", "warnings_baseline.txt")

# file:line[:col]: warning: text [-Wkind]
GCC_RE = re.compile(r"^(\S+?):\d+(?::\d+)?: warning: (.*?)(?: \[(-W[^\]]+)\])?\s*$")
# Assembler and linker: file:line: Warning: text / ld: warning: text
OTHER_RE = re.compile(r"^(\S+?)(?::\d+)?: [Ww]arning: (.*)$")


def count_warnings(path):
    """Returns ({(file, kind): count}, {(file, kind): [lines]}) of a build log."""
    counts = collections.Counter()
    lines = collections.defaultdict(list)
    with open(path, encoding="utf-8", errors="replace") as fh:
        for raw in fh:
            line = raw.rstrip("\n")
            if line.startswith("libpng warning"):
                continue
            m = GCC_RE.match(line)
            if m:
                key = (m.group(1), m.group(3) or "-W?")
            else:
                m = OTHER_RE.match(line)
                if not m:
                    continue
                key = (m.group(1), "other")
            counts[key] += 1
            lines[key].append(line)
    return counts, lines


def load_baseline(path):
    """Reads 'count file kind' lines; '#' starts a comment."""
    base = {}
    with open(path, encoding="utf-8") as fh:
        for raw in fh:
            line = raw.split("#", 1)[0].strip()
            if not line:
                continue
            count, name, kind = line.split()
            base[(name, kind)] = int(count)
    return base


def write_baseline(path, counts):
    with open(path, "w", encoding="utf-8") as fh:
        fh.write("# Known compiler warnings of a full jade build: count file kind.\n")
        fh.write("# Checked by tools/check_warnings.py; update with --update.\n")
        for (name, kind), count in sorted(counts.items()):
            fh.write(f"{count} {name} {kind}\n")


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("log", help="log of a full build (stdout and stderr)")
    ap.add_argument("--baseline", default=BASELINE)
    ap.add_argument("--update", action="store_true",
                    help="write the warnings of the log as the new baseline")
    args = ap.parse_args()

    counts, lines = count_warnings(args.log)
    total = sum(counts.values())
    if args.update:
        write_baseline(args.baseline, counts)
        print(f"Baseline written: {total} warnings in {len(counts)} file/kind pairs.")
        return 0

    base = load_baseline(args.baseline)
    new = {k: c for k, c in counts.items() if c > base.get(k, 0)}
    gone = {k: c for k, c in base.items() if counts.get(k, 0) < c}

    print(f"Warnings: {total} (baseline {sum(base.values())})")
    for (name, kind), count in sorted(new.items()):
        print(f"NEW: {name} {kind}: {count} (baseline {base.get((name, kind), 0)})")
        for line in lines[(name, kind)]:
            print(f"    {line}")
    for (name, kind), count in sorted(gone.items()):
        print(f"fewer: {name} {kind}: {counts.get((name, kind), 0)} "
              f"(baseline {count}), lower it with --update")
    if total == 0:
        print("No warnings found: is this the log of a full build?")
    return 1 if new else 0


if __name__ == "__main__":
    sys.exit(main())
