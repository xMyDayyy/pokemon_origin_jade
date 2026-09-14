#include "global.h"
#include "level_scaling.h"
#include "data.h"
#include "overworld.h"
#include "pokemon.h"
#include "random.h"
#include "event_data.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"
#include "config/hoenn_scaling.h"
#include "config/johto_scaling.h"

// =====================================================================
// Levelscaling - Umsetzung der Regeldateien config/hoenn_scaling.h und
// config/johto_scaling.h. Anker = hoechstes Level im Spielerteam;
// Trainer skalieren um den Anker herum (Teamstruktur bleibt erhalten),
// Wildpokemon liegen darunter; ein Korridor pro Mapsection bewahrt das
// Gefaelle der Region.
//
// Zwei Regionen, ein Rechenweg - sie unterscheiden sich nur in ihren
// Konstanten und ihrer Korridortabelle:
//   Hoenn: Region ueber IsHoennMapsec (zusammenhaengender Mapsec-Block),
//          Gebiete ohne Korridoreintrag nutzen die Default-Werte.
//   Johto: Region ueber die Korridortabelle selbst - Johtos Mapsections
//          liegen im selben Nummernkreis wie Kantos, und Kanto soll
//          seine handgesetzte Levelleiter behalten. Was nicht in der
//          Tabelle steht, wird also gar nicht erst skaliert.
// =====================================================================

// Reine Geografie: auch von Regionskarte, Ortsnamen, VM-Lizenzen und
// Sprites genutzt und deshalb unabhaengig von den Scaling-Schaltern.
#if defined(POKEMON_HNS)

bool32 IsHoennMapsec(u32 mapSecId)
{
    // Zusammenhaengender Hoenn-Block der HnS-Mapsection-Liste ...
    if (mapSecId >= MAPSEC_LITTLEROOT_TOWN && mapSecId < MAPSEC_NONE)
        return TRUE;
    // ... plus die drei Sections, die Hoenn mit dem Johto/Kanto-
    // Nummernkreis teilt (kein aktiver _hns-Nutzer bzw. nur
    // Platzhalterkarten): Siegesstrasse, Safari-Zone, Wrack.
    if (mapSecId == MAPSEC_VICTORY_ROAD
     || mapSecId == MAPSEC_SAFARI_ZONE
     || mapSecId == MAPSEC_ABANDONED_SHIP)
        return TRUE;
    return FALSE;
}

#else

bool32 IsHoennMapsec(u32 mapSecId)
{
    return FALSE;
}

#endif

#if defined(POKEMON_HNS) && (HOENN_LEVEL_SCALING == TRUE || JOHTO_LEVEL_SCALING == TRUE)

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
    // TRUE: die Korridortabelle definiert die Region (Johto).
    // FALSE: die Region haengt an IsHoennMapsec, Gebiete ohne Eintrag
    // laufen mit den Default-Werten (Hoenn).
    bool8 corridorListIsRegion;
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
};
#endif

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

// Welche Regel gilt auf der aktuellen Karte? NULL = kein Scaling.
static const struct ScalingRules *GetScalingRules(void)
{
    u16 mapsec = gMapHeader.regionMapSectionId;

#if JOHTO_LEVEL_SCALING == TRUE
    // Johto zuerst: MAPSEC_INDIGO_PLATEAU traegt Johtos Liga, liegt
    // aber im Kanto-Block der Mapsec-Liste.
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

    // Wildband: Anker - BELOW .. Anker - ABOVE, gleichverteilt.
    width = rules->wildBelow - rules->wildAbove + 1;
    scaled = anchor - rules->wildBelow + (s32)(Random() % width);

    GetCorridor(rules, &floor, &ceiling);
    return ClampScaledLevel(rules, scaled, floor, ceiling);
}


// Hebt eine Trainer-Art entlang ihrer Entwicklungskette an, solange
// das skalierte Level die Schwelle erreicht. Nur fuer Trainerteams -
// Wildpokemon behalten bewusst ihre Basisformen (Fangbarkeit).
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
        // Verzweigungen (z. B. Waumpel -> Schaloko/Panekon) zufaellig.
        species = candidates[Random() % count];
    }
    return species;
}

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
    // Johto (HnS fuehrt eigene Klassen)
    case TRAINER_CLASS_LEADER_HNS:
    case TRAINER_CLASS_LEADER_KANTO_HNS:
    case TRAINER_CLASS_ELITE_FOUR_HNS:
    case TRAINER_CLASS_CHAMPION_HNS:
    case TRAINER_CLASS_ROCKET_ADMIN_HNS:
        return TRUE;
    default:
        return FALSE;
    }
}

u8 ScaleTrainerMonLevel(const struct Trainer *trainer, u8 level, u8 partyMaxLevel)
{
    const struct ScalingRules *rules = GetScalingRules();
    s32 anchor, top, scaled;
    u8 floor, ceiling;

    if (rules == NULL)
        return level;
    // Superbosse mit festem Originallevel (Troy/Steven in den
    // Meteorfaellen, Rot am Silberberg) bleiben unskaliert.
    if (partyMaxLevel >= rules->fixedMinLevel)
        return level;

    anchor = GetScalingAnchor();
    if (anchor == 0 || partyMaxLevel == 0)
        return level;

    // Das Ass des Trainers liegt am Bandoberrand; alle anderen
    // behalten ihren originalen Abstand zum Ass. So bleibt die
    // Teamstruktur (z. B. 17/17/19) auch skaliert erhalten.
    top = anchor + rules->trainerAbove;
    if (IsBossTrainer(trainer))
        top += rules->bossExtra;
    scaled = top - (s32)(partyMaxLevel - level);
    if (scaled < anchor - rules->trainerBelow)
        scaled = anchor - rules->trainerBelow;

    GetCorridor(rules, &floor, &ceiling);
    return ClampScaledLevel(rules, scaled, floor, ceiling);
}

#else // Durchreichen ohne Scaling (Emerald-/FRLG-Build oder abgeschaltet)

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

// Die Hoenn-Stadtskripte setzen ihr FLAG_VISITED_* im ON_TRANSITION-Skript.
// Im Spieltest blieb Rosaltstadt trotz Besuch grau (nicht anfliegbar), also
// wird das Flag hier beim Laden jeder Karte zusaetzlich gesetzt. Das heilt
// auch bestehende Spielstaende, in denen das Flag fehlt.
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
