PokemonLeague_KarensRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_1_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_KarensRoom_EventScript_KarenRematchPostOBC

PokemonLeague_KarensRoom_EventScript_KarenRematchStandard::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_2_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematchPostOBC::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_POSTOBC_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
#if GERMAN
	.string "Melanie: Ah, du bist wieder hier.\p"
	.string "Ich vertraue darauf, dass du\n"
	.string "meinen Glauben nicht vergessen hast:\p"
	.string "Wahre Stärke entsteht aus dem\n"
	.string "Vertrauen zu den eigenen Pokémon.\p"
	.string "Seit unserem letzten Treffen hat sich\n"
	.string "meine Bindung zu meinen Pokémon weiter\l"
	.string "vertieft.\p"
	.string "Bist du bereit, einem Team\n"
	.string "gegenüberzustehen, vereint durch ein\l"
	.string "unzerbrechliches Band?\p"
	.string "Zeige mir die Kraft der Bindung\n"
	.string "mit deinen Pokémon.$"
#else
    .string "KAREN: Ah, it's you again.\p"
    .string "I trust you haven't forgotten\n"
    .string "my belief:\p"
    .string "True strength arises from trust\n"
    .string "in one's POKéMON.\p"
    .string "Since our last encounter, my\n"
    .string "bond with my POKéMON has\l"
    .string "deepened further.\p"
    .string "Are you ready to face a team\n"
    .string "united by an unbreakable bond?\p"
    .string "Show me the power of the bond\n"
    .string "with your POKéMON.$"
#endif

PokemonLeague_KarensRoom_Text_Before:
#if GERMAN
	.string "Ich bin Melanie von der Top Vier.\p"
	.string "Du bist {PLAYER}? Wie amüsant.\p"
	.string "Ich liebe Unlicht-Pokémon.\p"
	.string "Ihr wildes, hartes Image finde ich so\n"
	.string "faszinierend. Und sie sind so stark.\p"
	.string "Denkst du, du kannst sie besiegen?\n"
	.string "Versuche mich einfach zu unterhalten.\p"
	.string "Los geht’s.$"
#else
    .string "I am KAREN of the ELITE FOUR.\p"
    .string "You're {PLAYER}? How amusing.\p"
    .string "I love DARK-type POKéMON.\p"
    .string "I find their wild, tough image\n"
    .string "to be so appealing. And they're\l"
    .string "so strong.\p"
    .string "Think you can take them?\n"
    .string "Just try to entertain me.\p"
    .string "Let's go.$"
#endif

PokemonLeague_KarensRoom_Text_Beaten:
#if GERMAN
	.string "Hm, du bist gut. Das gefällt mir an einem\n"
	.string "Trainer.$"
#else
    .string "Well, aren't you good. I like that\n"
    .string "in a trainer.$"
#endif

PokemonLeague_KarensRoom_Text_Defeat:
#if GERMAN
	.string "Starke Pokémon.\p"
	.string "Schwache Pokémon.\p"
	.string "Das ist nur die egoistische\n"
	.string "Wahrnehmung der Menschen.\p"
	.string "Wirklich geschickte Trainer sollten\n"
	.string "versuchen, mit ihren Favoriten zu\l"
	.string "gewinnen.\p"
	.string "Dein Stil gefällt mir. Du verstehst,\n"
	.string "was wichtig ist.\p"
	.string "Mach weiter, der Champion wartet.$"
#else
    .string "Strong POKéMON.\p"
    .string "Weak POKéMON.\p"
    .string "That is only the selfish\n"
    .string "perception of people.\p"
    .string "Truly skilled trainers should\n"
    .string "try to win with their favorites.\p"
    .string "I like your style. You understand\n"
    .string "what's important.\p"
    .string "Go on--the CHAMPION is waiting.$"
#endif

