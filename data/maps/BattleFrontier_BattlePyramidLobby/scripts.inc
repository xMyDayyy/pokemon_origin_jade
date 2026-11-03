BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
#if GERMAN
	.string "Hier wird der Mut der Trainer auf die\n"
	.string "Probe gestellt!\p"
	.string "Willkommen in der Kampfpyramide!\p"
	.string "Ich begleite dich bei deinen\n"
	.string "Herausforderungen.$"
#else
	.string "Where the courage of TRAINERS\n"
	.string "is put to the test!\p"
	.string "Welcome to the BATTLE PYRAMID!\p"
	.string "I am your guide to\n"
	.string "the Battle Quest.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
#if GERMAN
	.string "Besitzt du den Mut, dich der Kampf-\n"
	.string "forschung-Herausforderung zu stellen?$"
#else
	.string "Have you the courage to embark on\n"
	.string "the Battle Quest challenge?$"
#endif

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
#if GERMAN
	.string "Wir freuen uns auf deine nächste\n"
	.string "Herausforderung.$"
#else
	.string "We await your challenge in the future!$"
#endif

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
#if GERMAN
	.string "In der Kampfforschung musst du die\n"
	.string "Kampfpyramide erforschen und\l"
	.string "versuchen, bis nach oben zu gelangen.\l"
	.string "\p"
	.string "Kämpfe dich durch sieben Etagen, die\n"
	.string "wie Irrgärten angelegt sind. Trainer\l"
	.string "und auch wilde Pokémon warten auf dich.\p"
	.string "Auf deinem Weg dürfen dich drei Pokémon\n"
	.string "begleiten, von denen keines ein Item\l"
	.string "halten darf.\p"
	.string "Für den Aufstieg erhältst du einen\n"
	.string "Pyrabeutel, in dem du Items verstauen\l"
	.string "kannst.\p"
	.string "Bestehst du die Herausforderung nicht,\n"
	.string "werden dir die Items im Pyrabeutel\l"
	.string "abgenommen.\p"
	.string "Möchtest du die Herausforderung\n"
	.string "abbrechen, wähle “Ausruhen” und\l"
	.string "speichere dann das Spiel.\p"
	.string "Wenn du die Herausforderung ohne\n"
	.string "Speichern abbrichst, wirst du\l"
	.string "disqualifiziert.$"
#else
	.string "The Battle Quest is a battling\n"
	.string "event in which you must explore\l"
	.string "the PYRAMID and try to reach the top.\p"
	.string "In the PYRAMID are seven floors of\n"
	.string "mazes, all of them filled with not only\l"
	.string "skilled TRAINERS but also wild POKéMON.\p"
	.string "You must enter with three POKéMON,\n"
	.string "none of them holding an item.\p"
	.string "On your ascent, you will be provided\n"
	.string "with a BATTLE BAG for items.\p"
	.string "If you fail in your challenge, any item\n"
	.string "placed in the BATTLE BAG disappears.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, you must select “REST”\l"
	.string "and save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
#if GERMAN
	.string "In der Kampfpyramide wird in zwei\n"
	.string "Kategorien gekämpft: Lv. 50 und Offene\l"
	.string "Kämpfe. Wofür entscheidest du dich?$"
#else
	.string "The PYRAMID offers two courses,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which will you enter?$"
#endif

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
#if GERMAN
	.string "Wunderbar! Nun wähle die drei Pokémon\n"
	.string "aus, die dich begleiten sollen.$"
#else
	.string "Very good. Now, please select the three\n"
	.string "POKéMON you wish to accompany you.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
#if GERMAN
	.string "Wir haben da ein kleines Problem…\p"
	.string "Deine drei Pokémon sind nicht\n"
	.string "teilnahmeberechtigt.\p"
	.string "Keines von ihnen darf ein Item\n"
	.string "halten.\p"
	.string "Eier{STR_VAR_1}.\p"
	.string "Bitte komm wieder, wenn du so weit\n"
	.string "bist.$"
#else
	.string "A slight problem, adventurer!\p"
	.string "You seem to not have the three\n"
	.string "POKéMON qualified for the challenge.\p"
	.string "Please also remember to take all\n"
	.string "items from your POKéMON.\p"
	.string "EGGS{STR_VAR_1}.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
#if GERMAN
	.string "Wir haben da ein kleines Problem…\p"
	.string "Deine drei Pokémon sind nicht\n"
	.string "teilnahmeberechtigt.\p"
	.string "Du brauchst Pokémon von Level 50\n"
	.string "oder weniger.\p"
	.string "Keines von ihnen darf ein Item\n"
	.string "halten.\p"
	.string "Eier{STR_VAR_1}.\p"
	.string "Bitte komm wieder, wenn du so weit\n"
	.string "bist.$"
#else
	.string "A slight problem, adventurer!\p"
	.string "You seem to not have the three\n"
	.string "POKéMON qualified for the challenge.\p"
	.string "The three POKéMON must be different\n"
	.string "and each no higher than Level 50.\p"
	.string "Please also remember to take all\n"
	.string "items from your POKéMON.\p"
	.string "EGGS{STR_VAR_1}.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd:

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
#if GERMAN
	.string "Bevor du die Kampfpyramide betrittst,\n"
	.string "musst du dein Spiel speichern. Okay?$"
#else
	.string "Before you enter the BATTLE PYRAMID,\n"
	.string "the game must be saved. Is that okay?$"
#endif

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
#if GERMAN
	.string "Sehr gut. Nun werde ich dich zur\n"
	.string "Kampfpyramide bringen.$"
#else
	.string "Very good. I will now show you into\n"
	.string "the BATTLE PYRAMID.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
#if GERMAN
	.string "Wir werden deinen Beutel sicher\n"
	.string "für dich aufbewahren, {PLAYER}.$"
#else
	.string "We will hold your BAG for safekeeping,\n"
	.string "{PLAYER}, while you are exploring.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
#if GERMAN
	.string "Bitte nimm diesen Pyrabeutel.$"
#else
	.string "In exchange, please take this BATTLE\n"
	.string "BAG, the one you used previously.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
#if GERMAN
	.string "Bitte nimm diesen Pyrabeutel.$"
#else
	.string "In exchange, please take this\n"
	.string "BATTLE BAG.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
#if GERMAN
	.string "{PLAYER} tauscht den Beutel gegen\n"
	.string "den Pyrabeutel.$"
#else
	.string "{PLAYER} exchanged the BAG for\n"
	.string "the BATTLE BAG.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
#if GERMAN
	.string "Stellst du dich auf diese Bodenplatte,\n"
	.string "gelangst du auf die nächste Ebene der\l"
	.string "Kampfpyramide.\p"
	.string "Ich hoffe, du überstehst das Abenteuer\n"
	.string "unbeschadet.$"
#else
	.string "When you step on this floor panel,\n"
	.string "you will be transported to a higher\l"
	.string "floor in the PYRAMID.\p"
	.string "I hope for your sake that your\n"
	.string "quest goes safely!$"
#endif

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
#if GERMAN
	.string "Da haben wir aber ein heftiges\n"
	.string "Problem! \p"
	.string "Du hast, bevor du die Herausforderung\n"
	.string "abgebrochen hast, nicht gespeichert.\p"
	.string "Daher wirst du für diese Herausforde-\n"
	.string "rung disqualifiziert. Schade!\p"
	.string "Hier hast du deinen Beutel zurück.\p"
	.string "{PLAYER} hat den Beutel erhalten.$"
#else
	.string "A major problem, explorer!\p"
	.string "You did not save before ending\n"
	.string "your challenge the last time.\p"
	.string "Consequently, your challenge has\n"
	.string "been disqualified, I'm sorry to say.\p"
	.string "Here is the BAG we've been holding\n"
	.string "for you.\p"
	.string "{PLAYER} got the BAG back.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
#if GERMAN
	.string "Schön, dich wiederzusehen!\p"
	.string "Du hast die Kampfpyramide erobert!\n"
	.string "Hervorragend, hervorragend!$"
#else
	.string "Excellent to see you back!\p"
	.string "You've conquered the PYRAMID!\n"
	.string "How splendid!$"
#endif

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
#if GERMAN
	.string "Äh, wir haben da ein kleines Problem.\n"
	.string "\p"
	.string "Eines deiner Pokémon hält ein Item.\n"
	.string "Bedauerlicherweise können Items, die\p"
	.string "du in der Kampfpyramide erhalten hast,\n"
	.string "nicht behalten werden.$"
#else
	.string "Ah, a slight problem.\p"
	.string "At least one POKéMON is holding\n"
	.string "an item.\p"
	.string "I'm sorry to say, items obtained in\n"
	.string "the PYRAMID cannot be taken away.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
#if GERMAN
	.string "Alle Items, die von deinen Pokémon\n"
	.string "gehalten werden, werden im Pyrabeutel\l"
	.string "verstaut, {PLAYER}.$"
#else
	.string "All items held by your POKéMON will be\n"
	.string "moved to your BATTLE BAG, {PLAYER}.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
#if GERMAN
	.string "Tut mir Leid, aber in deinem Pyrabeutel\n"
	.string "ist nicht genug Platz für alle Items.\p"
	.string "\p"
	.string "Bitte such dir die Items aus, die du\n"
	.string "mitnehmen möchtest.$"
#else
	.string "The BATTLE BAG cannot hold all your\n"
	.string "items, I'm sorry to say.\p"
	.string "Please pick the items you'll keep in the\n"
	.string "BATTLE BAG, and with your POKéMON.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
#if GERMAN
	.string "Eines deiner Pokémon hält immer noch\n"
	.string "ein Item.$"
#else
	.string "At least one POKéMON is still\n"
	.string "holding an item.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
#if GERMAN
	.string "Bitte such dir die Items aus, die du\n"
	.string "mitnehmen möchtest.$"
#else
	.string "Please pick the items you'll keep in the\n"
	.string "BATTLE BAG, and with your POKéMON.$"
#endif

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
#if GERMAN
	.string "{PLAYER} gibt alles zurück, was die\n"
	.string "Pokémon getragen haben.$"
#else
	.string "{PLAYER} returned everything that\n"
	.string "the POKéMON held.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
#if GERMAN
	.string "Dein Pyrabeutel wird hier von uns\n"
	.string "aufbewahrt. Wenn du das nächste Mal\p"
	.string "antrittst, bekommst du ihn wieder.\n"
	.string "{PLAYER} tauscht den Pyrabeutel gegen\l"
	.string "den Beutel ein.$"
#else
	.string "The BATTLE BAG you used will be kept\n"
	.string "in readiness for your next challenge.\p"
	.string "{PLAYER} turned the BATTLE BAG over\n"
	.string "for the BAG's return.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
#if GERMAN
	.string "Dein Erfolg wird gespeichert.\n"
	.string "Bitte warten.$"
#else
	.string "I must record your results.\n"
	.string "Please wait.$"
#endif

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
#if GERMAN
	.string "Als Andenken an deinen Sieg über die\n"
	.string "Kampfpyramide nimm bitte dies hier.$"
#else
	.string "As a memento for conquering\n"
	.string "the BATTLE PYRAMID, please take this.$"
#endif

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
#if GERMAN
	.string "{PLAYER} gewinnt {STR_VAR_1}.$"
#else
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"
#endif

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
#if GERMAN
	.string "…Ah… Dein Beutel ist voll.\p"
	.string "Bitte komm wieder, wenn du deinen\n"
	.string "Beutel aufgeräumt hast.$"
#else
	.string "…Ah…\n"
	.string "Your BAG appears to be filled.\p"
	.string "Please return after you've organized\n"
	.string "your BAG's contents.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
#if GERMAN
	.string "Das muss für dich enttäuschend sein…\p"
	.string "Hier ist dein Beutel.\p"
	.string "{PLAYER} bekommt den Beutel zurück.$"
#else
	.string "How disappointing for you…\p"
	.string "Here is the BAG we've been holding\n"
	.string "for you.\p"
	.string "{PLAYER} got the BAG back.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
#if GERMAN
	.string "Wir freuen uns auf deine nächste\n"
	.string "Herausforderung.$"
#else
	.string "We look forward to your\n"
	.string "next challenge!$"
#endif

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
#if GERMAN
	.string "Wir haben schon auf dich gewartet!\p"
	.string "Hier ist dein Preis für deinen Sieg\n"
	.string "über die Pyramide.$"
#else
	.string "We have been looking forward to\n"
	.string "your arrival!\p"
	.string "Here is your prize for conquering\n"
	.string "the PYRAMID.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
#if GERMAN
	.string "Willkommen…\n"
	.string "Ich freue mich darauf, dir zu erklären,\p"
	.string "welche Schwierigkeiten dich in der\n"
	.string "Kampfpyramide erwarten…$"
#else
	.string "Welcome…\p"
	.string "I shall be pleased to tell you what\n"
	.string "misfortunes await in the PYRAMID…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_Aah:
#if GERMAN
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "Aaah!$"
#else
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "Aah!$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
#if GERMAN
	.string "Ich sehe einen Funkenflug…\p"
	.string "Und in diesem sehe ich deine Pokémon\n"
	.string "gegen Paralyse ankämpfen…$"
#else
	.string "I see a shower of sparks…\p"
	.string "…And in it, I see your POKéMON\n"
	.string "struggling with paralysis…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
#if GERMAN
	.string "Ich sehe Gift…\p"
	.string "Und ich sehe, wie deine Pokémon unter\n"
	.string "der Wirkung des Gifts leiden…$"
#else
	.string "I see poison…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from the effects of poison…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
#if GERMAN
	.string "Ich sehe helle, rote Flammen…\p"
	.string "Und ich sehe, wie deine Pokémon sich\n"
	.string "gegen Verbrennungen wehren…$"
#else
	.string "I see bright red flames…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from burns…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
#if GERMAN
	.string "Ich spüre den enormen Druck\n"
	.string "aufgestauter Wut…\p"
	.string "Es ist ein Fluch…\p"
	.string "Und ich sehe, wie deinen Pokémon KP\n"
	.string "entzogen werden und sie keine Kraft\l"
	.string "haben, Verzweifler anzuwenden…$"
#else
	.string "I sense the tremendous pressure of\n"
	.string "unrequited anger…\p"
	.string "It is a curse…\p"
	.string "…And, I see your POKéMON drained of\n"
	.string "Power Points and having no recourse\l"
	.string "but to use STRUGGLE…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
#if GERMAN
	.string "Ich sehe schwebende Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die\n"
	.string "frustriert wirkungslose\l"
	.string "Boden-Attacken anwenden…$"
#else
	.string "I see POKéMON loftily airborne…\p"
	.string "…And, I see your POKéMON frustrated\n"
	.string "by powerless GROUND-type moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
#if GERMAN
	.string "Ich sehe Energie vom Grund aufsteigen…\n"
	.string "\p"
	.string "Und ich sehe deine Pokémon in der\n"
	.string "Umklammerung dieser Energie…$"
#else
	.string "I sense terrific energy rising from\n"
	.string "the ground below…\p"
	.string "…And, I see your POKéMON unable to\n"
	.string "escape the power's clutches…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintIce:
#if GERMAN
	.string "Ich sehe Pokémon und die Kälte des\n"
	.string "Eises…\p"
	.string "Und ich sehe, wie deine Pokémon sich\n"
	.string "gegen die Kälte der Attacken wehren…$"
#else
	.string "I see ICE-type POKéMON…\p"
	.string "…And, I see your POKéMON fighting\n"
	.string "the freezing effects of ice…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
#if GERMAN
	.string "Ich sehe einen Orkan von Attacken, die\n"
	.string "den Anwender gefährden…\p"
	.string "Und ich sehe deine Pokémon, die\n"
	.string "ihm zum Opfer fallen…$"
#else
	.string "I see a flurry of moves that imperil\n"
	.string "the user…\p"
	.string "…And, I see your POKéMON falling\n"
	.string "to them…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
#if GERMAN
	.string "Ich sehe Psycho-Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die unter\n"
	.string "den Psycho-Attacken leiden…$"
#else
	.string "I see PSYCHIC-type POKéMON…\p"
	.string "…And, I see your POKéMON in torment\n"
	.string "from PSYCHIC moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintRock:
#if GERMAN
	.string "Ich sehe Gestein-Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die unter\n"
	.string "den Gestein-Attacken leiden…$"
#else
	.string "I see ROCK-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from ROCK moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
#if GERMAN
	.string "Ich sehe Kampf-Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die unter\n"
	.string "den Kampf-Attacken leiden…$"
#else
	.string "I see FIGHTING-type POKéMON…\p"
	.string "…And, I see your POKéMON pummeled\n"
	.string "by FIGHTING moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
#if GERMAN
	.string "Regentanz… Sonnentag…\n"
	.string "Sandsturm… Hagelsturm…\p"
	.string "Ich sehe Pokémon, die mit dem Wetter\n"
	.string "stärker werden…\p"
	.string "Ich sehe deine Pokémon, verwirrt durch\n"
	.string "die verschiedenen Attacken-Arten…$"
#else
	.string "RAIN DANCE… SUNNY DAY…\n"
	.string "SANDSTORM… HAIL…\p"
	.string "I see POKéMON that become stronger\n"
	.string "with the weather…\p"
	.string "…And, I see your POKéMON confounded\n"
	.string "by different types of moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintBug:
#if GERMAN
	.string "Ich sehe Käfer-Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die unter\n"
	.string "verschiedenen Attacken leiden…$"
#else
	.string "I see BUG-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from different kinds of attacks…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintDark:
#if GERMAN
	.string "Ich sehe Unlicht-Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die unter\n"
	.string "Unlicht-Attacken leiden…$"
#else
	.string "I see DARK-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from DARK-type moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintWater:
#if GERMAN
	.string "Ich sehe Wasser-Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die unter\n"
	.string "Wasser-Attacken leiden…$"
#else
	.string "I see WATER-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from WATER-type moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
#if GERMAN
	.string "Ich sehe Geist-Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die unter\n"
	.string "Geist-Attacken leiden…$"
#else
	.string "I see GHOST-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from GHOST-type moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
#if GERMAN
	.string "Ich sehe Stahl-Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die unter\n"
	.string "enorm starken Attacken leiden…$"
#else
	.string "I see STEEL-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from enormously powerful moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
#if GERMAN
	.string "Ich sehe fliegende Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die unter\n"
	.string "enorm starken Attacken leiden…$"
#else
	.string "I see flying POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from enormously powerful moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
#if GERMAN
	.string "Ich sehe die, die durch die Kraft von\n"
	.string "Steinen entwickelt wurden…\p"
	.string "Ich spüre Feuer, Wasser und\n"
	.string "Elektrizität…\p"
	.string "Und ich sehe deine Pokémon, wie sie\n"
	.string "unter diesen Kräften leiden…$"
#else
	.string "I see those that have evolved from\n"
	.string "the power of stones…\p"
	.string "I also sense fire, water,\n"
	.string "and electricity…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from those three powers…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
#if GERMAN
	.string "Ich sehe Normal-Pokémon…\p"
	.string "Und ich sehe deine Pokémon, die unter\n"
	.string "enorm starken Attacken leiden…$"
#else
	.string "I see NORMAL-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering\n"
	.string "from enormously powerful moves…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
#if GERMAN
	.string "Ob du meinem Orakel Glauben schenkst\n"
	.string "oder nicht, liegt allein bei dir…\p"
	.string "Die Zukunft lässt sich stets ändern…\n"
	.string "Ich wünsche dir einen sicheren Weg…$"
#else
	.string "Whether you believe my fortunes\n"
	.string "or not, the choice is yours…\p"
	.string "The future can be changed anytime…\n"
	.string "I wish you safe passage…$"
#endif

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
#if GERMAN
	.string "Wusstest du das nicht?\p"
	.string "Wenn du schnell rennst, werden Trainer\n"
	.string "auf dich aufmerksam und fordern dich\p"
	.string "heraus. Wenn du ihnen aus dem Weg gehen\n"
	.string "willst, schau ihnen nicht in die Augen\l"
	.string "und schleich an ihnen vorbei.$"
#else
	.string "Did you know?\p"
	.string "If you run fast, TRAINERS may notice\n"
	.string "and come after you for a battle.\p"
	.string "So, if you want to avoid TRAINERS,\n"
	.string "don't catch their eyes, but sneak\l"
	.string "cautiously and quietly past them.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
#if GERMAN
	.string "Aaaaaaaaaaaarghuaaaaaaargh!\p"
	.string "Ich hatte so viele Items, und nun habe\n"
	.string "ich alle verloren, weil ich verloren\l"
	.string "habe!\p"
	.string "Aaaaaaaaaaaarghuaaaaaaargh!$"
#else
	.string "Awaaaaaaarrrrgh!\p"
	.string "I had a whole lot of items, but I lost\n"
	.string "them all when I lost!\p"
	.string "Awaaaaaaarrrrgh!$"
#endif

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
#if GERMAN
	.string "Willkommen zurück!\n"
	.string "Dir ist das Undenkbare gelungen!\p"
	.string "Du hast den Pyrakönig besiegt\n"
	.string "und die Kampfpyramide erobert!$"
#else
	.string "Welcome back!\n"
	.string "You've done the unthinkable!\p"
	.string "You've defeated the PYRAMID KING\n"
	.string "and conquered the BATTLE PYRAMID!$"
#endif

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
#if GERMAN
	.string "Junger Forschergeist!\n"
	.string "In Anerkennung deines Mutes geben wir\l"
	.string "dir Gewinnpunkte.$"
#else
	.string "Young explorer!\n"
	.string "In commendation of your courage,\l"
	.string "we give you these Battle Point(s)!$"
#endif

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
#if GERMAN
	.string "Die Regeln der Kampfforschung hängen\n"
	.string "öffentlich aus.$"
#else
	.string "The Battle Quest rules are listed.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
#if GERMAN
	.string "Wähle bitte ein Themengebiet aus.$"
#else
	.string "Which heading do you want to read?$"
#endif

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
#if GERMAN
	.string "Wurde die Kampfpyramide erobert,\n"
	.string "werden die wilden Pokémon in ihr gegen\l"
	.string "andere ausgetauscht.\p"
	.string "Untersuche, beobachte und erfahre,\n"
	.string "welche wilden Pokémon auf dich warten.$"
#else
	.string "When the PYRAMID is conquered,\n"
	.string "the wild POKéMON that appear in it\l"
	.string "are replaced by different kinds.\p"
	.string "Explore, observe, and learn what kinds\n"
	.string "of wild POKéMON you may encounter.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
#if GERMAN
	.string "Im Inneren der Kampfpyramide liegen\n"
	.string "Trainer auf der Lauer und warten auf\l"
	.string "dich.\p"
	.string "Auf jeder Ebene können sich bis zu\n"
	.string "acht Trainer befinden.\p"
	.string "Besiegst du einen von ihnen, bekommst\n"
	.string "du wertvolle Hinweise mit auf den Weg.$"
#else
	.string "TRAINERS are lying in wait for you\n"
	.string "inside the PYRAMID.\p"
	.string "On each floor, there are up to\n"
	.string "eight TRAINERS.\p"
	.string "When you defeat a TRAINER, you will\n"
	.string "get a helpful hint for your adventure.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
#if GERMAN
	.string "Die Labyrinthe in der Kampfpyramide\n"
	.string "ändern sich ständig. Jedes Mal, wenn\p"
	.string "du sie erneut betrittst, sehen sie\n"
	.string "anders aus.\l"
	.string "Die Beleuchtung ist spärlich, daher sei\p"
	.string "vorsichtig. Hast du ein wildes Pkmn oder\n"
	.string "einen Trainer besiegt, wird es heller.$"
#else
	.string "The mazes in the PYRAMID rearrange\n"
	.string "themselves every time you enter it.\p"
	.string "The mazes are poorly lit.\n"
	.string "You must advance with caution.\p"
	.string "The light grows brighter whenever you\n"
	.string "defeat a wild POKéMON or a TRAINER.$"
#endif

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
#if GERMAN
	.string "Wenn du in der Kampfpyramide unterwegs\n"
	.string "bist, dient der Pyrabeutel dir als\l"
	.string "Beutel.\p"
	.string "Es gibt zwei verschiedene Pyrabeutel:\n"
	.string "Einen für das Abenteuer Level 50 und\l"
	.string "einen für das Abenteuer Offene Kämpfe.\l"
	.string "\p"
	.string "In ihnen kannst du 10 Items in einer\n"
	.string "maximalen Anzahl von 99 Stück pro Item\l"
	.string "verstauen.\p"
	.string "Scheiterst du, ist der Inhalt des\n"
	.string "Pyrabeutels verloren.$"
#else
	.string "The BATTLE BAG serves as your BAG\n"
	.string "while in the PYRAMID.\p"
	.string "There are two separate BATTLE BAGS--\n"
	.string "one each for the Level 50 and\l"
	.string "Open Level adventures.\p"
	.string "They each can hold up to 99 pieces\n"
	.string "of ten kinds of items.\p"
	.string "The contents of the BATTLE BAG are\n"
	.string "lost if you fail in your quest.$"
#endif

