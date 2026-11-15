const struct EasyChatWordInfo gEasyChatGroup_Endings[] = {
    [EC_INDEX(EC_WORD_WILL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Werden"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIKE),
#else
        .text = COMPOUND_STRING("WILL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_A),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WILL_BE_HERE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wird da sein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALL),
#else
        .text = COMPOUND_STRING("WILL BE HERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABOUT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Oder"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAN),
#else
        .text = COMPOUND_STRING("OR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AFTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIMES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zeiten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ON),
#else
        .text = COMPOUND_STRING("TIMES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WONDER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wunder"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OTHER),
#else
        .text = COMPOUND_STRING("WONDER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IS_IT_QUES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Es ist"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO),
#else
        .text = COMPOUND_STRING("IS IT?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANYWHERE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sei"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUT),
#else
        .text = COMPOUND_STRING("BE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ARE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIMME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gib mir"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OFF),
#else
        .text = COMPOUND_STRING("GIMME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COULD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Könnte"),
#else
        .text = COMPOUND_STRING("COULD"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_AT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIKELY_TO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vermutlich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BETTER),
#else
        .text = COMPOUND_STRING("LIKELY TO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOULD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Würde"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ARE),
#else
        .text = COMPOUND_STRING("WOULD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEFORE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ist"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THERE),
#else
        .text = COMPOUND_STRING("IS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELONGS_TO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ISN_T_IT_QUES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nicht wahr?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_A),
#else
        .text = COMPOUND_STRING("ISN'T IT?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BETTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LET_S)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lass uns"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AN),
#else
        .text = COMPOUND_STRING("LET'S"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OTHER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Andere"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OF),
#else
        .text = COMPOUND_STRING("OTHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ARE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bist"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ONCE),
#else
        .text = COMPOUND_STRING("ARE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COULD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("War"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IT),
#else
        .text = COMPOUND_STRING("WAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DID),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WERE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wurden"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IS_IT_QUES),
#else
        .text = COMPOUND_STRING("WERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIDN_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sind"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOR),
#else
        .text = COMPOUND_STRING("THOSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ISN_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ist kein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELONGS_TO),
#else
        .text = COMPOUND_STRING("ISN'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WON_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Werde nicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AS),
#else
        .text = COMPOUND_STRING("WON'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOESN_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kannst"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DID),
#else
        .text = COMPOUND_STRING("CAN'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DON_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Können"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIMME),
#else
        .text = COMPOUND_STRING("CAN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DON_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAVE),
#else
        .text = COMPOUND_STRING("DON'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mache"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAVEN_T),
#else
        .text = COMPOUND_STRING("DO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIMME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tut"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IN),
#else
        .text = COMPOUND_STRING("DOES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAVE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHOM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wem"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANYWHERE),
#else
        .text = COMPOUND_STRING("WHOM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAVEN_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHICH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Welche"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IS),
#else
        .text = COMPOUND_STRING("WHICH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WASN_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("War nicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ISN_T),
#else
        .text = COMPOUND_STRING("WASN'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEREN_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sollten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVER),
#else
        .text = COMPOUND_STRING("WEREN'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IS_IT_QUES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Habe"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN_T),
#else
        .text = COMPOUND_STRING("HAVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ISN_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAVEN_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Haben nicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN),
#else
        .text = COMPOUND_STRING("HAVEN'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ISN_T_IT_QUES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COULD),
#else
        .text = COMPOUND_STRING("A"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Eine"),
#else
        .text = COMPOUND_STRING("AN"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_LET_S),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nicht nur"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DO),
#else
        .text = COMPOUND_STRING("NOT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIKE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THERE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Da"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOESN_T),
#else
        .text = COMPOUND_STRING("THERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIKELY_TO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OK_QUES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("O.K.?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WITH),
#else
        .text = COMPOUND_STRING("OK?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAYBE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("So"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AFTER),
#else
        .text = COMPOUND_STRING("SO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAYBE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vielleicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DON_T),
#else
        .text = COMPOUND_STRING("MAYBE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OF),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABOUT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Umher"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIDN_T),
#else
        .text = COMPOUND_STRING("ABOUT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OFF),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Über"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOT),
#else
        .text = COMPOUND_STRING("OVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OK_QUES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Es"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ISN_T_IT_QUES),
#else
        .text = COMPOUND_STRING("IT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Alle"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OK_QUES),
#else
        .text = COMPOUND_STRING("ALL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ONCE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Für"),
#else
        .text = COMPOUND_STRING("FOR"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_OR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("An"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WITHOUT),
#else
        .text = COMPOUND_STRING("ON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OTHER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OFF)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Aus"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BE),
#else
        .text = COMPOUND_STRING("OFF"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Genauso"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SINCE),
#else
        .text = COMPOUND_STRING("AS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zu"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE),
#else
        .text = COMPOUND_STRING("TO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SINCE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WITH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mit"),
#else
        .text = COMPOUND_STRING("WITH"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_SO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BETTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Besser"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEREN_T),
#else
        .text = COMPOUND_STRING("BETTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Jemals"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOES),
#else
        .text = COMPOUND_STRING("EVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THERE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SINCE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Seit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVER),
#else
        .text = COMPOUND_STRING("SINCE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OF)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Einen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABOUT),
#else
        .text = COMPOUND_STRING("OF"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIMES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELONGS_TO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gehört zu"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIKELY_TO),
#else
        .text = COMPOUND_STRING("BELONGS TO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bei"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAYBE),
#else
        .text = COMPOUND_STRING("AT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("In"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEFORE),
#else
        .text = COMPOUND_STRING("IN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Auf"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHILE),
#else
        .text = COMPOUND_STRING("OUT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WASN_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Auch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAS),
#else
        .text = COMPOUND_STRING("TOO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WERE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIKE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ähnlich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WASN_T),
#else
        .text = COMPOUND_STRING("LIKE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEREN_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DID)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Getan"),
#else
        .text = COMPOUND_STRING("DID"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHICH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIDN_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nicht getan"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOM),
#else
        .text = COMPOUND_STRING("DIDN'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHILE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOESN_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Macht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WON_T),
#else
        .text = COMPOUND_STRING("DOESN'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WITHOUT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ohne"),
#else
        .text = COMPOUND_STRING("WITHOUT"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_WILL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AFTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nach"),
#else
        .text = COMPOUND_STRING("AFTER"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_WILL_BE_HERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEFORE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vorher"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WONDER),
#else
        .text = COMPOUND_STRING("BEFORE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WITH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHILE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Während"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOULD),
#else
        .text = COMPOUND_STRING("WHILE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WITHOUT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Als"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WERE),
#else
        .text = COMPOUND_STRING("THAN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WON_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ONCE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Einmal"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIMES),
#else
        .text = COMPOUND_STRING("ONCE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WONDER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANYWHERE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Irgendwo"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO),
#else
        .text = COMPOUND_STRING("ANYWHERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOULD),
#endif
        .enabled = TRUE,
    },
};
