#ifndef GUARD_NAMING_SCREEN_H
#define GUARD_NAMING_SCREEN_H

#include "main.h"

enum {
    NAMING_SCREEN_PLAYER,
    NAMING_SCREEN_BOX,
    NAMING_SCREEN_CAUGHT_MON,
    NAMING_SCREEN_NICKNAME,
    NAMING_SCREEN_WALDA,
    NAMING_SCREEN_CODE,
    NAMING_SCREEN_RIVAL,
};

extern void BattleMainCB2(void);

void DoNamingScreen(u8 templateNum, u8 *destBuffer, u16 monSpecies, u16 monGender, u32 monPersonality, bool8 isShiny, MainCallback returnCallback);

// Set by the caller before DoNamingScreen: B on an empty name leaves the screen
// without saving and sets gNamingScreenWentBack. Both are cleared on every exit.
extern bool8 gNamingScreenBackOnEmpty;
extern bool8 gNamingScreenWentBack;

#endif // GUARD_NAMING_SCREEN_H
