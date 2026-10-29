EverGrandeCity_SidneysRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition:
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	end

EverGrandeCity_SidneysRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	end

EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_SidneysRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_SidneysRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_SidneysRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_Sidney::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
	@ Origin Jade: rematch team once the player is Hoenn champion.
	goto_if_set FLAG_IS_HOENN_CHAMPION, EverGrandeCity_SidneysRoom_EventScript_Rematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_Rematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	trainerbattle_rematch TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_RematchIntro, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_IntroSpeech:
#if GERMAN
	.string "Da bist du ja endlich!\n"
	.string "Ich bin Ulrich von den Top Vier.\p"
	.string "Der Champion von Johto und Kanto,\n"
	.string "hier in unserer Liga…\l"
	.string "Gut! Das sieht gut aus!\p"
	.string "Schön! Dann lass uns beide einen Kampf\n"
	.string "erleben, wie man ihn nur hier in der\l"
	.string "Pokémon Liga erleben kann!$"
#else
	.string "So you finally made it!\n"
	.string "I'm SIDNEY of the ELITE FOUR.\p"
	.string "The CHAMPION of JOHTO and KANTO,\n"
	.string "right here in our LEAGUE…\l"
	.string "That's good! Looking real good!\p"
	.string "All right! You and me, let's enjoy\n"
	.string "a battle that can only be staged\l"
	.string "here in the POKéMON LEAGUE!$"
#endif

EverGrandeCity_SidneysRoom_Text_Defeat:
#if GERMAN
	.string "Ich habe verloren! Ich, Ulrich von den\n"
	.string "Top Vier. Macht nichts, es war lustig.$"
#else
	.string "Well, how do you like that? I lost!\n"
	.string "Eh, it was fun, so it doesn't matter.$"
#endif

EverGrandeCity_SidneysRoom_Text_PostBattleSpeech:
#if GERMAN
	.string "Nun, hör dir an, was dieser Verlierer\n"
	.string "zu sagen hat.\p"
	.string "Du bist bestens ausgerüstet.\n"
	.string "Daher solltest du nun in den nächsten\l"
	.string "Raum gehen - zum nächsten Kampf.$"
#else
	.string "Well, listen to what this loser has\n"
	.string "to say.\p"
	.string "You've got what it takes to go far.\n"
	.string "Now, go on to the next room and enjoy\l"
	.string "your next battle!$"
#endif

EverGrandeCity_SidneysRoom_Text_RematchIntro:
#if GERMAN
	.string "Ulrich: Ha! Du schon wieder!\p"
	.string "Seit unserem letzten Kampf habe ich\n"
	.string "an nichts anderes gedacht.\p"
	.string "Mein Team ist nicht mehr das alte…\n"
	.string "Und ich will sehen, ob du noch\l"
	.string "der Alte bist!$"
#else
	.string "SIDNEY: Ha! You again!\p"
	.string "Since our last battle, I haven't been\n"
	.string "able to think of anything else.\p"
	.string "My team isn't what it used to be…\n"
	.string "And I want to see if you are still\l"
	.string "what you used to be!$"
#endif
