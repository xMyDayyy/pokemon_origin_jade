BattleFrontier_PokemonCenter_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
BattleFrontier_PokemonCenter_2F_EventScript_Colosseum_hns::
	call CableClub_EventScript_Colosseum
	end

BattleFrontier_PokemonCenter_2F_EventScript_TradeCenter_hns::
	call CableClub_EventScript_TradeCenter
	end

BattleFrontier_PokemonCenter_2F_EventScript_RecordCorner_hns::
	call CableClub_EventScript_RecordCorner
	end

BattleFrontier_PokemonCenter_2F_EventScript_Eusine_hns::
	msgbox BattleFrontier_PokemonCenter_2F_Text_Eusine_hns, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_2F_Text_Eusine_hns:
#if GERMAN
	.string "Eusin: Trainer aus aller Welt\n"
	.string "kommen in die Kampfzone.\p"
	.string "Vielleicht hat einer von ihnen etwas\n"
	.string "über die legendären Pokémon gehört.$"
#else
	.string "EUSINE: Trainers from all over the\n"
	.string "world come to the BATTLE FRONTIER.\p"
	.string "Maybe one of them has heard\n"
	.string "something about legendary POKéMON.$"
#endif
