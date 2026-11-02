#include "global.h"
#include "event_data.h"
#include "pokedex.h"
#include "pokemon.h"
#include "randomizer.h"
#include "region_rule_oj.h"
#include "regions.h"
#include "constants/maps.h"
#include "constants/pokedex.h"

// Region rule, see docs/origin_jade/DECISIONS.md, D-049.

#if IS_HNS

// National numbers above 386 that the build enables: region of their line.
// tools/check_regions.py reads this table.
static const struct
{
    u16 nationalNum;
    u8 region;
} sLaterSpeciesRegions[] =
{
    { NATIONAL_DEX_BUDEW,       REGION_HOENN },
    { NATIONAL_DEX_ROSERADE,    REGION_HOENN },
    { NATIONAL_DEX_AMBIPOM,     REGION_JOHTO },
    { NATIONAL_DEX_MISMAGIUS,   REGION_JOHTO },
    { NATIONAL_DEX_HONCHKROW,   REGION_JOHTO },
    { NATIONAL_DEX_CHINGLING,   REGION_HOENN },
    { NATIONAL_DEX_BONSLY,      REGION_JOHTO },
    { NATIONAL_DEX_MIME_JR,     REGION_JOHTO },
    { NATIONAL_DEX_HAPPINY,     REGION_JOHTO },
    { NATIONAL_DEX_MUNCHLAX,    REGION_JOHTO },
    { NATIONAL_DEX_MANTYKE,     REGION_JOHTO },
    { NATIONAL_DEX_WEAVILE,     REGION_JOHTO },
    { NATIONAL_DEX_MAGNEZONE,   REGION_JOHTO },
    { NATIONAL_DEX_LICKILICKY,  REGION_JOHTO },
    { NATIONAL_DEX_RHYPERIOR,   REGION_JOHTO },
    { NATIONAL_DEX_TANGROWTH,   REGION_JOHTO },
    { NATIONAL_DEX_ELECTIVIRE,  REGION_JOHTO },
    { NATIONAL_DEX_MAGMORTAR,   REGION_JOHTO },
    { NATIONAL_DEX_TOGEKISS,    REGION_JOHTO },
    { NATIONAL_DEX_YANMEGA,     REGION_JOHTO },
    { NATIONAL_DEX_LEAFEON,     REGION_JOHTO },
    { NATIONAL_DEX_GLACEON,     REGION_JOHTO },
    { NATIONAL_DEX_GLISCOR,     REGION_JOHTO },
    { NATIONAL_DEX_MAMOSWINE,   REGION_JOHTO },
    { NATIONAL_DEX_PORYGON_Z,   REGION_JOHTO },
    { NATIONAL_DEX_GALLADE,     REGION_HOENN },
    { NATIONAL_DEX_PROBOPASS,   REGION_HOENN },
    { NATIONAL_DEX_DUSKNOIR,    REGION_HOENN },
    { NATIONAL_DEX_FROSLASS,    REGION_HOENN },
    { NATIONAL_DEX_SYLVEON,     REGION_JOHTO },
    { NATIONAL_DEX_WYRDEER,     REGION_JOHTO },
    { NATIONAL_DEX_KLEAVOR,     REGION_JOHTO },
    { NATIONAL_DEX_URSALUNA,    REGION_JOHTO },
    { NATIONAL_DEX_ANNIHILAPE,  REGION_JOHTO },
    { NATIONAL_DEX_FARIGIRAF,   REGION_JOHTO },
    { NATIONAL_DEX_DUDUNSPARCE, REGION_JOHTO },
};

enum Region GetSpeciesRegion(u16 species)
{
    u32 i;
    u32 nationalNum = SpeciesToNationalPokedexNum(species);

    if (nationalNum == NATIONAL_DEX_NONE)
        return REGION_NONE;
    if (nationalNum <= NATIONAL_DEX_MEW)
        return REGION_KANTO;
    if (nationalNum <= NATIONAL_DEX_CELEBI)
        return REGION_JOHTO;
    if (nationalNum <= NATIONAL_DEX_DEOXYS)
        return REGION_HOENN;
    for (i = 0; i < ARRAY_COUNT(sLaterSpeciesRegions); i++)
    {
        if (sLaterSpeciesRegions[i].nationalNum == nationalNum)
            return sLaterSpeciesRegions[i].region;
    }
    // Other lines of later generations: Hoenn, the last region.
    return REGION_HOENN;
}

bool32 IsRegionUnlocked(enum Region region)
{
    switch (region)
    {
    case REGION_JOHTO:
        // Catch-ups: arrival in New Bark Town, GS Ball delivered, Hoenn reached.
        return FlagGet(FLAG_JOHTO_UNLOCKED)
            || FlagGet(FLAG_JOHTO_ARRIVAL_DONE)
            || VarGet(VAR_JOHTO_HANDOVER) >= 3
            || IsRegionUnlocked(REGION_HOENN);
    case REGION_HOENN:
        return VarGet(VAR_HOENN_ARRIVAL_STATE) >= 1;
    default:
        return TRUE;
    }
}

bool32 IsSpeciesRegionUnlocked(u16 species)
{
    return IsRegionUnlocked(GetSpeciesRegion(species));
}

void TryUnlockJohtoOnMapLoad(void)
{
    if (FlagGet(FLAG_JOHTO_UNLOCKED) || !FlagGet(FLAG_SYS_GAME_CLEAR))
        return;
    if (GetCurrentRegion() != REGION_JOHTO)
        return;
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_RECEPTION_GATE_HNS)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_RECEPTION_GATE_HNS))
        return;
    FlagSet(FLAG_JOHTO_UNLOCKED);
}

// TRUE while any randomizer option randomizes something; the region rule is off then.
static bool32 IsAnyRandomizerOptionOn(void)
{
#if RANDOMIZER_AVAILABLE
    enum RandomizerFeature feature;

    for (feature = RANDOMIZE_WILD_MON; feature <= RANDOMIZE_TYPE_EFFECTIVENESS; feature++)
    {
        if (RandomizerFeatureEnabled(feature))
            return TRUE;
    }
#endif
    return FALSE;
}

u16 GetUnlockedEggSpecies(u16 eggSpecies, u16 parentSpecies)
{
    u16 line[8];
    u32 count = 0;
    u16 species = parentSpecies;

    if (IsSpeciesRegionUnlocked(eggSpecies) || IsAnyRandomizerOptionOn())
        return eggSpecies;
    // The line from the parent back to the egg species.
    while (species != SPECIES_NONE && count < ARRAY_COUNT(line))
    {
        line[count++] = species;
        if (species == eggSpecies)
            break;
        species = GetSpeciesPreEvolution(species);
    }
    if (count == 0 || line[count - 1] != eggSpecies)
        return eggSpecies;
    while (count-- > 0)
    {
        if (IsSpeciesRegionUnlocked(line[count]))
            return line[count];
    }
    // No stage of the line unlocked (a Hitmontop parent before Johto): the egg stays.
    return eggSpecies;
}

bool32 CanRegisterSeenSpecies(u16 species)
{
    return IsSpeciesRegionUnlocked(species)
        || IsAnyRandomizerOptionOn()
        || GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT);
}

#else

enum Region GetSpeciesRegion(u16 species) { return REGION_NONE; }
bool32 IsRegionUnlocked(enum Region region) { return TRUE; }
bool32 IsSpeciesRegionUnlocked(u16 species) { return TRUE; }
void TryUnlockJohtoOnMapLoad(void) {}
u16 GetUnlockedEggSpecies(u16 eggSpecies, u16 parentSpecies) { return eggSpecies; }
bool32 CanRegisterSeenSpecies(u16 species) { return TRUE; }

#endif
