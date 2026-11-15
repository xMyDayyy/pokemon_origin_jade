const struct EasyChatWordInfo gEasyChatGroup_Misc[] = {
    [EC_INDEX(EC_WORD_HIGHS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Höhen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UM),
#else
        .text = COMPOUND_STRING("HIGHS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABOVE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOWS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tiefen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVERY),
#else
        .text = COMPOUND_STRING("LOWS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Äh"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUTSIDE),
#else
        .text = COMPOUND_STRING("UM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REAR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hinten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT),
#else
        .text = COMPOUND_STRING("REAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BACK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINGS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sachen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS_IS_IT_EXCL),
#else
        .text = COMPOUND_STRING("THINGS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ding"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_S_IT_EXCL),
#else
        .text = COMPOUND_STRING("THING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BESIDE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unterhalb"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AM),
#else
        .text = COMPOUND_STRING("BELOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHOICE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABOVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Oberhalb"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_WAS),
#else
        .text = COMPOUND_STRING("ABOVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONFUSED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BACK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zurück"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS),
#else
        .text = COMPOUND_STRING("BACK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEEP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIGH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hoch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE),
#else
        .text = COMPOUND_STRING("HIGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOWN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hier"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE_WERE),
#else
        .text = COMPOUND_STRING("HERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVERY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSIDE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Innen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THING),
#else
        .text = COMPOUND_STRING("INSIDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUTSIDE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Außen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWAY),
#else
        .text = COMPOUND_STRING("OUTSIDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BESIDE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Neben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OPPOSITE),
#else
        .text = COMPOUND_STRING("BESIDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS_IS_IT_EXCL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Das ist es!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_WERE),
#else
        .text = COMPOUND_STRING("THIS IS IT!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Dies"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHEN),
#else
        .text = COMPOUND_STRING("THIS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGHS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVERY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Alles"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE),
#else
        .text = COMPOUND_STRING("EVERY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSIDE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Diese"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REAR),
#else
        .text = COMPOUND_STRING("THESE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEFT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE_WERE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Diese waren"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOWN),
#else
        .text = COMPOUND_STRING("THESE WERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOWS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOWN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hinunter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGH),
#else
        .text = COMPOUND_STRING("DOWN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEAR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Das"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGHS),
#else
        .text = COMPOUND_STRING("THAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OPPOSITE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_ARE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schon"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSIDE),
#else
        .text = COMPOUND_STRING("THOSE ARE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUTSIDE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_WERE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Genug"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEFT),
#else
        .text = COMPOUND_STRING("THOSE WERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REAR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_S_IT_EXCL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Das ist’s!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEAR),
#else
        .text = COMPOUND_STRING("THAT'S IT!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIGHT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Das sind"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BESIDE),
#else
        .text = COMPOUND_STRING("AM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHALLOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_WAS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Das war"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UP),
#else
        .text = COMPOUND_STRING("THAT WAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vorne"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABOVE),
#else
        .text = COMPOUND_STRING("FRONT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_WAS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Oben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIGHT),
#else
        .text = COMPOUND_STRING("UP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_S_IT_EXCL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOICE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wahl"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINGS),
#else
        .text = COMPOUND_STRING("CHOICE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Weit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_ARE),
#else
        .text = COMPOUND_STRING("FAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE_WERE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fort"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHALLOW),
#else
        .text = COMPOUND_STRING("AWAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEAR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nahe"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEEP),
#else
        .text = COMPOUND_STRING("NEAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINGS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHERE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wo"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOWS),
#else
        .text = COMPOUND_STRING("WHERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHEN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gleich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELOW),
#else
        .text = COMPOUND_STRING("WHEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS_IS_IT_EXCL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Was"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONFUSED),
#else
        .text = COMPOUND_STRING("WHAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_ARE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEEP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tief"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONT),
#else
        .text = COMPOUND_STRING("DEEP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_WERE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHALLOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Seicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHOICE),
#else
        .text = COMPOUND_STRING("SHALLOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Warum"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHY),
#else
        .text = COMPOUND_STRING("WHY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONFUSED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verwirrt"),
#else
        .text = COMPOUND_STRING("CONFUSED"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OPPOSITE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gegenüber"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAR),
#else
        .text = COMPOUND_STRING("OPPOSITE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHEN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEFT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Links"),
#else
        .text = COMPOUND_STRING("LEFT"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIGHT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rechts"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BACK),
#else
        .text = COMPOUND_STRING("RIGHT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHY),
#endif
        .enabled = TRUE,
    },
};
