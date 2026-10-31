SlateportCity_Mart_MapScripts::
	.byte 0

SlateportCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_HARBOR_MAIL
	pokemartlistend

SlateportCity_Mart_EventScript_BlackBelt::
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
	end

SlateportCity_Mart_EventScript_Man::
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
	end

SlateportCity_Mart_Text_SomeItemsOnlyAtMart:
#if GERMAN
	.string "Der Markt bietet einige interessante\n"
	.string "Merchandising-Artikel an.\p"
	.string "Aber einige Sachen wirst du nur in\n"
	.string "einem Pokémon-Supermarkt finden.$"
#else
	.string "The MARKET does have some interesting\n"
	.string "merchandise.\p"
	.string "But there are some items you can only\n"
	.string "get at a POKéMON MART.$"
#endif

SlateportCity_Mart_Text_GreatBallIsBetter:
#if GERMAN
	.string "Ein Hyperball fängt besser als ein\n"
	.string "Superball…\p"
	.string "Aber was erzähle ich das ausgerechnet\n"
	.string "dir? Du siehst aus wie ein Profi!\p"
	.string "Eigentlich könntest du MIR ein paar\n"
	.string "Fangtipps geben…$"
#else
	.string "An ULTRA BALL beats a GREAT BALL\n"
	.string "at catching POKéMON…\p"
	.string "But who am I telling? You look\n"
	.string "like a real pro!\p"
	.string "Really, you could be giving ME\n"
	.string "some catching tips…$"
#endif

