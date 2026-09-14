#ifndef GUARD_LEVEL_SCALING_H
#define GUARD_LEVEL_SCALING_H

#include "global.h"

struct Trainer;

// Dynamisches Levelscaling fuer Hoenn und Johto
// (siehe include/config/hoenn_scaling.h und include/config/johto_scaling.h).
// Welche Regel gilt, entscheidet die Mapsection der aktuellen Karte.
// Ausserhalb beider Regionen bzw. bei abgeschaltetem Scaling sind alle
// Funktionen wirkungslose Durchreichen - Kanto behaelt damit seine
// handgesetzte Levelleiter.
bool32 LevelScalingActive(void);
u8 ScaleWildMonLevel(u8 level);
u8 ScaleTrainerMonLevel(const struct Trainer *trainer, u8 level, u8 partyMaxLevel);
u16 ScaleTrainerMonSpecies(u16 species, u8 scaledLevel);

// Reine Geografie bzw. Hoenn-Flags - unabhaengig vom Scaling und auch
// von Regionskarte, Ortsnamen, VM-Lizenzen und Sprites genutzt.
bool32 IsHoennMapsec(u32 mapSecId);
void TrySetHoennVisitedFlag(void);

#endif // GUARD_LEVEL_SCALING_H
