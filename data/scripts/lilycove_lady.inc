LilycoveCity_PokemonCenter_1F_EventScript_LilycoveLady::
	special Script_GetLilycoveLadyId
	switch VAR_RESULT
	case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCenter_1F_EventScript_QuizLady
	case LILYCOVE_LADY_FAVOR, LilycoveCity_PokemonCenter_1F_EventScript_FavorLady
	case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCenter_1F_EventScript_ContestLady
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetFavorLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasAnotherPlayerGivenFavorLadyItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem::
	special BufferFavorLadyItemName
	special BufferFavorLadyPlayerName
	specialvar VAR_RESULT, DidFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_RequestItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_FavorLadyOpenBagMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem::
	specialvar VAR_RESULT, Script_DoesFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem::
	specialvar VAR_RESULT, IsFavorLadyThresholdMet
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize::
	setvar VAR_0x8004, 0
	specialvar VAR_0x8004, FavorLadyGetPrize
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn, MSGBOX_DEFAULT
	giveitem VAR_0x8004
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize::
	special SetFavorLadyState_Complete
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuizLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetQuizLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz::
	specialvar VAR_RESULT, GetQuizAuthor
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_LADY, LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz::
	specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz::
	setvar VAR_0x8004, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowBoringBye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz::
	special ClearQuizLadyPlayerAnswer
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion
	goto_if_eq VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER, LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer

LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState::
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion::
	special QuizLadyShowQuizQuestion
	waitstate
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer::
	special QuizLadyGetPlayerAnswer
	waitstate
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse::
	special SetQuizLadyState_Complete
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsQuizAnswerCorrect
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse::
	playse SE_SUCCESS
	delay 10
	playse SE_SUCCESS
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRight, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse::
	special BufferQuizCorrectAnswer
	special BufferQuizPrizeName
	playse SE_FAILURE
	delay 10
	playse SE_FAILURE
	msgbox LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs, MSGBOX_DEFAULT
	msgbox LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

@ VAR_RESULT is essentially ignored, both jumps are identical
LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize::
	specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize::
	setvar VAR_0x8005, 0
	special BufferQuizPrizeItem
	special SetQuizLadyState_Complete
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp, MSGBOX_DEFAULT
	special SetQuizLadyState_GivePrize
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz::
	special QuizLadyPickNewQuestion
	msgbox LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PickYourPrize, MSGBOX_DEFAULT
LilycoveCity_PokemonCenter_1F_EventScript_PickPrize::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_QuizLadyOpenBagMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_PickPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz, MSGBOX_DEFAULT
	special ClearQuizLadyQuestionAndAnswer
	special ClearQuizLadyPlayerAnswer
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION
LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion::
	fadescreen FADE_TO_BLACK
	special QuizLadySetCustomQuestion
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion
	end

LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz::
	special QuizLadyTakePrizeForCustomQuiz
	special QuizLadyRecordCustomQuizData
	special QuizLadySetWaitingForChallenger
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

@ Redundant with above script, VAR_RESULT will always be FALSE here
LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality, MSGBOX_DEFAULT
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase
	msgbox LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseForContestLady
	waitstate
	goto_if_eq VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock
	goto_if_ne VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock, MSGBOX_DEFAULT
	special SetContestLadyGivenPokeblock
	special GetContestLadyMonSpecies
	goto LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon
	waitmovement 0
	delay 60
	applymovement LOCALID_LILYCOVE_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady
	waitmovement 0
	delay 60
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	delay 120
	waitmoncry
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock::
	applymovement LOCALID_LILYCOVE_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonJump
	waitmovement 0
	delay 60
LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer
	waitmovement 0
	delay 60
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests, MSGBOX_DEFAULT
	special PutLilycoveContestLadyShowOnTheAir
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase::
	msgbox LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon:
	face_right
	delay_8
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady:
	face_left
	delay_8
	step_end

@ Unused
LilycoveCity_PokemonCenter_1F_Movement_MonFaceDown:
	face_down
	step_end

LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer:
	face_player
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonJump:
	disable_jump_landing_ground_effect
	jump_in_place_left
	disable_jump_landing_ground_effect
	jump_in_place_left
	step_end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLadyMon::
	specialvar VAR_RESULT, GetContestLadyCategory
	special Script_BufferContestLadyCategoryAndMonName
	special GetContestLadyMonSpecies
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_COOL, LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_BEAUTY, LilycoveCity_PokemonCenter_1F_EventScript_Skitty
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_CUTE, LilycoveCity_PokemonCenter_1F_EventScript_Poochyena
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_SMART, LilycoveCity_PokemonCenter_1F_EventScript_Kecleon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_TOUGH, LilycoveCity_PokemonCenter_1F_EventScript_Pikachu
	end

LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady:
#if GERMAN
	.string "Ich bin die Servicelady…$"
#else
	.string "I'm the FAVOR LADY…$"
#endif

LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing:
#if GERMAN
	.string "Im Moment interessiere ich mich\n"
	.string "brennend für “{STR_VAR_1}”…$"
#else
	.string "I've recently developed an obsession\n"
	.string "for {STR_VAR_1} things…$"
#endif

LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime:
#if GERMAN
	.string "Oh…\n"
	.string "Vielen Dank nochmals!$"
#else
	.string "Oh…\n"
	.string "Thank you for last time…$"
#endif

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing:
#if GERMAN
	.string "Ich dachte, es wäre {STR_VAR_3}\n"
	.string "gewesen…\p"
	.string "{STR_VAR_3} hat mir 1 {STR_VAR_2} geschenkt\n"
	.string "und gesagt, es wäre\p"
	.string "{STR_VAR_1}. Aber das stimmte gar nicht!\n"
	.string "Überhaupt nicht!$"
#else
	.string "Before, I think it was {STR_VAR_3}…\p"
	.string "{STR_VAR_3} gave me one {STR_VAR_2},\n"
	.string "saying it was {STR_VAR_1}.\p"
	.string "But it wasn't {STR_VAR_1}.\n"
	.string "Not in the least bit.$"
#endif

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing:
#if GERMAN
	.string "Vorher gab mir {STR_VAR_3} 1\n"
	.string "{STR_VAR_1}/e/en/es {STR_VAR_2}.\p"
	.string "Ganz mein Geschmack!$"
#else
	.string "Before, {STR_VAR_3} gave me a very\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "I cherish it now.$"
#endif

LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing:
#if GERMAN
	.string "Du, hör mal! Wenn du etwas hast, das\n"
	.string "unter die Kategorie “{STR_VAR_1}” fällt,\l"
	.string "gibst du mir etwas davon ab?!?$"
#else
	.string "Listen, if you have anything that\n"
	.string "is {STR_VAR_1}, will you share it\l"
	.string "with me?$"
#endif

LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe:
#if GERMAN
	.string "Wirklich?!? Echt?!?\n"
	.string "Oh! Und was gibst du mir?!?$"
#else
	.string "…Really?\n"
	.string "What will you give me?$"
#endif

LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye:
#if GERMAN
	.string "Ehrlich?\n"
	.string "Na, dann mach’s gut…$"
#else
	.string "Is that so?\n"
	.string "Then, it's good-bye…$"
#endif

LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare:
#if GERMAN
	.string "Oh…\n"
	.string "Du willst nicht teilen?$"
#else
	.string "Oh…\n"
	.string "You're not willing to share?$"
#endif

LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt:
#if GERMAN
	.string "Mh?\n"
	.string "{STR_VAR_2}… {STR_VAR_1}?\p"
	.string "Und das soll stimmen?\p"
	.string "Nun, ich muss mich trotzdem bei dir\n"
	.string "bedanken. Ich weiß es zu schätzen…$"
#else
	.string "Oh?\n"
	.string "That {STR_VAR_2} is {STR_VAR_1}?\p"
	.string "…Oh, is that right?\p"
	.string "Well, I owe you a thanks anyway.\n"
	.string "I'll try to cherish it…$"
#endif

LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis:
#if GERMAN
	.string "Oh…\p"
	.string "{STR_VAR_2} ist schon ganz\n"
	.string "{STR_VAR_1}…\p"
	.string "Ist das nicht toll?\n"
	.string "Einfach traumhaft…\p"
	.string "Vielen Dank…\n"
	.string "Ich werde gut darauf Acht geben…$"
#else
	.string "Oh…\p"
	.string "That's a quite {STR_VAR_1}\n"
	.string "{STR_VAR_2}…\p"
	.string "Isn't it nice?\n"
	.string "It's so dreamy…\p"
	.string "Thank you…\n"
	.string "I will cherish this…$"
#endif

LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis:
#if GERMAN
	.string "Uih… Oh…\p"
	.string "Das ist fan-tas-tisch!!!\n"
	.string "Das ist wirklich {STR_VAR_1}!!!\p"
	.string "Ich hätte nie gedacht, dass {STR_VAR_2}\n"
	.string "so {STR_VAR_1} sein\p"
	.string "könnte! Vielen Dank!\p"
	.string "Ich werde das bis an mein Lebensende\n"
	.string "bewahren und beschützen!$"
#else
	.string "…Oh, oh, oh…\p"
	.string "This is amazing!\n"
	.string "This really is {STR_VAR_1}!\p"
	.string "I never knew that one {STR_VAR_2}\n"
	.string "could be this {STR_VAR_1}!\p"
	.string "Thank you!\p"
	.string "I will treasure this for the rest\n"
	.string "of my life!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn:
#if GERMAN
	.string "Ich gebe dir dieses wunderbare Item als\n"
	.string "Dank für dein sagenhaftes Geschenk!\p"
	.string "Ich hoffe, du weißt es zu schätzen…$"
#else
	.string "I'll give you this wonderful item in\n"
	.string "return for your fabulous gift.\p"
	.string "I hope you will cherish it…$"
#endif

LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt:
#if GERMAN
	.string "Oh, schade! Wenn du keinen Platz hast,\n"
	.string "kann ich es dir leider nicht geben.\p"
	.string "Hol es dir doch ab, sobald du in deinem\n"
	.string "Beutel etwas aufgeräumt hast.$"
#else
	.string "Oh, you can't have it if you don't have\n"
	.string "the space for it.\p"
	.string "Please come see me when you get\n"
	.string "your BAG organized…$"
#endif

LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady:
#if GERMAN
	.string "Ich bin die Quizlady!\n"
	.string "Ich liiiiebe Quizze!$"
#else
	.string "I'm the QUIZ LADY!\n"
	.string "I love quizzes!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz:
#if GERMAN
	.string "Bitte?\p"
	.string "Ich warte auf einen Herausforderer,\n"
	.string "der sich traut, sich meinen Fragen zu\p"
	.string "stellen. Wir können ja später mal ein\n"
	.string "Schwätzchen halten.$"
#else
	.string "Oh?\p"
	.string "I'm waiting for a challenger to answer\n"
	.string "the quiz you made.\p"
	.string "We can chat another time, okay?$"
#endif

LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger:
#if GERMAN
	.string "Ich warte auf einen Herausforderer, der\n"
	.string "sich dem Quiz von {STR_VAR_1} stellt!$"
#else
	.string "I'm waiting for someone to challenge\n"
	.string "a quiz this {STR_VAR_1} thought up!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge:
#if GERMAN
	.string "Wenn du richtig antwortest, gewinnst du\n"
	.string "tolle Preise!\p"
	.string "Möchtest du es einmal versuchen?$"
#else
	.string "If you answer correctly, you can win\n"
	.string "fabulous prizes!\p"
	.string "Would you like to take the quiz\n"
	.string "challenge?$"
#endif

LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer:
	.string "… … … … … …\n"
	.string "… … … … … …$"

LilycoveCity_PokemonCenter_1F_Text_HowBoringBye:
#if GERMAN
	.string "Pah, wie langweilig!\n"
	.string "Mach’s gut!$"
#else
	.string "Oh, how boring!\n"
	.string "Bye-bye!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit:
#if GERMAN
	.string "Uuuuuh!\n"
	.string "Gibst du schon auf?$"
#else
	.string "Awww!\n"
	.string "You're going to quit?$"
#endif

LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime:
#if GERMAN
	.string "Ich hoffe, du nimmst später an meinem\n"
	.string "Quiz teil!$"
#else
	.string "Please take the quiz challenge\n"
	.string "another time!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_YouGotItRight:
#if GERMAN
	.string "Unglaublich! Du hast alles richtig\n"
	.string "beantwortet! Du bist echt klug!$"
#else
	.string "You're amazing! You've got it right!\n"
	.string "You're one sharp customer!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize:
#if GERMAN
	.string "Herzlichen Glückwunsch!\n"
	.string "Du hast gewonnen!\p"
	.string "{STR_VAR_1} hat für dich einen Preis\n"
	.string "gestiftet!$"
#else
	.string "Congratulations!\n"
	.string "You've got the quiz right!\p"
	.string "You've won a prize provided by\n"
	.string "{STR_VAR_1}!$"
#endif

@ Unused
LilycoveCity_PokemonCenter_1F_Text_XReceivedOneY:
#if GERMAN
	.string "{STR_VAR_1} erhält {STR_VAR_2}!$"
#else
	.string "{STR_VAR_1} received\n"
	.string "one {STR_VAR_2}!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp:
#if GERMAN
	.string "Dein Beutel ist voll. Schaffe Platz und\n"
	.string "komm dann wieder.$"
#else
	.string "Oh? Your BAG is filled up!\n"
	.string "Come see me when you have room.$"
#endif

LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs:
#if GERMAN
	.string "Hmm… Das war falsch! Die richtige\n"
	.string "Antwort lautet “{STR_VAR_3}”!$"
#else
	.string "Hmm… Wrong!\n"
	.string "The correct answer is “{STR_VAR_3}”!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize:
#if GERMAN
	.string "Wie schade!\p"
	.string "Nun muss ich den Preis {STR_VAR_1} selbst\n"
	.string "behalten.$"
#else
	.string "Too bad!\p"
	.string "I get to keep the quiz prize\n"
	.string "{STR_VAR_1} now!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz:
#if GERMAN
	.string "Hey, was meinst du? Würdest du nicht\n"
	.string "gerne dein eigenes Quiz erfinden?$"
#else
	.string "Listen, listen!\n"
	.string "Would you like to make your own quiz?$"
#endif

LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime:
#if GERMAN
	.string "Oh, verstehe…\n"
	.string "Nun, vielleicht ein anderes Mal!$"
#else
	.string "Oh, I see…\n"
	.string "Well, maybe next time!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_PickYourPrize:
#if GERMAN
	.string "Als Erstes musst du den Preis wählen,\n"
	.string "den der Gewinner deines Quizzes\l"
	.string "bekommen soll.\p"
	.string "Wenn der Teilnehmer allerdings nicht\n"
	.string "gewinnt, dann behalte ich den Preis!$"
#else
	.string "Okay, the first thing you have to do\n"
	.string "is pick the prize for the person that\l"
	.string "answers your quiz correctly.\p"
	.string "But beware, if the person taking\n"
	.string "the quiz can't get it right, I get to\l"
	.string "keep the prize!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize:
#if GERMAN
	.string "Wählst du keinen Preis aus, kannst du\n"
	.string "auch kein Quiz erfinden.\p"
	.string "Willst du doch kein Quiz erfinden?$"
#else
	.string "If you don't choose a prize,\n"
	.string "your quiz can't be made.\p"
	.string "Are you going to quit making\n"
	.string "your quiz?$"
#endif

LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz:
#if GERMAN
	.string "Sehr schön!\n"
	.string "Das ist ein toller Preis!\p"
	.string "Nun musst du die Quizfragen und die\n"
	.string "Antworten aufschreiben.$"
#else
	.string "Oh, how nice!\n"
	.string "That's a wonderful prize!\p"
	.string "Next, you need to write your quiz\n"
	.string "question and its answer.$"
#endif

LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion:
#if GERMAN
	.string "Willst du doch keine Fragen\n"
	.string "aufschreiben?$"
#else
	.string "Are you going to quit writing\n"
	.string "your quiz question?$"
#endif

@ Unused
LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizAnswer:
#if GERMAN
	.string "Möchtest du die Wahl deiner\n"
	.string "Quizantwort abbrechen?$"
#else
	.string "Are you going to quit choosing\n"
	.string "your quiz answer?$"
#endif

LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger:
#if GERMAN
	.string "Vielen Dank!\n"
	.string "Das ist wirklich ein tolles Quiz!\p"
	.string "Ich suche jetzt sofort jemanden, der\n"
	.string "an deinem Quiz teilnehmen wird.$"
#else
	.string "Thank you!\n"
	.string "You've put together a nice quiz.\p"
	.string "I'll go look for someone who'll take\n"
	.string "your quiz challenge right away.$"
#endif

LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady:
#if GERMAN
	.string "Ich bin die Wettbewerbslady!\n"
	.string "Ich liiiebe Wettbewerbe!$"
#else
	.string "I'm the CONTEST LADY!\n"
	.string "I sure do love CONTESTS!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock:
#if GERMAN
	.string "Vielen Dank für den {POKEBLOCK}!$"
#else
	.string "Thanks for your {POKEBLOCK} before!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality:
#if GERMAN
	.string "Dies ist mein Freund {STR_VAR_1}!\n"
	.string "Es ist der Inbegriff für {STR_VAR_2}!\p"
	.string "Aber ich glaube, dass es auch\n"
	.string "für {STR_VAR_2} steht!$"
#else
	.string "This is my friend {STR_VAR_1}!\n"
	.string "It's the epitome of {STR_VAR_2}!\p"
	.string "But I think that it will display\n"
	.string "even more {STR_VAR_2}!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase:
#if GERMAN
	.string "Ich brauche deine Hilfe!\p"
	.string "Gibst du mir bitte einen {POKEBLOCK}?\n"
	.string "Nur einen einzigen, bitte?\p"
	.string "Oh…\n"
	.string "Du hast ja gar keine {POKEBLOCK}Box?!?\l"
	.string "Schade! Na, das nächste Mal vielleicht.$"
#else
	.string "So, I need your help!\p"
	.string "Please, may I have one {POKEBLOCK}?\n"
	.string "All I'm asking for is one!\p"
	.string "…Oh, but…\n"
	.string "Don't you have a {POKEBLOCK} CASE?\l"
	.string "That's no good. Next time, then!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock:
#if GERMAN
	.string "Ich brauche deine Hilfe!\p"
	.string "Gibst du mir bitte einen {POKEBLOCK}?\n"
	.string "Nur einen einzigen, bitte?$"
#else
	.string "So, I need your help!\p"
	.string "Please, may I have one {POKEBLOCK}?\n"
	.string "All I'm asking for is one!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock:
#if GERMAN
	.string "Oooh!\n"
	.string "Auch nicht einen winzig kleinen {POKEBLOCK}?$"
#else
	.string "Awww!\n"
	.string "I can't have one {POKEBLOCK}?!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate:
#if GERMAN
	.string "Hach, echt…\n"
	.string "Geizkragen!!!$"
#else
	.string "Sheesh!\n"
	.string "What a cheapskate!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock:
#if GERMAN
	.string "Juhuu!\n"
	.string "Vielen Dank!!!\p"
	.string "Ich werde meinem Pokémon sofort deinen\n"
	.string "{POKEBLOCK} geben!$"
#else
	.string "Yay!\n"
	.string "Thank you!\p"
	.string "I'll feed my POKéMON your {POKEBLOCK}\n"
	.string "right away.$"
#endif

LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks:
#if GERMAN
	.string "Häh… Da scheint sich ja gar nichts zu\n"
	.string "tun…\p"
	.string "Hmm…\p"
	.string "Na, trotzdem vielen Dank!$"
#else
	.string "…It doesn't seem to have changed\n"
	.string "in any way at all…\p"
	.string "Hmm…\p"
	.string "Oh, well!\n"
	.string "Thank you very much!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks:
#if GERMAN
	.string "Juhuuu!\n"
	.string "Es freut sich wirklich darüber!\p"
	.string "Oh! Die {STR_VAR_2} von {STR_VAR_1} hat\n"
	.string "sich auch verbessert!\p"
	.string "Vielen Dank!$"
#else
	.string "Oh, yay!\n"
	.string "It's really delighted!\p"
	.string "I think it really improved {STR_VAR_1}'s\n"
	.string "{STR_VAR_2} quality, too.\p"
	.string "Thank you so much!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests:
#if GERMAN
	.string "Hmm…\p"
	.string "Jetzt können wir an den Wettbewerben\n"
	.string "teilnehmen.\p"
	.string "Feure uns an, wenn du uns siehst!$"
#else
	.string "Hmm…\p"
	.string "I think we may be ready to enter\n"
	.string "some CONTESTS.\p"
	.string "If you see us in one somewhere,\n"
	.string "I hope you'll cheer for us.$"
#endif

LilycoveCity_PokemonCenter_1F_Text_Zigzagoon:
#if GERMAN
	.string "{STR_VAR_1}: Kyuuu!$"
#else
	.string "{STR_VAR_1}: Guguuh!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_Kecleon:
	.string "{STR_VAR_1}: Igigigiiih!$"

LilycoveCity_PokemonCenter_1F_Text_Poochyena:
	.string "{STR_VAR_1}: Baaarun…$"

LilycoveCity_PokemonCenter_1F_Text_Pikachu:
#if GERMAN
	.string "{STR_VAR_1}: Pikkaaa!$"
#else
	.string "{STR_VAR_1}: Pikka!$"
#endif

LilycoveCity_PokemonCenter_1F_Text_Skitty:
	.string "{STR_VAR_1}: Umyaaaan!$"
