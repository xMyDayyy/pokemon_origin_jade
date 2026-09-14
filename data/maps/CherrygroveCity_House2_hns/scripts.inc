CherrygroveCity_House2_hns_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
#if GERMAN
	.string "Als ich noch ein kleiner Junge war,\n"
	.string "war ich ein Spitzentrainer!\p"
	.string "Heute sitze ich hier und erzähle\n"
	.string "davon. So ändern sich die Zeiten.$"
#else
	.string "When I was a boy, I was a top\n"
	.string "trainer!\p"
	.string "Now I sit here and talk about it.\n"
	.string "How times change.$"
#endif
