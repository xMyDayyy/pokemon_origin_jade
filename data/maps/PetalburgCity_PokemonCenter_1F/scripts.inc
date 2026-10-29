PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
#if IS_HNS
	release
	end
#endif
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
#if GERMAN
	.string "Der Umbau der Arena zieht sich.\p"
	.string "Meine Nachbarin sagt, der neue Leiter\n"
	.string "sei kaum aus dem Haus gekommen.$"
#else
	.string "The rebuilding of the GYM is\n"
	.string "dragging on.\p"
	.string "My neighbour says the new LEADER\n"
	.string "has hardly left his house.$"
#endif

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
#if GERMAN
	.string "Hier im Pokémon-Center kümmert man\n"
	.string "sich wirklich gut um die Pokémon.\p"
	.string "Ich komme extra aus Wiesenflur her.$"
#else
	.string "They really do take good care of\n"
	.string "POKéMON here at the CENTER.\p"
	.string "I come all the way from VERDANTURF\n"
	.string "TOWN for it.$"
#endif

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
#if GERMAN
	.string "Ich habe gehört, Prof. Birk sei am\n"
	.string "Strand mit einer fremden Person\l"
	.string "gesehen worden.\p"
	.string "Wer das wohl war?$"
#else
	.string "I heard PROF. BIRCH was seen down\n"
	.string "at the beach with a stranger.\p"
	.string "I wonder who that was?$"
#endif

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
#if GERMAN
	.string "Dein Geckarbor ist beispielsweise ein\n"
	.string "Pflanzen-Typ.\p"
	.string "Es ist stark gegenüber dem Wasser-\n"
	.string "und Boden-Typ.\p"
	.string "Aber es ist schwach gegenüber den\n"
	.string "Feuer-Pokémon.$"
#else
	.string "For example, your TREECKO\n"
	.string "is a GRASS type.\p"
	.string "It's strong against the WATER and\n"
	.string "GROUND types.\p"
	.string "But, it's weak against FIRE-type\n"
	.string "POKéMON.$"
#endif

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
#if GERMAN
	.string "Dein Flemmli ist beispielsweise ein\n"
	.string "Feuer-Typ.\p"
	.string "Es ist stark gegenüber dem Pflanzen-\n"
	.string "und Käfer-Typ.\p"
	.string "Aber es ist schwach gegenüber den\n"
	.string "Wasser-Pokémon.$"
#else
	.string "For example, your TORCHIC\n"
	.string "is a FIRE type.\p"
	.string "It's strong against the GRASS and\n"
	.string "BUG types.\p"
	.string "But, it's weak against WATER-type\n"
	.string "POKéMON.$"
#endif

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
#if GERMAN
	.string "Dein Hydropi ist beispielsweise ein\n"
	.string "Wasser-Typ.\p"
	.string "Es ist stark gegenüber dem Feuer-Typ.\p"
	.string "Aber es ist schwach gegenüber den\n"
	.string "Pflanzen- und Elektro-Pokémon.$"
#else
	.string "For example, your MUDKIP\n"
	.string "is a WATER type.\p"
	.string "It's strong against the FIRE type.\p"
	.string "But, it's weak against GRASS-type\n"
	.string "and ELECTRIC-type POKéMON.$"
#endif
