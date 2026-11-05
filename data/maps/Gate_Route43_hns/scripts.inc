Gate_Route43_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Gate_Route43_Rocket_OnFrame
	.byte 0

Gate_Route43_Rocket_OnFrame::
	map_script_2 VAR_TEMP_0, 0, Gate_Route43_RocketChecker
	.2byte 0

Gate_Route43_RocketChecker::
	setvar VAR_TEMP_0, 1
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 1, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 2, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 4, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 5, Gate_Route43_Rocket_EventScript_Shakedown
	end

Gate_Route43_Rocket_EventScript_Shakedown::
	lock
	showmoneybox 0, 0
	msgbox Gate_Route43_Rocket_Text_TollFee, MSGBOX_DEFAULT
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, Gate_Route43_Rocket_EventScript_ShakedownBroke
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Gate_Route43_Rocket_Text_ThankYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_ShakedownBroke::
	checkmoney 1
	goto_if_eq VAR_RESULT, FALSE, Gate_Route43_Rocket_EventScript_KickOut
	msgbox Gate_Route43_Rocket_Text_AllYouGot, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Gate_Route43_Rocket_Text_ThankYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_KickOut::
	msgbox Gate_Route43_Rocket_Text_KickOut, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_Policeman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_FROM_MAHOGANY_COP, Gate_Route43_Rocket_EventScript_PolicemanAfter
	msgbox Route43Gate_Text_OfficerFoundTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	setflag FLAG_GOT_TM_FROM_MAHOGANY_COP
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_PolicemanAfter::
	msgbox Gate_Route43_Text_OfficerAvoidGrass, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_Rockets::
	msgbox Gate_Route43_Rocket_Text_MakingABundle, MSGBOX_NPC
	end

Gate_Route43_Rocket_Text_TollFee:
#if GERMAN
	.string "Halt, Kleiner!\p"
	.string "Die Maut beträgt ¥500, um\n"
	.string "durchzugehen.$"
#else
    .string "Hold it there, kiddo!\p"
    .string "The toll is ¥500 to go\n"
    .string "through.$"
#endif

Gate_Route43_Rocket_Text_ThankYou:
#if GERMAN
	.string "Hehehe! Du bist ein guter Kunde!$"
#else
    .string "Thank you very much!$"
#endif

Gate_Route43_Rocket_Text_AllYouGot:
#if GERMAN
	.string "Dann zahl, was du hast, bitte.$"
#else
    .string "Then pay what you have, please.$"
#endif

Gate_Route43_Rocket_Text_KickOut:
#if GERMAN
	.string "Wow!\p"
	.string "Du bist total pleite!\p"
	.string "Fast schon Mitleid mit dir.\p"
	.string "Okay, du darfst durch…\p"
	.string "Sag es aber nicht dem anderen\n"
	.string "Wächter, verstanden?$"
#else
	.string "Wow!\p"
	.string "You're totally broke!\p"
	.string "I almost feel sorry for you.\p"
	.string "Okay, you can pass...\p"
	.string "Just don't tell the other guard,\n"
	.string "okay?$"
#endif

Gate_Route43_Rocket_Text_MakingABundle:
#if GERMAN
	.string "Hehehe, seitdem das Gerücht kursiert,\n"
	.string "dass am See des Zorns irgendwas ganz\l"
	.string "Merkwürdiges im Busch sein soll,\l"
	.string "strömen die Leute hier in Massen durch!$"
#else
    .string "He-he-he. We're making a bundle.\p"
    .string "Everyone wants to see what's going\n"
    .string "on up at LAKE OF RAGE.$"
#endif

Route43Gate_Text_OfficerFoundTM:
#if GERMAN
	.string "Ich wurde von diesen Dieben von meinem\n"
	.string "Posten vertrieben.\p"
	.string "Sie haben das hier liegen lassen.\p"
	.string "Es macht mir Angst. Könntest du\n"
	.string "es wegnehmen?$"
#else
    .string "I got chased from my post by these\n"
    .string "thugs in black.\p"
    .string "They left this behind.\p"
    .string "It makes me uncomfortable. Could\n"
    .string "you take it away?$"
#endif

Gate_Route43_Text_ReceivedTM30:
#if GERMAN
	.string "{PLAYER} erhielt TM36.$"
#else
    .string "{PLAYER} received TM36.$"
#endif

Gate_Route43_Text_OfficerAvoidGrass:
#if GERMAN
	.string "Benutze dieses Tor, um nicht durch\n"
	.string "das Gras zu laufen.$"
#else
    .string "Use this gate to avoid walking in\n"
    .string "the grass.$"
#endif
