#ifndef GUARD_PLAYER_CHARACTER_H
#define GUARD_PLAYER_CHARACTER_H

#include "constants/player_character.h"

// Everything that shows the local player and used to be chosen by gender.
// Link partners and the union room still go by gender (only the gender is sent).
struct PlayerCharacterInfo
{
    const u8 *name;                                 // intro list entry and default player name
    u8 gender;                                      // MALE, FEMALE: written to playerGender
    u8 facilityClass;                               // front pic (intro, trainer card, Hall of Fame, battle intro)
    u16 backPic;                                    // battle back pic (TRAINER_PIC_BACK_*), its own throw animation
    u16 avatarGfxIds[PLAYER_AVATAR_STATE_COUNT];    // overworld graphics per PLAYER_AVATAR_STATE_*
    u16 decoratingGfxId;                            // decorating in a secret base / bedroom
    u16 paletteTag;                                 // overworld palette (tag of the normal gfx); reflections are made from it
};

extern const struct PlayerCharacterInfo gPlayerCharacterInfo[PLAYER_CHARACTER_COUNT];

u8 GetPlayerCharacter(void);
bool8 IsHoennRivalBrendan(void);
const struct PlayerCharacterInfo *GetPlayerCharacterInfo(void);
void SetPlayerCharacter(u8 character);
u16 GetPlayerCharacterGfxId(void);
u16 GetPlayerCharacterFrontPicId(void);
u16 GetPlayerCharacterBackPicId(void);

#endif // GUARD_PLAYER_CHARACTER_H
