// Radio station strings ported from pokecrystal
// Lines fit ~32 char width for 28-tile window

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// ==========================================================
// Station Names (displayed at top of radio UI)
// ==========================================================

#if GERMAN
static const u8 sRadioStationName_OaksPkmnTalk[]    = _("Pokémon-Talk");
#else
static const u8 sRadioStationName_OaksPkmnTalk[]    = _("OAK's POKéMON Talk");
#endif
#if GERMAN
static const u8 sRadioStationName_PokedexShow[]     = _("Pokédex-Show");
#else
static const u8 sRadioStationName_PokedexShow[]     = _("POKéDEX Show");
#endif
#if GERMAN
static const u8 sRadioStationName_PokemonMusic[]    = _("Pokémon-Musik");
#else
static const u8 sRadioStationName_PokemonMusic[]    = _("POKéMON Music");
#endif
#if GERMAN
static const u8 sRadioStationName_LuckyChannel[]    = _("Glückskanal");
#else
static const u8 sRadioStationName_LuckyChannel[]    = _("Lucky Channel");
#endif
#if GERMAN
static const u8 sRadioStationName_BuenasPassword[]  = _("Passwort mit Buena");
#else
static const u8 sRadioStationName_BuenasPassword[]  = _("BUENA'S PASSWORD");
#endif
static const u8 sRadioStationName_Unown[]           = _("?????");
#if GERMAN
static const u8 sRadioStationName_PlacesAndPeople[] = _("Orte und Personen");
#else
static const u8 sRadioStationName_PlacesAndPeople[] = _("Places & People");
#endif
#if GERMAN
static const u8 sRadioStationName_LetsAllSing[]     = _("Lasst uns singen!");
#else
static const u8 sRadioStationName_LetsAllSing[]     = _("Let's All Sing!");
#endif
#if GERMAN
static const u8 sRadioStationName_PokeFlute[]       = _("PokéFlöte");
#else
static const u8 sRadioStationName_PokeFlute[]       = _("POKé FLUTE");
#endif

// ==========================================================
// POKéDEX Show
// ==========================================================

#if GERMAN
static const u8 sRadioText_PokedexShow_Intro[] = _("Eichs Pokédex-Show!");
#else
static const u8 sRadioText_PokedexShow_Intro[] = _("OAK's POKéDEX SHOW!");
#endif
#if GERMAN
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("Eich: Heutiges Pokémon: ");
#else
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("OAK: Today's POKéMON is ");
#endif

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

#if GERMAN
static const u8 sRadioText_OPT_Intro[] = _("Margit: Prof. Eichs Pokémon-Talk!");
#else
static const u8 sRadioText_OPT_Intro[] = _("MARY: PROF.OAK's POKéMON TALK!");
#endif
#if GERMAN
static const u8 sRadioText_OPT_WithMeMary[] = _("Mit mir, Margit!");
#else
static const u8 sRadioText_OPT_WithMeMary[] = _("With me, MARY!");
#endif
#if GERMAN
static const u8 sRadioText_OPT_OakPrefix[] = _("Eich: ");
#else
static const u8 sRadioText_OPT_OakPrefix[] = _("OAK: ");
#endif
#if GERMAN
static const u8 sRadioText_OPT_SeenAround[] = _("wurde gesichtet bei");
#else
static const u8 sRadioText_OPT_SeenAround[] = _("may be seen around");
#endif
#if GERMAN
static const u8 sRadioText_OPT_MaryPrefix[] = _("Margit: ");
#else
static const u8 sRadioText_OPT_MaryPrefix[] = _("MARY: ");
#endif
#if GERMAN
static const u8 sRadioText_OPT_MaryIs[] = _(" ist ");
#else
static const u8 sRadioText_OPT_MaryIs[] = _("'s ");
#endif

// Pokemon Channel interlude
#if GERMAN
static const u8 sRadioText_OPT_PokemonChannel[] = _("Pokémon Kanal");
#else
static const u8 sRadioText_OPT_PokemonChannel[] = _("POKéMON Channel");
#endif

// Adverbs (randomly selected)
#if GERMAN
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("süß und bezaubernd");
#else
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("sweet and adorably");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("wackelig und clever");
#else
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("wiggly and slickly");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("passend benannt und");
#else
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("aptly named and");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("unbestreitbar irgendwie");
#else
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("undeniably kind of");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("so, so unerträglich");
#else
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("so, so unbearably");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("wow, beeindruckend");
#else
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("wow, impressively");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("fast schon giftig");
#else
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("almost poisonously");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("ooh, so sinnlich");
#else
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("ooh, so sensually");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("so verschmitzt");
#else
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("so mischievously");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("so sehr aktuell");
#else
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("so very topically");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("sicher süchtig machend");
#else
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("sure addictively");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("im Wasser sieht es");
#else
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("looks in water is");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("Entwicklung muss wohl");
#else
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("evolution must be");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("provokant");
#else
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("provocatively");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("so ausgeflippt und");
#else
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("so flipped out and");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("herzzerschmelzend");
#else
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("heart-meltingly");
#endif

static const u8 *const sRadioText_OPT_Adverbs[] =
{
    sRadioText_OPT_Adverb_SweetAdorably,
    sRadioText_OPT_Adverb_WigglySlickly,
    sRadioText_OPT_Adverb_AptlyNamed,
    sRadioText_OPT_Adverb_UndeniablyKindOf,
    sRadioText_OPT_Adverb_Unbearably,
    sRadioText_OPT_Adverb_WowImpressively,
    sRadioText_OPT_Adverb_AlmostPoisonously,
    sRadioText_OPT_Adverb_Sensually,
    sRadioText_OPT_Adverb_Mischievously,
    sRadioText_OPT_Adverb_Topically,
    sRadioText_OPT_Adverb_Addictively,
    sRadioText_OPT_Adverb_LooksInWater,
    sRadioText_OPT_Adverb_EvolutionMustBe,
    sRadioText_OPT_Adverb_Provocatively,
    sRadioText_OPT_Adverb_FlippedOut,
    sRadioText_OPT_Adverb_HeartMeltingly,
};

// Adjectives (randomly selected)
#if GERMAN
static const u8 sRadioText_OPT_Adj_Cute[]           = _("niedlich.");
#else
static const u8 sRadioText_OPT_Adj_Cute[]           = _("cute.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Weird[]          = _("seltsam.");
#else
static const u8 sRadioText_OPT_Adj_Weird[]          = _("weird.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("angenehm.");
#else
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("pleasant.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("irgendwie mutig.");
#else
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("bold, sort of.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("furchterregend.");
#else
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("frightening.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("smart & elegant!");
#else
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("suave & debonair!");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("kraftvoll.");
#else
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("powerful.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("aufregend.");
#else
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("exciting.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("abgefahren!");
#else
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("groovy!");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("inspirierend.");
#else
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("inspiring.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("freundlich.");
#else
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("friendly.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("heiß, heiß, heiß!");
#else
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("hot, hot, hot!");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("anregend.");
#else
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("stimulating.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("zurückhaltend.");
#else
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("guarded.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("bezaubernd.");
#else
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("lovely.");
#endif
#if GERMAN
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("flink.");
#else
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("speedy.");
#endif

static const u8 *const sRadioText_OPT_Adjectives[] =
{
    sRadioText_OPT_Adj_Cute,
    sRadioText_OPT_Adj_Weird,
    sRadioText_OPT_Adj_Pleasant,
    sRadioText_OPT_Adj_BoldSortOf,
    sRadioText_OPT_Adj_Frightening,
    sRadioText_OPT_Adj_SuaveDebonair,
    sRadioText_OPT_Adj_Powerful,
    sRadioText_OPT_Adj_Exciting,
    sRadioText_OPT_Adj_Groovy,
    sRadioText_OPT_Adj_Inspiring,
    sRadioText_OPT_Adj_Friendly,
    sRadioText_OPT_Adj_HotHotHot,
    sRadioText_OPT_Adj_Stimulating,
    sRadioText_OPT_Adj_Guarded,
    sRadioText_OPT_Adj_Lovely,
    sRadioText_OPT_Adj_Speedy,
};

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

#if GERMAN
static const u8 sRadioText_BenIntro[] = _("Ben: Pokémon Musik-Kanal!");
#else
static const u8 sRadioText_BenIntro[] = _("BEN: POKéMON MUSIC CHANNEL!");
#endif
#if GERMAN
static const u8 sRadioText_BenIntro2[] = _("Hier ist DJ Ben!");
#else
static const u8 sRadioText_BenIntro2[] = _("It's me, DJ BEN!");
#endif
#if GERMAN
static const u8 sRadioText_FernIntro[] = _("Fabian: PokéMusik!");
#else
static const u8 sRadioText_FernIntro[] = _("FERN: POKéMUSIC!");
#endif
#if GERMAN
static const u8 sRadioText_FernIntro2[] = _("Mit DJ Fabian!");
#else
static const u8 sRadioText_FernIntro2[] = _("With DJ FERN!");
#endif
// "Today's {DAY}," built dynamically
#if GERMAN
static const u8 sRadioText_BenFern_TodayIs[] = _("Heute ist ");
#else
static const u8 sRadioText_BenFern_TodayIs[] = _("Today's ");
#endif
#if GERMAN
static const u8 sRadioText_BenFern_JamTo[] = _("lasst uns abrocken zu");
#else
static const u8 sRadioText_BenFern_JamTo[] = _("so let us jam to");
#endif
#if GERMAN
static const u8 sRadioText_BenFern_ChillTo[] = _("entspannt euch bei");
#else
static const u8 sRadioText_BenFern_ChillTo[] = _("so chill out to");
#endif
#if GERMAN
static const u8 sRadioText_BenFern_March[] = _("Pokémon Marsch!");
#else
static const u8 sRadioText_BenFern_March[] = _("POKéMON March!");
#endif
#if GERMAN
static const u8 sRadioText_BenFern_Lullaby[] = _("Pokémon Schlaflied!");
#else
static const u8 sRadioText_BenFern_Lullaby[] = _("POKéMON Lullaby!");
#endif

// ==========================================================
// Lucky Channel
// ==========================================================

#if GERMAN
static const u8 sRadioText_LC1[] = _("Bastian: Yeehaw! Wie geht’s euch");
#else
static const u8 sRadioText_LC1[] = _("REED: Yeehaw! How y'all doin'");
#endif
#if GERMAN
static const u8 sRadioText_LC2[] = _("gerade? Ob hoch oben oder ganz");
#else
static const u8 sRadioText_LC2[] = _("now? Whether you're up or way");
#endif
#if GERMAN
static const u8 sRadioText_LC3[] = _("unten, verpasst bloß nicht die");
#else
static const u8 sRadioText_LC3[] = _("down low, don't you miss the");
#endif
#if GERMAN
static const u8 sRadioText_LC4[] = _("Glückszahlen-Show!");
#else
static const u8 sRadioText_LC4[] = _("LUCKY NUMBER SHOW!");
#endif
#if GERMAN
static const u8 sRadioText_LC5[] = _("Die heutige Glückszahl ist");
#else
static const u8 sRadioText_LC5[] = _("Today's Lucky Number is");
#endif
// "{number}!" built dynamically
#if GERMAN
static const u8 sRadioText_LC_Repeat[] = _("Ich wiederhole das!");
#else
static const u8 sRadioText_LC_Repeat[] = _("I'll repeat that!");
#endif
#if GERMAN
static const u8 sRadioText_LC_Match[] = _("Trefft sie und geht zum");
#else
static const u8 sRadioText_LC_Match[] = _("Match it and go to");
#endif
#if GERMAN
static const u8 sRadioText_LC_Tower[] = _("Radioturm!");
#else
static const u8 sRadioText_LC_Tower[] = _("the RADIO TOWER!");
#endif
#if GERMAN
static const u8 sRadioText_LC_Drag1[] = _("…Mich zu wiederholen");
#else
static const u8 sRadioText_LC_Drag1[] = _("…Repeating myself");
#endif
#if GERMAN
static const u8 sRadioText_LC_Drag2[] = _("wird echt anstrengend…");
#else
static const u8 sRadioText_LC_Drag2[] = _("gets to be a drag…");
#endif

// ==========================================================
// Places and People
// ==========================================================

#if GERMAN
static const u8 sRadioText_PnP_Intro[] = _("Orte und Personen! Präsentiert");
#else
static const u8 sRadioText_PnP_Intro[] = _("PLACES AND PEOPLE! Brought");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Intro2[] = _("von mir, DJ Lilly!");
#else
static const u8 sRadioText_PnP_Intro2[] = _("to you by me, DJ LILY!");
#endif
static const u8 sRadioText_PnP_Space[] = _(" ");

// People adjectives
#if GERMAN
static const u8 sRadioText_PnP_Cute[]       = _("ist niedlich.");
#else
static const u8 sRadioText_PnP_Cute[]       = _("is cute.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Lazy[]       = _("ist etwas faul.");
#else
static const u8 sRadioText_PnP_Lazy[]       = _("is sort of lazy.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Happy[]      = _("ist immer fröhlich.");
#else
static const u8 sRadioText_PnP_Happy[]      = _("is always happy.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Noisy[]      = _("ist ziemlich laut.");
#else
static const u8 sRadioText_PnP_Noisy[]      = _("is quite noisy.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Precocious[] = _("ist frühreif.");
#else
static const u8 sRadioText_PnP_Precocious[] = _("is precocious.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Bold[]       = _("ist etwas mutig.");
#else
static const u8 sRadioText_PnP_Bold[]       = _("is somewhat bold.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Picky[]      = _("ist zu wählerisch!");
#else
static const u8 sRadioText_PnP_Picky[]      = _("is too picky!");
#endif
#if GERMAN
static const u8 sRadioText_PnP_SortOfOK[]   = _("ist irgendwie ok.");
#else
static const u8 sRadioText_PnP_SortOfOK[]   = _("is sort of OK.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_SoSo[]       = _("ist einfach so lala.");
#else
static const u8 sRadioText_PnP_SoSo[]       = _("is just so-so.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Great[]       = _("ist eigentlich toll.");
#else
static const u8 sRadioText_PnP_Great[]       = _("is actually great.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_MyType[]      = _("ist genau mein Typ.");
#else
static const u8 sRadioText_PnP_MyType[]      = _("is just my type.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Cool[]        = _("ist so cool, oder?");
#else
static const u8 sRadioText_PnP_Cool[]        = _("is so cool, no?");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Inspiring[]   = _("ist inspirierend!");
#else
static const u8 sRadioText_PnP_Inspiring[]   = _("is inspiring!");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Weird[]       = _("ist irgendwie seltsam.");
#else
static const u8 sRadioText_PnP_Weird[]       = _("is kind of weird.");
#endif
#if GERMAN
static const u8 sRadioText_PnP_RightForMe[]  = _("ist genau richtig für mich?");
#else
static const u8 sRadioText_PnP_RightForMe[]  = _("is right for me?");
#endif
#if GERMAN
static const u8 sRadioText_PnP_Odd[]         = _("ist definitiv seltsam!");
#else
static const u8 sRadioText_PnP_Odd[]         = _("is definitely odd!");
#endif

static const u8 *const sRadioText_PnP_PeopleAdj[] =
{
    sRadioText_PnP_Cute,
    sRadioText_PnP_Lazy,
    sRadioText_PnP_Happy,
    sRadioText_PnP_Noisy,
    sRadioText_PnP_Precocious,
    sRadioText_PnP_Bold,
    sRadioText_PnP_Picky,
    sRadioText_PnP_SortOfOK,
    sRadioText_PnP_SoSo,
    sRadioText_PnP_Great,
    sRadioText_PnP_MyType,
    sRadioText_PnP_Cool,
    sRadioText_PnP_Inspiring,
    sRadioText_PnP_Weird,
    sRadioText_PnP_RightForMe,
    sRadioText_PnP_Odd,
};

// ==========================================================
// Rocket Radio
// ==========================================================

#if GERMAN
static const u8 sRadioStationName_Rocket[] = _("Team Rocket");
#else
static const u8 sRadioStationName_Rocket[] = _("TEAM ROCKET");
#endif
#if GERMAN
static const u8 sRadioText_Rocket1[]  = _("… …Ähem, wir sind");
#else
static const u8 sRadioText_Rocket1[]  = _("… …Ahem, we are");
#endif
#if GERMAN
static const u8 sRadioText_Rocket2[]  = _("Team Rocket!");
#else
static const u8 sRadioText_Rocket2[]  = _("TEAM ROCKET!");
#endif
#if GERMAN
static const u8 sRadioText_Rocket3[]  = _("Nach drei Jahren");
#else
static const u8 sRadioText_Rocket3[]  = _("After three years");
#endif
#if GERMAN
static const u8 sRadioText_Rocket4[]  = _("der Vorbereitung sind wir");
#else
static const u8 sRadioText_Rocket4[]  = _("of preparation, we");
#endif
#if GERMAN
static const u8 sRadioText_Rocket5[]  = _("wieder auferstanden");
#else
static const u8 sRadioText_Rocket5[]  = _("have risen again");
#endif
#if GERMAN
static const u8 sRadioText_Rocket6[]  = _("aus der Asche!");
#else
static const u8 sRadioText_Rocket6[]  = _("from the ashes!");
#endif
#if GERMAN
static const u8 sRadioText_Rocket7[]  = _("Giovanni!");
#else
static const u8 sRadioText_Rocket7[]  = _("GIOVANNI!");
#endif
#if GERMAN
static const u8 sRadioText_Rocket8[]  = _("Kannst du uns hören?");
#else
static const u8 sRadioText_Rocket8[]  = _("Can you hear?");
#endif
static const u8 sRadioText_Rocket9[]  = _("");
static const u8 sRadioText_Rocket10[] = _("");

// ==========================================================
// Buena's Password
// ==========================================================

#if GERMAN
static const u8 sRadioText_Buena1[] = _("Buena: Hier ist Buena!");
#else
static const u8 sRadioText_Buena1[] = _("BUENA: BUENA here!");
#endif
#if GERMAN
static const u8 sRadioText_Buena2[] = _("Das heutige Passwort!");
#else
static const u8 sRadioText_Buena2[] = _("Today's password!");
#endif
#if GERMAN
static const u8 sRadioText_Buena3[] = _("Moment… Es ist");
#else
static const u8 sRadioText_Buena3[] = _("Let me think… It's");
#endif
// "{password}!" built dynamically with STR_VAR_1
static const u8 sRadioText_Buena4[] = _("{STR_VAR_1}!");
#if GERMAN
static const u8 sRadioText_Buena5[] = _("Vergiss es nicht! Ich bin im");
#else
static const u8 sRadioText_Buena5[] = _("Don't forget it! I'm in");
#endif
#if GERMAN
static const u8 sRadioText_Buena6[] = _("Radioturm von Dukatia!");
#else
static const u8 sRadioText_Buena6[] = _("GOLDENROD's RADIO TOWER!");
#endif


// ==========================================================
// Buena's Password Categories & Options
// ==========================================================

#if GERMAN
static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("Neuborkia");
#else
static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("NEW BARK TOWN");
#endif
#if GERMAN
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("Rosalia");
#else
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("CHERRYGROVE CITY");
#endif
#if GERMAN
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("Azalea");
#else
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("AZALEA TOWN");
#endif
#if GERMAN
static const u8 sRadioBuenaPassword_Flying[]          = _("Flug");
#else
static const u8 sRadioBuenaPassword_Flying[]          = _("FLYING");
#endif
#if GERMAN
static const u8 sRadioBuenaPassword_Bug[]             = _("Käfer");
#else
static const u8 sRadioBuenaPassword_Bug[]             = _("BUG");
#endif
#if GERMAN
static const u8 sRadioBuenaPassword_Grass[]           = _("Pflanze");
#else
static const u8 sRadioBuenaPassword_Grass[]           = _("GRASS");
#endif
#if GERMAN
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("Pokémon Talk");
#else
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("POKéMON Talk");
#endif
#if GERMAN
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("Pokémon Musik");
#else
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("POKéMON Music");
#endif
#if GERMAN
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("Glückskanal");
#else
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("Lucky Channel");
#endif

// ==========================================================
// Oak's POKéMON Talk - Special Reports
// ==========================================================

#if GERMAN
static const u8 sOPT_Report_Clefairy_0[]  = _("Margit: Heute Nacht, ein seltener");
#else
static const u8 sOPT_Report_Clefairy_0[]  = _("MARY: Tonight, a rare moonlight");
#endif
#if GERMAN
static const u8 sOPT_Report_Clefairy_1[]  = _("Mondschein-Moment im Talk!");
#else
static const u8 sOPT_Report_Clefairy_1[]  = _("moment on POKéMON TALK!");
#endif
#if GERMAN
static const u8 sOPT_Report_Clefairy_2[]  = _("Eich: Wir rücken ins Licht:");
#else
static const u8 sOPT_Report_Clefairy_2[]  = _("OAK: We're spotlighting the");
#endif
#if GERMAN
static const u8 sOPT_Report_Clefairy_3[]  = _("das mystische Piepi!");
#else
static const u8 sOPT_Report_Clefairy_3[]  = _("mystical CLEFAIRY!");
#endif
#if GERMAN
static const u8 sOPT_Report_Clefairy_4[]  = _("Sie versammeln sich am");
#else
static const u8 sOPT_Report_Clefairy_4[]  = _("They gather at MT.MOON");
#endif
#if GERMAN
static const u8 sOPT_Report_Clefairy_5[]  = _("Mondberg bei Vollmond.");
#else
static const u8 sOPT_Report_Clefairy_5[]  = _("under full moons.");
#endif
#if GERMAN
static const u8 sOPT_Report_Clefairy_6[]  = _("Margit: Sie tanzen im Kreis!");
#else
static const u8 sOPT_Report_Clefairy_6[]  = _("MARY: They DANCE in circles!");
#endif
#if GERMAN
static const u8 sOPT_Report_Clefairy_7[]  = _("So niedlich seltsam!");
#else
static const u8 sOPT_Report_Clefairy_7[]  = _("So adorably weird!");
#endif
#if GERMAN
static const u8 sOPT_Report_Clefairy_8[]  = _("Eich: Ein zeitloses Rätsel");
#else
static const u8 sOPT_Report_Clefairy_8[]  = _("OAK: A timeless mystery");
#endif
#if GERMAN
static const u8 sOPT_Report_Clefairy_9[]  = _("und ein toller Anblick!");
#else
static const u8 sOPT_Report_Clefairy_9[]  = _("and a sight to behold!");
#endif

#if GERMAN
static const u8 sOPT_Report_Lapras_0[]  = _("Margit: Ein sanfter Riese");
#else
static const u8 sOPT_Report_Lapras_0[]  = _("MARY: A gentle giant takes");
#endif
#if GERMAN
static const u8 sOPT_Report_Lapras_1[]  = _("steht heute im Rampenlicht!");
#else
static const u8 sOPT_Report_Lapras_1[]  = _("the stage on today's show!");
#endif
#if GERMAN
static const u8 sOPT_Report_Lapras_2[]  = _("Eich: Es ist die Ozeanfähre,");
#else
static const u8 sOPT_Report_Lapras_2[]  = _("OAK: It's the ocean ferry,");
#endif
#if GERMAN
static const u8 sOPT_Report_Lapras_3[]  = _("unser geliebtes Lapras!");
#else
static const u8 sOPT_Report_Lapras_3[]  = _("our beloved LAPRAS!");
#endif
#if GERMAN
static const u8 sOPT_Report_Lapras_4[]  = _("Gesehen im Einheitstunnel,");
#else
static const u8 sOPT_Report_Lapras_4[]  = _("Seen in UNION CAVE, but only");
#endif
#if GERMAN
static const u8 sOPT_Report_Lapras_5[]  = _("nur abends. Wie kurios!");
#else
static const u8 sOPT_Report_Lapras_5[]  = _("on Evenings. How curious!");
#endif
#if GERMAN
static const u8 sOPT_Report_Lapras_6[]  = _("Margit: So selten und friedlich!");
#else
static const u8 sOPT_Report_Lapras_6[]  = _("MARY: So rare and peaceful!");
#endif
#if GERMAN
static const u8 sOPT_Report_Lapras_7[]  = _("Und es singt auch noch!");
#else
static const u8 sOPT_Report_Lapras_7[]  = _("And it sings, too!");
#endif
#if GERMAN
static const u8 sOPT_Report_Lapras_8[]  = _("Eich: Manche sagen, sein Lied");
#else
static const u8 sOPT_Report_Lapras_8[]  = _("OAK: Some say its songs calm");
#endif
#if GERMAN
static const u8 sOPT_Report_Lapras_9[]  = _("beruhigt die Seele des Meeres.");
#else
static const u8 sOPT_Report_Lapras_9[]  = _("the soul of the sea.");
#endif

#if GERMAN
static const u8 sOPT_Report_Ampharos_0[]  = _("Margit: Willkommen zurück, Leute!");
#else
static const u8 sOPT_Report_Ampharos_0[]  = _("MARY: Welcome back, everyone!");
#endif
#if GERMAN
static const u8 sOPT_Report_Ampharos_1[]  = _("Zeit für Pokémon Talk!");
#else
static const u8 sOPT_Report_Ampharos_1[]  = _("Time for POKéMON TALK!");
#endif
#if GERMAN
static const u8 sOPT_Report_Ampharos_2[]  = _("Eich: Bringen wir Licht ins");
#else
static const u8 sOPT_Report_Ampharos_2[]  = _("OAK: Let's shine a light on");
#endif
#if GERMAN
static const u8 sOPT_Report_Ampharos_3[]  = _("Dunkel: Ampharos!");
#else
static const u8 sOPT_Report_Ampharos_3[]  = _("our friend AMPHAROS!");
#endif
#if GERMAN
static const u8 sOPT_Report_Ampharos_4[]  = _("Sein heller Schwanz leuchtet");
#else
static const u8 sOPT_Report_Ampharos_4[]  = _("Its bright tail glows through");
#endif
#if GERMAN
static const u8 sOPT_Report_Ampharos_5[]  = _("durch Nebel für Verirrte.");
#else
static const u8 sOPT_Report_Ampharos_5[]  = _("fog to guide lost folks.");
#endif
#if GERMAN
static const u8 sOPT_Report_Ampharos_6[]  = _("Margit: Kraftvoll, elegant,");
#else
static const u8 sOPT_Report_Ampharos_6[]  = _("MARY: Powerful, elegant,");
#endif
#if GERMAN
static const u8 sOPT_Report_Ampharos_7[]  = _("und unbestreitbar freundlich!");
#else
static const u8 sOPT_Report_Ampharos_7[]  = _("and undeniably friendly!");
#endif
#if GERMAN
static const u8 sOPT_Report_Ampharos_8[]  = _("Eich: Ein wichtiger Teil");
#else
static const u8 sOPT_Report_Ampharos_8[]  = _("OAK: A key part of many");
#endif
#if GERMAN
static const u8 sOPT_Report_Ampharos_9[]  = _("vieler Leuchtturm-Geschichten!");
#else
static const u8 sOPT_Report_Ampharos_9[]  = _("lighthouse stories!");
#endif

#if GERMAN
static const u8 sOPT_Report_Sudowoodo_0[]  = _("Margit: Als Nächstes, ein echter");
#else
static const u8 sOPT_Report_Sudowoodo_0[]  = _("MARY: Up next, a real oddball");
#endif
#if GERMAN
static const u8 sOPT_Report_Sudowoodo_1[]  = _("Sonderling auf Route 36...");
#else
static const u8 sOPT_Report_Sudowoodo_1[]  = _("on ROUTE 36...");
#endif
#if GERMAN
static const u8 sOPT_Report_Sudowoodo_2[]  = _("Eich: Mogelbaum! Sieht aus wie");
#else
static const u8 sOPT_Report_Sudowoodo_2[]  = _("OAK: SUDOWOODO! Looks like a");
#endif
#if GERMAN
static const u8 sOPT_Report_Sudowoodo_3[]  = _("ein Baum, ist aber keiner!");
#else
static const u8 sOPT_Report_Sudowoodo_3[]  = _("tree, but isn't one!");
#endif
#if GERMAN
static const u8 sOPT_Report_Sudowoodo_4[]  = _("Es blockiert den Weg und");
#else
static const u8 sOPT_Report_Sudowoodo_4[]  = _("It blocks the road and won't");
#endif
#if GERMAN
static const u8 sOPT_Report_Sudowoodo_5[]  = _("rührt sich ohne Wasser nicht.");
#else
static const u8 sOPT_Report_Sudowoodo_5[]  = _("budge without water.");
#endif
#if GERMAN
static const u8 sOPT_Report_Sudowoodo_6[]  = _("Margit: Es reagiert nur auf");
#else
static const u8 sOPT_Report_Sudowoodo_6[]  = _("MARY: It only reacts to a");
#endif
#if GERMAN
static const u8 sOPT_Report_Sudowoodo_7[]  = _("die Schiggykanne!");
#else
static const u8 sOPT_Report_Sudowoodo_7[]  = _("SQUIRTBOTTLE!");
#endif
#if GERMAN
static const u8 sOPT_Report_Sudowoodo_8[]  = _("Eich: Das ist kein Busch,");
#else
static const u8 sOPT_Report_Sudowoodo_8[]  = _("OAK: That's no bush, it's a");
#endif
#if GERMAN
static const u8 sOPT_Report_Sudowoodo_9[]  = _("sondern Gestein im Tarnmodus!");
#else
static const u8 sOPT_Report_Sudowoodo_9[]  = _("ROCK-type in disguise!");
#endif

#if GERMAN
static const u8 sOPT_Report_RedGyarados_0[]  = _("Margit: Die heutige Story ist");
#else
static const u8 sOPT_Report_RedGyarados_0[]  = _("MARY: Today's story is a");
#endif
#if GERMAN
static const u8 sOPT_Report_RedGyarados_1[]  = _("schockierend, aus Johto!");
#else
static const u8 sOPT_Report_RedGyarados_1[]  = _("shocking one from JOHTO!");
#endif
#if GERMAN
static const u8 sOPT_Report_RedGyarados_2[]  = _("Eich: Trainer sahen einen");
#else
static const u8 sOPT_Report_RedGyarados_2[]  = _("OAK: Trainers spotted a RED");
#endif
#if GERMAN
static const u8 sOPT_Report_RedGyarados_3[]  = _("Roten Garados am See des Zorns!");
#else
static const u8 sOPT_Report_RedGyarados_3[]  = _("GYARADOS at LAKE OF RAGE!");
#endif
#if GERMAN
static const u8 sOPT_Report_RedGyarados_4[]  = _("Anders als die üblichen");
#else
static const u8 sOPT_Report_RedGyarados_4[]  = _("Unlike the usual blue ones,");
#endif
#if GERMAN
static const u8 sOPT_Report_RedGyarados_5[]  = _("blauen, ist dieser knallrot!");
#else
static const u8 sOPT_Report_RedGyarados_5[]  = _("this one's bright crimson!");
#endif
#if GERMAN
static const u8 sOPT_Report_RedGyarados_6[]  = _("Margit: Man sagt, es hängt mit");
#else
static const u8 sOPT_Report_RedGyarados_6[]  = _("MARY: People say it's linked");
#endif
#if GERMAN
static const u8 sOPT_Report_RedGyarados_7[]  = _("seltsamen Radiowellen zusammen!");
#else
static const u8 sOPT_Report_RedGyarados_7[]  = _("to some strange radio waves!");
#endif
#if GERMAN
static const u8 sOPT_Report_RedGyarados_8[]  = _("Eich: Eine mysteriöse");
#else
static const u8 sOPT_Report_RedGyarados_8[]  = _("OAK: A mysterious evolution…");
#endif
#if GERMAN
static const u8 sOPT_Report_RedGyarados_9[]  = _("Entwicklung… Unnatürlich.");
#else
static const u8 sOPT_Report_RedGyarados_9[]  = _("Possibly unnatural.");
#endif

#if GERMAN
static const u8 sOPT_Report_Unown_0[]  = _("Margit: Wart ihr schon mal in den");
#else
static const u8 sOPT_Report_Unown_0[]  = _("MARY: Ever visited the RUINS");
#endif
#if GERMAN
static const u8 sOPT_Report_Unown_1[]  = _("Alph-Ruinen? Gruselig!");
#else
static const u8 sOPT_Report_Unown_1[]  = _("OF ALPH? Spooky stuff!");
#endif
#if GERMAN
static const u8 sOPT_Report_Unown_2[]  = _("Eich: Seltsame Symbole zieren");
#else
static const u8 sOPT_Report_Unown_2[]  = _("OAK: Strange symbols line the");
#endif
#if GERMAN
static const u8 sOPT_Report_Unown_3[]  = _("die Wände, wie alte Runen.");
#else
static const u8 sOPT_Report_Unown_3[]  = _("walls, like ancient runes.");
#endif
#if GERMAN
static const u8 sOPT_Report_Unown_4[]  = _("Drinnen findet ihr Icognito…");
#else
static const u8 sOPT_Report_Unown_4[]  = _("Inside, you'll find UNOWN…");
#endif
#if GERMAN
static const u8 sOPT_Report_Unown_5[]  = _("jedes wie ein Buchstabe!");
#else
static const u8 sOPT_Report_Unown_5[]  = _("each shaped like letters!");
#endif
#if GERMAN
static const u8 sOPT_Report_Unown_6[]  = _("Margit: Sie buchstabieren Dinge,");
#else
static const u8 sOPT_Report_Unown_6[]  = _("MARY: They spell things,");
#endif
#if GERMAN
static const u8 sOPT_Report_Unown_7[]  = _("vielleicht? Gruseln uns nur!");
#else
static const u8 sOPT_Report_Unown_7[]  = _("maybe? Or just freak us out!");
#endif
#if GERMAN
static const u8 sOPT_Report_Unown_8[]  = _("Eich: Ein echtes Rätsel der");
#else
static const u8 sOPT_Report_Unown_8[]  = _("OAK: A true puzzle of nature,");
#endif
#if GERMAN
static const u8 sOPT_Report_Unown_9[]  = _("Natur, bis heute ungelöst.");
#else
static const u8 sOPT_Report_Unown_9[]  = _("still unsolved to this day.");
#endif

#if GERMAN
static const u8 sOPT_Report_Snubbull_0[]  = _("Margit: Bewohner von Dukatia City");
#else
static const u8 sOPT_Report_Snubbull_0[]  = _("MARY: GOLDENROD residents are");
#endif
#if GERMAN
static const u8 sOPT_Report_Snubbull_1[]  = _("suchen überall verzweifelt!");
#else
static const u8 sOPT_Report_Snubbull_1[]  = _("searching high and low!");
#endif
#if GERMAN
static const u8 sOPT_Report_Snubbull_2[]  = _("Eich: Ein Snubbull ist");
#else
static const u8 sOPT_Report_Snubbull_2[]  = _("OAK: A SNUBBULL has gone rogue");
#endif
#if GERMAN
static const u8 sOPT_Report_Snubbull_3[]  = _("abtrünnig und auf der Flucht!");
#else
static const u8 sOPT_Report_Snubbull_3[]  = _("and is on the run!");
#endif
#if GERMAN
static const u8 sOPT_Report_Snubbull_4[]  = _("Normalerweise scheu und");
#else
static const u8 sOPT_Report_Snubbull_4[]  = _("Usually shy and fussy, it's");
#endif
#if GERMAN
static const u8 sOPT_Report_Snubbull_5[]  = _("zickig, gesichtet am Bahnhof.");
#else
static const u8 sOPT_Report_Snubbull_5[]  = _("been seen near the station.");
#endif
#if GERMAN
static const u8 sOPT_Report_Snubbull_6[]  = _("Margit: Vielleicht jagt es");
#else
static const u8 sOPT_Report_Snubbull_6[]  = _("MARY: Maybe it's chasing");
#endif
#if GERMAN
static const u8 sOPT_Report_Snubbull_7[]  = _("der Liebe… oder Abenteuern!");
#else
static const u8 sOPT_Report_Snubbull_7[]  = _("love… or just adventure!");
#endif
#if GERMAN
static const u8 sOPT_Report_Snubbull_8[]  = _("Eich: Haltet die Augen offen,");
#else
static const u8 sOPT_Report_Snubbull_8[]  = _("OAK: Keep your eyes peeled,");
#endif
#if GERMAN
static const u8 sOPT_Report_Snubbull_9[]  = _("und die Leine bereit.");
#else
static const u8 sOPT_Report_Snubbull_9[]  = _("and your leash ready.");
#endif

#if GERMAN
static const u8 sOPT_Report_Slowpoke_0[]  = _("Margit: Große News aus Azalea City");
#else
static const u8 sOPT_Report_Slowpoke_0[]  = _("MARY: Big news from AZALEA");
#endif
#if GERMAN
static const u8 sOPT_Report_Slowpoke_1[]  = _("diese Woche!");
#else
static const u8 sOPT_Report_Slowpoke_1[]  = _("TOWN this week!");
#endif
#if GERMAN
static const u8 sOPT_Report_Slowpoke_2[]  = _("Eich: Flegmon sind zu ihrem");
#else
static const u8 sOPT_Report_Slowpoke_2[]  = _("OAK: SLOWPOKE have returned");
#endif
#if GERMAN
static const u8 sOPT_Report_Slowpoke_3[]  = _("Brunnen zurückgekehrt!");
#else
static const u8 sOPT_Report_Slowpoke_3[]  = _("to their well after a crisis!");
#endif
#if GERMAN
static const u8 sOPT_Report_Slowpoke_4[]  = _("Team Rocket hatte ihnen");
#else
static const u8 sOPT_Report_Slowpoke_4[]  = _("TEAM ROCKET had been cutting");
#endif
#if GERMAN
static const u8 sOPT_Report_Slowpoke_5[]  = _("die Schwänze abgeschnitten!");
#else
static const u8 sOPT_Report_Slowpoke_5[]  = _("off their tails! Horrible!");
#endif
#if GERMAN
static const u8 sOPT_Report_Slowpoke_6[]  = _("Margit: Doch ein mutiger");
#else
static const u8 sOPT_Report_Slowpoke_6[]  = _("MARY: But a brave young");
#endif
#if GERMAN
static const u8 sOPT_Report_Slowpoke_7[]  = _("junger Trainer stoppte sie!");
#else
static const u8 sOPT_Report_Slowpoke_7[]  = _("trainer shut them down!");
#endif
#if GERMAN
static const u8 sOPT_Report_Slowpoke_8[]  = _("Eich: Die Flegmon sind");
#else
static const u8 sOPT_Report_Slowpoke_8[]  = _("OAK: The SLOWPOKE are safe");
#endif
#if GERMAN
static const u8 sOPT_Report_Slowpoke_9[]  = _("sicher und dösen wieder.");
#else
static const u8 sOPT_Report_Slowpoke_9[]  = _("and happily dozing again.");
#endif

#if GERMAN
static const u8 sOPT_Report_LavenderTower_0[]  = _("Margit: Lavandias Turm hat");
#else
static const u8 sOPT_Report_LavenderTower_0[]  = _("MARY: LAVENDER TOWN's tower");
#endif
#if GERMAN
static const u8 sOPT_Report_LavenderTower_1[]  = _("sich verändert!");
#else
static const u8 sOPT_Report_LavenderTower_1[]  = _("has changed tunes!");
#endif
#if GERMAN
static const u8 sOPT_Report_LavenderTower_2[]  = _("Eich: Der alte Geisterturm");
#else
static const u8 sOPT_Report_LavenderTower_2[]  = _("OAK: The old ghost tower is");
#endif
#if GERMAN
static const u8 sOPT_Report_LavenderTower_3[]  = _("ist jetzt ein Radiosender!");
#else
static const u8 sOPT_Report_LavenderTower_3[]  = _("now a RADIO STATION!");
#endif
#if GERMAN
static const u8 sOPT_Report_LavenderTower_4[]  = _("Manche Anwohner sagen, er");
#else
static const u8 sOPT_Report_LavenderTower_4[]  = _("Some locals say it still");
#endif
#if GERMAN
static const u8 sOPT_Report_LavenderTower_5[]  = _("fühlt sich… gruselig an.");
#else
static const u8 sOPT_Report_LavenderTower_5[]  = _("feels… spooky.");
#endif
#if GERMAN
static const u8 sOPT_Report_LavenderTower_6[]  = _("Margit: Ich schwöre, ich sah");
#else
static const u8 sOPT_Report_LavenderTower_6[]  = _("MARY: I swear I saw a GASTLY");
#endif
#if GERMAN
static const u8 sOPT_Report_LavenderTower_7[]  = _("ein Nebulak an der Kabine!");
#else
static const u8 sOPT_Report_LavenderTower_7[]  = _("near the mic booth!");
#endif
#if GERMAN
static const u8 sOPT_Report_LavenderTower_8[]  = _("Eich: Könnte Rauschen sein…");
#else
static const u8 sOPT_Report_LavenderTower_8[]  = _("OAK: Might be static…");
#endif
#if GERMAN
static const u8 sOPT_Report_LavenderTower_9[]  = _("oder Gespenster!");
#else
static const u8 sOPT_Report_LavenderTower_9[]  = _("or specters!");
#endif

#if GERMAN
static const u8 sOPT_Report_Tentacruel_0[]  = _("Margit: Seltsame News von den");
#else
static const u8 sOPT_Report_Tentacruel_0[]  = _("MARY: Weird news from the");
#endif
#if GERMAN
static const u8 sOPT_Report_Tentacruel_1[]  = _("Strudelinseln heute!");
#else
static const u8 sOPT_Report_Tentacruel_1[]  = _("WHIRL ISLANDS today!");
#endif
#if GERMAN
static const u8 sOPT_Report_Tentacruel_2[]  = _("Eich: Tentoxa umgeben");
#else
static const u8 sOPT_Report_Tentacruel_2[]  = _("OAK: TENTACRUEL have been");
#endif
#if GERMAN
static const u8 sOPT_Report_Tentacruel_3[]  = _("die Höhleneingänge!");
#else
static const u8 sOPT_Report_Tentacruel_3[]  = _("surrounding cave entrances!");
#endif
#if GERMAN
static const u8 sOPT_Report_Tentacruel_4[]  = _("Sie sind riesig und wirken");
#else
static const u8 sOPT_Report_Tentacruel_4[]  = _("They're massive, and acting");
#endif
#if GERMAN
static const u8 sOPT_Report_Tentacruel_5[]  = _("fast schon territorial.");
#else
static const u8 sOPT_Report_Tentacruel_5[]  = _("almost territorial.");
#endif
#if GERMAN
static const u8 sOPT_Report_Tentacruel_6[]  = _("Margit: Sie blockieren den Weg");
#else
static const u8 sOPT_Report_Tentacruel_6[]  = _("MARY: They block the way");
#endif
#if GERMAN
static const u8 sOPT_Report_Tentacruel_7[]  = _("ohne anzugreifen…");
#else
static const u8 sOPT_Report_Tentacruel_7[]  = _("without attacking…");
#endif
#if GERMAN
static const u8 sOPT_Report_Tentacruel_8[]  = _("Eich: Als würden sie etwas");
#else
static const u8 sOPT_Report_Tentacruel_8[]  = _("OAK: As if guarding something");
#endif
#if GERMAN
static const u8 sOPT_Report_Tentacruel_9[]  = _("tief unter den Wellen bewachen.");
#else
static const u8 sOPT_Report_Tentacruel_9[]  = _("deep beneath the waves.");
#endif

#define OPT_REPORT_LINES 10

// Origin Jade: report ids for the region and story gates in IsOPTReportAvailable.
enum
{
    OPT_REPORT_CLEFAIRY,
    OPT_REPORT_LAPRAS,
    OPT_REPORT_AMPHAROS,
    OPT_REPORT_SUDOWOODO,
    OPT_REPORT_RED_GYARADOS,
    OPT_REPORT_UNOWN,
    OPT_REPORT_SNUBBULL,
    OPT_REPORT_SLOWPOKE,
    OPT_REPORT_LAVENDER_TOWER,
    OPT_REPORT_TENTACRUEL,
    NUM_OPT_REPORTS,
};

static const u8 *const sOPT_Reports[NUM_OPT_REPORTS][OPT_REPORT_LINES] =
{
    [OPT_REPORT_CLEFAIRY] = { sOPT_Report_Clefairy_0, sOPT_Report_Clefairy_1, sOPT_Report_Clefairy_2, sOPT_Report_Clefairy_3, sOPT_Report_Clefairy_4, sOPT_Report_Clefairy_5, sOPT_Report_Clefairy_6, sOPT_Report_Clefairy_7, sOPT_Report_Clefairy_8, sOPT_Report_Clefairy_9 },
    [OPT_REPORT_LAPRAS] = { sOPT_Report_Lapras_0, sOPT_Report_Lapras_1, sOPT_Report_Lapras_2, sOPT_Report_Lapras_3, sOPT_Report_Lapras_4, sOPT_Report_Lapras_5, sOPT_Report_Lapras_6, sOPT_Report_Lapras_7, sOPT_Report_Lapras_8, sOPT_Report_Lapras_9 },
    [OPT_REPORT_AMPHAROS] = { sOPT_Report_Ampharos_0, sOPT_Report_Ampharos_1, sOPT_Report_Ampharos_2, sOPT_Report_Ampharos_3, sOPT_Report_Ampharos_4, sOPT_Report_Ampharos_5, sOPT_Report_Ampharos_6, sOPT_Report_Ampharos_7, sOPT_Report_Ampharos_8, sOPT_Report_Ampharos_9 },
    [OPT_REPORT_SUDOWOODO] = { sOPT_Report_Sudowoodo_0, sOPT_Report_Sudowoodo_1, sOPT_Report_Sudowoodo_2, sOPT_Report_Sudowoodo_3, sOPT_Report_Sudowoodo_4, sOPT_Report_Sudowoodo_5, sOPT_Report_Sudowoodo_6, sOPT_Report_Sudowoodo_7, sOPT_Report_Sudowoodo_8, sOPT_Report_Sudowoodo_9 },
    [OPT_REPORT_RED_GYARADOS] = { sOPT_Report_RedGyarados_0, sOPT_Report_RedGyarados_1, sOPT_Report_RedGyarados_2, sOPT_Report_RedGyarados_3, sOPT_Report_RedGyarados_4, sOPT_Report_RedGyarados_5, sOPT_Report_RedGyarados_6, sOPT_Report_RedGyarados_7, sOPT_Report_RedGyarados_8, sOPT_Report_RedGyarados_9 },
    [OPT_REPORT_UNOWN] = { sOPT_Report_Unown_0, sOPT_Report_Unown_1, sOPT_Report_Unown_2, sOPT_Report_Unown_3, sOPT_Report_Unown_4, sOPT_Report_Unown_5, sOPT_Report_Unown_6, sOPT_Report_Unown_7, sOPT_Report_Unown_8, sOPT_Report_Unown_9 },
    [OPT_REPORT_SNUBBULL] = { sOPT_Report_Snubbull_0, sOPT_Report_Snubbull_1, sOPT_Report_Snubbull_2, sOPT_Report_Snubbull_3, sOPT_Report_Snubbull_4, sOPT_Report_Snubbull_5, sOPT_Report_Snubbull_6, sOPT_Report_Snubbull_7, sOPT_Report_Snubbull_8, sOPT_Report_Snubbull_9 },
    [OPT_REPORT_SLOWPOKE] = { sOPT_Report_Slowpoke_0, sOPT_Report_Slowpoke_1, sOPT_Report_Slowpoke_2, sOPT_Report_Slowpoke_3, sOPT_Report_Slowpoke_4, sOPT_Report_Slowpoke_5, sOPT_Report_Slowpoke_6, sOPT_Report_Slowpoke_7, sOPT_Report_Slowpoke_8, sOPT_Report_Slowpoke_9 },
    [OPT_REPORT_LAVENDER_TOWER] = { sOPT_Report_LavenderTower_0, sOPT_Report_LavenderTower_1, sOPT_Report_LavenderTower_2, sOPT_Report_LavenderTower_3, sOPT_Report_LavenderTower_4, sOPT_Report_LavenderTower_5, sOPT_Report_LavenderTower_6, sOPT_Report_LavenderTower_7, sOPT_Report_LavenderTower_8, sOPT_Report_LavenderTower_9 },
    [OPT_REPORT_TENTACRUEL] = { sOPT_Report_Tentacruel_0, sOPT_Report_Tentacruel_1, sOPT_Report_Tentacruel_2, sOPT_Report_Tentacruel_3, sOPT_Report_Tentacruel_4, sOPT_Report_Tentacruel_5, sOPT_Report_Tentacruel_6, sOPT_Report_Tentacruel_7, sOPT_Report_Tentacruel_8, sOPT_Report_Tentacruel_9 },
};

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
