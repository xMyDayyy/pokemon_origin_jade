VermilionCity_PortInside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionPort_OnFrame
	.byte 0

VermilionPort_OnFrame::
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 1, VermilionPort_EventScript_SSAnneDeparts
	.2byte 0

@ Phase 2: Der Spieler verlaesst die S.S. Anne mit der VM01. Das Schiff laeuft
@ aus, der Hafen bleibt vorerst leer. Die frueher hier zustaendige Szene auf
@ SSAnne_Exterior entfaellt, das FRLG-Aussendeck wird nicht mehr betreten.
VermilionPort_EventScript_SSAnneDeparts::
	lockall
	delay 30
	playse SE_SHIP
	removeobject LOCALID_VERMILION_PORT_SS_ANNE
	setflag FLAG_HIDE_SS_ANNE
	delay 60
	msgbox VermilionPort_Text_SSAnneDeparted, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
	releaseall
	end

@ Phase 1: Solange die S.S. Anne im Hafen liegt, fuehrt der Matrose an Bord.
VermilionPort_EventScript_BoardSSAnne::
	msgbox VermilionPort_Text_AllAboardSSAnne, MSGBOX_DEFAULT
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_SSANNE_1F_CORRIDOR, 19, 2
	waitstate
	release
	end

@ Phase 3: Anne ausgelaufen, Aqua noch nicht da.
VermilionPort_EventScript_NoShipInPort::
	msgbox VermilionPort_Text_NoShipInPort, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_Text_SSAnneDeparted:
#if GERMAN
	.string "Die S.S. Anne hat abgelegt.\p"
	.string "Sie kehrt so bald nicht zurück.$"
#else
	.string "The S.S. ANNE has set sail.\p"
	.string "She won't return for a long time.$"
#endif

VermilionPort_Text_AllAboardSSAnne:
#if GERMAN
	.string "Willkommen an Bord der S.S. Anne!\n"
	.string "Hier entlang, bitte.$"
#else
	.string "Welcome aboard the S.S. ANNE!\n"
	.string "Right this way, please.$"
#endif

VermilionPort_Text_NoShipInPort:
#if GERMAN
	.string "Zurzeit liegt kein Schiff im Hafen.\p"
	.string "Schau doch später noch einmal\n"
	.string "vorbei.$"
#else
	.string "There's no ship in port right now.\p"
	.string "Come back another time.$"
#endif

VermilionPortIndoor_EventScript_Teacher::
	msgbox VermilionPortPassage_Text_Teacher, MSGBOX_NPC
	end
VermilionPortIndoor_EventScript_Nerd::
	msgbox VermilionPort_Text_SuperNerd, MSGBOX_NPC
	end

VermilionPortPassage_Text_Teacher:
#if GERMAN
	.string "Das Schnellboot fährt immer mittwochs\n"
	.string "und sonntags.$"
#else
	.string "The FAST SHIP sails every day!$"
#endif

VermilionPort_Text_SuperNerd:
#if GERMAN
	.string "Du kommst aus Johto?\p"
	.string "Oh, toll!\n"
	.string "Dort sollen viele seltene Pokémon\l"
	.string "leben!$"
#else
	.string "You came from JOHTO?\p"
	.string "I hear many rare POKéMON live\n"
	.string "over there.$"
#endif

VermilionPort_EventScript_Sailor::
	lock
	faceplayer
	@ Phase 1: S.S. Anne liegt im Hafen, Fahrschein noetig.
	goto_if_unset FLAG_HIDE_SS_ANNE, VermilionPort_EventScript_SSAnnePresent
	@ Phase 3: Anne ausgelaufen, Aqua noch nicht eingelaufen.
	goto_if_set FLAG_HIDE_VERMILION_SS_AQUA, VermilionPort_EventScript_NoShipInPort
	@ Phase 4: ab hier die bestehende S.S.-Aqua-Logik.
	goto_if_unset FLAG_RETURNED_MACHINE_PART, VermilionPort_EventScript_SailorCantSail
	goto_if_ge VAR_SSAQUA_STATE, 7, VermilionPort_EventScript_Sailor_AfterKanto
	msgbox VermilionPort_Text_AskBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_Refused
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, TRUE, VermilionPort_EventScript_Sailor_MaidenVoyage
	msgbox VermilionPort_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_EventScript_SSAnnePresent::
	msgbox VermilionPort_Text_AskBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_Refused
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, TRUE, VermilionPort_EventScript_BoardSSAnne
	msgbox VermilionPort_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_EventScript_SailorCantSail::
	msgbox VermilionPort_Text_SailorCantSail, MSGBOX_NPC
	closemessage
	release
	end

VermilionPort_EventScript_Sailor_AfterKanto::
	message VermilionPort_Text_WhereSail
	multichoicegrid 1, 0, MULTI_VERMILION_HARBOR, 2, FALSE
	switch VAR_RESULT
	case 0, VermilionPort_EventScript_ChoseOlivine
	case 1, VermilionPort_EventScript_ChoseSouthernIsland
	case 2, VermilionPort_EventScript_ChoseBirthIsland
	case 3, VermilionPort_EventScript_ChoseFarawayIsland
	case 4, VermilionPort_EventScript_ChoseBattleFrontier
	case 5, Common_EventScript_SailToHoenn
	case 6, VermilionPort_EventScript_Sailor_Refused
	case MULTI_B_PRESSED, VermilionPort_EventScript_Sailor_Refused
	release
	end

VermilionPort_EventScript_ChoseOlivine::
	closemessage
	delay 20
	checkitem ITEM_SS_TICKET
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE_HNS, 8, 16
	waitstate
	release
	end

VermilionPort_EventScript_ChoseSouthernIsland::
	closemessage
	delay 20
	checkitem ITEM_EON_TICKET
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_SOUTHERN_ISLAND_EXTERIOR_HNS, 13, 22
	waitstate
	release
	end

VermilionPort_EventScript_ChoseBirthIsland::
	closemessage
	delay 20
	checkitem ITEM_AURORA_TICKET
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR_HNS, 13, 23
	waitstate
	release
	end

VermilionPort_EventScript_ChoseFarawayIsland::
	closemessage
	delay 20
	checkitem ITEM_OLD_SEA_MAP
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, VermilionPort_EventScript_Sailor_NoCredentials
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_FARAWAY_ISLAND_ENTRANCE_HNS, 13, 38
	waitstate
	release
	end

VermilionPort_EventScript_ChoseBattleFrontier::
	closemessage
	delay 20
	call VermilionPort_EventScript_EnterShip
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS, 20, 67
	waitstate
	release
	end

VermilionPort_EventScript_Sailor_MaidenVoyage::
	msgbox VermilionPort_Text_FlashTicket, MSGBOX_DEFAULT
	call VermilionPort_EventScript_EnterShip
	setvar VAR_SSAQUA_STATE, 1
	warpsilent MAP_SSAQUA_1F_HNS, 29, 3
	waitstate
	release
	end

VermilionPort_EventScript_EnterShip::
	msgbox VermilionPort_Text_SailorGetOnBoard, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_VERMILIONMARINA_SAILOR, VermilionPort_Movement_SailorEnterBoat
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, VermilionPort_Movement_PlayerEnterBoat
	waitmovement 0
	special SpawnCameraObject
	playse SE_EXIT
	removeobject OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement LOCALID_VERMILIONMARINA_SAILOR, VermilionPort_Movement_BoatLeave
	applymovement LOCALID_VERMILIONMARINA_BOAT, VermilionPort_Movement_BoatLeave
	waitmovement LOCALID_VERMILIONMARINA_BOAT
	setrespawn HEAL_LOCATION_VERMILION_CITY_HNS
	return

VermilionPort_EventScript_Sailor_Refused::
	msgbox VermilionPort_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_EventScript_Sailor_NoCredentials::
	msgbox VermilionPort_Text_NoPass, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionPort_Movement_SailorEnterBoat:
	walk_down
	walk_down
	step_end

VermilionPort_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	walk_in_place_down
	step_end

VermilionPort_Movement_BoatLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

VermilionPort_Text_SailorCantSail:
#if GERMAN
	.string "Im Kraftwerk gab es einen Einbruch,\n"
	.string "deshalb können wir nicht auslaufen, bis\l"
	.string "der Dieb gefunden ist.$"
#else
	.string "There's been a break-in at the\n"
	.string "POWER PLANT, so we cannot set sail\l"
	.string "until the THIEF is found.$"
#endif

VermilionPort_Text_NoPass:
#if GERMAN
	.string "{PLAYER} wollte {STR_VAR_1} zeigen…\p"
	.string "…Aber kein {STR_VAR_1}!\p"
	.string "Entschuldigung!\n"
	.string "Du darfst nur an Bord, wenn du ein\l"
	.string "{STR_VAR_1} hast.$"
#else
    .string "{PLAYER} tried to show the\n"
    .string "{STR_VAR_1}…\p"
    .string "…But no {STR_VAR_1}!\p"
    .string "Sorry!\n"
    .string "You may board only if you have an\l"
    .string "{STR_VAR_1}.$"
#endif

VermilionPort_Text_SailorGetOnBoard:
#if GERMAN
	.string "Wir legen bald ab! Geh an Bord.$"
#else
    .string "We're departing soon.\n"
    .string "Please get on board.$"
#endif

VermilionPort_Text_CantBoard:
#if GERMAN
	.string "Du darfst jetzt nicht an Bord.$"
#else
    .string "Sorry. You can't board now.$"
#endif

VermilionPort_Text_WhereSail:
#if GERMAN
	.string "Wohin möchtest du Segeln?$"
#else
    .string "Where would you like to sail?$"
#endif

VermilionPort_Text_AskBoard:
#if GERMAN
	.string "Willkommen auf dem Schnellboot M.S.\n"
	.string "Aqua.\p"
	.string "Trittst du heute deine Reise an?$"
#else
    .string "Welcome to FAST SHIP S.S.AQUA.\p"
    .string "Will you be boarding today?$"
#endif

VermilionPort_Text_AskTicket:
#if GERMAN
	.string "Zeige mir bitte dein Bootsticket!$"
#else
    .string "May I see your S.S.TICKET?$"
#endif

VermilionPort_Text_ComeAgain:
#if GERMAN
	.string "Komm bald wieder!$"
#else
    .string "We hope to see you again!$"
#endif

VermilionPort_Text_FlashTicket:
#if GERMAN
	.string "Zeige mir bitte dein Bootsticket!$"
#else
    .string "{PLAYER} flashed the S.S.TICKET.\p"
    .string "That's it. Thank you!$"
#endif

VermilionPort_Text_NoTicket:
#if GERMAN
	.string "{PLAYER} sucht das Bootsticket…\p"
	.string "…Kein Ticket!\p"
	.string "Tut mir Leid! Du darfst nur\p"
	.string "mit Ticket an Bord.$"
#else
    .string "{PLAYER} tried to show the\n"
    .string "S.S.TICKET…\p"
    .string "…But no TICKET!\p"
    .string "Sorry!\n"
    .string "You may board only\l"
    .string "if you have an S.S.TICKET.$"
#endif
