FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	lock
	setspeaker FuchsiaCity_Text_BaobaName
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	release
	end

FuchsiaCity_Text_BaobaName:
#if GERMAN
	.string "Baoba$"
#else
	.string "BAOBA$"
#endif

FuchsiaCity_Text_Baoba:
#if GERMAN
	.string "Aufseher Baoba: {PLAYER}!\p"
	.string "Ich bin Aufseher Baoba.\p"
	.string "Etwas Schreckliches ist passiert!\n"
	.string "Meine alte Safari-Zone in\l"
	.string "Fuchsania City wurde aufgekauft\l"
	.string "und wieder eröffnet!\p"
	.string "Und anscheinend gibt es neue,\n"
	.string "exotische Pokémon!\p"
	.string "Das schadet meinem Geschäft!\p"
	.string "{PLAYER}, du musst in die neue\n"
	.string "Safari-Zone gehen und ein Pokémon\l"
	.string "fangen, um es mir zu zeigen.\p"
	.string "Ich muss über diese “exotischen”\n"
	.string "Pokémon Bescheid wissen.\p"
	.string "Bitte {PLAYER}, mein Geschäft\n"
	.string "hängt von dir ab!$"
#else
	.string "WARDEN BAOBA: {PLAYER}!\p"
	.string "This is WARDEN BAOBA.\p"
	.string "Something awful has happened! My\n"
	.string "old SAFARI ZONE in FUCHSIA CITY\l"
	.string "was bought out and reopened!\p"
	.string "And apparently it has exotic new\n"
	.string "POKéMON!\p"
	.string "It's hurting my business!\p"
	.string "{PLAYER}, you must venture into\n"
	.string "the new SAFARI ZONE and catch a\l"
	.string "POKéMON to show me. I must know\l"
	.string "about these 'exotic' POKéMON.\p"
	.string "Please {PLAYER}, my business\n"
	.string "depends on you!$"
#endif

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
#if GERMAN
	.string "Einer der Top Vier war früher einmal\n"
	.string "der Arenaleiter von Fuchsania City!$"
#else
	.string "One of the ELITE FOUR used to be\n"
	.string "the LEADER of FUCHSIA's GYM.$"
#endif

FuchsiaCity_Text_PokefanM:
#if GERMAN
	.string "Die Tochter von Koga, einem der Top\n"
	.string "Vier, hat es hier bis zur Arenaleiterin\l"
	.string "gebracht!$"
#else
	.string "KOGA's daughter succeeded him as\n"
	.string "the GYM LEADER after he joined the\l"
	.string "ELITE FOUR.$"
#endif

FuchsiaCity_Text_Teacher:
#if GERMAN
	.string "Schade, dass die Safari-Zone\p"
	.string "geschlossen ist…\n"
	.string "Das ist schließlich Fuchsanias\l"
	.string "Hauptattraktion.$"
#else
	.string "The SAFARI ZONE is under new\n"
	.string "management.\p"
	.string "And it has tons of new POKéMON!$"
#endif

FuchsiaCity_Text_Sign:
#if GERMAN
	.string "Fuchsania City\p"
	.string "Sieh nur! Die Rosarote Lieblichkeit!$"
#else
	.string "FUCHSIA CITY\p"
	.string "Behold! It's Passion Pink!$"
#endif

FuchsiaCity_Text_GymSign:
#if GERMAN
	.string "Pokémon-Arena von Fuchsania City\n"
	.string "Leiterin: Janina Die giftige\l"
	.string "Ninja-Meisterin$"
#else
	.string "FUCHSIA CITY POKéMON GYM\n"
	.string "LEADER: JANINE\p"
	.string "The Poisonous Ninja Master$"
#endif

FuchsiaCity_Text_SafariZoneOfficeSign:
#if GERMAN
	.string "Hier ist eine Notiz…\p"
	.string "Safari-Zone-Büro bis auf\n"
	.string "Weiteres geschlossen.$"
#else
	.string "There's a notice here…\p"
	.string "SAFARI ZONE OFFICE is closed until\n"
	.string "further notice.$"
#endif

FuchsiaCity_Text_SafariZone:
#if GERMAN
	.string "Safari-Zone Neuer Eigentümer\n"
	.string "Devon Corp.$"
#else
	.string "SAFARI ZONE\n"
	.string "NOW OWNED BY\l"
	.string "DEVON CORP.$"
#endif

FuchsiaCity_Text_SafariZoneClosedSign:
#if GERMAN
	.string "Der Aufseher ist auf Reisen.\p"
	.string "Deshalb ist die Safari-Zone\n"
	.string "geschlossen.$"
#else
	.string "The WARDEN is traveling abroad.\p"
	.string "Therefore, the SAFARI ZONE is\n"
	.string "closed.$"
#endif

FuchsiaCity_Text_NoLitteringSign:
#if GERMAN
	.string "Keine Umweltverschmutzung!\p"
	.string "Bitte nimm deinen Müll mit.$"
#else
	.string "No littering.\p"
	.string "Please take your waste with you.$"
#endif

