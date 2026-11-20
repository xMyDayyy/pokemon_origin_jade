const struct EasyChatWordInfo gEasyChatGroup_Hobbies[] = {
    [EC_INDEX(EC_WORD_IDOL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Idol"),
#else
        .text = COMPOUND_STRING("IDOL"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_ADVENTURE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANIME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Anime"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FISHING),
#else
        .text = COMPOUND_STRING("ANIME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANIME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SONG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Song"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANIME),
#else
        .text = COMPOUND_STRING("SONG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BALL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOVIE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Film"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOOK),
#else
        .text = COMPOUND_STRING("MOVIE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BIKE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SWEETS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Naschen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BALL),
#else
        .text = COMPOUND_STRING("SWEETS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BOARD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHAT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Plaudern"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VIEWING),
#else
        .text = COMPOUND_STRING("CHAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BOOK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHILD_S_PLAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kinderspiel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLOWERS),
#else
        .text = COMPOUND_STRING("CHILD'S PLAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAMERA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOYS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Spielzeug"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BOARD),
#else
        .text = COMPOUND_STRING("TOYS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CARDS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUSIC)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Musik"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BOOK),
#else
        .text = COMPOUND_STRING("MUSIC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHANNEL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CARDS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kartenspiele"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMICS),
#else
        .text = COMPOUND_STRING("CARDS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHAT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOPPING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Einkaufen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESIGN),
#else
        .text = COMPOUND_STRING("SHOPPING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHILD_S_PLAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAMERA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fotos"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOPPING),
#else
        .text = COMPOUND_STRING("CAMERA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLLECTION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VIEWING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Besichtigung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLANS),
#else
        .text = COMPOUND_STRING("VIEWING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMICS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPECTATOR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zuschauer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BIKE),
#else
        .text = COMPOUND_STRING("SPECTATOR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMPLETE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOURMET)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gourmet"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOLIDAY),
#else
        .text = COMPOUND_STRING("GOURMET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DANCE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GAME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Spiel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FESTIVAL),
#else
        .text = COMPOUND_STRING("GAME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DATE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RPG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rpg"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOVIE),
#else
        .text = COMPOUND_STRING("RPG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESIGN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLLECTION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sammlung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAMERA),
#else
        .text = COMPOUND_STRING("COLLECTION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIET),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COMPLETE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Komplett"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOURMET),
#else
        .text = COMPOUND_STRING("COMPLETE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FASHION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAGAZINE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Magazin"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERO),
#else
        .text = COMPOUND_STRING("MAGAZINE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FESTIVAL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WALK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Spazieren"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEROINE),
#else
        .text = COMPOUND_STRING("WALK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FISHING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BIKE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fahrrad"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAKING),
#else
        .text = COMPOUND_STRING("BIKE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLOWERS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOBBY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hobby"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOBBY),
#else
        .text = COMPOUND_STRING("HOBBY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GAME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPORTS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sport"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IDOL),
#else
        .text = COMPOUND_STRING("SPORTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOURMET),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOFTWARE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Software"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CARDS),
#else
        .text = COMPOUND_STRING("SOFTWARE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SONGS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Songs"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHILD_S_PLAY),
#else
        .text = COMPOUND_STRING("SONGS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEROINE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIET)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nahrung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMPLETE),
#else
        .text = COMPOUND_STRING("DIET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOBBY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TREASURE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kostbarkeit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TREASURE),
#else
        .text = COMPOUND_STRING("TREASURE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOLIDAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAVEL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Reisen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOCOMOTIVE),
#else
        .text = COMPOUND_STRING("TRAVEL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IDOL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DANCE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tanzen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAGAZINE),
#else
        .text = COMPOUND_STRING("DANCE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOCOMOTIVE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHANNEL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wassersport"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FASHION),
#else
        .text = COMPOUND_STRING("CHANNEL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOOK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAKING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Herstellung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUSIC),
#else
        .text = COMPOUND_STRING("MAKING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAGAZINE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FISHING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Angeln"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIET),
#else
        .text = COMPOUND_STRING("FISHING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAKING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DATE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verabredung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SWEETS),
#else
        .text = COMPOUND_STRING("DATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOVIE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESIGN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Design"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NAP),
#else
        .text = COMPOUND_STRING("DESIGN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUSIC),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOCOMOTIVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lokomotiven"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PC),
#else
        .text = COMPOUND_STRING("LOCOMOTIVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NAP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLUSH_DOLL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Plüschpuppen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHAT),
#else
        .text = COMPOUND_STRING("PLUSH DOLL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PC),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PC)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("PC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLUSH_DOLL),
#else
        .text = COMPOUND_STRING("PC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLANS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLOWERS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Blumen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAVEL),
#else
        .text = COMPOUND_STRING("FLOWERS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLUSH_DOLL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Held"),
#else
        .text = COMPOUND_STRING("HERO"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_RPG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NAP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nickerchen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLLECTION),
#else
        .text = COMPOUND_STRING("NAP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOPPING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEROINE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Heldin"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRENDY),
#else
        .text = COMPOUND_STRING("HEROINE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOFTWARE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FASHION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mode"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOFTWARE),
#else
        .text = COMPOUND_STRING("FASHION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SONG),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ADVENTURE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Abenteuer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SONG),
#else
        .text = COMPOUND_STRING("ADVENTURE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SONGS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BOARD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Brettspiele"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SONGS),
#else
        .text = COMPOUND_STRING("BOARD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPECTATOR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BALL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ball"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALK),
#else
        .text = COMPOUND_STRING("BALL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPORTS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BOOK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bücher"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GAME),
#else
        .text = COMPOUND_STRING("BOOK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SWEETS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FESTIVAL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Festivals"),
#else
        .text = COMPOUND_STRING("FESTIVAL"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOYS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COMICS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Comics"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPORTS),
#else
        .text = COMPOUND_STRING("COMICS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAVEL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOLIDAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ferien"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DANCE),
#else
        .text = COMPOUND_STRING("HOLIDAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TREASURE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLANS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Etwas planen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VACATION),
#else
        .text = COMPOUND_STRING("PLANS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRENDY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRENDY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schickimicki"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DATE),
#else
        .text = COMPOUND_STRING("TRENDY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VACATION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VACATION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Urlaub"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHANNEL),
#else
        .text = COMPOUND_STRING("VACATION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VIEWING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOOK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Aussehen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPECTATOR),
#else
        .text = COMPOUND_STRING("LOOK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALK),
#endif
        .enabled = TRUE,
    },
};
