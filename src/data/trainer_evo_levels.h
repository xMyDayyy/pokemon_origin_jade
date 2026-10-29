// Levels from which scaled trainer Pokemon (src/level_scaling.c) take a stone, trade or
// condition-only evolution into the species. Unlisted species use *_SCALING_EVO_OTHER_LEVEL.
// Each level L is the lowest level at which HnS 2.0.5's trainers field the species (or a
// later stage) such that, among all their Pokemon at L or higher, it outnumbers its
// pre-evolution (else the lowest level they field it). The comment gives those counts and
// the lowest level any HnS trainer fields the species or a later stage.
// Regenerate (overwrites edits): python3 -I tools/make_trainer_evo_levels.py --header > src/data/trainer_evo_levels.h
static const struct TrainerEvoLevel sTrainerEvoLevels[] =
{
    {SPECIES_PIKACHU,                    15}, // majority from 15: 20 Pikachu/Raichu vs 0 Pichu at >= 15; lowest 15 William (Raichu)
    {SPECIES_RAICHU,                     28}, // majority from 28: 8 Raichu vs 7 Pikachu at >= 28; lowest 15 William
    {SPECIES_NIDOQUEEN,                  20}, // majority from 20: 15 Nidoqueen vs 1 Nidorina at >= 20; lowest 20 Miller
    {SPECIES_NIDOKING,                   20}, // majority from 20: 15 Nidoking vs 2 Nidorino at >= 20; lowest 20 Miller
    {SPECIES_CLEFAIRY,                   18}, // majority from 18: 9 Clefairy/Clefable vs 0 Cleffa at >= 18; lowest 18 Ann_And_Anne
    {SPECIES_CLEFABLE,                   29}, // majority from 29: 4 Clefable vs 2 Clefairy at >= 29; lowest 29 Tiffany_3
    {SPECIES_NINETALES,                  27}, // majority from 27: 3 Ninetales vs 0 Vulpix at >= 27; lowest 27 Lois
    {SPECIES_JIGGLYPUFF,                 24}, // majority from 24: 5 Jigglypuff/Wigglytuff vs 0 Igglybuff at >= 24; lowest 24 Tiffany (Wigglytuff)
    {SPECIES_WIGGLYTUFF,                 24}, // majority from 24: 4 Wigglytuff vs 1 Jigglypuff at >= 24; lowest 24 Tiffany
    {SPECIES_VILEPLUME,                  30}, // majority from 30: 14 Vileplume vs 2 Gloom at >= 30; lowest 30 Ariana_1
    {SPECIES_ARCANINE,                   32}, // majority from 32: 7 Arcanine vs 1 Growlithe at >= 32; lowest 32 Alan_3
    {SPECIES_POLIWRATH,                  31}, // majority from 31: 18 Poliwrath vs 4 Poliwhirl at >= 31; lowest 31 Chuck_1
    {SPECIES_ALAKAZAM,                   45}, // majority from 45: 5 Alakazam vs 0 Kadabra at >= 45; lowest 45 Jake
    {SPECIES_MACHAMP,                    38}, // majority from 38: 13 Machamp vs 5 Machoke at >= 38; lowest 38 Kenji
    {SPECIES_VICTREEBEL,                 34}, // majority from 34: 17 Victreebel vs 0 Weepinbell at >= 34; lowest 34 Liz_4
    {SPECIES_GOLEM,                      38}, // majority from 38: 22 Golem vs 3 Graveler at >= 38; lowest 38 Erik
    {SPECIES_CLOYSTER,                   26}, // majority from 26: 14 Cloyster vs 4 Shellder at >= 26; lowest 26 Charlie
    {SPECIES_GENGAR,                     25}, // majority from 25: 8 Gengar vs 1 Haunter at >= 25; lowest 25 Morty_1
    {SPECIES_EXEGGUTOR,                  35}, // majority from 35: 10 Exeggutor vs 0 Exeggcute at >= 35; lowest 35 Grunt_9
    {SPECIES_CHANSEY,                    53}, // majority from 53: 2 Chansey/Blissey vs 0 Happiny at >= 53; lowest 53 Brent_4
    {SPECIES_STARMIE,                    25}, // majority from 25: 17 Starmie vs 2 Staryu at >= 25; lowest 25 Elaine
    {SPECIES_MR_MIME,                    22}, // majority from 22: 11 Mr Mime vs 0 Mime Jr at >= 22; lowest 22 Chad
    {SPECIES_VAPOREON,                   24}, // majority from 24: 8 Vaporeon vs 1 Eevee at >= 24; lowest 24 Gwen
    {SPECIES_JOLTEON,                    25}, // majority from 25: 5 Jolteon vs 1 Eevee at >= 25; lowest 25 Gwen
    {SPECIES_FLAREON,                    23}, // majority from 23: 8 Flareon vs 1 Eevee at >= 23; lowest 23 Gwen
    {SPECIES_SNORLAX,                    77}, // majority from 77: 2 Snorlax vs 0 Munchlax at >= 77; lowest 77 Red
    {SPECIES_CROBAT,                     52}, // majority from 52: 14 Crobat vs 0 Golbat at >= 52; lowest 52 Koga_1
    {SPECIES_TOGETIC,                    37}, // majority from 37: 3 Togetic/Togekiss vs 0 Togepi at >= 37; lowest 37 Kelly
    {SPECIES_BELLOSSOM,                  37}, // majority from 37: 6 Bellossom vs 0 Gloom at >= 37; lowest 37 Cybil
    {SPECIES_MARILL,                      7}, // majority from 7: 10 Marill/Azumarill vs 0 Azurill at >= 7; lowest 7 Henry
    {SPECIES_SUDOWOODO,                  30}, // majority from 30: 3 Sudowoodo vs 0 Bonsly at >= 30; lowest 30 Chuck_1
    {SPECIES_POLITOED,                   38}, // majority from 38: 5 Politoed vs 3 Poliwhirl at >= 38; lowest 27 Eusine
    {SPECIES_SUNFLORA,                   16}, // majority from 16: 6 Sunflora vs 1 Sunkern at >= 16; lowest 16 Jack
    {SPECIES_ESPEON,                     45}, // majority from 45: 7 Espeon vs 0 Eevee at >= 45; lowest 45 Richard
    {SPECIES_UMBREON,                    20}, // majority from 20: 5 Umbreon vs 1 Eevee at >= 20; lowest 20 Jamie
    {SPECIES_SLOWKING,                   45}, // majority from 45: 6 Slowking vs 0 Slowpoke at >= 45; lowest 45 Richard
    {SPECIES_STEELIX,                    33}, // majority from 33: 16 Steelix vs 2 Onix at >= 33; lowest 33 Kenji
    {SPECIES_SCIZOR,                     36}, // majority from 36: 13 Scizor vs 4 Scyther at >= 36; lowest 36 Jasmine_1
    {SPECIES_MANTINE,                    42}, // majority from 42: 6 Mantine vs 0 Mantyke at >= 42; lowest 42 Lola
    {SPECIES_KINGDRA,                    45}, // majority from 45: 8 Kingdra vs 4 Seadra at >= 45; lowest 45 Clair_1
    {SPECIES_PORYGON2,                   39}, // majority from 39: 4 Porygon2/Porygon Z vs 3 Porygon at >= 39; lowest 39 Archer (Porygon Z)
    {SPECIES_BLISSEY,                    63}, // majority from 63: 1 Blissey vs 0 Chansey at >= 63; lowest 63 Whitney_2
    {SPECIES_LUDICOLO,                   63}, // majority from 63: 2 Ludicolo vs 0 Lombre at >= 63; lowest 63 Akala_Picnicker
    {SPECIES_DELCATTY,                   64}, // majority from 64: 2 Delcatty vs 0 Skitty at >= 64; lowest 64 Whitney_2
    {SPECIES_ROSELIA,                    60}, // majority from 60: 4 Roselia/Roserade vs 0 Budew at >= 60; lowest 60 Joel_2
    {SPECIES_MILOTIC,                    61}, // majority from 61: 3 Milotic vs 0 Feebas at >= 61; lowest 61 Misty
    {SPECIES_HUNTAIL,                    68}, // majority from 68: 2 Huntail vs 0 Clamperl at >= 68; lowest 68 Melemele_Swimmer_2
    {SPECIES_GOREBYSS,                   63}, // majority from 63: 1 Gorebyss vs 0 Clamperl at >= 63; lowest 63 Poni_Swimmer_1
    {SPECIES_ROSERADE,                   60}, // majority from 60: 3 Roserade vs 1 Roselia at >= 60; lowest 60 Erika
    {SPECIES_AMBIPOM,                    64}, // majority from 64: 2 Ambipom vs 0 Aipom at >= 64; lowest 64 Trevor_3
    {SPECIES_MISMAGIUS,                  63}, // majority from 63: 2 Mismagius vs 0 Misdreavus at >= 63; lowest 63 Morty_2
    {SPECIES_HONCHKROW,                  53}, // majority from 53: 6 Honchkrow vs 3 Murkrow at >= 53; lowest 53 Karen_1
    {SPECIES_WEAVILE,                    64}, // majority from 64: 4 Weavile vs 0 Sneasel at >= 64; lowest 64 Pryce_2
    {SPECIES_MAGNEZONE,                  59}, // majority from 59: 3 Magnezone vs 0 Magneton at >= 59; lowest 37 Jasmine_1_3
    {SPECIES_LICKILICKY,                 65}, // majority from 65: 1 Lickilicky vs 0 Lickitung at >= 65; lowest 65 Whitney_2
    {SPECIES_RHYPERIOR,                  69}, // majority from 69: 2 Rhyperior vs 0 Rhydon at >= 69; lowest 69 Blue
    {SPECIES_TANGROWTH,                  60}, // majority from 60: 4 Tangrowth vs 3 Tangela at >= 60; lowest 60 Erika
    {SPECIES_ELECTIVIRE,                 59}, // majority from 59: 4 Electivire vs 2 Electabuzz at >= 59; lowest 59 Ltsurge
    {SPECIES_MAGMORTAR,                  62}, // majority from 62: 3 Magmortar vs 2 Magmar at >= 62; lowest 62 Joel_3
    {SPECIES_TOGEKISS,                   62}, // majority from 62: 1 Togekiss vs 0 Togetic at >= 62; lowest 62 Joel_3
    {SPECIES_YANMEGA,                    63}, // majority from 63: 2 Yanmega vs 0 Yanma at >= 63; lowest 63 Bugsy_2
    {SPECIES_LEAFEON,                    63}, // majority from 63: 2 Leafeon vs 0 Eevee at >= 63; lowest 63 Ulaula_Youngster
    {SPECIES_GLACEON,                    70}, // majority from 70: 1 Glaceon vs 0 Eevee at >= 70; lowest 70 Youko
    {SPECIES_GLISCOR,                    70}, // majority from 70: 2 Gliscor vs 0 Gligar at >= 70; lowest 70 Skylar
    {SPECIES_MAMOSWINE,                  65}, // majority from 65: 2 Mamoswine vs 0 Piloswine at >= 65; lowest 38 Pryce_1_3
    {SPECIES_PORYGON_Z,                  39}, // no majority (1 Porygon Z vs 3 Porygon2 at >= 39), so lowest 39 Archer
    {SPECIES_GALLADE,                    55}, // majority from 55: 1 Gallade vs 0 Kirlia at >= 55; lowest 55 Alex_3
    {SPECIES_DUSKNOIR,                   65}, // majority from 65: 2 Dusknoir vs 0 Dusclops at >= 65; lowest 65 Morty_2
    {SPECIES_FROSLASS,                   64}, // majority from 64: 2 Froslass vs 0 Snorunt at >= 64; lowest 64 Pryce_2
    {SPECIES_SYLVEON,                    70}, // majority from 70: 1 Sylveon vs 0 Eevee at >= 70; lowest 70 Shizuko
    {SPECIES_WYRDEER,                    63}, // majority from 63: 2 Wyrdeer vs 0 Stantler at >= 63; lowest 63 Morty_2
    {SPECIES_KLEAVOR,                    66}, // majority from 66: 3 Kleavor vs 1 Scyther at >= 66; lowest 66 Brock
    {SPECIES_URSALUNA,                   60}, // majority from 60: 1 Ursaluna vs 0 Ursaring at >= 60; lowest 60 Giovanni
    {SPECIES_ANNIHILAPE,                 64}, // majority from 64: 2 Annihilape vs 1 Primeape at >= 64; lowest 37 Chuck_1_3
    {SPECIES_DUDUNSPARCE_TWO_SEGMENT,    27}, // majority from 27: 4 Dudunsparce Two Segment vs 0 Dunsparce at >= 27; lowest 27 Devin
};

// Not fielded by HnS's trainers, so *_SCALING_EVO_OTHER_LEVEL:
// SPECIES_SHIFTRY SPECIES_CHIMECHO SPECIES_PROBOPASS SPECIES_FARIGIRAF

// Never picked (sTrainerEvoExcluded in src/level_scaling.c):
// SPECIES_DUDUNSPARCE_THREE_SEGMENT SPECIES_URSALUNA_BLOODMOON
