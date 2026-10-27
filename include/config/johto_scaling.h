#ifndef GUARD_CONFIG_JOHTO_SCALING_H
#define GUARD_CONFIG_JOHTO_SCALING_H

// =====================================================================
// Johto level scaling (hns_de / modern_hns_engde)
//
// Trainer and wild levels in Johto follow the highest level in the
// player's party (the anchor), clamped to the area's corridor
// {map section, floor, ceiling} below. Areas missing there are not scaled.
// Levels in trainers_hns.party only set the gaps within a team.
// =====================================================================

#define JOHTO_LEVEL_SCALING          TRUE  // master switch

#define JOHTO_SCALING_TRAINER_BELOW  3     // Trainer band: anchor - 3 ...
#define JOHTO_SCALING_TRAINER_ABOVE  2     // ... up to anchor + 2
#define JOHTO_SCALING_WILD_BELOW     10    // Wild band: anchor - 10 ...
#define JOHTO_SCALING_WILD_ABOVE     4     // ... up to anchor - 4
#define JOHTO_SCALING_BOSS_EXTRA     1     // Boss ace: anchor + 2 + 1

// Trainers with an original level of at least this are not scaled (Red on Mt. Silver).
#define JOHTO_SCALING_FIXED_MIN_LEVEL 77

// Scaled trainer Pokemon evolve once they reach their evolution level.
#define JOHTO_SCALING_TRAINER_EVOLVE TRUE
#define JOHTO_SCALING_EVO_OTHER_LEVEL 36   // threshold for stone/trade evolutions

#define JOHTO_SCALING_MIN_LEVEL      5     // absolute lower bound
#define JOHTO_SCALING_MAX_LEVEL      100   // absolute upper bound

// Ceiling of every corridor once FLAG_IS_JOHTO_CHAMPION is set (floors stay),
// see docs/origin_jade/DECISIONS.md, D-031.
#define JOHTO_SCALING_TITLE_CEILING  100

// No effect: Johto only scales areas listed in JOHTO_SCALING_CORRIDORS.
#define JOHTO_SCALING_DEFAULT_FLOOR    45
#define JOHTO_SCALING_DEFAULT_CEILING  80

#define JOHTO_SCALING_CORRIDORS \
    /* Way in from Kanto, also the way to the Johto League (45-80) */ \
    { MAPSEC_ROUTE_26,          45,  80 }, \
    { MAPSEC_ROUTE_27,          45,  80 }, \
    { MAPSEC_TOHJO_FALLS,       45,  80 }, \
    /* Tier 1: arrival up to Bugsy (45-55) */ \
    { MAPSEC_NEW_BARK_TOWN,     45,  55 }, \
    { MAPSEC_ROUTE_29,          45,  55 }, \
    { MAPSEC_CHERRYGROVE_CITY,  45,  55 }, \
    { MAPSEC_ROUTE_30,          45,  55 }, \
    { MAPSEC_ROUTE_31,          45,  55 }, \
    { MAPSEC_VIOLET_CITY,       45,  55 }, \
    { MAPSEC_SPROUT_TOWER,      45,  55 }, \
    { MAPSEC_RUINS_OF_ALPH,     45,  55 }, \
    { MAPSEC_ROUTE_32,          45,  55 }, \
    { MAPSEC_UNION_CAVE,        45,  55 }, \
    { MAPSEC_ROUTE_33,          45,  55 }, \
    { MAPSEC_AZALEA_TOWN,       45,  55 }, \
    { MAPSEC_SLOWPOKE_WELL,     45,  55 }, \
    { MAPSEC_ILEX_FOREST,       45,  55 }, \
    { MAPSEC_DARK_CAVE,         45,  55 }, \
    { MAPSEC_ROUTE_46,          45,  55 }, \
    /* Tier 2: Whitney and Morty (50-61) */ \
    { MAPSEC_ROUTE_34,          50,  61 }, \
    { MAPSEC_GOLDENROD_CITY,    50,  61 }, \
    { MAPSEC_ROUTE_35,          50,  61 }, \
    { MAPSEC_NATIONAL_PARK,     50,  61 }, \
    { MAPSEC_ROUTE_36,          50,  61 }, \
    { MAPSEC_ROUTE_37,          50,  61 }, \
    { MAPSEC_ECRUTEAK_CITY,     50,  61 }, \
    { MAPSEC_BURNED_TOWER,      50,  61 }, \
    { MAPSEC_TIN_TOWER,         50,  61 }, \
    /* Tier 3: Jasmine and Chuck (55-67) */ \
    { MAPSEC_ROUTE_38,          55,  67 }, \
    { MAPSEC_ROUTE_39,          55,  67 }, \
    { MAPSEC_OLIVINE_CITY,      55,  67 }, \
    { MAPSEC_OLIVINE_LIGHTHOUSE, 55, 71 }, \
    { MAPSEC_SS_AQUA,           55,  67 }, \
    { MAPSEC_ROUTE_40,          55,  67 }, \
    { MAPSEC_ROUTE_41,          55,  67 }, \
    { MAPSEC_WHIRL_ISLANDS,     55,  67 }, \
    { MAPSEC_CIANWOOD_CITY,     55,  67 }, \
    { MAPSEC_ROUTE_47,          55,  67 }, \
    { MAPSEC_ROUTE_48,          55,  67 }, \
    { MAPSEC_CLIFF_CAVE,        55,  67 }, \
    { MAPSEC_SAFARI_ZONE_GATE,  55,  67 }, \
    /* Tier 4: Pryce and Clair (60-73) */ \
    { MAPSEC_ROUTE_42,          60,  73 }, \
    { MAPSEC_MT_MORTAR,         60,  73 }, \
    { MAPSEC_MAHOGANY_TOWN,     60,  73 }, \
    { MAPSEC_ROUTE_43,          60,  73 }, \
    { MAPSEC_LAKE_OF_RAGE,      60,  73 }, \
    { MAPSEC_ROCKET_HIDEOUT_HNS, 60, 76 }, \
    { MAPSEC_ROUTE_44,          60,  73 }, \
    { MAPSEC_ICE_PATH,          60,  73 }, \
    { MAPSEC_BLACKTHORN_CITY,   60,  73 }, \
    { MAPSEC_DRAGONS_DEN,       60,  73 }, \
    { MAPSEC_ROUTE_45,          60,  73 }, \
    /* Tier 5: Victory Road and League (65-80). \
       MAPSEC_INDIGO_PLATEAU here means Johto's league maps only; \
       Kanto's plateau maps use config/kanto_scaling.h. */ \
    { MAPSEC_VICTORY_ROAD_HNS,  65,  80 }, \
    { MAPSEC_INDIGO_PLATEAU,    65,  80 }, \
    /* Mt. Silver (70-90) */ \
    { MAPSEC_ROUTE_28,          70,  90 }, \
    { MAPSEC_MT_SILVER,         70,  90 },

#endif // GUARD_CONFIG_JOHTO_SCALING_H
