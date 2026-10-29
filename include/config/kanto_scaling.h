#ifndef GUARD_CONFIG_KANTO_SCALING_H
#define GUARD_CONFIG_KANTO_SCALING_H

// =====================================================================
// Kanto level scaling (FRLG Kanto maps), see docs/origin_jade/DECISIONS.md, D-031.
//
// Off until FLAG_IS_KANTO_CHAMPION: the first run keeps the hand-set
// levels (D-011). After the title, trainers (rematches included) and wild
// Pokemon follow the player's anchor (include/level_scaling.h) up to
// KANTO_SCALING_MAX_LEVEL. Scaling only raises levels: the hand-set level is
// the floor. Kanto has no corridors.
// Before the title only VS Seeker rematch teams move up, to their tier's
// level floor (sKantoRematchLevelFloors in src/vs_seeker.c, D-034).
// Johto's league maps (Kanto mapsec, HnS map groups) use config/johto_scaling.h;
// Route22_hns is not scaled.
// =====================================================================

#define KANTO_LEVEL_SCALING          TRUE  // master switch

#define KANTO_SCALING_TRAINER_BELOW  3     // Trainer band: anchor - 3 ...
#define KANTO_SCALING_TRAINER_ABOVE  2     // ... up to anchor + 2
#define KANTO_SCALING_WILD_BELOW     10    // Wild band: anchor - 10 ...
#define KANTO_SCALING_WILD_ABOVE     4     // ... up to anchor - 4
#define KANTO_SCALING_BOSS_EXTRA     1     // Boss ace: anchor + 2 + 1

// Trainers with an original level of at least this are not scaled (none in Kanto today).
#define KANTO_SCALING_FIXED_MIN_LEVEL 77

// Scaled trainer Pokemon, and those a VS Seeker rematch floor raised, evolve
// once they reach their evolution level. Stone, trade and condition-only
// evolutions use the level in src/data/trainer_evo_levels.h. Branches and
// skipped steps are fixed per trainer and party slot.
#define KANTO_SCALING_TRAINER_EVOLVE TRUE
#define KANTO_SCALING_EVO_OTHER_LEVEL 36   // their level if the target species is not in that table
#define KANTO_SCALING_EVO_SKIP_PERCENT 10  // chance per evolution step to stay at the current stage

#define KANTO_SCALING_MIN_LEVEL      5     // absolute lower bound
#define KANTO_SCALING_MAX_LEVEL      100   // absolute upper bound

#endif // GUARD_CONFIG_KANTO_SCALING_H
