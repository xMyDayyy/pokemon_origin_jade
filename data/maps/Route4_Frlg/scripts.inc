Route4_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	.byte 0

@ Flugpunkt bereits beim Betreten der Route freischalten, nicht erst
@ beim Betreten des Pokemon-Centers.
Route4_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	end

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
