#ifndef GUARD_CONSTANTS_VARS_ORIGIN_JADE_H
#define GUARD_CONSTANTS_VARS_ORIGIN_JADE_H

// =====================================================================
// Origin Jade - reserved var block (0x4300-0x437F, stored in SaveBlock3)
//
// Add new Origin Jade vars here, in their region's section. Same rules as
// constants/flags_origin_jade.h. For yes/no values use a flag.
// =====================================================================

#define OJ_VARS_START               0x4300
#define OJ_VARS_COUNT               128
#define OJ_VARS_END                 (OJ_VARS_START + OJ_VARS_COUNT - 1)

#define OJ_VARS_KANTO               (OJ_VARS_START + 0)     // 24 slots
#define OJ_VARS_KANTO_SIZE          24
#define OJ_VARS_JOHTO               (OJ_VARS_START + 32)    // 40 slots
#define OJ_VARS_JOHTO_SIZE          40
#define OJ_VARS_HOENN               (OJ_VARS_START + 80)    // 24 slots
#define OJ_VARS_HOENN_SIZE          24
#define OJ_VARS_GLOBAL              (OJ_VARS_START + 112)   // 16 slots
#define OJ_VARS_GLOBAL_SIZE         16

// ---------------------------------------------------------------------
// Kanto (OJ_VARS_KANTO + 0 to + 23)
// ---------------------------------------------------------------------
// Legendary flee cooldowns, 2 bits per encounter (src/legendaries_oj.c).
#define VAR_LEGENDARY_FLEE_KANTO    (OJ_VARS_KANTO + 0)
// VS Seeker steps (src/vs_seeker.c): low byte = steps since the last use,
// high byte = steps since trainers started to want a rematch. Up to 100 each.
#define VAR_VS_SEEKER_STEPS         (OJ_VARS_KANTO + 1)
// Trainers that want a VS Seeker rematch on the current map: bit n = local id n + 1
// (LO: local ids 1-16, HI: 17-32). Cleared on every map change.
#define VAR_VS_SEEKER_REMATCH_LO    (OJ_VARS_KANTO + 2)
#define VAR_VS_SEEKER_REMATCH_HI    (OJ_VARS_KANTO + 3)
// Saffron's Trainer Fan Club (src/trainer_fan_club.c); VAR_FANCLUB_* are Lilycove's.
#define VAR_SAFFRON_FANCLUB_FAN_COUNTER      (OJ_VARS_KANTO + 4)
#define VAR_SAFFRON_FANCLUB_LOSE_FAN_TIMER   (OJ_VARS_KANTO + 5)

// ---------------------------------------------------------------------
// Johto (OJ_VARS_JOHTO + 0 to + 39)
// ---------------------------------------------------------------------
// HM permits as a bitmask, see include/johto_permits.h.
#define VAR_JOHTO_PERMITS           (OJ_VARS_JOHTO + 0)
// VAR_JOHTO_BADGES is in constants/vars_frlg_hns.h.
// Arrival from Kanto: 0 = a girl blocks New Bark Town's exit, 1 = exit open (set by Elm).
#define VAR_JOHTO_ARRIVAL_STATE     (OJ_VARS_JOHTO + 1)
// Johto starter from Elm's lab: 0 = Chikorita, 1 = Cyndaquil, 2 = Totodile.
// VAR_STARTER_MON keeps the Kanto starter (0 = Bulbasaur, 1 = Squirtle, 2 = Charmander).
#define VAR_JOHTO_STARTER_MON       (OJ_VARS_JOHTO + 2)
// Legendary flee cooldowns, 2 bits per encounter (src/legendaries_oj.c).
#define VAR_LEGENDARY_FLEE_JOHTO    (OJ_VARS_JOHTO + 3)

// ---------------------------------------------------------------------
// Hoenn (OJ_VARS_HOENN + 0 to + 23)
// ---------------------------------------------------------------------
// Hoenn vars moved off the numbers that vars_hns.h gives to HnS content.
#undef  VAR_TRICK_HOUSE_PUZZLE_3_STATE
#define VAR_TRICK_HOUSE_PUZZLE_3_STATE          (OJ_VARS_HOENN + 0)
#undef  VAR_TRICK_HOUSE_PUZZLE_4_STATE
#define VAR_TRICK_HOUSE_PUZZLE_4_STATE          (OJ_VARS_HOENN + 1)
#undef  VAR_TRICK_HOUSE_PUZZLE_5_STATE
#define VAR_TRICK_HOUSE_PUZZLE_5_STATE          (OJ_VARS_HOENN + 2)
#undef  VAR_WEATHER_INSTITUTE_STATE
#define VAR_WEATHER_INSTITUTE_STATE             (OJ_VARS_HOENN + 3)
#undef  VAR_TRICK_HOUSE_PUZZLE_7_STATE_2
#define VAR_TRICK_HOUSE_PUZZLE_7_STATE_2        (OJ_VARS_HOENN + 4)
#undef  VAR_SLATEPORT_FAN_CLUB_STATE
#define VAR_SLATEPORT_FAN_CLUB_STATE            (OJ_VARS_HOENN + 5)
#undef  VAR_MT_PYRE_STATE
#define VAR_MT_PYRE_STATE                       (OJ_VARS_HOENN + 6)
#undef  VAR_JAGGED_PASS_ASH_WEATHER
#define VAR_JAGGED_PASS_ASH_WEATHER             (OJ_VARS_HOENN + 7)
#undef  VAR_GLASS_WORKSHOP_STATE
#define VAR_GLASS_WORKSHOP_STATE                (OJ_VARS_HOENN + 8)
#undef  VAR_METEOR_FALLS_STATE
#define VAR_METEOR_FALLS_STATE                  (OJ_VARS_HOENN + 9)
#undef  VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE
#define VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE     (OJ_VARS_HOENN + 10)
#undef  VAR_TRICK_HOUSE_PRIZE_PICKUP
#define VAR_TRICK_HOUSE_PRIZE_PICKUP            (OJ_VARS_HOENN + 11)
#undef  VAR_VICTORY_ROAD_1F_STATE
#define VAR_VICTORY_ROAD_1F_STATE               (OJ_VARS_HOENN + 12)
#undef  VAR_OLDALE_RIVAL_STATE
#define VAR_OLDALE_RIVAL_STATE                  (OJ_VARS_HOENN + 13)
#undef  VAR_JAGGED_PASS_STATE
#define VAR_JAGGED_PASS_STATE                   (OJ_VARS_HOENN + 14)
// Devon's fossil revival in Rustboro. VAR_FOSSIL_RESURRECTION_STATE and
// VAR_WHICH_FOSSIL_REVIVED belong to the Ruins of Alph lab.
#define VAR_HOENN_FOSSIL_RESURRECTION_STATE     (OJ_VARS_HOENN + 15)
#define VAR_HOENN_WHICH_FOSSIL_REVIVED          (OJ_VARS_HOENN + 16)
// Legendary flee cooldowns, 2 bits per encounter (src/legendaries_oj.c).
#define VAR_LEGENDARY_FLEE_HOENN                (OJ_VARS_HOENN + 17)

// ---------------------------------------------------------------------
// Cross-region (OJ_VARS_GLOBAL + 0 to + 15)
// ---------------------------------------------------------------------
// no entries yet

#endif // GUARD_CONSTANTS_VARS_ORIGIN_JADE_H
