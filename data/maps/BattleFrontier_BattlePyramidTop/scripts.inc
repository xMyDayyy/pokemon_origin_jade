BattleFrontier_BattlePyramidTop_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidTop_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidTop_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidTop_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidTop_OnWarp
	.byte 0

BattleFrontier_BattlePyramidTop_OnTransition:
	pyramid_updatelight 200, PYRAMID_LIGHT_SET_RADIUS
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto_if_ne VAR_TEMP_C, 0, BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects
	setobjectxyperm LOCALID_BRANDON, 0, 0
BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects::
	end

BattleFrontier_BattlePyramidTop_OnResume:
	frontier_getbrainstatus
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus
	call BattleFrontier_EventScript_SetBrainObjectGfx
BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus::
	copyvar VAR_TEMP_C, VAR_RESULT
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePyramidTop_OnFrame:
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidTop_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID_TOP, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_Attendant::
	lock
	faceplayer
	goto_if_ne VAR_TEMP_D, 0, BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady
	goto_if_ne VAR_TEMP_C, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside
	msgbox BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop
	waitmovement 0
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath
	waitmovement 0
	message BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	closemessage
BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady::
	msgbox BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside::
	msgbox BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere, MSGBOX_DEFAULT
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
	setvar VAR_TEMP_D, 1
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon::
	lockall
	switch VAR_TEMP_C
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver::
	msgbox BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon

BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold::
	msgbox BattleFrontier_BattlePyramidTop_Text_EverythingYouHave, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_FarewellForNow, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon

BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle::
	closemessage
	dofacilitytrainerbattle FACILITY_BATTLE_PYRAMID
	waitstate
	return

BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside:
	walk_right
	walk_in_place_faster_left
	step_end

BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath:
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer:
	walk_fast_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_CameraPanUp:
	walk_slow_up
	walk_slow_up
	delay_16
	step_end

BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo:
#if GERMAN
	.string "Es ist wirklich eine Freude, dich hier zu\n"
	.string "sehen! Du hast es bis zum Gipfel der\l"
	.string "Kampfpyramide geschafft!\p"
	.string "Über uns befindet sich nur noch die\n"
	.string "Aussichtsplattform.\p"
	.string "Ein Platz, der nur denen offen steht,\n"
	.string "die die Pyramide erobert haben.\p"
	.string "Nun, dann darf ich bitten?\n"
	.string "Auf geht’s!$"
#else
	.string "It is a delight to see you here!\n"
	.string "You have reached the summit of\l"
	.string "the BATTLE PYRAMID!\p"
	.string "Above here is the PYRAMID's\n"
	.string "lookout point.\p"
	.string "It is a place open only to those\n"
	.string "who have conquered the PYRAMID.\p"
	.string "Now, please!\n"
	.string "Up you go!$"
#endif

BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid:
#if GERMAN
	.string "Der neue Eroberer der Pyramide! Sein\n"
	.string "Name soll in aller Munde sein!\l"
	.string "{PLAYER}!!!$"
#else
	.string "The PYRAMID's new conqueror!\n"
	.string "Let the name {PLAYER} be known!$"
#endif

BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere:
#if GERMAN
	.string "Es ist wahrlich eine Freude, dich zu\n"
	.string "sehen!\p"
	.string "Aber leider bist du nur Zweiter, denn\n"
	.string "ein anderer war schneller als du!\p"
	.string "Unser Chef hat die Pyramide bereits\n"
	.string "erobert!\p"
	.string "Wie dem auch sei, junger Forschergeist…\n"
	.string "Du bist ein Trainer!\p"
	.string "Behaupte dich mit aller Kraft und hol\n"
	.string "dir den Ruhm! Besiege unseren Chef!\p"
	.string "Bitte! Du bist so weit gegangen. Mach\n"
	.string "auch noch diesen einen Schritt!$"
#else
	.string "It is a delight to see you here!\p"
	.string "Unfortunately, you were second by\n"
	.string "a mere fraction of time!\p"
	.string "Our chief has already conquered\n"
	.string "the PYRAMID ahead of you.\p"
	.string "However, my young explorer…\n"
	.string "You are a TRAINER!\p"
	.string "Assert your power and take the glory\n"
	.string "of the pinnacle from our chief!\p"
	.string "Now, please! When you are ready,\n"
	.string "take one more step of courage!$"
#endif

BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure:
#if GERMAN
	.string "Junger Forschergeist…\p"
	.string "Meinst du nicht auch, dass Forschungs-\n"
	.string "reisen die Krönung der Abenteuer sind?\p"
	.string "Dein Verstand!\p"
	.string "Deine Stärke!\p"
	.string "Deine Pokémon!\p"
	.string "Aber vor allem dein Mut, dich durch\n"
	.string "unbekannte Welten zu bewegen…$"
#else
	.string "Young adventurer…\p"
	.string "Wouldn't you agree that explorations\n"
	.string "are the grandest of adventures?\p"
	.string "Your own wits!\p"
	.string "Your own strength!\p"
	.string "Your own POKéMON!\p"
	.string "And, above all, only your own courage\n"
	.string "to lead you through unknown worlds…$"
#endif

BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon:
#if GERMAN
	.string "Oh ja, das Leben ist einfach großartig!\n"
	.string "Ja, ja! Bitte?!?\p"
	.string "Ich heiße Brian!\p"
	.string "Ich bin der Pyrakönig, was bedeutet,\n"
	.string "dass ich die Verantwortung hier trage!\p"
	.string "Die meisten nennen mich einfach Chef!\p"
	.string "Du besitzt ein starkes Selbstver-\n"
	.string "trauen, da du es bis hierher geschafft\p"
	.string "hast. Hahaha!\n"
	.string "Das wird ein Riesenspaß!$"
#else
	.string "Aah, yes, indeed this life is grand!\n"
	.string "Grand, it is! Eh?\p"
	.string "I'm BRANDON!\p"
	.string "I'm the PYRAMID KING, which means\n"
	.string "I'm in charge here.\p"
	.string "Most people call me the chief!\p"
	.string "You coming here means you have\n"
	.string "that much confidence in yourself,\l"
	.string "am I right?\p"
	.string "Hahahah!\n"
	.string "This should be exciting!$"
#endif

BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle:
#if GERMAN
	.string "Also dann!\n"
	.string "Beweis deinen Mut und kämpfe!$"
#else
	.string "Now, then!\n"
	.string "Bring your courage to our battle!$"
#endif

BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease:
#if GERMAN
	.string "Brian: Hahaha! Das war einfach\n"
	.string "großartig! Großartig, jawohl!\p"
	.string "Gut gemacht! Du hast dir meine\n"
	.string "Anerkennung redlich verdient! Deinen\l"
	.string "Kampfzonenpass, bitte!$"
#else
	.string "BRANDON: Hahahah! Grand it was!\n"
	.string "Grand, yes, indeed!\p"
	.string "Well done! You've earned recognition!\n"
	.string "Your FRONTIER PASS, please!$"
#endif

BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol:
#if GERMAN
	.string "Das Bravursymbol wurde dem\n"
	.string "Kampfzonenpass hinzugefügt!$"
#else
	.string "The Brave Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"
#endif

BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting:
#if GERMAN
	.string "Junger Forschergeist! Ich freue mich\n"
	.string "schon auf unser nächstes Treffen!$"
#else
	.string "Young explorer!\n"
	.string "I look forward to our next meeting!$"
#endif

BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned:
#if GERMAN
	.string "Brian: … Endlich sehen wir uns\n"
	.string "wieder, junger Forschergeist!\p"
	.string "Deine Liebe für Abenteuer scheint aus\n"
	.string "tiefstem Herzen zu kommen…\p"
	.string "Ja… Als ich in deinem Alter war, war\n"
	.string "ich genauso…\p"
	.string "… … … …\p"
	.string "Leidenschaftlich!\p"
	.string "Gefährlich!\p"
	.string "Verzweifelt!\p"
	.string "Endlich ist es wieder Zeit für\n"
	.string "todesverachtende, lebensbejahende\l"
	.string "Abenteuer…$"
#else
	.string "BRANDON: …You've finally returned,\n"
	.string "young explorer…\p"
	.string "Your love of adventure seems to come\n"
	.string "deep from within your heart…\p"
	.string "Yes… You are exactly as I was in\n"
	.string "my own youth…\p"
	.string "… … …Ah…\p"
	.string "The passionate!\p"
	.string "The dangerous!\p"
	.string "The desperate!\p"
	.string "Those days of death-defying,\n"
	.string "life-affirming adventures are back…$"
#endif

BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter:
#if GERMAN
	.string "Also dann!\p"
	.string "Mein Mut übersteigt diesmal alle\n"
	.string "Grenzen!$"
#else
	.string "Now, then!\p"
	.string "I sense my own courage is off\n"
	.string "the meter!$"
#endif

BattleFrontier_BattlePyramidTop_Text_EverythingYouHave:
#if GERMAN
	.string "Alles, was du hast…\n"
	.string "würde ich auch gerne besitzen…$"
#else
	.string "Everything you have!\n"
	.string "I'm braced for it all!$"
#endif

BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis:
#if GERMAN
	.string "Brian: Hahahaha!\n"
	.string "Bemerkenswert!\l"
	.string "Wirklich ganz großartig!\p"
	.string "Junger Forschergeist!\p"
	.string "Du hast es mir durch und durch gezeigt!\n"
	.string "Bitte! Ich möchte dir dies geben!$"
#else
	.string "BRANDON: Hahahah!\n"
	.string "Remarkable!\l"
	.string "Yes, it's grand, indeed!\p"
	.string "Young explorer!\p"
	.string "You've bested me through and through!\n"
	.string "Here! I want you to have this!$"
#endif

BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine:
#if GERMAN
	.string "Das Bravursymbol erscheint in einem\n"
	.string "goldenen Glanz!$"
#else
	.string "The Brave Symbol took on\n"
	.string "a golden shine!$"
#endif

BattleFrontier_BattlePyramidTop_Text_FarewellForNow:
#if GERMAN
	.string "Oh, ja! Scheinbar muss auch ich noch\n"
	.string "sehr viel lernen!\p"
	.string "Ich hoffe, unsere Wege kreuzen sich\n"
	.string "bald wieder! Bis dahin Leb wohl, junger\l"
	.string "Forschergeist!$"
#else
	.string "Ah, yes! It just goes to show that\n"
	.string "I have much to learn still!\p"
	.string "May our paths cross again!\n"
	.string "Farewell for now, young explorer!$"
#endif

BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady:
#if GERMAN
	.string "Wenn du bereit bist, dann nimm deinen\n"
	.string "Mut zusammen und tritt vor.$"
#else
	.string "Now, when you are ready, take courage\n"
	.string "and step forward.$"
#endif

