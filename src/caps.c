#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "caps.h"
#include "hoenn_badges.h"
#include "johto_badges.h"
#include "pokemon.h"
#include "regions.h"

u8 GetCurrentBadgeCount(void)
{
    u16 i;
    u8 badgeCount = 0;
    for (i = FLAG_BADGE01_GET; i < FLAG_BADGE01_GET + NUM_BADGES; i++)
    {
        if (FlagGet(i))
            badgeCount++;
    }
    return badgeCount;
}

u32 GetKantoBadgeCount(void)
{
    u32 i, count = 0;

    for (i = FLAG_BADGE01_GET; i <= FLAG_BADGE08_GET; i++)
    {
        if (FlagGet(i))
            count++;
    }
    return count;
}

u32 GetRegionBadgeCount(u32 mapSecId)
{
#if IS_HNS
    switch (GetRegionForSectionId(mapSecId))
    {
    case REGION_JOHTO:
        return GetJohtoBadgeCount();
    case REGION_HOENN:
        return GetHoennBadgeCount();
    default:
        break;
    }
#endif
    return GetKantoBadgeCount();
}

u32 GetCurrentRegionBadgeCount(void)
{
    return GetRegionBadgeCount(gMapHeader.regionMapSectionId);
}

// Kanto badges (Kanto level ladder): the next leader's ace, after eight badges the champion's.
static const u8 sLevelCapTable_Normal[] =
{
    [0] = 12,  // no badges
    [1] = 17,  // badge 1
    [2] = 19,  // badge 2
    [3] = 22,  // badge 3
    [4] = 33,  // badge 4
    [5] = 33,  // badge 5
    [6] = 35,  // badge 6
    [7] = 38,  // badge 7
    [8] = 47,  // badge 8
};

// The next leader's lowest level, after eight badges the champion's.
static const u8 sLevelCapTable_Hard[] =
{
    [0] = 11,
    [1] = 16,
    [2] = 17,
    [3] = 21,
    [4] = 31,
    [5] = 31,
    [6] = 34,
    [7] = 36,
    [8] = 46,
};

#if IS_HNS
// Johto badges (VAR_JOHTO_BADGES), from the Kanto title on. Fixed levels of
// config/level_remap.h (HnS levels, Johto ladder 3-56 -> 44-73), first teams.
// Chuck, Jasmine and Pryce can come in any order, their teams follow how many of
// the three are beaten (_1, _1_2, _1_3): normal takes the highest ace of the
// possible next leaders, hard the lowest level of the weakest of them.
// After eight badges Lance (champion).
static const u8 sJohtoLevelCapTable_Normal[] =
{
    [0] = 48,  // Falkner
    [1] = 51,  // Bugsy
    [2] = 54,  // Whitney
    [3] = 56,  // Morty
    [4] = 62,  // Chuck 59, Jasmine 62, Pryce 60
    [5] = 62,  // second of the three: 62 each
    [6] = 63,  // third of the three: 63 each
    [7] = 67,  // Clair
    [8] = 73,  // Lance
};

static const u8 sJohtoLevelCapTable_Hard[] =
{
    [0] = 47,
    [1] = 51,
    [2] = 53,
    [3] = 55,
    [4] = 58,  // Chuck 58, Pryce 59, Jasmine 62
    [5] = 60,  // Pryce 60, Chuck 61, Jasmine 62
    [6] = 63,
    [7] = 65,
    [8] = 72,
};

// Hoenn badges, from the Johto title on (Emerald levels as in HnS, Hoenn ladder
// 3-58 -> 67-100). After eight badges Wallace (champion).
static const u8 sHoennLevelCapTable_Normal[] =
{
    [0] = 75,  // Roxanne
    [1] = 77,  // Brawly
    [2] = 80,  // Wattson
    [3] = 83,  // Flannery
    [4] = 85,  // Norman
    [5] = 85,  // Winona
    [6] = 90,  // Tate and Liza
    [7] = 93,  // Juan
    [8] = 100, // Wallace
};

static const u8 sHoennLevelCapTable_Hard[] =
{
    [0] = 74,
    [1] = 75,
    [2] = 77,
    [3] = 80,
    [4] = 83,
    [5] = 83,
    [6] = 89,
    [7] = 90,
    [8] = 98,
};

static u32 GetLadderCap(const u8 *normal, const u8 *hard, u32 badgeCount, u8 challengeLevelCap)
{
    if (badgeCount > 8)
        badgeCount = 8;
    return challengeLevelCap == 1 ? normal[badgeCount] : hard[badgeCount];
}
#endif

u32 GetCurrentLevelCap(void)
{
    static const u32 sLevelCapFlagMap[][2] =
    {
        {FLAG_BADGE01_GET, 15},
        {FLAG_BADGE02_GET, 19},
        {FLAG_BADGE03_GET, 24},
        {FLAG_BADGE04_GET, 29},
        {FLAG_BADGE05_GET, 31},
        {FLAG_BADGE06_GET, 33},
        {FLAG_BADGE07_GET, 42},
        {FLAG_BADGE08_GET, 46},
        {FLAG_IS_CHAMPION, 58},
    };

    u8 challengeLevelCap = gSaveBlock3Ptr->challengeSettings.tx_Challenges_LevelCap;

    if (challengeLevelCap != 0)
    {
        u8 badgeCount = GetCurrentBadgeCount();
        if (badgeCount > 8)
            badgeCount = 8;

#if IS_HNS
        // One ladder per region in Origin Jade's order (Kanto, Johto, Hoenn), each by
        // the badges of its own region. After the last title no cap.
        if (FlagGet(FLAG_IS_HOENN_CHAMPION))
            return MAX_LEVEL;
        if (FlagGet(FLAG_IS_JOHTO_CHAMPION))
            return GetLadderCap(sHoennLevelCapTable_Normal, sHoennLevelCapTable_Hard, GetHoennBadgeCount(), challengeLevelCap);
        if (FlagGet(FLAG_IS_KANTO_CHAMPION))
            return GetLadderCap(sJohtoLevelCapTable_Normal, sJohtoLevelCapTable_Hard, GetJohtoBadgeCount(), challengeLevelCap);
#else
        if (FlagGet(FLAG_IS_CHAMPION))
            return MAX_LEVEL;
#endif

        if (challengeLevelCap == 1)
            return sLevelCapTable_Normal[badgeCount];
        else
            return sLevelCapTable_Hard[badgeCount];
    }

    u32 i;

    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
                return sLevelCapFlagMap[i][1];
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    return MAX_LEVEL;
}

u32 GetSoftLevelCapExpValue(u32 level, u32 expValue)
{
    static const u32 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
    static const u32 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

    u32 levelDifference;
    u32 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (level < currentLevelCap)
    {
        if (B_LEVEL_CAP_EXP_UP)
        {
            levelDifference = currentLevelCap - level;
            if (levelDifference > ARRAY_COUNT(sExpScalingUp) - 1)
                return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingUp) - 1]);
            else
                return expValue + (expValue / sExpScalingUp[levelDifference]);
        }
        else
        {
            return expValue;
        }
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_HARD)
    {
        return 0;
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown) - 1)
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else
    {
       return expValue;
    }
}

u32 GetCurrentEVCap(void)
{
    static const u16 sEvCapFlagMap[][2] = {
        // Define EV caps for each milestone
        {FLAG_BADGE01_GET, MAX_TOTAL_EVS *  1 / 17},
        {FLAG_BADGE02_GET, MAX_TOTAL_EVS *  3 / 17},
        {FLAG_BADGE03_GET, MAX_TOTAL_EVS *  5 / 17},
        {FLAG_BADGE04_GET, MAX_TOTAL_EVS *  7 / 17},
        {FLAG_BADGE05_GET, MAX_TOTAL_EVS *  9 / 17},
        {FLAG_BADGE06_GET, MAX_TOTAL_EVS * 11 / 17},
        {FLAG_BADGE07_GET, MAX_TOTAL_EVS * 13 / 17},
        {FLAG_BADGE08_GET, MAX_TOTAL_EVS * 15 / 17},
        {FLAG_IS_CHAMPION, MAX_TOTAL_EVS},
    };

    if (B_EV_CAP_TYPE == EV_CAP_FLAG_LIST)
    {
        for (u32 evCap = 0; evCap < ARRAY_COUNT(sEvCapFlagMap); evCap++)
        {
            if (!FlagGet(sEvCapFlagMap[evCap][0]))
                return sEvCapFlagMap[evCap][1];
        }
    }
    else if (B_EV_CAP_TYPE == EV_CAP_VARIABLE)
    {
        return VarGet(B_EV_CAP_VARIABLE);
    }
    else if (B_EV_CAP_TYPE == EV_CAP_NO_GAIN)
    {
        return 0;
    }

    return MAX_TOTAL_EVS;
}
