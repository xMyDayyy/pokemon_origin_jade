Gate_NationalPark_hns_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	call Gate_NationalPark_EventScript_IsContestDay
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantNoContest
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_AttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_AttendantStart::
	playbgm MUS_HG_BUG_CONTEST_PREP, FALSE
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMon
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMon::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_AttendantEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTop
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBot
	waitmovement 0
	return


Gate_NationalPark_EventScript_AttendantFaint::
	msgbox Route35NationalParkGate_Text_FirstMonCantBattle, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	releaseall
	end

Gate_NationalPark_EventScript_AttendantCancel::
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	releaseall
	end

Gate_NationalPark_EventScript_AttendantAlreadyPlayed::
	msgbox Route35NationalParkGate_Text_ContestIsOver, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Gate_NationalPark_EventScript_AttendantNoContest::
	msgbox Route35NationalParkGate_Text_ContestExplanation, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ The contest runs on Tuesday, Thursday and Saturday, see
@ docs/origin_jade/DECISIONS.md, D-033. Returns TRUE/FALSE in VAR_RESULT.
Gate_NationalPark_EventScript_IsContestDay::
	special GetWeekday
	goto_if_eq VAR_RESULT, WEEKDAY_TUE, Gate_NationalPark_EventScript_ContestDay
	goto_if_eq VAR_RESULT, WEEKDAY_THU, Gate_NationalPark_EventScript_ContestDay
	goto_if_eq VAR_RESULT, WEEKDAY_SAT, Gate_NationalPark_EventScript_ContestDay
	setvar VAR_RESULT, FALSE
	return

Gate_NationalPark_EventScript_ContestDay:
	setvar VAR_RESULT, TRUE
	return

Gate_NationalPark_Movement_Player_EnterParkTop:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_Movement_Player_EnterParkBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_EventScript_BAttendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	call Gate_NationalPark_EventScript_IsContestDay
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantNoContest
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_BAttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_BAttendantStart::
	playbgm MUS_HG_BUG_CONTEST_PREP, FALSE
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMonB
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMonB::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_AttendantBEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTopB
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantBEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBotB
	waitmovement 0
	return

Gate_NationalPark_Movement_Player_EnterParkTopB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Gate_NationalPark_Movement_Player_EnterParkBotB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Route35NationalParkGate_Text_OfficerAskToParticipate:
#if GERMAN
	.string "Hallo, Trainer! Heute findet das\n"
	.string "Käferturnier statt.\p"
	.string "Die Regeln sind einfach.\p"
	.string "Fange mit einem deiner Pokémon ein\n"
	.string "Käfer-Pokémon. Die Jury bewertet\l"
	.string "es anschließend.\p"
	.string "Möchtest du es versuchen?$"
#else
	.string "Hello Trainer! The Bug-Catching\n"
	.string "Contest is on today.\p"
	.string "The rules are simple.\p"
	.string "Using one of your POKéMON, catch a\n"
	.string "bug POKéMON to be judged.\p"
	.string "Would you like to give it a try?$"
#endif

Route35NationalParkGate_Text_OfficerGiveSportBalls:
#if GERMAN
	.string "Alle Erfahrungspunkte, die deine\n"
	.string "Pokémon im Turnier sammeln,\l"
	.string "verfallen beim Verlassen des Parks.\p"
	.string "Hier sind die Turnierbälle für\n"
	.string "den Wettbewerb.$"
#else
	.string "Any EXP your POKéMON gains during\n"
	.string "the contest will be reverted when\l"
	.string "you leave.\p"
	.string "Here are the SPORT BALLS for the\n"
	.string "Contest.$"
#endif

Route35NationalParkGate_Text_OfficerExplainRules:
#if GERMAN
	.string "Wer das stärkste Käfer-Pokémon\n"
	.string "fängt, gewinnt.\p"
	.string "Wenn du keine Turnierbälle mehr\n"
	.string "hast, ist das Turnier vorbei.\p"
	.string "Du kannst bis zu fünf Pokémon\n"
	.string "fangen. Am Ende wählst du eines\l"
	.string "davon aus.\p"
	.string "Es wird bewertet und du darfst es\n"
	.string "behalten.\p"
	.string "Los! Fang das stärkste Käfer-\n"
	.string "Pokémon, das du finden kannst!$"
#else
	.string "The person who gets the strongest\n"
	.string "bug POKéMON is the winner.\p"
	.string "If you run out of SPORT BALLS,\n"
	.string "you're done.\p"
	.string "You can catch up to 5 POKéMON. At\n"
	.string "the end, you pick one of them.\p"
	.string "It will be judged, and you may\n"
	.string "keep it.\p"
	.string "Go out and catch the strongest bug\n"
	.string "POKéMON you can find!$"
#endif

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
#if GERMAN
	.string "Wenn du mehr als ein Pokémon dabei\n"
	.string "hast, musst du das erste Pokémon\l"
	.string "deines Teams einsetzen.\p"
	.string "Bist du damit einverstanden?$"
#else
	.string "If you have more than one POKéMON,\n"
	.string "you'll have to use the\l"
	.string "first POKéMON in your party.\p"
	.string "Is that OK with you?$"
#endif

Route35NationalParkGate_Text_OfficerHoldYourMon:
#if GERMAN
	.string "Gut. Wir passen währenddessen auf\n"
	.string "deine anderen Pokémon auf.$"
#else
	.string "Fine, we'll hold your other POKéMON\n"
	.string "while you compete.$"
#endif

Route35NationalParkGate_Text_MonLeftWithHelper:
#if GERMAN
	.string "Die Pokémon von {PLAYER} wurden dem\n"
	.string "Turnierhelfer übergeben.$"
#else
	.string "{PLAYER}'s POKéMON were left with\n"
	.string "the CONTEST HELPER.$"
#endif

Route35NationalParkGate_Text_TakePartInFuture:
#if GERMAN
	.string "Na gut. Wir hoffen, dass du später\n"
	.string "einmal am Turnier teilnimmst.$"
#else
	.string "OK. We hope you'll take part in the\n"
	.string "future.$"
#endif

Route35NationalParkGate_Text_FirstMonCantBattle:
#if GERMAN
	.string "Oh, oh… Das erste Pokémon in deinem\n"
	.string "Team kann nicht kämpfen.\p"
	.string "Tausche es bitte gegen das Pokémon,\n"
	.string "das am Turnier teilnehmen soll, und\l"
	.string "komm dann wieder.$"
#else
	.string "Uh-oh… The first POKéMON in your\n"
	.string "party can't battle.\p"
	.string "Please switch it with the POKéMON\n"
	.string "you want to use, then come see me.$"
#endif

Route35NationalParkGate_Text_ContestIsOver:
#if GERMAN
	.string "Das heutige Turnier ist vorbei.\p"
	.string "Wir hoffen, dass du bald wieder\n"
	.string "teilnimmst!$"
#else
	.string "Today's Contest is over.\p"
	.string "We hope you will participate in\n"
	.string "the future.$"
#endif

Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_YoungsterWonders, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BC2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Rocker:
#if GERMAN
	.string "Ich liebe Vogel-Pokémon!\p"
	.string "Letzte Nacht habe ich im Park einen\n"
	.string "Vogel vom Typ Unlicht gesehen!$"
#else
	.string "I love bird POKéMON! I found a\n"
	.string "DARK-type bird in the park\l"
	.string "last night!$"
#endif

Route35NationalParkGate_Text_BC2:
#if GERMAN
	.string "Ich hab ein Sichlor gefangen!$"
#else
	.string "I caught a whopping SCYTHER!$"
#endif

Route35NationalParkGate_Text_Beauty:
#if GERMAN
	.string "Der gewinnt immer diese Turniere!$"
#else
	.string "He always wins these contests!$"
#endif

Route35NationalParkGate_Text_WeHoldContests:
#if GERMAN
	.string "Hier im Park finden regelmäßig\n"
	.string "Käferturniere statt.\p"
	.string "Nimm doch auch einmal teil!$"
#else
	.string "We hold Contests regularly in the\n"
	.string "PARK. You should give it a shot.$"
#endif

Route35NationalParkGate_Text_YoungsterWonders:
#if GERMAN
	.string "Wann findet das nächste\n"
	.string "Käferturnier statt?$"
#else
	.string "When is the next Bug-Catching\n"
	.string "Contest going to be?$"
#endif

Route35NationalParkGate_Text_ContestExplanation:
#if GERMAN
	.string "Das Käferturnier findet jeden\n"
	.string "Dienstag, Donnerstag und Samstag\l"
	.string "statt.\p"
	.string "Für die Teilnahme gibt es einen\n"
	.string "Preis, und das gefangene\l"
	.string "Käfer-Pokémon darfst du behalten.$"
#else
	.string "The Bug-Catching Contest is held on\n"
	.string "Tuesday, Thursday and Saturday.\p"
	.string "You earn a prize for taking part,\n"
	.string "and you get to keep the bug\l"
	.string "POKéMON you catch.$"
#endif
