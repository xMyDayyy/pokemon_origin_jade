SSAqua_RoomSSE_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAqua_RoomSSE_OnFrame
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomSSE_OnTransition
	.byte 0

SSAqua_RoomSSE_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 5, SSAqua_RoomSSE_SetGirlPos
    end

SSAqua_RoomSSE_OnFrame::
	map_script_2 VAR_SSAQUA_STATE, 4, SSAqua_RoomSSE_EventScript_ReuinionScene
	.2byte 0

SSAqua_RoomSSE_SetGirlPos::
    setobjectxyperm LOCALID_SSAQUA_ROOM_SSE_GRANDDAUGTHER, 2, 4
    setobjectmovementtype LOCALID_SSAQUA_ROOM_SSE_GRANDDAUGTHER, MOVEMENT_TYPE_FACE_LEFT
    end

SSAqua_RoomSSE_EventScript_ReuinionScene::
	lock
    turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
    turnobject LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, DIR_SOUTH
    playse SE_PIN
    applymovement LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER
	applymovement LOCALID_SSAQUA_ROOM_SSE_GRANDDAUGTHER, SSAqua_RoomSSE_Movement_GirlEnter
    waitmovement 0
    turnobject LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, DIR_EAST
    msgbox SSAqua_RoomSSE_Text_GranddaughterWasPlaying, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, SSAqua_RoomSSE_Movement_PlayerEnter
    waitmovement 0
    turnobject LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, DIR_SOUTH
    msgbox SSAqua_RoomSSE_Text_EntertainedGranddaughter, MSGBOX_DEFAULT
    msgbox SSAqua_RoomSSE_Text_GrandpaHaveThis, MSGBOX_DEFAULT
    giveitem ITEM_METAL_COAT
	@ Bag full: the voyage goes on, the grandpa hands it over when talked to.
	call_if_eq VAR_RESULT, FALSE, SSAqua_RoomSSE_EventScript_MetalCoatPending
    closemessage
	setvar VAR_SSAQUA_STATE, 5
	release
	end

SSAqua_RoomSSE_EventScript_MetalCoatPending::
	call Common_EventScript_BagIsFull
	setflag FLAG_SSAQUA_METAL_COAT_PENDING
	return

SSAqua_RoomSSE_EventScript_Grandpa::
	lock
	faceplayer
	goto_if_ge VAR_SSAQUA_STATE, 4, SSAqua_RoomSSE_EventScript_GrandpaAfter
	msgbox SSAqua_RoomSSE_Text_CantFindGranddaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_RoomSSE_EventScript_GrandpaAfter::
	goto_if_set FLAG_SSAQUA_METAL_COAT_PENDING, SSAqua_RoomSSE_EventScript_GiveMetalCoat
	msgbox SSAqua_RoomSSE_Text_GrandpaTravelling, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_RoomSSE_EventScript_GiveMetalCoat::
	msgbox SSAqua_RoomSSE_Text_GrandpaHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_METAL_COAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	clearflag FLAG_SSAQUA_METAL_COAT_PENDING
	closemessage
	release
	end

SSAqua_RoomSSE_EventScript_GrandDaughter::
	msgbox SSAqua_RoomSSE_Text_GranddaughterHadFun, MSGBOX_NPC
	end

SSAqua_RoomSSE_Movement_GirlEnter:
    walk_up
    walk_up
    walk_left
    step_end

SSAqua_RoomSSE_Movement_PlayerEnter:
    walk_up
    walk_left
    walk_left
    walk_up
    step_end

SSAqua_RoomSSE_Text_CantFindGranddaughter:
#if GERMAN
	.string "Oh, hallo…\p"
	.string "Ich kann meine Enkelin nirgendwo\n"
	.string "finden.\p"
	.string "Wenn sie an Bord ist, ist alles in\n"
	.string "Ordnung.\p"
	.string "Sie ist ein Energiebündel und\p"
	.string "könnte jemanden nerven. Ich mache mir\n"
	.string "ernsthaft Sorgen…$"
#else
    .string "Oh, hello…\p"
    .string "I still can't find my\n"
    .string "granddaughter.\p"
    .string "If she's on the ship,\n"
    .string "that's OK.\p"
    .string "She's an energetic child,\n"
    .string "so she may be bugging someone\l"
    .string "I'm worried…$"
#endif

SSAqua_RoomSSE_Text_EntertainedGranddaughter:
#if GERMAN
	.string "Oh du bist es, ich hörte, du hast meine\n"
	.string "Enkelin bei Laune gehalten.\p"
	.string "Ich möchte dir dafür danken.$"
#else
    .string "{PLAYER}, was it?\n"
    .string "I heard you entertained my\l"
    .string "granddaughter.\p"
    .string "I want to thank you for that.$"
#endif

SSAqua_RoomSSE_Text_GrandpaHaveThis:
#if GERMAN
	.string "Ich möchte, dass du das nimmst!$"
#else
    .string "I know! I'd like you\n"
    .string "to have this!$"
#endif

SSAqua_RoomSSE_Text_GrandpaTravelling:
#if GERMAN
	.string "Wir machen eine Reise rund um die Welt!$"
#else
    .string "We're traveling around\n"
    .string "the world.$"
#endif

SSAqua_RoomSSE_Text_GranddaughterWasPlaying:
#if GERMAN
	.string "Hallo Opa, hier bin ich! Ich habe\p"
	.string "mit dem Kapitän und ihm hier gespielt!$"
#else
    .string "Grandpa, here I am!\n"
    .string "I was playing with\l"
    .string "the CAPTAIN and this person!$"
#endif

SSAqua_RoomSSE_Text_GranddaughterHadFun:
#if GERMAN
	.string "Das Spielen hat mir Spaß gemacht!$"
#else
    .string "I had lots of fun playing!$"
#endif
