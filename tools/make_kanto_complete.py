#!/usr/bin/env python3
"""Generates src/data/debug_kanto_complete.h: the state of a complete Kanto run.

The debug menu's "Johto Test" (src/debug.c) applies it to a new game: every
Kanto trainer beaten, every item, TM and HM found or received, every event
done, every species obtainable in Kanto caught and evolved as far as Kanto
allows, right after the first Kanto Hall of Fame.

Sources (all in the repository):
  - the active Kanto maps: FRLG maps (*_Frlg) whose map.json and layout in
    layouts.json have game_version "hns", minus EXCLUDED_MAPS;
  - every script label these maps reach (data/event_scripts.s and its
    includes, #if and .if resolved for the jade build), minus CUT_LABELS:
    flags, vars, trainers, items, gifts, trades, static battles, legendaries;
  - item balls and hidden items of these maps;
  - new_game.inc's new game items and src/new_game.c's start money;
  - wild_encounters.json: the FireRed and _Night tables of these maps;
  - trainers_frlg.party and gTrainerClasses for the prize money;
  - gSpeciesInfo of the preprocessed src/pokemon.c for the evolutions.
Values the scripts leave open come from the configuration below.

Usage (needs arm-none-eabi-cpp and a host C compiler, cc or $CC):
  python3 tools/make_kanto_complete.py            # writes the header
  python3 tools/make_kanto_complete.py --check    # exit 1 if the header is stale
  python3 tools/make_kanto_complete.py --overlap  # flags/vars Johto or Hoenn share
                                                  # with the run, exit 1 on new ones
Rerun it after changes to Kanto maps, scripts, wild tables, trainers or items.
"""

import argparse
import collections
import difflib
import glob
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HEADER = "src/data/debug_kanto_complete.h"
DEFINES = ["-DPOKEMON_HNS", "-DMODERN=1", "-DTESTING=0"]
ARM_CPP = ["arm-none-eabi-cpp", "-iquote", "include", "-Wno-trigraphs", "-std=gnu17"] + DEFINES


# ---------------------------------------------------------------------------
# Configuration

# Party right after the Kanto league. Starter index: VAR_STARTER_MON
# (0 Bulbasaur, 1 Squirtle, 2 Charmander).
KANTO_COMPLETE_STARTER = 2
KANTO_COMPLETE_PARTY_STARTER_FINAL = ["SPECIES_VENUSAUR", "SPECIES_BLASTOISE", "SPECIES_CHARIZARD"]
KANTO_COMPLETE_PARTY_STARTER_LEVEL = 45
KANTO_COMPLETE_PARTY = [
    ("SPECIES_PIDGEOT", 45),
    ("SPECIES_RAICHU", 45),
    ("SPECIES_NIDOKING", 45),
    ("SPECIES_GYARADOS", 44),
    ("SPECIES_ALAKAZAM", 45),
]

# Active FRLG maps a run up to the first Hall of Fame never enters: post-title
# content, link rooms, unused houses.
EXCLUDED_MAPS = {
    "CeruleanCave_1F_Frlg", "CeruleanCave_2F_Frlg", "CeruleanCave_B1F_Frlg",
    "BattleColosseum_2P_Frlg", "BattleColosseum_4P_Frlg", "RecordCorner_Frlg",
    "TradeCenter_Frlg", "UnionRoom_Frlg",
    "Route19_UnusedHouse_Frlg", "Route6_UnusedHouse_Frlg", "SaffronCity_Connection_Frlg",
}

# Script labels the walk does not enter: content after the Kanto title,
# trips to Johto, Hoenn and the Sevii Islands, rematches.
CUT_LABELS = {
    # Vermilion port and Cinnabar: ships after the title, Sevii trips.
    "VermilionPortFrlg_EventScript_Sailor_AfterKanto",
    "VermilionPortFrlg_EventScript_FirstTripFromOlivine",
    "VermilionPortFrlg_EventScript_ShowSSAqua",
    "Common_EventScript_SailToHoenn",
    "CinnabarIsland_EventScript_ReadyObjectsSailToOneIslandFromPokeCenter",
    "CinnabarIsland_EventScript_ReadyObjectsSailToOneIsland",
    "CinnabarIsland_EventScript_ReadyObjectsReturnFromSeviiIslands",
    "CinnabarIsland_EventScript_ExitPokeCenterForOneIsland",
    "CinnabarIsland_EventScript_ReturnFromSeviiIslands",
    "CinnabarIsland_EventScript_AgreeSailToOneIsland",
    "CinnabarIsland_EventScript_DeclineSailToOneIsland",
    "CinnabarIsland_EventScript_SailToOneIsland",
    "CinnabarIsland_EventScript_BillScene",
    "CinnabarIsland_PokemonCenter_1F_EventScript_Bill",
    "IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete",
    # Janina and Blue as gym leaders after the league change.
    "FuchsiaCity_Gym_EventScript_SetJanineLeader",
    "FuchsiaCity_Gym_EventScript_JanineLeader",
    "FuchsiaCity_Gym_EventScript_JanineRematch",
    "FuchsiaCity_Gym_EventScript_JanineGiveTM",
    "ViridianCity_Gym_EventScript_BlueLeader",
    "ViridianCity_Gym_EventScript_BlueRematch",
    # Elite Four rematches after the title.
    "PokemonLeague_AgathasRoom_EventScript_Rematch",
    "PokemonLeague_BrunosRoom_EventScript_Rematch",
    "PokemonLeague_LancesRoom_EventScript_Rematch",
    "PokemonLeague_LoreleisRoom_EventScript_Rematch",
    "PokemonLeague_ChampionsRoom_EventScript_Rematch",
    # Oak after the title: National Dex scene, GS Ball handover.
    "PalletTown_ProfessorOaksLab_EventScript_TryStartNationalDexScene",
    "PalletTown_ProfessorOaksLab_EventScript_GsBallReminder",
    "PalletTown_ProfessorOaksLab_EventScript_GiveGsBall",
    "PokedexRating_EventScript_DexComplete",
}
# Label prefixes cut the same way: link features, Johto gyms, Hoenn arrival,
# Sevii Islands.
CUT_PREFIXES = (
    "CableClub_", "EventScript_CableClub", "JohtoGym_EventScript_", "MysteryEventClub_",
    "EventScript_GaveProfile", "EventScript_GaveSpecialProfile", "Common_EventScript_Hoenn",
    "OneIsland_", "Seagallop", "EventScript_Seagallop",
)

# Flags Kanto scripts write that are not part of the saved state.
DROP_FLAGS = {
    "FLAG_SYS_USE_STRENGTH",            # cleared on every map load
    "FLAG_SAFE_FOLLOWER_MOVEMENT",      # follower runtime flag
    "FLAG_SYS_CTRL_OBJ_DELETE",         # set and cleared around static battles
    "FLAG_TALKED_TO_TEA_LADY_AFTER_HOF",  # dialogue after the title
    "FLAG_SHOWN_AURORA_TICKET",         # event tickets
    "FLAG_SHOWN_MYSTIC_TICKET",
    "FLAG_NURSE_UNION_ROOM_REMINDER",   # link feature
}

# Flags Kanto scripts set and clear: their value right after the first
# Hall of Fame (1 set, 0 clear).
MANUAL_FLAGS = {
    # Cleared by EventScript_ResetEliteFour.
    "FLAG_DEFEATED_LORELEI": 0, "FLAG_DEFEATED_BRUNO": 0, "FLAG_DEFEATED_AGATHA": 0,
    "FLAG_DEFEATED_LANCE": 0, "FLAG_DEFEATED_CHAMP": 0,
    "FLAG_DONT_TRANSITION_MUSIC": 0,
    # Legendaries caught, Bill back to human, fossils taken, keys and scope found.
    "FLAG_HIDE_ARTICUNO": 1, "FLAG_HIDE_ZAPDOS": 1, "FLAG_HIDE_MOLTRES_KANTO": 1,
    "FLAG_HIDE_MEW_KANTO": 1, "FLAG_HIDE_BILL_CLEFAIRY": 1, "FLAG_HIDE_DOME_FOSSIL": 1,
    "FLAG_HIDE_HELIX_FOSSIL": 1, "FLAG_HIDE_LIFT_KEY": 1, "FLAG_HIDE_SILPH_SCOPE": 1,
    # Oak waits in his lab with the GS Ball.
    "FLAG_HIDE_OAK_IN_HIS_LAB": 0,
    "FLAG_HIDE_PEWTER_CITY_GYM_GUIDE": 1, "FLAG_HIDE_PEWTER_MUSEUM_GUIDE": 0,
    # Hidden on the next Vermilion visit after talking to Oak's aide.
    "FLAG_HIDE_VERMILION_CITY_OAKS_AIDE": 1,
    "FLAG_IN_KANTO_SAFARI_ZONE": 0, "FLAG_POKEMON_MANSION_SWITCH_STATE": 0,
    "FLAG_SYS_ON_CYCLING_ROAD": 0, "FLAG_PENDING_DAYCARE_EGG": 0,
    # Mom's first call has rung (Common_EventScript_HnsMomCall, started from C).
    "FLAG_HNS_MOM_CALL_PENDING": 0,
    # Power Plant Electrode fought: removeobject sets the hide flags.
    "FLAG_HIDE_POWER_PLANT_ELECTRODE_1": 1, "FLAG_HIDE_POWER_PLANT_ELECTRODE_2": 1,
    # Shown by Script_UpdateTrainerFanClubGameClear (Kanto Hall of Fame).
    "FLAG_HIDE_SAFFRON_FAN_CLUB_BLACKBELT": 0, "FLAG_HIDE_SAFFRON_FAN_CLUB_ROCKER": 0,
    "FLAG_HIDE_SAFFRON_FAN_CLUB_WOMAN": 0, "FLAG_HIDE_SAFFRON_FAN_CLUB_BEAUTY": 0,
    # Seafoam Islands solved: both currents stopped.
    "FLAG_HIDE_SEAFOAM_1F_BOULDER_1": 1, "FLAG_HIDE_SEAFOAM_1F_BOULDER_2": 1,
    "FLAG_HIDE_SEAFOAM_B1F_BOULDER_1": 1, "FLAG_HIDE_SEAFOAM_B1F_BOULDER_2": 1,
    "FLAG_HIDE_SEAFOAM_B2F_BOULDER_1": 1, "FLAG_HIDE_SEAFOAM_B2F_BOULDER_2": 1,
    "FLAG_HIDE_SEAFOAM_B3F_BOULDER_1": 0, "FLAG_HIDE_SEAFOAM_B3F_BOULDER_2": 0,
    "FLAG_HIDE_SEAFOAM_B3F_BOULDER_3": 1, "FLAG_HIDE_SEAFOAM_B3F_BOULDER_4": 0,
    "FLAG_HIDE_SEAFOAM_B3F_BOULDER_5": 1, "FLAG_HIDE_SEAFOAM_B3F_BOULDER_6": 0,
    "FLAG_HIDE_SEAFOAM_B4F_BOULDER_1": 0, "FLAG_HIDE_SEAFOAM_B4F_BOULDER_2": 0,
    # Victory Road boulders as Route23_OnTransition resets them.
    "FLAG_HIDE_VICTORY_ROAD_2F_BOULDER": 1, "FLAG_HIDE_VICTORY_ROAD_3F_BOULDER": 0,
}

# Vars written with several values, by copyvar or only by C: their value right
# after the first Hall of Fame. Also overrides a single scripted value.
MANUAL_VARS = {
    "VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE": 0,
    "VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL": 3,
    "VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE": 0,
    "VAR_MAP_SCENE_PALLET_TOWN_OAK": 1,
    "VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB": 6,
    "VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE": 2,
    "VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY": 2,
    "VAR_MAP_SCENE_PEWTER_CITY": 2,
    "VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F": 0,
    "VAR_MAP_SCENE_POKEMON_CENTER_TEALA": 2,           # player went upstairs in a Pokemon Center
    "VAR_MAP_SCENE_POKEMON_LEAGUE": 0,                 # EventScript_ResetEliteFour
    "VAR_MAP_SCENE_ROUTE16": 0,
    "VAR_MAP_SCENE_ROUTE22": 4,
    "VAR_MAP_SCENE_ROUTE23": 8,                        # Earth Badge checked
    "VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB": 1,  # right after the title
    "VAR_MAP_SCENE_SEAFOAM_ISLANDS_B4F": 0,
    "VAR_MAP_SCENE_VERMILION_CITY": 3,
    "VAR_MAP_SCENE_VICTORY_ROAD_1F": 0,
    "VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1": 0,
    "VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2": 0,
    "VAR_MAP_SCENE_VICTORY_ROAD_3F": 0,
    "VAR_MAP_SCENE_VIRIDIAN_CITY_MART": 2,
    "VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN": 2,
    "VAR_TRAIN": 0,
    "VAR_LEGENDARY_FLEE_KANTO": 0,
    "VAR_MASSAGE_COOLDOWN_STEP_COUNTER": 500,
}

# Flags and vars src/debug.c sets itself (Hall of Fame, clock, Pokedex,
# starter); never emitted.
SET_BY_DEBUG_C = {
    "FLAG_SYS_GAME_CLEAR", "FLAG_SYS_RIBBON_GET", "FLAG_SYS_NATIONAL_DEX",
    "FLAG_SYS_CLOCK_SET", "VAR_NATIONAL_DEX", "VAR_STARTER_MON",
}

# Scratch vars, never part of the state.
SCRATCH_VAR_RE = re.compile(
    r"^VAR_(RESULT|0x[0-9A-Fa-f]+|TEMP_\w+|ITEM_ID|SPECIAL_\w+|FRONTIER_\w+|TEXT_COLOR"
    r"|LAST_TALKED|FACING|OBJ_GFX_ID_\w+|ELEVATOR_FLOOR)$")

# Random Rock Smash finds, not counted.
SKIP_GIFT_ITEMS = {"ITEM_RED_SHARD", "ITEM_BLUE_SHARD", "ITEM_GREEN_SHARD", "ITEM_YELLOW_SHARD",
                   "ITEM_HEART_SCALE"}
# Items handed out through a var the walk does not follow.
EXTRA_ITEMS = {
    "ITEM_TM16": 1, "ITEM_TM20": 1, "ITEM_TM33": 1,   # Celadon roof, thirsty girl (VAR_0x8009)
}

# Static battles that cannot end in a catch.
UNCATCHABLE_STATIC = {"SPECIES_MAROWAK"}   # Pokemon Tower ghost

# Box levels: species neither wild nor bred nor evolved get these, else
# DEFAULT_BOX_LEVEL. Wild species get their highest wild level, bred ones 1,
# evolved ones their evolution level (or the pre-evolution's level + 5).
GIFT_LEVELS = {
    "SPECIES_BULBASAUR": 5, "SPECIES_CHARMANDER": 5, "SPECIES_SQUIRTLE": 5,
    "SPECIES_EEVEE": 25, "SPECIES_LAPRAS": 25, "SPECIES_MAGIKARP": 5,
    "SPECIES_OMANYTE": 5, "SPECIES_KABUTO": 5, "SPECIES_AERODACTYL": 5,
    "SPECIES_HITMONLEE": 25, "SPECIES_HITMONCHAN": 25,
    "SPECIES_ARTICUNO": 40, "SPECIES_ZAPDOS": 40, "SPECIES_MOLTRES": 40, "SPECIES_MEW": 40,
    "SPECIES_SNORLAX": 24,
}
DEFAULT_BOX_LEVEL = 20
MAX_BOX_LEVEL = 50

# Trainer flags the run never sets: rematch teams after the title.
TRAINER_SKIP_RE = re.compile(r"^TRAINER_(ELITE_FOUR_\w+_2|CHAMPION_REMATCH_\w+)$")
# Rival battles, one set per player starter.
RIVAL_RE = re.compile(r"^TRAINER_(RIVAL_\w+|CHAMPION_FIRST)_(BULBASAUR|CHARMANDER|SQUIRTLE)$")
STARTER_NAMES = ["Bulbasaur", "Squirtle", "Charmander"]   # by VAR_STARTER_MON

# State the run sets outside the generated lists (debug C, the Hall of Fame
# script's specials). Only for --overlap.
RUNTIME_STATE = [
    "FLAG_SYS_GAME_CLEAR", "FLAG_SYS_RIBBON_GET", "FLAG_SYS_NATIONAL_DEX", "FLAG_SYS_CLOCK_SET",
    "VAR_NATIONAL_DEX", "VAR_STARTER_MON",
    "VAR_SAFFRON_FANCLUB_FAN_COUNTER", "VAR_SAFFRON_FANCLUB_LOSE_FAN_TIMER",   # Script_UpdateTrainerFanClubGameClear
]

# --overlap: flags and vars Kanto shares with Johto or Hoenn on purpose.
# "NAME" allows every shared use, "NAME@johto", "NAME@hoenn" or "NAME@alias"
# only that kind.
SHARED_ON_PURPOSE = {
    "FLAG_SYS_POKEMON_GET": "start menu entry, whole game",
    "FLAG_SYS_POKEDEX_GET": "start menu entry, whole game",
    "FLAG_SYS_POKENAV_GET": "PokeCom from Mom in Pallet Town, whole game",
    "FLAG_HAS_MATCH_CALL@johto": "PokeCom; Johto's arrival sets it again (D-005)",
    "FLAG_RECEIVED_POKENAV@johto": "PokeCom; Johto's arrival sets it again (D-005)",
    "FLAG_ADDED_MATCH_CALL_TO_POKENAV@johto": "PokeCom; Johto's arrival sets it again (D-005)",
    "FLAG_ADVENTURE_STARTED": "game start; Johto and Hoenn treat the adventure as started",
    "VAR_TRAIN": "Magnet Train ride, Saffron and Goldenrod stations (D-029)",
    "FLAG_SYS_B_DASH": "Running Shoes, whole game",
    "FLAG_RECEIVED_RUNNING_SHOES": "Running Shoes from Mom in Pallet Town (D-002)",
    "FLAG_SYS_NATIONAL_DEX": "National Pokedex from Oak in Kanto, whole game",
    "VAR_NATIONAL_DEX": "National Pokedex from Oak in Kanto, whole game",
    "FLAG_SYS_RIBBON_GET": "ribbon flag, whole game",
    "FLAG_SYS_PC_LANETTE": "PC storage name flag, whole game",
    "FLAG_SET_WALL_CLOCK": "wall clock set at home in Pallet Town (D-002)",
    "FLAG_START_NUZLOCKE": "Nuzlocke starts at Oak's Pokedex handover (D-004)",
    "FLAG_BADGE01_GET": "Kanto badges; Johto and Hoenn count their own (D-007)",
    "FLAG_BADGE02_GET": "Kanto badges; Johto and Hoenn count their own (D-007)",
    "FLAG_BADGE03_GET": "Kanto badges; Johto and Hoenn count their own (D-007)",
    "FLAG_BADGE04_GET": "Kanto badges; Johto and Hoenn count their own (D-007)",
    "FLAG_BADGE05_GET": "Kanto badges; Johto and Hoenn count their own (D-007)",
    "FLAG_BADGE06_GET": "Kanto badges; Johto and Hoenn count their own (D-007)",
    "FLAG_BADGE07_GET": "Kanto badges; Johto and Hoenn count their own (D-007)",
    "FLAG_BADGE08_GET": "Kanto badges; Johto and Hoenn count their own (D-007)",
    "FLAG_IS_KANTO_CHAMPION@johto": "Kanto title, read by Johto's league and Red (D-007, D-015)",
    "FLAG_SYS_GAME_CLEAR@johto": "first set by the Kanto league, opens the way to Johto (D-007, D-009)",
    "VAR_JOHTO_HANDOVER@johto": "Oak's GS Ball handover, Kanto to Johto (D-004)",
    "FLAG_CAUGHT_MEW": "one Mew, caught means gone for good (D-026)",
    "FLAG_DEFEATED_MEW": "one Mew, caught means gone for good (D-026)",
    "FLAG_RECEIVED_OVAL_CHARM": "one Oval Charm from the first Day Care egg (D-036)",
    "FLAG_PENDING_DAYCARE_EGG": "Day Care egg state, whole game",
    "FLAG_DONT_TRANSITION_MUSIC": "engine flag around warps",
    "FLAG_SYS_ON_CYCLING_ROAD@alias": "FLAG_SYS_CYCLING_ROAD, Emerald name of the same flag",
    "FLAG_HAS_MATCH_CALL@hoenn": "one PokeCom with Match Call from Pallet Town; Hoenn registers trainers on it (D-005)",
    "FLAG_ADDED_MATCH_CALL_TO_POKENAV@hoenn": "one PokeCom; Rustboro's Match Call tutorial is skipped (D-005)",
    "FLAG_ENABLE_MOM_MATCH_CALL": "one Mom (Pallet Town) in the PokeCom, whole game (D-002)",
    "FLAG_GOT_BICYCLE@johto": "one Bicycle; Goldenrod's shop gives none if Kanto's is in the bag (D-041)",
    "FLAG_GOT_COIN_CASE@johto": "one Coin Case; Goldenrod's ball holds a Nugget if it is in the bag (D-041)",
    "FLAG_REGISTER_RIVAL_POKENAV@johto": "rival in the PokeCom; Hoenn uses FLAG_HOENN_REGISTER_RIVAL_POKENAV (D-040)",
    "FLAG_SYS_GAME_CLEAR@hoenn": "a league was won: global uses only; Hoenn post-game checks the Hoenn title (D-040)",
    "VAR_STARTER_MON": "Kanto's starter; Johto uses VAR_JOHTO_STARTER_MON, Hoenn's readers are cut by IS_HNS (D-040)",
}


# ---------------------------------------------------------------------------
# Small helpers

def read(path):
    with open(os.path.join(REPO, path), encoding="utf-8", errors="replace") as f:
        return f.read()


def load_json(path):
    with open(os.path.join(REPO, path), encoding="utf-8") as f:
        return json.load(f)


def host_cc():
    cc = os.environ.get("CC") or shutil.which("cc") or shutil.which("gcc") or shutil.which("clang")
    if not cc:
        sys.exit("make_kanto_complete.py needs a host C compiler (cc/gcc/clang or $CC).")
    return cc


def split_args(text):
    """Splits a command's arguments at commas outside of parentheses."""
    parts, depth, cur = [], 0, []
    for c in text:
        if c == "(":
            depth += 1
        elif c == ")":
            depth -= 1
        if c == "," and depth == 0:
            parts.append("".join(cur).strip())
            cur = []
        else:
            cur.append(c)
    if "".join(cur).strip():
        parts.append("".join(cur).strip())
    return parts


def match_brace(text, i):
    """i points at '{'; returns the index after the matching '}'."""
    depth = 0
    while True:
        c = text[i]
        if c in "\"'":
            q, i = c, i + 1
            while text[i] != q:
                i += 2 if text[i] == "\\" else 1
        elif c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1


def split_top(text):
    """Splits at commas outside of braces, parentheses and strings."""
    parts, depth, cur, i = [], 0, [], 0
    while i < len(text):
        c = text[i]
        if c in "\"'":
            j = i + 1
            while text[j] != c:
                j += 2 if text[j] == "\\" else 1
            cur.append(text[i:j + 1])
            i = j + 1
            continue
        if c in "({":
            depth += 1
        elif c in ")}":
            depth -= 1
        if c == "," and depth == 0:
            parts.append("".join(cur).strip())
            cur = []
        else:
            cur.append(c)
        i += 1
    if "".join(cur).strip():
        parts.append("".join(cur).strip())
    return parts


# ---------------------------------------------------------------------------
# Preprocessor conditions of the script files

class Conditions:
    """Evaluates #if and .if lines with the macros event_scripts.s sees in the jade build."""

    def __init__(self):
        includes = [l for l in read("data/event_scripts.s").splitlines() if l.startswith("#include")]
        out = subprocess.run([host_cc(), "-E", "-dM", "-I", "include", "-iquote", "include"] + DEFINES
                             + ["-x", "c", "-"], input="\n".join(includes) + "\n", cwd=REPO,
                             capture_output=True, text=True)
        if out.returncode != 0:
            sys.exit("Preprocessing the script headers failed:\n" + out.stderr[:2000])
        self.macros = {}
        for line in out.stdout.splitlines():
            m = re.match(r"#define (\w+)(?:\s+(.*))?$", line)
            if m:
                self.macros[m.group(1)] = (m.group(2) or "").strip()

    def expand(self, expr, depth=0):
        if depth > 30:
            return "0"

        def repl(m):
            name = m.group(0)
            if name in ("and", "or", "not"):
                return name
            if name in self.macros and self.macros[name] != "":
                return "(" + self.expand(self.macros[name], depth + 1) + ")"
            return "0"
        return re.sub(r"\b[A-Za-z_]\w*\b", repl, expr)

    def eval(self, expr):
        e = expr.split("@")[0].split("//")[0].strip()
        e = re.sub(r"defined\s*\(\s*(\w+)\s*\)|defined\s+(\w+)",
                   lambda m: "1" if (m.group(1) or m.group(2)) in self.macros else "0", e)
        e = e.replace("&&", " and ").replace("||", " or ")
        e = re.sub(r"!(?!=)", " not ", e)
        e = re.sub(r"\b(0[xX][0-9a-fA-F]+|\d+)[uUlL]+\b", r"\1", e)
        e = self.expand(e).replace("/", "//")
        return bool(eval(e, {"__builtins__": {}}, {}))

    def defined(self, name):
        return name in self.macros

    def lines(self, path):
        """(line number, text) of the lines the build keeps."""
        out, stack, in_macro = [], [], False
        with open(os.path.join(REPO, path), encoding="utf-8", errors="replace") as f:
            for n, line in enumerate(f, 1):
                if re.match(r"\s*\.macro\b", line):
                    in_macro = True
                elif re.match(r"\s*\.endm\b", line):
                    in_macro = False
                pattern = r"\s*#\s*(ifdef|ifndef|if|elif|else|endif)\b\s*(.*)" if in_macro else \
                    r"\s*(?:#\s*|\.)(ifdef|ifndef|if|elif|elseif|else|endif)\b\s*(.*)"
                m = re.match(pattern, line)
                if m:
                    kind, arg = m.groups()
                    kind = "elif" if kind == "elseif" else kind
                    if kind == "ifdef":
                        c = self.defined(arg.split()[0])
                        stack.append((c, c))
                    elif kind == "ifndef":
                        c = not self.defined(arg.split()[0])
                        stack.append((c, c))
                    elif kind == "if":
                        c = self.eval(arg)
                        stack.append((c, c))
                    elif kind == "elif":
                        _, taken = stack.pop()
                        c = (not taken) and self.eval(arg)
                        stack.append((c, taken or c))
                    elif kind == "else":
                        _, taken = stack.pop()
                        stack.append((not taken, True))
                    else:
                        stack.pop()
                    continue
                if all(active for active, _ in stack):
                    out.append((n, line.rstrip("\n")))
        return out


# ---------------------------------------------------------------------------
# Script labels

TERMINATORS = {"end", "return", "goto", "step_end", "releaseall_end"}
STRING_CMDS = {"msgbox", "message", "applymovement", "braillemessage", "braillemsgbox",
               "braillemessage_wait", "pokemart", "pokemartdecoration", "pokemartdecoration2",
               "signmsg"}


class Scripts:
    def __init__(self, cond):
        self.cond = cond
        self.files = []
        self._include("data/event_scripts.s")
        self.labels = {}
        self.aliases = {}
        for path in self.files:
            self._parse(path)

    def _include(self, path):
        self.files.append(path)
        for _, line in self.cond.lines(path):
            m = re.match(r'\s*\.include\s+"(data/[^"]+)"', line)
            if m and m.group(1) not in self.files and os.path.exists(os.path.join(REPO, m.group(1))):
                self._include(m.group(1))

    def _parse(self, path):
        cur = None
        for n, line in self.cond.lines(path):
            if line.lstrip().startswith((".string", ".braille")):
                continue
            code = line.split("@")[0]
            m = re.match(r"\s*\.(?:set|equ)\s+(\w+)\s*,\s*(\w+)", code)
            if m:
                self.aliases[(path, m.group(1))] = m.group(2)
                continue
            m = re.match(r"^(\w+)::?\s*(.*)$", code)
            if m:
                name = m.group(1)
                if cur is not None and self.labels[cur]["falls"]:
                    self.labels[cur]["next"] = name
                self.labels[name] = {"file": path, "line": n, "cmds": [], "next": None, "falls": True}
                cur = name
                if not m.group(2).strip():
                    continue
                code = "\t" + m.group(2)
            if cur is None:
                continue
            m = re.match(r"^\s+([.\w]+)\s*(.*)$", code)
            if not m:
                continue
            cmd, args = m.group(1), split_args(m.group(2).strip())
            args = [self.aliases.get((path, a), a) for a in args]
            label = self.labels[cur]
            label["cmds"].append((n, cmd, args))
            if cmd in TERMINATORS or (cmd in (".2byte", ".byte") and args == ["0"]
                                      and label["cmds"][0][1] in ("map_script", "map_script_2", ".2byte", ".byte")):
                label["falls"] = False

    def edges(self, name):
        label = self.labels[name]
        for _, cmd, args in label["cmds"]:
            if cmd in STRING_CMDS:
                continue
            for a in args:
                for tok in re.findall(r"\b\w+\b", a):
                    if tok in self.labels:
                        yield tok
        if label["falls"] and label["next"]:
            yield label["next"]

    def walk(self, starts, cut=lambda name: False):
        seen = {s for s in starts if s in self.labels and not cut(s)}
        todo = list(seen)
        while todo:
            for nxt in self.edges(todo.pop()):
                if nxt not in seen and not cut(nxt):
                    seen.add(nxt)
                    todo.append(nxt)
        return seen

    def run_straight(self, name):
        """Commands of a label up to its end, following fallthrough."""
        while name:
            label = self.labels[name]
            for cmd in label["cmds"]:
                if cmd[1] in ("end", "return"):
                    return
                yield cmd
            name = label["next"] if label["falls"] else None


def is_cut(name):
    return name in CUT_LABELS or name.startswith(CUT_PREFIXES)


# ---------------------------------------------------------------------------
# Maps

class Maps:
    def __init__(self):
        layouts = {l["id"]: l for l in load_json("data/layouts/layouts.json")["layouts"] if l}
        self.all = {}
        for path in glob.glob(os.path.join(REPO, "data/maps/*/map.json")):
            with open(path, encoding="utf-8") as f:
                d = json.load(f)
            d["_dir"] = os.path.basename(os.path.dirname(path))
            lay = layouts.get(d.get("layout"))
            if d.get("game_version") == "hns" and lay and lay.get("game_version") == "hns":
                self.all[d["id"]] = d
        self.kanto = sorted((d for d in self.all.values()
                             if d["_dir"].endswith("_Frlg") and d["_dir"] not in EXCLUDED_MAPS),
                            key=lambda d: d["_dir"])

    @staticmethod
    def region(d):
        if d["_dir"].endswith("_Frlg"):
            return "kanto"
        return "johto" if d["_dir"].endswith("_hns") else "hoenn"

    @staticmethod
    def entries(d):
        out = [d["_dir"] + "_MapScripts"]
        for key in ("object_events", "coord_events", "bg_events"):
            for e in d.get(key) or []:
                if e.get("script") and e["script"] != "0x0":
                    out.append(e["script"])
        return out


# ---------------------------------------------------------------------------
# Species, items, trainers

def load_species_constants():
    """SPECIES_ name -> number, number -> canonical name (constants/species.h)."""
    raw, order = {}, []
    for line in read("include/constants/species.h").splitlines():
        m = re.match(r"#define\s+(SPECIES_\w+)\s+(.+?)\s*(//.*)?$", line)
        if m:
            raw[m.group(1)] = m.group(2)
            order.append(m.group(1))
    values = {}

    def resolve(name, depth=0):
        if name not in values:
            text = re.sub(r"SPECIES_\w+", lambda m: str(resolve(m.group(0), depth + 1)), raw[name])
            text = re.sub(r"\b(\d+)[uU]?\b", r"\1", text)
            values[name] = int(eval(text, {"__builtins__": {}}, {}))
        return values[name]
    for name in order:
        resolve(name)
    by_number = {}
    for name in order:
        if re.fullmatch(r"\d+", raw[name]):
            by_number.setdefault(values[name], name)
    for name in order:
        by_number.setdefault(values[name], name)
    return values, by_number


def load_species():
    """Enabled species in gSpeciesInfo order: name -> {num, natdex, evos}."""
    values, by_number = load_species_constants()
    if not shutil.which(ARM_CPP[0]):
        sys.exit("make_kanto_complete.py needs %s (the build's preprocessor)." % ARM_CPP[0])
    out = subprocess.run(ARM_CPP + ["src/pokemon.c"], cwd=REPO, capture_output=True, text=True)
    if out.returncode != 0:
        sys.exit("Preprocessing src/pokemon.c failed:\n" + out.stderr[:2000])
    text = out.stdout
    start = text.index("const struct SpeciesInfo gSpeciesInfo[] =")
    first = text.index("{", start)
    end = match_brace(text, first)
    i = first + 1
    entry_re = re.compile(r"\s*\[([^\]]+)\]\s*=\s*")
    species = {}

    def number(expr):
        expr = re.sub(r"SPECIES_\w+", lambda m: str(values[m.group(0)]), expr)
        return int(eval(re.sub(r"\b(\d+)[uU]?\b", r"\1", expr), {"__builtins__": {}}, {}))
    while i < end - 1:
        m = entry_re.match(text, i)
        if not m:
            i += 1
            continue
        num = number(m.group(1))
        body_start = text.index("{", m.end())
        body_end = match_brace(text, body_start)
        body = text[body_start:body_end]
        evos = []
        k = body.find(".evolutions =")
        if k != -1:
            arr = body.index("{", body.index("(const struct Evolution[])", k) + 1)
            for item in split_top(body[arr + 1:match_brace(body, arr) - 1]):
                if not item.startswith("{"):
                    continue
                fields = split_top(item[1:-1])
                if fields[0] == "0xFFFF":
                    break
                conds = re.findall(r"\{(IF_\w+)\s*,?\s*([^{}]*)\}", fields[3]) if len(fields) > 3 else []
                evos.append({"method": fields[0], "param": fields[1].strip(),
                             "target": by_number.get(number(fields[2])),
                             "conds": [(c, a.strip().rstrip(",").strip()) for c, a in conds]})
        nd = re.search(r"\.natDexNum\s*=\s*(\w+)", body)
        species[by_number.get(num, str(num))] = {"num": num, "natdex": nd.group(1) if nd else None, "evos": evos}
        i = body_end
    return species


def load_natdex_order():
    text = read("include/constants/pokedex.h")
    m = re.search(r"enum\s+NationalDexOrder\s*\{(.*?)\}", text, re.S)
    order, n = {}, -1
    for item in re.sub(r"//[^\n]*", "", m.group(1)).split(","):
        item = item.strip()
        if not item:
            continue
        name, _, val = item.partition("=")
        n = int(val.strip(), 0) if val.strip().isdigit() else n + 1
        order[name.strip()] = n
    return order


def load_key_items(cond):
    """Items in the key items pocket of this build (src/data/items.h)."""
    items, cur = set(), None
    for _, line in cond.lines("src/data/items.h"):
        m = re.match(r"\s*\[(ITEM_\w+)\]\s*=", line)
        if m:
            cur = m.group(1)
        elif cur and re.search(r"\.pocket\s*=\s*POCKET_KEY_ITEMS\b", line):
            items.add(cur)
    return items


def load_item_aliases():
    return dict(re.findall(r"^\s*(ITEM_\w+) = (ITEM_\w+),", read("include/constants/items.h"), re.M))


def species_constant(name):
    """trainerproc's species name -> SPECIES_ constant."""
    if name.startswith("SPECIES_"):
        return name
    out, underscore = ["SPECIES_"], False
    for ch in name:
        if ch.isascii() and ch.isalnum():
            if underscore:
                out.append("_")
            underscore = False
            out.append(ch.upper())
        elif ch in "'%’":
            pass
        elif ch == "♂":
            underscore = False
            out.append("_M")
        elif ch == "♀":
            underscore = False
            out.append("_F")
        elif ch == "é":
            if underscore:
                out.append("_")
            underscore = False
            out.append("E")
        else:
            underscore = True
    return "".join(out)


MON_HEADER_RE = re.compile(r"^(?P<first>[^()@]+?)\s*(?:\((?P<second>[^()]+)\)\s*(?:\((?P<third>[^()]+)\))?)?\s*(?:@\s*(?P<item>.+?))?\s*$")


def load_parties(path):
    """trainer id -> {class, double, mons: [(species, level)]} of a .party file."""
    text = re.sub(r"/\*.*?\*/", "", read(path), flags=re.S)
    parties = {}
    for block in re.split(r"(?m)^(?====)", text):
        m = re.match(r"===\s*(\w+)\s*===", block)
        if not m:
            continue
        trainer = {"class": "", "double": False, "mons": []}
        chunks = re.split(r"\n\s*\n", block.split("\n", 1)[1] if "\n" in block else "")
        for n, chunk in enumerate(chunks):
            lines = [l.rstrip() for l in chunk.strip("\n").split("\n") if l.strip()]
            if not lines:
                continue
            if n == 0:
                for line in lines:
                    if line.startswith("Class:"):
                        trainer["class"] = line.split(":", 1)[1].strip()
                    elif line.startswith("Double Battle:"):
                        trainer["double"] = line.split(":", 1)[1].strip().lower() == "yes"
                continue
            h = MON_HEADER_RE.match(lines[0].strip())
            if not h:
                continue
            second, third = h.group("second"), h.group("third")
            name = second.strip() if third is not None or (second is not None and len(second.strip()) > 1) \
                else h.group("first").strip()
            level = 100
            for line in lines[1:]:
                lm = re.match(r"Level:\s*(\d+)", line)
                if lm:
                    level = int(lm.group(1))
            trainer["mons"].append((species_constant(name), level))
        parties[m.group(1)] = trainer
    return parties


def load_class_money():
    money = {}
    text = read("src/battle_main.c")
    for m in re.finditer(r"\[(TRAINER_CLASS_\w+)\]\s*=\s*\{\s*_\(\"[^\"]*\"\)\s*(?:,\s*(\d+))?", text):
        money[m.group(1)] = int(m.group(2)) if m.group(2) and int(m.group(2)) else 5
    return money


def prize_money(party, class_money):
    """GetTrainerMoneyToGive for a single or double battle."""
    if not party or not party["mons"]:
        return 20
    cls = "TRAINER_CLASS_" + re.sub(r"[^A-Z0-9]+", "_", party["class"].upper()).strip("_")
    return 4 * party["mons"][-1][1] * class_money.get(cls, 5) * (2 if party["double"] else 1)


# ---------------------------------------------------------------------------
# The run

TRAINER_BATTLES = {
    "trainerbattle_single": [0], "trainerbattle_double": [0], "trainerbattle_no_intro": [0],
    "trainerbattle_earlyrival": [0], "trainerbattle_rematch": [0],
    "trainerbattle_rematch_double": [0], "trainerbattle_two_trainers": [0, 2],
}


class KantoRun:
    def __init__(self):
        self.cond = Conditions()
        self.scripts = Scripts(self.cond)
        self.maps = Maps()
        self.warnings = []
        self.labels = set()
        for d in self.maps.kanto:
            self.labels |= self.scripts.walk(Maps.entries(d), is_cut)
        self.item_aliases = load_item_aliases()
        self._collect()
        self._flags()
        self._vars()
        self._trainers()
        self._items()
        self._species()

    def item(self, name):
        return self.item_aliases.get(name, name)

    def cmds(self):
        for name in sorted(self.labels):
            for n, cmd, args in self.scripts.labels[name]["cmds"]:
                yield name, cmd, args

    def _collect(self):
        self.flag_writes = collections.defaultdict(set)
        self.var_writes = collections.defaultdict(set)
        self.trainers_fought = set()
        self.trainers_cleared = set()
        self.var_setvalues = collections.defaultdict(set)   # VAR -> SPECIES_/ITEM_ values
        self.legendaries = set()
        self.statics = set()
        self.gift_species = set()
        self.trade_ids = set()
        self.item_gifts = collections.defaultdict(dict)    # item -> label -> quantity
        self.item_removed = collections.defaultdict(int)
        self.item_var_gifts = set()
        self.shops = set()
        self.breeding = False
        objs = {d["_dir"]: d.get("object_events") or [] for d in self.maps.kanto}

        def object_flag(mdir, lid):
            for i, o in enumerate(objs.get(mdir, [])):
                if o.get("local_id") == lid or str(i + 1) == lid:
                    return o.get("flag")
            return None
        for name, cmd, a in self.cmds():
            path = self.scripts.labels[name]["file"]
            mdir = path.split("/")[2] if path.startswith("data/maps/") else None
            if cmd in ("setflag", "setworldmapflag"):
                self.flag_writes[a[0]].add(1)
            elif cmd == "clearflag":
                self.flag_writes[a[0]].add(0)
            elif cmd == "removeobject" and a and a[0] != "VAR_LAST_TALKED":
                fl = object_flag(mdir, a[0]) if mdir else None
                if fl and fl != "0":
                    self.flag_writes[fl].add(1)
            elif cmd == "setvar":
                self.var_writes[a[0]].add(a[1])
                if re.match(r"(SPECIES|ITEM)_", a[1]):
                    self.var_setvalues[a[0]].add(a[1])
                elif a[1].startswith("INGAME_TRADE_"):
                    self.trade_ids.add(a[1])
                elif a[0] == "VAR_0x8004" and a[1].startswith("LEGENDARY_"):
                    self.legendaries.add(a[1])
            elif cmd in ("addvar", "subvar", "copyvar"):
                self.var_writes[a[0]].add(cmd + " " + a[1])
            elif cmd == "settrainerflag":
                self.trainers_fought.add(a[0])
            elif cmd == "cleartrainerflag":
                self.trainers_cleared.add(a[0])
            elif cmd in TRAINER_BATTLES:
                for i in TRAINER_BATTLES[cmd]:
                    self.trainers_fought.add(a[i])
            elif cmd in ("giveitem", "additem") and a:
                if a[0].startswith("ITEM_"):
                    self.item_gifts[self.item(a[0])][name] = int(a[1]) if len(a) > 1 and a[1].isdigit() else 1
                else:
                    self.item_var_gifts.add(a[0])
            elif cmd == "giveitem_msg" and len(a) > 1:
                if a[1].startswith("ITEM_"):
                    self.item_gifts[self.item(a[1])][name] = int(a[2]) if len(a) > 2 and a[2].isdigit() else 1
            elif cmd == "removeitem" and a and a[0].startswith("ITEM_"):
                q = int(a[1]) if len(a) > 1 and a[1].isdigit() else 1
                self.item_removed[self.item(a[0])] = max(self.item_removed[self.item(a[0])], q)
            elif cmd in ("givemon", "giveegg") and a:
                self.gift_species.add(a[0])   # a species or a var, resolved below
            elif cmd == "setwildbattle" and a:
                self.statics.add(a[0])
            elif cmd == "pokemart" and a:
                self.shops.add(a[0])
            elif cmd in ("special", "specialvar", "callnative") and a and a[-1] == "GiveEggFromDaycare":
                self.breeding = True
        resolved = set()
        for s in self.gift_species:
            if s.startswith("SPECIES_"):
                resolved.add(s)
            else:
                resolved |= {v for v in self.var_setvalues.get(s, ()) if v.startswith("SPECIES_")}
        self.gift_species = resolved

    def _flags(self):
        flags = {}
        unresolved = []
        for name, values in self.flag_writes.items():
            if name.startswith("FLAG_TEMP_") or name in DROP_FLAGS or name in SET_BY_DEBUG_C:
                continue
            if name in MANUAL_FLAGS:
                continue
            if len(values) == 1:
                flags[name] = next(iter(values))
            else:
                unresolved.append(name)
        for name in sorted(unresolved):
            self.warnings.append("%s is set and cleared by Kanto scripts and has no MANUAL_FLAGS entry; "
                                 "left at its new game value" % name)
        for name, value in MANUAL_FLAGS.items():
            flags[name] = value
        # Legendaries caught: RecordLegendaryBattleOutcome sets the caught and done flags.
        table = read("src/legendaries_oj.c")
        for lid in self.legendaries:
            m = re.search(r"\[%s\]\s*=\s*STATIC_LEGENDARY\((\w+),\s*(\w+)" % lid, table)
            if m:
                flags[m.group(1)] = 1
                if m.group(2) != "0":
                    flags[m.group(2)] = 1
        # Item balls and hidden items of the Kanto maps.
        for d in self.maps.kanto:
            for o in d.get("object_events") or []:
                if self._ball_item(o) and o.get("flag", "0") not in ("0", ""):
                    flags[o["flag"]] = 1
            for b in d.get("bg_events") or []:
                if b.get("type") == "hidden_item" and b.get("flag"):
                    flags[b["flag"]] = 1
        self.flags = flags

    def _ball_item(self, obj):
        script = obj.get("script")
        if script not in self.scripts.labels or "ITEM_BALL" not in (obj.get("graphics_id") or ""):
            return None
        for _, cmd, args in self.scripts.labels[script]["cmds"]:
            if cmd == "finditem":
                return self.item(args[0]), int(args[1]) if len(args) > 1 and args[1].isdigit() else 1
        return None

    def _vars(self):
        out = {}
        for name, values in self.var_writes.items():
            if SCRATCH_VAR_RE.match(name) or name in SET_BY_DEBUG_C or name in MANUAL_VARS:
                continue
            if len(values) == 1 and not next(iter(values)).startswith(("addvar", "subvar", "copyvar")):
                out[name] = next(iter(values))
            else:
                self.warnings.append("%s is written with %s by Kanto scripts and has no MANUAL_VARS entry; "
                                     "left at its new game value" % (name, ", ".join(sorted(values))))
        for name, value in MANUAL_VARS.items():
            out[name] = str(value)
        self.vars = out

    def _trainers(self):
        parties = load_parties("src/data/trainers_frlg.party")
        class_money = load_class_money()
        fought = {t for t in self.trainers_fought if t.startswith("TRAINER_") and not TRAINER_SKIP_RE.match(t)}
        missing = sorted(t for t in fought if t not in parties)
        if missing:
            self.warnings.append("trainers without a party in trainers_frlg.party: " + ", ".join(missing))
        self.trainers = sorted(t for t in fought if not RIVAL_RE.match(t) and t not in self.trainers_cleared)
        common_money = sum(prize_money(parties.get(t), class_money) for t in fought if not RIVAL_RE.match(t))
        # VAR_STARTER_MON -> the rival's starter, from the branches on VAR_STARTER_MON.
        rival_of = collections.defaultdict(set)
        for name, cmd, a in self.cmds():
            if cmd.endswith("_if_eq") and len(a) == 3 and a[0] == "VAR_STARTER_MON" and a[1].isdigit():
                for lab in self.scripts.walk([a[2]], is_cut):
                    for _, c, args in self.scripts.labels[lab]["cmds"]:
                        if c in TRAINER_BATTLES:
                            m = RIVAL_RE.match(args[0])
                            if m:
                                rival_of[int(a[1])].add(m.group(2))
        self.rival_by_starter = []
        self.rival_money = []
        for starter in range(len(STARTER_NAMES)):
            suffixes = rival_of.get(starter, set())
            if len(suffixes) != 1:
                sys.exit("cannot tell the rival's starter for VAR_STARTER_MON %d: %s" % (starter, sorted(suffixes)))
            suffix = next(iter(suffixes))
            battles = sorted(t for t in fought if RIVAL_RE.match(t) and RIVAL_RE.match(t).group(2) == suffix)
            self.rival_by_starter.append([t for t in battles if t not in self.trainers_cleared])
            self.rival_money.append(sum(prize_money(parties.get(t), class_money) for t in battles))
        sizes = {len(r) for r in self.rival_by_starter}
        if len(sizes) != 1:
            sys.exit("the three rival paths have different lengths: %s" % self.rival_by_starter)
        start = re.search(r"SetMoney\(&gSaveBlock1Ptr->money,\s*(\d+)\)", read("src/new_game.c"))
        self.money = int(start.group(1)) + common_money + self.rival_money[KANTO_COMPLETE_STARTER]
        # Species seen in trainer battles.
        self.seen_common = {s for t in fought if not RIVAL_RE.match(t) for s, _ in parties.get(t, {"mons": []})["mons"]}
        self.seen_rival = [{s for t in r for s, _ in parties.get(t, {"mons": []})["mons"]}
                           for r in self.rival_by_starter]

    def _items(self):
        bag = collections.Counter()
        # New game items (removed again by ClearBag).
        for label in ("EventScript_ResetAllMapFlagsHnS", "EventScript_ResetAllMapFlagsFrlg"):
            if label in self.scripts.labels:
                for _, cmd, a in self.scripts.run_straight(label):
                    if cmd == "additem" and a[0].startswith("ITEM_"):
                        bag[self.item(a[0])] += int(a[1]) if len(a) > 1 and a[1].isdigit() else 1
        for d in self.maps.kanto:
            for o in d.get("object_events") or []:
                found = self._ball_item(o)
                if found:
                    bag[found[0]] += found[1]
            for b in d.get("bg_events") or []:
                # ITEM_NONE: Game Corner coins, not counted.
                if b.get("type") == "hidden_item" and b["item"] != "ITEM_NONE":
                    bag[self.item(b["item"])] += int(b.get("quantity", 1))
        for item, by_label in self.item_gifts.items():
            if item not in SKIP_GIFT_ITEMS:
                bag[item] += sum(by_label.values())
        for item, q in EXTRA_ITEMS.items():
            bag[self.item(item)] += q
        for item, q in self.item_removed.items():
            bag[item] -= q
        # One of each key item: gifts in exclusive branches (e.g. the Route 15
        # aide's Exp. Share or Small Exp. Share) are all counted above.
        for item in load_key_items(self.cond):
            if bag[item] > 1:
                bag[item] = 1
        self.bag = {i: q for i, q in sorted(bag.items()) if q > 0}
        # Items for evolutions: everything found, given, sold or won in Kanto.
        avail = set(bag) | set(self.item_gifts)
        for var in self.item_var_gifts:
            avail |= {self.item(v) for v in self.var_setvalues.get(var, ()) if v.startswith("ITEM_")}
        for shop in self.shops:
            for _, cmd, a in self.scripts.labels.get(shop, {"cmds": []})["cmds"]:
                if cmd == ".2byte" and a and a[0].startswith("ITEM_"):
                    avail.add(self.item(a[0]))
        self.items_available = avail

    def _species(self):
        sp = load_species()
        kanto_ids = {d["id"] for d in self.maps.kanto}
        wild_levels = {}
        for group in load_json("src/data/wild_encounters.json")["wild_encounter_groups"]:
            if not group.get("for_maps"):
                continue
            for e in group["encounters"]:
                if e["map"] not in kanto_ids or "LeafGreen" in e["base_label"]:
                    continue
                for key in ("land_mons", "water_mons", "rock_smash_mons", "fishing_mons"):
                    for m in (e.get(key) or {}).get("mons", []):
                        wild_levels[m["species"]] = max(wild_levels.get(m["species"], 0), m["max_level"])
        trades = {}
        kept = "\n".join(l for _, l in self.cond.lines("src/data/trade.h"))
        for tid in self.trade_ids:
            m = re.search(r"\[%s\]\s*=\s*\{(.*?)\n\s*\}," % tid, kept, re.S)
            if m:
                sm = re.search(r"\.species\s*=\s*(SPECIES_\w+)", m.group(1))
                if sm:
                    trades[tid] = sm.group(1)
        kanto_mapsecs = {d.get("region_map_section") for d in self.maps.kanto}
        how = {}
        for s in wild_levels:
            how.setdefault(s, "wild")
        for s in sorted(self.statics - UNCATCHABLE_STATIC):
            how.setdefault(s, "static")
        for s in sorted(self.gift_species):
            how.setdefault(s, "gift")
        for s in sorted(trades.values()):
            how.setdefault(s, "trade")
        pre = {}
        for s, d in sp.items():
            for e in d["evos"]:
                pre.setdefault(e["target"], (s, e))

        def root(s):
            while s in pre:
                s = pre[s][0]
            return s

        def evo_ok(e):
            if e["method"] == "EVO_TRADE":
                return False
            if e["method"] == "EVO_ITEM" and self.item(e["param"]) not in self.items_available:
                return False
            for c, arg in e["conds"]:
                if c == "IF_IN_MAPSEC" and arg not in kanto_mapsecs:
                    return False
                if c == "IF_HOLD_ITEM" and self.item(arg) not in self.items_available:
                    return False
            return True
        changed = True
        while changed:
            changed = False
            for s in list(how):
                for e in sp.get(s, {"evos": []})["evos"]:
                    if e["target"] in sp and e["target"] not in how and evo_ok(e):
                        how[e["target"]] = "evo"
                        changed = True
                b = root(s)
                if self.breeding and b in sp and b not in how:
                    how[b] = "breed"
                    changed = True
        missing = [s for s in how if s not in sp]
        if missing:
            self.warnings.append("species not enabled in this build: " + ", ".join(sorted(missing)))
        self.how = {s: h for s, h in how.items() if s in sp}
        levels = {}

        def level(s):
            if s not in levels:
                h = self.how.get(s)
                if s in wild_levels:
                    lv = wild_levels[s]
                elif s in GIFT_LEVELS:
                    lv = GIFT_LEVELS[s]
                elif h == "breed":
                    lv = 1
                elif h == "evo":
                    base, e = pre[s]
                    lv = level(base)
                    p = e["param"]
                    if e["method"] in ("EVO_LEVEL", "EVO_LEVEL_BATTLE_ONLY") and p.isdigit() and int(p) > 0:
                        lv = max(lv, int(p))
                    else:
                        lv += 5
                else:
                    lv = DEFAULT_BOX_LEVEL
                levels[s] = min(lv, MAX_BOX_LEVEL)
            return levels[s]
        party = {s for s, _ in KANTO_COMPLETE_PARTY}
        for s in list(party) + KANTO_COMPLETE_PARTY_STARTER_FINAL:
            if s not in self.how:
                self.warnings.append("party species %s is not obtainable in Kanto" % s)
        self.box = [(s, level(s)) for s in sorted(self.how, key=lambda s: sp[s]["num"]) if s not in party]
        self.seen_only = sorted((s for s in self.seen_common if s not in self.how and s in sp),
                                key=lambda s: sp[s]["num"])
        for i, seen in enumerate(self.seen_rival):
            extra = sorted(s for s in seen if s not in self.how and s not in self.seen_common)
            if extra:
                sys.exit("the rival of a %s player fields species Kanto does not offer: %s"
                         % (STARTER_NAMES[i], ", ".join(extra)))
        # Gen-1 families not obtainable, for the summary.
        natdex = load_natdex_order()
        gen1 = {s for s, d in sp.items() if 1 <= natdex.get(d["natdex"], 0) <= 151}
        roots = {root(s) for s in gen1}
        forms = re.compile(r"_(GMAX|MEGA|ALOLA|GALAR|HISUI|PALDEA|CAP|COSPLAY|ORIGINAL|PARTNER|STARTER|ROCK_STAR"
                           r"|BELLE|POP_STAR|PH_D|LIBRE|HOENN|SINNOH|UNOVA|KALOS|WORLD|FEMALE)")
        self.not_obtainable = sorted(s for s in sp if root(s) in roots and s not in self.how and not forms.search(s))


# ---------------------------------------------------------------------------
# Header

def render(run):
    out = []
    w = out.append
    w("// Generated by tools/make_kanto_complete.py - do not edit.")
    w("// State right after the first Kanto Hall of Fame for the debug menu's \"Johto Test\".")
    w("// Regenerate: python3 tools/make_kanto_complete.py (check: --check, shared state: --overlap).")
    w("")
    w("#define KANTO_COMPLETE_STARTER %d  // VAR_STARTER_MON: 0 Bulbasaur, 1 Squirtle, 2 Charmander"
      % KANTO_COMPLETE_STARTER)
    w("#define KANTO_COMPLETE_MONEY %d  // start money and every prize of the run" % run.money)
    w("")
    w("struct KantoCompleteMon { u16 species; u8 level; };")
    w("struct KantoCompleteVar { u16 var; u16 value; };")
    w("struct KantoCompleteItem { u16 item; u16 quantity; };")
    w("")

    def array(decl, items):
        w(decl)
        w("{")
        for item in items:
            w("    %s," % item)
        w("};")
        w("")
    array("static const u16 sKantoCompleteFlagsSet[] =", sorted(n for n, v in run.flags.items() if v))
    array("static const u16 sKantoCompleteFlagsClear[] =", sorted(n for n, v in run.flags.items() if not v))
    array("static const struct KantoCompleteVar sKantoCompleteVars[] =",
          ["{ %s, %s }" % (n, v) for n, v in sorted(run.vars.items())])
    array("static const u16 sKantoCompleteTrainers[] =", run.trainers)
    w("// Index: VAR_STARTER_MON.")
    w("static const u16 sKantoCompleteRivalTrainers[%d][%d] =" % (len(run.rival_by_starter), len(run.rival_by_starter[0])))
    w("{")
    for i, r in enumerate(run.rival_by_starter):
        w("    [%d] = { %s }," % (i, ", ".join(r)))
    w("};")
    w("")
    array("static const struct KantoCompleteItem sKantoCompleteBag[] =",
          ["{ %s, %d }" % (i, q) for i, q in run.bag.items()])
    w("// Index: VAR_STARTER_MON.")
    array("static const struct KantoCompleteMon sKantoCompletePartyStarter[] =",
          ["{ %s, %d }" % (s, KANTO_COMPLETE_PARTY_STARTER_LEVEL) for s in KANTO_COMPLETE_PARTY_STARTER_FINAL])
    array("static const struct KantoCompleteMon sKantoCompleteParty[] =",
          ["{ %s, %d }" % (s, lv) for s, lv in KANTO_COMPLETE_PARTY])
    w("// Box: every other species caught or evolved in Kanto; the chosen starter's")
    w("// final stage is in the party.")
    array("static const struct KantoCompleteMon sKantoCompleteMons[] =", ["{ %s, %d }" % m for m in run.box])
    array("static const u16 sKantoCompleteSeenOnly[] =", run.seen_only)
    return "\n".join(out).rstrip("\n") + "\n"


# ---------------------------------------------------------------------------
# --overlap

def resolve_values(names):
    """Numbers of FLAG_/VAR_ macros, via a compiled host program."""
    prelude = ('#include <stdio.h>\n#define TRUE 1\n#define FALSE 0\n#include "config/general.h"\n'
               '#include "constants/global.h"\n#include "constants/flags.h"\n#include "constants/vars.h"\n')
    cc = host_cc()
    names = sorted(names)
    with tempfile.TemporaryDirectory() as tmp:
        src, exe = os.path.join(tmp, "v.c"), os.path.join(tmp, "v")
        for _ in range(50):
            with open(src, "w") as f:
                f.write(prelude + "int main(void)\n{\n")
                for n in names:
                    f.write('    printf("%%s %%lld\\n", "%s", (long long)(%s));\n' % (n, n))
                f.write("    return 0;\n}\n")
            out = subprocess.run([cc, "-w", "-Iinclude"] + DEFINES + [src, "-o", exe], cwd=REPO,
                                 capture_output=True, text=True)
            if out.returncode == 0:
                break
            lines = open(src).read().split("\n")
            bad = set()
            for m in re.finditer(r"v\.c:(\d+):\d+: (?:error|note: in expansion)", out.stderr):
                hit = re.search(r'"(\w+)", \(long long\)', lines[int(m.group(1)) - 1])
                if hit:
                    bad.add(hit.group(1))
            if not bad:
                sys.exit("Could not evaluate the flag/var macros:\n" + out.stderr[:2000])
            names = [n for n in names if n not in bad]
        values = {}
        for line in subprocess.run([exe], capture_output=True, text=True).stdout.splitlines():
            n, v = line.split()
            values[n] = int(v)
    return values


def c_functions():
    funcs = {}
    fdef = re.compile(r"^[\w \*]+?\b(\w+)\s*\(([^;{]*)\)\s*\{", re.M)
    for path in sorted(glob.glob(os.path.join(REPO, "src/*.c"))):
        if path.endswith("/debug.c"):
            continue
        with open(path, encoding="utf-8", errors="replace") as f:
            text = f.read()
        for m in fdef.finditer(text):
            i, depth = m.end(), 1
            while depth and i < len(text):
                depth += {"{": 1, "}": -1}.get(text[i], 0)
                i += 1
            funcs.setdefault(m.group(1), text[m.start():i])
    return funcs


def c_tokens(funcs, name, depth=2, seen=None):
    seen = seen if seen is not None else set()
    if name in seen or name not in funcs:
        return set()
    seen.add(name)
    body = funcs[name]
    toks = set(re.findall(r"\b((?:FLAG|VAR)_[A-Z0-9_]+)\b", body))
    if depth:
        for callee in set(re.findall(r"\b([A-Z]\w+)\s*\(", body)):
            if callee != name:
                toks |= c_tokens(funcs, callee, depth - 1, seen)
    return toks


GENERIC_NAME_RE = re.compile(r"^(FLAG|VAR)_(0x[0-9A-Fa-f]+|TEMP_\w+|UNUSED\w*|SPECIAL_FLAG_UNUSED\w*|LANDMARK_\w+|REGISTERED_\w+)$")


def overlap(run):
    state = {}
    for n, v in run.flags.items():
        state[n] = "set" if v else "clear"
    for n, v in run.vars.items():
        state[n] = "= " + v
    for n in RUNTIME_STATE:
        state.setdefault(n, "C")
    tok = re.compile(r"\b((?:FLAG|VAR)_\w+)\b")
    refs = collections.defaultdict(lambda: collections.defaultdict(set))   # name -> region -> places
    any_refs = collections.defaultdict(set)
    funcs = c_functions()
    reached = collections.defaultdict(set)
    for d in run.maps.all.values():
        region = Maps.region(d)
        if region == "kanto":
            continue
        for name in run.scripts.walk(Maps.entries(d)):
            reached[name].add(region)
        for o in d.get("object_events") or []:
            if o.get("flag", "0") not in ("0", ""):
                refs[o["flag"]][region].add("%s (object)" % d["_dir"])
        for b in d.get("bg_events") or []:
            if b.get("type") == "hidden_item" and b.get("flag"):
                refs[b["flag"]][region].add("%s (hidden item)" % d["_dir"])
        for c in d.get("coord_events") or []:
            if c.get("var"):
                refs[c["var"]][region].add("%s (trigger)" % d["_dir"])
    for name, regions in reached.items():
        label = run.scripts.labels[name]
        for n, cmd, args in label["cmds"]:
            where = "%s (%s:%d)" % (name, label["file"], n)
            for a in args:
                for t in tok.findall(a):
                    for r in regions:
                        refs[t][r].add(where)
            if cmd in ("special", "specialvar") and args:
                for t in c_tokens(funcs, args[-1]):
                    for r in regions:
                        refs[t][r].add("%s via special %s" % (name, args[-1]))
    for name, label in run.scripts.labels.items():
        for _, _, args in label["cmds"]:
            for a in args:
                for t in tok.findall(a):
                    any_refs[t].add(label["file"])
    c_refs = collections.defaultdict(set)
    for path in glob.glob(os.path.join(REPO, "src/**/*.[ch]"), recursive=True):
        rel = os.path.relpath(path, REPO)
        if rel in ("src/debug.c", HEADER):
            continue
        with open(path, encoding="utf-8", errors="replace") as f:
            for t in set(tok.findall(f.read())):
                c_refs[t].add(rel)
                any_refs[t].add(rel)
    names = {n for n in run.cond.macros if n.startswith(("FLAG_", "VAR_"))
             and not n.endswith(("_START", "_END", "_COUNT", "_SIZE", "_BASE"))}
    values = resolve_values(names)
    by_value = collections.defaultdict(set)
    for n, v in values.items():
        by_value[(n.split("_")[0], v)].add(n)
    rows = []
    for name in sorted(state):
        kinds = {}
        for region in ("johto", "hoenn"):
            if refs[name].get(region):
                kinds[region] = sorted(refs[name][region])
        if name in values:
            others = sorted(n for n in by_value[(name.split("_")[0], values[name])]
                            if n != name and not GENERIC_NAME_RE.match(n) and any_refs.get(n))
            if others:
                kinds["alias"] = others
        if kinds:
            rows.append((name, kinds))
    failed, allowed = [], []
    for name, kinds in rows:
        bad = [k for k in kinds if name not in SHARED_ON_PURPOSE and "%s@%s" % (name, k) not in SHARED_ON_PURPOSE]
        (failed if bad else allowed).append((name, kinds, bad))
    used = {n for n, _, _ in allowed} | {n for n, _, _ in failed}
    stale = sorted(k for k in SHARED_ON_PURPOSE if k.split("@")[0] not in used
                   or ("@" in k and k.split("@")[1] not in dict(rows).get(k.split("@")[0], {})))
    print("Kanto run state shared with Johto/Hoenn: %d names, %d allowed (SHARED_ON_PURPOSE), %d new"
          % (len(rows), len(allowed), len(failed)))
    for name, kinds, bad in failed:
        print("\nNEW %s (%s)" % (name, state[name]))
        for k in bad:
            places = kinds[k]
            print("  %s: %s" % (k, "; ".join(places[:6]) + (" ... +%d" % (len(places) - 6) if len(places) > 6 else "")))
        if c_refs.get(name):
            print("  C: " + " ".join(sorted(c_refs[name])))
    if allowed:
        print("\nallowed:")
        for name, kinds, _ in allowed:
            reason = SHARED_ON_PURPOSE.get(name) or "; ".join(
                SHARED_ON_PURPOSE["%s@%s" % (name, k)] for k in kinds if "%s@%s" % (name, k) in SHARED_ON_PURPOSE)
            print("  %s [%s]: %s" % (name, ",".join(sorted(kinds)), reason))
    if stale:
        print("\nSHARED_ON_PURPOSE entries without a shared use: " + ", ".join(stale))
    return 1 if failed else 0


# ---------------------------------------------------------------------------

def summary(run):
    sets = sum(1 for v in run.flags.values() if v)
    print("flags set %d, clear %d, vars %d, trainers %d + rival %d, bag entries %d, box %d, seen only %d, money %d"
          % (sets, len(run.flags) - sets, len(run.vars), len(run.trainers), len(run.rival_by_starter[0]),
             len(run.bag), len(run.box), len(run.seen_only), run.money))
    print("Kanto maps %d, reached labels %d; Gen-1 family species not obtainable in Kanto: %s"
          % (len(run.maps.kanto), len(run.labels), ", ".join(run.not_obtainable) or "none"))
    for w in run.warnings:
        print("warning: " + w, file=sys.stderr)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--check", action="store_true", help="exit 1 if the header is stale")
    ap.add_argument("--overlap", action="store_true", help="report flags/vars shared with Johto or Hoenn")
    args = ap.parse_args()
    run = KantoRun()
    text = render(run)
    path = os.path.join(REPO, HEADER)
    if args.overlap:
        sys.exit(overlap(run))
    if args.check:
        try:
            with open(path, encoding="utf-8") as f:
                old = f.read()
        except OSError:
            old = ""
        if old != text:
            sys.stdout.writelines(difflib.unified_diff(old.splitlines(True), text.splitlines(True),
                                                       HEADER, HEADER + " (regenerated)"))
            print("%s is stale: run python3 tools/make_kanto_complete.py" % HEADER)
            sys.exit(1)
        print("%s is up to date" % HEADER)
        return
    with open(path, "w", encoding="utf-8") as f:
        f.write(text)
    summary(run)
    print("wrote " + HEADER)


if __name__ == "__main__":
    main()
