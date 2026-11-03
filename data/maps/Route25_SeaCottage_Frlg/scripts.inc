.equ BILL_IN_TELEPORTER,     FLAG_TEMP_2
.equ RETURN_AFTER_SS_TICKET, FLAG_TEMP_3

Route25_SeaCottage_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_SeaCottage_OnTransition
	.byte 0

Route25_SeaCottage_OnTransition::
	call_if_unset FLAG_HELPED_BILL_IN_SEA_COTTAGE, Route25_SeaCottage_EventScript_HideClefairyBill
	call_if_set FLAG_GOT_SS_TICKET, Route25_SeaCottage_EventScript_SetReturnedAfterSSTicket
	end

Route25_SeaCottage_EventScript_HideClefairyBill::
	clearflag FLAG_HIDE_BILL_CLEFAIRY
	setobjectxyperm LOCALID_BILL_HUMAN, 3, 3
	return

Route25_SeaCottage_EventScript_SetReturnedAfterSSTicket::
	setflag RETURN_AFTER_SS_TICKET
	return

Route25_SeaCottage_EventScript_Bill::
	lock
	faceplayer
	goto_if_set RETURN_AFTER_SS_TICKET, Route25_SeaCottage_EventScript_BillGoLookAtPC
	goto_if_set FLAG_GOT_SS_TICKET, Route25_SeaCottage_EventScript_BillGoToSSAnne
	goto_if_set FLAG_HELPED_BILL_IN_SEA_COTTAGE, Route25_SeaCottage_EventScript_BillGiveSSTicket
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route25_SeaCottage_EventScript_BillAskForHelpMale
	goto_if_eq VAR_RESULT, FEMALE, Route25_SeaCottage_EventScript_BillAskForHelpFemale
	end

Route25_SeaCottage_EventScript_BillAskForHelpMale::
	msgbox Route25_SeaCottage_Text_ImBillHelpMeOutPal, MSGBOX_YESNO
	goto Route25_SeaCottage_EventScript_BillAskForHelp
	end

Route25_SeaCottage_EventScript_BillAskForHelpFemale::
	msgbox Route25_SeaCottage_Text_ImBillHelpMeOutLady, MSGBOX_YESNO
	goto Route25_SeaCottage_EventScript_BillAskForHelp
	end

Route25_SeaCottage_EventScript_BillAskForHelp::
	call_if_eq VAR_RESULT, NO, Route25_SeaCottage_EventScript_DeclineHelpBill
	msgbox Route25_SeaCottage_Text_RunCellSeparationOnPC
	closemessage
	delay 10
	call_if_eq VAR_FACING, DIR_SOUTH, Route25_SeaCottage_EventScript_BillWalkToTeleporterSouth
	call_if_eq VAR_FACING, DIR_NORTH, Route25_SeaCottage_EventScript_BillWalkToTeleporter
	call_if_eq VAR_FACING, DIR_WEST, Route25_SeaCottage_EventScript_BillWalkToTeleporter
	call_if_eq VAR_FACING, DIR_EAST, Route25_SeaCottage_EventScript_BillWalkToTeleporter
	opendoor 10, 3
	waitdooranim
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillEnterTeleporter
	waitmovement 0
	removeobject LOCALID_BILL_CLEFAIRY
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 10, 3
	waitdooranim
	setflag BILL_IN_TELEPORTER
	release
	end

@ Just returns after message, execution continues as if player had said yes
Route25_SeaCottage_EventScript_DeclineHelpBill::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route25_SeaCottage_EventScript_DeclineHelpBillMale
	call_if_eq VAR_RESULT, FEMALE, Route25_SeaCottage_EventScript_DeclineHelpBillFemale
	return

Route25_SeaCottage_EventScript_DeclineHelpBillMale::
	msgbox Route25_SeaCottage_Text_NoPleaseChief
	return

Route25_SeaCottage_EventScript_DeclineHelpBillFemale::
	msgbox Route25_SeaCottage_Text_NoPleaseBeautiful
	return

Route25_SeaCottage_EventScript_BillWalkToTeleporterSouth::
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillWalkToTeleporterSouth
	waitmovement 0
	return

Route25_SeaCottage_EventScript_BillWalkToTeleporter::
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillWalkToTeleporter
	waitmovement 0
	return

Route25_SeaCottage_EventScript_BillGoToSSAnne::
	msgbox Route25_SeaCottage_Text_SSAnnePartyYouGoInstead
	release
	end

Route25_SeaCottage_EventScript_BillGiveSSTicket::
	famechecker FAMECHECKER_BILL, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route25_SeaCottage_EventScript_BillThanksMale
	call_if_eq VAR_RESULT, FEMALE, Route25_SeaCottage_EventScript_BillThanksFemale
	checkitemspace ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, Route25_SeaCottage_EventScript_NoRoomForSSTicket
	giveitem_msg Route25_SeaCottage_Text_ReceivedSSTicketFromBill, ITEM_SS_TICKET, 1, MUS_RG_OBTAIN_KEY_ITEM
	setflag FLAG_GOT_SS_TICKET_DUP
	setflag FLAG_HIDE_NUGGET_BRIDGE_ROCKET
	setflag FLAG_GOT_SS_TICKET
	setflag FLAG_SYS_PC_LANETTE
	goto Route25_SeaCottage_EventScript_BillGoToSSAnne
	end

Route25_SeaCottage_EventScript_BillThanksMale::
	msgbox Route25_SeaCottage_Text_ThanksBudTakeThis
	return

Route25_SeaCottage_EventScript_BillThanksFemale::
	msgbox Route25_SeaCottage_Text_ThanksLadyTakeThis
	return

Route25_SeaCottage_EventScript_NoRoomForSSTicket::
	msgbox Route25_SeaCottage_Text_YouveGotTooMuchStuff
	release
	end

Route25_SeaCottage_EventScript_BillGoLookAtPC::
	call_if_set FLAG_IS_KANTO_CHAMPION, Route25_SeaCottage_EventScript_BillTryGiveBoxLink
	msgbox Route25_SeaCottage_Text_CheckOutRareMonsOnPC
	release
	end

@ Origin Jade: the Pokemon Box Link after the Kanto title (D-059).
Route25_SeaCottage_EventScript_BillTryGiveBoxLink::
	goto_if_set FLAG_RECEIVED_POKEMON_BOX_LINK, Common_EventScript_NopReturn
	msgbox Route25_SeaCottage_Text_ChampionTakeBoxLink
	giveitem ITEM_POKEMON_BOX_LINK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setflag FLAG_RECEIVED_POKEMON_BOX_LINK
	return

Route25_SeaCottage_Movement_BillWalkToTeleporter::
	walk_up
	walk_up
	step_end

Route25_SeaCottage_Movement_BillWalkToTeleporterSouth::
	walk_right
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_up
	step_end

Route25_SeaCottage_Movement_BillEnterTeleporter::
	walk_up
	step_end

Route25_SeaCottage_EventScript_Computer::
	lockall
	goto_if_set RETURN_AFTER_SS_TICKET, Route25_SeaCottage_EventScript_OpenBillsMonList
	goto_if_set BILL_IN_TELEPORTER, Route25_SeaCottage_EventScript_RunCellSeparator
	msgbox Route25_SeaCottage_Text_TeleporterIsDisplayed
	releaseall
	end

Route25_SeaCottage_EventScript_RunCellSeparator::
	fadeoutbgm 0
	msgbox Route25_SeaCottage_Text_InitiatedTeleportersCellSeparator
	closemessage
	clearflag BILL_IN_TELEPORTER
	setflag FLAG_HELPED_BILL_IN_SEA_COTTAGE
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Route25_SeaCottage_Movement_CameraPanToTeleporters
	waitmovement 0
	delay 35
	playse SE_PIN
	waitse
	setvar VAR_0x8004, 0
	special AnimateTeleporterHousing
	delay 10
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	setvar VAR_0x8004, 1
	special AnimateTeleporterHousing
	playse SE_WARP_IN
	special AnimateTeleporterCable
	waitse
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	opendoor 3, 3
	waitdooranim
	fadeinbgm 0
	addobject LOCALID_BILL_HUMAN
	clearflag FLAG_HIDE_BILL_HUMAN_SEA_COTTAGE
	delay 50
	playfanfare MUS_LEVEL_UP
	applymovement LOCALID_BILL_HUMAN, Route25_SeaCottage_Movement_BillExitTeleporter
	waitmovement 0
	waitfanfare
	applymovement LOCALID_CAMERA, Route25_SeaCottage_Movement_CameraPanBackFromTeleporters
	waitmovement 0
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 3, 3
	waitdooranim
	applymovement LOCALID_BILL_HUMAN, Route25_SeaCottage_Movement_BillWalkToMiddleOfRoom
	waitmovement 0
	special RemoveCameraObject
	releaseall
	end

Route25_SeaCottage_EventScript_PlayTeleporterBeepSE::
	playse SE_BALL
	waitse
	delay 20
	return

Route25_SeaCottage_Movement_CameraPanToTeleporters::
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route25_SeaCottage_Movement_CameraPanBackFromTeleporters::
	delay_16
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

Route25_SeaCottage_EventScript_OpenBillsMonList::
	msgbox Route25_SeaCottage_Text_BillsFavoriteMonList
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_BillsMonList::
	message Route25_SeaCottage_Text_SeeWhichMon
	waitmessage
	multichoice 0, 0, MULTI_EEVEELUTIONS, FALSE
	switch VAR_RESULT
	case 0, Route25_SeaCottage_EventScript_ViewEevee
	case 1, Route25_SeaCottage_EventScript_ViewFlareon
	case 2, Route25_SeaCottage_EventScript_ViewJolteon
	case 3, Route25_SeaCottage_EventScript_ViewVaporeon
	case 4, Route25_SeaCottage_EventScript_ExitBillsMonList
	case 127, Route25_SeaCottage_EventScript_ExitBillsMonList
	end

Route25_SeaCottage_EventScript_ViewEevee::
	showmonpic SPECIES_EEVEE, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_EEVEE
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewFlareon::
	showmonpic SPECIES_FLAREON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_FLAREON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewJolteon::
	showmonpic SPECIES_JOLTEON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_JOLTEON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewVaporeon::
	showmonpic SPECIES_VAPOREON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_VAPOREON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ExitBillsMonList::
	releaseall
	end

Route25_SeaCottage_Movement_BillWalkToMiddleOfRoom::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

Route25_SeaCottage_Movement_BillExitTeleporter::
	walk_down
	step_end

Route25_SeaCottage_Text_ImBillHelpMeOutPal::
#if GERMAN
	.string "Hallo! Ich bin ein Pokémon!\n"
	.string "Spaß beiseite, ich bin keines!\p"
	.string "Nenn mich einfach Bill! Ich bin ein\n"
	.string "waschechter Pokémaniac!\p"
	.string "Glaubst du mir nicht?\p"
	.string "Mir ist ein Experiment missglückt!\n"
	.string "Dabei wurden meine Zellen mit denen\l"
	.string "eines Pokémon kombiniert!\p"
	.string "Wie sieht es aus?\n"
	.string "Hilfst du mir?$"
#else
	.string "Hiya! I'm a POKéMON…\n"
	.string "…No I'm not!\p"
	.string "Call me BILL!\n"
	.string "I'm a true-blue POKéMANIAC!\p"
	.string "Hey!\n"
	.string "What's with that skeptical look?\p"
	.string "I'm not joshing you, pal.\p"
	.string "I screwed up an experiment and got\n"
	.string "combined with a POKéMON!\p"
	.string "So, how about it?\n"
	.string "Help me out here!$"
#endif

Route25_SeaCottage_Text_ImBillHelpMeOutLady::
#if GERMAN
	.string "Hallo! Ich bin ein Pokémon!\n"
	.string "Spaß beiseite, ich bin keines!\p"
	.string "Nenn mich einfach Bill! Ich bin ein\n"
	.string "waschechter Pokémaniac!\p"
	.string "Glaubst du mir nicht?\p"
	.string "Mir ist ein Experiment missglückt!\n"
	.string "Dabei wurden meine Zellen mit denen\l"
	.string "eines Pokémon kombiniert!\p"
	.string "Wie sieht es aus?\n"
	.string "Hilfst du mir?$"
#else
	.string "Hiya! I'm a POKéMON…\n"
	.string "…No I'm not!\p"
	.string "Call me BILL!\n"
	.string "I'm a true-blue POKéMANIAC!\p"
	.string "Hey!\n"
	.string "What's with that skeptical look?\p"
	.string "I'm not joshing you, lady.\p"
	.string "I screwed up an experiment and got\n"
	.string "combined with a POKéMON!\p"
	.string "So, how about it?\n"
	.string "Help me out here!$"
#endif

Route25_SeaCottage_Text_RunCellSeparationOnPC::
#if GERMAN
	.string "Ich gehe in den Teleporter, und du\n"
	.string "startest von meinem PC aus das\l"
	.string "Zellteilungs-Programm.$"
#else
	.string "Wait till I get inside the\n"
	.string "TELEPORTER.\p"
	.string "When I do, go to my PC and run\n"
	.string "the Cell Separation System.$"
#endif

Route25_SeaCottage_Text_NoPleaseChief::
#if GERMAN
	.string "Nein? Komm schon, ich stecke in\n"
	.string "wirklich ernsten Schwierigkeiten!\p"
	.string "Also, hilfst du mir? Bitte!\n"
	.string "O.K.? Alles klar!$"
#else
	.string "No!?\n"
	.string "Now don't be so cold!\p"
	.string "Come on, you gotta help a guy in\n"
	.string "deep, deep trouble!\p"
	.string "What do you say, chief?\n"
	.string "Please?\l"
	.string "Okay?\l"
	.string "All right!$"
#endif

Route25_SeaCottage_Text_NoPleaseBeautiful::
#if GERMAN
	.string "Nein? Komm schon, ich stecke in\n"
	.string "wirklich ernsten Schwierigkeiten!\p"
	.string "Also, hilfst du mir? Bitte!\n"
	.string "O.K.? Alles klar!$"
#else
	.string "No!?\n"
	.string "Now don't be so cold!\p"
	.string "Come on, you gotta help a guy in\n"
	.string "deep, deep trouble!\p"
	.string "What do you say, beautiful?\n"
	.string "Please?\l"
	.string "Okay?\l"
	.string "All right!$"
#endif

Route25_SeaCottage_Text_ThanksBudTakeThis::
#if GERMAN
	.string "Bill: Klasse! Danke, Kumpel!\n"
	.string "Du hast bei mir etwas gut!\p"
	.string "Bist du hier, um dir meine Pokémon-\n"
	.string "Sammlung anzusehen?\p"
	.string "Nein?\n"
	.string "Das ist schade!\p"
	.string "Wie kann ich dir nur danken?\n"
	.string "Nimm einfach das hier...$"
#else
	.string "BILL: Yeehah!\n"
	.string "Thanks, bud! I owe you one!\p"
	.string "So, did you come to see my\n"
	.string "POKéMON collection?\p"
	.string "You didn't?\n"
	.string "That's a bummer.\p"
	.string "I've got to thank you…\n"
	.string "Oh, here, maybe this'll do.$"
#endif

Route25_SeaCottage_Text_ThanksLadyTakeThis::
#if GERMAN
	.string "Bill: Klasse! Danke, Kleine!\n"
	.string "Du hast bei mir etwas gut!\p"
	.string "Bist du hier, um dir meine Pokémon-\n"
	.string "Sammlung anzusehen?\p"
	.string "Nein?\n"
	.string "Das ist schade!\p"
	.string "Wie kann ich dir nur danken?\n"
	.string "Nimm einfach das hier...$"
#else
	.string "BILL: Yeehah!\n"
	.string "Thanks, lady! I owe you one!\p"
	.string "So, did you come to see my\n"
	.string "POKéMON collection?\p"
	.string "You didn't?\n"
	.string "That's a bummer.\p"
	.string "I've got to thank you…\n"
	.string "Oh, here, maybe this'll do.$"
#endif

Route25_SeaCottage_Text_ReceivedSSTicketFromBill::
#if GERMAN
	.string "{PLAYER} erhält ein Bootsticket!$"
#else
	.string "{PLAYER} received an S.S. TICKET\n"
	.string "from BILL.$"
#endif

Route25_SeaCottage_Text_YouveGotTooMuchStuff::
#if GERMAN
	.string "Heh Kiddie! Du trägst zu viel mit\n"
	.string "dir herum!$"
#else
	.string "You've got too much stuff!$"
#endif

Route25_SeaCottage_Text_SSAnnePartyYouGoInstead::
#if GERMAN
	.string "In Orania City ankert ein großes\n"
	.string "Kreuzfahrtschiff, die M.S. Anne!\p"
	.string "An Bord befinden sich nur Trainer!\p"
	.string "Sie haben mich zu einer Party\n"
	.string "eingeladen, aber ich mag so viel Trubel\l"
	.string "nicht.\p"
	.string "Hättest du Lust, hinzugehen?$"
#else
	.string "That cruise ship S.S. ANNE is in\n"
	.string "VERMILION CITY.\p"
	.string "I hear there are lots of TRAINERS\n"
	.string "on board, too.\p"
	.string "They invited me to their party, but\n"
	.string "I can't stand fancy do's.\p"
	.string "Why don't you go instead of me?\n"
	.string "Go on and have a good time.$"
#endif

Route25_SeaCottage_Text_CheckOutRareMonsOnPC::
#if GERMAN
	.string "Bill: Schau dir doch einfach auf dem PC\n"
	.string "ein paar meiner seltenen Pokémon an!$"
#else
	.string "BILL: Feel like checking out some\n"
	.string "of my rare POKéMON on my PC?\p"
	.string "Go on, check out my PC.$"
#endif

Route25_SeaCottage_Text_TeleporterIsDisplayed::
#if GERMAN
	.string "Auf dem PC läuft ein Programm zur\n"
	.string "Steuerung des Teleporters.$"
#else
	.string "TELEPORTER is displayed on the PC\n"
	.string "monitor.$"
#endif

Route25_SeaCottage_Text_InitiatedTeleportersCellSeparator::
#if GERMAN
	.string "{PLAYER} hat den Zell-Separator in\n"
	.string "Gang gesetzt!$"
#else
	.string "{PLAYER} initiated the TELEPORTER's\n"
	.string "Cell Separator.$"
#endif

Route25_SeaCottage_Text_BillsFavoriteMonList::
#if GERMAN
	.string "Eine Liste von Bills Lieblings-\n"
	.string "Pokémon!$"
#else
	.string "BILL's favorite POKéMON list!$"
#endif

Route25_SeaCottage_Text_SeeWhichMon::
#if GERMAN
	.string "Welches Pokémon möchtest du\n"
	.string "betrachten?$"
#else
	.string "Which POKéMON do you want to see?$"
#endif


Route25_SeaCottage_Text_ChampionTakeBoxLink::
#if GERMAN
	.string "Bill: Du hast die Liga besiegt?\n"
	.string "Wahnsinn!\p"
	.string "Dann nimm das hier. Mit der\n"
	.string "Pokémon-Box kommst du überall an\l"
	.string "die Boxen meines PCs!$"
#else
	.string "BILL: You beat the POKéMON LEAGUE?\n"
	.string "Amazing!\p"
	.string "Then take this. With the POKéMON\n"
	.string "BOX LINK, you can reach the BOXES\l"
	.string "of my PC from anywhere!$"
#endif

@ Origin Jade: Bill's grandfather from HnS's Bill's house. After the Kanto
@ title he asks to see four Pokemon in turn and gives EXP Candies L (D-059).
Route25_SeaCottage_EventScript_Grandpa::
	lock
	faceplayer
	goto_if_set FLAG_IS_KANTO_CHAMPION, Route25_SeaCottage_EventScript_GrandpaAfterTitle
	msgbox Route25_SeaCottage_Text_GrandpaIntro, MSGBOX_DEFAULT
	release
	end

Route25_SeaCottage_EventScript_GrandpaAfterTitle::
	goto_if_ge VAR_SEA_COTTAGE_GRANDPA, 5, Route25_SeaCottage_EventScript_GrandpaShownAll
	goto_if_ne VAR_SEA_COTTAGE_GRANDPA, 0, Route25_SeaCottage_EventScript_GrandpaAsk
	msgbox Route25_SeaCottage_Text_GrandpaIntro, MSGBOX_DEFAULT
	setvar VAR_SEA_COTTAGE_GRANDPA, 1
Route25_SeaCottage_EventScript_GrandpaAsk::
	call_if_eq VAR_SEA_COTTAGE_GRANDPA, 1, Route25_SeaCottage_EventScript_GrandpaHintMeowth
	call_if_eq VAR_SEA_COTTAGE_GRANDPA, 2, Route25_SeaCottage_EventScript_GrandpaHintZigzagoon
	call_if_eq VAR_SEA_COTTAGE_GRANDPA, 3, Route25_SeaCottage_EventScript_GrandpaHintPonyta
	call_if_eq VAR_SEA_COTTAGE_GRANDPA, 4, Route25_SeaCottage_EventScript_GrandpaHintFarfetchd
	msgbox Route25_SeaCottage_Text_GrandpaAskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route25_SeaCottage_EventScript_GrandpaDeclined
	msgbox Route25_SeaCottage_Text_GrandpaExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_SeaCottage_EventScript_GrandpaDeclined
	copyvar VAR_0x8005, VAR_0x8004
	specialvar VAR_RESULT, GetTradeSpecies
	goto_if_eq VAR_SEA_COTTAGE_GRANDPA, 1, Route25_SeaCottage_EventScript_GrandpaCheckMeowth
	goto_if_eq VAR_SEA_COTTAGE_GRANDPA, 2, Route25_SeaCottage_EventScript_GrandpaCheckZigzagoon
	goto_if_eq VAR_SEA_COTTAGE_GRANDPA, 3, Route25_SeaCottage_EventScript_GrandpaCheckPonyta
	goto_if_eq VAR_SEA_COTTAGE_GRANDPA, 4, Route25_SeaCottage_EventScript_GrandpaCheckFarfetchd
	release
	end

Route25_SeaCottage_EventScript_GrandpaHintMeowth::
	msgbox Route25_SeaCottage_Text_GrandpaMeowth, MSGBOX_DEFAULT
	return

Route25_SeaCottage_EventScript_GrandpaHintZigzagoon::
	msgbox Route25_SeaCottage_Text_GrandpaZigzagoon, MSGBOX_DEFAULT
	return

Route25_SeaCottage_EventScript_GrandpaHintPonyta::
	msgbox Route25_SeaCottage_Text_GrandpaPonyta, MSGBOX_DEFAULT
	return

Route25_SeaCottage_EventScript_GrandpaHintFarfetchd::
	msgbox Route25_SeaCottage_Text_GrandpaFarfetchd, MSGBOX_DEFAULT
	return

Route25_SeaCottage_EventScript_GrandpaCheckMeowth::
	goto_if_ne VAR_RESULT, SPECIES_MEOWTH, Route25_SeaCottage_EventScript_GrandpaWrongMon
	bufferspeciesname STR_VAR_1, SPECIES_MEOWTH
	setvar VAR_0x8006, 1
	goto Route25_SeaCottage_EventScript_GrandpaReward
	end

Route25_SeaCottage_EventScript_GrandpaCheckZigzagoon::
	goto_if_ne VAR_RESULT, SPECIES_ZIGZAGOON, Route25_SeaCottage_EventScript_GrandpaWrongMon
	bufferspeciesname STR_VAR_1, SPECIES_ZIGZAGOON
	setvar VAR_0x8006, 3
	goto Route25_SeaCottage_EventScript_GrandpaReward
	end

Route25_SeaCottage_EventScript_GrandpaCheckPonyta::
	goto_if_eq VAR_RESULT, SPECIES_RAPIDASH, Route25_SeaCottage_EventScript_GrandpaRightPonyta
	goto_if_ne VAR_RESULT, SPECIES_PONYTA, Route25_SeaCottage_EventScript_GrandpaWrongMon
Route25_SeaCottage_EventScript_GrandpaRightPonyta::
	bufferspeciesname STR_VAR_1, SPECIES_PONYTA
	setvar VAR_0x8006, 5
	goto Route25_SeaCottage_EventScript_GrandpaReward
	end

Route25_SeaCottage_EventScript_GrandpaCheckFarfetchd::
	goto_if_ne VAR_RESULT, SPECIES_FARFETCHD, Route25_SeaCottage_EventScript_GrandpaWrongMon
	bufferspeciesname STR_VAR_1, SPECIES_FARFETCHD
	setvar VAR_0x8006, 7
	goto Route25_SeaCottage_EventScript_GrandpaReward
	end

Route25_SeaCottage_EventScript_GrandpaReward::
	msgbox Route25_SeaCottage_Text_GrandpaShownPokemon, MSGBOX_DEFAULT
	msgbox Route25_SeaCottage_Text_GrandpaThanks, MSGBOX_DEFAULT
	giveitem ITEM_EXP_CANDY_L, VAR_0x8006
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	addvar VAR_SEA_COTTAGE_GRANDPA, 1
	msgbox Route25_SeaCottage_Text_GrandpaComeAgain, MSGBOX_DEFAULT
	release
	end

Route25_SeaCottage_EventScript_GrandpaDeclined::
	msgbox Route25_SeaCottage_Text_GrandpaYouDontHaveIt, MSGBOX_DEFAULT
	release
	end

Route25_SeaCottage_EventScript_GrandpaWrongMon::
	msgbox Route25_SeaCottage_Text_GrandpaWrongPokemon, MSGBOX_DEFAULT
	release
	end

Route25_SeaCottage_EventScript_GrandpaShownAll::
	msgbox Route25_SeaCottage_Text_GrandpaShownAll, MSGBOX_DEFAULT
	release
	end

Route25_SeaCottage_Text_GrandpaIntro::
#if GERMAN
	.string "Hm? Kennst du Bill? Er ist mein\n"
	.string "Enkel.\p"
	.string "Er tüftelt ständig an seinen PCs,\n"
	.string "also schaue ich ab und zu nach ihm.$"
#else
	.string "Hm? You know BILL? He's my\n"
	.string "grandson.\p"
	.string "He's always tinkering with his\n"
	.string "PCs, so I look in on him now and\l"
	.string "then.$"
#endif

Route25_SeaCottage_Text_GrandpaMeowth::
#if GERMAN
	.string "Mein Enkel Bill hat mir von einem\n"
	.string "Pokémon mit scharfen Krallen und\l"
	.string "einem Talisman auf der Stirn erzählt.\p"
	.string "Es soll Glück bringen.$"
#else
	.string "My grandson BILL told me about\n"
	.string "a POKéMON that has sharp claws,\l"
	.string "a charm on its head, and is\p"
	.string "said to bring good fortune.$"
#endif

Route25_SeaCottage_Text_GrandpaZigzagoon::
#if GERMAN
	.string "Bill hat ein Pokémon erwähnt, das im\n"
	.string "Zickzack herumläuft.\p"
	.string "Es soll ein richtiger kleiner\n"
	.string "Sammler sein.$"
#else
	.string "BILL mentioned a POKéMON that\n"
	.string "runs around in a zigzag\l"
	.string "pattern.\p"
	.string "It's quite the little\n"
	.string "scavenger, I hear.$"
#endif

Route25_SeaCottage_Text_GrandpaPonyta::
#if GERMAN
	.string "Kennst du ein Pokémon mit einer\n"
	.string "feurigen Mähne?\p"
	.string "Es soll schneller laufen als die\n"
	.string "meisten Züge.$"
#else
	.string "Do you know of a POKéMON with\n"
	.string "a fiery mane?\p"
	.string "I hear it can run faster than\n"
	.string "most trains.$"
#endif

Route25_SeaCottage_Text_GrandpaFarfetchd::
#if GERMAN
	.string "Bill hat mir von einem Pokémon\n"
	.string "erzählt, das immer eine Lauchstange\l"
	.string "bei sich trägt.\p"
	.string "Ein seltsames Geschöpf.$"
#else
	.string "BILL told me about a POKéMON\n"
	.string "that always carries a stalk\l"
	.string "of leek with it.\p"
	.string "Quite the peculiar creature.$"
#endif

Route25_SeaCottage_Text_GrandpaAskToSeeMon::
#if GERMAN
	.string "Hast du so ein Pokémon? Wenn ja,\n"
	.string "dann würde ich es gerne sehen…$"
#else
	.string "If you have that POKéMON, may I\n"
	.string "see it, please?$"
#endif

Route25_SeaCottage_Text_GrandpaExcitedToSee::
#if GERMAN
	.string "Oh, du willst mir echt eins zeigen?\n"
	.string "Wie lieb von dir!$"
#else
	.string "You will show me? How good of\n"
	.string "you!$"
#endif

Route25_SeaCottage_Text_GrandpaYouDontHaveIt::
#if GERMAN
	.string "Ach so, schade…$"
#else
	.string "You don't have it?\n"
	.string "That's too bad…$"
#endif

Route25_SeaCottage_Text_GrandpaShownPokemon::
#if GERMAN
	.string "Ah, das ist {STR_VAR_1}?\p"
	.string "Ist das nicht niedlich! Das ist nett\n"
	.string "von dir.$"
#else
	.string "Ah, so that is {STR_VAR_1}?\p"
	.string "Isn't it cute! That's so kind\n"
	.string "of you.$"
#endif

Route25_SeaCottage_Text_GrandpaThanks::
#if GERMAN
	.string "Danke!\p"
	.string "Das ist ein Zeichen meiner\n"
	.string "Anerkennung.$"
#else
	.string "Thanks!\p"
	.string "This is a token of my\n"
	.string "appreciation.$"
#endif

Route25_SeaCottage_Text_GrandpaComeAgain::
#if GERMAN
	.string "Besuche mich bitte mal wieder!$"
#else
	.string "Come visit again sometime.$"
#endif

Route25_SeaCottage_Text_GrandpaShownAll::
#if GERMAN
	.string "Danke, dass du mir so viele niedliche\n"
	.string "Pokémon gezeigt hast!\l"
	.string "Ich habe mich wirklich gut amüsiert.\p"
	.string "Das verleiht mir richtig Lebensenergie!$"
#else
	.string "Thanks for showing me so many\n"
	.string "cute POKéMON.\p"
	.string "I really enjoyed myself. I'm\n"
	.string "glad I've lived such a long life.$"
#endif

Route25_SeaCottage_Text_GrandpaWrongPokemon::
#if GERMAN
	.string "Hm…\p"
	.string "Ich glaube, das ist nicht das Pokémon,\n"
	.string "von dem ich gehört habe…$"
#else
	.string "Hm?\p"
	.string "That's not the POKéMON that I\n"
	.string "was told about.$"
#endif
