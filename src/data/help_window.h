// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
// Remember to modify include/constants/help_window.h to include identifiers so they can be used in event scripts.
const struct HelpWindow gHelpWindowInfo[] =
{
    [HELP_DEMO_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Information: Hilfe-Fenster"),
        .desc = COMPOUND_STRING("Dies ist ein Hilfe-Fenster. Du\n"
                                "kannst viel Text anzeigen,\n"
                                "den Spieler nicht lesen!\n\nSuper!"
#else
        .header = COMPOUND_STRING("Information: Help Windows"),
        .desc = COMPOUND_STRING("This is a help window. You can put\n"
                                "lots of text on the screen that\n"
                                "players won't read!\n\nIsn't that great!"
#endif
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 4, 5},
    },
    [HELP_GAMESTART_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Information: Weitere Optionen"),
        .desc = COMPOUND_STRING("Die Uhr kannst du in jedem Pokémon-Center\n"
                                "jederzeit ohne Nachteil umstellen.\n"
                                "Sieh dir auch die Basis-Items in deinem\n"
                                "Beutel und das Optionen-Menü an. Dort\n"
                                "warten noch mehr Anpassungsmöglichkeiten.\n"
                                "Viel Spaß!"
#else
        .header = COMPOUND_STRING("Information: More Options"),
        .desc = COMPOUND_STRING("The clock can be changed from any\n"
                                "POKéMON CENTER with no penalty.\n"
                                "Make sure to check your BAG's KEY ITEMS\n"
                                "and your OPTIONS MENU for even more\n"
                                "ways to customize your experience.\n"
                                "Enjoy!"
#endif
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_TRADE_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Warnung: Kompatibilität"),
        .desc = COMPOUND_STRING("Einen Link mit einem Spiel\n"
                                "herzustellen, welches nicht\n"
								"Heart & Soul ist, kann\n"
                                "permanenten Schaden deines Spielstandes.\n"
                                "Linke nur mit einer anderen Kopie von\n"
                                "Heart & Soul, welche dieselbe\n"
                                "Versionsnummer hat."
#else
        .header = COMPOUND_STRING("WARNING: COMPATIBILITY"),
        .desc = COMPOUND_STRING("Attempting to link incorrectly may result\n"
                                "in permanent damage to your save file.\n"
                                "Only link with another player if:\n"
                                "You are both playing Heart & Soul.\n"
                                "You are both on the same version.\n"
                                "You both have the same challenge settings.\n"
                                "You are NOT using any randomizer settings."
#endif
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 4, 5},
    },
    [HELP_SINJOH_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Optionaler Bonus-Inhalt: Sinjoh"),
        .desc = COMPOUND_STRING("Dieser NPC gewährt Zugang zum\nBonus-Inhalt: Sinjoh.\nFür die Story und die Vervoll-\nständigung des Nationalen Pokédex\nnicht erforderlich.\n"),
#else
        .header = COMPOUND_STRING("OPTIONAL BONUS CONTENT: SINJOH"),
        .desc = COMPOUND_STRING("This NPC grants access to optional\n"
                                "bonus content: SINJOH.\n"
                                "It is NOT required for story\n"
                                "or NATIONAL POKéDEX completion.\n"
                                "\n"
                                "It's just a bonus. If you want it."
                            ),
#endif
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_ALOLA_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Optionaler Bonus-Inhalt: Inseln"),
        .desc = COMPOUND_STRING("Dieser NPC gewährt Zugang zum\nBonus-Inhalt: Alola-Inseln.\nFür die Story und die Vervoll-\nständigung des Nationalen Pokédex\nnicht erforderlich.\n"),
#else
        .header = COMPOUND_STRING("OPTIONAL BONUS CONTENT: ISLES"),
        .desc = COMPOUND_STRING("This NPC grants access to optional\n"
                                "bonus content: ISLES.\n"
                                "It is NOT required for story\n"
                                "or NATIONAL POKéDEX completion.\n"
                                "\n"
                                "It's just a bonus. If you want it."
                            ),
#endif
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE1_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Baby-Pokémon: Fähigkeiten"),
        .desc = COMPOUND_STRING("Pichus Fähigkeit ist Statik.\n"
                                "Piis Fähigkeit ist Charmebolzen.\n"
                                "Fluffeluffs Fähigkeit ist Charmebolzen.\n"
                                "Rabauz' Fähigkeit ist Adrenalin.\n"
                                "Kussillas Fähigkeit ist Dösigkeit.\n"
                                "Elekids Fähigkeit ist Statik.\n"
                                "Magbys Fähigkeit ist Flammenkörper."
#else
        .header = COMPOUND_STRING("BABY POKéMON ABILITIES"),
        .desc = COMPOUND_STRING("PICHU's ability is STATIC.\n"
                                "CLEFFA's ability is CUTE CHARM.\n"
                                "IGGLYBUFF's ability is CUTE CHARM.\n"
                                "TYROGUE's ability is GUTS.\n"
                                "SMOOCHUM's ability is OBLIVIOUS.\n"
                                "ELEKID's ability is STATIC.\n"
                                "MAGBY's ability is FLAME BODY."
#endif
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE2_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Baby-Pokémon: Typen"),
        .desc = COMPOUND_STRING("Pichu ist Typ Elektro.\n"
                                "Pii ist Typ Normal.\n"
                                "Fluffeluff ist Typ Normal.\n"
                                "Rabauz ist Typ Kampf.\n"
                                "Kussilla ist Typ Eis.\n"
                                "Elekid ist Typ Elektro.\n"
                                "Magby ist Typ Feuer."
#else
        .header = COMPOUND_STRING("BABY POKéMON TYPES"),
        .desc = COMPOUND_STRING("PICHU is ELECTRIC type.\n"
                                "CLEFFA is NORMAL type.\n"
                                "IGGLYBUFF is NORMAL type.\n"
                                "TYROGUE is FIGHTING type.\n"
                                "SMOOCHUM is ICE type.\n"
                                "ELEKID is ELECTRIC type.\n"
                                "MAGBY is FIRE type."
#endif
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE3_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Baby-Pokémon: Rufe"),
        .desc = COMPOUND_STRING("Pichu sagt WAAAH.\n"
                                "Pii sagt EEK.\n"
                                "Fluffeluff sagt LALALA.\n"
                                "Rabauz sagt HIYAH.\n"
                                "Kussilla sagt EHEHE.\n"
                                "Elekid sagt OI, OI, OI.\n"
                                "Magby sagt TCH."
#else
        .header = COMPOUND_STRING("BABY POKéMON CRIES"),
        .desc = COMPOUND_STRING("PICHU says WAAAH.\n"
                                "CLEFFA says EEK.\n"
                                "IGGLYBUFF says LALALA.\n"
                                "TYROGUE says HIYAH.\n"
                                "SMOOCHUM says EHEHE.\n"
                                "ELEKID says OI, OI, OI.\n"
                                "MAGBY says TCH."
#endif
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE4_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Baby-Pokémon: Verhalten"),
        .desc = COMPOUND_STRING("Pichu spielt gerne.\n"
                                "Pii schaut den Mond an.\n"
                                "Fluffeluff singt alle in den Schlaf.\n"
                                "Rabauz trainiert ständig.\n"
                                "Kussilla genießt Aufmerksamkeit.\n"
                                "Elekid lädt sich auf.\n"
                                "Magby ist ein Hitzkopf."
#else
        .header = COMPOUND_STRING("BABY POKéMON ACTIONS"),
        .desc = COMPOUND_STRING("PICHU likes to PLAY all day.\n"
                                "CLEFFA LOOKS at the moon.\n"
                                "IGGLYBUFF puts them to SLEEP.\n"
                                "TYROGUE TRAINS constantly.\n"
                                "SMOOCHUM likes to SHOW off.\n"
                                "ELEKID STORES up charge.\n"
                                "MAGBY often ANGERS."
#endif
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_POKEBLOCK_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Näpfe: normale {POKEBLOCK}"),
        .desc = COMPOUND_STRING("Die Riegelfarbe lockt perfekte IVs an:\n"
                                "Rot: KP,Ang,Init{CLEAR_TO 104}Blau: KP,SP.A,Init\n"
                                "Rosa: Ang,SP.A,Init{CLEAR_TO 104}Grün: KP,Ver,SP.V\n"
                                "Gelb: KP,Ang,Ver{CLEAR_TO 104}Lila: Ang,Ver,SP.V\n"
                                "Indigo: KP,SP.A,SP.V{CLEAR_TO 104}Braun: Ver,Init,SP.V\n"
                                "Cyan: SP.A,Init,SP.V{CLEAR_TO 104}Oliv: Ang,Ver,Init\n"
                                "Grau: KP,Ang,SP.A\n"
                                "Jeder {POKEBLOCK}: versteckte Fähigkeit."
                            ),
#else
        .header = COMPOUND_STRING("FEEDERS: REGULAR POKéBLOCKS"),
        .desc = COMPOUND_STRING("POKéBLOCK colors attract perfect IVs:\n"
                                "RED: HP,ATK,SPE   BLU: HP,SPA,SPE\n"
                                "PNK: ATK,SPA,SPE  GRN: HP,DEF,SPD\n"
                                "YEL: HP,ATK,DEF   PUR: ATK,DEF,SPD\n"
                                "IND: HP,SPA,SPD   BRN: DEF,SPE,SPD\n"
                                "LBL: SPA,SPE,SPD  OLV: ATK,DEF,SPE\n"
                                "GRY: HP,ATK,SPA\n"
                                "Every POKéBLOCK attracts HIDDEN ABILITY."

                            ),
#endif
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_GOLD_POKEBLOCK_WINDOW] =
    {
#if GERMAN
        .header = COMPOUND_STRING("Näpfe: {POKEBLOCK} Gold"),
        .desc = COMPOUND_STRING("{POKEBLOCK} Gold lockt Pokémon mit fünf\n"
                                "perfekten IVs an. Der Geschmack legt\n"
                                "fest, welcher IV nicht perfekt ist:\n"
                                "Scharf: ohne SP.A{CLEAR_TO 104}Trocken: ohne Ang\n"
                                "Süß: ohne SP.V{CLEAR_TO 104}Bitter: ohne Init\n"
                                "Sauer: ohne KP\n"
                                "Jeder {POKEBLOCK}: versteckte Fähigkeit."
                            ),
#else
        .header = COMPOUND_STRING("FEEDERS: GOLD POKéBLOCKS"),
        .desc = COMPOUND_STRING("GOLD POKéBLOCKS attract POKéMON with\n"
                                "5 perfect IVs. Flavor determines which\n"
                                "IV is not perfect.\n"
                                "SPICY: no SP.ATK    DRY:    no ATTACK\n"
                                "SWEET: no SP.DEF   BITTER: no SPEED\n"
                                "SOUR:  no HP\n"
                                "Every POKéBLOCK attracts HIDDEN ABILITY."
                            ),
#endif
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    // Add more entries
};
