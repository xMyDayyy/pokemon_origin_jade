# Origin Jade - beta readiness

State of 2026-11-03: rounds 2 and 3 on top of the owner's map commits
`06ea236bdb` and `ad4a8db368` (on `balancing` since 2026-11-02, after the
198 commits of the first round): the branch `runde23` with round 2 (62
commits: the seven packages that implement the owner's answers of
2026-10-31 and 2026-11-02 and four German rest commits, rebased from
`2f284d83b9` onto the owner's commits), its 5 documentation commits,
round 3 (6 commits: contests as in Ruby and Sapphire, Emerald's battle
tents and the Route 111 Trainer Hill retired; tip `61ac7e277d`) and the
documentation commits on top, which change no code; then round 4 on top of
`r23-docs` (`74c47e7e1b`): the branch `r4-items` with 15 commits (every
item can be obtained, D-059; the owner's answers of 2026-11-03; tip of
the code `851aa886e2`) and its documentation commit. The sources are the
audit's finding list (297 findings, each with a status; checked again
against rounds 2 and 3: 149 fixed, 78 open or partly fixed), the owner's
answers, the reports of the packages, the per-commit build log
`percommit_r23` (all 73 commits after `ad4a8db368`), the integration run
`integ_r23` and the test run `tests_r23` on `61ac7e277d`, a build from
scratch and a release build of `61ac7e277d`, and `check_save_safety.py`
on the documentation tip; for round 4 the per-commit log `percommit_r4`
(15 of 15), the checks on its tip, a build from scratch, the test run
`tests_r4` and the audit's item check (`check_items.py`, outside the
repository). The state of rounds 2 and 3 alone, of round 2 before the
rebase and of 2026-10-31 (`b022af5623`) is in `TESTS.md`.
`docs/origin_jade/CHANGELOG.md` lists what changed,
`docs/origin_jade/PATCHES.md` how the series was made and verified.

## How to read this

- **Checked statically**: source, scripts and data read, the commit built
  and `tools/check_flags.py` run.
- **Checked by tool**: in addition, a check tool ran on this state
  (`tools/check_maps.py`, `tools/simulate_progress.py`,
  `tools/run_tests.py`, ...). The tools read sources, map data or the
  built ELF; none of them plays the game.
- **Not checked in an emulator**: true for everything in this file. There
  was no emulator with picture and input and no save files. The C test
  suite runs headless in mGBA, but it tests engine functions, not the game.
- Severity as in the audit: blocker, critical, important, minor, optional.
  A `*` marks an estimated severity (findings from the open points of the
  fix waves, `N-` ids).
- Finding ids: `A01`-`A122` (inventory), `T-<cluster>-<n>` (deep review),
  `W-<tool>-<n>` (tool runs), `N-<package>-<n>` (open points of the waves).
  `PATCHES.md` explains them.

## Summary

- **Kanto and Johto** have no known blocker on the story path: the
  progress simulator reaches the Kanto title and the Johto title, the map
  checker finds nothing from "important" up, and the known story traps are
  fixed in the source. Every text the German build shows on the story path
  has a German branch now (D-056, D-057).
- **Hoenn is reachable in a normal playthrough** (D-047): after the first
  Johto title Troy hands over the Hoenn Ticket in Oak's lab, and the
  ferries in Vermilion City and Olivine City sail to Hoenn. "Hoenn" stays
  in the ship menus until Slateport's harbour can be offered, so a player
  without a flyer always has a way back (O-032). The simulator reaches the
  Hoenn title without any switch. No known blocker is left.
- **Round 2** implemented the owner's answers of 2026-10-31 and 2026-11-02
  (D-051 to D-057): calls by region, separate Day Cares, Jirachi, Hoenn's
  lottery and marts, fixed boss movesets, the Johto league ladder, Troy and
  Red at level 100, badge counters per region, the Nuzlocke, challenge and
  randomizer rules of HnS, two debug aids, and German texts wherever the
  German build shows them. Every commit was built on its own; nothing of
  it ran in an emulator.
- **Round 3** brought the contests back as in Ruby and Sapphire (D-058):
  one rank per hall in Verdanturf, Fallarbor, Slateport and Lilycove, the
  Contest Pass from Verdanturf, the Pokeblock Case from Slateport, RS's
  lobbies and audience halls in place of Emerald's battle tents. The
  tents and Emerald's Trainer Hill on Route 111 are retired (owner S-04,
  S-05; D-030, D-044); HnS's copies at Route 40 stay. Round 2 was rebased
  onto the owner's map commits for this and checked again with the new
  ids.
- **Round 4** gives every item of the game a regular source (D-059, owner
  2026-11-03): the 21 TMs of HnS's old Kanto at its places on the FRLG
  maps (shops, item balls, trainers after their rematch, Brock after the
  Kanto title), the other items without a source in shops, as finds or
  from people (Bill's grandfather after the Kanto title, the Catching
  Charm, EXP. Charm and Pokemon Box Link), Hoenn's missing hidden items
  and the Kampfzone's Battle Point lists. Scott's gift counts the 11
  meetings that are left and waits for the Hoenn title (O-073). Held items
  of wild Pokemon count for now; the 20 items that come only by luck wait
  for the owner (O-078). No change to the save layout (44 flags, one var).
- **Nothing was played.** Every fix is checked statically or by tool; the
  emulator test of the three test steps (play A to Z, balancing, reach
  everything), of the story packages and of rounds 2 to 4 (list below)
  is still to do.
- So the build fits a **closed beta in German** (the owner's plan: German
  first, English during the beta; release planned for Sunday 2026-11-15)
  with testers who use the beta build
  (debug menus on); the debug menu's "Johto Test" and "Hoenn Test" (D-050)
  start at the Johto and the Hoenn chapter. It is **not ready for an open
  beta or a release** until the owner has read the draft texts and own
  translations (text round), decided the open questions below, and an
  emulator playthrough has been done.

## Beta criteria

| # | Criterion | Verdict | Evidence |
|---:|---|---|---|
| 1 | Build is reproducible | met (build from scratch of `851aa886e2`) | 2026-11-03, round 4: `make -j2` of the code tip `851aa886e2` in a new worktree compiles all 398 C files, exit 0, ROM SHA-1 `8fe887d805f3db1d350df34391a5d4488830873c`, the same as the incremental build of the per-commit run; 15 of 15 commits of round 4 built with their final ids (`make` ok, `check_flags` 0, `percommit_r4`). Rounds 2 and 3: `make` of `61ac7e277d` after removing `build/jade` compiles all 398 C files, exit 0, ROM SHA-1 `6346a2591693e2c99c3f1748b676d0f207afdbef`, the same as the incremental build of the integration run (`integ_r23`). Every commit after the owner's `ad4a8db368` was built with its final id: 73 of 73 (62 of round 2, 5 documentation, 6 of round 3; `make` ok, `check_flags` 0, both debug headers up to date, `percommit_r23`). Before the rebase round 2 had been built the same way on `2f284d83b9` (`percommit_r2`, `r2derest_final`; ROM `9d8271bc…` at the rest tip, without the owner's map commits); round 3 also on its package branch. Earlier states: `b022af5623` `11bec7d4cba038d647668f2f86c68ef3a29eee1f` (also from scratch), `b62f22e381` `5c1c08ae7685bf6073ea20c7f87df981d6488c2a`. Toolchain arm-none-eabi-gcc 13.2.1. |
| 2 | Release build, debug menus off | met (statically, `851aa886e2`) | Round 4: `make release` of `851aa886e2`, 2026-11-03: exit 0, SHA-1 `a4bb57818d0471f0d805d680541a76d1214f969e`, 111 warnings as before; the debug menu, the debug states and "Even Wild Slots" are not in the release ELF (they are in the beta ELF). Rounds 2 and 3: `make release` of `61ac7e277d`, 2026-11-03: exit 0, SHA-1 `10174fe5187327f5e3cb4bcfe39d7392bb493031`, 111 warnings as before (N-build_tools-4). The overworld debug menu (`Debug_ShowMainMenu`), the debug states (`Debug_SetJohtoTestState`, `Debug_SetHoennTestState`, D-050) and the switch "Even Wild Slots" (`gDebugEvenWildSlots`, D-055) are not in the release ELF (they are in the beta ELF); the battle debug menu's only trigger (Select, `src/battle_controller_player.c`) is compiled out. The sprite visualizer has no caller in the HnS summary screen and is linked in neither build. The release ROM was not started. Earlier: round 2 before the rebase `18eedc2ebb50f9165aaf65ade559a1281e9bd625`, `b022af5623` `34e173bde2dc2b804e1132a60a5675f928dd33b4`. |
| 3 | No known blocker on the story path Kanto -> Johto title | met (by tool) | `simulate_progress.py` on `851aa886e2` (round 4): Kanto title in wave 50, GS Ball 51, Johto badges 55-91, Johto title 105; `--diff` against the round before its review fixes: no milestone, stop, map, item ball, hidden item, trainer or gift changed. On `61ac7e277d` (`integ_r23`): Kanto title in wave 50, GS Ball 51, Johto badges 55-91, Johto title 105; no stop on the main path, the same waves as on round 2 and on `b022af5623`. `check_maps.py`: 0 findings from "important" up, 88 minor (1125 active maps by its count, see criterion 4; base: 3 critical, 10 important). The two critical findings of the owner's map work (the Trainer Hill entrance's warps to the removed Route 111 warp) are gone with round 3. Base: the simulator stopped in Kanto at the Celadon Game Corner (A01). Story traps A02, A03, A13, A57, A102 and the deep review's state bugs are fixed in the source (statically). |
| 4 | No known blocker on the story path Johto -> Hoenn title | met (by tool) | Round 4 (`851aa886e2`): Hoenn Ticket in wave 106, Hoenn reached in 108, Hoenn badges 109-127, Hoenn title 137, exit 0; 195 of 1115 active maps unreachable, as before. D-047: the first Johto title sets `VAR_HOENN_TICKET_STATE` 1, Troy hands over the Hoenn Ticket in Oak's lab, both ports sail to Hoenn; since round 2 "Hoenn" stays in the menus until "Graphitport City" can be offered (O-032), so no player is cut off from Hoenn. `simulate_progress.py` without `--hoenn-ticket` on `61ac7e277d` (`integ_r23`): Hoenn Ticket in wave 106, Hoenn reached in 108, Hoenn badges 109-127, Hoenn title 137, exit 0; the Contest Pass now in wave 112 (Verdanturf, before 121 in Lilycove). Unreachable active maps: 195 of 1115 (1125 before round 3: 16 retired, 6 new), all off the story path (Alola, Sinjoh, event islands, secret bases, facility rooms, unused maps). The simulator and `check_maps.py` count active maps differently: the simulator takes every map folder of the build without the 13 link maps (Union Room, Trade Center, Battle Colosseum, Record Corner), `check_maps.py` (1125 in criterion 3, 1135 before round 3) the maps listed in `map_groups.json` with the link maps, which leaves out 3 unused houses; with round 3 both lose the same 16 retired maps and gain the same 6 new ones. None of the scenes ran in an emulator. |
| 5 | Saves are safe | met (statically), with risks | Round 4 (`851aa886e2`): `check_budget.py` SaveBlock1 15868/15872, SaveBlock2 3892/3968, SaveBlock3 1584/1624, PokemonStorage 34144/35712, as before (EWRAM 95.28 %, ROM 77.19 %); 44 flags and one var more in free ids, layout unchanged; `check_save_safety.py` 76 findings (1 important, 3 minor, 72 optional) as before, after the tool learnt that the Mach and Acro Bike are never held together: 61 different key items, at most 60 at a time, for 60 slots (D-059). Rounds 2 and 3: `check_budget.py` on `61ac7e277d`: every save block within its flash space (SaveBlock1 15868/15872, SaveBlock2 3892/3968, SaveBlock3 1584/1624 with 40 free since the Day Cares of Kanto and Johto, D-052, PokemonStorage 34144/35712). `STATIC_ASSERT`s pin the layout; `test/save.c` (4 tests) passes. `check_save_safety.py` on the documentation tip: no blocker or critical finding; 1 important (no running clock, mitigated by `5e1b5f870d`, which the tool does not model), 3 minor (one is a false alarm on the Hall of Fame size, two concern the item randomizer's bag pockets), 72 optional, as before rounds 2 and 3; the Key Items pocket holds 58 obtainable key items in 60 slots. New games clear the Nuzlocke area flags. Round 2 changes the layout (SaveBlock3 +576 bytes for two Day Cares); round 3 adds four flags and keeps the layout (the retired Route 111 hill's records stay in SaveBlock3, unused). Saving and loading never ran in an emulator; old saves are out of scope (owner decision). |
| 6 | No English text on the story path | met (by tool, owner reading open) | Round 4 (`851aa886e2`): `check_game_text.py --english`: Hoenn 0, Johto 23, Kanto 5, shared 97, `src` 11, locked 290, retired 3, the same as before round 4; every new line of round 4 has a German branch (Bill's grandfather's texts, English only in HnS, are new German texts; Brock's line after the Kanto title is new). `check_game_text.py --english` on `61ac7e277d` (`integ_r23`): Hoenn 0, Johto 23 and Kanto 5 (trainer names in upstream capitals that no active script shows, O-066), shared 97 (83 debug texts and 14 battle tent texts marked unused), `src` 11 (5 debug, 4 unused union room texts, 2 credits names); the locked Sinjoh and Alola maps 290, the retired maps 3. Round 2 before round 3: Hoenn 2 (two unreferenced texts in the corridor of Emerald's Slateport tent, German since they moved into Slateport's contest hall, O-065); before round 2: Johto 125, shared 252, Hoenn 7, Kanto 5. Every active map text without a German branch was also read by hand (D-057). The translations that are not from an official German game and the new lines of round 3 (Scott in Slateport, O-070; the Route 121 Safari Zone desk) are drafts for the owner's text round. |
| 7 | Text fits the message box (208 px) | not met (minor) | Round 4 (`851aa886e2`): `check_text_width.py --list`: 35 exact lines over 208 px (Johto 28, Kanto 1, locked 6), as before; the new lines of round 4 at most 208 px (Brock's new line 162 px). `check_text_width.py --list` on the ROM of `61ac7e277d` (`integ_r23`): 35 exact lines over 208 px (Johto 28, Kanto 1, locked maps 6), the same as before rounds 2 and 3; none over the 216 px window outside locked maps. The new German lines of rounds 2 and 3 are at most 208 px (PokeCom lines at most 192 px). 364 lines with placeholders are estimates. |
| 8 | Static checks green | met | On `851aa886e2` (round 4): `check_flags.py` 0 problems (3479 flags, 696 vars: 44 flags and one var more than round 3), also at each of the 15 commits; `check_merge.py` 0 errors (8 known, 205 warnings, 273 hints); `check_maps.py` 88 minor, nothing from "important" up; `check_regions.py` 0 problems; `make_debug_states.py --check`: both headers up to date (from `6f39278fee` on, which regenerates them for the round's new items); `check_warnings.py` 105 warnings on the log of the build from scratch, as in the baseline (release 111, as before). On `61ac7e277d` (`integ_r23`): `check_flags.py` 0 problems (3435 flags, 695 vars: the four flags of round 3 more), also at each of the 73 commits (`percommit_r23`); `check_merge.py` 0 errors (8 known with a reason, 205 warnings and 273 hints as in the baseline); `check_maps.py` 0 findings from "important" up (88 minor); `check_regions.py` 0 problems (known exceptions listed, Jirachi on Route 4 among them); `make_debug_states.py --check`: both debug headers up to date, also at each of the 73 commits; `check_budget.py` exit 0. `check_warnings.py` on the log of the build from scratch: 105 warnings, as in the baseline. |
| 9 | Test suite without new failures | met (regression check) | Round 4 (`851aa886e2`, `tests_r4`): 5148 tests in 951 files, 2355 ok, 629 todo, 2164 failures, all known, 0 new, 0 changed; Origin Jade tests level scaling 11/11, flag/var routing 7/7, save sizes 4/4, region rule 14/14, debug states 3/3, Day Cares 2/2, even wild slots 2/2, region badges 1/1 (no test covers the new item sources). `tools/run_tests.py` on `61ac7e277d` (`tests_r23`): 5148 tests in 951 files, 2355 ok, 629 todo, 2164 failures, all known, 0 new, 0 changed (the same on round 2 before the rebase; on `b022af5623`: 5140 tests). Origin Jade tests: level scaling 11/11, flag/var routing 7/7, save sizes 4/4, region rule 14/14, debug states 3/3, Day Cares 2/2, even wild slots 2/2, region badges 1/1. Limit: about 2100 upstream tests cannot check anything because battle texts are German, and 24 failures are not triaged (A32, `N-tests-1`); no test covers the contests. |
| 10 | Every Pokedex species obtainable without trading | met (by tool) | Round 4 changes no wild table, trainer party or Pokemon gift; `check_regions.py` 0 problems on `851aa886e2`. Items (D-059): the audit's item check finds none of the 903 items of the build without a regular source; 20 come only by luck (O-078), 335 are not meant (listed in D-059). The catch list generated on round 2 before the rebase (`make_fangliste.py`, outside the repository): after Kanto all 151 Kanto species (with evolutions), after Johto all 129 Johto species (with breeding), after Hoenn all 422 species with evolutions and breeding (300 caught or received directly); nothing missing at any stage. Jirachi has a source again: Route 4 after the first trip to Hoenn (S-12, A69). The owner's map commits and round 3 change no wild table, trainer party or Pokemon gift; `check_regions.py` on `61ac7e277d` finds no wild table, overworld Pokemon, gift or static battle of a later region. |
| 11 | Played through in an emulator | **not met** | No emulator test. The checklists for the three test steps are in the audit's test matrix; "Emulator test list" and "What was not verified" below name what to test first and the gaps. |
| 12 | Owner decisions taken | **not met** | Most points were answered on 2026-10-31, 2026-11-02 and 2026-11-03 and are built (rounds 2 to 4); the rest is in "Owner decisions still needed", among them the questions of round 3 (O-068 to O-070) and of round 4 (O-075 to O-078). |

## Open findings by priority

From the audit's finding list, as of the audit series: 124 of 297 findings
were open or only partly fixed (1 blocker, 0 critical, 14 important, 43
minor, 66 optional). After the 42 commits of the story packages 122 were
open or partly fixed (0 blockers, 0 critical, 14 important, 42 minor, 66
optional; fixed 128). Round 2 (62 commits and the owner's answers) was
checked against the list: it fixes 21 findings (6 important: A20,
T-hoenn_a-1 to -3, T-johto_a-2, T-johto_b-2; 9 minor; 6 optional), settles
19 by an owner decision that keeps them as they are (11 minor, 8 optional)
and N-build_tools-3 by recommendation (the owner left the technical points
X-02 to X-07 to the audit's recommendation on 2026-11-02; X-03: no mdbook
docs for the beta), takes A30 back as decided (Nuzlocke deaths in battles
with an AI partner as in HnS, D-054) and fixes N-randomizer-2 in part.
Round 3 (6 commits) settles two more by the owner's decision to retire
Emerald's Trainer Hill on Route 111 (S-05, D-044): A15 (important) and
N-facilities-2 (minor), and fixes the rest of A61: Verdanturf's and
Slateport's contest halls give TM Attract and TM Torment with Hoenn flags
of their own (O-067), and with the Emerald tents retired no Hoenn map
shares a flag with the HnS tent copies at Route 40 any more. So 78 are
open or partly fixed now: 0 blockers, 0 critical, 7 important, 20 minor,
51 optional. Fixed: 149; decided in rounds 2 and 3: 23 (22 by the owner,
1 by recommendation); no bug or refuted: 12; intended by an older
decision: 4; duplicates: 31. The own open points of rounds 2 and 3 are
owner questions (O-041 to O-074, "Owner decisions still needed").
Round 4 (15 commits) implements the owner's answers of 2026-11-03 and
fixes no finding of the list; its own open points are O-075 to O-078.

### Blocker

None open. W-progress_sim-4 / O-002 (Hoenn not reachable without the
Hoenn Ticket) is fixed by the package `ticket` (D-047):

- **Fix:** the first Johto title sets `VAR_HOENN_TICKET_STATE` 1
  (`56be2a1860`); Troy hands over the ticket in Oak's lab (`59bd5a6e39`);
  the port menus offer "Hoenn" with it from both ports (`a18797946a`); the
  ticket is a key item, so "Items: Zufall" cannot replace it
  (`84e8dc6bb5`).
- **Test status:** checked by tool (`simulate_progress.py` without
  `--hoenn-ticket` reaches the Hoenn title, wave 137); not checked in an
  emulator (see "Emulator test list").

### Critical

None open. A04 and A05 are fixed (statically checked); with D-047 they
take effect in a normal playthrough.

### Important

Fixed in round 2: A20 (fixed boss movesets, D-053), T-johto_a-2 and
T-johto_b-2 (Johto story texts, D-057), T-hoenn_a-1 to -3 (battle tents,
move tutors, Safari Zone texts, D-056). Decided in round 3: A15
(Emerald's Trainer Hill on Route 111 is retired by the owner's decision,
S-05, `61ac7e277d`, D-044; O-024 resolved). Still open:

#### A19: regional forms, Sneasler and Overqwil are missing on purpose (D-023)

- **Status:** open, owner decision case by case. The owner's answer of
  2026-10-31 (S-14): regional forms that are evolutions stay in where HnS
  does not tie the evolution to a region, the others are reported to him.
  Every case is tied to a region, so all stay off; O-045 lists them.
- **Evidence:** `P_REGIONAL_FORMS` is `FALSE`
  (`include/config/species_enabled.h`); 44 regional forms of the Gen 1-3
  families, Sneasler, Overqwil and six regional evolutions are missing.
  D-023 records this; the audit's goal list asks for them.
- **Files:** `include/config/species_enabled.h`.
- **Impact:** no malfunction; goal and decision contradict each other.
  Enabling them touches the randomizer pool, O-009, the Battle Frontier
  data and possibly saves and Pokedex flags.
- **Proposal:** the owner decides per case of O-045; if one is wanted, a
  work package of its own that checks saves, ROM size and encounters
  first.
- **Test status:** not checked (proposal).

#### A10: Origin Jade tests - partly fixed

- **Status:** partly fixed (`17cb0ed51e`, `78aa81bd8e`, `c441d676ef`;
  region rule `58e89bd76b` and follow-ups, debug states `b022af5623`;
  round 2: Day Cares `f1b7342466`, even wild slots `a1509bd992`, region
  badges `3c8ec60228`, more cases for scaling, region rule and debug
  states).
- **Evidence:** `test/origin_jade/level_scaling.c` (11 tests),
  `test/origin_jade/event_data.c` (7), `test/save.c` (4),
  `test/origin_jade/region_rule.c` (14, D-049),
  `test/origin_jade/debug_states.c` (3, D-050),
  `test/origin_jade/daycares.c` (2, D-052),
  `test/origin_jade/even_wild_slots.c` (2, D-055) and
  `test/origin_jade/region_badges.c` (1, D-053) pass. Missing: tests for
  story scripts (GS Ball handover, theater state, Troy's scenes, the port
  menus, the calls of D-051) and for save migrations.
- **Files:** `test/origin_jade/`, `src/save.c` (`LoadGameSave`).
- **Proposal:** tests for the migrations and for the region rules (D-006);
  story scripts need an emulator or a script-level test harness.
- **Test status:** checked by tool (`run_tests.py`).

#### A32: upstream battle tests expect English messages - partly fixed

- **Status:** partly fixed: the failures are in the baseline
  `test/known_failures.tsv` (`631abb6cca`), where they stay (decided
  2026-11-02 by recommendation, X-04).
- **Evidence:** 1969 "Unmatched MESSAGE" and 127 statistical failures:
  species, move and battle texts are German without a language switch, so
  `GAME_LANG=ENGLISH` does not help.
- **Files:** `test/battle/**` (about 500 files with `MESSAGE`),
  `test/known_failures.tsv`.
- **Repro:** `python3 tools/run_tests.py`; see `build/jade-test/results/`.
- **Impact:** these tests report a regression only as a changed failure;
  they cannot catch real battle regressions.
- **Proposal:** keep the list (decided, X-04); an English test build as an
  extra CI job would make them useful again.
- **Test status:** checked by tool (full test run).

#### A35: clock-dependent mechanics at runtime - partly fixed

- **Status:** partly fixed (`5e1b5f870d`: without a running cartridge
  clock the fake clock is preselected in the challenge menu).
- **Evidence:** without a working clock `RtcGetInfo` returns a fixed date
  (`src/rtc.c`), `UpdatePerDay` never runs (`src/clock.c`), the weekday is
  always Saturday. The clock type can only be chosen in a new game.
- **Files:** `src/rtc.c`, `src/clock.c`, `src/new_game.c`,
  `src/challenge_menu.c`, `src/legendaries_oj.c`, `src/weekday_oj.c`.
- **Repro:** emulator with and without RTC, change of day, both clock
  types.
- **Impact:** with the hardware clock type on a cartridge or emulator
  without a clock: no daily reset, berries do not grow, fled legendaries
  never return, weekday siblings and events stay away.
- **Proposal:** the clock matrix belongs in the beta test.
- **Test status:** checked statically; not at runtime.

#### W-text_width-1: Johto story lines of 209-213 px (12 lines)

- **Status:** open, text round (O-012).
- **Evidence:** e.g. `EcruteakCity_Theater_hns/scripts.inc:1179` and
  `:1202` (213 px), `GoldenrodCity_RadioTower_3F_hns/scripts.inc:312`
  (211), `VioletCity_Gym_hns/scripts.inc:83` Falkner's intro (210),
  `NewBarkTown_Lab_hns/scripts.inc:1273` (209).
- **Impact:** 1-5 px over the convention, inside the 216 px window; the
  last character may touch the frame.
- **Proposal:** move one word to the next line.
- **Test status:** checked by tool (`check_text_width.py`,
  `check_game_text.py`).

#### W-text_width-5: estimated over-wide shared texts (item received)

- **Status:** open, text round.
- **Evidence:** the cross-check confirmed only `gText_PlayerFoundOneItem`
  (`data/text/obtain_item.inc`, 210 px with a 7-letter name); eight other
  estimates were refuted. Low severity.
- **Proposal:** break the line before `{STR_VAR_2}`.
- **Test status:** checked by tool, cross-checked.

#### W-text_width-6: battle texts over 208 px in the worst case (220 lines)

- **Status:** open, text round.
- **Evidence:** `src/battle_message.c` with the longest prefix ("das
  gegnerische ") and a 12-letter name; A40 names a 227 px case
  (`STRINGID_PKMNMADESLEEP`) and the grammar slip "von das gegnerische".
- **Proposal:** in the text round the cases over 216 px first, break after
  the name.
- **Test status:** not checked (tool estimate).

### Minor

| Id | Area | Finding | Status | What is open / proposal | Test status |
|---|---|---|---|---|---|
| A66 | shared | Overworld Pokemon show species that cannot be caught on their map | partly fixed | Routes 26/27 fixed (`8167ea7bc6`); the others need an owner decision | by tool (map data vs. wild tables) |
| A69 | shared | Jirachi has no source (only a retired map) | fixed | HnS's event on Route 4 by the Mt. Moon Pokemon Center, after the first trip to Hoenn (owner S-12, `4c8c287df6`, D-037) | by tool (`check_regions.py`, catch list) |
| N-challenge-3* | shared | Pokemon Center challenge blocks only the nurse, Mom, the S.S. Aqua bed and the Dojo; 59 maps with `HealPlayerParty` still heal | fixed | as in HnS: nurses, Mom and every bed that heals (S.S. Aqua, S.S. Tidal, Weather Institute) are blocked, story heals and people who let the player rest stay (D-054) | static |
| N-challenge-4* | shared | Hardcore Nuzlocke deletes the save also after a faint from poison in the field | decided | kept, as in HnS (D-054) | static |
| N-nuzlocke-1* | shared | With "Feste PKMN: Zufall" the received message of Kanto gifts names the original species | open | buffer the species after randomizing | static |
| N-nuzlocke-3* | shared | Nuzlocke deaths do not count in the Trainer Hills (O-028) | decided | kept exempt, as in HnS; O-028 resolved (D-054, D-045) | static |
| N-randomizer-1* | shared | Item randomizer: follow-up dialogs name the original item (e.g. Brock and TM39) | decided | kept, as in HnS (D-054) | static |
| N-randomizer-2* | shared | Item randomizer: trades (Berry Powder, glass workshop, Mom's savings, lottery) give other items | partly fixed | as in HnS, exchange menus give the chosen item (`giveitem_norandom`; D-023, D-054); Mom's savings and the lotteries stay randomized; Slateport's Berry Powder man waits for the owner's map (O-057) | static |
| N-w3_nuzlocke-2* | shared | `Common_EventScript_PartyIsFull` ends without `release` although Bill, the Elder, Kenya and Shuckie called `lock` | open | check for a freeze in the game; add `release` | not checked |
| T-legend_endgame-6 | shared | Challenge "Keine EVs" ends at Red, before Hoenn | fixed | ends with the Nuzlocke at the first Hoenn title, as HnS ends both at its credits (D-054) | static |
| W-core_save-3 | shared | With the item randomizer the Items pocket (up to 307 items, 236 slots) and Berries pocket (68, 66 slots) can fill up | open | limit the whitelist or secure gifts (W-core_save-4) | not checked (tool suspicion) |
| W-text_width-16 | shared | More English map texts: Moomoo twins, Route 34 Day Care, Slateport Battle Tent | fixed | German branches (D-057); the HnS tent lobby at Route 40 has 3 shown texts and 2 of an unused script, all German (`a3cbf5b4c2`, `04009d06e5`) | by tool (`check_game_text.py --english`) |
| W-text_width-17 | shared | English shared text files: `battle_tent.inc`, `safari_zone.inc`, `move_tutors.inc`, event tickets, Mixmeister | fixed | German branches from the German Emerald where it has the text (D-056); the 16 tent texts marked unused stay English | by tool |
| W-text_width-18 | shared | English source texts in visible windows: Safari gate help board, fisher choice, trade board | fixed | German branches (D-056) | by tool |
| W-text_width-2 | shared | 15 side-text lines of 209-212 px | text round | move a word | by tool |
| W-text_width-3 | shared | Berry Powder exchange line 227 px with a long item name | partly fixed | Cerulean City rewrapped (`08e3149815`); the same text in `SlateportCity/scripts.inc:1749` unchanged | by tool |
| W-text_width-7 | shared | Other estimated over-wide lines with placeholders | text round | measure with real values | not checked (tool estimate) |
| W-text_width-8 | shared | Four source text lines over 208 px in windows of their own | text round | window widths not measured | not checked (tool estimate) |
| A61 | Hoenn | Johto flags change Hoenn dialogs (D-040 leaks outside its list) | fixed | Wally's father, Rock Smash man, fossil maniac, Safari Zone, Strength have Hoenn flags; Lilycove has its own daily lottery ticket since round 2 (owner S-03, `43354ff84b`); since round 3 Verdanturf's contest girl gives TM Attract and Slateport's sailor TM Torment with Hoenn flags of their own, and the old TM flags and Scott's tent flags belong to the HnS tent copies at Route 40 alone, since the Emerald tents are retired (O-067, `d969de7b0b`, `ebc78f0ec9`, `c0a6f90aba`). Scott's two tent meetings went with the tents (O-073, owner question) | static |
| A63 | Hoenn | Battle Frontier offered from Hoenn only after an S.S. Tidal trip (`FLAG_MET_SCOTT_ON_SS_TIDAL`), not in D-030 | decided | kept, in D-030; Scott's call after the first Hoenn title points to the ship (owner S-02, D-051) | static |
| A67 | Hoenn | Hoenn families need evolution items sold only in Kanto/Johto | fixed | Mauville's mart and Lilycove 2F sell the stones, Lilycove also Reaper Cloth, Deep Sea Tooth and Scale (owner S-10, `dc016bbc28`, D-037) | static |
| A68 | Hoenn | Prism Scale has no source | decided | no Prism Scale; Milotic through beauty as in Gen 3 (owner S-11, D-037) | static |
| N-facilities-2* | Hoenn | Emerald Trainer Hill maps do not set `FLAG_TEMP_HIDE_FOLLOWER` (HnS maps do) | decided | the Emerald hill is retired (owner S-05, `61ac7e277d`, D-044); nothing to check | static |
| N-w3_hoenn-2* | Hoenn | Wally's, Scott's (two) and Roxanne's calls count steps in Johto and Kanto too | fixed | the calls count steps only on Hoenn maps, like Norman's call; the rival's call after the Space Center too (D-051, owner S-07) | static |
| A54 | Johto | Suicune sighting on Route 42 in a pocket behind a Cut tree | owner | move the trigger, add a hint, or record it in D-038 | static |
| A75 | Johto | A caught legendary (level 75) lifts the Johto anchor to 67 or more | decided | kept: legendaries in the party count for the anchor (D-039, D-053) | static |
| N-balance-1* | Johto | Four Johto trainers with fewer than 3 Pokemon (Marc, Rich, Shirley, Zuki) | fixed | filled up to three Pokemon (D-053) | by tool (audit script) |
| N-johto_story-1* | Johto | Celebi is no longer caught with the GS Ball (key item, not throwable); level 75, normal balls | decided | stays: no guaranteed catch, as in the original (owner S-09) | static |
| N-johto_story-2* | Johto | The theater's Mystic Water is lost with a full bag (`giveitem` without a space check) | open | `checkitemspace` (see W-core_save-4) | static |
| N-nuzlocke-2* | Johto | Route 41: Pokemon that faint in the unwinnable level-100 Tentacruel guard battle die | decided | kept, as in HnS (same battle at the same spot; D-054) | static |
| W-moveset_sim-3 | Johto | Ariana 1 (Rocket Hideout B2F) has 6 Pokemon; the double battle shows only the first 3 | decided | kept as scripted (D-053) | by tool (moveset simulation) |
| A48 | Kanto | TM27 (Return) is lost behind the retired Route 12 north gatehouse | owner | move the girl, drop TM27 in Kanto, or keep; then `EXCLUDED_MAPS` in `tools/make_debug_states.py` | by tool (`check_maps`, `simulate_progress`) |
| A50 | Kanto | `Route22_hns` is active but cannot be entered (O-022) | partly fixed | O-022 documented (`b4a8ab9ce9`); retire or connect (owner) | by tool (`check_maps`) |
| A74 | Kanto | Kanto ladder: 53 under-levelled evolutions (e.g. Dragonite 46/47, Tyranitar 47) | decided | kept (D-011, D-053) | static |
| A78 | Kanto | No move reminder in Kanto (chapter 1) | decided | Kanto stays without one, as HnS's Kanto (owner, D-054) | static |
| A37 | technical | GitHub Actions never ran | partly fixed | Jade workflow committed (`c64f0a28dd`), since `bb850c8d7c` and `0ab7449520` also with `check_regions.py` and the check of both debug states; Actions on (decided 2026-11-02 by recommendation, X-02): the owner only has to flip the switch; the test job is a placeholder | static (workflow never ran) |
| A38 | technical | Save and RAM budget almost used up (SaveBlock1 4 bytes free, EWRAM 95 %) | partly fixed | `tools/check_budget.py`, D-017; more reserve before the save freeze (see A89) | by tool (`check_budget`) |
| A40 | technical | Width tests in `test/text.c`: German overflows and the grammar slip "von das gegnerische" | text round | the 6 width failures are in the baseline | static |
| A89 | technical | SaveBlock1 has 4 bytes left; its layout depends on `FLAGS_COUNT` | partly fixed | `STATIC_ASSERT`s, D-016/D-017; `FLAGS_COUNT`/`VARS_COUNT` are pinned with a reserve before the save freeze (decided 2026-11-02 by recommendation, X-07) | by tool (build with asserts, `check_budget`) |
| A94 | technical | `test/text.c` fails on German Z-move names | partly fixed | in the baseline, where they stay (decided 2026-11-02 by recommendation, X-05); the real over-wide texts go to the text round | by tool (`run_tests`) |
| N-kanto_maps-3* | technical | Older HnS imports: Johto and Hoenn layouts not checked for Origin Jade tiles reverted by a merge | open | three-way check as in `425eb2fbb1` | not checked |
| N-tests-1* | technical | 24 test failures not triaged (bag sorting, Sheer Force, Day Care regional forms, Alolan Raticate form table, ...) | open | triage; some may be real bugs | by tool (`run_tests`) |

### Optional

| Id | Area | Finding | Status | Note |
|---|---|---|---|---|
| A109 | shared | Mamoswine practically needs the move reminder (Ancient Power) | open | comfort proposal; the condition can be met |
| A111 | shared | 147 active trainer Pokemon with moves they cannot learn (9 bosses confirmed, W-moveset_sim-2) | fixed | all trainers cleaned, 244 moves (D-053) |
| A113 | shared | Low IVs of Johto/Hoenn bosses for their scaled level (see O-023) | decided | boss IVs stay as in HnS (D-053) |
| N-balance-4* | shared | Partner OT name cut to "Siegfri" (7 characters), only in the summary | open | |
| N-challenge-1* | shared | Escape formula: `u8 speedVar` in `TryRunFromBattle` overflows after 5-6 tries (upstream) | open | |
| N-randomizer-3* | shared | With "Starter: Zufall" Oak's confirmation names the original species (the received message is right) | fixed | Oak, Elm and Birch name the shown species (D-023, D-054) |
| N-randomizer-4* | shared | "Starter: Zufall" only affects the Kanto starter; Elm and Birch give the original (D-023) | fixed | every lab starter, as HnS randomizes its starter (D-054) |
| N-randomizer-5* | shared | The item randomizer menu line does not mention fossils and evolution items | owner | text |
| N-randomizer-6* | shared | Scripted double wild battles are never randomized | open | whether an active map uses them is not checked |
| N-w3_nuzlocke-1* | shared | The new nickname question also appears without Nuzlocke (Johto starter and Goldenrod prizes in the PC, Bill's Eevee, the Dragon's Den Dratini) | owner | HnS asks nothing there; proposal keep (O-055) |
| W-core_save-4 | shared | 72 gift and trade scripts without a space check (71 in the tool report; Wallace's HM Waterfall is new) | open | secure the story-relevant ones (fossils, Bug-Catching Contest, Exp. Share, Metal Coat) with `checkitemspace` |
| W-core_save-5 | shared | Key items pocket: 2 slots reserve (58 of 60 since the Hoenn Ticket became a key item, `84e8dc6bb5`) | open | a rule in D-017 |
| W-core_save-6 | shared | Link features (Cable Club, Union Room, ...) reachable in the Jade build | decided | they stay (owner 2026-11-02: Union Room, Wireless Club, Direct Corner, Cable Club, link contests); test them with two emulators |
| W-progress_sim-14 | shared | Birth Island (HnS): warp 0 to the port lies in the wall | open | dead warp; the sailor replaces it |
| W-progress_sim-16 | shared | Orphaned active maps (nothing leads there) | owner | retire (D-018/D-019) or keep |
| A107 | Hoenn | Dead and write-only Hoenn data | open | clean-up (D-018/D-019) |
| A112 | Hoenn | May and Wally are no bosses (+1), unlike Silver and Blue | fixed | May and Wally are bosses (D-053) |
| A114 | Hoenn | Hoenn corridor floors are very hard for story rushers (+9 to +12 levels from Winona on) | decided | kept hard (D-053) |
| N-hoenn-1* | Hoenn | Dead Jade branches after A05/A58 (Birch and May at the lab, the Dad scene) | partly fixed | the father scenes are no longer built (`40102c8756`, `fe370081c1`, D-048); the hidden family objects are removed (O-030, D-048); left: the unreachable branch with Birch and May at the lab |
| N-hoenn-2* | Hoenn | The heading of D-040 names only Kanto | open | cosmetic |
| N-pokemon-1* | Hoenn | Medicham appears in the Battle Pyramid; dead test gift at the Safari gate | open | |
| N-randomizer-7* | Hoenn | Item randomizer swaps Shoal Salt and Shoal Shells; the Shell Bell can become unreachable | open | |
| N-w3_hoenn-1* | Hoenn | Wallace gives nothing if HM Waterfall is already in the bag | decided | no substitute (owner S-06, D-014) |
| N-w3_hoenn-3* | Hoenn | Wallace's text says the badge is needed to teach the HM; in Jade it is the permit | owner | text |
| T-hoenn_a-12 | Hoenn | Emerald player room leftovers in Norman's and Birch's house (D-002) | partly fixed | PC and decorations are the son's and May's (`ea9a0f7287`); Mom's Amulet Coin script and her scene after the wall clock are no longer built (`40102c8756`, `d38acf1988`); room decorations are set up in Pallet Town (O-029, D-048); the hidden objects of Mom and Dad are removed (O-030, D-048); left: notebook and wall clock |
| T-hoenn_b-4 | Hoenn | Steven in Meteor Falls stays at level 75-78, about 20 below the Hoenn post-game (D-031 vs. D-043) | fixed | Troy and Red: six Pokemon at level 100 (D-053) |
| T-legend_endgame-3 | Hoenn | Weather Institute 1F and the sailor judge Kyogre/Groudon differently for up to 3 days | open | |
| W-progress_sim-17 | Hoenn | Dead script code from design decisions (e.g. Brendan's teams, D-003) | partly fixed | Brendan's Go-Goggles handover in Lavaridge Town is no longer built (`fe370081c1`, D-048); the rest is clean-up |
| A105 | Johto | Dead states, never-set flags and test warps in Johto (New Bark Town 4-7, Ecruteak City 4/5/14) | owner | |
| A110 | Johto | League ceiling 65: Elite Four, Silver and Lance equally strong | fixed | league rooms rise from Will to Lance (D-012, D-053) |
| N-johto_story-3* | Johto | The Wailmer Pail does not wake the Battle Frontier Sudowoodo (only the SquirtBottle does) | open | |
| N-johto_story-4* | Johto | The new gate text has an English `#else` branch for non-German builds | decided | English branches stay, so the language can be chosen (owner, text group) |
| N-w3_nuzlocke-3* | Johto | Johto starter: the nickname question in the Nuzlocke branch has no YES/NO | open | works |
| N-w3_nuzlocke-4* | Johto | Dead code in the Goldenrod Game Corner prize room | open | |
| T-johto_b-5 | Johto | Kimono Girls' dance repeats until the legendary battle | partly fixed | once per visit (`b702b50666`); after a map change or whiteout it restarts as in HnS |
| T-johto_b-6 | Johto | Route 40 Trainer Hill courtyard open before the Johto title | owner | bind to `FLAG_IS_JOHTO_CHAMPION` or keep |
| T-johto_b-7 | Johto | Johto Safari Zone: west extension locked, Baoba's quest dead (P-004) | open | builder texts English |
| T-legend_endgame-4 | Johto | "... flew away!" after knocking out Deoxys | partly fixed | Lugia and Ho-Oh fixed (`ffe4fc5792`); Deoxys on Birth Island still shows it; the island is reached with the Aurora Ticket from Olivine City, since `d0f6521cf6` only after the first Hoenn trip |
| W-map_checker-11 | Johto | Route 41: the Tentacruel barrier (D-026) blocks nothing | owner | move it in front of an island entrance or drop it |
| W-map_checker-13 | Johto | Battle Frontier Pokemon Center: stairs to 1F outside the map (HnS) | open | no change recommended |
| W-text_width-9 | Johto | Help window `HELP_GAMESTART_WINDOW` 226/221 px | text round | probably never shown |
| A103 | Kanto | Dead Sevii branches in active Kanto scripts | open | clean-up (D-019) |
| A108 | Kanto | Bloodmoon Ursaluna can be obtained (Peat Block at night in Mt. Moon) | decided | stays as in HnS (owner S-13, D-023) |
| N-build_tools-1* | Kanto | Orphaned or locked maps in the `KNOWN_ERRORS` of `check_merge.py` | owner | retiring them changes the ROM |
| N-kanto_maps-1* | Kanto | Pallet Town: walkable door tiles without a warp (HnS tileset) | owner | |
| N-w3_kanto-1* | Kanto | Berry Powder only via the link Berry Blender; alone the exchange stays at 0 | owner | a neutral line needs owner text |
| N-w3_kanto-2* | Kanto | Cinnabar Lab: after revivals in the Ruins of Alph the farewell may be the no-fossil line | open | cosmetic |
| T-kanto_a-10 | Kanto | Oak's aides count only numbers 1-151 (randomizer) | open | proposal |
| T-kanto_a-11 | Kanto | Self-warp left on Route 2 (warp 10) | open | harmless |
| T-kanto_a-8 | Kanto | Cerulean City house 2 (burglary) has no entrance and wrong exits | owner | retire or restore the entrance |
| T-kanto_b-3 | Kanto | Fuchsia City: a girl still calls Koga the gym leader | owner | needs new story text |
| T-kanto_b-7 | Kanto | Saffron City station sign all in capitals (D-020) | text round | |
| W-core_save-8 | Kanto | Kanto title: Oak's plateau scene only after saving | partly fixed | a restart after the Hall of Fame save wakes the player in the room (`93ae559803`); Oak's line on the plateau is missed if the player switches off before the scene ends; no softlock |
| W-map_checker-12 | Kanto | S.S. Anne deck active but without access; its hidden Lava Cookie is lost | owner | move or give up |
| A121 | technical | Hall of Fame entries carry no region | decided | all regions hold 50 teams (`cd155adc3d`); one list without a region, as in HnS (D-054) |
| N-build_tools-2* | technical | Leftovers of removed build targets (`make compare` checks Emerald's `rom.sha1`, `make debug` writes the same file name, `docs/tutorials/how_to_frlg.md` names `make firered`) | open | |
| N-build_tools-3* | technical | CI docs check removed (`DECISIONS.md` not in `docs/SUMMARY.md`) | decided | no mdbook docs for the beta (2026-11-02 by recommendation, X-03) |
| N-build_tools-4* | technical | The release build (LTO) has 6 warnings more than the baseline; the warning check covers the normal build only | open | confirmed 2026-10-31: 111 vs. 105, also on `b022af5623` |
| N-build_tools-5* | technical | `make GAME_VERSION=EMERALD` on the command line still overrides the fixed version | open | |
| N-tests-2* | technical | 16 ball tests INVALID (HnS balls need a party index in the runner) | open | small runner exception possible |
| N-tests-3* | technical | 6 spread move damage tests fail on `B_MULTIPLE_TARGETS_DMG GEN_3` (HnS) | decided | Gen 3 rule kept as in HnS (D-053) |
| N-tests-4* | technical | `make check`: the hydra runner buffers without a limit | open | `run_tests.py` is not affected |
| W-core_save-7 | technical | Save migrations run on every `LoadGameSave` | open | harmless today; run them only for `SAVE_NORMAL` with status OK |
| W-map_checker-17 | technical | Unreached maps: intended or not modelled | open | maybe mark them retired in D-018/D-019 |
| W-progress_sim-18 | technical | Battle Frontier, Pyramid, contests and secret bases not modelled | open | check in the emulator |
| W-progress_sim-19 | technical | Other model-limit hits | open | probably model artefacts |

## Owner decisions still needed

The owner answered most open points on 2026-10-31, 2026-11-02 and
2026-11-03; rounds 2 to 4 built the answers (D-051 to D-059). Still open:

**Story and content**
- Text round: the owner reads every German text he did not write: the
  drafts of the story packages (Oak's and Troy's scenes, the port texts,
  the ticket description, the Hoenn texts of D-048, Mom's calls; Troy's
  "Ich erwarte dich in Hoenn!" where the owner's outline said "dort") and
  the own translations of round 2 where no official German text exists
  (D-056, D-057: among them the Headbutt tutor, the Blend Master, the
  Pokeblock help windows, Mahogany Town, the Radio Tower's top floor, the
  Goldenrod Underground, the Safari Zone gate), and the new lines of
  round 3: Scott in Slateport (O-070) and the last sentence of the Route
  121 Safari Zone desk, which names Slateport's contest hall. Lilycove's
  hall sign says "Pokémon Wettbewerb" as the German Ruby and Sapphire,
  the three new signs "Pokémon Wettbewerbe"; the owner may make them
  alike. Also the position of "¥"
  in money texts (D-057), Mom's heal texts after a whiteout at home
  (O-037), placeholder National Pokedex ratings (O-038), old text defects
  (O-040) and the line widths (O-012).
- Continue point after a title in front of the bedroom stairs (O-041):
  keep (9,3), or the spot next to the bed with a PC that refuses dolls
  that would box the player in.
- Region rule: the Johto Pokedex counts as complete without Azurill and
  Wynaut (to confirm). Decided 2026-11-02: the Pokedex evolution page
  keeps showing later species, as a help (O-034).
- Contests (D-058, built in round 3): the rank per hall (O-068: built as
  in Ruby and Sapphire, Verdanturf Normal and Fallarbor Super; the
  owner's note names them the other way round), paintings per rank
  (O-069: today each new lobby shows the newest winner of any rank;
  proposal keep) and Scott's new line when he leaves Slateport's hall
  (O-070: keep the scene, as proposed, or drop it). Scott's two tent
  meetings are gone with the Emerald tents; Scott is not needed for the
  story (owner 2026-11-03), and his gift counts the 11 meetings that are
  left and waits for the Hoenn title (O-073 resolved in round 4, D-030).
  The tents and the Route 111 Trainer Hill are retired (P-006 done;
  O-024, O-063, O-065, O-067 resolved).
- Trainer names in upstream capitals (O-066), when Sinjoh is unlocked or a
  team is reused.
- Route 41: the Tentacruel barrier blocks nothing (W-map_checker-11); its
  Nuzlocke deaths stay as in HnS (N-nuzlocke-2, D-054).
- Maps without access: Cerulean City house 2 (T-kanto_a-8), TM27 on
  Route 12 (A48), `Route22_hns` (A50, O-022), S.S. Anne deck
  (W-map_checker-12), orphaned maps (W-progress_sim-16), test warps
  (A105), Pallet Town door tiles (N-kanto_maps-1).
- Suicune sighting on Route 42 (A54), Route 40 hill courtyard before the
  title (T-johto_b-6), Fuchsia girl and Koga (T-kanto_b-3), Berry Powder
  only by link (N-w3_kanto-1).
- Owner text for the Petalburg gym boy after beating Wally in Mauville
  first (T-hoenn_a-4), for Clair in state 3 (T-johto_b-1) and for a
  Nuzlocke whiteout without a living Pokemon (A79).

**Balance**
- Decided 2026-11-02 (D-053): boss movesets (A20), unlearnable trainer
  moves (A111), league ladder (A110), May and Wally (A112), Troy and Red
  (T-hoenn_b-4), the four small Johto teams (N-balance-1); kept: A74,
  A75, A113, A114, W-moveset_sim-3, N-tests-3. Open: the catch malus
  levels in Johto and Hoenn (O-050).

**Pokemon and items**
- Answered 2026-10-31/11-02: evolution items in Hoenn's marts (A67,
  built), Prism Scale (A68: none, Milotic through beauty), Jirachi (A69:
  Route 4), Bloodmoon Ursaluna (A108: as in HnS), Celebi and the GS Ball
  (N-johto_story-1: as in the original), mythicals do not count for the
  Pokedex (D-036), Sinjoh and Alola stay locked (O-009).
- Answered 2026-11-03 and built in round 4 (D-059): every item can be
  obtained, the 21 TMs of HnS's old Kanto first (O-074).
- Still open: regional forms case by case (A19, O-045); overworld Pokemon
  that cannot be caught (A66); the Battle Point items in the Hoenn Test
  (O-060). Round 4: the Catching Charm, EXP. Charm and Pokemon Box Link,
  which HnS never gave (O-075, proposal keep); the prices of the new goods
  (berries 20, Battle Point prices) and the items of HnS's Kanto that now
  come in chapter one (TM Giga Impact for 3000, TM Flash Cannon on Route
  9, Pewter Crunchies; Brock's TM Rock Slide waits for the Kanto title)
  (O-076); Bottle Caps without Hyper Training (O-077, proposal keep them
  out); the 20 items that come only by luck, five of them at HnS's old
  places (O-078, proposal: fixed sources for those five).

**Challenges**
- Confirm the Nuzlocke end at the first Hoenn title (O-025; O-055 notes
  that HnS has the same rule at its credits).
- Settled as in HnS (D-054, owner 2026-11-02): Trainer Hills (O-028),
  "Keine EVs" end point (T-legend_endgame-6), Pokemon Center challenge
  scope (N-challenge-3), hardcore after field faints (N-challenge-4),
  randomizer texts, trades and starters (N-randomizer-1 to -4), battles
  with an AI partner.
- Still open: Nuzlocke rules that differ from HnS, among them the nickname
  question without Nuzlocke (O-055, N-w3_nuzlocke-1); move tutors in Kanto
  (O-056); item randomizer leftovers (O-057); randomizer species pool
  (O-058); randomizer menu line (N-randomizer-5).

**Hoenn details**
- Wallace's text names the badge, in Jade it is the permit
  (N-w3_hoenn-3); the wording of Scott's call after the first Hoenn title,
  Emerald's text kept as the hint to the S.S. Tidal (S-02, D-051).

**Technical**
- Decided 2026-11-02: link features stay (W-core_save-6, then test them),
  English `#else` branches stay (N-johto_story-4); move reminder in Kanto
  (A78) and Hall of Fame without a region (A121) as in HnS (D-054).
- Decided 2026-11-02 by recommendation (the owner left X-02 to X-07 to
  the audit): GitHub Actions on, the owner only flips the switch (A37,
  X-02); no mdbook docs for the beta (N-build_tools-3, X-03); the MESSAGE
  tests (A32, X-04) and the `test/text.c` failures (A94, X-05) stay in the
  baseline; the storage assert of `GetFlagPointer`/`GetVarPointer` on in
  the beta build, off in `make release` (A96, X-06, still to build); pin
  `FLAGS_COUNT`/`VARS_COUNT` with a reserve before the save freeze (A89,
  X-07).
- Still the owner's: retiring the maps without access listed in
  `check_merge.py` (N-build_tools-1, K-07 of the Porymap checklist); the
  shared tiles of his tileset commit `ad4a8db368` (the Route 111 desert
  tower entrance he fixes in Porymap; whether the 37 pixels that lost
  their transparency are restored from the original tiles, see "Risks").

**Decisions taken during the audit, to be confirmed**
- The Nuzlocke ends at the first Hoenn title (A23); a shiny first
  encounter and battles without a chance to catch use up no area (A83,
  A25).
- Later ship trips to Hoenn do not reset Hoenn (A04, D-029); where they
  dock follows the owner's port rules of 2026-10-31 (D-047).
- Kanto level caps follow the level ladder (A28); battle partners scale
  like opponents (A21).
- Meditite and Medicham are wild in Hoenn (A16).
- The GS Ball is a key item (A02); Emerald's Trainer Hill on Route 111 was
  made to work instead of being retired (A15; on 2026-11-02 the owner
  decided that it goes, retired in round 3, D-044).
- English trainer names in Johto took the German names of the first tier
  or of the Kanto/Hoenn version; the Cerulean badge explainer names the
  limits by badge count; the Victory Road Potion moved to (44,11); the
  radio quiz only raises Goldenrod's state; the Route 40 hill pays the
  prize money only with the prize.
- Mints with "Natur-Minzen: Aus" are sold from the first Hoenn title on
  (A85); the HM fallback works with every species randomizer (A119); the
  Origin Jade map edits on Routes 10, 17 and 19 lost in the HnS merge are
  restored (`425eb2fbb1`, can be dropped on its own); Wallace gives HM
  Waterfall if it is missing (T-hoenn_b-3; confirmed with S-06: nothing
  if it is there); Elm recognizes the hatched
  Violet City egg also with the randomizer and in the PC (T-johto_a-5);
  after the Farfetch'd search the charcoal master keeps his Team Rocket
  text, also after Kurt's GS Ball scene (T-johto_a-1);
  Johto rematch tiers are filled up to three Pokemon (A72); the places of
  the wild starters (A17); the theater gives Mystic Water to a player who
  kept HM Surf from Kanto (A13); the Kimono Girls' dance runs once per
  visit (T-johto_b-5).

Open questions that stay open in `DECISIONS.md`: O-012 (partly), O-022,
O-025, O-037, O-038, O-040, O-041, O-045, O-050, O-055 to O-058, O-060,
O-066, from round 3 O-068 to O-070 and, new in round 4, O-075 to O-078.
Resolved by the owner's answers of round 2: O-009, O-020, O-021, O-023,
O-028 to O-036 and O-039 (earlier: O-002 by D-047); by round 3: O-024,
O-063, O-065 and O-067; by round 4: O-073 and O-074. The O- numbers
missing in this range were reserved by work packages and not used
(round 3: O-071 and O-072); they are never assigned later. Planned
items: P-001 to P-004 (P-005 and P-006 are done).

## Emulator test list

The story packages (D-047 to D-050), round 2 (D-051 to D-057), round 3
(D-058) and round 4 (D-059) were checked statically, with the simulator
and with the C tests; none of their scenes ran. Test these first, in the
beta build (the debug states reach them quickly; "Even Wild Slots"
shortens the search for wild Pokemon).

### Story packages (and their changes in round 2)

1. **Johto Hall of Fame** at the first Johto title: after the record Oak
   and "???" (Troy) come in from the door, Troy talks only to Oak and
   leaves, Oak asks the player to come to his lab. No scene at a title
   defence. Troy keeps Emerald's sprite next to HnS's Oak and Lance
   (O-031, D-047).
2. **Waking up in the room** after the Kanto title, every Johto title and
   Red, also after a restart once the Hall of Fame has saved, in front of
   the stairs at (9,3) (O-041); a whiteout from there leads to Mom
   downstairs (her texts: O-037). Dolls and cushions placed at the bedroom
   PC are still there after leaving the room and after a title (O-029,
   D-048); a new game starts next to the bed. Elm's call after
   the first Johto title comes on the first step out of the house in
   Pallet Town (O-036, D-051), not again in New Bark Town.
3. **Oak's lab, Troy's scene:** from the door the player walks up to Oak
   and Troy; the scene in place when the player stands below Oak; the
   ticket handover and Troy leaving, stepping aside if the player is in
   his way. Bag-full branch (Key Items pocket full, in practice only with
   the debug menu): Troy stays, Oak points to him, Troy hands over the
   ticket when talked to after the player made room.
4. **Port menus and the one-way ticket:** Vermilion City before the M.S.
   Aqua's maiden voyage (note and only the Hoenn entries), Olivine City
   before it ("Orania City" and the Hoenn entries) and after it, the
   sailors at the Kampfzone and on Birth Island, the menu height with all
   entries. "Hoenn" stays until "Graphitport City" replaces it (after a
   visit; during the submarine scene "Hoenn" is back instead); Birch's
   greeting at the Route 104 pier only after the first trip, later
   "Hoenn" trips land there without an event (O-032, D-047);
   "Seegrasulb City" is added after a visit; landing in both harbours
   and the respawn there; Fly to Littleroot Town; the ticket stays in
   the Key Items pocket.
5. **Pokedex before and after Johto and Hoenn:** in Kanto the list has no
   jump into a later block, also after the Elite Four and Blue rematches;
   Johto species register from the first Johto map (not in the gatehouse),
   Hoenn species of Johto rematches and Janine only after the first
   crossing; Oak calls the Kanto Pokedex complete with all 151 but Mew;
   the evolution page shows later species too, as decided (O-034).
6. **Day Care eggs:** in Kanto Pikachu, Chansey, Snorlax or the parent's
   Hitmon instead of the baby, in Johto Marill and Wobbuffet instead of
   Azurill and Wynaut; babies once their region is unlocked; the old
   behaviour with any randomizer option (O-033).
7. **Morty's team:** the first Ecruteak City gym battle has two Misdreavus
   (levels 24 and 25) and no Duskull; rematches unchanged.
8. **Cerulean Cave:** Ditto in Wobbuffet's old slots on 1F, 2F and B1F,
   and the overworld Pokemon on 2F shows Ditto.
9. **Aurora Ticket timing:** the woman in Olivine City gives it only after
   the first trip to Hoenn and says her first line before.
10. **Diplomas:** Celadon City's game designer (all 151 but Mew) names the
    Kanto Pokedex, Lilycove City's the Johto Pokedex (without Azurill and
    Wynaut), both the National Pokedex once it is complete; the nurse's
    Gold Card greeting with the trainer card's four stars (O-039).
11. **Debug states:** "Johto Test" and "Hoenn Test" on a new game before
    the first Pokemon: team, PC (75 and 136 Pokemon, all usable), Pokedex
    185 and 282, waking up in the room or starting at the door of Oak's
    lab with Troy's scene, then on to Hoenn; the challenge settings stay
    as chosen.
12. **Hoenn texts of D-048:** "Birk sagt immer…", May, Birch's son, the
    Elite Four, Scott's call, Norman's PokeNav call after his defeat, the
    Petalburg townspeople after the gym opened, Mom's calls in each region.
13. **Hoenn calls only in Hoenn (D-051):** with a call of Wally, Roxanne,
    Scott or the rival still to come, fly to Kanto or Johto: it does not
    ring there and comes after a few steps outdoors back in Hoenn; Mom's,
    Elm's and the Johto trainers' calls ring as before. After the first
    Hoenn title Scott calls in Littleroot Town (S.S. Tidal); whoever meets
    him on board first does not get the call any more.

### Round 2 (owner answers of 2026-10-31 and 2026-11-02)

14. **Ship menus without a flyer (O-032, D-047):** after Birch's welcome,
    back in Kanto or Johto without a flying Pokemon (Nuzlocke): the ports
    and the island sailors still offer "Hoenn" until Slateport City was
    visited; then "Graphitport City" replaces it; between Groudon's
    awakening in the Magma Hideout and Team Aqua's submarine scene
    "Hoenn" is back; every later "Hoenn" trip lands at the Route 104 pier
    without Birch's greeting (see also step 4).
15. **Bedroom decorations and the continue point (O-029, O-041, D-048):**
    place dolls and cushions at the bedroom PC, also around the bed and
    three dolls around (6,6); leave the room, come back, win a title and
    restart: the decorations are there, the game continues at (9,3) in
    front of the stairs and the player can always reach the stairs and the
    PC; a new game starts next to the bed. Nothing appears in the New Bark
    Town house or in Littleroot Town.
16. **Elm's call in Pallet Town (O-036, D-051):** after the first Johto
    title the first step out of the house rings Elm's call; later in New
    Bark Town it does not ring again, and his lab speaks of the M.S. Aqua.
17. **Hoenn calls and Scott's hint (S-07, S-02, D-051):** step 13.
18. **Hoenn's lottery (S-03, D-040):** draw in Lilycove's department store
    and in Goldenrod's Radio Tower on the same day: both draw, with
    different numbers; a prize not collected waits in its own region; the
    next day both reset (also with the fake clock).
19. **Hoenn marts (S-10, D-037):** Mauville's mart sells Water, Leaf, Moon,
    Thunder, Shiny and Dawn Stone; the left clerk on Lilycove's 2F the same
    and Reaper Cloth, Deep Sea Tooth and Deep Sea Scale; prices and the
    evolutions they enable.
20. **Jirachi on Route 4 (S-12, D-026):** at night, after the first trip to
    Hoenn, the small white rock by the Mt. Moon Pokemon Center (7,4): the
    camera scene, Jirachi below the ledge at (5,9), level 80; before the
    Hoenn trip and by day the rock does nothing; after a catch or a
    knockout Jirachi follows the legendary rules; the hidden Persim Berry
    at (5,5) can still be found.
21. **Separate Day Cares (S-16, D-052):** leave Pokemon in Kanto's (Route
    5), Johto's (Route 34) and Hoenn's (Route 117) Day Care: each shows
    only its own; eggs come in the Day Care of their region after steps
    anywhere; only Hoenn's egg puts Route 117's man at the fence; the Oval
    Charm at each; saving and loading with all three in use; a new game
    (new save layout).
22. **Bills PC (S-16, D-052):** the PC menu, the access message and the
    messages after a catch, a gift or naming with a full party say "Bills
    PC" from the start, also in Hoenn and after Lanette on Route 114.
23. **Region rule with the randomizer (O-033, D-049):** with only "Trainer:
    Zufall" or only "Items: Zufall" a Day Care egg hatches as the baby
    before its region is unlocked and trainers fill the Pokedex at once;
    with only a modifier (chaos, similar strength) the rule holds (see
    step 6).
24. **Stars (O-039, D-049):** the nurse's Gold Card greeting at four
    trainer card stars and the Frontier Pass colour, before and after Red
    (see step 10).
25. **Boss movesets (B-01, B-02, D-053):** gym leaders, Elite Four,
    rivals, Rocket and Magma/Aqua leaders at their scaled levels in all
    three regions use the fixed sets; in Ariana's 2-vs-2, Tate and Liza,
    Maxie with Tabitha and Hoenn's double rematches no boss hits its
    partner; Kanto's league rematches after the title; no trainer uses a
    move its species cannot learn.
26. **Johto league ladder (B-05, D-053):** Will to Lance rise (average
    team about 62, 63, 64, 65, 67); after the title the ceilings are 100;
    Victory Road keeps 58-65.
27. **Troy and Red (B-10, D-053):** Troy at Meteor Falls and Red on Mt.
    Silver field six Pokemon at level 100 with their sets, also against a
    weak team (not scaled).
28. **Badge counters per region (B-08, B-06, B-12, D-053):** Johto phone
    rematches from three Johto badges, Hoenn trainers' battle requests from
    five Hoenn badges, the continue window shows the badges of the region
    the game was saved in, the challenge's trainer IVs and EVs follow the
    region's badges; the catch malus: Raikou, Entei and Celebi before the
    eighth Johto badge are harder to catch, wild Pokemon of a corridor
    never (O-050). May and Wally get +1 on the ace; the four filled Johto
    teams.
29. **HnS alignment (D-054):** "Keine EVs" ends at the first Hoenn title
    (no EV gain or EV items before, both after); the Pokemon Center
    challenge blocks the beds of the S.S. Tidal (the voyage still ends)
    and of the Weather Institute; the item randomizer's exchange menus
    give the item chosen (Cerulean's Berry Powder man, Route 113's Glass
    Workshop, Route 124's treasure hunter also with a full bag, Captain
    Stern's Scanner); "Starter: Zufall" at Oak's, Elm's and Birch's labs
    (preview, question, received Pokemon); in the Nuzlocke a Pokemon that
    faints next to Lance or Troy stays at 0 HP and dies after the next
    battle unless it is healed first.
30. **Debug toggle "Even Wild Slots" (D-055):** on and off in "Flags &
    Vars": land, water, each rod, Rock Smash and Headbutt trees come up
    about equally; off after a reset; not in the release build.
31. **Debug states with all items (O-035, D-050):** "Johto Test" (187
    items) and "Hoenn Test" (297): one of every purchase and repeatable
    item, the mints only with the mints option, nothing in the PC's item
    storage today; selling and tossing work.
32. **German texts (D-056, D-057):** play the story path in the German
    build and look for English: Mahogany Town and Elm's Radio Tower call,
    the Radio Tower's top floor, the Underground switches, the Safari
    Zone gate, Union Cave, the Moomoo barn, the move tutors, the Safari
    Zone texts in all three zones, the battle tents at Route 40, Pokeblock
    names and flavours, the Lilycove ladies, the Cycling Road and the Fan
    Club; the five money texts with "¥" (Route 32, Moomoo Farm, Route 4
    Pokemon Center, Pewter mart, Route 34 Day Care) end correctly; new
    lines fit their boxes and windows.

### Round 3 (contests as in Ruby and Sapphire, D-058)

33. **Verdanturf, Normal Rank:** without a Contest Pass the receptionist
    offers one, then enter the Normal Rank; info and exit; the girl's TM
    Attract (once, with her own flag); the link Berry Blender and the one
    with the old man, who gives a Pecha Berry once a day to a player
    without berries; the picture frame.
34. **Fallarbor, Super Rank:** without a Normal Rank ribbon of the
    category the entry is refused (cancel in the party menu); with one,
    enter and win; the sketch artist's line after the win; the reporter in
    the lobby on return.
35. **Slateport, Hyper Rank:** the little girl gives the Pokeblock Case,
    not twice and not to a player who has Baoba's; the blender with the old
    man and the boy; the sailor in the audience hall gives TM Torment;
    after the museum scene Scott comes out of the hall with his new line,
    and the meeting counts for his Battle Points (O-070).
36. **Lilycove, Master Rank:** only the Master Rank; the link counter asks
    for the Contest Pass; no Pokeblock Case at the counter, the girl in the
    lobby gives her Pokeblock tip; the contest artist after a Master Rank
    win; a Master Rank win with a Pokemon that already holds that ribbon
    gives a Luxury Ball, which with a full bag waits at the counter of any
    hall.
37. **After each contest** the player comes back to the lobby of the hall
    that held it (also the counter-flap walk to the door); save and reload
    in a lobby while the reporter is there.
38. **Audience halls:** the door top left in each new lobby, the stage and
    its sign, the people's texts, the mats back to the lobby.
39. **Towns:** the hall signs name the rank (Lilycove the Master Rank);
    in Verdanturf the camper, the old man in the Pokemon Center and the
    old lady in the mart, in Slateport the boy, the man by the market and
    the girl in the house near it (asks for the Contest Pass) speak of
    contests; the Route 121 Safari Zone desk without a case names
    Slateport's hall, Johto's Safari Zone gate keeps "the boy over there".
40. **Retired:** no door leads into the old tents or onto Emerald's hill
    on Route 111; the Hoenn map of the PokeNav shows no Trainer Hill on
    Route 111, also after a visit to the hill by Route 40; the HnS tent
    copies at Route 40 with their TM girl (TM Safeguard) and without Scott
    (O-073).
41. **Owner's tileset commit `ad4a8db368`:** look at the tiles it shares
    with other maps (see "Risks"): the desert tower entrance on Route 111,
    the Trick House roof on Route 110, Mauville, Route 118 and Slateport;
    note what looks wrong.

### Round 4 (every item can be obtained, D-059)

42. **Kanto shops and finds:** Celadon 2F sells the six new TMs (Giga
    Impact for 3000 next to Hyper Beam for 10000), 4F Poke Toy, Dream Mail
    and Strange Souvenir, 5F X Sp. Def and the six feathers, Pewter's mart
    Pewter Crunchies; the eight new TM balls (Routes 6, 9, 10, 11, 19,
    Rock Tunnel B1F, Celadon City, Viridian Forest) and the Fairy Feather
    in Mt. Moon 1F can be reached on foot and vanish for good; the seven
    hidden items (Vermilion, Cerulean City and Cave, Routes 8 and 15,
    Mt. Moon B2F) can be found with the Dowsing Machine.
43. **Kanto people:** Brock gives TM Rock Slide only after the Kanto
    title, with his new line, and once; before the title only TM Rock
    Tomb with the badge. Robert, Benny and Grace give their TM after their
    Kanto-title rematch team is beaten; Carter gives TM Thunder Wave after
    a won VS Seeker rematch, not after a lost one; Rick in Viridian Forest
    after the title. The man in the Underground Path takes a Rage Candy
    Bar for TM Explosion (full TM pocket: nothing is taken); the Black
    Belt in Celadon's roof room by day and by night.
44. **Bill's house and Celadon's designer:** Bill's grandfather only
    greets before the Kanto title; after it the four Pokemon in turn
    (Ponyta or Rapidash; a wrong Pokemon or "no" keeps the step), 1, 3, 5
    and 7 EXP. Candies L. Bill gives the Pokemon Box Link once after the
    title, and the box can be opened with it everywhere (also in a
    Nuzlocke run). The Catching Charm comes with the Kanto diploma.
45. **Johto and Lilycove:** Goldenrod's new goods and the berry seller in
    the flower shop (the berries can be planted); TM Rock Climb in Mt.
    Silver's item room, the Icy Rock in Ice Path 1F, the hidden finds in
    Ilex Forest and Ecruteak City. Lilycove's game designer: EXP. Charm
    with the Johto diploma; with the National Pokedex in the same visit
    the Shiny Charm follows without a second button press on read text;
    the diploma shows after both.
46. **Hoenn and the Kampfzone:** the hidden items in Route 111's desert,
    the Fiery Path, Route 119, outside the Sky Pillar and the seven relics
    in the dive pockets of Routes 124, 126 and 128. The third hold item
    clerk and the longer lists in the Kampfzone (and the vitamin counter
    of the Trainer Hill courtyard, which shares the vitamin list). Scott
    in his house before the Hoenn title: only his remarks (and the symbol
    and shield prizes), no welcome and no Battle Points; after the title
    the welcome and 4 Battle Points with all 11 meetings.
47. **Options and debug states:** the units line of the options menu in
    both settings; the Johto Test without the rewards after the Kanto
    title (Brock's TM80, the rematch TMs, Rick's TM81, the Box Link, the
    grandfather's candy), the Hoenn Test with them.

## Risks

- **No playtest.** Scenes with movement scripts, puzzles (Silph Co.
  teleporters, Seafoam currents, Victory Road boulders, Rocket spin tiles,
  Ice Path, Dragon's Den), battles that can be lost, time of day and luck
  are only modelled or read. Fixes of story state (theater, Azalea, Clair,
  Celebi, Hoenn arrival), the scenes of the story packages (Hall of
  Fame, Oak's lab, port menus), of round 2 (calls, decorations, the
  Jirachi event, the Day Cares) and of round 3 (the contest flow of Ruby
  and Sapphire on Emerald's contest engine: reception, rank checks, the
  way back to the right lobby, the reporter, the blenders) are checked
  statically; no test covers the contests.
- **Owner's tileset commit:** `ad4a8db368` (the hall buildings) also
  changes metatiles and tiles that other maps share: the entrance of the
  desert tower on Route 111 (metatiles 988 and 996 lose their dark
  opening; the owner fixes it later in Porymap), a few pixels of the
  Trick House roof on Route 110 (the owner keeps them), 1-3 pixels in
  Mauville and on Route 118, and 21 pixels of the `mauville` and 16 of
  the `slateport` tileset that are no longer transparent (palette index 0
  overwritten). A repair from the original tiles is offered to the owner;
  until he decides, step 41 of the emulator list checks these places by
  eye.
- **Save space is almost used up:** SaveBlock1 has 4 bytes left,
  SaveBlock3 40 since the Day Cares of round 2 (D-052), EWRAM is at 95 %.
  13 more Hoenn flags move the vars; more than 60 break the build (D-017).
  New save data needs the SaveBlock1 reserves of D-017 or a layout
  decision.
- **Saves:** until the release the layout may still grow (D-017), and old
  saves are not migrated; beta testers may have to start over.
- **Test suite:** about 2100 upstream tests check nothing because of
  German texts; 24 failures are not triaged, some may be real bugs.
- **Clock:** without a running cartridge clock the fake clock is
  preselected now; the clock matrix was never run.
- **Randomizer:** with "Items: Zufall" the Items and Berries pockets can
  fill up, and gifts without a space check are then lost.
- **Integration:** the wave-1 commits were built one by one on their
  package branches, not again after integration (new ids); the integrated
  tips were built. The 42 commits after the audit series were built one by
  one with their final ids. Round 2 was rebased onto the owner's map work
  for P-006 (`06ea236bdb`, `ad4a8db368`) without conflicts; with round 3
  every one of the 73 commits after `ad4a8db368` was built again with its
  final id, and the tip was also built from scratch and as a release
  build. If `balancing` moves on before the series is applied, the ids
  change again and the checks have to run again.
- **Texts:** the German texts of round 2 that are not from an official
  German game are own translations, round 3 has two new lines (Scott
  in Slateport, the Route 121 Safari Zone desk) and round 4 new texts for
  Bill's grandfather (English only in HnS), Brock's line after the Kanto
  title, Bill's Pokemon Box Link and the two designers' charms; until the
  owner's text round they may read unlike his texts.
- **Key pocket full:** 61 different key items have a source for 60 slots;
  since the Mach and Acro Bike are never held together, at most 60 fit at
  a time, three of them only by link or Mystery Gift (D-059). A further
  key item needs a slot freed the same way or a larger pocket.
- **Balance of the new items:** the items of HnS's old Kanto came after
  the Johto League there; some now come in chapter one (TM Giga Impact,
  TM Flash Cannon, Pewter Crunchies), and the Kampfzone sells EXP.
  Candies and Mochi for Battle Points (O-076).
- **CI** never ran on GitHub; the release build has 6 more warnings than
  the baseline the CI checks (LTO and newlib stubs).
- **Link features** are reachable and untested.

## What was not verified

- Any play in an emulator or on hardware: story scenes, puzzle dungeons,
  menus, battles at runtime, graphics, sound, saving and loading. The
  release ROM was built and inspected, not started.
- The scenes and rules of the story packages and of rounds 2 and 3 at
  runtime (the list above); the debug states only ran in
  `test/origin_jade/debug_states.c` on a fresh save, the Day Cares only in
  `test/origin_jade/daycares.c`, never in the game.
- The checklists of the three test steps (play A to Z, balancing, reach
  everything) of the audit's test matrix.
- The clock at runtime: change of day, weekdays, berries, the fake clock
  preselection.
- Link features (Union Room, trades, Cable Club, Mystery Gift); they
  need two emulators.
- Battle Frontier, Battle Pyramid, the HnS battle tents at Route 40,
  contests (the new halls of D-058 among them), secret bases and the
  Trainer Hill by Route 40 at runtime; the simulator does not model them.
- Randomizer, Nuzlocke and challenge options at runtime: seeds,
  distribution, whiteouts, deaths, nicknames, level caps.
- Balancing in the game; all expected levels come from a model of an
  average player, the boss movesets of D-053 were chosen from data, not
  played.
- Texts with placeholders (364 estimated over-wide lines) and texts in
  windows of their own (Pokedex, menus).
- Old saves (out of scope), locked content (Sinjoh, Alola, POSTOBC),
  builds with other switches, other toolchains, stack depth.
- The Pokedex area display against the wild tables (D-037).
- A visual check of the changed maps in Porymap (a checklist for the owner
  exists outside the repository).
- The CI workflow on GitHub.
- The 24 untriaged test failures; `make check` in one hydra run.
