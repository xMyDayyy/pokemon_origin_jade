const struct EasyChatWordInfo gEasyChatGroup_TrendySaying[] = {
    [EC_INDEX(EC_WORD_KTHX_BYE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vokuhila"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UGLY),
#else
        .text = COMPOUND_STRING("KTHX, BYE."),
        .alphabeticalOrder = EC_INDEX(EC_WORD_1_HIT_KO_EXCL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YES_SIR_EXCL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Aye, aye!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HASSLE),
#else
        .text = COMPOUND_STRING("YES, SIR!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AVANT_GARDE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AVANT_GARDE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Avantgarde"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AVANT_GARDE),
#else
        .text = COMPOUND_STRING("AVANT GARDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BABY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COUPLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Yuppies"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YES_SIR_EXCL),
#else
        .text = COMPOUND_STRING("COUPLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BANG),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH_OBLIGED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ihr diener!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BABY),
#else
        .text = COMPOUND_STRING("MUCH OBLIGED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CANCEL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEEHAW_EXCL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Jiihaah"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHAKE),
#else
        .text = COMPOUND_STRING("YEEHAW!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COUPLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEGA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mega"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPBEAT),
#else
        .text = COMPOUND_STRING("MEGA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESTINY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_1_HIT_KO_EXCL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gummipunkt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLATTEN),
#else
        .text = COMPOUND_STRING("1-HIT KO!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEVER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESTINY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Karma"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANNABE),
#else
        .text = COMPOUND_STRING("DESTINY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLATTEN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CANCEL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ndw"),
#else
        .text = COMPOUND_STRING("CANCEL"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPENING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Popper"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_1_HIT_KO_EXCL),
#else
        .text = COMPOUND_STRING("NEW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HASSLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLATTEN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Erdbeertee"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIP_AND),
#else
        .text = COMPOUND_STRING("FLATTEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEART),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIDDING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schofel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEART),
#else
        .text = COMPOUND_STRING("KIDDING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIP_AND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Loser"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH_OBLIGED),
#else
        .text = COMPOUND_STRING("LOSER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIDDING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zoff"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEEHAW_EXCL),
#else
        .text = COMPOUND_STRING("LOSING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOCKOUT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPENING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gimmick"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOUNG),
#else
        .text = COMPOUND_STRING("HAPPENING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KTHX_BYE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIP_AND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hip und"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESTINY),
#else
        .text = COMPOUND_STRING("HIP AND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHAKE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bananenshake"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEVER),
#else
        .text = COMPOUND_STRING("SHAKE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHADY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rock’n’roll"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WINNER),
#else
        .text = COMPOUND_STRING("SHADY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEGA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPBEAT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Dufte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOCKOUT),
#else
        .text = COMPOUND_STRING("UPBEAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MODERN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MODERN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Modern"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSER),
#else
        .text = COMPOUND_STRING("MODERN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH_OBLIGED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMELL_YA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rübennase"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEGA),
#else
        .text = COMPOUND_STRING("SMELL YA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BANG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Stulpen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MODERN),
#else
        .text = COMPOUND_STRING("BANG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OLD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOCKOUT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Licht aus..."),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CANCEL),
#else
        .text = COMPOUND_STRING("KNOCKOUT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHADY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HASSLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Aufstand"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OLD),
#else
        .text = COMPOUND_STRING("HASSLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHAKE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WINNER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Leuchtkeks"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEW),
#else
        .text = COMPOUND_STRING("WINNER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMELL_YA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEVER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Körperhitze"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHADY),
#else
        .text = COMPOUND_STRING("FEVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UGLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANNABE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gernegroß"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMELL_YA),
#else
        .text = COMPOUND_STRING("WANNABE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPBEAT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BABY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Baby"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIDDING),
#else
        .text = COMPOUND_STRING("BABY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANNABE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEART)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Holde"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BANG),
#else
        .text = COMPOUND_STRING("HEART"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WINNER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OLD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Oll"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KTHX_BYE),
#else
        .text = COMPOUND_STRING("OLD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEEHAW_EXCL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOUNG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Jung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COUPLE),
#else
        .text = COMPOUND_STRING("YOUNG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YES_SIR_EXCL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UGLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ätzend"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSING),
#else
        .text = COMPOUND_STRING("UGLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOUNG),
#endif
        .enabled = TRUE,
    },
};
