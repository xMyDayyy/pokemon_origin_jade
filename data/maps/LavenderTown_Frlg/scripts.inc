LavenderTown_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_BlockedHouse::
	msgbox LavenderTown_Text_BlockedHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_DoYouBelieveInGhosts::
#if GERMAN
	.string "Glaubst du an Geister?$"
#else
	.string "Do you believe in ghosts?$"
#endif

LavenderTown_Text_SoThereAreBelievers::
#if GERMAN
	.string "Echt?\n"
	.string "Hätte ich nicht gedacht!$"
#else
	.string "Really?\n"
	.string "So there are believers…$"
#endif

LavenderTown_Text_JustImaginingWhiteHand::
#if GERMAN
	.string "Hahaha, natürlich nicht!\p"
	.string "Und diese weiße Hand da auf deiner\n"
	.string "Schulter ist natürlich nicht echt!$"
#else
	.string "Hahaha, I guess not.\p"
	.string "That white hand on your shoulder…\n"
	.string "I'm just imagining it.$"
#endif

LavenderTown_Text_TownKnownAsMonGraveSite::
#if GERMAN
	.string "Diese Stadt ist als Ruhestätte für\n"
	.string "Pokémon bekannt.\p"
	.string "Im Pokémon-Turm werden Andachten\n"
	.string "gehalten.$"
#else
	.string "This town is known as the grave\n"
	.string "site of POKéMON.\p"
	.string "Memorial services are held in\n"
	.string "POKéMON TOWER.$"
#endif

LavenderTown_Text_GhostsAppearedInTower::
#if GERMAN
	.string "Geister spuken im Pokémon-Turm.\p"
	.string "Ich glaube, das sind die Geister jener\n"
	.string "Pokémon, die das Team Rocket auf dem\l"
	.string "Gewissen hat!$"
#else
	.string "Ghosts appeared in POKéMON TOWER.\p"
	.string "I think they're the spirits of\n"
	.string "POKéMON that the ROCKETS killed.$"
#endif

LavenderTown_Text_TownSign::
#if GERMAN
	.string "Lavandia\n"
	.string "Die edle, violette Stadt!$"
#else
	.string "LAVENDER TOWN\n"
	.string "The Noble Purple Town$"
#endif

LavenderTown_Text_BlockedHouse::
#if GERMAN
	.string "Geschlossen!\n"
	.string "Dieses Haus ist verflucht!$"
#else
	.string "Closed!\n"
	.string "This House is haunted!$"
#endif

LavenderTown_Text_SilphScopeNotice::
#if GERMAN
	.string "Silph Scope!\n"
	.string "Macht das Unsichtbare sichtbar!\p"
	.string "Silph Co.$"
#else
	.string "New SILPH SCOPE!\n"
	.string "Make the Invisible Plain to See!\p"
	.string "SILPH CO.$"
#endif

LavenderTown_Text_VolunteerPokemonHouse::
#if GERMAN
	.string "Lavandia \n"
	.string "Pokémon-Haus$"
#else
	.string "LAVENDER VOLUNTEER\n"
	.string "POKéMON HOUSE$"
#endif

LavenderTown_Text_PokemonTowerSign::
#if GERMAN
	.string "Mögen die Seelen der Pokémon im\n"
	.string "Pokémon-Turm in Frieden ruhen!$"
#else
	.string "POKéMON TOWER\n"
	.string "Becalm the Spirits of POKéMON$"
#endif

