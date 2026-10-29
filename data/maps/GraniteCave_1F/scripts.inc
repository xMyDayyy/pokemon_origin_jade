GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
#if IS_HNS
	@ HnS: no HM Flash in Hoenn, the hiker only talks.
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_HnsHikerDark, MSGBOX_DEFAULT
	release
	end
#else
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem_unless_owned ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end
#endif

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

#if IS_HNS
GraniteCave_1F_Text_HnsHikerDark:
#if GERMAN
	.string "Hey, du!\n"
	.string "Hier ist es schrecklich dunkel.\l"
	.string "Eine Erforschung wird damit schwierig.\p"
	.string "Der Typ, der vorher schon mal hier\n"
	.string "war… Troy heißt er, glaube ich…\p"
	.string "Der ist einfach reinspaziert, als wäre\n"
	.string "es taghell.\p"
	.string "Du siehst mir aus, als könntest du das\n"
	.string "auch. Viel Glück da unten!$"
#else
	.string "Hey, you!\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who was here earlier…\n"
	.string "STEVEN, I think his name was…\p"
	.string "He walked straight in like it was\n"
	.string "broad daylight.\p"
	.string "You look like you could do the same.\n"
	.string "Good luck down there!$"
#endif
#endif

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
#if GERMAN
	.string "Hey, du!\n"
	.string "Hier ist es schrecklich dunkel.\l"
	.string "Eine Erforschung wird damit schwierig.\l"
	.string "\p"
	.string "Der Typ, der vorher schon mal hier\n"
	.string "war… Troy heißt er, glaube ich…\p"
	.string "Der weiß, wie man Blitz einsetzt, daher\n"
	.string "wird es ihm wohl gut gehen, aber…\p"
	.string "Das Motto unter uns Wanderern heißt:\n"
	.string "Jedem aus der Klemme helfen.\p"
	.string "Deshalb bekommst du dies von mir.$"
#else
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"
#endif

GraniteCave_1F_Text_ExplainFlash:
#if GERMAN
	.string "Bringe einem Pokémon die VM Blitz\n"
	.string "bei und setze sie ein.\p"
	.string "Damit wird selbst die dunkelste Höhle\n"
	.string "von Licht erfüllt.\p"
	.string "Aber um das zu können, brauchst du den\n"
	.string "Orden der Arena von Faustauhaven.$"
#else
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"
#endif

