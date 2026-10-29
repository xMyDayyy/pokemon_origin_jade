#ifndef GUARD_JOHTO_BADGES_H
#define GUARD_JOHTO_BADGES_H

#include "global.h"

// Johto badges as a bitmask in VAR_JOHTO_BADGES; FLAG_BADGE0X_GET is shared with Kanto.

u32 GetJohtoBadgeCount(void);
bool32 HasJohtoBadge(u32 index);   // 0 = Falkner ... 7 = Clair
void SetJohtoBadge(void);          // Special: index in gSpecialVar_0x8004
void CheckJohtoBadge(void);        // Special: index in, result into VAR_RESULT
void CountJohtoBadges(void);       // Special: count into VAR_RESULT

#endif // GUARD_JOHTO_BADGES_H
