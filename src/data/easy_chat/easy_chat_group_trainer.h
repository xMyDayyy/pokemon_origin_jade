const struct EasyChatWordInfo gEasyChatGroup_Trainer[] = {
    [EC_INDEX(EC_WORD_I_CHOOSE_YOU)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Du bist dran"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GET),
#else
        .text = COMPOUND_STRING("I CHOOSE YOU"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BAG),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOTCHA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hab dich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BAG),
#else
        .text = COMPOUND_STRING("GOTCHA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CENTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRADE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tausch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEAF),
#else
        .text = COMPOUND_STRING("TRADE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EGG),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAPPHIRE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Saphir"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CENTER),
#else
        .text = COMPOUND_STRING("SAPPHIRE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EMERALD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Entwickeln"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_CHOOSE_YOU),
#else
        .text = COMPOUND_STRING("EVOLVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENCYCLOPEDIA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENCYCLOPEDIA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Enzyklopädie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EGG),
#else
        .text = COMPOUND_STRING("ENCYCLOPEDIA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVOLVE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wesen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVOLVE),
#else
        .text = COMPOUND_STRING("NATURE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLAME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CENTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Center"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENCYCLOPEDIA),
#else
        .text = COMPOUND_STRING("CENTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GET),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EGG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ei"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SP_ABILITY),
#else
        .text = COMPOUND_STRING("EGG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOLD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LINK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Link"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLAME),
#else
        .text = COMPOUND_STRING("LINK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOTCHA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SP_ABILITY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fähigkeit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOLD),
#else
        .text = COMPOUND_STRING("SP. ABILITY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GREEN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAINER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Trainer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GREEN),
#else
        .text = COMPOUND_STRING("TRAINER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_CHOOSE_YOU),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERSION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Version"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOTCHA),
#else
        .text = COMPOUND_STRING("VERSION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEAF),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKENAV)] =
    {
#if IS_HNS
#if GERMAN
        .text = COMPOUND_STRING("PokéCom"),
#else
        .text = COMPOUND_STRING("POKéGEAR"),
#endif
#else
#if GERMAN
        .text = COMPOUND_STRING("Pokénav"),
#else
        .text = COMPOUND_STRING("POKéNAV"),
#endif
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEVEL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEMON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Pokémon"),
#else
        .text = COMPOUND_STRING("POKéMON"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_LINK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GET)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bekommen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEDEX),
#else
        .text = COMPOUND_STRING("GET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEDEX)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Pokédex"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEMON),
#else
        .text = COMPOUND_STRING("POKéDEX"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEDEX),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUBY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rubin"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKENAV),
#else
        .text = COMPOUND_STRING("RUBY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEMON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEVEL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Level"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RED),
#else
        .text = COMPOUND_STRING("LEVEL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKENAV),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rot"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUBY),
#else
        .text = COMPOUND_STRING("RED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RED),
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GREEN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Grün"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAPPHIRE),
#else
        .text = COMPOUND_STRING("GREEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUBY),
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_BAG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Beutel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SILVER),
#else
        .text = COMPOUND_STRING("BAG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAPPHIRE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLAME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Flamme"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EMERALD),
#else
        .text = COMPOUND_STRING("FLAME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SILVER),
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GOLD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gold"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRADE),
#else
        .text = COMPOUND_STRING("GOLD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SP_ABILITY),
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_LEAF)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Blatt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAINER),
#else
        .text = COMPOUND_STRING("LEAF"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRADE),
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_SILVER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Silber"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERSION),
#else
        .text = COMPOUND_STRING("SILVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAINER),
#endif
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_EMERALD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Smaragd"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURE),
#else
        .text = COMPOUND_STRING("EMERALD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERSION),
#endif
        .enabled = TRUE,
    },
};
