#ifndef GUARD_CONFIG_HOENN_SCALING_H
#define GUARD_CONFIG_HOENN_SCALING_H

// =====================================================================
// Hoenn level scaling: trainers and wild Pokémon scale with the player's
// anchor (mean of the three highest party levels, at most
// SCALING_ANCHOR_MAX_DROP below the highest, include/level_scaling.h),
// clamped to a corridor per area. Bosses (leaders, Elite Four, champion,
// Magma/Aqua bosses and admins) get HOENN_SCALING_BOSS_EXTRA on top.
// Johto: config/johto_scaling.h, Kanto: config/kanto_scaling.h.
// =====================================================================

#define HOENN_LEVEL_SCALING          TRUE  // master switch

#define HOENN_SCALING_TRAINER_BELOW  5     // Trainer band: anchor - 5 ...
#define HOENN_SCALING_TRAINER_ABOVE  0     // ... up to the anchor
#define HOENN_SCALING_WILD_BELOW     10    // Wild band: anchor - 10 ...
#define HOENN_SCALING_WILD_ABOVE     4     // ... up to anchor - 4
#define HOENN_SCALING_BOSS_EXTRA     1     // Boss ace: anchor + 1

// Trainers whose original team reaches this level are not scaled.
#define HOENN_SCALING_FIXED_MIN_LEVEL 70


// Trainer Pokémon (not wild ones) evolve once the scaled level reaches
// their evolution level. Stone, trade and condition-only evolutions use the
// level in src/data/trainer_evo_levels.h. Branches and skipped steps are fixed
// per trainer and party slot.
#define HOENN_SCALING_TRAINER_EVOLVE TRUE
#define HOENN_SCALING_EVO_OTHER_LEVEL 36   // their level if the target species is not in that table
#define HOENN_SCALING_EVO_SKIP_PERCENT 10  // chance per evolution step to stay at the current stage

#define HOENN_SCALING_MIN_LEVEL      5     // absolute lower bound
#define HOENN_SCALING_MAX_LEVEL      100   // absolute upper bound

// Ceiling of every corridor once FLAG_IS_HOENN_CHAMPION is set (floors stay),
// see docs/origin_jade/DECISIONS.md, D-031.
#define HOENN_SCALING_TITLE_CEILING  100

// Corridor per area: {map section, floor, ceiling}. Areas without an entry
// use HOENN_SCALING_DEFAULT_FLOOR/CEILING. The tiers follow the player's
// anchor in Hoenn (arrival after the Johto title about 65, league about
// 92), see docs/origin_jade/DECISIONS.md, D-012.
#define HOENN_SCALING_DEFAULT_FLOOR    40
#define HOENN_SCALING_DEFAULT_CEILING  100

#define HOENN_SCALING_CORRIDORS \
    /* Tier 1: entry (65-85) */ \
    { MAPSEC_LITTLEROOT_TOWN,   65,  85 }, \
    { MAPSEC_OLDALE_TOWN,       65,  85 }, \
    { MAPSEC_PETALBURG_CITY,    75,  95 }, \
    { MAPSEC_ROUTE_101,         65,  85 }, \
    { MAPSEC_ROUTE_102,         65,  85 }, \
    { MAPSEC_ROUTE_103,         65,  85 }, \
    { MAPSEC_ROUTE_104,         65,  85 }, \
    { MAPSEC_PETALBURG_WOODS,   65,  85 }, \
    { MAPSEC_ROUTE_116,         65,  85 }, \
    { MAPSEC_RUSTURF_TUNNEL,    65,  85 }, \
    { MAPSEC_RUSTBORO_CITY,     65,  85 }, \
    { MAPSEC_DEWFORD_TOWN,      65,  85 }, \
    { MAPSEC_ROUTE_105,         75,  95 }, \
    { MAPSEC_ROUTE_106,         65,  85 }, \
    { MAPSEC_ROUTE_107,         75,  95 }, \
    { MAPSEC_ROUTE_108,         75,  95 }, \
    { MAPSEC_GRANITE_CAVE,      65,  85 }, \
    { MAPSEC_ABANDONED_SHIP,    75,  95 }, \
    /* Tier 2: early middle (70-90) */ \
    { MAPSEC_SLATEPORT_CITY,    70,  90 }, \
    { MAPSEC_ROUTE_109,         70,  90 }, \
    { MAPSEC_ROUTE_110,         70,  90 }, \
    { MAPSEC_MAUVILLE_CITY,     70,  90 }, \
    { MAPSEC_VERDANTURF_TOWN,   70,  90 }, \
    { MAPSEC_ROUTE_117,         70,  90 }, \
    { MAPSEC_ROUTE_118,         75,  95 }, \
    { MAPSEC_ROUTE_111,         75,  95 }, \
    { MAPSEC_ROUTE_112,         75,  95 }, \
    { MAPSEC_ROUTE_113,         70,  90 }, \
    { MAPSEC_FIERY_PATH,        75,  95 }, \
    { MAPSEC_FIERY_PATH2,       75,  95 }, \
    { MAPSEC_JAGGED_PASS,       75,  95 }, \
    { MAPSEC_JAGGED_PASS2,      75,  95 }, \
    { MAPSEC_NEW_MAUVILLE,      75,  95 }, \
    { MAPSEC_MIRAGE_TOWER,      70,  90 }, \
    /* Tier 3: late middle (75-95) */ \
    { MAPSEC_FALLARBOR_TOWN,    75,  95 }, \
    { MAPSEC_ROUTE_114,         75,  95 }, \
    { MAPSEC_ROUTE_115,         75,  95 }, \
    { MAPSEC_METEOR_FALLS,      75,  95 }, \
    { MAPSEC_METEOR_FALLS2,     75,  95 }, \
    { MAPSEC_MT_CHIMNEY,        75,  95 }, \
    { MAPSEC_LAVARIDGE_TOWN,    75,  95 }, \
    { MAPSEC_ROUTE_119,         75,  95 }, \
    { MAPSEC_ROUTE_120,         75,  95 }, \
    { MAPSEC_FORTREE_CITY,      75,  95 }, \
    { MAPSEC_SCORCHED_SLAB,     75,  95 }, \
    { MAPSEC_SAFARI_ZONE,       75,  95 }, \
    /* Tier 4: final stretch (80-100) */ \
    { MAPSEC_ROUTE_121,         80, 100 }, \
    { MAPSEC_ROUTE_122,         80, 100 }, \
    { MAPSEC_ROUTE_123,         80, 100 }, \
    { MAPSEC_LILYCOVE_CITY,     80, 100 }, \
    { MAPSEC_MT_PYRE,           80, 100 }, \
    { MAPSEC_ROUTE_124,         80, 100 }, \
    { MAPSEC_ROUTE_125,         80, 100 }, \
    { MAPSEC_ROUTE_126,         80, 100 }, \
    { MAPSEC_ROUTE_127,         80, 100 }, \
    { MAPSEC_ROUTE_128,         80, 100 }, \
    { MAPSEC_UNDERWATER_124,    80, 100 }, \
    { MAPSEC_UNDERWATER_126,    80, 100 }, \
    { MAPSEC_UNDERWATER_127,    80, 100 }, \
    { MAPSEC_UNDERWATER_128,    80, 100 }, \
    { MAPSEC_MOSSDEEP_CITY,     80, 100 }, \
    { MAPSEC_SHOAL_CAVE,        80, 100 }, \
    { MAPSEC_AQUA_HIDEOUT,      80, 100 }, \
    { MAPSEC_AQUA_HIDEOUT_OLD,  80, 100 }, \
    { MAPSEC_MAGMA_HIDEOUT,     80, 100 }, \
    { MAPSEC_SEAFLOOR_CAVERN,   80, 100 }, \
    { MAPSEC_UNDERWATER_SEAFLOOR_CAVERN, 80, 100 }, \
    { MAPSEC_SOOTOPOLIS_CITY,   80, 100 }, \
    { MAPSEC_UNDERWATER_SOOTOPOLIS, 80, 100 }, \
    { MAPSEC_CAVE_OF_ORIGIN,    80, 100 }, \
    { MAPSEC_ROUTE_129,         80, 100 }, \
    { MAPSEC_ROUTE_130,         80, 100 }, \
    { MAPSEC_ROUTE_131,         80, 100 }, \
    { MAPSEC_ROUTE_132,         80, 100 }, \
    { MAPSEC_ROUTE_133,         80, 100 }, \
    { MAPSEC_ROUTE_134,         80, 100 }, \
    { MAPSEC_PACIFIDLOG_TOWN,   80, 100 }, \
    { MAPSEC_MIRAGE_ISLAND,     80, 100 }, \
    { MAPSEC_SEALED_CHAMBER,    80, 100 }, \
    { MAPSEC_UNDERWATER_SEALED_CHAMBER, 80, 100 }, \
    { MAPSEC_ISLAND_CAVE,       80, 100 }, \
    { MAPSEC_DESERT_RUINS,      80, 100 }, \
    { MAPSEC_ANCIENT_TOMB,      80, 100 }, \
    /* Tier 5: endgame (85-100) */ \
    { MAPSEC_VICTORY_ROAD,      85, 100 }, \
    { MAPSEC_EVER_GRANDE_CITY,  85, 100 }, \
    { MAPSEC_SKY_PILLAR,        85, 100 }, \
    { MAPSEC_DESERT_UNDERPASS,  85, 100 }, \
    { MAPSEC_ARTISAN_CAVE,      85, 100 }, \
    { MAPSEC_MARINE_CAVE,       85, 100 }, \
    { MAPSEC_UNDERWATER_MARINE_CAVE, 85, 100 }, \
    { MAPSEC_TERRA_CAVE,        85, 100 }, \
    { MAPSEC_ALTERING_CAVE,     85, 100 }, \
    { MAPSEC_NAVEL_ROCK,        85, 100 }, \
    { MAPSEC_UNDERWATER_105,    85, 100 }, \
    { MAPSEC_UNDERWATER_125,    85, 100 }, \
    { MAPSEC_UNDERWATER_129,    85, 100 },


// =====================================================================
// Experience damping in all regions, by the level of the receiving Pokémon.
// =====================================================================
#define EXP_DAMP_ENABLED             TRUE
#define EXP_DAMP_FAST_UNTIL          30    // up to here: 100 %
#define EXP_DAMP_MID_UNTIL           60    // 31-60:
#define EXP_DAMP_MID_PERCENT         70    //   70 % experience
#define EXP_DAMP_HIGH_PERCENT        50    // from 61: 50 % experience

#endif // GUARD_CONFIG_HOENN_SCALING_H
