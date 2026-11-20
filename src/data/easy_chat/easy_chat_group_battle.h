const struct EasyChatWordInfo gEasyChatGroup_Battle[] = {
    [EC_INDEX(EC_WORD_MATCH_UP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Harmonieren"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REJECT),
#else
        .text = COMPOUND_STRING("MATCH UP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ACCEPT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Los"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ACCEPT),
#else
        .text = COMPOUND_STRING("GO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AIM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO_1)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("NR. 1"),
#else
        .text = COMPOUND_STRING("NO. 1"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_ATTACK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DECIDE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Entscheiden"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOVE),
#else
        .text = COMPOUND_STRING("DECIDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LET_ME_WIN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ich siege!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE_UP),
#else
        .text = COMPOUND_STRING("LET ME WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN_WIN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WINS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gewinnen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RESUSCITATE),
#else
        .text = COMPOUND_STRING("WINS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN_T_WIN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gewinne"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DECIDE),
#else
        .text = COMPOUND_STRING("WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHALLENGE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gewonnen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DECIDED),
#else
        .text = COMPOUND_STRING("WON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME_ON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IF_I_WIN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gewinne ich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SURRENDER),
#else
        .text = COMPOUND_STRING("IF I WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DECIDE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHEN_I_WIN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Siege ich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RECEIVED),
#else
        .text = COMPOUND_STRING("WHEN I WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DECIDED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN_T_WIN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sieg unmögl."),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERIOUS),
#else
        .text = COMPOUND_STRING("CAN'T WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EASY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN_WIN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kann siegen"),
#else
        .text = COMPOUND_STRING("CAN WIN"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_ESCAPE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO_MATCH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unterlegen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERSUS),
#else
        .text = COMPOUND_STRING("NO MATCH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIGHT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPIRIT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Seele"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOE),
#else
        .text = COMPOUND_STRING("SPIRIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIGHTS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DECIDED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Entschieden"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GENIUS),
#else
        .text = COMPOUND_STRING("DECIDED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRUMP_CARD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Trumpfkarte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIN),
#else
        .text = COMPOUND_STRING("TRUMP CARD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GENIUS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TAKE_THAT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Nimm das"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IF_I_WIN),
#else
        .text = COMPOUND_STRING("TAKE THAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE_UP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME_ON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Komm schon"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WINS),
#else
        .text = COMPOUND_STRING("COME ON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ATTACK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Angriff"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WON),
#else
        .text = COMPOUND_STRING("ATTACK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO_EASY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SURRENDER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ergeben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MATCH_UP),
#else
        .text = COMPOUND_STRING("SURRENDER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GUARD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GUTSY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mutig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHALLENGE),
#else
        .text = COMPOUND_STRING("GUTSY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GUTSY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Talentiert"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LET_ME_WIN),
#else
        .text = COMPOUND_STRING("TALENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IF_I_LOSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STRATEGY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Strategie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE),
#else
        .text = COMPOUND_STRING("STRATEGY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IF_I_WIN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMITE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schlagen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIGHT),
#else
        .text = COMPOUND_STRING("SMITE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INVINCIBLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MATCH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Partie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN_WIN),
#else
        .text = COMPOUND_STRING("MATCH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEADER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VICTORY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sieg"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME_ON),
#else
        .text = COMPOUND_STRING("VICTORY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEGEND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OFFENSIVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Offensiv"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POWER),
#else
        .text = COMPOUND_STRING("OFFENSIVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LET_ME_WIN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SENSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sinn"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PUSHOVER),
#else
        .text = COMPOUND_STRING("SENSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERSUS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gegen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEGEND),
#else
        .text = COMPOUND_STRING("VERSUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIGHTS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Streiten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EASY),
#else
        .text = COMPOUND_STRING("FIGHTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POWER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kraft"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEADER),
#else
        .text = COMPOUND_STRING("POWER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MATCH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHALLENGE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Herausfordrg"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO),
#else
        .text = COMPOUND_STRING("CHALLENGE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MATCH_UP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STRONG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Starken"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GUTSY),
#else
        .text = COMPOUND_STRING("STRONG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOVE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO_STRONG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zu stark"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TAKE_THAT),
#else
        .text = COMPOUND_STRING("TOO STRONG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NO_MATCH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_EASY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schonen"),
#else
        .text = COMPOUND_STRING("GO EASY"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_NO_1),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gegner"),
#else
        .text = COMPOUND_STRING("FOE"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_OFFENSIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GENIUS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Genie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MATCH),
#else
        .text = COMPOUND_STRING("GENIUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARTNER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEGEND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Legende"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARTNER),
#else
        .text = COMPOUND_STRING("LEGEND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POINTS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ESCAPE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Flucht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POINTS),
#else
        .text = COMPOUND_STRING("ESCAPE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POWER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AIM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ziel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RULE),
#else
        .text = COMPOUND_STRING("AIM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PUSHOVER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kämpfe"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMITE),
#else
        .text = COMPOUND_STRING("BATTLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RECEIVED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIGHT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kämpfen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO_EASY),
#else
        .text = COMPOUND_STRING("FIGHT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REJECT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RESUSCITATE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Beleben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEAK),
#else
        .text = COMPOUND_STRING("RESUSCITATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RESUSCITATE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POINTS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Punkte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPIRIT),
#else
        .text = COMPOUND_STRING("POINTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RULE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERIOUS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ernsthaft"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VICTORY),
#else
        .text = COMPOUND_STRING("SERIOUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SENSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE_UP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Aufgeben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN_T_WIN),
#else
        .text = COMPOUND_STRING("GIVE UP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERIOUS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verlust"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHEN_I_WIN),
#else
        .text = COMPOUND_STRING("LOSS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMITE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IF_I_LOSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verliere ich"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SENSE),
#else
        .text = COMPOUND_STRING("IF I LOSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPIRIT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verloren"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STRONG),
#else
        .text = COMPOUND_STRING("LOST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STRATEGY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verlieren"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STRATEGY),
#else
        .text = COMPOUND_STRING("LOSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STRONG),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GUARD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wache"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIGHTS),
#else
        .text = COMPOUND_STRING("GUARD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SURRENDER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARTNER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Partner"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALENT),
#else
        .text = COMPOUND_STRING("PARTNER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TAKE_THAT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REJECT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ablehnen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRUMP_CARD),
#else
        .text = COMPOUND_STRING("REJECT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALENT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ACCEPT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Akzeptieren"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INVINCIBLE),
#else
        .text = COMPOUND_STRING("ACCEPT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO_STRONG),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INVINCIBLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unschlagbar"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NO_MATCH),
#else
        .text = COMPOUND_STRING("INVINCIBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO_WEAK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RECEIVED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Erhalten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IF_I_LOSE),
#else
        .text = COMPOUND_STRING("RECEIVED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRUMP_CARD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EASY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Leicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSE),
#else
        .text = COMPOUND_STRING("EASY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERSUS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEAK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schwach"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOST),
#else
        .text = COMPOUND_STRING("WEAK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VICTORY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO_WEAK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zu schwach"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSS),
#else
        .text = COMPOUND_STRING("TOO WEAK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEAK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PUSHOVER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lappalie"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GUARD),
#else
        .text = COMPOUND_STRING("PUSHOVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHEN_I_WIN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEADER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Leiter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AIM),
#else
        .text = COMPOUND_STRING("LEADER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RULE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Regel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO_WEAK),
#else
        .text = COMPOUND_STRING("RULE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WINS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Attacke"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO_STRONG),
#else
        .text = COMPOUND_STRING("MOVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WON),
#endif
        .enabled = TRUE,
    },
};
