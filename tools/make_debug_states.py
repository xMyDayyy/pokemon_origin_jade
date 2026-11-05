#!/usr/bin/env python3
"""Generates the debug menu's test states (src/debug.c).

State A, src/data/debug_kanto_complete.h ("Johto Test"): Kanto complete,
right after the first Kanto Hall of Fame. Every Kanto trainer beaten, every
item, TM and HM found or received, every event done. Johto and Hoenn are
not unlocked.

State B, src/data/debug_johto_complete.h ("Hoenn Test"): applied on top of
state A. Kanto after its title and Johto complete as a completionist: the
Johto story and league, Red, the one-time encounters of both regions; battle
facilities untouched. Johto is unlocked, Hoenn not; Troy waits in Oak's lab
with the Hoenn Ticket (VAR_HOENN_TICKET_STATE 1).

Pokemon of both states: every stage of the region's lines (babies and later
evolutions included) seen and caught in the Pokedex; party and PC hold the
final stages of the lines (every branch) once, levels by LEVEL RULES below.

Sources (all in the repository):
  - the active maps (map.json and layout with game_version "hns"): state A
    the FRLG maps (*_Frlg) minus EXCLUDED_MAPS; state B also the
    post-title Kanto maps and the HnS maps of Johto and Johto's league;
  - every script label these maps reach (data/event_scripts.s and its
    includes, #if and .if resolved for the jade build), minus the cut labels
    of the state: flags, vars, trainers, items, gifts, trades, static
    battles, legendaries, and the flags and vars the specials they call
    write in C;
  - map pickups (objects whose script runs finditem) and hidden items of
    these maps;
  - new_game.inc's new game items and src/new_game.c's start money;
  - wild_encounters.json (Kanto: FireRed and _Night tables), the Johto
    corridors in include/config/johto_scaling.h;
  - trainers_frlg.party, trainers_hns.party and gTrainerClasses for the
    prize money;
  - gSpeciesInfo of the preprocessed src/pokemon.c for the evolutions,
    include/constants/pokedex.h and src/region_rule_oj.c (through
    tools/check_regions.py) for the species' regions;
  - src/legendaries_oj.c for the caught flags of one-time encounters;
  - the item lists of marts, the C arrays of VAR_GIFT_TABLES, C_ITEM_SOURCES
    and FACILITY_ITEMS, src/match_call.c's phone gifts and src/shop.c's badge
    mart and Battle Point shops (BP_EXCHANGES), the berry trees of
    new_game.inc and the held items of src/data/trade.h.
Values the scripts leave open come from the configuration below.

LEVEL RULES of the PC, the owner's (2026-10-31):
  - level evolution: the evolution level (Pidgeot 36);
  - other evolution (stone, trade, friendship, item, move, place): the
    pre-evolution's level + 2;
  - single stage or legendary: its catch level in this game.
The generator's reading of them (owner 2026-11-02: the states need not be
perfect):
  - catch level, also of a first stage below a later one: in Kanto the
    highest level in Kanto's wild tables, else the level of the gift or
    static battle; in Johto the top of the wild band of an average player
    where the species first appears (corridor floor + 2), else the
    gift or static level; eggs and trades of Johto the band of
    their map;
  - a baby that only hatches from an egg does not count as a
    pre-evolution when the next stage can be caught;
  - in state B the species of Kanto lines keep their level of state A,
    those of state A's party their party level.

ITEMS, the owner's (2026-11-02): everything the finished regions give.
  - every map pickup (an object whose script runs finditem) and hidden item,
    every gift; one of two gifts that exclude each other (EXCLUSIVE_GIFTS_B);
    key items and HMs once;
  - at least one of each item a run can buy or get again: mart lists (also
    the badge mart, pokemart 0) and the Premier Ball a mart adds for ten
    balls, purchases (a label that takes money or coins: prize rooms,
    vending machines, merchants), gifts through a var (the script's own
    setvar values, VAR_GIFT_TABLES, phone trainers, random picks),
    C_ITEM_SOURCES (Mom's savings), FACILITY_ITEMS (the Route 40 Trainer
    Hill's prizes and shop once the state opens it), BP_EXCHANGES (the
    Battle Point wares of the Trainer Hill's courtyard by Route 40, whose
    tents pay Battle Points before the Johto title; O-060 (a)), berry
    trees, Rock Smash finds, held items of in-game trades. Items only a
    clerk sells whose flag the state leaves untouched (a challenge option:
    Goldenrod's mints) are added only while that flag is clear.
  - the generator's reading: not counted are link-only sources
    (VAR_GIFT_SKIP), decorations, held items of wild Pokemon, Pickup, and
    the Kampfzone with its Battle Point exchange (it opens only after the
    Hoenn title);
  - a pocket keeps POCKET_RESERVE free slots for the next region; what does
    not fit goes into the PC's item storage, purchases first.

Usage (needs arm-none-eabi-cpp, a host C compiler, cc or $CC, and the
generated src/data/pokemon/teachable_learnsets.h of a build):
  python3 tools/make_debug_states.py            # writes both headers
  python3 tools/make_debug_states.py --check    # exit 1 if a header is stale or a
                                                # rule of the states fails (a flag or var
                                                # neither in the state nor in UNTOUCHED,
                                                # a pickup not collected, an item source
                                                # not resolved, a full pocket, ...)
  python3 tools/make_debug_states.py --overlap  # flags/vars of state A that Johto or
                                                # Hoenn share, exit 1 on new ones
  python3 tools/make_debug_states.py --levels   # how each PC level was derived
Rerun it after changes to maps, scripts, wild tables, trainers or items of
Kanto and Johto.
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
HEADER_B = "src/data/debug_johto_complete.h"
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
# Levels of an average player after the champion (Gen 5 experience).
KANTO_COMPLETE_PARTY_STARTER_LEVEL = 49
KANTO_COMPLETE_PARTY = [
    ("SPECIES_PIDGEOT", 43),
    ("SPECIES_RAICHU", 44),
    ("SPECIES_NIDOKING", 43),
    ("SPECIES_GYARADOS", 42),
    ("SPECIES_SNORLAX", 42),
]

# Active FRLG maps a run up to the first Hall of Fame never enters: post-title
# content, link rooms.
KANTO_POST_TITLE_MAPS = {"CeruleanCave_1F_Frlg", "CeruleanCave_2F_Frlg", "CeruleanCave_B1F_Frlg"}
KANTO_NEVER_MAPS = {
    "BattleColosseum_2P_Frlg", "BattleColosseum_4P_Frlg", "RecordCorner_Frlg",
    "TradeCenter_Frlg", "UnionRoom_Frlg",
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
    # TM Explosion for a Rage Candy Bar from Mahogany Town.
    "UndergroundPath_NorthSouthTunnel_EventScript_BaldingManCandyBar",
    # Rewards after the Kanto title or its rematch tier.
    "PewterCity_Gym_EventScript_TryGiveTMRockSlide",
    "Route13_EventScript_RobertGiveTMStoneEdge",
    "Route14_EventScript_BennyGiveTMWillOWisp",
    "Route15_EventScript_GraceGiveTMEnergyBall",
    "ViridianForest_EventScript_RickGiveTMXScissor",
    "Route25_SeaCottage_EventScript_BillTryGiveBoxLink",
    "Route25_SeaCottage_EventScript_GrandpaAfterTitle",
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
    # Elm's call after the first Johto title, also in Pallet Town.
    "NewBarkTown_EventScript_ElmCallAfterLeague",
    # Troy hands over the Hoenn Ticket after the first Johto title;
    # in state B the scene runs after the warp into Oak's lab.
    "PalletTown_ProfessorOaksLab_EventScript_TroyScene",
    "PalletTown_ProfessorOaksLab_EventScript_Troy",
    # Jirachi on Route 4 comes after the first trip to Hoenn.
    "Route4_EventScript_TryShowJirachi",
    "Route4_EventScript_WhiteRock",
    "Route4_EventScript_Jirachi",
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
    # Carter's VS Seeker rematch won (set in C, CB2_EndRematchBattle): TM73.
    "FLAG_DEFEATED_CARTER_REMATCH": 1,
    "FLAG_HIDE_PEWTER_CITY_GYM_GUIDE": 1, "FLAG_HIDE_PEWTER_MUSEUM_GUIDE": 0,
    # Hidden on the next Vermilion visit after talking to Oak's aide.
    "FLAG_HIDE_VERMILION_CITY_OAKS_AIDE": 1,
    "FLAG_IN_KANTO_SAFARI_ZONE": 0, "FLAG_POKEMON_MANSION_SWITCH_STATE": 0,
    "FLAG_SYS_ON_CYCLING_ROAD": 0,
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
                               "the lab sets it on every visit",
    "VAR_HOENN_TICKET_STATE": "0 until the first Johto title",
    "VAR_SECRET_BASE_INITIALIZED": "bedroom decorations, set on every visit of the player's room in Pallet Town "
                                   "and of New Bark's house",
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
    "FLAG_JOHTO_UNLOCKED": "TryUnlockJohtoOnMapLoad (src/region_rule_oj.c)",
    "FLAG_DEFEATED_CARTER_REMATCH": "CB2_EndRematchBattle (src/battle_setup.c)",
}

# Flags reset on every day change, never part of the state.
DAILY_FLAG_RE = re.compile(r"^FLAG_DAILY_\w+$")

# Scratch vars, never part of the state.
SCRATCH_VAR_RE = re.compile(
    r"^VAR_(RESULT|0x[0-9A-Fa-f]+|TEMP_\w+|ITEM_ID|SPECIAL_\w+|FRONTIER_\w+|TEXT_COLOR"
    r"|LAST_TALKED|FACING|OBJ_GFX_ID_\w+|ELEVATOR_FLOOR)$")

# Random Rock Smash finds: once each, as the other repeatable sources.
RANDOM_GIFT_ITEMS = {"ITEM_RED_SHARD", "ITEM_BLUE_SHARD", "ITEM_GREEN_SHARD", "ITEM_YELLOW_SHARD",
                     "ITEM_HEART_SCALE"}

# Gifts through a var that C code sets: label -> (file, array) of the items.
VAR_GIFT_TABLES = {
    "AzaleaTown_KurtsHouse_EventScript_Kurt2": [("src/shop.c", "sKurtBallShopItems")],
    "AzaleaTown_KurtsHouse_EventScript_SingularBall": [("src/shop.c", "sKurtBallShopItems")],
    "BugContestEventScript_Judging": [("src/bug_contest.c", "sFirstPlaceRewards"),
                                      ("src/bug_contest.c", "sSecondPlaceRewards"),
                                      ("src/bug_contest.c", "sThirdPlaceRewards")],
    "Gate_NationalPark_EventScript_GiveHeldPrize": [("src/bug_contest.c", "sFirstPlaceRewards"),
                                                    ("src/bug_contest.c", "sSecondPlaceRewards"),
                                                    ("src/bug_contest.c", "sThirdPlaceRewards")],
    "GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk": [("src/lottery_corner.c", "sLotteryPrizes")],
    "GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier": [("src/lottery_corner.c", "sLotteryPrizes")],
    "GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect": [("src/pokenav_radio.c", "sBuenaRewardTable")],
}
# Phone trainers' gifts: the item var and array of each HNS_MC_ITEM entry.
MATCH_CALL_FILE = "src/match_call.c"
# Items C code gives without a script: label that opens the source -> arrays.
C_ITEM_SOURCES = {
    # Mom buys items with the player's savings.
    "PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu": [("src/mom_savings.c", "sMomGifts_Sequential"),
                                                              ("src/mom_savings.c", "sMomGifts_Berries")],
}
# Battle facilities the walk leaves out whose items count once: the flag that
# opens one -> (prize arrays as (file, name pattern), mart lists of its
# clerks). The facility's own flags and records stay untouched.
FACILITY_ITEMS = {
    # Route 40 Trainer Hill; GetPrizeItemId picks from these lists.
    "FLAG_IS_JOHTO_CHAMPION": ([("src/trainer_hill.c", re.compile(r"^sPrizeList\w+_Hns$"))],
                               ["TrainerHill_Entrance_hns_Pokemart_Basic"]),
}
# Battle Point exchanges of facility maps the walk leaves out, whose wares
# count once (owner, O-060 (a)): exchange map -> the state map it opens
# from. Its clerks' CreateBP*Shop specials name the ware arrays (src/shop.c);
# decoration shops are left out. The Kampfzone's exchange opens only after
# the Hoenn title and is not listed.
BP_EXCHANGES = {
    # Route 40 Trainer Hill's courtyard; its three tents pay Battle Points
    # before the Johto title.
    "TrainerHill_Courtyard_hns": "Route40_hns",
}
# Gifts on facility maps the walk leaves out that a player gets before the
# state's title: map -> the labels kept (the rest of the map stays cut).
FACILITY_GIFTS_B = {
    # Route 40 courtyard tent: the girl with TM Safeguard (FLAG_RECEIVED_TM_ATTRACT).
    "VerdanturfTown_BattleTentLobby_hns": ("VerdanturfTown_BattleTentLobby_hns_EventScript_AttractGiver",
                                           "VerdanturfTown_BattleTentLobby_hns_EventScript_ReceivedAttract"),
}
BP_SHOP_FILE = "src/shop.c"
BP_SHOP_DATA = "src/data/battle_frontier/battle_frontier_exchange_corner.h"
# src/shop.c adds one per ten balls bought in a mart (I_PREMIER_BALL_BONUS).
PREMIER_BALL_BONUS = "ITEM_PREMIER_BALL"
# Gifts through a var a single player cannot get: label -> reason.
VAR_GIFT_SKIP = {
    "CeruleanCity_House4_EventScript_Reward_RecvSmall": "Wonder News reward (Mystery Gift, link)",
    "CeruleanCity_House4_EventScript_Reward_RecvBig": "Wonder News reward (Mystery Gift, link)",
    "CeruleanCity_House4_EventScript_Reward_SentSmall": "Wonder News reward (Mystery Gift, link)",
    "CeruleanCity_House4_EventScript_Reward_SentBig": "Wonder News reward (Mystery Gift, link)",
    "CeruleanCity_House5_EventScript_ExchangePowderForItem": "Berry Powder comes only from Berry Crush (link)",
}
# Arrays of the badge mart (pokemart 0) in src/shop.c, every badge count and
# the Pokemon Center challenge's lists.
BADGE_MART_RE = re.compile(r"^sShopInventory_\w+$")

# Bag pockets: pocket -> slot count macro (include/constants/global.h).
POCKET_SLOTS = {
    "POCKET_ITEMS": "BAG_ITEMS_COUNT", "POCKET_MEDICINE": "BAG_MEDICINE_COUNT",
    "POCKET_POKE_BALLS": "BAG_POKEBALLS_COUNT", "POCKET_TM_HM": "BAG_TMHM_COUNT",
    "POCKET_BERRIES": "BAG_BERRIES_COUNT", "POCKET_KEY_ITEMS": "BAG_KEYITEMS_COUNT",
    "POCKET_BATTLE_ITEMS": "BAG_BATTLE_ITEMS_COUNT", "POCKET_TREASURES": "BAG_TREASURES_COUNT",
}
# Free slots each pocket keeps for the next region's items; what does not fit
# goes into the PC's item storage.
POCKET_RESERVE = 20

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
    "FLAG_HAS_MATCH_CALL@johto": "PokeCom; Johto's arrival sets it again",
    "FLAG_RECEIVED_POKENAV@johto": "PokeCom; Johto's arrival sets it again",
    "FLAG_ADDED_MATCH_CALL_TO_POKENAV@johto": "PokeCom; Johto's arrival sets it again",
    "FLAG_ADVENTURE_STARTED": "game start; Johto and Hoenn treat the adventure as started",
    "VAR_TRAIN": "Magnet Train ride, Saffron and Goldenrod stations",
    "FLAG_SYS_B_DASH": "Running Shoes, whole game",
    "FLAG_RECEIVED_RUNNING_SHOES": "Running Shoes from Mom in Pallet Town",
    "FLAG_SYS_NATIONAL_DEX": "National Pokedex from Oak in Kanto, whole game",
    "VAR_NATIONAL_DEX": "National Pokedex from Oak in Kanto, whole game",
    "FLAG_SYS_RIBBON_GET": "ribbon flag, whole game",
    "FLAG_SYS_PC_LANETTE": "PC storage name flag, whole game",
    "FLAG_SET_WALL_CLOCK": "wall clock set at home in Pallet Town",
    "FLAG_START_NUZLOCKE": "Nuzlocke starts at Oak's Pokedex handover",
    "FLAG_BADGE01_GET": "Kanto badges; Johto and Hoenn count their own",
    "FLAG_BADGE02_GET": "Kanto badges; Johto and Hoenn count their own",
    "FLAG_BADGE03_GET": "Kanto badges; Johto and Hoenn count their own",
    "FLAG_BADGE04_GET": "Kanto badges; Johto and Hoenn count their own",
    "FLAG_BADGE05_GET": "Kanto badges; Johto and Hoenn count their own",
    "FLAG_BADGE06_GET": "Kanto badges; Johto and Hoenn count their own",
    "FLAG_BADGE07_GET": "Kanto badges; Johto and Hoenn count their own",
    "FLAG_BADGE08_GET": "Kanto badges; Johto and Hoenn count their own",
    "FLAG_IS_KANTO_CHAMPION@johto": "Kanto title, read by Johto's league and Red",
    "FLAG_SYS_GAME_CLEAR@johto": "first set by the Kanto league, opens the way to Johto",
    "VAR_JOHTO_HANDOVER@johto": "Oak's GS Ball handover, Kanto to Johto",
    "FLAG_CAUGHT_MEW": "one Mew, caught means gone for good",
    "FLAG_DEFEATED_MEW": "one Mew, caught means gone for good",
    "FLAG_RECEIVED_OVAL_CHARM": "one Oval Charm from the first Day Care egg",
    "FLAG_DONT_TRANSITION_MUSIC": "engine flag around warps",
    "FLAG_SYS_ON_CYCLING_ROAD@alias": "FLAG_SYS_CYCLING_ROAD, Emerald name of the same flag",
    "FLAG_HAS_MATCH_CALL@hoenn": "one PokeCom with Match Call from Pallet Town; Hoenn registers trainers on it",
    "FLAG_ADDED_MATCH_CALL_TO_POKENAV@hoenn": "one PokeCom; Rustboro's Match Call tutorial is skipped",
    "FLAG_ENABLE_MOM_MATCH_CALL": "one Mom (Pallet Town) in the PokeCom, whole game",
    "FLAG_GOT_BICYCLE@johto": "one Bicycle; Goldenrod's shop gives none if Kanto's is in the bag",
    "FLAG_GOT_COIN_CASE@johto": "one Coin Case; Goldenrod's ball holds a Nugget if it is in the bag",
    "FLAG_REGISTER_RIVAL_POKENAV@johto": "rival in the PokeCom; Hoenn uses FLAG_HOENN_REGISTER_RIVAL_POKENAV",
    "FLAG_SYS_GAME_CLEAR@hoenn": "a league was won: global uses only; Hoenn post-game checks the Hoenn title",
    "VAR_STARTER_MON": "Kanto's starter; Johto uses VAR_JOHTO_STARTER_MON, Hoenn's readers are cut by IS_HNS",
}


# ---------------------------------------------------------------------------
# Configuration, state B: Kanto and Johto complete, on top of state A

# Party right after the Johto league (about 70/63/63/62/60/60), no
# legendary. Johto starter index: VAR_JOHTO_STARTER_MON (0 Chikorita,
# 1 Cyndaquil, 2 Totodile).
JOHTO_COMPLETE_JOHTO_STARTER = 0
JOHTO_COMPLETE_PARTY = [
    ("SPECIES_CHARIZARD", 70),
    ("SPECIES_MEGANIUM", 63),
    ("SPECIES_GYARADOS", 63),
    ("SPECIES_AMPHAROS", 62),
    ("SPECIES_NIDOKING", 60),
    ("SPECIES_ESPEON", 60),
]

# HnS maps of state B besides Johto's map sections: Johto's league on the
# Indigo Plateau. None is excluded.
JOHTO_EXCLUDED_MAPS = set()

# Script labels of state B's walk that stay cut: battle facilities, link,
# Hoenn, the Sevii Islands, rematches, Troy's ticket, Sinjoh (locked by
# SINJOH_CONTENT_AVAILABLE).
CUT_LABELS_B = CUT_LABELS_ALWAYS | {
    "MtSilver_PokemonCenter_EventScript_Meara_BonusContentPrompt",
    "MtSilver_1F_WaterfallRoom_Scientist_Scene",
    # The Aurora Ticket comes after the first trip to Hoenn.
    "OlivineCity_EventScript_EonTicketWomanChamp",
    # Baoba's quest wants Hoenn Pokemon; his call in Rustboro City starts it.
    "SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBeach",
    "SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBrush",
    "SafariZoneGate_SafariZoneEntrance_EventScript_BaobaMountain",
    "SafariZoneGate_SafariZoneEntrance_EventScript_BaobaCave",
}
# Items state B's run finds that a finished run no longer has: item -> reason.
SKIP_ITEMS_B = {
    "ITEM_SPORT_BALL": "Bug-Catching Contest balls, taken back after the contest",
    "ITEM_GS_BALL": "used up at Ilex Forest's shrine",
    "ITEM_AZURE_FLUTE": "Sinjoh, locked (SINJOH_CONTENT_AVAILABLE); its item ball stays hidden",
    "ITEM_TIDAL_BELL": "Lugia's path; state B chose Ho-Oh (VAR_LUGIA_OR_HOOH 2)",
    "ITEM_SILVER_WING": "Lugia's path; state B chose Ho-Oh (VAR_LUGIA_OR_HOOH 2)",
}
# Gift labels of state B a run cannot use besides another label that gives
# the same item: label -> reason.
EXCLUSIVE_GIFTS_B = {
    "IcePath_B3F_EventScript_Swinub": "Delibird or Swinub gives TM72, FLAG_ITEM_ICEPATH4_TM_AVALANCHE allows one",
    # Second try of a gift the bag had no room for.
    "CianwoodCity_EventScript_ChucksWifeGiveSharpBeak": "Sharp Beak of the Fly scene (VAR_GETFLY 3)",
    "SSAqua_RoomSSE_EventScript_GiveMetalCoat": "Metal Coat of the reunion (FLAG_SSAQUA_METAL_COAT_PENDING)",
}
CUT_PREFIXES_B = CUT_PREFIXES + (
    "BattleFrontier_", "TrainerHill_", "ArtisanCave_",
    "Common_EventScript_SailTo",
)
# Script files whose labels state B's walk never enters.
CUT_FILES_B = re.compile(r"^data/scripts/(battle_frontier|trainer_hill|cable_club|mystery_event)")

# HnS's first-visit initialisation of a town's flags ("flag heap", a coord
# event at the town's entrance while its state var is 0): their writes count
# only for names no other label of the run writes.
INIT_LABELS_B = {
    "VioletCity_EventScript_Trigger", "AzaleaTown_EventScript_Trigger", "GoldenrodCity_EventScript_Trigger",
    "EcruteakCity_EventScript_Trigger", "OlivineCity_EventScript_CityTrigger",
    "MahoganyTown_EventScript_TownTrigger", "RocketHideout_B1F_TriggerTest",
    "Route27_OnTransition",
}

# State B: flags the Kanto and Johto scripts set and clear, value of a
# completionist after the first Johto title. Entries of MANUAL_FLAGS hold
# unless listed here.
MANUAL_FLAGS_B = {
    "FLAG_HIDE_VERMILION_SS_AQUA": 1,                  # Vermilion's port sets it on every visit
    "FLAG_HIDE_OAKS_LAB_TROY": 0,                      # Troy waits in Oak's lab
    "FLAG_JOHTO_UNLOCKED": 1,                          # first Johto map after the Kanto title
    # Bug-Catching Contest over, Safari Zone left, Route 41's Tentacruel fought.
    "FLAG_DISABLE_EXP_GAIN": 0, "FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE": 1, "FLAG_GOOD_LUCK_SAFARI_ZONE": 1,
    "FLAG_NO_SHINY": 0, "FLAG_NO_WILD_CATCHING": 0,
    # Goldenrod's underground switches, cleared on every load once solved.
    "FLAG_GOLDENROD_SWITCH_1": 0, "FLAG_GOLDENROD_SWITCH_2": 0, "FLAG_GOLDENROD_SWITCH_3": 0,
    "FLAG_GOLDENROD_SWITCH_ORDER": 0,
    "FLAG_GOT_DRATINI": 1,                             # the Dragon's Den elder's Dratini
    # Azalea: Bugsy's gym puzzle (set on every visit), Kurt, Silver, the Slowpoke.
    "FLAG_HIDE_AZALEA_ARIADOS_LEFT": 1, "FLAG_HIDE_AZALEA_ARIADOS_MID": 1, "FLAG_HIDE_AZALEA_ARIADOS_RIGHT": 1,
    "FLAG_HIDE_AZALEA_TOWN_KURT": 1, "FLAG_HIDE_AZALEA_TOWN_SILVER": 1, "FLAG_HIDE_AZALEA_TOWN_SLOWPOKE": 1,
    "FLAG_HIDE_KURT_1": 1,
    # Ilex Forest: the Farfetch'd caught, the charcoal master and his apprentice back in Azalea,
    # Kurt's and the Kimono Girl's scenes done, Celebi caught.
    "FLAG_HIDE_AZALEA_TOWN_CUT_MASTER": 0, "FLAG_HIDE_AZALEA_TOWN_FARFETCHD": 0,
    "FLAG_HIDE_ILEX_FOREST_APPRENTICE": 1, "FLAG_HIDE_ILEX_FOREST_MASTER": 1,
    "FLAG_HIDE_ILEX_FOREST_FARFETCHD_1": 1, "FLAG_HIDE_ILEX_FOREST_FARFETCHD_2": 1,
    "FLAG_HIDE_ILEX_FOREST_FARFETCHD_3": 1, "FLAG_HIDE_ILEX_FOREST_FARFETCHD_4": 1,
    "FLAG_HIDE_ILEX_FOREST_KIMONO": 1, "FLAG_HIDE_ILEX_FOREST_KURT": 1, "FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI": 1,
    # Cherrygrove's guide back home, Silver's battles in Cherrygrove, New Bark, Olivine,
    # Ecruteak, Goldenrod's underground and the Rocket Hideout done.
    "FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE": 0, "FLAG_HIDE_SILVER_CHERRYGROVE": 1,
    "FLAG_HIDE_SILVER_NEWBARKTOWN": 1, "FLAG_HIDE_OLIVINE_SILVER": 1, "FLAG_HIDE_ECRUTEAK_SILVER": 1,
    "FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER": 1, "FLAG_HIDE_ROCKETHIDEOUT3_SILVER": 1,
    # Suicune's sightings in Cianwood and on Route 42 done.
    "FLAG_HIDE_CIANWOOD_EUSINE": 1, "FLAG_HIDE_CIANWOOD_SUICUNE": 1, "FLAG_HIDE_ROUTE42_EUSINE": 1,
    "FLAG_HIDE_ROUTE42_SUICUNE": 1,
    # Clair gave the badge in the Dragon's Den.
    "FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR": 1, "FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR": 1,
    # Ecruteak's theater back to normal after the legendary, Tin Tower open.
    "FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS": 0, "FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS": 0,
    "FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI": 0, "FLAG_HIDE_TINTOWER_GUARD": 1,
    "FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS": 1, "FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS": 1,
    "FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL": 1, "FLAG_HIDE_ROUTE39_SHADOW": 1,
    # Goldenrod's Radio Tower freed.
    "FLAG_HIDE_GOLDENROD_NPCS": 0, "FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR": 0,
    "FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL": 1, "FLAG_HIDE_GOLDENROD_ROCKETS": 1,
    "FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO": 1, "FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1": 1,
    # One-time encounters caught (the maps set these on every visit as well).
    "FLAG_HIDE_HO_OH": 1, "FLAG_HIDE_LUGIA": 1, "FLAG_HIDE_LAKE_OF_RAGE_GYARADOS": 1, "FLAG_HIDE_MEWTWO": 1,
    "FLAG_HIDE_UNION_CAVE_LAPRAS": 1,
    # Silver waits in Johto's league center after the title.
    "FLAG_HIDE_INDIGO_PLATEAU_SILVER": 0,
    # Lake of Rage and Mahogany done.
    "FLAG_HIDE_LAKE_OF_RAGE_LANCE": 1, "FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS": 1,
    "FLAG_HIDE_LAB_POLICEMAN": 1, "FLAG_HIDE_NEWBARKTOWN_LAB_AIDE": 0,
    "FLAG_HIDE_VIOLET_CITY_AIDE": 1, "FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL": 1,
    "FLAG_RECEIVED_FIRST_BALLS": 1,
    # Red beaten; he returns for rematches.
    "FLAG_HIDE_MTSILVER_RED": 0,
    # Rocket Hideout done.
    "FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT": 1, "FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE": 1,
    "FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE": 1, "FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS": 1,
    "FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI": 1, "FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS": 1,
    "FLAG_HIDE_ROCKETHIDEOUT3_PETREL": 1, "FLAG_HIDE_ROCKETHIDEOUT_ROCKETS": 1,
    "FLAG_ROCKETHIDEOUT2_BATTLE": 0, "FLAG_ROCKETHIDEOUT_SWITCH": 1,
    "FLAG_HIDE_ROUTE28_SCIENTIST": 1,
    # The M.S. Aqua's maiden voyage done: the granddaughter found.
    "FLAG_HIDE_SSAQUA_1F_GRANDPA": 1, "FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER": 1,
    "FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER": 0, "FLAG_HIDE_SSAQUA_SAILOR": 0,
    "FLAG_SSAQUA_METAL_COAT_PENDING": 0,               # Metal Coat handed over at the reunion
    "FLAG_HIDE_TOHJO_GIOVANNI": 1,                     # Celebi's scene at Tohjo Falls
}

# State B: vars, as MANUAL_VARS.
MANUAL_VARS_B = {
    "VAR_HOENN_TICKET_STATE": 1,                       # Troy waits in Oak's lab
    "VAR_JOHTO_HANDOVER": 3,                           # GS Ball delivered to Elm
    "VAR_JOHTO_BADGES": "0xFF",                        # SetJohtoBadge, all eight
    "VAR_JOHTO_PERMITS": "(1 << PERM_COUNT) - 1",      # SetJohtoPermit, every permit
    "VAR_NUM_BADGES": 8,                               # HnS's badge count, the eight Johto gyms
    # Story vars of Johto: the last stage.
    "VAR_AZALEA_TOWN_STATE": 10,
    "VAR_BLACKTHORN_CITY_STATE": 5,
    "VAR_BLACKTHORN_GYM_STATE": 4,
    "VAR_BUG_CONTEST_STATE": 0,
    "VAR_CHERRYGROVE_CITY_STATE": 4,
    "VAR_DRAGONS_DEN_QUIZ": 0,
    "VAR_ECRUTEAK_CITY_STATE": 4,
    "VAR_ECRUTEAK_CITY_THEATER": 8,
    "VAR_ELECTRODES_FAINTED": 4,
    "VAR_FOSSIL_RESURRECTION_STATE": 0,
    "VAR_GETFLY": 2,
    "VAR_GOLDENROD_CITY_STATE": 11,
    "VAR_ILEX_FOREST_FARFETCHD": 4,
    "VAR_KENYA": 3,
    "VAR_LAKE_OF_RAGE_FISHERMAN": 2,
    "VAR_LEAGUE_STATE": 1,
    "VAR_MAHOGANY_TOWN_STATE": 17,
    "VAR_NEWBARKTOWN_LABSTATE": 11,                    # Elm's S.S. Ticket after the title
    "VAR_NEWBARK_TOWN_STATE": 7,                       # Elm's call after the title came
    "VAR_OLIVINE_CITY_STATE": 8,
    "VAR_ROCKET_HIDEOUT_STATUE_1": 2, "VAR_ROCKET_HIDEOUT_STATUE_2": 2, "VAR_ROCKET_HIDEOUT_STATUE_3": 2,
    "VAR_ROCKET_HIDEOUT_STATUE_4": 2, "VAR_ROCKET_HIDEOUT_STATUE_5": 2,
    "VAR_ROCKET_PASSWORD": 3,
    "VAR_ROUTE39_BARN": 5,                             # Miltank healed
    "VAR_RUINSOFALPH_STATE": 0,
    "VAR_SAFARI_ZONE_GATE_STATE": 4,
    "VAR_SAFARI_ZONE_STATE": 1,
    "VAR_SHUCKIE": 3,
    "VAR_SSAQUA_STATE": 7,                             # maiden voyage done
    "VAR_SUICUNE_ENCOUNTERS": 8,                       # Suicune caught in the Glockenturm
    "VAR_TRIGGER_ELM_ROCKET_CALL": 2,
    "VAR_VIOLET_CITY_KIMONO_GIRL": 2,
    "VAR_VIOLET_CITY_STATE": 5,
    "VAR_SEA_COTTAGE_GRANDPA": 2,                      # Meowth shown; next is Hoenn's Zigzagoon
    # Ho-Oh chosen on Route 39 (2; 1 Lugia); both caught.
    "VAR_LUGIA_OR_HOOH": 2, "VAR_COMPLETED_HO_OH": 3, "VAR_COMPLETED_LUGIA": 3,
}

SET_BY_DEBUG_C_B = dict(SET_BY_DEBUG_C, **{
    "VAR_JOHTO_STARTER_MON": "debug.c, JOHTO_COMPLETE_JOHTO_STARTER",
})

UNTOUCHED_B = dict(UNTOUCHED, **{
    "FLAG_SYS_BUG_CONTEST_MODE": "set and cleared around a Bug-Catching Contest",
    "FLAG_SYS_LAKE_OF_RAGE_TIDE": "follows the clock",
    "FLAG_SYS_SHOAL_TIDE": "follows the clock",
    "VAR_TIME_BASED_ENCOUNTER": "follows the clock, set on every map load",
    "VAR_CABLE_CLUB_STATE": "link feature",
    "VAR_ELEVATOR": "elevator position, set on every ride",
    "VAR_POKELOT_PRIZE_ITEM": "lottery prize waiting for room in the bag; none",
    "VAR_POKELOT_PRIZE_PLACE": "lottery prize waiting for room in the bag; none",
    "VAR_TOHJO_FALLS_GIOVANNI_STATE": "Celebi's scene at Tohjo Falls, reset on every visit without Celebi",
    "VAR_WHICH_FOSSIL_REVIVED": "only read while a fossil is being revived",
    "FLAG_MINTS_DISABLED": "challenge option tx_Mode_Mints; the flower shop clears it only after the Hoenn title",
})

DROP_FLAGS_B = dict(DROP_FLAGS)

# Rematch and title defence teams after the titles.
TRAINER_SKIP_RE_B = re.compile(r"^TRAINER_(ELITE_FOUR_\w+_2|CHAMPION_REMATCH_\w+|\w+_POSTOBC_HNS|"
                               r"(FALKNER|BUGSY|WHITNEY|MORTY|CHUCK|JASMINE|PRYCE|CLAIR|WILL|KOGA|BRUNO|KAREN|LANCE)"
                               r"_[2-9]_HNS)$")
JOHTO_RIVALS = {
    "var": "VAR_JOHTO_STARTER_MON",
    "re": re.compile(r"^TRAINER_RIVAL_(?P<starter>CHIKORITA|CYNDAQUIL|TOTODILE)_\d+_HNS$"),
    "names": ["Chikorita", "Cyndaquil", "Totodile"],   # by VAR_JOHTO_STARTER_MON
    "chosen": JOHTO_COMPLETE_JOHTO_STARTER,
}

# Catch levels that differ from the highest level of a species' sources:
# the chosen one of Lugia and Ho-Oh at its story level.
LEVEL_OVERRIDES_B = {
    "SPECIES_HO_OH": 78,
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

    def value(self, expr):
        """Integer value of an expression of the build's macros."""
        e = re.sub(r"\b(0[xX][0-9a-fA-F]+|\d+)[uUlL]+\b", r"\1", self.expand(expr)).replace("/", "//")
        return int(eval(e, {"__builtins__": {}}, {}))

    def pocket(self, name):
        """The pocket a POCKET_ name stands for (POCKET_TREASURES -> POCKET_ITEMS
        with combined pockets)."""
        while self.macros.get(name, "").startswith("POCKET_"):
            name = self.macros[name]
        return name

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


# Hoenn progress: 0 in both states (Troy's VAR_HOENN_TICKET_STATE is part of state B).
HOENN_PROGRESS_RE = re.compile(r"^(FLAG_IS_HOENN_CHAMPION|VAR_HOENN_(?!TICKET_STATE$)\w+)$")
BRANCH_RE = re.compile(r"^(goto|call)_if_(set|unset|eq|ne|lt|le|gt|ge)$")


def hoenn_branch(cmd, args):
    """For a branch on Hoenn progress: (its target, the commands after it) each
    True if it runs only after Hoenn progress. None for other commands."""
    m = BRANCH_RE.match(cmd)
    if not m or not args or not HOENN_PROGRESS_RE.match(args[0]):
        return None
    kind = m.group(2)
    if kind in ("set", "unset"):
        taken = kind == "unset"
    else:
        try:
            n = int(args[1], 0)
        except (IndexError, ValueError):
            return None
        taken = {"eq": n == 0, "ne": n != 0, "lt": 0 < n, "le": 0 <= n, "gt": 0 > n, "ge": 0 >= n}[kind]
    return not taken, taken and m.group(1) == "goto"


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
        # Johto's map sections and Johto's league (Kanto sections in HnS's maps).
        self.johto = sorted((d for d in self.all.values()
                             if d["_dir"].endswith("_hns") and d["_dir"] not in JOHTO_EXCLUDED_MAPS
                             and self.sections.region(d.get("region_map_section", "MAPSEC_NONE"))
                             in ("Johto", "Kanto")),
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


def load_item_values():
    """ITEM_ constant -> number, and number -> constant, of the Item enum (jade build)."""
    m = re.search(r"enum\s+__attribute__\(\(packed\)\)\s+Item\s*\{(.*?)\n\};", read("include/constants/items.h"), re.S)
    values, by_number, n = {}, {}, -1
    for line in re.sub(r"//[^\n]*", "", m.group(1)).split("\n"):
        em = re.match(r"\s*(\w+)\s*(?:=\s*(\w+))?\s*,", line)
        if not em:
            continue
        name, val = em.groups()
        if val is None:
            n += 1
        elif val.isdigit():
            n = int(val)
        elif val in values:
            n = values[val]
        else:
            continue
        values[name] = n
        if name.startswith("ITEM_") and not (val or "").startswith("ITEM_"):
            by_number.setdefault(n, name)
    return values, by_number


def c_item_array(cond, path, name):
    """ITEM_ constants of a C array initializer (plain or struct entries)."""
    text = "\n".join(l for _, l in cond.lines(path))
    m = re.search(r"\b%s\s*\[\s*\w*\s*\]\s*=\s*\{" % re.escape(name), text)
    if not m:
        return []
    body = text[m.end() - 1:match_brace(text, m.end() - 1)]
    return [i for i in re.findall(r"\bITEM_\w+\b", body) if i != "ITEM_NONE"]


def c_array_names(cond, path, pattern):
    """Names of the C arrays of a file that match pattern."""
    text = "\n".join(l for _, l in cond.lines(path))
    return sorted(n for n in re.findall(r"\b(\w+)\s*\[\s*\w*\s*\]\s*=\s*\{", text) if pattern.match(n))


def load_bp_shops(cond):
    """Special -> (mart type, BPShopEntry array) of src/shop.c's CreateBP*Shop
    functions."""
    text = "\n".join(l for _, l in cond.lines(BP_SHOP_FILE))
    return {f: (t, arr) for f, t, arr in re.findall(
        r"\bvoid\s+(CreateBP\w+)\s*\(\s*void\s*\)\s*\{\s*CreateBPShopCommon\(\s*(\w+)\s*,\s*(\w+)\s*\)\s*;\s*\}",
        text)}


def load_match_call_gifts(cond):
    """Item var -> array of the phone trainers' gifts (HNS_MC_ITEM entries)."""
    text = "\n".join(l for _, l in cond.lines(MATCH_CALL_FILE))
    return {var: arr for var, arr in
            re.findall(r"HNS_MC_ITEM\d\(\s*\w+,\s*\w+,\s*\w+,\s*(VAR_\w+),\s*(\w+)\s*\)", text)}


def load_berry_trees(cond):
    """Berry tree id (number) -> berries planted by the new game's setberrytree."""
    ids = {}
    for name, val in re.findall(r"#define\s+(BERRY_TREE_\w+)\s+(\w+)", read("include/constants/berry.h")):
        ids[name] = int(val) if val.isdigit() else ids.get(val)
    trees = collections.defaultdict(set)
    for _, line in cond.lines("data/scripts/new_game.inc"):
        m = re.match(r"\s*setberrytree\s+(\w+)\s*,\s*ITEM_TO_BERRY\((ITEM_\w+)\)", line)
        if m and ids.get(m.group(1)) is not None:
            trees[ids[m.group(1)]].add(m.group(2))
    return ids, trees


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


def load_johto_corridors():
    """MAPSEC_ -> (floor, ceiling) of JOHTO_SCALING_CORRIDORS."""
    text = read("include/config/johto_scaling.h")
    return {m.group(1): (int(m.group(2)), int(m.group(3)))
            for m in re.finditer(r"\{\s*(MAPSEC_\w+),\s*(\d+),\s*(\d+)", text)}


def load_fly_flags():
    """Flags of the combined Johto-Kanto fly map (sMapFlyDestinations, src/region_map.c)."""
    text = read("src/region_map.c")
    return sorted(set(re.findall(r"\.regionMapType\s*=\s*REGION_MAP_JK,\s*\.mapsec\s*=\s*\w+,\s*\.flag\s*=\s*(FLAG_\w+)",
                                 text)))


def load_bag_limits(cond):
    """Pocket -> slots of the jade build (include/constants/global.h); pockets
    the build combines (I_COMBINE_BAG_POCKETS) under the pocket they join."""
    limits = {}
    for pocket, macro in POCKET_SLOTS.items():
        if pocket == cond.pocket(pocket) and macro in cond.macros:
            limits[pocket] = cond.value(macro)
    return limits


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
        self.pockets = {self.item(i): self.cond.pocket(p) for i, p in load_item_pockets(self.cond).items()}
        self.key_items = {i for i, p in self.pockets.items() if p == "POCKET_KEY_ITEMS"}
        self.bag_limits = load_bag_limits(self.cond)
        self.item_values, self.item_by_value = load_item_values()
        self.match_call_gifts = load_match_call_gifts(self.cond)
        self.bp_shops = load_bp_shops(self.cond)
        self.berry_tree_ids, self.berry_trees = load_berry_trees(self.cond)
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

    def _hoenn_gated(self):
        """Commands of the run's labels that run only after Hoenn progress,
        as (label, line): behind a branch on HOENN_PROGRESS_RE, or in a label
        that only such commands reach."""
        labels = self.scripts.labels
        roots = {e for d in self.maps for e in Maps.entries(d)}
        gated = set()
        refs = collections.defaultdict(list)   # label -> (from label, line, needs Hoenn progress)
        for name in self.labels:
            cmds = labels[name]["cmds"]
            after = False
            for n, cmd, args in cmds:
                if after:
                    gated.add((name, n))
                branch = hoenn_branch(cmd, args)
                if cmd not in STRING_CMDS:
                    for a in args:
                        for tok in re.findall(r"\b\w+\b", a):
                            if tok in self.labels:
                                refs[tok].append((name, n, bool(branch and branch[0] and tok == args[-1])))
                if branch and branch[1]:
                    after = True
            nxt = labels[name]["next"]
            if labels[name]["falls"] and nxt in self.labels:
                refs[nxt].append((name, cmds[-1][0] if cmds else None, after))
        gated_labels = set()
        changed = True
        while changed:
            changed = False
            for name in self.labels:
                if name in gated_labels or name in roots or not refs.get(name):
                    continue
                if all(hoenn or src in gated_labels or (src, n) in gated for src, n, hoenn in refs[name]):
                    gated_labels.add(name)
                    changed = True
        for name in gated_labels:
            gated |= {(name, n) for n, _, _ in labels[name]["cmds"]}
        return gated

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
        self.purchase_items = collections.defaultdict(set)  # item -> purchase labels
        self.var_gift_sites = []                            # (label, var, file) of gifts through a var
        self.file_var_items = collections.defaultdict(set)  # (file, VAR) -> ITEM_ values of setvar
        self.marts = collections.defaultdict(set)           # list label ("0": badge mart) -> labels
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
        # Labels that take money or coins: purchases, not counted (as marts).
        purchases = {name for name in self.labels
                     if any(c in ("removemoney", "removecoins") for _, c, _ in self.scripts.labels[name]["cmds"])}
        gated = self._hoenn_gated()
        self.hoenn_writes = collections.defaultdict(set)    # name -> labels that write it after Hoenn progress
        self.other_writes = set()                           # names also written without Hoenn progress
        for name in sorted(self.labels):
            for n, cmd, a in self.scripts.labels[name]["cmds"]:
                if cmd in ("setflag", "setworldmapflag", "clearflag", "setvar", "addvar", "subvar", "copyvar") and a:
                    if (name, n) in gated:
                        self.hoenn_writes[a[0]].add(name)
                    else:
                        self.other_writes.add(a[0])
        for name in sorted(self.labels):
            path = self.scripts.labels[name]["file"]
            for n, cmd, a in self.scripts.labels[name]["cmds"]:
                if (name, n) in gated:
                    continue
                arg = (a[1] if cmd == "giveitem_msg" else a[0]) if len(a) > (cmd == "giveitem_msg") else None
                if cmd in ("giveitem", "additem", "giveitem_norandom", "giveitem_msg") and arg:
                    if arg.startswith("ITEM_"):
                        if name in purchases:
                            self.purchase_items[self.item(arg)].add(name)
                    elif arg.startswith("VAR_"):
                        self.var_gift_sites.append((name, arg, path))
                elif cmd == "setvar" and len(a) > 1 and a[1].startswith("ITEM_") and a[1] != "ITEM_NONE":
                    self.file_var_items[(path, a[0])].add(self.item(a[1]))
                elif cmd == "pokemart" and a:
                    self.marts[a[0]].add(name)
        for name, cmd, a in self.cmds():
            path = self.scripts.labels[name]["file"]
            mdir = map_dir_of(path)
            flag_writes = init_flags if name in init_labels else self.flag_writes
            var_writes = init_vars if name in init_labels else self.var_writes
            if cmd in ("giveitem", "additem", "giveitem_norandom", "giveitem_msg") and name in purchases:
                continue
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
        # Pickups (item balls, fossils) and hidden items of the maps.
        for d in self.maps:
            for o in d.get("object_events") or []:
                if self.pickup(o) and o.get("flag", "0") not in ("0", ""):
                    flags[o["flag"]] = 1
            for b in d.get("bg_events") or []:
                if b.get("type") == "hidden_item" and b.get("flag"):
                    flags[b["flag"]] = 1
        self.flags = flags

    def pickup(self, obj):
        """(item, quantity) of a map pickup: an object whose script runs finditem."""
        script = obj.get("script")
        if script not in self.scripts.labels:
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
                found = self.pickup(o)
                if found:
                    bag[found[0]] += found[1]
            for b in d.get("bg_events") or []:
                # ITEM_NONE: Game Corner coins, not counted.
                if b.get("type") == "hidden_item" and b["item"] != "ITEM_NONE":
                    bag[self.item(b["item"])] += int(b.get("quantity", 1))
        exclusive = self.cfg.get("exclusive_gifts", {})
        self._once_items()
        for item, by_label in self.item_gifts.items():
            if item in RANDOM_GIFT_ITEMS:
                self.once[item] |= set(by_label)
            else:
                bag[item] += sum(q for label, q in by_label.items() if label not in exclusive)
        for item, q in self.item_removed.items():
            bag[item] -= q
        # Items only clerks behind a challenge option sell: item -> the flag that hides the clerk.
        self.option_items = {i: next(iter(g)) for i, g in self.once_gates.items()
                             if len(g) == 1 and None not in g and bag[i] <= 0
                             and all(src in self.marts for src in self.once[i])}
        # Purchases and repeatable sources: at least one of each.
        for item in self.once:
            bag[item] = max(bag[item], 1)
        # One of each key item and HM: gifts in exclusive branches (e.g. the
        # Route 15 aide's Exp. Share or Small Exp. Share) are all counted above.
        for item in list(bag):
            if bag[item] > 1 and (item in self.w.key_items or item.startswith("ITEM_HM")):
                bag[item] = 1
        for item in self.cfg.get("skip_items", {}):
            bag.pop(item, None)
        self.bag = {i: q for i, q in sorted(bag.items()) if q > 0}

    def _once_items(self):
        """Items the bag holds at least once (owner, 2026-11-02): purchases
        (marts, prize rooms, merchants), gifts through a var (C tables, random
        picks, script values), berry trees and held items of in-game trades.
        Sets self.once (item -> sources) and self.once_problems."""
        w = self.w
        once = collections.defaultdict(set)
        gates = collections.defaultdict(set)   # item -> clerk flags of its marts (None: always open)
        problems = []
        for item, labels in self.purchase_items.items():
            once[item] |= labels
            gates[item].add(None)
        marts = dict(self.marts)
        for flag, (_, lists) in FACILITY_ITEMS.items():
            if self.flags.get(flag) == 1:
                for lst in lists:
                    marts[lst] = marts.get(lst, set()) | {flag}
        for lst, labels in sorted(marts.items()):
            if lst == "0":
                items = [i for arr in c_array_names(w.cond, "src/shop.c", BADGE_MART_RE)
                         for i in c_item_array(w.cond, "src/shop.c", arr)]
            else:
                items = []
                for _, cmd, args in self.scripts.labels.get(lst, {"cmds": []})["cmds"]:
                    if cmd != ".2byte" or not args or args[0] == "ITEM_NONE":
                        break
                    items.append(args[0])
            if not items:
                problems.append("mart list %s of %s has no items" % (lst, ", ".join(sorted(labels))))
            gate = self._clerk_flag(labels)
            if any(w.pockets.get(self.item(i)) == "POCKET_POKE_BALLS" for i in items):
                items.append(PREMIER_BALL_BONUS)
            for i in items:
                once[self.item(i)].add(lst if lst != "0" else "badge mart")
                gates[self.item(i)].add(gate)
        self.var_gift_skipped = set()
        for label, var, path in self.var_gift_sites:
            items = []
            if label in VAR_GIFT_SKIP:
                self.var_gift_skipped.add(label)
                continue
            if label in VAR_GIFT_TABLES:
                items = [i for p, arr in VAR_GIFT_TABLES[label] for i in c_item_array(w.cond, p, arr)]
            elif var in w.match_call_gifts:
                items = c_item_array(w.cond, MATCH_CALL_FILE, w.match_call_gifts[var])
            else:
                items = self._random_items(label, var) or sorted(self.file_var_items.get((path, var), ()))
            if not items:
                problems.append("%s gives an item through %s that the generator cannot resolve; "
                                "needs VAR_GIFT_TABLES or VAR_GIFT_SKIP" % (label, var))
            for i in items:
                once[self.item(i)].add(label)
        for label, arrays in C_ITEM_SOURCES.items():
            if label in self.labels:
                for p, arr in arrays:
                    for i in c_item_array(w.cond, p, arr):
                        once[self.item(i)].add(label)
        for flag, (arrays, _) in FACILITY_ITEMS.items():
            if self.flags.get(flag) == 1:
                for p, pattern in arrays:
                    for arr in c_array_names(w.cond, p, pattern):
                        for i in c_item_array(w.cond, p, arr):
                            once[self.item(i)].add(arr)
        state_maps = {d["_dir"] for d in self.maps}
        for mdir, entry in sorted(BP_EXCHANGES.items()):
            if entry not in state_maps:
                continue
            wares = self.bp_wares(mdir)
            if not wares:
                problems.append("BP exchange %s (BP_EXCHANGES): no clerk opens a Battle Point shop" % mdir)
            for arr, items in wares:
                if not items:
                    problems.append("BP exchange %s: no items in %s of %s" % (mdir, arr, BP_SHOP_DATA))
                for i in items:
                    once[self.item(i)].add(arr)
        for d in self.maps:
            for o in d.get("object_events") or []:
                if o.get("script") != "BerryTreeScript":
                    continue
                tid = str(o.get("trainer_sight_or_berry_tree_id", ""))
                num = int(tid) if tid.isdigit() else w.berry_tree_ids.get(tid)
                berries = w.berry_trees.get(num)
                if not berries:
                    problems.append("berry tree %s of %s has no berry in new_game.inc" % (tid, d["_dir"]))
                for b in berries or ():
                    once[self.item(b)].add("berry tree %s" % d["_dir"])
        kept = "\n".join(l for _, l in w.cond.lines("src/data/trade.h"))
        for tid in self.trade_ids:
            m = re.search(r"\[%s\]\s*=\s*\{(.*?)\n\s*\}," % tid, kept, re.S)
            hm = re.search(r"\.heldItem\s*=\s*(ITEM_\w+)", m.group(1)) if m else None
            if hm and hm.group(1) != "ITEM_NONE":
                once[self.item(hm.group(1))].add(tid)
        self.once = once
        self.once_gates = gates
        self.once_problems = problems

    def bp_wares(self, mdir):
        """(array, items) of each Battle Point shop the clerks of an exchange
        map open; decoration shops hold no bag items."""
        d = self.w.maps.by_dir.get(mdir)
        out = {}
        for name in sorted(self.scripts.walk(Maps.entries(d)) if d else ()):
            for _, cmd, args in self.scripts.labels[name]["cmds"]:
                if cmd == "special" and args and args[0] in self.w.bp_shops:
                    mtype, arr = self.w.bp_shops[args[0]]
                    if mtype != "MART_TYPE_BP_DECOR" and arr not in out:
                        out[arr] = c_item_array(self.w.cond, BP_SHOP_DATA, arr)
        return sorted(out.items())

    def _clerk_flag(self, labels):
        """The flag that hides the clerk of a mart, if the state leaves it at
        its new game value (a challenge option, UNTOUCHED); else None."""
        flags = {o.get("flag") for d in self.maps for o in d.get("object_events") or []
                 if o.get("script") in labels}
        if len(flags) == 1 and next(iter(flags)) in self.cfg["untouched"]:
            return next(iter(flags))
        return None

    def _random_items(self, label, var):
        """Items of 'random N' and 'addvar var, FIRST' before the gift: FIRST
        and the N-1 items after it."""
        n = None
        for _, cmd, args in self.scripts.labels[label]["cmds"]:
            if cmd == "random" and args and args[0].isdigit():
                n = int(args[0])
            elif cmd == "addvar" and n and len(args) > 1 and args[0] == var:
                first = self.w.item_values.get(args[1])
                if first is None:
                    return []
                return [self.w.item_by_value[v] for v in range(first, first + n) if v in self.w.item_by_value]
        return []

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
        manual = set(cfg["manual_flags"]) | set(cfg["manual_vars"])
        for name in sorted(self.hoenn_writes):
            if name in state and name not in self.other_writes and name not in manual:
                problems.append("%s: written only after Hoenn progress (%s), needs an UNTOUCHED reason"
                                % (name, ", ".join(sorted(self.hoenn_writes[name]))))
        written = self.written() | set(C_WRITERS)
        for table in ("manual_flags", "manual_vars", "drop_flags", "untouched"):
            for name in sorted(cfg[table]):
                if name not in written:
                    problems.append("%s: listed in %s, but nothing in the run writes it" % (name, table))
        gift_labels = {label for by_label in self.item_gifts.values() for label in by_label}
        for label in sorted(cfg.get("exclusive_gifts", {})):
            if label not in gift_labels:
                problems.append("%s: listed in exclusive_gifts, but gives no item in the run" % label)
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


def johto_catch_levels(world, run, species):
    """Species -> catch level in Johto: corridor floor + 2 of the lowest
    corridor whose wild tables have it, else the highest gift or static level
    of Johto's scripts (roamers: src/legendaries_oj.c), else for eggs and
    trades the band of their map."""
    corridors = load_johto_corridors()
    by_id = {d["id"]: d for d in world.maps.johto}

    def band(mapsec):
        c = corridors.get(mapsec)
        return min(c[0] + 2, c[1]) if c else None
    wild = {}
    for group in load_json("src/data/wild_encounters.json")["wild_encounter_groups"]:
        if not group.get("for_maps"):
            continue
        for e in group["encounters"]:
            d = by_id.get(e["map"])
            lv = band(d.get("region_map_section")) if d else None
            if lv is None:
                continue
            for key in ("land_mons", "water_mons", "rock_smash_mons", "fishing_mons", "hidden_mons"):
                for m in (e.get(key) or {}).get("mons", []):
                    s = species.canonical(m["species"])
                    if s:
                        wild[s] = min(wild.get(s, 999), lv)
    scripted, mapped = {}, {}
    for kind, s, level, path in run.mon_sources:
        mdir = map_dir_of(path)
        if not mdir or not mdir.endswith("_hns") or mdir not in world.maps.by_dir:
            continue
        s = species.canonical(s)
        if not s:
            continue
        if kind == "egg" or not level:
            lv = band(world.maps.by_dir[mdir].get("region_map_section"))
            if lv is not None:
                mapped[s] = min(mapped.get(s, 999), lv)
        else:
            scripted[s] = max(scripted.get(s, 0), level)
    for lid in run.legendaries:
        leg = world.legendaries.get(lid)
        if leg and leg["species"]:
            scripted.setdefault(leg["species"], leg["level"])
    for s, mdirs in trade_species(world, run).items():
        for mdir in mdirs:
            d = world.maps.by_dir.get(mdir)
            lv = band(d.get("region_map_section")) if d and mdir.endswith("_hns") else None
            cs = species.canonical(s)
            if lv is not None and cs:
                mapped[cs] = min(mapped.get(cs, 999), lv)
    out = dict(mapped)
    out.update(scripted)
    out.update(wild)
    out.update(LEVEL_OVERRIDES_B)
    return out


# ---------------------------------------------------------------------------
# The two states

def config_a(world):
    return {
        "name": "A", "maps": world.maps.kanto, "cut": is_cut,
        "drop_flags": DROP_FLAGS, "manual_flags": MANUAL_FLAGS, "manual_vars": MANUAL_VARS,
        "untouched": UNTOUCHED, "set_by_c": SET_BY_DEBUG_C,
        "trainer_skip": TRAINER_SKIP_RE, "rivals": [KANTO_RIVALS],
        "new_game_items": True, "start_money": True,
        # Mewtwo is in the PC (the whole Kanto Pokedex); its cave opens after the title.
        "extra_legendaries": ["LEGENDARY_MEWTWO"],
    }


def config_b(world):
    extra = [world.maps.by_dir[d] for d in sorted(FACILITY_GIFTS_B)]
    kanto_johto = {d["_dir"] for d in world.maps.kanto_all + world.maps.johto + extra}

    def cut(name):
        if name in CUT_LABELS_B or name.startswith(CUT_PREFIXES_B):
            return True
        f = world.scripts.labels[name]["file"]
        if CUT_FILES_B.match(f):
            return True
        mdir = map_dir_of(f)
        if mdir in FACILITY_GIFTS_B:
            return name not in FACILITY_GIFTS_B[mdir]
        return bool(mdir) and mdir not in kanto_johto
    return {
        "name": "B", "maps": world.maps.kanto_all + world.maps.johto + extra, "cut": cut,
        "drop_flags": DROP_FLAGS_B, "manual_flags": dict(MANUAL_FLAGS, **MANUAL_FLAGS_B),
        "manual_vars": dict(MANUAL_VARS, **MANUAL_VARS_B),
        "untouched": {n: r for n, r in UNTOUCHED_B.items() if n not in MANUAL_FLAGS_B and n not in MANUAL_VARS_B},
        "set_by_c": SET_BY_DEBUG_C_B, "init_labels": INIT_LABELS_B,
        "trainer_skip": TRAINER_SKIP_RE_B, "rivals": [KANTO_RIVALS, JOHTO_RIVALS],
        "new_game_items": True, "start_money": True,
        "skip_items": SKIP_ITEMS_B, "exclusive_gifts": EXCLUSIVE_GIFTS_B, "extra_legendaries": [],
    }


class States:
    def __init__(self):
        self.world = World()
        self.sp = Species()
        self.problems = []
        self._state_a()
        self._state_b()

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

    def _state_b(self):
        """Kanto and Johto lines; species of Kanto lines keep their level of state A
        (party or PC)."""
        w, sp = self.world, self.sp
        self.b = Run(w, config_b(w))
        self.dex_b = sp.dex_set({"Kanto", "Johto"})
        self.finals_b = sp.finals(self.dex_b)
        fixed = {s: self.levels_a.level(s) for s in self.kanto if self.levels_a.level(s) is not None}
        fixed.update(self.party_a)
        self.levels_b = Levels(sp, self.dex_b, johto_catch_levels(w, self.b, sp), fixed)
        self.party_b = list(JOHTO_COMPLETE_PARTY)
        self.box_b = self._box(self.finals_b, self.party_b, self.levels_b, "B")
        self.seen_b = self._seen_only(self.b, self.dex_b, {"Kanto", "Johto"})
        self._delta()

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

    def _delta(self):
        """State B as changes on top of state A."""
        a, b = self.a, self.b
        self.flags_b = {n: v for n, v in b.flags.items() if a.flags.get(n) != v}
        self.vars_b = {n: v for n, v in b.vars.items() if a.vars.get(n) != v}
        trainers_a = set(a.trainers)
        self.trainers_b = [t for t in b.trainers if t not in trainers_a]
        if a.rivals[0]["by_starter"] != b.rivals[0]["by_starter"]:
            self.problems.append("state B: Kanto rival battles differ from state A: %s" % b.rivals[0]["by_starter"])
        self.rival_b = b.rivals[1]["by_starter"]
        self.bag_a, self.pc_a = self._split_pc(a.bag, "A")
        if a.option_items:
            self.problems.append("state A: items behind a challenge option need an array of their own: %s"
                                 % sorted(a.option_items))
        bag_ab, pc_ab = self._split_pc(b.bag, "B")
        # Items only a clerk behind a challenge option sells: added only while the option allows it.
        self.option_bag_b = {i: bag_ab.pop(i) for i in sorted(b.option_items) if i in bag_ab}
        flags = set(b.option_items.values())
        if len(flags) > 1:
            self.problems.append("state B: more than one challenge option flag for items: %s" % sorted(flags))
        self.option_flag_b = next(iter(flags)) if flags else "0"
        bag = collections.Counter(bag_ab)
        bag.subtract(collections.Counter(self.bag_a))
        self.bag_add_b = {i: q for i, q in sorted(bag.items()) if q > 0}
        self.bag_remove_b = {i: -q for i, q in sorted(bag.items()) if q < 0}
        pc = collections.Counter(pc_ab)
        pc.subtract(collections.Counter(self.pc_a))
        self.pc_b = {i: q for i, q in sorted(pc.items()) if q > 0}
        if any(q < 0 for q in pc.values()):
            self.problems.append("state B: items of state A's PC missing: %s"
                                 % sorted(i for i, q in pc.items() if q < 0))
        self.money_b = min(b.money, MAX_MONEY)

    def _split_pc(self, bag, name):
        """(bag, PC items) of a state's items: a pocket keeps POCKET_RESERVE free
        slots, the rest of it goes into the PC, first the items only purchases
        and repeatable sources give, highest item number first. Key items and
        HMs stay in the bag."""
        w = self.world
        run = self.a if name == "A" else self.b
        found = set(run.bag) - set(run.once)
        bag, pc = dict(bag), {}
        by_pocket = collections.defaultdict(list)
        for i in bag:
            by_pocket[w.pockets.get(i)].append(i)
        for pocket, items in sorted(by_pocket.items(), key=lambda x: str(x[0])):
            room = w.bag_limits.get(pocket, 0) - POCKET_RESERVE
            movable = sorted((i for i in items if pocket != "POCKET_KEY_ITEMS" and not i.startswith("ITEM_HM")
                              and i not in run.option_items),
                             key=lambda i: (i in found, -w.item_values.get(i, 0)))
            while len(items) > room and movable:
                i = movable.pop(0)
                items.remove(i)
                pc[i] = bag.pop(i)
        return bag, dict(sorted(pc.items()))

    def check(self):
        """Every problem --check reports besides a stale header."""
        out = list(self.problems)
        out += self._check_a()
        out += self._check_b()
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

    @staticmethod
    def _check_pickups(name, run, flags, bag):
        """Every pickup and hidden item of the state's maps collected."""
        out = []
        skip = run.cfg.get("skip_items", {})
        for d in run.maps:
            for o in d.get("object_events") or []:
                found = run.pickup(o)
                if not found or o.get("flag", "0") in ("0", ""):
                    continue
                if not flags.get(o["flag"]):
                    out.append("state %s: pickup %s of %s not collected (%s)" % (name, found[0], d["_dir"], o["flag"]))
                if found[0] not in skip and found[0] not in run.item_removed and bag.get(found[0], 0) <= 0:
                    out.append("state %s: pickup %s of %s not in the bag" % (name, found[0], d["_dir"]))
            for b in d.get("bg_events") or []:
                if b.get("type") == "hidden_item" and b.get("flag") and not flags.get(b["flag"]):
                    out.append("state %s: hidden item %s of %s not collected (%s)"
                               % (name, b["item"], d["_dir"], b["flag"]))
        return out

    def _check_a(self):
        out = ["state A: %s" % p for p in self.a.coverage()]
        out += self._check_mons("A", self.dex_a, self.finals_a, self.party_a, self.box_a)
        out += self._check_pickups("A", self.a, self.a.flags, self.a.bag)
        out += self._check_items("A", self.a, self.bag_a, self.pc_a)
        flags_a = {n for n, v in self.a.flags.items() if v}
        for f in ("FLAG_JOHTO_UNLOCKED", "FLAG_JOHTO_ARRIVAL_DONE"):
            if f in flags_a:
                out.append("state A: %s set; Johto stays locked" % f)
        if int(self.a.vars.get("VAR_JOHTO_HANDOVER", "0"), 0) >= 3:
            out.append("state A: VAR_JOHTO_HANDOVER 3 unlocks Johto")
        if int(self.a.vars.get("VAR_HOENN_ARRIVAL_STATE", "0"), 0) != 0:
            out.append("state A: VAR_HOENN_ARRIVAL_STATE unlocks Hoenn")
        for f in load_fly_flags():
            if f.startswith("FLAG_WORLD_MAP_") and f not in flags_a:
                out.append("state A: fly destination %s not set" % f)
        return out

    def _check_b(self):
        out = ["state B: %s" % p for p in self.b.coverage()]
        out += self._check_mons("B", self.dex_b, self.finals_b, self.party_b, self.box_b)
        flags_ab = {n for n, v in dict(self.a.flags, **self.flags_b).items() if v}
        vars_ab = dict(self.a.vars, **self.vars_b)
        if int(vars_ab.get("VAR_HOENN_ARRIVAL_STATE", "0"), 0) != 0:
            out.append("state B: VAR_HOENN_ARRIVAL_STATE unlocks Hoenn")
        if vars_ab.get("VAR_HOENN_TICKET_STATE") != "1":
            out.append("state B: VAR_HOENN_TICKET_STATE must be 1, Troy waits in Oak's lab")
        if "ITEM_HOENN_TICKET" in self.b.bag:
            out.append("state B: the Hoenn Ticket is in the bag before Troy's scene")
        if "FLAG_JOHTO_UNLOCKED" not in flags_ab:
            out.append("state B: FLAG_JOHTO_UNLOCKED not set")
        for f in sorted(flags_ab):
            m = re.match(r"FLAG_BADGE(\d\d)_GET$", f)
            if m and int(m.group(1)) > 8:
                out.append("state B: %s set; Johto counts its badges in VAR_JOHTO_BADGES" % f)
        for f in load_fly_flags():
            if f not in flags_ab:
                out.append("state B: fly destination %s not set" % f)
        bag_ab = collections.Counter(self.bag_a)
        bag_ab.update(self.bag_add_b)
        bag_ab.subtract(self.bag_remove_b)
        bag_ab.update(self.option_bag_b)
        pc_ab = collections.Counter(self.pc_a)
        pc_ab.update(self.pc_b)
        out += self._check_pickups("B", self.b, dict(self.a.flags, **self.flags_b), bag_ab + pc_ab)
        out += self._check_items("B", self.b, {i: q for i, q in bag_ab.items() if q > 0}, dict(pc_ab))
        # Room for the Hoenn Ticket in the key items pocket.
        limit = self.world.bag_limits["POCKET_KEY_ITEMS"]
        keys = sum(1 for i, q in bag_ab.items() if q > 0 and self.world.pockets.get(i) == "POCKET_KEY_ITEMS")
        if keys >= limit:
            out.append("state B: %d key items leave no room for the Hoenn Ticket (pocket %d)" % (keys, limit))
        # Table entries no gift of the run uses (state B's maps include state A's).
        sites = {label for label, _, _ in self.b.var_gift_sites}
        for table in (VAR_GIFT_TABLES, VAR_GIFT_SKIP):
            for label in sorted(set(table) - sites):
                out.append("%s: listed in %s, but gives no item through a var in the run"
                           % (label, "VAR_GIFT_TABLES" if table is VAR_GIFT_TABLES else "VAR_GIFT_SKIP"))
        for label, arrays in sorted(C_ITEM_SOURCES.items()):
            if label not in self.b.labels:
                out.append("%s: listed in C_ITEM_SOURCES, but the run does not reach it" % label)
            for p, arr in arrays:
                if not c_item_array(self.world.cond, p, arr):
                    out.append("%s: no items in %s of %s (C_ITEM_SOURCES)" % (label, arr, p))
        for flag, (arrays, _) in sorted(FACILITY_ITEMS.items()):
            if self.b.flags.get(flag) != 1:
                out.append("%s: listed in FACILITY_ITEMS, but state B does not set it" % flag)
            for p, pattern in arrays:
                if not any(c_item_array(self.world.cond, p, arr)
                           for arr in c_array_names(self.world.cond, p, pattern)):
                    out.append("%s: no prize arrays %s in %s (FACILITY_ITEMS)" % (flag, pattern.pattern, p))
        maps_b = {d["_dir"] for d in self.b.maps}
        for mdir, entry in sorted(BP_EXCHANGES.items()):
            d = self.world.maps.by_dir.get(mdir)
            if not d:
                out.append("%s: listed in BP_EXCHANGES, but no active map" % mdir)
                continue
            if entry not in maps_b:
                out.append("%s: listed in BP_EXCHANGES, but state B has no map %s" % (mdir, entry))
            entry_id = self.world.maps.by_dir.get(entry, {}).get("id")
            linked = ({c.get("map") for c in d.get("connections") or []}
                      | {e.get("dest_map") for e in d.get("warp_events") or []})
            if entry_id not in linked:
                out.append("%s: BP_EXCHANGES opens it from %s, but no connection or warp leads there"
                           % (mdir, entry))
        return out

    def _check_items(self, name, run, bag, pc):
        """Every item of the run in the bag or the PC, pockets and PC not over
        their slots, every source of the once items resolved."""
        w = self.world
        out = ["state %s: %s" % (name, p) for p in run.once_problems]
        for i in sorted(run.bag):
            if bag.get(i, 0) + pc.get(i, 0) < run.bag[i]:
                out.append("state %s: %s missing in bag and PC" % (name, i))
            if w.pockets.get(i) not in w.bag_limits:
                out.append("state %s: %s has no pocket of this build" % (name, i))
        used = collections.Counter(w.pockets.get(i) for i in bag)
        for pocket, n in sorted(used.items(), key=lambda x: str(x[0])):
            if pocket in w.bag_limits and n > w.bag_limits[pocket]:
                out.append("state %s: %d items in %s (%d slots)" % (name, n, pocket, w.bag_limits[pocket]))
        room = w.cond.value("PC_ITEMS_COUNT") - len(c_item_array(w.cond, "src/player_pc.c", "sNewGamePCItems"))
        if len(pc) > room:
            out.append("state %s: %d items for the PC, %d slots free" % (name, len(pc), room))
        return out


# ---------------------------------------------------------------------------
# Headers

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
            ["{ %s, %d }" % (i, q) for i, q in states.bag_a.items()])
    w("// PC item storage: what does not fit into the bag's pockets.")
    c_array(w, "static const struct KantoCompleteItem sKantoCompletePcItems[] =",
            ["{ %s, %d }" % (i, q) for i, q in states.pc_a.items()])
    w("// Party: the chosen starter's final stage first.")
    c_array(w, "static const struct KantoCompleteMon sKantoCompleteParty[] =",
            ["{ %s, %d }" % (s, lv) for s, lv in states.party_a])
    w("// PC: the other final stages of the Kanto lines (every branch).")
    c_array(w, "static const struct KantoCompleteMon sKantoCompleteMons[] =", ["{ %s, %d }" % m for m in states.box_a])
    w("// Pokedex, seen and caught: every stage of the Kanto lines.")
    c_array(w, "static const u16 sKantoCompleteDex[] =", sorted(states.dex_a, key=states.sp.num))
    c_array(w, "static const u16 sKantoCompleteSeenOnly[] =", states.seen_a)
    return "\n".join(out).rstrip("\n") + "\n"


def render_b(states):
    out = []
    w = out.append
    w("// Generated by tools/make_debug_states.py - do not edit.")
    w("// State after the first Johto Hall of Fame for the debug menu's \"Hoenn Test\",")
    w("// applied on top of debug_kanto_complete.h (include that first).")
    w("// Regenerate: python3 tools/make_debug_states.py (check: --check).")
    w("")
    w("#define JOHTO_COMPLETE_JOHTO_STARTER %d  // VAR_JOHTO_STARTER_MON: 0 Chikorita, 1 Cyndaquil, 2 Totodile"
      % JOHTO_COMPLETE_JOHTO_STARTER)
    w("#define JOHTO_COMPLETE_MONEY %d  // start money and every prize of both regions" % states.money_b)
    w("")
    c_array(w, "static const u16 sJohtoCompleteFlagsSet[] =", sorted(n for n, v in states.flags_b.items() if v))
    c_array(w, "static const u16 sJohtoCompleteFlagsClear[] =", sorted(n for n, v in states.flags_b.items() if not v))
    c_array(w, "static const struct KantoCompleteVar sJohtoCompleteVars[] =",
            ["{ %s, %s }" % (n, v) for n, v in sorted(states.vars_b.items())])
    c_array(w, "static const u16 sJohtoCompleteTrainers[] =", states.trainers_b)
    rivals = states.rival_b
    w("// Index: VAR_JOHTO_STARTER_MON.")
    w("static const u16 sJohtoCompleteRivalTrainers[%d][%d] =" % (len(rivals), len(rivals[0])))
    w("{")
    for i, r in enumerate(rivals):
        w("    [%d] = { %s }," % (i, ", ".join(r)))
    w("};")
    w("")
    c_array(w, "static const struct KantoCompleteItem sJohtoCompleteBag[] =",
            ["{ %s, %d }" % (i, q) for i, q in states.bag_add_b.items()])
    w("// Items of state A used up later.")
    c_array(w, "static const struct KantoCompleteItem sJohtoCompleteBagRemove[] =",
            ["{ %s, %d }" % (i, q) for i, q in states.bag_remove_b.items()])
    w("// PC item storage: what does not fit into the bag's pockets.")
    c_array(w, "static const struct KantoCompleteItem sJohtoCompletePcItems[] =",
            ["{ %s, %d }" % (i, q) for i, q in states.pc_b.items()])
    w("// Sold only by a clerk a challenge option hides: added while this flag is clear.")
    w("#define JOHTO_COMPLETE_OPTION_FLAG %s" % states.option_flag_b)
    c_array(w, "static const struct KantoCompleteItem sJohtoCompleteOptionBag[] =",
            ["{ %s, %d }" % (i, q) for i, q in states.option_bag_b.items()])
    c_array(w, "static const struct KantoCompleteMon sJohtoCompleteParty[] =",
            ["{ %s, %d }" % (s, lv) for s, lv in states.party_b])
    w("// PC: the other final stages of the Kanto and Johto lines (every branch).")
    c_array(w, "static const struct KantoCompleteMon sJohtoCompleteMons[] =", ["{ %s, %d }" % m for m in states.box_b])
    w("// Pokedex, seen and caught: every stage of the Kanto and Johto lines.")
    c_array(w, "static const u16 sJohtoCompleteDex[] =", sorted(states.dex_b, key=states.sp.num))
    c_array(w, "static const u16 sJohtoCompleteSeenOnly[] =", states.seen_b)
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
        if rel in ("src/debug.c", HEADER, HEADER_B):
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
    for name, run in (("A", states.a), ("B", states.b)):
        sets = sum(1 for v in run.flags.values() if v)
        print("state %s run: flags set %d, clear %d, vars %d, trainers %d, bag entries %d, money %d, maps %d, labels %d"
              % (name, sets, len(run.flags) - sets, len(run.vars), len(run.trainers), len(run.bag), run.money,
                 len(run.maps), len(run.labels)))
    print("state A: Pokedex %d, party %d, PC %d, seen only %d"
          % (len(states.dex_a), len(states.party_a), len(states.box_a), len(states.seen_a)))
    print("state B (on top of A): flags %d, vars %d, trainers %d, bag +%d -%d, money %d; Pokedex %d, party %d, "
          "PC %d, seen only %d" % (len(states.flags_b), len(states.vars_b), len(states.trainers_b),
                                   len(states.bag_add_b), len(states.bag_remove_b), states.money_b,
                                   len(states.dex_b), len(states.party_b), len(states.box_b), len(states.seen_b)))
    for name, run, bag, pc in (("A", states.a, states.bag_a, states.pc_a), ("B", states.b, None, states.pc_b)):
        if bag is None:
            bag = collections.Counter(states.bag_a)
            bag.update(states.bag_add_b)
            bag.subtract(states.bag_remove_b)
            bag.update(states.option_bag_b)
            bag = {i: q for i, q in bag.items() if q > 0}
        used = collections.Counter(states.world.pockets.get(i) for i in bag)
        print("state %s items: %d, %d of them once (purchases, repeatable sources); pockets %s; PC items %s"
              % (name, len(run.bag), len(run.once),
                 ", ".join("%s %d/%d" % (p[len("POCKET_"):], used[p], n)
                           for p, n in sorted(states.world.bag_limits.items())),
                 ", ".join("%s %d" % x for x in pc.items()) or "none"))
    for name, run in (("A", states.a), ("B", states.b)):
        for w in run.warnings:
            print("warning (state %s): %s" % (name, w), file=sys.stderr)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--check", action="store_true",
                    help="exit 1 if a header is stale or a flag/var of the regions is not covered")
    ap.add_argument("--overlap", action="store_true", help="report flags/vars of state A shared with Johto or Hoenn")
    ap.add_argument("--levels", action="store_true", help="print how each PC level was derived")
    args = ap.parse_args()
    states = States()
    if args.overlap:
        sys.exit(overlap(states.a))
    if args.levels:
        for name, box, levels in (("A", states.box_a, states.levels_a), ("B", states.box_b, states.levels_b)):
            for s, lv in box:
                print("%s %-30s %3d  %s" % (name, s, lv, levels.how.get(s, "")))
        return
    texts = {HEADER: render(states), HEADER_B: render_b(states)}
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
