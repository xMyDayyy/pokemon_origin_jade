MauvilleCity_Mart_MapScripts::
	.byte 0

MauvilleCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MauvilleCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_SHINY_STONE
	pokemartlistend

MauvilleCity_Mart_EventScript_ExpertM::
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_Man::
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
	end

MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats:
#if GERMAN
	.string "Es gibt Items, die den Status eines\n"
	.string "Pokémon kurzzeitig erhöhen.\p"
	.string "Ich weiß, dass man X-Angriff und\n"
	.string "X-Abwehr im Kampf einsetzen kann…\p"
	.string "Ich glaube, es gibt aber auch noch\n"
	.string "andere.$"
#else
	.string "There are items that temporarily\n"
	.string "elevate the stats of POKéMON.\p"
	.string "The ones I know you use in battle\n"
	.string "are X ATTACK and X DEFEND…\p"
	.string "I do believe that there are others\n"
	.string "like them.$"
#endif

MauvilleCity_Mart_Text_DecisionsDetermineBattle:
#if GERMAN
	.string "Setze eine bestimmte Attacke ein,\n"
	.string "oder stattdessen ein Item…\p"
	.string "Ich glaube, die Entscheidungen des\n"
	.string "Trainers bestimmen, wie ein Kampf\l"
	.string "verläuft.$"
#else
	.string "Use a certain move, or use an item\n"
	.string "instead…\p"
	.string "The TRAINER's decisions determine how\n"
	.string "battles turn out, I think.$"
#endif

