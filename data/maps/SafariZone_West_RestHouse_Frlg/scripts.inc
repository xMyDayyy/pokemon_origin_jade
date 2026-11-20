SafariZone_West_RestHouse_Frlg_MapScripts::
	.byte 0

SafariZone_West_RestHouse_EventScript_Man::
	msgbox SafariZone_West_Text_BaitMakesMonStickAround, MSGBOX_NPC
	end

SafariZone_West_RestHouse_EventScript_Scientist::
	msgbox SafariZone_West_Text_RocksMakeMonRunButEasierCatch, MSGBOX_NPC
	end

SafariZone_West_RestHouse_EventScript_CooltrainerF::
	msgbox SafariZone_West_Text_HikedLotsDidntSeeMonIWanted, MSGBOX_NPC
	end

SafariZone_West_Text_KogaPatrolsSafariEverySoOften::
#if GERMAN
	.string "Die Safari-Zone ist riesig, nicht?\p"
	.string "Der Arenaleiter von Fuchsania City,\n"
	.string "Koga, hält hier gelegentlich Wache.\p"
	.string "Dank ihm können wir hier in Sicherheit\n"
	.string "spielen.$"
#else
	.string "The SAFARI ZONE's huge, wouldn't\n"
	.string "you say?\p"
	.string "FUCHSIA's GYM LEADER, KOGA, \n"
	.string "patrols the grounds every so often.\p"
	.string "Thanks to him, we can play here\n"
	.string "knowing that we're safe.$"
#endif

SafariZone_West_Text_RocksMakeMonRunButEasierCatch::
#if GERMAN
	.string "Wenn du Steine nach Pokémon wirfst,\n"
	.string "lassen sie sich leichter fangen, aber\l"
	.string "sie laufen auch eher weg!$"
#else
	.string "Tossing ROCKS at POKéMON might\n"
	.string "make them run, but they'll be\l"
	.string "easier to catch.$"
#endif

SafariZone_West_Text_BaitMakesMonStickAround::
#if GERMAN
	.string "Wenn du ihnen Köder zuwirfst, bleiben\n"
	.string "die Pokémon eher an einem Ort, da sie\l"
	.string "mit dem Fressen beschäftigt sind!$"
#else
	.string "Using BAIT will make POKéMON more\n"
	.string "likely to stick around if they get\l"
	.string "busy eating.$"
#endif

SafariZone_West_Text_HikedLotsDidntSeeMonIWanted::
#if GERMAN
	.string "Ich habe lange gesucht, aber keine\n"
	.string "neuen Pokémon gefunden.$"
#else
	.string "I hiked a lot, but I didn't see any\n"
	.string "POKéMON I wanted.$"
#endif

