#ifndef GUARD_CONSTANTS_PLAYER_CHARACTER_H
#define GUARD_CONSTANTS_PLAYER_CHARACTER_H

// Player character chosen in the new game intro, saved in gSaveBlock2Ptr->playerCharacter.
// NONE is an old save (or no choice yet): the character then follows playerGender
// (Gold or Kris). Saved values, never renumber them.
// Scripts: specialvar VAR_RESULT, GetPlayerCharacter (never returns NONE).
#define PLAYER_CHARACTER_NONE       0
#define PLAYER_CHARACTER_RED        1   // FireRed
#define PLAYER_CHARACTER_LEAF       2   // LeafGreen
#define PLAYER_CHARACTER_GOLD       3   // Gold/Silver
#define PLAYER_CHARACTER_KRIS       4   // Crystal
#define PLAYER_CHARACTER_BRENDAN    5   // Emerald
#define PLAYER_CHARACTER_MAY        6   // Emerald
#define PLAYER_CHARACTER_COUNT      7   // table size, NONE included

#endif // GUARD_CONSTANTS_PLAYER_CHARACTER_H
