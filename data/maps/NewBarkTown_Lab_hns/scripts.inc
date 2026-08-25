.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end

NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, NewBarkTown_Lab_EventScript_Elm_AfterEggCheck
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
NewBarkTown_Lab_EventScript_Elm_AfterEggCheck:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
#if GERMAN
	.string "{PLAYER}!\p"
	.string "Was machst du hier?\p"
	.string "Mein Assistent wartet noch auf dich\n"
	.string "in Viola City!$"
#else
	.string "{PLAYER}!\p"
	.string "What are you doing here?\p"
	.string "My aide is still waiting for you\n"
	.string "In VIOLET CITY!$"
#endif

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ELM
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	@callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	@callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, NewBarkTown_Lab_EventScript_GiveStarter_Chikorita
	call_if_eq VAR_STARTER_MON, 1, NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil
	call_if_eq VAR_STARTER_MON, 2, NewBarkTown_Lab_EventScript_GiveStarter_Totodile
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_GiveStarter_Chikorita::
	call_if_unset FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil::
	call_if_unset FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Totodile::
	call_if_unset FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_NotShiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

NewBarkTown_Lab_EventScript_GiveStarter_Shiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS
	return

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	setflag FLAG_ENABLE_CONDITION
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_START_NUZLOCKE
	setflag FLAG_EXP_SHARE_ENABLED
	removeitem ITEM_MYSTERY_EGG
	release
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end

NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ELM
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	checkspecies SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGETIC
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGEKISS
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
#if GERMAN
	.string "Wahrscheinlich besser nicht anfassen!$"
#else
	.string "Probably shouldn't touch!$"
#endif

NewBarkTown_Lab_Text_ElmIntro:
#if GERMAN
	.string "Lind: {PLAYER}! Da bist du!\p"
	.string "Ich brauche deine Hilfe.\n"
	.string "Ich forsche gerade an neuen Pokémon.\p"
	.string "Kannst du mir helfen, {PLAYER}?\p"
	.string "Schau…\p"
	.string "Ich schreibe eine Arbeit, die ich auf\n"
	.string "einer Konferenz vorstellen will.\p"
	.string "Doch es gibt einige Dinge, die ich noch\n"
	.string "nicht ganz verstehe.\p"
	.string "Also! Bitte zieh ein Pokémon auf,\n"
	.string "das ich kürzlich gefangen habe.$"
#else
	.string "ELM: {PLAYER}! There you are!\p"
	.string "I needed to ask you a favor.\p"
	.string "I'm conducting new POKéMON\n"
	.string "research right now. I was\l"
	.string "wondering if you could help\l"
	.string "me with it, {PLAYER}.\p"
	.string "You see…\p"
	.string "I'm writing a paper that I\n"
	.string "want to present at a conference.\p"
	.string "But there are some things I\n"
	.string "don't quite understand yet.\p"
	.string "So!\p"
	.string "I'd like you to raise a\n"
	.string "POKéMON that I recently caught.$"
#endif

NewBarkTown_Lab_Text_ElmAccepted:
#if GERMAN
	.string "Danke, {PLAYER}!\n"
	.string "Du bist eine große Hilfe!$"
#else
	.string "Thanks, {PLAYER}!\n"
	.string "You're a great help!$"
#endif

NewBarkTown_Lab_Text_ElmRefused:
#if GERMAN
	.string "Aber… Bitte, ich brauche deine Hilfe!$"
#else
	.string "But… Please, I need your\n"
	.string "help!$"
#endif

NewBarkTown_Lab_Text_ElmResearchAmbitions:
#if GERMAN
	.string "Wenn ich meine Ergebnisse habe, werden\n"
	.string "wir mehr über die Rätsel der Pokémon\l"
	.string "erfahren.\p"
	.string "Du kannst dich darauf verlassen!$"
#else
	.string "When I announce my findings,\n"
	.string "I'm sure we'll delve deeper\p"
	.string "into the many mysteries of\n"
	.string "POKéMON.\p"
	.string "You can count on it!$"
#endif

NewBarkTown_Lab_Text_ElmGotAnEmail:
#if GERMAN
	.string "Oh, holla! Ich habe eine E-Mail\n"
	.string "bekommen!\p"
	.string "… … … … … … … …\n"
	.string "Hm… Aha…\p"
	.string "Okay…$"
#else
	.string "Oh, hey! I got an e-mail!\p"
	.string "… … … … … … … …\n"
	.string "Hm… Uh-huh…\p"
	.string "Okay…$"
#endif

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
#if GERMAN
	.string "Lind: Hör mir zu! Ich habe da einen\n"
	.string "Bekannten namens Mr. Pokémon.\p"
	.string "Er ist immer gleich völlig aus dem\n"
	.string "Häuschen, wenn er meint, einen\l"
	.string "besonders seltenen Fund gemacht zu\l"
	.string "haben.\p"
	.string "Gerade eben hat er mir wieder eine\n"
	.string "seiner E-Mails geschickt, in der er mir\l"
	.string "versichert, dieses eine Mal wirklich\l"
	.string "etwas Besonderes gefunden zu haben.\p"
	.string "Höchstwahrscheinlich handelt es sich\n"
	.string "dabei mal wieder um ein Pokémon-Ei.\l"
	.string "Aber meine Assistenten und ich haben\l"
	.string "leider gerade alle Hände voll zu tun…\p"
	.string "Hm, was mache ich jetzt nur…\p"
	.string "Ich hab’s!\p"
	.string "Du könntest der Sache doch für mich\n"
	.string "nachgehen, oder? Was sagst du?\p"
	.string "Los, du darfst dir dafür auch eins\n"
	.string "dieser Pokémon hier aussuchen!$"
#else
	.string "Hey, listen.\p"
	.string "I have an acquaintance called\n"
	.string "MR. POKéMON.\p"
	.string "He keeps finding weird things and\n"
	.string "raving about his discoveries.\p"
	.string "Anyway, I just got an e-mail\n"
	.string "from him saying that this\l"
	.string "time it's real.\p"
	.string "It is intriguing, but we're\n"
	.string "busy with our POKéMON research...\p"
	.string "Wait!\n"
	.string "I know!\p"
	.string "{PLAYER}, can you go in our\n"
	.string "place?$"
#endif

NewBarkTown_Lab_Text_ElmChooseAPokemon:
#if GERMAN
	.string "Nimm eines der Pokémon aus diesen\n"
	.string "Pokébällen.\p"
	.string "Du wirst der erste Partner dieses\n"
	.string "Pokémon sein, {PLAYER}!\p"
	.string "Wähle jetzt!$"
#else
	.string "I want you to raise one of\n"
	.string "the POKéMON contained in these BALLS.\p"
	.string "You'll be that POKéMON's\n"
	.string "first partner, {PLAYER}!\p"
	.string "Go on. Pick one!$"
#endif

NewBarkTown_Lab_Text_ElmWhereGoing:
#if GERMAN
	.string "Lind: Halt! Wohin willst du?$"
#else
	.string "ELM: Wait! Where are you\n"
	.string "going?$"
#endif

NewBarkTown_Lab_Text_ChooseCyndaquil:
#if GERMAN
	.string "Lind: Du nimmst Feurigel, das\n"
	.string "Feuer-Pokémon?$"
#else
	.string "ELM: You'll take {STR_VAR_1},\n"
	.string "the {STR_VAR_2} POKéMON?$"
#endif

NewBarkTown_Lab_Text_ChooseTotodile:
#if GERMAN
	.string "Lind: Willst du Karnimani, das\n"
	.string "Wasser-Pokémon?$"
#else
	.string "ELM: Do you want {STR_VAR_1},\n"
	.string "the {STR_VAR_2} POKéMON?$"
#endif

NewBarkTown_Lab_Text_ChooseChikorita:
#if GERMAN
	.string "Lind: Also, Endivie gefällt dir,\n"
	.string "das Pflanzen-Pokémon?$"
#else
	.string "ELM: So, you like {STR_VAR_1},\n"
	.string "the {STR_VAR_2} POKéMON?$"
#endif

NewBarkTown_Lab_Text_DidntChooseStarter:
#if GERMAN
	.string "Lind: Denk gut nach.\p"
	.string "Dein Partner ist wichtig.$"
#else
	.string "ELM: Think it over carefully.\p"
	.string "Your partner is important.$"
#endif

NewBarkTown_Lab_Text_ChoseStarter:
#if GERMAN
	.string "Lind: Das ist auch ein tolles Pokémon!$"
#else
	.string "ELM: I think that's a great\n"
	.string "POKéMON too!$"
#endif

NewBarkTown_Lab_Text_ReceivedStarter:
#if GERMAN
	.string "{PLAYER} erhielt {STR_VAR_1}!$"
#else
	.string "{PLAYER} received {STR_VAR_1}!$"
#endif

NewBarkTown_Lab_Text_Nickname:
#if GERMAN
	.string "Willst du deinem {STR_VAR_1} einen\n"
	.string "Spitznamen geben?$"
#else
	.string "Would you like to give your\n"
	.string "{STR_VAR_1} a nickname?$"
#endif

NewBarkTown_Lab_Text_ElmDirections1:
#if GERMAN
	.string "Mr. Pokémon wohnt etwas hinter Rosalia\n"
	.string "City, der nächsten Stadt.\p"
	.string "Du kannst es kaum verfehlen.\n"
	.string "Aber sicher ist sicher.\p"
	.string "Du hast meine Nummer.\n"
	.string "Ruf an, wenn etwas ist!$"
#else
	.string "MR. POKéMON lives a little bit\n"
	.string "beyond CHERRYGROVE, the next\l"
	.string "city over.\p"
	.string "It's almost a direct route\n"
	.string "there, so you can't miss it.\p"
	.string "But just in case, you have my\n"
	.string "phone number. Call me if\l"
	.string "anything comes up!$"
#endif


NewBarkTown_Lab_Text_ElmLetYourMonBattle:
#if GERMAN
	.string "Wenn ein wildes Pokémon erscheint, lass\n"
	.string "deines kämpfen!$"
#else
	.string "If a wild POKéMON appears,\n"
	.string "let your POKéMON battle it!$"
#endif

NewBarkTown_Lab_Text_ElmDirections2:
#if GERMAN
	.string "Wenn ein wildes Pokémon erscheint, lass\n"
	.string "deines kämpfen!\p"
	.string "Wenn es verletzt ist, heile es an der\n"
	.string "Maschine links oder im Pokécenter.\p"
	.string "Ich zähle auf dich!$"
#else
	.string "If a wild POKéMON appears, let\n"
	.string "your POKéMON battle it!\p"
	.string "If your POKéMON is hurt, you\n"
	.string "should heal it with the machine\l"
	.string "to my right, or at the POKéCENTER.\p"
	.string "I'm counting on you!$"
#endif

NewBarkTown_Lab_Text_GotElmsNumber:
#if GERMAN
	.string "{PLAYER} bekam Linds Telefonnummer.$"
#else
	.string "{PLAYER} got ELM's phone\n"
	.string "number.$"
#endif

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
#if GERMAN
	.string "Mr. Pokémon sammelt seltene\n"
	.string "Antiquitäten.\p"
	.string "Schade, dass sie nur selten und nicht\n"
	.string "besonders nützlich sind.$"
#else
	.string "MR. POKéMON goes everywhere and\n"
	.string "finds rarities.\p"
	.string "Too bad they're just rare and\n"
	.string "not very useful…$"
#endif

NewBarkTown_Lab_Text_ElmPokeBall:
#if GERMAN
	.string "Enthält ein Pokémon, das Prof. Lind\n"
	.string "gefangen hat.$"
#else
	.string "It contains a POKéMON caught\n"
	.string "by PROF.ELM.$"
#endif

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
#if GERMAN
	.string "Lind: Oh, {PLAYER}… hier war ganz\n"
	.string "schön was los, sage ich dir!\p"
	.string "Aber warum erzählst du mir nicht, was es\n"
	.string "mit Mr. Pokémons großem Fund auf sich\l"
	.string "hatte?$"
#else
	.string "ELM: {PLAYER}, this is terrible…\p"
	.string "Oh, yes, what was MR. POKéMON's\n"
	.string "big discovery?$"
#endif

NewBarkTown_Lab_Text_ElmAfterTheft2:
#if GERMAN
	.string "{PLAYER} übergab das Rätsel-Ei\n"
	.string "an Prof. Lind.$"
#else
	.string "{PLAYER} handed the MYSTERY EGG\n"
	.string "to PROF.ELM.$"
#endif

NewBarkTown_Lab_Text_ElmAfterTheft3:
#if GERMAN
	.string "Lind: Hmm… das?$"
#else
	.string "ELM: This?$"
#endif

NewBarkTown_Lab_Text_ElmAfterTheft4:
#if GERMAN
	.string "Aber… Ist es ein Pokémon-Ei?\p"
	.string "Wenn ja, ist es eine große Entdeckung!\p"
	.string "Lind: Was?!?\p"
	.string "Prof. Eich gab dir einen Pokédex?\p"
	.string "{PLAYER}, stimmt das?\n"
	.string "Unglaublich!\p"
	.string "Er erkennt das Potential von\n"
	.string "Menschen als Trainer.\p"
	.string "Wow, {PLAYER}. Du könntest Champion\n"
	.string "werden.\p"
	.string "Du kommst gut mit Pokémon klar.\p"
	.string "Versuche die Arenaleiter\n"
	.string "herauszufordern.\p"
	.string "Die nächste Arena ist in Viola City.\p"
	.string "…{PLAYER}. Der Weg zum Sieg wird lang\n"
	.string "sein.\p"
	.string "Bevor du gehst, sprich besser mit\n"
	.string "deiner Mutter.$"
#else
	.string "But… Is it a POKéMON EGG?\p"
	.string "If it is, it is a great\n"
	.string "discovery!\p"
	.string "ELM: What?!?\p"
	.string "PROF.OAK gave you a POKéDEX?\p"
	.string "{PLAYER}, is that true?\n"
	.string "Th-that's incredible!\p"
	.string "He is superb at seeing the\n"
	.string "potential of people as trainers.\p"
	.string "Wow, {PLAYER}. You may have what\n"
	.string "it takes to become the CHAMPION.\p"
	.string "You seem to be getting on\n"
	.string "great with POKéMON too.\p"
	.string "You should take the POKéMON\n"
	.string "GYM challenge.\p"
	.string "The closest GYM would be the\n"
	.string "one in VIOLET CITY.\p"
	.string "…{PLAYER}. The road to the\n"
	.string "championship will be a long one.\p"
	.string "Before you leave, make sure\n"
	.string "that you talk to your mom.$"
#endif

NewBarkTown_Lab_Text_ElmStudyingEgg:
#if GERMAN
	.string "Lind: Gib nicht auf! Ich melde mich bei\n"
	.string "dir, sobald ich etwas über dieses Ei\l"
	.string "herausgefunden habe!$"
#else
	.string "ELM: Don't give up!\n"
	.string "I'll call if I learn anything\l"
	.string "about that EGG!$"
#endif

NewBarkTown_Lab_Text_ElmAideHasEgg:
#if GERMAN
	.string "Lind: {PLAYER}? Hast du meinen\n"
	.string "Assistenten getroffen?\p"
	.string "Er hätte dich mit dem Ei im\n"
	.string "Pokémon-Center von Viola City treffen\l"
	.string "sollen.\p"
	.string "Du hast ihn wohl knapp verpasst.\p"
	.string "Versuch es dort noch einmal.$"
#else
	.string "ELM: {PLAYER}? Didn't you meet\n"
	.string "my assistant?\p"
	.string "He should have met you with\n"
	.string "the EGG at VIOLET CITY's\p"
	.string "POKéMON CENTER.\p"
	.string "You must have just missed him.\n"
	.string "Try to catch him there.$"
#endif

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
#if GERMAN
	.string "Lind: Hey, hat sich am Ei etwas getan?$"
#else
	.string "ELM: Hey, has that EGG changed\n"
	.string "any?$"
#endif

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
#if GERMAN
	.string "Lind: Nanu? Ich dachte, es wäre etwas\n"
	.string "aus dem Ei geschlüpft, {PLAYER}!\l"
	.string "Wo ist das Pokémon?$"
#else
	.string "{PLAYER}? I thought the EGG\n"
	.string "hatched.\p"
	.string "Where is the POKéMON?$"
#endif

NewBarkTown_Lab_Text_ShowTogepi1:
#if GERMAN
	.string "Lind: {PLAYER}, das sieht toll aus!$"
#else
	.string "ELM: {PLAYER}, you look great!$"
#endif

NewBarkTown_Lab_Text_ShowTogepi2:
#if GERMAN
	.string "Was? Dieses Pokémon!?!$"
#else
	.string "What? That POKéMON!?!$"
#endif

NewBarkTown_Lab_Text_ShowTogepi3:
#if GERMAN
	.string "Das Ei ist geschlüpft!\n"
	.string "Pokémon werden aus Eiern geboren…\p"
	.string "Nein, vielleicht nicht alle.\p"
	.string "Es gibt noch viel zu erforschen.$"
#else
	.string "The EGG hatched! So, POKéMON\n"
	.string "are born from EGGS…\p"
	.string "No, perhaps not all POKéMON\n"
	.string "are.\p"
	.string "Wow, there's still a lot of\n"
	.string "research to be done.$"
#endif

NewBarkTown_Lab_Text_ElmGiveEverstone1:
#if GERMAN
	.string "Danke, {PLAYER}! Du hilfst uns die\n"
	.string "Geheimnisse der Pokémon zu lüften!\p"
	.string "Nimm dies als Dankeschön.$"
#else
	.string "Thanks, {PLAYER}! You're helping\n"
	.string "unravel POKéMON mysteries for us!\p"
	.string "I want you to have this as a\n"
	.string "token of our appreciation.$"
#endif

NewBarkTown_Lab_Text_ElmGiveEverstone2:
#if GERMAN
	.string "Das ist ein Ewigstein.\p"
	.string "Manche Pokémon entwickeln sich\n"
	.string "bei bestimmten Leveln.\p"
	.string "Ein Pokémon mit Ewigstein entwickelt\n"
	.string "sich nicht.\p"
	.string "Gib ihn einem Pokémon, das du nicht\n"
	.string "entwickeln willst.$"
#else
	.string "That's an EVERSTONE.\p"
	.string "Some species of POKéMON evolve\n"
	.string "when they grow to certain levels.\p"
	.string "A POKéMON holding the EVERSTONE\n"
	.string "won't evolve.\p"
	.string "Give it to a POKéMON you don't\n"
	.string "want to evolve.$"
#endif

NewBarkTown_Lab_Text_ElmCallYou:
#if GERMAN
	.string "Lind: {PLAYER}, ich rufe an, wenn etwas\n"
	.string "passiert.$"
#else
	.string "ELM: {PLAYER}, I'll call you if\n"
	.string "anything comes up.$"
#endif

NewBarkTown_Lab_Text_AideAfterTheft:
#if GERMAN
	.string "…Seufz… ich frage mich, wie es dem\n"
	.string "gestohlenen Pokémon jetzt wohl geht…\p"
	.string "Man sagt, aus einem Pokémon, das von\n"
	.string "einem bösen Menschen trainiert wird,\l"
	.string "wird auch mal ein böses Pokémon…$"
#else
	.string "…sigh… That stolen POKéMON.\p"
	.string "I wonder how it's doing.\p"
	.string "They say a POKéMON raised by a\n"
	.string "bad person turns bad itself.$"
#endif

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
#if GERMAN
	.string "Lind: Oh, hallo {PLAYER}!\n"
	.string "Mann, bei dir weiß man wirklich nie, mit\l"
	.string "was du einen als Nächstes überraschst!\p"
	.string "Dank dir macht meine Forschung\n"
	.string "ganz ausgezeichnete Fortschritte!\p"
	.string "Hier, bitte nimm das als Zeichen meiner\n"
	.string "Dankbarkeit!$"
#else
	.string "ELM: Hi, {PLAYER}!\p"
	.string "Thanks to you, my research is\n"
	.string "going great!\p"
	.string "Take this as a token of my\n"
	.string "appreciation.$"
#endif

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
#if GERMAN
	.string "Das ist ein Meisterball!\p"
	.string "Egal, mit welchem Pokémon du es auch zu\n"
	.string "tun hast, mit diesem wertvollen Pokéball\l"
	.string "gelingt es dir garantiert, es zu fangen!\p"
	.string "Meisterbälle werden angeblich exklusiv\n"
	.string "für herausragende Leistungen im Feld\l"
	.string "der Pokémon-Forschung ausgegeben…\p"
	.string "Aber ich glaube, du kannst damit mehr\n"
	.string "anfangen als ich, {PLAYER}.\l"
	.string "Hier, du kannst ihn haben!$"
#else
	.string "The MASTER BALL is the best!\p"
	.string "It's the ultimate BALL! It'll\n"
	.string "catch any POKéMON without fail.\p"
	.string "It's given only to recognized\n"
	.string "POKéMON researchers.\p"
	.string "I think you can make much better\n"
	.string "use of it than I can, {PLAYER}!$"
#endif

NewBarkTown_Lab_Text_KimonoGirls:
#if GERMAN
	.string "Die Kimono-Girls sagten, sie würden im\n"
	.string "Tanztheater von Teak City auf dich\l"
	.string "warten!\p"
	.string "Ich weiß, dass du jede Menge\n"
	.string "durchgemacht hast, seit ich dir dieses\l"
	.string "Ei anvertraut habe, aber ich hoffe\l"
	.string "schwer, dass du nach all diesen Mühen\l"
	.string "auch bis zum Schluss durchhältst!$"
#else
	.string "By the way...\n"
	.string "A group of beautiful KIMONO\l"
	.string "GIRLS were looking for you.\p"
	.string "They told me they are\n"
#endif

NewBarkTown_Lab_Text_KimonoWaiting:
#if GERMAN
	.string "Prof. Lind: Die Kimono-Girls warten im\n"
	.string "Teak-City Tanztheater.$"
#else
	.string "PROF.ELM: The KIMONO\n"
	.string "GIRLS are waiting for you at\l"
	.string "the ECRUTEAK DANCE THEATER.$"
#endif

NewBarkTown_Lab_Text_League:
#if GERMAN
	.string "Lind: Haha, gute Arbeit!\p"
	.string "Zuerst dachte ich, dieses Ei sei einfach\n"
	.string "nur selten und nichts weiter, aber die\l"
	.string "Sache hat inzwischen völlig andere\l"
	.string "Dimensionen angenommen, was?\p"
	.string "Was haben dir die Kimono-Girls erzählt?\p"
	.string "Ach, aber das geht mich nichts an.\p"
	.string "Das war ganz allein dein Verdienst.\n"
	.string "Du hast dich mit Herz und Seele durch\l"
	.string "alles durchgekämpft.\p"
	.string "Jemand, der aus eigener Kraft so viel\n"
	.string "erreicht hat, schafft es sicher auch an\l"
	.string "die Spitze der Pokémon Liga!\p"
	.string "Mach dich nun also auf den Weg\n"
	.string "zum Indigo-Plateau!\p"
	.string "Weißt du, wo das ist?\p"
	.string "Nimm von hier aus Route 27, bis du auf\n"
	.string "Route 26 gelangst. Du musst immer\l"
	.string "geradeaus in Richtung Norden!$"
#else
	.string "PROF.ELM: Hahaha...\n"
	.string "Good job!\p"
	.string "That rare EGG has brought you\n"
	.string "a lot of trouble, huh?\p"
	.string "The KIMONO GIRLS said something\n"
	.string "about me?\p"
	.string "I have nothing to do with it.\p"
	.string "You made your decision and went\n"
	.string "through with it.\p"
	.string "Having done so much, you should\n"
	.string "be able to face the LEAGUE now!\p"
	.string "You should head for INDIGO\n"
	.string "PLATEAU!\p"
	.string "Do you know how to get there?\n"
	.string "Follow ROUTE 27 to ROUTE 26.\p"
	.string "Once there, go straight north!$"
#endif


NewBarkTown_Lab_Text_ElmGiveTicket1:
#if GERMAN
	.string "Lind: Oh, hallo {PLAYER}!\n"
	.string "Ich habe dich schon erwartet!\p"
	.string "Ich habe dich heute zu mir gerufen, weil\n"
	.string "ich dir etwas geben möchte.\p"
	.string "Hier! Das ist ein Bootsticket.\p"
	.string "Damit kannst du auch in Kanto auf\n"
	.string "Pokémon-Jagd gehen!$"
#else
	.string "ELM: {PLAYER}! There you are!\p"
	.string "I called because I have\n"
	.string "something for you.\p"
	.string "See? It's an S.S.TICKET.\p"
	.string "Now you can catch POKéMON in\n"
	.string "KANTO.$"
#endif

NewBarkTown_Lab_Text_ElmGiveTicket2:
#if GERMAN
	.string "Lind: Das Schnellboot, für das dieses\n"
	.string "Ticket gültig ist, legt im Hafen von\l"
	.string "Oliviana City ab.\p"
	.string "Aber das weißt du ja wahrscheinlich\n"
	.string "besser als ich, {PLAYER}…\p"
	.string "Du und dein Pokémon-Team, ihr seid\n"
	.string "schließlich schon viel zusammen gereist.\p"
	.string "Also dann! Wenn du nach Kanto gehst,\n"
	.string "grüße bitte Professor Eich von mir!$"
#else
	.string "The ship departs from OLIVINE\n"
	.string "CITY.\p"
	.string "But you knew that already,\n"
	.string "{PLAYER}.\p"
	.string "After all, you've traveled all\n"
	.string "over with your POKéMON.\p"
	.string "Give my regards to PROF.OAK in\n"
	.string "KANTO!$"
#endif

NewBarkTown_Lab_Text_LabMonEgg:
#if GERMAN
	.string "Es ist das Pokémon-Ei, das von Prof.\n"
	.string "Lind erforscht wird.$"
#else
	.string "It's the POKéMON EGG being\n"
	.string "studied by PROF.ELM.$"
#endif

NewBarkTown_Lab_Text_AideGivePotion:
#if GERMAN
	.string "{PLAYER}, nimm das für deine\n"
	.string "Anstrengung.$"
#else
	.string "{PLAYER}, I want you to have\n"
	.string "this for your errand.$"
#endif

NewBarkTown_Lab_Text_AideAlwaysBusy:
#if GERMAN
	.string "Wir sind nur zu dritt, also haben wir\n"
	.string "immer viel zu tun.$"
#else
	.string "There are only three of us, so\n"
	.string "we're always busy.$"
#endif

NewBarkTown_Lab_Text_AideSave:
#if GERMAN
	.string "Vergiss nicht, regelmäßig zu speichern!\p"
	.string "Drücke Start und dann Sichern!$"
#else
	.string "Don't forget to save your game\n"
	.string "regularly!\p"
	.string "Press the START button, then\n"
	.string "SAVE the game!$"
#endif

NewBarkTown_Lab_Text_AideTheftTestimony:
#if GERMAN
	.string "Wir haben ein schrecklich lautes\n"
	.string "Geräusch von draußen gehört, doch\l"
	.string "während wir mit dem Professor nach dem\l"
	.string "Rechten gesehen haben, hat\l"
	.string "irgendjemand ein Pokémon gestohlen…\p"
	.string "…Seufz… ich frage mich, wie es dem\n"
	.string "gestohlenen Pokémon jetzt wohl geht…\p"
	.string "Man sagt, aus einem Pokémon, das von\n"
	.string "einem bösen Menschen trainiert wird,\l"
	.string "wird auch mal ein böses Pokémon…$"
#else
	.string "There was a loud noise\n"
	.string "outside…\p"
	.string "When we went to look,\n"
	.string "someone stole a POKéMON.\p"
	.string "It's unbelievable that anyone\n"
	.string "would do that!\p"
	.string "…sigh… That stolen POKéMON.\p"
	.string "I wonder how it's doing.\p"
	.string "They say a POKéMON raised by a\n"
	.string "bad person turns bad itself.$"
#endif

NewBarkTown_Lab_Text_AideGiveBalls:
#if GERMAN
	.string "{PLAYER}!\p"
	.string "Benutze diese für deine\n"
	.string "Pokédex-Mission!$"
#else
	.string "{PLAYER}!\p"
	.string "Use these on your POKéDEX\n"
	.string "quest!$"
#endif

NewBarkTown_Lab_Text_AideExplainBalls:
#if GERMAN
	.string "Um deinen Pokédex zu füllen, musst du\n"
	.string "Pokémon fangen.\p"
	.string "Wirf Pokébälle auf wilde Pokémon!$"
#else
	.string "To add to your POKéDEX, you\n"
	.string "have to catch POKéMON.\p"
	.string "Throw POKé BALLS at wild\n"
	.string "POKéMON to get them.$"
#endif

NewBarkTown_Lab_Text_Officer1:
#if GERMAN
	.string "Ich hörte, hier wurde ein Pokémon\n"
	.string "gestohlen…\p"
	.string "Ich wollte Infos von Prof. Lind.\p"
	.string "Offenbar war es ein junger Mann mit\n"
	.string "langen, roten Haaren…\p"
	.string "Was?\p"
	.string "Du hast gegen so einen Trainer\n"
	.string "gekämpft?\p"
	.string "Weißt du seinen Namen?$"
#else
	.string "I heard a POKéMON was stolen\n"
	.string "here…\p"
	.string "I was just getting some\n"
	.string "information from PROF.ELM.\p"
	.string "Apparently, it was a young\n"
	.string "male with long, red hair…\p"
	.string "What?\p"
	.string "You battled a trainer like\n"
	.string "that?\p"
	.string "Did you happen to get his\n"
	.string "name?$"
#endif

NewBarkTown_Lab_Text_Officer2_1:
#if GERMAN
	.string "OK! Also {RIVAL} hieß er?$"
#else
	.string "OK! So {RIVAL} was his name?$"
#endif

NewBarkTown_Lab_Text_Officer2:
#if GERMAN
	.string "Danke, dass du bei meinen Ermittlungen\n"
	.string "geholfen hast!$"
#else
	.string "Thanks for helping my\n"
	.string "investigation!$"
#endif

NewBarkTown_Lab_Text_OfficerNo:
#if GERMAN
	.string "Du kennst seinen Namen doch?!$"
#else
	.string "Surely you got his name?!$"
#endif

NewBarkTown_Lab_Text_Elm_CallMe:
#if GERMAN
	.string "Ah, {PLAYER}!\p"
	.string "Wie läuft’s mit dem Pokédex?\p"
	.string "Ich bin gerade beschäftigt, aber ruf\n"
	.string "mich mal an, dann kann ich deinen\l"
	.string "Fortschritt prüfen!$"
#else
	.string "Ah, {PLAYER}!\p"
	.string "How's your POKéDEX coming along?\n"
	.string "I'm busy now, but call me sometime\l"
	.string "and I can check your progress!$"
#endif
