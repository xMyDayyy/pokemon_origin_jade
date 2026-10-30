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
- `test/save.c`: save block sizes of Origin Jade (D-017).

The tests read the bands from `include/config/*_scaling.h`. They use
Route 29 (Johto) and Route 101 (Hoenn) as maps with a corridor and need
floors below the anchors they set (46 and 86).
