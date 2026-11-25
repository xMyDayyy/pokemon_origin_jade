#ifndef GUARD_LEVEL_SCALING_H
#define GUARD_LEVEL_SCALING_H

#include "global.h"

struct Trainer;
struct WildPokemon;

// Level scaling for Hoenn, Johto and (after the Kanto title) Kanto, rules in
// include/config/hoenn_scaling.h, johto_scaling.h and kanto_scaling.h.
// With LEVEL_REMAP (include/config/level_remap.h) all levels are fixed instead.
// Pass-throughs everywhere else.

// Anchor of all regions: mean of the three highest party levels (eggs excluded;
// fewer Pokemon: their mean), rounded, but at most this far below the highest level.
#define SCALING_ANCHOR_MAX_DROP 8

bool32 LevelScalingActive(void);
u8 ScaleWildMonLevel(u8 level);
// Surf and fishing (mons, count: the encounter table): in Johto and Hoenn the grass
// range of the map or of a neighbour map without grass, else as ScaleWildMonLevel.
u8 ScaleWaterWildMonLevel(u8 level, const struct WildPokemon *mons, u32 count);
// Static and scripted encounters and roamers: never below the top of the map's wild band
// (maps with Johto's or Hoenn's rules).
u8 ScaleStaticMonLevel(u8 level);
// trainerId: the trainer of the party (phone rematch level band, config/level_remap.h).
u8 ScaleTrainerMonLevel(const struct Trainer *trainer, u16 trainerId, u8 level, u8 partyMaxLevel);
// Corridor ceiling of the current map (highest scaled wild level), 0 on maps without scaling.
u8 GetScalingCeiling(void);
// In-game battle partners (FillPartnerParty): the current map's trainer band without the
// boss extra. Call before the partner's Pokemon join the party.
u8 ScalePartnerMonLevel(u8 level, u8 partyMaxLevel);
// Call right after ScaleTrainerMonLevel or ScalePartnerMonLevel for the same Pokemon.
// partyIndex: its index in the trainer's party data.
u16 ScaleTrainerMonSpecies(u16 species, u8 scaledLevel, u16 trainerId, u8 partyIndex);
// Fixed levels (config/level_remap.h): percent of the experience a Pokemon of
// receiverLevel gets for one of opponentLevel on the current map.
u32 GetRemapExpPercent(u8 receiverLevel, u8 opponentLevel);

// Not tied to scaling: also used by the region map, location names and HM licenses.
bool32 IsHoennMapsec(u32 mapSecId);
void TrySetHoennVisitedFlag(void);

#endif // GUARD_LEVEL_SCALING_H
