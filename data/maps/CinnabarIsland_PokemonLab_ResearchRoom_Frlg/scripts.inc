CinnabarIsland_PokemonLab_ResearchRoom_Frlg_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MetronomeTutor::
	goto EventScript_MetronomeTutor
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
	end

@ Kanto-Merge: Evoli hat in diesem Aufbau acht Entwicklungen - Blitza,
@ Aquana, Flamara, Feelinara, Folipurba, Glaziola, Psiana und Nachtara.
@ Der Vanilla-Text sprach von dreien.
CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons::
#if GERMAN
	.string "Evoli ist ein Rätsel.\p"
	.string "Je nachdem, womit man es in Berührung\n"
	.string "bringt oder wie eng die Freundschaft\l"
	.string "ist, wird ein anderes Pokémon daraus.\p"
	.string "Acht Formen kennen wir bisher.$"
#else
	.string "EEVEE is a mystery.\p"
	.string "What it becomes depends on what it\n"
	.string "touches, or how close its bond with\l"
	.string "its TRAINER has grown.\p"
	.string "We know of eight forms so far.$"
#endif

CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
#if GERMAN
	.string "Eine E-Mail ist angekommen!\p"
	.string "...\p"
	.string "Arktos, Zapdos und Lavados sind\n"
	.string "die drei legendären Vogel-Pokémon.\p"
	.string "Niemand weiß, in welcher Gegend sie\n"
	.string "leben.\p"
	.string "Wir werden als nächstes in der\n"
	.string "Höhle nahe Azuria City suchen.\p"
	.string "\n"
	.string "Von: Pokémon-Forschungsteam\p"
	.string "...$"
#else
	.string "There's an e-mail message.\p"
	.string "… … …\p"
	.string "There are three legendary bird\n"
	.string "POKéMON.\p"
	.string "They are ARTICUNO, ZAPDOS, and\n"
	.string "MOLTRES.\p"
	.string "Their whereabouts are unknown.\p"
	.string "We plan to explore the cavern\n"
	.string "close to CERULEAN.\p"
	.string "From: POKéMON RESEARCH TEAM…$"
#endif

CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
#if GERMAN
	.string "Eine Pfeife aus Bernstein!$"
#else
	.string "An amber pipe!$"
#endif

