#!/usr/bin/env python3
"""Loest alle Flag- und Var-Konstanten numerisch auf und meldet Kollisionen.

Warum es das gibt: zwei Namen auf derselben Nummer sind kein Compilerfehler.
Genau daran sind in diesem Projekt schon zweimal Fehler entstanden - die
Match-Call-Registrierung lag auf denselben Adressen wie 90 Hoenn-Inhaltsflags,
und die FRLG-Trainerflags ueberlagerten die Ordensflags. Beide Male hat der
Build geschwiegen und das Spiel sich falsch verhalten.

Aufruf:
    python3 tools/check_flags.py            # Kurzbericht
    python3 tools/check_flags.py --verbose  # mit allen Doppelbelegungen
    python3 tools/check_flags.py --free     # zusaetzlich freie Fenster

Nach jedem HnS-Merge laufen lassen. Rueckgabewert 1, wenn eine Kollision
gefunden wurde, die nicht als Alias eingetragen ist.
"""

import argparse
import collections
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Headerdateien des HnS/Jade-Builds, in Einlesereihenfolge. Spaetere
# Definitionen ueberschreiben fruehere - so wie es der Praeprozessor auch tut.
FLAG_HEADERS = [
    "include/constants/flags_hns.h",
    "include/constants/flags_hoenn_de.h",
    "include/constants/flags_frlg_hns.h",
    "include/constants/flags_origin_jade.h",
]
VAR_HEADERS = [
    "include/constants/vars_hns.h",
    "include/constants/vars_hoenn_de.h",
    "include/constants/vars_frlg_hns.h",
    "include/constants/vars_origin_jade.h",
]

# Bewusste Alias-Paare: verschiedene Namen fuer dieselbe Stelle. Werden nicht
# als Kollision gemeldet. Ein Name reicht, das Paar wird ueber den Wert
# zusammengefuehrt.
KNOWN_ALIAS_PREFIXES = (
    "FLAG_TEMP_",
    "FLAG_UNUSED",
    "FLAG_SPECIAL_FLAG_UNUSED",
    "VAR_UNUSED",
    # Landmarken sind eine eigene Nummerierung, die nur zufaellig FLAG_ heisst.
    "FLAG_LANDMARK_",
)

# Blockanker (FLAG_..._START und Co.) zeigen absichtlich auf das erste Flag
# ihres Blocks. Das ist keine Doppelbelegung.
ANCHOR_SUFFIXES = ("_START", "_END", "_COUNT", "_BASE", "_SIZE")

# Namen, die per Definition dasselbe Flag meinen (Emerald- und FRLG-Schreibweise
# derselben Sache). Werden nicht gemeldet.
KNOWN_ALIASES = {
    frozenset({"FLAG_SYS_CYCLING_ROAD", "FLAG_SYS_ON_CYCLING_ROAD"}),
    frozenset({"FLAG_SYS_MYSTERY_EVENT_ENABLE", "FLAG_SYS_MYSTERY_GIFT_ENABLE"}),
    frozenset({"FLAG_SYS_PC_BILL", "FLAG_SYS_PC_LANETTE"}),
}


def read_defines(paths):
    """Sammelt alle #define-Zeilen. Letzte Definition gewinnt."""
    defs = {}
    origin = {}
    for rel in paths:
        path = os.path.join(REPO, rel)
        if not os.path.exists(path):
            continue
        with open(path, encoding="utf-8", errors="replace") as fh:
            for lineno, line in enumerate(fh, 1):
                m = re.match(r"^#define\s+(\w+)\s+(.+?)\s*$", line)
                if not m:
                    continue
                name, value = m.group(1), re.sub(r"//.*$", "", m.group(2)).strip()
                if not value or "(" in name:
                    continue
                defs[name] = value
                origin[name] = f"{rel}:{lineno}"
    return defs, origin


def resolve_all(defs):
    """Wertet jede Definition zu einer Zahl aus, soweit moeglich."""
    cache = {}

    def resolve(name, depth=0):
        if name in cache:
            return cache[name]
        if depth > 40 or name not in defs:
            return None
        expr = defs[name]
        for _ in range(40):
            try:
                value = eval(expr, {"__builtins__": {}}, {})
            except NameError as err:
                missing = str(err).split("'")[1]
                if missing not in defs or missing == name:
                    return None
                expr = re.sub(r"\b" + missing + r"\b", "(" + defs[missing] + ")", expr)
                continue
            except Exception:
                return None
            if isinstance(value, int):
                cache[name] = value
                return value
            return None
        return None

    out = {}
    for name in defs:
        value = resolve(name)
        if isinstance(value, int):
            out[name] = value
    return out


def is_alias_name(name):
    return name.startswith(KNOWN_ALIAS_PREFIXES) or name.endswith(ANCHOR_SUFFIXES)


def check(kind, headers, prefix, verbose, show_free):
    defs, origin = read_defines(headers)
    values = {n: v for n, v in resolve_all(defs).items() if n.startswith(prefix)}
    by_value = collections.defaultdict(list)
    for name, value in values.items():
        by_value[value].append(name)

    # Stubs auf 0 sind abgeschaltete Namen, keine Belegung.
    collisions = {}
    for value, names in by_value.items():
        if value <= 0 or len(names) < 2:
            continue
        real = [n for n in names if not is_alias_name(n)]
        if frozenset(real) in KNOWN_ALIASES:
            continue
        if len(real) > 1:
            collisions[value] = sorted(real)

    used = sorted(v for v in values.values() if v > 0)
    print(f"{kind}: {len(values)} Namen aufgeloest, {len(set(used))} Nummern belegt")
    if collisions:
        print(f"  KOLLISIONEN: {len(collisions)} Nummern mit mehr als einem echten Namen")
        items = sorted(collisions.items())
        for value, names in (items if verbose else items[:10]):
            print(f"    {hex(value)}: {', '.join(names)}")
            if verbose:
                for name in names:
                    print(f"        {name} -> {origin.get(name, '?')}")
        if not verbose and len(items) > 10:
            print(f"    ... {len(items) - 10} weitere, --verbose zeigt alle")
    else:
        print("  keine Kollisionen")

    if show_free and used:
        gaps = []
        run = None
        for i in range(used[0], used[-1] + 1):
            if i not in set(used):
                if run is None:
                    run = i
            elif run is not None:
                gaps.append((run, i - 1))
                run = None
        big = [g for g in gaps if g[1] - g[0] >= 7]
        total = sum(b - a + 1 for a, b in big)
        print(f"  freie Fenster mit mindestens 8 Plaetzen: {len(big)} ({total} Stueck)")
        for a, b in big[:20]:
            print(f"    {hex(a)}-{hex(b)}  ({b - a + 1})")
        print("  Achtung: Bloecke, die zur Laufzeit hochgezaehlt werden")
        print("  (Trainerflags, Match-Call-Registrierung), sehen hier frei aus.")

    return 1 if collisions else 0


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--verbose", action="store_true", help="alle Kollisionen mit Fundstelle")
    parser.add_argument("--free", action="store_true", help="freie Fenster auflisten")
    args = parser.parse_args()

    status = 0
    status |= check("Flags", FLAG_HEADERS, "FLAG_", args.verbose, args.free)
    print()
    status |= check("Vars", VAR_HEADERS, "VAR_", args.verbose, args.free)
    return status


if __name__ == "__main__":
    sys.exit(main())
