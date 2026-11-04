SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
#if GERMAN
	.string "Hallo! Ich bin der Namenbewerter!\n"
	.string "Ich bin das Orakel der Namen!\p"
	.string "Ich würde mich freuen, die Kosenamen\n"
	.string "deiner Pokémon bewerten zu dürfen.$"
#else
	.string "Hi, hi! I'm the NAME RATER!\n"
	.string "I'm the fortune-teller of names!\p"
	.string "I shall be pleased to rate your\n"
	.string "POKéMON's nickname.$"
#endif

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
#if GERMAN
	.string "Für welches Pokémon soll ich den\n"
	.string "Kosenamen bewerten?$"
#else
	.string "Which POKéMON's nickname should\n"
	.string "I critique?$"
#endif

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
#if GERMAN
	.string "Hmmm… {STR_VAR_1}, nicht wahr? Da hast\n"
	.string "du aber einen schönen Namen verliehen.\p"
	.string "Aber! Was hältst du davon, wenn ich\n"
	.string "ihm einen etwas besseren Namen gebe?$"
#else
	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
	.string "quite a fine name you bestowed.\p"
	.string "But! What say you, if I were to\n"
	.string "suggest a slightly better name?$"
#endif

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
#if GERMAN
	.string "Sehr schön! Und wie soll der neue\n"
	.string "Kosename lauten?$"
#else
	.string "Ah, good. Then, what shall the new\n"
	.string "nickname be?$"
#endif

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
#if GERMAN
	.string "Fertig! Von nun an heißt dein Pokémon\n"
	.string "{STR_VAR_1}!\p"
	.string "Das ist ein besserer Name als der\n"
	.string "vorherige. Welch ein Glück für dich!$"
#else
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It is a better name than before!\n"
	.string "How fortunate for you!$"
#endif

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
#if GERMAN
	.string "Ich verstehe.\n"
	.string "Komm mich mal wieder besuchen.$"
#else
	.string "I see.\n"
	.string "Do come visit again.$"
#endif

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
#if GERMAN
	.string "Fertig! Von nun an heißt dein Pokémon\n"
	.string "{STR_VAR_1}!\p"
	.string "Eigentlich unterscheidet sich der Name\n"
	.string "nicht von dem vorherigen, und doch ist\l"
	.string "er um einiges besser! Welch ein Glück!$"
#else
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It looks no different from before,\n"
	.string "and yet, this is vastly superior!\p"
	.string "How fortunate for you!$"
#endif

SlateportCity_NameRatersHouse_Text_MagnificentName:
#if GERMAN
	.string "Hmmm… {STR_VAR_1}!\p"
	.string "Das ist ein wundervoller Kosename!\n"
	.string "Ein Name ohne Fehl und Tadel!\p"
	.string "Du tust gut daran, {STR_VAR_1} auch\n"
	.string "weiterhin liebevoll zu behandeln!$"
#else
	.string "Hmmm… {STR_VAR_1} it is!\p"
	.string "This is a magnificent nickname!\n"
	.string "It is impeccably beyond reproach!\p"
	.string "You'll do well to cherish your\n"
	.string "{STR_VAR_1} now and beyond.$"
#endif

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
#if GERMAN
	.string "Mhm, mhm…\n"
	.string "Das ist eigentlich ein Ei!$"
#else
	.string "Now, now.\n"
	.string "That is merely an EGG!$"
#endif

