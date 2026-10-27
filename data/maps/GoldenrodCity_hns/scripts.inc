GoldenrodCity_hns_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Trigger:: @flagheap
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
	setflag FLAG_VISITED_GOLDENROD_CITY
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_BILL
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2

	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_GOT_RETURN
	clearflag FLAG_GOT_FRUSTRATION
	clearflag FLAG_RECEIVED_BIKE
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
	clearflag FLAG_GOT_EEVEE
	clearflag FLAG_SYS_PC_BILL
	clearflag FLAG_RETURNED_MACHINE_PART
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	clearflag FLAG_GOLDENROD_MACHOKE_1
	clearflag FLAG_GOLDENROD_MACHOKE_2
	clearflag FLAG_GOLDENROD_MACHOKE_3
	clearflag FLAG_COMPLETED_SWITCHES
	@ Origin Jade: FLAG_ENABLE_RADIO stays set (radio card from Viridian).
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	clearflag FLAG_GOT_SUNNY_DAY
	clearflag FLAG_HIDE_RADIOTOWER_GATE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
	clearflag FLAG_GOT_QUICK_CLAW
	clearflag FLAG_GOT_MAGNET

	setvar VAR_BUG_CONTEST_STATE, 0
	setvar VAR_KENYA, 0
	setvar VAR_LUGIA_OR_HOOH, 0
	setvar VAR_TRAIN, 0
	setvar VAR_ELEVATOR, 0
	setvar VAR_GOLDENROD_CITY_STATE, 1
	release
	end

GoldenrodCity_Trigger_Music::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadenewbgm MUS_HG_ROCKET_TAKEOVER
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Trigger_Music2::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	fadedefaultbgm
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Trigger_MusicNotYet::
	special ShowMapNamePopup
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Elm_Togepi_Call::
	lock
	setspeaker GoldenrodCity_Text_ElmName
	pokenavcall GoldenrodCity_Text_ElmCall
	waitmessage
	delay 30
	release
	return

GoldenrodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_CooltrainerFCleared::
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROCKET_SCOUT
	faceplayer
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_Rocket1::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket2::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket3::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket4::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket5::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket6::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker2::
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_Mime::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_Beauty:
#if GERMAN
	.string "Das ist die Dukatia City Arena!\p"
	.string "Unsere Leiterin Bianka ist gerade nicht\n"
	.string "da. Sie könnte im Radioturm sein.$"
#else
	.string "This is the GOLDENROD GYM!\p"
	.string "Our leader WHITNEY is not here\n"
	.string "right now. She might be at the\l"
	.string "RADIO TOWER.$"
#endif

GoldenrodCity_Text_Woman:
#if GERMAN
	.string "Ich habe früher in Biankas Arena\n"
	.string "trainiert, aber ihr ständiges Weinen\l"
	.string "macht mir Kopfschmerzen.$"
#else
	.string "I used to train in WHITNEY's GYM,\n"
	.string "but all her crying gave me a\l"
	.string "headache.$"
#endif

GoldenrodCity_Text_HikerDay:
#if GERMAN
	.string "Als ich in die Spielhalle ging, war es\n"
	.string "Nacht… Wie lange war ich dort drin?!$"
#else
	.string "When I went into the GAME CORNER\n"
	.string "it was night time... How long was I\l"
	.string "in there?!$"
#endif

GoldenrodCity_Text_HikerNight:
#if GERMAN
	.string "Als ich in die Spielhalle ging, war es\n"
	.string "Tag… Wie lange war ich dort drin?!$"
#else
	.string "When I went into the GAME CORNER\n"
	.string "it was day time... How long was I\l"
	.string "in there?!$"
#endif

GoldenrodCity_Text_Snubbull:
#if GERMAN
	.string "Snubbull: Snuuubuuuull!$"
#else
	.string "SNUBBULL: SNUUUBUUUULL!$"
#endif

GoldenrodCity_Text_MrMime:
	.string "............................$"

GoldenrodCity_Text_ElmName:
#if GERMAN
	.string "Lind$"
#else
	.string "PROF.ELM$"
#endif

GoldenrodCity_Text_ElmCall:
#if GERMAN
	.string "Lind: Hallo, {PLAYER}? Ist das Ei\n"
	.string "schon geschlüpft?\p"
	.string "Falls das passiert, vergiss\n"
	.string "nicht, es zum Labor zu bringen.\p"
	.string "Ich muss es untersuchen!$"
#else
	.string "PROF.ELM: Hello, {PLAYER}? Has\n"
	.string "that EGG hatched yet?\p"
	.string "Once it hatches, don't forget to\n"
	.string "bring it by the lab! I need to\l"
	.string "see it!$"
#endif

GoldenrodCity_Text_PokefanM:
#if GERMAN
	.string "Dieser hochmoderne Radiosender wurde\n"
	.string "aus einem alten einsturzgefährdeten\l"
	.string "Turm gebaut, der hier einmal stand.$"
#else
	.string "They built the new RADIO TOWER\n"
	.string "to replace the old creaky one.$"
#endif

GoldenrodCity_Text_Youngster1:
#if GERMAN
	.string "Hier soll es irgendwo einen neuen\n"
	.string "Fahrradladen geben. Aber wo bloß?\p"
	.string "Ich finde ihn einfach nicht…$"
#else
	.string "I know there's a new BIKE SHOP,\n"
	.string "but I can't find it anywhere.$"
#endif

GoldenrodCity_Text_CooltrainerF1:
#if GERMAN
	.string "Hat sich dieser Mann in Schwarz etwa\n"
	.string "als Mitglied von Team Rocket verkleidet?\l"
	.string "Was ist das denn für ein Widerling?$"
#else
	.string "Is that man in black dressed up\n"
	.string "like a TEAM ROCKET member?\p"
	.string "How silly!$"
#endif

GoldenrodCity_Text_CooltrainerF1_Cleared:
#if GERMAN
	.string "Dann gehörte dieser Mann in Schwarz\n"
	.string "also wirklich zu Team Rocket?\l"
	.string "Ich kann es immer noch nicht glauben!$"
#else
	.string "Was that man in black really part\n"
	.string "of TEAM ROCKET? I can't believe it!$"
#endif

GoldenrodCity_Text_CooltrainerF2:
#if GERMAN
	.string "Der Radioturm in Dukatia City ist ein\n"
	.string "Wahrzeichen.\p"
	.string "Zurzeit läuft gerade eine\n"
	.string "Werbekampagne.\p"
	.string "Sie können deinen Com modifizieren, so\n"
	.string "dass er auch als Radio\p"
	.string "verwendet werden kann.$"
#else
	.string "The RADIO TOWER in GOLDENROD CITY\n"
	.string "is quite the landmark.\p"
	.string "They're running a campaign now.\p"
	.string "They'll give you a shiny new\n"
	.string "RADIO if you can pass their quiz.$"
#endif

GoldenrodCity_Text_CooltrainerF2_GotCard:
#if GERMAN
	.string "Oh, dein PokéCom ist auch ein\n"
	.string "Radio!$"
#else
	.string "Oh, your POKéGEAR already works\n"
	.string "as a radio!$"
#endif

GoldenrodCity_Text_Youngster2:
#if GERMAN
	.string "E-he-he-he…\p"
	.string "Ich habe Ärger bekommen, weil ich im\n"
	.string "Keller des Kaufhauses gespielt habe.$"
#else
	.string "E-he-he-he…\p"
	.string "I got in trouble for playing in\n"
	.string "the DEPT.STORE basement.$"
#endif

GoldenrodCity_Text_Lass:
#if GERMAN
	.string "Der Mann in diesem Haus bewertet deine\n"
	.string "Pokémon-Namen.\p"
	.string "Er kann deine Pokémon auch umbenennen.$"
#else
	.string "That man inside rates your\n"
	.string "POKéMON nicknames.\p"
	.string "He can even rename them.$"
#endif

GoldenrodCity_Text_Gramps:
#if GERMAN
	.string "Wow! Das ist eine große Stadt. Ich\p"
	.string "finde mich noch gar nicht zurecht.$"
#else
	.string "Whew! This town is so big,\n"
	.string "I can't find anything at all.$"
#endif

GoldenrodCity_Text_RocketScout1:
#if GERMAN
	.string "Das ist also der Radioturm…$"
#else
	.string "So this is the RADIO TOWER…$"
#endif

GoldenrodCity_Text_RocketScout2:
#if GERMAN
	.string "Was willst du, Nervensäge? Hau ab!$"
#else
	.string "What do you want, pest?\n"
	.string "Scram already!$"
#endif

GoldenrodCity_Text_Rocket1:
#if GERMAN
	.string "Aus dem Weg! Verschwinde!$"
#else
	.string "Stay out of the way!\n"
	.string "Beat it, kid!$"
#endif

GoldenrodCity_Text_Rocket2:
#if GERMAN
	.string "Wir haben den Radioturm besetzt, um…\p"
	.string "Moment mal! Das geht ein Kind wie dich\n"
	.string "doch gar nichts an!$"
#else
	.string "Take over the RADIO TOWER…\p"
	.string "What? It's none of your business!$"
#endif

GoldenrodCity_Text_Rocket3:
#if GERMAN
	.string "Pokémon? Sie sind nicht mehr als\p"
	.string "Werkzeuge zum Geldscheffeln!$"
#else
	.string "POKéMON? They're just tools\n"
	.string "we use to make money!$"
#endif

GoldenrodCity_Text_Rocket4:
#if GERMAN
	.string "Bald geht unser Traum in Erfüllung…\n"
	.string "Es war ein steiniger Weg bis hierher…$"
#else
	.string "Our dream will soon come true…\p"
	.string "It was a long, hard struggle…$"
#endif

GoldenrodCity_Text_Rocket5:
#if GERMAN
	.string "Ich glaube, ich sehe nicht recht!\n"
	.string "Was hat denn ein Kind hier verloren?\l"
	.string "Los, verzieh dich gefälligst!$"
#else
	.string "Hey, brat! You don't belong here!\n"
	.string "Get lost already!$"
#endif

GoldenrodCity_Text_Rocket6:
#if GERMAN
	.string "Komm und werde Zeuge der Macht von\n"
	.string "Team Rocket!$"
#else
	.string "Come and taste the terror of\n"
	.string "TEAM ROCKET!$"
#endif

GoldenrodCity_Text_StationSign:
#if GERMAN
	.string "Dukatia City Bahnhof$"
#else
	.string "GOLDENROD CITY STATION$"
#endif

GoldenrodCity_Text_RadioTowerSign:
#if GERMAN
	.string "Dukatia City Radioturm$"
#else
	.string "GOLDENROD CITY RADIO TOWER$"
#endif

GoldenrodCity_Text_DeptStoreSign:
#if GERMAN
	.string "Große Auswahl an Pokémon-Artikeln!\p"
	.string "Dukatia City Kaufhaus$"
#else
	.string "Full Selection of POKéMON Goods!\p"
	.string "GOLDENROD CITY DEPT.STORE$"
#endif

GoldenrodCity_Text_GymSign:
#if GERMAN
	.string "Pokémon-Arena von Dukatia City\n"
	.string "Leiterin: Bianka Ein Mädchen so scharf\l"
	.string "wie Sprengstoff!$"
#else
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "The Incredibly Pretty Girl!$"
#endif

GoldenrodCity_Text_CitySign:
#if GERMAN
	.string "Dukatia City\p"
	.string "Die festliche\n"
	.string "Stadt mit opulentem Charme$"
#else
	.string "GOLDENROD CITY\p"
	.string "The Festive City of Opulent Charm$"
#endif

GoldenrodCity_Text_BikeShopSign:
#if GERMAN
	.string "Die Welt ist ein Radweg! Fahrradladen$"
#else
	.string "The World is a Cycle Path!\n"
	.string "BIKE SHOP$"
#endif

GoldenrodCity_Text_GameCornerSign:
#if GERMAN
	.string "Dein Spielplatz!\p"
	.string "Dukatia City Spielhalle$"
#else
	.string "Your Playground!\p"
	.string "GOLDENROD CITY GAME CORNER$"
#endif

GoldenrodCity_Text_NameRaterSign:
#if GERMAN
	.string "Namenbewerter\p"
	.string "Hier erhältst du eine ehrliche\n"
	.string "Einschätzung deiner Spitznamen.$"
#else
	.string "NAME RATER\p"
	.string "Get Your POKéMON Nicknames Rated$"
#endif

GoldenrodCity_Text_UndergroundNorthSign:
#if GERMAN
	.string "Untergrundeingang$"
#else
	.string "UNDERGROUND ENTRANCE$"
#endif

GoldenrodCity_Text_UndergroundSouthSign:
#if GERMAN
	.string "Untergrundeingang$"
#else
	.string "UNDERGROUND ENTRANCE$"
#endif


GoldenrodCity_Text_FlowerShopSign:
#if GERMAN
	.string "Blühender Blumenladen$"
#else
	.string "Blooming Beautiful FLOWER SHOP$"
#endif

GoldenrodCity_Text_MoveTutorAsk:
#if GERMAN
	.string "Ich kann deinen Pokémon ein paar\n"
	.string "erstaunliche Attacken beibringen!\p"
	.string "Soll ich eine lehren?$"
#else
	.string "I can teach your POKéMON some\n"
	.string "amazing moves!\p"
	.string "Should I teach one?$"
#endif

GoldenrodCity_Text_MoveTutorCost:
#if GERMAN
	.string "A-aber…$"
#else
	.string "It'll cost you 1000 coins.\n"
	.string "Okay?$"
#endif

GoldenrodCity_Text_MoveTutorDecline:
#if GERMAN
	.string "Ohhh… Aber diese Attacken sind\n"
	.string "doch richtig gut!$"
#else
	.string "Aww… But these moves are great!$"
#endif

GoldenrodCity_Text_MoveTutorWhich:
#if GERMAN
	.string "A-aber…$"
#else
	.string "Wahahah! You won't regret it!\p"
	.string "Which move should I teach?$"
#endif

GoldenrodCity_Text_MoveTutorNoCash:
#if GERMAN
	.string "Hm, Mist. Ich muss noch Geld von zu\n"
	.string "Hause holen…$"
#else
	.string "Too bad. Guess I'll need to\n"
	.string "get some cash from home…$"
#endif

GoldenrodCity_Text_MoveTutorUnderstand:
#if GERMAN
	.string "A-aber…$"
#else
	.string "If you understand this move,\n"
	.string "you've made it as a trainer.$"
#endif

GoldenrodCity_Text_MoveTutorFarewell:
#if GERMAN
	.string "Wahahah! Mach’s gut, Wicht!$"
#else
	.string "Wahahah! Farewell, kid!$"
#endif

GoldenrodCity_Text_MoveTutorBut:
#if GERMAN
	.string "A-aber…$"
#else
	.string "B-but…$"
#endif

GoldenrodCity_Text_MoveTutorNotEnoughCoins:
#if GERMAN
	.string "…Du hast nicht genügend Münzen dabei…$"
#else
	.string "…You don't have enough coins…$"
#endif
