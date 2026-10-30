#!/usr/bin/env python3
"""Shifts Kanto's first-battle trainer parties (src/data/trainers_frlg.party)
to the ladder in docs/origin_jade/DECISIONS.md, D-011.

  - Bosses: every Pokemon of the party moves by the boss's shift (all three
    starter variants of rivals and the champion).
  - Route and dungeon trainers: every first battle on an active FRLG map moves
    by the shift of the map's section.
  - Elite Four and champion rematch teams (_2, CHAMPION_REMATCH_*): every
    Pokemon to E4_REMATCH_LEVEL (D-015, D-031).
  - VS Seeker rematch teams (D-034): only those in VS_SEEKER_SHIFT; the tier
    floors in src/vs_seeker.c lift the others.

Prints old -> new levels per trainer. Writes only with --apply and refuses
once the champion's ace is no longer at its old level (already shifted).

Usage: shift_kanto_ladder.py [--apply]
"""
import glob
import json
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PARTY = os.path.join(REPO, 'src/data/trainers_frlg.party')

BOSS_SHIFT = {
    'RIVAL_ROUTE22_EARLY': -1, 'RIVAL_CERULEAN': -3, 'LEADER_MISTY': 1,
    'RIVAL_SS_ANNE': 2, 'LEADER_LT_SURGE': 2, 'LEADER_ERIKA': 5,
    'BOSS_GIOVANNI': 8, 'RIVAL_POKEMON_TOWER': 3, 'LEADER_KOGA': 1,
    'RIVAL_SILPH': 4, 'BOSS_GIOVANNI_2': 6, 'LEADER_SABRINA': 4,
    'LEADER_BLAINE': 4, 'LEADER_GIOVANNI': 1, 'RIVAL_ROUTE22_LATE': 0,
    'ELITE_FOUR_LORELEI': -1, 'ELITE_FOUR_BRUNO': -2, 'ELITE_FOUR_AGATHA': -3,
    'ELITE_FOUR_LANCE': -3, 'CHAMPION_FIRST': -5,
}
STARTERS = ('SQUIRTLE', 'BULBASAUR', 'CHARMANDER')
BOSS_PREFIXES = ('RIVAL_', 'LEADER_', 'ELITE_FOUR_', 'CHAMPION_', 'BOSS_')

# Section: (shift, map names without _Frlg; a trailing _ matches every floor).
SECTIONS = {
    'Forest':     (0, ['ViridianForest', 'PewterCity_Gym']),
    'MtMoon':     (2, ['Route3', 'MtMoon_', 'CeruleanCity_Gym']),
    'Nugget':     (-3, ['Route4', 'Route24', 'Route25', 'CeruleanCity']),
    'SSAnne':     (2, ['Route5', 'Route6', 'SSAnne_', 'VermilionCity_Gym']),
    'RockTunnel': (4, ['Route9', 'Route10', 'RockTunnel_']),
    'Celadon':    (4, ['Route7', 'Route8', 'CeladonCity_Gym']),
    'Hideout':    (4, ['RocketHideout_', 'CeladonCity_GameCorner']),
    'Tower':      (6, ['PokemonTower_']),
    'R11_15':     (3, ['Route11', 'Route12', 'Route13', 'Route14', 'Route15']),
    'R16_18':     (2, ['Route16', 'Route17', 'Route18', 'FuchsiaCity_Gym']),
    'Silph':      (4, ['SilphCo_', 'SaffronCity_Dojo', 'SaffronCity_Gym']),
    'Cinnabar':   (5, ['Route19', 'Route20', 'Route21_', 'PokemonMansion_', 'CinnabarIsland_Gym']),
    'Viridian':   (6, ['ViridianCity_Gym']),
    'VR':         (-1, ['Route23', 'VictoryRoad_']),
}

# Route 6's first VS Seeker teams move with their first teams (section +2),
# so the rematch stays above the first battle.
VS_SEEKER_SHIFT = {'CAMPER_RICKY_2': 2, 'CAMPER_JEFF_2': 2, 'PICNICKER_ISABELLE_2': 2}

E4_REMATCH_OLD_LEVEL = 52
E4_REMATCH_LEVEL = 47
CHAMPION_OLD_ACE = 52   # guard: the champion's ace before the shift

TRAINERBATTLE = re.compile(r'^\s*trainerbattle_(?:single|double|no_intro|earlyrival|rival)\s+(TRAINER_\w+)')


def section_of(mapname):
    base = mapname[:-len('_Frlg')] if mapname.endswith('_Frlg') else mapname
    for sec, (_, names) in SECTIONS.items():
        for n in names:
            if (n.endswith('_') and base.startswith(n)) or base == n:
                return sec
    return None


def label_bodies(text):
    out, cur = {}, None
    for line in text.split('\n'):
        m = re.match(r'^(\w+)::?\s*$', line)
        if m:
            cur = m.group(1)
            out[cur] = []
        elif cur:
            out[cur].append(line)
    return out


def first_battle_maps():
    """trainer -> set of active FRLG maps whose scripts start the battle."""
    shared = label_bodies(open(os.path.join(REPO, 'data/scripts/trainers_frlg.inc')).read())
    uses = {}
    for f in sorted(glob.glob(os.path.join(REPO, 'data/maps/*_Frlg/map.json'))):
        m = json.load(open(f))
        if m.get('game_version') != 'hns':
            continue
        name = os.path.basename(os.path.dirname(f))
        p = os.path.join(os.path.dirname(f), 'scripts.inc')
        bodies = label_bodies(open(p).read()) if os.path.exists(p) else {}
        for o in m.get('object_events', []):
            for line in bodies.get(o.get('script')) or shared.get(o.get('script')) or []:
                t = TRAINERBATTLE.match(line)
                if t:
                    uses.setdefault(t.group(1), set()).add(name)
                    break
        for body in bodies.values():
            for line in body:
                t = TRAINERBATTLE.match(line)
                if t:
                    uses.setdefault(t.group(1), set()).add(name)
    return uses


def parse_party(lines):
    """trainer -> list of line indexes of its 'Level:' lines."""
    out, cur = {}, None
    for i, line in enumerate(lines):
        m = re.match(r'^=== (TRAINER_\w+) ===', line)
        if m:
            cur = m.group(1)
            out[cur] = []
        elif cur and line.startswith('Level:'):
            out[cur].append(i)
    return out


def level_at(lines, i):
    return int(re.match(r'Level:\s*(\d+)', lines[i]).group(1))


def boss_key(trainer):
    short = trainer[len('TRAINER_'):]
    if short in BOSS_SHIFT:
        return short
    for s in STARTERS:
        if short.endswith('_' + s) and short[:-len(s) - 1] in BOSS_SHIFT:
            return short[:-len(s) - 1]
    return None


def compute(lines, party):
    """trainer -> (shift, reason) or ('set', reason) for E4_REMATCH_LEVEL."""
    plan = {}
    unmapped = []
    for t, maps in sorted(first_battle_maps().items()):
        if t not in party:
            continue   # HnS trainers on Kanto maps (D-032)
        short = t[len('TRAINER_'):]
        b = boss_key(t)
        if b:
            plan[t] = (BOSS_SHIFT[b], b)
            continue
        if short.startswith(BOSS_PREFIXES):
            continue   # Oak's lab rival, E4 rematches
        secs = {section_of(m) for m in maps}
        if len(secs) != 1 or None in secs:
            unmapped.append((t, sorted(maps)))
            continue
        sec = secs.pop()
        plan[t] = (SECTIONS[sec][0], sec)
    for t in party:
        short = t[len('TRAINER_'):]
        if (short.startswith('ELITE_FOUR_') and short.endswith('_2')) or short.startswith('CHAMPION_REMATCH_'):
            plan[t] = ('set', 'E4 rematch')
    for short, n in VS_SEEKER_SHIFT.items():
        plan['TRAINER_' + short] = (n, 'VS Seeker')
    return plan, unmapped


def main():
    apply = '--apply' in sys.argv[1:]
    lines = open(PARTY, encoding='utf-8').read().split('\n')
    party = parse_party(lines)
    ace = max(level_at(lines, i) for i in party['TRAINER_CHAMPION_FIRST_SQUIRTLE'])
    if ace != CHAMPION_OLD_ACE:
        sys.exit('champion ace is %d, not %d: already shifted' % (ace, CHAMPION_OLD_ACE))
    plan, unmapped = compute(lines, party)
    changed = 0
    for t in party:
        if t not in plan:
            continue
        what, why = plan[t]
        old = [level_at(lines, i) for i in party[t]]
        if what == 'set':
            assert all(l == E4_REMATCH_OLD_LEVEL for l in old), (t, old)
            new = [E4_REMATCH_LEVEL] * len(old)
        else:
            new = [l + what for l in old]
        assert all(1 <= l <= 100 for l in new), (t, new)
        if new == old:
            continue
        changed += 1
        for i, l in zip(party[t], new):
            lines[i] = re.sub(r'^Level:\s*\d+', 'Level: %d' % l, lines[i])
        tag = 'set %d' % E4_REMATCH_LEVEL if what == 'set' else '%+d' % what
        print('%-42s %-7s %-22s %s -> %s' % (t, tag, why, '/'.join(map(str, old)), '/'.join(map(str, new))))
    for t, why in unmapped:
        print('UNMAPPED', t, why)
    print('%d parties changed%s' % (changed, '' if apply else ' (dry run, --apply writes)'))
    if unmapped:
        sys.exit(1)
    if apply:
        open(PARTY, 'w', encoding='utf-8').write('\n'.join(lines))


if __name__ == '__main__':
    main()
