#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "legendaries_oj.h"
#include "roamer.h"
#include "constants/battle.h"
#include "constants/legendaries_oj.h"
#include "constants/species.h"

// One-time encounters (legendaries, Union Cave Lapras, red Gyarados), see
// docs/origin_jade/DECISIONS.md, D-026:
//  - caught: never again;
//  - knocked out: back after every league victory (Kanto, Johto, Hoenn);
//  - fled: back after FLEE_COOLDOWN_DAYS RTC day changes; roamers just keep roaming.
// Whether a Pokémon appears at all (story state) is decided by the map scripts.

#if IS_HNS

#define FLEE_COOLDOWN_DAYS  3
#define FLEE_COUNTER_BITS   2
#define FLEE_COUNTER_MASK   ((1 << FLEE_COUNTER_BITS) - 1)

STATIC_ASSERT(FLEE_COOLDOWN_DAYS <= FLEE_COUNTER_MASK, FleeCooldownFitsCounter);

struct OjLegendary
{
    u16 caughtFlag;     // set on a catch, never cleared
    u16 doneFlag;       // set on a catch or knockout; cleared after a league victory unless caught (0 for roamers)
    u16 fleeVar;        // var with the 2-bit flee counters (0 for roamers)
    u8 fleeSlot;        // counter index in fleeVar (0-7); saved, never change it
    u8 roamerLevel;
    u16 roamerSpecies;  // SPECIES_NONE for static encounters
    u16 releaseFlag;    // a roamer roams once this flag is set
    u8 roamerTable;     // ROAMER_LOC_TABLE_*
};

#define STATIC_LEGENDARY(caught, done, var, slot) \
    { .caughtFlag = caught, .doneFlag = done, .fleeVar = var, .fleeSlot = slot }
#define ROAMING_LEGENDARY(caught, species, level, release, table) \
    { .caughtFlag = caught, .roamerSpecies = species, .roamerLevel = level, .releaseFlag = release, .roamerTable = table }

static const struct OjLegendary sLegendaries[LEGENDARY_COUNT] =
{
    [LEGENDARY_ARTICUNO]     = STATIC_LEGENDARY(FLAG_CAUGHT_ARTICUNO, FLAG_FOUGHT_ARTICUNO, VAR_LEGENDARY_FLEE_KANTO, 0),
    [LEGENDARY_ZAPDOS]       = STATIC_LEGENDARY(FLAG_CAUGHT_ZAPDOS, FLAG_FOUGHT_ZAPDOS, VAR_LEGENDARY_FLEE_KANTO, 1),
    [LEGENDARY_MOLTRES]      = STATIC_LEGENDARY(FLAG_CAUGHT_MOLTRES, FLAG_FOUGHT_MOLTRES, VAR_LEGENDARY_FLEE_KANTO, 2),
    [LEGENDARY_MEWTWO]       = STATIC_LEGENDARY(FLAG_CAUGHT_MEWTWO, FLAG_FOUGHT_MEWTWO, VAR_LEGENDARY_FLEE_KANTO, 3),
    [LEGENDARY_MEW]          = STATIC_LEGENDARY(FLAG_CAUGHT_MEW, FLAG_DEFEATED_MEW, VAR_LEGENDARY_FLEE_KANTO, 4),
    [LEGENDARY_LUGIA]        = STATIC_LEGENDARY(FLAG_CAUGHT_LUGIA, FLAG_DEFEATED_LUGIA, VAR_LEGENDARY_FLEE_JOHTO, 0),
    [LEGENDARY_HO_OH]        = STATIC_LEGENDARY(FLAG_CAUGHT_HO_OH, FLAG_DEFEATED_HO_OH, VAR_LEGENDARY_FLEE_JOHTO, 1),
    [LEGENDARY_CELEBI]       = STATIC_LEGENDARY(FLAG_CAUGHT_CELEBI, FLAG_DEFEATED_CELEBI, VAR_LEGENDARY_FLEE_JOHTO, 2),
    [LEGENDARY_SUICUNE]      = STATIC_LEGENDARY(FLAG_CAUGHT_SUICUNE, FLAG_DEFEATED_SUICUNE, VAR_LEGENDARY_FLEE_JOHTO, 3),
    [LEGENDARY_DEOXYS]       = STATIC_LEGENDARY(FLAG_BATTLED_DEOXYS, FLAG_DEFEATED_DEOXYS, VAR_LEGENDARY_FLEE_JOHTO, 4),
    [LEGENDARY_LAPRAS]       = STATIC_LEGENDARY(FLAG_CAUGHT_UNION_CAVE_LAPRAS, FLAG_DEFEATED_UNION_CAVE_LAPRAS, VAR_LEGENDARY_FLEE_JOHTO, 5),
    [LEGENDARY_RED_GYARADOS] = STATIC_LEGENDARY(FLAG_CAUGHT_RED_GYARADOS, FLAG_DEFEATED_RED_GYARADOS, VAR_LEGENDARY_FLEE_JOHTO, 6),
    [LEGENDARY_ENTEI]        = ROAMING_LEGENDARY(FLAG_CAUGHT_ENTEI, SPECIES_ENTEI, 75, FLAG_RELEASED_BEASTS, ROAMER_LOC_TABLE_JOHTO),
    [LEGENDARY_RAIKOU]       = ROAMING_LEGENDARY(FLAG_CAUGHT_RAIKOU, SPECIES_RAIKOU, 75, FLAG_RELEASED_BEASTS, ROAMER_LOC_TABLE_JOHTO),
    [LEGENDARY_REGIROCK]     = STATIC_LEGENDARY(FLAG_CAUGHT_REGIROCK, FLAG_DEFEATED_REGIROCK, VAR_LEGENDARY_FLEE_HOENN, 0),
    [LEGENDARY_REGICE]       = STATIC_LEGENDARY(FLAG_CAUGHT_REGICE, FLAG_DEFEATED_REGICE, VAR_LEGENDARY_FLEE_HOENN, 1),
    [LEGENDARY_REGISTEEL]    = STATIC_LEGENDARY(FLAG_CAUGHT_REGISTEEL, FLAG_DEFEATED_REGISTEEL, VAR_LEGENDARY_FLEE_HOENN, 2),
    [LEGENDARY_GROUDON]      = STATIC_LEGENDARY(FLAG_CAUGHT_GROUDON, FLAG_DEFEATED_GROUDON, VAR_LEGENDARY_FLEE_HOENN, 3),
    [LEGENDARY_KYOGRE]       = STATIC_LEGENDARY(FLAG_CAUGHT_KYOGRE, FLAG_DEFEATED_KYOGRE, VAR_LEGENDARY_FLEE_HOENN, 4),
    [LEGENDARY_RAYQUAZA]     = STATIC_LEGENDARY(FLAG_CAUGHT_RAYQUAZA, FLAG_DEFEATED_RAYQUAZA, VAR_LEGENDARY_FLEE_HOENN, 5),
    [LEGENDARY_LATIAS]       = ROAMING_LEGENDARY(FLAG_CAUGHT_LATIAS, SPECIES_LATIAS, 100, FLAG_IS_HOENN_CHAMPION, ROAMER_LOC_TABLE_HOENN),
    [LEGENDARY_LATIOS]       = ROAMING_LEGENDARY(FLAG_CAUGHT_LATIOS, SPECIES_LATIOS, 100, FLAG_IS_HOENN_CHAMPION, ROAMER_LOC_TABLE_HOENN),
};

static u32 GetFleeDaysLeft(const struct OjLegendary *legendary)
{
    if (legendary->fleeVar == 0)
        return 0;
    return (VarGet(legendary->fleeVar) >> (legendary->fleeSlot * FLEE_COUNTER_BITS)) & FLEE_COUNTER_MASK;
}

static void SetFleeDaysLeft(const struct OjLegendary *legendary, u32 days)
{
    u32 shift = legendary->fleeSlot * FLEE_COUNTER_BITS;
    u16 value;

    if (legendary->fleeVar == 0)
        return;
    value = VarGet(legendary->fleeVar) & ~(FLEE_COUNTER_MASK << shift);
    VarSet(legendary->fleeVar, value | ((days & FLEE_COUNTER_MASK) << shift));
}

bool32 IsLegendaryIdAvailable(u32 id)
{
    const struct OjLegendary *legendary;

    if (id >= LEGENDARY_COUNT)
        return FALSE;
    legendary = &sLegendaries[id];
    if (FlagGet(legendary->caughtFlag))
        return FALSE;
    if (legendary->doneFlag != 0 && FlagGet(legendary->doneFlag))
        return FALSE;
    return GetFleeDaysLeft(legendary) == 0;
}

// Special (special or specialvar): id in VAR_0x8004. TRUE unless caught, knocked out since
// the last league victory, or fled less than FLEE_COOLDOWN_DAYS days ago.
bool16 IsLegendaryAvailable(void)
{
    gSpecialVar_Result = IsLegendaryIdAvailable(gSpecialVar_0x8004);
    return gSpecialVar_Result;
}

// Special: id in VAR_0x8004, call right after the battle. A lost battle whites out before.
void RecordLegendaryBattleOutcome(void)
{
    const struct OjLegendary *legendary;

    if (gSpecialVar_0x8004 >= LEGENDARY_COUNT)
        return;
    legendary = &sLegendaries[gSpecialVar_0x8004];

    switch (gBattleOutcome)
    {
    case B_OUTCOME_CAUGHT:
        FlagSet(legendary->caughtFlag);
        if (legendary->doneFlag != 0)
            FlagSet(legendary->doneFlag);
        break;
    case B_OUTCOME_WON:
        if (legendary->doneFlag != 0)
            FlagSet(legendary->doneFlag);
        break;
    case B_OUTCOME_RAN:
    case B_OUTCOME_PLAYER_TELEPORTED:
    case B_OUTCOME_MON_FLED:
    case B_OUTCOME_MON_TELEPORTED:
        SetFleeDaysLeft(legendary, FLEE_COOLDOWN_DAYS);
        break;
    }
}

// Special for Common_EventScript_ReviveDefeatedLegendaries, after every league victory:
// knocked-out Pokémon can be met again, released roamers that are neither caught nor
// roaming start roaming again. A second call changes nothing.
void ReviveDefeatedLegendaries(void)
{
    u32 i;

    for (i = 0; i < LEGENDARY_COUNT; i++)
    {
        const struct OjLegendary *legendary = &sLegendaries[i];

        if (FlagGet(legendary->caughtFlag))
            continue;
        if (legendary->roamerSpecies != SPECIES_NONE)
        {
            if (FlagGet(legendary->releaseFlag) && !IsRoamerSpeciesActive(legendary->roamerSpecies))
                TryAddRoamer(legendary->roamerSpecies, legendary->roamerLevel, legendary->roamerTable);
        }
        else if (legendary->doneFlag != 0)
        {
            FlagClear(legendary->doneFlag);
        }
    }
}

// Called on every RTC day change with the number of days passed (src/clock.c).
void UpdateLegendaryFleeCooldowns(u16 days)
{
    u32 i;

    for (i = 0; i < LEGENDARY_COUNT; i++)
    {
        const struct OjLegendary *legendary = &sLegendaries[i];
        u32 left = GetFleeDaysLeft(legendary);

        if (left != 0)
            SetFleeDaysLeft(legendary, left > days ? left - days : 0);
    }
}

// Called when a roamer battle ends with a catch (src/battle_main.c).
void RecordRoamerCaught(u16 species)
{
    u32 i;

    for (i = 0; i < LEGENDARY_COUNT; i++)
    {
        if (sLegendaries[i].roamerSpecies != SPECIES_NONE && sLegendaries[i].roamerSpecies == species)
            FlagSet(sLegendaries[i].caughtFlag);
    }
}

// Level of a roamer in sLegendaries, 0 for other species (src/roamer.c).
u8 GetLegendaryRoamerLevel(u16 species)
{
    u32 i;

    for (i = 0; i < LEGENDARY_COUNT; i++)
    {
        if (sLegendaries[i].roamerSpecies != SPECIES_NONE && sLegendaries[i].roamerSpecies == species)
            return sLegendaries[i].roamerLevel;
    }
    return 0;
}

#else

bool32 IsLegendaryIdAvailable(u32 id) { return TRUE; }
bool16 IsLegendaryAvailable(void) { gSpecialVar_Result = TRUE; return TRUE; }
void RecordLegendaryBattleOutcome(void) {}
void ReviveDefeatedLegendaries(void) {}
void UpdateLegendaryFleeCooldowns(u16 days) {}
void RecordRoamerCaught(u16 species) {}
u8 GetLegendaryRoamerLevel(u16 species) { return 0; }

#endif
