CherrygroveCity_House1_hns_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
#if GERMAN
	.string "Acht Arenen hat Johto, und keine\n"
	.string "davon verschenkt einen Orden.\p"
	.string "Wer aus anderen Regionen kommt,\n"
	.string "unterschätzt sie gern.$"
#else
	.string "JOHTO has eight GYMS, and not one\n"
	.string "of them gives a BADGE away.\p"
	.string "People from other regions tend to\n"
	.string "underestimate them.$"
#endif

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
#if GERMAN
	.string "Wenn ich mal groß bin, möchte ich\n"
	.string "unbedingt Arenaleiter werden!\p"
	.string "Ich lasse meine Pokémon jetzt schon\n"
	.string "gegen die meiner Freunde antreten,\l"
	.string "damit sie stärker werden!$"
#else
	.string "When I get older, I'm going to\n"
	.string "be a GYM LEADER!\p"
	.string "I make my POKéMON battle with\n"
	.string "my friend's to make them\l"
	.string "tougher!$"
#endif
