Route39_Barn_hns_MapScripts::
	.byte 0

Route39_Barn_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	goto_if_eq VAR_ROUTE39_BARN, 0, Route39_Barn_EventScript_Miltank_NeedBerries5
	goto_if_eq VAR_ROUTE39_BARN, 1, Route39_Barn_EventScript_Miltank_NeedBerries4
	goto_if_eq VAR_ROUTE39_BARN, 2, Route39_Barn_EventScript_Miltank_NeedBerries3
	goto_if_eq VAR_ROUTE39_BARN, 3, Route39_Barn_EventScript_Miltank_NeedBerries2
	goto_if_eq VAR_ROUTE39_BARN, 4, Route39_Barn_EventScript_Miltank_NeedBerries1
	msgbox Route39_Text_MoomooHappyMoo, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Barn_EventScript_Miltank_NeedBerries5::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused

	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnLittleHealthier, MSGBOX_DEFAULT
	closemessage

	setvar VAR_ROUTE39_BARN, 1
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries4::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused

	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnLittleHealthier, MSGBOX_DEFAULT
	closemessage

	setvar VAR_ROUTE39_BARN, 2
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries3::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused
	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnQuiteHealthy, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE39_BARN, 3
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries2::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused
	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnQuiteHealthy, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE39_BARN, 4
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries1::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused
	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnTotallyHealthy, MSGBOX_DEFAULT
	playfanfare MUS_HEAL 
	waitfanfare
	closemessage
	setvar VAR_ROUTE39_BARN, 5
	release
	end

Route39_Barn_EventScript_Miltank_Refused::
	msgbox Route39_Text_BarnRefusedBerry, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Barn_EventScript_Miltank_NoBerries::
	msgbox Route39_Text_BarnNoBerries, MSGBOX_DEFAULT
	release
	end

Route39_Barn_EventScript_Twins::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39_Barn_EventScript_TwinsAfter
	msgbox Route39_Text_BarnTwinMoomooIsSick, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Barn_EventScript_TwinsAfter::
	msgbox Route39_Text_BarnTwinFeedingMoomoo
	closemessage
	release
	end

Route39_Text_BarnTwinMoomooIsSick:
#if GERMAN
	.string "Unser Miltank ist krank…\p"
	.string "Es braucht ganz viele Sinelbeeren.$"
#else
	.string "MOOMOO is sick…\p"
	.string "She needs lots of ORAN BERRIES.$"
#endif

Route39_Text_BarnTwinFeedingMoomoo:
#if GERMAN
	.string "Unserem Miltank geht es wieder gut!\n"
	.string "Vielen Dank!$"
#else
	.string "MOOMOO is all better!\n"
	.string "Thank you!$"
#endif

Route39_Text_MoomooWeakMoo:
#if GERMAN
	.string "Miltank: …Muh…$"
#else
	.string "MILTANK: …Moo…$"
#endif

Route39_Text_BarnCryIsWeak:
#if GERMAN
	.string "Sein Ruf klingt schwach…\n"
	.string "Miltank eine Sinelbeere geben?$"
#else
	.string "Its cry is weak…\n"
	.string "Give an ORAN BERRY to MILTANK?$"
#endif

Route39_Text_MoomooHappyMoo:
#if GERMAN
	.string "Miltank: Muuuh!$"
#else
	.string "MILTANK: Mooo!$"
#endif

Route39_Text_BarnGaveBerry:
#if GERMAN
	.string "{PLAYER} gibt Miltank eine\n"
	.string "Sinelbeere.$"
#else
	.string "{PLAYER} gave an ORAN BERRY to\n"
	.string "MILTANK.$"
#endif

Route39_Text_BarnLittleHealthier:
#if GERMAN
	.string "Miltank geht es schon ein\n"
	.string "wenig besser!$"
#else
	.string "MILTANK became a little\n"
	.string "healthier!$"
#endif

Route39_Text_BarnQuiteHealthy:
#if GERMAN
	.string "Miltank geht es schon viel\n"
	.string "besser!$"
#else
	.string "MILTANK became quite\n"
	.string "healthy!$"
#endif

Route39_Text_BarnTotallyHealthy:
#if GERMAN
	.string "Miltank ist wieder ganz\n"
	.string "gesund!$"
#else
	.string "MILTANK became totally\n"
	.string "healthy!$"
#endif

Route39_Text_BarnNoBerries:
#if GERMAN
	.string "{PLAYER} hat keine Sinelbeeren…$"
#else
	.string "{PLAYER} has no ORAN BERRIES…$"
#endif

Route39_Text_BarnRefusedBerry:
#if GERMAN
	.string "{PLAYER} gibt Miltank keine\n"
	.string "Sinelbeere.\p"
	.string "Miltank sieht traurig aus.$"
#else
	.string "{PLAYER} wouldn't give an\n"
	.string "ORAN BERRY.\p"
	.string "MILTANK looks sad.$"
#endif
