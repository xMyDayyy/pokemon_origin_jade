#include "global.h"
#include "daycare.h"
#include "event_data.h"
#include "pokemon.h"
#include "test/overworld_script.h"
#include "test/test.h"
#include "constants/daycare.h"
#include "constants/region_map_sections.h"

// Day Cares per region, see docs/origin_jade/DECISIONS.md, D-052.

static void SetMapsec(u32 mapsec)
{
    gMapHeader.regionMapSectionId = mapsec;
}

static void StoreFirstPartyMon(void)
{
    struct DayCare *daycare = GetCurrentDaycare();

    StorePokemonInDaycare(&gPlayerParty[0], &daycare->mons[Daycare_FindEmptySpot(daycare)]);
}

TEST("Day Cares: Kanto, Johto and Hoenn keep their own Pokemon")
{
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 10;
        givemon SPECIES_EEVEE, 10;
        givemon SPECIES_ZIGZAGOON, 10;
    );
    SetMapsec(MAPSEC_ROUTE_5);
    StoreFirstPartyMon();
    SetMapsec(MAPSEC_ROUTE_34);
    StoreFirstPartyMon();
    SetMapsec(MAPSEC_ROUTE_117);
    StoreFirstPartyMon();

    SetMapsec(MAPSEC_ROUTE_5);
    EXPECT_EQ(CountPokemonInDaycare(GetCurrentDaycare()), 1);
    EXPECT_EQ(GetBoxMonData(&GetCurrentDaycare()->mons[0].mon, MON_DATA_SPECIES), SPECIES_PIKACHU);
    SetMapsec(MAPSEC_ROUTE_34);
    EXPECT_EQ(CountPokemonInDaycare(GetCurrentDaycare()), 1);
    EXPECT_EQ(GetBoxMonData(&GetCurrentDaycare()->mons[0].mon, MON_DATA_SPECIES), SPECIES_EEVEE);
    SetMapsec(MAPSEC_ROUTE_117);
    EXPECT(GetCurrentDaycare() == &gSaveBlock1Ptr->daycare);
    EXPECT_EQ(CountPokemonInDaycare(GetCurrentDaycare()), 1);
    EXPECT_EQ(GetBoxMonData(&GetCurrentDaycare()->mons[0].mon, MON_DATA_SPECIES), SPECIES_ZIGZAGOON);
}

TEST("Day Cares: a pair in Johto's Day Care lays its egg there")
{
    u32 step;

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_DITTO, 10;
        givemon SPECIES_EEVEE, 10, gender=MON_MALE;
    );
    SetMapsec(MAPSEC_ROUTE_34);
    StoreFirstPartyMon();
    StoreFirstPartyMon();
    for (step = 0; step < 256 * 100 && GetDaycareState() != DAYCARE_EGG_WAITING; step++)
        ShouldEggHatch();
    EXPECT_EQ(GetDaycareState(), DAYCARE_EGG_WAITING);
    // The flag of Hoenn's Day Care stays clear, Hoenn's and Kanto's have no egg.
    EXPECT(!FlagGet(FLAG_PENDING_DAYCARE_EGG));
    SetMapsec(MAPSEC_ROUTE_117);
    EXPECT_EQ(GetDaycareState(), DAYCARE_NO_MONS);
    SetMapsec(MAPSEC_ROUTE_5);
    EXPECT_EQ(GetDaycareState(), DAYCARE_NO_MONS);
}
