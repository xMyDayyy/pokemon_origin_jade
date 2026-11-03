# Origin Jade - decision log

This file records what was decided for Origin Jade, why, and where it lives
in the code. It is meant for everyone who works on the project later, so
that decisions are not undone by accident or argued again from scratch.

## How to use this log

- Every entry has an ID (`D-` decision, `P-` planned but not built,
  `O-` open question). IDs are never reused or renumbered. New entries go at
  the end of their list. Work packages reserve O- ids before they are
  integrated; reserved ids a package did not use stay unused and are
  never assigned later (O-042 to O-044, O-046 to O-049, O-051 to O-054,
  O-059, O-061, O-062, O-064, O-071, O-072).
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
  2026-10-15 for Johto, Hoenn and Red (D-028), changed 2026-10-31 (the
  continue point after the Kanto league, the Johto titles and Red is the
  player's room; Mom's calls).
- **Decision:** Mom lives in Pallet Town only. The house in New Bark Town
  belongs to a stranger, and Littleroot Town has no player family (Brendan's
  house is Norman's family, May's house is Professor Birch's). After the
  Kanto league the player wakes up in their room in Pallet Town, also when
  the game is restarted after the Hall of Fame has saved
  (`HEAL_LOCATION_PALLET_TOWN_PLAYERS_ROOM`); a whiteout from there still
  leads to Mom on the ground floor. The same holds after every Johto title
  and after Red. After Hoenn titles the game continues in Littleroot Town
  in front of Birch's lab (D-028).
- **Why:** The player grew up in Pallet Town (intro text), Mom gives the
  PokeCom and the Running Shoes there, her savings menu moved there, the
  wall clock is set there. Waking up in New Bark Town or Littleroot Town
  contradicts all of that.
- **Code:** `EnterHallOfFame` in `src/post_battle_event_funcs.c` (Kanto),
  the room's heal location at the end of `src/data/heal_locations.json`
  and in `IsLastHealLocationPlayerHouse` (`src/heal_location.c`);
  `setrespawn` in `data/scripts/new_game.inc`; Johto, Hoenn and Red:
  D-028; the respawn fallback in `src/overworld.c`; the Abra teleport "home" in
  `IndigoPlateau_PokemonCenter_hns`. Fly to Littleroot lands in front of the
  lab, not in a bedroom (c41aa5ed17).
- **Mom's calls:** her PokeCom calls follow the journey (`sMomTextScripts`
  in `src/pokenav_match_call_data.c`, last set flag wins). In Kanto and
  Johto she talks about Pallet Town (`MatchCall_Text_Mom2`, from the moment
  she hands over the PokeCom), from the arrival in Hoenn
  (`FLAG_VISITED_LITTLEROOT_TOWN`) about Hoenn, after the Hoenn title
  (`FLAG_IS_HOENN_CHAMPION`) about three leagues and Oak. Her lines start
  with "Mama:" like her PokeCom name. Mom2 and Mom3 are drafts for the
  owner to review; Mom2 ("ich höre ja von deinen Erfolgen") also plays
  before the first badge.
- **Evidence:** 91a23faa50 (intro: the player lives in Pallet Town),
  515df62894 / c8104f5e3a / 458db58a02 (Mom in Pallet), e77afc248a (New Bark
  is not home any more, savings moved), 848361320c (wall clock in Pallet),
  23e37d3239 (house interiors swapped), e2383a2ff6 / c6d873d96f (Littleroot
  families), ca0ca34bf4 (Birch sees off "the foreign champion").

### D-003 Rivals and families
- **Status:** Active (changed 2026-10-31)
- **Decision:** Blue is the rival in Kanto, Silver in Johto, May in Hoenn
  (always May, starter line fixed to Torchic). `{RIVAL}` resolves by region:
  Kanto `rivalNameKanto` (SaveBlock3), Johto `rivalName`, Hoenn May.
  Norman is a regular gym leader, not the player's father; what people in
  Hoenn know about the player is ruled in D-048.
- **Evidence:** 92afbf1a13, 9163d7dd9f, b751e8ca72, dea50a503c, 3e9cd28737.

### D-004 Arrival in Johto: the Kanto champion is a stranger there
- **Status:** Active (2026-09-08 onwards, GS Ball changed 2026-10-30)
- **Decision:** After the Kanto league Oak asks the player to his lab and
  hands over the GS Ball for Elm (`VAR_JOHTO_HANDOVER`: 0 nothing, 1 Oak
  asked, 2 GS Ball received, 3 delivered to Elm). The way to Johto leads
  through the gatehouse south of Route 23. In Johto nobody knows the player
  except Elm; texts that treated the player as a beginner or as a local were
  rewritten (signs give directions instead of tutorials). Oak is no longer
  at Mr. Pokemon's house; the Johto Pokedex extension comes from Oak right
  after the GS Ball. The adventure and the Nuzlocke start at Oak's Pokedex
  handover in Kanto.
- **Rules:** The GS Ball is a key item: it cannot be sold, tossed, stored
  or thrown, so it always reaches Elm. Celebi's shrine asks for it
  (`checkitem`, D-026).
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
- **Status:** Active (badge readers changed 2026-11-02, D-053)
- **Decision:**
  - Kanto badges are `FLAG_BADGE01_GET`-`FLAG_BADGE08_GET` (FRLG gyms).
  - Johto badges are the bitmask `VAR_JOHTO_BADGES` (`src/johto_badges.c`).
    The Johto gym scripts still set `FLAG_BADGE0x_GET` as well; in Johto
    those flags mean nothing, because the Kanto league set them long before.
  - Hoenn badges are `VAR_HOENN_BADGES` (`src/hoenn_badges.c`).
  - Badge readers count the badges of the region the player stands in
    (`GetCurrentRegionBadgeCount`, `src/caps.c`; D-053): the rematch
    stages (D-012), match calls (`HasEnoughBadgesForRematch`, Hoenn's
    battle requests), the Gen 9 catch malus, the challenge menu's
    trainer IV/EV tables, and the continue window (the region of the
    saved map). The save menu shows the badges of all regions; obedience
    (P-003) and the level-cap challenge (D-011) stay on Kanto's badges.
  - Titles: `FLAG_IS_KANTO_CHAMPION`, `FLAG_IS_JOHTO_CHAMPION`,
    `FLAG_IS_HOENN_CHAMPION`. `FLAG_SYS_GAME_CLEAR` is first set by the Kanto
    league; Hoenn post-game checks use `FLAG_IS_HOENN_CHAMPION` (D-040).
    `FLAG_IS_CHAMPION` is a legacy flag (set by the Johto and Hoenn
    halls of fame) - do not use it for Kanto or Johto logic.
- **Evidence:** f5aa45302b, 20ceec5a1e, 161ede4b96, 9f4cf4bb86.

### D-008 Field moves per region
- **Status:** Active (changed 2026-10-30: notes on Victory Road, Whirlpool
  and New Bark Town)
- **Decision:** Kanto uses the FRLG badge thresholds (Flash 1, Cut 2, Fly 3,
  Strength 4, Surf 5, Rock Smash 6, Waterfall 7). Johto uses permits
  ("Befugnis", `VAR_JOHTO_PERMITS`) handed out by the Johto gym leaders
  (Falkner Rock Smash, Bugsy Cut, Whitney Strength, Morty Surf, Pryce Dive,
  Clair Waterfall). Hoenn uses licenses ("Erlaubnis"). Fly and Flash are not
  locked in Johto and Hoenn. Routes 26, 27 and the Tohjo Falls are exempt
  from the permits: they are walked twice, the first time on arrival.
- **Notes (as built):**
  - Kanto's Victory Road needs Rock Smash. On `VictoryRoad_1F_Frlg` the
    breakable rocks at (7,19) and (6,10) (752eca56bd) close the way from
    Route 23 to the ladder up to 2F. HM06 comes only from Giovanni with the
    eighth badge (`ViridianCity_Gym_Frlg`), so the order holds; moving HM06
    or these rocks changes it.
  - Whirlpool has no permit. The whirlpools (Route 41, Dragon's Den) open
    with the seventh Johto badge (Pryce) alone; neither the HM nor a
    Pokemon that knows Whirlpool is checked (`EventScript_Whirlpool`,
    `data/scripts/field_move_scripts_hns.inc`).
  - New Bark Town's east shore is the town's own water, not the exempt
    Route 27. On foot the way back east to Route 27 and Kanto therefore
    opens with Morty's Surf permit; before that only Fly leads back.
- **Evidence:** 0bcda4eed1, c569114c6b, 4f711ce15d, f7ec752555,
  71301e75a1, 9c9eac68df, cf857f4e0e.

### D-009 The gatehouse south of Route 23 (four-way junction)
- **Status:** Active (Johto exit changed 2026-10-30; Red's level changed
  2026-11-02, D-053)
- **Decision:** `ReceptionGate_hns` connects east to Kanto (Route 22 gate,
  needs all eight Kanto badges), south to Johto (opens with
  `FLAG_SYS_GAME_CLEAR`, i.e. after the Kanto league; while
  `VAR_JOHTO_HANDOVER` is 1 the guard sends the player to Oak for the GS
  Ball first, D-004), west to Mt. Silver
  (opens only with `FLAG_IS_JOHTO_CHAMPION` - Red's team is level 100) and north
  to the league (D-010). Each check has its own temp var, so passing one
  does not switch off the others for the rest of the visit. HnS's Black Belt
  in the west corridor steps aside with the Johto title as well (HnS hid him
  with Oak's permission in its retired Kanto).
- **Evidence:** 49ab1eff8b, 4e687ebd9b, 9f4cf4bb86, 1391e9d479,
  4cd0b47231, review 2026-10-09 (one temp var per check), review
  2026-10-11 (Black Belt).

### D-010 The league changes after the eighth Johto badge and the legendary event
- **Status:** Active (2026-10-10, 2026-10-11, 2026-10-12, theater state
  changed 2026-10-30).
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
  the south entrance is removed: that entrance is the way home from Johto
  to Kanto.
  - The theater state `VAR_ECRUTEAK_CITY_THEATER` only moves forward: the
    early theater (Rocket grunt 2, Surf gentleman 3) is optional and never
    lowers a later state, and Elm's Master Ball scene (4) also sends the
    grunt away.
- **Evidence:** decisions 2026-10-10, 2026-10-11 and 2026-10-12 (HnS's
  Victory Road only if needed, Moltres stays in Kanto's; flying must not skip
  Silver); e900a95bad; 9be851b978.

## Balancing

### D-011 Kanto: hand-set level ladder up to 47
- **Status:** Active (ladder changed 2026-10-29, evolved teams confirmed
  2026-11-02, level caps changed
  2026-10-30)
- **Decision:** Kanto's levels are set by hand and end with the champion at
  45-47. They follow an average player: about three of four trainers, half
  of the other wild Pokemon fought, new species caught, the Exp. Share on
  from the start (`B_SPLIT_EXP` Gen 5) and Gen 5 experience (D-042). That
  player meets every boss within about two levels of the team mean; aces
  may stand higher. Rushers have to train.
  - Boss aces: Brock 10, Misty 17, Surge 21, Erika 28, Koga 36, Sabrina 39,
    Blaine 42, Giovanni 42; the rival 7, 15, 20, 31, 38 and 43 (Route 22);
    Giovanni at the Game Corner 31 and at Silph 39; Elite Four 43-46;
    champion 45-47. Teams rise monotonically.
  - Route and dungeon trainers moved with their section's next boss
    (`tools/shift_kanto_ladder.py`).
  - Elite Four and champion rematch teams: 47 (D-015).
  - Legendaries: birds and Mew 40, Mewtwo 50. Other statics and gifts at
    the player's level when they are met, rounded: Snorlax 30 (Route 12)
    and 35 (Route 16), Marowak 30, the Power Plant's Electrode 35,
    Hitmonlee and Hitmonchan 35, Lapras 35, the fossils 40, Magikarp 10,
    the Game Corner prizes 25.
  - The average player's team at the title: about 49/44/43/43/42/42 (mean
    44, anchor 45). The debug menu's Johto Test starts with such a team
    (`tools/make_debug_states.py`, D-050).
  - Obedience for traded Pokemon follows the number of Kanto badges (10,
    then +5 per badge, 50 with eight); after the Johto title every Pokemon
    obeys (D-031).
  - Level-cap challenge (`src/caps.c`, D-041), per number of Kanto badges:
    "Normal" is the next leader's ace (10, 17, 21, 28, 36, 39, 42, 42; with
    eight badges the champion's 47), "Hard" the next leader's lowest level
    (9, 16, 19, 26, 34, 37, 40, 40; 45), as HnS derived its tables.
  - After the Kanto title Kanto scales to the player and these hand-set
    levels are the floor (D-031).
  - The ladder lowered the levels, not the teams: 53 evolved Pokemon stand
    below their evolution level (e.g. Dragonite 46 and 47, Tyranitar 47);
    the owner keeps them (2026-11-02, D-053).
- **Evidence:** b20f555d4d, 20fa75b584, 1662b679fc, 2f349b5ce2, af10c86033;
  ladder: decision 2026-10-29; evolved teams: owner answer 2026-10-31 (B-03).

### D-012 Johto and Hoenn: dynamic level scaling
- **Status:** Active (anchor, bands and corridors changed 2026-10-29,
  battle partners, the Goldenrod/Ecruteak ceilings and rematch team sizes
  changed 2026-10-30; bosses and the Johto league rooms changed
  2026-11-02, D-053)
- **Decision:** Johto and Hoenn scale to the player (`src/level_scaling.c`,
  `include/config/johto_scaling.h`, `include/config/hoenn_scaling.h`).
  - Anchor, in every region: the mean of the three highest party levels,
    rounded, but at most `SCALING_ANCHOR_MAX_DROP` (8) below the highest
    level (`include/level_scaling.h`). Weak fillers do not pull the levels
    down: a level 100 Pokemon with five level 1 Pokemon gives 92.
  - Trainers: anchor -3..+0 (Hoenn -5..+0), a boss's ace +1. Wild Pokemon:
    anchor -10..-4. Corridors per map section clamp both. Bosses
    (`IsBossTrainer`): gym leaders, Elite Four, champions, the rivals
    (Blue, Silver, May and Wally), Team Rocket's, Magma's and Aqua's
    leaders and admins.
  - Johto corridors: Routes 26 and 27, Tohjo Falls 40-80; arrival up to
    Bugsy 41-50 (Cherrygrove 41-48); Whitney and Morty 44-53 (Goldenrod
    44-61 from the Radio Tower takeover, `VAR_MAHOGANY_TOWN_STATE` 16;
    Ecruteak 44-61 from Elm's Master Ball, which opens the theater's
    legendary event, `VAR_ECRUTEAK_CITY_THEATER` 4; optional story
    ceilings in the corridor table); Chuck and Jasmine 47-55; Rocket
    Hideout and Pryce 50-58; Clair, Tin Tower and the Whirl Islands 56-64;
    Victory Road and the league 58-65, in the league rooms rising from
    Will to Lance (below); Mt. Silver 70-90 (Red unscaled).
  - Johto league rooms (`JOHTO_SCALING_ROOMS`, D-053): like HGSS the
    levels rise from Will to Lance, with HnS's steps (aces 50, 52, 54, 55,
    56). Per room the ace goes to anchor + extra instead of the boss
    extra, clamped to the room's own floor and ceiling: Will -1 (58-62),
    Koga +1 (59-63), Bruno +3 (61-64), Karen +4 (62-65), Lance +5
    (63-67). The Elite Four stay within the league corridor, the
    champion's ceiling is 2 above it (owner, option (b) of B-05). The
    average player (anchor 64) meets 62, 63, 64, 65 and 67; after the
    Johto title the ceilings become 100 and the steps stay.
  - Hoenn corridors: entry 65-85, early middle 70-90, late middle 75-95,
    final stretch 80-100, endgame 85-100; side areas reached later sit a
    tier higher.
  - The average player of D-011 meets the bosses at about +1..+2.5 over the
    team mean in Johto and +0..+3 in Hoenn. Team at the Johto title about
    70/63/63/62/60/60 (mean 63, anchor 65), at the Hoenn league about
    100/88/88/87/85/85 (mean 89, anchor 92). Rushers fall behind and have
    to train; stronger teams meet the corridor ceilings.
  - Experience is Gen 5 in every region (D-042).
  Johto's gym leaders have six Pokemon; route trainers and their phone
  rematch stages at least three (`tools/fill_johto_parties.py`: trainer
  class beats the local wild pool, duplicate a Pokemon rather than break
  the class; a rematch stage uses the maps of its first stage and keeps
  its own Pokemon; the four the tool left out are filled by hand, D-053).
  Rematch teams scale
  as well (every stage is below level 77). In-game battle partners (Troy
  in Mossdeep's Space Center, Siegfried in the Rocket Hideout) scale like
  a trainer of the map without the boss extra (`ScalePartnerMonLevel`,
  `src/battle_partner.c`); while a partner fights along, the anchor counts
  only the player's three Pokemon. HnS's badge gate for rematch
  stages (`GetMaxRematchStageForBadges`, `src/battle_setup.c`) counts the
  badges of the region the trainer stands in (Johto `VAR_JOHTO_BADGES`,
  Hoenn `VAR_HOENN_BADGES`, D-007); that region's title opens every stage.
  Kanto's rematches use the VS Seeker (D-034). After a region's title its
  corridor ceilings become 100 (D-031). Scaled trainer Pokemon evolve at
  their evolution level, level evolutions with extra conditions (Tyrogue's
  stats, Wurmple's personality, gender, time) as well. Stone, trade and
  condition evolutions (friendship, move, place) happen from the level from
  which HnS 2.0.5's own trainers mostly field the evolved species: the lowest
  level L at which they field it (or a later stage) and, among all their
  Pokemon at L or higher, more often than its pre-evolution (e.g. Gengar
  25, Raichu 28, Politoed 38, Crobat 52, Magnezone 59). One line per
  species in `src/data/trainer_evo_levels.h` with those counts, for the
  owner to tune (generated by `tools/make_trainer_evo_levels.py`;
  `--rule lowest` gives the lowest level instead); species HnS never
  fields from level 36 (`*_SCALING_EVO_OTHER_LEVEL`). Each evolution step
  is skipped with 10 % (`*_SCALING_EVO_SKIP_PERCENT`), which also stops a
  second step; a skip only stops an evolution the scaling adds, never below
  the species in the trainer's party (owner 2026-10-26). Skips and
  branches are fixed per trainer and party slot (a
  hash of trainer id, party index and step), so a trainer fields the same
  team in every battle at the same level. Rare forms are never picked
  (`sTrainerEvoExcluded` in `src/level_scaling.c`: Dudunsparce
  Three-Segment, Bloodmoon Ursaluna, Maushold Family of Three). The same
  rules hold in Hoenn, Johto, Kanto after the title and for the Kanto VS
  Seeker floor (D-034).
- **Evidence:** e900a95bad, 8f0e70b65c, 1685acfbc7, e1fde77aa4,
  cf857f4e0e, f549506494, e936f02c84, c239d59e43, 20a176b3af, c16d35c5aa;
  trainer evolution levels: decision 2026-10-21; majority rule, 10 %
  skipped steps, rare forms: decision 2026-10-26.

### D-013 Kanto is complete without trading
- **Status:** Active (amended 2026-10-29, changed 2026-10-30, owner decision;
  changed 2026-10-31: babies of the Gen-1 families count to Johto, D-049)
- **Decision:** All 151 Kanto species (D-049) are obtainable in Kanto
  without link trades: both fossils at Mt. Moon, both Hitmons at the
  dojo, evolution items placed in Kanto, all three starters in the wild
  (5 %), two-slot day care with breeding, extra Game Corner prizes. Day and
  night replace the FireRed/LeafGreen version split. Overworld Pokemon show
  what can be caught on a map (next to, not on, the encounter tiles).
  The other 34 species of the Gen-1 families (babies and later evolutions)
  count to Johto: the evolutions are possible in Kanto as before
  (evolutions are exempt), the babies hatch from Kanto's Day Care only
  once Johto is unlocked. Oak's rating, his aides' gifts and Celadon's
  diploma count the 151 (D-049).
  - Fossils: Mt. Moon B2F gives both; Cinnabar's lab revives each one the
    player took and still carries
    (`CinnabarIsland_PokemonLab_ExperimentRoom_Frlg`).
  - Starters: Bulbasaur in Viridian Forest, Charmander in Mt. Moon 1F and
    Squirtle on Route 24, each 5 % by day and at night, whatever the player
    chose (owner 2026-10-30; Johto and Hoenn: D-037). At night the share
    comes from the night table's most common species.
  - LeafGreen's water and bug exclusives follow the same rule, at night in
    the FireRed slot of their counterpart (same rate, LeafGreen's levels):
    Slowpoke for Psyduck, Slowbro for Golduck, Staryu for Shellder
    (Cinnabar: Slowbro for Seadra) on every Kanto map where LeafGreen has
    them, and Pinsir for Scyther in the Safari Zone (Center and East, 1 %
    each). Maps without a night table got one with only the changed areas
    (the other areas fall back to day, D-037). Starmie by Water Stone,
    Slowbro also at level 37 (2026-10-29).
  - Evolution items lie only on active Kanto maps; FRLG's Sevii items do
    not count (D-019). Celadon Department Store 4F sells, next to the FRLG
    stones, Ice Stone, Shiny Stone, Sun Stone, Black Augurite, King's Rock,
    Metal Coat and Dragon Scale (a shop, because King's Rock and Metal Coat
    each evolve two species). Item balls: Up-Grade (Silph Co. 9F), Dubious
    Disc (Silph Co. 10F), Protector (Mt. Moon 1F), Magmarizer (Pokemon
    Mansion 2F). Hidden items: Oval Stone (Rock Tunnel B1F), Electirizer
    (Cerulean Cave B1F).
  - No evolution needs a trade: Kadabra, Machoke, Graveler and Haunter also
    evolve by level; the held-item evolutions take the item from the bag
    (`I_USE_EVO_HELD_ITEMS_FROM_BAG`).
  - Of the 151, everything is obtainable before the first Kanto title
    except Mewtwo, who comes from Cerulean Cave right after it; so does the
    Electirizer for Electivire. The babies follow once Johto is unlocked
    (D-049).
- **Evidence:** 71a79b3a14, ff6d47ca45, ead606af10, 7aacaa2699,
  d8f26d241e, d0e2cc9ec4, 2d0e6a62af, 00da4d2a7a, 535f47948b, 5578b2caee;
  decision 2026-10-29 (LeafGreen exclusives at night, Sevii items replaced,
  Kleavor is in the game); decision 2026-10-30 (every starter wild, day and
  night).

### D-014 HM handovers in Johto never leave the player empty-handed
- **Status:** Active (changed 2026-10-30: Wallace's HM Waterfall in Hoenn;
  changed 2026-11-02: no replacement in Hoenn, owner)
- **Decision:** A player from Kanto already owns most HMs. Every HM handover
  checks for the HM; if it is already owned, there is a different reward
  with an in-world reason - never "then I have nothing for you". Exploring
  has to pay off.
- **Exception:** Waterfall and Whirlpool do not exist in Origin Jade's Kanto
  (no active Kanto map hands them out). They stay regular Johto finds: the
  ball on the Ice Path holds Waterfall, and Lance hands over Whirlpool in the
  Rocket Hideout. Waterfall can only be used with Clair's permit (D-008).
- **Hoenn:** the Ice Path ball is optional, but Ever Grande City and the
  Hoenn league lie behind a waterfall. Wallace in Sootopolis (after
  Rayquaza) therefore hands over HM Waterfall when it is not in the bag
  (`SootopolisCity_EventScript_GiveWaterfall`); with the HM in the bag he
  only points to the gym. The Rain Badge is the Waterfall license (D-008).
  The replacement rule above is Johto's: Wallace gives nothing else when
  the HM came from Johto (owner 2026-10-31).
  `FLAG_RECEIVED_HM_WATERFALL` is a Hoenn flag (`flags_hoenn_de.h`).
- **Evidence:** 09aac39e14, 5b0269166d, f9bd3e5021 (Waterfall, Whirlpool);
  audit 2026-10-30 (Wallace).

### D-015 Kanto's Elite Four rematch after the Kanto title
- **Status:** Active (2026-10-10, levels 2026-10-29)
- **Decision:** After the Kanto title the Kanto Elite Four use their
  rematch teams, matching the rematch texts that already showed. FRLG picked
  the teams by `FLAG_IS_CHAMPION`, which only FRLG's postgame (One Island)
  sets. The rematches end when the league changes (D-010). Their teams are
  at level 47 (D-011) and scale from there (D-031).
- **Evidence:** review 2026-10-09, decided 2026-10-10; levels 2026-10-29.

## Data, saves and maps (technical conventions)

### D-016 Flags and vars
- **Status:** Active (reserves and storage checks changed 2026-10-30)
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
  - Only numbers inside a storage window are saved: SaveBlock1 flags below
    `FLAGS_COUNT` and vars up to `VARS_END`, the FRLG, FRLG trainer, HnS
    rematch tier and Origin Jade windows in SaveBlock3, and the special
    flags and vars (not saved). Any other number would write into
    neighbouring save fields. `tools/check_flags.py` reports named flags
    and vars without storage, `--free` lists only free numbers with
    storage, and in the test build `GetFlagPointer`/`GetVarPointer` make a
    test INVALID for such a number.
  - Reserves (2026-10-30): SaveBlock1 trainer flag window 2 ids
    (`TRAINER_FLAGS_END` 0xAC7, last HnS/Hoenn trainer 1477 = 0xAC5,
    STATIC_ASSERT in `src/event_data.c` on `TRAINERS_COUNT_HNS`, which a
    new id raises by hand; `check_flags.py` check 2 also catches a trainer
    flag on a named flag); Hoenn vars 25 (0x415E-0x4176,
    `VARS_END` is fixed); FRLG flags from `FRLG_FLAGS_RESERVE_START`
    (0x12A1) to 0x13FF; Origin Jade sections: their spare slots
    (`check_flags.py --free`). Hoenn flags move `FLAGS_COUNT`: up to 12 more
    keep the SaveBlock1 layout, more move `vars` and the fields after it
    (see D-017).
- **Evidence:** 9a12676bc2, c2cbd316ad, 5dbd22cc65, 5bda779144,
  f89324b8d2, 42058c2f69, 2e9792740c; audit 2026-10-30 (A44, A89, A95, A96).

### D-017 Saves and migrations
- **Status:** Active (changed 2026-10-30: budget, layout guards; changed
  2026-11-02: SaveBlock3 holds Kanto's and Johto's Day Cares, D-052)
- **Rules:** The save layout freezes with the release; until then it may
  grow deliberately (2cbf85903d). One-time migrations of Origin Jade run in
  `LoadGameSave` (`src/save.c`) and are keyed to a flag from the Origin Jade
  block, which new games set right away - never through `SAVE_VERSION`:
  that number belongs to HnS upstream and is bumped there.
- **Budget** (2026-11-02, ROM as of `runde23` 2026-11-03;
  `python3 tools/check_budget.py` prints it after a build): SaveBlock1
  15868 of 15872 bytes (4 free), SaveBlock2 3892 of 3968 (76 free),
  SaveBlock3 1584 of 1624 (40 free; 1008 before the Day Cares of
  D-052), PokemonStorage 34144 of 35712 (1568 free). The limits are the
  flash space `src/save.c` checks with `STATIC_ASSERT`; new Origin Jade
  data goes to SaveBlock3 (D-016), which has only 40 bytes left since the
  Day Cares of D-052; new save data needs the SaveBlock1 reserves below or
  a layout decision. SaveBlock1 reserves that can be reused in place
  without moving offsets: `roamerPadding` (84 bytes), `dexPadding1` and
  `dexPadding2` (63 each), `unused_9C6` (2), `outbreakUnused1/2/3`.
  Memory: EWRAM 249760 of 262144 bytes (95.28 %, of which `gHeap`
  115968), IWRAM 25704 of 32768 (78.44 %), ROM 25894888 of 33554432
  (77.17 %).
- **Layout guards and reserves (2026-10-30):**
  - Sizes: SaveBlock1 15868 of 15872 bytes (4 free), SaveBlock2 3892,
    SaveBlock3 1584 of 1624 (40 free), PokemonStorage 34144. `test/save.c`
    checks these sizes; the build checks the limits.
  - SaveBlock3: new fields only at its end. The offsets of the Origin Jade
    fields are pinned by STATIC_ASSERTs in `src/save.c`. The config
    switches in front of them (`FNPC_ENABLE_NPC_FOLLOWERS`,
    `OW_SHOW_ITEM_DESCRIPTIONS`, `USE_DEXNAV_SEARCH_LEVELS`,
    `APRICORN_TREE_COUNT`) would move them.
  - SaveBlock1: `flags[]` grows with `FLAGS_COUNT` (D-016); from 13 more
    Hoenn flags on, `vars` and later fields move, and with more than 60 the
    build fails.
  - A deliberate layout change updates the asserts in `src/save.c` and
    the sizes in `test/save.c` in the same commit.
- **Evidence:** 2cbf85903d, 9635b02081, 2026-10-10 (Johto starter var);
  audit 2026-10-30 (A38, A89, A93, A97).

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
- **Status:** Active (changed 2026-11-02: Alola listed; Sinjoh and Alola
  stay locked, owner; changed 2026-11-02: Emerald's battle tents and
  Trainer Hill retired)
- **Decision:** HnS's own Kanto maps are retired (`hns_kanto_retired`); the
  FRLG Kanto maps are used. The Sevii Islands are retired, reversibly
  (`frlg_sevii_retired`); everything that would lead there is disabled (Bill
  after Blaine, the Indigo Plateau guard's Sevii branch). The Sinjoh content
  is locked by `SINJOH_CONTENT_AVAILABLE` in `include/config/general.h`.
  HnS's 20 Alola maps (`MelemeleIsle_hns` and the others) are active
  (`game_version` `hns`) but have no way in: their only warps are in the
  retired `Route13_hns`, and the Melemele fly spot needs
  `FLAG_VISITED_ALOLA`, which only Melemele sets. Sinjoh and Alola stay
  locked (owner 2026-10-31); what unlocking them would need is in O-009.
  Emerald's facilities that HnS has too are retired in favour of HnS's
  (owner 2026-11-02): the Battle Frontier (`frontier_em_retired`, D-030),
  the battle tents (`em_tents_retired`, D-030) and the Trainer Hill on
  Route 111 (`em_trainer_hill_retired`, D-044).
- **Evidence:** 752b880dee, 67c1384191, 82f533ac08, 020c34f826,
  84e198c40c, ba8f5e9168, review 2026-10-09.

## Language and upstream

### D-020 Language, comments and game text
- **Status:** Active (changed 2026-10-30)
- **Rules:**
  - Comments are English (since 2026-10-09).
  - The German build never shows English game text. Changes to game text
    go into the `#if GERMAN` branch; the English branch is only adapted to
    match.
  - German texts follow the official German games (source cascade in
    1767d31fe6). Real umlauts and ß, no "ae/oe/ue/ss" substitutes. Title
    case, no all-caps.
  - Pixel limits: text box 208 px (`tools/check_text_width.py` measures
    the built ROM), PokeNav call box 192 px (`check_pokenav_text.py`).
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
- **Status:** Active (changed 2026-10-30, changed 2026-10-31: no fossils
  rolled; changed 2026-11-02: Bloodmoon Ursaluna, regional forms as
  evolutions; exchange menus and lab starters, D-054)
- **Decision:** HnS's GEN SCOPE option (randomizer pool limited to Gen 1-3
  families) stays in the code and the save, but has no row in the challenge
  menu and is off (`RANDOMIZER_DEFAULT_GEN_SCOPE_1_3` FALSE in
  `include/config/randomizer.h`). Gen 4-9 and the regional forms are off in
  `species_enabled.h`, so both settings give the same pool.
  - Regional forms (`P_REGIONAL_FORMS` FALSE, 4458a3bc2e) stay off. The
    owner keeps regional forms that are evolutions where HnS does not tie
    the evolution to a region (2026-10-31); every such case in HnS's data
    is tied to a region or starts from a regional form that only locked
    content offers, so none is enabled (list in O-045).
  - Bloodmoon Ursaluna stays as HnS has it (owner 2026-10-31): it is a
    form of Ursaluna (`P_GEN_8_CROSS_EVOS`), not a regional form. Ursaring
    with a Peat Block at night inside Mt. Moon (`IF_IN_MAPSEC`
    `MAPSEC_MT_MOON`; every FRLG Mt. Moon floor has that map section)
    becomes Bloodmoon Ursaluna, elsewhere at night Ursaluna (HnS's order,
    3430ae928d). The Peat Block is sold in Mahogany's granny shop;
    Teddiursa lives in Dark Cave, Ursaring on Route 45 and Mt. Silver.
    HnS's Hisui branch needs `SINJOH_CONTENT_AVAILABLE` (D-019). Trainers
    never evolve into it (`sTrainerEvoExcluded`, D-012).
  - Items ("Items: Zufall", `src/randomizer.c`): item balls, hidden items
    and NPC gifts are randomized from the first starter on
    (`FLAG_SYS_POKEMON_GET`), so in all three regions. Key items, HMs and
    the GS Ball keep their place, and so do fossils and evolution items
    (sort types evolution stone, evolution item and fossil, plus King's
    Rock, Metal Coat, Deep Sea Tooth, Deep Sea Scale, Razor Claw and Razor
    Fang), so D-013 and D-037 hold with the item randomizer too; they can
    still be rolled for other items, fossils never (Root and Claw Fossil
    left the whitelist `src/data/randomizer/item_whitelist.h`, D-049).
    Oak's five Poke Balls (after the
    Pokedex and the refill after the Route 22 rival) and what the player
    picks from an exchange menu (`giveitem_norandom`: Celadon's coin prizes,
    Cerulean's Berry Powder man, Route 113's Glass Workshop flutes,
    Route 124's shard trades, Captain Stern's Scanner trade in Slateport's
    harbour; D-054) bypass the randomizer. A Kanto gift with its own receive
    text (`giveitem_msg`: the gym leaders' TMs, the Master Ball, the Amulet
    Coin and others) gets the generic obtain message when its item was
    changed; the dialogue around it still names the original item. Outside
    the chaos mode each item has its own fixed result, seeded by the trainer
    ID, the map, the local ID (item ball, NPC) or the hidden flag (hidden
    item) and the original item.
  - Trainers ("Trainer: Zufall"): each opponent's team is seeded by its
    trainer constant, team size and slot (after the level scaling's species
    choice), so two trainers of one class get different teams.
  - Fixed Pokemon ("Feste PKMN: Zufall"): from the first starter on, script
    gifts (`givemon`), static and event battles (`setwildbattle`,
    `setwildbattleshiny`, `seteventmon`) are randomized by
    `RandomizeScriptedFixedMon`, seeded by the trainer ID, the map, the
    local ID of the object talked to and the species. Outside the chaos mode
    a soft reset gives the same result. Unchanged, as the menu text says:
    named gifts (`givenamedmon`), roamers, the casino prizes (Goldenrod
    Game Corner, Celadon prize room), Cianwood's Tentacool (stands in for a
    missing Surf user) and the starters of Oak's, Elm's and Birch's labs
    (`sFixedMonExceptionMaps`, map-wide). Scripted double wild battles are
    not randomized. Gift eggs (`giveegg`: Violet City's Togepi, Lavaridge's
    Wynaut) get their species when given (`RandomizeGiftEggMon`, same
    seed); Day Care eggs hatch as the parents' species. Elm counts the
    hatched Violet City egg whatever its species (`FLAG_HATCHED_TOGEPI_EGG`,
    set in `AddHatchedMonToParty`).
  - Starters ("Starter: Zufall"): every lab's preview applies it, Oak's,
    Elm's and Birch's (Johto starter after the Hoenn dex; D-054), each
    seeded by the trainer ID and the ball's species; the one-type
    challenge changes only Oak's. The lab hands out exactly the previewed
    and named species with the preview's shininess (D-035). When a preview
    shows another species than the ball's, the lab asks with a text that
    names it (`...OtherStarter` in the three labs) instead of the ball's
    own text.
  - Field moves: with any option that changes the player's species
    (Starter, wild, fixed, evolutions, evolution lines) or the moves, owning
    the HM is enough; the first party Pokemon may use it
    (`HMsOverwriteOptionActive`, `src/challenge_menu.c`, as for Nuzlocke,
    party limit, mirror and one-type runs). Badges and permits (D-008)
    still apply.
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
- **Status:** Active (2026-10-15, Johto levels changed 2026-10-27, D-039,
  Hoenn levels 2026-10-29, D-043; changed 2026-11-02: Jirachi)
- **Decision:** All one-time encounters share one table
  (`src/legendaries_oj.c`, ids in `include/constants/legendaries_oj.h`):
  Articuno, Zapdos, Moltres, Mewtwo, Mew (Mt. Moon only), Lugia, Ho-Oh,
  Celebi, Suicune, Deoxys (HnS Birth Island only), Union Cave Lapras, the red
  Gyarados, Entei, Raikou, Regirock, Regice, Registeel, Groudon, Kyogre,
  Rayquaza, Latias, Latios and Jirachi (Route 4, D-037).
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
    title once the chosen one is caught (level 80; the chosen one keeps its
    story level 78, D-039). Route 41's Tentacruel then step aside for Ho-Oh
    choosers.
  - Latias and Latios both roam Hoenn after the first Hoenn title (level 100,
    Emerald routes). No Latias roams Kanto or Johto. Faraway Island,
    Southern Island and Navel Rock are not offered anywhere.
  - Levels: Johto's follow D-039, Hoenn's D-043 (both never below the top of
    the map's wild band); Kanto's are fixed (birds and Mew 40, Mewtwo 50,
    D-011; Jirachi 80 like Deoxys in D-039, HnS had 50). Sudowoodo and
    Snorlax never return. The GS Ball is used up at the shrine; there is no
    second Celebi.
- **Evidence:** decision 2026-10-15 (O-004).

### D-027 Suicune waits in Johto's Glockenturm
- **Status:** Active (2026-10-15). Changed 2026-10-27 by D-038 and D-039:
  Suicune waits only after the Route 36 scene (`VAR_SUICUNE_ENCOUNTERS` 4),
  Eusine's hint moved to Route 36, the level is 78. The tower access (either
  bell) stays.
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
  Changed 2026-10-30 (no Emerald after-title scenes in Littleroot),
  changed 2026-10-31 (Johto titles and Red continue in the player's room
  in Pallet Town), changed 2026-11-02 (Elm's call in Pallet Town, D-051).
- **Decision:**
  - Johto's league can be repeated: the Black Belt in front of the Elite
    Four door never shows. Title defences use the `_2` teams, a short Lance
    scene (no Mary, no Oak) and a Hall of Fame text without Kanto; HnS's
    `SetGameClearFlags` is gone.
  - Kanto's league can be repeated until the league change (D-010, D-015).
    Hoenn's league can be repeated; later Hoenn titles skip May and Birch.
  - After every Johto title and after Red: Hall of Fame (saves), no credits,
    the player wakes up in their room in Pallet Town
    (`HEAL_LOCATION_PALLET_TOWN_PLAYERS_ROOM`, D-002);
    `HEAL_LOCATION_NEW_BARK_TOWN_LAB_HNS` is no longer used. Elm's call
    after the first Johto title comes on the first step out of the house
    in Pallet Town (D-051). After every Hoenn title it
    continues in Littleroot Town in front of Birch's lab. Emerald's
    S.S. Ticket and Lati TV scene in Norman's and Birch's houses does not
    run (D-002, D-003); Latias and Latios roam without it (D-026). Neither
    does Birch's National Mode scene (the Pokedex has it since the
    arrival): the first title sets `VAR_DEX_UPGRADE_JOHTO_STARTER_STATE` 3
    and Scott's S.S. Tidal call, so the Johto starters for the full Hoenn
    dex follow as in Emerald.
  - The credits roll once, at the first Hoenn title, the end of the game
    (`FLAG_ROLLED_ENDING_CREDITS`).
  - Silver waits in Johto's league center for a daily battle after the Johto
    title. `{RIVAL}` shows Silver's name on Johto's league maps.
  - Code: `special GameClearNoCredits` (`src/post_battle_event_funcs.c`),
    `HallOfFame_SetRollCredits` (`src/hall_of_fame.c`).
- **Evidence:** decision 2026-10-15 (O-013); owner answer 2026-11-02
  (O-036).

### D-029 Magnet Train, radio quiz and ships
- **Status:** Active (2026-10-15, ships changed 2026-10-20, Hoenn trips
  changed 2026-10-30, changed 2026-10-31: Hoenn entries of the ship menus,
  D-047; Aurora Ticket, D-049; changed 2026-11-02: Birch's greeting only
  after the first trip, D-047)
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
    other port, the Kampfzone and Entstehungsinsel (with the Aurora
    Ticket). The M.S. Aqua sails every day from both ports. The Hoenn
    entries of the menus follow D-047.
  - The sailors at the Kampfzone and on Birth Island sail to Olivine and
    Vermilion, and to Hoenn like the ports (D-047).
  - Only the first Hoenn trip (`VAR_HOENN_ARRIVAL_STATE` 0) sets the end
    state of Emerald's intro (`Common_EventScript_HoennSkipIntro`); every
    trip with the "Hoenn" entry lands on the Route 104 pier, where only
    the first trip starts Birch's arrival scene; later "Hoenn" trips land
    there without an event (D-047). The trips to Slateport and Lilycove
    (D-047) change no Hoenn state, so a trip never opens a town early or
    lands in a scene. The ticket is not used up. Every trip sets the
    respawn: in front of Birch's lab for the pier, the Pokemon Center of
    Slateport or Lilycove for their harbours. Whoever leaves the beach
    before Birch's greeting (Fly, Teleport, Dig) gets the welcome
    (Pokedex, badge case, Birch's contact) on entering the lab (D-005).
  - The woman in Olivine City gives the Aurora Ticket only after the first
    trip to Hoenn (`VAR_HOENN_ARRIVAL_STATE` 1 or more, which needs the
    Johto title), so Deoxys comes after Hoenn is unlocked (D-049).
  - Faraway Island and Southern Island are not offered.
- **Evidence:** decision 2026-10-15 (O-003); daily ship, return trips to
  Hoenn and Aurora Ticket 2026-10-20.

### D-030 One Battle Frontier: the HnS Kampfzone
- **Status:** Active (2026-10-15; changed 2026-11-02: Scott's hint, D-051;
  changed 2026-11-02: Emerald's battle tents retired; changed 2026-11-03:
  Scott's gift counts 11 meetings)
- **Decision:** The Emerald frontier (47 maps, 36 layouts) is retired
  (`frontier_em_retired`). The HnS Kampfzone is reached by ship (D-029) and,
  after the Hoenn title, from Slateport and Lilycove: the S.S. Tidal lists
  it once the player has met Scott on board (`FLAG_MET_SCOTT_ON_SS_TIDAL`,
  his scene at the first boarding); his call after the first Hoenn title
  points there (D-051, owner 2026-10-31). It is only on the
  Johto/Kanto region map. The Artisan Cave is bound to the HnS Kampfzone and
  counts as part of it (`MAPSEC_BATTLE_FRONTIER`); unlike HnS its door in the
  Kampfzone is open (ledge corner at (29,9), the Engineer beside the path;
  owner confirmed 2026-10-26).
  A whiteout there leads to the Kampfzone's nurse.
  Emerald's battle tents in Verdanturf, Fallarbor and Slateport are retired
  as well (9 maps and 4 layouts with game_version `em_tents_retired`; owner
  2026-11-02, S-04: HnS's endgame counts). Their buildings are contest
  halls now (D-058). The HnS copies of the three tents in the courtyard of
  the Route 40 Trainer Hill stay, but Scott is not on their maps: their
  scripts for his two tent meetings (`FLAG_MET_SCOTT_IN_VERDANTURF`,
  `FLAG_MET_SCOTT_IN_FALLARBOR`) have no object and never run, so the two
  meetings are no longer in the game. Scott is not needed for the story
  (owner 2026-11-03). His gift in his house in the Kampfzone counts the 11
  meetings that remain (`VAR_SCOTT_STATE`: Petalburg, Rustboro twice,
  Slateport twice, Mauville, Route 119 and his call after the Fortree gym,
  Lilycove, Mossdeep, Ever Grande): 4 Battle Points from 11 on (Emerald:
  13), 3 from 9 on, 2 from 6 on, else 1. The M.S. Aqua reaches the
  Kampfzone long before Hoenn, so Scott gives his welcome and the gift
  only after the Hoenn title (`FLAG_IS_HOENN_CHAMPION`), when all
  meetings are over; before that he only has his usual remarks and the
  prizes for the frontier symbols and his shields.
- **Evidence:** decision 2026-10-15 (O-006); owner answer 2026-10-31
  (S-02); owner answers 2026-11-02 (S-04); owner answer 2026-11-03
  (O-073).

### D-031 Level scaling after a region's title
- **Status:** Active (2026-10-15, Johto statics changed 2026-10-27, D-039,
  Hoenn statics 2026-10-29, D-043; Troy and Red changed 2026-11-02, D-053)
- **Decision:** After a region's title its trainers (rematches included) and
  wild Pokemon scale to the player's anchor without a ceiling (level 100).
  - Kanto: FRLG maps, off before `FLAG_IS_KANTO_CHAMPION`; no corridors, the
    hand-set level (D-011) is the floor, the band is Johto's, trainer
    Pokemon evolve (`include/config/kanto_scaling.h`).
  - Johto and Hoenn: corridor ceilings become 100 with
    `FLAG_IS_JOHTO_CHAMPION` / `FLAG_IS_HOENN_CHAMPION`; floors stay.
  - Fixed: Red, the facilities, and Kanto's static and scripted encounters
    (D-026). Johto's and Hoenn's, roamers included, never fall below the top
    of the map's wild band (D-039, D-043). Red on Mt. Silver and Troy
    (Steven) at Meteor Falls are the final bosses of the story: six
    Pokemon each at level 100 with fixed movesets (D-053), above
    `JOHTO_SCALING_FIXED_MIN_LEVEL` (77) and `HOENN_SCALING_FIXED_MIN_LEVEL`
    (70), so no corridor or level cap of the scaling touches them (before:
    Red 77-93, Troy 75-78 as set in 876c3d4c19).
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
  - The weekday siblings appear only on their day and give their item once:
    Monica (Monday, Route 40), Tuscany (Tuesday, Route 29), Wesley
    (Wednesday, Lake of Rage), Arthur (Thursday, Route 36), Frieda (Friday,
    Route 32), Santos (Saturday, Blackthorn City), Sunny (Sunday, Route 37).
  - Goldenrod Dept. Store 5F: the TM lady is there on Sunday only (TM
    Rückkehr once, HnS logic; owner kept it 2026-10-21).
  - Haircut brothers (Goldenrod Underground): the older brother on Tuesday,
    Thursday and Saturday, the younger on Sunday, Wednesday and Friday,
    nobody on Monday; one haircut per day.
  - Not weekday-bound: Union Cave's Lapras (D-026), the M.S. Aqua (D-029).
- **Evidence:** decision 2026-10-15; TM lady, haircut brothers and contest
  day 2026-10-20.

### D-034 Kanto rematches through the VS Seeker
- **Status:** Active (2026-10-20, levels 2026-10-29)
- **Decision:** On FRLG maps every trainer with a FireRed/LeafGreen rematch
  can be fought again through the VS Seeker (Kampffahnder, Vermilion
  Pokemon Center): 157 trainers, without the Sevii rows (D-019). FRLG
  behaviour: the device charges in 100 steps, trainers in view answer
  (70 %), the wish ends after 100 steps or when the player leaves the map,
  and a trainer who wants a rematch challenges the player on sight.
  - Teams by tier: VS Seeker received, 4 Kanto badges, 6 Kanto badges,
    Kanto title, Johto title. The newest team up to the current tier
    fights; a trainer without one fights his first team again.
  - The first three tiers sit on the D-011 ladder (18-21, 30-31, 37);
    from the Kanto title on the teams scale (D-031). Route 6's rematch teams
    (Ricky, Jeff, Isabelle) moved up with their first teams.
  - Before the Kanto title a rematch team whose highest level is below its
    tier's floor (18, 30, 37) moves up as a whole until it reaches it and
    evolves like Kanto's scaling (D-012: levels from
    `src/data/trainer_evo_levels.h`, 10 % of the steps skipped, skips and
    branches fixed per rematch team and party slot, rare forms never)
    (`sKantoRematchLevelFloors` in `src/vs_seeker.c`, applied in
    `src/level_scaling.c`).
  - Outside Kanto the VS Seeker only says that it works in Kanto. Match
    Call, Johto's phone rematches and the gym rematches (D-032) are
    untouched: the VS Seeker has its own table and state
    (`FLAG_VS_SEEKER_CHARGING`, `VAR_VS_SEEKER_STEPS`,
    `VAR_VS_SEEKER_REMATCH_LO/HI`).
  - Code: `src/vs_seeker.c`, `src/data/vs_seeker_kanto.h`, the rematch
    hooks in `src/battle_setup.c`, the level floor in `src/level_scaling.c`.
- **Evidence:** decision 2026-10-20.

### D-035 Starter previews roll shinies everywhere
- **Status:** Active (2026-10-20)
- **Decision:** Every starter choice rolls a shiny for its preview, once
  per ball and map visit, and hands out the starter with exactly that
  shininess: Oak's lab (Kanto), Elm's lab (Johto) and Birch's lab (Johto
  starter after the completed Hoenn dex). The chance is the normal shiny
  chance incl. Shiny Charm rerolls, not "always shiny" (owner confirmed
  2026-10-21).
  - Code: `GetStarterPreviewBall` / `ScrCmd_showmonpic` (`src/scrcmd.c`),
    `FLAG_STARTER_PREVIEW_CHECKED_1-3` / `FLAG_SHINY_STARTER_1-3`, givemon
    with `SHINY_MODE_ALWAYS` / `SHINY_MODE_NEVER` in the three labs.
- **Evidence:** decision 2026-10-20 (O-011).

### D-036 Charm sources
- **Status:** Active (2026-10-21, changed 2026-10-31: 422 species; Johto
  dex without Azurill and Wynaut; 2026-11-02: mythicals confirmed)
- **Decision:**
  - Ovalpin (Oval Charm): the Day Care man hands it over once, right after
    the player's first egg, at every active Day Care (Kanto Route 5, Johto
    Route 34, Hoenn Route 117; Four Island is retired, D-019). It makes eggs
    turn up more often at the Day Care, not hatch faster. With a full bag
    the usual message shows and the next egg offers it again
    (`FLAG_RECEIVED_OVAL_CHARM`).
  - Schillerpin (Shiny Charm): the game designer in Lilycove's Cove Lily
    Motel hands it over once with the Pokedex diploma, once the player holds
    the first Hoenn title (`FLAG_IS_HOENN_CHAMPION`) and `HasAllMons` reports
    the National Pokedex complete (`FLAG_RECEIVED_SHINY_CHARM`). He only
    appears after the first Hoenn title; his diploma logic (Johto dex) is
    unchanged, except that Azurill and Wynaut are not needed (D-049). The
    charm adds `I_SHINY_CHARM_ADDITIONAL_ROLLS` shiny rolls.
  - The National Pokedex counts the enabled species of HnS's obtainable dex
    (422: Kanto 151, Johto 129, Hoenn 142, D-049); species disabled in this
    build do not count, in `HasAllMons` as in the count and the rating. All
    422 are obtainable without trading (D-037). Not required: the
    mythicals and Regirock, Regice, Registeel (HnS's `dexNotRequired`;
    owner kept it 2026-10-26 and again 2026-10-31: Mew, Celebi, Jirachi
    and Deoxys do not count, as in the official games). Every completion
    check skips them (`isMythical` without `dexForceRequired`, which no
    Gen 1-3 species sets): `HasAllMons`, `HasAllKantoMons`,
    `HasAllJohotoMons`, `HasAllHoennMons` and Birch's PC rating
    (`src/birch_pc.c`).
  - Code: `DayCare_EventScript_GiveOvalCharm` (`data/scripts/day_care.inc`,
    called by the egg scripts of Route 5, Route 34 and Route 117);
    `LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveShinyCharm` (runs
    before `Special_ShowDiploma`).
- **Evidence:** decision 2026-10-21 (O-008).

### D-037 Hoenn is complete without trading
- **Status:** Active (2026-10-26, changed 2026-10-30, starters: owner decision;
  changed 2026-10-31: 422 species; changed 2026-11-02: Jirachi, evolution
  items in Hoenn's marts, Milotic; Pokeblock Case and blenders, D-058)
- **Decision:** All 422 species of the National Pokedex (D-049) and the
  whole Hoenn dex are obtainable without link trades. As in Kanto (D-013), day and night
  replace the Ruby/Sapphire version split on Emerald's wild tables.
  - Route 102: Surskit (10 %); Route 117: Roselia (20 %) and Surskit (10 %),
    day and night. Masquerain at level 22, Budew by breeding Roselia without
    incense (`P_INCENSE_BREEDING` Gen 9), Roserade with the Shiny Stone
    (Celadon Department Store 4F, Mahogany's granny shop, Mauville's Mart,
    Lilycove Department Store 2F).
  - Route 114: Zangoose by day in Seviper's slots (9 %), Seviper at night.
  - Meteor Falls, all five maps: Solrock by day, Lunatone at night in
    Solrock's slots, on land and surfing.
  - Meditite and Medicham, which Emerald dropped, in Ruby/Sapphire's slots
    and levels, day and night: Mt. Pyre's exterior Meditite (30 %, in two
    of Shuppet's slots); Victory Road B1F and B2F Medicham (10 %, in one of
    Lairon's slots).
  - Starters, whatever the player chose (owner 2026-10-30): the Johto
    starters are wild at 5 %, day and night, all before the second badge
    - Chikorita in Ilex Forest, Cyndaquil on Route 31, Totodile on Route 32
    (grass on the coast) - and an overworld Pokemon shows each. The
    Hoenn starters are wild at 5 % around the clock (no night tables
    there): Treecko in Petalburg Woods, Torchic on Route 113, Mudkip on
    Route 102. The share comes from the table's most common species where
    the slot rates allow (Ilex Forest at night: Paras; Petalburg Woods:
    Wurmple). Kanto's starters: D-013.
  - `src/data/wild_encounters.json`: the plain table is the day table
    (morning, day and evening), the entry with the suffix `_Night` the night
    table (19:00-6:00), right after it. A map without a night table uses its
    day table around the clock.
  - The Pokedex area screen shows the table the encounter code uses: per area
    the day table when the night has none; retired maps and maps of the other
    region map (Hoenn vs. Kanto and Johto) are skipped (`FindMapsWithMon`,
    `src/pokedex_area_screen.c`).
  - Evolution items for the Hoenn families (owner 2026-10-31), in two
    steps like Johto (Goldenrod's Department Store, then Mahogany's
    granny shop):
    - Mauville's Mart (the third gym's town, the hub after Slateport):
      Water Stone (Ludicolo), Leaf Stone (Shiftry), Moon Stone
      (Delcatty), Thunder Stone (Probopass), Dawn Stone (Gallade,
      Froslass) and Shiny Stone (Roserade): Lotad, Seedot and Ralts
      (Route 102), Skitty (Route 116), Nosepass (Granite Cave) and
      Roselia (Route 117, east of Mauville) are met around it.
    - Lilycove Department Store 2F, left clerk (after the sixth badge,
      Hoenn's department store like Celadon's): the same six stones and
      Reaper Cloth (Dusknoir), Deep Sea Tooth (Huntail) and Deep Sea
      Scale (Gorebyss), for Mt. Pyre's Duskull and the Clamperl met with
      Dive. Before that, the only sources are single finds (item balls,
      the treasure hunter on Route 124, Captain Stern's Scanner trade).
  - Milotic (owner 2026-10-31): only by beauty, as in Gen 3. Feebas bites
    on the six Feebas tiles of Route 119 (any rod, `src/wild_encounter.c`);
    beauty 170 or more from Pokeblocks (the Berry Blenders in the contest
    lobbies of Verdanturf, Fallarbor, Slateport and Lilycove; the Pokeblock
    Case from the little girl in Slateport's contest lobby, D-058, or from
    Baoba at Johto's Safari Zone gate), then a level up. No Prism Scale
    lies anywhere (no item ball, shop or gift); its evolution entries stay
    in the species data. Only the item randomizer can roll one
    (`src/data/randomizer/item_whitelist.h`).
  - Jirachi (owner 2026-10-31): HnS's Mt. Moon Square event, moved to
    FRLG's Route 4 because HnS's Kanto maps are retired (D-019). The white
    rock is the small rock by Mt. Moon's Pokemon Center (7,4,
    `Route4_EventScript_WhiteRock`; the rock at 5,5 holds the hidden
    Persim Berry). Touching it at night (`FLAG_NIGHT_POKEMON` clear, as
    in HnS) summons Jirachi once (`FLAG_SUMMONED_MTMOON_JIRACHI`), which
    then waits below the ledge (5,9, `FLAG_HIDE_MTMOON_JIRACHI`) until it
    is fought. HnS's Kanto came after the Johto title; here the rock
    answers only after the first trip to Hoenn (`VAR_HOENN_ARRIVAL_STATE`
    1 or more, D-049), like Deoxys's Aurora Ticket (D-029). Level 80,
    fixed like Kanto's other statics; legendary rules and level in D-026
    (`LEGENDARY_JIRACHI`). Mythicals stay out of `HasAllMons` (D-036).
- **Evidence:** decision 2026-10-26 (O-019); audit 2026-10-30 (Meditite and
  Medicham had no reachable source); decision 2026-10-30 (every starter
  wild).

### D-038 Suicune: HnS's sightings, Crystal's Route 36, the Glockenturm
- **Status:** Active (2026-10-27). Supersedes D-027 in the waiting condition
  and Eusine's hint; D-027's tower access stays.
- **Decision:** Suicune's story follows HnS up to Route 42 and Crystal after
  that. It stays in Johto; HnS's Kanto chain stays retired.
  - Burned Tower release and Eusine: HnS, unchanged. Olivine's first visit
    arms Cianwood: sighting and Eusine battle (HnS team), unchanged.
    Route 42: sighting with HnS's Eusine dialogue, no Glockenturm hint
    (Cianwood neither).
  - Route 36 (Crystal): once both sightings are done Suicune stands in the
    path from Route 37 (35,16). The coord event on (39,18), the one tile
    between that path and the rest of Route 36, starts the scene: Suicune
    runs off north, Eusine walks in from the south and says it seems to head
    for the Glockenturm. Every walk between Route 37 and the National Park
    gate, Route 35 or Violet City passes that tile.
  - Glockenturm 1F: Suicune waits there after the Route 36 scene, talk to it
    (level D-039, legendary rules D-026). Eusine walks in after the first
    knockout or catch. Access as in D-027 (either theater bell). No Wise
    Trio, no Clear Bell change, no Raikou/Entei cameo.
  - Afterwards Eusine stays in the Kampfzone (D-030); nothing in Kanto.
  - `VAR_SUICUNE_ENCOUNTERS` (HnS var; no new flags or vars):
    - 0: before Olivine's first visit;
    - 1: Cianwood armed (Olivine's first visit);
    - 2: Cianwood done, Route 42 not yet;
    - 3: both Johto sightings done, Route 36 armed (set by whichever of
      Cianwood and Route 42 comes second);
    - 4: Route 36 done, Suicune waits on Glockenturm 1F;
    - 5-7: unused (HnS's retired Kanto steps);
    - 8: first knockout or catch at the Glockenturm, Eusine's scene played.
    Route 42's own sighting is `FLAG_HIDE_ROUTE42_SUICUNE`. Saves at 3 from
    before this change get the Route 36 scene; the tower shows Suicune
    from 4.
  - Code: `Route36_hns` (`LOCALID_ROUTE36_SUICUNE`/`_EUSINE` with
    `FLAG_TEMP_2`/`FLAG_TEMP_3`, coord event at value 3), `TinTower_1F_hns`,
    `Route42_hns`, `CianwoodCity_hns`.
- **Evidence:** decision 2026-10-27.

### D-039 Johto's static and legendary levels fit the scaling
- **Status:** Active (2026-10-27, event and player levels 2026-10-29;
  legendaries in the anchor confirmed 2026-11-02, D-053;
  changed 2026-10-30: roamer example corrected; changed 2026-10-31:
  Deoxys after the first trip to Hoenn). Replaces the fixed levels
  of D-026 and D-031 for Johto.
- **Decision:** Johto's legendaries sit at 75-80 by story point; the other
  strong statics fit the corridor (D-012) where they can first be met. None
  of them falls below the top of the map's wild band afterwards.
  - Levels (old in brackets):
    - Raikou and Entei, roaming from the Burned Tower (3-4 badges): 75 (40);
    - Celebi, Ilex Forest (GS Ball, from Surf on): 75 (40);
    - Suicune, Glockenturm 1F (8 badges): 78 (50);
    - Lugia and Ho-Oh, story battle and the chosen one's returns (8 badges,
      theater): 78 (50);
    - the Lugia or Ho-Oh not chosen (after the first Johto title): 80 (70);
    - Deoxys, Birth Island (after the first trip to Hoenn, D-029): 80
      (70);
    - Sudowoodo, Route 36 (after Whitney, corridor 44-53): 50 (20);
    - Union Cave's Lapras (Surf, after Morty): 55 (20);
    - the red Gyarados, Lake of Rage (about 6 badges, corridor 50-58):
      55 (30);
    - the Rocket Hideout's three Electrode (corridor 50-58): 60 (30);
    - the Kampfzone's Sudowoodo (after the Johto title): 65 (40).
    Route 41's four Tentacruel stay at 100: they guard the Whirl Islands
    (unwinnable, healed after the battle), they are not an encounter: not
    catchable, never shiny (`FLAG_NO_WILD_CATCHING` with
    `P_ONLY_OBTAINABLE_SHINIES`).
  - The average player's anchor (highest level in brackets): arrival from
    Kanto 46 (49), after Whitney 52 (57), after Morty 53 (57), Lake of Rage
    57-58 (62-63), eight badges 63-64 (68), first Johto title 65 (70);
    afterwards it keeps rising (ceilings 100, D-031). The legendaries stay
    in the owner's range of 75-80 and so stand well above that player
    (Raikou and Entei +22 at the Burned Tower, the Glockenturm about +14).
  - Floor: on maps with Johto's or Hoenn's scaling, static and scripted
    encounters
    (`seteventmon`, `setwildbattle`, `setwildbattleshiny`) and roamers are
    at least the top of the map's wild band (anchor - 4, clamped to the
    corridor; `ScaleStaticMonLevel`, `src/level_scaling.c`). Before the
    title the corridor ceilings cap it, so it lifts a Pokemon only for
    players above that corridor (e.g. Sudowoodo to 53). Raikou and Entei
    stay at 75 until then: their routes (`sRoamerLocationsJohto`, Routes
    29-39, 42-46 and 48) reach at most 64 (Routes 44 and 45). After the
    title it lifts the returns of D-026 and the roamers with the player.
    Kanto and unscaled maps (Birth Island, the Kampfzone) keep fixed levels
    (`staticFloor` in `src/level_scaling.c`).
  - A legendary in the party counts for the anchor like any other
    Pokemon (D-012): a Raikou, Entei or Celebi at 75 lifts the anchor to
    at least 67, and trainers and wild Pokemon then sit at the corridor
    ceilings until the league. In the box it does not count. The owner
    keeps this (2026-11-02, D-053): the scaling follows the team the
    player uses.
  - Roamers keep the level they started with. Raikou and Entei start at
    their level in `src/legendaries_oj.c`; a roamer below it, or below the
    floor, moves up at its next encounter and keeps its share of HP
    (`TryRaiseRoamerLevel`, `src/roamer.c`).
  - Kanto: D-011, Hoenn: D-043.
- **Evidence:** decision 2026-10-27.

### D-040 Hoenn keeps its own state where a finished Kanto would leak into it
- **Status:** Active (2026-10-29, Johto leaks changed 2026-10-30, Strength
  and Flash changed 2026-10-30; changed 2026-11-02: Lilycove's lottery)
- **Decision:** A finished Kanto or Johto must not unlock or change Hoenn
  content. Where FRLG or HnS and Emerald share a flag or var, Hoenn gets its
  own state or checks the Hoenn title:
  - Trainer Fan Clubs: Saffron's club (`src/trainer_fan_club.c`) uses
    `VAR_SAFFRON_FANCLUB_FAN_COUNTER` / `VAR_SAFFRON_FANCLUB_LOSE_FAN_TIMER`;
    `VAR_FANCLUB_FAN_COUNTER` / `VAR_FANCLUB_LOSE_FAN_TIMER` are Lilycove's.
    The Kanto title fills Saffron's club, the first Hoenn title Lilycove's;
    the fans are separate. Link battles, contests, Secret Base battles and
    the HnS Battle Tower count for Lilycove's club, as in Emerald.
  - `FLAG_HOENN_RECEIVED_POKENAV`: Mr. Stone's PokeNav scene at Devon (Mr.
    Briney's location, the Devon scientist, the Rustboro boy).
    `FLAG_RECEIVED_POKENAV` stays Mom's PokeCom and is not read any more.
  - `FLAG_HOENN_REGISTER_RIVAL_POKENAV`: May registered on Route 104
    (Emerald's meaning; it places her on Route 104 until Rustboro or
    Dewford). Route 103 registers May through `FLAG_ENABLE_RIVAL_MATCH_CALL`
    only, so Route 104 shows her PokeCom line once.
  - `FLAG_HOENN_RECEIVED_HM_SURF`: Norman's Surf license, read by Wally's
    parents. `FLAG_RECEIVED_HM_SURF` stays the Ecruteak theater's.
  - `FLAG_HOENN_RECEIVED_HM_ROCK_SMASH`: Mauville's Rock Smash man (and the
    hint man on Route 111 he hides); `FLAG_RECEIVED_HM_ROCK_SMASH` stays
    Route 36's.
  - `FLAG_HOENN_RECEIVED_REVIVED_FOSSIL_MON`: Devon's fossil revival, read by
    the Fossil Maniac on Route 114; `FLAG_RECEIVED_REVIVED_FOSSIL_MON` stays
    the Ruins of Alph lab's.
  - `FLAG_HOENN_RECEIVED_HM_STRENGTH`: the Rusturf Tunnel scene (no HM in
    Hoenn), read by the PokeNav calls of Mr. Stone and the rival;
    `FLAG_RECEIVED_HM_STRENGTH` stays the Olivine cafe sailor's. The Granite
    Cave hiker gives no HM Flash and sets no flag; `FLAG_RECEIVED_HM_FLASH`
    stays Sage Li's in Sprout Tower.
  - `VAR_HOENN_SAFARI_ZONE_STATE`: Hoenn's Safari Zone. Time up, no Safari
    Balls left or retiring there leads back to the Route 121 entrance
    (`data/scripts/safari_zone.inc`), not to Johto's gate;
    `VAR_SAFARI_ZONE_STATE` stays the Johto gate's.
  - Lottery: Lilycove's Department Store draws
    its own ticket each day. `FLAG_HOENN_PICKED_LOTO_TICKET` (cleared with
    the daily flags in `ClearDailyFlags`) and the prize waiting for room
    in the bag (`VAR_HOENN_POKELOT_PRIZE_ITEM`,
    `VAR_HOENN_POKELOT_PRIZE_PLACE`) are Lilycove's;
    `FLAG_DAILY_PICKED_LOTO_TICKET` and `VAR_POKELOT_PRIZE_*` stay
    Goldenrod's Radio Tower. Lilycove's number is the upper half of the
    daily lottery number (`RetrieveHoennLotteryNumber`,
    `src/lottery_corner.c`), Goldenrod's and the Lucky Channel's the lower
    half, so the two draws differ.
  - Hoenn post-game checks use `FLAG_IS_HOENN_CHAMPION`, not
    `FLAG_SYS_GAME_CLEAR`: the Hoenn gym leaders' rematch calls, Secret Base
    battles, TV mass outbreaks, PokeNews and the Battle Tower profile show,
    post-game contest opponents.
  - `FLAG_SYS_GAME_CLEAR` keeps the meaning "a league was won": the PC's
    Hall of Fame option, easy chat word groups, link and Colosseum/XD data,
    Kanto's own scripts, the gatehouse (D-009), the Trainer Hill prize lists
    and Prof. Birch staying in his lab (he never does Emerald's field work).
  - Mr. Stone's thank-you gift: every game starts with the Exp. Share (key
    item); if it is in the bag he gives the held Kleiner EP-Teiler instead.
  - Petalburg's Pokemon Center woman never reads `VAR_STARTER_MON` (Kanto's
    starter) in Origin Jade (`#if IS_HNS`).
  - Other builds map the new names to the vanilla flags and vars
    (`include/constants/flags.h`, `vars.h`).
- **Evidence:** full Kanto run analysis, decision 2026-10-29; owner
  2026-10-31 (Hoenn's own lottery ticket).

### D-041 Johto keeps its own state where a finished Kanto would leak into it
- **Status:** Active (2026-10-29, Kanto cap table changed 2026-10-30)
- **Decision:** A finished Kanto must not unlock or change Johto content:
  - Badge-based marts (`pokemart 0`: Violet City, the Trainer Hill clerk by
    Route 40) count Johto badges (`GetNumberOfBadges`, `src/shop.c`).
    Rematch stages: D-012.
  - The Trainer Hill by Route 40 is Johto post-game and opens with
    `FLAG_IS_JOHTO_CHAMPION` (HnS: `FLAG_SYS_GAME_CLEAR`).
  - Key items are not handed out twice: Silph's president takes the Card
    Key (Türöffner) back after Giovanni, so the Radio Tower director's Card
    Key story runs as in HnS; Goldenrod's bike shop gives no second Bicycle
    and sets `FLAG_GOT_BICYCLE` when it gives one; the Coin Case ball in
    Goldenrod's underground holds a Nugget if the Coin Case is in the bag
    and otherwise sets `FLAG_GOT_COIN_CASE`; the aide on Route 15 gives the
    Kleiner EP-Teiler (every game starts with the Exp. Share key item).
  - The M.S. Aqua's arrival in Vermilion no longer carries HnS's Kanto
    reset.
  - After each Kanto title the plateau scene ends with
    `special ClearCreditsSceneState`, which restores map name popups, map
    music and sound effects (FRLG's credits did this).
  - Level-cap challenge (`src/caps.c`): Kanto badges table (values in
    D-011) until the Kanto title, then 70 until `FLAG_IS_JOHTO_CHAMPION`,
    then no cap.
- **Evidence:** full Kanto run analysis, decision 2026-10-29.

### D-042 Gen 5 experience in every region
- **Status:** Active (2026-10-29)
- **Decision:** Experience follows Gen 5 everywhere (`B_SCALED_EXP` Gen 5,
  `include/config/battle.h`): base experience / 5, weighted by the level
  difference, so Pokemon behind the foe catch up and those far ahead gain
  little. On top of that:
  - trainer battles x1.5 (`B_TRAINER_EXP_MULTIPLIER` Gen 3);
  - the classic split with the Exp. Share key item from the start
    (`B_SPLIT_EXP` Gen 5, D-011);
  - damping by the receiving Pokemon's level: 100 % up to 30, 70 % at
    31-60, 50 % from 61 (`EXP_DAMP_*`, `include/config/hoenn_scaling.h`);
  - the challenge menu's experience rate.
  The levels of all three regions are tuned for the average player (D-011,
  D-012); rushers have to train.
- **Evidence:** decision 2026-10-29.

### D-043 Hoenn's static and legendary levels fit the scaling
- **Status:** Active (2026-10-29). Replaces the fixed Hoenn levels of D-026
  and D-031.
- **Decision:** The player reaches level 100 in Hoenn. Its legendaries sit
  at 100, the other static encounters at the player's level where they are
  met, rounded (old in brackets):
  - Regirock, Regice and Registeel: 100 (40);
  - Groudon, Kyogre and Rayquaza: 100 (70);
  - Latias and Latios, roaming after the first Hoenn title: 100 (40);
  - Kecleon on Routes 119 and 120: 80 (30);
  - New Mauville's Voltorb: 75 (25);
  - the Aqua Hideout's Electrode: 85 (30).
  - Floor as in Johto: static and scripted encounters and roamers on Hoenn
    maps are at least the top of the map's wild band (D-039).
  - Gifts keep their levels (Castform 25, the fossils 20, Beldum 5).
- **Evidence:** decision 2026-10-29.

### D-044 One Trainer Hill: HnS's by Route 40
- **Status:** Active (2026-10-30; changed 2026-11-02: Emerald's hill on
  Route 111 retired, owner S-05)
- **Decision:** Only HnS's hill by Route 40 is in the game (Johto
  post-game, D-041): HnS trainers, party at level 50, item prizes plus
  money, records in SaveBlock1 (`trainerHillTimes`). HnS's endgame counts
  (owner 2026-11-02).
  - Emerald's hill on Route 111 is retired: the owner removed its building,
    warp and sign from Route 111 (06ea236bdb); its seven maps
    (`TrainerHill_Entrance`, `TrainerHill_1F` to `_4F`, `TrainerHill_Roof`,
    `TrainerHill_Elevator`) and seven layouts (with
    `LAYOUT_BATTLE_ELEVATOR`, used otherwise only by the retired Emerald
    frontier) carry game_version `em_trainer_hill_retired`. The script and
    text of the Route 111 sign and Route 111's reset of
    `VAR_TRAINER_HILL_IS_ACTIVE` are gone. The PokeNav map no longer lists
    the hill as a landmark on Route 111 (`src/landmark.c`).
  - What made Emerald's hill work stays in the code, unused: Emerald's
    trainers, floors and prizes selected by the map layout in
    `src/trainer_hill.c` (`IsHnsTrainerHill`), `trainerhill_inhoennhill`,
    and its records in SaveBlock3 (`trainerHillTimesHoenn`; the save layout
    stays). Bringing it back needs the maps active again and an entrance on
    Route 111.
- **Evidence:** decision 2026-10-30 (make the Route 111 hill work instead of
  retiring it); owner answers 2026-11-02 (S-05).

### D-045 Nuzlocke rules
- **Status:** Active (2026-10-30; changed 2026-10-30: static encounters,
  eggs, nicknames of starters and gifts; changed 2026-11-02: Trainer
  Hills, Route 41 and battles with an AI partner as in HnS, D-054). The
  end point waits for the owner's confirmation (O-025).
- **Decision:** The challenge menu's Nuzlocke (`src/nuzlocke.c`) works like
  this in Origin Jade:
  - Start and end: it starts at Oak's Pokedex handover in Kanto
    (`FLAG_START_NUZLOCKE`, D-004) and ends at the first Hoenn title, the end
    of the game (`FLAG_END_NUZLOCKE`, set in Hoenn's Hall of Fame before the
    save, D-028). Red on Mt. Silver does not end it. Afterwards none of its
    rules applies: no encounter limit, no deaths, no nickname rule, no save
    deletion on a whiteout.
  - First encounter per area (Normal and Hart; map sections, `sNuzlockeLUT`):
    the first single wild battle in an area uses it up, caught or not.
    These do not use it up: trainer battles, double wild battles, scripted
    static encounters, legendary and roamer battles, the
    Safari Zone and the Bug-Catching Contest (free catching there), battles
    in which catching is impossible (`FLAG_NO_WILD_CATCHING`, e.g. Route 41's
    Tentacruel; the Pokemon Tower's ghosts without the Silph Scope and the
    Marowak ghost, `BATTLE_TYPE_GHOST`), an off-type Pokemon under the One
    Type Challenge, a Pokemon blocked by the species clause ("Duplikate")
    and a shiny under the shiny clause. Code: `HandleEndTurn_FinishBattle`
    (`src/battle_main.c`).
  - Shiny clause ("Shiny-Klausel"): a shiny can always be caught, and
    meeting one never uses up the area.
  - Static encounters: scripted battles (`setwildbattle` with
    `dowildbattle`: Snorlax on Routes 12 and 16, Sudowoodo on Route 36 and
    at the Battle Frontier, Union Cave's Lapras, the Electrode of the Power
    Plant, the Rocket Hideout and the Aqua Hideout, New Mauville's Voltorb,
    Kecleon on Routes 119 and 120) can always be caught, without the area,
    species or dupes check, and use up nothing (`NuzlockeIsStaticEncounter`,
    set in `BattleSetup_StartScriptedWildBattle`). Legendaries are free as
    well (see above).
  - Eggs always hatch, in any area, and use up no area.
  - Deaths: a Pokemon that faints dies when the battle ends (or when it
    faints from poison in the field): released, or moved to the PC as
    unusable ("Friedhof", always in Leicht). No deaths in Trainer Hill,
    Battle Frontier, link, first-battle and catch-tutorial battles, nor in
    the Bug-Catching Contest (its party is restored afterwards). Battles
    with an AI partner (Lance in the Rocket Hideout, Troy in Mossdeep's
    Space Center) are skipped too, as in HnS (D-054): a Pokemon that
    faints there comes back into the party at 0 HP and dies at the end of
    the next battle unless it is healed first.
  - Whiteout: fainted party members die as above; eggs and members that can
    still fight stay. If none can fight, the first living Pokemon from the
    PC joins in the first free slot, a level 1 Rattata when the PC has none
    (`NuzlockeRefillPartyAfterWhiteOut`). Hart deletes the save instead.
  - Nicknames ("Spitzname"): caught and hatched Pokemon (also from gift
    eggs such as Togepi and Wynaut) and gifts through the common receive
    scripts (`Common_EventScript_GiftMon`) open the naming screen without
    asking. The rule does not wait for `FLAG_START_NUZLOCKE`; it holds
    from the start of the game. Other gifts do so through
    `Common_EventScript_AskNicknameGiftPartyMon` / `...BoxMon`
    (`data/event_scripts.s`) or the same check in their own script:
    - Kanto: the starter (Oak's lab), Lapras, Eevee, the Dojo's Pokemon,
      the fossils, the Game Corner prizes, the Magikarp on Route 4;
    - Johto: the starter, also when it goes to the PC (Elm's lab), the
      Game Corner prizes, Bill's Eevee, the elder's special Dratini, the
      fossils of the Ruins of Alph's lab, but not Kenya and Shuckie, who
      keep the nickname of their former trainer;
    - Hoenn: Castform (Weather Institute), the fossils at Devon, and after
      the title, outside the Nuzlocke, Beldum and Birch's Johto starters.
  - Trainer Hill (by Route 40, D-044): no deaths there, as in HnS (D-054,
    O-028). A Pokemon that faints stays in the party at 0 HP; leaving the
    hill after a loss heals the party, otherwise a Pokemon Center does.
  - Route 41's Tentacruel guards (level 100, no catching): a Pokemon that
    faints there dies, as in HnS; the battle uses up no area (static
    encounter, see above).
  - Rules that differ from HnS and wait for the owner: O-055.
- **Evidence:** audit 2026-10-30 (A23, A25, A30, A79, A83, A87); owner
  decision 2026-10-30 (rules as usual in the Nuzlocke community: static
  encounters and eggs are free).

### D-046 Only Origin Jade is built
- **Status:** Active (2026-10-30, changed 2026-10-31: region check in the
  CI, debug states D-050; changed 2026-11-02: "Even Wild Slots", D-055)
- **Decision:** The make process builds only Origin Jade: `GAME_VERSION`
  `POKEMON_HNS` (so `IS_HNS`), map version `hns`, title "POKEMON JADE",
  `Pokemon_Origin_Jade.gba`. `make`, `make jade`, `make check`,
  `make release` and `make debug` all build it; the emerald, firered,
  leafgreen and hns targets are gone, and a `BUILD=` other than `jade` stops
  with an error. The other versions' code (`#if FIRERED`, `#if EMERALD`, ...)
  stays in the sources so HnS and expansion merges stay small; it is neither
  built nor checked.
- **Rules / code:** top of `Makefile`. Generated sources (trainer parties,
  teachable learnsets) always use the jade defines.
- **Checks:** the CI workflow (`.github/workflows/build.yml`) builds the
  ROM and the release ROM on every push and pull request, prints their
  SHA-1 and runs `tools/check_warnings.py` (no warning beyond
  `tools/warnings_baseline.txt`), `tools/check_flags.py`,
  `tools/check_regions.py` (D-049), `tools/make_debug_states.py
  --check` and `tools/check_budget.py`;
  `check_merge.py` runs without blocking. Map errors that are unreachable
  or intended go into its `KNOWN_ERRORS` with the decision that covers
  them. The upstream Docs and Labels workflows run only by hand.
- **Debug menus:** the overworld debug menu (R + Start, with "Johto Test"
  and "Hoenn Test", D-050, and the switch "Even Wild Slots", D-055),
  the battle debug menu (Select) and the sprite visualizer are on in the
  normal build (beta testing) and off in `make release`
  (`DISABLED_ON_RELEASE`, `include/config/debug.h`).
- **Evidence:** owner decisions 2026-10-30 (only Jade; debug menus on in
  the beta, off in the release).

### D-047 Hoenn Ticket story and ports
- **Status:** Active (2026-10-31; changed 2026-11-02: "Hoenn" stays until
  Slateport's harbour can be sailed to, O-032; Troy's sprite, O-031).
  Resolves O-002.
- **Decision:**
  - At the first Johto title Oak and an unknown man ("???", Troy) come
    into Johto's Hall of Fame after the record. Troy talks only to Oak (he
    urgently needs to speak to him and waits in his lab) and leaves; Oak
    then briefly asks the player to come to his lab at home. The scene sets
    `VAR_HOENN_TICKET_STATE` 1 before the Hall of Fame saves. Title
    defences have no such scene.
  - Troy (Steven) brings the Hoenn Ticket. He waits in Oak's lab from the
    first Johto title on (`VAR_HOENN_TICKET_STATE` 1): Oak and Troy stand
    side by side and face each other. Entering the lab starts the scene;
    from the door the player walks up to them. Oak introduces Troy as the
    former champion of Hoenn (Wallace stays the champion of Hoenn's
    league), says vaguely that the balance of land and sea in Hoenn is in
    danger because Team Magma and Team Aqua are up to something, and asks
    the player to travel to Hoenn. Troy: as champion of Kanto and Johto
    the player is strong enough, he has to follow his own research. He
    hands over the ticket for the ferries in Vermilion City and Olivine
    City ("Ich erwarte dich in Hoenn") and leaves (state 3). With a full
    bag he stays (state 2) and hands it over when talked to; Oak points to
    him meanwhile.
  - Saves already past the first Johto title that have not been to Hoenn
    arm the scene on entering the lab (D-005).
  - Troy has Emerald's sprite `OBJ_EVENT_GFX_STEVEN`, the one of the
    Hoenn maps, everywhere: in Johto's Hall of Fame, in Oak's lab and in
    Hoenn (owner 2026-11-02, O-031). HnS's `OBJ_EVENT_GFX_STEVEN_HNS` is
    left only on maps the jade build never reaches (HnS's retired Kanto
    maps, the locked Sinjoh maps, a test map).
  - The ship menus in Vermilion, Olivine and on the islands (Kampfzone,
    Birth Island) are built on every visit and list only what can be
    sailed to now:
    - "Hoenn" from the Hoenn Ticket (`VAR_HOENN_TICKET_STATE` 3) as long
      as "Graphitport City" is not offered; every trip with it lands on the
      Route 104 pier (D-029). Only the first trip arms Birch's greeting
      there (`VAR_HOENN_ARRIVAL_STATE` 1); later trips land without an
      event. So a player without a flyer always has a way back to Hoenn
      (O-032).
    - "Graphitport City" replaces "Hoenn" after Birch's welcome
      (`VAR_HOENN_ARRIVAL_STATE` 3) once Slateport was visited and while
      its harbour can be used: it is open from the first visit and closed
      only for Team Aqua's submarine scene (`VAR_SLATEPORT_HARBOR_STATE`
      1, from Groudon's awakening in the Magma Hideout until the scene in
      the harbour; a ship would land on the trigger tiles of that scene,
      (8,11) to (8,14)). While it is closed, "Hoenn" is offered again. It
      lands in Slateport's harbour (8,11).
    - "Seegrasulb City" is added after the welcome once Lilycove was
      visited; Lilycove's harbour is never closed by the story. It lands in
      Lilycove's harbour (8,11).
    - Without such a visit no ship goes to a harbour. Fly to Littleroot
      Town always works, because the first crossing marks it visited.
  - The Hoenn ferry runs from both ports as soon as the player has the
    ticket, also before the M.S. Aqua's maiden voyage: Vermilion then
    offers only the Hoenn entries, Olivine the maiden voyage ("Orania
    City") and the Hoenn entries.
  - No ship sails from Slateport or Lilycove to Kanto or Johto before the
    Hoenn title; Fly is enough. The S.S. Tidal is unchanged (to the
    Kampfzone after the Hoenn title, D-030). The island sailors list
    "Hoenn", "Graphitport City" and "Seegrasulb City" under the same
    conditions as the ports, so also before the Hoenn title.
  - The static lists `MULTI_OLIVINE_HARBOR`, `MULTI_VERMILION_HARBOR` and
    `MULTI_SSAQUA_RETURN(_PORTS)` are no longer used.
  - Oak no longer sees the player off at the Olivine port (HnS's National
    Dex scene, "maybe to Hoenn someday"): his object and scene are gone,
    and Elm's M.S. Aqua news after the first Johto title no longer sends
    the player there.
  - The Hoenn Ticket is a key item (`POCKET_KEY_ITEMS`, importance 1): it
    cannot be sold, tossed or stored, and the item randomizer leaves it
    alone (only key items, HMs and the GS Ball are exempt). Scripts hand it
    over with `giveitem_norandom`. It stays in the bag after the crossing
    as a souvenir.
- **Code:** `PokemonLeague_HallOfFame_hns` (`OakAndTroy`, both objects
  hidden by `FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK` until `addobject`);
  `PalletTown_ProfessorOaksLab_Frlg` (`SetupTroy`, `TroyScene`,
  `FLAG_HIDE_OAKS_LAB_TROY`); `Common_EventScript_ShipMenu`, the
  `Common_EventScript_CheckShipTo*` and `Common_EventScript_SailTo*`
  scripts in `data/scripts/hoenn_arrival.inc`, `SHIP_DEST_*` and
  `SHIP_PORT_*` in `include/constants/script_menu.h`;
  `VAR_HOENN_TICKET_STATE` in `include/constants/vars_hoenn_de.h`;
  `ITEM_HOENN_TICKET` in `src/data/items.h`.
- **Evidence:** owner decisions 2026-10-31 (plan part A, Hoenn Ticket
  story); owner answers 2026-11-02 (O-031, O-032).

### D-048 Hoenn: an unknown trainer, Norman is not the father
- **Status:** Active (2026-10-31; changed 2026-11-02: decorations in
  Pallet Town, O-029; continue point in front of the stairs, O-041;
  family objects removed, O-030)
- **Decision:** In Hoenn the player is a stranger. Apart from Troy, who
  brought the player to Hoenn, and Wallace (below), nobody there knows that
  the player is the champion of Kanto and Johto or where exactly they come
  from; a few people have vague news (from the mainland, a strong trainer).
  Norman knows only the rumours: the player comes from the mainland and is
  a good trainer. Norman is a regular gym leader whose family lives in
  Littleroot Town (D-002, D-003). He is never the player's father, and no
  text the jade build can show says so. The always hidden objects of
  Emerald's player family are gone from the Littleroot Town maps (owner
  2026-11-02, O-030, below).
- **Rules / code:**
  - Using an item at the wrong place shows "Birk sagt immer…"
    (`gText_BirchsAdvice`) on Hoenn maps and on Emerald maps outside Kanto,
    as Oak does in Kanto and Elm in Johto (`GetCannotUseItemText` in
    `src/item_use.c`, also the Battle Pyramid bag). `gText_DadsAdvice` is
    not built.
  - Who knows what: Norman only the rumours (his call, battle and PokeNav
    texts). Birch and his family know from Troy that a strong trainer from
    the mainland is coming; May (Route 103, Route 110, Lilycove) and Birch's
    son speak only of that. Others have at most heard of a strong trainer
    from afar: Sidney, Glacia and Drake in the league, Scott's call after
    the Sootopolis badge; the man in Slateport's mart only thinks the player
    looks like a pro. Wallace may know more, because Troy, the former
    champion, told him; his speech stays.
  - The German texts this entry added or changed are drafts for the owner
    to review.
  - The Petalburg gym opens as before with the fourth Hoenn badge (owner
    2026-10-31). From `VAR_PETALBURG_GYM_STATE` 6 (open) on, the mart
    woman, the man in the Pokemon Center, the gentleman, Wally and his
    mother no longer say that the gym is closed or being rebuilt.
  - Norman's PokeNav call: before his battle "my gym is open, I am still
    waiting", between his defeat and the Hoenn title its own text
    (`MatchCall_Text_NormanAfterBadge`, `MatchCall_GetMessage_Trainer`),
    after the title his rematch texts as before.
  - Norman's son's room (Brendan's house, 2F) and May's room are theirs:
    the PC there shows an e-mail, never the player's bedroom PC, and the
    player's room decorations are not set up in either room. The PC upstairs
    in the New Bark Town house runs the same script as Brendan's and shows
    the e-mail too (D-002); that room has no decoration objects, so nothing
    is set up there either.
  - The player's room decorations (dolls and cushions placed with
    "Dekoration" at the bedroom PC) are set up in the player's room in
    Pallet Town, the only room with the player's PC (owner 2026-11-02,
    O-029): ON_TRANSITION `SecretBase_EventScript_SetDecorationFlags`, ON_WARP
    `SecretBase_EventScript_InitDecorations`, the twelve decoration objects
    of HnS's room (`FLAG_DECORATION_1` to `_12`, saved flags that the
    room sets again on every visit). The room uses HnS's bedroom layout
    (since `23e37d3239`), whose floor holds decorations almost
    everywhere, also around the bed; the PC does not check whether a doll
    cuts a tile off. After a title (Kanto, every Johto title, Red) the game
    therefore continues at (9,3) in front of the stairs, a floor tile that
    never holds decorations, next to the stairs warp (9,2):
    `HEAL_LOCATION_PALLET_TOWN_PLAYERS_ROOM` and the warp after the Kanto
    credits scene (`IndigoPlateau_Exterior_Frlg`). Dolls cannot box the
    player in there. A new game still starts at (6,6) next to the bed,
    before any decoration (O-041).
  - Emerald's scenes in which the player is Norman's child are not built
    for jade (`#if !IS_HNS`; the source stays for merges, D-046). Labels
    that `map.json` or a map script table needs stay as empty stubs. Not
    built: the player's house in Littleroot Town (moving in, Dad on TV,
    Mom's PokeNav, the Amulet Coin, Dad's S.S. Ticket and the Lati news);
    Norman's wife's and Birch's wife's greeting at the first visit ("from
    Johto"; only Emerald's moving truck started it);
    May's or Brendan's greeting of the new neighbour in their house ("a gym
    leader's kid"); the arrival with Mom in the moving truck and her
    Running Shoes in front of the house ("your father will be overjoyed");
    Birch's starter gift after the rescue ("your father's blood"); Dad's
    PokeNav call on Mr. Briney's boat; the Hall of Fame step that brings
    Dad home with the S.S. Ticket; Brendan's Go-Goggles line in Lavaridge
    ("your dad"); `gText_Dad`; Mom coming upstairs after the first wall
    clock setting ("your new room"; the wall clock only sets the time). The
    Enigma Berry and the Mystery Event berry, both off in Origin Jade, name
    Norman instead of "Vater".
  - No hidden objects of the player's family are left in Littleroot Town
    (O-030): Dad with Norman's sprite on the ground floor of both houses,
    Mom on both floors of both houses and Mom in front of them are removed
    from the maps. The scripts that placed them (`MoveMomTo*`,
    `SetMomStandingInFrontOfDoorPos`) and the empty stubs
    `PlayersHouse_1F_EventScript_Mom` and `LittlerootTown_EventScript_Mom`
    are not built, the Hoenn arrival no longer sets their hide flags, and
    Emerald's heal locations of the two houses (unused in jade) have no
    healer. The non-jade scenes that still name these objects (D-046) are
    not built either. The function that shows the cannot-use line is
    `DisplayAdviceCannotUseItemMessage` (Emerald's
    `DisplayDadsAdviceCannotUseItemMessage`); `gText_DadsAdvice` is only in
    the non-jade branches.
- **Evidence:** owner requirements 2026-10-31 (point 4); owner answers
  2026-11-02 (O-029: set up in Pallet Town; O-030: remove).

### D-049 Pokemon per region
- **Status:** Active (2026-10-31, owner decision; changed 2026-10-31:
  Celadon's diploma names the Kanto Pokedex; changed 2026-11-02: Jirachi
  on Route 4, the rule is off with any randomizer option, stars as on the
  trainer card)
- **Decision:** Kanto has only Kanto Pokemon, Johto adds Johto's and Hoenn
  adds Hoenn's: before a region is unlocked, no source hands out a species
  of that region. Evolutions are exempt: a Golbat may become a Crobat in
  Kanto, so every evolution stays possible early. There is no Pokedex
  filter; the National Pokedex stays as it is.
  - Regions of the 422 enabled species (`GetSpeciesRegion`): national
    numbers 1-151 are Kanto, 152-251 Johto, 252-386 Hoenn. Babies and later
    evolutions (Gen 4, 6, 8 and 9) of Kanto and Johto lines count to Johto
    (Pichu, Crobat, Magnezone, Sylveon, Kleavor ...), those of Hoenn lines
    to Hoenn (Budew, Gallade, Dusknoir ...). Kanto 151, Johto 129, Hoenn
    142, so 280 species after Johto. Forms count as their species.
  - Unlocked (`IsRegionUnlocked`): Kanto always. Johto on the first Johto
    map after the Kanto title (`FLAG_JOHTO_UNLOCKED`, set on every map
    load); the gatehouse south of Route 23 (`ReceptionGate_hns`, D-009) does
    not count. Catch-ups (D-005): `FLAG_JOHTO_ARRIVAL_DONE`,
    `VAR_JOHTO_HANDOVER` 3, Hoenn unlocked. Hoenn with the first trip there
    (`VAR_HOENN_ARRIVAL_STATE` 1 or more). The current map does not decide:
    `GetCurrentRegion` counts the Kampfzone and Birth Island as Hoenn.
    Oak's Johto extension of the Pokedex at the GS Ball handover stays a
    text.
  - Fixed sources changed for the rule:
    - Cerulean Cave: FireRed's tables (1F, 2F, B1F) and the overworld
      Pokemon on 2F have Ditto, from FRLG's own table of the cave, in
      Wobbuffet's place (same level).
    - Deoxys: the Aurora Ticket only after the first trip to Hoenn (D-029).
    - Item randomizer: Root and Claw Fossil are no longer rolled; Ruins of
      Alph's lab would revive them in Johto (D-023).
    - Morty's first team (`TRAINER_MORTY_1_HNS`): a second Misdreavus
      (level 25, Astonish, Confuse Ray, Mean Look, Hex) in Duskull's
      place. Rematch teams keep their species.
  - Day Care eggs (`GetUnlockedEggSpecies`, called in
    `DetermineEggSpeciesAndParentSlots`): an egg of a region not unlocked
    yet gets the first stage on the way to the mother's species (or the
    non-Ditto parent's) whose region is unlocked: Pikachu instead of Pichu,
    Chansey instead of Happiny, the parent's Hitmon instead of Tyrogue in
    Kanto; Marill instead of Azurill, Wobbuffet instead of Wynaut in Johto.
    Babies hatch normally once their region is unlocked; an egg keeps its
    species. With no unlocked stage between egg and parent (a Hitmontop
    parent before Johto) the egg keeps its species too; no such parent can
    be had before the unlock. Not while any randomizer option is on
    (owner 2026-11-02, O-033; `IsAnyRandomizerOptionOn`): wild, trainer,
    item, fixed Pokemon, starter, evolution, evolution method, type, type
    effectiveness, ability or move randomization. The randomizer mixes the
    regions on purpose (plan item C8); an egg then hatches as its parents
    make it, babies included. The modifiers (chaos, similar strength,
    map-based, legendaries) change nothing alone, and the item randomizer
    counts from the first Pokemon on (D-023). Two upstream tests in
    `test/daycare.c` expect a Pichu egg and are known failures.
  - Seen (`CanRegisterSeenSpecies`, battle end in `src/battle_main.c`): a
    Pokemon sent out in battle goes into the Pokedex as seen only if its
    region is unlocked or the player has caught one. Trainers keep their
    teams: Kanto's Elite Four and Blue's rematches after the Kanto title (7
    Johto species), the Johto gym and Elite Four rematches and Janine (21
    Hoenn species) and the evolutions of the level scaling. What they show
    early is not stored and counts once met again after the unlock, so the
    National Pokedex list (HnS's obtainable order up to the highest seen
    entry) does not jump into a later region's block. Without the
    randomizer, wild tables and static encounters offer no species of a
    later region, so this concerns trainers (plan item C7). Not while any
    randomizer option is on, as for Day Care eggs (O-033): random trainers
    may then fill the Pokedex with later species. Other
    sources (gifts, eggs, evolutions, trades) set seen and caught as
    before. The Pokedex's evolution page still names later evolutions and
    babies, as a help (owner 2026-11-02, O-034).
  - Kanto Pokedex (`GetKantoPokedexCount`, `HasAllKantoMons`): HnS's Kanto
    dex order keeps its 185 entries (`P_NEW_EVOS_IN_REGIONAL_DEX`), but the
    counts of Oak's rating and his aides and Celadon's diploma take only
    national numbers 1-151. Oak calls it complete with all 151 but Mew
    (`GetProfOaksRatingMessageByCount`; FRLG's threshold there was one too
    high with the expansion's `KANTO_DEX_COUNT`, so it never said
    complete). Celadon's diploma names the Kanto Pokedex, Lilycove's the
    Johto Pokedex, both the National Pokedex once `HasAllMons` reports it
    complete (`DisplayDiplomaText` in `src/diploma.c`, by the map it is
    shown on).
  - Johto Pokedex (`HasAllJohotoMons`, `GetPokedexRatingText`): HnS's
    Johto dex (282 entries) lists Azurill and Wynaut, which count to
    Hoenn. Elm's and Birch's rating and Lilycove's diploma (D-036) leave
    them out like the mythicals, so the Johto dex can be completed before
    Hoenn. The seen and caught numbers shown stay as they are.
  - Stars (owner 2026-11-02, O-039 option a): the trainer card, the
    nurse's Gold Card greeting (at four stars) and the Frontier Pass
    colour count the same stars, one each for the Johto, Kanto and Hoenn
    titles and for beating Red (`GetHnSTrainerStars`, which
    `CountPlayerTrainerStars` returns in this build). No Pokedex counts
    for them.
- **Code:** `src/region_rule_oj.c` (the table of national numbers above
  386), `TryUnlockJohtoOnMapLoad` in both map loads of `src/overworld.c`;
  test `test/origin_jade/region_rule.c`.
- **Check:** `tools/check_regions.py` (also in the CI): no wild table of
  an active Kanto map has a species of Johto or Hoenn, none of a Johto map
  one of Hoenn, and neither do the overworld Pokemon that show a map's
  species nor the gifts and static battles of the map scripts. Known
  exceptions: `Route22_hns` (Taillow), which cannot be entered (O-022);
  the Ruins of Alph lab's Lileep and Anorith (only from Hoenn's fossils);
  an uncalled test script at the Johto Safari Zone gate; Jirachi on
  Route 4 (only after the first trip to Hoenn, D-037). In the National
  Pokedex order (`enum ObtainableDexOrder`) every Kanto species lies in
  the Kanto block and every Johto species in the Kanto or Johto block, so
  the list cannot jump; `--dex-gaps` prints the blocks (Kanto 1-185, Johto
  186-282; the 34 Johto species of Kanto lines in the Kanto block, Azurill
  and Wynaut in the Johto block). Trainer parties and trades are not
  checked.
- **Why:** The regions open one after the other in the story (D-001); a
  species of a later region should first turn up there.
- **Evidence:** owner decisions 2026-10-31 (Pokemon per region, evolutions
  exempt, no Pokedex filter, Gen 4 evolutions of Kanto lines count to
  Johto). The Johto dex without Azurill and Wynaut follows the plan's
  Kanto 151 (C7) and the owner's 280 species after Johto (review
  2026-10-31).

### D-050 Debug states "Johto Test" and "Hoenn Test"
- **Status:** Active (2026-10-31, owner requirements; changed 2026-11-02:
  every obtainable item, O-035 answered)
- **Decision:** The overworld debug menu (D-046) sets two test states on a
  new game (before the first Pokemon); `tools/make_debug_states.py`
  generates both from the game data.
  - "Johto Test" (`src/data/debug_kanto_complete.h`): Kanto right after the
    first Kanto Hall of Fame. Every Kanto trainer, item, TM, HM and event,
    Kanto's eight badges and fly destinations; Oak waits with the GS Ball
    (`VAR_JOHTO_HANDOVER` 1). Johto and Hoenn stay locked (D-049). The
    player wakes up in their room in Pallet Town. Team as before (D-011):
    Charizard 49, Pidgeot 43, Raichu 44, Nidoking 43, Gyarados 42, Snorlax
    42.
  - "Hoenn Test" (`src/data/debug_johto_complete.h`, applied on top of the
    Johto Test): Kanto after its title and Johto done by a completionist.
    Johto's story, gyms (`VAR_JOHTO_BADGES` 0xFF, every permit), league
    and Red; the one-time encounters of both regions caught (birds, Mew,
    Mewtwo, Snorlax, Lugia and Ho-Oh, Celebi, Suicune, Raikou, Entei,
    Sudowoodo, Union Cave's Lapras, the red Gyarados; the generator takes
    Ho-Oh as the bird chosen on Route 39); the M.S. Aqua's maiden voyage;
    every item of both regions (see the generator rules); Kanto's and
    Johto's fly destinations; no badge flags 09-16.
    Untouched: the battle facilities (Kampfzone, the Trainer Hill), Sinjoh
    (locked, D-019), Hoenn, rematches and title defences. Johto is
    unlocked, Hoenn not. The player starts at the door of Oak's lab with
    `VAR_HOENN_TICKET_STATE` 1, so Troy's scene runs at once (D-047); the
    Hoenn Ticket is not in the bag before it. Team: Charizard 70, Meganium
    63, Gyarados 63, Ampharos 62, Nidoking 60, Espeon 60 (D-012), no
    legendary; Johto starter Chikorita.
  - Pokedex: every stage of the region's lines is seen and caught, babies
    and later evolutions included (Kanto lines 185 species; Kanto and Johto
    lines 282, Azurill and Wynaut included). Party and PC hold each final
    stage once, every branch, no living dex (owner): 81 for Kanto's 151
    (Golbat, Onix, Scyther ... are final there), 142 for Kanto and Johto.
    Mewtwo is in the Johto Test's PC and counts as caught; his cave opens
    after the title.
  - Items (owner, 2026-11-02, O-035): the bag holds everything the finished
    regions give, so the owner can see what a player can have. Found and
    received items with their count; key items and HMs once; at least one
    of every item a player can buy or get again: mart goods (also the
    Johto badge mart) and the Premier Ball a mart adds for ten balls, the
    Game Corner prizes, vending machines, merchants (Rage Candy Bar,
    Moomoo Milk), Kurt's balls, Bug-Catching Contest, lottery and Buena
    prizes, phone trainers' gifts, Mom's purchases, berry trees, Rock Smash
    finds, held items of in-game trades; in the Hoenn Test also the prizes
    and the shop of the Trainer Hill by Route 40 (Johto post-game, D-041);
    Goldenrod's mints and Mirror Herb only while the mints option sells
    them (`FLAG_MINTS_DISABLED` clear). Each pocket keeps 20 free slots for
    the next region; what does not fit goes into the PC's item storage
    (none so far: the Johto Test has 187 items, the Hoenn Test 297, the
    fullest pocket holds 107 of 236 slots). Money stays as without
    purchases.
  - Items left out, the generator's reading: link-only rewards (Wonder
    News, Berry Powder), decorations (not bag items), held items of wild
    Pokemon and Pickup (random finds), and the Kampfzone with everything
    bought with Battle Points (its BP exchange and that of the Trainer
    Hill's courtyard). Battle Points come only from the Kampfzone's
    facilities; the M.S. Aqua reaches the Kampfzone after the maiden
    voyage (D-029), but the states leave it untouched and
    `GetCurrentRegion` counts it as Hoenn (D-049). Open: O-060.
  - PC levels (owner): a level evolution at its evolution level (Pidgeot
    36); stone, trade, friendship, item and other evolutions at the
    pre-evolution's level + 2; single stages and legendaries at their
    catch level in this game.
  - PC levels, the generator's reading (O-035; owner 2026-11-02: the
    states need not be perfect): the catch level, also of a
    first stage below a later one, is in Kanto the highest level in
    Kanto's wild tables, else the gift or static level (D-011); in Johto
    the top of an average player's wild band where the species first
    appears (corridor floor + 2, D-012), else the gift or static level
    (D-039; Lugia 80, the chosen Ho-Oh 78); eggs and trades the band of
    their map (Togepi 43). A baby that only hatches does not count as the
    pre-evolution of a stage that can be caught (Wobbuffet from Wynaut,
    Sudowoodo from Bonsly). In the Hoenn Test the species of Kanto lines
    keep their Johto Test level, those of its party their party level
    (Pidgeot 43, Raichu 44, Snorlax 42).
  - Every Pokemon is usable: the player is the original trainer, Poke
    Ball, no egg; the debug states create them directly, so the randomizer
    does not change them. Hall of Fame count, champion ribbon and money
    (every prize, at most 9,999,999) as after the titles.
  - Challenge settings (Nuzlocke, randomizer, level caps, one type, mints)
    stay as chosen for the new game; the Hoenn Test leaves
    `FLAG_MINTS_DISABLED` alone (Goldenrod's flower shop clears it only
    after the Hoenn title).
- **Generator rules:** each state walks every script label its maps reach.
  A flag or var written with one value takes it; one written with several
  values, by `copyvar`/`addvar` or by C code behind a special needs a value
  in the generator's manual tables or a reason in `UNTOUCHED`. HnS's
  first-visit flag setup of a town (its "flag heap") counts only for names
  nothing else writes. Items: every map pickup (an object whose script
  runs `finditem`: FRLG's and HnS's item balls, HnS's Poke Ball objects,
  the Ruins of Alph's fossils) and hidden item is collected and in the
  bag, every gift too; of two gifts that exclude each other one counts
  (Ice Path's TM72); key items and HMs once. Once each: the lists of the
  `pokemart` commands the walk reaches (`pokemart 0`: every list of
  `src/shop.c`'s badge mart), the items of a label that takes money or
  coins (a purchase), gifts through a var (the script's own `setvar`
  values, C arrays in `VAR_GIFT_TABLES`, the phone trainers' arrays of
  `src/match_call.c`, `random` with `addvar`), `C_ITEM_SOURCES` (Mom's
  savings), the berry trees of the state's maps (`new_game.inc`), Rock
  Smash finds and held items of in-game trades; the Premier Ball of a
  mart list with a ball (`src/shop.c`, `I_PREMIER_BALL_BONUS`);
  `FACILITY_ITEMS` (the Route 40 Trainer Hill's prize lists of
  `src/trainer_hill.c` and its shop while the state sets
  `FLAG_IS_JOHTO_CHAMPION`); `VAR_GIFT_SKIP` lists the link-only gifts.
  A mart whose clerk is hidden by a flag the state leaves at its new game
  value (a challenge option, `UNTOUCHED`) adds the items only it sells
  while that flag is clear (`JOHTO_COMPLETE_OPTION_FLAG`).
  Not counted: purchases behind Hoenn progress. `--check` (CI) fails on a
  stale header, on a written flag or var that is neither in the state nor
  listed, on a value the state takes from a write that runs only after Hoenn
  progress (`FLAG_IS_HOENN_CHAMPION`, `VAR_HOENN_*`), on a list entry that
  nothing writes any more, on a pickup or hidden item not collected, and on
  a state that would unlock Johto or Hoenn too early, misses a fly
  destination, sets a badge flag 09-16, owns more or fewer Pokemon than the
  final stages, holds the Hoenn Ticket or leaves no room for it. It also
  fails on a gift through a var, a mart list or a berry tree it cannot
  resolve, on an item table entry nothing uses, on a `FACILITY_ITEMS` flag
  state B does not set or prize lists without items, on an item without a
  pocket, and on a pocket or the PC's item storage over its slots.
- **Replaces:** the hand-written Hoenn quick start (wrong Kanto fly flags,
  badge flags 09-16, Rayquaza and Kyogre at level 100, a ticket var nothing
  read, start at the Olivine port) and the Johto Test's living dex.
- **Code:** `tools/make_debug_states.py`; `Debug_SetJohtoTestState`,
  `Debug_SetHoennTestState` and the menu actions in `src/debug.c`;
  `Debug_EventScript_JohtoTestWarpHome`, `Debug_EventScript_HoennTestWarpLab`
  in `data/scripts/debug.inc`; test `test/origin_jade/debug_states.c`.
- **Evidence:** owner requirements 2026-10-31 (points 6, 7, 11, 14, 17);
  plan part D; owner answers 2026-11-02 (O-035 and its addendum: every
  other item of the region once, pocket sizes checked, overflow into the
  PC).

### D-051 Calls by region and the calls after a title
- **Status:** Active (2026-11-02)
- **Decision:**
  - Hoenn's calls ring only in Hoenn. The calls that start after a number
    of steps outdoors count those steps only on Hoenn maps
    (`IsHoennMapsec`); outside Hoenn they wait and come after the return:
    Wally's call after his battle in Mauville (he registers in the
    PokeNav), Roxanne's registration call, Scott's call after the Fortree
    badge, the rival's call after the Space Center (May or Birch's son) and
    Norman's call when his gym opens (D-048).
  - No other Hoenn call rings on its own: random trainer calls need a call
    text, which only HnS's Johto trainers have, and Birch is only called
    by the player. Kanto's and Johto's calls (Mom, Elm, HnS's trainers)
    are unchanged.
  - After the first Hoenn title Scott calls (Emerald's call and text,
    kept): he is aboard the S.S. Tidal and invites the player to take the
    ferry in Slateport or Lilycove. The Hall of Fame arms it
    (`FLAG_SCOTT_CALL_BATTLE_FRONTIER`); it comes after 10 steps outdoors
    in Hoenn, normally right after the title in Littleroot Town (D-028).
    On board Scott invites the player to the Kampfzone, which the ferries
    list from then on (D-030). Whoever meets him on board before the call
    does not get it any more.
  - Elm's call after the first Johto title ("I have news, come by my
    lab") comes as in HnS right after the title at home: HnS continued in
    New Bark Town and started it on the town's first frame
    (`VAR_NEWBARK_TOWN_STATE` 6); Origin Jade wakes the player up in
    Pallet Town (D-028), so Pallet Town starts it too, on the first step
    out of the house. It no longer waits for a visit to New Bark Town,
    which could come after the M.S. Aqua's maiden voyage or after Hoenn
    (O-036). Elm's lab text (the M.S. Aqua sets sail) is unchanged.
- **Code:** `HOENN_CALL_WAITS` in `ShouldDoWallyCall`,
  `ShouldDoScottFortreeCall`, `ShouldDoScottBattleFrontierCall`,
  `ShouldDoRoxanneCall`, `ShouldDoRivalRayquazaCall`; `ShouldDoNormanCall`
  (`src/field_specials.c`);
  `EverGrandeCity_HallOfFame_EventScript_SkipDexUpgradeEvent`
  (`data/scripts/hall_of_fame.inc`),
  `LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall`,
  `SSTidalCorridor_EventScript_ScottScene`; `PalletTown_OnFrame` and
  `NewBarkTown_OnFrame` (`NewBarkTown_EventScript_ElmCallAfterLeague`).
- **Evidence:** owner answers 2026-10-31 (S-02, S-07) and 2026-11-02
  (O-036: as in HnS).

### D-052 Day Cares per region, Bill's PC
- **Status:** Active (2026-11-02, owner decisions 2026-10-31)
- **Decision:** Kanto (Route 5), Johto (Route 34) and Hoenn (Route 117)
  each have their own Day Care; Pokemon, steps and eggs left in one region
  stay there (owner: no shared storage).
  - The Day Care scripts and specials work on the Day Care of the current
    map's region (`GetCurrentDaycare`, `src/daycare.c`, by
    `GetCurrentRegion`).
  - Storage: Hoenn's is Emerald's `gSaveBlock1Ptr->daycare` (SaveBlock1
    has 4 bytes left); Kanto's and Johto's are `daycareKanto` and
    `daycareJohto` at the end of SaveBlock3, word arrays of 288 bytes
    holding a `struct DayCare` (size checked in `src/daycare.c`, offsets
    pinned in `src/save.c`). The save layout changed: SaveBlock3 grows from
    1008 to 1584 of 1624 bytes (40 left, D-017). Old saves are out of scope
    (owner), there is no migration.
  - Every step counts in all three: their Pokemon gain steps and can lay an
    egg wherever the player walks (`ShouldEggHatch`). Eggs in the party
    hatch on the step counter of SaveBlock1's Day Care, as before.
  - `FLAG_PENDING_DAYCARE_EGG` stays Hoenn's (it puts Route 117's Day Care
    man at the fence); Kanto's and Johto's eggs set no flag, and their
    scripts no longer clear it (they read `GetDaycareState`).
  - Record mixing (a link feature) exchanges the mail of Hoenn's Day Care
    only, as in Emerald.
  - Unchanged: the Oval Charm at every Day Care (D-036), the region rule
    for eggs (D-049).
  - Bill's PC (owner): the storage is "Bills PC" ("BILL's PC") from the
    start, in every region. The PC menu, the access message and the
    transfer messages after a catch, a gift or naming never say "Jemandes
    PC" or Lanette's name in this build (`IS_HNS` in `src/script_menu.c`,
    `src/battle_message.c`, `src/battle_script_commands.c`,
    `src/naming_screen.c`, `data/scripts/pc.inc`,
    `data/scripts/pc_transfer.inc`). `FLAG_SYS_PC_LANETTE`, still set at
    Bill's Sea Cottage and by Lanette on Route 114, no longer changes the
    name. The two transfer texts got their English branch.
- **Code:** `GetCurrentDaycare`, `GetRegionDaycare`, `TryProduceEgg`,
  `ShouldEggHatch` (`src/daycare.c`); `struct SaveBlock3`
  (`include/global.h`); `Route5_Frlg`, `Route34_DayCare_hns`; test
  `test/origin_jade/daycares.c`.
- **Evidence:** owner answers 2026-10-31 (S-16, O-020, O-021).

### D-053 Balance round 2: boss movesets, league ladder, region badges
- **Status:** Active (2026-11-02, owner answers 2026-10-31 to B-01-B-13)
- **Decision:**
  - Fixed boss movesets (B-01): every Pokemon of a scaled boss (gym
    leaders, Elite Four, champions, rivals, Team Rocket's admins and
    Giovanni, first teams and rematches) carries a fixed set of four
    moves, chosen for strength and type coverage at its scaled level
    and good up to level 100: its best STAB attacks, coverage, at most
    one setup move (Swords Dance, Dragon Dance, Calm Mind, Nasty Plot,
    Bulk Up, Curse ...) and a status or recovery move where it pays off
    (sleep, paralysis, burn, Recover, Roost ...). Moves of the old set
    stay where they hold up. Unreliable or situational moves are not
    used (Return, Frustration, Hidden Power, one-hit KOs, two-turn
    attacks except Solar Beam with Drought, self-KO moves, Fake Out,
    Dream Eater, weight- and HP-based moves). Bosses that fight double
    or 2-vs-2 battles (Ariana with a grunt, Hoenn's gym rematches, Tate
    and Liza, Maxie with Tabitha) carry no move that also hits their
    partner (Earthquake, Surf, Discharge, Sludge Wave ...) unless every
    Pokemon that can stand next to them is immune (Flying type,
    Levitate ...): such a move hits the partner at full damage (B-13),
    and the AI uses it as long as the partner survives. Single-target
    and both-foes moves (Rock Slide, Earth Power, Hydro Pump ...) take
    their place. The TMs and tutors below count per region reached, not
    per boss: an early Johto leader may know a TM the player only finds
    later in Johto (an implementation choice, not set by the owner).
    Every move is learnable in
    this game by the species the boss fields at the floor of its
    corridor (after the scaling's evolutions, D-012, pre-evolutions
    included): level-up up to the corridor's ceiling (100 for rematches
    after a title) in either learnset option, a TM, HM or tutor the
    player can get in the regions reached by then (Kanto for Kanto's
    rematches; Kanto and Johto for Johto and for Blue's and Janina's
    Kanto gyms after the league change; all for Hoenn), or an egg move
    (not for legendaries and not for a rival's starter). Held items and
    abilities stay. Done for Johto (`src/data/trainers_hns.party`),
    Hoenn (`src/data/trainers.party`, Magma's and Aqua's leaders and
    admins, May and Wally included) and Kanto's rematch teams of the
    Elite Four and the champion after the Kanto title
    (`src/data/trainers_frlg.party`, D-015).
    Kanto's first-run bosses are not scaled and keep FireRed's sets
    (D-011); Troy and Red: below.
  - Every other trainer Pokemon only knows moves its species (or a
    pre-evolution) can learn in this game: level-up in either learnset
    option, a TM, HM or tutor of this game's data, or an egg move (B-02).
    244 moves of 156 Pokemon in all four party files were replaced by a
    learnable move of a similar role (same type and category and similar
    power, or the same kind of status move, preferring level-up moves up
    to the Pokemon's level), locked content included (Sinjoh, Alola,
    HnS's retired Kanto teams). Owen's Nidorino and Nidorina had each
    other's moves and swap them back. Pokemon of disabled species
    (regional forms in locked content) have no learnsets in this build
    and keep their moves.
  - May and Wally count as bosses (+1 on the ace) like Silver and Blue:
    `TRAINER_CLASS_RIVAL` is a boss class in `IsBossTrainer`
    (`src/level_scaling.c`). Brendan's teams (unused, D-003) and Troy
    share the class; Troy is not scaled (D-031). (B-06, D-012)
  - Troy at Meteor Falls (`TRAINER_STEVEN`) and Red on Mt. Silver
    (`TRAINER_RED_HNS`) are the absolute final bosses of the story: both
    field six Pokemon at level 100 with fixed movesets, held items as
    before, never scaled (B-10, D-031). Troy: Skarmory (Spikes, Stealth
    Rock, Roost, Brave Bird), Claydol (Earthquake, Psychic, Ice Beam,
    Shadow Ball), Aggron (Head Smash, Iron Head, Earthquake, Autotomize),
    Cradily (Curse, Recover, Rock Slide, Earthquake), Armaldo (Swords
    Dance, X-Scissor, Rock Blast, Earthquake), Metagross (Meteor Mash,
    Earthquake, Zen Headbutt, Bullet Punch). Red: Pikachu (Volt Tackle,
    Surf, Iron Tail, Brick Break), Snorlax (Curse, Body Slam, Earthquake,
    Crunch), Charizard (Fire Blast, Air Slash, Dragon Pulse, Focus
    Blast), Venusaur (Giga Drain, Sludge Bomb, Sleep Powder, Synthesis),
    Blastoise (Hydro Pump, Ice Beam, Dark Pulse, Focus Blast), Espeon
    (Calm Mind, Psychic, Shadow Ball, Morning Sun).
  - Johto league: levels rise from Will to Lance like HGSS instead of all
    aces at the corridor's 65; each room has its own band top and
    corridor, the champion stands above the Elite Four (B-05, D-012).
    The owner chose option (b): the champion room's ceiling is 2 above
    the league's 65, so Lance tops out at 67 and the Elite Four rise
    within 58-65. The steps per room (extras -1, +1, +3, +4, +5 after
    HnS's aces; floors 58, 59, 61, 62, 63; ceilings 62, 63, 64, 65, 67)
    are an implementation choice, not set by the owner, and can be tuned
    in the table.
    Code: `JOHTO_SCALING_ROOMS` (`include/config/johto_scaling.h`),
    `FindScalingRoom` (`src/level_scaling.c`); the rooms apply to
    opponents only, not to battle partners, wild or static encounters.
  - Badge readers count the badges of the current region (B-08, D-007):
    `GetRegionBadgeCount` / `GetCurrentRegionBadgeCount` (`src/caps.c`)
    serve `HasEnoughBadgesForRematch` (Johto 3 badges, "after Whitney" as
    in HnS; Hoenn the same 3), Hoenn's battle requests by phone
    (`GetNumOwnedBadges`, 5 badges as in Emerald), the Gen 9 catch malus,
    the challenge menu's trainer IV/EV tables (`GetChallengesBadgeCount`)
    and the badge number of the continue window (region of the saved
    map). The catch malus keeps its rule (each step above the level of
    the badge count costs a fifth of the odds), but in Johto and Hoenn the
    levels are the corridor ceilings of the next gym's tier: Johto 50,
    50, 53, 53, 55, 55, 58, 64 for 0-7 badges, Hoenn 85, 85, 90, 95, 95,
    95, 100, 100 (Kanto keeps Gen 9's 25-60). In Johto and Hoenn it only
    applies above the corridor ceiling of the map (`GetScalingCeiling`,
    `src/level_scaling.c`): nothing on the ways in from Kanto (Routes 26
    and 27, Tohjo Falls, 40-80) before the first Johto badge or in tiers
    visited before their gym. With Kanto's table every Johto and Hoenn
    Pokemon would be above the levels; with these only Pokemon
    above the corridor are harder to catch, mainly Raikou, Entei and
    Celebi at 75 before the eighth Johto badge (O-050).
  - Johto trainers with fewer than three Pokemon are filled up to three
    with species of the region (Kanto and Johto, D-049), by hand because
    `tools/fill_johto_parties.py` finds no wild pool or class type for
    them (B-12, D-012): Marc, collector in the Radio Tower 3F (Kabutops
    and Aerodactyl 36 to his Omastar 37); Rasso (`TRAINER_RICH_HNS`),
    collector in the Radio Tower 4F (Smeargle and Ditto 39 to his
    Porygon 40); Hiltrud (`TRAINER_SHIRLEY_HNS`), expert on the
    M.S. Aqua (Granbull 62 between Jigglypuff 61 and Wigglytuff 63);
    Tamao (`TRAINER_ZUKI_HNS`), kimono girl in the Ecruteak theater (two
    more Umbreon 48, like the other four kimono girls' three
    Eeveelutions). The newcomers use the level-up moves of their level,
    except Smeargle, whose only level-up move is Sketch: it knows Spore,
    Fake Out, Shadow Ball and Thunderbolt.
  - Kept as they are (owner answers):
    - Kanto's ladder keeps evolved Pokemon below their evolution level
      (B-03, D-011).
    - Legendaries in the party count for the anchor (B-04, D-039,
      D-012; checked in `GetScalingAnchor`, which skips only eggs).
      Mythicals do not count for Pokedex completion (D-036).
    - Boss IVs stay as HnS and Emerald set them (B-07), e.g. Whitney 2,
      Falkner to Morty 12, Silver 0 in his first three battles, May 0;
      the challenge option for trainer IVs follows the region's badges
      (B-08).
    - Hoenn's corridor floors stay hard for players who skip trainers:
      from Flannery on about 9-12 levels above such a team (B-09, D-012
      asks for training).
    - Ariana in the Rocket Hideout B2F (`TRAINER_ARIANA_1_HNS`) keeps six
      Pokemon; in the 2-vs-2 battle with Lance against her and a grunt
      (`multi_2_vs_2`) only her first three fight, as scripted (B-11).
    - Spread moves follow Gen 3 (`B_MULTIPLE_TARGETS_DMG GEN_3` in
      `include/config/battle.h`, as in HnS): in double battles a move
      that hits both foes does 50 % to each, one that hits the whole
      field (Earthquake) full damage; from Gen 4 on it is 75 %.
      The six upstream tests that expect the later rule stay in the
      baseline of known failures (B-13).
- **Evidence:** owner answers 2026-10-31 (B-01-B-13) and 2026-11-02.

### D-054 Nuzlocke, challenges and randomizer work as in HnS
- **Status:** Active (2026-11-02)
- **Decision:** The Nuzlocke, the challenges, the randomizer and the
  comfort features do what HnS does (HnS 2.0.5, `9041f705db`; the upstream
  2.0.6 changes none of it). A rule of HnS holds for Kanto and Hoenn too.
  What FRLG's Kanto adds is checked against HnS's own Kanto: what was there
  comes into FRLG's Kanto, what was not stays out. Per point:
  - Trainer Hills (N-01, O-028): HnS's battle end skips Nuzlocke deaths
    in its Trainer Hill (`BATTLE_TYPE_TRAINER_HILL`, like the Battle
    Frontier), and its reception heals after a loss; Origin Jade's Route 40
    hill is the same, unchanged (D-045). Emerald's hill on Route 111 is
    retired (D-044).
  - Route 41's Tentacruel guards (N-02): HnS's own fight, same script and
    same spot (also K-04). A Pokemon that faints there dies, as in HnS;
    unlike HnS the fight uses up no area (static encounters, owner
    2026-10-30, D-045).
  - "Keine EVs" (N-03): HnS lifts it with Red, where its Nuzlocke ends and
    its credits roll. Origin Jade lifts it with the Nuzlocke at the first
    Hoenn title (`FLAG_END_NUZLOCKE`, D-045), where the credits roll
    (D-028): `MonGainEVs` (`src/pokemon.c`), `ItemUseCB_Medicine`
    (`src/party_menu.c`) and the menu text.
  - Pokemon Center challenge (N-04): HnS blocks the nurses (also the one
    in the Dojo's VIP room), Mom and the bed on the S.S. Aqua; every other
    heal (story heals, people who let the player rest) stays. Origin Jade
    blocks the same in all three regions: the nurses (also FRLG's), Mom in
    Pallet Town and every bed that heals: the S.S. Aqua's, the S.S.
    Tidal's (`SSTidalRooms`; the voyage still ends after the usual steps)
    and the Weather Institute's on Route 119
    (`Route119_WeatherInstitute_1F`). The menu text names exactly these.
  - Hardcore (N-05): HnS deletes the save at every whiteout while the
    Nuzlocke runs (`CB2_WhiteOut`), also after fainting from poison in the
    field; unchanged.
  - Item randomizer and dialogue (N-06): HnS randomizes NPC gifts
    (`giveitem`), and the dialogue around a gift still names the original
    item (a gym leader explaining his TM); unchanged. FRLG's Kanto gifts
    with their own receive text follow the same rule (D-023).
  - Paid exchanges and the item randomizer (N-07): HnS's exchanges with a
    menu (Goldenrod's Game Corner prizes and drink machine, Kurt's balls,
    the Moomoo Milk) give the chosen item (`additem`); Mom's purchases, the
    lottery and Mahogany's merchant (`giveitem`) go through the randomizer.
    Origin Jade gives the chosen item at its exchange menus too:
    Celadon's prize room, Cerulean's Berry Powder man, Route 113's Glass
    Workshop, Route 124's treasure hunter (shards for stones and Deep Sea
    items) and Captain Stern in Slateport's harbour (Scanner for a Deep Sea
    Tooth or Scale) (`giveitem_norandom`, D-023; the last two trade only
    evolution items, which keep their place anyway); Celadon's and
    Lilycove's drink machines and Mauville's prizes already use `additem`.
    Mom and both lotteries stay randomized as in HnS.
  - Starters (N-08): "Starter: Zufall" changes the player's starter in
    HnS (its only lab, Elm's). Origin Jade applies it to every starter the
    player chooses in a lab: Oak's, Elm's and Birch's (one Johto starter
    after the completed Hoenn dex), in `ScrCmd_showmonpic`
    (`src/scrcmd.c`); preview, question, receive message and Pokemon are
    the same species (D-023, D-035); Birch's balls show the same three
    species as Elm's. As in HnS the one-type challenge changes only the
    first starter, and "Feste PKMN" leaves the labs alone.
  - Move relearner (N-09): HnS's Johto has one (Blackthorn City), so has
    Emerald's Hoenn (Fallarbor Town), HnS's Kanto none; FRLG's on Two
    Island is retired (D-019). Kanto stays without one (owner 2026-11-02,
    A78).
  - Hall of Fame (N-10): HnS keeps one list without a region; its league
    titles and Red's victory (`GameClear`) are mixed in it. Origin Jade's
    three regions share the 50 places the same way (no region marker).
  - Battles with an AI partner (from O-055): HnS skips the Nuzlocke deaths
    at the end of such a battle (`BATTLE_TYPE_INGAME_PARTNER`, Lance in
    the Rocket Hideout); a Pokemon that fainted comes back into the party
    at 0 HP and dies at the end of the next battle unless it is healed
    first. Origin Jade does the same again, also for Troy in Mossdeep's
    Space Center: the multi battle macros (`multi_do`, `multi_do_fixed`)
    no longer call a death check of their own after the party is restored
    (audit 2026-10-30, A30, taken back), D-045.
- **Open:** O-055 (Nuzlocke rules that differ from HnS outside these
  points), O-056 (move tutors in Kanto against HnS's Kanto), O-057 (item
  randomizer: Slateport's Berry Powder man, single items for money,
  start), O-058 (randomizer species pool).
- **Evidence:** owner answers 2026-10-31 and 2026-11-02 (group 4: "alles
  wie im HnS-Upstream"; FRLG's Kanto against HnS's Kanto); HnS code
  compared with `git show 9041f705db:<file>`.

### D-055 Debug toggle "Even Wild Slots"
- **Status:** Active (2026-11-02, owner: test aid "Wilde gleich verteilt")
- **Decision:** The overworld debug menu's "Flags & Vars" list has "Even
  Wild Slots" (debug texts stay English, D-020). While it is on, every
  slot of the current encounter table is equally likely: land, water,
  Rock Smash (also the Headbutt trees, which use its table) and each rod
  (Old Rod slots 0-1, Good Rod 2-4, Super Rod 5-9). The table itself
  (map, time of day, randomizer) and the levels stay as they are;
  abilities that draw a type (Magnet Pull, Static ...) still come first.
  DexNav's sightings while walking (`TryFindHiddenPokemon`) and the map's
  wild species behind ambient cries and a transforming follower
  (`GetLocalWildMon`, `GetLocalWaterMon`) use the even slots too; the
  species of DexNav's hidden table and mass outbreaks keep their own
  odds. The switch lives in RAM (`gDebugEvenWildSlots`): off after a
  reset, nothing in the save, no save layout change. `make release` has
  no debug menu (D-046) and drops the check (`DEBUG_OVERWORLD_MENU`).
- **Why:** A tester who checks which Pokemon a map has would need
  hundreds of encounters for a slot of 1 %.
- **Code:** `UseDebugEvenWildSlots` and `ChooseWildMonIndex_*` in
  `src/wild_encounter.c`, `DebugAction_FlagsVars_EvenWildSlotsOnOff` in
  `src/debug.c`; test `test/origin_jade/even_wild_slots.c`.
- **Evidence:** owner answers 2026-11-02 (test aid "Wilde gleich
  verteilt": yes).

### D-056 German completion of the common texts
- **Status:** Active (2026-11-02, owner: the beta comes out in German
  first, everything that is not German gets translated, both languages
  stay selectable)
- **Decision:**
  - Every common text the German build shows (`data/text`,
    `data/scripts`, strings in `src`) has a German branch under
    `#if GERMAN`; the English text stays as the `#else` branch (D-020).
    Where a file or table had no `#if GERMAN` yet, the pattern is added
    per text.
  - Sources, in this order: the official German Emerald texts
    (pokeemerald-german), the German Ruby/Sapphire texts (pokeruby
    `data-de`) where Emerald has none; written in title case (D-020).
    Line breaks change only where a line would exceed 208 px. Obvious
    slips of the official text are smoothed (punctuation, a garbled
    sentence, grammar such as "so lange" or "gemäß ihrem Wesen", speaker
    names as in the owner's existing texts, e.g. "Mr. Brack:"); the
    commit messages name each case. HnS-only texts without an official
    German text are own translations in the style of the neighbouring
    texts; the owner reads them in the text round.
  - Where the official text has no term, the owner's existing German
    texts decide: stat abbreviations as in the Pokedex (KP, Ang, Ver,
    Init, SP.A, SP.V), "IVs" as in the challenge menu, the HnS tent
    copies as "Kampfcamp Arena", "Kampfcamp Palast", "Kampfcamp Fabrik".
  - Done 2026-11-02: the move tutors of Emerald and HnS; the Safari
    Zone's common texts (Route 121, also used by Johto's Safari Zone gate
    and Fuchsia's entrance); the event-ticket sailors and signs (not
    reachable, D-026, D-029); the Blend Master's champion gate; the two
    Pokeblock feeder help windows; Dewford's fishing choice; Pokeblock
    names and flavours; the PC wallpaper "Punkte"; the game names in two
    TV shows ("Automaten" instead of the official "Einarmigen Banditen",
    which does not fit the German lines of the show); "Lv." in the
    Pokedex move list; the battle tents (`data/text/battle_tent.inc`,
    shown by the HnS copies at the Route 40 Trainer Hill, which stay
    under S-04); the menu answers of the Trick House Mechadolls,
    Fortree's Hidden Power giver and the Battle Tower feelings man; the
    Lilycove ladies (favour requests, contest categories and the contest
    lady's nicknames as in German Emerald); the Cycling Road results; the
    Trainer Fan Club ratings; the Exp. Candy, ability change and form
    change messages of the party menu; the elder's quiz answer "Freund"
    in the Dragon's Den; the list of banned species at the Battle
    Frontier and tent desks; the easy chat keyboard; English words in
    existing German branches ("Wesen/" when feeding Pokeblocks, "Typ/",
    the move relearner's "Level-Attacken").
  - Stays English on purpose: debug texts (D-020: `data/scripts/debug.inc`,
    `data/scripts/config.inc`, `src/debug.c`, the sprite visualizer);
    strings marked unused (`src/data/union_room.h`, the 16 battle tent
    texts marked `@ Unused`, unused entries of `src/strings.c`); names in
    the credits; internal strings (identifiers, link and compatibility
    strings).
  - English strings in `src` that cannot be reached stay as they are:
    the DexNav (`DEXNAV_ENABLED` FALSE), the R-button fly prompt of the
    region map (`OW_FLAG_POKE_RIDER` 0), the FRLG Trainer Tower, Seagallop
    and Safari Zone battle menus (Sevii retired, D-019; `IS_FRLG` 0),
    Alola and Sinjoh map names (D-019), the Sleep Clause message
    (`B_FLAG_SLEEP_CLAUSE` 0), the code entry screen (special `EnterCode`
    is not called), the Battle Tower interview's "Satisfied" and
    "Dissatisfied" (only the retired Emerald Battle Frontier lobby) and
    the Regi doll menu of the game corner (script not called).
- **Not covered:** map texts (`data/maps/*`), trainer names in the party
  files.
- **Check:** `python3 -I tools/check_game_text.py --english`; after this
  change the area "gemeinsam" lists only debug texts (83) and 14 of the
  16 unused battle tent texts, the area "src" only debug (5), unused
  union room texts (4) and credits names (2). The word list does not see
  single words, all-caps names or lowercase fragments; those were
  searched by hand in every common and `src` literal without German
  words.
- **Evidence:** owner answers 2026-11-02 (beta plan, "Deutsch
  vervollständigen"); S-04 (the HnS tent copies at Route 40 stay).

### D-057 German completion of the map texts
- **Status:** Active (2026-11-02, owner: the beta comes out in German
  first, everything that is not German gets translated, both languages
  stay selectable)
- **Decision:**
  - Every text in `data/maps/*/scripts.inc` that the German build shows
    on a Kanto, Johto or Hoenn map has a German branch under `#if GERMAN`;
    the English text stays as the `#else` branch (D-020). Exceptions: the
    cases under "Not covered" below, and short cries and interjections
    that read the same in German (such as "Arrgh!", "Gwah!", "Zombies!",
    "Mew!"), which keep a single string without a branch.
  - Names and terms as in the German HGSS, FRLG and Emerald games and in
    the owner's existing map texts (Mahagonia City, Wutkeks, Norbert,
    Intendant, Lambda, Athena, Atlas, Siegfried, Kelleröffner, Aufseher
    Baoba, Safari-Level, Pokériegel, Napf, IVs as in the challenge menu).
    The texts are own translations in the style of the neighbouring
    texts; the owner reads them in the text round. Title case (D-020);
    message lines at most 208 px, PokeNav call lines at most 192 px.
  - Done 2026-11-02, Johto: Mahogany Town (13 texts, also Elm's call
    about the radio tower), the radio tower's top floor (map
    `GoldenrodCity_RadioTower_5F_hns`, "4S" on its signs; 20) and the
    Underground switch room (29), the Safari Zone gate entrance (18),
    Union Cave 1F (15), the Moomoo Farm barn (11), Meara in the Mt. Silver
    Pokemon Center (4; she appears only with Sinjoh, D-019) and the Day
    Care's party limit message (1). Kanto: the "Space Shuttle" sign in
    Pewter's museum ("Raumfähre"). Hoenn: the Poochyena on Route 114
    ("Wau! Wauwau!"). Route 40 Trainer Hill: the HnS copy of the Slateport
    Battle Tent lobby (`SlateportCity_BattleTentLobby_hns`; the tool
    counts it under Hoenn because `MAPSEC_TRAINER_HILL` is an Emerald map
    section, outside the tool's Johto range)
    shows 3 NPC texts (man, girl, woman), now the owner's German texts of
    the Emerald lobby, whose English texts are the same. Its TM giver
    script (`SlateportCity_BattleTentLobby_hns_EventScript_TormentGiver`)
    has no object on the HnS map, so its two texts (`CouldntFindMonForMe`,
    `ExplainTorment`) are never shown; they got the Emerald lobby's German
    texts as well. Both branches of `ExplainTorment` name TM41 Torment,
    while the unused script would give TM42 Facade (HnS changed only its
    `giveitem`). If the owner ever places the NPC, item and text have to
    agree, and its flag is the Emerald TM giver's
    (`FLAG_RECEIVED_TM_TORMENT`).
  - "$" ends a string (`charmap.txt`) and must never stand in a text.
    Five German texts that used it for money were cut off there (Route 32,
    Moomoo Farm, Route 4 Pokemon Center, Pewter mart, Route 34 Day Care);
    they use "¥" now, which the font shows as the Pokedollar sign, in the
    place and spacing their own wording had ("500 ¥", "500¥"). The order
    is not settled: the owner's texts use both "500 ¥" and "¥300"; he
    decides the style in the text round.
- **Not covered:** trainer names in the party files (O-066), locked and
  retired maps (D-019; the tool counts 290 and 3 texts there),
  unreferenced Japanese FRLG texts, common texts (D-056).
- **Check:** `python3 -I tools/check_game_text.py --english` lists no map
  text of an active region any more (the two English contest hall texts
  of the Emerald Slateport tent corridor are German since the RS contest
  halls use them, O-065); the 23 (Johto) and 5 (Kanto) entries are party
  names (O-066). The word list
  does not see short texts; every map text of an active region without a
  German branch was read by hand (left: the interjections and cries named
  above and the unreferenced Japanese FRLG texts).
- **Evidence:** owner answers 2026-11-02 (beta plan, "Deutsch
  vervollständigen").

### D-058 Contests as in Ruby/Sapphire
- **Status:** Active (2026-11-02, owner: contests "ganz wie Rubin/Saphir",
  in four halls)
- **Decision:** Pokemon Contests work as in Ruby/Sapphire (pret
  `pokeruby` was the reference). Each hall holds one rank:
  - Verdanturf Town: Normal Rank; Fallarbor Town: Super Rank; Slateport
    City: Hyper Rank; Lilycove City: Master Rank and, as before, the link
    contests (X-08). The owner's note names the towns the other way round
    for Normal and Super (O-068).
  - Lobbies: Verdanturf, Fallarbor and Slateport have RS's lobby with its
    people (`VerdanturfTown_ContestLobby`, `FallarborTown_ContestLobby`,
    `SlateportCity_ContestLobby`, new maps at the end of their town's map
    group, behind the doors the owner drew in place of the battle tents).
    They use RS's lobby layout, which Emerald kept unused as
    `LAYOUT_FALLARBOR_TOWN_LEFTOVER_RSCONTEST_LOBBY`. Lilycove keeps
    Emerald's lobby.
  - Contest Pass (`ITEM_CONTEST_PASS`, "Wettbewerbskarte"): every hall's
    receptionist asks for it. Verdanturf's issues it on request, the others
    send the player to Verdanturf; Lilycove's link counter asks for it too.
  - Reception: the receptionist names the hall's rank and offers enter,
    info and exit; there is no rank menu. The hall's receptionist script
    sets `VAR_CONTEST_RANK` (`ContestLobby_EventScript_ContestReceptionist`
    and the Origin Jade branch of
    `LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist`,
    `data/scripts/contest_hall.inc`). Rank requirements are RS's (and
    Emerald's): any Pokemon may enter Normal; a higher rank needs the
    ribbon of the rank below in the same category (`TryEnterContestMon`).
  - Stage and return: the contest runs on Emerald's stage maps
    (`ContestHall*`, by category). Afterwards the player returns to the
    lobby of the hall that held it (`ContestHall_EventScript_SetExitWarp*`
    by `VAR_CONTEST_TYPE`, which names the hall because each hall has one
    rank), where the reporter of the Bravo Trainer interview may wait
    (`LilycoveCity_ContestLobby_EventScript_TryShowContestReporter`; new
    flags `FLAG_HIDE_VERDANTURF_TOWN_CONTEST_REPORTER` and
    `FLAG_HIDE_FALLARBOR_TOWN_CONTEST_REPORTER`, Slateport and Lilycove use
    their Emerald flags; each town hides its reporter on entry).
    Lilycove's contest artist (museum painting) stays; he comes only after
    a Master Rank win.
  - Prizes as in RS and Emerald: a ribbon; a Master Rank win with a
    Pokemon that already holds that ribbon gives a Luxury Ball (with a full
    bag it waits at the counter of any hall).
  - Pokeblock Case: the little girl in Slateport's lobby gives it, by item
    check (a case from Baoba counts); Lilycove's receptionist no longer
    does (RS); the Safari Zone desk on Route 121 names Slateport's hall
    (O-063). The little girl in Lilycove's lobby no longer says that the
    lady at the counter gave her a case; she always gives Emerald's other
    line, the tip on making Pokeblocks. Berry Blenders: each RS lobby has
    a link blender and one with people (Verdanturf and Fallarbor: the old
    man; Slateport: the old man and a boy,
    `ContestLobby_EventScript_BerryBlender`). The old man
    gives a Pecha Berry once a day to a player without berries
    (`FLAG_DAILY_CONTEST_LOBBY_RECEIVED_BERRY`, one flag for all lobbies, as
    in RS). Lilycove's blenders and the Blend Master stay.
  - Paintings: the frame in each RS lobby shows the newest contest winner
    (`CONTEST_WINNER_HALL_1`, the first of Lilycove's six frames). Emerald
    keeps one list of the six newest winners of all ranks; RS kept one
    painting per rank (O-069).
  - Fallarbor's sketch artist says the sketch of the player's Pokemon is
    up after a win there (`FLAG_CONTEST_SKETCH_CREATED`, cleared when the
    player enters the town).
  - TM Attract: the girl in Verdanturf's lobby, with a flag of her own
    (`FLAG_HOENN_RECEIVED_TM_ATTRACT`); the girl in the HnS tent copy at
    Route 40 keeps `FLAG_RECEIVED_TM_ATTRACT` (O-067).
  - Contest halls: a door in each RS lobby leads to RS's audience hall
    with its stage and people (`VerdanturfTown_ContestHall`,
    `FallarborTown_ContestHall`, `SlateportCity_ContestHall`, RS's layout
    `LAYOUT_FALLARBOR_TOWN_LEFTOVER_RSCONTEST_HALL`). Their texts are the
    RS hall texts that Emerald left unused in the corridors of its battle
    tents, with the owner's German (O-065). The sailor in Slateport's hall
    gives TM Torment, with a flag of his own
    (`FLAG_HOENN_RECEIVED_TM_TORMENT`).
  - The contest halls stand where Emerald had its battle tents; the tents
    are retired (D-030, D-019).
  - Towns: the signs at the hall doors and the people who spoke of the
    battle tents have their RS contest texts again: in Verdanturf the
    camper, the old man in the Pokemon Center and the old lady in the
    mart; in Slateport the boy, a man by the market and the girl in the
    house near it, who asks for the Contest Pass as in RS. Lilycove's hall
    sign names the Master Rank, as in RS. Scott still leaves Slateport's
    hall after the museum
    (`SlateportCity_EventScript_ScottContestHallScene`, he counts for
    `VAR_SCOTT_STATE`); his line is new (O-070).
- **Evidence:** owner answers 2026-11-02 ("Wettbewerbe (Owner,
  endgültig)"); owner commits 06ea236bdb and ad4a8db368 (hall buildings
  with doors).

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
- **P-005** Done 2026-10-31: Mom's call texts follow Kanto, Johto and
  Hoenn (D-002).
- **P-006** Done 2026-11-02: Emerald's Battle Tents (Fallarbor Town,
  Verdanturf Town, Slateport City) and Emerald's Trainer Hill on Route 111
  are retired; HnS's endgame counts, with the tent copies and the hill by
  Route 40 (owner 2026-10-31 and 2026-11-02, S-04, S-05; D-030, D-044,
  D-019). The owner removed the buildings from the maps on `balancing`
  (06ea236bdb: the three tents and the hill, with the hill's warp event,
  the last of Route 111, and its sign; the tents' warp events stay;
  ad4a8db368: the tilesets); round 2 sits on top of those commits, and
  the scripts, flags and texts left are cleaned up (O-024, O-065, O-067
  resolved). Contest halls as in Ruby and Sapphire stand in the tents'
  places (D-058): Verdanturf Town (Normal, with the Contest Pass),
  Fallarbor Town (Super), Slateport City (Hyper) and Lilycove City
  (Master), with rank locks, the Contest Pass and the Pokeblock Case as in
  Ruby and Sapphire. Built in Ruby and Sapphire's order; the owner's note
  names the towns of the first two ranks the other way round (O-068).

## Open questions

- **O-001** Resolved 2026-10-11: the league has changed (D-010).
- **O-002** Resolved 2026-10-31: Troy hands over the Hoenn Ticket in Oak's
  lab after the first Johto title (D-047).
- **O-003** Resolved 2026-10-15 (D-029).
- **O-004** Resolved 2026-10-15 (D-026).
- **O-005** Resolved 2026-10-12: Kanto never sets HnS's `FLAG_SYS_PC_BILL`
  (Goldenrod's first visit clears it, Ecruteak's Pokemon Center sets it; it
  only drives Bill's mother in Goldenrod). Bill's Sea Cottage sets
  `FLAG_SYS_PC_LANETTE`, which `flags_hoenn_de.h` moves to the Hoenn block,
  away from HnS's alias of `FLAG_SYS_PC_BILL` (O-021). The Celadon Eevee no
  longer sets Bill's `FLAG_GOT_EEVEE`, and the radio card stays (D-024).
- **O-006** Resolved 2026-10-15 (D-030).
- **O-007** Resolved 2026-10-15 (D-032).
- **O-008** Resolved 2026-10-21: the Day Care hands out the Ovalpin with the
  first egg, Lilycove's game designer the Schillerpin for the completed
  National Pokedex after the first Hoenn title (D-036).
- **O-009** Resolved 2026-11-02: Sinjoh and Alola stay locked (owner,
  D-019). Kept for a later unlock: enabling Sinjoh also needs the Gen 4+
  and regional forms in `species_enabled.h`. Risks found 2026-10-30,
  harmless while Sinjoh stays locked and Alola has no way in:
  - Locked content still uses disabled species: the POSTOBC rematch teams
    in `trainers_hns.party` (the Elite Four, Lance and Red, chosen only at
    `VAR_SINJOH_STORYLINE` 13 or more; the gym leaders in HnS's retired
    Dojo VIP room), Sinjoh, Route 49/50 and Alola trainers, and the wild
    tables of Snowswept Cavern, Route 49 and the Alola caves.
  - The 20 Alola maps (`MelemeleIsle_hns` and the others) are active
    (`game_version` `hns`) but have no way in: the only warps are in the
    retired `Route13_hns`, and the Melemele fly spot needs
    `FLAG_VISITED_ALOLA`, which only Melemele sets (D-019).
- **O-010** Resolved 2026-10-12: the Route 30 and Route 26 trees use the
  reserve slots `BERRY_TREE_ROUTE_30_ORAN` and `BERRY_TREE_ROUTE_26_SITRUS`;
  slot 33 is only shared with retired maps. Older saves are migrated in
  `LoadGameSave` (`FLAG_MIGRATED_JOHTO_BERRY_SLOTS`).
- **O-011** Resolved 2026-10-15: Oak's lab copies the ball number before the
  preview and hands out the starter with the preview's shininess.
- **O-012** Text debt. Partly resolved 2026-11-02: the 172 Johto texts
  without a German branch (346072a202) and every other English text the
  German build showed on an active map or from the common scripts have a
  German branch now (D-056, D-057). Left for the text round: the owner's
  reading of those translations and the line widths. Line widths,
  re-measured 2026-10-30 with
  `tools/check_text_width.py` (bytes of the built German ROM, FONT_NORMAL
  widths by glyph id, lines split at `\n`, `\l`, `\p`): no German line is
  wider than the 216 px text window; 30 are wider than the 208 px limit
  (29 Johto, 1 Kanto, 209-213 px, `--list` names them). Lines with
  `{PLAYER}`, `{RIVAL}` or `{STR_VAR_x}` are estimates (7 or 10 characters
  of 6 px): 199 may exceed 216 px, most of them in `data/text`. The locked
  Sinjoh and Alola maps (D-019) add 6 English lines over 208 px. The
  earlier 4951 lines over 216 px (652123e252) match the widths
  `check_pokenav_text.py` read one glyph off until 2026-10-30. On
  2026-11-02, after the translations, the built ROM has the same 35 exact
  lines over 208 px as before (Johto 28, Kanto 1, locked maps 6). Later,
  as its own round (owner 2026-10-21).
- **O-013** Resolved 2026-10-15 (D-028).
- **O-014** Resolved 2026-10-15: Silver's daily battle (D-028), gym rematches
  and Janina in Fuchsia (D-032). The signposts and the Dojo VIP room stay off.
- **O-015** Resolved 2026-10-21: the text slips found 2026-10-11 are fixed
  (2026-10-15: gatehouse, Johto's Oak, Vermilion's port; 2026-10-21: Kanto's
  Lance names the rival, Will says "Top Vier", `IndigoPlateau_Text_ShigyNinja`,
  Route 28 in German, "M.S. Anne" on the region map, Camper Todd's
  "Dukatia-Arena"). Over-wide lines left in these texts belong to O-012.
- **O-016** Resolved 2026-10-13: the radio works in Kanto (D-025).
- **O-017** Resolved 2026-10-13: Hoenn Sound stays off (D-025); the
  PokeCom's "Zustand" from the radio card on and Buena's hint before the
  quiz stay as they are.
- **O-018** Resolved 2026-10-20: Blue leads the Viridian gym after the
  league change (D-032).
- **O-019** Resolved 2026-10-26: Surskit, Roselia, Zangoose and Lunatone are
  wild in Hoenn; Masquerain, Budew and Roserade follow by level, breeding and
  the Shiny Stone (D-037).
- **O-020** Resolved 2026-11-02: each region has its own Day Care (owner,
  D-052).
- **O-021** Resolved 2026-11-02: the storage is always "Bills PC" (owner,
  D-052).
- **O-022** Nuzlocke: Kanto's Route 22 and HnS's `Route22_hns` share
  `MAPSEC_ROUTE_22` (one first encounter for both); `MAPSEC_INDIGO_PLATEAU`
  is shared too, with no wild table there yet. In practice only the plateau
  matters: `Route22_hns` is active (game_version "hns", own wild table) but
  cannot be entered. No warp leads there, and its only active connection,
  from `Route26North_hns`, has no walkable tile on either edge. Only
  `src/roamer.c` and `src/string_util.c` refer to the map.
- **O-023** Resolved 2026-11-02: the badge readers count the region the
  player stands in (D-007, D-053).
- **O-024** Resolved 2026-11-02: Emerald's hill on Route 111 is retired
  (D-044); `MAPSEC_TRAINER_HILL` on the Johto map fits the remaining hill
  by Route 40.
- **O-025** Nuzlocke end point: the Nuzlocke ends at the first Hoenn title
  (D-045); until 2026-10-30 it ended when Red was beaten. Owner to confirm.
- **O-026** Resolved 2026-10-30: scripted static encounters can always be
  caught and use up no area (D-045).
- **O-027** Resolved 2026-10-30: eggs always hatch and use up no area
  (D-045).
- **O-028** Resolved 2026-11-02: the Trainer Hills stay without Nuzlocke
  deaths, as in HnS (D-054, D-045); only the hill by Route 40 is left
  (D-044).
- **O-029** Resolved 2026-11-02 (owner): the player's room decorations
  are set up in the bedroom in Pallet Town (D-048).
- **O-030** Resolved 2026-11-02 (owner: remove): the hidden objects of
  Emerald's player family are removed from the Littleroot Town maps, and
  the jade code no longer names Dad's advice (D-048).
- **O-031** Resolved 2026-11-02 (owner): Troy has Emerald's sprite
  `OBJ_EVENT_GFX_STEVEN` everywhere (D-047).
- **O-032** Resolved 2026-11-02 (owner): "Hoenn" (Route 104 pier, Birch's
  greeting only on the first trip) stays in the ship menus until
  "Graphitport City" can be offered, then that replaces it; "Seegrasulb
  City" is added once Lilycove was visited. No dead end without a flyer
  (D-047).
- **O-033** Resolved 2026-11-02 (owner, option b): the region rule is off
  with any randomizer option, trainers or items alone included; what the
  game itself fixes stays (a Day Care egg comes from its parents; fossils
  are never rolled, D-023). `IsAnyRandomizerOptionOn` in
  `src/region_rule_oj.c` (D-049).
- **O-034** Resolved 2026-11-02 (owner: keep, the page is a help;
  `HGSS_HIDE_UNSEEN_EVOLUTION_NAMES` stays FALSE). The question was: the
  HGSS Pokedex's evolution page names every evolution and pre-evolution
  of a seen species and shows its icon, also those of a later region
  (Golbat shows Crobat in Kanto, Pikachu shows Pichu). Owner point 8 says
  Kanto's Pokedex shows only Kanto Pokemon; the list shows a later
  species only once the player has it (D-049), this page shows them all.
  The change not made: `HGSS_HIDE_UNSEEN_EVOLUTION_NAMES` TRUE
  (`include/config/pokedex_plus_hgss.h`) and no icon for an unseen
  target in `HandleTargetSpeciesPrintIcon` (`src/pokedex_plus_hgss.c`),
  which would hide every unseen evolution, of any region.
- **O-035** Resolved 2026-11-02: the debug states need not be perfect but
  hold everything the finished regions give; purchases such as the Game
  Corner prize TMs and every other item, shop goods too, once each (D-050).
  The generator's other readings stay.
- **O-036** Resolved 2026-11-02 (owner: as in HnS): Elm's call comes on
  the first step out of the house in Pallet Town after the first Johto
  title, as HnS's came in New Bark Town (D-051).
- **O-037** Mom's heal texts after a whiteout at home
  (`gText_HadQuiteAnExperienceTakeRest`, `gText_MomExplainHPGetPotions`):
  capitals "MAMA"/"POKéMON", a beginner tutorial; reachable from the start
  of a new game (whiteout before the first Pokemon Center heal, respawn
  `HEAL_LOCATION_PALLET_TOWN` from `new_game.inc`), after the Kanto title,
  and now also after a Johto title or Red (room respawn). Proposal: owner
  text; tutorial only before the first badge.
- **O-038** The German National dex rating texts are placeholders ("Unter
  300. / Weiter so!"); through Elm's call after the completed Johto dex
  they are now reachable before Hoenn. Needs owner text.
- **O-039** Resolved 2026-11-02 (owner, option a): the nurse's Gold Card
  greeting and the Frontier Pass colour count the trainer card's stars
  (three titles and Red, D-049).
- **O-040** Old German text defects found in the story text check, for the
  text round: trainer school e-mail (`gText_PokemonTrainerSchoolEmail`, now
  at three PCs), "mit Pokécenter challenge!" (`players_house.inc`), Birch's
  league text paragraph break mid-sentence, Lilycove game designer `\l`
  before `\p` and "Aner- kennung".
- **O-041** Continue point in the Pallet Town bedroom (D-048, O-029):
  placed dolls and cushions now stay in the room, and the bedroom PC puts
  them on any decoration tile, also around the bed. At the old continue
  point (6,6) next to the bed three dolls ((5,6), (6,5), (6,7); the bed
  is at (7,6)), or six one tile further out, box the player in for good
  in the save the Hall of Fame makes: no Fly or Teleport indoors, no
  Escape Rope or Dig outside caves, the PC out of reach. The game now
  continues after a title at (9,3) in front of the stairs, which no doll
  can block; a new game starts at (6,6) as before (no decorations yet).
  Owner: keep (9,3), or the spot next to the bed with a PC that refuses
  any doll that would cut (6,6) off from the stairs and the PC.
- **O-045** Regional forms as evolutions (owner 2026-10-31: keep those
  whose evolution HnS does not tie to a region, report the others). All
  are off (`P_REGIONAL_FORMS` FALSE, D-023) and stay off; no case qualifies,
  each is tied to a region. Owner to decide case by case:
  - Tied by the evolution itself (`IF_REGION`, never true in this game):
    Pikachu to Alolan Raichu (Thunder Stone), Exeggcute to Alolan
    Exeggutor (Leaf Stone), Cubone to Alolan Marowak (level 28, night),
    Koffing to Galarian Weezing (level 35), Mime Jr. to Galarian Mr. Mime
    (knows Mimic), Quilava to Hisuian Typhlosion (level 36), Hisuian
    Qwilfish to Overqwil (knows Barb Barrage; HnS added the Hisui
    condition, 743d0ba49d).
  - Tied by the first stage, a regional form that HnS offers only on the
    locked Alola maps, in locked Sinjoh (Route 49 and 50, Snowswept
    Cavern) or nowhere; the evolution itself has no region condition:
    Sneasler (Hisuian Sneasel with a Razor Claw by day; HnS has Sneasler
    itself wild on Route 49 and in Snowswept Cavern), Perrserker,
    Sirfetch'd, Mr. Rime, Cursola, Obstagoon (Galarian Zigzagoon and
    Linoone), Clodsire, and the regional second stages Raticate,
    Sandslash, Ninetales, Dugtrio, Persian, Graveler and Golem, Muk
    (Alola), Rapidash, Slowbro and Slowking (Galar), Arcanine and
    Electrode (Hisui).
  - Not regional forms, in the game as they are: Kleavor, Ursaluna and
    Bloodmoon Ursaluna (D-023), Wyrdeer, Annihilape, Farigiraf,
    Dudunsparce.
  Enabling one needs `species_enabled.h`, a source for its first stage,
  the Pokedex lists and the region table of `src/region_rule_oj.c`
  (D-049).
- **O-050** Gen 9 catch malus in Johto and Hoenn (D-053): the owner
  decided that the badge readers count the current region (B-08); the
  malus's levels per badge count in Johto and Hoenn are the corridor
  ceilings of the next gym's tier (`sBadgeLevelJohto`,
  `sBadgeLevelHoenn` in `src/battle_script_commands.c`), and it only
  applies to Pokemon above the corridor ceiling of the map
  (`GetScalingCeiling`). Effect: Raikou, Entei and Celebi (75) cost 0.8
  per step above it (3-4 Johto badges: 0.33-0.41 of the odds; nothing on
  Routes 26 and 27 and at Tohjo Falls, corridor 40-80), the Rocket
  Hideout's Electrode (60, 6 badges) 0.8; wild Pokemon of the corridor
  never, also not on the ways in from Kanto before the first Johto badge
  or in a tier visited before its gym. Before B-08 the malus counted
  Kanto's badges, so it never applied in Johto and Hoenn (all eight are
  won by then). Owner to confirm, or to switch the malus off outside
  Kanto.
- **O-055** Nuzlocke rules that differ from HnS outside D-054's points.
  Owner to decide whether they follow HnS too:
  - End point: HnS ends the Nuzlocke with Red, where its credits roll;
    Origin Jade ends it at the first Hoenn title, where its credits roll
    (D-028). Same rule, so O-025 can be confirmed as it is.
  - Wild battles without catching: HnS's only one, Route 41's Tentacruel
    (`FLAG_NO_WILD_CATCHING`), uses up the area there, because HnS's area
    check has no exception for battles without catching or for scripted
    static encounters. Origin Jade leaves it free like every scripted
    static encounter (owner decision 2026-10-30, D-045). FRLG's Pokemon
    Tower ghosts without the Silph Scope (`BATTLE_TYPE_GHOST`) and battles
    under `B_FLAG_NO_CATCHING` have no counterpart in HnS and use up no
    area either. Proposal: keep.
  - Nickname question outside the Nuzlocke at four gifts (Johto starter
    into the PC, Goldenrod's prizes into the PC, Bill's Eevee, the special
    Dratini; D-045): HnS asks nothing there. Proposal: keep, it is what all
    other gifts do.
- **O-056** Move tutors in Kanto against HnS's Kanto (rule of D-054).
  HnS's Kanto (its maps are retired, D-019) had free tutors for Sleep Talk
  (Viridian City), Double-Edge (Viridian City), Rollout (Pewter City),
  Dynamic Punch (Route 4), Swagger (Route 4's Pokemon Center), Mimic
  (Saffron City's Pokemon Center) and Explosion (Cinnabar Island's Pokemon
  Center), and in the Fighting Dojo's VIP room the three Battle Point
  tutors that also stand at Route 40's Trainer Hill. HnS's other tutors are
  in Johto (among them Ilex Forest, Olivine City and Route 40), at New
  Sinjoh's hot springs and on Ulaula Isle in Alola (both locked, D-019).
  FRLG's twelve tutors in Origin Jade's Kanto, compared with that:
  - Mimic (the Copycat in Saffron City) and Double-Edge (Victory Road 2F):
    HnS's Kanto taught them too, so they stay.
  - Mega Punch and Mega Kick (Route 4), Seismic Toss (Pewter's museum),
    Dream Eater (Viridian City), Rock Slide (Rock Tunnel), Thunder Wave
    (Silph Co. 2F), Counter (Celadon's store 3F) and Softboiled (Celadon
    City): HnS's Kanto taught them only for Battle Points in the Dojo's
    VIP room, which stays off (D-032); Route 40's Trainer Hill teaches them
    the same way.
  - Substitute (Fuchsia City) and Metronome (Cinnabar's lab): HnS teaches
    them only in Johto (the Route 40 gate, Olivine City).
  - Missing in Origin Jade's Kanto: Sleep Talk, Rollout, Dynamic Punch,
    Swagger and Explosion; Origin Jade teaches them only at their Emerald
    places in Hoenn.
  Proposal: keep all twelve FRLG tutors (ten moves were in HnS's Kanto,
  the other two come in Johto right after Kanto; removing them only takes
  moves away), and bring HnS's five missing tutors into FRLG's Kanto at
  the same places (Viridian City, Pewter City, Route 4, Route 4's Pokemon
  Center, Cinnabar Island's Pokemon Center). Adding them needs objects in
  the maps (Porymap, owner); a strict reading of the rule would also take
  out Substitute and Metronome. Owner to decide.
- **O-057** Item randomizer, left from N-07 (D-054):
  - Slateport's Berry Powder man (`SlateportCity/scripts.inc`) is the same
    exchange as Cerulean's but still uses `giveitem`; the map was being
    edited in Porymap by the owner on 2026-11-02. Proposal:
    `giveitem_norandom` there too once the map is back.
  - Single items for money: HnS itself differs (Mahogany's merchant through
    the randomizer, the Moomoo Milk not). Mt. Chimney's Lava Cookie lady
    and Route 109's Seashore House (Soda Pop) use `giveitem` like
    Mahogany's merchant and stay randomized. Proposal: keep as HnS.
  - Start: HnS randomizes from its first Poke Balls
    (`FLAG_RECEIVED_FIRST_BALLS`), Origin Jade from the first starter
    (D-023); Oak's Poke Balls and Route 1's Potion sample (`additem`) are
    not randomized either. Proposal: keep.
- **O-058** Randomizer species pool (owner question 2026-11-02). HnS 2.0.5
  builds every generation (`species_enabled.h`: Gen 1-9 and the regional
  forms on) and has a GEN SCOPE row in the randomizer tab: "GEN 1-3", the
  default (Gen 1-3 families with their cross-gen evolutions and
  pre-evolutions, plus the regional forms of its obtainable Pokedex), or
  "GEN 1-9" (every species); it can be changed during a run. Origin Jade
  builds only Gen 1-3 with their cross-gen evolutions (Gen 4-9 lines and
  regional forms off, D-023, D-037), so its pool is HnS's default without
  the regional forms, and the row is hidden. The Nuzlocke has no pool of
  its own (its species clause looks at the species met). Options:
  (a) keep it so and name the difference in the forum post;
  (b) as HnS: Gen 4-9 and the regional forms back on and the row shown
  again: a larger ROM and save layout (Pokedex flags), new species in
  every list and in the region rule and dex counts (D-049), the locked
  content of O-009 comes back into play; several days with tests.
  Proposal: (a) for the beta.
- **O-060** Kampfzone items in the Hoenn Test (D-050): the M.S. Aqua
  reaches the Kampfzone after its maiden voyage, so after the Johto title
  (D-029), and Battle Points then buy 32 items the Hoenn Test does not
  hold (Power items, Choice Scarf, Focus Sash, Assault Vest, Eviolite,
  Rocky Helmet, Ability Capsule and Patch, Dive, Repeat and Timer Ball
  ..., at the BP exchange of the Kampfzone and of the Trainer Hill's
  courtyard). The generator leaves the Kampfzone out because the states
  leave it untouched and `GetCurrentRegion` counts it as Hoenn. The owner's
  answer to S-02 ("Kampfzone erst ab Hoenn-Titel") was given on the Hoenn
  ferries. Options: (a) the Hoenn Test adds the BP items once; (b) they
  stay out, the Kampfzone counts as Hoenn; (c) the Kampfzone opens only
  after the Hoenn title everywhere (the M.S. Aqua entry,
  `Common_EventScript_ShipMenuPushIslands`), then (b) follows.
- **O-063** Resolved 2026-11-02: Hoenn's Pokeblock Case comes from the
  little girl in Slateport's contest lobby (D-058). The desk on Route 121
  has a line of its own naming Slateport's contest hall
  (`Route121_SafariZoneEntrance_Text_YouNeedPokeblockCaseSlateport`);
  Johto's Safari Zone gate keeps "the boy over there".
- **O-065** Resolved 2026-11-02: the Ruby/Sapphire contest halls behind
  the lobbies of Verdanturf, Fallarbor and Slateport (D-058) show the RS
  contest hall texts that sat unused in the corridors of the Emerald
  battle tents. `MyPapaIsContestJudge` and `ItsAppealTime`, the two that
  were still English, and the three stage signs got the German Ruby/
  Sapphire wording. The texts of the HnS copy of the lobby at Route 40
  (`SlateportCity_BattleTentLobby_hns`: 3 shown, 2 of an unused script)
  have been German since 2026-11-02 (D-057).
- **O-066** 28 trainer names in `src/data/trainers_hns.party` are still in
  upstream capitals (HnS's Kanto leaders and Blue, the POSTOBC rematch
  teams of Johto and Kanto). None is shown today: only scripts of retired
  HnS Kanto maps fight the leaders (`src/battle_bg.c` uses Blaine's id
  only for the background), the POSTOBC teams only behind Sinjoh
  (D-019). Proposal: German names (Rocko, Misty, Major Bob, Erika,
  Sabrina, Pyro, Blau, Falk, Kai, Bianka, Jens, Hartwig, Jasmin, Norbert,
  Sandra, Janina, Willi, Koga, Bruno, Melanie, Siegfried) when Sinjoh is
  unlocked or a team is reused.
- **O-067** Resolved 2026-11-02: Emerald's Verdanturf Battle Tent is
  retired (D-030), so only the girl in the HnS copy of its lobby at
  Route 40 (`VerdanturfTown_BattleTentLobby_hns`) sets
  `FLAG_RECEIVED_TM_ATTRACT`; she gives TM Safeguard. The girl in
  Verdanturf's contest lobby (Ruby/Sapphire) gives TM Attract with a flag
  of her own, `FLAG_HOENN_RECEIVED_TM_ATTRACT` (D-058).
- **O-068** Rank per contest hall (D-058): the owner's note of
  2026-11-02 gives Laubwechselfeld (Fallarbor) the Normal Rank and
  Wiesenflur (Verdanturf) the Super Rank, but also asks for contests
  "ganz wie Rubin/Saphir", where Verdanturf holds Normal and Fallarbor
  Super and the German RS texts send the player to Wiesenflur for the
  Contest Pass. Built as RS. Swapping the two needs the two receptionist
  scripts (`VAR_CONTEST_RANK`), the stage's exit warps
  (`data/maps/ContestHall/scripts.inc`), the Contest Pass texts and the
  town and stage signs. Owner to confirm.
- **O-069** Contest paintings (D-058): the frame in the lobbies of
  Verdanturf, Fallarbor and Slateport shows the newest winner of any
  contest, because Emerald keeps one list of the six newest winners
  (Lilycove's six frames). RS kept one painting for Normal, one for Super
  and three each for Hyper and Master. Per-rank paintings would need
  `GetContestWinnerSaveIdx` (`src/contest.c`) to file winners by rank, and
  Lilycove's frames would then show Master and Hyper winners only.
  Proposal: keep the newest winner everywhere.
- **O-070** Scott in Slateport (D-058): Emerald lets him leave the battle
  tent after the museum scene and talk about the tent challenge. The tent
  is a contest hall now; he leaves the hall and says he looked for strong
  trainers there (`SlateportCity_Text_ScottLeavesContestHall`, a new text,
  not from an official game). Ruby/Sapphire has no such scene. Options:
  (a) keep the scene with the new text; (b) drop the scene (one Scott
  meeting less for `VAR_SCOTT_STATE`, which sets the Battle Points he
  gives in the Kampfzone; the top gift would then need 10 instead of 11,
  D-030). Proposal: (a); the owner reads the text.
- **O-073** Resolved 2026-11-03: Scott is not needed for the story
  (owner). His two tent meetings in Verdanturf and Fallarbor stay out;
  his gift in the Kampfzone gives 4 Battle Points from 11 meetings on,
  the number still possible (D-030).
- **O-074** TMs of HnS's old Kanto (D-019): 21 TMs that HnS gives only in
  its own Kanto, whose maps are retired here, have no source in Origin
  Jade; only the item randomizer can roll them. 14 of their moves no
  tutor teaches either: Stone Edge, Will-O-Wisp, Energy Ball and X-Scissor
  (rewards after the last rematch with the HnS trainers Kenny on Route 13,
  Trevor on Route 14, Hillary on Route 15 and Rob in Viridian Forest);
  Silver Wind, Flash Cannon, Rock Polish, Grass Knot, Brine, Fling and
  Recycle (items on Routes 6, 9, 10, 11 and 19, in Rock Tunnel and in
  Celadon City; Brine also in the Celadon Department Store); Giga Impact,
  Captivate and Gyro Ball (Celadon Department Store). Seven have a tutor
  but no TM: Endure, Explosion, Thunder Wave, Psych Up, Rock Slide, Sleep
  Talk and Dream Eater. The rematch rewards (Stone Edge, Will-O-Wisp,
  Energy Ball, X-Scissor, and Thunder Wave from Carter on Route 14) need
  another giver: those HnS trainers are not in FRLG Kanto, whose rematches run through the VS
  Seeker (D-034). Proposal, after the owner's rule that what HnS's Kanto
  had comes to FRLG Kanto: all 21 into FRLG Kanto, at the same places
  where possible (the department store, items and gifts; a rematch
  reward from a FRLG trainer on the same route after his last VS Seeker
  rematch; Rock Slide as an item in Pewter City or Rock Tunnel). Owner to
  decide.

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
| Goldenrod's TM lady and the haircut brothers follow day and night | HnS | D-033 (2026-10-20) |
| Entering the Bug-Catching Contest uses up the day | D-033 (2026-10-15) | D-033 (2026-10-20) |
| Suicune waits on Glockenturm 1F after both Johto sightings (var 3); Eusine's hint at the second sighting | D-027 (2026-10-15) | D-038 (2026-10-27) |
| Johto's static and legendary levels fixed (Lugia/Ho-Oh 50 and 70, Suicune 50, Raikou/Entei 40, Sudowoodo 20) | D-026 / D-031 (2026-10-15) | D-039 (2026-10-27) |
| Pokemon that faint in a battle with an AI partner die at its end | d05aa4864f (audit A30) | D-054 (2026-11-02, as in HnS) |
| The ship menus offer "Hoenn" only until Birch's welcome | D-047 (2026-10-31) | D-047 (2026-11-02, O-032) |
| The region rule is off only with randomizer options that change the player's species | D-049 (2026-10-31) | D-049 (2026-11-02, O-033) |
| Elm's call after the first Johto title waits for a visit to New Bark Town | `NewBarkTown_OnFrame` (HnS trigger kept while home moved to Pallet Town, D-028) | D-051 (2026-11-02, O-036) |
| One Day Care storage for all regions | Emerald / HnS | D-052 (2026-11-02) |
| Scaled bosses keep the moves of their original level; Johto's league aces all at the corridor's 65 | HnS / Emerald, D-012 | D-053 (2026-11-02) |
| Emerald's Trainer Hill on Route 111 works with its own trainers, prizes and records | D-044 (2026-10-30) | D-044 (2026-11-02) |
| Battle tents in Verdanturf, Fallarbor and Slateport; Lilycove's contest hall holds every rank and its reception gives the Pokeblock Case | Emerald | D-030, D-058 (2026-11-02) |
