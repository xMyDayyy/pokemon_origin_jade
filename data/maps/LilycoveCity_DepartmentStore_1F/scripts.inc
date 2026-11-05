LilycoveCity_DepartmentStore_1F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_1F_EventScript_Greeter::
	msgbox LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_HOENN_POKELOT_PRIZE_ITEM, ITEM_NONE, LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_HOENN_PICKED_LOTO_TICKET, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
	setflag FLAG_HOENN_PICKED_LOTO_TICKET
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveHoennLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special DoLotteryCornerComputerEffect
	special PickLotteryCornerTicket
	delay 220
	special EndLotteryCornerComputerEffect
	delay 10
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, LilycoveCity_DepartmentStore_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, LilycoveCity_DepartmentStore_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FullMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_HOENN_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_HOENN_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_HOENN_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_HOENN_POKELOT_PRIZE_PLACE, warn=FALSE
	copyvar VAR_0x8005, VAR_HOENN_POKELOT_PRIZE_ITEM, warn=FALSE
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_HOENN_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_HOENN_POKELOT_PRIZE_PLACE, 0
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LittleGirl::
	msgbox LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanM::
	msgbox LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox LilycoveCity_DepartmentStore_1F_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_FloorNamesSign::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
	end

LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore:
#if GERMAN
	.string "Willkommen im Einkaufszentrum von\n"
	.string "Seegrasulb City.$"
#else
	.string "Welcome to LILYCOVE DEPARTMENT STORE.$"
#endif

LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings:
#if GERMAN
	.string "Immer wenn ich in das Einkaufszentrum\n"
	.string "gehe, endet das damit, dass ich tausend\l"
	.string "Dinge kaufe, weil es so viel Spaß macht.$"
#else
	.string "Whenever I come to the DEPARTMENT\n"
	.string "STORE, I always end up buying all sorts\l"
	.string "of things because it's so fun.$"
#endif

LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture:
#if GERMAN
	.string "Heute wird mir meine Mama ein paar\n"
	.string "schöne Möbel kaufen.$"
#else
	.string "Today, my mom is going to buy me some\n"
	.string "nice furniture.$"
#endif

LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill:
#if GERMAN
	.string "Ich kaufe etwas Schönes für mein\n"
	.string "Azumarill, weil es einen Wettbewerb\l"
	.string "gewonnen hat.$"
#else
	.string "I'm buying something for my AZUMARILL\n"
	.string "as a reward for winning a CONTEST.$"
#endif

LilycoveCity_DepartmentStore_1F_Text_Azumarill:
#if GERMAN
	.string "Azumarill: Maririroo!$"
#else
	.string "AZUMARILL: Maririroo!$"
#endif

LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign:
#if GERMAN
	.string "EG: Information\n"
	.string "       Lotterie\p"
	.string "1S: Alles für den Trainer\p"
	.string "2S: Alles für den Kampf\p"
	.string "3S: TM\p"
	.string "4S: Poképuppen\p"
	.string "Dach: Dachterrasse$"
#else
	.string "1F: SERVICE COUNTER\n"
	.string "    LOTTERY CORNER\p"
	.string "2F: TRAINER'S ZONE\p"
	.string "3F: BATTLE COLLECTION\p"
	.string "4F: TM CORNER\p"
	.string "5F: POKé DOLL FLOOR\p"
	.string "ROOFTOP: ROOFTOP PLAZA$"
#endif

@ Unused
LilycoveCity_DepartmentStore_1F_Text_WirelessCommIsFun:
#if GERMAN
	.string "Die Drahtlos-Kommunikation macht\n"
	.string "wirklich Spaß, findest du nicht?\p"
	.string "Ich glaube, damit sind Dinge möglich,\n"
	.string "die es vorher nicht gab.\p"
	.string "Zum Beispiel kannst du jetzt mit Leuten\n"
	.string "tauschen, mit denen es früher nicht\l"
	.string "ging.\p"
	.string "Ich finde, das wird richtig spannend!$"
#else
	.string "Wireless Communication is a\n"
	.string "lot of fun, isn't it?\p"
	.string "I think it lets you do things that\n"
	.string "weren't possible before.\p"
	.string "For instance, you can now trade\n"
	.string "with people you couldn't before.\p"
	.string "I think it's going to be exciting!$"
#endif

@ Unused
LilycoveCity_DepartmentStore_1F_Text_SpreadWordAboutWirelessComm:
#if GERMAN
	.string "Ich möchte allen erzählen, wie viel\n"
	.string "Spaß die Drahtlos-Kommunikation macht.$"
#else
	.string "I want to spread the word about how\n"
	.string "fun Wireless Communication can be.$"
#endif

