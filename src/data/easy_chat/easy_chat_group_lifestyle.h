const struct EasyChatWordInfo gEasyChatGroup_Lifestyle[] = {
    [EC_INDEX(EC_WORD_CHORES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Pflichten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORK),
#else
        .text = COMPOUND_STRING("CHORES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLOWANCE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Heim"),
#else
        .text = COMPOUND_STRING("HOME"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MONEY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geld"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LETTER),
#else
        .text = COMPOUND_STRING("MONEY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHORES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLOWANCE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Taschengeld"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIGITAL),
#else
        .text = COMPOUND_STRING("ALLOWANCE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLASS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bad"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TELEVISION),
#else
        .text = COMPOUND_STRING("BATH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMMEMORATE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONVERSATION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gespräch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMMEMORATE),
#else
        .text = COMPOUND_STRING("CONVERSATION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONVERSATION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCHOOL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schule"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MONEY),
#else
        .text = COMPOUND_STRING("SCHOOL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEPT_STORE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COMMEMORATE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gedenken"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVENT),
#else
        .text = COMPOUND_STRING("COMMEMORATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIGITAL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HABIT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gewohnheit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONVERSATION),
#else
        .text = COMPOUND_STRING("HABIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DREAM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GROUP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gruppe"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HABIT),
#else
        .text = COMPOUND_STRING("GROUP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVENT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wort"),
#else
        .text = COMPOUND_STRING("WORD"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_GROUP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lager"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOME),
#else
        .text = COMPOUND_STRING("STORE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HABIT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERVICE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Service"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INFORMATION),
#else
        .text = COMPOUND_STRING("SERVICE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Arbeit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ITEM),
#else
        .text = COMPOUND_STRING("WORK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INFORMATION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SYSTEM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("System"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEPT_STORE),
#else
        .text = COMPOUND_STRING("SYSTEM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ITEM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAIN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Trainieren"),
#else
        .text = COMPOUND_STRING("TRAIN"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_KINDERGARTEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLASS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lektion"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORE),
#else
        .text = COMPOUND_STRING("CLASS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LESSONS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LESSONS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unterricht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIFE),
#else
        .text = COMPOUND_STRING("LESSONS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LETTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INFORMATION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Information"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIVING),
#else
        .text = COMPOUND_STRING("INFORMATION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIFE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIVING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lebendig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACHER),
#else
        .text = COMPOUND_STRING("LIVING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIVING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACHER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lehrer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLASS),
#else
        .text = COMPOUND_STRING("TEACHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MACHINE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOURNAMENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Turnier"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STUDY),
#else
        .text = COMPOUND_STRING("TOURNAMENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAIL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LETTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Brief"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MACHINE),
#else
        .text = COMPOUND_STRING("LETTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MESSAGE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geschehen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RENTAL),
#else
        .text = COMPOUND_STRING("EVENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MONEY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIGITAL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Digitales"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MESSAGE),
#else
        .text = COMPOUND_STRING("DIGITAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NAME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Test"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NAME),
#else
        .text = COMPOUND_STRING("TEST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEWS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEPT_STORE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kaufhaus"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEWS),
#else
        .text = COMPOUND_STRING("DEPT. STORE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARTY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TELEVISION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fernseher"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARTY),
#else
        .text = COMPOUND_STRING("TELEVISION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PHONE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PHONE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Telefon"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHORES),
#else
        .text = COMPOUND_STRING("PHONE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POPULAR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ITEM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Item"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POPULAR),
#else
        .text = COMPOUND_STRING("ITEM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PROMISE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NAME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Name"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAIL),
#else
        .text = COMPOUND_STRING("NAME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RADIO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEWS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Neuigkeiten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RADIO),
#else
        .text = COMPOUND_STRING("NEWS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RENTAL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POPULAR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Populär"),
#else
        .text = COMPOUND_STRING("POPULAR"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCHOOL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARTY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Party"),
#else
        .text = COMPOUND_STRING("PARTY"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERVICE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STUDY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lernen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SYSTEM),
#else
        .text = COMPOUND_STRING("STUDY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MACHINE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Maschine"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLOWANCE),
#else
        .text = COMPOUND_STRING("MACHINE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STUDY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAIL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Post"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PHONE),
#else
        .text = COMPOUND_STRING("MAIL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SYSTEM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MESSAGE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mitteilung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEST),
#else
        .text = COMPOUND_STRING("MESSAGE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACHER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PROMISE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Versprechen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAIN),
#else
        .text = COMPOUND_STRING("PROMISE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TELEVISION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DREAM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Traum"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DREAM),
#else
        .text = COMPOUND_STRING("DREAM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KINDERGARTEN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kindergarten"),
#else
        .text = COMPOUND_STRING("KINDERGARTEN"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOURNAMENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIFE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Leben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LESSONS),
#else
        .text = COMPOUND_STRING("LIFE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAIN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RADIO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Radio"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PROMISE),
#else
        .text = COMPOUND_STRING("RADIO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RENTAL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Miete"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORLD),
#else
        .text = COMPOUND_STRING("RENTAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORLD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Welt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORD),
#else
        .text = COMPOUND_STRING("WORLD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORLD),
#endif
        .enabled = TRUE,
    },
};
