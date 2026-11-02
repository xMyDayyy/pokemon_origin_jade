#include "global.h"
#include "caps.h"
#include "event_data.h"
#include "test/test.h"
#include "constants/region_map_sections.h"

// Badge readers count the region the player stands in, see
// docs/origin_jade/DECISIONS.md D-007, D-053.

TEST("Region badges: each region counts its own badges")
{
    u32 i;

    for (i = FLAG_BADGE01_GET; i <= FLAG_BADGE08_GET; i++)
        FlagSet(i);
    VarSet(VAR_JOHTO_BADGES, 0x07);
    VarSet(VAR_HOENN_BADGES, 0x01);
    EXPECT_EQ(GetRegionBadgeCount(MAPSEC_PALLET_TOWN), 8);
    EXPECT_EQ(GetRegionBadgeCount(MAPSEC_ROUTE_29), 3);
    EXPECT_EQ(GetRegionBadgeCount(MAPSEC_ROUTE_101), 1);
    VarSet(VAR_JOHTO_BADGES, 0);
    VarSet(VAR_HOENN_BADGES, 0);
}
