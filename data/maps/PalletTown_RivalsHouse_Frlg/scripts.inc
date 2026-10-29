.equ RECEIVED_TOWN_MAP, VAR_TEMP_1

PalletTown_RivalsHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
	end

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	return

PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
	setvar RECEIVED_TOWN_MAP, TRUE
	return

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	@ Origin Jade: Daisy gives no Town Map.
	goto_if_eq RECEIVED_TOWN_MAP, TRUE, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_DaisyGoodLuck
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_RivalsHouse_EventScript_HeardBattledRival
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
	closemessage
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_RivalsHouse_EventScript_HeardBattledRival::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
	release
	end

PalletTown_RivalsHouse_EventScript_GroomMon::
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
	release
	end

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
	release
	end

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
	release
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
	release
	end

@ Origin Jade: replaces the Town Map handover.
PalletTown_RivalsHouse_EventScript_DaisyGoodLuck::
	msgbox PalletTown_RivalsHouse_Text_DaisyGoodLuck
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	release
	end

PalletTown_RivalsHouse_Text_DaisyGoodLuck:
#if GERMAN
	.string "Sarah: Oh, wie schön!\p"
	.string "Du hast ein Pokémon von meinem\n"
	.string "Opa bekommen.\p"
	.string "Dann wird es ja Zeit, dass du\n"
	.string "losziehst. Viel Spaß, {PLAYER}!$"
#else
	.string "DAISY: Oh, how nice!\p"
	.string "You got a POKéMON from my\n"
	.string "GRANDPA.\p"
	.string "Time for you to set off, then.\n"
	.string "Have fun, {PLAYER}!$"
#endif

PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
	release
	end

PalletTown_RivalsHouse_EventScript_ExplainTownMap::
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
	release
	end

PalletTown_RivalsHouse_EventScript_TownMap::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
	end

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_HiBrothersAtLab::
#if GERMAN
	.string "Sarah: Hallo {PLAYER}!\p"
	.string "{RIVAL} wartet in Opas Labor.$"
#else
	.string "DAISY: Hi, {PLAYER}!\p"
	.string "My brother, {RIVAL}, is out at\n"
	.string "Grandpa's LAB.$"
#endif

PalletTown_RivalsHouse_Text_HeardYouBattledRival::
#if GERMAN
	.string "Sarah: Hallo {PLAYER}! Ich hörte, dass\n"
	.string "du gegen {RIVAL} gekämpft hast.\l"
	.string "Das hätte ich gerne gesehen!$"
#else
	.string "DAISY: {PLAYER}, I heard you had\n"
	.string "a battle against {RIVAL}.\p"
	.string "I wish I'd seen that!$"
#endif

PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp::
#if GERMAN
	.string "Opa hat dich um einen Botengang\n"
	.string "gebeten?\p"
	.string "Hier, das wird dir weiterhelfen!$"
#else
	.string "Grandpa asked you to run an\n"
	.string "errand?\p"
	.string "Gee, that's lazy of him.\n"
	.string "Here, this will help you.$"
#endif

PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy::
#if GERMAN
	.string "{PLAYER} erhält eine Karte!$"
#else
	.string "{PLAYER} received a TOWN MAP\n"
	.string "from DAISY.$"
#endif

PalletTown_RivalsHouse_Text_DontHaveSpaceForThis::
#if GERMAN
	.string "Du trägst zu viele Dinge mit dir\n"
	.string "herum!$"
#else
	.string "You don't have space for this in\n"
	.string "your BAG.$"
#endif

PalletTown_RivalsHouse_Text_ExplainTownMap::
#if GERMAN
	.string "Benutze die Karte, um deinen Standort\n"
	.string "zu bestimmen.$"
#else
	.string "You can use the TOWN MAP to find\n"
	.string "out where you are, or check the\l"
	.string "names of places.$"
#endif

PalletTown_RivalsHouse_Text_PleaseGiveMonsRest::
#if GERMAN
	.string "Sarah: Wie Menschen sind Pokémon\n"
	.string "Lebewesen!\p"
	.string "Wenn sie erschöpft sind, brauchen sie\n"
	.string "eine Pause!$"
#else
	.string "DAISY: Just like people, POKéMON\n"
	.string "are living things.\p"
	.string "When they get tired, please give\n"
	.string "them a rest.$"
#endif

PalletTown_RivalsHouse_Text_ItsBigMapOfKanto::
#if GERMAN
	.string "Eine große Karte!\n"
	.string "Sie ist nützlich!$"
#else
	.string "It's a big map of the KANTO region.\n"
	.string "Now this would be useful!$"
#endif

PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks::
#if GERMAN
	.string "Wow! Unmengen von Büchern über\n"
	.string "Pokémon!$"
#else
	.string "The shelves are crammed full of\n"
	.string "books on POKéMON.$"
#endif

PalletTown_RivalsHouse_Text_LikeMeToGroomMon::
#if GERMAN
	.string "Sarah: Hi! Gutes Timing. Ich war\n"
	.string "gerade dabei, Tee zu machen.\p"
	.string "Hättest du auch gern eine Tasse\n"
	.string "Tee?\p"
	.string "Oh, deine Pokémon sehen ein bisschen\n"
	.string "mitgenommen aus.\p"
	.string "Möchtest du, dass ich eines für\n"
	.string "dich verschönere?$"
#else
	.string "DAISY: Hi, {PLAYER}!\n"
	.string "Good timing.\p"
	.string "I'm about to have some tea.\n"
	.string "Would you like to join me?\p"
	.string "Oh, but look.\n"
	.string "Your POKéMON are a little dirty.\p"
	.string "Would you like me to groom one?$"
#endif

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming::
#if GERMAN
	.string "Möchtest du keines deiner Pokémon\n"
	.string "verschönern lassen?\l"
	.string "Gut, dann trinken wir eben nur Tee.$"
#else
	.string "You don't need any grooming done?\n"
	.string "Okay, we'll just have tea.$"
#endif

PalletTown_RivalsHouse_Text_GroomWhichOne::
#if GERMAN
	.string "Welches soll ich verschönern?$"
#else
	.string "Which one should I groom?$"
#endif

PalletTown_RivalsHouse_Text_LookingNiceInNoTime::
#if GERMAN
	.string "Sarah: Gut. In kürzester Zeit wird\n"
	.string "es hübsch und adrett aussehen.$"
#else
	.string "DAISY: Okay, I'll get it looking\n"
	.string "nice in no time.$"
#endif

PalletTown_RivalsHouse_Text_ThereYouGoAllDone::
#ifdef BUGFIX @ The localizers missed what should be a textcolor change in the localizations.
	.string "{COLOR DARK_GRAY}{STR_VAR_1} sieht zufrieden aus.\p"
	.string "{COLOR RED}Daisy: Hier bitte. Schon fertig.\n"
#else @ In the JP games, gender-based text used a different font instead of different colors.
	.string "{FONT_NORMAL}{STR_VAR_1} sieht zufrieden aus.\p"
	.string "{FONT_FEMALE}Daisy: Hier bitte. Schon fertig.\n"
#endif
	.string "Siehst du? Ist es jetzt nicht\n"
	.string "wunderschön?\p"
	.string "Es ist so ein süßes Pokémon.$"

PalletTown_RivalsHouse_Text_CantGroomAnEgg::
#if GERMAN
	.string "Es tut mir Leid, aber ich kann\n"
	.string "wirklich kein Ei verschönern.$"
#else
	.string "Oh, sorry. I honestly can't\n"
	.string "groom an EGG.$"
#endif

PalletTown_RivalsHouse_Text_MayISeeFirstMon::
#if GERMAN
	.string "Sarah: Deine Pokémon werden dich\n"
	.string "lieben, wenn du sie mit Liebe trainierst.\l"
	.string "{PLAYER}, darf ich dein erstes Pokémon\l"
	.string "sehen?$"
#else
	.string "DAISY: Your POKéMON grow to love\n"
	.string "you if you raise them with love.\p"
	.string "For example, {PLAYER}, may I see\n"
	.string "your first POKéMON?$"
#endif

PalletTown_RivalsHouse_Text_CouldntLoveYouMore::
#if GERMAN
	.string "Es liebt dich über alles! Das ist\n"
	.string "so wunderbar und toll!\p"
	.string "Dein Pokémon könnte nicht glücklicher\n"
	.string "sein!$"
#else
	.string "It couldn't possibly love you\n"
	.string "any more than it does now.\p"
	.string "Your POKéMON is happy beyond\n"
	.string "words.$"
#endif

PalletTown_RivalsHouse_Text_ItLooksVeryHappy::
#if GERMAN
	.string "Es ist sehr glücklich!\p"
	.string "Ich wünschte, {RIVAL} könnte das\n"
	.string "sehen und etwas daraus lernen.$"
#else
	.string "It looks very happy.\p"
	.string "I wish {RIVAL} could see this and\n"
	.string "learn something from it.$"
#endif

PalletTown_RivalsHouse_Text_ItsQuiteFriendly::
#if GERMAN
	.string "Es ist ein guter Freund von dir!\n"
	.string "Behandle es weiterhin gut!$"
#else
	.string "It's quite friendly with you.\n"
	.string "Keep being good to it!$"
#endif

PalletTown_RivalsHouse_Text_ItsWarmingUpToYou::
#if GERMAN
	.string "Es nähert sich dir an! Euer\n"
	.string "gegenseitiges Vertrauen muss noch\l"
	.string "besser werden!$"
#else
	.string "It's warming up to you.\n"
	.string "Trust must be growing between you.$"
#endif

PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet::
#if GERMAN
	.string "Es kennt dich noch nicht gut!\p"
	.string "Pokémon sind zunächst skeptisch,\n"
	.string "wenn man sie fängt!$"
#else
	.string "It's not quite familiar with you\n"
	.string "yet.\p"
	.string "POKéMON are all quite wary when\n"
	.string "you first get them.$"
#endif

PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou::
#if GERMAN
	.string "{PLAYER}, ich mag gar nicht, wie es\n"
	.string "dich anschaut!\p"
	.string "Du solltest etwas liebevoller mit\n"
	.string "ihm umgehen!$"
#else
	.string "{PLAYER}, I don't like the way it\n"
	.string "glares at you.\p"
	.string "Could you try being a little nicer\n"
	.string "to it?$"
#endif

PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch::
#if GERMAN
	.string "… äh, ich weiß nicht wie ich es sagen\n"
	.string "soll, aber…\p"
	.string "Gibt es einen Grund, warum dich\n"
	.string "dein Pokémon so abgrundtief hasst?$"
#else
	.string "…Um, it's not easy for me to say\n"
	.string "this, but…\p"
	.string "Is there some reason why your\n"
	.string "POKéMON would hate you so much?$"
#endif

PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy::
#if GERMAN
	.string "Das liebliche, zuckersüße\n"
	.string "Piepi.$"
#else
	.string "“The lovely and sweet\n"
	.string "CLEFAIRY”$"
#endif

