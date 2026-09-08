PalletTown_PlayersHouse_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_PlayersHouse_2F_OnFrame
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
@ Der Ablauf folgt NewBarkTown_PlayersHouse_2F_Script_ClockSetupTrigger:
@ Ausrufezeichen, Hinweis, Uhrbildschirm.
@ ============================================================================
PalletTown_PlayersHouse_2F_OnFrame::
	map_script_2 VAR_PALLET_HOUSE_CLOCK, 0, PalletTown_PlayersHouse_2F_EventScript_ClockSetup
	.2byte 0

PalletTown_PlayersHouse_2F_EventScript_ClockSetup::
	lockall
	delay 20
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 60
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	setvar VAR_PALLET_HOUSE_CLOCK, 1
	setflag FLAG_SET_WALL_CLOCK
	releaseall
	end

@ Ansprechbar, solange die Uhr haengt - stellt sie erneut.
PalletTown_PlayersHouse_2F_EventScript_WallClock::
	lockall
	goto_if_unset FLAG_SET_WALL_CLOCK, PalletTown_PlayersHouse_2F_EventScript_ClockSetup
	msgbox PlayersHouse_2F_Text_ClockChange, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	releaseall
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_Sign::
	msgbox PalletTown_PlayersHouse_2F_Text_PressLRForHelp, MSGBOX_SIGN
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

PalletTown_PlayersHouse_2F_Text_PressLRForHelp::
#if GERMAN
	.string "Eine Nachricht…\p"
	.string "Wenn du nicht weiter weißt, rufe das\n"
	.string "Hilfe-Menü durch Drücken der L- oder\l"
	.string "R-Taste auf.$"
#else
	.string "It's a posted notice…\p"
	.string "If you're confused, ask for HELP!\n"
	.string "Press the L or R Button!$"
#endif

