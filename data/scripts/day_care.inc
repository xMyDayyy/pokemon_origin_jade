Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
#if IS_HNS
	call_if_unset FLAG_RECEIVED_OVAL_CHARM, DayCare_EventScript_GiveOvalCharm
#endif
	release
	end

#if IS_HNS
@ Oval Charm with the first Day Care egg (Route 5, Route 34, Route 117).
@ See docs/origin_jade/DECISIONS.md, D-036.
DayCare_EventScript_GiveOvalCharm::
	msgbox DayCare_Text_OvalCharmFirstEgg, MSGBOX_DEFAULT
	giveitem ITEM_OVAL_CHARM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_OVAL_CHARM
	msgbox DayCare_Text_ExplainOvalCharm, MSGBOX_DEFAULT
	return
#endif

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	chooseboxmon SELECT_PC_MON_DAYCARE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
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
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	waitstate
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
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

Route117_Text_DoYouWantEgg:
#if GERMAN
	.string "Ach, du bist es!\p"
	.string "Wir haben deine Pokémon aufgezogen\n"
	.string "und wurden überrascht!\p"
	.string "Deine Pokémon haben nun ein Ei!\p"
	.string "Wir wissen nicht, wie das passiert\n"
	.string "ist, aber deine Pokémon haben es.\p"
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

Route117_Text_YourMonIsDoingFine:
#if GERMAN
	.string "Ach, du bist es! Schön, dich zu sehen.\n"
	.string "Deinem {STR_VAR_1} geht es sehr gut.$"
#else
	.string "Ah, it's you! Good to see you.\n"
	.string "Your {STR_VAR_1}'s doing fine.$"
#endif

Route117_Text_IllKeepIt:
#if GERMAN
	.string "Ich werde es behalten.$"
#else
	.string "Well then, I'll keep it.\n"
	.string "Thanks!$"
#endif

Route117_Text_YouHaveNoRoomForIt:
#if GERMAN
	.string "Du hast keinen Platz dafür… Komm\n"
	.string "wieder, wenn du Platz geschafft hast.$"
#else
	.string "You have no room for it…\n"
	.string "Come back when you've made room.$"
#endif

Route117_Text_ReceivedEgg:
#if GERMAN
	.string "{PLAYER} erhält das Ei vom\n"
	.string "Pensionsleiter.$"
#else
	.string "{PLAYER} received the EGG from\n"
	.string "the DAY-CARE MAN.$"
#endif

Route117_Text_TakeGoodCareOfIt:
#if GERMAN
	.string "Kümmere dich gut darum.$"
#else
	.string "Take good care of it.$"
#endif

Route117_Text_FriendlyWithOtherTrainersMon:
#if GERMAN
	.string "Übrigens, dein {STR_VAR_1} scheint sich\n"
	.string "gut mit dem {STR_VAR_3} von {STR_VAR_2} zu\l"
	.string "verstehen.\p"
	.string "Ich habe gesehen, wie sie einen Brief\n"
	.string "ausgetauscht haben…$"
#else
	.string "By the way, about your {STR_VAR_1},\n"
	.string "it seemed to be friendly with\l"
	.string "{STR_VAR_2}'s {STR_VAR_3}.\p"
	.string "I may even have seen it receiving\n"
	.string "a piece of MAIL.$"
#endif

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
#if GERMAN
	.string "Wenn du deine Pokémon abholen\n"
	.string "möchtest, sprich mit meiner Frau.$"
#else
	.string "If you want to pick up your POKéMON,\n"
	.string "have a word with my wife.$"
#endif

Route117_Text_YourMonsAreDoingFine:
#if GERMAN
	.string "Ah, du bist es! Deine Pokémon {STR_VAR_1}\n"
	.string "und {STR_VAR_2} entwickeln sich prächtig.$"
#else
	.string "Ah, it's you! Your {STR_VAR_1} and\n"
	.string "{STR_VAR_2} are doing fine.$"
#endif

Route117_Text_IWillKeepDoYouWantIt:
#if GERMAN
	.string "Ich werde es behalten.\n"
	.string "Oder möchtest du es haben?$"
#else
	.string "I really will keep it.\n"
	.string "You do want this, yes?$"
#endif

#if IS_HNS
DayCare_Text_OvalCharmFirstEgg:
#if GERMAN
	.string "Für deine erste erfolgreiche Zucht\n"
	.string "geben wir dir das hier noch dazu!$"
#else
	.string "This was your first successful\n"
	.string "breeding with us, so take this too!$"
#endif

DayCare_Text_ExplainOvalCharm:
#if GERMAN
	.string "Mit dem Ovalpin findet sich in der\n"
	.string "Pension öfter ein Ei.$"
#else
	.string "With the OVAL CHARM, EGGS turn up\n"
	.string "at the DAY CARE more often.$"
#endif
#endif

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
#if GERMAN
	.string "Ich bin die Pensionsleiterin.\p"
	.string "Wir ziehen Pokémon für dich auf.\p"
	.string "Sollen wir eins für dich aufziehen?$"
#else
	.string "I'm the DAY-CARE LADY.\p"
	.string "We can raise POKéMON for you.\p"
	.string "Would you like us to raise one?$"
#endif

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
#if GERMAN
	.string "Welches Pokémon sollen wir für\n"
	.string "dich aufziehen?$"
#else
	.string "Which POKéMON should we raise for\n"
	.string "you?$"
#endif

Route117_PokemonDayCare_Text_WellRaiseYourMon:
#if GERMAN
	.string "Fein, dann nehmen wir dein {STR_VAR_1}\n"
	.string "für eine Weile in Pflege.\p"
	.string "Schau später mal nach ihm.$"
#else
	.string "Fine, we'll raise your {STR_VAR_1}\n"
	.string "for a while.\p"
	.string "Come back for it later.$"
#endif

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
#if GERMAN
	.string "Wir können zwei deiner Pokémon nehmen.\n"
	.string "Möchtest du noch eins in Pflege geben?$"
#else
	.string "We can raise two of your POKéMON.\n"
	.string "Would you like us to raise one more?$"
#endif

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
#if GERMAN
	.string "Mein Mann hat dich schon gesucht.$"
#else
	.string "My husband was looking for you.$"
#endif

Route117_PokemonDayCare_Text_FineThenComeAgain:
#if GERMAN
	.string "Oh, gut.\n"
	.string "Komm bald wieder.$"
#else
	.string "Oh, fine, then.\n"
	.string "Come again.$"
#endif

Route117_PokemonDayCare_Text_NotEnoughMoney:
#if GERMAN
	.string "Du hast nicht genug Geld…$"
#else
	.string "You don't have enough money…$"
#endif

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
#if GERMAN
	.string "Möchtest du das andere auch wieder\n"
	.string "mitnehmen?$"
#else
	.string "Will you take back the other one,\n"
	.string "too?$"
#endif

Route117_PokemonDayCare_Text_ComeAgain:
#if GERMAN
	.string "Gut.\n"
	.string "Komm bald wieder.$"
#else
	.string "Fine.\n"
	.string "Come again.$"
#endif

Route117_PokemonDayCare_Text_GoodToSeeYou:
#if GERMAN
	.string "Ach, du bist es! Schön dich zu sehen.\n"
	.string "Deinen Pokémon kann es einfach nur gut\l"
	.string "gehen!$"
#else
	.string "Ah, it's you! Good to see you.\n"
	.string "Your POKéMON can only be doing good!$"
#endif

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
#if GERMAN
	.string "Dein {STR_VAR_1} ist um {STR_VAR_2} Level\n"
	.string "gewachsen.$"
#else
	.string "By level, your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2}.$"
#endif

Route117_PokemonDayCare_Text_YourTeamIsFull:
#if GERMAN
	.string "Dein Pokémon-Team ist vollzählig.\n"
	.string "Schaffe Platz und komm dann wieder.$"
#else
	.string "Your POKéMON team is full.\n"
	.string "Make room, then come see me.$"
#endif

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
#if GERMAN
	.string "Welches Pokémon möchtest du abholen?$"
#else
	.string "Which POKéMON will you take back?$"
#endif

Route117_PokemonDayCare_Text_ItWillCostX:
#if GERMAN
	.string "Wenn du dein {STR_VAR_1} mitnehmen\n"
	.string "willst, kostet das {STR_VAR_2}¥.$"
#else
	.string "If you want your {STR_VAR_1} back,\n"
	.string "it will cost ¥{STR_VAR_2}.$"
#endif

Route117_PokemonDayCare_Text_HeresYourMon:
#if GERMAN
	.string "Sehr schön!\n"
	.string "Hier ist dein Pokémon!$"
#else
	.string "Perfect!\n"
	.string "Here's your POKéMON.$"
#endif

Route117_PokemonDayCare_Text_TookBackMon:
#if GERMAN
	.string "{PLAYER} hat {STR_VAR_1} von der\n"
	.string "Pensionsleiterin zurückerhalten.$"
#else
	.string "{PLAYER} took back {STR_VAR_1} from\n"
	.string "the DAY-CARE LADY.$"
#endif

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
#if GERMAN
	.string "Oh! Du hast aber nur ein Pokémon.\p"
	.string "Komm einfach später wieder.$"
#else
	.string "Oh? But you have just one\n"
	.string "POKéMON.\p"
	.string "Come back another time.$"
#endif

Route117_PokemonDayCare_Text_TakeYourMonBack:
#if GERMAN
	.string "Möchtest du dein Pokémon wieder\n"
	.string "mitnehmen?$"
#else
	.string "Will you take your POKéMON back?$"
#endif

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
#if GERMAN
	.string "Wenn du das Pokémon hier lässt,\n"
	.string "womit willst du denn dann kämpfen?\p"
	.string "Komm einfach später wieder.$"
#else
	.string "If you leave me that POKéMON,\n"
	.string "what will you battle with?\p"
	.string "Come back another time.$"
#endif

Text_EggHatchHuh:
#if GERMAN
	.string "Wie?$"
#else
	.string "Huh?$"
#endif

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
#if GERMAN
	.string "Bitte?\n"
	.string "Aber, aber…\p"
	.string "Wenn du das Pokémon bei mir lässt, dann\n"
	.string "hast du ja nur noch ein einziges bei dir!\p"
	.string "Fang doch einfach ein paar Pokémon,\n"
	.string "dann sehen wir weiter.$"
#else
	.string "Huh?\n"
	.string "Now, now.\p"
	.string "If you leave that POKéMON with\n"
	.string "me, you'll be left with just one.\p"
	.string "You will be better off if you catch\n"
	.string "some more, I dare say.$"
#endif
