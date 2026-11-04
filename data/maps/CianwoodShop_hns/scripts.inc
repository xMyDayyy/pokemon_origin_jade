CianwoodShop_hns_MapScripts::
	.byte 0

CianwoodShop_EventScriptMan::
	setvar VAR_OLIVINE_CITY_STATE, 4
	giveitem ITEM_SECRET_POTION
	end

CianwoodCity_EventScript_Pharmacist::
	lock
	faceplayer
	checkitem ITEM_SECRET_POTION
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_PharmacistAfter
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, CianwoodCity_EventScript_PharmacistAfter
	msgbox CianwoodCity_Text_PharmacistGivePotion, MSGBOX_DEFAULT
	giveitem ITEM_SECRET_POTION
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 4
	release
	end

CianwoodCity_EventScript_PharmacistAfter::
	msgbox CianwoodCity_Text_PharmacistDescribePotion, MSGBOX_DEFAULT
	closemessage
	release
	end


CianwoodCity_Text_PharmacistGivePotion:
#if GERMAN
	.string "Hm? Medizin willst du von mir?\p"
	.string "Dein Pkmn-Team wirkt jetzt nicht\n"
	.string "gerade schwerverletzt oder krank auf\l"
	.string "mich… Wo drückt denn der Schuh?\p"
	.string "… … …\p"
	.string "Ach so, dann geht es hier also um das\n"
	.string "Pokémon vom Leuchtturm! Na klar!\p"
	.string "Diese Medizin sollte genau das sein,\n"
	.string "was du brauchst. Hier, nimm!$"
#else
	.string "Your POKéMON appear to be fine.\p"
	.string "Is something worrying you?\p"
	.string "…\p"
	.string "The LIGHTHOUSE POKéMON is in\n"
	.string "trouble?\p"
	.string "I got it!\p"
	.string "This ought to do the trick.$"
#endif

CianwoodCity_Text_ReceivedSecretpotion:
#if GERMAN
	.string "{PLAYER} hat den Geheimtrank\n"
	.string "erhalten!$"
#else
	.string "{PLAYER} received SECRET POTION.$"
#endif

CianwoodCity_Text_PharmacistDescribePotion:
#if GERMAN
	.string "Mein Geheimtrank ist etwas zu stark,\n"
	.string "deshalb gebe ich ihn nur im Notfall.$"
#else
	.string "My SECRET POTION is a tad too\n"
	.string "strong, so I only offer it in an\l"
	.string "emergency.$"
#endif
