#include "battle_dynamax.h"
#include "battle_anim_scripts.h"
#include "constants/battle.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/contest.h"

// The Gen. 4+ contest data comes from urpg's contest movedex.

#if B_BINDING_TURNS >= GEN_5
#if GERMAN
#define BINDING_TURNS "4 oder 5"
#else
#define BINDING_TURNS "4 or 5"
#endif
#else
#if GERMAN
#define BINDING_TURNS "2 bis 5"
#else
#define BINDING_TURNS "2 to 5"
#endif
#endif

// Shared Move Description entries

#if GERMAN
const u8 gNotDoneYetDescription[] = _(
    "Diese Attacke ist noch\n"
    "nicht fertig entwickelt.");
#else
const u8 gNotDoneYetDescription[] = _(
    "This move can't be used. Its\n"
    "effect is in development.");
#endif

static const u8 sNullDescription[] = _("");

#if GERMAN
static const u8 sMegaDrainDescription[] = _(
    "Saugt dem Ziel die Hälfte des\n"
    "Schadens als KP ab.");
#else
static const u8 sMegaDrainDescription[] = _(
    "Attack that absorbs\n"
    "half the damage inflicted.");
#endif

#if B_SKIP_RECHARGE != GEN_1
#if GERMAN
static const u8 sHyperBeamDescription[] = _(
    "Starke Attacke. Angreifer\n"
    "setzt eine Runde aus.");
#else
static const u8 sHyperBeamDescription[] = _(
    "Leaves the user immobile\n"
    "if target is not KO'd.");
#endif
#else
#if GERMAN
static const u8 sHyperBeamDescription[] = _(
    "Setzt aus, wenn der Gegner\n"
    "nicht besiegt wird.");
#else
static const u8 sHyperBeamDescription[] = _(
    "Leaves the user immobile\n"
    "if target is not KO'd.");
#endif
#endif

#if GERMAN
static const u8 sRevengeDescription[] = _(
    "Attacke wird stärker, wenn\n"
    "Anwender Schaden nimmt.");
#else
static const u8 sRevengeDescription[] = _(
    "Attack that moves last\n"
    "and gains power if hit.");
#endif

#if GERMAN
static const u8 sPluckDescription[] = _(
    "Isst die Beere des Gegners\n"
    "und erhält ihren Effekt.");
#else
static const u8 sPluckDescription[] = _(
    "Eats the foe's held Berry\n"
    "gaining its effect.");
#endif

#if GERMAN
static const u8 sHealingWishDescription[] = _(
    "Der Nutzer wird k.o., heilt\n"
    "dafür den Nachfolger.");
#else
static const u8 sHealingWishDescription[] = _(
    "The user faints to heal up\n"
    "the recipient.");
#endif

#if GERMAN
static const u8 sWringOutDescription[] = _(
    "Je höher die KP des Zieles,\n"
    "desto stärker.");
#else
static const u8 sWringOutDescription[] = _(
    "The higher the foe's HP\n"
    "the more damage caused.");
#endif

#if GERMAN
static const u8 sUTurnDescription[] = _(
    "Der Anwender wird nach dem\n"
    "Angriff ausgewechselt.");
#else
static const u8 sUTurnDescription[] = _(
    "Does damage then switches\n"
    "out the user.");
#endif

#if GERMAN
static const u8 sStormThrowDescription[] = _(
    "Ein Angriff mit\n"
    "Volltreffergarantie.");
#else
static const u8 sStormThrowDescription[] = _(
    "This attack always results\n"
    "in a critical hit.");
#endif

#if GERMAN
static const u8 sCircleThrowDescription[] = _(
    "Wechselt das Ziel aus. Been-\n"
    "det Kämpfe in der Wildnis.");
#else
static const u8 sCircleThrowDescription[] = _(
    "Knocks foe away to switch\n"
    "it out or end wild battle.");
#endif

#if GERMAN
static const u8 sChipAwayDescription[] = _(
    "Schadet trotz\n"
    "Statusänderungen des Zieles.");
#else
static const u8 sChipAwayDescription[] = _(
    "Strikes through the foe's\n"
    "stat changes.");
#endif

#if GERMAN
static const u8 sHeavySlamDescription[] = _(
    "Je schwerer der Anwender als\n"
    "das Ziel, desto stärker.");
#else
static const u8 sHeavySlamDescription[] = _(
    "Does more damage if the\n"
    "user outweighs the foe.");
#endif

#if GERMAN
static const u8 sPsyshockDescription[] = _(
    "Eine Energiewelle, die\n"
    "physischen Schaden zufügt.");
#else
static const u8 sPsyshockDescription[] = _(
    "Attacks with a psychic wave\n"
    "that does physical damage.");
#endif

#if GERMAN
static const u8 sLavaPlumeDescription[] = _(
    "Tiefrote Flammen. Verbrennen\n"
    "die Ziele eventuell.");
#else
static const u8 sLavaPlumeDescription[] = _(
    "Scarlet flames torch\n"
    "everything around the user.");
#endif

#if GERMAN
static const u8 sShadowForceDescription[] = _(
    "Verschwindet in Runde 1.\n"
    "Trifft trotz Schutz.");
#else
static const u8 sShadowForceDescription[] = _(
    "Vanishes on the first turn\n"
    "then strikes the next turn.");
#endif

#if GERMAN
static const u8 sFalseSwipeDescription[] = _(
    "Ein Angriff, der dem Ziel\n"
    "zumindest 1 KP lässt.");
#else
static const u8 sFalseSwipeDescription[] = _(
    "Attack that leaves the\n"
    "foe with at least 1 HP.");
#endif

#if GERMAN
static const u8 sDrainingKissDescription[] = _(
    "Saugt über die Hälfte des\n"
    "Schadens als KP ab.");
#else
static const u8 sDrainingKissDescription[] = _(
    "Attack that absorbs over\n"
    "half the damage inflicted.");
#endif

#if GERMAN
static const u8 sCloseCombatDescription[] = _(
    "Ein Sturzflug. Senkt eigene\n"
    "Vert. und Sp.Vert.");
#else
static const u8 sCloseCombatDescription[] = _(
    "A strong attack but lowers\n"
    "the defensive stats.");
#endif

#if GERMAN
static const u8 sHyperspaceHoleDescription[] = _(
    "Trifft durch ein Dimensions-\n"
    "loch. Schutz wirkt nicht.");
#else
static const u8 sHyperspaceHoleDescription[] = _(
    "Uses a warp hole to attack.\n"
    "Can't be evaded.");
#endif

#if GERMAN
static const u8 sSuckerPunchDescription[] = _(
    "Erstschlag, gelingt nur gegen\n"
    "angreifende Ziele.");
#else
static const u8 sSuckerPunchDescription[] = _(
    "Strikes first if the foe\n"
    "is preparing an attack.");
#endif

#if GERMAN
static const u8 sFeintDescription[] = _(
    "Ein Lichtschnitt, der auch\n"
    "Schutz durchbricht.");
#else
static const u8 sFeintDescription[] = _(
    "Attack that hits foes\n"
    "using moves like Protect.");
#endif

#if GERMAN
static const u8 sProtectDescription[] = _(
    "Weicht Angriff aus. Schei-\n"
    "tert evtl. bei Wdh.");
#else
static const u8 sProtectDescription[] = _(
    "Evades attack, but may fail\n"
    "if used in succession.");
#endif

#if GERMAN
static const u8 sGMaxOneBlowDescription[] = _(
    "Urshifus G-Max-Angriff.\n"
    "Ignoriert Max-Schutz.");
#else
static const u8 sGMaxOneBlowDescription[] = _(
    "G-max Urshifu attack.\n"
    "Ignores Max Guard.");
#endif

const struct MoveInfo gMovesInfo[MOVES_COUNT_ALL] =
{
    [MOVE_NONE] =
    {
        .name = COMPOUND_STRING("-"),
        .description = COMPOUND_STRING(""),
        .effect = EFFECT_HIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 0,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .sketchBanned = TRUE,
        .assistBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_None,
    },

    [MOVE_POUND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pfund"),
#else
        .name = COMPOUND_STRING("POUND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Hieb mit den Vorder-\n"
            "beinen oder dem Schweif."),
#else
            "Pounds the foe with\n"
            "forelegs or tail."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS == GEN_4,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_POUND,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Pound,
    },

    [MOVE_KARATE_CHOP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Karateschlag"),
#else
        .name = COMPOUND_STRING("KARATE CHOP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gute Möglichkeit, einen\n"
            "Volltreffer zu landen."),
#else
            "A chopping attack with a\n"
            "high critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_FIGHTING : TYPE_NORMAL,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_KarateChop,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_SLAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Duplexhieb"),
#else
        .name = COMPOUND_STRING("DOUBLE SLAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft den Gegner 2 - 5-mal\n"
            "hintereinander."),
#else
            "Repeatedly slaps the foe\n"
            "2 to 5 times."),
#endif
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_POUND},
        .battleAnimScript = gBattleAnimMove_DoubleSlap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COMET_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kometenhieb"),
#else
        .name = COMPOUND_STRING("COMET PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft den Gegner 2 - 5-mal\n"
            "hintereinander."),
#else
            "Repeatedly punches the foe\n"
            "2 to 5 times."),
#endif
        .effect = EFFECT_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CometPunch,
    },

    [MOVE_MEGA_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Megahieb"),
#else
        .name = COMPOUND_STRING("MEGA PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein unglaublich kräftiger\n"
            "Hieb."),
#else
            "A strong punch thrown with\n"
            "incredible power."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_MegaPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PAY_DAY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zahltag"),
#else
        .name = COMPOUND_STRING("PAY DAY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirft Münzen auf Gegner.\n"
            "Geld wird erstattet."),
#else
            "Throws coins at the foe.\n"
            "Money is recovered after."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PAYDAY,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST : CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PayDay,
    },

    [MOVE_FIRE_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feuerschlag"),
#else
        .name = COMPOUND_STRING("FIRE PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlag, der dem Gegner evtl.\n"
            "Verbrennungen zufügt."),
#else
            "A fiery punch that may burn\n"
            "the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_FIRE_PUNCH,
        .contestComboMoves = {COMBO_STARTER_ICE_PUNCH, COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_THUNDER_PUNCH},
        .battleAnimScript = gBattleAnimMove_FirePunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICE_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eishieb"),
#else
        .name = COMPOUND_STRING("ICE PUNCH"),
#endif
        .description = COMPOUND_STRING(
        #if B_USE_FROSTBITE == TRUE
#if GERMAN
            "Ein eisiger Schlag. Er kann\n"
            "Frostbeulen verursachen."),
#else
            "leave the foe with frostbite."),
#endif
        #else
#if GERMAN
            "Ein Schlag, der den Gegner\n"
            "evtl. einfriert."),
#else
            "freeze the foe."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_ICE_PUNCH,
        .contestComboMoves = {COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_THUNDER_PUNCH},
        .battleAnimScript = gBattleAnimMove_IcePunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Donnerschlag"),
#else
        .name = COMPOUND_STRING("THUNDER PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlag, der den Gegner evtl.\n"
            "paralysiert."),
#else
            "An electrified punch that\n"
            "may paralyze the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_THUNDER_PUNCH,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_ICE_PUNCH},
        .battleAnimScript = gBattleAnimMove_ThunderPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SCRATCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kratzer"),
#else
        .name = COMPOUND_STRING("SCRATCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Gegner wird mit\n"
            "scharfen Klauen zerkratzt."),
#else
            "Scratches the foe with\n"
            "sharp claws."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCRATCH,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Scratch,
    },

    [MOVE_VISE_GRIP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Klammer"),
#else
        .name = COMPOUND_STRING("VISE GRIP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Umklammert den Gegner mit\n"
            "großen, kräftigen Zangen."),
#else
            "Grips the foe with large and\n"
            "powerful pincers."),
#endif
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_VICE_GRIP,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ViseGrip,
    },

    [MOVE_GUILLOTINE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Guillotine"),
#else
        .name = COMPOUND_STRING("GUILLOTINE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kräftige Scheren-Attacke.\n"
            "Führt evtl. zum K.O."),
#else
            "A powerful pincer attack\n"
            "that KOs if it hits."),
#endif
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_VICE_GRIP},
        .battleAnimScript = gBattleAnimMove_Guillotine,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAZOR_WIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Klingensturm"),
#else
        .name = COMPOUND_STRING("RAZOR WIND"),
#endif
        #if B_UPDATED_MOVE_DATA == GEN_3 || B_UPDATED_MOVE_DATA == GEN_1
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Attacke, die auf 2\n"
            "Runden basiert."),
#else
                "A 2-turn move that strikes\n"
                "the foe on the 2nd turn."),
#endif
        #else
            .description = COMPOUND_STRING(
#if GERMAN
                "Ein Angriff über 2 Runden,\n"
                "mit hoher Volltrefferrate."),
#else
                "A 2-turn move with a high\n"
                "critical-hit ratio."),
#endif
        #endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 100 : 75,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .criticalHitStage = 1,
        #elif B_UPDATED_MOVE_DATA == GEN_2
            .criticalHitStage = 2,
        #else
            .criticalHitStage = 0,
        #endif
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNWHIPPEDWHIRLWIND },
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RazorWind,
    },

    [MOVE_SWORDS_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schwerttanz"),
#else
        .name = COMPOUND_STRING("SWORDS DANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht den Angriffs-Wert\n"
            "drastisch."),
#else
            "A fighting dance that\n"
            "sharply raises Attack."),
#endif
        .effect = EFFECT_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SWORDS_DANCE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SwordsDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CUT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zerschneider"),
#else
        .name = COMPOUND_STRING("CUT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft den Gegner mit\n"
            "Klauen, Scheren o. ä."),
#else
            "Cuts the foe with sharp\n"
            "scythes, claws, etc."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_Cut,
    },

    [MOVE_GUST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Windstoß"),
#else
        .name = COMPOUND_STRING("GUST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft den Gegner mit Wind-\n"
            "stoß durch Flügelschlag."),
#else
            "Strikes the foe with a gust\n"
            "of wind whipped up by wings."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_FLYING : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_4) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .damagesAirborneDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .windMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Gust,
    },

    [MOVE_WING_ATTACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flügelschlag"),
#else
        .name = COMPOUND_STRING("WING ATTACK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft den Gegner mit weit\n"
            "gespreizten Flügeln."),
#else
            "Strikes the foe with wings\n"
            "spread wide."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 60 : 35,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WingAttack,
    },

    [MOVE_WHIRLWIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wirbelwind"),
#else
        .name = COMPOUND_STRING("WHIRLWIND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Weht Gegner weg und be-\n"
            "endet den Kampf in Wildnis."),
#else
            "Blows away the foe, switches\n"
            "it out or ends wild battle."),
#endif
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 0,
            .priority = -6,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .accuracy = 100,
            .priority = -6,
        #elif B_UPDATED_MOVE_DATA == GEN_2
            .accuracy = 100,
            .priority = -1,
        #else
            .accuracy = 85,
            .priority = 0,
        #endif
        .pp = 20,
        .target = TARGET_SELECTED,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .windMove = TRUE,
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STEALTH_ROCK, COMBO_STARTER_SPIKES, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_Whirlwind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fliegen"),
#else
        .name = COMPOUND_STRING("FLY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Steigt empor in der 1. Runde\n"
            "und trifft Gegner in der 2."),
#else
            "Flies up on the first turn,\n"
            "then strikes the next turn."),
#endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 90 : 70,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNFLEWHIGH, .status = STATE_ON_AIR },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Fly,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Klammergriff"),
#else
        .name = COMPOUND_STRING("BIND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Umschlingt den Gegner für\n"
            ""BINDING_TURNS" Runden lang."),
#else
            "Binds and squeezes the foe\n"
            "for "BINDING_TURNS" turns."),
#endif
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 75,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_BIND,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_VICE_GRIP},
        .battleAnimScript = gBattleAnimMove_Bind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Slam"),
#else
        .name = COMPOUND_STRING("SLAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlag mit einem langen\n"
            "Schweif, einer Ranke o. ä."),
#else
            "Slams the foe with a long\n"
            "tail, vine, etc."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_POUND},
        .battleAnimScript = gBattleAnimMove_Slam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_VINE_WHIP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rankenhieb"),
#else
        .name = COMPOUND_STRING("VINE WHIP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Peitschenartiger Schlag\n"
            "mit Ranken."),
#else
            "Strikes the foe with\n"
            "slender, whiplike vines."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 25,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 15,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 45 : 35,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_VineWhip,
    },

    [MOVE_STOMP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stampfer"),
#else
        .name = COMPOUND_STRING("STOMP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stampfen mit Fuß. Gegner\n"
            "schreckt evtl. zurück."),
#else
            "Stomps the enemy with a big\n"
            "foot. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Stomp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Doppelkick"),
#else
        .name = COMPOUND_STRING("DOUBLE KICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppeltritt. Der Gegner\n"
            "wird zweimal getroffen."),
#else
            "A double-kicking attack\n"
            "that strikes the foe twice."),
#endif
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEGA_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Megakick"),
#else
        .name = COMPOUND_STRING("MEGA KICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein extrem\n"
            "heftiger Tritt."),
#else
            "An extremely powerful kick\n"
            "with intense force."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_MegaKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_JUMP_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sprungkick"),
#else
        .name = COMPOUND_STRING("JUMP KICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sprung-Tritt. Selbstschä-\n"
            "digung bei Misserfolg."),
#else
            "A strong jumping kick. May\n"
            "miss and hurt the kicker."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 85,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_JumpKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROLLING_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fegekick"),
#else
        .name = COMPOUND_STRING("ROLLING KICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schneller Tritt aus der\n"
            "Drehung."),
#else
            "A fast kick delivered from\n"
            "a rapid spin. May flinch."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 85,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RollingKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SAND_ATTACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sandwirbel"),
#else
        .name = COMPOUND_STRING("SAND ATTACK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt Genauigkeit des Geg-\n"
            "ners durch Sand."),
#else
            "Reduces the foe's accuracy\n"
            "by hurling sand in its face."),
#endif
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_GROUND : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SAND_ATTACK,
        .contestComboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_SandAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HEADBUTT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kopfnuss"),
#else
        .name = COMPOUND_STRING("HEADBUTT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Rammt den Gegner und lässt\n"
            "ihn evtl. zurückschrecken."),
#else
            "A ramming attack that may\n"
            "cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_Headbutt,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HORN_ATTACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hornattacke"),
#else
        .name = COMPOUND_STRING("HORN ATTACK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Spießt den Gegner mit\n"
            "spitzen Hörnern auf."),
#else
            "Jabs the foe with sharp\n"
            "horns."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_HORN_ATTACK,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_HornAttack,
    },

    [MOVE_FURY_ATTACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Furienschlag"),
#else
        .name = COMPOUND_STRING("FURY ATTACK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Spießt den Gegner 2 - 5-mal\n"
            "mit spitzen Hörnern auf."),
#else
            "Jabs the foe 2 to 5 times\n"
            "with sharp horns, etc."),
#endif
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HORN_ATTACK, COMBO_STARTER_PECK},
        .battleAnimScript = gBattleAnimMove_FuryAttack,
    },

    [MOVE_HORN_DRILL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hornbohrer"),
#else
        .name = COMPOUND_STRING("HORN DRILL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "K.O.-Attacke, die ein Horn\n"
            "als Bohrer einsetzt."),
#else
            "A one-hit KO attack that\n"
            "uses a horn like a drill."),
#endif
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HORN_ATTACK},
        .battleAnimScript = gBattleAnimMove_HornDrill,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TACKLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tackle"),
#else
        .name = COMPOUND_STRING("TACKLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft den Gegner mit vollem\n"
            "Körpereinsatz."),
#else
            "Charges the foe with a full-\n"
            "body tackle."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 40,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .power = 50,
        #else
            .power = 35,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 95,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN, COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Tackle,
    },

    [MOVE_BODY_SLAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bodyslam"),
#else
        .name = COMPOUND_STRING("BODY SLAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Körper-Ramme, kann\n"
            "Paralyse hervorrufen."),
#else
            "A full-body slam that may\n"
            "cause paralysis."),
#endif
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BodySlam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WRAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wickel"),
#else
        .name = COMPOUND_STRING("WRAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Umschlingt den Gegner\n"
            BINDING_TURNS"-mal mit Ranken."),
#else
            "Wraps and squeezes the foe\n"
            BINDING_TURNS" times with vines, etc."),
#endif
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Wrap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAKE_DOWN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bodycheck"),
#else
        .name = COMPOUND_STRING("TAKE DOWN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Rücksichtslose Attacke,\n"
            "mit Selbstschädigung."),
#else
            "A reckless charge attack\n"
            "that also hurts the user."),
#endif
        .effect = EFFECT_RECOIL,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_TakeDown,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THRASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fuchtler"),
#else
        .name = COMPOUND_STRING("THRASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Attacke über 2 bis 3 Runden,\n"
            "die Anwender verwirrt."),
#else
            "A rampage of 2 to 3 turns\n"
            "that confuses the user."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 120 : 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAGE},
        .battleAnimScript = gBattleAnimMove_Thrash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_EDGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Risikotackle"),
#else
        .name = COMPOUND_STRING("DOUBLE-EDGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lebensgefährlicher Angriff\n"
            "mit Selbstschädigung."),
#else
            "A life-risking tackle that\n"
            "also hurts the user."),
#endif
        .effect = EFFECT_RECOIL,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 120 : 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = B_UPDATED_MOVE_DATA >= GEN_3 ? 33 : 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_DoubleEdge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAIL_WHIP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rutenschlag"),
#else
        .name = COMPOUND_STRING("TAIL WHIP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hieb mit dem Schweif, senkt\n"
            "die VERT. des Gegners."),
#else
            "Wags the tail to lower the\n"
            "foe's Defense."),
#endif
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_TailWhip,
    },

    [MOVE_POISON_STING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftstachel"),
#else
        .name = COMPOUND_STRING("POISON STING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit Widerhaken,\n"
            "kann Gegner vergiften."),
#else
            "A toxic attack with barbs,\n"
            "etc., that may poison."),
#endif
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 20,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonSting,
    },

    [MOVE_TWINEEDLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Duonadel"),
#else
        .name = COMPOUND_STRING("TWINEEDLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stacheln an den Vorderbei-\n"
            "nen treffen Gegner 2-mal."),
#else
            "Foreleg stingers jab foe\n"
            "twice. May poison."),
#endif
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .strikeCount = 2,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Twineedle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PIN_MISSILE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nadelrakete"),
#else
        .name = COMPOUND_STRING("PIN MISSILE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Spitze Nadeln treffen den\n"
            "Gegner 2 - 5-mal."),
#else
            "Sharp pins are fired to\n"
            "strike 2 to 5 times."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 14,
        .type = TYPE_BUG,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PinMissile,
    },

    [MOVE_LEER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Silberblick"),
#else
        .name = COMPOUND_STRING("LEER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gegners VERT.-Wert wird\n"
            "durch Blick gesenkt."),
#else
            "Frightens the foes with a\n"
            "leer to lower Defense."),
#endif
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_LEER,
        .contestComboMoves = {COMBO_STARTER_RAGE, COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_Leer,
    },

    [MOVE_BITE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Biss"),
#else
        .name = COMPOUND_STRING("BITE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Beißt zu und lässt den Geg-\n"
            "ner evtl. zurückschrecken."),
#else
            "Bites with vicious fangs.\n"
            "May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = B_UPDATED_MOVE_TYPES >= GEN_2 ? TYPE_DARK : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_Bite,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GROWL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Heuler"),
#else
        .name = COMPOUND_STRING("GROWL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Knurren, das den ANGR.-Wert\n"
            "des Gegners senkt."),
#else
            "Growls cutely to reduce the\n"
            "foe's Attack."),
#endif
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_Growl,
    },

    [MOVE_ROAR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Brüller"),
#else
        .name = COMPOUND_STRING("ROAR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verjagt den Gegner und be-\n"
            "endet den Kampf in Wildnis."),
#else
            "Switches the foe out\n"
            "or ends wild battle."),
#endif
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        #if B_UPDATED_MOVE_DATA >= GEN_3
            .priority = -6,
        #elif B_UPDATED_MOVE_DATA == GEN_2
            .priority = -1,
        #else
            .priority = 0,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .soundMove = TRUE,
        .copycatBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STEALTH_ROCK, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE, COMBO_STARTER_SPIKES, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_Roar,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gesang"),
#else
        .name = COMPOUND_STRING("SING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Lied, das den Gegner\n"
            "in tiefen Schlaf versetzt."),
#else
            "A soothing song lulls the\n"
            "foe into a deep slumber."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SING,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sing,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUPERSONIC] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Superschall"),
#else
        .name = COMPOUND_STRING("SUPERSONIC"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ausstoß bizarrer Schallwel-\n"
            "len. Verwirrt Gegner evtl."),
#else
            "Emits bizarre sound waves\n"
            "that may confuse the foe."),
#endif
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Supersonic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SONIC_BOOM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ultraschall"),
#else
        .name = COMPOUND_STRING("SONIC BOOM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schockwellen. Richten immer\n"
            "20 KP Schaden an."),
#else
            "Launches shock waves that\n"
            "always inflict 20 HP damage."),
#endif
        .effect = EFFECT_FIXED_HP_DAMAGE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .fixedDamage = 20 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SonicBoom,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DISABLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aussetzer"),
#else
        .name = COMPOUND_STRING("DISABLE"),
#endif
#if GERMAN
        .description = COMPOUND_STRING(
        #if B_DISABLE_TURNS >= GEN_5
            "Blockiert die letzte Attacke\n"
            "des Gegners für 4 Runden."),
        #elif B_DISABLE_TURNS == GEN_4
            "Blockiert die letzte Attacke\n"
            "des Gegners für 4-7 Runden."),
        #else
            "Psycho-Attacke. Blockiert\n"
            "eine Attacke des Gegners."),
        #endif
#else
        .description = COMPOUND_STRING(
        #if B_DISABLE_TURNS >= GEN_5
            "For 4 turns, prevents foe\n"
        #elif B_DISABLE_TURNS == GEN_4
            "For 4-7 turns, prevents foe\n"
        #else
            "For 2-5 turns, prevents foe\n"
        #endif
            "from using last used move."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 80,
        #else
            .accuracy = 55,
        #endif
        .effect = EFFECT_DISABLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Disable,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ACID] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Säure"),
#else
        .name = COMPOUND_STRING("ACID"),
#endif
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_4
#if GERMAN
            "Versprüht ätzende Flüssig-\n"
            "keit, senkt evtl. SPEZ. VERT."),
#else
            "May lower Sp. Def."),
#endif
        #else
#if GERMAN
            "Versprüht ätzende Flüssig-\n"
            "keit, senkt evtl. VERT."),
#else
            "May lower Defense."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
            .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = B_UPDATED_MOVE_DATA >= GEN_4 ? MOVE_EFFECT_SP_DEF_MINUS_1 : MOVE_EFFECT_DEF_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Acid,
    },

    [MOVE_EMBER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Glut"),
#else
        .name = COMPOUND_STRING("EMBER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwache Feuer-Attacke.\n"
            "Verbrennt Gegner evtl."),
#else
            "A weak fire attack that may\n"
            "inflict a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Ember,
    },

    [MOVE_FLAMETHROWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flammenwurf"),
#else
        .name = COMPOUND_STRING("FLAMETHROWER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Starke Feuer-Attacke.\n"
            "Verbrennt Gegner evtl."),
#else
            "A powerful fire attack that\n"
            "may inflict a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Flamethrower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Weißnebel"),
#else
        .name = COMPOUND_STRING("MIST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Nebel, der die Änderung der\n"
            "Werte verhindert."),
#else
            "Creates a mist that stops\n"
            "reduction of stats."),
#endif
        .effect = EFFECT_MIST,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Mist,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_GUN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aquaknarre"),
#else
        .name = COMPOUND_STRING("WATER GUN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Gegner wird mit Wasser\n"
            "bespritzt."),
#else
            "Squirts water to attack\n"
            "the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_WATER_SPORT},
        .battleAnimScript = gBattleAnimMove_WaterGun,
    },

    [MOVE_HYDRO_PUMP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hydropumpe"),
#else
        .name = COMPOUND_STRING("HYDRO PUMP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Spritzt Wasser mit\n"
            "Hochdruck auf den Gegner."),
#else
            "Blasts water at high power\n"
            "to strike the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_WATER,
        .accuracy = 80,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_HydroPump,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SURF] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Surfer"),
#else
        .name = COMPOUND_STRING("SURF"),
#endif
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_4
#if GERMAN
            "Eine riesige Welle bricht\n"
            "über das Kampffeld herein."),
#else
            "crashes it down on the field."),
#endif
        #else
#if GERMAN
            "Eine riesige Welle bricht\n"
            "über den Gegner herein."),
#else
            "crashes it down on the foes."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = B_UPDATED_MOVE_DATA >= GEN_4 ? TARGET_FOES_AND_ALLY : TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .damagesUnderwater = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SURF,
        .contestComboMoves = {COMBO_STARTER_DIVE, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Surf,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICE_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eisstrahl"),
#else
        .name = COMPOUND_STRING("ICE BEAM"),
#endif
        .description = COMPOUND_STRING(
        #if B_USE_FROSTBITE == TRUE
#if GERMAN
            "Ein eisiger Strahl. Er kann\n"
            "Frostbeulen verursachen."),
#else
            "beam. May cause frostbite."),
#endif
        #else
#if GERMAN
            "Gegner wird von Eisstrahl\n"
            "getroffen, friert evtl. ein."),
#else
            "beam that may freeze it."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            // The following effect is also relevant in battle_Pike.c
            // If you cherry-pick this to use something other than the config, make sure to update it there too
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IceBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLIZZARD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blizzard"),
#else
        .name = COMPOUND_STRING("BLIZZARD"),
#endif
        .description = COMPOUND_STRING(
        #if B_USE_FROSTBITE == TRUE
#if GERMAN
            "Ein eisiger Sturm. Er kann\n"
            "Frostbeulen verursachen."),
#else
            "storm. May cause frostbite."),
#endif
        #else
#if GERMAN
            "Ein Schneesturm, der den\n"
            "Gegner einfrieren kann."),
#else
            "storm that may freeze it."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_ICE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_2 ? 70 : 90,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInHailSnow = B_BLIZZARD_HAIL >= GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_POWDER_SNOW},
        .battleAnimScript = gBattleAnimMove_Blizzard,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYBEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psystrahl"),
#else
        .name = COMPOUND_STRING("PSYBEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Feuert einen Strahl ab, der\n"
            "Gegner verwirren kann."),
#else
            "Fires a peculiar ray that\n"
            "may confuse the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Psybeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BUBBLE_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blubbstrahl"),
#else
        .name = COMPOUND_STRING("BUBBLE BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Versprüht Blasen, die den\n"
            "INIT.-Wert evtl. senken."),
#else
            "Forcefully sprays bubbles\n"
            "that may lower Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_BubbleBeam,
    },

    [MOVE_AURORA_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aurorastrahl"),
#else
        .name = COMPOUND_STRING("AURORA BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Regenbogenfarbener Strahl,\n"
            "senkt evtl. ANGR.-Wert."),
#else
            "Fires a rainbow-colored\n"
            "beam that may lower Attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_AuroraBeam,
    },

    [MOVE_HYPER_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hyperstrahl"),
#else
        .name = COMPOUND_STRING("HYPER BEAM"),
#endif
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HyperBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PECK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schnabel"),
#else
        .name = COMPOUND_STRING("PECK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift Gegner mit dem\n"
            "Schnabel an."),
#else
            "Attacks the foe with a\n"
            "jabbing beak, etc."),
#endif
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_PECK,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Peck,
    },

    [MOVE_DRILL_PECK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bohrschnabel"),
#else
        .name = COMPOUND_STRING("DRILL PECK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Attacke, bei der der Schna-\n"
            "bel als Bohrer dient."),
#else
            "A corkscrewing attack with\n"
            "the beak acting as a drill."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PECK},
        .battleAnimScript = gBattleAnimMove_DrillPeck,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUBMISSION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Überroller"),
#else
        .name = COMPOUND_STRING("SUBMISSION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Rücksichtsloser Rempler. \n"
            "Schädigt auch Angreifer."),
#else
            "A reckless body slam that\n"
            "also hurts the user."),
#endif
        .effect = EFFECT_RECOIL,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .argument = { .recoilPercentage = 25 },
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_Submission,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LOW_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fußkick"),
#else
        .name = COMPOUND_STRING("LOW KICK"),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_3
        .description = COMPOUND_STRING(
#if GERMAN
            "Tritt, der massigen Gegnern\n"
            "mehr Schaden zufügt."),
#else
                "A kick that inflicts more\n"
                "damage on heavier foes."),
#endif
            .effect = EFFECT_LOW_KICK,
        #else
            .description = COMPOUND_STRING(
#if GERMAN
                "Ein niedriger Fußtritt,\n"
                "der zurückschrecken lässt."),
#else
                "A low, tripping kick that\n"
                "may cause flinching."),
#endif
            .effect = EFFECT_HIT,
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_FLINCH,
                .chance = 30,
            }),
        #endif
        .power = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 50,
        .type = TYPE_FIGHTING,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 100 : 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_LATER : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LowKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COUNTER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Konter"),
#else
        .name = COMPOUND_STRING("COUNTER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kontert physischen Tref-\n"
            "fer mit doppelter Kraft."),
#else
            "Retaliates any physical hit\n"
            "with double the power."),
#endif
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = -5,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .argument = {
            .reflectDamage.damagePercent = 200,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_PHYSICAL,
        },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_5,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT, COMBO_STARTER_ENCORE, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_Counter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SEISMIC_TOSS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Geowurf"),
#else
        .name = COMPOUND_STRING("SEISMIC TOSS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Richtet Schaden gemäß\n"
            "Level d. Angreifers an."),
#else
            "Inflicts damage identical\n"
            "to the user's level."),
#endif
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_SeismicToss,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STRENGTH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stärke"),
#else
        .name = COMPOUND_STRING("STRENGTH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt enorme Kraft und\n"
            "rammt den Gegner."),
#else
            "Builds enormous power,\n"
            "then slams the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Strength,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ABSORB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Absorber"),
#else
        .name = COMPOUND_STRING("ABSORB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Attacke, die die Hälfte des\n"
            "Schadens absorbiert."),
#else
            "Attack that absorbs\n"
            "half the damage inflicted."),
#endif
        .effect = EFFECT_ABSORB,
        .power = 20,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_4 ? 25 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_Absorb,
    },

    [MOVE_MEGA_DRAIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Megasauger"),
#else
        .name = COMPOUND_STRING("MEGA DRAIN"),
#endif
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .zMove = { .powerOverride = 120 },
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_MegaDrain,
    },

    [MOVE_LEECH_SEED] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Egelsamen"),
#else
        .name = COMPOUND_STRING("LEECH SEED"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gegner wird bepflanzt und\n"
            "verliert jede Runde KP."),
#else
            "Plants a seed on the foe to\n"
            "steal HP on every turn."),
#endif
        .effect = EFFECT_LEECH_SEED,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_LEECH_SEED,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_WORRY_SEED, COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_LeechSeed,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GROWTH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wachstum"),
#else
        .name = COMPOUND_STRING("GROWTH"),
#endif
        .description = COMPOUND_STRING(
        #if B_GROWTH_STAT_RAISE >= GEN_5
#if GERMAN
            "Der Körper wächst. ANGR. u.\n"
            "SPEZ. ANGR. werden erhöht."),
#else
            "Forces the body to grow,\n"
            "raising Attack and Sp. Atk."),
#endif
        #else
#if GERMAN
            "Der Körper wächst und\n"
            "SPEZ. ANGR. wird erhöht."),
#else
            "Forces the body to grow\n"
            "and heightens Sp. Atk."),
#endif
        #endif
        .effect = B_GROWTH_STAT_RAISE >= GEN_5 ? EFFECT_GROWTH : EFFECT_SPECIAL_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_GROWTH,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Growth,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAZOR_LEAF] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rasierblatt"),
#else
        .name = COMPOUND_STRING("RAZOR LEAF"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft Gegner mit Blättern.\n"
            "Hohe Volltrefferquote."),
#else
            "Cuts enemies with leaves.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_RazorLeaf,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SOLAR_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Solarstrahl"),
#else
        .name = COMPOUND_STRING("SOLAR BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Absorbiert Licht in der 1.\n"
            "Runde, 2. Runde Angriff."),
#else
            "Absorbs light in one turn,\n"
            "then attacks next turn."),
#endif
        .effect = EFFECT_SOLAR_BEAM,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNTOOKSUNLIGHT, .weather = B_WEATHER_SUN },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_SolarBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POISON_POWDER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftpuder"),
#else
        .name = COMPOUND_STRING("POISON POWDER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verstreut giftigen Puder,\n"
            "der Gegner vergiften kann."),
#else
            "Scatters a toxic powder\n"
            "that may poison the foe."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 75,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_POISON },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_POISON_POWDER,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
        .battleAnimScript = gBattleAnimMove_PoisonPowder,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STUN_SPORE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stachelspore"),
#else
        .name = COMPOUND_STRING("STUN SPORE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verstreut Puder, der den\n"
            "Gegner evtl. paralysiert."),
#else
            "Scatters a powder that may\n"
            "paralyze the foe."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_PARALYSIS },
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
        .battleAnimScript = gBattleAnimMove_StunSpore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLEEP_POWDER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schlafpuder"),
#else
        .name = COMPOUND_STRING("SLEEP POWDER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verstreut Puder, der Geg.\n"
            "evtl. in Schlaf versetzt."),
#else
            "Scatters a powder that may\n"
            "cause the foe to sleep."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_SLEEP_POWDER,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
        .battleAnimScript = gBattleAnimMove_SleepPowder,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PETAL_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blättertanz"),
#else
        .name = COMPOUND_STRING("PETAL DANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff über 2-3 Runden.\n"
            "Angreifer wird verwirrt."),
#else
            "A rampage of 2 to 3 turns\n"
            "that confuses the user."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 90,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .danceMove = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_PetalDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STRING_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fadenschuss"),
#else
        .name = COMPOUND_STRING("STRING SHOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Umwickelt Gegner mit Faden\n"
            "und senkt INIT.-Wert."),
#else
            "Binds the foe with string\n"
            "to reduce its Speed."),
#endif
        .effect = B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_SPEED_DOWN_2 : EFFECT_SPEED_DOWN,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 40,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_STRING_SHOT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StringShot,
    },

    [MOVE_DRAGON_RAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drachenwut"),
#else
        .name = COMPOUND_STRING("DRAGON RAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stößt Schockwellen aus, die\n"
            "40 KP Schaden anrichten."),
#else
            "Launches shock waves that\n"
            "always inflict 40 HP damage."),
#endif
        .effect = EFFECT_FIXED_HP_DAMAGE,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_4) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .argument = { .fixedDamage = 40 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_RAGE,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonRage,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FIRE_SPIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feuerwirbel"),
#else
        .name = COMPOUND_STRING("FIRE SPIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fängt den Gegner im Feuer-\n"
            "ring, "BINDING_TURNS" Runden."),
#else
            "Traps the foe in a ring of\n"
            "fire for "BINDING_TURNS" turns."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_FIRE_SPIN,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FireSpin,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER_SHOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Donnerschock"),
#else
        .name = COMPOUND_STRING("THUNDER SHOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Elektro-Attacke. Gegner\n"
            "evtl. paralysiert."),
#else
            "An electrical attack that\n"
            "may paralyze the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ThunderShock,
    },

    [MOVE_THUNDERBOLT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Donnerblitz"),
#else
        .name = COMPOUND_STRING("THUNDERBOLT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Starke Elektro-Attacke,\n"
            "Gegner evtl. paralysiert."),
#else
            "A strong electrical attack\n"
            "that may paralyze the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Thunderbolt,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER_WAVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Donnerwelle"),
#else
        .name = COMPOUND_STRING("THUNDER WAVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein schwacher Stromstoß,\n"
            "der den Gegner paralysiert."),
#else
            "A weak jolt of electricity\n"
            "that paralyzes the foe."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 90 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_PARALYSIS },
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_THUNDER_WAVE,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ThunderWave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THUNDER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Donner"),
#else
        .name = COMPOUND_STRING("THUNDER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Elektro-Attacke, die den\n"
            "Gegner evtl. paralysiert."),
#else
            "A lightning attack that may\n"
            "cause paralysis."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 70,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .damagesAirborne = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .alwaysHitsInRain = TRUE,
        .accuracy50InSun = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_LOCK_ON, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Thunder,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_THROW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Steinwurf"),
#else
        .name = COMPOUND_STRING("ROCK THROW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirft kleine Steine auf den\n"
            "Gegner."),
#else
            "Throws small rocks to\n"
            "strike the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_2 ? 90 : 65,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ROCK_THROW,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockThrow,
    },

    [MOVE_EARTHQUAKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Erdbeben"),
#else
        .name = COMPOUND_STRING("EARTHQUAKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Mächtiges Beben. Ist bei\n"
            "fliegenden Feinden nutzlos."),
#else
            "A powerful quake that\n"
            "hits all other POKéMON."),
#endif
        .effect = EFFECT_EARTHQUAKE,
        .power = 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .damagesUnderground = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_EARTHQUAKE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Earthquake,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FISSURE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Geofissur"),
#else
        .name = COMPOUND_STRING("FISSURE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sofort-K.O. Wirft Gegner\n"
            "in Gebirgsspalte."),
#else
            "A one-hit KO move that\n"
            "drops the foe in a fissure."),
#endif
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesUnderground = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_EARTHQUAKE},
        .battleAnimScript = gBattleAnimMove_Fissure,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DIG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schaufler"),
#else
        .name = COMPOUND_STRING("DIG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gräbt sich in der 1. Runde\n"
            "ein und trifft in der 2."),
#else
            "Digs underground the first\n"
            "turn and strikes next turn."),
#endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 80,
        #elif B_UPDATED_MOVE_DATA >= GEN_2
            .power = 60,
        #else
            .power = 100,
        #endif
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .skyBattleBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNDUGHOLE, .status = STATE_UNDERGROUND },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Dig,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TOXIC] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Toxin"),
#else
        .name = COMPOUND_STRING("TOXIC"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Vergiftet den Gegner mit \n"
            "einem starken Toxin."),
#else
            "Poisons the foe with an\n"
            "intensifying toxin."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_TOXIC },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .alwaysHitsOnSameType = B_TOXIC_NEVER_MISS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TOXIC,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Toxic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONFUSION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Konfusion"),
#else
        .name = COMPOUND_STRING("CONFUSION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Psycho-Attacke, die den\n"
            "Gegner evtl. verwirrt."),
#else
            "A psychic attack that may\n"
            "cause confusion."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CONFUSION,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_Confusion,
    },

    [MOVE_PSYCHIC] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psychokinese"),
#else
        .name = COMPOUND_STRING("PSYCHIC"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Starke Psycho-Attacke, die\n"
            "evtl. SPEZ. VERT. senkt."),
#else
            "A powerful psychic attack\n"
            "that may lower Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PSYCHIC,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_CONFUSION, COMBO_STARTER_KINESIS},
        .battleAnimScript = gBattleAnimMove_Psychic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYPNOSIS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hypnose"),
#else
        .name = COMPOUND_STRING("HYPNOSIS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hypno-Attacke, die Gegner\n"
            "evtl. in Schlaf versetzt."),
#else
            "A hypnotizing move that\n"
            "may induce sleep."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 60,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HYPNOSIS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Hypnosis,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEDITATE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Meditation"),
#else
        .name = COMPOUND_STRING("MEDITATE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Friedliche Meditation, um\n"
            "ANGR.-Wert zu steigern."),
#else
            "Meditates in a peaceful\n"
            "fashion to raise Attack."),
#endif
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Meditate,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AGILITY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Agilität"),
#else
        .name = COMPOUND_STRING("AGILITY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Entspannt den Körper, um\n"
            "INIT.-Wert. zu steigern."),
#else
            "Relaxes the body to sharply\n"
            "boost Speed."),
#endif
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_AGILITY,
        .contestComboMoves = {COMBO_STARTER_DOUBLE_TEAM},
        .battleAnimScript = gBattleAnimMove_Agility,
        .validApprenticeMove = TRUE,
    },

    [MOVE_QUICK_ATTACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ruckzuckhieb"),
#else
        .name = COMPOUND_STRING("QUICK ATTACK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr schneller Angriff mit\n"
            "Erstschlaggarantie."),
#else
            "An extremely fast attack\n"
            "that always strikes first."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DOUBLE_TEAM},
        .battleAnimScript = gBattleAnimMove_QuickAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Raserei"),
#else
        .name = COMPOUND_STRING("RAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht ANGR. des Anwenders\n"
            "bei jedem gegn. Treffer."),
#else
            "Raises the user's Attack\n"
            "every time it is hit."),
#endif
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAGE,
        }),
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_RAGE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Rage,
    },

    [MOVE_TELEPORT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Teleport"),
#else
        .name = COMPOUND_STRING("TELEPORT"),
#endif
        #if B_TELEPORT_BEHAVIOR >= GEN_8
        .description = COMPOUND_STRING(
#if GERMAN
            "Tauscht den Nutzer zuletzt\n"
            "aus. Wilde {PKMN} fliehen."),
#else
            "Switches the user out last.\n"
            "Flees when used by wild {PKMN}."),
#endif
        #else
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Psychoangriff zur\n"
            "sofortigen Flucht."),
#else
            "A psychic move for fleeing\n"
            "from battle instantly."),
#endif
        #endif
        .effect = EFFECT_TELEPORT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_8 ? -6 : 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CONFUSION, COMBO_STARTER_DOUBLE_TEAM, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_Teleport,
    },

    [MOVE_NIGHT_SHADE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nachtnebel"),
#else
        .name = COMPOUND_STRING("NIGHT SHADE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Richtet Schaden gemäß\n"
            "Level d. Angreifers an."),
#else
            "Inflicts damage identical\n"
            "to the user's level."),
#endif
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NightShade,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIMIC] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mimikry"),
#else
        .name = COMPOUND_STRING("MIMIC"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kopiert eine zuvor ausge-\n"
            "führte Attacke d. Gegners."),
#else
            "Copies last move used by the\n"
            "foe during one battle."),
#endif
        .effect = EFFECT_MIMIC,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 0 : 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresSubstitute = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Mimic,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SCREECH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kreideschrei"),
#else
        .name = COMPOUND_STRING("SCREECH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stößt einen Schrei aus, um\n"
            "gegn. VERT. zu senken."),
#else
            "Emits a screech to sharply\n"
            "reduce the foe's Defense."),
#endif
        .effect = EFFECT_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Screech,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOUBLE_TEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Doppelteam"),
#else
        .name = COMPOUND_STRING("DOUBLE TEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt Ebenbilder, um \n"
            "Fluchtwert zu erhöhen."),
#else
            "Creates illusory copies to\n"
            "raise evasiveness."),
#endif
        .effect = EFFECT_EVASION_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DOUBLE_TEAM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleTeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RECOVER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Genesung"),
#else
        .name = COMPOUND_STRING("RECOVER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Max. KP des Anwenders w.\n"
            "bis zur Hälfte aufgefüllt."),
#else
            "Recovers up to half the\n"
            "user's maximum HP."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 10,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Recover,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HARDEN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Härtner"),
#else
        .name = COMPOUND_STRING("HARDEN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt die Muskulatur und\n"
            "erhöht VERT.-Wert."),
#else
            "Stiffens the body's \n"
            "muscles to raise Defense."),
#endif
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_HARDEN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Harden,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MINIMIZE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Komprimator"),
#else
        .name = COMPOUND_STRING("MINIMIZE"),
#endif
        .description = COMPOUND_STRING(
        #if B_MINIMIZE_EVASION >= GEN_5
#if GERMAN
            "Anwender schrumpft. Flucht-\n"
            "wert steigt deutlich."),
#else
            "sharply raise evasiveness."),
#endif
        #else
#if GERMAN
            "Anwender schrumpft, um\n"
            "Fluchtwert zu erhöhen."),
#else
            "raise evasiveness."),
#endif
        #endif
        .effect = EFFECT_MINIMIZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Minimize,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SMOKESCREEN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rauchwolke"),
#else
        .name = COMPOUND_STRING("SMOKESCREEN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt Genauigkeit d. Geg-\n"
            "ners mit Rauch, Tinte o. ä."),
#else
            "Lowers the foe's accuracy\n"
            "using smoke, ink, etc."),
#endif
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SMOG},
        .battleAnimScript = gBattleAnimMove_Smokescreen,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONFUSE_RAY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Konfustrahl"),
#else
        .name = COMPOUND_STRING("CONFUSE RAY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein fieser Strahl, der den\n"
            "Gegner verwirrt."),
#else
            "A sinister ray that\n"
            "confuses the foe."),
#endif
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ConfuseRay,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WITHDRAW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Panzerschutz"),
#else
        .name = COMPOUND_STRING("WITHDRAW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Rückzug in den harten\n"
            "Panzer. Erhöht VERT.-Wert."),
#else
            "Withdraws the body into its\n"
            "hard shell to raise Defense."),
#endif
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Withdraw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DEFENSE_CURL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Einigler"),
#else
        .name = COMPOUND_STRING("DEFENSE CURL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verbirgt Schwächen per Ein-\n"
            "rollen, VERT.-Wert steigt."),
#else
            "Curls up to conceal weak\n"
            "spots and raise Defense."),
#endif
        .effect = EFFECT_DEFENSE_CURL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_DEFENSE_CURL,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DefenseCurl,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BARRIER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Barriere"),
#else
        .name = COMPOUND_STRING("BARRIER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt Barriere, die den\n"
            "VERT.-Wert stark erhöht."),
#else
            "Creates a barrier that\n"
            "sharply raises Defense."),
#endif
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Barrier,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LIGHT_SCREEN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lichtschild"),
#else
        .name = COMPOUND_STRING("LIGHT SCREEN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt Lichtwand u. senkt\n"
            "SPEZ. ANGR.-Schaden."),
#else
            "Wall of light cuts special\n"
            "damage for 5 turns."),
#endif
        .effect = EFFECT_LIGHT_SCREEN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_LightScreen,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HAZE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dunkelnebel"),
#else
        .name = COMPOUND_STRING("HAZE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt dunklen Dunst.\n"
            "Löscht alle Statusänder."),
#else
            "Creates a black haze that\n"
            "eliminates all stat changes."),
#endif
        .effect = EFFECT_HAZE,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_Haze,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REFLECT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Reflektor"),
#else
        .name = COMPOUND_STRING("REFLECT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt Lichtwand, schützt\n"
            "teilweise vor phys. Angr."),
#else
            "Wall of light cuts physical\n"
            "damage for 5 turns."),
#endif
        .effect = EFFECT_REFLECT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Reflect,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FOCUS_ENERGY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Energiefokus"),
#else
        .name = COMPOUND_STRING("FOCUS ENERGY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bündelt Kraft. Volltreffer-\n"
            "chance wird erhöht."),
#else
            "Focuses power to raise the\n"
            "critical-hit ratio."),
#endif
        .effect = EFFECT_FOCUS_ENERGY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .argument = { .status = VOLATILE_FOCUS_ENERGY },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_FOCUS_ENERGY,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FocusEnergy,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BIDE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Geduld"),
#else
        .name = COMPOUND_STRING("BIDE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erträgt 2 Runden Angriffe,\n"
            "schlägt doppelt zurück."),
#else
            "Endures attack for 2\n"
            "turns to retaliate double."),
#endif
        .effect = EFFECT_BIDE,
        .power = 1,
        .type = TYPE_NORMAL,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .priority = 1,
        #elif B_UPDATED_MOVE_DATA >= GEN_2
            .accuracy = 100,
            .priority = 0,
        #else
            .accuracy = 0,
            .priority = 0,
        #endif
        .pp = 10,
        .target = TARGET_USER,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Bide,
    },

    [MOVE_METRONOME] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Metronom"),
#else
        .name = COMPOUND_STRING("METRONOME"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bewegt Finger und wählt eine\n"
            "{PKMN}-Attacke zufällig aus."),
#else
            "Waggles a finger to use any\n"
            "Pokémon move at random."),
#endif
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_3,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Metronome,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIRROR_MOVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Spiegeltrick"),
#else
        .name = COMPOUND_STRING("MIRROR MOVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erwidert gegn. Angriff mit\n"
            "derselben Attacke."),
#else
            "Counters the foe's attack\n"
            "with the same move."),
#endif
        .effect = EFFECT_MIRROR_MOVE,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_3,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MirrorMove,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SELF_DESTRUCT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Finale"),
#else
        .name = COMPOUND_STRING("SELF-DESTRUCT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Richtet großen Schaden an.\n"
            "Anwender wird besiegt."),
#else
            "Inflicts severe damage but\n"
            "makes the user faint."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 200 : 130,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .explosion = TRUE,
        .parentalBondBanned = TRUE,
        .dampBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_SelfDestruct,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EGG_BOMB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eierbombe"),
#else
        .name = COMPOUND_STRING("EGG BOMB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Ei wird auf den Gegner\n"
            "abgefeuert."),
#else
            "An egg is forcibly hurled at\n"
            "the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SOFT_BOILED},
        .battleAnimScript = gBattleAnimMove_EggBomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schlecker"),
#else
        .name = COMPOUND_STRING("LICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Leck-Attacke mit Zunge.\n"
            "Gegner evtl. paralysiert."),
#else
            "Licks with a long tongue to\n"
            "injure. May also paralyze."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 30 : 20,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Lick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SMOG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Smog"),
#else
        .name = COMPOUND_STRING("SMOG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit Gas. Gegner wird\n"
            "evtl. vergiftet."),
#else
            "An exhaust-gas attack\n"
            "that may also poison."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 30 : 20,
        .type = TYPE_POISON,
        .accuracy = 70,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 40,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SMOG,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Smog,
    },

    [MOVE_SLUDGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schlammbad"),
#else
        .name = COMPOUND_STRING("SLUDGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirft Schlamm auf Gegner.\n"
            "Evtl. Vergiftung."),
#else
            "Sludge is hurled to inflict\n"
            "damage. May also poison."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 40,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SLUDGE,
        .contestComboMoves = {COMBO_STARTER_SLUDGE_BOMB},
        .battleAnimScript = gBattleAnimMove_Sludge,
    },

    [MOVE_BONE_CLUB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Knochenkeule"),
#else
        .name = COMPOUND_STRING("BONE CLUB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlägt Gegner mit Keule\n"
            "und verschreckt ihn evtl."),
#else
            "Clubs the foe with a bone.\n"
            "May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONE_CLUB,
        .contestComboMoves = {COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH, COMBO_STARTER_SHADOW_BONE},
        .battleAnimScript = gBattleAnimMove_BoneClub,
    },

    [MOVE_FIRE_BLAST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feuersturm"),
#else
        .name = COMPOUND_STRING("FIRE BLAST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Feuersbrunst, die alles ver-\n"
            "sengt. Verbrennt Geg. evtl."),
#else
            "Incinerates everything it\n"
            "strikes. May cause a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FireBlast,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATERFALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kaskade"),
#else
        .name = COMPOUND_STRING("WATERFALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine mächtige Attacke. Das\n"
            "Ziel schreckt evtl. zurück."),
#else
            "Charges with speed to climb\n"
            "waterfalls. May flinch."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_FLINCH,
                .chance = 20,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Waterfall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CLAMP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schnapper"),
#else
        .name = COMPOUND_STRING("CLAMP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Umklammert und quetscht\n"
            ""BINDING_TURNS" Runden lang."),
#else
            "Traps and squeezes the\n"
            "foe for "BINDING_TURNS" turns."),
#endif
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 75,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 15 : 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_CLAMP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Clamp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWIFT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sternschauer"),
#else
        .name = COMPOUND_STRING("SWIFT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verschießt sternförmige\n"
            "Strahlen. Treffergarantie!"),
#else
            "Sprays star-shaped rays\n"
            "that never miss."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Swift,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKULL_BASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schädelwumme"),
#else
        .name = COMPOUND_STRING("SKULL BASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Zieht Kopf ein und greift in\n"
            "der nächsten Runde an."),
#else
            "Tucks in the head, then\n"
            "attacks on the next turn."),
#endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNLOWEREDHEAD },
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
                .self = TRUE,
                .onChargeTurnOnly = TRUE,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkullBash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIKE_CANNON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dornkanone"),
#else
        .name = COMPOUND_STRING("SPIKE CANNON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verschießt spitze Stacheln\n"
            "und trifft 2 - 5-mal."),
#else
            "Launches sharp spikes that\n"
            "strike 2 to 5 times."),
#endif
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpikeCannon,
    },

    [MOVE_CONSTRICT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Umklammerung"),
#else
        .name = COMPOUND_STRING("CONSTRICT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schmerzvoller Klammergriff.\n"
            "Senkt evtl. INIT.-Wert."),
#else
            "Constricts to inflict pain.\n"
            "May lower Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Constrict,
    },

    [MOVE_AMNESIA] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Amnesie"),
#else
        .name = COMPOUND_STRING("AMNESIA"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gedächtnisverlust, der\n"
            "SPEZ. VERT. deutlich erhöht."),
#else
            "Forgets about something\n"
            "and sharply raises Sp. Def."),
#endif
        .effect = EFFECT_SPECIAL_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_AMNESIA,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Amnesia,
        .validApprenticeMove = TRUE,
    },

    [MOVE_KINESIS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psykraft"),
#else
        .name = COMPOUND_STRING("KINESIS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lenkt Gegner ab und senkt\n"
            "evtl. seine Genauigkeit."),
#else
            "Distracts the foe.\n"
            "May lower accuracy."),
#endif
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 80,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_KINESIS,
        .contestComboMoves = {COMBO_STARTER_CONFUSION, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_Kinesis,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SOFT_BOILED] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Weichei"),
#else
        .name = COMPOUND_STRING("SOFT-BOILED"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Max. KP des Anwenders w.\n"
            "bis zur Hälfte aufgefüllt."),
#else
            "Recovers up to half the\n"
            "user's maximum HP."),
#endif
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_FIRST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SOFT_BOILED,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SoftBoiled,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HIGH_JUMP_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Turmkick"),
#else
        .name = COMPOUND_STRING("HIGH JUMP KICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sprungtritt mit Knie. Misser-\n"
            "folg verletzt den Anwender."),
#else
            "A jumping knee kick. If it\n"
            "misses, the user is hurt."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 130,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 100,
        #else
            .power = 85,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_HighJumpKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GLARE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftblick"),
#else
        .name = COMPOUND_STRING("GLARE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schüchtert Gegner ein, so\n"
            "dass er paralysiert ist."),
#else
            "Intimidates and frightens\n"
            "the foe into paralysis."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 90,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_PARALYSIS },
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_GLARE,
        .contestComboMoves = {COMBO_STARTER_LEER},
        .battleAnimScript = gBattleAnimMove_Glare,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DREAM_EATER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Traumfresser"),
#else
        .name = COMPOUND_STRING("DREAM EATER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlafendem Gegner wird\n"
            "halber Schaden abgezogen."),
#else
            "Takes one half the damage\n"
            "inflicted on a sleeping foe."),
#endif
        .effect = EFFECT_DREAM_EATER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER},
        .battleAnimScript = gBattleAnimMove_DreamEater,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POISON_GAS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftwolke"),
#else
        .name = COMPOUND_STRING("POISON GAS"),
#endif
#if GERMAN
        .description = COMPOUND_STRING(
            "Hüllt Gegner in giftiges\n"
            "Gas ein, kann vergiften."),
#else
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_5
            "Envelops the foes in a toxic\n"
        #else
            "Envelops the foe in a toxic\n"
        #endif
            "gas that may poison."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 90,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 80,
        #else
            .accuracy = 55,
        #endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_POISON,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_5 ? TARGET_BOTH : TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_POISON },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_POISON_GAS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonGas,
    },

    [MOVE_BARRAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stakkato"),
#else
        .name = COMPOUND_STRING("BARRAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirft 2 - 5-mal runde Gegen-\n"
            "stände auf den Gegner."),
#else
            "Hurls round objects at the\n"
            "foe 2 to 5 times."),
#endif
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Barrage,
    },

    [MOVE_LEECH_LIFE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blutsauger"),
#else
        .name = COMPOUND_STRING("LEECH LIFE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Angriff, der die Hälfte\n"
            "des Schadens absaugt."),
#else
            "Attack that steals half\n"
            "the damage inflicted."),
#endif
        .effect = EFFECT_ABSORB,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeechLife,
    },

    [MOVE_LOVELY_KISS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Todeskuss"),
#else
        .name = COMPOUND_STRING("LOVELY KISS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fordert Kuss mit bösem\n"
            "Blick. Evtl. Schlaf."),
#else
            "Demands a kiss with a scary\n"
            "face that induces sleep."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_LOVELY_KISS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LovelyKiss,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKY_ATTACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Himmelsfeger"),
#else
        .name = COMPOUND_STRING("SKY ATTACK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft in Runde 2. Hohe Voll-\n"
            "trefferquote, schreckt evtl."),
#else
            "2-turn attack. High critical\n"
            "hit ratio, and may flinch."),
#endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = B_UPDATED_MOVE_DATA >= GEN_4 ? STRINGID_CLOAKEDINAHARSHLIGHT : STRINGID_PKMNISGLOWING },
    #if B_UPDATED_MOVE_DATA >= GEN_3
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
    #endif
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkyAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRANSFORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wandler"),
#else
        .name = COMPOUND_STRING("TRANSFORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ändert die Anwenderzellen\n"
            "für ein Ebenbild d. Gegners."),
#else
            "Alters the user's cells to\n"
            "become a copy of the foe."),
#endif
        .effect = EFFECT_TRANSFORM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS < GEN_5,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Transform,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BUBBLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blubber"),
#else
        .name = COMPOUND_STRING("BUBBLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit Blasen. INIT.-\n"
            "Wert wird evtl. gesenkt."),
#else
            "Attack using bubbles.\n"
            "May lower the foe's Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 40 : 20,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Bubble,
    },

    [MOVE_DIZZY_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Irrschlag"),
#else
        .name = COMPOUND_STRING("DIZZY PUNCH"),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_2
        .description = COMPOUND_STRING(
#if GERMAN
            "Rhythmischer Schlag, der\n"
            "den Gegner verwirren kann."),
#else
                "A rhythmic punch that may\n"
                "confuse the target."),
#endif
        #else
            .description = COMPOUND_STRING(
#if GERMAN
                "Das Ziel wird getroffen\n"
                "von rhythmischen Schlägen."),
#else
                "The target is hit with\n"
                "rhythmic punches."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_CONFUSION,
                .chance = 20,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DizzyPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPORE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pilzspore"),
#else
        .name = COMPOUND_STRING("SPORE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt eine Wolke aus ein-\n"
            "schläfernden Sporen."),
#else
            "Scatters a cloud of spores\n"
            "that always induce sleep."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SPORE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Spore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blitz"),
#else
        .name = COMPOUND_STRING("FLASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt helles Licht, das\n"
            "gegn. Genauigkeit senkt."),
#else
            "Looses a powerful blast of\n"
            "light that cuts accuracy."),
#endif
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 70,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Flash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYWAVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psywelle"),
#else
        .name = COMPOUND_STRING("PSYWAVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Psycho-Welle mit unter-\n"
            "schiedlicher Intensität."),
#else
            "Attacks with a psychic\n"
            "wave of varying intensity."),
#endif
        .effect = EFFECT_PSYWAVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 80,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_Psywave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPLASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Platscher"),
#else
        .name = COMPOUND_STRING("SPLASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Nur ein Platscher..., der\n"
            "überhaupt nichts bewirkt."),
#else
            "It's just a splash...\n"
            "Has no effect whatsoever."),
#endif
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_3 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Splash,
    },

    [MOVE_ACID_ARMOR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Säurepanzer"),
#else
        .name = COMPOUND_STRING("ACID ARMOR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verflüssigt Körper d. An-\n"
            "wenders. Erhöht VERT."),
#else
            "Liquifies the user's body\n"
            "to sharply raise Defense."),
#endif
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AcidArmor,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CRABHAMMER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Krabbhammer"),
#else
        .name = COMPOUND_STRING("CRABHAMMER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlägt mit Schere zu.\n"
            "Volltrefferchance hoch."),
#else
            "Hammers with a pincer. Has a\n"
            "high critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 90,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_Crabhammer,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EXPLOSION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Explosion"),
#else
        .name = COMPOUND_STRING("EXPLOSION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Richtet großen Schaden an.\n"
            "Anwender wird besiegt."),
#else
            "Inflicts severe damage but\n"
            "makes the user faint."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_2 ? 250 : 170,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .explosion = TRUE,
        .parentalBondBanned = TRUE,
        .dampBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_Explosion,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FURY_SWIPES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kratzfurie"),
#else
        .name = COMPOUND_STRING("FURY SWIPES"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Beharkt Gegner 2 - 5-mal\n"
            "mit scharfen Klauen o. ä."),
#else
            "Rakes the foe with sharp\n"
            "claws, etc., 2 to 5 times."),
#endif
        .effect = EFFECT_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 80,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCRATCH},
        .battleAnimScript = gBattleAnimMove_FurySwipes,
    },

    [MOVE_BONEMERANG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Knochmerang"),
#else
        .name = COMPOUND_STRING("BONEMERANG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Bumerang aus Knochen,\n"
            "der zweimal trifft."),
#else
            "Throws a bone boomerang\n"
            "that strikes twice."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_GROUND,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .strikeCount = 2,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONEMERANG,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONE_RUSH, COMBO_STARTER_SHADOW_BONE},
        .battleAnimScript = gBattleAnimMove_Bonemerang,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Erholung"),
#else
        .name = COMPOUND_STRING("REST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender schläft 2 Runden,\n"
            "KP und Status erneuert."),
#else
            "The user sleeps for 2 turns,\n"
            "restoring HP and status."),
#endif
        .effect = EFFECT_REST,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_REST,
        .contestComboMoves = {COMBO_STARTER_BELLY_DRUM, COMBO_STARTER_CHARM, COMBO_STARTER_YAWN},
        .battleAnimScript = gBattleAnimMove_Rest,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_SLIDE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Steinhagel"),
#else
        .name = COMPOUND_STRING("ROCK SLIDE"),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_2
        .description = COMPOUND_STRING(
#if GERMAN
            "Schleudert riesige Felsen.\n"
            "Verschreckt evtl. Gegner."),
#else
                "Large boulders are hurled.\n"
                "May cause flinching."),
#endif
        #else
            .description = COMPOUND_STRING(
#if GERMAN
                "Trifft den Gegner mit\n"
                "einer Lawine aus Steinen."),
#else
                "Hits the foe with an\n"
                "avalanche of rocks."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_FLINCH,
                .chance = 30,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROCK_THROW},
        .battleAnimScript = gBattleAnimMove_RockSlide,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYPER_FANG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hyperzahn"),
#else
        .name = COMPOUND_STRING("HYPER FANG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit Zähnen.\n"
            "Verschreckt evtl. Gegner."),
#else
            "Attacks with sharp fangs.\n"
            "May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HyperFang,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHARPEN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schärfer"),
#else
        .name = COMPOUND_STRING("SHARPEN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Reduziert Polygonzahl und\n"
            "erhöht ANGR.-Wert."),
#else
            "Reduces the polygon count\n"
            "and raises Attack."),
#endif
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sharpen,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONVERSION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Umwandlung"),
#else
        .name = COMPOUND_STRING("CONVERSION"),
#endif
        .description = COMPOUND_STRING(
        #if B_UPDATED_CONVERSION >= GEN_6
#if GERMAN
            "Wandelt Typ d. Anwenders in\n"
            "Typ der ersten Attacke."),
#else
            "into first known move's type."),
#endif
        #else
#if GERMAN
            "Wandelt Typ d. Anwenders in\n"
            "bekannten Attacken-Typ."),
#else
            "into a known move's type."),
#endif
        #endif
        .effect = EFFECT_CONVERSION,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Conversion,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRI_ATTACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Triplette"),
#else
        .name = COMPOUND_STRING("TRI ATTACK"),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_2
        .description = COMPOUND_STRING(
        #if B_USE_FROSTBITE == TRUE
#if GERMAN
            "Feuert 3 Arten von Strahlen.\n"
            "Evtl. Verbr./Paral./Frostb."),
#else
                    "May burn/para/frostbite."),
#endif
        #else
#if GERMAN
            "Feuert 3 Arten von Strahlen\n"
            "gleichzeitig ab."),
#else
                    "May burn/paralyze/freeze."),
#endif
        #endif
        #else
            .description = COMPOUND_STRING(
#if GERMAN
                "Ein dreieckiges Energiefeld\n"
                "wird erzeugt und gestartet."),
#else
                "A triangular field of energy\n"
                "is created and launched."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        #if B_UPDATED_MOVE_DATA >= GEN_2
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_TRI_ATTACK,
                .chance = 20,
            }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON},
        .battleAnimScript = gBattleAnimMove_TriAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUPER_FANG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Superzahn"),
#else
        .name = COMPOUND_STRING("SUPER FANG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift mit scharfen Zähnen\n"
            "an. Halbiert gegnerische KP."),
#else
            "Attacks with sharp fangs\n"
            "and cuts half the foe's HP."),
#endif
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .damagePercentage = 50 },
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_SuperFang,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schlitzer"),
#else
        .name = COMPOUND_STRING("SLASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hieb mit Klauen o. ä. Hohe\n"
            "Volltrefferquote."),
#else
            "Slashes with claws, etc. Has\n"
            "a high critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCRATCH, COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_Slash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUBSTITUTE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Delegator"),
#else
        .name = COMPOUND_STRING("SUBSTITUTE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lockvogel, der 1/4 der max.\n"
            "KP des Anwenders besitzt."),
#else
            "Creates a decoy using 1/4\n"
            "of the user's maximum HP."),
#endif
        .effect = EFFECT_SUBSTITUTE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Substitute,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STRUGGLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Verzweifler"),
#else
        .name = COMPOUND_STRING("STRUGGLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Einsatz nur bei verbrauch-\n"
            "ten AP. Selbstschädigung!"),
#else
            "Used only if all PP are gone.\n"
            "Also hurts the user a little."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_STRUGGLE,
            .accuracy = 0,
            .pp = 1,
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_RECOIL_HP_25,
                .self = TRUE,
            }),
        #elif B_UPDATED_MOVE_DATA >= GEN_2
            .effect = EFFECT_RECOIL,
            .accuracy = 100,
            .pp = 1,
            .argument = { .recoilPercentage = 25 },
        #else
            .effect = EFFECT_RECOIL,
            .accuracy = 100,
            .pp = 10,
            .argument = { .recoilPercentage = 50 },
        #endif
        .power = 50,
        .type = TYPE_NORMAL,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .battleAnimScript = gBattleAnimMove_Struggle,
        .validApprenticeMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_TOUGH,
    },

    [MOVE_SKETCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nachahmer"),
#else
        .name = COMPOUND_STRING("SKETCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kopiert stets den zuletzt\n"
            "erlittenen Angriff."),
#else
            "Copies the foe's last move\n"
            "permanently."),
#endif
        .effect = EFFECT_SKETCH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sketch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRIPLE_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dreifachkick"),
#else
        .name = COMPOUND_STRING("TRIPLE KICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Tritt Gegner 3-mal nach-\n"
            "einander. Härte nimmt zu."),
#else
            "Kicks the foe 3 times in a\n"
            "row with rising intensity."),
#endif
        .effect = EFFECT_TRIPLE_KICK,
        .power = 10,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_TripleKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_THIEF] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Raub"),
#else
        .name = COMPOUND_STRING("THIEF"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kann das vom Gegner\n"
            "gehaltene Item stehlen."),
#else
            "While attacking, it may\n"
            "steal the foe's held item."),
#endif
        .effect = EFFECT_STEAL_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Thief,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIDER_WEB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Spinnennetz"),
#else
        .name = COMPOUND_STRING("SPIDER WEB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wickelt Gegner ein. Flucht \n"
            "oder Tausch unmöglich."),
#else
            "Ensnares the foe to stop it\n"
            "from fleeing or switching."),
#endif
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_3,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STRING_SHOT},
        .battleAnimScript = gBattleAnimMove_SpiderWeb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIND_READER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Willensleser"),
#else
        .name = COMPOUND_STRING("MIND READER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ahnt gegnerische Aktion.\n"
            "Nächste Attacke trifft."),
#else
            "Senses the foe's action to\n"
            "ensure the next move's hit."),
#endif
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_EARLIER : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_MIND_READER,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MindReader,
        .validApprenticeMove = TRUE,
    },

    [MOVE_NIGHTMARE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nachtmahr"),
#else
        .name = COMPOUND_STRING("NIGHTMARE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bewirkt 1/4 Schaden pro\n"
            "Zug bei schlafendem Gegner."),
#else
            "Inflicts 1/4 damage on a\n"
            "sleeping foe every turn."),
#endif
        .effect = EFFECT_NIGHTMARE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_3,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER},
        .battleAnimScript = gBattleAnimMove_Nightmare,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLAME_WHEEL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flammenrad"),
#else
        .name = COMPOUND_STRING("FLAME WHEEL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Feuer-Attacke, die Gegner\n"
            "evtl. verbrennt."),
#else
            "A fiery charge attack that\n"
            "may inflict a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FlameWheel,
    },

    [MOVE_SNORE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schnarcher"),
#else
        .name = COMPOUND_STRING("SNORE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Laute Attacke. Kann nur im\n"
            "Schlaf benutzt werden."),
#else
            "A loud attack that can only\n"
            "be used asleep. May flinch."),
#endif
        .effect = EFFECT_SNORE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_REST},
        .battleAnimScript = gBattleAnimMove_Snore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CURSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fluch"),
#else
        .name = COMPOUND_STRING("CURSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirkt anders, wenn der\n"
            "Anwender ein Geist-{PKMN} ist."),
#else
            "A move that functions\n"
            "differently for GHOSTS."),
#endif
        .effect = EFFECT_CURSE,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_5 ? TYPE_GHOST : TYPE_MYSTERY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_CURSE },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_CURSE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Curse,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLAIL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dreschflegel"),
#else
        .name = COMPOUND_STRING("FLAIL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Richtet mehr Schaden an,\n"
            "wenn eigene KP niedrig sind."),
#else
            "Inflicts more damage when\n"
            "the user's HP is down."),
#endif
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_Flail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CONVERSION_2] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Umwandlung2"),
#else
        .name = COMPOUND_STRING("CONVERSION 2"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender wird resistent\n"
            "gegen letzten Angr.-Typ."),
#else
            "Makes the user resistant\n"
            "to the last attack's type."),
#endif
        .effect = EFFECT_CONVERSION_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = B_UPDATED_MOVE_DATA >= GEN_5 ? TARGET_SELECTED : TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Conversion2,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AEROBLAST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Luftstoß"),
#else
        .name = COMPOUND_STRING("AEROBLAST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt ein Vakuum.\n"
            "Hohe Volltrefferquote."),
#else
            "Launches a vacuumed blast.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST :
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Aeroblast,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COTTON_SPORE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Baumwollsaat"),
#else
        .name = COMPOUND_STRING("COTTON SPORE"),
#endif
#if GERMAN
        .description = COMPOUND_STRING(
            "Sporen heften sich an den\n"
            "Gegner. Senkt INIT.-Wert."),
#else
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_6
            "Spores cling to the foes,\n"
        #else
            "Spores cling to the foe,\n"
        #endif
            "sharply reducing Speed."),
#endif
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 85,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_6 ? TARGET_BOTH : TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CottonSpore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REVERSAL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gegenschlag"),
#else
        .name = COMPOUND_STRING("REVERSAL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Richtet mehr Schaden an,\n"
            "wenn eigene KP niedrig sind."),
#else
            "Inflicts more damage when\n"
            "the user's HP is down."),
#endif
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_LATER : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_Reversal,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPITE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Groll"),
#else
        .name = COMPOUND_STRING("SPITE"),
#endif
#if GERMAN
        .description = COMPOUND_STRING(
            "AP des letzten gegner.\n"
            "Angriffs werden gesenkt."),
#else
        .description = COMPOUND_STRING(
            "Spitefully cuts the PP\n"
        #if B_PP_REDUCED_BY_SPITE >= GEN_4
            "of the foe's last move by 4."),
        #else
            "of foe's last move by 2-5."),
        #endif
#endif
        .effect = EFFECT_SPITE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresSubstitute = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_Spite,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POWDER_SNOW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pulverschnee"),
#else
        .name = COMPOUND_STRING("POWDER SNOW"),
#endif
        .description = COMPOUND_STRING(
        #if B_USE_FROSTBITE == TRUE
#if GERMAN
            "Bläst Schnee. Kann dabei\n"
            "Frostbeulen verursachen."),
#else
            "gust. May cause frostbite."),
#endif
        #else
#if GERMAN
            "Schnee auf Gegner, der\n"
            "evtl. eingefroren wird."),
#else
            "gust. May cause freezing."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_POWDER_SNOW,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_PowderSnow,
    },

    [MOVE_PROTECT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schutzschild"),
#else
        .name = COMPOUND_STRING("PROTECT"),
#endif
        .description = sProtectDescription,
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .priority = 3,
        #else
            .priority = 2,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_NORMAL },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_Protect,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MACH_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tempohieb"),
#else
        .name = COMPOUND_STRING("MACH PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schneller Hieb, der stets\n"
            "zuerst trifft."),
#else
            "A punch is thrown at wicked\n"
            "speed to strike first."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MachPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SCARY_FACE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Grimasse"),
#else
        .name = COMPOUND_STRING("SCARY FACE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erschreckt mit Grimasse. \n"
            "INIT.-Wert sinkt deutlich."),
#else
            "Frightens with a scary face\n"
            "to sharply reduce Speed."),
#endif
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCARY_FACE,
        .contestComboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_RAGE},
        .battleAnimScript = gBattleAnimMove_ScaryFace,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FEINT_ATTACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Finte"),
#else
        .name = COMPOUND_STRING("FEINT ATTACK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Zieht den Gegner heran und\n"
            "entwaffnet ihn. Trifft immer."),
#else
            "Draws the foe close, then\n"
            "strikes without fail."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_LEER, COMBO_STARTER_POUND},
        .battleAnimScript = gBattleAnimMove_FeintAttack,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWEET_KISS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bitterkuss"),
#else
        .name = COMPOUND_STRING("SWEET KISS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fordert Kuss mit süßem\n"
            "Blick. Verwirrt Gegner evtl."),
#else
            "Demands a kiss with a cute\n"
            "look. May cause confusion."),
#endif
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_SweetKiss,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BELLY_DRUM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bauchtrommel"),
#else
        .name = COMPOUND_STRING("BELLY DRUM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht ANGR.-Wert,\n"
            "opfert jedoch KP."),
#else
            "Maximizes Attack while\n"
            "sacrificing half of max HP."),
#endif
        .effect = EFFECT_BELLY_DRUM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BELLY_DRUM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BellyDrum,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLUDGE_BOMB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Matschbombe"),
#else
        .name = COMPOUND_STRING("SLUDGE BOMB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirft Schlamm auf Gegner\n"
            "und vergiftet ihn evtl."),
#else
            "Sludge is hurled to inflict\n"
            "damage. May also poison."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SLUDGE_BOMB,
        .contestComboMoves = {COMBO_STARTER_SLUDGE},
        .battleAnimScript = gBattleAnimMove_SludgeBomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUD_SLAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lehmschelle"),
#else
        .name = COMPOUND_STRING("MUD-SLAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirft Gegner Matsch ins Ge-\n"
            "sicht. Genauigkeit sinkt."),
#else
            "Hurls mud in the foe's face\n"
            "to reduce its accuracy."),
#endif
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_MUD_SLAP,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_SAND_ATTACK, COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_MudSlap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_OCTAZOOKA] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Octazooka"),
#else
        .name = COMPOUND_STRING("OCTAZOOKA"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verschießt Tinte und senkt\n"
            "dadurch Genauigkeit."),
#else
            "Fires a lump of ink to\n"
            "damage and cut accuracy."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Octazooka,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIKES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stachler"),
#else
        .name = COMPOUND_STRING("SPIKES"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Richtet bei Tausch Schaden\n"
            "mit Stacheln an."),
#else
            "Sets spikes that hurt a \n"
            "foe switching in."),
#endif
        .effect = EFFECT_SPIKES,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .forcePressure = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_SPIKES,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Spikes,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ZAP_CANNON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blitzkanone"),
#else
        .name = COMPOUND_STRING("ZAP CANNON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kräftige, ungenaue At-\n"
            "tacke, die evtl. paralysiert."),
#else
            "Powerful and sure to cause\n"
            "paralysis, but inaccurate."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 120 : 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 50,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_LOCK_ON},
        .battleAnimScript = gBattleAnimMove_ZapCannon,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FORESIGHT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gesichte"),
#else
        .name = COMPOUND_STRING("FORESIGHT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verhindert Anstieg von\n"
            "gegnerischem Fluchtwert."),
#else
            "Negates the foe's efforts\n"
            "to heighten evasiveness."),
#endif
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 0 : 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresSubstitute = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Foresight,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DESTINY_BOND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Abgangsbund"),
#else
        .name = COMPOUND_STRING("DESTINY BOND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wird der Angreifer besiegt,\n"
            "gilt das auch für d. Gegner."),
#else
            "If the user faints, the foe\n"
            "is also made to faint."),
#endif
        .effect = EFFECT_DESTINY_BOND,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_FOLLOW_ME },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENDURE, COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_DestinyBond,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PERISH_SONG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Abgesang"),
#else
        .name = COMPOUND_STRING("PERISH SONG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wer dieses Lied hört, wird\n"
            "nach 3 Runden besiegt."),
#else
            "Any Pokémon hearing this\n"
            "song faints in 3 turns."),
#endif
        .effect = EFFECT_PERISH_SONG,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_SING, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_PerishSong,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICY_WIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eissturm"),
#else
        .name = COMPOUND_STRING("ICY WIND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eis-Attacke, die den INIT.-\n"
            "Wert des Gegners senkt."),
#else
            "A chilling attack that\n"
            "lowers the foe's Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IcyWind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DETECT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Scanner"),
#else
        .name = COMPOUND_STRING("DETECT"),
#endif
        .description = sProtectDescription,
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .priority = 3,
        #else
            .priority = 2,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_NORMAL },
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT},
        .battleAnimScript = gBattleAnimMove_Detect,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BONE_RUSH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Knochenhatz"),
#else
        .name = COMPOUND_STRING("BONE RUSH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift Gegner 2 - 5-mal in\n"
            "Folge mit einem Knochen an."),
#else
            "Strikes the foe with a bone\n"
            "in hand 2 to 5 times."),
#endif
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_GROUND,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 80,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONE_RUSH,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_SHADOW_BONE},
        .battleAnimScript = gBattleAnimMove_BoneRush,
    },

    [MOVE_LOCK_ON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zielschuss"),
#else
        .name = COMPOUND_STRING("LOCK-ON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Visiert Gegner an u. trifft\n"
            "in der nächsten Runde."),
#else
            "Locks on to the foe to\n"
            "ensure the next move hits."),
#endif
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_EARLIER : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_LOCK_ON,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LockOn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_OUTRAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wutanfall"),
#else
        .name = COMPOUND_STRING("OUTRAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wiederholt Angriff 2-3 Run-\n"
            "den lang. Verwirrt Anwender."),
#else
            "A rampage of 2 to 3 turns\n"
            "that confuses the user."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 120 : 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 15,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Outrage,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SANDSTORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sandsturm"),
#else
        .name = COMPOUND_STRING("SANDSTORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt einen Sandsturm,\n"
            "der mehrere Runden wütet."),
#else
            "Causes a sandstorm that\n"
            "rages for several turns."),
#endif
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .windMove = TRUE,
        .argument = { .weatherType = BATTLE_WEATHER_SANDSTORM },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SANDSTORM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Sandstorm,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GIGA_DRAIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gigasauger"),
#else
        .name = COMPOUND_STRING("GIGA DRAIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Absorbiert die Hälfte des\n"
            "angerichteten Schadens."),
#else
            "Attack that steals half\n"
            "the damage inflicted."),
#endif
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_GigaDrain,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ENDURE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ausdauer"),
#else
        .name = COMPOUND_STRING("ENDURE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hält jeder Attacke 1 Runde\n"
            "stand. 1 KP bleibt stets."),
#else
            "Endures any attack for\n"
            "1 turn, leaving at least 1HP."),
#endif
        .effect = EFFECT_ENDURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #elif B_UPDATED_MOVE_DATA >= GEN_3
            .priority = 3,
        #else
            .priority = 2,
        #endif
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_NONE },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_NEXT_APPEAL_LATER : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ENDURE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Endure,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CHARM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Charme"),
#else
        .name = COMPOUND_STRING("CHARM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Betört den Gegner u. redu-\n"
            "ziert seinen ANGR. deutlich."),
#else
            "Charms the foe and sharply\n"
            "reduces its Attack."),
#endif
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_CHARM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Charm,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROLLOUT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Walzer"),
#else
        .name = COMPOUND_STRING("ROLLOUT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Attacke, die 5 Runden\n"
            "dauert. Die Härte nimmt zu."),
#else
            "Attack lasting 5 turns\n"
            "with rising intensity."),
#endif
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN},
        .battleAnimScript = gBattleAnimMove_Rollout,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FALSE_SWIPE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Trugschlag"),
#else
        .name = COMPOUND_STRING("FALSE SWIPE"),
#endif
        .description = sFalseSwipeDescription,
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_FalseSwipe,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWAGGER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Angeberei"),
#else
        .name = COMPOUND_STRING("SWAGGER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verwirrt den Gegner und\n"
            "erhöht ANGR.-Wert deutlich."),
#else
            "Confuses the foe, but also\n"
            "sharply raises its Attack."),
#endif
        .effect = EFFECT_SWAGGER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 85 : 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        //.ignoresSubstitute = TRUE, In Gen4+, the attack raise will no longer bypass Substitute. However, this is tricky to code
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS : CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Swagger,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MILK_DRINK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Milchgetränk"),
#else
        .name = COMPOUND_STRING("MILK DRINK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt bis zur Hälfte der max.\n"
            "KP des Benutzers auf."),
#else
            "Recovers up to half the\n"
            "user's maximum HP."),
#endif
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_FIRST : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MilkDrink,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPARK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Funkensprung"),
#else
        .name = COMPOUND_STRING("SPARK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Elektro-Hieb, der Gegner\n"
            "paralysieren kann."),
#else
            "An electrified tackle that\n"
            "may paralyze the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Spark,
    },

    [MOVE_FURY_CUTTER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zornklinge"),
#else
        .name = COMPOUND_STRING("FURY CUTTER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Attacke, deren Härte\n"
            "bei jedem Treffer zunimmt."),
#else
            "Attack that intensifies\n"
            "on each successive hit."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 40,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 20,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_FURY_CUTTER,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_FuryCutter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STEEL_WING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stahlflügel"),
#else
        .name = COMPOUND_STRING("STEEL WING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft den Gegner hart mit\n"
            "ausgebreiteten Flügeln."),
#else
            "Strikes the foe with hard\n"
            "wings spread wide."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 90,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SteelWing,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEAN_LOOK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Horrorblick"),
#else
        .name = COMPOUND_STRING("MEAN LOOK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Böser Blick, der die Flucht\n"
            "des Gegners vereitelt."),
#else
            "Fixes the foe with a mean\n"
            "look that prevents escape."),
#endif
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = (B_UPDATED_MOVE_FLAGS >= GEN_6) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_MEAN_LOOK,
        .contestComboMoves = {COMBO_STARTER_CURSE},
        .battleAnimScript = gBattleAnimMove_MeanLook,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ATTRACT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Anziehung"),
#else
        .name = COMPOUND_STRING("ATTRACT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff des anderen Ge-\n"
            "schlechts unwahrscheinl."),
#else
            "Makes the opposite gender\n"
            "less likely to attack."),
#endif
        .effect = EFFECT_ATTRACT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Attract,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLEEP_TALK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schlafrede"),
#else
        .name = COMPOUND_STRING("SLEEP TALK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Benutzt per Zufall eine\n"
            "Attacke im Schlaf."),
#else
            "Uses an available move\n"
            "randomly while asleep."),
#endif
        .effect = EFFECT_SLEEP_TALK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mimicBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_REST},
        .battleAnimScript = gBattleAnimMove_SleepTalk,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HEAL_BELL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Vitalglocke"),
#else
        .name = COMPOUND_STRING("HEAL BELL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Läutet beruhigend, heilt\n"
            "alle Status-Veränderungen."),
#else
            "Chimes soothingly to heal\n"
            "all status abnormalities."),
#endif
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_HEAL_BELL,
        .contestComboMoves = {COMBO_STARTER_LUCKY_CHANT},
        .battleAnimScript = gBattleAnimMove_HealBell,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RETURN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rückkehr"),
#else
        .name = COMPOUND_STRING("RETURN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff, dessen Kraft bei \n"
            "Freundschaft größer wird."),
#else
            "Attack that increases\n"
            "in power with friendship."),
#endif
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Return,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PRESENT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Geschenk"),
#else
        .name = COMPOUND_STRING("PRESENT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Bombe als Geschenk. Es\n"
            "kann KP wiederherstellen."),
#else
            "A gift in the form of a\n"
            "bomb. May restore HP."),
#endif
        .effect = EFFECT_PRESENT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CELEBRATE, COMBO_STARTER_COVET, COMBO_STARTER_HAPPY_HOUR, COMBO_STARTER_WISH},
        .battleAnimScript = gBattleAnimMove_Present,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FRUSTRATION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Frustration"),
#else
        .name = COMPOUND_STRING("FRUSTRATION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Attacke ist stärker bei\n"
            "verhassten TRAINERn."),
#else
            "Attack that is stronger\n"
            "if the Trainer is disliked."),
#endif
        .effect = EFFECT_FRUSTRATION,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Frustration,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SAFEGUARD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bodyguard"),
#else
        .name = COMPOUND_STRING("SAFEGUARD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Mystische Kraft, die alle\n"
            "Statusprobleme verhindert."),
#else
            "Protects allies from status\n"
            "problems for 5 turns."),
#endif
        .effect = EFFECT_SAFEGUARD,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 25,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Safeguard,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PAIN_SPLIT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Leidteiler"),
#else
        .name = COMPOUND_STRING("PAIN SPLIT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Addiert KP v. Anwender u.\n"
            "Gegner, teilt gerecht auf."),
#else
            "Adds the user and foe's HP,\n"
            "then shares them equally."),
#endif
        .effect = EFFECT_PAIN_SPLIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_3 ? 0 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_PainSplit,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SACRED_FIRE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Läuterfeuer"),
#else
        .name = COMPOUND_STRING("SACRED FIRE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Mystische Feuer-Attacke, \n"
            "die d. Geg. evtl. verbrennt."),
#else
            "A mystical fire attack that\n"
            "may inflict a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_SacredFire,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MAGNITUDE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Intensität"),
#else
        .name = COMPOUND_STRING("MAGNITUDE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein erdbebenartiger An-\n"
            "griff von zufälliger Stärke."),
#else
            "A ground-shaking attack\n"
            "of random intensity."),
#endif
        .effect = EFFECT_MAGNITUDE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesUnderground = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Magnitude,
    },

    [MOVE_DYNAMIC_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wuchtschlag"),
#else
        .name = COMPOUND_STRING("DYNAMIC PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kräftige Attacke, die ver-\n"
            "wirrt, aber ungenau ist."),
#else
            "Powerful and sure to cause\n"
            "confusion, but inaccurate."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 50,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_DynamicPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEGAHORN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Vielender"),
#else
        .name = COMPOUND_STRING("MEGAHORN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Brutaler Frontalangriff\n"
            "mit spitzen Hörnern."),
#else
            "A brutal ramming attack\n"
            "using out-thrust horns."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_BUG,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Megahorn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DRAGON_BREATH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feuerodem"),
#else
        .name = COMPOUND_STRING("DRAGON BREATH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fegt den Gegner mit zer-\n"
            "störerisch heißem Atem weg."),
#else
            "Strikes the foe with a blast\n"
            "of breath. May paralyze."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_BREATH,
        .contestComboMoves = {COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonBreath,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BATON_PASS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Staffette"),
#else
        .name = COMPOUND_STRING("BATON PASS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Tauscht {PKMN} aus. Alle\n"
            "Änderungen bleiben bestehen."),
#else
            "Switches out the user while\n"
            "keeping effects in play."),
#endif
        .effect = EFFECT_BATON_PASS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION : CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_AGILITY, COMBO_STARTER_AMNESIA, COMBO_STARTER_HONE_CLAWS, COMBO_STARTER_CALM_MIND, COMBO_STARTER_NASTY_PLOT, COMBO_STARTER_ROCK_POLISH},
        .battleAnimScript = gBattleAnimMove_BatonPass,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ENCORE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zugabe"),
#else
        .name = COMPOUND_STRING("ENCORE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel wiederholt die letz-\n"
            "te Attacke drei Runden lang."),
#else
            "Makes the foe repeat its\n"
            "last move over 3 turns."),
#endif
        .effect = EFFECT_ENCORE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .encoreBanned = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_ENCORE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Encore,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PURSUIT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Verfolgung"),
#else
        .name = COMPOUND_STRING("PURSUIT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Richtet großen Schaden bei\n"
            "Austausch des Gegners an."),
#else
            "Inflicts bad damage if used\n"
            "on a foe switching out."),
#endif
        .effect = EFFECT_PURSUIT,
        .power = 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Pursuit,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RAPID_SPIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Turbodreher"),
#else
        .name = COMPOUND_STRING("RAPID SPIN"),
#endif
        .description = COMPOUND_STRING(
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
#if GERMAN
            "Dreht sich, entfernt Effekte\n"
            "und erhöht das Tempo."),
#else
            "effects, while upping speed."),
#endif
        #else
#if GERMAN
            "Trifft den Gegner durch\n"
            "Drehen mit max. Tempo."),
#else
            "effects."),
#endif
        #endif
        .effect = EFFECT_RAPID_SPIN,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 50 : 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        #endif
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RapidSpin,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWEET_SCENT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lockduft"),
#else
        .name = COMPOUND_STRING("SWEET SCENT"),
#endif
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_6
#if GERMAN
            "Lockt Gegner an und senkt\n"
            "Fluchtwert deutlich."),
#else
            "Allures the foes to harshly\n"
            "reduce evasiveness."),
#endif
        #else
#if GERMAN
            "Lockt Gegner an und senkt\n"
            "seinen Fluchtwert."),
#else
            "Allures the foes to reduce\n"
            "evasiveness."),
#endif
        #endif
        .effect = B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_EVASION_DOWN_2 : EFFECT_EVASION_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SWEET_SCENT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SweetScent,
        .validApprenticeMove = TRUE,
    },

    [MOVE_IRON_TAIL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eisenschweif"),
#else
        .name = COMPOUND_STRING("IRON TAIL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Att. mit hartem Schweif. \n"
            "Senkt evtl. VERT.-Wert."),
#else
            "Attacks with a rock-hard\n"
            "tail. May lower Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 75,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IronTail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_METAL_CLAW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Metallklaue"),
#else
        .name = COMPOUND_STRING("METAL CLAW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Klauen-Attacke. Evtl. Er-\n"
            "höhung d. ANGR.-Wert d. Anw."),
#else
            "A claw attack that may\n"
            "raise the user's Attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 35,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_METAL_SOUND},
        .battleAnimScript = gBattleAnimMove_MetalClaw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_VITAL_THROW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Überwurf"),
#else
        .name = COMPOUND_STRING("VITAL THROW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Attacke stets gleich, aber\n"
            "mit Treffergarantie."),
#else
            "Makes the user's move last,\n"
            "but it never misses."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_VitalThrow,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MORNING_SUN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Morgengrauen"),
#else
        .name = COMPOUND_STRING("MORNING SUN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt KP auf. Die Menge\n"
            "hängt vom Wetter ab."),
#else
            "Restores HP. The amount\n"
            "varies with the weather."),
#endif
        .effect = EFFECT_MORNING_SUN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_MorningSun,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SYNTHESIS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Synthese"),
#else
        .name = COMPOUND_STRING("SYNTHESIS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt KP auf. Die Menge\n"
            "hängt vom Wetter ab."),
#else
            "Restores HP. The amount\n"
            "varies with the weather."),
#endif
        .effect = EFFECT_SYNTHESIS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Synthesis,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MOONLIGHT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mondschein"),
#else
        .name = COMPOUND_STRING("MOONLIGHT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt KP auf. Die Menge\n"
            "hängt vom Wetter ab."),
#else
            "Restores HP. The amount\n"
            "varies with the weather."),
#endif
        .effect = EFFECT_MOONLIGHT,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Moonlight,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HIDDEN_POWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kraftreserve"),
#else
        .name = COMPOUND_STRING("HIDDEN POWER"),
#endif
        .description = COMPOUND_STRING(
        #if B_HIDDEN_POWER_DMG >= GEN_6
#if GERMAN
            "Der Typ dieser Attacke\n"
            "hängt vom Benutzer ab."),
#else
            "The type varies\n"
            "with the user."),
#endif
        #else
#if GERMAN
            "Die Wirkung dieser Attacke\n"
            "hängt vom Benutzer ab."),
#else
            "The type and effectiveness\n"
            "vary with the user."),
#endif
        #endif
        .power = B_HIDDEN_POWER_DMG >= GEN_6 ? 60 : 1,
        .effect = EFFECT_HIDDEN_POWER,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HiddenPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CROSS_CHOP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kreuzhieb"),
#else
        .name = COMPOUND_STRING("CROSS CHOP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelter Hieb. Hohe \n"
            "Volltrefferquote."),
#else
            "A double-chopping attack.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_CrossChop,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TWISTER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Windhose"),
#else
        .name = COMPOUND_STRING("TWISTER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft Gegner mit\n"
            "heftigem Wirbelsturm."),
#else
            "Whips up a vicious twister\n"
            "to tear at foes. May flinch."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .damagesAirborneDoubleDamage = TRUE,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Twister,
    },

    [MOVE_RAIN_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Regentanz"),
#else
        .name = COMPOUND_STRING("RAIN DANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht Stärke von WASSER-\n"
            "Attacken 5 Runden lang."),
#else
            "Boosts the power of Water-\n"
            "type moves for 5 turns."),
#endif
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .argument = { .weatherType =  BATTLE_WEATHER_RAIN },
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_RAIN_DANCE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RainDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUNNY_DAY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sonnentag"),
#else
        .name = COMPOUND_STRING("SUNNY DAY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht Stärke von FEUER-\n"
            "Attacken 5 Runden lang."),
#else
            "Boosts the power of Fire-\n"
            "type moves for 5 turns."),
#endif
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .argument = { .weatherType = BATTLE_WEATHER_SUN },
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SUNNY_DAY,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SunnyDay,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CRUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Knirscher"),
#else
        .name = COMPOUND_STRING("CRUNCH"),
#endif
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_4
#if GERMAN
            "Beißt mit Reißzähnen zu\n"
            "und senkt evtl. VERT."),
#else
            "May lower Defense."),
#endif
        #else
#if GERMAN
            "Beißt mit Reißzähnen zu und\n"
            "senkt evtl. SPEZ. VERT."),
#else
            "May lower Sp. Def."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
            .additionalEffects = ADDITIONAL_EFFECTS({
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
        #else
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
        #endif
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCARY_FACE},
        .battleAnimScript = gBattleAnimMove_Crunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIRROR_COAT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Spiegelcape"),
#else
        .name = COMPOUND_STRING("MIRROR COAT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kontert d. Spezial-Attacke\n"
            "d. Geg. mit 2-facher Kraft."),
#else
            "Counters the foe's special\n"
            "attack at double the power."),
#endif
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = -5,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = {
            .reflectDamage.damagePercent = 200,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_SPECIAL,
        },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_5,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = B_UPDATED_MOVE_FLAGS <= GEN_8,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT, COMBO_STARTER_ENCORE, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_MirrorCoat,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYCH_UP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psycho-Plus"),
#else
        .name = COMPOUND_STRING("PSYCH UP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kopiert Effekt(e) d. Gegners\n"
            "u. gibt sie dem Angreifer."),
#else
            "Copies foe's stat changes\n"
            "and gives to the user."),
#endif
        .effect = EFFECT_PSYCH_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS < GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EXTREME_SPEED] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Turbotempo"),
#else
        .name = COMPOUND_STRING("EXTREME SPEED"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Extrem schnelle und kraft-\n"
            "volle Attacke."),
#else
            "An extremely fast and\n"
            "powerful attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 2 : 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ExtremeSpeed,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ANCIENT_POWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Antik-Kraft"),
#else
        .name = COMPOUND_STRING("ANCIENT POWER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Angriff, der alle\n"
            "Status-Werte erhöhen kann."),
#else
            "Attack that may raise\n"
            "all stats."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = B_UPDATED_MOVE_DATA < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AncientPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHADOW_BALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Spukball"),
#else
        .name = COMPOUND_STRING("SHADOW BALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bewirft Gegner und senkt\n"
            "evtl. SPEZ. VERT."),
#else
            "Hurls a black blob that may\n"
            "lower the foe's Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowBall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FUTURE_SIGHT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Seher"),
#else
        .name = COMPOUND_STRING("FUTURE SIGHT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt innere Kraft. Trifft\n"
            "2 Runden später."),
#else
            "Heightens inner power to\n"
            "strike 2 turns later."),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 100,
        #else
            .power = 80,
        #endif
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 90,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_SAME_TYPE : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_CONFUSION, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
        .battleAnimScript = gBattleAnimMove_FutureSight,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_SMASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zertrümmerer"),
#else
        .name = COMPOUND_STRING("ROCK SMASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Zertrümmernder Angriff, \n"
            "der evtl. VERT.-Wert senkt."),
#else
            "A rock-crushing attack\n"
            "that may lower Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 40 : 20,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockSmash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WHIRLPOOL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Whirlpool"),
#else
        .name = COMPOUND_STRING("WHIRLPOOL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fängt den Gegner in einem\n"
            "Strudel, "BINDING_TURNS" Rd."),
#else
            "Traps and hurts the foe in\n"
            "a whirlpool for "BINDING_TURNS" turns."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .damagesUnderwater = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_WHIRLPOOL,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Whirlpool,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BEAT_UP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Prügler"),
#else
        .name = COMPOUND_STRING("BEAT UP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ruft Pokémon hinzu, um an\n"
            "dem Angriff teilzuhaben."),
#else
            "Summons party Pokémon to\n"
            "join in the attack."),
#endif
        .effect = EFFECT_BEAT_UP,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 1 : 10,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BEAT_UP_MESSAGE,
            .preAttackEffect = TRUE,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BeatUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FAKE_OUT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mogelhieb"),
#else
        .name = COMPOUND_STRING("FAKE OUT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft nur mit dem 1. Schlag.\n"
            "Gegner schreckt zurück."),
#else
            "Moves 1st and flinches. Only\n"
            "works on user's 1st turn."),
#endif
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 3 : 1,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .effect = EFFECT_FIRST_TURN_ONLY,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_FAKE_OUT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FakeOut,
        .validApprenticeMove = TRUE,
    },

    [MOVE_UPROAR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aufruhr"),
#else
        .name = COMPOUND_STRING("UPROAR"),
#endif
#if GERMAN
        .description = COMPOUND_STRING(
        #if B_UPROAR_TURNS >= GEN_5
            "Erzeugt für 3 Züge einen\n"
            "Aufruhr. Verhindert Schlaf."),
        #else
            "Erzeugt für 2-5 Züge einen\n"
            "Aufruhr. Verhindert Schlaf."),
        #endif
#else
        .description = COMPOUND_STRING(
        #if B_UPROAR_TURNS >= GEN_5
            "Causes an uproar for 3\n"
        #else
            "Causes an uproar for 2 to 5\n"
        #endif
            "turns and prevents sleep."),
#endif
        .effect = EFFECT_UPROAR,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_UPROAR,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Uproar,
        .validApprenticeMove = TRUE,
    },

    [MOVE_STOCKPILE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Horter"),
#else
        .name = COMPOUND_STRING("STOCKPILE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lädt Kraft für bis zu 3\n"
            "Runden auf."),
#else
            "Charges up power for up to\n"
            "3 turns."),
#endif
        .effect = EFFECT_STOCKPILE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_4 ? 20 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_STOCKPILE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Stockpile,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SPIT_UP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Entfessler"),
#else
        .name = COMPOUND_STRING("SPIT UP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Entlädt gehortete Kraft.\n"
            "Je mehr, desto besser."),
#else
            "Releases stockpiled power\n"
            "(the more the better)."),
#endif
        .effect = EFFECT_SPIT_UP,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STOCKPILE},
        .battleAnimScript = gBattleAnimMove_SpitUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SWALLOW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Verzehrer"),
#else
        .name = COMPOUND_STRING("SWALLOW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Absorbiert gehortete\n"
            "Kraft. Stellt KP wieder her."),
#else
            "Absorbs stockpiled power\n"
            "and restores HP."),
#endif
        .effect = EFFECT_SWALLOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STOCKPILE},
        .battleAnimScript = gBattleAnimMove_Swallow,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HEAT_WAVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hitzewelle"),
#else
        .name = COMPOUND_STRING("HEAT WAVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gegner wird von heißem Atem\n"
            "getroffen. Verbrennt evtl."),
#else
            "Exhales a hot breath on the\n"
            "foes. May inflict a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 100,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_HeatWave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HAIL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hagelsturm"),
#else
        .name = COMPOUND_STRING("HAIL"),
#endif
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
            .description = COMPOUND_STRING(
#if GERMAN
                "Beschwört einen Schnee-\n"
                "sturm, der 5 Runden anhält."),
#else
                "Summons a snowstorm that\n"
                "lasts for five turns."),
#endif
        #else
            .description = COMPOUND_STRING(
#if GERMAN
                "Beschwört einen Hagelsturm,\n"
                "der jede Runde trifft."),
#else
                "Summons a hailstorm that\n"
                "strikes every turn."),
#endif
        #endif
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .argument = { .weatherType = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW) ? BATTLE_WEATHER_SNOW : BATTLE_WEATHER_HAIL },
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_HAIL,
        .contestComboMoves = {0},
        .battleAnimScript = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW) ? gBattleAnimMove_Snowscape : gBattleAnimMove_Hail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TORMENT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Folterknecht"),
#else
        .name = COMPOUND_STRING("TORMENT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Quält Gegner u. verhindert\n"
            "Wdh. eines Angriffs."),
#else
            "Torments the foe and stops\n"
            "successive use of a move."),
#endif
        .effect = EFFECT_TORMENT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_TORMENT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Torment,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FLATTER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schmeichler"),
#else
        .name = COMPOUND_STRING("FLATTER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verwirrt den Gegner, erhöht\n"
            "aber dessen SPEZ. ANGR."),
#else
            "Confuses the foe, but\n"
            "raises its Sp. Atk."),
#endif
        .effect = EFFECT_FLATTER,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_Flatter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WILL_O_WISP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Irrlicht"),
#else
        .name = COMPOUND_STRING("WILL-O-WISP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fügt dem Gegner \n"
            "Verbrennungen zu."),
#else
            "Inflicts a burn on the foe\n"
            "with intense fire."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 85 : 75,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_BURN },
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_WILL_O_WISP,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_WillOWisp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MEMENTO] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Memento-Mori"),
#else
        .name = COMPOUND_STRING("MEMENTO"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Benutzer ist besiegt\n"
            "und senkt die gegn. Werte."),
#else
            "The user faints and harshly\n"
            "lowers foes Atk and Sp.Atk."),
#endif
        .effect = EFFECT_MEMENTO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESTORE_REPLACEMENT_HP },
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_BLOCK},
        .battleAnimScript = gBattleAnimMove_Memento,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FACADE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fassade"),
#else
        .name = COMPOUND_STRING("FACADE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht ANGR. nach Verbren-\n"
            "nung, Paralyse o. Vergift."),
#else
            "Boosts power when burned,\n"
            "paralyzed, or poisoned."),
#endif
        .effect = EFFECT_FACADE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Facade,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FOCUS_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Power-Punch"),
#else
        .name = COMPOUND_STRING("FOCUS PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff, der später trifft.\n"
            "Ben. schreckt evtl. zurück."),
#else
            "Powerful attack, moves last.\n"
            "The user flinches if hit."),
#endif
        .effect = EFFECT_FOCUS_PUNCH,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = -3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = TRUE,
        .punchingMove = TRUE,
        .meFirstBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_FocusPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SMELLING_SALTS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Riechsalz"),
#else
        .name = COMPOUND_STRING("SMELLING SALTS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelt wirksam gegen\n"
            "Paralyse, heilt sie aber auch."),
#else
            "Powerful against paralyzed\n"
            "foes, but also heals them."),
#endif
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 70 : 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .status = STATUS1_PARALYSIS },
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FORCE_PALM, COMBO_STARTER_THUNDER_WAVE, COMBO_STARTER_GLARE},
        .battleAnimScript = gBattleAnimMove_SmellingSalts,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FOLLOW_ME] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Spotlight"),
#else
        .name = COMPOUND_STRING("FOLLOW ME"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Zieht Aufmerksamkeit an.\n"
            "Gegner greift nur Anw. an."),
#else
            "Draws attention to make\n"
            "foes attack only the user."),
#endif
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 2 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FollowMe,
        .validApprenticeMove = TRUE,
    },

    [MOVE_NATURE_POWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Natur-Kraft"),
#else
        .name = COMPOUND_STRING("NATURE POWER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Elementklasse des\n"
            "Angriffs hängt vom Ort ab."),
#else
            "The type of attack varies\n"
            "depending on the location."),
#endif
        .effect = EFFECT_NATURE_POWER,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = B_UPDATED_MOVE_FLAGS >= GEN_6 ? TARGET_SELECTED : TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NaturePower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CHARGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ladevorgang"),
#else
        .name = COMPOUND_STRING("CHARGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lädt Energie für den kom-\n"
            "menden Elektro-Angr. auf."),
#else
            "Charges power to boost the\n"
            "Electric move used next."),
#endif
        .effect = EFFECT_CHARGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CHARGE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Charge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAUNT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Verhöhner"),
#else
        .name = COMPOUND_STRING("TAUNT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Legt den Gegner rein. Er\n"
            "benutzt nur noch Angriffe."),
#else
            "Taunts the foe into only\n"
            "using attack moves."),
#endif
        .effect = EFFECT_TAUNT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_4,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION : CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TAUNT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Taunt,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HELPING_HAND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rechte Hand"),
#else
        .name = COMPOUND_STRING("HELPING HAND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Steigert die Kraft der An-\n"
            "griffe des Getroffenen."),
#else
            "Boosts the power of ally\n"
            "recipient's moves."),
#endif
        .effect = EFFECT_HELPING_HAND,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = B_UPDATED_MOVE_DATA >= GEN_4 ? TARGET_ALLY : TARGET_USER,
        .priority = 5,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HelpingHand,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TRICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Trickbetrug"),
#else
        .name = COMPOUND_STRING("TRICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Betrügt beim Handel\n"
            "mit Gegenständen."),
#else
            "Tricks the foe into trading\n"
            "held items."),
#endif
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Trick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROLE_PLAY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rollentausch"),
#else
        .name = COMPOUND_STRING("ROLE PLAY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Parodiert Gegner u. kopiert\n"
            "seine Spezialfähigkeiten."),
#else
            "Mimics the target and\n"
            "copies its Ability."),
#endif
        .effect = EFFECT_ROLE_PLAY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RolePlay,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WISH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wunschtraum"),
#else
        .name = COMPOUND_STRING("WISH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Wunsch, der KP auffüllt.\n"
            "Die Erfüllung braucht Zeit."),
#else
            "A wish that restores HP.\n"
            "It takes time to work."),
#endif
        .effect = EFFECT_WISH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .healingMove = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_WISH,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Wish,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ASSIST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zuschuss"),
#else
        .name = COMPOUND_STRING("ASSIST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift zufällig mit einem\n"
            "Angriff d. Partners an."),
#else
            "Attacks randomly with one\n"
            "of the partner's moves."),
#endif
        .effect = EFFECT_ASSIST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Assist,
        .validApprenticeMove = TRUE,
    },

    [MOVE_INGRAIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Verwurzler"),
#else
        .name = COMPOUND_STRING("INGRAIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verwurzelung füllt KP auf.\n"
            "Austausch unmöglich."),
#else
            "Lays roots that restore HP.\n"
            "The user can't switch out."),
#endif
        .effect = EFFECT_INGRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Ingrain,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SUPERPOWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kraftkoloss"),
#else
        .name = COMPOUND_STRING("SUPERPOWER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Steigert Stärke deutlich,\n"
            "senkt aber Status-Werte."),
#else
            "Boosts strength sharply,\n"
            "but lowers abilities."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_DEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_Superpower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MAGIC_COAT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Magiemantel"),
#else
        .name = COMPOUND_STRING("MAGIC COAT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gibt Spezialeffekte zurück\n"
            "an Benutzer."),
#else
            "Reflects special effects\n"
            "back to the attacker."),
#endif
        .effect = EFFECT_MAGIC_COAT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_DEPENDS,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagicCoat,
        .validApprenticeMove = TRUE,
    },

    [MOVE_RECYCLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aufbereitung"),
#else
        .name = COMPOUND_STRING("RECYCLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Recycling eines\n"
            "verwendeten Items."),
#else
            "Recycles a used item for\n"
            "one more use."),
#endif
        .effect = EFFECT_RECYCLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Recycle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REVENGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Vergeltung"),
#else
        .name = COMPOUND_STRING("REVENGE"),
#endif
        .description = sRevengeDescription,
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -4,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_REVENGE,
        .contestComboMoves = {COMBO_STARTER_PAYBACK},
        .battleAnimScript = gBattleAnimMove_Revenge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BRICK_BREAK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Durchbruch"),
#else
        .name = COMPOUND_STRING("BRICK BREAK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Durchbricht Barrieren und\n"
            "verursacht Schaden."),
#else
            "Destroys barriers such as\n"
            "REFLECT and causes damage."),
#endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BREAK_SCREEN,
            .preAttackEffect = TRUE,
        }),
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_BrickBreak,
        .validApprenticeMove = TRUE,
    },

    [MOVE_YAWN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gähner"),
#else
        .name = COMPOUND_STRING("YAWN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gegner gähnt und schläft\n"
            "in der nächsten Runde ein."),
#else
            "Lulls the foe into yawning,\n"
            "then sleeping next turn."),
#endif
        .effect = EFFECT_YAWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_YAWN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Yawn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_KNOCK_OFF] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Abschlag"),
#else
        .name = COMPOUND_STRING("KNOCK OFF"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlägt Gegner Item weg.\n"
            "Vereitelt so den Gebrauch."),
#else
            "Knocks down the foe's held\n"
            "item to prevent its use."),
#endif
        .effect = EFFECT_KNOCK_OFF,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MON : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT},
        .battleAnimScript = gBattleAnimMove_KnockOff,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ENDEAVOR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Notsituation"),
#else
        .name = COMPOUND_STRING("ENDEAVOR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wird stärker, wenn Anw.-KP\n"
            "geringer als Gegner-KP ist."),
#else
            "Cuts foe's HP to equal\n"
            "user's HP."),
#endif
        .effect = EFFECT_ENDEAVOR,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
        .battleAnimScript = gBattleAnimMove_Endeavor,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ERUPTION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eruption"),
#else
        .name = COMPOUND_STRING("ERUPTION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je höher KP des Benutzers,\n"
            "desto mehr Schaden."),
#else
            "The higher the user's HP,\n"
            "the more damage caused."),
#endif
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_EARTHQUAKE, COMBO_STARTER_ENDURE, COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Eruption,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKILL_SWAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wertewechsel"),
#else
        .name = COMPOUND_STRING("SKILL SWAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anw. tauscht Spezial-\n"
            "fähigkeit mit Pokémon."),
#else
            "The user swaps special\n"
            "abilities with the target."),
#endif
        .effect = EFFECT_SKILL_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkillSwap,
        .validApprenticeMove = TRUE,
    },

    [MOVE_IMPRISON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Begrenzer"),
#else
        .name = COMPOUND_STRING("IMPRISON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hindert Gegner an Atta-\n"
            "cken, die d. Benutzer kennt."),
#else
            "Prevents foes from using\n"
            "moves known by the user."),
#endif
        .effect = EFFECT_IMPRISON,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .forcePressure = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_DONT_EXCITE_AUDIENCE : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Imprison,
        .validApprenticeMove = TRUE,
    },

    [MOVE_REFRESH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Heilung"),
#else
        .name = COMPOUND_STRING("REFRESH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kuriert Vergiftungen, Para-\n"
            "lyse und Verbrennung."),
#else
            "Heals poisoning, paralysis,\n"
            "or a burn."),
#endif
        .effect = EFFECT_REFRESH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SING, COMBO_STARTER_WATER_SPORT},
        .battleAnimScript = gBattleAnimMove_Refresh,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GRUDGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nachspiel"),
#else
        .name = COMPOUND_STRING("GRUDGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wenn Anw. bes., werden AP\n"
            "der Finalattacke gelöscht."),
#else
            "If the user faints, deletes\n"
            "all PP of foe's last move."),
#endif
        .effect = EFFECT_GRUDGE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_FOLLOW_ME },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_Grudge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SNATCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Übernahme"),
#else
        .name = COMPOUND_STRING("SNATCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Immunität geg. den Effekt\n"
            "d. nächsten gegn. Angriffs."),
#else
            "Steals the effects of the\n"
            "move the target uses next."),
#endif
        .effect = EFFECT_SNATCH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .ignoresSubstitute = TRUE,
        .forcePressure = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Snatch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SECRET_POWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Geheimpower"),
#else
        .name = COMPOUND_STRING("SECRET POWER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff, dessen Auswirkung\n"
            "abhängig vom Ort ist."),
#else
            "Attack with effects\n"
            "that vary by location."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SECRET_POWER,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SecretPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DIVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Taucher"),
#else
        .name = COMPOUND_STRING("DIVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Taucht in der 1. Runde\n"
            "unter u. trifft in der 2."),
#else
            "Dives underwater the first\n"
            "turn and strikes next turn."),
#endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 80 : 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .skyBattleBanned = TRUE,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNHIDUNDERWATER, .status = STATE_UNDERWATER },
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_DIVE,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SURF},
        .battleAnimScript = gBattleAnimMove_Dive,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ARM_THRUST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Armstoß"),
#else
        .name = COMPOUND_STRING("ARM THRUST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schläge mit geradem Arm, die\n"
            "Gegner 2 - 5-mal treffen."),
#else
            "Straight-arm punches that\n"
            "strike the foe 2 to 5 times."),
#endif
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_ArmThrust,
    },

    [MOVE_CAMOUFLAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tarnung"),
#else
        .name = COMPOUND_STRING("CAMOUFLAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Elementklasse des\n"
            "Pokémon hängt vom Ort ab."),
#else
            "Alters the Pokémon's type\n"
            "depending on the location."),
#endif
        .effect = EFFECT_CAMOUFLAGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Camouflage,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TAIL_GLOW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schweifglanz"),
#else
        .name = COMPOUND_STRING("TAIL GLOW"),
#endif
#if GERMAN
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_5
            "Ein blinkendes Licht. SPEZ.\n"
            "ANGR. steigt drastisch."),
        #else
            "Ein blinkendes Licht. SPEZ.\n"
            "ANGR. wird deutlich erhöht."),
        #endif
#else
        .description = COMPOUND_STRING(
        #if B_UPDATED_MOVE_DATA >= GEN_5
            "Flash light that drastically\n"
        #else
            "Flashes a light that sharply\n"
        #endif
            "raises Sp. Atk."),
#endif
        .effect = B_UPDATED_MOVE_DATA >= GEN_5 ? EFFECT_SPECIAL_ATTACK_UP_3 : EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TailGlow,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LUSTER_PURGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Scheinwerfer"),
#else
        .name = COMPOUND_STRING("LUSTER PURGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit grellem Licht.\n"
            "Senkt evtl. SPEZ. VERT."),
#else
            "Attacks with a burst of\n"
            "light. May lower Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = (B_UPDATED_MOVE_DATA >= GEN_9) ? 95 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_LusterPurge,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MIST_BALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nebelball"),
#else
        .name = COMPOUND_STRING("MIST BALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff m. Daunengestöber,\n"
            "senkt evtl. SPEZ. ANGR."),
#else
            "Attacks with a flurry of\n"
            "down. May lower Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = (B_UPDATED_MOVE_DATA >= GEN_9) ? 95 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_MistBall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FEATHER_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Daunenreigen"),
#else
        .name = COMPOUND_STRING("FEATHER DANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hüllt Gegner in Daunen und\n"
            "senkt ANGR.-Wert deutlich."),
#else
            "Envelops the foe with down\n"
            "to sharply reduce Attack."),
#endif
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FeatherDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TEETER_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Taumeltanz"),
#else
        .name = COMPOUND_STRING("TEETER DANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verwirrt alle Pokémon im \n"
            "Kampf."),
#else
            "Confuses all Pokémon on\n"
            "the scene."),
#endif
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .danceMove = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_4,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TeeterDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLAZE_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feuerfeger"),
#else
        .name = COMPOUND_STRING("BLAZE KICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hohe Volltrefferquote. Ver-\n"
            "ursacht evtl. Verbrennung."),
#else
            "A kick with a high critical-\n"
            "hit ratio. May cause a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_BlazeKick,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUD_SPORT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lehmsuhler"),
#else
        .name = COMPOUND_STRING("MUD SPORT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bedeckt Anw. mit Lehm u. er-\n"
            "höht Schutz geg. Elek.-Att."),
#else
            "Covers the user in mud to\n"
            "weaken all Electric moves."),
#endif
        // in theory this should mention 5 turns (gen 6+)
        .effect = EFFECT_MUD_SPORT,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_MUD_SPORT,
        .contestComboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM, COMBO_STARTER_WATER_SPORT},
        .battleAnimScript = gBattleAnimMove_MudSport,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICE_BALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Frostbeule"),
#else
        .name = COMPOUND_STRING("ICE BALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff für 5 Runden. \n"
            "Stärker, wenn Treffer."),
#else
            "A 5-turn attack that gains\n"
            "power on successive hits."),
#endif
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ballisticMove = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_DEFENSE_CURL},
        .battleAnimScript = gBattleAnimMove_IceBall,
    },

    [MOVE_NEEDLE_ARM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nietenranke"),
#else
        .name = COMPOUND_STRING("NEEDLE ARM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit dornigen Armen. \n"
            "Geg. schreckt evtl. zurück."),
#else
            "Attacks with thorny arms.\n"
            "May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NeedleArm,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SLACK_OFF] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tagedieb"),
#else
        .name = COMPOUND_STRING("SLACK OFF"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Durch Müßiggang wird die\n"
            "Hälfte d. max. KP aufgefüllt."),
#else
            "Slacks off and restores\n"
            "half the maximum HP."),
#endif
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SlackOff,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYPER_VOICE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schallwelle"),
#else
        .name = COMPOUND_STRING("HYPER VOICE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Laute Attacke mit Schall-\n"
            "wellen."),
#else
            "A loud attack that uses\n"
            "sound waves to injure."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HyperVoice,
        .validApprenticeMove = TRUE,
    },

    [MOVE_POISON_FANG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftzahn"),
#else
        .name = COMPOUND_STRING("POISON FANG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit Reißzähnen. \n"
            "Gegner wird evtl. vergiftet."),
#else
            "A sharp-fanged attack.\n"
            "May badly poison the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TOXIC,
            .chance = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonFang,
    },

    [MOVE_CRUSH_CLAW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zermalmklaue"),
#else
        .name = COMPOUND_STRING("CRUSH CLAW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit scharfen Klau-\n"
            "en. Senkt evtl. VERT.-Wert."),
#else
            "Tears at the foe with sharp\n"
            "claws. May lower Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_CrushClaw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLAST_BURN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lohekanonade"),
#else
        .name = COMPOUND_STRING("BLAST BURN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Starker Angriff. Angreifer\n"
            "muss eine Runde aussetzen."),
#else
            "Powerful, but leaves the\n"
            "user immobile the next turn."),
#endif
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_BlastBurn,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HYDRO_CANNON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aquahaubitze"),
#else
        .name = COMPOUND_STRING("HYDRO CANNON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Starker Angriff. Angreifer\n"
            "muss eine Runde aussetzen."),
#else
            "Powerful, but leaves the\n"
            "user immobile the next turn."),
#endif
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_HydroCannon,
        .validApprenticeMove = TRUE,
    },

    [MOVE_METEOR_MASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sternenhieb"),
#else
        .name = COMPOUND_STRING("METEOR MASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Schlag wie ein Meteor.\n"
            "Erhöht evtl. ANGR.-Wert."),
#else
            "Fires a meteor-like punch.\n"
            "May raise Attack."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 100,
        .type = TYPE_STEEL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeteorMash,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ASTONISH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Erstauner"),
#else
        .name = COMPOUND_STRING("ASTONISH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff, der Gegner evtl.\n"
            "zurückschrecken lässt."),
#else
            "Attack that may shock\n"
            "the foe into flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Astonish,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WEATHER_BALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Meteorologe"),
#else
        .name = COMPOUND_STRING("WEATHER BALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Elementkl. u. Stärke der At-\n"
            "tacke sind wetterabhängig."),
#else
            "The move's type and power\n"
            "change with the weather."),
#endif
        .effect = EFFECT_WEATHER_BALL,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 160 },
        .ballisticMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SANDSTORM, COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_WeatherBall,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AROMATHERAPY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aromakur"),
#else
        .name = COMPOUND_STRING("AROMATHERAPY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt alle Status-Probleme\n"
            "mit beruhigendem Duft."),
#else
            "Heals all status problems\n"
            "with a soothing scent."),
#endif
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS < GEN_6,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE : CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Aromatherapy,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FAKE_TEARS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Trugträne"),
#else
        .name = COMPOUND_STRING("FAKE TEARS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Täuscht Weinen vor, um\n"
            "gegn. SPEZ. VERT. zu senken."),
#else
            "Feigns crying to sharply\n"
            "lower the foe's Sp. Def."),
#endif
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUICKLY_GROW_BORED :
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FakeTears,
        .validApprenticeMove = TRUE,
    },

    [MOVE_AIR_CUTTER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Windschnitt"),
#else
        .name = COMPOUND_STRING("AIR CUTTER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift mit heftigem Wind an.\n"
            "Hohe Volltrefferquote."),
#else
            "Hacks with razorlike wind.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 55,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AirCutter,
        .validApprenticeMove = TRUE,
    },

    [MOVE_OVERHEAT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hitzekoller"),
#else
        .name = COMPOUND_STRING("OVERHEAT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit voller Kraft.\n"
            "SPEZ. ANGR. sinkt deutlich."),
#else
            "Allows a full-power attack,\n"
            "but sharply lowers Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = B_UPDATED_MOVE_DATA < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_Overheat,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ODOR_SLEUTH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schnüffler"),
#else
        .name = COMPOUND_STRING("ODOR SLEUTH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hindert Gegner daran, ihren\n"
            "Fluchtwert zu erhöhen."),
#else
            "Negate evasiveness and\n"
            "Ghost type's immunities."),
#endif
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OdorSleuth,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_TOMB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Felsgrab"),
#else
        .name = COMPOUND_STRING("ROCK TOMB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hält den Feind mit Steinen\n"
            "auf u. senkt INIT.-Wert."),
#else
            "Stops the foe from moving\n"
            "with rocks and cuts Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 50,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROCK_THROW},
        .battleAnimScript = gBattleAnimMove_RockTomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SILVER_WIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Silberhauch"),
#else
        .name = COMPOUND_STRING("SILVER WIND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Pulver-Attacke, die evtl.\n"
            "die Werte erhöht."),
#else
            "A powdery attack that may\n"
            "raise abilities."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SilverWind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_METAL_SOUND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Metallsound"),
#else
        .name = COMPOUND_STRING("METAL SOUND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stößt einen spitzen Schrei\n"
            "aus. Senkt SPEZ. VERT."),
#else
            "Emits a horrible screech\n"
            "that sharply lowers Sp. Def."),
#endif
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_METAL_SOUND,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MetalSound,
        .validApprenticeMove = TRUE,
    },

    [MOVE_GRASS_WHISTLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Grasflöte"),
#else
        .name = COMPOUND_STRING("GRASS WHISTLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Versetzt Gegner mit schö-\n"
            "ner Melodie in den Schlaf."),
#else
            "Lulls the foe into sleep\n"
            "with a pleasant melody."),
#endif
        .effect = EFFECT_NON_VOLATILE_STATUS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 55,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_AVOID_STARTLE_ONCE : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_GRASS_WHISTLE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassWhistle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_TICKLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Spaßkanone"),
#else
        .name = COMPOUND_STRING("TICKLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bringt Gegner zum Lachen.\n"
            "ANGR. u. VERT. sinken."),
#else
            "Makes the foe laugh to\n"
            "lower Attack and Defense."),
#endif
        .effect = EFFECT_TICKLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS < GEN_4,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Tickle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COSMIC_POWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kosmik-Kraft"),
#else
        .name = COMPOUND_STRING("COSMIC POWER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht VERT. u. SPEZ. VERT.\n"
            "durch mystische Kraft."),
#else
            "Raises Defense and Sp. Def\n"
            "with a mystic power."),
#endif
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CosmicPower,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_SPOUT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fontränen"),
#else
        .name = COMPOUND_STRING("WATER SPOUT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ist wirkungsvoller, wenn KP\n"
            "des Benutzers hoch sind."),
#else
            "Inflicts more damage if the\n"
            "user's HP is high."),
#endif
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_WaterSpout,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SIGNAL_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ampelleuchte"),
#else
        .name = COMPOUND_STRING("SIGNAL BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Seltsame Strahlenattacke.\n"
            "Verwirrt evtl. den Gegner."),
#else
            "A strange beam attack that\n"
            "may confuse the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SignalBeam,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHADOW_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Finsterfaust"),
#else
        .name = COMPOUND_STRING("SHADOW PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schattenhieb. Ausweichen\n"
            "unmöglich."),
#else
            "An unavoidable punch that\n"
            "is thrown from shadows."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowPunch,
        .validApprenticeMove = TRUE,
    },

    [MOVE_EXTRASENSORY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sondersensor"),
#else
        .name = COMPOUND_STRING("EXTRASENSORY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Besonderer Angriff. Gegner\n"
            "schreckt evtl. zurück."),
#else
            "Attacks with a peculiar\n"
            "power. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL : CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Extrasensory,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SKY_UPPERCUT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Himmelhieb"),
#else
        .name = COMPOUND_STRING("SKY UPPERCUT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kinnhaken, als würde man in\n"
            "die Luft springen."),
#else
            "An uppercut thrown as if\n"
            "leaping into the sky."),
#endif
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .damagesAirborne = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_SkyUppercut,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SAND_TOMB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sandgrab"),
#else
        .name = COMPOUND_STRING("SAND TOMB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fängt den Gegner im\n"
            "Treibsand, "BINDING_TURNS" Rd."),
#else
            "Traps and hurts the foe in\n"
            "quicksand for "BINDING_TURNS" turns."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_GROUND,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_SAND_TOMB,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_SandTomb,
        .validApprenticeMove = TRUE,
    },

    [MOVE_SHEER_COLD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eiseskälte"),
#else
        .name = COMPOUND_STRING("SHEER COLD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eis-Attacke. Besiegt den\n"
            "Gegner, wenn sie trifft."),
#else
            "A chilling attack that\n"
            "causes fainting if it hits."),
#endif
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 30,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .noAffectOnSameTypeTarget = B_SHEER_COLD_IMMUNITY >= GEN_7,
        .accIncreaseByTenOnSameType = B_SHEER_COLD_ACC >= GEN_7,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_SheerCold,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUDDY_WATER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lehmbrühe"),
#else
        .name = COMPOUND_STRING("MUDDY WATER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift mit Matsch an und\n"
            "senkt evtl. Genauigkeit."),
#else
            "Attacks with muddy water.\n"
            "May lower accuracy."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_STARTLE_PREV_MONS : CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_MuddyWater,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BULLET_SEED] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kugelsaat"),
#else
        .name = COMPOUND_STRING("BULLET SEED"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verschießt 2 bis 5 Samen\n"
            "gleichzeitig auf Gegner."),
#else
            "Shoots 2 to 5 seeds in a row\n"
            "to strike the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 25 : 10,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_BulletSeed,
    },

    [MOVE_AERIAL_ACE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aero-Ass"),
#else
        .name = COMPOUND_STRING("AERIAL ACE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine extrem schnelle und\n"
            "unausweichbare Attacke."),
#else
            "An extremely speedy and\n"
            "unavoidable attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AerialAce,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ICICLE_SPEAR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eisspeer"),
#else
        .name = COMPOUND_STRING("ICICLE SPEAR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Feuert 2-5 Eiszapfen auf\n"
            "den Gegner."),
#else
            "Attacks the foe by firing\n"
            "2 to 5 icicles in a row."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 25 : 10,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IcicleSpear,
    },

    [MOVE_IRON_DEFENSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eisenabwehr"),
#else
        .name = COMPOUND_STRING("IRON DEFENSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt den Körper.\n"
            "Erhöht VERT.-Wert deutlich."),
#else
            "Hardens the body's surface\n"
            "to sharply raise Defense."),
#endif
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IronDefense,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BLOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rückentzug"),
#else
        .name = COMPOUND_STRING("BLOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Versperrt den Fluchtweg\n"
            "des Gegners."),
#else
            "Blocks the foe's way and\n"
            "prevents escape."),
#endif
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BLOCK,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Block,
        .validApprenticeMove = TRUE,
    },

    [MOVE_HOWL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Jauler"),
#else
        .name = COMPOUND_STRING("HOWL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Jault, um in sich zu gehen.\n"
            "Erhöht ANGR.-Wert."),
#else
            "Howls to raise the spirit\n"
            "and boosts Attack."),
#endif
        .power = 0,
        .effect = EFFECT_ATTACK_UP,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_8 ? TARGET_USER_AND_ALLY: TARGET_USER ,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BETTER_IF_LAST : CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Howl,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DRAGON_CLAW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drachenklaue"),
#else
        .name = COMPOUND_STRING("DRAGON CLAW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Gegner wird mit\n"
            "scharfen Klauen verletzt."),
#else
            "Slashes the foe with sharp\n"
            "claws."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonClaw,
        .validApprenticeMove = TRUE,
    },

    [MOVE_FRENZY_PLANT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fauna-Statue"),
#else
        .name = COMPOUND_STRING("FRENZY PLANT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Starker Angriff. Angreifer\n"
            "muss eine Runde aussetzen."),
#else
            "Powerful, but leaves the\n"
            "user immobile the next turn."),
#endif
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_FrenzyPlant,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BULK_UP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Protzer"),
#else
        .name = COMPOUND_STRING("BULK UP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Pumpt den Körper auf. ANGR.\n"
            "u. VERT. werden erhöht."),
#else
            "Bulks up the body to boost\n"
            "both Attack and Defense."),
#endif
        .effect = EFFECT_BULK_UP,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BulkUp,
        .validApprenticeMove = TRUE,
    },

    [MOVE_BOUNCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sprungfeder"),
#else
        .name = COMPOUND_STRING("BOUNCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Springt hoch u. landet in\n"
            "nächstem Zug. Evtl. Para."),
#else
            "Bounces up, then down the\n"
            "next turn. May paralyze."),
#endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 85,
        .type = TYPE_FLYING,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId =  STRINGID_PKMNSPRANGUP, .status = STATE_ON_AIR },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Bounce,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MUD_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lehmschuss"),
#else
        .name = COMPOUND_STRING("MUD SHOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bewirft den Gegner mit Lehm\n"
            "und senkt INIT.-Wert."),
#else
            "Hurls mud at the foe and\n"
            "reduces Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_HIGHLY_APPEALING : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_MudShot,
    },

    [MOVE_POISON_TAIL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftschweif"),
#else
        .name = COMPOUND_STRING("POISON TAIL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hohe Volltrefferquote.\n"
            "Gegner evtl. vergiftet."),
#else
            "Has a high critical-hit\n"
            "ratio. May also poison."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_PoisonTail,
        .validApprenticeMove = TRUE,
    },

    [MOVE_COVET] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bezirzer"),
#else
        .name = COMPOUND_STRING("COVET"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bittet charmant um das ge-\n"
            "haltene Item des Gegners."),
#else
            "Cutely begs to obtain an\n"
            "item held by the foe."),
#endif
        .effect = EFFECT_STEAL_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 60 : 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_COVET,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Covet,
        .validApprenticeMove = TRUE,
    },

    [MOVE_VOLT_TACKLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Volttackle"),
#else
        .name = COMPOUND_STRING("VOLT TACKLE"),
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_4
        .description = COMPOUND_STRING(
#if GERMAN
            "Riskanter Tackle. Verletzt\n"
            "Anw., paralysiert evtl."),
#else
            "A life-risking tackle that\n"
            "hurts the user. May paralyze."),
#endif
        #else
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein riskanter Tackle, der\n"
            "leicht verletzt."),
#else
            "A life-risking tackle that\n"
            "slightly hurts the user."),
#endif
        #endif
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_PARALYSIS,
                .chance = 10,
            }),
        #endif
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_VoltTackle,
        .validApprenticeMove = TRUE,
    },

    [MOVE_MAGICAL_LEAF] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zauberblatt"),
#else
        .name = COMPOUND_STRING("MAGICAL LEAF"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Magischer Blattangriff.\n"
            "Ausweichen unmöglich."),
#else
            "Attacks with a strange leaf\n"
            "that cannot be evaded."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_MagicalLeaf,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_SPORT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nassmacher"),
#else
        .name = COMPOUND_STRING("WATER SPORT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Benutzer wird nass, so dass\n"
            "er Feuer besser standhält."),
#else
            "The user becomes soaked to\n"
            "weaken all Fire moves."),
#endif
        // in theory this should mention 5 turns (gen6+)
        .effect = EFFECT_WATER_SPORT,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_WATER_SPORT,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_WaterSport,
        .validApprenticeMove = TRUE,
    },

    [MOVE_CALM_MIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gedankengut"),
#else
        .name = COMPOUND_STRING("CALM MIND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht SPEZ. ANGR. u. SPEZ.\n"
            "VERT. durch Konzentration."),
#else
            "Raises Sp. Atk and Sp. Def\n"
            "by focusing the mind."),
#endif
        .effect = EFFECT_CALM_MIND,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS : CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CALM_MIND,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CalmMind,
        .validApprenticeMove = TRUE,
    },

    [MOVE_LEAF_BLADE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Laubklinge"),
#else
        .name = COMPOUND_STRING("LEAF BLADE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hieb mit scharfkantigem\n"
            "Blatt. Hohe Volltrefferqu."),
#else
            "Slashes with a sharp leaf.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 90 : 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeafBlade,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DRAGON_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drachentanz"),
#else
        .name = COMPOUND_STRING("DRAGON DANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein mystischer Tanz, der\n"
            "ANGR.- u. INIT.-Wert erhöht."),
#else
            "A mystical dance that ups\n"
            "Attack and Speed."),
#endif
        .effect = EFFECT_DRAGON_DANCE,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_DANCE,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonDance,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROCK_BLAST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Felswurf"),
#else
        .name = COMPOUND_STRING("ROCK BLAST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirft 2 - 5-mal in Folge\n"
            "Felsblöcke auf den Gegner."),
#else
            "Hurls boulders at the foe\n"
            "2 to 5 times in a row."),
#endif
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 80,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .ballisticMove = B_UPDATED_MOVE_FLAGS >= GEN_7,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING : CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockBlast,
    },

    [MOVE_SHOCK_WAVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schockwelle"),
#else
        .name = COMPOUND_STRING("SHOCK WAVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schnelle Elektro-Attacke\n"
            "mit Treffergarantie."),
#else
            "A fast and unavoidable\n"
            "electric attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ShockWave,
        .validApprenticeMove = TRUE,
    },

    [MOVE_WATER_PULSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aquawelle"),
#else
        .name = COMPOUND_STRING("WATER PULSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ultraschallwellen, die den\n"
            "Gegner verwirren können."),
#else
            "Attacks with ultrasonic\n"
            "waves. May confuse the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION : CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_WaterPulse,
        .validApprenticeMove = TRUE,
    },

    [MOVE_DOOM_DESIRE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kismetwunsch"),
#else
        .name = COMPOUND_STRING("DOOM DESIRE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Speichert Sonnenenergie.\n"
            "Angriff 2 Runden später."),
#else
            "Summons strong light to\n"
            "attack 2 turns later."),
#endif
        .effect = EFFECT_FUTURE_SIGHT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 140 : 120,
        .type = TYPE_STEEL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST :
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoomDesire,
        .validApprenticeMove = TRUE,
    },

    [MOVE_PSYCHO_BOOST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psyschub"),
#else
        .name = COMPOUND_STRING("PSYCHO BOOST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit voller Kraft.\n"
            "SPEZ. ANGR. sinkt deutlich."),
#else
            "Allows a full-power attack,\n"
            "but sharply lowers Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
        .battleAnimScript = gBattleAnimMove_PsychoBoost,
        .validApprenticeMove = TRUE,
    },

    [MOVE_ROOST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ruheort"),
#else
        .name = COMPOUND_STRING("ROOST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender landet und ruht\n"
            "sich aus. Füllt halbe KP auf."),
#else
            "Restores the user's HP by\n"
            "half of its max HP."),
#endif
        .effect = EFFECT_ROOST,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_BRAVE_BIRD},
        .battleAnimScript = gBattleAnimMove_Roost,
    },

    [MOVE_GRAVITY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Erdanziehung"),
#else
        .name = COMPOUND_STRING("GRAVITY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Gravitation steigt fünf\n"
            "Runden. Fliegen unmöglich."),
#else
            "Gravity is intensified\n"
            "negating levitation."),
#endif
        .effect = EFFECT_GRAVITY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Gravity,
    },

    [MOVE_MIRACLE_EYE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wunderauge"),
#else
        .name = COMPOUND_STRING("MIRACLE EYE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Unlicht-Pkmn sind angreifba-\n"
            "r. Trifft trotz Ausweichen."),
#else
            "Negate evasiveness and\n"
            "Dark type's immunities."),
#endif
        .effect = EFFECT_MIRACLE_EYE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MiracleEye,
    },

    [MOVE_WAKE_UP_SLAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Weckruf"),
#else
        .name = COMPOUND_STRING("WAKE-UP SLAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Großer Schaden bei Schlaf,\n"
            "weckt den Gegner aber auf."),
#else
            "Powerful against sleeping\n"
            "foes, but also wakes them."),
#endif
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 70 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .status = STATUS1_SLEEP },
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
        }),
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER},
        .battleAnimScript = gBattleAnimMove_WakeUpSlap,
    },

    [MOVE_HAMMER_ARM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hammerarm"),
#else
        .name = COMPOUND_STRING("HAMMER ARM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender trifft mit starkem\n"
            "Hieb. Senkt eigene Init."),
#else
            "A swinging fist attack\n"
            "that also lowers Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_HammerArm,
    },

    [MOVE_GYRO_BALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gyroball"),
#else
        .name = COMPOUND_STRING("GYRO BALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit Tempo. Je langsa-\n"
            "mer, desto mehr Schaden."),
#else
            "A high-speed spin that does\n"
            "more damage to faster foes."),
#endif
        .effect = EFFECT_GYRO_BALL,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GyroBall,
    },

    [MOVE_HEALING_WISH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Heilopfer"),
#else
        .name = COMPOUND_STRING("HEALING WISH"),
#endif
        .description = sHealingWishDescription,
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .healingMove = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HealingWish,
    },

    [MOVE_BRINE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lake"),
#else
        .name = COMPOUND_STRING("BRINE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hat der Gegner höchstens\n"
            "halbe KP, trifft sie doppelt."),
#else
            "Does double damage to foes\n"
            "with half HP or less."),
#endif
        .effect = EFFECT_BRINE,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Brine,
    },

    [MOVE_NATURAL_GIFT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Beerenkräfte"),
#else
        .name = COMPOUND_STRING("NATURAL GIFT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die getragene Beere bestimmt\n"
            "Typ und Stärke der Attacke."),
#else
            "The effectiveness varies\n"
            "with the held Berry."),
#endif
        .effect = EFFECT_NATURAL_GIFT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NaturalGift,
    },

    [MOVE_FEINT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Offenlegung"),
#else
        .name = COMPOUND_STRING("FEINT"),
#endif
        .description = sFeintDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 30 : 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_6,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Feint,
    },

    [MOVE_PLUCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pflücker"),
#else
        .name = COMPOUND_STRING("PLUCK"),
#endif
        .description = sPluckDescription,
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BUG_BITE,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Pluck,
    },

    [MOVE_TAILWIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rückenwind"),
#else
        .name = COMPOUND_STRING("TAILWIND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt eine Böe, die das\n"
#else
            "Whips up a breeze, doubling\n"
#endif
        #if B_TAILWIND_TURNS >= GEN_5
#if GERMAN
            "Tempo 4 Runden verdoppelt."),
#else
            "ally Speed for 4 turns."),
#endif
        #else
#if GERMAN
            "Tempo 3 Runden verdoppelt."),
#else
            "ally Speed for 3 turns."),
#endif
        #endif
        .effect = EFFECT_TAILWIND,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .snatchAffected = TRUE,
        .windMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Tailwind,
    },

    [MOVE_ACUPRESSURE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Akupressur"),
#else
        .name = COMPOUND_STRING("ACUPRESSURE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Druck auf Stresspunkte\n"
            "steigert einen Wert enorm."),
#else
            "The user sharply raises\n"
            "one of its stats."),
#endif
        .effect = EFFECT_ACUPRESSURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER_OR_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS < GEN_5,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Acupressure,
    },

    [MOVE_METAL_BURST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Metallstoß"),
#else
        .name = COMPOUND_STRING("METAL BURST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff gegen den Gegner, der\n"
            "zuletzt Schaden zufügte."),
#else
            "Retaliates any hit with\n"
            "greater power."),
#endif
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = {
            .reflectDamage.damagePercent = 150,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_PHYSICAL | 1u << DAMAGE_CATEGORY_SPECIAL,
        },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS < GEN_5,
        .meFirstBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_METAL_SOUND, COMBO_STARTER_ENCORE, COMBO_STARTER_TAUNT, COMBO_STARTER_TORMENT},
        .battleAnimScript = gBattleAnimMove_MetalBurst,
    },

    [MOVE_U_TURN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kehrtwende"),
#else
        .name = COMPOUND_STRING("U-TURN"),
#endif
        .description = sUTurnDescription,
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_UTurn,
    },

    [MOVE_CLOSE_COMBAT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nahkampf"),
#else
        .name = COMPOUND_STRING("CLOSE COMBAT"),
#endif
        .description = sCloseCombatDescription,
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
        .battleAnimScript = gBattleAnimMove_CloseCombat,
    },

    [MOVE_PAYBACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gegenstoß"),
#else
        .name = COMPOUND_STRING("PAYBACK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Handelt der Anwender nach\n"
            "dem Gegner, doppelte Kraft."),
#else
            "Attack that gains power\n"
            "if the user moves last."),
#endif
        .effect = EFFECT_PAYBACK,
        .power = 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_PAYBACK,
        .contestComboMoves = {COMBO_STARTER_REVENGE},
        .battleAnimScript = gBattleAnimMove_Payback,
    },

    [MOVE_ASSURANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gewissheit"),
#else
        .name = COMPOUND_STRING("ASSURANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hat der Gegner schon\n"
            "Schaden, doppelte Kraft."),
#else
            "Attack that gains power\n"
            "if the foe has been hurt."),
#endif
        .effect = EFFECT_ASSURANCE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PAYBACK, COMBO_STARTER_REVENGE},
        .battleAnimScript = gBattleAnimMove_Assurance,
    },

    [MOVE_EMBARGO] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Itemsperre"),
#else
        .name = COMPOUND_STRING("EMBARGO"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verhindert, dass Gegner oder\n"
            "Trainer Items verwenden."),
#else
            "Prevents the foe from\n"
            "using any items."),
#endif
        .effect = EFFECT_EMBARGO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Embargo,
    },

    [MOVE_FLING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schleuder"),
#else
        .name = COMPOUND_STRING("FLING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schleudert das Item. Kraft\n"
            "und Effekt hängen davon ab."),
#else
            "The effectiveness varies\n"
            "with the held item."),
#endif
        .effect = EFFECT_FLING,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CELEBRATE, COMBO_STARTER_COVET, COMBO_STARTER_HAPPY_HOUR, COMBO_STARTER_WISH},
        .battleAnimScript = gBattleAnimMove_Fling,
    },

    [MOVE_PSYCHO_SHIFT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psybann"),
#else
        .name = COMPOUND_STRING("PSYCHO SHIFT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Suggestivkräfte schieben\n"
            "Statusprobleme zum Gegner."),
#else
            "Transfers status problems\n"
            "to the foe."),
#endif
        .effect = EFFECT_PSYCHO_SHIFT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_2 },
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychoShift,
    },

    [MOVE_TRUMP_CARD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Trumpfkarte"),
#else
        .name = COMPOUND_STRING("TRUMP CARD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je weniger AP sie hat, desto\n"
            "größer ihre Angriffskraft."),
#else
            "The less PP the move has\n"
            "the more damage it does."),
#endif
        .effect = EFFECT_TRUMP_CARD,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TrumpCard,
    },

    [MOVE_HEAL_BLOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Heilblockade"),
#else
        .name = COMPOUND_STRING("HEAL BLOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verhindert fünf Runden lang\n"
            "gegnerische Heilung."),
#else
            "Prevents the foes from\n"
            "recovering HP for 5 turns."),
#endif
        .effect = EFFECT_HEAL_BLOCK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_2 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HealBlock,
    },

    [MOVE_WRING_OUT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Auswringen"),
#else
        .name = COMPOUND_STRING("WRING OUT"),
#endif
        .description = sWringOutDescription,
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WringOut,
    },

    [MOVE_POWER_TRICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Krafttrick"),
#else
        .name = COMPOUND_STRING("POWER TRICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Psycho-Kräfte tauschen ei-\n"
            "genen Angr.- und Vert.-Wert."),
#else
            "The user swaps its Attack\n"
            "and Defense stats."),
#endif
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerTrick,
    },

    [MOVE_GASTRO_ACID] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Magensäfte"),
#else
        .name = COMPOUND_STRING("GASTRO ACID"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Magensäfte entfernen die\n"
            "Effekte der gegn. Fähigkeit."),
#else
            "Stomach acid suppresses\n"
            "the foe's Ability."),
#endif
        .effect = EFFECT_GASTRO_ACID,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GastroAcid,
    },

    [MOVE_LUCKY_CHANT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Beschwörung"),
#else
        .name = COMPOUND_STRING("LUCKY CHANT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Beschwörungsformel\n"
            "verhindert gegn. Volltreffer."),
#else
            "Prevents the foe from\n"
            "landing critical hits."),
#endif
        .effect = EFFECT_LUCKY_CHANT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_LUCKY_CHANT,
        .contestComboMoves = {COMBO_STARTER_HEAL_BELL},
        .battleAnimScript = gBattleAnimMove_LuckyChant,
    },

    [MOVE_ME_FIRST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Egotrip"),
#else
        .name = COMPOUND_STRING("ME FIRST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Führt die Attacke des Geg-\n"
            "ners mit größerer Kraft aus."),
#else
            "Executes the foe's attack\n"
            "with greater power."),
#endif
        .effect = EFFECT_ME_FIRST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENT,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeFirst,
    },

    [MOVE_COPYCAT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Imitator"),
#else
        .name = COMPOUND_STRING("COPYCAT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender imitiert die zuletzt\n"
            "verwendete Attacke."),
#else
            "The user mimics the last\n"
            "move used by a foe."),
#endif
        .effect = EFFECT_COPYCAT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = (B_UPDATED_MOVE_FLAGS >= GEN_7 || B_UPDATED_MOVE_FLAGS < GEN_3),
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Copycat,
    },

    [MOVE_POWER_SWAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Krafttausch"),
#else
        .name = COMPOUND_STRING("POWER SWAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Psycho-Kräfte tauschen Än-\n"
            "derungen an Angr. und Sp.Ang."),
#else
            "Swaps changes to Attack\n"
            "and Sp. Atk with the foe."),
#endif
        .effect = EFFECT_POWER_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerSwap,
    },

    [MOVE_GUARD_SWAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schutztausch"),
#else
        .name = COMPOUND_STRING("GUARD SWAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Psycho-Kräfte tauschen Än-\n"
            "derungen an Vert. u. Sp.Vert."),
#else
            "Swaps changes to Defense\n"
            "and Sp. Def with the foe."),
#endif
        .effect = EFFECT_GUARD_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GuardSwap,
    },

    [MOVE_PUNISHMENT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Strafattacke"),
#else
        .name = COMPOUND_STRING("PUNISHMENT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je stärker der Gegner\n"
            "gesteigert, desto mehr Kraft."),
#else
            "Does more damage the more\n"
            "the foe has powered up."),
#endif
        .effect = EFFECT_PUNISHMENT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Punishment,
    },

    [MOVE_LAST_RESORT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zuflucht"),
#else
        .name = COMPOUND_STRING("LAST RESORT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erst nutzbar, wenn alle ande-\n"
            "ren Attacken benutzt wurden."),
#else
            "Can only be used if every\n"
            "other move has been used."),
#endif
        .effect = EFFECT_LAST_RESORT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 140 : 130,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LastResort,
    },

    [MOVE_WORRY_SEED] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sorgensamen"),
#else
        .name = COMPOUND_STRING("WORRY SEED"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Samen wandelt die gegn.\n"
            "Fähigkeit in Insomnia um."),
#else
            "Plants a seed on the foe\n"
            "giving it Insomnia."),
#endif
        .effect = EFFECT_OVERWRITE_ABILITY,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .overwriteAbility = ABILITY_INSOMNIA },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_WORRY_SEED,
        .contestComboMoves = {COMBO_STARTER_LEECH_SEED, COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_WorrySeed,
    },

    [MOVE_SUCKER_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tiefschlag"),
#else
        .name = COMPOUND_STRING("SUCKER PUNCH"),
#endif
        .description = sSuckerPunchDescription,
        .effect = EFFECT_SUCKER_PUNCH,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 70 : 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SuckerPunch,
    },

    [MOVE_TOXIC_SPIKES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftspitzen"),
#else
        .name = COMPOUND_STRING("TOXIC SPIKES"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Falle mit Giftdornen\n"
            "vergiftet neue Gegner."),
#else
            "Sets spikes that poison a\n"
            "foe switching in."),
#endif
        .effect = EFFECT_TOXIC_SPIKES,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .forcePressure = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TOXIC_SPIKES,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ToxicSpikes,
    },

    [MOVE_HEART_SWAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Statustausch"),
#else
        .name = COMPOUND_STRING("HEART SWAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Psycho-Kräfte tauschen alle\n"
            "Statuswertänderungen."),
#else
            "Swaps any stat changes\n"
            "with the foe."),
#endif
        .effect = EFFECT_HEART_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeartSwap,
    },

    [MOVE_AQUA_RING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wasserring"),
#else
        .name = COMPOUND_STRING("AQUA RING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Schleier aus Wasser rege-\n"
            "neriert jede Runde einige KP."),
#else
            "Forms a veil of water\n"
            "that restores HP."),
#endif
        .effect = EFFECT_AQUA_RING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AquaRing,
    },

    [MOVE_MAGNET_RISE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Magnetflug"),
#else
        .name = COMPOUND_STRING("MAGNET RISE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender schwebt fünf\n"
            "Runden durch Magnetismus."),
#else
            "The user levitates with\n"
            "electromagnetism."),
#endif
        .effect = EFFECT_MAGNET_RISE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagnetRise,
    },

    [MOVE_FLARE_BLITZ] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flammenblitz"),
#else
        .name = COMPOUND_STRING("FLARE BLITZ"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ansturm in Flammen. Der An-\n"
            "wender nimmt dabei Schaden."),
#else
            "A charge that may burn the\n"
            "foe. Also hurts the user."),
#endif
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FlareBlitz,
    },

    [MOVE_FORCE_PALM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kraftwelle"),
#else
        .name = COMPOUND_STRING("FORCE PALM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit einer Schockwel-\n"
            "le, die evtl. paralysiert."),
#else
            "A shock wave attack that\n"
            "may paralyze the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_FORCE_PALM,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ForcePalm,
    },

    [MOVE_AURA_SPHERE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aurasphäre"),
#else
        .name = COMPOUND_STRING("AURA SPHERE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Stoß Auraenergie aus dem\n"
            "Inneren. Trifft in jedem Fall."),
#else
            "Attacks with an aura blast\n"
            "that cannot be evaded."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 90,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AuraSphere,
    },

    [MOVE_ROCK_POLISH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Steinpolitur"),
#else
        .name = COMPOUND_STRING("ROCK POLISH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender senkt den Luftwi-\n"
            "derstand. Init. steigt enorm."),
#else
            "Polishes the body to\n"
            "sharply raise Speed."),
#endif
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ROCK_POLISH,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockPolish,
    },

    [MOVE_POISON_JAB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gifthieb"),
#else
        .name = COMPOUND_STRING("POISON JAB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit vergiftetem Arm.\n"
            "Vergiftet den Gegner evtl."),
#else
            "A stabbing attack that\n"
            "may poison the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PoisonJab,
    },

    [MOVE_DARK_PULSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Finsteraura"),
#else
        .name = COMPOUND_STRING("DARK PULSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Aura schlechter Gedanken.\n"
            "Schreckt evtl. zurück."),
#else
            "Attacks with a horrible\n"
            "aura. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DarkPulse,
    },

    [MOVE_NIGHT_SLASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nachthieb"),
#else
        .name = COMPOUND_STRING("NIGHT SLASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit scharfen Klauen.\n"
            "Hohe Volltrefferquote."),
#else
            "Hits as soon as possible.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_DARK,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_NightSlash,
    },

    [MOVE_AQUA_TAIL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nassschweif"),
#else
        .name = COMPOUND_STRING("AQUA TAIL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit dem Schweif wie\n"
            "eine Welle im tosenden Sturm."),
#else
            "The user swings its tail\n"
            "like a wave to attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_AquaTail,
    },

    [MOVE_SEED_BOMB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Samenbomben"),
#else
        .name = COMPOUND_STRING("SEED BOMB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lässt Samen mit harter\n"
            "Schale auf den Gegner fallen."),
#else
            "A barrage of hard seeds\n"
            "is fired at the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROTOTILLER},
        .battleAnimScript = gBattleAnimMove_SeedBomb,
    },

    [MOVE_AIR_SLASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Luftschnitt"),
#else
        .name = COMPOUND_STRING("AIR SLASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit einer Luftklinge.\n"
            "Schreckt evtl. zurück."),
#else
            "Attacks with a blade of\n"
            "air. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AirSlash,
    },

    [MOVE_X_SCISSOR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kreuzschere"),
#else
        .name = COMPOUND_STRING("X-SCISSOR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Attacke, die einer\n"
            "Scherenbewegung ähnelt."),
#else
            "Slashes the foe with crossed\n"
            "scythes, claws, etc."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
        .battleAnimScript = gBattleAnimMove_XScissor,
    },

    [MOVE_BUG_BUZZ] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Käfergebrumm"),
#else
        .name = COMPOUND_STRING("BUG BUZZ"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Schockwelle aus Flügel-\n"
            "schlägen. Senkt evtl. Sp.Vert."),
#else
            "A damaging sound wave that\n"
            "may lower Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTIFUL : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BugBuzz,
    },

    [MOVE_DRAGON_PULSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drachenpuls"),
#else
        .name = COMPOUND_STRING("DRAGON PULSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Schockwelle aus dem\n"
            "offenen Maul des Anwenders."),
#else
            "Generates a shock wave to\n"
            "damage the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 85 : 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonPulse,
    },

    [MOVE_DRAGON_RUSH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drachenstoß"),
#else
        .name = COMPOUND_STRING("DRAGON RUSH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein gefährlicher Angriff.\n"
            "Schreckt evtl. zurück."),
#else
            "Tackles the foe with menace.\n"
            "May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 75,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_RUSH,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonRush,
    },

    [MOVE_POWER_GEM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Juwelenkraft"),
#else
        .name = COMPOUND_STRING("POWER GEM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Lichtstrahl, der funkelt,\n"
            "als sei er aus Juwelen."),
#else
            "Attacks with rays of light\n"
            "that sparkle like diamonds."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 70,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerGem,
    },

    [MOVE_DRAIN_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ableithieb"),
#else
        .name = COMPOUND_STRING("DRAIN PUNCH"),
#endif
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_DrainPunch,
    },

    [MOVE_VACUUM_WAVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Vakuumwelle"),
#else
        .name = COMPOUND_STRING("VACUUM WAVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Faustwirbel sendet eine\n"
            "Vakuumwelle. Trifft zuerst."),
#else
            "Whirls its fists to send\n"
            "a wave that strikes first."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_VacuumWave,
    },

    [MOVE_FOCUS_BLAST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fokusstoß"),
#else
        .name = COMPOUND_STRING("FOCUS BLAST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender bündelt den Fokus.\n"
            "Senkt evtl. gegn. Sp.Vert."),
#else
            "Attacks at full power.\n"
            "May lower Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 70,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_FocusBlast,
    },

    [MOVE_ENERGY_BALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Energieball"),
#else
        .name = COMPOUND_STRING("ENERGY BALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Feuert Kraft aus der Natur\n"
            "ab. Senkt evtl. Sp.Vert."),
#else
            "Draws power from nature to\n"
            "attack. May lower Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_EnergyBall,
    },

    [MOVE_BRAVE_BIRD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sturzflug"),
#else
        .name = COMPOUND_STRING("BRAVE BIRD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff aus niedriger Höhe.\n"
            "Anwender erleidet Schaden."),
#else
            "A low altitude charge that\n"
            "also hurts the user."),
#endif
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BRAVE_BIRD,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BraveBird,
    },

    [MOVE_EARTH_POWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Erdkräfte"),
#else
        .name = COMPOUND_STRING("EARTH POWER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Boden erzittert. Senkt\n"
            "evtl. gegn. Sp.Vert."),
#else
            "Makes the ground erupt with\n"
            "power. May lower Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_EarthPower,
    },

    [MOVE_SWITCHEROO] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wechseldich"),
#else
        .name = COMPOUND_STRING("SWITCHEROO"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Item wird in Windeseile\n"
            "mit dem Gegner getauscht."),
#else
            "Swaps items with the foe\n"
            "faster than the eye can see."),
#endif
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Switcheroo,
    },

    [MOVE_GIGA_IMPACT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gigastoß"),
#else
        .name = COMPOUND_STRING("GIGA IMPACT"),
#endif
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GigaImpact,
    },

    [MOVE_NASTY_PLOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ränkeschmied"),
#else
        .name = COMPOUND_STRING("NASTY PLOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Finstere Gedanken steigern\n"
            "den eigenen Sp.Ang. enorm."),
#else
            "Thinks bad thoughts to\n"
            "sharply boost Sp. Atk."),
#endif
        .effect = EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_NASTY_PLOT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NastyPlot,
    },

    [MOVE_BULLET_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Patronenhieb"),
#else
        .name = COMPOUND_STRING("BULLET PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein ultraschneller Hieb. Mit\n"
            "Erstschlaggarantie."),
#else
            "Punches as fast as a bul-\n"
            "let. It always hits first."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BulletPunch,
    },

    [MOVE_AVALANCHE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lawine"),
#else
        .name = COMPOUND_STRING("AVALANCHE"),
#endif
        .description = sRevengeDescription,
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -4,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Avalanche,
    },

    [MOVE_ICE_SHARD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eissplitter"),
#else
        .name = COMPOUND_STRING("ICE SHARD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bewirft den Gegner mit\n"
            "Eisklumpen. Trifft zuerst."),
#else
            "Hurls a chunk of ice that\n"
            "always strikes first."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IceShard,
    },

    [MOVE_SHADOW_CLAW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dunkelklaue"),
#else
        .name = COMPOUND_STRING("SHADOW CLAW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Klauen aus der Schattenwelt.\n"
            "Hohe Volltrefferquote."),
#else
            "Strikes with a shadow claw.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_ShadowClaw,
    },

    [MOVE_THUNDER_FANG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Donnerzahn"),
#else
        .name = COMPOUND_STRING("THUNDER FANG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Biss mit E-Zähnen. Schreckt\n"
            "oder paralysiert evtl."),
#else
            "May cause flinching or\n"
            "leave the foe paralyzed."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_THUNDER_FANG,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_FANG, COMBO_STARTER_ICE_FANG},
        .battleAnimScript = gBattleAnimMove_ThunderFang,
    },

    [MOVE_ICE_FANG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eiszahn"),
#else
        .name = COMPOUND_STRING("ICE FANG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kann zurückschrecken lassen\n"
#else
            "May cause flinching or\n"
#endif
        #if B_USE_FROSTBITE == TRUE
#if GERMAN
            "oder Frostbeulen erzeugen."),
#else
            "leave the foe with frostbite."),
#endif
        #else
#if GERMAN
            "oder den Gegner einfrieren."),
#else
            "leave the foe frozen."),
#endif
        #endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_ICE_FANG,
        .contestComboMoves = {COMBO_STARTER_FIRE_FANG, COMBO_STARTER_THUNDER_FANG},
        .battleAnimScript = gBattleAnimMove_IceFang,
    },

    [MOVE_FIRE_FANG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feuerzahn"),
#else
        .name = COMPOUND_STRING("FIRE FANG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Biss mit Feuerzähnen.\n"
            "Schreckt o. verbrennt evtl."),
#else
            "May cause flinching or\n"
            "leave the foe with a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_FIRE_FANG,
        .contestComboMoves = {COMBO_STARTER_ICE_FANG, COMBO_STARTER_THUNDER_FANG},
        .battleAnimScript = gBattleAnimMove_FireFang,
    },

    [MOVE_SHADOW_SNEAK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schattenstoß"),
#else
        .name = COMPOUND_STRING("SHADOW SNEAK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Schatten greift von\n"
            "hinten an. Trifft zuerst."),
#else
            "Extends the user's shadow\n"
            "to strike first."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowSneak,
    },

    [MOVE_MUD_BOMB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schlammbombe"),
#else
        .name = COMPOUND_STRING("MUD BOMB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit Schlammklumpen.\n"
            "Senkt evtl. gegn. Gen."),
#else
            "Throws a blob of mud to\n"
            "damage and cut accuracy."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MudBomb,
    },

    [MOVE_PSYCHO_CUT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psychoklinge"),
#else
        .name = COMPOUND_STRING("PSYCHO CUT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Klingen aus Psycho-Energie.\n"
            "Hohe Volltrefferquote."),
#else
            "Tears with psychic blades.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychoCut,
    },

    [MOVE_ZEN_HEADBUTT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zen-Kopfstoß"),
#else
        .name = COMPOUND_STRING("ZEN HEADBUTT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender bündelt den Willen\n"
            "und rammt. Schreckt evtl."),
#else
            "Hits with a strong head-\n"
            "butt. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ZenHeadbutt,
    },

    [MOVE_MIRROR_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Spiegelsalve"),
#else
        .name = COMPOUND_STRING("MIRROR SHOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Energiestrahl aus dem\n"
            "Körper. Senkt evtl. Gen."),
#else
            "Emits a flash of energy to\n"
            "damage and cut accuracy."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MirrorShot,
    },

    [MOVE_FLASH_CANNON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lichtkanone"),
#else
        .name = COMPOUND_STRING("FLASH CANNON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gesammelte Lichtenergie.\n"
            "Senkt evtl. gegn. Sp.Vert."),
#else
            "Releases a blast of light\n"
            "that may lower Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlashCannon,
    },

    [MOVE_ROCK_CLIMB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kraxler"),
#else
        .name = COMPOUND_STRING("ROCK CLIMB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine stürmische Attacke, die\n"
            "den Gegner evtl. verwirrt."),
#else
            "A charging attack that may\n"
            "confuse the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockClimb,
    },

    [MOVE_DEFOG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Auflockern"),
#else
        .name = COMPOUND_STRING("DEFOG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt gegn. Fluchtwert. Hebt\n"
            "Stachler und Schilde auf."),
#else
            "Removes obstacles and\n"
            "lowers evasion."),
#endif
        .effect = EFFECT_DEFOG,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        //.ignoresSubstitute = TRUE, In Gen5+, the evasion drop will no longer bypass Substitute. However, this is tricky to code
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Defog,
    },

    [MOVE_TRICK_ROOM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bizarroraum"),
#else
        .name = COMPOUND_STRING("TRICK ROOM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein bizarrer Raum lässt\n"
            "Langsame zuerst agieren."),
#else
            "Slower Pokémon get to move\n"
            "first for 5 turns."),
#endif
        .effect = EFFECT_TRICK_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_FIELD,
        .priority = -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_SMART : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TrickRoom,
    },

    [MOVE_DRACO_METEOR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Draco Meteor"),
#else
        .name = COMPOUND_STRING("DRACO METEOR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Beschwört Kometen. Der Rück-\n"
            "stoß senkt den Sp.Ang. enorm."),
#else
            "Casts comets onto the foe.\n"
            "Harshly lowers the Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DracoMeteor,
    },

    [MOVE_DISCHARGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ladungsstoß"),
#else
        .name = COMPOUND_STRING("DISCHARGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Elektrizität greift alle Pkmn\n"
            "im Kampf an. Paralysiert evtl."),
#else
            "Zaps all other {PKMN} with\n"
            "electricity. May paralyze."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Discharge,
    },

    [MOVE_LAVA_PLUME] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flammensturm"),
#else
        .name = COMPOUND_STRING("LAVA PLUME"),
#endif
        .description = sLavaPlumeDescription,
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_LavaPlume,
    },

    [MOVE_LEAF_STORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blättersturm"),
#else
        .name = COMPOUND_STRING("LEAF STORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Blättersturm. Rückstoß\n"
            "senkt Sp.Ang. stark."),
#else
            "Whips up a storm of leaves.\n"
            "Harshly lowers the Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeafStorm,
    },

    [MOVE_POWER_WHIP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blattgeißel"),
#else
        .name = COMPOUND_STRING("POWER WHIP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirbelt Ranken oder Tentakel\n"
            "gegen den Gegner."),
#else
            "Violently lashes the foe\n"
            "with vines or tentacles."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_PowerWhip,
    },

    [MOVE_ROCK_WRECKER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Felswerfer"),
#else
        .name = COMPOUND_STRING("ROCK WRECKER"),
#endif
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RockWrecker,
    },

    [MOVE_CROSS_POISON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftstreich"),
#else
        .name = COMPOUND_STRING("CROSS POISON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hieb, der evtl. vergiftet.\n"
            "Hohe Volltrefferquote."),
#else
            "A slash that may poison a\n"
            "foe and do critical damage."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_POISON,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CrossPoison,
    },

    [MOVE_GUNK_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mülltreffer"),
#else
        .name = COMPOUND_STRING("GUNK SHOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schießt Müll auf den Gegner\n"
            "und vergiftet ihn evtl."),
#else
            "Shoots filthy garbage at\n"
            "the foe. May also poison."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 70,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_TOUGH : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GunkShot,
    },

    [MOVE_IRON_HEAD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eisenschädel"),
#else
        .name = COMPOUND_STRING("IRON HEAD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Treffer mit stahlhartem\n"
            "Kopf. Schreckt evtl. zurück."),
#else
            "Slams the foe with a hard\n"
            "head. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IronHead,
    },

    [MOVE_MAGNET_BOMB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Magnetbombe"),
#else
        .name = COMPOUND_STRING("MAGNET BOMB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Haftbombe trifft das\n"
            "Ziel. Sie trifft immer."),
#else
            "Launches a magnet that\n"
            "strikes without fail."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagnetBomb,
    },

    [MOVE_STONE_EDGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Steinkante"),
#else
        .name = COMPOUND_STRING("STONE EDGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sticht mit scharfen Steinen\n"
            "zu. Hohe Volltrefferquote."),
#else
            "Stabs the foe with stones.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_StoneEdge,
    },

    [MOVE_CAPTIVATE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Liebreiz"),
#else
        .name = COMPOUND_STRING("CAPTIVATE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt Sp.Ang. stark bei Geg-\n"
            "nern anderen Geschlechts."),
#else
            "Makes the opposite gender\n"
            "sharply reduce its Sp. Atk."),
#endif
        .effect = EFFECT_CAPTIVATE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
        .battleAnimScript = gBattleAnimMove_Captivate,
    },

    [MOVE_STEALTH_ROCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tarnsteine"),
#else
        .name = COMPOUND_STRING("STEALTH ROCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwebende Steine schaden\n"
            "eingreifenden Gegnern."),
#else
            "Sets floating stones that\n"
            "hurt a foe switching in."),
#endif
        .effect = EFFECT_STEALTH_ROCK,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .forcePressure = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STEALTH_ROCK},
        .battleAnimScript = gBattleAnimMove_StealthRock,
    },

    [MOVE_GRASS_KNOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Strauchler"),
#else
        .name = COMPOUND_STRING("GRASS KNOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gras bringt zu Fall. Je schwe-\n"
            "rer, desto mehr Schaden."),
#else
            "A snare attack that does\n"
            "more damage to heavier foes."),
#endif
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassKnot,
    },

    [MOVE_CHATTER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Geschwätz"),
#else
        .name = COMPOUND_STRING("CHATTER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Angriff mit Schallwellen.\n"
            "Verwirrt evtl. den Gegner."),
#else
            "Attacks with a sound wave\n"
            "that causes confusion."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_6,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .chance = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .chance = 10,
        #else
            .chance = 31,
        #endif
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Chatter,
    },

    [MOVE_JUDGMENT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Urteilskraft"),
#else
        .name = COMPOUND_STRING("JUDGMENT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Feuert Lichtstrahlen ab. Der\n"
            "Typ hängt von der Tafel ab."),
#else
            "The type varies with the\n"
            "kind of Plate held."),
#endif
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .holdEffect = HOLD_EFFECT_PLATE },
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Judgment,
    },

    [MOVE_BUG_BITE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Käferbiss"),
#else
        .name = COMPOUND_STRING("BUG BITE"),
#endif
        .description = sPluckDescription,
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BUG_BITE,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_CUTE : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BugBite,
    },

    [MOVE_CHARGE_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ladestrahl"),
#else
        .name = COMPOUND_STRING("CHARGE BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Elektrostrahl. Steigert\n"
            "evtl. eigenen Sp.Ang."),
#else
            "Fires a beam of electricity.\n"
            "May raise Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 70,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ChargeBeam,
    },

    [MOVE_WOOD_HAMMER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Holzhammer"),
#else
        .name = COMPOUND_STRING("WOOD HAMMER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit robustem Körper.\n"
            "Der Anwender nimmt Schaden."),
#else
            "Slams the body into a foe.\n"
            "The user gets hurt too."),
#endif
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WoodHammer,
    },

    [MOVE_AQUA_JET] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wasserdüse"),
#else
        .name = COMPOUND_STRING("AQUA JET"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit so hohem Tempo,\n"
            "dass er zuerst trifft."),
#else
            "Strikes first by dashing\n"
            "at the foe at a high speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_AquaJet,
    },

    [MOVE_ATTACK_ORDER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schlagbefehl"),
#else
        .name = COMPOUND_STRING("ATTACK ORDER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Untergebene greifen an. Hohe\n"
            "Volltrefferquote."),
#else
            "Underlings pummel the foe.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_ATTACK_ORDER,
        .contestComboMoves = {COMBO_STARTER_DEFEND_ORDER, COMBO_STARTER_HEAL_ORDER},
        .battleAnimScript = gBattleAnimMove_AttackOrder,
    },

    [MOVE_DEFEND_ORDER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blockbefehl"),
#else
        .name = COMPOUND_STRING("DEFEND ORDER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein lebendes Schild steigert\n"
            "Vert. und Sp.Vert."),
#else
            "Raises Defense and Sp. Def\n"
            "with a living shield."),
#endif
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_DEFEND_ORDER,
        .contestComboMoves = {COMBO_STARTER_ATTACK_ORDER, COMBO_STARTER_HEAL_ORDER},
        .battleAnimScript = gBattleAnimMove_DefendOrder,
    },

    [MOVE_HEAL_ORDER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Heilbefehl"),
#else
        .name = COMPOUND_STRING("HEAL ORDER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Untergebene heilen den\n"
            "Anwender um halbe max. KP."),
#else
            "The user's underlings show\n"
            "up to heal half its max HP."),
#endif
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HEAL_ORDER,
        .contestComboMoves = {COMBO_STARTER_ATTACK_ORDER, COMBO_STARTER_DEFEND_ORDER},
        .battleAnimScript = gBattleAnimMove_HealOrder,
    },

    [MOVE_HEAD_SMASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kopfstoß"),
#else
        .name = COMPOUND_STRING("HEAD SMASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein schwerer Kopfstoß.\n"
            "Anwender nimmt auch Schaden."),
#else
            "A life-risking headbutt that\n"
            "seriously hurts the user."),
#endif
        .effect = EFFECT_RECOIL,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 50 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeadSmash,
    },

    [MOVE_DOUBLE_HIT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Doppelschlag"),
#else
        .name = COMPOUND_STRING("DOUBLE HIT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft das Ziel mit dem\n"
            "Schweif o. Ä. gleich zweimal."),
#else
            "Slams the foe with a tail\n"
            "etc. Strikes twice."),
#endif
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleHit,
    },

    [MOVE_ROAR_OF_TIME] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zeitenlärm"),
#else
        .name = COMPOUND_STRING("ROAR OF TIME"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Kraft, die die Zeit ver-\n"
            "zerrt. Nächste Runde Pause."),
#else
            "Powerful, but leaves the\n"
            "user immobile the next turn."),
#endif
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RoarOfTime,
    },

    [MOVE_SPACIAL_REND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Raumschlag"),
#else
        .name = COMPOUND_STRING("SPACIAL REND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwere, raumgreifende Atta-\n"
            "cke. Hohe Volltrefferquote."),
#else
            "Tears the foe, and space.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpacialRend,
    },

    [MOVE_LUNAR_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lunartanz"),
#else
        .name = COMPOUND_STRING("LUNAR DANCE"),
#endif
        .description = sHealingWishDescription,
        .effect = EFFECT_LUNAR_DANCE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LunarDance,
    },

    [MOVE_CRUSH_GRIP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Quetschgriff"),
#else
        .name = COMPOUND_STRING("CRUSH GRIP"),
#endif
        .description = sWringOutDescription,
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CrushGrip,
    },

    [MOVE_MAGMA_STORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lavasturm"),
#else
        .name = COMPOUND_STRING("MAGMA STORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fängt den Gegner in einem\n"
            "Feuerwirbel, "BINDING_TURNS" Rd."),
#else
            "Traps the foe in a vortex\n"
            "of fire for "BINDING_TURNS" turns."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 120,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 70,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_MAGMA_STORM,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_MagmaStorm,
    },

    [MOVE_DARK_VOID] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schlummerort"),
#else
        .name = COMPOUND_STRING("DARK VOID"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Zieht den Gegner in Dunkel-\n"
            "heit und schläfert ihn ein."),
#else
            "Drags the foes into total\n"
            "darkness, inducing Sleep."),
#endif
        .effect = EFFECT_DARK_VOID,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 50 : 80,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .nonVolatileStatus = MOVE_EFFECT_SLEEP },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_DARK_VOID,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DarkVoid,
    },

    [MOVE_SEED_FLARE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schocksamen"),
#else
        .name = COMPOUND_STRING("SEED FLARE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt eine Schockwelle.\n"
            "Senkt evtl. gegn. Sp.Vert."),
#else
            "Generates a shock wave that\n"
            "sharply reduces Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 40,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SeedFlare,
    },

    [MOVE_OMINOUS_WIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Unheilböen"),
#else
        .name = COMPOUND_STRING("OMINOUS WIND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Abscheuliche Winde. Steigert\n"
            "evtl. alle eigenen Werte."),
#else
            "A repulsive attack that may\n"
            "raise all stats."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_BEAUTY : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OminousWind,
    },

    [MOVE_SHADOW_FORCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schemenkraft"),
#else
        .name = COMPOUND_STRING("SHADOW FORCE"),
#endif
        .description = sShadowForceDescription,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS == GEN_6,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId = STRINGID_VANISHEDINSTANTLY, .status = STATE_PHANTOM_FORCE },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = C_UPDATED_MOVE_CATEGORIES >= GEN_6 ? CONTEST_CATEGORY_COOL : CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShadowForce,
    },

    [MOVE_HONE_CLAWS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Klauenwetzer"),
#else
        .name = COMPOUND_STRING("HONE CLAWS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wetzt die Klauen. Erhöht\n"
            "Angriff und Genauigkeit."),
#else
            "Sharpens its claws to raise\n"
            "Attack and Accuracy."),
#endif
        .effect = EFFECT_ATTACK_ACCURACY_UP,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_HONE_CLAWS,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HoneClaws,
    },

    [MOVE_WIDE_GUARD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rundumschutz"),
#else
        .name = COMPOUND_STRING("WIDE GUARD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt eine Runde vor An-\n"
            "griffen auf das ganze Team."),
#else
            "Evades wide-ranging attacks\n"
            "for one turn."),
#endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_WIDE_GUARD },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WideGuard,
    },

    [MOVE_GUARD_SPLIT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schutzteiler"),
#else
        .name = COMPOUND_STRING("GUARD SPLIT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gleicht Vert. und Sp.Vert. mit\n"
            "dem Ziel aus."),
#else
            "Averages changes to Defense\n"
            "and Sp. Def with the foe."),
#endif
        .effect = EFFECT_GUARD_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GuardSplit,
    },

    [MOVE_POWER_SPLIT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kraftteiler"),
#else
        .name = COMPOUND_STRING("POWER SPLIT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gleicht Angriff und Sp.Ang.\n"
            "mit dem Ziel aus."),
#else
            "Averages changes to Attack\n"
            "and Sp. Atk with the foe."),
#endif
        .effect = EFFECT_POWER_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerSplit,
    },

    [MOVE_WONDER_ROOM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wunderraum"),
#else
        .name = COMPOUND_STRING("WONDER ROOM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Tauscht 5 Runden lang Vert.\n"
            "und Sp.Vert. aller Pkmn."),
#else
            "Defense and Sp. Def stats\n"
            "are swapped for 5 turns."),
#endif
        .effect = EFFECT_WONDER_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WonderRoom,
    },

    [MOVE_PSYSHOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psychoschock"),
#else
        .name = COMPOUND_STRING("PSYSHOCK"),
#endif
        .description = sPsyshockDescription,
        .effect = EFFECT_PSYSHOCK,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Psyshock,
    },

    [MOVE_VENOSHOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftschock"),
#else
        .name = COMPOUND_STRING("VENOSHOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelt so stark gegen\n"
            "vergiftete Ziele."),
#else
            "Does double damage if the\n"
            "foe is poisoned."),
#endif
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_PSN_ANY },
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC, COMBO_STARTER_POISON_GAS, COMBO_STARTER_POISON_POWDER, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_Venoshock,
    },

    [MOVE_AUTOTOMIZE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Autotomie"),
#else
        .name = COMPOUND_STRING("AUTOTOMIZE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirft Ballast ab. Erhöht Init.\n"
            "stark, senkt Gewicht."),
#else
            "Sheds additional weight to\n"
            "sharply boost Speed."),
#endif
        .effect = EFFECT_AUTOTOMIZE,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Autotomize,
    },

    [MOVE_RAGE_POWDER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wutpulver"),
#else
        .name = COMPOUND_STRING("RAGE POWDER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Zieht die Angriffe der Gegner\n"
            "auf den Anwender."),
#else
            "Scatters powder to make\n"
            "foes attack only the user."),
#endif
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 2 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .powderMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RagePowder,
    },

    [MOVE_TELEKINESIS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Telekinese"),
#else
        .name = COMPOUND_STRING("TELEKINESIS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lässt das Ziel 3 Runden\n"
            "schweben. Leicht zu treffen."),
#else
            "Makes the foe float. It is\n"
            "easier to hit for 3 turns."),
#endif
        .effect = EFFECT_TELEKINESIS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Telekinesis,
    },

    [MOVE_MAGIC_ROOM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Magieraum"),
#else
        .name = COMPOUND_STRING("MAGIC ROOM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Items verlieren 5 Runden lang\n"
            "ihre Wirkung."),
#else
            "Hold items lose their\n"
            "effects for 5 turns."),
#endif
        .effect = EFFECT_MAGIC_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagicRoom,
    },

    [MOVE_SMACK_DOWN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Katapult"),
#else
        .name = COMPOUND_STRING("SMACK DOWN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Holt fliegende Ziele auf den\n"
            "Boden herunter."),
#else
            "Throws a rock to knock the\n"
            "foe down to the ground."),
#endif
        .effect = EFFECT_SMACK_DOWN,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesAirborne = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_SmackDown,
    },

    [MOVE_STORM_THROW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bergsturm"),
#else
        .name = COMPOUND_STRING("STORM THROW"),
#endif
        .description = sStormThrowDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_StormThrow,
    },

    [MOVE_FLAME_BURST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Funkenflug"),
#else
        .name = COMPOUND_STRING("FLAME BURST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Funken treffen auch das\n"
            "Pkmn neben dem Ziel."),
#else
            "A bursting flame that does\n"
            "damage to all foes."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLAME_BURST,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlameBurst,
    },

    [MOVE_SLUDGE_WAVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schlammwoge"),
#else
        .name = COMPOUND_STRING("SLUDGE WAVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Schlammwelle, die evtl.\n"
            "vergiftet."),
#else
            "Swamps all others with a wave\n"
            "of sludge. May also poison."),
#endif
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SludgeWave,
    },

    [MOVE_QUIVER_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Falterreigen"),
#else
        .name = COMPOUND_STRING("QUIVER DANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht Sp.Ang., Sp.Vert. und\n"
            "Init. des Anwenders."),
#else
            "Dances to raise Sp. Atk\n"
            "Sp. Def and Speed."),
#endif
        .effect = EFFECT_QUIVER_DANCE,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_QuiverDance,
    },

    [MOVE_HEAVY_SLAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rammboss"),
#else
        .name = COMPOUND_STRING("HEAVY SLAM"),
#endif
        .description = sHeavySlamDescription,
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_7,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeavySlam,
    },

    [MOVE_SYNCHRONOISE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Synchrolärm"),
#else
        .name = COMPOUND_STRING("SYNCHRONOISE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft nur Pkmn, die\n"
            "denselben Typ haben."),
#else
            "An odd shock wave that only\n"
            "damages same-type {PKMN}."),
#endif
        .effect = EFFECT_SYNCHRONOISE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 120 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Synchronoise,
    },

    [MOVE_ELECTRO_BALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Elektroball"),
#else
        .name = COMPOUND_STRING("ELECTRO BALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je schneller der Anwender als\n"
            "das Ziel, desto stärker."),
#else
            "Hurls an orb that does more\n"
            "damage to slower foes."),
#endif
        .effect = EFFECT_ELECTRO_BALL,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_AGILITY, COMBO_STARTER_CHARGE, COMBO_STARTER_ROCK_POLISH},
        .battleAnimScript = gBattleAnimMove_ElectroBall,
    },

    [MOVE_SOAK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Überflutung"),
#else
        .name = COMPOUND_STRING("SOAK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Überschüttet das Ziel und\n"
            "macht es zum Wasser-Typ."),
#else
            "Sprays water at the foe,\n"
            "changing it to Water type."),
#endif
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_WATER },
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Soak,
    },

    [MOVE_FLAME_CHARGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nitroladung"),
#else
        .name = COMPOUND_STRING("FLAME CHARGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff in Flammen. Erhöht\n"
            "die eigene Init."),
#else
            "Attacks in a cloak of\n"
            "flames. Raises Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlameCharge,
    },

    [MOVE_COIL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Einrollen"),
#else
        .name = COMPOUND_STRING("COIL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Rollt sich ein. Erhöht An-\n"
            "griff, Vert. und Genauigkeit."),
#else
            "Coils up to raise Attack,\n"
            "Defense and Accuracy."),
#endif
        .effect = EFFECT_COIL,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Coil,
    },

    [MOVE_LOW_SWEEP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fußtritt"),
#else
        .name = COMPOUND_STRING("LOW SWEEP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff auf die Beine. Senkt\n"
            "die Init. des Zieles."),
#else
            "Attacks the foe's legs\n"
            "lowering its Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LowSweep,
    },

    [MOVE_ACID_SPRAY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Säurespeier"),
#else
        .name = COMPOUND_STRING("ACID SPRAY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ätzende Flüssigkeit. Senkt\n"
            "Sp.Vert. des Zieles stark."),
#else
            "Sprays a hide-melting acid.\n"
            "Sharply reduces Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AcidSpray,
    },

    [MOVE_FOUL_PLAY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schmarotzer"),
#else
        .name = COMPOUND_STRING("FOUL PLAY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je höher der Angriff des\n"
            "Zieles, desto mehr Schaden."),
#else
            "The higher the foe's Attack\n"
            "the more damage caused."),
#endif
        .effect = EFFECT_FOUL_PLAY,
        .power = 95,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FoulPlay,
    },

    [MOVE_SIMPLE_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wankelstrahl"),
#else
        .name = COMPOUND_STRING("SIMPLE BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ändert die Fähigkeit des\n"
            "Zieles zu Wankelmut."),
#else
            "A beam that changes the\n"
            "foe's Ability to Simple."),
#endif
        .effect = EFFECT_OVERWRITE_ABILITY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .overwriteAbility = ABILITY_SIMPLE },
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SimpleBeam,
    },

    [MOVE_ENTRAINMENT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zwango"),
#else
        .name = COMPOUND_STRING("ENTRAINMENT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel nimmt die Fähigkeit\n"
            "des Anwenders an."),
#else
            "Makes the foe mimic the\n"
            "user, gaining its Ability."),
#endif
        .effect = EFFECT_ENTRAINMENT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_ENTRAINMENT,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Entrainment,
    },

    [MOVE_AFTER_YOU] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Galanterie"),
#else
        .name = COMPOUND_STRING("AFTER YOU"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel handelt direkt nach\n"
            "dem Anwender."),
#else
            "Helps out the target, letting\n"
            "it move next."),
#endif
        .effect = EFFECT_AFTER_YOU,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AfterYou,
    },

    [MOVE_ROUND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kanon"),
#else
        .name = COMPOUND_STRING("ROUND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit Gesang. Singen\n"
            "mehrere mit, wird er stärker."),
#else
            "A song that inflicts damage.\n"
            "Others can join in too."),
#endif
        .effect = EFFECT_ROUND,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ROUND,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Round,
    },

    [MOVE_ECHOED_VOICE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Widerhall"),
#else
        .name = COMPOUND_STRING("ECHOED VOICE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wird stärker, je öfter sie\n"
            "hintereinander wirkt."),
#else
            "Does more damage every turn\n"
            "it is used."),
#endif
        .effect = EFFECT_ECHOED_VOICE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_EchoedVoice,
    },

    [MOVE_CHIP_AWAY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zermürben"),
#else
        .name = COMPOUND_STRING("CHIP AWAY"),
#endif
        .description = sChipAwayDescription,
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ChipAway,
    },

    [MOVE_CLEAR_SMOG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Klärsmog"),
#else
        .name = COMPOUND_STRING("CLEAR SMOG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Setzt die Statusänderungen\n"
            "des Zieles zurück."),
#else
            "Attacks with white haze that\n"
            "eliminates all stat changes."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CLEAR_SMOG,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ClearSmog,
    },

    [MOVE_STORED_POWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kraftvorrat"),
#else
        .name = COMPOUND_STRING("STORED POWER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je höher die eigenen Werte,\n"
            "desto stärker."),
#else
            "The higher the user's stats\n"
            "the more damage caused."),
#endif
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_AMNESIA, COMBO_STARTER_HONE_CLAWS, COMBO_STARTER_CALM_MIND, COMBO_STARTER_NASTY_PLOT},
        .battleAnimScript = gBattleAnimMove_StoredPower,
    },

    [MOVE_QUICK_GUARD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rapidschutz"),
#else
        .name = COMPOUND_STRING("QUICK GUARD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt das Team vor\n"
            "Erstschlag-Attacken."),
#else
            "Evades priority attacks\n"
            "for one turn."),
#endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_QUICK_GUARD, },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_QuickGuard,
    },

    [MOVE_ALLY_SWITCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Seitentausch"),
#else
        .name = COMPOUND_STRING("ALLY SWITCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Tauscht den Platz mit einem\n"
            "Mitstreiter."),
#else
            "The user switches places\n"
            "with its partner."),
#endif
        .effect = EFFECT_ALLY_SWITCH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_7 ? 2 : 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AllySwitch,
    },

    [MOVE_SCALD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Siedewasser"),
#else
        .name = COMPOUND_STRING("SCALD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Siedend heißes Wasser.\n"
            "Verbrennt das Ziel eventuell."),
#else
            "Shoots boiling water at the\n"
            "foe. May inflict a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCALD,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Scald,
    },

    [MOVE_SHELL_SMASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hausbruch"),
#else
        .name = COMPOUND_STRING("SHELL SMASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt Vert. und Sp.Vert.,\n"
            "erhöht Angriff, Sp.Ang., Init."),
#else
            "Sharply raises Atk/Sp.Atk/\n"
            "Speed, but drops Def/Sp.Def."),
#endif
        .effect = EFFECT_SHELL_SMASH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShellSmash,
    },

    [MOVE_HEAL_PULSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Heilwoge"),
#else
        .name = COMPOUND_STRING("HEAL PULSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt das Ziel um die Hälfte\n"
            "seiner max. KP."),
#else
            "Recovers up to half the\n"
            "target's maximum HP."),
#endif
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .pulseMove = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HealPulse,
    },

    [MOVE_HEX] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bürde"),
#else
        .name = COMPOUND_STRING("HEX"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fügt Zielen mit Statuspro-\n"
            "blem hohen Schaden zu."),
#else
            "Does double damage if the\n"
            "foe has a status problem."),
#endif
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 160 },
        .argument = { .status = STATUS1_ANY },
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC, COMBO_STARTER_FORCE_PALM, COMBO_STARTER_THUNDER_WAVE, COMBO_STARTER_INFERNO, COMBO_STARTER_WILL_O_WISP, COMBO_STARTER_LOVELY_KISS, COMBO_STARTER_SPORE, COMBO_STARTER_SING, COMBO_STARTER_YAWN, COMBO_STARTER_HYPNOSIS, COMBO_STARTER_DARK_VOID, COMBO_STARTER_GRASS_WHISTLE, COMBO_STARTER_SLEEP_POWDER, COMBO_STARTER_POISON_GAS, COMBO_STARTER_POISON_POWDER, COMBO_STARTER_TOXIC_SPIKES, COMBO_STARTER_GLARE},
        .battleAnimScript = gBattleAnimMove_Hex,
    },

    [MOVE_SKY_DROP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Freier Fall"),
#else
        .name = COMPOUND_STRING("SKY DROP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt das Ziel hoch und lässt\n"
            "es in Runde 2 fallen."),
#else
            "Takes the foe into the sky\n"
            "then drops it the next turn."),
#endif
        .effect = EFFECT_SKY_DROP,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNTOOKTARGETHIGH, .status = STATE_ON_AIR },
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_SkyDrop,
    },

    [MOVE_SHIFT_GEAR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gangwechsel"),
#else
        .name = COMPOUND_STRING("SHIFT GEAR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht den Angriff und die\n"
            "Init. des Anwenders."),
#else
            "Rotates its gears to raise\n"
            "Attack and Speed."),
#endif
        .effect = EFFECT_SHIFT_GEAR,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_SHIFT_GEAR,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShiftGear,
    },

    [MOVE_CIRCLE_THROW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Überkopfwurf"),
#else
        .name = COMPOUND_STRING("CIRCLE THROW"),
#endif
        .description = sCircleThrowDescription,
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -6,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENTRAINMENT, COMBO_STARTER_PLAY_NICE},
        .battleAnimScript = gBattleAnimMove_CircleThrow,
    },

    [MOVE_INCINERATE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Einäschern"),
#else
        .name = COMPOUND_STRING("INCINERATE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verbrennt die Beere oder das\n"
            "Item des Zieles."),
#else
            "Burns up Berries and Gems\n"
            "preventing their use."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 30,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_INCINERATE,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Incinerate,
    },

    [MOVE_QUASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Verzögerung"),
#else
        .name = COMPOUND_STRING("QUASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel greift erst als\n"
            "Letztes an."),
#else
            "Suppresses the foe, making\n"
            "it move last."),
#endif
        .effect = EFFECT_QUASH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Quash,
    },

    [MOVE_ACROBATICS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Akrobatik"),
#else
        .name = COMPOUND_STRING("ACROBATICS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelt so stark, wenn der\n"
            "Anwender kein Item trägt."),
#else
            "Does double damage if the\n"
            "user has no item."),
#endif
        .effect = EFFECT_ACROBATICS,
        .power = 55,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Acrobatics,
    },

    [MOVE_REFLECT_TYPE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Typenspiegel"),
#else
        .name = COMPOUND_STRING("REFLECT TYPE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Anwender nimmt den Typ\n"
            "des Zieles an."),
#else
            "The user reflects the foe's\n"
            "type, copying it."),
#endif
        .effect = EFFECT_REFLECT_TYPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ReflectType,
    },

    [MOVE_RETALIATE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Heimzahlung"),
#else
        .name = COMPOUND_STRING("RETALIATE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärker, wenn zuvor ein\n"
            "Mitstreiter besiegt wurde."),
#else
            "Attack that does more\n"
            "damage if an ally fainted."),
#endif
        .effect = EFFECT_RETALIATE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Retaliate,
    },

    [MOVE_FINAL_GAMBIT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wagemut"),
#else
        .name = COMPOUND_STRING("FINAL GAMBIT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schadet in Höhe der eigenen\n"
            "KP. Anwender wird K.O."),
#else
            "The user faints to damage\n"
            "the foe equal to its HP."),
#endif
        .effect = EFFECT_FINAL_GAMBIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .explosion = B_UPDATED_MOVE_FLAGS <= GEN_5,
        .mirrorMoveBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FinalGambit,
    },

    [MOVE_BESTOW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Offerte"),
#else
        .name = COMPOUND_STRING("BESTOW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gibt das eigene Item an ein\n"
            "Ziel ohne Item ab."),
#else
            "The user gives its held\n"
            "item to the foe."),
#endif
        .effect = EFFECT_BESTOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CELEBRATE, COMBO_STARTER_COVET, COMBO_STARTER_HAPPY_HOUR, COMBO_STARTER_WISH},
        .battleAnimScript = gBattleAnimMove_Bestow,
    },

    [MOVE_INFERNO] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Inferno"),
#else
        .name = COMPOUND_STRING("INFERNO"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Dichte Flammen. Das Ziel\n"
            "erleidet Verbrennungen."),
#else
            "Powerful and sure to inflict\n"
            "a burn, but inaccurate."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 50,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_INFERNO,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Inferno,
    },

    [MOVE_WATER_PLEDGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wassersäulen"),
#else
        .name = COMPOUND_STRING("WATER PLEDGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Mit Feuersäulen kombiniert\n"
            "stärker. Erzeugt Regenbogen."),
#else
            "Attacks with a column of\n"
            "water. May make a rainbow."),
#endif
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WaterPledge,
    },

    [MOVE_FIRE_PLEDGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feuersäulen"),
#else
        .name = COMPOUND_STRING("FIRE PLEDGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Mit Pflanzensäulen stärker.\n"
            "Erzeugt ein Feuermeer."),
#else
            "Attacks with a column of\n"
            "fire. May burn the grass."),
#endif
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FirePledge,
    },

    [MOVE_GRASS_PLEDGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pflanzensäulen"),
#else
        .name = COMPOUND_STRING("GRASS PLEDGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Mit Wassersäulen kombiniert\n"
            "stärker. Erzeugt Sumpf."),
#else
            "Attacks with a column of\n"
            "grass. May create a swamp."),
#endif
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassPledge,
    },

    [MOVE_VOLT_SWITCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Voltwechsel"),
#else
        .name = COMPOUND_STRING("VOLT SWITCH"),
#endif
        .description = sUTurnDescription,
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_VoltSwitch,
    },

    [MOVE_STRUGGLE_BUG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Käfertrutz"),
#else
        .name = COMPOUND_STRING("STRUGGLE BUG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt den Sp.Ang. der Ziele.\n"
            ""),
#else
            "Resisting, the user attacks\n"
            "the foes. Lowers Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 30,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StruggleBug,
    },

    [MOVE_BULLDOZE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dampfwalze"),
#else
        .name = COMPOUND_STRING("BULLDOZE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Walzt den Boden platt. Senkt\n"
            "die Init. aller Betroffenen."),
#else
            "Stomps down on the ground.\n"
            "Hits all and lowers Speed."),
#endif
        .effect = EFFECT_EARTHQUAKE,
        .power = 60,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Bulldoze,
    },

    [MOVE_FROST_BREATH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eisesodem"),
#else
        .name = COMPOUND_STRING("FROST BREATH"),
#endif
        .description = sStormThrowDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .alwaysCriticalHit = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FrostBreath,
    },

    [MOVE_DRAGON_TAIL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drachenrute"),
#else
        .name = COMPOUND_STRING("DRAGON TAIL"),
#endif
        .description = sCircleThrowDescription,
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = -6,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_DRAGON_TAIL,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_STEALTH_ROCK, COMBO_STARTER_SPIKES, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_DragonTail,
    },

    [MOVE_WORK_UP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kraftschub"),
#else
        .name = COMPOUND_STRING("WORK UP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht den Angriff und\n"
            "Sp.Ang. des Anwenders."),
#else
            "The user is roused.\n"
            "Ups Attack and Sp. Atk."),
#endif
        .effect = EFFECT_ATTACK_SPATK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WorkUp,
    },

    [MOVE_ELECTROWEB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Elektronetz"),
#else
        .name = COMPOUND_STRING("ELECTROWEB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein E-Netz fängt die Ziele.\n"
            "Senkt deren Init."),
#else
            "Snares the foes with an\n"
            "electric net. Lowers Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STRING_SHOT},
        .battleAnimScript = gBattleAnimMove_Electroweb,
    },

    [MOVE_WILD_CHARGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stromstoß"),
#else
        .name = COMPOUND_STRING("WILD CHARGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Anwender erleidet dabei\n"
            "selbst Schaden."),
#else
            "An electrical tackle that\n"
            "also hurts the user."),
#endif
        .effect = EFFECT_RECOIL,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WildCharge,
    },

    [MOVE_DRILL_RUN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schlagbohrer"),
#else
        .name = COMPOUND_STRING("DRILL RUN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Dreht sich wie ein Bohrer.\n"
            "Hohe Volltrefferquote."),
#else
            "Spins its body like a drill.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
        .battleAnimScript = gBattleAnimMove_DrillRun,
    },

    [MOVE_DUAL_CHOP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Doppelhieb"),
#else
        .name = COMPOUND_STRING("DUAL CHOP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Angriff erfolgt zweimal\n"
            "hintereinander."),
#else
            "Attacks with brutal hits\n"
            "that strike twice."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DualChop,
    },

    [MOVE_HEART_STAMP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Herzstempel"),
#else
        .name = COMPOUND_STRING("HEART STAMP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein harter Schlag. Das Ziel\n"
            "schreckt evtl. zurück."),
#else
            "A sudden blow after a cute\n"
            "act. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeartStamp,
    },

    [MOVE_HORN_LEECH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Holzgeweih"),
#else
        .name = COMPOUND_STRING("HORN LEECH"),
#endif
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HornLeech,
    },

    [MOVE_SACRED_SWORD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sanctoklinge"),
#else
        .name = COMPOUND_STRING("SACRED SWORD"),
#endif
        .description = sChipAwayDescription,
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SacredSword,
    },

    [MOVE_RAZOR_SHELL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kalkklinge"),
#else
        .name = COMPOUND_STRING("RAZOR SHELL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt evtl. die Vert. des\n"
            "Zieles."),
#else
            "Tears at the foe with sharp\n"
            "shells. May lower Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RazorShell,
    },

    [MOVE_HEAT_CRASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Brandstempel"),
#else
        .name = COMPOUND_STRING("HEAT CRASH"),
#endif
        .description = sHeavySlamDescription,
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeatCrash,
    },

    [MOVE_LEAF_TORNADO] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Grasmixer"),
#else
        .name = COMPOUND_STRING("LEAF TORNADO"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt evtl. die Genauigkeit\n"
            "des Zieles."),
#else
            "Circles the foe with leaves\n"
            "to damage and cut accuracy."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LeafTornado,
    },

    [MOVE_STEAMROLLER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Quetschwalze"),
#else
        .name = COMPOUND_STRING("STEAMROLLER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Walzt das Ziel platt. Es\n"
            "schreckt evtl. zurück."),
#else
            "Crushes the foe with its\n"
            "body. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Steamroller,
    },

    [MOVE_COTTON_GUARD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Watteschild"),
#else
        .name = COMPOUND_STRING("COTTON GUARD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hüllt sich in Flaum. Erhöht\n"
            "die Vert. drastisch."),
#else
            "Wraps its body in cotton.\n"
            "Drastically raises Defense."),
#endif
        .effect = EFFECT_DEFENSE_UP_3,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CottonGuard,
    },

    [MOVE_NIGHT_DAZE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nachtflut"),
#else
        .name = COMPOUND_STRING("NIGHT DAZE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Finstere Schockwellen. Senkt\n"
            "evtl. die Genauigkeit."),
#else
            "Looses a pitch-black shock\n"
            "wave. May lower accuracy."),
#endif
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 40,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NightDaze,
    },

    [MOVE_PSYSTRIKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psychostoß"),
#else
        .name = COMPOUND_STRING("PSYSTRIKE"),
#endif
        .description = sPsyshockDescription,
        .effect = EFFECT_PSYSHOCK,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Psystrike,
    },

    [MOVE_TAIL_SLAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kehrschelle"),
#else
        .name = COMPOUND_STRING("TAIL SLAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft das Ziel zwei- bis\n"
            "fünfmal hintereinander."),
#else
            "Strikes the foe with its\n"
            "tail 2 to 5 times."),
#endif
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TailSlap,
    },

    [MOVE_HURRICANE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Orkan"),
#else
        .name = COMPOUND_STRING("HURRICANE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heftige Windböen. Verwirren\n"
            "das Ziel eventuell."),
#else
            "Traps the foe in a fierce\n"
            "wind. May cause confusion."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_FLYING,
        .accuracy = 70,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .damagesAirborne = TRUE,
        .alwaysHitsInRain = TRUE,
        .accuracy50InSun = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Hurricane,
    },

    [MOVE_HEAD_CHARGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Steinschädel"),
#else
        .name = COMPOUND_STRING("HEAD CHARGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Rempelangriff. Anwender\n"
            "nimmt leichten Schaden."),
#else
            "A charge using guard hair.\n"
            "It hurts the user a little."),
#endif
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 25 },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeadCharge,
    },

    [MOVE_GEAR_GRIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Klikkdiskus"),
#else
        .name = COMPOUND_STRING("GEAR GRIND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Angriff erfolgt zweimal\n"
            "hintereinander."),
#else
            "Throws two steel gears\n"
            "that strike twice."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 180 },
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SHIFT_GEAR},
        .battleAnimScript = gBattleAnimMove_GearGrind,
    },

    [MOVE_SEARING_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flammenball"),
#else
        .name = COMPOUND_STRING("SEARING SHOT"),
#endif
        .description = sLavaPlumeDescription,
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SearingShot,
    },

    [MOVE_TECHNO_BLAST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Techblaster"),
#else
        .name = COMPOUND_STRING("TECHNO BLAST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Typ hängt vom getragenen\n"
            "Modul ab."),
#else
            "The type varies with the\n"
            "kind of Drive held."),
#endif
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 120 : 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .holdEffect = HOLD_EFFECT_DRIVE },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TechnoBlast,
    },

    [MOVE_RELIC_SONG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Urgesang"),
#else
        .name = COMPOUND_STRING("RELIC SONG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Urgesang. Die Ziele\n"
            "schlafen eventuell ein."),
#else
            "Attacks with an ancient\n"
            "song. May induce sleep."),
#endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_SLEEP },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SLEEP,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RelicSong,
    },

    [MOVE_SECRET_SWORD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mystoschwert"),
#else
        .name = COMPOUND_STRING("SECRET SWORD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Kraft des Horns erzeugt\n"
            "physischen Schaden."),
#else
            "Cuts with a long horn that\n"
            "does physical damage."),
#endif
        .effect = EFFECT_PSYSHOCK,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SecretSword,
    },

    [MOVE_GLACIATE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eiszeit"),
#else
        .name = COMPOUND_STRING("GLACIATE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Klirrend kalte Luft. Senkt\n"
            "die Init. der Ziele."),
#else
            "Blows very cold air at the\n"
            "foes. It lowers their Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_Glaciate,
    },

    [MOVE_BOLT_STRIKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blitzschlag"),
#else
        .name = COMPOUND_STRING("BOLT STRIKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein geladener Rempler. Para-\n"
            "lysiert das Ziel eventuell."),
#else
            "Strikes with a great amount\n"
            "of lightning. May paralyze."),
#endif
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BoltStrike,
    },

    [MOVE_BLUE_FLARE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blauflammen"),
#else
        .name = COMPOUND_STRING("BLUE FLARE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Intensivblaue Flammen. Ver-\n"
            "brennen das Ziel eventuell."),
#else
            "Engulfs the foe in a blue\n"
            "flame. May inflict a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BlueFlare,
    },

    [MOVE_FIERY_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feuerreigen"),
#else
        .name = COMPOUND_STRING("FIERY DANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht evtl. den Sp.Ang. des\n"
            "Anwenders."),
#else
            "Dances cloaked in flames.\n"
            "May raise Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .danceMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FieryDance,
    },

    [MOVE_FREEZE_SHOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Frostvolt"),
#else
        .name = COMPOUND_STRING("FREEZE SHOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft in Runde 2. Paralysiert\n"
            "das Ziel eventuell."),
#else
            "A powerful 2-turn move that\n"
            "may paralyze the foe."),
#endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_CLOAKEDINAFREEZINGLIGHT },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FreezeShock,
    },

    [MOVE_ICE_BURN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Frosthauch"),
#else
        .name = COMPOUND_STRING("ICE BURN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft in Runde 2. Verbrennt\n"
            "das Ziel eventuell."),
#else
            "A powerful 2-turn move that\n"
            "may inflict a burn."),
#endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_CLOAKEDINAFREEZINGLIGHT },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IceBurn,
    },

    [MOVE_SNARL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Standpauke"),
#else
        .name = COMPOUND_STRING("SNARL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Standpauke. Senkt den\n"
            "Sp.Ang. der Ziele."),
#else
            "Yells and rants at the foe\n"
            "lowering its Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Snarl,
    },

    [MOVE_ICICLE_CRASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eiszapfhagel"),
#else
        .name = COMPOUND_STRING("ICICLE CRASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwere Eiszapfen. Das Ziel\n"
            "schreckt evtl. zurück."),
#else
            "Drops large icicles on the\n"
            "foe. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IcicleCrash,
    },

    [MOVE_V_CREATE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("V-Generator"),
#else
        .name = COMPOUND_STRING("V-CREATE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr stark. Senkt eigene\n"
            "Vert., Sp.Vert. und Init."),
#else
            "Very powerful, but lowers\n"
            "Defense, Sp. Def and Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 220 },
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_V_CREATE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_VCreate,
    },

    [MOVE_FUSION_FLARE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kreuzflamme"),
#else
        .name = COMPOUND_STRING("FUSION FLARE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärker, wenn zuvor ein\n"
            "gewaltiger Blitz einschlug."),
#else
            "Summons a fireball. Works\n"
            "well with a thunderbolt."),
#endif
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FusionFlare,
    },

    [MOVE_FUSION_BOLT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kreuzdonner"),
#else
        .name = COMPOUND_STRING("FUSION BOLT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärker, wenn zuvor eine\n"
            "gewaltige Flamme brannte."),
#else
            "Summons a thunderbolt.\n"
            "Works well with a fireball."),
#endif
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FusionBolt,
    },

    [MOVE_FLYING_PRESS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flying Press"),
#else
        .name = COMPOUND_STRING("FLYING PRESS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Angriff hat die Typen\n"
            "Kampf und Flug zugleich."),
#else
            "This attack does Fighting\n"
            "and Flying-type damage."),
#endif
        .effect = EFFECT_TWO_TYPED_MOVE,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 100 : 80,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 170 },
        .argument = { .type = TYPE_FLYING },
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .gravityBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlyingPress,
    },

    [MOVE_MAT_BLOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tatami-Schild"),
#else
        .name = COMPOUND_STRING("MAT BLOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt das Team vor Scha-\n"
            "den. Nicht gegen Status-Att."),
#else
            "Evades damaging moves.\n"
            "Only works on 1st turn."),
#endif
        .effect = EFFECT_MAT_BLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_MAT_BLOCK, },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MatBlock,
    },

    [MOVE_BELCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rülpser"),
#else
        .name = COMPOUND_STRING("BELCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gelingt nur, wenn der Anwen-\n"
            "der eine Beere gegessen hat."),
#else
            "Lets out a loud belch.\n"
            "Must eat a Berry to use it."),
#endif
        .effect = EFFECT_BELCH,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Belch,
    },

    [MOVE_ROTOTILLER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pflüger"),
#else
        .name = COMPOUND_STRING("ROTOTILLER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht Angriff und Sp.Ang.\n"
            "aller Pflanzen-Pkmn."),
#else
            "Ups the Attack and Sp. Atk\n"
            "of Grass-type Pokémon."),
#endif
        .effect = EFFECT_ROTOTILLER,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ROTOTILLER,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Rototiller,
    },

    [MOVE_STICKY_WEB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Klebenetz"),
#else
        .name = COMPOUND_STRING("STICKY WEB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Netz senkt die Init.\n"
            "eingreifender Gegner."),
#else
            "Weaves a sticky net that\n"
            "slows foes switching in."),
#endif
        .effect = EFFECT_STICKY_WEB,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STRING_SHOT},
        .battleAnimScript = gBattleAnimMove_StickyWeb,
    },

    [MOVE_FELL_STINGER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stachelfinale"),
#else
        .name = COMPOUND_STRING("FELL STINGER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Besiegt sie das Ziel, steigt\n"
            "der Angriff drastisch."),
#else
            "If it knocks out a foe\n"
            "the Attack stat is raised."),
#endif
        .effect = EFFECT_FELL_STINGER,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 50 : 30,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 25,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FellStinger,
    },

    [MOVE_PHANTOM_FORCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Phantomkraft"),
#else
        .name = COMPOUND_STRING("PHANTOM FORCE"),
#endif
        .description = sShadowForceDescription,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_7,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_VANISHEDINSTANTLY, .status = STATE_PHANTOM_FORCE },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PhantomForce,
    },

    [MOVE_TRICK_OR_TREAT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Halloween"),
#else
        .name = COMPOUND_STRING("TRICK-OR-TREAT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel nimmt zusätzlich den\n"
            "Typ Geist an."),
#else
            "Goes trick-or-treating,\n"
            "adding Ghost type to foe."),
#endif
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_GHOST },
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TrickOrTreat,
    },

    [MOVE_NOBLE_ROAR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kampfgebrüll"),
#else
        .name = COMPOUND_STRING("NOBLE ROAR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Gebrüll senkt Angriff und\n"
            "Sp.Ang. des Zieles."),
#else
            "Intimidates the foe, to cut\n"
            "Attack and Sp. Atk."),
#endif
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NobleRoar,
    },

    [MOVE_ION_DELUGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Plasmaschauer"),
#else
        .name = COMPOUND_STRING("ION DELUGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Normal-Attacken nehmen den\n"
            "Typ Elektro an."),
#else
            "Electrifies Normal-type\n"
            "moves with charged atoms."),
#endif
        .effect = EFFECT_ION_DELUGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 25,
        .target = TARGET_FIELD,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_IonDeluge,
    },

    [MOVE_PARABOLIC_CHARGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Parabolladung"),
#else
        .name = COMPOUND_STRING("PARABOLIC CHARGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft alle nahen Pkmn. Heilt\n"
            "um die halbe Schadenshöhe."),
#else
            "Damages adjacent Pokémon\n"
            "and heals up by half of it."),
#endif
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 65 : 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PARABOLIC_CHARGE,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ParabolicCharge,
    },

    [MOVE_FORESTS_CURSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Waldesfluch"),
#else
        .name = COMPOUND_STRING("FOREST'S CURSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel nimmt zusätzlich den\n"
            "Typ Pflanze an."),
#else
            "Puts a curse on the foe,\n"
            "adding the Grass type."),
#endif
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_GRASS },
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ForestsCurse,
    },

    [MOVE_PETAL_BLIZZARD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blütenwirbel"),
#else
        .name = COMPOUND_STRING("PETAL BLIZZARD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Blütenwirbel erfasst alle\n"
            "Pkmn in der Nähe."),
#else
            "Stirs up a violent storm\n"
            "of petals to attack all."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PetalBlizzard,
    },

    [MOVE_FREEZE_DRY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gefriertrockner"),
#else
        .name = COMPOUND_STRING("FREEZE-DRY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Super effektiv gegen\n"
#else
            "Super effective on Water-\n"
#endif
        #if B_USE_FROSTBITE == TRUE
#if GERMAN
            "Wasser-Typ, Frostbeulen."),
#else
            "types. May cause frostbite."),
#endif
        #else
#if GERMAN
            "Wasser-Typ, kann frieren."),
#else
            "types. May cause freezing."),
#endif
        #endif
        .effect = EFFECT_SUPER_EFFECTIVE_ON_ARG,
        .power = 70,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .type = TYPE_WATER },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FreezeDry,
    },

    [MOVE_DISARMING_VOICE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Säuselstimme"),
#else
        .name = COMPOUND_STRING("DISARMING VOICE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein bezirzender Ruf, der in\n"
            "jedem Fall trifft."),
#else
            "Lets out a charming cry\n"
            "that cannot be evaded."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DisarmingVoice,
    },

    [MOVE_PARTING_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Abgangstirade"),
#else
        .name = COMPOUND_STRING("PARTING SHOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt Angriff und Sp.Ang.,\n"
            "wechselt dann aus."),
#else
            "Lowers the foe's Attack and\n"
            "Sp. Atk, then switches out."),
#endif
        .effect = EFFECT_PARTING_SHOT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESTORE_REPLACEMENT_HP },
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PartingShot,
    },

    [MOVE_TOPSY_TURVY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Invertigo"),
#else
        .name = COMPOUND_STRING("TOPSY-TURVY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Invertiert alle\n"
            "Statusänderungen des Zieles."),
#else
            "Swaps all stat changes that\n"
            "affect the target."),
#endif
        .effect = EFFECT_TOPSY_TURVY,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 0 : 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TopsyTurvy,
    },

    [MOVE_DRAINING_KISS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Diebeskuss"),
#else
        .name = COMPOUND_STRING("DRAINING KISS"),
#endif
        .description = sDrainingKissDescription,
        .effect = EFFECT_ABSORB,
        .power = 50,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 75 },
        .makesContact = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DrainingKiss,
    },

    [MOVE_CRAFTY_SHIELD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Trickschutz"),
#else
        .name = COMPOUND_STRING("CRAFTY SHIELD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt das Team eine Runde\n"
            "vor Status-Attacken."),
#else
            "Evades status moves for\n"
            "one turn."),
#endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_CRAFTY_SHIELD },
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CraftyShield,
    },

    [MOVE_FLOWER_SHIELD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Floraschutz"),
#else
        .name = COMPOUND_STRING("FLOWER SHIELD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht die Vert. aller\n"
            "Pflanzen-Pkmn im Kampf."),
#else
            "Raises the Defense of\n"
            "Grass-type Pokémon."),
#endif
        .effect = EFFECT_FLOWER_SHIELD,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlowerShield,
    },

    [MOVE_GRASSY_TERRAIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Grasfeld"),
#else
        .name = COMPOUND_STRING("GRASSY TERRAIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Boden wird 5 Runden zu\n"
            "Gras und heilt KP."),
#else
            "The ground turns to grass\n"
            "for 5 turns. Restores HP."),
#endif
        .effect = EFFECT_GRASSY_TERRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_GRASSY_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GrassyTerrain,
    },

    [MOVE_MISTY_TERRAIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nebelfeld"),
#else
        .name = COMPOUND_STRING("MISTY TERRAIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Nebel schützt 5 Runden lang\n"
            "vor Statusproblemen."),
#else
            "Covers the ground with mist\n"
            "for 5 turns. Blocks status."),
#endif
        .effect = EFFECT_MISTY_TERRAIN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_MISTY_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MistyTerrain,
    },

    [MOVE_ELECTRIFY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Elektrifizierung"),
#else
        .name = COMPOUND_STRING("ELECTRIFY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die nächste Attacke des\n"
            "Zieles wird zum Typ Elektro."),
#else
            "Electrifies the foe, making\n"
            "its next move Electric-type."),
#endif
        .effect = EFFECT_ELECTRIFY,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PARABOLIC_CHARGE},
        .battleAnimScript = gBattleAnimMove_Electrify,
    },

    [MOVE_PLAY_ROUGH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Knuddler"),
#else
        .name = COMPOUND_STRING("PLAY ROUGH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein grobes Spiel. Senkt evtl.\n"
            "den Angriff des Zieles."),
#else
            "Plays rough with the foe.\n"
            "May lower Attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PlayRough,
    },

    [MOVE_FAIRY_WIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feenbrise"),
#else
        .name = COMPOUND_STRING("FAIRY WIND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Feenbrise, die das Ziel\n"
            "erfasst."),
#else
            "Stirs up a fairy wind to\n"
            "strike the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FairyWind,
    },

    [MOVE_MOONBLAST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mondgewalt"),
#else
        .name = COMPOUND_STRING("MOONBLAST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Kraft des Mondes. Senkt\n"
            "evtl. den Sp.Ang."),
#else
            "Attacks with the power of\n"
            "the moon. May lower Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Moonblast,
    },

    [MOVE_BOOMBURST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Überschallknall"),
#else
        .name = COMPOUND_STRING("BOOMBURST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein gewaltiger Knall trifft\n"
            "alle Pkmn in der Umgebung."),
#else
            "Attacks everything with a\n"
            "destructive sound wave."),
#endif
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Boomburst,
    },

    [MOVE_FAIRY_LOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feenschloss"),
#else
        .name = COMPOUND_STRING("FAIRY LOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "In der nächsten Runde kann\n"
            "niemand fliehen."),
#else
            "Locks down the battlefield\n"
            "preventing escape next turn."),
#endif
        .effect = EFFECT_FAIRY_LOCK,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FairyLock,
    },

    [MOVE_KINGS_SHIELD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Königsschild"),
#else
        .name = COMPOUND_STRING("KING'S SHIELD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt und senkt den\n"
            "Angriff bei Berührung stark."),
#else
            "Evades damage, and sharply\n"
            "reduces Attack if struck."),
#endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_KINGS_SHIELD },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_KingsShield,
    },

    [MOVE_PLAY_NICE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kameradschaft"),
#else
        .name = COMPOUND_STRING("PLAY NICE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schließt Freundschaft und\n"
            "senkt den Angriff des Zieles."),
#else
            "Befriend the foe, lowering\n"
            "its Attack without fail."),
#endif
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_PLAY_NICE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PlayNice,
    },

    [MOVE_CONFIDE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Vertrauenssache"),
#else
        .name = COMPOUND_STRING("CONFIDE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Geheimnis stört das Ziel.\n"
            "Senkt dessen Sp.Ang."),
#else
            "Shares a secret with the\n"
            "foe, lowering Sp. Atk."),
#endif
        .effect = EFFECT_SPECIAL_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Confide,
    },

    [MOVE_DIAMOND_STORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Diamantsturm"),
#else
        .name = COMPOUND_STRING("DIAMOND STORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Diamantsturm. Erhöht\n"
            "evtl. die eigene Vert."),
#else
            "Whips up a storm of\n"
            "diamonds. May up Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = B_UPDATED_MOVE_DATA >= GEN_7 ? MOVE_EFFECT_DEF_PLUS_2:  MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DiamondStorm,
    },

    [MOVE_STEAM_ERUPTION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dampfschwall"),
#else
        .name = COMPOUND_STRING("STEAM ERUPTION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Siedend heißer Dampf.\n"
            "Verbrennt das Ziel eventuell."),
#else
            "Immerses the foe in heated\n"
            "steam. May inflict a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCALD},
        .battleAnimScript = gBattleAnimMove_SteamEruption,
    },

    [MOVE_HYPERSPACE_HOLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dimensionsloch"),
#else
        .name = COMPOUND_STRING("HYPERSPACE HOLE"),
#endif
        .description = sHyperspaceHoleDescription,
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HYPERSPACE_HOLE,
        .contestComboMoves = {COMBO_STARTER_HYPERSPACE_FURY},
        .battleAnimScript = gBattleAnimMove_HyperspaceHole,
    },

    [MOVE_WATER_SHURIKEN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wasser-Shuriken"),
#else
        .name = COMPOUND_STRING("WATER SHURIKEN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft zwei- bis fünfmal. Mit\n"
            "Erstschlaggarantie."),
#else
            "Throws 2 to 5 stars that\n"
            "are sure to strike first."),
#endif
        .effect = EFFECT_SPECIES_POWER_OVERRIDE,
        .power = 15,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = B_UPDATED_MOVE_DATA >= GEN_7 ? DAMAGE_CATEGORY_SPECIAL : DAMAGE_CATEGORY_PHYSICAL,
        .argument = {
            .speciesPowerOverride.species = SPECIES_GRENINJA_ASH,
            .speciesPowerOverride.power = 20,
            .speciesPowerOverride.numOfHits = 3
        },
        .multiHit = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WaterShuriken,
    },

    [MOVE_MYSTICAL_FIRE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Magieflamme"),
#else
        .name = COMPOUND_STRING("MYSTICAL FIRE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine heiße Flamme. Senkt den\n"
            "Sp.Ang. des Zieles."),
#else
            "Breathes a special, hot\n"
            "fire. Lowers Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 75 : 65,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MysticalFire,
    },

    [MOVE_SPIKY_SHIELD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schutzstacheln"),
#else
        .name = COMPOUND_STRING("SPIKY SHIELD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt und schadet bei\n"
            "Berührung dem Angreifer."),
#else
            "Evades attack, and damages\n"
            "the foe if struck."),
#endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_SPIKY_SHIELD },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpikyShield,
    },

    [MOVE_AROMATIC_MIST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Duftwolke"),
#else
        .name = COMPOUND_STRING("AROMATIC MIST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht die Sp.Vert. eines\n"
            "Mitstreiters."),
#else
            "Raises the Sp. Def of a\n"
            "partner Pokémon."),
#endif
        .effect = EFFECT_AROMATIC_MIST,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AromaticMist,
    },

    [MOVE_EERIE_IMPULSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mystowellen"),
#else
        .name = COMPOUND_STRING("EERIE IMPULSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Mysteriöse Wellen senken den\n"
            "Sp.Ang. des Zieles stark."),
#else
            "Exposes the foe to a pulse\n"
            "that sharply cuts Sp. Atk."),
#endif
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_EerieImpulse,
    },

    [MOVE_VENOM_DRENCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftfalle"),
#else
        .name = COMPOUND_STRING("VENOM DRENCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt Angriff, Sp.Ang. und\n"
            "Init. vergifteter Ziele."),
#else
            "Lowers the Attack, Sp. Atk\n"
            "and Speed of poisoned foes."),
#endif
        .effect = EFFECT_VENOM_DRENCH,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC, COMBO_STARTER_POISON_GAS, COMBO_STARTER_POISON_POWDER, COMBO_STARTER_TOXIC_SPIKES},
        .battleAnimScript = gBattleAnimMove_VenomDrench,
    },

    [MOVE_POWDER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pulverschleuder"),
#else
        .name = COMPOUND_STRING("POWDER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Setzt das Ziel eine Feuer--\n"
            "Att. ein, nimmt es Schaden."),
#else
            "Damages the foe if it uses\n"
            "a Fire-type move."),
#endif
        .effect = EFFECT_POWDER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .powderMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Powder,
    },

    [MOVE_GEOMANCY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Geokontrolle"),
#else
        .name = COMPOUND_STRING("GEOMANCY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht in Runde 2 Sp.Ang.,\n"
            "Sp.Vert. und Init."),
#else
            "Raises Sp. Atk, Sp. Def and\n"
            "Speed on the 2nd turn."),
#endif
        .effect = EFFECT_GEOMANCY,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .skyBattleBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKNMABSORBINGPOWER },
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Geomancy,
    },

    [MOVE_MAGNETIC_FLUX] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Magnetregler"),
#else
        .name = COMPOUND_STRING("MAGNETIC FLUX"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht Vert. und Sp.Vert. von\n"
            "Plus- und Minus-Trägern."),
#else
            "Boosts the defenses of\n"
            "those with Plus or Minus."),
#endif
        .effect = EFFECT_MAGNETIC_FLUX,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagneticFlux,
    },

    [MOVE_HAPPY_HOUR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Goldene Zeiten"),
#else
        .name = COMPOUND_STRING("HAPPY HOUR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verdoppelt das Preisgeld\n"
            "nach einem Sieg."),
#else
            "Doubles the amount of\n"
            "Prize Money received."),
#endif
        .effect = EFFECT_HAPPY_HOUR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_HAPPY_HOUR,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HappyHour,
    },

    [MOVE_ELECTRIC_TERRAIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Elektrofeld"),
#else
        .name = COMPOUND_STRING("ELECTRIC TERRAIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Boden wird 5 Runden elek-\n"
            "trisch. Verhindert Schlaf."),
#else
            "Electrifies the ground for\n"
            "5 turns. Prevents sleep."),
#endif
        .effect = EFFECT_ELECTRIC_TERRAIN,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_ELECTRIC_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ElectricTerrain,
    },

    [MOVE_DAZZLING_GLEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zauberschein"),
#else
        .name = COMPOUND_STRING("DAZZLING GLEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein mächtiger Lichtblitz, der\n"
            "dem Ziel schadet."),
#else
            "Damages foes by emitting\n"
            "a bright flash."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DazzlingGleam,
    },

    [MOVE_CELEBRATE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ehrentag"),
#else
        .name = COMPOUND_STRING("CELEBRATE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gratuliert dir zu deinem\n"
            "besonderen Tag."),
#else
            "Congratulates you on your\n"
            "special day."),
#endif
        .effect = EFFECT_CELEBRATE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_CELEBRATE,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Celebrate,
    },

    [MOVE_HOLD_HANDS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Händchenhalten"),
#else
        .name = COMPOUND_STRING("HOLD HANDS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender und Mitstreiter\n"
            "reichen einander die Hände."),
#else
            "The user and ally hold hands\n"
            "making them happy."),
#endif
        .effect = EFFECT_HOLD_HANDS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HoldHands,
    },

    [MOVE_BABY_DOLL_EYES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kulleraugen"),
#else
        .name = COMPOUND_STRING("BABY-DOLL EYES"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt den Angriff des Zieles.\n"
            "Trifft immer zuerst."),
#else
            "Lowers the foe's Attack\n"
            "before it can move."),
#endif
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BabyDollEyes,
    },

    [MOVE_NUZZLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wangenrubbler"),
#else
        .name = COMPOUND_STRING("NUZZLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Reibt geladene Wangen am\n"
            "Ziel. Paralysiert es."),
#else
            "Rubs its cheeks against\n"
            "the foe, paralyzing it."),
#endif
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_Nuzzle,
    },

    [MOVE_HOLD_BACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zurückhaltung"),
#else
        .name = COMPOUND_STRING("HOLD BACK"),
#endif
        .description = sFalseSwipeDescription,
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS, //CONTEST_EFFECT_QUICKLY_GROW_BORED
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HoldBack,
    },

    [MOVE_INFESTATION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Plage"),
#else
        .name = COMPOUND_STRING("INFESTATION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Befällt und attackiert den\n"
            "Gegner, "BINDING_TURNS" Runden."),
#else
            "The foe is infested and\n"
            "attacked for "BINDING_TURNS" turns."),
#endif
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_INFESTATION,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Infestation,
    },

    [MOVE_POWER_UP_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Steigerungshieb"),
#else
        .name = COMPOUND_STRING("POWER-UP PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein harter Schlag. Erhöht den\n"
            "eigenen Angriff."),
#else
            "A hard punch that raises\n"
            "the user's Attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerUpPunch,
    },

    [MOVE_OBLIVION_WING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Unheilsschwingen"),
#else
        .name = COMPOUND_STRING("OBLIVION WING"),
#endif
        .description = sDrainingKissDescription,
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 75 },
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OblivionWing,
    },

    [MOVE_THOUSAND_ARROWS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tausend Pfeile"),
#else
        .name = COMPOUND_STRING("THOUSAND ARROWS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft auch fliegende Ziele\n"
            "und holt sie herunter."),
#else
            "Can hit Flying foes, then\n"
            "knocks them to the ground."),
#endif
        .effect = EFFECT_SMACK_DOWN,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesAirborne = TRUE,
        .ignoreTypeIfFlyingAndUngrounded = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTIFUL,
        .contestComboStarterId = COMBO_STARTER_THOUSAND_ARROWS,
        .contestComboMoves = {COMBO_STARTER_THOUSAND_WAVES},
        .battleAnimScript = gBattleAnimMove_ThousandArrows,
    },

    [MOVE_THOUSAND_WAVES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tausend Wellen"),
#else
        .name = COMPOUND_STRING("THOUSAND WAVES"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Getroffene Ziele können\n"
            "nicht mehr fliehen."),
#else
            "Those hit by the wave can\n"
            "no longer escape."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_THOUSAND_WAVES,
        .contestComboMoves = {COMBO_STARTER_THOUSAND_ARROWS},
        .battleAnimScript = gBattleAnimMove_ThousandWaves,
    },

    [MOVE_LANDS_WRATH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bodengewalt"),
#else
        .name = COMPOUND_STRING("LAND'S WRATH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Kraft des Landes trifft\n"
            "alle Gegner."),
#else
            "Gathers the energy of the\n"
            "land to attack every foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LandsWrath,
    },

    [MOVE_LIGHT_OF_RUIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lux Calamitatis"),
#else
        .name = COMPOUND_STRING("LIGHT OF RUIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Lichtstrahl. Der Anwender\n"
            "nimmt Rückstoß-Schaden."),
#else
            "Fires a great beam of light\n"
            "that also hurts the user."),
#endif
        .effect = EFFECT_RECOIL,
        .power = 140,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .recoilPercentage = 50 },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LightOfRuin,
    },

    [MOVE_ORIGIN_PULSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ursprungswoge"),
#else
        .name = COMPOUND_STRING("ORIGIN PULSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Unzählige blau leuchtende\n"
            "Strahlen treffen die Ziele."),
#else
            "Beams of glowing blue light\n"
            "blast both foes."),
#endif
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_OriginPulse,
    },

    [MOVE_PRECIPICE_BLADES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Abgrundsklinge"),
#else
        .name = COMPOUND_STRING("PRECIPICE BLADES"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Klingen aus der Kraft des\n"
            "Erdreichs treffen die Ziele."),
#else
            "Fearsome blades of stone\n"
            "attack both foes."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_LAST
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PrecipiceBlades,
    },

    [MOVE_DRAGON_ASCENT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zenitstürmer"),
#else
        .name = COMPOUND_STRING("DRAGON ASCENT"),
#endif
        .description = sCloseCombatDescription,
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonAscent,
    },

    [MOVE_HYPERSPACE_FURY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dimensionswahn"),
#else
        .name = COMPOUND_STRING("HYPERSPACE FURY"),
#endif
        .description = sHyperspaceHoleDescription,
        .effect = EFFECT_HYPERSPACE_FURY,
        .power = 100,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT, // TODO: Is this supposed to happen before the attack animation?
        },
        {
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING, //CONTEST_EFFECT_EXCITES_AUDIENCE_MORE_IF_FIRST
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_HYPERSPACE_FURY,
        .contestComboMoves = {COMBO_STARTER_HYPERSPACE_HOLE},
        .battleAnimScript = gBattleAnimMove_HyperspaceFury,
    },

    [MOVE_SHORE_UP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sandsammler"),
#else
        .name = COMPOUND_STRING("SHORE UP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt halbe max. KP auf, im\n"
            "Sandsturm mehr."),
#else
            "Restores the user's HP.\n"
            "More HP in a sandstorm."),
#endif
        .effect = EFFECT_SHORE_UP,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
        .battleAnimScript = gBattleAnimMove_ShoreUp,
    },

    [MOVE_FIRST_IMPRESSION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Überrumpler"),
#else
        .name = COMPOUND_STRING("FIRST IMPRESSION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr stark, gelingt aber nur\n"
            "in der ersten Runde."),
#else
            "Hits hard and first.\n"
            "Only works first turn."),
#endif
        .effect = EFFECT_FIRST_TURN_ONLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .moveProperty = MOVE_FIRST_IMPRESSION },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FirstImpression,
    },

    [MOVE_BANEFUL_BUNKER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Bunker"),
#else
        .name = COMPOUND_STRING("BANEFUL BUNKER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt und vergiftet\n"
            "Angreifer bei Berührung."),
#else
            "Protects user and poisons\n"
            "foes on contact."),
#endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_BANEFUL_BUNKER },
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BanefulBunker,
    },

    [MOVE_SPIRIT_SHACKLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schattenfessel"),
#else
        .name = COMPOUND_STRING("SPIRIT SHACKLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Näht den Schatten fest. Das\n"
            "Ziel kann nicht fliehen."),
#else
            "After being hit, foes can\n"
            "no longer escape."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpiritShackle,
    },

    [MOVE_DARKEST_LARIAT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dark Lariat"),
#else
        .name = COMPOUND_STRING("DARKEST LARIAT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schadet trotz\n"
            "Statusänderungen des Zieles."),
#else
            "Swings the arms to strike\n"
            "It ignores stat changes."),
#endif
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DarkestLariat,
    },

    [MOVE_SPARKLING_ARIA] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schaumserenade"),
#else
        .name = COMPOUND_STRING("SPARKLING ARIA"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt Verbrennungen aller\n"
            "Pkmn, die Schaden nehmen."),
#else
            "Sings with bubbles. Cures\n"
            "burns on contact."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_BURN },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
            .sheerForceOverride = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCALD},
        .battleAnimScript = gBattleAnimMove_SparklingAria,
    },

    [MOVE_ICE_HAMMER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eishammer"),
#else
        .name = COMPOUND_STRING("ICE HAMMER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein starker Hieb. Senkt die\n"
            "Init. des Anwenders."),
#else
            "Swings the fist to strike.\n"
            "Lowers the user's Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_IceHammer,
    },

    [MOVE_FLORAL_HEALING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Florakur"),
#else
        .name = COMPOUND_STRING("FLORAL HEALING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt halbe max. KP des Zieles\n"
            "auf, auf Gras mehr."),
#else
            "Restores an ally's HP.\n"
            "Heals more on grass."),
#endif
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .argument = { .moveProperty = MOVE_EFFECT_FLORAL_HEALING },
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FloralHealing,
    },

    [MOVE_HIGH_HORSEPOWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pferdestärke"),
#else
        .name = COMPOUND_STRING("HIGH HORSEPOWER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine heftige Attacke mit\n"
            "vollem Körpereinsatz."),
#else
            "Slams hard into the foe with\n"
            "its entire body."),
#endif
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HighHorsepower,
    },

    [MOVE_STRENGTH_SAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kraftabsorber"),
#else
        .name = COMPOUND_STRING("STRENGTH SAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt um den Angriff des\n"
            "Zieles und senkt diesen."),
#else
            "Saps the foe's Attack to\n"
            "heal HP, then drops Attack."),
#endif
        .effect = EFFECT_STRENGTH_SAP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StrengthSap,
    },

    [MOVE_SOLAR_BLADE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Solarklinge"),
#else
        .name = COMPOUND_STRING("SOLAR BLADE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sammelt in Runde 1 Licht,\n"
            "trifft in Runde 2."),
#else
            "Charges first turn, then\n"
            "chops with a blade of light."),
#endif
        .effect = EFFECT_SOLAR_BEAM,
        .power = 125,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_PKMNTOOKSUNLIGHT, .weather = B_WEATHER_SUN },
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_SolarBlade,
    },

    [MOVE_LEAFAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blattwerk"),
#else
        .name = COMPOUND_STRING("LEAFAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift das Ziel mit Blättern\n"
            "an."),
#else
            "Attacks with a flurry of\n"
            "small leaves."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
        .battleAnimScript = gBattleAnimMove_Leafage,
    },

    [MOVE_SPOTLIGHT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rampenlicht"),
#else
        .name = COMPOUND_STRING("SPOTLIGHT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "In dieser Runde greifen alle\n"
            "nur dieses Ziel an."),
#else
            "Makes the foe attack the\n"
            "spotlighted Pokémon."),
#endif
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Spotlight,
    },

    [MOVE_TOXIC_THREAD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftfaden"),
#else
        .name = COMPOUND_STRING("TOXIC THREAD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Giftige Fäden vergiften und\n"
            "senken die Init."),
#else
            "Attacks with a thread that\n"
            "poisons and drops Speed."),
#endif
        .effect = EFFECT_TOXIC_THREAD,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC},
        .battleAnimScript = gBattleAnimMove_ToxicThread,
    },

    [MOVE_LASER_FOCUS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Konzentration"),
#else
        .name = COMPOUND_STRING("LASER FOCUS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der nächste Angriff wird\n"
            "sicher ein Volltreffer."),
#else
            "Guarantees the next move\n"
            "will be a critical hit."),
#endif
        .effect = EFFECT_LASER_FOCUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LaserFocus,
    },

    [MOVE_GEAR_UP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hilfsmechanik"),
#else
        .name = COMPOUND_STRING("GEAR UP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht Angriff und Sp.Ang.\n"
            "von Plus- und Minus-Trägern."),
#else
            "Boosts the attacks of\n"
            "those with Plus or Minus."),
#endif
        .effect = EFFECT_GEAR_UP,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GearUp,
    },

    [MOVE_THROAT_CHOP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Neck Strike"),
#else
        .name = COMPOUND_STRING("THROAT CHOP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel kann 2 Runden keine\n"
            "Schall-Att. einsetzen."),
#else
            "Chops the throat to disable\n"
            "sound moves for 2 turns."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THROAT_CHOP,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ThroatChop,
    },

    [MOVE_POLLEN_PUFF] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pollenknödel"),
#else
        .name = COMPOUND_STRING("POLLEN PUFF"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schadet Gegnern, heilt\n"
            "dagegen Mitstreiter."),
#else
            "Explodes on foes, but\n"
            "restores ally's HP."),
#endif
        .effect = EFFECT_HIT_ENEMY_HEAL_ALLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PollenPuff,
    },

    [MOVE_ANCHOR_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ankerschuss"),
#else
        .name = COMPOUND_STRING("ANCHOR SHOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Ankerkette hält das Ziel\n"
            "fest. Es kann nicht fliehen."),
#else
            "Strangles the foe with a\n"
            "chain. The foe can't escape."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AnchorShot,
    },

    [MOVE_PSYCHIC_TERRAIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psychofeld"),
#else
        .name = COMPOUND_STRING("PSYCHIC TERRAIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt 5 Runden vor Atta-\n"
            "cken mit Erstschlagquote."),
#else
            "The ground turns weird for\n"
            "5 turns. Blocks priority."),
#endif
        .effect = EFFECT_PSYCHIC_TERRAIN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PSYCHIC_TERRAIN,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychicTerrain,
    },

    [MOVE_LUNGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Anfallen"),
#else
        .name = COMPOUND_STRING("LUNGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Angriff mit ganzer Kraft.\n"
            "Senkt den Angriff des Zieles."),
#else
            "Lunges at the foe to lower\n"
            "its Attack stat."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Lunge,
    },

    [MOVE_FIRE_LASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feuerpeitsche"),
#else
        .name = COMPOUND_STRING("FIRE LASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine brennende Peitsche.\n"
            "Senkt die Vert. des Zieles."),
#else
            "Whips the foe with fire\n"
            "lowering its Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_FireLash,
    },

    [MOVE_POWER_TRIP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Überheblichkeit"),
#else
        .name = COMPOUND_STRING("POWER TRIP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je höher die eigenen Werte,\n"
            "desto stärker."),
#else
            "It hits harder the more\n"
            "stat boosts the user has."),
#endif
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PowerTrip,
    },

    [MOVE_BURN_UP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ausbrennen"),
#else
        .name = COMPOUND_STRING("BURN UP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr stark. Der Anwender\n"
            "verliert den Typ Feuer."),
#else
            "Burns out the user fully\n"
            "removing the Fire type."),
#endif
        .effect = EFFECT_FAIL_IF_NOT_ARG_TYPE,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .argument = { .type = TYPE_FIRE },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_ARG_TYPE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
        .battleAnimScript = gBattleAnimMove_BurnUp,
    },

    [MOVE_SPEED_SWAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Initiativetausch"),
#else
        .name = COMPOUND_STRING("SPEED SWAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Tauscht die Init. mit der des\n"
            "Zieles."),
#else
            "Swaps user's Speed with\n"
            "the target's."),
#endif
        .effect = EFFECT_SPEED_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpeedSwap,
    },

    [MOVE_SMART_STRIKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schmalhorn"),
#else
        .name = COMPOUND_STRING("SMART STRIKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein spitzes Horn durchbohrt\n"
            "das Ziel. Trifft immer."),
#else
            "Hits with an accurate\n"
            "horn that never misses."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SmartStrike,
    },

    [MOVE_PURIFY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Läuterung"),
#else
        .name = COMPOUND_STRING("PURIFY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt das Statusproblem des\n"
            "Zieles. Füllt eigene KP auf."),
#else
            "Cures the foe's status\n"
            "to restore HP."),
#endif
        .effect = EFFECT_PURIFY,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Purify,
    },

    [MOVE_REVELATION_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wecktanz"),
#else
        .name = COMPOUND_STRING("REVELATION DANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Typ entspricht dem des\n"
            "Anwenders."),
#else
            "Dances with mystical power.\n"
            "Matches user's first type."),
#endif
        .effect = EFFECT_REVELATION_DANCE,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RevelationDance,
    },

    [MOVE_CORE_ENFORCER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sanktionskern"),
#else
        .name = COMPOUND_STRING("CORE ENFORCER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hat das Ziel schon gehandelt,\n"
            "verliert es seine Fähigkeit."),
#else
            "Hits with a ray that\n"
            "nullifies the foe's Ability."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 140 },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CORE_ENFORCER,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CoreEnforcer,
    },

    [MOVE_TROP_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tropenkick"),
#else
        .name = COMPOUND_STRING("TROP KICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein heftiger Tritt. Senkt den\n"
            "Angriff des Zieles."),
#else
            "An intense kick from the\n"
            "tropics. Lowers Attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TropKick,
    },

    [MOVE_INSTRUCT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kommando"),
#else
        .name = COMPOUND_STRING("INSTRUCT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel setzt seine letzte\n"
            "Attacke sofort erneut ein."),
#else
            "Orders the target to use\n"
            "its last move again."),
#endif
        .effect = EFFECT_INSTRUCT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Instruct,
    },

    [MOVE_BEAK_BLAST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schnabelkanone"),
#else
        .name = COMPOUND_STRING("BEAK BLAST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhitzt den Schnabel.\n"
            "Verbrennt Angreifer dabei."),
#else
            "Heats beak to attack last.\n"
            "Burns foe on contact."),
#endif
        .effect = EFFECT_BEAK_BLAST,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = -3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .ballisticMove = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BeakBlast,
    },

    [MOVE_CLANGING_SCALES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schuppenrasseln"),
#else
        .name = COMPOUND_STRING("CLANGING SCALES"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein lautes Rasseln. Senkt die\n"
            "eigene Vert."),
#else
            "Makes a big noise with\n"
            "its scales. Drops Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ClangingScales,
    },

    [MOVE_DRAGON_HAMMER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drachenhammer"),
#else
        .name = COMPOUND_STRING("DRAGON HAMMER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Nutzt den Körper wie einen\n"
            "Hammer und stürzt sich herab."),
#else
            "Swings its whole body\n"
            "like a hammer to damage."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
        .battleAnimScript = gBattleAnimMove_DragonHammer,
    },

    [MOVE_BRUTAL_SWING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wirbler"),
#else
        .name = COMPOUND_STRING("BRUTAL SWING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein schwungvoller Angriff\n"
            "auf alle Pkmn in der Nähe."),
#else
            "Violently swings around\n"
            "to hurt everyone nearby."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BrutalSwing,
    },

    [MOVE_AURORA_VEIL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Auroraschleier"),
#else
        .name = COMPOUND_STRING("AURORA VEIL"),
#endif
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwächt alle Angriffe,\n"
            "nur bei Schnee nutzbar."),
#else
            "Weakens all attacks, but\n"
            "only usable with snow."),
#endif
        #elif B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_BOTH
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwächt alle Angriffe bei\n"
            "Hagel oder Schnee."),
#else
            "Weakens all attacks if\n"
            "used in hail or snow."),
#endif
        #else
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwächt alle Angriffe,\n"
            "nur bei Hagel nutzbar."),
#else
            "Weakens all attacks, but\n"
            "only usable with hail."),
#endif
        #endif
        .effect = EFFECT_AURORA_VEIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
        .battleAnimScript = gBattleAnimMove_AuroraVeil,
    },

    [MOVE_SHELL_TRAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Panzerfalle"),
#else
        .name = COMPOUND_STRING("SHELL TRAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Explodiert, wenn eine\n"
            "physische Attacke trifft."),
#else
            "Sets a shell trap that\n"
            "damages on contact."),
#endif
        .effect = EFFECT_SHELL_TRAP,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = -3,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShellTrap,
    },

    [MOVE_FLEUR_CANNON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kanonenbouquet"),
#else
        .name = COMPOUND_STRING("FLEUR CANNON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein gewaltiger Strahl. Senkt\n"
            "den eigenen Sp.Ang. stark."),
#else
            "A strong ray that harshly\n"
            "lowers Sp. Attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FleurCannon,
    },

    [MOVE_PSYCHIC_FANGS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psychobeißer"),
#else
        .name = COMPOUND_STRING("PSYCHIC FANGS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Biss, der auch Barrieren\n"
            "wie Reflektor durchbricht."),
#else
            "Chomps with psychic fangs.\n"
            "Destroys any barriers."),
#endif
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BREAK_SCREEN,
            .preAttackEffect = TRUE,
        }),
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PsychicFangs,
    },

    [MOVE_STOMPING_TANTRUM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fruststampfer"),
#else
        .name = COMPOUND_STRING("STOMPING TANTRUM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelt so stark, wenn die\n"
            "letzte Attacke misslang."),
#else
            "Stomps around angrily.\n"
            "Stronger after a failure."),
#endif
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StompingTantrum,
    },

    [MOVE_SHADOW_BONE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schattenknochen"),
#else
        .name = COMPOUND_STRING("SHADOW BONE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein beseelter Knochen. Senkt\n"
            "evtl. die Vert. des Zieles."),
#else
            "Strikes with a haunted\n"
            "bone. Might drop Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SHADOW_BONE,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH},
        .battleAnimScript = gBattleAnimMove_ShadowBone,
    },

    [MOVE_ACCELEROCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Turbofelsen"),
#else
        .name = COMPOUND_STRING("ACCELEROCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein schneller Aufprall. Hohe\n"
            "Erstschlagquote."),
#else
            "Hits with a high-speed\n"
            "rock that always goes first."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Accelerock,
    },

    [MOVE_LIQUIDATION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aquadurchstoß"),
#else
        .name = COMPOUND_STRING("LIQUIDATION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Kraft des Wassers. Senkt\n"
            "evtl. die Vert. des Zieles."),
#else
            "Slams the foe with water.\n"
            "Can lower Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
        .battleAnimScript = gBattleAnimMove_Liquidation,
    },

    [MOVE_PRISMATIC_LASER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Prisma-Laser"),
#else
        .name = COMPOUND_STRING("PRISMATIC LASER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Mächtige Lichtstrahlen.\n"
            "Nächste Runde Pause."),
#else
            "A high power laser that\n"
            "forces recharge next turn."),
#endif
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PrismaticLaser,
    },

    [MOVE_SPECTRAL_THIEF] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Diebesschatten"),
#else
        .name = COMPOUND_STRING("SPECTRAL THIEF"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stiehlt die erhöhten Werte\n"
            "des Zieles und greift an."),
#else
            "Steals the target's stat\n"
            "boosts, then attacks."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEAL_STATS,
            .preAttackEffect = TRUE,
        }),
        .ignoresSubstitute = TRUE,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpectralThief,
    },

    [MOVE_SUNSTEEL_STRIKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stahlgestirn"),
#else
        .name = COMPOUND_STRING("SUNSTEEL STRIKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft und ignoriert dabei\n"
            "die Fähigkeit des Zieles."),
#else
            "A sun-fueled strike that\n"
            "ignores abilities."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SunsteelStrike,
    },

    [MOVE_MOONGEIST_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schattenstrahl"),
#else
        .name = COMPOUND_STRING("MOONGEIST BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Lichtstrahl, der die Fä-\n"
            "higkeit des Zieles ignoriert."),
#else
            "A moon-powered beam that\n"
            "ignores abilities."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MoongeistBeam,
    },

    [MOVE_TEARFUL_LOOK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tränendrüse"),
#else
        .name = COMPOUND_STRING("TEARFUL LOOK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Blick mit Tränen. Senkt\n"
            "Angriff und Sp.Ang."),
#else
            "The user tears up, dropping\n"
            "Attack and Sp. Attack."),
#endif
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TearfulLook,
    },

    [MOVE_ZING_ZAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Elektropikser"),
#else
        .name = COMPOUND_STRING("ZING ZAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein starker Stromstoß. Das\n"
            "Ziel schreckt evtl. zurück."),
#else
            "An electrified impact that\n"
            "can cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
        .battleAnimScript = gBattleAnimMove_ZingZap,
    },

    [MOVE_NATURES_MADNESS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Naturzorn"),
#else
        .name = COMPOUND_STRING("NATURE'S MADNESS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel verliert die Hälfte\n"
            "seiner KP."),
#else
            "Halves the foe's HP with\n"
            "the power of nature."),
#endif
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .damagePercentage = 50 },
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NaturesMadness,
    },

    [MOVE_MULTI_ATTACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Multi-Angriff"),
#else
        .name = COMPOUND_STRING("MULTI-ATTACK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Typ hängt vom getragenen\n"
            "Erinnerung-Item ab."),
#else
            "Attack that changes\n"
            "with Memories."),
#endif
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 120 : 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .holdEffect = HOLD_EFFECT_MEMORY },
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MultiAttack,
    },

    [MOVE_MIND_BLOWN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Knallkopf"),
#else
        .name = COMPOUND_STRING("MIND BLOWN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft alle in der Nähe. Der\n"
            "Anwender verliert halbe KP."),
#else
            "It explodes the user's head\n"
            "to damage everything around."),
#endif
        .effect = EFFECT_MAX_HP_50_RECOIL,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .dampBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MindBlown,
    },

    [MOVE_PLASMA_FISTS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Plasmafäuste"),
#else
        .name = COMPOUND_STRING("PLASMA FISTS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Normal-Attacken nehmen den\n"
            "Typ Elektro an."),
#else
            "Hits with electrical fists.\n"
            "Normal moves turn Electric."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ION_DELUGE,
        }),
        .battleAnimScript = gBattleAnimMove_PlasmaFists,
    },

    [MOVE_PHOTON_GEYSER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Photonen-Geysir"),
#else
        .name = COMPOUND_STRING("PHOTON GEYSER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Nutzt den höheren der beiden\n"
            "Angriffswerte."),
#else
            "User's highest attack stat\n"
            "determines its category."),
#endif
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PhotonGeyser,
    },

    [MOVE_ZIPPY_ZAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Britzelturbo"),
#else
        .name = COMPOUND_STRING("ZIPPY ZAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "E-Ausbrüche treffen immer\n"
            "zuerst und stets kritisch."),
#else
            "Electric bursts always go\n"
            "first and land a critical hit."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .alwaysCriticalHit = TRUE,
        .metronomeBanned = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EVS_PLUS_1,
            .self = TRUE,
        }),
        #endif
        .battleAnimScript = gBattleAnimMove_ZippyZap,
    },

    [MOVE_SPLISHY_SPLASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Plätschersurfer"),
#else
        .name = COMPOUND_STRING("SPLISHY SPLASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine riesige E-Welle,\n"
            "kann Gegner paralysieren."),
#else
            "A huge electrified wave that\n"
            "may paralyze the foes."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_SplishySplash,
    },

    [MOVE_FLOATY_FALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schwebesturz"),
#else
        .name = COMPOUND_STRING("FLOATY FALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwebt in der Luft und\n"
            "taucht schräg ab. Schreckt."),
#else
            "Floats in air and dives at\n"
            "angle. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .gravityBanned = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_FloatyFall,
    },

    [MOVE_PIKA_PAPOW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pika-Flash"),
#else
        .name = COMPOUND_STRING("PIKA PAPOW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Pikachus Liebe erhöht\n"
            "die Stärke. Verfehlt nie."),
#else
            "Pikachu's love increases its\n"
            "power. It never misses."),
#endif
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_PikaPapow,
    },

    [MOVE_BOUNCY_BUBBLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blubbsauger"),
#else
        .name = COMPOUND_STRING("BOUNCY BUBBLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Angriff, der\n"
#else
            "Attack that absorbs\n"
#endif
        #if B_UPDATED_MOVE_DATA >= GEN_8
#if GERMAN
            "allen Schaden absorbiert."),
#else
            "all the damage inflicted."),
#endif
        #else
#if GERMAN
            "die Hälfte des Schadens."),
#else
            "half the damage inflicted."),
#endif
        #endif
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 50 },
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .battleAnimScript = gBattleAnimMove_BouncyBubble,
    },

    [MOVE_BUZZY_BUZZ] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Knisterladung"),
#else
        .name = COMPOUND_STRING("BUZZY BUZZ"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schießt einen Stromstoß,\n"
            "der immer paralysiert."),
#else
            "Shoots a jolt of electricity\n"
            "that always paralyzes."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
        }),
        .battleAnimScript = gBattleAnimMove_BuzzyBuzz,
    },

    [MOVE_SIZZLY_SLIDE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flackerbrand"),
#else
        .name = COMPOUND_STRING("SIZZLY SLIDE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der in Flammen gehüllte\n"
            "Nutzer verbrennt Gegner."),
#else
            "User cloaked in fire charges.\n"
            "Leaves the foe with a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .thawsUser = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
        }),
        .battleAnimScript = gBattleAnimMove_SizzlySlide,
    },

    [MOVE_GLITZY_GLOW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pulsieraura"),
#else
        .name = COMPOUND_STRING("GLITZY GLOW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Telekinetische Kraft\n"
            "senkt Sp.Ang. per Wand."),
#else
            "Telekinetic force that sets\n"
            "wall, lowering Sp. Atk damage."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 90,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 95 : 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LIGHT_SCREEN,
        }),
        .battleAnimScript = gBattleAnimMove_GlitzyGlow,
    },

    [MOVE_BADDY_BAD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Quälzone"),
#else
        .name = COMPOUND_STRING("BADDY BAD"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Handelt böse, greift an.\n"
            "Senkt Angriff per Wand."),
#else
            "Acting badly, attacks. Sets\n"
            "wall, lowering Attack damage."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 90,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 95 : 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REFLECT,
        }),
        .battleAnimScript = gBattleAnimMove_BaddyBad,
    },

    [MOVE_SAPPY_SEED] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sprießbomben"),
#else
        .name = COMPOUND_STRING("SAPPY SEED"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Riesenstängel streut\n"
            "Samen, saugen KP pro Runde."),
#else
            "Giant stalk scatters seeds\n"
            "that drain HP every turn."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 90,
        .type = TYPE_GRASS,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 90 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .magicCoatAffected = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LEECH_SEED,
        }),
        .battleAnimScript = gBattleAnimMove_SappySeed,
    },

    [MOVE_FREEZY_FROST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Klirrfrost"),
#else
        .name = COMPOUND_STRING("FREEZY FROST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristalle treffen und\n"
            "setzen Status zurück."),
#else
            "Crystal from cold haze hits.\n"
            "Eliminates all stat changes."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 90,
        .type = TYPE_ICE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 90 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_HAZE,
        }),
        .battleAnimScript = gBattleAnimMove_FreezyFrost,
    },

    [MOVE_SPARKLY_SWIRL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Glitzersturm"),
#else
        .name = COMPOUND_STRING("SPARKLY SWIRL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Umhüllt Gegner mit einem\n"
            "Duft. Heilt Team-Status."),
#else
            "Wrap foe with whirlwind of\n"
            "scent. Heals party's status."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 120 : 90,
        .type = TYPE_FAIRY,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 85 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 5 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_AROMATHERAPY,
        }),
        .battleAnimScript = gBattleAnimMove_SparklySwirl,
    },

    [MOVE_VEEVEE_VOLLEY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Evo-Crash"),
#else
        .name = COMPOUND_STRING("VEEVEE VOLLEY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Evolis Liebe erhöht\n"
            "die Stärke. Verfehlt nie."),
#else
            "Eevee's love increases its\n"
            "power. It never misses."),
#endif
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_VeeveeVolley,
    },

    [MOVE_DOUBLE_IRON_BASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Panzerfäuste"),
#else
        .name = COMPOUND_STRING("DOUBLE IRON BASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Dreht sich und schlägt mit\n"
            "den Armen. Kann schrecken."),
#else
            "The user spins and hits with\n"
            "its arms. May cause flinch."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .strikeCount = 2,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DoubleIronBash,
    },

    [MOVE_DYNAMAX_CANNON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dynamax-Kanone"),
#else
        .name = COMPOUND_STRING("DYNAMAX CANNON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gebündelte Energie. Doppelt\n"
            "gegen Dynamax-Gegner."),
#else
            "Unleashes core energy.\n"
            "2x against Dynamaxed foes."),
#endif
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mimicBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DynamaxCannon,
    },

    [MOVE_SNIPE_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Präzisionsschuss"),
#else
        .name = COMPOUND_STRING("SNIPE SHOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft das gewählte Ziel\n"
            "trotz Umleitung."),
#else
            "The user ignores effects\n"
            "that draw in moves."),
#endif
        .effect = EFFECT_SNIPE_SHOT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SnipeShot,
    },

    [MOVE_JAW_LOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fesselbiss"),
#else
        .name = COMPOUND_STRING("JAW LOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Anwender und Ziel können\n"
            "nicht ausgewechselt werden."),
#else
            "Prevents the user and\n"
            "the target from escaping."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TRAP_BOTH,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_JawLock,
    },

    [MOVE_STUFF_CHEEKS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Backenstopfer"),
#else
        .name = COMPOUND_STRING("STUFF CHEEKS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Frisst die Beere. Erhöht die\n"
            "Vert. stark."),
#else
            "Consumes the user's Berry,\n"
            "then sharply raises Def."),
#endif
        .effect = EFFECT_STUFF_CHEEKS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StuffCheeks,
    },

    [MOVE_NO_RETREAT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Finalformation"),
#else
        .name = COMPOUND_STRING("NO RETREAT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht alle eigenen Werte,\n"
            "verhindert aber Flucht."),
#else
            "Raises all of the user's\n"
            "stats but prevents escape."),
#endif
        .effect = EFFECT_NO_RETREAT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_NoRetreat,
    },

    [MOVE_TAR_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Teerschuss"),
#else
        .name = COMPOUND_STRING("TAR SHOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt die Init. Das Ziel wird\n"
            "anfällig für Feuer."),
#else
            "Lowers the foe's Speed and\n"
            "makes it weak to Fire."),
#endif
        .effect = EFFECT_TAR_SHOT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TarShot,
    },

    [MOVE_MAGIC_POWDER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Magiepuder"),
#else
        .name = COMPOUND_STRING("MAGIC POWDER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel nimmt den Typ Psycho\n"
            "an."),
#else
            "Magic powder changes the\n"
            "target into a Psychic type."),
#endif
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .type = TYPE_PSYCHIC },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MagicPowder,
    },

    [MOVE_DRAGON_DARTS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drachenpfeile"),
#else
        .name = COMPOUND_STRING("DRAGON DARTS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift zweimal an. Bei zwei\n"
            "Zielen je einmal."),
#else
            "The user attacks twice. Two\n"
            "targets are hit once each."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SMART,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .strikeCount = 2,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonDarts,
    },

    [MOVE_TEATIME] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Teatime"),
#else
        .name = COMPOUND_STRING("TEATIME"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Alle am Kampf beteiligten\n"
            "Pkmn essen ihre Beere."),
#else
            "All Pokémon have teatime\n"
            "and eat their Berries."),
#endif
        .effect = EFFECT_TEATIME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Teatime,
    },

    [MOVE_OCTOLOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Octoklammer"),
#else
        .name = COMPOUND_STRING("OCTOLOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel kann nicht fliehen.\n"
            "Senkt Vert. und Sp.Vert."),
#else
            "Traps the foe to lower Def\n"
            "and Sp. Def each turn."),
#endif
        .effect = EFFECT_OCTOLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Octolock,
    },

    [MOVE_BOLT_BEAK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schockschnabel"),
#else
        .name = COMPOUND_STRING("BOLT BEAK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelt stark, wenn der\n"
            "Anwender vor dem Ziel zieht."),
#else
            "Double power if the user\n"
            "moves before the target."),
#endif
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BoltBeak,
    },

    [MOVE_FISHIOUS_REND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kiemenbiss"),
#else
        .name = COMPOUND_STRING("FISHIOUS REND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelt stark, wenn der\n"
            "Anwender vor dem Ziel zieht."),
#else
            "Double power if the user\n"
            "moves before the target."),
#endif
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FishiousRend,
    },

    [MOVE_COURT_CHANGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Seitenwechsel"),
#else
        .name = COMPOUND_STRING("COURT CHANGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Tauscht die Effekte beider\n"
            "Feldseiten."),
#else
            "The user swaps effects on\n"
            "either side of the field."),
#endif
        .effect = EFFECT_COURT_CHANGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CourtChange,
    },

    [MOVE_CLANGOROUS_SOUL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Seelentanz"),
#else
        .name = COMPOUND_STRING("CLANGOROUS SOUL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kostet KP und erhöht dafür\n"
            "alle eigenen Werte."),
#else
            "The user uses some of its\n"
            "HP to raise all its stats."),
#endif
        .effect = EFFECT_CLANGOROUS_SOUL,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .danceMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ClangorousSoul,
    },

    [MOVE_BODY_PRESS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Body Press"),
#else
        .name = COMPOUND_STRING("BODY PRESS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je höher die eigene Vert.,\n"
            "desto mehr Schaden."),
#else
            "Does more damage the\n"
            "higher the user's Def."),
#endif
        .effect = EFFECT_BODY_PRESS,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BodyPress,
    },

    [MOVE_DECORATE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Verzierung"),
#else
        .name = COMPOUND_STRING("DECORATE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht Angriff und Sp.Ang.\n"
            "des Zieles stark."),
#else
            "The user sharply raises\n"
            "the target's Atk and Sp.Atk."),
#endif
        .effect = EFFECT_DECORATE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Decorate,
    },

    [MOVE_DRUM_BEATING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Trommelschläge"),
#else
        .name = COMPOUND_STRING("DRUM BEATING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wurzeln greifen an. Senkt die\n"
            "Init. des Zieles."),
#else
            "Plays a drum to attack.\n"
            "The foe's Speed is lowered."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DrumBeating,
    },

    [MOVE_SNAP_TRAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fangeisen"),
#else
        .name = COMPOUND_STRING("SNAP TRAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hält das Ziel 4 bis 5 Runden\n"
            "in einem Fangeisen fest."),
#else
            "Snares the target in a snap\n"
            "trap for four to five turns."),
#endif
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_SNAP_TRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SnapTrap,
    },

    [MOVE_PYRO_BALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feuerball"),
#else
        .name = COMPOUND_STRING("PYRO BALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Ball aus Feuer. Verbrennt\n"
            "das Ziel eventuell."),
#else
            "Launches a fiery ball at the\n"
            "target. It may cause a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .thawsUser = TRUE,
        .ballisticMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_PyroBall,
    },

    [MOVE_BEHEMOTH_BLADE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gigantenhieb"),
#else
        .name = COMPOUND_STRING("BEHEMOTH BLADE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelter Schaden gegen\n"
            "dynamaximierte Ziele."),
#else
            "Strikes as a sword. Deals 2x\n"
            "damage to Dynamaxed foes."),
#endif
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BehemothBlade,
    },

    [MOVE_BEHEMOTH_BASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gigantenstoß"),
#else
        .name = COMPOUND_STRING("BEHEMOTH BASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelter Schaden gegen\n"
            "dynamaximierte Ziele."),
#else
            "Attacks as a shield. Deals 2x\n"
            "damage to Dynamaxed foes."),
#endif
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BehemothBash,
    },

    [MOVE_AURA_WHEEL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aura-Rad"),
#else
        .name = COMPOUND_STRING("AURA WHEEL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht die Init. Der Typ\n"
            "hängt von der Form ab."),
#else
            "Raises Speed to attack. The\n"
            "Type is based on its form."),
#endif
        .effect = EFFECT_AURA_WHEEL,
        .power = 110,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AuraWheel,
    },

    [MOVE_BREAKING_SWIPE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Breitseite"),
#else
        .name = COMPOUND_STRING("BREAKING SWIPE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Schweifhieb. Senkt den\n"
            "Angriff der Ziele."),
#else
            "Swings its tail to attack.\n"
            "Lowers the Atk of those hit."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BreakingSwipe,
    },

    [MOVE_BRANCH_POKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zweigstoß"),
#else
        .name = COMPOUND_STRING("BRANCH POKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift das Ziel mit einem\n"
            "spitzen Zweig an."),
#else
            "The user pokes the target\n"
            "with a pointed branch."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BranchPoke,
    },

    [MOVE_OVERDRIVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Overdrive"),
#else
        .name = COMPOUND_STRING("OVERDRIVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Dröhnende Vibrationen\n"
            "treffen alle Gegner."),
#else
            "The user twangs its guitar,\n"
            "causing strong vibrations."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Overdrive,
    },

    [MOVE_APPLE_ACID] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Apfelsäure"),
#else
        .name = COMPOUND_STRING("APPLE ACID"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Saure Flüssigkeit. Senkt die\n"
            "Sp.Vert. des Zieles."),
#else
            "Attacks with tart apple acid\n"
            "to lower the foe's Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AppleAcid,
    },

    [MOVE_GRAV_APPLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gravitation"),
#else
        .name = COMPOUND_STRING("GRAV APPLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Apfel von oben. Senkt die\n"
            "Vert. des Zieles."),
#else
            "Drops an apple from above.\n"
            "Lowers the foe's Defense."),
#endif
        .effect = EFFECT_GRAV_APPLE,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GravApple,
    },

    [MOVE_SPIRIT_BREAK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Seelenbruch"),
#else
        .name = COMPOUND_STRING("SPIRIT BREAK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein wuchtiger Treffer. Senkt\n"
            "den Sp.Ang. des Zieles."),
#else
            "Attacks with spirit-breaking\n"
            "force. Lowers Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SpiritBreak,
    },

    [MOVE_STRANGE_STEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wunderdampf"),
#else
        .name = COMPOUND_STRING("STRANGE STEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Seltsamer Dampf. Verwirrt das\n"
            "Ziel eventuell."),
#else
            "Emits a strange steam to\n"
            "potentially confuse the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_StrangeSteam,
    },

    [MOVE_LIFE_DEW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lebenstropfen"),
#else
        .name = COMPOUND_STRING("LIFE DEW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt die KP des Anwenders\n"
            "und der Mitstreiter."),
#else
            "Scatters water to restore\n"
            "the HP of itself and allies."),
#endif
        .effect = EFFECT_LIFE_DEW,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LifeDew,
    },

    [MOVE_OBSTRUCT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Abblocker"),
#else
        .name = COMPOUND_STRING("OBSTRUCT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt und senkt bei\n"
            "Berührung die Vert. stark."),
#else
            "Protects itself, harshly\n"
            "lowering Def on contact."),
#endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_OBSTRUCT },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Obstruct,
    },

    [MOVE_FALSE_SURRENDER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kniefalltrick"),
#else
        .name = COMPOUND_STRING("FALSE SURRENDER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Stich mit dem Haar, der in\n"
            "jedem Fall trifft."),
#else
            "Bows to stab the foe\n"
            "with hair. It never misses."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FalseSurrender,
    },

    [MOVE_METEOR_ASSAULT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sternensturm"),
#else
        .name = COMPOUND_STRING("METEOR ASSAULT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr stark. Der Anwender\n"
            "muss danach aussetzen."),
#else
            "Attacks with a thick leek.\n"
            "The user must then rest."),
#endif
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeteorAssault,
    },

    [MOVE_ETERNABEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Unendynastrahlen"),
#else
        .name = COMPOUND_STRING("ETERNABEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr stark. Der Anwender\n"
            "muss danach aussetzen."),
#else
            "Eternatus' strongest move.\n"
            "The user rests next turn."),
#endif
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Eternabeam,
    },

    [MOVE_STEEL_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stahlstrahl"),
#else
        .name = COMPOUND_STRING("STEEL BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Stahlstrahl. Der Anwender\n"
            "erleidet Schaden."),
#else
            "Fires a beam of steel from\n"
            "its body. It hurts the user."),
#endif
        .effect = EFFECT_MAX_HP_50_RECOIL,
        .power = 140,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SteelBeam,
    },

    [MOVE_EXPANDING_FORCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flächenmacht"),
#else
        .name = COMPOUND_STRING("EXPANDING FORCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Auf dem Psychofeld stärker\n"
            "und trifft alle Gegner."),
#else
            "Power goes up and damages\n"
            "all foes on Psychic Terrain."),
#endif
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument.terrainBoost = {
            .terrain = STATUS_FIELD_PSYCHIC_TERRAIN,
            .percent = 50,
            .groundCheck = GROUND_CHECK_USER,
            .hitsBothFoes = TRUE,
        },
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PSYCHIC_TERRAIN},
        .battleAnimScript = gBattleAnimMove_ExpandingForce,
    },

    [MOVE_STEEL_ROLLER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eisenwalze"),
#else
        .name = COMPOUND_STRING("STEEL ROLLER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Zerstört das Feld. Ohne Feld\n"
            "schlägt sie fehl."),
#else
            "Destroys terrain. Fails if\n"
            "ground isn't terrain."),
#endif
        .effect = EFFECT_STEEL_ROLLER,
        .power = 130,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SteelRoller,
    },

    [MOVE_SCALE_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schuppenschuss"),
#else
        .name = COMPOUND_STRING("SCALE SHOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft 2- bis 5-mal. Erhöht\n"
            "Init., senkt Vert."),
#else
            "Shoots scales 2 to 5 times.\n"
            "Ups Speed, lowers defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .multiHit = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SCALE_SHOT,
        }),
        .battleAnimScript = gBattleAnimMove_ScaleShot,
    },

    [MOVE_METEOR_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Meteorstrahl"),
#else
        .name = COMPOUND_STRING("METEOR BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht in Runde 1 den Sp.Ang.\n"
            "und trifft in Runde 2."),
#else
            "A 2-turn move that raises\n"
            "Sp. Attack before attacking."),
#endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 120,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_METEORBEAMCHARGING },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .onChargeTurnOnly = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_MeteorBeam,
    },

    [MOVE_SHELL_SIDE_ARM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Muschelwaffe"),
#else
        .name = COMPOUND_STRING("SHELL SIDE ARM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Nutzt den höheren Angriffs-\n"
            "wert. Vergiftet eventuell."),
#else
            "Deals better of physical and\n"
            "special damage. May poison."),
#endif
        .effect = EFFECT_SHELL_SIDE_ARM,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ShellSideArm,
    },

    [MOVE_MISTY_EXPLOSION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Nebelexplosion"),
#else
        .name = COMPOUND_STRING("MISTY EXPLOSION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft alle, Anwender wird K.O.\n"
            "Auf Nebelfeld stärker."),
#else
            "Hit everything and faint.\n"
            "Powers up on Misty Terrain."),
#endif
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .explosion = TRUE,
        .dampBanned = TRUE,
        .argument.terrainBoost = {
            .terrain =  STATUS_FIELD_MISTY_TERRAIN,
            .percent = 50,
            .groundCheck = GROUND_CHECK_USER,
        },
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MISTY_TERRAIN},
        .battleAnimScript = gBattleAnimMove_MistyExplosion,
    },

    [MOVE_GRASSY_GLIDE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Grasrutsche"),
#else
        .name = COMPOUND_STRING("GRASSY GLIDE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Auf dem Grasfeld mit\n"
            "Erstschlaggarantie."),
#else
            "Gliding on ground, hits. Goes\n"
            "first on Grassy Terrain."),
#endif
        .effect = EFFECT_GRASSY_GLIDE,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 55 : 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GRASSY_TERRAIN},
        .battleAnimScript = gBattleAnimMove_GrassyGlide,
    },

    [MOVE_RISING_VOLTAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hochspannung"),
#else
        .name = COMPOUND_STRING("RISING VOLTAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Auf dem Elektrofeld doppelt\n"
            "so stark."),
#else
            "This move's power doubles\n"
            "when on Electric Terrain."),
#endif
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument.terrainBoost = {
            .terrain = STATUS_FIELD_ELECTRIC_TERRAIN,
            .percent = 100,
            .groundCheck = GROUND_CHECK_TARGET,
        },
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ELECTRIC_TERRAIN},
        .battleAnimScript = gBattleAnimMove_RisingVoltage,
    },

    [MOVE_TERRAIN_PULSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Feldimpuls"),
#else
        .name = COMPOUND_STRING("TERRAIN PULSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Typ und Stärke hängen vom\n"
            "aktiven Feld ab."),
#else
            "Type and power changes\n"
            "depending on the terrain."),
#endif
        .effect = EFFECT_TERRAIN_PULSE,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_REPETITION_NOT_BORING : CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ELECTRIC_TERRAIN, COMBO_STARTER_MISTY_TERRAIN, COMBO_STARTER_GRASSY_TERRAIN, COMBO_STARTER_PSYCHIC_TERRAIN},
        .battleAnimScript = gBattleAnimMove_TerrainPulse,
    },

    [MOVE_SKITTER_SMACK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Krabbelkracher"),
#else
        .name = COMPOUND_STRING("SKITTER SMACK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Angriff von hinten. Senkt\n"
            "den Sp.Ang. des Zieles."),
#else
            "User skitters behind foe to\n"
            "attack. Lowers foe's Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SkitterSmack,
    },

    [MOVE_BURNING_JEALOUSY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Neidflammen"),
#else
        .name = COMPOUND_STRING("BURNING JEALOUSY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verbrennt Ziele, deren Werte\n"
            "in der Runde stiegen."),
#else
            "Foes that have stats upped\n"
            "during the turn get burned."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .onlyIfTargetRaisedStats = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_BurningJealousy,
    },

    [MOVE_LASH_OUT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Frustventil"),
#else
        .name = COMPOUND_STRING("LASH OUT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelt stark, wenn eigene\n"
            "Werte gesenkt wurden."),
#else
            "If user's stats were lowered\n"
            "this turn, power is doubled."),
#endif
        .effect = EFFECT_LASH_OUT,
        .power = 75,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_LashOut,
    },

    [MOVE_POLTERGEIST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Poltergeist"),
#else
        .name = COMPOUND_STRING("POLTERGEIST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Nutzt das Item des Zieles.\n"
            "Ohne Item schlägt sie fehl."),
#else
            "Control foe's item to attack.\n"
            "Fails if foe has no item."),
#endif
        .effect = EFFECT_POLTERGEIST,
        .power = 110,
        .type = TYPE_GHOST,
        .accuracy = 90,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Poltergeist,
    },

    [MOVE_CORROSIVE_GAS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Korrosionsgas"),
#else
        .name = COMPOUND_STRING("CORROSIVE GAS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ätzendes Gas zersetzt die\n"
            "Items aller nahen Pkmn."),
#else
            "Highly acidic gas melts items\n"
            "held by surrounding Pokémon."),
#endif
        .effect = EFFECT_CORROSIVE_GAS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 40,
        .target = TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_CorrosiveGas,
    },

    [MOVE_COACHING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Coaching"),
#else
        .name = COMPOUND_STRING("COACHING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht Angriff und Vert. der\n"
            "Mitstreiter."),
#else
            "Properly coaches allies to\n"
            "up their Attack and Defense."),
#endif
        .effect = EFFECT_COACHING,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Coaching,
    },

    [MOVE_FLIP_TURN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rollwende"),
#else
        .name = COMPOUND_STRING("FLIP TURN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Anwender wird nach dem\n"
            "Angriff ausgewechselt."),
#else
            "Attacks and rushes back to\n"
            "switch with a party Pokémon."),
#endif
        .effect = EFFECT_HIT_ESCAPE,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FlipTurn,
    },

    [MOVE_TRIPLE_AXEL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dreifach-Axel"),
#else
        .name = COMPOUND_STRING("TRIPLE AXEL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bis zu drei Tritte, die von\n"
            "Treffer zu Treffer stärker."),
#else
            "A 3-kick attack that gets\n"
            "more powerful with each hit."),
#endif
        .effect = EFFECT_TRIPLE_KICK,
        .power = 20,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_TripleAxel,
    },

    [MOVE_DUAL_WINGBEAT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Doppelflügel"),
#else
        .name = COMPOUND_STRING("DUAL WINGBEAT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft das Ziel zweimal\n"
            "hintereinander."),
#else
            "User slams the target with\n"
            "wings and hits twice in a row."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DualWingbeat,
    },

    [MOVE_SCORCHING_SANDS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Brandsand"),
#else
        .name = COMPOUND_STRING("SCORCHING SANDS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Brennend heißer Sand.\n"
            "Verbrennt das Ziel eventuell."),
#else
            "Throws scorching sand at\n"
            "the target. May leave a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ScorchingSands,
    },

    [MOVE_JUNGLE_HEALING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dschungelheilung"),
#else
        .name = COMPOUND_STRING("JUNGLE HEALING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt KP und Statusprobleme\n"
            "des ganzen Teams."),
#else
            "Heals HP and status of\n"
            "itself and allies in battle."),
#endif
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_JungleHealing,
    },

    [MOVE_WICKED_BLOW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Finstertreffer"),
#else
        .name = COMPOUND_STRING("WICKED BLOW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein fokussierter Schlag mit\n"
            "Volltreffergarantie."),
#else
            "Mastering the Dark style,\n"
            "strikes with a critical hit."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 75 : 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WickedBlow,
    },

    [MOVE_SURGING_STRIKES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Trefferschwall"),
#else
        .name = COMPOUND_STRING("SURGING STRIKES"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft dreimal, jedes Mal mit\n"
            "Volltreffergarantie."),
#else
            "Mastering the Water style,\n"
            "strikes with 3 critical hits."),
#endif
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .punchingMove = TRUE,
        .strikeCount = 3,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SurgingStrikes,
    },

    [MOVE_THUNDER_CAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blitzgefängnis"),
#else
        .name = COMPOUND_STRING("THUNDER CAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fängt den Gegner in einem\n"
            "E-Käfig, "BINDING_TURNS" Rd."),
#else
            "Traps the foe in a cage of\n"
            "electricity for "BINDING_TURNS" turns."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
            .multistring.wrapped = B_MSG_WRAPPED_THUNDER_CAGE,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ThunderCage,
    },

    [MOVE_DRAGON_ENERGY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drachenkräfte"),
#else
        .name = COMPOUND_STRING("DRAGON ENERGY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je höher die eigenen KP,\n"
            "desto stärker."),
#else
            "The higher the user's HP\n"
            "the more damage caused."),
#endif
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_DragonEnergy,
    },

    [MOVE_FREEZING_GLARE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eisiger Blick"),
#else
        .name = COMPOUND_STRING("FREEZING GLARE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schießt Psychokraft aus\n"
#else
            "Shoots psychic power from\n"
#endif
        #if B_USE_FROSTBITE == TRUE
#if GERMAN
            "Augen. Kann Frostbeulen."),
#else
            "the eyes. May frostbite."),
#endif
        #else
#if GERMAN
            "den Augen. Kann einfrieren."),
#else
            "the eyes. May freeze the foe."),
#endif
        #endif
        .power = 90,
        .effect = EFFECT_HIT,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FreezingGlare,
    },

    [MOVE_FIERY_WRATH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Brennender Zorn"),
#else
        .name = COMPOUND_STRING("FIERY WRATH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine flammende Aura. Die Ziele\n"
            "schrecken evtl. zurück."),
#else
            "Attack fueled by your\n"
            "wrath. May cause flinching."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_FieryWrath,
    },

    [MOVE_THUNDEROUS_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Donnernder Tritt"),
#else
        .name = COMPOUND_STRING("THUNDEROUS KICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein blitzschneller Tritt.\n"
            "Senkt die Vert. des Zieles."),
#else
            "Uses a lightning-like kick\n"
            "to hit. Lowers foe's Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ThunderousKick,
    },

    [MOVE_GLACIAL_LANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blizzardlanze"),
#else
        .name = COMPOUND_STRING("GLACIAL LANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Lanze aus Eis trifft alle\n"
            "Gegner."),
#else
            "Hurls a blizzard-cloaked\n"
            "icicle lance at foes."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 130,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_GlacialLance,
    },

    [MOVE_ASTRAL_BARRAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Astralfragmente"),
#else
        .name = COMPOUND_STRING("ASTRAL BARRAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Viele kleine Spukgestalten\n"
            "greifen die Gegner an."),
#else
            "Sends a frightful amount\n"
            "of small ghosts at foes."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_AstralBarrage,
    },

    [MOVE_EERIE_SPELL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schauderspruch"),
#else
        .name = COMPOUND_STRING("EERIE SPELL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Nimmt der letzten Attacke\n"
            "des Zieles 3 AP."),
#else
            "Attacks with psychic power.\n"
            "Foe's last move has 3 PP cut."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EERIE_SPELL,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_EerieSpell,
    },

    [MOVE_DIRE_CLAW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Unheilsklauen"),
#else
        .name = COMPOUND_STRING("DIRE CLAW"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Vergiftet, paralysiert oder\n"
            "schläfert evtl. ein."),
#else
            "High critical hit chance. May\n"
            "paralyze, poison or drowse."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 80 : 60,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DIRE_CLAW,
            .chance = 50,
        }),
        .battleAnimScript = gBattleAnimMove_DireClaw,
    },

    [MOVE_PSYSHIELD_BASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Barrierenstoß"),
#else
        .name = COMPOUND_STRING("PSYSHIELD BASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Rammstoß. Erhöht die\n"
            "eigene Vert."),
#else
            "Hits a foe with psychic\n"
            "energy. May raise Defense."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_PsyshieldBash,
    },

    [MOVE_POWER_SHIFT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kraftwechsel"),
#else
        .name = COMPOUND_STRING("POWER SHIFT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Tauscht den eigenen Angriff\n"
            "mit der Vert."),
#else
            "The user swaps its Attack\n"
            "and Defense stats."),
#endif
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_PowerShift,
},

    [MOVE_STONE_AXE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Felsaxt"),
#else
        .name = COMPOUND_STRING("STONE AXE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verstreut Steine, die ein-\n"
            "greifenden Gegnern schaden."),
#else
            "Sets sharp rocks that hurt\n"
            "the foe."),
#endif
        .effect = EFFECT_STONE_AXE,
        .power = 65,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_StoneAxe,
    },

    [MOVE_SPRINGTIDE_STORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Frühlingsorkan"),
#else
        .name = COMPOUND_STRING("SPRINGTIDE STORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heftige Böen. Senken evtl.\n"
            "den Angriff der Ziele."),
#else
            "Wraps a foe in fierce winds.\n"
            "Varies with the user's form."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_FAIRY,
        .accuracy = 80,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_SpringtideStorm,
    },

    [MOVE_MYSTICAL_POWER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mythenkraft"),
#else
        .name = COMPOUND_STRING("MYSTICAL POWER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine wundersame Kraft.\n"
            "Erhöht den eigenen Sp.Ang."),
#else
            "A mysterious power strikes,\n"
            "raising the user's Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_MysticalPower,
    },

    [MOVE_RAGING_FURY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flammenwut"),
#else
        .name = COMPOUND_STRING("RAGING FURY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wütet 2 bis 3 Runden. Danach\n"
            "ist der Anwender verwirrt."),
#else
            "A rampage of 2 to 3 turns\n"
            "that confuses the user."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_USER_MORE_EASILY_STARTLED : CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_RagingFury,
    },

    [MOVE_WAVE_CRASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wellentackle"),
#else
        .name = COMPOUND_STRING("WAVE CRASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Sturz in Wasser gehüllt.\n"
            "Verletzt den Anwender."),
#else
            "A slam shrouded in water.\n"
            "It also hurts the user."),
#endif
        .effect = EFFECT_RECOIL,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 75,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .recoilPercentage = 33 },
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_WaveCrash,
    },

    [MOVE_CHLOROBLAST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Chlorostrahl"),
#else
        .name = COMPOUND_STRING("CHLOROBLAST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Chlorophyll-Strahl.\n"
            "Verletzt den Anwender."),
#else
            "A user-hurting blast of\n"
            "amassed chlorophyll."),
#endif
        .effect = EFFECT_CHLOROBLAST,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 150 : 120,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_Chloroblast,
    },

    [MOVE_MOUNTAIN_GALE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Frostfallwind"),
#else
        .name = COMPOUND_STRING("MOUNTAIN GALE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Riesige Eisbrocken. Das Ziel\n"
            "schreckt evtl. zurück."),
#else
            "Giant chunks of ice damage\n"
            "the foe. It may flinch."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 85,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_MountainGale,
    },

    [MOVE_VICTORY_DANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Siegestanz"),
#else
        .name = COMPOUND_STRING("VICTORY DANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Tanz. Erhöht Angriff,\n"
            "Vert. und Init."),
#else
            "Dances to raise Attack,\n"
            "Defense and Speed."),
#endif
        .effect = EFFECT_VICTORY_DANCE,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_VictoryDance,
    },

    [MOVE_HEADLONG_RUSH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schmetterramme"),
#else
        .name = COMPOUND_STRING("HEADLONG RUSH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Rammstoß. Senkt eigene\n"
            "Vert. und Sp.Vert."),
#else
            "Hits with a full-body tackle.\n"
            "Lowers the users's defenses."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_HeadlongRush,
    },

    [MOVE_BARB_BARRAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftstachelregen"),
#else
        .name = COMPOUND_STRING("BARB BARRAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Vergiftet evtl. Doppelt stark\n"
            "gegen Vergiftete."),
#else
            "Can poison on impact. Powers\n"
            "up against poisoned foes."),
#endif
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 60,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .status = STATUS1_PSN_ANY },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 50,
        }),
        .battleAnimScript = gBattleAnimMove_BarbBarrage,
    },

    [MOVE_ESPER_WING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Auraschwingen"),
#else
        .name = COMPOUND_STRING("ESPER WING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hohe Volltrefferquote.\n"
            "Erhöht die eigene Init."),
#else
            "High critical hit ratio.\n"
            "Ups the user's Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 80 : 75,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 90,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_EsperWing,
    },

    [MOVE_BITTER_MALICE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Niedertracht"),
#else
        .name = COMPOUND_STRING("BITTER MALICE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eiskalter Hass. Senkt den\n"
            "Angriff des Zieles."),
#else
            "A spine-chilling resentment.\n"
            "Lowers the foe's Attack."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 75 : 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_BitterMalice,
    },

    [MOVE_SHELTER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Refugium"),
#else
        .name = COMPOUND_STRING("SHELTER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Härtet die Haut. Erhöht die\n"
            "Vert. stark."),
#else
            "The user hardens their skin,\n"
            "sharply raising its Defense."),
#endif
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_Shelter,
    },

    [MOVE_TRIPLE_ARROWS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drillingspfeile"),
#else
        .name = COMPOUND_STRING("TRIPLE ARROWS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt evtl. die Vert. Das Ziel\n"
            "schreckt evtl. zurück."),
#else
            "High critical hit ratio.\n"
            "May lower Defense or flinch."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 90 : 50,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 15,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_TripleArrows,
    },

    [MOVE_INFERNAL_PARADE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Phantomparade"),
#else
        .name = COMPOUND_STRING("INFERNAL PARADE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verbrennt evtl. Doppelt\n"
            "stark gegen Statusprobleme."),
#else
            "Hurts a foe harder if it has\n"
            "an ailment. May leave a burn."),
#endif
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .status = STATUS1_ANY },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_InfernalParade,
    },

    [MOVE_CEASELESS_EDGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Klingenschwall"),
#else
        .name = COMPOUND_STRING("CEASELESS EDGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verstreut Splitter, die ein-\n"
            "greifenden Gegnern schaden."),
#else
            "Sets Spikes that hurt the\n"
            "foe."),
#endif
        .effect = EFFECT_CEASELESS_EDGE,
        .power = 65,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_CeaselessEdge,
    },

    [MOVE_BLEAKWIND_STORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Polarorkan"),
#else
        .name = COMPOUND_STRING("BLEAKWIND STORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kalte Winde. Senken evtl. die\n"
            "Init. der Ziele."),
#else
            "Hits with brutal, cold winds.\n"
            "May lower the foe's Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_FLYING,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInRain = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_BleakwindStorm,
    },

    [MOVE_WILDBOLT_STORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Donnerorkan"),
#else
        .name = COMPOUND_STRING("WILDBOLT STORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Unwetter. Paralysiert die\n"
            "Ziele eventuell."),
#else
            "Hits with a brutal tempest.\n"
            "May inflict paralysis."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_ELECTRIC,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInRain = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 20,
        }),
        .battleAnimScript = gBattleAnimMove_WildboltStorm,
    },

    [MOVE_SANDSEAR_STORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wüstenorkan"),
#else
        .name = COMPOUND_STRING("SANDSEAR STORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heißer Sand im Wind. Ver-\n"
            "brennt die Ziele eventuell."),
#else
            "Hits with brutally hot sand.\n"
            "May inflict a burn."),
#endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_GROUND,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .alwaysHitsInRain = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
        .battleAnimScript = gBattleAnimMove_SandsearStorm,
    },

    [MOVE_LUNAR_BLESSING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lunargebet"),
#else
        .name = COMPOUND_STRING("LUNAR BLESSING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt KP und Statusprobleme\n"
            "des ganzen Teams."),
#else
            "The user heals and cures\n"
            "itself and its ally."),
#endif
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_LunarBlessing,
    },

    [MOVE_TAKE_HEART] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mutschub"),
#else
        .name = COMPOUND_STRING("TAKE HEART"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt Statusprobleme. Erhöht\n"
            "Sp.Ang. und Sp.Vert."),
#else
            "The user lifts its spirits to\n"
            "heal and strengthen itself."),
#endif
        .effect = EFFECT_TAKE_HEART,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_TakeHeart,
    },

    [MOVE_TERA_BLAST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tera-Ausbruch"),
#else
        .name = COMPOUND_STRING("TERA BLAST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Typ und Schaden richten sich\n"
            "nach dem Tera-Typ."),
#else
            "If the user's Terastallized,\n"
            "it hits with its Tera type."),
#endif
        .effect = EFFECT_TERA_BLAST,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .forcePressure = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TERA_BLAST,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_TeraBlast,
    },

    [MOVE_SILK_TRAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fadenfalle"),
#else
        .name = COMPOUND_STRING("SILK TRAP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt und senkt bei\n"
            "Berührung die Init."),
#else
            "Protects itself, lowering\n"
            "Speed on contact."),
#endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_SILK_TRAP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_SilkTrap,
    },

    [MOVE_AXE_KICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fersenkick"),
#else
        .name = COMPOUND_STRING("AXE KICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verwirrt evtl. Bei Misserfolg\n"
            "schadet sie dem Anwender."),
#else
            "May miss and hurt the kicker.\n"
            "May cause confusion."),
#endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_AxeKick,
    },

    [MOVE_LAST_RESPECTS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Letzte Ehre"),
#else
        .name = COMPOUND_STRING("LAST RESPECTS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je mehr besiegte Team-Pkmn,\n"
            "desto stärker."),
#else
            "This move deals more damage\n"
            "for each defeated ally."),
#endif
        .effect = EFFECT_LAST_RESPECTS,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_LastRespects,
    },

    [MOVE_LUMINA_CRASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lichteinschlag"),
#else
        .name = COMPOUND_STRING("LUMINA CRASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein sonderbares Licht. Senkt\n"
            "die Sp.Vert. stark."),
#else
            "A mind-affecting light\n"
            "harshly lowers Sp. Def."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_LuminaCrash,
    },

    [MOVE_ORDER_UP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Auftischen"),
#else
        .name = COMPOUND_STRING("ORDER UP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht einen Wert je nach\n"
            "Nigiragi im Maul."),
#else
            "Boosts a user's stats\n"
            "depending on Tatsugiri."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ORDER_UP,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_OrderUp,
    },

    [MOVE_JET_PUNCH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Düsenhieb"),
#else
        .name = COMPOUND_STRING("JET PUNCH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Strudelhieb mit\n"
            "Erstschlaggarantie."),
#else
            "A punch is thrown at blinding\n"
            "speed to strike first."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_JetPunch,
    },

    [MOVE_SPICY_EXTRACT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Chili-Essenz"),
#else
        .name = COMPOUND_STRING("SPICY EXTRACT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht den Angriff des Zieles\n"
            "stark, senkt dessen Vert."),
#else
            "Sharply ups target's Attack,\n"
            "harshly lowers its Defense."),
#endif
        .effect = EFFECT_SPICY_EXTRACT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_SpicyExtract,
    },

    [MOVE_SPIN_OUT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Reifendrehung"),
#else
        .name = COMPOUND_STRING("SPIN OUT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein wilder Wirbel. Senkt die\n"
            "eigene Init. stark."),
#else
            "Furiously strains its legs.\n"
            "Harshly lowers user's Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_2,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_SpinOut,
    },

    [MOVE_POPULATION_BOMB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mäuseplage"),
#else
        .name = COMPOUND_STRING("POPULATION BOMB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft bis zu zehnmal\n"
            "hintereinander."),
#else
            "The user's fellows hit one\n"
            "to ten times in a row."),
#endif
        .effect = EFFECT_POPULATION_BOMB,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .strikeCount = 10,
        .battleAnimScript = gBattleAnimMove_PopulationBomb,
    },

    [MOVE_ICE_SPINNER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eiskreisel"),
#else
        .name = COMPOUND_STRING("ICE SPINNER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Eiswirbel, der das aktive\n"
            "Feld zerstört."),
#else
            "Ice-covered feet hit a foe\n"
            "and destroy the terrain."),
#endif
        .effect = EFFECT_ICE_SPINNER,
        .power = 80,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .battleAnimScript = gBattleAnimMove_IceSpinner,
    },

    [MOVE_GLAIVE_RUSH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Großklingenstoß"),
#else
        .name = COMPOUND_STRING("GLAIVE RUSH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bis zur nächsten Runde tref-\n"
            "fen alle Angriffe doppelt."),
#else
            "Foe attacks next turn can't\n"
            "miss and do double damage."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_GLAIVE_RUSH,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_GlaiveRush,
    },

    [MOVE_REVIVAL_BLESSING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Vitalsegen"),
#else
        .name = COMPOUND_STRING("REVIVAL BLESSING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Belebt ein besiegtes Team--\n"
            "Pkmn mit halben KP wieder."),
#else
            "Revives a fainted party {PKMN}\n"
            "and restores half of its HP."),
#endif
        .effect = EFFECT_REVIVAL_BLESSING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .healingMove = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .battleAnimScript = gBattleAnimMove_RevivalBlessing,
    },

    [MOVE_SALT_CURE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pökelsalz"),
#else
        .name = COMPOUND_STRING("SALT CURE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schadet jede Runde. Doppelt\n"
            "bei Stahl und Wasser."),
#else
            "Hurts foe every turn. Double\n"
            "damage to Steel and Water."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SALT_CURE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_SaltCure,
    },

    [MOVE_TRIPLE_DIVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tauchtriade"),
#else
        .name = COMPOUND_STRING("TRIPLE DIVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft das Ziel dreimal\n"
            "hintereinander."),
#else
            "Hits target with splashes\n"
            "of water 3 times in a row."),
#endif
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .battleAnimScript = gBattleAnimMove_TripleDive,
    },

    [MOVE_MORTAL_SPIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Letalwirbler"),
#else
        .name = COMPOUND_STRING("MORTAL SPIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Vergiftet die Ziele und\n"
            "befreit von Fesseln."),
#else
            "Erases trap moves and Leech\n"
            "Seed. Poisons adjacent foes."),
#endif
        .effect = EFFECT_RAPID_SPIN,
        .power = 30,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_MortalSpin,
    },

    [MOVE_DOODLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Abpausen"),
#else
        .name = COMPOUND_STRING("DOODLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Team-Pkmn erhalten die\n"
            "Fähigkeit des Zieles."),
#else
            "Changes user's and ally's\n"
            "Ability into the target's."),
#endif
        .effect = EFFECT_DOODLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_Doodle,
    },

    [MOVE_FILLET_AWAY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Abspaltung"),
#else
        .name = COMPOUND_STRING("FILLET AWAY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kostet KP. Erhöht Angriff,\n"
            "Sp.Ang. und Init. stark."),
#else
            "Sharply boosts offenses and\n"
            "Speed by using its own HP."),
#endif
        .effect = EFFECT_FILLET_AWAY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_FilletAway,
    },

    [MOVE_KOWTOW_CLEAVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kniefallspalter"),
#else
        .name = COMPOUND_STRING("KOWTOW CLEAVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Hieb aus der Verbeugung,\n"
            "der in jedem Fall trifft."),
#else
            "User slashes the foe after\n"
            "kowtowing. It never misses."),
#endif
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_KowtowCleave,
    },

    [MOVE_FLOWER_TRICK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blumentrick"),
#else
        .name = COMPOUND_STRING("FLOWER TRICK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft immer und ist stets\n"
            "ein Volltreffer."),
#else
            "Rigged bouquet. Always gets\n"
            "a critical hit, never missing."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .alwaysCriticalHit = TRUE,
        .battleAnimScript = gBattleAnimMove_FlowerTrick,
    },

    [MOVE_TORCH_SONG] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Loderlied"),
#else
        .name = COMPOUND_STRING("TORCH SONG"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lodernde Flammen. Erhöht den\n"
            "eigenen Sp.Ang."),
#else
            "Flames scorch the target.\n"
            "Boosts the user's Sp. Atk."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_TorchSong,
    },

    [MOVE_AQUA_STEP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wogentanz"),
#else
        .name = COMPOUND_STRING("AQUA STEP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Flinke Tanzschritte. Erhöht\n"
            "die eigene Init."),
#else
            "Hits with light, fluid dance\n"
            "steps. Ups the user's Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .danceMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_AquaStep,
    },

    [MOVE_RAGING_BULL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rasender Stier"),
#else
        .name = COMPOUND_STRING("RAGING BULL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Durchbricht Barrieren. Der\n"
            "Typ hängt von der Form ab."),
#else
            "Tackle that breaks barriers.\n"
            "User's form determines type."),
#endif
        .effect = EFFECT_RAGING_BULL,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BREAK_SCREEN,
            .preAttackEffect = TRUE,
        }),
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_RagingBull,
    },

    [MOVE_MAKE_IT_RAIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Goldrausch"),
#else
        .name = COMPOUND_STRING("MAKE IT RAIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schüttet Münzen aus. Senkt\n"
            "den eigenen Sp.Ang."),
#else
            "Lowers the user's Sp. Atk.\n"
            "Money is recovered after."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PAYDAY,
        },
        {
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_MakeItRain,
    },

    [MOVE_RUINATION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Verderben"),
#else
        .name = COMPOUND_STRING("RUINATION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Halbiert die KP des Zieles.\n"
            ""),
#else
            "Summons a ruinous disaster\n"
            "and cuts half the foe's HP."),
#endif
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .damagePercentage = 50 },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Ruination,
    },

    [MOVE_COLLISION_COURSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kollisionskurs"),
#else
        .name = COMPOUND_STRING("COLLISION COURSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärker, wenn sie sehr\n"
            "effektiv ist."),
#else
            "Prehistoric explosion that's\n"
            "stronger if super effective."),
#endif
        .effect = EFFECT_COLLISION_COURSE,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_CollisionCourse,
    },

    [MOVE_ELECTRO_DRIFT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blitztour"),
#else
        .name = COMPOUND_STRING("ELECTRO DRIFT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärker, wenn sie sehr\n"
            "effektiv ist."),
#else
            "Futuristic electricity. It's\n"
            "stronger if super effective."),
#endif
        .effect = EFFECT_COLLISION_COURSE,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_ElectroDrift,
    },

    [MOVE_SHED_TAIL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schwanzabwurf"),
#else
        .name = COMPOUND_STRING("SHED TAIL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kostet KP, erzeugt einen\n"
            "Delegator und wechselt aus."),
#else
            "Creates a Substitute for\n"
            "itself before switching out."),
#endif
        .effect = EFFECT_SHED_TAIL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_ShedTail,
    },

    [MOVE_CHILLY_RECEPTION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Eisige Stimmung"),
#else
        .name = COMPOUND_STRING("CHILLY RECEPTION"),
#endif
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein schlechter Witz\n"
            "beschwört Hagel, wechselt."),
#else
            "Bad joke summons hailstorm.\n"
            "The user also switches out."),
#endif
        #else
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein schlechter Witz\n"
            "beschwört Schnee, wechselt."),
#else
            "Bad joke summons snowstorm.\n"
            "The user also switches out."),
#endif
        #endif
        .effect = EFFECT_WEATHER_AND_SWITCH,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .argument = { .weatherType = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL) ? BATTLE_WEATHER_HAIL : BATTLE_WEATHER_SNOW },
        .battleAnimScript = gBattleAnimMove_ChillyReception,
    },

    [MOVE_TIDY_UP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aufräumen"),
#else
        .name = COMPOUND_STRING("TIDY UP"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Räumt das Feld. Erhöht\n"
            "eigenen Angriff und Init."),
#else
            "User tidies up hazards and\n"
            "raises its Attack and Speed."),
#endif
        .effect = EFFECT_TIDY_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_TidyUp,
    },

    [MOVE_SNOWSCAPE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schneelandschaft"),
#else
        .name = COMPOUND_STRING("SNOWSCAPE"),
#endif
        #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
            .description = COMPOUND_STRING(
#if GERMAN
                "Beschwört einen Hagelsturm,\n"
                "der jede Runde trifft."),
#else
                "Summons a hailstorm that\n"
                "strikes every turn."),
#endif
        #else
            .description = COMPOUND_STRING(
#if GERMAN
                "Beschwört Schneesturm,\n"
                "der 5 Runden anhält."),
#else
                "Summons a snowstorm that\n"
                "lasts for five turns."),
#endif
        #endif
        .effect = EFFECT_WEATHER,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .weatherType = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL) ? BATTLE_WEATHER_HAIL : BATTLE_WEATHER_SNOW },
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS : CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL) ? gBattleAnimMove_Hail : gBattleAnimMove_Snowscape,
    },

    [MOVE_POUNCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Anspringen"),
#else
        .name = COMPOUND_STRING("POUNCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Sprungangriff. Senkt die\n"
            "Init. des Zieles."),
#else
            "The user pounces on the foe,\n"
            "lowering its Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_Pounce,
    },

    [MOVE_TRAILBLAZE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wegbereiter"),
#else
        .name = COMPOUND_STRING("TRAILBLAZE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein flinker Angriff. Erhöht\n"
            "die eigene Init."),
#else
            "The user attacks suddenly,\n"
            "raising its Speed."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Trailblaze,
    },

    [MOVE_CHILLING_WATER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kalte Dusche"),
#else
        .name = COMPOUND_STRING("CHILLING WATER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eiskaltes Wasser. Senkt den\n"
            "Angriff des Zieles."),
#else
            "A shower with ice-cold water\n"
            "lowers the target's Attack."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ChillingWater,
    },

    [MOVE_HYPER_DRILL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hyperbohrer"),
#else
        .name = COMPOUND_STRING("HYPER DRILL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Bohrstich, der auch\n"
            "Schutzschild durchbricht."),
#else
            "A spinning pointed part\n"
            "bypasses a foe's Protect."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_HyperDrill,
    },

    [MOVE_TWIN_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Doppelstrahl"),
#else
        .name = COMPOUND_STRING("TWIN BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft das Ziel zweimal\n"
            "hintereinander."),
#else
            "Mystical eye-beams that hit\n"
            "the target twice in a row."),
#endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .strikeCount = 2,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_TwinBeam,
    },

    [MOVE_RAGE_FIST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zornesfaust"),
#else
        .name = COMPOUND_STRING("RAGE FIST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Je öfter getroffen, desto\n"
            "stärker."),
#else
            "The more the user has been\n"
            "hit, the stronger the move."),
#endif
        .effect = EFFECT_RAGE_FIST,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_RageFist,
    },

    [MOVE_ARMOR_CANNON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rüstungskanone"),
#else
        .name = COMPOUND_STRING("ARMOR CANNON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr stark. Senkt eigene\n"
            "Vert. und Sp.Vert."),
#else
            "A strong attack but lowers\n"
            "the defensive stats."),
#endif
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_ArmorCannon,
    },

    [MOVE_BITTER_BLADE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Reueschwert"),
#else
        .name = COMPOUND_STRING("BITTER BLADE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Saugt die Hälfte des\n"
            "Schadens als KP ab."),
#else
            "Attack that absorbs\n"
            "half the damage inflicted."),
#endif
        .effect = EFFECT_ABSORB,
        .power = 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = { .absorbPercentage = 50 },
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .healingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_BitterBlade,
    },

    [MOVE_DOUBLE_SHOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zweifachladung"),
#else
        .name = COMPOUND_STRING("DOUBLE SHOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr stark. Der Anwender\n"
            "verliert den Typ Elektro."),
#else
            "Discharges all electricity,\n"
            "losing the Electric type."),
#endif
        .effect = EFFECT_FAIL_IF_NOT_ARG_TYPE,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .argument = { .type = TYPE_ELECTRIC },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_ARG_TYPE,
            .self = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_DoubleShock,
    },

    [MOVE_GIGATON_HAMMER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Riesenhammer"),
#else
        .name = COMPOUND_STRING("GIGATON HAMMER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr stark, aber nicht zwei-\n"
            "mal hintereinander nutzbar."),
#else
            "Swings a huge hammer. Can't\n"
            "be used twice in a row."),
#endif
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .cantUseTwice = TRUE,
        .battleAnimScript = gBattleAnimMove_GigatonHammer,
    },

    [MOVE_COMEUPPANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Vendetta"),
#else
        .name = COMPOUND_STRING("COMEUPPANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Vergilt den zuletzt erlitte-\n"
            "nen Schaden verstärkt."),
#else
            "Retaliates strongly against\n"
            "who last hurt the user."),
#endif
        .effect = EFFECT_REFLECT_DAMAGE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = {
            .reflectDamage.damagePercent = 150,
            .reflectDamage.damageCategories = 1u << DAMAGE_CATEGORY_PHYSICAL | 1u << DAMAGE_CATEGORY_SPECIAL,
        },
        .makesContact = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Comeuppance,
    },

    [MOVE_AQUA_CUTTER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aquaschnitt"),
#else
        .name = COMPOUND_STRING("AQUA CUTTER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wasser wie eine Klinge. Hohe\n"
            "Volltrefferquote."),
#else
            "Pressurized water cut with a\n"
            "high critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_WATER,
        .accuracy = 100,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .pp = 20,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_AquaCutter,
    },

    [MOVE_BLAZING_TORQUE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hitzeturbo"),
        .description = COMPOUND_STRING(
            "Ein Motorangriff. Verbrennt\n"
            "das Ziel eventuell."),
#else
        .name = COMPOUND_STRING("BLAZING TORQUE"),
        .description = COMPOUND_STRING("---"),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_BlazingTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_WICKED_TORQUE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Finsterturbo"),
        .description = COMPOUND_STRING(
            "Ein Motorangriff. Schläfert\n"
            "das Ziel eventuell ein."),
#else
        .name = COMPOUND_STRING("WICKED TORQUE"),
        .description = COMPOUND_STRING("---"),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SLEEP,
            .chance = 10,
        }),
        .battleAnimScript = gBattleAnimMove_WickedTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_NOXIOUS_TORQUE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Toxiturbo"),
        .description = COMPOUND_STRING(
            "Ein Motorangriff. Vergiftet\n"
            "das Ziel eventuell."),
#else
        .name = COMPOUND_STRING("NOXIOUS TORQUE"),
        .description = COMPOUND_STRING("---"),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_NoxiousTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_COMBAT_TORQUE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Raufturbo"),
        .description = COMPOUND_STRING(
            "Ein Motorangriff. Paralysiert\n"
            "das Ziel eventuell."),
#else
        .name = COMPOUND_STRING("COMBAT TORQUE"),
        .description = COMPOUND_STRING("---"),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_CombatTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_MAGICAL_TORQUE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zauberturbo"),
        .description = COMPOUND_STRING(
            "Ein Motorangriff. Verwirrt\n"
            "das Ziel eventuell."),
#else
        .name = COMPOUND_STRING("MAGICAL TORQUE"),
        .description = COMPOUND_STRING("---"),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
        .battleAnimScript = gBattleAnimMove_MagicalTorque,
        .randomizerInvalid = TRUE,
    },

    [MOVE_PSYBLADE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psychoschneide"),
#else
        .name = COMPOUND_STRING("PSYBLADE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Auf dem Elektrofeld um die\n"
            "Hälfte stärker."),
#else
            "This move's power increases\n"
            "when on Electric Terrain."),
#endif
        .effect = EFFECT_TERRAIN_BOOST,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument.terrainBoost = {
            .terrain = STATUS_FIELD_ELECTRIC_TERRAIN,
            .percent = 50,
            .groundCheck = GROUND_CHECK_NONE,
        },
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_Psyblade,
    },

    [MOVE_HYDRO_STEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hydrodampf"),
#else
        .name = COMPOUND_STRING("HYDRO STEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bei Sonnenschein stärker\n"
            "statt schwächer."),
#else
            "This move's power increases\n"
            "under harsh sunlight."),
#endif
        .effect = EFFECT_HYDRO_STEAM,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .battleAnimScript = gBattleAnimMove_HydroSteam,
    },

    [MOVE_BLOOD_MOON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blutmond"),
#else
        .name = COMPOUND_STRING("BLOOD MOON"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr stark, aber nicht zwei-\n"
            "mal hintereinander nutzbar."),
#else
            "Unleashes the blood moon.\n"
            "Can't be used twice in a row."),
#endif
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .cantUseTwice = TRUE,
        .battleAnimScript = gBattleAnimMove_BloodMoon,
    },

    [MOVE_MATCHA_GOTCHA] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Quirlschuss"),
#else
        .name = COMPOUND_STRING("MATCHA GOTCHA"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Saugt halben Schaden als KP\n"
            "ab. Verbrennt evtl."),
#else
            "Absorbs half the damage\n"
            "inflicted. May cause a burn."),
#endif
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 15,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .absorbPercentage = 50 },
        .thawsUser = TRUE,
        .healingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
        .battleAnimScript = gBattleAnimMove_MatchaGotcha,
    },

    [MOVE_SYRUP_BOMB] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sirupbombe"),
#else
        .name = COMPOUND_STRING("SYRUP BOMB"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt 3 Runden lang jede\n"
            "Runde die Init. des Zieles."),
#else
            "Lowers the foe's speed\n"
            "each turn for 3 turns."),
#endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SYRUP_BOMB,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_SyrupBomb,
    },

    [MOVE_IVY_CUDGEL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rankenkeule"),
#else
        .name = COMPOUND_STRING("IVY CUDGEL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Typ hängt von der\n"
            "getragenen Maske ab."),
#else
            "Type changes with held mask.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_IVY_CUDGEL,
        .power = 100,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3 ? 1 : 2,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_IvyCudgel,
    },

    [MOVE_ELECTRO_SHOT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stromstrahl"),
#else
        .name = COMPOUND_STRING("ELECTRO SHOT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht in Runde 1 den Sp.Ang.\n"
            "und trifft in Runde 2."),
#else
            "Gathers electricity, then\n"
            "fires a high-voltage shot."),
#endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument.twoTurnAttack = { .stringId = STRINGID_ELECTROSHOTCHARGING, .weather = B_WEATHER_RAIN },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .onChargeTurnOnly = TRUE,
            .sheerForceOverride = TRUE,
        }),
        .battleAnimScript = gBattleAnimMove_ElectroShot,
    },

    [MOVE_TERA_STARSTORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tera-Sternhagel"),
#else
        .name = COMPOUND_STRING("TERA STARSTORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft als Stellarform alle\n"
            "Gegner zugleich."),
#else
            "In Terapagos's Stellar\n"
            "Form, it hits all foes."),
#endif
        .effect = EFFECT_TERA_STARSTORM,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .assistBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .battleAnimScript = gBattleAnimMove_TeraStarstorm,
    },

    [MOVE_FICKLE_BEAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Launenlaser"),
#else
        .name = COMPOUND_STRING("FICKLE BEAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Manchmal feuern alle Köpfe\n"
            "und verdoppeln die Kraft."),
#else
            "Shoots a beam of light.\n"
            "Sometimes twice as strong."),
#endif
        .effect = EFFECT_FICKLE_BEAM,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_FickleBeam,
    },

    [MOVE_BURNING_BULWARK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Flammenschild"),
#else
        .name = COMPOUND_STRING("BURNING BULWARK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt und verbrennt bei\n"
            "Berührung den Angreifer."),
#else
            "Evades attack, and burns\n"
            "the foe if struck."),
#endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_BURNING_BULWARK },
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .battleAnimScript = gBattleAnimMove_BurningBulwark,
    },

    [MOVE_THUNDERCLAP] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sturmblitz"),
#else
        .name = COMPOUND_STRING("THUNDERCLAP"),
#endif
        .description = sSuckerPunchDescription,
        .effect = EFFECT_SUCKER_PUNCH,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_Thunderclap,
    },

    [MOVE_MIGHTY_CLEAVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wuchtklinge"),
#else
        .name = COMPOUND_STRING("MIGHTY CLEAVE"),
#endif
        .description = sFeintDescription,
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_MightyCleave,
    },

    [MOVE_TACHYON_CUTTER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tachyon-Schnitt"),
#else
        .name = COMPOUND_STRING("TACHYON CUTTER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft zweimal hintereinan-\n"
            "der und in jedem Fall."),
#else
            "Launches particle blades at\n"
            "the target. Strikes twice."),
#endif
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .strikeCount = 2,
        .slicingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_TachyonCutter,
    },

    [MOVE_HARD_PRESS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stahlpresse"),
#else
        .name = COMPOUND_STRING("HARD PRESS"),
#endif
        .description = sWringOutDescription,
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .battleAnimScript = gBattleAnimMove_HardPress,
    },

    [MOVE_DRAGON_CHEER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drachenschrei"),
#else
        .name = COMPOUND_STRING("DRAGON CHEER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht die Volltrefferquote\n"
            "der Mitstreiter."),
#else
            "Increases allies' critical hit\n"
            "ratio, especially if Dragons."),
#endif
        .effect = EFFECT_DRAGON_CHEER,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 15,
        .target = TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresSubstitute = TRUE,
        .battleAnimScript = gBattleAnimMove_DragonCheer,
    },

    [MOVE_ALLURING_VOICE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lockstimme"),
#else
        .name = COMPOUND_STRING("ALLURING VOICE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Verwirrt Ziele, deren Werte in\n"
            "der Runde stiegen."),
#else
            "Confuses foe if its stats\n"
            "were boosted this turn."),
#endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .onlyIfTargetRaisedStats = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_AlluringVoice,
    },

    [MOVE_TEMPER_FLARE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Frustflamme"),
#else
        .name = COMPOUND_STRING("TEMPER FLARE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelt so stark, wenn die\n"
            "letzte Attacke misslang."),
#else
            "A desperation attack. Power\n"
            "doubles if last move failed."),
#endif
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .battleAnimScript = gBattleAnimMove_TemperFlare,
    },

    [MOVE_SUPERCELL_SLAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Donnerstoß"),
#else
        .name = COMPOUND_STRING("SUPERCELL SLAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bei Misserfolg schadet sie\n"
            "dem Anwender."),
#else
            "An electrified slam. If it\n"
            "misses, the user is hurt."),
#endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
        .battleAnimScript = gBattleAnimMove_SupercellSlam,
    },

    [MOVE_PSYCHIC_NOISE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psycholärm"),
#else
        .name = COMPOUND_STRING("PSYCHIC NOISE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Ziel kann 2 Runden lang\n"
            "keine KP heilen."),
#else
            "Sound waves that damage and\n"
            "prevent healing for 2 turns."),
#endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PSYCHIC_NOISE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_PsychicNoise,
    },

    [MOVE_UPPER_HAND] =
    {
        .effect = EFFECT_UPPER_HAND,
#if GERMAN
        .name = COMPOUND_STRING("Schnellkonter"),
#else
        .name = COMPOUND_STRING("UPPER HAND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lässt das Ziel schrecken,\n"
            "wenn es Priorität nutzt."),
#else
            "Makes the target flinch if\n"
            "readying a priority move."),
#endif
        .power = 65,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = TARGET_SELECTED,
        .priority = 3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_UpperHand,
    },

    [MOVE_MALIGNANT_CHAIN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giftkettung"),
#else
        .name = COMPOUND_STRING("MALIGNANT CHAIN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Giftkette. Vergiftet\n"
            "das Ziel eventuell schwer."),
#else
            "A corrosive chain attack\n"
            "that may badly poison."),
#endif
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 5,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TOXIC,
            .chance = 50,
        }),
        .battleAnimScript = gBattleAnimMove_MalignantChain,
    },

    // Z-Moves
    [MOVE_BREAKNECK_BLITZ] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hyper-Sprintangriff"),
#else
        .name = COMPOUND_STRING("BREAKNECK BLITZ"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Baut Schwung auf und rammt\n"
            "den Gegner. Kraft variiert."),
#else
            "Builds momentum and crashes\n"
            "into the foe. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,    //determined from move type
        .battleAnimScript = gBattleAnimMove_BreakneckBlitz,
    },
    [MOVE_ALL_OUT_PUMMELING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fulminante Faustschläge"),
#else
        .name = COMPOUND_STRING("ALL-OUT PUMMELING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Rammt eine Energiekugel\n"
            "ins Ziel. Kraft variiert."),
#else
            "Rams an energy orb into\n"
            "the target. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_AllOutPummeling,
    },
    [MOVE_SUPERSONIC_SKYSTRIKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Finaler Steilflug"),
#else
        .name = COMPOUND_STRING("SUPERSONIC SKYSTRIKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Steigt auf und stürzt aufs\n"
            "Ziel. Kraft variiert."),
#else
            "Soars up and plummets toward\n"
            "the target. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SupersonicSkystrike,
    },
    [MOVE_ACID_DOWNPOUR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Vernichtender Säureregen"),
#else
        .name = COMPOUND_STRING("ACID DOWNPOUR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Versenkt das Ziel in\n"
            "Giftsumpf. Kraft variiert."),
#else
            "Sinks the target in a poison\n"
            "swamp. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_AcidDownpour,
    },
    [MOVE_TECTONIC_RAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Seismische Eruption"),
#else
        .name = COMPOUND_STRING("TECTONIC RAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gräbt sich tief ein, rammt\n"
            "das Ziel. Kraft variiert."),
#else
            "Burrows deep and slams into\n"
            "the target. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .battleAnimScript = gBattleAnimMove_TectonicRage,
    },
    [MOVE_CONTINENTAL_CRUSH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Apokalyptische Steinpresse"),
#else
        .name = COMPOUND_STRING("CONTINENTAL CRUSH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lässt einen Felsberg auf\n"
            "fallen. Kraft variiert."),
#else
            "Drops a huge rock mountain\n"
            "on the foe. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_ContinentalCrush,
    },
    [MOVE_SAVAGE_SPIN_OUT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Wirbelnder Insektenhieb"),
#else
        .name = COMPOUND_STRING("SAVAGE SPIN-OUT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Spuckt Seidenfäden, um\n"
            "Gegner zu binden. Variiert."),
#else
            "Spits threads of silk to\n"
            "bind the foe. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SavageSpinOut,
    },
    [MOVE_NEVER_ENDING_NIGHTMARE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ewige Nacht"),
#else
        .name = COMPOUND_STRING("NEVER-ENDING NIGHTMARE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Tiefer Groll fesselt\n"
            "das Ziel. Kraft variiert."),
#else
            "Deep-seated grudges trap\n"
            "the target. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_NeverEndingNightmare,
    },
    [MOVE_CORKSCREW_CRASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Turbo-Spiralkombo"),
#else
        .name = COMPOUND_STRING("CORKSCREW CRASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Dreht sich schnell und\n"
            "rammt das Ziel. Variiert."),
#else
            "Spins very fast and rams\n"
            "the target. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_CorkscrewCrash,
    },
    [MOVE_INFERNO_OVERDRIVE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dynamische Maxiflamme"),
#else
        .name = COMPOUND_STRING("INFERNO OVERDRIVE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Haucht intensives Feuer\n"
            "aufs Ziel. Kraft variiert."),
#else
            "Breathes intense fire at\n"
            "the target. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_InfernoOverdrive,
    },
    [MOVE_HYDRO_VORTEX] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Super-Wassertornado"),
#else
        .name = COMPOUND_STRING("HYDRO VORTEX"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein riesiger Strudel\n"
            "verschlingt Ziel. Variiert."),
#else
            "A huge whirlpool swallows\n"
            "the target. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_HydroVortex,
    },
    [MOVE_BLOOM_DOOM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Brillante Blütenpracht"),
#else
        .name = COMPOUND_STRING("BLOOM DOOM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Nutzt Pflanzenenergie zum\n"
            "Angriff. Kraft variiert."),
#else
            "Uses plant energy to attack\n"
            "the target. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_BloomDoom,
    },
    [MOVE_GIGAVOLT_HAVOC] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gigavolt-Funkensalve"),
#else
        .name = COMPOUND_STRING("GIGAVOLT HAVOC"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Trifft den Gegner mit\n"
            "starkem Strom. Variiert."),
#else
            "Hits the foe with powerful\n"
            "electricity. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GigavoltHavoc,
    },
    [MOVE_SHATTERED_PSYCHE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Psycho-Schmetterschlag"),
#else
        .name = COMPOUND_STRING("SHATTERED PSYCHE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kontrolliert das Ziel, um\n"
            "es zu verletzen. Variiert."),
#else
            "Controls the target to\n"
            "hurt it. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_ShatteredPsyche,
    },
    [MOVE_SUBZERO_SLAMMER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tobender Geofrost"),
#else
        .name = COMPOUND_STRING("SUBZERO SLAMMER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt Temperatur, friert\n"
            "das Ziel ein. Variiert."),
#else
            "Drops the temp and freezes\n"
            "the target. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SubzeroSlammer,
    },
    [MOVE_DEVASTATING_DRAKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Drastisches Drachendröhnen"),
#else
        .name = COMPOUND_STRING("DEVASTATING DRAKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt Aura und greift\n"
            "das Ziel an. Variiert."),
#else
            "Develops aura and attacks\n"
            "the target. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_DevastatingDrake,
    },
    [MOVE_BLACK_HOLE_ECLIPSE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schwarzes Loch des Grauens"),
#else
        .name = COMPOUND_STRING("BLACK HOLE ECLIPSE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Saugt das Ziel in dunkle\n"
            "Energie. Kraft variiert."),
#else
            "Sucks the target into dark\n"
            "energy. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_BlackHoleEclipse,
    },
    [MOVE_TWINKLE_TACKLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Entzückender Sternenstoß"),
#else
        .name = COMPOUND_STRING("TWINKLE TACKLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Spielt mit dem Ziel in\n"
            "reizvollem Raum. Variiert."),
#else
            "Toys with the target in a\n"
            "charming space. Power varies."),
#endif
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_TwinkleTackle,
    },
    [MOVE_CATASTROPIKA] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Perfektes Pika-Projektil"),
#else
        .name = COMPOUND_STRING("CATASTROPIKA"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Nutzer nutzt maximale\n"
            "Elektrizität, stürzt sich."),
#else
            "Pikachu uses the max amount\n"
            "of electricity and pounces."),
#endif
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_Catastropika,
    },
    [MOVE_10000000_VOLT_THUNDERBOLT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Tausendfacher Donnerblitz"),
#else
        .name = COMPOUND_STRING("10,000,000 VOLT THUNDERBOLT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Setzt einen starken Blitz\n"
            "frei. Hohe Volltr.-Quote."),
#else
            "Cap Pikachu unleashes jolt.\n"
            "High critical-hit ratio."),
#endif
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .criticalHitStage = 2,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_10000000VoltThunderbolt,
    },
    [MOVE_STOKED_SPARKSURFER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Blitz-Wellenritt"),
#else
        .name = COMPOUND_STRING("STOKED SPARKSURFER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift mit voller Kraft an.\n"
            "Verursacht Paralyse."),
#else
            "Alolan Raichu attacks with\n"
            "full force. Causes paralysis."),
#endif
        .effect = EFFECT_HIT,
        .power = 175,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_StokedSparksurfer,
    },
    [MOVE_EXTREME_EVOBOOST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Macht der Neun"),
#else
        .name = COMPOUND_STRING("EXTREME EVOBOOST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhält Energie von\n"
            "Freunden. Erhöht Werte."),
#else
            "Eevee gets energy from\n"
            "its friends. Boosts stats."),
#endif
        .effect = EFFECT_EXTREME_EVOBOOST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .battleAnimScript = gBattleAnimMove_ExtremeEvoboost,
    },
    [MOVE_PULVERIZING_PANCAKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schluss mit lustig"),
#else
        .name = COMPOUND_STRING("PULVERIZING PANCAKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bewegt sich energisch und\n"
            "greift mit voller Kraft an."),
#else
            "Snorlax energetically moves\n"
            "and attacks with full force."),
#endif
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_PulverizingPancake,
    },
    [MOVE_GENESIS_SUPERNOVA] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Supernova des Ursprungs"),
#else
        .name = COMPOUND_STRING("GENESIS SUPERNOVA"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift mit voller Kraft an.\n"
            "Lädt Terrain psychisch auf."),
#else
            "Mew attacks with full force.\n"
            "Psychically charges terrain."),
#endif
        .effect = EFFECT_HIT,
        .power = 185,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_GenesisSupernova,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PSYCHIC_TERRAIN,
            .chance = 100,
        }),
    },
    [MOVE_SINISTER_ARROW_RAID] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schatten-Pfeilregen"),
#else
        .name = COMPOUND_STRING("SINISTER ARROW RAID"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schießt unzählige Pfeile\n"
            "mit voller Kraft ab."),
#else
            "Decidueye shoots countless\n"
            "arrows with full force."),
#endif
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SinisterArrowRaid,
    },
    [MOVE_MALICIOUS_MOONSAULT] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hyper Dark Crusher"),
#else
        .name = COMPOUND_STRING("MALICIOUS MOONSAULT"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Rammt das Ziel mit voller\n"
            "Kraft."),
#else
            "Incineroar crashes into\n"
            "the target with full force."),
#endif
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .minimizeDoubleDamage = TRUE,
        .battleAnimScript = gBattleAnimMove_MaliciousMoonsault,
    },
    [MOVE_OCEANIC_OPERETTA] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Grandiose Meeressymphonie"),
#else
        .name = COMPOUND_STRING("OCEANIC OPERETTA"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Beschwört eine riesige\n"
            "Wassermenge auf den Gegner."),
#else
            "Primarina summons a massive\n"
            "amount of water at the foe."),
#endif
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .battleAnimScript = gBattleAnimMove_OceanicOperetta,
    },
    [MOVE_SPLINTERED_STORMSHARDS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Fataler Steinregen"),
#else
        .name = COMPOUND_STRING("SPLINTERED STORMSHARDS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift mit voller Kraft an.\n"
            "Entfernt alles Terrain."),
#else
            "Lycanroc attacks with full\n"
            "force. Removes all terrain."),
#endif
        .effect = EFFECT_ICE_SPINNER,
        .power = 190,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SplinteredStormshards,
    },
    [MOVE_LETS_SNUGGLE_FOREVER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Herzliche Knuddelkloppe"),
#else
        .name = COMPOUND_STRING("LET'S SNUGGLE FOREVER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlägt das Ziel mit\n"
            "voller Kraft."),
#else
            "Mimikyu punches the target\n"
            "with full force."),
#endif
        .effect = EFFECT_HIT,
        .power = 190,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_LetsSnuggleForever,
    },
    [MOVE_CLANGOROUS_SOULBLAZE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Rasselnder Seelentanz"),
#else
        .name = COMPOUND_STRING("CLANGOROUS SOULBLAZE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift mit voller Kraft an.\n"
            "Erhöht alle eigenen Werte."),
#else
            "Kommo-o attacks with full\n"
            "force. Boosts all stats."),
#endif
        .effect = EFFECT_HIT,
        .power = 185,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_ClangorousSoulblaze,
    },
    [MOVE_GUARDIAN_OF_ALOLA] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Alolas Wächter"),
#else
        .name = COMPOUND_STRING("GUARDIAN OF ALOLA"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Der Landgeist senkt die\n"
            "KP des Gegners stark."),
#else
            "The Land Spirit Pokémon\n"
            "greatly reduces the foe's HP."),
#endif
        .effect = EFFECT_FIXED_PERCENT_DAMAGE,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = { .damagePercentage = 75 },
        .battleAnimScript = gBattleAnimMove_GuardianOfAlola,
    },
    [MOVE_SEARING_SUNRAZE_SMASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Schmetternde Sonnenwalze"),
#else
        .name = COMPOUND_STRING("SEARING SUNRAZE SMASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift mit voller Kraft an.\n"
            "Ignoriert Fähigkeiten."),
#else
            "Solgaleo attacks with full\n"
            "force. Ignores abilities."),
#endif
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_SearingSunrazeSmash,
    },
    [MOVE_MENACING_MOONRAZE_MAELSTROM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Geballter Mondlaser"),
#else
        .name = COMPOUND_STRING("MENACING MOONRAZE MAELSTROM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Greift mit voller Kraft an.\n"
            "Ignoriert Fähigkeiten."),
#else
            "Lunala attacks with full\n"
            "force. Ignores abilities."),
#endif
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_MenacingMoonrazeMaelstrom,
    },
    [MOVE_LIGHT_THAT_BURNS_THE_SKY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Licht des Erlöschens"),
#else
        .name = COMPOUND_STRING("LIGHT THAT BURNS THE SKY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Nutzt den höchsten\n"
            "Angriffswert. Ignoriert."),
#else
            "Uses Necrozma's highest\n"
            "attack. Ignores abilities."),
#endif
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 200,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_LightThatBurnsTheSky,
    },
    [MOVE_SOUL_STEALING_7_STAR_STRIKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Sternbild des Seelenraubes"),
#else
        .name = COMPOUND_STRING("SOUL-STEALING 7-STAR STRIKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlägt und tritt mit\n"
            "voller Kraft."),
#else
            "Marshadow punches and\n"
            "kicks with full force."),
#endif
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_SoulStealing7StarStrike,
    },

    [MOVE_MAX_GUARD] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Wall"),
#else
        .name = COMPOUND_STRING("MAX GUARD"),
#endif
        .description = sProtectDescription,
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = { .protectMethod = PROTECT_MAX_GUARD },
        .battleAnimScript = gBattleAnimMove_MaxGuard,
    },

    [MOVE_MAX_FLARE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Brand"),
#else
        .name = COMPOUND_STRING("MAX FLARE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Feuer-Dynamax-Angriff.\n"
            "Verstärkt Sonne 5 Runden."),
#else
            "Fire Dynamax attack.\n"
            "Intensifies sun for 5 turns."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxFlare,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SUN,
        }),
    },

    [MOVE_MAX_FLUTTERBY] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Schwarm"),
#else
        .name = COMPOUND_STRING("MAX FLUTTERBY"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Käfer-Dynamax-Angriff.\n"
            "Senkt Sp.Angriff des Ziels."),
#else
            "Bug Dynamax attack.\n"
            "Lowers foe's Sp. Atk stat."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxFlutterby,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SP_ATK_SIDE,
        }),
    },

    [MOVE_MAX_LIGHTNING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Gewitter"),
#else
        .name = COMPOUND_STRING("MAX LIGHTNING"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Elektro-Dynamax-Angriff.\n"
            "Elektrifiziert das Terrain."),
#else
            "Electric Dynamax attack.\n"
            "Turns the terrain electric."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxLightning,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ELECTRIC_TERRAIN,
        }),
    },

    [MOVE_MAX_STRIKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Angriff"),
#else
        .name = COMPOUND_STRING("MAX STRIKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Normal-Dynamax-Angriff.\n"
            "Senkt Tempo des Gegners."),
#else
            "Normal Dynamax attack.\n"
            "Lowers foe's Speed stat."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxStrike,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SPEED_SIDE,
        }),
    },

    [MOVE_MAX_KNUCKLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Faust"),
#else
        .name = COMPOUND_STRING("MAX KNUCKLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Kampf-Dynamax-Angriff.\n"
            "Erhöht Angriff des Teams."),
#else
            "Fighting Dynamax attack.\n"
            "Boosts ally Attack stats."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxKnuckle,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_ATTACK,
        }),
    },

    [MOVE_MAX_PHANTASM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Spuk"),
#else
        .name = COMPOUND_STRING("MAX PHANTASM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Geister-Dynamax-Angriff.\n"
            "Senkt Vert. des Gegners."),
#else
            "Ghost Dynamax attack.\n"
            "Lowers foe's Defense stat."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxPhantasm,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_DEFENSE_SIDE,
        }),
    },

    [MOVE_MAX_HAILSTORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Frost"),
#else
        .name = COMPOUND_STRING("MAX HAILSTORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Eis-Dynamax-Angriff.\n"
            "Beschwört Hagel, 5 Runden."),
#else
            "Ice Dynamax attack.\n"
            "Summons hail for 5 turns."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxHailstorm,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_HAIL,
        }),
    },

    [MOVE_MAX_OOZE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Giftschwall"),
#else
        .name = COMPOUND_STRING("MAX OOZE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gift-Dynamax-Angriff.\n"
            "Erhöht Sp.Ang. des Teams."),
#else
            "Poison Dynamax attack.\n"
            "Boosts ally Sp. Atk stats."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxOoze,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_SP_ATK,
        }),
    },

    [MOVE_MAX_GEYSER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Flut"),
#else
        .name = COMPOUND_STRING("MAX GEYSER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Wasser-Dynamax-Angriff.\n"
            "Beschwört Regen, 5 Runden."),
#else
            "Water Dynamax attack.\n"
            "Summons rain for 5 turns."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxGeyser,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAIN,
        }),
    },

    [MOVE_MAX_AIRSTREAM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Düse"),
#else
        .name = COMPOUND_STRING("MAX AIRSTREAM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Flug-Dynamax-Angriff.\n"
            "Erhöht Tempo des Teams."),
#else
            "Flying Dynamax attack.\n"
            "Boosts ally Speed stats."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxAirstream,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_SPEED,
        }),
    },

    [MOVE_MAX_STARFALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Zauber"),
#else
        .name = COMPOUND_STRING("MAX STARFALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fee-Dynamax-Angriff.\n"
            "Macht das Terrain neblig."),
#else
            "Fairy Dynamax attack.\n"
            "Turns the terrain misty."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxStarfall,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_MISTY_TERRAIN,
        }),
    },

    [MOVE_MAX_WYRMWIND] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Wyrm"),
#else
        .name = COMPOUND_STRING("MAX WYRMWIND"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Drachen-Dynamax-Angriff.\n"
            "Senkt Angriff des Gegners."),
#else
            "Dragon Dynamax attack.\n"
            "Lowers foe's Attack stat."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxWyrmwind,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_ATTACK_SIDE,
        }),
    },

    [MOVE_MAX_MINDSTORM] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Kinese"),
#else
        .name = COMPOUND_STRING("MAX MINDSTORM"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Psycho-Dynamax-Angriff.\n"
            "Terrain wird psychisch."),
#else
            "Psychic Dynamax attack.\n"
            "Turns the terrain psychic."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxMindstorm,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PSYCHIC_TERRAIN,
        }),
    },

    [MOVE_MAX_ROCKFALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Brocken"),
#else
        .name = COMPOUND_STRING("MAX ROCKFALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gesteins-Dynamax-Angriff.\n"
            "Beschwört einen Sandsturm."),
#else
            "Rock Dynamax attack.\n"
            "Summons a sandstorm."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxRockfall,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SANDSTORM,
        }),
    },

    [MOVE_MAX_QUAKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Erdstoß"),
#else
        .name = COMPOUND_STRING("MAX QUAKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Boden-Dynamax-Angriff.\n"
            "Erhöht Sp.Vert. des Teams."),
#else
            "Ground Dynamax attack.\n"
            "Boosts ally Sp. Def stats."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .battleAnimScript = gBattleAnimMove_MaxQuake,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_SP_DEF,
        }),
    },

    [MOVE_MAX_DARKNESS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Dunkel"),
#else
        .name = COMPOUND_STRING("MAX DARKNESS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Unlicht-Dynamax-Angriff.\n"
            "Senkt Sp.Vert. des Gegners."),
#else
            "Dark Dynamax attack.\n"
            "Lowers foe's Sp. Def stat."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxDarkness,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SP_DEF_SIDE,
        }),
    },

    [MOVE_MAX_OVERGROWTH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Flora"),
#else
        .name = COMPOUND_STRING("MAX OVERGROWTH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Pflanzen-Dynamax-Angriff.\n"
            "Macht das Terrain zu Gras."),
#else
            "Grass Dynamax attack.\n"
            "Turns the terrain grassy."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxOvergrowth,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_GRASSY_TERRAIN,
        }),
    },

    [MOVE_MAX_STEELSPIKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Dyna-Stahlzacken"),
#else
        .name = COMPOUND_STRING("MAX STEELSPIKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Stahl-Dynamax-Angriff.\n"
            "Erhöht Vert. des Teams."),
#else
            "Steel Dynamax attack.\n"
            "Boosts ally Defense stats."),
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_MaxSteelspike,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAISE_TEAM_DEFENSE,
        }),
    },

    [MOVE_G_MAX_VINE_LASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Geißel"),
#else
        .name = COMPOUND_STRING("G-MAX VINE LASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bisaflor-G-Max-Angriff.\n"
            "Schadet 4 Runden lang."),    //ANIM TODO
#else
            "G-max Venusaur attack.\n"
            "Damages for 4 turns."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxVineLash,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_VINE_LASH,
        }),
    },

    [MOVE_G_MAX_WILDFIRE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Feuerflug"),
#else
        .name = COMPOUND_STRING("G-MAX WILDFIRE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Glurak-G-Max-Angriff.\n"
            "Schadet 4 Runden lang."),    //ANIM TODO
#else
            "G-max Charizard attack.\n"
            "Damages for 4 turns."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxWildfire,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WILDFIRE,
        }),
    },

    [MOVE_G_MAX_CANNONADE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Beschuss"),
#else
        .name = COMPOUND_STRING("G-MAX CANNONADE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Turtok-G-Max-Angriff.\n"
            "Schadet 4 Runden lang."),    //ANIM TODO
#else
            "G-max Blastoise attack.\n"
            "Damages for 4 turns."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxCannonade,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CANNONADE,
        }),
    },

    [MOVE_G_MAX_BEFUDDLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Benebelung"),
#else
        .name = COMPOUND_STRING("G-MAX BEFUDDLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Smettbo-G-Max-Angriff.\n"
            "Gift, Paralyse oder Schlaf."),    //ANIM TODO
#else
            "G-max Butterfree attack.\n"
            "Poison, paralysis, or sleep."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxBefuddle,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EFFECT_SPORE_SIDE,
        }),
    },

    [MOVE_G_MAX_VOLT_CRASH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Blitzhagel"),
#else
        .name = COMPOUND_STRING("G-MAX VOLT CRASH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Pikachu-G-Max-Angriff.\n"
            "Paralysiert die Gegner."),    //ANIM TODO
#else
            "G-max Pikachu attack.\n"
            "Paralyzes opponents."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxVoltCrash,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYZE_SIDE,
        }),
    },

    [MOVE_G_MAX_GOLD_RUSH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Münzregen"),
#else
        .name = COMPOUND_STRING("G-MAX GOLD RUSH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Mauzi-G-Max-Angriff.\n"
            "Verwirrt, bringt Geld ein."),    //ANIM TODO
#else
            "G-max Meowth attack.\n"
            "Confuses and earns money."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxGoldRush,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE,
        }),
    },

    [MOVE_G_MAX_CHI_STRIKE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Fokusschlag"),
#else
        .name = COMPOUND_STRING("G-MAX CHI STRIKE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Machomei-G-Max-Angriff.\n"
            "Erhöht Volltrefferquote."),    //ANIM TODO
#else
            "G-max Machamp attack.\n"
            "Boosts critical-hit ratio."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxChiStrike,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CRIT_PLUS_SIDE,
        }),
    },

    [MOVE_G_MAX_TERROR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Spuksperre"),
#else
        .name = COMPOUND_STRING("G-MAX TERROR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Gengar-G-Max-Angriff.\n"
            "Verhindert Fluchtversuche."),    //ANIM TODO
#else
            "G-max Gengar attack.\n"
            "Prevents foes from escaping."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxTerror,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE_SIDE,
        }),
    },

    [MOVE_G_MAX_FOAM_BURST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Schaumbad"),
#else
        .name = COMPOUND_STRING("G-MAX FOAM BURST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Krabborak-G-Max-Angriff.\n"
            "Senkt Tempo stark."),    //ANIM TODO
#else
            "G-max Kingler attack.\n"
            "Harshly lowers foe's Speed."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxFoamBurst,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_SPEED_2_SIDE,
        }),
    },

    [MOVE_G_MAX_RESONANCE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Melodie"),
#else
        .name = COMPOUND_STRING("G-MAX RESONANCE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Lapras-G-Max-Angriff.\n"
            "Mindert Schaden 5 Runden."),    //ANIM TODO
#else
            "G-max Lapras attack.\n"
            "Reduces damage for 5 turns."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxResonance,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_AURORA_VEIL,
        }),
    },

    [MOVE_G_MAX_CUDDLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Gekuschel"),
#else
        .name = COMPOUND_STRING("G-MAX CUDDLE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Evoli-G-Max-Angriff.\n"
            "Verliebt die Gegner."),    //ANIM TODO
#else
            "G-max Eevee attack.\n"
            "Infatuates opponents."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxCuddle,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_INFATUATE_SIDE,
        }),
    },

    [MOVE_G_MAX_REPLENISH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Recycling"),
#else
        .name = COMPOUND_STRING("G-MAX REPLENISH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Relaxo-G-Max-Angriff.\n"
            "Stellt Beeren wieder her."),    //ANIM TODO
#else
            "G-max Snorlax attack.\n"
            "Restores eaten Berries."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxReplenish,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECYCLE_BERRIES,
        }),
    },

    [MOVE_G_MAX_MALODOR] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Gestank"),
#else
        .name = COMPOUND_STRING("G-MAX MALODOR"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sleimok-G-Max-Angriff.\n"
            "Vergiftet die Gegner."),    //ANIM TODO
#else
            "G-max Garbodor attack.\n"
            "Poisons opponents."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxMalodor,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON_SIDE,
        }),
    },

    [MOVE_G_MAX_MELTDOWN] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Schmelze"),
#else
        .name = COMPOUND_STRING("G-MAX MELTDOWN"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Meltan-G-Max-Angriff.\n"
            "Verhindert Attackenwdh."),    //ANIM TODO
#else
            "G-max Melmetal attack.\n"
            "Prevents repeat move use."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxMeltdown,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TORMENT_SIDE,
        }),
    },

    [MOVE_G_MAX_DRUM_SOLO] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Getrommel"),
#else
        .name = COMPOUND_STRING("G-MAX DRUM SOLO"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Rillaboom-G-Max-Angriff.\n"
            "Ignoriert dessen Fähigkeit."),    //ANIM TODO
#else
            "G-max Rillaboom attack.\n"
            "Ignores target's abilities."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxDrumSolo,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIXED_POWER,
        }),
    },

    [MOVE_G_MAX_FIREBALL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Brandball"),
#else
        .name = COMPOUND_STRING("G-MAX FIREBALL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Cinderace-G-Max-Angriff.\n"
            "Ignoriert dessen Fähigkeit."),    //ANIM TODO
#else
            "G-max Cinderace attack.\n"
            "Ignores target's abilities."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxFireball,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIXED_POWER,
        }),
    },

    [MOVE_G_MAX_HYDROSNIPE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Schütze"),
#else
        .name = COMPOUND_STRING("G-MAX HYDROSNIPE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Inteleon-G-Max-Angriff.\n"
            "Ignoriert dessen Fähigkeit."),    //ANIM TODO
#else
            "G-max Inteleon attack.\n"
            "Ignores target's abilities."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxHydrosnipe,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIXED_POWER,
        }),
    },

    [MOVE_G_MAX_WIND_RAGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Sturmstoß"),
#else
        .name = COMPOUND_STRING("G-MAX WIND RAGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Corviknight-G-Max-Angriff.\n"
            "Entfernt Schutzschilde."),    //ANIM TODO
#else
            "G-max Corviknight attack.\n"
            "Removes opponent screens."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxWindRage,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEFOG,
        }),
    },

    [MOVE_G_MAX_GRAVITAS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Astrowellen"),
#else
        .name = COMPOUND_STRING("G-MAX GRAVITAS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Orbeetle-G-Max-Angriff.\n"
            "Schwerkraft 5 Runden lang."),    //ANIM TODO
#else
            "G-max Orbeetle attack.\n"
            "Changes gravity for 5 turns."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxGravitas,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_GRAVITY,
        }),
    },

    [MOVE_G_MAX_STONESURGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Geröll"),
#else
        .name = COMPOUND_STRING("G-MAX STONESURGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Drednaw-G-Max-Angriff.\n"
            "Verstreut scharfe Steine."),    //ANIM TODO
#else
            "G-max Drednaw attack.\n"
            "Scatters sharp rocks."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxStonesurge,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEALTH_ROCK,
        }),
    },

    [MOVE_G_MAX_VOLCALITH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Schlacke"),
#else
        .name = COMPOUND_STRING("G-MAX VOLCALITH"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Coalossal-G-Max-Angriff.\n"
            "Schadet 4 Runden lang."),    //ANIM TODO
#else
            "G-max Coalossal attack.\n"
            "Damages for 4 turns."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxVolcalith,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_VOLCALITH,
        }),
    },

    [MOVE_G_MAX_TARTNESS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Säureguss"),
#else
        .name = COMPOUND_STRING("G-MAX TARTNESS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Flapple-G-Max-Angriff.\n"
            "Senkt Ausweichen des Ziels."),    //ANIM TODO
#else
            "G-max Flapple attack.\n"
            "Lowers foe's evasiveness."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxTartness,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LOWER_EVASIVENESS_SIDE,
        }),
    },

    [MOVE_G_MAX_SWEETNESS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Nektarflut"),
#else
        .name = COMPOUND_STRING("G-MAX SWEETNESS"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Appletun-G-Max-Angriff.\n"
            "Heilt Status des Teams."),    //ANIM TODO
#else
            "G-max Appletun attack.\n"
            "Heals ally status conditions."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSweetness,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_AROMATHERAPY,
        }),
    },

    [MOVE_G_MAX_SANDBLAST] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Sandstoß"),
#else
        .name = COMPOUND_STRING("G-MAX SANDBLAST"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sandaconda-G-Max-Angriff.\n"
            "Fängt Gegner im Sandsturm."),    //ANIM TODO
#else
            "G-max Sandaconda attack.\n"
            "Traps foes in a sandstorm."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSandblast,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SANDBLAST_SIDE,
        }),
    },

    [MOVE_G_MAX_STUN_SHOCK] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Voltschlag"),
#else
        .name = COMPOUND_STRING("G-MAX STUN SHOCK"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Toxtricity-G-Max-Angriff.\n"
            "Vergiftet oder paralysiert."),    //ANIM TODO
#else
            "G-max Toxtricity attack.\n"
            "Poisons or paralyzes foes."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxStunShock,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON_PARALYZE_SIDE,
        }),
    },

    [MOVE_G_MAX_CENTIFERNO] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Feuerkessel"),
#else
        .name = COMPOUND_STRING("G-MAX CENTIFERNO"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Centiskorch-G-Max-Angriff.\n"
            "Fängt Gegner in Flammen."),    //ANIM TODO
#else
            "G-max Centiskorch attack.\n"
            "Traps foes in flames."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxCentiferno,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FIRE_SPIN_SIDE,
        }),
    },

    [MOVE_G_MAX_SMITE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Sanktion"),
#else
        .name = COMPOUND_STRING("G-MAX SMITE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hatterene-G-Max-Angriff.\n"
            "Verwirrt die Gegner."),    //ANIM TODO
#else
            "G-max Hatterene attack.\n"
            "Confuses opponents."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSmite,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSE_SIDE,
        }),
    },


    [MOVE_G_MAX_SNOOZE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Gähnzwang"),
#else
        .name = COMPOUND_STRING("G-MAX SNOOZE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Grimmsnarl-G-Max-Angriff.\n"
            "Lässt Gegner einschlafen."),    //ANIM TODO
#else
            "G-max Grimmsnarl attack.\n"
            "Lulls foes into sleep."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSnooze,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_YAWN_FOE,
        }),
    },

    [MOVE_G_MAX_FINALE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Lichtblick"),
#else
        .name = COMPOUND_STRING("G-MAX FINALE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Alcremie-G-Max-Angriff.\n"
            "Heilt KP der Verbündeten."),    //ANIM TODO
#else
            "G-max Alcremie attack.\n"
            "Heals ally HP."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxFinale,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_HEAL_TEAM,
        }),
    },

    [MOVE_G_MAX_STEELSURGE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Stahlschlag"),
#else
        .name = COMPOUND_STRING("G-MAX STEELSURGE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Copperajah-G-Max-Angriff.\n"
            "Verstreut scharfe Stacheln."),    //ANIM TODO
#else
            "G-max Copperajah attack.\n"
            "Scatters sharp spikes."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxSteelsurge,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEELSURGE,
        }),
    },

    [MOVE_G_MAX_DEPLETION] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Dämpfer"),
#else
        .name = COMPOUND_STRING("G-MAX DEPLETION"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Duraludon-G-Max-Angriff.\n"
            "Senkt AP des Ziels."),    //ANIM TODO
#else
            "G-max Duraludon attack.\n"
            "Reduces target's PP."),    //ANIM TODO
#endif
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .battleAnimScript = gBattleAnimMove_GMaxDepletion,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPITE,
        }),
    },

    [MOVE_G_MAX_ONE_BLOW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Einzelhieb"),
#else
        .name = COMPOUND_STRING("G-MAX ONE BLOW"),
#endif
        .description = sGMaxOneBlowDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxOneBlow,
    },

    [MOVE_G_MAX_RAPID_FLOW] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Giga-Multihieb"),
#else
        .name = COMPOUND_STRING("G-MAX RAPID FLOW"),
#endif
        .description = sGMaxOneBlowDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .battleAnimScript = gBattleAnimMove_GMaxRapidFlow,
    },
};
