VermilionCity_PortInside_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionPortFrlg_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionPortFrlg_OnFrame
	.byte 0

@ The M.S. Aqua lies here once her maiden voyage from Olivine is done, see docs/origin_jade/DECISIONS.md, D-029.
VermilionPortFrlg_OnTransition::
	setflag FLAG_HIDE_VERMILION_SS_AQUA
	call_if_ge VAR_SSAQUA_STATE, 7, VermilionPortFrlg_EventScript_ShowSSAqua
	end

VermilionPortFrlg_EventScript_ShowSSAqua::
	clearflag FLAG_HIDE_VERMILION_SS_AQUA
	return

VermilionPortFrlg_OnFrame::
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 1, VermilionPortFrlg_EventScript_SSAnneDeparts
	.2byte 0

@ Phase 2: the S.S. Anne sets sail once the player has HM01.
VermilionPortFrlg_EventScript_SSAnneDeparts::
	lockall
	delay 30
	playse SE_SHIP
	removeobject LOCALID_VERMILION_PORT_FRLG_SS_ANNE
	setflag FLAG_HIDE_SS_ANNE
	delay 60
	msgbox VermilionPortFrlg_Text_SSAnneDeparted, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
	releaseall
	end

@ Phase 1: the S.S. Anne is in port.
VermilionPortFrlg_EventScript_BoardSSAnne::
	msgbox VermilionPortFrlg_Text_FlashTicket, MSGBOX_DEFAULT
	msgbox VermilionPortFrlg_Text_AllAboardSSAnne, MSGBOX_DEFAULT
	call VermilionPortFrlg_EventScript_EnterShip
	warpsilent MAP_SSANNE_1F_CORRIDOR, 19, 2
	waitstate
	release
	end

@ Phase 3: no ship in port until the first Johto title.
VermilionPortFrlg_EventScript_NoShipInPort::
	msgbox VermilionPortFrlg_Text_NoShipInPort, MSGBOX_DEFAULT
	closemessage
	release
	end

@ After the first Johto title the M.S. Aqua starts in Olivine; Vermilion follows after the maiden voyage.
VermilionPortFrlg_EventScript_FirstTripFromOlivine::
	msgbox VermilionPortFrlg_Text_FirstTripFromOlivine, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPortFrlg_Text_SSAnneDeparted:
#if GERMAN
	.string "Die M.S. Anne hat abgelegt.\p"
	.string "Sie kehrt so bald nicht zurück.$"
#else
	.string "The S.S. ANNE has set sail.\p"
	.string "She won't return for a long time.$"
#endif

VermilionPortFrlg_Text_AllAboardSSAnne:
#if GERMAN
	.string "Willkommen an Bord der M.S. Anne!\n"
	.string "Hier entlang, bitte.$"
#else
	.string "Welcome aboard the S.S. ANNE!\n"
	.string "Right this way, please.$"
#endif

VermilionPortFrlg_Text_NoShipInPort:
#if GERMAN
	.string "Zurzeit liegt kein Schiff im Hafen.\p"
	.string "Schau doch später noch einmal\n"
	.string "vorbei.$"
#else
	.string "There's no ship in port right now.\p"
	.string "Come back another time.$"
#endif

@ Talks about the M.S. Aqua once she calls here.
VermilionPortIndoorFrlg_EventScript_Teacher::
	lock
	faceplayer
	goto_if_lt VAR_SSAQUA_STATE, 7, VermilionPortIndoorFrlg_EventScript_TeacherNoShip
	msgbox VermilionPortPassageFrlg_Text_Teacher, MSGBOX_DEFAULT
	release
	end

VermilionPortIndoorFrlg_EventScript_TeacherNoShip::
	msgbox VermilionPortPassageFrlg_Text_TeacherNoShip, MSGBOX_DEFAULT
	release
	end

VermilionPortIndoorFrlg_EventScript_Nerd::
	msgbox VermilionPortFrlg_Text_SuperNerd, MSGBOX_NPC
	end

VermilionPortPassageFrlg_Text_Teacher:
#if GERMAN
	.string "Das Schnellboot M.S. Aqua legt hier\n"
	.string "jeden Tag ab!$"
#else
	.string "The FAST SHIP S.S.AQUA leaves here\n"
	.string "every day!$"
#endif

VermilionPortPassageFrlg_Text_TeacherNoShip:
#if GERMAN
	.string "Ich warte auf das Schnellboot\n"
	.string "M.S. Aqua.\p"
	.string "Es soll eines Tages auch hier\n"
	.string "anlegen!$"
#else
	.string "I'm waiting for the FAST SHIP\n"
	.string "S.S.AQUA.\p"
	.string "They say it'll dock here\n"
	.string "someday!$"
#endif

VermilionPortFrlg_Text_SuperNerd:
#if GERMAN
	.string "In Johto sollen viele seltene\n"
	.string "Pokémon leben.\p"
	.string "Eines Tages fahre ich mit dem\n"
	.string "Schiff dorthin!$"
#else
	.string "I hear many rare POKéMON live\n"
	.string "in JOHTO.\p"
	.string "Someday I'll take a ship there!$"
#endif

VermilionPortFrlg_EventScript_Sailor::
	lock
	faceplayer
	@ Phase 1: S.S. Anne
	goto_if_unset FLAG_HIDE_SS_ANNE, VermilionPortFrlg_EventScript_SSAnnePresent
	@ Phase 3: no ship until the first Johto title
	goto_if_unset FLAG_IS_JOHTO_CHAMPION, VermilionPortFrlg_EventScript_NoShipInPort
	goto_if_lt VAR_SSAQUA_STATE, 7, VermilionPortFrlg_EventScript_FirstTripFromOlivine
	@ Phase 4: M.S. Aqua, every day (see docs/origin_jade/DECISIONS.md, D-029)
	goto VermilionPortFrlg_EventScript_Sailor_AfterKanto
	end

VermilionPortFrlg_EventScript_SSAnnePresent::
	msgbox VermilionPortFrlg_Text_AskBoardSSAnne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionPortFrlg_EventScript_Sailor_Refused
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, TRUE, VermilionPortFrlg_EventScript_BoardSSAnne
	msgbox VermilionPortFrlg_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPortFrlg_EventScript_Sailor_AfterKanto::
	message VermilionPortFrlg_Text_WhereSail
	waitmessage
	multichoice 28, 2, MULTI_VERMILION_HARBOR, FALSE
	switch VAR_RESULT
	case SS_AQUA_SELECTION_OTHER_PORT, VermilionPortFrlg_EventScript_ChoseOlivine
	case SS_AQUA_SELECTION_BATTLE_FRONTIER, VermilionPortFrlg_EventScript_ChoseBattleFrontier
	case SS_AQUA_SELECTION_BIRTH_ISLAND, VermilionPortFrlg_EventScript_ChoseBirthIsland
	case SS_AQUA_SELECTION_HOENN, Common_EventScript_SailToHoenn
	goto VermilionPortFrlg_EventScript_Sailor_Refused

VermilionPortFrlg_EventScript_ChoseOlivine::
	closemessage
	delay 20
	checkitem ITEM_SS_TICKET
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPortFrlg_EventScript_Sailor_NoCredentials
	call VermilionPortFrlg_EventScript_EnterShip
	@ 8,15: Oak may still stand at 8,16 in front of the sailor.
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE_HNS, 8, 15
	waitstate
	release
	end

VermilionPortFrlg_EventScript_ChoseBirthIsland::
	closemessage
	delay 20
	checkitem ITEM_AURORA_TICKET
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPortFrlg_EventScript_Sailor_NoCredentials
	call VermilionPortFrlg_EventScript_EnterShip
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR_HNS, 13, 23
	waitstate
	release
	end

VermilionPortFrlg_EventScript_ChoseBattleFrontier::
	closemessage
	delay 20
	call VermilionPortFrlg_EventScript_EnterShip
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS, 20, 67
	waitstate
	release
	end

VermilionPortFrlg_EventScript_EnterShip::
	msgbox VermilionPortFrlg_Text_SailorGetOnBoard, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_VERMILIONMARINA_FRLG_SAILOR, VermilionPortFrlg_Movement_SailorEnterBoat
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, VermilionPortFrlg_Movement_PlayerEnterBoat
	waitmovement 0
	special SpawnCameraObject
	playse SE_EXIT
	removeobject OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement LOCALID_VERMILIONMARINA_FRLG_SAILOR, VermilionPortFrlg_Movement_BoatLeave
	applymovement LOCALID_VERMILIONMARINA_FRLG_BOAT, VermilionPortFrlg_Movement_BoatLeave
	waitmovement LOCALID_VERMILIONMARINA_FRLG_BOAT
	@ Keep the FRLG heal location, HEAL_LOCATION_VERMILION_CITY_HNS is on a disabled map.
	setrespawn HEAL_LOCATION_VERMILION_CITY
	return

VermilionPortFrlg_EventScript_Sailor_Refused::
	msgbox VermilionPortFrlg_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPortFrlg_EventScript_Sailor_NoCredentials::
	msgbox VermilionPortFrlg_Text_NoPass, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPortFrlg_Movement_SailorEnterBoat:
	walk_down
	walk_down
	step_end

VermilionPortFrlg_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	walk_in_place_down
	step_end

VermilionPortFrlg_Movement_BoatLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

VermilionPortFrlg_Text_NoPass:
#if GERMAN
	.string "{PLAYER} versucht, das {STR_VAR_1}\n"
	.string "zu zeigen…\p"
	.string "…Du hast kein {STR_VAR_1}!\p"
	.string "Tut mir leid! Du darfst nur mit\n"
	.string "{STR_VAR_1} an Bord.$"
#else
    .string "{PLAYER} tried to show the\n"
    .string "{STR_VAR_1}…\p"
    .string "…But no {STR_VAR_1}!\p"
    .string "Sorry!\n"
    .string "You may board only if you have an\l"
    .string "{STR_VAR_1}.$"
#endif

VermilionPortFrlg_Text_SailorGetOnBoard:
#if GERMAN
	.string "Wir legen bald ab! Geh an Bord.$"
#else
    .string "We're departing soon.\n"
    .string "Please get on board.$"
#endif

VermilionPortFrlg_Text_WhereSail:
#if GERMAN
	.string "Wohin möchtest du segeln?$"
#else
    .string "Where would you like to sail?$"
#endif

VermilionPortFrlg_Text_AskBoardSSAnne:
#if GERMAN
	.string "Die M.S. Anne liegt im Hafen.\p"
	.string "Möchtest du an Bord gehen?$"
#else
	.string "The S.S. ANNE is in port.\p"
	.string "Would you like to go aboard?$"
#endif

VermilionPortFrlg_Text_FirstTripFromOlivine:
#if GERMAN
	.string "Die M.S. Aqua startet ihre\n"
	.string "Jungfernfahrt in Oliviana City.\p"
	.string "Erst danach legt sie auch hier an.$"
#else
	.string "The S.S.AQUA starts her maiden\n"
	.string "voyage in OLIVINE CITY.\p"
	.string "She'll only call here after that.$"
#endif

VermilionPortFrlg_Text_ComeAgain:
#if GERMAN
	.string "Komm bald wieder!$"
#else
    .string "We hope to see you again!$"
#endif

VermilionPortFrlg_Text_FlashTicket:
#if GERMAN
	.string "{PLAYER} zeigt das Bootsticket.\p"
	.string "In Ordnung. Danke schön!$"
#else
    .string "{PLAYER} flashed the S.S.TICKET.\p"
    .string "That's it. Thank you!$"
#endif

VermilionPortFrlg_Text_NoTicket:
#if GERMAN
	.string "{PLAYER} sucht das Bootsticket…\p"
	.string "…Kein Ticket!\p"
	.string "Tut mir leid! Du darfst nur\n"
	.string "mit Ticket an Bord.$"
#else
    .string "{PLAYER} tried to show the\n"
    .string "S.S.TICKET…\p"
    .string "…But no TICKET!\p"
    .string "Sorry!\n"
    .string "You may board only\l"
    .string "if you have an S.S.TICKET.$"
#endif
