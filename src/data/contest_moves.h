const struct ContestEffect gContestEffects[] =
{
    [CONTEST_EFFECT_HIGHLY_APPEALING] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
#if GERMAN
        .description = COMPOUND_STRING(
        "Eine sehr ansprechende\n"
        "Vorführung."),
#else
        .description = COMPOUND_STRING("Quite the appealing move."),
#endif
        #else
#if GERMAN
        .description = COMPOUND_STRING(
        "Eine sehr ansprechende\n"
        "Vorführung."),
#else
        .description = COMPOUND_STRING("A highly appealing move."),
#endif
        #endif
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 40,
        .jam = 0,
        .function = ContestEffect_HighlyAppealing,
    },
    [CONTEST_EFFECT_USER_MORE_EASILY_STARTLED] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Einsatz der Attacke macht\n"
        "Pkmn leichter irritierbar."),
#else
        .description = COMPOUND_STRING("After this move, the user is\nmore easily startled."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 60,
        .jam = 0,
        .function = ContestEffect_UserMoreEasilyStartled,
    },
    [CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Großartiger Ausdruck, der\n"
        "sich nicht steigern lässt."),
#else
        .description = COMPOUND_STRING("Makes a great appeal, but\nallows no more to the end."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 80,
        .jam = 0,
        .function = ContestEffect_GreatAppealButNoMoreMoves,
    },
    [CONTEST_EFFECT_REPETITION_NOT_BORING] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Langweilt den Juror auch\n"
        "bei Wiederholung nicht."),
#else
        .description = COMPOUND_STRING("Can be repeatedly used\nwithout boring the JUDGE."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_RepetitionNotBoring,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_ONCE] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Kann Irritation durch\n"
        "andere einmal verhindern."),
#else
        .description = COMPOUND_STRING("Can avoid being startled\nby others once."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_AvoidStartleOnce,
    },
    [CONTEST_EFFECT_AVOID_STARTLE] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Kann Irritation durch\n"
        "andere verhindern."),
#else
        .description = COMPOUND_STRING("Can avoid being startled\nby others."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_AvoidStartle,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Kann Irritation durch an-\n"
        "dere ein wenig eindämmen."),
#else
        .description = COMPOUND_STRING("Can avoid being startled\nby others a little."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_AvoidStartleSlightly,
    },
    [CONTEST_EFFECT_USER_LESS_EASILY_STARTLED] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Einsatz der Attacke dämmt\n"
        "danach Irritation ein."),
#else
        .description = COMPOUND_STRING("After this move, the user is\nless likely to be startled."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_UserLessEasilyStartled,
    },
    [CONTEST_EFFECT_STARTLE_FRONT_MON] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert das vordere\n"
        "Pokémon ein wenig."),
#else
        .description = COMPOUND_STRING("Slightly startles the\nPOKéMON in front."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
        .function = ContestEffect_StartleFrontMon,
    },
    [CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert die Pokémon ein\n"
        "wenig, die schon auftraten."),
#else
        .description = COMPOUND_STRING("Slightly startles those\nthat have made appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
        .function = ContestEffect_StartlePrevMons,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert das Pokémon, das\n"
        "vorher aufgetreten ist."),
#else
        .description = COMPOUND_STRING("Startles the last Pokémon\nto act before the user."),
#endif
        #else
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert das Pokémon, das\n"
        "vorher aufgetreten ist."),
#else
        .description = COMPOUND_STRING("Startles the POKéMON that\nappealed before the user."),
#endif
        #endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 20,
        .jam = 30,
        .function = ContestEffect_StartleFrontMon,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert alle Pokémon,\n"
        "die bisher auftraten."),
#else
        .description = COMPOUND_STRING("Startles all of the Pokémon\nto act before the user."),
#endif
        #else
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert alle Pokémon,\n"
        "die bisher auftraten."),
#else
        .description = COMPOUND_STRING("Startles all POKéMON that\nhave done their appeals."),
#endif
        #endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 20,
        .function = ContestEffect_StartlePrevMons,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert das vordere\n"
        "Pokémon sehr stark."),
#else
        .description = COMPOUND_STRING("Badly startles the\nPOKéMON in front."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 10,
        .jam = 40,
        .function = ContestEffect_StartleFrontMon,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert die Pokémon, die\n"
        "schon aufgetreten sind."),
#else
        .description = COMPOUND_STRING("Badly startles those that\nhave made appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 10,
        .jam = 30,
        .function = ContestEffect_StartlePrevMons,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON_2] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert das Pokémon, das\n"
        "vorher aufgetreten ist."),
#else
        .description = COMPOUND_STRING("Startles the POKéMON that\nappealed before the user."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
        .function = ContestEffect_StartlePrevMon2,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS_2] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert alle Pokémon, die\n"
        "vorher aufgetreten sind."),
#else
        .description = COMPOUND_STRING("Startles all POKéMON that\nhave done their appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
        .function = ContestEffect_StartlePrevMons2,
    },
    [CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
#if GERMAN
        .description = COMPOUND_STRING(
        "Lenkt den Juror von den\n"
        "anderen Pokémon ab."),
#else
        .description = COMPOUND_STRING("Makes audience expect\nlittle of other contestants."),
#endif
        #else
#if GERMAN
        .description = COMPOUND_STRING(
        "Lenkt den Juror von den\n"
        "anderen Pokémon ab."),
#else
        .description = COMPOUND_STRING("Shifts the JUDGE's\nattention from others."),
#endif
        #endif
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_ShiftJudgeAttention,
    },
    [CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert Pokémon, bes. die,\n"
        "auf die der Juror achtet."),
#else
        .description = COMPOUND_STRING("Startles the POKéMON that\nhas the JUDGE's attention."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonWithJudgesAttention,
    },
    [CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Stört die anderen und An-\n"
        "wender setzt 1 Runde aus."),
#else
        .description = COMPOUND_STRING("Jams the others, and misses\none turn of appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 40,
        .jam = 40,
        .function = ContestEffect_JamsOthersButMissOneTurn,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert Pkmn, bes. die, die\n"
        "Ausdruck gl. Typs zeigten."),
#else
        .description = COMPOUND_STRING("Startles POKéMON that\nmade a same-type appeal."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsSameTypeAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert Pkmn mit Ausdruck\n"
        "des Typs Cool."),
#else
        .description = COMPOUND_STRING("Badly startles POKéMON\nthat made COOL appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsCoolAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert Pkmn mit Ausdruck\n"
        "des Typs Schön."),
#else
        .description = COMPOUND_STRING("Badly startles POKéMON\nthat made BEAUTY appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsBeautyAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert Pkmn mit Ausdruck\n"
        "des Typs Anmut."),
#else
        .description = COMPOUND_STRING("Badly startles POKéMON\nthat made CUTE appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsCuteAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert Pkmn mit Ausdruck\n"
        "des Typs Klug."),
#else
        .description = COMPOUND_STRING("Badly startles POKéMON\nthat made SMART appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsSmartAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert Pkmn mit Ausdruck\n"
        "des Typs Stark."),
#else
        .description = COMPOUND_STRING("Badly startles POKéMON\nthat made TOUGH appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsToughAppeal,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Macht nachfolgendes\n"
        "Pokémon nervös."),
#else
        .description = COMPOUND_STRING("Makes one POKéMON after\nthe user nervous."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_MakeFollowingMonNervous,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
#if GERMAN
        .description = COMPOUND_STRING(
        "Macht alle nachfolgenden\n"
        "Pokémon nervös."),
#else
        .description = COMPOUND_STRING("Makes the remaining\nPokémon nervous."),
#endif
        #else
#if GERMAN
        .description = COMPOUND_STRING(
        "Macht alle nachfolgenden\n"
        "Pokémon nervös."),
#else
        .description = COMPOUND_STRING("Makes all POKéMON after\nthe user nervous."),
#endif
        #endif
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_MakeFollowingMonsNervous,
    },
    [CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Schwächt Kondition der\n"
        "Pkmn, die bisher auftraten."),
#else
        .description = COMPOUND_STRING("Worsens the condition of\nthose that made appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_WorsenConditionOfPrevMons,
    },
    [CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert Pokémon, die eine\n"
        "gute Kondition haben."),
#else
        .description = COMPOUND_STRING("Badly startles POKéMON in\ngood condition."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
        .function = ContestEffect_BadlyStartlesMonsInGoodCondition,
    },
    [CONTEST_EFFECT_BETTER_IF_FIRST] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Ausdruck gelingt sehr gut,\n"
        "wenn als Erster vorgeführt."),
#else
        .description = COMPOUND_STRING("The appeal works great if\nperformed first."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfFirst,
    },
    [CONTEST_EFFECT_BETTER_IF_LAST] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Ausdruck gelingt sehr gut,\n"
        "wenn zuletzt vorgeführt."),
#else
        .description = COMPOUND_STRING("The appeal works great if\nperformed last."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfLast,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Ausdruck gelingt so gut\n"
        "wie die der Vorgänger."),
#else
        .description = COMPOUND_STRING("Makes the appeal as good\nas those before it."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_AppealAsGoodAsPrevOnes,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Ausdruck gelingt so gut\n"
        "wie der des Vorgängers."),
#else
        .description = COMPOUND_STRING("Makes the appeal as good\nas the one before it."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_AppealAsGoodAsPrevOne,
    },
    [CONTEST_EFFECT_BETTER_WHEN_LATER] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Je später der Auftritt,\n"
        "desto besser der Ausdruck."),
#else
        .description = COMPOUND_STRING("The appeal works better\nthe later it is performed."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_BetterWhenLater,
    },
    [CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
#if GERMAN
        .description = COMPOUND_STRING(
        "Die Qualität des Ausdrucks\n"
        "hängt vom Timing ab."),
#else
        .description = COMPOUND_STRING("Effectiveness varies\ndepending on when it is used."),
#endif
        #else
#if GERMAN
        .description = COMPOUND_STRING(
        "Die Qualität des Ausdrucks\n"
        "hängt vom Timing ab."),
#else
        .description = COMPOUND_STRING("The appeal's quality varies\ndepending on its timing."),
#endif
        #endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_QualityDependsOnTiming,
    },
    [CONTEST_EFFECT_BETTER_IF_SAME_TYPE] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Gelingt gut, wenn vom\n"
        "selben Typ wie der vorige."),
#else
        .description = COMPOUND_STRING("Works well if it's the same\ntype as the one before."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfSameType,
    },
    [CONTEST_EFFECT_BETTER_IF_DIFF_TYPE] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Gelingt gut, wenn vom\n"
        "anderen Typ als der vorige."),
#else
        .description = COMPOUND_STRING("Works well if different in\ntype than the one before."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfDiffType,
    },
    [CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
#if GERMAN
        .description = COMPOUND_STRING(
        "Hängt von Qualität des\n"
        "Ausdrucks d. Vorgängers ab."),
#else
        .description = COMPOUND_STRING("Affected by how well the\nprevious Pokémon's move went."),
#endif
        #else
#if GERMAN
        .description = COMPOUND_STRING(
        "Hängt von Qualität des\n"
        "Ausdrucks d. Vorgängers ab."),
#else
        .description = COMPOUND_STRING("Affected by how well the\nappeal in front goes."),
#endif
        #endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_AffectedByPrevAppeal,
    },
    [CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Verbessert die Kondition\n"
        "und verhindert Nervosität."),
#else
        .description = COMPOUND_STRING("Ups the user's condition.\nHelps prevent nervousness."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_ImproveConditionPreventNervousness,
    },
    [CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Ausdruck gelingt gut, wenn\n"
        "Kondition des Pkmn gut ist."),
#else
        .description = COMPOUND_STRING("The appeal works well if the\nuser's condition is good."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_BetterWithGoodCondition,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_EARLIER] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
#if GERMAN
        .description = COMPOUND_STRING(
        "Der nächste Ausdruck kann\n"
        "früher vorgeführt werden."),
#else
        .description = COMPOUND_STRING("Causes the user to move\nearlier on the next turn."),
#endif
        #else
#if GERMAN
        .description = COMPOUND_STRING(
        "Der nächste Ausdruck kann\n"
        "früher vorgeführt werden."),
#else
        .description = COMPOUND_STRING("The next appeal can be\nmade earlier next turn."),
#endif
        #endif
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_NextAppealEarlier,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_LATER] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
#if GERMAN
        .description = COMPOUND_STRING(
        "Der nächste Ausdruck kann\n"
        "später vorgeführt werden."),
#else
        .description = COMPOUND_STRING("Causes the user to move\nlater on the next turn."),
#endif
        #else
#if GERMAN
        .description = COMPOUND_STRING(
        "Der nächste Ausdruck kann\n"
        "später vorgeführt werden."),
#else
        .description = COMPOUND_STRING("The next appeal can be\nmade later next turn."),
#endif
        #endif
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_NextAppealLater,
    },
    [CONTEST_EFFECT_MAKE_SCRAMBLING_TURN_ORDER_EASIER] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Ändert die Reihenfolge der\n"
        "nächst. Auftritte leichter."),
#else
        .description = COMPOUND_STRING("Makes the next turn's order\nmore easily scrambled."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_MakeScramblingTurnOrderEasier,
    },
    [CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Ändert die Reihenfolge der\n"
        "nächsten Auftritte."),
#else
        .description = COMPOUND_STRING("Scrambles the order of\nappeals on the next turn."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_ScrambleNextTurnOrder,
    },
    [CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Verzückt das Publikum in\n"
        "jedem Wettbewerb."),
#else
        .description = COMPOUND_STRING("An appeal that excites the\naudience in any CONTEST."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? 20 : 10,
        .jam = 0,
        .function = ContestEffect_ExciteAudienceInAnyContest,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Irritiert alle Pokémon,\n"
        "deren Ausdruck gut war."),
#else
        .description = COMPOUND_STRING("Badly startles all POKéMON\nthat made good appeals."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_BadlyStartleMonsWithGoodAppeals,
    },
    [CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Gelingt am besten, wenn\n"
        "das Publikum gespannt ist."),
#else
        .description = COMPOUND_STRING("The appeal works best the\nmore the crowd is excited."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_BetterWhenAudienceExcited,
    },
    [CONTEST_EFFECT_DONT_EXCITE_AUDIENCE] =
    {
#if GERMAN
        .description = COMPOUND_STRING(
        "Bremst zeitweise Begeis-\n"
        "terung des Publikums."),
#else
        .description = COMPOUND_STRING("Temporarily stops the\ncrowd from growing excited."),
#endif
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_DontExciteAudience,
    },
};
