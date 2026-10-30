#ifndef GUARD_CONFIG_JOHTO_SCALING_H
#define GUARD_CONFIG_JOHTO_SCALING_H

// =====================================================================
// Johto level scaling (hns_de / modern_hns_engde)
//
// Trainer and wild levels in Johto follow the player's anchor (mean of
// the three highest party levels, at most SCALING_ANCHOR_MAX_DROP below
// the highest, include/level_scaling.h), clamped to the area's corridor
// {map section, floor, ceiling} below. Areas missing there are not scaled.
// Levels in trainers_hns.party only set the gaps within a team.
// =====================================================================

#define JOHTO_LEVEL_SCALING          TRUE  // master switch

#define JOHTO_SCALING_TRAINER_BELOW  3     // Trainer band: anchor - 3 ...
#define JOHTO_SCALING_TRAINER_ABOVE  0     // ... up to the anchor
#define JOHTO_SCALING_WILD_BELOW     10    // Wild band: anchor - 10 ...
#define JOHTO_SCALING_WILD_ABOVE     4     // ... up to anchor - 4
#define JOHTO_SCALING_BOSS_EXTRA     1     // Boss ace: anchor + 1

// Trainers with an original level of at least this are not scaled (Red on Mt. Silver).
#define JOHTO_SCALING_FIXED_MIN_LEVEL 77

// Scaled trainer Pokemon evolve once they reach their evolution level. Stone,
// trade and condition-only evolutions use the level in src/data/trainer_evo_levels.h.
// Branches and skipped steps are fixed per trainer and party slot.
#define JOHTO_SCALING_TRAINER_EVOLVE TRUE
#define JOHTO_SCALING_EVO_OTHER_LEVEL 36   // their level if the target species is not in that table
#define JOHTO_SCALING_EVO_SKIP_PERCENT 10  // chance per evolution step to stay at the current stage

#define JOHTO_SCALING_MIN_LEVEL      5     // absolute lower bound
#define JOHTO_SCALING_MAX_LEVEL      100   // absolute upper bound

// Ceiling of every corridor once FLAG_IS_JOHTO_CHAMPION is set (floors stay),
// see docs/origin_jade/DECISIONS.md, D-031.
#define JOHTO_SCALING_TITLE_CEILING  100

// No effect: Johto only scales areas listed in JOHTO_SCALING_CORRIDORS.
#define JOHTO_SCALING_DEFAULT_FLOOR    40
#define JOHTO_SCALING_DEFAULT_CEILING  80

// Ceilings: the bosses' levels for the average player (D-012); stronger teams
// meet capped levels. Floors: about 6 below that player's anchor at the tier's start.
#define JOHTO_SCALING_CORRIDORS \
    /* Way in from Kanto, also the way to the Johto League (40-80) */ \
    { MAPSEC_ROUTE_26,          40,  80 }, \
    { MAPSEC_ROUTE_27,          40,  80 }, \
    { MAPSEC_TOHJO_FALLS,       40,  80 }, \
    /* Tier 1: arrival up to Bugsy (41-50) */ \
    { MAPSEC_NEW_BARK_TOWN,     41,  50 }, \
    { MAPSEC_ROUTE_29,          41,  50 }, \
    /* Silver's first team: six Pokemon at the ace's level */ \
    { MAPSEC_CHERRYGROVE_CITY,  41,  48 }, \
    { MAPSEC_ROUTE_30,          41,  50 }, \
    { MAPSEC_ROUTE_31,          41,  50 }, \
    { MAPSEC_VIOLET_CITY,       41,  50 }, \
    { MAPSEC_SPROUT_TOWER,      41,  50 }, \
    { MAPSEC_RUINS_OF_ALPH,     41,  50 }, \
    { MAPSEC_ROUTE_32,          41,  50 }, \
    { MAPSEC_UNION_CAVE,        41,  50 }, \
    { MAPSEC_ROUTE_33,          41,  50 }, \
    { MAPSEC_AZALEA_TOWN,       41,  50 }, \
    { MAPSEC_SLOWPOKE_WELL,     41,  50 }, \
    { MAPSEC_ILEX_FOREST,       41,  50 }, \
    { MAPSEC_DARK_CAVE,         41,  50 }, \
    { MAPSEC_ROUTE_46,          41,  50 }, \
    /* Tier 2: Whitney and Morty (44-53) */ \
    { MAPSEC_ROUTE_34,          44,  53 }, \
    /* Radio Tower after Pryce */ \
    { MAPSEC_GOLDENROD_CITY,    44,  61 }, \
    { MAPSEC_ROUTE_35,          44,  53 }, \
    { MAPSEC_NATIONAL_PARK,     44,  53 }, \
    { MAPSEC_ROUTE_36,          44,  53 }, \
    { MAPSEC_ROUTE_37,          44,  53 }, \
    /* Theater with eight badges */ \
    { MAPSEC_ECRUTEAK_CITY,     44,  61 }, \
    { MAPSEC_BURNED_TOWER,      44,  53 }, \
    /* Only with eight badges: tier 5 */ \
    { MAPSEC_TIN_TOWER,         56,  64 }, \
    /* Tier 3: Chuck and Jasmine (47-55) */ \
    { MAPSEC_ROUTE_38,          47,  55 }, \
    { MAPSEC_ROUTE_39,          47,  55 }, \
    { MAPSEC_OLIVINE_CITY,      47,  55 }, \
    { MAPSEC_OLIVINE_LIGHTHOUSE, 47, 55 }, \
    { MAPSEC_SS_AQUA,           47,  55 }, \
    { MAPSEC_ROUTE_40,          47,  55 }, \
    { MAPSEC_ROUTE_41,          47,  55 }, \
    /* Only with eight badges: tier 5 */ \
    { MAPSEC_WHIRL_ISLANDS,     56,  64 }, \
    { MAPSEC_CIANWOOD_CITY,     47,  55 }, \
    { MAPSEC_ROUTE_47,          47,  55 }, \
    { MAPSEC_ROUTE_48,          47,  55 }, \
    { MAPSEC_CLIFF_CAVE,        47,  55 }, \
    { MAPSEC_SAFARI_ZONE_GATE,  47,  55 }, \
    /* Tier 4: Rocket Hideout and Pryce (50-58) */ \
    { MAPSEC_ROUTE_42,          50,  58 }, \
    { MAPSEC_MT_MORTAR,         50,  58 }, \
    { MAPSEC_MAHOGANY_TOWN,     50,  58 }, \
    { MAPSEC_ROUTE_43,          50,  58 }, \
    { MAPSEC_LAKE_OF_RAGE,      50,  58 }, \
    { MAPSEC_ROCKET_HIDEOUT_HNS, 50, 58 }, \
    /* Tier 5: Clair, after the Radio Tower (56-64) */ \
    { MAPSEC_ROUTE_44,          56,  64 }, \
    { MAPSEC_ICE_PATH,          56,  64 }, \
    { MAPSEC_BLACKTHORN_CITY,   56,  64 }, \
    { MAPSEC_DRAGONS_DEN,       56,  64 }, \
    { MAPSEC_ROUTE_45,          56,  64 }, \
    /* Tier 6: Victory Road and League (58-65). \
       MAPSEC_INDIGO_PLATEAU here means Johto's league maps only; \
       Kanto's plateau maps use config/kanto_scaling.h. */ \
    { MAPSEC_VICTORY_ROAD_HNS,  58,  65 }, \
    { MAPSEC_INDIGO_PLATEAU,    58,  65 }, \
    /* Mt. Silver (70-90) */ \
    { MAPSEC_ROUTE_28,          70,  90 }, \
    { MAPSEC_MT_SILVER,         70,  90 },

#endif // GUARD_CONFIG_JOHTO_SCALING_H
