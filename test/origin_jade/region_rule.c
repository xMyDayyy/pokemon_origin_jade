#include "global.h"
#include "daycare.h"
#include "event_data.h"
#include "pokedex.h"
#include "pokemon.h"
#include "region_rule_oj.h"
#include "test/overworld_script.h"
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

TEST("Region rule: Day Care eggs before the unlock hatch as the first unlocked stage")
{
    // Kanto only.
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_PICHU, SPECIES_RAICHU), SPECIES_PIKACHU);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_PICHU, SPECIES_PIKACHU), SPECIES_PIKACHU);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_HAPPINY, SPECIES_BLISSEY), SPECIES_CHANSEY);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_MUNCHLAX, SPECIES_SNORLAX), SPECIES_SNORLAX);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_TYROGUE, SPECIES_HITMONCHAN), SPECIES_HITMONCHAN);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_TYROGUE, SPECIES_HITMONLEE), SPECIES_HITMONLEE);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_BULBASAUR, SPECIES_VENUSAUR), SPECIES_BULBASAUR);
    // No stage of the line unlocked: the egg keeps its species.
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_TYROGUE, SPECIES_HITMONTOP), SPECIES_TYROGUE);

    // Johto unlocked, Hoenn not.
    FlagSet(FLAG_JOHTO_UNLOCKED);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_PICHU, SPECIES_RAICHU), SPECIES_PICHU);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_AZURILL, SPECIES_AZUMARILL), SPECIES_MARILL);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_WYNAUT, SPECIES_WOBBUFFET), SPECIES_WOBBUFFET);

    // Hoenn unlocked.
    VarSet(VAR_HOENN_ARRIVAL_STATE, 1);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_AZURILL, SPECIES_AZUMARILL), SPECIES_AZURILL);
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_WYNAUT, SPECIES_WOBBUFFET), SPECIES_WYNAUT);
}

TEST("Region rule: Day Care eggs keep their species with randomized species")
{
    PARAMETRIZE { gSaveBlock3Ptr->challengeSettings.tx_Random_WildPokemon = TRUE; }
    PARAMETRIZE { gSaveBlock3Ptr->challengeSettings.tx_Random_Static = TRUE; }
    PARAMETRIZE { gSaveBlock3Ptr->challengeSettings.tx_Random_Starter = TRUE; }
    PARAMETRIZE { gSaveBlock3Ptr->challengeSettings.tx_Random_Evolutions = TRUE; }
    EXPECT_EQ(GetUnlockedEggSpecies(SPECIES_PICHU, SPECIES_RAICHU), SPECIES_PICHU);
}

TEST("Region rule: a Pikachu pair in Kanto's Day Care gives a Pikachu egg")
{
    u32 egg = 0;

    PARAMETRIZE { egg = SPECIES_PIKACHU; }
    PARAMETRIZE { egg = SPECIES_PICHU; FlagSet(FLAG_JOHTO_UNLOCKED); }
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100, gender=MON_MALE;
        givemon SPECIES_PIKACHU, 100, gender=MON_FEMALE;
    );
    StorePokemonInDaycare(&gPlayerParty[0], &gSaveBlock1Ptr->daycare.mons[0]);
    StorePokemonInDaycare(&gPlayerParty[0], &gSaveBlock1Ptr->daycare.mons[1]);
    RUN_OVERWORLD_SCRIPT( special GiveEggFromDaycare; );
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), egg);
}

TEST("Region rule: species seen in battle wait for their region unless caught")
{
    EXPECT(CanRegisterSeenSpecies(SPECIES_ZUBAT));
    EXPECT(CanRegisterSeenSpecies(SPECIES_GOLBAT));
    EXPECT(!CanRegisterSeenSpecies(SPECIES_CROBAT));
    EXPECT(!CanRegisterSeenSpecies(SPECIES_DUSKULL));

    GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_CROBAT), FLAG_SET_CAUGHT);
    EXPECT(CanRegisterSeenSpecies(SPECIES_CROBAT));

    FlagSet(FLAG_JOHTO_UNLOCKED);
    EXPECT(CanRegisterSeenSpecies(SPECIES_CHIKORITA));
    EXPECT(!CanRegisterSeenSpecies(SPECIES_DUSKULL));
    VarSet(VAR_HOENN_ARRIVAL_STATE, 1);
    EXPECT(CanRegisterSeenSpecies(SPECIES_DUSKULL));
}

TEST("Region rule: species seen in battle count at once with randomized species")
{
    PARAMETRIZE { gSaveBlock3Ptr->challengeSettings.tx_Random_WildPokemon = TRUE; }
    PARAMETRIZE { gSaveBlock3Ptr->challengeSettings.tx_Random_Static = TRUE; }
    PARAMETRIZE { gSaveBlock3Ptr->challengeSettings.tx_Random_Starter = TRUE; }
    PARAMETRIZE { gSaveBlock3Ptr->challengeSettings.tx_Random_Evolutions = TRUE; }
    EXPECT(CanRegisterSeenSpecies(SPECIES_CHIKORITA));
    EXPECT(CanRegisterSeenSpecies(SPECIES_DUSKULL));
}

TEST("Region rule: random trainers alone keep the seen rule")
{
    gSaveBlock3Ptr->challengeSettings.tx_Random_Trainer = TRUE;
    EXPECT(!CanRegisterSeenSpecies(SPECIES_DUSKULL));
}
