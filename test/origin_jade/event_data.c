#include "global.h"
#include "event_data.h"
#include "test/test.h"

// Flag and var windows of GetFlagPointer/GetVarPointer (src/event_data.c), see
// docs/origin_jade/DECISIONS.md D-016.

// Byte of the flag, and the flag alone is set in it.
#define EXPECT_FLAG_AT(id, byte) \
    do \
    { \
        EXPECT_EQ(GetFlagPointer(id), &(byte)); \
        FlagSet(id); \
        EXPECT_EQ((byte), 1 << ((id) & 7)); \
        EXPECT(FlagGet(id)); \
        FlagClear(id); \
        EXPECT_EQ((byte), 0); \
    } while (0)

TEST("Flag routing: SaveBlock1 flags up to FLAGS_COUNT")
{
    EXPECT_EQ(GetFlagPointer(0), NULL);
    EXPECT_FLAG_AT(1, gSaveBlock1Ptr->flags[0]);
    EXPECT_FLAG_AT(FLAG_SYS_POKEMON_GET, gSaveBlock1Ptr->flags[FLAG_SYS_POKEMON_GET / 8]);
    EXPECT_FLAG_AT(FLAG_IS_HOENN_CHAMPION, gSaveBlock1Ptr->flags[FLAG_IS_HOENN_CHAMPION / 8]);
    EXPECT_FLAG_AT(FLAGS_COUNT - 1, gSaveBlock1Ptr->flags[NUM_FLAG_BYTES - 1]);
}

TEST("Flag routing: FRLG flags in SaveBlock3")
{
    EXPECT_FLAG_AT(FRLG_FLAGS_START, gSaveBlock3Ptr->flagsFrlg[0]);
    EXPECT_FLAG_AT(FLAG_HIDE_VERMILION_SS_AQUA, gSaveBlock3Ptr->flagsFrlg[(FLAG_HIDE_VERMILION_SS_AQUA - FRLG_FLAGS_START) / 8]);
    EXPECT_FLAG_AT(FRLG_FLAGS_END, gSaveBlock3Ptr->flagsFrlg[FRLG_NUM_FLAG_BYTES - 1]);
}

TEST("Flag routing: FRLG trainer and HnS rematch tier flags in SaveBlock3")
{
    EXPECT_FLAG_AT(FRLG_TRAINER_FLAGS_START, gSaveBlock3Ptr->flagsFrlgTrainers[0]);
    EXPECT_FLAG_AT(FRLG_TRAINER_FLAGS_END, gSaveBlock3Ptr->flagsFrlgTrainers[(FRLG_TRAINER_FLAGS_END - FRLG_TRAINER_FLAGS_START) / 8]);
    EXPECT_FLAG_AT(HNS_REMATCH_TIER_FLAGS_START, gSaveBlock3Ptr->flagsHnsRematchTiers[0]);
    EXPECT_FLAG_AT(HNS_REMATCH_TIER_FLAGS_END, gSaveBlock3Ptr->flagsHnsRematchTiers[(HNS_REMATCH_TIER_FLAGS_END - HNS_REMATCH_TIER_FLAGS_START) / 8]);
}

TEST("Flag routing: Origin Jade flags in SaveBlock3")
{
    EXPECT_FLAG_AT(OJ_FLAGS_START, gSaveBlock3Ptr->flagsOj[0]);
    EXPECT_FLAG_AT(FLAG_IS_JOHTO_CHAMPION, gSaveBlock3Ptr->flagsOj[(FLAG_IS_JOHTO_CHAMPION - OJ_FLAGS_START) / 8]);
    EXPECT_FLAG_AT(OJ_FLAGS_END, gSaveBlock3Ptr->flagsOj[OJ_NUM_FLAG_BYTES - 1]);
}

TEST("Flag routing: setting a flag leaves its neighbours alone")
{
    FlagSet(FLAG_IS_JOHTO_CHAMPION);
    EXPECT(!FlagGet(FLAG_IS_JOHTO_CHAMPION - 1));
    EXPECT(!FlagGet(FLAG_IS_JOHTO_CHAMPION + 1));
    FlagToggle(FLAG_IS_JOHTO_CHAMPION);
    EXPECT(!FlagGet(FLAG_IS_JOHTO_CHAMPION));
}

TEST("Var routing: SaveBlock1, FRLG and Origin Jade windows")
{
    EXPECT_EQ(GetVarPointer(VARS_START - 1), NULL);
    EXPECT_EQ(GetVarPointer(VARS_START), &gSaveBlock1Ptr->vars[0]);
    EXPECT_EQ(GetVarPointer(VARS_END), &gSaveBlock1Ptr->vars[VARS_COUNT - 1]);
    EXPECT_EQ(GetVarPointer(FRLG_VARS_START), &gSaveBlock3Ptr->varsFrlg[0]);
    EXPECT_EQ(GetVarPointer(FRLG_VARS_END), &gSaveBlock3Ptr->varsFrlg[FRLG_VARS_COUNT - 1]);
    EXPECT_EQ(GetVarPointer(OJ_VARS_START), &gSaveBlock3Ptr->varsOj[0]);
    EXPECT_EQ(GetVarPointer(OJ_VARS_END), &gSaveBlock3Ptr->varsOj[OJ_VARS_COUNT - 1]);
    EXPECT_EQ(GetVarPointer(VAR_RESULT), &gSpecialVar_Result);
}

TEST("Var routing: VarSet and VarGet use the same slot")
{
    EXPECT(VarSet(OJ_VARS_START + 1, 1234));
    EXPECT_EQ(VarGet(OJ_VARS_START + 1), 1234);
    EXPECT_EQ(gSaveBlock3Ptr->varsOj[1], 1234);
    EXPECT_EQ(VarGet(OJ_VARS_START), 0);
    EXPECT(VarSet(FRLG_VARS_START + 2, 77));
    EXPECT_EQ(gSaveBlock3Ptr->varsFrlg[2], 77);
    // Ids below VARS_START have no storage: VarGet returns the id.
    EXPECT_EQ(VarGet(5), 5);
}
