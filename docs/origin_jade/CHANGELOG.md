# Origin Jade - changelog

Changes of the audit round of 2026-10-30/31, of the story packages that
followed it on 2026-10-31, of round 2 on 2026-11-02 (the owner's answers
of 2026-10-31 and 2026-11-02) and of round 3 on 2026-11-02/03 (contests as
in Ruby and Sapphire), for players and testers. The upstream
`CHANGELOG.md` in the repository root belongs to pokeemerald-expansion and
is not about Origin Jade.

- Base: `3525d22e71` (branch `balancing`). The commit ids below are those of
  the integration branch `audit` (`balancing` up to `2f284d83b9`) and, for
  rounds 2 and 3, of the branch `runde23` on top of the owner's map
  commits `06ea236bdb` and `ad4a8db368` (round 2 was rebased onto them;
  its ids before the rebase are no longer used);
  `docs/origin_jade/PATCHES.md` lists every commit, including
  documentation and tool-only ones that change nothing in the game.
- Names: English names first, the German in-game name in parentheses where
  it differs and a tester needs it to find the place.
- Every change was checked statically (source read, built, `check_flags`)
  and many with the new check tools. None was tested in an emulator yet; see
  `docs/origin_jade/BETA_READINESS.md`.
- Saves made before this round are not migrated and were not tested; start
  a new game (owner decision 2026-10-30). Randomizer seeds changed as well.
  Round 2 changes the save layout again (separate Day Cares, D-052);
  round 3 adds four flags and leaves the layout as it is.

## Round 3: contests as in Ruby and Sapphire

The owner's answers of 2026-10-31 and 2026-11-02 retire Emerald's battle
tents and the Trainer Hill on Route 111 (S-04, S-05: HnS's endgame
counts) and bring the contests back "ganz wie Rubin/Saphir", in four
halls (D-058). On `balancing` the owner drew the hall buildings in place
of the tents and removed the hill from Route 111 (`06ea236bdb`, tilesets
`ad4a8db368`; the tileset commit also changes a few shared tiles on
Routes 110, 111 and 118 and in Mauville and Slateport, see the risks in
`BETA_READINESS.md`); rounds 2 and 3 sit on top of those commits. The
new texts come from the German Ruby and Sapphire or the owner's texts;
Scott's line in Slateport (O-070) and the last sentence of the Route 121
Safari Zone desk are new, for the owner's text round.

### Contests (D-058)

- One rank per hall, as in Ruby and Sapphire: Verdanturf Town
  (Wiesenflur) Normal Rank, Fallarbor Town (Laubwechselfeld) Super,
  Slateport City (Graphitport City) Hyper, Lilycove City (Seegrasulb City)
  Master and, as before, the link contests. The owner's note names the
  towns of Normal and Super the other way round (O-068, open).
  `d969de7b0b`
- Verdanturf, Fallarbor and Slateport have Ruby and Sapphire's contest
  lobby with its people, behind the doors the owner drew in place of the
  tents. The receptionist names the hall's rank and offers to enter, info
  and exit, without a rank menu; every hall and Lilycove's link counter
  ask for the Contest Pass (Wettbewerbskarte), which Verdanturf issues; a
  higher rank needs the ribbon of the rank below in the same category.
  After a contest the player comes back to the lobby of the hall that held
  it, where the reporter of the Bravo Trainer interview may wait.
  `d969de7b0b`
- Pokeblock Case (Pokériegelbox): the little girl in Slateport's lobby
  gives it, a case from Baoba counts; Lilycove's receptionist no longer
  does, and the girl in Lilycove's lobby only gives her tip on making
  Pokeblocks. Each new lobby has a link Berry Blender and one with people;
  the old man gives a Pecha Berry once a day to a player without berries.
  Fallarbor's sketch artist hangs up a sketch after a win there; the girl
  in Verdanturf's lobby gives TM Attract (TM Anziehung) with a flag of her
  own. `d969de7b0b`
- A door in each new lobby leads to Ruby and Sapphire's audience hall with
  its stage and people. Its texts are the hall texts Emerald left unused
  in the corridors of its tents; the last two English ones and the three
  stage signs are German now (O-065). The sailor in Slateport's hall gives
  TM Torment (TM Folterknecht). `ebc78f0ec9`
- Towns: the signs at the hall doors name the rank (Lilycove's the Master
  Rank), and the people who spoke of the battle tents speak of contests
  again: in Verdanturf the camper, the old man in the Pokemon Center and
  the old lady in the mart; in Slateport the boy, a man by the market and
  the girl in the house near it, who asks for the Contest Pass. Scott
  still comes out of Slateport's hall after the museum scene, now with a
  new line (O-070). `bddcd1dc75`
- Safari Zone on Route 121: without a Pokeblock Case the desk sends the
  player to Slateport's contest hall instead of to "the boy over there",
  who is not in Hoenn (O-063). `eb5d7173a1`

### Retired: battle tents and the Route 111 Trainer Hill (D-030, D-044)

- Emerald's battle tents in Verdanturf, Fallarbor and Slateport are
  retired (9 maps, 4 layouts); no door leads there any more. The HnS
  copies in the courtyard of the Route 40 Trainer Hill stay, without
  Scott: his two tent meetings are gone, so he gives at most 3 instead of
  4 Battle Points in the Kampfzone (open question O-073). The girl in the
  Verdanturf copy gives TM Safeguard with the old flag, Verdanturf's
  contest girl TM Attract with her own (O-067). `c0a6f90aba`
- Emerald's Trainer Hill on Route 111 is retired (7 maps, 7 layouts): the
  owner removed its building, warp and sign; Route 111 no longer resets
  the hill's state, and the Hoenn map of the PokeNav no longer shows a
  Trainer Hill on Route 111, also after a visit to the hill by Route 40
  (O-024). Its code and its records stay unused; the save layout does not
  change. The map checker's two critical findings (the hill's entrance
  warps to the removed Route 111 warp) are gone. `61ac7e277d`
- Four new flags (the reporters of Verdanturf and Fallarbor, TM Attract,
  TM Torment), no new var, no change to the save layout.

## Round 2: owner answers of 2026-10-31 and 2026-11-02

The owner answered the open points of the first round: story and Hoenn
(`S-` points), balance (`B-`), Nuzlocke, challenges and randomizer as in
HnS (`N-`), several open questions (`O-`), and the beta plan: the beta
comes out in German first, so every text the German build shows gets a
German branch (the English one stays selectable). New decisions D-051 to
D-057; the new German texts that are not from an official German game
are drafts for the owner's text round.

### Story, calls and ports (D-047, D-048, D-051)

- Ship menus: "Hoenn" (the Route 104 pier) stays in the menus of the ports
  and island sailors from the Hoenn Ticket on until "Graphitport City"
  (Slateport City) can be offered, after a visit and not during Team
  Aqua's submarine scene in its harbour. Before, "Hoenn" went away with
  Prof. Birch's welcome, so a player without a flyer in Kanto or Johto
  (Nuzlocke) had no way back until Slateport was visited. Birch's greeting
  at the pier comes only after the first trip. `8a436c258b` (O-032)
- Hoenn's calls ring only in Hoenn: Wally's (Heiko's) call after Mauville
  City, Roxanne's (Felizia's) registration call, Scott's calls after the
  Fortree badge and after the first Hoenn title and the rival's call after
  the Space Center count their steps only on Hoenn maps and come after the
  return. `4a168b28b9` (S-07)
- After the first Hoenn title Scott calls in Littleroot Town (Wurzelheim):
  he is aboard the S.S. Tidal and invites the player to the ferry
  (Emerald's call, kept as the hint the owner asked for); whoever meets him
  on board first does not get the call afterwards. `d84bc3c745` (S-02)
- Elm's (Lind's) call after the first Johto title comes on the first step
  out of the house in Pallet Town (Alabastia), as HnS's came at home in
  New Bark Town; before, only on the next visit to New Bark Town.
  `f0b3e86bee` (O-036)
- Pallet Town bedroom: dolls and cushions placed at the bedroom PC stay in
  the room. After a title (Kanto, every Johto title, Red) the game
  continues in front of the stairs at (9,3) instead of next to the bed,
  where three dolls could box the player in for good; a new game still
  starts next to the bed. `e40a94553b` (O-029, open: O-041)
- Troy keeps Emerald's sprite everywhere (already built, recorded).
  `9ddb662b5d` (O-031)
- Littleroot Town: the always hidden objects of Emerald's player family
  (Dad, Mom) are removed from the maps; the function behind "Birk sagt
  immer…" no longer has Dad in its name. `5b3acc2d2f`, `c6f9c36648`
  (O-030)

### Hoenn and Pokemon (D-026, D-037, D-040, D-049)

- Lilycove City (Seegrasulb City) department store: Hoenn has its own
  daily lottery ticket, one a day there and one in Goldenrod's Radio
  Tower, with different draws; an unclaimed prize stays in its region.
  `43354ff84b` (S-03)
- Jirachi has a source again: HnS's event from its retired Mt. Moon
  outside map is on Route 4 by the Mt. Moon Pokemon Center (the small
  white rock at (7,4), at night, once, after the first trip to Hoenn);
  Jirachi at level 80 follows the legendary rules. `4c8c287df6` (S-12,
  A69)
- Mauville City's (Malvenfroh City's) mart and the left clerk on Lilycove
  department store 2F sell Water, Leaf, Moon, Thunder, Shiny and Dawn
  Stone for the Hoenn families; Lilycove also the Reaper Cloth, Deep Sea
  Tooth and Deep Sea Scale. `dc016bbc28` (S-10, A67)
- Recorded without a code change: Wallace (Wassili) gives no substitute
  if HM Waterfall came from Johto (S-06); Milotic only through beauty, no
  Prism Scale (S-11); Sinjoh and Alola stay locked (S-15); mythicals do
  not count for Pokedex completion; Bloodmoon Ursaluna as in HnS (S-13);
  every regional form that is an evolution is tied to a region, so all
  stay off and the owner decides case by case (S-14, O-045).
  `37ce3d37a5`, `f8e03c9a14`
- Region rule: off with any randomizer option, trainers or items alone
  included (Day Care eggs, the seen rule); the modifiers alone keep it.
  `6d8d9bcdfc` (O-033, option b)
- Recorded without a code change: the Pokedex's evolution page keeps
  naming later evolutions and babies, as a help (owner 2026-11-02, O-034).
- The nurse's Gold Card greeting and the Frontier Pass colour count the
  trainer card's stars (titles and Red). `1d8e2f2b80` (O-039, option a)

### Day Cares and Bill's PC (D-052)

- Kanto (Route 5), Johto (Route 34) and Hoenn (Route 117) each have their
  own Day Care: Pokemon and eggs left in one region stay there, and every
  step counts in all three. Save layout: SaveBlock3 grows from 1008 to
  1584 of 1624 bytes. `f1b7342466` (S-16, O-020)
- The storage is "Bills PC" from the start and in every region; "Jemandes
  PC" and Lanette's name no longer appear. `4fb0881c9a` (S-16, O-021)

### Battle and balance (D-053)

- Fixed, strong movesets for the scaled level of every boss: Johto (60
  bosses, 360 Pokemon), Hoenn (96 bosses, 498 Pokemon) and Kanto's league
  rematch teams after the Kanto title (38 Pokemon); in double and 2-vs-2
  battles no move that also hits the partner. `ad0c38ec25`, `4255412581`,
  `7e20415d95` (B-01, A20)
- Every trainer Pokemon knows only moves it can learn in this game: 244
  moves of 156 Pokemon replaced by similar learnable ones. `0d034edead`
  (B-02, A111)
- May (Maike) and Wally count as bosses (+1 on the ace). `293e135449`
  (B-06)
- Troy at Meteor Falls and Red on Mt. Silver are the last bosses of the
  story: six Pokemon each at level 100 with fixed movesets. `36760edbec`
  (B-10)
- Johto league: the levels rise from Will (Willi) to Lance (Siegfried) as
  in HGSS; for an average team Will 62, Koga 63, Bruno 64, Karen (Melanie)
  65 and Lance 67 instead of all at 65. `0e19260900` (B-05, A110)
- Badge counters count the badges of the current region: phone rematches,
  the battle requests of Hoenn's trainers, the Gen 9 catch malus, the
  challenge's trainer IV/EV tables and the continue window. In Johto and
  Hoenn the catch malus applies only above the map's corridor (mainly
  Raikou, Entei and Celebi before the eighth Johto badge, O-050).
  `3c8ec60228` (B-08)
- Four Johto trainers with fewer than three Pokemon are filled up (two
  collectors in the Radio Tower, the expert on the M.S. Aqua, Kimono Girl
  Zuki). `c1574fd6ce` (B-12)
- Kept and recorded: Kanto leaders' evolutions below their evolution
  level, legendaries in the scaling anchor, boss IVs, hard Hoenn
  corridors, Ariana's six entries in the 2-vs-2 battle, spread moves as in
  Gen 3, 50 % per target in doubles (B-03, B-04, B-07, B-09, B-11, B-13).
  `7e577dda7d`

### Nuzlocke, challenges and randomizer as in HnS (D-054)

- "Keine EVs" ends with the Nuzlocke at the first Hoenn title, as HnS ends
  both at its credits; the menu text says so. `a7d130039b` (N-03)
- Pokemon Center challenge: the beds of the S.S. Tidal and of the Weather
  Institute on Route 119 no longer heal either. `26a2666739` (N-04)
- Item randomizer: exchange menus give the item chosen (Cerulean's Berry
  Powder man, Route 113's Glass Workshop, Route 124's treasure hunter,
  Captain Stern's Scanner trade in Slateport's harbour); with a full bag
  Route 124 gives the shard back. `a8d021c844` (N-07)
- "Starter: Zufall" changes Elm's and Birch's starters too; when the
  preview shows another species than the ball's, Oak, Elm and Birch ask
  with its name. `953333a642`, `40ae485a0f` (N-08)
- Battles with an AI partner (Lance in the Rocket Hideout, Troy in the
  Space Center): as in HnS a Pokemon that faints there dies only if it is
  not healed before the end of the next battle; this takes back
  `d05aa4864f`. `b1f3d2734d`
- Recorded without a code change: no deaths in the Trainer Hills (O-028),
  Route 41's Tentacruel, hardcore, the dialogue around randomized gifts,
  no move reminder in Kanto, one Hall of Fame list; new open questions
  O-055 to O-058. `67f25ca805` (N-01, N-02, N-05, N-06, N-09, N-10)

### Debug menu (D-050, D-055, beta build only)

- Items of both states: every item the finished regions give, and once
  each what can be bought or got again (marts and their Premier Ball, Game
  Corner prizes, vending machines, merchants, Kurt, contest, lottery and
  phone gifts, Mom's purchases, berry trees, Rock Smash, trade items, in
  the Hoenn Test the Route 40 Trainer Hill's prizes); Goldenrod's mints
  only while the mints option sells them; what does not fit into a pocket
  goes into the PC's item storage (D-050, O-035). Items bought with Battle
  Points are open (O-060). `8eb46fd987`
- "Even Wild Slots" (overworld debug menu, "Flags & Vars"): while it is
  on, every slot of the current encounter table is equally likely (land,
  water, Rock Smash and Headbutt, each rod); off after a reset, nothing in
  the save (D-055). `a1509bd992`

### German texts (D-056, D-057)

- Common texts that the German build showed in English have a German
  branch now (the English one stays as `#else`), mostly from the official
  German Emerald: the move tutors of Emerald and HnS, the Safari Zone
  (Route 121, Johto's Safari Zone gate, Fuchsia City's entrance), the
  event-ticket sailors, the Blend Master, the Pokeblock feeder help
  windows of the Safari Zone gate, menu answers (Dewford's fisherman, the
  Trick House, Fortree, the Battle Tower), Pokeblock names and flavours,
  the PC wallpaper "Punkte", game names in two TV shows, "Lv." in the
  Pokedex move list, the battle tents (shown by the HnS copies at the
  Route 40 Trainer Hill), the Lilycove ladies, Cycling Road results and
  Fan Club ratings, party menu messages, the Dragon's Den answer, the easy
  chat keyboard and English words in German branches. `6ccc8f8ca8` to
  `66e606c02b`, `f1f2e8ff0c`
- Map texts: Mahogany Town (Mahagonia City, also Elm's call about the
  Radio Tower), the Radio Tower's top floor, the Goldenrod Underground
  switch room, the Safari Zone gate entrance, Union Cave 1F, the Moomoo
  Farm barn, the Mt. Silver Pokemon Center, the Day Care's party limit
  message, the "Raumfähre" sign in Pewter City's museum, the Poochyena on
  Route 114 and the HnS copy of Slateport's tent lobby at Route 40.
  `4ff756809d`, `01bbabf2ab`, `9a16d641a5`, `4efc5b011a`, `0b573ed13e`,
  `a3cbf5b4c2`, `04009d06e5`
- Five German map texts that wrote money with "$" were cut off there
  ("$" ends a string): Route 32, the Moomoo Farm, the Route 4 Pokemon
  Center, Pewter City's mart and the Route 34 Day Care. They use "¥" now,
  which the font shows as the Pokedollar sign. `102d5ed683`
- Left in English on purpose or unreachable: debug texts, strings marked
  unused, credits names, two unreferenced texts in Emerald's Slateport
  tent corridor (O-065; German since round 3, in Slateport's contest
  hall) and 28 trainer names in upstream capitals that no active script
  shows (O-066). `edae0ce493`, `b8391f20bb`

### Tests and tools

- New Origin Jade tests: `test/origin_jade/daycares.c` (three Day Cares,
  D-052), `test/origin_jade/even_wild_slots.c` (D-055) and
  `test/origin_jade/region_badges.c` (badges per region, D-053); more cases
  in `level_scaling.c` (Hoenn rival, Johto league rooms, corridor ceiling),
  `region_rule.c` (any randomizer option, modifiers alone) and
  `debug_states.c` (one item per purchase source, Goldenrod's mints).
  5148 tests, 0 new and 0 changed failures. `f1b7342466`, `a1509bd992`,
  `3c8ec60228`, `293e135449`, `0e19260900`, `6d8d9bcdfc`, `8eb46fd987`
- `tools/make_debug_states.py` puts every purchase and repeatable item of
  the finished regions into the debug states and checks the pocket sizes;
  `tools/check_regions.py` knows Jirachi on Route 4 as an exception.
  `8eb46fd987`, `4c8c287df6`

## Story packages of 2026-10-31

The owner's requirements of 2026-10-31: the Hoenn Ticket story (D-047),
Hoenn without a father (D-048), Pokemon per region (D-049) and two debug
states (D-050). All new German texts are drafts for the owner to review.

### The way to Hoenn: Hoenn Ticket and ports (D-047)

- After the Kanto title, every Johto title and the win over Red the player
  wakes up in their room in Pallet Town, also after a restart once the Hall
  of Fame has saved; before, Johto titles and Red continued in New Bark
  Town (Neuborkia). A whiteout from the room leads to Mom downstairs.
  `93ae559803`, `da69d2519c`
- Johto Hall of Fame: at the first Johto title Prof. Oak and an unknown man
  ("???", Troy) come in after the record. Troy asks Oak for an urgent talk
  in his lab and leaves; Oak asks the player to come to his lab at home.
  Title defences have no such scene. `56be2a1860`
- Oak's lab in Pallet Town: entering it after the first Johto title starts
  Troy's scene. Oak introduces Troy as the former champion of Hoenn and
  asks the player to travel there (Team Magma and Team Aqua are up to
  something); Troy hands over the Hoenn Ticket and leaves. With a full Key
  Items pocket he waits and hands it over when talked to. Saves already
  past the Johto title get the scene too. `59bd5a6e39`
- The Hoenn Ticket is a key item with a new description: it cannot be
  sold, tossed or stored, "Items: Zufall" does not replace it, and it stays
  in the bag after the crossing. `84e8dc6bb5`
- The ports of Vermilion City (Orania City) and Olivine City (Oliviana
  City) and the sailors at the Battle Frontier (Kampfzone) and on Birth
  Island list only where a ship goes now: "Hoenn" with the ticket until
  Birch's welcome in his lab (a one-way trip, every crossing lands on the
  Route 104 pier), "Graphitport City" and "Seegrasulb City" after the
  welcome once the town was visited. The Hoenn ferry leaves both ports at
  once, also before the M.S. Aqua's maiden voyage. The way back from Hoenn
  is Fly. `a18797946a` (changed in round 2: "Hoenn" stays until
  "Graphitport City" can be offered, `8a436c258b`)
- Olivine City port: Prof. Oak no longer waits there to see the player off,
  and Elm's (Lind's) text after the Johto title no longer sends the player
  there. `e8c6cc9b93`

### Hoenn: an unknown trainer, Norman is not the father (D-048)

- Using an item at the wrong place in Hoenn shows "Birk sagt immer…"
  instead of "Vati sagt immer…". `d27f2c12bd`
- At the first Hoenn title Prof. Birch names Norman instead of "your
  father". `1e2c25cad3`
- People in Hoenn know at most of a strong trainer from the mainland: May
  (Maike) on Route 103, Route 110 and in Lilycove City (Seegrasulb City),
  Birch's son, Sidney, Glacia, Drake, Scott's call after the Sootopolis
  badge and the man in Slateport's mart. Wallace's speech stays (Troy told
  him). `e6e74b3a85`, `af94011ea4`
- Mom's PokeCom calls follow the journey (Pallet Town in Kanto and Johto,
  Hoenn from the arrival, three leagues after the Hoenn title), and she is
  "Mama" everywhere. `5a0cfc67c1`, `7f3ae8b30f`
- Petalburg City (Blütenburg City): once the gym is open (fourth Hoenn
  badge, as before), five townspeople no longer talk of the rebuilding;
  Norman's PokeNav call after his defeat has a text of its own.
  `5ddcaaf6da`, `fd64cd265f`
- The PCs in Norman's son's room, in May's room and upstairs in the New
  Bark Town house show the Pokemon Trainer School e-mail, and the player's
  decorations are not set up in Littleroot Town; the player's bedroom PC
  is the one in Pallet Town. `ea9a0f7287`
- Emerald's scenes in which the player is Norman's child (moving in, Dad
  on TV, the new neighbours' greeting, Mom's Running Shoes, Birch's
  starter gift, Dad's PokeNav call, the S.S. Ticket after the title,
  Brendan's Go-Goggles line, Mom after the wall clock) are no longer built;
  they were unreachable in a normal game (Mom after the wall clock only on
  saves without a set clock). The unused berry texts name Norman.
  `40102c8756`, `7d5e1d669e`, `d5542f3a39`, `3b20fb905a`, `fe370081c1`,
  `68df18a8b8`, `d38acf1988`
- English branches (not shown in the German build) no longer call Norman
  "DAD". `1c7b9f82a6`

### Pokemon per region (D-049)

- Every species belongs to a region: Kanto 151, Johto 129, Hoenn 142;
  babies and later evolutions of Kanto and Johto lines count to Johto,
  those of Hoenn lines to Hoenn. Johto is unlocked on the first Johto map
  after the Kanto title, Hoenn with the first crossing. Before that no
  source hands out a species of the region; evolutions are exempt.
  `58e89bd76b`
- Cerulean Cave: Ditto instead of Wobbuffet. `66a9a36a4c`
- Ecruteak City (Teak City) gym: Morty's (Jens') first team has a second
  Misdreavus instead of Duskull. `16eb7f6e2e`
- Olivine City: the Aurora Ticket (Deoxys) only after the first trip to
  Hoenn. `d0f6521cf6`
- "Items: Zufall" no longer rolls the Root and Claw Fossil. `42e8c25c46`
- Day Care: an egg of a region that is not unlocked yet hatches as the
  first unlocked stage (Pikachu instead of Pichu in Kanto, Marill instead
  of Azurill in Johto); not with a randomizer option that changes the
  player's species (O-033; since round 2 with any randomizer option,
  `6d8d9bcdfc`). `8fcbb1acc0`
- Pokedex: a Pokemon of a locked region that a trainer sends out is
  registered as seen only once the region is unlocked or the species was
  caught, so the National Pokedex list no longer jumps into a later block.
  `f37a68c419`
- Kanto Pokedex: Oak's rating, his aides' gifts and the game designer in
  Celadon City count the 151; Oak calls the Pokedex complete with all 151
  but Mew (he never did before), and the Celadon diploma names the Kanto
  Pokedex. `756563f7d7`, `26979b66fe`
- Johto Pokedex: Elm's and Birch's rating, Lilycove's diploma and the star
  count behind the nurse's Gold Card greeting no longer need Azurill and
  Wynaut, so the Johto Pokedex can be completed before Hoenn. The trainer
  card's stars count titles and Red, not the Pokedex (D-049 corrected).
  `58f244eade`, `2f4f6ccede`; the English rating text ends correctly
  (not shown in the German build) `e6466779e5`. Since round 2 the Gold
  Card greeting counts the trainer card's stars (`1d8e2f2b80`).

### Debug states (D-050, beta build only)

- "Johto Test" (overworld debug menu, new game before the first Pokemon):
  Kanto right after its first Hall of Fame, the Pokedex of all Kanto lines
  (185), in party and PC only the 81 final stages, Oak waits with the GS
  Ball, Johto and Hoenn locked; the player wakes up in the room.
  `ae3e095a3c`
- "Hoenn Test": Kanto and Johto done by a completionist (story, badges and
  permits, league, Red, one-time encounters, every item ball and hidden
  item, Pokedex 282, the 142 final stages; team Charizard 70, Meganium 63,
  Gyarados 63, Ampharos 62, Nidoking 60, Espeon 60). It starts at the door
  of Oak's lab, where Troy's scene runs, and replaces the hand-written
  Hoenn quick start. `13bf3c8cb6`
- Round 2 adds the purchases to the items of both states and the switch
  "Even Wild Slots" (see above).

## Kanto

- Celadon City (Prismania City): all eleven warps lie on doors again; the
  Game Corner, prize room, restaurant and hotel can be entered, so the main
  path after the fourth badge (Rocket Hideout, Silph Scope, Poke Flute) is
  open again. `bf4d84843d`
- Route 8: the gatehouse to Saffron City can be entered from the west.
  `75c85591c8`
- Mt. Moon B3F: the way to Mew's chamber is walkable (door tile without
  collision, landing from the water onto the south shore). `49aa20ab68`
- Route 2 east gatehouse (north door), the Power Plant back door on Route 10
  and the Mt. Moon B2F ladder to B1F work in both directions. `2df90d157b`
- Lavender Town Pokemon Center 2F uses the upstairs layout instead of a copy
  of the ground floor. `0124707dc7`
- Route 9: the item ball with TM40 (Aerial Ace) lies on a reachable tile.
  `0dacb0557a`
- Pewter City (Marmoria City): the Running Shoes triggers at the east exit
  run at most once after Brock instead of on every pass. `e3dcdf00eb`
- Kanto Safari Zone: the border blocks of the four areas show the right
  tiles again. `cbb0a9a2ca`
- Routes 10, 17 and 19: Origin Jade's map edits lost in the HnS merge are
  back (sign and hidden item collision, sea instead of the dead HnS island
  on Route 19). `425eb2fbb1`
- Three hidden items can be found again: Rare Candy in Cerulean City, Persim
  Berry on Route 3, Moon Stone in Mt. Moon B2F. `6faac92fe4`
- Victory Road 2F: the Potion lies on a reachable tile (44,11). `fc4265e4bf`
- After a whiteout at home, Mom names Prof. Oak instead of Prof. Birch.
  `22adbd2c6d`
- Cerulean City: the badge explainer gives Origin Jade's obedience limits
  (2/4/6/8 badges: level 20/30/40/50). `6fa1cfe509`
- Cinnabar Lab: the Dome Fossil can be revived after the Helix Fossil and
  the Old Amber; a fossil already revived in the Ruins of Alph lab is no
  longer offered a second time. `df6c6afbdc`
- Cerulean City: the Berry Powder man checks for berries in the bag, so the
  Powder Jar can be obtained; his exchange text fits the box with long item
  names. `605046006a`, `08e3149815`
- Viridian City: the tutorial old man no longer asks about Teachy TV, which
  Origin Jade does not have. `e29aa5d3f2`
- Pallet Town: Daisy's (Sarah's) farewell text is not repeated after the
  Pokedex scene. `15b545ea9a`
- Fuchsia City zoo: the fossil sign always shows Omanyte, like the
  enclosure. `6518eabf61`
- Magnet Train: after arriving in Saffron City or Goldenrod City the player
  no longer ends up on the conductor's tile. `ffbdea3d0d`
- Bulbasaur (Viridian Forest), Charmander (Mt. Moon 1F) and Squirtle
  (Route 24) are wild at 5 % at night too. `51b8d58b8c`
- The gate south of Route 23 lets the player pass to Johto only after
  picking up the GS Ball from Prof. Oak. `ae4b56e8e8`

## Johto

- The GS Ball is a key item: it cannot be sold, tossed, stored or thrown;
  the Ilex Forest (Steineichenwald) shrine starts the Celebi event only with
  the GS Ball in the bag. Celebi has to be caught with normal balls.
  `28cbfca6b4`
- Ecruteak City (Teak City) theater: its state only moves forward, so the
  league change after the legendary event can no longer be lost.
  `80b60b17ac`
- Azalea Town no longer takes away HM Surf from Kanto. The theater's Surf
  gentleman gives HM Surf, or Mystic Water to a player who already has it,
  and no longer both when the bag is full (the Mystic Water is still lost
  then, see `BETA_READINESS.md`). `89f7c83d03`
- Prof. Elm's (Lind's) lab: the PokeCom's "Zustand" entry is unlocked also
  when the player talks to Elm from the left. `4d8cf66d21`
- Mr. Pokemon's house: the Red Scale is no longer lost with a full bag.
  `35b99a0b2a`
- Battle Frontier (Kampfzone): Sudowoodo stands on a reachable tile and can
  be woken with the SquirtBottle (level 65). `bf713b3067`, `c16463afb7`
- Route 36: the SquirtBottle question fits the text box. `89d8e2c60d`
- Rematch tiers, Red on Mt. Silver and the Pyramid King carry German names.
  `030660c91d`
- Rocket Hideout B2F: the double battle with Lance (Siegfried) uses German
  defeat texts. `a142e01c51`
- Radio Tower: winning the radio quiz no longer sets Goldenrod City's
  (Dukatia City's) state back (music, Radio Tower NPCs). `ecba0eaa87`
- Goldenrod City flower shop: the mint seller speaks German before the
  third Johto badge. `cd86b6c21a`
- Ilex Forest: the charcoal master no longer sets Azalea Town back (a
  defeated Celebi could not return, Kurt repeated the GS Ball scene).
  `63f7024435`
- New Bark Town (Neuborkia): entering the house that is the player's home
  in HnS (a stranger's house in Origin Jade) no longer brings back the
  battling Youngster on Route 30. `7e3c346926`
- Blackthorn City (Ebenholz City) gym: Clair (Sandra) does not battle a
  second time after the Dragon's Den shrine. `896c802fac`
- Tin Tower and Whirl Islands: the Kimono Girl's text after a battle
  without a catch no longer says "caught". `9df1dfe85a`
- Lugia and Ho-Oh: no "flew away!" after a knockout. `ffe4fc5792`
- The Kimono Girls' dance runs once per visit. `b702b50666`
- Ilex Forest: a loss against Celebi leaves no stray Celebi or Kurt in the
  forest. `ac408421ec`
- Prof. Elm recognizes the Pokemon hatched from the Violet City egg also
  with the fixed-Pokemon randomizer and when it is in the PC. `e30f4f495e`
- Trainer Hill by Route 40: the prize money is paid only together with the
  prize (with a full bag it was paid on every talk). `2d84ddaa50`
- Battle Frontier and Trainer Hill no longer draw the disabled Regieleki and
  Regidrago (empty Pokemon or crash screen before). `d0324da2bf`
- Chikorita (Ilex Forest), Cyndaquil (Route 31) and Totodile (Route 32) are
  wild at 5 %, day and night, each with an overworld Pokemon. `ecf36a7f03`
- Routes 26 and 27: the overworld Pokemon show species that can be caught
  there instead of starters. `8167ea7bc6`

## Hoenn

Hoenn is reached by ship with the Hoenn Ticket, which Troy hands over in
Oak's lab after the first Johto title (D-047, see the story packages
above).

- Later ship trips to Hoenn no longer reset Hoenn's story (Petalburg gym
  softlock, Mossdeep Space Center battle, Mr. Briney, repeated arrival
  scenes, the second desert fossil). `ffa85af6e0`
- Until Prof. Birch's welcome every "Hoenn" trip lands on the Route 104
  pier. After the welcome the port menus offer "Graphitport City"
  (Slateport City; once it was visited, not while the Team Aqua submarine
  scene is pending) and "Seegrasulb City" (Lilycove City; once it was
  visited), and the ships land in their harbors. `a18797946a`; before,
  later trips docked in Slateport City's harbor on their own once it was
  visited (`ffa85af6e0`, `2c6403fa2d`). Since round 2 "Hoenn" stays until
  "Graphitport City" is offered, and later "Hoenn" trips land at the pier
  without Birch's greeting (`8a436c258b`).
- Every trip sets the respawn point in Hoenn; Prof. Birch's welcome is
  caught up in his lab if the player left the beach before it.
  `84a564e935`
- After the Hoenn title there is no S.S. Ticket scene in Littleroot Town
  (Wurzelheim) and no "national mode" scene with Birch and May.
  `f85a38c16f`, `a242593207`
- May's music also plays for female players. `97954fcd88`
- Flying to the Pokemon League lands in front of the league building in
  Ever Grande City (Prachtpolis City). `638ad542b2`
- Lilycove City contest lobby: the girl recognizes the Pokeblock Case.
  `3c4a70b8d1` (since round 3 she only gives her Pokeblock tip, and the
  case comes from Slateport's contest lobby, D-058)
- Johto progress no longer changes Hoenn dialogs: Wally's parents (Surf),
  the Rock Smash man, the fossil maniac and the Strength flag of the Rusturf
  Tunnel have Hoenn flags of their own; Johto's HMs Strength and Flash stay
  obtainable after Hoenn. `38cea6c78f`, `99406ad67c`, `24f9f86e81`
- Hoenn Safari Zone: own state; time up, no balls left or quitting lead back
  to the entrance on Route 121. `df79e21ae3`
- Trainer Hill on Route 111 works with Emerald's trainers and floors (it had
  empty floors), with records of its own. `0b265d9f0f` (retired in round
  3 by the owner's decision, `61ac7e277d`, D-044)
- Meditite (Mt. Chimney) and Medicham (Victory Road) are wild again.
  `548c6a1eb1`
- Treecko, Torchic and Mudkip are wild at 5 % instead of 1 %. `dc7c95072c`
- Sootopolis City (Xeneroville): Wallace (Wassili) gives HM Waterfall if the
  player does not have it; before, Ever Grande City needed the optional item
  ball in Johto's Ice Path. `52695b73f8`
- Weather Institute: the weather report names the right Hoenn route.
  `66c8c9114f`
- The abnormal weather ends on its Hoenn route; Johto Routes 38, 47 and 48
  no longer get Hoenn tiles. `d30437a99d`
- Petalburg City (Blütenburg City): the gym boy's scene runs once; the
  closed gym can be left with one to three badges. `eb6b5a1a66`,
  `601bf4bb9a`
- Mauville City (Malvenfroh City): after the battle, Wally no longer stands
  in Petalburg City for the catching tutorial. `5eb145e6a7`
- Littleroot Town: the townsperson with the PC hint is visible.
  `63e06c1ef7`
- Norman's call about the gym opening rings only in Hoenn. `488df2564a`
- Rustboro City (Metarost City): the Cutter's house finishes its dialog
  (new German line about the Stone Badge). `7192e23ba7`

## Challenges

### Nuzlocke

- The Nuzlocke ends at the first Hoenn title instead of at Red (O-025, owner
  to confirm). `130c5adb25`
- Battles without a chance to catch (Route 41 guards, ghosts without the
  Silph Scope) do not use up the area. `1d8451f15c`
- Shiny clause: a shiny first encounter does not use up the area.
  `ac46dd2994`
- Pokemon that faint in double battles with a computer-controlled partner
  (Lance, Steven) die like in other battles. `d05aa4864f` (taken back on
  2026-11-02: as in HnS, they die only if they are not healed before the
  next battle, D-054)
- A whiteout no longer overwrites eggs in the party. `df06d73321`
- Scripted static encounters (Snorlax, Sudowoodo, Lapras, Electrode,
  Voltorb, Kecleon) are free and can always be caught. `321f7eb411`
- Eggs always hatch and use up no area. `dbb71e3ec6`
- Nickname rule for gifts: Kanto gifts, the Kanto starter, the Johto starter
  in the PC, Goldenrod prize Pokemon, Anorith, Bill's Eevee, the Dragon's
  Den Dratini and Hoenn's gift Pokemon. `ee688ea031`, `de88177172`,
  `2077bf9dbe`, `551f9a1327`, `ed568069c4`

### Randomizer

- "Items: Zufall" works from the first starter on, also in Kanto; gift
  messages name the item actually received. `28158c0e9d`
- Hidden items are randomized one by one (several of one kind on a map no
  longer turn into the same item). `013fb23c59`
- Fossils and evolution items stay in place. `d989ed8f85`
- "Trainer: Zufall" seeds per trainer instead of per trainer class.
  `8d16c9177e`
- "Feste PKMN": the exceptions the menu promises hold, a soft reset no
  longer rerolls gifts, and Oak's starter is the one the preview showed.
  `69bf221161`
- Only gift eggs are randomized; Day Care eggs hatch as the parents'
  species. `93f7a7c67a`
- The HM fallback (the HM in the bag is enough) also works with every
  species randomizer. `998ceca95f`

### Challenge menu

- Level caps in Kanto follow the level ladder (Normal: next leader's ace;
  Hard: next leader's lowest level). `cc1c3ed002`
- "Super teuer!": items sell for their base price again. `6355102c85`
- "Weniger Flucht": the escape chance depends on speed instead of a flat
  50 %. `2d0444d19c`
- The random number generator is seeded only when a new game starts, not on
  every save in the menu. `0b35c1bde2`
- The one-type challenge is off by default. `5ee30d9a40`
- "Natur-Minzen: Aus": the mints are sold after the first Hoenn title, as
  the menu says. `a1d638b38f`
- The "Legendäre" row can only be chosen with "Ausgleich: Aus", where it has
  an effect. `d4770f4d8f`
- Menu descriptions match what the options do (clock speed, EXP, IVs, EVs,
  Pokemon Center, hardcore Nuzlocke). `a6bb899765`

## Battle and balance

- The battle partners are named Troy (Steven) and Siegfried (Lance) and
  scale to the player's level. `4df138907f`, `2353317f2f`
- HnS's female gym leaders, Elite Four members and Kimono Girls are female
  trainers (affects their Pokemon's natures). `167979e1c0`
- Goldenrod City and Ecruteak City keep a level ceiling of 53 until their
  story turn. `22896141f1`
- Johto phone rematches have at least three Pokemon. `9cd7d8f439`

## Saves and technical

- All Halls of Fame (Kanto, Johto, Hoenn and the PC view) hold 50 teams.
  `cd155adc3d`
- New game: if the cartridge clock does not run, the fake clock is
  preselected in the challenge menu. `5e1b5f870d`
- Debug menus are on in the beta build (`make`) and off in `make release`.
  `be6aabb11a`
- Only Origin Jade is built: `make`, `make check`, `make release` and
  `make debug` build Jade (`Pokemon_Origin_Jade.gba`, the release build
  `Pokemon_Origin_Jade-release.gba`); `make jade` stays as an alias.
  `dca90ec7e8`
- `make clean` removes the Jade ROM and every build directory.
  `51e8c2d135`
- `INSTALL.md` builds with `make`. `8e41cc9191`
- One CI workflow for Jade (build, release build, checks) replaces the
  upstream jobs. `c64f0a28dd`
- Save layout: SaveBlock3 grows from 992 to 1008 bytes (records of the Route
  111 Trainer Hill, unused since round 3, the layout stays); build-time
  guards for the save layout and the trainer flag window. `0b265d9f0f`,
  `78aa81bd8e`, `ed9d3eaf11`

## Tools and tests

- `tools/check_maps.py`: static check of all active maps. `bbe30578ea` and
  six follow-ups up to `63ef906433`
- `tools/simulate_progress.py` with the data layer `tools/oj_world.py`:
  static playthrough model Kanto -> Johto -> Hoenn. `8dede143ee`,
  `c415155a59`
- `tools/check_game_text.py`: game text widths in the sources and English
  leftovers. `a81e0f6dad`, `e847161c54`, `b887df3606`
- `tools/check_text_width.py`: line widths in the built ROM. `e348ff39bb`
- `tools/check_save_safety.py`: gifts, bag pockets, new game, migrations,
  Hall of Fame, clock and link features. `9ea6ff6d2d`, `46be3a9de6`
- `tools/check_budget.py` (save and memory budget) and
  `tools/check_warnings.py` (compiler warnings against a baseline).
  `fd95e149f0`, `6586e2c42a`
- `check_merge.py` without false alarms, known cases with a reason;
  `check_pokenav_text.py` reads the glyph widths from index 0;
  `tools/make_kanto_complete.py` no longer reports Pikachu PhD as
  missing. `2174699385`, `5ebf0cb597`, `6b20e81d4a`
- Test suite: the test runner builds again, tests start like a new game,
  Origin Jade tests for level scaling and flag/var routing, save size
  tests, and `tools/run_tests.py` with a baseline of known failures.
  `c68220b18f`, `a0e623d5ea`, `17cb0ed51e`, `78aa81bd8e`, `631abb6cca`,
  `c441d676ef`
- `tools/check_regions.py`: no wild table, overworld Pokemon, gift or
  static battle of an active map offers a species of a later region, and
  the National Pokedex order cannot jump into a later block (`--dex-gaps`);
  part of the CI. `bb850c8d7c`
- `tools/simulate_progress.py` and `tools/check_save_safety.py` know
  `giveitem_norandom`; the simulator reaches the Hoenn title without
  `--hoenn-ticket`. `e505824673`
- `tools/make_debug_states.py` (was `make_kanto_complete.py`) generates
  both debug states; `--check` (CI) also fails on a Kanto or Johto story
  flag or var that is neither in a state nor listed with a reason.
  `0ab7449520`, `ae3e095a3c`, `13bf3c8cb6`
- Origin Jade tests for the region rule (`test/origin_jade/region_rule.c`)
  and the debug states (`test/origin_jade/debug_states.c`); two upstream
  Day Care tests that expect a Pichu egg are known failures now (D-049).
  `58e89bd76b` and the following region commits, `b022af5623`

## Known open points

`docs/origin_jade/BETA_READINESS.md` lists everything that is still open,
with evidence and the owner decisions it needs. The most important:

- The new German texts are drafts for the owner's text round: the scenes
  of the story packages (D-047, D-048), the translations of round 2 that
  are not from an official German game (D-056, D-057) and the new lines
  of round 3 (Scott in Slateport, O-070; the Route 121 Safari Zone desk).
- Open questions of round 2: the continue point in the bedroom (O-041),
  regional forms case by case (O-045), the catch malus levels in Johto
  and Hoenn (O-050), Nuzlocke rules that differ from HnS (O-055), move
  tutors in Kanto (O-056), item randomizer leftovers (O-057), the
  randomizer species pool (O-058), Battle Point items in the Hoenn Test
  (O-060) and trainer names in upstream capitals (O-066). Round 3 resolved
  O-024, O-063, O-065 and O-067. Older ones still open: O-022, O-025,
  O-037, O-038, O-040.
- Open questions of round 3: the rank per contest hall (O-068), paintings
  per rank (O-069), Scott's new line in Slateport (O-070), Scott's two
  tent meetings that went with the tents (O-073) and 21 TMs of HnS's old
  Kanto without a source (O-074).
- Nothing of rounds 2 and 3 was played in an emulator; `BETA_READINESS.md`
  lists what to test first, among it one pass through each contest hall.
