#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "region_rule_oj.h"
#include "test/test.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"

// Region rule, see docs/origin_jade/DECISIONS.md, D-049.

static void SetMap(u32 map, u32 mapsec)
{
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(map);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(map);
    gMapHeader.regionMapSectionId = mapsec;
}

TEST("Region rule: species regions")
{
    EXPECT_EQ(GetSpeciesRegion(SPECIES_NONE), REGION_NONE);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_BULBASAUR), REGION_KANTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_PIKACHU), REGION_KANTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_MEW), REGION_KANTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_CHIKORITA), REGION_JOHTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_PICHU), REGION_JOHTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_CROBAT), REGION_JOHTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_CELEBI), REGION_JOHTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_TREECKO), REGION_HOENN);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_AZURILL), REGION_HOENN);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_WYNAUT), REGION_HOENN);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_DEOXYS_SPEED), REGION_HOENN);
    // Later evolutions and babies of Kanto and Johto lines: Johto.
    EXPECT_EQ(GetSpeciesRegion(SPECIES_MAGNEZONE), REGION_JOHTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_HAPPINY), REGION_JOHTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_SYLVEON), REGION_JOHTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_KLEAVOR), REGION_JOHTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_URSALUNA_BLOODMOON), REGION_JOHTO);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_DUDUNSPARCE_THREE_SEGMENT), REGION_JOHTO);
    // Of Hoenn lines: Hoenn.
    EXPECT_EQ(GetSpeciesRegion(SPECIES_BUDEW), REGION_HOENN);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_GALLADE), REGION_HOENN);
    EXPECT_EQ(GetSpeciesRegion(SPECIES_DUSKNOIR), REGION_HOENN);
}

static bool32 IsRegionalForm(u16 species)
{
    return gSpeciesInfo[species].isAlolanForm || gSpeciesInfo[species].isGalarianForm
        || gSpeciesInfo[species].isHisuianForm || gSpeciesInfo[species].isPaldeanForm;
}

// Region of the Gen 1-3 species in the line of a later species: its nearest
// pre-evolution, or for babies what they evolve into. REGION_NONE without one
// or for the lines of regional forms.
static enum Region GetLineRegion(u16 species)
{
    u32 i;
    u16 pre = species;
    const struct Evolution *evos;

    while ((pre = GetSpeciesPreEvolution(pre)) != SPECIES_NONE)
    {
        if (IsRegionalForm(pre))
            return REGION_NONE;
        if (SpeciesToNationalPokedexNum(pre) <= NATIONAL_DEX_DEOXYS)
            return GetSpeciesRegion(pre);
    }
    evos = GetSpeciesEvolutions(species);
    for (i = 0; evos != NULL && evos[i].method != EVOLUTIONS_END; i++)
    {
        u16 target = evos[i].targetSpecies;
        if (!IsRegionalForm(target) && SpeciesToNationalPokedexNum(target) <= NATIONAL_DEX_DEOXYS)
            return GetSpeciesRegion(target);
    }
    return REGION_NONE;
}

TEST("Region rule: babies and later evolutions count to their line's region")
{
    u32 nationalNum, johto = 0, hoenn = 0;

    // The test build enables every family; Origin Jade enables 36 of these.
    for (nationalNum = NATIONAL_DEX_DEOXYS + 1; nationalNum <= NATIONAL_DEX_COUNT; nationalNum++)
    {
        u16 species = NationalPokedexNumToSpecies(nationalNum);
        enum Region line;

        // Regional forms (off in Origin Jade) have national numbers of their own in the test build.
        if (species == SPECIES_NONE || !IsSpeciesEnabled(species) || IsRegionalForm(species))
            continue;
        line = GetLineRegion(species);
        if (line == REGION_NONE)
        {
            EXPECT_EQ(GetSpeciesRegion(species), REGION_HOENN);
        }
        else if (line == REGION_HOENN)
        {
            EXPECT_EQ(GetSpeciesRegion(species), REGION_HOENN);
            hoenn++;
        }
        else
        {
            EXPECT_EQ(GetSpeciesRegion(species), REGION_JOHTO);
            johto++;
        }
    }
    EXPECT_EQ(johto, 29);
    EXPECT_EQ(hoenn, 7);
}

TEST("Region rule: Johto unlocks on the first Johto map after the Kanto title")
{
    u32 mapsec = gMapHeader.regionMapSectionId;

    EXPECT(IsRegionUnlocked(REGION_KANTO));
    EXPECT(!IsRegionUnlocked(REGION_JOHTO));
    EXPECT(!IsSpeciesRegionUnlocked(SPECIES_CHIKORITA));
    EXPECT(IsSpeciesRegionUnlocked(SPECIES_PIKACHU));

    // Before the Kanto title nothing counts.
    SetMap(MAP_ROUTE26_HNS, MAPSEC_ROUTE_26);
    TryUnlockJohtoOnMapLoad();
    EXPECT(!IsRegionUnlocked(REGION_JOHTO));

    // The gatehouse south of Route 23 does not count.
    FlagSet(FLAG_SYS_GAME_CLEAR);
    SetMap(MAP_RECEPTION_GATE_HNS, MAPSEC_VICTORY_ROAD_HNS);
    TryUnlockJohtoOnMapLoad();
    EXPECT(!IsRegionUnlocked(REGION_JOHTO));

    // Kanto maps do not count.
    SetMap(MAP_PALLET_TOWN, MAPSEC_PALLET_TOWN);
    TryUnlockJohtoOnMapLoad();
    EXPECT(!IsRegionUnlocked(REGION_JOHTO));

    SetMap(MAP_ROUTE26_HNS, MAPSEC_ROUTE_26);
    TryUnlockJohtoOnMapLoad();
    EXPECT(FlagGet(FLAG_JOHTO_UNLOCKED));
    EXPECT(IsRegionUnlocked(REGION_JOHTO));
    EXPECT(IsSpeciesRegionUnlocked(SPECIES_CROBAT));
    EXPECT(!IsRegionUnlocked(REGION_HOENN));
    gMapHeader.regionMapSectionId = mapsec;
}

TEST("Region rule: Johto catch-ups and Hoenn")
{
    PARAMETRIZE { FlagSet(FLAG_JOHTO_ARRIVAL_DONE); }
    PARAMETRIZE { VarSet(VAR_JOHTO_HANDOVER, 3); }
    PARAMETRIZE { VarSet(VAR_HOENN_ARRIVAL_STATE, 1); }
    EXPECT(IsRegionUnlocked(REGION_JOHTO));
}

TEST("Region rule: Hoenn unlocks with the first trip there")
{
    VarSet(VAR_JOHTO_HANDOVER, 2);
    EXPECT(!IsRegionUnlocked(REGION_JOHTO));
    EXPECT(!IsSpeciesRegionUnlocked(SPECIES_DUSKULL));
    VarSet(VAR_HOENN_ARRIVAL_STATE, 1);
    EXPECT(IsRegionUnlocked(REGION_HOENN));
    EXPECT(IsSpeciesRegionUnlocked(SPECIES_DUSKULL));
    EXPECT(IsSpeciesRegionUnlocked(SPECIES_DUSKNOIR));
}
