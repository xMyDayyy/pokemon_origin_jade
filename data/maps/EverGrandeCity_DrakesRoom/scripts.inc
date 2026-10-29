EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	@ Origin Jade: rematch team once Hoenn's league is won.
	goto_if_set FLAG_IS_HOENN_CHAMPION, EverGrandeCity_DrakesRoom_EventScript_Rematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_Rematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	trainerbattle_rematch TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_RematchIntro, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
#if GERMAN
	.string "Ich bin der letzte der Top Vier in der\n"
	.string "Pokémon Liga, Dragan der\l"
	.string "Drachenmeister!\p"
	.string "Von Natur aus sind Pokémon wild.\n"
	.string "Sie sind frei.\p"
	.string "Manchmal behindern sie uns.\n"
	.string "Manchmal helfen sie uns.\p"
	.string "Du trägst den Titel eines Champions.\n"
	.string "Doch lebst du noch, was er bedeutet:\l"
	.string "mit Pokémon als gleichwertigen\l"
	.string "Partnern zu kämpfen?\p"
	.string "Ein Titel schützt dich hier nicht.\n"
	.string "Zeig mir die Antwort im Kampf!$"
#else
	.string "I am the last of the POKéMON LEAGUE\n"
	.string "ELITE FOUR, DRAKE the DRAGON master!\p"
	.string "In their natural state, POKéMON are\n"
	.string "wild living things. They are free.\p"
	.string "At times, they hinder us.\n"
	.string "At times, they help us.\p"
	.string "You carry a CHAMPION's title.\n"
	.string "But do you still live what it means:\l"
	.string "to battle with POKéMON as your\l"
	.string "equal partners?\p"
	.string "A title will not protect you here.\n"
	.string "Show me your answer in battle!$"
#endif

EverGrandeCity_DrakesRoom_Text_Defeat:
#if GERMAN
	.string "Hervorragend! Das muss man sagen.$"
#else
	.string "Superb, it should be said.$"
#endif

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
#if GERMAN
	.string "Dir gebührt wahre Ehre, da du als\n"
	.string "Trainer der Pokémon so weit gekommen\l"
	.string "bist.\p"
	.string "Du weißt, was verlangt wird.\p"
	.string "Ja, ein Trainer braucht ein ehrliches\n"
	.string "Herz.\p"
	.string "Pokémon berühren das Gute im Herzen\n"
	.string "des Trainers und lernen, zwischen gut\l"
	.string "und schlecht zu unterscheiden.\p"
	.string "Sie berühren die guten Herzen der\n"
	.string "Trainer und wachsen daran.\p"
	.string "Geh! Geh weiter!\n"
	.string "Der Champ erwartet dich!$"
#else
	.string "You deserve every credit for coming\n"
	.string "this far as a TRAINER of POKéMON.\p"
	.string "You do seem to know what is needed.\p"
	.string "Yes, what a TRAINER needs is a\n"
	.string "virtuous heart.\p"
	.string "POKéMON touch the good hearts of\n"
	.string "TRAINERS and learn good from wrong.\p"
	.string "They touch the good hearts of\n"
	.string "TRAINERS and grow strong.\p"
	.string "Go! Go onwards!\n"
	.string "The CHAMPION is waiting!$"
#endif

EverGrandeCity_DrakesRoom_Text_RematchIntro:
#if GERMAN
	.string "Dragan: Du kehrst zurück, um dich\n"
	.string "erneut den Drachen zu stellen?\p"
	.string "Gut. Diesmal halte ich\n"
	.string "nichts zurück.\p"
	.string "Zeig mir die Stärke, die dich zum\n"
	.string "Champion gemacht hat!$"
#else
	.string "DRAKE: You return to face\n"
	.string "the dragons once more?\p"
	.string "Good. This time, I will\n"
	.string "hold nothing back.\p"
	.string "Show me the strength that made\n"
	.string "you a CHAMPION!$"
#endif
