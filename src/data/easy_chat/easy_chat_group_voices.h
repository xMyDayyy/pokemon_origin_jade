const struct EasyChatWordInfo gEasyChatGroup_Voices[] = {
    [EC_INDEX(EC_WORD_EXCL)] =
    {
        .text = COMPOUND_STRING("!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCL_EXCL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("!!!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCL_EXCL),
#else
        .text = COMPOUND_STRING("!!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCL_EXCL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUES_EXCL)] =
    {
        .text = COMPOUND_STRING("?!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DASH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUES)] =
    {
        .text = COMPOUND_STRING("?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DASH_DASH_DASH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS)] =
    {
        .text = COMPOUND_STRING("…"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS_EXCL)] =
    {
        .text = COMPOUND_STRING("…!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS)] =
    {
        .text = COMPOUND_STRING("………"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DASH)] =
    {
        .text = COMPOUND_STRING("-"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DASH_DASH_DASH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("---"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUES_EXCL),
#else
        .text = COMPOUND_STRING("- - -"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUES_EXCL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UH_OH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Oh oh"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ARRGH),
#else
        .text = COMPOUND_STRING("UH-OH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AGREE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAAAH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Waaah"),
#else
        .text = COMPOUND_STRING("WAAAH"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_AHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AHAHA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ahahaha"),
#else
        .text = COMPOUND_STRING("AHAHA"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_AIYEEH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_QUES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Oh?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_URGH),
#else
        .text = COMPOUND_STRING("OH?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ARRGH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOPE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nö"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAY),
#else
        .text = COMPOUND_STRING("NOPE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_URGH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Argh"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOL),
#else
        .text = COMPOUND_STRING("URGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRIES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HMM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hmm"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OKAY),
#else
        .text = COMPOUND_STRING("HMM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHOAH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Oooh"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FUFUFU),
#else
        .text = COMPOUND_STRING("WHOAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EEK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WROOOAAR_EXCL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Woooar"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOCKED),
#else
        .text = COMPOUND_STRING("WROOOAAR!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EH_QUES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wow"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRAAAH),
#else
        .text = COMPOUND_STRING("WOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EHEHE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIGGLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kicher"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GWAH),
#else
        .text = COMPOUND_STRING("GIGGLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FUFUFU),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIGH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Seufz"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GWAHAHAHA),
#else
        .text = COMPOUND_STRING("SIGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIGGLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNBELIEVABLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unglaublich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAH),
#else
        .text = COMPOUND_STRING("UNBELIEVABLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRAAAH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRIES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schreit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EH_QUES),
#else
        .text = COMPOUND_STRING("CRIES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GWAH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AGREE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Richtig!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEHE),
#else
        .text = COMPOUND_STRING("AGREE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GWAHAHAHA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EH_QUES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Häh?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAHAHA),
#else
        .text = COMPOUND_STRING("EH?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schrei"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EHEHE),
#else
        .text = COMPOUND_STRING("CRY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAHAHA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EHEHE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hähähä"),
#else
        .text = COMPOUND_STRING("EHEHE"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OI_OI_OI)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Oje oje"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEHEHE),
#else
        .text = COMPOUND_STRING("OI, OI, OI"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEHE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_YEAH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Oh, yeah"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUFUFU),
#else
        .text = COMPOUND_STRING("OH, YEAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEHEHE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Oh"),
#else
        .text = COMPOUND_STRING("OH"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIYAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OOPS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hups"),
#else
        .text = COMPOUND_STRING("OOPS"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_HMM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOCKED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geschockt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUMPH),
#else
        .text = COMPOUND_STRING("SHOCKED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOHOHO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EEK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Igitt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOHOHO),
#else
        .text = COMPOUND_STRING("EEK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUMPH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRAAAH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Graaah"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OOPS),
#else
        .text = COMPOUND_STRING("GRAAAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LALALA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GWAHAHAHA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gwahahaha"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EEK),
#else
        .text = COMPOUND_STRING("GWAHAHAHA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Art"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YAY),
#else
        .text = COMPOUND_STRING("WAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MMM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TCH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tse"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YUP),
#else
        .text = COMPOUND_STRING("TCH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUFUFU),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEHE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hähä"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOWEE),
#else
        .text = COMPOUND_STRING("HEHE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOPE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hah"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIGGLE),
#else
        .text = COMPOUND_STRING("HAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YUP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Jajaja"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LALALA),
#else
        .text = COMPOUND_STRING("YUP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_DEAR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAHAHA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hahaha"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_DEAR),
#else
        .text = COMPOUND_STRING("HAHAHA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_YEAH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AIYEEH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Aiyeeh"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MMM),
#else
        .text = COMPOUND_STRING("AIYEEH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_KAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIYAH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hiyah"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOPE),
#else
        .text = COMPOUND_STRING("HIYAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_QUES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FUFUFU)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Föföfö"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH),
#else
        .text = COMPOUND_STRING("FUFUFU"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OI_OI_OI),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Brüll lach"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UH_OH),
#else
        .text = COMPOUND_STRING("LOL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OKAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SNORT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Prust"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_YEAH),
#else
        .text = COMPOUND_STRING("SNORT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OOPS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUMPH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hmpf"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_QUES),
#else
        .text = COMPOUND_STRING("HUMPH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOCKED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEHEHE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hehehe"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OI_OI_OI),
#else
        .text = COMPOUND_STRING("HEHEHE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIGH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Heh"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_KAY),
#else
        .text = COMPOUND_STRING("HEH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SNORT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOHOHO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hohoho"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOAH),
#else
        .text = COMPOUND_STRING("HOHOHO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TCH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UH_HUH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ui ui"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SNORT),
#else
        .text = COMPOUND_STRING("UH-HUH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UH_HUH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_DEAR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Meine güte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AGREE),
#else
        .text = COMPOUND_STRING("OH, DEAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UH_OH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ARRGH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Aarrgh"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRY),
#else
        .text = COMPOUND_STRING("ARRGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNBELIEVABLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUFUFU)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hihihi"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRIES),
#else
        .text = COMPOUND_STRING("MUFUFU"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_URGH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MMM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mmmh"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIGH),
#else
        .text = COMPOUND_STRING("MMM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAAAH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_KAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Okay"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TCH),
#else
        .text = COMPOUND_STRING("OH-KAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAHAHAHA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OKAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Durchschnitt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWW),
#else
        .text = COMPOUND_STRING("OKAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LALALA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lalala"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UH_HUH),
#else
        .text = COMPOUND_STRING("LALALA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOAH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Jaha"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNBELIEVABLE),
#else
        .text = COMPOUND_STRING("YAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Uff"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAAAH),
#else
        .text = COMPOUND_STRING("AWW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOWEE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOWEE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Juchee"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAHAHAHA),
#else
        .text = COMPOUND_STRING("WOWEE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WROOOAAR_EXCL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GWAH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Grrr"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WROOOAAR_EXCL),
#else
        .text = COMPOUND_STRING("GWAH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAHAHAHA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wahahaha"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOW),
#else
        .text = COMPOUND_STRING("WAHAHAHA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YUP),
#endif
        .enabled = TRUE,
    },
};
