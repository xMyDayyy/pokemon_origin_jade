#ifndef GUARD_LEVEL_SCALING_H
#define GUARD_LEVEL_SCALING_H

#include "global.h"

struct Trainer;

// Level scaling for Hoenn, Johto and (after the Kanto title) Kanto, rules in
// include/config/hoenn_scaling.h, johto_scaling.h and kanto_scaling.h.
// Pass-throughs everywhere else.
bool32 LevelScalingActive(void);
u8 ScaleWildMonLevel(u8 level);
u8 ScaleTrainerMonLevel(const struct Trainer *trainer, u8 level, u8 partyMaxLevel);
// Call right after ScaleTrainerMonLevel for the same Pokemon. partyIndex: its index
// in the trainer's party data.
u16 ScaleTrainerMonSpecies(u16 species, u8 scaledLevel, u16 trainerId, u8 partyIndex);

// Not tied to scaling: also used by the region map, location names and HM licenses.
bool32 IsHoennMapsec(u32 mapSecId);
void TrySetHoennVisitedFlag(void);

#endif // GUARD_LEVEL_SCALING_H
