BattleFrontier_PokemonCenter_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition_hns
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition_hns:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST_HNS
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse_hns::
	setvar VAR_0x800B, LOCALID_FRONTIER_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid_hns::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man_hns::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena_hns, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker_hns::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge_hns, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty_hns::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty_hns, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon_hns:
#if GERMAN
	.string "Hier war gerade jemand, der hat ein\n"
	.string "Pokémon gehabt, das ich vorher noch\p"
	.string "nie gesehen habe. Ich habe auch in der\n"
	.string "Trainerschule nichts darüber gelernt.\p"
	.string "Wo findet man wohl so ein Pokémon?$"
#else
	.string "There was someone here using a \n"
	.string "POKéMON I've never seen before.\p"
	.string "I never learned about it at\n"
	.string "TRAINER'S SCHOOL at least.\p"
	.string "I wonder where you can catch POKéMON\n"
	.string "like that.$"
#endif

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena_hns:
#if GERMAN
	.string "Okay! Nächster Halt: Kampfring!\n"
	.string "Ich sollte mir schnell ein Pokémon aus\l"
	.string "dem Pokémon-Lagerungs-System nehmen.$"
#else
	.string "Okay! Next stop, the BATTLE ARENA!\n"
	.string "I'd better get the right POKéMON from\l"
	.string "the PC Storage System.$"
#endif

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge_hns:
#if GERMAN
	.string "Kicher… Mit diesem Schatz hier werde\n"
	.string "ich jede Herausforderung bestehen!$"
#else
	.string "Giggle… I'm going to go through every\n"
	.string "challenge with just this baby!$"
#endif

BattleFrontier_PokemonCenter_1F_Text_Skitty_hns:
#if GERMAN
	.string "Eneco: Mya myaaah!$"
#else
	.string "SKITTY: Mya myaaah!$"
#endif

