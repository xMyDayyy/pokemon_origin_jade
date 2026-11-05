PewterCity_Museum_1F_Frlg_MapScripts::
	.byte 0

PewterCity_Museum_1F_EventScript_Scientist1::
	lock
	faceplayer
	goto_if_eq VAR_FACING, DIR_WEST, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	goto_if_eq VAR_FACING, DIR_SOUTH, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	goto_if_eq VAR_FACING, DIR_NORTH, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	msgbox PewterCity_Museum_1F_Text_PleaseEnjoyYourself
	release
	end

PewterCity_Museum_1F_EventScript_Scientist1BehindCounter::
	msgbox PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter
	goto_if_eq VAR_RESULT, NO, PewterCity_Museum_1F_EventScript_ExplainAmber
	end

PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter::
	msgbox PewterCity_Museum_1F_Text_AmberContainsGeneticMatter
	applymovement LOCALID_MUSEUM_SCIENTIST1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Museum_1F_EventScript_ExplainAmber::
	msgbox PewterCity_Museum_1F_Text_AmberIsFossilizedSap
	applymovement LOCALID_MUSEUM_SCIENTIST1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	showmoneybox 0, 0
	msgbox PewterCity_Museum_1F_Text_Its50YForChildsTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_TryPayForTicket
	msgbox PewterCity_Museum_1F_Text_ComeAgain
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_TryPayForTicket::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NotEnoughMoney
	closemessage
	call_if_eq VAR_TEMP_1, 0, PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft
	call_if_eq VAR_TEMP_1, 1, PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid
	call_if_eq VAR_TEMP_1, 2, PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	waitse
	msgbox PewterCity_Museum_1F_Text_Right50YThankYou
	setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 1
	hidemoneybox
	releaseall
	end

PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterLeft
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterMid
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterRight
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_NotEnoughMoney::
	msgbox PewterCity_Museum_1F_Text_DontHaveEnoughMoney
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Movement_ForcePlayerExit::
	walk_down
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterLeft::
	walk_right
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterMid::
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterRight::
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_Scientist2::
	msgbox PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldAmberScientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_AMBER, PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber
	msgbox PewterCity_Museum_1F_Text_WantYouToGetAmberExamined
	checkitemspace ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NoRoomForOldAmber
	setflag FLAG_GOT_OLD_AMBER
	removeobject LOCALID_OLD_AMBER
	giveitem_msg PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan, ITEM_OLD_AMBER, 1, MUS_RG_OBTAIN_KEY_ITEM
	release
	end

PewterCity_Museum_1F_EventScript_NoRoomForOldAmber::
	msgbox PewterCity_Museum_1F_Text_DontHaveSpaceForThis
	release
	end

PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber::
	msgbox PewterCity_Museum_1F_Text_GetOldAmberChecked
	release
	end

PewterCity_Museum_1F_EventScript_OldAmber::
	msgbox PewterCity_Museum_1F_Text_BeautifulPieceOfAmber, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_AerodactylFossil::
	lockall
	setvar VAR_0x8004, SPECIES_AERODACTYL
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Museum_1F_Text_AerodactylFossil
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Museum_1F_EventScript_KabutopsFossil::
	lockall
	setvar VAR_0x8004, SPECIES_KABUTOPS
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Museum_1F_Text_KabutopsFossil
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Museum_1F_Text_Its50YForChildsTicket::
#if GERMAN
	.string "Für Kinder kostet der Eintritt ¥50!\p"
	.string "Möchtest du hinein?$"
#else
	.string "Yes, yes.\n"
	.string "It's ¥50 for a child's ticket.\p"
	.string "Would you like to come in?$"
#endif

PewterCity_Museum_1F_Text_ComeAgain::
#if GERMAN
	.string "Komm bald wieder!$"
#else
	.string "Come again!$"
#endif

PewterCity_Museum_1F_Text_Right50YThankYou::
#if GERMAN
	.string "O.K., das sind ¥50!\n"
	.string "Vielen Dank!$"
#else
	.string "Right, ¥50!\n"
	.string "Thank you!$"
#endif

PewterCity_Museum_1F_Text_DontHaveEnoughMoney::
#if GERMAN
	.string "Du hast nicht genug Geld…$"
#else
	.string "You don't have enough money.$"
#endif

PewterCity_Museum_1F_Text_PleaseEnjoyYourself::
#if GERMAN
	.string "Viel Vergnügen!$"
#else
	.string "Please enjoy yourself.$"
#endif

PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs::
#if GERMAN
	.string "Du hast hinter dem Tresen nichts zu\n"
	.string "suchen!\p"
	.string "Na ja, egal!\n"
	.string "Weißt du, was Bernstein ist?$"
#else
	.string "You can't sneak in the back way!\n"
	.string "Nice try, kid, but no.\p"
	.string "Oh, whatever!\n"
	.string "Do you know what AMBER is?$"
#endif

PewterCity_Museum_1F_Text_AmberContainsGeneticMatter::
#if GERMAN
	.string "Es soll ein Labor geben, in dem man\n"
	.string "versucht, aus altem Bernstein\l"
	.string "Urzeit-Pokémon wiederauferstehen zu\l"
	.string "lassen!$"
#else
	.string "AMBER contains the genetic matter\n"
	.string "of ancient POKéMON.\p"
	.string "There's a LAB somewhere trying to\n"
	.string "resurrect POKéMON from AMBER.$"
#endif

PewterCity_Museum_1F_Text_AmberIsFossilizedSap::
#if GERMAN
	.string "Bernstein ist versteinertes Baumharz.$"
#else
	.string "AMBER is actually sap, that gooey\n"
	.string "stuff that oozes from trees.\p"
	.string "The ancient sap fossilized over\n"
	.string "time to become rock-hard AMBER.$"
#endif

@ Unused
PewterCity_Museum_1F_Text_PleaseGoAround::
	.string "あちらへ　おまわりください$"

PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife::
#if GERMAN
	.string "Dies ist ein außergewöhnliches\n"
	.string "Fossil!$"
#else
	.string "I should be grateful for my long\n"
	.string "life.\p"
	.string "Never did I think I would get to\n"
	.string "see the bones of a dragon!$"
#endif

PewterCity_Museum_1F_Text_WantYouToGetAmberExamined::
#if GERMAN
	.string "Pst! Ich glaube, in diesem Stück\n"
	.string "Bernstein ist Pokémon-Dns enthalten!\p"
	.string "Es wäre grandios, wenn man daraus ein\n"
	.string "Pokémon wiederauferstehen lassen\l"
	.string "könnte!\p"
	.string "Doch meine Kollegen nehmen mich\n"
	.string "nicht ernst!\p"
	.string "Könntest du etwas für mich erledigen?\p"
	.string "Lass das im Pokémon-Labor\n"
	.string "untersuchen!$"
#else
	.string "Ssh! Listen, I need to share a\n"
	.string "secret with someone.\p"
	.string "I think that this chunk of AMBER\n"
	.string "contains POKéMON DNA!\p"
	.string "It would be a shattering scientific\n"
	.string "breakthrough if POKéMON could be\l"
	.string "resurrected from it.\p"
	.string "But, my colleagues just ignore\n"
	.string "what I have to say.\p"
	.string "So, I have a favor to ask!\p"
	.string "I want you to get this examined at\n"
	.string "a POKéMON LAB somewhere.$"
#endif

PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan::
#if GERMAN
	.string "{PLAYER} erhält einen Altbernstein!$"
#else
	.string "{PLAYER} received the OLD AMBER\n"
	.string "from the man.$"
#endif

PewterCity_Museum_1F_Text_GetOldAmberChecked::
#if GERMAN
	.string "Pst!\n"
	.string "Lass den Altbernstein untersuchen!$"
#else
	.string "Ssh!\n"
	.string "Get the OLD AMBER checked!$"
#endif

PewterCity_Museum_1F_Text_DontHaveSpaceForThis::
#if GERMAN
	.string "Du hast keinen Platz dafür!$"
#else
	.string "You don't have space for this.$"
#endif

PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit::
#if GERMAN
	.string "Unser besonderer Stolz sind zwei\n"
	.string "Fossilien von äußerst seltenen,\l"
	.string "prähistorischen Pokémon!$"
#else
	.string "We have two fossils of rare,\n"
	.string "prehistoric POKéMON on exhibit.$"
#endif

PewterCity_Museum_1F_Text_BeautifulPieceOfAmber::
#if GERMAN
	.string "Der Bernstein schimmert goldbraun\n"
	.string "und ist durchsichtig!$"
#else
	.string "There is a beautiful piece of\n"
	.string "AMBER in a clear gold color.$"
#endif

PewterCity_Museum_1F_Text_AerodactylFossil::
#if GERMAN
	.string "Aerodactyl-Fossil Ein urzeitliches und\n"
	.string "seltenes Pokémon.$"
#else
	.string "AERODACTYL Fossil\n"
	.string "A primitive and rare POKéMON.$"
#endif

PewterCity_Museum_1F_Text_KabutopsFossil::
#if GERMAN
	.string "Kabutops-Fossil Ein urzeitliches und\n"
	.string "seltenes Pokémon.$"
#else
	.string "KABUTOPS Fossil\n"
	.string "A primitive and rare POKéMON.$"
#endif

