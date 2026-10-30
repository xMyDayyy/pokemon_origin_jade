#include "global.h"
#include "task.h"
#include "event_object_movement.h"
#include "item_use.h"
#include "event_scripts.h"
#include "event_data.h"
#include "script.h"
#include "event_object_lock.h"
#include "field_specials.h"
#include "item.h"
#include "item_menu.h"
#include "field_effect.h"
#include "script_movement.h"
#include "battle.h"
#include "battle_setup.h"
#include "random.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "vs_seeker.h"
#include "menu.h"
#include "regions.h"
#include "string_util.h"
#include "tv.h"
#include "malloc.h"
#include "field_screen_effect.h"
#include "gym_leader_rematch.h"
#include "sound.h"
#include "constants/battle_setup.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "constants/script_commands.h"
#include "constants/trainer_types.h"
#include "constants/field_effects.h"

// Documentation for the Vs. Seeker can be found in docs/tutorials/vs_seeker.md.
//
// Origin Jade: the VS Seeker works on Kanto's FRLG maps only and uses FireRed/LeafGreen's
// rematch table (src/data/vs_seeker_kanto.h). Its state lives in Origin Jade vars
// (VAR_VS_SEEKER_STEPS, VAR_VS_SEEKER_REMATCH_LO/HI) and FLAG_VS_SEEKER_CHARGING, never
// in the Match Call data, so Match Call, phone and gym rematches keep working
// everywhere, see docs/origin_jade/DECISIONS.md, D-034.

enum
{
   VSSEEKER_NOT_CHARGED,
   VSSEEKER_NO_ONE_IN_RANGE,
   VSSEEKER_CAN_USE,
};

typedef enum
{
    VSSEEKER_SINGLE_RESP_RAND,
    VSSEEKER_SINGLE_RESP_NO,
    VSSEEKER_SINGLE_RESP_YES
} VsSeekerSingleRespCode;

typedef enum
{
    VSSEEKER_RESPONSE_NO_RESPONSE,
    VSSEEKER_RESPONSE_UNFOUGHT_TRAINERS,
    VSSEEKER_RESPONSE_FOUND_REMATCHES
} VsSeekerResponseCode;

struct VsSeekerTrainerInfo
{
    const u8 *script;
    u16 trainerIdx;
    u8 localId;
    u8 objectEventId;
    s16 xCoord;
    s16 yCoord;
    u16 graphicsId;
};

struct VsSeekerStruct
{
    struct VsSeekerTrainerInfo trainerInfo[OBJECT_EVENTS_COUNT];
    u8 trainerIdxArray[OBJECT_EVENTS_COUNT];
    u8 runningBehaviourEtcArray[OBJECT_EVENTS_COUNT];
    u8 numRematchableTrainers;
};

// Kanto rematch table: one row per trainer, one column per progress tier.
#define KANTO_REMATCH_TIERS 6
#define SKIP 0xFFFF

struct KantoRematch
{
    u16 trainerIds[KANTO_REMATCH_TIERS];
};

#include "data/vs_seeker_kanto.h"

// Progress tiers = columns of sKantoRematches. FRLG's own milestones in brackets.
enum
{
    KANTO_REMATCH_TIER_FIRST_BATTLE,
    KANTO_REMATCH_TIER_VS_SEEKER,       // VS Seeker received (same)
    KANTO_REMATCH_TIER_4_BADGES,        // 4 Kanto badges (Celadon visited)
    KANTO_REMATCH_TIER_6_BADGES,        // 6 Kanto badges (Fuchsia visited)
    KANTO_REMATCH_TIER_KANTO_TITLE,     // Kanto title (Hall of Fame)
    KANTO_REMATCH_TIER_JOHTO_TITLE,     // Johto title (Sevii Islands finished)
};

#define KANTO_REMATCH_TIER_2_BADGES 4
#define KANTO_REMATCH_TIER_3_BADGES 6

// Level floor per tier before the Kanto title: a rematch team whose highest level
// is lower moves up as a whole until it reaches the floor (src/level_scaling.c).
// 0 = no floor. From the Kanto title on the teams scale instead, see
// docs/origin_jade/DECISIONS.md, D-031 and D-034.
// Keep each floor below the ace of the tier's next gym leader. A rematch team
// below its own first team is raised in src/data/trainers_frlg.party instead.
static const u8 sKantoRematchLevelFloors[KANTO_REMATCH_TIERS] =
{
    [KANTO_REMATCH_TIER_VS_SEEKER] = 18,
    [KANTO_REMATCH_TIER_4_BADGES]  = 30,
    [KANTO_REMATCH_TIER_6_BADGES]  = 37,
};

// Trainers that want a rematch are kept as a bit per local id in two vars.
#define VS_SEEKER_MAX_LOCAL_ID 32

// FRLG: a trainer with a rematch answers the VS Seeker in 70 of 100 cases.
#define VS_SEEKER_REMATCH_CHANCE 70

#define END_TRAINER_INFO 0xFF
// static declarations
static EWRAM_DATA struct VsSeekerStruct *sVsSeeker = NULL;

static void VsSeekerResetInBagStepCounter(void);
static void VsSeekerResetChargingStepCounter(void);
static void Task_ResetObjectsRematchWantedState(u8 taskId);
static void ResetMovementOfRematchableTrainers(u16 newMapGroup, u16 newMapNum);
static void Task_VsSeekerFrameCountdown(u8 taskId);
static void Task_VsSeeker_PlaySoundAndGetResponseCode(u8 taskId);
static void GatherNearbyTrainerInfo(void);
static void Task_VsSeeker_ShowResponseToPlayer(u8 taskId);
static u8 CanUseVsSeeker(void);
static u8 GetVsSeekerResponseInArea(void);
static u8 GetResponseMovementTypeFromTrainerGraphicsId(u16 graphicsId);
static u16 GetTrainerFlagFromScript(const u8 * script);
static void ClearAllTrainerRematchStates(void);
static bool8 IsTrainerVisibleOnScreen(struct VsSeekerTrainerInfo * trainerInfo);
static bool32 HasFightableTrainers(void);
static void StartTrainerObjectMovementScript(struct VsSeekerTrainerInfo * trainerInfo, const u8 * script);
static u8 GetCurVsSeekerResponse(s32 vsSeekerIdx, u16 trainerIdx);
static void StartAllRespondantIdleMovements(void);
static bool8 ObjectEventIdIsSane(u8 objectEventId);
static u8 GetRandomFaceDirectionMovementType();

#if GERMAN
static const u8 sText_BatteryNotChargedNeedXSteps[] = _("Die Batterie ist nicht aufgeladen.\pBenötigte Schritte zum\nAufladen: {STR_VAR_1}{PAUSE_UNTIL_PRESS}");
static const u8 sText_NoTrainersWithinRange[] = _("Keine Trainer in Reichweite, die\nkämpfen könnten…\pKampffahnder ausgeschaltet.{PAUSE_UNTIL_PRESS}");
static const u8 sText_TrainersNotReady[] = _("Die anderen Trainer sind noch nicht\nbereit zu kämpfen.\pIch muss eine Weile warten.{PAUSE_UNTIL_PRESS}");
static const u8 sText_OnlyWorksInKanto[] = _("Hier reagiert kein Trainer auf den\nKampffahnder.\pEr funktioniert nur in Kanto.{PAUSE_UNTIL_PRESS}");
#else
static const u8 sText_BatteryNotChargedNeedXSteps[] = _("The battery isn't charged enough.\pNo. of steps required to fully\ncharge the battery: {STR_VAR_1}{PAUSE_UNTIL_PRESS}");
static const u8 sText_NoTrainersWithinRange[] = _("There are no Trainers within range\nwho can battle…\pThe VS Seeker was turned off.{PAUSE_UNTIL_PRESS}");
static const u8 sText_TrainersNotReady[] = _("The other Trainers don't appear\nto be ready for battle.\pLet's wait till later.{PAUSE_UNTIL_PRESS}");
static const u8 sText_OnlyWorksInKanto[] = _("No Trainers here respond to\nthe VS Seeker.\pIt only works in Kanto.{PAUSE_UNTIL_PRESS}");
#endif

static const u8 sMovementScript_Wait48[] = {
    MOVEMENT_ACTION_DELAY_16,
    MOVEMENT_ACTION_DELAY_16,
    MOVEMENT_ACTION_DELAY_16,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sMovementScript_TrainerUnfought[] = {
    MOVEMENT_ACTION_EMOTE_EXCLAMATION_MARK,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sMovementScript_TrainerUnknown[] = {
    MOVEMENT_ACTION_EMOTE_QUESTION_MARK,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sMovementScript_TrainerNoRematch[] = {
    MOVEMENT_ACTION_EMOTE_X,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sMovementScript_TrainerRematch[] = {
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_DOWN,
    MOVEMENT_ACTION_EMOTE_DOUBLE_EXCL_MARK,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sFaceDirectionMovementTypeByFacingDirection[] = {
    MOVEMENT_TYPE_FACE_DOWN,
    MOVEMENT_TYPE_FACE_DOWN,
    MOVEMENT_TYPE_FACE_UP,
    MOVEMENT_TYPE_FACE_LEFT,
    MOVEMENT_TYPE_FACE_RIGHT
};

// ---------------------------------------------------------------------------
// Kanto rematch state (D-034)
// ---------------------------------------------------------------------------

// FRLG Kanto map: a Kanto mapsec outside HnS's map groups, as in src/level_scaling.c.
static bool32 IsVsSeekerMap(void)
{
    return GetCurrentRegion() == REGION_KANTO
        && gSaveBlock1Ptr->location.mapGroup >= MAP_GROUP(MAP_LITTLEROOT_TOWN);
}

static u32 GetRematchMask(void)
{
    return VarGet(VAR_VS_SEEKER_REMATCH_LO) | ((u32)VarGet(VAR_VS_SEEKER_REMATCH_HI) << 16);
}

static void SetRematchMask(u32 mask)
{
    VarSet(VAR_VS_SEEKER_REMATCH_LO, mask & 0xFFFF);
    VarSet(VAR_VS_SEEKER_REMATCH_HI, mask >> 16);
}

static bool32 IsLocalIdInMask(u32 localId, u32 mask)
{
    if (localId == 0 || localId > VS_SEEKER_MAX_LOCAL_ID)
        return FALSE;
    return (mask & (1u << (localId - 1))) != 0;
}

static void SetLocalIdWantsRematch(u32 localId, bool32 wantsRematch)
{
    u32 mask = GetRematchMask();

    if (localId == 0 || localId > VS_SEEKER_MAX_LOCAL_ID)
        return;
    if (wantsRematch)
        mask |= 1u << (localId - 1);
    else
        mask &= ~(1u << (localId - 1));
    SetRematchMask(mask);
}

// The wish ends when the VS Seeker has recharged (the flag is cleared then).
static bool32 DoesLocalIdWantRematch(u32 localId)
{
    return FlagGet(I_VS_SEEKER_CHARGING) && IsLocalIdInMask(localId, GetRematchMask());
}

// Row of sKantoRematches that holds this trainer at any tier, or -1.
static s32 GetKantoRematchRow(u16 trainerId)
{
    u32 i, j;

    if (trainerId == TRAINER_NONE || trainerId == SKIP)
        return -1;

    for (i = 0; i < ARRAY_COUNT(sKantoRematches); i++)
    {
        for (j = 0; j < KANTO_REMATCH_TIERS; j++)
        {
            if (sKantoRematches[i].trainerIds[j] == TRAINER_NONE)
                break;
            if (sKantoRematches[i].trainerIds[j] == trainerId)
                return i;
        }
    }
    return -1;
}

static u32 GetKantoBadgeCount(void)
{
    u32 i, count = 0;

    for (i = FLAG_BADGE01_GET; i <= FLAG_BADGE08_GET; i++)
    {
        if (FlagGet(i))
            count++;
    }
    return count;
}

static u32 GetKantoRematchTier(void)
{
    u32 badges;

    if (FlagGet(FLAG_IS_JOHTO_CHAMPION))
        return KANTO_REMATCH_TIER_JOHTO_TITLE;
    if (FlagGet(FLAG_IS_KANTO_CHAMPION))
        return KANTO_REMATCH_TIER_KANTO_TITLE;

    badges = GetKantoBadgeCount();
    if (badges >= KANTO_REMATCH_TIER_3_BADGES)
        return KANTO_REMATCH_TIER_6_BADGES;
    if (badges >= KANTO_REMATCH_TIER_2_BADGES)
        return KANTO_REMATCH_TIER_4_BADGES;
    return KANTO_REMATCH_TIER_VS_SEEKER;
}

bool32 IsKantoRematchTrainer(u16 trainerId)
{
    return GetKantoRematchRow(trainerId) != -1;
}

// Team for a rematch: the newest team up to the current tier. Without one the
// first team fights again, as in FRLG. TRAINER_NONE if the trainer has no rematch.
u16 GetKantoRematchTrainerId(u16 trainerId)
{
    s32 row = GetKantoRematchRow(trainerId);
    const u16 *trainerIds;
    s32 tier;

    if (row == -1)
        return TRAINER_NONE;

    trainerIds = sKantoRematches[row].trainerIds;
    for (tier = GetKantoRematchTier(); tier > KANTO_REMATCH_TIER_FIRST_BATTLE; tier--)
    {
        if (trainerIds[tier] != TRAINER_NONE && trainerIds[tier] != SKIP)
            return trainerIds[tier];
    }
    return trainerIds[KANTO_REMATCH_TIER_FIRST_BATTLE];
}

// FRLG's ShouldTryRematchBattle: the trainer has a rematch and was beaten once.
// Whether it wants one now decides DoesLastTalkedWantKantoRematch.
bool32 ShouldTryKantoRematch(u16 trainerId)
{
    s32 row = GetKantoRematchRow(trainerId);

    if (row == -1)
        return FALSE;
    return HasTrainerBeenFought(sKantoRematches[row].trainerIds[KANTO_REMATCH_TIER_FIRST_BATTLE]);
}

bool32 DoesLastTalkedWantKantoRematch(void)
{
    return DoesLocalIdWantRematch(gSpecialVar_LastTalked);
}

// For trainer sight: does this object of the current map want a Kanto rematch?
bool32 DoesKantoObjectWantRematch(u16 trainerId, u32 objectEventId)
{
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];

    if (objectEvent->mapNum != gSaveBlock1Ptr->location.mapNum
     || objectEvent->mapGroup != gSaveBlock1Ptr->location.mapGroup)
        return FALSE;
    return IsKantoRematchTrainer(trainerId) && DoesLocalIdWantRematch(objectEvent->localId);
}

void ClearKantoRematchOfLastTalked(void)
{
    SetLocalIdWantsRematch(gSpecialVar_LastTalked, FALSE);
}

// Level floor for this trainer's team in the battle being set up: the tier's floor
// in a Kanto VS Seeker rematch against it before the Kanto title, else 0.
// A double battle rematch is one trainer whose party holds both trainers' Pokemon.
u8 GetKantoRematchLevelFloor(const struct Trainer *trainer)
{
    u16 trainerId = TRAINER_BATTLE_PARAM.opponentA;
    u8 mode = GetTrainerBattleMode();

    if (gIsDebugBattle || !(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || !IsVsSeekerMap())
        return 0;
    if (mode != TRAINER_BATTLE_REMATCH && mode != TRAINER_BATTLE_REMATCH_DOUBLE)
        return 0;
    if (!IsKantoRematchTrainer(trainerId) || trainer != GetTrainerStructFromId(trainerId))
        return 0;
    // Same check that started the rematch (IsTrainerReadyForRematch).
    if (!DoesLastTalkedWantKantoRematch())
        return 0;
    return sKantoRematchLevelFloors[GetKantoRematchTier()];
}

// Debug menu: the VS Seeker can be used right away. Run EventScript_VsSeekerChargingDone
// afterwards so that trainers still waiting for a rematch stop spinning.
void VsSeekerSetFullyCharged(void)
{
    FlagClear(I_VS_SEEKER_CHARGING);
    VarSet(VAR_VS_SEEKER_STEPS, VSSEEKER_RECHARGE_STEPS);
}

// ---------------------------------------------------------------------------

void VsSeekerFreezeObjectsAfterChargeComplete(void)
{
    CreateTask(Task_ResetObjectsRematchWantedState, 80);
}

#define tIsPlayerFrozen data[0]
#define tAreObjectsFrozen data[1]

static void Task_ResetObjectsRematchWantedState(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u32 i;

    if ((!task->tIsPlayerFrozen) && IsPlayerStandingStill())
    {
        PlayerFreeze();
        task->tIsPlayerFrozen = TRUE;
    }

    if (!task->tAreObjectsFrozen)
    {
        for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        {
            if (!ObjectEventIdIsSane(i))
                continue;

            if (gObjectEvents[i].singleMovementActive)
                return;

            FreezeObjectEvent(&gObjectEvents[i]);
        }
    }

    task->tAreObjectsFrozen = TRUE;
    if (task->tIsPlayerFrozen)
    {
        DestroyTask(taskId);
        StopPlayerAvatar();
        ScriptContext_Enable();
    }
}
#undef tIsPlayerFrozen
#undef tAreObjectsFrozen

// The VS Seeker has recharged: the trainers that wanted a rematch go back to the
// movement of their map template.
void VsSeekerResetObjectMovementAfterChargeComplete(void)
{
    struct ObjectEventTemplate *templates = gSaveBlock1Ptr->objectEventTemplates;
    u32 i, j;
    u32 mask = GetRematchMask();
    u8 movementType;
    u8 objEventId;

    for (i = 0; i < gMapHeader.events->objectEventCount; i++)
    {
        if (!IsLocalIdInMask(templates[i].localId, mask))
            continue;

        movementType = GetRandomFaceDirectionMovementType();
        for (j = 0; j < gMapHeader.events->objectEventCount; j++)
        {
            if (gMapHeader.events->objectEvents[j].localId == templates[i].localId
             && gMapHeader.events->objectEvents[j].kind != OBJ_KIND_CLONE)
            {
                movementType = gMapHeader.events->objectEvents[j].movementType;
                break;
            }
        }
        templates[i].movementType = movementType;

        if (TryGetObjectEventIdByLocalIdAndMap(templates[i].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objEventId))
            continue;
        if (ObjectEventIdIsSane(objEventId))
            SetTrainerMovementType(&gObjectEvents[objEventId], movementType);
    }
    ClearAllTrainerRematchStates();
}

bool8 UpdateVsSeekerStepCounter(void)
{
    u32 steps, inBag, charging;

    if (!I_VS_SEEKER_CHARGING)
        return FALSE;

    steps = VarGet(VAR_VS_SEEKER_STEPS);
    inBag = steps & 0xFF;
    charging = steps >> 8;
    if (inBag > VSSEEKER_RECHARGE_STEPS)
        inBag = VSSEEKER_RECHARGE_STEPS;
    if (charging > VSSEEKER_RECHARGE_STEPS)
        charging = VSSEEKER_RECHARGE_STEPS;

    if (inBag < VSSEEKER_RECHARGE_STEPS && CheckBagHasItem(ITEM_VS_SEEKER, 1))
        inBag++;

    if (FlagGet(I_VS_SEEKER_CHARGING))
    {
        if (charging < VSSEEKER_RECHARGE_STEPS)
            charging++;
        if (charging == VSSEEKER_RECHARGE_STEPS)
        {
            // EventScript_VsSeekerChargingDone resets the trainers and clears their wish.
            FlagClear(I_VS_SEEKER_CHARGING);
            VarSet(VAR_VS_SEEKER_STEPS, inBag);
            return TRUE;
        }
    }

    VarSet(VAR_VS_SEEKER_STEPS, inBag | (charging << 8));
    return FALSE;
}

// Called on every map change: the wish to battle ends when the player leaves.
void MapResetTrainerRematches(u16 mapGroup, u16 mapNum)
{
    if (!I_VS_SEEKER_CHARGING)
        return;

    if (GetRematchMask() != 0)
        ResetMovementOfRematchableTrainers(mapGroup, mapNum);
    FlagClear(I_VS_SEEKER_CHARGING);
    VsSeekerResetChargingStepCounter();
    ClearAllTrainerRematchStates();
}

// Objects of the map just left can still be on screen after a map connection.
// Only those that answered the VS Seeker stop spinning.
static void ResetMovementOfRematchableTrainers(u16 newMapGroup, u16 newMapNum)
{
    u32 i;
    u32 mask = GetRematchMask();

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        struct ObjectEvent * objectEvent = &gObjectEvents[i];

        if (!objectEvent->active || objectEvent->isPlayer || gSprites[objectEvent->spriteId].data[0] != i)
            continue;
        if (objectEvent->mapGroup == newMapGroup && objectEvent->mapNum == newMapNum)
            continue;
        if (objectEvent->movementType != MOVEMENT_TYPE_ROTATE_CLOCKWISE || !IsLocalIdInMask(objectEvent->localId, mask))
            continue;

        gSprites[objectEvent->spriteId].x2 = 0;
        gSprites[objectEvent->spriteId].y2 = 0;
        SetTrainerMovementType(objectEvent, GetRandomFaceDirectionMovementType());
    }
}

// Low byte of VAR_VS_SEEKER_STEPS: steps since the last use.
static void VsSeekerResetInBagStepCounter(void)
{
    VarSet(VAR_VS_SEEKER_STEPS, VarGet(VAR_VS_SEEKER_STEPS) & 0xFF00);
}

// High byte of VAR_VS_SEEKER_STEPS: steps since trainers started to want a rematch.
static void VsSeekerResetChargingStepCounter(void)
{
    VarSet(VAR_VS_SEEKER_STEPS, VarGet(VAR_VS_SEEKER_STEPS) & 0x00FF);
}

#define tCountdown      data[0]
#define tBeepDelay      data[1]
#define tNumBeeps       data[2]
#define tResponseCode   data[3]

void Task_InitVsSeekerAndCheckForTrainersOnScreen(u8 taskId)
{
    u32 i;
    u32 respval;

    if (!I_VS_SEEKER_CHARGING) return;

    for (i = 0; i < 16; i++)
        gTasks[taskId].data[i] = 0;

    if (!IsVsSeekerMap())
    {
        DisplayItemMessageOnField(taskId, sText_OnlyWorksInKanto, Task_ItemUse_CloseMessageBoxAndReturnToField_VsSeeker);
        return;
    }

    sVsSeeker = AllocZeroed(sizeof(struct VsSeekerStruct));
    GatherNearbyTrainerInfo();
    respval = CanUseVsSeeker();
    if (respval == VSSEEKER_NOT_CHARGED)
    {
        Free(sVsSeeker);
        sVsSeeker = NULL;
        DisplayItemMessageOnField(taskId, sText_BatteryNotChargedNeedXSteps, Task_ItemUse_CloseMessageBoxAndReturnToField_VsSeeker);
    }
    else if (respval == VSSEEKER_NO_ONE_IN_RANGE)
    {
        Free(sVsSeeker);
        sVsSeeker = NULL;
        DisplayItemMessageOnField(taskId, sText_NoTrainersWithinRange, Task_ItemUse_CloseMessageBoxAndReturnToField_VsSeeker);
    }
    else if (respval == VSSEEKER_CAN_USE)
    {
        FieldEffectStart(FLDEFF_USE_VS_SEEKER);
        gTasks[taskId].func = Task_VsSeekerFrameCountdown;
        gTasks[taskId].tCountdown = 15;
    }
}



static void Task_VsSeekerFrameCountdown(u8 taskId)
{
    if (--gTasks[taskId].tCountdown == 0)
    {
        gTasks[taskId].func = Task_VsSeeker_PlaySoundAndGetResponseCode;
        gTasks[taskId].tBeepDelay = 16;
    }
}

static void Task_VsSeeker_PlaySoundAndGetResponseCode(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (tNumBeeps != 2 && --tBeepDelay == 0)
    {
        PlaySE(SE_CONTEST_MONS_TURN);
        tBeepDelay = 11;
        tNumBeeps++;
    }

    if (!FieldEffectActiveListContains(FLDEFF_USE_VS_SEEKER))
    {
        VsSeekerResetInBagStepCounter();
        tResponseCode = GetVsSeekerResponseInArea();
        ScriptMovement_StartObjectMovementScript(LOCALID_PLAYER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, sMovementScript_Wait48);
        gTasks[taskId].func = Task_VsSeeker_ShowResponseToPlayer;
    }
}

static void Task_VsSeeker_ShowResponseToPlayer(u8 taskId)
{
    if (!ScriptMovement_IsObjectMovementFinished(LOCALID_PLAYER, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup))
        return;

    if (gTasks[taskId].tResponseCode == VSSEEKER_RESPONSE_NO_RESPONSE)
    {
        DisplayItemMessageOnField(taskId, sText_TrainersNotReady, Task_ItemUse_CloseMessageBoxAndReturnToField_VsSeeker);
    }
    else
    {
        if (gTasks[taskId].tResponseCode == VSSEEKER_RESPONSE_FOUND_REMATCHES)
            StartAllRespondantIdleMovements();

        ClearDialogWindowAndFrame(0, TRUE);
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        DestroyTask(taskId);
    }
    Free(sVsSeeker);
    sVsSeeker = NULL;
}

#undef tCountdown
#undef tBeepDelay
#undef tNumBeeps
#undef tResponseCode

// Trainers on the current map that are spawned (only those can be on screen).
static void GatherNearbyTrainerInfo(void)
{
    struct ObjectEventTemplate *templates = gSaveBlock1Ptr->objectEventTemplates;
    u8 objectEventId = 0;
    u8 vsSeekerObjectIdx = 0;
    s32 objectEventIdx;

    for (objectEventIdx = 0; objectEventIdx < gMapHeader.events->objectEventCount; objectEventIdx++)
    {
        u16 trainerIdx;

        if (vsSeekerObjectIdx >= OBJECT_EVENTS_COUNT - 1)
            break;

        trainerIdx = GetTrainerFlagFromScript(templates[objectEventIdx].script);
        if (trainerIdx == TRAINER_NONE && (!I_SHOW_NO_ID_TRAINER || templates[objectEventIdx].trainerType == TRAINER_TYPE_NONE))
            continue;
        if (TryGetObjectEventIdByLocalIdAndMap(templates[objectEventIdx].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId))
            continue;
        if (trainerIdx == TRAINER_NONE && templates[objectEventIdx].trainerType != TRAINER_TYPE_NONE)
            DebugPrintf("Object event with local id %d is not TRAINER_TYPE_NONE but doesn't have a visible trainerID", templates[objectEventIdx].localId);
        sVsSeeker->trainerInfo[vsSeekerObjectIdx].script = templates[objectEventIdx].script;
        sVsSeeker->trainerInfo[vsSeekerObjectIdx].trainerIdx = trainerIdx;
        sVsSeeker->trainerInfo[vsSeekerObjectIdx].localId = templates[objectEventIdx].localId;
        sVsSeeker->trainerInfo[vsSeekerObjectIdx].objectEventId = objectEventId;
        sVsSeeker->trainerInfo[vsSeekerObjectIdx].xCoord = gObjectEvents[objectEventId].currentCoords.x - MAP_OFFSET;
        sVsSeeker->trainerInfo[vsSeekerObjectIdx].yCoord = gObjectEvents[objectEventId].currentCoords.y - MAP_OFFSET;
        sVsSeeker->trainerInfo[vsSeekerObjectIdx].graphicsId = templates[objectEventIdx].graphicsId;
        vsSeekerObjectIdx++;
    }
    sVsSeeker->trainerInfo[vsSeekerObjectIdx].localId = END_TRAINER_INFO;
}

static u8 CanUseVsSeeker(void)
{
    u32 vsSeekerChargeSteps = VarGet(VAR_VS_SEEKER_STEPS) & 0xFF;

    if (vsSeekerChargeSteps >= VSSEEKER_RECHARGE_STEPS)
    {
        if (!HasFightableTrainers())
            return VSSEEKER_NO_ONE_IN_RANGE;
        return VSSEEKER_CAN_USE;
    }

    ConvertIntToDecimalStringN(gStringVar1, (VSSEEKER_RECHARGE_STEPS - vsSeekerChargeSteps), STR_CONV_MODE_LEFT_ALIGN, 3);
    return VSSEEKER_NOT_CHARGED;
}

// A beaten trainer with a Kanto rematch whose local id can be stored.
static bool32 CanTrainerWantRematch(struct VsSeekerTrainerInfo *trainerInfo)
{
    if (trainerInfo->localId == 0 || trainerInfo->localId > VS_SEEKER_MAX_LOCAL_ID)
        return FALSE;
    return ShouldTryKantoRematch(trainerInfo->trainerIdx);
}

// FRLG: all objects of an answering trainer want the rematch, also the
// off-screen partner of a double battle trainer.
static void SetTrainerWantsRematch(u16 trainerIdx)
{
    struct ObjectEventTemplate *templates = gSaveBlock1Ptr->objectEventTemplates;
    u32 i;

    for (i = 0; i < gMapHeader.events->objectEventCount; i++)
    {
        if (GetTrainerFlagFromScript(templates[i].script) == trainerIdx)
            SetLocalIdWantsRematch(templates[i].localId, TRUE);
    }
}

static u8 GetVsSeekerResponseInArea(void)
{
    u32 trainerIdx, response, rval;
    s32 vsSeekerIdx;
    bool32 trainerHasNotYetBeenFought = FALSE;
    bool32 trainerWantsRematch = FALSE;

    // Wishes from an earlier use have ended with the recharge.
    ClearAllTrainerRematchStates();

    for (vsSeekerIdx = 0; sVsSeeker->trainerInfo[vsSeekerIdx].localId != END_TRAINER_INFO; vsSeekerIdx++)
    {
        struct VsSeekerTrainerInfo *trainerInfo = &sVsSeeker->trainerInfo[vsSeekerIdx];

        if (!IsTrainerVisibleOnScreen(trainerInfo))
            continue;

        trainerIdx = trainerInfo->trainerIdx;
        if (trainerIdx == TRAINER_NONE)
        {
            StartTrainerObjectMovementScript(trainerInfo, sMovementScript_TrainerUnknown);
            continue;
        }

        if (!HasTrainerBeenFought(trainerIdx))
        {
            StartTrainerObjectMovementScript(trainerInfo, sMovementScript_TrainerUnfought);
            trainerHasNotYetBeenFought = TRUE;
            continue;
        }

        if (!CanTrainerWantRematch(trainerInfo))
        {
            StartTrainerObjectMovementScript(trainerInfo, sMovementScript_TrainerNoRematch);
            continue;
        }

        // Both objects of a double battle trainer answer the same way.
        rval = Random() % 100;
        response = GetCurVsSeekerResponse(vsSeekerIdx, trainerIdx);
        if (response == VSSEEKER_SINGLE_RESP_YES)
            rval = 100;
        else if (response == VSSEEKER_SINGLE_RESP_NO)
            rval = 0;

        if (rval < 100 - VS_SEEKER_REMATCH_CHANCE)
        {
            StartTrainerObjectMovementScript(trainerInfo, sMovementScript_TrainerNoRematch);
            continue;
        }

        SetTrainerWantsRematch(trainerIdx);
        ShiftStillObjectEventCoords(&gObjectEvents[trainerInfo->objectEventId]);
        StartTrainerObjectMovementScript(trainerInfo, sMovementScript_TrainerRematch);
        sVsSeeker->trainerIdxArray[sVsSeeker->numRematchableTrainers] = vsSeekerIdx;
        sVsSeeker->runningBehaviourEtcArray[sVsSeeker->numRematchableTrainers] = GetResponseMovementTypeFromTrainerGraphicsId(trainerInfo->graphicsId);
        sVsSeeker->numRematchableTrainers++;
        trainerWantsRematch = TRUE;
    }

    if (trainerWantsRematch)
    {
        PlaySE(SE_PIN);
        FlagSet(I_VS_SEEKER_CHARGING);
        VsSeekerResetChargingStepCounter();
        return VSSEEKER_RESPONSE_FOUND_REMATCHES;
    }

    if (trainerHasNotYetBeenFought)
        return VSSEEKER_RESPONSE_UNFOUGHT_TRAINERS;

    return VSSEEKER_RESPONSE_NO_RESPONSE;
}

// Answer of an earlier visible object with the same trainer, if there is one.
static u8 GetCurVsSeekerResponse(s32 vsSeekerIdx, u16 trainerIdx)
{
    s32 i, j;

    for (i = 0; i < vsSeekerIdx; i++)
    {
        if (!IsTrainerVisibleOnScreen(&sVsSeeker->trainerInfo[i]) || sVsSeeker->trainerInfo[i].trainerIdx != trainerIdx)
            continue;

        for (j = 0; j < sVsSeeker->numRematchableTrainers; j++)
        {
            if (sVsSeeker->trainerIdxArray[j] == i)
                return VSSEEKER_SINGLE_RESP_YES;
        }
        return VSSEEKER_SINGLE_RESP_NO;
    }
    return VSSEEKER_SINGLE_RESP_RAND;
}

static bool32 ShouldChangeMovementForTrainerType(u32 trainerType)
{
    if (trainerType == TRAINER_TYPE_NORMAL)
        return TRUE;
    return (trainerType == TRAINER_TYPE_BURIED);
}

// After a won rematch: the trainer (both objects of a double battle) stops spinning
// and no longer wants a rematch.
void ClearRematchMovementByTrainerId(void)
{
    s32 i;
    u8 objEventId = 0;
    struct ObjectEventTemplate *objectEventTemplates = gSaveBlock1Ptr->objectEventTemplates;
    struct ObjectEvent *objectEvent;
    s32 row = GetKantoRematchRow(TRAINER_BATTLE_PARAM.opponentA);

    if (!I_VS_SEEKER_CHARGING) return;

    if (row == -1)
        return;

    for (i = 0; i < gMapHeader.events->objectEventCount; i++)
    {
        if (!ShouldChangeMovementForTrainerType(objectEventTemplates[i].trainerType)
        || row != GetKantoRematchRow(GetTrainerFlagFromScript(objectEventTemplates[i].script)))
            continue;

        SetLocalIdWantsRematch(objectEventTemplates[i].localId, FALSE);
        if (TryGetObjectEventIdByLocalIdAndMap(objectEventTemplates[i].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objEventId))
            continue;
        objectEvent = &gObjectEvents[objEventId];
        TryOverrideTemplateCoordsForObjectEvent(objectEvent, sFaceDirectionMovementTypeByFacingDirection[objectEvent->facingDirection]);

        if (gSelectedObjectEvent == objEventId)
            objectEvent->movementType = sFaceDirectionMovementTypeByFacingDirection[objectEvent->facingDirection];
        else
            objectEvent->movementType = MOVEMENT_TYPE_FACE_DOWN;
    }
}

static bool8 ObjectEventIdIsSane(u8 objectEventId)
{
    struct ObjectEvent *objectEvent;

    if (objectEventId >= OBJECT_EVENTS_COUNT)
        return FALSE;
    objectEvent = &gObjectEvents[objectEventId];
    if (objectEvent->active && gMapHeader.events->objectEventCount >= objectEvent->localId && gSprites[objectEvent->spriteId].data[0] == objectEventId)
        return TRUE;
    return FALSE;
}

static u8 GetRandomFaceDirectionMovementType()
{
    u16 randomFacingDirection = Random() % 4;

    switch (randomFacingDirection)
    {
    case 0:
        return MOVEMENT_TYPE_FACE_UP;
    case 1:
        return MOVEMENT_TYPE_FACE_DOWN;
    case 2:
        return MOVEMENT_TYPE_FACE_LEFT;
    case 3:
        return MOVEMENT_TYPE_FACE_RIGHT;
    default:
        return MOVEMENT_TYPE_FACE_DOWN;
    }
}

static bool32 IsRegularLandTrainer(u16 graphicsId)
{
    u32 i;
    u16 regularTrainersOnLand[] =
    {
        OBJ_EVENT_GFX_AQUA_MEMBER_F,
        OBJ_EVENT_GFX_AQUA_MEMBER_M,
        OBJ_EVENT_GFX_BEAUTY,
        OBJ_EVENT_GFX_BLACK_BELT,
        OBJ_EVENT_GFX_BOY_1,
        OBJ_EVENT_GFX_BOY_2,
        OBJ_EVENT_GFX_BOY_3,
        OBJ_EVENT_GFX_BUG_CATCHER,
        OBJ_EVENT_GFX_CAMPER,
        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_F,
        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_M,
        OBJ_EVENT_GFX_EXPERT_F,
        OBJ_EVENT_GFX_EXPERT_M,
        OBJ_EVENT_GFX_FAT_MAN,
        OBJ_EVENT_GFX_FISHERMAN,
        OBJ_EVENT_GFX_GENTLEMAN,
        OBJ_EVENT_GFX_GIRL_1,
        OBJ_EVENT_GFX_GIRL_2,
        OBJ_EVENT_GFX_GIRL_3,
        OBJ_EVENT_GFX_HEX_MANIAC,
        OBJ_EVENT_GFX_HIKER,
        OBJ_EVENT_GFX_LASS,
        OBJ_EVENT_GFX_LITTLE_BOY,
        OBJ_EVENT_GFX_LITTLE_GIRL,
        OBJ_EVENT_GFX_MAGMA_MEMBER_F,
        OBJ_EVENT_GFX_MAGMA_MEMBER_M,
        OBJ_EVENT_GFX_MAN_3,
        OBJ_EVENT_GFX_MAN_4,
        OBJ_EVENT_GFX_MAN_5,
        OBJ_EVENT_GFX_MANIAC,
        OBJ_EVENT_GFX_NINJA_BOY,
        OBJ_EVENT_GFX_PICNICKER,
        OBJ_EVENT_GFX_POKEFAN_F,
        OBJ_EVENT_GFX_POKEFAN_M,
        OBJ_EVENT_GFX_PSYCHIC_M,
        OBJ_EVENT_GFX_RICH_BOY,
        OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F,
        OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M,
        OBJ_EVENT_GFX_SAILOR,
        OBJ_EVENT_GFX_SCHOOL_KID_M,
        OBJ_EVENT_GFX_TUBER_F,
        OBJ_EVENT_GFX_TUBER_M,
        OBJ_EVENT_GFX_TWIN,
        OBJ_EVENT_GFX_WOMAN_1,
        OBJ_EVENT_GFX_WOMAN_2,
        OBJ_EVENT_GFX_WOMAN_4,
        OBJ_EVENT_GFX_WOMAN_5,
        OBJ_EVENT_GFX_YOUNGSTER,
        OBJ_EVENT_GFX_TUBER_F_FRLG,
        OBJ_EVENT_GFX_SAILOR_FRLG,
        OBJ_EVENT_GFX_HIKER_FRLG,
        OBJ_EVENT_GFX_PICNICKER_FRLG,
        OBJ_EVENT_GFX_CAMPER_FRLG,
        OBJ_EVENT_GFX_BEAUTY_FRLG,
        OBJ_EVENT_GFX_WOMAN_2_FRLG,
        OBJ_EVENT_GFX_FAT_MAN_FRLG,
        OBJ_EVENT_GFX_BUG_CATCHER_FRLG,
        OBJ_EVENT_GFX_WOMAN_1_FRLG,
        OBJ_EVENT_GFX_YOUNGSTER_FRLG,
        OBJ_EVENT_GFX_LASS_FRLG,
        OBJ_EVENT_GFX_LITTLE_GIRL_FRLG,
        OBJ_EVENT_GFX_LITTLE_BOY_FRLG,
        // Further FRLG trainers that spin in FireRed/LeafGreen.
        OBJ_EVENT_GFX_BOY,
        OBJ_EVENT_GFX_MAN,
        OBJ_EVENT_GFX_ROCKER,
        OBJ_EVENT_GFX_BALDING_MAN,
        OBJ_EVENT_GFX_COOLTRAINER_M,
        OBJ_EVENT_GFX_COOLTRAINER_F,
        OBJ_EVENT_GFX_SWIMMER_M_LAND,
        OBJ_EVENT_GFX_SWIMMER_F_LAND,
        OBJ_EVENT_GFX_BLACKBELT,
    };

    for (i = 0; i < ARRAY_COUNT(regularTrainersOnLand); i++)
    {
        if (graphicsId == regularTrainersOnLand[i])
            return TRUE;
    }
    return FALSE;
}

static bool32 IsRegularWaterTrainer(u16 graphicsId)
{
    u32 i;
    u16 regularTrainersInWater[] =
    {
        OBJ_EVENT_GFX_SWIMMER_F,
        OBJ_EVENT_GFX_SWIMMER_M,
        OBJ_EVENT_GFX_TUBER_M_SWIMMING,
        OBJ_EVENT_GFX_SWIMMER_F_WATER,
        OBJ_EVENT_GFX_SWIMMER_M_WATER,
        OBJ_EVENT_GFX_TUBER_M_WATER,
    };

    for (i = 0; i < ARRAY_COUNT(regularTrainersInWater); i++)
    {
        if (graphicsId == regularTrainersInWater[i])
            return TRUE;
    }
    return FALSE;
}

static u8 GetResponseMovementTypeFromTrainerGraphicsId(u16 graphicsId)
{
    if (IsRegularLandTrainer(graphicsId) || IsRegularWaterTrainer(graphicsId))
        return MOVEMENT_TYPE_ROTATE_CLOCKWISE;

    return MOVEMENT_TYPE_FACE_DOWN;
}

static u16 GetTrainerFlagFromScript(const u8 *script)
{
    // The trainer flag is located 3 bytes (command + flags + localIdA) from the script pointer, assuming the trainerbattle command is first in the script.
    // Because scripts are unaligned, and because the ARM processor requires shorts to be 16-bit aligned, this function needs to perform explicit bitwise operations to get the correct flag.
    u16 trainerFlag = TRAINER_NONE;
    struct ScriptContext *ctx;

    if (script == NULL)
        return TRAINER_NONE;

    ctx = AllocZeroed(sizeof(struct ScriptContext));
    if (script[0] == SCR_OP_TRAINERBATTLE)
    {
        ctx->scriptPtr = script + 3;
        trainerFlag = ScriptPeekHalfword(ctx);
    }
    else if (Script_MatchesCallNative(script, NativeVsSeekerRematchId, TRUE))
    {
        ctx->scriptPtr = script + 5;
        trainerFlag = ScriptPeekHalfword(ctx);
    }
    Free(ctx);
    return trainerFlag;
}

static void ClearAllTrainerRematchStates(void)
{
    SetRematchMask(0);
}

static bool8 IsTrainerVisibleOnScreen(struct VsSeekerTrainerInfo * trainerInfo)
{
    s16 x;
    s16 y;

    PlayerGetDestCoords(&x, &y);
    x -= MAP_OFFSET;
    y -= MAP_OFFSET;

    if (   x - 7 <= trainerInfo->xCoord
        && x + 7 >= trainerInfo->xCoord
        && y - 5 <= trainerInfo->yCoord
        && y + 5 >= trainerInfo->yCoord
        && ObjectEventIdIsSane(trainerInfo->objectEventId))
        return TRUE;
    return FALSE;
}

// FRLG: the VS Seeker only starts when a trainer in view is unbeaten or has a rematch.
static bool32 HasFightableTrainers(void)
{
    u32 i;

    for (i = 0; sVsSeeker->trainerInfo[i].localId != END_TRAINER_INFO; i++)
    {
        if (sVsSeeker->trainerInfo[i].trainerIdx == TRAINER_NONE)
            continue;
        if (IsTrainerVisibleOnScreen(&sVsSeeker->trainerInfo[i]))
        {
            if (!HasTrainerBeenFought(sVsSeeker->trainerInfo[i].trainerIdx) || CanTrainerWantRematch(&sVsSeeker->trainerInfo[i]))
                return TRUE;
        }
    }

    return FALSE;
}

static void StartTrainerObjectMovementScript(struct VsSeekerTrainerInfo * trainerInfo, const u8 * script)
{
    UnfreezeObjectEvent(&gObjectEvents[trainerInfo->objectEventId]);
    ScriptMovement_StartObjectMovementScript(trainerInfo->localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, script);
}

void NativeVsSeekerRematchId(struct ScriptContext *ctx)
{
    u16 trainerId = ScriptReadHalfword(ctx);
    if (ctx->breakOnTrainerBattle && HasTrainerBeenFought(trainerId) && !ShouldTryRematchBattleForTrainerId(trainerId))
        StopScript(ctx);
}


static void StartAllRespondantIdleMovements(void)
{
    s32 i;
    s32 j;

    for (i = 0; i < sVsSeeker->numRematchableTrainers; i++)
    {
        j = sVsSeeker->trainerIdxArray[i];
        struct ObjectEvent *objectEvent = &gObjectEvents[sVsSeeker->trainerInfo[j].objectEventId];

        if (ShouldChangeMovementForTrainerType(objectEvent->trainerType))
        {
            if (ObjectEventIdIsSane(sVsSeeker->trainerInfo[j].objectEventId))
                SetTrainerMovementType(objectEvent, sVsSeeker->runningBehaviourEtcArray[i]);
            TryOverrideTemplateCoordsForObjectEvent(objectEvent, sVsSeeker->runningBehaviourEtcArray[i]);
        }
    }
}
