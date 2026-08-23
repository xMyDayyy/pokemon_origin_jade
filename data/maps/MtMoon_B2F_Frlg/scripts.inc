MtMoon_B2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	.byte 0

MtMoon_B2F_OnTransition::
	@ Kanto-Merge: Jedes Fossil haengt an seinem eigenen Flag, damit man
	@ beide mitnehmen kann. Vorher liess FLAG_GOT_FOSSIL_FROM_MT_MOON nach
	@ der ersten Wahl beide verschwinden.
	call_if_unset FLAG_GOT_DOME_FOSSIL, MtMoon_B2F_EventScript_ShowDomeFossil
	call_if_unset FLAG_GOT_HELIX_FOSSIL, MtMoon_B2F_EventScript_ShowHelixFossil
	end

MtMoon_B2F_EventScript_ShowDomeFossil::
	clearflag FLAG_HIDE_DOME_FOSSIL
	return

MtMoon_B2F_EventScript_ShowHelixFossil::
	clearflag FLAG_HIDE_HELIX_FOSSIL
	return

MtMoon_B2F_EventScript_MiguelTrigger::
	lockall
	applymovement LOCALID_MIGUEL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call MtMoon_B2F_EventScript_BattleMiguel
	releaseall
	end

MtMoon_B2F_EventScript_Miguel::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_DOME_FOSSIL, MtMoon_B2F_EventScript_MiguelGoPickFossil2
	goto_if_set FLAG_GOT_HELIX_FOSSIL, MtMoon_B2F_EventScript_MiguelFossilPicked
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
	call MtMoon_B2F_EventScript_BattleMiguel
	release
	end

MtMoon_B2F_EventScript_BattleMiguel::
	textcolor NPC_TEXT_COLOR_MALE
	message MtMoon_B2F_Text_MiguelIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_MIGUEL
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelDefeat
	setvar VAR_MAP_SCENE_MT_MOON_B2F, 1
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	return

MtMoon_B2F_EventScript_MiguelFossilPicked::
	msgbox MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils
	release
	end

MtMoon_B2F_EventScript_MiguelGoPickFossil2::
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
	call MtMoon_B2F_EventScript_BattleMiguel
	release
	end

MtMoon_B2F_EventScript_MiguelGoPickFossil::
	msgbox MtMoon_B2F_Text_MiguelTakeThemBoth
	release
	end

MtMoon_B2F_EventScript_DomeFossil::
	lock
	faceplayer
	@ Kanto-Merge: keine Wahl mehr noetig, beide Fossilien sind frei.
	removeobject LOCALID_DOME_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedDomeFossil, ITEM_DOME_FOSSIL, 1, MUS_RG_OBTAIN_KEY_ITEM
	closemessage
	@ Kanto-Merge: Beide Fossilien bleiben liegen. Fuer 'alle 185 fangbar'
	@ braucht es beide Entwicklungslinien - der Rivale nimmt das andere
	@ deshalb nicht mehr mit.
	setflag FLAG_GOT_DOME_FOSSIL
	release
	end

MtMoon_B2F_Movement_MiguelToHelixFossil::
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_HelixFossil::
	lock
	faceplayer
	@ Kanto-Merge: keine Wahl mehr noetig, beide Fossilien sind frei.
	removeobject LOCALID_HELIX_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedHelixFossil, ITEM_HELIX_FOSSIL, 1, MUS_RG_OBTAIN_KEY_ITEM
	closemessage
	setflag FLAG_GOT_HELIX_FOSSIL
	release
	end

MtMoon_B2F_EventScript_DontTakeFossil::
	release
	end

MtMoon_B2F_Movement_MiguelToDomeFossil::
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_MiguelIntro::
#if GERMAN
	.string "Stopp! Hände weg!\p"
	.string "Wer zuerst kommt, mahlt zuerst!\n"
	.string "Die Fossilien gehören mir!$"
#else
	.string "Hey, stop!\p"
	.string "I found these fossils!\n"
	.string "They're both mine!$"
#endif

MtMoon_B2F_Text_MiguelDefeat::
#if GERMAN
	.string "Na gut!\n"
	.string "Ich gebe dir eines ab!$"
#else
	.string "Okay!\n"
	.string "I'll share!$"
#endif

MtMoon_B2F_Text_WellEachTakeAFossil::
#if GERMAN
	.string "O.K., du kannst sie haben.\p"
	.string "Nimm ruhig beide mit!$"
#else
	.string "We'll each take a fossil!\n"
	.string "No being greedy!$"
#endif

@ Kanto-Merge: seit beide Fossilien liegenbleiben ungenutzt.
MtMoon_B2F_Text_ThenThisFossilIsMine::
#if GERMAN
	.string "O.K., dann gehört das hier mir!$"
#else
	.string "All right.\n"
	.string "Then this fossil is mine!$"
#endif

MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils::
#if GERMAN
	.string "Auf der fernen Zinnoberinsel\n"
	.string "gibt es ein Pokémon-Labor.\p"
	.string "Dort versucht man, aus fossilem\n"
	.string "Gen-Material Pokémon zu erschaffen.$"
#else
	.string "Far away, on CINNABAR ISLAND,\n"
	.string "there's a POKéMON LAB.\p"
	.string "They do research on regenerating\n"
	.string "fossils.$"
#endif

MtMoon_B2F_Text_Grunt1Intro::
#if GERMAN
	.string "Wir vom Team Rocket werden die\n"
	.string "Fossilien finden, die Pokémon wieder\l"
	.string "beleben und teuer verkaufen!$"
#else
	.string "We, TEAM ROCKET, shall find the\n"
	.string "fossils!\p"
	.string "Reviving POKéMON from them will\n"
	.string "earn us huge riches!$"
#endif

MtMoon_B2F_Text_Grunt1Defeat::
#if GERMAN
	.string "Grr!\n"
	.string "Das gibt es nicht!$"
#else
	.string "Urgh!\n"
	.string "Now I'm mad!$"
#endif

MtMoon_B2F_Text_Grunt1PostBattle::
#if GERMAN
	.string "Du machst mich irre! Das Team\n"
	.string "Rocket wird dich im Auge behalten!$"
#else
	.string "You made me mad!\n"
	.string "TEAM ROCKET will blacklist you!$"
#endif

MtMoon_B2F_Text_Grunt2Intro::
#if GERMAN
	.string "Wir sind das Team Rocket, die\n"
	.string "Pokémon-Räuber!$"
#else
	.string "We, TEAM ROCKET, are POKéMON\n"
	.string "gangsters!\l"
	.string "We strike fear with our strength!$"
#endif

MtMoon_B2F_Text_Grunt2Defeat::
#if GERMAN
	.string "Nein!\n"
	.string "Ich hab es vermasselt!$"
#else
	.string "I blew it!$"
#endif

MtMoon_B2F_Text_Grunt2PostBattle::
#if GERMAN
	.string "Verdammt! Wie erkläre ich das\n"
	.string "meinen Partnern?$"
#else
	.string "Darn it all!\n"
	.string "My associates won't stand for this!$"
#endif

MtMoon_B2F_Text_Grunt3Intro::
#if GERMAN
	.string "Wir drehen hier ein dickes Ding!\n"
	.string "Mach dich vom Acker!$"
#else
	.string "We're pulling a big job here!\n"
	.string "Get lost, kid!$"
#endif

MtMoon_B2F_Text_Grunt3Defeat::
#if GERMAN
	.string "Du bist 'ne harte Nuss, Kiddie!$"
#else
	.string "So, you are good…$"
#endif

MtMoon_B2F_Text_Grunt3PostBattle::
#if GERMAN
	.string "Wenn du ein Fossil hast, gib es her\n"
	.string "und verschwinde!$"
#else
	.string "If you find a fossil, give it to me\n"
	.string "and scram!$"
#endif

MtMoon_B2F_Text_Grunt4Intro::
#if GERMAN
	.string "Geh Erwachsenen nicht auf den\n"
	.string "Wecker, du Nervensäge!$"
#else
	.string "Little kids shouldn't be messing\n"
	.string "around with grown-ups!\p"
	.string "It could be bad news!$"
#endif

MtMoon_B2F_Text_Grunt4Defeat::
#if GERMAN
	.string "Ich bin sauer!$"
#else
	.string "I'm steamed!$"
#endif

MtMoon_B2F_Text_Grunt4PostBattle::
#if GERMAN
	.string "Schon lange vor den Menschen\n"
	.string "haben Pokémon hier gelebt...$"
#else
	.string "POKéMON lived here long before\n"
	.string "people came.$"
#endif

MtMoon_B2F_Text_YouWantDomeFossil::
#if GERMAN
	.string "Möchtest du das Domfossil?$"
#else
	.string "Do you want the DOME FOSSIL?$"
#endif

MtMoon_B2F_Text_YouWantHelixFossil::
#if GERMAN
	.string "Möchtest du das Helixfossil?$"
#else
	.string "Do you want the HELIX FOSSIL?$"
#endif

MtMoon_B2F_Text_ObtainedHelixFossil::
#if GERMAN
	.string "Helixfossil erhalten!$"
#else
	.string "Obtained the HELIX FOSSIL!$"
#endif

MtMoon_B2F_Text_ObtainedDomeFossil::
#if GERMAN
	.string "Domfossil erhalten!$"
#else
	.string "Obtained the DOME FOSSIL!$"
#endif

@ Kanto-Merge: Beim erneuten Ansprechen, solange noch ein Fossil liegt.
MtMoon_B2F_Text_MiguelTakeThemBoth::
#if GERMAN
	.string "Wie gesagt, du kannst sie nehmen.\p"
	.string "Ich wollte die eh nicht haben...$"
#else
	.string "Like I said, you can have them.\p"
	.string "I didn't want them anyway...$"
#endif
