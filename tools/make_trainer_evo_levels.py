#!/usr/bin/env python3
"""Trainer evolution levels for the level scaling (src/level_scaling.c).

For every evolution the scaling applies that is not a plain level evolution
(EVO_ITEM, EVO_TRADE, EVO_LEVEL / EVO_LEVEL_BATTLE_ONLY with level 0), finds
the level from which HnS's own trainers mostly field the evolved species:
the lowest level L at which they field it (or a later stage) and, among all
their Pokemon at L or higher, field it more often than the pre-evolution.
--rule lowest takes the lowest level at which they field it instead.
Emerald's and FRLG's lowest levels are shown for reference. Targets in
sTrainerEvoExcluded (src/level_scaling.c) get no row.

Run from the repository root (needs git and arm-none-eabi-cpp):
  python3 -I tools/make_trainer_evo_levels.py            # Markdown table
  python3 -I tools/make_trainer_evo_levels.py --header   # src/data/trainer_evo_levels.h
  python3 -I tools/make_trainer_evo_levels.py --json     # raw data
"""

import argparse
import json
import os
import re
import subprocess
import sys

# Commit with HnS's own party file: HnS 2.0.5, second parent of merge cc58e0c648.
# After an HnS update, set it to the upstream side of that merge.
HNS_REV = "9041f705db"
HNS_PARTY = "src/data/trainers_hns.party"
EMERALD_PARTY = "src/data/trainers.party"
FRLG_PARTY = "src/data/trainers_frlg.party"

CPP = ["arm-none-eabi-cpp", "-iquote", "include", "-Wno-trigraphs", "-DMODERN=1",
       "-DTESTING=0", "-DPOKEMON_HNS", "-std=gnu17"]

FALLBACK_NAME = "*_SCALING_EVO_OTHER_LEVEL"
FALLBACK_LEVEL = 36

SCALING_C = "src/level_scaling.c"
EXCLUDED_ARRAY = "sTrainerEvoExcluded"

NON_LEVEL_METHODS = ("EVO_ITEM", "EVO_TRADE")
LEVEL_METHODS = ("EVO_LEVEL", "EVO_LEVEL_BATTLE_ONLY")

# Trainer ids that are not real opponents.
SKIP_TRAINER_RE = re.compile(r"^TRAINER_(NONE|DEBUG\w*|TEST\w*)$")


# ---------------------------------------------------------------------------
# Species constants

def eval_int(expr, names):
    """Evaluates a small C integer expression with known SPECIES_ names."""
    def repl(m):
        return str(names[m.group(0)])
    text = re.sub(r"SPECIES_\w+", repl, expr)
    text = re.sub(r"\b(\d+)[uU]?\b", r"\1", text)
    if not re.fullmatch(r"[\d\s+\-*()]+", text):
        raise ValueError("cannot evaluate: " + expr)
    return int(eval(text, {"__builtins__": {}}, {}))


def load_species_constants(repo):
    """Returns (name -> number, number -> first name) from constants/species.h."""
    raw = {}
    order = []
    with open(os.path.join(repo, "include/constants/species.h"), encoding="utf-8") as f:
        for line in f:
            m = re.match(r"#define\s+(SPECIES_\w+)\s+(.+?)\s*(//.*)?$", line)
            if m:
                raw[m.group(1)] = m.group(2)
                order.append(m.group(1))
    values = {}

    def resolve(name, depth=0):
        if name in values:
            return values[name]
        if depth > 20:
            raise ValueError("alias loop at " + name)
        expr = raw[name]
        for dep in re.findall(r"SPECIES_\w+", expr):
            resolve(dep, depth + 1)
        values[name] = eval_int(expr, values)
        return values[name]

    for name in order:
        resolve(name)
    by_number = {}
    for name in order:
        # The first plain-number define is the canonical name.
        if re.fullmatch(r"\d+", raw[name]) and values[name] not in by_number:
            by_number[values[name]] = name
    for name in order:
        by_number.setdefault(values[name], name)
    return values, by_number


def load_excluded(repo, names):
    """Species in sTrainerEvoExcluded, which the scaling never picks."""
    with open(os.path.join(repo, SCALING_C), encoding="utf-8") as f:
        text = f.read()
    m = re.search(EXCLUDED_ARRAY + r"\[\]\s*=\s*\{(.*?)\};", text, re.S)
    if not m:
        raise ValueError("%s not found in %s" % (EXCLUDED_ARRAY, SCALING_C))
    body = re.sub(r"//[^\n]*", "", m.group(1))
    return {names[n] for n in re.findall(r"SPECIES_\w+", body)}


# ---------------------------------------------------------------------------
# Evolution data, taken from the preprocessed species info of the jade build

def skip_literal(text, i):
    quote = text[i]
    i += 1
    while text[i] != quote:
        i += 2 if text[i] == "\\" else 1
    return i + 1


def match_brace(text, i):
    """i points at '{'; returns the index after the matching '}'."""
    depth = 0
    while True:
        c = text[i]
        if c in "\"'":
            i = skip_literal(text, i)
            continue
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1


def split_top(text, sep=","):
    """Splits at sep outside of braces and parentheses."""
    parts, depth, cur, i = [], 0, [], 0
    while i < len(text):
        c = text[i]
        if c in "\"'":
            j = skip_literal(text, i)
            cur.append(text[i:j])
            i = j
            continue
        if c in "({":
            depth += 1
        elif c in ")}":
            depth -= 1
        if c == sep and depth == 0:
            parts.append("".join(cur).strip())
            cur = []
        else:
            cur.append(c)
        i += 1
    if "".join(cur).strip():
        parts.append("".join(cur).strip())
    return parts


def load_evolutions(repo, names):
    """Returns (species number -> [evolution dict], set of species with an entry)."""
    out = subprocess.run(CPP + ["src/pokemon.c"], cwd=repo, check=True,
                         capture_output=True, text=True).stdout
    start = out.index("const struct SpeciesInfo gSpeciesInfo[] =")
    i = out.index("{", start) + 1
    end = match_brace(out, out.index("{", start))
    evolutions, present = {}, set()
    entry_re = re.compile(r"\s*\[([^\]]+)\]\s*=\s*")
    while i < end - 1:
        m = entry_re.match(out, i)
        if not m:
            i += 1
            continue
        species = eval_int(m.group(1), names)
        body_start = out.index("{", m.end())
        body_end = match_brace(out, body_start)
        body = out[body_start:body_end]
        present.add(species)
        k = body.find(".evolutions =")
        if k != -1:
            arr = body.index("{", body.index("(const struct Evolution[])", k) + 1)
            arr_body = body[arr + 1:match_brace(body, arr) - 1]
            evos = []
            for item in split_top(arr_body):
                if not item.startswith("{"):
                    continue
                fields = split_top(item[1:-1])
                if fields[0] == "0xFFFF":
                    break
                conds = re.findall(r"\{(IF_\w+)\s*,?\s*([^{}]*)\}", fields[3]) if len(fields) > 3 else []
                evos.append({
                    "method": fields[0],
                    "param": fields[1],
                    "target": eval_int(fields[2], names),
                    "conditions": [(c, a.strip()) for c, a in conds],
                })
            evolutions[species] = evos
        i = body_end
        while i < end and out[i] in " \t\r\n,":
            i += 1
    return evolutions, present


# ---------------------------------------------------------------------------
# Trainer parties (.party, trainerproc syntax)

def species_constant(name):
    """trainerproc's fprint_species: Showdown name -> SPECIES_ constant."""
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


HEADER_RE = re.compile(r"^(?P<first>[^()@]+?)\s*(?:\((?P<second>[^()]+)\)\s*(?:\((?P<third>[^()]+)\))?)?\s*(?:@\s*(?P<item>.+?))?\s*$")


def parse_party(text, source):
    """Returns [{id, class, mons: [(species constant, level)]}] in file order."""
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    trainers = []
    for block in re.split(r"(?m)^(?====)", text):
        m = re.match(r"===\s*(\w+)\s*===", block)
        if not m:
            continue
        trainer = {"id": m.group(1), "class": "", "source": source, "mons": []}
        chunks = re.split(r"\n\s*\n", block.split("\n", 1)[1] if "\n" in block else "")
        for n, chunk in enumerate(chunks):
            lines = [l.rstrip() for l in chunk.strip("\n").split("\n") if l.strip()]
            if not lines:
                continue
            if n == 0:
                for line in lines:
                    if line.startswith("Class:"):
                        trainer["class"] = line.split(":", 1)[1].strip()
                continue
            h = HEADER_RE.match(lines[0].strip())
            if not h:
                raise ValueError("%s %s: bad Pokemon line %r" % (source, trainer["id"], lines[0]))
            first, second, third = h.group("first"), h.group("second"), h.group("third")
            if third is not None or (second is not None and len(second.strip()) > 1):
                species = second.strip()
            else:
                species = first.strip()
            level = 100
            for line in lines[1:]:
                lm = re.match(r"Level:\s*(\d+)", line)
                if lm:
                    level = int(lm.group(1))
            trainer["mons"].append((species_constant(species), level))
        trainers.append(trainer)
    return trainers


def load_trainer_maps(repo):
    """Trainer id -> (first map whose scripts name it, the map's game_version)."""
    maps = {}
    root = os.path.join(repo, "data/maps")
    for name in sorted(os.listdir(root)):
        version = ""
        try:
            with open(os.path.join(root, name, "map.json"), encoding="utf-8") as f:
                version = json.load(f).get("game_version", "")
        except (OSError, ValueError):
            pass
        for fname in ("scripts.inc", "scripts.pory"):
            path = os.path.join(root, name, fname)
            if not os.path.isfile(path):
                continue
            with open(path, encoding="utf-8", errors="replace") as f:
                for tid in re.findall(r"\bTRAINER_\w+", f.read()):
                    maps.setdefault(tid, (name, version))
    return maps


def trainer_map(maps, tid):
    """Map of the trainer, for rematch teams (TRAINER_X_3_HNS) the map of the first team."""
    if tid in maps:
        return maps[tid]
    m = re.match(r"^(TRAINER_\w+?)_\d+(_HNS)?$", tid)
    if m:
        for base in (m.group(1) + (m.group(2) or ""), m.group(1) + "_1" + (m.group(2) or "")):
            if base in maps:
                return maps[base]
    return ("", "")


def referenced_trainers(repo, rev, party):
    """Trainer ids named anywhere in data/ or src/ except the party file and its output."""
    excludes = [":!" + party, ":!" + party[:-len(".party")] + ".h"]
    cmd = ["git", "grep", "-ohwI"] + ([] if rev else ["--untracked"]) + ["TRAINER_[A-Z0-9_]*"]
    cmd += ([rev] if rev else []) + ["--", "data", "src"] + excludes
    out = subprocess.run(cmd, cwd=repo, check=True, capture_output=True, text=True).stdout
    return set(out.split())


def read_file(repo, path, rev=None):
    if rev is None:
        with open(os.path.join(repo, path), encoding="utf-8") as f:
            return f.read()
    return subprocess.run(["git", "show", "%s:%s" % (rev, path)], cwd=repo, check=True,
                          capture_output=True, text=True).stdout


def lowest_levels(trainers, names, used):
    """Species number -> (level, trainer) of the lowest level a used trainer fields it."""
    best = {}
    for t in trainers:
        if SKIP_TRAINER_RE.match(t["id"]) or t["id"] not in used:
            continue
        for const, level in t["mons"]:
            if const not in names:
                raise ValueError("%s %s: unknown species %s" % (t["source"], t["id"], const))
            num = names[const]
            if num not in best or level < best[num][0]:
                best[num] = (level, t)
    return best


def majority_level(mons, pre, evolved):
    """Lowest level L at which an evolved species is fielded and the evolved species
    outnumber the pre-evolutions among all Pokemon at L or higher. Without such an L,
    the lowest level of an evolved species (majority False)."""
    pop = [(level, species in evolved, t) for species, level, t in mons
           if species in evolved or species in pre]
    levels = sorted({level for level, is_evolved, _ in pop if is_evolved})
    if not levels:
        return None

    def at(level):
        evolved_count = sum(1 for lv, e, _ in pop if e and lv >= level)
        trainer = next(t for lv, e, t in pop if e and lv == level)
        return {"level": level, "evolved": evolved_count, "trainer": trainer["id"],
                "pre": sum(1 for lv, e, _ in pop if not e and lv >= level)}

    for level in levels:
        cell = at(level)
        if cell["evolved"] > cell["pre"]:
            cell["majority"] = True
            return cell
    cell = at(levels[0])
    cell["majority"] = False
    return cell


# ---------------------------------------------------------------------------

def describe(evo):
    if evo["method"] in NON_LEVEL_METHODS:
        text = "%s %s" % ("item" if evo["method"] == "EVO_ITEM" else "trade", evo["param"])
        text = text.replace(" 0", "").replace("ITEM_", "")
    else:
        text = "level 0" if evo["method"] == "EVO_LEVEL" else "level 0, battle only"
    conds = []
    for c, a in evo["conditions"]:
        a = re.sub(r"\(\(\d+ >= \d+\) \? \d+ : (\d+)\)", r"\1", a)
        if c == "IF_GENDER":
            a = {"0x00": "male", "0xFE": "female"}.get(a, a)
        conds.append(c[3:].lower() + (" " + a if a else ""))
    if conds:
        text += " (" + ", ".join(conds) + ")"
    return text


def later_stages(evolutions, species):
    """All species that species evolves into, directly or later, by any method."""
    seen, todo = set(), [species]
    while todo:
        for evo in evolutions.get(todo.pop(), []):
            if evo["target"] not in seen:
                seen.add(evo["target"])
                todo.append(evo["target"])
    return seen


def collect(repo, hns_rev, hns_path, rule="majority"):
    names, by_number = load_species_constants(repo)
    evolutions, present = load_evolutions(repo, names)
    excluded = load_excluded(repo, names)
    maps = load_trainer_maps(repo)
    hns = parse_party(read_file(repo, hns_path, hns_rev), "HnS")
    em = parse_party(read_file(repo, EMERALD_PARTY), "Emerald")
    frlg = parse_party(read_file(repo, FRLG_PARTY), "FRLG")
    used = {"hns": referenced_trainers(repo, hns_rev, hns_path),
            "em": referenced_trainers(repo, None, EMERALD_PARTY),
            "frlg": referenced_trainers(repo, None, FRLG_PARTY)}
    low = {"hns": lowest_levels(hns, names, used["hns"]),
           "em": lowest_levels(em, names, used["em"]),
           "frlg": lowest_levels(frlg, names, used["frlg"])}
    unused = {"hns": [t["id"] for t in hns if t["mons"] and t["id"] not in used["hns"]
                      and not SKIP_TRAINER_RE.match(t["id"])]}
    hns_mons = [(names[const], level, t) for t in hns
                if t["id"] in used["hns"] and not SKIP_TRAINER_RE.match(t["id"])
                for const, level in t["mons"]]

    rows = {}
    for src in sorted(evolutions):
        for evo in evolutions[src]:
            if evo["method"] in NON_LEVEL_METHODS:
                pass
            elif evo["method"] in LEVEL_METHODS and evo["param"] == "0":
                pass
            else:
                continue
            tgt = evo["target"]
            row = rows.setdefault(tgt, {"target": by_number[tgt], "enabled": tgt in present,
                                        "excluded": tgt in excluded, "ways": [], "pre": []})
            way = "%s: %s" % (by_number[src], describe(evo))
            if way not in row["ways"]:
                row["ways"].append(way)
            if by_number[src] not in row["pre"]:
                row["pre"].append(by_number[src])

    def cell(key, species, via):
        level, t = low[key][species]
        where, version = trainer_map(maps, t["id"])
        return {"level": level, "trainer": t["id"], "class": t["class"], "map": where,
                "map_version": version, "via": by_number[species] if via else None}

    for tgt, row in rows.items():
        for key in ("hns", "em", "frlg"):
            # The species itself, or a later stage fielded lower (Raichu before Pikachu).
            best = None
            for species in [tgt] + sorted(later_stages(evolutions, tgt)):
                if species in low[key] and (best is None or low[key][species][0] < low[key][best][0]):
                    best = species
            row[key] = cell(key, best, best != tgt) if best is not None else None
            row[key + "_own"] = cell(key, tgt, False) if tgt in low[key] else None
        evolved = [tgt] + sorted(later_stages(evolutions, tgt))
        row["evolved"] = [by_number[s] for s in evolved]
        row["majority"] = majority_level(hns_mons, {names[p] for p in row["pre"]}, set(evolved))
        if row["excluded"] or not row["hns"]:
            row["level"] = None
        elif rule == "lowest":
            row["level"] = row["hns"]["level"]
        else:
            row["level"] = row["majority"]["level"]
    return [rows[t] for t in sorted(rows)], unused


def pretty(const):
    """SPECIES_MR_MIME -> Mr Mime, TRAINER_JASMINE_1_3_HNS -> Jasmine_1_3."""
    if const.startswith("TRAINER_"):
        return re.sub(r"_HNS$", "", const[8:]).title()
    return const[8:].replace("_", " ").title()


def majority_text(r):
    m = r["majority"]
    counts = "%d %s vs %d %s at >= %d" % (
        m["evolved"], "/".join(pretty(s) for s in r["evolved"]),
        m["pre"], "/".join(pretty(s) for s in r["pre"]), m["level"])
    h = r["hns"]
    lowest = "lowest %d %s%s" % (h["level"], pretty(h["trainer"]),
                                 " (%s)" % pretty(h["via"]) if h["via"] else "")
    if m["majority"]:
        return "majority from %d: %s; %s" % (m["level"], counts, lowest)
    return "no majority (%s), so %s" % (counts, lowest)


def ref(cell):
    if not cell:
        return "-"
    via = (" via " + cell["via"][8:]) if cell["via"] else ""
    return "%d (%s%s)" % (cell["level"], cell["trainer"], via)


def print_markdown(rows):
    print("| Target | Evolution | HnS lowest level, trainer, map | HnS majority | Emerald | FRLG | Used |")
    print("|---|---|---|---|---|---|---|")
    for r in rows:
        hns = "-"
        if r["hns"]:
            h = r["hns"]
            where = h["map"] or "no map script"
            if h["map_version"] not in ("", "hns"):
                where += ", " + h["map_version"]
            via = (", via " + h["via"][8:]) if h["via"] else ""
            hns = "%d %s (%s, %s%s)" % (h["level"], h["trainer"], h["class"], where, via)
        majority = majority_text(r) if r["hns"] else "-"
        if r["excluded"]:
            used = "excluded"
        elif r["level"] is not None:
            used = str(r["level"])
        else:
            used = "%d (fallback)" % FALLBACK_LEVEL
        print("| %s%s | %s | %s | %s | %s | %s | %s |" % (
            r["target"][8:], "" if r["enabled"] else " (disabled)", "; ".join(r["ways"]),
            hns, majority, ref(r["em"]), ref(r["frlg"]), used))


def print_name_list(title, names):
    if not names:
        return
    print("")
    print(title)
    line = "//"
    for name in names:
        if len(line) + len(name) + 1 > 100:
            print(line)
            line = "//"
        line += " " + name
    print(line)


def print_header(rows, rule):
    width = max(len(r["target"]) for r in rows if r["level"] is not None) + 2
    print("// Levels from which scaled trainer Pokemon (src/level_scaling.c) take a stone, trade or")
    print("// condition-only evolution into the species. Unlisted species use %s." % FALLBACK_NAME)
    if rule == "lowest":
        print("// Each level is the lowest at which an HnS 2.0.5 trainer fields the species or a later")
        print("// stage; the comment names that trainer and map.")
        print("// Regenerate (overwrites edits): python3 -I tools/make_trainer_evo_levels.py --rule lowest --header > src/data/trainer_evo_levels.h")
    else:
        print("// Each level L is the lowest level at which HnS 2.0.5's trainers field the species (or a")
        print("// later stage) such that, among all their Pokemon at L or higher, it outnumbers its")
        print("// pre-evolution (else the lowest level they field it). The comment gives those counts and")
        print("// the lowest level any HnS trainer fields the species or a later stage.")
        print("// Regenerate (overwrites edits): python3 -I tools/make_trainer_evo_levels.py --header > src/data/trainer_evo_levels.h")
    print("static const struct TrainerEvoLevel sTrainerEvoLevels[] =")
    print("{")
    for r in rows:
        if r["level"] is None:
            continue
        h = r["hns"]
        entry = "{%s," % r["target"]
        if rule == "lowest":
            where = ""
            if h["map"]:
                where = ", " + h["map"]
                if h["map_version"] not in ("", "hns"):
                    where += " (retired map)"
            via = (", fields " + h["via"]) if h["via"] else ""
            comment = "%s%s%s" % (h["trainer"], where, via)
        else:
            comment = majority_text(r)
        print("    %s %3d}, // %s" % (entry.ljust(width + 2), r["level"], comment))
    print("};")
    print_name_list("// Not fielded by HnS's trainers, so %s:" % FALLBACK_NAME,
                    [r["target"] for r in rows if r["level"] is None and r["enabled"] and not r["excluded"]])
    print_name_list("// Never picked (%s in %s):" % (EXCLUDED_ARRAY, SCALING_C),
                    [r["target"] for r in rows if r["excluded"]])


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--header", action="store_true", help="print src/data/trainer_evo_levels.h")
    parser.add_argument("--json", action="store_true", help="print the raw rows as JSON")
    parser.add_argument("--rule", choices=("majority", "lowest"), default="majority",
                        help="majority: level from which HnS mostly fields the evolved species "
                             "(default); lowest: lowest level at which HnS fields it")
    parser.add_argument("--hns-rev", default=HNS_REV,
                        help="git revision of HnS's party file ('' = working tree), default %(default)s")
    parser.add_argument("--hns-party", default=HNS_PARTY, help="path of HnS's party file")
    parser.add_argument("--repo", default=".", help="repository root")
    args = parser.parse_args()
    rows, unused = collect(args.repo, args.hns_rev or None, args.hns_party, args.rule)
    for r in rows:
        if args.rule == "majority" and r["level"] is not None and not r["majority"]["majority"]:
            print("note: %s: HnS never fields it more often than %s, lowest level %d used"
                  % (r["target"], "/".join(r["pre"]), r["level"]), file=sys.stderr)
    if args.header:
        print_header(rows, args.rule)
    elif args.json:
        json.dump({"rows": rows, "unused_hns_trainers": unused["hns"]}, sys.stdout, indent=1)
        print()
    else:
        print_markdown(rows)
        print("")
        print("HnS trainers no script or table names (skipped): " + ", ".join(unused["hns"]))


if __name__ == "__main__":
    main()
