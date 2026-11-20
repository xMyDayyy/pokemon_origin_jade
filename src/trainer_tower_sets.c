#include "global.h"
#include "trainer_tower.h"
#include "text.h"
#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/trainer_tower.h"
#include "constants/trainers.h"

#define TRAINER_TOWER_OTID 0 | (4096 << 16)

#define PERSONALITY_FEMALE_ADAMANT     0x03
#define PERSONALITY_FEMALE_BOLD        0x05
#define PERSONALITY_FEMALE_BRAVE       0x02
#define PERSONALITY_FEMALE_CALM        0x14
#define PERSONALITY_FEMALE_CAREFUL     0x17
#define PERSONALITY_FEMALE_GENTLE      0x15
#define PERSONALITY_FEMALE_HARDY       0x00
#define PERSONALITY_FEMALE_HASTY       0x0B
#define PERSONALITY_FEMALE_IMPISH      0x08
#define PERSONALITY_FEMALE_JOLLY       0x0D
#define PERSONALITY_FEMALE_LAX         0x09
#define PERSONALITY_FEMALE_LONELY      0x01
#define PERSONALITY_FEMALE_MILD        0x10
#define PERSONALITY_FEMALE_MODEST      0x0F
#define PERSONALITY_FEMALE_NAIVE       0x0E
#define PERSONALITY_FEMALE_QUIET       0x11
#define PERSONALITY_FEMALE_RASH        0x13
#define PERSONALITY_FEMALE_RELAXED     0x07
#define PERSONALITY_FEMALE_SASSY       0x16
#define PERSONALITY_FEMALE_SERIOUS     0x0C
#define PERSONALITY_FEMALE_TIMID       0x0A
#define PERSONALITY_GENDERLESS_BOLD    0x05
#define PERSONALITY_GENDERLESS_CALM    0x14
#define PERSONALITY_GENDERLESS_JOLLY   0x0D
#define PERSONALITY_GENDERLESS_MILD    0x10
#define PERSONALITY_GENDERLESS_MODEST  0x0F
#define PERSONALITY_GENDERLESS_QUIET   0x11
#define PERSONALITY_GENDERLESS_RELAXED 0x07
#define PERSONALITY_GENDERLESS_TIMID   0x0A
#define PERSONALITY_MALE_ADAMANT       0x03
#define PERSONALITY_MALE_ADAMANT_2     0x35
#define PERSONALITY_MALE_ADAMANT_3     0x4E
#define PERSONALITY_MALE_ADAMANT_4     0x80
#define PERSONALITY_MALE_BOLD          0x37
#define PERSONALITY_MALE_BOLD_2        0x82
#define PERSONALITY_MALE_BRAVE         0x02
#define PERSONALITY_MALE_BRAVE_2       0x34
#define PERSONALITY_MALE_BRAVE_3       0x4D
#define PERSONALITY_MALE_BRAVE_4       0x7F
#define PERSONALITY_MALE_BRAVE_5       0xCA
#define PERSONALITY_MALE_CALM          0x2D
#define PERSONALITY_MALE_CALM_2        0x46
#define PERSONALITY_MALE_CALM_3        0x91
#define PERSONALITY_MALE_CAREFUL       0x30
#define PERSONALITY_MALE_CAREFUL_2     0x94
#define PERSONALITY_MALE_HARDY         0x00
#define PERSONALITY_MALE_HARDY_2       0x32
#define PERSONALITY_MALE_HARDY_3       0x96
#define PERSONALITY_MALE_HASTY         0x24
#define PERSONALITY_MALE_HASTY_2       0x56
#define PERSONALITY_MALE_HASTY_3       0x88
#define PERSONALITY_MALE_IMPISH        0x08
#define PERSONALITY_MALE_IMPISH_2      0x21
#define PERSONALITY_MALE_IMPISH_3      0x53
#define PERSONALITY_MALE_IMPISH_4      0x85
#define PERSONALITY_MALE_JOLLY         0x3F
#define PERSONALITY_MALE_JOLLY_2       0x8A
#define PERSONALITY_MALE_LONELY        0x33
#define PERSONALITY_MALE_LONELY_2      0x97
#define PERSONALITY_MALE_MILD          0x29
#define PERSONALITY_MALE_MODEST        0x0F
#define PERSONALITY_MALE_MODEST_2      0x41
#define PERSONALITY_MALE_MODEST_3      0x8C
#define PERSONALITY_MALE_NAIVE         0x40
#define PERSONALITY_MALE_NAUGHTY       0x4F
#define PERSONALITY_MALE_NAUGHTY_2     0x81
#define PERSONALITY_MALE_QUIET         0x2A
#define PERSONALITY_MALE_QUIET_2       0x43
#define PERSONALITY_MALE_QUIET_3       0x8E
#define PERSONALITY_MALE_QUIET_4       0xC0
#define PERSONALITY_MALE_RELAXED       0x07
#define PERSONALITY_MALE_RELAXED_2     0x20
#define PERSONALITY_MALE_RELAXED_3     0x84
#define PERSONALITY_MALE_RELAXED_4     0xCF
#define PERSONALITY_MALE_SASSY         0x93
#define PERSONALITY_MALE_SERIOUS       0x0C
#define PERSONALITY_MALE_SERIOUS_2     0x25
#define PERSONALITY_MALE_SERIOUS_3     0x57
#define PERSONALITY_MALE_SERIOUS_4     0x89
#define PERSONALITY_MALE_TIMID         0x0A
#define PERSONALITY_MALE_TIMID_2       0x23
#define PERSONALITY_MALE_TIMID_3       0x87
#define PERSONALITY_MALE_TIMID_4       0xD2

// Dummy strings must be declared explicitly for the sake of modern gcc
#define DUMMY_TOWER_MON(iv) {.hpIV = iv, .attackIV = iv, .defenseIV = iv, .speedIV = iv, .spAttackIV = iv, .spDefenseIV = iv, .nickname = _("$$$$$$$$$$")}
#define DUMMY_TOWER_TEAM(iv) {.name = _(""), .textColor = 1, .speechBefore = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, .speechWin = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, .speechLose = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, .speechAfter = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, .mons = {DUMMY_TOWER_MON(iv), DUMMY_TOWER_MON(iv), DUMMY_TOWER_MON(iv), DUMMY_TOWER_MON(iv), DUMMY_TOWER_MON(iv), DUMMY_TOWER_MON(iv)}}

static const struct TrainerTowerFloor sTrainerTowerFloor_Single_4 =
{
    .id = 1,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_WHITE_HERB,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Hendrik"),
#else
            .name = _("COLE"),
#endif
            .facilityClass = FACILITY_CLASS_YOUNGSTER_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_AHAHA, EC_WORD_YOU, EC_WORD_GOING, EC_WORD_DON_T, EC_WORD_WHERE, EC_WORD_EXCL},
            .speechWin = {EC_WORD_AS, EC_WORD_EXCL, EC_WORD_GOOD_BYE, EC_WORD_EXCL, 0xFFFF, 0xFFFF},
            .speechLose = {EC_WORD_HIYAH, EC_WORD_EXCL_EXCL, EC_WORD_DONE, EC_WORD_IN, EC_WORD_COMPLETE, EC_WORD_EXCL_EXCL},
            .speechAfter = {EC_WORD_TCH, EC_WORD_TCH, EC_WORD_YOU_RE, EC_WORD_TOO_STRONG, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_RATICATE,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_SHOCK_WAVE, MOVE_HYPER_FANG, MOVE_SCARY_FACE, MOVE_ENDEAVOR},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Rattikarl"),
#else
                    .nickname = _("RATICATE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAGMAR,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_FIRE_PUNCH, MOVE_SUNNY_DAY, MOVE_SMOG, MOVE_STRENGTH},
                    .hpEV = 100,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 210,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HASTY_2,
#if GERMAN
                    .nickname = _("Magmar"),
#else
                    .nickname = _("MAGMAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAGCARGO,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_FLAMETHROWER, MOVE_AMNESIA, MOVE_BODY_SLAM, MOVE_HARDEN},
                    .hpEV = 110,
                    .attackEV = 200,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 200,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_BRAVE,
#if GERMAN
                    .nickname = _("Magcargo"),
#else
                    .nickname = _("MAGCARGO"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PRIMEAPE,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_OVERHEAT, MOVE_SEISMIC_TOSS, MOVE_SWAGGER, MOVE_KARATE_CHOP},
                    .hpEV = 100,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 210,
                    .spAttackEV = 200,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID_3,
#if GERMAN
                    .nickname = _("Rasaff"),
#else
                    .nickname = _("PRIMEAPE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GOLBAT,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_GIGA_DRAIN, MOVE_CONFUSE_RAY, MOVE_SLUDGE_BOMB, MOVE_MEAN_LOOK},
                    .hpEV = 0,
                    .attackEV = 200,
                    .defenseEV = 0,
                    .speedEV = 110,
                    .spAttackEV = 200,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_NAUGHTY_2,
#if GERMAN
                    .nickname = _("Golbat"),
#else
                    .nickname = _("GOLBAT"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SLOWBRO,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_SUNNY_DAY, MOVE_YAWN, MOVE_FLAMETHROWER, MOVE_CONFUSION},
                    .hpEV = 100,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 210,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_QUIET,
#if GERMAN
                    .nickname = _("Lahmus"),
#else
                    .nickname = _("SLOWBRO"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00016aab
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Single_7 =
{
    .id = 2,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_DRAGON_SCALE,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Pavel"),
#else
            .name = _("JAC"),
#endif
            .facilityClass = FACILITY_CLASS_BURGLAR_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_MOVE2(THIEF), EC_WORD_EXCL, EC_WORD_GIMME, EC_WORD_SOMETHING},
            .speechWin = {EC_WORD_YOU_VE, EC_WORD_NOTHING, EC_WORD_WHAT, EC_WORD_I, EC_WORD_NEED, 0xFFFF},
            .speechLose = {EC_WORD_EEK, EC_WORD_EXCL_EXCL, EC_WORD_I, EC_WORD_SORRY, EC_WORD_I, EC_WORD_GIVE_UP},
            .speechAfter = {EC_WORD_I, EC_WORD_WANTS, EC_WORD_NONE, EC_MOVE2(THIEF), EC_WORD_MORE, EC_WORD_MAKE},
            .mons =
            {
                {
                    .species = SPECIES_MEOWTH,
                    .heldItem = ITEM_LIECHI_BERRY,
                    .moves = {MOVE_SWAGGER, MOVE_SUBSTITUTE, MOVE_FAKE_OUT, MOVE_SLASH},
                    .hpEV = 200,
                    .attackEV = 110,
                    .defenseEV = 0,
                    .speedEV = 200,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = 138 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Mauzi"),
#else
                    .nickname = _("MEOWTH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FLAREON,
                    .heldItem = ITEM_PETAYA_BERRY,
                    .moves = {MOVE_FLAMETHROWER, MOVE_BITE, MOVE_SAND_ATTACK, MOVE_FIRE_SPIN},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 200,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Flamara"),
#else
                    .nickname = _("FLAREON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PORYGON,
                    .heldItem = ITEM_PETAYA_BERRY,
                    .moves = {MOVE_TRI_ATTACK, MOVE_RECYCLE, MOVE_PSYBEAM, MOVE_CONVERSION_2},
                    .hpEV = 100,
                    .attackEV = 0,
                    .defenseEV = 210,
                    .speedEV = 0,
                    .spAttackEV = 200,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_GENDERLESS_RELAXED,
#if GERMAN
                    .nickname = _("Porygon"),
#else
                    .nickname = _("PORYGON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CHANSEY,
                    .heldItem = ITEM_LUCKY_PUNCH,
                    .moves = {MOVE_FLAMETHROWER, MOVE_LIGHT_SCREEN, MOVE_BODY_SLAM, MOVE_MINIMIZE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_MILD,
#if GERMAN
                    .nickname = _("Chaneira"),
#else
                    .nickname = _("CHANSEY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FARFETCHD,
                    .heldItem = ITEM_STICK,
                    .moves = {MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE, MOVE_FLY, MOVE_SAND_ATTACK},
                    .hpEV = 100,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 110,
                    .otId = 133 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_IMPISH_4,
#if GERMAN
                    .nickname = _("Porenta"),
#else
                    .nickname = _("FARFETCH'D"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MR_MIME,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_SUBSTITUTE, MOVE_SHOCK_WAVE, MOVE_LIGHT_SCREEN, MOVE_BRICK_BREAK},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = 130 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BOLD_2,
#if GERMAN
                    .nickname = _("Pantimos"),
#else
                    .nickname = _("MR. MIME"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00016456
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Single_Unused =
{
    .id = 3,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_IRON,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Beate"),
#else
            .name = _("MILY"),
#endif
            .facilityClass = FACILITY_CLASS_PSYCHIC_F_FRLG,
            .textColor = 1,
            .speechBefore = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechWin = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechAfter = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_CHANSEY,
                    .heldItem = ITEM_ORAN_BERRY,
                    .moves = {MOVE_LIGHT_SCREEN, MOVE_EGG_BOMB, MOVE_MINIMIZE, MOVE_SECRET_POWER},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_IMPISH,
#if GERMAN
                    .nickname = _("Chaneira"),
#else
                    .nickname = _("CHANSEY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CLEFABLE,
                    .heldItem = ITEM_ORAN_BERRY,
                    .moves = {MOVE_METRONOME, MOVE_REFLECT, MOVE_SING, MOVE_POUND},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Pixi"),
#else
                    .nickname = _("CLEFABLE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TOGETIC,
                    .heldItem = ITEM_ORAN_BERRY,
                    .moves = {MOVE_METRONOME, MOVE_REFLECT, MOVE_SWEET_KISS, MOVE_PECK},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Togetic"),
#else
                    .nickname = _("TOGETIC"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TOGETIC,
                    .heldItem = ITEM_ORAN_BERRY,
                    .moves = {MOVE_METRONOME, MOVE_HIDDEN_POWER, MOVE_ATTRACT, MOVE_LIGHT_SCREEN},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_RELAXED_2,
#if GERMAN
                    .nickname = _("Togetic"),
#else
                    .nickname = _("TOGETIC"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CHANSEY,
                    .heldItem = ITEM_ORAN_BERRY,
                    .moves = {MOVE_FLAMETHROWER, MOVE_SOFT_BOILED, MOVE_LIGHT_SCREEN, MOVE_SECRET_POWER},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_BOLD,
#if GERMAN
                    .nickname = _("Chaneira"),
#else
                    .nickname = _("CHANSEY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CLEFABLE,
                    .heldItem = ITEM_ORAN_BERRY,
                    .moves = {MOVE_REFLECT, MOVE_FLAMETHROWER, MOVE_SING, MOVE_BODY_SLAM},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 200,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_QUIET_4,
#if GERMAN
                    .nickname = _("Pixi"),
#else
                    .nickname = _("CLEFABLE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x000164ec
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_5 = {
    .id = 4,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_CHOICE_BAND,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Urs&karo"),
#else
            .name = _("JOS & ANNE"),
#endif
            .facilityClass = FACILITY_CLASS_COOL_COUPLE_FRLG,
            .textColor = 7,
            .speechBefore = {EC_WORD_HERE_GOES, EC_WORD_EXCL_EXCL, EC_WORD_DO, EC_WORD_READY, EC_WORD_TO, EC_WORD_LOSE},
            .speechWin = {EC_WORD_PERFECT, EC_WORD_EXCL, EC_WORD_WE, EC_WORD_GOT, EC_WORD_WON, EC_WORD_EXCL},
            .speechLose = {EC_WORD_LOST, EC_WORD_QUES_EXCL, EC_WORD_YOU, EC_WORD_MUST_BE, EC_WORD_FULL, EC_WORD_JOKING},
            .speechAfter = {EC_WORD_HOW_DO, EC_WORD_CAN, EC_WORD_I, EC_WORD_THAT, EC_WORD_LOSE, EC_WORD_QUES},
            .mons =
            {
                {
                    .species = SPECIES_RAPIDASH,
                    .heldItem = ITEM_WHITE_HERB,
                    .moves = {MOVE_BOUNCE, MOVE_OVERHEAT, MOVE_HYPNOSIS, MOVE_RETURN},
                    .hpEV = 100,
                    .attackEV = 100,
                    .defenseEV = 0,
                    .speedEV = 110,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_MILD,
#if GERMAN
                    .nickname = _("Gallopa"),
#else
                    .nickname = _("RAPIDASH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NINETALES,
                    .heldItem = ITEM_CHARCOAL,
                    .moves = {MOVE_CONFUSE_RAY, MOVE_WILL_O_WISP, MOVE_HEAT_WAVE, MOVE_DIG},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 200,
                    .spAttackEV = 200,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_GENTLE,
#if GERMAN
                    .nickname = _("Vulnona"),
#else
                    .nickname = _("NINETALES"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MISDREAVUS,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_GRUDGE, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT},
                    .hpEV = 200,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 210,
                    .spAttackEV = 100,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Traunfugil"),
#else
                    .nickname = _("MISDREAVUS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ALAKAZAM,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_LIGHT_SCREEN, MOVE_RECOVER, MOVE_PSYCHIC, MOVE_THUNDER_PUNCH},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Simsala"),
#else
                    .nickname = _("ALAKAZAM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_BLISSEY,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_LIGHT_SCREEN, MOVE_ATTRACT, MOVE_RETURN, MOVE_PSYCHIC},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Heiteira"),
#else
                    .nickname = _("BLISSEY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CROBAT,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_TOXIC, MOVE_FLY, MOVE_CONFUSE_RAY, MOVE_SHADOW_BALL},
                    .hpEV = 100,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 210,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CAREFUL,
#if GERMAN
                    .nickname = _("Iksbat"),
#else
                    .nickname = _("CROBAT"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Urs&karo"),
#else
            .name = _("JOS & ANNE"),
#endif
            .facilityClass = FACILITY_CLASS_COOL_COUPLE_FRLG,
            .textColor = 7,
            .speechBefore = {EC_WORD_HERE_GOES, EC_WORD_EXCL_EXCL, EC_WORD_DO, EC_WORD_READY, EC_WORD_TO, EC_WORD_LOSE},
            .speechWin = {EC_WORD_PERFECT, EC_WORD_EXCL, EC_WORD_WE, EC_WORD_GOT, EC_WORD_WON, EC_WORD_EXCL},
            .speechLose = {EC_WORD_LOST, EC_WORD_QUES_EXCL, EC_WORD_YOU, EC_WORD_MUST_BE, EC_WORD_FULL, EC_WORD_JOKING},
            .speechAfter = {EC_WORD_HOW_DO, EC_WORD_CAN, EC_WORD_I, EC_WORD_THAT, EC_WORD_LOSE, EC_WORD_QUES},
            .mons =
            {
                {
                    .species = SPECIES_HOUNDOOM,
                    .heldItem = ITEM_CHARCOAL,
                    .moves = {MOVE_TAUNT, MOVE_FLAMETHROWER, MOVE_WILL_O_WISP, MOVE_CRUNCH},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_BOLD_2,
#if GERMAN
                    .nickname = _("Hundemon"),
#else
                    .nickname = _("HOUNDOOM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_AERODACTYL,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_ROAR, MOVE_FIRE_BLAST, MOVE_HYPER_BEAM, MOVE_AERIAL_ACE},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_LONELY,
#if GERMAN
                    .nickname = _("Aerodactyl"),
#else
                    .nickname = _("AERODACTYL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ARCANINE,
                    .heldItem = ITEM_CHARCOAL,
                    .moves = {MOVE_HEAT_WAVE, MOVE_EXTREME_SPEED, MOVE_ROAR, MOVE_DIG},
                    .hpEV = 210,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 200,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HASTY_2,
#if GERMAN
                    .nickname = _("Arkani"),
#else
                    .nickname = _("ARCANINE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_WEEZING,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_EXPLOSION, MOVE_SMOKESCREEN, MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT},
                    .hpEV = 100,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 110,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_QUIET_3,
#if GERMAN
                    .nickname = _("Smogmog"),
#else
                    .nickname = _("WEEZING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CHARIZARD,
                    .heldItem = ITEM_WHITE_HERB,
                    .moves = {MOVE_OVERHEAT, MOVE_OUTRAGE, MOVE_DRAGON_RAGE, MOVE_SMOKESCREEN},
                    .hpEV = 100,
                    .attackEV = 110,
                    .defenseEV = 0,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_LONELY,
#if GERMAN
                    .nickname = _("Glurak"),
#else
                    .nickname = _("CHARIZARD"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GENGAR,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT},
                    .hpEV = 55,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID_3,
#if GERMAN
                    .nickname = _("Gengar"),
#else
                    .nickname = _("GENGAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00017908
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_6 = {
    .id = 5,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_CALCIUM,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Eva&tim"),
#else
            .name = _("EMY & ALEK"),
#endif
            .facilityClass = FACILITY_CLASS_YOUNG_COUPLE_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_GIDDY, EC_WORD_FROM, EC_WORD_LOVEY_DOVEY, EC_WORD_JOY, EC_WORD_EXCL_EXCL},
            .speechWin = {EC_WORD_SIGH, EC_WORD_ELLIPSIS, EC_WORD_MY, EC_WORD_GIRL, EC_WORD_IS, EC_WORD_CUTE},
            .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCL_EXCL, EC_WORD_YOU, EC_WORD_ARE, EC_WORD_DON_T, EC_WORD_SERIOUSLY},
            .speechAfter = {EC_WORD_QUES_EXCL, EC_WORD_ELLIPSIS, EC_WORD_WHO, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_QUES},
            .mons =
            {
                {
                    .species = SPECIES_TAUROS,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_FLAMETHROWER, MOVE_REST, MOVE_SHOCK_WAVE, MOVE_DOUBLE_TEAM},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID,
#if GERMAN
                    .nickname = _("Tauros"),
#else
                    .nickname = _("TAUROS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_KANGASKHAN,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_FLAMETHROWER, MOVE_DIZZY_PUNCH, MOVE_REST, MOVE_FAKE_OUT},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BRAVE,
#if GERMAN
                    .nickname = _("Kangama"),
#else
                    .nickname = _("KANGASKHAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FEAROW,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_DRILL_PECK, MOVE_TRI_ATTACK, MOVE_DOUBLE_EDGE, MOVE_REST},
                    .hpEV = 100,
                    .attackEV = 210,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CAREFUL_2,
#if GERMAN
                    .nickname = _("Ibitak"),
#else
                    .nickname = _("FEAROW"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TOGETIC,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_FLAMETHROWER, MOVE_LIGHT_SCREEN, MOVE_REST, MOVE_ANCIENT_POWER},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_HASTY,
#if GERMAN
                    .nickname = _("Togetic"),
#else
                    .nickname = _("TOGETIC"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PIDGEOT,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_STEEL_WING, MOVE_FLY, MOVE_MIRROR_MOVE, MOVE_REST},
                    .hpEV = 100,
                    .attackEV = 110,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_JOLLY,
#if GERMAN
                    .nickname = _("Tauboss"),
#else
                    .nickname = _("PIDGEOT"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_URSARING,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_REST, MOVE_SNORE, MOVE_DIG, MOVE_SLASH},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Ursaring"),
#else
                    .nickname = _("URSARING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Eva&tim"),
#else
            .name = _("EMY & ALEK"),
#endif
            .facilityClass = FACILITY_CLASS_YOUNG_COUPLE_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_GIDDY, EC_WORD_FROM, EC_WORD_LOVEY_DOVEY, EC_WORD_JOY, EC_WORD_EXCL_EXCL},
            .speechWin = {EC_WORD_SIGH, EC_WORD_ELLIPSIS, EC_WORD_MY, EC_WORD_GIRL, EC_WORD_IS, EC_WORD_CUTE},
            .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCL_EXCL, EC_WORD_YOU, EC_WORD_ARE, EC_WORD_DON_T, EC_WORD_SERIOUSLY},
            .speechAfter = {EC_WORD_QUES_EXCL, EC_WORD_ELLIPSIS, EC_WORD_WHO, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_QUES},
            .mons =
            {
                {
                    .species = SPECIES_LICKITUNG,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_FLAMETHROWER, MOVE_EARTHQUAKE, MOVE_REST, MOVE_SLEEP_TALK},
                    .hpEV = 0,
                    .attackEV = 100,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 55,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Schlurp"),
#else
                    .nickname = _("LICKITUNG"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NOCTOWL,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_REFLECT, MOVE_AERIAL_ACE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HASTY,
#if GERMAN
                    .nickname = _("Noctuh"),
#else
                    .nickname = _("NOCTOWL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FURRET,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_FLAMETHROWER, MOVE_AMNESIA, MOVE_SHOCK_WAVE, MOVE_SLASH},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_NAIVE,
#if GERMAN
                    .nickname = _("Wiesenior"),
#else
                    .nickname = _("FURRET"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RATICATE,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_SUPER_FANG, MOVE_QUICK_ATTACK, MOVE_SWAGGER, MOVE_ENDEAVOR},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Rattikarl"),
#else
                    .nickname = _("RATICATE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_WIGGLYTUFF,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_SUNNY_DAY, MOVE_FLAMETHROWER, MOVE_ATTRACT, MOVE_BODY_SLAM},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HASTY,
#if GERMAN
                    .nickname = _("Knuddeluff"),
#else
                    .nickname = _("WIGGLYTUFF"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PORYGON2,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_THUNDERBOLT, MOVE_CONVERSION_2, MOVE_TRI_ATTACK, MOVE_RECOVER},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_GENDERLESS_TIMID,
#if GERMAN
                    .nickname = _("Porygon2"),
#else
                    .nickname = _("PORYGON2"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00015d3b
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_2 = {
    .id = 6,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_HP_UP,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Udo&gabi"),
#else
            .name = _("JO & HALEY"),
#endif
            .facilityClass = FACILITY_CLASS_CRUSH_KIN_FRLG,
            .textColor = 5,
            .speechBefore = {EC_WORD_YOU, EC_WORD_YOU, EC_WORD_YOU, EC_WORD_WINS, EC_WORD_BETTER, EC_WORD_DON_T},
            .speechWin = {EC_WORD_YOU, EC_WORD_DON_T, EC_WORD_JOKING, EC_WORD_QUES, EC_WORD_WE, EC_WORD_WON},
            .speechLose = {EC_WORD_WIMPY, EC_WORD_ELLIPSIS, EC_WORD_WE, EC_WORD_BEEN, EC_WORD_WEAK, EC_WORD_ELLIPSIS},
            .speechAfter = {EC_WORD_HAHAHA, EC_WORD_ELLIPSIS, EC_WORD_WE_RE, EC_WORD_FULL, EC_WORD_USELESS, EC_WORD_ELLIPSIS},
            .mons =
            {
                {
                    .species = SPECIES_SNEASEL,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_SHADOW_BALL, MOVE_SUNNY_DAY, MOVE_TAUNT, MOVE_AERIAL_ACE},
                    .hpEV = 200,
                    .attackEV = 0,
                    .defenseEV = 50,
                    .speedEV = 210,
                    .spAttackEV = 0,
                    .spDefenseEV = 50,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_JOLLY,
#if GERMAN
                    .nickname = _("Sniebel"),
#else
                    .nickname = _("SNEASEL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ALAKAZAM,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_FIRE_PUNCH, MOVE_RECOVER, MOVE_PSYCHIC, MOVE_SUNNY_DAY},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BOLD,
#if GERMAN
                    .nickname = _("Simsala"),
#else
                    .nickname = _("ALAKAZAM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_HITMONTOP,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_MEGA_KICK, MOVE_ENDEAVOR, MOVE_DIG, MOVE_SUNNY_DAY},
                    .hpEV = 100,
                    .attackEV = 210,
                    .defenseEV = 0,
                    .speedEV = 200,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_IMPISH,
#if GERMAN
                    .nickname = _("Kapoera"),
#else
                    .nickname = _("HITMONTOP"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GIRAFARIG,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_LIGHT_SCREEN, MOVE_SUNNY_DAY, MOVE_SHADOW_BALL, MOVE_PSYBEAM},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Girafarig"),
#else
                    .nickname = _("GIRAFARIG"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_XATU,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_SUNNY_DAY, MOVE_DRILL_PECK, MOVE_CONFUSE_RAY, MOVE_PSYCHIC},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CALM,
#if GERMAN
                    .nickname = _("Xatu"),
#else
                    .nickname = _("XATU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MR_MIME,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_REFLECT, MOVE_SUNNY_DAY, MOVE_PSYCHIC, MOVE_SHOCK_WAVE},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 200,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BOLD,
#if GERMAN
                    .nickname = _("Pantimos"),
#else
                    .nickname = _("MR. MIME"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Udo&gabi"),
#else
            .name = _("JO & HALEY"),
#endif
            .facilityClass = FACILITY_CLASS_CRUSH_KIN_FRLG,
            .textColor = 5,
            .speechBefore = {EC_WORD_YOU, EC_WORD_YOU, EC_WORD_YOU, EC_WORD_WINS, EC_WORD_BETTER, EC_WORD_DON_T},
            .speechWin = {EC_WORD_YOU, EC_WORD_DON_T, EC_WORD_JOKING, EC_WORD_QUES, EC_WORD_WE, EC_WORD_WON},
            .speechLose = {EC_WORD_WIMPY, EC_WORD_ELLIPSIS, EC_WORD_WE, EC_WORD_BEEN, EC_WORD_WEAK, EC_WORD_ELLIPSIS},
            .speechAfter = {EC_WORD_HAHAHA, EC_WORD_ELLIPSIS, EC_WORD_WE_RE, EC_WORD_FULL, EC_WORD_USELESS, EC_WORD_ELLIPSIS},
            .mons =
            {
                {
                    .species = SPECIES_HYPNO,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_FIRE_PUNCH, MOVE_HYPNOSIS, MOVE_PSYCHIC, MOVE_NIGHTMARE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID_3,
#if GERMAN
                    .nickname = _("Hypno"),
#else
                    .nickname = _("HYPNO"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_HITMONCHAN,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_FIRE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_DETECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_MODEST,
#if GERMAN
                    .nickname = _("Nockchan"),
#else
                    .nickname = _("HITMONCHAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MACHAMP,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_FLAMETHROWER, MOVE_BRICK_BREAK, MOVE_SCARY_FACE, MOVE_DIG},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_QUIET_2,
#if GERMAN
                    .nickname = _("Machomei"),
#else
                    .nickname = _("MACHAMP"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_HOUNDOOM,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_ROAR, MOVE_FLAMETHROWER, MOVE_BITE, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID_3,
#if GERMAN
                    .nickname = _("Hundemon"),
#else
                    .nickname = _("HOUNDOOM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PRIMEAPE,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_OVERHEAT, MOVE_SWAGGER, MOVE_SEISMIC_TOSS, MOVE_DOUBLE_TEAM},
                    .hpEV = 100,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 110,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_MODEST_3,
#if GERMAN
                    .nickname = _("Rasaff"),
#else
                    .nickname = _("PRIMEAPE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_HERACROSS,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_LEER},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_IMPISH_4,
#if GERMAN
                    .nickname = _("Skaraborn"),
#else
                    .nickname = _("HERACROSS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x000160b1
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Knockout_1 = {
    .id = 7,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_KNOCKOUT,
    .prize = TTPRIZE_METAL_COAT,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Miguel"),
#else
            .name = _("JORDY"),
#endif
            .facilityClass = FACILITY_CLASS_BIKER_FRLG,
            .textColor = 3,
            .speechBefore = {EC_WORD_DON_T, EC_WORD_MAKE, EC_WORD_ME, EC_WORD_GIGGLE, EC_WORD_YOU, EC_WORD_PUSHOVER},
            .speechWin = {EC_WORD_WHAT, EC_WORD_FOR, EC_WORD_AN, EC_WORD_PUSHOVER, EC_WORD_YOU_RE, EC_WORD_EXCL},
            .speechLose = {EC_WORD_YOU, EC_WORD_GOT, EC_WORD_FULL, EC_WORD_FIGHTING, EC_WORD_MAKE, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_DARN, EC_WORD_EXCL, EC_WORD_I, EC_WORD_UNDERSTAND, EC_WORD_IT, EC_WORD_DON_T},
            .mons =
            {
                {
                    .species = SPECIES_MAGBY,
                    .heldItem = ITEM_LAX_INCENSE,
                    .moves = {MOVE_SMOKESCREEN, MOVE_CONFUSE_RAY, MOVE_FLAMETHROWER, MOVE_SCREECH},
                    .hpEV = 210,
                    .attackEV = 30,
                    .defenseEV = 30,
                    .speedEV = 0,
                    .spAttackEV = 210,
                    .spDefenseEV = 30,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_QUIET_2,
#if GERMAN
                    .nickname = _("Magby"),
#else
                    .nickname = _("MAGBY"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_CLEFFA,
                    .heldItem = ITEM_LAX_INCENSE,
                    .moves = {MOVE_ATTRACT, MOVE_CHARM, MOVE_SECRET_POWER, MOVE_FLASH},
                    .hpEV = 210,
                    .attackEV = 210,
                    .defenseEV = 30,
                    .speedEV = 0,
                    .spAttackEV = 30,
                    .spDefenseEV = 30,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE_5,
#if GERMAN
                    .nickname = _("Pii"),
#else
                    .nickname = _("CLEFFA"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_IGGLYBUFF,
                    .heldItem = ITEM_LAX_INCENSE,
                    .moves = {MOVE_SING, MOVE_HIDDEN_POWER, MOVE_CHARM, MOVE_DOUBLE_TEAM},
                    .hpEV = 210,
                    .attackEV = 0,
                    .defenseEV = 45,
                    .speedEV = 210,
                    .spAttackEV = 0,
                    .spDefenseEV = 45,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID_4,
#if GERMAN
                    .nickname = _("Fluffeluff"),
#else
                    .nickname = _("IGGLYBUFF"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SMOOCHUM,
                    .heldItem = ITEM_LAX_INCENSE,
                    .moves = {MOVE_FAKE_TEARS, MOVE_PSYCHIC, MOVE_MEAN_LOOK, MOVE_SING},
                    .hpEV = 210,
                    .attackEV = 0,
                    .defenseEV = 45,
                    .speedEV = 0,
                    .spAttackEV = 210,
                    .spDefenseEV = 45,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_QUIET,
#if GERMAN
                    .nickname = _("Kussilla"),
#else
                    .nickname = _("SMOOCHUM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TOGEPI,
                    .heldItem = ITEM_LAX_INCENSE,
                    .moves = {MOVE_SWEET_KISS, MOVE_YAWN, MOVE_ANCIENT_POWER, MOVE_DOUBLE_TEAM},
                    .hpEV = 210,
                    .attackEV = 210,
                    .defenseEV = 45,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 45,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_BRAVE_2,
#if GERMAN
                    .nickname = _("Togepi"),
#else
                    .nickname = _("TOGEPI"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_PICHU,
                    .heldItem = ITEM_LAX_INCENSE,
                    .moves = {MOVE_THUNDER_WAVE, MOVE_SHOCK_WAVE, MOVE_SWEET_KISS, MOVE_FLASH},
                    .hpEV = 210,
                    .attackEV = 0,
                    .defenseEV = 45,
                    .speedEV = 0,
                    .spAttackEV = 210,
                    .spDefenseEV = 45,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_QUIET_3,
#if GERMAN
                    .nickname = _("Pichu"),
#else
                    .nickname = _("PICHU"),
#endif
                    .friendship = 0
                },
            }
        },
        {
#if GERMAN
            .name = _("Elert"),
#else
            .name = _("ERNEST"),
#endif
            .facilityClass = FACILITY_CLASS_BIKER_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_SLEEP, EC_WORD_TIME, EC_WORD_FOR, EC_WORD_CHILDREN, EC_WORD_EXCL},
            .speechWin = {EC_WORD_DON_T, EC_WORD_GUTSY, EC_WORD_THOSE_WERE, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {EC_WORD_WHY, EC_WORD_DID, EC_WORD_YOU, EC_WORD_CRUSH, EC_WORD_ME, EC_WORD_QUES},
            .speechAfter = {EC_WORD_I_AM, EC_WORD_DEFEATED, EC_WORD_I, EC_WORD_NEED, EC_WORD_A, EC_WORD_NAP},
            .mons =
            {
                {
                    .species = SPECIES_CLEFFA,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_SWEET_KISS, MOVE_FRUSTRATION, MOVE_SING, MOVE_ATTRACT},
                    .hpEV = 210,
                    .attackEV = 210,
                    .defenseEV = 45,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 45,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE_5,
#if GERMAN
                    .nickname = _("Pii"),
#else
                    .nickname = _("CLEFFA"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_MAGBY,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_FRUSTRATION, MOVE_CONFUSE_RAY, MOVE_FLAMETHROWER, MOVE_TOXIC},
                    .hpEV = 90,
                    .attackEV = 210,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 210,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE_3,
#if GERMAN
                    .nickname = _("Magby"),
#else
                    .nickname = _("MAGBY"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_TOGEPI,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_FRUSTRATION, MOVE_DOUBLE_TEAM, MOVE_TOXIC, MOVE_SWEET_KISS},
                    .hpEV = 210,
                    .attackEV = 210,
                    .defenseEV = 45,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 45,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_BRAVE_2,
#if GERMAN
                    .nickname = _("Togepi"),
#else
                    .nickname = _("TOGEPI"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_SMOOCHUM,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_MEAN_LOOK, MOVE_PERISH_SONG, MOVE_TOXIC, MOVE_FLASH},
                    .hpEV = 90,
                    .attackEV = 0,
                    .defenseEV = 210,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 210,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Kussilla"),
#else
                    .nickname = _("SMOOCHUM"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_IGGLYBUFF,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_DOUBLE_TEAM, MOVE_SWEET_KISS, MOVE_SEISMIC_TOSS, MOVE_FLASH},
                    .hpEV = 210,
                    .attackEV = 0,
                    .defenseEV = 45,
                    .speedEV = 210,
                    .spAttackEV = 0,
                    .spDefenseEV = 45,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Fluffeluff"),
#else
                    .nickname = _("IGGLYBUFF"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_PICHU,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_TAIL_WHIP, MOVE_FRUSTRATION, MOVE_ATTRACT, MOVE_THUNDER_WAVE},
                    .hpEV = 90,
                    .attackEV = 210,
                    .defenseEV = 0,
                    .speedEV = 210,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Pichu"),
#else
                    .nickname = _("PICHU"),
#endif
                    .friendship = 0
                },
            }
        },
        {
#if GERMAN
            .name = _("Karl"),
#else
            .name = _("GABRIEL"),
#endif
            .facilityClass = FACILITY_CLASS_CUE_BALL_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_YAHOO, EC_WORD_EXCL, EC_WORD_HERE_I_COME, EC_WORD_BABE, EC_WORD_TO, EC_WORD_SWARM},
            .speechWin = {EC_WORD_I_AM, EC_WORD_INVINCIBLE, EC_WORD_YOU, EC_WORD_MUST_BE, EC_WORD_KNOW, EC_WORD_ELLIPSIS},
            .speechLose = {EC_WORD_WHAT, EC_WORD_WAS, EC_WORD_THAT, EC_WORD_QUES, 0xFFFF, 0xFFFF},
            .speechAfter = {EC_WORD_NEXT, EC_WORD_TIME, EC_WORD_WILL, EC_WORD_I, EC_WORD_WIN, EC_WORD_EXCL},
            .mons =
            {
                {
                    .species = SPECIES_PICHU,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_THUNDER_WAVE, MOVE_FRUSTRATION, MOVE_THUNDERBOLT, MOVE_ATTRACT},
                    .hpEV = 90,
                    .attackEV = 210,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 210,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_NAUGHTY_2,
#if GERMAN
                    .nickname = _("Pichu"),
#else
                    .nickname = _("PICHU"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_TOGEPI,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_ATTRACT, MOVE_FRUSTRATION, MOVE_TOXIC, MOVE_SUBSTITUTE},
                    .hpEV = 210,
                    .attackEV = 210,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 90,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_LONELY,
#if GERMAN
                    .nickname = _("Togepi"),
#else
                    .nickname = _("TOGEPI"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_CLEFFA,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_ENCORE, MOVE_TOXIC, MOVE_DOUBLE_TEAM, MOVE_FLASH},
                    .hpEV = 210,
                    .attackEV = 0,
                    .defenseEV = 150,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 150,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_RELAXED_4,
#if GERMAN
                    .nickname = _("Pii"),
#else
                    .nickname = _("CLEFFA"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_IGGLYBUFF,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_ATTRACT, MOVE_SUBSTITUTE, MOVE_SING, MOVE_PERISH_SONG},
                    .hpEV = 210,
                    .attackEV = 0,
                    .defenseEV = 210,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 90,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_RELAXED_4,
#if GERMAN
                    .nickname = _("Fluffeluff"),
#else
                    .nickname = _("IGGLYBUFF"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_SMOOCHUM,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_SWEET_KISS, MOVE_PERISH_SONG, MOVE_TOXIC, MOVE_ATTRACT},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Kussilla"),
#else
                    .nickname = _("SMOOCHUM"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_MAGBY,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_LEER, MOVE_FRUSTRATION, MOVE_SUBSTITUTE, MOVE_FLAMETHROWER},
                    .hpEV = 90,
                    .attackEV = 210,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 210,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE_3,
#if GERMAN
                    .nickname = _("Magby"),
#else
                    .nickname = _("MAGBY"),
#endif
                    .friendship = 0
                },
            }
        },
    },
    .checksum = 0x00017a4a
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Knockout_2 = {
    .id = 8,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_KNOCKOUT,
    .prize = TTPRIZE_UP_GRADE,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Melvin"),
#else
            .name = _("MIKE"),
#endif
            .facilityClass = FACILITY_CLASS_HIKER_FRLG,
            .textColor = 5,
            .speechBefore = {EC_WORD_WHO_WAS, EC_WORD_POKEMON, EC_WORD_THOSE, EC_WORD_FULL, EC_WORD_FROM, EC_WORD_POWER},
            .speechWin = {EC_WORD_WHAT_S_UP_QUES, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_YOURS, EC_WORD_POWER, EC_WORD_QUES},
            .speechLose = {EC_WORD_YOU_VE, EC_WORD_ME, EC_WORD_WITH, EC_MOVE2(FAKE_OUT), EC_WORD_DEFEATED, EC_WORD_ELLIPSIS},
            .speechAfter = {EC_WORD_OH_YEAH, EC_WORD_EXCL, EC_WORD_IT_S, EC_WORD_VERY, EC_WORD_EXCELLENT, EC_WORD_EXCL},
            .mons =
            {
                {
                    .species = SPECIES_PINSIR,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_GUILLOTINE, MOVE_BRICK_BREAK, MOVE_DIG, MOVE_REVENGE},
                    .hpEV = 100,
                    .attackEV = 210,
                    .defenseEV = 0,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Pinsir"),
#else
                    .nickname = _("PINSIR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CHARIZARD,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_DRAGON_CLAW, MOVE_METAL_CLAW, MOVE_AERIAL_ACE, MOVE_OUTRAGE},
                    .hpEV = 200,
                    .attackEV = 200,
                    .defenseEV = 0,
                    .speedEV = 110,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_2,
#if GERMAN
                    .nickname = _("Glurak"),
#else
                    .nickname = _("CHARIZARD"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RHYDON,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_MEGAHORN, MOVE_HORN_DRILL, MOVE_CRUSH_CLAW, MOVE_BRICK_BREAK},
                    .hpEV = 100,
                    .attackEV = 210,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_LAX,
#if GERMAN
                    .nickname = _("Rizeros"),
#else
                    .nickname = _("RHYDON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ARCANINE,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_EXTREME_SPEED, MOVE_IRON_TAIL, MOVE_AERIAL_ACE, MOVE_DIG},
                    .hpEV = 110,
                    .attackEV = 200,
                    .defenseEV = 0,
                    .speedEV = 200,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY,
#if GERMAN
                    .nickname = _("Arkani"),
#else
                    .nickname = _("ARCANINE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GOLEM,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_DOUBLE_EDGE, MOVE_ROLLOUT, MOVE_BRICK_BREAK, MOVE_DIG},
                    .hpEV = 100,
                    .attackEV = 210,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BRAVE,
#if GERMAN
                    .nickname = _("Geowaz"),
#else
                    .nickname = _("GOLEM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_HOUNDOOM,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_CRUNCH, MOVE_REVERSAL, MOVE_DOUBLE_EDGE, MOVE_COUNTER},
                    .hpEV = 200,
                    .attackEV = 110,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_IMPISH,
#if GERMAN
                    .nickname = _("Hundemon"),
#else
                    .nickname = _("HOUNDOOM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Silke"),
#else
            .name = _("REBECCA"),
#endif
            .facilityClass = FACILITY_CLASS_CRUSH_GIRL_FRLG,
            .textColor = 5,
            .speechBefore = {EC_WORD_I, EC_WORD_WANTS, EC_WORD_WINS, EC_WORD_EXCL, 0xFFFF, 0xFFFF},
            .speechWin = {EC_WORD_TO, EC_WORD_WELL, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_OVERWHELMING, EC_WORD_EXCL},
            .speechLose = {EC_WORD_ARRGH, EC_WORD_EXCL_EXCL, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechAfter = {EC_WORD_YOU, EC_WORD_ANGERS, EC_WORD_ME, EC_WORD_BUT, EC_WORD_YOU_RE, EC_WORD_TOUGH},
            .mons =
            {
                {
                    .species = SPECIES_SANDSLASH,
                    .heldItem = ITEM_SILK_SCARF,
                    .moves = {MOVE_CRUSH_CLAW, MOVE_DIG, MOVE_DOUBLE_EDGE, MOVE_AERIAL_ACE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_JOLLY,
#if GERMAN
                    .nickname = _("Sandamer"),
#else
                    .nickname = _("SANDSLASH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_DRAGONAIR,
                    .heldItem = ITEM_SILK_SCARF,
                    .moves = {MOVE_OUTRAGE, MOVE_IRON_TAIL, MOVE_DOUBLE_EDGE, MOVE_SLAM},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_ADAMANT,
#if GERMAN
                    .nickname = _("Dragonir"),
#else
                    .nickname = _("DRAGONAIR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RAPIDASH,
                    .heldItem = ITEM_SILK_SCARF,
                    .moves = {MOVE_BOUNCE, MOVE_IRON_TAIL, MOVE_THRASH, MOVE_DOUBLE_EDGE},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_CAREFUL_2,
#if GERMAN
                    .nickname = _("Gallopa"),
#else
                    .nickname = _("RAPIDASH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FLAREON,
                    .heldItem = ITEM_SILK_SCARF,
                    .moves = {MOVE_IRON_TAIL, MOVE_FLAIL, MOVE_BITE, MOVE_DOUBLE_EDGE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_IMPISH_2,
#if GERMAN
                    .nickname = _("Flamara"),
#else
                    .nickname = _("FLAREON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDOQUEEN,
                    .heldItem = ITEM_SILK_SCARF,
                    .moves = {MOVE_SUPERPOWER, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK, MOVE_COUNTER},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CAREFUL,
#if GERMAN
                    .nickname = _("Nidoqueen"),
#else
                    .nickname = _("NIDOQUEEN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PERSIAN,
                    .heldItem = ITEM_SILK_SCARF,
                    .moves = {MOVE_RETURN, MOVE_AERIAL_ACE, MOVE_IRON_TAIL, MOVE_DIG},
                    .hpEV = 110,
                    .attackEV = 200,
                    .defenseEV = 0,
                    .speedEV = 200,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Snobilikat"),
#else
                    .nickname = _("PERSIAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Alfons"),
#else
            .name = _("NICOLAS"),
#endif
            .facilityClass = FACILITY_CLASS_BLACK_BELT_FRLG,
            .textColor = 5,
            .speechBefore = {EC_WORD_HERE, EC_WORD_IS, EC_WORD_WHERE, EC_WORD_STOP, EC_WORD_IS, EC_WORD_EXCL},
            .speechWin = {EC_WORD_YOU_RE, EC_WORD_TOO_WEAK, EC_WORD_TO, EC_WORD_EVER, EC_WORD_FAINT, EC_WORD_ME},
            .speechLose = {EC_WORD_WHY, EC_WORD_COULD, EC_WORD_I, EC_WORD_BABE, EC_WORD_DON_T, EC_WORD_FAINT},
            .speechAfter = {EC_WORD_I, EC_WORD_MUST_BE, EC_WORD_MORE, EC_WORD_TRAIN, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_HITMONLEE,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_MEGA_KICK, MOVE_REVERSAL, MOVE_FOCUS_PUNCH, MOVE_BRICK_BREAK},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_IMPISH,
#if GERMAN
                    .nickname = _("Kicklee"),
#else
                    .nickname = _("HITMONLEE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SCYTHER,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_SLASH, MOVE_REVERSAL, MOVE_STEEL_WING, MOVE_AERIAL_ACE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CAREFUL,
#if GERMAN
                    .nickname = _("Sichlor"),
#else
                    .nickname = _("SCYTHER"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAGMAR,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_FIRE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_BRICK_BREAK, MOVE_IRON_TAIL},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_IMPISH_3,
#if GERMAN
                    .nickname = _("Magmar"),
#else
                    .nickname = _("MAGMAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MACHAMP,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_DYNAMIC_PUNCH, MOVE_DIG, MOVE_CROSS_CHOP, MOVE_REVENGE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY,
#if GERMAN
                    .nickname = _("Machomei"),
#else
                    .nickname = _("MACHAMP"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PRIMEAPE,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_THRASH, MOVE_CROSS_CHOP, MOVE_IRON_TAIL, MOVE_AERIAL_ACE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 110,
                    .spAttackEV = 0,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_IMPISH,
#if GERMAN
                    .nickname = _("Rasaff"),
#else
                    .nickname = _("PRIMEAPE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_POLIWRATH,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_BODY_SLAM, MOVE_DIG, MOVE_MEGA_KICK, MOVE_COUNTER},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_JOLLY,
#if GERMAN
                    .nickname = _("Quappo"),
#else
                    .nickname = _("POLIWRATH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
    },
    .checksum = 0x00016f05
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Single_5 = {
    .id = 9,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_HP_UP,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Ludger"),
#else
            .name = _("JOEY"),
#endif
            .facilityClass = FACILITY_CLASS_CAMPER_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_WHO_WAS, EC_WORD_POKEMON, EC_WORD_THOSE, EC_WORD_TERRIBLE, EC_WORD_TOUGH, EC_WORD_EXCL},
            .speechWin = {EC_WORD_BEEN, EC_WORD_WHO_WAS, EC_WORD_POKEMON, EC_WORD_TO, EC_WORD_A_LOT, EC_WORD_QUES},
            .speechLose = {EC_WORD_YOURS, EC_WORD_POKEMON, EC_WORD_THOSE, EC_WORD_A_LOT, EC_WORD_TO, EC_WORD_TOUGH},
            .speechAfter = {EC_WORD_ABSOLUTELY, EC_WORD_WAY, EC_WORD_POKEMON, EC_WORD_MATCH_UP, EC_WORD_IS, EC_WORD_IMPORTANT},
            .mons =
            {
                {
                    .species = SPECIES_MURKROW,
                    .heldItem = ITEM_BLACK_GLASSES,
                    .moves = {MOVE_FAINT_ATTACK, MOVE_AERIAL_ACE, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Kramurx"),
#else
                    .nickname = _("MURKROW"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TAUROS,
                    .heldItem = ITEM_SILK_SCARF,
                    .moves = {MOVE_EARTHQUAKE, MOVE_BODY_SLAM, MOVE_ROCK_TOMB, MOVE_PURSUIT},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS,
#if GERMAN
                    .nickname = _("Tauros"),
#else
                    .nickname = _("TAUROS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SLOWBRO,
                    .heldItem = ITEM_MYSTIC_WATER,
                    .moves = {MOVE_AMNESIA, MOVE_PSYCHIC, MOVE_SURF, MOVE_ICE_BEAM},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Lahmus"),
#else
                    .nickname = _("SLOWBRO"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ARBOK,
                    .heldItem = ITEM_POISON_BARB,
                    .moves = {MOVE_IRON_TAIL, MOVE_SLUDGE_BOMB, MOVE_ROCK_SLIDE, MOVE_TOXIC},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Arbok"),
#else
                    .nickname = _("ARBOK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDOKING,
                    .heldItem = ITEM_SOFT_SAND,
                    .moves = {MOVE_EARTHQUAKE, MOVE_MEGAHORN, MOVE_SLUDGE_BOMB, MOVE_ROCK_SLIDE},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS,
#if GERMAN
                    .nickname = _("Nidoking"),
#else
                    .nickname = _("NIDOKING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RAPIDASH,
                    .heldItem = ITEM_CHARCOAL,
                    .moves = {MOVE_FLAMETHROWER, MOVE_BOUNCE, MOVE_QUICK_ATTACK, MOVE_DOUBLE_KICK},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Gallopa"),
#else
                    .nickname = _("RAPIDASH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00016417
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Single_8 = {
    .id = 10,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_METAL_COAT,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Lilly"),
#else
            .name = _("LILY"),
#endif
            .facilityClass = FACILITY_CLASS_PKMN_BREEDER_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_I, EC_WORD_WANTS, EC_WORD_SOMETHING, EC_WORD_BACK, 0xFFFF, 0xFFFF},
            .speechWin = {EC_WORD_I, EC_WORD_BELIEVE, EC_WORD_ON, EC_WORD_WHO_WAS, EC_WORD_POKEMON, EC_WORD_EXCL},
            .speechLose = {EC_WORD_I, EC_WORD_NEED, EC_WORD_SOMETHING, EC_WORD_BACK, EC_WORD_ELLIPSIS, 0xFFFF},
            .speechAfter = {EC_WORD_WHO_WAS, EC_WORD_POKEMON, EC_WORD_GOT, EC_WORD_ALWAYS, EC_WORD_MY, EC_WORD_TRUST},
            .mons =
            {
                {
                    .species = SPECIES_CLEFAIRY,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_CHARM, MOVE_METRONOME, MOVE_RETURN, MOVE_REST},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Piepi"),
#else
                    .nickname = _("CLEFAIRY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TOGEPI,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_CHARM, MOVE_METRONOME, MOVE_RETURN, MOVE_REST},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Togepi"),
#else
                    .nickname = _("TOGEPI"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MEOWTH,
                    .heldItem = ITEM_SILK_SCARF,
                    .moves = {MOVE_CHARM, MOVE_ASSIST, MOVE_RETURN, MOVE_REST},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Mauzi"),
#else
                    .nickname = _("MEOWTH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_JIGGLYPUFF,
                    .heldItem = ITEM_SILK_SCARF,
                    .moves = {MOVE_CHARM, MOVE_ROLLOUT, MOVE_RETURN, MOVE_REST},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Pummeluff"),
#else
                    .nickname = _("JIGGLYPUFF"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SNORLAX,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_CHARM, MOVE_ROLLOUT, MOVE_RETURN, MOVE_REST},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_2,
#if GERMAN
                    .nickname = _("Relaxo"),
#else
                    .nickname = _("SNORLAX"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SNUBBULL,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_CHARM, MOVE_LICK, MOVE_RETURN, MOVE_REST},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Snubbull"),
#else
                    .nickname = _("SNUBBULL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00016cb7
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Single_2 = {
    .id = 11,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_UP_GRADE,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Bruno"),
#else
            .name = _("BRANDON"),
#endif
            .facilityClass = FACILITY_CLASS_BUG_CATCHER_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_POISON, EC_WORD_IS, EC_WORD_SO, EC_WORD_VERY, EC_WORD_AWFUL, EC_WORD_ISN_T_IT_QUES},
            .speechWin = {EC_WORD_LOOKS, EC_WORD_QUES, EC_WORD_IS, EC_WORD_POISON, EC_WORD_DON_T, EC_WORD_TERRIBLE},
            .speechLose = {EC_WORD_EH_QUES, EC_WORD_OUR, EC_WORD_POISON, EC_WORD_WASN_T, EC_WORD_ALL_RIGHT, EC_WORD_QUES_EXCL},
            .speechAfter = {EC_WORD_POISON, EC_WORD_IS, EC_WORD_A, EC_WORD_TERRIBLE, EC_MOVE(TORMENT), EC_WORD_ISN_T_IT_QUES},
            .mons =
            {
                {
                    .species = SPECIES_BUTTERFREE,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_SILVER_WIND, MOVE_SLEEP_POWDER, MOVE_PSYCHIC, MOVE_SUPERSONIC},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Smettbo"),
#else
                    .nickname = _("BUTTERFREE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_BEEDRILL,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_SLUDGE_BOMB, MOVE_TWINEEDLE, MOVE_DOUBLE_TEAM, MOVE_AERIAL_ACE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Bibor"),
#else
                    .nickname = _("BEEDRILL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PARASECT,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_GIGA_DRAIN, MOVE_LIGHT_SCREEN, MOVE_STUN_SPORE, MOVE_SLASH},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Parasek"),
#else
                    .nickname = _("PARASECT"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_YANMA,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_HYPNOSIS, MOVE_SONIC_BOOM, MOVE_QUICK_ATTACK, MOVE_AERIAL_ACE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Yanma"),
#else
                    .nickname = _("YANMA"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SHUCKLE,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_TOXIC, MOVE_ROCK_TOMB, MOVE_PROTECT, MOVE_REST},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Pottrott"),
#else
                    .nickname = _("SHUCKLE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FORRETRESS,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_TOXIC, MOVE_GIGA_DRAIN, MOVE_PROTECT, MOVE_SANDSTORM},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Forstellka"),
#else
                    .nickname = _("FORRETRESS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00016e1f
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_3 = {
    .id = 12,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_IRON,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Max&klara"),
#else
            .name = _("RIC & RENE"),
#endif
            .facilityClass = FACILITY_CLASS_CRUSH_KIN_FRLG,
            .textColor = 5,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_REALLY, EC_WORD_CUTE, EC_WORD_EXCL, 0xFFFF, 0xFFFF},
            .speechWin = {EC_WORD_I_AM, EC_WORD_TO, EC_WORD_CUTE, EC_WORD_EXCL, 0xFFFF, 0xFFFF},
            .speechLose = {EC_WORD_EH_QUES, EC_WORD_I_AM, EC_WORD_NOT_VERY, EC_WORD_CUTE, EC_WORD_QUES, 0xFFFF},
            .speechAfter = {EC_WORD_I, EC_WORD_GIVE, EC_WORD_MY, EC_WORD_BEST, EC_WORD_EXCL, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_HITMONLEE,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_ROCK_TOMB, MOVE_HI_JUMP_KICK, MOVE_BULK_UP, MOVE_PROTECT},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE,
#if GERMAN
                    .nickname = _("Kicklee"),
#else
                    .nickname = _("HITMONLEE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RHYDON,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_MEGAHORN, MOVE_ROCK_BLAST, MOVE_BRICK_BREAK, MOVE_PROTECT},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE_4,
#if GERMAN
                    .nickname = _("Rizeros"),
#else
                    .nickname = _("RHYDON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GOLEM,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_BRICK_BREAK, MOVE_ROCK_BLAST, MOVE_DIG, MOVE_PROTECT},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_BRAVE,
#if GERMAN
                    .nickname = _("Geowaz"),
#else
                    .nickname = _("GOLEM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAGMAR,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_FIRE_PUNCH, MOVE_BRICK_BREAK, MOVE_CONFUSE_RAY, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_NAUGHTY,
#if GERMAN
                    .nickname = _("Magmar"),
#else
                    .nickname = _("MAGMAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_HERACROSS,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_MEGAHORN, MOVE_BRICK_BREAK, MOVE_ROCK_TOMB, MOVE_PROTECT},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE_4,
#if GERMAN
                    .nickname = _("Skaraborn"),
#else
                    .nickname = _("HERACROSS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_POLIWRATH,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_FOCUS_PUNCH, MOVE_SURF, MOVE_BULK_UP, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_LONELY_2,
#if GERMAN
                    .nickname = _("Quappo"),
#else
                    .nickname = _("POLIWRATH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Max&klara"),
#else
            .name = _("RIC & RENE"),
#endif
            .facilityClass = FACILITY_CLASS_CRUSH_KIN_FRLG,
            .textColor = 5,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_REALLY, EC_WORD_CUTE, EC_WORD_EXCL, 0xFFFF, 0xFFFF},
            .speechWin = {EC_WORD_I_AM, EC_WORD_TO, EC_WORD_CUTE, EC_WORD_EXCL, 0xFFFF, 0xFFFF},
            .speechLose = {EC_WORD_EH_QUES, EC_WORD_I_AM, EC_WORD_NOT_VERY, EC_WORD_CUTE, EC_WORD_QUES, 0xFFFF},
            .speechAfter = {EC_WORD_I, EC_WORD_GIVE, EC_WORD_MY, EC_WORD_BEST, EC_WORD_EXCL, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_MACHAMP,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_CROSS_CHOP, MOVE_SEISMIC_TOSS, MOVE_ROCK_TOMB, MOVE_PROTECT},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_3,
#if GERMAN
                    .nickname = _("Machomei"),
#else
                    .nickname = _("MACHAMP"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PINSIR,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_ROCK_TOMB, MOVE_SEISMIC_TOSS, MOVE_SUBMISSION, MOVE_PROTECT},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Pinsir"),
#else
                    .nickname = _("PINSIR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAROWAK,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_BRICK_BREAK, MOVE_BONEMERANG, MOVE_AERIAL_ACE, MOVE_PROTECT},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_ADAMANT,
#if GERMAN
                    .nickname = _("Knogga"),
#else
                    .nickname = _("MAROWAK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_HITMONCHAN,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_MACH_PUNCH, MOVE_THUNDER_PUNCH, MOVE_DOUBLE_TEAM, MOVE_PROTECT},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT,
#if GERMAN
                    .nickname = _("Nockchan"),
#else
                    .nickname = _("HITMONCHAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ELECTABUZZ,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_THUNDER_PUNCH, MOVE_BRICK_BREAK, MOVE_THUNDER_WAVE, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_NAUGHTY,
#if GERMAN
                    .nickname = _("Elektek"),
#else
                    .nickname = _("ELECTABUZZ"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_POLIWRATH,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_FOCUS_PUNCH, MOVE_SURF, MOVE_BULK_UP, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_LONELY_2,
#if GERMAN
                    .nickname = _("Quappo"),
#else
                    .nickname = _("POLIWRATH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x000166b4
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_1 = {
    .id = 13,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_DRAGON_SCALE,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Lena&petra"),
#else
            .name = _("JEN & KIRA"),
#endif
            .facilityClass = FACILITY_CLASS_TWINS_FRLG,
            .textColor = 5,
            .speechBefore = {EC_WORD_LET_S, EC_WORD_TRIES, EC_WORD_TOUGH, EC_WORD_EXCL, 0xFFFF, 0xFFFF},
            .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCL, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechAfter = {EC_WORD_WE, EC_WORD_MUST_BE, EC_WORD_WORKING, EC_WORD_BETTER, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_JOLTEON,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_QUICK_ATTACK, MOVE_THUNDERBOLT, MOVE_DOUBLE_KICK, MOVE_PIN_MISSILE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_MILD,
#if GERMAN
                    .nickname = _("Blitza"),
#else
                    .nickname = _("JOLTEON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ESPEON,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_QUICK_ATTACK, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_BITE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_MILD,
#if GERMAN
                    .nickname = _("Psiana"),
#else
                    .nickname = _("ESPEON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FLAREON,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_QUICK_ATTACK, MOVE_FLAMETHROWER, MOVE_SHADOW_BALL, MOVE_IRON_TAIL},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_LONELY,
#if GERMAN
                    .nickname = _("Flamara"),
#else
                    .nickname = _("FLAREON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_VAPOREON,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_QUICK_ATTACK, MOVE_WATERFALL, MOVE_ICE_BEAM, MOVE_BITE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MILD,
#if GERMAN
                    .nickname = _("Aquana"),
#else
                    .nickname = _("VAPOREON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_EEVEE,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_QUICK_ATTACK, MOVE_DOUBLE_EDGE, MOVE_BITE, MOVE_IRON_TAIL},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MILD,
#if GERMAN
                    .nickname = _("Evoli"),
#else
                    .nickname = _("EEVEE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_UMBREON,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_QUICK_ATTACK, MOVE_FAINT_ATTACK, MOVE_SHADOW_BALL, MOVE_IRON_TAIL},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MILD,
#if GERMAN
                    .nickname = _("Nachtara"),
#else
                    .nickname = _("UMBREON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Lena&petra"),
#else
            .name = _("JEN & KIRA"),
#endif
            .facilityClass = FACILITY_CLASS_TWINS_FRLG,
            .textColor = 3,
            .speechBefore = {EC_WORD_LET_S, EC_WORD_TRIES, EC_WORD_TOUGH, EC_WORD_EXCL, 0xFFFF, 0xFFFF},
            .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCL, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechAfter = {EC_WORD_WE, EC_WORD_MUST_BE, EC_WORD_WORKING, EC_WORD_BETTER, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_JOLTEON,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HELPING_HAND, MOVE_THUNDERBOLT},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = 10 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Blitza"),
#else
                    .nickname = _("JOLTEON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ESPEON,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_HELPING_HAND, MOVE_PSYCHIC},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = 10 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Psiana"),
#else
                    .nickname = _("ESPEON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FLAREON,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HELPING_HAND, MOVE_FLAMETHROWER},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = 13 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_JOLLY,
#if GERMAN
                    .nickname = _("Flamara"),
#else
                    .nickname = _("FLAREON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_VAPOREON,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HELPING_HAND, MOVE_SURF},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = 35 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID_2,
#if GERMAN
                    .nickname = _("Aquana"),
#else
                    .nickname = _("VAPOREON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_EEVEE,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HELPING_HAND, MOVE_DOUBLE_EDGE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = 35 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID_2,
#if GERMAN
                    .nickname = _("Evoli"),
#else
                    .nickname = _("EEVEE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_UMBREON,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HELPING_HAND, MOVE_FAINT_ATTACK},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = 35 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID_2,
#if GERMAN
                    .nickname = _("Nachtara"),
#else
                    .nickname = _("UMBREON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00017fc2
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_4 = {
    .id = 14,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_MENTAL_HERB,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Hans&anna"),
#else
            .name = _("ISAC & MAG"),
#endif
            .facilityClass = FACILITY_CLASS_COOL_COUPLE_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_WHO_WAS, EC_WORD_POKEMON, EC_WORD_WILL, EC_WORD_DON_T, EC_WORD_SHAKY, EC_WORD_EXCL},
            .speechWin = {EC_WORD_LOOKS, EC_WORD_QUES, EC_WORD_I, EC_WORD_HAVE, EC_WORD_DON_T, EC_WORD_LAY},
            .speechLose = {EC_WORD_EH_QUES, EC_WORD_YOU, EC_WORD_MAKE, EC_WORD_ME, EC_WORD_SHAKY, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_I_AM, EC_WORD_LOVEY_DOVEY, EC_WORD_FOR, EC_WORD_HE, EC_WORD_DON_T, EC_WORD_SHAKY},
            .mons =
            {
                {
                    .species = SPECIES_NIDOKING,
                    .heldItem = ITEM_SOFT_SAND,
                    .moves = {MOVE_EARTHQUAKE, MOVE_MEGAHORN, MOVE_SHADOW_BALL, MOVE_FIRE_BLAST},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT,
#if GERMAN
                    .nickname = _("Nidoking"),
#else
                    .nickname = _("NIDOKING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GLIGAR,
                    .heldItem = ITEM_SOFT_SAND,
                    .moves = {MOVE_EARTHQUAKE, MOVE_QUICK_ATTACK, MOVE_AERIAL_ACE, MOVE_IRON_TAIL},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Skorgla"),
#else
                    .nickname = _("GLIGAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_QUAGSIRE,
                    .heldItem = ITEM_SOFT_SAND,
                    .moves = {MOVE_EARTHQUAKE, MOVE_SLUDGE_BOMB, MOVE_BLIZZARD, MOVE_BRICK_BREAK},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Morlord"),
#else
                    .nickname = _("QUAGSIRE"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_PILOSWINE,
                    .heldItem = ITEM_SOFT_SAND,
                    .moves = {MOVE_EARTHQUAKE, MOVE_BLIZZARD, MOVE_ANCIENT_POWER, MOVE_BODY_SLAM},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Keifel"),
#else
                    .nickname = _("PILOSWINE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GOLEM,
                    .heldItem = ITEM_SOFT_SAND,
                    .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_BLAST, MOVE_BRICK_BREAK, MOVE_EXPLOSION},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Geowaz"),
#else
                    .nickname = _("GOLEM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_STEELIX,
                    .heldItem = ITEM_SOFT_SAND,
                    .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_DRAGON_BREATH, MOVE_DOUBLE_EDGE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Stahlos"),
#else
                    .nickname = _("STEELIX"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Hans&anna"),
#else
            .name = _("ISAC & MAG"),
#endif
            .facilityClass = FACILITY_CLASS_COOL_COUPLE_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_WHO_WAS, EC_WORD_POKEMON, EC_WORD_WILL, EC_WORD_DON_T, EC_WORD_SHAKY, EC_WORD_EXCL},
            .speechWin = {EC_WORD_LOOKS, EC_WORD_QUES, EC_WORD_I, EC_WORD_HAVE, EC_WORD_DON_T, EC_WORD_LAY},
            .speechLose = {EC_WORD_EH_QUES, EC_WORD_YOU, EC_WORD_MAKE, EC_WORD_ME, EC_WORD_SHAKY, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_I_AM, EC_WORD_LOVEY_DOVEY, EC_WORD_FOR, EC_WORD_HE, EC_WORD_DON_T, EC_WORD_SHAKY},
            .mons =
            {
                {
                    .species = SPECIES_SKARMORY,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_SANDSTORM, MOVE_STEEL_WING, MOVE_AIR_CUTTER, MOVE_SPIKES},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HASTY,
#if GERMAN
                    .nickname = _("Panzaeron"),
#else
                    .nickname = _("SKARMORY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MANTINE,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_ICE_BEAM, MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_AERIAL_ACE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_HASTY,
#if GERMAN
                    .nickname = _("Mantax"),
#else
                    .nickname = _("MANTINE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_JUMPLUFF,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_TAIL_WHIP, MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_AERIAL_ACE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HASTY,
#if GERMAN
                    .nickname = _("Papungha"),
#else
                    .nickname = _("JUMPLUFF"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GENGAR,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT, MOVE_PSYCHIC},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HASTY,
#if GERMAN
                    .nickname = _("Gengar"),
#else
                    .nickname = _("GENGAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CROBAT,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_GIGA_DRAIN, MOVE_POISON_FANG, MOVE_FLY, MOVE_STEEL_WING},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HASTY,
#if GERMAN
                    .nickname = _("Iksbat"),
#else
                    .nickname = _("CROBAT"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_XATU,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_PSYCHIC, MOVE_CONFUSE_RAY, MOVE_AERIAL_ACE, MOVE_LIGHT_SCREEN},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HASTY,
#if GERMAN
                    .nickname = _("Xatu"),
#else
                    .nickname = _("XATU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00016bb0
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Knockout_8 = {
    .id = 15,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_KNOCKOUT,
    .prize = TTPRIZE_BRIGHT_POWDER,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Judith"),
#else
            .name = _("CHELSEA"),
#endif
            .facilityClass = FACILITY_CLASS_PKMN_RANGER_F_FRLG,
            .textColor = 7,
            .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_GREEN, EC_WORD_WORLD, EC_WORD_IS, EC_WORD_IMPORTANT, EC_WORD_ISN_T_IT_QUES},
            .speechWin = {EC_WORD_YOU, EC_WORD_GOT, EC_WORD_LOST, EC_WORD_EXCL, 0xFFFF, 0xFFFF},
            .speechLose = {EC_WORD_BE, EC_WORD_NICE, EC_WORD_TO, EC_WORD_THE, EC_WORD_GREEN, EC_WORD_WORLD},
            .speechAfter = {EC_WORD_POISON, EC_WORD_NEVER, EC_WORD_ABSOLUTELY, EC_WORD_GREEN, EC_WORD_WORLD, EC_WORD_EXCL},
            .mons =
            {
                {
                    .species = SPECIES_VILEPLUME,
                    .heldItem = ITEM_PETAYA_BERRY,
                    .moves = {MOVE_INGRAIN, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_STUN_SPORE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_QUIET,
#if GERMAN
                    .nickname = _("Giflor"),
#else
                    .nickname = _("VILEPLUME"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_STARMIE,
                    .heldItem = ITEM_PETAYA_BERRY,
                    .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_WATERFALL, MOVE_RECOVER},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_GENDERLESS_MILD,
#if GERMAN
                    .nickname = _("Starmie"),
#else
                    .nickname = _("STARMIE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_URSARING,
                    .heldItem = ITEM_LIECHI_BERRY,
                    .moves = {MOVE_FAINT_ATTACK, MOVE_BODY_SLAM, MOVE_BRICK_BREAK, MOVE_ROCK_TOMB},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_LONELY,
#if GERMAN
                    .nickname = _("Ursaring"),
#else
                    .nickname = _("URSARING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NOCTOWL,
                    .heldItem = ITEM_LIECHI_BERRY,
                    .moves = {MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_FAINT_ATTACK, MOVE_AERIAL_ACE},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_LONELY,
#if GERMAN
                    .nickname = _("Noctuh"),
#else
                    .nickname = _("NOCTOWL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NINETALES,
                    .heldItem = ITEM_PETAYA_BERRY,
                    .moves = {MOVE_GRUDGE, MOVE_OVERHEAT, MOVE_FAINT_ATTACK, MOVE_WILL_O_WISP},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MILD,
#if GERMAN
                    .nickname = _("Vulnona"),
#else
                    .nickname = _("NINETALES"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_LEDIAN,
                    .heldItem = ITEM_LIECHI_BERRY,
                    .moves = {MOVE_SILVER_WIND, MOVE_SWIFT, MOVE_AERIAL_ACE, MOVE_TOXIC},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_LONELY,
#if GERMAN
                    .nickname = _("Ledian"),
#else
                    .nickname = _("LEDIAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Otmar"),
#else
            .name = _("TRENTON"),
#endif
            .facilityClass = FACILITY_CLASS_PKMN_RANGER_M_FRLG,
            .textColor = 7,
            .speechBefore = {EC_WORD_I_AM, EC_MOVE2(PROTECT), EC_WORD_FOR, EC_WORD_ABSOLUTELY, EC_WORD_GREEN, EC_WORD_WORLD},
            .speechWin = {EC_WORD_TAKE_THAT, EC_WORD_EXCL, EC_WORD_LOST, EC_WORD_IS, EC_WORD_FOR, EC_WORD_BABE},
            .speechLose = {EC_MOVE2(PROTECT), EC_WORD_FOR, EC_WORD_ABSOLUTELY, EC_WORD_GREEN, EC_WORD_WORLD, EC_WORD_EXCL},
            .speechAfter = {EC_MOVE2(PROTECT), EC_WORD_AND, EC_WORD_RESUSCITATE, EC_WORD_ABSOLUTELY, EC_WORD_GREEN, EC_WORD_WORLD},
            .mons =
            {
                {
                    .species = SPECIES_GYARADOS,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_BLIZZARD, MOVE_HYPER_BEAM},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HASTY_3,
#if GERMAN
                    .nickname = _("Garados"),
#else
                    .nickname = _("GYARADOS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_VICTREEBEL,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_REFLECT, MOVE_ATTRACT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_QUIET_3,
#if GERMAN
                    .nickname = _("Sarzenia"),
#else
                    .nickname = _("VICTREEBEL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_DONPHAN,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_IRON_TAIL, MOVE_DOUBLE_EDGE},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_LONELY_2,
#if GERMAN
                    .nickname = _("Donphan"),
#else
                    .nickname = _("DONPHAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FEAROW,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_FAINT_ATTACK, MOVE_DRILL_PECK, MOVE_STEEL_WING, MOVE_DOUBLE_TEAM},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_LONELY_2,
#if GERMAN
                    .nickname = _("Ibitak"),
#else
                    .nickname = _("FEAROW"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ARCANINE,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_EXTREME_SPEED, MOVE_FIRE_BLAST, MOVE_CRUNCH, MOVE_AERIAL_ACE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_NAUGHTY,
#if GERMAN
                    .nickname = _("Arkani"),
#else
                    .nickname = _("ARCANINE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ARIADOS,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_PSYCHIC, MOVE_SLUDGE_BOMB, MOVE_SIGNAL_BEAM, MOVE_TOXIC},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_LONELY_2,
#if GERMAN
                    .nickname = _("Ariados"),
#else
                    .nickname = _("ARIADOS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Pablo"),
#else
            .name = _("ALBERT"),
#endif
            .facilityClass = FACILITY_CLASS_COOLTRAINER_M_FRLG,
            .textColor = 7,
            .speechBefore = {EC_WORD_LET_S, EC_WORD_AN, EC_WORD_EXCITING, EC_WORD_TIME, EC_WORD_HERE, EC_WORD_GOT},
            .speechWin = {EC_WORD_YOU_RE, EC_WORD_TOO_WEAK, EC_WORD_FOR, EC_WORD_EXCITING, EC_WORD_THING, EC_WORD_EXCL},
            .speechLose = {EC_WORD_YOU_RE, EC_WORD_TOUGH, EC_WORD_THAT_WAS, EC_WORD_WILD, EC_WORD_AND, EC_WORD_EXCITING},
            .speechAfter = {EC_WORD_I_AM, EC_WORD_TIRED, EC_WORD_AFTER, EC_WORD_THESE, EC_WORD_EXCITING, EC_WORD_FIGHTING},
            .mons =
            {
                {
                    .species = SPECIES_KINGDRA,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_TWISTER, MOVE_OCTAZOOKA, MOVE_AURORA_BEAM, MOVE_RETURN},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_GENTLE,
#if GERMAN
                    .nickname = _("Seedraking"),
#else
                    .nickname = _("KINGDRA"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GOLEM,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK, MOVE_DOUBLE_EDGE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_BRAVE_4,
#if GERMAN
                    .nickname = _("Geowaz"),
#else
                    .nickname = _("GOLEM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_DRAGONITE,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_THUNDER, MOVE_FIRE_BLAST, MOVE_BLIZZARD, MOVE_DRAGON_CLAW},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_LONELY,
#if GERMAN
                    .nickname = _("Dragoran"),
#else
                    .nickname = _("DRAGONITE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TYRANITAR,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_THUNDER, MOVE_FIRE_BLAST},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_LONELY_2,
#if GERMAN
                    .nickname = _("Despotar"),
#else
                    .nickname = _("TYRANITAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_AMPHAROS,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_REFLECT, MOVE_THUNDER, MOVE_BRICK_BREAK, MOVE_RETURN},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RASH,
#if GERMAN
                    .nickname = _("Ampharos"),
#else
                    .nickname = _("AMPHAROS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_VENUSAUR,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_TOXIC, MOVE_BODY_SLAM},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_QUIET,
#if GERMAN
                    .nickname = _("Bisaflor"),
#else
                    .nickname = _("VENUSAUR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
    },
    .checksum = 0x0001844c
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Knockout_3 = {
    .id = 16,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_KNOCKOUT,
    .prize = TTPRIZE_CALCIUM,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Helga"),
#else
            .name = _("CAMRYN"),
#endif
            .facilityClass = FACILITY_CLASS_PICNICKER_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_LET_S, EC_WORD_FIGHT, EC_WORD_I, EC_WORD_WON_T, EC_WORD_LOSE, EC_WORD_EXCL},
            .speechWin = {EC_WORD_I, EC_WORD_SAID, EC_WORD_LET_ME_WIN, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {EC_WORD_OH_QUES, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_HAVE, EC_WORD_I, EC_WORD_LOST, EC_WORD_QUES},
            .speechAfter = {EC_WORD_YOU_RE, EC_WORD_TOO_STRONG, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_MURKROW,
                    .heldItem = ITEM_BLACK_GLASSES,
                    .moves = {MOVE_AERIAL_ACE, MOVE_SHADOW_BALL, MOVE_FAINT_ATTACK, MOVE_CONFUSE_RAY},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Kramurx"),
#else
                    .nickname = _("MURKROW"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RAPIDASH,
                    .heldItem = ITEM_CHARCOAL,
                    .moves = {MOVE_BOUNCE, MOVE_FLAMETHROWER, MOVE_QUICK_ATTACK, MOVE_DOUBLE_KICK},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Gallopa"),
#else
                    .nickname = _("RAPIDASH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MILTANK,
                    .heldItem = ITEM_SILK_SCARF,
                    .moves = {MOVE_MILK_DRINK, MOVE_BRICK_BREAK, MOVE_BODY_SLAM, MOVE_SHADOW_BALL},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Miltank"),
#else
                    .nickname = _("MILTANK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GOLDUCK,
                    .heldItem = ITEM_MYSTIC_WATER,
                    .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_LIGHT_SCREEN},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Entoron"),
#else
                    .nickname = _("GOLDUCK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SANDSLASH,
                    .heldItem = ITEM_SOFT_SAND,
                    .moves = {MOVE_SANDSTORM, MOVE_AERIAL_ACE, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Sandamer"),
#else
                    .nickname = _("SANDSLASH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDOQUEEN,
                    .heldItem = ITEM_HARD_STONE,
                    .moves = {MOVE_EARTHQUAKE, MOVE_SUPERPOWER, MOVE_SLUDGE_BOMB, MOVE_ROCK_SLIDE},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Nidoqueen"),
#else
                    .nickname = _("NIDOQUEEN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Nadine"),
#else
            .name = _("NATALIA"),
#endif
            .facilityClass = FACILITY_CLASS_AROMA_LADY_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_LIKES, EC_WORD_YOU, EC_WORD_THESE, EC_MOVE(SWEET_SCENT), EC_WORD_QUES, 0xFFFF},
            .speechWin = {EC_WORD_WAS, EC_WORD_THAT, EC_WORD_DON_T, EC_WORD_NICE, EC_WORD_QUES, 0xFFFF},
            .speechLose = {EC_WORD_THAT, EC_WORD_WASN_T, EC_WORD_ALL_RIGHT, EC_WORD_QUES, 0xFFFF, 0xFFFF},
            .speechAfter = {EC_WORD_I, EC_MOVE2(REFRESH), EC_WORD_THING, EC_WORD_WITH, EC_WORD_REFRESHING, EC_MOVE(AROMATHERAPY)},
            .mons =
            {
                {
                    .species = SPECIES_BELLOSSOM,
                    .heldItem = ITEM_PERSIM_BERRY,
                    .moves = {MOVE_SWEET_SCENT, MOVE_ATTRACT, MOVE_PETAL_DANCE, MOVE_FLAIL},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Blubella"),
#else
                    .nickname = _("BELLOSSOM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_VICTREEBEL,
                    .heldItem = ITEM_MIRACLE_SEED,
                    .moves = {MOVE_SWEET_SCENT, MOVE_ATTRACT, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Sarzenia"),
#else
                    .nickname = _("VICTREEBEL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PARASECT,
                    .heldItem = ITEM_MIRACLE_SEED,
                    .moves = {MOVE_SWEET_SCENT, MOVE_ATTRACT, MOVE_GIGA_DRAIN, MOVE_AERIAL_ACE},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Parasek"),
#else
                    .nickname = _("PARASECT"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_VILEPLUME,
                    .heldItem = ITEM_PERSIM_BERRY,
                    .moves = {MOVE_SWEET_SCENT, MOVE_ATTRACT, MOVE_PETAL_DANCE, MOVE_SLUDGE_BOMB},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Giflor"),
#else
                    .nickname = _("VILEPLUME"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_VENUSAUR,
                    .heldItem = ITEM_PERSIM_BERRY,
                    .moves = {MOVE_SWEET_SCENT, MOVE_ATTRACT, MOVE_PETAL_DANCE, MOVE_SLUDGE_BOMB},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Bisaflor"),
#else
                    .nickname = _("VENUSAUR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MEGANIUM,
                    .heldItem = ITEM_MIRACLE_SEED,
                    .moves = {MOVE_SWEET_SCENT, MOVE_ATTRACT, MOVE_GIGA_DRAIN, MOVE_BODY_SLAM},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_2,
#if GERMAN
                    .nickname = _("Meganie"),
#else
                    .nickname = _("MEGANIUM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Karin"),
#else
            .name = _("KATHLEEN"),
#endif
            .facilityClass = FACILITY_CLASS_COOLTRAINER_F_FRLG,
            .textColor = 7,
            .speechBefore = {EC_WORD_TO, EC_WORD_AWFUL, EC_WORD_IS_IT_QUES, EC_WORD_FOR, EC_WORD_BABE, EC_WORD_DONE},
            .speechWin = {EC_WORD_SORRY, EC_WORD_ELLIPSIS, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {EC_WORD_THAT, EC_WORD_IS, EC_WORD_HARD, EC_WORD_TO, EC_WORD_BELIEVE, EC_WORD_ELLIPSIS},
            .speechAfter = {EC_WORD_YOU_VE, EC_WORD_PURE_POWER, EC_WORD_THAT, EC_WORD_IS, EC_WORD_NATURAL, EC_WORD_QUES},
            .mons =
            {
                {
                    .species = SPECIES_MAROWAK,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_BONEMERANG, MOVE_AERIAL_ACE},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Knogga"),
#else
                    .nickname = _("MAROWAK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_LAPRAS,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_PSYCHIC, MOVE_THUNDER},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Lapras"),
#else
                    .nickname = _("LAPRAS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ARCANINE,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_EXTREME_SPEED, MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_AERIAL_ACE},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_SERIOUS_3,
#if GERMAN
                    .nickname = _("Arkani"),
#else
                    .nickname = _("ARCANINE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RAICHU,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_QUICK_ATTACK, MOVE_DOUBLE_TEAM, MOVE_IRON_TAIL},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SERIOUS_4,
#if GERMAN
                    .nickname = _("Raichu"),
#else
                    .nickname = _("RAICHU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TOGETIC,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_ANCIENT_POWER, MOVE_SWEET_KISS, MOVE_PSYCHIC, MOVE_MAGICAL_LEAF},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Togetic"),
#else
                    .nickname = _("TOGETIC"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SNORLAX,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_BODY_SLAM, MOVE_REST, MOVE_SNORE, MOVE_SHADOW_BALL},
                    .hpEV = 84,
                    .attackEV = 84,
                    .defenseEV = 84,
                    .speedEV = 84,
                    .spAttackEV = 84,
                    .spDefenseEV = 84,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_SERIOUS,
#if GERMAN
                    .nickname = _("Relaxo"),
#else
                    .nickname = _("SNORLAX"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
    },
    .checksum = 0x0001738c
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Single_6 = {
    .id = 17,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_CARBOS,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Hugo"),
#else
            .name = _("BRADEN"),
#endif
            .facilityClass = FACILITY_CLASS_SWIMMER_M_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_WITH, EC_WORD_WHO_WAS, EC_WORD_TOUGHNESS, EC_WORD_VERY, EC_WORD_HAPPY},
            .speechWin = {EC_WORD_WROOOAAR_EXCL, EC_WORD_EXCL, EC_WORD_SERIOUS, EC_WORD_I_VE, EC_WORD_WON, EC_WORD_QUES},
            .speechLose = {EC_WORD_YOU_VE, EC_WORD_ME, EC_WORD_OFF, EC_WORD_HAPPY, EC_WORD_SHAKY, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_ALL_RIGHT, EC_WORD_WORK, EC_WORD_EXCL, EC_WORD_YOU, EC_WORD_ARE, EC_WORD_FABULOUS},
            .mons =
            {
                {
                    .species = SPECIES_VAPOREON,
                    .heldItem = ITEM_CHERI_BERRY,
                    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_SHADOW_BALL, MOVE_WISH},
                    .hpEV = 100,
                    .attackEV = 0,
                    .defenseEV = 110,
                    .speedEV = 0,
                    .spAttackEV = 200,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_QUIET,
#if GERMAN
                    .nickname = _("Aquana"),
#else
                    .nickname = _("VAPOREON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SLOWBRO,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_SURF, MOVE_CONFUSION, MOVE_AMNESIA, MOVE_DISABLE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_CALM_3,
#if GERMAN
                    .nickname = _("Lahmus"),
#else
                    .nickname = _("SLOWBRO"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_POLITOED,
                    .heldItem = ITEM_CHESTO_BERRY,
                    .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_HYPNOSIS, MOVE_SWAGGER},
                    .hpEV = 100,
                    .attackEV = 100,
                    .defenseEV = 110,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Quaxo"),
#else
                    .nickname = _("POLITOED"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TENTACRUEL,
                    .heldItem = ITEM_POISON_BARB,
                    .moves = {MOVE_SURF, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_MIRROR_COAT},
                    .hpEV = 100,
                    .attackEV = 0,
                    .defenseEV = 110,
                    .speedEV = 0,
                    .spAttackEV = 200,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Tentoxa"),
#else
                    .nickname = _("TENTACRUEL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RATICATE,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_SUPER_FANG, MOVE_HYPER_FANG, MOVE_THUNDER_WAVE, MOVE_QUICK_ATTACK},
                    .hpEV = 110,
                    .attackEV = 200,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Rattikarl"),
#else
                    .nickname = _("RATICATE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_DUNSPARCE,
                    .heldItem = ITEM_PERSIM_BERRY,
                    .moves = {MOVE_WATER_PULSE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_YAWN},
                    .hpEV = 255,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE_4,
#if GERMAN
                    .nickname = _("Dummisel"),
#else
                    .nickname = _("DUNSPARCE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00016530
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Mixed_1 = {
    .id = 18,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_KINGS_ROCK,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Dagmar"),
#else
            .name = _("ALLYSON"),
#endif
            .facilityClass = FACILITY_CLASS_COOLTRAINER_F_FRLG,
            .textColor = 7,
            .speechBefore = {EC_WORD_TODAY, EC_WORD_WON_T, EC_WORD_I, EC_WORD_LOSE, EC_WORD_EXCL, 0xFFFF},
            .speechWin = {EC_WORD_YES, EC_WORD_EXCL_EXCL, EC_WORD_TODAY, EC_WORD_ADORE, EC_WORD_I, EC_WORD_ME},
            .speechLose = {EC_WORD_I_WAS, EC_WORD_CONFUSED, EC_WORD_OVER, EC_WORD_THING, EC_WORD_I, EC_WORD_MODE},
            .speechAfter = {EC_WORD_YOU_RE, EC_WORD_TODAY, EC_WORD_TOO_STRONG, EC_WORD_IT_S, EC_WORD_ALL, EC_WORD_EXCL},
            .mons =
            {
                {
                    .species = SPECIES_STARMIE,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_THUNDER_WAVE, MOVE_RECOVER},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_GENDERLESS_MODEST,
#if GERMAN
                    .nickname = _("Starmie"),
#else
                    .nickname = _("STARMIE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_BLASTOISE,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_MIRROR_COAT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HARDY_2,
#if GERMAN
                    .nickname = _("Turtok"),
#else
                    .nickname = _("BLASTOISE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_KINGDRA,
                    .heldItem = ITEM_CHESTO_BERRY,
                    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_DRAGON_BREATH, MOVE_REST},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_MODEST_3,
#if GERMAN
                    .nickname = _("Seedraking"),
#else
                    .nickname = _("KINGDRA"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_QUAGSIRE,
                    .heldItem = ITEM_CHESTO_BERRY,
                    .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_REST},
                    .hpEV = 0,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 155,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Morlord"),
#else
                    .nickname = _("QUAGSIRE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_LAPRAS,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_ATTRACT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Lapras"),
#else
                    .nickname = _("LAPRAS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_DRAGONITE,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_LIGHT_SCREEN},
                    .hpEV = 0,
                    .attackEV = 100,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 155,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Dragoran"),
#else
                    .nickname = _("DRAGONITE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00016e32
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Single_1 = {
    .id = 19,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_UP_GRADE,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Anselm"),
#else
            .name = _("ALBERTO"),
#endif
            .facilityClass = FACILITY_CLASS_SAILOR_FRLG,
            .textColor = 5,
            .speechBefore = {EC_WORD_LET_S, EC_WORD_NOW, EC_WORD_WITH, EC_WORD_THAT, EC_WORD_BEGINNING, EC_WORD_EXCL},
            .speechWin = {EC_WORD_YO, EC_WORD_EXCL_EXCL, EC_WORD_YOU, EC_WORD_GIVE, EC_WORD_OUT, EC_WORD_NOW},
            .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_DONE, EC_WORD_ELLIPSIS, EC_WORD_I, EC_WORD_GIVE_UP, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_OK_QUES, EC_WORD_I, EC_WORD_CONCEDE, EC_WORD_ELLIPSIS, EC_WORD_I, EC_WORD_LOST},
            .mons =
            {
                {
                    .species = SPECIES_FERALIGATR,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_DRAGON_CLAW},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HARDY_2,
#if GERMAN
                    .nickname = _("Impergator"),
#else
                    .nickname = _("FERALIGATR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_POLIWRATH,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_MEGA_KICK, MOVE_ROCK_TOMB},
                    .hpEV = 100,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Quappo"),
#else
                    .nickname = _("POLIWRATH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_KANGASKHAN,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_CRUSH_CLAW, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB, MOVE_AERIAL_ACE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 130,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 125,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_ADAMANT,
#if GERMAN
                    .nickname = _("Kangama"),
#else
                    .nickname = _("KANGASKHAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MILTANK,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_ROCK_TOMB, MOVE_MILK_DRINK},
                    .hpEV = 155,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_ADAMANT,
#if GERMAN
                    .nickname = _("Miltank"),
#else
                    .nickname = _("MILTANK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GOLDUCK,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_CROSS_CHOP, MOVE_SURF, MOVE_ICE_BEAM, MOVE_DISABLE},
                    .hpEV = 0,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 210,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Entoron"),
#else
                    .nickname = _("GOLDUCK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GRANBULL,
                    .heldItem = ITEM_LIECHI_BERRY,
                    .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 130,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 125,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE_5,
#if GERMAN
                    .nickname = _("Granbull"),
#else
                    .nickname = _("GRANBULL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00016890
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Mixed_5 = {
    .id = 20,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_METAL_COAT,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Ute&bert"),
#else
            .name = _("KAT & KIPP"),
#endif
            .facilityClass = FACILITY_CLASS_SIS_AND_BRO_FRLG,
            .textColor = 4,
            .speechBefore = {EC_WORD_FUFUFU, EC_WORD_ELLIPSIS, EC_WORD_WE, EC_WORD_LOSE, EC_WORD_NEVER, EC_WORD_EXCL},
            .speechWin = {EC_WORD_FUFUFU, EC_WORD_ELLIPSIS, EC_WORD_WE_RE, EC_WORD_TOO_STRONG, EC_WORD_TO, EC_WORD_LOSE},
            .speechLose = {EC_WORD_WHAT, EC_WORD_EH_QUES, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_JOKING, EC_WORD_QUES},
            .speechAfter = {EC_WORD_WAAAH, EC_WORD_WAAAH, EC_WORD_OH, EC_WORD_BIG, EC_WORD_SISTER, EC_WORD_EXCL},
            .mons =
            {
                {
                    .species = SPECIES_SNEASEL,
                    .heldItem = ITEM_RAWST_BERRY,
                    .moves = {MOVE_DIG, MOVE_TORMENT, MOVE_REFLECT, MOVE_TAUNT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_JOLLY,
#if GERMAN
                    .nickname = _("Sniebel"),
#else
                    .nickname = _("SNEASEL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_OMASTAR,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_DIVE, MOVE_LEER, MOVE_TICKLE, MOVE_SUPERSONIC},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CALM,
#if GERMAN
                    .nickname = _("Amoroso"),
#else
                    .nickname = _("OMASTAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_DEWGONG,
                    .heldItem = ITEM_PERSIM_BERRY,
                    .moves = {MOVE_DIVE, MOVE_ENCORE, MOVE_GROWL, MOVE_SAFEGUARD},
                    .hpEV = 200,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 210,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CALM,
#if GERMAN
                    .nickname = _("Jugong"),
#else
                    .nickname = _("DEWGONG"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_QUAGSIRE,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_DIVE, MOVE_YAWN, MOVE_AMNESIA, MOVE_SAFEGUARD},
                    .hpEV = 200,
                    .attackEV = 0,
                    .defenseEV = 110,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CALM_3,
#if GERMAN
                    .nickname = _("Morlord"),
#else
                    .nickname = _("QUAGSIRE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CORSOLA,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_DIG, MOVE_MIRROR_COAT, MOVE_RECOVER, MOVE_CONFUSE_RAY},
                    .hpEV = 155,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CAREFUL,
#if GERMAN
                    .nickname = _("Corasonn"),
#else
                    .nickname = _("CORSOLA"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SANDSLASH,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_DIG, MOVE_COUNTER, MOVE_DEFENSE_CURL, MOVE_SAND_ATTACK},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CAREFUL_2,
#if GERMAN
                    .nickname = _("Sandamer"),
#else
                    .nickname = _("SANDSLASH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Ute&bert"),
#else
            .name = _("KAT & KIPP"),
#endif
            .facilityClass = FACILITY_CLASS_SIS_AND_BRO_FRLG,
            .textColor = 4,
            .speechBefore = {EC_WORD_FUFUFU, EC_WORD_ELLIPSIS, EC_WORD_WE, EC_WORD_LOSE, EC_WORD_NEVER, EC_WORD_EXCL},
            .speechWin = {EC_WORD_FUFUFU, EC_WORD_ELLIPSIS, EC_WORD_WE_RE, EC_WORD_TOO_STRONG, EC_WORD_TO, EC_WORD_LOSE},
            .speechLose = {EC_WORD_WHAT, EC_WORD_EH_QUES, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_JOKING, EC_WORD_QUES},
            .speechAfter = {EC_WORD_WAAAH, EC_WORD_WAAAH, EC_WORD_OH, EC_WORD_BIG, EC_WORD_SISTER, EC_WORD_EXCL},
            .mons =
            {
                {
                    .species = SPECIES_FURRET,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_DIG, MOVE_AMNESIA, MOVE_DEFENSE_CURL, MOVE_FOLLOW_ME},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Wiesenior"),
#else
                    .nickname = _("FURRET"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_AZUMARILL,
                    .heldItem = ITEM_WHITE_HERB,
                    .moves = {MOVE_DIVE, MOVE_LIGHT_SCREEN, MOVE_TAIL_WHIP, MOVE_DEFENSE_CURL},
                    .hpEV = 155,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CALM,
#if GERMAN
                    .nickname = _("Azumarill"),
#else
                    .nickname = _("AZUMARILL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_KINGLER,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_DIVE, MOVE_HARDEN, MOVE_LEER, MOVE_AMNESIA},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_CALM_3,
#if GERMAN
                    .nickname = _("Kingler"),
#else
                    .nickname = _("KINGLER"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CLOYSTER,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_DIVE, MOVE_WITHDRAW, MOVE_PROTECT, MOVE_SUPERSONIC},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CALM,
#if GERMAN
                    .nickname = _("Austos"),
#else
                    .nickname = _("CLOYSTER"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_QUAGSIRE,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_DIG, MOVE_YAWN, MOVE_AMNESIA, MOVE_SAFEGUARD},
                    .hpEV = 200,
                    .attackEV = 0,
                    .defenseEV = 110,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CAREFUL_2,
#if GERMAN
                    .nickname = _("Morlord"),
#else
                    .nickname = _("QUAGSIRE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_KABUTOPS,
                    .heldItem = ITEM_PECHA_BERRY,
                    .moves = {MOVE_DIG, MOVE_SAND_ATTACK, MOVE_ENDURE, MOVE_CONFUSE_RAY},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_CAREFUL,
#if GERMAN
                    .nickname = _("Kabutops"),
#else
                    .nickname = _("KABUTOPS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00015d7c
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_8 = {
    .id = 21,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_MENTAL_HERB,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Bernd&emma"),
#else
            .name = _("GEB&MEGAN"),
#endif
            .facilityClass = FACILITY_CLASS_COOL_COUPLE_FRLG,
            .textColor = 7,
            .speechBefore = {EC_WORD_YOU_RE, EC_WORD_OUR, EC_WORD_FOE, EC_WORD_QUES, EC_WORD_GIGGLE, EC_WORD_ELLIPSIS},
            .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_SORRY, EC_WORD_EXCL},
            .speechLose = {EC_WORD_MY, EC_WORD_WORD, EC_WORD_IS, EC_WORD_SIMPLE, EC_WORD_UNBELIEVABLE, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_WE, EC_WORD_MUST_BE, EC_WORD_MORE, EC_WORD_TRAIN, EC_WORD_EXCL, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_POLITOED,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_SURF, MOVE_HYPNOSIS, MOVE_PERISH_SONG, MOVE_SWAGGER},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_MODEST_3,
#if GERMAN
                    .nickname = _("Quaxo"),
#else
                    .nickname = _("POLITOED"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GYARADOS,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_HYPER_BEAM, MOVE_DRAGON_DANCE, MOVE_THUNDER_WAVE, MOVE_THUNDERBOLT},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Garados"),
#else
                    .nickname = _("GYARADOS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_LAPRAS,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Lapras"),
#else
                    .nickname = _("LAPRAS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDOQUEEN,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_SUPERPOWER, MOVE_ROCK_SLIDE},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Nidoqueen"),
#else
                    .nickname = _("NIDOQUEEN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_JYNX,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_WATER_PULSE, MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_PSYCHIC},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Rossana"),
#else
                    .nickname = _("JYNX"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GIRAFARIG,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_LIGHT_SCREEN, MOVE_CRUNCH, MOVE_PSYCHIC, MOVE_REFLECT},
                    .hpEV = 210,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_MODEST_3,
#if GERMAN
                    .nickname = _("Girafarig"),
#else
                    .nickname = _("GIRAFARIG"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Bernd&emma"),
#else
            .name = _("GEB&MEGAN"),
#endif
            .facilityClass = FACILITY_CLASS_COOL_COUPLE_FRLG,
            .textColor = 7,
            .speechBefore = {EC_WORD_YOU_RE, EC_WORD_OUR, EC_WORD_FOE, EC_WORD_QUES, EC_WORD_GIGGLE, EC_WORD_ELLIPSIS},
            .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_SORRY, EC_WORD_EXCL},
            .speechLose = {EC_WORD_MY, EC_WORD_WORD, EC_WORD_IS, EC_WORD_SIMPLE, EC_WORD_UNBELIEVABLE, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_WE, EC_WORD_MUST_BE, EC_WORD_MORE, EC_WORD_TRAIN, EC_WORD_EXCL, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_MAROWAK,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_CAREFUL_2,
#if GERMAN
                    .nickname = _("Knogga"),
#else
                    .nickname = _("MAROWAK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_URSARING,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Ursaring"),
#else
                    .nickname = _("URSARING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SLOWKING,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_SHADOW_BALL},
                    .hpEV = 0,
                    .attackEV = 110,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 200,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_QUIET,
#if GERMAN
                    .nickname = _("Laschoking"),
#else
                    .nickname = _("SLOWKING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ALAKAZAM,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_PSYCHIC, MOVE_PROTECT, MOVE_LIGHT_SCREEN, MOVE_REFLECT},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_MODEST_2,
#if GERMAN
                    .nickname = _("Simsala"),
#else
                    .nickname = _("ALAKAZAM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDOKING,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_SURF, MOVE_MEGAHORN, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HARDY,
#if GERMAN
                    .nickname = _("Nidoking"),
#else
                    .nickname = _("NIDOKING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RHYDON,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_EARTHQUAKE, MOVE_PROTECT, MOVE_MEGAHORN, MOVE_ROCK_SLIDE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SASSY,
#if GERMAN
                    .nickname = _("Rizeros"),
#else
                    .nickname = _("RHYDON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x000160f4
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_Unused1 = {
    .id = 22,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_ZINC,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Bea&tina"),
#else
            .name = _("LISA&LEAH"),
#endif
            .facilityClass = FACILITY_CLASS_TWINS_FRLG,
            .textColor = 1,
            .speechBefore = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechWin = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechAfter = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_POLIWAG,
                    .heldItem = ITEM_CHERI_BERRY,
                    .moves = {MOVE_SURF, MOVE_PROTECT, MOVE_TOXIC, MOVE_DOUBLE_TEAM},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID_3,
#if GERMAN
                    .nickname = _("Quapsel"),
#else
                    .nickname = _("POLIWAG"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SQUIRTLE,
                    .heldItem = ITEM_MYSTIC_WATER,
                    .moves = {MOVE_WATER_PULSE, MOVE_PROTECT, MOVE_TOXIC, MOVE_MIRROR_COAT},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CALM,
#if GERMAN
                    .nickname = _("Schiggy"),
#else
                    .nickname = _("SQUIRTLE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CHINCHOU,
                    .heldItem = ITEM_MAGNET,
                    .moves = {MOVE_SURF, MOVE_THUNDER_WAVE, MOVE_CONFUSE_RAY, MOVE_THUNDERBOLT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Lampi"),
#else
                    .nickname = _("CHINCHOU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDORAN_F,
                    .heldItem = ITEM_POISON_BARB,
                    .moves = {MOVE_WATER_PULSE, MOVE_SLUDGE_BOMB, MOVE_CRUNCH, MOVE_DIG},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Nidoran♀"),
#else
                    .nickname = _("NIDORAN♀"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CLEFAIRY,
                    .heldItem = ITEM_WHITE_HERB,
                    .moves = {MOVE_WATER_PULSE, MOVE_DOUBLE_TEAM, MOVE_SING, MOVE_MINIMIZE},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Piepi"),
#else
                    .nickname = _("CLEFAIRY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_HORSEA,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_SURF, MOVE_SMOKESCREEN, MOVE_ATTRACT, MOVE_DRAGON_RAGE},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CALM,
#if GERMAN
                    .nickname = _("Seeper"),
#else
                    .nickname = _("HORSEA"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Bea&tina"),
#else
            .name = _("LISA&LEAH"),
#endif
            .facilityClass = FACILITY_CLASS_TWINS_FRLG,
            .textColor = 1,
            .speechBefore = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechWin = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechAfter = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_WOOPER,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_YAWN, MOVE_FLASH},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SASSY,
#if GERMAN
                    .nickname = _("Felino"),
#else
                    .nickname = _("WOOPER"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PSYDUCK,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_SURF, MOVE_CROSS_CHOP, MOVE_HYPNOSIS, MOVE_DISABLE},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Enton"),
#else
                    .nickname = _("PSYDUCK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SNUBBULL,
                    .heldItem = ITEM_PECHA_BERRY,
                    .moves = {MOVE_WATER_PULSE, MOVE_THUNDER_WAVE, MOVE_CRUNCH, MOVE_SHADOW_BALL},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Snubbull"),
#else
                    .nickname = _("SNUBBULL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_JIGGLYPUFF,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_WATER_PULSE, MOVE_THUNDER_WAVE, MOVE_SING, MOVE_DISABLE},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Pummeluff"),
#else
                    .nickname = _("JIGGLYPUFF"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDORAN_M,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_WATER_PULSE, MOVE_SLUDGE_BOMB, MOVE_HORN_DRILL, MOVE_DIG},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HARDY,
#if GERMAN
                    .nickname = _("Nidoran♂"),
#else
                    .nickname = _("NIDORAN♂"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TOTODILE,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_SURF, MOVE_PROTECT, MOVE_TOXIC, MOVE_DOUBLE_TEAM},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CALM,
#if GERMAN
                    .nickname = _("Karnimani"),
#else
                    .nickname = _("TOTODILE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(15),
    },
    .checksum = 0x000197d4
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Knockout_7 = {
    .id = 23,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_KNOCKOUT,
    .prize = TTPRIZE_PROTEIN,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Martina"),
#else
            .name = _("PRISCILLA"),
#endif
            .facilityClass = FACILITY_CLASS_TUBER_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_SMALL, EC_WORD_POKEMON, EC_WORD_GIRL, EC_WORD_EXCL},
            .speechWin = {EC_WORD_WAAAH, EC_WORD_EXCL, EC_WORD_HAVE, EC_WORD_I, EC_WORD_WON, EC_WORD_QUES},
            .speechLose = {EC_WORD_OH_DEAR, EC_WORD_ELLIPSIS, EC_WORD_I_VE, EC_WORD_DON_T, EC_WORD_WON, EC_WORD_ELLIPSIS},
            .speechAfter = {EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_NICE, EC_WORD_TRAINER, EC_WORD_THANK_YOU, EC_WORD_EXCL},
            .mons =
            {
                {
                    .species = SPECIES_GOLDEEN,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_WATER_PULSE, MOVE_MEGAHORN, MOVE_SUPERSONIC, MOVE_ICE_BEAM},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Goldini"),
#else
                    .nickname = _("GOLDEEN"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_SEAKING,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_SURF, MOVE_MEGAHORN, MOVE_HORN_DRILL, MOVE_PROTECT},
                    .hpEV = 100,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Golking"),
#else
                    .nickname = _("SEAKING"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_LANTURN,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_ICE_BEAM},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 210,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_MODEST_3,
#if GERMAN
                    .nickname = _("Lanturn"),
#else
                    .nickname = _("LANTURN"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_LANTURN,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_HYDRO_PUMP, MOVE_THUNDER, MOVE_ICE_BEAM, MOVE_RAIN_DANCE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 210,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Lanturn"),
#else
                    .nickname = _("LANTURN"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_GOLDEEN,
                    .heldItem = ITEM_APICOT_BERRY,
                    .moves = {MOVE_WATER_PULSE, MOVE_DOUBLE_EDGE, MOVE_TOXIC, MOVE_PSYBEAM},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Goldini"),
#else
                    .nickname = _("GOLDEEN"),
#endif
                    .friendship = 0
                },
                {
                    .species = SPECIES_SEAKING,
                    .heldItem = ITEM_PETAYA_BERRY,
                    .moves = {MOVE_SURF, MOVE_HYPER_BEAM, MOVE_ICE_BEAM, MOVE_PSYBEAM},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Golking"),
#else
                    .nickname = _("SEAKING"),
#endif
                    .friendship = 0
                },
            }
        },
        {
#if GERMAN
            .name = _("Tanja"),
#else
            .name = _("CHARLOTTE"),
#endif
            .facilityClass = FACILITY_CLASS_LADY_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_HELLO, EC_WORD_I_AM, EC_WORD_AN, EC_WORD_POKEMON, EC_WORD_LADY, EC_WORD_EXCL},
            .speechWin = {EC_WORD_OH, EC_WORD_MY, EC_WORD_MY, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_SORRY},
            .speechLose = {EC_WORD_YOU_RE, EC_WORD_BETTER, EC_WORD_THAN, EC_WORD_AN, EC_WORD_POKEMON, EC_WORD_LADY},
            .speechAfter = {EC_WORD_HOHOHO, EC_WORD_THANK_YOU, EC_WORD_FOR, EC_WORD_OF, EC_WORD_AMUSING, EC_WORD_FIGHTING},
            .mons =
            {
                {
                    .species = SPECIES_OCTILLERY,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_OCTAZOOKA, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_FLAMETHROWER},
                    .hpEV = 55,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Octillery"),
#else
                    .nickname = _("OCTILLERY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_QWILFISH,
                    .heldItem = ITEM_PERSIM_BERRY,
                    .moves = {MOVE_SURF, MOVE_TOXIC, MOVE_REVENGE, MOVE_DOUBLE_TEAM},
                    .hpEV = 200,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 210,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CALM,
#if GERMAN
                    .nickname = _("Baldorfish"),
#else
                    .nickname = _("QWILFISH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_REMORAID,
                    .heldItem = ITEM_PECHA_BERRY,
                    .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_THUNDER_WAVE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Remoraid"),
#else
                    .nickname = _("REMORAID"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_REMORAID,
                    .heldItem = ITEM_WHITE_HERB,
                    .moves = {MOVE_WATER_PULSE, MOVE_BLIZZARD, MOVE_FIRE_BLAST, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Remoraid"),
#else
                    .nickname = _("REMORAID"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_OCTILLERY,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_OCTAZOOKA, MOVE_SLUDGE_BOMB, MOVE_THUNDER_WAVE, MOVE_HYPER_BEAM},
                    .hpEV = 155,
                    .attackEV = 100,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_SASSY,
#if GERMAN
                    .nickname = _("Octillery"),
#else
                    .nickname = _("OCTILLERY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_QWILFISH,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_DESTINY_BOND},
                    .hpEV = 100,
                    .attackEV = 100,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 210,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Baldorfish"),
#else
                    .nickname = _("QWILFISH"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Daniela"),
#else
            .name = _("SHANIA"),
#endif
            .facilityClass = FACILITY_CLASS_SWIMMER_F_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_POKEMON, EC_WORD_HEROINE, EC_WORD_EXCL, 0xFFFF},
            .speechWin = {EC_WORD_AHAHA, EC_WORD_NONE, EC_WORD_CHOICE, EC_WORD_YOU_RE, EC_WORD_SIMPLE, EC_WORD_TOO_WEAK},
            .speechLose = {EC_WORD_WHY, EC_WORD_QUES_EXCL, EC_WORD_YOU, EC_WORD_DON_T, EC_WORD_LIE, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_NICE, EC_WORD_FIGHTING, EC_WORD_THANK_YOU, EC_WORD_EXCL, EC_WORD_VERY, EC_WORD_ENTERTAINING},
            .mons =
            {
                {
                    .species = SPECIES_MANTINE,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Mantax"),
#else
                    .nickname = _("MANTINE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAGIKARP,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_SPLASH, MOVE_TACKLE, MOVE_NONE, MOVE_NONE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_JOLLY,
#if GERMAN
                    .nickname = _("Karpador"),
#else
                    .nickname = _("MAGIKARP"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MANTINE,
                    .heldItem = ITEM_MENTAL_HERB,
                    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_CONFUSE_RAY, MOVE_ATTRACT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Mantax"),
#else
                    .nickname = _("MANTINE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GYARADOS,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_HYPER_BEAM, MOVE_THUNDER_WAVE, MOVE_EARTHQUAKE, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_ADAMANT,
#if GERMAN
                    .nickname = _("Garados"),
#else
                    .nickname = _("GYARADOS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAGIKARP,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_FLAIL, MOVE_TACKLE, MOVE_NONE, MOVE_NONE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CAREFUL_2,
#if GERMAN
                    .nickname = _("Karpador"),
#else
                    .nickname = _("MAGIKARP"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GYARADOS,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_DOUBLE_EDGE, MOVE_THUNDER_WAVE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Garados"),
#else
                    .nickname = _("GYARADOS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
    },
    .checksum = 0x0001521d
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Knockout_4 = {
    .id = 24,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_KNOCKOUT,
    .prize = TTPRIZE_DRAGON_SCALE,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Steffen"),
#else
            .name = _("BRENNAN"),
#endif
            .facilityClass = FACILITY_CLASS_SAILOR_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_TAKE_THAT, EC_WORD_EASY, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_IMPORTANT, EC_WORD_EXCL},
            .speechWin = {EC_WORD_YOU, EC_WORD_LOSE, EC_WORD_AT, EC_WORD_GIVE_UP, EC_WORD_EXCL, 0xFFFF},
            .speechLose = {EC_WORD_HOPELESS, EC_WORD_YOU_VE, EC_WORD_SIMPLE, EC_WORD_WON, EC_WORD_EXCL, 0xFFFF},
            .speechAfter = {EC_WORD_I, EC_WORD_WANTS, EC_WORD_NONE, EC_MOVE(GRUDGE), EC_WORD_BUT, EC_WORD_ELLIPSIS},
            .mons =
            {
                {
                    .species = SPECIES_LAPRAS,
                    .heldItem = ITEM_CHESTO_BERRY,
                    .moves = {MOVE_HYDRO_PUMP, MOVE_PSYCHIC, MOVE_ATTRACT, MOVE_REST},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 255,
                    .otId = 15 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Lapras"),
#else
                    .nickname = _("LAPRAS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_KINGDRA,
                    .heldItem = ITEM_CHESTO_BERRY,
                    .moves = {MOVE_HYDRO_PUMP, MOVE_BLIZZARD, MOVE_DRAGON_BREATH, MOVE_REST},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_MODEST_3,
#if GERMAN
                    .nickname = _("Seedraking"),
#else
                    .nickname = _("KINGDRA"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MACHAMP,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_HYPER_BEAM},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 130,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 125,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_3,
#if GERMAN
                    .nickname = _("Machomei"),
#else
                    .nickname = _("MACHAMP"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CHANSEY,
                    .heldItem = ITEM_ORAN_BERRY,
                    .moves = {MOVE_WATER_PULSE, MOVE_SOFT_BOILED, MOVE_MINIMIZE, MOVE_THUNDER_WAVE},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_BOLD,
#if GERMAN
                    .nickname = _("Chaneira"),
#else
                    .nickname = _("CHANSEY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TAUROS,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB, MOVE_SWAGGER},
                    .hpEV = 110,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT,
#if GERMAN
                    .nickname = _("Tauros"),
#else
                    .nickname = _("TAUROS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SNORLAX,
                    .heldItem = ITEM_ORAN_BERRY,
                    .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_DOUBLE_TEAM, MOVE_REST},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_IMPISH_2,
#if GERMAN
                    .nickname = _("Relaxo"),
#else
                    .nickname = _("SNORLAX"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Umberto"),
#else
            .name = _("KADEN"),
#endif
            .facilityClass = FACILITY_CLASS_FISHERMAN_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_MY, EC_WORD_FISHING, EC_WORD_FASHION, EC_WORD_IS, EC_WORD_FANTASTIC, EC_WORD_EXCL},
            .speechWin = {EC_WORD_MY, EC_WORD_FISHING, EC_WORD_FASHION, EC_WORD_WINS, EC_WORD_SIMPLE, EC_WORD_EXCL},
            .speechLose = {EC_WORD_UH_OH, EC_WORD_ELLIPSIS, EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_EXCL, 0xFFFF},
            .speechAfter = {EC_WORD_FASHION, EC_WORD_CUTENESS, EC_WORD_BECOMES, EC_WORD_DON_T, EC_WORD_WINS, EC_WORD_EXCL},
            .mons =
            {
                {
                    .species = SPECIES_CHINCHOU,
                    .heldItem = ITEM_MAGNET,
                    .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_CONFUSE_RAY, MOVE_PROTECT},
                    .hpEV = 100,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Lampi"),
#else
                    .nickname = _("CHINCHOU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_DRATINI,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_WATER_PULSE, MOVE_THUNDER_WAVE, MOVE_DRAGON_BREATH, MOVE_PROTECT},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = 0 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Dratini"),
#else
                    .nickname = _("DRATINI"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SLOWPOKE,
                    .heldItem = ITEM_PECHA_BERRY,
                    .moves = {MOVE_WATER_PULSE, MOVE_YAWN, MOVE_DISABLE, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Flegmon"),
#else
                    .nickname = _("SLOWPOKE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAGIKARP,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_SPLASH, MOVE_FLAIL, MOVE_TACKLE, MOVE_NONE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = 23 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CAREFUL,
#if GERMAN
                    .nickname = _("Karpador"),
#else
                    .nickname = _("MAGIKARP"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_SEAKING,
                    .heldItem = ITEM_CHERI_BERRY,
                    .moves = {MOVE_HORN_DRILL, MOVE_MEGAHORN, MOVE_SUPERSONIC, MOVE_AGILITY},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = 23 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_CAREFUL,
#if GERMAN
                    .nickname = _("Golking"),
#else
                    .nickname = _("SEAKING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TENTACRUEL,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_MIRROR_COAT, MOVE_SUPERSONIC, MOVE_PROTECT, MOVE_TOXIC},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_HARDY_3,
#if GERMAN
                    .nickname = _("Tentoxa"),
#else
                    .nickname = _("TENTACRUEL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Walter"),
#else
            .name = _("EMANUEL"),
#endif
            .facilityClass = FACILITY_CLASS_GENTLEMAN_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_HMM, EC_WORD_QUES, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_TALENT, EC_WORD_QUES},
            .speechWin = {EC_WORD_I, EC_WORD_UNDERSTAND, EC_WORD_I, EC_WORD_HAVE, EC_WORD_DON_T, EC_WORD_AGREE},
            .speechLose = {EC_WORD_YOU, EC_WORD_ARE, EC_WORD_SIMPLE, EC_WORD_A, EC_WORD_MASTER, EC_WORD_TRAINER},
            .speechAfter = {EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_I_WAS, EC_WORD_SON, EC_WORD_FOE, EC_WORD_ELLIPSIS},
            .mons =
            {
                {
                    .species = SPECIES_VAPOREON,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_ATTRACT, MOVE_BITE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CALM,
#if GERMAN
                    .nickname = _("Aquana"),
#else
                    .nickname = _("VAPOREON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ESPEON,
                    .heldItem = ITEM_CHESTO_BERRY,
                    .moves = {MOVE_PSYCHIC, MOVE_BITE, MOVE_REFLECT, MOVE_REST},
                    .hpEV = 110,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Psiana"),
#else
                    .nickname = _("ESPEON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_BLISSEY,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_WATER_PULSE, MOVE_MINIMIZE, MOVE_THUNDER_WAVE, MOVE_PROTECT},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_BOLD,
#if GERMAN
                    .nickname = _("Heiteira"),
#else
                    .nickname = _("BLISSEY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_STARMIE,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_PSYCHIC},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 155,
                    .otId = 20 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_GENDERLESS_CALM,
#if GERMAN
                    .nickname = _("Starmie"),
#else
                    .nickname = _("STARMIE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PERSIAN,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_SLASH, MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_FAKE_OUT},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 130,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 125,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_JOLLY,
#if GERMAN
                    .nickname = _("Snobilikat"),
#else
                    .nickname = _("PERSIAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_AZUMARILL,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_SURF, MOVE_ENCORE, MOVE_ATTRACT, MOVE_DIG},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HARDY,
#if GERMAN
                    .nickname = _("Azumarill"),
#else
                    .nickname = _("AZUMARILL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
    },
    .checksum = 0x0001554b
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Single_3 = {
    .id = 25,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_METAL_COAT,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Yannick"),
#else
            .name = _("JARRETT"),
#endif
            .facilityClass = FACILITY_CLASS_JUGGLER_FRLG,
            .textColor = 2,
            .speechBefore = {EC_WORD_LET_S, EC_WORD_AN, EC_MOVE2(EXPLOSION), EC_WORD_PARTY, EC_WORD_GOT, EC_WORD_EXCL},
            .speechWin = {EC_WORD_CONGRATS, EC_WORD_FOR, EC_WORD_YOURS, EC_WORD_LOSS, EC_WORD_PARTY, EC_WORD_EXCL},
            .speechLose = {EC_WORD_NICE, EC_MOVE(SELF_DESTRUCT), EC_WORD_EXCL, EC_WORD_YOU_RE, EC_WORD_PERFECT, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_TOTALLY, EC_WORD_MORE, EC_WORD_PARTY, EC_WORD_QUES, EC_WORD_YAHOO, EC_WORD_YAHOO},
            .mons =
            {
                {
                    .species = SPECIES_ELECTRODE,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_EXPLOSION, MOVE_LIGHT_SCREEN, MOVE_SCREECH, MOVE_THUNDERBOLT},
                    .hpEV = 10,
                    .attackEV = 150,
                    .defenseEV = 100,
                    .speedEV = 150,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_GENDERLESS_JOLLY,
#if GERMAN
                    .nickname = _("Lektrobal"),
#else
                    .nickname = _("ELECTRODE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_VOLTORB,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_EXPLOSION, MOVE_FLASH, MOVE_DOUBLE_TEAM, MOVE_THUNDER},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_GENDERLESS_JOLLY,
#if GERMAN
                    .nickname = _("Voltobal"),
#else
                    .nickname = _("VOLTORB"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_WEEZING,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_EXPLOSION, MOVE_SLUDGE_BOMB, MOVE_DESTINY_BOND, MOVE_THUNDERBOLT},
                    .hpEV = 0,
                    .attackEV = 200,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Smogmog"),
#else
                    .nickname = _("WEEZING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GOLEM,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_EXPLOSION, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 150,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE_4,
#if GERMAN
                    .nickname = _("Geowaz"),
#else
                    .nickname = _("GOLEM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_EXEGGCUTE,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_EXPLOSION, MOVE_STUN_SPORE, MOVE_HYPNOSIS, MOVE_GIGA_DRAIN},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Owei"),
#else
                    .nickname = _("EXEGGCUTE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FORRETRESS,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_EXPLOSION, MOVE_GIGA_DRAIN, MOVE_DIG, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 100,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_RELAXED_3,
#if GERMAN
                    .nickname = _("Forstellka"),
#else
                    .nickname = _("FORRETRESS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00015b6a
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Mixed_3 = {
    .id = 26,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_DRAGON_SCALE,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Raimund"),
#else
            .name = _("OWEN"),
#endif
            .facilityClass = FACILITY_CLASS_SUPER_NERD_FRLG,
            .textColor = 2,
            .speechBefore = {EC_WORD_HERE_GOES, EC_MOVE2(THUNDER_WAVE), EC_MOVE2(WRAP), EC_WORD_ME, EC_WORD_DON_T, EC_WORD_EXCL},
            .speechWin = {EC_WORD_ACCEPT, EC_WORD_MY, EC_MOVE2(PRESENT), EC_WORD_THE, EC_MOVE2(THUNDER_WAVE), EC_WORD_EXCL},
            .speechLose = {EC_MOVE2(WRAP), EC_MOVE(BIND), EC_WORD_ELECTRIC, EC_MOVE2(WHIRLWIND), EC_WORD_SPIRALING, EC_WORD_ABOUT},
            .speechAfter = {EC_MOVE2(WHIRLWIND), EC_WORD_SPIRALING, 0xFFFF, 0xFFFF, EC_WORD_SPIRALING, EC_MOVE2(WHIRLWIND)},
            .mons =
            {
                {
                    .species = SPECIES_MAGNETON,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_PROTECT, MOVE_ZAP_CANNON, MOVE_TOXIC, MOVE_SUPERSONIC},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 125,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 130,
                    .otId = 10 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_GENDERLESS_TIMID,
#if GERMAN
                    .nickname = _("Magneton"),
#else
                    .nickname = _("MAGNETON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PIKACHU,
                    .heldItem = ITEM_LIGHT_BALL,
                    .moves = {MOVE_THUNDER_WAVE, MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_DOUBLE_TEAM},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 150,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 105,
                    .otId = 15 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Pikachu"),
#else
                    .nickname = _("PIKACHU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_JOLTEON,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_THUNDER_WAVE, MOVE_THUNDERBOLT, MOVE_DOUBLE_TEAM, MOVE_TOXIC},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BOLD,
#if GERMAN
                    .nickname = _("Blitza"),
#else
                    .nickname = _("JOLTEON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_BLISSEY,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_THUNDER_WAVE, MOVE_BLIZZARD, MOVE_WATER_PULSE, MOVE_REST},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_BOLD,
#if GERMAN
                    .nickname = _("Heiteira"),
#else
                    .nickname = _("BLISSEY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PORYGON2,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_THUNDER_WAVE, MOVE_ZAP_CANNON, MOVE_PSYCHIC, MOVE_RECOVER},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 125,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 130,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_GENDERLESS_BOLD,
#if GERMAN
                    .nickname = _("Porygon2"),
#else
                    .nickname = _("PORYGON2"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PORYGON,
                    .heldItem = ITEM_LAX_INCENSE,
                    .moves = {MOVE_THUNDER_WAVE, MOVE_ZAP_CANNON, MOVE_DOUBLE_TEAM, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = 5 | (0 << 16),
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_GENDERLESS_BOLD,
#if GERMAN
                    .nickname = _("Porygon"),
#else
                    .nickname = _("PORYGON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x000160ec
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Mixed_2 = {
    .id = 27,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_SINGLE,
    .prize = TTPRIZE_PROTEIN,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Lothar"),
#else
            .name = _("LORENZO"),
#endif
            .facilityClass = FACILITY_CLASS_PSYCHIC_M_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_THESE, EC_WORD_POWER, EC_WORD_IS, EC_WORD_NOW, EC_WORD_DONE, EC_WORD_EXCL},
            .speechWin = {EC_WORD_NONE, EC_WORD_KEEN_EYE, EC_WORD_STOP, EC_WORD_WHO_WAS, EC_WORD_POWER, EC_WORD_EXCL},
            .speechLose = {EC_WORD_HERE_IT_IS, EC_WORD_EXCL, EC_MOVE(KINESIS), EC_WORD_EXCL, EC_WORD_ELLIPSIS, 0xFFFF},
            .speechAfter = {EC_WORD_I, EC_WORD_DO, EC_WORD_IT, EC_WORD_IN, EC_MOVE(KINESIS), EC_WORD_HALL_OF_FAME},
            .mons =
            {
                {
                    .species = SPECIES_MR_MIME,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_LIGHT_SCREEN, MOVE_REFLECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Pantimos"),
#else
                    .nickname = _("MR. MIME"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_HYPNO,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_PSYCHIC},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 200,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_MODEST_3,
#if GERMAN
                    .nickname = _("Hypno"),
#else
                    .nickname = _("HYPNO"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ALAKAZAM,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_PSYCHIC},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 150,
                    .spAttackEV = 155,
                    .spDefenseEV = 50,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Simsala"),
#else
                    .nickname = _("ALAKAZAM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GENGAR,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, MOVE_HYPNOSIS, MOVE_TOXIC},
                    .hpEV = 0,
                    .attackEV = 200,
                    .defenseEV = 0,
                    .speedEV = 100,
                    .spAttackEV = 55,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_HASTY_3,
#if GERMAN
                    .nickname = _("Gengar"),
#else
                    .nickname = _("GENGAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GIRAFARIG,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_CRUNCH, MOVE_BODY_SLAM, MOVE_REST},
                    .hpEV = 0,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 155,
                    .spAttackEV = 0,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_ADAMANT,
#if GERMAN
                    .nickname = _("Girafarig"),
#else
                    .nickname = _("GIRAFARIG"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_STARMIE,
                    .heldItem = ITEM_APICOT_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_SURF, MOVE_RECOVER, MOVE_ICE_BEAM},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 55,
                    .speedEV = 250,
                    .spAttackEV = 150,
                    .spDefenseEV = 55,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_GENDERLESS_TIMID,
#if GERMAN
                    .nickname = _("Starmie"),
#else
                    .nickname = _("STARMIE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x0001624b
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_Unused2 = {
    .id = 28,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_SCOPE_LENS,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Mia&fabian"),
#else
            .name = _("NIA & CARL"),
#endif
            .facilityClass = FACILITY_CLASS_COOL_COUPLE_FRLG,
            .textColor = 4,
            .speechBefore = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechWin = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechAfter = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_MUK,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_THUNDERBOLT, MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_BODY_SLAM},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Sleimok"),
#else
                    .nickname = _("MUK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GENGAR,
                    .heldItem = ITEM_PETAYA_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_CONFUSE_RAY, MOVE_PSYCHIC, MOVE_EXPLOSION},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 155,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_GENTLE,
#if GERMAN
                    .nickname = _("Gengar"),
#else
                    .nickname = _("GENGAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ALAKAZAM,
                    .heldItem = ITEM_GANLON_BERRY,
                    .moves = {MOVE_THUNDER_PUNCH, MOVE_PSYCHIC, MOVE_RECOVER, MOVE_REFLECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Simsala"),
#else
                    .nickname = _("ALAKAZAM"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_JOLTEON,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_THUNDERBOLT, MOVE_FLAIL, MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM},
                    .hpEV = 0,
                    .attackEV = 50,
                    .defenseEV = 100,
                    .speedEV = 160,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BOLD,
#if GERMAN
                    .nickname = _("Blitza"),
#else
                    .nickname = _("JOLTEON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ELECTRODE,
                    .heldItem = ITEM_LIECHI_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_EXPLOSION, MOVE_MIRROR_COAT, MOVE_LIGHT_SCREEN},
                    .hpEV = 0,
                    .attackEV = 55,
                    .defenseEV = 0,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_GENDERLESS_CALM,
#if GERMAN
                    .nickname = _("Lektrobal"),
#else
                    .nickname = _("ELECTRODE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RAICHU,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_COUNTER, MOVE_REVERSAL, MOVE_LIGHT_SCREEN},
                    .hpEV = 0,
                    .attackEV = 55,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BRAVE,
#if GERMAN
                    .nickname = _("Raichu"),
#else
                    .nickname = _("RAICHU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Mia&fabian"),
#else
            .name = _("NIA & CARL"),
#endif
            .facilityClass = FACILITY_CLASS_COOL_COUPLE_FRLG,
            .textColor = 4,
            .speechBefore = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechWin = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechAfter = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_KANGASKHAN,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_SHADOW_BALL, MOVE_REVERSAL, MOVE_ENDURE, MOVE_FAKE_OUT},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 105,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 150,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_ADAMANT,
#if GERMAN
                    .nickname = _("Kangama"),
#else
                    .nickname = _("KANGASKHAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TAUROS,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_DOUBLE_EDGE, MOVE_ROCK_TOMB, MOVE_SURF, MOVE_REST},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT,
#if GERMAN
                    .nickname = _("Tauros"),
#else
                    .nickname = _("TAUROS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MILTANK,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_BODY_SLAM, MOVE_SHADOW_BALL, MOVE_MILK_DRINK, MOVE_ROCK_TOMB},
                    .hpEV = 0,
                    .attackEV = 155,
                    .defenseEV = 50,
                    .speedEV = 250,
                    .spAttackEV = 0,
                    .spDefenseEV = 55,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_ADAMANT,
#if GERMAN
                    .nickname = _("Miltank"),
#else
                    .nickname = _("MILTANK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RHYDON,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_THUNDERBOLT, MOVE_MEGAHORN, MOVE_HORN_DRILL, MOVE_ROCK_TOMB},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Rizeros"),
#else
                    .nickname = _("RHYDON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_DRAGONITE,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_BLIZZARD, MOVE_SURF, MOVE_OUTRAGE, MOVE_FLAMETHROWER},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CALM_3,
#if GERMAN
                    .nickname = _("Dragoran"),
#else
                    .nickname = _("DRAGONITE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_LAPRAS,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_THUNDERBOLT, MOVE_BLIZZARD, MOVE_SURF, MOVE_HORN_DRILL},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 31,
                    .attackIV = 31,
                    .defenseIV = 31,
                    .speedIV = 31,
                    .spAttackIV = 31,
                    .spDefenseIV = 31,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_CALM_3,
#if GERMAN
                    .nickname = _("Lapras"),
#else
                    .nickname = _("LAPRAS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00016360
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_7 = {
    .id = 29,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_CARBOS,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Axel&bea"),
#else
            .name = _("AXE & REN"),
#endif
            .facilityClass = FACILITY_CLASS_SIS_AND_BRO_FRLG,
            .textColor = 2,
            .speechBefore = {EC_WORD_OUR, EC_WORD_SWIFT_SWIM, EC_WORD_DOESN_T, EC_WORD_ME, EC_WORD_COLD, EC_WORD_EXCL},
            .speechWin = {EC_WORD_I, EC_WORD_WIN, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_DON_T, EC_WORD_HOT},
            .speechLose = {EC_WORD_I_VE, EC_WORD_HUNGRY, EC_WORD_OUT, EC_WORD_SOMETHING, EC_WORD_HOT, 0xFFFF},
            .speechAfter = {EC_WORD_SISTER, EC_WORD_I, EC_WORD_NEED, EC_WORD_SOMETHING, EC_WORD_HOT, EC_WORD_PLEASE},
            .mons =
            {
                {
                    .species = SPECIES_LANTURN,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_RAIN_DANCE, MOVE_SURF, MOVE_THUNDER, MOVE_ICE_BEAM},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Lanturn"),
#else
                    .nickname = _("LANTURN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MANTINE,
                    .heldItem = ITEM_PETAYA_BERRY,
                    .moves = {MOVE_RAIN_DANCE, MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_ICE_BEAM},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 155,
                    .spAttackEV = 100,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_CALM,
#if GERMAN
                    .nickname = _("Mantax"),
#else
                    .nickname = _("MANTINE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_DEWGONG,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_RAIN_DANCE, MOVE_SURF, MOVE_SHEER_COLD, MOVE_BLIZZARD},
                    .hpEV = 0,
                    .attackEV = 100,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 55,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_QUIET,
#if GERMAN
                    .nickname = _("Jugong"),
#else
                    .nickname = _("DEWGONG"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CLOYSTER,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_RAIN_DANCE, MOVE_SURF, MOVE_ICE_BEAM, MOVE_HYPER_BEAM},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_QUIET,
#if GERMAN
                    .nickname = _("Austos"),
#else
                    .nickname = _("CLOYSTER"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TENTACRUEL,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_RAIN_DANCE, MOVE_SURF, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 100,
                    .speedEV = 100,
                    .spAttackEV = 255,
                    .spDefenseEV = 55,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Tentoxa"),
#else
                    .nickname = _("TENTACRUEL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GYARADOS,
                    .heldItem = ITEM_LIECHI_BERRY,
                    .moves = {MOVE_RAIN_DANCE, MOVE_SURF, MOVE_DRAGON_DANCE, MOVE_RETURN},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_ADAMANT,
#if GERMAN
                    .nickname = _("Garados"),
#else
                    .nickname = _("GYARADOS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Axel&bea"),
#else
            .name = _("AXE & REN"),
#endif
            .facilityClass = FACILITY_CLASS_SIS_AND_BRO_FRLG,
            .textColor = 2,
            .speechBefore = {EC_WORD_OUR, EC_WORD_SWIFT_SWIM, EC_WORD_DOESN_T, EC_WORD_ME, EC_WORD_COLD, EC_WORD_EXCL},
            .speechWin = {EC_WORD_I, EC_WORD_WIN, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_DON_T, EC_WORD_HOT},
            .speechLose = {EC_WORD_I_VE, EC_WORD_HUNGRY, EC_WORD_OUT, EC_WORD_SOMETHING, EC_WORD_HOT, 0xFFFF},
            .speechAfter = {EC_WORD_SISTER, EC_WORD_I, EC_WORD_NEED, EC_WORD_SOMETHING, EC_WORD_HOT, EC_WORD_PLEASE},
            .mons =
            {
                {
                    .species = SPECIES_ELECTABUZZ,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_THUNDER, MOVE_PSYCHIC, MOVE_CROSS_CHOP, MOVE_LIGHT_SCREEN},
                    .hpEV = 0,
                    .attackEV = 155,
                    .defenseEV = 155,
                    .speedEV = 100,
                    .spAttackEV = 100,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_NAIVE,
#if GERMAN
                    .nickname = _("Elektek"),
#else
                    .nickname = _("ELECTABUZZ"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAGNETON,
                    .heldItem = ITEM_PETAYA_BERRY,
                    .moves = {MOVE_THUNDER, MOVE_SONIC_BOOM, MOVE_METAL_SOUND, MOVE_REFLECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_GENDERLESS_TIMID,
#if GERMAN
                    .nickname = _("Magneton"),
#else
                    .nickname = _("MAGNETON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PORYGON,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_THUNDER, MOVE_PSYCHIC, MOVE_BLIZZARD, MOVE_PROTECT},
                    .hpEV = 255,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_GENDERLESS_QUIET,
#if GERMAN
                    .nickname = _("Porygon"),
#else
                    .nickname = _("PORYGON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_DRAGONAIR,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_THUNDER, MOVE_SURF, MOVE_BLIZZARD, MOVE_OUTRAGE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 50,
                    .speedEV = 155,
                    .spAttackEV = 255,
                    .spDefenseEV = 50,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Dragonir"),
#else
                    .nickname = _("DRAGONAIR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PERSIAN,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_THUNDER, MOVE_FAKE_OUT, MOVE_WATER_PULSE, MOVE_RETURN},
                    .hpEV = 0,
                    .attackEV = 155,
                    .defenseEV = 0,
                    .speedEV = 200,
                    .spAttackEV = 155,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_HASTY,
#if GERMAN
                    .nickname = _("Snobilikat"),
#else
                    .nickname = _("PERSIAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_STARMIE,
                    .heldItem = ITEM_GANLON_BERRY,
                    .moves = {MOVE_THUNDER, MOVE_SURF, MOVE_RECOVER, MOVE_REFLECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 95,
                    .speedEV = 255,
                    .spAttackEV = 100,
                    .spDefenseEV = 60,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_GENDERLESS_BOLD,
#if GERMAN
                    .nickname = _("Starmie"),
#else
                    .nickname = _("STARMIE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00015272
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Double_Unused3 = {
    .id = 30,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_DOUBLE,
    .prize = TTPRIZE_ZINC,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Resi&ede"),
#else
            .name = _("KATI & GEB"),
#endif
            .facilityClass = FACILITY_CLASS_YOUNG_COUPLE_FRLG,
            .textColor = 2,
            .speechBefore = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechWin = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechAfter = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_FLAAFFY,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_ATTRACT, MOVE_PROTECT, MOVE_THUNDERBOLT, MOVE_REFLECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_RELAXED_3,
#if GERMAN
                    .nickname = _("Waaty"),
#else
                    .nickname = _("FLAAFFY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_QUAGSIRE,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_ATTRACT, MOVE_SURF, MOVE_AMNESIA, MOVE_BLIZZARD},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_SASSY,
#if GERMAN
                    .nickname = _("Morlord"),
#else
                    .nickname = _("QUAGSIRE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PIKACHU,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_ATTRACT, MOVE_REVERSAL, MOVE_THUNDERBOLT, MOVE_IRON_TAIL},
                    .hpEV = 0,
                    .attackEV = 155,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Pikachu"),
#else
                    .nickname = _("PIKACHU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ELECTABUZZ,
                    .heldItem = ITEM_LIECHI_BERRY,
                    .moves = {MOVE_ATTRACT, MOVE_COUNTER, MOVE_ICE_PUNCH, MOVE_BODY_SLAM},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 150,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 105,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CALM_2,
#if GERMAN
                    .nickname = _("Elektek"),
#else
                    .nickname = _("ELECTABUZZ"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TOGETIC,
                    .heldItem = ITEM_KINGS_ROCK,
                    .moves = {MOVE_ATTRACT, MOVE_BLIZZARD, MOVE_ANCIENT_POWER, MOVE_WATER_PULSE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_CALM,
#if GERMAN
                    .nickname = _("Togetic"),
#else
                    .nickname = _("TOGETIC"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GOLDUCK,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_ATTRACT, MOVE_SURF, MOVE_DIG, MOVE_CROSS_CHOP},
                    .hpEV = 0,
                    .attackEV = 155,
                    .defenseEV = 50,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 50,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Entoron"),
#else
                    .nickname = _("GOLDUCK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Resi&ede"),
#else
            .name = _("KATI & GEB"),
#endif
            .facilityClass = FACILITY_CLASS_YOUNG_COUPLE_FRLG,
            .textColor = 2,
            .speechBefore = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechWin = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechLose = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .speechAfter = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
            .mons =
            {
                {
                    .species = SPECIES_PICHU,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_ATTRACT, MOVE_PROTECT, MOVE_SWEET_KISS, MOVE_REVERSAL},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_ADAMANT,
#if GERMAN
                    .nickname = _("Pichu"),
#else
                    .nickname = _("PICHU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ELEKID,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_ATTRACT, MOVE_PROTECT, MOVE_DOUBLE_TEAM, MOVE_FOCUS_PUNCH},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 130,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 125,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BRAVE,
#if GERMAN
                    .nickname = _("Elekid"),
#else
                    .nickname = _("ELEKID"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_TOGEPI,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_ATTRACT, MOVE_PROTECT, MOVE_YAWN, MOVE_WATER_PULSE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Togepi"),
#else
                    .nickname = _("TOGEPI"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PSYDUCK,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_ATTRACT, MOVE_PROTECT, MOVE_DIG, MOVE_DIVE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Enton"),
#else
                    .nickname = _("PSYDUCK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAREEP,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_ATTRACT, MOVE_PROTECT, MOVE_LIGHT_SCREEN, MOVE_THUNDERBOLT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Voltilamm"),
#else
                    .nickname = _("MAREEP"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_WOOPER,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_ATTRACT, MOVE_PROTECT, MOVE_SURF, MOVE_YAWN},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 10,
                    .attackIV = 10,
                    .defenseIV = 10,
                    .speedIV = 10,
                    .spAttackIV = 10,
                    .spDefenseIV = 10,
                    .abilityNum = 1,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Felino"),
#else
                    .nickname = _("WOOPER"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        DUMMY_TOWER_TEAM(0),
    },
    .checksum = 0x00015966
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Knockout_6 = {
    .id = 31,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_KNOCKOUT,
    .prize = TTPRIZE_WHITE_HERB,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Anatol"),
#else
            .name = _("BEN"),
#endif
            .facilityClass = FACILITY_CLASS_ROCKER_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_LALALA, EC_WORD_LET_S, EC_WORD_OVER, EC_WORD_ELECTRIC, EC_WORD_POWER, EC_MOVE(SING)},
            .speechWin = {EC_WORD_STATIC, EC_WORD_IS, EC_WORD_ELECTRIC, EC_WORD_YES, EC_WORD_IT, EC_WORD_IS},
            .speechLose = {EC_WORD_ELECTRIC, EC_WORD_OVER, EC_WORD_MY, EC_WORD_DIGITAL, EC_WORD_TELEVISION, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_ELECTRIC, EC_WORD_EXCL, EC_WORD_IT_S, EC_WORD_AN, EC_MOVE(NATURE_POWER), EC_WORD_EXCL},
            .mons =
            {
                {
                    .species = SPECIES_ELECTRODE,
                    .heldItem = ITEM_LIECHI_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_MIRROR_COAT, MOVE_EXPLOSION, MOVE_THUNDER_WAVE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 55,
                    .speedEV = 255,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_GENDERLESS_CALM,
#if GERMAN
                    .nickname = _("Lektrobal"),
#else
                    .nickname = _("ELECTRODE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_ELECTABUZZ,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH, MOVE_PSYCHIC, MOVE_ICE_PUNCH},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 155,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_MODEST,
#if GERMAN
                    .nickname = _("Elektek"),
#else
                    .nickname = _("ELECTABUZZ"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_LANTURN,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_THUNDERBOLT, MOVE_DOUBLE_EDGE, MOVE_ICE_BEAM, MOVE_HYDRO_PUMP},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 125,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 130,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_QUIET_3,
#if GERMAN
                    .nickname = _("Lanturn"),
#else
                    .nickname = _("LANTURN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAGNETON,
                    .heldItem = ITEM_LIECHI_BERRY,
                    .moves = {MOVE_ZAP_CANNON, MOVE_HYPER_BEAM, MOVE_LOCK_ON, MOVE_SUPERSONIC},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 55,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_GENDERLESS_CALM,
#if GERMAN
                    .nickname = _("Magneton"),
#else
                    .nickname = _("MAGNETON"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RAICHU,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_DOUBLE_EDGE, MOVE_MEGA_KICK, MOVE_REVERSAL, MOVE_BODY_SLAM},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 80,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 75,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_JOLLY_2,
#if GERMAN
                    .nickname = _("Raichu"),
#else
                    .nickname = _("RAICHU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_AMPHAROS,
                    .heldItem = ITEM_SHELL_BELL,
                    .moves = {MOVE_THUNDERBOLT, MOVE_MEGA_KICK, MOVE_COUNTER, MOVE_BODY_SLAM},
                    .hpEV = 0,
                    .attackEV = 200,
                    .defenseEV = 150,
                    .speedEV = 0,
                    .spAttackEV = 10,
                    .spDefenseEV = 150,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Ampharos"),
#else
                    .nickname = _("AMPHAROS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Martin"),
#else
            .name = _("CAMDEN"),
#endif
            .facilityClass = FACILITY_CLASS_ENGINEER_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_LALALA, EC_WORD_LET_S, EC_WORD_OVER, EC_WORD_ELECTRIC, EC_WORD_POWER, EC_MOVE(SING)},
            .speechWin = {EC_WORD_A, EC_MOVE(THUNDERBOLT), EC_WORD_IS, EC_WORD_TOO, EC_WORD_ELECTRIC, EC_WORD_EXCL},
            .speechLose = {EC_WORD_ELECTRIC, EC_WORD_EXCL, EC_WORD_IS, EC_WORD_OVER, EC_WORD_WIRELESS, EC_WORD_LINK},
            .speechAfter = {EC_WORD_ELECTRIC, EC_WORD_EXCL, EC_WORD_IT_S, EC_WORD_AN, EC_WORD_TREASURE, EC_WORD_EXCL},
            .mons =
            {
                {
                    .species = SPECIES_GRANBULL,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_THUNDERBOLT, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 55,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BRAVE,
#if GERMAN
                    .nickname = _("Granbull"),
#else
                    .nickname = _("GRANBULL"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PERSIAN,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_THUNDERBOLT, MOVE_WATER_PULSE, MOVE_HYPNOSIS, MOVE_SLASH},
                    .hpEV = 0,
                    .attackEV = 100,
                    .defenseEV = 55,
                    .speedEV = 255,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Snobilikat"),
#else
                    .nickname = _("PERSIAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_LICKITUNG,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_PROTECT, MOVE_SURF, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL},
                    .hpEV = 200,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 55,
                    .spDefenseEV = 0,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BRAVE,
#if GERMAN
                    .nickname = _("Schlurp"),
#else
                    .nickname = _("LICKITUNG"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RATICATE,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_HYPER_FANG, MOVE_SUPER_FANG, MOVE_REVERSAL},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 100,
                    .speedEV = 50,
                    .spAttackEV = 0,
                    .spDefenseEV = 105,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_CAREFUL_2,
#if GERMAN
                    .nickname = _("Rattikarl"),
#else
                    .nickname = _("RATICATE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PRIMEAPE,
                    .heldItem = ITEM_SCOPE_LENS,
                    .moves = {MOVE_THUNDERBOLT, MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 130,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 125,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BRAVE,
#if GERMAN
                    .nickname = _("Rasaff"),
#else
                    .nickname = _("PRIMEAPE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_KANGASKHAN,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_SURF, MOVE_CRUSH_CLAW, MOVE_REST},
                    .hpEV = 0,
                    .attackEV = 100,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_QUIET,
#if GERMAN
                    .nickname = _("Kangama"),
#else
                    .nickname = _("KANGASKHAN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Wilhelm"),
#else
            .name = _("ZACKERY"),
#endif
            .facilityClass = FACILITY_CLASS_SCIENTIST_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_LALALA, EC_WORD_LET_S, EC_WORD_OVER, EC_WORD_ELECTRIC, EC_WORD_POWER, EC_MOVE(SING)},
            .speechWin = {EC_WORD_A, EC_MOVE2(THUNDER_SHOCK), EC_WORD_IS, EC_WORD_TOO, EC_WORD_ELECTRIC, EC_WORD_EXCL},
            .speechLose = {EC_WORD_ELECTRIC, EC_WORD_EXCL, EC_MOVE2(FLASH), EC_MOVE2(FLASH), EC_MOVE2(FLASH), EC_WORD_EXCL_EXCL},
            .speechAfter = {EC_WORD_ALL, EC_WORD_TOGETHER, EC_WORD_NOW, EC_WORD_EXCL_EXCL, EC_MOVE(SPARK), EC_MOVE(SPARK)},
            .mons =
            {
                {
                    .species = SPECIES_WEEZING,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_THUNDERBOLT, MOVE_SLUDGE_BOMB, MOVE_FLAMETHROWER, MOVE_SHADOW_BALL},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 0,
                    .speedEV = 0,
                    .spAttackEV = 155,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BRAVE,
#if GERMAN
                    .nickname = _("Smogmog"),
#else
                    .nickname = _("WEEZING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MUK,
                    .heldItem = ITEM_LEFTOVERS,
                    .moves = {MOVE_THUNDERBOLT, MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_CURSE},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 150,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 105,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 1,
                    .personality = PERSONALITY_MALE_RELAXED_3,
#if GERMAN
                    .nickname = _("Sleimok"),
#else
                    .nickname = _("MUK"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_GENGAR,
                    .heldItem = ITEM_PETAYA_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_WILL_O_WISP},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 250,
                    .spAttackEV = 155,
                    .spDefenseEV = 105,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Gengar"),
#else
                    .nickname = _("GENGAR"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MISDREAVUS,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_PSYCHIC, MOVE_GRUDGE, MOVE_CONFUSE_RAY, MOVE_DESTINY_BOND},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 0,
                    .speedEV = 150,
                    .spAttackEV = 105,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_TIMID,
#if GERMAN
                    .nickname = _("Traunfugil"),
#else
                    .nickname = _("MISDREAVUS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CROBAT,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_SLUDGE_BOMB, MOVE_CONFUSE_RAY, MOVE_GIGA_DRAIN, MOVE_TOXIC},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 110,
                    .spAttackEV = 0,
                    .spDefenseEV = 200,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_TIMID_3,
#if GERMAN
                    .nickname = _("Iksbat"),
#else
                    .nickname = _("CROBAT"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_HAUNTER,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_DESTINY_BOND, MOVE_HYPNOSIS, MOVE_CONFUSE_RAY, MOVE_TOXIC},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 20,
                    .attackIV = 20,
                    .defenseIV = 20,
                    .speedIV = 20,
                    .spAttackIV = 20,
                    .spDefenseIV = 20,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_CALM_3,
#if GERMAN
                    .nickname = _("Alpollo"),
#else
                    .nickname = _("HAUNTER"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
    },
    .checksum = 0x00014f49
};

static const struct TrainerTowerFloor sTrainerTowerFloor_Knockout_5 = {
    .id = 32,
    .floorIdx = MAX_TRAINER_TOWER_FLOORS,
    .challengeType = CHALLENGE_TYPE_KNOCKOUT,
    .prize = TTPRIZE_UP_GRADE,
    .trainers =
    {
        {
#if GERMAN
            .name = _("Dolores"),
#else
            .name = _("MAURA"),
#endif
            .facilityClass = FACILITY_CLASS_BEAUTY_FRLG,
            .textColor = 2,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_GROUP, EC_WORD_LEADER, EC_WORD_EXCL, 0xFFFF},
            .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_LEADER, EC_WORD_FROM, EC_WORD_QUES, 0xFFFF},
            .speechLose = {EC_WORD_I_AM, EC_WORD_NONE, EC_WORD_LEADER, EC_WORD_IT_S, EC_WORD_A_LITTLE, EC_WORD_LAY},
            .speechAfter = {EC_WORD_HEH, EC_WORD_THE, EC_WORD_GROUND, EC_WORD_IS, EC_WORD_FULL, EC_WORD_SLIMY},
            .mons =
            {
                {
                    .species = SPECIES_PICHU,
                    .heldItem = ITEM_FOCUS_BAND,
                    .moves = {MOVE_THUNDER_SHOCK, MOVE_THUNDER_WAVE, MOVE_SWEET_KISS, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_BOLD,
#if GERMAN
                    .nickname = _("Pichu"),
#else
                    .nickname = _("PICHU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_MAREEP,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_THUNDER_SHOCK, MOVE_CHARGE, MOVE_PROTECT, MOVE_RETURN},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Voltilamm"),
#else
                    .nickname = _("MAREEP"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_IGGLYBUFF,
                    .heldItem = ITEM_QUICK_CLAW,
                    .moves = {MOVE_SING, MOVE_SWEET_KISS, MOVE_PRESENT, MOVE_PROTECT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Fluffeluff"),
#else
                    .nickname = _("IGGLYBUFF"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CLEFFA,
                    .heldItem = ITEM_LAX_INCENSE,
                    .moves = {MOVE_SING, MOVE_SWEET_KISS, MOVE_ENCORE, MOVE_METRONOME},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Pii"),
#else
                    .nickname = _("CLEFFA"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDORAN_F,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_CRUNCH, MOVE_DIG, MOVE_FLATTER, MOVE_ATTRACT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Nidoran♀"),
#else
                    .nickname = _("NIDORAN♀"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDORAN_M,
                    .heldItem = ITEM_SITRUS_BERRY,
                    .moves = {MOVE_HORN_DRILL, MOVE_SLUDGE_BOMB, MOVE_FLATTER, MOVE_ATTRACT},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 255,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 255,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_RELAXED,
#if GERMAN
                    .nickname = _("Nidoran♂"),
#else
                    .nickname = _("NIDORAN♂"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Michaela"),
#else
            .name = _("MIKAELA"),
#endif
            .facilityClass = FACILITY_CLASS_LASS_FRLG,
            .textColor = 1,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_TRAINER, EC_WORD_NO_1, EC_WORD_HERE, EC_WORD_EXCL},
            .speechWin = {EC_WORD_NEVER, EC_WORD_SAID, EC_WORD_WHERE, EC_WORD_I_AM, EC_WORD_NO_1, EC_WORD_EXCL},
            .speechLose = {EC_WORD_ELSE, EC_WORD_TIME, EC_WORD_I_AM, EC_WORD_EXCESS, EC_WORD_ALL_RIGHT, EC_WORD_EXCL},
            .speechAfter = {EC_WORD_THE, EC_MOVE2(SPIT_UP), EC_WORD_DOESN_T, EC_WORD_ME, EC_WORD_FULL, EC_WORD_DONE},
            .mons =
            {
                {
                    .species = SPECIES_NIDORINO,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_SHOCK_WAVE, MOVE_HORN_DRILL, MOVE_ICE_BEAM, MOVE_IRON_TAIL},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_RELAXED,
#if GERMAN
                    .nickname = _("Nidorino"),
#else
                    .nickname = _("NIDORINO"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDORINA,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_SHOCK_WAVE, MOVE_CRUNCH, MOVE_BODY_SLAM, MOVE_COUNTER},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Nidorina"),
#else
                    .nickname = _("NIDORINA"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_PIKACHU,
                    .heldItem = ITEM_LIGHT_BALL,
                    .moves = {MOVE_SHOCK_WAVE, MOVE_THUNDER_WAVE, MOVE_COUNTER, MOVE_BODY_SLAM},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 200,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 55,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_QUIET,
#if GERMAN
                    .nickname = _("Pikachu"),
#else
                    .nickname = _("PIKACHU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_FLAAFFY,
                    .heldItem = ITEM_BRIGHT_POWDER,
                    .moves = {MOVE_SHOCK_WAVE, MOVE_DOUBLE_TEAM, MOVE_SEISMIC_TOSS, MOVE_BODY_SLAM},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 150,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Waaty"),
#else
                    .nickname = _("FLAAFFY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_JIGGLYPUFF,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_SHOCK_WAVE, MOVE_SHADOW_BALL, MOVE_FOCUS_PUNCH, MOVE_BODY_SLAM},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 150,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 105,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_SASSY,
#if GERMAN
                    .nickname = _("Pummeluff"),
#else
                    .nickname = _("JIGGLYPUFF"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CLEFAIRY,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_SHOCK_WAVE, MOVE_METEOR_MASH, MOVE_MOONLIGHT, MOVE_BODY_SLAM},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 155,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Piepi"),
#else
                    .nickname = _("CLEFAIRY"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
        {
#if GERMAN
            .name = _("Nestor"),
#else
            .name = _("FLINT"),
#endif
            .facilityClass = FACILITY_CLASS_ENGINEER_FRLG,
            .textColor = 4,
            .speechBefore = {EC_WORD_I_AM, EC_WORD_LEADER, EC_WORD_AT, EC_MOVE2(MILK_DRINK), EC_WORD_THE, EC_WORD_WORLD},
            .speechWin = {EC_WORD_IF, EC_WORD_I_AM, EC_WORD_WINS, EC_WORD_THAT, EC_MOVE2(MILK_DRINK), EC_WORD_EXCL},
            .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_DRINK, EC_WORD_MORE, EC_MOVE2(MILK_DRINK), EC_WORD_EXCL},
            .speechAfter = {EC_WORD_WROOOAAR_EXCL, EC_WORD_EXCL, EC_WORD_I, EC_WORD_DROOLING, EC_WORD_ALL, EC_WORD_FULL},
            .mons =
            {
                {
                    .species = SPECIES_WIGGLYTUFF,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_WATER_PULSE, MOVE_FLAMETHROWER},
                    .hpEV = 0,
                    .attackEV = 0,
                    .defenseEV = 155,
                    .speedEV = 0,
                    .spAttackEV = 255,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_RELAXED_4,
#if GERMAN
                    .nickname = _("Knuddeluff"),
#else
                    .nickname = _("WIGGLYTUFF"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_CLEFABLE,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_SOFT_BOILED, MOVE_METEOR_MASH, MOVE_DOUBLE_EDGE},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 100,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 150,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_RELAXED_4,
#if GERMAN
                    .nickname = _("Pixi"),
#else
                    .nickname = _("CLEFABLE"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDOQUEEN,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_THUNDERBOLT, MOVE_CRUNCH, MOVE_SUPERPOWER, MOVE_SURF},
                    .hpEV = 0,
                    .attackEV = 200,
                    .defenseEV = 110,
                    .speedEV = 0,
                    .spAttackEV = 100,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_FEMALE_RELAXED,
#if GERMAN
                    .nickname = _("Nidoqueen"),
#else
                    .nickname = _("NIDOQUEEN"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_NIDOKING,
                    .heldItem = ITEM_CHOICE_BAND,
                    .moves = {MOVE_THUNDERBOLT, MOVE_HYPER_BEAM, MOVE_MEGAHORN, MOVE_SHADOW_BALL},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 150,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 100,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_BRAVE,
#if GERMAN
                    .nickname = _("Nidoking"),
#else
                    .nickname = _("NIDOKING"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_RAICHU,
                    .heldItem = ITEM_SALAC_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_REVERSAL, MOVE_IRON_TAIL, MOVE_DOUBLE_EDGE},
                    .hpEV = 0,
                    .attackEV = 155,
                    .defenseEV = 150,
                    .speedEV = 100,
                    .spAttackEV = 0,
                    .spDefenseEV = 105,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Raichu"),
#else
                    .nickname = _("RAICHU"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
                {
                    .species = SPECIES_AMPHAROS,
                    .heldItem = ITEM_LUM_BERRY,
                    .moves = {MOVE_THUNDERBOLT, MOVE_REST, MOVE_BODY_SLAM, MOVE_IRON_TAIL},
                    .hpEV = 0,
                    .attackEV = 255,
                    .defenseEV = 150,
                    .speedEV = 0,
                    .spAttackEV = 0,
                    .spDefenseEV = 105,
                    .otId = TRAINER_TOWER_OTID,
                    .hpIV = 15,
                    .attackIV = 15,
                    .defenseIV = 15,
                    .speedIV = 15,
                    .spAttackIV = 15,
                    .spDefenseIV = 15,
                    .abilityNum = 0,
                    .personality = PERSONALITY_MALE_ADAMANT_4,
#if GERMAN
                    .nickname = _("Ampharos"),
#else
                    .nickname = _("AMPHAROS"),
#endif
                    .friendship = MAX_FRIENDSHIP
                },
            }
        },
    },
    .checksum = 0x00016b80
};

const struct EReaderTrainerTowerSetSubstruct gTrainerTowerLocalHeader = {
    .numFloors = MAX_TRAINER_TOWER_FLOORS,
    .id = 1
};

const struct TrainerTowerFloor *const gTrainerTowerFloors[NUM_TOWER_CHALLENGE_TYPES][MAX_TRAINER_TOWER_FLOORS] = {
    [CHALLENGE_TYPE_SINGLE] = {
        &sTrainerTowerFloor_Single_1,
        &sTrainerTowerFloor_Single_2,
        &sTrainerTowerFloor_Single_3,
        &sTrainerTowerFloor_Single_4,
        &sTrainerTowerFloor_Single_5,
        &sTrainerTowerFloor_Single_6,
        &sTrainerTowerFloor_Single_7,
        &sTrainerTowerFloor_Single_8
    },
    [CHALLENGE_TYPE_DOUBLE] = {
        &sTrainerTowerFloor_Double_1,
        &sTrainerTowerFloor_Double_2,
        &sTrainerTowerFloor_Double_3,
        &sTrainerTowerFloor_Double_4,
        &sTrainerTowerFloor_Double_5,
        &sTrainerTowerFloor_Double_6,
        &sTrainerTowerFloor_Double_7,
        &sTrainerTowerFloor_Double_8
    },
    [CHALLENGE_TYPE_KNOCKOUT] = {
        &sTrainerTowerFloor_Knockout_1,
        &sTrainerTowerFloor_Knockout_2,
        &sTrainerTowerFloor_Knockout_3,
        &sTrainerTowerFloor_Knockout_4,
        &sTrainerTowerFloor_Knockout_5,
        &sTrainerTowerFloor_Knockout_6,
        &sTrainerTowerFloor_Knockout_7,
        &sTrainerTowerFloor_Knockout_8
    },
    [CHALLENGE_TYPE_MIXED] = {
        &sTrainerTowerFloor_Mixed_1,
        &sTrainerTowerFloor_Mixed_2,
        &sTrainerTowerFloor_Mixed_3,
        &sTrainerTowerFloor_Double_8,
        &sTrainerTowerFloor_Mixed_5,
        &sTrainerTowerFloor_Knockout_8,
        &sTrainerTowerFloor_Double_3,
        &sTrainerTowerFloor_Knockout_2
    }
};
