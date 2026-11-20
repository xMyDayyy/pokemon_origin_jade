VermilionCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Woman::
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
#if GERMAN
	.string "Auch wenn sie den gleichen Level haben,\n"
	.string "können die Fähigkeiten von Pokémon\l"
	.string "trotzdem verschieden sein.\p"
	.string "Das Pokémon eines Trainers ist\n"
	.string "stärker als ein wild lebendes.$"
#else
	.string "Even if they are the same level,\n"
	.string "POKéMON can have very different\l"
	.string "stats and abilities.\p"
	.string "A POKéMON raised by a TRAINER is\n"
	.string "stronger than one in the wild.$"
#endif

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
#if GERMAN
	.string "Mein Pokémon wurde vergiftet!\n"
	.string "Das Gift hat es lange nach dem Kampf\l"
	.string "besiegt!$"
#else
	.string "My POKéMON was poisoned!\n"
	.string "It fainted while we were walking!$"
#endif

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
#if GERMAN
	.string "Es stimmt, dass ein Pokémon mit\n"
	.string "einem hohen Level sehr stark ist...\p"
	.string "Allerdings haben alle Pokémon\n"
	.string "Schwächen. Die richtige Attacke kann\l"
	.string "sie leicht besiegen!\p"
	.string "Daher gibt es kein Universal-\n"
	.string "Pokémon.$"
#else
	.string "It is true that a higher-level\n"
	.string "POKéMON will be more powerful…\p"
	.string "But, all POKéMON will have weak\n"
	.string "points against specific types.\p"
	.string "So, there appears to be no\n"
	.string "universally strong POKéMON.$"
#endif

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
#if GERMAN
	.string "Der Drang, gegen jemanden noch\n"
	.string "einmal zu kämpfen…\p"
	.string "Kennst du diesen Drang auch?\n"
	.string "Bestimmt kennst du ihn!\p"
	.string "Ich wollte auch immer wieder gegen\n"
	.string "bestimmte Trainer antreten.\p"
	.string "Wenn dich ein Trainer anruft, will\n"
	.string "er vielleicht einen Rückkampf!$"
#else
	.string "The urge to battle with someone\n"
	.string "you've tangled with before…\p"
	.string "Have you ever had that urge?\n"
	.string "I'm sure you have.\p"
	.string "I wanted to battle certain people\n"
	.string "again over and over, too.\p"
	.string "When a TRAINER calls you, they\n"
	.string "might want a rematch!$"
#endif
