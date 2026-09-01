SafariZoneGate_SafariZoneEntrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZoneGate_SafariZoneEntrance_OnFrame
	.byte 0

SafariZoneGate_SafariZoneEntrance_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 3, SafariZoneGate_SafariZoneEntrance_MeetBaoba
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SafariZoneGate_SafariZoneEntrance_EventScript_ExitSafari
	.2byte 0

SafariZoneGate_SafariZoneEntrance_EventScript_ExitSafari::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_ReenterSafari
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_ReenterSafari::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	warp MAP_SAFARI_ZONE_ENTERANCE_HNS, 0
	delay 120
	end

SafariZoneGate_SafariZoneEntrance_MeetBaoba::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFARIZONEGATE_BAOBA
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, SafariZoneGate_SafariZoneEntrance_Movement_WalkToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement LOCALID_SAFARIZONEGATE_BAOBA
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaWelcome, MSGBOX_DEFAULT
	closemessage
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaPokeblocks, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	applymovement LOCALID_SAFARIZONEGATE_BAOBA, SafariZoneGate_SafariZoneEntrance_Movement_ReturnToTable
	waitmovement 0
	setvar VAR_SAFARI_ZONE_GATE_STATE, 4
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Baoba::
	lock
	faceplayer
	goto_if_eq VAR_BAOBA_QUEST_STATE, 1, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBeach
	goto_if_eq VAR_BAOBA_QUEST_STATE, 2, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBrush
	goto_if_eq VAR_BAOBA_QUEST_STATE, 3, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaMountain
	goto_if_eq VAR_BAOBA_QUEST_STATE, 4, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaCave
	goto_if_ge VAR_BAOBA_QUEST_STATE, 5, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDone
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Baoba, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBeach::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 1
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBeachDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 200000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 2
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaBrush::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBrush, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 2
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaBrushDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 300000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 3
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaMountain::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaMountain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 3
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaMountainDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 400000
	delay 60
	playse SE_SHOP
	updatemoneybox
	delay 60
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 4
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaCave::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaCave, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	special ChoosePartyMon
	waitstate
	lockall
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined
	baobacheckmon 4
	goto_if_eq VAR_RESULT, FALSE, SafarioneEntrance_EventScript_BaobaWrong
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaCaveDone, MSGBOX_DEFAULT
	showmoneybox 0, 0
	addmoney 400000
	delay 20
	playse SE_SHOP
	updatemoneybox
	delay 20
	closemessage
	hidemoneybox
	setvar VAR_BAOBA_QUEST_STATE, 5
	release
	end

SafarioneEntrance_EventScript_BaobaWrong::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaWrong, MSGBOX_DEFAULT
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDeclined:
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BaobaDone::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BaobaDone, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Test::
	givemon SPECIES_BELDUM, 5
	givemon SPECIES_CASTFORM, 5
	givemon SPECIES_MEDICHAM, 5
	givemon SPECIES_BAGON, 5
	end

SafariZoneGate_SafariZoneEntrance_Text_BaobaBeachDone:
#if GERMAN
	.string "Danke, {PLAYER}!\n"
	.string "Nimm dieses Geld, um dein Safari-Level\l"
	.string "aufzuwerten, und zeig mir als Nächstes\l"
	.string "ein seltenes Pokémon aus dem\l"
	.string "Busch-Bereich!$"
#else
	.string "Thank you, {PLAYER}!\n"
	.string "Here, take this money to upgrade\l"
	.string "your SAFARI LEVEL and show me an\l"
	.string "exotic POKéMON from the BRUSH area\l"
	.string "next!$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaBrushDone:
#if GERMAN
	.string "Danke, {PLAYER}!\n"
	.string "Nimm dieses Geld, um dein Safari-Level\l"
	.string "aufzuwerten, und zeig mir als Nächstes\l"
	.string "ein seltenes Pokémon aus dem\l"
	.string "Berg-Bereich!$"
#else
	.string "Thank you, {PLAYER}!\n"
	.string "Here, take this money to upgrade\l"
	.string "your SAFARI LEVEL and show me an\l"
	.string "exotic POKéMON from the MOUNTAIN\l"
	.string "area next!$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaMountainDone:
#if GERMAN
	.string "Danke, {PLAYER}!\n"
	.string "Nimm dieses Geld, um dein Safari-Level\l"
	.string "aufzuwerten, und zeig mir als Nächstes\l"
	.string "ein seltenes Pokémon aus dem\l"
	.string "Höhlen-Bereich!$"
#else
	.string "Thank you, {PLAYER}!\n"
	.string "Here, take this money to upgrade\l"
	.string "your SAFARI LEVEL and show me an\l"
	.string "exotic POKéMON from the CAVE area\l"
	.string "next!$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaCaveDone:
#if GERMAN
	.string "Danke, {PLAYER}!\n"
	.string "Das ist alles, was ich sehen wollte.\p"
	.string "Jetzt weiß ich, was Devon plant, und\n"
	.string "kann mithalten.\l"
	.string "Nimm das hier als Belohnung für deine\l"
	.string "Mühe.$"
#else
	.string "Thank you, {PLAYER}!\n"
	.string "That's all I need to see.\p"
	.string "Now that I know what DEVON is up\n"
	.string "to, I'll be able to keep my SAFARI\l"
	.string "competitive. Here, take this as a\l"
	.string "reward for your troubles.$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaWrong:
#if GERMAN
	.string "Das kann nicht stimmen!$"
#else
	.string "That can't be right!$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaBeach:
#if GERMAN
	.string "Ah, {PLAYER}!\p"
	.string "Hast du mir ein seltenes Pokémon aus\n"
	.string "dem Strand-Bereich der Safarizone\l"
	.string "mitgebracht?$"
#else
	.string "Ah, {PLAYER}!\p"
	.string "Did you bring an exotic POKéMON\n"
	.string "from the BEACH area of the FUCHSIA\l"
	.string "SAFARI ZONE to show me?$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaBrush:
#if GERMAN
	.string "Ah, {PLAYER}!\p"
	.string "Hast du mir ein seltenes Pokémon aus\n"
	.string "dem Busch-Bereich der Safarizone\l"
	.string "mitgebracht?$"
#else
	.string "Ah, {PLAYER}!\p"
	.string "Did you bring an exotic POKéMON\n"
	.string "from the BRUSH area of the FUCHSIA\l"
	.string "SAFARI ZONE to show me?$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaMountain:
#if GERMAN
	.string "Ah, {PLAYER}!\p"
	.string "Hast du mir ein seltenes Pokémon aus\n"
	.string "dem Berg-Bereich der Safarizone\l"
	.string "mitgebracht?$"
#else
	.string "Ah, {PLAYER}!\p"
	.string "Did you bring an exotic POKéMON\n"
	.string "from the MOUNTAIN area of the\l"
	.string "FUCHSIA SAFARI ZONE to show me?$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaCave:
#if GERMAN
	.string "Ah, {PLAYER}!\p"
	.string "Hast du mir ein seltenes Pokémon aus\n"
	.string "dem Höhlen-Bereich der Safarizone\l"
	.string "mitgebracht?$"
#else
	.string "Ah, {PLAYER}!\p"
	.string "Did you bring an exotic POKéMON\n"
	.string "from the CAVE area of the FUCHSIA\l"
	.string "SAFARI ZONE to show me?$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaDeclined:
#if GERMAN
	.string "Was soll ich jetzt tun?\n"
	.string "Wir können mit Devon nie mithalten!$"
#else
	.string "What will I do now?\n"
	.string "We'll never keep up with DEVON!$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaLastMon:
#if GERMAN
	.string "Ich kann nicht dein letztes Pokémon\n"
	.string "nehmen!$"
#else
	.string "I can't take your last POKéMON!$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaDone:
#if GERMAN
	.string "Ah, {PLAYER}!\p"
	.string "Dank dir floriert die Safarizone!\p"
	.string "Vielleicht sollte ich dich zum\n"
	.string "Besitzer ernennen…\p"
	.string "Nein, das wäre absurd.\n"
	.string "Hahahaha.$"
#else
	.string "Ah, {PLAYER}!\p"
	.string "Thanks to you, the SAFARI ZONE is\n"
	.string "thriving!\p"
	.string "Maybe I should name you OWNER of\n"
	.string "the safari zone...\p"
	.string "No, that would be ridiculous.\n"
	.string "Ahahahaha.$"
#endif

SafariZoneGate_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZoneGate_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, SafariZoneGate_SafariZoneEntrance_EventScript_NoPokeblockCase
	call SafariZoneGate_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, SafariZoneGate_SafariZoneEntrance_EventScript_NotEnoughMoney
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
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_SAFARI_ZONE_ENTERANCE_HNS, 0
	waitstate
	end

SafariZoneGate_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

SafariZoneGate_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

SafariZoneGate_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SafariZoneGate_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Boy::
	lock
	faceplayer
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, SafariZoneGate_SafariZoneEntrance_EventScript_BoyGiveExtraPokeblockCase
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_BoyGiveExtraPokeblockCase::
	msgbox SafariZoneGate_SafariZoneEntrance_Text_BoyGiveCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_EventScript_Engineer::
	lock
	faceplayer
	msgbox SafariZoneGate_SafariZoneEntrance_Text_Engineer, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_down
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_up
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_WalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

SafariZoneGate_SafariZoneEntrance_Movement_ReturnToTable:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SafariZoneGate_SafariZoneEntrance_Text_BaobaWelcome:
#if GERMAN
	.string "Hallo {PLAYER}!\n"
	.string "Ich hab auf dich gewartet.\l"
	.string "Na, was sagst du?\p"
	.string "Das hier ist übrigens eine brandneue\n"
	.string "Safarizone…\p"
	.string "Und sie wächst noch!\p"
	.string "Bisher sind zwei Zonen offen und 4\n"
	.string "weitere in Planung!\p"
	.string "Viel Spaß in der Safarizone!\n"
	.string "Ich ruf dich, wenn die anderen Zonen\l"
	.string "fertig sind!$"
#else
	.string "Hi {PLAYER}!\n"
	.string "I've been waiting for you.\n"
	.string "What do you think?\p"
	.string "This is a brand new SAFARI ZONE\n"
	.string "by the way...\p"
	.string "And it's still expanding!\p"
	.string "So far, we have two zones open\n"
	.string "and 4 more on the way!\p"
	.string "Enjoy the SAFARI ZONE! I'll\n"
	.string "call you when the other zones\l"
	.string "are ready!$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BaobaPokeblocks:
#if GERMAN
	.string "Oh! Fast vergessen.\p"
	.string "Pokériegel sind ein wichtiger Teil\n"
	.string "meiner Safarizone - nimm am besten\l"
	.string "welche mit!$"
#else
	.string "Oh! I almost forgot.\p"
	.string "POKéBLOCKS are an essential\n"
	.string "feature of my SAFARI ZONE, so\l"
	.string "you'd better have one of these!$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_Baoba:
#if GERMAN
	.string "Hallo {PLAYER}!\p"
	.string "Wie gefällt dir die Safarizone?$"
#else
	.string "Hi {PLAYER}!\p"
	.string "How are you enjoying the SAFARI\n"
	.string "ZONE?$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_Boy:
#if GERMAN
	.string "Ich hab gehört, die neue Zone\n"
	.string "soll Drachen-Pokémon haben!$"
#else
	.string "I heard the new zone they\n"
	.string "are working on has dragons!$"
#endif

SafariZoneGate_SafariZoneEntrance_Text_BoyGiveCase:
	.string "Here, you seem like you need this.$"

SafariZoneGate_SafariZoneEntrance_Text_Engineer:
#if GERMAN
	.string "Sorry, Trainer! Dieser Bereich ist noch\n"
	.string "im Bau. Schau später nochmal vorbei!$"
#else
	.string "Sorry Trainer, this area is still\n"
	.string "under construction. Check back\l"
	.string "later!$"
#endif
