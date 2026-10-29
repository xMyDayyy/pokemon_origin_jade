EverGrandeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott::
#if IS_HNS
	@ Hoenn badge 6 (Winona)
	setvar VAR_0x8004, 5
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
#else
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
#endif
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_EVER_GRANDE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Woman::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Scott::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_EXIT
	waitse
	removeobject LOCALID_EVER_GRANDE_SCOTT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth::
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit::
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_ScottExit:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad:
#if GERMAN
	.string "Die Pokémon Liga triffst du kurz\n"
	.string "hinter der Siegesstraße.\p"
	.string "Wenn du schon so weit gekommen bist,\n"
	.string "musst du einfach weitergehen.$"
#else
	.string "The POKéMON LEAGUE is only a short\n"
	.string "distance after the VICTORY ROAD.\p"
	.string "If you've come this far, what choice\n"
	.string "do you have but to keep going?$"
#endif

EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon:
#if GERMAN
	.string "Die lange und qualvolle Siegesstraße…\p"
	.string "Es ist fast so, als würde man sein\n"
	.string "ganzes Leben noch einmal leben…\p"
	.string "Glaube an deine Pokémon und gib\n"
	.string "dein Bestes!$"
#else
	.string "The long and harrowing VICTORY ROAD…\p"
	.string "It's like reliving the path one has\n"
	.string "traveled in life…\p"
	.string "Believe in your POKéMON and give it\n"
	.string "your very best!$"
#endif

EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou:
#if GERMAN
	.string "Scott: {PLAYER}{KUN}, du hast dich zur\n"
	.string "Pokémon Liga durchgebissen.\p"
	.string "Das freut mich für dich!\n"
	.string "Meine Anfeuerungen haben sich gelohnt.\l"
	.string "\p"
	.string "Und wenn du Champ der Pokémon Liga\n"
	.string "wirst, {PLAYER}{KUN}…\p"
	.string "dann melde ich mich wieder bei dir.\p"
	.string "Okay, {PLAYER}{KUN}.\n"
	.string "Auf zum Ruhm!$"
#else
	.string "SCOTT: {PLAYER}{KUN}, you've clawed your\n"
	.string "way up to face the POKéMON LEAGUE!\p"
	.string "I'm happy for you!\n"
	.string "You made my cheering worthwhile!\p"
	.string "{PLAYER}{KUN}, if you were to become\n"
	.string "the POKéMON LEAGUE CHAMPION…\p"
	.string "I'll get in touch with you then.\p"
	.string "Okay, {PLAYER}{KUN}.\n"
	.string "Go for greatness!$"
#endif

