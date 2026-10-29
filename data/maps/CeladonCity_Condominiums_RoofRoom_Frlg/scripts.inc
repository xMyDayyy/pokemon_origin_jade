CeladonCity_Condominiums_RoofRoom_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_RoofRoom_EventScript_BlackBelt::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_TheresNothingIDontKnow, MSGBOX_NPC
	end

CeladonCity_Condominiums_RoofRoom_EventScript_EeveeBall::
	lock
	faceplayer
	setvar VAR_TEMP_1, SPECIES_EEVEE
	givemon SPECIES_EEVEE, 25
	goto_if_eq VAR_RESULT, 0, CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveeParty
	goto_if_eq VAR_RESULT, 1, CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveePC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveeParty::
	removeobject LOCALID_EEVEE_POKEBALL
	playfanfare MUS_LEVEL_UP
	message CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
	end

CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveePC::
	removeobject LOCALID_EEVEE_POKEBALL
	playfanfare MUS_LEVEL_UP
	message CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC
	end

CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC::
	call Common_EventScript_TransferredToPC
	goto CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
	end

@ Origin Jade: FLAG_GOT_EEVEE is Bill's Eevee in Goldenrod, not set here.
CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee::
	release
	end

CeladonCity_Condominiums_RoofRoom_EventScript_TMsPamphlet::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs, MSGBOX_SIGN
	end

CeladonCity_Condominiums_RoofRoom_EventScript_Blackboard::
	lockall
	msgbox CeladonCity_Condominiums_RoofRoom_Text_WirelessAdapterLecture
	message CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading
	waitmessage
	setvar VAR_0x8004, 4
	multichoice 0, 0, MULTI_LINKED_DIRECT_UNION, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub
	case 1, CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner
	case 2, CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom
	case 3, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	case 127, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	end

CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading::
	message CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading
	waitmessage
	multichoice 0, 0, MULTI_LINKED_DIRECT_UNION, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub
	case 1, CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner
	case 2, CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom
	case 3, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	case 127, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	end

CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainWirelessClub
	goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
	end

CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainDirectCorner
	goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
	end

CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainUnionRoom
	goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
	end

CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard::
	releaseall
	end

CeladonCity_Condominiums_RoofRoom_Text_TheresNothingIDontKnow::
#if GERMAN
	.string "Ich kenne jedes Detail der\n"
	.string "Pokémon-Welt in deinem Game Boy\l"
	.string "Advance!\p"
	.string "Triff dich mit Freunden und tausche\n"
	.string "Pokémon!$"
#else
	.string "There is nothing that I don't know,\n"
	.string "like I wrote on the blackboard.\p"
	.string "I know about the world of POKéMON\n"
	.string "in your GAME BOY ADVANCE!\p"
	.string "Get together with your friends and\n"
	.string "enjoy trading POKéMON!$"
#endif

CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee::
#if GERMAN
	.string "{PLAYER} erhält ein Evoli!$"
#else
	.string "{PLAYER} obtained an EEVEE!$"
#endif

CeladonCity_Condominiums_RoofRoom_Text_BoxIsFull::
	.string "ポケモンが　いっぱいだ\n"
	.string "ボックスを　かえて　きなさい$"

CeladonCity_Condominiums_RoofRoom_Text_WirelessAdapterLecture::
#if GERMAN
	.string "Pokémon Lektüre\p"
	.string "Spielen mit dem Drahtlosen Adapter$"
#else
	.string "POKéMON Lecture\p"
	.string "Playing with the Wireless Adapter$"
#endif

CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading::
#if GERMAN
	.string "Wähle bitte ein Themengebiet aus.$"
#else
	.string "Which heading do you want to read?$"
#endif

CeladonCity_Condominiums_RoofRoom_Text_ExplainWirelessClub::
#if GERMAN
	.string "Der Pokémon Drahtlosklub befindet sich\n"
	.string "im oberen Stockwerk jedes\l"
	.string "Pokémon-Centers.\l"
	.string "Tritt dem Klub bei, um Freunde via\l"
	.string "Drahtlosem Adapter zu treffen.$"
#else
	.string "The POKéMON WIRELESS CLUB is\n"
	.string "upstairs at any POKéMON CENTER.\p"
	.string "Visit one to link up with friend(s)\n"
	.string "using your Wireless Adapter.$"
#endif

CeladonCity_Condominiums_RoofRoom_Text_ExplainDirectCorner::
#if GERMAN
	.string "Um nur einen Freund zu treffen, kannst\n"
	.string "du in den Direktklub gehen.\l"
	.string "Das ist der rechte Schalter im Pokémon\l"
	.string "Drahtlosklub.\p"
	.string "Triff deinen Freund in der Tauschbörse\n"
	.string "oder im Kolosseum!$"
#else
	.string "To link only with a friend, go to\n"
	.string "the DIRECT CORNER.\p"
	.string "It is the right counter at the\n"
	.string "POKéMON WIRELESS CLUB.\p"
	.string "Go into the TRADE CORNER or the\n"
	.string "COLOSSEUM with your friend.$"
#endif

CeladonCity_Condominiums_RoofRoom_Text_ExplainUnionRoom::
#if GERMAN
	.string "Um dich mit vielen Freunden zu treffen,\n"
	.string "kannst du in den Konnex-Klub gehen.\l"
	.string "Das ist der linke Schalter im Pokémon\l"
	.string "Drahtlosklub.\p"
	.string "Im Konnex-Klub triffst du andere\n"
	.string "Trainer.$"
#else
	.string "To link and communicate with\n"
	.string "anyone, go to the UNION ROOM.\p"
	.string "It is the left counter at the\n"
	.string "POKéMON WIRELESS CLUB.\p"
	.string "Go to the UNION ROOM and enjoy\n"
	.string "meeting other TRAINERS.$"
#endif

CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs::
#if GERMAN
	.string "Ein Infoblatt über TM.\p"
	.string "……\p"
	.string "Es gibt insgesamt 50 TM.\p"
	.string "Außerdem gibt es sieben VM, die\n"
	.string "mehrfach nutzbar sind.\p"
	.string "Silph Co.$"
#else
	.string "It's a pamphlet on TMs.\p"
	.string "… …\p"
	.string "There are fifty TMs in all.\p"
	.string "There are also seven HMs that\n"
	.string "can be used repeatedly.\p"
	.string "SILPH CO.$"
#endif

