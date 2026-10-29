SootopolisCity_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_OnWarp
	.byte 0

SootopolisCity_OnLoad:
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockGymDoor
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_LegendariesNotArrived
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockHouseDoors
	end

SootopolisCity_EventScript_LegendariesNotArrived::
	end

SootopolisCity_EventScript_LockHouseDoors::
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, TRUE
	return

SootopolisCity_EventScript_LockGymDoor::
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, TRUE
	return

SootopolisCity_OnTransition:
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
	call SootopolisCity_EventScript_SetWeather
	call SootopolisCity_EventScript_SetLayout
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetExitCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetOutsideGymObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetExpertBlockCaveEntrance
	end

SootopolisCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SootopolisCity_EventScript_SetBattleSpectators::
	setobjectxyperm LOCALID_KIRI, 13, 48
	setobjectxyperm LOCALID_SOOTOPOLIS_BOY_1, 46, 32
	setobjectxyperm LOCALID_SOOTOPOLIS_NINJA_BOY, 48, 41
	setobjectxyperm LOCALID_SOOTOPOLIS_WOMAN_1, 45, 43
	setobjectmovementtype LOCALID_KIRI, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SOOTOPOLIS_BOY_1, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_SOOTOPOLIS_NINJA_BOY, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_SOOTOPOLIS_WOMAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SootopolisCity_EventScript_SetLayout::
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalLayout
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_le VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
	return

SootopolisCity_EventScript_SetNormalLayout::
	return

SootopolisCity_EventScript_SetLegendariesLayout::
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
	return

SootopolisCity_EventScript_SetWeather::
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalWeather
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalWeather
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetDownpour
	goto_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetDownpour
	goto_if_le VAR_SKY_PILLAR_STATE, 1, Common_EventScript_SetAbnormalWeather
	return

SootopolisCity_EventScript_SetNormalWeather::
	return

SootopolisCity_EventScript_SetDownpour::
	setweather WEATHER_DOWNPOUR
	return

SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos::
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos
	return

SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
	return

SootopolisCity_EventScript_SetExitCaveOfOriginObjPos::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
	end

SootopolisCity_EventScript_SetOutsideGymObjPos::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 29, 33
	setobjectxyperm LOCALID_SOOTOPOLIS_MAXIE, 33, 35
	setobjectxyperm LOCALID_SOOTOPOLIS_ARCHIE, 34, 35
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 0, SootopolisCity_EventScript_SetWallaceMiddle
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 1, SootopolisCity_EventScript_SetWallaceRight
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 2, SootopolisCity_EventScript_SetWallaceLeft
	return

SootopolisCity_EventScript_SetWallaceMiddle::
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 33
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetWallaceRight::
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 32, 33
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetWallaceLeft::
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 30, 33
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetExpertBlockCaveEntrance::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
	return

SootopolisCity_OnWarp:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_PlayerFaceLegendaries
	.2byte 0

SootopolisCity_EventScript_PlayerFaceLegendaries::
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_PlayerFaceLegendaries1
	call_if_eq VAR_SKY_PILLAR_STATE, 2, SootopolisCity_EventScript_PlayerFaceLegendaries2
	end

SootopolisCity_EventScript_PlayerFaceLegendaries1::
	turnobject LOCALID_PLAYER, DIR_NORTH
	return

SootopolisCity_EventScript_PlayerFaceLegendaries2::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_SKY_PILLAR_STATE, 3
	return

SootopolisCity_OnResume:
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 9, 6
	end

SootopolisCity_OnFrame:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_StartLegendariesScene
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_StartRayquazaScene
	.2byte 0

@ If not at PokeCenter, assumed to have arrived via Dive
SootopolisCity_EventScript_StartLegendariesScene::
	lockall
	special StorePlayerCoordsInVars
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_LegendariesSceneFromDive
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_LegendariesSceneFromDive
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
	end

SootopolisCity_EventScript_LegendariesSceneFromPokeCenter::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	setweather WEATHER_ABNORMAL
	doweather
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
	special Script_DoRayquazaScene
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_PanToActionFromPokeCenter:
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_PanBackToPokeCenter:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	step_end

SootopolisCity_EventScript_LegendariesSceneFromDive::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	setweather WEATHER_ABNORMAL
	doweather
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
	special Script_DoRayquazaScene
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToDive
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_PanToActionFromDive:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PanBackToDive:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_KyogreAttack:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_KyogreDefend:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_KyogreMoveBack:
	lock_facing_direction
	walk_right
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_KyogreIdle:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	step_end

SootopolisCity_Movement_GroudonAttack:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_GroudonDefend:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_GroudonMoveBack:
	lock_facing_direction
	walk_left
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_GroudonIdle:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	step_end

@ If not at PokeCenter, assumed to have arrived via Dive
SootopolisCity_EventScript_StartRayquazaScene::
	lockall
	special StorePlayerCoordsInVars
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_RayquazaSceneFromDive
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_RayquazaSceneFromDive
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
	end

SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	call SootopolisCity_EventScript_SetRoughWater
	removeobject LOCALID_SOOTOPOLIS_GROUDON
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
	hideobjectat LOCALID_SOOTOPOLIS_RAYQUAZA, MAP_SOOTOPOLIS_CITY
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	waitstate
	playse SE_THUNDER
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 3
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_SOOTOPOLIS
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32
	waitstate
	end

SootopolisCity_EventScript_RayquazaSceneFromDive::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	call SootopolisCity_EventScript_SetRoughWater
	removeobject LOCALID_SOOTOPOLIS_GROUDON
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	waitstate
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 2
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_SURF
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpwhitefade MAP_SOOTOPOLIS_CITY, 29, 53
	waitstate
	end

SootopolisCity_EventScript_SetRoughWater::
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, FALSE
	return

SootopolisCity_Movement_RayquazaFlyOff:
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

SootopolisCity_Movement_PanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerApproachLegendaries:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Unused
SootopolisCity_Movement_PlayerApproachLegendariesDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Unused
SootopolisCity_Movement_UnusedPanUp:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

@ Unused
SootopolisCity_Movement_UnusedPanBack:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_EventScript_CaveOfOriginExpert::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ExpertPostLegendaries
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ExpertLegendaries
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_ExpertLeadToCave
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertLeadToCave::
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertPostLegendaries::
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertLegendaries::
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Kiri::
	lock
	faceplayer
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_KiriGiveBerry
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_KiriGiveBerry
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_KiriRayquaza
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_KiriRayquaza::
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
	closemessage
	release
	end

@ Gives 2 berries daily. First ranges from FIRST_KIRI_BERRY to LAST_KIRI_BERRY, second is always Figy or Iapapa
SootopolisCity_EventScript_KiriGiveBerry::
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
	random NUM_KIRI_BERRIES
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
	goto_if_eq VAR_RESULT, 1, SootopolisCity_EventScript_GiveIapapaBerry
	end

SootopolisCity_EventScript_GiveFigyBerry::
	giveitem ITEM_FIGY_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveIapapaBerry::
	giveitem ITEM_IAPAPA_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriReceivedBerry::
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriLikeSeasonBornIn::
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman2::
	lockall
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman2Rayquaza
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Woman2Rayquaza::
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Man::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ManPostLegendaries
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ManPostLegendaries::
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Woman1PostLegendaries
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman1Rayquaza
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_Woman1Legendaries
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1Legendaries::
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_WOMAN_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Woman1PostLegendaries::
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1Rayquaza::
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoy::
	lockall
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_NinjaBoyRayquaza
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_NinjaBoyNormal
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_NinjaBoyNormal
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_NinjaBoyNormal::
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoyRayquaza::
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1::
	lockall
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy1Rayquaza
	goto_if_set FLAG_IS_HOENN_CHAMPION, SootopolisCity_EventScript_Boy1GameClear
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Boy1Normal
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_Boy1Normal
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Boy1Rayquaza::
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1GameClear::
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1Normal::
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GymSign::
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
	end

SootopolisCity_EventScript_CitySign::
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
	end

EventScript_ClosedSootopolisDoor::
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
	end

SootopolisCity_EventScript_Steven::
	lockall
	applymovement LOCALID_SOOTOPOLIS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_StevenHelpWallace
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_StevenHelpedWallace
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_StevenHelpedWallace
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenHelpWallace::
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenMaxieArchieLeft::
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenHelpedWallace::
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin::
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
	waitmovement 0
	delay 120
	applymovement LOCALID_SOOTOPOLIS_EXPERT, SootopolisCity_Movement_ExpertMoveAside
	waitmovement 0
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
	waitmovement 0
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
	waitmovement 0
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 9, 20
	waitstate
	end

SootopolisCity_EventScript_StartWalkToCaveOfOriginWest::
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
	waitmovement 0
	return

SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth::
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
	waitmovement 0
	return

SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_StevenWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	delay_4
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_ExpertMoveAside:
	walk_slow_left
	walk_in_place_faster_right
	step_end

SootopolisCity_Movement_StevenArriveCaveEntrance:
	walk_down
	walk_down
	walk_left
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_left
	step_end

SootopolisCity_Movement_PlayerArriveCaveEntrance:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

SootopolisCity_Movement_PlayerEnterCaveOfOrigin:
	walk_up
	walk_up
	step_end

SootopolisCity_EventScript_Boy2::
	lockall
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy2Rayquaza
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Boy2Rayquaza::
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_BlackBelt::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_BlackBeltRayquaza
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_BlackBeltRayquaza::
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Girl::
	lockall
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_GirlRayquaza
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_GirlRayquaza::
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_Maniac::
	lockall
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ManiacRayquaza
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_ManiacRayquaza::
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Wallace::
	lock
	faceplayer
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_GoToSkyPillar
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, SootopolisCity_EventScript_GoToGym
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveWaterfall::
#if IS_HNS
	@ HnS: no HM from Wallace, the Rain Badge grants the Waterfall license.
	msgbox Text_HnsWallaceNoWaterfallHandover, MSGBOX_DEFAULT
#else
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_WATERFALL
#endif
	setflag FLAG_RECEIVED_HM_WATERFALL
#if IS_HNS
	msgbox Text_HnsWallaceWaterfallGoToGym, MSGBOX_DEFAULT
#else
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
#endif
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_WallaceMoveFromGym
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_EventScript_WallaceMoveFromGym
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_WallaceMoveFromGymWest
	release
	end

SootopolisCity_EventScript_WallaceMoveFromGym::
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGym
	waitmovement 0
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 1
	return

SootopolisCity_EventScript_WallaceMoveFromGymWest::
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGymWest
	waitmovement 0
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 2
	return

SootopolisCity_EventScript_GoToSkyPillar::
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GoToGym::
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Movement_WallaceMoveFromGym:
	walk_right
	walk_in_place_faster_down
	step_end

SootopolisCity_Movement_WallaceMoveFromGymWest:
	walk_left
	walk_in_place_faster_down
	step_end

SootopolisCity_EventScript_Maxie::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_MaxieRayquaza
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_MaxieRayquaza::
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
	releaseall
	end

SootopolisCity_EventScript_Archie::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ArchieRayquaza
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_ArchieRayquaza::
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
	releaseall
	end

SootopolisCity_EventScript_MaxieArchieLeave::
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setvar VAR_MT_PYRE_STATE, 2
	warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
	waitstate
	releaseall
	end

@ Unused
SootopolisCity_Movement_Levitate::
	levitate
	step_end

@ Unused
SootopolisCity_Movement_DestroyTask::
	destroy_extra_task
	step_end

SootopolisCity_Text_GymSign:
#if GERMAN
	.string "Xeneroville Pokémon Arena\n"
	.string "Leiter: Juan\p"
	.string "“Der Arenaleiter, der die Schönheit\n"
	.string "des Wassers zum Leuchten bringt!”$"
#else
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
	.string "LEADER: JUAN\p"
	.string "“The GYM LEADER with the beauty\n"
	.string "of pure water!”$"
#endif

SootopolisCity_Text_CitySign:
#if GERMAN
	.string "Xeneroville\p"
	.string "“Die mystische Stadt, in der die\n"
	.string "Geschichte stillsteht.”$"
#else
	.string "SOOTOPOLIS CITY\p"
	.string "“The mystical city where history\n"
	.string "slumbers.”$"
#endif

SootopolisCity_Text_DoorIsClosed:
#if GERMAN
	.string "Die Tür ist zu.$"
#else
	.string "The door is closed.$"
#endif

SootopolisCity_Text_PhysicallyFitLivingHere:
#if GERMAN
	.string "Im Meer tauchen. Treppenstufen auf und\n"
	.string "ab rennen…\p"
	.string "Wenn du an diesem Ort lebst, wirst du\n"
	.string "körperlich fit.$"
#else
	.string "Diving in the sea. Climbing up and\n"
	.string "down stairs all the time…\p"
	.string "If you live in this town, you end up\n"
	.string "getting physically fit.$"
#endif

SootopolisCity_Text_GiantPokemonSuddenlyAppeared:
#if GERMAN
	.string "Auf einmal tauchten diese riesigen\n"
	.string "Pokémon mitten im Ort auf!\p"
	.string "Ich habe sie noch nie vorher gesehen!\n"
	.string "\p"
	.string "Warum greifen sie sich wohl gegenseitig\n"
	.string "an?\p"
	.string "Warum können diese Pokémon nicht\n"
	.string "einfach Freunde sein?$"
#else
	.string "These giant POKéMON suddenly appeared\n"
	.string "in the middle of the city!\p"
	.string "And, I've never seen them before!\p"
	.string "Why are they smashing into each\n"
	.string "other like that?\p"
	.string "Why can't they be friends, those\n"
	.string "POKéMON?$"
#endif

SootopolisCity_Text_WhatIsThatGreenPokemon:
#if GERMAN
	.string "Was? Wie? Häh?\n"
	.string "Was ist das für ein grünes Pokémon?$"
#else
	.string "What? What? What?\n"
	.string "What is that green POKéMON?!$"
#endif

SootopolisCity_Text_WhereDidLegendariesGo:
#if GERMAN
	.string "Groudon und Kyogre…\n"
	.string "Wo seid ihr hin?\p"
	.string "Ob sie jetzt woanders für Dürre und\n"
	.string "Überschwemmungen sorgen?$"
#else
	.string "GROUDON and KYOGRE…\n"
	.string "Where did they go?\p"
	.string "Will they cause droughts or downpours\n"
	.string "somewhere else?$"
#endif

SootopolisCity_Text_TwoPokemonArentAngry:
#if GERMAN
	.string "Irgendwie habe ich das Gefühl, dass\n"
	.string "diese beiden Pokémon gar nicht wütend\l"
	.string "sind.\p"
	.string "Ich glaube… sie können einfach\n"
	.string "ihre Kräfte nicht kontrollieren…$"
#else
	.string "I just get this sense somehow that\n"
	.string "the two POKéMON aren't angry.\p"
	.string "I think… They probably can't control\n"
	.string "their own power…$"
#endif

SootopolisCity_Text_FlyingMonStoppedRampage:
#if GERMAN
	.string "Das fliegende Pokémon kam aus dem\n"
	.string "Himmel und hat die beiden wütenden\l"
	.string "Pokémon beruhigt…$"
#else
	.string "That flying POKéMON came down from\n"
	.string "the sky and stopped the rampaging\l"
	.string "POKéMON…$"
#endif

SootopolisCity_Text_WonderWhatWorldIsLike:
#if GERMAN
	.string "Ich… Ich war noch nie außerhalb der\n"
	.string "Stadt.\p"
	.string "Ich frage mich, wie die Welt hinter\n"
	.string "diesem Horizont aussieht?$"
#else
	.string "I… I've never been out of this city.\p"
	.string "I wonder what the world is like on\n"
	.string "the other side of this round sky?$"
#endif

SootopolisCity_Text_ThisIsWicked:
#if GERMAN
	.string "Wow! Das ist abgefahren!$"
#else
	.string "Wow!\n"
	.string "This is wicked!$"
#endif

SootopolisCity_Text_ThatWasWicked:
#if GERMAN
	.string "Wow! Das war abgefahren!$"
#else
	.string "Wow!\n"
	.string "That was wicked!$"
#endif

SootopolisCity_Text_GoRedAndBlueMon:
#if GERMAN
	.string "Los, rotes Pokémon!\n"
	.string "Gib nicht auf, blaues Pokémon!$"
#else
	.string "Go for it, red POKéMON!\n"
	.string "Don't back off, blue POKéMON!$"
#endif

SootopolisCity_Text_DoYouKnowMonNames:
#if GERMAN
	.string "… … … … …\n"
	.string "…\p"
	.string "Hi, weißt du, wie die beiden Pokémon\n"
	.string "heißen, die dort drüben kämpfen?$"
#else
	.string "… … … … … …\p"
	.string "Hi, do you know the names of those\n"
	.string "POKéMON fighting over there?$"
#endif

SootopolisCity_Text_GreenOneSettlesThings:
#if GERMAN
	.string "Ich war echt gespannt, ob das rote oder\n"
	.string "das blaue Pokémon gewinnt. Aber dann\l"
	.string "hat das grüne Pokémon alles\p"
	.string "entschieden.\n"
	.string "Das nenne ich eine spannende Wendung!$"
#else
	.string "I was wondering which one would win,\n"
	.string "the red one or the blue one, but, oh no,\l"
	.string "it's the green one that settles things!\p"
	.string "Talk about a huge turn of events!$"
#endif

SootopolisCity_Text_SeeingLegendWithOwnEyes:
#if GERMAN
	.string "Eine alte Legende sagt, dass Land und\n"
	.string "Meer ihre Formen durch einen\p"
	.string "unerbittlichen Kampf zwischen Pokémon\n"
	.string "bekommen haben.\p"
	.string "Und nun sehe ich genau das passieren.\n"
	.string "Whoa! \l"
	.string "Ich hätte nie gedacht, dass ich einmal\l"
	.string "\p"
	.string "mit meinen eigenen Augen Zeuge eines so\n"
	.string "bedeutenden Ereignisses werden würde!$"
#else
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between POKéMON.\p"
	.string "Well, I'm seeing that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"
#endif

SootopolisCity_Text_SawLegendWithOwnEyes:
#if GERMAN
	.string "Eine alte Legende sagt, dass Land und\n"
	.string "Meer ihre Formen durch einen\p"
	.string "unerbittlichen Kampf zwischen Pokémon\n"
	.string "bekommen haben.\p"
	.string "Und nun sehe ich genau das passieren.\n"
	.string "Whoa! \l"
	.string "Ich hätte nie gedacht, dass ich einmal\l"
	.string "\p"
	.string "mit meinen eigenen Augen Zeuge eines so\n"
	.string "bedeutenden Ereignisses werden würde!$"
#else
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between POKéMON.\p"
	.string "Well, I saw that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"
#endif

SootopolisCity_Text_BigPokemonFighting:
#if GERMAN
	.string "Ein großes Pokémon kämpft gegen ein\n"
	.string "anderes großes Pokémon!\p"
	.string "Bitte, jemand muss sie aufhalten!$"
#else
	.string "A big POKéMON is fighting with\n"
	.string "another big POKéMON!\p"
	.string "Please, someone make them stop!$"
#endif

SootopolisCity_Text_PrettyMonCameFromSky:
#if GERMAN
	.string "Ein wunderschönes Pokémon kam\n"
	.string "aus dem Himmel geflogen…$"
#else
	.string "A pretty POKéMON came down from\n"
	.string "the sky…$"
#endif

SootopolisCity_Text_SootopolisWillBeWrecked:
#if GERMAN
	.string "Oh nein!\n"
	.string "Xeneroville wird zerstört!$"
#else
	.string "Oh, no!\n"
	.string "SOOTOPOLIS CITY will get wrecked!$"
#endif

SootopolisCity_Text_SootopolisDidntGetWrecked:
#if GERMAN
	.string "Xeneroville wurde nicht zerstört!$"
#else
	.string "SOOTOPOLIS CITY didn't get wrecked!$"
#endif

SootopolisCity_Text_NoOrdinaryTourist:
#if GERMAN
	.string "Hm! Du bist den ganzen Weg nach\n"
	.string "Xeneroville gekommen? Du bist kein\l"
	.string "normaler Tourist.\p"
	.string "Aber das macht dich auch nicht zu\n"
	.string "einem außergewöhnlichen Touristen.$"
#else
	.string "Hm!\n"
	.string "You've come all the way to SOOTOPOLIS?\l"
	.string "You're no ordinary tourist.\p"
	.string "But I suppose that doesn't make you\n"
	.string "an extraordinary tourist, either.$"
#endif

SootopolisCity_Text_CityRegainedCalm:
#if GERMAN
	.string "In die Stadt ist wieder Ruhe\n"
	.string "eingekehrt.$"
#else
	.string "The city has regained its calm…$"
#endif

SootopolisCity_Text_CaveOfOriginPleaseLeave:
#if GERMAN
	.string "Wer bist du denn wohl?\p"
	.string "Dies ist die Urzeithöhle.\p"
	.string "Die Geister der Pokémon, zur Ruhe\n"
	.string "gebettet am Pyroberg, erwachen hier\l"
	.string "zum Leben, sagt man.\p"
	.string "Bitte verlasse diesen Ort.$"
#else
	.string "Who might you be?\p"
	.string "This is the CAVE OF ORIGIN.\p"
	.string "The spirits of POKéMON, becalmed at\n"
	.string "MT. PYRE, are said to be revived here.\p"
	.string "Please leave.$"
#endif

SootopolisCity_Text_LeadSuperiorTrainerToCave:
#if GERMAN
	.string "Eine Person mit unbeugsamem Willen und\n"
	.string "überragendem Talent…\p"
	.string "Ein Trainer, der sich mit den unter-\n"
	.string "schiedlichsten Pokémon auskennt…\p"
	.string "Wassili hat mich beauftragt, dass ich,\n"
	.string "sollte ich so eine Person finden, diesen\l"
	.string "Trainer zu dieser Höhle führen soll.$"
#else
	.string "A person with a strong will and\n"
	.string "superior talent…\p"
	.string "A TRAINER who has knowledge and\n"
	.string "experience of many kinds of POKéMON…\p"
	.string "If such a person were to appear, I was\n"
	.string "instructed by WALLACE to lead that\l"
	.string "TRAINER to this CAVE.$"
#endif

SootopolisCity_Text_AwakenedPokemonClash:
#if GERMAN
	.string "Oh…\p"
	.string "Der Kampf zwischen den beiden Pokémon\n"
	.string "wurde durch das Aufwachen eines\l"
	.string "dritten Pokémon beendet…$"
#else
	.string "Oh, my…\p"
	.string "The clash between the two awakened\n"
	.string "POKéMON was quelled by the awakening\l"
	.string "of a third POKéMON…$"
#endif

SootopolisCity_Text_CaveOfOriginSleepsToo:
#if GERMAN
	.string "Dies ist die Urzeithöhle…\p"
	.string "Nachdem die Krise überwunden ist,\n"
	.string "sollte auch für diese Höhle wieder Ruhe\l"
	.string "einkehren…$"
#else
	.string "This is the CAVE OF ORIGIN…\p"
	.string "With the passing of the crisis,\n"
	.string "the cave, too, shall sleep…$"
#endif

SootopolisCity_Text_SootopolisSkyBeautiful:
#if GERMAN
	.string "Xeneroville entwickelte sich im Krater\n"
	.string "eines Vulkans.\p"
	.string "Wenn du in den Himmel schaust, kannst\n"
	.string "du den Rand des Kraters über dir\l"
	.string "erkennen. Der Himmel wird zum Kreis.\p"
	.string "Aber das macht den Himmel über\n"
	.string "Xeneroville zum schönsten Himmel.$"
#else
	.string "SOOTOPOLIS sprang up as a town in\n"
	.string "the crater of a volcano.\p"
	.string "If you look up at the sky, the lip of\n"
	.string "the crater is also visible.\l"
	.string "So, all you see is the sky in a circle.\p"
	.string "But that's what makes the sky above\n"
	.string "SOOTOPOLIS the most beautiful.$"
#endif

SootopolisCity_Text_GiganticPokemonFight:
#if GERMAN
	.string "Wenn zwei so riesige Pokémon wild\n"
	.string "miteinander kämpfen, können wir nur\l"
	.string "dastehen und zuschauen.$"
#else
	.string "When two POKéMON that gigantic\n"
	.string "are fighting that savagely, there's\l"
	.string "not much that we can do.$"
#endif

SootopolisCity_Text_FearedWorstWhenPokemonFlewDown:
#if GERMAN
	.string "Als das dritte Pokémon erschien,\n"
	.string "befürchtete ich das Schlimmste.$"
#else
	.string "When that third POKéMON flew down,\n"
	.string "I feared the worst.$"
#endif

SootopolisCity_Text_NightSkyFavoriteScenery:
#if GERMAN
	.string "Ein Stück des Nachthimmels, umgeben\n"
	.string "vom Rund des Vulkankraters…\p"
	.string "Und in diesem runden Stück Himmel\n"
	.string "strahlen und blinken die Sterne, als\l"
	.string "wären sie lebendig. Ich liebe das…$"
#else
	.string "A circle of a night sky framed by\n"
	.string "the crater of a volcano…\p"
	.string "And in that ring, stars flicker and\n"
	.string "blink as if they were alive…\l"
	.string "It's my favorite scenery.$"
#endif

SootopolisCity_Text_WeatherWentWild:
#if GERMAN
	.string "Wir hatten heute Morgen klares Wetter,\n"
	.string "aber…\p"
	.string "auf einmal zog sich der Himmel mit\n"
	.string "dunklen Wolken zu und es fing an zu\l"
	.string "regnen. Und ein Gewitter zog auf.\p"
	.string "Das war unangenehm!\p"
	.string "Ob die beiden Pokémon die Ursache\n"
	.string "dafür sind?$"
#else
	.string "The weather was clear this morning,\n"
	.string "but…\p"
	.string "All of a sudden, dark clouds brewed up,\n"
	.string "rain started falling in sheets, and\l"
	.string "there was thunder and lightning, too.\p"
	.string "The weather just went completely\n"
	.string "wild!\p"
	.string "Is all of this because of those\n"
	.string "POKéMON?$"
#endif

SootopolisCity_Text_YouBroughtFlyingMon:
#if GERMAN
	.string "Oh?\p"
	.string "Hast du das fliegende Pokémon hierher\n"
	.string "gebracht?\p"
	.string "Nun, du bist ein unglaubliches Kind!$"
#else
	.string "Oh?\p"
	.string "It was you who brought that flying\n"
	.string "POKéMON here?\p"
	.string "Well, aren't you amazing!$"
#endif

SootopolisCity_Text_GroudonPleaseStop:
#if GERMAN
	.string "Marc: G… Groudon…\n"
	.string "Bitte! Hör auf damit!\p"
	.string "Ich erkenne nun deine ganze Kraft!\p"
	.string "Wenn du nicht aufhörst, wird nicht nur\n"
	.string "Xeneroville, sondern ganz Hoenn\l"
	.string "ruiniert werden!$"
#else
	.string "MAXIE: G… GROUDON…\n"
	.string "Please! Stop what you're doing!\p"
	.string "I know the extent of your power now!\p"
	.string "If you keep going, all HOENN, not just\n"
	.string "SOOTOPOLIS, will be utterly ruined!$"
#endif

SootopolisCity_Text_AfterAllOurScheming:
#if GERMAN
	.string "Marc: Es gab neben Groudon und Kyogre\n"
	.string "noch ein uraltes Pokémon…\p"
	.string "Und nachdem wir uns erfolglos\n"
	.string "angestrengt haben, schafft es dieses\l"
	.string "dritte Pokémon mit Leichtigkeit, die\l"
	.string "Sache wieder ins Lot zu bringen…\p"
	.string "Ha… Hahahahaha…$"
#else
	.string "MAXIE: So the super-ancient POKéMON\n"
	.string "weren't only GROUDON and KYOGRE…\p"
	.string "After all our fruitless scheming and\n"
	.string "frantic efforts, that one POKéMON's\l"
	.string "simple action puts everything right\l"
	.string "again as if nothing had happened…\p"
	.string "Fu…\n"
	.string "Fuhahaha…$"
#endif

SootopolisCity_Text_KyogreCalmDown:
#if GERMAN
	.string "Adrian: Kyogre! Was ist los?!?\n"
	.string "Schau hierher! Dies ist die rote Kugel!\l"
	.string "Beruhige dich! Kyogre!\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\p"
	.string "Das ist schlecht!\n"
	.string "Es reagiert überhaupt nicht!$"
#else
	.string "ARCHIE: KYOGRE! What's wrong?!\n"
	.string "Look over here! It's the RED ORB!\l"
	.string "Calm down! KYOGRE!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "It's no good!\n"
	.string "It's not responding at all!$"
#endif

SootopolisCity_Text_TryingMeaninglessToPokemon:
#if GERMAN
	.string "Adrian: Kyogre und Groudon sind wer\n"
	.string "weiß wohin geflohen.\p"
	.string "Das Klima in Hoenn hat sich wieder\n"
	.string "normalisiert…\p"
	.string "Haha… Hahahahahaha…\p"
	.string "Vielleicht war das, was wir vorhatten,\n"
	.string "bedeutungslos für die Pokémon…$"
#else
	.string "ARCHIE: KYOGRE and GROUDON both\n"
	.string "flew off to who knows where.\p"
	.string "The weather in HOENN has returned\n"
	.string "to its normal state…\p"
	.string "Haha…\n"
	.string "Hahaha…\p"
	.string "Maybe what we were trying to do was\n"
	.string "something small, even meaningless,\l"
	.string "to POKéMON…$"
#endif

SootopolisCity_Text_InvolvedWithCrisisComeWithMe:
#if GERMAN
	.string "Troy: Diese kämpfenden Pokémon…\n"
	.string "Groudon… und Kyogre…\p"
	.string "Diese uralten Pokémon sind aus einem\n"
	.string "langen Schlaf erwacht…\p"
	.string "Und nun treffen sie mit ihren un-\n"
	.string "kontrollierbaren Kräften aufeinander…\l"
	.string "\p"
	.string "{PLAYER}{KUN}…\p"
	.string "Da du hier bist, gehe ich davon aus,\n"
	.string "dass du bereit bist, uns in dieser Krise\l"
	.string "zu helfen.\p"
	.string "Da ist jemand, den möchte ich dir\n"
	.string "gerne vorstellen.\p"
	.string "Komm bitte mit.$"
#else
	.string "STEVEN: Those POKéMON fighting…\n"
	.string "GROUDON… And KYOGRE…\p"
	.string "The two super-ancient POKéMON\n"
	.string "were awakened from a long sleep…\p"
	.string "And now they are smashing each other\n"
	.string "with their uncontrollable energy…\p"
	.string "…{PLAYER}{KUN}.\p"
	.string "You being here now I'll take to mean\n"
	.string "that you're prepared to become\l"
	.string "involved in this crisis.\p"
	.string "Well, then, there's someone that\n"
	.string "I'd like you to meet.\p"
	.string "Come with me, please.$"
#endif

SootopolisCity_Text_DoesThisMakeYourFearPokemon:
#if GERMAN
	.string "Troy: Hör zu, {PLAYER}{KUN}.\p"
	.string "Wenn du dir Groudon und Kyogre\n"
	.string "anschaust, meinst du dann, dass man die\l"
	.string "Pokémon fürchten muss?\p"
	.string "Nein, das muss man nicht…\n"
	.string "Pokémon sind vielmehr…\p"
	.string "Warum ich dich das frage?\n"
	.string "Die Antwort kennst du bereits.$"
#else
	.string "STEVEN: Listen, {PLAYER}{KUN}.\p"
	.string "Does seeing GROUDON and KYOGRE make\n"
	.string "you think POKéMON are to be feared?\p"
	.string "But that's not true.\n"
	.string "POKéMON are really more…\p"
	.string "…Why am I asking you this?\n"
	.string "You already know.$"
#endif

SootopolisCity_Text_HereWereAreHelpWallace:
#if GERMAN
	.string "Troy: Okay, wir sind da!\p"
	.string "Innen wirst du jemanden namens\n"
	.string "Wassili finden.\p"
	.string "Ich glaube, du besitzt, was nötig ist,\n"
	.string "um ihm zu helfen…$"
#else
	.string "STEVEN: Okay, here we are!\p"
	.string "Inside here you'll find someone named\n"
	.string "WALLACE.\p"
	.string "I think you have what's needed to\n"
	.string "help him…$"
#endif

SootopolisCity_Text_KnowWhatsNeededToHelpHim:
#if GERMAN
	.string "Troy: Ich glaube, du besitzt, was\n"
	.string "nötig ist, um ihm zu helfen…$"
#else
	.string "STEVEN: I think you have what's\n"
	.string "needed to help him…$"
#endif

SootopolisCity_Text_NeverBeenToSkyPillar:
#if GERMAN
	.string "Troy: Der Himmelturm…\p"
	.string "Ich war niemals dort.\n"
	.string "Wo ist der überhaupt?$"
#else
	.string "STEVEN: The SKY PILLAR…\p"
	.string "I've never been there.\n"
	.string "I wonder where it could be?$"
#endif

SootopolisCity_Text_SoThatsRayquaza:
#if GERMAN
	.string "Troy: Das ist also Rayquaza…\p"
	.string "Unglaublich, wie die zwei tobenden\n"
	.string "Pokémon in Angst fliehen…$"
#else
	.string "STEVEN: So that's RAYQUAZA…\p"
	.string "It's incredible how the two rampaging\n"
	.string "POKéMON would flee from it in fear…$"
#endif

SootopolisCity_Text_MaxieArchieLeft:
#if GERMAN
	.string "Troy: Sieht so aus, als seien Marc und\n"
	.string "Adrian irgendwo hingegangen.\p"
	.string "Vielleicht sind sie zum Pyroberg\n"
	.string "gegangen, um die Kugeln\l"
	.string "zurückzubringen…$"
#else
	.string "STEVEN: It looks like both MAXIE and\n"
	.string "ARCHIE have gone away somewhere.\p"
	.string "Perhaps they've gone to MT. PYRE to\n"
	.string "return those ORBS…$"
#endif

SootopolisCity_Text_HaventYouScaledSkyPillar:
#if GERMAN
	.string "Wassili: Oh?\n"
	.string "{PLAYER}{KUN}?\p"
	.string "Du hast den Himmelturm noch nicht\n"
	.string "erklommen?\p"
	.string "Ich bin sicher, du schaffst es im\n"
	.string "Himmelturm bis ganz nach oben…$"
#else
	.string "WALLACE: Oh?\n"
	.string "{PLAYER}{KUN}?\p"
	.string "Haven't you scaled the SKY PILLAR\n"
	.string "yet?\p"
	.string "I'm sure that you can make it to\n"
	.string "the top of the SKY PILLAR…$"
#endif

SootopolisCity_Text_AquaMagmaDidntMeanHarm:
#if GERMAN
	.string "Wassili: {PLAYER}{KUN}…\p"
	.string "Die Anführer von Team Magma und Aqua…\n"
	.string "Ich glaube nicht, dass sie gefährlich\l"
	.string "sind.\p"
	.string "Es kann nicht schaden, wenn wir uns\n"
	.string "anhören, was sie zu sagen haben.$"
#else
	.string "WALLACE: {PLAYER}{KUN}…\p"
	.string "The leaders of TEAM MAGMA and AQUA,\n"
	.string "I don't think they meant harm.\p"
	.string "It wouldn't hurt to hear what they\n"
	.string "have to say for themselves.$"
#endif

SootopolisCity_Text_ThankYouForHelpAcceptThis:
#if GERMAN
	.string "Wassili: {PLAYER}{KUN}…\n"
	.string "Meine Augen haben mir also doch keinen\l"
	.string "Streich gespielt.\p"
	.string "Dank deiner Hilfe wurde Xeneroville…\n"
	.string "Nein! Ganz Hoenn wurde gerettet.\p"
	.string "Im Namen aller Menschen danke ich dir.\n"
	.string "\p"
	.string "Dies ist ein Geschenk von mir.\n"
	.string "Bitte nimm es an.$"
#else
	.string "WALLACE: {PLAYER}{KUN}…\n"
	.string "My eyes didn't deceive me.\p"
	.string "Thanks to your help, SOOTOPOLIS…\n"
	.string "No, all of HOENN was saved.\p"
	.string "On behalf of the people, I thank you.\p"
	.string "This is a gift from me.\n"
	.string "Please accept it.$"
#endif

SootopolisCity_Text_ExplainWaterfallGoToGym:
#if GERMAN
	.string "Die Versteckte Maschine enthält\n"
	.string "Kaskade.\p"
	.string "Sobald du den Schauerorden besitzt,\n"
	.string "kannst du einem Pokémon diese VM\l"
	.string "beibringen.\p"
	.string "Es kann dann Wasserfälle bezwingen.\p"
	.string "Und wo bekommt man den Schauerorden?\n"
	.string "Das weißt du doch, oder etwa nicht?\p"
	.string "Richtig! Du musst den Arenaleiter in\n"
	.string "Xeneroville besiegen.\p"
	.string "Wenn du bereit bist, tritt durch diese\n"
	.string "Tür.$"
#else
	.string "That HIDDEN MACHINE contains\n"
	.string "WATERFALL.\p"
	.string "If you have the RAIN BADGE, a POKéMON\n"
	.string "that has learned that HM move can\l"
	.string "force its way up waterfalls.\p"
	.string "And where does one get the RAIN BADGE?\n"
	.string "You know, don't you?\p"
	.string "That's right! You have to beat\n"
	.string "the SOOTOPOLIS GYM LEADER.\p"
	.string "When you're all set to go, step through\n"
	.string "that door.$"
#endif

SootopolisCity_Text_DazzledByMentor:
#if GERMAN
	.string "Wassili: Ich bin mir sicher, dass dich der\n"
	.string "atemberaubend elegante Kampfstil\l"
	.string "meines Mentors schwindelig machen wird.$"
#else
	.string "WALLACE: I'm sure that you will be\n"
	.string "dazzled by my mentor's breathtakingly\l"
	.string "elegant battle style.$"
#endif

#if IS_HNS
@ Unused.
Text_HnsWaterfallLicense:
#if GERMAN
	.string "{PLAYER} erhält die Lizenz für\n"
	.string "Kaskade!$"
#else
	.string "{PLAYER} received the licence for\n"
	.string "WATERFALL!$"
#endif

Text_HnsWallaceNoWaterfallHandover:
#if GERMAN
	.string "Wassili: {PLAYER}{KUN}…\n"
	.string "Meine Augen haben mir also doch keinen\l"
	.string "Streich gespielt.\p"
	.string "Dank deiner Hilfe wurde Xeneroville…\n"
	.string "Nein! Ganz Hoenn wurde gerettet.\p"
	.string "Im Namen aller Menschen danke ich dir.\p"
	.string "Schenken kann ich dir nichts, was ein\n"
	.string "Champ nicht schon hätte.$"
#else
	.string "WALLACE: {PLAYER}{KUN}…\n"
	.string "My eyes didn't deceive me.\p"
	.string "Thanks to your help, SOOTOPOLIS…\n"
	.string "No, all of HOENN was saved.\p"
	.string "On behalf of the people, I thank you.\p"
	.string "There is nothing I could give you\n"
	.string "that a CHAMPION wouldn't have.$"
#endif

Text_HnsWallaceWaterfallGoToGym:
#if GERMAN
	.string "Kaskade beherrschst du längst.\p"
	.string "In Hoenn brauchst du dafür aber den\n"
	.string "Schauerorden.\p"
	.string "Und wo bekommt man den Schauerorden?\n"
	.string "Das weißt du doch, oder etwa nicht?\p"
	.string "Richtig! Du musst den Arenaleiter in\n"
	.string "Xeneroville besiegen.\p"
	.string "Wenn du bereit bist, tritt durch diese\n"
	.string "Tür.$"
#else
	.string "You've long known how to use\n"
	.string "WATERFALL.\p"
	.string "In HOENN, though, you need the\n"
	.string "RAIN BADGE for it.\p"
	.string "And where does one get the RAIN BADGE?\n"
	.string "You know, don't you?\p"
	.string "That's right! You have to beat\n"
	.string "the SOOTOPOLIS GYM LEADER.\p"
	.string "When you're all set to go, step through\n"
	.string "that door.$"
#endif
#endif
