#include "global.h"
#include "level_scaling.h"
#include "data.h"
#include "overworld.h"
#include "pokemon.h"
#include "random.h"
#include "event_data.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"
#include "config/hoenn_scaling.h"
#include "config/johto_scaling.h"
#include "config/kanto_scaling.h"

// =====================================================================
// Level scaling, rules in config/hoenn_scaling.h, config/johto_scaling.h
// and config/kanto_scaling.h.
// Hoenn: every mapsec where IsHoennMapsec is TRUE, unlisted ones use the
// default corridor. Johto: only the mapsecs in its corridor table.
// Kanto: FRLG maps (IsFrlgKantoMap), only after the Kanto title.
// After a region's title its corridors lose their ceiling, see
// docs/origin_jade/DECISIONS.md, D-031.
// =====================================================================

#if defined(POKEMON_HNS)

bool32 IsHoennMapsec(u32 mapSecId)
{
    if (mapSecId >= MAPSEC_LITTLEROOT_TOWN && mapSecId < MAPSEC_NONE)
        return TRUE;
    // Hoenn mapsecs inside the Johto/Kanto number range
    if (mapSecId == MAPSEC_VICTORY_ROAD
     || mapSecId == MAPSEC_SAFARI_ZONE
     || mapSecId == MAPSEC_ABANDONED_SHIP
     || mapSecId == MAPSEC_LILYCOVE_CITY)
        return TRUE;
    return FALSE;
}

#else

bool32 IsHoennMapsec(u32 mapSecId)
{
    return FALSE;
}

#endif

#if defined(POKEMON_HNS) && (HOENN_LEVEL_SCALING == TRUE || JOHTO_LEVEL_SCALING == TRUE || KANTO_LEVEL_SCALING == TRUE)

struct ScalingCorridor
{
    u16 mapsec;
    u8 floor;
    u8 ceiling;
};

struct ScalingRules
{
    const struct ScalingCorridor *corridors;
    u16 corridorCount;
    u8 trainerBelow;
    u8 trainerAbove;
    u8 wildBelow;
    u8 wildAbove;
    u8 bossExtra;
    u8 fixedMinLevel;
    u8 evoOtherLevel;
    u8 minLevel;
    u8 maxLevel;
    u8 defaultFloor;
    u8 defaultCeiling;
    bool8 trainerEvolve;
    // TRUE: only mapsecs in the corridor table scale (Johto).
    // FALSE: IsHoennMapsec / IsFrlgKantoMap decide, unlisted mapsecs use the defaults.
    bool8 corridorListIsRegion;
    // TRUE: never below the level from the party/encounter data (Kanto).
    bool8 originalLevelIsFloor;
    // Once this title flag is set, titleCeiling replaces every ceiling.
    u16 titleFlag;
    u8 titleCeiling;
};

#if HOENN_LEVEL_SCALING == TRUE
static const struct ScalingCorridor sHoennCorridors[] =
{
    HOENN_SCALING_CORRIDORS
};

static const struct ScalingRules sHoennRules =
{
    .corridors           = sHoennCorridors,
    .corridorCount       = ARRAY_COUNT(sHoennCorridors),
    .trainerBelow        = HOENN_SCALING_TRAINER_BELOW,
    .trainerAbove        = HOENN_SCALING_TRAINER_ABOVE,
    .wildBelow           = HOENN_SCALING_WILD_BELOW,
    .wildAbove           = HOENN_SCALING_WILD_ABOVE,
    .bossExtra           = HOENN_SCALING_BOSS_EXTRA,
    .fixedMinLevel       = HOENN_SCALING_FIXED_MIN_LEVEL,
    .evoOtherLevel       = HOENN_SCALING_EVO_OTHER_LEVEL,
    .minLevel            = HOENN_SCALING_MIN_LEVEL,
    .maxLevel            = HOENN_SCALING_MAX_LEVEL,
    .defaultFloor        = HOENN_SCALING_DEFAULT_FLOOR,
    .defaultCeiling      = HOENN_SCALING_DEFAULT_CEILING,
    .trainerEvolve       = HOENN_SCALING_TRAINER_EVOLVE,
    .corridorListIsRegion = FALSE,
    .originalLevelIsFloor = FALSE,
    .titleFlag           = FLAG_IS_HOENN_CHAMPION,
    .titleCeiling        = HOENN_SCALING_TITLE_CEILING,
};
#endif

#if JOHTO_LEVEL_SCALING == TRUE
static const struct ScalingCorridor sJohtoCorridors[] =
{
    JOHTO_SCALING_CORRIDORS
};

static const struct ScalingRules sJohtoRules =
{
    .corridors           = sJohtoCorridors,
    .corridorCount       = ARRAY_COUNT(sJohtoCorridors),
    .trainerBelow        = JOHTO_SCALING_TRAINER_BELOW,
    .trainerAbove        = JOHTO_SCALING_TRAINER_ABOVE,
    .wildBelow           = JOHTO_SCALING_WILD_BELOW,
    .wildAbove           = JOHTO_SCALING_WILD_ABOVE,
    .bossExtra           = JOHTO_SCALING_BOSS_EXTRA,
    .fixedMinLevel       = JOHTO_SCALING_FIXED_MIN_LEVEL,
    .evoOtherLevel       = JOHTO_SCALING_EVO_OTHER_LEVEL,
    .minLevel            = JOHTO_SCALING_MIN_LEVEL,
    .maxLevel            = JOHTO_SCALING_MAX_LEVEL,
    .defaultFloor        = JOHTO_SCALING_DEFAULT_FLOOR,
    .defaultCeiling      = JOHTO_SCALING_DEFAULT_CEILING,
    .trainerEvolve       = JOHTO_SCALING_TRAINER_EVOLVE,
    .corridorListIsRegion = TRUE,
    .originalLevelIsFloor = FALSE,
    .titleFlag           = FLAG_IS_JOHTO_CHAMPION,
    .titleCeiling        = JOHTO_SCALING_TITLE_CEILING,
};
#endif

#if KANTO_LEVEL_SCALING == TRUE
// No corridors: from the hand-set level up to the absolute maximum.
static const struct ScalingRules sKantoRules =
{
    .corridors           = NULL,
    .corridorCount       = 0,
    .trainerBelow        = KANTO_SCALING_TRAINER_BELOW,
    .trainerAbove        = KANTO_SCALING_TRAINER_ABOVE,
    .wildBelow           = KANTO_SCALING_WILD_BELOW,
    .wildAbove           = KANTO_SCALING_WILD_ABOVE,
    .bossExtra           = KANTO_SCALING_BOSS_EXTRA,
    .fixedMinLevel       = KANTO_SCALING_FIXED_MIN_LEVEL,
    .evoOtherLevel       = KANTO_SCALING_EVO_OTHER_LEVEL,
    .minLevel            = KANTO_SCALING_MIN_LEVEL,
    .maxLevel            = KANTO_SCALING_MAX_LEVEL,
    .defaultFloor        = KANTO_SCALING_MIN_LEVEL,
    .defaultCeiling      = KANTO_SCALING_MAX_LEVEL,
    .trainerEvolve       = KANTO_SCALING_TRAINER_EVOLVE,
    .corridorListIsRegion = FALSE,
    .originalLevelIsFloor = TRUE,
    .titleFlag           = FLAG_IS_KANTO_CHAMPION,
    .titleCeiling        = KANTO_SCALING_MAX_LEVEL,
};
#endif

// FRLG Kanto map: a Kanto mapsec outside HnS's map groups, which come first in
// data/maps/map_groups.json (before Emerald's, MAP_LITTLEROOT_TOWN). Johto's league
// maps (Kanto mapsec) keep the Johto rules; Route22_hns has no corridor and is not scaled.
static bool32 IsFrlgKantoMap(void)
{
    u32 mapsec = gMapHeader.regionMapSectionId;

    if (mapsec < KANTO_MAPSEC_START || mapsec > KANTO_MAPSEC_END)
        return FALSE;
    return gSaveBlock1Ptr->location.mapGroup >= MAP_GROUP(MAP_LITTLEROOT_TOWN);
}

// Leaves floor/ceiling untouched if the mapsec has no corridor.
static bool32 FindCorridor(const struct ScalingRules *rules, u16 mapsec, u8 *floor, u8 *ceiling)
{
    u32 i;

    for (i = 0; i < rules->corridorCount; i++)
    {
        if (rules->corridors[i].mapsec == mapsec)
        {
            if (floor != NULL)
                *floor = rules->corridors[i].floor;
            if (ceiling != NULL)
                *ceiling = rules->corridors[i].ceiling;
            return TRUE;
        }
    }
    return FALSE;
}

// NULL = no scaling on the current map.
static const struct ScalingRules *GetScalingRules(void)
{
    u16 mapsec = gMapHeader.regionMapSectionId;

    // Kanto's first run keeps the hand-set levels (D-011); scaling starts with
    // the Kanto title (D-031).
    if (IsFrlgKantoMap())
    {
#if KANTO_LEVEL_SCALING == TRUE
        if (FlagGet(sKantoRules.titleFlag))
            return &sKantoRules;
#endif
        return NULL;
    }
#if JOHTO_LEVEL_SCALING == TRUE
    if (FindCorridor(&sJohtoRules, mapsec, NULL, NULL))
        return &sJohtoRules;
#endif
#if HOENN_LEVEL_SCALING == TRUE
    if (IsHoennMapsec(mapsec))
        return &sHoennRules;
#endif
    return NULL;
}

bool32 LevelScalingActive(void)
{
    return GetScalingRules() != NULL;
}

// Anchor: highest level in the party, eggs excluded (0 = no Pokemon).
static u8 GetScalingAnchor(void)
{
    u32 i;
    u8 best = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            continue;
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL))
            continue;
        if (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL, NULL) > best)
            best = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL, NULL);
    }
    return best;
}

static void GetCorridor(const struct ScalingRules *rules, u8 *floor, u8 *ceiling)
{
    *floor = rules->defaultFloor;
    *ceiling = rules->defaultCeiling;
    FindCorridor(rules, gMapHeader.regionMapSectionId, floor, ceiling);
    // After the region's title only the floor stays (D-031).
    if (FlagGet(rules->titleFlag) && *ceiling < rules->titleCeiling)
        *ceiling = rules->titleCeiling;
}

static u8 ClampScaledLevel(const struct ScalingRules *rules, s32 level, u8 floor, u8 ceiling)
{
    if (level < floor)
        level = floor;
    if (level > ceiling)
        level = ceiling;
    if (level < rules->minLevel)
        level = rules->minLevel;
    if (level > rules->maxLevel)
        level = rules->maxLevel;
    return level;
}

u8 ScaleWildMonLevel(u8 level)
{
    const struct ScalingRules *rules = GetScalingRules();
    s32 anchor, scaled, width;
    u8 floor, ceiling;

    if (rules == NULL)
        return level;
    anchor = GetScalingAnchor();
    if (anchor == 0)
        return level;

    // Wild band: anchor - BELOW .. anchor - ABOVE, uniformly distributed.
    width = rules->wildBelow - rules->wildAbove + 1;
    scaled = anchor - rules->wildBelow + (s32)(Random() % width);

    GetCorridor(rules, &floor, &ceiling);
    scaled = ClampScaledLevel(rules, scaled, floor, ceiling);
    if (rules->originalLevelIsFloor && scaled < level)
        scaled = level;
    return scaled;
}


// Trainer Pokemon only: evolves up to two steps if the scaled level allows it.
u16 ScaleTrainerMonSpecies(u16 species, u8 scaledLevel)
{
    const struct ScalingRules *rules = GetScalingRules();
    u32 step, i;

    if (rules == NULL || rules->trainerEvolve != TRUE)
        return species;

    for (step = 0; step < 2; step++)
    {
        const struct Evolution *evos = GetSpeciesEvolutions(species);
        u16 candidates[8];
        u32 count = 0;

        if (evos == NULL)
            break;
        for (i = 0; evos[i].method != EVOLUTIONS_END && count < ARRAY_COUNT(candidates); i++)
        {
            u16 threshold;
            switch (evos[i].method)
            {
            case EVO_LEVEL:
            case EVO_LEVEL_BATTLE_ONLY:
                threshold = evos[i].param;
                break;
            case EVO_ITEM:
            case EVO_TRADE:
                threshold = rules->evoOtherLevel;
                break;
            default:
                continue;
            }
            if (scaledLevel >= threshold)
                candidates[count++] = evos[i].targetSpecies;
        }
        if (count == 0)
            break;
        species = candidates[Random() % count];
    }
    return species;
}

// Trainer classes that get the boss extra levels.
static bool32 IsBossTrainer(const struct Trainer *trainer)
{
    switch (trainer->trainerClass)
    {
    // Hoenn
    case TRAINER_CLASS_LEADER:
    case TRAINER_CLASS_ELITE_FOUR:
    case TRAINER_CLASS_CHAMPION:
    case TRAINER_CLASS_MAGMA_LEADER:
    case TRAINER_CLASS_MAGMA_ADMIN:
    case TRAINER_CLASS_AQUA_LEADER:
    case TRAINER_CLASS_AQUA_ADMIN:
    // Johto
    case TRAINER_CLASS_LEADER_HNS:
    case TRAINER_CLASS_LEADER_KANTO_HNS:
    case TRAINER_CLASS_ELITE_FOUR_HNS:
    case TRAINER_CLASS_CHAMPION_HNS:
    case TRAINER_CLASS_ROCKET_ADMIN_HNS:
    case TRAINER_CLASS_RIVAL_HNS:
    // Kanto
    case TRAINER_CLASS_LEADER_FRLG:
    case TRAINER_CLASS_ELITE_FOUR_FRLG:
    case TRAINER_CLASS_CHAMPION_FRLG:
    case TRAINER_CLASS_BOSS_FRLG:
    case TRAINER_CLASS_RIVAL_LATE_FRLG:
        return TRUE;
    default:
        return FALSE;
    }
}

// partyMaxLevel: highest original level in the trainer's party.
u8 ScaleTrainerMonLevel(const struct Trainer *trainer, u8 level, u8 partyMaxLevel)
{
    const struct ScalingRules *rules = GetScalingRules();
    s32 anchor, top, scaled;
    u8 floor, ceiling;

    if (rules == NULL)
        return level;
    if (partyMaxLevel >= rules->fixedMinLevel)
        return level;

    anchor = GetScalingAnchor();
    if (anchor == 0 || partyMaxLevel == 0)
        return level;

    // The ace goes to the top of the band, the others keep their distance to it.
    top = anchor + rules->trainerAbove;
    if (IsBossTrainer(trainer))
        top += rules->bossExtra;
    scaled = top - (s32)(partyMaxLevel - level);
    if (scaled < anchor - rules->trainerBelow)
        scaled = anchor - rules->trainerBelow;

    GetCorridor(rules, &floor, &ceiling);
    scaled = ClampScaledLevel(rules, scaled, floor, ceiling);
    if (rules->originalLevelIsFloor && scaled < level)
        scaled = level;
    return scaled;
}

#else // Pass-through without scaling (Emerald/FRLG build or switched off)

bool32 LevelScalingActive(void)
{
    return FALSE;
}

u8 ScaleWildMonLevel(u8 level)
{
    return level;
}

u8 ScaleTrainerMonLevel(const struct Trainer *trainer, u8 level, u8 partyMaxLevel)
{
    return level;
}

u16 ScaleTrainerMonSpecies(u16 species, u8 scaledLevel)
{
    return species;
}

#endif

#if defined(POKEMON_HNS)

// Visited flags of the Hoenn towns, set again on every map load.
static const struct { u16 mapSec; u16 flag; } sHoennVisitedFlags[] =
{
    { MAPSEC_LITTLEROOT_TOWN,  FLAG_VISITED_LITTLEROOT_TOWN  },
    { MAPSEC_OLDALE_TOWN,      FLAG_VISITED_OLDALE_TOWN      },
    { MAPSEC_DEWFORD_TOWN,     FLAG_VISITED_DEWFORD_TOWN     },
    { MAPSEC_LAVARIDGE_TOWN,   FLAG_VISITED_LAVARIDGE_TOWN   },
    { MAPSEC_FALLARBOR_TOWN,   FLAG_VISITED_FALLARBOR_TOWN   },
    { MAPSEC_VERDANTURF_TOWN,  FLAG_VISITED_VERDANTURF_TOWN  },
    { MAPSEC_PACIFIDLOG_TOWN,  FLAG_VISITED_PACIFIDLOG_TOWN  },
    { MAPSEC_PETALBURG_CITY,   FLAG_VISITED_PETALBURG_CITY   },
    { MAPSEC_SLATEPORT_CITY,   FLAG_VISITED_SLATEPORT_CITY   },
    { MAPSEC_MAUVILLE_CITY,    FLAG_VISITED_MAUVILLE_CITY    },
    { MAPSEC_RUSTBORO_CITY,    FLAG_VISITED_RUSTBORO_CITY    },
    { MAPSEC_FORTREE_CITY,     FLAG_VISITED_FORTREE_CITY     },
    { MAPSEC_LILYCOVE_CITY,    FLAG_VISITED_LILYCOVE_CITY    },
    { MAPSEC_MOSSDEEP_CITY,    FLAG_VISITED_MOSSDEEP_CITY    },
    { MAPSEC_SOOTOPOLIS_CITY,  FLAG_VISITED_SOOTOPOLIS_CITY  },
    { MAPSEC_EVER_GRANDE_CITY, FLAG_VISITED_EVER_GRANDE_CITY },
};

void TrySetHoennVisitedFlag(void)
{
    u32 i;
    u32 mapSec = gMapHeader.regionMapSectionId;

    for (i = 0; i < ARRAY_COUNT(sHoennVisitedFlags); i++)
    {
        if (sHoennVisitedFlags[i].mapSec == mapSec)
        {
            FlagSet(sHoennVisitedFlags[i].flag);
            return;
        }
    }
}

#else

void TrySetHoennVisitedFlag(void) {}

#endif
