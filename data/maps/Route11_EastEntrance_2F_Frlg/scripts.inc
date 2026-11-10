.equ REQUIRED_CAUGHT_MONS, 30

Route11_EastEntrance_2F_Frlg_MapScripts::
	.byte 0

Route11_EastEntrance_2F_EventScript_LeftBinoculars::
	lockall
	goto_if_set FLAG_WOKE_UP_ROUTE_12_SNORLAX, Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone
	msgbox Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad
	releaseall
	end

Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone::
	msgbox Route11_EastEntrance_2F_Text_WhatABreathtakingView
	releaseall
	end

Route11_EastEntrance_2F_EventScript_RightBinoculars::
	msgbox Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender, MSGBOX_SIGN
	end

Route11_EastEntrance_2F_EventScript_Turner::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_NIDORINOA
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set FLAG_DID_NINA_TRADE, Route11_EastEntrance_2F_EventScript_AlreadyTraded
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route11_EastEntrance_2F_EventScript_DeclineTrade
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route11_EastEntrance_2F_EventScript_DeclineTrade
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, Route11_EastEntrance_2F_EventScript_NotRequestedMon
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag FLAG_DID_NINA_TRADE
	release
	end

Route11_EastEntrance_2F_EventScript_DeclineTrade::
	msgbox Trade_Text_AwwOhWell
	release
	end

Route11_EastEntrance_2F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end

Route11_EastEntrance_2F_EventScript_AlreadyTraded::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end

Route11_EastEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route11_EastEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_ITEMFINDER, Route11_EastEntrance_2F_EventScript_AlreadyGotItemfinder
	msgbox Route11_EastEntrance_2F_Text_GiveItemfinderIfCaught30, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	@ 2: aide count (all species with a species randomizer)
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route11_EastEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route11_EastEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_ITEMFINDER
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route11_EastEntrance_2F_Text_ReceivedItemfinderFromAide, ITEM_ITEMFINDER
	setflag FLAG_GOT_ITEMFINDER
	msgbox Route11_EastEntrance_2F_Text_ExplainItemfinder
	release
	end

Route11_EastEntrance_2F_EventScript_AlreadyGotItemfinder::
	msgbox Route11_EastEntrance_2F_Text_ExplainItemfinder
	release
	end

Route11_EastEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_ITEMFINDER
	return

Route11_EastEntrance_2F_Text_GiveItemfinderIfCaught30::
#if GERMAN
	.string "Hallo! Erinnerst du dich?\n"
	.string "Ich bin Prof. Eichs Assistent!\p"
	.string "Wenn du mindestens {STR_VAR_1}\n"
	.string "verschiedene Pokémon gefangen hast,\l"
	.string "habe ich ein Geschenk für dich:\l"
	.string "{STR_VAR_2}\p"
	.string "Also, {PLAYER}, hast du {STR_VAR_1}\n"
	.string "unterschiedliche Pokémon gefangen?$"
#else
	.string "Hi! Remember me?\n"
	.string "I'm one of PROF. OAK's AIDES.\p"
	.string "If your POKéDEX has complete data\n"
	.string "on {STR_VAR_1} species, I'm supposed to\l"
	.string "give you a reward.\p"
	.string "PROF. OAK entrusted me with the\n"
	.string "{STR_VAR_2} for you.\p"
	.string "So, {PLAYER}, let me ask you.\p"
	.string "Have you gathered data on at least\n"
	.string "{STR_VAR_1} kinds of POKéMON?$"
#endif

Route11_EastEntrance_2F_Text_GreatHereYouGo::
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

Route11_EastEntrance_2F_Text_ReceivedItemfinderFromAide::
#if GERMAN
	.string "{PLAYER} erhält {STR_VAR_2}!$"
#else
	.string "{PLAYER} received the {STR_VAR_2}\n"
	.string "from the AIDE.$"
#endif

Route11_EastEntrance_2F_Text_ExplainItemfinder::
#if GERMAN
	.string "Auf dem Boden liegen oft Items,\n"
	.string "die man nicht sehen kann.\p"
	.string "Der Detektor spürt Items in deiner\n"
	.string "Nähe auf!\p"
	.string "Allerdings ortet er nicht die exakte\n"
	.string "Position!\p"
	.string "Er zeigt nur in die Richtung, wo\n"
	.string "das Item liegt.\p"
	.string "Benutze ihn, um dich zu orientieren\n"
	.string "und suche dann manuell!$"
#else
	.string "There are items on the ground that\n"
	.string "may be hidden from view.\p"
	.string "Use the ITEMFINDER to detect any\n"
	.string "hidden items close to you.\p"
	.string "The machine is a bit limited.\n"
	.string "It can't pinpoint item locations.\p"
	.string "What it does is show the direction\n"
	.string "where the item is.\p"
	.string "Use it to get your bearings, then\n"
	.string "search the suspect area by hand.$"
#endif

Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad::
#if GERMAN
	.string "Du schaust durch das Fernrohr.\p"
	.string "Mitten auf dem Weg schläft ein\n"
	.string "großes Pokémon!$"
#else
	.string "Let's see what the binoculars have\n"
	.string "to show…\p"
	.string "A big POKéMON is asleep on a road!$"
#endif

Route11_EastEntrance_2F_Text_WhatABreathtakingView::
#if GERMAN
	.string "Du schaust durch das Fernrohr.\p"
	.string "Du hast eine wunderschöne Aussicht!$"
#else
	.string "Let's see what the binoculars have\n"
	.string "to show…\p"
	.string "What a breathtaking view!$"
#endif

Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender::
#if GERMAN
	.string "Du schaust durch das Fernrohr.\p"
	.string "Der einzige Weg von Azuria City nach\n"
	.string "Lavandia führt durch den Felstunnel.$"
#else
	.string "Let's see what the binoculars have\n"
	.string "to show…\p"
	.string "To get to LAVENDER TOWN from\n"
	.string "CERULEAN CITY…\p"
	.string "ROCK TUNNEL appears to be a good\n"
	.string "route to take.$"
#endif

