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
@ whiting out lets the player enter again.
BugContestEventScript_Judging::
	setflag FLAG_DAILY_BUG_CONTEST_COMPLETED
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	copyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8000, 3
	special BufferBugContestResult
	buffernumberstring STR_VAR_3, VAR_RESULT
	msgbox BugContest_Text_Third, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Score, MSGBOX_DEFAULT
	setvar VAR_0x8000, 2
	special BufferBugContestResult
	buffernumberstring STR_VAR_3, VAR_RESULT
	msgbox BugContest_Text_Second, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Score, MSGBOX_DEFAULT
	setvar VAR_0x8000, 1
	special BufferBugContestResult
	buffernumberstring STR_VAR_3, VAR_RESULT
	msgbox BugContest_Text_First, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	msgbox BugContest_Text_Score, MSGBOX_DEFAULT
	closemessage
	call_if_ge VAR_0x8006, 4, BugContest_EventScript_Consolation
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	call_if_eq VAR_RESULT, FALSE, BugContest_EventScript_HoldPrize
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

@ Bag full: the gate attendant keeps the prize (VAR_0x8000, the item after the
@ randomizer) in VAR_BUG_CONTEST_STATE until the player has room, like HGSS.
BugContest_EventScript_HoldPrize::
	msgbox BugContest_Text_BagFullHoldPrize, MSGBOX_DEFAULT
	copyvar VAR_BUG_CONTEST_STATE, VAR_0x8000
	addvar VAR_BUG_CONTEST_STATE, BUG_CONTEST_PRIZE_HELD
	return

@ Not among the first three: the consolation prize.
BugContest_EventScript_Consolation::
	bufferitemname STR_VAR_1, VAR_0x8005
	msgbox BugContest_Text_Consolation, MSGBOX_DEFAULT
	closemessage
	return

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_End::
	special HealPlayerParty
	special LoadPlayerParty
	special ExitBugContestMode
	clearflag FLAG_DISABLE_EXP_GAIN
	call_if_lt VAR_BUG_CONTEST_STATE, BUG_CONTEST_PRIZE_HELD, BugContest_EventScript_ClearState
	special RemoveSportBalls
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK_HNS, 7, 2
	waitstate
	releaseall
	end

BugContest_EventScript_ClearState::
	setvar VAR_BUG_CONTEST_STATE, 0
	return

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

@ Results: STR_VAR_1 species, STR_VAR_2 entrant (BufferBugContestResult), STR_VAR_3 score.
BugContest_Text_Third:
#if GERMAN
	.string "Den dritten Platz belegt\n"
	.string "{STR_VAR_2} mit einem\l"
	.string "zappelnden {STR_VAR_1}!$"
#else
	.string "Placing third is\n"
	.string "{STR_VAR_2}, who caught\l"
	.string "a wriggling {STR_VAR_1}!$"
#endif

BugContest_Text_Second:
#if GERMAN
	.string "Den zweiten Platz belegt\n"
	.string "{STR_VAR_2} mit einem\l"
	.string "zuckenden {STR_VAR_1}!$"
#else
	.string "Placing second is\n"
	.string "{STR_VAR_2}, who caught\l"
	.string "a writhing {STR_VAR_1}!$"
#endif

BugContest_Text_First:
#if GERMAN
	.string "Der Sieger des Käferturniers\n"
	.string "ist…\p"
	.string "{STR_VAR_2} mit einem\n"
	.string "gewaltigen {STR_VAR_1}!$"
#else
	.string "This Bug-Catching Contest Winner\n"
	.string "is...\p"
	.string "{STR_VAR_2},\n"
	.string "who caught a whopping {STR_VAR_1}!$"
#endif

BugContest_Text_Score:
#if GERMAN
	.string "Mit einem Punktestand von {STR_VAR_3}!$"
#else
	.string "The score was {STR_VAR_3} points!$"
#endif

BugContest_Text_Consolation:
#if GERMAN
	.string "Alle anderen erhalten dieses Item\n"
	.string "als Trostpreis: {STR_VAR_1}!$"
#else
	.string "Everyone else gets a {STR_VAR_1} as\n"
	.string "a consolation prize!$"
#endif

@ Entrants of the judging (sBugContestNpcNames).
BugContest_Text_NameWilhelm::
#if GERMAN
	.string "Käfersammler Wilhelm$"
#else
	.string "BUGCATCHER SHAUN$"
#endif

BugContest_Text_NameAlan::
#if GERMAN
	.string "Käfersammler Alan$"
#else
	.string "BUGCATCHER ED$"
#endif

BugContest_Text_NameUli::
#if GERMAN
	.string "Ass-Trainerin Uli$"
#else
	.string "COOLTRAINER BELINDA$"
#endif

BugContest_Text_NameTill::
#if GERMAN
	.string "Camper Till$"
#else
	.string "CAMPER BARRY$"
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

BugContest_Text_BagFullHoldPrize::
#if GERMAN
	.string "Oh, oh…\p"
	.string "Sieht so aus, als wäre dein Beutel voll.\p"
	.string "Dann bewahren wir deinen Preis noch\n"
	.string "etwas länger auf. Schaffe bitte\l"
	.string "Platz und komme dann wieder.$"
#else
	.string "Uh-oh…\n"
	.string "Your BAG is full, {PLAYER}.\p"
	.string "We'll hold on to your prize.\n"
	.string "Please make room, then come see me.$"
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
