#!/usr/bin/env python3
"""Durchspiel-Simulator: static, monotonic progression model of Origin Jade.

Plays the jade build (Kanto -> Johto -> Hoenn) without an emulator on the
active maps (game_version "hns") and reports in which order the story
milestones become reachable, where progress stops, and which maps, items,
trainers, gifts and static encounters stay out of reach.

Usage:
    python3 -I tools/simulate_progress.py                 # report to stdout
    python3 -I tools/simulate_progress.py --out DIR       # report.txt + report.json
    python3 -I tools/simulate_progress.py --hoenn-ticket  # start with the Hoenn Ticket (what-if)
    python3 -I tools/simulate_progress.py --force-warp MAP_CELADON_CITY:0
    python3 -I tools/simulate_progress.py --give-item ITEM_POKE_FLUTE --set-flag FLAG_X
    python3 -I tools/simulate_progress.py --diff old/report.json new/report.json

Options:
    --hoenn-ticket       start with the Hoenn Ticket received (ITEM_HOENN_TICKET,
                         VAR_HOENN_TICKET_STATE 3); not needed for the main path,
                         Troy hands it over in Oak's lab (D-047)
    --force-warp M:N     warp N of map M triggers from its tile or any neighbour
                         (what-if test for broken warp tiles, no data change)
    --give-item ITEM     start with ITEM (what-if)
    --set-flag FLAG      start with FLAG set (what-if)
    --set-var VAR=N      N is a possible value of VAR from the start (what-if,
                         e.g. VAR_HOENN_LICENSES=63 to look past a stop)
    --strict-specials    unmodelled specials return 0 instead of "any value"
    --max-waves N        stop after N waves (default 400)
    --out DIR            write report.txt and report.json into DIR
    --compare JSON       append what changed against an older report.json
                         (e.g. base vs. a branch with fixes)
    --diff OLD NEW       only compare two report.json files, no simulation
    --quiet              no progress lines on stderr

Exit status: 0 if the Hoenn title is reachable, 1 otherwise.

Model (an upper bound of what a player can reach):
  * State: every flag holds the set of values it may have (clear/set), every
    var the set of values it may have (capped; counters saturate one above
    the largest constant any script compares them with), items and trainer
    flags like flags. Effects only add possibilities, so the fixpoint is
    monotonic: a write never removes an earlier value.
  * Start: the new-game state of src/new_game.c (EventScript_ResetAllMapFlags
    HnS and Frlg) in Pallet Town, player's room (6,6).
  * Terrain: map.bin collision and elevation, metatile behaviours (ledges
    one way, directional walls, doors from the south, arrow/stair/step
    warps, Surf mounts onto water with an elevation mismatch from elevation
    3, waterfalls up only with Waterfall, Dive and emerge connections,
    setdivewarp where a map has no such connection, falls through holes
    and cracked floors to the setholewarp map),
    map connections, warps (MAP_DYNAMIC returns where the player came from
    or goes to a setdynamicwarp target), setmetatile from scripts,
    setmaplayoutindex (every layout a script may set counts as possible;
    each tile takes its most permissive variant).
  * Field moves follow D-008 (src/field_move.c): Kanto badge flags on Kanto
    map sections, Johto permits (VAR_JOHTO_PERMITS) on Johto sections
    except Routes 26/27 and Tohjo Falls, Hoenn licenses (VAR_HOENN_LICENSES)
    on Hoenn sections, HnS badge thresholds elsewhere. A party member that
    knows the move is assumed once the HM item is owned.
  * Objects: visible while their flag may be clear, unless the map's
    ON_TRANSITION script sets it before any branch (light sprites are no
    objects); they block their tile only if they can never be hidden or
    removed and do not wander. Cut trees, rocks, whirlpools and NPCs
    disappear when one of their script paths runs removeobject; boulders
    give way once FLAG_SYS_USE_STRENGTH may be set on that map; statues of
    the rotating tile puzzles (Mossdeep Gym, Trick House 7) stop blocking
    once a switch can move them.
  * Scripts: data/event_scripts.s with every .include and #if/.if resolved
    for the jade build. Every feasible path of a triggered script is
    followed (path-sensitive, with a budget and a coarse fallback):
    goto/call/return, all goto_if/call_if forms, switch/case, flags, vars,
    items, trainer battles (always won), warps, givemon, wild battles,
    marts, removeobject/setobjectxyperm, moverotatingtileobjects (one
    shift), setmetatile, specials (badges,
    permits, licenses, field-move permission modelled; others scanned in C
    for FlagSet/FlagClear/VarSet, their result is "any value" and every
    branch on it is reported).
  * Triggers: object scripts (adjacent, across counters, trainer sight),
    signs and hidden items (adjacent), metatile scripts that matter for
    progress (METATILE_SCRIPTS: Trick House door), coord events (tile
    reached and the trigger value possible; a coord event blocks its tile
    while every path pushes the player back without changing the trigger),
    map scripts (ON_TRANSITION, ON_LOAD, ON_RESUME, ON_RETURN_TO_FIELD,
    ON_DIVE_WARP always, ON_FRAME/ON_WARP_INTO tables while the value is
    possible).

Limits (read the results with these in mind):
  * Upper bound: whatever the report calls unreachable cannot be reached
    (modulo model errors); what it calls reachable may still need an order
    the game forbids, a battle the player cannot win, money, luck or
    trading. Order-dependent softlocks (one-way trips, items lost before
    use, state set backwards) are not found.
  * Fly, Teleport, Dig, Escape Rope and whiteouts are not modelled: they
    only return to places already reached. Bikes, currents, ice, muddy
    slopes and rotating gates are treated as freely passable.
  * Wandering NPCs never block. Trainer sight ignores walls. Elevation is
    ignored when talking to objects. On elevation-0 tiles the last
    non-zero elevation (used by the game for warps and coord events) is
    not tracked: warps of any elevation may trigger there, coord events
    may fire but never count as a sure block.
  * Alternative layouts (tides, day/night, Sky Pillar, Mirage Island) are
    a union: a tile is as passable as its best layout, whatever the time.
  * "Verwaist" (orphaned) means no warp, connection, script or C file
    names the map or its layout; C code that computes map numbers (Battle
    Pyramid floors) or contest warps is not seen.
  * C code outside the scanned specials (battle results, Pokedex counts,
    time of day, randomizer) is "any value".
"""

import argparse
import bisect
import collections
import json
import os
import re
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import check_flags  # noqa: E402
import oj_world as W  # noqa: E402


# ---------------------------------------------------------------------------
# Value domain
# ---------------------------------------------------------------------------

class _Any:
    """Any value of a var (top of the lattice)."""

    def __repr__(self):
        return "ANY"


ANY = _Any()
ZERO = frozenset([0])
MAX_VALUES = 64
FLAG_CLEAR = 1
FLAG_SET = 2


def vs_union(a, b, limit=MAX_VALUES):
    if a is ANY or b is ANY:
        return ANY
    u = a | b
    return ANY if len(u) > limit else u


def vs_iter_ints(s):
    return [v for v in s if isinstance(v, int)]


# Condition codes of goto_if/call_if (sScriptConditionTable).
COND_TABLE = {
    0: (1, 0, 0),  # lt
    1: (0, 1, 0),  # eq
    2: (0, 0, 1),  # gt
    3: (1, 1, 0),  # le
    4: (0, 1, 1),  # ge
    5: (1, 0, 1),  # ne
}
COND_SUFFIX = {"lt": 0, "eq": 1, "gt": 2, "le": 3, "ge": 4, "ne": 5}
RE_IF_FLAG = re.compile(r"(v?)(goto|call)_if_(set|unset)$")
RE_IF_VAR = re.compile(r"(v?)(goto|call)_if_(lt|eq|gt|le|ge|ne)$")
RE_IF_TRAINER = re.compile(r"(goto|call)_if_(defeated|not_defeated)$")

# Specials that set a fixed warp destination in C: name -> (dest if
# VAR_0x8004 == 0, dest otherwise), each (map, x, y).
SPECIAL_WARPS = {
    "CableCarWarp": (("MAP_MT_CHIMNEY_CABLE_CAR_STATION", 6, 4),
                     ("MAP_ROUTE112_CABLE_CAR_STATION", 6, 4)),  # src/field_specials.c
}

# Commands after which the next instruction is not reached by falling through.
FALLTHROUGH_END = ("end", "return", "goto", "gotostd", ".byte", ".2byte", ".4byte")

# Step callbacks that write a var on every step: callback -> vars.
STEP_CALLBACK_VARS = {
    "STEP_CB_SOOTOPOLIS_ICE": ("VAR_ICE_STEP_COUNT",),
}

# Layouts on which trainerhill_inhoennhill returns TRUE (IsHnsTrainerHill).
HOENN_TRAINER_HILL_LAYOUTS = {"LAYOUT_TRAINER_HILL_ENTRANCE", "LAYOUT_TRAINER_HILL_1F", "LAYOUT_TRAINER_HILL_2F",
                              "LAYOUT_TRAINER_HILL_3F", "LAYOUT_TRAINER_HILL_4F", "LAYOUT_TRAINER_HILL_ROOF"}

# Field moves: HM item, rule tables (D-008, src/field_move.c).
FIELD_MOVES = {
    "cut": ("ITEM_HM_CUT", 2, 2, 0, 0),
    "flash": ("ITEM_HM_FLASH", 1, 1, None, None),
    "rock_smash": ("ITEM_HM_ROCK_SMASH", 6, 1, 1, 1),
    "strength": ("ITEM_HM_STRENGTH", 4, 3, 2, 2),
    "surf": ("ITEM_HM_SURF", 5, 4, 3, 3),
    "fly": ("ITEM_HM_FLY", 3, 5, None, None),
    "dive": ("ITEM_HM_DIVE", 7, 7, 4, 4),
    "waterfall": ("ITEM_HM_WATERFALL", 7, 8, 5, 5),
}
# (item, Kanto badge, HnS default badge, Johto permit bit, Hoenn license bit)
FIELD_MOVE_IDS = {"FIELD_MOVE_CUT": "cut", "FIELD_MOVE_FLASH": "flash", "FIELD_MOVE_ROCK_SMASH": "rock_smash",
                  "FIELD_MOVE_STRENGTH": "strength", "FIELD_MOVE_SURF": "surf", "FIELD_MOVE_FLY": "fly",
                  "FIELD_MOVE_DIVE": "dive", "FIELD_MOVE_WATERFALL": "waterfall"}
MOVE_TO_FIELD = {"MOVE_CUT": "cut", "MOVE_FLASH": "flash", "MOVE_ROCK_SMASH": "rock_smash",
                 "MOVE_STRENGTH": "strength", "MOVE_SURF": "surf", "MOVE_FLY": "fly",
                 "MOVE_DIVE": "dive", "MOVE_WATERFALL": "waterfall"}
MOVE_NAMES_DE = {"cut": "Zerschneider", "flash": "Blitz", "rock_smash": "Zertrümmerer",
                 "strength": "Stärke", "surf": "Surfer", "fly": "Fliegen", "dive": "Taucher",
                 "waterfall": "Kaskade"}

DIRS = {"S": (0, 1), "N": (0, -1), "W": (-1, 0), "E": (1, 0)}
MOVE_VEC = {"up": (0, -1), "down": (0, 1), "left": (-1, 0), "right": (1, 0),
            "northeast": (1, -1), "northwest": (-1, -1), "southeast": (1, 1), "southwest": (-1, 1)}
MOVE_STEP = re.compile(r"^(?:walk|walk_slow|walk_slower|walk_slowest|walk_fast|walk_faster|walk_fastest|slide|"
                       r"player_run|ride_water_current|jump|jump_2|walk_diag|walk_slow_diag)_"
                       r"(up|down|left|right|northeast|northwest|southeast|southwest)$")
CONN_DIR = {"S": "down", "N": "up", "W": "left", "E": "right"}

PLAYER_IDS = {"OBJ_EVENT_ID_PLAYER", "LOCALID_PLAYER", "255"}

# Graphics that TrySpawnObjectEvents shows as a light sprite, not as an
# object event: they never block and cannot be talked to.
LIGHT_GFX = {"OBJ_EVENT_GFX_LIGHT_SPRITE", "OBJ_EVENT_GFX_LIGHT_HNS", "OBJ_EVENT_GFX_POKE_CENTER_LIGHT_HNS",
             "OBJ_EVENT_GFX_MART_LIGHT_HNS", "OBJ_EVENT_GFX_SMALL_LIGHT_HNS"}

# Commands that end a straight run of script code.
FLOW_CMDS = ("goto", "call", "return", "end", "switch", "case", "jump", "waitstate", "warp")

# Maps where the engine puts an arriving player on foot even on water.
SEAFOAM_ON_FOOT = {"MAP_SEAFOAM_ISLANDS_B3F", "MAP_SEAFOAM_ISLANDS_B4F"}

# Metatile behaviour predicate -> script the engine runs when the player
# faces such a tile and presses A (GetInteractedMetatileScript).
METATILE_SCRIPTS = [
    ("IsTrickHousePuzzleDoor", "Route110_TrickHousePuzzle_EventScript_Door"),
]

# Multiplayer rooms: only reachable through link specials, not part of the model.
LINK_MAPS = re.compile(r"UnionRoom|TradeCenter|BattleColosseum|RecordCorner|LinkContestRoom")


def is_link_map(m):
    return bool(LINK_MAPS.search(m.name))

MAP_SCRIPT_ALWAYS = ("MAP_SCRIPT_ON_TRANSITION", "MAP_SCRIPT_ON_LOAD", "MAP_SCRIPT_ON_RESUME",
                     "MAP_SCRIPT_ON_RETURN_TO_FIELD", "MAP_SCRIPT_ON_DIVE_WARP")
MAP_SCRIPT_TABLES = ("MAP_SCRIPT_ON_FRAME_TABLE", "MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE")

WARP_CMDS = ("warp", "warpsilent", "warpdoor", "warpteleport", "warpwhitefade", "warpspinenter",
             "warpmossdeepgym", "warphole")
RESULT_CMDS_ANY = {
    "checkitemspace", "checkpcitem", "checkitemtype", "checkmoney", "checkdecor", "checkdecorspace",
    "checkplayergender", "checkspecies", "checkspecies_choose", "getpartysize", "getcaughtmon",
    "getseenmon", "checknuzlocke", "checkrandomizer", "yesnobox", "multichoice", "multichoicedefault",
    "multichoicegrid", "dynmultichoice", "_dynmultichoice", "dynmultistack", "drawboxtext",
    "checkpartymonlevel", "canhypertrain", "hasgigantamaxfactor", "checkteratype", "chooseboxmon",
    "checkmodernfatefulencounter", "checkfollowernpc", "getpokenewsactive", "showelevmenu",
    "checkobjectat", "comparehiddenvar", "getbraillestringwidth", "istmrelearneractive",
    "giveegg", "giveoddegg", "givenamedmon", "baobacheckmon",
}
OUT_VAR_CMDS = {  # command -> indices of output var args
    "checkcoins": (0,), "getplayerxy": (0, 1), "getobjectxy": (2, 3), "getobjecttemplatexy": (2, 3),
    "getobjectcurrentxy": (2, 3), "getobjectfacingdirection": (1,), "getdirectiontoface": (0,),
    "isfollowerfieldmoveuser": (0,), "getdifficulty": (0,), "getmoverelearnerstate": (0,),
}
IGNORED_CMDS = {
    "lock", "lockall", "release", "releaseall", "faceplayer", "msgbox", "message", "waitmessage",
    "closemessage", "waitbuttonpress", "applymovement2", "waitmovement", "waitmovementall", "delay",
    "playse", "waitse", "playfanfare", "waitfanfare", "playbgm", "savebgm", "fadedefaultbgm",
    "fadenewbgm", "fadeoutbgm", "fadeinbgm", "playmoncry", "waitmoncry", "fadescreen",
    "fadescreenspeed", "fadescreenswapbuffers", "turnobject", "turnvobject", "createvobject",
    "setobjectmovementtype", "addobject", "showobjectat", "hideobjectat", "set_visible",
    "set_invisible", "textcolor", "bufferspeciesname", "bufferitemname", "bufferitemnameplural",
    "buffermovename", "buffernumberstring", "bufferstdstring", "bufferstring", "bufferpartymonnick",
    "bufferdecorationname", "bufferboxname", "buffertrainerclassname", "buffertrainername",
    "buffercontestname", "bufferleadmonspeciesname", "buffermoncategory", "bufferlivemonnickname",
    "showmonpic", "hidemonpic", "showmoneybox", "hidemoneybox", "updatemoneybox", "showcoinsbox",
    "hidecoinsbox", "updatecoinsbox", "removemoney", "addmoney", "removecoins", "addcoins",
    "waitstate", "opendoor", "closedoor", "waitdooranim", "setdooropen", "setdoorclosed",
    "setweather", "doweather", "resetweather", "setflashlevel", "animateflash", "setrespawn",
    "incrementgamestat", "dofieldeffect", "setfieldeffectargument",
    "waitfieldeffect", "dofieldeffectsparkle", "setberrytree", "register_matchcall", "famechecker",
    "erasebox", "drawbox", "messageautoscroll", "messageinstant", "braillemsgbox", "braillemessage",
    "braillemessage_wait", "closebraillemessage", "brailleformat", "pokenavcall", "setspeaker",
    "hideplayer", "showplayer", "setobjectsubpriority", "resetobjectsubpriority", "setmonmove",
    "setmonmetlocation", "playslotmachine", "showcontestpainting", "vmessage", "vbuffermessage",
    "vbufferstring", "setvaddress", "loadword", "loadbyte", "setptr", "loadbytefromptr",
    "setptrbyte", "copylocal", "copybyte", "nop", "nop1", "dotimebasedevents", "gettime",
    "gettimeofday", "initclock", "setmodernfatefulencounter", "trywondercardscript",
    "setmysteryeventstatus", "helpwindow", "showhelpwindow", "hidehelpwindow", "loadhelp",
    "unloadhelp", "signmsg", "normalmsg", "lock_facing_direction", "unlock_facing_direction",
    "hidefollower", "updatefollowingmon", "getfolloweraction", "setfollowernpc", "createfollowernpc",
    "destroyfollowernpc", "facefollowernpc", "hidefollowernpc", "changefollowerbattler",
    "setdynamicaifunc", "setdynamicswitchaifunc", "settotemboost", "setstartingstatus",
    "setmoverelearnerstate", "showitemdescription", "showberrydescription", "hideitemdescription",
    "pausefakertc", "resumefakertc", "togglefakertc", "addtime", "adddays", "addhours",
    "addminutes", "fwdtime", "fwdweekday", "forcesave", "stoporasdowsing", "setwilddoubleflag",
    "cant_see", "cant_see_if", "cant_see_if_set", "cant_see_if_unset", "cant_see_if_lt",
    "cant_see_if_eq", "cant_see_if_gt", "cant_see_if_le", "cant_see_if_ge", "cant_see_if_ne",
    "cant_see_if_trainerflag_set", "cant_see_if_trainerflag_unset", "selectapproachingtrainer",
    "lockfortrainer", "calculatemonstats", "setescapewarp", "turnrotatingtileobjects",
    "freerotatingtilepuzzle", "move_tutor_dummy",
    "increasedifficulty", "decreasedifficulty", "setdifficulty", "setstatus1", "setko",
    "setteratype", "hypertrain", "togglegigantamaxfactor", "tryspecialevo", "addelevmenuitem",
    "jump_in_place_down", "remove5mons", "deleteparty", "removegenericmon", "removenamedmon",
    "vsseeker_rematchid", "frontier_set", "frontier_get", "applymovement_dummy", "givebp",
    "givedecoration", "adddecoration", "removedecoration", "setcaughtmon", "setseenmon",
    "setwildbattleshiny_dummy", "multi_2_vs_2", "endram", "returnram", "removeitem", "removeallitem",
    "copyobjectxytoperm", "putitemaway", "msgreceiveditem",
}
STD_NAMES = {0: "STD_OBTAIN_ITEM", 1: "STD_FIND_ITEM", 5: "MSGBOX_YESNO"}

# Specials whose result is known to be "any value" (player choice, battle
# result, luck, Pokedex size) and need no report.
KNOWN_ANY_SPECIALS = {
    "GetBattleOutcome", "ShouldTryRematchBattle", "IsTrainerReadyForRematch", "GetPlayerFacingDirection",
    "CountPartyNonEggMons", "CalculatePlayerPartyCount", "CountPartyAliveNonEggMons",
    "CountPartyAliveNonEggMons_IgnoreVar0x8004Slot", "GetFrlgPokedexCount", "ScriptGetPokedexInfo",
    "ScriptGetPartyMonSpecies", "GetLeadMonFriendshipScore", "GetLeadMonFriendship", "GetMaxPartySize",
    "ScriptCheckFreePokemonStorageSpace", "GetSelectedMonNicknameAndSpecies", "GetTradeSpecies",
    "GetInGameTradeSpeciesInfo", "IsNuzlockeNicknamingActive", "GetPlayerAvatarBike", "IsBadEggInParty",
    "DoesPlayerPartyContainSpecies", "PlayerHasBerries", "GetDaycareState", "CheckItemHandoverPointless",
    "IsWirelessAdapterConnected", "IsEnoughForCostInVar0x8005", "GetSlotMachineId", "HasEnoughBerryPowder",
    "IsPokerusInParty", "ChooseMonForMoveTutor", "ChooseMonForMoveRelearner", "ChoosePartyMon",
    "GetNumLevelsGainedFromDaycare", "TakePokemonFromDaycare", "GetNumFansOfPlayerInTrainerFanClub",
    "IsFanClubMemberFanOfPlayer", "Script_IsFanClubMemberFanOfPlayer", "IsPartyLimitChallengeActive",
    "IsPokecenterChallengeActivated", "GetWeekCount", "IsLegendaryAvailable",
}


# ---------------------------------------------------------------------------
# Game state (may-sets)
# ---------------------------------------------------------------------------

class State:
    def __init__(self):
        self.flags = {}
        self.vars = {}
        self.items = {}
        self.trainers = set()
        self.removed = set()        # (map_id, obj index) removable by a script
        self.positions = collections.defaultdict(set)   # (map_id, idx) -> extra (x, y)
        self.overrides = collections.defaultdict(lambda: collections.defaultdict(set))
        self.dyn_warps = collections.defaultdict(set)  # map -> {(map_id, warp_id, x, y)}
        self.dive_warps = collections.defaultdict(set)
        self.hole_maps = collections.defaultdict(set)  # map -> maps setholewarp names
        self.seeds = set()          # (map_id, warp_id, x, y) script arrivals
        self.layouts = collections.defaultdict(set)

    def flag(self, key):
        return self.flags.get(key, FLAG_CLEAR)

    def var(self, key):
        return self.vars.get(key, ZERO)

    def item(self, name):
        return self.items.get(name, FLAG_CLEAR)

    def trainer(self, t):
        return (FLAG_CLEAR | FLAG_SET) if t in self.trainers else FLAG_CLEAR


# ---------------------------------------------------------------------------
# Effects of one script run
# ---------------------------------------------------------------------------

class Effects:
    def __init__(self):
        self.flags = {}
        self.vars = {}
        self.items = {}
        self.trainers = {}
        self.removed = set()
        self.positions = collections.defaultdict(set)
        self.overrides = collections.defaultdict(lambda: collections.defaultdict(set))
        self.dyn_warps = collections.defaultdict(set)
        self.dive_warps = collections.defaultdict(set)
        self.hole_maps = collections.defaultdict(set)
        self.holes = set()          # (dest map, (dx, dy)) of warphole, relative to the script start
        self.seeds = {}
        self.layouts = collections.defaultdict(set)
        self.where = {}             # (kind, key, value) -> instruction index
        self.gifts = []
        self.statics = []
        self.reads = set()
        self.executed = set()
        self.unknown_specials = collections.defaultdict(set)
        self.branch_specials = collections.defaultdict(set)
        self.unknown_cmds = collections.Counter()
        self.infeasible = {}        # instr index -> text
        self.passing = False
        self.player_moves = set()   # final (dx, dy) of scripted player movement
        self.paths = 0
        self.coarse = False
        self.final_overlays = []

    def write_flag(self, key, value, idx):
        bit = FLAG_SET if value else FLAG_CLEAR
        self.flags[key] = self.flags.get(key, 0) | bit
        self.where.setdefault(("f", key, value), idx)

    def write_var(self, key, values, idx, limit=MAX_VALUES):
        self.vars[key] = vs_union(self.vars.get(key, frozenset()), values, limit)
        if values is not ANY:
            for v in values:
                self.where.setdefault(("v", key, v), idx)

    def give_item(self, item, idx):
        self.items.setdefault(item, idx)

    def defeat(self, t, idx):
        self.trainers.setdefault(t, idx)


class Budget(Exception):
    pass


class Path:
    __slots__ = ("pc", "ret", "ov", "cmp", "moved", "warped", "wrote_trigger", "origin", "last_special", "disp")

    def __init__(self, pc):
        self.pc = pc
        self.ret = ()
        self.ov = {}
        self.cmp = None
        self.moved = False
        self.warped = False
        self.wrote_trigger = False
        self.origin = {}
        self.last_special = None
        self.disp = ()             # unit steps of scripted player movement

    def fork(self):
        p = Path(self.pc)
        p.ret = self.ret
        p.ov = dict(self.ov)
        p.cmp = self.cmp
        p.moved = self.moved
        p.warped = self.warped
        p.wrote_trigger = self.wrote_trigger
        p.origin = dict(self.origin)
        p.last_special = self.last_special
        p.disp = self.disp
        return p


# ---------------------------------------------------------------------------
# Simulator
# ---------------------------------------------------------------------------

class Simulator:
    def __init__(self, args, log):
        self.args = args
        self.log = log
        t0 = time.time()
        self.world = W.World()
        self.macros = self.world.macros
        self.scripts = W.ScriptDB(self.macros)
        self.items_db = W.Items()
        self.cfuncs = W.CFunctions()
        self.values = check_flags.resolve_all()
        self.beh = self.world.behaviors
        self.log("Daten geladen in %.1fs (%d Skriptbefehle, %d Labels)" % (
            time.time() - t0, len(self.scripts.instrs), len(self.scripts.labels)))
        self._init_constants()
        self._init_behaviors()
        self._static_scan()
        self.state = State()
        self.mapinfo_cache = {}
        self.cache = {}
        self.readers = collections.defaultdict(set)
        self.first = {}                 # milestone key -> (wave, source)
        self.region_first = {}
        self.map_first = {}
        self.map_via = {}          # map -> how it was first entered (see Explorer.push)
        self.seed_where = {}       # script warp target -> instruction index
        self.executed = set()
        self.unknown_specials = collections.defaultdict(set)
        self.branch_specials = collections.defaultdict(set)
        self.unknown_cmds = collections.Counter()
        self.infeasible = {}
        self.gift_runs = {}
        self.static_runs = {}
        self.coarse_entries = set()
        self.water_walk = collections.Counter()
        self.void_warps = {}
        self.wave = 0
        self.notes = []
        self.forced_warps = collections.defaultdict(set)
        for spec in args.force_warp or []:
            mid, _, n = spec.partition(":")
            self.forced_warps[mid].add(int(n))

    # -- milestones -----------------------------------------------------
    def note_first(self, key, idx, source):
        if key in self.first:
            return
        self.first[key] = (self.wave, idx, source)

    def note_var(self, k, old, new, eff, source):
        """Milestones hidden in bitmask vars."""
        if k in (self.v_johto_badges, self.v_hoenn_badges, self.v_permits, self.v_licenses):
            for bit in range(8):
                def has(vals):
                    return vals is ANY or any(isinstance(v, int) and v & (1 << bit) for v in vals)
                if has(new) and not has(old):
                    idx = None
                    if new is not ANY:
                        for v in new:
                            if isinstance(v, int) and v & (1 << bit):
                                idx = eff.where.get(("v", k, v))
                                if idx is not None:
                                    break
                    self.note_first(("bit", k, bit), idx, source)

    # -- constants ------------------------------------------------------
    def _init_constants(self):
        v = self.values
        self.temp_flags = {n for k, n in v.items() if k.startswith("FLAG_TEMP_")}
        self.temp_vars = {n for k, n in v.items() if k.startswith("VAR_TEMP_")}
        self.special_var_start = v.get("SPECIAL_VARS_START", 0x8000)
        self.flag_names = {}
        for k, n in sorted(v.items()):
            if k.startswith("FLAG_"):
                self.flag_names.setdefault(n, k)
        self.var_names = {}
        for k, n in sorted(v.items()):
            if k.startswith("VAR_"):
                self.var_names.setdefault(n, k)
        self.trainer_names = {}
        for k, n in sorted(v.items()):
            if k.startswith("TRAINER_") and not k.startswith("TRAINER_FLAGS") and not k.startswith("TRAINER_TYPE"):
                self.trainer_names.setdefault(n, k)
        self.k_badges = [self.flag_key("FLAG_BADGE0%d_GET" % i) for i in range(1, 9)]
        self.k_strength = self.values.get("FLAG_SYS_USE_STRENGTH")
        self.v_johto_badges = self.values["VAR_JOHTO_BADGES"]
        self.v_hoenn_badges = self.values["VAR_HOENN_BADGES"]
        self.v_permits = self.values["VAR_JOHTO_PERMITS"]
        self.v_licenses = self.values["VAR_HOENN_LICENSES"]
        self.v_result = self.values["VAR_RESULT"]
        self.v_last_talked = self.values.get("VAR_LAST_TALKED")
        self.v_facing = self.values.get("VAR_FACING")
        self.v_8000 = self.values["VAR_0x8000"]
        self.v_8004 = self.values["VAR_0x8004"]
        self.v_8009 = self.values["VAR_0x8009"]
        self.title_flags = {self.flag_key(n): n for n in (
            "FLAG_IS_KANTO_CHAMPION", "FLAG_IS_JOHTO_CHAMPION", "FLAG_IS_HOENN_CHAMPION", "FLAG_SYS_GAME_CLEAR")}

    def flag_key(self, name, map_id=None):
        n = self.values.get(name)
        if n is None:
            n = self.macros.value(name)
        if n is None:
            n = name
        if isinstance(n, int) and n in self.temp_flags and map_id:
            return (n, map_id)
        if isinstance(n, int) and n == self.k_strength_raw() and map_id:
            return (n, map_id)
        return n

    def k_strength_raw(self):
        return self.values.get("FLAG_SYS_USE_STRENGTH")

    def var_key(self, name, map_id=None):
        n = self.values.get(name)
        if n is None:
            n = self.macros.value(name)
        if n is None:
            return None
        if n in self.temp_vars and map_id:
            return (n, map_id)
        return n

    def is_var_name(self, name):
        n = self.values.get(name)
        if n is None and name and name.startswith("VAR_"):
            n = self.macros.value(name)
        if n is None:
            return False
        return name.startswith("VAR_") or (0x4000 <= n <= 0x40FF) or (0x8000 <= n <= 0x80FF)

    def var_limit(self, key):
        """Bitmask vars keep every combination of their eight bits."""
        if key in (self.v_johto_badges, self.v_hoenn_badges, self.v_permits, self.v_licenses):
            return 512
        return MAX_VALUES

    def is_special_var(self, key):
        return isinstance(key, int) and key >= self.special_var_start

    def flag_label(self, key):
        n = key[0] if isinstance(key, tuple) else key
        return self.flag_names.get(n, str(n))

    def var_label(self, key):
        n = key[0] if isinstance(key, tuple) else key
        return self.var_names.get(n, str(n))

    def const(self, text):
        """Argument -> int, or a symbol string (items, species, unknown)."""
        text = text.strip()
        if text.startswith(("ITEM_", "SPECIES_", "MOVE_")):
            return W.canonical_item(text)
        try:
            return int(text, 0)
        except ValueError:
            pass
        v = self.values.get(text)
        if v is None:
            v = self.macros.value(text)
        if v is None:
            v = self.macros.eval(text)
        return v if v is not None else text

    def _init_behaviors(self):
        b = self.beh
        mb = b.value
        self.MB_DOOR = b.set_of("IsWarpDoor")
        self.MB_STEP_WARP = b.set_of("IsWarpDoor", "IsLadder", "IsEscalator", "IsNonAnimDoor",
                                     "IsLavaridgeB1FWarp", "IsLavaridge1FWarp", "IsAquaHideoutWarp",
                                     "IsMtPyreHole", "IsMossdeepGymWarp", "IsUnionRoomWarp")
        self.MB_ARROW = {"N": b.set_of("IsNorthArrowWarp"), "S": b.set_of("IsSouthArrowWarp"),
                         "W": b.set_of("IsWestArrowWarp"), "E": b.set_of("IsEastArrowWarp")}
        self.MB_STAIR = {"W": b.set_of("IsDirectionalUpLeftStairWarp", "IsDirectionalDownLeftStairWarp"),
                         "E": b.set_of("IsDirectionalUpRightStairWarp", "IsDirectionalDownRightStairWarp"),
                         "N": set(), "S": set()}
        self.MB_JUMP = {"S": b.set_of("IsJumpSouth"), "N": b.set_of("IsJumpNorth"),
                        "W": b.set_of("IsJumpWest"), "E": b.set_of("IsJumpEast")}
        blocked = {"S": b.set_of("IsSouthBlocked"), "N": b.set_of("IsNorthBlocked"),
                   "W": b.set_of("IsWestBlocked"), "E": b.set_of("IsEastBlocked")}
        # Leaving the current tile in direction d / entering the next tile.
        self.MB_LEAVE_BLOCK = {"S": blocked["S"], "N": blocked["N"], "W": blocked["W"], "E": blocked["E"]}
        self.MB_DIR_BLOCK = set().union(*blocked.values())
        self.MB_ENTER_BLOCK = {"S": blocked["N"], "N": blocked["S"], "W": blocked["E"], "E": blocked["W"]}
        self.MB_SURF_FISH = b.set_of("IsSurfableFishableWater")
        self.MB_SURFABLE = set(b.surfable)
        self.MB_WATERFALL = b.set_of("IsWaterfall")
        self.MB_DIVEABLE = b.set_of("IsDiveable")
        self.MB_NO_EMERGE = b.set_of("IsUnableToEmerge")
        self.MB_COUNTER = b.set_of("IsCounter")
        self.MB_CRACKED_HOLE = b.set_of("IsCrackedFloorHole")
        self.MB_CRACKED_FLOOR = b.set_of("IsCrackedFloor")
        # Scripts of GetInteractedMetatileScript (src/field_control_avatar.c)
        # that change progress; the others only show text or menus.
        self.MB_INTERACT = [(b.set_of(pred), label) for pred, label in METATILE_SCRIPTS]
        self.warp_behaviors = (self.MB_STEP_WARP | self.MB_DOOR | set().union(*self.MB_ARROW.values())
                               | set().union(*self.MB_STAIR.values()))

    # -- static scan of the scripts --------------------------------------
    def _static_scan(self):
        """Relevant constants per var, files with setmetatile, label owners."""
        self.var_consts = collections.defaultdict(set)
        self.setmetatile_files = set()
        self.setmetatile_xy = set()
        self.layout_files = set()   # script files with setmaplayoutindex
        self.layout_targets = set()  # layouts set by setmaplayoutindex
        self.label_starts = sorted(self.scripts.labels.values())
        self.label_at = {}
        for name, idx in self.scripts.labels.items():
            self.label_at.setdefault(idx, name)
        for ins in self.scripts.instrs:
            c = ins.cmd
            a = ins.args
            if c == "setmaplayoutindex" and a:
                self.layout_files.add(ins.file)
                self.layout_targets.add(a[0])
            if c == "setmetatile":
                self.setmetatile_files.add(ins.file)
                if len(a) >= 2:
                    x, y = self.const(a[0]), self.const(a[1])
                    if isinstance(x, int) and isinstance(y, int):
                        self.setmetatile_xy.add((x, y))
            if c in ("setvar", "addvar", "subvar", "compare", "case") or (
                    re.match(r"(goto|call)_if_(lt|eq|gt|le|ge|ne)$", c) and len(a) == 3):
                var = a[0] if c != "case" else None
                val = a[1] if c != "case" else a[0]
                v = self.const(val)
                if isinstance(v, int) and var and self.is_var_name(var):
                    k = self.values.get(var)
                    if k is not None:
                        self.var_consts[k].add(v)
        self.var_cap = {k: max(vals) + 1 for k, vals in self.var_consts.items() if vals}
        self.file_map = {}
        for m in self.world.maps.values():
            if m.active:
                self.file_map[m.scripts_file] = m.id

    def transition_hides(self, m):
        """Flags the map's ON_TRANSITION script sets before its first branch.
        Objects spawn after that script, so an object hidden by such a flag
        never shows up, unless a script of the map clears the flag again."""
        out = set()
        for typ, label in self.scripts.map_scripts(m.name):
            i = self.scripts.labels.get(label) if typ == "MAP_SCRIPT_ON_TRANSITION" else None
            while i is not None and i < len(self.scripts.instrs):
                ins = self.scripts.instrs[i]
                if ins.cmd == "setflag" and ins.args:
                    out.add(ins.args[0])
                elif ins.cmd == "clearflag" and ins.args:
                    out.discard(ins.args[0])
                elif ins.cmd.startswith(FLOW_CMDS) and ins.cmd != "callnative":
                    break
                i += 1
        if out:
            out -= {ins.args[0] for ins in self.scripts.instrs
                    if ins.file == m.scripts_file and ins.cmd == "clearflag" and ins.args}
        return out

    def owner_label(self, idx):
        """Nearest label at or before an instruction index."""
        i = bisect.bisect_right(self.label_starts, idx) - 1
        if i < 0:
            return None
        return self.label_at.get(self.label_starts[i])

    # -- map info -------------------------------------------------------
    def mapinfo(self, mid):
        info = self.mapinfo_cache.get(mid)
        if info is not None:
            return info
        m = self.world.maps.get(mid)
        if m is None or not m.active:
            self.mapinfo_cache[mid] = False
            return False
        g = self.world.grid(mid)
        if g is None:
            self.mapinfo_cache[mid] = False
            return False
        info = MapInfo(self, m, g)
        self.mapinfo_cache[mid] = info
        return info

    # -- reading the state through a path --------------------------------
    def read_flag(self, p, key, eff):
        if key in p.ov:
            return p.ov[key]
        eff.reads.add(("f", key))
        mask = self.state.flag(key)
        return frozenset(v for v, bit in ((0, FLAG_CLEAR), (1, FLAG_SET)) if mask & bit)

    def read_var(self, p, key, eff):
        if key in p.ov:
            return p.ov[key]
        if self.is_special_var(key):
            # Set by C code outside the script (callbacks of the last special).
            if key not in p.origin and key != self.v_facing:
                p.origin[key] = p.last_special or "(vor dem Skript gesetzt)"
            return ANY
        eff.reads.add(("v", key))
        return self.state.var(key)

    def read_item(self, p, item, eff):
        k = ("item", item)
        if k in p.ov:
            return p.ov[k]
        eff.reads.add(("i", item))
        mask = self.state.item(item)
        return frozenset(v for v, bit in ((0, FLAG_CLEAR), (1, FLAG_SET)) if mask & bit)

    def read_trainer(self, p, t, eff):
        k = ("trainer", t)
        if k in p.ov:
            return p.ov[k]
        eff.reads.add(("t", t))
        mask = self.state.trainer(t)
        return frozenset(v for v, bit in ((0, FLAG_CLEAR), (1, FLAG_SET)) if mask & bit)

    def value_of(self, p, arg, eff, ctx):
        """Argument value: a var's values or a constant (as a set)."""
        if self.is_var_name(arg):
            k = self.var_key(arg, ctx["map"])
            if k is None:
                return ANY
            return self.read_var(p, k, eff)
        v = self.const(arg)
        return frozenset([v])

    # -- field moves ----------------------------------------------------
    def bits_possible(self, key, bit):
        vals = self.state.var(key)
        if vals is ANY:
            return True
        return any(isinstance(v, int) and v & (1 << bit) for v in vals)

    def field_move_ok(self, move, rules, item_needed=True):
        item, kb, db, pb, lb = FIELD_MOVES[move]
        if item_needed and not (self.state.item(item) & FLAG_SET):
            return False
        if rules == "kanto":
            return bool(self.state.flag(self.k_badges[kb - 1]) & FLAG_SET)
        if rules == "hoenn":
            return True if lb is None else self.bits_possible(self.v_licenses, lb)
        if rules == "johto":
            return True if pb is None else self.bits_possible(self.v_permits, pb)
        return bool(self.state.flag(self.k_badges[db - 1]) & FLAG_SET)

    def field_move_reason(self, move, rules):
        item, kb, db, pb, lb = FIELD_MOVES[move]
        parts = []
        if not (self.state.item(item) & FLAG_SET):
            parts.append("%s fehlt" % item)
        if rules == "kanto" and not (self.state.flag(self.k_badges[kb - 1]) & FLAG_SET):
            parts.append("Kanto-Orden %d fehlt" % kb)
        elif rules == "hoenn" and lb is not None and not self.bits_possible(self.v_licenses, lb):
            parts.append("Hoenn-Erlaubnis Bit %d fehlt" % lb)
        elif rules == "johto" and pb is not None and not self.bits_possible(self.v_permits, pb):
            parts.append("Johto-Befugnis Bit %d fehlt" % pb)
        elif rules == "default" and not (self.state.flag(self.k_badges[db - 1]) & FLAG_SET):
            parts.append("Orden-Flag %d fehlt" % db)
        return ", ".join(parts) or "?"

    # =================================================================
    # Script interpreter
    # =================================================================
    def run_entry(self, label, ctx):
        idx = self.scripts.index(label)
        eff = Effects()
        if idx is None:
            eff.unknown_cmds["(Label fehlt) " + label] += 1
            return eff
        try:
            self._run(idx, ctx, eff, coarse=False)
        except Budget:
            eff2 = Effects()
            eff2.coarse = True
            try:
                self._run(idx, ctx, eff2, coarse=True)
            except Budget:
                eff2.unknown_cmds["(Budget überschritten) " + label] += 1
            eff = eff2
        return eff

    def _run(self, start, ctx, eff, coarse):
        budget = 4000 if coarse else 60000
        first = Path(start)
        if ctx.get("last_talked") is not None and self.v_last_talked is not None:
            first.ov[self.v_last_talked] = frozenset([ctx["last_talked"]])
        todo = [first]
        seen = set()
        steps = 0
        instrs = self.scripts.instrs
        while todo:
            p = todo.pop()
            while True:
                if p.pc >= len(instrs):
                    self._end_path(p, eff, ctx)
                    break
                steps += 1
                if steps > budget:
                    raise Budget()
                ins = instrs[p.pc]
                eff.executed.add(p.pc)
                res = self.step(p, ins, ctx, eff, coarse)
                if res is None:
                    p.pc += 1
                    continue
                if res == "end":
                    self._end_path(p, eff, ctx)
                    break
                # res: list of successor paths (already positioned)
                for q in res:
                    if coarse:
                        q.ov = {}
                        key = (q.pc, q.ret)
                    else:
                        key = (q.pc, q.ret, frozenset((k, v) for k, v in q.ov.items()), q.moved, q.wrote_trigger)
                    if key in seen:
                        continue
                    seen.add(key)
                    todo.append(q)
                break

    def _end_path(self, p, eff, ctx):
        eff.paths += 1
        if p.disp and not p.warped:
            eff.player_moves.add(p.disp)
        if (not p.warped) and ((not p.moved) or p.wrote_trigger):
            eff.passing = True
        if ctx.get("collect_final"):
            eff.final_overlays.append(dict(p.ov))

    def goto(self, p, label, call=False):
        idx = self.scripts.index(label)
        if idx is None:
            return "end"
        q = p.fork()
        if call:
            if len(q.ret) > 24:
                return "end"
            q.ret = q.ret + (p.pc + 1,)
        q.pc = idx
        return [q]

    def do_return(self, p):
        if not p.ret:
            return "end"
        q = p.fork()
        q.pc = q.ret[-1]
        q.ret = q.ret[:-1]
        return [q]

    # -- writes ---------------------------------------------------------
    def set_flag(self, p, key, value, eff, idx, ctx):
        p.ov[key] = frozenset([value])
        eff.write_flag(key, value, idx)
        if ctx.get("trigger") == ("f", key):
            p.wrote_trigger = True

    def set_var(self, p, key, values, eff, idx, ctx):
        if values is not ANY and key in self.var_cap:
            cap = self.var_cap[key]
            values = frozenset(min(v, cap) if isinstance(v, int) and v > cap else v for v in values)
        p.ov[key] = values
        p.origin.pop(key, None)
        if not self.is_special_var(key):
            eff.write_var(key, values, idx, self.var_limit(key))
        if ctx.get("trigger") == ("v", key):
            p.wrote_trigger = True

    def give_item(self, p, item, eff, idx):
        if not isinstance(item, str) or not item.startswith("ITEM_"):
            eff.unknown_cmds["(unbekanntes Item) %s" % (item,)] += 1
            return
        item = W.canonical_item(item)
        p.ov[("item", item)] = frozenset([1])
        eff.give_item(item, idx)

    def item_arg(self, p, arg, eff, ctx):
        """Item names an argument may hold (symbols)."""
        if self.is_var_name(arg):
            k = self.var_key(arg, ctx["map"])
            vals = self.read_var(p, k, eff) if k is not None else ANY
            if vals is ANY:
                return []
            return [v for v in vals if isinstance(v, str)]
        return [W.canonical_item(arg)]

    def move_rotating_objects(self, arg, eff, ctx):
        """moverotatingtileobjects: objects on an arrow of the rotating colour
        shift one tile (MoveRotatingTileObjects, src/rotating_tile_puzzle.c).
        Only the first shift is recorded; any recorded move makes the object
        a non-fixed blocker."""
        colour = self.const(arg)
        mid = ctx["map"]
        m = self.world.maps.get(mid)
        if m is None or not isinstance(colour, int):
            return
        lowest = self.const("METATILE_MossdeepGym_YellowArrow_Right")
        start = self.const("METATILE_TrickHousePuzzle_Arrow_YellowOnWhite_Right"
                           if ctx.get("rotating_trick_house") else "METATILE_MossdeepGym_YellowArrow_Right")
        if not isinstance(lowest, int) or not isinstance(start, int):
            return
        grid = self.world.grid(mid)
        shift = {0: (1, 0), 1: (0, 1), 2: (-1, 0), 3: (0, -1)}
        row_width = 8
        for oi, o in enumerate(m.objects):
            x, y = o.get("x"), o.get("y")
            if not isinstance(x, int) or not isinstance(y, int) or not grid.inside(x, y):
                continue
            mt = grid.metatile(x, y)
            if mt < lowest or mt < start or (mt - start) // row_width != colour:
                continue
            d = shift.get((mt - start) % row_width)
            if d:
                eff.positions[(mid, oi)].add((x + d[0], y + d[1]))

    def remove_object(self, p, local, map_name, eff, ctx, idx):
        mid = ctx["map"]
        if map_name:
            mid = map_name
        m = self.world.maps.get(mid)
        if m is None:
            return
        oi = None
        if self.is_var_name(local):
            k = self.var_key(local, ctx["map"])
            vals = self.read_var(p, k, eff) if k is not None else ANY
            if vals is not ANY:
                for v in vals:
                    if isinstance(v, int):
                        oi = m.object_index(v)
        else:
            oi = m.object_index(local)
            if oi is None:
                v = self.const(local)
                if isinstance(v, int):
                    oi = m.object_index(v)
        if oi is None:
            return
        obj = m.objects[oi]
        flag = obj.get("flag", "0")
        if flag and flag != "0":
            self.set_flag(p, self.flag_key(flag, mid), 1, eff, idx, ctx)
        eff.removed.add((mid, oi))

    # -- conditions -----------------------------------------------------
    def compare_sets(self, a, b):
        """Possible compare results (0 lt, 1 eq, 2 gt) and the refinement
        function for the left side."""
        if a is ANY or b is ANY:
            return {0, 1, 2}
        res = set()
        for x in a:
            for y in b:
                if isinstance(x, int) and isinstance(y, int):
                    res.add(0 if x < y else 1 if x == y else 2)
                elif x == y:
                    res.add(1)
                else:
                    res.update((0, 1, 2))
        return res

    def refine(self, a, b, results):
        if a is ANY:
            if b is not ANY and len(b) == 1 and results == {1}:
                return b
            return ANY
        if b is ANY:
            return a
        out = set()
        for x in a:
            for y in b:
                if isinstance(x, int) and isinstance(y, int):
                    r = 0 if x < y else 1 if x == y else 2
                elif x == y:
                    r = 1
                else:
                    r = None
                if r is None or r in results:
                    out.add(x)
                    break
        return frozenset(out)

    def branch(self, p, ins, ctx, eff, cmp, cond, target, call, coarse):
        """cmp: (results, subject, refine_fn). Returns successor paths."""
        results, subject, refine_fn = cmp
        table = COND_TABLE[cond]
        taken = {r for r in results if table[r]}
        fall = {r for r in results if not table[r]}
        out = []
        if subject in p.origin and taken and fall:
            eff.branch_specials[p.origin[subject]].add(p.pc)
        if taken:
            res = self.goto(p, target, call=call)
            if res != "end":
                q = res[0]
                if refine_fn and not coarse:
                    refine_fn(q, taken)
                out.append(q)
        else:
            eff.infeasible.setdefault(p.pc, "Sprung nie möglich")
        if fall:
            q = p.fork()
            q.pc = p.pc + 1
            if refine_fn and not coarse:
                refine_fn(q, fall)
            out.append(q)
        else:
            eff.infeasible.setdefault(p.pc, "Weiterlauf nie möglich")
        return out

    def cmp_var(self, p, var_arg, val_arg, ctx, eff):
        k = self.var_key(var_arg, ctx["map"]) if self.is_var_name(var_arg) else None
        a = self.read_var(p, k, eff) if k is not None else self.value_of(p, var_arg, eff, ctx)
        b = self.value_of(p, val_arg, eff, ctx)
        results = self.compare_sets(a, b)

        def ref(q, rs, k=k, a=a, b=b):
            if k is not None:
                q.ov[k] = self.refine(a, b, rs)
        return (results, k, ref)

    def cmp_flag(self, p, key, eff, reader):
        vals = reader(p, key, eff)
        results = set(vals)

        def ref(q, rs, key=key):
            q.ov[key] = frozenset(rs)
        return (results, None, ref)

    # -- one instruction ------------------------------------------------
    def step(self, p, ins, ctx, eff, coarse):
        c = ins.cmd
        a = ins.args
        idx = p.pc
        if c in ("end", "endram"):
            return "end"
        if c in ("return", "returnram"):
            return self.do_return(p)
        if c in ("goto", "vgoto"):
            return self.goto(p, a[0])
        if c in ("call", "vcall"):
            return self.goto(p, a[0], call=True)
        if c in ("gotostd", "callstd"):
            return self.do_std(p, ins, ctx, eff, call=(c == "callstd"))
        if c in (".byte", ".2byte", ".4byte", ".string", ".braille", "map_script", "map_script_2"):
            return "end"

        m = RE_IF_FLAG.match(c)
        if m:
            key = self.flag_key(a[0], ctx["map"])
            cmp = self.cmp_flag(p, key, eff, self.read_flag)
            return self.branch(p, ins, ctx, eff, cmp, 1 if m.group(3) == "set" else 0, a[1],
                               m.group(2) == "call", coarse)
        m = RE_IF_VAR.match(c)
        if m:
            call = m.group(2) == "call"
            cond = COND_SUFFIX[m.group(3)]
            if len(a) >= 3:
                cmp = self.cmp_var(p, a[0], a[1], ctx, eff)
                return self.branch(p, ins, ctx, eff, cmp, cond, a[2], call, coarse)
            cmp = p.cmp or ({0, 1, 2}, None, None)
            return self.branch(p, ins, ctx, eff, cmp, cond, a[0], call, coarse)
        m = RE_IF_TRAINER.match(c)
        if m:
            t = self.const(a[0])
            cmp = self.cmp_flag(p, t, eff, lambda pp, k, e: self.read_trainer(pp, k, e))
            res, subj, _ = cmp

            def ref(q, rs, t=t):
                q.ov[("trainer", t)] = frozenset(rs)
            return self.branch(p, ins, ctx, eff, (res, subj, ref), 1 if m.group(2) == "defeated" else 0,
                               a[1], m.group(1) == "call", coarse)
        if c in ("goto_if", "call_if", "vgoto_if", "vcall_if"):
            cond = self.const(a[0])
            cond = cond if isinstance(cond, int) and cond in COND_TABLE else 1
            cmp = p.cmp or ({0, 1, 2}, None, None)
            return self.branch(p, ins, ctx, eff, cmp, cond, a[1], c.endswith("call_if"), coarse)
        if c in ("compare", "compare_var_to_value", "compare_var_to_var"):
            p.cmp = self.cmp_var(p, a[0], a[1], ctx, eff)
            return None
        if c == "checkflag":
            p.cmp = self.cmp_flag(p, self.flag_key(a[0], ctx["map"]), eff, self.read_flag)
            return None
        if c == "checktrainerflag":
            t = self.const(a[0])
            vals = self.read_trainer(p, t, eff)
            p.cmp = (set(vals), None, None)
            return None
        if c == "switch":
            k = self.var_key(a[0], ctx["map"])
            vals = self.read_var(p, k, eff) if k is not None else ANY
            self.set_var(p, self.v_8000, vals, eff, idx, ctx)
            if k in p.origin:
                p.origin[self.v_8000] = p.origin[k]
            return None
        if c == "case":
            cmp = self.cmp_var(p, "VAR_0x8000", a[0], ctx, eff)
            return self.branch(p, ins, ctx, eff, cmp, 1, a[1], False, coarse)

        # -- flags and vars --
        if c in ("setflag", "clearflag"):
            self.set_flag(p, self.flag_key(a[0], ctx["map"]), 1 if c == "setflag" else 0, eff, idx, ctx)
            return None
        if c == "setworldmapflag":
            self.set_flag(p, self.flag_key(a[0], ctx["map"]), 1, eff, idx, ctx)
            return None
        if c in ("setvar", "setorcopyvar", "copyvar"):
            k = self.var_key(a[0], ctx["map"])
            if k is None:
                return None
            vals = self.value_of(p, a[1], eff, ctx)
            src = self.var_key(a[1], ctx["map"]) if self.is_var_name(a[1]) else None
            self.set_var(p, k, vals, eff, idx, ctx)
            if src is not None and src in p.origin:
                p.origin[k] = p.origin[src]
            return None
        if c in ("addvar", "subvar"):
            k = self.var_key(a[0], ctx["map"])
            if k is None:
                return None
            cur = self.read_var(p, k, eff)
            delta = self.value_of(p, a[1], eff, ctx)
            if cur is ANY or delta is ANY:
                self.set_var(p, k, ANY, eff, idx, ctx)
                return None
            out = set()
            for x in cur:
                for d in delta:
                    if isinstance(x, int) and isinstance(d, int):
                        out.add(max(0, x + d) if c == "addvar" else max(0, x - d))
                    else:
                        out = None
                        break
                if out is None:
                    break
            self.set_var(p, k, ANY if out is None else frozenset(out), eff, idx, ctx)
            return None
        if c == "settrainerflag":
            t = self.const(a[0])
            p.ov[("trainer", t)] = frozenset([1])
            eff.defeat(t, idx)
            return None
        if c == "cleartrainerflag":
            return None

        # -- items --
        if c in ("giveitem", "giveitem_norandom", "finditem", "additem", "addpcitem", "giveitem_unless_owned"):
            for it in self.item_arg(p, a[0], eff, ctx):
                self.give_item(p, it, eff, idx)
            if c == "finditem" and ctx.get("last_talked") is not None:
                self.remove_object(p, str(ctx["last_talked"]), None, eff, ctx, idx)
            if c != "additem":
                self.set_var(p, self.v_result, frozenset([0, 1]), eff, idx, ctx)
            return None
        if c == "giveitem_msg":
            for it in self.item_arg(p, a[1], eff, ctx):
                self.give_item(p, it, eff, idx)
            return None
        if c == "checkitem":
            vals = set()
            for it in self.item_arg(p, a[0], eff, ctx) or []:
                vals |= self.read_item(p, it, eff)
            if not self.item_arg(p, a[0], eff, ctx):
                vals = {0, 1}
            self.set_var(p, self.v_result, frozenset(vals), eff, idx, ctx)
            return None
        if c == "pokemart":
            j = self.scripts.index(a[0])
            while j is not None and j < len(self.scripts.instrs):
                ii = self.scripts.instrs[j]
                if ii.cmd in (".2byte", ".byte") and ii.args:
                    it = W.canonical_item(ii.args[0])
                    if it in ("ITEM_NONE", "0"):
                        break
                    if it.startswith("ITEM_"):
                        self.give_item(p, it, eff, idx)
                    j += 1
                elif ii.cmd == "pokemartlistend":
                    break
                else:
                    break
            return None

        # -- Pokemon --
        if c in ("givemon", "giveegg", "giveoddegg", "createmon"):
            sp = a[0] if c != "createmon" else (a[2] if len(a) > 2 else "?")
            eff.gifts.append((sp, idx))
            self.set_var(p, self.v_result, ANY, eff, idx, ctx)
            return None
        if c in ("setwildbattle", "setwildbattleshiny", "setwildbossbattle", "seteventmon"):
            eff.statics.append((a[0] if a else "?", idx))
            return None
        if c in ("dowildbattle",):
            return None
        if c == "ingame_trade":
            eff.gifts.append(("Tausch " + a[0], idx))
            out = []
            q = p.fork()
            q.pc = p.pc + 1
            out.append(q)
            for lbl in (a[2], a[3]):
                r = self.goto(p, lbl)
                if r != "end":
                    out.extend(r)
            return out
        if c == "move_tutor":
            if len(a) > 5 and a[5] not in ("0", ""):
                self.set_flag(p, self.flag_key(a[5], ctx["map"]), 1, eff, idx, ctx)
            out = []
            for lbl in (a[3], a[4]):
                r = self.goto(p, lbl)
                if r != "end":
                    out.extend(r)
            return out or "end"

        # -- trainers --
        if c.startswith("trainerbattle"):
            return self.do_trainerbattle(p, ins, ctx, eff, idx)

        # -- warps --
        if c in WARP_CMDS:
            # The script keeps running until waitstate; the map change stops it there.
            self.do_warp(p, ins, ctx, eff, idx)
            p.warped = True
            return None
        if c == "waitstate" and p.warped:
            return "end"
        if c in ("setdynamicwarp", "setwarp"):
            dest = self.warp_target(a)
            if dest:
                eff.dyn_warps[ctx["map"]].add(dest)
            return None
        if c == "setdivewarp":
            dest = self.warp_target(a)
            if dest:
                eff.dive_warps[ctx["map"]].add(dest)
            return None
        if c == "setholewarp":
            if a:
                eff.hole_maps[ctx["map"]].add(a[0])
            return None

        # -- objects and map --
        if c == "removeobject":
            self.remove_object(p, a[0], a[1] if len(a) > 1 else None, eff, ctx, idx)
            return None
        if c == "initrotatingtilepuzzle":
            v = self.const(a[0]) if a else 0
            ctx["rotating_trick_house"] = isinstance(v, int) and v != 0
            return None
        if c == "moverotatingtileobjects":
            self.move_rotating_objects(a[0] if a else "0", eff, ctx)
            return None
        if c in ("setobjectxyperm", "setobjectxy"):
            m = self.world.maps.get(ctx["map"])
            if m is not None:
                oi = m.object_index(a[0])
                if oi is None:
                    v = self.const(a[0])
                    oi = m.object_index(v) if isinstance(v, int) else None
                x, y = self.const(a[1]), self.const(a[2])
                if oi is not None and isinstance(x, int) and isinstance(y, int):
                    eff.positions[(ctx["map"], oi)].add((x, y))
            return None
        if c in ("applymovement",):
            if a and a[0] in PLAYER_IDS:
                p.moved = True
                if len(a) > 1:
                    p.disp = p.disp + self.movement_steps(a[1])
                if len(a) > 1 and "Whirlpool" in a[1] and ctx.get("object") is not None:
                    eff.removed.add((ctx["map"], ctx["object"]))
            return None
        if c == "setmetatile":
            x, y, mt = self.const(a[0]), self.const(a[1]), self.const(a[2])
            imp = self.const(a[3]) if len(a) > 3 else 0
            if isinstance(x, int) and isinstance(y, int) and isinstance(mt, int):
                eff.overrides[ctx["map"]][(x, y)].add((mt, 1 if imp else 0))
            return None
        if c == "setmaplayoutindex":
            eff.layouts[ctx["map"]].add(a[0])
            return None

        # -- specials --
        if c in ("special", "specialvar", "callnative", "gotonative"):
            return self.do_special(p, ins, ctx, eff, idx, coarse)

        # -- results --
        if c == "msgbox":
            if len(a) > 1 and a[1] in ("MSGBOX_YESNO", "5"):
                self.set_var(p, self.v_result, frozenset([0, 1]), eff, idx, ctx)
            return None
        if c in ("checkpartymove", "checkfieldmove"):
            fm = MOVE_TO_FIELD.get(a[0]) if c == "checkpartymove" else FIELD_MOVE_IDS.get(a[0])
            ok = True
            if fm:
                info = self.mapinfo(ctx["map"])
                rules = info.rules if info else "default"
                need_rule = c == "checkpartymove" or (len(a) > 1 and self.const(a[1]) == 1)
                item = FIELD_MOVES[fm][0]
                eff.reads.add(("i", item))
                eff.reads.add(("any", None))
                has_item = bool(self.read_item(p, item, eff) & {1})
                ok = has_item and (not need_rule or self.field_move_ok(fm, rules, item_needed=False))
            party = self.macros.value("PARTY_SIZE") or 6
            vals = frozenset([0, 1, 2, 3, 4, 5, party]) if ok else frozenset([party])
            if c == "checkpartymove":
                vals = frozenset([0, 1, 2, 3, 4, 5, party]) if ok else frozenset([party])
            self.set_var(p, self.v_result, vals, eff, idx, ctx)
            return None
        if c == "setstepcallback":
            # Per-step callbacks in C that count steps in a var (src/field_tasks.c).
            for v in STEP_CALLBACK_VARS.get(a[0] if a else "", ()):
                k = self.var_key(v, ctx["map"])
                if k is not None:
                    self.set_var(p, k, ANY, eff, idx, ctx)
            return None
        if c == "trainerhill_inhoennhill":
            # GetInHoennHill (src/trainer_hill.c): TRUE only on the Emerald hill layouts.
            m = self.world.maps.get(ctx["map"])
            lay = m.layout_id if m else None
            vals = frozenset([1 if lay in HOENN_TRAINER_HILL_LAYOUTS else 0]) if lay else ANY
            self.set_var(p, self.v_result, vals, eff, idx, ctx)
            return None
        if c == "random":
            n = self.const(a[0])
            vals = frozenset(range(n)) if isinstance(n, int) and 0 < n <= MAX_VALUES else ANY
            self.set_var(p, self.v_result, vals, eff, idx, ctx)
            return None
        if c in RESULT_CMDS_ANY:
            self.set_var(p, self.v_result, ANY, eff, idx, ctx)
            return None
        if c in OUT_VAR_CMDS:
            for i in OUT_VAR_CMDS[c]:
                if i < len(a):
                    k = self.var_key(a[i], ctx["map"])
                    if k is not None:
                        self.set_var(p, k, ANY, eff, idx, ctx)
            return None
        if c in IGNORED_CMDS or c in ("pokemartlistend", "pokemartdecoration", "pokemartdecoration2",
                                      "givedecoration", "setescapewarp"):
            return None
        if c.startswith(("walk_", "face_", "jump_", "slide_", "delay_", "emote_", "player_",
                         "lock_", "unlock_", "set_", "step_", "frontier_", "tower_", "dome_",
                         "palace_", "arena_", "factory_", "pike_", "pyramid_", "apprentice_",
                         "trainerhill_", "slateporttent_", "verdanturftent_", "fallarbortent_",
                         "battletent_", "disable_", "enable_", "fly_", "spin_", "nurse_",
                         "levitate", "appear_", "disappear_", "ride_", "walk", "run_",
                         "acro_", "start_", "init_", "figure_", "exclamation", "question",
                         "heart", "reveal_", "store_", "restore_", "ttower_", "dofacility",
                         "facilitytrainerbattle", "setmultitrainerbattle")):
            return None
        eff.unknown_cmds[c] += 1
        self.set_var(p, self.v_result, ANY, eff, idx, ctx)
        return None

    def movement_steps(self, label):
        """Unit steps of a movement script (collisions ignored, as in the game;
        diagonal steps split into two)."""
        cache = self.__dict__.setdefault("_move_cache", {})
        if label in cache:
            return cache[label]
        i = self.scripts.index(label)
        steps = []
        while i is not None and i < len(self.scripts.instrs):
            c = self.scripts.instrs[i].cmd
            if c == "step_end" or c in ("end", "return"):
                break
            m = MOVE_STEP.match(c)
            if m:
                vx, vy = MOVE_VEC[m.group(1)]
                for _ in range(2 if c.startswith("jump_2_") else 1):
                    if vx:
                        steps.append((vx, 0))
                    if vy:
                        steps.append((0, vy))
            i += 1
        cache[label] = tuple(steps)
        return cache[label]

    def do_std(self, p, ins, ctx, eff, call):
        std = self.const(ins.args[0]) if ins.args else None
        if std in (0, 1):  # STD_OBTAIN_ITEM, STD_FIND_ITEM
            vals = self.read_var(p, self.v_8000, eff)
            if vals is not ANY:
                for v in vals:
                    if isinstance(v, str):
                        self.give_item(p, v, eff, p.pc)
            if std == 1 and ctx.get("last_talked") is not None:
                self.remove_object(p, str(ctx["last_talked"]), None, eff, ctx, p.pc)
            self.set_var(p, self.v_result, frozenset([0, 1]), eff, p.pc, ctx)
        elif std == 5:
            self.set_var(p, self.v_result, frozenset([0, 1]), eff, p.pc, ctx)
        if call:
            return None
        return "end"

    def warp_target(self, args):
        if not args:
            return None
        mid = args[0]
        rest = [self.const(x) for x in args[1:]]
        if len(rest) == 1:
            return (mid, rest[0], None, None)
        if len(rest) == 2:
            return (mid, None, rest[0], rest[1])
        if len(rest) >= 3:
            return (mid, rest[0], rest[1], rest[2])
        return (mid, None, None, None)

    def warp_targets(self, p, args, ctx, eff):
        """warp_target with coordinates or warp ids taken from vars
        (warpdoor MAP, VAR_0x8008, VAR_0x8009)."""
        if not args:
            return []
        choices = [[args[0]]]
        for x in args[1:]:
            if self.is_var_name(x):
                k = self.var_key(x, ctx["map"])
                vals = self.read_var(p, k, eff) if k is not None else ANY
                if vals is ANY:
                    return []
                choices.append([str(v) for v in vs_iter_ints(vals)][:16])
            else:
                choices.append([x])
        out = [[]]
        for c in choices:
            out = [o + [v] for o in out for v in c]
        return [self.warp_target(o) for o in out]

    def do_warp(self, p, ins, ctx, eff, idx):
        for dest in self.warp_targets(p, ins.args, ctx, eff):
            if dest is None:
                continue
            if ins.cmd == "warphole":
                # The player falls to his own coordinates (MAP_UNDEFINED: the map of setholewarp).
                eff.holes.add((dest[0], (sum(d[0] for d in p.disp), sum(d[1] for d in p.disp))))
                return
            eff.seeds.setdefault(dest, idx)

    def do_trainerbattle(self, p, ins, ctx, eff, idx):
        c = ins.cmd
        a = ins.args
        trainers = []
        cont = None
        if c == "trainerbattle":
            if len(a) > 2:
                trainers.append(a[2])
            if len(a) > 7 and a[7] not in ("TRAINER_NONE", "0"):
                trainers.append(a[7])
            if len(a) > 5 and a[5] not in ("NULL", "0", "FALSE"):
                cont = a[5]
        elif c == "trainerbattle_two_trainers":
            trainers = [a[0], a[2]]
        else:
            trainers = [a[0]] if a else []
            if c in ("trainerbattle_single", "trainerbattle_double"):
                n = 3 if c == "trainerbattle_single" else 4
                if len(a) > n and a[n] not in ("FALSE", "0", "NULL"):
                    cont = a[n]
        for t in trainers:
            tv = self.const(t)
            p.ov[("trainer", tv)] = frozenset([1])
            eff.defeat(tv, idx)
        out = []
        q = p.fork()
        q.pc = p.pc + 1
        out.append(q)
        if cont:
            r = self.goto(p, cont)
            if r != "end":
                for qq in r:
                    for t in trainers:
                        qq.ov[("trainer", self.const(t))] = frozenset([1])
                out.extend(r)
        return out

    # -- specials -------------------------------------------------------
    def do_special(self, p, ins, ctx, eff, idx, coarse):
        a = ins.args
        if ins.cmd == "specialvar":
            out_var, name = a[0], a[1]
        else:
            out_var, name = None, a[0]
        out_key = self.var_key(out_var, ctx["map"]) if out_var else self.v_result

        def bit_index():
            vals = self.read_var(p, self.v_8004, eff)
            if vals is ANY:
                return list(range(8))
            return [v for v in vals if isinstance(v, int)]

        def set_bits(var):
            cur = self.read_var(p, var, eff)
            bits = bit_index()
            if cur is ANY:
                self.set_var(p, var, ANY, eff, idx, ctx)
                return
            out = frozenset((v | (1 << b)) for v in cur if isinstance(v, int) for b in bits)
            self.set_var(p, var, out, eff, idx, ctx)

        def check_bits(var):
            cur = self.read_var(p, var, eff)
            res = set()
            for b in bit_index():
                if cur is ANY:
                    res |= {0, 1}
                else:
                    for v in cur:
                        if isinstance(v, int):
                            res.add(1 if v & (1 << b) else 0)
            self.set_var(p, out_key, frozenset(res or {0}), eff, idx, ctx)

        def count_bits(var):
            cur = self.read_var(p, var, eff)
            if cur is ANY:
                self.set_var(p, out_key, frozenset(range(9)), eff, idx, ctx)
            else:
                self.set_var(p, out_key, frozenset(bin(v).count("1") for v in cur if isinstance(v, int)),
                             eff, idx, ctx)

        if name == "SetJohtoBadge":
            set_bits(self.v_johto_badges)
        elif name == "SetHoennBadge":
            set_bits(self.v_hoenn_badges)
        elif name == "SetJohtoPermit":
            set_bits(self.v_permits)
        elif name == "SetHoennLicense":
            set_bits(self.v_licenses)
        elif name == "CheckJohtoBadge":
            check_bits(self.v_johto_badges)
        elif name == "CheckHoennBadge":
            check_bits(self.v_hoenn_badges)
        elif name == "CountJohtoBadges":
            count_bits(self.v_johto_badges)
        elif name == "CountHoennBadges":
            count_bits(self.v_hoenn_badges)
        elif name in ("CheckFieldPermission", "CheckHoennLicense"):
            info = self.mapinfo(ctx["map"])
            rules = info.rules if info else "default"
            if rules == "hoenn":
                check_bits(self.v_licenses)
            elif rules == "johto" and name == "CheckFieldPermission":
                check_bits(self.v_permits)
            else:
                self.set_var(p, out_key, frozenset([1]), eff, idx, ctx)
        elif name == "GetItemBallIdAndAmountFromTemplate":
            item = None
            m = self.world.maps.get(ctx["map"])
            if m is not None and ctx.get("object") is not None:
                item = m.objects[ctx["object"]].get("trainer_sight_or_berry_tree_id")
            self.set_var(p, self.v_result, frozenset([W.canonical_item(item)]) if item else ANY, eff, idx, ctx)
            self.set_var(p, self.v_8009, ANY, eff, idx, ctx)
        elif name == "StartMarowakBattle":
            # CB2_EndMarowakBattle: VAR_RESULT FALSE only if the Silph Scope
            # made the ghost visible (src/battle_setup.c).
            scope = self.read_item(p, "ITEM_SILPH_SCOPE", eff)
            self.set_var(p, self.v_result, frozenset([0, 1]) if 1 in scope else frozenset([1]), eff, idx, ctx)
            eff.statics.append(("SPECIES_MAROWAK", idx))
        elif name in SPECIAL_WARPS:
            # C code sets the warp destination from VAR_0x8004; a later special warps.
            vals = self.read_var(p, self.v_8004, eff)
            ints = [0, 1] if vals is ANY else vs_iter_ints(vals)
            for v in ints:
                dest = SPECIAL_WARPS[name][1 if v else 0]
                eff.seeds.setdefault((dest[0], None, dest[1], dest[2]), idx)
            p.warped = True
        elif name in KNOWN_ANY_SPECIALS:
            self.set_var(p, out_key, ANY, eff, idx, ctx)
        else:
            ce = self.cfuncs.effects(name)
            for f in ce["set"]:
                self.set_flag(p, self.flag_key(f, ctx["map"]), 1, eff, idx, ctx)
                p.ov.pop(self.flag_key(f, ctx["map"]), None)
            for f in ce["clear"]:
                self.set_flag(p, self.flag_key(f, ctx["map"]), 0, eff, idx, ctx)
                p.ov.pop(self.flag_key(f, ctx["map"]), None)
            for v in ce["vars"]:
                k = self.var_key(v, ctx["map"])
                if k is not None and k not in (self.v_johto_badges, self.v_hoenn_badges,
                                               self.v_permits, self.v_licenses):
                    self.set_var(p, k, ANY, eff, idx, ctx)
            eff.unknown_specials[name].add(idx)
            result = frozenset([0]) if self.args.strict_specials else ANY
            if out_var or ce["result"] or not ce["found"]:
                self.set_var(p, out_key, result, eff, idx, ctx)
                p.origin[out_key] = name
        p.last_special = name
        if ins.cmd == "gotonative":
            return "end"
        return None


# ---------------------------------------------------------------------------
# Per-map data for the terrain search
# ---------------------------------------------------------------------------

class MapInfo:
    def __init__(self, sim, m, grid):
        self.sim = sim
        self.map = m
        self.id = m.id
        self.grid = grid
        self.rules = sim.world.mapsecs.field_rules(m.mapsec)
        self.region = sim.world.mapsecs.region(m.mapsec)
        self.underwater = m.map_type == "MAP_TYPE_UNDERWATER"
        self.warp_at = collections.defaultdict(list)
        for i, w in enumerate(m.warps):
            self.warp_at[(w["x"], w["y"])].append(i)
        self.coord_at = collections.defaultdict(list)
        for i, c in enumerate(m.coord_events):
            if c.get("type") == "trigger":
                self.coord_at[(c["x"], c["y"])].append(i)
        self.conn = collections.defaultdict(list)
        for c in m.connections:
            self.conn[c["direction"]].append((c["map"], int(c.get("offset", 0))))
        self.has_setmetatile = m.scripts_file in sim.setmetatile_files or m.scripts_file in sim.layout_files
        self.interact = []          # (x, y, label) of metatile interaction scripts
        hit = {}
        for mt in {blk & 0x3FF for blk in grid.blocks}:
            b = grid.behavior_of_metatile(mt)
            for beh, label in sim.MB_INTERACT:
                if b in beh and label in sim.scripts.labels:
                    hit[mt] = label
        if hit:
            for i, blk in enumerate(grid.blocks):
                label = hit.get(blk & 0x3FF)
                if label:
                    self.interact.append((i % grid.w, i // grid.w, label))
        self.objects = []
        hides = sim.transition_hides(m)
        for i, o in enumerate(m.objects):
            if (o.get("type") == "clone" or not isinstance(o.get("x"), int)
                    or o.get("graphics_id") in LIGHT_GFX):
                # Light sprites are not object events (IsLightSpriteGfxId).
                self.objects.append(None)
                continue
            flag = o.get("flag", "0")
            script = o.get("script", "")
            if script in ("NULL", "0x0", "0", ""):
                script = None
            mt = o.get("movement_type", "")
            moving = ("WANDER" in mt or "WALK_SEQUENCE" in mt or "COPY_PLAYER" in mt or "FOLLOW" in mt
                      or re.search(r"WALK_(UP|DOWN|LEFT|RIGHT)_AND_", mt) is not None)
            gfx = o.get("graphics_id", "")
            ttype = o.get("trainer_type", "TRAINER_TYPE_NONE")
            sight = o.get("trainer_sight_or_berry_tree_id", "0")
            try:
                sight = int(sight)
            except ValueError:
                sight = 0
            item_ball = ("ITEM_BALL" in gfx or gfx in ("OBJ_EVENT_GFX_POKE_BALL",)
                         or script == "Common_EventScript_FindItem")
            self.objects.append({
                "idx": i, "x": o["x"], "y": o["y"], "elev": int(o.get("elevation", 0) or 0),
                "flag": sim.flag_key(flag, m.id) if flag not in ("0", "", None) else None,
                "flag_name": flag if flag not in ("0", "", None) else None,
                "script": script, "moving": moving, "gfx": gfx,
                "trainer": ttype not in ("TRAINER_TYPE_NONE", "0") and sight > 0,
                "sight": sight, "boulder": "PUSHABLE_BOULDER" in gfx, "item_ball": item_ball,
                "hidden_on_entry": flag in hides,
                "movement": mt,
            })

    def step(self, x, y, dx, dy):
        """Next tile, crossing connections: (map_id, x, y) or None."""
        g = self.grid
        nx, ny = x + dx, y + dy
        if 0 <= nx < g.w and 0 <= ny < g.h:
            return self.id, nx, ny
        d = {(1, 0): "right", (-1, 0): "left", (0, 1): "down", (0, -1): "up"}[(dx, dy)]
        for tm, off in self.conn.get(d, ()):
            ti = self.sim.mapinfo(tm)
            if not ti:
                continue
            tg = ti.grid
            if d == "right":
                tx, ty = nx - g.w, ny - off
            elif d == "left":
                tx, ty = tg.w + nx, ny - off
            elif d == "down":
                tx, ty = nx - off, ny - g.h
            else:
                tx, ty = nx - off, tg.h + ny
            if 0 <= tx < tg.w and 0 <= ty < tg.h:
                return tm, tx, ty
        return None


# ---------------------------------------------------------------------------
# Terrain search and fixpoint
# ---------------------------------------------------------------------------

class Explorer:
    def __init__(self, sim):
        self.sim = sim
        self.seen = set()
        self.queue = collections.deque()
        self.tiles = collections.defaultdict(set)      # map -> {(x, y)}
        self.tile_elev = collections.defaultdict(set)  # map -> {(x, y, e)}
        self.pending = []                               # (state, dir, reason)
        self.pending_coord = []
        self.coord_hits = set()                         # (map, coord idx)
        self.dyn_entry = collections.defaultdict(set)  # map -> {(src map, warp idx)}
        self.dyn_waiting = collections.defaultdict(list)
        self.dyn_used = set()                           # (map, warp idx) of MAP_DYNAMIC warps used
        self.dive_used = set()                          # maps the player can dive or emerge from via setdivewarp
        self.arrivals = collections.defaultdict(set)    # map -> {(x, y)} where warps put the player
        self.landed = set()                             # states entered without a step
        self.new_tiles = 0
        self.blockers = {}
        self.blocked_reasons = collections.defaultdict(lambda: collections.defaultdict(set))
        self.walk_cache = {}
        self.states_at = collections.defaultdict(list)  # (map, x, y) -> states reached there

    # -- tile data with overrides --
    def tile(self, info, x, y):
        """(behavior, collision, elevation), optimistic over setmetatile."""
        g = info.grid
        b = g.behavior(x, y)
        col = g.collision(x, y)
        e = g.elevation(x, y)
        ov = self.sim.state.overrides.get(info.id)
        if ov and (x, y) in ov:
            for mt, imp in ov[(x, y)]:
                nb = g.behavior_of_metatile(mt)
                if not imp and (col or (b in self.sim.MB_DIR_BLOCK and nb not in self.sim.MB_DIR_BLOCK)):
                    # Passable replacement (also one that removes a one-way wall).
                    col = 0
                    b = nb
                elif nb in self.sim.warp_behaviors and b not in self.sim.warp_behaviors:
                    b = nb
                elif nb in self.sim.MB_DIVEABLE and b not in self.sim.MB_DIVEABLE:
                    b = nb
        lays = self.sim.state.layouts.get(info.id)
        if lays:
            b, col, e = self.layout_tile(info, x, y, (b, col, e), lays)
        return b, col, e

    def layout_tile(self, info, x, y, cur, lays):
        """The most permissive of cur and the same tile in the layouts that
        setmaplayoutindex may put on this map (all layouts count as possible):
        passable before blocked, land before water, warps before floor."""
        best, rank = cur, self.tile_rank(cur)
        for lid in lays:
            g = self.sim.world.grid(info.id, lid)
            if g is None or g is info.grid or g.w != info.grid.w or g.h != info.grid.h:
                continue
            cand = (g.behavior(x, y), g.collision(x, y), g.elevation(x, y))
            r = self.tile_rank(cand)
            if r < rank:
                best, rank = cand, r
        return best

    def tile_rank(self, t):
        b, col, _ = t
        return (col != 0, b in self.sim.MB_SURFABLE, b not in self.sim.warp_behaviors)

    def requeue(self, mid, xys=None):
        """Expands reached states again after the terrain changed: all of map
        mid, or only on the tiles xys and next to them (setmetatile may add a
        dive spot or a warp to a tile that was already expanded)."""
        if xys is None:
            keys = [k for k in self.states_at if k[0] == mid]
        else:
            keys = {(mid, x + dx, y + dy) for x, y in xys for dx, dy in ((0, 0),) + tuple(DIRS.values())}
        for k in keys:
            self.queue.extend(self.states_at.get(k, ()))
        self.walk_cache = {}

    def push(self, st, landed=False, via=None):
        """Adds a state. landed: placed by a warp or a script, not by a step,
        so coord events on that tile do not fire. via: where the player came
        from ((map, warp) or (map, "conn") or ("script", index))."""
        if landed and st not in self.seen:
            self.landed.add(st)
        if st in self.seen:
            return
        self.seen.add(st)
        self.queue.append(st)
        m, x, y, e, s = st
        self.states_at[(m, x, y)].append(st)
        if (x, y) not in self.tiles[m]:
            self.tiles[m].add((x, y))
            self.new_tiles += 1
            if m not in self.sim.map_first:
                self.sim.map_first[m] = self.sim.wave
                self.sim.map_via[m] = via
                info = self.sim.mapinfo(m)
                if info and info.region != "Sonder" and info.region not in self.sim.region_first:
                    self.sim.region_first[info.region] = (self.sim.wave, m)
        self.tile_elev[m].add((x, y, e))

    def arrive(self, mid, warp_id, x=None, y=None, src=None):
        """Places the player on a warp or coordinates of map mid."""
        info = self.sim.mapinfo(mid)
        if not info:
            self.sim.void_warps.setdefault((mid, warp_id), src)
            return
        m = info.map
        if warp_id is not None and isinstance(warp_id, int) and 0 <= warp_id < len(m.warps):
            w = m.warps[warp_id]
            x, y = w["x"], w["y"]
            if src is not None and w.get("dest_map") == "MAP_DYNAMIC":
                if src not in self.dyn_entry[mid]:
                    self.dyn_entry[mid].add(src)
                    for st in self.dyn_waiting.pop(mid, []):
                        self.queue.append(st)
        if not isinstance(x, int) or not isinstance(y, int) or not info.grid.inside(x, y):
            if warp_id is not None and not (isinstance(warp_id, int) and 0 <= warp_id < len(m.warps)):
                self.sim.void_warps.setdefault((mid, warp_id), src)
            return
        b, col, e = self.tile(info, x, y)
        # GetAdjustedInitialTransitionFlags (src/overworld.c): surfing on any
        # surfable tile (also water warps). Seafoam B3F/B4F put the player on
        # foot there; the currents that carry him on are not modelled, so
        # both states count.
        s = 1 if (b in self.sim.MB_SURFABLE and not info.underwater) else 0
        self.arrivals[mid].add((x, y))
        if s and mid in SEAFOAM_ON_FOOT:
            self.push((mid, x, y, e, 0), landed=True, via=src)
        self.push((mid, x, y, e, s), landed=True, via=src)

    def script_starts(self, key):
        """Where the player stands when the entry's script starts."""
        kind, mid = key[0], key[1]
        info = self.sim.mapinfo(mid)
        if not info:
            return set()
        tiles = self.tiles.get(mid, set())
        if kind == "coord":
            c = info.map.coord_events[key[2]]
            return {(c["x"], c["y"])}
        if kind in ("map", "frame"):
            return set(self.arrivals.get(mid, ())) & tiles
        if kind == "obj":
            o = info.objects[key[2]]
            pos = {(o["x"], o["y"])} | self.sim.state.positions.get((mid, key[2]), set())
        elif kind == "bg":
            b = info.map.bg_events[key[2]]
            pos = {(b["x"], b["y"])}
        elif kind == "mt":
            pos = {(key[2], key[3])}
        else:
            return set()
        return {(px + dx, py + dy) for px, py in pos for dx, dy in DIRS.values() if (px + dx, py + dy) in tiles}

    def walk_steps(self, mid, x, y, steps):
        """End of a scripted walk, crossing map connections (e.g. boat trips)."""
        key = (mid, x, y, steps)
        if key in self.walk_cache:
            return self.walk_cache[key]
        self.walk_cache[key] = None
        for dx, dy in steps:
            info = self.sim.mapinfo(mid)
            if not info or not info.grid.inside(x, y):
                return None
            t = info.step(x, y, dx, dy)
            if t is None:
                return None
            mid, x, y = t
        self.walk_cache[key] = (mid, x, y)
        return mid, x, y

    def place(self, mid, x, y, via=None):
        info = self.sim.mapinfo(mid)
        if not info or not info.grid.inside(x, y):
            return
        b, col, e = self.tile(info, x, y)
        self.push((mid, x, y, e, 1 if b in self.sim.MB_SURF_FISH else 0), landed=True, via=via)

    def warp_from(self, info, wi, src_state):
        w = info.map.warps[wi]
        dest = w.get("dest_map")
        try:
            did = int(w.get("dest_warp_id", 0))
        except (TypeError, ValueError):
            did = self.sim.const(str(w.get("dest_warp_id")))
        if dest == "MAP_DYNAMIC":
            self.dyn_used.add((info.id, wi))
            targets = set(self.dyn_entry.get(info.id, ()))
            for (dm, dw, dx, dy) in self.sim.state.dyn_warps.get(info.id, ()):
                targets.add((dm, dw if isinstance(dw, int) else None, dx, dy))
            if not targets and src_state is not None:
                self.dyn_waiting[info.id].append(src_state)
            for t in targets:
                if len(t) == 2:
                    self.arrive(t[0], t[1], src=(info.id, wi))
                else:
                    self.arrive(t[0], t[1], t[2], t[3], src=(info.id, wi))
            return
        self.arrive(dest, did, src=(info.id, wi))

    def warp_here(self, info, x, y, e):
        # Warps compare with PlayerGetElevation, the last non-zero elevation;
        # on elevation-0 tiles that is unknown here, so any warp may match.
        for wi in info.warp_at.get((x, y), ()):
            we = int(info.map.warps[wi].get("elevation", 0) or 0)
            if we == e or we == 0 or e == 0:
                return wi
        return None

    def run(self):
        """Processes the queue and retries blocked moves. True if anything new."""
        sim = self.sim
        before = len(self.seen)
        # Seeds from script warps.
        for dest in list(sim.state.seeds):
            mid, wid, x, y = dest
            self.arrive(mid, wid if isinstance(wid, int) else None, x, y,
                        src=("script", sim.seed_where.get(dest)))
        # Dynamic warps may have new targets.
        for mid, wi in list(self.dyn_used):
            self.warp_from(sim.mapinfo(mid), wi, None)
        # setdivewarp may have set a target after the tiles were expanded.
        for mid in list(self.dive_used):
            for dest in sim.state.dive_warps.get(mid, ()):
                self.arrive(dest[0], dest[1], dest[2], dest[3])
        # Scripted player movement (cutscenes walk the player through walls)
        # and falls through holes, both relative to where the script started.
        for key, entry in list(sim.cache.items()):
            if entry.get("moves"):
                for (sx, sy) in self.script_starts(key):
                    for steps in entry["moves"]:
                        end = self.walk_steps(key[1], sx, sy, steps)
                        if end:
                            self.place(*end, via=(key[1], "move"))
            for dest, (dx, dy) in entry.get("holes", ()):
                targets = sim.state.hole_maps.get(key[1], ()) if dest == "MAP_UNDEFINED" else (dest,)
                for (sx, sy) in self.script_starts(key):
                    for tm in targets:
                        self.arrive(tm, None, sx + dx, sy + dy, src=key)
        # Retry blocked moves.
        old = self.pending
        self.pending = []
        for st, d in old:
            self.try_move(st, d)
        oldc = self.pending_coord
        self.pending_coord = []
        for st in oldc:
            self.queue.append(st)
            self.seen.discard(("coord",) + st)
        while self.queue:
            st = self.queue.popleft()
            self.expand(st)
        return len(self.seen) != before

    def coord_must_fire(self, m, c):
        """True if coord event c of map m fires for every possible value."""
        sim = self.sim
        var = c.get("var", "")
        if var in ("TRIGGER_RUN_IMMEDIATELY", "0", ""):
            return False
        val = sim.const(str(c.get("var_value", "0")))
        if sim.is_var_name(var):
            vals = sim.state.var(sim.var_key(var, m))
            return vals is not ANY and vals == frozenset([val])
        mask = sim.state.flag(sim.flag_key(var, m))
        return mask == (FLAG_SET if val else FLAG_CLEAR)

    def coord_blocks(self, info, st):
        """True if a coord event must fire here and always pushes back."""
        sim = self.sim
        m, x, y, e, s = st
        blocked = False
        for ci in info.coord_at.get((x, y), ()):
            c = info.map.coord_events[ci]
            ce = int(c.get("elevation", 0) or 0)
            if ce != e and ce != 0:
                if e == 0:
                    # Last non-zero elevation unknown: may fire, never sure to block.
                    self.coord_hits.add((m, ci))
                continue
            self.coord_hits.add((m, ci))
            if not self.coord_must_fire(m, c):
                continue
            entry = sim.cache.get(("coord", m, ci))
            if entry is None or not entry["passing"]:
                blocked = True
                self.blocked_reasons[m][("coord", ci)].add((x, y))
        return blocked

    def expand(self, st):
        sim = self.sim
        m, x, y, e, s = st
        info = sim.mapinfo(m)
        if not info:
            return
        if info.coord_at.get((x, y)) and st not in self.landed and self.coord_blocks(info, st):
            self.pending_coord.append(st)
            return
        # Forced warps (what-if option).
        for wi in sim.forced_warps.get(m, ()):
            if wi < len(info.map.warps):
                w = info.map.warps[wi]
                if abs(w["x"] - x) + abs(w["y"] - y) <= 1:
                    self.warp_from(info, wi, st)
        # Dive and emerge.
        b, col, te = self.tile(info, x, y)
        if s and b in sim.MB_DIVEABLE:
            if sim.field_move_ok("dive", info.rules):
                for dm, _ in info.conn.get("dive", ()):
                    self.arrive(dm, None, x, y)
                self.dive_used.add(m)
                for dest in sim.state.dive_warps.get(m, ()):
                    self.arrive(dest[0], dest[1], dest[2], dest[3])
            else:
                self.pending.append((st, "dive"))
                self.blocked_reasons[m][("ability", "dive")].add((x, y))
        if info.underwater and b not in sim.MB_NO_EMERGE:
            if sim.field_move_ok("dive", info.rules):
                emerge = info.conn.get("emerge", ())
                for dm, _ in emerge:
                    self.arrive(dm, None, x, y)
                # Without an emerge connection the engine uses setdivewarp.
                if not emerge:
                    self.dive_used.add(m)
                    for dest in sim.state.dive_warps.get(m, ()):
                        self.arrive(dest[0], dest[1], dest[2], dest[3])
            else:
                self.pending.append((st, "emerge"))
        for d in DIRS:
            self.try_move(st, d)

    def object_block(self, mid, x, y, e):
        """Index of an object that blocks (mid, x, y) for elevation e, or None,
        and whether it may go away later."""
        blk = self.blockers.get(mid)
        if blk is None:
            blk = self.build_blockers(mid)
        for oi, oe, kind in blk.get((x, y), ()):
            if oe == 0 or e == 0 or oe == e:
                return oi, kind
        return None

    def build_blockers(self, mid):
        sim = self.sim
        info = sim.mapinfo(mid)
        out = collections.defaultdict(list)
        if info:
            for o in info.objects:
                if o is None or o["moving"]:
                    continue
                oi = o["idx"]
                key = o["flag"]
                visible = (key is None or bool(sim.state.flag(key) & FLAG_CLEAR)) and not o["hidden_on_entry"]
                if not visible:
                    continue
                hideable = (key is not None and bool(sim.state.flag(key) & FLAG_SET)) or (mid, oi) in sim.state.removed
                if hideable:
                    continue
                if sim.state.positions.get((mid, oi)):
                    continue
                if o["boulder"]:
                    sk = sim.flag_key("FLAG_SYS_USE_STRENGTH", mid)
                    if sim.state.flag(sk) & FLAG_SET:
                        continue
                out[(o["x"], o["y"])].append((oi, o["elev"], "obj"))
        self.blockers[mid] = out
        return out

    def try_move(self, st, d):
        sim = self.sim
        if d in ("dive", "emerge"):
            self.queue.append(st)
            self.seen.add(st)
            return
        m, x, y, e, s = st
        info = sim.mapinfo(m)
        if not info:
            return
        dx, dy = DIRS[d]
        cb, ccol, ce = self.tile(info, x, y)
        # Warps triggered by pressing a direction on the current tile.
        if cb in sim.MB_STAIR[d] or cb in sim.MB_ARROW[d]:
            wi = self.warp_here(info, x, y, e)
            if wi is not None:
                self.warp_from(info, wi, st)
                return
        if d == "N" and info.grid.inside(x, y - 1):
            fb, fcol, fe = self.tile(info, x, y - 1)
            if fb in sim.MB_DOOR:
                fe_player = 0 if ce == 0 else e
                wi = self.warp_here(info, x, y - 1, fe_player)
                if wi is not None:
                    self.warp_from(info, wi, st)
                    return
        if cb in sim.MB_WATERFALL and s:
            if d == "N":
                if not sim.field_move_ok("waterfall", info.rules):
                    self.pending.append((st, d))
                    self.blocked_reasons[m][("ability", "waterfall")].add((x, y))
                    return
            elif d != "S":
                return
        t = info.step(x, y, dx, dy)
        if t is None:
            return
        tm, tx, ty = t
        tinfo = sim.mapinfo(tm)
        if not tinfo:
            return
        tb, tcol, te = self.tile(tinfo, tx, ty)
        if cb in sim.MB_LEAVE_BLOCK[d] or tb in sim.MB_ENTER_BLOCK[d] or tcol:
            ctype = "imp"
        elif e != 0 and te not in (0, 15) and te != e:
            ctype = "elev"
        else:
            ob = self.object_block(tm, tx, ty, e)
            ctype = "obj" if ob else "none"
        if ctype == "elev" and s and te == 3 and not self.object_block(tm, tx, ty, 3):
            self.push((tm, tx, ty, 3, 0), via=(m, "conn"))
            return
        if tb in sim.MB_JUMP[d] and not s:
            land = tinfo.step(tx, ty, dx, dy)
            if land:
                lm, lx, ly = land
                linfo = sim.mapinfo(lm)
                if linfo:
                    lb, lcol, le = self.tile(linfo, lx, ly)
                    self.push((lm, lx, ly, e if le == 15 else le, 0), via=(m, "conn"))
            return
        if ctype == "none":
            if tb in sim.MB_WATERFALL and d == "N" and not sim.field_move_ok("waterfall", tinfo.rules):
                self.pending.append((st, d))
                self.blocked_reasons[tm][("ability", "waterfall")].add((tx, ty))
                return
            ne = e if (te == 15 or ce == 15) else te
            ns = s
            if s and tb not in sim.MB_SURFABLE and te == 3:
                ns = 0
            if not s and tb in sim.MB_SURF_FISH:
                sim.water_walk[tm] += 1
            if tb in sim.MB_STEP_WARP:
                wi = self.warp_here(tinfo, tx, ty, ne)
                if wi is not None:
                    self.tiles[tm].add((tx, ty))
                    self.warp_from(tinfo, wi, st)
                    return
            if tb in sim.MB_CRACKED_HOLE and sim.state.hole_maps.get(tm):
                # EventScript_FallDownHole: same coordinates on the setholewarp map.
                self.tiles[tm].add((tx, ty))
                for hm in sim.state.hole_maps[tm]:
                    self.arrive(hm, None, tx, ty, src=(tm, None))
                return
            if tb in sim.MB_CRACKED_FLOOR and sim.state.hole_maps.get(tm):
                # A cracked floor gives way under a slow player (Sky Pillar),
                # a fast bike crosses it: both are possible.
                for hm in sim.state.hole_maps[tm]:
                    self.arrive(hm, None, tx, ty, src=(tm, None))
            self.push((tm, tx, ty, ne, ns), via=(m, "conn"))
            return
        if ctype == "elev" and not s and e == 3 and tb in sim.MB_SURF_FISH:
            if sim.field_move_ok("surf", info.rules):
                self.push((tm, tx, ty, te, 1), via=(m, "conn"))
            else:
                self.pending.append((st, d))
                self.blocked_reasons[m][("ability", "surf")].add((x, y))
            return
        if ctype == "obj":
            self.pending.append((st, d))
            oi, _ = ob
            self.blocked_reasons[tm][("obj", oi)].add((tx, ty))
            return
        if ctype == "imp" and (tinfo.has_setmetatile or (tx, ty) in sim.setmetatile_xy
                               or (cb in sim.MB_LEAVE_BLOCK[d] and info.has_setmetatile)):
            # setmetatile may open the target, or the one-way wall we stand on.
            self.pending.append((st, d))


class Fixpoint:
    """Waves of terrain search and script runs until nothing changes."""

    def __init__(self, sim):
        self.sim = sim
        self.ex = Explorer(sim)

    # -- triggers -------------------------------------------------------
    def entries(self):
        """All script entries that can run now: key -> (label, ctx)."""
        sim = self.sim
        ex = self.ex
        out = {}
        for mid in list(ex.tiles):
            info = sim.mapinfo(mid)
            if not info:
                continue
            m = info.map
            for typ, label in sim.scripts.map_scripts(m.name):
                if typ in MAP_SCRIPT_ALWAYS:
                    out[("map", mid, typ)] = (label, {"map": mid, "kind": typ})
                elif typ in MAP_SCRIPT_TABLES:
                    for ti, (var, val, script) in enumerate(sim.scripts.frame_table(label)):
                        k = sim.var_key(var, mid)
                        v = sim.const(val)
                        vals = sim.state.var(k) if k is not None else ANY
                        if vals is ANY or v in vals:
                            out[("frame", mid, typ, ti)] = (script, {"map": mid, "kind": typ})
            tiles = ex.tiles[mid]
            for o in info.objects:
                if o is None or not o["script"]:
                    continue
                oi = o["idx"]
                if o["hidden_on_entry"] or (o["flag"] is not None and not (sim.state.flag(o["flag"]) & FLAG_CLEAR)):
                    continue
                positions = {(o["x"], o["y"])} | sim.state.positions.get((mid, oi), set())
                if self.object_reachable(info, tiles, positions, o):
                    out[("obj", mid, oi)] = (o["script"], {"map": mid, "kind": "obj", "object": oi,
                                                           "last_talked": oi + 1})
            for bi, bg in enumerate(m.bg_events):
                if bg.get("type") == "sign" and bg.get("script"):
                    if self.bg_reachable(tiles, bg):
                        out[("bg", mid, bi)] = (bg["script"], {"map": mid, "kind": "bg"})
                elif bg.get("type") == "hidden_item":
                    if self.bg_reachable(tiles, bg, hidden=True):
                        out[("hidden", mid, bi)] = (None, {"map": mid, "kind": "hidden", "bg": bi})
            for x, y, label in info.interact:
                if any((x + dx, y + dy) in tiles for dx, dy in DIRS.values()):
                    out[("mt", mid, x, y)] = (label, {"map": mid, "kind": "mt"})
        for (mid, ci) in ex.coord_hits:
            info = sim.mapinfo(mid)
            c = info.map.coord_events[ci]
            if not c.get("script"):
                continue
            var = c.get("var", "")
            ctx = {"map": mid, "kind": "coord"}
            if var in ("TRIGGER_RUN_IMMEDIATELY", "0", ""):
                out[("coord", mid, ci)] = (c["script"], ctx)
                continue
            val = sim.const(str(c.get("var_value", "0")))
            if sim.is_var_name(var):
                k = sim.var_key(var, mid)
                vals = sim.state.var(k)
                ok = vals is ANY or val in vals
                ctx["trigger"] = ("v", k)
            else:
                k = sim.flag_key(var, mid)
                ok = bool(sim.state.flag(k) & (FLAG_SET if val else FLAG_CLEAR))
                ctx["trigger"] = ("f", k)
            if ok:
                out[("coord", mid, ci)] = (c["script"], ctx)
        return out

    def object_reachable(self, info, tiles, positions, o):
        for (ox, oy) in positions:
            for dx, dy in DIRS.values():
                if (ox + dx, oy + dy) in tiles:
                    return True
                cx, cy = ox + dx, oy + dy
                if (ox + 2 * dx, oy + 2 * dy) in tiles and info.grid.inside(cx, cy):
                    if info.grid.behavior(cx, cy) in self.sim.MB_COUNTER:
                        return True
            if o["trainer"]:
                for dx, dy in DIRS.values():
                    for k in range(1, o["sight"] + 1):
                        if (ox + k * dx, oy + k * dy) in tiles:
                            return True
        return False

    def bg_reachable(self, tiles, bg, hidden=False):
        x, y = bg["x"], bg["y"]
        facing = bg.get("player_facing_dir", "BG_EVENT_PLAYER_FACING_ANY")
        cand = {"BG_EVENT_PLAYER_FACING_NORTH": [(0, 1)], "BG_EVENT_PLAYER_FACING_SOUTH": [(0, -1)],
                "BG_EVENT_PLAYER_FACING_EAST": [(-1, 0)], "BG_EVENT_PLAYER_FACING_WEST": [(1, 0)]}.get(
            facing, [(0, 1), (0, -1), (1, 0), (-1, 0)])
        if hidden:
            cand = [(0, 1), (0, -1), (1, 0), (-1, 0), (0, 0)]
        return any((x + dx, y + dy) in tiles for dx, dy in cand)

    # -- merging --------------------------------------------------------
    def merge(self, key, eff, source):
        """Adds one run's effects to the state. Returns changed state keys."""
        sim = self.sim
        st = sim.state
        changed = set()
        for k, bits in eff.flags.items():
            old = st.flag(k)
            new = old | bits
            if new != old:
                st.flags[k] = new
                changed.add(("f", k))
                if bits & FLAG_SET and not old & FLAG_SET:
                    sim.note_first(("flag", k), eff.where.get(("f", k, 1)), source)
        for k, vals in eff.vars.items():
            old = st.var(k)
            new = vs_union(old, vals, sim.var_limit(k))
            if new is not old and new != old:
                st.vars[k] = new
                changed.add(("v", k))
                sim.note_var(k, old, new, eff, source)
        for it, idx in eff.items.items():
            if not st.item(it) & FLAG_SET:
                st.items[it] = st.item(it) | FLAG_SET
                changed.add(("i", it))
                sim.note_first(("item", it), idx, source)
        for t, idx in eff.trainers.items():
            if t not in st.trainers:
                st.trainers.add(t)
                changed.add(("t", t))
                sim.note_first(("trainer", t), idx, source)
        for r in eff.removed:
            if r not in st.removed:
                st.removed.add(r)
                changed.add(("terrain", r[0]))
        for k, pos in eff.positions.items():
            if not pos <= st.positions[k]:
                st.positions[k] |= pos
                changed.add(("terrain", k[0]))
        for mid, tiles in eff.overrides.items():
            for xy, vals in tiles.items():
                if not vals <= st.overrides[mid][xy]:
                    st.overrides[mid][xy] |= vals
                    changed.add(("terrain", mid))
                    changed.add(("tile", mid, xy))
        for mid, ds in eff.dyn_warps.items():
            if not ds <= st.dyn_warps[mid]:
                st.dyn_warps[mid] |= ds
                changed.add(("dyn", mid))
        for mid, ds in eff.dive_warps.items():
            if not ds <= st.dive_warps[mid]:
                st.dive_warps[mid] |= ds
                changed.add(("dyn", mid))
        for mid, ds in eff.hole_maps.items():
            if not ds <= st.hole_maps[mid]:
                st.hole_maps[mid] |= ds
                changed.add(("dyn", mid))
        for dest, idx in eff.seeds.items():
            if dest not in st.seeds:
                st.seeds.add(dest)
                sim.seed_where.setdefault(dest, idx)
                changed.add(("seed", dest))
                sim.seed_where.setdefault(dest, (idx, source))
        for mid, ls in eff.layouts.items():
            if not ls <= st.layouts[mid]:
                st.layouts[mid] |= ls
                changed.add(("layout", mid))
        for sp, idx in eff.gifts:
            sim.gift_runs.setdefault(idx, (sp, source, sim.wave))
        for sp, idx in eff.statics:
            sim.static_runs.setdefault(idx, (sp, source, sim.wave))
        sim.executed |= eff.executed
        for n, s in eff.unknown_specials.items():
            sim.unknown_specials[n] |= s
        for n, s in eff.branch_specials.items():
            sim.branch_specials[n] |= s
        sim.unknown_cmds.update(eff.unknown_cmds)
        for i, txt in eff.infeasible.items():
            sim.infeasible.setdefault(i, txt)
        if eff.coarse:
            sim.coarse_entries.add(source)
        return changed

    def apply_hidden(self, key, ctx):
        sim = self.sim
        info = sim.mapinfo(ctx["map"])
        bg = info.map.bg_events[ctx["bg"]]
        eff = Effects()
        item = W.canonical_item(bg.get("item", ""))
        if item.startswith("ITEM_"):
            eff.give_item(item, None)
        fl = bg.get("flag")
        if fl and fl != "0":
            eff.write_flag(sim.flag_key(fl, ctx["map"]), 1, None)
        return eff

    def run(self):
        sim = self.sim
        log = sim.log
        start = time.time()
        sim.seed_where = {}
        self.ex.arrive("MAP_PALLET_TOWN_PLAYERS_HOUSE_2F", None, 6, 6)
        dirty_terrain = True
        while sim.wave < sim.args.max_waves:
            sim.wave += 1
            self.ex.blockers = {}
            grew = self.ex.run()
            entries = self.entries()
            changed = set()
            ran = 0
            effs = []
            for key, (label, ctx) in entries.items():
                c = sim.cache.get(key)
                if c is not None and not c["stale"]:
                    continue
                ran += 1
                if ctx["kind"] == "hidden":
                    eff = self.apply_hidden(key, ctx)
                else:
                    eff = sim.run_entry(label, ctx)
                sim.cache[key] = {"stale": False, "passing": eff.passing, "reads": eff.reads, "label": label,
                                  "moves": eff.player_moves, "holes": eff.holes}
                for r in eff.reads:
                    sim.readers[r].add(key)
                effs.append((key, eff))
            for key, eff in effs:
                changed |= self.merge(key, eff, key)
            touched = collections.defaultdict(set)
            for ck in changed:
                if ck[0] == "layout":
                    self.ex.requeue(ck[1])
                elif ck[0] == "tile":
                    touched[ck[1]].add(ck[2])
            for mid, xys in touched.items():
                self.ex.requeue(mid, xys)
            for ck in changed:
                for key in sim.readers.get(ck, ()):
                    if key in sim.cache:
                        sim.cache[key]["stale"] = True
                if ck[0] in ("i", "f", "v"):
                    for key in sim.readers.get(("any", None), ()):
                        if key in sim.cache:
                            sim.cache[key]["stale"] = True
            log("Welle %3d: %6d Felder, %4d Karten, %4d Skripte gelaufen, %4d Änderungen (%.0fs)" % (
                sim.wave, sum(len(t) for t in self.ex.tiles.values()), len(self.ex.tiles), ran,
                sum(1 for ck in changed if ck[0] != "tile"), time.time() - start))
            if not grew and not changed and ran == 0:
                break
        return self.ex


# ---------------------------------------------------------------------------
# Milestones and report
# ---------------------------------------------------------------------------

def where_of(sim, idx):
    if idx is None:
        return ""
    ins = sim.scripts.instrs[idx]
    return ins.where()


def entry_path(sim, mid, depth=10):
    """How map mid was first entered, back to `depth` maps (newest first)."""
    steps = []
    seen = set()
    while mid is not None and mid not in seen and len(steps) < depth:
        seen.add(mid)
        m = sim.world.maps.get(mid)
        name = m.name if m else mid
        via = sim.map_via.get(mid)
        if via is None:
            steps.append(name)
            break
        if via[0] == "script":
            steps.append("%s (Skript-Warp %s)" % (name, where_of(sim, via[1]) or "?"))
            break
        if len(via) == 3:            # script entry key: (kind, map, index)
            src = via[1]
            how = "Loch"
        else:
            src, how = via
        sm = sim.world.maps.get(src)
        sname = sm.name if sm else src
        if how == "conn":
            steps.append("%s (Verbindung von %s)" % (name, sname))
        elif how == "move":
            steps.append("%s (Skriptbewegung von %s)" % (name, sname))
        elif how == "Loch" or how is None:
            steps.append("%s (Loch/Fall von %s)" % (name, sname))
        else:
            steps.append("%s (Warp %s von %s)" % (name, how, sname))
        mid = src
    return steps


def shadowed_connection(m, ci):
    """True if an earlier connection of map m in the same direction has the
    same offset: the engine takes the first match (GetIncomingConnection),
    so connection ci is never used."""
    c = m.connections[ci]
    return any(o["direction"] == c["direction"] and int(o.get("offset", 0)) == int(c.get("offset", 0))
               for o in m.connections[:ci])


def describe_source(sim, source):
    kind = source[0]
    mid = source[1]
    m = sim.world.maps.get(mid)
    name = m.name if m else mid
    if kind == "obj":
        o = m.objects[source[2]]
        return "%s Objekt %d (%s, %d/%d)" % (name, source[2] + 1, o.get("script"), o["x"], o["y"])
    if kind == "coord":
        c = m.coord_events[source[2]]
        return "%s Coord-Event (%d/%d, %s)" % (name, c["x"], c["y"], c.get("script"))
    if kind == "bg":
        b = m.bg_events[source[2]]
        return "%s Schild (%d/%d, %s)" % (name, b["x"], b["y"], b.get("script"))
    if kind == "hidden":
        b = m.bg_events[source[2]]
        return "%s verstecktes Item (%d/%d)" % (name, b["x"], b["y"])
    if kind == "mt":
        return "%s Metatile (%d/%d)" % (name, source[2], source[3])
    if kind in ("map", "frame"):
        return "%s %s" % (name, source[2])
    return str(source)


class Report:
    def __init__(self, sim, ex):
        self.sim = sim
        self.ex = ex
        self.lines = []
        self.data = {}

    def p(self, text=""):
        self.lines.append(text)

    def milestones(self):
        sim = self.sim
        out = []
        badge_names = {k: "Kanto-Orden %d (%s)" % (i + 1, sim.flag_label(k)) for i, k in enumerate(sim.k_badges)}
        for key, (wave, idx, source) in sim.first.items():
            kind = key[0]
            label = None
            if kind == "flag" and key[1] in badge_names:
                label = ("Orden", badge_names[key[1]])
            elif kind == "flag" and key[1] in sim.title_flags:
                label = ("Titel", sim.title_flags[key[1]])
            elif kind == "bit":
                var = key[1]
                name = {sim.v_johto_badges: "Johto-Orden", sim.v_hoenn_badges: "Hoenn-Orden",
                        sim.v_permits: "Johto-Befugnis", sim.v_licenses: "Hoenn-Erlaubnis"}[var]
                extra = ""
                if var in (sim.v_permits, sim.v_licenses):
                    extra = " (%s)" % ["Zerschneider", "Zertrümmerer", "Stärke", "Surfer", "Taucher",
                                       "Kaskade", "?", "?"][key[2]]
                label = ("Orden" if "Orden" in name else "Befugnis", "%s %d%s" % (name, key[2] + 1, extra))
            elif kind == "item" and (sim.items_db.is_key(key[1]) or sim.items_db.is_hm(key[1])):
                disp = sim.items_db.display.get(key[1], "")
                label = ("VM" if sim.items_db.is_hm(key[1]) else "Basis-Item", "%s (%s)" % (disp, key[1]))
            if label:
                out.append((wave, label[0], label[1], describe_source(sim, source) if source else "", where_of(sim, idx)))
        for region, (wave, mid) in sim.region_first.items():
            m = sim.world.maps.get(mid)
            path = entry_path(sim, mid)
            out.append((wave, "Region", "%s erreicht" % region, " <- ".join(path) if path else mid, ""))
        order = {"Region": 0, "Titel": 1, "Orden": 2, "Befugnis": 3, "VM": 4, "Basis-Item": 5}
        out.sort(key=lambda r: (r[0], order.get(r[1], 9), r[2]))
        return out

    def build(self):
        sim = self.sim
        ex = self.ex
        a = sim.args
        self.p("Durchspiel-Simulator Origin Jade (statisches, monotones Modell)")
        self.p("=" * 66)
        self.data["revision"] = W.source_revision()
        self.p("Stand: %s" % self.data["revision"])
        self.p("Optionen: Hoenn-Ticket=%s, erzwungene Warps=%s, Zusatz-Items=%s, Zusatz-Flags=%s, "
               "strikte Specials=%s" % ("ja" if a.hoenn_ticket else "nein", ",".join(a.force_warp or []) or "-",
                                         ",".join(a.give_item or []) or "-",
                                         ",".join((a.set_flag or []) + (a.set_var or [])) or "-",
                                         "ja" if a.strict_specials else "nein"))
        self.p("Wellen bis zum Fixpunkt: %d. Erreicht: %d Karten, %d Felder." % (
            sim.wave, len(ex.tiles), sum(len(t) for t in ex.tiles.values())))
        self.p("Lesart: Obergrenze. Unerreichbar heißt hier sicher unerreichbar (bis auf Modellfehler);")
        self.p("erreichbar heißt nur, dass Gelände, Skripte und Zustände es nicht ausschließen.")
        self.p("")

        # Goals
        self.p("1. Ziele")
        self.p("-" * 66)
        goals = []
        for name in ("FLAG_IS_KANTO_CHAMPION", "FLAG_IS_JOHTO_CHAMPION", "FLAG_IS_HOENN_CHAMPION"):
            k = sim.flag_key(name)
            hit = sim.first.get(("flag", k))
            goals.append((name, hit[0] if hit else None))
            self.p("  %-26s %s" % (name, ("erreichbar ab Welle %d" % hit[0]) if hit else "NICHT erreichbar"))
        self.data["goals"] = {n: w for n, w in goals}
        for region in ("Kanto", "Johto", "Hoenn"):
            r = sim.region_first.get(region)
            self.p("  Region %-19s %s" % (region, ("erreicht ab Welle %d (%s)" % (r[0], sim.world.maps[r[1]].name))
                                         if r else "NICHT erreicht"))
        self.p("")

        # Milestones
        ms = self.milestones()
        self.data["milestones"] = [dict(zip(("wave", "kind", "name", "source", "where"), r)) for r in ms]
        self.p("2. Meilensteine in der Reihenfolge, in der sie erreichbar werden")
        self.p("-" * 66)
        for wave, kind, name, src, where in ms:
            self.p("  W%-4d %-10s %s" % (wave, kind, name))
            if src or where:
                self.p("         <- %s%s" % (src, ("  [%s]" % where) if where else ""))
        self.p("")

        # Stops
        self.p("3. Wo der Fortschritt stoppt")
        self.p("-" * 66)
        stops = self.stops()
        self.data["stops"] = stops
        for s in stops:
            self.p("  * [%s] %s" % (s["kind"], s["text"]))
            for d in s.get("details", [])[:12]:
                self.p("      - %s" % d)
            if len(s.get("details", [])) > 12:
                self.p("      - ... %d weitere" % (len(s["details"]) - 12))
        if not stops:
            self.p("  keine")
        self.p("")

        # Unreachable lists
        self.unreachable_lists()

        # Model notes
        self.p("9. Modellhinweise")
        self.p("-" * 66)
        rel_specials = sorted((n, len(s)) for n, s in sim.branch_specials.items())
        self.p("  Specials ohne Modell, nach deren Ergebnis verzweigt wird (Annahme: beliebiges Ergebnis): %d" % len(rel_specials))
        for n, cnt in rel_specials:
            locs = sorted(where_of(sim, i) for i in sim.branch_specials[n])
            self.p("    %-40s %s" % (n, ", ".join(locs[:3]) + (" ..." if len(locs) > 3 else "")))
        other = sorted(n for n in sim.unknown_specials if n not in sim.branch_specials)
        self.p("  Weitere aufgerufene Specials ohne Modell (nur C-Scan der Flags/Vars): %d" % len(other))
        self.p("    " + ", ".join(other[:60]) + (" ..." if len(other) > 60 else ""))
        self.data["specials_branch"] = {n: sorted(where_of(sim, i) for i in s) for n, s in sim.branch_specials.items()}
        self.data["specials_other"] = other
        unk = [(c, n) for c, n in sim.unknown_cmds.most_common() if not c.startswith("(")]
        self.p("  Unbekannte Skriptbefehle (als wirkungslos behandelt): %s" % (
            ", ".join("%s×%d" % (c, n) for c, n in unk[:30]) or "keine"))
        miss = [(c, n) for c, n in sim.unknown_cmds.most_common() if c.startswith("(")]
        if miss:
            self.p("  Auffälligkeiten beim Ausführen: %s" % ", ".join("%s×%d" % (c, n) for c, n in miss[:20]))
        if sim.coarse_entries:
            self.p("  Grob ausgeführt (Pfadbudget überschritten): %s" % ", ".join(
                describe_source(sim, s) for s in sorted(sim.coarse_entries, key=str)[:10]))
        lay = {sim.world.maps[m].name: sorted(v) for m, v in sim.state.layouts.items() if m in sim.world.maps}
        if lay:
            self.p("  setmaplayoutindex als Vereinigung der Layouts (günstigstes Feld zählt): %s" % (
                ", ".join(sorted(lay))))
        shadow = sorted("%s -> %s (%s)" % (m.name, sim.world.maps[c["map"]].name if c["map"] in sim.world.maps
                                           else c["map"], c["direction"])
                        for m in sim.world.active_maps() for ci, c in enumerate(m.connections)
                        if shadowed_connection(m, ci))
        if shadow:
            self.p("  Verdeckte Verbindungen (die Engine nimmt die erste gleicher Richtung und Lage): %s" % (
                ", ".join(shadow)))
        ww = sorted(((sim.world.maps[m].name, n) for m, n in sim.water_walk.items()), key=lambda r: -r[1])
        if ww:
            self.p("  Wasser ohne Surfer betretbar (keine Höhenstufe dazwischen, wie die Engine): %s" % (
                ", ".join("%s×%d" % r for r in ww[:12])))
        if sim.void_warps:
            self.p("  Warps auf fehlende/stillgelegte Ziele: %s" % ", ".join(
                "%s#%s" % k for k in sorted(sim.void_warps, key=str)[:20]))
        self.data["void_warps"] = ["%s#%s" % k for k in sorted(sim.void_warps, key=str)]
        self.p("")
        return "\n".join(self.lines) + "\n"

    # -- stops ----------------------------------------------------------
    def stops(self):
        sim = self.sim
        ex = self.ex
        out = []
        reached = set(ex.tiles)
        # (a) warps from reached maps into unreached active maps.
        coord_blocked = collections.defaultdict(set)
        for st in ex.pending_coord:
            coord_blocked[st[0]].add((st[1], st[2]))
        for mid in sorted(reached):
            info = sim.mapinfo(mid)
            if not info:
                continue
            tiles = ex.tiles[mid]
            for wi, w in enumerate(info.map.warps):
                dest = w.get("dest_map")
                if dest == "MAP_DYNAMIC" or dest in reached:
                    continue
                dm = sim.world.maps.get(dest)
                if dm is None or not dm.active or is_link_map(dm):
                    continue
                x, y = w["x"], w["y"]
                base = {"map": info.map.name, "warp": wi, "dest": dm.name, "x": x, "y": y}
                if not info.grid.inside(x, y):
                    out.append(dict(base, kind="Warp außerhalb der Karte",
                                    text="%s Warp %d (%d/%d) -> %s liegt außerhalb der Karte" % (
                                        info.map.name, wi, x, y, dm.name)))
                    continue
                b, col, e = ex.tile(info, x, y)
                near = [(x + dx, y + dy) for dx, dy in DIRS.values() if (x + dx, y + dy) in tiles]
                bname = sim.beh.name.get(b, str(b))
                approach = [(x, y + 1)] if b in sim.MB_DOOR else [(x, y)] + near
                cblock = [t for t in approach if t in coord_blocked[mid]]
                if cblock:
                    out.append(dict(self.local_block(info, "Coord-Event sperrt Zugang", wi, dm, x, y,
                                                     only=("coord",)), **base))
                elif b not in sim.warp_behaviors and ((x, y) in tiles or near):
                    out.append(dict(base, kind="Warp nicht auslösbar", behavior=bname, collision=col,
                                    text="%s Warp %d (%d/%d) -> %s: Feld hat Verhalten %s, Kollision %d, "
                                         "Höhe %d; erreichte Nachbarfelder: %s" % (
                                             info.map.name, wi, x, y, dm.name, bname, col, e,
                                             ", ".join("%d/%d" % t for t in near) or "-")))
                elif b not in sim.MB_DOOR and (x, y) not in tiles and near:
                    out.append(dict(base, kind="Warp-Feld nicht betretbar", behavior=bname, collision=col,
                                    text="%s Warp %d (%d/%d) -> %s: Feld (%s, Kollision %d, Höhe %d, "
                                         "Warp-Höhe %s) ist von den erreichten Nachbarn %s aus nicht betretbar" % (
                                             info.map.name, wi, x, y, dm.name, bname, col, e, w.get("elevation"),
                                             ", ".join("%d/%d" % t for t in near))))
                elif b in sim.MB_DOOR and (x, y + 1) not in tiles:
                    out.append(dict(self.local_block(info, "Tür nicht erreicht", wi, dm, x, y), **base))
                elif b not in sim.MB_DOOR and (x, y) not in tiles:
                    out.append(dict(self.local_block(info, "Warp-Feld nicht erreicht", wi, dm, x, y), **base))
                else:
                    out.append(dict(base, kind="Warp ohne Wirkung",
                                    text="%s Warp %d (%d/%d) -> %s: Feld und Zugang erreicht, Warp löst im Modell "
                                         "trotzdem nicht aus (Höhe Warp %s, Feld %d)" % (
                                             info.map.name, wi, x, y, dm.name, w.get("elevation"), e)))
        # (b) connections into unreached maps.
        for mid in sorted(reached):
            info = sim.mapinfo(mid)
            if not info:
                continue
            for ci, c in enumerate(info.map.connections):
                if c["direction"] in ("dive", "emerge"):
                    continue
                if c["map"] in reached or shadowed_connection(info.map, ci):
                    continue
                dm = sim.world.maps.get(c["map"])
                if dm is None or not dm.active:
                    continue
                out.append(dict(self.local_block(info, "Verbindung nicht passierbar", None, dm, None, None,
                                                 extra="Richtung %s" % c["direction"]),
                                map=info.map.name, dest=dm.name))
        # (c) blocked abilities overall.
        abil = collections.defaultdict(set)
        for mid, reasons in ex.blocked_reasons.items():
            for r, tiles in reasons.items():
                if r[0] == "ability":
                    info = sim.mapinfo(mid)
                    abil[(r[1], info.rules)].add(info.map.name)
        for (move, rules), maps in sorted(abil.items()):
            if sim.field_move_ok(move, rules):
                continue
            out.append({"kind": "Feldattacke fehlt", "move": move, "rules": rules,
                        "text": "%s (%s-Regeln) nie nutzbar: %s; betrifft %d Karten" % (
                            MOVE_NAMES_DE.get(move, move), rules, sim.field_move_reason(move, rules), len(maps)),
                        "details": sorted(maps)})
        # (d) milestone instructions in scripts that ran but never reached them.
        out.extend(self.unreached_milestone_code())
        return out

    def local_block(self, info, kind, wi, dm, x, y, extra="", only=None):
        """Blockers of a map that may explain why (x, y) is not reached,
        nearest first."""
        sim = self.sim
        reasons = self.ex.blocked_reasons.get(info.id, {})
        rows = []
        for r, tiles in reasons.items():
            if only and r[0] not in only:
                continue
            if x is not None:
                dist = min(abs(tx - x) + abs(ty - y) for tx, ty in tiles)
            else:
                dist = 0
            # Rank: changeable blockers first, NPCs that never move last.
            rank = 0
            if r[0] == "ability":
                if sim.field_move_ok(r[1], info.rules):
                    continue
                txt = "%s fehlt (%s) an %d Feldern, z. B. %s" % (
                    MOVE_NAMES_DE.get(r[1], r[1]), sim.field_move_reason(r[1], info.rules), len(tiles),
                    "%d/%d" % sorted(tiles)[0])
            elif r[0] == "obj":
                o = info.map.objects[r[1]]
                key = info.objects[r[1]]["flag"]
                if key is not None and sim.state.flag(key) & FLAG_SET:
                    continue
                rank = 0 if o.get("flag", "0") != "0" else 1
                txt = "Objekt %d (%s, %s) bei %d/%d steht im Weg; %s" % (
                    r[1] + 1, o.get("graphics_id"), o.get("script"), o["x"], o["y"],
                    ("Flag %s wird nie gesetzt" % o.get("flag")) if o.get("flag", "0") != "0"
                    else "ohne Flag, kein Skript entfernt es")
            elif r[0] == "coord":
                c = info.map.coord_events[r[1]]
                if not self.ex.coord_must_fire(info.id, c):
                    continue
                vk = sim.var_key(c.get("var", ""), info.id) if sim.is_var_name(c.get("var", "")) else None
                vals = sim.state.var(vk) if vk is not None else None
                txt = "Coord-Event %s bei %d/%d (%s == %s; mögliche Werte %s) schiebt immer zurück" % (
                    c.get("script"), c["x"], c["y"], c.get("var"), c.get("var_value"),
                    sorted(vals, key=str) if vals not in (None, ANY) else vals)
            else:
                continue
            rows.append((rank, dist, txt))
        rows.sort()
        details = [t for _, _, t in rows[:6]]
        where = ("Warp %d (%d/%d) " % (wi, x, y)) if wi is not None else ""
        return {"kind": kind, "map": info.map.name, "dest": dm.name,
                "text": "%s %s-> %s %s" % (info.map.name, where, dm.name, extra),
                "details": details or ["kein veränderlicher Blocker gefunden (Gelände/Kollision)"]}

    def milestone_instr(self, ins):
        """Description if the instruction grants a milestone, else None."""
        sim = self.sim
        c = ins.cmd
        a = ins.args
        if c == "setflag" and a:
            k = sim.flag_key(a[0])
            if k in sim.k_badges or k in sim.title_flags:
                return "setflag %s" % a[0]
        if c in ("special",) and a and a[0] in ("SetJohtoBadge", "SetHoennBadge", "SetJohtoPermit", "SetHoennLicense"):
            return "special %s" % a[0]
        if c in ("giveitem", "giveitem_norandom", "finditem", "additem", "giveitem_msg") and a:
            it = W.canonical_item(a[1] if c == "giveitem_msg" else a[0])
            if sim.items_db.is_key(it) or sim.items_db.is_hm(it):
                return "%s %s" % (c, it)
        if c in WARP_CMDS and a:
            # A warp into a story region that was never reached (e.g. the ship to Hoenn).
            dm = sim.world.maps.get(a[0])
            if dm is not None and dm.active and dm.id not in self.ex.tiles:
                dreg = sim.world.region(dm.id)
                smid = sim.file_map.get(ins.file)
                sreg = sim.world.region(smid) if smid else None
                if dreg in ("Kanto", "Johto", "Hoenn") and dreg != sreg and dreg not in sim.region_first:
                    return "%s %s (Region %s)" % (c, a[0], dreg)
        return None

    def unreached_milestone_code(self):
        sim = self.sim
        out = []
        groups = collections.defaultdict(list)
        for i, ins in enumerate(sim.scripts.instrs):
            if i in sim.executed:
                continue
            desc = self.milestone_instr(ins)
            if not desc:
                continue
            mid = sim.file_map.get(ins.file)
            if ins.file.startswith("data/maps/") and mid is None:
                continue  # retired map
            if mid is not None and mid not in self.ex.tiles:
                continue  # map never reached: covered by the map list
            if "debug" in ins.file:
                continue
            # Start of the code that falls through into i (labels do not stop it).
            li = i
            while li > 0:
                prev = sim.scripts.instrs[li - 1]
                if prev.file != ins.file or prev.cmd in FALLTHROUGH_END:
                    break
                li -= 1
            label = sim.owner_label(li) or sim.owner_label(i)
            started = any(j in sim.executed for j in range(li, i))
            if mid is None and not started:
                continue  # shared script nobody calls
            groups[(label, started)].append((i, desc, li))
        for (label, started), items in sorted(groups.items(), key=lambda r: str(r[0])):
            li = min(r[2] for r in items)
            items = [(i, d) for i, d, _ in items]
            first = items[0][0]
            conds = []
            for j in range(li or 0, first):
                if j in sim.infeasible:
                    conds.append("%s (%s): %s" % (sim.scripts.instrs[j], sim.infeasible[j], ""))
            kind = "Zweig nie erreicht" if started else "Skript nie gestartet"
            details = ["%s  [%s]" % (d, where_of(sim, i)) for i, d in items]
            details += ["Bedingung: %s" % c.rstrip(": ") for c in conds[:6]]
            out.append({"kind": kind, "label": label,
                        "text": "%s: %s" % (label, "; ".join(d for _, d in items[:4])),
                        "details": details})
        return out

    def layout_holders(self, active):
        """Active maps whose layout only serves setmaplayoutindex on another
        map: no warp and no used connection of an active map leads to them."""
        sim = self.sim
        cand = {m.id for m in active if m.layout_id in sim.layout_targets}
        if not cand:
            return set()
        for m in active:
            for w in m.warps:
                cand.discard(w.get("dest_map"))
            for ci, c in enumerate(m.connections):
                if not shadowed_connection(m, ci):
                    cand.discard(c["map"])
        return cand

    def orphan_maps(self, active, unreached):
        """Unreached maps nothing refers to: no warp or used connection of
        another active map, no script of another active map or of
        data/scripts, no C file names the map or its layout. Leftovers rather
        than blocked content."""
        sim = self.sim
        refs = collections.defaultdict(set)   # map id -> referring map ids
        for m in active:
            for w in m.warps:
                refs[w.get("dest_map")].add(m.id)
            for ci, c in enumerate(m.connections):
                if not shadowed_connection(m, ci):
                    refs[c["map"]].add(m.id)
        for ins in sim.scripts.instrs:
            owner = sim.file_map.get(ins.file)
            if owner is None and not ins.file.startswith("data/scripts/"):
                continue
            for a in ins.args:
                if a in unreached:
                    refs[a].add(owner or "script")
        c_refs = sim.world.c_map_refs()
        return {mid for mid in unreached if not (refs[mid] - {mid}) and mid not in c_refs
                and sim.world.maps[mid].layout_id not in c_refs}

    # -- unreachable lists --
    def unreachable_lists(self):
        sim = self.sim
        ex = self.ex
        active = [m for m in sim.world.active_maps() if not is_link_map(m)]
        holders = self.layout_holders(active)
        unreached = [m for m in active if m.id not in ex.tiles and m.id not in holders]
        by_region = collections.defaultdict(list)
        for m in unreached:
            by_region[sim.world.region(m.id)].append(m.name)
        self.p("4. Unerreichbare aktive Karten: %d von %d" % (len(unreached), len(active)))
        self.p("-" * 66)
        for r in sorted(by_region):
            names = sorted(by_region[r])
            self.p("  %s (%d): %s" % (r, len(names), ", ".join(names)))
        self.data["unreached_maps"] = {r: sorted(v) for r, v in by_region.items()}
        orphans = self.orphan_maps(active, {m.id for m in unreached})
        if orphans:
            self.p("  Davon verwaist (kein Warp, keine Verbindung, kein Skript einer anderen aktiven Karte und "
                   "kein C-Code nennt sie): %s" % ", ".join(sorted(sim.world.maps[o].name for o in orphans)))
        self.data["orphan_maps"] = sorted(sim.world.maps[o].name for o in orphans)
        unreached_holders = sorted(sim.world.maps[h].name for h in holders if h not in ex.tiles)
        if unreached_holders:
            self.p("  Nicht mitgezählt, nur Layout-Vorlage für setmaplayoutindex (kein Warp, keine "
                   "benutzte Verbindung führt hin): %s" % ", ".join(unreached_holders))
        self.data["layout_holders"] = unreached_holders
        self.p("")

        items, hidden, trainers = [], [], []
        for m in active:
            info = sim.mapinfo(m.id)
            if not info:
                continue
            for o in info.objects:
                if o is None:
                    continue
                key = ("obj", m.id, o["idx"])
                if o["item_ball"]:
                    if key not in sim.cache:
                        item = o.get("gfx")
                        raw = m.objects[o["idx"]]
                        it = raw.get("trainer_sight_or_berry_tree_id") if o["script"] == "Common_EventScript_FindItem" else o["script"]
                        items.append((sim.world.region(m.id), "%s (%d/%d) %s" % (m.name, o["x"], o["y"], it)))
                if o["trainer"] and o["script"]:
                    if key not in sim.cache:
                        trainers.append((sim.world.region(m.id), "%s (%d/%d) %s" % (m.name, o["x"], o["y"], o["script"])))
            for bi, bg in enumerate(m.bg_events):
                if bg.get("type") == "hidden_item" and ("hidden", m.id, bi) not in sim.cache:
                    hidden.append((sim.world.region(m.id), "%s (%d/%d) %s" % (m.name, bg["x"], bg["y"], bg.get("item"))))
        # Trainer battles in active map scripts never executed.
        tb = []
        gifts = []
        statics = []
        for i, ins in enumerate(sim.scripts.instrs):
            mid = sim.file_map.get(ins.file)
            if mid is None:
                continue
            region = sim.world.region(mid)
            if ins.cmd.startswith("trainerbattle") and i not in sim.executed:
                t = ins.args[2] if ins.cmd == "trainerbattle" and len(ins.args) > 2 else (ins.args[0] if ins.args else "?")
                tb.append((region, "%s %s [%s]" % (sim.world.maps[mid].name, t, ins.where())))
            if ins.cmd in ("givemon", "giveegg", "giveoddegg", "ingame_trade") and i not in sim.executed:
                gifts.append((region, "%s %s %s [%s]" % (sim.world.maps[mid].name, ins.cmd, ins.args[0] if ins.args else "",
                                                         ins.where())))
            if ins.cmd in ("setwildbattle", "setwildbossbattle", "seteventmon", "setwildbattleshiny") and i not in sim.executed:
                statics.append((region, "%s %s [%s]" % (sim.world.maps[mid].name, ins.args[0] if ins.args else "",
                                                        ins.where())))
        for title, rows, key in (("5. Unerreichbare Item-Bälle", items, "items"),
                                 ("6. Unerreichbare versteckte Items", hidden, "hidden_items"),
                                 ("7a. Nie ausgelöste Trainer-Objekte", trainers, "trainer_objects"),
                                 ("7b. Nie ausgeführte Trainerkämpfe in Kartenskripten", tb, "trainer_battles"),
                                 ("8a. Nie ausgeführte Geschenke/Tausche (givemon, giveegg, ingame_trade)", gifts, "gifts"),
                                 ("8b. Nie ausgeführte statische Begegnungen", statics, "statics")):
            self.p("%s: %d" % (title, len(rows)))
            self.p("-" * 66)
            byr = collections.defaultdict(list)
            for r, txt in rows:
                byr[r].append(txt)
            for r in sorted(byr):
                self.p("  %s (%d):" % (r, len(byr[r])))
                for txt in sorted(byr[r]):
                    self.p("    %s" % txt)
            self.data[key] = {r: sorted(v) for r, v in byr.items()}
            self.p("")


def compare_reports(old, new, old_name):
    """Text lines: what changed between two report.json dicts (old -> new)."""
    lines = ["10. Vergleich mit %s" % old_name, "-" * 66,
             "  Stand alt: %s, neu: %s" % (old.get("revision", "?"), new.get("revision", "?"))]

    def norm(x):
        # Line numbers move between versions; compare without "[file:line]".
        return re.sub(r"\s*\[[^\]]*:\d+\]", "", x).strip()

    def flat(d, key):
        v = d.get(key) or {}
        if isinstance(v, dict):
            return {norm("%s: %s" % (r, x)) for r, xs in v.items() for x in xs}
        return {norm(x.get("text", str(x)) if isinstance(x, dict) else str(x)) for x in v}

    for name in sorted(set(old.get("goals", {})) | set(new.get("goals", {}))):
        a, b = old.get("goals", {}).get(name), new.get("goals", {}).get(name)
        if (a is None) != (b is None):
            lines.append("  Ziel %s: %s -> %s" % (name, "erreichbar" if a is not None else "NICHT erreichbar",
                                                  "erreichbar" if b is not None else "NICHT erreichbar"))
    ms_old = {(m["kind"], m["name"]) for m in old.get("milestones", [])}
    ms_new = {(m["kind"], m["name"]) for m in new.get("milestones", [])}
    for title, rows in (("Meilensteine neu erreichbar", ms_new - ms_old),
                        ("Meilensteine nicht mehr erreichbar", ms_old - ms_new)):
        lines.append("  %s: %d" % (title, len(rows)))
        lines.extend("    %s %s" % r for r in sorted(rows))
    for key, title in (("stops", "Stopps"), ("unreached_maps", "Unerreichbare Karten"),
                       ("items", "Unerreichbare Item-Bälle"), ("hidden_items", "Unerreichbare versteckte Items"),
                       ("trainer_objects", "Nie ausgelöste Trainer-Objekte"),
                       ("gifts", "Nie ausgeführte Geschenke"), ("statics", "Nie ausgeführte statische Begegnungen")):
        a, b = flat(old, key), flat(new, key)
        lines.append("  %s: %d behoben/entfallen, %d neu" % (title, len(a - b), len(b - a)))
        for x in sorted(a - b):
            lines.append("    - %s" % x)
        for x in sorted(b - a):
            lines.append("    + %s" % x)
    lines.append("")
    return lines


# ---------------------------------------------------------------------------
# Start state and main
# ---------------------------------------------------------------------------

def init_state(sim):
    """New game: EventScript_ResetAllMapFlagsHnS and ...Frlg (src/new_game.c)."""
    st = sim.state
    for label in ("EventScript_ResetAllMapFlagsHnS", "EventScript_ResetAllMapFlagsFrlg"):
        eff = sim.run_entry(label, {"map": "MAP_PALLET_TOWN_PLAYERS_HOUSE_2F", "kind": "init",
                                    "collect_final": True})
        if len(eff.final_overlays) != 1:
            sim.notes.append("%s hat %d Pfade; Startzustand als Vereinigung" % (label, len(eff.final_overlays)))
        for ov in eff.final_overlays:
            for k, vals in ov.items():
                if isinstance(k, tuple) and k and k[0] == "item":
                    if 1 in vals:
                        st.items[k[1]] = FLAG_SET
                    continue
                if isinstance(k, tuple) and k and k[0] == "trainer":
                    continue
                if k in eff.flags:
                    st.flags[k] = (FLAG_SET if 1 in vals else 0) | (FLAG_CLEAR if 0 in vals else 0)
                elif k in eff.vars and not sim.is_special_var(k):
                    st.vars[k] = vals
        for it in eff.items:
            st.items[it] = FLAG_SET
        sim.executed |= eff.executed
    if sim.args.hoenn_ticket:
        st.items["ITEM_HOENN_TICKET"] = FLAG_SET
        k = sim.var_key("VAR_HOENN_TICKET_STATE", None)
        st.vars[k] = vs_union(st.var(k), frozenset([3]))
    for it in sim.args.give_item or []:
        st.items[W.canonical_item(it)] = FLAG_SET
    for fl in sim.args.set_flag or []:
        st.flags[sim.flag_key(fl)] = FLAG_SET
    for spec in sim.args.set_var or []:
        name, _, val = spec.partition("=")
        k = sim.var_key(name.strip(), None)
        v = sim.const(val)
        if k is None or not isinstance(v, int):
            sys.exit("--set-var: unknown var or value: %s" % spec)
        # What-if: the value becomes possible from the start, the old ones stay.
        st.vars[k] = vs_union(st.var(k), frozenset([v]))


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--hoenn-ticket", action="store_true",
                        help="start with the Hoenn Ticket received (what-if, D-047)")
    parser.add_argument("--force-warp", action="append", metavar="MAP:N", help="warp N of MAP always triggers")
    parser.add_argument("--give-item", action="append", metavar="ITEM", help="start with ITEM")
    parser.add_argument("--set-flag", action="append", metavar="FLAG", help="start with FLAG set")
    parser.add_argument("--set-var", action="append", metavar="VAR=N", help="N is a possible value of VAR from the start")
    parser.add_argument("--strict-specials", action="store_true", help="unmodelled specials return 0")
    parser.add_argument("--max-waves", type=int, default=400)
    parser.add_argument("--out", metavar="DIR", help="write report.txt and report.json here")
    parser.add_argument("--compare", metavar="JSON", help="list changes against an older report.json")
    parser.add_argument("--diff", nargs=2, metavar=("OLD", "NEW"), help="only compare two report.json files")
    parser.add_argument("--quiet", action="store_true")
    args = parser.parse_args()

    if args.diff:
        with open(args.diff[0], encoding="utf-8") as fh:
            old = json.load(fh)
        with open(args.diff[1], encoding="utf-8") as fh:
            new = json.load(fh)
        sys.stdout.write("\n".join(compare_reports(old, new, args.diff[0])) + "\n")
        return 0

    def log(msg):
        if not args.quiet:
            print(msg, file=sys.stderr, flush=True)

    sim = Simulator(args, log)
    init_state(sim)
    fp = Fixpoint(sim)
    ex = fp.run()
    rep = Report(sim, ex)
    text = rep.build()
    if args.compare:
        with open(args.compare, encoding="utf-8") as fh:
            old = json.load(fh)
        new = json.loads(json.dumps(rep.data, default=str))
        text += "\n".join(compare_reports(old, new, args.compare)) + "\n"
    if args.out:
        os.makedirs(args.out, exist_ok=True)
        with open(os.path.join(args.out, "report.txt"), "w", encoding="utf-8") as fh:
            fh.write(text)
        with open(os.path.join(args.out, "report.json"), "w", encoding="utf-8") as fh:
            json.dump(rep.data, fh, ensure_ascii=False, indent=1, default=str)
        log("Bericht: %s" % os.path.join(args.out, "report.txt"))
    else:
        sys.stdout.write(text)
    hoenn = sim.first.get(("flag", sim.flag_key("FLAG_IS_HOENN_CHAMPION")))
    return 0 if hoenn else 1


if __name__ == "__main__":
    sys.exit(main())
