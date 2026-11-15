
#include "global.h"
#include "contest.h"

enum {
    CONTEST_OPPONENT_JIMMY,
    CONTEST_OPPONENT_EDITH,
    CONTEST_OPPONENT_EVAN,
    CONTEST_OPPONENT_KELSEY,
    CONTEST_OPPONENT_MADISON,
    CONTEST_OPPONENT_RAYMOND,
    CONTEST_OPPONENT_GRANT,
    CONTEST_OPPONENT_PAIGE,
    CONTEST_OPPONENT_ALEC,
    CONTEST_OPPONENT_SYDNEY,
    CONTEST_OPPONENT_MORRIS,
    CONTEST_OPPONENT_MARIAH,
    CONTEST_OPPONENT_RUSSELL,
    CONTEST_OPPONENT_MELANIE,
    CONTEST_OPPONENT_CHANCE,
    CONTEST_OPPONENT_AGATHA,
    CONTEST_OPPONENT_BEAU,
    CONTEST_OPPONENT_KAY,
    CONTEST_OPPONENT_CALE,
    CONTEST_OPPONENT_CAITLIN,
    CONTEST_OPPONENT_COLBY,
    CONTEST_OPPONENT_KYLIE,
    CONTEST_OPPONENT_LIAM,
    CONTEST_OPPONENT_MILO,
    CONTEST_OPPONENT_KARINA,
    CONTEST_OPPONENT_BOBBY,
    CONTEST_OPPONENT_CLAIRE,
    CONTEST_OPPONENT_WILLIE,
    CONTEST_OPPONENT_CASSIDY,
    CONTEST_OPPONENT_MORGAN,
    CONTEST_OPPONENT_SUMMER,
    CONTEST_OPPONENT_MILES,
    CONTEST_OPPONENT_AUDREY,
    CONTEST_OPPONENT_AVERY,
    CONTEST_OPPONENT_ARIANA,
    CONTEST_OPPONENT_ASHTON,
    CONTEST_OPPONENT_SANDRA,
    CONTEST_OPPONENT_CARSON,
    CONTEST_OPPONENT_KATRINA,
    CONTEST_OPPONENT_LUKE,
    CONTEST_OPPONENT_RAUL,
    CONTEST_OPPONENT_JADA,
    CONTEST_OPPONENT_ZEEK,
    CONTEST_OPPONENT_DIEGO,
    CONTEST_OPPONENT_ALIYAH,
    CONTEST_OPPONENT_NATALIA,
    CONTEST_OPPONENT_DEVIN,
    CONTEST_OPPONENT_TYLOR,
    CONTEST_OPPONENT_RONNIE,
    CONTEST_OPPONENT_CLAUDIA,
    CONTEST_OPPONENT_ELIAS,
    CONTEST_OPPONENT_JADE,
    CONTEST_OPPONENT_FRANCIS,
    CONTEST_OPPONENT_ALISHA,
    CONTEST_OPPONENT_SAUL,
    CONTEST_OPPONENT_FELICIA,
    CONTEST_OPPONENT_EMILIO,
    CONTEST_OPPONENT_KARLA,
    CONTEST_OPPONENT_DARRYL,
    CONTEST_OPPONENT_SELENA,
    CONTEST_OPPONENT_NOEL,
    CONTEST_OPPONENT_LACEY,
    CONTEST_OPPONENT_CORBIN,
    CONTEST_OPPONENT_GRACIE,
    CONTEST_OPPONENT_COLTIN,
    CONTEST_OPPONENT_ELLIE,
    CONTEST_OPPONENT_MARCUS,
    CONTEST_OPPONENT_KIARA,
    CONTEST_OPPONENT_BRYCE,
    CONTEST_OPPONENT_JAMIE,
    CONTEST_OPPONENT_JORGE,
    CONTEST_OPPONENT_DEVON,
    CONTEST_OPPONENT_JUSTINA,
    CONTEST_OPPONENT_RALPH,
    CONTEST_OPPONENT_ROSA,
    CONTEST_OPPONENT_KEATON,
    CONTEST_OPPONENT_MAYRA,
    CONTEST_OPPONENT_LAMAR,
    CONTEST_OPPONENT_AUBREY,
    CONTEST_OPPONENT_NIGEL,
    CONTEST_OPPONENT_CAMILLE,
    CONTEST_OPPONENT_DEON,
    CONTEST_OPPONENT_JANELLE,
    CONTEST_OPPONENT_HEATH,
    CONTEST_OPPONENT_SASHA,
    CONTEST_OPPONENT_FRANKIE,
    CONTEST_OPPONENT_HELEN,
    CONTEST_OPPONENT_CAMILE,
    CONTEST_OPPONENT_MARTIN,
    CONTEST_OPPONENT_SERGIO,
    CONTEST_OPPONENT_KAILEY,
    CONTEST_OPPONENT_PERLA,
    CONTEST_OPPONENT_CLARA,
    CONTEST_OPPONENT_JAKOB,
    CONTEST_OPPONENT_TREY,
    CONTEST_OPPONENT_LANE
};

// All contest opponents have a common set of AI flags (which contains all of the actually
// useful AI scripts, as well as some dummys) and a random combination of 2-3 dummy flags.
// Seems that like the battle AI they had more plans for this than what ended up in the final game
#define CONTEST_AI_SET_1  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_2  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_19 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_3  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_18 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_4  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_17 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_5  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_16 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_6  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_7  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_8  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_13 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_9  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_24)
#define CONTEST_AI_SET_A  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_11 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_B  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_10 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_C  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_9  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_D  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_8  | CONTEST_AI_DUMMY_22 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_E  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_24)
#define CONTEST_AI_SET_F  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_6  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_10 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_11 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_18 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_12 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_17 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_13 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_16 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_14 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_15 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_16 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_13 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_17 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_23 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_18 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_10 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_19 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_9  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1A (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_8  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1B (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_1C (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_6  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_1D (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1E (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1F (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_20 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_21 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_25)

// All AI contestants have the same trainer ID
#define CONTEST_AI_TRAINER_ID 0xFFFF

const struct ContestWinner gDefaultContestWinners[] =
{
    [CONTEST_WINNER_HALL_1 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_ELECTRIKE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
#if GERMAN
        .monName = _("Frizzo"),
        .trainerName = _("Günter"),
#else
        .monName = _("ELECTER"),
        .trainerName = _("EZRA"),
#endif
        .contestRank = CONTEST_RANK_NORMAL
    },
    [CONTEST_WINNER_HALL_2 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_TROPIUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
#if GERMAN
        .monName = _("Tropi"),
        .trainerName = _("Ernst"),
#else
        .monName = _("TROPO"),
        .trainerName = _("ALLAN"),
#endif
        .contestRank = CONTEST_RANK_HYPER
    },
    [CONTEST_WINNER_HALL_3 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_XATU,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
#if GERMAN
        .monName = _("Utax"),
        .trainerName = _("Pia"),
#else
        .monName = _("TUXA"),
        .trainerName = _("JULIET"),
#endif
        .contestRank = CONTEST_RANK_NORMAL
    },
    [CONTEST_WINNER_HALL_4 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_PLUSLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
#if GERMAN
        .monName = _("Plusimo"),
        .trainerName = _("Udo"),
#else
        .monName = _("PULSE"),
        .trainerName = _("BAILY"),
#endif
        .contestRank = CONTEST_RANK_MASTER
    },
    [CONTEST_WINNER_HALL_5 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_SHUPPET,
        .contestCategory = CONTEST_CATEGORY_SMART,
#if GERMAN
        .monName = _("Shupsi"),
        .trainerName = _("Mirjam"),
#else
        .monName = _("SHUPUP"),
        .trainerName = _("MELANY"),
#endif
        .contestRank = CONTEST_RANK_SUPER
    },
    [CONTEST_WINNER_HALL_6 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_ZANGOOSE,
        .contestCategory = CONTEST_CATEGORY_COOL,
#if GERMAN
        .monName = _("Genso"),
        .trainerName = _("Eva"),
#else
        .monName = _("GOOZAN"),
        .trainerName = _("HANA"),
#endif
        .contestRank = CONTEST_RANK_HYPER
    },
    [CONTEST_WINNER_HALL_UNUSED_1 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_LOUDRED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
#if GERMAN
        .monName = _("Keelo"),
        .trainerName = _("Isegrim"),
#else
        .monName = _("LOUDED"),
        .trainerName = _("BRYANT"),
#endif
        .contestRank = CONTEST_RANK_HYPER
    },
    [CONTEST_WINNER_HALL_UNUSED_2 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_DELCATTY,
        .contestCategory = CONTEST_CATEGORY_CUTE,
#if GERMAN
        .monName = _("Conec"),
        .trainerName = _("Haubert"),
#else
        .monName = _("KITSY"),
        .trainerName = _("OMAR"),
#endif
        .contestRank = CONTEST_RANK_MASTER
    }
};

const struct ContestPokemon gContestOpponents[] =
{
    [CONTEST_OPPONENT_JIMMY] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_POOCHYENA,
#if GERMAN
        .nickname = _("Fiffi"),
        .trainerName = _("Jimmy"),
#else
        .nickname = _("POOCHY"),
        .trainerName = _("JIMMY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BOY_1,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_ROAR,
            MOVE_BITE,
            MOVE_TAKE_DOWN,
            MOVE_HOWL
        },
        .cool = 10,
        .beauty = 4,
        .cute = 10,
        .smart = 3,
        .tough = 4,
        .sheen = 50,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_EDITH] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_ILLUMISE,
#if GERMAN
        .nickname = _("Luxi"),
        .trainerName = _("Klara"),
#else
        .nickname = _("MUSILLE"),
        .trainerName = _("EDITH"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_REST,
            MOVE_FACADE,
            MOVE_TACKLE,
            MOVE_COVET
        },
        .cool = 10,
        .beauty = 10,
        .cute = 6,
        .smart = 1,
        .tough = 2,
        .sheen = 60,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_EVAN] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_DUSTOX,
#if GERMAN
        .nickname = _("Doxu"),
        .trainerName = _("Karlo"),
#else
        .nickname = _("DUSTER"),
        .trainerName = _("EVAN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SILVER_WIND,
            MOVE_MOONLIGHT,
            MOVE_LIGHT_SCREEN,
            MOVE_GUST
        },
        .cool = 2,
        .beauty = 10,
        .cute = 10,
        .smart = 12,
        .tough = 4,
        .sheen = 70,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KELSEY] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SEEDOT,
#if GERMAN
        .nickname = _("Samini"),
        .trainerName = _("Trudi"),
#else
        .nickname = _("DOTS"),
        .trainerName = _("KELSEY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_BIDE,
            MOVE_SYNTHESIS,
            MOVE_BULLET_SEED,
            MOVE_GROWTH
        },
        .cool = 3,
        .beauty = 3,
        .cute = 5,
        .smart = 2,
        .tough = 7,
        .sheen = 80,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MADISON] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_TAILLOW,
#if GERMAN
        .nickname = _("Schwalbi"),
        .trainerName = _("Helena"),
#else
        .nickname = _("TATAY"),
        .trainerName = _("MADISON"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_WING_ATTACK,
            MOVE_AGILITY,
            MOVE_AERIAL_ACE,
            MOVE_GROWL
        },
        .cool = 1,
        .beauty = 3,
        .cute = 3,
        .smart = 5,
        .tough = 4,
        .sheen = 90,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_RAYMOND] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_NINCADA,
#if GERMAN
        .nickname = _("Cadinja"),
        .trainerName = _("Willi"),
#else
        .nickname = _("NINDA"),
        .trainerName = _("RAYMOND"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_LEECH_LIFE,
            MOVE_FALSE_SWIPE,
            MOVE_FURY_SWIPES,
            MOVE_MIND_READER
        },
        .cool = 5,
        .beauty = 2,
        .cute = 10,
        .smart = 7,
        .tough = 8,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_GRANT] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SHROOMISH,
#if GERMAN
        .nickname = _("Knilzli"),
        .trainerName = _("Hartmut"),
#else
        .nickname = _("SMISH"),
        .trainerName = _("GRANT"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_STUN_SPORE,
            MOVE_LEECH_SEED,
            MOVE_MEGA_DRAIN,
            MOVE_ATTRACT
        },
        .cool = 3,
        .beauty = 3,
        .cute = 10,
        .smart = 2,
        .tough = 2,
        .sheen = 50,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_PAIGE] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SPHEAL,
#if GERMAN
        .nickname = _("Mopso"),
        .trainerName = _("Claudia"),
#else
        .nickname = _("SLEAL"),
        .trainerName = _("PAIGE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_AURORA_BEAM,
            MOVE_WATER_GUN,
            MOVE_GROWL,
            MOVE_ROCK_TOMB
        },
        .cool = 3,
        .beauty = 5,
        .cute = 1,
        .smart = 10,
        .tough = 10,
        .sheen = 60,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ALEC] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SLAKOTH,
#if GERMAN
        .nickname = _("Blumpi"),
        .trainerName = _("Alec"),
#else
        .nickname = _("SLOKTH"),
        .trainerName = _("ALEC"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_STRENGTH,
            MOVE_COUNTER,
            MOVE_YAWN,
            MOVE_ENCORE
        },
        .cool = 10,
        .beauty = 4,
        .cute = 4,
        .smart = 5,
        .tough = 18,
        .sheen = 70,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SYDNEY] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_WHISMUR,
#if GERMAN
        .nickname = _("Flurmi"),
        .trainerName = _("Silke"),
#else
        .nickname = _("WHIRIS"),
        .trainerName = _("SYDNEY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ASTONISH,
            MOVE_SCREECH,
            MOVE_UPROAR,
            MOVE_HYPER_VOICE
        },
        .cool = 2,
        .beauty = 2,
        .cute = 7,
        .smart = 2,
        .tough = 7,
        .sheen = 80,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MORRIS] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_MAKUHITA,
#if GERMAN
        .nickname = _("Mahita"),
        .trainerName = _("Peer"),
#else
        .nickname = _("MAHITA"),
        .trainerName = _("MORRIS"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_B,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SEISMIC_TOSS,
            MOVE_VITAL_THROW,
            MOVE_TACKLE,
            MOVE_REVERSAL
        },
        .cool = 9,
        .beauty = 1,
        .cute = 1,
        .smart = 8,
        .tough = 1,
        .sheen = 90,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MARIAH] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_ARON,
#if GERMAN
        .nickname = _("Stolli"),
        .trainerName = _("Maria"),
#else
        .nickname = _("RONAR"),
        .trainerName = _("MARIAH"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_C,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_METAL_CLAW,
            MOVE_IRON_DEFENSE,
            MOVE_HEADBUTT,
            MOVE_TAKE_DOWN
        },
        .cool = 5,
        .beauty = 10,
        .cute = 2,
        .smart = 10,
        .tough = 2,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_RUSSELL] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_CROBAT,
#if GERMAN
        .nickname = _("X-Flies"),
        .trainerName = _("Rudolf"),
#else
        .nickname = _("BATRO"),
        .trainerName = _("RUSSELL"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_D,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_HAZE,
            MOVE_MEAN_LOOK,
            MOVE_CONFUSE_RAY,
            MOVE_LEECH_LIFE
        },
        .cool = 4,
        .beauty = 2,
        .cute = 2,
        .smart = 2,
        .tough = 10,
        .sheen = 50,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MELANIE] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_GULPIN,
#if GERMAN
        .nickname = _("Schluppi"),
        .trainerName = _("Melanie"),
#else
        .nickname = _("GULIN"),
        .trainerName = _("MELANIE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_E,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SLUDGE,
            MOVE_AMNESIA,
            MOVE_TOXIC,
            MOVE_YAWN
        },
        .cool = 1,
        .beauty = 10,
        .cute = 1,
        .smart = 10,
        .tough = 5,
        .sheen = 60,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CHANCE] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_MANECTRIC,
#if GERMAN
        .nickname = _("Frizzzel"),
        .trainerName = _("Bertram"),
#else
        .nickname = _("RIKELEC"),
        .trainerName = _("CHANCE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_RICH_BOY,
        .aiFlags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SPARK,
            MOVE_THUNDER_WAVE,
            MOVE_THUNDER,
            MOVE_ROAR
        },
        .cool = 20,
        .beauty = 10,
        .cute = 1,
        .smart = 1,
        .tough = 1,
        .sheen = 70,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_AGATHA] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_BULBASAUR,
#if GERMAN
        .nickname = _("Samsi"),
        .trainerName = _("Desiree"),
#else
        .nickname = _("BULBY"),
        .trainerName = _("AGATHA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWL,
            MOVE_LEECH_SEED,
            MOVE_TACKLE,
            MOVE_SWEET_SCENT
        },
        .cool = 5,
        .beauty = 3,
        .cute = 10,
        .smart = 10,
        .tough = 4,
        .sheen = 50,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_BEAU] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_BUTTERFREE,
#if GERMAN
        .nickname = _("Schmetti"),
        .trainerName = _("Emma"),
#else
        .nickname = _("FUTTERBE"),
        .trainerName = _("BEAU"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_HEX_MANIAC,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SUPERSONIC,
            MOVE_WHIRLWIND,
            MOVE_SILVER_WIND,
            MOVE_SAFEGUARD
        },
        .cool = 3,
        .beauty = 10,
        .cute = 2,
        .smart = 10,
        .tough = 4,
        .sheen = 60,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KAY] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_PIDGEOTTO,
#if GERMAN
        .nickname = _("Ogaboga"),
        .trainerName = _("Julia"),
#else
        .nickname = _("PIDEOT"),
        .trainerName = _("KAY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_5,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MIRROR_MOVE,
            MOVE_QUICK_ATTACK,
            MOVE_AERIAL_ACE,
            MOVE_FEATHER_DANCE
        },
        .cool = 10,
        .beauty = 8,
        .cute = 4,
        .smart = 2,
        .tough = 3,
        .sheen = 70,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CALE] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_DIGLETT,
#if GERMAN
        .nickname = _("Gidda"),
        .trainerName = _("Hans"),
#else
        .nickname = _("DIGLE"),
        .trainerName = _("CALE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_HIKER,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_DIG,
            MOVE_EARTHQUAKE,
            MOVE_FISSURE,
            MOVE_MAGNITUDE
        },
        .cool = 4,
        .beauty = 2,
        .cute = 3,
        .smart = 5,
        .tough = 10,
        .sheen = 80,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CAITLIN] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_POLIWAG,
#if GERMAN
        .nickname = _("Quappi"),
        .trainerName = _("Andrea"),
#else
        .nickname = _("WAGIL"),
        .trainerName = _("CAITLIN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TUBER_F,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_HYDRO_PUMP,
            MOVE_RAIN_DANCE,
            MOVE_BODY_SLAM,
            MOVE_ICE_BEAM
        },
        .cool = 2,
        .beauty = 10,
        .cute = 5,
        .smart = 3,
        .tough = 10,
        .sheen = 90,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_COLBY] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_TOTODILE,
#if GERMAN
        .nickname = _("Kroka"),
        .trainerName = _("Kevin"),
#else
        .nickname = _("TOTDIL"),
        .trainerName = _("COLBY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_NINJA_BOY,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_RAGE,
            MOVE_SCREECH,
            MOVE_SURF,
            MOVE_BLIZZARD
        },
        .cool = 6,
        .beauty = 10,
        .cute = 2,
        .smart = 1,
        .tough = 5,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KYLIE] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_LEDYBA,
#if GERMAN
        .nickname = _("Marikä"),
        .trainerName = _("Beate"),
#else
        .nickname = _("BALEDY"),
        .trainerName = _("KYLIE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BEAUTY,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_BATON_PASS,
            MOVE_AGILITY,
            MOVE_SWIFT,
            MOVE_ATTRACT
        },
        .cool = 8,
        .beauty = 6,
        .cute = 8,
        .smart = 6,
        .tough = 2,
        .sheen = 90,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_LIAM] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_DELIBIRD,
#if GERMAN
        .nickname = _("Kurry"),
        .trainerName = _("Leslie"),
#else
        .nickname = _("BIRDLY"),
        .trainerName = _("LIAM"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_5,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_PRESENT,
            MOVE_FACADE,
            MOVE_FOCUS_PUNCH,
            MOVE_RETURN
        },
        .cool = 4,
        .beauty = 3,
        .cute = 10,
        .smart = 5,
        .tough = 3,
        .sheen = 80,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MILO] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_LARVITAR,
#if GERMAN
        .nickname = _("Tarlar"),
        .trainerName = _("Oskar"),
#else
        .nickname = _("TARVITAR"),
        .trainerName = _("MILO"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MANIAC,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_THRASH,
            MOVE_TORMENT,
            MOVE_CRUNCH,
            MOVE_DIG
        },
        .cool = 8,
        .beauty = 5,
        .cute = 5,
        .smart = 8,
        .tough = 10,
        .sheen = 70,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KARINA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_ROSELIA,
#if GERMAN
        .nickname = _("Rosali"),
        .trainerName = _("Karina"),
#else
        .nickname = _("RELIA"),
        .trainerName = _("KARINA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .aiFlags = CONTEST_AI_SET_10,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PETAL_DANCE,
            MOVE_MAGICAL_LEAF,
            MOVE_GRASS_WHISTLE,
            MOVE_INGRAIN
        },
        .cool = 50,
        .beauty = 15,
        .cute = 75,
        .smart = 10,
        .tough = 20,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_BOBBY] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_DODRIO,
#if GERMAN
        .nickname = _("Doldi"),
        .trainerName = _("Bobby"),
#else
        .nickname = _("DUODO"),
        .trainerName = _("BOBBY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_PECK,
            MOVE_FURY_ATTACK,
            MOVE_RETURN,
            MOVE_GROWL
        },
        .cool = 15,
        .beauty = 21,
        .cute = 15,
        .smart = 85,
        .tough = 35,
        .sheen = 110,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CLAIRE] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_TRAPINCH,
#if GERMAN
        .nickname = _("Knacki"),
        .trainerName = _("Judith"),
#else
        .nickname = _("PINCHIN"),
        .trainerName = _("CLAIRE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_BITE,
            MOVE_SAND_ATTACK,
            MOVE_DIG,
            MOVE_FEINT_ATTACK
        },
        .cool = 75,
        .beauty = 25,
        .cute = 25,
        .smart = 10,
        .tough = 25,
        .sheen = 120,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_WILLIE] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_CACNEA,
#if GERMAN
        .nickname = _("Kotus"),
        .trainerName = _("Helmut"),
#else
        .nickname = _("NACAC"),
        .trainerName = _("WILLIE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SPIKES,
            MOVE_LEER,
            MOVE_POISON_STING,
            MOVE_SAND_ATTACK
        },
        .cool = 10,
        .beauty = 30,
        .cute = 25,
        .smart = 65,
        .tough = 25,
        .sheen = 130,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CASSIDY] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SANDSLASH,
#if GERMAN
        .nickname = _("Sadan"),
        .trainerName = _("Britta"),
#else
        .nickname = _("SHRAND"),
        .trainerName = _("CASSIDY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_13,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SLASH,
            MOVE_DEFENSE_CURL,
            MOVE_SWIFT,
            MOVE_FURY_SWIPES
        },
        .cool = 30,
        .beauty = 90,
        .cute = 30,
        .smart = 10,
        .tough = 100,
        .sheen = 140,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MORGAN] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_BALTOY,
#if GERMAN
        .nickname = _("Puppibal"),
        .trainerName = _("Torben"),
#else
        .nickname = _("TOYBAL"),
        .trainerName = _("MORGAN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_14,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SELF_DESTRUCT,
            MOVE_ROCK_TOMB,
            MOVE_PSYBEAM,
            MOVE_CONFUSION
        },
        .cool = 50,
        .beauty = 40,
        .cute = 10,
        .smart = 35,
        .tough = 35,
        .sheen = 150,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SUMMER] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_MEDICHAM,
#if GERMAN
        .nickname = _("Infernalis"),
        .trainerName = _("Bianka"),
#else
        .nickname = _("CHAMCHAM"),
        .trainerName = _("SUMMER"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_15,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_REVERSAL,
            MOVE_THUNDER_PUNCH,
            MOVE_FIRE_PUNCH,
            MOVE_ICE_PUNCH
        },
        .cool = 40,
        .beauty = 20,
        .cute = 40,
        .smart = 40,
        .tough = 40,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MILES] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SPINDA,
#if GERMAN
        .nickname = _("Spirrwirr"),
        .trainerName = _("Alex"),
#else
        .nickname = _("SPININ"),
        .trainerName = _("MILES"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_TEETER_DANCE,
            MOVE_PSYCH_UP,
            MOVE_HYPNOSIS,
            MOVE_UPROAR
        },
        .cool = 25,
        .beauty = 75,
        .cute = 25,
        .smart = 10,
        .tough = 25,
        .sheen = 110,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_AUDREY] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SWABLU,
#if GERMAN
        .nickname = _("Bluppf"),
        .trainerName = _("Sabine"),
#else
        .nickname = _("SWABY"),
        .trainerName = _("AUDREY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_17,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MIRROR_MOVE,
            MOVE_PERISH_SONG,
            MOVE_SAFEGUARD,
            MOVE_MIST
        },
        .cool = 30,
        .beauty = 30,
        .cute = 40,
        .smart = 30,
        .tough = 25,
        .sheen = 120,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_AVERY] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SPOINK,
#if GERMAN
        .nickname = _("Grunzo"),
        .trainerName = _("August"),
#else
        .nickname = _("POINKER"),
        .trainerName = _("AVERY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SPLASH,
            MOVE_CONFUSE_RAY,
            MOVE_SNORE,
            MOVE_REST
        },
        .cool = 40,
        .beauty = 10,
        .cute = 30,
        .smart = 40,
        .tough = 30,
        .sheen = 130,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ARIANA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_KECLEON,
#if GERMAN
        .nickname = _("Kecli"),
        .trainerName = _("Ariana"),
#else
        .nickname = _("KECON"),
        .trainerName = _("ARIANA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_THIEF,
            MOVE_SCREECH,
            MOVE_ANCIENT_POWER,
            MOVE_BIND
        },
        .cool = 10,
        .beauty = 10,
        .cute = 40,
        .smart = 75,
        .tough = 35,
        .sheen = 140,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ASHTON] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_GOLDEEN,
#if GERMAN
        .nickname = _("Goldinchen"),
        .trainerName = _("Toni"),
#else
        .nickname = _("GOLDEN"),
        .trainerName = _("ASHTON"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_HORN_ATTACK,
            MOVE_FURY_ATTACK,
            MOVE_HORN_DRILL,
            MOVE_TAIL_WHIP
        },
        .cool = 70,
        .beauty = 30,
        .cute = 5,
        .smart = 30,
        .tough = 25,
        .sheen = 150,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SANDRA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_BARBOACH,
#if GERMAN
        .nickname = _("Schmerbse"),
        .trainerName = _("Susi"),
#else
        .nickname = _("BOBOACH"),
        .trainerName = _("SANDRA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_MUD_SPORT,
            MOVE_WATER_SPORT,
            MOVE_EARTHQUAKE,
            MOVE_FUTURE_SIGHT
        },
        .cool = 45,
        .beauty = 45,
        .cute = 60,
        .smart = 25,
        .tough = 15,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CARSON] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SKARMORY,
#if GERMAN
        .nickname = _("Leopanz"),
        .trainerName = _("Clemens"),
#else
        .nickname = _("CORPY"),
        .trainerName = _("CARSON"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_1B,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SWIFT,
            MOVE_DOUBLE_TEAM,
            MOVE_AGILITY,
            MOVE_CUT
        },
        .cool = 40,
        .beauty = 30,
        .cute = 25,
        .smart = 60,
        .tough = 20,
        .sheen = 110,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KATRINA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_LOTAD,
#if GERMAN
        .nickname = _("Urlotzo"),
        .trainerName = _("Katrin"),
#else
        .nickname = _("TADO"),
        .trainerName = _("KATRINA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_1C,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ASTONISH,
            MOVE_GROWL,
            MOVE_RAIN_DANCE,
            MOVE_WATER_PULSE
        },
        .cool = 15,
        .beauty = 15,
        .cute = 30,
        .smart = 15,
        .tough = 75,
        .sheen = 120,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_LUKE] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_SLOWBRO,
#if GERMAN
        .nickname = _("Jahnus"),
        .trainerName = _("Lukas"),
#else
        .nickname = _("BROWLO"),
        .trainerName = _("LUKE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_FAT_MAN,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_YAWN,
            MOVE_DISABLE,
            MOVE_GROWL,
            MOVE_CONFUSION
        },
        .cool = 20,
        .beauty = 40,
        .cute = 40,
        .smart = 30,
        .tough = 20,
        .sheen = 100,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_RAUL] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_FARFETCHD,
#if GERMAN
        .nickname = _("Polente"),
        .trainerName = _("Ramon"),
#else
        .nickname = _("FETCHIN"),
        .trainerName = _("RAUL"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_5,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_FACADE,
            MOVE_FURY_CUTTER,
            MOVE_FLY,
            MOVE_RETURN
        },
        .cool = 40,
        .beauty = 10,
        .cute = 40,
        .smart = 20,
        .tough = 20,
        .sheen = 110,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JADA] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_SEEL,
#if GERMAN
        .nickname = _("Robbie"),
        .trainerName = _("Janina"),
#else
        .nickname = _("SEELEY"),
        .trainerName = _("JADA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ATTRACT,
            MOVE_ICE_BEAM,
            MOVE_SAFEGUARD,
            MOVE_GROWL
        },
        .cool = 10,
        .beauty = 30,
        .cute = 40,
        .smart = 20,
        .tough = 20,
        .sheen = 120,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ZEEK] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_DROWZEE,
#if GERMAN
        .nickname = _("Traudel"),
        .trainerName = _("Karl"),
#else
        .nickname = _("DROWZIN"),
        .trainerName = _("ZEEK"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_PSYCHIC_M,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_DISABLE,
            MOVE_FUTURE_SIGHT,
            MOVE_HIDDEN_POWER,
            MOVE_RETURN
        },
        .cool = 10,
        .beauty = 40,
        .cute = 50,
        .smart = 30,
        .tough = 45,
        .sheen = 130,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_DIEGO] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_HITMONCHAN,
#if GERMAN
        .nickname = _("Ginockjan"),
        .trainerName = _("Fabio"),
#else
        .nickname = _("HITEMON"),
        .trainerName = _("DIEGO"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_M,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SKY_UPPERCUT,
            MOVE_DETECT,
            MOVE_REVENGE,
            MOVE_MEGA_PUNCH
        },
        .cool = 45,
        .beauty = 20,
        .cute = 10,
        .smart = 20,
        .tough = 45,
        .sheen = 140,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ALIYAH] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_BLISSEY,
#if GERMAN
        .nickname = _("Heidi"),
        .trainerName = _("Ramona"),
#else
        .nickname = _("BLISS"),
        .trainerName = _("ALIYAH"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TEALA,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SING,
            MOVE_SOFT_BOILED,
            MOVE_EGG_BOMB,
            MOVE_DOUBLE_EDGE
        },
        .cool = 20,
        .beauty = 35,
        .cute = 40,
        .smart = 20,
        .tough = 20,
        .sheen = 150,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_NATALIA] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_ELEKID,
#if GERMAN
        .nickname = _("Elli"),
        .trainerName = _("Nadine"),
#else
        .nickname = _("KIDLEK"),
        .trainerName = _("NATALIA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SHOCK_WAVE,
            MOVE_QUICK_ATTACK,
            MOVE_SCREECH,
            MOVE_ATTRACT
        },
        .cool = 40,
        .beauty = 10,
        .cute = 40,
        .smart = 25,
        .tough = 25,
        .sheen = 140,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_DEVIN] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_SNUBBULL,
#if GERMAN
        .nickname = _("Stupsi"),
        .trainerName = _("Mirko"),
#else
        .nickname = _("SNUBBINS"),
        .trainerName = _("DEVIN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GENTLEMAN,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SCARY_FACE,
            MOVE_TAUNT,
            MOVE_TAIL_WHIP,
            MOVE_BITE
        },
        .cool = 20,
        .beauty = 20,
        .cute = 20,
        .smart = 20,
        .tough = 20,
        .sheen = 130,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_TYLOR] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_MISDREAVUS,
#if GERMAN
        .nickname = _("Trauni"),
        .trainerName = _("Hanna"),
#else
        .nickname = _("DREAVIS"),
        .trainerName = _("TYLOR"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_HEX_MANIAC,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PERISH_SONG,
            MOVE_MEAN_LOOK,
            MOVE_CONFUSE_RAY,
            MOVE_PAIN_SPLIT
        },
        .cool = 10,
        .beauty = 35,
        .cute = 10,
        .smart = 45,
        .tough = 20,
        .sheen = 120,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_RONNIE] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_LAIRON,
#if GERMAN
        .nickname = _("Strollak"),
        .trainerName = _("Achim"),
#else
        .nickname = _("LAIRN"),
        .trainerName = _("RONNIE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_HIKER,
        .aiFlags = CONTEST_AI_SET_1D,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_METAL_SOUND,
            MOVE_METAL_CLAW,
            MOVE_HARDEN,
            MOVE_TAKE_DOWN
        },
        .cool = 30,
        .beauty = 50,
        .cute = 35,
        .smart = 100,
        .tough = 90,
        .sheen = 200,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CLAUDIA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SHIFTRY,
#if GERMAN
        .nickname = _("Stilug"),
        .trainerName = _("Gabi"),
#else
        .nickname = _("SHIFTY"),
        .trainerName = _("CLAUDIA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWTH,
            MOVE_RAZOR_WIND,
            MOVE_EXPLOSION,
            MOVE_EXTRASENSORY
        },
        .cool = 75,
        .beauty = 75,
        .cute = 65,
        .smart = 35,
        .tough = 70,
        .sheen = 210,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ELIAS] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_NINJASK,
#if GERMAN
        .nickname = _("Askinja"),
        .trainerName = _("Rolf"),
#else
        .nickname = _("NINAS"),
        .trainerName = _("ELIAS"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SCREECH,
            MOVE_FURY_SWIPES,
            MOVE_SAND_ATTACK,
            MOVE_BATON_PASS
        },
        .cool = 30,
        .beauty = 50,
        .cute = 95,
        .smart = 70,
        .tough = 70,
        .sheen = 220,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JADE] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SWELLOW,
#if GERMAN
        .nickname = _("Schwallo"),
        .trainerName = _("Else"),
#else
        .nickname = _("WELOW"),
        .trainerName = _("JADE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_AGILITY,
            MOVE_AERIAL_ACE,
            MOVE_WING_ATTACK,
            MOVE_FLY
        },
        .cool = 65,
        .beauty = 85,
        .cute = 35,
        .smart = 75,
        .tough = 40,
        .sheen = 230,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_FRANCIS] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_MIGHTYENA,
#if GERMAN
        .nickname = _("Jänagi"),
        .trainerName = _("Frank"),
#else
        .nickname = _("YENA"),
        .trainerName = _("FRANCIS"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_TAUNT,
            MOVE_THIEF,
            MOVE_ODOR_SLEUTH,
            MOVE_TAKE_DOWN
        },
        .cool = 40,
        .beauty = 80,
        .cute = 35,
        .smart = 70,
        .tough = 70,
        .sheen = 240,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ALISHA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_BEAUTIFLY,
#if GERMAN
        .nickname = _("Papinilli"),
        .trainerName = _("Anna"),
#else
        .nickname = _("TIFLY"),
        .trainerName = _("ALISHA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_1E,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MORNING_SUN,
            MOVE_SILVER_WIND,
            MOVE_STUN_SPORE,
            MOVE_SECRET_POWER
        },
        .cool = 40,
        .beauty = 70,
        .cute = 25,
        .smart = 80,
        .tough = 100,
        .sheen = 250,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SAUL] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SEAKING,
#if GERMAN
        .nickname = _("Kingola"),
        .trainerName = _("Konrad"),
#else
        .nickname = _("KINGSEA"),
        .trainerName = _("SAUL"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_1F,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_FLAIL,
            MOVE_SUPERSONIC,
            MOVE_HORN_ATTACK,
            MOVE_FURY_ATTACK
        },
        .cool = 80,
        .beauty = 60,
        .cute = 30,
        .smart = 70,
        .tough = 90,
        .sheen = 200,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_FELICIA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_CASTFORM_NORMAL,
#if GERMAN
        .nickname = _("Feomorf"),
        .trainerName = _("Luise"),
#else
        .nickname = _("CASTER"),
        .trainerName = _("FELICIA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SUNNY_DAY,
            MOVE_WEATHER_BALL,
            MOVE_SANDSTORM,
            MOVE_RETURN
        },
        .cool = 70,
        .beauty = 80,
        .cute = 80,
        .smart = 50,
        .tough = 65,
        .sheen = 210,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_EMILIO] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_MACHOKE,
#if GERMAN
        .nickname = _("Schockma"),
        .trainerName = _("Michael"),
#else
        .nickname = _("CHOKEM"),
        .trainerName = _("EMILIO"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_20,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SEISMIC_TOSS,
            MOVE_FOCUS_ENERGY,
            MOVE_KARATE_CHOP,
            MOVE_SCARY_FACE
        },
        .cool = 70,
        .beauty = 85,
        .cute = 25,
        .smart = 60,
        .tough = 50,
        .sheen = 220,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KARLA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_LOMBRE,
#if GERMAN
        .nickname = _("Ombre"),
        .trainerName = _("Anika"),
#else
        .nickname = _("LOMBE"),
        .trainerName = _("KARLA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ATTRACT,
            MOVE_FLASH,
            MOVE_UPROAR,
            MOVE_GROWL
        },
        .cool = 40,
        .beauty = 60,
        .cute = 90,
        .smart = 45,
        .tough = 70,
        .sheen = 230,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_DARRYL] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SEVIPER,
#if GERMAN
        .nickname = _("Pitisvi"),
        .trainerName = _("Detlef"),
#else
        .nickname = _("VIPES"),
        .trainerName = _("DARRYL"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_POISON_FANG,
            MOVE_GLARE,
            MOVE_WRAP,
            MOVE_SCREECH
        },
        .cool = 35,
        .beauty = 50,
        .cute = 90,
        .smart = 40,
        .tough = 100,
        .sheen = 240,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SELENA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_WAILMER,
#if GERMAN
        .nickname = _("Waila"),
        .trainerName = _("Xenia"),
#else
        .nickname = _("MERAIL"),
        .trainerName = _("SELENA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_F,
        .aiFlags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_WATER_PULSE,
            MOVE_REST,
            MOVE_WATER_SPOUT,
            MOVE_SPLASH
        },
        .cool = 30,
        .beauty = 100,
        .cute = 100,
        .smart = 50,
        .tough = 30,
        .sheen = 250,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_NOEL] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_MAGIKARP,
#if GERMAN
        .nickname = _("Kardorpa"),
        .trainerName = _("Florian"),
#else
        .nickname = _("KARPAG"),
        .trainerName = _("NOEL"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_TACKLE,
            MOVE_SPLASH,
            MOVE_FLAIL,
            MOVE_TACKLE
        },
        .cool = 30,
        .beauty = 30,
        .cute = 160,
        .smart = 50,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_LACEY] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_LUNATONE,
#if GERMAN
        .nickname = _("Luna"),
        .trainerName = _("Diana"),
#else
        .nickname = _("LUNONE"),
        .trainerName = _("LACEY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_21,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_EXPLOSION,
            MOVE_FUTURE_SIGHT,
            MOVE_PSYCHIC,
            MOVE_CONFUSION
        },
        .cool = 50,
        .beauty = 70,
        .cute = 60,
        .smart = 70,
        .tough = 50,
        .sheen = 210,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CORBIN] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_ABSOL,
#if GERMAN
        .nickname = _("Sloab"),
        .trainerName = _("Lutz"),
#else
        .nickname = _("ABSO"),
        .trainerName = _("CORBIN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MANIAC,
        .aiFlags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PERISH_SONG,
            MOVE_HAIL,
            MOVE_HYPER_BEAM,
            MOVE_SLASH
        },
        .cool = 95,
        .beauty = 80,
        .cute = 85,
        .smart = 35,
        .tough = 35,
        .sheen = 220,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_GRACIE] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_EXEGGUTOR,
#if GERMAN
        .nickname = _("Oweioh"),
        .trainerName = _("Tamara"),
#else
        .nickname = _("EGGSOR"),
        .trainerName = _("GRACIE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_STOMP,
            MOVE_HYPNOSIS,
            MOVE_EGG_BOMB,
            MOVE_SKILL_SWAP
        },
        .cool = 40,
        .beauty = 50,
        .cute = 60,
        .smart = 100,
        .tough = 80,
        .sheen = 200,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_COLTIN] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_CUBONE,
#if GERMAN
        .nickname = _("Gossar"),
        .trainerName = _("Merlin"),
#else
        .nickname = _("CUBIN"),
        .trainerName = _("COLTIN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_4,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_BONE_CLUB,
            MOVE_BONEMERANG,
            MOVE_BONE_RUSH,
            MOVE_GROWL
        },
        .cool = 40,
        .beauty = 35,
        .cute = 85,
        .smart = 35,
        .tough = 100,
        .sheen = 210,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ELLIE] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_HITMONLEE,
#if GERMAN
        .nickname = _("Knicko"),
        .trainerName = _("Birte"),
#else
        .nickname = _("HITMON"),
        .trainerName = _("ELLIE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_F,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_REVERSAL,
            MOVE_REVENGE,
            MOVE_FOCUS_ENERGY,
            MOVE_MEGA_KICK
        },
        .cool = 85,
        .beauty = 30,
        .cute = 25,
        .smart = 50,
        .tough = 100,
        .sheen = 220,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MARCUS] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_SQUIRTLE,
#if GERMAN
        .nickname = _("Krötox"),
        .trainerName = _("Albert"),
#else
        .nickname = _("SURTLE"),
        .trainerName = _("MARCUS"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SAILOR,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_TAIL_WHIP,
            MOVE_BUBBLE,
            MOVE_FOCUS_PUNCH,
            MOVE_WITHDRAW
        },
        .cool = 30,
        .beauty = 35,
        .cute = 100,
        .smart = 40,
        .tough = 95,
        .sheen = 230,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KIARA] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_KANGASKHAN,
#if GERMAN
        .nickname = _("Amakan"),
        .trainerName = _("Paula"),
#else
        .nickname = _("KHANKAN"),
        .trainerName = _("KIARA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_3,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_MEGA_PUNCH,
            MOVE_RAGE,
            MOVE_FOCUS_PUNCH,
            MOVE_TAIL_WHIP
        },
        .cool = 100,
        .beauty = 50,
        .cute = 30,
        .smart = 50,
        .tough = 100,
        .sheen = 240,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_BRYCE] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_PINECO,
#if GERMAN
        .nickname = _("Zapfok"),
        .trainerName = _("Klaus"),
#else
        .nickname = _("PINOC"),
        .trainerName = _("BRYCE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BUG_CATCHER,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_EXPLOSION,
            MOVE_SPIKES,
            MOVE_LIGHT_SCREEN,
            MOVE_GIGA_DRAIN
        },
        .cool = 80,
        .beauty = 80,
        .cute = 80,
        .smart = 80,
        .tough = 80,
        .sheen = 250,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JAMIE] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_DUNSPARCE,
#if GERMAN
        .nickname = _("Manni"),
        .trainerName = _("Gerda"),
#else
        .nickname = _("DILTOT"),
        .trainerName = _("JAMIE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_5,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SPITE,
            MOVE_YAWN,
            MOVE_DEFENSE_CURL,
            MOVE_TAKE_DOWN
        },
        .cool = 40,
        .beauty = 35,
        .cute = 100,
        .smart = 40,
        .tough = 110,
        .sheen = 240,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JORGE] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_HOUNDOOM,
#if GERMAN
        .nickname = _("Deimelmon"),
        .trainerName = _("Hugo"),
#else
        .nickname = _("DOOMOND"),
        .trainerName = _("JORGE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GENTLEMAN,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ROAR,
            MOVE_FLAMETHROWER,
            MOVE_FEINT_ATTACK,
            MOVE_SUNNY_DAY
        },
        .cool = 100,
        .beauty = 100,
        .cute = 30,
        .smart = 25,
        .tough = 80,
        .sheen = 230,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_DEVON] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_MILTANK,
#if GERMAN
        .nickname = _("Milli"),
        .trainerName = _("David"),
#else
        .nickname = _("MILKAN"),
        .trainerName = _("DEVON"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_M,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MILK_DRINK,
            MOVE_HEAL_BELL,
            MOVE_DEFENSE_CURL,
            MOVE_BLIZZARD
        },
        .cool = 50,
        .beauty = 110,
        .cute = 100,
        .smart = 35,
        .tough = 40,
        .sheen = 220,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JUSTINA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_GYARADOS,
#if GERMAN
        .nickname = _("Garadi"),
        .trainerName = _("Jasmin"),
#else
        .nickname = _("RADOS"),
        .trainerName = _("JUSTINA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .aiFlags = CONTEST_AI_SET_1D,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_HYPER_BEAM,
            MOVE_HYDRO_PUMP,
            MOVE_RAIN_DANCE,
            MOVE_BITE
        },
        .cool = 160,
        .beauty = 200,
        .cute = 20,
        .smart = 40,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_RALPH] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_LOUDRED,
#if GERMAN
        .nickname = _("Krakeel"),
        .trainerName = _("Gert"),
#else
        .nickname = _("LOUDERD"),
        .trainerName = _("RALPH"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_M,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_HYPER_VOICE,
            MOVE_STOMP,
            MOVE_ROAR,
            MOVE_HOWL
        },
        .cool = 170,
        .beauty = 50,
        .cute = 55,
        .smart = 150,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_ROSA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SKITTY,
#if GERMAN
        .nickname = _("Necoco"),
        .trainerName = _("Rosa"),
#else
        .nickname = _("SITTY"),
        .trainerName = _("ROSA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ATTRACT,
            MOVE_ASSIST,
            MOVE_FEINT_ATTACK,
            MOVE_TAIL_WHIP
        },
        .cool = 40,
        .beauty = 200,
        .cute = 150,
        .smart = 185,
        .tough = 60,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KEATON] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SLAKING,
#if GERMAN
        .nickname = _("Assimax"),
        .trainerName = _("Kurt"),
#else
        .nickname = _("SLING"),
        .trainerName = _("KEATON"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_COVET,
            MOVE_COUNTER,
            MOVE_ENCORE,
            MOVE_SLACK_OFF
        },
        .cool = 85,
        .beauty = 85,
        .cute = 170,
        .smart = 110,
        .tough = 150,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MAYRA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_ALTARIA,
#if GERMAN
        .nickname = _("Ria"),
        .trainerName = _("Sonja"),
#else
        .nickname = _("TARIA"),
        .trainerName = _("MAYRA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_DRAGON_DANCE,
            MOVE_HYPER_BEAM,
            MOVE_PERISH_SONG,
            MOVE_SAFEGUARD
        },
        .cool = 170,
        .beauty = 150,
        .cute = 30,
        .smart = 30,
        .tough = 90,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_LAMAR] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_KIRLIA,
#if GERMAN
        .nickname = _("Kirojal"),
        .trainerName = _("Sönke"),
#else
        .nickname = _("LIRKI"),
        .trainerName = _("LAMAR"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_RICH_BOY,
        .aiFlags = CONTEST_AI_SET_1E,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SHOCK_WAVE,
            MOVE_SHADOW_BALL,
            MOVE_SKILL_SWAP,
            MOVE_RETURN
        },
        .cool = 230,
        .beauty = 60,
        .cute = 60,
        .smart = 230,
        .tough = 80,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_AUBREY] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_BELLOSSOM,
#if GERMAN
        .nickname = _("Bella"),
        .trainerName = _("Magda"),
#else
        .nickname = _("BLOSSOM"),
        .trainerName = _("AUBREY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_1F,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PETAL_DANCE,
            MOVE_SWEET_SCENT,
            MOVE_STUN_SPORE,
            MOVE_FLASH
        },
        .cool = 35,
        .beauty = 200,
        .cute = 150,
        .smart = 130,
        .tough = 40,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_NIGEL] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SABLEYE,
#if GERMAN
        .nickname = _("Irizo"),
        .trainerName = _("Sascha"),
#else
        .nickname = _("EYESAB"),
        .trainerName = _("NIGEL"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_MEAN_LOOK,
            MOVE_FEINT_ATTACK,
            MOVE_KNOCK_OFF,
            MOVE_CONFUSE_RAY
        },
        .cool = 25,
        .beauty = 35,
        .cute = 230,
        .smart = 150,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CAMILLE] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_NATU,
#if GERMAN
        .nickname = _("Tumani"),
        .trainerName = _("Mila"),
#else
        .nickname = _("UTAN"),
        .trainerName = _("CAMILLE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_20,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_NIGHT_SHADE,
            MOVE_FUTURE_SIGHT,
            MOVE_CONFUSE_RAY,
            MOVE_PSYCHIC
        },
        .cool = 35,
        .beauty = 35,
        .cute = 150,
        .smart = 130,
        .tough = 170,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_DEON] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_SHARPEDO,
#if GERMAN
        .nickname = _("Haitodo"),
        .trainerName = _("Knut"),
#else
        .nickname = _("PEDOS"),
        .trainerName = _("DEON"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_AGILITY,
            MOVE_SWAGGER,
            MOVE_TAUNT,
            MOVE_TAKE_DOWN
        },
        .cool = 140,
        .beauty = 70,
        .cute = 140,
        .smart = 75,
        .tough = 100,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JANELLE] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_LUVDISC,
#if GERMAN
        .nickname = _("Kusslieb"),
        .trainerName = _("Inca"),
#else
        .nickname = _("LUVIS"),
        .trainerName = _("JANELLE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SWEET_KISS,
            MOVE_ATTRACT,
            MOVE_TAKE_DOWN,
            MOVE_CHARM
        },
        .cool = 50,
        .beauty = 100,
        .cute = 220,
        .smart = 40,
        .tough = 190,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_HEATH] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_HERACROSS,
#if GERMAN
        .nickname = _("Skarab"),
        .trainerName = _("Felix"),
#else
        .nickname = _("HEROSS"),
        .trainerName = _("HEATH"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_STRENGTH,
            MOVE_ENDURE,
            MOVE_REVERSAL,
            MOVE_ROCK_TOMB
        },
        .cool = 170,
        .beauty = 70,
        .cute = 110,
        .smart = 240,
        .tough = 140,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SASHA] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_ELECTRODE,
#if GERMAN
        .nickname = _("Lekbal"),
        .trainerName = _("Debora"),
#else
        .nickname = _("RODLECT"),
        .trainerName = _("SASHA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_EXPLOSION,
            MOVE_LIGHT_SCREEN,
            MOVE_SWIFT,
            MOVE_FLASH
        },
        .cool = 200,
        .beauty = 200,
        .cute = 30,
        .smart = 35,
        .tough = 50,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_FRANKIE] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_PICHU,
#if GERMAN
        .nickname = _("Deibel"),
        .trainerName = _("Boris"),
#else
        .nickname = _("CHUPY"),
        .trainerName = _("FRANKIE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_21,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SWEET_KISS,
            MOVE_ATTRACT,
            MOVE_REST,
            MOVE_TAIL_WHIP
        },
        .cool = 25,
        .beauty = 150,
        .cute = 180,
        .smart = 115,
        .tough = 120,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_HELEN] = {
        .filter = CONTEST_FILTER_NONE,
        .species = SPECIES_WOBBUFFET,
#if GERMAN
        .nickname = _("Wohingenau"),
        .trainerName = _("Delia"),
#else
        .nickname = _("WOBET"),
        .trainerName = _("HELEN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_COUNTER,
            MOVE_MIRROR_COAT,
            MOVE_SAFEGUARD,
            MOVE_DESTINY_BOND
        },
        .cool = 60,
        .beauty = 230,
        .cute = 50,
        .smart = 220,
        .tough = 210,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CAMILE] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_GENGAR,
#if GERMAN
        .nickname = _("Garok"),
        .trainerName = _("Helga"),
#else
        .nickname = _("GAREN"),
        .trainerName = _("CAMILE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_HEX_MANIAC,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_DESTINY_BOND,
            MOVE_CONFUSE_RAY,
            MOVE_LICK,
            MOVE_SLUDGE_BOMB
        },
        .cool = 200,
        .beauty = 100,
        .cute = 50,
        .smart = 80,
        .tough = 180,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_MARTIN] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_PORYGON,
#if GERMAN
        .nickname = _("Poly"),
        .trainerName = _("Max"),
#else
        .nickname = _("GONPOR"),
        .trainerName = _("MARTIN"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SCIENTIST_1,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_CONVERSION_2,
            MOVE_CONVERSION,
            MOVE_RETURN,
            MOVE_RECYCLE
        },
        .cool = 130,
        .beauty = 130,
        .cute = 130,
        .smart = 130,
        .tough = 130,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_SERGIO] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_DRAGONITE,
#if GERMAN
        .nickname = _("Dragan"),
        .trainerName = _("Silvio"),
#else
        .nickname = _("DRITE"),
        .trainerName = _("SERGIO"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BOY_1,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_OUTRAGE,
            MOVE_SLAM,
            MOVE_TWISTER,
            MOVE_EARTHQUAKE
        },
        .cool = 150,
        .beauty = 140,
        .cute = 50,
        .smart = 120,
        .tough = 150,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_KAILEY] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_MEOWTH,
#if GERMAN
        .nickname = _("Miauzi"),
        .trainerName = _("Karla"),
#else
        .nickname = _("MEOWY"),
        .trainerName = _("KAILEY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWL,
            MOVE_TAUNT,
            MOVE_PAY_DAY,
            MOVE_BITE
        },
        .cool = 125,
        .beauty = 110,
        .cute = 180,
        .smart = 170,
        .tough = 80,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_PERLA] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_JYNX,
#if GERMAN
        .nickname = _("Rossa"),
        .trainerName = _("Pamela"),
#else
        .nickname = _("NYX"),
        .trainerName = _("PERLA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BEAUTY,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PERISH_SONG,
            MOVE_MEAN_LOOK,
            MOVE_LOVELY_KISS,
            MOVE_FAKE_TEARS
        },
        .cool = 100,
        .beauty = 150,
        .cute = 100,
        .smart = 150,
        .tough = 120,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_CLARA] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_TOGEPI,
#if GERMAN
        .nickname = _("Epigo"),
        .trainerName = _("Hanna"),
#else
        .nickname = _("GEPITO"),
        .trainerName = _("CLARA"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWL,
            MOVE_YAWN,
            MOVE_ENCORE,
            MOVE_FOLLOW_ME
        },
        .cool = 80,
        .beauty = 120,
        .cute = 200,
        .smart = 120,
        .tough = 80,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_JAKOB] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_ESPEON,
#if GERMAN
        .nickname = _("Psysy"),
        .trainerName = _("Julius"),
#else
        .nickname = _("SPEON"),
        .trainerName = _("JAKOB"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_PSYCHIC_M,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SWIFT,
            MOVE_QUICK_ATTACK,
            MOVE_MORNING_SUN,
            MOVE_TAIL_WHIP
        },
        .cool = 180,
        .beauty = 150,
        .cute = 100,
        .smart = 80,
        .tough = 150,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_TREY] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_SLOWKING,
#if GERMAN
        .nickname = _("Lethargo"),
        .trainerName = _("Ansgar"),
#else
        .nickname = _("SLOWGO"),
        .trainerName = _("TREY"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_SAILOR,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_FACADE,
            MOVE_CURSE,
            MOVE_YAWN,
            MOVE_FOCUS_PUNCH
        },
        .cool = 100,
        .beauty = 80,
        .cute = 200,
        .smart = 110,
        .tough = 170,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    },
    [CONTEST_OPPONENT_LANE] = {
        .filter = CONTEST_FILTER_ONLY_POSTGAME,
        .species = SPECIES_URSARING,
#if GERMAN
        .nickname = _("Ringo"),
        .trainerName = _("Lane"),
#else
        .nickname = _("URSING"),
        .trainerName = _("LANE"),
#endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_THRASH,
            MOVE_AERIAL_ACE,
            MOVE_FAKE_TEARS,
            MOVE_LEER
        },
        .cool = 180,
        .beauty = 140,
        .cute = 30,
        .smart = 80,
        .tough = 190,
        .sheen = 255,
        .personality = 0,
        .otId = CONTEST_AI_TRAINER_ID,
    }
};
