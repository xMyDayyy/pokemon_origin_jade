#!/usr/bin/env python3
"""Region rule check for the jade build.

No wild table of an active map offers a species of a later region: Kanto
maps only Kanto species, Johto maps Kanto and Johto species. Hoenn maps and
maps outside the three regions are not limited. Also checks the overworld
Pokemon that show what a map offers: objects without a script that
use a species sprite (OBJ_EVENT_GFX_MON_BASE+SPECIES_*), and the gifts and
static battles in the map scripts of active maps (givemon, giveegg,
setwildbattle, setwildbattleshiny, seteventmon). Scripts outside the maps
(data/scripts) and trades are not checked.

Pokedex order: the National Pokedex list runs up to the highest seen entry
of enum ObtainableDexOrder (include/constants/pokedex.h, the jade build
uses it: SEPARATE_OBTAINABLE_DEX), in blocks marked // Kanto, // Johto and
// Hoenn. Every species of a region lies in its region's block or an
earlier one, so seeing it before a later region is unlocked does not let
the list jump into a later block.

Species regions follow GetSpeciesRegion (src/region_rule_oj.c): national
numbers 1-151 Kanto, 152-251 Johto, 252-386 Hoenn, higher numbers from its
table sLaterSpeciesRegions (anything else: Hoenn). National numbers come
from the species info (.natDexNum) and include/constants/pokedex.h.

Tables: src/data/wild_encounters.json, day and night, all encounter types,
without the LeafGreen tables (the jade build does not compile them). Active
maps are those with game_version "hns"; map regions as in
tools/oj_world.py (MapSections.region).

Usage:
    python3 -I tools/check_regions.py             # findings; exit status 1 if any
    python3 -I tools/check_regions.py --list      # also the species of each region's maps
    python3 -I tools/check_regions.py --dex-gaps  # also the blocks of the Pokedex order

Builds nothing and changes nothing. Needs no compiler.
"""

import argparse
import glob
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import oj_world  # noqa: E402

REGIONS = ["Kanto", "Johto", "Hoenn"]

# Map region -> species regions allowed in its wild tables.
ALLOWED = {
    "Kanto": {"Kanto"},
    "Johto": {"Kanto", "Johto"},
}

# Known exceptions: map id or (map id, species) -> reason. They are listed but do not fail.
KNOWN = {
    ("MAP_RUINS_OF_ALPH_LAB_HNS", "SPECIES_LILEEP"): "belebt das Wurzelfossil, das es nur in Hoenn gibt",
    ("MAP_RUINS_OF_ALPH_LAB_HNS", "SPECIES_ANORITH"): "belebt das Klauenfossil, das es nur in Hoenn gibt",
    ("MAP_ROUTE4", "SPECIES_JIRACHI"): "erst nach der ersten Fahrt nach Hoenn",
    "MAP_SAFARI_ZONE_LOW_RIGHT_HNS": "öffnet erst nach Baobas Questreihe, nach der ersten Fahrt nach Hoenn",
    ("MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS", "SPECIES_BELDUM"): "Testskript ohne Aufruf",
    ("MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS", "SPECIES_CASTFORM"): "Testskript ohne Aufruf",
    ("MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS", "SPECIES_MEDICHAM"): "Testskript ohne Aufruf",
    ("MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS", "SPECIES_BAGON"): "Testskript ohne Aufruf",
}

MON_GFX = re.compile(r"OBJ_EVENT_GFX_MON_BASE\s*\+\s*(SPECIES_\w+)")
# Script commands that hand out a species or start a battle with it.
SCRIPT_MON = re.compile(r"^\s*(givemon|giveegg|setwildbattle|setwildbattleshiny|seteventmon)\b([^\n]*)", re.M)


def national_dex_numbers():
    """NATIONAL_DEX_* -> number, from enum NationalDexOrder (unconditional part)."""
    text = open(oj_world.repo_path("include", "constants", "pokedex.h"), encoding="utf-8").read()
    body = re.search(r"enum NationalDexOrder\s*\{(.*?)\n\};", text, re.S).group(1)
    numbers = {}
    value = 0
    for line in body.splitlines():
        line = re.sub(r"//.*", "", line).strip()
        if line.startswith("#"):
            break
        for name in re.findall(r"\b(NATIONAL_DEX_\w+)\b", line):
            numbers[name] = value
            value += 1
    return numbers


def species_national_numbers(dex):
    """SPECIES_* -> national number, from .natDexNum in the species info."""
    result = {}
    for path in sorted(glob.glob(oj_world.repo_path("src", "data", "pokemon", "species_info", "*.h"))):
        current = None
        for line in open(path, encoding="utf-8", errors="replace"):
            if line.startswith("#define"):
                current = None
            m = re.match(r"\s*\[(SPECIES_\w+)\]\s*=", line)
            if m:
                current = m.group(1)
                continue
            m = re.search(r"\.natDexNum\s*=\s*(NATIONAL_DEX_\w+)", line)
            if m and current and current not in result and m.group(1) in dex:
                result[current] = dex[m.group(1)]
    return result


def later_species_regions(dex):
    """National number -> region of sLaterSpeciesRegions in src/region_rule_oj.c."""
    text = open(oj_world.repo_path("src", "region_rule_oj.c"), encoding="utf-8").read()
    body = re.search(r"sLaterSpeciesRegions\[\]\s*=\s*\{(.*?)\n\};", text, re.S)
    if not body:
        sys.exit("sLaterSpeciesRegions not found in src/region_rule_oj.c")
    table = {}
    for name, region in re.findall(r"\{\s*(NATIONAL_DEX_\w+)\s*,\s*REGION_(\w+)\s*\}", body.group(1)):
        if name not in dex:
            sys.exit("%s in sLaterSpeciesRegions is not a national dex constant" % name)
        table[dex[name]] = region.title()
    return table


class SpeciesRegions:
    def __init__(self):
        dex = national_dex_numbers()
        self.dex = dex
        self.national = species_national_numbers(dex)
        self.later = later_species_regions(dex)
        self.mew = dex["NATIONAL_DEX_MEW"]
        self.celebi = dex["NATIONAL_DEX_CELEBI"]
        self.deoxys = dex["NATIONAL_DEX_DEOXYS"]

    def national_number(self, species):
        num = self.national.get(species)
        if num is not None:
            return num
        # Forms built by macros (SPECIES_UNOWN_B): longest matching national dex name.
        parts = species.replace("SPECIES_", "", 1).split("_")
        while parts:
            num = self.dex.get("NATIONAL_DEX_" + "_".join(parts))
            if num is not None:
                return num
            parts.pop()
        return None

    def region(self, species):
        num = self.national_number(species)
        if num is None:
            return None
        return self.region_of_number(num)

    def region_of_number(self, num):
        if num <= self.mew:
            return "Kanto"
        if num <= self.celebi:
            return "Johto"
        if num <= self.deoxys:
            return "Hoenn"
        return self.later.get(num, "Hoenn")


def load_maps():
    """Map id -> oj_world.Map; the active map wins when two share an id."""
    maps = {}
    for d in sorted(os.listdir(oj_world.repo_path("data", "maps"))):
        p = oj_world.repo_path("data", "maps", d, "map.json")
        if os.path.exists(p):
            m = oj_world.Map(json.load(open(p, encoding="utf-8")), d)
            if m.id in maps and not m.active:
                continue
            maps[m.id] = m
    return maps


def wild_tables():
    """(label, map id, encounter type, species list) of the compiled wild tables."""
    data = json.load(open(oj_world.repo_path("src", "data", "wild_encounters.json"), encoding="utf-8"))
    for group in data["wild_encounter_groups"]:
        for enc in group.get("encounters", []):
            label = enc.get("base_label", "")
            if "LeafGreen" in label or "map" not in enc:
                continue
            for key, value in enc.items():
                if key.endswith("_mons") and isinstance(value, dict):
                    yield label, enc["map"], key, [mon["species"] for mon in value.get("mons", [])]


def script_mons(map_dir):
    """(command, species) of the gift and battle commands in a map's scripts."""
    result = set()
    for name in ("scripts.inc", "scripts.pory"):
        p = oj_world.repo_path("data", "maps", map_dir, name)
        if not os.path.exists(p):
            continue
        text = open(p, encoding="utf-8", errors="replace").read()
        for command, rest in SCRIPT_MON.findall(text):
            for species in re.findall(r"\bSPECIES_\w+", rest):
                if species != "SPECIES_NONE":
                    result.add((command, species))
    return sorted(result)


def dex_order(regions):
    """Blocks and entries of enum ObtainableDexOrder.

    Returns ({block: (first, last)}, [(position, name, region)]); region is
    None for entries without a national number of their own in the
    unconditional part of enum NationalDexOrder (the regional forms, off in
    the jade build; their numbers would lie above 386, outside any limit).
    """
    text = open(oj_world.repo_path("include", "constants", "pokedex.h"), encoding="utf-8").read()
    body = re.search(r"enum ObtainableDexOrder\s*\{(.*?)\n\};", text, re.S)
    if not body:
        sys.exit("enum ObtainableDexOrder not found in include/constants/pokedex.h")
    blocks = {}
    entries = []
    block = None
    position = 0
    for line in body.group(1).splitlines():
        marker = re.match(r"\s*//\s*(\w.*?)\s*$", line)
        if marker:
            block = marker.group(1)
            blocks[block] = [position + 1, position]
            continue
        for name in re.findall(r"\bOBTAINABLE_DEX_(\w+)\b", re.sub(r"//.*", "", line)):
            if name == "NONE":
                continue
            position += 1
            if block in blocks:
                blocks[block][1] = position
            num = regions.dex.get("NATIONAL_DEX_" + name)
            entries.append((position, name, regions.region_of_number(num) if num else None))
    for r in REGIONS:
        if r not in blocks:
            sys.exit("enum ObtainableDexOrder has no // %s block" % r)
    return {b: tuple(v) for b, v in blocks.items()}, entries


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--list", action="store_true", help="also list the species of each region's maps")
    parser.add_argument("--dex-gaps", action="store_true", help="also print the blocks of the Pokedex order")
    args = parser.parse_args()

    regions = SpeciesRegions()
    mapsecs = oj_world.MapSections()
    maps = load_maps()

    findings = []
    known = []
    unknown_species = set()
    checked_tables = 0
    checked_commands = 0
    seen = {r: set() for r in REGIONS}

    def check(map_id, where, species):
        m = maps.get(map_id)
        if m is None or not m.active:
            return
        map_region = mapsecs.region(m.mapsec)
        sp_region = regions.region(species)
        if sp_region is None:
            unknown_species.add(species)
            return
        allowed = ALLOWED.get(map_region)
        if allowed is None or sp_region in allowed:
            if map_region in seen:
                seen[map_region].add(species)
            return
        line = "%s (%s, %s): %s ist eine %s-Art" % (map_id, map_region, where, species, sp_region)
        reason = KNOWN.get((map_id, species), KNOWN.get(map_id))
        (known if reason else findings).append((line, reason))

    for label, map_id, kind, species_list in wild_tables():
        m = maps.get(map_id)
        if m is None or not m.active:
            continue
        checked_tables += 1
        for species in sorted(set(species_list)):
            check(map_id, "%s %s" % (label, kind), species)

    for map_id, m in sorted(maps.items()):
        if not m.active:
            continue
        for i, obj in enumerate(m.objects):
            gfx = MON_GFX.search(str(obj.get("graphics_id", "")))
            if gfx and str(obj.get("script", "NULL")) in ("NULL", "0", ""):
                check(map_id, "Überwelt-Pokémon %d" % (i + 1), gfx.group(1))

    for map_dir in sorted(os.listdir(oj_world.repo_path("data", "maps"))):
        p = oj_world.repo_path("data", "maps", map_dir, "map.json")
        if not os.path.exists(p):
            continue
        map_id = json.load(open(p, encoding="utf-8"))["id"]
        m = maps.get(map_id)
        if m is None or not m.active or m.dir != map_dir:
            continue
        for command, species in script_mons(map_dir):
            checked_commands += 1
            check(map_id, "Skript: %s" % command, species)

    blocks, entries = dex_order(regions)
    for position, name, sp_region in entries:
        # Hoenn's block is the last one the list can jump into.
        if sp_region is None or sp_region == REGIONS[-1]:
            continue
        first, last = blocks[sp_region]
        if position > last:
            findings.append(("Pokédex-Reihenfolge: %s auf Platz %d ist eine %s-Art hinter dem %s-Block (%d-%d)"
                             % (name, position, sp_region, sp_region, first, last), None))

    print("Regionenregel: %d Wildtabellen und %d Skriptbefehle aktiver Karten, %d Einträge der "
          "Pokédex-Reihenfolge geprüft" % (checked_tables, checked_commands, len(entries)))
    if args.dex_gaps:
        for r in REGIONS[:-1]:
            first, last = blocks[r]
            own = [(pos, name) for pos, name, sp_region in entries if sp_region == r]
            earlier = [pos for pos, name in own if pos < first]
            print("  %s-Block %d-%d: %d %s-Arten, die letzte auf Platz %d (%s), %d davon in früheren Blöcken"
                  % (r, first, last, len(own), r, max(own)[0], max(own)[1], len(earlier)))
        first, last = blocks[REGIONS[-1]]
        earlier = [pos for pos, name, sp_region in entries if sp_region == REGIONS[-1] and pos < first]
        print("  %s-Block %d-%d: der letzte, ohne Grenze; %d Hoenn-Arten in früheren Blöcken, danach %d Einträge"
              % (REGIONS[-1], first, last, len(earlier), len(entries) - last))
    if args.list:
        for r in REGIONS:
            print("  %s-Karten: %d Arten" % (r, len(seen[r])))
            for species in sorted(seen[r], key=lambda s: (REGIONS.index(regions.region(s)), s)):
                print("    %-30s %s" % (species, regions.region(species)))
    for line, reason in sorted(set(known)):
        print("  bekannt: %s - %s" % (line, reason))
    for species in sorted(unknown_species):
        findings.append(("%s: keine Nationalnummer gefunden" % species, None))
    for line, _ in sorted(set(findings)):
        print("  FEHLER: " + line)
    print("%d Problem(e)" % len(set(findings)))
    return 1 if findings else 0


if __name__ == "__main__":
    sys.exit(main())
