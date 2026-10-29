#ifndef GUARD_JOHTO_PERMITS_H
#define GUARD_JOHTO_PERMITS_H

#include "constants/johto_permits.h"

// HM permits for Johto, handed out with the matching Johto badges.

bool32 HasJohtoPermit(u32 index);
bool32 JohtoPermitsApply(void);     // TRUE in Johto, except on the way in from Kanto
bool32 IsJohtoMapsec(u32 mapSecId);
void SetJohtoPermit(void);          // Special: PERM_* index in gSpecialVar_0x8004

// Checks the license in Hoenn, the permit in Johto, TRUE elsewhere.
void CheckFieldPermission(void);    // Special: index in gSpecialVar_0x8004
void BufferFieldPermissionTerm(void); // Special: the region's term into STR_VAR_2

#endif // GUARD_JOHTO_PERMITS_H
