PokemonLeague_BrunosRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume_Hns
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_BrunosRoom_OnResume_Hns::
	setvar VAR_0x8004, 2
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_BrunosRoom_EventScript_Bruno_Hns::
	lock
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 4, PokemonLeague_BrunosRoom_EventScript_BrunoDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematch
	msgbox PokemonLeague_BrunosRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_1_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_BrunosRoom_EventScript_BrunoRematchPostOBC

PokemonLeague_BrunosRoom_EventScript_BrunoRematchStandard::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_2_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematchPostOBC::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_POSTOBC_HNS, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_BrunosRoom_Text_Defeat_Hns, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 4
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoDefeated::
	msgbox PokemonLeague_BrunosRoom_Text_Defeat_Hns, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_BrunosRoom_Text_RematchBefore:
#if GERMAN
	.string "Bruno: Willkommen zurück, junger\n"
	.string "Krieger.\p"
	.string "Durch hartes Training sind wir\n"
	.string "noch stärker geworden.\p"
	.string "Mein steinharter Wille ist nun noch\n"
	.string "fester und unbeugsamer.\p"
	.string "Bist du bereit, dich einer noch größeren\n"
	.string "Prüfung zu stellen?\p"
	.string "Zeig mir die Früchte deines Trainings.\p"
	.string "Hoo hah!$"
#else
    .string "BRUNO: Welcome back, young\n"
    .string "warrior.\p"
    .string "Through rigorous training, we have\n"
    .string "grown stronger.\p"
    .string "My rock-hard will is even more firm\n"
    .string "and unyielding.\p"
    .string "Are you prepared to face an even\n"
    .string "greater challenge?\p"
    .string "Show me the results of your\n"
    .string "training.\p"
    .string "Hoo hah!$"
#endif

PokemonLeague_BrunosRoom_Text_Before:
#if GERMAN
	.string "Ich bin Bruno von den Top Vier.\p"
	.string "Ich trainiere bis ans Limit, denn ich\n"
	.string "glaube an unser Potenzial.\p"
	.string "So sind wir stark geworden.\p"
	.string "Hältst du unserer Kraft stand?\p"
	.string "Hm? Keine Angst in deinen Augen.\n"
	.string "Du wirkst entschlossen.\p"
	.string "Perfekt für den Kampf!\p"
	.string "Bereit, {PLAYER}? Du wirst dich unserer\n"
	.string "überwältigenden Macht beugen!\p"
	.string "Hoo hah!$"
#else
    .string "I am BRUNO of the ELITE FOUR.\p"
    .string "I always train to the extreme be-\n"
    .string "cause I believe in our potential.\p"
    .string "That is how we became strong.\p"
    .string "Can you withstand our power?\p"
    .string "Hm? I see no fear in you. You look\n"
    .string "determined. Perfect for battle!\p"
    .string "Ready, {PLAYER}? You will bow down\n"
    .string "to our overwhelming power!\p"
    .string "Hoo hah!$"
#endif

PokemonLeague_BrunosRoom_Text_Beaten:
#if GERMAN
	.string "Warum? Wie konnte ich nur verlieren?$"
#else
    .string "Why? How could we lose?$"
#endif

PokemonLeague_BrunosRoom_Text_Defeat_Hns:
#if GERMAN
	.string "Nach dieser Niederlage habe ich\n"
	.string "kein Recht mehr zu reden…\p"
	.string "Stell dich deiner nächsten\n"
	.string "Herausforderung!$"
#else
    .string "Having lost, I have no right to\n"
    .string "say anything…\p"
    .string "Go face your next challenge!$"
#endif
