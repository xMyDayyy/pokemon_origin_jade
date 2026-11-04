BlackthornCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
#if GERMAN
	.string "Tief im Inneren des fernen\n"
	.string "Indigo Plateaus befindet sich die\l"
	.string "Pokémon Liga.\p"
	.string "Die fähigsten Trainer des ganzen\n"
	.string "Landes kommen dort zusammen!$"
#else
	.string "Deep inside far-off INDIGO\n"
	.string "PLATEAU is the POKéMON LEAGUE.\p"
	.string "I hear the best trainers gather\n"
	.string "there from around the country.$"
#endif

BlackthornCity_PokemonCenter1FTwinText:
#if GERMAN
	.string "Es gibt da eine ganz bestimmte Attacke,\n"
	.string "die ich meinem Pokémon unbedingt\l"
	.string "beibringen möchte. Also suchte ich den\l"
	.string "Attacken-Verlerner auf und habe es\l"
	.string "eine VM-Attacke vergessen lassen.$"
#else
	.string "There was this move I just had\n"
	.string "to teach my POKéMON.\p"
	.string "So I got the MOVE DELETER to make\n"
	.string "it forget an HM move.$"
#endif
