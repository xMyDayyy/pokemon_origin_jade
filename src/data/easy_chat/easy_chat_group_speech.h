const struct EasyChatWordInfo gEasyChatGroup_Speech[] = {
    [EC_INDEX(EC_WORD_LISTEN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zuhören"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUT),
#else
        .text = COMPOUND_STRING("LISTEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_LITTLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOT_VERY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nicht sehr"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS_IF),
#else
        .text = COMPOUND_STRING("NOT VERY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_LOT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEAN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gemein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALSO),
#else
        .text = COMPOUND_STRING("MEAN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_TINY_BIT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lügen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_READY),
#else
        .text = COMPOUND_STRING("LIE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABSOLUTELY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gelogen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNTIL),
#else
        .text = COMPOUND_STRING("LAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALSO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RECOMMEND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Empfohlen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NITWIT),
#else
        .text = COMPOUND_STRING("RECOMMEND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALTHOUGH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NITWIT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Blödkopf"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JUST),
#else
        .text = COMPOUND_STRING("NITWIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUITE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wirklich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISS),
#else
        .text = COMPOUND_STRING("QUITE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FROM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Von"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MODE),
#else
        .text = COMPOUND_STRING("FROM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AROUND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEELING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fühlen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THE),
#else
        .text = COMPOUND_STRING("FEELING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS_IF),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BUT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Aber"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABSOLUTELY),
#else
        .text = COMPOUND_STRING("BUT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS_MUCH_AS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOWEVER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Jedoch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RATHER),
#else
        .text = COMPOUND_STRING("HOWEVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWFULLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CASE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fall"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REALLY),
#else
        .text = COMPOUND_STRING("CASE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Der"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_LITTLE),
#else
        .text = COMPOUND_STRING("THE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CASE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Daneben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RECOMMEND),
#else
        .text = COMPOUND_STRING("MISS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENOUGH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Genau wie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FINALLY),
#else
        .text = COMPOUND_STRING("HOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVEN_SO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Treffer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERIOUSLY),
#else
        .text = COMPOUND_STRING("HIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FANTASTIC),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENOUGH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Reicht aus"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AROUND),
#else
        .text = COMPOUND_STRING("ENOUGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEELING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A_LOT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Viel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMETHING),
#else
        .text = COMPOUND_STRING("A LOT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FINALLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A_LITTLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ein bisschen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PROBABLY),
#else
        .text = COMPOUND_STRING("A LITTLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOR_NOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABSOLUTELY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Die"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CASE),
#else
        .text = COMPOUND_STRING("ABSOLUTELY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FROM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Und"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FANTASTIC),
#else
        .text = COMPOUND_STRING("AND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ONLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nur"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEELING),
#else
        .text = COMPOUND_STRING("ONLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AROUND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Etwa"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOR_NOW),
#else
        .text = COMPOUND_STRING("AROUND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOWEVER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PROBABLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Eventuell"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWFULLY),
#else
        .text = COMPOUND_STRING("PROBABLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IF),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IF)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wenn"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LAY),
#else
        .text = COMPOUND_STRING("IF"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSTEAD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sehr"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEAN),
#else
        .text = COMPOUND_STRING("VERY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JOKING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A_TINY_BIT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wenig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOW),
#else
        .text = COMPOUND_STRING("A TINY BIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JUST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WILD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wild"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANY),
#else
        .text = COMPOUND_STRING("WILD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_S)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Noch mal"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMEHOW),
#else
        .text = COMPOUND_STRING("THAT'S"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JUST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bloß"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOWEVER),
#else
        .text = COMPOUND_STRING("JUST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTEN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVEN_SO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Trotzdem"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOOD),
#else
        .text = COMPOUND_STRING("EVEN SO,"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEAN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUST_BE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Muss"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIE),
#else
        .text = COMPOUND_STRING("MUST BE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURALLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verständlich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MORE),
#else
        .text = COMPOUND_STRING("NATURALLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MODE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOR_NOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Für nun"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUST_BE),
#else
        .text = COMPOUND_STRING("FOR NOW,"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOOD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNDERSTOOD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verstanden"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOT_VERY),
#else
        .text = COMPOUND_STRING("UNDERSTOOD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MORE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JOKING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Scherzen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOTALLY),
#else
        .text = COMPOUND_STRING("JOKING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUST_BE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_READY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bereit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_S),
#else
        .text = COMPOUND_STRING("READY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURALLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMETHING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Etwas"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ONLY),
#else
        .text = COMPOUND_STRING("SOMETHING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NITWIT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMEHOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Irgendwie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALTHOUGH),
#else
        .text = COMPOUND_STRING("SOMEHOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOT_VERY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALTHOUGH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Obwohl"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERFECT),
#else
        .text = COMPOUND_STRING("ALTHOUGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ONLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALSO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Also"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENOUGH),
#else
        .text = COMPOUND_STRING("ALSO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERFECT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERFECT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Perfekt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JOKING),
#else
        .text = COMPOUND_STRING("PERFECT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PROBABLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AS_MUCH_AS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("So viel wie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERY),
#else
        .text = COMPOUND_STRING("AS MUCH AS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUITE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REALLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ehrlich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS_MUCH_AS),
#else
        .text = COMPOUND_STRING("REALLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RATHER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRULY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wahrhaftig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSTEAD),
#else
        .text = COMPOUND_STRING("TRULY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_READY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERIOUSLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ernst"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIT),
#else
        .text = COMPOUND_STRING("SERIOUSLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REALLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOTALLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Noch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVEN_SO),
#else
        .text = COMPOUND_STRING("TOTALLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RECOMMEND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNTIL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bis"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AND),
#else
        .text = COMPOUND_STRING("UNTIL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERIOUSLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AS_IF)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Als ob"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNDERSTOOD),
#else
        .text = COMPOUND_STRING("AS IF"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMEHOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOOD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Laune"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURALLY),
#else
        .text = COMPOUND_STRING("MOOD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMETHING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RATHER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Eher"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_LOT),
#else
        .text = COMPOUND_STRING("RATHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_S),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWFULLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Furchtbar"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FROM),
#else
        .text = COMPOUND_STRING("AWFULLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MODE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Denke"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRULY),
#else
        .text = COMPOUND_STRING("MODE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO_LATE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MORE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mehr"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_A_TINY_BIT),
#else
        .text = COMPOUND_STRING("MORE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOTALLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO_LATE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zu spät"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IF),
#else
        .text = COMPOUND_STRING("TOO LATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRULY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FINALLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Endlich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WILD),
#else
        .text = COMPOUND_STRING("FINALLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNDERSTOOD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Irgendein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUITE),
#else
        .text = COMPOUND_STRING("ANY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNTIL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSTEAD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Statt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO_LATE),
#else
        .text = COMPOUND_STRING("INSTEAD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FANTASTIC)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fantastisch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTEN),
#else
        .text = COMPOUND_STRING("FANTASTIC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WILD),
#endif
        .enabled = TRUE,
    },
};
