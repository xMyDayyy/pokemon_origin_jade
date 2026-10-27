# Origin Jade - decision log

This file records what was decided for Origin Jade, why, and where it lives
in the code. It is meant for everyone who works on the project later, so
that decisions are not undone by accident or argued again from scratch.

## How to use this log

- Every entry has an ID (`D-` decision, `P-` planned but not built,
  `O-` open question). IDs are never reused or renumbered. New entries go at
  the end of their list.
- Status: **Active**, **Superseded** (the entry names its successor),
  **Planned** (decided, not built yet) or **Open** (no decision yet).
- Code that implements a decision should name its ID in a comment, e.g.
  `see docs/origin_jade/DECISIONS.md, D-010`.
- Before changing something listed here, change the entry first (or add a
  new one that supersedes it) and say why.
- Commit IDs in the "Evidence" lines point to the commits in which the
  decision was made or explained. Most of those commit messages are in
  German and explain the reasoning in detail.

The entries up to 2026-09-17 were reconstructed from the full commit
history of the `balancing` branch and the comments in the code. Entries
dated 2026-10-10 or later were decided directly.

---

## Story and world

### D-001 Story order Kanto -> Johto -> Hoenn, Kanto is chapter one
- **Status:** Active (since 2026-08-20)
- **Decision:** The game starts in Pallet Town. Kanto comes from FireRed /
  LeafGreen (its maps now drawn on the HnS layouts), Johto from Heart & Soul,
  Hoenn from Emerald. The HnS version of Kanto is retired (D-019).
- **Rules:** Kanto is the first of three chapters: after the Kanto league
  there are no credits. Oak's farewell scene at the Indigo Plateau ends with
  "come to my lab" and the player waking up at home. The credits belong to
  the end of the whole journey.
- **Evidence:** ff120d4dcf (Kanto merge), 88f9b2863f, 311a0b7f16,
  533a956251, d5b32f3bdd, fb4e3827a5. Version plan: 0.7 Johto started,
  0.8 Johto finished, 0.9 special features (Nuzlocke, randomizer), 1.0
  release after the beta (e2e9ebff45).

### D-002 Home is Pallet Town
- **Status:** Active (2026-10-10). Supersedes the rule
  "New Bark Town once Johto was visited" from a740935891. Changed
  2026-10-15 for Johto, Hoenn and Red (D-028).
- **Decision:** Mom lives in Pallet Town only. The house in New Bark Town
  belongs to a stranger, and Littleroot Town has no player family (Brendan's
  house is Norman's family, May's house is Professor Birch's). After the
  Kanto league the player wakes up at home in Pallet Town. After Johto
  titles and Red the game continues in New Bark Town, after Hoenn titles in
  Littleroot Town, each in front of the professor's lab (D-028).
- **Why:** The player grew up in Pallet Town (intro text), Mom gives the
  PokeCom and the Running Shoes there, her savings menu moved there, the
  wall clock is set there. Waking up in New Bark Town or Littleroot Town
  contradicts all of that.
- **Code:** `EnterHallOfFame` in `src/post_battle_event_funcs.c` (Kanto);
  `setrespawn` in `data/scripts/new_game.inc`; Johto, Hoenn and Red:
  D-028; the respawn fallback in `src/overworld.c`; the Abra teleport "home" in
  `IndigoPlateau_PokemonCenter_hns`. Fly to Littleroot lands in front of the
  lab, not in a bedroom (c41aa5ed17).
- **Evidence:** 91a23faa50 (intro: the player lives in Pallet Town),
  515df62894 / c8104f5e3a / 458db58a02 (Mom in Pallet), e77afc248a (New Bark
  is not home any more, savings moved), 848361320c (wall clock in Pallet),
  23e37d3239 (house interiors swapped), e2383a2ff6 / c6d873d96f (Littleroot
  families), ca0ca34bf4 (Birch sees off "the foreign champion").

### D-003 Rivals and families
- **Status:** Active
- **Decision:** Blue is the rival in Kanto, Silver in Johto, May in Hoenn
  (always May, starter line fixed to Torchic). `{RIVAL}` resolves by region:
  Kanto `rivalNameKanto` (SaveBlock3), Johto `rivalName`, Hoenn May.
  Norman is a regular gym leader, not the player's father.
- **Evidence:** 92afbf1a13, 9163d7dd9f, b751e8ca72, dea50a503c, 3e9cd28737.

### D-004 Arrival in Johto: the Kanto champion is a stranger there
- **Status:** Active (2026-09-08 onwards)
- **Decision:** After the Kanto league Oak asks the player to his lab and
  hands over the GS Ball for Elm (`VAR_JOHTO_HANDOVER`: 0 nothing, 1 Oak
  asked, 2 GS Ball received, 3 delivered to Elm). The way to Johto leads
  through the gatehouse south of Route 23. In Johto nobody knows the player
  except Elm; texts that treated the player as a beginner or as a local were
  rewritten (signs give directions instead of tutorials). Oak is no longer
  at Mr. Pokemon's house; the Johto Pokedex extension comes from Oak right
  after the GS Ball. The adventure and the Nuzlocke start at Oak's Pokedex
  handover in Kanto.
- **Evidence:** 1602e8b729, 6b0d350e04, b01bc5bebb, e77afc248a,
  66c8c06d55, 567810fe2e, e88ed22ac8, 1c01993e43, c904a2d5ab, 9c25e8f5e1,
  3b9309c7f9, d862d25c3d, c7104b184e.

### D-005 Transition logic uses Origin Jade's own state, with catch-ups
- **Status:** Active (2026-09-16)
- **Rule:** Whatever depends on the Kanto -> Johto transition is bound to
  Origin Jade's own vars and flags (e.g. `VAR_JOHTO_ARRIVAL_STATE`,
  `FLAG_JOHTO_ARRIVAL_DONE`, `FLAG_RECEIVED_JOHTO_STARTER`), never to HnS
  states that are set in scenes Origin Jade skips (Mom's house in New Bark
  Town, the HnS game start). Every state change gets a catch-up for saves
  that are already past that point.
- **Evidence:** 198d3db26f, 9e076ee684, fca38d758e, 8613206dde, 112f8d25d8.

## Regions and progression

### D-006 Region rules follow the map section
- **Status:** Active
- **Decision:** The current region is determined at runtime from the map
  section (`GetCurrentRegion`, MAPSEC ranges), not from the build. Region
  rules hang on that: `KantoRulesApply`, `JohtoPermitsApply`,
  `HoennLicensesApply`. Example: Acro Bike tricks only in Hoenn.
- **Evidence:** 0bcda4eed1, 5eee70eda6, e86ff35706, 9163d7dd9f.

### D-007 Badges and titles per region
- **Status:** Active
- **Decision:**
  - Kanto badges are `FLAG_BADGE01_GET`-`FLAG_BADGE08_GET` (FRLG gyms).
  - Johto badges are the bitmask `VAR_JOHTO_BADGES` (`src/johto_badges.c`).
    The Johto gym scripts still set `FLAG_BADGE0x_GET` as well; in Johto
    those flags mean nothing, because the Kanto league set them long before.
  - Hoenn badges are `VAR_HOENN_BADGES` (`src/hoenn_badges.c`).
  - Titles: `FLAG_IS_KANTO_CHAMPION`, `FLAG_IS_JOHTO_CHAMPION`,
    `FLAG_IS_HOENN_CHAMPION`. `FLAG_SYS_GAME_CLEAR` is first set by the Kanto
    league. `FLAG_IS_CHAMPION` is a legacy flag (set by the Johto and Hoenn
    halls of fame) - do not use it for Kanto or Johto logic.
- **Evidence:** f5aa45302b, 20ceec5a1e, 161ede4b96, 9f4cf4bb86.

### D-008 Field moves per region
- **Status:** Active
- **Decision:** Kanto uses the FRLG badge thresholds (Flash 1, Cut 2, Fly 3,
  Strength 4, Surf 5, Rock Smash 6, Waterfall 7). Johto uses permits
  ("Befugnis", `VAR_JOHTO_PERMITS`) handed out by the Johto gym leaders
  (Falkner Rock Smash, Bugsy Cut, Whitney Strength, Morty Surf, Pryce Dive,
  Clair Waterfall). Hoenn uses licenses ("Erlaubnis"). Fly and Flash are not
  locked in Johto and Hoenn. Routes 26, 27 and the Tohjo Falls are exempt
  from the permits: they are walked twice, the first time on arrival.
- **Evidence:** 0bcda4eed1, c569114c6b, 4f711ce15d, f7ec752555,
  71301e75a1, 9c9eac68df, cf857f4e0e.

### D-009 The gatehouse south of Route 23 (four-way junction)
- **Status:** Active
- **Decision:** `ReceptionGate_hns` connects east to Kanto (Route 22 gate,
  needs all eight Kanto badges), south to Johto (opens with
  `FLAG_SYS_GAME_CLEAR`, i.e. after the Kanto league), west to Mt. Silver
  (opens only with `FLAG_IS_JOHTO_CHAMPION` - Red is level 77-93) and north
  to the league (D-010). Each check has its own temp var, so passing one
  does not switch off the others for the rest of the visit. HnS's Black Belt
  in the west corridor steps aside with the Johto title as well (HnS hid him
  with Oak's permission in its retired Kanto).
- **Evidence:** 49ab1eff8b, 4e687ebd9b, 9f4cf4bb86, 1391e9d479,
  4cd0b47231, review 2026-10-09 (one temp var per check), review
  2026-10-11 (Black Belt).

### D-010 The league changes after the eighth Johto badge and the legendary event
- **Status:** Active (2026-10-10, 2026-10-11, 2026-10-12).
- **Decision:** There is one way to the league: the gatehouse north exit,
  Kanto's Route 23 and Victory Road (Moltres), Kanto's Indigo Plateau. The
  league changes once the player holds all eight Johto badges and has
  finished the legendary event at the Ecruteak theater. From then on the
  plateau door leads into Johto's league center instead of Kanto's, also when
  flying there. Kanto's league is gone; should a whiteout bring the player
  into Kanto's center, the guard blocks the Elite Four door with FRLG's
  "closed" line.
  - HnS's Victory Road (`VictoryRoadKanto_*_hns`) is retired again;
    `Route23_hns` is no longer reachable. Its items lie in Kanto's Victory Road
    1F-3F (same flags), placed at random, to be moved in Porymap if needed.
  - Silver's last battle (HnS Victory Road teams) takes place in Johto's
    league center: until it is won he stands on the tile in front of the
    Elite Four door (`VAR_ROUTE27_STATE` < 3).
  - Johto's center leads out onto Kanto's plateau; `IndigoPlateau_hns` is
    only reached by Teleport and connects south to Kanto's Route 23.
- **Story:** the league has changed, as in Gold/Silver: Lance is champion,
  Koga has joined the Elite Four, Lorelei and Agatha are gone. The in-game
  announcement is still to be written.
- **Rules / code:** `PokemonLeague_EventScript_CheckLeagueChanged`
  (`data/scripts/pokemon_league.inc`) is the one condition; the plateau door
  warp is `MAP_DYNAMIC` (`IndigoPlateau_Exterior_EventScript_SetDoorWarp`).
  Silver: `IndigoPlateau_EventScript_SetupSilverFinal`. HnS's checkpoint at
  the south entrance (`ReceptionGate_Trigger`) stays unused: that entrance is
  the way home from Johto to Kanto.
- **Evidence:** decisions 2026-10-10, 2026-10-11 and 2026-10-12 (HnS's
  Victory Road only if needed, Moltres stays in Kanto's; flying must not skip
  Silver); e900a95bad; 9be851b978.

## Balancing

### D-011 Kanto: hand-set level ladder up to 52
- **Status:** Active
- **Decision:** Kanto's levels are set by hand and end with the champion at
  52; legendaries at most 40. Teams rise monotonically, at most two levels
  below the ace; route trainers sit 3-5 levels below the next boss. The
  Exp. Share is on from the start and the level band is tuned for it
  (`B_SPLIT_EXP` Gen 5). Obedience for traded Pokemon follows the number of
  Kanto badges (10, then +5 per badge, 50 with eight); after the Johto
  title every Pokemon obeys (D-031). Kanto's Elite Four rematch teams are
  also capped at 52. After the Kanto title Kanto scales to the player and
  these hand-set levels are the floor (D-031).
- **Evidence:** b20f555d4d, 20fa75b584, 1662b679fc, 2f349b5ce2, af10c86033.

### D-012 Johto and Hoenn: dynamic level scaling
- **Status:** Active
- **Decision:** Johto and Hoenn scale to the player (`src/level_scaling.c`,
  `include/config/johto_scaling.h`): Johto corridors 45-80 (Mt. Silver
  70-90, Red unscaled), trainers anchor -3..+2, bosses +3 (Hoenn +5, it is
  the final region). The arrival corridor has the full band. Johto's gym
  leaders have six Pokemon; route trainers at least three
  (`tools/fill_johto_parties.py`: trainer class beats the local wild pool,
  duplicate a Pokemon rather than break the class). Rematch teams scale
  as well (every stage is below level 77); HnS's badge gate for rematch
  stages (`GetMaxRematchStageForBadges`) is off because the Kanto title is
  set before Johto. After a region's title its corridor ceilings become
  100 (D-031).
- **Evidence:** e900a95bad, 8f0e70b65c, 1685acfbc7, e1fde77aa4,
  cf857f4e0e, f549506494, e936f02c84, c239d59e43, 20a176b3af, c16d35c5aa.

### D-013 Kanto is complete without trading
- **Status:** Active
- **Decision:** All 185 species of the Gen-1 families are obtainable in
  Kanto without link trades: both fossils at Mt. Moon, both Hitmons at the
  dojo, evolution items placed in Kanto, the unchosen starters in the wild
  (5 %), two-slot day care with breeding, extra Game Corner prizes. Day and
  night replace the FireRed/LeafGreen version split. Overworld Pokemon show
  what can be caught on a map (next to, not on, the encounter tiles).
- **Evidence:** 71a79b3a14, ff6d47ca45, ead606af10, 7aacaa2699,
  d8f26d241e, d0e2cc9ec4, 2d0e6a62af, 00da4d2a7a, 535f47948b, 5578b2caee.

### D-014 HM handovers in Johto never leave the player empty-handed
- **Status:** Active
- **Decision:** A player from Kanto already owns most HMs. Every HM handover
  checks for the HM; if it is already owned, there is a different reward
  with an in-world reason - never "then I have nothing for you". Exploring
  has to pay off.
- **Exception:** Waterfall and Whirlpool do not exist in Origin Jade's Kanto
  (no active Kanto map hands them out). They stay regular Johto finds: the
  ball on the Ice Path holds Waterfall, and Lance hands over Whirlpool in the
  Rocket Hideout. Waterfall can only be used with Clair's permit (D-008).
- **Evidence:** 09aac39e14, 5b0269166d, f9bd3e5021 (Waterfall, Whirlpool).

### D-015 Kanto's Elite Four rematch after the Kanto title
- **Status:** Active (2026-10-10)
- **Decision:** After the Kanto title the Kanto Elite Four use their
  rematch teams, matching the rematch texts that already showed. FRLG picked
  the teams by `FLAG_IS_CHAMPION`, which only FRLG's postgame (One Island)
  sets. The rematches end when the league changes (D-010).
- **Evidence:** review 2026-10-09, decided 2026-10-10.

## Data, saves and maps (technical conventions)

### D-016 Flags and vars
- **Status:** Active
- **Rules:**
  - New Origin Jade flags and vars come only from
    `include/constants/flags_origin_jade.h` and `vars_origin_jade.h`
    (stored in SaveBlock3, sections per region with reserves).
  - Existing numbers are never renumbered. When two names collide, the
    Hoenn / Origin Jade side moves; HnS keeps its numbers, so HnS merges
    stay conflict-free. If both regions use the same *name*, the Hoenn
    scripts get a name of their own (example: Devon's fossil revival,
    `VAR_HOENN_FOSSIL_RESURRECTION_STATE`).
  - Run `tools/check_flags.py` after every HnS merge. The compiler does not
    report two names on one number.
  - Hidden-item flags must lie inside the 13-bit window above
    `FLAG_HIDDEN_ITEMS_START`; the FRLG flag block therefore sits at 0x1000.
    FRLG trainer flags are redirected by `TrainerIdToFlagId`.
  - `FLAG_TEMP_x` on cut trees and boulders is correct (hidden for the
    current visit); hidden items need real flags.
- **Evidence:** 9a12676bc2, c2cbd316ad, 5dbd22cc65, 5bda779144,
  f89324b8d2, 42058c2f69, 2e9792740c.

### D-017 Saves and migrations
- **Status:** Active
- **Rules:** The save layout freezes with the release; until then it may
  grow deliberately (2cbf85903d). One-time migrations of Origin Jade run in
  `LoadGameSave` (`src/save.c`) and are keyed to a flag from the Origin Jade
  block, which new games set right away - never through `SAVE_VERSION`:
  that number belongs to HnS upstream and is bumped there.
- **Evidence:** 2cbf85903d, 9635b02081, 2026-10-10 (Johto starter var).

### D-018 Maps and layouts
- **Status:** Active
- **Rules:**
  - Never remove a map from `map_groups.json` or a layout from
    `layouts.json`; append new ones at the end. Map and layout indices are
    stored in save files.
  - Retire content with a `game_version` other than `"hns"` - in **both**
    `map.json` and `layouts.json`. `mapjson` then emits NULL silently,
    without a build error.
  - `layout_version` must match the tilesets' attribute width (`frlg`
    32-bit, `hns` 16-bit). Porymap may rewrite attribute files in the wrong
    width.
  - `data/event_scripts.s` is a hand-maintained include list.
  - Local IDs must be unique per map; Porymap may drop `local_id` fields or
    add stub entries to `region_map_sections.json`.
- **Evidence:** 7c35866292, fcb615fbb6, 68c800eb29, 36c1841e2c,
  c95ae0fbcb, 97f2d54743, 4d57e6d6dc, 6f8f66dd8c, 35b22a81e7, e14f493887.

### D-019 Retired and locked content
- **Status:** Active
- **Decision:** HnS's own Kanto maps are retired (`hns_kanto_retired`); the
  FRLG Kanto maps are used. The Sevii Islands are retired, reversibly
  (`frlg_sevii_retired`); everything that would lead there is disabled (Bill
  after Blaine, the Indigo Plateau guard's Sevii branch). The Sinjoh content
  is locked by `SINJOH_CONTENT_AVAILABLE` in `include/config/general.h`.
- **Evidence:** 752b880dee, 67c1384191, 82f533ac08, 020c34f826,
  84e198c40c, ba8f5e9168, review 2026-10-09.

## Language and upstream

### D-020 Language, comments and game text
- **Status:** Active
- **Rules:**
  - Comments are English (since 2026-10-09).
  - The German build never shows English game text. Changes to game text
    go into the `#if GERMAN` branch; the English branch is only adapted to
    match.
  - German texts follow the official German games (source cascade in
    1767d31fe6). Real umlauts and ß, no "ae/oe/ue/ss" substitutes. Title
    case, no all-caps.
  - Pixel limits: text box 208 px, PokeNav call box 192 px
    (`check_pokenav_text.py`).
  - Debug menu texts stay English.
- **Evidence:** 1767d31fe6, 6736e18718, 61504582b3, 652123e252,
  c7104b184e, d1a2067c84.

### D-021 Upstream policy
- **Status:** Active
- **Decision:** HnS (pokemonHnS-backup) is taken over as a three-way diff,
  because the branches share no history. In conflicts: translations and
  Origin Jade's design stay ours, upstream wins where the build needs it,
  otherwise combine. From pokeemerald-expansion, individual fixes are ported
  (with a comment naming the upstream PR); a merge of 1.16/1.17 is not
  planned for now (large incompatible refactors).
- **Evidence:** 007b3968fc, 4784435413, b0a460c224, 6a6a4fcaec,
  c3c361d4b4, cc58e0c648, review 2026-10-09.

### D-022 Moltres exists once, in Kanto
- **Status:** Active (2026-10-11)
- **Decision:** Moltres can only be met on Kanto's Victory Road 4F
  (`VictoryRoad_4F_Frlg`, level 40, `FLAG_HIDE_MOLTRES_KANTO`; D-013).
  HnS's second Moltres on Mt. Silver (`MtSilver_1F_MoltresRoom_hns`, level
  50, `FLAG_HIDE_MOLTRES`) is removed - otherwise it could be caught twice.
  Its object stays in map.json (so old saves made in the room find their
  template) but never spawns and never battles. Kanto's Victory Road stays
  reachable after the league change (D-010), so Moltres cannot be missed by
  the change; catching, knocking out and fleeing follow D-026.
- **Evidence:** decision 2026-10-11.

### D-023 Randomizer without a GEN SCOPE row
- **Status:** Active
- **Decision:** HnS's GEN SCOPE option (randomizer pool limited to Gen 1-3
  families) stays in the code and the save, but has no row in the challenge
  menu and is off (`RANDOMIZER_DEFAULT_GEN_SCOPE_1_3` FALSE in
  `include/config/randomizer.h`). Gen 4-9 and the regional forms are off in
  `species_enabled.h`, so both settings give the same pool.
- **Evidence:** b0a460c224, 6a6a4fcaec, c3c361d4b4. The row came in with
  6a6a4fcaec, the default TRUE with cc58e0c648; both reverted 2026-10-12.

### D-024 Goldenrod's radio quiz gives the Magnet Train pass
- **Status:** Active (2026-10-12, prize changed 2026-10-15)
- **Decision:** The radio card comes from the Viridian tutorial and stays:
  Goldenrod's first-visit flag heap no longer clears `FLAG_ENABLE_RADIO`.
  The radio tower quiz stays; its prize is the Pass (Fahrschein) for the
  Magnet Train (D-029). Whitney in the radio
  tower and the receptionist's offer depend on
  `FLAG_WON_GOLDENROD_RADIO_QUIZ`; the Beauty at the gym door stays on
  `FLAG_HIDE_GOLDENROD_BEAUTY`. Johto radio stations only play the Rocket
  broadcast during the takeover (Goldenrod state 6 until
  `FLAG_HIDE_GOLDENROD_ROCKETS` is set again). Older saves are migrated in
  `LoadGameSave` (`FLAG_MIGRATED_GOLDENROD_FLAG_HEAP`); saves that already
  won the quiz keep the radio card as their prize. The Pass is a key item;
  the item randomizer leaves it alone. The quiz answers stay as in HnS:
  question 3 (does Kurt use Aprikoko?) is answered No, Kurt uses berries.
- **Evidence:** decision 2026-10-12 (O-005); quiz answers 2026-10-20.

### D-025 Radio stations by region and progress
- **Status:** Active (2026-10-13)
- **Decision:** The radio card from Viridian makes the radio work in Kanto
  right away; Johto programmes start with the radio tower quiz.
  - Kanto (Kanto mapsecs): Oak's Pokemon Talk with Kanto routes and only
    the Clefairy report (FRLG has no radio of its own, so there are no
    other Kanto reports), the Pokedex show in the morning, Orte und Personen
    (Kanto places and Kanto trainers the player has beaten, no leaders,
    Elite Four, champion, rivals, Giovanni or Oak), Let's All Sing and the
    Poke Flute.
  - Johto (Johto mapsecs) from `FLAG_WON_GOLDENROD_RADIO_QUIZ`: Oak's
    Pokemon Talk with Johto routes and reports, the Pokedex show, Pokemon
    Music, the Lucky Channel (it announces the lottery clerk's number) and
    Buena's Password. The Sudowoodo report runs until Sudowoodo is gone, the
    red Gyarados report after the first visit to the Lake of Rage; the
    Lavender radio tower report never runs (the Pokemon Tower is still a
    tower in Origin Jade).
  - Unown and the Mahogany signal stay tied to their places; the Rocket
    broadcast replaces the Johto programmes during the takeover, only in
    Johto. Kanto stations are silent in Johto and Hoenn, Johto stations in
    Kanto and Hoenn. Hoenn Sound is removed: Hoenn is a region of its own.
  - Code: `IsStationAvailable`, `IsOPTReportAvailable` and `PickPnPTrainer`
    in `src/pokenav_radio.c`.
- **Evidence:** decision 2026-10-13 (O-016).

### D-026 Legendary rules: caught means gone for good
- **Status:** Active (2026-10-15)
- **Decision:** All one-time encounters share one table
  (`src/legendaries_oj.c`, ids in `include/constants/legendaries_oj.h`):
  Articuno, Zapdos, Moltres, Mewtwo, Mew (Mt. Moon only), Lugia, Ho-Oh,
  Celebi, Suicune, Deoxys (HnS Birth Island only), Union Cave Lapras, the red
  Gyarados, Entei, Raikou, Regirock, Regice, Registeel, Groudon, Kyogre,
  Rayquaza, Latias and Latios.
  - Caught: never again. The battle outcome sets the caught flag, not the
    Pokedex (the randomizer changes species).
  - Knocked out: back after every league victory - Kanto titles while the
    Kanto league exists, every Johto and Hoenn title
    (`Common_EventScript_ReviveDefeatedLegendaries` in all three halls of
    fame).
  - Fled: back after three RTC day changes (2-bit counters in
    `VAR_LEGENDARY_FLEE_KANTO/JOHTO/HOENN`, `UpdatePerDay`). Roamers keep
    roaming.
  - Each map decides on entry (`IsLegendaryAvailable`). Story battles
    (Lugia, Ho-Oh, Celebi, red Gyarados) move the story on whatever the
    outcome.
  - The Lugia or Ho-Oh not chosen on Route 39 appears after the first Johto
    title once the chosen one is caught (level 70; the chosen one keeps 50).
    Route 41's Tentacruel then step aside for Ho-Oh choosers.
  - Latias and Latios both roam Hoenn after the first Hoenn title (level 40,
    Emerald routes). No Latias roams Kanto or Johto. Faraway Island,
    Southern Island and Navel Rock are not offered anywhere.
  - Levels stay fixed. Sudowoodo and Snorlax never return. The GS Ball is
    used up at the shrine; there is no second Celebi.
- **Evidence:** decision 2026-10-15 (O-004).

### D-027 Suicune waits in Johto's Glockenturm
- **Status:** Active (2026-10-15)
- **Decision:** Suicune's story stays in Johto. After both Johto sightings
  (Cianwood and Route 42, `VAR_SUICUNE_ENCOUNTERS` 3) Suicune waits on the
  Glockenturm's ground floor (`TinTower_1F_hns`, level 50, talk to it) and
  follows D-026. Eusine points there at the second sighting and appears after
  the first knockout or catch (var 8). The Ecruteak sages let holders of
  either bell in (Klarglocke or Gischtglocke), so Lugia and Ho-Oh choosers
  reach it after the theater. HnS's Kanto part stays retired.
- **Evidence:** decision 2026-10-15.

### D-028 Leagues: farmable, continue in the region, credits at the end
- **Status:** Active (2026-10-15). Replaces D-002 for Johto, Hoenn and Red.
- **Decision:**
  - Johto's league can be repeated: the Black Belt in front of the Elite
    Four door never shows. Title defences use the `_2` teams, a short Lance
    scene (no Mary, no Oak) and a Hall of Fame text without Kanto; HnS's
    `SetGameClearFlags` is gone.
  - Kanto's league can be repeated until the league change (D-010, D-015).
    Hoenn's league can be repeated; later Hoenn titles skip May and Birch.
  - After every Johto title and after Red: Hall of Fame (saves), no credits,
    the game continues in New Bark Town in front of Elm's lab
    (`HEAL_LOCATION_NEW_BARK_TOWN_LAB_HNS`). After every Hoenn title it
    continues in Littleroot Town in front of Birch's lab.
  - The credits roll once, at the first Hoenn title, the end of the game
    (`FLAG_ROLLED_ENDING_CREDITS`).
  - Silver waits in Johto's league center for a daily battle after the Johto
    title. `{RIVAL}` shows Silver's name on Johto's league maps.
  - Code: `special GameClearNoCredits` (`src/post_battle_event_funcs.c`),
    `HallOfFame_SetRollCredits` (`src/hall_of_fame.c`).
- **Evidence:** decision 2026-10-15 (O-013).

### D-029 Magnet Train, radio quiz and ships
- **Status:** Active (2026-10-15, ships changed 2026-10-20)
- **Decision:**
  - Kanto has one way into Johto: the gatehouse (D-009). Flying between the
    regions opens with the first Johto visit.
  - The Magnet Train runs once the player has the Pass, the prize of
    Goldenrod's radio quiz (D-024). Both stations only check the Pass; there
    is no power plant quest.
  - The M.S. Anne lies in Vermilion until the player has HM Cut. Afterwards
    no ship calls at Vermilion until the first Johto title; the dock ferry
    is gone.
  - After the first Johto title the M.S. Aqua sails. Its first trip is the
    maiden voyage from Olivine to Vermilion; afterwards both ports offer the
    other port, the Kampfzone, Entstehungsinsel (with the Aurora Ticket) and
    Hoenn (unchanged, O-002). The M.S. Aqua sails every day from both ports.
  - The sailors at the Kampfzone and on Birth Island sail to Olivine,
    Vermilion or Hoenn. The Hoenn entry has the ports' condition (Johto
    title, maiden voyage done) and uses `Common_EventScript_SailToHoenn`.
  - The woman in Olivine City gives the Aurora Ticket only after the Johto
    title (`FLAG_IS_JOHTO_CHAMPION`).
  - Faraway Island and Southern Island are not offered.
- **Evidence:** decision 2026-10-15 (O-003); daily ship, return trips to
  Hoenn and Aurora Ticket 2026-10-20.

### D-030 One Battle Frontier: the HnS Kampfzone
- **Status:** Active (2026-10-15)
- **Decision:** The Emerald frontier (47 maps, 36 layouts) is retired
  (`frontier_em_retired`). The HnS Kampfzone is reached by ship (D-029) and,
  after the Hoenn title, from Slateport and Lilycove. It is only on the
  Johto/Kanto region map. The Artisan Cave is bound to the HnS Kampfzone and
  counts as part of it (`MAPSEC_BATTLE_FRONTIER`); unlike HnS its door in the
  Kampfzone is open (ledge corner at (29,9), the Engineer beside the path;
  owner confirmed 2026-10-26).
  A whiteout there leads to the Kampfzone's nurse.
- **Evidence:** decision 2026-10-15 (O-006).

### D-031 Level scaling after a region's title
- **Status:** Active (2026-10-15)
- **Decision:** After a region's title its trainers (rematches included) and
  wild Pokemon scale to the player's anchor without a ceiling (level 100).
  - Kanto: FRLG maps, off before `FLAG_IS_KANTO_CHAMPION`; no corridors, the
    hand-set level (D-011) is the floor, the band is Johto's, trainer
    Pokemon evolve (`include/config/kanto_scaling.h`).
  - Johto and Hoenn: corridor ceilings become 100 with
    `FLAG_IS_JOHTO_CHAMPION` / `FLAG_IS_HOENN_CHAMPION`; floors stay.
  - Fixed: static and scripted encounters and roamers (D-026), Red, the
    facilities. Steven at Meteor Falls (level 75-78) stays fixed as the
    owner set it before (876c3d4c19, Hoenn's counterpart to Red,
    `HOENN_SCALING_FIXED_MIN_LEVEL` 70); setting it to 79 lets only him
    scale.
  - After the Johto title every Pokemon obeys, traded ones too (Johto badge
    limits: P-003).
- **Evidence:** decision 2026-10-15; Steven: 876c3d4c19.

### D-032 Johto content after the title, Janina in Fuchsia, Blue in Viridian
- **Status:** Active (2026-10-15, Blue added 2026-10-20)
- **Decision:**
  - The eight Johto gym leaders accept rematches in their gyms after the
    Johto title, without limit, with their `_2` teams (money only).
  - Jasmine offers her Steelix ("Beißer") in a trade after the title, until
    the trade is done.
  - After the league change (D-010) Koga is only in Johto's Elite Four:
    Janina leads the FRLG Fuchsia gym (`TRAINER_JANINE_HNS`, TM Gifthieb
    once, rematches, no badge).
  - After the league change Blue leads the FRLG Viridian gym
    (`TRAINER_BLUE_HNS`, HnS's Viridian team, TM Bizarroraum once via
    `FLAG_GOT_TM_TRICK_ROOM_FROM_BLUE`, rematches without limit, money only,
    no badge). He carries the player-chosen Kanto rival name (D-003).
    Giovanni is hidden after the change once he has handed over HM06; before
    the change the gym is unchanged.
  - HnS's signposts (Clair, Janine and the other leaders) and the Fighting
    Dojo's VIP room stay off: they would need return trips into Kanto.
  - Mt. Moon B3F's three item balls hold Top-Genesung, Top-Trank and
    Top-Beleber (O-007).
- **Evidence:** decision 2026-10-15 (O-014); Blue 2026-10-20 (O-018).

### D-033 Weekdays
- **Status:** Active (2026-10-15, changed 2026-10-20)
- **Decision:** Weekday content follows the RTC (`special GetWeekday`,
  `src/weekday_oj.c`).
  - Bug-Catching Contest: Tuesday, Thursday and Saturday, once per day.
    Only a judged contest uses up the day; retiring without a catch or
    whiting out lets the player enter again the same day.
  - Not weekday-bound: Union Cave's Lapras (D-026), the M.S. Aqua (D-029).
- **Evidence:** decision 2026-10-15; contest day 2026-10-20.

---

## Planned, not built yet

- **P-001** The son of the woman who now lives in the New Bark Town house is
  meant to appear later as a trainer (e77afc248a).
- **P-002** The wall clock tile in the Pallet Town house is still missing;
  `PalletTown_PlayersHouse_2F_EventScript_WallClock` waits for it
  (848361320c, 9e22901516).
- **P-003** Obedience limits of their own for Johto ("in Johto eigene
  Grenzen", af10c86033). Until then the table ends at level 50 after the
  eighth Kanto badge; after the Johto title every Pokemon obeys (D-031).
- **P-004** Baoba's Safari Zone call should come back through his own quest
  line (5f794c19fd, 0bee0d524b).
- **P-005** Mom's three call texts still describe Hoenn milestones and should
  be re-hung for Kanto/Johto.

## Open questions

- **O-001** Resolved 2026-10-11: the league has changed (D-010).
- **O-002** Hoenn Ticket: no source in the game except the debug menu. The
  story after the ticket exists but does not fit the earlier system; it
  will be redesigned (2026-10-10). Do not implement in the meantime.
- **O-003** Resolved 2026-10-15 (D-029).
- **O-004** Resolved 2026-10-15 (D-026).
- **O-005** Resolved 2026-10-12: Kanto never sets Bill's PC flag, the
  Celadon Eevee no longer sets Bill's `FLAG_GOT_EEVEE`, and the radio card
  stays (D-024).
- **O-006** Resolved 2026-10-15 (D-030).
- **O-007** Resolved 2026-10-15 (D-032).
- **O-008** Shiny Charm / Oval Charm currently have no source.
- **O-009** Enabling Sinjoh also needs the Gen 4+ and regional forms in
  `species_enabled.h`.
- **O-010** Resolved 2026-10-12: the Route 30 and Route 26 trees use the
  reserve slots `BERRY_TREE_ROUTE_30_ORAN` and `BERRY_TREE_ROUTE_26_SITRUS`;
  slot 33 is only shared with retired maps. Older saves are migrated in
  `LoadGameSave` (`FLAG_MIGRATED_JOHTO_BERRY_SLOTS`).
- **O-011** Kanto starter preview: the preview can roll a shiny, but Oak's lab
  hands out a regular Pokemon (the preview rolls for `VAR_STARTER_MON` 0,
  which Oak's lab only sets after the handover).
- **O-012** Text debt: 172 Johto texts without a German branch (346072a202);
  4951 German HnS lines wider than 216 px (652123e252).
- **O-013** Resolved 2026-10-15 (D-028).
- **O-014** Resolved 2026-10-15: Silver's daily battle (D-028), gym rematches
  and Janina in Fuchsia (D-032). The signposts and the Dojo VIP room stay off.
- **O-015** Text slips found 2026-10-11: the gatehouse's
  `ReceptionGate_Text_LeagueDenied` writes "duerfen"/"Siegesstrasse"; Kanto's
  Lance says "Es ist... {PLAYER}! Auch er hat die Top Vier besiegt!" where
  the rival is meant; Will says "Elite Vier"; typos in Johto's
  `IndigoPlateau_EventScript_ShigyNinja` text; Route 28 has English text
  only; Johto's Oak says "Es ist lange her" after the Johto title although he
  handed over the GS Ball shortly before; the ship is "M.S. Anne" in FRLG's
  German texts but "S.S. Anne" in Vermilion's port texts
  (`VermilionCity_PortInside_*`) and on the region map; Camper Todd's call
  (`data/text/match_call_hns.inc`) says "Rosalia-Arena" for Goldenrod's gym.
- **O-016** Resolved 2026-10-13: the radio works in Kanto (D-025).
- **O-017** Resolved 2026-10-13: Hoenn Sound stays off (D-025); the
  PokeCom's "Zustand" from the radio card on and Buena's hint before the
  quiz stay as they are.
- **O-018** Resolved 2026-10-20: Blue leads the Viridian gym after the
  league change (D-032).

## Superseded decisions (kept for the record)

| Old decision | Where | Replaced by |
|---|---|---|
| After Johto was visited, the player wakes up in New Bark Town after a league | a740935891, `GameClear` | D-002 (2026-10-10) |
| HnS's Victory Road maps retired, the FRLG Victory Road replaces them | 4e687ebd9b | D-010 (2026-10-10) |
| Daisy hands over the PokeGear | a5475129c4 | Mom gives the PokeCom (515df62894) |
| Field moves in Johto follow the badge flags | HnS / 0bcda4eed1 | Johto permits (71301e75a1) |
| Mt. Silver opens with `FLAG_SYS_GAME_CLEAR` | HnS | `FLAG_IS_JOHTO_CHAMPION` (4cd0b47231) |
| `FLAG_IS_CHAMPION` is the Johto title | 4d33757ced | `FLAG_IS_JOHTO_CHAMPION` (f5aa45302b) |
| Johto starts in Mom's house in New Bark Town | HnS | D-004 |
| A second Moltres on Mt. Silver | HnS | D-022 (2026-10-11) |
| North exit leads to HnS's Victory Road after the league change | D-010 (2026-10-10) | D-010 (2026-10-12) |
| After every league (Johto, Hoenn, Red too) the player wakes up in Pallet Town | D-002 (2026-10-10) | D-028 (2026-10-15) |
| Credits after the Johto title and after Red | HnS | D-028 (2026-10-15) |
| Goldenrod's radio quiz gives a Master Ball | D-024 (2026-10-12) | D-024 / D-029 (2026-10-15) |
| Legendaries come back after Johto's second Hall of Fame, caught or not | HnS | D-026 (2026-10-15) |
| A knocked-out Moltres is gone for good | D-022 (2026-10-11) | D-026 (2026-10-15) |
| The M.S. Aqua sails on two weekdays per port | D-029 / D-033 (2026-10-15) | D-029 (2026-10-20) |
| Entering the Bug-Catching Contest uses up the day | D-033 (2026-10-15) | D-033 (2026-10-20) |
