FuchsiaCity_SafariZone_Entrance_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZone_Entrance_OnFrame
	.byte 0

FuchsiaCity_SafariZone_Entrance_OnFrame::
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1, FuchsiaCity_SafariZone_Entrance_EventScript_ExitWarpIn
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2, FuchsiaCity_SafariZone_Entrance_EventScript_ExitEarly
	map_script_2 VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3, FuchsiaCity_SafariZone_Entrance_EventScript_ExitWalkIn
	.2byte 0

@ When player runs out of balls mid-battle
FuchsiaCity_SafariZone_Entrance_EventScript_ExitWalkIn::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ApproachCounter
	waitmovement 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit2
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

@ When player runs of out balls after catching a pokemon, or runs out of steps
FuchsiaCity_SafariZone_Entrance_EventScript_ExitWarpIn::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

@ When player re-enters the entrance building with balls/steps remaining
FuchsiaCity_SafariZone_Entrance_EventScript_ExitEarly::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_SafariZone_Entrance_Text_GoingToLeaveSafariZoneEarly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FuchsiaCity_SafariZone_Entrance_EventScript_ReturnToSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PleaseReturnSafariBalls
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_Exit
	waitmovement 0
	special ExitSafariMode
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ReturnToSafariZone::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_GoodLuck
	closemessage
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ReEnter
	waitmovement 0
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_Movement_Exit::
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_ReEnter::
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_Exit2::
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_ApproachCounter::
	walk_down
	delay_8
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerMid::
	lockall
	setvar VAR_TEMP_2, 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerRight::
	lockall
	setvar VAR_TEMP_2, 1
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EntryTriggerLeft::
	lockall
	setvar VAR_TEMP_2, 2
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FuchsiaCity_SafariZone_Entrance_Text_WelcomeToSafariZone
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PlaySafariGameFor500, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_OkayPleaseComeAgain
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone::
	call FuchsiaCity_SafariZone_Entrance_EventScript_CheckSpaceForMons
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney
	removemoney 500
	updatemoneybox
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ThatllBe500WeOnlyUseSpecialBalls
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FuchsiaCity_SafariZone_Entrance_Text_PlayerReceived30SafariBalls
	waitfanfare
	call EventScript_RestorePrevTextColor
	msgbox FuchsiaCity_SafariZone_Entrance_Text_CallYouOnPAWhenYouRunOut
	closemessage
	hidemoneybox
	call_if_eq VAR_TEMP_2, 0, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneMid
	call_if_eq VAR_TEMP_2, 1, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneRight
	call_if_eq VAR_TEMP_2, 2, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneLeft
	special EnterSafariMode
	@ Kennzeichnet die Kanto-Safari-Zone. Ohne das Flag fuehrt der Ausstieg in
	@ data/scripts/safari_zone.inc in die Johto-Zone.
	setflag FLAG_IN_KANTO_SAFARI_ZONE
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 2
	warp MAP_SAFARI_ZONE_CENTER, 255, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneRight::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneRight
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneMid::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneMid
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneLeft::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneLeft
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_CheckSpaceForMons::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, Common_EventScript_NopReturn
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NopReturn
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_OopsNotEnoughMoney
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack::
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ForceBack
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_ForceBack::
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneMid::
	walk_up
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneRight::
	walk_up
	walk_left
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneLeft::
	walk_up
	walk_right
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_InfoAttendant::
	lock
	faceplayer
	msgbox FuchsiaCity_SafariZone_Entrance_Text_FirstTimeAtSafariZone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_ExplainSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_SorryYoureARegularHere
	release
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ExplainSafariZone::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ExplainSafariZone
	release
	end

FuchsiaCity_SafariZone_Entrance_Text_WelcomeToSafariZone::
#if GERMAN
	.string "Willkommen in der Safari-Zone!$"
#else
	.string "Welcome to the SAFARI ZONE!$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_PlaySafariGameFor500::
#if GERMAN
	.string "Für nur 500¥ darfst du im Park so viele\n"
	.string "Pokémon fangen, wie du möchtest!\p"
	.string "Möchtest du auf die Jagd gehen?$"
#else
	.string "For just ¥500, you can play the\n"
	.string "SAFARI GAME.\p"
	.string "You can roam the wide-open safari\n"
	.string "and catch what you like.\p"
	.string "Would you like to play?$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_ThatllBe500WeOnlyUseSpecialBalls::
#if GERMAN
	.string "Das kostet 500¥!\p"
	.string "Wir verwenden hier spezielle Pokébälle.$"
#else
	.string "That'll be ¥500, please!\p"
	.string "We only use a special kind of \n"
	.string "POKé BALLS here.$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_PlayerReceived30SafariBalls::
#if GERMAN
	.string "{PLAYER} erhält 30 Safaribälle!$"
#else
	.string "{PLAYER} received 30 SAFARI BALLS\n"
	.string "from the attendant.$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_CallYouOnPAWhenYouRunOut::
#if GERMAN
	.string "Wir rufen dich über Lautsprecher aus,\n"
	.string "wenn deine Fangzeit abgelaufen oder\l"
	.string "dein Vorrat an Safaribällen erschöpft\l"
	.string "ist!$"
#else
	.string "We'll call you on the PA when you\n"
	.string "run out of time or SAFARI BALLS.\p"
	.string "Well, I'll wish you the best of\n"
	.string "luck!$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_OkayPleaseComeAgain::
#if GERMAN
	.string "O.K.!\n"
	.string "Besuche uns bald wieder!$"
#else
	.string "Okay.\n"
	.string "Please come again!$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_OopsNotEnoughMoney::
#if GERMAN
	.string "Ups!\n"
	.string "Du hast nicht genug Geld!$"
#else
	.string "Oops!\n"
	.string "Not enough money!$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_GoingToLeaveSafariZoneEarly::
#if GERMAN
	.string "Hast du keine Lust mehr?$"
#else
	.string "Are you going to leave the\n"
	.string "SAFARI ZONE early?$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_PleaseReturnSafariBalls::
#if GERMAN
	.string "Gib bitte die restlichen Safaribälle\n"
	.string "zurück.$"
#else
	.string "Please return any SAFARI BALLS\n"
	.string "you may have left.$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_GoodLuck::
#if GERMAN
	.string "Viel Glück!$"
#else
	.string "Good luck!$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_CatchFairShareComeAgain::
#if GERMAN
	.string "War die Jagd erfolgreich?\n"
	.string "Besuche uns bald wieder!$"
#else
	.string "Did you catch your fair share?\n"
	.string "Come again!$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_FirstTimeAtSafariZone::
#if GERMAN
	.string "Hi!\n"
	.string "Bist du zum ersten Mal hier?$"
#else
	.string "Hi! Is it your first time here at\n"
	.string "the SAFARI ZONE?$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_ExplainSafariZone::
#if GERMAN
	.string "Die Safari-Zone besteht aus vier\n"
	.string "Abschnitten.\p"
	.string "In jedem Abschnitt findet man\n"
	.string "verschiedene Pokémon. Versuche, sie mit\l"
	.string "Safaribällen zu fangen.\p"
	.string "Du kannst auch Köder oder Steine\n"
	.string "werfen.\p"
	.string "Bei einem Köder flieht das Pokémon\n"
	.string "nicht so schnell, ist aber schwieriger\l"
	.string "zu fangen.\p"
	.string "Bei einem Stein flieht das Pokémon eher,\n"
	.string "ist aber einfacher zu fangen.\p"
	.string "Wenn du keine Safaribälle mehr hast\n"
	.string "oder wenn die Zeit abgelaufen ist,\l"
	.string "endet das Spiel!$"
#else
	.string "The SAFARI ZONE actually has\n"
	.string "four zones in it.\p"
	.string "Each zone has different kinds of\n"
	.string "POKéMON, even some rare ones.\p"
	.string "Use the supplied SAFARI BALLS to\n"
	.string "catch them.\p"
	.string "You can also throw BAIT or ROCKS\n"
	.string "besides the SAFARI BALLS.\p"
	.string "If you throw BAIT, the POKéMON\n"
	.string "becomes less likely to flee, but\l"
	.string "harder to catch.\p"
	.string "If you throw ROCKS, the POKéMON\n"
	.string "becomes more likely to flee, but\l"
	.string "easier to catch.\p"
	.string "When you run out of time or SAFARI\n"
	.string "BALLS, it's game over for you!$"
#endif

FuchsiaCity_SafariZone_Entrance_Text_SorryYoureARegularHere::
#if GERMAN
	.string "Heh, du bist ein Stammkunde!$"
#else
	.string "Sorry, you're a regular here!$"
#endif

