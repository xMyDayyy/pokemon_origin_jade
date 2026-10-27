Route26_House2_hns_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end

Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
#if GERMAN
	.string "Hier steht etwas geschrieben.\p"
	.string "Lesen?$"
#else
    .string "There's something written here.\p"
    .string "Read it?$"
#endif

DayOfWeekSiblingsHouse_Text_Pokedex2:
#if GERMAN
	.string "An meine Brüder und Schwestern:\p"
	.string "Wir sind stolz darauf, Pokémon-\n"
	.string "Trainern zu dienen.\p"
	.string "Wenn ein Trainer mit dir spricht,\n"
	.string "gib ihm etwas Nützliches.\p"
	.string "Eure Monja\p"
	.string "Weiterlesen?$"
#else
    .string "To my brothers and sisters:\p"
    .string "We take pride in serving POKéMON\n"
    .string "trainers.\p"
    .string "When trainers talk to you, give\n"
    .string "them something useful.\p"
    .string "Love,\n"
    .string "MONICA\p"
    .string "Keep reading?$"
#endif

DayOfWeekSiblingsHouse_Text_Pokedex3:
#if GERMAN
	.string "Montag, Monja Route 40\p"
	.string "Dienstag, Dietlinde Route 29\p"
	.string "Mittwoch, Mitko See des Zorns\p"
	.string "Donnerstag, Donatus Route 36\p"
	.string "Freitag, Frieda Route 32\p"
	.string "Samstag, Samson Ebenholz City\p"
	.string "Sonntag, Sonnfried Route 37$"
#else
    .string "Monday, MONICA\n"
    .string "ROUTE 40\p"
    .string "Tuesday, TUSCANY\n"
    .string "ROUTE 29\p"
    .string "Wednesday, WESLEY\n"
    .string "LAKE OF RAGE\p"
    .string "Thursday, ARTHUR\n"
    .string "ROUTE 36\p"
    .string "Friday, FRIEDA\n"
    .string "ROUTE 32\p"
    .string "Saturday, SANTOS\n"
    .string "BLACKTHORN CITY\p"
    .string "Sunday, SUNNY\n"
    .string "ROUTE 37$"
#endif
