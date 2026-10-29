BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	waitse
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	fadescreen FADE_TO_BLACK
	setvar VAR_BUG_CONTEST_STATE, 3

	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	BugContest_EventScript_TimesUp2::
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContest_EventScript_WrongChoiceMon
	goto_if_eq VAR_0x8004, 0, BugContest_EventScript_WrongChoiceMon
	fadescreen FADE_TO_BLACK
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 5
	waitstate
	delay 90
	end

BugContest_EventScript_WrongChoiceMon::
	msgbox BugContest_Text_WrongChoiceMon, MSGBOX_DEFAULT
	goto BugContest_EventScript_TimesUp2
	end

@ Only a judged contest uses up the day; retiring without a catch or
@ whiting out lets the player enter again, see
@ docs/origin_jade/DECISIONS.md, D-033.
BugContestEventScript_Judging::
	setflag FLAG_DAILY_BUG_CONTEST_COMPLETED
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_First2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_First3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Second::
	msgbox BugContest_Text_Second1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Second2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Second3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Third::
	msgbox BugContest_Text_Third1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Third2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Third3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_End::
	special HealPlayerParty
	special LoadPlayerParty
	special ExitBugContestMode
	clearflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSportBalls
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK_HNS, 7, 2
	waitstate
	releaseall
	end

BugContest_EventScript_SideEnd::
	warp MAP_GATE_NATIONAL_PARK_HNS, 35, 7
	waitstate
	releaseall
	end

BugContest_Text_Judging0::
#if GERMAN
	.string "Das Turnier ist beendet.\p"
	.string "Bitte wähle das Pokémon, das du\n"
	.string "behalten und bewerten lassen\l"
	.string "möchtest.$"
#else
	.string "The contest has now concluded.\n"
	.string "Please pick the POKéMON you would\l"
	.string "like to keep and have judged.$"
#endif

BugContest_Text_Judging1::
#if GERMAN
	.string "Wir bewerten jetzt die Pokémon,\n"
	.string "die ihr gefangen habt.\p"
	.string "…………………\n"
	.string "…………………\p"
	.string "Die Gewinner stehen fest!\n"
	.string "Seid ihr bereit?$"
#else
	.string "We will now judge the POKéMON\n"
	.string "you've caught.\p"
	.string "...................\n"
	.string "...................\p"
	.string "We have chosen the winners! Are\n"
	.string "you ready for this?$"
#endif

BugContest_Text_WrongChoiceMon:
#if GERMAN
	.string "Bitte wähle das Pokémon, das du\n"
	.string "behalten und bewerten lassen\l"
	.string "möchtest.$"
#else
	.string "Please pick the POKéMON you would\n"
	.string "like to keep and have judged.$"
#endif

BugContest_Text_DidntCatch:
#if GERMAN
	.string "Oh nein! Du hast kein Pokémon\n"
	.string "gefangen und scheidest aus.\p"
	.string "Du erhältst dein Team jetzt\n"
	.string "zurück.\p"
	.string "Du darfst es heute noch einmal\n"
	.string "versuchen.$"
#else
	.string "Oh no! You didn't catch a POKéMON.\n"
	.string "You've forfeited the competition.\p"
	.string "Your party will now be returned.\p"
	.string "You may try again today.$"
#endif

BugContest_Text_TimesUp:
#if GERMAN
	.string "Ding-dong! Die Zeit ist um!$"
#else
	.string "Ding-dong! Time's up!$"
#endif

BugContest_Text_WhiteOut:
#if GERMAN
	.string "{PLAYER} hat keine kampffähigen\n"
	.string "Pokémon mehr.\p"
	.string "{PLAYER} scheidet aus dem\n"
	.string "Turnier aus.\p"
	.string "Du darfst es heute noch einmal\n"
	.string "versuchen.$"
#else
	.string "{PLAYER} is out of usable POKéMON.\n"
	.string "{PLAYER} forfeited the contest.\p"
	.string "You may try again today.$"
#endif

BugContest_Text_First1:
#if GERMAN
	.string "Den dritten Platz belegt\n"
	.string "Ass-Trainerin Uli mit einem\l"
	.string "zappelnden Smettbo!$"
#else
	.string "Placing third is the COOLTRAINER\n"
	.string "BELINDA, who caught a wriggling\l"
	.string "BUTTERFREE!$"
#endif
BugContest_Text_First2:
#if GERMAN
	.string "Den zweiten Platz belegt\n"
	.string "Käfersammler Wilhelm mit einem\l"
	.string "zuckenden Pinsir!$"
#else
	.string "Placing second is the BUGCATCHER\n"
	.string "SHAUN, who caught a writhing\l"
	.string "PINSIR!$"
#endif
BugContest_Text_First3:
#if GERMAN
	.string "Der Sieger des Käferturniers\n"
	.string "ist…\p"
	.string "{PLAYER} mit einem gewaltigen\n"
	.string "{STR_VAR_1}!$"
#else
	.string "This Bug-Catching Contest Winner\n"
	.string "is...\p"
	.string "{PLAYER}, who caught a whopping\n"
	.string "{STR_VAR_1}!$"
#endif

BugContest_Text_Second1:
#if GERMAN
	.string "Den dritten Platz belegt\n"
	.string "Ass-Trainerin Uli mit einem\l"
	.string "zappelnden Smettbo!$"
#else
	.string "Placing third is the COOLTRAINER\n"
	.string "BELINDA, who caught a wriggling\l"
	.string "BUTTERFREE!$"
#endif
BugContest_Text_Second2:
#if GERMAN
	.string "Den zweiten Platz belegt {PLAYER}\n"
	.string "mit einem zuckenden {STR_VAR_1}!$"
#else
	.string "Placing second is {PLAYER}, who\n"
	.string "caught a writhing {STR_VAR_1}!$"
#endif
BugContest_Text_Second3:
#if GERMAN
	.string "Der Sieger des Käferturniers\n"
	.string "ist…\p"
	.string "Käfersammler Wilhelm mit einem\n"
	.string "gewaltigen Pinsir!$"
#else
	.string "This Bug-Catching Contest Winner\n"
	.string "is...\p"
	.string "BUGCATCHER SHAUN, who caught a\n"
	.string "whopping PINSIR!$"
#endif

BugContest_Text_Third1:
#if GERMAN
	.string "Den dritten Platz belegt {PLAYER}\n"
	.string "mit einem zappelnden {STR_VAR_1}!$"
#else
	.string "Placing third is {PLAYER}, who\n"
	.string "caught a wriggling {STR_VAR_1}!$"
#endif
BugContest_Text_Third2:
#if GERMAN
	.string "Den zweiten Platz belegt\n"
	.string "Ass-Trainerin Uli mit einem\l"
	.string "zuckenden Smettbo!$"
#else
	.string "Placing second is the COOLTRAINER\n"
	.string "BELINDA, who caught a writhing\l"
	.string "BUTTERFREE!$"
#endif
BugContest_Text_Third3:
#if GERMAN
	.string "Der Sieger des Käferturniers\n"
	.string "ist…\p"
	.string "Käfersammler Wilhelm mit einem\n"
	.string "gewaltigen Pinsir!$"
#else
	.string "This Bug-Catching Contest Winner\n"
	.string "is...\p"
	.string "BUGCATCHER SHAUN, who caught a\n"
	.string "whopping PINSIR!$"
#endif

BugContest_Text_TakePartInFuture:
#if GERMAN
	.string "Danke für deine Teilnahme!\n"
	.string "Wir hoffen, du machst wieder mit.$"
#else
	.string "Thank you for participating!\n"
	.string "We hope you'll take part in the\l"
	.string "future.$"
#endif

BugContest_Text_TransferAndReturn:
#if GERMAN
	.string "Das gewählte Käfer-Pokémon wird\n"
	.string "auf den PC übertragen.\p"
	.string "Du erhältst dein Team zurück.$"
#else
	.string "Your chosen BUG POKéMON will now\n"
	.string "be sent to the PC and your party\l"
	.string "will be returned to you.$"
#endif
