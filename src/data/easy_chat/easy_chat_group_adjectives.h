const struct EasyChatWordInfo gEasyChatGroup_Adjectives[] = {
    [EC_INDEX(EC_WORD_WANDERING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Latsch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIMPY),
#else
        .text = COMPOUND_STRING("WANDERING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANTICIPATION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RICKETY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wackel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHREDDED),
#else
        .text = COMPOUND_STRING("RICKETY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWESOME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROCK_SOLID)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Steinhart"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMOOTH),
#else
        .text = COMPOUND_STRING("ROCK-SOLID"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BREAK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUNGRY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Magenknurr"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLIMY),
#else
        .text = COMPOUND_STRING("HUNGRY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESTROYED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIGHT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Knurschp"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANTICIPATION),
#else
        .text = COMPOUND_STRING("TIGHT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DROOLING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TICKLISH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kille kille"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWESOME),
#else
        .text = COMPOUND_STRING("TICKLISH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCITING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TWIRLING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schleuder"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCITING),
#else
        .text = COMPOUND_STRING("TWIRLING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIERY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPIRALING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wirbel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TICKLISH),
#else
        .text = COMPOUND_STRING("SPIRALING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPILY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIRSTY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lechz"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIN),
#else
        .text = COMPOUND_STRING("THIRSTY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOPELESS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOLLING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lümmel räkel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIGHT),
#else
        .text = COMPOUND_STRING("LOLLING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUNGRY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SILKY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wuschel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANDERING),
#else
        .text = COMPOUND_STRING("SILKY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INCREASING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SADLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schnüff"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIRSTY),
#else
        .text = COMPOUND_STRING("SADLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOLLING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOPELESS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ooch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOLLING),
#else
        .text = COMPOUND_STRING("HOPELESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOVEY_DOVEY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USELESS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Müll"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUNGRY),
#else
        .text = COMPOUND_STRING("USELESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RICKETY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DROOLING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sabber"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VORACIOUS),
#else
        .text = COMPOUND_STRING("DROOLING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIPPED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCITING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Jipp! jipp!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPILY),
#else
        .text = COMPOUND_STRING("EXCITING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROCK_SOLID),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THICK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schwabbel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_USELESS),
#else
        .text = COMPOUND_STRING("THICK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SADLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMOOTH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Glatt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YET),
#else
        .text = COMPOUND_STRING("SMOOTH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCATTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLIMY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Glibber"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOPELESS),
#else
        .text = COMPOUND_STRING("SLIMY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHAKY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Klapper"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIPPED),
#else
        .text = COMPOUND_STRING("THIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHREDDED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BREAK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schepper"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESTROYED),
#else
        .text = COMPOUND_STRING("BREAK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SILKY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VORACIOUS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mampf fress"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DROOLING),
#else
        .text = COMPOUND_STRING("VORACIOUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLIMY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCATTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schmeiß"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BREAK),
#else
        .text = COMPOUND_STRING("SCATTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMOOTH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWESOME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Irre"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TWIRLING),
#else
        .text = COMPOUND_STRING("AWESOME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPIRALING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIMPY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Angst bibber"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCATTER),
#else
        .text = COMPOUND_STRING("WIMPY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THICK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOBBLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zitter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOVEY_DOVEY),
#else
        .text = COMPOUND_STRING("WOBBLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHAKY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schüttel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SADLY),
#else
        .text = COMPOUND_STRING("SHAKY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIRSTY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIPPED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ratsch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHAKY),
#else
        .text = COMPOUND_STRING("RIPPED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TICKLISH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHREDDED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fetz"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THICK),
#else
        .text = COMPOUND_STRING("SHREDDED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIGHT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INCREASING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wurgs"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROCK_SOLID),
#else
        .text = COMPOUND_STRING("INCREASING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TWIRLING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YET)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nööö"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RICKETY),
#else
        .text = COMPOUND_STRING("YET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_USELESS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESTROYED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rumms berst"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPIRALING),
#else
        .text = COMPOUND_STRING("DESTROYED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VORACIOUS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIERY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zisch fackel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INCREASING),
#else
        .text = COMPOUND_STRING("FIERY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANDERING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOVEY_DOVEY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schnuckelig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SILKY),
#else
        .text = COMPOUND_STRING("LOVEY-DOVEY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIMPY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPILY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Megagrins"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIERY),
#else
        .text = COMPOUND_STRING("HAPPILY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOBBLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANTICIPATION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Grins hoff"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOBBLY),
#else
        .text = COMPOUND_STRING("ANTICIPATION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YET),
#endif
        .enabled = TRUE,
    },
};
