BattleFrontier_BattlePikeLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving_hns::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting_hns, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen_hns
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance_hns, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen_hns, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults_hns
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults_hns
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge_hns::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay_hns, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor_hns
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain_hns
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR_HNS, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor_hns::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor_hns
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor_hns:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag_hns
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems_hns
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder_hns
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder_hns::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain_hns::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitstate
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike_hns:
#if GERMAN
	.string "Hier wird das Glück der Trainer\n"
	.string "auf die Probe gestellt…\p"
	.string "Willkommen bei der Kampfipitis…\p"
	.string "Ich begleite dich zur Kampfipitis…$"
#else
	.string "Where the luck of TRAINERS\n"
	.string "is put to the test…\p"
	.string "Welcome to the BATTLE PIKE…\p"
	.string "I am your guide to the BATTLE PIKE…$"
#endif

BattleFrontier_BattlePikeLobby_Text_TakeChallenge_hns:
#if GERMAN
	.string "Möchtest du gerne an der Kampfbahn-\n"
	.string "Herausforderung teilnehmen?$"
#else
	.string "Would you like to take the Battle\n"
	.string "Choice challenge?$"
#endif

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike_hns:
#if GERMAN
	.string "Wir bieten hier eine besondere Heraus-\n"
	.string "forderung an: Die Kampfbahn!\p"
	.string "Die Regeln sind wirklich sehr einfach…\p"
	.string "Wähle einen von drei möglichen Wegen\n"
	.string "und schlag dich zu deinem Ziel durch,\l"
	.string "das am Ende der Kampfipitis liegt…\p"
	.string "Das, was dir auf deinem Weg an\n"
	.string "Herausforderungen begegnet, hängt\l"
	.string "allein von deinem Glück ab…\p"
	.string "Erreichst du dein Ziel, erhältst du\n"
	.string "Gewinnpunkte.\p"
	.string "Wenn du die Herausforderung abbrechen\n"
	.string "möchtest, wende dich bitte an unser \l"
	.string "Personal in den Räumen am Weg.\p"
	.string "Wenn du nicht speicherst, bevor du die\n"
	.string "Herausforderung unterbrichst, wirst du\l"
	.string "disqualifiziert.$"
#else
	.string "Here we conduct an event we call\n"
	.string "the Battle Choice.\p"
	.string "The Battle Choice rules are very\n"
	.string "simple…\p"
	.string "Choose one of three paths and make\n"
	.string "your way to the goal room at the end\l"
	.string "of the BATTLE PIKE. It's that simple.\p"
	.string "However, what happens on the chosen\n"
	.string "path depends entirely on the luck\l"
	.string "of the challenger…\p"
	.string "If you reach the goal, you will be\n"
	.string "rewarded with Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please have a word with\l"
	.string "our staff in the big rooms on the way.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"
#endif

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou_hns:
#if GERMAN
	.string "Wir freuen uns auf deine nächste\n"
	.string "Herausforderung.$"
#else
	.string "We look forward to seeing you\n"
	.string "on another occasion…$"
#endif

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode_hns:
#if GERMAN
	.string "Du kannst zwischen zwei Kategorien\n"
	.string "wählen: Level 50 und Offene Kämpfe.\l"
	.string "Welcher Weg ist richtig für dich?$"
#else
	.string "You have the choice of two courses,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which will you challenge?$"
#endif

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50_hns:
#if GERMAN
	.string "Ich bitte vielmals um Entschuldigung,\n"
	.string "aber…\p"
	.string "Deine Pokémon sind nicht\n"
	.string "teilnahmeberechtigt.\p"
	.string "Du brauchst drei verschiedene\n"
	.string "Pokémon von Level 50 oder weniger.\p"
	.string "Jedes muss außerdem ein anderes Item\n"
	.string "halten.\p"
	.string "Eier{STR_VAR_1}.\p"
	.string "Bitte komm wieder, wenn du so weit\n"
	.string "bist…$"
#else
	.string "I beg your pardon, but…\p"
	.string "You do not have three eligible\n"
	.string "POKéMON for the Battle Choice event.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"
#endif

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd_hns:
#if GERMAN
	.string "Komm wieder, wenn du bereit bist.$"
#else
	.string "Please come see me when\n"
	.string "you are ready…$"
#endif

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen_hns:
#if GERMAN
	.string "Ich bitte vielmals um Entschuldigung,\n"
	.string "aber…\p"
	.string "Deine Pokémon sind nicht\n"
	.string "teilnahmeberechtigt.\p"
	.string "Du brauchst drei verschiedene\n"
	.string "Pokémon.\p"
	.string "Jedes muss außerdem ein anderes Item\n"
	.string "halten.\p"
	.string "Eier{STR_VAR_1}.\p"
	.string "Bitte komm wieder, wenn du so weit\n"
	.string "bist…$"
#else
	.string "I beg your pardon, but…\p"
	.string "You do not have three eligible\n"
	.string "POKéMON for the Battle Choice event.\p"
	.string "You must have three different\n"
	.string "POKéMON to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"
#endif

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons_hns:
#if GERMAN
	.string "Bitte wähle 3 Pokémon, mit denen du dich\n"
	.string "der Herausforderung stellen möchtest.$"
#else
	.string "Please choose the three POKéMON\n"
	.string "you wish to enter in the challenge…$"
#endif

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge_hns:
#if GERMAN
	.string "Bevor du dich der Herausforderung\n"
	.string "stellst, muss ich dein Spiel speichern.\l"
	.string "Bist du damit einverstanden?$"
#else
	.string "Before starting your Battle Choice\n"
	.string "challenge, I must save the game.\l"
	.string "Is that acceptable?$"
#endif

BattleFrontier_BattlePikeLobby_Text_StepThisWay_hns:
#if GERMAN
	.string "Bitte hier entlang.$"
#else
	.string "Please step this way…$"
#endif

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults_hns:
#if GERMAN
	.string "Deine Herausforderung endet hier…\p"
	.string "Dein Erfolg wird gespeichert.\n"
	.string "Bitte warten…$"
#else
	.string "Your challenge has ended…\p"
	.string "I shall record your results.\n"
	.string "Please wait…$"
#endif

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance_hns:
#if GERMAN
	.string "Du hast die Herausforderung\n"
	.string "gemeistert…\p"
	.string "Ich muss schon sagen…\n"
	.string "Du hattest Glück im Übermaß…$"
#else
	.string "You have completed the challenge…\p"
	.string "I must say… You seem to possess luck\n"
	.string "in abundance…$"
#endif

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults_hns:
#if GERMAN
	.string "Dein Erfolg wird gespeichert.\n"
	.string "Bitte warten…$"
#else
	.string "I shall record your results.\n"
	.string "Please wait…$"
#endif

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2_hns:
	.string "In Anerkennung deiner bestandenen\n"
	.string "Kampfbahn-Herausforderung erhältst\l"
	.string "du Gewinnpunkte…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit_hns:
#if GERMAN
	.string "Du scheinst die Höchstzahl an\n"
	.string "Gewinnpunkten erreicht zu haben…\p"
	.string "Bitte tausche einige Gewinnpunkte\n"
	.string "gegen Preise ein und komm wieder…$"
#else
	.string "You appear to have reached the limit\n"
	.string "for Battle Points…\p"
	.string "Please exchange some Battle Points\n"
	.string "for prizes, then return…$"
#endif

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting_hns:
#if GERMAN
	.string "Ich bitte vielmals um Entschuldigung,\n"
	.string "aber…\p"
	.string "Du hast, bevor du die Herausforderung\n"
	.string "abgebrochen hast, nicht gespeichert.\p"
	.string "Daher wirst du für diese Herausforde-\n"
	.string "rung disqualifiziert. Tut mir Leid!$"
#else
	.string "I beg your pardon, but…\p"
	.string "You failed to save before you quit\n"
	.string "your challenge the last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. I am sorry…$"
#endif

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen_hns:
#if GERMAN
	.string "Herzlichen Glückwunsch!\p"
	.string "Du hast dir von der Pfipitistin den Sieg\n"
	.string "geholt und die Herausforderung\l"
	.string "gemeistert!$"
#else
	.string "Congratulations…\p"
	.string "You have snatched victory from the\n"
	.string "PIKE QUEEN and cleared the event…$"
#endif

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints_hns:
#if GERMAN
	.string "In Anerkennung deines unglaublichen\n"
	.string "Glücks erhältst du Gewinnpunkte.$"
#else
	.string "In recognition of your amazing luck,\n"
	.string "we award you these Battle Point(s)…$"
#endif

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal_hns:
#if GERMAN
	.string "Argh! Ich habe meine Chance vertan!\n"
	.string "Ich war nur noch einen Raum vom Ziel\p"
	.string "entfernt! Du musst hier auf Gift, Eis\n"
	.string "und andere gemeine Dinge achten!$"
#else
	.string "Arrgh! I blew my chance!\n"
	.string "I was one room away from the goal!\p"
	.string "In this place, you'd better watch out\n"
	.string "for poison, freezing, and so on.$"
#endif

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer_hns:
#if GERMAN
	.string "Ich habe die Herausforderung bereits\n"
	.string "zum 10. Mal gemeistert, trotzdem\p"
	.string "habe ich noch nie gegen einen\n"
	.string "Trainer gekämpft.$"
#else
	.string "I've completed the challenge 10 times\n"
	.string "now, but I've never had to battle\l"
	.string "a TRAINER once.$"
#endif

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere_hns:
#if GERMAN
	.string "Überleg mal!\p"
	.string "Meinst du nicht auch, dass die\n"
	.string "besonderen Fähigkeiten der Pokémon\l"
	.string "hier sehr nützlich sein können?$"
#else
	.string "Listen! Listen!\p"
	.string "Don't you think that the special\n"
	.string "abilities of POKéMON will be useful\l"
	.string "here?$"
#endif

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose_hns:
#if GERMAN
	.string "Was ist das nur für ein seltsamer Ort?\n"
	.string "Ich werde einfach nicht schlau daraus!\p"
	.string "Ich habe die Herausforderung schon oft\n"
	.string "angenommen, aber egal, welchen Weg ich\l"
	.string "wähle - ich treffe immer nur Trainer.$"
#else
	.string "What is this weird place?\n"
	.string "I can't figure it out at all!\p"
	.string "I've taken the challenge a bunch\n"
	.string "of times, but all I ever do is run into\l"
	.string "TRAINERS whichever path I choose.$"
#endif

BattleFrontier_BattlePikeLobby_Text_RulesAreListed_hns:
#if GERMAN
	.string "Die Regeln der Kampfbahn hängen\n"
	.string "öffentlich aus.$"
#else
	.string "The Battle Choice's rules are listed.$"
#endif

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading_hns:
#if GERMAN
	.string "Wähle bitte ein Themengebiet aus.$"
#else
	.string "Which heading do you want to read?$"
#endif

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules_hns:
#if GERMAN
	.string "Beutel und PokéCom dürfen nicht\n"
	.string "auf die Kampfbahn mitgenommen werden.$"
#else
	.string "The BAG and POKéGEAR may not be used\n"
	.string "during a Battle Choice challenge.$"
#endif

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules_hns:
#if GERMAN
	.string "Auf der Kampfbahn ist jede Beere und\n"
	.string "jedes Kraut nur einmal wirksam.$"
#else
	.string "During a Battle Choice challenge,\n"
	.string "any BERRY or HERB held by POKéMON\l"
	.string "will be effective only once.$"
#endif

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules_hns:
#if GERMAN
	.string "Auf der Kampfbahn kann die Reihenfolge\n"
	.string "der Pokémon nicht verändert werden.\p"
	.string "Du musst die Reihenfolge festlegen,\n"
	.string "bevor du die Herausforderung annimmst.$"
#else
	.string "During a Battle Choice challenge,\n"
	.string "the sequence of POKéMON cannot be\l"
	.string "changed.\p"
	.string "The sequence must be set before\n"
	.string "starting your challenge.$"
#endif

