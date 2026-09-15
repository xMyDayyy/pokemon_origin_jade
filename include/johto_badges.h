#ifndef GUARD_JOHTO_BADGES_H
#define GUARD_JOHTO_BADGES_H

#include "global.h"

// Johto-Ordensystem: eigene Bitmaske in VAR_JOHTO_BADGES, getrennt von
// FLAG_BADGE01-08. Die teilen sich Kanto und Johto - Rocko setzt
// FLAG_BADGE01_GET, Falkner ebenfalls. Nach der Kanto-Liga sind alle acht
// gesetzt, eine Ordenabfrage in Johto geht deshalb immer durch.
// Gleiche Bauart wie das Hoenn-Ordensystem.

u32 GetJohtoBadgeCount(void);
bool32 HasJohtoBadge(u32 index);   // 0 = Falkner ... 7 = Clair
void SetJohtoBadge(void);          // Special: Index in gSpecialVar_0x8004
void CheckJohtoBadge(void);        // Special: Index rein, Ergebnis nach VAR_RESULT
void CountJohtoBadges(void);       // Special: Anzahl nach VAR_RESULT

#endif // GUARD_JOHTO_BADGES_H
