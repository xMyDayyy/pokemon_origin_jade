PokemonTower_6F_Frlg_MapScripts::
	.byte 0

PokemonTower_6F_EventScript_MarowakGhost::
	lockall
	textcolor NPC_TEXT_COLOR_MON
	msgbox PokemonTower_6F_Text_BeGoneIntruders
	setwildbattle SPECIES_MAROWAK, 30
	special StartMarowakBattle
	waitstate
	goto_if_eq VAR_RESULT, FALSE, PokemonTower_6F_EventScript_DefeatedMarowakGhost  @ VAR_RESULT set by CB2_EndMarowakBattle
	applymovement LOCALID_PLAYER, PokemonTower_6F_Movement_ForcePlayerUp
	waitmovement 0
	releaseall
	end

PokemonTower_6F_EventScript_DefeatedMarowakGhost::
	message PokemonTower_6F_Text_GhostWasCubonesMother
	waitmessage
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	msgbox PokemonTower_6F_Text_MothersSpiritWasCalmed
	setvar VAR_MAP_SCENE_POKEMON_TOWER_6F, 1
	releaseall
	end

PokemonTower_6F_Movement_ForcePlayerUp::
	walk_up
	step_end

PokemonTower_6F_EventScript_Angelica::
	trainerbattle_single TRAINER_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaIntro, PokemonTower_6F_Text_AngelicaDefeat
	msgbox PokemonTower_6F_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Emilia::
	trainerbattle_single TRAINER_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaIntro, PokemonTower_6F_Text_EmiliaDefeat
	msgbox PokemonTower_6F_Text_EmiliaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Jennifer::
	trainerbattle_single TRAINER_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferIntro, PokemonTower_6F_Text_JenniferDefeat
	msgbox PokemonTower_6F_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_AngelicaIntro::
#if GERMAN
	.string "Ich... brauche...\n"
	.string "Blut...$"
#else
	.string "Give…me…\n"
	.string "blood…$"
#endif

PokemonTower_6F_Text_AngelicaDefeat::
#if GERMAN
	.string "Wo bin ich?$"
#else
	.string "Groan!$"
#endif

PokemonTower_6F_Text_AngelicaPostBattle::
#if GERMAN
	.string "Ich fühle mich so blutleer und\n"
	.string "schwach...$"
#else
	.string "I feel anemic and weak…$"
#endif

PokemonTower_6F_Text_EmiliaIntro::
#if GERMAN
	.string "Buuh... buhuhu!$"
#else
	.string "Urff…\n"
	.string "Kwaah!$"
#endif

PokemonTower_6F_Text_EmiliaDefeat::
#if GERMAN
	.string "Irgendetwas hat mich verlassen!$"
#else
	.string "Something fell out!$"
#endif

PokemonTower_6F_Text_EmiliaPostBattle::
#if GERMAN
	.string "Es war ein böser Geist, der Besitz\n"
	.string "von mir ergriffen hatte!$"
#else
	.string "My hair didn't fall out!\n"
	.string "It was a malevolent spirit!$"
#endif

PokemonTower_6F_Text_JenniferIntro::
#if GERMAN
	.string "Buh...\n"
	.string "Buh... buhuhu...$"
#else
	.string "Ke…ke…ke…\n"
	.string "ke…ke…ke!$"
#endif

PokemonTower_6F_Text_JenniferDefeat::
#if GERMAN
	.string "Buuh!$"
#else
	.string "Keee!$"
#endif

PokemonTower_6F_Text_JenniferPostBattle::
#if GERMAN
	.string "Was geht hier vor?$"
#else
	.string "What's going on here?$"
#endif

PokemonTower_6F_Text_BeGoneIntruders::
#if GERMAN
	.string "Verschwindet...\n"
	.string "Eindringlinge...$"
#else
	.string "Be gone…\n"
	.string "Intruders…$"
#endif

PokemonTower_6F_Text_GhostWasCubonesMother::
#if GERMAN
	.string "Der Geist war die rastlose Seele\n"
	.string "der Mutter eines Tragosso!$"
#else
	.string "The ghost was the restless spirit\n"
	.string "of CUBONE's mother!$"
#endif

PokemonTower_6F_Text_MothersSpiritWasCalmed::
#if GERMAN
	.string "Ihre Seele hat Frieden gefunden.\p"
	.string "Sie ist in das Jenseits eingekehrt...$"
#else
	.string "The mother's spirit was calmed.\p"
	.string "It departed to the afterlife…$"
#endif

