VerdanturfTown_ContestHall_MapScripts::
	.byte 0

@ Audience hall behind Verdanturf's contest lobby, as in Ruby/Sapphire.

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
	.string "Darf ich dir einen Rat geben?\p"
	.string "In jedem Wettbewerb, zum Beispiel im\n"
	.string "Wettbewerb für Anmut, bewerten sie im\l"
	.string "ersten Durchlauf nicht nur die Anmut.\p"
	.string "Du solltest daher Wege finden, deine\n"
	.string "Pokémon besser aufzuziehen.$"
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
	.string "Ich habe meine Pokémon zur Anmut\n"
	.string "erzogen.\p"
	.string "Man kann seine Pokémon an einem Wett-\n"
	.string "bewerb für Anmut teilnehmen lassen!\p"
	.string "Ich bin so froh, dass ich meine Pokémon\n"
	.string "liebevoll aufgezogen habe.$"
#else
	.string "I raised my POKéMON to be cute.\p"
	.string "I found out you can put POKéMON in\n"
	.string "a CONTEST for cuteness!\p"
	.string "I'm so glad I raised my POKéMON with\n"
	.string "loving care…$"
#endif

VerdanturfTown_ContestHall_Text_MyMonRules:
#if GERMAN
	.string "Mein Pokémon ist der Kracher!\p"
	.string "Es ist cool, stark, schön, anmutig und\n"
	.string "klug. Alles in einem!\p"
	.string "Ich werde mit ihm sämtliche\n"
	.string "Wettbewerbe gewinnen!$"
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
