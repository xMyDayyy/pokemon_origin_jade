Route16_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route16_EventScript_RemoveSnorlax
	end

Route16_EventScript_RemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route16_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route16_OnTransitionCyclingRoad
	end

Route16_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route16_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route16_OnWarpCyclingRoad
	.2byte 0

Route16_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route16_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route16_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route16_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 24
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_16_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route16_EventScript_FoughtSnorlax
	release
	end

Route16_EventScript_DontUsePokeFlute::
	release
	end

Route16_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route16_EventScript_SnorlaxNoPokeFlute::
	msgbox Route16_Text_MonSprawledOutInSlumber
	release
	end

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end

Route16_Text_LaoIntro::
#if GERMAN
	.string "Was willst du?$"
#else
	.string "What do you want?$"
#endif

Route16_Text_LaoDefeat::
#if GERMAN
	.string "Wage ja nicht zu lachen!$"
#else
	.string "Don't you dare laugh!$"
#endif

Route16_Text_LaoPostBattle::
#if GERMAN
	.string "Wir lungern hier herum!\n"
	.string "Wie sieht es bei dir aus?$"
#else
	.string "We like just hanging here.\n"
	.string "What's it to you?$"
#endif

Route16_Text_KojiIntro::
#if GERMAN
	.string "Du besitzt ein schönes Fahrrad!\n"
	.string "Her damit!$"
#else
	.string "Nice BIKE!\n"
	.string "Hand it over!$"
#endif

Route16_Text_KojiDefeat::
#if GERMAN
	.string "K.o.!$"
#else
	.string "Knockout!$"
#endif

Route16_Text_KojiPostBattle::
#if GERMAN
	.string "Na ja, vergiss es!\n"
	.string "Wer braucht schon ein Fahrrad?$"
#else
	.string "Forget it, who needs your BIKE!$"
#endif

Route16_Text_LukeIntro::
#if GERMAN
	.string "Lass uns spielen, Hasenfuß!$"
#else
	.string "Come out and play, little mouse!$"
#endif

Route16_Text_LukeDefeat::
#if GERMAN
	.string "Du kleine Ratte!$"
#else
	.string "You little rat!$"
#endif

Route16_Text_LukePostBattle::
#if GERMAN
	.string "Ich hasse es, zu verlieren!\n"
	.string "Mach, dass du wegkommst!$"
#else
	.string "I hate losing!\n"
	.string "Get out of my face!$"
#endif

Route16_Text_HideoIntro::
#if GERMAN
	.string "Heh! Du hast mich angerempelt!$"
#else
	.string "Hey, you just bumped me!$"
#endif

Route16_Text_HideoDefeat::
#if GERMAN
	.string "Rumms! Überrumpelt!$"
#else
	.string "Kaboom!$"
#endif

Route16_Text_HideoPostBattle::
#if GERMAN
	.string "Man kann über eine Küstenstraße von\n"
	.string "Orania City nach Fuchsania City\l"
	.string "gelangen.$"
#else
	.string "We'll always be hanging around here\n"
	.string "even if you don't like it.\p"
	.string "You can detour to VERMILION from\n"
	.string "FUCHSIA going along the coast.$"
#endif

Route16_Text_CamronIntro::
#if GERMAN
	.string "Ich bin furchtbar gemein und\n"
	.string "erfolgssüchtig!$"
#else
	.string "I'm feeling hungry and mean!\n"
	.string "I need a punching bag!$"
#endif

Route16_Text_CamronDefeat::
#if GERMAN
	.string "Nein, nein, nein!$"
#else
	.string "Bad, bad, bad!$"
#endif

Route16_Text_CamronPostBattle::
#if GERMAN
	.string "Ich mag wilde Pokémon!\n"
	.string "Sie strotzen nur so vor Kraft!$"
#else
	.string "If I'm going to have POKéMON, they\n"
	.string "may as well be ferocious.\p"
	.string "I'd use them to leave my enemies\n"
	.string "in tatters.$"
#endif

Route16_Text_RubenIntro::
#if GERMAN
	.string "Ja, sicher!\n"
	.string "Ich mache dir Platz!$"
#else
	.string "Hey, there!\n"
	.string "Let's have ourselves a good time!$"
#endif

Route16_Text_RubenDefeat::
#if GERMAN
	.string "Treibe mich nicht in den Wahnsinn!$"
#else
	.string "Don't make me mad!$"
#endif

Route16_Text_RubenPostBattle::
#if GERMAN
	.string "Ich liebe es, andere mit meinen\n"
	.string "bissigen Pokémon zu schikanieren!$"
#else
	.string "I get my kicks by harassing people\n"
	.string "with my stinking POKéMON.\p"
	.string "They're great for startling people.\n"
	.string "And, they bite, too.$"
#endif

Route16_Text_MonSprawledOutInSlumber::
#if GERMAN
	.string "Ein schlafendes Pokémon versperrt\n"
	.string "den Weg!$"
#else
	.string "A POKéMON is sprawled out in\n"
	.string "a deep and comfortable slumber.$"
#endif

Route16_Text_CyclingRoadSign::
#if GERMAN
	.string "Radweg\n"
	.string "Gute Abfahrt!$"
#else
	.string "Enjoy the slope!\n"
	.string "CYCLING ROAD$"
#endif

Route16_Text_RouteSign::
#if GERMAN
	.string "Route 16\n"
	.string "Prismania City - Fuchsania City$"
#else
	.string "ROUTE 16\n"
	.string "CELADON CITY - FUCHSIA CITY$"
#endif

Route16_Text_JedIntro::
#if GERMAN
	.string "Uwe: Unsere Liebe kennt keine Grenzen.\n"
	.string "Wir lieben uns und zeigen das!$"
#else
	.string "JED: Our love knows no bounds.\n"
	.string "We're in love and we show it!$"
#endif

Route16_Text_JedDefeat::
#if GERMAN
	.string "Uwe: Oh, nein! Meine Geliebte hat\n"
	.string "mich verlieren sehen.$"
#else
	.string "JED: Oh, no!\n"
	.string "My love has seen me as a loser!$"
#endif

Route16_Text_JedPostBattle::
#if GERMAN
	.string "Uwe: Hör zu, Lena! Du solltest dich\n"
	.string "weniger auf mich konzentrieren.$"
#else
	.string "JED: Listen, LEA.\n"
	.string "You need to focus less on me.$"
#endif

Route16_Text_JedNotEnoughMons::
#if GERMAN
	.string "Uwe: Du hast nur ein Pokémon?\n"
	.string "Gibt es in deinem Herzen keine Liebe?$"
#else
	.string "JED: You have just one POKéMON?\n"
	.string "Is there no love in your heart?$"
#endif

Route16_Text_LeaIntro::
#if GERMAN
	.string "Lena: Manchmal erschreckt es mich,\n"
	.string "wie intensiv unsere Liebe ist.$"
#else
	.string "LEA: Sometimes, the intensity of\n"
	.string "our love scares me.$"
#endif

Route16_Text_LeaDefeat::
#if GERMAN
	.string "Lena: Oh! Aber Uwe sieht auch bei\n"
	.string "einer Niederlage cool aus!$"
#else
	.string "LEA: Ohh! But JED looks cool\n"
	.string "even in a loss!$"
#endif

Route16_Text_LeaPostBattle::
#if GERMAN
	.string "Lena: Äh, es tut mir Leid.\n"
	.string "Uwe ist so cool.$"
#else
	.string "LEA: Ehehe, I'm sorry.\n"
	.string "JED is so cool.$"
#endif

Route16_Text_LeaNotEnoughMons::
#if GERMAN
	.string "Lena: Oh, du hast keine zwei Pokémon bei\n"
	.string "dir?\p"
	.string "Fühlst du dich oder fühlt sich\n"
	.string "dein Pokémon nicht einsam?$"
#else
	.string "LEA: Oh, you don't have two\n"
	.string "POKéMON with you?\p"
	.string "Doesn't it feel lonely for you or\n"
	.string "your POKéMON?$"
#endif
