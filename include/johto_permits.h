#ifndef GUARD_JOHTO_PERMITS_H
#define GUARD_JOHTO_PERMITS_H

#include "constants/johto_permits.h"

// VM-Befugnisse fuer Johto. Der Spieler beherrscht die Feldattacken laengst
// (Kanto-Champion), darf sie in Johto aber erst nach der jeweiligen Befugnis
// einsetzen -- vergeben wird sie zusammen mit dem passenden Johto-Orden.
//
// Eine eigene Bitmaske ist noetig, weil Kanto und Johto sich FLAG_BADGE01-08
// teilen: nach der Kanto-Liga sind alle acht gesetzt, eine Ordenabfrage in
// Johto geht deshalb immer durch. Gleiche Bauart wie die Hoenn-Lizenzen.

bool32 HasJohtoPermit(u32 index);
bool32 JohtoPermitsApply(void);     // TRUE, wenn der Spieler gerade in Johto steht
bool32 IsJohtoMapsec(u32 mapSecId);
void SetJohtoPermit(void);          // Special: Index in gSpecialVar_0x8004

// Regionsuebergreifend: prueft in Hoenn die Lizenz, in Johto die Befugnis,
// sonst immer TRUE.
void CheckFieldPermission(void);    // Special: Index in gSpecialVar_0x8004
void BufferFieldPermissionTerm(void); // Special: Wort der Region nach STR_VAR_2

#endif // GUARD_JOHTO_PERMITS_H
