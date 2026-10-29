Route5_PokemonDayCare_Frlg_MapScripts::
	.byte 0

Route5_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route5_PokemonDayCare_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route5_PokemonDayCare_TwoMonsInDaycare
	msgbox DayCare_Text_WouldYouLikeUsToRaiseMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_GiveMonToRaise
	msgbox DayCare_Text_FineThenComeAgain
	release
	end

Route5_PokemonDayCare_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route5_PokemonDayCare_OnlyOneMonInParty
	msgbox DayCare_Text_WhichMonShouldWeRaise
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Route5_PokemonDayCare_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route5_PokemonDayCare_OnlyOneAliveMonInParty
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox DayCare_Text_WellRaiseYourMon
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_CanRaiseOneMore
	release
	end

Route5_PokemonDayCare_ComeAgain::
	msgbox DayCare_Text_ComeAgain
	release
	end

Route5_PokemonDayCare_CanRaiseOneMore::
	msgbox DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_GiveMonToRaise
	goto Route5_PokemonDayCare_ComeAgain
	end

Route5_PokemonDayCare_OnlyOneMonInParty::
	msgbox DayCare_Text_YouHaveJustOneMon
	release
	end

Route5_PokemonDayCare_OnlyOneAliveMonInParty::
	msgbox DayCare_Text_WhatWillYouBattleWith
	release
	end

Route5_PokemonDayCare_EggWaiting::
	msgbox DayCare_Text_HusbandWasLookingForYou
	release
	end

Route5_PokemonDayCare_MonHasGrownXLevels::
	msgbox DayCare_Text_YourMonHasGrownXLevels
	return

Route5_PokemonDayCare_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route5_PokemonDayCare_MonHasGrownXLevels
	return

Route5_PokemonDayCare_OneMonInDaycare::
	msgbox DayCare_Text_GoodToSeeYou
	setvar VAR_0x8004, 0
	call Route5_PokemonDayCare_DisplayLevelsGained
	msgbox DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_GiveMonToRaise
	msgbox DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_TryRetrieveMon
	goto Route5_PokemonDayCare_ComeAgain
	end

Route5_PokemonDayCare_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route5_PokemonDayCare_NoRoomInParty
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route5_PokemonDayCare_ComeAgain
	goto Route5_PokemonDayCare_CostPrompt
	end

Route5_PokemonDayCare_CostPrompt::
	special GetDaycareCost
	msgbox DayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_CheckEnoughMoney
	goto Route5_PokemonDayCare_ComeAgain
	end

Route5_PokemonDayCare_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, TRUE, Route5_PokemonDayCare_RetrieveMon
	msgbox DayCare_Text_NotEnoughMoney
	release
	end

Route5_PokemonDayCare_RetrieveMon::
	applymovement LOCALID_ROUTE5_DAYCARE_WOMAN, Route5_PokemonDayCare_Movement_RetrieveMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox DayCare_Text_HeresYourMon
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox DayCare_Text_TookBackMon
	call EventScript_RestorePrevTextColor
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_AskRetrieveOtherMon
	goto Route5_PokemonDayCare_ComeAgain
	end

Route5_PokemonDayCare_AskRetrieveOtherMon::
	msgbox DayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_TryRetrieveMon
	goto Route5_PokemonDayCare_ComeAgain
	end

Route5_PokemonDayCare_NoRoomInParty::
	msgbox DayCare_Text_YourPartyIsFull
	release
	end

Route5_PokemonDayCare_Movement_RetrieveMon::
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_left
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
Route5_PokemonDayCare_EventScript_UnusedEnd::
	end

Route5_PokemonDayCare_TwoMonsInDaycare::
	msgbox DayCare_Text_GoodToSeeYou
	setvar VAR_0x8004, 0
	call Route5_PokemonDayCare_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route5_PokemonDayCare_DisplayLevelsGained
	msgbox DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_TryRetrieveMon
	msgbox DayCare_Text_ComeAgain
	release
	end

@ Unused
Route5_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	waitstate
	goto_if_eq VAR_RESULT, 2, Route5_PokemonDayCare_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox DayCare_Text_HeresYourMon
	msgbox DayCare_Text_ComeAgain
	release
	end
