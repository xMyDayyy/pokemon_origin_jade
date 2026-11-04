LilycoveCity_PokemonTrainerFanClub_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_PokemonTrainerFanClub_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonTrainerFanClub_OnTransition
	.byte 0

	@ See field_specials.c for a breakdown of the Fan Club and its variables

LilycoveCity_PokemonTrainerFanClub_OnFrame:
	map_script_2 VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
	.2byte 0

LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans::
	lockall
	applymovement LOCALID_TRAINER_FAN_CLUB_LASS, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer
	applymovement LOCALID_TRAINER_FAN_CLUB_MAN, LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan, MSGBOX_DEFAULT
	applymovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer
	waitmovement 0
	setvar VAR_LILYCOVE_FAN_CLUB_STATE, 2
	releaseall
	end

LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer:
	delay_8
	walk_in_place_faster_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer:
	walk_down
	walk_in_place_faster_right
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer:
	jump_in_place_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_in_place_faster_down
	step_end

LilycoveCity_PokemonTrainerFanClub_OnTransition:
	call LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 2, LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions::
	special TryLoseFansFromPlayTime
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer::
	specialvar VAR_RESULT, ShouldHideFanClubInterviewer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer
	clearflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	clearflag FLAG_FAN_CLUB_STRENGTH_SHARED
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer::
	setflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	return

@ Set up the fan club TV show, if the player has at least 5 fans in the club
@ Rather than counting up, 1 is subtracted from the total for each member not a fan of the players
LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow::
	setvar VAR_0x8005, NUM_TRAINER_FAN_CLUB_MEMBERS
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	goto_if_ge VAR_0x8005, 5, LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan::
	subvar VAR_0x8005, 1
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow::
	special TryPutTrainerFanClubOnAir
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_LASS, 7, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_POKEFAN_M, 3, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, 7, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_NINJA_BOY, 5, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BOY, 5, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_MAN, 8, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_WOMAN, 3, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_EXPERT_F, 8, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting::
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Man::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER6
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Lass::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanM::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER2
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER3
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoy::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER4
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Boy::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER5
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Woman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER7
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertF::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER8
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Interviewer::
	lock
	faceplayer
	goto_if_set FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed
	goto_if_unset FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_Interview
	end

@ The interviewer doesnt count as an individual fan club member
@ Instead they always ask about whoever the Lass would be interested in, if not the player
LilycoveCity_PokemonTrainerFanClub_EventScript_Interview::
	setvar VAR_0x8005, TVSHOW_FAN_CLUB_SPECIAL
	special InterviewBefore
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2
	copyvar VAR_0x800A, VAR_0x8006
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	message LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_FAN_CLUB_RATER
	special ShowScrollableMultichoice
	waitstate
	setvar VAR_0x8004, FANCLUB_MEMBER1
	switch VAR_RESULT
	case 11, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
	case MULTI_B_PRESSED, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	copyvar VAR_0x8006, VAR_0x800A
	copyvar VAR_0x8005, VAR_RESULT
	special PutFanClubSpecialOnTheAir
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo, MSGBOX_DEFAULT
	setflag FLAG_FAN_CLUB_STRENGTH_SHARED
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial, MSGBOX_DEFAULT
	release
	end

@ Shouldnt be reached
LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2::
	end

LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer:
#if GERMAN
	.string "Oh, wow!\n"
	.string "Das ist {PLAYER}!$"
#else
	.string "Oh, wow!\n"
	.string "It's {PLAYER}!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan:
#if GERMAN
	.string "Ich habe die Neuigkeit schon gehört.\n"
	.string "Du bist wirklich stark, nicht wahr?\p"
	.string "Wir diskutieren immer darüber, wer\n"
	.string "hier der stärkste Trainer ist.\p"
	.string "Als ich von dir gehört habe, beschloss\n"
	.string "ich, dein Fan zu werden!\p"
	.string "Ich hoffe, du wirst auch weiterhin\n"
	.string "gegen starke Trainer antreten.\p"
	.string "So kommen wir auch weiterhin in den\n"
	.string "Genuss deiner megaheißen Kämpfe.\p"
	.string "Dann sehen auch die anderen hier, wie\n"
	.string "stark du wirklich bist!\p"
	.string "Denk dran: Ich jubele dir zu, {PLAYER}!$"
#else
	.string "I've heard the news!\n"
	.string "You're really strong, aren't you?\p"
	.string "We always argue about who is the\n"
	.string "strongest of all TRAINERS here.\p"
	.string "So when I heard about you, I decided\n"
	.string "to be your fan!\p"
	.string "I hope you'll keep on battling other\n"
	.string "tough TRAINERS.\p"
	.string "That way, we'll be able to see more\n"
	.string "of your hot, hot battles.\p"
	.string "That will make the others here see\n"
	.string "exactly how great you are.\p"
	.string "Remember, I'm cheering for you,\n"
	.string "{PLAYER}!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin:
#if GERMAN
	.string "Ja, {PLAYER}!\n"
	.string "Dich wollen wir als Sieger sehen!$"
#else
	.string "Yo, {PLAYER}!\n"
	.string "You're the one we want to win!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest:
#if GERMAN
	.string "Die anderen wissen gar nicht, dass du\n"
	.string "besser bist als alle anderen!\p"
	.string "Das stimmt doch, oder {PLAYER}?\n"
	.string "Zeig ihnen, was du drauf hast!$"
#else
	.string "The others, they don't know that\n"
	.string "you're the best of the best!\p"
	.string "Isn't that right, {PLAYER}?\n"
	.string "Show them you've got guts!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary:
#if GERMAN
	.string "Ich sage es ja nicht gerne, aber der\n"
	.string "Trainer, über den alle sprechen, ist\l"
	.string "{STR_VAR_1}, keine Frage!\p"
	.string "Die Stärke dieses Trainers…\n"
	.string "Ganz außergewöhnlich.$"
#else
	.string "I hate to say this, but the TRAINER\n"
	.string "everybody's talking about is\l"
	.string "{STR_VAR_1}, no question about it!\p"
	.string "That TRAINER's power…\n"
	.string "It's out of the ordinary.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen:
#if GERMAN
	.string "Mist… Ich sage jedem, dass {STR_VAR_1}\n"
	.string "am besten von allen ist.\p"
	.string "Aber niemand hört mir zu…$"
#else
	.string "Darn it… I've been telling people\n"
	.string "that {STR_VAR_1} is the best now…\p"
	.string "But no one wants to listen…$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer:
#if GERMAN
	.string "Ich habe etwas über einen neuen,\n"
	.string "starken Trainer gehört.\p"
	.string "Dieser Trainer wird bestimmt auch die\n"
	.string "Arenaleiter besiegen.\p"
	.string "Weißt du irgendwas über diesen neuen\n"
	.string "Trainer?$"
#else
	.string "I've been hearing things about\n"
	.string "a tough new TRAINER.\p"
	.string "This TRAINER's supposed to be beating\n"
	.string "GYM LEADERS, even.\p"
	.string "Do you know anything about this\n"
	.string "new TRAINER?$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou:
#if GERMAN
	.string "Oh! {PLAYER}!\p"
	.string "Los! Ich drücke dir die Daumen!$"
#else
	.string "Oh!\n"
	.string "{PLAYER}!\p"
	.string "Go for it!\n"
	.string "I'm pulling for you!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan:
#if GERMAN
	.string "Seufz… Kamillo…\p"
	.string "Oh, nein! Warte mal!\n"
	.string "Das stimmt gar nicht! Nein, nein!\p"
	.string "Ich bin dein größter Fan!\p"
	.string "Also mach mich stolz!\n"
	.string "Los!$"
#else
	.string "Sigh…\n"
	.string "BRAWLY…\p"
	.string "Oh, no! Wait!\n"
	.string "That's not right! No, no, no!\p"
	.string "I'm your fan through and through!\p"
	.string "So make me proud!\n"
	.string "Go for it!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly:
#if GERMAN
	.string "Ich kann mir nicht helfen, aber ich\n"
	.string "finde nur Kamillo klasse…$"
#else
	.string "I can't help it, I can only get to\n"
	.string "like BRAWLY…$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly:
#if GERMAN
	.string "Niemand erkennt den Charme von\n"
	.string "Kamillo…\p"
	.string "Mir doch egal!\p"
	.string "Auch wenn keiner ihm zujubelt, ich\n"
	.string "unterstütze Kamillo!$"
#else
	.string "Nobody understands the charm of\n"
	.string "BRAWLY…\p"
	.string "I don't care!\p"
	.string "Even if I'm the only one, I'm going\n"
	.string "to keep cheering for BRAWLY!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly:
#if GERMAN
	.string "Egal, was die anderen sagen, der\n"
	.string "Arenaleiter von Faustauhaven, Kamillo,\l"
	.string "ist mein Favorit!$"
#else
	.string "Whatever anyone says, my favorite\n"
	.string "TRAINER is DEWFORD's GYM LEADER\l"
	.string "BRAWLY!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather:
#if GERMAN
	.string "Du hast Norman in jeder Hinsicht\n"
	.string "übertroffen!\p"
	.string "Das sag ich dir. Und da gibt es\n"
	.string "überhaupt keinen Zweifel dran!$"
#else
	.string "You've surpassed NORMAN in every\n"
	.string "regard!\p"
	.string "I'm telling you, so there's no question\n"
	.string "about it at all!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling:
#if GERMAN
	.string "Selbst in scheinbar aussichtslosen\n"
	.string "Situationen gibt Norman nicht auf.\p"
	.string "Ich weiß, dass das stimmt!\p"
	.string "Und du verhältst dich genauso.\n"
	.string "Also, kämpfe fleißig weiter.$"
#else
	.string "Even when things turned bleak,\n"
	.string "NORMAN never gave up.\p"
	.string "This I know to be true.\p"
	.string "You never give up even if you lose!\n"
	.string "So keep on battling!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman:
#if GERMAN
	.string "Norman hat im Kampf mehr Kraft, \n"
	.string "Charisma und Darbietungstalent\l"
	.string "gezeigt als du.\p"
	.string "Auch wenn die Leute sagen, dass du\n"
	.string "stark bist…\p"
	.string "Du hast noch einen weiten Weg vor dir,\n"
	.string "wenn du so werden willst wie er.$"
#else
	.string "NORMAN battled with more power,\n"
	.string "charisma, and showmanship than you.\p"
	.string "Even though people may say that\n"
	.string "you're strong…\p"
	.string "You've still got a long way to go\n"
	.string "compared to him.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent:
#if GERMAN
	.string "Du bekommst langsam auch die Aura von\n"
	.string "Autorität, die Norman umgibt.\p"
	.string "Aber es gibt einen gewaltigen\n"
	.string "Unterschied zwischen dir und Norman.\p"
	.string "Aber ich kann dir nicht sagen, was das\n"
	.string "ist. Du musst es selbst herausfinden.$"
#else
	.string "You're beginning to get the same\n"
	.string "air of awe NORMAN exudes.\p"
	.string "But there's something conclusively\n"
	.string "different between you and NORMAN.\p"
	.string "I can't tell you what that is.\n"
	.string "You'll have to find it yourself.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers:
#if GERMAN
	.string "Jeder hier ist ein großer Fan von\n"
	.string "Pokémon-Kämpfen.\p"
	.string "Wir diskutieren gerade, welcher\n"
	.string "Trainer der stärkste ist.\p"
	.string "Wenn du berühmt wirst, werden wir\n"
	.string "vielleicht deine Fans!$"
#else
	.string "Everyone here, we're all huge fans\n"
	.string "of POKéMON battles.\p"
	.string "We discuss who we consider to be\n"
	.string "the strongest of all TRAINERS.\p"
	.string "If you were to become famous,\n"
	.string "we might even become your fans!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer:
#if GERMAN
	.string "Kreisch! Das ist {PLAYER}!\n"
	.string "Wirklich und wahrhaftig!!!\p"
	.string "Bitte, schüttle mir die Hand!\n"
	.string "Biiitte!!!$"
#else
	.string "Oh, woweee! It's {PLAYER}!\n"
	.string "For real, too!\p"
	.string "Please, shake my hand, shake my hand!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou:
#if GERMAN
	.string "Ich juble dir ständig zu, {PLAYER}!\n"
	.string "Immer! Iiimmer!\p"
	.string "Ich möchte dich niemals als Verlierer\n"
	.string "sehen, {PLAYER}.\p"
	.string "Ich weiß, dass du sehr, sehr, sehr\n"
	.string "stark bist, {PLAYER}!$"
#else
	.string "I'll always cheer for you, {PLAYER}!\n"
	.string "Always, always!\p"
	.string "I don't want to see you lose ever,\n"
	.string "{PLAYER}.\p"
	.string "Because I know you're really,\n"
	.string "really strong, {PLAYER}!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool:
#if GERMAN
	.string "{STR_VAR_1} ist wirklich megacool…\p"
	.string "Jeder denkt das, stimmt’s? Stimmt’s?!?$"
#else
	.string "{STR_VAR_1} is really cool…\p"
	.string "Everyone thinks so, right, right?$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe:
#if GERMAN
	.string "{STR_VAR_1} ist cooool, meinst du\n"
	.string "nicht auch?\p"
	.string "Selbst ein Würstchen wie ich jubelt\n"
	.string "seinem favorisierten Trainer zu.$"
#else
	.string "{STR_VAR_1} really is cool, don't\n"
	.string "you think so?\p"
	.string "Even if it's just me, I'm going to keep\n"
	.string "cheering my favorite TRAINER.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat:
#if GERMAN
	.string "Mein Lieblings-Trainer muss…\p"
	.string "cool…\p"
	.string "stark…\p"
	.string "und total nett sein…\p"
	.string "Ich wollte, es gäbe so einen Trainer…$"
#else
	.string "My favorite TRAINER is…\p"
	.string "Cool…\p"
	.string "Strong…\p"
	.string "And really nice…\p"
	.string "I wish there was a TRAINER like that…$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou:
#if GERMAN
	.string "Hui! Das ist {PLAYER}!\n"
	.string "Wahnsinn!\p"
	.string "Wenn ich groß bin, möchte ich auch so\n"
	.string "stark sein wie du, {PLAYER}!$"
#else
	.string "Whoa! It's {PLAYER}!\n"
	.string "Wicked!\p"
	.string "When I grow up, I want to be strong\n"
	.string "like you, {PLAYER}!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou:
#if GERMAN
	.string "Auch wenn ich dein einziger Fan bin…\p"
	.string "Ich werde dir immer zujubeln, du bist\n"
	.string "mein Favorit, {PLAYER}!\p"
	.string "Denn ich glaube an dich, {PLAYER}!$"
#else
	.string "Even if I'm the only one…\p"
	.string "You'll always be the only one\n"
	.string "I cheer for, {PLAYER}!\p"
	.string "Because I believe in you, {PLAYER}!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool:
#if GERMAN
	.string "{STR_VAR_1} ist so unverschämt cool…\n"
	.string "Ich möchte meinem Held die Hand\l"
	.string "schütteln.$"
#else
	.string "{STR_VAR_1} is so wickedly cool…\n"
	.string "I want to shake hands with my hero.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan:
#if GERMAN
	.string "Auch wenn ich der einzige Fan bin…\p"
	.string "Ich werde niemals aufhören, ein Fan von\n"
	.string "{STR_VAR_1} zu sein!\p"
	.string "Denn ich habe gehört, dass {STR_VAR_1}\n"
	.string "niemals verliert!$"
#else
	.string "Even if I'm the only one…\p"
	.string "I'm never going to stop being\n"
	.string "{STR_VAR_1}'s fan!\p"
	.string "Because I've heard, {STR_VAR_1}\n"
	.string "never loses!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll:
#if GERMAN
	.string "{PLAYER}!\n"
	.string "Du bist wirklich unglaublich!\p"
	.string "Schon als ich dich das erste Mal\n"
	.string "gesehen habe, habe ich deine\l"
	.string "Einzigartigkeit bemerkt.\p"
	.string "Scheinbar täuschen mich meine Augen\n"
	.string "nie.$"
#else
	.string "{PLAYER}!\n"
	.string "You are amazing after all!\p"
	.string "Ever since I set eyes on you,\n"
	.string "I knew that you were great.\p"
	.string "It looks like my eyes didn't deceive me.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner:
#if GERMAN
	.string "Wen kümmern schon die anderen?\n"
	.string "Ich bin auf deiner Seite!\p"
	.string "Keine Sorge. Geh da raus und kämpfe\n"
	.string "wie immer.$"
#else
	.string "Who cares about the others.\n"
	.string "I'm in your corner!\p"
	.string "You don't need to worry. Just get\n"
	.string "out there and battle like always.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne:
#if GERMAN
	.string "Du bist ein anständiger Trainer.\n"
	.string "Das ist meine Meinung.\p"
	.string "Aber ich denke, {STR_VAR_1} ist im\n"
	.string "Moment die Nummer eins.\p"
	.string "Das ist jedenfalls meine Auffassung.\n"
	.string "Aber lass dir darüber keine grauen\l"
	.string "Haare wachsen.$"
#else
	.string "You're a pretty decent TRAINER,\n"
	.string "I think.\p"
	.string "But I also think that {STR_VAR_1}\n"
	.string "is number one right now.\p"
	.string "That's just my opinion.\n"
	.string "Don't worry about it too much.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer:
#if GERMAN
	.string "Wow, du bist wirklich sehr stark.\n"
	.string "Vielleicht sogar stärker als {STR_VAR_1}.\p"
	.string "Aber {STR_VAR_1} braucht mich.\p"
	.string "Wenn ich {STR_VAR_1} nicht zujuble,\n"
	.string "wer wird es dann tun?$"
#else
	.string "Wow, you really are strong.\n"
	.string "Maybe even stronger than {STR_VAR_1}.\p"
	.string "But {STR_VAR_1} needs me.\p"
	.string "If I don't cheer for {STR_VAR_1},\n"
	.string "who will?$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind:
#if GERMAN
	.string "Du hast mich überzeugt.\n"
	.string "Du bist stark, nicht wahr?\p"
	.string "Würdest du mir bitte erzählen, wie\n"
	.string "du so stark geworden bist?$"
#else
	.string "You've changed my mind!\n"
	.string "You are strong, aren't you?\p"
	.string "I'd like you to tell me how you managed\n"
	.string "to get so strong!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation:
#if GERMAN
	.string "Je schwieriger die Lage, desto\n"
	.string "ästhetischer wird dein Kampf.\p"
	.string "Ich kann deinen nächsten Kampf gar\n"
	.string "nicht erwarten!$"
#else
	.string "The tougher the situation, the more\n"
	.string "attractively you battle.\p"
	.string "I can't wait for your next battle!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout:
#if GERMAN
	.string "Unter den wirklich heißen Trainern hebt\n"
	.string "sich {STR_VAR_1} besonders hervor.\p"
	.string "Diese Stärke. Das ist nicht normal.\p"
	.string "Du kämpfst auch sehr gut, aber du\n"
	.string "gehörst nicht in die gleiche Klasse wie\l"
	.string "{STR_VAR_1}.$"
#else
	.string "Among the recently hot TRAINERS,\n"
	.string "{STR_VAR_1} is the standout.\p"
	.string "That toughness, it's simply not normal.\p"
	.string "You're doing okay, but you're not in\n"
	.string "the same class as {STR_VAR_1}.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger:
#if GERMAN
	.string "Du bist sehr populär…\p"
	.string "Du bist stark und du sorgst gut für\n"
	.string "deine Pokémon.\p"
	.string "Aber, weißt du, ich glaube an {STR_VAR_1}.\p"
	.string "{STR_VAR_1} ist definitiv stärker!\n"
	.string "Ich bin mir da sicher!$"
#else
	.string "You are really popular…\p"
	.string "You're strong, and you're caring to\n"
	.string "POKéMON. No one can knock you.\p"
	.string "But, you know, I believe in {STR_VAR_1}.\p"
	.string "{STR_VAR_1} is definitely stronger!\n"
	.string "I'm positive!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive:
#if GERMAN
	.string "Du…\p"
	.string "Beeindruckend!$"
#else
	.string "You…\p"
	.string "Impressive!$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth:
#if GERMAN
	.string "Dein wahrer Wert… Es ist gut, wenn\n"
	.string "nur ich ihn erkenne.\p"
	.string "Ich glaube nicht, dass die anderen die\n"
	.string "versteckten Kräfte verstehen würden.$"
#else
	.string "Your true worth, it is fine if only\n"
	.string "I recognized it.\p"
	.string "The others I doubt will understand\n"
	.string "the hidden power that beats within.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential:
#if GERMAN
	.string "Ja, deine Augen spiegeln deine Stärke\n"
	.string "wider.\p"
	.string "Aber!\p"
	.string "Du hast dein eigenes Potenzial noch\n"
	.string "nicht erkannt.$"
#else
	.string "Yes, I see strength in your eyes.\p"
	.string "But!\p"
	.string "You still haven't realized your\n"
	.string "potential.$"
#endif

LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength:
#if GERMAN
	.string "Es stimmt, du agierst wirklich sehr\n"
	.string "kraftvoll.\p"
	.string "Aber! Ich sage dir was!\p"
	.string "Diese Kraft kann noch nicht als wahre\n"
	.string "Stärke betrachtet werden!\p"
	.string "Wahre Stärke ist…\n"
	.string "… …\p"
	.string "Äh, eigentlich weiß ich das auch\n"
	.string "nicht…$"
#else
	.string "It is true that you are tremendously\n"
	.string "powerful.\p"
	.string "But!\n"
	.string "I can tell…\p"
	.string "That strength cannot be considered\n"
	.string "true strength yet!\p"
	.string "True strength is…!\n"
	.string "… …\p"
	.string "Actually, I have no idea, either.$"
#endif
