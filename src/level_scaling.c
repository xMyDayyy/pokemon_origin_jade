#include "global.h"
#include "level_scaling.h"
#include "battle.h"
#include "data.h"
#include "overworld.h"
#include "pokemon.h"
#include "random.h"
#include "event_data.h"
#include "vs_seeker.h"
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
// Kanto: FRLG maps (IsFrlgKantoMap), only after the Kanto title; before it
// only VS Seeker rematch teams move up to a floor.
// After a region's title its corridors lose their ceiling.
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
    // Optional: storyCeiling replaces ceiling while var storyVar is below storyValue.
    u8 storyCeiling;
    u16 storyVar;
    u16 storyValue;
};

// A map whose trainers have their own band top and corridor (Johto league rooms).
struct ScalingRoom
{
    u16 map;
    s8 extra;
    u8 floor;
    u8 ceiling;
};

struct ScalingRules
{
    const struct ScalingCorridor *corridors;
    u16 corridorCount;
    const struct ScalingRoom *rooms;
    u16 roomCount;
    u8 trainerBelow;
    u8 trainerAbove;
    u8 wildBelow;
    u8 wildAbove;
    u8 bossExtra;
    u8 fixedMinLevel;
    u8 evoOtherLevel;
    u8 evoSkipPercent;
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
    // TRUE: static and scripted encounters and roamers are at least the top of
    // the wild band (ScaleStaticMonLevel; Johto, Hoenn).
    bool8 staticFloor;
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
    .evoSkipPercent      = HOENN_SCALING_EVO_SKIP_PERCENT,
    .minLevel            = HOENN_SCALING_MIN_LEVEL,
    .maxLevel            = HOENN_SCALING_MAX_LEVEL,
    .defaultFloor        = HOENN_SCALING_DEFAULT_FLOOR,
    .defaultCeiling      = HOENN_SCALING_DEFAULT_CEILING,
    .trainerEvolve       = HOENN_SCALING_TRAINER_EVOLVE,
    .corridorListIsRegion = FALSE,
    .originalLevelIsFloor = FALSE,
    .staticFloor         = TRUE,
    .titleFlag           = FLAG_IS_HOENN_CHAMPION,
    .titleCeiling        = HOENN_SCALING_TITLE_CEILING,
};
#endif

#if JOHTO_LEVEL_SCALING == TRUE
static const struct ScalingCorridor sJohtoCorridors[] =
{
    JOHTO_SCALING_CORRIDORS
};

static const struct ScalingRoom sJohtoRooms[] =
{
    JOHTO_SCALING_ROOMS
};

static const struct ScalingRules sJohtoRules =
{
    .corridors           = sJohtoCorridors,
    .corridorCount       = ARRAY_COUNT(sJohtoCorridors),
    .rooms               = sJohtoRooms,
    .roomCount           = ARRAY_COUNT(sJohtoRooms),
    .trainerBelow        = JOHTO_SCALING_TRAINER_BELOW,
    .trainerAbove        = JOHTO_SCALING_TRAINER_ABOVE,
    .wildBelow           = JOHTO_SCALING_WILD_BELOW,
    .wildAbove           = JOHTO_SCALING_WILD_ABOVE,
    .bossExtra           = JOHTO_SCALING_BOSS_EXTRA,
    .fixedMinLevel       = JOHTO_SCALING_FIXED_MIN_LEVEL,
    .evoOtherLevel       = JOHTO_SCALING_EVO_OTHER_LEVEL,
    .evoSkipPercent      = JOHTO_SCALING_EVO_SKIP_PERCENT,
    .minLevel            = JOHTO_SCALING_MIN_LEVEL,
    .maxLevel            = JOHTO_SCALING_MAX_LEVEL,
    .defaultFloor        = JOHTO_SCALING_DEFAULT_FLOOR,
    .defaultCeiling      = JOHTO_SCALING_DEFAULT_CEILING,
    .trainerEvolve       = JOHTO_SCALING_TRAINER_EVOLVE,
    .corridorListIsRegion = TRUE,
    .originalLevelIsFloor = FALSE,
    .staticFloor         = TRUE,
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
    .evoSkipPercent      = KANTO_SCALING_EVO_SKIP_PERCENT,
    .minLevel            = KANTO_SCALING_MIN_LEVEL,
    .maxLevel            = KANTO_SCALING_MAX_LEVEL,
    .defaultFloor        = KANTO_SCALING_MIN_LEVEL,
    .defaultCeiling      = KANTO_SCALING_MAX_LEVEL,
    .trainerEvolve       = KANTO_SCALING_TRAINER_EVOLVE,
    .corridorListIsRegion = FALSE,
    .originalLevelIsFloor = TRUE,
    .staticFloor         = FALSE,
    .titleFlag           = FLAG_IS_KANTO_CHAMPION,
    .titleCeiling        = KANTO_SCALING_MAX_LEVEL,
};
#define KANTO_REMATCH_FLOOR_RULES (&sKantoRules)
#else
#define KANTO_REMATCH_FLOOR_RULES NULL
#endif

// Evolution rules for the Pokemon that ScaleTrainerMonLevel just raised to a Kanto
// VS Seeker rematch floor (Kanto's rules), NULL otherwise. Read by ScaleTrainerMonSpecies.
static EWRAM_DATA const struct ScalingRules *sRematchFloorRules = NULL;

// FRLG Kanto map: a Kanto mapsec outside HnS's map groups, which come first in
// data/maps/map_groups.json (before Emerald's, MAP_LITTLEROOT_TOWN). Johto's league
// maps (Kanto mapsec) keep the Johto rules.
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
            {
                *ceiling = rules->corridors[i].ceiling;
                if (rules->corridors[i].storyVar != 0
                 && VarGet(rules->corridors[i].storyVar) < rules->corridors[i].storyValue)
                    *ceiling = rules->corridors[i].storyCeiling;
            }
            return TRUE;
        }
    }
    return FALSE;
}

// NULL = no scaling on the current map.
static const struct ScalingRules *GetScalingRules(void)
{
    u16 mapsec = gMapHeader.regionMapSectionId;

    // Kanto's first run keeps the hand-set levels; scaling starts with
    // the Kanto title.
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

// Anchor: mean of the three highest party levels (fewer Pokemon: their mean), rounded,
// but at least the highest level - SCALING_ANCHOR_MAX_DROP. Eggs excluded (0 = no Pokemon).
// Only the first partySlots party slots count.
static u8 GetScalingAnchor(u32 partySlots)
{
    u8 top[3] = {0}; // highest first
    u32 i, j, count = 0, sum = 0, anchor;

    for (i = 0; i < partySlots; i++)
    {
        u8 level, temp;

        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            continue;
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL))
            continue;
        level = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL, NULL);
        for (j = 0; j < ARRAY_COUNT(top); j++)
        {
            if (level > top[j])
                SWAP(level, top[j], temp);
        }
        if (count < ARRAY_COUNT(top))
            count++;
    }
    if (count == 0)
        return 0;
    for (i = 0; i < count; i++)
        sum += top[i];
    anchor = (sum + count / 2) / count;
    if (anchor + SCALING_ANCHOR_MAX_DROP < top[0])
        anchor = top[0] - SCALING_ANCHOR_MAX_DROP;
    return anchor;
}

// Room of the current map, NULL if it has none.
static const struct ScalingRoom *FindScalingRoom(const struct ScalingRules *rules)
{
    u32 i;
    u16 map = gSaveBlock1Ptr->location.mapNum | (gSaveBlock1Ptr->location.mapGroup << 8);

    for (i = 0; i < rules->roomCount; i++)
    {
        if (rules->rooms[i].map == map)
            return &rules->rooms[i];
    }
    return NULL;
}

// room: replaces the corridor of the map section (trainers only), may be NULL.
static void GetCorridor(const struct ScalingRules *rules, const struct ScalingRoom *room, u8 *floor, u8 *ceiling)
{
    *floor = rules->defaultFloor;
    *ceiling = rules->defaultCeiling;
    if (room != NULL)
    {
        *floor = room->floor;
        *ceiling = room->ceiling;
    }
    else
    {
        FindCorridor(rules, gMapHeader.regionMapSectionId, floor, ceiling);
    }
    // After the region's title only the floor stays.
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
    anchor = GetScalingAnchor(PARTY_SIZE);
    if (anchor == 0)
        return level;

    // Wild band: anchor - BELOW .. anchor - ABOVE, uniformly distributed.
    width = rules->wildBelow - rules->wildAbove + 1;
    scaled = anchor - rules->wildBelow + (s32)(Random() % width);

    GetCorridor(rules, NULL, &floor, &ceiling);
    scaled = ClampScaledLevel(rules, scaled, floor, ceiling);
    if (rules->originalLevelIsFloor && scaled < level)
        scaled = level;
    return scaled;
}

u8 GetScalingCeiling(void)
{
    const struct ScalingRules *rules = GetScalingRules();
    u8 floor, ceiling;

    if (rules == NULL)
        return 0;
    GetCorridor(rules, NULL, &floor, &ceiling);
    return ceiling;
}

// Static and scripted encounters and roamers on maps with Johto's or Hoenn's rules: at
// least the top of the map's wild band.
// Pass-through elsewhere (Kanto keeps its levels).
u8 ScaleStaticMonLevel(u8 level)
{
    const struct ScalingRules *rules = GetScalingRules();
    s32 anchor;
    u8 floor, ceiling, top;

    if (rules == NULL || !rules->staticFloor)
        return level;
    anchor = GetScalingAnchor(PARTY_SIZE);
    if (anchor == 0)
        return level;
    GetCorridor(rules, NULL, &floor, &ceiling);
    top = ClampScaledLevel(rules, anchor - rules->wildAbove, floor, ceiling);
    if (top > level)
        return top;
    return level;
}

// One row of sTrainerEvoLevels.
struct TrainerEvoLevel
{
    u16 species;
    u8 level;
};

#include "data/trainer_evo_levels.h"

// Level from which a scaled trainer Pokemon takes a stone, trade or condition-only
// evolution into targetSpecies; fallback for species missing in the table.
static u8 GetTrainerEvoLevel(u16 targetSpecies, u8 fallback)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sTrainerEvoLevels); i++)
    {
        if (sTrainerEvoLevels[i].species == targetSpecies)
            return sTrainerEvoLevels[i].level;
    }
    return fallback;
}

// Rare forms and special evolutions ScaleTrainerMonSpecies never picks.
static const u16 sTrainerEvoExcluded[] =
{
    SPECIES_DUDUNSPARCE_THREE_SEGMENT,
    SPECIES_URSALUNA_BLOODMOON,
    SPECIES_MAUSHOLD_THREE,
};

static bool32 IsTrainerEvoExcluded(u16 species)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sTrainerEvoExcluded); i++)
    {
        if (sTrainerEvoExcluded[i] == species)
            return TRUE;
    }
    return FALSE;
}

// Fixed pseudo-random value per trainer, party slot and evolution step (lowbias32 mix).
static u32 TrainerEvoHash(u16 trainerId, u8 partyIndex, u8 step)
{
    u32 hash = trainerId | ((u32)partyIndex << 16) | ((u32)step << 24);

    hash ^= hash >> 16;
    hash *= 0x7FEB352D;
    hash ^= hash >> 15;
    hash *= 0x846CA68B;
    hash ^= hash >> 16;
    return hash;
}

// Trainer Pokemon only: evolves up to two steps if the scaled level allows it.
// Level evolutions at their level; stone, trade and level-0 (condition-only) ones
// at GetTrainerEvoLevel.
// Each step is skipped with evoSkipPercent, which also ends the evolution.
// Skips and branches come from TrainerEvoHash.
// Call right after ScaleTrainerMonLevel or ScalePartnerMonLevel for the same Pokemon.
// partyIndex: its index in the trainer's party data.
u16 ScaleTrainerMonSpecies(u16 species, u8 scaledLevel, u16 trainerId, u8 partyIndex)
{
    const struct ScalingRules *rules = GetScalingRules();
    u32 step, i, j;

    if (rules == NULL)
        rules = sRematchFloorRules;
    sRematchFloorRules = NULL;
    if (rules == NULL || rules->trainerEvolve != TRUE)
        return species;

    for (step = 0; step < 2; step++)
    {
        const struct Evolution *evos = GetSpeciesEvolutions(species);
        u16 candidates[8];
        u32 count = 0, hash;

        if (evos == NULL)
            break;
        for (i = 0; evos[i].method != EVOLUTIONS_END && count < ARRAY_COUNT(candidates); i++)
        {
            u16 threshold;
            if (IsTrainerEvoExcluded(evos[i].targetSpecies))
                continue;
            switch (evos[i].method)
            {
            case EVO_LEVEL:
            case EVO_LEVEL_BATTLE_ONLY:
                // Level 0: condition-only (friendship, move, place), like stone/trade.
                if (evos[i].param != 0)
                    threshold = evos[i].param;
                else
                    threshold = GetTrainerEvoLevel(evos[i].targetSpecies, rules->evoOtherLevel);
                break;
            case EVO_ITEM:
            case EVO_TRADE:
                threshold = GetTrainerEvoLevel(evos[i].targetSpecies, rules->evoOtherLevel);
                break;
            default:
                continue;
            }
            if (scaledLevel < threshold)
                continue;
            // Each target once (Eevee: 12 evolutions into 8 species).
            for (j = 0; j < count; j++)
            {
                if (candidates[j] == evos[i].targetSpecies)
                    break;
            }
            if (j == count)
                candidates[count++] = evos[i].targetSpecies;
        }
        if (count == 0)
            break;
        hash = TrainerEvoHash(trainerId, partyIndex, step);
        if ((hash & 0xFFFF) % 100 < rules->evoSkipPercent)
            break;
        species = candidates[(hash >> 16) % count];
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
    case TRAINER_CLASS_RIVAL: // May and Wally
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

// Kanto VS Seeker rematch before the Kanto title: if the team's highest level is
// below the tier's floor (GetKantoRematchLevelFloor), the ace goes to the floor and
// the others keep their distance to it. Never lowers, at most MAX_LEVEL.
static u8 RaiseToKantoRematchFloor(const struct Trainer *trainer, u8 level, u8 partyMaxLevel)
{
    s32 top = GetKantoRematchLevelFloor(trainer);
    s32 raised;

    if (partyMaxLevel == 0 || partyMaxLevel >= top)
        return level;
    raised = top - (s32)(partyMaxLevel - level);
    if (raised > MAX_LEVEL)
        raised = MAX_LEVEL;
    sRematchFloorRules = KANTO_REMATCH_FLOOR_RULES;
    return raised;
}

// Trainer band of rules. partyMaxLevel: highest original level in the party.
// In a battle with an in-game partner the anchor counts only the player's own
// slots (the partner's team fills the last MULTI_PARTY_SIZE).
// room: own band top and corridor of the map (opponents only), may be NULL.
static u8 ScaleToTrainerBand(const struct ScalingRules *rules, u8 level, u8 partyMaxLevel, bool32 isBoss, const struct ScalingRoom *room)
{
    s32 anchor, top, scaled;
    u8 floor, ceiling;

    if (partyMaxLevel >= rules->fixedMinLevel)
        return level;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        anchor = GetScalingAnchor(PARTY_SIZE - MULTI_PARTY_SIZE);
    else
        anchor = GetScalingAnchor(PARTY_SIZE);
    if (anchor == 0 || partyMaxLevel == 0)
        return level;

    // The ace goes to the top of the band, the others keep their distance to it.
    top = anchor + rules->trainerAbove;
    if (room != NULL)
        top += room->extra;
    else if (isBoss)
        top += rules->bossExtra;
    scaled = top - (s32)(partyMaxLevel - level);
    if (scaled < anchor - rules->trainerBelow)
        scaled = anchor - rules->trainerBelow;

    GetCorridor(rules, room, &floor, &ceiling);
    scaled = ClampScaledLevel(rules, scaled, floor, ceiling);
    if (rules->originalLevelIsFloor && scaled < level)
        scaled = level;
    return scaled;
}

// partyMaxLevel: highest original level in the trainer's party.
u8 ScaleTrainerMonLevel(const struct Trainer *trainer, u8 level, u8 partyMaxLevel)
{
    const struct ScalingRules *rules = GetScalingRules();

    sRematchFloorRules = NULL;
    if (rules == NULL)
        return RaiseToKantoRematchFloor(trainer, level, partyMaxLevel);
    return ScaleToTrainerBand(rules, level, partyMaxLevel, IsBossTrainer(trainer), FindScalingRoom(rules));
}

// partyMaxLevel: highest original level in the partner's party.
u8 ScalePartnerMonLevel(u8 level, u8 partyMaxLevel)
{
    const struct ScalingRules *rules = GetScalingRules();

    sRematchFloorRules = NULL;
    if (rules == NULL)
        return level;
    return ScaleToTrainerBand(rules, level, partyMaxLevel, FALSE, NULL);
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

u8 ScaleStaticMonLevel(u8 level)
{
    return level;
}

u8 GetScalingCeiling(void)
{
    return 0;
}

u8 ScaleTrainerMonLevel(const struct Trainer *trainer, u8 level, u8 partyMaxLevel)
{
    return level;
}

u8 ScalePartnerMonLevel(u8 level, u8 partyMaxLevel)
{
    return level;
}

u16 ScaleTrainerMonSpecies(u16 species, u8 scaledLevel, u16 trainerId, u8 partyIndex)
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
    // Ever Grande City is left to its coord events above the waterfall.
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
