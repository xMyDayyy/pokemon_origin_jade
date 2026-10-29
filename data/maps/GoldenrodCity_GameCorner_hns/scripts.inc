GoldenrodCity_GameCorner_hns_MapScripts::
	.byte 0

GoldenrodCity_GameCorner_PrizeRoom_EventScript_PrizeClerkMons::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon::
	@callnative DisableStaticRandomizer
	showcoinsbox 1, 1
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	multichoice 20, 0, MULTI_PRIZE_MONS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Abra
	case 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Clefairy
	case 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Munchlax
	case 3, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Dratini
	case 4, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Porygon
	case 5, GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	case 127, GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange::
	hidecoinsbox 0, 0
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_Abra::
	setvar VAR_TEMP_1, SPECIES_ABRA
	setvar VAR_TEMP_2, 120
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_Clefairy::
	setvar VAR_TEMP_1, SPECIES_CLEFAIRY
	setvar VAR_TEMP_2, 500
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_Munchlax::
	setvar VAR_TEMP_1, SPECIES_MUNCHLAX
	setvar VAR_TEMP_2, 2800
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_Dratini::
	setvar VAR_TEMP_1, SPECIES_DRATINI
	setvar VAR_TEMP_2, 5500
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_Porygon::
	setvar VAR_TEMP_1, SPECIES_PORYGON
	setvar VAR_TEMP_2, 6500
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	msgbox GoldenrodCity_GameCorner_PrizeRoom_Text_YouWantPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, VAR_TEMP_2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
	switch VAR_TEMP_1
	updatecoinsbox 1, 1
	playse SE_SHOP
	case SPECIES_ABRA,     GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveAbra
	case SPECIES_CLEFAIRY, GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveClefairy
	case SPECIES_DRATINI,  GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveDratini
	case SPECIES_MUNCHLAX,  GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveMunchlax
	case SPECIES_PORYGON,  GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePorygon
	case SPECIES_PINSIR,   GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePinsir
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveAbra::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveClefairy::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveDratini::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveMunchlax::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePorygon::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePinsir::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty
	goto_if_eq VAR_RESULT, 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC
	goto_if_eq VAR_RESULT, 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_PartyFull
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_PartyFull::
	msgbox Route119_WeatherInstitute_2F_Text_NoRoomForPokemon
	hidecoinsbox 0, 0
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_NicknamePartyMon::
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty_Nickname_Nuzlocke::
	message GoldenrodGamecorner_Text_GiveNicknameToThisMon
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase::
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNoCoinCase
	release
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins::
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNeedMoreCoins
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty::
	removecoins VAR_TEMP_2
	playse SE_SHOP
	updatecoinsbox 1, 1
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message GoldenrodCity_GameCorner_Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty_Nickname_Nuzlocke
	msgbox GoldenrodGamecorner_Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NicknamePartyMon
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC::
	removecoins VAR_TEMP_2
	playse SE_SHOP
	updatecoinsbox 1, 1
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message GoldenrodCity_GameCorner_Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_TransferredToPC
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TransferredToPC::
	call Common_EventScript_TransferredToPC
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_PartyMon::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_PcMon::
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_GameCorner_EventScript_SendMon
	call Common_EventScript_NameReceivedBoxMon
	goto GoldenrodCity_GameCorner_EventScript_SendMon
	closemessage
	hidecoinsbox 0, 0
	@callnative EnableStaticRandomizer
	release
	end

GoldenrodCity_GameCorner_EventScript_SendMon::
	call Common_EventScript_TransferredToPC
	closemessage
	hidecoinsbox 0, 0
	@callnative EnableStaticRandomizer
	release
	end

	.set TM_ICE_BEAM_COINS, 4000
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_REST_COINS, 2000
	.set TM_SWORDS_DANCE_COINS, 3000
	.set TM_SUBSTITUTE_COINS, 2000

GoldenrodCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorIntro, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrizeMessage
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrizeMessage::
	message GoldenrodCity_GameCorner_Text_PrizeVendorWhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize::
	message GoldenrodCity_GameCorner_Text_PrizeVendorWhichPrize
	waitmessage
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrize::
	dynmultichoice 12, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, GoldenrodCity_GameCorner_PrizeRoom_Text_TM44, GoldenrodCity_GameCorner_PrizeRoom_Text_TM90, GoldenrodCity_GameCorner_PrizeRoom_Text_TM75, GoldenrodCity_GameCorner_PrizeRoom_Text_TM13, GoldenrodCity_GameCorner_PrizeRoom_Text_TM24, GoldenrodCity_GameCorner_PrizeRoom_Text_TM35, GoldenrodCity_GameCorner_PrizeRoom_Text_Cancel
	switch VAR_RESULT
	case 0, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMRest
	case 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMSubstitute
	case 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMSwordsDance
	case 3, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMIceBeam
	case 4, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMThunderbolt
	case 5, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMFlamethrower
	case 6, GoldenrodCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMIceBeam::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMFlamethrower::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMThunderbolt::
	setvar VAR_TEMP_1, 6
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMRest::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TM_REST
	setvar VAR_0x8004, ITEM_TM_REST
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMSwordsDance::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_TM75
	setvar VAR_0x8004, ITEM_TM75
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMSubstitute::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_TM90
	setvar VAR_0x8004, ITEM_TM90
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox GoldenrodCity_GameCorner_PrizeRoom_Text_SoYourChoiceIsTM, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	goto_if_unset FLAG_FINITE_TMS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrizeInfinite
	switch VAR_TEMP_1
	case 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeam
	case 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrower
	case 3, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMRest
	case 4, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSwordsDance
	case 5, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSubstitute
	case 6, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderbolt
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrizeInfinite::
	switch VAR_TEMP_1
	case 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeamInfinite
	case 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrowerInfinite
	case 3, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMRestInfinite
	case 4, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSwordsDanceInfinite
	case 5, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSubstituteInfinite
	case 6, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderboltInfinite
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeamInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_ICE_BEAM, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrowerInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_FLAMETHROWER, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderboltInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_THUNDERBOLT, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMRestInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_REST_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_REST, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_REST_COINS
	additem ITEM_TM_REST
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSwordsDanceInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_SWORDS_DANCE_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM75, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_SWORDS_DANCE_COINS
	additem ITEM_TM75
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSubstituteInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_SUBSTITUTE_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM90, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_SUBSTITUTE_COINS
	additem ITEM_TM90
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_ICE_BEAM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_FLAMETHROWER
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMRest::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_REST_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_REST
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_REST_COINS
	additem ITEM_TM_REST
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSwordsDance::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_SWORDS_DANCE_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM75
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_SWORDS_DANCE_COINS
	additem ITEM_TM75
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSubstitute::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_SUBSTITUTE_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM90
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_SUBSTITUTE_COINS
	additem ITEM_TM90
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM::
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNeedMoreCoins, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis::
	msgbox GoldenrodCity_GameCorner_PrizeRoom_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect::
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorQuit, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

GoldenrodCity_GameCorner_PrizeRoom_Text_TM44:
#if GERMAN
	.string "Erholung{CLEAR_TO 0x58}2.000 M.$"
#else
	.string "REST{CLEAR_TO 0x58}2,000 C.$"
#endif

GoldenrodCity_GameCorner_PrizeRoom_Text_TM90:
#if GERMAN
	.string "Delegator{CLEAR_TO 0x58}2.000 M.$"
#else
	.string "SUBSTITUTE{CLEAR_TO 0x58}2,000 C.$"
#endif

GoldenrodCity_GameCorner_PrizeRoom_Text_TM75:
#if GERMAN
	.string "Schwerttanz{CLEAR_TO 0x58}3.000 M.$"
#else
	.string "SWORDS DANCE{CLEAR_TO 0x58}3,000 C.$"
#endif

GoldenrodCity_GameCorner_PrizeRoom_Text_TM13:
#if GERMAN
	.string "Eisstrahl{CLEAR_TO 0x58}4.000 M.$"
#else
	.string "ICE BEAM{CLEAR_TO 0x58}4,000 C.$"
#endif

GoldenrodCity_GameCorner_PrizeRoom_Text_TM24:
#if GERMAN
	.string "Donnerblitz{CLEAR_TO 0x58}4.000 M.$"
#else
	.string "THUNDERBOLT{CLEAR_TO 0x58}4,000 C.$"
#endif

GoldenrodCity_GameCorner_PrizeRoom_Text_TM35:
#if GERMAN
	.string "Flammenwurf{CLEAR_TO 0x58}4.000 M.$"
#else
	.string "FLAMETHROWER{CLEAR_TO 0x58}4,000 C.$"
#endif

GoldenrodCity_GameCorner_PrizeRoom_Text_Cancel:
#if GERMAN
	.string "Abbruch$"
#else
	.string "EXIT$"
#endif

GoldenrodCity_GameCorner_PrizeRoom_Text_SoYourChoiceIsTM:
#if GERMAN
	.string "Du möchtest also {STR_VAR_1} {STR_VAR_2}?$"
#else
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"
#endif

GoldenrodCity_GameCorner_PrizeRoom_Text_YouAlreadyHaveThis:
#if GERMAN
	.string "Das Item hast du bereits.$"
#else
	.string "You already have that item.$"
#endif


GoldenrodCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_PokefanM1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_Hiker::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_MoveTutorInside, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_PokefanM2::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_PokefanM2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_CooltrainerM::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_Pharmacist::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_Pharmacist, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_PrizeRoom_Text_YouWantPrize:
#if GERMAN
	.string "{STR_VAR_1} richtig?$"
#else
	.string "{STR_VAR_1} is what you want?$"
#endif

GoldenrodCity_GameCorner_Text_PlayerObtainedTheMon:
#if GERMAN
	.string "{PLAYER} erhält {STR_VAR_1}!$"
#else
	.string "{PLAYER} got {STR_VAR_1}!$"
#endif

GoldenrodGamecorner_Text_GiveNicknameToThisMon:
#if GERMAN
	.string "{STR_VAR_1} Spitzname geben?$"
#else
	.string "Nickname {STR_VAR_1}?$"
#endif

GoldenrodCity_GameCorner_Text_PrizeVendorIntro:
#if GERMAN
	.string "Willkommen!\p"
	.string "Wir tauschen deine Spielmünzen\n"
	.string "gegen tolle Preise!$"
#else
    .string "Welcome!\p"
    .string "We exchange your game coins for\n"
    .string "fabulous prizes!$"
#endif

GoldenrodCity_GameCorner_Text_PrizeVendorWhichPrize:
#if GERMAN
	.string "Welchen Preis möchtest du?$"
#else
    .string "Which prize would you like?$"
#endif

GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo:
#if GERMAN
	.string "Hier, bitte!$"
#else
    .string "Here you go!$"
#endif

GoldenrodCity_GameCorner_Text_PrizeVendorNeedMoreCoins:
#if GERMAN
	.string "Tut mir Leid, aber du brauchst mehr\n"
	.string "Münzen.$"
#else
    .string "Sorry! You need more coins.$"
#endif

GoldenrodCity_GameCorner_Text_PrizeVendorNoMoreRoom:
#if GERMAN
	.string "Dein Beutel scheint voll zu sein!$"
#else
    .string "Sorry. You can't carry any more.$"
#endif

GoldenrodCity_GameCorner_Text_PrizeVendorQuit:
#if GERMAN
	.string "Oh, in Ordnung! Dann spare dir ein paar\n"
	.string "Münzen zusammen, bis du wiederkommst!$"
#else
    .string "OK. Please save your coins and come\n"
    .string "again!$"
#endif

GoldenrodCity_GameCorner_Text_PrizeVendorNoCoinCase:
#if GERMAN
	.string "Oh? Du hast keinen Münzkorb.$"
#else
    .string "Oh? You don't have a COIN CASE.$"
#endif

GoldenrodCity_GameCorner_Text_Pharmacist:
#if GERMAN
	.string "Ich spiele nur an diesem Automaten.\p"
	.string "Ich glaube, er spuckt mehr aus\n"
	.string "als die anderen.$"
#else
    .string "I always play this slot machine.\n"
    .string "It pays out more than others,\l"
    .string "I think.$"
#endif

GoldenrodCity_GameCorner_Text_Woman:
#if GERMAN
	.string "Dein Spielplatz!\p"
	.string "Dukatia City Spielhalle$"
#else
    .string "I can't stop winning!$"
#endif

GoldenrodCity_GameCorner_Text_PokefanM1:
#if GERMAN
	.string "Ich liebe diesen neuen Automaten.\p"
	.string "Er stellt eine größere Herausforderung\n"
	.string "dar als jene in Prismania City.$"
#else
    .string "I just love this new slot machine.\p"
    .string "It's more of a challenge than the\n"
    .string "ones in CELADON.$"
#endif

GoldenrodCity_GameCorner_Text_CooltrainerM:
#if GERMAN
	.string "Das Leben ist ein Spiel.\p"
	.string "Ich werde Karten spielen, bis\n"
	.string "ich umfalle!$"
#else
    .string "Life is a gamble. I'm going to pull\n"
    .string "till I drop!$"
#endif

GoldenrodCity_GameCorner_Text_PokefanF:
#if GERMAN
	.string "Karten…\p"
	.string "Ich ziehe sie den Automaten vor, weil\n"
	.string "man seine Chancen besser abschätzen\l"
	.string "kann.\p"
	.string "Aber der Gewinn ist viel geringer.$"
#else
    .string "Roulette…\p"
    .string "I prefer it over the slots because\n"
    .string "it's easier to figure the odds.\p"
    .string "But the payout is much lower.$"
#endif

GoldenrodCity_GameCorner_Text_CooltrainerF:
#if GERMAN
	.string "Ich höre erst auf, wenn ich gewinne!$"
#else
    .string "I won't quit until I win!$"
#endif

GoldenrodCity_GameCorner_Text_Gentleman:
#if GERMAN
	.string "Ich habe meinen Pokémon Eisstrahl\n"
	.string "beigebracht.\p"
	.string "Es hat zwar gedauert, bis ich genug\n"
	.string "Münzen hatte, aber es hat sich gelohnt.$"
#else
    .string "I taught ICE BEAM to my POKéMON.\p"
    .string "It was hard to get enough coins for\n"
    .string "it, but it was worth it.$"
#endif

GoldenrodCity_GameCorner_Text_PokefanM2:
#if GERMAN
	.string "Ich hatte an den Automaten kein Glück.\n"
	.string "Bei den Karten sieht es auch nicht\l"
	.string "anders aus…\p"
	.string "Ich war so zornig, dass ich meinen\n"
	.string "Münzkorb im Untergrund weggeworfen\l"
	.string "habe.$"
#else
    .string "I couldn't win at the slots, and I\n"
    .string "blew it on roulette.\p"
    .string "I got so furious, I tossed out my\n"
    .string "COIN CASE in the UNDERGROUND.$"
#endif

GoldenrodCity_GameCorner_Text_MoveTutorInside:
#if GERMAN
	.string "Wahahah! Die Münzen klingeln!$"
#else
    .string "Wahahah! The coins keep rolling in!$"
#endif

GoldenrodCity_GameCorner_Text_LeftTheirDrink:
#if GERMAN
	.string "Jemand hat sein Getränk stehen lassen.\p"
	.string "Es riecht süß!$"
#else
    .string "Someone left their drink.\p"
    .string "It smells sweet.$"
#endif

@ ========================================
@ VOLTORB FLIP GAME IMPLEMENTATION
@ ========================================

GoldenrodCity_GameCorner_EventScript_VoltorbFlip::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_EventScript_VF_NoCoinCase
	message GoldenrodCity_GameCorner_Text_VF_Welcome
	waitmessage
	setvar VAR_TEMP_4, 0

GoldenrodCity_GameCorner_EventScript_VF_CheckCoinCap::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, MAX_COINS, GoldenrodCity_GameCorner_EventScript_VF_ShowMenu
	msgbox GoldenrodCity_GameCorner_Text_VF_CoinCap, MSGBOX_DEFAULT
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_7, 0
	hidecoinsbox 0, 5
	releaseall
	end

GoldenrodCity_GameCorner_EventScript_VF_ShowMenu::
	showcoinsbox 1, 1
	copyvar VAR_TEMP_A, VAR_TEMP_4
	addvar VAR_TEMP_A, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_A
	message GoldenrodCity_GameCorner_Text_VF_PlayLevel
	waitmessage
	dynmultichoice 19, 6, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, GoldenrodCity_GameCorner_Text_VF_OptPlay, GoldenrodCity_GameCorner_Text_VF_OptGameInfo, GoldenrodCity_GameCorner_Text_VF_OptQuit
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_GameCorner_EventScript_VF_Play
	goto_if_eq VAR_RESULT, 1, GoldenrodCity_GameCorner_EventScript_VF_GameInfo
	@ Quit or B-press
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_7, 0
	closemessage
	hidecoinsbox 0, 5
	releaseall
	end

GoldenrodCity_GameCorner_EventScript_VF_GameInfo::
	message GoldenrodCity_GameCorner_Text_VF_WhichInfo
	waitmessage
	dynmultichoice 19, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, GoldenrodCity_GameCorner_Text_VF_OptHowToPlay, GoldenrodCity_GameCorner_Text_VF_OptHint, GoldenrodCity_GameCorner_Text_VF_OptAboutNotes, GoldenrodCity_GameCorner_Text_VF_OptReturn
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_GameCorner_EventScript_VF_HowToPlay
	goto_if_eq VAR_RESULT, 1, GoldenrodCity_GameCorner_EventScript_VF_Hint
	goto_if_eq VAR_RESULT, 2, GoldenrodCity_GameCorner_EventScript_VF_AboutNotes
	goto GoldenrodCity_GameCorner_EventScript_VF_ShowMenu

GoldenrodCity_GameCorner_EventScript_VF_HowToPlay::
	msgbox GoldenrodCity_GameCorner_Text_VF_HowToPlay, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_GameInfo

GoldenrodCity_GameCorner_EventScript_VF_Hint::
	msgbox GoldenrodCity_GameCorner_Text_VF_HintText, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_GameInfo

GoldenrodCity_GameCorner_EventScript_VF_AboutNotes::
	msgbox GoldenrodCity_GameCorner_Text_VF_AboutNotes, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_GameInfo

GoldenrodCity_GameCorner_EventScript_VF_Play::
	closemessage
	copyvar VAR_TEMP_6, VAR_TEMP_4
	setvar VAR_TEMP_5, 0
	hidecoinsbox 0, 5
	special Special_ViewVoltorbFlip
	waitstate
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_GameCorner_EventScript_VF_HandleLoss
	goto_if_eq VAR_RESULT, 1, GoldenrodCity_GameCorner_EventScript_VF_HandleWin
	goto GoldenrodCity_GameCorner_EventScript_VF_HandleQuit
	end

GoldenrodCity_GameCorner_EventScript_VF_HandleWin::
	msgbox GoldenrodCity_GameCorner_Text_VF_GameClear, MSGBOX_DEFAULT
	copyvar VAR_TEMP_1, VAR_TEMP_5
	showcoinsbox 1, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_1
	msgbox GoldenrodCity_GameCorner_Text_VF_ReceivedCoins, MSGBOX_DEFAULT
	addcoins VAR_TEMP_5
	setvar VAR_TEMP_5, 0
	updatecoinsbox 1, 1
	goto_if_le VAR_TEMP_4, VAR_TEMP_6, GoldenrodCity_GameCorner_EventScript_VF_CheckCoinCap
	copyvar VAR_TEMP_A, VAR_TEMP_4
	addvar VAR_TEMP_A, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_A
	msgbox GoldenrodCity_GameCorner_Text_VF_Advanced, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_CheckCoinCap

GoldenrodCity_GameCorner_EventScript_VF_HandleLoss::
	msgbox GoldenrodCity_GameCorner_Text_VF_OhNo, MSGBOX_DEFAULT
	goto_if_ge VAR_TEMP_4, VAR_TEMP_6, GoldenrodCity_GameCorner_EventScript_VF_ShowMenu
	copyvar VAR_TEMP_A, VAR_TEMP_4
	addvar VAR_TEMP_A, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_A
	msgbox GoldenrodCity_GameCorner_Text_VF_Dropped, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_ShowMenu

GoldenrodCity_GameCorner_EventScript_VF_HandleQuit::
	goto_if_eq VAR_TEMP_5, 0, GoldenrodCity_GameCorner_EventScript_VF_QuitNoCoins
	copyvar VAR_TEMP_1, VAR_TEMP_5
	showcoinsbox 1, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_1
	msgbox GoldenrodCity_GameCorner_Text_VF_ReceivedCoins, MSGBOX_DEFAULT
	addcoins VAR_TEMP_5
	setvar VAR_TEMP_5, 0
	updatecoinsbox 1, 1

GoldenrodCity_GameCorner_EventScript_VF_QuitNoCoins::
	goto_if_ge VAR_TEMP_4, VAR_TEMP_6, GoldenrodCity_GameCorner_EventScript_VF_CheckCoinCap
	copyvar VAR_TEMP_A, VAR_TEMP_4
	addvar VAR_TEMP_A, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_A
	msgbox GoldenrodCity_GameCorner_Text_VF_Dropped, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_CheckCoinCap

GoldenrodCity_GameCorner_EventScript_VF_NoCoinCase::
	msgbox GoldenrodCity_GameCorner_Text_VF_NeedCoinCase, MSGBOX_DEFAULT
	releaseall
	end

GoldenrodCity_GameCorner_EventScript_VFAttendant1::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_VFAttendant1, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceDown
	waitmovement 0
	release
	end

GoldenrodCity_GameCorner_EventScript_VFAttendant2::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_VFAttendant2, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceDown
	waitmovement 0
	release
	end

@ Voltorb Flip Menu Option Strings
GoldenrodCity_GameCorner_Text_VF_OptPlay:
#if GERMAN
	.string "Spielen$"
#else
	.string "PLAY$"
#endif

GoldenrodCity_GameCorner_Text_VF_OptGameInfo:
#if GERMAN
	.string "Spielregeln$"
#else
	.string "GAME INFO$"
#endif

GoldenrodCity_GameCorner_Text_VF_OptQuit:
#if GERMAN
	.string "Ende$"
#else
	.string "QUIT$"
#endif

GoldenrodCity_GameCorner_Text_VF_OptHowToPlay:
#if GERMAN
	.string "Wie man spielt$"
#else
	.string "HOW TO PLAY$"
#endif

GoldenrodCity_GameCorner_Text_VF_OptHint:
#if GERMAN
	.string "Tipps!$"
#else
	.string "HINT$"
#endif

GoldenrodCity_GameCorner_Text_VF_OptAboutNotes:
#if GERMAN
	.string "Über Hinweise$"
#else
	.string "ABOUT NOTES$"
#endif

GoldenrodCity_GameCorner_Text_VF_OptReturn:
#if GERMAN
	.string "Zurück$"
#else
	.string "RETURN$"
#endif

@ Voltorb Flip Dialogue Strings
GoldenrodCity_GameCorner_Text_VF_Welcome:
#if GERMAN
	.string "Willkommen bei Voltofalle!\p$"
#else
	.string "Welcome to VOLTORB FLIP!\p$"
#endif

GoldenrodCity_GameCorner_Text_VF_PlayLevel:
#if GERMAN
	.string "Möchtest du Voltofalle Lv. {STR_VAR_1} spielen?$"
#else
	.string "Play VOLTORB Flip Lv. {STR_VAR_1}?$"
#endif

GoldenrodCity_GameCorner_Text_VF_GameClear:
#if GERMAN
	.string "Geschafft!\p"
	.string "Du hast alle versteckten x2- und\n"
	.string "x3-Karten gefunden!$"
#else
	.string "Game clear!\p"
	.string "You've found all the hidden\n"
	.string "x2 and x3 cards!$"
#endif

GoldenrodCity_GameCorner_Text_VF_ReceivedCoins:
#if GERMAN
	.string "Du hast {STR_VAR_1} Münze(n) erhalten!$"
#else
	.string "You have received\n"
	.string "{STR_VAR_1} Coin(s)!$"
#endif

GoldenrodCity_GameCorner_Text_VF_Advanced:
#if GERMAN
	.string "Der Schwierigkeitsgrad von Voltofalle\n"
	.string "steigt auf Lv. {STR_VAR_1} an!$"
#else
	.string "Advanced to Game Lv. {STR_VAR_1}!$"
#endif

GoldenrodCity_GameCorner_Text_VF_OhNo:
#if GERMAN
	.string "So ein Pech! Du gehst leer aus!$"
#else
	.string "Oh no! You get 0 Coins!$"
#endif

GoldenrodCity_GameCorner_Text_VF_Dropped:
#if GERMAN
	.string "Der Schwierigkeitsgrad von Voltofalle\n"
	.string "fällt auf Lv. {STR_VAR_1} zurück!$"
#else
	.string "Dropped to Game Lv. {STR_VAR_1}.$"
#endif

GoldenrodCity_GameCorner_Text_VF_CoinCap:
#if GERMAN
	.string "Du hast 9 999 Münzen gesammelt.\n"
	.string "Mehr kannst du nicht tragen.$"
#else
	.string "You've gathered 9,999 COINS.\n"
	.string "You cannot gather any more.$"
#endif

GoldenrodCity_GameCorner_Text_VF_WhichInfo:
#if GERMAN
	.string "Was möchtest du wissen?$"
#else
	.string "Which set of info?$"
#endif

GoldenrodCity_GameCorner_Text_VF_HowToPlay:
#if GERMAN
	.string "Bei Voltoball-Flip deckst du Karten\n"
	.string "mit versteckten Zahlen auf.\p"
	.string "Unter ihnen liegen die Zahlen\n"
	.string "1 bis 3 und Voltoball.\p"
	.string "Die erste Zahl bringt dir entsprechend\n"
	.string "viele Münzen.\p"
	.string "Jede weitere Zahl vervielfacht\n"
	.string "deinen bisherigen Gewinn.\p"
	.string "Eine 2 verdoppelt, eine 3 verdreifacht\n"
	.string "ihn.\p"
	.string "Triffst du Voltoball, ist das Spiel\n"
	.string "vorbei.\p"
	.string "Alle in der Runde gesammelten\n"
	.string "Münzen gehen verloren!\p"
	.string "Mit Aufgeben sicherst du dir deine\n"
	.string "bisherigen Münzen.\p"
	.string "Finde alle x2- und x3-Karten,\n"
	.string "um die nächste Stufe zu erreichen!$"
#else
	.string "VOLTORB FLIP is a game in which you flip\n"
	.string "cards to find numbers hidden beneath.\p"
	.string "The cards hide the numbers 1 through 3,\n"
	.string "and VOLTORB as well.\p"
	.string "The first number you flip gives\n"
	.string "you that many Coins.\p"
	.string "Each new number multiplies your total.\n"
	.string "A 2 by x2 and a 3 by x3.\p"
	.string "But if you flip a VOLTORB, it's game over.\n"
	.string "You lose all Coins collected that round!\p"
	.string "QUIT the game at any time to keep\n"
	.string "the Coins you've found so far.\p"
	.string "Find all hidden x2 and x3 cards to clear\n"
	.string "the game and advance to the next level!$"
#endif

GoldenrodCity_GameCorner_Text_VF_HintText:
#if GERMAN
	.string "Die Zahlen am Rand geben dir Hinweise\n"
	.string "auf die Felder.\p"
	.string "Sie beziehen sich auf die jeweilige\n"
	.string "Reihe oder Spalte.\p"
	.string "Je höher die Zahl, desto mehr\n"
	.string "wertvolle Karten gibt es dort.\p"
	.string "Die Voltoball-Anzahl zeigt, wie viele\n"
	.string "sich dort verstecken.\p"
	.string "Nutze beide Hinweise, um sichere Karten\n"
	.string "zu finden!$"
#else
	.string "The numbers on the sides of the board\n"
	.string "are hints about the numbers…\p"
	.string "hidden in that row or column.\p"
	.string "The larger the number, the more high-\n"
	.string "value cards are in that row or column.\p"
	.string "The VOLTORB count tells you how\n"
	.string "many VOLTORBs lurk there.\p"
	.string "Use both totals to figure out\n"
	.string "which cards are safe to flip!$"
#endif

GoldenrodCity_GameCorner_Text_VF_AboutNotes:
#if GERMAN
	.string "Mit dem Notizmodus ({L_BUTTON} &\n"
	.string "{R_BUTTON}) markierst du\p"
	.string "Karten mit 1-3 oder Voltoball.\p"
	.string "Markiere vermutete Felder und\n"
	.string "decke sie später auf.\p"
	.string "Eine weitere Markierung entfernt die\n"
	.string "Notiz.$"
#else
	.string "Use the notes mode ({L_BUTTON} & {R_BUTTON}) to mark\n"
	.string "cards with numbers 1-3 or a VOLTORB.\p"
	.string "Mark a card you think you know,\n"
	.string "then flip it when you're sure.\p"
	.string "Apply a note again to remove it.$"
#endif

GoldenrodCity_GameCorner_Text_VF_NeedCoinCase:
#if GERMAN
	.string "Oh? Du hast keinen Münzkorb.$"
#else
	.string "Oh? You don't have a COIN CASE.$"
#endif

GoldenrodCity_GameCorner_Text_VFAttendant1:
#if GERMAN
	.string "Du willst Voltoball-Flip spielen?\p"
	.string "Dazu musst du auf die andere\n"
	.string "Seite des Tisches gehen.$"
#else
	.string "You want to play VOLTORB FLIP?\p"
	.string "You need to be on the other\n"
	.string "side of the table.$"
#endif

GoldenrodCity_GameCorner_Text_VFAttendant2:
#if GERMAN
	.string "Versuch es auf der anderen Seite des\n"
	.string "Tisches, Freund.$"
#else
	.string "Try the other side of\n"
	.string "the table, pal.$"
#endif
