Route12_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	end

Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_MonSprawledOutInSlumber::
#if GERMAN
	.string "Ein schlafendes Pokémon versperrt den\n"
	.string "Weg!$"
#else
	.string "A POKéMON is sprawled out in\n"
	.string "a deep and comfortable slumber.$"
#endif

Text_SnorlaxWokeUp::
#if GERMAN
	.string "Relaxo ist aufgewacht!\p"
	.string "Es ist brummig und greift verschlafen\n"
	.string "an!$"
#else
	.string "SNORLAX woke up!\p"
	.string "It attacked in a grumpy rage!$"
#endif

Text_SnorlaxReturnedToMountains::
#if GERMAN
	.string "Relaxo hat sich wieder beruhigt!\n"
	.string "Es gähnt und läuft in die Berge zurück!$"
#else
	.string "SNORLAX calmed down.\n"
	.string "It gave a huge yawn…\l"
	.string "And returned to the mountains.$"
#endif

Text_WantToUsePokeFlute::
#if GERMAN
	.string "Die Pokéflöte spielen?$"
#else
	.string "Want to use the POKé FLUTE?$"
#endif

Text_PlayedPokeFlute::
#if GERMAN
	.string "{PLAYER} spielt die Pokéflöte.$"
#else
	.string "{PLAYER} played the POKé FLUTE.$"
#endif

Route12_Text_NedIntro::
#if GERMAN
	.string "Cool!\n"
	.string "Mir ist etwas ins Netz gegangen!$"
#else
	.string "Yeah!\n"
	.string "I got a bite here!$"
#endif

Route12_Text_NedDefeat::
#if GERMAN
	.string "Mist!\n"
	.string "Bloß ein kleiner Fisch!$"
#else
	.string "Tch!\n"
	.string "Just a small fry…$"
#endif

Route12_Text_NedPostBattle::
#if GERMAN
	.string "Irgendwann werde ich den großen\n"
	.string "Fang machen!$"
#else
	.string "Hang on!\n"
	.string "My line's snagged!$"
#endif

Route12_Text_ChipIntro::
#if GERMAN
	.string "Nur mit der Ruhe!\n"
	.string "Als Angler muss man geduldig sein!$"
#else
	.string "Be patient.\n"
	.string "Fishing is a waiting game.$"
#endif

Route12_Text_ChipDefeat::
#if GERMAN
	.string "Der ist mir entwischt!$"
#else
	.string "That one got away!$"
#endif

Route12_Text_ChipPostBattle::
#if GERMAN
	.string "Hätte ich eine bessere Angel,\n"
	.string "würde ich bessere Pokémon fangen!$"
#else
	.string "With a better ROD, I could catch\n"
	.string "better POKéMON…$"
#endif

Route12_Text_JustinIntro::
#if GERMAN
	.string "Besitzt du einen Mondstein?$"
#else
	.string "I'm searching for a MOON STONE.\n"
	.string "Have you found one?$"
#endif

Route12_Text_JustinDefeat::
#if GERMAN
	.string "Aua!$"
#else
	.string "Oww!$"
#endif

Route12_Text_JustinPostBattle::
#if GERMAN
	.string "Wenn ich einen Mondstein hätte,\n"
	.string "könnten sich meine Pokémon\l"
	.string "weiterentwickeln!$"
#else
	.string "I could have made my POKéMON\n"
	.string "evolve with a MOON STONE.\p"
	.string "I would have won then, I bet.$"
#endif

Route12_Text_LucaIntro::
#if GERMAN
	.string "Elektrizität ist meine Stärke!$"
#else
	.string "Electricity is my specialty.\p"
	.string "I don't know a thing about POKéMON\n"
	.string "of the sea, though.$"
#endif

Route12_Text_LucaDefeat::
#if GERMAN
	.string "Stromkreis unterbrochen!$"
#else
	.string "Unplugged!$"
#endif

Route12_Text_LucaPostBattle::
#if GERMAN
	.string "Wasser leitet Elektrizität. Greife\n"
	.string "Wasser-Pokémon mit Elektrizität an!$"
#else
	.string "Water conducts electricity, so you\n"
	.string "should zap sea POKéMON.$"
#endif

Route12_Text_HankIntro::
#if GERMAN
	.string "Der Angelkönig gegen das Pokémon-\n"
	.string "Kind!$"
#else
	.string "The FISHING FOOL versus POKéMON\n"
	.string "KID!$"
#endif

Route12_Text_HankDefeat::
#if GERMAN
	.string "Das war spitze!$"
#else
	.string "Touch too much!$"
#endif

Route12_Text_HankPostBattle::
#if GERMAN
	.string "Von Pokémon verstehst du sehr viel,\n"
	.string "doch ich bin der bessere Angler!$"
#else
	.string "I guess you get to be good at\n"
	.string "what you like.\p"
	.string "Well, you beat me at POKéMON,\n"
	.string "but you can't top me at fishing.$"
#endif

Route12_Text_ElliotIntro::
#if GERMAN
	.string "Eigentlich würde ich lieber arbeiten...$"
#else
	.string "I love fishing, don't get me wrong.\p"
	.string "But it'd be best if I also had more\n"
	.string "work.$"
#endif

Route12_Text_ElliotDefeat::
#if GERMAN
	.string "Das war wahrlich kein Zuckerschlecken!$"
#else
	.string "It's not easy…$"
#endif

Route12_Text_ElliotPostBattle::
#if GERMAN
	.string "O.k., mit der Zeit gewöhnt man sich\n"
	.string "daran, zu verlieren!$"
#else
	.string "It's all right.\n"
	.string "Losing doesn't bug me anymore.$"
#endif

Route12_Text_AndrewIntro::
#if GERMAN
	.string "Man weiß nie, was der nächste Fang\n"
	.string "sein wird!$"
#else
	.string "What's catching?\p"
	.string "You never know what you could\n"
	.string "catch!$"
#endif

Route12_Text_AndrewDefeat::
#if GERMAN
	.string "Ich habe verloren!$"
#else
	.string "Lost it!$"
#endif

Route12_Text_AndrewPostBattle::
#if GERMAN
	.string "Ich fange immer Karpador. Doch\n"
	.string "sie sind so schwach!$"
#else
	.string "What, MAGIKARP?\p"
	.string "I catch them all the time, sure.\n"
	.string "But, boy are they wimpy.$"
#endif

Route12_Text_RouteSign::
#if GERMAN
	.string "Route 12\n"
	.string "Norden: Lavandia$"
#else
	.string "ROUTE 12 \n"
	.string "North to LAVENDER$"
#endif

Route12_Text_SportfishingArea::
#if GERMAN
	.string "Sportangel-Zone$"
#else
	.string "SPORTFISHING AREA$"
#endif

Route12_Text_JesIntro::
#if GERMAN
	.string "Deniz: Falls ich gewinne, mache\n"
	.string "ich Sira einen Heiratsantrag!$"
#else
	.string "JES: If I win, I'm going to\n"
	.string "propose to GIA.$"
#endif

Route12_Text_JesDefeat::
#if GERMAN
	.string "Deniz: Oh, Mist! Warum konntest du\n"
	.string "uns nicht gewinnen lassen?$"
#else
	.string "JES: Oh, please, why couldn't you\n"
	.string "let us win?$"
#endif

Route12_Text_JesPostBattle::
#if GERMAN
	.string "Deniz: Oh, Sira, meine Liebste,\n"
	.string "verzeih mir!$"
#else
	.string "JES: Oh, GIA, forgive me,\n"
	.string "my love!$"
#endif

Route12_Text_JesNotEnoughMons::
#if GERMAN
	.string "Deniz: Sira und ich werden für\n"
	.string "immer zusammen sein.\p"
	.string "Wir werden nicht kämpfen, ehe du\n"
	.string "nicht zwei Pokémon mitbringst.$"
#else
	.string "JES: GIA and I, we'll be\n"
	.string "together forever.\p"
	.string "We won't battle unless you have\n"
	.string "two POKéMON of your own.$"
#endif

Route12_Text_GiaIntro::
#if GERMAN
	.string "Sira: Heh, Deniz…\p"
	.string "wenn wir gewinnen, heiraten wir!$"
#else
	.string "GIA: Hey, JES…\p"
	.string "If we win, I'll marry you!$"
#endif

Route12_Text_GiaDefeat::
#if GERMAN
	.string "Sira: Aber warum nur?$"
#else
	.string "GIA: Oh, but why?$"
#endif

Route12_Text_GiaPostBattle::
#if GERMAN
	.string "Sira: Deniz, du Dummerchen!\n"
	.string "Du hast es vermasselt!$"
#else
	.string "GIA: JES, you silly!\n"
	.string "You ruined this!$"
#endif

Route12_Text_GiaNotEnoughMons::
#if GERMAN
	.string "Sira: Ich ertrage es nicht, ohne\n"
	.string "meinen Deniz zu kämpfen.\p"
	.string "Hast du nicht noch ein weiteres\n"
	.string "Pokémon?$"
#else
	.string "GIA: I can't bear to battle\n"
	.string "without my JES!\p"
	.string "Don't you have one more POKéMON?$"
#endif
