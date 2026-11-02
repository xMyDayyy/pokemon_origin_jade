FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
#if IS_HNS
	setflag FLAG_HIDE_FALLARBOR_TOWN_CONTEST_REPORTER
#endif
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
#if GERMAN
	.string "Was ist los? Was ist los?\p"
	.string "Ich habe eine zwielichtige Gestalt aus\n"
	.string "dem Labor von Prof. Kosmo flitzen\l"
	.string "sehen.$"
#else
	.string "Something's happening,\n"
	.string "and I don't like it!\p"
	.string "I've seen shady characters wandering\n"
	.string "in and out of PROF. COZMO's home…$"
#endif

FallarborTown_Text_RegionKnownForMeteors:
#if GERMAN
	.string "Diese Region ist schon seit Urzeiten\n"
	.string "für ihre Meteoritenschauer bekannt.\p"
	.string "Man sagt, Meteorfälle sei durch den\n"
	.string "Aufprall eines Meteoriten entstanden.$"
#else
	.string "This region's been known for meteors\n"
	.string "since the olden days.\p"
	.string "They say METEOR FALLS was gouged out\n"
	.string "by a falling meteorite long ago.$"
#endif

FallarborTown_Text_MyPreciousAzurill:
#if GERMAN
	.string "Schau mal! Guck doch mal!\n"
	.string "Das ist mein süßes Azurill!\p"
	.string "Es ist glatt, weich und plüschig!$"
#else
	.string "See! Take a look!\n"
	.string "This is my precious AZURILL!\p"
	.string "It's slick and smooth and plushy, too!$"
#endif

FallarborTown_Text_Azurill:
#if GERMAN
	.string "Azurill: Rooreelooo.$"
#else
	.string "AZURILL: Rooreelooo.$"
#endif

FallarborTown_Text_HaveYouChallengedFlannery:
#if GERMAN
	.string "Hast du schon Flavia, die Leiterin der\n"
	.string "Arena von Bad Lavastadt,\l"
	.string "herausgefordert?\p"
	.string "Ihr Großvater ist sehr berühmt.\n"
	.string "Er war einer der Top Vier in der Pokémon\l"
	.string "Liga.\p"
	.string "Es würde mich gar nicht wundern, wenn\n"
	.string "Flavia ebenfalls ein großer Trainer\l"
	.string "wird.$"
#else
	.string "Have you already challenged FLANNERY,\n"
	.string "the LEADER of LAVARIDGE GYM?\p"
	.string "The girl's grandfather was famous.\n"
	.string "He was one of the ELITE FOUR in the\l"
	.string "POKéMON LEAGUE at one point.\p"
	.string "It wouldn't surprise me to see FLANNERY\n"
	.string "become a great TRAINER in her own\l"
	.string "right.$"
#endif

FallarborTown_Text_BattleTentSign:
#if GERMAN
	.string "Kampfcamp Laubwechselfeld “Mögen Sich\n"
	.string "Die Besten Teams Hier Treffen!”$"
#else
	.string "BATTLE TENT FALLARBOR SITE\n"
	.string "“May the Greatest Teams Gather!”$"
#endif

FallarborTown_Text_TownSign:
#if GERMAN
	.string "Laubwechselfeld “Eine Gemeinschaft\n"
	.string "von Farmern mit kleinen Gärten.”$"
#else
	.string "FALLARBOR TOWN\n"
	.string "“A farm community with small gardens.”$"
#endif

FallarborTown_Text_MoveTutorSign:
#if GERMAN
	.string "Haus des Attacken-Helfers\n"
	.string "“Neue Attacken für deine Pokémon.”$"
#else
	.string "MOVE TUTOR'S HOUSE\n"
	.string "“New moves taught to POKéMON.”$"
#endif

