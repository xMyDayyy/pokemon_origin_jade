MossdeepCity_StevensHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
	.byte 0

MossdeepCity_StevensHouse_OnLoad:
	call_if_unset FLAG_IS_HOENN_CHAMPION, MossdeepCity_StevensHouse_EventScript_HideStevensNote
	end

MossdeepCity_StevensHouse_EventScript_HideStevensNote::
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, TRUE
	return

MossdeepCity_StevensHouse_OnTransition:
	call_if_eq VAR_STEVENS_HOUSE_STATE, 2, MossdeepCity_StevensHouse_EventScript_SetStevenPos
	end

MossdeepCity_StevensHouse_EventScript_SetStevenPos::
	setobjectxyperm LOCALID_STEVENS_HOUSE_STEVEN, 6, 5
	setobjectmovementtype LOCALID_STEVENS_HOUSE_STEVEN, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_StevensHouse_OnFrame:
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
	.2byte 0

MossdeepCity_StevensHouse_EventScript_StevenGivesDive::
	lockall
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
	waitmovement 0
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
	giveitem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
#if !IS_HNS
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
#endif
	closemessage
	delay 20
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_STEVENS_HOUSE_STATE, 2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_StevenApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MossdeepCity_StevensHouse_Movement_StevenReturn:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MossdeepCity_StevensHouse_EventScript_BeldumPokeball::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_LeaveBeldum
	goto MossdeepCity_StevensHouse_EventScript_GiveBeldum
	end

MossdeepCity_StevensHouse_EventScript_LeaveBeldum::
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_GiveBeldum::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_StevensHouse_EventScript_SendBeldumParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_StevensHouse_EventScript_SendBeldumPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumParty::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumPC::
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	end

MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM
	removeobject LOCALID_STEVENS_HOUSE_BALL
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_StevensHouse_Text_ObtainedBeldum
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_ReceivedBeldum::
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_RockDisplay::
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_Steven::
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
	end

MossdeepCity_StevensHouse_EventScript_Letter::
	lockall
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
	releaseall
	end

@ Unused, leftover from RS
MossdeepCity_StevensHouse_EventScript_DiveItemBall::
	finditem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	end

MossdeepCity_StevensHouse_Text_YouveEarnedHMDive:
#if GERMAN
	.string "Troy: {PLAYER}{KUN}?\p"
	.string "Ja, das ist mein Zuhause. Peinlich,\n"
	.string "wie kahl die Räume hier sind.\p"
	.string "Oh, hier, nimm diese VM.\p"
	.string "Sie enthält Taucher. Ich habe das\n"
	.string "meinen Pokémon schon beigebracht.$"
#else
	.string "STEVEN: {PLAYER}{KUN}…\p"
	.string "As you can see, there's not much here,\n"
	.string "but this is my home.\p"
	.string "Thank you for all that you've done.\p"
	.string "This is my token of appreciation.\n"
	.string "It's the HIDDEN MACHINE DIVE.\p"
	.string "No need to be shy--you've earned\n"
	.string "this HM.$"
#endif

MossdeepCity_StevensHouse_Text_ExplainDive:
#if GERMAN
	.string "Troy: Wenn du Surfer einsetzt und über\n"
	.string "das Meer gleitest, wirst du dunkle\l"
	.string "Stellen im Wasser bemerken können.\p"
	.string "Setze hier Taucher ein und du kannst\n"
	.string "hinabtauchen bis zum Meeresboden.\p"
	.string "Wenn du wieder auftauchen möchtest,\n"
	.string "setze ebenfalls Taucher ein.\p"
	.string "An manchen Stellen ist das Auftauchen\n"
	.string "allerdings nicht möglich.$"
#else
	.string "STEVEN: While you're using SURF, you\n"
	.string "should notice dark patches of water.\p"
	.string "Use DIVE if you come to deep water\n"
	.string "like it. You'll drop to the seafloor.\p"
	.string "When you want to come back up, use\n"
	.string "DIVE again.\p"
	.string "In some places, it won't be possible\n"
	.string "for you to surface, though.$"
#endif

MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis:
#if GERMAN
	.string "Troy: Zwischen Moosbach City und\n"
	.string "Xeneroville gibt es eine\l"
	.string "Unterwasserhöhle.\p"
	.string "Die, die Kapt. Brigg auf seiner\n"
	.string "Expedition entdeckt hat, weißt du.$"
#else
	.string "STEVEN: Apparently, there's an\n"
	.string "underwater cavern between\l"
	.string "MOSSDEEP and SOOTOPOLIS.\p"
	.string "You know, the one that CAPT. STERN\n"
	.string "found in his submarine.$"
#endif

MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum:
#if GERMAN
	.string "{PLAYER} überprüft den Pokéball.\p"
	.string "Er enthält das Pokémon Tanhel.\p"
	.string "Den Pokéball nehmen?$"
#else
	.string "{PLAYER} checked the POKé BALL.\p"
	.string "It contained the POKéMON\n"
	.string "BELDUM.\p"
	.string "Take the POKé BALL?$"
#endif

MossdeepCity_StevensHouse_Text_ObtainedBeldum:
#if GERMAN
	.string "{PLAYER} hat Tanhel erhalten.$"
#else
	.string "{PLAYER} obtained a BELDUM.$"
#endif

@ Unused
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon:
#if GERMAN
	.string "Es ist kein Platz für ein weiteres\n"
	.string "Pokémon vorhanden.$"
#else
	.string "There is no space for another POKéMON.$"
#endif

MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas:
#if GERMAN
	.string "{PLAYER} legt den Pokéball zurück.$"
#else
	.string "{PLAYER} left the POKé BALL where\n"
	.string "it was.$"
#endif

MossdeepCity_StevensHouse_Text_LetterFromSteven:
#if GERMAN
	.string "Das ist ein Brief.\p"
	.string "\n"
	.string "… … … … … …\p"
	.string "An {PLAYER}{KUN}…\p"
	.string "Ich habe mich dazu entschlossen, etwas\n"
	.string "Mentaltraining zu machen und auf der\l"
	.string "Straße zu trainieren.\p"
	.string "Ich werde für einige Zeit nicht nach\n"
	.string "Hause kommen.\p"
	.string "Ich möchte dich um einen Gefallen\n"
	.string "bitten.\p"
	.string "Ich möchte, dass du den Pokéball\n"
	.string "nimmst, der auf dem Tisch liegt.\p"
	.string "Er enthält mein Lieblings-Pokémon\n"
	.string "Tanhel.\p"
	.string "Ich verlasse mich auf dich.\p"
	.string "Mögen wir uns eines Tages wiedersehen.\n"
	.string "\p"
	.string "Troy Trumm$"
#else
	.string "It's a letter.\p"
	.string "… … … … … …\p"
	.string "To {PLAYER}{KUN}…\p"
	.string "I've decided to do a little soul-\n"
	.string "searching and train on the road.\p"
	.string "I don't plan to return home for some\n"
	.string "time.\p"
	.string "I have a favor to ask of you.\p"
	.string "I want you to take the POKé BALL on\n"
	.string "the desk.\p"
	.string "Inside it is a BELDUM, my favorite\n"
	.string "POKéMON.\p"
	.string "I'm counting on you.\p"
	.string "May our paths cross someday.\p"
	.string "STEVEN STONE$"
#endif

MossdeepCity_StevensHouse_Text_CollectionOfRareRocks:
#if GERMAN
	.string "Eine Kollektion seltener Steine,\n"
	.string "zusammengetragen von Troy.$"
#else
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by STEVEN.$"
#endif

#if IS_HNS
@ Unused.
Text_HnsDiveLicense:
#if GERMAN
	.string "{PLAYER} erhält die Lizenz für\n"
	.string "Taucher!$"
#else
	.string "{PLAYER} received the licence for\n"
	.string "DIVE!$"
#endif

@ Unused.
Text_HnsStevenGiveDive:
#if GERMAN
	.string "Troy: {PLAYER}?\p"
	.string "Ja, das ist mein Zuhause. Peinlich,\n"
	.string "wie kahl die Räume hier sind.\p"
	.string "Hier, nimm diese VM. Auf dem Festland\n"
	.string "wirst du sie nie gebraucht haben.\p"
	.string "Einsetzen darfst du sie in Hoenn aber\n"
	.string "erst mit dem Mentalorden.\p"
	.string "Die Arena hier in Moosbach wartet\n"
	.string "schon auf dich.$"
#else
	.string "STEVEN: {PLAYER}?\p"
	.string "As you can see, there's not much here,\n"
	.string "but this is my home.\p"
	.string "Here, take this HM. You'll never have\n"
	.string "needed it on the mainland.\p"
	.string "In HOENN, though, you may only use it\n"
	.string "once you hold the MIND BADGE.\p"
	.string "The GYM here in MOSSDEEP is already\n"
	.string "waiting for you.$"
#endif
#endif
