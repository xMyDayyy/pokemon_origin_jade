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
- **Status:** Active
- **Decision:**
  - Kanto badges are `FLAG_BADGE01_GET`-`FLAG_BADGE08_GET` (FRLG gyms).
  - Johto badges are the bitmask `VAR_JOHTO_BADGES` (`src/johto_badges.c`).
    The Johto gym scripts still set `FLAG_BADGE0x_GET` as well; in Johto
    those flags mean nothing, because the Kanto league set them long before.
  - Hoenn badges are `VAR_HOENN_BADGES` (`src/hoenn_badges.c`).
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
- **Status:** Active (Johto exit changed 2026-10-30)
- **Decision:** `ReceptionGate_hns` connects east to Kanto (Route 22 gate,
  needs all eight Kanto badges), south to Johto (opens with
  `FLAG_SYS_GAME_CLEAR`, i.e. after the Kanto league; while
  `VAR_JOHTO_HANDOVER` is 1 the guard sends the player to Oak for the GS
  Ball first, D-004), west to Mt. Silver
  (opens only with `FLAG_IS_JOHTO_CHAMPION` - Red is level 77-93) and north
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
- **Status:** Active (ladder changed 2026-10-29, level caps changed
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
    44, anchor 45). The debug menu's Johto test starts with such a team
    (`tools/make_kanto_complete.py`).
  - Obedience for traded Pokemon follows the number of Kanto badges (10,
    then +5 per badge, 50 with eight); after the Johto title every Pokemon
    obeys (D-031).
  - Level-cap challenge (`src/caps.c`, D-041), per number of Kanto badges:
    "Normal" is the next leader's ace (10, 17, 21, 28, 36, 39, 42, 42; with
    eight badges the champion's 47), "Hard" the next leader's lowest level
    (9, 16, 19, 26, 34, 37, 40, 40; 45), as HnS derived its tables.
  - After the Kanto title Kanto scales to the player and these hand-set
    levels are the floor (D-031).
- **Evidence:** b20f555d4d, 20fa75b584, 1662b679fc, 2f349b5ce2, af10c86033;
  ladder: decision 2026-10-29.

### D-012 Johto and Hoenn: dynamic level scaling
- **Status:** Active (anchor, bands and corridors changed 2026-10-29,
  battle partners, the Goldenrod/Ecruteak ceilings and rematch team sizes
  changed 2026-10-30)
- **Decision:** Johto and Hoenn scale to the player (`src/level_scaling.c`,
  `include/config/johto_scaling.h`, `include/config/hoenn_scaling.h`).
  - Anchor, in every region: the mean of the three highest party levels,
    rounded, but at most `SCALING_ANCHOR_MAX_DROP` (8) below the highest
    level (`include/level_scaling.h`). Weak fillers do not pull the levels
    down: a level 100 Pokemon with five level 1 Pokemon gives 92.
  - Trainers: anchor -3..+0 (Hoenn -5..+0), a boss's ace +1. Wild Pokemon:
    anchor -10..-4. Corridors per map section clamp both.
  - Johto corridors: Routes 26 and 27, Tohjo Falls 40-80; arrival up to
    Bugsy 41-50 (Cherrygrove 41-48); Whitney and Morty 44-53 (Goldenrod
    44-61 from the Radio Tower takeover, `VAR_MAHOGANY_TOWN_STATE` 16;
    Ecruteak 44-61 from Elm's Master Ball, which opens the theater's
    legendary event, `VAR_ECRUTEAK_CITY_THEATER` 4; optional story
    ceilings in the corridor table); Chuck and Jasmine 47-55; Rocket
    Hideout and Pryce 50-58; Clair, Tin Tower and the Whirl Islands 56-64;
    Victory Road and the league 58-65; Mt. Silver 70-90 (Red unscaled).
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
  its own Pokemon). Rematch teams scale
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
- **Status:** Active (amended 2026-10-29, changed 2026-10-30, owner decision)
- **Decision:** All 185 species of the Gen-1 families are obtainable in
  Kanto without link trades: both fossils at Mt. Moon, both Hitmons at the
  dojo, evolution items placed in Kanto, all three starters in the wild
  (5 %), two-slot day care with breeding, extra Game Corner prizes. Day and
  night replace the FireRed/LeafGreen version split. Overworld Pokemon show
  what can be caught on a map (next to, not on, the encounter tiles).
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
  - Everything is obtainable before the first Kanto title except Mewtwo and
    Electivire, which come from Cerulean Cave right after it.
- **Evidence:** 71a79b3a14, ff6d47ca45, ead606af10, 7aacaa2699,
  d8f26d241e, d0e2cc9ec4, 2d0e6a62af, 00da4d2a7a, 535f47948b, 5578b2caee;
  decision 2026-10-29 (LeafGreen exclusives at night, Sevii items replaced,
  Kleavor is in the game); decision 2026-10-30 (every starter wild, day and
  night).

### D-014 HM handovers in Johto never leave the player empty-handed
- **Status:** Active (changed 2026-10-30: Wallace's HM Waterfall in Hoenn)
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
- **Status:** Active (changed 2026-10-30: budget, layout guards)
- **Rules:** The save layout freezes with the release; until then it may
  grow deliberately (2cbf85903d). One-time migrations of Origin Jade run in
  `LoadGameSave` (`src/save.c`) and are keyed to a flag from the Origin Jade
  block, which new games set right away - never through `SAVE_VERSION`:
  that number belongs to HnS upstream and is bumped there.
- **Budget** (2026-10-31; `python3 tools/check_budget.py` prints it after a
  build): SaveBlock1 15868 of 15872 bytes (4 free), SaveBlock2 3892 of 3968
  (76 free), SaveBlock3 1008 of 1624 (616 free), PokemonStorage 34144 of
  35712 (1568 free). The limits are the flash space `src/save.c` checks
  with `STATIC_ASSERT`; new Origin Jade data goes to SaveBlock3 (D-016).
  SaveBlock1 reserves that can be reused in place without moving offsets:
  `roamerPadding` (84 bytes), `dexPadding1` and `dexPadding2` (63 each),
  `unused_9C6` (2), `outbreakUnused1/2/3`. Memory: EWRAM 249180 of 262144
  bytes (95.05 %, of which `gHeap` 115968), IWRAM 25704 of 32768
  (78.44 %), ROM 25897336 of 33554432 (77.18 %).
- **Layout guards and reserves (2026-10-30):**
  - Sizes: SaveBlock1 15868 of 15872 bytes (4 free), SaveBlock2 3892,
    SaveBlock3 1008 of 1624 (616 free), PokemonStorage 34144. `test/save.c`
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
- **Status:** Active (changed 2026-10-30)
- **Decision:** HnS's GEN SCOPE option (randomizer pool limited to Gen 1-3
  families) stays in the code and the save, but has no row in the challenge
  menu and is off (`RANDOMIZER_DEFAULT_GEN_SCOPE_1_3` FALSE in
  `include/config/randomizer.h`). Gen 4-9 and the regional forms are off in
  `species_enabled.h`, so both settings give the same pool.
  - Items ("Items: Zufall", `src/randomizer.c`): item balls, hidden items
    and NPC gifts are randomized from the first starter on
    (`FLAG_SYS_POKEMON_GET`), so in all three regions. Key items, HMs and
    the GS Ball keep their place, and so do fossils and evolution items
    (sort types evolution stone, evolution item and fossil, plus King's
    Rock, Metal Coat, Deep Sea Tooth, Deep Sea Scale, Razor Claw and Razor
    Fang), so D-013 and D-037 hold with the item randomizer too; they can
    still be rolled for other items. Oak's five Poke Balls (after the
    Pokedex and the refill after the Route 22 rival) and the coin prizes of
    Celadon's prize room (`giveitem_norandom`) bypass the randomizer. Other
    exchanges that use `giveitem` (Cerulean's Berry Powder man, Route 113's
    Glass Workshop) still go through it. A Kanto gift with its own receive
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
  - Starters ("Starter: Zufall"): only Oak's preview applies it (and the
    one-type challenge); the lab hands out exactly the previewed and named
    species with the preview's shininess (D-035). Elm's and Birch's labs
    hand out the shown species.
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
  Hoenn levels 2026-10-29, D-043)
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
    title once the chosen one is caught (level 80; the chosen one keeps its
    story level 78, D-039). Route 41's Tentacruel then step aside for Ho-Oh
    choosers.
  - Latias and Latios both roam Hoenn after the first Hoenn title (level 100,
    Emerald routes). No Latias roams Kanto or Johto. Faraway Island,
    Southern Island and Navel Rock are not offered anywhere.
  - Levels: Johto's follow D-039, Hoenn's D-043 (both never below the top of
    the map's wild band); Kanto's are fixed (birds and Mew 40, Mewtwo 50,
    D-011). Sudowoodo and
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
  in Pallet Town).
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
    after the first Johto title comes on the next visit to New Bark Town.
    After every Hoenn title it
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
- **Evidence:** decision 2026-10-15 (O-013).

### D-029 Magnet Train, radio quiz and ships
- **Status:** Active (2026-10-15, ships changed 2026-10-20, Hoenn trips
  changed 2026-10-30, changed 2026-10-31: Hoenn entries of the ship menus,
  D-047)
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
    trip with the "Hoenn" entry lands on the Route 104 pier, where Birch's
    arrival scene starts. The trips to Slateport and Lilycove (D-047)
    change no Hoenn state, so a trip never opens a town early or lands in
    a scene. The ticket is not used up. Every trip sets the respawn: in
    front of Birch's lab for the pier, the Pokemon Center of Slateport or
    Lilycove for their harbours. Whoever leaves the beach before Birch's
    greeting (Fly, Teleport, Dig) gets the welcome (Pokedex, badge case,
    Birch's contact) on entering the lab (D-005).
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
- **Status:** Active (2026-10-15, Johto statics changed 2026-10-27, D-039,
  Hoenn statics 2026-10-29, D-043)
- **Decision:** After a region's title its trainers (rematches included) and
  wild Pokemon scale to the player's anchor without a ceiling (level 100).
  - Kanto: FRLG maps, off before `FLAG_IS_KANTO_CHAMPION`; no corridors, the
    hand-set level (D-011) is the floor, the band is Johto's, trainer
    Pokemon evolve (`include/config/kanto_scaling.h`).
  - Johto and Hoenn: corridor ceilings become 100 with
    `FLAG_IS_JOHTO_CHAMPION` / `FLAG_IS_HOENN_CHAMPION`; floors stay.
  - Fixed: Red, the facilities, and Kanto's static and scripted encounters
    (D-026). Johto's and Hoenn's, roamers included, never fall below the top
    of the map's wild band (D-039, D-043). Steven at Meteor Falls (level 75-78) stays
    fixed as the owner set it before (876c3d4c19, Hoenn's counterpart to
    Red, `HOENN_SCALING_FIXED_MIN_LEVEL` 70); setting it to 79 lets only him
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
- **Status:** Active (2026-10-21, changed 2026-10-31: 422 species)
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
    unchanged. The charm adds `I_SHINY_CHARM_ADDITIONAL_ROLLS` shiny rolls.
  - The National Pokedex counts the enabled species of HnS's obtainable dex
    (422: Kanto 151, Johto 129, Hoenn 142, D-049); species disabled in this
    build do not count, in `HasAllMons` as in the count and the rating. All
    422 are obtainable without trading (D-037). Not required: the
    mythicals and Regirock, Regice, Registeel (HnS's `dexNotRequired`;
    owner kept it 2026-10-26).
  - Code: `DayCare_EventScript_GiveOvalCharm` (`data/scripts/day_care.inc`,
    called by the egg scripts of Route 5, Route 34 and Route 117);
    `LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveShinyCharm` (runs
    before `Special_ShowDiploma`).
- **Evidence:** decision 2026-10-21 (O-008).

### D-037 Hoenn is complete without trading
- **Status:** Active (2026-10-26, changed 2026-10-30, starters: owner decision;
  changed 2026-10-31: 422 species)
- **Decision:** All 422 species of the National Pokedex (D-049) and the
  whole Hoenn dex are obtainable without link trades. As in Kanto (D-013), day and night
  replace the Ruby/Sapphire version split on Emerald's wild tables.
  - Route 102: Surskit (10 %); Route 117: Roselia (20 %) and Surskit (10 %),
    day and night. Masquerain at level 22, Budew by breeding Roselia without
    incense (`P_INCENSE_BREEDING` Gen 9), Roserade with the Shiny Stone
    (Celadon Department Store 4F, Mahogany's granny shop).
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
  - Jirachi has no source (only HnS's retired Mt. Moon); it is not required
    for `HasAllMons`.
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
  changed 2026-10-30: roamer example corrected). Replaces the fixed levels
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
    - Deoxys, Birth Island (after the Johto title): 80 (70);
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
  - Roamers keep the level they started with. Raikou and Entei start at
    their level in `src/legendaries_oj.c`; a roamer below it, or below the
    floor, moves up at its next encounter and keeps its share of HP
    (`TryRaiseRoamerLevel`, `src/roamer.c`).
  - Kanto: D-011, Hoenn: D-043.
- **Evidence:** decision 2026-10-27.

### D-040 Hoenn keeps its own state where a finished Kanto would leak into it
- **Status:** Active (2026-10-29, Johto leaks changed 2026-10-30, Strength
  and Flash changed 2026-10-30)
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
- **Evidence:** full Kanto run analysis, decision 2026-10-29.

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

### D-044 Two Trainer Hills: HnS's by Route 40, Emerald's on Route 111
- **Status:** Active (2026-10-30)
- **Decision:** Both hills work, each with its own data:
  - Route 40 (Johto post-game, D-041) stays HnS's hill: HnS trainers, party
    at level 50, item prizes plus money, records in SaveBlock1
    (`trainerHillTimes`).
  - Route 111 (opens with `FLAG_IS_HOENN_CHAMPION`) is Emerald's hill:
    Emerald's trainers and floors, opponents at the level of the player's
    strongest Pokemon, Emerald's prizes (TMs and items, no money), records
    of its own in SaveBlock3 (`trainerHillTimesHoenn`). A loss returns the
    player to its own reception.
  - `src/trainer_hill.c` picks the set by the map layout
    (`IsHnsTrainerHill`); scripts ask with `trainerhill_inhoennhill`.
  - Both hills share `MAPSEC_TRAINER_HILL` (O-024).
- **Evidence:** decision 2026-10-30 (make the Route 111 hill work instead of
  retiring it).

### D-045 Nuzlocke rules
- **Status:** Active (2026-10-30; changed 2026-10-30: static encounters,
  eggs, nicknames of starters and gifts). The end point waits for the
  owner's confirmation (O-025).
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
    the Bug-Catching Contest (its party is restored afterwards). In battles
    with an AI partner (Lance in the Rocket Hideout, Steven in Mossdeep's
    Space Center) this happens to the player's own Pokemon once the party
    is restored after the battle (multi battle macros in
    `asm/macros/battle_frontier/battle_tower.inc`).
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
  - Open: deaths in the Trainer Hills (O-028).
- **Evidence:** audit 2026-10-30 (A23, A25, A30, A79, A83, A87); owner
  decision 2026-10-30 (rules as usual in the Nuzlocke community: static
  encounters and eggs are free).

### D-046 Only Origin Jade is built
- **Status:** Active (2026-10-30)
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
  `tools/make_kanto_complete.py --check` and `tools/check_budget.py`;
  `check_merge.py` runs without blocking. Map errors that are unreachable
  or intended go into its `KNOWN_ERRORS` with the decision that covers
  them. The upstream Docs and Labels workflows run only by hand.
- **Debug menus:** the overworld debug menu (R + Start, with "Johto Test"),
  the battle debug menu (Select) and the sprite visualizer are on in the
  normal build (beta testing) and off in `make release`
  (`DISABLED_ON_RELEASE`, `include/config/debug.h`).
- **Evidence:** owner decisions 2026-10-30 (only Jade; debug menus on in
  the beta, off in the release).

### D-047 Hoenn Ticket story and ports
- **Status:** Active (2026-10-31). Resolves O-002.
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
  - Troy has one sprite everywhere (owner); currently
    `OBJ_EVENT_GFX_STEVEN`, see O-031.
  - The ship menus in Vermilion, Olivine and on the islands (Kampfzone,
    Birth Island) are built on every visit and list only what can be
    sailed to now:
    - "Hoenn" from the Hoenn Ticket (`VAR_HOENN_TICKET_STATE` 3) until
      Birch's welcome in his lab (`VAR_HOENN_ARRIVAL_STATE` 3); every trip
      with it lands on the Route 104 pier (D-029). The entry stays after
      the first crossing while the welcome is pending (arrival state 1 or
      2); after the welcome the ticket opens no more trips.
    - "Graphitport City" after the welcome once Slateport was visited,
      unless its harbour is closed for Team Aqua's submarine scene
      (`VAR_SLATEPORT_HARBOR_STATE` 1); it lands in Slateport's harbour
      (8,11).
    - "Seegrasulb City" after the welcome once Lilycove was visited; it
      lands in Lilycove's harbour (8,11).
    - Without such a visit no ship goes there. Fly to Littleroot Town
      always works, because the first crossing marks it visited.
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
  story).

### D-048 Hoenn: an unknown trainer, Norman is not the father
- **Status:** Active (2026-10-31)
- **Decision:** In Hoenn the player is a stranger. Apart from Troy, who
  brought the player to Hoenn, and Wallace (below), nobody there knows that
  the player is the champion of Kanto and Johto or where exactly they come
  from; a few people have vague news (from the mainland, a strong trainer).
  Norman knows only the rumours: the player comes from the mainland and is
  a good trainer. Norman is a regular gym leader whose family lives in
  Littleroot Town (D-002, D-003). He is never the player's father, and no
  text the jade build can show says so. Hidden map objects and code names
  from Emerald's father scenes are still there (O-030).
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
    the e-mail too (D-002); that room still sets up the decorations (O-029).
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
- **Evidence:** owner requirements 2026-10-31 (point 4).

### D-049 Pokemon per region
- **Status:** Active (2026-10-31, owner decision)
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
- **Code:** `src/region_rule_oj.c` (the table of national numbers above
  386), `TryUnlockJohtoOnMapLoad` in both map loads of `src/overworld.c`;
  test `test/origin_jade/region_rule.c`.
- **Why:** The regions open one after the other in the story (D-001); a
  species of a later region should first turn up there.
- **Evidence:** owner decisions 2026-10-31 (Pokemon per region, evolutions
  exempt, no Pokedex filter, Gen 4 evolutions of Kanto lines count to
  Johto).

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
- **O-009** Enabling Sinjoh also needs the Gen 4+ and regional forms in
  `species_enabled.h`. Risks found 2026-10-30, harmless while Sinjoh stays
  locked and Alola has no way in:
  - Locked content still uses disabled species: the POSTOBC rematch teams
    in `trainers_hns.party` (the Elite Four, Lance and Red, chosen only at
    `VAR_SINJOH_STORYLINE` 13 or more; the gym leaders in HnS's retired
    Dojo VIP room), Sinjoh, Route 49/50 and Alola trainers, and the wild
    tables of Snowswept Cavern, Route 49 and the Alola caves.
  - The 20 Alola maps (`MelemeleIsle_hns` and the others) are active
    (`game_version` `hns`) but have no way in: the only warps are in the
    retired `Route13_hns`, and the Melemele fly spot needs
    `FLAG_VISITED_ALOLA`, which only Melemele sets. D-019 does not list
    them yet.
- **O-010** Resolved 2026-10-12: the Route 30 and Route 26 trees use the
  reserve slots `BERRY_TREE_ROUTE_30_ORAN` and `BERRY_TREE_ROUTE_26_SITRUS`;
  slot 33 is only shared with retired maps. Older saves are migrated in
  `LoadGameSave` (`FLAG_MIGRATED_JOHTO_BERRY_SLOTS`).
- **O-011** Resolved 2026-10-15: Oak's lab copies the ball number before the
  preview and hands out the starter with the preview's shininess.
- **O-012** Text debt: 172 Johto texts without a German branch
  (346072a202). Line widths, re-measured 2026-10-30 with
  `tools/check_text_width.py` (bytes of the built German ROM, FONT_NORMAL
  widths by glyph id, lines split at `\n`, `\l`, `\p`): no German line is
  wider than the 216 px text window; 30 are wider than the 208 px limit
  (29 Johto, 1 Kanto, 209-213 px, `--list` names them). Lines with
  `{PLAYER}`, `{RIVAL}` or `{STR_VAR_x}` are estimates (7 or 10 characters
  of 6 px): 199 may exceed 216 px, most of them in `data/text`. The locked
  Sinjoh and Alola maps (D-019) add 6 English lines over 208 px. The
  earlier 4951 lines over 216 px (652123e252) match the widths
  `check_pokenav_text.py` read one glyph off until 2026-10-30. Later, as
  its own round (owner 2026-10-21).
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
- **O-020** The Day Cares of Route 5, Route 34 and Route 117 share one save
  slot (`gSaveBlock1Ptr->daycare`, `FLAG_PENDING_DAYCARE_EGG`): Pokemon and
  eggs left in one region can be collected in the others.
- **O-021** Bill's PC name: `FLAG_SYS_PC_LANETTE` from Bill's Sea Cottage
  names the storage "Bills PC" in Kanto, Johto and Hoenn alike (Lanette on
  Route 114 sets the same flag). HnS's "Jemandes PC" until Ecruteak and
  Emerald's until Lanette do not occur.
- **O-022** Nuzlocke: Kanto's Route 22 and HnS's `Route22_hns` share
  `MAPSEC_ROUTE_22` (one first encounter for both); `MAPSEC_INDIGO_PLATEAU`
  is shared too, with no wild table there yet. In practice only the plateau
  matters: `Route22_hns` is active (game_version "hns", own wild table) but
  cannot be entered. No warp leads there, and its only active connection,
  from `Route26North_hns`, has no walkable tile on either edge. Only
  `src/roamer.c` and `src/string_util.c` refer to the map.
- **O-023** Badge readers still on Kanto's count: `HasEnoughBadgesForRematch`
  (all random Match Calls, "after Whitney" in HnS), the Gen-9 catch malus,
  the challenge menu's trainer IV/EV tables, the continue window's badge
  total (the save menu adds Johto and Hoenn).
- **O-024** Both Trainer Hills use `MAPSEC_TRAINER_HILL`, which the HnS
  build places on the Johto map and `IsHoennMapsec` does not count as Hoenn:
  inside the hill on Route 111 the region map shows Johto, its trainer
  battles play Johto's battle and victory music (`MUS_HG_VS_TRAINER`,
  `MUS_HG_VICTORY_TRAINER`), and Hoenn-only mapsec rules (rival name, item
  texts, Hoenn licenses) do not apply (D-044). A Hoenn mapsec of their own
  for the seven Emerald `TrainerHill_*` maps would end all of these.
- **O-025** Nuzlocke end point: the Nuzlocke ends at the first Hoenn title
  (D-045); until 2026-10-30 it ended when Red was beaten. Owner to confirm.
- **O-026** Resolved 2026-10-30: scripted static encounters can always be
  caught and use up no area (D-045).
- **O-027** Resolved 2026-10-30: eggs always hatch and use up no area
  (D-045).
- **O-028** Nuzlocke and the Trainer Hills (Route 40, D-041; Route 111 in
  Hoenn): their battles skip Nuzlocke deaths (`BATTLE_TYPE_TRAINER_HILL`
  in `HandleEndTurn_FinishBattle`, D-045), so a Pokemon that faints there
  stays in the party at 0 HP. Leaving a hill after a loss heals the party
  (`HealPlayerParty` in the entrance scripts), otherwise a Pokemon Center
  does. Rule needed: deaths count there like in other trainer battles, or
  the hills stay exempt like the Battle Frontier.
- **O-029** Room decorations: the bedroom PC in Pallet Town is the only one
  left (D-048) and still offers "Dekoration", but the Pallet Town bedroom
  never sets decorations up (no `SecretBase_EventScript_InitDecorations`
  there): dolls and cushions placed there are not shown again once the
  player leaves the room. The only room that still sets them up, at the same
  spots, is upstairs in the New Bark Town house, which belongs to a stranger
  (D-002). Options: set them up in the Pallet Town bedroom (ON_TRANSITION
  `SecretBase_EventScript_SetDecorationFlags` and ON_WARP
  `SecretBase_EventScript_InitDecorations` as in New Bark Town; check the
  FRLG layout in Porymap first), or hide "Dekoration" in the bedroom PC menu
  and stop setting them up in New Bark Town.
- **O-030** Leftovers of Emerald's father scenes, none of them visible in
  jade: the Littleroot Town maps keep the objects of the player's family,
  always hidden: Dad with Norman's sprite on the ground floor of both houses
  (`LOCALID_PLAYERS_HOUSE_1F_DAD`, `FLAG_HIDE_PLAYERS_HOUSE_DAD`), Mom in
  both houses (`LOCALID_PLAYERS_HOUSE_1F_MOM` with the empty
  `PlayersHouse_1F_EventScript_Mom`, `LOCALID_PLAYERS_HOUSE_2F_MOM`) and
  in front of them (`LOCALID_LITTLEROOT_MOM`). Upstream names stay too,
  e.g. `DisplayDadsAdviceCannotUseItemMessage` (shows Birch's line in Hoenn,
  D-048) and `gText_DadsAdvice` (not built). Removing the objects needs
  Porymap, and the non-jade scenes kept for merges still use them;
  renaming upstream names makes merges larger (D-021, D-046). Owner to
  decide whether they go.
- **O-031** Troy's sprite: the owner decided on one sprite everywhere
  (D-047). The build uses Emerald's `OBJ_EVENT_GFX_STEVEN`; HnS's
  `OBJ_EVENT_GFX_STEVEN_HNS` is the alternative. Not compared in an
  emulator yet next to the other people of his scenes (FRLG's Oak in his
  lab, HnS's Oak and Lance in Johto's Hall of Fame).
- **O-032** Nuzlocke without a flyer after Birch's welcome: from then on
  the ship menus offer no "Hoenn" entry, and Slateport's and Lilycove's
  harbours only once visited (D-047). A player who flies back to Kanto or
  Johto before reaching Slateport and then loses every Pokemon that can
  use Fly (Nuzlocke deaths) has no way back to Hoenn until they get a new
  flyer, and the areas of Kanto and Johto are mostly used up by then.
  Rule needed: e.g. keep "Hoenn" until Slateport was visited, or accept
  it.

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
