Route4_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	.byte 0

@ Unlock the fly point on entering the route.
Route4_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	call Route4_EventScript_TryShowJirachi
	end

@ Jirachi: shown once summoned at the white rock; legendary rules.
Route4_EventScript_TryShowJirachi::
	setflag FLAG_HIDE_MTMOON_JIRACHI
	goto_if_unset FLAG_SUMMONED_MTMOON_JIRACHI, Common_EventScript_NopReturn
	setvar VAR_0x8004, LEGENDARY_JIRACHI
	specialvar VAR_RESULT, IsLegendaryAvailable
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MTMOON_JIRACHI
	return

@ White rock: summons Jirachi once, at night, after the first trip to Hoenn.
Route4_EventScript_WhiteRock::
	lock
	msgbox Route4_Text_WhiteRockTouchIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_EventScript_WhiteRockRelease
	goto_if_lt VAR_HOENN_ARRIVAL_STATE, 1, Route4_EventScript_WhiteRockNoReaction
	goto_if_set FLAG_SUMMONED_MTMOON_JIRACHI, Route4_EventScript_WhiteRockNoReaction
	goto_if_set FLAG_NIGHT_POKEMON, Route4_EventScript_WhiteRockNoReaction
	msgbox Route4_Text_WhiteRockTouchNight, MSGBOX_DEFAULT
	playse SE_M_SELF_DESTRUCT
	waitse
	closemessage
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_M_GUST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	delay 60
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 30
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_M_GUST2
	waitse
	playse SE_M_EXPLOSION
	fadescreenswapbuffers FADE_TO_WHITE
	clearflag FLAG_HIDE_MTMOON_JIRACHI
	setflag FLAG_SUMMONED_MTMOON_JIRACHI
	addobject LOCALID_ROUTE4_JIRACHI
	waitse
	delay 70
	fadescreenswapbuffers FADE_FROM_WHITE
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Route4_Movement_CameraPanDown
	waitmovement 0
	applymovement2 LOCALID_ROUTE4_JIRACHI, Route4_Movement_Jirachi
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
	applymovement2 OBJ_EVENT_ID_CAMERA, Route4_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	release
	end

Route4_EventScript_WhiteRockNoReaction::
	msgbox Route4_Text_WhiteRockTouchDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_EventScript_WhiteRockRelease::
	release
	end

Route4_EventScript_Jirachi::
	lock
	faceplayer
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	msgbox Route4_Text_Jirachi, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	seteventmon SPECIES_JIRACHI, 80
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_0x8004, LEGENDARY_JIRACHI
	special RecordLegendaryBattleOutcome
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Common_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_RemoveStaticPokemon
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto Common_EventScript_LegendaryFlewAway
	end

Route4_Movement_CameraPanDown:
	walk_down
	walk_down
	step_end

Route4_Movement_CameraPanUp:
	walk_up
	walk_up
	step_end

Route4_Movement_Jirachi:
	jump_in_place_down
	jump_in_place_down
	step_end

Route4_EventScript_Unused::
	end

Route4_EventScript_Woman::
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_Text_TrippedOverGeodude::
#if GERMAN
	.string "Aua! Ich bin über ein Kleinstein\n"
	.string "gestolpert, ein Stein-Pokémon!$"
#else
	.string "Ouch! I tripped over a rocky\n"
	.string "POKéMON, GEODUDE!$"
#endif

Route4_Text_CrissyIntro::
#if GERMAN
	.string "Ich bin hier, um Pilz-Pokémon zu\n"
	.string "fangen!$"
#else
	.string "I came to MT. MOON in search of\n"
	.string "mushroom POKéMON.$"
#endif

Route4_Text_CrissyDefeat::
#if GERMAN
	.string "Ach, Pilz-Pokémon sind ja so süß!$"
#else
	.string "After all I did to catch them!$"
#endif

Route4_Text_CrissyPostBattle::
#if GERMAN
	.string "Es dürfte hier keine Pilz-Pokémon\n"
	.string "mehr geben.\p"
	.string "Ich glaube, ich habe alle gefangen.$"
#else
	.string "There might not be any more\n"
	.string "mushrooms here.\p"
	.string "I think I got them all.$"
#endif

Route4_Text_MtMoonEntrance::
#if GERMAN
	.string "Mondberg\n"
	.string "Tunneleingang$"
#else
	.string "MT. MOON\n"
	.string "Tunnel Entrance$"
#endif

Route4_Text_RouteSign::
#if GERMAN
	.string "Route 4\n"
	.string "Mondberg - Azuria City$"
#else
	.string "ROUTE 4\n"
	.string "MT. MOON - CERULEAN CITY$"
#endif

Route4_Text_WhiteRockTouchIt:
#if GERMAN
	.string "Ein seltsamer, weißer Stein.\n"
	.string "Die Farbe erinnert an den Mond.\p"
	.string "Berühren?$"
#else
	.string "An unusual white rock.\n"
	.string "The color reminds you of the moon.\p"
	.string "Touch it?$"
#endif

Route4_Text_WhiteRockTouchDay:
#if GERMAN
	.string "{PLAYER} berührt den seltsamen Stein.\n"
	.string "..........................\l"
	.string "..........................\l"
	.string "Nichts geschieht!$"
#else
	.string "{PLAYER} touched the unusual rock.\n"
	.string "..........................\l"
	.string "..........................\l"
	.string "But nothing happened.$"
#endif

Route4_Text_WhiteRockTouchNight:
#if GERMAN
	.string "{PLAYER} berührt den seltsamen Stein.\n"
	.string "..........................\l"
	.string "..........................$"
#else
	.string "{PLAYER} touched the unusual rock.\n"
	.string "..........................\l"
	.string "..........................$"
#endif

Route4_Text_Jirachi:
#if GERMAN
	.string "Jirachi: Chi!$"
#else
	.string "JIRACHI: Chi!$"
#endif

Text_MegaPunchTeach::
#if GERMAN
	.string "Ein Schlag von roher Gewalt!\p"
	.string "Mit zerstörerischer, verheerender\n"
	.string "Wirkung.\p"
	.string "Wenn es darauf ankommt, ist Megahieb\n"
	.string "die ultimative Attacke!\l"
	.string "Du stimmst zu, oder?\p"
	.string "Also!\n"
	.string "Soll ein Pokémon diese Attacke\l"
	.string "erlernen?$"
#else
	.string "A punch of roaring ferocity!\p"
	.string "Packed with destructive power!\p"
	.string "When the chips are down,\n"
	.string "MEGA PUNCH is the ultimate attack!\l"
	.string "You agree, yes?\p"
	.string "Now!\n"
	.string "Let me teach it to your POKéMON!$"
#endif

Text_MegaPunchDeclined::
#if GERMAN
	.string "Du kommst wieder, wenn du die Bedeutung\n"
	.string "von Megahieb erkannt hast.$"
#else
	.string "You'll be back when you understand\n"
	.string "the worth of MEGA PUNCH.$"
#endif

Text_MegaPunchWhichMon::
#if GERMAN
	.string "Schön!\n"
	.string "Welches Pokémon soll Megahieb\l"
	.string "erlernen?$"
#else
	.string "Fine!\n"
	.string "Which POKéMON will learn it?$"
#endif

Text_MegaPunchTaught::
#if GERMAN
	.string "Nun sind wir Freunde, was Hiebe\n"
	.string "angeht!\p"
	.string "Du solltest gehen, ehe dich der arme,\n"
	.string "fehlgeleitete Kerl, der dort drüben nur\l"
	.string "Tritte trainiert, sieht.$"
#else
	.string "Now, we are comrades in the way of\n"
	.string "punching!\p"
	.string "You should go before you're seen\n"
	.string "by the misguided fool who trains\l"
	.string "only his silly kicking over there.$"
#endif

Text_MegaKickTeach::
#if GERMAN
	.string "Ein Tritt von brutaler Energie!\p"
	.string "Mit zerstörerischer, verheerender\n"
	.string "Wirkung.\p"
	.string "Wenn es darauf ankommt, ist Megakick\n"
	.string "die ultimative Attacke!\p"
	.string "O.K.!\n"
	.string "Ich werde Megakick einem Pokémon\l"
	.string "beibringen.$"
#else
	.string "A kick of brutal ferocity!\p"
	.string "Packed with destructive power!\p"
	.string "When you get right down to it,\n"
	.string "MEGA KICK is the ultimate attack!\l"
	.string "Don't you agree?\p"
	.string "Okay!\n"
	.string "I'll teach it to your POKéMON!$"
#endif

Text_MegaKickDeclined::
#if GERMAN
	.string "Du kommst angekrochen, wenn du die\n"
	.string "wahre Bedeutung von Megakick\l"
	.string "erkennst.$"
#else
	.string "You'll come crawling back when you\n"
	.string "realize the value of MEGA KICK.$"
#endif

Text_MegaKickWhichMon::
#if GERMAN
	.string "In Ordnung!\n"
	.string "Welches Pokémon soll Megakick\l"
	.string "erlernen?$"
#else
	.string "All right!\n"
	.string "Which POKéMON wants to learn it?$"
#endif

Text_MegaKickTaught::
#if GERMAN
	.string "Nun sind wir Freunde, was Tritte\n"
	.string "angeht!\p"
	.string "Du solltest gehen, ehe dich der arme,\n"
	.string "fehlgeleitete Kerl, der dort drüben nur\l"
	.string "Hiebe trainiert, sieht.$"
#else
	.string "Now, we are soul mates in the way\n"
	.string "of kicking!\p"
	.string "You should run before you're seen\n"
	.string "by the deluded nitwit who trains\l"
	.string "only simple punching over there.$"
#endif

Route4_Text_PeopleLikeAndRespectBrock::
#if GERMAN
	.string "Oh, das ist ja der Felsorden!\n"
	.string "Du hast ihn von Rocko bekommen, oder?\l"
	.string "Rocko ist cool. Er ist nicht nur stark,\l"
	.string "sondern auch beliebt und wird\l"
	.string "respektiert.\l"
	.string "Ich möchte auch ein Arenaleiter wie er\l"
	.string "werden.$"
#else
	.string "Oh, wow, that's the BOULDERBADGE!\n"
	.string "You got it from BROCK, didn't you?\p"
	.string "BROCK is cool. He's not just tough.\n"
	.string "People like and respect him.\p"
	.string "I want to become a GYM LEADER\n"
	.string "like him.$"
#endif
