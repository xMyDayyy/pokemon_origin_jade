#include "global.h"
#include "event_data.h"
#include "hoenn_badges.h"

// Hoenn badges as a bitmask in VAR_HOENN_BADGES (bit 0 = Roxanne ... bit 7 = Juan).
// Use these instead of FLAG_BADGE01-08 for Hoenn.

#if defined(POKEMON_HNS)

u32 GetHoennBadgeCount(void)
{
    u32 i, count = 0;
    u16 mask = VarGet(VAR_HOENN_BADGES);

    for (i = 0; i < 8; i++)
    {
        if (mask & (1 << i))
            count++;
    }
    return count;
}

bool32 HasHoennBadge(u32 index)
{
    if (index >= 8)
        return FALSE;
    return (VarGet(VAR_HOENN_BADGES) & (1 << index)) != 0;
}

// Special: badge index (0-7) in gSpecialVar_0x8004
void SetHoennBadge(void)
{
    if (gSpecialVar_0x8004 < 8)
        VarSet(VAR_HOENN_BADGES, VarGet(VAR_HOENN_BADGES) | (1 << gSpecialVar_0x8004));
}

// Special: badge index (0-7) in gSpecialVar_0x8004, result in gSpecialVar_Result
void CheckHoennBadge(void)
{
    gSpecialVar_Result = HasHoennBadge(gSpecialVar_0x8004);
}

// Special: number of Hoenn badges in gSpecialVar_Result
void CountHoennBadges(void)
{
    gSpecialVar_Result = GetHoennBadgeCount();
}

#else

u32 GetHoennBadgeCount(void) { return 0; }
bool32 HasHoennBadge(u32 index) { return FALSE; }
void SetHoennBadge(void) {}
void CheckHoennBadge(void) { gSpecialVar_Result = FALSE; }
void CountHoennBadges(void) { gSpecialVar_Result = 0; }

#endif
