#!/usr/bin/env python3
"""Fills up Johto's trainer teams, stage by stage along the level corridors.

  - Bosses (leaders, Elite Four, champion, Rocket admins, Silver) to six.
  - Route trainers with fewer than three to three.
  - Newcomers come from the wild pool of the trainer's map and share a type
    with the existing team.
  - No move block: the engine uses the learnset moves for the level.

Usage: fill_johto_parties.py <corridor floor of the stage>
"""
import collections
import glob
import json
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PARTY = os.path.join(REPO, 'src/data/trainers_hns.party')

BOSS_CLASSES = {'Leader Hns', 'Leader Kanto Hns', 'Elite Four Hns', 'Champion Hns',
                'Rocket Admin Hns', 'Rival Hns'}
# Classes that use the water pool.
WATER_CLASSES = {'Fisherman Hns', 'Swimmer M Hns', 'Swimmer F Hns', 'Sailor Hns'}

# Types a class's newcomers must have. Other classes only share a type with
# the existing team.
CLASS_TYPES = {
    'Bug Catcher Hns':   {'BUG'},
    'Bird Keeper Hns':   {'FLYING'},
    'Fisherman Hns':     {'WATER'},
    'Swimmer M Hns':     {'WATER'},
    'Swimmer F Hns':     {'WATER'},
    'Sailor Hns':        {'WATER'},
    'Firebreather Hns':  {'FIRE'},
    'Hiker Hns':         {'ROCK', 'GROUND'},
    'Black Belt Hns':    {'FIGHTING'},
    'Battle Girl Hns':   {'FIGHTING'},
    'Hex Maniac Hns':    {'GHOST', 'PSYCHIC'},
    'Psychic M Hns':     {'PSYCHIC'},
    'Psychic Hns':       {'PSYCHIC'},
    'Dragon Tamer Hns':  {'DRAGON'},
    'Skier Hns':         {'ICE'},
    'Sage Hns':          {'GHOST', 'PSYCHIC', 'FLYING'},
    'Kimono Girl Hns':   {'PSYCHIC', 'FIRE', 'WATER', 'ELECTRIC', 'GRASS'},
    'Team Rocket Hns':   {'POISON', 'DARK', 'ELECTRIC'},
    'Rocket Admin Hns':  {'POISON', 'DARK', 'ELECTRIC'},
    'Juggler Hns':       {'PSYCHIC', 'ELECTRIC'},
    'Pokemaniac Hns':    {'ROCK', 'GROUND', 'NORMAL'},
    'Biker Hns':         {'POISON', 'FIRE'},
    'Burglar Hns':       {'FIRE'},
    'Officer Hns':       {'NORMAL', 'DARK'},
    'Parasol Lady Hns':  {'WATER'},
}


def species_types():
    """Species name -> set of its types, read from the species_info families."""
    types = {}
    for f in glob.glob(os.path.join(REPO, 'src/data/pokemon/species_info/*families.h')):
        t = open(f, encoding='utf-8', errors='replace').read()
        for m in re.finditer(r'\[SPECIES_([A-Z_0-9]+)\]\s*=\s*\{(.*?)\n    \},', t, re.S):
            tm = re.search(r'\.types\s*=\s*MON_TYPES\(([^)]*)\)', m.group(2))
            if tm:
                types[m.group(1)] = {x.strip().replace('TYPE_', '') for x in tm.group(1).split(',') if x.strip()}
    return types


def johto_stages():
    """Map section -> (corridor floor, ceiling); the floor identifies the stage."""
    s = open(os.path.join(REPO, 'include/config/johto_scaling.h'), encoding='utf-8').read()
    out = {}
    for m in re.finditer(r'\{\s*(MAPSEC_\w+),\s*(\d+),\s*(\d+)\s*\}', s):
        out[m.group(1)] = (int(m.group(2)), int(m.group(3)))
    return out


def map_info():
    """Map directory -> (mapsec, map ID)."""
    out = {}
    for p in glob.glob(os.path.join(REPO, 'data/maps/*/map.json')):
        j = json.load(open(p, encoding='utf-8'))
        out[os.path.basename(os.path.dirname(p))] = (j.get('region_map_section'), j.get('id'))
    return out


def wild_pools():
    """Map ID -> {'land': Counter, 'water': Counter} of wild species."""
    d = json.load(open(os.path.join(REPO, 'src/data/wild_encounters.json')))
    g = [x for x in d['wild_encounter_groups'] if x['label'] == 'gWildMonHeaders'][0]
    out = collections.defaultdict(lambda: collections.defaultdict(collections.Counter))
    for e in g['encounters']:
        for field, bucket in (('land_mons', 'land'), ('rock_smash_mons', 'land'),
                              ('water_mons', 'water'), ('fishing_mons', 'water')):
            v = e.get(field)
            if isinstance(v, dict):
                for mon in v['mons']:
                    nm = mon['species'][8:]
                    if nm != 'NONE':
                        out[e['map']][bucket][nm] += 1
    return out


def parse_party():
    """Splits trainers_hns.party into (trainer name or None, text block) pairs."""
    txt = open(PARTY, encoding='utf-8', errors='replace').read()
    blocks = re.split(r'(?m)^(?==== )', txt)
    parsed = []
    for b in blocks:
        m = re.match(r'=== (\S+) ===', b)
        if not m:
            parsed.append((None, b))
            continue
        parsed.append((m.group(1), b))
    return parsed


def trainer_maps():
    """Trainer -> map directories whose scripts reference it."""
    out = collections.defaultdict(set)
    for f in glob.glob(os.path.join(REPO, 'data/maps/*/scripts.inc')):
        d = os.path.basename(os.path.dirname(f))
        for m in re.finditer(r'\b(TRAINER_[A-Z_0-9]+_HNS)\b', open(f, encoding='utf-8', errors='replace').read()):
            out[m.group(1)].add(d)
    return out


def main(stage_floor):
    """Fills up the teams of all Johto trainers whose corridor floor is stage_floor."""
    types = species_types()
    stages = johto_stages()
    minfo = map_info()
    pools = wild_pools()
    tmaps = trainer_maps()
    parsed = parse_party()

    # Fallback: species used by other trainers of the same class.
    by_class = collections.defaultdict(collections.Counter)
    for name, b in parsed:
        if not name:
            continue
        cm = re.search(r'^Class:\s*(.+)$', b, re.M)
        if not cm:
            continue
        for seg in b.rstrip('\n').split('\n\n')[1:]:
            if 'Level:' in seg:
                by_class[cm.group(1).strip()][seg.split('\n')[0].split(' @ ')[0].strip()] += 1

    added = collections.Counter()
    out = []
    for name, b in parsed:
        if not name or name not in tmaps:
            out.append(b)
            continue
        dirs = [d for d in tmaps[name] if minfo.get(d, (None,))[0] in stages]
        if not dirs:
            out.append(b)
            continue
        # Stages (corridor floors) of the trainer's maps.
        floors = {stages[minfo[d][0]][0] for d in dirs}
        if stage_floor not in floors:
            out.append(b)
            continue

        cls = re.search(r'^Class:\s*(.+)$', b, re.M)
        cls = cls.group(1).strip() if cls else ''
        target = 6 if cls in BOSS_CLASSES else 3

        trail = len(b) - len(b.rstrip('\n'))
        chunks = b.rstrip('\n').split('\n\n')
        header, mons = chunks[0], [c.split('\n') for c in chunks[1:]]
        mons = [m for m in mons if any(l.startswith('Level:') for l in m)]
        if not mons or len(mons) >= target:
            out.append(b)
            continue

        have = {m[0].split(' @ ')[0].strip().upper().replace("'", '').replace('-', '').replace('.', '')
                for m in mons}
        team_types = set()
        for h in have:
            team_types |= types.get(h, set())

        bucket = 'water' if cls in WATER_CLASSES else 'land'
        pool = collections.Counter()
        for d in dirs:
            mid = minfo[d][1]
            pool.update(pools.get(mid, {}).get(bucket, {}))
            if not pool:
                pool.update(pools.get(mid, {}).get('land' if bucket == 'water' else 'water', {}))

        want = CLASS_TYPES.get(cls)

        def rank(sp):
            shared = len(types.get(sp, set()) & team_types)
            return (-shared, -pool[sp])

        cands = [sp for sp in pool if sp not in have]
        # Class types first; without a match in the wild pool, repeat one of
        # the trainer's own species.
        if want:
            strict = [sp for sp in cands if types.get(sp, set()) & want]
            if not strict:
                strict = [sp for sp in sorted(have) if types.get(sp, set()) & want]
            if strict:
                cands = strict
        cands.sort(key=rank)
        # Rotate equally ranked candidates by an offset from the trainer's name.
        if len(cands) > 2:
            top = [sp for sp in cands if rank(sp)[0] == rank(cands[0])[0]]
            rest = [sp for sp in cands if sp not in top]
            off = sum(ord(ch) for ch in name) % len(top)
            cands = top[off:] + top[:off] + rest
        # Without a wild pool (gyms, buildings): species of the same trainer class
        if not cands:
            cands = [sp for sp, _ in by_class[cls].most_common()
                     if sp.upper().replace("'", '').replace('-', '').replace('.', '') not in have
                     and types.get(sp.upper().replace("'", '').replace('-', '').replace('.', ''), set()) & team_types]
        if not cands:
            out.append(b)
            continue

        iv = next((l for l in mons[0] if l.startswith('IVs:')), None)
        lvls = [int(re.search(r'Level:\s*(\d+)', '\n'.join(m)).group(1)) for m in mons]
        lo, hi = min(lvls), max(lvls)
        need = target - len(mons)
        for i in range(need):
            sp = cands[i % len(cands)]
            pretty = sp.title().replace('_', ' ')
            seg = [pretty, f'Level: {lo}']
            if iv:
                seg.append(iv)
            mons.insert(len(mons) - 1, seg)   # insert before the previous ace
            added[name] += 1
        n = len(mons)
        for i, seg in enumerate(mons):
            lvl = lo + round((hi - lo) * i / (n - 1)) if n > 1 else lo
            for k, l in enumerate(seg):
                if l.startswith('Level:'):
                    seg[k] = f'Level: {lvl}'
        out.append(header + '\n\n' + '\n\n'.join('\n'.join(s) for s in mons) + '\n' * trail)

    open(PARTY, 'w', encoding='utf-8').write(''.join(out))
    print(f'Stufe mit Boden {stage_floor}: {len(added)} Trainer ergaenzt, {sum(added.values())} Pokemon')


if __name__ == '__main__':
    main(int(sys.argv[1]))
