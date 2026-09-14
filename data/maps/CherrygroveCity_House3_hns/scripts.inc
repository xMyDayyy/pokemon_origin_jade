CherrygroveCity_House3_hns_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
#if GERMAN
	.string "Bei uns im Ort erzählt man sich, ein\n"
	.string "Pokémon habe sich mitten auf dem\l"
	.string "Marktplatz entwickelt.\p"
	.string "Alle sind erschrocken.$"
#else
	.string "They say around here that a POKéMON\n"
	.string "once evolved right in the middle of\l"
	.string "the market square.\p"
	.string "Everyone was startled.$"
#endif

CherrygroveCity_EvolutionHouse_Text_Lass:
#if GERMAN
	.string "Pokémon verändern sich?\p"
	.string "Ich wäre schockiert, wenn das plötzlich\n"
	.string "passieren würde!$"
#else
	.string "POKéMON change?\p"
	.string "I would be shocked if one did\n"
	.string "that!$"
#endif
