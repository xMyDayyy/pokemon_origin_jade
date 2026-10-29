GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_GoodToSeeYouLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem_unless_owned ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
#if IS_HNS
	closemessage
#else
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
#endif
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_GoodToSeeYouLetterForMe:
#if GERMAN
	.string "Troy: Hi, {PLAYER}!\n"
	.string "Schön, dich wiederzusehen.\p"
	.string "Was ich hier in der Grotte mache?\p"
	.string "Ich bin auf der Suche nach seltenen\n"
	.string "Steinen.\p"
	.string "Oh? Ein Brief? Für mich?$"
#else
	.string "STEVEN: Hi, {PLAYER}!\n"
	.string "Good to see you again.\p"
	.string "What am I doing here in the cave?\p"
	.string "I'm looking for rare stones.\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"
#endif

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
#if GERMAN
	.string "Troy: Okay, danke schön.\p"
	.string "Du hast all die Beschwerlichkeiten auf\n"
	.string "dich genommen, um ihn mir zu bringen.\l"
	.string "\p"
	.string "Ich muss mich bedanken. Ehrlich.\n"
	.string "Ich werde dir diese TM geben.\p"
	.string "Sie enthält meine Lieblingsattacke,\n"
	.string "Stahlflügel.$"
#else
	.string "STEVEN: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "STEEL WING.$"
#endif

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
#if GERMAN
	.string "Troy: Deine Pokémon sehen recht\n"
	.string "talentiert aus.\p"
	.string "Ich weiß ja, wie gut du bist - deshalb\n"
	.string "habe ich dich nach Hoenn geholt.\p"
	.string "Du wirst auch hier Champ. Daran habe\n"
	.string "ich keinen Zweifel.$"
#else
	.string "STEVEN: Your POKéMON appear quite\n"
	.string "capable.\p"
	.string "I know how good you are - that's why\n"
	.string "I brought you to HOENN.\p"
	.string "You'll be CHAMPION here as well.\n"
	.string "I have no doubt about it.$"
#endif

GraniteCave_StevensRoom_Text_RegisteredSteven:
#if GERMAN
	.string "Troy wurde im PokéCom-Verzeichnis\n"
	.string "eingetragen.$"
#else
	.string "Registered STEVEN\n"
	.string "in the POKéGEAR.$"
#endif

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
#if GERMAN
	.string "Nun muss ich mich aber wirklich\n"
	.string "beeilen.$"
#else
	.string "Now, I've got to hurry along.$"
#endif

GraniteCave_StevensRoom_Text_OhBagIsFull:
#if GERMAN
	.string "Oh, dein Beutel ist voll.\n"
	.string "Das ist aber wirklich schade.$"
#else
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"
#endif

