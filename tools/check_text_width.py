#!/usr/bin/env python3
"""Measures the line widths of all script texts as the built ROM shows them.

Every label in data/**/*.inc and data/*.s that starts with .string is looked
up in the ELF, its bytes are read from the .gba (so #if GERMAN and the other
branches are resolved as built) and each displayed line (split at \\n, \\l,
\\p) is measured like GetStringWidth() in src/text.c: FONT_NORMAL unless the
text switches fonts, glyph widths from src/fonts.c indexed by glyph id.

Lines with {PLAYER}, {RIVAL}, {STR_VAR_x} or icons are estimates (names 7,
buffers 10 characters of 6 px). Texts of retired maps are not in the ROM;
maps in LOCKED_MAPSECS (Sinjoh and Alola) are counted separately.

Usage (after make):
    python3 tools/check_text_width.py              # summary per area
    python3 tools/check_text_width.py --list       # every line over the limit
    python3 tools/check_text_width.py --limit 216

Exit status 1 if an exact line outside locked maps is wider than --limit.
"""

import argparse
import collections
import glob
import json
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ROM_BASE = 0x08000000

LOCKED_MAPSECS = {
    "MAPSEC_SINJOH_RUINS", "MAPSEC_NEW_SINJOH", "MAPSEC_MELEMELE_ISLAND",
    "MAPSEC_AKALA_ISLAND", "MAPSEC_AKALA_CAVE", "MAPSEC_AKALA_FOREST",
    "MAPSEC_ULAULA_ISLAND", "MAPSEC_ULAULA_CAVE", "MAPSEC_ULAULA_CAVE_2",
    "MAPSEC_PONI_ISLAND", "MAPSEC_PONI_CAVE", "MAPSEC_ALOLA_OCEAN",
}

# Bytes after EXT_CTRL_CODE_BEGIN and the code (include/constants/characters.h).
EXT_ARGS = {0x01: 1, 0x02: 1, 0x03: 1, 0x04: 3, 0x05: 1, 0x06: 1, 0x08: 1,
            0x0B: 2, 0x0C: 1, 0x0D: 1, 0x0E: 1, 0x10: 2, 0x11: 1, 0x12: 1,
            0x13: 1, 0x14: 1, 0x19: 1, 0x1A: 1, 0x1B: 1, 0x1C: 3}
PLACEHOLDERS = {0x01: ("PLAYER", 42), 0x02: ("STR_VAR_1", 60),
                0x03: ("STR_VAR_2", 60), 0x04: ("STR_VAR_3", 60),
                0x06: ("RIVAL", 42)}
ICON_WIDTH = 8


def read(path):
    with open(os.path.join(REPO, path), encoding="utf-8", errors="replace") as fh:
        return fh.read()


def load_fonts():
    """Returns {font id: glyph width table} for the fonts with a Latin table."""
    fonts_c = read("src/fonts.c")
    enum = re.search(r"enum\s*\{\s*(FONT_SMALL,.*?)\}", read("include/text.h"), re.S).group(1)
    names = re.findall(r"^\s*(FONT_\w+)", enum, re.M)
    tables = {}
    for font_id, name in enumerate(names):
        camel = "".join(p.capitalize() for p in re.sub(r"_COPY_\d", "", name)[5:].split("_"))
        m = re.search(r"gFont%sLatinGlyphWidths\[\] = \{(.*?)\};" % camel, fonts_c, re.S)
        if m:
            tables[font_id] = [int(x) for x in re.findall(r"\d+", m.group(1))]
    return tables, names.index("FONT_NORMAL")


def load_glyph_names():
    """Glyph id -> character, for printing; the first charmap entry wins."""
    names = {}
    for line in read("charmap.txt").splitlines():
        m = re.match(r"^'(.+?)'\s*=\s*([0-9A-Fa-f]{2})\s*(?:@.*)?$", line.strip())
        if m:
            names.setdefault(int(m.group(2), 16), m.group(1).replace("\\'", "'"))
    return names


def measure(data, fonts, normal):
    """Splits a ROM string into lines: [(width, estimated, start, end)]."""
    lines = []
    width, estimated, table, min_width = 0, False, fonts[normal], 0
    i = start = 0
    while i < len(data):
        b = data[i]
        if b == 0xFF:
            break
        if b in (0xFA, 0xFB, 0xFE):
            lines.append((width, estimated, start, i))
            width, estimated = 0, False
            i += 1
            start = i
            continue
        if b in (0xFD, 0xF7):
            ph = PLACEHOLDERS.get(data[i + 1]) if b == 0xFD else None
            width += ph[1] if ph else 0
            estimated = True
            i += 2
            continue
        if b in (0xF8, 0xF9):
            width += ICON_WIDTH
            estimated = True
            i += 2
            continue
        if b == 0xFC:
            code, arg = data[i + 1], data[i + 2] if i + 2 < len(data) else 0
            if code == 0x06:
                table = fonts.get(arg, table)
            elif code == 0x07:
                table = fonts[normal]
            elif code == 0x11:
                width += arg
            elif code == 0x12:
                width = arg
            elif code == 0x13:
                width = max(width, arg)
            elif code == 0x14:
                min_width = arg
            i += 2 + EXT_ARGS.get(code, 0)
            continue
        width += max(table[b], min_width)
        i += 1
    lines.append((width, estimated, start, i))
    return lines


def decode(data, glyphs):
    """Readable text of one line; control codes and placeholders as {..}."""
    out = []
    i = 0
    while i < len(data):
        b = data[i]
        if b == 0xFC and i + 1 < len(data):
            out.append("{FC %02X}" % data[i + 1])
            i += 2 + EXT_ARGS.get(data[i + 1], 0)
        elif b in (0xF7, 0xF8, 0xF9, 0xFD) and i + 1 < len(data):
            ph = PLACEHOLDERS.get(data[i + 1]) if b == 0xFD else None
            out.append("{%s}" % (ph[0] if ph else "%02X %02X" % (b, data[i + 1])))
            i += 2
        else:
            out.append(glyphs.get(b, "{%02X}" % b))
            i += 1
    return "".join(out)


def text_labels():
    """Label -> (file, line) for every label whose first statement is .string."""
    label_re = re.compile(r"^(\w+)::?\s*(?:@.*)?$")
    labels = {}
    files = glob.glob(os.path.join(REPO, "data/**/*.inc"), recursive=True)
    files += glob.glob(os.path.join(REPO, "data/*.s"))
    for path in sorted(files):
        rel = os.path.relpath(path, REPO)
        lines = read(rel).split("\n")
        for n, raw in enumerate(lines):
            m = label_re.match(raw)
            if not m:
                continue
            for nxt in lines[n + 1:n + 40]:
                s = nxt.strip()
                if not s or s[0] in "@#" or s.startswith("//"):
                    continue
                if s.startswith(".string"):
                    labels.setdefault(m.group(1), (rel, n + 1))
                break
    return labels


def map_areas():
    """Map directory -> area name."""
    areas = {}
    for path in glob.glob(os.path.join(REPO, "data/maps/*/map.json")):
        with open(path, encoding="utf-8") as fh:
            data = json.load(fh)
        d = os.path.basename(os.path.dirname(path))
        if data.get("region_map_section") in LOCKED_MAPSECS:
            areas[d] = "locked"
        elif d.endswith("_Frlg"):
            areas[d] = "kanto"
        elif d.endswith("_hns"):
            areas[d] = "johto"
        else:
            areas[d] = "hoenn"
    return areas


def area_of(rel, areas):
    m = re.match(r"data/maps/([^/]+)/", rel)
    if m:
        return "maps/" + areas.get(m.group(1), "?")
    return os.path.dirname(rel) or rel


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--elf", default="Pokemon_Origin_Jade.elf")
    ap.add_argument("--limit", type=int, default=208, help="line width in px (208)")
    ap.add_argument("--list", action="store_true", help="print every line over the limit")
    args = ap.parse_args()

    elf = os.path.join(REPO, args.elf)
    gba = os.path.splitext(elf)[0] + ".gba"
    if not (os.path.exists(elf) and os.path.exists(gba)):
        sys.exit(f"{args.elf} or its .gba not found: run make first")
    with open(gba, "rb") as fh:
        rom = fh.read()
    nm = subprocess.run(["arm-none-eabi-nm", "--defined-only", elf],
                        capture_output=True, text=True, check=True).stdout
    addresses = {}
    for line in nm.splitlines():
        parts = line.split()
        if len(parts) == 3:
            addresses.setdefault(parts[2], int(parts[0], 16))

    fonts, normal = load_fonts()
    glyphs = load_glyph_names()
    areas = map_areas()
    stats = collections.defaultdict(collections.Counter)
    over = []
    for label, (rel, line_no) in sorted(text_labels().items()):
        addr = addresses.get(label)
        if addr is None or not 0 <= addr - ROM_BASE < len(rom):
            continue
        start = addr - ROM_BASE
        data = rom[start:rom.index(b"\xff", start) + 1]
        area = area_of(rel, areas)
        stats[area]["labels"] += 1
        for width, estimated, first, last in measure(data, fonts, normal):
            stats[area]["lines"] += 1
            if width > args.limit:
                stats[area]["estimated over" if estimated else "over"] += 1
                if width > 216 and not estimated:
                    stats[area]["over 216"] += 1
                over.append((rel, line_no, label, width, estimated,
                             decode(data[first:last], glyphs)))

    print(f"Lines wider than {args.limit} px (FONT_NORMAL, as built):")
    print(f"{'area':<22}{'labels':>8}{'lines':>8}{'over':>7}{'>216':>7}{'est.':>7}")
    for area in sorted(stats):
        s = stats[area]
        print(f"{area:<22}{s['labels']:>8}{s['lines']:>8}{s['over']:>7}"
              f"{s['over 216']:>7}{s['estimated over']:>7}")
    if args.list:
        for rel, line_no, label, width, estimated, text in sorted(over):
            mark = "~" if estimated else " "
            print(f"{mark}{width:4d} px  {rel}:{line_no}  {label}\n         {text}")
    bad = sum(s["over"] for a, s in stats.items() if a != "maps/locked")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
