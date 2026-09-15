#include "global.h"
#include "event_data.h"
#include "johto_badges.h"
#include "constants/vars.h"

// Johto-Ordensystem: eigene Bitmaske in VAR_JOHTO_BADGES, getrennt von den
// Ordensflags FLAG_BADGE01-08 (die teilt sich Johto mit Kanto und sie sind
// nach der Kanto-Liga laengst alle gesetzt). Fuettert Gehorsamsgrenzen,
// Arenagatter, Trainerpass und die Rueckkampfskalierung.

#if defined(POKEMON_HNS)

u32 GetJohtoBadgeCount(void)
{
    u32 i, count = 0;
    u16 mask = VarGet(VAR_JOHTO_BADGES);

    for (i = 0; i < 8; i++)
    {
        if (mask & (1 << i))
            count++;
    }
    return count;
}

bool32 HasJohtoBadge(u32 index)
{
    if (index >= 8)
        return FALSE;
    return (VarGet(VAR_JOHTO_BADGES) & (1 << index)) != 0;
}

// Special: Ordenindex (0-7) in gSpecialVar_0x8004
void SetJohtoBadge(void)
{
    if (gSpecialVar_0x8004 < 8)
        VarSet(VAR_JOHTO_BADGES, VarGet(VAR_JOHTO_BADGES) | (1 << gSpecialVar_0x8004));
}

// Special: Ordenindex (0-7) in gSpecialVar_0x8004, Ergebnis nach
// gSpecialVar_Result. Ersetzt in Johto-Skripten die FLAG_BADGE0x_GET-Abfragen.
void CheckJohtoBadge(void)
{
    gSpecialVar_Result = HasJohtoBadge(gSpecialVar_0x8004);
}

// Special: Anzahl der Johto-Orden nach gSpecialVar_Result
void CountJohtoBadges(void)
{
    gSpecialVar_Result = GetJohtoBadgeCount();
}

#else

u32 GetJohtoBadgeCount(void) { return 0; }
bool32 HasJohtoBadge(u32 index) { return FALSE; }
void SetJohtoBadge(void) {}
void CheckJohtoBadge(void) { gSpecialVar_Result = FALSE; }
void CountJohtoBadges(void) { gSpecialVar_Result = 0; }

#endif
