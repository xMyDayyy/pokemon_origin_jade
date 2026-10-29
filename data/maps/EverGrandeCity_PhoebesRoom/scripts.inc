EverGrandeCity_PhoebesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_OnFrame
	.byte 0

EverGrandeCity_PhoebesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_PhoebesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end

EverGrandeCity_PhoebesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 2, EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
	end

EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_PhoebesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_PhoebesRoom_EventScript_Phoebe::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
	@ Origin Jade: rematch team once Hoenn's league is won.
	goto_if_set FLAG_IS_HOENN_CHAMPION, EverGrandeCity_PhoebesRoom_EventScript_Rematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_Rematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	trainerbattle_rematch TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_RematchIntro, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_Text_IntroSpeech:
#if GERMAN
	.string "Ahahahahaha!\p"
	.string "Ich bin Antonia von den Top Vier.\n"
	.string "Ich habe am Pyroberg trainiert.\p"
	.string "Während des Trainings habe ich die\n"
	.string "Fähigkeit erworben, mit Geist-Pokémon\l"
	.string "zu kommunizieren.\p"
	.string "In der Tat ist das Band zwischen mir\n"
	.string "und den Pokémon sehr stark.\p"
	.string "Komm und schau, ob du irgendetwas\n"
	.string "gegen meine Pokémon ausrichten kannst.$"
#else
	.string "Ahahaha!\p"
	.string "I'm PHOEBE of the ELITE FOUR.\n"
	.string "I did my training on MT. PYRE.\p"
	.string "While I trained, I gained the ability\n"
	.string "to commune with GHOST-type POKéMON.\p"
	.string "Yes, the bond I developed with POKéMON\n"
	.string "is extremely tight.\p"
	.string "So, come on, just try and see if you can\n"
	.string "even inflict damage on my POKéMON!$"
#endif

EverGrandeCity_PhoebesRoom_Text_Defeat:
#if GERMAN
	.string "Oh, verdammt.\n"
	.string "Aus und vorbei. Verloren.$"
#else
	.string "Oh, darn.\n"
	.string "I've gone and lost.$"
#endif

EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech:
#if GERMAN
	.string "Das Band zwischen dir und deinen\n"
	.string "Pokémon ist ebenfalls sehr stark.\p"
	.string "Das habe ich gar nicht bemerkt, daher\n"
	.string "konnte ich nur verlieren.\p"
	.string "Ja, jetzt möchte ich sehen, wie weit\n"
	.string "dieses Band euch bringt.\p"
	.string "Geh und betritt den nächsten Raum.$"
#else
	.string "There's a definite bond between you\n"
	.string "and your POKéMON, too.\p"
	.string "I didn't recognize it, so it's only\n"
	.string "natural that I lost.\p"
	.string "Yup, I'd like to see how far your bond\n"
	.string "will carry you.\p"
	.string "Go ahead, move on to the next room.$"
#endif

EverGrandeCity_PhoebesRoom_Text_RematchIntro:
#if GERMAN
	.string "Antonia: Willkommen zurück!\p"
	.string "Auf dem Pyroberg habe ich seit deinem\n"
	.string "letzten Besuch neue Freunde gewonnen.\p"
	.string "Meine Pokémon brennen darauf,\n"
	.string "dich wiederzusehen!$"
#else
	.string "PHOEBE: Welcome back!\p"
	.string "I've made new friends at MT. PYRE\n"
	.string "since your last visit.\p"
	.string "My POKéMON are dying to\n"
	.string "see you again!$"
#endif
