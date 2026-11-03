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
new known failures). State of 2026-11-02 for round 2 (on `2f284d83b9`,
before the rebase; its last D-057 commit is now `edae0ce493`): 5148 tests
in 951 files, 2355 ok, 629 todo, 2164 known failures; the 8 new tests
(`daycares.c` 2, `even_wild_slots.c` 2, `region_badges.c` 1, two more in
`level_scaling.c`, one more in `debug_states.c`) pass, and no known
failure changed. State of 2026-11-03 at `61ac7e277d` (rounds 2 and 3 on
the owner's map commits): the same 5148 tests with the same results. The
causes:

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
  `absorb.c`): `B_MULTIPLE_TARGETS_DMG GEN_3` from HnS, kept by the owner
  (B-13, D-053).
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
  Kanto unscaled before its title and never below the set level after it;
  since round 2 also the Hoenn rival as a boss (+1 on the ace), the five
  Johto league rooms rising from Will to Lance (average and weak team,
  after the title, Victory Road) and the corridor ceiling of the current
  map (`GetScalingCeiling`, used by the catch malus). Rules: D-012, D-031,
  D-039, D-053.
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
- `test/origin_jade/debug_states.c` (3 tests): the debug menu's "Johto
  Test" and "Hoenn Test" (D-050) on a fresh save: Pokedex counts (185 and
  282), party and PC (75 and 136 final stages) with some levels, usable
  PC Pokemon, Johto and Hoenn locked or unlocked, badges, Troy's
  `VAR_HOENN_TICKET_STATE` 1 and room for the Hoenn Ticket, a picked-up
  TM and fossil of Johto, one item of each kind of purchase or repeatable
  source (Game Corner, marts and their Premier Ball, berry trees, phone
  gifts, the Route 40 Trainer Hill's prizes ...),
  `FLAG_MINTS_DISABLED` as the new game set it and Goldenrod's mints only
  while that option sells them.
- `test/origin_jade/daycares.c`: Kanto's, Johto's and Hoenn's Day Cares
  keep their own Pokemon, and a pair in Johto's lays its egg there without
  touching Hoenn's `FLAG_PENDING_DAYCARE_EGG`. D-052.
- `test/origin_jade/even_wild_slots.c`: the debug toggle "Even Wild Slots"
  (D-055): every land, water and Rock Smash slot comes up about equally
  often while it is on; off, the last land slot keeps its 1 %.
- `test/origin_jade/region_badges.c`: the badge readers count the region
  of a map: Kanto's badge flags, `VAR_JOHTO_BADGES` and `VAR_HOENN_BADGES`
  (`GetRegionBadgeCount`, D-007, D-053).
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
  Alph lab; an uncalled test script; Jirachi on Route 4, only after the
  first trip to Hoenn) are listed but do not fail. Exit 1 on a finding.
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
  Ticket in the bag; since round 2 also every purchase and repeatable item
  resolved (gifts through vars, mart lists, berry trees), no unused item
  table entry, every item in a pocket and no pocket or PC item storage
  over its slots. `--levels` prints how each PC level was derived,
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
  space check, bag pockets (also with the item randomizer; key items a
  player never holds together, `EXCLUSIVE_KEY_ITEMS`, take one slot), new
  game state, migrations, Hall of Fame, clock and link features;
  `--check NAME` runs one check. Exit 1 on a blocker or critical finding.
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

## Test matrix (2026-11-03, round 4: `r4-items`)

State: round 4 on top of `r23-docs` (`74c47e7e1b`): the branch `r4-items`
with 15 commits (every item can be obtained, D-059; tip of the code
`851aa886e2`) and its documentation commit (no code change). Results
from the per-commit run `percommit_r4` and the checks on `851aa886e2`,
the build from scratch in a new worktree of `851aa886e2`, the test run
`tests_r4` and the audit's item check `check_items.py` (outside the
repository). `docs/origin_jade/BETA_READINESS.md` gives the verdict per
beta criterion and the emulator test list. Nothing was checked in an
emulator.

| Area | Check | Result |
|---|---|---|
| Build | `make -j2` per commit (`percommit_r4`) | 15 of 15 commits after `74c47e7e1b` `make=ok` with their final ids; `check_flags` 0 at each. `make_debug_states.py --check`: both headers up to date at the first two commits and from `6f39278fee` on; in between it reports the round's new items as missing until that commit regenerates the headers (one regeneration for the round, as planned) |
| Build | `make -j2` from scratch (new worktree of `851aa886e2`) | exit 0, 398 C files, ROM SHA-1 `8fe887d805f3db1d350df34391a5d4488830873c`, the same as the incremental build of the per-commit run at its last commit; 8 minutes with `-j2` |
| Build | `make release` | exit 0, SHA-1 `a4bb57818d0471f0d805d680541a76d1214f969e`; overworld debug menu, debug states and "Even Wild Slots" not linked (checked in the ELF's symbols); not started |
| Build | `check_warnings.py` | 105 warnings on the log of the build from scratch, as in the baseline; release build 111 (LTO and newlib stubs), as before |
| Data | `check_merge.py` | 0 errors, 8 known (205 warnings, 273 hints, as in the baseline) |
| Data | `check_regions.py` | 0 problems; round 4 changes no wild table, overworld Pokemon or Pokemon gift |
| Data | `make_debug_states.py --check` | both headers up to date on `851aa886e2`; Johto Test 220 items (the rewards after the Kanto title or its rematch tier moved to the Hoenn Test), Hoenn Test 379 items (four berries in the PC's item storage) |
| Flags and vars | `check_flags.py`; `test/origin_jade/event_data.c` | 0 problems (3479 flags, 696 vars: 44 flags and one var more than round 3); 7 of 7 tests pass |
| Saves | `check_budget.py`; `test/save.c` | SaveBlock1 15868/15872, SaveBlock2 3892/3968, SaveBlock3 1584/1624, PokemonStorage 34144/35712; EWRAM 95.28 %, IWRAM 78.44 %, ROM 77.19 %; round 4 does not change the layout (its flags and var lie in free ids of the Origin Jade blocks) |
| Saves | `check_save_safety.py` | 76 findings: 1 important, 3 minor, 72 optional, as before round 4; Key Items pocket 61 obtainable, at most 60 at a time (the Mach and Acro Bike are never held together), 60 slots; without the tool change 27 minor (24 key item gifts) |
| Items | `check_items.py` (audit tool, outside the repository) | 903 items of the build: none without a regular source; 20 only by luck (wild held items, Pickup; O-078); 335 not meant, with the reason (D-059) |
| Progress | `simulate_progress.py` | without a switch: Kanto title in wave 50, GS Ball 51, Johto badges 55-91, Johto title 105, Hoenn Ticket 106, Hoenn reached 108, Hoenn badges 109-127, Hoenn title 137, exit 0; 195 of 1115 active maps unreachable, none on the story path; `--diff` against the round before its review fixes: nothing changed |
| Maps | `check_maps.py --min-severity klein` | 88 findings, all minor, on 1125 active maps, as before round 4; the new objects and hidden items bring nothing new |
| Texts | `check_text_width.py --list` | 35 exact lines over 208 px (Johto 28, Kanto 1, locked 6), as before; the new lines of round 4 at most 208 px (Brock's line after the Kanto title 162 px, Bill's grandfather at most 196 px) |
| Texts | `check_game_text.py --english` | Hoenn 0, Johto 23 and Kanto 5 (trainer names in upstream capitals, O-066), shared 97, `src` 11, locked maps 290, retired maps 3, as before round 4; every new text of round 4 has a German branch |
| Engine | `run_tests.py` | 5148 tests in 951 files: 2355 ok, 629 todo, 2164 known failures, 0 new, 0 changed (`tests_r4`, in the worktree of the build from scratch) |
| Engine | Origin Jade tests | `level_scaling.c` 11/11, `event_data.c` 7/7, `region_rule.c` 14/14, `debug_states.c` 3/3, `daycares.c` 2/2, `even_wild_slots.c` 2/2, `region_badges.c` 1/1, `test/save.c` 4/4; no test covers the new item sources, Carter's rematch flag or Scott's gift |
| Not checked | - | play in an emulator (the new item balls, hidden items and shops, Brock, the rematch rewards, Bill's grandfather, the designers' charms, Scott in the Kampfzone, the new Battle Point lists, the options text, the debug states), balance of the new items in the game, link features, the CI workflow on GitHub |

### Earlier state: rounds 2 and 3 (`runde23`, 2026-11-03)

State: the branch `runde23`: the owner's map commits `06ea236bdb` and
`ad4a8db368` on `2f284d83b9`, round 2 rebased onto them (62 commits, the
same subjects as before the rebase), its 5 documentation commits, round 3
(6 commits: contests as in Ruby and Sapphire, Emerald's battle tents and
the Route 111 Trainer Hill retired; tip `61ac7e277d`) and the
documentation commits on top (no code change). Results from the
per-commit run `percommit_r23`, the integration run `integ_r23` and the
test run `tests_r23` on `61ac7e277d`; the build from scratch, the release
build and the warning count from the worktree of `runde23`;
`check_save_safety.py` on the documentation tip.
`docs/origin_jade/BETA_READINESS.md` gives the verdict per beta criterion
and the emulator test list. Nothing was checked in an emulator.

| Area | Check | Result |
|---|---|---|
| Build | `make` per commit (`percommit_r23`) | 73 of 73 commits after `ad4a8db368` `make=ok` with their final ids (62 of round 2, 5 documentation commits, 6 of round 3); `check_flags` 0 and both debug headers up to date at each |
| Build | `make` in the integration worktree (incremental) | exit 0 on `61ac7e277d`, ROM SHA-1 `6346a2591693e2c99c3f1748b676d0f207afdbef` |
| Build | `make` from scratch (after removing `build/jade`) | exit 0, 398 C files, the same ROM SHA-1 |
| Build | `make release` | exit 0, SHA-1 `10174fe5187327f5e3cb4bcfe39d7392bb493031`; overworld debug menu, debug states and "Even Wild Slots" not linked (checked in the ELF's symbols); not started |
| Build | `check_warnings.py` | 105 warnings on the log of the build from scratch, as in the baseline; release build 111 (LTO and newlib stubs), as before |
| Data | `check_merge.py` | 0 errors, 8 known (205 warnings, 273 hints, as in the baseline) |
| Data | `check_regions.py` | 0 problems; the known exceptions listed, Jirachi on Route 4 among them |
| Data | `make_debug_states.py --check` | both headers up to date on `61ac7e277d` and at each of the 73 commits; round 3 does not touch their sources |
| Flags and vars | `check_flags.py`; `test/origin_jade/event_data.c` | 0 problems (3435 flags, 695 vars; 4 flags more than round 2: the contest reporters of Verdanturf and Fallarbor, Hoenn's TM Attract and TM Torment, `OJ_FLAGS_GLOBAL` + 1 to + 4); 7 of 7 tests pass |
| Saves | `check_budget.py`; `test/save.c` | SaveBlock1 15868/15872, SaveBlock2 3892/3968, SaveBlock3 1584/1624, PokemonStorage 34144/35712; EWRAM 95.28 %, IWRAM 78.44 %, ROM 77.17 %; 4 of 4 tests pass; round 3 does not change the layout |
| Saves | `check_save_safety.py` (documentation tip) | 76 findings: 1 important, 3 minor, 72 optional, as before rounds 2 and 3; Key Items pocket 58 obtainable of 60 slots |
| Progress | `simulate_progress.py` | without a switch: Kanto title in wave 50, GS Ball 51, Johto badges 55-91, Johto title 105, Hoenn Ticket 106 (Oak's lab), Hoenn reached 108, Hoenn badges 109-127, Hoenn title 137, exit 0; the Contest Pass in wave 112 (Verdanturf) instead of 121 (Lilycove), no other milestone moved; 195 of 1115 active maps unreachable (1125 before round 3: 16 retired, 6 new), none on the story path. The simulator counts every map folder of the build without the 13 link maps, `check_maps.py` (next row) the maps of `map_groups.json` with the link maps and without 3 unused houses; both lose the same 16 maps and gain the same 6 |
| Maps | `check_maps.py --min-severity klein` | 88 findings, all minor, on 1125 active maps (1135 before round 3; its count differs from the simulator's, see the row above); nothing from "important" up. With round 2 on the owner's map commits alone the entrance of the Route 111 hill had two critical findings (its warps lead to the removed Route 111 warp); round 3 retires the hill's maps, and nothing new came |
| Texts | `check_text_width.py --list` | 35 exact lines over 208 px (Johto 28, Kanto 1, locked 6), as before rounds 2 and 3; none over 216 px outside locked maps; the new lines of round 3 at most 208 px |
| Texts | `check_game_text.py --english` | Hoenn 0, Johto 23 and Kanto 5 (trainer names in upstream capitals, O-066), shared 97 (83 debug, 14 tent texts marked unused), `src` 11 (debug, unused union room texts, credits names), locked maps 290, retired maps 3; before round 3 Hoenn 2 (the two texts of Emerald's Slateport tent corridor, German since they moved into Slateport's contest hall, O-065) |
| Pokemon | catch list | not generated again: the owner's map commits and round 3 change no wild table, trainer party or Pokemon gift (`check_regions.py` above); the last run is in the round-2 matrix below |
| Engine | `run_tests.py` | 5148 tests in 951 files: 2355 ok, 629 todo, 2164 known failures, 0 new, 0 changed (`tests_r23`) |
| Engine | Origin Jade tests | `level_scaling.c` 11/11, `event_data.c` 7/7, `region_rule.c` 14/14, `debug_states.c` 3/3, `daycares.c` 2/2, `even_wild_slots.c` 2/2, `region_badges.c` 1/1, `test/save.c` 4/4; no test covers the contests |
| Not checked | - | play in an emulator (story scenes, port menus, calls, Day Cares, Jirachi, boss battles, debug states, the contest halls with their reception, return warps and blenders, German texts in their boxes), the clock at runtime, link features (the link contests among them), Battle Frontier and other facilities at runtime, randomizer and Nuzlocke at runtime, the CI workflow on GitHub |

### Earlier state: round 2 before the rebase (2026-11-02)

State: round 2 on `2f284d83b9`, before it was rebased onto the owner's
map commits: the branch `runde2` with the seven packages of the owner's
answers (58 commits), the four German rest commits on top and the
documentation commits on top of those (no code change). The rebase gave
every commit a new id with the same subject; the D-057 commit at the tip
of `runde2` is now `edae0ce493`, the rest tip `bdf6de26e6`, and
`PATCHES.md` lists only the new ids. The results below belong to the
builds before the rebase, without the owner's map commits. They come from
the integration run `integ_r2` and the test run `integ_tests_r2` on the
tip of `runde2` unless the documentation tip is named; the build from
scratch, the release build, the warning count, the text checks, the save
check and the budget come from a new worktree of the documentation tip,
whose code is that of the rest tip (the rest commits change only texts of
one map and the documentation). Nothing was checked in an emulator.

| Area | Check | Result |
|---|---|---|
| Build | `make` in the integration clone (incremental) | exit 0 on the tip of `runde2`, ROM SHA-1 `2c85c88afce3eb8d88bff8e265d3a955955ac0b6`; each of the 58 commits of `runde2` built with its id before the rebase (`make=ok`, `check_flags` 0, both debug headers up to date, `percommit_r2`); the four rest commits with their ids before the rebase one by one in their package worktree (`make` ok, `check_flags` 0, both debug headers up to date, ROM `9d8271bc…` from the second on, `r2derest_final`) |
| Build | `make` from scratch (new worktree of the documentation tip) | exit 0, ROM SHA-1 `9d8271bcd2f622c5b09d2b263bd3f8b8f74aec21`, the same as the rest package's build of the rest tip |
| Build | `make release` (documentation tip) | exit 0, SHA-1 `18eedc2ebb50f9165aaf65ade559a1281e9bd625`; overworld debug menu, debug states and "Even Wild Slots" not linked; not started |
| Build | `check_warnings.py` | 105 warnings on the log of the build from scratch, as in the baseline; release build 111 (LTO and newlib stubs), as before |
| Data | `check_merge.py` | 0 errors, 8 known (205 warnings, 273 hints, as in the baseline) |
| Data | `check_regions.py` | 0 problems on the tip of `runde2` and the documentation tip; the known exceptions listed, Jirachi on Route 4 among them |
| Data | `make_debug_states.py --check` | both headers up to date on the tip of `runde2`, at each of its 58 commits and on the documentation tip |
| Flags and vars | `check_flags.py`; `test/origin_jade/event_data.c` | 0 problems (3431 flags, 695 vars; 3 flags and 2 vars more than on `b022af5623`: the Hoenn lottery's flag and two vars, Jirachi's caught and defeated flags); 7 of 7 tests pass |
| Saves | `check_budget.py`; `test/save.c` | SaveBlock1 15868/15872, SaveBlock2 3892/3968, SaveBlock3 1584/1624 (1008 before the Day Cares of D-052), PokemonStorage 34144/35712; EWRAM 95.28 %, IWRAM 78.44 %, ROM 77.18 %; 4 of 4 tests pass |
| Saves | `check_save_safety.py` (documentation tip) | 76 findings: 1 important, 3 minor, 72 optional, as before round 2; Key Items pocket 58 obtainable of 60 slots |
| Progress | `simulate_progress.py` | without a switch: Kanto title in wave 50, GS Ball 51, Johto badges 55-91, Johto title 105, Hoenn Ticket 106 (Oak's lab), Hoenn reached 108, Hoenn badges 109-127, Hoenn title 137, exit 0; 195 of 1125 active maps unreachable, none on the story path; the same waves as on `b022af5623` |
| Maps | `check_maps.py --min-severity klein` | 88 findings, all minor; nothing from "important" up |
| Texts | `check_text_width.py --list` (documentation tip) | 35 exact lines over 208 px (Johto 28, Kanto 1, locked 6), as before round 2; none over 216 px outside locked maps |
| Texts | `check_game_text.py --english` | documentation tip: Johto 23 and Kanto 5 (trainer names in upstream capitals, O-066), Hoenn 2 (unreferenced texts of Emerald's Slateport tent corridor, O-065), shared 97 (83 debug, 14 tent texts marked unused), `src` 11 (debug, unused union room texts, credits names), locked maps 290; on the tip of `runde2` Hoenn 7 (the HnS tent lobby at Route 40, German since the rest commits); before round 2 Johto 125, shared 252, Hoenn 7, Kanto 5 |
| Pokemon | catch list (`make_fangliste.py`, outside the repository, on the tip of `runde2`) | after Kanto 151 of 151 Kanto species, after Johto 129 of 129 Johto species, after Hoenn 422 of 422 species (with evolutions and breeding); nothing missing at any stage; Jirachi on Route 4 |
| Trainers | trainer atlas (`make_trainer_atlas.py`, outside the repository, on the tip of `runde2`) | every trainer with team, items, abilities, moves and the level range after scaling: Kanto 471, Johto 421, Hoenn 823 entries; a listing for testers, not a check |
| Engine | `run_tests.py` | 5148 tests in 951 files: 2355 ok, 629 todo, 2164 known failures, 0 new, 0 changed (`integ_tests_r2`) |
| Engine | Origin Jade tests | `level_scaling.c` 11/11, `event_data.c` 7/7, `region_rule.c` 14/14, `debug_states.c` 3/3, `daycares.c` 2/2, `even_wild_slots.c` 2/2, `region_badges.c` 1/1, `test/save.c` 4/4 |
| Not checked | - | play in an emulator (story scenes, port menus, calls, Day Cares, Jirachi, boss battles, debug states, German texts in their boxes), the clock at runtime, link features, Battle Frontier and other facilities at runtime, randomizer and Nuzlocke at runtime, the CI workflow on GitHub |

### Earlier state: `b022af5623` (story packages, 2026-10-31)

State: branch `audit` at `b022af5623` (the audit series, the story
packages D-047 to D-049, their fixes and the debug states D-050) and the
documentation commits on top (no code change). Results from the
integration run `integ_b10` on the tip unless another run is named; the
fresh build, the release build, the warning count and the English count
come from a separate worktree of the tip. Nothing was checked in an
emulator.

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
