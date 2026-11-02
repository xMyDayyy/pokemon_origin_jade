Route39_FarmHouse_hns_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk


	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
#if GERMAN
	.string "Unser Miltank gibt keine Milch mehr!\p"
	.string "Diese Farm ist berühmt für die Milch, die\n"
	.string "hier produziert wird. Die Leute reißen\l"
	.string "sich richtiggehend darum!\p"
	.string "Aber wenn wir dem kranken Pokémon sehr\n"
	.string "viele Sinelbeeren zu fressen geben,\l"
	.string "kommt es vielleicht wieder auf die\l"
	.string "Beine!$"
#else
	.string "My MILTANK ain't givin' me\n"
	.string "milk no more.\p"
	.string "This here FARM's got famous milk.\p"
	.string "Most everyone wants a drink.\p"
	.string "It'll give me lots o' milk if'n\n"
	.string "I feed it lots o' BERRIES,\l"
	.string "I reckon.$"
#endif

Route39_Text_FarmerMBuyMilk:
#if GERMAN
	.string "Möchtest du ein bisschen was von der\n"
	.string "berühmten Milch der Kuhmuh-Farm?\p"
	.string "Wenn du sie deinen Pokémon zu trinken\n"
	.string "gibst, werden ihre KP aufgefrischt!\p"
	.string "Eine Flasche macht nur 500 ¥!$"
#else
	.string "How'd you like my MOOMOO MILK?\p"
	.string "It's my pride and joy, there.\p"
	.string "Give it to POKéMON to restore HP!\p"
	.string "I'll give it to ya fer just\n"
	.string "¥500.$"
#endif

Route39_Text_FarmerMGotMilk:
#if GERMAN
	.string "Bitte sehr, trink aus und genieße!$"
#else
	.string "Here ya go!\n"
	.string "Drink up'n enjoy!$"
#endif

Route39_Text_FarmerMNoMoney:
#if GERMAN
	.string "Oh, dein Geld reicht leider nicht!$"
#else
	.string "Sorry, there.\n"
	.string "No cash, no sale!$"
#endif

Route39_Text_FarmerMNoRoom:
#if GERMAN
	.string "Hm, dein Beutel ist wohl schon voll.$"
#else
	.string "I reckon yer PACK's full.$"
#endif

Route39_Text_FarmerMNoSale:
#if GERMAN
	.string "Willst du wirklich keine Milch? Na gut,\n"
	.string "aber komm mal wieder, hörst du?$"
#else
	.string "You don't want it?\n"
	.string "Come again, hear?$"
#endif

Route39FarmHouse_Text_WouldYouLikeAnother:
#if GERMAN
	.string "Wie wär’s mit noch einer?$"
#else
	.string "How bout another?$"
#endif

Route39_Text_GotMilk:
#if GERMAN
	.string "{PLAYER} erhielt Kuhmuh-Milch.$"
#else
	.string "{PLAYER} got MOOMOO MILK.$"
#endif

Route39_Text_FarmerMMilking:
#if GERMAN
	.string "Hm, vielleicht sollte ich mal mit dem\n"
	.string "Melken anfangen…$"
#else
	.string "I best go do my milkin'.$"
#endif

Route39_Text_FarmerFInTrouble:
#if GERMAN
	.string "Unsere Milch wird sogar bis nach\n"
	.string "Kanto geliefert!\p"
	.string "Wenn unser Miltank keine Milch mehr\n"
	.string "gibt, haben wir also echt Probleme!$"
#else
	.string "Our milk even goes out to\n"
	.string "KANTO.\p"
	.string "So if our own MILTANK won't\n"
	.string "give us any milk, we're in trouble.$"
#endif

Route39_Text_FarmerFHealedMiltank:
#if GERMAN
	.string "Dir haben wir zu verdanken, dass unser\n"
	.string "Miltank wieder leckere Milch gibt!\p"
	.string "Hier, das ist für deine Mühen!$"
#else
	.string "You fixed our MILTANK, hon.\n"
	.string "Now it gives MOOMOO MILK again.\p"
	.string "Here's somethin' fer your trouble.$"
#endif

Route39_Text_FarmerFSnatchSpeech:
#if GERMAN
	.string "Das ist Übernahme.\p"
	.string "Eine knifflige Attacke, mit der ein\n"
	.string "Pokémon die Attacke des Gegners kurz\l"
	.string "vor dem\p"
	.string "Einsatz stiehlt.\p"
	.string "Wenn mehrere Pokémon Übernahme\n"
	.string "einsetzen, stiehlt nur das langsamste\l"
	.string "die Attacke\p"
	.string "Setz sie klug ein.\p"
	.string "Timing ist alles, mein Lieber.$"
#else
	.string "That there's SNATCH.\p"
	.string "It's a tricky move that lets\n"
	.string "a POKéMON steal a foe's move\l"
	.string "right before it's used.\p"
	.string "If more than one POKéMON use\n"
	.string "SNATCH, only the slowest one\l"
	.string "will end up stealing the move.\p"
	.string "Use it smart, hon. Timing is\n"
	.string "everything.$"
#endif
