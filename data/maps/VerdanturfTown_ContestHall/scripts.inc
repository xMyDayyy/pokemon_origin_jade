VerdanturfTown_ContestHall_MapScripts::
	.byte 0

@ Audience hall behind Verdanturf's contest lobby, as in Ruby/Sapphire (D-058).

VerdanturfTown_ContestHall_EventScript_Boy1::
	msgbox VerdanturfTown_ContestHall_Text_MyMonRules, MSGBOX_NPC
	end

VerdanturfTown_ContestHall_EventScript_Boy2::
	msgbox VerdanturfTown_ContestHall_Text_WhichContestYouEntering, MSGBOX_NPC
	end

VerdanturfTown_ContestHall_EventScript_LittleGirl::
	msgbox VerdanturfTown_ContestHall_Text_RaisedMonToBeCute, MSGBOX_NPC
	end

VerdanturfTown_ContestHall_EventScript_StageSign::
	msgbox VerdanturfTown_ContestHall_Text_NormalRankStage, MSGBOX_SIGN
	end

VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
#if GERMAN
	.string "An welchem Wettbewerb nimmst du teil?\n"
	.string "Möchtest du einen Rat?\p"
	.string "Bei jedem Wettbewerb, zum Beispiel\n"
	.string "einem Anmutwettbewerb, wird im ersten\l"
	.string "Durchlauf nicht nur die Anmut bewertet.\p"
	.string "Du musst Wege finden, deine Pokémon\n"
	.string "besser aufzuziehen.$"
#else
	.string "Which CONTEST are you entering?\n"
	.string "Want a piece of advice?\p"
	.string "In any CONTEST, for example, a CUTE\n"
	.string "CONTEST, I don't think they judge you\l"
	.string "only on cuteness in the first round.\p"
	.string "You need to work out ways for raising\n"
	.string "POKéMON better.$"
#endif

VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
#if GERMAN
	.string "Ich habe mein Pokémon anmutig\n"
	.string "aufgezogen.\p"
	.string "Ich habe herausgefunden, dass man mit\n"
	.string "Pokémon an einem Anmutwettbewerb\l"
	.string "teilnehmen kann!\p"
	.string "Wie gut, dass ich mein Pokémon mit so\n"
	.string "viel Liebe aufgezogen habe…$"
#else
	.string "I raised my POKéMON to be cute.\p"
	.string "I found out you can put POKéMON in\n"
	.string "a CONTEST for cuteness!\p"
	.string "I'm so glad I raised my POKéMON with\n"
	.string "loving care…$"
#endif

VerdanturfTown_ContestHall_Text_MyMonRules:
#if GERMAN
	.string "Mein Pokémon ist spitze!\p"
	.string "Es ist cool, stark und dabei schön,\n"
	.string "anmutig und klug. Einfach perfekt!\p"
	.string "Da kann ich auch gleich jeden\n"
	.string "einzelnen Wettbewerb gewinnen wollen.$"
#else
	.string "My POKéMON rules!\p"
	.string "It's cool, tough yet beautiful, cute,\n"
	.string "and smart. It's complete!\p"
	.string "I may as well go for wins in every\n"
	.string "single CONTEST.$"
#endif

VerdanturfTown_ContestHall_Text_NormalRankStage:
#if GERMAN
	.string "Pokémon Wettbewerbe\n"
	.string "Bühne für die Normal-Klasse!$"
#else
	.string "POKéMON CONTESTS\n"
	.string "NORMAL RANK STAGE!$"
#endif
