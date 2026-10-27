SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_IS_HOENN_CHAMPION, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	copyobjectxytoperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_IS_HOENN_CHAMPION, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS, 20, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideplayer
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_IS_HOENN_CHAMPION, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
#if IS_HNS
	@ Hoenn badge 7 (Tate & Liza)
	setvar VAR_0x8004, 6
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
#else
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
#endif
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_IS_HOENN_CHAMPION, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
#if GERMAN
	.string "Verzeihung?\n"
	.string "Du suchst nach einem Schiff?\p"
	.string "Oh, das tut mir Leid, aber die Fähre\n"
	.string "steht momentan nicht zur Verfügung…$"
#else
	.string "I beg your pardon?\n"
	.string "You're looking for a ship?\p"
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at present…$"
#endif

SlateportCity_Harbor_Text_MayISeeYourTicket:
#if GERMAN
	.string "Hallo! Möchtest du mit der Fähre\n"
	.string "fahren? Zeigst du mir bitte dein\l"
	.string "Ticket?$"
#else
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"
#endif

SlateportCity_Harbor_Text_YouMustHaveTicket:
#if GERMAN
	.string "{PLAYER} hat kein Ticket…\p"
	.string "Das tut mir schrecklich Leid.\p"
	.string "Nur mit einem Ticket kannst du mit der\n"
	.string "Fähre fahren.$"
#else
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"
#endif

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
#if GERMAN
	.string "{PLAYER} zückt das Ticket.\p"
	.string "Perfekt! Damit kannst du an Bord!\p"
	.string "Und wo soll die Reise hingehen?$"
#else
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"
#endif

SlateportCity_Harbor_Text_SailAnotherTime:
#if GERMAN
	.string "Bitte komm später noch einmal wieder!$"
#else
	.string "Please sail with us another time!$"
#endif

SlateportCity_Harbor_Text_LilycoveItIs:
#if GERMAN
	.string "Nach Seegrasulb City?$"
#else
	.string "LILYCOVE CITY it is, then!$"
#endif

SlateportCity_Harbor_Text_BattleFrontierItIs:
#if GERMAN
	.string "Zur Kampfzone?$"
#else
	.string "BATTLE FRONTIER it is, then!$"
#endif

SlateportCity_Harbor_Text_PleaseBoardFerry:
#if GERMAN
	.string "Bitte komm an Bord. Wir legen bald ab.$"
#else
	.string "Please board the ferry and wait for\n"
	.string "departure.$"
#endif

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
#if GERMAN
	.string "Und wo soll die Reise hingehen?$"
#else
	.string "Then, where would you like to go?$"
#endif

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
#if GERMAN
	.string "Eine Reise zum Meeresboden…\n"
	.string "Ich frage mich, wie es dort wohl ist?\l"
	.string "\p"
	.string "Eines Tages möchte ich auch einmal so\n"
	.string "tief unter Wasser reisen.$"
#else
	.string "A journey to the bottom of the sea…\n"
	.string "I wonder what it'd be like?\p"
	.string "I'd love to go deep underwater like\n"
	.string "that someday.$"
#endif

SlateportCity_Harbor_Text_AbnormalWeather:
#if GERMAN
	.string "Um eine sichere Schiffsreise zu\n"
	.string "gewährleisten, müssen wir stets auf das\l"
	.string "Wetter achten.\p"
	.string "Apropos Wetter: Ein Typ vom\n"
	.string "Klimainstitut hat mir etwas\l"
	.string "Interessantes erzählt.\p"
	.string "Er sagte, dass im ganzen Land das\n"
	.string "Wetter verrückt spielt!\p"
	.string "Du solltest mal zum Klima-Institut\n"
	.string "gehen und dich umhören.$"
#else
	.string "For a ship to sail safely, we need to\n"
	.string "know about the weather!\p"
	.string "Speaking of weather, I heard something\n"
	.string "from a guy at the WEATHER INSTITUTE.\p"
	.string "He was saying abnormal weather has\n"
	.string "been reported all over the place!\p"
	.string "You should visit the WEATHER INSTITUTE\n"
	.string "and ask around!$"
#endif

SlateportCity_Harbor_Text_SubTooSmallForMe:
#if GERMAN
	.string "Ich wäre gerne mit Kapt. Brigg auf die\n"
	.string "Expedition zum Meeresboden gegangen.\p"
	.string "Aber das U-Boot ist zu klein für mich.\n"
	.string "\p"
	.string "Ich könnte mich ja reinquetschen, aber\n"
	.string "dann hätte der Kapitän keinen Platz\l"
	.string "mehr…$"
#else
	.string "I wanted to go with CAPT. STERN on\n"
	.string "the ocean floor exploration.\p"
	.string "But the sub's too small for me.\p"
	.string "If I squeezed in, there wouldn't be\n"
	.string "any room for the CAPTAIN…$"
#endif

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
#if GERMAN
	.string "Kapt. Brigg: Diese Schlägertypen…\p"
	.string "Das sind die gleichen Typen, die\n"
	.string "versucht haben, die Devon-waren aus\l"
	.string "dem Museum zu stehlen.$"
#else
	.string "CAPT. STERN: Those thugs…\p"
	.string "They're the same lot who tried to rob\n"
	.string "the DEVON GOODS at the MUSEUM.$"
#endif

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
#if GERMAN
	.string "Adrian: Oh?\n"
	.string "Nicht du schon wieder… Stöhn…\p"
	.string "Du bist ganz schön hartnäckig, uns bis\n"
	.string "hierher zu folgen, das muss ich schon\l"
	.string "sagen.\p"
	.string "Und nun…\n"
	.string "Niemand kann uns stoppen! Niemand!!!\p"
	.string "Oder willst du uns etwa in unser Ver-\n"
	.string "steck in Seegrasulb City folgen?\p"
	.string "Ahahahahaha…$"
#else
	.string "ARCHIE: Oh?\n"
	.string "Not you again…\p"
	.string "You are tenacious to track us here,\n"
	.string "that much I will give you.\p"
	.string "But now…\n"
	.string "No one can stop us! No one!\p"
	.string "Or, will you follow us back to our\n"
	.string "HIDEOUT in LILYCOVE CITY?\p"
	.string "Fwahahahaha…$"
#endif

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
#if GERMAN
	.string "Kapt. Brigg: Warum…\p"
	.string "Warum sollte Team Aqua mein Tief-\n"
	.string "see-Forschungsboot 1 stehlen wollen?\p"
	.string "Sie können doch nicht hinter dem\n"
	.string "schlafenden Pokémon am Meeresgrund\l"
	.string "her sein…\p"
	.string "Selbst wenn ich sie verfolgen würde…\n"
	.string "Ich hätte keine Chance gegen sie…$"
#else
	.string "CAPT. STERN: Why…\p"
	.string "Why would TEAM AQUA steal my\n"
	.string "SUBMARINE EXPLORER 1?\p"
	.string "They can't be after the slumbering\n"
	.string "POKéMON at the bottom of the sea…\p"
	.string "But even if I were to chase them,\n"
	.string "I don't stand a chance against them…$"
#endif

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
#if GERMAN
	.string "Kapt. Brigg: Oh, {PLAYER}{KUN}…\p"
	.string "Okay… Du konntest Team Aqua nicht\n"
	.string "aufhalten…\p"
	.string "Oh, nein, mach dir bitte keine Vorwürfe!\n"
	.string "Die Schuld liegt nicht bei dir.\p"
	.string "Ein U-Boot zu verfolgen und\n"
	.string "aufzuhalten ist für die meisten\l"
	.string "Menschen unmöglich.\p"
	.string "Du benötigst ein Pokémon, das weiß,\n"
	.string "wie man Taucher ausführt…\p"
	.string "Vielleicht, wenn du dich nach Moosbach\n"
	.string "City begibst…\p"
	.string "Dort trifft man auf viele Taucher.\n"
	.string "Vielleicht kann dir einer das\l"
	.string "beibringen…$"
#else
	.string "CAPT. STERN: Oh, {PLAYER}{KUN}…\p"
	.string "Okay… So TEAM AQUA left before you\n"
	.string "could stop them…\p"
	.string "Oh, no, don't blame yourself.\n"
	.string "You're not responsible for this.\p"
	.string "Trying to catch a submarine…\n"
	.string "It's impossible for most people.\p"
	.string "You would need a POKéMON that knows\n"
	.string "how to DIVE…\p"
	.string "Perhaps if you went out to\n"
	.string "MOSSDEEP CITY…\p"
	.string "A lot of divers live out there, so\n"
	.string "someone might teach you…$"
#endif

SlateportCity_Harbor_Text_NeedDiveToCatchSub:
#if GERMAN
	.string "Kapt. Brigg: Ein U-Boot einzuholen und\n"
	.string "aufzuhalten… Das ist unmöglich.\p"
	.string "Du benötigst ein Pokémon, das weiß,\n"
	.string "wie man Taucher ausführt…\p"
	.string "Vielleicht, wenn du dich nach Moosbach\n"
	.string "City begibst…\p"
	.string "Dort trifft man auf viele Taucher,\n"
	.string "vielleicht kann dir einer das\l"
	.string "beibringen…$"
#else
	.string "CAPT. STERN: Trying to catch a\n"
	.string "submarine… It's impossible.\p"
	.string "You would need a POKéMON that knows\n"
	.string "how to DIVE…\p"
	.string "Perhaps if you went out to\n"
	.string "MOSSDEEP CITY…\p"
	.string "A lot of divers live out there, so\n"
	.string "someone might teach you…$"
#endif

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
#if GERMAN
	.string "Kapt. Brigg: Oh, ja.\n"
	.string "Mr. Brack kam in unsere Werft.\p"
	.string "Nun dauert es nicht mehr lange, bis\n"
	.string "wir unsere Fähre fertig stellen!$"
#else
	.string "CAPT. STERN: Oh, yes.\n"
	.string "MR. BRINEY came to our SHIPYARD.\p"
	.string "It won't be long now before we finish\n"
	.string "making the ferry!$"
#endif

SlateportCity_Harbor_Text_FinishedMakingFerry:
#if GERMAN
	.string "Kapt. Brigg: {PLAYER}{KUN}!\p"
	.string "Wir haben die Fähre MS Tide endlich\n"
	.string "fertig gestellt.\p"
	.string "Ohne die Hilfe deines Freundes Mr.\n"
	.string "Brack hätten wir das nicht geschafft.\l"
	.string "\p"
	.string "Bitte nimm an einer kurzen Fahrt teil!$"
#else
	.string "CAPT. STERN: {PLAYER}{KUN}!\p"
	.string "We finally finished making the ferry\n"
	.string "S.S. TIDAL!\p"
	.string "We couldn't have done it without\n"
	.string "your friend MR. BRINEY.\p"
	.string "Please go for a short cruise on it!$"
#endif

SlateportCity_Harbor_Text_WouldYouTradeScanner:
#if GERMAN
	.string "Kapt. Brigg: Oh?\n"
	.string "{PLAYER}{KUN}, das Item, das du da\l"
	.string "hast… \p"
	.string "Das ist ein Scanner! Der würde uns\n"
	.string "sicher bei unseren Forschungen helfen.\l"
	.string "\p"
	.string "{PLAYER}{KUN}, würdest du ihn gegen\n"
	.string "etwas anderes eintauschen?\p"
	.string "Zum Beispiel gegen einen Abysszahn\n"
	.string "oder eine Abyssplatte?$"
#else
	.string "CAPT. STERN: Oh?\n"
	.string "{PLAYER}{KUN}, that item you have…\p"
	.string "That's a SCANNER! That would sure\n"
	.string "help us on our explorations.\p"
	.string "{PLAYER}{KUN}, would you trade your\n"
	.string "SCANNER for something?\p"
	.string "Like, say, a DEEPSEATOOTH or\n"
	.string "a DEEPSEASCALE that I have?$"
#endif

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
#if GERMAN
	.string "Kapt. Brigg: Bist du sicher? Aber damit\n"
	.string "kannst du doch nichts anfangen…\p"
	.string "Also gut. Wenn du aber den Scanner doch\n"
	.string "noch gegen etwas anderes tauschen\l"
	.string "willst, dann lass es mich wissen!$"
#else
	.string "CAPT. STERN: Are you certain?\n"
	.string "It's useless to you, {PLAYER}{KUN}…\p"
	.string "Well, okay, then. If you want to trade\n"
	.string "your SCANNER, let me know.$"
#endif

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
#if GERMAN
	.string "Kapt. Brigg: Du möchtest den Abysszahn\n"
	.string "dafür haben?$"
#else
	.string "CAPT. STERN: So you'll trade it for\n"
	.string "my DEEPSEATOOTH?$"
#endif

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
#if GERMAN
	.string "Kapt. Brigg: Du möchtest die\n"
	.string "Abyssplatte dafür haben?$"
#else
	.string "CAPT. STERN: So you'll trade it for\n"
	.string "my DEEPSEASCALE?$"
#endif

SlateportCity_Harbor_Text_WhichOneDoYouWant:
#if GERMAN
	.string "Kapt. Brigg: Was hättest du gerne?$"
#else
	.string "CAPT. STERN: Which one do you want?$"
#endif

SlateportCity_Harbor_Text_HandedScannerToStern:
#if GERMAN
	.string "{PLAYER} gibt Kapt. Brigg den Scanner.$"
#else
	.string "{PLAYER} handed the SCANNER to\n"
	.string "CAPT. STERN.$"
#endif

SlateportCity_Harbor_Text_ThisWillHelpResearch:
#if GERMAN
	.string "Kapt. Brigg: Danke, {PLAYER}{KUN}!\n"
	.string "Das wird unsere Forschungen\l"
	.string "weiterbringen!$"
#else
	.string "CAPT. STERN: Thanks, {PLAYER}{KUN}!\n"
	.string "This will help our research a lot!$"
#endif
