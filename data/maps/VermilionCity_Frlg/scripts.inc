VermilionCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
	.byte 0

VermilionCity_OnFrame::
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
	.2byte 0

VermilionCity_EventScript_ExitSSAnne::
	lockall
	applymovement LOCALID_PLAYER, VermilionCity_Movement_ExitSSAnne
	waitmovement 0
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
	releaseall
	end

VermilionCity_Movement_ExitSSAnne::
	walk_up
	walk_up
	step_end

VermilionCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
	end

VermilionCity_EventScript_HideOaksAide::
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_EventScript_Woman::
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
	end

VermilionCity_EventScript_OldMan1::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
	release
	end

VermilionCity_EventScript_OldMan1SSAnneLeft::
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
	release
	end

VermilionCity_EventScript_CheckHasMysticTicket::
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
	checkitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckHasAuroraTicket::
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckSeagallopPresent::
	@ Kanto-Merge: Die Seegallope fuhr zu den stillgelegten Sevii-Inseln.
	@ Stattdessen dasselbe Faehrmenue wie in Olivia - die Liste
	@ MULTI_VERMILION_HARBOR gab es bereits, sie haing nur an der
	@ stillgelegten HnS-Karte.
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_WhereSail
	multichoicegrid 1, 0, MULTI_VERMILION_HARBOR, 2, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_ChoseOlivine
	case 1, VermilionCity_EventScript_ChoseSouthernIsland
	case 2, VermilionCity_EventScript_ChoseBirthIsland
	case 3, VermilionCity_EventScript_ChoseFarawayIsland
	case 4, VermilionCity_EventScript_ChoseBattleFrontier
	case 5, Common_EventScript_SailToHoenn
	case 6, VermilionCity_EventScript_CancelSail
	case MULTI_B_PRESSED, VermilionCity_EventScript_CancelSail
	release
	end

VermilionCity_EventScript_CancelSail::
	closemessage
	release
	end

@ Ziele, die ein Ticket verlangen. Ohne bleibt der Matrose freundlich.
VermilionCity_EventScript_ChoseSouthernIsland::
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, VermilionCity_EventScript_NoTicket
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_NoTicket
	closemessage
	delay 20
	warpsilent MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
	waitstate
	release
	end

VermilionCity_EventScript_ChoseBirthIsland::
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, VermilionCity_EventScript_NoTicket
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_NoTicket
	closemessage
	delay 20
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR, 15, 20
	waitstate
	release
	end

VermilionCity_EventScript_ChoseFarawayIsland::
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, VermilionCity_EventScript_NoTicket
	checkitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_NoTicket
	closemessage
	delay 20
	warpsilent MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	waitstate
	release
	end

VermilionCity_EventScript_ChoseBattleFrontier::
	goto_if_unset FLAG_LANDMARK_BATTLE_FRONTIER, VermilionCity_EventScript_NoTicket
	closemessage
	delay 20
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_EAST, 3, 24
	waitstate
	release
	end

@ Nach Johto. Erst moeglich, wenn der Spieler dort gewesen ist.
VermilionCity_EventScript_ChoseOlivine::
	goto_if_unset FLAG_VISITED_JOHTO, VermilionCity_EventScript_NoTicket
	closemessage
	delay 20
	warpsilent MAP_OLIVINE_CITY_HNS, 13, 43
	waitstate
	release
	end

VermilionCity_EventScript_NoTicket::
	msgbox VermilionCity_Text_FerryNoTicket
	closemessage
	release
	end

VermilionCity_Text_WhereSail:
#if GERMAN
	.string "Wohin soll die Reise gehen?$"
#else
	.string "Where would you like to sail?$"
#endif

VermilionCity_Text_FerryNoTicket:
#if GERMAN
	.string "Dorthin kann ich dich noch nicht\n"
	.string "bringen. Komm wieder, wenn du die\l"
	.string "nötigen Papiere hast!$"
#else
	.string "I can't take you there yet.\n"
	.string "Come back when you have the right\l"
	.string "papers!$"
#endif

VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
	call VermilionCity_EventScript_CheckHasMysticTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_BoardSeagallopRainbowPass
	waitmessage
	goto EventScript_SeviiDestinationsPage1
	end

VermilionCity_EventScript_HasMysticTicket::
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 17, 6, MULTI_SEVII_NAVEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowMysticTicket::
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
	return

VermilionCity_EventScript_HasAuroraTicket::
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 6, MULTI_SEVII_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowAuroraTicket::
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
	return

VermilionCity_EventScript_HasMysticAndAuroraTickets::
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 5, MULTI_SEVII_NAVEL_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_SailToBirthIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

EventScript_SailToNavelRock::
	msgbox VermilionCity_Text_Seagallop10Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
	goto EventScript_SetSail
	end

EventScript_SailToBirthIsland::
	msgbox VermilionCity_Text_Seagallop12Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_ChooseSeagallopDestTriPass::
	message VermilionCity_Text_BoardSeagallopTriPass
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	multichoice 19, 5, MULTI_SEAGALLOP_123, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToOneIsland2
	case 1, EventScript_SailToTwoIsland2
	case 2, EventScript_SailToThreeIsland2
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

@ Unreachable
Vermilion_EventScript_Unused::
	release
	end

VermilionCity_EventScript_CheckTicketLeft::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_CheckTicketRight::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_ExitedTicketCheck::
	lockall
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
	releaseall
	end

VermilionCity_EventScript_CheckTicket::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_VERMILION_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
	msgbox VermilionCity_Text_DoYouHaveATicket
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
	msgbox VermilionCity_Text_FlashedSSTicket
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
	releaseall
	end

VermilionCity_EventScript_DontHaveSSTicket::
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_CheckSeagallopPresentTrigger::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_Sailor::
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
	end

VermilionCity_EventScript_OaksAide::
	lock
	faceplayer
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
	release
	end

VermilionCity_EventScript_OldMan2::
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop
	waitmoncry
	msgbox VermilionCity_Text_MachopStompingLandFlat
	release
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_EventScript_SnorlaxNotice::
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_EventScript_PokemonFanClubSign::
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_LTSURGE, 0
	msgbox VermilionCity_Text_GymSign
	releaseall
	end

VermilionCity_EventScript_HarborSign::
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end

VermilionCity_Text_GrimerMultipliesInSludge::
#if GERMAN
	.string "Wir sind sehr umweltbewusst!\p"
	.string "Wir haben gehört, dass Sleima sich in\n"
	.string "giftigem Dreck wohl fühlt und\l"
	.string "entwickelt!$"
#else
	.string "We're careful about pollution here.\p"
	.string "We've heard GRIMER multiplies in\n"
	.string "toxic sludge.$"
#endif

VermilionCity_Text_DidYouSeeSSAnneInHarbor::
#if GERMAN
	.string "Hast du gesehen?\n"
	.string "Die M.S. Anne ankert im Hafen!$"
#else
	.string "Did you see the S.S. ANNE moored\n"
	.string "in the harbor?$"
#endif

VermilionCity_Text_SSAnneHasDepartedForYear::
#if GERMAN
	.string "Die M.S. Anne ist ausgelaufen!\p"
	.string "Sie wird in einem Jahr wieder hier\n"
	.string "anlegen.$"
#else
	.string "So, the S.S. ANNE has departed?\p"
	.string "She'll be back in VERMILION about\n"
	.string "this time next year.$"
#endif

VermilionCity_Text_BuildingOnThisLand::
#if GERMAN
	.string "Ich möchte auf diesem Land bauen.\n"
	.string "Mein Pokémon ebnet den Boden!$"
#else
	.string "I'm putting up a building on this\n"
	.string "plot of land. I own it all.\p"
	.string "My POKéMON is tamping the land\n"
	.string "to lay the foundation.$"
#endif

VermilionCity_Text_Machop::
#if GERMAN
	.string "Machollo: Macho! Machollo!$"
#else
	.string "MACHOP: Guoh! Gogogoh!$"
#endif

VermilionCity_Text_MachopStompingLandFlat::
#if GERMAN
	.string "Ein Machollo ebnet das Land!$"
#else
	.string "A MACHOP is stomping the land flat.$"
#endif

VermilionCity_Text_SSAnneVisitsOnceAYear::
#if GERMAN
	.string "Die M.S. Anne ist ein luxuriöses\n"
	.string "Kreuzfahrtschiff.\p"
	.string "Wir besuchen Orania City einmal\n"
	.string "im Jahr.$"
#else
	.string "The S.S. ANNE is a famous luxury\n"
	.string "cruise ship.\p"
	.string "It visits VERMILION once a year.$"
#endif

VermilionCity_Text_CitySign::
#if GERMAN
	.string "Orania City\n"
	.string "Die abendrote Hafenstadt$"
#else
	.string "VERMILION CITY\n"
	.string "The Port of Exquisite Sunsets$"
#endif

VermilionCity_Text_SnorlaxBlockingRoute12::
#if GERMAN
	.string "Achtung!\p"
	.string "Route 12 wird von einem\n"
	.string "schlafenden Pokémon blockiert.\p"
	.string "Umleitung: Felstunnel nach\n"
	.string "Lavandia.\p"
	.string "Polizei von Orania City$"
#else
	.string "NOTICE!\p"
	.string "ROUTE 12 may be blocked off by a\n"
	.string "sleeping POKéMON.\p"
	.string "Detour through ROCK TUNNEL to\n"
	.string "LAVENDER TOWN.\p"
	.string "VERMILION POLICE$"
#endif

VermilionCity_Text_PokemonFanClubSign::
#if GERMAN
	.string "Pokémon-Fanclub\n"
	.string "Alle Pokémon-Fans sind willkommen!$"
#else
	.string "POKéMON FAN CLUB\n"
	.string "All POKéMON fans welcome!$"
#endif

VermilionCity_Text_GymSign::
#if GERMAN
	.string "Pokémon-Arena von Orania City Leiter:\n"
	.string "Major Bob Ein Blitz am Himmel des\l"
	.string "Militärs$"
#else
	.string "VERMILION CITY POKéMON GYM\n"
	.string "LEADER: LT. SURGE\l"
	.string "The Lightning American!$"
#endif

VermilionCity_Text_VermilionHarbor::
#if GERMAN
	.string "Hafen von Orania City$"
#else
	.string "VERMILION HARBOR$"
#endif

VermilionCity_Text_WelcomeToTheSSAnne::
#if GERMAN
	.string "Willkommen an Bord!$"
#else
	.string "Welcome to the S.S. ANNE!$"
#endif

VermilionCity_Text_DoYouHaveATicket::
#if GERMAN
	.string "Willkommen auf der M.S. Anne!\p"
	.string "Verzeihung, hast du ein Ticket?$"
#else
	.string "Welcome to the S.S. ANNE!\p"
	.string "Excuse me, do you have a ticket?$"
#endif

VermilionCity_Text_FlashedSSTicket::
#if GERMAN
	.string "{FONT_NORMAL}{PLAYER} zeigt das Bootsticket!\p"
	.string "{FONT_MALE}Großartig!\n"
	.string "Willkommen auf der M.S. Anne!$"
#else
	.string "{FONT_NORMAL}{PLAYER} flashed the S.S. TICKET!\p"
	.string "{FONT_MALE}Great!\n"
	.string "Welcome to the S.S. ANNE!$"
#endif

VermilionCity_Text_DontHaveNeededSSTicket::
#if GERMAN
	.string "{FONT_NORMAL}{PLAYER} hat kein Bootsticket!\p"
	.string "{FONT_MALE}Tut mir Leid!\p"
	.string "Du brauchst ein Ticket, um an Bord\n"
	.string "gehen zu können.$"
#else
	.string "{FONT_NORMAL}{PLAYER} doesn't have the needed\n"
	.string "S.S. TICKET.\p"
	.string "{FONT_MALE}Sorry!\p"
	.string "You need a ticket to get aboard.$"
#endif

VermilionCity_Text_TheShipSetSail::
#if GERMAN
	.string "Das Schiff ist in See gestochen!$"
#else
	.string "The ship set sail.$"
#endif

VermilionCity_Text_BoardSeagallopTriPass::
#if GERMAN
	.string "Ah, du hast den Tri-Pass.\p"
	.string "Möchtest du an Bord der\n"
	.string "Seesprint-Fähre?$"
#else
	.string "Ah, you have a TRI-PASS.\p"
	.string "Would you like to board\n"
	.string "a SEAGALLOP ferry?$"
#endif

VermilionCity_Text_Seagallop7Departing::
#if GERMAN
	.string "O.K.! Alles klar!\p"
	.string "Seesprint Tempo 7 wird in Kürze ablegen.$"
#else
	.string "Okay, everything's in order.\p"
	.string "SEAGALLOP HI-SPEED 7 will be\n"
	.string "departing immediately.$"
#endif

VermilionCity_Text_BoardSeagallopRainbowPass::
#if GERMAN
	.string "Ah, du hast den Bunt-Pass.\p"
	.string "Möchtest du an Bord der\n"
	.string "Seesprint-Fähre?$"
#else
	.string "Ah, you have a RAINBOW PASS.\p"
	.string "Would you like to board\n"
	.string "a SEAGALLOP ferry?$"
#endif

VermilionCity_Text_OhMysticTicketTakeYouToNavelRock::
#if GERMAN
	.string "Oh! Das ist das Geheimticket!\n"
	.string "Das ist selten.\p"
	.string "Wir bringen dich gerne zum Nabelfels.$"
#else
	.string "Oh! That's a MYSTICTICKET!\n"
	.string "Now that is rare.\p"
	.string "We'll be happy to take you to\n"
	.string "NAVEL ROCK anytime.$"
#endif

VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland::
#if GERMAN
	.string "Oh! Das ist das Auroraticket!\n"
	.string "Das ist selten.\p"
	.string "Wir bringen dich gerne zur\n"
	.string "Entstehungsinsel.$"
#else
	.string "Oh! That's an AURORATICKET!\n"
	.string "Now that is rare.\p"
	.string "We'll be happy to take you to\n"
	.string "BIRTH ISLAND anytime.$"
#endif

VermilionCity_Text_BoardSeagallopFerry::
#if GERMAN
	.string "Möchtest du an Bord der\n"
	.string "Seesprint-Fähre?$"
#else
	.string "Would you like to board\n"
	.string "a SEAGALLOP ferry?$"
#endif

VermilionCity_Text_Seagallop10Departing::
#if GERMAN
	.string "O.K.! Alles klar! Du kannst an Bord\n"
	.string "der Spezialfähre.\p"
	.string "Seesprint Tempo 10 wird sofort ablegen.$"
#else
	.string "Okay, everything's in order for you\n"
	.string "to board a special ferry.\p"
	.string "SEAGALLOP HI-SPEED 10 will be\n"
	.string "departing immediately.$"
#endif

VermilionCity_Text_Seagallop12Departing::
#if GERMAN
	.string "O.K.! Alles klar! Du kannst an Bord\n"
	.string "der Spezialfähre.\p"
	.string "Seesprint Tempo 12 wird sofort ablegen.$"
#else
	.string "Okay, everything's in order for you\n"
	.string "to board a special ferry.\p"
	.string "SEAGALLOP HI-SPEED 12 will be\n"
	.string "departing immediately.$"
#endif

VermilionCity_Text_Route2AideHasPackageForYou::
#if GERMAN
	.string "Oh, hallo, {PLAYER}!\n"
	.string "Wie geht es dir?\p"
	.string "Ich bin es, einer von Prof. Eichs\n"
	.string "Assistenten.\p"
	.string "Hast du bereits einen anderen\n"
	.string "Assistenten getroffen?\p"
	.string "Er hatte ein Paket von Prof. Eich\n"
	.string "für dich, {PLAYER}.\p"
	.string "Er sagte, er sucht dich bei Route 2,\n"
	.string "{PLAYER}.\p"
	.string "Wenn du bei Route 2 bist, halte nach ihm\n"
	.string "Ausschau.$"
#else
	.string "Oh, hello, {PLAYER}!\n"
	.string "How are you doing?\p"
	.string "It's me, one of PROF. OAK's AIDES.\p"
	.string "Did you meet the other AIDE?\p"
	.string "He had a package from PROF. OAK\n"
	.string "for you, {PLAYER}.\p"
	.string "He said he'd look for you around\n"
	.string "ROUTE 2, {PLAYER}.\p"
	.string "If you're in the ROUTE 2 area,\n"
	.string "please look for him.$"
#endif

