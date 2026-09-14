Route34_DayCare_hns_MapScripts::
	.byte 0

Route34_DayCare_Bookshelf1::
	lock
	msgbox Route34_DayCare_Text_Bookshelf1, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE1_WINDOW
	release
	end

Route34_DayCare_Bookshelf2::
	lock
	msgbox Route34_DayCare_Text_Bookshelf2, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE2_WINDOW
	release
	end

Route34_DayCare_Bookshelf3::
	lock
	msgbox Route34_DayCare_Text_Bookshelf3, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE3_WINDOW
	release
	end

Route34_DayCare_Bookshelf4::
	lock
	msgbox Route34_DayCare_Text_Bookshelf4, MSGBOX_AUTOCLOSE
	helpwindow HELP_DAYCARE4_WINDOW
	release
	end

Route34_DayCare_Text_Bookshelf1:
#if GERMAN
	.string "Eine Enzyklopädie über Baby-Pokémon.\p"
	.string "Teil 1: Über Fähigkeiten.$"
#else
	.string "A BABY POKéMON encyclopedia!\p"
	.string "VOLUME 1: ALL ABOUT ABILITIES$"
#endif

Route34_DayCare_Text_Bookshelf2:
#if GERMAN
	.string "Eine Enzyklopädie über Baby-Pokémon.\p"
	.string "Teil 2: Typen.$"
#else
	.string "A BABY POKéMON encyclopedia!\p"
	.string "VOLUME 2: TYPICAL TYPES$"
#endif

Route34_DayCare_Text_Bookshelf3:
#if GERMAN
	.string "Eine Enzyklopädie über Baby-Pokémon.\p"
	.string "Teil 3: Geräusche von Babys.$"
#else
	.string "A BABY POKéMON encyclopedia!\p"
	.string "VOLUME 3: BABIES' CRIES$"
#endif

Route34_DayCare_Text_Bookshelf4:
#if GERMAN
	.string "Eine Enzyklopädie über Baby-Pokémon.\p"
	.string "Teil 4: Süße Eigenheiten.$"
#else
	.string "A BABY POKéMON encyclopedia!\p"
	.string "VOLUME 4: ADORABLE ACTIONS$"
#endif

Route34_DayCare_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ODD_EGG, Route34_DayCare_EventScript_ClerkAfter
	msgbox Route34_DayCare_Text_ClerkBefore, MSGBOX_DEFAULT
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_ClerkPartyFull
	msgbox Route34_DayCare_Text_ClerkQuestion, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
	setvar VAR_0x8005, 0
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	switch VAR_RESULT
	case 0, Route34_DayCare_EventScript_ClerkRejection
	case 1, Route34_DayCare_EventScript_GivePichu
	case 2, Route34_DayCare_EventScript_GiveCleffa
	case 3, Route34_DayCare_EventScript_GiveIgglybuff
	case 4, Route34_DayCare_EventScript_GiveTyrogue
	case 5, Route34_DayCare_EventScript_GiveSmoochum
	case 6, Route34_DayCare_EventScript_GiveElekid
	case 7, Route34_DayCare_EventScript_GiveMagby
	case 8, Route34_DayCare_EventScript_GiveMantyke
	case 9, Route34_DayCare_EventScript_GiveBonsly
	case 10, Route34_DayCare_EventScript_GiveHappiny
	case 11, Route34_DayCare_EventScript_GiveMimeJr
	closemessage
	release
	end

Route34_DayCare_EventScript_GivePichu::
	giveoddegg 1
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveCleffa::
	giveoddegg 2
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveIgglybuff::
	giveoddegg 3
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveTyrogue::
	giveoddegg 4
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveSmoochum::
	giveoddegg 5
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveElekid::
	giveoddegg 6
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMagby::
	giveoddegg 7
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMantyke::
	giveoddegg 8
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveBonsly::
	giveoddegg 9
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveHappiny::
	giveoddegg 10
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMimeJr::
	giveoddegg 11
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_Clerk_GaveEgg::
	msgbox Route34_DayCare_Text_TakeCare, MSGBOX_DEFAULT
	closemessage
	delay 30
	setflag FLAG_RECEIVED_ODD_EGG
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route34_DayCare_Text_ReceivedOddEgg
	waitfanfare
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkPartyFull::
	msgbox Route34_DayCare_Text_ClerkNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkRejection::
	msgbox Route34_DayCare_Text_Rejection, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkAfter::
	msgbox Route34_DayCare_Text_ClerkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_Text_ClerkBefore:
#if GERMAN
	.string "Ich bin der Sohn des Pensions-\n"
	.string "Paars.\p"
	.string "Ein seltsames Ei wurde bei einem Trainer\n"
	.string "gefunden, doch er wollte es nicht…\p"
	.string "Ich könnte es dir geben…\n"
	.string "Aber wie kann ich wissen, dass du gut\l"
	.string "darauf aufpasst?$"
#else
	.string "I'm the DAY-CARE couple's son.\p"
	.string "An ODD EGG was found with a TRAINER's\n"
	.string "POKéMON, but they didn't want it...\p"
	.string "I'd offer it to you...\n"
	.string "But how can I know you'll take good\l"
	.string "care of it?$"
#endif

Route34_DayCare_Text_ClerkNoRoom:
#if GERMAN
	.string "Sieht so aus, als könntest du kein\n"
	.string "weiteres Pokémon tragen.$"
#else
	.string "It looks like you can't carry another\n"
	.string "POKéMON anyway.$"
#endif

Route34_DayCare_Text_ClerkQuestion:
#if GERMAN
	.string "Beantworte mir diese Frage.\n"
	.string "Was hältst du von diesem Ei?$"
#else
	.string "Answer this question for me.\n"
	.string "How do you feel about this ODD EGG?$"
#endif

Route34_DayCare_Text_Rejection:
#if GERMAN
	.string "Hmm, ich glaube, dieses Ei ist nicht für\n"
	.string "dich.\p"
	.string "Es wäre unverantwortlich, ein\n"
	.string "kostbares Ei an jemanden zu geben, der\l"
	.string "sich noch nicht\p"
	.string "genug mit Baby-Pokémon auskennt!$"
#else
	.string "Hmm, I think this EGG isn't for you.\p"
	.string "It would be irresponsible of me to\n"
	.string "give out a precious EGG like this\l"
	.string "to someone who isn't as well-read\l"
	.string "on the subject of baby POKéMON!$"
#endif

Route34_DayCare_Text_ReceivedOddEgg:
#if GERMAN
	.string "{PLAYER} erhielt das Seltsame Ei.$"
#else
	.string "{PLAYER} Received the ODD EGG.$"
#endif

Route34_DayCare_Text_TakeCare:
#if GERMAN
	.string "Ich wusste, dass du der richtige\n"
	.string "Trainer dafür bist. Pass gut auf es auf!$"
#else
	.string "I knew you were the right trainer\n"
	.string "for the job. Take good care of it!$"
#endif

Route34_DayCare_Text_ClerkAfter:
#if GERMAN
	.string "Wir sehen hier oft solche Eier.\p"
	.string "Doch bei diesem war etwas anders.$"
#else
	.string "We see a lot of those eggs around\n"
	.string "here.\p"
	.string "Something was different about that\n"
	.string "one, though.$"
#endif

Route34_DayCare_EventScript_Ditto::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DITTO, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_Ditto, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34_DayCare_Text_Ditto:
#if GERMAN
	.string "Ditto: Tto!$"
#else
	.string "DITTO: Tto!$"
#endif

Route34_EventScript_DaycareMan::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPartyLimitChallengeActive @ tx_randomizer_and_challenges
	goto_if_eq VAR_RESULT, TRUE, Route34_DayCare_EventScript_ClosedForChallenge
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_EventScript_CheckOnTwoMons
	msgbox Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareEggWaiting::
	msgbox Route34_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route34_EventScript_DaycareAcceptEgg::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, VAR_0x8004, Route34_EventScript_DaycareReceiveEgg
	msgbox Route34_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareReceiveEgg::
	message Route34_Text_ReceivedEgg
	playfanfare MUS_HG_OBTAIN_EGG
	waitfanfare
	waitbuttonpress
	msgbox Route34_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route34_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route34_EventScript_MonReceivedMail
	return

Route34_EventScript_MonReceivedMail::
	msgbox Route34_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route34_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_DayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPartyLimitChallengeActive @ tx_randomizer_and_challenges
	goto_if_eq VAR_RESULT, TRUE, Route34_DayCare_EventScript_ClosedForChallenge
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_DayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_DayCare_EventScript_TwoMonsInDaycare
	msgbox Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route34_DayCare_EventScript_OnlyTwoAliveMons
	msgbox Route34_DayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route34_DayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route34_DayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CanRaiseOneMore
	release
	end

Route34_DayCare_EventScript_ComeAgain::
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_CanRaiseOneMore::
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_ClosedForChallenge::
	msgbox Route34_DayCare_Text_ClosedForChallenge, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Text_ClosedForChallenge:
	.string "Sorry, we can't look after your\n"
	.string "POKéMON during a party limit\l"
	.string "challenge!$"

Route34_DayCare_EventScript_OnlyOneMon::
	msgbox Route34_DayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyOneAliveMon::
	msgbox Route34_DayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route34_DayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_EggWaiting::
	msgbox Route34_DayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route34_DayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route34_DayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route34_DayCare_EventScript_YourMonHasGrownXLevels
	return

Route34_DayCare_EventScript_OneMonInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_TryRetrieveMon::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_CostPrompt
	end

Route34_DayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route34_DayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_CheckEnoughMoney
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_RetrieveMon
	msgbox Route34_DayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_RetrieveMon::
	@applymovement LOCALID_DAYCARE_LADY, Route34_DayCare_Movement_RetrieveDaycareMon
	@waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route34_DayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_AskRetrieveOtherMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route34_DayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_NoRoom::
	msgbox Route34_DayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route34_DayCare_EventScript_UnusedEnd::
	end

Route34_DayCare_EventScript_TwoMonsInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon:
#if GERMAN
	.string "Ich bin der Pensionsleiter.\p"
	.string "Ich kümmere mich um die wertvollen\n"
	.string "Pokémon der Trainer.\p"
	.string "Wenn ich eines deiner Pokémon auf-\n"
	.string "ziehen soll, sprich mit meiner Frau.$"
#else
	.string "I'm the DAY-CARE MAN.\p"
	.string "I help take care of the precious\n"
	.string "POKéMON of TRAINERS.\p"
	.string "If you'd like me to raise your POKéMON,\n"
	.string "have a word with my wife.$"
#endif

Route34_Text_DoYouWantEgg:
#if GERMAN
	.string "Ach, du bist es!\p"
	.string "Wir haben deine Pokémon aufgezogen\n"
	.string "und sind ganz schön überrascht!\p"
	.string "Deine Pokémon haben nun ein Ei!\p"
	.string "Wir wissen nicht, wie das passiert\n"
	.string "ist, aber jetzt ist es da.\p"
	.string "Möchtest du es haben?$"
#else
	.string "Ah, it's you!\p"
	.string "We were raising your POKéMON,\n"
	.string "and my goodness, were we surprised!\p"
	.string "Your POKéMON had an EGG!\p"
	.string "We don't know how it got there,\n"
	.string "but your POKéMON had it.\p"
	.string "You do want it, yes?$"
#endif

Route34_Text_YourMonIsDoingFine:
#if GERMAN
	.string "Ach, du bist es! Schön, dich zu sehen.\n"
	.string "Deinem {STR_VAR_1} geht es sehr gut.$"
#else
	.string "Ah, it's you! Good to see you.\n"
	.string "Your {STR_VAR_1}'s doing fine.$"
#endif

Route34_Text_IllKeepIt:
#if GERMAN
	.string "Na dann, ich behalte es.\n"
	.string "Danke!$"
#else
	.string "Well then, I'll keep it.\n"
	.string "Thanks!$"
#endif

Route34_Text_YouHaveNoRoomForIt:
#if GERMAN
	.string "Du hast keinen Platz dafür… komm\n"
	.string "wieder, wenn du Platz geschaffen hast.$"
#else
	.string "You have no room for it…\n"
	.string "Come back when you've made room.$"
#endif

Route34_Text_ReceivedEgg:
#if GERMAN
	.string "{PLAYER} erhält das Ei vom\n"
	.string "Pensionsleiter.$"
#else
	.string "{PLAYER} received the EGG from\n"
	.string "the DAY-CARE MAN.$"
#endif

Route34_Text_TakeGoodCareOfIt:
#if GERMAN
	.string "Pass gut auf es auf.$"
#else
	.string "Take good care of it.$"
#endif

Route34_Text_FriendlyWithOtherTrainersMon:
#if GERMAN
	.string "Übrigens, dein {STR_VAR_1} war freundlich\n"
	.string "zu {STR_VAR_2}s {STR_VAR_3}.\p"
	.string "Ich habe sogar gesehen, wie es\n"
	.string "Post bekam.$"
#else
	.string "By the way, about your {STR_VAR_1},\n"
	.string "it seemed to be friendly with\l"
	.string "{STR_VAR_2}'s {STR_VAR_3}.\p"
	.string "I may even have seen it receiving\n"
	.string "a piece of MAIL.$"
#endif

@ Unused
Route34_Text_SeeWifeIfYouWantToPickUpMon:
#if GERMAN
	.string "Wenn du dein Pokémon abholen willst,\n"
	.string "sprich mit meiner Frau.$"
#else
	.string "If you want to pick up your POKéMON,\n"
	.string "have a word with my wife.$"
#endif

Route34_Text_YourMonsAreDoingFine:
#if GERMAN
	.string "Ah, du bist es! Deine Pokémon {STR_VAR_1}\n"
	.string "und {STR_VAR_2} entwickeln sich prächtig.$"
#else
	.string "Ah, it's you! Your {STR_VAR_1} and\n"
	.string "{STR_VAR_2} are doing fine.$"
#endif

Route34_Text_IWillKeepDoYouWantIt:
#if GERMAN
	.string "Dann werde ich es behalten.\n"
	.string "Oder möchtest du es doch haben?$"
#else
	.string "I really will keep it.\n"
	.string "You do want this, yes?$"
#endif

Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon:
#if GERMAN
	.string "Ich bin die Pensionsleiterin.\n"
	.string "Wir ziehen Pokémon für dich auf.\p"
	.string "Sollen wir eines aufziehen?$"
#else
	.string "I'm the DAY-CARE LADY.\p"
	.string "We can raise POKéMON for you.\p"
	.string "Would you like us to raise one?$"
#endif

Route34_DayCare_Text_WhichMonShouldWeRaise:
#if GERMAN
	.string "Welches Pokémon sollen wir für dich\n"
	.string "aufziehen?$"
#else
	.string "Which POKéMON should we raise for\n"
	.string "you?$"
#endif

Route34_DayCare_Text_WellRaiseYourMon:
#if GERMAN
	.string "Fein, dann nehmen wir dein {STR_VAR_1}\n"
	.string "für eine Weile in Pflege.\p"
	.string "Schau später mal nach ihm.$"
#else
	.string "Fine, we'll raise your {STR_VAR_1}\n"
	.string "for a while.\p"
	.string "Come back for it later.$"
#endif

Route34_DayCare_Text_WeCanRaiseOneMore:
#if GERMAN
	.string "Wir können zwei deiner Pokémon\n"
	.string "aufziehen.\l"
	.string "Möchtest du, dass wir noch eins\p"
	.string "aufziehen?$"
#else
	.string "We can raise two of your POKéMON.\n"
	.string "Would you like us to raise one more?$"
#endif

Route34_DayCare_Text_HusbandWasLookingForYou:
#if GERMAN
	.string "Mein Mann hat nach dir gesucht.$"
#else
	.string "My husband was looking for you.$"
#endif

Route34_DayCare_Text_FineThenComeAgain:
#if GERMAN
	.string "Oh, gut.\n"
	.string "Komm bald wieder.$"
#else
	.string "Oh, fine, then.\n"
	.string "Come again.$"
#endif

Route34_DayCare_Text_NotEnoughMoney:
#if GERMAN
	.string "Du hast nicht genug Geld.$"
#else
	.string "You don't have enough money…$"
#endif

Route34_DayCare_Text_TakeOtherOneBackToo:
#if GERMAN
	.string "Willst du das andere Pokémon auch\n"
	.string "zurücknehmen?$"
#else
	.string "Will you take back the other one,\n"
	.string "too?$"
#endif

Route34_DayCare_Text_ComeAgain:
#if GERMAN
	.string "Oh, gut.\n"
	.string "Komm bald wieder.$"
#else
	.string "Fine.\n"
	.string "Come again.$"
#endif

Route34_DayCare_Text_GoodToSeeYou:
#if GERMAN
	.string "Ah, du bist es! Schön dich zu sehen.\n"
	.string "Deinem Pokémon geht es sicher gut.$"
#else
	.string "Ah, it's you! Good to see you.\n"
	.string "Your POKéMON can only be doing good!$"
#endif

Route34_DayCare_Text_YourMonHasGrownXLevels:
#if GERMAN
	.string "Dein {STR_VAR_1} ist um {STR_VAR_2} Level\n"
	.string "gewachsen.$"
#else
	.string "By level, your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2}.$"
#endif

Route34_DayCare_Text_YourTeamIsFull:
#if GERMAN
	.string "Dein Pokémon-Team ist vollzählig.\n"
	.string "Schaffe Platz und komm dann wieder.$"
#else
	.string "Your POKéMON team is full.\n"
	.string "Make room, then come see me.$"
#endif

@ Unused
Route34_DayCare_Text_TakeBackWhichMon:
#if GERMAN
	.string "Welches Pokémon willst du\n"
	.string "zurücknehmen?$"
#else
	.string "Which POKéMON will you take back?$"
#endif

Route34_DayCare_Text_ItWillCostX:
#if GERMAN
	.string "Wenn du dein {STR_VAR_1} mitnehmen\n"
	.string "willst, kostet das {STR_VAR_2} $.$"
#else
	.string "If you want your {STR_VAR_1} back,\n"
	.string "it will cost ¥{STR_VAR_2}.$"
#endif

Route34_DayCare_Text_HeresYourMon:
#if GERMAN
	.string "Perfekt! Hier ist dein Pokémon.$"
#else
	.string "Perfect!\n"
	.string "Here's your POKéMON.$"
#endif

Route34_DayCare_Text_TookBackMon:
#if GERMAN
	.string "{PLAYER} hat {STR_VAR_1} von der\n"
	.string "Pensionsleiterin zurückerhalten.$"
#else
	.string "{PLAYER} took back {STR_VAR_1} from\n"
	.string "the DAY-CARE LADY.$"
#endif

Route34_DayCare_Text_YouHaveJustOneMon:
#if GERMAN
	.string "Oh? Du hast nur ein Pokémon.\p"
	.string "Komm ein anderes Mal wieder.$"
#else
	.string "Oh? But you have just one\n"
	.string "POKéMON.\p"
	.string "Come back another time.$"
#endif

Route34_DayCare_Text_TakeYourMonBack:
#if GERMAN
	.string "Willst du dein Pokémon zurückhaben?$"
#else
	.string "Will you take your POKéMON back?$"
#endif

Route34_DayCare_Text_WhatWillYouBattleWith:
#if GERMAN
	.string "Wenn du das Pokémon hierlässt,\n"
	.string "womit willst du denn dann kämpfen?\p"
	.string "Komm einfach später wieder.$"
#else
	.string "If you leave me that POKéMON,\n"
	.string "what will you battle with?\p"
	.string "Come back another time.$"
#endif

Route34_DayCare_Text_YoullBeLeftWithJustOne:
#if GERMAN
	.string "Wie bitte?\n"
	.string "Aber, aber…\p"
	.string "Wenn du das Pokémon bei mir lässt, dann\n"
	.string "hast du ja nur noch ein einziges bei dir!\p"
	.string "Fange doch einfach ein paar Pokémon,\n"
	.string "dann sehen wir weiter.$"
#else
	.string "Huh?\n"
	.string "Now, now.\p"
	.string "If you leave that POKéMON with\n"
	.string "me, you'll be left with just one.\p"
	.string "You will be better off if you catch\n"
	.string "some more, I dare say.$"
#endif
