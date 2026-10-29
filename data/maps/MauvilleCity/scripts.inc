MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
#if IS_HNS
	giveitem ITEM_NEW_MAUVILLE_KEY
#else
	giveitem ITEM_BASEMENT_KEY
#endif
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem_unless_owned ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
#if GERMAN
	.string "Onkel: Ich glaube, es liegt an dem\n"
	.string "Pokémon, dass dieser Junge mehr Pep\l"
	.string "hat. Aber er hat zu viel Pep…$"
#else
	.string "UNCLE: It's because of POKéMON that\n"
	.string "this boy's got more pep, I suppose…\l"
	.string "But he's become a bit too peppy…$"
#endif

MauvilleCity_Text_WallyWantToChallengeGym:
#if GERMAN
	.string "Heiko: Oooch, bitte, Onkel, bitte!\p"
	.string "Ich möchte in dieser Arena antreten,\n"
	.string "um zu sehen, wie gut ich bin.\p"
	.string "Bitte! Darf ich? Biiiitte!$"
#else
	.string "WALLY: Aww, UNCLE, please?\p"
	.string "I want to challenge this GYM and see\n"
	.string "how much better I've become.\p"
	.string "Please? May I, please?$"
#endif

MauvilleCity_Text_UncleYourePushingIt:
#if GERMAN
	.string "Onkel: Nun hör mal auf, Heiko.\p"
	.string "Seit du mit Pokémon zusammenlebst,\n"
	.string "bist du viel stärker geworden.\p"
	.string "Aber - du überforderst dich, wenn du\n"
	.string "plötzlich in einer Arena antrittst.$"
#else
	.string "UNCLE: Now hold on, WALLY.\p"
	.string "Since you started living with POKéMON,\n"
	.string "you have grown quite a lot stronger.\p"
	.string "But don't you think you're pushing it\n"
	.string "to suddenly challenge a GYM?$"
#endif

MauvilleCity_Text_WallyWeCanBeatAnyone:
#if GERMAN
	.string "Heiko: Ich bin nicht überfordert!\p"
	.string "Wenn ich mich mit meinem Pokémon\n"
	.string "zusammentue, besiege ich jeden!$"
#else
	.string "WALLY: I'm not pushing it.\p"
	.string "If I combine forces with my POKéMON,\n"
	.string "we can beat anyone!$"
#endif

MauvilleCity_Text_WallyWillYouBattleMe:
#if GERMAN
	.string "Heiko: Oh! Hi {PLAYER}!\p"
	.string "Seit wir uns das letzte Mal gesehen\n"
	.string "haben, bin ich viel stärker geworden.\l"
	.string "\p"
	.string "{PLAYER}, ich möchte von dir und auch\n"
	.string "von meinem Onkel verstanden werden.\p"
	.string "{PLAYER}, bitte, würdest du gegen mich\n"
	.string "kämpfen?$"
#else
	.string "WALLY: Oh! Hi, {PLAYER}!\p"
	.string "I've gotten a lot stronger since\n"
	.string "we met.\p"
	.string "{PLAYER}, I want you and my UNCLE to\n"
	.string "understand that.\p"
	.string "{PLAYER}, please, will you have\n"
	.string "a battle with me?$"
#endif

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
#if GERMAN
	.string "Heiko: Oh… Wenn du nicht gegen mich\n"
	.string "antreten willst, {PLAYER}, wird mein\p"
	.string "Onkel nie erkennen, wie stark ich schon\n"
	.string "bin.$"
#else
	.string "WALLY: Oh… If you won't battle me,\n"
	.string "{PLAYER}, my UNCLE won't know that I've\l"
	.string "become really strong.$"
#endif

MauvilleCity_Text_UncleCanYouBattleWally:
#if GERMAN
	.string "Onkel: {PLAYER}{KUN}, richtig?\n"
	.string "Darf ich dich um Heikos Willen bitten,\l"
	.string "dieses eine Mal gegen ihn zu kämpfen?\l"
	.string "\p"
	.string "Ich glaube nicht, dass er mir im\n"
	.string "Moment überhaupt zuhören will…$"
#else
	.string "UNCLE: {PLAYER}{KUN}, was it?\n"
	.string "On WALLY's behalf, can I ask you to\l"
	.string "battle with him just this once?\p"
	.string "I don't think he's going to listen to\n"
	.string "any reason the way he is now.$"
#endif

MauvilleCity_Text_WallyPleaseBattleMe:
#if GERMAN
	.string "Heiko: {PLAYER}, bitte!\n"
	.string "Kämpfe gegen mich! Biiiitte!$"
#else
	.string "WALLY: {PLAYER}, please!\n"
	.string "Battle with me, please.$"
#endif

MauvilleCity_Text_WallyHereICome:
#if GERMAN
	.string "Heiko: {PLAYER}, vielen Dank!\p"
	.string "Okay… Jetzt komme ich!$"
#else
	.string "WALLY: {PLAYER}, thank you.\p"
	.string "Okay… Here I come!$"
#endif

MauvilleCity_Text_WallyDefeat:
#if GERMAN
	.string "Heiko: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "Ich habe verloren…$"
#else
	.string "WALLY: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "I lost…$"
#endif

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
#if GERMAN
	.string "Heiko: Onkel…\n"
	.string "Ich gehe zurück nach Wiesenflur…$"
#else
	.string "WALLY: UNCLE…\n"
	.string "I'll go back to VERDANTURF…$"
#endif

MauvilleCity_Text_ThankYouNotEnoughToBattle:
#if GERMAN
	.string "{PLAYER}, herzlichen Dank! Trainer zu\n"
	.string "sein verlangt viel von einem, oder?\p"
	.string "Man besitzt nicht einfach nur Pokémon\n"
	.string "und lässt sie kämpfen. Um ein richtiger\l"
	.string "Trainer zu sein, braucht es mehr.$"
#else
	.string "{PLAYER}, thank you.\n"
	.string "Being a TRAINER is tough, isn't it?\p"
	.string "It's not enough just to have POKéMON\n"
	.string "and make them battle. That isn't what\l"
	.string "being a real TRAINER is about.$"
#endif

MauvilleCity_Text_UncleNoNeedToBeDown:
#if GERMAN
	.string "Onkel: Heiko, du brauchst deshalb\n"
	.string "nicht so niedergeschlagen zu sein.\p"
	.string "Was hält dich davon ab, stärker und\n"
	.string "stärker zu werden? Nichts!\p"
	.string "Komm, gehen wir nach Hause.\n"
	.string "Da warten sie alle schon auf dich.$"
#else
	.string "UNCLE: WALLY, there's no need to be so\n"
	.string "down on yourself.\p"
	.string "Why, what's keeping you from becoming\n"
	.string "stronger and stronger?\p"
	.string "Come on, let's go home.\n"
	.string "Everyone's waiting for you.$"
#endif

MauvilleCity_Text_UncleVisitUsSometime:
#if GERMAN
	.string "Onkel: {PLAYER}{KUN}, mir dämmert\n"
	.string "es so langsam. Du musst der Trainer\l"
	.string "sein,\p"
	.string "der sich damals um Heiko gekümmert hat,\n"
	.string "als er sein erstes Pokémon fing.\p"
	.string "Warum besuchst du uns nicht irgendwann\n"
	.string "in Wiesenflur? Ich bin sicher, Heiko\l"
	.string "würde sich sehr freuen.$"
#else
	.string "UNCLE: {PLAYER}{KUN}, it just dawned on me\n"
	.string "that you must be the TRAINER who kept\l"
	.string "an eye out for WALLY when he caught\l"
	.string "his POKéMON.\p"
	.string "Why don't you visit us in VERDANTURF\n"
	.string "sometime?\l"
	.string "I'm sure WALLY would enjoy it.$"
#endif


MauvilleCity_Text_WallyPokenavCall:
#if GERMAN
	.string "… … … … … … … … … … … …\p"
	.string "Heiko: Oh, hallo {PLAYER}!\p"
	.string "Ich muss dir was erzählen! Mein\n"
	.string "Onkel hat mir einen PokéCom\l"
	.string "gegeben.\p"
	.string "Nun kann ich mit dir reden, wann\n"
	.string "immer ich möchte, {PLAYER}!\p"
	.string "… … … … … … … … … … … Klick!$"
#else
	.string "… … … … … … … … … … … Beep!\p"
	.string "WALLY: Oh, hello, {PLAYER}!\p"
	.string "I just wanted to tell you that\n"
	.string "my uncle bought me a POKéGEAR!\p"
	.string "Now I can get in touch with you\n"
	.string "anytime, {PLAYER}!\p"
	.string "… … … … … … … … … … … Click!$"
#endif

MauvilleCity_Text_RegisteredWally:
#if GERMAN
	.string "Heiko wurde im PokéCom-Verzeichnis\n"
	.string "eingetragen.$"
#else
	.string "Registered WALLY\n"
	.string "in the POKéGEAR.$"
#endif

MauvilleCity_Text_ScottYouDidntHoldBack:
#if GERMAN
	.string "Scott: Hehe…\n"
	.string "Ich habe diesen Kampf beobachtet!\p"
	.string "Du bist ein Freund von diesem Jungen,\n"
	.string "von Heiko, oder?\p"
	.string "Aber du hast dich nicht zurückgehalten\n"
	.string "und ihn beeindruckend besiegt.\p"
	.string "Yeah! Das ist es, was Pokémon-Kämpfe\n"
	.string "ausmacht!\p"
	.string "Ich bewundere solche Trainer!\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "Ich feure dich an!$"
#else
	.string "SCOTT: Hehe…\n"
	.string "I was watching that match!\p"
	.string "You're friends with that boy WALLY,\n"
	.string "aren't you?\p"
	.string "But you didn't hold anything back\n"
	.string "and beat him impressively.\p"
	.string "Yeah! That's what a real POKéMON\n"
	.string "battle is all about!\p"
	.string "I idolize TRAINERS like that!\p"
	.string "… … … … … …\n"
	.string "I'll be cheering for you!$"
#endif

MauvilleCity_Text_WattsonNeedFavorTakeKey:
#if GERMAN
	.string "Walter: Oh, {PLAYER}{KUN}!\n"
	.string "Du siehst aus, als hättest du Mumm!\l"
	.string "Das ist sehr gut, hähähähähä…\p"
	.string "Gut! Ich habe es entschieden!\n"
	.string "Du tust mir einen Gefallen,\l"
	.string "{PLAYER}{KUN}! \p"
	.string "Malvenfroh City hat einen\n"
	.string "unterirdischen Bereich, der neu\l"
	.string "Malvenfroh heißt.\p"
	.string "{PLAYER}{KUN}, ich schicke dich\n"
	.string "jetzt da hinunter, damit du den\l"
	.string "Generator ausschaltest.\p"
	.string "Der Generator ist kurz davor, \n"
	.string "heißzulaufen. Das ist sehr gefährlich.\l"
	.string "\p"
	.string "Hier hast du den Schlüssel für\n"
	.string "Neu Malvenfroh.$"
#else
	.string "WATTSON: Oh, {PLAYER}{KUN}!\n"
	.string "You look like you have a lot of zip!\l"
	.string "That's a good thing, wahahahaha!\p"
	.string "Fine! I've decided!\n"
	.string "I need a favor, {PLAYER}{KUN}!\p"
	.string "MAUVILLE CITY has an underground\n"
	.string "sector called NEW MAUVILLE.\p"
	.string "{PLAYER}{KUN}, I'd like you to go there and\n"
	.string "switch off the GENERATOR.\p"
	.string "The GENERATOR has been running a bit\n"
	.string "haywire. It's getting unsafe.\p"
	.string "Here, this is the KEY to get into\n"
	.string "NEW MAUVILLE.$"
#endif

MauvilleCity_Text_WattsonWontBeChallenge:
#if GERMAN
	.string "Walter: Mach dir keine Sorgen. Man kann\n"
	.string "das nicht gerade eine Herausforderung\l"
	.string "nennen.\p"
	.string "Der Eingang zu neu Malvenfroh ist eine\n"
	.string "kurze Surf-Strecke von Route 110\l"
	.string "entfernt.\p"
	.string "Das ist alles. Du kannst mir vertrauen!\n"
	.string "Wahahahahahaha!$"
#else
	.string "WATTSON: Don't you worry about it.\n"
	.string "It won't be a challenge to you.\p"
	.string "The entrance to NEW MAUVILLE is just\n"
	.string "a short SURF away from ROUTE 110.\p"
	.string "That's it, then, you have my trust!\n"
	.string "Wahahahaha!$"
#endif

MauvilleCity_Text_WattsonThanksTakeTM:
#if GERMAN
	.string "Walter: Wahahahahaha!\p"
	.string "Ich wusste es, {PLAYER}{KUN}! Ich\n"
	.string "wusste, ich habe die richtige Person\l"
	.string "herausgepickt!\p"
	.string "Hier, das ist mein Dankeschön - eine\n"
	.string "TM, die Donnerblitz enthält!\p"
	.string "Nimm! Du hast sie dir wirklich verdient!$"
#else
	.string "WATTSON: Wahahahaha!\p"
	.string "I knew it, {PLAYER}{KUN}! I knew I'd made\n"
	.string "the right choice asking you!\p"
	.string "This is my thanks--a TM containing\n"
	.string "THUNDERBOLT!\p"
	.string "Go on, you've earned it!$"
#endif

MauvilleCity_Text_WattsonYoungTakeCharge:
#if GERMAN
	.string "Walter: Wahahahahaha!\p"
	.string "Es freut mich zu sehen, wie energetisch\n"
	.string "sich die jungen Leute heute\p"
	.string "entwickeln!$"
#else
	.string "WATTSON: Wahahahaha!\p"
	.string "It pleases me to no end to see\n"
	.string "the young step up and take charge!$"
#endif

MauvilleCity_Text_NurseHurtMonBackToHealth:
#if GERMAN
	.string "Weißt du, es ist cool, dass es\n"
	.string "Pokémon-Kämpfe und all das Zeugs gibt…\p"
	.string "Aber wenn dein Pokémon verletzt wird,\n"
	.string "dann musst du es gesund pflegen.$"
#else
	.string "You know, it's cool to have POKéMON\n"
	.string "battles and stuff…\p"
	.string "But if your POKéMON gets hurt,\n"
	.string "you have to nurse it back to health.$"
#endif

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
#if GERMAN
	.string "Die Straßen dieses Ortes führen nach\n"
	.string "Norden, Süden, nach Westen und Osten.\l"
	.string "\p"
	.string "Daher reisen hier auch so viele ver-\n"
	.string "schiedene Leute durch.$"
#else
	.string "The roads of this town stretch north\n"
	.string "and south, and east and west.\p"
	.string "Because of that, we get all sorts of\n"
	.string "people coming through.$"
#endif

MauvilleCity_Text_RydelVeryGenerous:
#if GERMAN
	.string "Warst du schon in Radlas Radladen?\p"
	.string "Radla, der Eigentümer, ist ein sehr\n"
	.string "großzügiger Mann.$"
#else
	.string "Have you been to RYDEL'S CYCLES yet?\p"
	.string "RYDEL, the owner, is a very generous\n"
	.string "man.$"
#endif

MauvilleCity_Text_PokemonCanJumpYouOnBike:
#if GERMAN
	.string "Selbst wenn du mit dem Rad fährst,\n"
	.string "können dich Pokémon anspringen.$"
#else
	.string "Even if you're riding a BIKE,\n"
	.string "wild POKéMON could jump you.$"
#endif

MauvilleCity_Text_CitySign:
#if GERMAN
	.string "Malvenfroh City\n"
	.string "“Die strahlende Stadt der Freude!”$"
#else
	.string "MAUVILLE CITY\n"
	.string "“The bright and shiny city of fun!”$"
#endif

MauvilleCity_Text_GymSign:
#if GERMAN
	.string "Pokémon Arena von Malvenfroh City\n"
	.string "Leiter: Walter “Der Mann, der Spannung\l"
	.string "entlädt!”$"
#else
	.string "MAUVILLE CITY POKéMON GYM\n"
	.string "LEADER: WATTSON\l"
	.string "“The cheerfully electrifying man!”$"
#endif

MauvilleCity_Text_BikeShopSign:
#if GERMAN
	.string "Radlas Räder “Fahre im Kies und lass\n"
	.string "dich durchschütteln!”$"
#else
	.string "“Ride in gravel and shake up your\n"
	.string "soul!”\l"
	.string "RYDEL'S CYCLES$"
#endif

MauvilleCity_Text_GameCornerSign:
#if GERMAN
	.string "Malvenfroh City Spielhalle\n"
	.string "“Der Ort für alle Spieler!”$"
#else
	.string "“The play spot for all!”\n"
	.string "MAUVILLE GAME CORNER$"
#endif

MauvilleCity_Text_ExplainTV:
#if GERMAN
	.string "Hi, hast du in letzter Zeit\n"
	.string "ferngesehen?\p"
	.string "Da gibt es jetzt jede Menge coole,\n"
	.string "neue Shows.\p"
	.string "Fernsehen ist so cool. Plötzlich habe\n"
	.string "ich meine Freunde im Fernsehen gesehen.\p"
	.string "Und manchmal, da zeigen sie dich im\n"
	.string "Fernsehen und du weißt es gar nicht.\p"
	.string "Ich möchte auch mal im Fernsehen sein.\n"
	.string "\p"
	.string "Du solltest immer mal wieder den\n"
	.string "Fernseher einschalten…$"
#else
	.string "Hi, do you check out TV at all?\p"
	.string "They've added a bunch of cool new\n"
	.string "shows recently.\p"
	.string "TV is so cool. I've seen my friends on\n"
	.string "TV just out of the blue.\p"
	.string "And, sometimes, they even put you on TV\n"
	.string "without telling you.\p"
	.string "I wish I would be on TV sometime.\p"
	.string "That's why I think you should check\n"
	.string "out TVs whenever you can.$"
#endif

MauvilleCity_Text_BeenCheckingOutTV:
#if GERMAN
	.string "Hi, hast du in letzter Zeit\n"
	.string "ferngesehen?$"
#else
	.string "Hi, have you been checking out TVs?$"
#endif
