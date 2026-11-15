const u8 gEasyChatWord_Appeal[] = _("APPEAL");
const u8 gEasyChatWord_Events[] = _("EVENTS");
const u8 gEasyChatWord_StayAtHome[] = _("STAY-AT-HOME");
const u8 gEasyChatWord_Berry[] = _("BERRY");
const u8 gEasyChatWord_Contest[] = _("CONTEST");
const u8 gEasyChatWord_Mc[] = _("MC");
const u8 gEasyChatWord_Judge[] = _("JUDGE");
const u8 gEasyChatWord_Super[] = _("SUPER");
const u8 gEasyChatWord_Stage[] = _("STAGE");
const u8 gEasyChatWord_HallOfFame[] = _("HALL OF FAME");
const u8 gEasyChatWord_Evolution[] = _("EVOLUTION");
const u8 gEasyChatWord_Hyper[] = _("HYPER");
const u8 gEasyChatWord_BattleTower[] = _("BATTLE TOWER");
const u8 gEasyChatWord_Leaders[] = _("LEADERS");
const u8 gEasyChatWord_BattleRoom[] = _("BATTLE ROOM");
const u8 gEasyChatWord_Hidden[] = _("HIDDEN");
const u8 gEasyChatWord_SecretBase[] = _("SECRET BASE");
const u8 gEasyChatWord_Blend[] = _("BLEND");
const u8 gEasyChatWord_POKEBLOCK[] = _("{POKEBLOCK}");
const u8 gEasyChatWord_Master[] = _("MASTER");
const u8 gEasyChatWord_Rank[] = _("RANK");
const u8 gEasyChatWord_Ribbon[] = _("RIBBON");
const u8 gEasyChatWord_Crush[] = _("CRUSH");
const u8 gEasyChatWord_Direct[] = _("DIRECT");
const u8 gEasyChatWord_Tower[] = _("TOWER");
const u8 gEasyChatWord_Union[] = _("UNION");
const u8 gEasyChatWord_Room[] = _("ROOM");
const u8 gEasyChatWord_Wireless[] = _("WIRELESS");
const u8 gEasyChatWord_Frontier[] = _("FRONTIER");

const struct EasyChatWordInfo gEasyChatGroup_Events[] = {
    [EC_INDEX(EC_WORD_APPEAL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ausdruck"),
#else
        .text = COMPOUND_STRING("APPEAL"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVENTS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Events"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STAY_AT_HOME),
#else
        .text = COMPOUND_STRING("EVENTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_ROOM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STAY_AT_HOME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Babysitten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIBBON),
#else
        .text = COMPOUND_STRING("STAY-AT-HOME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_TOWER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BERRY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Beere"),
#else
        .text = COMPOUND_STRING("BERRY"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_BERRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONTEST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wettbewerb"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STAGE),
#else
        .text = COMPOUND_STRING("CONTEST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BLEND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MC)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("MC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIRECT),
#else
        .text = COMPOUND_STRING("MC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONTEST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JUDGE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Juror"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIRELESS),
#else
        .text = COMPOUND_STRING("JUDGE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRUSH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SUPER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Super"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_TOWER),
#else
        .text = COMPOUND_STRING("SUPER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIRECT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STAGE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bühne"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVOLUTION),
#else
        .text = COMPOUND_STRING("STAGE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVENTS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HALL_OF_FAME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ruhmeshalle"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVENTS),
#else
        .text = COMPOUND_STRING("HALL OF FAME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVOLUTION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLUTION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Entwicklung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET_BASE),
#else
        .text = COMPOUND_STRING("EVOLUTION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONTIER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HYPER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hyper"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HYPER),
#else
        .text = COMPOUND_STRING("HYPER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HALL_OF_FAME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_TOWER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Duellturm"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JUDGE),
#else
        .text = COMPOUND_STRING("BATTLE TOWER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIDDEN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEADERS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Leiter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_ROOM),
#else
        .text = COMPOUND_STRING("LEADERS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HYPER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_ROOM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kampfraum"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RANK),
#else
        .text = COMPOUND_STRING("BATTLE ROOM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JUDGE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIDDEN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Versteckte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROOM),
#else
        .text = COMPOUND_STRING("HIDDEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEADERS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET_BASE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geheimbasis"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNION),
#else
        .text = COMPOUND_STRING("SECRET BASE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MASTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BLEND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mixen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEADERS),
#else
        .text = COMPOUND_STRING("BLEND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MC),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEBLOCK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("{POKEBLOCK}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MC),
#else
        .text = COMPOUND_STRING("{POKEBLOCK}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEBLOCK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MASTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Meister"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MASTER),
#else
        .text = COMPOUND_STRING("MASTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RANK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RANK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Klasse"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BLEND),
#else
        .text = COMPOUND_STRING("RANK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIBBON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIBBON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Band"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRUSH),
#else
        .text = COMPOUND_STRING("RIBBON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROOM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRUSH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mühle"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEBLOCK),
#else
        .text = COMPOUND_STRING("CRUSH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET_BASE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIRECT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Direkt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HALL_OF_FAME),
#else
        .text = COMPOUND_STRING("DIRECT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STAGE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOWER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Turm"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUPER),
#else
        .text = COMPOUND_STRING("TOWER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STAY_AT_HOME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNION)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Konnex"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOWER),
#else
        .text = COMPOUND_STRING("UNION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUPER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROOM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Klub"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIDDEN),
#else
        .text = COMPOUND_STRING("ROOM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOWER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIRELESS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Drahtlos"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONTEST),
#else
        .text = COMPOUND_STRING("WIRELESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNION),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONTIER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zone"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONTIER),
#else
        .text = COMPOUND_STRING("FRONTIER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIRELESS),
#endif
        .enabled = TRUE,
    },
};
