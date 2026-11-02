#include "global.h"
#include "debug.h"
#include "wild_encounter.h"
#include "constants/wild_encounter.h"
#include "test/test.h"

// Debug menu toggle "Even Wild Slots" (src/wild_encounter.c), see
// docs/origin_jade/DECISIONS.md, D-055.

// Draws of a slot function; every slot of the table comes up about equally often.
#define EXPECT_EVEN_SLOTS(choose, count, draws) \
    do \
    { \
        u32 _i, _counts[count] = {0}; \
        for (_i = 0; _i < (draws); _i++) \
            _counts[choose()]++; \
        for (_i = 0; _i < (count); _i++) \
            EXPECT_GT(_counts[_i], (draws) / (count) / 2); \
    } while (0)

TEST("Even Wild Slots: every land, water and Rock Smash slot equally likely")
{
    gDebugEvenWildSlots = TRUE;
    EXPECT_EVEN_SLOTS(ChooseWildMonIndex_Land, LAND_WILD_COUNT, 1200);
    EXPECT_EVEN_SLOTS(ChooseWildMonIndex_Water, WATER_WILD_COUNT, 500);
    EXPECT_EVEN_SLOTS(ChooseWildMonIndex_Rocks, ROCK_WILD_COUNT, 500);
    gDebugEvenWildSlots = FALSE;
}

TEST("Even Wild Slots: off, the last land slot keeps its 1 percent")
{
    u32 i, last = 0;

    gDebugEvenWildSlots = FALSE;
    for (i = 0; i < 1200; i++)
    {
        if (ChooseWildMonIndex_Land() == LAND_WILD_COUNT - 1)
            last++;
    }
    EXPECT_LT(last, 50);
}
