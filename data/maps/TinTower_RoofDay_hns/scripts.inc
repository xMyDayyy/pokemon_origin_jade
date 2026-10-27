TinTower_RoofDay_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_RoofDay_OnTransition
	.byte 0

@ Ho-Oh: story battle at VAR_COMPLETED_HO_OH 2; afterwards the legendary rules decide
@ (see docs/origin_jade/DECISIONS.md, D-026). The Ho-Oh not chosen on Route 39 waits
@ after the first Johto title once Lugia is caught.
TinTower_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, TinTower_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, TinTower_RoofDay_EventScript_SetDay
	goto_if_eq VAR_COMPLETED_HO_OH, 2, TinTower_RoofDay_MapScript_HoohStory
	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_HO_OH
	setobjectxyperm LOCALID_HO_OH, 10, 6
	goto_if_lt VAR_COMPLETED_HO_OH, 3, TinTower_RoofDay_MapScript_End
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, TinTower_RoofDay_MapScript_CheckHoOh
	goto_if_unset FLAG_IS_JOHTO_CHAMPION, TinTower_RoofDay_MapScript_End
	goto_if_unset FLAG_CAUGHT_LUGIA, TinTower_RoofDay_MapScript_End
TinTower_RoofDay_MapScript_CheckHoOh:
	setvar VAR_0x8004, LEGENDARY_HO_OH
	specialvar VAR_RESULT, IsLegendaryAvailable
	goto_if_ne VAR_RESULT, TRUE, TinTower_RoofDay_MapScript_End
	clearflag FLAG_HIDE_HO_OH
TinTower_RoofDay_MapScript_End:
	end

TinTower_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_TIN_TOWER_ROOF_NIGHT_HNS
	return

TinTower_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_TIN_TOWER_ROOF_DAY_HNS
	return

TinTower_RoofDay_MapScript_HoohStory::
	clearflag FLAG_HIDE_HO_OH
	end

TinTower_RoofDay_EventScript_TalkToKimono::
	lockall
	playbgm MUS_HG_KIMONO_GIRL_DANCE, FALSE
	msgbox TinTower_RoofDay_Text_Kimono_Opening, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Step_Aside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, TinTower_RoofDay_Walk_To_Center
	waitmovement 0
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Step_In
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Step_Start_Left
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Step_Start_Right
	waitmovement 5
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	setweather WEATHER_DROUGHT
	doweather
	@ 1
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Down
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Right
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Left
	waitmovement LOCALID_KIMONO_4
	delay 30
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 2
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Down
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Far_Right
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Far_Left
	waitmovement LOCALID_KIMONO_4
	delay 30
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 3
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Right
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Left
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Down
	waitmovement LOCALID_TINTOWER_KIMONO_3
	delay 30
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 4
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Far_Right
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Far_Left
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Down
	waitmovement LOCALID_TINTOWER_KIMONO_3
	delay 30
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 5
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Left_Up
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Right_Up
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Dance_Step_Up
	waitmovement LOCALID_KIMONO_1
	delay 30
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	waitse
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_HO_OH, TinTower_RoofDay_Movement_HoOhAppear
	applymovement OBJ_EVENT_ID_CAMERA, TinTower_RoofDay_Movement_CameraPanUp
	waitmovement 0
	delay 50
	@ setweather WEATHER_NONE
	@ doweather
	waitse
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_HO_OH, TinTower_RoofDay_Movement_HoOhApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, TinTower_RoofDay_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_1, TinTower_RoofDay_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_TINTOWER_KIMONO_2, TinTower_RoofDay_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_TINTOWER_KIMONO_3, TinTower_RoofDay_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_4, TinTower_RoofDay_Movement_Kimono_Dance_Look_Up
	waitmovement 0
	msgbox TinTower_RoofDay_Text_Kimono_Closing1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

@ The story battle moves the story on whatever the outcome.
TinTower_RoofDay_EventScript_HoOh::
	lockall
	goto_if_ne VAR_COMPLETED_HO_OH, 2, TinTower_RoofDay_EventScript_HoOhPostgame
	waitse
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	playbgm MUS_HG_VS_HO_OH, 0
	seteventmon SPECIES_HO_OH, 50
	call TinTower_RoofDay_EventScript_HoOhBattle
	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	applymovement LOCALID_KIMONO_MID, TinTower_RoofDay_Movement_Kimono_Dance_Shift_Right2
	waitmovement 0
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	setvar VAR_ECRUTEAK_CITY_THEATER, 8
	setvar VAR_COMPLETED_HO_OH, 3
	releaseall
	end

@ After the story: the chosen Ho-Oh at Lv 50, the Ho-Oh not chosen at Lv 70.
TinTower_RoofDay_EventScript_HoOhPostgame::
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	playbgm MUS_HG_VS_HO_OH, 0
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, TinTower_RoofDay_EventScript_HoOhPostgameChosen
	seteventmon SPECIES_HO_OH, 70
	goto TinTower_RoofDay_EventScript_HoOhPostgameBattle

TinTower_RoofDay_EventScript_HoOhPostgameChosen:
	seteventmon SPECIES_HO_OH, 50
TinTower_RoofDay_EventScript_HoOhPostgameBattle:
	call TinTower_RoofDay_EventScript_HoOhBattle
	releaseall
	end

@ Battle, record the outcome, Ho-Oh leaves the roof.
TinTower_RoofDay_EventScript_HoOhBattle::
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_0x8004, LEGENDARY_HO_OH
	special RecordLegendaryBattleOutcome
	setvar VAR_LAST_TALKED, LOCALID_HO_OH
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TinTower_RoofDay_EventScript_CaughtHooh
	goto TinTower_RoofDay_EventScript_HoohFlewAway

TinTower_RoofDay_EventScript_HoohFlewAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_HO_OH
	setweather WEATHER_NONE
	doweather
	setflag FLAG_HIDE_HO_OH
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, SPECIES_HO_OH
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	return

TinTower_RoofDay_EventScript_CaughtHooh::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_HO_OH
	setweather WEATHER_NONE
	doweather
	setflag FLAG_HIDE_HO_OH
	fadescreenswapbuffers FADE_FROM_BLACK
	return

TinTower_RoofDay_EventScript_Zuki::
	goto_if_eq VAR_COMPLETED_HO_OH, 3, TinTower_RoofDay_EventScript_ZukiAfter
	msgbox TinTower_RoofDay_Text_Zuki_Before, MSGBOX_NPC
	end
TinTower_RoofDay_EventScript_ZukiAfter::
	goto_if_unset FLAG_CAUGHT_HO_OH, TinTower_RoofDay_EventScript_ZukiAfterNotCaught
	msgbox TinTower_RoofDay_Text_Kimono_AfterCaught, MSGBOX_NPC
	end
TinTower_RoofDay_EventScript_ZukiAfterNotCaught::
	msgbox TinTower_RoofDay_Text_Kimono_AfterNotCaught, MSGBOX_NPC
	end

TinTower_RoofDay_EventScript_Naoko::
	goto_if_eq VAR_COMPLETED_HO_OH, 3, TinTower_RoofDay_EventScript_NaokoAfter
	msgbox TinTower_RoofDay_Text_Naoko_Before, MSGBOX_NPC
	end
TinTower_RoofDay_EventScript_NaokoAfter::
	msgbox TinTower_RoofDay_Text_Kimono_After, MSGBOX_NPC
	end

TinTower_RoofDay_EventScript_Miki::
	goto_if_eq VAR_COMPLETED_HO_OH, 3, TinTower_RoofDay_EventScript_MikiAfter
	msgbox TinTower_RoofDay_Text_Miki_Before, MSGBOX_NPC
	end
TinTower_RoofDay_EventScript_MikiAfter::
	msgbox TinTower_RoofDay_Text_Kimono_After, MSGBOX_NPC
	end

TinTower_RoofDay_EventScript_Sayo::
	goto_if_eq VAR_COMPLETED_HO_OH, 3, TinTower_RoofDay_EventScript_SayoAfter
	msgbox TinTower_RoofDay_Text_Sayo_Before, MSGBOX_NPC
	end
TinTower_RoofDay_EventScript_SayoAfter::
	msgbox TinTower_RoofDay_Text_Kimono_After, MSGBOX_NPC
	end

TinTower_RoofDay_EventScript_Kuni::
	goto_if_eq VAR_COMPLETED_HO_OH, 3, TinTower_RoofDay_EventScript_KuniAfter
	msgbox TinTower_RoofDay_Text_Kuni_Before, MSGBOX_NPC
	end
TinTower_RoofDay_EventScript_KuniAfter::
	msgbox TinTower_RoofDay_Text_Kimono_After, MSGBOX_NPC
	end

TinTower_RoofDay_Text_Kimono_AfterNotCaught:
#if GERMAN
	.string "Ihr habt Ho-Oh nicht nur hierher\n"
	.string "gerufen, sondern Ihr konntet es auch\l"
	.string "wie durch ein Wunder einfangen…\p"
	.string "Das war wirklich eine Glanzleistung.\n"
	.string "Es gibt nun nichts mehr, was wir Euch\l"
	.string "noch erzählen könnten.\p"
	.string "Wir wünschen Euch auch für den Rest\n"
	.string "Eurer Reise alles Gute…$"
#else
	.string "You have not only made HO-OH\n"
	.string "appear, but you have also defeated\l"
	.string "it...\p"
	.string "There is nothing more for us to\n"
	.string "say. Take care of yourself in your\l"
	.string "journey...$"
#endif

TinTower_RoofDay_Text_Kimono_AfterCaught:
#if GERMAN
	.string "Ihr habt Ho-Oh nicht nur hierher\n"
	.string "gerufen, sondern Ihr konntet es auch\l"
	.string "wie durch ein Wunder einfangen…\p"
	.string "Das war wirklich eine Glanzleistung.\n"
	.string "Es gibt nun nichts mehr, was wir Euch\l"
	.string "noch erzählen könnten.\p"
	.string "Wir wünschen Euch auch für den Rest\n"
	.string "Eurer Reise alles Gute…$"
#else
	.string "You have not only made HO-OH\n"
	.string "appear, but you have also caught\l"
	.string "it...\p"
	.string "There is nothing more for us to\n"
	.string "say. Take care of yourself in your\l"
	.string "journey...$"
#endif

TinTower_RoofDay_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TinTower_RoofDay_Movement_CameraPanDown:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

TinTower_RoofDay_Movement_HoOhApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

TinTower_RoofDay_Movement_HoOhAppear:
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end


TinTower_RoofDay_Movement_Kimono_Step_Aside:
	face_right
	delay_16
	walk_right
	delay_16
	face_left
	step_end

TinTower_RoofDay_Walk_To_Center:
	walk_up
	walk_up
	walk_up
	delay_16
	face_down
	step_end

TinTower_RoofDay_Movement_Kimono_Step_In:
	walk_left
	delay_16
	face_down
	step_end


TinTower_RoofDay_Movement_Kimono_Step_Start_Left:
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

TinTower_RoofDay_Movement_Kimono_Step_Start_Right:
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

TinTower_RoofDay_Movement_Kimono_Dance_Mid:
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

TinTower_RoofDay_Movement_Kimono_Dance_Shift_Down:
	face_down
	delay_8
	walk_down
	delay_8
	face_down
	delay_16
	step_end

TinTower_RoofDay_Movement_Kimono_Dance_Shift_Right:
	face_right
	delay_8
	walk_right
	delay_8
	face_down
	delay_16
	step_end

TinTower_RoofDay_Movement_Kimono_Dance_Shift_Up:
	face_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_down
	delay_16
	step_end

TinTower_RoofDay_Movement_Kimono_Dance_Shift_Left:
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

TinTower_RoofDay_Movement_Kimono_Dance_Shift_Far_Right:
	face_right
	delay_8
	walk_right
	walk_right
	walk_right
	face_down
	delay_16
	step_end

TinTower_RoofDay_Movement_Kimono_Dance_Shift_Far_Left:
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

TinTower_RoofDay_Movement_Kimono_Dance_Shift_Left_Up:
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

TinTower_RoofDay_Movement_Kimono_Dance_Shift_Right_Up:
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

TinTower_RoofDay_Movement_Kimono_Dance_Look_Up:
	face_right
	delay_8
	face_up
	delay_16
	step_end

TinTower_RoofDay_Movement_Kimono_Dance_Step_Up:
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

TinTower_RoofDay_Movement_Kimono_Dance_Shift_Right2:
	face_right
	delay_8
	walk_right
	delay_8
	face_down
	delay_16
	face_left
	step_end

TinTower_RoofDay_Text_Zuki_Before::
#if GERMAN
	.string "Tamao: Geh nun zu Ho-Oh.$"
#else
	.string "ZUKI: Go, face HO-OH. $"
#endif
TinTower_RoofDay_Text_Naoko_Before::
	.string "Umeko: Geh nun zu Ho-Oh.$"
TinTower_RoofDay_Text_Miki_Before::
#if GERMAN
	.string "Satsuki: Geh nun zu Ho-Oh.$"
#else
	.string "MIKI: Go, face HO-OH. $"
#endif
TinTower_RoofDay_Text_Sayo_Before::
	.string "Sakura: Geh nun zu Ho-Oh.$"
TinTower_RoofDay_Text_Kuni_Before::
#if GERMAN
	.string "Komomo: Geh nun zu Ho-Oh.$"
#else
	.string "KUNI: Go, face HO-OH. $"
#endif

TinTower_RoofDay_Text_Kimono_Opening::
#if GERMAN
	.string "Tamao: Dies ist der Ort, an dem wir\n"
	.string "mit Ho-Oh in Kontakt treten werden.\p"
	.string "Wenn hier gleichzeitig der Klang des\n"
	.string "Tanzes, den wir täglich proben, und der\l"
	.string "Klang der Klarglocke, die Ihr erhalten\l"
	.string "habt, ertönt, wird Ho-Oh wieder vom\p"
	.string "weiten Himmelszelt zu uns\n"
	.string "herabsteigen!$"
#else
	.string "KIMONO GIRL: That's right.\n"
	.string "This is where we welcome HO-OH.\p"
	.string "When the dance we practiced many\n"
	.string "days becomes one with the sound of the\p"
	.string "CLEAR BELL we entrusted to you, then\n"
	.string "HO-OH shall come down from the great\l"
	.string "arch of the sky once again. $"
#endif

TinTower_RoofDay_Text_Kimono_Closing1::
#if GERMAN
	.string "Das ist tatsächlich Ho-Oh…\n"
	.string "Der Hüter des Himmels aus\p"
	.string "alten Zeiten…\p"
	.string "So viele haben es immer wieder\n"
	.string "versucht und sind gescheitert…\p"
	.string "{PLAYER}, dein Herz in völliger\n"
	.string "Harmonie mit der Klarglocke\p"
	.string "hat es endlich erscheinen lassen…\n"
	.string "{PLAYER}, siehst du das nicht?\p"
	.string "Ho-Oh… Es muss die ganze Zeit auf\n"
	.string "jemanden wie dich gewartet haben.\p"
	.string "Stimmst du mir zu?$"
#else
	.string "That is indeed HO-OH...\n"
	.string "The guardian of the sky from\p"
	.string "ancient times... \p"
	.string "So many have tried again and again,\n"
	.string "only to fail...\p"
	.string "{PLAYER}, your heart in complete\n"
	.string "harmony with the CLEAR BELL has finally\p"
	.string "allowed it to appear...\n"
	.string "{PLAYER}, don't you see?\p"
	.string "HO-OH... It must have been waiting for\n"
	.string "someone like you all this time.\p"
	.string "Wouldn't you agree? $"
#endif

TinTower_RoofDay_Text_Kimono_After::
#if GERMAN
	.string "Wir danken Euch für alles.\n"
	.string "Wenn Ihr Professor Lind begegnet,\l"
	.string "richtet ihm bitte unsere Grüße aus.$"
#else
	.string "You have done a great job.\n"
	.string "Say hello to PROF.ELM for us.$"
#endif
