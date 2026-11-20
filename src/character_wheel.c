#include "global.h"
#include "character_wheel.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "list_menu.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "player_character.h"
#include "pokemon.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "util.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#if OJ_CHARACTER_WHEEL

// Character wheel of the new game intro: the six trainer pics stand on an
// ellipse, the one in front is full size, the others get smaller and darker
// towards the back. Slot i holds PLAYER_CHARACTER_RED + i; going right from
// the front: Red, Leaf, Gold, Kris, Brendan, May.

#define WHEEL_COUNT         (PLAYER_CHARACTER_COUNT - PLAYER_CHARACTER_RED)
#define WHEEL_STEP          256                         // angle between two neighbours
#define WHEEL_CIRCLE        (WHEEL_COUNT * WHEEL_STEP)  // full turn

// Ellipse the feet stand on (screen pixels)
#define WHEEL_CENTER_X      120
#define WHEEL_CENTER_Y      108
#define WHEEL_RADIUS_X      88
#define WHEEL_RADIUS_Y      44
#define WHEEL_FEET_Y        31      // pic centre to feet at full size

#define WHEEL_SCALE_BACK    128     // size at the back, Q8 (0.5); front is 256
#define WHEEL_DARK_MAX      7       // BlendPalette coefficient (of 16) towards black at the back
#define WHEEL_TURN_FRAMES   16      // one step, eased out
#define WHEEL_FADE_STEPS    16      // BLDALPHA fade 0..16 in, 16..0 out, one step per frame

#define WHEEL_ARROW_X       44      // turn arrows, left and right of the front character
#define WHEEL_ARROW_Y       (WHEEL_CENTER_Y + WHEEL_RADIUS_Y - WHEEL_FEET_Y)
#define TAG_WHEEL_ARROW     0x7A10

enum {
    WHEEL_STATE_FADE_IN,
    WHEEL_STATE_INPUT,
    WHEEL_STATE_TURN,
    WHEEL_STATE_FADE_OUT,
};

#define tState          data[0]
#define tFront          data[1]     // slot in front, or turning to the front
#define tPos            data[2]     // wheel angle: tFront * WHEEL_STEP at rest
#define tFrom           data[3]     // wheel angle when the turn started
#define tDelta          data[4]     // +-WHEEL_STEP
#define tTimer          data[5]
#define tAlpha          data[6]
#define tWindowId       data[7]
#define tArrowTaskId    data[8]
#define tArrowOffset    data[9]     // scroll offset for the arrows: 1 shows both, 0 hides both
#define tCallerTaskId   data[10]
#define tOnConfirm      11          // data[11] and data[12]: TaskFunc
#define tSavedBldCnt    data[13]
#define tSavedBldAlpha  data[14]

#define sSlot           data[0]
#define sTaskId         data[1]
#define sDark           data[2]     // blend coefficient now in the palette

static void Task_CharacterWheel(u8 taskId);
static void SpriteCB_WheelCharacter(struct Sprite *sprite);

#if GERMAN
static const u8 sText_WhoAreYou[] = _("Wer bist du?");
#else
static const u8 sText_WhoAreYou[] = _("Who are you?");
#endif

// sin of an angle in 1/WHEEL_CIRCLE turns as Q8, between the gSineTable entries
static s32 WheelSin(s32 angle)
{
    s32 pos, index, frac, a, b;

    angle %= WHEEL_CIRCLE;
    if (angle < 0)
        angle += WHEEL_CIRCLE;
    pos = angle * 256;
    index = pos / WHEEL_CIRCLE;
    frac = pos % WHEEL_CIRCLE;
    a = gSineTable[index];
    b = gSineTable[(index + 1) & 0xFF];
    return a + (b - a) * frac / WHEEL_CIRCLE;
}

static void PrintFrontName(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    const u8 *name = gPlayerCharacterInfo[PLAYER_CHARACTER_RED + tFront].name;
    u32 width = GetWindowAttribute(tWindowId, WINDOW_WIDTH) * 8;

    FillWindowPixelBuffer(tWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(tWindowId, FONT_NORMAL, sText_WhoAreYou, 4, 1, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(tWindowId, FONT_NORMAL, name, width - 4 - GetStringWidth(FONT_NORMAL, name, 0), 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(tWindowId, COPYWIN_GFX);
}

void StartCharacterWheel(u8 character, u8 windowId, u8 callerTaskId, TaskFunc onConfirm)
{
    u8 taskId = CreateTask(Task_CharacterWheel, 0);
    s16 *data = gTasks[taskId].data;
    u32 i;

    if (character < PLAYER_CHARACTER_RED || character >= PLAYER_CHARACTER_COUNT)
        character = PLAYER_CHARACTER_RED;
    tState = WHEEL_STATE_FADE_IN;
    tFront = character - PLAYER_CHARACTER_RED;
    tPos = tFront * WHEEL_STEP;
    tAlpha = 0;
    tWindowId = windowId;
    tCallerTaskId = callerTaskId;
    SetWordTaskArg(taskId, tOnConfirm, (u32)onConfirm);

    // The trainer pics fade in over BG1 like the intro's own sprites
    tSavedBldCnt = GetGpuReg(REG_OFFSET_BLDCNT);
    tSavedBldAlpha = GetGpuReg(REG_OFFSET_BLDALPHA);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));

    for (i = 0; i < WHEEL_COUNT; i++)
    {
        u8 spriteId = CreateTrainerSprite(FacilityClassToPicIndex(gPlayerCharacterInfo[PLAYER_CHARACTER_RED + i].facilityClass), 0, 0, 0, NULL);
        struct Sprite *sprite = &gSprites[spriteId];

        sprite->oam.priority = 0;
        sprite->oam.objMode = ST_OAM_OBJ_BLEND;
        sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
        InitSpriteAffineAnim(sprite); // own matrix, set by the callback (the dummy affine anim never touches it)
        sprite->sSlot = i;
        sprite->sTaskId = taskId;
        sprite->sDark = 0xFF;
        sprite->callback = SpriteCB_WheelCharacter;
        SpriteCB_WheelCharacter(sprite);
    }

    // Shown only while the wheel stands still (both thresholds 0: offset 0 hides both)
    tArrowOffset = 0;
    tArrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_LEFT, WHEEL_ARROW_Y,
                                                            WHEEL_CENTER_X - WHEEL_ARROW_X, WHEEL_CENTER_X + WHEEL_ARROW_X,
                                                            0, TAG_WHEEL_ARROW, TAG_WHEEL_ARROW, (u16 *)&tArrowOffset);

    PutWindowTilemap(windowId);
    PrintFrontName(taskId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void StartTurn(u8 taskId, s32 direction)
{
    s16 *data = gTasks[taskId].data;

    PlaySECursorMove(SE_SELECT);
    tFrom = tPos;
    tDelta = direction * WHEEL_STEP;
    tTimer = 0;
    tArrowOffset = 0;
    tFront = (tFront + direction + WHEEL_COUNT) % WHEEL_COUNT;
    PrintFrontName(taskId);
    tState = WHEEL_STATE_TURN;
}

static void DestroyWheel(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u32 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];

        if (!sprite->inUse || sprite->callback != SpriteCB_WheelCharacter)
            continue;
        // CreateTrainerSprite's template is gone, so free by tile start and palette slot
        BlendPalette(OBJ_PLTT_ID(sprite->oam.paletteNum), 16, 0, RGB_BLACK);
        FreeSpriteOamMatrix(sprite);
        FreeSpriteTilesByTag(GetSpriteTileTagByTileStart(sprite->sheetTileStart));
        FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(sprite->oam.paletteNum));
        DestroySprite(sprite);
    }
    SetGpuReg(REG_OFFSET_BLDCNT, tSavedBldCnt);
    SetGpuReg(REG_OFFSET_BLDALPHA, tSavedBldAlpha);
    gTasks[tCallerTaskId].func = (TaskFunc)GetWordTaskArg(taskId, tOnConfirm);
    DestroyTask(taskId);
}

static void Task_CharacterWheel(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case WHEEL_STATE_FADE_IN:
        if (++tAlpha >= WHEEL_FADE_STEPS)
        {
            tArrowOffset = 1;
            tState = WHEEL_STATE_INPUT;
        }
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(tAlpha, WHEEL_FADE_STEPS - tAlpha));
        break;
    case WHEEL_STATE_INPUT:
        // B does nothing, as in the list
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            SetPlayerCharacter(PLAYER_CHARACTER_RED + tFront);
            RemoveScrollIndicatorArrowPair(tArrowTaskId);
            tState = WHEEL_STATE_FADE_OUT;
        }
        else if (JOY_HELD(DPAD_RIGHT))
        {
            StartTurn(taskId, 1);
        }
        else if (JOY_HELD(DPAD_LEFT))
        {
            StartTurn(taskId, -1);
        }
        break;
    case WHEEL_STATE_TURN:
        // ease out: the step covered after t frames is sin(t / WHEEL_TURN_FRAMES * 90 degrees)
        tTimer++;
        tPos = tFrom + tDelta * gSineTable[tTimer * 64 / WHEEL_TURN_FRAMES] / 256;
        if (tTimer >= WHEEL_TURN_FRAMES)
        {
            tPos = tFront * WHEEL_STEP;
            tArrowOffset = 1;
            tState = WHEEL_STATE_INPUT;
        }
        break;
    case WHEEL_STATE_FADE_OUT:
        if (--tAlpha <= 0)
        {
            DestroyWheel(taskId);
            return;
        }
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(tAlpha, WHEEL_FADE_STEPS - tAlpha));
        break;
    }
}

// Places a trainer pic on the ellipse: position, size, darkness and draw order
// all follow from its angle (0 = in front, WHEEL_CIRCLE / 2 = at the back).
static void SpriteCB_WheelCharacter(struct Sprite *sprite)
{
    s32 angle = sprite->sSlot * WHEEL_STEP - gTasks[sprite->sTaskId].tPos;
    s32 sin = WheelSin(angle);
    s32 cos = WheelSin(angle + WHEEL_CIRCLE / 4);
    s32 depth = (256 + cos) / 2;                                        // 0 back .. 256 front
    s32 scale = WHEEL_SCALE_BACK + (256 - WHEEL_SCALE_BACK) * depth / 256;
    s32 dark = (WHEEL_DARK_MAX * (65536 - depth * depth) + 32768) / 65536;
    u16 matrix = 0x10000 / scale;

    sprite->x = WHEEL_CENTER_X + WHEEL_RADIUS_X * sin / 256;
    sprite->y = WHEEL_CENTER_Y + WHEEL_RADIUS_Y * cos / 256 - WHEEL_FEET_Y * scale / 256;
    sprite->subpriority = 1 + (256 - depth) / 2;                        // front on top, arrows (0) above all
    SetOamMatrix(sprite->oam.matrixNum, matrix, 0, 0, matrix);
    if (dark != sprite->sDark)
    {
        sprite->sDark = dark;
        BlendPalette(OBJ_PLTT_ID(sprite->oam.paletteNum), 16, dark, RGB_BLACK);
    }
}

#endif // OJ_CHARACTER_WHEEL
