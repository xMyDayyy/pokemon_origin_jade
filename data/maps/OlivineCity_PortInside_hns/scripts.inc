OlivineCity_PortInside_hns_MapScripts::
	.byte 0


OlivineCity_PortInside_EventScript_Oak::
	lock
	playbgm MUS_HG_OAK, FALSE
	playse SE_PIN
	applymovement2 LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_OLIVINEPORT_OAK
	turnobject LOCALID_OLIVINEPORT_OAK, DIR_NORTH
	@ Origin Jade: the Pokedex is national from the start, Oak only sees the champion off.
	msgbox OlivineCity_PortInside_Text_Nationaldex1, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_PIN
	applymovement2 LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_OLIVINEPORT_OAK
	msgbox OlivineCity_PortInside_Text_Nationaldex4, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OlivineCity_PortInside_Movement_PlayerMoveOver
	waitmovement 0
	applymovement LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakLeave
	waitmovement 0
	setflag FLAG_HIDE_OLIVINE_PORT_OAK
	playse SE_EXIT
	removeobject LOCALID_OLIVINEPORT_OAK
	fadedefaultbgm
	waitse
	release
	end

OlivineCity_PortInside_Movement_PlayerMoveOver:
	walk_up
	walk_left
	face_right
	step_end

OlivineCity_PortInside_Movement_OakLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_PortInside_Text_Nationaldex1:
#if GERMAN
	.string "Eich: Oh, {PLAYER}!\p"
	.string "Jetzt bist du Champion von Kanto\n"
	.string "und Johto!\p"
	.string "Ich bin wirklich stolz auf dich!$"
#else
	.string "PROF.OAK: Oh, {PLAYER}!\p"
	.string "Now you're the CHAMPION of both\n"
	.string "KANTO and JOHTO!\p"
	.string "I'm really proud of you!$"
#endif
OlivineCity_PortInside_Text_Nationaldex4:
#if GERMAN
	.string "Hoppla! Schon so spät!\p"
	.string "Im Radiosender von Dukatia City\n"
	.string "wird gleich meine Sendung\l"
	.string "aufgezeichnet!\p"
	.string "Mit der M.S. Aqua kannst du jetzt\n"
	.string "nach Orania City oder in die\l"
	.string "Kampfzone fahren.\p"
	.string "Mit dem richtigen Ticket sogar bis\n"
	.string "zur Entstehungsinsel!\p"
	.string "Und vielleicht eines Tages bis nach\n"
	.string "Hoenn… Gute Reise, {PLAYER}!$"
#else
	.string "Oops! Look at the time!\p"
	.string "I have to record my radio show in\n"
	.string "GOLDENROD CITY!\p"
	.string "The S.S.AQUA can take you to\n"
	.string "VERMILION CITY and the BATTLE\l"
	.string "FRONTIER now.\p"
	.string "With the right ticket, even to\n"
	.string "BIRTH ISLAND!\p"
	.string "And maybe to HOENN someday…\n"
	.string "Have a good trip, {PLAYER}!$"
#endif

OlivinePort_EventScript_CooltrainerF::
	msgbox OlivinePort_Text_CooltrainerF, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher1::
	msgbox OlivinePort_Text_FishingGuru1, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher2::
	msgbox OlivinePort_Text_FishingGuru2, MSGBOX_NPC
	end

OlivinePort_EventScript_Youngster::
	msgbox OlivinePort_Text_Youngster, MSGBOX_NPC
	end

@ Origin Jade: the M.S. Aqua sails every day from the first Johto title on; the first trip is the
@ maiden voyage to Vermilion. See docs/origin_jade/DECISIONS.md, D-029.
OlivinePort_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_IS_JOHTO_CHAMPION, OlivinePort_EventScript_SailorNotYet
	goto_if_ge VAR_SSAQUA_STATE, 7, OlivinePort_EventScript_Sailor_AfterKanto
	msgbox OlivinePort_Text_AskBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_Refused
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivinePort_EventScript_Sailor_MaidenVoyage
	msgbox OlivinePort_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_SailorNotYet::
	msgbox OlivinePort_Text_SailorNotYet, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_Sailor_AfterKanto::
	message OlivinePort_Text_WhereSail
	waitmessage
	multichoice 28, 2, MULTI_OLIVINE_HARBOR, FALSE
	switch VAR_RESULT
	case SS_AQUA_SELECTION_OTHER_PORT, OlivinePort_EventScript_ChoseVermilion
	case SS_AQUA_SELECTION_BATTLE_FRONTIER, OlivinePort_EventScript_ChoseBattleFrontier
	case SS_AQUA_SELECTION_BIRTH_ISLAND, OlivinePort_EventScript_ChoseBirthIsland
	case SS_AQUA_SELECTION_HOENN, Common_EventScript_SailToHoenn
	goto OlivinePort_EventScript_Sailor_Refused

OlivinePort_EventScript_ChoseVermilion::
	closemessage
	delay 20
	checkitem ITEM_SS_TICKET
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	@ Origin Jade: lands in Vermilion's port building, in front of the sailor.
	warpsilent MAP_VERMILION_CITY_PORT_INSIDE_FRLG, 8, 9
	waitstate
	release
	end

OlivinePort_EventScript_ChoseBirthIsland::
	closemessage
	delay 20
	checkitem ITEM_AURORA_TICKET
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR_HNS, 13, 23
	waitstate
	release
	end

OlivinePort_EventScript_ChoseBattleFrontier::
	closemessage
	delay 20
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS, 20, 67
	waitstate
	release
	end

OlivinePort_EventScript_Sailor_MaidenVoyage::
	msgbox OlivinePort_Text_FlashTicket, MSGBOX_DEFAULT
	call OlivinePort_EventScript_EnterShip
	setvar VAR_SSAQUA_STATE, 1
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER

	clearflag FLAG_HIDE_SSAQUA_SAILOR
	clearflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER

	warpsilent MAP_SSAQUA_1F_HNS, 29, 3
	waitstate
	release
	end

OlivinePort_EventScript_EnterShip::
	msgbox OlivinePort_Text_SailorGetOnBoard, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_SailorEnterBoat
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, OlivinePort_Movement_PlayerEnterBoat
	waitmovement 0
	special SpawnCameraObject
	playse SE_EXIT
	removeobject OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_BoatLeave
	applymovement LOCALID_OLIVINEPORT_BOAT, OlivinePort_Movement_BoatLeave
	waitmovement LOCALID_OLIVINEPORT_BOAT
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
	return

OlivinePort_EventScript_Sailor_Refused::
	msgbox OlivinePort_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_Sailor_NoCredentials::
	msgbox OlivinePort_Text_NoPass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_Movement_SailorEnterBoat:
	walk_down
	walk_down
	step_end

OlivinePort_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	walk_in_place_down
	step_end

OlivinePort_Movement_BoatLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OlivinePort_Text_NoPass:
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

OlivinePort_Text_SailorGetOnBoard:
#if GERMAN
	.string "Wir legen bald ab! Geh an Bord.$"
#else
    .string "We're departing soon.\n"
    .string "Please get on board.$"
#endif

OlivinePort_Text_CantBoard:
#if GERMAN
	.string "Du darfst jetzt nicht an Bord.$"
#else
    .string "Sorry. You can't board now.$"
#endif

OlivinePort_Text_WhereSail:
#if GERMAN
	.string "Wohin möchtest du segeln?$"
#else
    .string "Where would you like to sail?$"
#endif

OlivinePort_Text_AskBoard:
#if GERMAN
	.string "Willkommen auf dem Schnellboot M.S.\n"
	.string "Aqua.\p"
	.string "Trittst du heute deine Reise an?$"
#else
    .string "Welcome to FAST SHIP S.S.AQUA.\p"
    .string "Will you be boarding today?$"
#endif

OlivinePort_Text_SailorNotYet:
#if GERMAN
	.string "Die M.S. Aqua wird gerade für ihre\n"
	.string "Jungfernfahrt vorbereitet.\p"
	.string "Komm später wieder!$"
#else
	.string "The S.S.AQUA is being readied for\n"
	.string "her maiden voyage.\p"
	.string "Please come back later!$"
#endif

OlivinePort_Text_AskTicket:
#if GERMAN
	.string "Zeige mir bitte dein\p"
	.string "Bootsticket.$"
#else
    .string "May I see your S.S.TICKET?$"
#endif

OlivinePort_Text_ComeAgain:
#if GERMAN
	.string "Komm bald wieder!$"
#else
    .string "We hope to see you again!$"
#endif

OlivinePort_Text_FlashTicket:
#if GERMAN
	.string "{PLAYER} zeigt das Bootsticket.\p"
	.string "In Ordnung. Danke schön!$"
#else
    .string "{PLAYER} flashed the S.S.TICKET.\p"
    .string "That's it. Thank you!$"
#endif

OlivinePort_Text_NoTicket:
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

OlivinePort_Text_FishingGuru1:
#if GERMAN
	.string "Hier kannst du Muschas leicht\p"
	.string "fangen. An anderen Orten sind sie\n"
	.string "seltener.$"
#else
    .string "SHELLDER are easy to catch here.\p"
    .string "They're kind of rare elsewhere.$"
#endif

OlivinePort_Text_FishingGuru2:
#if GERMAN
	.string "Wie viele Angeln hast du?\p"
	.string "Mit verschiedenen Angeln, fängst du\n"
	.string "verschiedene Pokémon.$"
#else
    .string "How many RODS do you have?\p"
    .string "Different RODS catch different\n"
    .string "POKéMON.$"
#endif

OlivinePort_Text_Youngster:
#if GERMAN
	.string "M.S. Aqua benutzt Spezialdüsen,\n"
	.string "um über die Wellen zu gleiten!$"
#else
    .string "S.S.AQUA uses jets to skim\n"
    .string "over the waves!$"
#endif

OlivinePort_Text_CooltrainerF:
#if GERMAN
	.string "In Kanto gibt es viele Pokémon.\p"
	.string "Ich wünschte, ich könnte dorthin…$"
#else
    .string "There are lots of POKéMON in KANTO.\p"
    .string "I wish I could go…$"
#endif

OlivinePort_Text_SailorBeforeHOF:
#if GERMAN
	.string "Wir wollen nicht, dass du ins Wasser\n"
	.string "fällst. Darum lasen wir dich nicht\l"
	.string "herein.$"
#else
    .string "We don't want you to fall into the\n"
    .string "sea, so you're not allowed in.$"
#endif
