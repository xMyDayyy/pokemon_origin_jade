const struct EasyChatWordInfo gEasyChatGroup_Time[] = {
    [EC_INDEX(EC_WORD_FALL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Herbst"),
#else
        .text = COMPOUND_STRING("FALL"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_AGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MORNING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Morgen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANOTHER),
#else
        .text = COMPOUND_STRING("MORNING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALMOST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOMORROW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Übermorgen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEGINNING),
#else
        .text = COMPOUND_STRING("TOMORROW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALWAYS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LAST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Letzte(N)"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOON),
#else
        .text = COMPOUND_STRING("LAST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANOTHER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tag"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEARLY),
#else
        .text = COMPOUND_STRING("DAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEGINNING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMETIME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Irgendwann"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NIGHTTIME),
#else
        .text = COMPOUND_STRING("SOMETIME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CURRENT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALWAYS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Immer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OLDEN),
#else
        .text = COMPOUND_STRING("ALWAYS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAILY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CURRENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Momentan"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TUESDAY),
#else
        .text = COMPOUND_STRING("CURRENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOREVER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ewig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THURSDAY),
#else
        .text = COMPOUND_STRING("FOREVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAYS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAYS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tage"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_END),
#else
        .text = COMPOUND_STRING("DAYS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAYTIME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_END)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ende"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOREVER),
#else
        .text = COMPOUND_STRING("END"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EARLIER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TUESDAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Dienstag"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALMOST),
#else
        .text = COMPOUND_STRING("TUESDAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_END),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YESTERDAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gestern"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRIDAY),
#else
        .text = COMPOUND_STRING("YESTERDAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FALL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TODAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Heute"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EARLIER),
#else
        .text = COMPOUND_STRING("TODAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FINAL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRIDAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Freitag"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPRING),
#else
        .text = COMPOUND_STRING("FRIDAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FINISH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MONDAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Montag"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YESTERDAY),
#else
        .text = COMPOUND_STRING("MONDAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOREVER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LATER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Später"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FALL),
#else
        .text = COMPOUND_STRING("LATER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRIDAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EARLIER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Früher"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TODAY),
#else
        .text = COMPOUND_STRING("EARLIER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LAST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANOTHER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Am anderen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALWAYS),
#else
        .text = COMPOUND_STRING("ANOTHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LATER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zeit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMETIME),
#else
        .text = COMPOUND_STRING("TIME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MONDAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FINISH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schluss"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOW),
#else
        .text = COMPOUND_STRING("FINISH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MONTH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEDNESDAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mittwoch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LAST),
#else
        .text = COMPOUND_STRING("WEDNESDAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MORNING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bald"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FINAL),
#else
        .text = COMPOUND_STRING("SOON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEARLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_START)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("START"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEDNESDAY),
#else
        .text = COMPOUND_STRING("START"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEXT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MONTH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Monat"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CURRENT),
#else
        .text = COMPOUND_STRING("MONTH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NIGHT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STOP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Stopp"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MONTH),
#else
        .text = COMPOUND_STRING("STOP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NIGHTTIME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Jetzt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MONDAY),
#else
        .text = COMPOUND_STRING("NOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FINAL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Letzter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MORNING),
#else
        .text = COMPOUND_STRING("FINAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OLDEN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEXT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nächstes"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEXT),
#else
        .text = COMPOUND_STRING("NEXT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SATURDAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AGE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Alter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NIGHT),
#else
        .text = COMPOUND_STRING("AGE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMETIME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SATURDAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Samstag"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SATURDAY),
#else
        .text = COMPOUND_STRING("SATURDAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SUMMER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sommer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FINISH),
#else
        .text = COMPOUND_STRING("SUMMER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPRING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SUNDAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sonntag"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUMMER),
#else
        .text = COMPOUND_STRING("SUNDAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_START),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEGINNING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Anfang"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUNDAY),
#else
        .text = COMPOUND_STRING("BEGINNING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STOP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPRING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Frühling"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LATER),
#else
        .text = COMPOUND_STRING("SPRING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUMMER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAYTIME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tageszeit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_START),
#else
        .text = COMPOUND_STRING("DAYTIME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUNDAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WINTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Winter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STOP),
#else
        .text = COMPOUND_STRING("WINTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THURSDAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAILY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Täglich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAY),
#else
        .text = COMPOUND_STRING("DAILY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OLDEN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Damals"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAYS),
#else
        .text = COMPOUND_STRING("OLDEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TODAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALMOST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fast"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAYTIME),
#else
        .text = COMPOUND_STRING("ALMOST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOMORROW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEARLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Beinahe"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAILY),
#else
        .text = COMPOUND_STRING("NEARLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TUESDAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THURSDAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Donnerstag"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOMORROW),
#else
        .text = COMPOUND_STRING("THURSDAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEDNESDAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NIGHTTIME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bettzeit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WINTER),
#else
        .text = COMPOUND_STRING("NIGHTTIME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEEK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NIGHT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nacht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEEK),
#else
        .text = COMPOUND_STRING("NIGHT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WINTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEEK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Woche"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIME),
#else
        .text = COMPOUND_STRING("WEEK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YESTERDAY),
#endif
        .enabled = TRUE,
    },
};
