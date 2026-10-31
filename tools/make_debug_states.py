#!/usr/bin/env python3
"""Generates the debug menu's test states (src/debug.c).

State A, src/data/debug_kanto_complete.h ("Johto Test"): Kanto complete,
right after the first Kanto Hall of Fame. Every Kanto trainer beaten, every
item, TM and HM found or received, every event done. Johto and Hoenn are
not unlocked.

Pokemon: every stage of the region's lines (babies and later
evolutions included) seen and caught in the Pokedex; party and PC hold the
final stages of the lines (every branch) once, levels by LEVEL RULES below.

Sources (all in the repository):
  - the active maps (map.json and layout with game_version "hns"): the FRLG
    maps (*_Frlg) minus EXCLUDED_MAPS;
  - every script label these maps reach (data/event_scripts.s and its
    includes, #if and .if resolved for the jade build), minus the cut labels
    of the state: flags, vars, trainers, items, gifts, trades, static
    battles, legendaries, and the flags and vars the specials they call
    write in C;
  - item balls and hidden items of these maps;
  - new_game.inc's new game items and src/new_game.c's start money;
  - wild_encounters.json: the FireRed and _Night tables of these maps;
  - trainers_frlg.party and gTrainerClasses for the prize money;
  - gSpeciesInfo of the preprocessed src/pokemon.c for the evolutions,
    include/constants/pokedex.h and src/region_rule_oj.c (through
    tools/check_regions.py) for the species' regions;
  - src/legendaries_oj.c for the caught flags of one-time encounters.
Values the scripts leave open come from the configuration below.

LEVEL RULES of the PC, the owner's (2026-10-31):
  - level evolution: the evolution level (Pidgeot 36);
  - other evolution (stone, trade, friendship, item, move, place): the
    pre-evolution's level + 2;
  - single stage or legendary: its catch level in this game.
The generator's reading of them:
  - catch level, also of a first stage below a later one: the highest
    level in Kanto's wild tables, else the level of the gift or static
    battle;
  - a baby that only hatches from an egg does not count as a
    pre-evolution when the next stage can be caught.

Usage (needs arm-none-eabi-cpp, a host C compiler, cc or $CC, and the
generated src/data/pokemon/teachable_learnsets.h of a build):
  python3 tools/make_debug_states.py            # writes the header
  python3 tools/make_debug_states.py --check    # exit 1 if the header is stale or a
                                                # flag or var of the region is
                                                # neither in the state nor in UNTOUCHED
  python3 tools/make_debug_states.py --overlap  # flags/vars of state A that Johto or
                                                # Hoenn share, exit 1 on new ones
  python3 tools/make_debug_states.py --levels   # how each PC level was derived
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

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import check_regions  # noqa: E402
import oj_world  # noqa: E402

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HEADER = "src/data/debug_kanto_complete.h"
DEFINES = ["-DPOKEMON_HNS", "-DMODERN=1", "-DTESTING=0"]
ARM_CPP = ["arm-none-eabi-cpp", "-iquote", "include", "-Wno-trigraphs", "-std=gnu17"] + DEFINES
MAX_MONEY = 9999999
PC_SIZE = 14 * 30


# ---------------------------------------------------------------------------
# Configuration, state A: right after the first Kanto Hall of Fame

# Party right after the Kanto league. Starter index: VAR_STARTER_MON
# (0 Bulbasaur, 1 Squirtle, 2 Charmander).
KANTO_COMPLETE_STARTER = 2
KANTO_COMPLETE_PARTY_STARTER_FINAL = ["SPECIES_VENUSAUR", "SPECIES_BLASTOISE", "SPECIES_CHARIZARD"]
# Levels of an average player after the champion (Gen 5 experience, D-011).
KANTO_COMPLETE_PARTY_STARTER_LEVEL = 49
KANTO_COMPLETE_PARTY = [
    ("SPECIES_PIDGEOT", 43),
    ("SPECIES_RAICHU", 44),
    ("SPECIES_NIDOKING", 43),
    ("SPECIES_GYARADOS", 42),
    ("SPECIES_SNORLAX", 42),
]

# Active FRLG maps a run up to the first Hall of Fame never enters: post-title
# content, link rooms, unused houses.
KANTO_POST_TITLE_MAPS = {"CeruleanCave_1F_Frlg", "CeruleanCave_2F_Frlg", "CeruleanCave_B1F_Frlg"}
KANTO_NEVER_MAPS = {
    "BattleColosseum_2P_Frlg", "BattleColosseum_4P_Frlg", "RecordCorner_Frlg",
    "TradeCenter_Frlg", "UnionRoom_Frlg",
    "Route19_UnusedHouse_Frlg", "Route6_UnusedHouse_Frlg", "SaffronCity_Connection_Frlg",
}
EXCLUDED_MAPS = KANTO_POST_TITLE_MAPS | KANTO_NEVER_MAPS

# Script labels the walk does not enter: content after the Kanto title,
# trips to Johto, Hoenn and the Sevii Islands, rematches.
CUT_LABELS_POST_TITLE = {
    # Vermilion port: ships after the title.
    "VermilionPortFrlg_EventScript_Sailor_AfterKanto",
    "VermilionPortFrlg_EventScript_FirstTripFromOlivine",
    "VermilionPortFrlg_EventScript_ShowSSAqua",
    # Janina and Blue as gym leaders after the league change.
    "FuchsiaCity_Gym_EventScript_SetJanineLeader",
    "FuchsiaCity_Gym_EventScript_JanineLeader",
    "FuchsiaCity_Gym_EventScript_JanineRematch",
    "FuchsiaCity_Gym_EventScript_JanineGiveTM",
    "ViridianCity_Gym_EventScript_BlueLeader",
    "ViridianCity_Gym_EventScript_BlueRematch",
    # Oak after the title: National Dex scene, GS Ball handover.
    "PalletTown_ProfessorOaksLab_EventScript_TryStartNationalDexScene",
    "PalletTown_ProfessorOaksLab_EventScript_GsBallReminder",
    "PalletTown_ProfessorOaksLab_EventScript_GiveGsBall",
    "PokedexRating_EventScript_DexComplete",
}
CUT_LABELS_ALWAYS = {
    # Ships to Hoenn and the Sevii Islands.
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
    # Troy hands over the Hoenn Ticket after the first Johto title (D-047).
    "PalletTown_ProfessorOaksLab_EventScript_TroyScene",
    "PalletTown_ProfessorOaksLab_EventScript_Troy",
    # Elite Four rematches after the title.
    "PokemonLeague_AgathasRoom_EventScript_Rematch",
    "PokemonLeague_BrunosRoom_EventScript_Rematch",
    "PokemonLeague_LancesRoom_EventScript_Rematch",
    "PokemonLeague_LoreleisRoom_EventScript_Rematch",
    "PokemonLeague_ChampionsRoom_EventScript_Rematch",
}
CUT_LABELS = CUT_LABELS_POST_TITLE | CUT_LABELS_ALWAYS
# Label prefixes cut the same way: link features, Johto gyms, Hoenn arrival,
# Sevii Islands.
CUT_PREFIXES = (
    "CableClub_", "EventScript_CableClub", "JohtoGym_EventScript_", "MysteryEventClub_",
    "EventScript_GaveProfile", "EventScript_GaveSpecialProfile", "Common_EventScript_Hoenn",
    "OneIsland_", "Seagallop", "EventScript_Seagallop",
)

# Flags the scripts write that are not part of the saved state: name -> reason.
DROP_FLAGS = {
    "FLAG_SYS_USE_STRENGTH": "cleared on every map load",
    "FLAG_SAFE_FOLLOWER_MOVEMENT": "follower runtime flag",
    "FLAG_SYS_CTRL_OBJ_DELETE": "set and cleared around static battles",
    "FLAG_TALKED_TO_TEA_LADY_AFTER_HOF": "dialogue after the title",
    "FLAG_SHOWN_AURORA_TICKET": "event ticket",
    "FLAG_SHOWN_MYSTIC_TICKET": "event ticket",
    "FLAG_NURSE_UNION_ROOM_REMINDER": "link feature",
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

# Flags and vars src/debug.c or the debug script set (Hall of Fame, clock,
# Pokedex, starter): never emitted. Name -> where.
SET_BY_DEBUG_C = {
    "FLAG_SYS_GAME_CLEAR": "debug.c, Hall of Fame",
    "FLAG_SYS_RIBBON_GET": "debug.c, Hall of Fame",
    "FLAG_SYS_NATIONAL_DEX": "EnableNationalPokedex in debug.c",
    "FLAG_SYS_CLOCK_SET": "RtcInitLocalTimeOffset in debug.c",
    "VAR_NATIONAL_DEX": "EnableNationalPokedex in debug.c",
    "VAR_STARTER_MON": "debug.c, KANTO_COMPLETE_STARTER",
}

# Flags and vars the region's scripts or specials write that the state leaves
# at their new game value on purpose: name -> reason.
UNTOUCHED = {
    "FLAG_HIDE_OAKS_LAB_TROY": "Troy waits in Oak's lab only after the first Johto title; "
                               "the lab sets it on every visit (D-047)",
    "VAR_HOENN_TICKET_STATE": "0 until the first Johto title (D-047)",
    # C writes of specials the scripts call.
    "FLAG_HIDE_FANCLUB_BOY": "Emerald's fan club (Lilycove), not the jade build's Script_UpdateTrainerFanClubGameClear",
    "FLAG_HIDE_FANCLUB_LADY": "Emerald's fan club (Lilycove), not the jade build's Script_UpdateTrainerFanClubGameClear",
    "FLAG_HIDE_FANCLUB_LITTLE_BOY": "Emerald's fan club (Lilycove), not the jade build's "
                                    "Script_UpdateTrainerFanClubGameClear",
    "FLAG_HIDE_FANCLUB_OLD_LADY": "Emerald's fan club (Lilycove), not the jade build's Script_UpdateTrainerFanClubGameClear",
    "FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER": "Emerald's fan club (Lilycove), not the jade build's "
                                               "Script_UpdateTrainerFanClubGameClear",
    "VAR_LILYCOVE_FAN_CLUB_STATE": "Emerald's fan club (Lilycove), not the jade build's "
                                   "Script_UpdateTrainerFanClubGameClear",
    "VAR_RUSTURF_TUNNEL_STATE": "Emerald's Rusturf Tunnel part of the same special",
    "FLAG_HIDE_MAP_NAME_POPUP": "credits scene state",
    "FLAG_SHOWN_BOX_WAS_FULL_MESSAGE": "message state of a full PC box",
    "FLAG_SYS_SAFARI_MODE": "set and cleared around a Safari Zone visit",
    "VAR_DAILY_PICKED_BERRIES": "daily counter",
    "VAR_DAILY_PLANTED_BERRIES": "daily counter",
    "VAR_DAILY_WILDS": "daily counter",
    "VAR_TRAINER_CARD_MON_ICON_1": "trainer card photo, rebuilt from the party",
    "VAR_TRAINER_CARD_MON_ICON_2": "trainer card photo, rebuilt from the party",
    "VAR_TRAINER_CARD_MON_ICON_3": "trainer card photo, rebuilt from the party",
    "VAR_TRAINER_CARD_MON_ICON_4": "trainer card photo, rebuilt from the party",
    "VAR_TRAINER_CARD_MON_ICON_5": "trainer card photo, rebuilt from the party",
    "VAR_TRAINER_CARD_MON_ICON_6": "trainer card photo, rebuilt from the party",
    "VAR_TRAINER_CARD_MON_ICON_TINT_IDX": "trainer card photo, rebuilt from the party",
}

# Writers in C the effect scan of the specials does not see: name -> function.
C_WRITERS = {
    "FLAG_HIDE_SAFFRON_FAN_CLUB_BLACKBELT": "Script_UpdateTrainerFanClubGameClear (src/trainer_fan_club.c)",
    "FLAG_HIDE_SAFFRON_FAN_CLUB_ROCKER": "Script_UpdateTrainerFanClubGameClear (src/trainer_fan_club.c)",
    "FLAG_HIDE_SAFFRON_FAN_CLUB_WOMAN": "Script_UpdateTrainerFanClubGameClear (src/trainer_fan_club.c)",
    "FLAG_HIDE_SAFFRON_FAN_CLUB_BEAUTY": "Script_UpdateTrainerFanClubGameClear (src/trainer_fan_club.c)",
    "VAR_LEGENDARY_FLEE_KANTO": "RecordLegendaryBattleOutcome, UpdateLegendaryFleeCooldowns (src/legendaries_oj.c)",
}

# Flags reset on every day change, never part of the state.
DAILY_FLAG_RE = re.compile(r"^FLAG_DAILY_\w+$")

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

# Level of a species Kanto gives only by trade (the trade keeps the level of
# the Pokemon given away).
KANTO_TRADE_LEVEL = 20

# Trainer flags the run never sets: rematch teams after the title.
TRAINER_SKIP_RE = re.compile(r"^TRAINER_(ELITE_FOUR_\w+_2|CHAMPION_REMATCH_\w+)$")
# Rival battles, one set per player starter.
KANTO_RIVALS = {
    "var": "VAR_STARTER_MON",
    "re": re.compile(r"^TRAINER_(RIVAL_\w+|CHAMPION_FIRST)_(?P<starter>BULBASAUR|CHARMANDER|SQUIRTLE)$"),
    "names": ["Bulbasaur", "Squirtle", "Charmander"],   # by VAR_STARTER_MON
    "chosen": KANTO_COMPLETE_STARTER,
}

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
        sys.exit("make_debug_states.py needs a host C compiler (cc/gcc/clang or $CC).")
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


def map_dir_of(path):
    """Map folder of a script file under data/maps, else None."""
    return path.split("/")[2] if path.startswith("data/maps/") else None


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
        self.by_dir = {d["_dir"]: d for d in self.all.values()}
        self.sections = oj_world.MapSections()
        self.kanto = sorted((d for d in self.all.values()
                             if d["_dir"].endswith("_Frlg") and d["_dir"] not in EXCLUDED_MAPS),
                            key=lambda d: d["_dir"])
        self.kanto_all = sorted((d for d in self.all.values()
                                 if d["_dir"].endswith("_Frlg") and d["_dir"] not in KANTO_NEVER_MAPS),
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
        sys.exit("make_debug_states.py needs %s (the build's preprocessor)." % ARM_CPP[0])
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


def load_item_pockets(cond):
    """Item -> pocket (POCKET_*) of this build (src/data/items.h)."""
    pockets, cur = {}, None
    for _, line in cond.lines("src/data/items.h"):
        m = re.match(r"\s*\[(ITEM_\w+)\]\s*=", line)
        if m:
            cur = m.group(1)
            continue
        pm = re.search(r"\.pocket\s*=\s*(POCKET_\w+)", line)
        if cur and pm:
            pockets.setdefault(cur, pm.group(1))
    return pockets


def load_item_aliases(cond):
    """Item alias -> item: ITEM_X = ITEM_Y lines of constants/items.h and the
    TM and HM names (ITEM_TM_<MOVE> -> ITEM_TMnn) of the jade build."""
    aliases = dict(re.findall(r"^\s*(ITEM_\w+) = (ITEM_\w+),", read("include/constants/items.h"), re.M))
    # constants/tms_hms.h: the IS_HNS lists come first, the others after #else.
    lists = collections.defaultdict(list)
    for m in re.finditer(r"#define FOREACH_(TM|HM)\(F\)((?:[^\n]*\\\n)*[^\n]*)", read("include/constants/tms_hms.h")):
        lists[m.group(1)].append(re.findall(r"\bF\((\w+)\)", m.group(2)))
    branch = 0 if cond.eval("IS_HNS") else -1
    for kind, versions in lists.items():
        for n, move in enumerate(versions[branch], 1):
            aliases["ITEM_%s_%s" % (kind, move)] = "ITEM_%s%02d" % (kind, n)
    return aliases


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


def load_legendaries():
    """LEGENDARY_ id -> {caught, done, species, level} of src/legendaries_oj.c."""
    out = {}
    text = read("src/legendaries_oj.c")
    for m in re.finditer(r"\[(LEGENDARY_\w+)\]\s*=\s*STATIC_LEGENDARY\((\w+),\s*(\w+)", text):
        out[m.group(1)] = {"caught": m.group(2), "done": m.group(3) if m.group(3) != "0" else None,
                           "species": None, "level": None}
    for m in re.finditer(r"\[(LEGENDARY_\w+)\]\s*=\s*ROAMING_LEGENDARY\((\w+),\s*(SPECIES_\w+),\s*(\d+),\s*(\w+)",
                         text):
        out[m.group(1)] = {"caught": m.group(2), "done": None, "species": m.group(3), "level": int(m.group(4)),
                           "release": m.group(5)}
    return out


def load_fly_flags():
    """Flags of the combined Johto-Kanto fly map (sMapFlyDestinations, src/region_map.c)."""
    text = read("src/region_map.c")
    return sorted(set(re.findall(r"\.regionMapType\s*=\s*REGION_MAP_JK,\s*\.mapsec\s*=\s*\w+,\s*\.flag\s*=\s*(FLAG_\w+)",
                                 text)))


# ---------------------------------------------------------------------------
# A run: everything the state's maps reach

TRAINER_BATTLES = {
    "trainerbattle_single": [0], "trainerbattle_double": [0], "trainerbattle_no_intro": [0],
    "trainerbattle_earlyrival": [0], "trainerbattle_rematch": [0],
    "trainerbattle_rematch_double": [0], "trainerbattle_two_trainers": [0, 2],
}


class World:
    """Data both states share."""

    def __init__(self):
        self.cond = Conditions()
        self.scripts = Scripts(self.cond)
        self.maps = Maps()
        self.item_aliases = load_item_aliases(self.cond)
        self.cfuncs = oj_world.CFunctions()
        self.legendaries = load_legendaries()
        self.pockets = load_item_pockets(self.cond)
        self.key_items = {i for i, p in self.pockets.items() if p == "POCKET_KEY_ITEMS"}
        self.class_money = load_class_money()
        self.parties = {}
        for path in ("src/data/trainers_frlg.party", "src/data/trainers_hns.party"):
            for t, p in load_parties(path).items():
                self.parties.setdefault(t, p)

    def item(self, name):
        return self.item_aliases.get(name, name)


class Run:
    """The state of a run through the configured maps and labels."""

    def __init__(self, world, cfg):
        self.w = world
        self.cfg = cfg
        self.scripts = world.scripts
        self.maps = cfg["maps"]
        self.warnings = []
        self.labels = set()
        for d in self.maps:
            self.labels |= self.scripts.walk(Maps.entries(d), cfg["cut"])
        self._collect()
        self._flags()
        self._vars()
        self._trainers()
        self._items()

    def item(self, name):
        return self.w.item(name)

    def cmds(self):
        for name in sorted(self.labels):
            for n, cmd, args in self.scripts.labels[name]["cmds"]:
                yield name, cmd, args

    def _collect(self):
        self.flag_writes = collections.defaultdict(set)
        self.var_writes = collections.defaultdict(set)
        self.c_writes = collections.defaultdict(set)        # name -> specials that write it in C
        self.trainers_fought = set()
        self.trainers_cleared = set()
        self.var_setvalues = collections.defaultdict(set)   # VAR -> SPECIES_/ITEM_ values
        self.file_var_species = collections.defaultdict(set)  # (file, VAR) -> SPECIES_ values
        self.legendaries = set()
        self.statics = set()
        self.gift_species = set()
        self.trade_ids = collections.defaultdict(set)       # INGAME_TRADE_ -> map folders
        self.mon_sources = []                               # (kind, species or var, level, file)
        self.item_gifts = collections.defaultdict(dict)     # item -> label -> quantity
        self.item_removed = collections.defaultdict(int)
        self.item_var_gifts = set()
        self.shops = set()
        self.breeding = False
        objs = {d["_dir"]: d.get("object_events") or [] for d in self.maps}

        def object_flag(mdir, lid):
            for i, o in enumerate(objs.get(mdir, [])):
                if o.get("local_id") == lid or str(i + 1) == lid:
                    return o.get("flag")
            return None
        init_labels = self.cfg.get("init_labels", set())
        init_flags = collections.defaultdict(set)
        init_vars = collections.defaultdict(set)
        for name, cmd, a in self.cmds():
            path = self.scripts.labels[name]["file"]
            mdir = map_dir_of(path)
            flag_writes = init_flags if name in init_labels else self.flag_writes
            var_writes = init_vars if name in init_labels else self.var_writes
            if cmd in ("setflag", "setworldmapflag"):
                flag_writes[a[0]].add(1)
            elif cmd == "clearflag":
                flag_writes[a[0]].add(0)
            elif cmd == "removeobject" and a and a[0] != "VAR_LAST_TALKED":
                fl = object_flag(mdir, a[0]) if mdir else None
                if fl and fl != "0":
                    flag_writes[fl].add(1)
            elif cmd == "setvar":
                var_writes[a[0]].add(a[1])
                if re.match(r"(SPECIES|ITEM)_", a[1]):
                    self.var_setvalues[a[0]].add(a[1])
                    if a[1].startswith("SPECIES_"):
                        self.file_var_species[(path, a[0])].add(a[1])
                elif a[1].startswith("INGAME_TRADE_"):
                    self.trade_ids[a[1]].add(mdir)
                elif a[0] == "VAR_0x8004" and a[1].startswith("LEGENDARY_"):
                    self.legendaries.add(a[1])
            elif cmd in ("addvar", "subvar", "copyvar"):
                var_writes[a[0]].add(cmd + " " + a[1])
            elif cmd == "ingame_trade" and a:
                self.trade_ids[a[0]].add(mdir)
            elif cmd == "settrainerflag":
                self.trainers_fought.add(a[0])
            elif cmd == "cleartrainerflag":
                self.trainers_cleared.add(a[0])
            elif cmd in TRAINER_BATTLES:
                for i in TRAINER_BATTLES[cmd]:
                    # gas macro arguments may also be separated by spaces.
                    self.trainers_fought.add(a[i].split()[0])
            elif cmd in ("giveitem", "additem", "giveitem_norandom") and a:
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
            elif cmd == "givemon" and a:
                self.gift_species.add(a[0])   # a species or a var, resolved below
                self.mon_sources.append(("gift", a[0], int(a[1]) if len(a) > 1 and a[1].isdigit() else None, path))
            elif cmd == "giveegg" and a:
                self.gift_species.add(a[0])
                self.mon_sources.append(("egg", a[0], None, path))
            elif cmd in ("setwildbattle", "setwildbattleshiny", "seteventmon") and a:
                self.statics.add(a[0])
                self.mon_sources.append(("static", a[0], int(a[1]) if len(a) > 1 and a[1].isdigit() else None, path))
            elif cmd == "pokemart" and a:
                self.shops.add(a[0])
            elif cmd in ("special", "specialvar", "callnative") and a:
                if a[-1] == "GiveEggFromDaycare":
                    self.breeding = True
                eff = self.w.cfuncs.effects(a[-1], depth=1)
                for n in eff["set"] | eff["clear"] | eff["vars"]:
                    self.c_writes[n].add(a[-1])
        for n, values in init_flags.items():
            if n not in self.flag_writes:
                self.flag_writes[n] = values
        for n, values in init_vars.items():
            if n not in self.var_writes:
                self.var_writes[n] = values
        resolved = set()
        for s in self.gift_species:
            if s.startswith("SPECIES_"):
                resolved.add(s)
            else:
                resolved |= {v for v in self.var_setvalues.get(s, ()) if v.startswith("SPECIES_")}
        self.gift_species = resolved
        sources = []
        for kind, s, level, path in self.mon_sources:
            names = [s] if s.startswith("SPECIES_") else sorted(self.file_var_species.get((path, s), ()))
            for n in names:
                sources.append((kind, n, level, path))
        self.mon_sources = sources

    def _flags(self):
        cfg = self.cfg
        flags = {}
        self.unresolved_flags = []
        for name, values in self.flag_writes.items():
            if name.startswith("FLAG_TEMP_") or DAILY_FLAG_RE.match(name) or name in cfg["drop_flags"] \
                    or name in cfg["set_by_c"]:
                continue
            if name in cfg["manual_flags"] or name in cfg["untouched"]:
                continue
            if len(values) == 1:
                flags[name] = next(iter(values))
            else:
                self.unresolved_flags.append(name)
                if name not in cfg["untouched"]:
                    self.warnings.append("%s is set and cleared by the scripts and has no manual flag entry; "
                                         "left at its new game value" % name)
        for name, value in cfg["manual_flags"].items():
            flags[name] = value
        # Roamers the run releases.
        for lid, leg in self.w.legendaries.items():
            if leg.get("release") and flags.get(leg["release"]) == 1:
                self.legendaries.add(lid)
        # Legendaries caught: RecordLegendaryBattleOutcome sets the caught and done flags.
        for lid in sorted(self.legendaries | set(cfg.get("extra_legendaries", ()))):
            leg = self.w.legendaries.get(lid)
            if leg:
                flags[leg["caught"]] = 1
                if leg["done"]:
                    flags[leg["done"]] = 1
        # Item balls and hidden items of the maps.
        for d in self.maps:
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
        cfg = self.cfg
        out = {}
        self.unresolved_vars = []
        for name, values in self.var_writes.items():
            if SCRATCH_VAR_RE.match(name) or name in cfg["set_by_c"] or name in cfg["manual_vars"] \
                    or name in cfg["untouched"]:
                continue
            if len(values) == 1 and not next(iter(values)).startswith(("addvar", "subvar", "copyvar")):
                out[name] = next(iter(values))
            else:
                self.unresolved_vars.append(name)
                if name not in cfg["untouched"]:
                    self.warnings.append("%s is written with %s by the scripts and has no manual var entry; "
                                         "left at its new game value" % (name, ", ".join(sorted(values))))
        for name, value in cfg["manual_vars"].items():
            out[name] = str(value)
        self.vars = out

    def _trainers(self):
        parties = self.w.parties
        class_money = self.w.class_money
        cfg = self.cfg
        fought = {t for t in self.trainers_fought if t.startswith("TRAINER_") and not cfg["trainer_skip"].match(t)}
        missing = sorted(t for t in fought if t not in parties)
        if missing:
            self.warnings.append("trainers without a party: " + ", ".join(missing))

        def is_rival(t):
            return any(r["re"].match(t) for r in cfg["rivals"])
        self.trainers = sorted(t for t in fought if not is_rival(t) and t not in self.trainers_cleared)
        money = sum(prize_money(parties.get(t), class_money) for t in fought if not is_rival(t))
        self.rivals = []
        for rcfg in cfg["rivals"]:
            # Starter var -> the rival's starter, from the branches on the var.
            rival_of = collections.defaultdict(set)
            for name, cmd, a in self.cmds():
                if cmd.endswith("_if_eq") and len(a) == 3 and a[0] == rcfg["var"] and a[1].isdigit():
                    for lab in self.scripts.walk([a[2]], cfg["cut"]):
                        for _, c, args in self.scripts.labels[lab]["cmds"]:
                            if c in TRAINER_BATTLES:
                                m = rcfg["re"].match(args[0])
                                if m:
                                    rival_of[int(a[1])].add(m.group("starter"))
            by_starter, rival_money = [], []
            for starter in range(len(rcfg["names"])):
                suffixes = rival_of.get(starter, set())
                if len(suffixes) != 1:
                    sys.exit("cannot tell the rival's starter for %s %d: %s" % (rcfg["var"], starter, sorted(suffixes)))
                suffix = next(iter(suffixes))
                battles = sorted(t for t in fought if rcfg["re"].match(t)
                                 and rcfg["re"].match(t).group("starter") == suffix)
                by_starter.append([t for t in battles if t not in self.trainers_cleared])
                rival_money.append(sum(prize_money(parties.get(t), class_money) for t in battles))
            sizes = {len(r) for r in by_starter}
            if len(sizes) != 1:
                sys.exit("the rival paths of %s have different lengths: %s" % (rcfg["var"], by_starter))
            money += rival_money[rcfg["chosen"]]
            self.rivals.append({"cfg": rcfg, "by_starter": by_starter})
        if cfg.get("start_money"):
            start = re.search(r"SetMoney\(&gSaveBlock1Ptr->money,\s*(\d+)\)", read("src/new_game.c"))
            money += int(start.group(1))
        self.money = money
        # Species seen in trainer battles.
        self.seen_common = {s for t in fought if not is_rival(t) for s, _ in parties.get(t, {"mons": []})["mons"]}
        self.seen_rival = []
        for r in self.rivals:
            self.seen_rival.append([{s for t in path for s, _ in parties.get(t, {"mons": []})["mons"]}
                                    for path in r["by_starter"]])

    def _items(self):
        bag = collections.Counter()
        if self.cfg.get("new_game_items"):
            # New game items (removed again by ClearBag).
            for label in ("EventScript_ResetAllMapFlagsHnS", "EventScript_ResetAllMapFlagsFrlg"):
                if label in self.scripts.labels:
                    for _, cmd, a in self.scripts.run_straight(label):
                        if cmd == "additem" and a[0].startswith("ITEM_"):
                            bag[self.item(a[0])] += int(a[1]) if len(a) > 1 and a[1].isdigit() else 1
        for d in self.maps:
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
        for item, q in self.cfg.get("extra_items", {}).items():
            bag[self.item(item)] += q
        for item, q in self.item_removed.items():
            bag[item] -= q
        # One of each key item and HM: gifts in exclusive branches (e.g. the
        # Route 15 aide's Exp. Share or Small Exp. Share) are all counted above.
        for item in list(bag):
            if bag[item] > 1 and (item in self.w.key_items or item.startswith("ITEM_HM")):
                bag[item] = 1
        for item in self.cfg.get("skip_items", {}):
            bag.pop(item, None)
        self.bag = {i: q for i, q in sorted(bag.items()) if q > 0}

    def written(self):
        """Every flag and var the run's scripts and specials write."""
        return set(self.flag_writes) | set(self.var_writes) | set(self.c_writes)

    def coverage(self):
        """Problems: flags and vars the run writes that are neither in the state
        nor listed with a reason, and list entries nothing writes."""
        cfg = self.cfg
        state = set(self.flags) | set(self.vars)
        problems = []
        listed = set(cfg["drop_flags"]) | set(cfg["untouched"]) | set(cfg["set_by_c"])
        for name in sorted(self.written()):
            if name.startswith("FLAG_TEMP_") or DAILY_FLAG_RE.match(name) or SCRATCH_VAR_RE.match(name):
                continue
            if name in state or name in listed:
                continue
            if name in self.unresolved_flags or name in self.unresolved_vars:
                values = self.flag_writes.get(name) or self.var_writes.get(name)
                problems.append("%s: written with %s, needs a manual value or an UNTOUCHED reason"
                                % (name, ", ".join(sorted(str(v) for v in values))))
            else:
                problems.append("%s: written in C by %s, needs a manual value or an UNTOUCHED reason"
                                % (name, ", ".join(sorted(self.c_writes.get(name, ())))))
        written = self.written() | set(C_WRITERS)
        for table in ("manual_flags", "manual_vars", "drop_flags", "untouched"):
            for name in sorted(cfg[table]):
                if name not in written:
                    problems.append("%s: listed in %s, but nothing in the run writes it" % (name, table))
        return problems


# ---------------------------------------------------------------------------
# Species: Pokedex, PC and levels

class Species:
    def __init__(self):
        self.info = load_species()
        natdex = load_natdex_order()
        self.national = {s: natdex.get(d["natdex"], 0) for s, d in self.info.items()}
        self.later = check_regions.later_species_regions(check_regions.national_dex_numbers())
        self.base = {}   # national number -> the species with the lowest species number
        for s, d in sorted(self.info.items(), key=lambda x: x[1]["num"]):
            n = self.national[s]
            if n and n not in self.base:
                self.base[n] = s
        self.bases = set(self.base.values())
        self.evos = {s: [e for e in self.info[s]["evos"] if e["target"] in self.bases] for s in self.bases}
        self.pre = {}
        for s in sorted(self.bases, key=self.num):
            for e in self.evos[s]:
                self.pre.setdefault(e["target"], s)
        # Lines: species connected by evolutions.
        parent = {s: s for s in self.bases}

        def find(s):
            while parent[s] != s:
                parent[s] = parent[parent[s]]
                s = parent[s]
            return s
        for t, p in self.pre.items():
            parent[find(t)] = find(p)
        self.line = {s: find(s) for s in self.bases}

    def num(self, s):
        return self.info[s]["num"]

    def region(self, s):
        n = self.national[s]
        if n <= 151:
            return "Kanto"
        if n <= 251:
            return "Johto"
        if n <= 386:
            return "Hoenn"
        return self.later.get(n, "Hoenn")

    def canonical(self, s):
        """The base species of a species or form, by national number."""
        return self.base.get(self.national.get(s, 0))

    def dex_set(self, regions):
        """Every stage of the lines with a species of these regions."""
        lines = {self.line[s] for s in self.bases if self.region(s) in regions}
        return {s for s in self.bases if self.line[s] in lines}

    def finals(self, members):
        return {s for s in members if not any(e["target"] in members for e in self.evos[s])}

    def evo_step(self, pre, s):
        """('level', N) for a level evolution, else ('other', None)."""
        levels = [int(e["param"]) for e in self.evos[pre] if e["target"] == s
                  and e["method"] in ("EVO_LEVEL", "EVO_LEVEL_BATTLE_ONLY") and e["param"].isdigit()
                  and int(e["param"]) > 0]
        return ("level", min(levels)) if levels else ("other", None)

    def describe(self, pre, s):
        es = [e for e in self.evos[pre] if e["target"] == s]
        return es[0]["method"].replace("EVO_", "").lower() if es else "?"


class Levels:
    """PC levels of a state (LEVEL RULES in the docstring)."""

    def __init__(self, species, members, catch, fixed=None):
        self.sp = species
        self.members = members           # species the pre-evolution search sees
        self.catch = catch               # species -> catch level in the region
        self.fixed = fixed or {}         # species -> level kept from state A
        self.memo = {}
        self.how = {}

    def _pre(self, s):
        p = self.sp.pre.get(s)
        return p if p in self.members else None

    def _breed_only(self, s):
        if s in self.fixed or s in self.catch:
            return False
        p = self._pre(s)
        return p is None or self._breed_only(p)

    def level(self, s):
        if s in self.memo:
            return self.memo[s]
        if s in self.fixed:
            lv, how = self.fixed[s], "as in state A"
        else:
            p = self._pre(s)
            if p is None or (self._breed_only(p) and s in self.catch):
                lv = self.catch.get(s)
                how = "caught" if lv is not None else "no source"
            else:
                kind, param = self.sp.evo_step(p, s)
                if kind == "level":
                    lv, how = param, "level evolution of %s" % p
                else:
                    base = self.level(p)
                    lv = base + 2 if base is not None else None
                    how = "%s of %s (%s) + 2" % (self.sp.describe(p, s), p, base)
        self.memo[s], self.how[s] = lv, how
        return lv


def trade_species(world, run):
    """Species the run's in-game trades give: species -> map folders."""
    out = collections.defaultdict(set)
    kept = "\n".join(l for _, l in world.cond.lines("src/data/trade.h"))
    for tid, mdirs in run.trade_ids.items():
        m = re.search(r"\[%s\]\s*=\s*\{(.*?)\n\s*\}," % tid, kept, re.S)
        if m:
            sm = re.search(r"\.species\s*=\s*(SPECIES_\w+)", m.group(1))
            if sm:
                out[sm.group(1)] |= {d for d in mdirs if d}
    return out


def kanto_catch_levels(world, runs, species):
    """Species -> catch level in Kanto: highest level in the wild tables of
    state A's maps, else the highest gift or static level of Kanto's scripts,
    else KANTO_TRADE_LEVEL for trades."""
    ids = {d["id"] for d in world.maps.kanto}
    wild = {}
    for group in load_json("src/data/wild_encounters.json")["wild_encounter_groups"]:
        if not group.get("for_maps"):
            continue
        for e in group["encounters"]:
            if e["map"] not in ids or "LeafGreen" in e["base_label"]:
                continue
            for key in ("land_mons", "water_mons", "rock_smash_mons", "fishing_mons"):
                for m in (e.get(key) or {}).get("mons", []):
                    s = species.canonical(m["species"])
                    if s:
                        wild[s] = max(wild.get(s, 0), m["max_level"])
    scripted = {}
    for run in runs:
        for kind, s, level, path in run.mon_sources:
            mdir = map_dir_of(path)
            if not mdir or not mdir.endswith("_Frlg") or (kind == "static" and s in UNCATCHABLE_STATIC):
                continue
            s = species.canonical(s)
            if s and level:
                scripted[s] = max(scripted.get(s, 0), level)
    out = {}
    for run in runs:
        for s in trade_species(world, run):
            cs = species.canonical(s)
            if cs and any(d.endswith("_Frlg") for d in trade_species(world, run)[s]):
                out[cs] = KANTO_TRADE_LEVEL
    out.update(scripted)
    out.update(wild)
    return out


# ---------------------------------------------------------------------------
# The state

def config_a(world):
    return {
        "name": "A", "maps": world.maps.kanto, "cut": is_cut,
        "drop_flags": DROP_FLAGS, "manual_flags": MANUAL_FLAGS, "manual_vars": MANUAL_VARS,
        "untouched": UNTOUCHED, "set_by_c": SET_BY_DEBUG_C,
        "trainer_skip": TRAINER_SKIP_RE, "rivals": [KANTO_RIVALS],
        "new_game_items": True, "start_money": True, "extra_items": EXTRA_ITEMS,
        # Mewtwo is in the PC (the whole Kanto Pokedex); its cave opens after the title.
        "extra_legendaries": ["LEGENDARY_MEWTWO"],
    }


class States:
    def __init__(self):
        self.world = World()
        self.sp = Species()
        self.problems = []
        self._state_a()

    def _state_a(self):
        """Kanto lines in the Pokedex, Kanto's final stages in party and PC."""
        w, sp = self.world, self.sp
        self.a = Run(w, config_a(w))
        # Gifts and static battles of Kanto after the title (Mewtwo), for levels only.
        kanto_post = Run(w, dict(config_a(w), maps=[d for d in w.maps.kanto_all if d not in w.maps.kanto], rivals=[]))
        self.kanto = {s for s in sp.bases if sp.region(s) == "Kanto"}
        self.dex_a = sp.dex_set({"Kanto"})
        self.finals_a = sp.finals(self.kanto)
        self.levels_a = Levels(sp, self.kanto, kanto_catch_levels(w, [self.a, kanto_post], sp))
        starter = KANTO_COMPLETE_PARTY_STARTER_FINAL[KANTO_COMPLETE_STARTER]
        self.party_a = [(starter, KANTO_COMPLETE_PARTY_STARTER_LEVEL)] + KANTO_COMPLETE_PARTY
        self.box_a = self._box(self.finals_a, self.party_a, self.levels_a, "A")
        self.seen_a = self._seen_only(self.a, self.dex_a, {"Kanto"})

    def _box(self, finals, party, levels, name):
        party_species = {s for s, _ in party}
        box = []
        for s in sorted(finals - party_species, key=self.sp.num):
            lv = levels.level(s)
            if lv is None:
                self.problems.append("state %s: no catch level for %s (%s)" % (name, s, levels.how[s]))
                continue
            box.append((s, max(1, min(lv, 100))))
        return box

    def _seen_only(self, run, dex, regions):
        """Species trainers show that are not in the Pokedex list, of unlocked regions."""
        seen = set(run.seen_common)
        for r, sets in zip(run.rivals, run.seen_rival):
            seen |= sets[r["cfg"]["chosen"]]
        out = set()
        for s in seen:
            c = self.sp.canonical(s)
            if c and c not in dex and self.sp.region(c) in regions:
                out.add(c)
        return sorted(out, key=self.sp.num)

    def check(self):
        """Every problem --check reports besides a stale header."""
        out = list(self.problems)
        out += self._check_a()
        return out

    @staticmethod
    def _check_mons(name, dex, finals, party, box):
        out = []
        owned = [s for s, _ in party] + [s for s, _ in box]
        dup = sorted(s for s, n in collections.Counter(owned).items() if n > 1)
        if dup:
            out.append("state %s: species twice in party and PC: %s" % (name, ", ".join(dup)))
        if set(owned) != finals:
            out.append("state %s: party and PC are not the final stages: missing %s, not final %s"
                       % (name, sorted(finals - set(owned)), sorted(set(owned) - finals)))
        if not finals <= dex:
            out.append("state %s: final stages outside the Pokedex list" % name)
        if len(box) > PC_SIZE or len(party) > 6:
            out.append("state %s: %d party and %d PC Pokemon do not fit" % (name, len(party), len(box)))
        return out

    def _check_a(self):
        out = ["state A: %s" % p for p in self.a.coverage()]
        out += self._check_mons("A", self.dex_a, self.finals_a, self.party_a, self.box_a)
        flags_a = {n for n, v in self.a.flags.items() if v}
        for f in ("FLAG_JOHTO_UNLOCKED", "FLAG_JOHTO_ARRIVAL_DONE"):
            if f in flags_a:
                out.append("state A: %s set; Johto stays locked (D-049)" % f)
        if int(self.a.vars.get("VAR_JOHTO_HANDOVER", "0"), 0) >= 3:
            out.append("state A: VAR_JOHTO_HANDOVER 3 unlocks Johto (D-049)")
        if int(self.a.vars.get("VAR_HOENN_ARRIVAL_STATE", "0"), 0) != 0:
            out.append("state A: VAR_HOENN_ARRIVAL_STATE unlocks Hoenn (D-049)")
        for f in load_fly_flags():
            if f.startswith("FLAG_WORLD_MAP_") and f not in flags_a:
                out.append("state A: fly destination %s not set" % f)
        return out

# ---------------------------------------------------------------------------
# Header

def c_array(w, decl, items):
    w(decl)
    w("{")
    for item in items:
        w("    %s," % item)
    w("};")
    w("")


def render(states):
    run = states.a
    out = []
    w = out.append
    w("// Generated by tools/make_debug_states.py - do not edit.")
    w("// State right after the first Kanto Hall of Fame for the debug menu's \"Johto Test\".")
    w("// Regenerate: python3 tools/make_debug_states.py (check: --check, shared state: --overlap).")
    w("")
    w("#define KANTO_COMPLETE_STARTER %d  // VAR_STARTER_MON: 0 Bulbasaur, 1 Squirtle, 2 Charmander"
      % KANTO_COMPLETE_STARTER)
    w("#define KANTO_COMPLETE_MONEY %d  // start money and every prize of the run" % run.money)
    w("")
    w("struct KantoCompleteMon { u16 species; u8 level; };")
    w("struct KantoCompleteVar { u16 var; u16 value; };")
    w("struct KantoCompleteItem { u16 item; u16 quantity; };")
    w("")
    c_array(w, "static const u16 sKantoCompleteFlagsSet[] =", sorted(n for n, v in run.flags.items() if v))
    c_array(w, "static const u16 sKantoCompleteFlagsClear[] =", sorted(n for n, v in run.flags.items() if not v))
    c_array(w, "static const struct KantoCompleteVar sKantoCompleteVars[] =",
            ["{ %s, %s }" % (n, v) for n, v in sorted(run.vars.items())])
    c_array(w, "static const u16 sKantoCompleteTrainers[] =", run.trainers)
    rivals = run.rivals[0]["by_starter"]
    w("// Index: VAR_STARTER_MON.")
    w("static const u16 sKantoCompleteRivalTrainers[%d][%d] =" % (len(rivals), len(rivals[0])))
    w("{")
    for i, r in enumerate(rivals):
        w("    [%d] = { %s }," % (i, ", ".join(r)))
    w("};")
    w("")
    c_array(w, "static const struct KantoCompleteItem sKantoCompleteBag[] =",
            ["{ %s, %d }" % (i, q) for i, q in run.bag.items()])
    w("// Party: the chosen starter's final stage first.")
    c_array(w, "static const struct KantoCompleteMon sKantoCompleteParty[] =",
            ["{ %s, %d }" % (s, lv) for s, lv in states.party_a])
    w("// PC: the other final stages of the Kanto lines (every branch).")
    c_array(w, "static const struct KantoCompleteMon sKantoCompleteMons[] =", ["{ %s, %d }" % m for m in states.box_a])
    w("// Pokedex, seen and caught: every stage of the Kanto lines.")
    c_array(w, "static const u16 sKantoCompleteDex[] =", sorted(states.dex_a, key=states.sp.num))
    c_array(w, "static const u16 sKantoCompleteSeenOnly[] =", states.seen_a)
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
    for d in run.w.maps.all.values():
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
    names = {n for n in run.w.cond.macros if n.startswith(("FLAG_", "VAR_"))
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

def summary(states):
    for name, run in (("A", states.a),):
        sets = sum(1 for v in run.flags.values() if v)
        print("state %s run: flags set %d, clear %d, vars %d, trainers %d, bag entries %d, money %d, maps %d, labels %d"
              % (name, sets, len(run.flags) - sets, len(run.vars), len(run.trainers), len(run.bag), run.money,
                 len(run.maps), len(run.labels)))
    print("state A: Pokedex %d, party %d, PC %d, seen only %d"
          % (len(states.dex_a), len(states.party_a), len(states.box_a), len(states.seen_a)))
    for name, run in (("A", states.a),):
        for w in run.warnings:
            print("warning (state %s): %s" % (name, w), file=sys.stderr)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--check", action="store_true",
                    help="exit 1 if the header is stale or a flag/var of the region is not covered")
    ap.add_argument("--overlap", action="store_true", help="report flags/vars of state A shared with Johto or Hoenn")
    ap.add_argument("--levels", action="store_true", help="print how each PC level was derived")
    args = ap.parse_args()
    states = States()
    if args.overlap:
        sys.exit(overlap(states.a))
    if args.levels:
        for name, box, levels in (("A", states.box_a, states.levels_a),):
            for s, lv in box:
                print("%s %-30s %3d  %s" % (name, s, lv, levels.how.get(s, "")))
        return
    texts = {HEADER: render(states)}
    if args.check:
        failed = False
        for header, text in texts.items():
            try:
                with open(os.path.join(REPO, header), encoding="utf-8") as f:
                    old = f.read()
            except OSError:
                old = ""
            if old != text:
                sys.stdout.writelines(difflib.unified_diff(old.splitlines(True), text.splitlines(True),
                                                           header, header + " (regenerated)"))
                print("%s is stale: run python3 tools/make_debug_states.py" % header)
                failed = True
            else:
                print("%s is up to date" % header)
        problems = states.check()
        for p in problems:
            print("problem: " + p)
        if problems:
            print("%d problems" % len(problems))
        sys.exit(1 if failed or problems else 0)
    for header, text in texts.items():
        with open(os.path.join(REPO, header), "w", encoding="utf-8") as f:
            f.write(text)
        print("wrote " + header)
    summary(states)
    for p in states.check():
        print("problem: " + p, file=sys.stderr)


if __name__ == "__main__":
    main()
