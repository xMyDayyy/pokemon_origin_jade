EcruteakCity_House2_hns_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
#if GERMAN
	.string "Oh, suchst du mit deinem Pokémon-Team\n"
	.string "nach dem großen Abenteuer?\p"
	.string "Tja, aber zu einem echten Abenteuer\n"
	.string "gehört auch immer eine Schatzsuche!\p"
	.string "Habe ich nicht recht?$"
#else
	.string "Ah. You're on an adventure with\n"
	.string "your POKéMON?\p"
	.string "Well, what's an adventure without\n"
	.string "treasure hunting?\p"
	.string "Am I right, or am I right?$"
#endif

Ecruteak_Text_ItemfinderTrueSpirit:
#if GERMAN
	.string "Aha!\n"
	.string "Du weißt offensichtlich ganz genau,\l"
	.string "was Männerherzen höher schlagen lässt!\p"
	.string "Du gefällst mir! Hier, nimm das mit.$"
#else
	.string "Good! You understand the true\n"
	.string "spirit of adventure.\p"
	.string "I like that! Take this with you.$"
#endif

Ecruteak_Text_ItemfinderExplanation:
#if GERMAN
	.string "Manchmal liegen Items herum, die man\n"
	.string "leicht übersieht.\p"
	.string "Setze den Detektor ein, um Items\n"
	.string "aufzuspüren, die sich in der Nähe\l"
	.string "befinden.\p"
	.string "Den exakten Fundort musst du aber\n"
	.string "selbst herausfinden.\p"
	.string "Ich hörte auch, dass in der Turmruine\n"
	.string "von Teak City Items zu finden wären.$"
#else
	.string "There are many items lying about\n"
	.string "that aren't obvious.\p"
	.string "Use ITEMFINDER to check if there\n"
	.string "is an item on the ground near you.\p"
	.string "It doesn't show the exact spot,\n"
	.string "so you'll have to look yourself.\p"
	.string "Oh yeah--I heard there are items\n"
	.string "in ECRUTEAK's BURNED TOWER.$"
#endif

Ecruteak_Text_ItemfinderToEachHisOwn:
#if GERMAN
	.string "…Na gut, wenn du meinst!$"
#else
	.string "Oh… To each his own, I suppose…$"
#endif

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	checkitem ITEM_DOWSING_MACHINE
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_AlreadyGotItemfinder
	msgbox Ecruteak_Text_ItemfinderAdventure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_GiveItemFinder
	msgbox Ecruteak_Text_ItemfinderToEachHisOwn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_GiveItemFinder::
	msgbox Ecruteak_Text_ItemfinderTrueSpirit, MSGBOX_DEFAULT
	giveitem ITEM_DOWSING_MACHINE
EcruteakCity_House2_EventScript_AlreadyGotItemfinder::
	msgbox Ecruteak_Text_ItemfinderExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
#if GERMAN
	.string "Teak City ist eine sehr alte Stadt.\n"
	.string "Viele Generationen Geschichte stehen\l"
	.string "in Büchern wie diesem.$"
#else
	.string "ECRUTEAK is a very old city.\n"
	.string "Many generations passed down\l"
	.string "their history in books like these.$"
#endif

Ecruteak_Text_HistoryBook:
#if GERMAN
	.string "Die Geschichte von Teak City…\p"
	.string "Lesen?$"
#else
	.string "HISTORY OF ECRUTEAK\p"
	.string "Want to read it?$"
#endif

Ecruteak_Text_TwoTowers:
#if GERMAN
	.string "In Teak City gab es einmal zwei Türme.\n"
	.string "Jeder der beiden diente einem von zwei\l"
	.string "fliegenden Pokémon als Landestelle.\p"
	.string "Doch dann brannte einer dieser Türme\n"
	.string "ab, und auch die Pokémon verschwanden.\l"
	.string "So steht es geschrieben.\p"
	.string "Weiterlesen?$"
#else
	.string "In ECRUTEAK, there were two towers.\p"
	.string "Each tower was the roost of\n"
	.string "powerful flying POKéMON.\p"
	.string "But one of the towers burned to\n"
	.string "the ground.\p"
	.string "The two POKéMON haven't been seen\n"
	.string "since…\p"
	.string "Keep reading?$"
#endif

Ecruteak_Text_ThreeMon:
#if GERMAN
	.string "Drei weitere Pokémon streiften damals\n"
	.string "durch die nähere Umgebung der Stadt.\p"
	.string "Die Leute aus Teak City bezeichneten\n"
	.string "sie als Reinkarnationen der Typen Blitz,\l"
	.string "Feuer und Wasser.\p"
	.string "Doch keines von ihnen konnte die\n"
	.string "überwältigende Macht, die ihnen\l"
	.string "innewohnte, bändigen.\p"
	.string "Irgendwann verschwanden sie eins nach\n"
	.string "dem anderen im hohen Gras, und der Wind\l"
	.string "trug jedes von ihnen in eine andere\l"
	.string "Richtung.\p"
	.string "So steht es geschrieben.$"
#else
	.string "ECRUTEAK was also home to three\n"
	.string "POKéMON that raced around the town.\p"
	.string "They were said to have been born\n"
	.string "of water, lightning and fire.\p"
	.string "But they could not contain their\n"
	.string "excessive power.\p"
	.string "So they say the three ran like the\n"
	.string "wind off into the grassland.$"
#endif
