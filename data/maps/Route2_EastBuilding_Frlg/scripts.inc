.equ REQUIRED_SEEN_MONS, 10

Route2_EastBuilding_Frlg_MapScripts::
	.byte 0

Route2_EastBuilding_EventScript_Aide::
	lock
	faceplayer
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_HM05, Route2_EastBuilding_EventScript_AlreadyGotHM05
	msgbox Route2_EastBuilding_Text_GiveHM05IfSeen10Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	@ 2: aide count (all species with a species randomizer)
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_SEEN_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route2_EastBuilding_Text_GreatHereYouGo
	checkitemspace ITEM_HM05
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route2_EastBuilding_Text_ReceivedHM05FromAide, ITEM_HM05
	setflag FLAG_GOT_HM05
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_AlreadyGotHM05::
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_HM05
	return

Route2_EastBuilding_EventScript_Rocker::
	msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
	end

Route2_EastBuilding_Text_GiveHM05IfSeen10Mons::
#if GERMAN
	.string "Hallo! Erinnerst du dich?\n"
	.string "Ich bin Prof. Eichs Assistent!\p"
	.string "Wenn du mindestens 10 verschiedene\n"
	.string "Pokémon gefangen hast, habe ich ein\l"
	.string "Geschenk für dich: VM05\p"
	.string "Also, {PLAYER}, hast du 10\n"
	.string "unterschiedliche Pokémon gefangen?$"
#else
	.string "Hi! Remember me?\n"
	.string "I'm one of PROF. OAK's AIDES.\p"
	.string "If your POKéDEX has complete data\n"
	.string "on ten species, I'm supposed to\l"
	.string "give you a reward.\p"
	.string "PROF. OAK entrusted me with\n"
	.string "HM05 for you.\p"
	.string "So, {PLAYER}, let me ask you.\p"
	.string "Have you gathered data on at least\n"
	.string "ten kinds of POKéMON?$"
#endif

Route2_EastBuilding_Text_GreatHereYouGo::
#if GERMAN
	.string "Super! Du hast {STR_VAR_3} verschiedene\n"
	.string "Pokémon gefangen!\p"
	.string "Einfach klasse! Hier, das hast du\n"
	.string "dir redlich verdient!$"
#else
	.string "Great! You have caught or owned\n"
	.string "{STR_VAR_3} kinds of POKéMON!\p"
	.string "Congratulations!\n"
	.string "Here you go!$"
#endif

Route2_EastBuilding_Text_ReceivedHM05FromAide::
#if GERMAN
	.string "{PLAYER} erhält VM05!$"
#else
	.string "{PLAYER} received HM05\n"
	.string "from the AIDE.$"
#endif

Route2_EastBuilding_Text_ExplainHM05::
#if GERMAN
	.string "Die VM05 enthält die versteckte\n"
	.string "Attacke Blitz.\p"
	.string "Blitz erhellt selbst die dunkelsten\n"
	.string "Höhlen und Verliese.$"
#else
	.string "HM05 contains the hidden move\n"
	.string "FLASH.\p"
	.string "FLASH lights up even the darkest\n"
	.string "of caves and dungeons.$"
#endif

Route2_EastBuilding_Text_CanGetThroughRockTunnel::
#if GERMAN
	.string "Sobald eines deiner Pokémon Blitz\n"
	.string "erlernt hat, kannst du dich in den\l"
	.string "Felstunnel wagen!$"
#else
	.string "Once a POKéMON learns FLASH, you\n"
	.string "can get through ROCK TUNNEL.$"
#endif

