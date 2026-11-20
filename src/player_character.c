#include "global.h"
#include "player_character.h"
#include "pokemon.h"
#include "constants/event_objects.h"
#include "constants/trainers.h"

// Player characters of the new game intro. Index: PLAYER_CHARACTER_*.
// Red and Leaf only have FRLG overworld sheets; a state without one uses the
// Gold (Red) or Kris (Leaf) sheet until their own sheets exist.
const struct PlayerCharacterInfo gPlayerCharacterInfo[PLAYER_CHARACTER_COUNT] =
{
    [PLAYER_CHARACTER_RED] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rot"),
#else
        .name = COMPOUND_STRING("RED"),
#endif
        .gender = MALE,
        .facilityClass = FACILITY_CLASS_RED,
        .backPic = TRAINER_PIC_BACK_RED,
        .avatarGfxIds =
        {
            [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_RED_NORMAL,
            [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_RED_BIKE,
            [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_GOLD_ACRO_BIKE_HNS,   // fallback: Gold, no Red acro bike sheet yet
            [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_RED_SURF,
            [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_GOLD_UNDERWATER_HNS,  // fallback: Gold, no Red underwater sheet yet
            [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_RED_FIELD_MOVE,
            [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_RED_FISH,
            [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_GOLD_WATERING_HNS,    // fallback: Gold, no Red watering sheet yet
        },
        .decoratingGfxId = OBJ_EVENT_GFX_GOLD_DECORATING_HNS,                       // fallback: Gold, no Red decorating sheet yet
        .paletteTag = OBJ_EVENT_PAL_TAG_PLAYER_RED,
    },
    [PLAYER_CHARACTER_LEAF] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Leaf"),
#else
        .name = COMPOUND_STRING("LEAF"),
#endif
        .gender = FEMALE,
        .facilityClass = FACILITY_CLASS_LEAF,
        .backPic = TRAINER_PIC_BACK_LEAF,
        .avatarGfxIds =
        {
            [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_GREEN_NORMAL,
            [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_GREEN_BIKE,
            [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_KRIS_ACRO_BIKE_HNS,   // fallback: Kris, no Leaf acro bike sheet yet
            [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_GREEN_SURF,
            [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_KRIS_UNDERWATER_HNS,  // fallback: Kris, no Leaf underwater sheet yet
            [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_GREEN_FIELD_MOVE,
            [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_GREEN_FISH,
            [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_KRIS_WATERING_HNS,    // fallback: Kris, no Leaf watering sheet yet
        },
        .decoratingGfxId = OBJ_EVENT_GFX_KRIS_DECORATING_HNS,                       // fallback: Kris, no Leaf decorating sheet yet
        .paletteTag = OBJ_EVENT_PAL_TAG_PLAYER_GREEN,
    },
    [PLAYER_CHARACTER_GOLD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gold"),
#else
        .name = COMPOUND_STRING("GOLD"),
#endif
        .gender = MALE,
        .facilityClass = FACILITY_CLASS_GOLD_HNS,
        .backPic = TRAINER_PIC_BACK_GOLD_HNS,
        .avatarGfxIds =
        {
            [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_GOLD_NORMAL_HNS,
            [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_GOLD_MACH_BIKE_HNS,
            [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_GOLD_ACRO_BIKE_HNS,
            [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_GOLD_SURFING_HNS,
            [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_GOLD_UNDERWATER_HNS,
            [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_GOLD_FIELD_MOVE_HNS,
            [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_GOLD_FISHING_HNS,
            [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_GOLD_WATERING_HNS,
        },
        .decoratingGfxId = OBJ_EVENT_GFX_GOLD_DECORATING_HNS,
        .paletteTag = OBJ_EVENT_PAL_TAG_GOLD_HNS,
    },
    [PLAYER_CHARACTER_KRIS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kris"),
#else
        .name = COMPOUND_STRING("KRIS"),
#endif
        .gender = FEMALE,
        .facilityClass = FACILITY_CLASS_KRIS_HNS,
        .backPic = TRAINER_PIC_BACK_KRIS_HNS,
        .avatarGfxIds =
        {
            [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_KRIS_NORMAL_HNS,
            [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_KRIS_MACH_BIKE_HNS,
            [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_KRIS_ACRO_BIKE_HNS,
            [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_KRIS_SURFING_HNS,
            [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_KRIS_UNDERWATER_HNS,
            [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_KRIS_FIELD_MOVE_HNS,
            [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_KRIS_FISHING_HNS,
            [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_KRIS_WATERING_HNS,
        },
        .decoratingGfxId = OBJ_EVENT_GFX_KRIS_DECORATING_HNS,
        .paletteTag = OBJ_EVENT_PAL_TAG_KRIS_HNS,
    },
    [PLAYER_CHARACTER_BRENDAN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Brix"),
#else
        .name = COMPOUND_STRING("BRENDAN"),
#endif
        .gender = MALE,
        .facilityClass = FACILITY_CLASS_BRENDAN,
        .backPic = TRAINER_PIC_BACK_BRENDAN,
        .avatarGfxIds =
        {
            [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_BRENDAN_NORMAL,
            [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_BRENDAN_MACH_BIKE,
            [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_BRENDAN_ACRO_BIKE,
            [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_BRENDAN_SURFING,
            [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_BRENDAN_UNDERWATER,
            [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE,
            [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_BRENDAN_FISHING,
            [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_BRENDAN_WATERING,
        },
        .decoratingGfxId = OBJ_EVENT_GFX_BRENDAN_DECORATING,
        .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN,
    },
    [PLAYER_CHARACTER_MAY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Maike"),
#else
        .name = COMPOUND_STRING("MAY"),
#endif
        .gender = FEMALE,
        .facilityClass = FACILITY_CLASS_MAY,
        .backPic = TRAINER_PIC_BACK_MAY,
        .avatarGfxIds =
        {
            [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_MAY_NORMAL,
            [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_MAY_MACH_BIKE,
            [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_MAY_ACRO_BIKE,
            [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_MAY_SURFING,
            [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_MAY_UNDERWATER,
            [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_MAY_FIELD_MOVE,
            [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_MAY_FISHING,
            [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_MAY_WATERING,
        },
        .decoratingGfxId = OBJ_EVENT_GFX_MAY_DECORATING,
        .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    },
};

// Never returns PLAYER_CHARACTER_NONE: an old save (byte 0) gets the look it had, by gender.
u8 GetPlayerCharacter(void)
{
    u8 character = gSaveBlock2Ptr->playerCharacter;

    if (character != PLAYER_CHARACTER_NONE && character < PLAYER_CHARACTER_COUNT)
        return character;
#if IS_HNS
    return gSaveBlock2Ptr->playerGender == FEMALE ? PLAYER_CHARACTER_KRIS : PLAYER_CHARACTER_GOLD;
#elif IS_FRLG
    return gSaveBlock2Ptr->playerGender == FEMALE ? PLAYER_CHARACTER_LEAF : PLAYER_CHARACTER_RED;
#else
    return gSaveBlock2Ptr->playerGender == FEMALE ? PLAYER_CHARACTER_MAY : PLAYER_CHARACTER_BRENDAN;
#endif
}

const struct PlayerCharacterInfo *GetPlayerCharacterInfo(void)
{
    return &gPlayerCharacterInfo[GetPlayerCharacter()];
}

// The Hoenn rival is May, except for May herself: then it is Brendan.
bool8 IsHoennRivalBrendan(void)
{
    return GetPlayerCharacter() == PLAYER_CHARACTER_MAY;
}

// Saves the character and its gender, so gender texts and checkplayergender keep working.
void SetPlayerCharacter(u8 character)
{
    if (character == PLAYER_CHARACTER_NONE || character >= PLAYER_CHARACTER_COUNT)
        return;
    gSaveBlock2Ptr->playerCharacter = character;
    gSaveBlock2Ptr->playerGender = gPlayerCharacterInfo[character].gender;
}

// Also a special: specialvar VAR_OBJ_GFX_ID_x, GetPlayerCharacterGfxId
u16 GetPlayerCharacterGfxId(void)
{
    return GetPlayerCharacterInfo()->avatarGfxIds[PLAYER_AVATAR_STATE_NORMAL];
}

u16 GetPlayerCharacterFrontPicId(void)
{
    return FacilityClassToPicIndex(GetPlayerCharacterInfo()->facilityClass);
}

u16 GetPlayerCharacterBackPicId(void)
{
    return GetPlayerCharacterInfo()->backPic;
}
