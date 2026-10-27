LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	.byte 0

	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
	@ 1: Beat Elite Four, Dex upgrade ready
	@ 2: Received National Dex
	@ 3: Left lab after receiving National Dex
	@ 4: Entered lab after catching all Hoenn mons
	@ 5: Birch told player to choose Johto starter
	@ 6: Chose Johto starter

	@ State descriptions for VAR_BIRCH_LAB_STATE
	@ 1: Never occurs
	@ 2: Chose starter
	@ 3: Received starter in lab
	@ 4: Defeated rival on Route 103
	@ 5: Received pokedex

LittlerootTown_ProfessorBirchsLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout

LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_OnWarp:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
	turnobject LOCALID_PLAYER, DIR_NORTH
	addobject LOCALID_BIRCHS_LAB_BIRCH
	addobject LOCALID_BIRCHS_LAB_RIVAL
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_NORTH
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
	turnobject LOCALID_BIRCHS_LAB_AIDE, DIR_EAST
	setobjectxy LOCALID_BIRCHS_LAB_AIDE, 10, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject::
	addobject LOCALID_BIRCHS_LAB_RIVAL
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
	addobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	addobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	addobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	addobject LOCALID_BIRCHS_LAB_RIVAL
	turnobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, 8, 4
	turnobject LOCALID_BIRCHS_LAB_TOTODILE_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_TOTODILE_BALL, 9, 4
	turnobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_CHIKORITA_BALL, 10, 4
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_EAST
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
	end

LittlerootTown_ProfessorBirchsLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
	map_script_2 VAR_HOENN_ARRIVAL_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_HoennWelcome
	.2byte 0

@ The starter is technically given prior to this on Route 101 by special ChooseStarter
@ This is just where the game tells you its yours and lets you nickname it
LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
	lockall
	bufferleadmonspeciesname STR_VAR_1
	message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_BIRCH_LAB_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
	lockall
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
	lockall
	delay 30
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
	waitmovement 0
	delay 20
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
	playse SE_PC_ON
	waitse
	delay 20
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
	waitmovement 0
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
	lockall
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Totodile::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TOTODILE, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
	call_if_unset FLAG_SHINY_STARTER_2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveJohtoStarterNotShiny
	call_if_set FLAG_SHINY_STARTER_2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveJohtoStarterShiny
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile::
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
	call_if_unset FLAG_SHINY_STARTER_3, LittlerootTown_ProfessorBirchsLab_EventScript_GiveJohtoStarterNotShiny
	call_if_set FLAG_SHINY_STARTER_3, LittlerootTown_ProfessorBirchsLab_EventScript_GiveJohtoStarterShiny
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita::
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
	call_if_unset FLAG_SHINY_STARTER_1, LittlerootTown_ProfessorBirchsLab_EventScript_GiveJohtoStarterNotShiny
	call_if_set FLAG_SHINY_STARTER_1, LittlerootTown_ProfessorBirchsLab_EventScript_GiveJohtoStarterShiny
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

@ Gives the Johto starter in VAR_TEMP_TRANSFERRED_SPECIES with the shininess of its preview
@ (FLAG_SHINY_STARTER_1-3 = Chikorita, Cyndaquil, Totodile, rolled by showmonpic).
@ See docs/origin_jade/DECISIONS.md, D-035.
LittlerootTown_ProfessorBirchsLab_EventScript_GiveJohtoStarterNotShiny::
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

LittlerootTown_ProfessorBirchsLab_EventScript_GiveJohtoStarterShiny::
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
	lock
	faceplayer
	@ Hand over the badge case if the player does not have it yet.
	call LittlerootTown_ProfessorBirchsLab_EventScript_TryHandBinder
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TryHandBinder::
	goto_if_set FLAG_RECEIVED_PASS_BINDER, LittlerootTown_ProfessorBirchsLab_EventScript_BinderHandled
	goto_if_le VAR_HOENN_ARRIVAL_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_BinderHandled
	call Common_EventScript_HoennGiveBadgeBinder
LittlerootTown_ProfessorBirchsLab_EventScript_BinderHandled::
	return

LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
	release
	end

EventScript_RegisterProfBirch::
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCHS_LAB_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
	lock
	faceplayer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PC::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Book::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
	waitmessage
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
#if GERMAN
	.string "Wie? Prof. Birk?\p"
	.string "Der Prof arbeitet an einer Feld-Studie.\n"
	.string "Also ist er nicht hier.\p"
	.string "Oh, ich erkläre dir, was eine Feld-Studie\n"
	.string "in diesem Falle ist:\p"
	.string "Man beobachtet und studiert Dinge in\n"
	.string "ihrem natürlichen Umfeld. In Feldern\l"
	.string "oder auf Bergen, anstatt im Labor.\p"
	.string "Der Prof ist kein Typ, der am\n"
	.string "Schreibtisch arbeiten kann. Er muss\l"
	.string "einfach draußen in der freien Natur die\l"
	.string "Dinge beobachten und studieren.$"
#else
	.string "Hunh? PROF. BIRCH?\p"
	.string "The PROF's away on fieldwork.\n"
	.string "Ergo, he isn't here.\p"
	.string "Oh, let me explain what fieldwork is.\p"
	.string "It is to study things in the natural\n"
	.string "environment, like fields and mountains,\l"
	.string "instead of a laboratory.\p"
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
#if GERMAN
	.string "Der Prof ist kein Typ, der am\n"
	.string "Schreibtisch arbeiten kann. Er muss\l"
	.string "einfach draußen in der freien Natur die\l"
	.string "Dinge beobachten und studieren.$"
#else
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
#if GERMAN
	.string "Prof. Birk studiert den Lebensraum\n"
	.string "und die Verbreitung von Pokémon.\p"
	.string "Der Prof freut sich über die Mitarbeit\n"
	.string "von {RIVAL}. Da spürt man Zuneigung!$"
#else
	.string "PROF. BIRCH is studying the habitats\n"
	.string "and distribution of POKéMON.\p"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
	.string "There's a lot of love there.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
#if GERMAN
	.string "Prof. Birk: Du bist also\n"
	.string "{PLAYER}{KUN}! \p"
	.string "Dein Vater hat mir schon viel von dir\n"
	.string "erzählt.\p"
	.string "Ich habe auch erfahren, dass du noch\n"
	.string "kein eigenes Pokémon besitzt.\p"
	.string "Aber wie du eben gekämpft hast…\n"
	.string "Diese Gelassenheit…\p"
	.string "In deinen Adern fließt wirklich das\n"
	.string "Blut deines Vaters!\p"
	.string "Als Dank dafür, dass du mich gerettet\n"
	.string "hast, möchte ich dir das Pokémon\l"
	.string "schenken, das du dabei benutzt hast.\p"
	.string "{PLAYER} erhält {STR_VAR_1}!$"
#else
	.string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
	.string "I've heard so much about you from\n"
	.string "your father.\p"
	.string "I've heard that you don't have your\n"
	.string "own POKéMON yet.\p"
	.string "But the way you battled earlier,\n"
	.string "you pulled it off with aplomb!\p"
	.string "I guess you have your father's blood\n"
	.string "in your veins after all!\p"
	.string "Oh, yes. As thanks for rescuing me,\n"
	.string "I'd like you to have the POKéMON you\l"
	.string "used earlier.\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
#if GERMAN
	.string "Prof. Birk: Willst du dem {STR_VAR_1} einen\n"
	.string "Kosenamen geben?$"
#else
	.string "PROF. BIRCH: While you're at it, why not\n"
	.string "give a nickname to that {STR_VAR_1}?$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
#if GERMAN
	.string "Prof. Birk: Wenn du dich mit Pokémon\n"
	.string "beschäftigst und Erfahrungen\p"
	.string "sammelst, wirst du mit Sicherheit ein\n"
	.string "sehr guter Trainer!\p"
	.string "Mein Kind, {RIVAL}, studiert ebenfalls\n"
	.string "Pokémon und hilft mir dabei sehr.\p"
	.string "{PLAYER}{KUN}, meinst du nicht, es\n"
	.string "wäre eine gute Idee, wenn du dich mit\l"
	.string "{RIVAL} triffst?$"
#else
	.string "PROF. BIRCH: If you work at POKéMON\n"
	.string "and gain experience, I think you'll make\l"
	.string "an extremely good TRAINER.\p"
	.string "My kid, {RIVAL}, is also studying\n"
	.string "POKéMON while helping me out.\p"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
	.string "a good idea to go see {RIVAL}?$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
#if GERMAN
	.string "Prof. Birk: Großartig!\n"
	.string "{RIVAL} wird sich auch sehr freuen.\p"
	.string "{RIVAL} soll dir beibringen, was es\n"
	.string "bedeutet, ein Trainer zu sein.$"
#else
	.string "PROF. BIRCH: Great!\n"
	.string "{RIVAL} should be happy, too.\p"
	.string "Get {RIVAL} to teach you what it\n"
	.string "means to be a TRAINER.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
#if GERMAN
	.string "Prof. Birk: Ach, sei doch nicht so!\n"
	.string "Du solltest dich wirklich mit meinem\l"
	.string "Sprössling treffen!$"
#else
	.string "PROF. BIRCH: Oh, don't be that way.\n"
	.string "You should go meet my kid.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
#if GERMAN
	.string "Prof. Birk: {RIVAL}? {RIVAL} ist,\n"
	.string "glaube ich, nach Hause gegangen.\p"
	.string "Oder das Kind krabbelt mal wieder\n"
	.string "irgendwo durch hohes Gras…\p"
	.string "Wenn du und deine Pokémon müde\n"
	.string "sind, dann ruht euch zu Hause aus.$"
#else
	.string "PROF. BIRCH: {RIVAL}?\n"
	.string "Gone home, I think.\p"
	.string "Or maybe that kid's scrabbling around\n"
	.string "in tall grass again somewhere…\p"
	.string "If you or your POKéMON get tired,\n"
	.string "you should get some rest at home.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
#if GERMAN
	.string "Prof. Birk: Oh, hallo, {PLAYER}{KUN}!\n"
	.string "\p"
	.string "Ich habe gehört, du hast {RIVAL} \n"
	.string "besiegt! Super! Das war dein erster\l"
	.string "Kampf gegen einen Trainer!\p"
	.string "{RIVAL} hilft mir schon sehr lange bei\n"
	.string "meinen Forschungen.\p"
	.string "{RIVAL} besitzt eine respektable\n"
	.string "Geschichte als Trainer.\p"
	.string "Hier, das hilft mir bei meinen\n"
	.string "Forschungen. Aber ich denke, du kannst\l"
	.string "den Pokédex auch gebrauchen.$"
#else
	.string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
	.string "I heard you beat {RIVAL} on\n"
	.string "your first try. That's excellent!\p"
	.string "{RIVAL}'s been helping with my research\n"
	.string "for a long time.\p"
	.string "{RIVAL} has an extensive history as\n"
	.string "a TRAINER already.\p"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
	.string "research, but I think you should have\l"
	.string "this POKéDEX.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
#if GERMAN
	.string "{PLAYER} erhält den Pokédex!$"
#else
	.string "{PLAYER} received the POKéDEX!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
#if GERMAN
	.string "Prof. Birk: Der Pokédex ist ein hoch\n"
	.string "entwickeltes, technisches Gerät, das\l"
	.string "automatisch jedes Pokémon, das du\l"
	.string "siehst oder fängst, registriert.\p"
	.string "{RIVAL} geht nie ohne ihn aus dem\n"
	.string "Haus. \p"
	.string "Immer, wenn mein Kind ein seltenes\n"
	.string "Pokémon fängt, kommt es und zeigt mir\l"
	.string "den Eintrag im Pokédex, während ich\l"
	.string "draußen forsche.$"
#else
	.string "PROF. BIRCH: The POKéDEX is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any POKéMON you meet or catch.\p"
	.string "My kid, {RIVAL}, goes everywhere\n"
	.string "with it.\p"
	.string "Whenever my kid catches a rare POKéMON\n"
	.string "and records its data in the POKéDEX,\l"
	.string "why, {RIVAL} looks for me while I'm out\l"
	.string "doing fieldwork, and shows me.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
#if GERMAN
	.string "Prof. Birk: Unzählige Pokémon erwarten\n"
	.string "dich bereits.\p"
	.string "Hach, ich muss jetzt auch dringend\n"
	.string "wieder meinen Forschungen nachgehen.$"
#else
	.string "PROF. BIRCH: Countless POKéMON\n"
	.string "await you!\p"
	.string "Argh, I'm getting the itch to get out\n"
	.string "and do fieldwork again!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
#if GERMAN
	.string "Maike: Oh, wow, {PLAYER}{KUN}!\n"
	.string "Jetzt hast du auch einen Pokédex!\p"
	.string "Das ist ja toll! Genau wie ich!\n"
	.string "Ich habe hier etwas für dich!$"
#else
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
	.string "You got a POKéDEX, too!\p"
	.string "That's great! Just like me!\n"
	.string "I've got something for you, too!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
#if GERMAN
	.string "Maike: Es macht unheimlich viel Spaß, all\n"
	.string "die verschiedenen Pokémon zu fangen!\p"
	.string "Ich schaue mich wirklich überall um,\n"
	.string "denn ich will die unterschiedlichsten\l"
	.string "Pokémon fangen.\p"
	.string "Sobald ich niedliche Pokémon entdecke,\n"
	.string "fange ich sie mit Pokébällen.$"
#else
	.string "MAY: It's fun if you can get a lot of\n"
	.string "POKéMON!\p"
	.string "I'm going to look all over the place\n"
	.string "because I want different POKéMON.\p"
	.string "If I find any cute POKéMON, I'll catch\n"
	.string "them with POKé BALLS!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
#if GERMAN
	.string "Oh! Dein Beutel ist voll.$"
#else
	.string "Oh? Your BAG's full.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
#if GERMAN
	.string "Maike: Ich frage mich, wo ich jetzt\n"
	.string "nach weiteren Pokémon suchen soll.$"
#else
	.string "MAY: I wonder where I should go look\n"
	.string "for POKéMON next?$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
#if GERMAN
	.string "Maike: Ach…\n"
	.string "Du hast auch einen Pokédex.\p"
	.string "Na, dann.\n"
	.string "Ich gebe dir dies.$"
#else
	.string "BRENDAN: Huh…\n"
	.string "So you got a POKéDEX, too.\p"
	.string "Well then, here.\n"
	.string "I'll give you these.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
#if GERMAN
	.string "Maike: Weißt du, je mehr Pokémon du\n"
	.string "besitzt, desto mehr Spaß macht es.\p"
	.string "Ich reise viel umher, um die unter-\n"
	.string "schiedlichsten Pokémon zu finden.\p"
	.string "Und wenn ich ein cooles Pokémon sehe,\n"
	.string "versuche ich natürlich, es zu fangen.$"
#else
	.string "BRENDAN: You know it's more fun to\n"
	.string "have a whole bunch of POKéMON.\p"
	.string "I'm going to explore all over the place\n"
	.string "to find different POKéMON.\p"
	.string "If I find any cool POKéMON, you bet\n"
	.string "I'll try to get them with POKé BALLS.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
#if GERMAN
	.string "Hey, dein Beutel ist voll.$"
#else
	.string "Hey, your BAG's full.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
#if GERMAN
	.string "Maike: Und wo soll ich jetzt mal nach\n"
	.string "Pokémon suchen?$"
#else
	.string "BRENDAN: Where should I look for\n"
	.string "POKéMON next…$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
#if GERMAN
	.string "Das ist eine kompliziert aussehende\n"
	.string "Maschine. Der Prof wird sie für seine\l"
	.string "Forschungen brauchen…$"
#else
	.string "It's a serious-looking machine.\n"
	.string "The PROF must use this for research.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
#if GERMAN
	.string "Ein PC, der in der Forschung eingesetzt\n"
	.string "wird. Besser nicht damit spielen!$"
#else
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
#if GERMAN
	.string "Es ist voll mit Büchern über Pokémon.$"
#else
	.string "It's crammed with books on POKéMON.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
#if GERMAN
	.string "Dieses Buch ist viel zu kompliziert…$"
#else
	.string "It's a book that's too hard to read.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
#if GERMAN
	.string "Prof. Birk: Nun…\p"
	.string "{PLAYER}{KUN} und {RIVAL}, ich\n"
	.string "hatte euch gebeten, mir bei meinen\l"
	.string "Pokémon-Studien zu helfen.\p"
	.string "Dank eurer Hilfe kommen neue Fakten\n"
	.string "ans Tageslicht.\p"
	.string "Scheinbar sind in der Hoenn-Region\n"
	.string "auch Pkmn anderer Regionen ansässig.\p"
	.string "Das ist auch ein Beweis, wie reich die\n"
	.string "Natur in Hoenn ist.\p"
	.string "Daher ist es sinnvoll, wenn ich eure\n"
	.string "Pokédexe mit dem Nationalen Modus\l"
	.string "ausrüste.\p"
	.string "Gebt mir mal eure Pokédexe.$"
#else
	.string "PROF. BIRCH: Now…\p"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
	.string "of you help me study POKéMON.\p"
	.string "Thanks to your help, new facts\n"
	.string "are coming to light.\p"
	.string "It appears that in the HOENN region,\n"
	.string "there are also POKéMON from other\l"
	.string "regions.\p"
	.string "It goes to show how rich and varied\n"
	.string "the natural environments of HOENN\l"
	.string "happen to be.\p"
	.string "That's why I think it's necessary for\n"
	.string "me to upgrade your POKéDEX to\l"
	.string "the NATIONAL Mode.\p"
	.string "Here, let me see your POKéDEX units.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
#if GERMAN
	.string "Maike: Hihihi!\p"
	.string "Ich finde es total cool, dass mein\n"
	.string "Pokédex auch verbessert wird!\p"
	.string "Dank dir, {PLAYER}{KUN}! Denn du hast\n"
	.string "so viele Pokémon gefangen!$"
#else
	.string "MAY: Eheheh!\p"
	.string "It's so cool that even my POKéDEX\n"
	.string "is getting updated!\p"
	.string "It's because you went out and caught\n"
	.string "so many POKéMON, {PLAYER}{KUN}!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
#if GERMAN
	.string "Maike: Ich bin durch ganz Hoenn gereist\n"
	.string "und habe die Pokémon untersucht.\p"
	.string "Dank mir bekommen wir beide jetzt den\n"
	.string "Nationalen Modus.\p"
	.string "Ja ja, heute ist dein Glückstag,\n"
	.string "{PLAYER}!$"
#else
	.string "BRENDAN: I went out all over HOENN\n"
	.string "and checked out POKéMON.\p"
	.string "You can thank me for getting\n"
	.string "the NATIONAL Mode POKéDEX.\p"
	.string "Yep, you're lucky, {PLAYER}!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone:
#if GERMAN
	.string "Prof. Birk: Okay, fertig!$"
#else
	.string "PROF. BIRCH: Okay, all done!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
#if GERMAN
	.string "Der Pokédex von {PLAYER} wurde mit dem\n"
	.string "Nationalen Modus ausgerüstet.$"
#else
	.string "{PLAYER}'s POKéDEX was upgraded\n"
	.string "to the NATIONAL Mode!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
#if GERMAN
	.string "Prof. Birk: Vergiss nicht! Du bist der\n"
	.string "Champ, aber deine Pokémon-Reise ist\l"
	.string "noch lange nicht zu Ende.\p"
	.string "Die Straße namens Pokémon findet\n"
	.string "niemals ein Ende.\p"
	.string "Irgendwo gibt es hohes Gras, das auf\n"
	.string "dich wartet.$"
#else
	.string "PROF. BIRCH: But listen.\n"
	.string "You've become the CHAMPION,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
#if GERMAN
	.string "Maike: Ich glaube, ich gönne mir eine\n"
	.string "kurze Pause von der Arbeit draußen.\p"
	.string "Ich werde dem Prof hier ein bisschen\n"
	.string "helfen.$"
#else
	.string "MAY: I think I'll take a short break\n"
	.string "from fieldwork.\p"
	.string "I think I'll help the PROF here for\n"
	.string "a while.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
#if GERMAN
	.string "Maike: Ich glaube, ich gönne mir eine\n"
	.string "kurze Pause von der Arbeit draußen.\p"
	.string "Ich werde dem Prof hier ein bisschen\n"
	.string "helfen.$"
#else
	.string "BRENDAN: For the time being,\n"
	.string "I'm taking a break from fieldwork.\p"
	.string "I'll be helping out the PROF here\n"
	.string "for a while.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
#if GERMAN
	.string "Prof. Birk: Oh, {PLAYER}{KUN}!\n"
	.string "Lass mich einen Blick auf deinen\l"
	.string "Pokédex werfen.\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\p"
	.string "Ja, es besteht kein Zweifel.\p"
	.string "Dein Pokédex der Hoenn-Region ist\n"
	.string "vollständig!\p"
	.string "Das ist mehr als beeindruckend.\p"
	.string "Ich habe ein Geschenk für dich.\p"
	.string "Nimm es als Anerkennung der\n"
	.string "fantastischen Arbeit, die du geleistet\l"
	.string "hast.\p"
	.string "Ich schenke dir ein seltenes Pokémon,\n"
	.string "das nur in einer anderen Region zu\l"
	.string "finden ist.\p"
	.string "Such dir eines von diesen drei Pokémon\n"
	.string "aus.$"
#else
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "Let's have a look at your POKéDEX.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Yes, there's no doubt about it.\p"
	.string "You really have completed the HOENN\n"
	.string "region's POKéDEX.\p"
	.string "That's more than just impressive.\p"
	.string "I have a gift for you.\p"
	.string "Consider it my show of appreciation\n"
	.string "for the fantastic work you've done.\p"
	.string "My gift is a rare POKéMON only found\n"
	.string "in another region!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
#if GERMAN
	.string "Prof. Birk: Dies sind seltene Pokémon,\n"
	.string "die in anderen Regionen beheimatet\l"
	.string "sind.\p"
	.string "Such dir eines von den drei Pokémon\n"
	.string "aus.$"
#else
	.string "PROF. BIRCH: These are rare POKéMON\n"
	.string "only found in another region!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
#if GERMAN
	.string "Prof. Birk: Das Feuer-Pokémon\n"
	.string "Feurigel hat dein Interesse geweckt?\p"
	.string "Du bist clever wie immer!\p"
	.string "Du möchtest Feurigel haben?$"
#else
	.string "PROF. BIRCH: The FIRE POKéMON\n"
	.string "CYNDAQUIL caught your eye!\p"
	.string "You're as sharp as ever!\p"
	.string "So the CYNDAQUIL is your choice?$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
#if GERMAN
	.string "Prof. Birk: Das Wasser-Pokémon\n"
	.string "Karnimani hat dein Interesse geweckt?\l"
	.string "\p"
	.string "Eine gute Wahl!\p"
	.string "Du möchtest Karnimani haben?$"
#else
	.string "PROF. BIRCH: The WATER POKéMON\n"
	.string "TOTODILE is your choice!\p"
	.string "You know how to pick a good one.\p"
	.string "So, you'll take the TOTODILE?$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
#if GERMAN
	.string "Prof. Birk: Das Pflanzen-Pokémon\n"
	.string "Endivie hat dein Interesse geweckt?\p"
	.string "Du weißt, was gut für dich ist!\p"
	.string "Du möchtest Endivie haben?$"
#else
	.string "PROF. BIRCH: The GRASS POKéMON\n"
	.string "CHIKORITA is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the CHIKORITA?$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
#if GERMAN
	.string "Prof. Birk: Lass dir Zeit, bevor du\n"
	.string "dich entscheidest.\p"
	.string "Es sind alles Pokémon von\n"
	.string "unschätzbarem Wert.$"
#else
	.string "PROF. BIRCH: Take your time before\n"
	.string "you decide.\p"
	.string "They're all invaluable POKéMON.$"
#endif

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon:
#if GERMAN
	.string "Prof. Birk: Aha!\n"
	.string "Du hast ein feines Pokémon gewählt!$"
#else
	.string "PROF. BIRCH: I see!\n"
	.string "You picked a fine POKéMON!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
#if GERMAN
	.string "{PLAYER} erhält {STR_VAR_1} von Prof.\n"
	.string "Birk!$"
#else
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. BIRCH!$"
#endif

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
#if GERMAN
	.string "Möchtest du dem {STR_VAR_1}, das du\n"
	.string "erhalten hast, einen Spitznamen geben?$"
#else
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_1} you received?$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
#if GERMAN
	.string "Prof. Birk: Vergiss nicht! Dein\n"
	.string "Hoenn-Pokédex ist vollständig.\p"
	.string "Die Straße namens Pokémon findet\n"
	.string "niemals ein Ende.\p"
	.string "Irgendwo gibt es hohes Gras, das auf\n"
	.string "dich wartet.$"
#else
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
	.string "You've completed the HOENN POKéDEX,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
#if GERMAN
	.string "Du hast das Pokémon erhalten.\n"
	.string "Lass die anderen lieber in Ruhe.$"
#else
	.string "You received the promised POKéMON.\n"
	.string "Better leave the others alone.$"
#endif

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
#if GERMAN
	.string "Oh, du hast keinen Platz für dieses\n"
	.string "Pokémon.$"
#else
	.string "Oh, you don't have any room for\n"
	.string "this POKéMON.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
#if GERMAN
	.string "Maike: {PLAYER}{KUN}, jetzt…\n"
	.string "Was wirst du jetzt tun?\p"
	.string "Wirst du weiter in Kämpfen antreten\n"
	.string "und deine Fähigkeiten verbessern?\p"
	.string "Oder versuchst du, den Nationalen\n"
	.string "Pokédex vollständig zu bekommen?\p"
	.string "Ich werde hier bleiben und dem Prof\n"
	.string "helfen.$"
#else
	.string "MAY: {PLAYER}{KUN}, after this…\n"
	.string "What are you going to do?\p"
	.string "Are you going to keep battling\n"
	.string "and sharpening your skills?\p"
	.string "Or are you going to try filling\n"
	.string "the NATIONAL POKéDEX?\p"
	.string "I'm staying here to help the PROF.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
#if GERMAN
	.string "Maike: Statt nur Pokémon zu sammeln,\n"
	.string "konzentriere ich mich lieber auf das\l"
	.string "Aufziehen eines bestimmten Pokémon.$"
#else
	.string "BRENDAN: Rather than collecting\n"
	.string "POKéMON, I prefer slowly and \l"
	.string "steadily raising the one I chose.$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
#if GERMAN
	.string "Maike: Oh, hi {PLAYER}{KUN}!\n"
	.string "Hast du schon die Kampfzone besucht?$"
#else
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
	.string "Have you gone to that place,\l"
	.string "the BATTLE FRONTIER?$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
#if GERMAN
	.string "Maike: Hey, {PLAYER}!\n"
	.string "Hast du schon die Kampfzone besucht?$"
#else
	.string "BRENDAN: Hey, {PLAYER}!\n"
	.string "Have you gone out to that place,\l"
	.string "the BATTLE FRONTIER?$"
#endif

LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
#if GERMAN
	.string "… … … … … … … … … … …Piep!\p"
	.string "Scott: Hallo {PLAYER}! Ich bin’s,\n"
	.string "Scott.\p"
	.string "Ich bin auf der MS Tide. Auf See\n"
	.string "zu sein ist einfach großartig!\p"
	.string "Übrigens…\p"
	.string "Ich würde dich gerne an einen\n"
	.string "bestimmten Ort einladen.\p"
	.string "Wenn du interessiert bist, dann\n"
	.string "nimm entweder in Graphitport City\l"
	.string "oder Seegrasulb City die Fähre.\p"
	.string "Alles Weitere besprechen wir,\n"
	.string "wenn wir uns an Bord treffen.\l"
	.string "Bis dann!\p"
	.string "… … … … … … … … … … …Klick!$"
#else
	.string "… … … … … … … … … … … Beep!\p"
	.string "SCOTT: Hi, hi, {PLAYER}! It's me,\n"
	.string "SCOTT.\p"
	.string "I'm aboard the S.S. TIDAL now.\n"
	.string "It feels great to be on the sea!\p"
	.string "By the way…\p"
	.string "There's this place that I'd like\n"
	.string "to invite you to for a visit.\p"
	.string "If you're interested, board a\n"
	.string "ferry at either SLATEPORT or\l"
	.string "LILYCOVE.\p"
	.string "I'll fill you in on the details\n"
	.string "when we meet. I'll be waiting!\p"
	.string "… … … … … … … … … … … Click!$"
#endif
