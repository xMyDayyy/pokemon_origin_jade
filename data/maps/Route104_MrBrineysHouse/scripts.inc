Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_HOENN_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
#if GERMAN
	.string "Mr. Brack: Warte, Mädchen!\n"
	.string "Immer langsam, Pecko!$"
#else
	.string "MR. BRINEY: Hold on, lass!\n"
	.string "Wait up, PEEKO!$"
#endif

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
#if GERMAN
	.string "Hm? Du bist {PLAYER}{KUN}!\n"
	.string "Du hast meinen Liebling Pecko gerettet!\l"
	.string "Wir verdanken dir sehr viel!\p"
	.string "Wie bitte?\n"
	.string "Du möchtest mit mir segeln?\p"
	.string "Hmhm…\p"
	.string "Du musst einen Brief in Faustauhaven\n"
	.string "und ein Paket in Graphitport City\l"
	.string "abgeben?\p"
	.string "Da bist du aber gut beschäftigt!\p"
	.string "Aber deine Bitte ist überhaupt kein\n"
	.string "Problem für mich.\p"
	.string "Bei mir bist du richtig! Wir setzen\n"
	.string "Segel Richtung Faustauhaven!$"
#else
	.string "Hm? You're {PLAYER}{KUN}!\n"
	.string "You saved my darling PEEKO!\l"
	.string "We owe so much to you!\p"
	.string "What's that?\n"
	.string "You want to sail with me?\p"
	.string "Hmhm…\p"
	.string "You have a LETTER bound for DEWFORD\n"
	.string "and a package for SLATEPORT, then?\p"
	.string "Quite the busy life you must lead!\p"
	.string "But, certainly, what you're asking is\n"
	.string "no problem at all.\p"
	.string "You've come to the right man!\n"
	.string "We'll set sail for DEWFORD.$"
#endif

Route104_MrBrineysHouse_Text_SetSailForDewford:
#if GERMAN
	.string "Mr. Brack: Also, auf nach Faustauhaven!\p"
	.string "Anker gelichtet!\n"
	.string "Pecko, wir setzen Segel, mein Liebling!$"
#else
	.string "MR. BRINEY: DEWFORD it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"
#endif

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
#if GERMAN
	.string "Mr. Brack: Wirklich?\n"
	.string "Deine Besorgungen können warten?\p"
	.string "Lass dir Zeit. Ein Wort genügt und wir\n"
	.string "setzen Segel.$"
#else
	.string "MR. BRINEY: Is that so?\n"
	.string "Your deliveries can wait?\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail!$"
#endif

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
#if GERMAN
	.string "Mr. Brack: Ahoi! Ich weiß genau,\n"
	.string "was du jetzt sagen willst!\p"
	.string "Du musst einen Brief in Faustauhaven\n"
	.string "und ein Paket in Graphitport City\l"
	.string "abgeben.\p"
	.string "Nun, ich bin der richtige Mann für\n"
	.string "diesen Job!\p"
	.string "Dann segeln wir zuerst Richtung\n"
	.string "Faustauhaven.$"
#else
	.string "MR. BRINEY: Ahoy!\n"
	.string "I know exactly what you want to say!\p"
	.string "You're to deliver a LETTER to DEWFORD\n"
	.string "and a package to SLATEPORT.\p"
	.string "What you need me to do is no problem\n"
	.string "at all--I'm the man for the job!\p"
	.string "First, we'll set sail for DEWFORD.$"
#endif

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
#if GERMAN
	.string "Mr. Brack: Ahoi! Ich weiß genau,\n"
	.string "was du jetzt sagen willst!\p"
	.string "Du musst Kapt. Brigg in Graphitport City\n"
	.string "ein Paket bringen.\p"
	.string "Nun, ich bin der richtige Mann für\n"
	.string "diesen Job!\p"
	.string "Dann segeln wir zuerst Richtung\n"
	.string "Faustauhaven.$"
#else
	.string "MR. BRINEY: Ahoy!\n"
	.string "I know exactly what you want to say!\p"
	.string "You're to deliver a package to\n"
	.string "CAPT. STERN in SLATEPORT.\p"
	.string "What you need me to do is no problem\n"
	.string "at all--I'm the man for the job!\p"
	.string "First, we'll set sail for DEWFORD.$"
#endif

Route104_MrBrineysHouse_Text_WhereAreWeBound:
#if GERMAN
	.string "Mr. Brack: Ahoi! Für dich fahre ich\n"
	.string "jederzeit wieder raus!\p"
	.string "Nun, wo soll es hingehen?$"
#else
	.string "MR. BRINEY: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Now, my friend, where are we bound?$"
#endif

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
#if GERMAN
	.string "Mr. Brack: Wirklich?\n"
	.string "Nun, Pecko verdankt dir ihr Leben.\p"
	.string "Lass dir Zeit. Ein Wort genügt und wir\n"
	.string "setzen Segel.$"
#else
	.string "MR. BRINEY: Is that so?\n"
	.string "Well, PEEKO owes her life to you.\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail!$"
#endif

Route104_MrBrineysHouse_Text_Peeko:
#if GERMAN
	.string "Pecko: Pii piihyoro!$"
#else
	.string "PEEKO: Pii piihyoro!$"
#endif

