const struct EasyChatWordInfo gEasyChatGroup_Greetings[] = {
    [EC_INDEX(EC_WORD_THANKS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Dank"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME_OVER),
#else
        .text = COMPOUND_STRING("THANKS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APOLOGIZE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ja"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OI),
#else
        .text = COMPOUND_STRING("YES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPRECIATE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_GOES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hier kommt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEET_YOU),
#else
        .text = COMPOUND_STRING("HERE GOES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BYE_BYE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_I_COME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hier bin ich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEE_YA),
#else
        .text = COMPOUND_STRING("HERE I COME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME_OVER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_IT_IS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hier ist es"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THANKS),
#else
        .text = COMPOUND_STRING("HERE IT IS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONGRATS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEAH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Yeah"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THANK_YOU),
#else
        .text = COMPOUND_STRING("YEAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COUNT_ON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELCOME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Willkommen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCUSE_ME),
#else
        .text = COMPOUND_STRING("WELCOME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCUSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OI)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Au"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMELL),
#else
        .text = COMPOUND_STRING("OI"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCUSE_ME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOW_DO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE_ME),
#else
        .text = COMPOUND_STRING("HOW DO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGIVE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONGRATS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Glückwunsch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONGRATS),
#else
        .text = COMPOUND_STRING("CONGRATS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE_ME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE_ME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gib"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HELLO),
#else
        .text = COMPOUND_STRING("GIVE ME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO_AHEAD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SORRY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sorry"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY),
#else
        .text = COMPOUND_STRING("SORRY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOOD_BYE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APOLOGIZE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verzeihung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY_THERE),
#else
        .text = COMPOUND_STRING("APOLOGIZE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HELLO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGIVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schon gut"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY_QUES),
#else
        .text = COMPOUND_STRING("FORGIVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE_GOES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY_THERE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hey da"),
#else
        .text = COMPOUND_STRING("HEY, THERE"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE_I_COME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HELLO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hallo"),
#else
        .text = COMPOUND_STRING("HELLO"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE_IT_IS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD_BYE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tschüss"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE_GOES),
#else
        .text = COMPOUND_STRING("GOOD-BYE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THANK_YOU)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Danke schön"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTENING),
#else
        .text = COMPOUND_STRING("THANK YOU"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY_THERE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_VE_ARRIVED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ich bin da"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOO_HAH),
#else
        .text = COMPOUND_STRING("I'VE ARRIVED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY_QUES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARDON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Pardon"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_VE_ARRIVED),
#else
        .text = COMPOUND_STRING("PARDON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HI),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCUSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tagchen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YES),
#else
        .text = COMPOUND_STRING("EXCUSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOO_HAH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEE_YA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bis dann"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YO),
#else
        .text = COMPOUND_STRING("SEE YA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOW_DO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCUSE_ME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Entschuldige"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YAHOO),
#else
        .text = COMPOUND_STRING("EXCUSE ME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUH_QUES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL_THEN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nun, dann"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NO),
#else
        .text = COMPOUND_STRING("WELL, THEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_VE_ARRIVED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_AHEAD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Weiter so"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELL_THEN),
#else
        .text = COMPOUND_STRING("GO AHEAD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTENING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPRECIATE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schätzen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARDON),
#else
        .text = COMPOUND_STRING("APPRECIATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEET_YOU),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY_QUES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hey?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPRECIATE),
#else
        .text = COMPOUND_STRING("HEY?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT_S_UP_QUES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Was ist los?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGIVE),
#else
        .text = COMPOUND_STRING("WHAT'S UP?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OI),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUH_QUES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wie?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SORRY),
#else
        .text = COMPOUND_STRING("HUH?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARDON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HI),
#else
        .text = COMPOUND_STRING("NO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEE_YA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HI)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tag auch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCUSE),
#else
        .text = COMPOUND_STRING("HI"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMELL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEAH_YEAH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Yeah, yeah"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BYE_BYE),
#else
        .text = COMPOUND_STRING("YEAH, YEAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SORRY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BYE_BYE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tschau"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOOD_BYE),
#else
        .text = COMPOUND_STRING("BYE-BYE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THANK_YOU),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEET_YOU)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bis bald"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APOLOGIZE),
#else
        .text = COMPOUND_STRING("MEET YOU"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THANKS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hey"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHAT_S_UP_QUES),
#else
        .text = COMPOUND_STRING("HEY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELCOME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMELL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geruch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO_AHEAD),
#else
        .text = COMPOUND_STRING("SMELL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELL_THEN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LISTENING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hör zu"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOW_DO),
#else
        .text = COMPOUND_STRING("LISTENING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHAT_S_UP_QUES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOO_HAH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Huh hah"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUH_QUES),
#else
        .text = COMPOUND_STRING("HOO-HAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YAHOO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YAHOO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Juchuu"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELCOME),
#else
        .text = COMPOUND_STRING("YAHOO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEAH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Jepp"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEAH),
#else
        .text = COMPOUND_STRING("YO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEAH_YEAH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME_OVER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ach, komm"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEAH_YEAH),
#else
        .text = COMPOUND_STRING("COME OVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COUNT_ON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zählen auf"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COUNT_ON),
#else
        .text = COMPOUND_STRING("COUNT ON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YO),
#endif
        .enabled = TRUE,
    },
};
