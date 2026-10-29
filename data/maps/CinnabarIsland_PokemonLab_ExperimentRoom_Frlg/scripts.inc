.equ HELIX_FOSSIL, 1
.equ DOME_FOSSIL,  2
.equ OLD_AMBER,    3

CinnabarIsland_PokemonLab_ExperimentRoom_Frlg_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_Garett::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_SEEL
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set FLAG_DID_SEELOR_TRADE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, PARTY_SIZE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag FLAG_DID_SEELOR_TRADE
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade::
	msgbox Trade_Text_AwwOhWell
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist::
	lock
	faceplayer
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_REVIVED_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedMtMoonFossil
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_RevivedAllFossils
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveRevivedMon
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilStillReviving
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddHelixFossilToList
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelix
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddDomeFossilToList
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDome
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilAmber
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddHelixFossilToList::
	goto_if_unset FLAG_GOT_HELIX_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
	goto_if_set FLAG_REVIVED_HELIX, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
	setvar VAR_RESULT, TRUE
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddDomeFossilToList::
	goto_if_unset FLAG_GOT_DOME_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
	goto_if_set FLAG_REVIVED_DOME, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
	setvar VAR_RESULT, TRUE
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList::
	goto_if_unset FLAG_GOT_OLD_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
	goto_if_set FLAG_REVIVED_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
	setvar VAR_RESULT, TRUE
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse::
	setvar VAR_RESULT, FALSE
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_NoIsTooBad
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelix::
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	waitmessage
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelixAmber
	multichoice 0, 0, MULTI_HELIX, FALSE
	switch VAR_RESULT
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDome::
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	waitmessage
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDomeAmber
	multichoice 0, 0, MULTI_DOME, FALSE
	switch VAR_RESULT
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilAmber::
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	waitmessage
	multichoice 0, 0, MULTI_AMBER, FALSE
	switch VAR_RESULT
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelixAmber::
	multichoice 0, 0, MULTI_HELIX_AMBER, FALSE
	switch VAR_RESULT
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
	case 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDomeAmber::
	multichoice 0, 0, MULTI_DOME_AMBER, FALSE
	switch VAR_RESULT
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
	case 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil::
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	bufferitemname STR_VAR_2, ITEM_HELIX_FOSSIL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_HELIX_FOSSIL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil::
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	bufferitemname STR_VAR_2, ITEM_DOME_FOSSIL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_DOME_FOSSIL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber::
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	bufferitemname STR_VAR_2, ITEM_OLD_AMBER
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_OLD_AMBER
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_YouComeAgain
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilStillReviving::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveRevivedMon::
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveOmanyte
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveKabuto
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveAerodactyl
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveOmanyte::
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
	givemon SPECIES_OMANYTE, 40
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	setflag FLAG_REVIVED_HELIX
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveKabuto::
	setvar VAR_TEMP_1, SPECIES_KABUTO
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
	givemon SPECIES_KABUTO, 40
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	setflag FLAG_REVIVED_DOME
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveAerodactyl::
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
	givemon SPECIES_AERODACTYL, 40
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	setflag FLAG_REVIVED_AMBER
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor
	waitmessage
	waitfanfare
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor
	waitmessage
	waitfanfare
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC::
	call Common_EventScript_TransferredToPC
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon::
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_RevivedAllFossils::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_YouComeAgain
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedMtMoonFossil::
	goto_if_set FLAG_GOT_HELIX_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedHelix
	goto_if_set FLAG_GOT_DOME_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedDome
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedHelix::
	goto_if_unset FLAG_REVIVED_HELIX, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
	setvar VAR_RESULT, TRUE
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedDome::
	goto_if_unset FLAG_REVIVED_DOME, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
	setvar VAR_RESULT, TRUE
	return

Text_MetronomeTeach::
#if GERMAN
	.string "Tak-tak-tak!\n"
	.string "Ich kann einem Pokémon eine tolle\l"
	.string "Attacke beibringen!\p"
	.string "Die Attacke heißt Metronom!\n"
	.string "Könnte sie dir gefallen?$"
#else
	.string "Tch-tch-tch!\n"
	.string "I'll teach you a nifty move.\p"
	.string "Teach it to a POKéMON, and watch\n"
	.string "the fun unfold!\p"
	.string "It's a move called METRONOME.\n"
	.string "Does it strike your fancy?$"
#endif

Text_MetronomeDeclined::
#if GERMAN
	.string "Ich sage dir, es macht viel Spaß!$"
#else
	.string "I tell you, it's a lot of fun!$"
#endif

Text_MetronomeWhichMon::
#if GERMAN
	.string "O.K.! Welches Pokémon soll sie erlernen?$"
#else
	.string "Okay!\n"
	.string "Which POKéMON should I teach?$"
#endif

Text_MetronomeTaught::
#if GERMAN
	.string "Tak-tak-tak!\n"
	.string "So klingt ein Metronom!\p"
	.string "Damit setzt dein Pokémon Attacken\n"
	.string "ein, die es gar nicht kennt!$"
#else
	.string "Tch-tch-tch!\n"
	.string "That's the sound of a METRONOME.\p"
	.string "It tweaks your POKéMON's brain into\n"
	.string "using moves it doesn't even know.$"
#endif

CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe::
#if GERMAN
	.string "Hallo!\p"
	.string "Ich leite hier die Forschungen!\p"
	.string "Wir erforschen Fossilien von\n"
	.string "Urzeit-Pokémon!\p"
	.string "Hast du ein Fossil für mich?$"
#else
	.string "Hiya!\p"
	.string "I am important doctor.\n"
	.string "Yes, very much so, indeed.\p"
	.string "Here, I study rare POKéMON fossils.\n"
	.string "All the time, I study.\p"
	.string "You!\n"
	.string "Have you a fossil for me?$"
#endif

CinnabarIsland_PokemonLab_ExperimentRoom_Text_NoIsTooBad::
#if GERMAN
	.string "Nein?\n"
	.string "Zu schade!$"
#else
	.string "No!\n"
	.string "Is too bad!$"
#endif

@ Unused
CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalkJP::
	.string "ちょっと　じかん　かかるよ！\p"
	.string "そこらへんを　すこし\n"
	.string "ブラブラ　してくると　よろしー！$"

CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife::
#if GERMAN
	.string "Wo warst du? Wir haben dein Fossil\n"
	.string "wieder belebt!\p"
	.string "Ein {STR_VAR_1}, ganz wie ich es\n"
	.string "vermutet habe!$"
#else
	.string "You late.\n"
	.string "Where were you?\p"
	.string "Your fossil is back to life!\n"
	.string "It was {STR_VAR_1} like I think!$"
#endif

CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor::
#if GERMAN
	.string "{PLAYER} erhält {STR_VAR_1}!$"
#else
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from the doctor.$"
#endif

@ Unused
CinnabarIsland_PokemonLab_ExperimentRoom_Text_NoRoomForPokemon::
	.string "ポケモン　いっぱいで　もてないね！$"

CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain::
#if GERMAN
	.string "Oh!\n"
	.string "Das ist ein {STR_VAR_2}!\p"
	.string "Es ist ein Fossil von {STR_VAR_1}, einem\n"
	.string "schon lange ausgestorbenen Pokémon!\p"
	.string "Dank modernster Technik können wir\n"
	.string "Pokémon aus Fossilien wieder beleben!$"
#else
	.string "Oh!\n"
	.string "That is {STR_VAR_2}, it is!\p"
	.string "It is fossil of {STR_VAR_1},\n"
	.string "a POKéMON that is already extinct!\p"
	.string "My Resurrection Machine will make\n"
	.string "that POKéMON live again!$"
#endif

@ TODO: Resolve text dump error below?
CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor::
#if GERMAN
	.string "Gib es schnell her, damit ich fortfahren\n"
	.string "kann!\p"
	.string "{FONT_NORMAL}{PLAYER} übergibt das\n"
	.string "{STR_VAR_2}!$"
#else
	.string "So!\n"
	.string "You hurry and give me that!\p"
	.string "{FONT_NORMAL}{PLAYER} handed over the\n"
	.string "{STR_VAR_2} to the weird doctor.$"
#endif

CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk::
#if GERMAN
	.string "Es wird einige Zeit dauern!\n"
	.string "Komm einfach später wieder vorbei!$"
#else
	.string "I take a little time!\n"
	.string "You go for walk a little while!$"
#endif

CinnabarIsland_PokemonLab_ExperimentRoom_Text_YouComeAgain::
#if GERMAN
	.string "Du bist jederzeit willkommen!$"
#else
	.string "Aiyah!\n"
	.string "You come again!$"
#endif

