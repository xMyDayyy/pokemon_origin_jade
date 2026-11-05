#include "global.h"
#include "challenge_menu.h"
#include "script.h"
#include "event_data.h"
#include "fieldmap.h"
#include "overworld.h"
#include "bug_contest.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "pokemon.h"
#include "item.h"
#include "battle.h"
#include "field_screen_effect.h"
#include "string_util.h"
#include "level_scaling.h"
#include "randomizer.h"
#include "wild_encounter.h"
#include "constants/event_objects.h"

#if IS_HNS

// Judging like HGSS: score = rarity points + level + IV points + HP points.
#define BUG_CONTEST_NPC_COUNT        4
#define BUG_CONTEST_ENTRANTS         (BUG_CONTEST_NPC_COUNT + 1)
#define BUG_CONTEST_PLAYER           BUG_CONTEST_NPC_COUNT // entrant id of the player
#define BUG_CONTEST_UNKNOWN_RARITY   100 // species missing from every contest table
#define BUG_CONTEST_NPC_MIN_HP       30  // NPC catches keep 30-100 % of their HP
#define BUG_CONTEST_CONSOLATION_PRIZE ITEM_ORAN_BERRY // 4th place and below

struct BugContestEntry
{
    u16 species;
    u16 score;
};

struct BugContestRarity
{
    u8 minPercent;
    u8 points;
};

static u32 sBugContestStartTime;
static bool8 sBugContestTimerActive;
static EWRAM_DATA struct BugContestEntry sBugContestEntries[BUG_CONTEST_ENTRANTS] = {0};
static EWRAM_DATA u8 sBugContestRanking[BUG_CONTEST_ENTRANTS] = {0}; // entrant ids, best first
static EWRAM_DATA bool8 sBugContestJudged = FALSE;

// Share of the contest table -> rarity points; the last row takes everything rarer.
static const struct BugContestRarity sBugContestRarity[] =
{
    {20,  50},
    {10, 100},
    { 5, 150},
    { 2, 200},
    { 0, 250},
};

static const u16 sFirstPlaceRewards[]  = { ITEM_MOON_STONE, ITEM_SUN_STONE, ITEM_LEAF_STONE };
static const u16 sSecondPlaceRewards[] = { ITEM_FIRE_STONE, ITEM_THUNDER_STONE, ITEM_WATER_STONE };
static const u16 sThirdPlaceRewards[]  = {
    ITEM_ORAN_BERRY, ITEM_CHERI_BERRY, ITEM_PERSIM_BERRY,
    ITEM_PECHA_BERRY, ITEM_RAWST_BERRY, ITEM_ASPEAR_BERRY, ITEM_CHESTO_BERRY
};

// NPC entrants, in the order of their bugs in the judging scene (VAR_OBJ_GFX_ID_0 to _3).
extern const u8 BugContest_Text_NameWilhelm[];
extern const u8 BugContest_Text_NameAlan[];
extern const u8 BugContest_Text_NameUli[];
extern const u8 BugContest_Text_NameTill[];

static const u8 *const sBugContestNpcNames[BUG_CONTEST_NPC_COUNT] =
{
    BugContest_Text_NameWilhelm,
    BugContest_Text_NameAlan,
    BugContest_Text_NameUli,
    BugContest_Text_NameTill,
};

bool32 GetBugContestFlag(void)
{
    return FlagGet(FLAG_SYS_BUG_CONTEST_MODE);
}

void BugContestRetirePrompt(void)
{
    ScriptContext_SetupScript(BugContest_EventScript_TimesUp);
}

void EnterBugContestMode(void)
{
    // The Nuzlocke's capture restriction is suspended for the contest by
    // IsNuzlockeCaptureSuspended(); FLAG_START_NUZLOCKE must stay set so deaths,
    // revive blocking and the PC rules keep applying.
    FlagSet(FLAG_SYS_BUG_CONTEST_MODE);
    sBugContestStartTime = gMain.vblankCounter1;
    sBugContestTimerActive = TRUE;
    sBugContestJudged = FALSE;
}

void ExitBugContestMode(void)
{
    FlagClear(FLAG_SYS_BUG_CONTEST_MODE);
    sBugContestTimerActive = FALSE;
    sBugContestJudged = FALSE;
}

bool8 BugContestCheckTimeLimit(void)
{
    if (!FlagGet(FLAG_SYS_BUG_CONTEST_MODE) || !sBugContestTimerActive)
        return FALSE;

    u32 elapsed = gMain.vblankCounter1 - sBugContestStartTime;
    if (elapsed >= BUG_CONTEST_TIME_LIMIT_FRAMES)
    {
        sBugContestTimerActive = FALSE;
        ScriptContext_SetupScript(BugContest_EventScript_TimesUp);
        return TRUE;
    }

    return FALSE;
}

bool8 TransferBugContestMon(void)
{
    u8 monIndex = VarGet(VAR_0x8004);
    struct Pokemon *mon = &gPlayerParty[monIndex];
    struct BoxPokemon *boxMon = &mon->box;
    u8 boxId, boxPos;

    if (StorePokemonInBox(boxMon, &boxId, &boxPos) != -1)
    {
        ZeroMonData(mon);
        CompactPartySlots();
        gSpecialVar_Result = MON_GIVEN_TO_PC;
    }
    else
    {
        gSpecialVar_Result = MON_CANT_GIVE;
    }

    return FALSE;
}

// Species of each land slot as met in the park (randomizer included).
static void GetContestSlotSpecies(const struct WildPokemonInfo *info, u16 *slotSpecies)
{
    u32 i;

    for (i = 0; i < LAND_WILD_COUNT; i++)
    {
        slotSpecies[i] = info->wildPokemon[i].species;
#if RANDOMIZER_AVAILABLE == TRUE
        slotSpecies[i] = RandomizeWildEncounter(slotSpecies[i], gSaveBlock1Ptr->location.mapNum,
                                                gSaveBlock1Ptr->location.mapGroup, WILD_AREA_LAND, i);
#endif
    }
}

// Percent of a table's encounters that give this species, 0 if none.
static u32 GetSpeciesPercent(const u16 *slotSpecies, u16 species)
{
    u32 i, chance = 0;

    for (i = 0; i < LAND_WILD_COUNT; i++)
    {
        if (slotSpecies[i] == species)
            chance += GetLandMonSlotChance(i);
    }
    if (chance == 0)
        return 0;
    chance = chance * 100 / GetLandMonChanceTotal();
    return (chance == 0) ? 1 : chance;
}

static u32 GetRarityPoints(u32 percent)
{
    u32 i;

    if (percent == 0)
        return BUG_CONTEST_UNKNOWN_RARITY;
    for (i = 0; i < ARRAY_COUNT(sBugContestRarity) - 1; i++)
    {
        if (percent >= sBugContestRarity[i].minPercent)
            break;
    }
    return sBugContestRarity[i].points;
}

// The player's bug: share in the current table, else in another time of day's table.
static u32 GetPlayerRarityPoints(u32 headerId, const u16 *slotSpecies, u16 species)
{
    u16 otherSpecies[LAND_WILD_COUNT];
    u32 time, percent = GetSpeciesPercent(slotSpecies, species);

    for (time = 0; percent == 0 && time < TIMES_OF_DAY_COUNT; time++)
    {
        const struct WildPokemonInfo *info = gWildMonHeaders[headerId].encounterTypes[time].landMonsInfo;

        if (info == NULL)
            continue;
        GetContestSlotSpecies(info, otherSpecies);
        percent = GetSpeciesPercent(otherSpecies, species);
    }
    return GetRarityPoints(percent);
}

static u16 CalcBugContestScore(u32 rarityPoints, u32 level, u32 ivSum, u32 hpPercent)
{
    return rarityPoints + level + ivSum * 100 / (NUM_STATS * MAX_PER_STAT_IVS) + hpPercent;
}

// A random catch from the table, weighted by the slot chances, never the player's species.
static void GenerateNpcEntry(struct BugContestEntry *entry, const struct WildPokemonInfo *info,
                             const u16 *slotSpecies, u16 playerSpecies)
{
    const struct WildPokemon *slot;
    u32 i, slotId, chance, pick, total = 0, minLevel, maxLevel, level, ivSum = 0, hpPercent;
    bool32 exclude;

    for (i = 0; i < LAND_WILD_COUNT; i++)
    {
        if (slotSpecies[i] != playerSpecies)
            total += GetLandMonSlotChance(i);
    }
    // Only if every slot has the player's species (randomizer) may it repeat.
    exclude = (total != 0);
    if (!exclude)
        total = GetLandMonChanceTotal();

    pick = Random() % total;
    for (slotId = 0; slotId < LAND_WILD_COUNT - 1; slotId++)
    {
        chance = (exclude && slotSpecies[slotId] == playerSpecies) ? 0 : GetLandMonSlotChance(slotId);
        if (pick < chance)
            break;
        pick -= chance;
    }
    slot = &info->wildPokemon[slotId];

    minLevel = min(slot->minLevel, slot->maxLevel);
    maxLevel = max(slot->minLevel, slot->maxLevel);
    level = ScaleWildMonLevel(minLevel + Random() % (maxLevel - minLevel + 1));
    for (i = 0; i < NUM_STATS; i++)
        ivSum += Random() % (MAX_PER_STAT_IVS + 1);
    hpPercent = BUG_CONTEST_NPC_MIN_HP + Random() % (101 - BUG_CONTEST_NPC_MIN_HP);

    entry->species = slotSpecies[slotId];
    entry->score = CalcBugContestScore(GetRarityPoints(GetSpeciesPercent(slotSpecies, entry->species)),
                                       level, ivSum, hpPercent);
}

// Scores the player's chosen bug (VAR_0x8004) and four NPC catches, ranks them
// and sets the graphics of the five bugs in the judging scene.
static void JudgeBugContest(void)
{
    struct Pokemon *mon;
    const struct WildPokemonInfo *info = NULL;
    u16 slotSpecies[LAND_WILD_COUNT];
    u32 i, j, ivSum = 0, maxHP, hpPercent, rarityPoints, gfxId;
    u32 headerId = GetCurrentMapWildMonHeaderId();
    u32 monIndex = VarGet(VAR_0x8004);

    if (monIndex >= PARTY_SIZE)
        monIndex = 0;
    mon = &gPlayerParty[monIndex];
    if (headerId != HEADER_NONE)
        info = gWildMonHeaders[headerId].encounterTypes[GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND)].landMonsInfo;

    // Player
    maxHP = GetMonData(mon, MON_DATA_MAX_HP);
    hpPercent = (maxHP != 0) ? GetMonData(mon, MON_DATA_HP) * 100 / maxHP : 0;
    for (i = 0; i < NUM_STATS; i++)
        ivSum += GetMonData(mon, MON_DATA_HP_IV + i);
    sBugContestEntries[BUG_CONTEST_PLAYER].species = GetMonData(mon, MON_DATA_SPECIES);
    rarityPoints = BUG_CONTEST_UNKNOWN_RARITY;
    if (info != NULL)
    {
        GetContestSlotSpecies(info, slotSpecies);
        rarityPoints = GetPlayerRarityPoints(headerId, slotSpecies, sBugContestEntries[BUG_CONTEST_PLAYER].species);
    }
    sBugContestEntries[BUG_CONTEST_PLAYER].score = CalcBugContestScore(rarityPoints, GetMonData(mon, MON_DATA_LEVEL),
                                                                       ivSum, hpPercent);

    // NPCs
    for (i = 0; i < BUG_CONTEST_NPC_COUNT; i++)
    {
        if (info != NULL)
        {
            GenerateNpcEntry(&sBugContestEntries[i], info, slotSpecies, sBugContestEntries[BUG_CONTEST_PLAYER].species);
        }
        else
        {
            sBugContestEntries[i].species = (sBugContestEntries[BUG_CONTEST_PLAYER].species == SPECIES_CATERPIE)
                                          ? SPECIES_WEEDLE : SPECIES_CATERPIE;
            sBugContestEntries[i].score = 0;
        }
    }

    // Best first; on equal scores the player ranks higher.
    sBugContestRanking[0] = BUG_CONTEST_PLAYER;
    for (i = 0; i < BUG_CONTEST_NPC_COUNT; i++)
        sBugContestRanking[i + 1] = i;
    for (i = 1; i < BUG_CONTEST_ENTRANTS; i++)
    {
        u8 id = sBugContestRanking[i];

        for (j = i; j > 0 && sBugContestEntries[sBugContestRanking[j - 1]].score < sBugContestEntries[id].score; j--)
            sBugContestRanking[j] = sBugContestRanking[j - 1];
        sBugContestRanking[j] = id;
    }

    for (i = 0; i < BUG_CONTEST_NPC_COUNT; i++)
        VarSet(VAR_OBJ_GFX_ID_0 + i, OBJ_EVENT_MON + sBugContestEntries[i].species);
    gfxId = OBJ_EVENT_MON + sBugContestEntries[BUG_CONTEST_PLAYER].species;
    if (IsMonShiny(mon))
        gfxId += OBJ_EVENT_MON_SHINY;
    if (GetMonGender(mon) == MON_FEMALE)
        gfxId += OBJ_EVENT_MON_FEMALE;
    VarSet(VAR_OBJ_GFX_ID_0 + BUG_CONTEST_NPC_COUNT, gfxId);

    sBugContestJudged = TRUE;
}

static u32 GetPlayerPlace(void)
{
    u32 i;

    for (i = 0; i < BUG_CONTEST_ENTRANTS; i++)
    {
        if (sBugContestRanking[i] == BUG_CONTEST_PLAYER)
            break;
    }
    return i + 1;
}

// Map transition of the judging scene: judges and shows the five bugs.
void PrepareBugContestJudging(void)
{
    JudgeBugContest();
}

// VAR_RESULT: the player's place (1 to 5). VAR_0x8005: the prize.
bool8 JudgeBugContestMon(void)
{
    if (!sBugContestJudged)
        JudgeBugContest();
    gSpecialVar_Result = GetPlayerPlace();

    switch (gSpecialVar_Result)
    {
    case 1:
        VarSet(VAR_0x8005, sFirstPlaceRewards[Random() % ARRAY_COUNT(sFirstPlaceRewards)]);
        break;
    case 2:
        VarSet(VAR_0x8005, sSecondPlaceRewards[Random() % ARRAY_COUNT(sSecondPlaceRewards)]);
        break;
    case 3:
        VarSet(VAR_0x8005, sThirdPlaceRewards[Random() % ARRAY_COUNT(sThirdPlaceRewards)]);
        break;
    default:
        VarSet(VAR_0x8005, BUG_CONTEST_CONSOLATION_PRIZE);
        break;
    }

    return FALSE;
}

// VAR_0x8000: place 1 to 3. STR_VAR_1: species, STR_VAR_2: entrant, VAR_RESULT: score.
void BufferBugContestResult(void)
{
    u32 place = gSpecialVar_0x8000;
    u32 id;

    if (place == 0 || place > BUG_CONTEST_ENTRANTS)
        place = 1;
    id = sBugContestRanking[place - 1];
    StringCopy(gStringVar1, GetSpeciesName(sBugContestEntries[id].species));
    if (id == BUG_CONTEST_PLAYER)
        StringCopy(gStringVar2, gSaveBlock2Ptr->playerName);
    else
        StringCopy(gStringVar2, sBugContestNpcNames[id]);
    gSpecialVar_Result = sBugContestEntries[id].score;
}

static bool32 IsPlayerDefeated(u32 battleOutcome)
{
    switch (battleOutcome)
    {
    case B_OUTCOME_LOST:
    case B_OUTCOME_DREW:
        return TRUE;
    case B_OUTCOME_WON:
    case B_OUTCOME_RAN:
    case B_OUTCOME_PLAYER_TELEPORTED:
    case B_OUTCOME_MON_FLED:
    case B_OUTCOME_CAUGHT:
        return FALSE;
    default:
        return FALSE;
    }
}

void CB2_EndBugContestBattle(void)
{
    CpuFill16(0, (void *)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);
    u8 partyCount = 0;
    for (u8 i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
            partyCount++;
    }

    if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        SetMainCallback2(CB2_BugContestWhiteOut);
    }
    else if (gBattleOutcome == B_OUTCOME_CAUGHT)
    {
        if (partyCount == GetMaxPartySize())
            ScriptContext_SetupScript(BugContest_EventScript_TimesUp);
        SetMainCallback2(CB2_ReturnToField);
        gFieldCallback = FieldCB_ReturnToFieldNoScriptCheckMusic;
    }
    else
    {
        SetMainCallback2(CB2_ReturnToField);
        gFieldCallback = FieldCB_ReturnToFieldNoScriptCheckMusic;
    }
}

bool8 RemoveSportBalls(void)
{
    u16 count = CountTotalItemQuantityInBag(ITEM_SPORT_BALL);

    if (count > 0)
        RemoveBagItem(ITEM_SPORT_BALL, count);

    return FALSE;
}

#else

void BugContestRetirePrompt(void) {}
void EnterBugContestMode(void) {}
void ExitBugContestMode(void) {}
bool8 TransferBugContestMon(void) { return FALSE; }
bool8 JudgeBugContestMon(void) { return FALSE; }
bool8 RemoveSportBalls(void) { return FALSE; }
void PrepareBugContestJudging(void) {}
void BufferBugContestResult(void) {}
bool32 GetBugContestFlag(void) { return FALSE; }
void CB2_EndBugContestBattle(void) {}
bool8 BugContestCheckTimeLimit(void) { return FALSE; }
const u8 BugContest_EventScript_WhiteOut[] = {0};
const u8 BugContest_EventScript_TimesUp[] = {0};

#endif