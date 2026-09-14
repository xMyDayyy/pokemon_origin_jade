CherrygroveCity_Mart_hns_MapScripts::
	.byte 0

Cherrygrove_Pokemart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_ge VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Clerk2
	pokemart Cherrygrove_Pokemart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Cherrygrove_Pokemart_EventScript_Youngster::
	lock
	faceplayer
	msgbox Cherrygrove_Pokemart_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Bugcatcher::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Bugcatcher2
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Bugcatcher2::
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Clerk2::
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 3
Cherrygrove_Pokemart_Pokemart:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_NONE
	release
	end

Cherrygrove_Pokemart_Text_CooltrainerM:
#if GERMAN
	.string "Die Pokébälle sind leider ausverkauft.\n"
	.string "Wann wohl die neue Lieferung kommt?$"
#else
	.string "They're fresh out of POKé BALLS!\p"
	.string "When will they get more of them?$"
#endif

Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock:
#if GERMAN
	.string "Die neue Lieferung Pokébälle ist da!\n"
	.string "Jetzt kann ich wieder nach Herzenslust\l"
	.string "auf Pokémon-Jagd gehen!$"
#else
	.string "POKé BALLS are in stock!\n"
	.string "Now I can catch POKéMON!$"
#endif

Cherrygrove_Pokemart_Text_Youngster:
#if GERMAN
	.string "Die Käfer-Pokémon im hohen Gras\n"
	.string "vergiften gern, wenn man sie\l"
	.string "unterschätzt.\p"
	.string "Hier deckt sich jeder mit Gegengift\n"
	.string "ein, bevor er nach Norden geht.$"
#else
	.string "The BUG POKéMON in the tall grass\n"
	.string "like to poison anyone who\l"
	.string "underestimates them.\p"
	.string "Everyone here stocks up on ANTIDOTE\n"
	.string "before heading north.$"
#endif
