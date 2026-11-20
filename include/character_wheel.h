#ifndef GUARD_CHARACTER_WHEEL_H
#define GUARD_CHARACTER_WHEEL_H

#include "config/character_wheel.h"
#include "task.h"

#if OJ_CHARACTER_WHEEL
// Shows the character wheel over the running screen, with `character` in front.
// windowId: a window (frame drawn by the caller) for the question and the name;
// the caller clears it afterwards. The trainer pics fade in against BG1.
// On A the choice is saved with SetPlayerCharacter, the wheel's sprites, palettes,
// matrices and task are freed, BLDCNT/BLDALPHA are restored and the task
// callerTaskId continues with onConfirm.
void StartCharacterWheel(u8 character, u8 windowId, u8 callerTaskId, TaskFunc onConfirm);
#endif

#endif // GUARD_CHARACTER_WHEEL_H
