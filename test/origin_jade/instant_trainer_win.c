#include "global.h"
#include "battle_setup.h"
#include "debug.h"
#include "money.h"
#include "test/battle.h"

// Debug menu toggle "Instant Tr. Win" (src/battle_main.c), see
// docs/origin_jade/DECISIONS.md, D-055. The battle tests start with the
// toggle off; BattleTest_TearDown switches it off again.

// Money before the battle (GIVEN and THEN run in separate calls).
static u32 sMoneyBefore;

// EXP of a mon at the start of a level.
static u32 ExpAtLevel(u32 species, u32 level)
{
    return gExperienceTables[gSpeciesInfo[species].growthRate][level];
}

AI_SINGLE_BATTLE_TEST("Instant Trainer Win: every opposing mon faints, the player's mon gains EXP and keeps its HP")
{
    GIVEN {
        gDebugInstantTrainerWin = TRUE;
        sMoneyBefore = GetMoney(&gSaveBlock1Ptr->money);
        PLAYER(SPECIES_WOBBUFFET) { Level(20); HP(30); }
        OPPONENT(SPECIES_CATERPIE) { Level(10); }
        OPPONENT(SPECIES_WEEDLE) { Level(10); }
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(opponent);
        EXPERIENCE_BAR(player);
        HP_BAR(opponent);
        EXPERIENCE_BAR(player);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_WON);
        EXPECT_EQ(player->hp, 30);
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HP), 30);
        EXPECT_GT(GetMonData(&gPlayerParty[0], MON_DATA_EXP), ExpAtLevel(SPECIES_WOBBUFFET, 20));
        EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_HP), 0);
        EXPECT_EQ(GetMonData(&gEnemyParty[1], MON_DATA_HP), 0);
        EXPECT_GT(GetMoney(&gSaveBlock1Ptr->money), sMoneyBefore);
    }
}

AI_SINGLE_BATTLE_TEST("Instant Trainer Win: the trainer slide before the first turn still shows")
{
    GIVEN {
        gDebugInstantTrainerWin = TRUE;
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_BEFORE_FIRST_TURN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        MESSAGE("Trainer A: This message plays before the first turn.{PAUSE_UNTIL_PRESS}");
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_WON);
    }
}

AI_SINGLE_BATTLE_TEST("Instant Trainer Win: the trainer slide on the last switch-in still shows")
{
    GIVEN {
        gDebugInstantTrainerWin = TRUE;
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_LAST_SWITCHIN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(opponent);
        MESSAGE("Trainer A: This message plays after the enemy switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_WON);
    }
}

AI_DOUBLE_BATTLE_TEST("Instant Trainer Win: double battle, both player mons gain EXP and keep their HP")
{
    GIVEN {
        gDebugInstantTrainerWin = TRUE;
        PLAYER(SPECIES_WOBBUFFET) { Level(20); HP(40); }
        PLAYER(SPECIES_WYNAUT) { Level(20); HP(20); }
        OPPONENT(SPECIES_CATERPIE) { Level(10); }
        OPPONENT(SPECIES_WEEDLE) { Level(10); }
        OPPONENT(SPECIES_PIDGEY) { Level(10); }
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_WON);
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HP), 40);
        EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_HP), 20);
        EXPECT_GT(GetMonData(&gPlayerParty[0], MON_DATA_EXP), ExpAtLevel(SPECIES_WOBBUFFET, 20));
        EXPECT_GT(GetMonData(&gPlayerParty[1], MON_DATA_EXP), ExpAtLevel(SPECIES_WYNAUT, 20));
        EXPECT_EQ(GetMonData(&gEnemyParty[0], MON_DATA_HP), 0);
        EXPECT_EQ(GetMonData(&gEnemyParty[1], MON_DATA_HP), 0);
        EXPECT_EQ(GetMonData(&gEnemyParty[2], MON_DATA_HP), 0);
    }
}

AI_MULTI_BATTLE_TEST("Instant Trainer Win: multi battle with a partner against two trainers")
{
    GIVEN {
        gDebugInstantTrainerWin = TRUE;
        MULTI_PLAYER(SPECIES_WOBBUFFET) { HP(50); }
        MULTI_PARTNER(SPECIES_WYNAUT) { HP(25); }
        MULTI_OPPONENT_A(SPECIES_CATERPIE);
        MULTI_OPPONENT_B(SPECIES_WEEDLE);
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_WON);
        EXPECT_EQ(playerLeft->hp, 50);
        EXPECT_EQ(playerRight->hp, 25);
    }
}

AI_ONE_VS_TWO_BATTLE_TEST("Instant Trainer Win: double battle against two trainers")
{
    GIVEN {
        gDebugInstantTrainerWin = TRUE;
        MULTI_PLAYER(SPECIES_WOBBUFFET) { HP(50); }
        MULTI_PLAYER(SPECIES_WYNAUT) { HP(25); }
        MULTI_OPPONENT_A(SPECIES_CATERPIE);
        MULTI_OPPONENT_A(SPECIES_PIDGEY);
        MULTI_OPPONENT_B(SPECIES_WEEDLE);
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        HP_BAR(opponentLeft);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_WON);
        EXPECT_EQ(playerLeft->hp, 50);
        EXPECT_EQ(playerRight->hp, 25);
    }
}

AI_TWO_VS_ONE_BATTLE_TEST("Instant Trainer Win: partner and player against one trainer")
{
    GIVEN {
        gDebugInstantTrainerWin = TRUE;
        MULTI_PLAYER(SPECIES_WOBBUFFET) { HP(50); }
        MULTI_PARTNER(SPECIES_WYNAUT) { HP(25); }
        MULTI_OPPONENT_A(SPECIES_CATERPIE);
        MULTI_OPPONENT_A(SPECIES_WEEDLE);
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_WON);
        EXPECT_EQ(playerLeft->hp, 50);
        EXPECT_EQ(playerRight->hp, 25);
    }
}

AI_SINGLE_BATTLE_TEST("Instant Trainer Win: off, the trainer battle runs normally")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NOT HP_BAR(opponent);
    } THEN {
        EXPECT_NE(gBattleOutcome, B_OUTCOME_WON);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
    }
}

WILD_BATTLE_TEST("Instant Trainer Win: on, a wild battle runs normally")
{
    GIVEN {
        gDebugInstantTrainerWin = TRUE;
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_CATERPIE) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NOT HP_BAR(opponent);
    } THEN {
        EXPECT_NE(gBattleOutcome, B_OUTCOME_WON);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
    }
}

SINGLE_BATTLE_TEST("Instant Trainer Win: on, a recorded link battle runs normally")
{
    GIVEN {
        gDebugInstantTrainerWin = TRUE;
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        NOT HP_BAR(opponent);
    } THEN {
        EXPECT_NE(gBattleOutcome, B_OUTCOME_WON);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
    }
}
