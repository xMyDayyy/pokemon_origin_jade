BattleFrontier_RankingHall_hns_MapScripts::
	.byte 0

BattleFrontier_RankingHall_EventScript_TowerSinglesRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_SINGLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerDoublesRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_DOUBLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerMultisRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_MULTIS
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerLinkRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_LINK
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_ArenaRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_ARENA
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PalaceRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PALACE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_FactoryRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_FACTORY
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_DomeRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_DOME
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PikeRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PIKE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PyramidRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PYRAMID
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_ShowRecords_hns::
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_Attendant_hns::
	msgbox BattleFrontier_RankingHall_Text_ExplainRankingHall_hns, MSGBOX_NPC
	end

BattleFrontier_RankingHall_EventScript_DomePikeFactoryRecordsSign_hns::
	msgbox BattleFrontier_RankingHall_Text_DomePikeFactoryRecords_hns, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_PalaceArenaPyramidRecordsSIgn_hns::
	msgbox BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords_hns, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy_hns::
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_IsYourNameOnThisList_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_RankingHall_EventScript_NinjaBoy_hnsNameOnList_hns
	msgbox BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy_hnsNameOnList_hns::
	msgbox BattleFrontier_RankingHall_Text_WowThatsSuper_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_Boy_hns::
	msgbox BattleFrontier_RankingHall_Text_MyNamesNotUpThere_hns, MSGBOX_NPC
	end

BattleFrontier_RankingHall_Text_ExplainRankingHall_hns:
#if GERMAN
	.string "Dies ist die Ergebnishalle.\n"
	.string "Hier sind die Namen der Trainer\p"
	.string "verewigt, die sich durch ihre Ergebnisse\n"
	.string "bei den Kampfzonen-Kämpfen\l"
	.string "unsterblich gemacht haben.$"
#else
	.string "This is the RANKING HALL.\p"
	.string "This is where we recognize the immortal\n"
	.string "TRAINERS who left great records in\l"
	.string "BATTLE FRONTIER events.$"
#endif

BattleFrontier_RankingHall_Text_DomePikeFactoryRecords_hns:
#if GERMAN
	.string "Ergebnisse: Kampfstadion, Kampfipitis\n"
	.string "und Kampffabrik$"
#else
	.string "BATTLE DOME, BATTLE PIKE,\n"
	.string "and BATTLE FACTORY Records$"
#endif

BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords_hns:
#if GERMAN
	.string "Ergebnisse: Kampfpalast, Kampf-\n"
	.string "ring und Kampfpyramide$"
#else
	.string "BATTLE PALACE, BATTLE ARENA,\n"
	.string "and BATTLE PYRAMID Records$"
#endif

BattleFrontier_RankingHall_Text_IsYourNameOnThisList_hns:
#if GERMAN
	.string "Hallo. Steht dein Name auch auf der\n"
	.string "Liste?$"
#else
	.string "Hi, is your name on this list?$"
#endif

BattleFrontier_RankingHall_Text_WowThatsSuper_hns:
#if GERMAN
	.string "Wow, das ist ja super!!!\n"
	.string "Ich werde mich auch anstrengen!$"
#else
	.string "Wow, that's super!\n"
	.string "I'll have to try harder, too!$"
#endif

BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName_hns:
#if GERMAN
	.string "Wirklich?\n"
	.string "Wenn du die Namen deiner Freunde hier\p"
	.string "siehst, strengst du dich bestimmt noch\n"
	.string "mehr an.$"
#else
	.string "Oh, is that right?\p"
	.string "If you saw your friend's name up here,\n"
	.string "I bet it would make you work harder!$"
#endif

BattleFrontier_RankingHall_Text_MyNamesNotUpThere_hns:
#if GERMAN
	.string "Hmm…\n"
	.string "Ich kann meinen Namen nicht finden…\p"
	.string "Kein Wunder! Ich habe ja auch noch nie\n"
	.string "an Kämpfen teilgenommen…$"
#else
	.string "Hmm…\n"
	.string "My name's not up there…\p"
	.string "Well, it's only natural since I haven't\n"
	.string "taken any challenges yet.$"
#endif

