PalletTown_PlayersHouse_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition::
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
	end

PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
	setrespawn HEAL_LOCATION_PALLET_TOWN
	return

PalletTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
	.2byte 0

PalletTown_PlayersHouse_2F_FirstWarpIn::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
	end

@ ============================================================================
@ Kanto-Merge: Die Wanduhr. In HnS haengt sie im Obergeschoss in Neuborkia,
@ wo der Spieler bei uns nicht mehr wohnt; gestellt wird sie jetzt hier.
@ Aufbau wie dort: die Uhr haengt an der Treppe, zwei Triggerfelder davor,
@ der Spieler laeuft hin und stellt sie.
@ ============================================================================
PalletTown_PlayersHouse_2F_Script_ClockSetupTrigger1::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_PlayersHouse_2F_Movement_PlayerWalkToClock1
	waitmovement 0
	goto PalletTown_PlayersHouse_2F_Script_ClockSetupCommon
	end

PalletTown_PlayersHouse_2F_Script_ClockSetupTrigger2::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_PlayersHouse_2F_Movement_PlayerWalkToClock2
	waitmovement 0
	goto PalletTown_PlayersHouse_2F_Script_ClockSetupCommon
	end

PalletTown_PlayersHouse_2F_Script_ClockSetupCommon::
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	setvar VAR_PALLET_HOUSE_CLOCK, 1
	setflag FLAG_SET_WALL_CLOCK
	releaseall
	end

@ Von (10,3) aus: nach rechts vor die Treppe, dann hoch zur Uhr.
PalletTown_PlayersHouse_2F_Movement_PlayerWalkToClock1:
	walk_right
	walk_up
	delay_8
	step_end

@ Von (11,3) aus steht der Spieler schon richtig.
PalletTown_PlayersHouse_2F_Movement_PlayerWalkToClock2:
	walk_up
	delay_8
	step_end

@ Ansprechbar, solange die Uhr haengt - stellt sie erneut.
PalletTown_PlayersHouse_2F_EventScript_WallClock::
	lockall
	msgbox PlayersHouse_2F_Text_ClockChange, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	releaseall
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_Text_PlayedWithNES::
#if GERMAN
	.string "{PLAYER} spielt NES!\p"
	.string "O.K.!\n"
	.string "Die Reise kann beginnen!$"
#else
	.string "{PLAYER} played with the NES.\p"
	.string "…Okay!\n"
	.string "It's time to go!$"
#endif

