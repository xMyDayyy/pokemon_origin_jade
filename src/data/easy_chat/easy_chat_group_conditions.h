const struct EasyChatWordInfo gEasyChatGroup_Conditions[] = {
    [EC_INDEX(EC_WORD_HOT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Heiß"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PREPOSTEROUS),
#else
        .text = COMPOUND_STRING("HOT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABSENT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXISTS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Existiert"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABSENT),
#else
        .text = COMPOUND_STRING("EXISTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALONE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCESS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Übermäßig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALONE),
#else
        .text = COMPOUND_STRING("EXCESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AMUSING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPROVED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Genehmigt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AMUSING),
#else
        .text = COMPOUND_STRING("APPROVED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPROVED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hat"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELSE),
#else
        .text = COMPOUND_STRING("HAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWFUL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUSY),
#else
        .text = COMPOUND_STRING("GOOD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BADLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LESS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Weniger"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEST),
#else
        .text = COMPOUND_STRING("LESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BECOMES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOMENTUM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schwung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEED),
#else
        .text = COMPOUND_STRING("MOMENTUM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gehen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIMPLE),
#else
        .text = COMPOUND_STRING("GOING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEIRD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verrückt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REFRESHING),
#else
        .text = COMPOUND_STRING("WEIRD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BIG),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BUSY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Beschäftigt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXISTS),
#else
        .text = COMPOUND_STRING("BUSY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BORED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOGETHER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zusammen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCELLENT),
#else
        .text = COMPOUND_STRING("TOGETHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUSY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FULL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Voll"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FABULOUS),
#else
        .text = COMPOUND_STRING("FULL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLOSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABSENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Abwesend"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISTAKE),
#else
        .text = COMPOUND_STRING("ABSENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Seine"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LACKS),
#else
        .text = COMPOUND_STRING("BEING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CORRECT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Brauche"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOOD),
#else
        .text = COMPOUND_STRING("NEED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIFFERENT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TASTY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lecker"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MYSTERY),
#else
        .text = COMPOUND_STRING("TASTY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOCILE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILLED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geschickt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET),
#else
        .text = COMPOUND_STRING("SKILLED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOISY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Laut"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOING),
#else
        .text = COMPOUND_STRING("NOISY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENTERTAINING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BIG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Groß"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BORED),
#else
        .text = COMPOUND_STRING("BIG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCELLENT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LATE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Spät"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPROVED),
#else
        .text = COMPOUND_STRING("LATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCESS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLOSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nahe bei"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILL),
#else
        .text = COMPOUND_STRING("CLOSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXISTS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOCILE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sanftmütig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILLED),
#else
        .text = COMPOUND_STRING("DOCILE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXPENSIVE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AMUSING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Amüsant"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEAKENED),
#else
        .text = COMPOUND_STRING("AMUSING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FABULOUS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENTERTAINING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unterhaltsam"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEALTHY),
#else
        .text = COMPOUND_STRING("ENTERTAINING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERFECTION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Perfektion"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BIG),
#else
        .text = COMPOUND_STRING("PERFECTION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FULL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRETTY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hübsch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAS),
#else
        .text = COMPOUND_STRING("PRETTY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEALTHY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gesund"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOT),
#else
        .text = COMPOUND_STRING("HEALTHY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOOD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCELLENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Exzellent"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIND),
#else
        .text = COMPOUND_STRING("EXCELLENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPSIDE_DOWN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Umgedreht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRETTY),
#else
        .text = COMPOUND_STRING("UPSIDE DOWN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEALTHY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kalt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLD),
#else
        .text = COMPOUND_STRING("COLD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REFRESHING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Erfrischend"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NONE),
#else
        .text = COMPOUND_STRING("REFRESHING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMPOSSIBLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNAVOIDABLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unvermeidbar"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMALL),
#else
        .text = COMPOUND_STRING("UNAVOIDABLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Viele"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOUSY),
#else
        .text = COMPOUND_STRING("MUCH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LACKS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERWHELMING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mitreißend"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOISY),
#else
        .text = COMPOUND_STRING("OVERWHELMING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LATE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FABULOUS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fabelhaft"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LUKEWARM),
#else
        .text = COMPOUND_STRING("FABULOUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LESS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Anderes"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TASTY),
#else
        .text = COMPOUND_STRING("ELSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOUSY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXPENSIVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Teuer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BADLY),
#else
        .text = COMPOUND_STRING("EXPENSIVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CORRECT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Richtig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERWHELMING),
#else
        .text = COMPOUND_STRING("CORRECT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LUKEWARM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IMPOSSIBLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unmöglich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIRED),
#else
        .text = COMPOUND_STRING("IMPOSSIBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISTAKE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMALL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Klein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLOSE),
#else
        .text = COMPOUND_STRING("SMALL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOMENTUM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIFFERENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verschiedene"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURAL),
#else
        .text = COMPOUND_STRING("DIFFERENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIRED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Müde"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOTHING),
#else
        .text = COMPOUND_STRING("TIRED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MYSTERY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geschick"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOW),
#else
        .text = COMPOUND_STRING("SKILL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURAL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Top"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NON_STOP),
#else
        .text = COMPOUND_STRING("TOP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NON_STOP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nonstop"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERFECTION),
#else
        .text = COMPOUND_STRING("NON-STOP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOISY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PREPOSTEROUS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Absurd"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CORRECT),
#else
        .text = COMPOUND_STRING("PREPOSTEROUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NON_STOP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NONE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOCILE),
#else
        .text = COMPOUND_STRING("NONE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NONE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOTHING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nichts"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEEMS),
#else
        .text = COMPOUND_STRING("NOTHING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOTHING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURAL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Natürlich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELL),
#else
        .text = COMPOUND_STRING("NATURAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERWHELMING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BECOMES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wird"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWFUL),
#else
        .text = COMPOUND_STRING("BECOMES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERFECTION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LUKEWARM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lauwarm"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAST),
#else
        .text = COMPOUND_STRING("LUKEWARM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PREPOSTEROUS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schnell"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOMENTUM),
#else
        .text = COMPOUND_STRING("FAST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRETTY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Niedrig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEING),
#else
        .text = COMPOUND_STRING("LOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REFRESHING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWFUL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schlimm"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LATE),
#else
        .text = COMPOUND_STRING("AWFUL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALONE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Alleine"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXPENSIVE),
#else
        .text = COMPOUND_STRING("ALONE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEEMS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BORED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gelangweilt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOP),
#else
        .text = COMPOUND_STRING("BORED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIMPLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geheimnis"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCESS),
#else
        .text = COMPOUND_STRING("SECRET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MYSTERY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geheim"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPSIDE_DOWN),
#else
        .text = COMPOUND_STRING("MYSTERY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILLED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LACKS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fehlt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMPOSSIBLE),
#else
        .text = COMPOUND_STRING("LACKS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMALL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bestes"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENTERTAINING),
#else
        .text = COMPOUND_STRING("BEST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TASTY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOUSY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lausig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNAVOIDABLE),
#else
        .text = COMPOUND_STRING("LOUSY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIRED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISTAKE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fehler"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEIRD),
#else
        .text = COMPOUND_STRING("MISTAKE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOGETHER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Höflich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIFFERENT),
#else
        .text = COMPOUND_STRING("KIND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schlecht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH),
#else
        .text = COMPOUND_STRING("WELL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNAVOIDABLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEAKENED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geschwächt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FULL),
#else
        .text = COMPOUND_STRING("WEAKENED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPSIDE_DOWN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIMPLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Einfach"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LESS),
#else
        .text = COMPOUND_STRING("SIMPLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEAKENED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEEMS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Scheinbar"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BECOMES),
#else
        .text = COMPOUND_STRING("SEEMS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEIRD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BADLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mies"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOGETHER),
#else
        .text = COMPOUND_STRING("BADLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELL),
#endif
        .enabled = TRUE,
    },
};
