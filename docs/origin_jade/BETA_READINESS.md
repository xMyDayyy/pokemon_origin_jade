# Origin Jade - beta readiness

State of 2026-10-31: branch `audit` at `b62f22e381` (144 commits on
`3525d22e71`) plus the documentation commits of this round, which change
no code. The sources are the audit's finding list (297 findings, each with
a status), its test matrix and the checks repeated on 2026-10-31.
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
  fixed in the source. English texts remain on the Johto story path.
- **Hoenn cannot be reached in a normal playthrough.** The Hoenn Ticket has
  no source except the debug menu (O-002, blocker). With the ticket the
  simulator reaches all eight Hoenn badges and the Hoenn title.
- **Nothing was played.** Every fix is checked statically or by tool; the
  emulator test of the three test steps (play A to Z, balancing, reach
  everything) is still to do.
- So the build fits a **closed beta** with testers who use the beta build
  (debug menus on) and take the Hoenn Ticket from the debug menu after the
  Johto title. It is **not ready for an open beta or a release** until
  O-002 is decided, the English story texts are translated and an
  emulator playthrough has been done.

## Beta criteria

| # | Criterion | Verdict | Evidence |
|---:|---|---|---|
| 1 | Build is reproducible | met | 2026-10-31: `make -j2` in a fresh worktree compiles all 397 C files, exit 0; ROM SHA-1 `5c1c08ae7685bf6073ea20c7f87df981d6488c2a`, the same as the incremental build of the integration clone (`integ_b8`). Every commit of waves 2 and 3 and of the documentation was built on its own with its final id; the wave-1 commits were built on their package branches before integration, 7 of them only as part of a package or integration build (`PATCHES.md`). Toolchain arm-none-eabi-gcc 13.2.1. |
| 2 | Release build, debug menus off | met (statically) | `make release` of the same state, 2026-10-31: exit 0, SHA-1 `182fd390ba35e26e171f5684d6a87d3b5f7a7ca0`. The overworld debug menu (`Debug_ShowMainMenu`) is not in the release ELF; the battle debug menu's only trigger (Select, `src/battle_controller_player.c:398`) is compiled out. The sprite visualizer has no caller in the HnS summary screen and is linked in neither build. The release ROM was not started. |
| 3 | No known blocker on the story path Kanto -> Johto title | met (by tool) | `simulate_progress.py`: Kanto title in wave 50, GS Ball 51, Johto badges 55-91, Johto title 105; no stop on the main path. `check_maps.py`: 0 findings from "important" up (base: 3 critical, 10 important). Base: the simulator stopped in Kanto at the Celadon Game Corner (A01). Story traps A02, A03, A13, A57, A102 and the deep review's state bugs are fixed in the source (statically). |
| 4 | No known blocker on the story path Johto -> Hoenn title | **not met** | The Hoenn Ticket has no source (O-002, `W-progress_sim-4`). With `--hoenn-ticket` the simulator reaches Hoenn in wave 111, the Hoenn badges in 112-130 and the Hoenn title in 140. The critical findings A04 (ship trips reset Hoenn) and A05 (S.S. Ticket scene after the title) are fixed but only matter once Hoenn is reachable. |
| 5 | Saves are safe | met (statically), with risks | `check_budget.py`: every save block within its flash space (SaveBlock1 15868/15872, SaveBlock2 3892/3968, SaveBlock3 1008/1624, PokemonStorage 34144/35712). `STATIC_ASSERT`s pin the layout; `test/save.c` (4 tests) passes. `check_save_safety.py`: no blocker or critical finding; 1 important (no running clock, mitigated by `5e1b5f870d`, which the tool does not model), 3 minor (one is a false alarm on the Hall of Fame size, two concern the item randomizer's bag pockets), 74 optional. New games clear the Nuzlocke area flags. Saving and loading never ran in an emulator; old saves are out of scope (owner decision). |
| 6 | No English text on the story path | **not met** | `check_game_text.py --english`: Johto 125 English texts (51 important: 40 story NPCs, 11 triggers; base 144), shared scripts 252 (169 minor, 83 debug), Hoenn 7, Kanto 5 (all in locked content). On the story path: Radio Tower 5F, Goldenrod Underground switches, Mahogany Town, Elm's call about the Radio Tower, Union Cave 1F; in every region the Safari Zone system texts, the Battle Tents and the Emerald move tutors (T-johto_a-2, T-johto_b-2, T-hoenn_a-1 to -3). |
| 7 | Text fits the message box (208 px) | not met (minor) | `check_text_width.py --list` on the built ROM: 35 exact lines over 208 px (Johto 28, Kanto 1, locked maps 6); none over the 216 px window outside locked maps. 365 lines with placeholders are estimates. |
| 8 | Static checks green | met | `check_flags.py` 0 problems (3426 flags, 693 vars); `check_merge.py` 0 errors (8 known with a reason); `check_maps.py` 0 findings from "important" up (88 minor); `make_kanto_complete.py --check` up to date, `--overlap` 0 new; `check_budget.py` exit 0; `check_warnings.py` on the full build log of 2026-10-31: 105 warnings, as in the baseline. |
| 9 | Test suite without new failures | met (regression check) | `tools/run_tests.py` on `b62f22e381`: 5124 tests in 946 files, 2333 ok, 629 todo, 2162 failures, all known, 0 new, 0 changed. Origin Jade tests: level scaling 9/9, flag/var routing 7/7, save sizes 4/4. Limit: about 2100 upstream tests cannot check anything because battle texts are German, and 24 failures are not triaged (A32, `N-tests-1`). |
| 10 | Every Pokedex species obtainable without trading | met except Jirachi | Availability model of the inventory on this state: 421 of 422 species have a source; Jirachi has none (A69; D-036 does not require it). All nine starters and Meditite/Medicham are wild. Hoenn sources need the ticket (criterion 4). |
| 11 | Played through in an emulator | **not met** | No emulator test. The checklists for the three test steps are in the audit's test matrix; "What was not verified" below names the gaps. |
| 12 | Owner decisions taken | **not met** | See "Owner decisions still needed". |

## Open findings by priority

From the audit's finding list: 124 of 297 findings are open or only
partly fixed (1 blocker, 0 critical, 14 important, 43 minor, 66
optional). Fixed: 126; no bug or refuted: 12; intended by a decision: 4;
duplicates: 31.

### Blocker

#### W-progress_sim-4 / O-002: Hoenn is not reachable without the Hoenn Ticket

- **Status:** open, owner decision (O-002: "story after the ticket ... will
  be redesigned. Do not implement in the meantime").
- **Evidence:** `Common_EventScript_SailToHoenn`
  (`data/scripts/hoenn_arrival.inc:7-9`) runs only with `ITEM_HOENN_TICKET`
  in the bag, otherwise `Common_EventScript_HoennNoTicket`. The ticket has
  no source in the game except the debug menu ("Give item").
- **Files:** `data/scripts/hoenn_arrival.inc`; the ports that call it
  (`VermilionCity_PortInside_Frlg`, `VermilionCity_PortInside_hns`,
  `OlivineCity_PortInside_hns`, `SSAqua_1F_hns`); the future ticket source.
- **Repro:** `python3 -I tools/simulate_progress.py` ends with exit 1
  (Hoenn not reached). In the game: after the Johto title choose Hoenn at
  a port without the ticket.
- **Impact:** a normal playthrough ends after the Johto title; without the
  ticket 566 active maps stay unreachable, 420 of them in Hoenn.
- **Proposal:** the owner decides the ticket's story and source. Until
  then testers take the ticket from the debug menu after the Johto title
  and pick Hoenn at the port; the simulator runs with `--hoenn-ticket`.
- **Test status:** checked by tool (`simulate_progress.py` with and without
  the ticket); not checked in an emulator.

### Critical

None open. A04 and A05 are fixed (statically checked); they take effect
once Hoenn is reachable.

### Important

#### A20: fixed movesets of scaled bosses stay at their original level

- **Status:** open, owner decision.
- **Evidence:** `CustomTrainerPartyAssignMoves` (`src/battle_main.c`) sets
  a trainer Pokemon's listed moves regardless of the scaled level. Boss
  moveset simulation (`000c8fd011`; trainer data and scaling unchanged
  since): Johto 36 bosses, 213 Pokemon, 157 with fixed moves, level gap of
  20 or more for 99 and of 30 or more for 27; Hoenn 55 bosses, 252
  Pokemon, 78 with fixed moves, all with a gap of 30 or more, 67 of 40 or
  more.
- **Files:** `src/battle_main.c`, `src/data/trainers.party`,
  `src/data/trainers_hns.party`.
- **Repro:** Hoenn with a team from the Johto title (anchor about 65)
  against Roxanne: Golem at level 66 with Rock Throw and Defense Curl.
- **Impact:** bosses are much weaker than their level suggests; Pokemon
  added by `tools/fill_johto_parties.py` get level-fitting moves, the
  original members do not.
- **Proposal:** option 1 keep and document, option 2 level-up moveset from
  a level gap on, option 3 hybrid at runtime: TM, egg and special moves
  stay, outdated level-up moves are replaced by stronger ones the scaled
  species learns by its level (the audit recommends option 3). Curating
  the first boss battles by hand is an alternative without runtime code.
- **Test status:** checked by tool (moveset simulation); not in an emulator.

#### A19: regional forms, Sneasler and Overqwil are missing on purpose (D-023)

- **Status:** open, owner decision.
- **Evidence:** `P_REGIONAL_FORMS` is `FALSE`
  (`include/config/species_enabled.h`); 44 regional forms of the Gen 1-3
  families, Sneasler, Overqwil and six regional evolutions are missing.
  D-023 records this; the audit's goal list asks for them.
- **Files:** `include/config/species_enabled.h`.
- **Impact:** no malfunction; goal and decision contradict each other.
  Enabling them touches the randomizer pool, O-009, the Battle Frontier
  data and possibly saves and Pokedex flags.
- **Proposal:** the owner clarifies the goal; if wanted, a work package of
  its own that checks saves, ROM size and encounters first.
- **Test status:** not checked (proposal).

#### A15: Emerald's Trainer Hill on Route 111 - partly fixed

- **Status:** partly fixed (`0b265d9f0f`: Emerald trainers and floors,
  records of its own in SaveBlock3). Open, owner decision: both hills share
  `MAPSEC_TRAINER_HILL`, which the HnS build places on the Johto map (O-024),
  and the prize rule (Emerald's prizes without money, D-044).
- **Evidence:** D-044, O-024; `src/trainer_hill.c`.
- **Files:** `src/trainer_hill.c`, the seven `TrainerHill_*` maps,
  `src/data/region_map/region_map_sections.json`.
- **Repro:** after the Hoenn title enter the hill on Route 111 (31,113):
  the region map shows Johto, battles play Johto's music, Hoenn-only map
  section rules do not apply.
- **Impact:** cosmetic and rules inside the hill; the hill itself works
  (statically).
- **Proposal:** a Hoenn map section of its own for the seven Emerald maps.
- **Test status:** checked statically (code paths, build, `check_flags`);
  neither hill was run.

#### A10: Origin Jade tests - partly fixed

- **Status:** partly fixed (`17cb0ed51e`, `78aa81bd8e`, `c441d676ef`).
- **Evidence:** `test/origin_jade/level_scaling.c` (9 tests),
  `test/origin_jade/event_data.c` (7), `test/save.c` (4) pass. Missing:
  tests for story scripts (GS Ball handover, theater state) and for save
  migrations.
- **Files:** `test/origin_jade/`, `src/save.c` (`LoadGameSave`).
- **Proposal:** tests for the migrations and for the region rules (D-006);
  story scripts need an emulator or a script-level test harness.
- **Test status:** checked by tool (`run_tests.py`).

#### A32: upstream battle tests expect English messages - partly fixed

- **Status:** partly fixed: the failures are in the baseline
  `test/known_failures.tsv` (`631abb6cca`); the rule is an owner decision.
- **Evidence:** 1969 "Unmatched MESSAGE" and 127 statistical failures:
  species, move and battle texts are German without a language switch, so
  `GAME_LANG=ENGLISH` does not help.
- **Files:** `test/battle/**` (about 500 files with `MESSAGE`),
  `test/known_failures.tsv`.
- **Repro:** `python3 tools/run_tests.py`; see `build/jade-test/results/`.
- **Impact:** these tests report a regression only as a changed failure;
  they cannot catch real battle regressions.
- **Proposal:** exclude them, switch them to German strings, or keep the
  list (current state).
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

#### T-johto_a-2: English story texts in Johto (Radio Tower 5F, Underground, Union Cave, Day Care)

- **Status:** open, text round (O-012).
- **Evidence:** labels without a `#if GERMAN` branch:
  `data/maps/GoldenrodCity_RadioTower_5F_hns/scripts.inc` (20 labels:
  fake director, Executive, Rocket boss, director, Silver/Rainbow Wing),
  `GoldenrodCity_UndergroundSwitches_hns/scripts.inc` (29: Silver's
  battle, grunts, "SWITCH 1 activated." and the anti-softlock question),
  `UnionCave_1F_hns/scripts.inc` (15, 5 trainers),
  `Route34_DayCare_hns/scripts.inc` (1).
- **Repro:** Radio Tower 5F, talk to the fake director.
- **Impact:** the Rocket takeover, Silver's underground battle and the
  switch puzzle hints are English in the German build (against D-020).
- **Proposal:** German branches, story texts first (5F, switches).
- **Test status:** checked statically (texts read; `check_game_text.py`).

#### T-johto_b-2: English texts in Mahogany Town, Elm's call, Moomoo Farm, Safari Zone gate, Battle Tent

- **Status:** open, text round (O-012); the cross-check rates it rather
  minor, Mahogany Town first.
- **Evidence:** `data/maps/Mahoganytown_hns/scripts.inc` (13 labels, among
  them the Rage Candy Bar merchant who blocks Route 44 and Elm's mandatory
  call about the Radio Tower takeover),
  `Route39_Barn_hns/scripts.inc` (11),
  `SafariZoneGate_SafariZoneEntrance_hns/scripts.inc` (18),
  `SlateportCity_BattleTentLobby_hns/scripts.inc` (5).
- **Repro:** Mahogany Town, talk to the merchant before the Rocket
  hideout.
- **Impact:** mandatory story texts in English.
- **Proposal:** German branches, Mahogany Town and Elm's call first; check
  widths (208 px, PokeNav 192 px).
- **Test status:** checked statically.

#### T-hoenn_a-1: Battle Tents (Emerald and Route 40) entirely English

- **Status:** open, text round; not covered by O-012.
- **Evidence:** `data/text/battle_tent.inc`: 63 text labels, no German
  branch; used by the Slateport, Verdanturf and Fallarbor tent lobbies and
  the HnS copies by the Route 40 Trainer Hill.
- **Repro:** Slateport City, Battle Tent lobby, talk to the receptionist.
- **Impact:** welcome, rules, sign-up, results and BP of all six tent
  lobbies in English.
- **Proposal:** translate with `#if GERMAN` (terms as in the Kampfzone),
  then measure the widths.
- **Test status:** checked statically.

#### T-hoenn_a-2: Emerald move tutors (11 scripts) English, also in Johto

- **Status:** open, text round; not covered by O-012.
- **Evidence:** `data/text/move_tutors.inc`: 44 labels, no German branch;
  `data/scripts/move_tutors.inc`. Hoenn tutors from Slateport City on;
  Johto: Olivine City (Metronome), Route 40 Trainer Hill courtyard
  (Substitute), Ilex Forest (Headbutt).
- **Repro:** Slateport City, Pokemon Fan Club, talk to the tutor.
- **Proposal:** translate `move_tutors.inc`; move names already come in
  German.
- **Test status:** checked statically.

#### T-hoenn_a-3: Safari Zone system texts English in all three zones

- **Status:** open, text round; not covered by O-012.
- **Evidence:** `data/scripts/safari_zone.inc`: 42 English labels, no
  German branch; `src/safari_zone.c` calls them in every region (time up,
  out of balls, quit). The Hoenn entrance on Route 121 is entirely English.
- **Repro:** Kanto Safari Zone, walk until the time is up: "Ding-dong!
  Time's up!".
- **Proposal:** translate `safari_zone.inc`, the time, ball and quit texts
  first.
- **Test status:** checked statically.

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
| A69 | shared | Jirachi has no source (only a retired map) | owner | create a source or record it as unobtainable (D-037 names the gap) | static |
| N-challenge-3* | shared | Pokemon Center challenge blocks only the nurse, Mom, the S.S. Aqua bed and the Dojo; 59 maps with `HealPlayerParty` still heal | owner | menu text adjusted (`a6bb899765`); behaviour open | static |
| N-challenge-4* | shared | Hardcore Nuzlocke deletes the save also after a faint from poison in the field | owner | text says "bei jeder Niederlage"; keep or limit to battles | static |
| N-nuzlocke-1* | shared | With "Feste PKMN: Zufall" the received message of Kanto gifts names the original species | open | buffer the species after randomizing | static |
| N-nuzlocke-3* | shared | Nuzlocke deaths do not count in the Trainer Hills (O-028) | owner | proposal: keep them exempt like the Battle Frontier | static |
| N-randomizer-1* | shared | Item randomizer: follow-up dialogs name the original item (e.g. Brock and TM39) | owner | generic texts or `giveitem_norandom` | static |
| N-randomizer-2* | shared | Item randomizer: trades (Berry Powder, glass workshop, Mom's savings, lottery) give other items | owner | exclude with `giveitem_norandom` or accept | static |
| N-w3_nuzlocke-2* | shared | `Common_EventScript_PartyIsFull` ends without `release` although Bill, the Elder, Kenya and Shuckie called `lock` | open | check for a freeze in the game; add `release` | not checked |
| T-legend_endgame-6 | shared | Challenge "Keine EVs" ends at Red, before Hoenn | owner | extend to the first Hoenn title like the Nuzlocke? | static |
| W-core_save-3 | shared | With the item randomizer the Items pocket (up to 307 items, 236 slots) and Berries pocket (68, 66 slots) can fill up | open | limit the whitelist or secure gifts (W-core_save-4) | not checked (tool suspicion) |
| W-text_width-16 | shared | More English map texts: Moomoo twins, Route 34 Day Care, Slateport Battle Tent | text round | overlaps T-johto_b-2, T-johto_a-2, T-hoenn_a-1 | by tool |
| W-text_width-17 | shared | English shared text files: `battle_tent.inc`, `safari_zone.inc`, `move_tutors.inc`, event tickets, Mixmeister | text round | overlaps T-hoenn_a-1 to -3 | by tool |
| W-text_width-18 | shared | English source texts in visible windows: Safari gate help board, fisher choice, trade board | text round | translate | by tool |
| W-text_width-2 | shared | 15 side-text lines of 209-212 px | text round | move a word | by tool |
| W-text_width-3 | shared | Berry Powder exchange line 227 px with a long item name | partly fixed | Cerulean City rewrapped (`08e3149815`); the same text in `SlateportCity/scripts.inc:1749` unchanged | by tool |
| W-text_width-7 | shared | Other estimated over-wide lines with placeholders | text round | measure with real values | not checked (tool estimate) |
| W-text_width-8 | shared | Four source text lines over 208 px in windows of their own | text round | window widths not measured | not checked (tool estimate) |
| A61 | Hoenn | Johto flags change Hoenn dialogs (D-040 leaks outside its list) | partly fixed | Wally's father, Rock Smash man, fossil maniac, Safari Zone, Strength have Hoenn flags; open: shared daily lottery ticket Lilycove/Goldenrod, tent TMs and Scott's flags once per game (owner) | static |
| A63 | Hoenn | Battle Frontier offered from Hoenn only after an S.S. Tidal trip (`FLAG_MET_SCOTT_ON_SS_TIDAL`), not in D-030 | owner | document in D-030 or relax the condition | static |
| A67 | Hoenn | Hoenn families need evolution items sold only in Kanto/Johto | owner | sell them in Hoenn marts or document | not checked (suspicion) |
| A68 | Hoenn | Prism Scale has no source | owner | place one or document the Beauty path to Milotic | static |
| N-facilities-2* | Hoenn | Emerald Trainer Hill maps do not set `FLAG_TEMP_HIDE_FOLLOWER` (HnS maps do) | open | check the follower Pokemon at runtime | not checked |
| N-w3_hoenn-2* | Hoenn | Wally's, Scott's (two) and Roxanne's calls count steps in Johto and Kanto too | owner | same guard as Norman's call (`488df2564a`); changes vanilla calls | static |
| A54 | Johto | Suicune sighting on Route 42 in a pocket behind a Cut tree | owner | move the trigger, add a hint, or record it in D-038 | static |
| A75 | Johto | A caught legendary (level 75) lifts the Johto anchor to 67 or more | owner | legendary levels and anchor effect (also Red, Mt. Silver floor, theater ceiling) | static |
| N-balance-1* | Johto | Four Johto trainers with fewer than 3 Pokemon (Marc, Rich, Shirley, Zuki) | owner | fill up or an exception in D-012 | by tool (audit script) |
| N-johto_story-1* | Johto | Celebi is no longer caught with the GS Ball (key item, not throwable); level 75, normal balls | owner | accept and document, or change | static |
| N-johto_story-2* | Johto | The theater's Mystic Water is lost with a full bag (`giveitem` without a space check) | open | `checkitemspace` (see W-core_save-4) | static |
| N-nuzlocke-2* | Johto | Route 41: Pokemon that faint in the unwinnable level-100 Tentacruel guard battle die | owner | exception? The guards stand where nobody passes anyway (W-map_checker-11) | static |
| W-moveset_sim-3 | Johto | Ariana 1 (Rocket Hideout B2F) has 6 Pokemon; the double battle shows only the first 3 | owner | stronger ones first, drop slots 4-6, or keep | by tool (moveset simulation) |
| A48 | Kanto | TM27 (Return) is lost behind the retired Route 12 north gatehouse | owner | move the girl, drop TM27 in Kanto, or keep; then `EXCLUDED_MAPS` in `tools/make_kanto_complete.py` | by tool (`check_maps`, `simulate_progress`) |
| A50 | Kanto | `Route22_hns` is active but cannot be entered (O-022) | partly fixed | O-022 documented (`b4a8ab9ce9`); retire or connect (owner) | by tool (`check_maps`) |
| A74 | Kanto | Kanto ladder: 53 under-levelled evolutions (e.g. Dragonite 46/47, Tyranitar 47) | owner | use pre-evolutions or accept | static |
| A78 | Kanto | No move reminder in Kanto (chapter 1) | owner | add one or accept | static |
| A37 | technical | GitHub Actions never ran | partly fixed | Jade workflow committed (`c64f0a28dd`); the owner has to enable Actions; the test job is a placeholder | static (workflow never ran) |
| A38 | technical | Save and RAM budget almost used up (SaveBlock1 4 bytes free, EWRAM 95 %) | partly fixed | `tools/check_budget.py`, D-017; more reserve is an owner decision (see A89) | by tool (`check_budget`) |
| A40 | technical | Width tests in `test/text.c`: German overflows and the grammar slip "von das gegnerische" | text round | the 6 width failures are in the baseline | static |
| A46 | technical | Build target and README described HnS | partly fixed | `INSTALL.md` builds with `make` (`8e41cc9191`); `README.md` is rewritten by the last documentation commit of this round | static |
| A89 | technical | SaveBlock1 has 4 bytes left; its layout depends on `FLAGS_COUNT` | partly fixed | `STATIC_ASSERT`s, D-016/D-017; pinning `FLAGS_COUNT`/`VARS_COUNT` is an owner decision | by tool (build with asserts, `check_budget`) |
| A94 | technical | `test/text.c` fails on German Z-move names | partly fixed | in the baseline; adapt the expectations or exclude the tests (owner) | by tool (`run_tests`) |
| N-kanto_maps-3* | technical | Older HnS imports: Johto and Hoenn layouts not checked for Origin Jade tiles reverted by a merge | open | three-way check as in `425eb2fbb1` | not checked |
| N-tests-1* | technical | 24 test failures not triaged (bag sorting, Sheer Force, Day Care regional forms, Alolan Raticate form table, ...) | open | triage; some may be real bugs | by tool (`run_tests`) |

### Optional

| Id | Area | Finding | Status | Note |
|---|---|---|---|---|
| A109 | shared | Mamoswine practically needs the move reminder (Ancient Power) | open | comfort proposal; the condition can be met |
| A111 | shared | 147 active trainer Pokemon with moves they cannot learn (9 bosses confirmed, W-moveset_sim-2) | owner | review the list |
| A113 | shared | Low IVs of Johto/Hoenn bosses for their scaled level (see O-023) | owner | |
| N-balance-4* | shared | Partner OT name cut to "Siegfri" (7 characters), only in the summary | open | |
| N-challenge-1* | shared | Escape formula: `u8 speedVar` in `TryRunFromBattle` overflows after 5-6 tries (upstream) | open | |
| N-randomizer-3* | shared | With "Starter: Zufall" Oak's confirmation names the original species (the received message is right) | owner | text |
| N-randomizer-4* | shared | "Starter: Zufall" only affects the Kanto starter; Elm and Birch give the original (D-023) | owner | |
| N-randomizer-5* | shared | The item randomizer menu line does not mention fossils and evolution items | owner | text |
| N-randomizer-6* | shared | Scripted double wild battles are never randomized | open | whether an active map uses them is not checked |
| N-w3_nuzlocke-1* | shared | The new nickname question also appears without Nuzlocke (Johto starter and Goldenrod prizes in the PC, Bill's Eevee, the Dragon's Den Dratini) | owner | may be rejected |
| W-core_save-4 | shared | 72 gift and trade scripts without a space check (71 in the tool report; Wallace's HM Waterfall is new) | open | secure the story-relevant ones (fossils, Bug-Catching Contest, Exp. Share, Metal Coat) with `checkitemspace` |
| W-core_save-5 | shared | Key items pocket: 3 slots reserve | open | a rule in D-017 |
| W-core_save-6 | shared | Link features (Cable Club, Union Room, ...) reachable in the Jade build | owner | offer them on purpose (then test them) or hide them |
| W-progress_sim-14 | shared | Birth Island (HnS): warp 0 to the port lies in the wall | open | dead warp; the sailor replaces it |
| W-progress_sim-16 | shared | Orphaned active maps (nothing leads there) | owner | retire (D-018/D-019) or keep |
| A107 | Hoenn | Dead and write-only Hoenn data | open | clean-up (D-018/D-019) |
| A112 | Hoenn | May and Wally are no bosses (+1), unlike Silver and Blue | owner | |
| A114 | Hoenn | Hoenn corridor floors are very hard for story rushers (+9 to +12 levels from Winona on) | owner | |
| N-hoenn-1* | Hoenn | Dead Jade branches after A05/A58 (Birch and May at the lab, the Dad scene) | open | delete, or a short scene with owner text |
| N-hoenn-2* | Hoenn | The heading of D-040 names only Kanto | open | cosmetic |
| N-pokemon-1* | Hoenn | Medicham appears in the Battle Pyramid; dead test gift at the Safari gate | open | |
| N-randomizer-7* | Hoenn | Item randomizer swaps Shoal Salt and Shoal Shells; the Shell Bell can become unreachable | open | |
| N-w3_hoenn-1* | Hoenn | Wallace gives nothing if HM Waterfall is already in the bag | owner | a substitute reward would be a design decision |
| N-w3_hoenn-3* | Hoenn | Wallace's text says the badge is needed to teach the HM; in Jade it is the permit | owner | text |
| T-hoenn_a-12 | Hoenn | Emerald player room leftovers in Norman's and Birch's house (D-002) | owner | |
| T-hoenn_b-4 | Hoenn | Steven in Meteor Falls stays at level 75-78, about 20 below the Hoenn post-game (D-031 vs. D-043) | owner | |
| T-legend_endgame-3 | Hoenn | Weather Institute 1F and the sailor judge Kyogre/Groudon differently for up to 3 days | open | |
| W-progress_sim-17 | Hoenn | Dead script code from design decisions (e.g. Brendan's teams, D-003) | open | clean-up |
| A105 | Johto | Dead states, never-set flags and test warps in Johto (New Bark Town 4-7, Ecruteak City 4/5/14) | owner | |
| A110 | Johto | League ceiling 65: Elite Four, Silver and Lance equally strong | owner | |
| N-johto_story-3* | Johto | The Wailmer Pail does not wake the Battle Frontier Sudowoodo (only the SquirtBottle does) | open | |
| N-johto_story-4* | Johto | The new gate text has an English `#else` branch for non-German builds | owner | keep or German only |
| N-w3_nuzlocke-3* | Johto | Johto starter: the nickname question in the Nuzlocke branch has no YES/NO | open | works |
| N-w3_nuzlocke-4* | Johto | Dead code in the Goldenrod Game Corner prize room | open | |
| T-johto_b-5 | Johto | Kimono Girls' dance repeats until the legendary battle | partly fixed | once per visit (`b702b50666`); after a map change or whiteout it restarts as in HnS |
| T-johto_b-6 | Johto | Route 40 Trainer Hill courtyard open before the Johto title | owner | bind to `FLAG_IS_JOHTO_CHAMPION` or keep |
| T-johto_b-7 | Johto | Johto Safari Zone: west extension locked, Baoba's quest dead (P-004) | open | builder texts English |
| T-legend_endgame-4 | Johto | "... flew away!" after knocking out Deoxys | partly fixed | Lugia and Ho-Oh fixed (`ffe4fc5792`); Birth Island needs an event ticket |
| W-map_checker-11 | Johto | Route 41: the Tentacruel barrier (D-026) blocks nothing | owner | move it in front of an island entrance or drop it |
| W-map_checker-13 | Johto | Battle Frontier Pokemon Center: stairs to 1F outside the map (HnS) | open | no change recommended |
| W-text_width-9 | Johto | Help window `HELP_GAMESTART_WINDOW` 226/221 px | text round | probably never shown |
| A103 | Kanto | Dead Sevii branches in active Kanto scripts | open | clean-up (D-019) |
| A108 | Kanto | Bloodmoon Ursaluna can be obtained (Peat Block at night in Mt. Moon) | owner | confirm or remove |
| N-build_tools-1* | Kanto | Orphaned or locked maps in the `KNOWN_ERRORS` of `check_merge.py` | owner | retiring them changes the ROM |
| N-kanto_maps-1* | Kanto | Pallet Town: walkable door tiles without a warp (HnS tileset) | owner | |
| N-w3_kanto-1* | Kanto | Berry Powder only via the link Berry Blender; alone the exchange stays at 0 | owner | a neutral line needs owner text |
| N-w3_kanto-2* | Kanto | Cinnabar Lab: after revivals in the Ruins of Alph the farewell may be the no-fossil line | open | cosmetic |
| T-kanto_a-10 | Kanto | Oak's aides count only numbers 1-151 (randomizer) | open | proposal |
| T-kanto_a-11 | Kanto | Self-warp left on Route 2 (warp 10) | open | harmless |
| T-kanto_a-8 | Kanto | Cerulean City house 2 (burglary) has no entrance and wrong exits | owner | retire or restore the entrance |
| T-kanto_b-3 | Kanto | Fuchsia City: a girl still calls Koga the gym leader | owner | needs new story text |
| T-kanto_b-7 | Kanto | Saffron City station sign all in capitals (D-020) | text round | |
| W-core_save-8 | Kanto | Kanto title: Oak's plateau scene only after saving | open | no softlock |
| W-map_checker-12 | Kanto | S.S. Anne deck active but without access; its hidden Lava Cookie is lost | owner | move or give up |
| A121 | technical | Hall of Fame entries carry no region | partly fixed | all regions hold 50 teams (`cd155adc3d`); a region per entry is an owner decision |
| N-build_tools-2* | technical | Leftovers of removed build targets (`make compare` checks Emerald's `rom.sha1`, `make debug` writes the same file name, `docs/tutorials/how_to_frlg.md` names `make firered`) | open | |
| N-build_tools-3* | technical | CI docs check removed (`DECISIONS.md` not in `docs/SUMMARY.md`) | owner | mdbook docs wanted? |
| N-build_tools-4* | technical | The release build (LTO) has 6 warnings more than the baseline; the warning check covers the normal build only | open | confirmed 2026-10-31: 111 vs. 105 |
| N-build_tools-5* | technical | `make GAME_VERSION=EMERALD` on the command line still overrides the fixed version | open | |
| N-tests-2* | technical | 16 ball tests INVALID (HnS balls need a party index in the runner) | open | small runner exception possible |
| N-tests-3* | technical | 6 spread move damage tests fail on `B_MULTIPLE_TARGETS_DMG GEN_3` (HnS) | owner | intended? not in DECISIONS |
| N-tests-4* | technical | `make check`: the hydra runner buffers without a limit | open | `run_tests.py` is not affected |
| W-core_save-7 | technical | Save migrations run on every `LoadGameSave` | open | harmless today; run them only for `SAVE_NORMAL` with status OK |
| W-map_checker-17 | technical | Unreached maps: intended or not modelled | open | maybe mark them retired in D-018/D-019 |
| W-progress_sim-18 | technical | Battle Frontier, Pyramid, contests and secret bases not modelled | open | check in the emulator |
| W-progress_sim-19 | technical | Other model-limit hits | open | probably model artefacts |

## Owner decisions still needed

**Story and content**
- O-002: source and story of the Hoenn Ticket (blocker for Hoenn).
- English game text in the German build: a text round with the official
  German terms, or by the owner. It covers O-012 (Johto story) and the
  shared texts O-012 does not name (Safari Zone, Battle Tents, move tutors,
  event tickets), plus the line widths.
- Route 41: the Tentacruel barrier blocks nothing (W-map_checker-11), and
  Nuzlocke deaths in its battle (N-nuzlocke-2).
- Maps without access: Cerulean City house 2 (T-kanto_a-8), TM27 on
  Route 12 (A48), `Route22_hns` (A50, O-022), S.S. Anne deck
  (W-map_checker-12), orphaned maps (W-progress_sim-16), test warps
  (A105), Pallet Town door tiles (N-kanto_maps-1).
- Suicune sighting on Route 42 (A54), Route 40 hill courtyard before the
  title (T-johto_b-6), Fuchsia girl and Koga (T-kanto_b-3), player room in
  Littleroot (T-hoenn_a-12), Berry Powder only by link (N-w3_kanto-1).
- Owner text for the Petalburg gym boy after beating Wally in Mauville
  first (T-hoenn_a-4), for Clair in state 3 (T-johto_b-1) and for a
  Nuzlocke whiteout without a living Pokemon (A79); approval of the new
  German lines and adopted names of this round, which the owner did not
  write.

**Balance**
- Fixed movesets of scaled bosses (A20, three options).
- Under-levelled evolutions of the Kanto ladder (A74); legendary levels
  and their effect on the anchor, Red, the Mt. Silver floor and the
  theater ceiling (A75).
- League ceiling (A110), May and Wally as bosses (A112), boss IVs (A113),
  Hoenn floors for rushers (A114), Steven in Meteor Falls (T-hoenn_b-4).
- 147 trainer moves that cannot be learned (A111); Ariana 1 in the double
  battle (W-moveset_sim-3); Johto trainers with fewer than 3 Pokemon
  (N-balance-1).

**Pokemon and items**
- Regional forms, Sneasler and Overqwil (A19).
- Evolution items in Hoenn marts (A67), Prism Scale (A68), Jirachi (A69),
  Bloodmoon Ursaluna (A108), overworld Pokemon that cannot be caught
  (A66).
- Celebi can no longer be caught with the GS Ball (N-johto_story-1).

**Challenges**
- Confirm the Nuzlocke end at the first Hoenn title (O-025).
- Nuzlocke in the Trainer Hills (O-028).
- "Keine EVs" end point (T-legend_endgame-6); Pokemon Center challenge
  scope (N-challenge-3); hardcore after field faints (N-challenge-4).
- Randomizer texts and trades (N-randomizer-1 to -5); nickname question
  without Nuzlocke (N-w3_nuzlocke-1).

**Hoenn details**
- Battle Frontier only after the S.S. Tidal (A63); shared lottery ticket,
  tent TMs and Scott's flags (A61); further Hoenn calls outside Hoenn
  (N-w3_hoenn-2); Wallace's reward and text (N-w3_hoenn-1, -3).
- Hoenn map section for the Route 111 Trainer Hill and its prize rule
  (A15, O-024, D-044).

**Technical**
- Move reminder in Kanto (A78); Hall of Fame with a region per entry
  (A121).
- Link features: offer and test, or hide (W-core_save-6).
- Tests: MESSAGE tests (A32), `test/text.c` (A94), spread move damage
  (N-tests-3); pin `FLAGS_COUNT`/`VARS_COUNT` (A89).
- Enable GitHub Actions (A37); mdbook docs (N-build_tools-3); the English
  `#else` branch of the gate text (N-johto_story-4); retiring maps listed in
  `check_merge.py` (N-build_tools-1); the storage assert of
  `GetFlagPointer`/`GetVarPointer` also in the beta build, off in
  `make release` (A96).

**Decisions taken during the audit, to be confirmed**
- The Nuzlocke ends at the first Hoenn title (A23); a shiny first
  encounter and battles without a chance to catch use up no area (A83,
  A25).
- Later ship trips to Hoenn do not reset Hoenn and dock in a fixed Hoenn
  harbor (A04, D-029).
- Kanto level caps follow the level ladder (A28); battle partners scale
  like opponents (A21).
- Meditite and Medicham are wild in Hoenn (A16).
- The GS Ball is a key item (A02); Emerald's Trainer Hill on Route 111 is
  made to work instead of being retired (A15).
- English trainer names in Johto took the German names of the first tier
  or of the Kanto/Hoenn version; the Cerulean badge explainer names the
  limits by badge count; the Victory Road Potion moved to (44,11); the
  radio quiz only raises Goldenrod's state; the Route 40 hill pays the
  prize money only with the prize.
- Mints with "Natur-Minzen: Aus" are sold from the first Hoenn title on
  (A85); the HM fallback works with every species randomizer (A119); the
  Origin Jade map edits on Routes 10, 17 and 19 lost in the HnS merge are
  restored (`425eb2fbb1`, can be dropped on its own); Wallace gives HM
  Waterfall if it is missing (T-hoenn_b-3); Elm recognizes the hatched
  Violet City egg also with the randomizer and in the PC (T-johto_a-5);
  after the Farfetch'd search the charcoal master keeps his Team Rocket
  text, also after Kurt's GS Ball scene (T-johto_a-1);
  Johto rematch tiers are filled up to three Pokemon (A72); the places of
  the wild starters (A17); the theater gives Mystic Water to a player who
  kept HM Surf from Kanto (A13); the Kimono Girls' dance runs once per
  visit (T-johto_b-5).

Open questions that stay in `DECISIONS.md`: O-002, O-009, O-012, O-020,
O-021, O-022, O-023, O-024, O-025, O-028; planned items P-001 to P-005.

## Risks

- **No playtest.** Scenes with movement scripts, puzzles (Silph Co.
  teleporters, Seafoam currents, Victory Road boulders, Rocket spin tiles,
  Ice Path, Dragon's Den), battles that can be lost, time of day and luck
  are only modelled or read. Fixes of story state (theater, Azalea, Clair,
  Celebi, Hoenn arrival) are checked statically.
- **SaveBlock1 has 4 bytes left** and EWRAM is at 95 %. 13 more Hoenn flags
  move the vars; more than 60 break the build (D-017). New data goes to
  SaveBlock3 (616 bytes free).
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
  tips were built.
- **CI** never ran on GitHub; the release build has 6 more warnings than
  the baseline the CI checks (LTO and newlib stubs).
- **Link features** are reachable and untested.

## What was not verified

- Any play in an emulator or on hardware: story scenes, puzzle dungeons,
  menus, battles at runtime, graphics, sound, saving and loading. The
  release ROM was built and inspected, not started.
- The checklists of the three test steps (play A to Z, balancing, reach
  everything) of the audit's test matrix.
- The clock at runtime: change of day, weekdays, berries, the fake clock
  preselection.
- Link features (Union Room, trades, Cable Club, Mystery Gift); they
  need two emulators.
- Battle Frontier, Battle Pyramid, Battle Tents, contests, secret bases and
  both Trainer Hills at runtime; the simulator does not model them.
- Randomizer, Nuzlocke and challenge options at runtime: seeds,
  distribution, whiteouts, deaths, nicknames, level caps.
- Balancing in the game; all expected levels come from a model of an
  average player.
- Texts with placeholders (365 estimated over-wide lines) and texts in
  windows of their own (Pokedex, menus).
- Old saves (out of scope), locked content (Sinjoh, Alola, POSTOBC),
  builds with other switches, other toolchains, stack depth.
- The Pokedex area display against the wild tables (D-037).
- A visual check of the changed maps in Porymap (a checklist for the owner
  exists outside the repository).
- The CI workflow on GitHub.
- The 24 untriaged test failures; `make check` in one hydra run.
