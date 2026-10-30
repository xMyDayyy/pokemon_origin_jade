#!/usr/bin/env python3
"""Prints the save and memory budget of the jade build.

Save: SaveBlock1/2/3 and PokemonStorage against the flash space src/save.c
gives them (its STATIC_ASSERTs), from a probe compiled with the jade flags.
Memory: EWRAM, IWRAM and ROM use of the built ELF against the regions of
ld_script_modern.ld; gHeap is part of EWRAM.

Usage (after make; needs arm-none-eabi-gcc and arm-none-eabi-readelf):
    python3 tools/check_budget.py
    python3 tools/check_budget.py --elf Pokemon_Origin_Jade-release.elf
    python3 tools/check_budget.py --min-free 64   # exit 1 below 64 free bytes

Exit status 1 if a save block or memory region has less than --min-free
bytes left (default 0).
"""

import argparse
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PREFIX = "arm-none-eabi-"
# Flags of the jade build (Makefile CPPFLAGS and CFLAGS) that change struct sizes.
CFLAGS = ["-iquote", "include", "-Wno-trigraphs", "-DMODERN=1", "-DTESTING=0",
          "-DPOKEMON_HNS", "-std=gnu17", "-mthumb", "-mthumb-interwork", "-O2",
          "-mabi=apcs-gnu", "-mtune=arm7tdmi", "-march=armv4t"]

# name, size expression, limit expression (as in src/save.c)
SAVE_BLOCKS = [
    ("SaveBlock1", "sizeof(struct SaveBlock1)",
     "SECTOR_DATA_SIZE * (SECTOR_ID_SAVEBLOCK1_END - SECTOR_ID_SAVEBLOCK1_START + 1)"),
    ("SaveBlock2", "sizeof(struct SaveBlock2)", "SECTOR_DATA_SIZE"),
    ("SaveBlock3", "sizeof(struct SaveBlock3)",
     "SAVE_BLOCK_3_CHUNK_SIZE * NUM_SECTORS_PER_SLOT"),
    ("PokemonStorage", "sizeof(struct PokemonStorage)",
     "SECTOR_DATA_SIZE * (SECTOR_ID_PKMN_STORAGE_END - SECTOR_ID_PKMN_STORAGE_START + 1)"),
]

SIZE_UNITS = {"": 1, "K": 1024, "M": 1024 * 1024}


def probe_save_sizes():
    """Returns [(name, used, limit)] for SAVE_BLOCKS."""
    exprs = []
    for _, size, limit in SAVE_BLOCKS:
        exprs += [size, limit]
    src = ('#include "global.h"\n#include "save.h"\n'
           '#include "pokemon_storage_system.h"\n'
           "const unsigned int gBudgetProbe[] = {\n    "
           + ",\n    ".join(exprs) + "\n};\n")
    out = subprocess.run([PREFIX + "gcc", *CFLAGS, "-S", "-o", "-", "-x", "c", "-"],
                         input=src, capture_output=True, text=True, cwd=REPO)
    if out.returncode != 0:
        sys.exit("probe failed to compile (run make first):\n" + out.stderr)
    asm = out.stdout[out.stdout.index("gBudgetProbe:"):]
    values = [int(v, 0) for v in re.findall(r"\.word\s+(\d+)", asm)][:len(exprs)]
    return [(name, values[2 * i], values[2 * i + 1])
            for i, (name, _, _) in enumerate(SAVE_BLOCKS)]


def memory_regions(path):
    """Returns {name: (origin, length, writable)} from the MEMORY block of a linker script."""
    with open(path, encoding="utf-8") as fh:
        text = fh.read()
    block = re.search(r"MEMORY\s*\{(.*?)\}", text, re.S).group(1)
    regions = {}
    for m in re.finditer(r"(\w+)\s*\(([^)]*)\)\s*:\s*ORIGIN\s*=\s*(\w+)\s*,\s*"
                         r"LENGTH\s*=\s*(\d+)([KM]?)", block):
        regions[m.group(1)] = (int(m.group(3), 0), int(m.group(4)) * SIZE_UNITS[m.group(5)],
                               "w" in m.group(2))
    return regions


def elf_usage(elf, regions):
    """Bytes used per region: allocated sections by address, file data by load address."""
    used = {name: 0 for name in regions}

    def region_of(addr):
        for name, (origin, length, _) in regions.items():
            if origin <= addr < origin + length:
                return name
        return None

    out = subprocess.run([PREFIX + "readelf", "-SlW", elf],
                         capture_output=True, text=True, check=True).stdout
    sections = re.findall(r"^\s*\[\s*\d+\]\s+(\S+)\s+(\S+)\s+([0-9a-f]{8})\s+([0-9a-f]+)\s+"
                          r"([0-9a-f]+)\s+\S+\s+(\S*)", out, re.M)
    segments = re.findall(r"^\s*LOAD\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+"
                          r"0x([0-9a-f]+)\s+0x([0-9a-f]+)", out, re.M)
    for name, kind, addr, _, size, flags in sections:
        if "A" not in flags or not int(size, 16):
            continue
        region = region_of(int(addr, 16))
        # NOBITS takes no space in read-only memory: it only marks a load address.
        if region and (kind != "NOBITS" or regions[region][2]):
            used[region] += int(size, 16)
    # Initialised RAM data is also stored in ROM at its load address.
    for _, vaddr, paddr, filesz, _ in segments:
        if int(vaddr, 16) != int(paddr, 16) and region_of(int(paddr, 16)):
            used[region_of(int(paddr, 16))] += int(filesz, 16)
    return used


def symbol_size(elf, symbol):
    out = subprocess.run([PREFIX + "nm", "-S", elf], capture_output=True, text=True,
                         check=True).stdout
    m = re.search(r"^[0-9a-f]+ ([0-9a-f]+) \w " + re.escape(symbol) + "$", out, re.M)
    return int(m.group(1), 16) if m else None


def row(name, used, limit, extra=""):
    free = limit - used
    print(f"{name:<15} {used:>10} {limit:>10} {free:>9} {100.0 * used / limit:7.2f} %{extra}")
    return free


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--elf", default="Pokemon_Origin_Jade.elf")
    ap.add_argument("--ld-script", default="ld_script_modern.ld")
    ap.add_argument("--min-free", type=int, default=0,
                    help="exit 1 if anything has fewer free bytes")
    args = ap.parse_args()
    elf = os.path.join(REPO, args.elf)
    if not os.path.exists(elf):
        sys.exit(f"{args.elf} not found: run make first")

    low = []
    print(f"{'':<15} {'used':>10} {'limit':>10} {'free':>9} {'use':>9}")
    for name, used, limit in probe_save_sizes():
        if row(name, used, limit) < args.min_free:
            low.append(name)
    print()
    regions = memory_regions(os.path.join(REPO, args.ld_script))
    usage = elf_usage(elf, regions)
    heap = symbol_size(elf, "gHeap")
    for name, (_, length, _) in regions.items():
        extra = f"  (gHeap {heap})" if name == "EWRAM" and heap else ""
        if row(name, usage[name], length, extra) < args.min_free:
            low.append(name)
    if low:
        print(f"\nLess than {args.min_free} bytes free: {', '.join(low)}")
    return 1 if low else 0


if __name__ == "__main__":
    sys.exit(main())
