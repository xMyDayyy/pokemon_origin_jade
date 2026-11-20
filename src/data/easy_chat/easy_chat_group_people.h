const struct EasyChatWordInfo gEasyChatGroup_People[] = {
    [EC_INDEX(EC_WORD_OPPONENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Feind"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BROTHER),
#else
        .text = COMPOUND_STRING("OPPONENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ADULT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LADY),
#else
        .text = COMPOUND_STRING("I"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOU)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Du"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IT_S),
#else
        .text = COMPOUND_STRING("YOU"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AREN_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOURS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Deine"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SON),
#else
        .text = COMPOUND_STRING("YOURS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AUNT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Dein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOURS),
#else
        .text = COMPOUND_STRING("SON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BABE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOUR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Deiner"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOUR),
#else
        .text = COMPOUND_STRING("YOUR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEEN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOU_RE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Du bist"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BABE),
#else
        .text = COMPOUND_STRING("YOU'RE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BOY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOU_VE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Du hast"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU),
#else
        .text = COMPOUND_STRING("YOU'VE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BROTHER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOTHER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mutter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU_RE),
#else
        .text = COMPOUND_STRING("MOTHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHILDREN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRANDFATHER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Großvater"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU_VE),
#else
        .text = COMPOUND_STRING("GRANDFATHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAUGHTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNCLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Onkel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARENT),
#else
        .text = COMPOUND_STRING("UNCLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DUDE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FATHER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vater"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HE),
#else
        .text = COMPOUND_STRING("FATHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAMILY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BOY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Junge"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HE_S),
#else
        .text = COMPOUND_STRING("BOY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FATHER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ADULT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Erwachsener"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ADULT),
#else
        .text = COMPOUND_STRING("ADULT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRIEND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BROTHER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bruder"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEIR),
#else
        .text = COMPOUND_STRING("BROTHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIRL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SISTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schwester"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERS),
#else
        .text = COMPOUND_STRING("SISTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRANDFATHER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRANDMOTHER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Großmutter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAMILY),
#else
        .text = COMPOUND_STRING("GRANDMOTHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRANDMOTHER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AUNT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tante"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OPPONENT),
#else
        .text = COMPOUND_STRING("AUNT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Eltern"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MRS),
#else
        .text = COMPOUND_STRING("PARENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HE_S),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Man"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRIEND),
#else
        .text = COMPOUND_STRING("MAN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_HER),
#else
        .text = COMPOUND_STRING("ME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIRL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mädchen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_THEM),
#else
        .text = COMPOUND_STRING("GIRL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BABE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Dich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_US),
#else
        .text = COMPOUND_STRING("BABE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAMILY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Familie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_WHOM),
#else
        .text = COMPOUND_STRING("FAMILY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ihr"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIBLINGS),
#else
        .text = COMPOUND_STRING("HER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_AM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ihm"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRANDMOTHER),
#else
        .text = COMPOUND_STRING("HIM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_WAS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Er"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRANDFATHER),
#else
        .text = COMPOUND_STRING("HE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_VE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLACE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ort"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MR),
#else
        .text = COMPOUND_STRING("PLACE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IT_S),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAUGHTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tochter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I),
#else
        .text = COMPOUND_STRING("DAUGHTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KID),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_AM),
#else
        .text = COMPOUND_STRING("HIS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LADY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HE_S)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Er ist"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_VE),
#else
        .text = COMPOUND_STRING("HE'S"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AREN_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sind nicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_WAS),
#else
        .text = COMPOUND_STRING("AREN'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIBLINGS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geschwister"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIM),
#else
        .text = COMPOUND_STRING("SIBLINGS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOTHER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KID)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kindchen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY),
#else
        .text = COMPOUND_STRING("KID"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHILDREN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kinder"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HER),
#else
        .text = COMPOUND_STRING("CHILDREN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MRS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Herr"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMEONE),
#else
        .text = COMPOUND_STRING("MR."),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MRS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Frau"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BOY),
#else
        .text = COMPOUND_STRING("MRS."),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MYSELF),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MYSELF)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mir"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KID),
#else
        .text = COMPOUND_STRING("MYSELF"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OPPONENT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_WAS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ich war"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHILDREN),
#else
        .text = COMPOUND_STRING("I WAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_ME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zu mir"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIRL),
#else
        .text = COMPOUND_STRING("TO ME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARENT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAN),
#else
        .text = COMPOUND_STRING("MY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERSON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_AM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ich bin"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MY),
#else
        .text = COMPOUND_STRING("I AM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLACE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_VE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ich habe"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO_WAS),
#else
        .text = COMPOUND_STRING("I'VE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIVAL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ME),
#else
        .text = COMPOUND_STRING("WHO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMEONE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Jemand"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MYSELF),
#else
        .text = COMPOUND_STRING("SOMEONE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE_IS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHO_WAS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Meine"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOTHER),
#else
        .text = COMPOUND_STRING("WHO WAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE_WAS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_WHOM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Für wen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNCLE),
#else
        .text = COMPOUND_STRING("TO WHOM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIBLINGS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHOSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wessen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLACE),
#else
        .text = COMPOUND_STRING("WHOSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SISTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHO_IS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wer ist"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERSON),
#else
        .text = COMPOUND_STRING("WHO IS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IT_S)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Das ist"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIVAL),
#else
        .text = COMPOUND_STRING("IT'S"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMEONE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LADY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Dame"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SISTER),
#else
        .text = COMPOUND_STRING("LADY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRIEND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Freund"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIS),
#else
        .text = COMPOUND_STRING("FRIEND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEIR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verbündeter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE),
#else
        .text = COMPOUND_STRING("ALLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERSON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Person"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_VE),
#else
        .text = COMPOUND_STRING("PERSON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_WERE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DUDE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Type"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOME),
#else
        .text = COMPOUND_STRING("DUDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_RE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ihnen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE_IS),
#else
        .text = COMPOUND_STRING("THEY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_VE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY_WERE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sie waren"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOMAN),
#else
        .text = COMPOUND_STRING("THEY WERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_HER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_THEM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Für sie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_RE),
#else
        .text = COMPOUND_STRING("TO THEM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_ME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEIR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Euch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE_WAS),
#else
        .text = COMPOUND_STRING("THEIR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_THEM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY_RE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sie sind"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_WERE),
#else
        .text = COMPOUND_STRING("THEY'RE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_US),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY_VE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sie haben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AREN_T),
#else
        .text = COMPOUND_STRING("THEY'VE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_WHOM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wir"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AUNT),
#else
        .text = COMPOUND_STRING("WE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNCLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEEN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Waren"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAUGHTER),
#else
        .text = COMPOUND_STRING("BEEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_US)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Für uns"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DUDE),
#else
        .text = COMPOUND_STRING("TO US"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE_RE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unser"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUR),
#else
        .text = COMPOUND_STRING("OUR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE_VE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WE_RE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wir sind"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FATHER),
#else
        .text = COMPOUND_STRING("WE'RE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIVAL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rivale"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLY),
#else
        .text = COMPOUND_STRING("RIVAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO_IS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WE_VE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wir haben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEEN),
#else
        .text = COMPOUND_STRING("WE'VE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO_WAS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOMAN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sie konnten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO),
#else
        .text = COMPOUND_STRING("WOMAN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO_IS),
#else
        .text = COMPOUND_STRING("SHE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOMAN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHE_WAS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sie war"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOSE),
#else
        .text = COMPOUND_STRING("SHE WAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_HER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Für alle"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE),
#else
        .text = COMPOUND_STRING("TO HER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU_RE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Eure"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE_VE),
#else
        .text = COMPOUND_STRING("HERS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU_VE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHE_IS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sie ist"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE_RE),
#else
        .text = COMPOUND_STRING("SHE IS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOUR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sie hatte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_ME),
#else
        .text = COMPOUND_STRING("SOME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOURS),
#endif
        .enabled = TRUE,
    },
};
