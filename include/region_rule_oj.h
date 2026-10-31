#ifndef GUARD_REGION_RULE_OJ_H
#define GUARD_REGION_RULE_OJ_H

#include "constants/regions.h"

// Region rule, see docs/origin_jade/DECISIONS.md, D-049.

// Region of a species: national numbers 1-151 Kanto, 152-251 Johto, 252-386 Hoenn;
// babies and later evolutions count to their line's region (Kanto lines to Johto).
// REGION_NONE for SPECIES_NONE.
enum Region GetSpeciesRegion(u16 species);
// Kanto always; Johto from the first Johto map after the Kanto title (not the gatehouse
// south of Route 23); Hoenn from the first trip there.
bool32 IsRegionUnlocked(enum Region region);
bool32 IsSpeciesRegionUnlocked(u16 species);
// Map load: sets FLAG_JOHTO_UNLOCKED on a Johto map after the Kanto title.
void TryUnlockJohtoOnMapLoad(void);
// Day Care egg of a region not unlocked yet: the first stage on the way to
// parentSpecies whose region is unlocked (Pikachu instead of Pichu). Unchanged
// with a randomizer option that changes the player's species, or if no stage of
// the line is unlocked.
u16 GetUnlockedEggSpecies(u16 eggSpecies, u16 parentSpecies);

#endif // GUARD_REGION_RULE_OJ_H
