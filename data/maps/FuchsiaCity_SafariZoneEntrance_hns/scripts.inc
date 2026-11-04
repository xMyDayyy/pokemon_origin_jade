FuchsiaCity_SafariZoneEntrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZoneEntrance_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_SafariZoneEntrance_OnTransition
	.byte 0

FuchsiaCity_SafariZoneEntrance_OnFrame::
	map_script_2 VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari
	.2byte 0

FuchsiaCity_SafariZoneEntrance_OnTransition::
	call_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_FirstTime
	end

FuchsiaCity_SafariZoneEntrance_FirstTime::
	setobjectxyperm LOCALID_SAFARIZONEFUCHSIA_STEVEN, 4, 10
	setobjectmovementtype LOCALID_SAFARIZONEFUCHSIA_STEVEN, MOVEMENT_TYPE_FACE_LEFT
	end

FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone
	waitmovement 0
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH_HNS, 0
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN

	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome, MSGBOX_DEFAULT
	closemessage
	checkitem ITEM_POKEBLOCK_CASE
	call_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase

	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable
	waitmovement 0
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 1
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	return

FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase:
#if GERMAN
	.string "Ach ja, das hier könntest du noch\n"
	.string "gebrauchen.$"
#else
	.string "Oh and you might need this.$"
#endif

FuchsiaCity_SafariZoneEntrance_Steven::
	lock
	faceplayer
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_SafariZoneEntrance_EventScript_Steven_Trade
	goto_if_set FLAG_IS_KANTO_CHAMPION, FuchsiaCity_SafariZoneEntrance_StevenChamp
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Steven, MSGBOX_NPC
	release
	end

FuchsiaCity_SafariZoneEntrance_StevenChamp::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenChamp, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenChamp:
#if GERMAN
	.string "Oh, hallo {PLAYER}.\n"
	.string "Oder soll ich sagen: Kanto-Champion?\p"
	.string "Weißt du, eine Zeit lang war ich\n"
	.string "Champion der Hoenn-Region.\p"
	.string "Willkommen im Club, {PLAYER}.\p"
	.string "Hier, nimm das als kleines\n"
	.string "Willkommensgeschenk.$"
#else
	.string "Oh, hey {PLAYER}.\n"
	.string "Or should I say KANTO champion?\p"
	.string "You know, for some time, I was the\n"
	.string "champion of the HOENN region.\p"
	.string "So welcome to the club, {PLAYER}.\p"
	.string "In fact, here.\n"
	.string "Consider this a welcome gift.$"
#endif

FuchsiaCity_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase
	call FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 4, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft
	call_if_eq VAR_TEMP_0, 6, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	setflag FLAG_IN_KANTO_SAFARI_ZONE
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH_HNS, 1
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_up
	walk_up
	walk_up
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer:
	walk_right
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome:
#if GERMAN
	.string "Ich heiße Troy. Meine Familie hat\n"
	.string "kürzlich diese Safari-Zone gekauft und\l"
	.string "viele Verbesserungen vorgenommen.\p"
	.string "Hier findest du sehr exotische Pokémon.\n"
	.string "Besonders, wenn du dein Safari-Level\l"
	.string "erhöhst.\p"
	.string "Sprich einfach mit dem Aufseher hier, um\n"
	.string "dein Safari-Level jederzeit zu\l"
	.string "steigern.$"
#else
	.string "Hello again, {PLAYER}!\p"
	.string "Welcome to the DEVON SAFARI ZONE!\p"
	.string "This specially designed safari\n"
	.string "has 4 different habitats that\l"
	.string "attract and house different invasive\l"
	.string "species from the HOENN region.\p"
	.string "We encourage trainers to capture\n"
	.string "as many as they can to safely\l"
	.string "remove them from the environment.\p"
	.string "You'll find very rare POKéMON\n"
	.string "here. Especially if you increase\l"
	.string "your SAFARI LEVEL.\p"
	.string "Just speak to the attendant here\n"
	.string "any time to increase your SAFARI\l"
	.string "LEVEL.$"
#endif

FuchsiaCity_SafariZoneEntrance_UpgradeGuy::
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 1, FuchsiaCity_SafariZoneEntrance_UpgradeGuy1
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 2, FuchsiaCity_SafariZoneEntrance_UpgradeGuy2
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 3, FuchsiaCity_SafariZoneEntrance_UpgradeGuy3
	msgbox FuchsiaCity_SafariZoneEntrance_Text_MaxLevel, MSGBOX_NPC
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy1::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 200000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 200000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 2
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy2::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 300000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 300000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 3
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy3::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 400000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 400000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 4
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_Text_Steven:
#if GERMAN
	.string "Oh, hallo, {PLAYER}.\p"
	.string "Ich hoffe, die Safari gefällt dir.\p"
	.string "Hast du in letzter Zeit seltene\n"
	.string "Steine gesehen?$"
#else
	.string "Oh, hey, {PLAYER}.\p"
	.string "I hope you're enjoying the SAFARI.\p"
	.string "Have you seen any rare stones\n"
	.string "lately?$"
#endif

FuchsiaCity_SafariZoneEntrance_Text_Level1:
#if GERMAN
	.string "Hallo {PLAYER}, möchtest du dein\n"
	.string "Safari-Level auf 2 erhöhen?\l"
	.string "Das kostet ¥200.000.$"
#else
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 2? It will cost you ¥200,000.$"
#endif

FuchsiaCity_SafariZoneEntrance_Text_Level2:
#if GERMAN
	.string "Hallo {PLAYER}, möchtest du dein\n"
	.string "Safari-Level auf 3 erhöhen?\l"
	.string "Das kostet ¥300.000.$"
#else
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 3? It will cost you ¥300,000.$"
#endif

FuchsiaCity_SafariZoneEntrance_Text_Level3:
#if GERMAN
	.string "Hallo {PLAYER}, möchtest du dein\n"
	.string "Safari-Level auf 4 erhöhen?\l"
	.string "Das kostet ¥400.000.$"
#else
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 4? It will cost you ¥400,000.$"
#endif

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined:
#if GERMAN
	.string "Oh, das ist schade…$"
#else
	.string "Oh, that's too bad, then...$"
#endif

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted:
#if GERMAN
	.string "Genieße die Premium-Safari-Zone!$"
#else
	.string "Enjoy the premium SAFARI ZONE\n"
	.string "experience!$"
#endif

FuchsiaCity_SafariZoneEntrance_EventScript_Steven_Trade::
	goto_if_set FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED, FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted
	ingame_trade INGAME_TRADE_BELDUM, FuchsiaCity_SafariZoneEntrance_Text_StevenWantToTrade, FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineTrade, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotRequestedMon, FuchsiaCity_SafariZoneEntrance_Text_StevenTakeCare
	setflag FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineTrade::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenDeclineTrade, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenNotRequestedMon, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenTradeCompleted, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenWantToTrade:
#if GERMAN
	.string "Sag, {PLAYER}…\n"
	.string "Ich habe dieses Tanhel jetzt eine\l"
	.string "ganze Weile aufgezogen.\p"
	.string "Aber ich denke, es ist besser\n"
	.string "bei einem Trainer wie dir aufgehoben.\p"
	.string "Tauschst du mir ein {STR_VAR_1}\n"
	.string "für mein {STR_VAR_2}?$"
#else
	.string "Say, {PLAYER}…\n"
	.string "I've been raising this BELDUM\l"
	.string "for a while now.\p"
	.string "But I think it would do better\n"
	.string "with a trainer like you.\p"
	.string "Would you trade me a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"
#endif

FuchsiaCity_SafariZoneEntrance_Text_StevenTakeCare:
#if GERMAN
	.string "Exzellent!\n"
	.string "Gib gut acht auf Eisen.$"
#else
	.string "Excellent!\n"
	.string "Please take good care of IRON.$"
#endif

FuchsiaCity_SafariZoneEntrance_Text_StevenDeclineTrade:
#if GERMAN
	.string "Schon okay.\n"
	.string "Das Angebot steht noch, falls du deine\l"
	.string "Meinung änderst.$"
#else
	.string "That's all right.\n"
	.string "The offer stands if you change\l"
	.string "your mind.$"
#endif

FuchsiaCity_SafariZoneEntrance_Text_StevenNotRequestedMon:
#if GERMAN
	.string "Hmm, das ist kein {STR_VAR_1}.\n"
	.string "Das hatte ich nicht im Sinn.$"
#else
	.string "Hmm, that's not a {STR_VAR_1}.\n"
	.string "That's not quite what I had\l"
	.string "in mind.$"
#endif

FuchsiaCity_SafariZoneEntrance_Text_StevenTradeCompleted:
#if GERMAN
	.string "Wie geht es Eisen?\n"
	.string "Tanhel sind faszinierende Pokémon.\p"
	.string "Sie kommunizieren mit magnetischen\n"
	.string "Impulsen.$"
#else
	.string "How is IRON doing?\n"
	.string "BELDUM are fascinating POKéMON.\p"
	.string "They communicate with each other\n"
	.string "using magnetic pulses.$"
#endif

FuchsiaCity_SafariZoneEntrance_Text_MaxLevel:
#if GERMAN
	.string "Hallo {PLAYER}, danke, dass du\n"
	.string "weiterhin Premium-Mitglied der\l"
	.string "Fuchsania City Safari-Zone bist.$"
#else
	.string "Hello {PLAYER}, thank you for\n"
	.string "continuing to be a premium member\l"
	.string "at the FUCHSIA SAFARI ZONE.$"
#endif
