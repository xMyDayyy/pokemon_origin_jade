PetalburgCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
	.byte 0

PetalburgCity_Gym_OnLoad:
#if IS_HNS
	@ HnS: cancel Norman's pending hint call.
	call PetalburgCity_Gym_EventScript_HnsCancelNormanCall
#endif
	goto_if_eq VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_OpenUnlockedDoors
	call_if_ge VAR_PETALBURG_GYM_STATE, 7, PetalburgCity_Gym_EventScript_UnlockAllDoors
	end

@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
#if IS_HNS
PetalburgCity_Gym_EventScript_HnsCancelNormanCall::
	goto_if_unset FLAG_HNS_NORMAN_CALL_PENDING, PetalburgCity_Gym_EventScript_HnsCancelDone
	clearflag FLAG_HNS_NORMAN_CALL_PENDING
	setvar VAR_HNS_NORMAN_CALL_STEPS, 0
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
PetalburgCity_Gym_EventScript_HnsCancelDone::
	return
#endif

PetalburgCity_Gym_EventScript_OpenUnlockedDoors::
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	end

PetalburgCity_Gym_EventScript_UnlockAllDoors::
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	return

PetalburgCity_Gym_OnTransition:
	call_if_eq VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_MoveWallyToEntrance
#if IS_HNS
	@ HnS: Norman always stands in the back room.
	call PetalburgCity_Gym_EventScript_MoveNormanToBackRoom
#else
	call_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_MoveNormanToEntrance
#endif
	call_if_set FLAG_IS_HOENN_CHAMPION, PetalburgCity_Gym_EventScript_CheckNormanForRematch
	end

PetalburgCity_Gym_EventScript_MoveWallyToEntrance::
	setobjectxyperm LOCALID_PETALBURG_GYM_WALLY, 5, 108
	return

PetalburgCity_Gym_EventScript_MoveNormanToEntrance::
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 4, 107
	return

#if IS_HNS
PetalburgCity_Gym_EventScript_MoveNormanToBackRoom::
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 4, 2
	return
#endif

PetalburgCity_Gym_EventScript_CheckNormanForRematch::
#if IS_HNS
	@ HnS: Norman stays in the back room.
	return
#endif
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_NORMAN_1
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	goto_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 4, 107
	return

PetalburgCity_Gym_EventScript_DontMoveNormanToFront::
	setvar VAR_PETALBURG_GYM_STATE, 8
	end

PetalburgCity_Gym_OnWarp:
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
	.2byte 0

PetalburgCity_Gym_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PetalburgCity_Gym_OnFrame:
	@ HnS: state 2 = gym closed until the 4th Hoenn badge.
	map_script_2 VAR_PETALBURG_GYM_STATE, 2, PetalburgCity_Gym_EventScript_ClosedEject
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
	.2byte 0

PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial::
	lockall
	msgbox PetalburgCity_Gym_Text_NormanSoDidItWorkOut, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	delay 30
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_NormanGoCollectBadges, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_GYM_STATE, 2
	releaseall
	end

PetalburgCity_Gym_Movement_WallyExitGym:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

PetalburgCity_Gym_EventScript_Norman::
	vsseeker_rematchid TRAINER_NORMAN_1
	lock
	faceplayer
	switch VAR_PETALBURG_GYM_STATE
#if IS_HNS
	case 0, PetalburgCity_Gym_EventScript_NormanHnsClosed
	case 1, PetalburgCity_Gym_EventScript_NormanHnsClosed
	case 2, PetalburgCity_Gym_EventScript_NormanHnsClosed
	case 3, PetalburgCity_Gym_EventScript_NormanHnsClosed
	case 4, PetalburgCity_Gym_EventScript_NormanHnsClosed
	case 5, PetalburgCity_Gym_EventScript_NormanHnsClosed
#else
	case 0, PetalburgCity_Gym_EventScript_NormanHnsClosed
	case 1, PetalburgCity_Gym_EventScript_NormanHnsClosed
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
#endif
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
	msgbox PetalburgCity_Gym_Text_NormanYoureHereWithYourPokemon, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
	case DIR_NORTH, PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
	end

PetalburgCity_Gym_EventScript_ClosedEject::
	special CountHoennBadges
	goto_if_ge VAR_RESULT, 4, PetalburgCity_Gym_EventScript_OpensWithBadges
	lockall
	msgbox PetalburgCity_Gym_Text_GymIsClosed, MSGBOX_DEFAULT
	closemessage
	warp MAP_PETALBURG_CITY, 15, 8
	waitstate
	releaseall
	end

PetalburgCity_Gym_EventScript_OpensWithBadges::
#if IS_HNS
	@ HnS: runs from ON_FRAME without lockall, so no PokeNav call may start here.
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
#endif
	setvar VAR_PETALBURG_GYM_STATE, 6
	call Common_EventScript_ReadyPetalburgGymForBattle
#if IS_HNS
	@ Origin Jade: open the entrance doors at once; the room doors stay shut.
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	special DrawWholeMapView
#endif
	end

PetalburgCity_Gym_Text_GymIsClosed:
#if GERMAN
	.string "Die Arena von Blütenburg City\n"
	.string "ist zurzeit geschlossen.$"
#else
	.string "The PETALBURG CITY GYM is\n"
	.string "closed at the moment.$"
#endif

PetalburgCity_Gym_EventScript_NormanHnsClosed::
	msgbox PetalburgCity_Gym_Text_NormanHnsClosed, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_Text_NormanHnsClosed:
#if GERMAN
	.string "Willkommen. Ich bin Norman,\n"
	.string "der Arenaleiter von Blütenburg City.\p"
	.string "Die Arena wird zurzeit umgebaut.\n"
	.string "Kämpfe finden hier vorerst nicht statt.\p"
	.string "Wende dich zuerst an Metarost City im\n"
	.string "Norden - dort steht die erste Arena\l"
	.string "von Hoenn.\p"
	.string "Meine Familie wohnt in Wurzelheim,\n"
	.string "falls du dort vorbeikommst.$"
#else
	.string "Welcome. I am NORMAN, the\n"
	.string "GYM LEADER of PETALBURG CITY.\p"
	.string "The GYM is being rebuilt at present.\n"
	.string "No battles are held here for now.\p"
	.string "Go to RUSTBORO CITY in the north\n"
	.string "first - the first GYM of HOENN\l"
	.string "stands there.\p"
	.string "My family lives in LITTLEROOT TOWN,\n"
	.string "should you pass through.$"
#endif

PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth::
	setvar VAR_0x8008, 0
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth::
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialWest::
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialEast::
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorial::
	addobject LOCALID_PETALBURG_GYM_WALLY
	playse SE_DOOR
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_NormanOhYoureWallyRight, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_NormanHmISee, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
	msgbox PetalburgCity_Gym_Text_NormanPlayerGoWithWally, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressWallySouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressWallyWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressWallyEast
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndNormanGivesPokeBall, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanFaceDoorWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanFaceDoorEast
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyFacePlayer
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyFaceDown
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyFacePlayer
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyFacePlayer
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
	removeobject LOCALID_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
	setvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_PETALBURG_CITY_STATE, 2
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	special InitBirchState
	warp MAP_PETALBURG_CITY, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallyArriveSouth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveNorth::
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
	waitmovement 0
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveWestEast::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallySouth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth::
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyWest::
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyEast::
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerWest::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerEast::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallySouth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyNorth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyWest::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyEast::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFacePlayer::
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFaceDown::
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanNoBadges::
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanOneBadge::
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanTwoBadges::
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanThreeBadges::
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanFaceDoorSouth::
	return

@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorWest::
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorEast::
	return

PetalburgCity_Gym_EventScript_NormanPostBattle::
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_GiveEnigmaBerry
	goto_if_unset FLAG_RECEIVED_TM_FACADE, PetalburgCity_Gym_EventScript_GiveFacade2
	goto_if_set FLAG_IS_HOENN_CHAMPION, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
	msgbox PetalburgCity_Gym_Text_NormanGoingToKeepTraining, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GiveFacade2::
	call PetalburgCity_Gym_EventScript_GiveFacade
	release
	end

PetalburgCity_Gym_EventScript_NormanRematch::
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry::
	specialvar VAR_RESULT, IsEnigmaBerryValid
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkitem ITEM_ENIGMA_BERRY_E_READER
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkpcitem ITEM_ENIGMA_BERRY_E_READER
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	goto_if_eq VAR_ENIGMA_BERRY_AVAILABLE, 0, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
	setvar VAR_RESULT, TRUE
	return

PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry::
	setvar VAR_RESULT, FALSE
	return

PetalburgCity_Gym_EventScript_GiveEnigmaBerry::
	giveitem ITEM_ENIGMA_BERRY_E_READER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
	release
	end

PetalburgCity_Gym_EventScript_NormanBattle::
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_BADGE05_GET
	setvar VAR_0x8004, 4
	special SetHoennBadge
	special ResetHealLocationFromDewford
	call EventScript_HideMrBriney
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
	special DrawWholeMapView
	call PetalburgCity_Gym_EventScript_GiveFacade
#if IS_HNS
	@ HnS: the Balance Badge grants the Surf license.
	setvar VAR_0x8004, LIC_SURF
	special SetHoennLicense
#endif
	delay 30
	msgbox PetalburgCity_Gym_Text_NormanAfterDefeat, MSGBOX_DEFAULT
	closemessage
#if IS_HNS
	@ HnS: skip the scene with Wally's father (state 5 = Surf handover done).
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end
#endif
	delay 40
	playse SE_DOOR
	delay 10
	addobject LOCALID_PETALBURG_GYM_WALLYS_DAD
	switch VAR_FACING
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
	end

PetalburgCity_Gym_EventScript_GiveFacade::
	giveitem_unless_owned ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM_FACADE
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
	return

PetalburgCity_Gym_EventScript_WallysDadArrivesNorth::
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrivesEast::
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrivesWest::
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrives::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_Delay48
	waitmovement 0
	delay 10
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 20
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
	removeobject LOCALID_PETALBURG_GYM_WALLYS_DAD
	setvar VAR_PETALBURG_CITY_STATE, 4
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	warp MAP_PETALBURG_CITY, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
	waitmovement 0
	return

PetalburgCity_Gym_Movement_WallysDadExitNorth:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysDadExitEast:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysDadExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth:
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast:
	delay_16
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_WallysDadEnterGym:
	walk_up
	delay_8
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Gym_Movement_Unused:
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_down
	step_end

PetalburgCity_Gym_Movement_WallyArriveNorth:
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

PetalburgCity_Gym_Movement_WallyArrive:
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallyExitNorth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitEast:
	walk_down
	walk_down
	walk_right
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitSouthWest:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallySouth:
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyWest:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyEast:
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough::
	msgbox PetalburgCity_Gym_Text_NormanNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_SpeedRoomDoor::
	lockall
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 85
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_EnterRoom::
	closemessage
	delay 30
	warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009
	waitstate
	releaseall
	end

PetalburgCity_Gym_EventScript_DontEnterRoom::
	releaseall
	end

PetalburgCity_Gym_EventScript_DoorLocked::
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
	releaseall
	end

@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
PetalburgCity_Gym_EventScript_AccuracyRoomDoor::
	lockall
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 98
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_ConfusionRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 46
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightDefenseRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RecoveryRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 72
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightStrengthRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftOHKORoomDoor::
	lockall
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightOHKORoomDoor::
	lockall
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_RandallPostBadge::
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_ParkerPostBadge::
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_George::
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_GeorgePostBadge::
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_BerkePostBadge::
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_MaryPostBadge::
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Alexia::
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_AlexiaPostBadge::
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Jody::
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_JodyPostBadge::
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
	end

@ VAR_0x8004 below is the room number
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors::
	setvar VAR_0x8004, 1
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors::
	setvar VAR_0x8004, 2
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors::
	setvar VAR_0x8004, 3
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors::
	setvar VAR_0x8004, 4
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors::
	setvar VAR_0x8004, 5
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors::
	setvar VAR_0x8004, 6
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors::
	setvar VAR_0x8004, 7
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenOHKORoomDoors::
	setvar VAR_0x8004, 8
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles::
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles::
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles::
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles::
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles::
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles::
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles::
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles::
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SlideOpenRoomDoors::
	special PetalburgGymSlideOpenRoomDoors
	waitstate
	return

PetalburgCity_Gym_EventScript_UnlockRoomDoors::
	special PetalburgGymUnlockRoomDoors
	return

PetalburgCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GymGuidePostVictory::
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_LeftGymStatue::
	lockall
#if IS_HNS
	@ Hoenn badge 5 (Norman)
	setvar VAR_0x8004, 4
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_GymStatueCertified
#else
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
#endif
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_RightGymStatue::
	lockall
#if IS_HNS
	@ Hoenn badge 5 (Norman)
	setvar VAR_0x8004, 4
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_GymStatueCertified
#else
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
#endif
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_GymStatueCertified::
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_EventScript_GymStatue::
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_Text_NormanYoureHereWithYourPokemon:
#if GERMAN
	.string "Hm?\p"
	.string "Ein fremdes Gesicht in meiner Arena.\p"
	.string "Und ein Pokémon, das dir einfach so\n"
	.string "folgt… du bist kein Anfänger.\p"
	.string "Nun gut. Wir sprechen uns noch.$"
#else
	.string "Hmm?\p"
	.string "A face I do not know in my GYM.\p"
	.string "And a POKéMON that simply follows\n"
	.string "you… you are no beginner.\p"
	.string "Very well. We will speak again.$"
#endif

PetalburgCity_Gym_Text_WallyIdLikeAPokemon:
#if GERMAN
	.string "Äh… Ich… Ich hätte so gerne ein\n"
	.string "Pokémon. Bitte…$"
#else
	.string "Um… I…\n"
	.string "I'd like to get a POKéMON, please…$"
#endif

PetalburgCity_Gym_Text_NormanOhYoureWallyRight:
#if GERMAN
	.string "Wie? Du… Ach… Gut.\n"
	.string "Du bist Heiko, nicht wahr?$"
#else
	.string "What? You… Oh… Fine.\n"
	.string "You're WALLY, aren't you?$"
#endif

PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon:
#if GERMAN
	.string "Heiko: Ich werde meine Verwandten\n"
	.string "in Wiesenflur besuchen.\p"
	.string "Ich glaube, ich werde mich da doch\n"
	.string "einsam fühlen, daher würde ich gerne ein\l"
	.string "Pokémon mitnehmen.\p"
	.string "Aber ich habe noch nie eines gefangen.\n"
	.string "Ich weiß nicht, wie das geht…$"
#else
	.string "WALLY: I'm going to go stay with my\n"
	.string "relatives in VERDANTURF TOWN.\p"
	.string "I thought I would be lonely by myself,\n"
	.string "so I wanted to take a POKéMON along.\p"
	.string "But I've never caught a POKéMON before.\n"
	.string "I don't know how…$"
#endif

PetalburgCity_Gym_Text_NormanHmISee:
#if GERMAN
	.string "Oh, ich verstehe…$"
#else
	.string "Oh, I see…$"
#endif

PetalburgCity_Gym_Text_NormanPlayerGoWithWally:
#if GERMAN
	.string "Und du - hilfst du Heiko dabei,\n"
	.string "ein Pokémon zu fangen?$"
#else
	.string "And you - will you help WALLY\n"
	.string "catch a POKéMON?$"
#endif

PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon:
#if GERMAN
#if IS_HNS
	@ Under HnS Wally uses Linoone (see LoadWallyZigzagoon).
	.string "Heiko, hier, ich leihe dir mein Pokémon.\p"
	.string "Heiko hat ein Geradaks erhalten.$"
#else
	.string "Heiko, hier, ich leihe dir mein Pokémon.\p"
	.string "Heiko hat ein Zigzachs erhalten.$"
#endif
#else
#if IS_HNS
	.string "WALLY, here, I'll loan you my POKéMON.\p"
	.string "WALLY received a LINOONE!$"
#else
	.string "WALLY, here, I'll loan you my POKéMON.\p"
	.string "WALLY received a ZIGZAGOON!$"
#endif
#endif

PetalburgCity_Gym_Text_WallyThankYouAndNormanGivesPokeBall:
#if GERMAN
	.string "Heiko: Oh, wow!!!\n"
	.string "Ein Pokémon!\p"
	.string "Hm. Ich gebe dir auch diesen\n"
	.string "Pokéball. Dann leg los!\p"
	.string "Heiko erhält einen Pokéball!$"
#else
	.string "WALLY: Wow!!!\n"
	.string "A POKéMON!\p"
	.string "Here, take this POKé BALL\n"
	.string "as well. Off you go!\p"
	.string "WALLY received a POKé BALL!$"
#endif

PetalburgCity_Gym_Text_WallyOhWowThankYou:
#if GERMAN
	.string "Heiko: Oh, wow!!!\n"
	.string "Danke schön!$"
#else
	.string "WALLY: Oh, wow!\n"
	.string "Thank you!$"
#endif

PetalburgCity_Gym_Text_WouldYouReallyComeWithMe:
#if GERMAN
	.string "{PLAYER}… Kommst du wirklich mit\n"
	.string "mir???$"
#else
	.string "{PLAYER}… Would you really come\n"
	.string "with me?$"
#endif

PetalburgCity_Gym_Text_NormanSoDidItWorkOut:
#if GERMAN
	.string "Und? Hat es geklappt?$"
#else
	.string "Well? Did it work out?$"
#endif

PetalburgCity_Gym_Text_WallyThankYouBye:
#if GERMAN
	.string "Heiko: Danke. Ja, wunderbar.\n"
	.string "Hier haben Sie Ihr Pokémon zurück.\p"
	.string "Danke, {PLAYER}, dass du mit mir\n"
	.string "gegangen bist.\p"
	.string "Euch beiden habe ich es zu verdanken,\n"
	.string "dass ich mein erstes Pokémon fangen\l"
	.string "konnte.\p"
	.string "Ich verspreche, ich werde mich gut\n"
	.string "darum kümmern!\p"
	.string "Oh! Meine Mama wartet sicher schon auf\n"
	.string "mich! Ich muss nach Hause!\p"
	.string "Bis bald, {PLAYER}!$"
#else
	.string "WALLY: Thank you, yes, it did.\n"
	.string "Here's your POKéMON back.\p"
	.string "{PLAYER}, thank you for coming along\n"
	.string "with me.\p"
	.string "You two are why I was able to catch\n"
	.string "my POKéMON.\p"
	.string "I promise I'll take really good\n"
	.string "care of it.\p"
	.string "Oh! My mom's waiting for me,\n"
	.string "so I have to go!\p"
	.string "Bye, {PLAYER}!$"
#endif

PetalburgCity_Gym_Text_NormanGoCollectBadges:
#if GERMAN
	.string "Nun…\p"
	.string "Wenn du in Hoenn etwas erreichen\n"
	.string "willst - hier ist mein Rat.\p"
	.string "Geh nach Metarost City, gleich hinter\n"
	.string "diesem Ort.\p"
	.string "Dort solltest du die Arenaleiterin\n"
	.string "Felizia herausfordern.\p"
	.string "Suche danach die anderen Arenen auf\n"
	.string "und besiege die Leiter.\p"
	.string "Ich bin selbst Arenaleiter. Auch wir\n"
	.string "werden eines Tages gegeneinander\l"
	.string "antreten.\p"
	.string "Aber erst, wenn du dich hier bewährt\n"
	.string "hast.$"
#else
	.string "Well…\p"
	.string "If you want to get somewhere in\n"
	.string "HOENN, here is my advice.\p"
	.string "Go to RUSTBORO CITY, just beyond\n"
	.string "this town.\p"
	.string "Challenge the GYM LEADER there,\n"
	.string "ROXANNE.\p"
	.string "After that, seek out the other GYMS\n"
	.string "and beat their LEADERS.\p"
	.string "I am a GYM LEADER myself. One day\n"
	.string "we two will face each other as well.\p"
	.string "But not before you have proven\n"
	.string "yourself here.$"
#endif

PetalburgCity_Gym_Text_NormanGoToRustboro:
#if GERMAN
	.string "Hm? Wolltest du nicht zur\n"
	.string "Arena in Metarost City?\p"
	.string "Ohne Orden aus Hoenn trete ich nicht\n"
	.string "gegen dich an.\p"
	.string "Fordere mich heraus, sobald du vier\n"
	.string "Orden hast, ja?$"
#else
	.string "Hmm? Were you not going to\n"
	.string "the GYM in RUSTBORO CITY?\p"
	.string "I will not battle you without HOENN\n"
	.string "BADGES.\p"
	.string "Challenge me once you have four of\n"
	.string "them, yes?$"
#endif

PetalburgCity_Gym_Text_NormanGoToDewford:
#if GERMAN
	.string "Oh, ich sehe schon… Du hast die\n"
	.string "Arenaleiterin in Metarost City besiegt.\p"
	.string "Aber es gibt weitere Trainer, die\n"
	.string "stärker sind als du, {PLAYER}.\p"
	.string "Wenn du das Meer überquerst, kommst du\n"
	.string "nach Faustauhaven. Dort triffst du auf\l"
	.string "den Arenaleiter Kamillo.\p"
	.string "Du solltest ihn wirklich herausfordern…$"
#else
	.string "Oh, I see… You beat the GYM\n"
	.string "LEADER in RUSTBORO CITY.\p"
	.string "But there are TRAINERS stronger than\n"
	.string "you still, {PLAYER}.\p"
	.string "Cross the sea and you reach DEWFORD\n"
	.string "TOWN. The GYM LEADER there is\l"
	.string "BRAWLY.\p"
	.string "You really should challenge him…$"
#endif

PetalburgCity_Gym_Text_YouHaveGottenStronger:
#if GERMAN
	.string "Hm… {PLAYER}, du bist stärker\n"
	.string "geworden.\p"
	.string "Das sehe ich an der Anzahl der Orden,\n"
	.string "die du dir verdient hast.$"
#else
	.string "Hmm… {PLAYER}, you have\n"
	.string "grown stronger.\p"
	.string "I can tell by the number of BADGES\n"
	.string "you have earned.$"
#endif

PetalburgCity_Gym_Text_NormanIntro:
#if GERMAN
	.string "Der Umbau ist abgeschlossen.\p"
	.string "Die Arena von Blütenburg City ist\n"
	.string "wieder geöffnet.\p"
	.string "{PLAYER}… Man erzählt sich, du hättest\n"
	.string "jenseits des Meeres schon einiges\l"
	.string "erreicht.\p"
	.string "Umso besser. Kampf ist Kampf!\p"
	.string "Ich werde als Arenaleiter alles tun,\n"
	.string "um zu gewinnen!\p"
	.string "Gib ebenfalls dein Bestes!$"
#else
	.string "The rebuilding is finished.\p"
	.string "The PETALBURG CITY GYM is open\n"
	.string "again.\p"
	.string "{PLAYER}… They say you achieved a\n"
	.string "great deal beyond the sea.\p"
	.string "All the better. A battle is a battle!\p"
	.string "As a GYM LEADER I will do everything\n"
	.string "I can to win!\p"
	.string "Give it your best as well!$"
#endif

PetalburgCity_Gym_Text_NormanDefeat:
#if GERMAN
	.string "…\p"
	.string "Sauber gekämpft.\p"
	.string "Die Regeln der Liga sind eindeutig -\n"
	.string "der Orden gehört dir.$"
#else
	.string "…\p"
	.string "Well fought.\p"
	.string "The rules of the LEAGUE are clear -\n"
	.string "the BADGE is yours.$"
#endif

PetalburgCity_Gym_Text_ReceivedBalanceBadge:
#if GERMAN
	.string "{PLAYER} hat den Balanceorden von\n"
	.string "Norman erhalten!$"
#else
	.string "{PLAYER} received the BALANCE BADGE\n"
	.string "from NORMAN!$"
#endif

PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis:
#if GERMAN
	.string "Mit diesem Orden erhöht sich\n"
	.string "die Verteidigung all deiner Pokémon.\p"
	.string "In Hoenn gilt er außerdem als\n"
	.string "Erlaubnis, Surfer einzusetzen.\p"
	.string "Nimm auch das hier. Ich bin sicher,\n"
	.string "du wirst es gut nutzen.$"
#else
	.string "This BADGE raises the\n"
	.string "DEFENSE of all your POKéMON.\p"
	.string "In HOENN it also serves as your\n"
	.string "permission to use SURF.\p"
	.string "Take this as well. I am sure you\n"
	.string "will put it to good use.$"
#endif

PetalburgCity_Gym_Text_ExplainFacade:
#if GERMAN
	.string "TM42 enthält Fassade.\p"
	.string "Sie verdoppelt die Stärke der Attacken,\n"
	.string "wenn das Pokémon vergiftet,\l"
	.string "paralysiert oder verbrannt wurde.\p"
	.string "So kann eine vermeintlich\n"
	.string "aussichtslose Situation vielleicht\l"
	.string "gerettet werden.$"
#else
	.string "DAD: TM42 contains FACADE.\p"
	.string "It doubles the power of moves if\n"
	.string "the POKéMON is poisoned, paralyzed,\l"
	.string "or burned.\p"
	.string "It might be able to turn a bad\n"
	.string "situation into an advantage.$"
#endif

PetalburgCity_Gym_Text_NormanAfterDefeat:
#if GERMAN
	.string "Als Arenaleiter ärgert mich\n"
	.string "diese Niederlage.\p"
	.string "Als Trainer hat sie mir gezeigt, woran\n"
	.string "ich noch arbeiten muss.$"
#else
	.string "As the GYM LEADER this\n"
	.string "defeat annoys me.\p"
	.string "As a TRAINER it showed me what I\n"
	.string "still have to work on.$"
#endif

PetalburgCity_Gym_Text_PleaseComeWithMe:
#if GERMAN
	.string "Ah, da bist du ja, {PLAYER}{KUN}!\p"
	.string "Komm doch bitte mal mit.\n"
	.string "Ich habe hier etwas für dich.$"
#else
	.string "Ah, there you are, {PLAYER}{KUN}!\p"
	.string "Please come with me.\n"
	.string "I have something I want you to have.$"
#endif

PetalburgCity_Gym_Text_LetMeBorrowPlayer:
#if GERMAN
	.string "Norman, du hast doch nichts dagegen?\p"
	.string "Ich entführe dir {PLAYER}{KUN} mal\n"
	.string "eben für ein paar Minuten.$"
#else
	.string "NORMAN, you don't mind, do you?\p"
	.string "Let me borrow your {PLAYER}{KUN} for\n"
	.string "a minute or two.$"
#endif

PetalburgCity_Gym_Text_NormanGoingToKeepTraining:
#if GERMAN
	.string "Ich bleibe hier und nehme das\n"
	.string "Training wieder auf.\p"
	.string "Kommst du wieder nach Blütenburg\n"
	.string "City, stehe ich anders da.$"
#else
	.string "I will stay here and take up\n"
	.string "my training again.\p"
	.string "Come back to PETALBURG CITY and\n"
	.string "you will find me a different match.$"
#endif

PetalburgCity_Gym_Text_NormanNoAmountOfTrainingIsEnough:
#if GERMAN
	.string "Die Welt der Pokémon ist\n"
	.string "vielfältig.\p"
	.string "Ich bin überzeugt, dass selbst das\n"
	.string "härteste Training dieser Vielfalt nicht\l"
	.string "gerecht wird.$"
#else
	.string "The world of POKéMON is\n"
	.string "deep.\p"
	.string "I honestly think that no amount of\n"
	.string "training would ever be enough.$"
#endif

PetalburgCity_Gym_Text_GymGuideAdvice:
#if GERMAN
	.string "Na, wie sieht es aus, auf dem Weg zum\n"
	.string "Champ, {PLAYER}?\p"
	.string "Die Türen dieser Arena öffnen sich,\n"
	.string "wenn du die einzelnen Trainer besiegst.\p"
	.string "Huups! Die Türen in diesem Raum sind ja\n"
	.string "schon offen, greif mich bitte nicht\p"
	.string "an! \p"
	.string "Die Trainer der Arena von Blütenburg\n"
	.string "City setzen die verschiedensten Items\l"
	.string "ein.\p"
	.string "Die Tür auf der linken Seite führt in\n"
	.string "den Initiative-Raum.\p"
	.string "Die Tür auf der rechten Seite führt in\n"
	.string "den Raum der Genauigkeit.\p"
	.string "Die Türen sind beschriftet, lies genau\n"
	.string "und triff eine überlegte Wahl.\p"
	.string "Hast du dich für eine Tür entschieden…\n"
	.string "Nun, ähm, genug der Worte!$"
#else
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "The doors in this GYM open when you\n"
	.string "beat the awaiting TRAINERS.\p"
	.string "Whoops! The doors in this room are\n"
	.string "already open, so don't attack me!\p"
	.string "The TRAINERS of PETALBURG GYM\n"
	.string "use all kinds of items.\p"
	.string "The door at the left leads to\n"
	.string "the SPEED ROOM.\p"
	.string "The door at the right leads to\n"
	.string "the ACCURACY ROOM.\p"
	.string "The room's name will be on\n"
	.string "the door, so choose carefully.\p"
	.string "Once you've chosen the door…\n"
	.string "Well, hey, go for it!$"
#endif

PetalburgCity_Gym_Text_GymGuidePostVictory:
#if GERMAN
	.string "{PLAYER}! Hui! Du hast Norman\n"
	.string "besiegt!\p"
	.string "Wie… Unglaublich!\n"
	.string "Die Ereignisse überschlagen sich!$"
#else
	.string "{PLAYER}! Whoa! You beat NORMAN!\p"
	.string "How… Incredible!\n"
	.string "Things are moving fast!$"
#endif

PetalburgCity_Gym_Text_RandallIntro:
#if GERMAN
	.string "Die Fähigkeit, dem Gegner mit einer\n"
	.string "Attacke zuvorzukommen…\p"
	.string "Das alleine gibt einem doch schon einen\n"
	.string "enormen Vorteil, meinst du nicht auch?$"
#else
	.string "The ability to attack before the\n"
	.string "opponent…\p"
	.string "Just that alone puts me at a great\n"
	.string "advantage, don't you agree?$"
#endif

PetalburgCity_Gym_Text_RandallDefeat:
#if GERMAN
	.string "Das war ein unglaublicher Kampf!$"
#else
	.string "That was a magnificent battle!$"
#endif

PetalburgCity_Gym_Text_RandallPostBattle:
#if GERMAN
	.string "Geh weiter in den nächsten Raum, wo\n"
	.string "eine neue Herausforderung wartet.\p"
	.string "Auf der linken Seite befindet sich der\n"
	.string "Raum der Verwirrung.\p"
	.string "Auf der rechten Seite findest du den\n"
	.string "Raum der Verteidigung.$"
#else
	.string "Go on to the next room where a new\n"
	.string "challenge awaits you.\p"
	.string "At the left is the CONFUSION ROOM.\p"
	.string "The right door leads to the DEFENSE\n"
	.string "ROOM.$"
#endif

PetalburgCity_Gym_Text_RandallPostBadge:
#if GERMAN
	.string "Ob du siegst oder verlierst… Du darfst\n"
	.string "dein Training und das deiner Pokémon\l"
	.string "auf keinen Fall vernachlässigen.\p"
	.string "Das macht für mich einen wahren\n"
	.string "Arenaleiter aus.$"
#else
	.string "Whomever you beat, and whomever you\n"
	.string "may lose to, you never shirk from\l"
	.string "training yourself and your POKéMON.\p"
	.string "That's what I think being a\n"
	.string "GYM LEADER is all about.$"
#endif

PetalburgCity_Gym_Text_ParkerIntro:
#if GERMAN
	.string "Dies ist der Raum der Verwirrung.\p"
	.string "Zeig mir, wie stark das Band zwischen\n"
	.string "dir und deinen Pokémon ist.$"
#else
	.string "This is the CONFUSION ROOM.\p"
	.string "Let me see how well bonded you are\n"
	.string "with your POKéMON!$"
#endif

PetalburgCity_Gym_Text_ParkerDefeat:
#if GERMAN
	.string "Ich konnte dein Team nicht genug\n"
	.string "verwirren… Euer Band ist stark.$"
#else
	.string "I couldn't confuse your team enough…\n"
	.string "You share a strong bond together.$"
#endif

PetalburgCity_Gym_Text_ParkerPostBattle:
#if GERMAN
	.string "Der nächste Raum ist der Raum der\n"
	.string "Stärke. Kommst du gegen pure Gewalt\l"
	.string "an?$"
#else
	.string "The next room is the STRENGTH ROOM.\n"
	.string "Can you withstand brute force?$"
#endif

PetalburgCity_Gym_Text_ParkerPostBadge:
#if GERMAN
	.string "Nachdem du unseren Arenaleiter besiegt\n"
	.string "hast, wurde unser Training härter.$"
#else
	.string "After you beat our LEADER, the\n"
	.string "training has become a lot tougher.$"
#endif

PetalburgCity_Gym_Text_GeorgeIntro:
#if GERMAN
	.string "Immer, wenn du den Sieg in greifbarer\n"
	.string "Nähe siehst, füllt dein Gegner KP auf…\l"
	.string "\p"
	.string "Kannst du dir vorstellen, wie man sich\n"
	.string "in so einer Situation fühlt?\p"
	.string "Ich werde dir so eine Situation\n"
	.string "demonstrieren!$"
#else
	.string "Just when you think you're going to\n"
	.string "win, your opponent restores HP…\p"
	.string "Can you just imagine how awful that\n"
	.string "must feel?\p"
	.string "I'll show you exactly how awful it\n"
	.string "feels!$"
#endif

PetalburgCity_Gym_Text_GeorgeDefeat:
#if GERMAN
	.string "Ich konnte nicht genügend KP\n"
	.string "auffüllen… Welch eine Angriffskraft…$"
#else
	.string "I couldn't restore HP enough…\n"
	.string "What ATTACK power…$"
#endif

PetalburgCity_Gym_Text_GeorgePostBattle:
#if GERMAN
	.string "Die Fähigkeiten eines Trainers\n"
	.string "entwickeln sich mit dem Training.\p"
	.string "Ich habe mich offensichtlich nicht\n"
	.string "genug angestrengt.\p"
	.string "Geh! Der nächste Raum ist der K.O.-\n"
	.string "Treffer-Raum.$"
#else
	.string "A TRAINER's abilities are earned\n"
	.string "only through effort.\p"
	.string "I clearly did not work hard enough.\p"
	.string "Go on! The next room is the OHKO\n"
	.string "ROOM.$"
#endif

PetalburgCity_Gym_Text_GeorgePostBadge:
#if GERMAN
	.string "Ich werde auch weiterhin in den Arenen\n"
	.string "trainieren. Und Arenaleiter werden!$"
#else
	.string "I'm going to keep training at GYMS.\n"
	.string "One day, I'll become a LEADER.$"
#endif

PetalburgCity_Gym_Text_BerkeIntro:
#if GERMAN
	.string "Ich werde es dir nicht leicht machen.\p"
	.string "Ich werde dir beibringen, was es für ein\n"
	.string "Pokémon bedeutet, einen Volltreffer zu\l"
	.string "erhalten.$"
#else
	.string "I'm not going to take it easy on you.\p"
	.string "I'll show you how horrid it is for\n"
	.string "a POKéMON to take a critical hit!$"
#endif

PetalburgCity_Gym_Text_BerkeDefeat:
#if GERMAN
	.string "Deine Stärke…\n"
	.string "Du kämpfst großartig!$"
#else
	.string "Your power…\n"
	.string "You're the real deal.$"
#endif

PetalburgCity_Gym_Text_BerkePostBattle:
#if GERMAN
	.string "Norman ist stark. Als Trainer erweise\n"
	.string "ich ihm den größten Respekt.\p"
	.string "Und ich sehe, dass die gleiche Stärke\n"
	.string "auch in dir ruht.\p"
	.string "Ich fühle, dass du dich nun einem\n"
	.string "Kampf mit ihm stellen kannst.$"
#else
	.string "NORMAN is strong. As a TRAINER I\n"
	.string "give him my utmost respect.\p"
	.string "And I see the same strength resting\n"
	.string "in you.\p"
	.string "I feel you are ready to face him\n"
	.string "now.$"
#endif

PetalburgCity_Gym_Text_BerkePostBadge:
#if GERMAN
	.string "Seit Norman die Arena von Blütenburg\n"
	.string "City leitet, sind die Trainer hier viel\l"
	.string "stärker geworden.$"
#else
	.string "Since NORMAN has led the PETALBURG\n"
	.string "GYM, the TRAINERS here have grown\l"
	.string "much stronger.$"
#endif

PetalburgCity_Gym_Text_MaryIntro:
#if GERMAN
	.string "Kicher…\n"
	.string "Dies ist der Raum der Genauigkeit.\p"
	.string "Es ist schon ziemlich fies, wenn jede\n"
	.string "Attacke ein Treffer ist.$"
#else
	.string "Giggle…\n"
	.string "This is the ACCURACY ROOM.\p"
	.string "It's pretty nasty when every attack\n"
	.string "lands without fail.$"
#endif

PetalburgCity_Gym_Text_MaryDefeat:
#if GERMAN
	.string "Du bist ein bisschen stärker als ich…$"
#else
	.string "You were a cut above me…$"
#endif

PetalburgCity_Gym_Text_MaryPostBattle:
#if GERMAN
	.string "Es warten noch weitaus stärkere\n"
	.string "Trainer auf dich.\p"
	.string "Der linke ist der Raum der Verteidigung\n"
	.string "und der rechte der Raum der Erholung.\p"
	.string "\p"
	.string "Die Attacken deiner Pokémon werden in\n"
	.string "beiden Räumen auf die Probe gestellt.$"
#else
	.string "There are some even stronger\n"
	.string "TRAINERS waiting for you.\p"
	.string "The left is the DEFENSE ROOM, and\n"
	.string "the right is the RECOVERY ROOM.\p"
	.string "Your POKéMON's ATTACK power will be\n"
	.string "on trial either way.$"
#endif

PetalburgCity_Gym_Text_MaryPostBadge:
#if GERMAN
	.string "Weißt du, wonach wir als Trainer\n"
	.string "streben?\p"
	.string "Wir streben danach, die Seelenfreunde\n"
	.string "unserer Pokémon zu werden.$"
#else
	.string "Do you know what we're trying to\n"
	.string "achieve as TRAINERS?\p"
	.string "We're striving to become soul mates\n"
	.string "with our POKéMON.$"
#endif

PetalburgCity_Gym_Text_AlexiaIntro:
#if GERMAN
	.string "Je stärker die Verteidigung ist, desto\n"
	.string "rücksichtsloser kann ich angreifen.$"
#else
	.string "The higher the DEFENSE, the more\n"
	.string "reckless I can be in attack.$"
#endif

PetalburgCity_Gym_Text_AlexiaDefeat:
#if GERMAN
	.string "Unsere Verteidigung reichte nicht aus…$"
#else
	.string "Our defenses weren't enough…$"
#endif

PetalburgCity_Gym_Text_AlexiaPostBattle:
#if GERMAN
	.string "Ich denke, du hast mir eine wertvolle\n"
	.string "Lektion erteilt.\p"
	.string "Nun, geh weiter. Die linke Tür führt\n"
	.string "in den Raum der Stärke.\p"
	.string "Die rechte Tür öffnet den\n"
	.string "K.O.-Treffer-Raum.\p"
	.string "In beiden warten äußerst talentierte\n"
	.string "Trainer.$"
#else
	.string "I think you've taught me a valuable\n"
	.string "lesson here.\p"
	.string "Now, go on! The left door goes to\n"
	.string "the STRENGTH ROOM.\p"
	.string "The right door opens to\n"
	.string "the ONE-HIT KO ROOM.\p"
	.string "Both of them have TRAINERS who are\n"
	.string "skilled at offense.$"
#endif

PetalburgCity_Gym_Text_AlexiaPostBadge:
#if GERMAN
	.string "Hallo! Hast du mal Surfer ausprobiert?$"
#else
	.string "Hi! Have you tried using SURF?$"
#endif

PetalburgCity_Gym_Text_JodyIntro:
#if GERMAN
	.string "Unser Arenaleiter hat uns angewiesen,\n"
	.string "alles zu geben.\p"
	.string "Und genau das habe ich vor!$"
#else
	.string "Our GYM LEADER told us to go all out.\p"
	.string "And that is exactly what I intend to\n"
	.string "do!$"
#endif

PetalburgCity_Gym_Text_JodyDefeat:
#if GERMAN
	.string "Aber… Das war wohl nichts!$"
#else
	.string "But… I went all out!$"
#endif

PetalburgCity_Gym_Text_JodyPostBattle:
#if GERMAN
	.string "Wie du deine Pokémon einsetzt…\n"
	.string "Du erinnerst mich an unseren Leiter.\p"
	.string "Geh weiter! Norman erwartet dich\n"
	.string "bereits!$"
#else
	.string "The way you use your POKéMON…\n"
	.string "You remind me of our LEADER.\p"
	.string "Go on! NORMAN is waiting for you\n"
	.string "already!$"
#endif

PetalburgCity_Gym_Text_JodyPostBadge:
#if GERMAN
	.string "Sicher, es ist immer von Vorteil, die\n"
	.string "Pokémon stärker werden zu lassen.\p"
	.string "Aber was macht einen Gewinner aus?\p"
	.string "Nun, das sind die Gefühle, die ein\n"
	.string "Trainer seinen Pokémon entgegenbringt.$"
#else
	.string "Sure, it's fine to make your POKéMON\n"
	.string "stronger.\p"
	.string "But what decides the winner?\p"
	.string "Why, it's the feelings TRAINERS have\n"
	.string "for their POKéMON.$"
#endif

PetalburgCity_Gym_Text_DoorAppearsLocked:
#if GERMAN
	.string "Die Tür ist noch verschlossen…$"
#else
	.string "This door appears to be locked\n"
	.string "right now…$"
#endif

PetalburgCity_Gym_Text_EnterSpeedRoom:
#if GERMAN
	.string "“Initiative-Raum” steht auf\n"
	.string "dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
#else
	.string "“SPEED ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
#endif

@ Unused
PetalburgCity_Gym_Text_DoorAppearsLocked2:
#if GERMAN
	.string "Die Tür ist noch verschlossen…$"
#else
	.string "This door appears to be locked\n"
	.string "right now…$"
#endif

PetalburgCity_Gym_Text_EnterAccuracyRoom:
#if GERMAN
	.string "“Raum der Genauigkeit” steht\n"
	.string "auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
#else
	.string "“ACCURACY ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
#endif

PetalburgCity_Gym_Text_EnterConfusionRoom:
#if GERMAN
	.string "“Raum der Verwirrung”\n"
	.string "steht auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
#else
	.string "“CONFUSION ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
#endif

PetalburgCity_Gym_Text_EnterDefenseRoom:
#if GERMAN
	.string "“Raum der Verteidigung” steht\n"
	.string "auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
#else
	.string "“DEFENSE ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
#endif

PetalburgCity_Gym_Text_EnterRecoveryRoom:
#if GERMAN
	.string "“Raum der Erholung” steht auf\n"
	.string "dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
#else
	.string "“RECOVERY ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
#endif

PetalburgCity_Gym_Text_EnterStrengthRoom:
#if GERMAN
	.string "“Raum der Stärke” steht auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
#else
	.string "“STRENGTH ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
#endif

PetalburgCity_Gym_Text_EnterOHKORoom:
#if GERMAN
	.string "“K.O.-Treffer-Raum”\n"
	.string "steht auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
#else
	.string "“ONE-HIT KO ROOM,” the sign says.\p"
	.string "Do you want to go through?$"
#endif

PetalburgCity_Gym_Text_EnterGymLeadersRoom:
#if GERMAN
	.string "“Arenaleiter”\p"
	.string "“Sieh selbst, welche Pokémon dich\n"
	.string "erwarten!” steht auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"
#else
	.string "“GYM LEADER'S ROOM\p"
	.string "“See for yourself what POKéMON await\n"
	.string "you!” the sign says.\p"
	.string "Do you want to go through?$"
#endif

PetalburgCity_Gym_Text_GymStatue:
#if GERMAN
	.string "Pokémon Arena von Blütenburg City$"
#else
	.string "PETALBURG CITY POKéMON GYM$"
#endif

PetalburgCity_Gym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon Arena von Blütenburg City\p"
	.string "Normans anerkannte Trainer:\n"
	.string "{PLAYER}$"
#else
	.string "PETALBURG CITY POKéMON GYM\p"
	.string "NORMAN'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif

PetalburgCity_Gym_Text_NormanPreRematch:
#if GERMAN
	.string "Du willst es noch einmal\n"
	.string "wissen?\p"
	.string "Eine Herausforderung schlage ich nicht\n"
	.string "aus - dafür bin ich Arenaleiter.\p"
	.string "In einer Arena zählt nur eines: dass\n"
	.string "beide ihr Bestes geben.$"
#else
	.string "You want another go?\p"
	.string "I never turn down a challenge -\n"
	.string "that is what a GYM LEADER is for.\p"
	.string "In a GYM only one thing counts:\n"
	.string "that both sides give their best.$"
#endif

PetalburgCity_Gym_Text_NormanRematchDefeat:
#if GERMAN
	.string "Äh… Haha…\n"
	.string "Du bist ein harter Brocken…$"
#else
	.string "Uh… Haha…\n"
	.string "Maybe that was going too hard…$"
#endif

PetalburgCity_Gym_Text_NormanPostRematch:
#if GERMAN
	.string "Wieder verloren.\p"
	.string "Aber ein Kampf gegen einen Trainer\n"
	.string "deines Formats bringt mich weiter.\p"
	.string "Komm ruhig wieder vorbei.$"
#else
	.string "Beaten again.\p"
	.string "But a battle against a TRAINER of\n"
	.string "your calibre moves me forward.\p"
	.string "Do come by again.$"
#endif

PetalburgCity_Gym_Text_NormanRematchNeedTwoMons:
#if GERMAN
	.string "Du willst es noch einmal\n"
	.string "wissen?\p"
	.string "Eine Herausforderung schlage ich nicht\n"
	.string "aus - dafür bin ich Arenaleiter.\p"
	.string "Hm? Warte.\p"
	.string "Du hast nur ein Pokémon, das kämpfen\n"
	.string "kann?\p"
	.string "Tut mir Leid, aber du brauchst\n"
	.string "mindestens zwei Pokémon.$"
#else
	.string "You want another go?\p"
	.string "I never turn down a challenge -\n"
	.string "that is what a GYM LEADER is for.\p"
	.string "Hmm? Wait a moment.\p"
	.string "You have only one POKéMON able to\n"
	.string "battle?\p"
	.string "I am sorry, but you need at least\n"
	.string "two.$"
#endif

#if IS_HNS
@ Unused.
PetalburgCity_Gym_Text_HnsRegisteredNorman:
#if GERMAN
	.string "Normans Nummer wurde im PokéCom-\n"
	.string "Verzeichnis eingetragen.$"
#else
	.string "Registered NORMAN\n"
	.string "in the POKéNAV.$"
#endif

@ Unused.
PetalburgCity_Gym_Text_HnsSurfLicense:
#if GERMAN
	.string "Und hier ist die Surflizenz.\p"
	.string "Sie berechtigt dich, Surfer überall in\n"
	.string "Hoenn einzusetzen.\p"
	.string "{PLAYER} erhält die Lizenz für\n"
	.string "Surfer!$"
#else
	.string "And here is the SURF LICENCE.\p"
	.string "It entitles you to use SURF anywhere\n"
	.string "in HOENN.\p"
	.string "{PLAYER} received the licence for\n"
	.string "SURF!$"
#endif
#endif
