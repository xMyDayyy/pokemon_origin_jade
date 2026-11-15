#include "easy_chat.h"

#include "easy_chat_group_pokemon.h"
#include "easy_chat_group_trainer.h"
#include "easy_chat_group_status.h"
#include "easy_chat_group_battle.h"
#include "easy_chat_group_greetings.h"
#include "easy_chat_group_people.h"
#include "easy_chat_group_voices.h"
#include "easy_chat_group_speech.h"
#include "easy_chat_group_endings.h"
#include "easy_chat_group_feelings.h"
#include "easy_chat_group_conditions.h"
#include "easy_chat_group_actions.h"
#include "easy_chat_group_lifestyle.h"
#include "easy_chat_group_hobbies.h"
#include "easy_chat_group_time.h"
#include "easy_chat_group_misc.h"
#include "easy_chat_group_adjectives.h"
#include "easy_chat_group_events.h"
#include "easy_chat_group_move_1.h"
#include "easy_chat_group_move_2.h"
#include "easy_chat_group_trendy_saying.h"
#include "easy_chat_group_pokemon2.h"

const struct EasyChatGroup gEasyChatGroups[EC_NUM_GROUPS] = {
    [EC_GROUP_POKEMON] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pokémon"),
#else
        .name = COMPOUND_STRING("POKéMON"),
#endif
        .wordData = {.valueList = gEasyChatGroup_Pokemon},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Pokemon),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Pokemon),
    },
    [EC_GROUP_TRAINER] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Trainer"),
#else
        .name = COMPOUND_STRING("TRAINER"),
#endif
        .wordData = {.words = gEasyChatGroup_Trainer},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Trainer),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Trainer) - 6, // Excludes Red, Green, Flame, Gold, Leaf, and Silver
    },
    [EC_GROUP_STATUS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Status"),
#else
        .name = COMPOUND_STRING("STATUS"),
#endif
        .wordData = {.words = gEasyChatGroup_Status},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Status),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Status),
    },
    [EC_GROUP_BATTLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Kampf"),
#else
        .name = COMPOUND_STRING("BATTLE"),
#endif
        .wordData = {.words = gEasyChatGroup_Battle},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Battle),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Battle),
    },
    [EC_GROUP_GREETINGS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Empfang"),
#else
        .name = COMPOUND_STRING("GREETINGS"),
#endif
        .wordData = {.words = gEasyChatGroup_Greetings},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Greetings),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Greetings),
    },
    [EC_GROUP_PEOPLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Personen"),
#else
        .name = COMPOUND_STRING("PEOPLE"),
#endif
        .wordData = {.words = gEasyChatGroup_People},
        .numWords = ARRAY_COUNT(gEasyChatGroup_People),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_People),
    },
    [EC_GROUP_VOICES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Ausrufe"),
#else
        .name = COMPOUND_STRING("VOICES"),
#endif
        .wordData = {.words = gEasyChatGroup_Voices},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Voices),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Voices),
    },
    [EC_GROUP_SPEECH] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Stilmittel"),
#else
        .name = COMPOUND_STRING("SPEECH"),
#endif
        .wordData = {.words = gEasyChatGroup_Speech},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Speech),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Speech),
    },
    [EC_GROUP_ENDINGS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Verknüpfung"),
#else
        .name = COMPOUND_STRING("ENDINGS"),
#endif
        .wordData = {.words = gEasyChatGroup_Endings},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Endings),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Endings),
    },
    [EC_GROUP_FEELINGS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Gefühle"),
#else
        .name = COMPOUND_STRING("FEELINGS"),
#endif
        .wordData = {.words = gEasyChatGroup_Feelings},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Feelings),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Feelings),
    },
    [EC_GROUP_CONDITIONS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Konditionen"),
#else
        .name = COMPOUND_STRING("CONDITIONS"),
#endif
        .wordData = {.words = gEasyChatGroup_Conditions},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Conditions),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Conditions),
    },
    [EC_GROUP_ACTIONS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Aktionen"),
#else
        .name = COMPOUND_STRING("ACTIONS"),
#endif
        .wordData = {.words = gEasyChatGroup_Actions},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Actions),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Actions),
    },
    [EC_GROUP_LIFESTYLE] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Lifestyle"),
#else
        .name = COMPOUND_STRING("LIFESTYLE"),
#endif
        .wordData = {.words = gEasyChatGroup_Lifestyle},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Lifestyle),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Lifestyle),
    },
    [EC_GROUP_HOBBIES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hobbies"),
#else
        .name = COMPOUND_STRING("HOBBIES"),
#endif
        .wordData = {.words = gEasyChatGroup_Hobbies},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Hobbies),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Hobbies),
    },
    [EC_GROUP_TIME] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Zeit"),
#else
        .name = COMPOUND_STRING("TIME"),
#endif
        .wordData = {.words = gEasyChatGroup_Time},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Time),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Time),
    },
    [EC_GROUP_MISC] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Positionen"),
#else
        .name = COMPOUND_STRING("MISC."),
#endif
        .wordData = {.words = gEasyChatGroup_Misc},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Misc),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Misc),
    },
    [EC_GROUP_ADJECTIVES] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Geräusche"),
#else
        .name = COMPOUND_STRING("ADJECTIVES"),
#endif
        .wordData = {.words = gEasyChatGroup_Adjectives},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Adjectives),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Adjectives),
    },
    [EC_GROUP_EVENTS] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Mischmasch"),
#else
        .name = COMPOUND_STRING("EVENTS"),
#endif
        .wordData = {.words = gEasyChatGroup_Events},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Events),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Events),
    },
    [EC_GROUP_MOVE_1] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Attacken 1"),
#else
        .name = COMPOUND_STRING("MOVE 1"),
#endif
        .wordData = {.valueList = gEasyChatGroup_Move1},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Move1),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Move1),
    },
    [EC_GROUP_MOVE_2] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Attacken 2"),
#else
        .name = COMPOUND_STRING("MOVE 2"),
#endif
        .wordData = {.valueList = gEasyChatGroup_Move2},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Move2),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Move2),
    },
    [EC_GROUP_TRENDY_SAYING] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Hipper Spruch"),
#else
        .name = COMPOUND_STRING("TRENDY SAYING"),
#endif
        .wordData = {.words = gEasyChatGroup_TrendySaying},
        .numWords = ARRAY_COUNT(gEasyChatGroup_TrendySaying),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_TrendySaying),
    },
    [EC_GROUP_POKEMON_NATIONAL] =
    {
#if GERMAN
        .name = COMPOUND_STRING("Pokémon 2"),
#else
        .name = COMPOUND_STRING("POKéMON2"),
#endif
        .wordData = {.valueList = gEasyChatGroup_Pokemon2},
        .numWords = ARRAY_COUNT(gEasyChatGroup_Pokemon2),
        .numEnabledWords = ARRAY_COUNT(gEasyChatGroup_Pokemon2),
    },
};
