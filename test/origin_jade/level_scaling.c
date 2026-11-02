#include "global.h"
#include "data.h"
#include "event_data.h"
#include "level_scaling.h"
#include "pokemon.h"
#include "test/test.h"
#include "config/hoenn_scaling.h"
#include "config/johto_scaling.h"
#include "config/kanto_scaling.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"

// Rules: include/config/*_scaling.h, docs/origin_jade/DECISIONS.md D-012, D-031, D-039.

static const struct Trainer sTrainer = { .trainerClass = TRAINER_CLASS_YOUNGSTER_HNS };
static const struct Trainer sBoss = { .trainerClass = TRAINER_CLASS_LEADER_HNS };
static const struct Trainer sHoennRival = { .trainerClass = TRAINER_CLASS_RIVAL };

// Map for GetScalingRules: map group (HnS, Emerald or FRLG maps) and mapsec.
static void SetMap(u32 map, u32 mapsec)
{
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(map);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(map);
    gMapHeader.regionMapSectionId = mapsec;
}

// Party of Wobbuffet with these levels; level 0 = egg at level 100.
static void SetParty(const u8 *levels, u32 count)
{
    u32 i;

    ZeroPlayerPartyMons();
    for (i = 0; i < count; i++)
    {
        CreateMon(&gPlayerParty[i], SPECIES_WOBBUFFET, levels[i] ? levels[i] : 100, 0, OTID_STRUCT_PLAYER_ID);
        if (levels[i] == 0)
        {
            bool32 isEgg = TRUE;
            SetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, &isEgg);
        }
    }
    CalculatePlayerPartyCount();
}

#define SET_PARTY(...) ({ static const u8 _levels[] = { __VA_ARGS__ }; SetParty(_levels, ARRAY_COUNT(_levels)); })

// Ace of an ordinary trainer, original level 10: lands on the anchor.
static u32 AceLevel(void)
{
    return ScaleTrainerMonLevel(&sTrainer, 10, 10);
}

TEST("Level scaling: anchor is the rounded mean of the three highest levels")
{
    u32 mapsec = gMapHeader.regionMapSectionId;
    u32 anchor = 0;

    // Johto after the title: no ceiling below 100.
    SetMap(MAP_ROUTE29_HNS, MAPSEC_ROUTE_29);
    FlagSet(FLAG_IS_JOHTO_CHAMPION);
    PARAMETRIZE { SET_PARTY(60, 55, 52, 10); anchor = 56; }
    PARAMETRIZE { SET_PARTY(50, 41); anchor = 46; }
    PARAMETRIZE { SET_PARTY(57); anchor = 57; }
    PARAMETRIZE { SET_PARTY(0, 0, 64, 60, 59); anchor = 61; }
    // Highest 100, the others level 1: mean 34, but at most 8 below 100.
    PARAMETRIZE { SET_PARTY(100, 1, 1, 1, 1, 1); anchor = 100 - SCALING_ANCHOR_MAX_DROP; }
    EXPECT_EQ(AceLevel(), anchor + JOHTO_SCALING_TRAINER_ABOVE);
    gMapHeader.regionMapSectionId = mapsec;
}

TEST("Level scaling: corridor clamps trainer, wild and static levels")
{
    u32 mapsec = gMapHeader.regionMapSectionId;
    u32 low, low2, high, high2, i;

    // Johto before the title: corridor of Route 29.
    SetMap(MAP_ROUTE29_HNS, MAPSEC_ROUTE_29);
    SET_PARTY(10);
    low = AceLevel();
    SET_PARTY(20);
    low2 = AceLevel();
    SET_PARTY(99, 99, 99);
    high = AceLevel();
    SET_PARTY(95, 95, 95);
    high2 = AceLevel();
    EXPECT_EQ(low, low2);
    EXPECT_GT(low, 20);
    EXPECT_EQ(high, high2);
    EXPECT_LT(high, 95);
    EXPECT_LT(low, high);
    for (i = 0; i < 20; i++)
        EXPECT_LE(ScaleWildMonLevel(5), high);
    EXPECT_EQ(ScaleStaticMonLevel(5), high);

    // The title lifts the ceiling, the floor stays.
    FlagSet(FLAG_IS_JOHTO_CHAMPION);
    EXPECT_EQ(AceLevel(), 95 + JOHTO_SCALING_TRAINER_ABOVE);
    SET_PARTY(10);
    EXPECT_EQ(AceLevel(), low);
    gMapHeader.regionMapSectionId = mapsec;
}

TEST("Level scaling: boss aces get the boss extra levels")
{
    u32 mapsec = gMapHeader.regionMapSectionId;

    SetMap(MAP_ROUTE29_HNS, MAPSEC_ROUTE_29);
    FlagSet(FLAG_IS_JOHTO_CHAMPION);
    SET_PARTY(60, 60, 60);
    EXPECT_EQ(ScaleTrainerMonLevel(&sTrainer, 30, 30), 60 + JOHTO_SCALING_TRAINER_ABOVE);
    EXPECT_EQ(ScaleTrainerMonLevel(&sBoss, 30, 30), 60 + JOHTO_SCALING_TRAINER_ABOVE + JOHTO_SCALING_BOSS_EXTRA);

    SetMap(MAP_ROUTE101, MAPSEC_ROUTE_101);
    FlagSet(FLAG_IS_HOENN_CHAMPION);
    SET_PARTY(90, 90, 90);
    EXPECT_EQ(ScaleTrainerMonLevel(&sTrainer, 30, 30), 90 + HOENN_SCALING_TRAINER_ABOVE);
    EXPECT_EQ(ScaleTrainerMonLevel(&sBoss, 30, 30), 90 + HOENN_SCALING_TRAINER_ABOVE + HOENN_SCALING_BOSS_EXTRA);
    // May and Wally count as bosses like Silver and Blue.
    EXPECT_EQ(ScaleTrainerMonLevel(&sHoennRival, 30, 30), 90 + HOENN_SCALING_TRAINER_ABOVE + HOENN_SCALING_BOSS_EXTRA);
    gMapHeader.regionMapSectionId = mapsec;
}

// Ace of a boss in each Johto league room, Will's first.
static void LeagueAces(u32 *aces)
{
    static const u16 sRooms[] =
    {
        MAP_POKEMON_LEAGUE_WILLS_ROOM_HNS,
        MAP_POKEMON_LEAGUE_KOGAS_ROOM_HNS,
        MAP_POKEMON_LEAGUE_BRUNOS_ROOM_HNS,
        MAP_POKEMON_LEAGUE_KARENS_ROOM_HNS,
        MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM_HNS,
    };
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sRooms); i++)
    {
        SetMap(sRooms[i], MAPSEC_INDIGO_PLATEAU);
        aces[i] = ScaleTrainerMonLevel(&sBoss, 50, 50);
    }
}

TEST("Level scaling: Johto league rooms rise from Will to Lance")
{
    u32 mapsec = gMapHeader.regionMapSectionId;
    u32 aces[5], i;

    // Average player at the league: the rooms' ceilings, the Elite Four within
    // the league corridor, the champion 2 above it.
    SET_PARTY(64, 64, 64);
    LeagueAces(aces);
    EXPECT_EQ(aces[0], 62);
    EXPECT_EQ(aces[3], 65);
    EXPECT_EQ(aces[4], 67);
    for (i = 1; i < ARRAY_COUNT(aces); i++)
        EXPECT_LT(aces[i - 1], aces[i]);

    // Weak team: the rooms' floors, still rising.
    SET_PARTY(45, 45, 45);
    LeagueAces(aces);
    EXPECT_EQ(aces[0], 58);
    EXPECT_EQ(aces[4], 63);
    for (i = 1; i < ARRAY_COUNT(aces); i++)
        EXPECT_LT(aces[i - 1], aces[i]);

    // After the title only the floors stay.
    FlagSet(FLAG_IS_JOHTO_CHAMPION);
    SET_PARTY(90, 90, 90);
    LeagueAces(aces);
    EXPECT_EQ(aces[0], 89);
    EXPECT_EQ(aces[4], 95);
    for (i = 1; i < ARRAY_COUNT(aces); i++)
        EXPECT_LT(aces[i - 1], aces[i]);

    // Victory Road keeps the league corridor and the boss extra.
    FlagClear(FLAG_IS_JOHTO_CHAMPION);
    SetMap(MAP_ROUTE29_HNS, MAPSEC_VICTORY_ROAD_HNS);
    SET_PARTY(64, 64, 64);
    EXPECT_EQ(ScaleTrainerMonLevel(&sBoss, 50, 50), 64 + JOHTO_SCALING_TRAINER_ABOVE + JOHTO_SCALING_BOSS_EXTRA);
    gMapHeader.regionMapSectionId = mapsec;
}

TEST("Level scaling: team members keep their distance, down to the trainer band")
{
    u32 mapsec = gMapHeader.regionMapSectionId;
    s32 top = 60 + JOHTO_SCALING_TRAINER_ABOVE;

    SetMap(MAP_ROUTE29_HNS, MAPSEC_ROUTE_29);
    FlagSet(FLAG_IS_JOHTO_CHAMPION);
    SET_PARTY(60, 60, 60);
    EXPECT_EQ(ScaleTrainerMonLevel(&sTrainer, 29, 30), max(top - 1, 60 - JOHTO_SCALING_TRAINER_BELOW));
    EXPECT_EQ(ScaleTrainerMonLevel(&sTrainer, 10, 30), 60 - JOHTO_SCALING_TRAINER_BELOW);
    // Original level at the fixed minimum or above: not scaled (Red).
    EXPECT_EQ(ScaleTrainerMonLevel(&sTrainer, JOHTO_SCALING_FIXED_MIN_LEVEL, JOHTO_SCALING_FIXED_MIN_LEVEL), JOHTO_SCALING_FIXED_MIN_LEVEL);
    gMapHeader.regionMapSectionId = mapsec;
}

TEST("Level scaling: wild levels stay in the wild band")
{
    u32 mapsec = gMapHeader.regionMapSectionId;
    u32 i, level;

    SetMap(MAP_ROUTE29_HNS, MAPSEC_ROUTE_29);
    FlagSet(FLAG_IS_JOHTO_CHAMPION);
    SET_PARTY(70, 70, 70);
    for (i = 0; i < 50; i++)
    {
        level = ScaleWildMonLevel(5);
        EXPECT_GE(level, 70 - JOHTO_SCALING_WILD_BELOW);
        EXPECT_LE(level, 70 - JOHTO_SCALING_WILD_ABOVE);
    }
    gMapHeader.regionMapSectionId = mapsec;
}

TEST("Level scaling: static encounters start at the top of the wild band in Johto and Hoenn")
{
    u32 mapsec = gMapHeader.regionMapSectionId;

    SetMap(MAP_ROUTE29_HNS, MAPSEC_ROUTE_29);
    FlagSet(FLAG_IS_JOHTO_CHAMPION);
    SET_PARTY(70, 70, 70);
    EXPECT_EQ(ScaleStaticMonLevel(30), 70 - JOHTO_SCALING_WILD_ABOVE);
    EXPECT_EQ(ScaleStaticMonLevel(80), 80);

    SetMap(MAP_ROUTE101, MAPSEC_ROUTE_101);
    FlagSet(FLAG_IS_HOENN_CHAMPION);
    SET_PARTY(90, 90, 90);
    EXPECT_EQ(ScaleStaticMonLevel(30), 90 - HOENN_SCALING_WILD_ABOVE);
    EXPECT_EQ(ScaleStaticMonLevel(100), 100);
    gMapHeader.regionMapSectionId = mapsec;
}

TEST("Level scaling: Kanto keeps its levels before the Kanto title")
{
    u32 mapsec = gMapHeader.regionMapSectionId;

    SetMap(MAP_PALLET_TOWN, MAPSEC_PALLET_TOWN);
    SET_PARTY(80, 80, 80);
    EXPECT(!LevelScalingActive());
    EXPECT_EQ(ScaleWildMonLevel(3), 3);
    EXPECT_EQ(ScaleStaticMonLevel(30), 30);
    EXPECT_EQ(ScaleTrainerMonLevel(&sTrainer, 5, 5), 5);
    gMapHeader.regionMapSectionId = mapsec;
}

TEST("Level scaling: Kanto after the title scales, never below the set level")
{
    u32 mapsec = gMapHeader.regionMapSectionId;

    SetMap(MAP_PALLET_TOWN, MAPSEC_PALLET_TOWN);
    FlagSet(FLAG_IS_KANTO_CHAMPION);
    SET_PARTY(60, 60, 60);
    EXPECT(LevelScalingActive());
    EXPECT_EQ(ScaleTrainerMonLevel(&sTrainer, 40, 40), 60 + KANTO_SCALING_TRAINER_ABOVE);
    EXPECT_EQ(ScaleTrainerMonLevel(&sTrainer, 70, 70), 70);
    // No static floor in Kanto.
    EXPECT_EQ(ScaleStaticMonLevel(30), 30);
    gMapHeader.regionMapSectionId = mapsec;
}

TEST("Level scaling: Hoenn and Johto mapsecs")
{
    EXPECT(IsHoennMapsec(MAPSEC_ROUTE_101));
    EXPECT(IsHoennMapsec(MAPSEC_VICTORY_ROAD));
    EXPECT(!IsHoennMapsec(MAPSEC_ROUTE_29));
    EXPECT(!IsHoennMapsec(MAPSEC_PALLET_TOWN));
}
