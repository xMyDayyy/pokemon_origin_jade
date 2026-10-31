# Origin Jade - automated tests

The C test suite in `test/` (upstream pokeemerald-expansion tests plus the
Origin Jade tests in `test/origin_jade/`) runs headless in mGBA. Most
upstream tests expect English battle texts and names and the expansion's
default battle configs, so many of them fail in Origin Jade by design.
`tools/run_tests.py` therefore compares every run with a list of known
failures and only reports what is new.

## Running

    python3 tools/run_tests.py            # build, run all files, compare
    python3 tools/run_tests.py -j4 test/save.c test/origin_jade/level_scaling.c
    python3 tools/run_tests.py --no-build # reuse Pokemon_Origin_Jade-test.elf

- The script builds `Pokemon_Origin_Jade-test.elf` (`make BUILD=jade TEST=1`)
  and runs every test file in its own `mgba-rom-test` process, `-j` files
  at a time (default: all cores). A file that hangs is stopped after the
  timeout or after 20000 emulator messages within one test.
- Exit status 0: every failure is in the baseline with the same result,
  the same place (file:line of the failing check) and the same reason.
  Numbers in the reason do not count (statistical rates, damage values,
  item counts), so a known failure may change only its numbers. 1: new
  failures, or known failures with a different result (e.g. FAIL that
  became CRASH), place or reason (e.g. a MESSAGE test that now fails on an
  HP check); both are listed at the end.
- Results: `build/jade-test/results/results.tsv` (every test with its
  status, result, place and failure reason) and one log per file in
  `build/jade-test/results/logs/`.
- The full run takes 10 to 12 minutes with `-j3`.
- `make check BUILD=jade` still runs the whole suite in one go through
  mgba-rom-test-hydra, without the baseline.

## Results

- ok: PASS, KNOWN_FAILING, EXPECTED_FAIL, KNOWN_FAILING_PASS.
- todo: TO_DO, upstream placeholders. Not a failure.
- fail: FAIL, ASSUMPTION_FAIL, INVALID, CRASH, TIMEOUT, EXPECTED_FAIL_PASS,
  and HANG/NO_RESULT when the file run ended early.

## Baseline

`test/known_failures.tsv` lists the known failures: file, test, result,
place and reason of the failing check. Tests that fail on a file's
`ASSUMPTIONS` block get the place and reason of that block. State of
2026-10-30: 5124 tests in 946 files, 2333 ok, 629 todo, 2162 known
failures. Two runs gave the same results. The causes:

- 1969 "Unmatched MESSAGE": the tests expect English battle texts. Battle
  texts and names are German without a language switch, so
  `GAME_LANG=ENGLISH` does not help.
- 127 statistical tests ("Expected ... passes/successes, observed ..."),
  mostly because the message they count never matches.
- 16 INVALID "requires explicit party index": HnS Poke Balls are used from
  the party menu (`ITEM_USE_PARTY_MENU`), the test runner then wants a
  party index (among them all tests in `test/battle/capture.c`).
- 14 ASSUMPTION_FAIL (evolution tracker, Revelation Dance, sleep turns,
  sleep clause): the test's assumptions do not hold with the HnS configs.
- 6 spread-move damage tests (`damage_formula.c`, `levitate.c`,
  `absorb.c`): `B_MULTIPLE_TARGETS_DMG GEN_3` from HnS.
- 6 text width tests in `test/text.c` with German texts; each stops at the
  first text that is too wide.
- 2 Day Care tests in `test/daycare.c` (added 2026-10-31, not in the
  numbers above) expect a Pichu egg from Pikachu: in the test's fresh save
  Johto is not unlocked, so the egg is a Pikachu (D-049).
- 24 others, not triaged yet: animation order (11), AI move choice (4),
  bag sorting, Sheer Force, Daycare regional forms, the form table of
  Alolan Raticate, `CreateNPCTrainerPartyForTrainer`, a trainer slide and
  one learnset test that meets a disabled species. Some of them may be
  real bugs.

After a change that fixes tests or changes them on purpose, or that moves
lines of a test file with known failures (the place is a line number):

    python3 tools/run_tests.py --update-baseline

Then review the diff of `test/known_failures.tsv` and commit it together
with the change. Do not add a failure to the baseline to hide a
regression; fix it, or note it in the commit message and in
`docs/origin_jade/DECISIONS.md` if it is a decision.

## Test environment

Every test starts with cleared save blocks, the challenge settings of a new
game (`SetDefaultChallengeSettings`, one-type challenge off) and empty PC
boxes with names (`test/test_runner.c`). In the test build,
`GetFlagPointer`/`GetVarPointer` make a test INVALID when it uses a flag or
var number without storage (D-016).

## Origin Jade tests

- `test/origin_jade/level_scaling.c`: anchor rule (mean of the three highest
  levels, at most `SCALING_ANCHOR_MAX_DROP` below the highest, eggs left
  out), corridor clamp and the title lifting the ceiling, boss extra
  levels, team spread, wild band, static floor on Johto and Hoenn maps,
  Kanto unscaled before its title and never below the set level after it.
  Rules: D-012, D-031, D-039.
- `test/origin_jade/event_data.c`: flag and var routing of
  `GetFlagPointer`/`GetVarPointer` into SaveBlock1 and the SaveBlock3
  windows (FRLG, FRLG trainers, HnS rematch tiers, Origin Jade). D-016.
- `test/origin_jade/region_rule.c`: region of single species; every baby
  and later evolution of a Gen 1-3 line counts to its line's region (29
  Johto, 7 Hoenn; the test build enables every family, so the counts per
  region of the ROM cannot be checked there); Johto unlock on the first
  Johto map after the Kanto title (not the gatehouse), its catch-ups and
  the Hoenn unlock; Day Care eggs before the unlock (also through the Day
  Care itself) and with randomized species; the seen rule. D-049.
- `test/save.c`: save block sizes of Origin Jade (D-017).

The tests read the bands from `include/config/*_scaling.h`. They use
Route 29 (Johto) and Route 101 (Hoenn) as maps with a corridor and need
floors below the anchors they set (46 and 86).

## Static check tools

These tools read the sources, the map data or the built ELF; none of them
plays the game. Run them from the repository root; the ones marked
"after make" need a built ROM. The CI workflow (D-046) runs
`check_flags.py`, `make_kanto_complete.py --check`, `check_budget.py`,
`check_warnings.py` and, without blocking, `check_merge.py`.

- `python3 -I tools/check_maps.py --min-severity klein`: warps, arrival
  tiles, objects, connections and layouts of all active maps, with a
  reachability walk from the new game; `--rev audit --compare 3525d22e71`
  compares two states, `--render MAP` draws a map. Exit 1 on a proven
  finding from "wichtig" up.
- `python3 -I tools/simulate_progress.py --out DIR`: static playthrough
  model Kanto -> Johto -> Hoenn (milestones in order, where progress
  stops, unreachable maps, items, trainers, gifts); `--hoenn-ticket`
  starts with the Hoenn Ticket already received (what-if; in the game
  Troy hands it over in Oak's lab, D-047), `--diff OLD NEW` compares two
  reports. Exit 0 only if the Hoenn title is reachable.
- `tools/oj_world.py`: shared data layer of the static tools (maps,
  layouts, metatile behaviours, map sections, items, event scripts);
  imported with `sys.path.insert(0, "tools"); import oj_world`, no command
  line of its own.
- `python3 -I tools/check_game_text.py --english --out DIR`: measures every
  game text line in the sources against 208 px and lists English
  leftovers by region; `--list` prints the over-wide lines. Exit 1 on a
  proven over-wide line of active content.
- `python3 -I tools/check_save_safety.py --json out.json`: gifts without a
  space check, bag pockets (also with the item randomizer), new game
  state, migrations, Hall of Fame, clock and link features; `--check NAME`
  runs one check. Exit 1 on a blocker or critical finding.
- `python3 tools/check_text_width.py --list` (after make): line widths of
  all script texts as the built ROM shows them. Exit 1 on an exact line
  over the limit outside locked maps.
- `python3 tools/check_budget.py` (after make): save blocks and EWRAM,
  IWRAM and ROM against their limits (D-017); `--elf` for the release ELF,
  `--min-free N` to fail below N free bytes.
- `python3 tools/check_warnings.py build.log`: compiler warnings of a full
  build (`make clean`, then `make -O 2>&1 | tee build.log`) against
  `tools/warnings_baseline.txt`; `--update` rewrites the baseline.
- `python3 check_merge.py`: consistency of the Kanto/Johto/Hoenn merge
  (warps, connections, flags, layouts, wild tables); known cases are in
  its `KNOWN_ERRORS` with the decision that covers them.

Also after every change to flags, vars, trainers or Kanto content:
`python3 tools/check_flags.py` (D-016) and
`python3 tools/make_kanto_complete.py --check`.

## Test matrix (2026-10-31)

State: branch `audit` at `b62f22e381` and the documentation commits on
top (no code change). Details, the emulator checklists and the raw data are
in the audit's test matrix; `docs/origin_jade/BETA_READINESS.md` gives the
verdict per beta criterion. Nothing was checked in an emulator.

| Area | Check | Result |
|---|---|---|
| Build | `make -j2` from scratch | exit 0, 397 of 397 C files, ROM SHA-1 `5c1c08ae7685bf6073ea20c7f87df981d6488c2a` (same as the incremental build) |
| Build | `make release` | exit 0, SHA-1 `182fd390ba35e26e171f5684d6a87d3b5f7a7ca0`, overworld debug menu not linked; not started |
| Build | `check_warnings.py` | 105 warnings, as in the baseline; release build 111 (LTO and newlib stubs) |
| Data | `check_merge.py` | 0 errors, 8 known |
| Data | `make_kanto_complete.py --check`, `--overlap` | header up to date, 0 new shared names |
| Flags and vars | `check_flags.py`; `test/origin_jade/event_data.c` | 0 problems (3426 flags, 693 vars); 7 of 7 tests pass |
| Saves | `check_budget.py`; `test/save.c` | SaveBlock1 15868/15872, SaveBlock2 3892/3968, SaveBlock3 1008/1624, PokemonStorage 34144/35712; EWRAM 95.05 %, IWRAM 78.44 %, ROM 77.18 %; 4 of 4 tests pass |
| Saves | `check_save_safety.py` | 78 findings: 1 important (no running clock; the fake clock preselection is not modelled), 3 minor (Hall of Fame size is a false alarm, two bag pockets with the item randomizer), 74 optional |
| Progress | `simulate_progress.py` | with the Hoenn Ticket story (D-047), without `--hoenn-ticket`: Kanto title in wave 50, Johto title in 105, Hoenn Ticket in 106 (Oak's lab), Hoenn reached in 108, Hoenn title in 137 (exit 0); with `--hoenn-ticket`: Hoenn title in 136; nothing lost against the earlier run with `--hoenn-ticket` (Hoenn title in 140); no other stop on the main path |
| Maps | `check_maps.py --min-severity klein` | 88 findings, all minor (base `3525d22e71`: 117, of them 3 critical and 10 important) |
| Texts | `check_text_width.py --list` | 35 exact lines over 208 px (Johto 28, Kanto 1, locked 6), none over 216 px outside locked maps |
| Texts | `check_game_text.py --english` | English: Johto 125 (51 important), shared 252, Hoenn 7, Kanto 5 (locked) |
| Pokemon | availability model of the audit | 421 of 422 Pokedex species with a source (Jirachi none, A69); all 9 starters wild |
| Engine | `run_tests.py` | 5124 tests in 946 files: 2333 ok, 629 todo, 2162 known failures, 0 new, 0 changed (the baseline of 2026-10-30 holds) |
| Engine | `test/origin_jade/level_scaling.c` | 9 of 9 pass |
| Not checked | - | play in an emulator, the clock at runtime, link features, Battle Frontier and other facilities at runtime, randomizer and Nuzlocke at runtime, the CI workflow on GitHub |
