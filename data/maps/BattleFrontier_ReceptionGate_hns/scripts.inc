BattleFrontier_ReceptionGate_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition_hns
	.byte 0

BattleFrontier_ReceptionGate_OnTransition_hns:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame_hns:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_FRONTIER_RECEPTION_GREETER
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene_hns
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene_hns::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter_hns
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit_hns
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter_hns:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit_hns:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike_hns
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall_hns
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode_hns::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_Level50_hns::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry_hns::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems_hns::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_Symbols_hns::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns:
#if GERMAN
	.string "Bist du zum ersten Mal hier?\n"
	.string "Komm bitte hier entlang.$"
#else
	.string "Is it your first time here?\n"
	.string "Please step this way!$"
#endif

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns:
#if GERMAN
	.string "Der ultimative Ort für ultimative\n"
	.string "Kämpfe! Willkommen in der Kampfzone!$"
#else
	.string "The front lines of POKéMON battling!\n"
	.string "Welcome to the BATTLE FRONTIER!$"
#endif

BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns:
#if GERMAN
	.string "Jeder, der zum ersten Mal hier ist,\n"
	.string "bekommt einen Kampfzonenpass von uns.\p"
	.string "Damit kannst du alle Einrichtungen der\n"
	.string "Kampfzone besuchen.\p"
	.string "Hier, bitte schön!$"
#else
	.string "For a first-time visitor, we issue\n"
	.string "the FRONTIER PASS.\p"
	.string "It's for use at all the facilities\n"
	.string "in the BATTLE FRONTIER.\p"
	.string "Here you are!$"
#endif

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns:
#if GERMAN
	.string "{PLAYER} erhält den Kampfzonenpass.$"
#else
	.string "{PLAYER} obtained\n"
	.string "the FRONTIER PASS.$"
#endif

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns:
#if GERMAN
	.string "{PLAYER} steckt den Trainerpass\n"
	.string "zum Kampfzonenpass.$"
#else
	.string "{PLAYER} placed the TRAINER CARD\n"
	.string "in the FRONTIER PASS.$"
#endif

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns:
#if GERMAN
	.string "Wir hoffen, dir gefällt, was die\n"
	.string "Kampf- Zone zu bieten hat.$"
#else
	.string "We hope you enjoy all that the BATTLE\n"
	.string "FRONTIER has to offer!$"
#endif

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns:
#if GERMAN
	.string "???: Oh, wenn das nicht\n"
	.string "{PLAYER}{KUN} ist!\l"
	.string "Du bist also doch gekommen! Schön!$"
#else
	.string "???: Well, if it isn't {PLAYER}{KUN}!\n"
	.string "You came out here!$"
#endif

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns:
#if GERMAN
	.string "Tutor: Oh! Herr Scott!\n"
	.string "Einen schönen guten Tag, der Herr!$"
#else
	.string "GUIDE: Oh! MR. SCOTT, sir!\n"
	.string "Good day to you, sir!$"
#endif

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns:
#if GERMAN
	.string "Scott: Es ist großartig, dich hier\n"
	.string "zu sehen!\p"
	.string "Ich hoffe, du hast ein bisschen Zeit\n"
	.string "mitgebracht, um dir hier alles\l"
	.string "anzusehen?!?\p"
	.string "Und natürlich hoffe ich auch, dass du\n"
	.string "die Reinheit unserer Kämpfe hier\l"
	.string "genießen wirst!\p"
	.string "Ich wohne hier auf dem Gelände,\n"
	.string "also komm mich doch mal besuchen!$"
#else
	.string "SCOTT: It's great to see you here,\n"
	.string "it really is!\p"
	.string "I hope you'll take your time and\n"
	.string "explore everywhere.\p"
	.string "Naturally, I hope you'll also experience\n"
	.string "the pure essence of battling.\p"
	.string "I also have my quarters here, so feel\n"
	.string "free to visit if you have time.$"
#endif

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns:
#if GERMAN
	.string "Ich begleite dich durch die\n"
	.string "Einrichtungen der Kampfzone.$"
#else
	.string "I'm your guide to the various facilities\n"
	.string "here in the BATTLE FRONTIER.$"
#endif

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns:
#if GERMAN
	.string "Was möchtest du gerne wissen?$"
#else
	.string "Which would you like to learn about?$"
#endif

BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns:
#if GERMAN
	.string "Der riesige Turm ist das Symbol der\n"
	.string "Kampfzone.\p"
	.string "Es gibt vier verschiedene Arten von\n"
	.string "Kampfräumen - für Einzel-, Doppel-,\l"
	.string "Multi- und Link-Multikämpfe.$"
#else
	.string "It is the gigantic tower considered\n"
	.string "to be the BATTLE FRONTIER's symbol.\p"
	.string "There are four kinds of BATTLE ROOMS\n"
	.string "in the tower for SINGLE, DOUBLE, MULTI,\l"
	.string "and LINK MULTI BATTLES.$"
#endif

BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns:
#if GERMAN
	.string "Das Kampfstadion hat die Form eines\n"
	.string "gewaltigen Eis.\p"
	.string "Hier werden so genannte Kampfturniere\n"
	.string "abgehalten.\p"
	.string "Diese können in Einzel- oder Doppel-\n"
	.string "kämpfen ausgefochten werden.$"
#else
	.string "The BATTLE DOME is the large building\n"
	.string "shaped like a huge egg.\p"
	.string "Events named Battle Tourneys are held\n"
	.string "in this facility.\p"
	.string "The Battle Tourneys are offered in\n"
	.string "two courses--for SINGLE and DOUBLE\l"
	.string "BATTLES.$"
#endif

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns:
#if GERMAN
	.string "Der Kampfpalast ist das rote Gebäude,\n"
	.string "ganz rechts in der Kampfzone.\p"
	.string "Hier gibt es zwei Kampfhallen: Eine\n"
	.string "für Einzel- und eine für Doppelkämpfe.$"
#else
	.string "The BATTLE PALACE is the red building\n"
	.string "on the right of the BATTLE FRONTIER.\p"
	.string "There are two kinds of BATTLE HALLS\n"
	.string "for SINGLE and DOUBLE BATTLES.$"
#endif

BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns:
#if GERMAN
	.string "Das einem Dojo nachempfundene Gebäude\n"
	.string "ist der Kampfring, er ist in der Mitte\l"
	.string "rechts zu finden.\p"
	.string "Hier findet das K.O.-Teamturnier\n"
	.string "statt.$"
#else
	.string "The BATTLE ARENA is the dojo-like\n"
	.string "building at the center-right of\l"
	.string "the BATTLE FRONTIER.\p"
	.string "An event called the Set KO Tourney\n"
	.string "takes place at the BATTLE ARENA.$"
#endif

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns:
#if GERMAN
	.string "Uns am nächsten ist das große Gebäude\n"
	.string "der Kampffabrik.\p"
	.string "Hier findet der so genannte Wechsel-\n"
	.string "kampf statt.\p"
	.string "Auch hier kannst du in Einzel- oder\n"
	.string "Doppelkämpfen antreten.$"
#else
	.string "The BATTLE FACTORY is the large\n"
	.string "building that is the closest to us.\p"
	.string "An event called the Battle Swap\n"
	.string "is conducted there.\p"
	.string "The Battle Swap event is offered in\n"
	.string "two courses for SINGLE and DOUBLE\l"
	.string "BATTLES.$"
#endif

BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns:
#if GERMAN
	.string "Das Gebäude, das wie ein Pokémon\n"
	.string "aussieht, ist die Kampfipitis - in der\l"
	.string "Mitte links.\p"
	.string "Hier findet man die Kampfbahnen.$"
#else
	.string "The BATTLE PIKE is the building shaped\n"
	.string "like a POKéMON at the center-left of\l"
	.string "the BATTLE FRONTIER.\p"
	.string "An event called the Battle Choice\n"
	.string "is conducted there.$"
#endif

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns:
#if GERMAN
	.string "Die Kampfpyramide ist eine riesen-\n"
	.string "große Pyramide.\p"
	.string "Hier finden die so genannten Kampf-\n"
	.string "forschungen statt.$"
#else
	.string "The BATTLE PYRAMID is the enormous\n"
	.string "pyramid.\p"
	.string "An event called the Battle Quest\n"
	.string "is conducted there.$"
#endif

BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns:
#if GERMAN
	.string "Die Ergebnishalle befindet sich in der\n"
	.string "Nähe des Duellturms.\p"
	.string "Hier kannst du dir die Rekorde der\n"
	.string "Trainer anschauen, die sich den\l"
	.string "Herausforderungen der Kampfzone\l"
	.string "gestellt haben.$"
#else
	.string "The RANKING HALL is located near\n"
	.string "the BATTLE TOWER.\p"
	.string "There, you may see the most fantastic\n"
	.string "records left by the TRAINERS that\l"
	.string "took on the many challenges of\l"
	.string "the BATTLE FRONTIER.$"
#endif

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns:
#if GERMAN
	.string "Die Tauschecke befindet sich in der\n"
	.string "Nähe des Duellturms.\p"
	.string "Hier kannst du Gewinnpunkte, die du in\n"
	.string "der Kampfzone erhalten hast, gegen\l"
	.string "tolle Preise eintauschen.$"
#else
	.string "The EXCHANGE SERVICE CORNER is near\n"
	.string "the BATTLE TOWER.\p"
	.string "The Battle Points you have earned in\n"
	.string "the BATTLE FRONTIER may be exchanged\l"
	.string "for fabulous prizes there.$"
#endif

BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns:
#if GERMAN
	.string "Ich erkläre dir die Basisregeln, die für\n"
	.string "alle Herausforderungen der Kampfzone\l"
	.string "gelten.$"
#else
	.string "I'm your guide to the basic rules that\n"
	.string "are common to all the challenges\l"
	.string "offered by the facilities in the BATTLE\l"
	.string "FRONTIER.$"
#endif

BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns:
#if GERMAN
	.string "Was möchtest du gerne wissen?$"
#else
	.string "What would you like to learn about?$"
#endif

BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns:
#if GERMAN
	.string "Alle Herausforderungen der Kampfzone\n"
	.string "haben zwei Kategorien: Level 50 und\l"
	.string "Offene Kämpfe.$"
#else
	.string "All the challenges at the BATTLE\n"
	.string "FRONTIER's facilities come in\l"
	.string "two courses--Level 50 and Open Level.$"
#endif

BattleFrontier_ReceptionGate_Text_Level50Info_hns:
#if GERMAN
	.string "Die Level 50-Herausforderungen sind\n"
	.string "offen für Pokémon bis einschließlich\l"
	.string "Level 50.\p"
	.string "Beachte aber, dass kein Trainer, gegen\n"
	.string "den du antrittst, Pokémon besitzt, die\l"
	.string "unter Level 50 sind!\p"
	.string "Diese Kategorie ist die Eingangsstufe\n"
	.string "für die Kämpfe in der Kampfzone.\p"
	.string "Wir hoffen, dass du dich am Anfang\n"
	.string "für diese Stufe entscheiden wirst.$"
#else
	.string "The Level 50 course is open to POKéMON\n"
	.string "up to and including Level 50.\p"
	.string "Please keep in mind, however, that\n"
	.string "no TRAINER you face will have any\l"
	.string "POKéMON below Level 50.\p"
	.string "This course is the entry level for\n"
	.string "battles at the BATTLE FRONTIER.\p"
	.string "To begin, we hope you will challenge\n"
	.string "this course.$"
#endif

BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns:
#if GERMAN
	.string "In den Offenen Kämpfen gibt es kein\n"
	.string "Limit für die Level der Pokémon.\p"
	.string "Der Level deiner Gegner wird dem\n"
	.string "Level deiner Pokémon angepasst.\p"
	.string "Trotzdem wird kein Trainer, gegen den\n"
	.string "du antrittst, ein Pokémon haben, das\l"
	.string "unter Level 60 ist.$"
#else
	.string "The Open Level course places no limit\n"
	.string "on the levels of POKéMON entering\l"
	.string "challenges.\p"
	.string "The levels of your opponents will\n"
	.string "be adjusted to match the levels of\l"
	.string "your POKéMON.\p"
	.string "However, no TRAINER you face will\n"
	.string "have any POKéMON below Level 60.$"
#endif

BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns:
#if GERMAN
	.string "Praktisch gesehen, kann jede Art von\n"
	.string "Pokémon an jeder Herausforderung\l"
	.string "teilnehmen.\p"
	.string "Eier und bestimmte Arten von Pokémon\n"
	.string "sind dennoch nicht zugelassen.\p"
	.string "Die Anzahl der Pokémon, die du mit in den\n"
	.string "Kampf nehmen kannst, variiert von\l"
	.string "Einrichtung zu Einrichtung.\p"
	.string "In allen Einrichtungen gilt aber: Zwei\n"
	.string "oder mehr Pkmn der gleichen Art dürfen\l"
	.string "nicht in einen Kampf gebracht werden.$"
#else
	.string "Virtually any kind of POKéMON may take\n"
	.string "on the challenges at all facilities.\p"
	.string "EGGS and certain kinds of POKéMON,\n"
	.string "however, are not permitted.\p"
	.string "The numbers of POKéMON required for\n"
	.string "challenges will depend on the facility.\p"
	.string "At all facilities, however, two or more\n"
	.string "of the same kind of POKéMON are not\l"
	.string "permitted.$"
#endif

BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns:
#if GERMAN
	.string "Nimmst du eine Herausforderung der\n"
	.string "Kampfzone an, musst du\p"
	.string "darauf achten, dass deine Pokémon\n"
	.string "unterschiedliche Items halten.$"
#else
	.string "When entering a challenge at a BATTLE\n"
	.string "FRONTIER facility, POKéMON may not\l"
	.string "be holding the same kind of item.\p"
	.string "Please make sure that all POKéMON\n"
	.string "entering a challenge are holding\l"
	.string "different items.$"
#endif

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns:
#if GERMAN
	.string "Ich erkläre dir den Kampfzonenpass.$"
#else
	.string "I'm your guide to the FRONTIER PASS.$"
#endif

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns:
#if GERMAN
	.string "Was möchtest du wissen?$"
#else
	.string "Which would you like to learn about?$"
#endif

BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns:
#if GERMAN
	.string "Es gibt sieben Einrichtungen hier in\n"
	.string "der Kampfzone.\p"
	.string "Trainer, die sich durch hervorragendes\n"
	.string "Talent auszeichnen, können als\l"
	.string "Anerkennung Symbole erlangen.\p"
	.string "Um diese Medaillen zu erhalten, müssen\n"
	.string "mehrere Trainer in Folge besiegt werden\l"
	.string "und manchmal auch bestimmte\p"
	.string "Herausforderungen mehrmals bestritten\n"
	.string "werden. Es ist sicherlich nicht einfach,\l"
	.string "hier zu gewinnen. Daher: Viel Glück!$"
#else
	.string "There are seven facilities at\n"
	.string "the BATTLE FRONTIER.\p"
	.string "TRAINERS who gain recognition for\n"
	.string "their abilities may be rewarded with\l"
	.string "symbols from each of the facilities.\p"
	.string "To earn a symbol, TRAINERS may need\n"
	.string "to defeat other TRAINERS in a row,\l"
	.string "and may need to win events repeatedly.\p"
	.string "It's certainly not easy to win symbols.\n"
	.string "I wish you the best of luck!$"
#endif

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns:
#if GERMAN
	.string "Du hast die Möglichkeit, einen Kampf in\n"
	.string "deinen Kampfzonenpass aufnehmen zu\l"
	.string "lassen.\p"
	.string "Vielleicht möchtest du einen Kampf, den\n"
	.string "du gegen oder mit Freunden geführt\l"
	.string "hast, dort eintragen lassen.\p"
	.string "Oder du lässt Kämpfe in der Kampfzone\n"
	.string "eintragen. Kämpfe der Kampfipitis und\l"
	.string "der Kampfpyramide werden nicht\l"
	.string "eingetragen.\p"
	.string "Am Ende eines Kampfes kannst du dich\n"
	.string "entscheiden, ob du ihn eintragen lassen\l"
	.string "möchtest oder nicht.$"
#else
	.string "It is possible to record one battle\n"
	.string "on your FRONTIER PASS.\p"
	.string "You may record a battle you had with\n"
	.string "a friend or friends.\p"
	.string "Or you may record a battle conducted\n"
	.string "at the BATTLE FRONTIER excluding\l"
	.string "matches at the BATTLE PIKE or\l"
	.string "the BATTLE PYRAMID.\p"
	.string "You may choose to record your match\n"
	.string "at the end of a battle.$"
#endif

BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns:
#if GERMAN
	.string "Trainer, die herausragend in der\n"
	.string "Kampfzone gekämpft haben, erhalten so\l"
	.string "genannte Gewinnpunkte.\p"
	.string "Diese kannst du nach Belieben in der\n"
	.string "Tauschecke gegen Preise eintauschen.$"
#else
	.string "Battle Points are rewards given to\n"
	.string "TRAINERS who battled outstandingly\l"
	.string "at the BATTLE FRONTIER.\p"
	.string "You may trade in your Battle Points\n"
	.string "for prizes at the EXCHANGE SERVICE\l"
	.string "CORNER.$"
#endif

