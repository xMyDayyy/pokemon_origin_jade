#ifndef GUARD_VS_SEEKER_H
#define GUARD_VS_SEEKER_H

#include "global.h"

struct Trainer;

void Task_InitVsSeekerAndCheckForTrainersOnScreen(u8 taskId);
bool8 UpdateVsSeekerStepCounter(void);
void MapResetTrainerRematches(u16 mapGroup, u16 mapNum);
void ClearRematchMovementByTrainerId(void);
void NativeVsSeekerRematchId(struct ScriptContext *ctx);

// Kanto rematches through the VS Seeker, see docs/origin_jade/DECISIONS.md, D-034.
bool32 IsKantoRematchTrainer(u16 trainerId);
u16 GetKantoRematchTrainerId(u16 trainerId);
bool32 ShouldTryKantoRematch(u16 trainerId);
bool32 DoesLastTalkedWantKantoRematch(void);
bool32 DoesKantoObjectWantRematch(u16 trainerId, u32 objectEventId);
void ClearKantoRematchOfLastTalked(void);
u8 GetKantoRematchLevelFloor(const struct Trainer *trainer);
void VsSeekerSetFullyCharged(void);

#define VSSEEKER_RECHARGE_STEPS 100

#endif //GUARD_VS_SEEKER_H
