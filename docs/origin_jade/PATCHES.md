# Origin Jade - patch series of the audit round

This file describes the patch series of the audit round of 2026-10-30/31,
of the story packages that followed it on 2026-10-31 and of round 2 on
2026-11-02 (the owner's answers of 2026-10-31 and 2026-11-02): how it was
made, which commits depend on each other, how each commit was verified
and how to apply it. What changed for players is in
`docs/origin_jade/CHANGELOG.md`, what is still open in
`docs/origin_jade/BETA_READINESS.md`.

- **Range:** `3525d22e71..b022af5623`, 192 commits: the audit series (144),
  its 6 documentation commits, then the story packages, the fixes after
  their text check and the debug states (42). Another 6 documentation
  commits follow on top, 198 in all, up to `2f284d83b9`. The owner
  approved them, and `balancing` was fast-forwarded to `2f284d83b9` on
  2026-10-31. Round 2 sits on `2f284d83b9`: `2f284d83b9..ae42426ece`, 62
  commits (the seven packages of the owner's answers, 58, and four German
  rest commits), and 5 documentation commits on top (this file is one of
  them), 265 in all. Nothing of round 2 is committed on `balancing` before
  the owner's approval. Since 2026-11-02 `balancing` also has the owner's
  map commits `06ea236bdb` and `ad4a8db368` on `2f284d83b9` (see "How to
  apply").
- **Commit ids:** the ids (shas) of commits 1-198 are those of the
  integration branch `audit`, now also on `balancing`. The ids of round 2
  are those of the integration branch `runde2` (commits 199-256), of the
  branch `r2-derest` on top of it (257-260) and of `r2-docs` on top of
  that (261-265). Applying the series with `git am` or a rebase gives new
  ids; the content stays the same.
- **Author and committer** of every commit: xMyDayyy. Commit messages are
  German and describe the change, the files and the effect.
- **Finding ids** in the list below: `A01`-`A122` from the audit's
  inventory, `T-<cluster>-<n>` from the line-by-line deep review,
  `W-<tool>-<n>` from the tool runs, `N-<package>-<n>` from the open points
  of the waves. Their evidence lives in the audit reports, outside the
  repository; `BETA_READINESS.md` repeats the open ones with their
  evidence. The story packages implement the owner's requirements of
  2026-10-31 instead of findings: `owner <n>` is point n of those
  requirements, `plan <id>` an item of the implementation plan's short
  list (A0-D2) that the owner approved with them, `text check` a finding
  of the text check of the story packages. Round 2 implements the owner's
  answers of 2026-10-31 and 2026-11-02: `S-`, `B-` and `N-` are the
  points of his answer list (story and Hoenn, balance, Nuzlocke,
  challenges and randomizer), `O-` the open questions of `DECISIONS.md` he
  answered, `beta: German` his beta plan (the beta comes out in German
  first, so everything that is not German gets a German branch); finding
  ids are added where a commit closes one.

## How the series was made

1. **Inventory.** An audit of `3525d22e71` in 13 phases (story per region,
   systems, data, saves, build and tests) produced the findings `A01`-`A122`
   with evidence, severity and a proposal each.
2. **Wave 1 (83 commits).** Eleven fix packages, each in its own branch
   and worktree (`wp-<package>`) from `3525d22e71`: `kanto_maps`,
   `johto_story`, `hoenn`, `facilities`, `pokemon`, `balance`, `nuzlocke`,
   `randomizer`, `challenge`, `build_tools`, `tests`. Every package was
   reviewed; the review fixes were folded into the commits they belong to
   (autosquash), and every commit was built and checked on its own. After
   the owner decisions of 2026-10-30 the package `starters` (all nine
   starters wild) and one commit for the debug menus were added. The
   packages were then integrated onto `audit` one after the other, which
   gave them new commit ids.
3. **Wave 2 (21 commits).** Small fixes without an owner decision from the
   open points of wave 1, and the map checker `tools/check_maps.py`
   (7 commits), committed on `audit`.
4. **Deep review and tool runs.** Seven clusters were read line by line and
   cross-checked; the map checker, a progress simulator, text width
   measurements, a boss moveset simulation and a core/save review ran on
   the integrated state. They produced the `T-` and `W-` findings.
5. **Wave 3 (40 commits).** Fix packages `w3_hoenn`, `w3_kanto`,
   `w3_johto`, `w3_nuzlocke` and `w3b` (Hall of Fame, clock) for those
   findings, and three tools (`check_game_text`, `check_save_safety`,
   `simulate_progress` with `oj_world`). Each package was reviewed and
   fixed up before integration.
6. **Documentation (6 commits).** D-017 budget numbers, this file,
   `CHANGELOG.md`, `BETA_READINESS.md`, `TESTS.md` and `README.md`.
7. **Story packages (35 commits).** The owner's requirements of 2026-10-31
   (Hoenn Ticket story instead of the debug ticket, Hoenn without a father,
   Pokemon per region) became an implementation plan, which the owner
   approved with corrections. Three packages from `13e6f261fd`, each in
   its own worktree: `ticket` (D-047, resolves O-002), `norman` (D-048),
   `regions` (D-049). Each was reviewed, the review fixes were folded in,
   and the packages were integrated onto `audit` one after the other
   (new ids).
8. **Fixes after the text check (3 commits).** A text check of the story
   packages found three slips (`storyfix`); most of its other findings
   are open questions O-036 to O-040.
9. **Debug states (4 commits).** Package `debug` (D-050): the generator
   `tools/make_debug_states.py` and the debug menu's "Johto Test" and
   "Hoenn Test", reviewed and fixed up before integration.
10. **Documentation (6 commits).** `DECISIONS.md` (O-036 to O-040),
    `CHANGELOG.md`, `BETA_READINESS.md`, `TESTS.md`, `README.md` and this
    file for the 42 commits of steps 7 to 9. The owner approved commits 1
    to 198 on 2026-10-31.
11. **Round 2 (58 commits).** The owner's answers of 2026-10-31 and
    2026-11-02 became seven packages from `2f284d83b9`, each in its own
    worktree (`r2-<package>`): `story` (D-051), `hoenn` (D-052),
    `balance` (D-053), `hnsalign` (D-054), `debugaids` (D-055),
    `decommon` (D-056) and `demaps` (D-057). Each was reviewed, the review
    fixes were folded into their commits (autosquash), and every commit
    was built and checked on its own. The packages were then cherry-picked
    onto `runde2` one after the other (new ids); conflicts in
    `DECISIONS.md` were resolved entry by entry, those in the other
    documentation files row by row.
12. **German rest (4 commits).** The integration check of `runde2` still
    found English texts in the HnS copy of Slateport's tent lobby at the
    Route 40 Trainer Hill; package `derest` (branch `r2-derest` on
    `runde2`) translated them and corrected D-057, O-065 and O-066 (new
    O-067).
13. **Documentation (5 commits).** `DECISIONS.md` checked after the
    merge of the seven packages, `CHANGELOG.md`, `BETA_READINESS.md`,
    `TESTS.md` and this file for the 62 commits of steps 11 and 12.

Rules every commit follows: one finding (or a tight group of the same
kind) per commit; `DECISIONS.md` changes in the same commit as the
behaviour it describes; new flags and vars only in
`include/constants/flags_origin_jade.h` and `vars_origin_jade.h`, at the
next free id of their section; no save migrations (owner decision
2026-10-30: old saves are out of scope); no English game text; code
comments in English.

## Order and dependencies

Apply the series as one block in the listed order. The packages touch
mostly different files, but nearly all of them edit
`docs/origin_jade/DECISIONS.md`, so moving a commit across packages makes
the patches conflict there. Inside the series these orders are required:

- **Flag and var allocations** (next free id of their section, so the
  numbers depend on the order):
  `38cea6c78f` `FLAG_HOENN_RECEIVED_HM_SURF` (Hoenn section + 14),
  `99406ad67c` `FLAG_HOENN_RECEIVED_HM_ROCK_SMASH` and
  `FLAG_HOENN_RECEIVED_REVIVED_FOSSIL_MON` (+ 15, + 16),
  `24f9f86e81` `FLAG_HOENN_RECEIVED_HM_STRENGTH` (+ 17; it also moves the
  static assert on the last Hoenn flag in `src/event_data.c`),
  `df79e21ae3` `VAR_HOENN_SAFARI_ZONE_STATE` (`OJ_VARS_HOENN` + 18),
  `e30f4f495e` `FLAG_HATCHED_TOGEPI_EGG` (`OJ_FLAGS_JOHTO` + 15).
  `ed9d3eaf11` moves `FRLG_FLAGS_RESERVE_START` and adds check 7 of
  `tools/check_flags.py` (reserve markers).
- **DECISIONS entries.** New ids were given in integration order: D-044
  and O-024 (`0b265d9f0f`), D-045 and O-025 (`130c5adb25`), O-026 to O-028
  (`1f0a14655c`; O-026 and O-027 resolved by `321f7eb411` and
  `dbb71e3ec6`), D-046 (`dca90ec7e8`, extended by `c64f0a28dd` and
  `be6aabb11a`). D-017, D-023, D-029, D-040 and D-045 are edited by many
  commits.
- **Save layout.** `0b265d9f0f` grows SaveBlock3 from 992 to 1008 bytes
  (`trainerHillTimesHoenn` at its end). `78aa81bd8e` pins the SaveBlock3
  offsets with `STATIC_ASSERT`s and sets the sizes in `test/save.c`; it was
  written on the base and still expects 992. `c441d676ef` sets 1008 and
  pins the new field. Between these two commits the SaveBlock3 size test
  in `test/save.c` fails (the ROM builds); from `c441d676ef` on it passes.
- **Baselines.** `6586e2c42a` creates `tools/warnings_baseline.txt`,
  `000c8fd011` removes one entry. `631abb6cca` creates
  `test/known_failures.tsv`; its places are file:line, so a later commit
  that moves lines of a test file with known failures must update it.
  `2174699385` adds the S.S. Aqua entry to the `KNOWN_ERRORS` of
  `check_merge.py`, `9c984c84a9` removes it together with the data fix.
- **Build.** `dca90ec7e8` (only Origin Jade is built) comes before
  `a545d4e73a`, `c64f0a28dd` (the CI calls `make`) and `be6aabb11a`
  (`DISABLED_ON_RELEASE` relies on `make release` building Jade).
- **Shared scripts and functions.** `ee688ea031` adds
  `Common_EventScript_AskNicknameGiftPartyMon` and `...GiftBoxMon`, which
  `de88177172`, `2077bf9dbe`, `551f9a1327` and `ed568069c4` call.
  `28158c0e9d` adds `giveitem_norandom`. `93f7a7c67a` adds
  `RandomizeGiftEggMon`, which `e30f4f495e` relies on. `0b265d9f0f` adds
  `GetPrizeMoney`, which `2d84ddaa50` calls from another place. `8dede143ee` (`oj_world.py`)
  comes before `c415155a59` (the simulator imports it). The map checker
  commits `bbe30578ea` to `63ef906433`, the text tool commits
  `a81e0f6dad` to `b887df3606` and the save tool commits `9ea6ff6d2d`,
  `46be3a9de6` build on each other.
- **Same lines in the same file** (swapping them makes the patches
  conflict): `data/scripts/hoenn_arrival.inc` (`ffa85af6e0`, `84a564e935`,
  `f85a38c16f`, `638ad542b2`, `2c6403fa2d`, `63e06c1ef7`);
  `data/maps/NewBarkTown_Lab_hns/scripts.inc` (`80b60b17ac`, `4d8cf66d21`,
  `e30f4f495e`, `2077bf9dbe`); the Nuzlocke end of battle in
  `src/battle_main.c` (`1d8451f15c`, `ac46dd2994`, `d05aa4864f`,
  `321f7eb411`); `src/randomizer.c`, `src/challenge_menu.c` and
  `src/nuzlocke.c` within their packages; `src/trainer_hill.c`
  (`0b265d9f0f`, `2d84ddaa50`); `data/maps/IlexForest_hns/scripts.inc`
  (`28cbfca6b4`, `63f7024435`, `ac408421ec`); `src/field_specials.c`
  (`66c8c9114f`, `d30437a99d`, `488df2564a`); `src/save.c`, `test/save.c`
  (`78aa81bd8e`, `c441d676ef`).
- **Debug state.** `src/data/debug_kanto_complete.h` is not changed by the
  audit series; `python3 tools/make_kanto_complete.py --check` reports it
  up to date at its tip (2026-10-31). The debug package changes that:
  `0ab7449520` renames the generator to `tools/make_debug_states.py`,
  `ae3e095a3c` regenerates `debug_kanto_complete.h`, `13bf3c8cb6` adds
  `src/data/debug_johto_complete.h`. The per-commit log records the check
  of `debug_kanto_complete.h` as up to date at `0ab7449520` and
  `ae3e095a3c` and that of `debug_johto_complete.h` at `13bf3c8cb6`; at
  the tip both headers are up to date (`integ_b10`).
- **Story packages: flags, vars and DECISIONS ids.** `59bd5a6e39` adds
  `FLAG_HIDE_OAKS_LAB_TROY` (`OJ_FLAGS_KANTO` + 10) and gives
  `VAR_HOENN_TICKET_STATE` (`vars_hoenn_de.h`) its new meaning;
  `58e89bd76b` adds `FLAG_JOHTO_UNLOCKED` (`OJ_FLAGS_GLOBAL` + 0). New
  entries: D-047 (`84e8dc6bb5`, extended by every `ticket` commit), D-048
  (`d27f2c12bd`, extended by the `norman` package), D-049 (`58e89bd76b`,
  extended by the `regions` package, `26979b66fe` and `2f4f6ccede`), D-050
  (`13bf3c8cb6`); O-031 (`59bd5a6e39`), O-032 (`a18797946a`), O-029
  (`ea9a0f7287`), O-030 (`40102c8756`), O-033 (`8fcbb1acc0`), O-034
  (`f37a68c419`), O-035 (`13bf3c8cb6`), O-036 to O-040 (documentation).
  The packages reserved their O- ids before integration, so `ticket`'s
  O-031 and O-032 come before `norman`'s O-029 and O-030 in the series.
  D-002 (`ticket`, `norman`) and D-029 (`ticket`, `regions`) are edited by
  two packages each.
- **Story packages: shared code.** `GetSpeciesRegion` and
  `IsRegionUnlocked` (`58e89bd76b`, `src/region_rule_oj.c`) are used by
  `8fcbb1acc0`, `f37a68c419`, `756563f7d7` and `58f244eade`;
  `tools/check_regions.py` (`bb850c8d7c`) and the generator (`ae3e095a3c`)
  read its table of national numbers. `59bd5a6e39` hands the ticket over
  with `giveitem_norandom` (`28158c0e9d`), which `e505824673` teaches the
  simulator and `check_save_safety.py`. The debug commits `0ab7449520`,
  `ae3e095a3c`, `13bf3c8cb6` and `b022af5623` build on each other; the
  Hoenn Test needs Troy's scene (`56be2a1860`, `59bd5a6e39`) and the
  room's heal location (`93ae559803`).
- **Same lines in the same file** (story packages): the port maps
  `OlivineCity_PortInside_hns`, `VermilionCity_PortInside_Frlg`,
  `SSAqua_1F_hns` (`e8c6cc9b93`, `a18797946a`);
  `PokemonLeague_HallOfFame_hns` (`da69d2519c`, `56be2a1860`); the
  Littleroot Town house maps and `data/scripts/players_house.inc`
  (`7f3ae8b30f`, `ea9a0f7287`, `40102c8756`, `7d5e1d669e`, `d38acf1988`);
  `src/pokenav_match_call_data.c` and `data/text/match_call.inc`
  (`1c7b9f82a6`, `5a0cfc67c1`, `fd64cd265f`, `af94011ea4`);
  `src/strings.c` (`d27f2c12bd`, `7f3ae8b30f`, `68df18a8b8`);
  `src/region_rule_oj.c`, `include/region_rule_oj.h` and
  `test/origin_jade/region_rule.c` (`58e89bd76b`, `8fcbb1acc0`,
  `f37a68c419`, `756563f7d7`, `bb850c8d7c`, `58f244eade`); `src/pokedex.c`
  and `src/birch_pc.c` (`756563f7d7`, `58f244eade`);
  `tools/make_debug_states.py` and `src/debug.c` (`0ab7449520`,
  `ae3e095a3c`, `13bf3c8cb6`); `include/debug.h` (`ae3e095a3c`,
  `13bf3c8cb6`); `.github/workflows/build.yml` (`bb850c8d7c`,
  `0ab7449520`); `docs/origin_jade/TESTS.md` (ten of the 42 commits).
  `8fcbb1acc0` adds the two Day Care tests that expect a Pichu egg to
  `test/known_failures.tsv`.
- **Round 2: flags, vars and DECISIONS ids.** `ba63ca78b9` adds
  `FLAG_HOENN_PICKED_LOTO_TICKET` (Hoenn section of
  `flags_origin_jade.h` + 18) and `VAR_HOENN_POKELOT_PRIZE_ITEM` and
  `_PLACE` (`OJ_VARS_HOENN` + 19, + 20); `36a20c443a` adds
  `FLAG_CAUGHT_JIRACHI` and `FLAG_DEFEATED_JIRACHI` (+ 19, + 20) and
  `LEGENDARY_JIRACHI`. New entries: D-051 (`647a0d1054`), D-052
  (`bc06eb8f8e`), D-053 (`4cd02e34e1`), D-054 (`25d9748af9`), D-055
  (`19983480f5`), D-056 (`d6af502fa7`), D-057 (`124a45487b`); O-041
  (`15003b77fa`), O-045 (`e6120b14d0`), O-050 (`c76a60fd47`), O-055 to
  O-058 (`7899ace9a1`), O-060 (`22b6c4d130`), O-063 (`d6af502fa7`),
  O-065 and O-066 (`124a45487b`), O-067 (`ae42426ece`), P-006 (this
  documentation). The packages reserved their O- ids before integration;
  the unused ones stay unused and are never assigned later. Nearly every
  commit of round 2 edits `DECISIONS.md`, and most of them
  `BETA_READINESS.md`.
- **Round 2: save layout and debug headers.** `bc06eb8f8e` grows
  SaveBlock3 from 1008 to 1584 bytes (Kanto's and Johto's Day Cares at its
  end) and updates the asserts in `src/save.c` and the size in
  `test/save.c` in the same commit. `15003b77fa`, `bc06eb8f8e`,
  `ba9263431e` and `22b6c4d130` regenerate the debug headers
  (`src/data/debug_kanto_complete.h`, `src/data/debug_johto_complete.h`);
  the per-commit log records both headers up to date at every commit of
  `runde2`; the four rest commits do not touch their sources, and at the
  tip both are up to date.
- **Round 2: same lines in the same file:** `tools/make_debug_states.py`
  (`2366a7faef`, `15003b77fa`, `36a20c443a`, `bc06eb8f8e`, `22b6c4d130`);
  `src/data/trainers_hns.party` (`ba9263431e`, `94ef1dfa9c`,
  `525145feff`, `076468daf3`), `src/data/trainers.party` (`ba9263431e`,
  `9814c8cc06`, `076468daf3`), `src/data/trainers_frlg.party`
  (`b0516cb308`, `076468daf3`); `src/level_scaling.c` and
  `test/origin_jade/level_scaling.c` (`4cd02e34e1`, `f453e1cd12`,
  `c76a60fd47`); `src/debug.c` (`bc06eb8f8e`, `22b6c4d130`,
  `19983480f5`); `src/strings.c` (`2f7ccdd058`, `8a09804587`,
  `84105d9593`); `data/maps/Route34_DayCare_hns/scripts.inc`
  (`bc06eb8f8e`, `b310ef0fad`, `f2ff040f0c`);
  `data/scripts/hoenn_arrival.inc` (`23661ee2e3`, `2241a44b1e`);
  `src/data/heal_locations.json` (`15003b77fa`, `2241a44b1e`);
  `src/field_specials.c` (`647a0d1054`, `a44511935c`);
  `src/battle_script_commands.c` (`2f7ccdd058`, `c76a60fd47`);
  `src/challenge_menu.c` (`c76a60fd47`, `25d9748af9`); `src/party_menu.c`
  (`25d9748af9`, `84105d9593`); `data/specials.inc` (`ba63ca78b9`,
  `cd270e41d1`); `include/constants/flags_origin_jade.h` (`ba63ca78b9`,
  `36a20c443a`); `data/maps/SlateportCity_BattleTentLobby_hns/scripts.inc`
  (`a39d3e0ffa`, `6d8abd351d`).
- **Round 2: shared code.** `GetRegionBadgeCount` (`c76a60fd47`,
  `src/caps.c`) and `GetScalingCeiling` (`src/level_scaling.c`) serve the
  badge readers and the catch malus; `IsBossTrainer` (`4cd02e34e1`) and
  `JOHTO_SCALING_ROOMS` (`f453e1cd12`) come before the boss sets
  `525145feff` and `9814c8cc06`, which were chosen for the scaled levels.
  `cd270e41d1` takes back the death check of `d05aa4864f` (A30) in the
  multi battle macros. `22b6c4d130` comes before `19983480f5` in
  `src/debug.c`.

## Verification per commit

Every commit up to `b022af5623` was built (`make jade -j3` on the package
branches, `make -j2` later; both build the same Jade ROM) and checked with
`python3 tools/check_flags.py` (0 problems); for wave 1 the table says
where only a package or integration build exists. The 6 documentation
commits 193-198 change no code and were not built. Every commit of round
2 (199-260) was built with its final id; the 5 documentation commits
261-265 change no code. The logs are kept in the audit workspace, not in
the repository.

| Part | Commits | Per-commit build and `check_flags` | Logs |
|---|---:|---|---|
| Wave 1 | 83 | On the package branches before integration: every commit of 10 packages (76 commits) built and checked; `build_tools` gave a byte-identical ROM over all 10 commits. `pokemon` (2 data commits), `starters` (4) and the debug menu commit: only builds of the package or of the integration. After integration (new ids) the wave-1 commits were not rebuilt one by one; the integrated tips were (build 0, `check_flags` 0, debug header up to date). | package reports, `*_percommit*.log`, `review_*_pc_*.log`, `integ_build1.res`, `integ_build2.res`, `integ_b4.res` |
| Wave 2 | 21 | 21 of 21 `make=ok`, `check_flags` 0, with the ids of `audit` | `percommit_wave2.log` |
| Wave 3 | 40 | 40 of 40 `make=ok`, `check_flags` 0, with the ids of `audit` | `percommit_w3.log` |
| Tip `b62f22e381` | 144 | `make` 0, ROM SHA-1 `5c1c08ae7685bf6073ea20c7f87df981d6488c2a`, `check_flags` 0, `check_budget.py`, `check_text_width.py`, `make_kanto_complete.py --check`, test suite with `tools/run_tests.py`: 0 new and 0 changed failures | `integ_b8.res`, `integ_tests_b8.log` |
| Documentation | 6 | each commit: `make -j2` 0, ROM SHA-1 unchanged, `check_flags` 0 | `abschluss/work/repo_docs/` (full and release builds), `abschluss/work/crosscheck/percommit_docs.log` (per commit, final ids) |
| Story packages | 35 | 35 of 35 `make=ok`, `check_flags` 0, with the ids of `audit`; before that every commit also on its package branch after the review fixes | `percommit_story.log`; package logs |
| Story state `58f244eade` | 185 | `make` 0, ROM SHA-1 `7665d2fdd3ffbb2ef1ce2d5b6061f753f7058942`, `check_flags` 0, `check_budget.py`, `check_text_width.py`, `make_kanto_complete.py --check`, `check_regions.py` 0 problems, `check_maps.py` 88 minor, `check_merge.py` 0 errors (8 known), simulator without `--hoenn-ticket`: Hoenn title in wave 137, test suite with `tools/run_tests.py`: 5138 tests, 0 new and 0 changed failures | `integ_b9.res`, `integ_tests_b9.log` |
| Fixes and debug states | 7 | 7 of 7 `make=ok`, `check_flags` 0, with the ids of `audit`; the debug state check (before `0ab7449520` still `make_kanto_complete.py`) without a problem, the log records `debug_kanto_complete.h` up to date up to `ae3e095a3c` and `debug_johto_complete.h` from `13bf3c8cb6` on | `percommit_b10.log` |
| Tip `b022af5623` | 192 | `make` 0, ROM SHA-1 `11bec7d4cba038d647668f2f86c68ef3a29eee1f` (also after a build from scratch), `check_flags` 0, `check_budget.py`, `check_text_width.py`, `make_debug_states.py --check` (both headers up to date), `check_regions.py` 0 problems, `check_maps.py` 88 minor, `check_merge.py` 0 errors (8 known), simulator without `--hoenn-ticket`: Hoenn title in wave 137, test suite with `tools/run_tests.py`: 5140 tests, 0 new and 0 changed failures | `integ_b10.res`, `integ_tests_b10.log` |
| Documentation (2) | 6 | documentation only, not built; `check_flags` 0 | - |
| Round 2 | 58 | 58 of 58 `make=ok`, `check_flags` 0, both debug headers up to date, with the ids of `runde2`; before that every commit also on its package branch after the review fixes | `percommit_r2.log`; package logs |
| Round 2 state `124a45487b` | 256 | `make` 0, ROM SHA-1 `2c85c88afce3eb8d88bff8e265d3a955955ac0b6`, `check_flags` 0, both debug headers up to date, `check_regions.py` 0 problems, `check_text_width.py` as the baseline, `check_maps.py` 88 minor, `check_merge.py` 0 errors (8 known, 205 warnings, 273 hints), simulator without `--hoenn-ticket`: Kanto title in wave 50, Johto 105, Hoenn 137, `check_budget.py` (SaveBlock3 1584/1624), test suite with `tools/run_tests.py`: 5148 tests, 0 new and 0 changed failures | `integ_r2.res`, `integ_tests_r2.log`, `sim_r2/` |
| German rest | 4 | 4 of 4 `make=ok`, `check_flags` 0 (3431 flags, 695 vars), both debug headers up to date, with the final ids of `r2-derest`, built one by one after the autosquash; ROM SHA-1 `8a63e8ea90ba2ad4cd36c4c7215b60a208fd5e62` for `a39d3e0ffa`, `9d8271bcd2f622c5b09d2b263bd3f8b8f74aec21` from `6d8abd351d` on | `r2derest_final.log` (the versions before the autosquash: `r2derest_c*.log`) |
| Tip `ae42426ece` | 260 | in a new worktree of the documentation tip (same code): `make` from scratch 0, ROM SHA-1 `9d8271bcd2f622c5b09d2b263bd3f8b8f74aec21` (the same as the rest package's build), `make release` 0 (SHA-1 `18eedc2ebb50f9165aaf65ade559a1281e9bd625`, no debug menu), `check_warnings.py` 105 (release 111), `check_flags` 0 (3431 flags, 695 vars), `make_debug_states.py --check` (both headers up to date), `check_regions.py` 0 problems, `check_text_width.py` 35 exact lines as before, `check_game_text.py --english` (Johto 23, Kanto 5, Hoenn 2, shared 97), `check_save_safety.py` 76 findings as before, `check_budget.py` | `r2docs_build.log`, `r2docs_release.log` |
| Documentation (3) | 5 | documentation only, not built one by one (the tip build above has the same code); `check_flags` 0 | - |

On 2026-10-31 the audit tip `b62f22e381` and the tip `b022af5623` were
also built from scratch in a separate worktree (all 397 C files
compiled): each ROM has the same SHA-1 as above, and
`tools/check_warnings.py` finds 105 warnings on each full log, as many as
the baseline. `make release` of `b022af5623` gives exit 0 and SHA-1
`34e173bde2dc2b804e1132a60a5675f928dd33b4` (111 warnings, as on
`b62f22e381`; see N-build_tools-4 in `BETA_READINESS.md`).

## How to apply

Commits 1-198 are on `balancing` since 2026-10-31 (fast-forward to
`2f284d83b9`). Round 2 (commits 199-265) sits on `2f284d83b9`. Since then
the owner pushed his map work for P-006 to `balancing` (`06ea236bdb`
"Anpassungen an Karten", `ad4a8db368` "Tilesets für Änderungen
nachgeladen"), so a fast-forward that keeps the ids is no longer
possible. Round 2 goes on top of `ad4a8db368`, by rebase or with
`git am`; every commit gets a new id with the same subject and changes
(the 62 code commits apply to `ad4a8db368` without conflicts). The ids in
this file, `CHANGELOG.md`, `BETA_READINESS.md` and `TESTS.md` then have
to be matched by subject, and the per-commit builds and the checks run
again on the new ids.

**Rebase** (in the integration clone):

    git rebase --onto ad4a8db368 2f284d83b9 r2-docs

**Patches** (`git am`):

    # in the integration clone
    git format-patch 2f284d83b9..r2-docs -o patches/runde2/
    # in the target repository
    git checkout balancing        # at ad4a8db368
    git am --3way patches/runde2/*.patch

For the first round the same worked with `3525d22e71..b022af5623`
(`patches/audit/`) and the 6 doc commits on `b022af5623`
(`patches/docs2/`).

`git am` keeps author, author date and message; the committer date and so
the commit ids change. The per-package exports of the waves and of round
2 (`patches/<package>/`, `patches/r2_<package>/`) hold the versions before
integration and are not meant for applying; use the export of the whole
branch.

After applying, run:

    make -j$(nproc)
    python3 tools/check_flags.py
    python3 tools/check_regions.py
    python3 tools/make_debug_states.py --check
    python3 tools/check_budget.py
    python3 check_merge.py
    python3 tools/run_tests.py

If the target branch has new commits, also run the static tools of
`docs/origin_jade/TESTS.md` (`tools/check_maps.py`,
`tools/simulate_progress.py`, which needs no `--hoenn-ticket` any more and
ends with exit 0 only if the Hoenn title is reachable).

## Full list in order

The number is the position in the series; the title is the commit title
(German, as in git).

### Wave 1

#### `kanto_maps`: Kanto maps and warps

| # | Commit | Title | Findings |
|---:|---|---|---|
| 1 | `bf4d84843d` | Prismania City: Türen wieder auf allen Warps | A01, W-map_checker-1, W-progress_sim-1 |
| 2 | `75c85591c8` | Route 8: Torhaus nach Saffronia von Westen wieder betretbar | A12, W-map_checker-3 |
| 3 | `49aa20ab68` | Mondberg B3F: Weg zur Mew-Kammer begehbar | A11, W-map_checker-2, W-progress_sim-2 |
| 4 | `2df90d157b` | Kanto: drei Warps auf auslösbare Felder gelegt | T-kanto_a-3, T-kanto_a-4, W-map_checker-4 |
| 5 | `0124707dc7` | Lavandia: Obergeschoss des Pokémon-Centers mit dem richtigen Layout | W-map_checker-5 |
| 6 | `0dacb0557a` | Route 9: Itemball mit TM40 (Aero-Ass) erreichbar | A47, W-map_checker-5, W-progress_sim-3 |
| 7 | `6b20e81d4a` | make_kanto_complete: Pikachu-Doktor nicht mehr als fehlend gemeldet | A71 |
| 8 | `e3dcdf00eb` | Marmoria City: Laufschuh-Trigger nach Rocko nur noch einmal | A49 |
| 9 | `cbb0a9a2ca` | Safari-Zone (Kanto): Randblöcke wieder vollständig | A39, A98, W-map_checker-5 |
| 10 | `425eb2fbb1` | Route 10, 17, 19: im HnS-Merge verlorene Layout-Änderungen zurück | N-kanto_maps-2 |
| 11 | `b4a8ab9ce9` | DECISIONS: Zertrümmerer auf der Siegesstraße, Route22_hns in O-022 | A50, A104 |

#### `johto_story`: Johto story state

| # | Commit | Title | Findings |
|---:|---|---|---|
| 12 | `28cbfca6b4` | Johto: GS-Ball als Basis-Item, Celebi-Schrein verlangt ihn | A02, A52 |
| 13 | `80b60b17ac` | Johto: Theater-Zustand läuft nur noch vorwärts | A03, T-kanto_b-5 |
| 14 | `89f7c83d03` | Johto: Azalea nimmt die VM Surfer aus Kanto nicht mehr weg | A13 |
| 15 | `4d8cf66d21` | Johto: PokéCom-„Zustand“ auch, wenn Lind von links angesprochen wird | A53 |
| 16 | `35b99a0b2a` | Johto: Rote Haut geht bei vollem Beutel nicht mehr verloren | A57 |
| 17 | `ae4b56e8e8` | Torhaus: Weg nach Johto erst mit Eichs GS-Ball | A102 |
| 18 | `c16463afb7` | Kampfzone: Mogelbaum lässt sich mit der Schiggykanne wecken | A65 |
| 19 | `06befcd4c6` | DECISIONS: Strudel und Rückweg aus Neuborkia in D-008 festgehalten | A51, A106 |

#### `hoenn`: Hoenn arrival and story

| # | Commit | Title | Findings |
|---:|---|---|---|
| 20 | `ffa85af6e0` | Hoenn: Schiffsfahrten setzen die Hoenn-Story nicht mehr zurück | A04, A14 |
| 21 | `84a564e935` | Hoenn: Respawn bei der Ankunft, Birks Empfang wird nachgeholt | A64 |
| 22 | `f85a38c16f` | Hoenn: keine M.S.-Ticket-Szene in Wurzelheim nach dem Titel | A05 |
| 23 | `a242593207` | Hoenn: Birks Szene „Nationaler Modus“ nach dem Titel entfällt | A58 |
| 24 | `97954fcd88` | Hoenn: Maikes Musik auch für Spielerinnen | A60 |
| 25 | `638ad542b2` | Hoenn: Fliegen zur Pokémon-Liga in Prachtpolis City | A59 |
| 26 | `3c4a70b8d1` | Hoenn: Mädchen im Wettbewerbs-Foyer erkennt die Pokériegelbox | A62 |
| 27 | `38cea6c78f` | Hoenn: eigenes Surfer-Flag für Wallys Eltern | A55, A61 |
| 28 | `99406ad67c` | Hoenn: Zertrümmerer-Mann und Fossilmaniac mit eigenen Flags | A61 |
| 29 | `df79e21ae3` | Hoenn: Safari-Zone mit eigenem Zustand, Ausgang wieder auf Route 121 | A61 |
| 30 | `2c6403fa2d` | Hoenn: Schiffsankunft nicht mitten in Adrians Szene im Hafen | A04, A14 |

#### `facilities`: Battle Frontier and Trainer Hills

| # | Commit | Title | Findings |
|---:|---|---|---|
| 31 | `d0324da2bf` | Kampfzone und Trainerberg: keine deaktivierten Arten mehr in den Teams | A18 |
| 32 | `0b265d9f0f` | Hoenn: Trainerberg auf Route 111 mit Emerald-Trainern statt leerer Etagen | A15, A29 |

#### `pokemon`: Pokemon availability

| # | Commit | Title | Findings |
|---:|---|---|---|
| 33 | `548c6a1eb1` | Hoenn: Meditie und Meditalis wieder wild (Pyroberg, Siegesstraße) | A16 |
| 34 | `d1dfc29263` | DECISIONS: O-009 um gesperrte Inhalte mit deaktivierten Arten ergänzt | A70, A76, A117 |

#### `starters`: all starters wild (owner decision 2026-10-30)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 35 | `51b8d58b8c` | Kanto: Bisasam, Glumanda und Schiggy auch nachts mit 5 % | A17 |
| 36 | `ecf36a7f03` | Johto: Endivie, Feurigel und Karnimani wild mit 5 % | A17 |
| 37 | `dc7c95072c` | Hoenn: Geckarbor, Flemmli und Hydropi mit 5 % statt 1 % | A17 |
| 38 | `8167ea7bc6` | Route 26 und 27: Overworld-Pokémon zeigen fangbare Arten statt Starter | A66 |

#### `balance`: level scaling and battle partners

| # | Commit | Title | Findings |
|---:|---|---|---|
| 39 | `cc1c3ed002` | Levelcap-Challenge: Kanto-Tabellen passend zur Leiter | A28 |
| 40 | `4df138907f` | Kampfpartner: Troy und Siegfried statt STEVEN und LANCE | A115, W-text_width-21 |
| 41 | `167979e1c0` | HnS-Trainerinnen: Geschlecht weiblich bei Arenaleiterinnen und Co. | A116 |
| 42 | `2353317f2f` | Kampfpartner skalieren mit: Troy und Siegfried auf Spielerniveau | A21 |
| 43 | `22896141f1` | Johto: Dukatia und Teak bis zur Story-Wende mit Decke 53 | A73 |
| 44 | `9cd7d8f439` | Johto: Telefon-Rückkämpfe mit mindestens drei Pokémon | A72 |

#### `nuzlocke`: Nuzlocke rules

| # | Commit | Title | Findings |
|---:|---|---|---|
| 45 | `130c5adb25` | Nuzlocke endet mit dem ersten Hoenn-Titel statt mit Rot | A23 |
| 46 | `1d8451f15c` | Nuzlocke: Kämpfe ohne Fangmöglichkeit verbrauchen das Gebiet nicht | A25 |
| 47 | `ac46dd2994` | Nuzlocke: Shiny-Klausel verbraucht die erste Begegnung nicht mehr | A83 |
| 48 | `d05aa4864f` | Nuzlocke: Tod auch in Kämpfen mit KI-Partner | A30 |
| 49 | `df06d73321` | Nuzlocke: Niederlage überschreibt keine Eier mehr | A79 |
| 50 | `ee688ea031` | Nuzlocke: Spitznamenpflicht auch für Kantos Geschenk-Pokémon | A87 |
| 51 | `1f0a14655c` | DECISIONS: offene Nuzlocke-Punkte zu Statics, Eiern und Trainerberg | A26, A118 |

#### `randomizer`: randomizer

| # | Commit | Title | Findings |
|---:|---|---|---|
| 52 | `28158c0e9d` | Item-Randomizer: ab dem ersten Starter aktiv, auch in Kanto | A24 |
| 53 | `013fb23c59` | Item-Randomizer: versteckte Items einzeln, Karte im Seed richtig herum | A88 |
| 54 | `d989ed8f85` | Item-Randomizer: Fossilien und Entwicklungs-Items bleiben an ihrem Platz | A120 |
| 55 | `8d16c9177e` | Trainer-Randomizer: Seed je Trainer statt je Trainerklasse | A80 |
| 56 | `69bf221161` | Feste PKMN: Ausnahmen wie im Menü, feste Seeds, Starter wie Vorschau | A27 |
| 57 | `93f7a7c67a` | Feste PKMN: nur Geschenk-Eier zufällig, Pensions-Eier bleiben | A77 |
| 58 | `998ceca95f` | VM-Notlösung auch bei allen Arten-Randomizern | A119 |

#### `challenge`: challenge menu

| # | Commit | Title | Findings |
|---:|---|---|---|
| 59 | `6355102c85` | Super teuer!: Verkaufspreis wieder vom Grundpreis | A81 |
| 60 | `2d0444d19c` | Weniger Flucht: Fluchtchance nach Initiative statt pauschal 50 % | A82 |
| 61 | `0b35c1bde2` | Challenge-Menü: RNG nur beim neuen Spiel aus den Timern säen | A84 |
| 62 | `5ee30d9a40` | Ein-Typ-Challenge: Standard explizit aus, genullte SaveBlock3 gilt als aus | A45 |
| 63 | `cd86b6c21a` | Dukatia Blumenladen: Minzverkäuferin spricht Deutsch | A86, W-text_width-21 |
| 64 | `a1d638b38f` | Natur-Minzen „Aus“: Verkauf ab dem ersten Hoenn-Titel | A85 |
| 65 | `d4770f4d8f` | Zufallsmodus: Zeile „Legendäre“ nur ohne Ausgleich wählbar | A85 |
| 66 | `a6bb899765` | Challenge-Menü: Beschreibungen passend zur Umsetzung | A85 |

#### `build_tools`: build, CI and check tools

| # | Commit | Title | Findings |
|---:|---|---|---|
| 67 | `dca90ec7e8` | Build: nur noch Origin Jade, make und make check bauen Jade | A36, A43 |
| 68 | `51e8c2d135` | Build: make clean entfernt die Jade-ROM und alle Build-Verzeichnisse | A41 |
| 69 | `5ebf0cb597` | Werkzeug: check_pokenav_text.py liest die Glyphbreiten ab Index 0 | A34, A90 |
| 70 | `2174699385` | Werkzeug: check_merge.py ohne Fehlalarme, bekannte Fälle mit Begründung | A39, A91 |
| 71 | `e348ff39bb` | Werkzeug: Textbreiten der gebauten ROM messen, Textschuld neu bewertet | A34, A90 |
| 72 | `fd95e149f0` | Werkzeug: Save- und Speicherbudget nach dem Build ausgeben | A38 |
| 73 | `6586e2c42a` | Werkzeug: Compiler-Warnungen gegen eine feste Liste prüfen | A99, A100 |
| 74 | `a545d4e73a` | Build: teachable_learnsets.h folgt der GAME_VERSION | A42 |
| 75 | `8e41cc9191` | Doku: INSTALL.md baut mit make statt make hns | A46 |
| 76 | `c64f0a28dd` | CI: ein Jade-Workflow statt der Upstream-Jobs | A36, A37, A92 |

#### Debug menus (owner decision 2026-10-30, added at integration)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 77 | `be6aabb11a` | Debug-Menüs: in der Beta an, in make release aus | A09, A22, A33 |

#### `tests`: test suite and save layout guards

| # | Commit | Title | Findings |
|---:|---|---|---|
| 78 | `c68220b18f` | Tests: fake_rtc.h bindet global.h selbst ein, Test-Runner kompiliert | A06, A31 |
| 79 | `a0e623d5ea` | Tests: Testumgebung startet wie ein neues Spiel, Ballwurf hängt nicht mehr | A07 |
| 80 | `ed9d3eaf11` | Flags: Nummern ohne Speicher erkennen, Reservemarke FRLG hinter S.S. Aqua | A39, A44, A96 |
| 81 | `78aa81bd8e` | Speicherlayout: Wächter für Trainerfenster, SaveBlock3 und Testgrößen | A89, A93, A95, A97 |
| 82 | `17cb0ed51e` | Tests: Origin-Jade-Tests für Level-Skalierung und Flag-/Var-Umleitung | A10 |
| 83 | `631abb6cca` | Tests: run_tests.py mit Liste bekannter Fehlschläge als Regressionstest | A08, A32, A94 |

### Wave 2

#### Small fixes (1)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 84 | `030660c91d` | Johto: deutsche Namen für Rückkampfstufen, Rot und Pyramidenkönig | W-text_width-21, N-balance-2 |
| 85 | `a142e01c51` | Rocket-Versteck: deutsche Niederlagentexte im Doppelkampf mit Siegfried | W-text_width-21, N-balance-3 |
| 86 | `ecba0eaa87` | Radioturm: Quizgewinn setzt den Dukatia-Status nicht mehr zurück | T-johto_b-3 |

#### `map_checker`: `tools/check_maps.py`

| # | Commit | Title | Findings |
|---:|---|---|---|
| 87 | `bbe30578ea` | Werkzeug: statische Kartenprüfung tools/check_maps.py | - |
| 88 | `245a1302de` | Kartenprüfung: Höhen, Fahrten und Kartenwechsel genauer bewertet | - |
| 89 | `3823921744` | Kartenprüfung: Spielerbewegungen aus Coord-Events nachgezogen | - |
| 90 | `846613507a` | Kartenprüfung: Bewertung bekannter Muster nachgeschärft | - |
| 91 | `ca2b081d19` | Kartenprüfung: Vergleich mit einem früheren Stand (--compare) | - |
| 92 | `8215548626` | Kartenprüfung: Textblöcke beenden Skripte, Ausgabe reproduzierbar | - |
| 93 | `63ef906433` | Kartenprüfung: Kartenreste von Layoutwechseln als "optional" | - |

#### Small fixes (2)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 94 | `6faac92fe4` | Kanto: drei versteckte Items mit passender Höhe wieder auffindbar | W-map_checker-6, W-map_checker-7, W-map_checker-8 |
| 95 | `fc4265e4bf` | Siegesstraße 2F (Kanto): Trank auf ein erreichbares Feld | W-map_checker-9, W-progress_sim-3 |
| 96 | `22adbd2c6d` | Kanto: Mama nennt nach einer Niederlage Prof. Eich statt Prof. Birk | T-kanto_a-1 |
| 97 | `6fa1cfe509` | Azuria: Orden-Erklärer nennt die Gehorsamsgrenzen von Origin Jade | T-kanto_a-2 |
| 98 | `89d8e2c60d` | Route 36: Frage zur Schiggykanne passt in die Textbox | W-text_width-20 |
| 99 | `321f7eb411` | Nuzlocke: statische Begegnungen sind frei und immer fangbar | A26 |
| 100 | `dbb71e3ec6` | Nuzlocke: Eier schlüpfen immer und verbrauchen kein Gebiet | A118 |
| 101 | `c441d676ef` | Tests: SaveBlock3-Größe mit den Rekorden des Hoenn-Trainerbergs | A93 |
| 102 | `2d84ddaa50` | Trainerberg Route 40: Preisgeld nur zusammen mit dem Preis | N-facilities-1 |
| 103 | `9c984c84a9` | M.S. Aqua 1F: Tür-Warp zeigt auf den vorhandenen Hafen-Warp | A39, W-map_checker-14 |
| 104 | `000c8fd011` | Nuzlocke: ungenutzte Variable entfernt | N-challenge-2 |

### Wave 3

#### `w3_hoenn`: Hoenn

| # | Commit | Title | Findings |
|---:|---|---|---|
| 105 | `52695b73f8` | Xeneroville: Wassili gibt VM Kaskade, wenn sie fehlt | T-hoenn_b-3 |
| 106 | `66c8c9114f` | Wetterinstitut: Wetterbericht nennt die richtige Hoenn-Route | T-hoenn_b-1 |
| 107 | `d30437a99d` | Wetterereignis: Ende auf der Hoenn-Route statt in Kartengruppe 0 | T-hoenn_b-2 |
| 108 | `eb6b5a1a66` | Blütenburg City: Szene des Arena-Jungen läuft nur einmal | T-hoenn_a-5 |
| 109 | `601bf4bb9a` | Arena Blütenburg City: geschlossene Arena auch mit 1-3 Orden verlassen | T-hoenn_a-6 |
| 110 | `5eb145e6a7` | Malvenfroh City: nach dem Kampf steht Heiko nicht mehr in Blütenburg | T-hoenn_a-4 |
| 111 | `24f9f86e81` | Hoenn: Stärke und Blitz setzen keine Johto-Flags mehr | T-hoenn_a-8 |
| 112 | `63e06c1ef7` | Wurzelheim: Ortsbewohner mit dem PC-Hinweis bleibt sichtbar | T-hoenn_a-11 |
| 113 | `488df2564a` | Normans Anruf zur Arenaöffnung klingelt nur in Hoenn | T-hoenn_a-9 |
| 114 | `7192e23ba7` | Metarost City: Schneider-Haus bricht den Dialog nicht mehr ab | T-hoenn_a-7 |

#### `w3_kanto`: Kanto

| # | Commit | Title | Findings |
|---:|---|---|---|
| 115 | `df6c6afbdc` | Zinnober-Labor: Domfossil nach Helixfossil und Altbernstein belebbar | T-kanto_b-1 |
| 116 | `605046006a` | Azuria: Beerenpuder-Mann prüft Beeren im Beutel statt Beerentüte | T-kanto_a-6, W-progress_sim-15 |
| 117 | `e29aa5d3f2` | Vertania: Tutorial-Opa fragt nicht mehr nach dem Lehrkanal | T-kanto_a-5 |
| 118 | `15b545ea9a` | Alabastia: Sarahs Abschiedstext nach dem Pokédex nicht noch einmal | T-kanto_a-7 |
| 119 | `6518eabf61` | Fuchsania-Zoo: Fossil-Schild zeigt immer Amonitas wie das Gehege | T-kanto_b-4 |
| 120 | `ffbdea3d0d` | Magnetzug: Spieler steht nach der Ankunft nicht im Schaffner | T-kanto_b-6 |
| 121 | `08e3149815` | Azuria: Beerenpuder-Tauschtext passt mit langen Itemnamen in die Box | T-kanto_a-6, W-text_width-3 |

#### `w3b`: Hall of Fame and clock

| # | Commit | Title | Findings |
|---:|---|---|---|
| 122 | `cd155adc3d` | Ruhmeshalle: Johto, Hoenn und PC-Anzeige fassen 50 Teams wie Kanto | A121, W-core_save-1 |
| 123 | `5e1b5f870d` | Neues Spiel: Fake-Uhr vorgewählt, wenn die Modul-Uhr nicht läuft | A35, W-core_save-2 |

#### `text_width`: `tools/check_game_text.py`

| # | Commit | Title | Findings |
|---:|---|---|---|
| 124 | `a81e0f6dad` | Werkzeug: Spieltexte im Quelltext messen und englische Reste finden | - |
| 125 | `e847161c54` | Werkzeug: Textprüfung bewertet Debug- und Sinjoh-Texte nach ihrer Karte | - |
| 126 | `b887df3606` | Werkzeug: Textprüfung meldet englische Trainernamen der .party-Dateien | - |

#### `core_save`: `tools/check_save_safety.py`

| # | Commit | Title | Findings |
|---:|---|---|---|
| 127 | `9ea6ff6d2d` | Werkzeug: statische Prüfung von Geschenken, Taschen und neuem Spiel | - |
| 128 | `46be3a9de6` | Speicherprüfung: Ruhmeshalle, RTC und Link-Funktionen | - |

#### `progress_sim`: `tools/oj_world.py`, `tools/simulate_progress.py`

| # | Commit | Title | Findings |
|---:|---|---|---|
| 129 | `8dede143ee` | Werkzeuge: gemeinsame Datenschicht oj_world.py für statische Prüfungen | - |
| 130 | `c415155a59` | Werkzeuge: Durchspiel-Simulator simulate_progress.py | - |

#### `w3_johto`: Johto

| # | Commit | Title | Findings |
|---:|---|---|---|
| 131 | `63f7024435` | Steineichenwald: Holzkohlemeister setzt Azalea nicht mehr zurück | T-johto_a-1 |
| 132 | `7e3c346926` | Neuborkia: fremdes Haus holt das Route-30-Duell nicht mehr zurück | T-johto_a-3 |
| 133 | `896c802fac` | Sandra-Arena: kein zweiter Kampf nach dem Drachenschrein | T-johto_b-1 |
| 134 | `9df1dfe85a` | Kimono-Girl Zuki: Text ohne Fang sagt nicht mehr „eingefangen“ | T-legend_endgame-1 |
| 135 | `ffe4fc5792` | Lugia und Ho-Oh: kein „flog davon!“ nach einem K.O. | T-legend_endgame-4 |
| 136 | `b702b50666` | Kimono-Tanz: läuft pro Besuch nur einmal | T-johto_b-5 |
| 137 | `ac408421ec` | Steineichenwald: Niederlage gegen Celebi lässt keine Figuren zurück | T-legend_endgame-2 |
| 138 | `bf713b3067` | Kampfzone: Mogelbaum steht auf einem erreichbaren Feld | A65, W-map_checker-10, W-progress_sim-9 |
| 139 | `e30f4f495e` | Lind erkennt das geschlüpfte Ei aus Viola City auch mit Randomizer | A122, T-johto_a-5 |

#### `w3_nuzlocke`: Nuzlocke nicknames and D-039

| # | Commit | Title | Findings |
|---:|---|---|---|
| 140 | `de88177172` | Nuzlocke: Spitznamenpflicht auch für den Kanto-Starter | A87, T-kanto_a-12 |
| 141 | `2077bf9dbe` | Nuzlocke: Johto-Starter im PC bekommt auch einen Spitznamen | A87, T-johto_a-4 |
| 142 | `551f9a1327` | Nuzlocke: Spitznamenpflicht für weitere Johto-Geschenke | A87 |
| 143 | `ed568069c4` | Nuzlocke: Spitznamenpflicht auch für Hoenns Geschenk-Pokémon | A87, T-hoenn_a-10 |
| 144 | `b62f22e381` | DECISIONS: D-039 ohne Wanderer auf Route 26 | T-legend_endgame-5 |

### Documentation

| # | Commit | Title | Findings |
|---:|---|---|---|
| 145 | `38a08f72f4` | Doku: Budgetzahlen in D-017 auf den aktuellen Stand | A38 |
| 146 | `bb1681f692` | Doku: CHANGELOG.md für Spieler und Tester dieser Runde | - |
| 147 | `985723383a` | Doku: PATCHES.md mit Reihenfolge, Prüfung und Anwendung der Reihe | - |
| 148 | `ee3c444213` | Doku: BETA_READINESS.md mit Kriterien, offenen Punkten und Risiken | - |
| 149 | `52ba1053c9` | Doku: TESTS.md um die Prüfwerkzeuge und die Testmatrix ergänzt | A10 |
| 150 | `13e6f261fd` | Doku: README.md für Origin Jade | A46 |

`src/data/debug_kanto_complete.h` was up to date at the end of the audit
series, so none of commits 1 to 150 regenerates it.

### Story packages (owner requirements of 2026-10-31)

#### `ticket`: Hoenn Ticket story and ports (D-047)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 151 | `84e8dc6bb5` | Hoenn: Hoennticket als Basis-Item | owner 1, plan A4 |
| 152 | `93ae559803` | Alabastia: Heilort im Zimmer, nach dem Kanto-Titel dort weiter | owner 1 |
| 153 | `da69d2519c` | Johto-Liga und Rot: danach im Zimmer in Alabastia aufwachen | owner 1, plan A1 |
| 154 | `59bd5a6e39` | Eichs Labor: Troy übergibt das Hoennticket | owner 1, owner 15, plan A0, W-progress_sim-4 (O-002) |
| 155 | `56be2a1860` | Johto-Ruhmeshalle: Eich und Troy kommen nach der Aufzeichnung | owner 1 |
| 156 | `e8c6cc9b93` | Oliviana: Eichs Abschied am Hafen entfällt, Linds Text angepasst | plan A6 |
| 157 | `a18797946a` | Häfen: dynamische Menüs mit Hoenn, Graphitport und Seegrasulb | owner 2, plan A5a, plan A5b |
| 158 | `e505824673` | Werkzeuge: giveitem_norandom bekannt, Hoenn ohne Schalter erreichbar | W-progress_sim-4 |

#### `norman`: Hoenn without a father (D-048)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 159 | `d27f2c12bd` | Hoenn: „Birk sagt immer…“ statt „Vati sagt immer…“ | owner 4 |
| 160 | `1e2c25cad3` | Hoenn-Liga: Birk nennt beim ersten Titel Norman statt „deinen Vater“ | owner 4 |
| 161 | `1c7b9f82a6` | Englische Zweige: Norman ist auch dort nicht „DAD“ | owner 4 |
| 162 | `e6e74b3a85` | Hoenn: Maike, Birks Sohn und Ulrich wissen nur Vages über den Spieler | owner 4, plan B3 |
| 163 | `5a0cfc67c1` | PokéCom: Mamas Anrufe passen zu Kanto, Johto und Hoenn | owner 4, P-005 |
| 164 | `7f3ae8b30f` | Mama heißt überall Mama, nicht Mutti oder Mutter | owner 4 |
| 165 | `5ddcaaf6da` | Blütenburg City: nach der Arenaöffnung spricht niemand mehr vom Umbau | owner 12 |
| 166 | `fd64cd265f` | PokéCom: Norman nach seiner Niederlage mit eigenem Anruftext | owner 4 |
| 167 | `ea9a0f7287` | Wurzelheim: Zimmer von Normans Sohn ohne PC und Deko des Spielers | owner 4, T-hoenn_a-12 |
| 168 | `40102c8756` | Wurzelheim: Szenen im Haus der Spielerfamilie nicht mehr im Jade-Build | owner 4, plan B8, N-hoenn-1 |
| 169 | `7d5e1d669e` | Wurzelheim: Begrüßung als neue Nachbarn nicht mehr im Jade-Build | owner 4, plan B8 |
| 170 | `d5542f3a39` | Wurzelheim: Ankunft mit Mama und Laufschuh-Szene nicht mehr im Jade-Build | plan B8 |
| 171 | `3b20fb905a` | Birks Labor: Emeralds Starter-Übergabe nicht mehr im Jade-Build | plan B8 |
| 172 | `fe370081c1` | Hoenn: Papas Anruf, Ticket-Schritt und Brix' Vater-Satz nicht mehr gebaut | plan B8, N-hoenn-1 |
| 173 | `68df18a8b8` | Vater-Texte: Beeren, Mystery Event und gText_Dad ohne Vater | owner 4, plan B8 |
| 174 | `d38acf1988` | Wanduhr: erstes Stellen ohne Mamas Umzugsszene | plan B8 |
| 175 | `af94011ea4` | Hoenn: Frosina, Dragan, Scott und ein Marktkunde nennen keinen Champion | owner 4, plan B3 |

#### `regions`: Pokemon per region (D-049)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 176 | `58e89bd76b` | Regionen: Artenzuordnung und Freischaltung von Johto und Hoenn | owner 8, owner 10, plan C1 |
| 177 | `66a9a36a4c` | Azurblaue Höhle: Ditto statt Woingenau | plan C2 |
| 178 | `16eb7f6e2e` | Jens: Traunfugil statt Zwirrlicht im ersten Arenateam | owner 18, plan C6 |
| 179 | `d0f6521cf6` | Oliviana City: Auroraticket erst nach der Ankunft in Hoenn | plan C4 |
| 180 | `42e8c25c46` | Zufall: Wurzel- und Klauenfossil keine Item-Ergebnisse mehr | plan C5 |
| 181 | `8fcbb1acc0` | Pension: Eier vor der Freischaltung als erste erlaubte Stufe | plan C3, plan C8 |
| 182 | `f37a68c419` | Pokédex: Gegner späterer Regionen erst nach der Freischaltung gesehen | owner 13, plan C7, plan C8 |
| 183 | `756563f7d7` | Kanto-Pokédex: Eichs Bewertung und das Diplom zählen die 151 | plan C7 |
| 184 | `bb850c8d7c` | Werkzeug: check_regions.py prüft Arten je Region und die Pokédex-Folge | plan C7 |
| 185 | `58f244eade` | Johto-Pokédex: Bewertung, Stern und Diplom ohne Azurill und Isso | owner 8 |

### Fixes after the text check of the story packages

| # | Commit | Title | Findings |
|---:|---|---|---|
| 186 | `26979b66fe` | Diplom in Prismania City: Kanto-Pokédex statt Johto-Pokédex | text check |
| 187 | `e6466779e5` | Johto-Bewertung: Endzeichen im englischen Text ergänzt | text check |
| 188 | `2f4f6ccede` | D-049: Der Johto-Pokédex zählt nicht für die Sterne des Trainerpasses | text check |

### `debug`: debug states "Johto Test" and "Hoenn Test" (D-050)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 189 | `0ab7449520` | Werkzeug: make_kanto_complete.py heißt jetzt make_debug_states.py | - |
| 190 | `ae3e095a3c` | Johto Test: Pokédex aller Kanto-Linien, im PC nur die Endformen | owner 7, owner 11, owner 14, owner 17 |
| 191 | `13bf3c8cb6` | Hoenn Test: Kanto und Johto komplett aus dem Generator, Start bei Troy | owner 6, owner 11, owner 14, owner 17, plan D1, plan D2 |
| 192 | `b022af5623` | Test: debug_states.c prüft Johto Test und Hoenn Test | A10 |

### Documentation (2)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 193 | `6a543a57fc` | Doku: DECISIONS.md mit O-036 bis O-040 aus der Textprüfung der Story | text check |
| 194 | `e48f92fb79` | Doku: CHANGELOG.md um die Story-Pakete, Nachfixes und Debug-Zustände | - |
| 195 | `e330acc928` | Doku: BETA_READINESS.md mit Hoenn über Troy und Emulator-Testliste | - |
| 196 | `60d8ddbb0f` | Doku: TESTS.md mit Testmatrix der Spitze b022af5623 | A10 |
| 197 | `3d4e34b85c` | Doku: README.md nennt Hoenn über Troys Hoennticket erreichbar | - |
| 198 | `2f284d83b9` | Doku: PATCHES.md um die 42 Commits der Story-Pakete und Debug-Zustände | - |

The ids of commits 193 to 198 are those of branch `wp-docs2` on
`b022af5623`; `audit` and `balancing` were fast-forwarded to them.

### Round 2 (owner answers of 2026-10-31 and 2026-11-02)

#### `story`: calls by region, ports and the Pallet Town room (D-051)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 199 | `23661ee2e3` | Schiffsmenüs: „Hoenn“ bleibt, bis Graphitport City anfahrbar ist | O-032 |
| 200 | `647a0d1054` | Hoenn-Anrufe klingeln nur noch in Hoenn | S-07, N-w3_hoenn-2 |
| 201 | `cd421bc8a8` | MS Tide: Scotts Einladung entfällt nach dem Treffen an Bord | S-02, A63 |
| 202 | `2366a7faef` | Linds Anruf nach dem Johto-Titel kommt in Alabastia | O-036 |
| 203 | `15003b77fa` | Zimmer-Deko im Spielerzimmer in Alabastia | O-029, O-041 |
| 204 | `3a229e49c0` | Doku: Troy behält überall das Smaragd-Sprite | O-031 |
| 205 | `2241a44b1e` | Wurzelheim: unsichtbare Familienobjekte der Vater-Szenen entfernt | O-030, N-hoenn-1, T-hoenn_a-12 |
| 206 | `fe29e7cec3` | Code: Funktion für „… sagt immer“ ohne Vater im Namen | O-030 |

#### `hoenn`: lottery, marts, Jirachi, Day Cares, Bills PC (D-052)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 207 | `ba63ca78b9` | Hoenn: eigenes Tageslos im Kaufhaus Seegrasulb | S-03, A61 |
| 208 | `36a20c443a` | Kanto: Jirachi-Ereignis vom Mondberg-Vorplatz auf Route 4 | S-12, A69 |
| 209 | `2cc7c3a70b` | Hoenn: Läden verkaufen Entwicklungs-Items der Hoenn-Familien | S-10, A67 |
| 210 | `9daf2269e5` | Doku: Owner-Antworten zu Wassili, Milotic, Alola/Sinjoh und Mythischen | S-06, S-11, S-15, B-04, A68, N-w3_hoenn-1, O-009 |
| 211 | `e6120b14d0` | Doku: Blutmond-Ursaluna wie HnS, Regionalformen als Entwicklungen | S-13, S-14, A19, A108 |
| 212 | `ad371f51b9` | Regionenregel: aus bei jeder Randomizer-Option | O-033 |
| 213 | `901b96b798` | Trainerpass-Sterne auch für Goldpass-Begrüßung und Kampfzonenpass | O-039 |
| 214 | `bc06eb8f8e` | Pensionen: eigene Pension für Kanto, Johto und Hoenn | S-16, O-020 |
| 215 | `2f7ccdd058` | Bills PC heißt von Anfang an und überall Bills PC | S-16, O-021 |

#### `balance`: boss movesets, league ladder and region badges (D-053)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 216 | `4cd02e34e1` | Hoenn: Maike und Heiko zählen als Bosse (+1 auf das Ass) | B-06, A112 |
| 217 | `ba9263431e` | Troy und Rot: sechs Pokémon auf Level 100 als letzte Story-Bosse | B-10, T-hoenn_b-4 |
| 218 | `f453e1cd12` | Johto-Liga: Level steigen von Willi bis Siegfried wie in HGSS | B-05, A110 |
| 219 | `c76a60fd47` | Ordenzähler: Rückkämpfe, Fangmalus, Challenge und Fortsetzen nach Region | B-08, O-023 |
| 220 | `94ef1dfa9c` | Johto: vier Trainer mit weniger als drei Pokémon aufgefüllt | B-12, N-balance-1 |
| 221 | `525145feff` | Johto-Bosse: feste, starke Movesets für skalierte Level | B-01, A20 |
| 222 | `9814c8cc06` | Hoenn-Bosse: feste, starke Movesets für skalierte Level | B-01, A20 |
| 223 | `b0516cb308` | Kanto-Liga: feste, starke Movesets für die skalierten Rückkampfteams | B-01, A20 |
| 224 | `076468daf3` | Trainer: nicht erlernbare Attacken durch ähnliche erlernbare ersetzt | B-02, A111, W-moveset_sim-2 |
| 225 | `e7d55de9d6` | Doku: D-053 mit den Balance-Antworten ohne Codeänderung | B-03, B-04, B-07, B-09, B-11, B-13, A74, A75, A113, A114, W-moveset_sim-3, N-tests-3 |

#### `hnsalign`: Nuzlocke, challenges and randomizer as in HnS (D-054)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 226 | `25d9748af9` | Challenge „Keine EVs“ endet mit der Nuzlocke beim ersten Hoenn-Titel | N-03, T-legend_endgame-6 |
| 227 | `d4dc31a1fc` | Pokécenter-Challenge: Betten in Hoenn heilen nicht mehr | N-04, N-challenge-3 |
| 228 | `116c058ec8` | Item-Randomizer: Tauschmenüs geben die gewählte Ware ohne Zufall | N-07, N-randomizer-2 |
| 229 | `514e40f424` | Starterwahl: Rückfrage nennt die gezeigte Art, wenn sie wechselt | N-08, N-randomizer-3 |
| 230 | `03a46c603f` | Randomizer: „Starter: Zufall“ gilt auch für Linds und Birks Starter | N-08, N-randomizer-4 |
| 231 | `7899ace9a1` | Doku: D-054 vollständig, O-028 erledigt, offene Punkte O-055 bis O-058 | N-01, N-02, N-05, N-06, N-09, N-10, O-028, N-challenge-4, N-nuzlocke-2, N-nuzlocke-3, N-randomizer-1, A78, A121 |
| 232 | `cd270e41d1` | Nuzlocke: Kämpfe mit KI-Partner wieder wie in HnS | A30 (as in HnS) |

#### `debugaids`: debug states, "Even Wild Slots" (D-050, D-055)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 233 | `22b6c4d130` | Debug-Zustände: jedes erhältliche Item der Regionen einmal (O-035) | O-035 |
| 234 | `19983480f5` | Debug-Menü: Schalter für gleich verteilte wilde Pokémon (Testhilfe) | owner test aid |

#### `decommon`: German common texts (D-056)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 235 | `267e045499` | Texte: Attacken-Lehrer aus Smaragd und HnS auf Deutsch | beta: German, T-hoenn_a-2, W-text_width-17 |
| 236 | `6a8121aae0` | Texte: Safari-Zone (Route 121 und gemeinsame Texte) auf Deutsch | beta: German, T-hoenn_a-3, W-text_width-17 |
| 237 | `aae4064594` | Texte: Seeleute der Fahrschein-Inseln auf Deutsch | beta: German, W-text_width-17 |
| 238 | `78f24c21f2` | Texte: Absage des Mixmeisters vor dem Titel auf Deutsch | beta: German, W-text_width-17 |
| 239 | `c2cc300396` | Texte: Hilfefenster zu den Riegelnäpfen der Safari-Zone auf Deutsch | beta: German, W-text_width-18 |
| 240 | `13efde70d7` | Texte: Englische Antworten in Auswahlmenüs auf Deutsch | beta: German, W-text_width-18 |
| 241 | `081b7785e6` | Texte: Namen und Geschmäcker der Pokériegel auf Deutsch | beta: German |
| 242 | `f59de1486a` | Texte: PC-Hintergrund „Punkte“ und Spielnamen im TV auf Deutsch | beta: German |
| 243 | `0769a01664` | Texte: Level-Kürzel in der Attackenliste des Pokédex auf Deutsch | beta: German |
| 244 | `41c549abbd` | Texte: Kampfcamps am Trainerberg (Route 40) auf Deutsch | beta: German, T-hoenn_a-1, W-text_width-17 |
| 245 | `f74fdc84cd` | Texte: Wünsche und Wettbewerbe der Damen in Seegrasulb auf Deutsch | beta: German |
| 246 | `a44511935c` | Texte: Radweg-Ergebnis und Fanclub-Bewertung auf Deutsch | beta: German |
| 247 | `8a09804587` | Texte: Englische Wörter in deutschen Zweigen übersetzt | beta: German |
| 248 | `84105d9593` | Texte: Weitere Meldungen aus src auf Deutsch | beta: German |
| 249 | `d6af502fa7` | Doku: DECISIONS D-056 (deutsche gemeinsame Texte) und O-063 | beta: German |

#### `demaps`: German map texts (D-057)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 250 | `af909b894e` | Texte: Mahagonia City auf Deutsch | beta: German, T-johto_b-2 |
| 251 | `b310ef0fad` | Texte: Einheitstunnel, Kuhmuh-Stall, Silberberg-Center und Pension | beta: German, T-johto_a-2, T-johto_b-2, W-text_width-16 |
| 252 | `c76fe0e14c` | Texte: Radioturm 4. Stock und Untergrund-Schalterraum auf Deutsch | beta: German, T-johto_a-2 |
| 253 | `3c955f5419` | Texte: Eingang der Safari-Zone am Safari-Tor auf Deutsch | beta: German, T-johto_b-2 |
| 254 | `f2ff040f0c` | Texte: Geldbeträge mit „$“ in fünf deutschen Kartentexten | beta: German |
| 255 | `0c3c46987e` | Texte: Museum Marmoria City und Fiffyen auf Route 114 auf Deutsch | beta: German |
| 256 | `124a45487b` | Doku: DECISIONS D-057 (deutsche Kartentexte), O-065 und O-066 | beta: German |

#### `derest`: German rest of the tent lobby at Route 40 (D-057)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 257 | `a39d3e0ffa` | Texte: NPCs im Kampfcamp Fabrik am Trainerberg auf Deutsch | beta: German, T-johto_b-2, W-text_width-16 |
| 258 | `6d8abd351d` | Texte: unbenutzter TM-Geber im Kampfcamp Fabrik mit Smaragd-Texten | beta: German |
| 259 | `161ec0942e` | Doku: D-057 mit dem Kampfcamp Fabrik, O-065 und O-066 genauer | beta: German |
| 260 | `ae42426ece` | Doku: O-067 geteiltes TM-Flag der zwei Kampfcamp-Lobbys von Wiesenflur | S-04 |

### Documentation (3)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 261 | `9a266e3891` | Doku: DECISIONS.md nach der Zusammenführung der Runde 2 bereinigt | - |
| 262 | `1f6159b7ab` | Doku: CHANGELOG.md um die Runde 2 mit den Owner-Antworten | - |
| 263 | `eb05273ab1` | Doku: BETA_READINESS.md auf den Stand der Runde 2 | - |
| 264 | `449f9a5fc6` | Doku: TESTS.md mit den neuen Tests und der Testmatrix der Runde 2 | A10 |
| 265 | this commit | Doku: PATCHES.md um die 62 Commits der Runde 2 | - |

The id of commit 265 is in `git log`; a commit cannot name its own id.
The ids of commits 199 to 256 are those of `runde2`, 257 to 260 of
`r2-derest` and 261 to 265 of `r2-docs`; on top of the owner's
`ad4a8db368` (rebase or `git am`, see "How to apply") they get new ones.
