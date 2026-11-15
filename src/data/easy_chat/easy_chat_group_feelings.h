const u8 gEasyChatWord_Meet[] = _("MEET");
const u8 gEasyChatWord_Play[] = _("PLAY");
const u8 gEasyChatWord_Hurried[] = _("HURRIED");
const u8 gEasyChatWord_Goes[] = _("GOES");
const u8 gEasyChatWord_Giddy[] = _("GIDDY");
const u8 gEasyChatWord_Happy[] = _("HAPPY");
const u8 gEasyChatWord_Happiness[] = _("HAPPINESS");
const u8 gEasyChatWord_Excite[] = _("EXCITE");
const u8 gEasyChatWord_Important[] = _("IMPORTANT");
const u8 gEasyChatWord_Funny[] = _("FUNNY");
const u8 gEasyChatWord_Got[] = _("GOT");
const u8 gEasyChatWord_GoHome[] = _("GO HOME");
const u8 gEasyChatWord_Disappointed[] = _("DISAPPOINTED");
const u8 gEasyChatWord_Disappoints[] = _("DISAPPOINTS");
const u8 gEasyChatWord_Sad[] = _("SAD");
const u8 gEasyChatWord_Try[] = _("TRY");
const u8 gEasyChatWord_Tries[] = _("TRIES");
const u8 gEasyChatWord_Hears[] = _("HEARS");
const u8 gEasyChatWord_Think[] = _("THINK");
const u8 gEasyChatWord_Hear[] = _("HEAR");
const u8 gEasyChatWord_Wants[] = _("WANTS");
const u8 gEasyChatWord_Misheard[] = _("MISHEARD");
const u8 gEasyChatWord_Dislike[] = _("DISLIKE");
const u8 gEasyChatWord_Angry[] = _("ANGRY");
const u8 gEasyChatWord_Anger[] = _("ANGER");
const u8 gEasyChatWord_Scary[] = _("SCARY");
const u8 gEasyChatWord_Lonesome[] = _("LONESOME");
const u8 gEasyChatWord_Disappoint[] = _("DISAPPOINT");
const u8 gEasyChatWord_Joy[] = _("JOY");
const u8 gEasyChatWord_Gets[] = _("GETS");
const u8 gEasyChatWord_Never[] = _("NEVER");
const u8 gEasyChatWord_Darn[] = _("DARN");
const u8 gEasyChatWord_Downcast[] = _("DOWNCAST");
const u8 gEasyChatWord_Incredible[] = _("INCREDIBLE");
const u8 gEasyChatWord_Likes[] = _("LIKES");
const u8 gEasyChatWord_Dislikes[] = _("DISLIKES");
const u8 gEasyChatWord_Boring[] = _("BORING");
const u8 gEasyChatWord_Care[] = _("CARE");
const u8 gEasyChatWord_Cares[] = _("CARES");
const u8 gEasyChatWord_AllRight[] = _("ALL RIGHT");
const u8 gEasyChatWord_Adore[] = _("ADORE");
const u8 gEasyChatWord_Disaster[] = _("DISASTER");
const u8 gEasyChatWord_Enjoy[] = _("ENJOY");
const u8 gEasyChatWord_Enjoys[] = _("ENJOYS");
const u8 gEasyChatWord_Eat[] = _("EAT");
const u8 gEasyChatWord_Lacking[] = _("LACKING");
const u8 gEasyChatWord_Bad[] = _("BAD");
const u8 gEasyChatWord_Hard[] = _("HARD");
const u8 gEasyChatWord_Terrible[] = _("TERRIBLE");
const u8 gEasyChatWord_Should[] = _("SHOULD");
const u8 gEasyChatWord_Nice[] = _("NICE");
const u8 gEasyChatWord_Drink[] = _("DRINK");
const u8 gEasyChatWord_Surprise[] = _("SURPRISE");
const u8 gEasyChatWord_Fear[] = _("FEAR");
const u8 gEasyChatWord_Want[] = _("WANT");
const u8 gEasyChatWord_Wait[] = _("WAIT");
const u8 gEasyChatWord_Satisfied[] = _("SATISFIED");
const u8 gEasyChatWord_See[] = _("SEE");
const u8 gEasyChatWord_Rare[] = _("RARE");
const u8 gEasyChatWord_Negative[] = _("NEGATIVE");
const u8 gEasyChatWord_Done[] = _("DONE");
const u8 gEasyChatWord_Danger[] = _("DANGER");
const u8 gEasyChatWord_Defeated[] = _("DEFEATED");
const u8 gEasyChatWord_Beat[] = _("BEAT");
const u8 gEasyChatWord_Great[] = _("GREAT");
const u8 gEasyChatWord_Romantic[] = _("ROMANTIC");
const u8 gEasyChatWord_Question[] = _("QUESTION");
const u8 gEasyChatWord_Understand[] = _("UNDERSTAND");
const u8 gEasyChatWord_Understands[] = _("UNDERSTANDS");

const struct EasyChatWordInfo gEasyChatGroup_Feelings[] = {
    [EC_INDEX(EC_WORD_MEET)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Weinen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISLIKES),
#else
        .text = COMPOUND_STRING("MEET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ADORE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Spielen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCITE),
#else
        .text = COMPOUND_STRING("PLAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALL_RIGHT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HURRIED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Eilig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GETS),
#else
        .text = COMPOUND_STRING("HURRIED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANGER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEFEATED),
#else
        .text = COMPOUND_STRING("GOES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANGRY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIDDY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schwindelig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISASTER),
#else
        .text = COMPOUND_STRING("GIDDY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BAD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Glücklich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HURRIED),
#else
        .text = COMPOUND_STRING("HAPPY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEAT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPINESS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Glück"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LONESOME),
#else
        .text = COMPOUND_STRING("HAPPINESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BORING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCITE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Begeistern"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOWNCAST),
#else
        .text = COMPOUND_STRING("EXCITE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CARE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IMPORTANT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wichtig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPOINTS),
#else
        .text = COMPOUND_STRING("IMPORTANT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CARES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FUNNY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lustig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPOINTED),
#else
        .text = COMPOUND_STRING("FUNNY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DANGER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Haben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EAT),
#else
        .text = COMPOUND_STRING("GOT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DARN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_HOME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Heimgehen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DONE),
#else
        .text = COMPOUND_STRING("GO HOME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEFEATED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPOINTED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Enttäuscht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUESTION),
#else
        .text = COMPOUND_STRING("DISAPPOINTED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPOINT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPOINTS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Enttäuschen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JOY),
#else
        .text = COMPOUND_STRING("DISAPPOINTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPOINTED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Traurig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINK),
#else
        .text = COMPOUND_STRING("SAD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPOINTS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unzufrieden"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPOINT),
#else
        .text = COMPOUND_STRING("TRY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISASTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRIES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Versucht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEAR),
#else
        .text = COMPOUND_STRING("TRIES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISLIKE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEARS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gute laune"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DANGER),
#else
        .text = COMPOUND_STRING("HEARS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISLIKES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fröhlich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOES),
#else
        .text = COMPOUND_STRING("THINK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DONE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEAR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hören"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENJOY),
#else
        .text = COMPOUND_STRING("HEAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOWNCAST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANTS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Will"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENJOYS),
#else
        .text = COMPOUND_STRING("WANTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRINK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISHEARD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verhört"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPINESS),
#else
        .text = COMPOUND_STRING("MISHEARD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EAT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISLIKE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nicht mögen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPY),
#else
        .text = COMPOUND_STRING("DISLIKE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENJOY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANGRY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wütend"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GREAT),
#else
        .text = COMPOUND_STRING("ANGRY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENJOYS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANGER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wut"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALL_RIGHT),
#else
        .text = COMPOUND_STRING("ANGER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCITE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCARY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unheimlich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEARS),
#else
        .text = COMPOUND_STRING("SCARY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEAR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LONESOME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Einsam"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOT),
#else
        .text = COMPOUND_STRING("LONESOME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FUNNY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPOINT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Frustriert"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO_HOME),
#else
        .text = COMPOUND_STRING("DISAPPOINT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GETS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JOY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Freude"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEAR),
#else
        .text = COMPOUND_STRING("JOY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIDDY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GETS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bekommt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEE),
#else
        .text = COMPOUND_STRING("GETS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO_HOME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEVER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAIT),
#else
        .text = COMPOUND_STRING("NEVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DARN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verdammt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BORING),
#else
        .text = COMPOUND_STRING("DARN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOWNCAST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Entmutigt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FUNNY),
#else
        .text = COMPOUND_STRING("DOWNCAST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GREAT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INCREDIBLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sagenhaft"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOULD),
#else
        .text = COMPOUND_STRING("INCREDIBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPINESS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIKES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vorlieben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANT),
#else
        .text = COMPOUND_STRING("LIKES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISLIKES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Abneigung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEGATIVE),
#else
        .text = COMPOUND_STRING("DISLIKES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HARD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BORING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Langweilig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NICE),
#else
        .text = COMPOUND_STRING("BORING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEAR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CARE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sorgen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISLIKE),
#else
        .text = COMPOUND_STRING("CARE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEARS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CARES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sorgt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEVER),
#else
        .text = COMPOUND_STRING("CARES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HURRIED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALL_RIGHT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gut"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROMANTIC),
#else
        .text = COMPOUND_STRING("ALL RIGHT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMPORTANT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ADORE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vergöttern"),
#else
        .text = COMPOUND_STRING("ADORE"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_INCREDIBLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISASTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Desaster"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BAD),
#else
        .text = COMPOUND_STRING("DISASTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JOY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENJOY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Genießen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEAT),
#else
        .text = COMPOUND_STRING("ENJOY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LACKING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENJOYS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Genießt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TERRIBLE),
#else
        .text = COMPOUND_STRING("ENJOYS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIKES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EAT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Essen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HARD),
#else
        .text = COMPOUND_STRING("EAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LONESOME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LACKING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unzureichend"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIDDY),
#else
        .text = COMPOUND_STRING("LACKING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEET),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BAD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schlechte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RARE),
#else
        .text = COMPOUND_STRING("BAD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISHEARD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HARD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schwer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CARE),
#else
        .text = COMPOUND_STRING("HARD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEGATIVE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TERRIBLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schrecklich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CARES),
#else
        .text = COMPOUND_STRING("TERRIBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEVER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOULD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Miese laune"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAY),
#else
        .text = COMPOUND_STRING("SHOULD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NICE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NICE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nett"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAD),
#else
        .text = COMPOUND_STRING("NICE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DRINK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Trinken"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRINK),
#else
        .text = COMPOUND_STRING("DRINK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUESTION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SURPRISE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Überraschung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SURPRISE),
#else
        .text = COMPOUND_STRING("SURPRISE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RARE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEAR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Furcht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCARY),
#else
        .text = COMPOUND_STRING("FEAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROMANTIC),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Möchte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRY),
#else
        .text = COMPOUND_STRING("WANT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAIT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Langeweile"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LACKING),
#else
        .text = COMPOUND_STRING("WAIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SATISFIED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SATISFIED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zufrieden"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DARN),
#else
        .text = COMPOUND_STRING("SATISFIED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCARY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lachen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ADORE),
#else
        .text = COMPOUND_STRING("SEE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RARE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Selten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISHEARD),
#else
        .text = COMPOUND_STRING("RARE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOULD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEGATIVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Negativ"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNDERSTAND),
#else
        .text = COMPOUND_STRING("NEGATIVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SURPRISE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DONE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fertig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNDERSTANDS),
#else
        .text = COMPOUND_STRING("DONE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TERRIBLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DANGER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gefahr"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRIES),
#else
        .text = COMPOUND_STRING("DANGER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEFEATED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Besiegt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIKES),
#else
        .text = COMPOUND_STRING("DEFEATED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRIES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEAT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schlug"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEET),
#else
        .text = COMPOUND_STRING("BEAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GREAT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Großartig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMPORTANT),
#else
        .text = COMPOUND_STRING("GREAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNDERSTAND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROMANTIC)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Romantisch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANTS),
#else
        .text = COMPOUND_STRING("ROMANTIC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNDERSTANDS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUESTION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Frage"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANGER),
#else
        .text = COMPOUND_STRING("QUESTION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAIT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNDERSTAND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verstehen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANGRY),
#else
        .text = COMPOUND_STRING("UNDERSTAND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNDERSTANDS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Versteht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SATISFIED),
#else
        .text = COMPOUND_STRING("UNDERSTANDS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANTS),
#endif
        .enabled = TRUE,
    },
};
