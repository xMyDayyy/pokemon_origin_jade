BattleFrontier_BattlePalaceLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge_hns, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded_hns
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded_hns
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge_hns::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge_hns::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant_hns::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge_hns
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle_hns
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns2_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe_hns, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor_hns
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR_HNS, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge_hns::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge_hns::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge_hns
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge_hns::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge_hns
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant_hns
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor_hns
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor_hns
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant_hns::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant_hns::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor_hns::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor_hns::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor_hns::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor_hns::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor_hns:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics_hns
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature_hns
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves_hns
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered_hns
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger_hns
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle_hns:
#if GERMAN
	.string "Hier wird das Herz der Trainer\n"
	.string "auf die Probe gestellt!\p"
	.string "Willkommen im Kampfpalast!\p"
	.string "Ich nehme Herausforderungen für die\n"
	.string "Einzelkampf-Hallen entgegen!$"
#else
	.string "Where the hearts of TRAINERS\n"
	.string "are put to the test.\p"
	.string "I welcome you to the BATTLE PALACE.\p"
	.string "I accept challenges to the SINGLE\n"
	.string "BATTLE HALLS.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge_hns:
#if GERMAN
	.string "Möchtest du dich der Herausforderung\n"
	.string "der Einzelkampf-Hallen stellen?$"
#else
	.string "Do you wish to take\n"
	.string "the SINGLE BATTLE HALL challenge?$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge_hns:
#if GERMAN
	.string "Im Kampfpalast gibt es verschiedene\n"
	.string "Einzelkampf-Hallen für Einzelkämpfe.\p"
	.string "Die Einzelkämpfe verlaufen auf die\n"
	.string "übliche Weise. Es gibt eine\l"
	.string "entscheidende Regel, die es zu\l"
	.string "beachten gilt!!!\p"
	.string "Trainer dürfen ihre Pokémon lediglich\n"
	.string "in den Kampf rufen und zurückziehen.\p"
	.string "Ansonsten dürfen sie ihren Pokémon\n"
	.string "keinerlei Anweisungen geben!\p"
	.string "Die Pokémon sollen sich ihrem Wesen\n"
	.string "entsprechend verhalten und eigen-\p"
	.string "ständig kämpfen! Vertrau deinen\n"
	.string "Pokémon und achte auf sie.\p"
	.string "Schaffst du es, sieben Trainer in Folge\n"
	.string "zu besiegen, erhältst du von uns\l"
	.string "Gewinnpunkte.\p"
	.string "Willst du die Herausforderung\n"
	.string "abbrechen, musst du dein Spiel\l"
	.string "speichern.\p"
	.string "Andernfalls wirst du bei Abbruch\n"
	.string "disqualifiziert.$"
#else
	.string "In the BATTLE PALACE, there are\n"
	.string "several auditoriums for SINGLE BATTLES\l"
	.string "that are named SINGLE BATTLE HALLS.\p"
	.string "The SINGLE BATTLES are conducted in\n"
	.string "the usual way, except with one crucial\l"
	.string "rule that must be obeyed.\p"
	.string "TRAINERS are permitted only to switch\n"
	.string "their POKéMON in and out.\p"
	.string "TRAINERS are otherwise forbidden to\n"
	.string "command their POKéMON.\p"
	.string "The POKéMON are to behave according\n"
	.string "to their nature and battle on their own.\p"
	.string "You must put your trust in your\n"
	.string "POKéMON and watch over them.\p"
	.string "If you achieve the honor of beating\n"
	.string "seven TRAINERS in succession,\l"
	.string "we will present you with Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, you must save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns:
#if GERMAN
	.string "Stärke dein Herz und deine Pokémon und\n"
	.string "komm dann wieder.$"
#else
	.string "When you have fortified your heart\n"
	.string "and POKéMON, you must return.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge_hns:
#if GERMAN
	.string "Es gibt zwei Kampfhallen: Für Level 50\n"
	.string "und Offene Kämpfe.\l"
	.string "Wofür entscheidest du dich?$"
#else
	.string "There are two BATTLE HALLS,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which is your choice of a challenge?$"
#endif

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50_hns:
#if GERMAN
	.string "Entschuldigung!\p"
	.string "Aber deine Pokémon sind nicht\n"
	.string "teilnahmeberechtigt.\p"
	.string "Du brauchst drei verschiedene\n"
	.string "Pokémon von Level 50 oder weniger.\p"
	.string "Jedes muss außerdem ein anderes Item\n"
	.string "halten.\p"
	.string "Eier{STR_VAR_1}.\p"
	.string "Bitte komm wieder, wenn du bereit\n"
	.string "bist.$"
#else
	.string "Sigh…\p"
	.string "You do not have the three POKéMON\n"
	.string "required for the challenge.\p"
	.string "To enter, you must provide three\n"
	.string "different kinds of POKéMON.\p"
	.string "These POKéMON must all be of\n"
	.string "Level 50 or lower.\p"
	.string "They also must not be holding\n"
	.string "the same kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd_hns:
#if GERMAN
	.string "Komm wieder, wenn du vorbereitet bist.$"
#else
	.string "Come back when you have made\n"
	.string "your preparations.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen_hns:
#if GERMAN
	.string "Entschuldigung!\p"
	.string "Aber deine Pokémon sind nicht\n"
	.string "teilnahmeberechtigt.\p"
	.string "Du brauchst drei verschiedene\n"
	.string "Pokémon.\p"
	.string "Jedes muss außerdem ein anderes Item\n"
	.string "halten.\p"
	.string "Eier{STR_VAR_1}.\p"
	.string "Bitte komm wieder, wenn du bereit\n"
	.string "bist.$"
#else
	.string "Sigh…\p"
	.string "You do not have the three POKéMON\n"
	.string "required for the challenge.\p"
	.string "To enter, you must provide three\n"
	.string "different kinds of POKéMON.\p"
	.string "They also must not be holding\n"
	.string "the same kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons_hns:
#if GERMAN
	.string "Gut. Nun wähle deine drei Pokémon aus.$"
#else
	.string "Good. Now, you must select your\n"
	.string "three POKéMON.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns2_hns:
#if GERMAN
	.string "Bevor du die Kampfhalle betrittst,\n"
	.string "musst du dein Spiel speichern. Okay?$"
#else
	.string "I must save before I show you to\n"
	.string "the BATTLE HALL. Is that okay?$"
#endif

BattleFrontier_BattlePalaceLobby_Text_FollowMe_hns:
#if GERMAN
	.string "Gut. Dann folge mir.$"
#else
	.string "Good.\n"
	.string "Now, follow me.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded_hns:
#if GERMAN
	.string "Ich fühle mich geehrt, dass ich deine\n"
	.string "Pokémon sehen durfte.\p"
	.string "Dein Erfolg wird gespeichert.\n"
	.string "Bitte warte einen Moment.$"
#else
	.string "I feel privileged for having seen\n"
	.string "your POKéMON's exploits.\p"
	.string "The results will be recorded.\n"
	.string "I must ask you to briefly wait.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak_hns:
#if GERMAN
	.string "Sieben Siege in Folge…\p"
	.string "Das Band zwischen deinem Herzen und\n"
	.string "deinen Pokémon scheint stark zu sein.$"
#else
	.string "To achieve a 7-win streak…\p"
	.string "The bonds that bind your heart with\n"
	.string "your POKéMON seem firm and true.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded_hns:
#if GERMAN
	.string "Dein Erfolg wird gespeichert.\n"
	.string "Bitte warte einen Moment.$"
#else
	.string "Your feat will be recorded.\n"
	.string "I must ask you to briefly wait.$"
#endif

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak_hns:
#if GERMAN
	.string "Für deinen siebenfachen Sieg bekommst\n"
	.string "du von uns Gewinnpunkte überreicht.$"
#else
	.string "For the feat of your 7-win streak,\n"
	.string "we present you with Battle Point(s).$"
#endif

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize_hns:
#if GERMAN
	.string "Du hast keinen Platz für den Preis?\p"
	.string "Räum deinen Beutel auf und komm\n"
	.string "dann wieder.$"
#else
	.string "You seem to have no space for\n"
	.string "our prize.\p"
	.string "You should return when you have\n"
	.string "organized your BAG.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting_hns:
#if GERMAN
	.string "Wir haben auf dich gewartet…$"
#else
	.string "We have been waiting for you…$"
#endif

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns:
#if GERMAN
	.string "Bevor du die Kampfhalle betrittst,\n"
	.string "musst du dein Spiel speichern.$"
#else
	.string "I must save before I show you to\n"
	.string "the BATTLE HALL. Is that okay?$"
#endif

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge_hns:
#if GERMAN
	.string "Seufz…\p"
	.string "Du hast, bevor du die Herausforderung\n"
	.string "abgebrochen hast, nicht gespeichert.\p"
	.string "Daher wirst du für diese Herausforde-\n"
	.string "rung disqualifiziert. Schade!$"
#else
	.string "Sigh…\p"
	.string "You failed to save before you ended\n"
	.string "your challenge the last time.\p"
	.string "As a result, your challenge has been\n"
	.string "disqualified. It is most unfortunate.$"
#endif

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize_hns:
#if GERMAN
	.string "{PLAYER} gewinnt {STR_VAR_1}.$"
#else
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink_hns:
#if GERMAN
	.string "Für so einen kräftigen Burschen wie\n"
	.string "mich sind kräftige Pokémon das Wahre!\p"
	.string "Angriff ist die beste Verteidigung!\n"
	.string "Eine rücksichtslose Attacke das Beste!\p"
	.string "Aber darüber wollte ich jetzt\n"
	.string "eigentlich gar nicht reden.\p"
	.string "Manchmal kommt hier eine niedliche\n"
	.string "Lady vorbei.\p"
	.string "Sie sagt, sie kann erkennen, was\n"
	.string "Pokémon denken.\p"
	.string "Ich kenn mich damit nicht aus, aber ich\n"
	.string "weiß, dass die Lady verdammt süß ist.\p"
	.string "\p"
	.string "Was?!?\n"
	.string "Warum schaust du mich so komisch an?$"
#else
	.string "For a hardy fellow like me,\n"
	.string "hardy POKéMON are the best.\p"
	.string "Offense is the best defense!\n"
	.string "A relentless attack is the ultimate!\p"
	.string "But that's not what I wanted to chat\n"
	.string "about.\p"
	.string "Every so often a really cute lady\n"
	.string "swings by here.\p"
	.string "She says that she can tell what\n"
	.string "POKéMON are thinking.\p"
	.string "I don't know about that part,\n"
	.string "but she is really cute.\p"
	.string "Huh?\n"
	.string "Why are you looking at me like that?$"
#endif

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere_hns:
#if GERMAN
	.string "Hmm…\p"
	.string "Das Wesen der Pokémon und die\n"
	.string "Attacken, die sie gelernt haben,\l"
	.string "scheinen der Schlüssel zu sein.\p"
	.string "Um es deutlicher zu machen: Die\n"
	.string "Attacken sollten zum Wesen der Pokémon\l"
	.string "passen.\p"
	.string "Wenn dein Pokémon Schwierigkeiten hat\n"
	.string "und nicht alles gibt, dann solltest du\l"
	.string "prüfen, wie gut seine Attacken zu\l"
	.string "seinem Wesen passen.$"
#else
	.string "Hmm…\p"
	.string "It appears that the nature of POKéMON\n"
	.string "and the moves that they have been\l"
	.string "taught are the keys to battle here.\p"
	.string "To be more precise, it's how well\n"
	.string "the moves match the nature of\l"
	.string "the POKéMON.\p"
	.string "If your POKéMON is in trouble and\n"
	.string "unable to live up to its potential,\l"
	.string "you may need to examine how well\l"
	.string "its moves match its nature.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms_hns:
#if GERMAN
	.string "Mein Pokémon ist sehr sanftmütig.\p"
	.string "Aber wenn ich es in eine Kampfhalle\n"
	.string "mitnehme, scheint es sich manchmal ganz\l"
	.string "merkwürdig zu verändern!\p"
	.string "Es wirkt dann regelrecht\n"
	.string "einschüchternd! Richtig schockierend!$"
#else
	.string "My POKéMON is usually very docile.\p"
	.string "But when it's in a BATTLE HALL,\n"
	.string "it sometimes seems to become\l"
	.string "transformed into something wicked!\p"
	.string "It becomes totally intimidating.\n"
	.string "It's shocking, even.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway_hns:
#if GERMAN
	.string "Ich frage mich, welches Wesen ein\n"
	.string "Pokémon hat, das seine Gegner schwächt\l"
	.string "und dann langsam zur Strecke bringt.\p"
	.string "Ich würde mich echt wundern, wenn es\n"
	.string "dann ein Lasches Wesen hätte.\p"
	.string "Nee, bestimmt nicht!$"
#else
	.string "I wonder what sort of nature a POKéMON\n"
	.string "would have if it favored enfeebling its\l"
	.string "opponents and chipping away slowly.\p"
	.string "I'd be surprised if it was a LAX nature.\p"
	.string "But, nah, that can't be right.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle_hns:
#if GERMAN
	.string "Hier wird das Herz der Trainer\n"
	.string "auf die Probe gestellt!\p"
	.string "Willkommen im Kampfpalast!\p"
	.string "Ich nehme Herausforderungen für die\n"
	.string "Doppelkampf-Hallen entgegen!$"
#else
	.string "Where the hearts of TRAINERS\n"
	.string "are put to the test.\p"
	.string "I welcome you to the BATTLE PALACE.\p"
	.string "I accept challenges to the DOUBLE\n"
	.string "BATTLE HALLS.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge_hns:
#if GERMAN
	.string "Möchtest du dich der Herausforderung\n"
	.string "der Doppelkampf-Hallen stellen?$"
#else
	.string "Do you wish to take\n"
	.string "the DOUBLE BATTLE HALL challenge?$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge_hns:
#if GERMAN
	.string "Im Kampfpalast gibt es verschiedene\n"
	.string "Doppelkampf-Hallen für Doppelkämpfe.\p"
	.string "Die Doppelkämpfe verlaufen auf die\n"
	.string "übliche Weise. Es gibt eine\l"
	.string "entscheidende Regel, die es zu\l"
	.string "beachten gilt!!!\p"
	.string "Trainer dürfen ihre Pokémon lediglich\n"
	.string "in den Kampf rufen und zurückziehen.\p"
	.string "Ansonsten dürfen sie ihren Pokémon\n"
	.string "keinerlei Anweisungen geben!\p"
	.string "Die Pokémon sollen sich ihrem Wesen\n"
	.string "entsprechend verhalten und eigen-\p"
	.string "ständig kämpfen! Vertrau deinen\n"
	.string "Pokémon und achte auf sie.\p"
	.string "Schaffst du es, sieben Trainer in Folge\n"
	.string "zu besiegen, erhältst du von uns\l"
	.string "Gewinnpunkte.\p"
	.string "Willst du die Herausforderung\n"
	.string "abbrechen, musst du dein Spiel\l"
	.string "speichern.\p"
	.string "Andernfalls wirst du bei Abbruch\n"
	.string "disqualifiziert.$"
#else
	.string "In the BATTLE PALACE, there are\n"
	.string "several auditoriums for DOUBLE BATTLES\l"
	.string "that are named DOUBLE BATTLE HALLS.\p"
	.string "The DOUBLE BATTLES are conducted in\n"
	.string "the usual way, except with one crucial\l"
	.string "rule that must be obeyed.\p"
	.string "TRAINERS are permitted only to switch\n"
	.string "their POKéMON in and out.\p"
	.string "TRAINERS are otherwise forbidden to\n"
	.string "command their POKéMON.\p"
	.string "The POKéMON are to behave according\n"
	.string "to their nature and battle on their own.\p"
	.string "You must put your trust in your\n"
	.string "POKéMON and watch over them.\p"
	.string "If you achieve the honor of beating\n"
	.string "seven TRAINERS in succession,\l"
	.string "we will present you with Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers_hns:
#if GERMAN
	.string "Um den Palastregenten und sechs\n"
	.string "Trainer in Folge zu besiegen…$"
#else
	.string "To defeat the PALACE MAVEN\n"
	.string "and seven TRAINERS in a row…$"
#endif

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints_hns:
#if GERMAN
	.string "In Anerkennung des Bandes zwischen dir\n"
	.string "und deinen Pokémon geben wir dir\l"
	.string "Gewinnpunkte.$"
#else
	.string "In honor of the bond you share with\n"
	.string "your POKéMON, we present you with\l"
	.string "these Battle Point(s).$"
#endif

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch_hns:
#if GERMAN
	.string "Möchtest du deinen letzten\n"
	.string "Kampfpalast-Kampf in deinen\l"
	.string "Kampfzonenpass eintragen?$"
#else
	.string "Would you like to record your latest\n"
	.string "BATTLE PALACE match on your\l"
	.string "FRONTIER PASS?$"
#endif

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed_hns:
#if GERMAN
	.string "Die Regeln der Kampfhalle hängen\n"
	.string "öffentlich aus.$"
#else
	.string "The BATTLE HALL rules are listed.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading_hns:
#if GERMAN
	.string "Wähle bitte ein Themengebiet aus.$"
#else
	.string "Which heading do you want to read?$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics_hns:
#if GERMAN
	.string "Hier müssen die Pokémon selbständig\n"
	.string "handeln und kämpfen.\p"
	.string "Anders als wilde Pokémon reagieren\n"
	.string "Pokémon, die mit Menschen zusammen-\l"
	.string "leben, abhängig von ihrem Wesen.$"
#else
	.string "Here, POKéMON are required to think\n"
	.string "and battle by themselves.\p"
	.string "Unlike in the wild, POKéMON that live\n"
	.string "with people behave differently\l"
	.string "depending on their nature.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature_hns:
#if GERMAN
	.string "Je nach Wesenheit wird ein Pokémon\n"
	.string "eventuell angreifen, egal, was passiert.\p"
	.string "Ein anderes wird sich vielleicht seinem\n"
	.string "Wesen entsprechend unter allen\p"
	.string "Umständen schützen wollen. Ein anderes\n"
	.string "irritiert oder verwirrt seinen Gegner.\p"
	.string "Abhängig von seinem Wesen wird ein\n"
	.string "Pokémon Lieblingsattacken haben, die\l"
	.string "es hervorragend beherrscht.\p"
	.string "Auf der anderen Seite wird es Attacken\n"
	.string "kennen, die es nicht mag und die ihm\l"
	.string "Schwierigkeiten machen.$"
#else
	.string "Depending on its nature, a POKéMON\n"
	.string "may prefer to attack no matter what.\p"
	.string "Another POKéMON may prefer to protect\n"
	.string "itself from any harm.\p"
	.string "Yet another may enjoy vexing or\n"
	.string "confounding its foes.\p"
	.string "Due to its nature, a POKéMON\n"
	.string "will have favorite moves that it is good\l"
	.string "at using.\p"
	.string "It may also dislike certain moves that\n"
	.string "it has trouble using.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves_hns:
#if GERMAN
	.string "Es gibt offensive Attacken, die dem\n"
	.string "Gegner Schaden zufügen.\p"
	.string "Es gibt defensive Attacken, die auf\n"
	.string "gegnerische Attacken vorbereiten oder\l"
	.string "aber KP wiederherstellen können.\p"
	.string "Und es gibt Attacken, die den Gegner\n"
	.string "schwächen, indem sie Statusprobleme\l"
	.string "verursachen, wie Vergiftungen oder\l"
	.string "Paralyse.\p"
	.string "Pokémon werden diese 3 Kategorien mit\n"
	.string "Sicherheit im Kampf in Betracht ziehen!$"
#else
	.string "There are offensive moves that inflict\n"
	.string "direct damage on the foe.\p"
	.string "There are defensive moves that are\n"
	.string "used to prepare for enemy attacks or\l"
	.string "used to heal HP and so on.\p"
	.string "There are also other somewhat-odd\n"
	.string "moves that may enfeeble the foes with\l"
	.string "stat problems including poison and \l"
	.string "paralysis.\p"
	.string "POKéMON will consider using moves in\n"
	.string "these three categories.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered_hns:
#if GERMAN
	.string "Gibt ein Trainer seinem Pokémon keine\n"
	.string "Anweisungen, wird es vielleicht nicht in\l"
	.string "der Lage sein, bestimmte Attacken\p"
	.string "einzusetzen. Ein Pokémon hat\n"
	.string "Schwierigkeiten mit Attacken, die es\l"
	.string "nicht mag.\p"
	.string "Kennt ein Pokémon nur Attacken, die\n"
	.string "seinem Wesen widersprechen, so kann es\l"
	.string "nicht immer sein ganzes Können zeigen.$"
#else
	.string "When not under command by its TRAINER,\n"
	.string "a POKéMON may be unable to effectively\l"
	.string "use certain moves.\p"
	.string "A POKéMON is not good at using any\n"
	.string "move that it dislikes.\p"
	.string "If a POKéMON only knows moves that\n"
	.string "do not match its nature, it will often\l"
	.string "be unable to live up to its potential.$"
#endif

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger_hns:
#if GERMAN
	.string "Abhängig von seinem Wesen, wird ein\n"
	.string "Pokémon vielleicht auch Attacken\l"
	.string "einsetzen, die seinem Wesen\l"
	.string "widersprechen.\p"
	.string "Benimmt es sich in bestimmten\n"
	.string "Situationen merkwürdig, beobachte es\l"
	.string "genau.$"
#else
	.string "Depending on its nature, a POKéMON may\n"
	.string "start using moves that don't match its\l"
	.string "nature when it is in trouble.\p"
	.string "If a POKéMON begins behaving oddly\n"
	.string "in a pinch, watch it carefully.$"
#endif

