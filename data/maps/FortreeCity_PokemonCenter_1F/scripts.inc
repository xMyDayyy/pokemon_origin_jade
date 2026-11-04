FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
#if GERMAN
	.string "Na, Kindchen, arbeitest du an einem\n"
	.string "Pokédex?\p"
	.string "Hmm… Ich an deiner Stelle würde mal die\n"
	.string "Safari-Zone auf der Route 121\l"
	.string "besuchen.$"
#else
	.string "Listen, kid, are you working\n"
	.string "on a POKéDEX?\p"
	.string "Hmm… Go to the SAFARI ZONE.\n"
	.string "That's my suggestion.$"
#endif

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
#if GERMAN
	.string "Hast du schon mal eine Statistik\n"
	.string "geTauscht?\p"
	.string "Sehr nützliche Einrichtung! Die\n"
	.string "Erfolge\l"
	.string "eines jeden Trainers werden dort ge-\l"
	.string "speichert und miteinander verglichen.\p"
	.string "Ich weiß zwar nicht, wie das passiert,\n"
	.string "aber es ist einfach irre. Und aufregend!$"
#else
	.string "Have you done anything at\n"
	.string "the RECORD CORNER?\p"
	.string "It's pretty neat. It mixes and matches\n"
	.string "the records of TRAINERS.\p"
	.string "I don't know quite how it works,\n"
	.string "but it's cool. It's exciting, even!$"
#endif

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
#if GERMAN
	.string "Hey, du hast einen PokéCom!\n"
	.string "Ich habe auch so einen.\p"
	.string "Kennst du schon das Trainer/Ruf-\n"
	.string "System des PokéComs?\p"
	.string "Wenn du das in Betrieb nimmst, kannst\n"
	.string "du jederzeit mit den registrierten\l"
	.string "Trainern sprechen.\p"
	.string "Außerdem kannst du sehen, welche\n"
	.string "Trainer erneut gegen dich antreten\l"
	.string "möchten.\p"
	.string "Ist das nicht einfach super?\n"
	.string "Das muss man Devon wirklich lassen!$"
#else
	.string "Oh, wow, you have a POKéGEAR!\n"
	.string "And it's just like mine!\p"
	.string "Do you know about POKéGEAR's\n"
	.string "MATCH CALL system?\p"
	.string "Access it, and you can chat with\n"
	.string "registered TRAINERS anytime.\p"
	.string "It also shows you which TRAINERS\n"
	.string "want a rematch with you.\p"
	.string "It's really nifty! Those DEVON guys\n"
	.string "sure know what they're doing!$"
#endif

