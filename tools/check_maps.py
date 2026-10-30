#!/usr/bin/env python3
"""Static consistency check of all active maps (warps, objects, connections, layouts).

A map is active when its game_version matches the build (default "hns", the
jade build; a missing game_version counts as "emerald", as in mapjson) and it is
listed in data/maps/map_groups.json.

Checks and finding codes:
  0. K-UNERREICHBAR  active map the walk never reaches (with the dead
                     entrances that cause it).
  1. Warps: W-NICHT-AUSLOESBAR (no warp behaviour), W-NICHT-BETRETBAR (step-on
     warp on a blocked tile), W-TUER-VERSPERRT, W-PFEIL-WAND, W-HOEHE (warp
     elevation never matches the player's), W-AUSSERHALB, W-ZIEL-FEHLT,
     W-ZIEL-INAKTIV, W-ZIEL-ID; W-SKRIPT if a coord event or script warp of
     the map serves the warp instead.
  2. Arrival tiles: Z-AUSSERHALB, Z-EINGESPERRT (no step possible),
     Z-SACKGASSE (no way out of the map), Z-IN-WAND.
  3. Objects, item balls, hidden items and signs: O-EINGEMAUERT,
     O-UNERREICHBAR, O-HOEHE (bg event elevation never matches); coord
     events: C-HOEHE.
  4. Connections: V-ZIEL-INAKTIV, V-EINSEITIG, V-OFFSET, V-GROESSE,
     V-KEIN-UEBERLAPP, V-NICHT-BEGEHBAR, V-KANTE.
  5. Layouts: L-FEHLT, L-MAPBIN, L-BORDER, L-TILESET, L-ZU-GROSS,
     L-METATILE-ID.

Reachability uses one walk over all active maps, starting at the new-game
position, with the engine's collision, elevation, ledge, surf and warp rules.
It is optimistic: field moves (Surf, Waterfall, Rock Climb, Cut, Strength,
Rock Smash) are available, objects never block, story flags are ignored, every
setmetatile and setmaplayoutindex a map's scripts can run counts, and warps
done by scripts count once the map running them is reached (scripts are
assigned to maps through their call graph). Player moves by applymovement in
coord event scripts count (every branch, the player ends up after each move).
So "unreachable" is a strong result, "reachable" is not a proof. Not modelled:
rides started by talking or by map scripts (maps with many player moves get
"ungeprueft" for objects), bike-only paths, warps set up in C with runtime
values.

Findings carry a provisional status (nachgewiesen/verdacht/vorschlag/
ungeprueft) and severity (blocker/kritisch/wichtig/klein/optional). Whether a
finding blocks the story needs a human look; the tool marks a warp whose target
map has no other access but has content as kritisch. Content means items,
trainers, berry trees and NPCs whose map-specific script has an effect (scripts
shared by 3+ maps, such as cable club attendants, do not count). Broken warp
targets and connections of maps the walk never reaches, and one-way
connections without a passage, are optional; a broken warp target behind an
object that always blocks the access tile is only verdacht.

Usage:
    python3 -I tools/check_maps.py                    # report of the work tree
    python3 -I tools/check_maps.py --rev 3525d22e71   # report of a commit
    python3 -I tools/check_maps.py --region kanto     # one region (kanto, johto, hoenn)
    python3 -I tools/check_maps.py --map CeladonCity_Frlg
    python3 -I tools/check_maps.py --min-severity wichtig
    python3 -I tools/check_maps.py --json out.json    # all findings as JSON
    python3 -I tools/check_maps.py --verbose          # details also for optional findings
    python3 -I tools/check_maps.py --render MtMoon_B3F_Frlg   # ASCII view of one map
    python3 -I tools/check_maps.py --selftest         # known hits on the base commit
    python3 -I tools/check_maps.py --rev audit --compare 3525d22e71   # fixed/new since a commit

Regions follow the map folder name: *_Frlg = Kanto, *_hns = Johto, rest = Hoenn.
Exit status 1 if a finding is nachgewiesen and at least wichtig.
"""

import argparse
import collections
import json
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Commit and findings the self-test expects (audit findings A01 and A11).
SELFTEST_REV = "3525d22e71"
SELFTEST_EXPECT = [
    ("W-NICHT-AUSLOESBAR", "CeladonCity_Frlg", 0),
    ("W-NICHT-BETRETBAR", "MtMoon_B3F_Frlg", 1),
]

START_MAP = "MAP_PALLET_TOWN_PLAYERS_HOUSE_2F"  # src/new_game.c WarpToTruck
START_POS = (6, 6)

MAX_MAP_DATA_SIZE = 10240  # include/fieldmap.h
MAP_OFFSET_W = 15
MAP_OFFSET_H = 14
NUM_METATILES_TOTAL = 1024

STATUS_ORDER = ["nachgewiesen", "verdacht", "vorschlag", "ungeprueft"]
SEVERITY_ORDER = ["blocker", "kritisch", "wichtig", "klein", "optional"]
REGIONS = ["Kanto", "Johto", "Hoenn"]

DIRS = {"N": (0, -1), "S": (0, 1), "W": (-1, 0), "E": (1, 0)}
OPPOSITE = {"up": "down", "down": "up", "left": "right", "right": "left",
            "dive": "emerge", "emerge": "dive"}
EDGE_DIR = {"N": "up", "S": "down", "W": "left", "E": "right"}

# Script commands that move the player to another map (asm/macros/event.inc).
WARP_CMDS = ("warp", "warpsilent", "warpdoor", "warpteleport", "warpspinenter",
             "warpmossdeepgym", "warpwhitefade", "setwarp", "setdynamicwarp",
             "setescapewarp", "setdivewarp")
WARP_CMD_RE = re.compile(r"^\s*(" + "|".join(WARP_CMDS) + r")\s+(MAP_\w+)\s*(?:,([^@\n]*))?", re.M)
HOLE_RE = re.compile(r"^\s*(setholewarp|warphole)\s+(MAP_\w+)", re.M)
RESPAWN_RE = re.compile(r"^\s*setrespawn\s+(HEAL_LOCATION_\w+)", re.M)
SETLAYOUT_RE = re.compile(r"^\s*setmaplayoutindex\s+(LAYOUT_\w+)", re.M)
SETMETATILE_RE = re.compile(r"^\s*setmetatile\s+(\d+)\s*,\s*(\d+)\s*,\s*(\w+)\s*,\s*(\w+)", re.M)
C_WARP_RE = re.compile(r"SetWarpDestination\(\s*MAP_GROUP\((MAP_\w+)\)\s*,\s*MAP_NUM\(\1\)\s*,"
                       r"\s*([-\w]+)\s*,\s*(-?\w+)\s*,\s*(-?\w+)\s*\)")
C_TABLE_RE = re.compile(r"\{\s*MAP_GROUP\((MAP_\w+)\)\s*,\s*MAP_NUM\(\1\)\s*,\s*(\w+)\s*,\s*(\w+)\s*\}")
C_MAPREF_RE = re.compile(r"\bMAP_GROUP\((MAP_\w+)\)")
PLAYER_MOVE_RE = re.compile(r"^\s*applymovement\s+(OBJ_EVENT_ID_PLAYER|LOCALID_PLAYER)\b", re.M)
RIDE_MIN_MOVES = 10  # from this many player movements a map counts as a scripted ride/puzzle
PLAYER_APPLY_RE = re.compile(r"^\s*applymovement\s+(?:OBJ_EVENT_ID_PLAYER|LOCALID_PLAYER)\s*,\s*(\w+)")
BRANCH_RE = re.compile(r"^\s*(goto|call|case)(_if\w*)?\s+(?:[^@\n]*,\s*)?(\w+)\s*$")
# Movement commands that move the object, and how far (asm/macros/movement.inc).
STEP_RE = re.compile(r"^\s*(walk_slow_stairs|walk_slow|walk_faster|walk_fast|walk|ride_water_current|slide|player_run|"
                     r"jump_2|jump_special|jump|acro_wheelie_hop|acro_wheelie_jump|acro_pop_wheelie_move|"
                     r"acro_wheelie_move|acro_end_wheelie_move)_(down|up|left|right)(?:_affine)?\s*$")
DIAG_RE = re.compile(r"^\s*walk_(?:slow_)?diag_(north|south)(west|east)\s*$")
STATIONARY_RE = re.compile(r"MOVEMENT_TYPE_(NONE|FACE_|LOOK_AROUND)")
COMMON_SCRIPT_MAPS = 3  # an object script used on this many maps is a shared feature, not map content
STEP_DIST = {"jump_2": 2, "jump_special": 2, "acro_wheelie_jump": 2}
STEP_DIR = {"down": (0, 1), "up": (0, -1), "left": (-1, 0), "right": (1, 0)}
GAME_CLEAR_RE = re.compile(r"\s*special\s+\w*(GameClear|HallOfFame)\w*")
# Script commands that hand out something or change the game state (object rating).
EFFECT_RE = re.compile(r"^\s*(giveitem|givemon|giveegg|givedecoration|trainerbattle\w*|setwildbattle|"
                       r"dowildbattle|pokemart|pokemartdecoration\w*|special|setflag|warp\w*)\b", re.M)

# Files whose map references are not real warps the player can use.
SKIP_SCRIPT_FILES = {"data/scripts/debug.inc"}
SKIP_C_FILES = {"src/debug.c"}


def parse_int(text):
    """Returns the integer value of a C/asm literal, or None."""
    text = text.strip()
    if text in ("TRUE", "FALSE"):
        return int(text == "TRUE")
    try:
        return int(text, 0)
    except ValueError:
        return None


# ---------------------------------------------------------------- file access

class Source:
    """Reads repo files from the work tree or from a git revision."""

    def __init__(self, root, rev=None):
        self.root = root
        self.rev = rev
        self._files = None
        self._proc = None
        if rev:
            out = subprocess.run(["git", "-C", root, "ls-tree", "-r", "--name-only", rev],
                                 check=True, capture_output=True, text=True).stdout
            self._files = set(out.splitlines())
            self._proc = subprocess.Popen(["git", "-C", root, "cat-file", "--batch"],
                                          stdin=subprocess.PIPE, stdout=subprocess.PIPE)

    def exists(self, path):
        if self.rev:
            return path in self._files
        return os.path.isfile(os.path.join(self.root, path))

    def read(self, path):
        """Returns the file content as bytes, or None if it does not exist."""
        if not self.exists(path):
            return None
        if not self.rev:
            with open(os.path.join(self.root, path), "rb") as fh:
                return fh.read()
        self._proc.stdin.write(f"{self.rev}:{path}\n".encode())
        self._proc.stdin.flush()
        header = self._proc.stdout.readline().split()
        size = int(header[2])
        data = self._proc.stdout.read(size)
        self._proc.stdout.read(1)
        return data

    def text(self, path):
        data = self.read(path)
        return None if data is None else data.decode("utf-8", errors="replace")

    def list(self, prefix, suffix=""):
        """All files below prefix that end with suffix, sorted."""
        if self.rev:
            return sorted(p for p in self._files if p.startswith(prefix) and p.endswith(suffix))
        found = []
        for dirpath, _, names in os.walk(os.path.join(self.root, prefix)):
            for name in names:
                path = os.path.relpath(os.path.join(dirpath, name), self.root).replace(os.sep, "/")
                if path.endswith(suffix):
                    found.append(path)
        return sorted(found)


# ---------------------------------------------------------------- constants

class Behaviors:
    """Metatile behaviour numbers and the groups the field code checks."""

    def __init__(self, src):
        text = src.text("include/constants/metatile_behaviors.h")
        body = text[text.index("enum {") + 6:text.index("};")]
        self.value = {}
        self.name = {}
        num = 0
        for line in body.splitlines():
            line = line.split("//")[0].strip().rstrip(",")
            if not line.startswith("MB_"):
                continue
            if "=" in line:
                key, val = (s.strip() for s in line.split("="))
                num = parse_int(val)
            else:
                key = line
            self.value[key] = num
            self.name.setdefault(num, key)
            num += 1

        def group(*names):
            return frozenset(self.value[n] for n in names if n in self.value)

        # IsWarpMetatileBehavior (src/field_control_avatar.c): fires on stepping onto the tile.
        self.step_warp = group("MB_ANIMATED_DOOR", "MB_LADDER", "MB_UP_ESCALATOR", "MB_DOWN_ESCALATOR",
                               "MB_NON_ANIMATED_DOOR", "MB_WATER_DOOR", "MB_DEEP_SOUTH_WARP",
                               "MB_LAVARIDGE_GYM_B1F_WARP", "MB_LAVARIDGE_GYM_1F_WARP",
                               "MB_AQUA_HIDEOUT_WARP", "MB_MT_PYRE_HOLE", "MB_MOSSDEEP_GYM_WARP",
                               "MB_BRIDGE_OVER_OCEAN")
        # TryDoorWarp: fires when walking north into the tile.
        self.door = group("MB_ANIMATED_DOOR")
        # TryArrowWarp: fires while standing on the tile and pushing a direction.
        self.arrow = group("MB_NORTH_ARROW_WARP", "MB_WATER_NORTH_ARROW_WARP",
                           "MB_STAIRS_OUTSIDE_ABANDONED_SHIP", "MB_SOUTH_ARROW_WARP",
                           "MB_WATER_SOUTH_ARROW_WARP", "MB_SHOAL_CAVE_ENTRANCE",
                           "MB_WEST_ARROW_WARP", "MB_EAST_ARROW_WARP",
                           "MB_UP_RIGHT_STAIR_WARP", "MB_UP_LEFT_STAIR_WARP",
                           "MB_DOWN_RIGHT_STAIR_WARP", "MB_DOWN_LEFT_STAIR_WARP")
        self.any_warp = self.step_warp | self.door | self.arrow
        self.hole = group("MB_CRACKED_FLOOR_HOLE", "MB_CRACKED_FLOOR")
        self.diveable = group("MB_INTERIOR_DEEP_WATER", "MB_DEEP_WATER", "MB_SOOTOPOLIS_DEEP_WATER")
        self.no_emerge = group("MB_NO_SURFACING", "MB_SEAWEED_NO_SURFACING")
        self.counter = group("MB_COUNTER")
        self.rock_climb = group("MB_ROCK_CLIMB")
        self.jump = {"S": group("MB_JUMP_SOUTH"), "N": group("MB_JUMP_NORTH"),
                     "W": group("MB_JUMP_WEST"), "E": group("MB_JUMP_EAST")}
        # gDirectionBlockedMetatileFuncs (src/event_object_movement.c), by blocked side.
        self.blocks = {
            "S": group("MB_IMPASSABLE_SOUTH", "MB_IMPASSABLE_SOUTHEAST", "MB_IMPASSABLE_SOUTHWEST",
                       "MB_IMPASSABLE_SOUTH_AND_NORTH"),
            "N": group("MB_IMPASSABLE_NORTH", "MB_IMPASSABLE_NORTHEAST", "MB_IMPASSABLE_NORTHWEST",
                       "MB_IMPASSABLE_SOUTH_AND_NORTH", "MB_TALL_GRASS_IMPASSABLE_NORTH",
                       "MB_CAVE_IMPASSABLE_NORTH"),
            "E": group("MB_IMPASSABLE_EAST", "MB_IMPASSABLE_NORTHEAST", "MB_IMPASSABLE_SOUTHEAST",
                       "MB_IMPASSABLE_WEST_AND_EAST", "MB_SECRET_BASE_BREAKABLE_DOOR"),
            "W": group("MB_IMPASSABLE_WEST", "MB_IMPASSABLE_NORTHWEST", "MB_IMPASSABLE_SOUTHWEST",
                       "MB_IMPASSABLE_WEST_AND_EAST", "MB_SECRET_BASE_BREAKABLE_DOOR"),
        }
        # TILE_FLAG_SURFABLE in src/metatile_behavior.c.
        surf = set()
        table = src.text("src/metatile_behavior.c")
        for m in re.finditer(r"\[(MB_\w+)\]\s*=\s*([^,\n]+)", table):
            if "TILE_FLAG_SURFABLE" in m.group(2) and m.group(1) in self.value:
                surf.add(self.value[m.group(1)])
        self.surfable = frozenset(surf)

    def label(self, beh):
        return self.name.get(beh, f"0x{beh:02x}")


def load_metatile_labels(src):
    labels = {}
    for m in re.finditer(r"^#define\s+(METATILE_\w+)\s+(0x[0-9A-Fa-f]+|\d+)", src.text("include/constants/metatile_labels.h"), re.M):
        labels[m.group(1)] = int(m.group(2), 0)
    return labels


def load_tilesets(src):
    """Maps a tileset symbol to the path of its metatile_attributes.bin."""
    arrays = {}
    for m in re.finditer(r"(gMetatileAttributes_\w+)\[\]\s*=\s*INCBIN_U\d+\(\"([^\"]+)\"\)", src.text("src/data/tilesets/metatiles.h")):
        arrays[m.group(1)] = m.group(2)
    tilesets = {}
    for m in re.finditer(r"const struct Tileset (gTileset_\w+)\s*=\s*\{(.*?)\};", src.text("src/data/tilesets/headers.h"), re.S):
        attr = re.search(r"\.metatileAttributes\s*=\s*(\w+)", m.group(2))
        if attr and attr.group(1) in arrays:
            tilesets[m.group(1)] = arrays[attr.group(1)]
    return tilesets


# ---------------------------------------------------------------- scripts

LABEL_RE = re.compile(r"^(\w+):{1,2}")
INCLUDE_RE = re.compile(r'^\s*\.include\s+"(data/[^"]+)"', re.M)
TERMINAL_RE = re.compile(r"^\s*(end|return|goto|step_end|releaseall\s*$|\.2byte\s+0\s*$)")


class ScriptBlock:
    """Commands between one label and the next."""

    def __init__(self, name, path, line):
        self.name = name
        self.path = path
        self.line = line
        self.lines = []         # code lines without comments
        self.numbers = []       # file line number of each code line
        self.refs = set()
        self.next = None
        self.warps = []         # (cmd, map id, warp id, x, y, where)
        self.holes = []         # (map id, where)
        self.respawns = []      # heal location ids
        self.setmetatiles = []  # (x, y, metatile, impassable, where)
        self.layouts = []       # (layout id, where) of setmaplayoutindex


class ScriptIndex:
    """All event script labels of the build with their references and map commands."""

    def __init__(self, src):
        self.blocks = {}
        self.by_file = collections.defaultdict(list)
        files = [p for p in INCLUDE_RE.findall(src.text("data/event_scripts.s") or "")
                 if p not in SKIP_SCRIPT_FILES and not p.startswith("data/text/")]
        files.append("data/event_scripts.s")
        for path in files:
            text = src.text(path)
            if text:
                self._parse(path, text)
        names = set(self.blocks)
        for block in self.blocks.values():
            block.refs = set(re.findall(r"\b[A-Za-z_]\w+\b", "\n".join(block.lines))) & names
            self._commands(block)

    def _parse(self, path, text):
        current = None
        for number, line in enumerate(text.splitlines(), 1):
            m = LABEL_RE.match(line)
            if m:
                block = ScriptBlock(m.group(1), path, number)
                if current is not None and not self._ends(current):
                    current.next = block.name
                self.blocks.setdefault(block.name, block)
                self.by_file[path].append(block.name)
                current = block
                rest = line[m.end():].strip()
                if rest:
                    block.lines.append(rest)
                    block.numbers.append(number)
            elif current is not None:
                code = line.split("@")[0].rstrip()
                if code.strip():
                    current.lines.append(code)
                    current.numbers.append(number)

    @staticmethod
    def _ends(block):
        return bool(block.lines) and bool(TERMINAL_RE.match(block.lines[-1]))

    def _commands(self, block):
        """Collects the map-related commands of one block with their source lines."""
        for code, number in zip(block.lines, block.numbers):
            where = f"{block.path}:{number} ({block.name})"
            m = WARP_CMD_RE.match(code)
            if m:
                args = [a.strip() for a in (m.group(3) or "").split(",") if a.strip()]
                vals = [parse_int(a) for a in args]
                warp_id = x = y = None
                if len(args) == 1:
                    warp_id = vals[0]
                elif len(args) == 2:
                    x, y = vals
                elif len(args) >= 3:
                    warp_id, x, y = vals[:3]
                    if warp_id is not None and warp_id >= 0xFF:
                        warp_id = None
                block.warps.append((m.group(1), m.group(2), warp_id, x, y, where))
            m = HOLE_RE.match(code)
            if m:
                block.holes.append((m.group(2), where))
            m = RESPAWN_RE.match(code)
            if m:
                block.respawns.append(m.group(1))
            m = SETLAYOUT_RE.match(code)
            if m:
                block.layouts.append((m.group(1), where))
            m = SETMETATILE_RE.match(code)
            if m:
                block.setmetatiles.append((int(m.group(1)), int(m.group(2)), m.group(3), m.group(4), where))

    def labels_in_file(self, path):
        return self.by_file.get(path, [])

    def movement_shift(self, label):
        """(dx, dy) a movement script moves its object by, or None if the label is unknown."""
        name, dx, dy = label, 0, 0
        for _ in range(8):
            block = self.blocks.get(name)
            if block is None:
                return None if name == label else (dx, dy)
            for line in block.lines:
                if line.strip() == "step_end":
                    return dx, dy
                m = STEP_RE.match(line)
                if m:
                    sx, sy = STEP_DIR[m.group(2)]
                    dist = STEP_DIST.get(m.group(1), 1)
                    dx, dy = dx + sx * dist, dy + sy * dist
                    continue
                m = DIAG_RE.match(line)
                if m:
                    dx += -1 if m.group(2) == "west" else 1
                    dy += -1 if m.group(1) == "north" else 1
            if not block.next:
                break
            name = block.next
        return dx, dy

    def player_shifts(self, label, limit=400):
        """Offsets the player stands at after each scripted move of a script (all branches)."""
        found = set()
        seen = set()
        stack = [(label, 0, 0, 0)]
        while stack and len(seen) < limit:
            name, i, dx, dy = stack.pop()
            block = self.blocks.get(name)
            if block is None or (name, i, dx, dy) in seen:
                continue
            seen.add((name, i, dx, dy))
            if i >= len(block.lines):
                if block.next and not self._ends(block):
                    stack.append((block.next, 0, dx, dy))
                continue
            line = block.lines[i]
            m = PLAYER_APPLY_RE.match(line)
            if m:
                shift = self.movement_shift(m.group(1))
                if shift and shift != (0, 0):
                    dx, dy = dx + shift[0], dy + shift[1]
                    found.add((dx, dy))
                stack.append((name, i + 1, dx, dy))
                continue
            m = BRANCH_RE.match(line)
            if m and m.group(3) in self.blocks:
                stack.append((m.group(3), 0, dx, dy))
            if line.split()[0] in ("end", "return", "goto", "step_end"):
                continue
            stack.append((name, i + 1, dx, dy))
        found.discard((0, 0))
        return found

    def closure(self, roots):
        """Blocks reachable from the roots through references and fall-through."""
        seen = set()
        stack = [r for r in roots if r in self.blocks]
        out = []
        while stack:
            name = stack.pop()
            if name in seen:
                continue
            seen.add(name)
            block = self.blocks[name]
            out.append(block)
            stack.extend(block.refs - seen)
            if block.next and block.next not in seen:
                stack.append(block.next)
        return out


# ---------------------------------------------------------------- map data

class Layout:
    """One layout with decoded blocks and behaviours."""

    def __init__(self, entry, src, tilesets):
        self.entry = entry
        self.id = entry["id"]
        self.width = entry["width"]
        self.height = entry["height"]
        self.version = entry.get("layout_version") or "emerald"
        self.problems = []  # (code, severity, text) for check 5
        self.blocks = None
        frlg = self.version == "frlg"
        self.attr_size = 4 if frlg else 2
        self.beh_mask = 0x1FF if frlg else 0xFF
        self.num_primary = 512 if self.version == "emerald" else 640
        data = src.read(entry["blockdata_filepath"])
        if data is None:
            self.problems.append(("L-MAPBIN", "blocker", f"map.bin fehlt: {entry['blockdata_filepath']}"))
            return
        expected = self.width * self.height * 2
        if len(data) < expected:
            self.problems.append(("L-MAPBIN", "kritisch", f"{entry['blockdata_filepath']}: {len(data)} Bytes, erwartet "
                                                          f"{expected} ({self.width}x{self.height}); dahinter liegende Daten werden als Karte gelesen"))
        elif len(data) > expected:
            self.problems.append(("L-MAPBIN", "optional", f"{entry['blockdata_filepath']}: {len(data)} Bytes, erwartet "
                                                          f"{expected} ({self.width}x{self.height}); der Rest wird ignoriert"))
        count = min(len(data), expected) // 2
        self.blocks = [data[2 * i] | (data[2 * i + 1] << 8) for i in range(count)]
        self.blocks += [0x0C00] * (self.width * self.height - count)
        self.attr_tables = []
        for key in ("primary_tileset", "secondary_tileset"):
            path = tilesets.get(entry.get(key))
            raw = src.read(path) if path else None
            if raw is None:
                self.problems.append(("L-TILESET", "kritisch", f"{key} {entry.get(key)}: Attributdatei nicht gefunden"))
                raw = b""
            self.attr_tables.append(raw)
        self.beh_of = {}
        self.behaviours = [self.metatile_behaviour(b & 0x3FF) for b in self.blocks]

    def metatile_behaviour(self, metatile):
        """Behaviour value the engine sees (u8 after masking), or None if out of range."""
        if metatile in self.beh_of:
            return self.beh_of[metatile]
        if metatile < self.num_primary:
            table, index = self.attr_tables[0], metatile
        elif metatile < NUM_METATILES_TOTAL:
            table, index = self.attr_tables[1], metatile - self.num_primary
        else:
            table, index = b"", 0
        offset = index * self.attr_size
        if offset + self.attr_size > len(table):
            value = None
        else:
            raw = int.from_bytes(table[offset:offset + self.attr_size], "little")
            value = (raw & self.beh_mask) & 0xFF
        self.beh_of[metatile] = value
        return value


class Map:
    """One map.json plus its layout and per-tile helpers."""

    def __init__(self, data, folder):
        self.data = data
        self.folder = folder
        self.name = data["name"]
        self.id = data["id"]
        self.region = region_of(folder)
        self.active = False
        self.layout = None
        self.events = data           # replaced by the shared_events_map later
        self.scripts_path = f"data/maps/{folder}/scripts.inc"
        self.overrides = collections.defaultdict(list)  # tile index -> [(behaviour, passable, where, elevation)]

    # tile access ------------------------------------------------------
    @property
    def width(self):
        return self.layout.width

    @property
    def height(self):
        return self.layout.height

    def inside(self, x, y):
        return 0 <= x < self.layout.width and 0 <= y < self.layout.height

    def block(self, x, y):
        return self.layout.blocks[x + y * self.layout.width]

    def collision(self, x, y):
        return (self.block(x, y) >> 10) & 3

    def elevation(self, x, y):
        return self.block(x, y) >> 12

    def metatile(self, x, y):
        return self.block(x, y) & 0x3FF

    def behaviour(self, x, y):
        b = self.layout.behaviours[x + y * self.layout.width]
        return -1 if b is None else b

    def behaviours(self, x, y):
        """Base behaviour plus every behaviour a setmetatile of this map can put there."""
        base = self.behaviour(x, y)
        extra = self.overrides.get(x + y * self.layout.width)
        if not extra:
            return (base,)
        return (base,) + tuple(o[0] for o in extra)

    def passable(self, x, y):
        """Collision bits clear, or a setmetatile of this map clears them."""
        if self.collision(x, y) == 0:
            return True
        return any(o[1] for o in self.overrides.get(x + y * self.layout.width, ()))

    def elevations(self, x, y):
        """Base elevation plus elevations a layout swap of this map can put there."""
        base = self.elevation(x, y)
        extra = self.overrides.get(x + y * self.layout.width)
        if not extra:
            return (base,)
        return (base,) + tuple(sorted({o[3] for o in extra if o[3] is not None and o[3] != base}))

    def warps(self):
        return self.events.get("warp_events") or []

    def coord_events(self):
        return self.events.get("coord_events") or []

    def objects(self):
        return self.events.get("object_events") or []

    def bg_events(self):
        return self.events.get("bg_events") or []

    def connections(self):
        """Connections the engine loads (connections_no_include drops them all)."""
        if self.data.get("connections_no_include") in (True, "TRUE"):
            return []
        return self.data.get("connections") or []


def region_of(folder):
    if folder.endswith("_Frlg"):
        return "Kanto"
    if folder.endswith("_hns"):
        return "Johto"
    return "Hoenn"


class World:
    """All maps, layouts, scripts and seeds of one build."""

    def __init__(self, src, version):
        self.src = src
        self.version = version
        self.beh = Behaviors(src)
        self.labels = load_metatile_labels(src)
        self.tilesets = load_tilesets(src)
        groups = json.loads(src.text("data/maps/map_groups.json"))
        grouped = {name for g in groups["group_order"] for name in groups[g]}

        self.maps = {}      # id -> Map
        self.by_name = {}   # name -> Map
        for path in src.list("data/maps/", "/map.json"):
            folder = path.split("/")[2]
            data = json.loads(src.text(path))
            m = Map(data, folder)
            gv = data.get("game_version") or "emerald"
            m.active = gv == version and m.name in grouped
            self.maps[m.id] = m
            self.by_name[m.name] = m
        for m in self.maps.values():
            shared = m.data.get("shared_events_map")
            if shared in self.by_name:
                m.events = self.by_name[shared].data
            shared = m.data.get("shared_scripts_map")
            if shared in self.by_name:
                m.scripts_path = f"data/maps/{self.by_name[shared].folder}/scripts.inc"

        layouts = json.loads(src.text("data/layouts/layouts.json"))["layouts"]
        self.layout_entries = {l["id"]: l for l in layouts if isinstance(l, dict) and "id" in l}
        self.layouts = {}
        for m in self.active_maps():
            entry = self.layout_entries.get(m.data["layout"])
            if entry is None:
                continue
            if entry["id"] not in self.layouts:
                self.layouts[entry["id"]] = Layout(entry, src, self.tilesets)
            m.layout = self.layouts[entry["id"]]

        self.alt_layout_users = collections.defaultdict(set)   # layout id -> maps that swap it in
        self.heal = json.loads(src.text("src/data/heal_locations.json"))["heal_locations"]
        self.heal_by_id = {h["id"]: h for h in self.heal}
        self.c_texts = {p: self.src.text(p) or "" for p in self.src.list("src/", ".c") if p not in SKIP_C_FILES}
        self._load_scripts()
        self._load_c_warps()

    def _add_layout_overrides(self, m, layout_id, where):
        """Tiles a setmaplayoutindex can swap in count like setmetatile overrides."""
        entry = self.layout_entries.get(layout_id)
        if entry is None or layout_id == m.layout.id:
            return
        self.alt_layout_users[layout_id].add(m)
        if (entry.get("game_version") or "emerald") != self.version:
            return
        if layout_id not in self.layouts:
            self.layouts[layout_id] = Layout(entry, self.src, self.tilesets)
        alt = self.layouts[layout_id]
        if alt.blocks is None or (alt.width, alt.height) != (m.width, m.height):
            return
        for i, (a, b) in enumerate(zip(m.layout.blocks, alt.blocks)):
            if (a & 0xFFF) != (b & 0xFFF):
                beh = alt.behaviours[i]
                m.overrides[i].append((-1 if beh is None else beh, (b >> 10) & 3 == 0, f"{where} {layout_id}", b >> 12))

    def active_maps(self):
        return [m for m in self.maps.values() if m.active]

    def usable(self, m):
        return m is not None and m.active and m.layout is not None and m.layout.blocks is not None

    # scripts ----------------------------------------------------------
    def _load_scripts(self):
        """Attributes scripted warps, holes, respawns and setmetatile to the maps that run them."""
        self.scripts = ScriptIndex(self.src)
        self.map_script_warps = collections.defaultdict(list)
        self.map_holes = collections.defaultdict(list)
        self.map_respawns = collections.defaultdict(list)
        self.map_arrival_scripts = set()   # maps whose map scripts run on arrival
        self.map_game_clear = set()        # maps whose scripts end in the Hall of Fame sequence
        self.map_rides = set()             # maps whose own scripts move the player a lot (rides, puzzles)
        self.script_targets = collections.defaultdict(list)   # map id -> [where]
        self.coord_rides = collections.defaultdict(dict)      # map id -> {(x, y): {(dx, dy)}} moved by coord events
        for m in self.active_maps():
            for ce in m.coord_events():
                if ce.get("type") != "weather" and ce.get("script") in self.scripts.blocks:
                    shifts = self.scripts.player_shifts(ce["script"])
                    if shifts:
                        self.coord_rides[m.id].setdefault((ce["x"], ce["y"]), set()).update(shifts)
            roots = set(self.scripts.labels_in_file(m.scripts_path))
            for ev in m.objects() + m.coord_events() + m.bg_events():
                if ev.get("script") in self.scripts.blocks:
                    roots.add(ev["script"])
            text = self.src.text(m.scripts_path) or ""
            if re.search(r"MAP_SCRIPT_ON_(FRAME_TABLE|WARP_INTO_MAP_TABLE)", text):
                self.map_arrival_scripts.add(m.id)
            if len(PLAYER_MOVE_RE.findall(text)) >= RIDE_MIN_MOVES:
                self.map_rides.add(m.id)
            for block in self.scripts.closure(roots):
                if any(GAME_CLEAR_RE.match(line) for line in block.lines):
                    self.map_game_clear.add(m.id)
                for cmd, target, warp_id, x, y, where in block.warps:
                    self.map_script_warps[m.id].append((cmd, target, warp_id, x, y, where))
                    self.script_targets[target].append(where)
                for target, where in block.holes:
                    self.map_holes[m.id].append(target)
                    self.script_targets[target].append(where)
                self.map_respawns[m.id].extend(block.respawns)
                if m.layout is None or m.layout.blocks is None:
                    continue
                for layout_id, where in block.layouts:
                    self._add_layout_overrides(m, layout_id, where)
                for x, y, tile_name, impassable_text, where in block.setmetatiles:
                    tile = self.labels.get(tile_name, parse_int(tile_name))
                    impassable = parse_int(impassable_text)
                    if tile is None or impassable is None or not m.inside(x, y):
                        continue
                    beh = m.layout.metatile_behaviour(tile & 0x3FF)
                    m.overrides[x + y * m.width].append((-1 if beh is None else beh, impassable == 0, where, None))
        # Scripts started from C run without a map context: their warps are global seeds.
        self.global_script_warps = []
        c_roots = set()
        for text in self.c_texts.values():
            c_roots.update(set(re.findall(r"\b[A-Za-z_]\w+\b", text)) & self.scripts.blocks.keys())
        for block in self.scripts.closure(c_roots):
            for entry in block.warps:
                self.global_script_warps.append(entry)
                self.script_targets[entry[1]].append(entry[5])

    def _load_c_warps(self):
        """Warp destinations written in C, and other C references to maps."""
        self.c_warps = []                  # (map_id, warp_id, x, y, where)
        self.c_refs = collections.defaultdict(list)
        for path, text in self.c_texts.items():
            for m in C_WARP_RE.finditer(text):
                line = text.count("\n", 0, m.start()) + 1
                self.c_warps.append((m.group(1), parse_int(m.group(2)), parse_int(m.group(3)),
                                     parse_int(m.group(4)), f"{path}:{line}"))
            for m in C_TABLE_RE.finditer(text):
                line = text.count("\n", 0, m.start()) + 1
                self.c_warps.append((m.group(1), None, parse_int(m.group(2)), parse_int(m.group(3)),
                                     f"{path}:{line}"))
            for m in C_MAPREF_RE.finditer(text):
                line = text.count("\n", 0, m.start()) + 1
                self.c_refs[m.group(1)].append(f"{path}:{line}")


# ---------------------------------------------------------------- movement

class Walker:
    """Player movement rules (optimistic, see module docstring)."""

    def __init__(self, world):
        self.world = world
        self.beh = world.beh

    @staticmethod
    def arrival_state(m, x, y):
        """(cur, prev) elevation right after the player is placed on (x, y) of the base layout."""
        return Walker.arrival_states(m, x, y)[0]

    @staticmethod
    def arrival_states(m, x, y):
        """(cur, prev) pairs for every elevation the tile can have."""
        return [(0, 0) if e == 15 else (e, e) for e in m.elevations(x, y)]

    def step(self, m, x, y, cur, prev, d):
        """First state one push in direction d leads to, or None."""
        found = self.steps(m, x, y, cur, prev, d)
        return found[0] if found else None

    def steps(self, m, x, y, cur, prev, d):
        """States one push in direction d leads to: [(map, x, y, cur, prev)]."""
        dx, dy = DIRS[d]
        nm, nx, ny = self.neighbour(m, x, y, dx, dy, d)
        if nm is None:
            return []
        nbehs = nm.behaviours(nx, ny)
        # Ledge jumps ignore collision and elevation and land two tiles further.
        if any(b in self.beh.jump[d] for b in nbehs) and nm is m:
            lx, ly = nx + dx, ny + dy
            if not m.inside(lx, ly):
                return []
            return [(m, lx, ly, e if e != 15 else cur, e if e not in (0, 15) else prev) for e in m.elevations(lx, ly)]
        opposite = {"N": "S", "S": "N", "W": "E", "E": "W"}[d]
        if all(b in self.beh.blocks[d] for b in m.behaviours(x, y)):
            return []
        if all(b in self.beh.blocks[opposite] for b in nbehs):
            return []
        climb = any(b in self.beh.rock_climb for b in nbehs)
        if not nm.passable(nx, ny) and not climb:
            return []
        if climb:
            return [(nm, nx, ny, 0, prev)]
        surfing = any(b in self.beh.surfable for b in m.behaviours(x, y))
        start_surf = prev == 3 and any(b in self.beh.surfable for b in nbehs)
        out = []
        for e in nm.elevations(nx, ny):
            if cur != 0 and e not in (0, 15) and e != cur and not (start_surf or (surfing and e == 3)):
                continue
            if e == 15 or m.elevation(x, y) == 15:
                out.append((nm, nx, ny, cur, prev))
            else:
                out.append((nm, nx, ny, e, e if e != 0 else prev))
        return out

    def neighbour(self, m, x, y, dx, dy, d):
        """Tile next to (x, y), following a map connection at the edge."""
        nx, ny = x + dx, y + dy
        if m.inside(nx, ny):
            return m, nx, ny
        direction = EDGE_DIR[d]
        for conn in m.connections():
            if conn.get("direction") != direction:
                continue
            other = self.world.maps.get(conn.get("map"))
            if not self.world.usable(other):
                continue
            off = int(conn.get("offset", 0))
            if direction in ("up", "down"):
                tx = nx - off
                ty = other.height - 1 if direction == "up" else 0
            else:
                ty = ny - off
                tx = other.width - 1 if direction == "left" else 0
            if other.inside(tx, ty):
                return other, tx, ty
        return None, None, None

    def warp_elevation_ok(self, warp, position_elevation):
        return warp["elevation"] == 0 or warp["elevation"] == position_elevation

    def stuck(self, m, x, y, cur, prev):
        """True if the player can neither walk off (x, y) nor use an arrow warp there."""
        if any(b in self.beh.arrow for b in m.behaviours(x, y)):
            return False
        return all(self.step(m, x, y, cur, prev, d) is None for d in DIRS)


# ---------------------------------------------------------------- reachability

class Reach:
    """Walk over all active maps from the new-game position."""

    def __init__(self, world):
        self.world = world
        self.walker = Walker(world)
        self.states = collections.defaultdict(set)    # map id -> {(x, y, cur, prev)}
        self.tiles = collections.defaultdict(dict)    # map id -> {(x, y): {prev}}
        self.used_warps = set()                       # (map id, warp index)
        self.entered = set()
        self.queue = collections.deque()
        self.incoming = collections.defaultdict(list)  # map id -> [(src map id, warp index)]
        self.dynamic_returns = collections.defaultdict(set)  # map id -> warps the player came in by
        self.dynamic_fired = set()                           # maps whose MAP_DYNAMIC warp was used
        for m in world.active_maps():
            for i, w in enumerate(m.warps()):
                self.incoming[w["dest_map"]].append((m.id, i))

    def seed(self, map_id, x=None, y=None, warp_id=None):
        """Places the player on a map: by coordinates, by warp id or, if unknown, on every warp tile."""
        m = self.world.maps.get(map_id)
        if not self.world.usable(m):
            return
        spots = []
        if warp_id is not None and 0 <= warp_id < len(m.warps()):
            w = m.warps()[warp_id]
            spots.append((w["x"], w["y"]))
        elif x is not None and y is not None:
            spots.append((x, y))
        else:
            spots += [(w["x"], w["y"]) for w in m.warps()]
            spots += [(h["x"], h["y"]) for h in self.world.heal if h["map"] == map_id]
        for sx, sy in spots:
            if not m.inside(sx, sy):
                continue
            for cur, prev in Walker.arrival_states(m, sx, sy):
                self.push(m, sx, sy, cur, prev)
                if m.id in self.world.map_arrival_scripts and self.walker.stuck(m, sx, sy, cur, prev):
                    for tx, ty in self.walk_in_tiles(m, sx, sy):
                        for state in Walker.arrival_states(m, tx, ty):
                            self.push(m, tx, ty, *state)

    @staticmethod
    def walk_in_tiles(m, x, y, limit=5):
        """Nearest walkable tiles a scripted walk-in can bring the player to (through walls)."""
        seen = {(x, y)}
        ring = [(x, y)]
        for _ in range(limit):
            nxt = []
            for cx, cy in ring:
                for dx, dy in DIRS.values():
                    p = (cx + dx, cy + dy)
                    if p not in seen and m.inside(*p):
                        seen.add(p)
                        nxt.append(p)
            found = [p for p in nxt if m.passable(*p)]
            if found:
                return found
            ring = nxt
        return []

    def push(self, m, x, y, cur, prev):
        key = (x, y, cur, prev)
        bucket = self.states[m.id]
        if key in bucket:
            return
        bucket.add(key)
        self.tiles[m.id].setdefault((x, y), set()).add(prev)
        self.queue.append((m, x, y, cur, prev))

    def on_enter(self, m):
        """Seeds that open up once a map is reached (its scripts, its fly spot)."""
        self.entered.add(m.id)
        w = self.world
        for cmd, target, warp_id, x, y, _ in w.map_script_warps.get(m.id, ()):
            self.seed(target, x, y, warp_id)
        for hid in w.map_respawns.get(m.id, ()):
            h = w.heal_by_id.get(hid)
            if h and h.get("respawn_map"):
                self.seed(h["respawn_map"], h.get("respawn_x"), h.get("respawn_y"))
            if h:
                self.seed(h["map"], h["x"], h["y"])
        for h in w.heal:
            if h["map"] == m.id:
                self.seed(m.id, h["x"], h["y"])

    def follow_warp(self, m, index):
        w = m.warps()[index]
        self.used_warps.add((m.id, index))
        dest = w["dest_map"]
        if dest == "MAP_DYNAMIC":
            # A dynamic warp returns to the warp the player came in by.
            self.dynamic_fired.add(m.id)
            for src_id, src_index in self.dynamic_returns[m.id]:
                sw = self.world.maps[src_id].warps()[src_index]
                self.seed(src_id, sw["x"], sw["y"])
            return
        dm = self.world.maps.get(dest)
        wid = parse_int(str(w["dest_warp_id"]))
        if not self.world.usable(dm) or wid is None or not 0 <= wid < len(dm.warps()):
            return
        if (m.id, index) not in self.dynamic_returns[dm.id]:
            self.dynamic_returns[dm.id].add((m.id, index))
            if dm.id in self.dynamic_fired:
                self.seed(m.id, w["x"], w["y"])
        self.seed(dest, warp_id=wid)

    def warps_at(self, m, x, y):
        return [i for i, w in enumerate(m.warps()) if w["x"] == x and w["y"] == y]

    def fired_warps(self, m, x, y, prev):
        """Warp indices the player can fire from (x, y): standing/stepping on it, or a door to the north."""
        beh = self.world.beh
        fired = []
        behs = m.behaviours(x, y)
        if any(b in beh.step_warp or b in beh.arrow for b in behs):
            for i in self.warps_at(m, x, y):
                if self.walker.warp_elevation_ok(m.warps()[i], prev):
                    fired.append(i)
        if y > 0 and any(b in beh.door for b in m.behaviours(x, y - 1)):
            pos_elev = prev if m.elevation(x, y) != 0 else 0
            for i in self.warps_at(m, x, y - 1):
                if self.walker.warp_elevation_ok(m.warps()[i], pos_elev):
                    fired.append(i)
        return fired

    def coordinate_exits(self, m, x, y):
        """Maps entered at the same coordinates by diving, emerging or falling."""
        beh = self.world.beh
        behs = m.behaviours(x, y)
        out = []
        for conn in m.connections():
            d = conn.get("direction")
            if d == "dive" and any(b in beh.diveable for b in behs):
                out.append(conn["map"])
            elif d == "emerge" and not any(b in beh.no_emerge for b in behs):
                out.append(conn["map"])
        if any(b in beh.hole for b in behs):
            out.extend(t for t in self.world.map_holes.get(m.id, ()) if t != "MAP_UNDEFINED")
        return out

    def run(self):
        world = self.world
        self.seed(START_MAP, *START_POS)
        for _, target, warp_id, x, y, _ in world.global_script_warps:
            self.seed(target, x, y, warp_id)
        for target, warp_id, x, y, _ in world.c_warps:
            self.seed(target, x, y, warp_id)
        while self.queue:
            m, x, y, cur, prev = self.queue.popleft()
            if m.id not in self.entered:
                self.on_enter(m)
            for i in self.fired_warps(m, x, y, prev):
                self.follow_warp(m, i)
            for target in self.coordinate_exits(m, x, y):
                self.seed(target, x, y)
            for tx, ty in self.ride_targets(m, x, y):
                for state in Walker.arrival_states(m, tx, ty):
                    self.push(m, tx, ty, *state)
            for d in DIRS:
                for nxt in self.walker.steps(m, x, y, cur, prev, d):
                    self.push(*nxt)
        return self

    def ride_targets(self, m, x, y):
        """Passable tiles a coord event on (x, y) moves the player to by applymovement."""
        out = []
        for dx, dy in self.world.coord_rides.get(m.id, {}).get((x, y), ()):
            tx, ty = x + dx, y + dy
            if m.inside(tx, ty) and m.passable(tx, ty):
                out.append((tx, ty))
        return out

    def escapes(self, m, x, y):
        """True if the player placed on (x, y) can leave the map by walking, warping or a connection."""
        start = (x, y) + Walker.arrival_state(m, x, y)
        seen = {start}
        stack = [start]
        if m.id in self.world.map_arrival_scripts and self.walker.stuck(m, *start):
            for tx, ty in self.walk_in_tiles(m, x, y):
                state = (tx, ty) + Walker.arrival_state(m, tx, ty)
                seen.add(state)
                stack.append(state)
        # Going back through the arrival warp counts: arrow warps fire at once, others after a step off and on.
        if self.fired_warps(m, x, y, start[3]):
            if any(b in self.world.beh.arrow for b in m.behaviours(x, y)) or not self.walker.stuck(m, *start):
                return True
        while stack:
            state = stack.pop()
            cx, cy, cur, prev = state
            if state != start and self.fired_warps(m, cx, cy, prev):
                return True
            if self.coordinate_exits(m, cx, cy):
                return True
            nexts = [(tx, ty) + Walker.arrival_state(m, tx, ty) for tx, ty in self.ride_targets(m, cx, cy)]
            for d in DIRS:
                for nxt in self.walker.steps(m, cx, cy, cur, prev, d):
                    if nxt[0] is not m:
                        return True
                    nexts.append(nxt[1:])
            for state in nexts:
                if state not in seen:
                    seen.add(state)
                    stack.append(state)
        return False

    def map_reached(self, map_id):
        return map_id in self.entered

    def tile_reached(self, map_id, x, y):
        return (x, y) in self.tiles.get(map_id, {})


# ---------------------------------------------------------------- findings

class Finding:
    def __init__(self, check, code, m, coords, status, severity, text, details=(), index=None):
        self.check = check
        self.code = code
        self.map = m.name if m else ""
        self.region = m.region if m else "-"
        self.coords = coords
        self.status = status
        self.severity = severity
        self.text = text
        self.details = list(details)
        self.index = index

    def where(self):
        if self.coords is None:
            return self.map
        return f"{self.map} ({self.coords[0]},{self.coords[1]})"

    def as_dict(self):
        return {"check": self.check, "code": self.code, "region": self.region, "map": self.map,
                "coords": self.coords, "index": self.index, "status": self.status,
                "severity": self.severity, "text": self.text, "details": self.details}


class Checker:
    def __init__(self, world, reach):
        self.world = world
        self.reach = reach
        self.walker = reach.walker
        self.beh = world.beh
        self.findings = []
        self.item_of_script = self._item_scripts()
        self._effect_cache = {}
        # Object scripts used on several maps (attendants, cable club) are no map-specific content.
        users = collections.defaultdict(set)
        for m in world.active_maps():
            for o in m.objects():
                users[o.get("script", "")].add(m.id)
        self.common_scripts = {s for s, ids in users.items() if len(ids) >= COMMON_SCRIPT_MAPS}
        self.map_text = {}

    def add(self, *args, **kwargs):
        self.findings.append(Finding(*args, **kwargs))

    def blocking_object(self, m, x, y):
        """Text for an object that always stands on (x, y) and no script of the map moves, or None."""
        if m.id not in self.map_text:
            self.map_text[m.id] = self.world.src.text(m.scripts_path) or ""
        for i, o in enumerate(m.objects()):
            if (o.get("x"), o.get("y")) != (x, y) or o.get("flag", "0") not in ("0", 0, ""):
                continue
            if not STATIONARY_RE.match(o.get("movement_type", "")):
                continue
            local = o.get("local_id")
            if local and re.search(rf"\b(applymovement|setobjectxy\w*|removeobject|moveobjectoffscreen)\s+{local}\b",
                                   self.map_text[m.id]):
                continue
            return f"Objekt {i} ({o.get('script', '')}) steht ohne Flag fest auf ({x},{y}), kein Skript der Karte bewegt es"
        return None

    def describe_tile(self, m, x, y):
        b = m.behaviour(x, y)
        return (f"Metatile 0x{m.metatile(x, y):03x}, {self.beh.label(b)}, Kollision {m.collision(x, y)}, "
                f"Höhe {m.elevation(x, y)}")

    # check 1 ------------------------------------------------------------
    def warp_trigger(self, m, i, w):
        """How warp i can fire: (kind, approach tile) or (None, reason code, reason text)."""
        x, y = w["x"], w["y"]
        behs = m.behaviours(x, y)
        base = m.behaviour(x, y)
        if any(b in self.beh.door for b in behs) and y + 1 < m.height:
            if m.passable(x, y + 1):
                return ("Tür", (x, y + 1))
            if not m.passable(x, y):
                return (None, "W-TUER-VERSPERRT", "Feld vor der Tür (Süden) ist Kollision")
        if any(b in self.beh.step_warp for b in behs):
            if m.passable(x, y) and self._enterable(m, x, y):
                return ("Betreten", (x, y))
            return (None, "W-NICHT-BETRETBAR", "Warp-Kachel löst nur beim Betreten aus, ist aber nicht betretbar")
        if any(b in self.beh.arrow for b in behs):
            if m.passable(x, y) and self._enterable(m, x, y):
                return ("Pfeil", (x, y))
            return (None, "W-PFEIL-WAND", "Pfeil-/Treppenkachel ist Kollision, nur direkt nach der Ankunft nutzbar")
        return (None, "W-NICHT-AUSLOESBAR", f"Kachel hat kein Warp-Verhalten ({self.beh.label(base)})")

    def _enterable(self, m, x, y):
        for d, (dx, dy) in DIRS.items():
            sx, sy = x - dx, y - dy
            if m.inside(sx, sy) and m.passable(sx, sy):
                e = m.elevation(sx, sy)
                if self.walker.step(m, sx, sy, e, e, d) is not None:
                    return True
        return False

    def nearby_warp_tiles(self, m, x, y, radius=2):
        """Tiles with warp behaviour near (x, y) that have no warp event (fix hint)."""
        warp_tiles = {(w["x"], w["y"]) for w in m.warps()}
        hits = []
        for yy in range(y - radius, y + radius + 1):
            for xx in range(x - radius, x + radius + 1):
                if m.inside(xx, yy) and (xx, yy) not in warp_tiles and m.behaviour(xx, yy) in self.beh.any_warp:
                    hits.append(f"({xx},{yy}) {self.beh.label(m.behaviour(xx, yy))}")
        return hits

    def check_warps(self):
        world, reach = self.world, self.reach
        for m in world.active_maps():
            if not world.usable(m):
                continue
            groups = collections.defaultdict(list)
            for i, w in enumerate(m.warps()):
                groups[w["dest_map"]].append(i)
            for i, w in enumerate(m.warps()):
                x, y = w["x"], w["y"]
                where = f"data/maps/{m.folder}/map.json warp_events[{i}]"
                dest = w["dest_map"]
                if not m.inside(x, y):
                    # Never fires; as an arrival spot it puts the player outside the map (check 2).
                    _, sev, consequence = self._dead_warp_rating(m, i, w, groups, False, False)
                    self.add(1, "W-AUSSERHALB", m, (x, y), "nachgewiesen", sev,
                             f"Warp {i} → {self._dest_name(w)} liegt außerhalb der Karte ({m.width}x{m.height})",
                             [where, consequence], index=i)
                    continue
                trig = self.warp_trigger(m, i, w)
                source_ok = trig[0] is not None and reach.tile_reached(m.id, *trig[1])
                if dest != "MAP_DYNAMIC":
                    self._check_warp_target(m, i, w, where, trig, source_ok)
                if trig[0] is None:
                    self._report_dead_warp(m, i, w, groups, trig[1], trig[2])
                    continue
                problem = self._warp_elevation_problem(m, w, trig)
                if problem:
                    self._report_dead_warp(m, i, w, groups, "W-HOEHE", problem)

    def _check_warp_target(self, m, i, w, where, trig, source_ok):
        """Target map must be active and have the target warp id."""
        world = self.world
        dest = w["dest_map"]
        dm = world.maps.get(dest)
        wid = parse_int(str(w["dest_warp_id"]))
        status = "nachgewiesen"
        if source_ok:
            sev, note = "kritisch", "Quelle erreichbar und auslösbar"
            blocker = self.blocking_object(m, *trig[1])
            if blocker:
                status, sev, note = "verdacht", "klein", "Quelle nur ohne Objekte erreichbar: " + blocker
        elif self.reach.map_reached(m.id):
            sev, note = "klein", "Quelle nicht nutzbar"
        else:
            sev, note = "optional", "Quelle nicht nutzbar, Karte selbst nicht erreichbar"
        if dm is None:
            self.add(1, "W-ZIEL-FEHLT", m, (w["x"], w["y"]), status, sev,
                     f"Warp {i} führt zu {dest}, die Karte gibt es nicht", [where, note], index=i)
        elif not dm.active:
            self.add(1, "W-ZIEL-INAKTIV", m, (w["x"], w["y"]), status, sev,
                     f"Warp {i} führt zu {dm.name} (game_version {dm.data.get('game_version')}), "
                     f"im Build ein NULL-Header", [where, note], index=i)
        elif wid is not None and not 0 <= wid < len(dm.warps()):
            self.add(1, "W-ZIEL-ID", m, (w["x"], w["y"]), status, sev,
                     f"Warp {i} führt zu {dm.name} Warp-ID {wid}, die Karte hat nur {len(dm.warps())} Warps",
                     [where, note], index=i)

    def _report_dead_warp(self, m, i, w, groups, code, reason):
        """Adds a finding for a warp that never fires, rated by what is lost."""
        world, reach = self.world, self.reach
        x, y = w["x"], w["y"]
        details = [f"data/maps/{m.folder}/map.json warp_events[{i}]",
                   f"Kachel ({x},{y}): {self.describe_tile(m, x, y)}", reason]
        overrides = m.overrides.get(x + y * m.width)
        if overrides:
            details.append("Skript ändert dieses Feld: " + ", ".join(o[2] for o in overrides[:4]))
        hints = self.nearby_warp_tiles(m, x, y)
        if hints:
            details.append("Warp-Kacheln ohne Warp in der Nähe: " + "; ".join(hints))
        dest_name = self._dest_name(w)
        scripted = [(c["x"], c["y"], c.get("script", "")) for c in m.coord_events()
                    if c.get("type") != "weather" and abs(c["x"] - x) + abs(c["y"] - y) <= 2]
        script_warps = [e[5] for e in world.map_script_warps.get(m.id, ()) if e[1] == w["dest_map"]]
        if scripted or script_warps:
            if scripted:
                details.append("Coord-Events: " + ", ".join(f"({cx},{cy}) {s}" for cx, cy, s in scripted))
            if script_warps:
                details.append("Skript-Warps dieser Karte zum selben Ziel: " + ", ".join(sorted(set(script_warps))[:3]))
            self.add(1, "W-SKRIPT", m, (x, y), "vorschlag", "optional",
                     f"Warp {i} → {dest_name} wird per Skript bedient ({code})", details, index=i)
            return
        warp_tile = any(b in self.beh.any_warp for b in m.behaviours(x, y))
        status, severity, consequence = self._dead_warp_rating(m, i, w, groups, bool(hints), warp_tile)
        details.append(consequence)
        text = {"W-NICHT-AUSLOESBAR": f"Warp {i} → {dest_name} ist nicht auslösbar",
                "W-NICHT-BETRETBAR": f"Warp {i} → {dest_name}: Warp-Feld nicht betretbar",
                "W-TUER-VERSPERRT": f"Warp {i} → {dest_name}: Tür ohne begehbares Feld davor",
                "W-PFEIL-WAND": f"Warp {i} → {dest_name}: Pfeil-Warp auf Kollisionsfeld",
                "W-HOEHE": f"Warp {i} → {dest_name}: Höhe des Warps passt nicht zur Spielerhöhe"}[code]
        if code == "W-PFEIL-WAND":
            arrivals = [s for s, si in reach.incoming.get(m.id, ()) if self._dest_index(s, si) == i]
            if arrivals:
                status, severity = "verdacht", "optional"
                details.append("Ankunftsfeld von " + ", ".join(sorted({world.maps[s].name for s in arrivals}))
                               + ": direkt nach der Ankunft nutzbar")
        self.add(1, code, m, (x, y), status, severity, text, details, index=i)

    def _warp_elevation_problem(self, m, w, trig):
        """Reason text if the warp elevation never matches the player's elevation on the trigger tile."""
        if w["elevation"] == 0:
            return None
        kind, (ax, ay) = trig
        prevs = self.reach.tiles.get(m.id, {}).get((ax, ay))
        if not prevs:
            return None
        if kind == "Tür" and m.elevation(ax, ay) == 0:
            return (f"Feld vor der Tür ({ax},{ay}) hat Höhe 0: der Tür-Warp löst dann nur mit Warp-Höhe 0 aus, "
                    f"hat aber Höhe {w['elevation']}")
        if w["elevation"] not in prevs:
            return (f"Warp-Höhe {w['elevation']}, Spielerhöhe auf ({ax},{ay}) ist {sorted(prevs)} "
                    f"(GetWarpEventAtPosition verlangt Gleichheit oder Warp-Höhe 0)")
        return None

    def _dest_name(self, w):
        dm = self.world.maps.get(w["dest_map"])
        return dm.name if dm else w["dest_map"]

    def _dest_index(self, src_id, src_index):
        return parse_int(str(self.world.maps[src_id].warps()[src_index]["dest_warp_id"]))

    def _dead_warp_rating(self, m, i, w, groups, hints, warp_tile):
        """Status, severity and consequence text of a warp that cannot fire.

        A warp next to a door/arrow tile without warp is most likely shifted by
        one tile; a warp on a visible door/ladder/arrow tile is expected to work.
        Other dead warps that something warps onto are often only arrival spots
        (one-way by design, e.g. Elite Four rooms).
        """
        reach = self.reach
        wid = parse_int(str(w["dest_warp_id"]))
        if w["dest_map"] == m.id and wid == i:
            return "nachgewiesen", "optional", "Warp zeigt auf sich selbst (Platzhalter, Bedienung per Skript)"
        if not reach.map_reached(m.id):
            return "nachgewiesen", "optional", "Ohne Wirkung: die Karte selbst ist nicht erreichbar"
        lost, content = self._target_loss(m, w)
        if lost and not content:
            return "nachgewiesen", "optional", f"{lost} hat keinen anderen Zugang, aber auch keinen Inhalt"
        x, y = w["x"], w["y"]
        near = [(x + dx, y + dy) for dx, dy in DIRS.values()] + [(x, y)]
        if not any(m.inside(nx, ny) and reach.tile_reached(m.id, nx, ny) for nx, ny in near):
            if lost:
                return "nachgewiesen", "wichtig", (f"{lost} hat keinen anderen Zugang; zusätzlich ist das Warp-Feld "
                                                   "selbst nicht erreichbar (abgeschnittener Kartenteil)")
            return "nachgewiesen", "optional", "Ohne Wirkung: das Feld ist ohnehin nicht erreichbar"
        if lost:
            return "nachgewiesen", "kritisch", f"{lost} hat keinen anderen Zugang; Inhalt: " + ", ".join(content[:6])
        siblings = [j for j in groups[w["dest_map"]] if j != i and (m.id, j) in reach.used_warps]
        if siblings:
            sev = "klein" if hints or warp_tile else "optional"
            return "nachgewiesen", sev, f"Andere Warps zum selben Ziel funktionieren: {siblings}"
        if warp_tile:
            return "nachgewiesen", "wichtig", "Zielkarte ist anders erreichbar; die sichtbare Warp-Kachel funktioniert nicht"
        if hints:
            return "nachgewiesen", "wichtig", "Zielkarte ist anders erreichbar; dieser Weg fehlt (Warp vermutlich versetzt)"
        arrivals = sorted({self.world.maps[s].name for s, si in reach.incoming.get(m.id, ())
                           if self._dest_index(s, si) == i})
        if arrivals:
            return "verdacht", "optional", ("Nur Ankunftspunkt (von " + ", ".join(arrivals)
                                            + "); Rückweg über dieses Feld nicht möglich, oft gewollt")
        return "verdacht", "optional", "Zielkarte ist anders erreichbar; Warp ohne Funktion"

    def _target_loss(self, m, w):
        """(what, content) the dead warp alone leads to, or (None, None) if the target is reachable otherwise."""
        dm = self.world.maps.get(w["dest_map"])
        wid = parse_int(str(w["dest_warp_id"]))
        if not self.world.usable(dm) or wid is None or not 0 <= wid < len(dm.warps()):
            return None, None
        if not self.reach.map_reached(dm.id):
            return "Zielkarte", self.map_content(dm, exclude=m.id)
        t = dm.warps()[wid]
        around = [(t["x"] + dx, t["y"] + dy) for dx, dy in DIRS.values()] + [(t["x"], t["y"])]
        if any(self.reach.tile_reached(dm.id, ax, ay) for ax, ay in around):
            return None, None
        return "Zielbereich", self.area_content(dm, t["x"], t["y"], wid)

    def map_content(self, m, exclude=None, seen=None):
        """Items, trainers, NPCs with effects and maps behind it (other than exclude) of a map."""
        seen = seen if seen is not None else {m.id}
        found = []
        for o in m.objects():
            kind, detail = self.object_kind(o)
            if kind in ("Item-Ball", "Trainer", "Figur", "Beerenbaum"):
                found.append(f"{kind} {detail}".strip())
        found += [f"verstecktes Item {b.get('item', '')}" for b in m.bg_events() if b.get("type") == "hidden_item"]
        for w in m.warps():
            dm = self.world.maps.get(w["dest_map"])
            if self.world.usable(dm) and dm.id != exclude and dm.id not in seen and not self.reach.map_reached(dm.id):
                seen.add(dm.id)
                if self.map_content(dm, exclude, seen):
                    found.append(f"dahinter {dm.name}")
        return found

    def area_content(self, m, x, y, own_warp):
        """Objects, signs, items and other warps in the walkable area around (x, y)."""
        if not m.inside(x, y):
            return []
        start = [p for p in [(x, y)] + [(x + dx, y + dy) for dx, dy in DIRS.values()] if m.inside(*p)]
        todo = [p for p in start if m.passable(*p)]
        area = set(todo)
        while todo:
            cx, cy = todo.pop()
            for dx, dy in DIRS.values():
                p = (cx + dx, cy + dy)
                if p not in area and m.inside(*p) and m.passable(*p):
                    area.add(p)
                    todo.append(p)
        area.update(start)
        found = [f"Objekt {i}" for i, o in enumerate(m.objects()) if (o.get("x"), o.get("y")) in area]
        found += [f"bg {i}" for i, b in enumerate(m.bg_events()) if (b["x"], b["y"]) in area]
        found += [f"Warp {i}" for i, w in enumerate(m.warps()) if i != own_warp and (w["x"], w["y"]) in area]
        return found

    # check 2 ------------------------------------------------------------
    def check_targets(self):
        world, reach = self.world, self.reach
        seen = set()
        for m in world.active_maps():
            if not world.usable(m):
                continue
            for i, w in enumerate(m.warps()):
                dm = world.maps.get(w["dest_map"])
                wid = parse_int(str(w["dest_warp_id"]))
                if not world.usable(dm) or wid is None or not 0 <= wid < len(dm.warps()):
                    continue
                key = (dm.id, wid)
                used = (m.id, i) in reach.used_warps
                if key in seen and not used:
                    continue
                seen.add(key)
                t = dm.warps()[wid]
                tx, ty = t["x"], t["y"]
                where = f"data/maps/{m.folder}/map.json warp_events[{i}] → data/maps/{dm.folder}/map.json warp_events[{wid}]"
                if not dm.inside(tx, ty):
                    sev = "kritisch" if used else "klein" if reach.map_reached(m.id) else "optional"
                    self.add(2, "Z-AUSSERHALB", dm, (tx, ty), "nachgewiesen", sev,
                             f"Ankunftsfeld von {m.name} Warp {i} liegt außerhalb der Karte", [where], index=wid)
                    continue
                if used and not reach.escapes(dm, tx, ty):
                    scripted = bool(world.map_script_warps.get(dm.id)) or dm.id in world.map_game_clear
                    severity = "optional" if dm.id in world.map_game_clear else "klein" if scripted else "wichtig"
                    self.add(2, "Z-SACKGASSE", dm, (tx, ty), "verdacht" if scripted else "nachgewiesen", severity,
                             f"Ankunft von {m.name} Warp {i}: von hier führt kein Weg aus der Karte "
                             f"(nur Fliegen/Teleport/Fluchtseil)",
                             [where, "Karte hat Skript-Warps oder die Ruhmeshalle (Ausgang evtl. per Skript)" if scripted
                              else "Karte hat keine Skript-Warps"], index=wid)
                cur, prev = Walker.arrival_state(dm, tx, ty)
                exits = [d for d in DIRS if self.walker.step(dm, tx, ty, cur, prev, d) is not None]
                own_warp = any(b in self.beh.arrow for b in dm.behaviours(tx, ty))
                if not exits and not own_warp:
                    details = [where, f"Kachel: {self.describe_tile(dm, tx, ty)}",
                               "Quelle wird im Spiel benutzt" if used else "Quelle wird nie ausgelöst"]
                    status, severity = "nachgewiesen", "kritisch" if used else "klein"
                    if dm.id in world.map_arrival_scripts and Reach.walk_in_tiles(dm, tx, ty):
                        status, severity = "verdacht", "optional"
                        details.append("Zielkarte hat ON_FRAME/ON_WARP_INTO-Skripte; vermutlich führt ein Skript "
                                       "den Spieler herein (applymovement)")
                    self.add(2, "Z-EINGESPERRT", dm, (tx, ty), status, severity,
                             f"Ankunft von {m.name} Warp {i}: kein begehbares Nachbarfeld (Softlock)",
                             details, index=wid)
                elif not dm.passable(tx, ty) and not any(b in self.beh.any_warp for b in dm.behaviours(tx, ty)):
                    self.add(2, "Z-IN-WAND", dm, (tx, ty), "nachgewiesen", "optional",
                             f"Ankunft von {m.name} Warp {i} auf Kollisionsfeld ohne Warp-Verhalten",
                             [where, f"Kachel: {self.describe_tile(dm, tx, ty)}"], index=wid)

    # check 3 ------------------------------------------------------------
    def _item_scripts(self):
        """Item-ball script label -> item constant (label starting with finditem ITEM_X)."""
        items = {}
        for block in self.world.scripts.blocks.values():
            m = re.match(r"\s*finditem\s+(ITEM_\w+)", block.lines[0]) if block.lines else None
            if m:
                items[block.name] = m.group(1)
        return items

    def stand_tiles(self, m, x, y):
        """Tiles from which the player can talk to / pick up something on (x, y)."""
        out = []
        for dx, dy in DIRS.values():
            nx, ny = x + dx, y + dy
            if not m.inside(nx, ny):
                continue
            if m.passable(nx, ny):
                out.append((nx, ny))
            if m.behaviour(nx, ny) in self.beh.counter and m.inside(nx + dx, ny + dy) and m.passable(nx + dx, ny + dy):
                out.append((nx + dx, ny + dy))
        return out

    def object_kind(self, obj):
        """(kind, detail): Item-Ball, Trainer, Beerenbaum, Figur (script with effect) or Deko."""
        gfx = obj.get("graphics_id", "")
        script = obj.get("script", "")
        if "ITEM_BALL" in gfx or script in self.item_of_script or script == "Common_EventScript_FindItem":
            item = self.item_of_script.get(script) or obj.get("trainer_sight_or_berry_tree_id", "")
            return "Item-Ball", item
        if obj.get("trainer_type", "TRAINER_TYPE_NONE") not in ("TRAINER_TYPE_NONE", "0", 0):
            return "Trainer", ""
        if obj.get("movement_type") == "MOVEMENT_TYPE_BERRY_TREE_GROWTH":
            return "Beerenbaum", ""
        if re.search(r"BOULDER|CUTTABLE_TREE|BREAKABLE_ROCK|ROCK_SMASH|WHIRLPOOL", gfx):
            return "Hindernis", ""
        effects = self.script_effects(script)
        if effects and script in self.common_scripts:
            return "Allgemein", ""
        if effects:
            return "Figur", "/".join(sorted(effects))
        return "Deko", ""

    def script_effects(self, label):
        """Commands with a lasting effect in a script and the blocks of its own file it uses."""
        if label not in self._effect_cache:
            index = self.world.scripts
            found = set()
            block = index.blocks.get(label)
            if block is not None:
                local = [b for b in index.closure([label]) if b.path == block.path]
                for b in local:
                    found.update(EFFECT_RE.findall("\n".join(b.lines)))
            self._effect_cache[label] = found
        return self._effect_cache[label]

    def check_objects(self):
        world, reach = self.world, self.reach
        for m in world.active_maps():
            if not world.usable(m) or not reach.map_reached(m.id):
                continue
            path = f"data/maps/{m.folder}/map.json"
            for i, obj in enumerate(m.objects()):
                if obj.get("type") == "clone":
                    continue
                x, y = obj["x"], obj["y"]
                if not m.inside(x, y):
                    continue
                kind, item = self.object_kind(obj)
                label = f"{kind} {item}".strip()
                self._rate_spot(m, x, y, f"object_events[{i}] {label} ({obj.get('script', '')})", kind,
                                obj.get("flag", "0") not in ("0", 0, ""), f"{path} object_events[{i}]", i)
            for i, bg in enumerate(m.bg_events()):
                x, y = bg["x"], bg["y"]
                if not m.inside(x, y):
                    continue
                if bg.get("type") == "hidden_item":
                    self._rate_spot(m, x, y, f"bg_events[{i}] verstecktes Item {bg.get('item', '')}", "Verstecktes Item",
                                    False, f"{path} bg_events[{i}]", i, elevation=bg.get("elevation", 0))
                elif bg.get("type") == "sign":
                    self._check_bg_elevation(m, x, y, bg, f"{path} bg_events[{i}]", i)
            for i, ce in enumerate(m.coord_events()):
                if ce.get("type") != "weather" and m.inside(ce["x"], ce["y"]):
                    self._check_coord_elevation(m, ce, f"{path} coord_events[{i}]", i)

    def _check_bg_elevation(self, m, x, y, bg, where, index):
        """A sign is readable only from a tile where the player's elevation matches."""
        elevation = bg.get("elevation", 0)
        reached = [s for s in self.stand_tiles(m, x, y) if self.reach.tile_reached(m.id, *s)]
        if elevation == 0 or not reached:
            return
        ok, fixed = self.facing_elevation_ok(m, reached, elevation)
        if not ok:
            self.add(3, "O-HOEHE", m, (x, y), "nachgewiesen" if fixed else "verdacht", "optional",
                     f"bg_events[{index}] Schild ({bg.get('script', '')}): Höhe {elevation} passt zu keinem "
                     f"erreichbaren Nachbarfeld, nicht lesbar",
                     [where, f"Nachbarfelder (Höhe): {[(s, m.elevation(*s)) for s in reached]}"], index=index)

    def _check_coord_elevation(self, m, ce, where, index):
        """A coord event fires only if its elevation is 0 or equals the player's elevation on the tile."""
        x, y, elevation = ce["x"], ce["y"], ce.get("elevation", 0)
        prevs = self.reach.tiles.get(m.id, {}).get((x, y))
        if elevation == 0 or not prevs or elevation in prevs:
            return
        fixed = m.elevation(x, y) not in (0, 15)
        script = ce.get("script", "")
        self.add(3, "C-HOEHE", m, (x, y), "nachgewiesen" if fixed else "verdacht", "wichtig",
                 f"coord_events[{index}] {script} ({ce.get('var')} = {ce.get('var_value')}): Höhe {elevation}, "
                 f"Spielerhöhe auf dem Feld {sorted(prevs)}, das Ereignis löst nie aus",
                 [where, f"Kachel: {self.describe_tile(m, x, y)}"], index=index)

    def facing_elevation_ok(self, m, stand_tiles, elevation):
        """(ok, fixed): can a bg event of this elevation be faced from one of the stand tiles."""
        fixed = True
        for sx, sy in stand_tiles:
            e = m.elevation(sx, sy)
            if e == 15:
                fixed = False
            if e != 0 and elevation in self.reach.tiles[m.id].get((sx, sy), ()):
                return True, fixed
        return False, fixed

    def _rate_spot(self, m, x, y, label, kind, hidden_flag, where, index, elevation=None):
        reach = self.reach
        stands = self.stand_tiles(m, x, y)
        reached = [s for s in stands if reach.tile_reached(m.id, *s)]
        # Items are content; trainers and NPCs with effects may be; decoration is not.
        if kind in ("Item-Ball", "Verstecktes Item"):
            status, sev = "nachgewiesen", "klein"
        elif kind in ("Figur", "Trainer", "Beerenbaum"):
            status, sev = ("ungeprueft", "optional") if hidden_flag else ("verdacht", "klein")
        else:
            status, sev = "verdacht", "optional"
        details = [where, f"Kachel: {self.describe_tile(m, x, y)}"]
        if m.id in self.world.map_rides:
            status = "ungeprueft"
            details.append("Karte bewegt den Spieler oft per Skript (Fahrt/Rätsel), das Modell sieht diese Wege nicht")
        if not stands:
            self.add(3, "O-EINGEMAUERT", m, (x, y), status, sev,
                     f"{label}: alle Nachbarfelder sind Kollision", details, index=index)
        elif not reached:
            self.add(3, "O-UNERREICHBAR", m, (x, y), status, sev,
                     f"{label}: kein erreichbares Nachbarfeld", details + [f"Nachbarfelder: {stands}"], index=index)
        elif elevation not in (None, 0):
            ok, fixed = self.facing_elevation_ok(m, reached, elevation)
            if not ok:
                self.add(3, "O-HOEHE", m, (x, y), "nachgewiesen" if fixed else "verdacht", sev,
                         f"{label}: Höhe {elevation} passt zu keinem erreichbaren Nachbarfeld, nicht auffindbar",
                         details + [f"Nachbarfelder (Höhe): {[(s, m.elevation(*s)) for s in reached]}"], index=index)

    # check 4 ------------------------------------------------------------
    def check_connections(self):
        world, reach = self.world, self.reach
        for m in world.active_maps():
            if not world.usable(m):
                continue
            no_include = m.data.get("connections_no_include") in (True, "TRUE")
            for conn in m.data.get("connections") or []:
                d = conn.get("direction")
                target = world.maps.get(conn.get("map"))
                off = int(conn.get("offset", 0))
                where = f"data/maps/{m.folder}/map.json connections ({d}, {conn.get('map')}, {off})"
                if no_include:
                    continue
                if target is None or not target.active:
                    self.add(4, "V-ZIEL-INAKTIV", m, None, "nachgewiesen",
                             "kritisch" if reach.map_reached(m.id) else "klein",
                             f"Verbindung {d} zu {conn.get('map')}: Karte fehlt oder ist inaktiv", [where])
                    continue
                if not world.usable(target):
                    continue
                back = [c for c in target.connections() if c.get("map") == m.id and c.get("direction") == OPPOSITE.get(d)]
                if not back:
                    note, sev = "", "klein"
                    if target.data.get("connections_no_include") in (True, "TRUE"):
                        note, sev = " (Gegenseite hat connections_no_include)", "optional"
                    elif not reach.map_reached(m.id):
                        sev = "optional"
                    elif d not in ("dive", "emerge") and not self._passages(m, target, d, off):
                        sev = "optional"
                    self.add(4, "V-EINSEITIG", m, None, "nachgewiesen", sev,
                             f"Verbindung {d} zu {target.name} ohne Gegenrichtung{note}", [where])
                elif all(int(c.get("offset", 0)) != -off for c in back):
                    self.add(4, "V-OFFSET", m, None, "nachgewiesen", "wichtig",
                             f"Verbindung {d} zu {target.name}: Offset {off}, Gegenseite "
                             f"{[int(c.get('offset', 0)) for c in back]} (erwartet {-off})", [where])
                if d in ("dive", "emerge"):
                    if (target.width, target.height) != (m.width, m.height):
                        self.add(4, "V-GROESSE", m, None, "nachgewiesen", "wichtig",
                                 f"Tauch-Verbindung {d} zu {target.name}: Größe {target.width}x{target.height} "
                                 f"statt {m.width}x{m.height}", [where])
                    continue
                self._check_edge(m, target, d, off, where)

    @staticmethod
    def _edge_pairs(m, target, d, off):
        """Pairs of edge tiles (here, there) that face each other across a connection."""
        if d in ("up", "down"):
            span = [x for x in range(m.width) if 0 <= x - off < target.width]
            my_y = 0 if d == "up" else m.height - 1
            their_y = target.height - 1 if d == "up" else 0
            pairs = [((x, my_y), (x - off, their_y)) for x in span]
        else:
            span = [y for y in range(m.height) if 0 <= y - off < target.height]
            my_x = 0 if d == "left" else m.width - 1
            their_x = target.width - 1 if d == "left" else 0
            pairs = [((my_x, y), (their_x, y - off)) for y in span]
        return pairs

    def _passages(self, m, target, d, off):
        return [(a, b) for a, b in self._edge_pairs(m, target, d, off) if m.passable(*a) and target.passable(*b)]

    def _check_edge(self, m, target, d, off, where):
        """Shared edge must overlap and have at least one passage."""
        pairs = self._edge_pairs(m, target, d, off)
        if not pairs:
            self.add(4, "V-KEIN-UEBERLAPP", m, None, "nachgewiesen", "klein",
                     f"Verbindung {d} zu {target.name}: Karten überlappen nicht (Offset {off})", [where])
            return
        passages = [(a, b) for a, b in pairs if m.passable(*a) and target.passable(*b)]
        dead_ends = [(a, b) for a, b in pairs if m.passable(*a) != target.passable(*b)]
        if not passages:
            self.add(4, "V-NICHT-BEGEHBAR", m, None, "nachgewiesen", "optional",
                     f"Verbindung {d} zu {target.name}: kein Feldpaar an der Kante ist auf beiden Seiten begehbar",
                     [where])
        elif dead_ends and self.reach.map_reached(m.id):
            sample = ", ".join(f"{a}↔{b}" for a, b in dead_ends[:4])
            self.add(4, "V-KANTE", m, None, "verdacht", "optional",
                     f"Verbindung {d} zu {target.name}: {len(dead_ends)} Kantenfelder enden auf der Gegenseite an einer Wand",
                     [where, f"Beispiele (hier↔dort): {sample}"])

    # check 5 ------------------------------------------------------------
    def check_layouts(self):
        world = self.world
        users = collections.defaultdict(list)
        for m in world.active_maps():
            users[m.data["layout"]].append(m)
            if m.data["layout"] not in world.layout_entries:
                self.add(5, "L-FEHLT", m, None, "nachgewiesen", "blocker",
                         f"Layout {m.data['layout']} steht nicht in layouts.json", [f"data/maps/{m.folder}/map.json"])
        for lid, layout in sorted(world.layouts.items()):
            maps = users[lid] or sorted(world.alt_layout_users[lid], key=lambda mm: mm.name)
            first = maps[0]
            names = ", ".join(sorted(u.name for u in maps))
            for code, sev, text in layout.problems:
                self.add(5, code, first, None, "nachgewiesen", sev, f"{lid}: {text}", [f"benutzt von: {names}"])
            entry = layout.entry
            border = world.src.read(entry["border_filepath"])
            if layout.version == "frlg":
                bw, bh = entry.get("border_width", 2), entry.get("border_height", 2)
            else:
                bw, bh = 2, 2
            if border is None:
                self.add(5, "L-BORDER", first, None, "nachgewiesen", "kritisch",
                         f"{lid}: border.bin fehlt", [f"benutzt von: {names}"])
            elif len(border) != bw * bh * 2:
                self.add(5, "L-BORDER", first, None, "nachgewiesen", "klein",
                         f"{lid}: border.bin hat {len(border)} Bytes, Rand {bw}x{bh} braucht {bw * bh * 2}",
                         [entry["border_filepath"], f"benutzt von: {names}"])
            if (layout.width + MAP_OFFSET_W) * (layout.height + MAP_OFFSET_H) > MAX_MAP_DATA_SIZE:
                self.add(5, "L-ZU-GROSS", first, None, "nachgewiesen", "kritisch",
                         f"{lid}: {layout.width}x{layout.height} überschreitet MAX_MAP_DATA_SIZE "
                         f"({(layout.width + 15) * (layout.height + 14)} > {MAX_MAP_DATA_SIZE})", [f"benutzt von: {names}"])
            if layout.blocks is None:
                continue
            bad = collections.Counter()
            for i, block in enumerate(layout.blocks):
                if layout.behaviours[i] is None:
                    bad[block & 0x3FF] += 1
            if bad:
                sample = ", ".join(f"0x{t:03x}×{n}" for t, n in sorted(bad.items())[:6])
                self.add(5, "L-METATILE-ID", first, None, "nachgewiesen", "klein",
                         f"{lid}: {sum(bad.values())} Felder nutzen Metatiles ohne Attributeintrag ({sample})",
                         [f"benutzt von: {names}"])

    # map level ------------------------------------------------------------
    def check_unreached_maps(self):
        world, reach = self.world, self.reach
        for m in sorted(world.active_maps(), key=lambda mm: mm.name):
            if not world.usable(m) or reach.map_reached(m.id):
                continue
            content = self.map_content(m)
            details = ["Inhalt: " + (", ".join(content[:8]) if content
                                     else "keiner (keine Items, Trainer oder Figuren mit Wirkung)")]
            dead_in, via = self.dead_entrances(m.id)
            if dead_in:
                details.append("Nicht nutzbare Eingänge aus erreichten Karten: " + "; ".join(dead_in))
            if via:
                details.append("Erreichbar nur über unerreichte Karten: " + ", ".join(via[:6]))
            refs = world.c_refs.get(m.id, []) + world.script_targets.get(m.id, [])
            if refs:
                details.append("Referenzen (Skript/C): " + ", ".join(sorted(set(refs))[:5]))
            status = "ungeprueft" if refs and not dead_in else "verdacht"
            sev = ("wichtig" if dead_in else "klein") if content else "optional"
            self.add(0, "K-UNERREICHBAR", m, None, status, sev,
                     "Aktive Karte ist vom Spielstart aus nicht erreichbar", details)

    def dead_entrances(self, map_id, depth=8):
        """Dead warps of reached maps that lead here, directly or through other unreached maps."""
        world, reach = self.world, self.reach
        dead, via, seen = [], [], {map_id}
        frontier = [map_id]
        for _ in range(depth):
            nxt = []
            for target in frontier:
                for src_id, idx in reach.incoming.get(target, ()):
                    src = world.maps[src_id]
                    if not world.usable(src):
                        continue
                    if reach.map_reached(src_id):
                        if (src_id, idx) not in reach.used_warps:
                            w = src.warps()[idx]
                            text = f"{src.name} Warp {idx} ({w['x']},{w['y']})"
                            if target != map_id:
                                text += f" → {world.maps[target].name}"
                            if text not in dead:
                                dead.append(text)
                    elif src_id not in seen:
                        seen.add(src_id)
                        via.append(src.name)
                        nxt.append(src_id)
            frontier = nxt
        return dead, via

    def run(self):
        self.check_warps()
        self.check_targets()
        self.check_objects()
        self.check_connections()
        self.check_layouts()
        self.check_unreached_maps()
        return self.findings


# ---------------------------------------------------------------- output

CHECK_TITLES = {
    0: "Karten ohne Zugang",
    1: "Warp-Auslösung und Warp-Ziele",
    2: "Ankunftsfelder",
    3: "Objekte, Item-Bälle, versteckte Items",
    4: "Kartenverbindungen",
    5: "Layouts",
}


def sort_key(f):
    return (SEVERITY_ORDER.index(f.severity), STATUS_ORDER.index(f.status), f.map, f.coords or (0, 0))


def print_report(findings, world, reach, out, verbose=False):
    active = world.active_maps()
    print(f"Aktive Karten: {len(active)}, erreicht: {len(reach.entered)}, "
          f"Layouts geprüft: {len(world.layouts)}", file=out)
    total = collections.Counter((f.status, f.severity) for f in findings)
    print("Befunde gesamt: " + str(len(findings)), file=out)
    for sev in SEVERITY_ORDER:
        row = ", ".join(f"{st} {total[(st, sev)]}" for st in STATUS_ORDER if total[(st, sev)])
        if row:
            print(f"  {sev}: {row}", file=out)
    for region in REGIONS:
        part = [f for f in findings if f.region == region]
        print(f"\n{'=' * 78}\nRegion {region}: {len(part)} Befunde "
              f"({sum(1 for m in active if m.region == region)} aktive Karten)\n{'=' * 78}", file=out)
        for check in sorted(CHECK_TITLES):
            sub = sorted((f for f in part if f.check == check), key=sort_key)
            if not sub:
                continue
            print(f"\n-- ({check}) {CHECK_TITLES[check]}: {len(sub)}", file=out)
            for f in sub:
                print(f"[{f.status}/{f.severity}] {f.code} {f.where()}: {f.text}", file=out)
                if f.severity != "optional" or verbose:
                    for d in f.details:
                        print(f"      {d}", file=out)


def render_map(world, reach, name, out):
    """ASCII view of one map: reachability, collision, warps and objects."""
    m = world.by_name.get(name)
    if not world.usable(m):
        print(f"{name}: keine aktive Karte", file=out)
        return
    marks = {}
    for i, w in enumerate(m.warps()):
        marks[(w["x"], w["y"])] = "W" if (m.id, i) in reach.used_warps else "X"
    for o in m.objects():
        if o.get("type") != "clone":
            marks.setdefault((o["x"], o["y"]), "@")
    for b in m.bg_events():
        if b.get("type") == "hidden_item":
            marks.setdefault((b["x"], b["y"]), "?")
    print(f"{m.name} {m.width}x{m.height}  Legende: Ziffer = Höhe eines erreichten Feldes, "
          f". = begehbar, nicht erreicht, # = Kollision, W/X = Warp genutzt/nicht genutzt, "
          f"@ = Objekt, ? = verstecktes Item", file=out)
    print("    " + "".join(str(x % 10) for x in range(m.width)), file=out)
    for y in range(m.height):
        row = []
        for x in range(m.width):
            if (x, y) in marks:
                row.append(marks[(x, y)])
            elif reach.tile_reached(m.id, x, y):
                e = m.elevation(x, y)
                row.append("0123456789abcdef"[e])
            elif m.passable(x, y):
                row.append(".")
            else:
                row.append("#")
        print(f"{y:3d} " + "".join(row), file=out)


def run_checks(src, version):
    world = World(src, version)
    reach = Reach(world).run()
    findings = Checker(world, reach).run()
    return world, reach, findings


def selftest(root):
    src = Source(root, SELFTEST_REV)
    _, _, findings = run_checks(src, "hns")
    ok = True
    for code, name, index in SELFTEST_EXPECT:
        hit = [f for f in findings if f.code == code and f.map == name and f.index == index]
        print(f"{'OK  ' if hit else 'FAIL'} {code} {name} Warp {index}"
              + (f": {hit[0].text} [{hit[0].status}/{hit[0].severity}]" if hit else ""))
        ok = ok and bool(hit)
    return 0 if ok else 1


def select(findings, args):
    """Findings that pass the --min-severity, --region and --map filters."""
    limit = SEVERITY_ORDER.index(args.min_severity)
    shown = [f for f in findings if SEVERITY_ORDER.index(f.severity) <= limit]
    if args.region:
        shown = [f for f in shown if f.region.lower() == args.region]
    if args.map:
        shown = [f for f in shown if f.map in args.map]
    return shown


def finding_key(f):
    """Identity of a finding across revisions: code, map and event index (or the text)."""
    return (f.code, f.map, f.index if f.index is not None else f.text)


def print_compare(old, new, rev, out):
    """Findings fixed, added or rated differently since rev."""
    old_by = {finding_key(f): f for f in old}
    new_by = {finding_key(f): f for f in new}
    fixed = sorted((f for k, f in old_by.items() if k not in new_by), key=sort_key)
    added = sorted((f for k, f in new_by.items() if k not in old_by), key=sort_key)
    changed = sorted((f for k, f in new_by.items() if k in old_by
                      and (old_by[k].status, old_by[k].severity) != (f.status, f.severity)), key=sort_key)
    print(f"\n{'=' * 78}\nVergleich mit {rev}: behoben {len(fixed)}, neu {len(added)}, "
          f"anders bewertet {len(changed)}\n{'=' * 78}", file=out)
    for title, part in (("Behoben (nur in " + rev + ")", fixed), ("Neu (nur im geprüften Stand)", added)):
        print(f"\n-- {title}: {len(part)}", file=out)
        for f in part:
            print(f"[{f.status}/{f.severity}] {f.region} {f.code} {f.where()}: {f.text}", file=out)
    print(f"\n-- Anders bewertet: {len(changed)}", file=out)
    for f in changed:
        o = old_by[finding_key(f)]
        print(f"[{o.status}/{o.severity} -> {f.status}/{f.severity}] {f.region} {f.code} {f.where()}: {f.text}",
              file=out)


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--rev", help="check a git revision instead of the work tree")
    parser.add_argument("--compare", metavar="REV", help="also check REV and list findings fixed or new since then")
    parser.add_argument("--version", default="hns", help="game_version of the build (default hns)")
    parser.add_argument("--region", choices=["kanto", "johto", "hoenn"])
    parser.add_argument("--map", action="append", help="only findings of this map (name), repeatable")
    parser.add_argument("--min-severity", choices=SEVERITY_ORDER, default="optional")
    parser.add_argument("--json", help="write all shown findings to this JSON file")
    parser.add_argument("--verbose", action="store_true", help="details also for optional findings")
    parser.add_argument("--selftest", action="store_true", help=f"expect the known hits on {SELFTEST_REV}")
    parser.add_argument("--render", action="append", help="print an ASCII view of this map (name), repeatable")
    args = parser.parse_args()

    if args.selftest:
        return selftest(REPO)
    src = Source(REPO, args.rev)
    world, reach, findings = run_checks(src, args.version)
    if args.render:
        for name in args.render:
            render_map(world, reach, name, sys.stdout)
        return 0
    shown = select(findings, args)
    print_report(shown, world, reach, sys.stdout, args.verbose)
    if args.compare:
        _, _, old = run_checks(Source(REPO, args.compare), args.version)
        print_compare(select(old, args), shown, args.compare, sys.stdout)
    if args.json:
        with open(args.json, "w", encoding="utf-8") as fh:
            json.dump([f.as_dict() for f in shown], fh, ensure_ascii=False, indent=1)
    failing = [f for f in shown if f.status == "nachgewiesen" and SEVERITY_ORDER.index(f.severity) <= 2]
    return 1 if failing else 0


if __name__ == "__main__":
    sys.exit(main())
