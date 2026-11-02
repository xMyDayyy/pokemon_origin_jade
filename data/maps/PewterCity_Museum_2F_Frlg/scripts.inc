PewterCity_Museum_2F_Frlg_MapScripts::
	.byte 0

PewterCity_Museum_2F_EventScript_Man::
	msgbox PewterCity_Museum_1F_Text_WhatsSpecialAboutMoonStone, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_BoughtColorTVForMoonLanding, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Scientist::
	msgbox PewterCity_Museum_1F_Text_RunningSpaceExhibitThisMonth, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_LittleGirl::
	msgbox PewterCity_Museum_1F_Text_AskedDaddyToCatchPikachu, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_BaldingMan::
	msgbox PewterCity_Museum_1F_Text_PikachuSoonIPromise, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_SpaceShuttle::
	msgbox PewterCity_Museum_1F_Text_SpaceShuttle, MSGBOX_SIGN
	end

PewterCity_Museum_2F_EventScript_MoonStone::
	msgbox PewterCity_Museum_1F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

Text_SeismicTossTeach::
#if GERMAN
	.string "Das Geheimnis des Raumes…\n"
	.string "Die Rätsel des Planeten…\p"
	.string "Es gibt so vieles, worüber wir so\n"
	.string "wenig wissen!\p"
	.string "Aber was treibt uns an, noch mehr zu\n"
	.string "hinterfragen und nicht das Handtuch zu\l"
	.string "werfen?\l"
	.string "Der einzige erlaubte Wurf…\p"
	.string "Wie wäre es mit Geowurf?\n"
	.string "Soll ich das einem Pokémon beibringen?$"
#else
	.string "The secrets of space…\n"
	.string "The mysteries of earth…\p"
	.string "There are so many things about\n"
	.string "which we know so little.\p"
	.string "But that should spur us to study\n"
	.string "harder, not toss in the towel.\p"
	.string "The only thing you should toss…\p"
	.string "Well, how about SEISMIC TOSS?\n"
	.string "Should I teach that to a POKéMON?$"
#endif

Text_SeismicTossDeclined::
#if GERMAN
	.string "So ist das also!\n"
	.string "Ich bin sicher, du kommst zurück!$"
#else
	.string "Is that so?\n"
	.string "I'm sure you'll be back for it.$"
#endif

Text_SeismicTossWhichMon::
#if GERMAN
	.string "Welches Pokémon soll die Attacke\n"
	.string "erlernen?$"
#else
	.string "Which POKéMON wants to learn\n"
	.string "SEISMIC TOSS?$"
#endif

Text_SeismicTossTaught::
#if GERMAN
	.string "Ich hoffe, du wirfst nicht das\n"
	.string "Handtuch! Mach weiter so!$"
#else
	.string "I hope you won't toss in the towel.\n"
	.string "Keep it up.$"
#endif

PewterCity_Museum_1F_Text_WhatsSpecialAboutMoonStone::
#if GERMAN
	.string "Mondstein?\p"
	.string "Was ist daran so einzigartig?$"
#else
	.string "MOON STONE, huh?\p"
	.string "What's so special about it?\n"
	.string "Looks like an ordinary rock to me.$"
#endif

PewterCity_Museum_1F_Text_BoughtColorTVForMoonLanding::
#if GERMAN
	.string "Der 20. Juli 1969!\p"
	.string "Die erste Mondlandung!\p"
	.string "Für die Fernsehübertragung hatte ich\n"
	.string "extra einen Farbfernseher gekauft!$"
#else
	.string "July 20, 1969!\p"
	.string "Humankind first set foot on the\n"
	.string "moon that day.\p"
	.string "I bought a color TV just so I\n"
	.string "could watch that news.$"
#endif

PewterCity_Museum_1F_Text_RunningSpaceExhibitThisMonth::
#if GERMAN
	.string "Momentan haben wir eine\n"
	.string "Raumfahrt-Ausstellung.$"
#else
	.string "This month, we're running a space\n"
	.string "exhibit.$"
#endif

PewterCity_Museum_1F_Text_AskedDaddyToCatchPikachu::
#if GERMAN
	.string "Ich hätte gerne ein Pikachu!\n"
	.string "Es ist so furchtbar süß!\p"
	.string "Mein Papa soll mir eines fangen!$"
#else
	.string "I want a PIKACHU!\n"
	.string "It's so cute!\p"
	.string "I asked my daddy to catch me one!$"
#endif

PewterCity_Museum_1F_Text_PikachuSoonIPromise::
#if GERMAN
	.string "Ja, ein Pikachu!\n"
	.string "Ich verspreche, ich fange eins!$"
#else
	.string "Yeah, a PIKACHU soon, I promise!$"
#endif

PewterCity_Museum_1F_Text_SpaceShuttle::
#if GERMAN
	.string "Raumfähre$"
#else
	.string "Space Shuttle$"
#endif

PewterCity_Museum_1F_Text_MeteoriteThatFellOnMtMoon::
#if GERMAN
	.string "Auf dem Mondberg gefundenes\n"
	.string "Meteoritengestein “Mondstein?”$"
#else
	.string "A meteorite that fell on MT. MOON.\n"
	.string "It is thought to be a MOON STONE.$"
#endif

