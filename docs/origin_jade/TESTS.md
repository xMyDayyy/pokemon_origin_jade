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
failures. Two runs gave the same results. State of 2026-10-31 at
`b022af5623`: 5140 tests in 948 files, 2347 ok, 629 todo, 2164 known
failures (the 16 new tests are `test/origin_jade/region_rule.c` and
`test/origin_jade/debug_states.c`; the two Day Care tests below are the
new known failures). The causes:

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
  numbers of 2026-10-30) expect a Pichu egg from Pikachu: in the test's
  fresh save Johto is not unlocked, so the egg is a Pikachu (D-049).
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
  Care itself) and with any randomizer option (the modifiers alone keep
  the rule); the seen rule; the Kanto
  Pokedex count and Celadon's diploma (151, Mew not needed); the Johto
  Pokedex complete without Azurill and Wynaut. D-049.
- `test/origin_jade/debug_states.c`: the debug menu's "Johto Test" and
  "Hoenn Test" (D-050) on a fresh save: Pokedex counts (185 and 282),
  party and PC (75 and 136 final stages) with some levels, usable PC
  Pokemon, Johto and Hoenn locked or unlocked, badges, Troy's
  `VAR_HOENN_TICKET_STATE` 1 and room for the Hoenn Ticket, a picked-up
  TM and fossil of Johto, one item of each kind of purchase or repeatable
  source (Game Corner, marts and their Premier Ball, berry trees, phone
  gifts, the Route 40 Trainer Hill's prizes ...),
  `FLAG_MINTS_DISABLED` as the new game set it and Goldenrod's mints only
  while that option sells them.
- `test/origin_jade/daycares.c`: Kanto's, Johto's and Hoenn's Day Cares
  keep their own Pokemon, and a pair in Johto's lays its egg there without
  touching Hoenn's `FLAG_PENDING_DAYCARE_EGG`. D-052.
- `test/save.c`: save block sizes of Origin Jade (D-017).

The tests read the bands from `include/config/*_scaling.h`. They use
Route 29 (Johto) and Route 101 (Hoenn) as maps with a corridor and need
floors below the anchors they set (46 and 86).

## Static check tools

These tools read the sources, the map data or the built ELF; none of them
plays the game. Run them from the repository root; the ones marked
"after make" need a built ROM. The CI workflow (D-046) runs
`check_flags.py`, `check_regions.py`, `make_debug_states.py --check`,
`check_budget.py`, `check_warnings.py` and, without blocking,
`check_merge.py`.

- `python3 -I tools/check_maps.py --min-severity klein`: warps, arrival
  tiles, objects, connections and layouts of all active maps, with a
  reachability walk from the new game; `--rev audit --compare 3525d22e71`
  compares two states, `--render MAP` draws a map. Exit 1 on a proven
  finding from "wichtig" up.
- `python3 -I tools/check_regions.py`: no wild table of an active map, no
  overworld Pokemon showing a species and no gift or static battle of a
  map script (`givemon`, `giveegg`, `setwildbattle`, `seteventmon`) offers
  a species of a later region (Kanto maps only Kanto species, Johto maps
  Kanto and Johto ones, D-049), and no Kanto or Johto species lies behind
  its region's block of the National Pokedex order; species regions as
  in `src/region_rule_oj.c`. `--list` prints the species of each region's
  maps, `--dex-gaps` the Pokedex blocks. Known exceptions (the
  unreachable `Route22_hns`, O-022; the Hoenn fossils of the Ruins of
  Alph lab; an uncalled test script) are listed but do not fail. Exit 1
  on a finding.
- `python3 tools/make_debug_states.py --check` (needs the generated
  teachable learnsets of a build): the debug states of D-050
  (`src/data/debug_kanto_complete.h`, `src/data/debug_johto_complete.h`)
  are up to date, and every flag and var the scripts of Kanto and Johto
  (and the specials they call) write is either part of a state or listed
  in the generator with a reason (`UNTOUCHED`, the manual tables), so a
  new story flag cannot be forgotten; no value comes from a write that
  runs only after Hoenn progress. Also: every map pickup and hidden item
  collected, Johto locked in the Johto Test, Hoenn locked in both, every
  fly destination of the regions set, no badge flag 09-16, party and PC
  hold exactly the final stages, Troy's scene pending without a Hoenn
  Ticket in the bag. `--levels` prints how each PC level was derived,
  `--overlap` the flags and vars of the Johto Test that Johto or Hoenn
  share. Exit 1 on a finding.
- `python3 -I tools/simulate_progress.py --out DIR`: static playthrough
  model Kanto -> Johto -> Hoenn (milestones in order, where progress
  stops, unreachable maps, items, trainers, gifts). Without a switch it
  follows the story through Troy's scene in Oak's lab (D-047) and the
  ferry; `--hoenn-ticket` starts with the Hoenn Ticket already received
  (what-if), `--diff OLD NEW` compares two reports. Exit 0 only if the
  Hoenn title is reachable.
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
`python3 tools/make_debug_states.py --check`; after a change to wild
tables, overworld Pokemon, gifts or the Pokedex order:
`python3 -I tools/check_regions.py` (D-049).

## Test matrix (2026-10-31)

State: branch `audit` at `b022af5623` (the audit series, the story
packages D-047 to D-049, their fixes and the debug states D-050) and the
documentation commits on top (no code change). Results from the
integration run `integ_b10` on the tip unless another run is named; the
fresh build, the release build, the warning count and the English count
come from a separate worktree of the tip.
`docs/origin_jade/BETA_READINESS.md` gives the verdict per beta criterion
and the emulator test list for the story packages. Nothing was checked in
an emulator.

| Area | Check | Result |
|---|---|---|
| Build | `make` in the integration clone (incremental) | exit 0, ROM SHA-1 `11bec7d4cba038d647668f2f86c68ef3a29eee1f`; each of the 42 commits after the audit series built with its final id (`make=ok`, `check_flags` 0) |
| Build | `make` from scratch (after `rm -rf build/jade`) | exit 0, 397 C files, the same ROM SHA-1 as the incremental build |
| Build | `make release` | exit 0, SHA-1 `34e173bde2dc2b804e1132a60a5675f928dd33b4`, overworld debug menu and debug states not linked; not started |
| Build | `check_warnings.py` | 105 warnings on the log of the fresh build, as in the baseline; release build 111 (LTO and newlib stubs) |
| Data | `check_merge.py` | 0 errors, 8 known (205 warnings, 273 hints, as in the baseline) |
| Data | `check_regions.py` | 0 problems, the known exceptions listed; `--dex-gaps` (regions package): Kanto block 1-185, Johto block 186-282, no species behind its region's block |
| Data | `make_debug_states.py --check`, `--overlap` | both headers up to date at the tip; at each of the 7 commits after the story packages the per-commit log records one header up to date and no problem: `debug_kanto_complete.h` up to `ae3e095a3c` (before `0ab7449520` the generator was `make_kanto_complete.py`), `debug_johto_complete.h` (new in `13bf3c8cb6`) from `13bf3c8cb6` on; `--overlap` 0 new (debug package) |
| Flags and vars | `check_flags.py`; `test/origin_jade/event_data.c` | 0 problems (3428 flags, 693 vars); 7 of 7 tests pass |
| Saves | `check_budget.py`; `test/save.c` | SaveBlock1 15868/15872, SaveBlock2 3892/3968, SaveBlock3 1008/1624, PokemonStorage 34144/35712; EWRAM 95.05 %, IWRAM 78.44 %, ROM 77.16 %; 4 of 4 tests pass |
| Saves | `check_save_safety.py` | 76 findings (debug package, the integration clone gave the same count): 1 important, 3 minor, 72 optional; Key Items pocket 58 obtainable of 60 slots |
| Progress | `simulate_progress.py` | without a switch: Kanto title in wave 50, Johto title 105, Hoenn Ticket 106 (Oak's lab), Hoenn reached 108, Hoenn badges 109-127, Hoenn title 137, exit 0; 195 of 1125 active maps unreachable, none on the story path; the same waves on `58f244eade` (`integ_b9`) |
| Progress | `simulate_progress.py --hoenn-ticket` | Hoenn title in 136; nothing lost against the run with the switch on `b62f22e381` (Hoenn title in 140) (ticket package) |
| Maps | `check_maps.py --min-severity klein` | 88 findings, all minor |
| Texts | `check_text_width.py --list` | 35 exact lines over 208 px (Johto 28, Kanto 1, locked 6), none over 216 px outside locked maps |
| Texts | `check_game_text.py --english` | English: Johto 125, shared 252, Hoenn 7, Kanto 5 (locked), as on `b62f22e381`; the new English message of the debug menu ("Hoenn Test needs a new game..."; the Johto Test message only moved) is debug-only (D-020) |
| Pokemon | availability model of the audit | not re-run after the story packages (see the earlier state); `check_regions.py` above |
| Engine | `run_tests.py` | 5140 tests in 948 files: 2347 ok, 629 todo, 2164 known failures, 0 new, 0 changed (`integ_tests_b10`); on `58f244eade`: 5138 tests, 0 new, 0 changed (`integ_tests_b9`) |
| Engine | Origin Jade tests | `level_scaling.c` 9/9, `event_data.c` 7/7, `region_rule.c` 14/14, `debug_states.c` 2/2, `test/save.c` 4/4 |
| Not checked | - | play in an emulator (story scenes, port menus, Pokedex, Day Care, debug states), the clock at runtime, link features, Battle Frontier and other facilities at runtime, randomizer and Nuzlocke at runtime, the CI workflow on GitHub |

### Earlier state: `b62f22e381` (audit series)

State: branch `audit` at `b62f22e381` and the documentation commits on
top (no code change). Details, the emulator checklists and the raw data are
in the audit's test matrix. Nothing was checked in an emulator.

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
| Progress | `simulate_progress.py` | without the ticket: Kanto title in wave 50, Johto title in 105, Hoenn unreachable (O-002, resolved later by D-047); with `--hoenn-ticket`: Hoenn title in 140; no other stop on the main path |
| Maps | `check_maps.py --min-severity klein` | 88 findings, all minor (base `3525d22e71`: 117, of them 3 critical and 10 important) |
| Texts | `check_text_width.py --list` | 35 exact lines over 208 px (Johto 28, Kanto 1, locked 6), none over 216 px outside locked maps |
| Texts | `check_game_text.py --english` | English: Johto 125 (51 important), shared 252, Hoenn 7, Kanto 5 (locked) |
| Pokemon | availability model of the audit | 421 of 422 Pokedex species with a source (Jirachi none, A69); all 9 starters wild |
| Engine | `run_tests.py` | 5124 tests in 946 files: 2333 ok, 629 todo, 2162 known failures, 0 new, 0 changed (the baseline of 2026-10-30 holds) |
| Engine | `test/origin_jade/level_scaling.c` | 9 of 9 pass |
| Not checked | - | play in an emulator, the clock at runtime, link features, Battle Frontier and other facilities at runtime, randomizer and Nuzlocke at runtime, the CI workflow on GitHub |
