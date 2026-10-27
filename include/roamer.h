#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

// Location tables for TryAddRoamer. The id is saved in struct Roamer: only append.
#if IS_HNS
enum { ROAMER_LOC_TABLE_JOHTO, ROAMER_LOC_TABLE_KANTO, ROAMER_LOC_TABLE_HOENN, ROAMER_LOC_TABLE_COUNT };
#else
enum { ROAMER_LOC_TABLE_HOENN, ROAMER_LOC_TABLE_COUNT };
#endif

void DeactivateAllRoamers(void);
void InitRoamer(void);
void InitKantoRoamers(void);
void UpdateLocationHistoryForRoamer(void);
void RoamerMoveToOtherLocationSet(u32 roamerIndex);
void RoamerMove(u32 roamerIndex);
bool8 IsRoamerAt(u32 roamerIndex, u8 mapGroup, u8 mapNum);
void CreateRoamerMonInstance(u32 roamerIndex);
bool8 TryStartRoamerEncounter(void);
void UpdateRoamerHPStatus(struct Pokemon *mon);
void SetRoamerInactive(u32 roamerIndex);
void GetRoamerLocation(u32 roamerIndex, u8 *mapGroup, u8 *mapNum);
bool8 TryAddRoamer(u16 species, u8 level, u8 locationTableId);
bool8 IsRoamerSpeciesActive(u16 species);
void MoveAllRoamersToOtherLocationSets(void);
void MoveAllRoamers(void);
void TryShowRoamerFlash(void);

extern u8 gEncounteredRoamerIndex;

#endif // GUARD_ROAMER_H
