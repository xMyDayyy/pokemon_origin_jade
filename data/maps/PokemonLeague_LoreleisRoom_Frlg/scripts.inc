PokemonLeague_LoreleisRoom_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_LoreleisRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_LoreleisRoom_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_LoreleisRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_LoreleisRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_LoreleisRoom_OnFrame
	.byte 0

PokemonLeague_LoreleisRoom_OnResume::
	setvar VAR_0x8004, 0
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_LoreleisRoom_OnLoad::
	call_if_set FLAG_DEFEATED_LORELEI, PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen
	call_if_eq VAR_MAP_SCENE_POKEMON_LEAGUE, 1, PokemonLeague_LoreleisRoom_EventScript_CloseEntry
	end

PokemonLeague_LoreleisRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_LoreleisRoom_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_LEAGUE_LORELEIS_ROOM
	end

PokemonLeague_LoreleisRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_LoreleisRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_LoreleisRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_LoreleisRoom_OnFrame::
	map_script_2 VAR_MAP_SCENE_POKEMON_LEAGUE, 0, PokemonLeague_LoreleisRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_LoreleisRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 1
	releaseall
	end

PokemonLeague_LoreleisRoom_EventScript_Lorelei::
	lock
	faceplayer
	famechecker FAMECHECKER_LORELEI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_DEFEATED_LORELEI, PokemonLeague_LoreleisRoom_EventScript_PostBattle
	famechecker FAMECHECKER_LORELEI, 0
	famechecker FAMECHECKER_LORELEI, 1
	@ Origin Jade: rematch intro and team after the Kanto title.
	call_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_LoreleisRoom_EventScript_Intro
	call_if_set FLAG_IS_KANTO_CHAMPION, PokemonLeague_LoreleisRoom_EventScript_RematchIntro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	call_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_LoreleisRoom_EventScript_Battle
	call_if_set FLAG_IS_KANTO_CHAMPION, PokemonLeague_LoreleisRoom_EventScript_Rematch
	clearflag FLAG_TEMP_5
	goto PokemonLeague_LoreleisRoom_EventScript_DefeatedLorelei
	end

PokemonLeague_LoreleisRoom_EventScript_Intro::
	msgbox PokemonLeague_LoreleisRoom_Text_Intro
	return

PokemonLeague_LoreleisRoom_EventScript_RematchIntro::
	msgbox PokemonLeague_LoreleisRoom_Text_RematchIntro
	return

PokemonLeague_LoreleisRoom_EventScript_Battle::
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LORELEI, PokemonLeague_LoreleisRoom_Text_Defeat
	return

PokemonLeague_LoreleisRoom_EventScript_Rematch::
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LORELEI_2, PokemonLeague_LoreleisRoom_Text_Defeat
	return

PokemonLeague_LoreleisRoom_EventScript_PostBattle::
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle
	release
	end

PokemonLeague_LoreleisRoom_EventScript_DefeatedLorelei::
	setflag FLAG_DEFEATED_LORELEI
	call PokemonLeague_EventScript_OpenDoor
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle
	release
	end

PokemonLeague_LoreleisRoom_Text_Intro::
#if GERMAN
	.string "Willkommen in der Pokémon Liga!\p"
	.string "Ich bin Lorelei und gehöre zu den\n"
	.string "Top Vier!\p"
	.string "Niemand kann sich mit mir messen,\n"
	.string "wenn es um Eis-Pokémon geht!\p"
	.string "Die Kraft von Eis-Attacken ist\n"
	.string "unglaublich!\p"
	.string "Du wirst um Gnade winseln, wenn ich\n"
	.string "deine Pokémon eingefroren habe!\p"
	.string "Hahaha!\n"
	.string "Bist du bereit?{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"
#else
	.string "Welcome to the POKéMON LEAGUE.\p"
	.string "I am LORELEI of the ELITE FOUR.\p"
	.string "No one can best me when it comes\n"
	.string "to icy POKéMON.\p"
	.string "Freezing moves are powerful.\p"
	.string "Your POKéMON will be at my mercy\n"
	.string "when they are frozen solid.\p"
	.string "Hahaha!\n"
	.string "Are you ready?{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"
#endif

PokemonLeague_LoreleisRoom_Text_RematchIntro::
#if GERMAN
	.string "Willkommen in der Pokémon Liga!\p"
	.string "Ich, Lorelei von den Top Vier, bin\n"
	.string "zurückgekehrt!\p"
	.string "Du weißt ja Bescheid! Niemand kann sich\n"
	.string "mit mir messen, wenn es um Eis-Pokémon\l"
	.string "geht!\l"
	.string "Die Kraft von Eis-Attacken ist\l"
	.string "unglaublich!\p"
	.string "Du wirst um Gnade winseln, wenn ich\n"
	.string "deine Pokémon eingefroren habe!\p"
	.string "Hahaha!\n"
	.string "Bist du bereit?{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"
#else
	.string "Welcome to the POKéMON LEAGUE.\p"
	.string "I, LORELEI of the ELITE FOUR,\n"
	.string "have returned!\p"
	.string "You know how it goes.\n"
	.string "No one can best me when it comes\l"
	.string "to icy POKéMON.\p"
	.string "Freezing moves are powerful.\p"
	.string "Your POKéMON will be at my mercy\n"
	.string "when they are frozen solid.\p"
	.string "Hahaha!\n"
	.string "Are you ready?{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"
#endif

PokemonLeague_LoreleisRoom_Text_Defeat::
#if GERMAN
	.string "… es sollte nicht so laufen!$"
#else
	.string "…Things shouldn't be this way!$"
#endif

PokemonLeague_LoreleisRoom_Text_PostBattle::
#if GERMAN
	.string "Du bist besser, als ich dachte!\n"
	.string "Geh ruhig weiter!\p"
	.string "Das hier war nur ein Vorgeschmack auf\n"
	.string "die Dinge, die dich noch erwarten...$"
#else
	.string "You're better than I thought.\n"
	.string "Go on ahead.\p"
	.string "You only got a taste of the\n"
	.string "POKéMON LEAGUE's power.$"
#endif

