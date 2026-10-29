EverGrandeCity_GlaciasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
	.byte 0

EverGrandeCity_GlaciasRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_GlaciasRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

EverGrandeCity_GlaciasRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
	end

EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_GlaciasRoom_EventScript_Glacia::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
	@ Origin Jade: rematch team once Hoenn's league is won.
	goto_if_set FLAG_IS_HOENN_CHAMPION, EverGrandeCity_GlaciasRoom_EventScript_Rematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_Rematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	trainerbattle_rematch TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_RematchIntro, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_Text_IntroSpeech:
#if GERMAN
	.string "Willkommen. Mein Name ist Frosina\n"
	.string "von den Top Vier.\p"
	.string "Ich bin von weit her nach Hoenn gereist,\n"
	.string "um meine eisigen Talente zu trainieren.\p"
	.string "Aber bisher haben mich nur lausige\n"
	.string "Trainer mit noch lausigeren Pokémon\l"
	.string "herausgefordert.\p"
	.string "Doch von dir habe ich gehört…\n"
	.string "Champion zweier Regionen.\p"
	.string "Endlich jemand, der mich zwingen\n"
	.string "könnte, alles zu geben!$"
#else
	.string "Welcome, my name is GLACIA\n"
	.string "of the ELITE FOUR.\p"
	.string "I've traveled from afar to HOENN\n"
	.string "so that I may hone my ice skills.\p"
	.string "But all I have seen are challenges by\n"
	.string "weak TRAINERS and their POKéMON.\p"
	.string "You, though… I have heard of you.\n"
	.string "The CHAMPION of two regions.\p"
	.string "At last, someone who might force me\n"
	.string "to go all out!$"
#endif

EverGrandeCity_GlaciasRoom_Text_Defeat:
#if GERMAN
	.string "Du und deine Pokémon…\n"
	.string "Euer Zusammenhalt verbrennt alles!\p"
	.string "Diese Hitze besiegt jeden.\p"
	.string "Kein Wunder, dass mein eisiges Talent\n"
	.string "dahinschmolz und dir nicht schadete.$"
#else
	.string "You and your POKéMON…\n"
	.string "How hot your spirits burn!\p"
	.string "The all-consuming heat overwhelms.\p"
	.string "It's no surprise that my icy skills\n"
	.string "failed to harm you.$"
#endif

EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech:
#if GERMAN
	.string "Geh weiter in den nächsten Raum.\p"
	.string "Und dort wirst du die schrecklichste\n"
	.string "Seite der Pokémon Liga kennen lernen.$"
#else
	.string "Advance to the next room.\p"
	.string "And there, confirm the truly fearsome\n"
	.string "side of the POKéMON LEAGUE.$"
#endif

EverGrandeCity_GlaciasRoom_Text_RematchIntro:
#if GERMAN
	.string "Frosina: Du bist zurückgekehrt…\p"
	.string "Ich bin weit gereist, um Eis zu finden,\n"
	.string "das niemals schmilzt.\p"
	.string "Zeig mir, ob dein Kampfgeist noch\n"
	.string "genauso heiß lodert wie damals!$"
#else
	.string "GLACIA: So you have returned…\p"
	.string "I have traveled far in search of ice\n"
	.string "that never melts.\p"
	.string "Show me if your fighting spirit\n"
	.string "still burns as hot as it did!$"
#endif
