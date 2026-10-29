#!/usr/bin/env python3
"""
check_pokenav_text.py -- measures the line width of all PokeNav call texts.

A call text line may be at most 192 px wide, 16 px less than in a msgbox.

Glyph widths come from src/fonts.c, the character mapping from charmap.txt.

Usage from the repository root:
    python3 check_pokenav_text.py
    python3 check_pokenav_text.py --limit 192
"""

import argparse
import glob
import os
import re
import sys

WINDOW_PX = 224          # 28 tiles
TEXT_START_X = 32        # room for the handset icon
DEFAULT_LIMIT = WINDOW_PX - TEXT_START_X


def load_glyph_widths(path="src/fonts.c"):
    """Glyph widths of the normal font, indexed by glyph id."""
    with open(path, encoding="utf-8", errors="replace") as fh:
        text = fh.read()
    start = text.index("gFontNormalLatinGlyphWidths[] = {")
    block = text[start:text.index("};", start)]
    return [int(x) for x in re.findall(r"\b(\d+)\b", block)[1:]]


def load_charmap(path="charmap.txt"):
    """Character -> glyph id. Only entries of the form 'x' = NN."""
    mapping = {}
    pattern = re.compile(r"^'(.+?)'\s*=\s*([0-9A-Fa-f]{2})\s*$")
    with open(path, encoding="utf-8", errors="replace") as fh:
        for line in fh:
            m = pattern.match(line.strip())
            if m:
                mapping[m.group(1)] = int(m.group(2), 16)
    return mapping


PLACEHOLDERS = {
    # Assumed length in characters of each placeholder.
    "PLAYER": 7, "RIVAL": 7, "STR_VAR_1": 10, "STR_VAR_2": 10,
    "STR_VAR_3": 10, "KUN": 0, "POKEMON": 7, "POKEBLOCK": 9,
}


def line_width(line, widths, charmap):
    """Width in pixels. Control characters are skipped."""
    total = 0
    i = 0
    while i < len(line):
        if line[i] == "{":
            end = line.find("}", i)
            if end == -1:
                break
            name = line[i + 1:end]
            base = name.split("_")[0]
            for key, chars in PLACEHOLDERS.items():
                if name.startswith(key):
                    total += chars * 6
                    break
            i = end + 1
            continue
        ch = line[i]
        gid = charmap.get(ch)
        if gid is None:
            total += 6          # unknown character: average width
        elif gid < len(widths):
            total += widths[gid]
        i += 1
    return total


def collect_call_texts():
    """Returns {label: [(file, text line)]} for all pokenavcall targets."""
    files = (glob.glob("data/maps/*/scripts.inc")
             + glob.glob("data/scripts/*.inc")
             + ["data/event_scripts.s"])
    targets = {}
    for path in files:
        if not os.path.exists(path):
            continue
        with open(path, encoding="utf-8", errors="replace") as fh:
            text = fh.read()
        for label in re.findall(r"^\s*pokenavcall\s+(\w+)", text, re.M):
            targets.setdefault(label, [])

    for path in files:
        if not os.path.exists(path):
            continue
        with open(path, encoding="utf-8", errors="replace") as fh:
            lines = fh.read().split("\n")
        current = None
        for raw in lines:
            m = re.match(r"^(\w+)::?\s*$", raw)
            if m:
                current = m.group(1) if m.group(1) in targets else None
                continue
            if current is None:
                continue
            if raw.strip().startswith("#") or not raw.strip():
                if raw.strip().startswith("#endif"):
                    current = None
                continue
            m = re.match(r'\s*\.string\s+"(.*)"\s*$', raw)
            if m:
                targets[current].append((path, m.group(1)))
            elif raw.strip() and not raw.strip().startswith("@"):
                current = None
    return targets


def main():
    """Prints every call text line that is wider than the limit."""
    ap = argparse.ArgumentParser()
    ap.add_argument("--limit", type=int, default=DEFAULT_LIMIT,
                    help="Zeilenbreite in Pixeln (Default: %d)" % DEFAULT_LIMIT)
    args = ap.parse_args()

    if not os.path.exists("src/fonts.c"):
        sys.exit("Bitte im Repo-Wurzelverzeichnis ausfuehren.")

    widths = load_glyph_widths()
    charmap = load_charmap()
    targets = collect_call_texts()

    print("Anrufbox: %d px breit, Text ab x=%d -> %d px nutzbar"
          % (WINDOW_PX, TEXT_START_X, args.limit))
    print("Gefundene pokenavcall-Texte: %d\n" % len(targets))

    problems = 0
    for label in sorted(targets):
        for path, raw in targets[label]:
            for chunk in re.split(r"\\n|\\l|\\p", raw):
                chunk = chunk.replace("$", "")
                if not chunk:
                    continue
                px = line_width(chunk, widths, charmap)
                if px > args.limit:
                    problems += 1
                    print("%3d px  %-44s %s"
                          % (px, label[:44], os.path.basename(os.path.dirname(path))))
                    print("        %s" % chunk)

    print("\nZeilen ueber dem Limit: %d" % problems)
    return 1 if problems else 0


if __name__ == "__main__":
    sys.exit(main())
