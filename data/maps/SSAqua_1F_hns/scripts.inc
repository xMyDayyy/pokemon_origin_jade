SSAqua_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAqua_1F_OnFrame
	.byte 0

SSAqua_1F_OnFrame::
	map_script_2 VAR_SSAQUA_STATE, 5, SSAqua_1F_EventScript_Arrived
	.2byte 0

SSAqua_1F_EventScript_Arrived::
	lock
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 10  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_DING_DONG
	msgbox SSAqua_1F_Text_Sailor1_InVermilion, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SSAQUA_STATE, 6
	release
	end

SSAqua_1F_EventScript_DoorSailor::
	lock
	faceplayer
	goto_if_ge VAR_SSAQUA_STATE, 5, SSAqua_1F_EventScript_DoorSailorArrived
	msgbox SSAqua_1F_Text_Sailor1_ToVermilion, MSGBOX_NPC
	end

SSAqua_1F_EventScript_DoorSailorArrived::
	msgbox SSAqua_1F_Text_SailorDoorArrived, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SSAqua_1F_EventScript_LeaveBoat
	closemessage
	release
	end

SSAqua_1F_EventScript_LeaveBoat::
	fadescreenswapbuffers FADE_TO_BLACK
	@ Origin Jade: without HnS's Kanto reset (flag heap); Kanto is played first.
	setvar VAR_SSAQUA_STATE, 7
	@ Origin Jade: lands in Vermilion's port building, in front of the sailor.
	warp MAP_VERMILION_CITY_PORT_INSIDE_FRLG, 8, 9
	waitstate
	release
	end

SSAqua_1F_EventScript_RoomSailor::
	msgbox SSAqua_1F_Text_Sailor2_FirstTime, MSGBOX_NPC
	end

SSAqua_1F_EventScript_Sailor3::
	msgbox SSAqua_1F_Text_Sailor3, MSGBOX_NPC
	end

SSAqua_1F_Trigger_Grandpa::
	lock
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 28, SSAqua_1F_EventScript_GrandpaEnterLeft
	call_if_eq VAR_TEMP_0, 29, SSAqua_1F_EventScript_GrandpaEnterRight
	applymovement OBJ_EVENT_ID_PLAYER, SSAqua_1F_Movement_PlayerSlideRight
	waitmovement 0
	applymovement LOCALID_SSAQUA_1F_GRANDPA, Common_Movement_WalkRight1
	waitmovement 0
	msgbox SSAqua_1F_Text_Grandpa, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SSAQUA_1F_GRANDPA, SSAqua_1F_Movement_GrandpaLeave
	waitmovement 0
	playse SE_DOOR
	removeobject LOCALID_SSAQUA_1F_GRANDPA

	setflag FLAG_HIDE_SSAQUA_1F_GRANDPA		@flagheap
	setflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER

	clearflag FLAG_HIDE_SSAQUA_SAILOR
	clearflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER

	setvar VAR_SSAQUA_STATE, 2
	release
	end

SSAqua_1F_EventScript_GrandpaEnterLeft::
	applymovement LOCALID_SSAQUA_1F_GRANDPA, SSAqua_1F_Movement_GrandpaEnterLeft
	waitmovement 0
	return

SSAqua_1F_EventScript_GrandpaEnterRight::
	applymovement LOCALID_SSAQUA_1F_GRANDPA, SSAqua_1F_Movement_GrandpaEnterRight
	waitmovement 0
	return

SSAqua_1F_Movement_GrandpaEnterLeft:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_1F_Movement_GrandpaEnterRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_1F_Movement_PlayerSlideRight:
	face_left
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

SSAqua_1F_Movement_GrandpaLeave:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SSAqua_1F_Text_Sailor1_ToVermilion:
#if GERMAN
	.string "Die M.S. Aqua ist auf dem Weg nach\n"
	.string "Orania City.\p"
	.string "Wenn wir dort in den Hafen einlaufen,\n"
	.string "machen wir eine Durchsage.$"
#else
    .string "FAST SHIP S.S.AQUA is en route to\n"
    .string "VERMILION CITY.\p"
    .string "We will make an announcement when\n"
    .string "we arrive.$"
#endif

SSAqua_1F_Text_Sailor1_ToOlivine:
#if GERMAN
	.string "Die M.S. Aqua ist auf dem Weg nach\n"
	.string "Oliviana City.\p"
	.string "Wenn wir dort in den Hafen einlaufen,\n"
	.string "machen wir eine Durchsage.$"
#else
    .string "FAST SHIP S.S.AQUA is en route to\n"
    .string "OLIVINE CITY.\p"
    .string "We will make an announcement when\n"
    .string "we arrive.$"
#endif

SSAqua_1F_Text_Sailor2_FirstTime:
#if GERMAN
	.string "Das ist deine Kabine.\p"
	.string "Wenn dein Pokémon-Team verletzt ist,\n"
	.string "dann mache hier ein Nickerchen. Dadurch\l"
	.string "wird es geheilt.$"
#else
    .string "Here's your cabin.\p"
    .string "If your POKéMON are hurt, take a\n"
    .string "nap in the bed.\p"
    .string "That will heal them.$"
#endif

SSAqua_1F_Text_Sailor3:
#if GERMAN
	.string "Alle Passagiere sind Trainer.\p"
	.string "Sie brennen darauf, in ihren Kabinen zu\n"
	.string "kämpfen.$"
#else
    .string "The passengers are all trainers.\p"
    .string "They're all itching to battle in\n"
    .string "their cabins.$"
#endif

SSAqua_1F_Text_Grandpa:
#if GERMAN
	.string "Entschuldigung, ich bin in Eile!\p"
	.string "Ich bin auf der Suche nach meiner\n"
	.string "Enkelin! Sie ist verschwunden! Wenn du\l"
	.string "ein kleines Mädchen siehst, dann sag\l"
	.string "bitte Bescheid!$"
#else
    .string "Whoa! Excuse me. I was in a hurry!\p"
    .string "My granddaughter is missing!\p"
    .string "She's just a wee girl. If you see\n"
    .string "her, please let me know!$"
#endif

SSAqua_1F_Text_Sailor1_InOlivine:
#if GERMAN
	.string "Die M.S. Aqua hat nun in Oliviana City\n"
	.string "angelegt!$"
#else
    .string "FAST SHIP S.S.AQUA has arrived in\n"
    .string "OLIVINE CITY.$"
#endif

SSAqua_1F_Text_Sailor1_InVermilion:
#if GERMAN
	.string "Die M.S. Aqua hat nun in Orania City\n"
	.string "angelegt!$"
#else
    .string "FAST SHIP S.S.AQUA has arrived in\n"
    .string "VERMILION CITY.$"
#endif


SSAqua_1F_Text_SailorDoorArrived:
#if GERMAN
	.string "Wir sind in Orania City angekommen.\n"
	.string "Gehst du von Bord?$"
#else
    .string "We have arrived in VERMILION CITY.\n"
    .string "Would you like to disembark?$"
#endif

@ M.S. Aqua return trips from the Kampfzone and Birth Island, see docs/origin_jade/DECISIONS.md, D-029.
@ Jump here after lock/faceplayer and the sailor's question; VAR_0x8004 holds the local id of the ship.
@ Hoenn is offered when the port menus offer it (Johto title, maiden voyage done) and uses their script.
SSAqua_EventScript_ChooseReturnPort::
	goto_if_unset FLAG_IS_JOHTO_CHAMPION, SSAqua_EventScript_ChooseReturnPortNoHoenn
	goto_if_lt VAR_SSAQUA_STATE, 7, SSAqua_EventScript_ChooseReturnPortNoHoenn
	multichoice 28, 4, MULTI_SSAQUA_RETURN, FALSE
	switch VAR_RESULT
	case SS_AQUA_RETURN_OLIVINE, SSAqua_EventScript_ReturnToOlivine
	case SS_AQUA_RETURN_VERMILION, SSAqua_EventScript_ReturnToVermilion
	case SS_AQUA_RETURN_HOENN, Common_EventScript_SailToHoenn
	goto SSAqua_EventScript_ReturnRefused

SSAqua_EventScript_ChooseReturnPortNoHoenn::
	multichoice 28, 6, MULTI_SSAQUA_RETURN_PORTS, FALSE
	switch VAR_RESULT
	case SS_AQUA_RETURN_OLIVINE, SSAqua_EventScript_ReturnToOlivine
	case SS_AQUA_RETURN_VERMILION, SSAqua_EventScript_ReturnToVermilion
	goto SSAqua_EventScript_ReturnRefused

SSAqua_EventScript_ReturnRefused::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

SSAqua_EventScript_ReturnToOlivine::
	call SSAqua_EventScript_ReturnDepart
	@ 8,15: Oak may still stand at 8,16 in front of the sailor.
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE_HNS, 8, 15
	waitstate
	release
	end

SSAqua_EventScript_ReturnToVermilion::
	call SSAqua_EventScript_ReturnDepart
	warpsilent MAP_VERMILION_CITY_PORT_INSIDE_FRLG, 8, 9
	waitstate
	release
	end

SSAqua_EventScript_ReturnDepart::
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	removeobject VAR_LAST_TALKED
	call Common_EventScript_FerryDepartIsland
	return
