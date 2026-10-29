WhirlIslands_LugiaChamber_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WhirlIslands_LugiaChamber_OnTransition
	.byte 0

@ Lugia: story battle at VAR_COMPLETED_LUGIA 2; afterwards the legendary rules decide
@ (see docs/origin_jade/DECISIONS.md, D-026). The Lugia not chosen on Route 39 waits
@ after the first Johto title once Ho-Oh is caught.
WhirlIslands_LugiaChamber_OnTransition:
	goto_if_eq VAR_COMPLETED_LUGIA, 2, WhirlIslands_LugiaChamber_MapScript_LugiaStory
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_LUGIA
	setobjectxyperm LOCALID_LUGIA, 29, 12
	goto_if_lt VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_MapScript_End
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, WhirlIslands_LugiaChamber_MapScript_CheckLugia
	goto_if_unset FLAG_IS_JOHTO_CHAMPION, WhirlIslands_LugiaChamber_MapScript_End
	goto_if_unset FLAG_CAUGHT_HO_OH, WhirlIslands_LugiaChamber_MapScript_End
WhirlIslands_LugiaChamber_MapScript_CheckLugia:
	setvar VAR_0x8004, LEGENDARY_LUGIA
	specialvar VAR_RESULT, IsLegendaryAvailable
	goto_if_ne VAR_RESULT, TRUE, WhirlIslands_LugiaChamber_MapScript_End
	clearflag FLAG_HIDE_LUGIA
WhirlIslands_LugiaChamber_MapScript_End:
	end

WhirlIslands_LugiaChamber_MapScript_LugiaStory::
	clearflag FLAG_HIDE_LUGIA
	end

WhirlIslands_LugiaChamber_EventScript_TalkToKimono::
	lockall
	playbgm MUS_HG_KIMONO_GIRL_DANCE, FALSE
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_Opening, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Step_Aside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, WhirlIslands_LugiaChamber_Walk_To_Center
	waitmovement 0
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Step_In
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Step_Start_Left
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Step_Start_Right
	waitmovement 5
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	@ 1
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Down
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Left
	waitmovement LOCALID_KIMONO_4
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 2
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Down
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Right
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Left
	waitmovement LOCALID_KIMONO_4
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 3
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Left
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Down
	waitmovement LOCALID_KIMONO_3
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 4
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Right
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Left
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Down
	waitmovement LOCALID_KIMONO_3
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 5
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Left_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right_Up
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Step_Up
	waitmovement LOCALID_KIMONO_1
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	waitse
	setobjectxyperm LOCALID_KIMONO_1, 27, 18
	setobjectxyperm LOCALID_KIMONO_2, 28, 19
	setobjectxyperm LOCALID_KIMONO_MID, 29, 20
	setobjectxyperm LOCALID_KIMONO_4, 30, 19
	setobjectxyperm LOCALID_KIMONO_3, 31, 18
	setobjectmovementtype LOCALID_KIMONO_1, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_KIMONO_2, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_KIMONO_3, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_KIMONO_4, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_KIMONO_MID, MOVEMENT_TYPE_FACE_UP
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_LUGIA, WhirlIslands_LugiaChamber_Movement_LugiaAppear
	applymovement OBJ_EVENT_ID_CAMERA, WhirlIslands_LugiaChamber_Movement_CameraPanUp
	waitmovement 0
	delay 50
	@ setweather WEATHER_NONE
	@ doweather
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_LUGIA, WhirlIslands_LugiaChamber_Movement_LugiaApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WhirlIslands_LugiaChamber_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_1, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_2, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_3, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up
	waitmovement 0
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_Closing1, MSGBOX_DEFAULT
	waitmessage
	setobjectxyperm LOCALID_LUGIA, 29, 12


	closemessage
	releaseall
	end

@ The story battle moves the story on whatever the outcome.
WhirlIslands_LugiaChamber_EventScript_Lugia::
	lockall
	goto_if_ne VAR_COMPLETED_LUGIA, 2, WhirlIslands_LugiaChamber_EventScript_LugiaPostgame
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	playbgm MUS_HG_VS_LUGIA, 0
	seteventmon SPECIES_LUGIA, 78
	call WhirlIslands_LugiaChamber_EventScript_LugiaBattle
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	applymovement LOCALID_KIMONO_MID, WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right2
	waitmovement 0
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	setvar VAR_ECRUTEAK_CITY_THEATER, 8
	setvar VAR_COMPLETED_LUGIA, 3
	releaseall
	end

@ After the story: the chosen Lugia at Lv 78, the Lugia not chosen at Lv 80.
WhirlIslands_LugiaChamber_EventScript_LugiaPostgame::
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	playbgm MUS_HG_VS_LUGIA, 0
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, WhirlIslands_LugiaChamber_EventScript_LugiaPostgameChosen
	seteventmon SPECIES_LUGIA, 80
	goto WhirlIslands_LugiaChamber_EventScript_LugiaPostgameBattle

WhirlIslands_LugiaChamber_EventScript_LugiaPostgameChosen:
	seteventmon SPECIES_LUGIA, 78
WhirlIslands_LugiaChamber_EventScript_LugiaPostgameBattle:
	call WhirlIslands_LugiaChamber_EventScript_LugiaBattle
	releaseall
	end

@ Battle, record the outcome, Lugia leaves the chamber.
WhirlIslands_LugiaChamber_EventScript_LugiaBattle::
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_0x8004, LEGENDARY_LUGIA
	special RecordLegendaryBattleOutcome
	setvar VAR_LAST_TALKED, LOCALID_LUGIA
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, WhirlIslands_LugiaChamber_EventScript_CaughtLugia
	goto WhirlIslands_LugiaChamber_EventScript_LugiaFlewAway

WhirlIslands_LugiaChamber_EventScript_LugiaFlewAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_LUGIA
	setweather WEATHER_NONE
	doweather
	setflag FLAG_HIDE_LUGIA
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	return

WhirlIslands_LugiaChamber_EventScript_CaughtLugia::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_LUGIA
	setweather WEATHER_NONE
	doweather
	setflag FLAG_HIDE_LUGIA
	fadescreenswapbuffers FADE_FROM_BLACK
	return

WhirlIslands_LugiaChamber_EventScript_Zuki::
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_EventScript_ZukiAfter
	msgbox WhirlIslands_LugiaChamber_Text_Zuki_Before, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_ZukiAfter::
	goto_if_unset FLAG_CAUGHT_LUGIA, WhirlIslands_LugiaChamber_EventScript_ZukiAfterNotCaught
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_AfterCaught, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_ZukiAfterNotCaught::
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_AfterNotCaught, MSGBOX_NPC
	end

WhirlIslands_LugiaChamber_EventScript_Naoko::
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_EventScript_NaokoAfter
	msgbox WhirlIslands_LugiaChamber_Text_Naoko_Before, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_NaokoAfter::
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_After, MSGBOX_NPC
	end

WhirlIslands_LugiaChamber_EventScript_Miki::
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_EventScript_MikiAfter
	msgbox WhirlIslands_LugiaChamber_Text_Miki_Before, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_MikiAfter::
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_After, MSGBOX_NPC
	end

WhirlIslands_LugiaChamber_EventScript_Sayo::
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_EventScript_SayoAfter
	msgbox WhirlIslands_LugiaChamber_Text_Sayo_Before, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_SayoAfter::
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_After, MSGBOX_NPC
	end

WhirlIslands_LugiaChamber_EventScript_Kuni::
	goto_if_eq VAR_COMPLETED_LUGIA, 3, WhirlIslands_LugiaChamber_EventScript_KuniAfter
	msgbox WhirlIslands_LugiaChamber_Text_Kuni_Before, MSGBOX_NPC
	end
WhirlIslands_LugiaChamber_EventScript_KuniAfter::
	msgbox WhirlIslands_LugiaChamber_Text_Kimono_After, MSGBOX_NPC
	end

WhirlIslands_LugiaChamber_Text_Kimono_AfterNotCaught:
#if GERMAN
	.string "Ihr habt Lugia nicht nur hierher\n"
	.string "gerufen, sondern Ihr konntet es auch,\l"
	.string "wie durch ein Wunder, einfangen…\p"
	.string "Das war wahrlich eine große Heldentat.\n"
	.string "Es gibt nun nichts mehr, was wir Euch\l"
	.string "noch erzählen könnten.\p"
	.string "Wir wünschen Euch auch für den Rest\n"
	.string "Eurer Reise alles Gute…$"
#else
	.string "You have not only made LUGIA\n"
	.string "appear, but you have also defeated\l"
	.string "it...\p"
	.string "There is nothing more for us to\n"
	.string "say. Take care of yourself in your\l"
#endif

WhirlIslands_LugiaChamber_Text_Kimono_AfterCaught:
#if GERMAN
	.string "Ihr habt Lugia nicht nur hierher\n"
	.string "gerufen, sondern Ihr konntet es auch,\l"
	.string "wie durch ein Wunder, einfangen…\p"
	.string "Das war wahrlich eine große Heldentat.\n"
	.string "Es gibt nun nichts mehr, was wir Euch\l"
	.string "noch erzählen könnten.\p"
	.string "Wir wünschen Euch auch für den Rest\n"
	.string "Eurer Reise alles Gute…$"
#else
	.string "You have not only made LUGIA\n"
	.string "appear, but you have also caught\l"
	.string "it...\p"
	.string "There is nothing more for us to\n"
	.string "say. Take care of yourself in your\l"
	.string "journey...$"
#endif

WhirlIslands_LugiaChamber_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WhirlIslands_LugiaChamber_Movement_CameraPanDown:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WhirlIslands_LugiaChamber_Movement_LugiaApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_LugiaAppear:
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end


WhirlIslands_LugiaChamber_Movement_Kimono_Step_Aside:
	face_right
	delay_16
	walk_right
	delay_16
	face_left
	step_end

WhirlIslands_LugiaChamber_Walk_To_Center:
	walk_up
	walk_up
	walk_up
	delay_16
	face_down
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Step_In:
	walk_left
	delay_16
	face_down
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Step_Start_Left:
	face_right
	delay_16
	face_up
	delay_16
	walk_up
	walk_up
	delay_16
	face_left
	delay_16
	walk_left
	delay_16
	face_down
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Step_Start_Right:
	face_right
	delay_16
	face_up
	delay_16
	walk_up
	walk_up
	delay_16
	face_right
	delay_16
	walk_right
	delay_16
	face_down
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Mid:
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	delay_8
	delay_8
	delay_8
	delay_8
	delay_16
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Down:
	face_down
	delay_8
	walk_down
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right:
	face_right
	delay_8
	walk_right
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Up:
	face_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Left:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	walk_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Right:
	face_right
	delay_8
	walk_right
	walk_right
	walk_right
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Far_Left:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	walk_left
	walk_left
	walk_left
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Left_Up:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	walk_left
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right_Up:
	face_right
	delay_8
	walk_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_right
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Look_Up:
	face_right
	delay_8
	face_up
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Step_Up:
	face_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands_LugiaChamber_Movement_Kimono_Dance_Shift_Right2:
	face_right
	delay_8
	walk_right
	delay_8
	face_down
	delay_16
	face_left
	step_end

WhirlIslands_LugiaChamber_Text_Zuki_Before::
#if GERMAN
	.string "Tamao: Geh nun zu Lugia.$"
#else
	.string "ZUKI: Go, face LUGIA. $"
#endif
WhirlIslands_LugiaChamber_Text_Naoko_Before::
	.string "Umeko: Geh nun zu Lugia.$"
WhirlIslands_LugiaChamber_Text_Miki_Before::
#if GERMAN
	.string "Satsuki: Geh nun zu Lugia.$"
#else
	.string "MIKI: Go, face LUGIA. $"
#endif
WhirlIslands_LugiaChamber_Text_Sayo_Before::
	.string "Sakura: Geh nun zu Lugia.$"
WhirlIslands_LugiaChamber_Text_Kuni_Before::
#if GERMAN
	.string "Komono: Geh nun zu Lugia.$"
#else
	.string "KUNI: Go, face LUGIA. $"
#endif

WhirlIslands_LugiaChamber_Text_Kimono_Opening::
#if GERMAN
	.string "Tamao: Dies ist der Ort, an dem wir\n"
	.string "mit Lugia in Kontakt treten werden.\p"
	.string "Wenn sich hier der Klang des Tanzes, den\n"
	.string "wir täglich proben, mit dem Eurer\l"
	.string "Gischtglocke überlagert, wird Lugia aus\l"
	.string "seinem Schlaf tief am Grund\p"
	.string "des Wasserfalls erwachen und sich\n"
	.string "von uns erblicken lassen!$"
#else
	.string "KIMONO GIRL: That's right.\n"
	.string "This is where we welcome LUGIA.\p"
	.string "When the dance we practiced many\n"
	.string "days becomes one with the sound of the\l"
	.string "Tidal Bell we entrusted to you, then\l"
	.string "LUGIA shall come out from deep within\l"
	.string "the waterfall basin once again. $"
#endif

WhirlIslands_LugiaChamber_Text_Kimono_Closing1::
#if GERMAN
	.string "Was Ihr da vor Euch seht, ist Lugia…\n"
	.string "Seit Urzeiten erzählt man sich hier von\l"
	.string "ihm, dem Schutzpatron der Meere…\p"
	.string "Schon viele vor Euch haben sich daran\n"
	.string "versucht, das Gleiche zu erreichen,\l"
	.string "doch alle scheiterten sie kläglich…\p"
	.string "{PLAYER}, Ihr hattet endlich Erfolg\n"
	.string "damit, weil Euer Herz mit der\l"
	.string "Gischtglocke in Einklang stand…$"
#else
	.string "That is indeed LUGIA...\n"
	.string "The guardian of these islands from\l"
	.string "ancient times... \p"
	.string "So many have tried again and again,\n"
	.string "only to fail...\p"
	.string "{PLAYER}, your heart in complete\n"
	.string "harmony with the Tidal Bell has finally\l"
	.string "allowed it to appear...\n"
	.string "{PLAYER}, don't you see?\p"
	.string "LUGIA... It must have been waiting for\n"
	.string "someone like you all this time.\p"
	.string "Wouldn't you agree? $"
#endif

WhirlIslands_LugiaChamber_Text_Kimono_After::
#if GERMAN
	.string "Kimono-Girl: Heute hast du dich wahrlich\n"
	.string "bewiesen, {PLAYER}.$"
#else
	.string "KIMONO GIRL: You've proven yourself\n"
	.string "today, {PLAYER}.$"
#endif
