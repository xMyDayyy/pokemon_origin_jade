VerdanturfTown_ContestLobby_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_ContestLobby_OnTransition
	.byte 0

@ Normal Rank contest hall, as in Ruby/Sapphire. Shared scripts are in data/scripts/contest_hall.inc.

VerdanturfTown_ContestLobby_OnTransition:
	call LilycoveCity_ContestLobby_EventScript_TryShowContestReporter
	end

VerdanturfTown_ContestLobby_EventScript_ContestReceptionist::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_NORMAL
	goto ContestLobby_EventScript_ContestReceptionist
	end

VerdanturfTown_ContestLobby_EventScript_BerryBlender::
	lockall
	setvar VAR_0x8008, LOCALID_VERDANTURF_CONTEST_LOBBY_BLEND_LEADER
	setvar VAR_0x8009, 1
	goto ContestLobby_EventScript_BerryBlender
	end

VerdanturfTown_ContestLobby_EventScript_AttractGiver::
	lock
	faceplayer
	goto_if_set FLAG_HOENN_RECEIVED_TM_ATTRACT, VerdanturfTown_ContestLobby_EventScript_ReceivedAttract
	msgbox VerdanturfTown_ContestLobby_Text_TryThisMoveInContest, MSGBOX_DEFAULT
	giveitem_unless_owned ITEM_TM_ATTRACT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_HOENN_RECEIVED_TM_ATTRACT
	release
	end

VerdanturfTown_ContestLobby_EventScript_ReceivedAttract::
	msgbox VerdanturfTown_ContestLobby_Text_PokemonAttractMeSo, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_ContestLobby_EventScript_Boy1::
	msgbox VerdanturfTown_ContestLobby_Text_LookedAroundContestHall, MSGBOX_NPC
	end

VerdanturfTown_ContestLobby_EventScript_Boy2::
	msgbox VerdanturfTown_ContestLobby_Text_PickMonWorthyOfTheme, MSGBOX_NPC
	end

VerdanturfTown_ContestLobby_Text_LookedAroundContestHall:
#if GERMAN
	.string "Ich bin hineingegangen und habe mich\n"
	.string "ein bisschen in der Wettbewerbshalle\l"
	.string "umgeschaut.\p"
	.string "Wenn man da oben auf der riesigen\n"
	.string "Bühne steht… Das muss Aufregung pur\l"
	.string "sein!$"
#else
	.string "I went in through the entrance and\n"
	.string "took a look around the CONTEST hall.\p"
	.string "Getting up on that big stage…\n"
	.string "It's going to be tense!$"
#endif

VerdanturfTown_ContestLobby_Text_TryThisMoveInContest:
#if GERMAN
	.string "Oh, die Liebe zu meinen Pokémon…\n"
	.string "Diese Anziehungskraft…\p"
	.string "Hups!\n"
	.string "Das war gar nicht für deine Ohren\l"
	.string "bestimmt! Nun, wie auch immer…\p"
	.string "Wenn du an einem Wettbewerb\n"
	.string "teilnimmst, probiere mal diese\l"
	.string "Attacke aus.$"
#else
	.string "Oh, my love for POKéMON…\n"
	.string "The attraction they evoke in me…\p"
	.string "Whoops!\n"
	.string "You weren't meant to see that!\l"
	.string "Well, anyway.\p"
	.string "If you're entering a CONTEST, try this\n"
	.string "move on for size.$"
#endif

VerdanturfTown_ContestLobby_Text_PokemonAttractMeSo:
#if GERMAN
	.string "Meine Gefühle für Pokémon…\n"
	.string "Oh, Pokémon ziehen mich so an…$"
#else
	.string "My feelings for POKéMON…\n"
	.string "Oh, they attract me so…$"
#endif

VerdanturfTown_ContestLobby_Text_PickMonWorthyOfTheme:
#if GERMAN
	.string "An welchem Wettbewerb planst du\n"
	.string "teilzunehmen?\p"
	.string "Wenn du an einem Coolness-Wettbewerb\n"
	.string "teilnehmen willst, muss das Pokémon\l"
	.string "cool sein!\p"
	.string "Wähle immer das Pokémon aus, das am\n"
	.string "besten zur Kategorie des Wettbewerbs\l"
	.string "passt und die passenden Attacken\l"
	.string "kennt.\p"
	.string "Das ist das Wesentliche!$"
#else
	.string "Which CONTEST are you planning on\n"
	.string "entering?\p"
	.string "If you're entering a COOL CONTEST,\n"
	.string "a cool POKéMON has to be the one!\p"
	.string "Pick a POKéMON worthy of the CONTEST\n"
	.string "theme, and make sure it has the\l"
	.string "right set of moves to match.\p"
	.string "That's fundamental!$"
#endif
