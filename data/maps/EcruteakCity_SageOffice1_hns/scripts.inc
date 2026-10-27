EcruteakCity_SageOffice1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
#if GERMAN
	.string "Die Glocke aus Zinn klingt\n"
	.string "hell und rein\p"
	.string "für alle, die im Schutz\n"
	.string "des Turmes sein.$"
#else
	.string "The bell of tin rings clearly for\n"
	.string "those under the tower's wing.$"
#endif

EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	@ The Tidal Bell (Lugia path) opens the tower too, for Suicune on 1F. See docs/origin_jade/DECISIONS.md, D-027.
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageTidalBell
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAGEOFFICE_SAGE
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageTidalBell::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAGEOFFICE_SAGE
	msgbox EcruteakTinTowerEntrance_Text_SageHearsTidalBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	@ Ho-Oh waits on the roof (Ho-Oh path, after the theater).
	goto_if_eq VAR_COMPLETED_HO_OH, 2, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
#if GERMAN
	.string "Der Glockenturm ist nur Würdigen\n"
	.string "zugänglich.\p"
	.string "Es tut mir leid, aber du musst\n"
	.string "wieder gehen.$"
#else
	.string "TIN TOWER is off limits to the\n"
	.string "unworthy. Sorry but you'll have\l"
	.string "to leave.$"
#endif

EcruteakTinTowerEntrance_Text_SageWithBadge:
#if GERMAN
	.string "Wenn du nicht im Besitz des Ordens von\n"
	.string "Teak City bist, darfst du den Zinnturm\l"
	.string "nicht betreten.\p"
	.string "Ah! Das ist der Orden von Teak City! Du\n"
	.string "darfst passieren.$"
#else
	.string "TIN TOWER is off limits to anyone\n"
	.string "without ECRUTEAK GYM's BADGE.\p"
	.string "Ah!\p"
	.string "ECRUTEAK's GYM BADGE! Please, go\n"
	.string "right through.$"
#endif

EcruteakTinTowerEntrance_Text_SageNoClearBell:
#if GERMAN
	.string "Ein denkwürdiger Augenblick.\p"
	.string "Entschuldigung, aber ich muss dich\n"
	.string "bitten zu gehen.\p"
	.string "…Was lindert Seelenschmerzen…\p"
	.string "Das Trio der Weisen sagt stets\p"
	.string "Dinge, die sehr schwierig zu verstehen\n"
	.string "sind…$"
#else
	.string "A momentous event has occurred.\p"
	.string "I beg your pardon, but I must ask\n"
	.string "you to leave.\p"
	.string "…What soothes the soul…\p"
	.string "The WISE TRIO say things that are\n"
	.string "so very difficult to understand…$"
#endif

EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
#if GERMAN
	.string "Ein denkwürdiger Augenblick.\p"
	.string "Entschuldigung, aber ich muss dich\n"
	.string "bitten zu gehen.\p"
	.string ".........$"
#else
	.string "A momentous event has occurred.\p"
	.string "I beg your pardon, but I must ask\n"
	.string "you to leave.\p"
	.string "..............................$"
#endif
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
#if GERMAN
	.string "Ah!\p"
	.string "Das Läuten der Klarglocke!\p"
	.string "Es… ist erhaben!\p"
	.string "Das schönste Läuten,\n"
	.string "das ich je hörte!\p"
	.string "Dieser Ton sagt alles über\n"
	.string "die Seele des Trägers aus.\p"
	.string "Du…\p"
	.string "Du könntest es durch den\n"
	.string "Glockenturm schaffen.\p"
	.string "Schreite voran.$"
#else
	.string "Ah!\p"
	.string "The CLEAR BELL's chime!\p"
	.string "It… It's sublime!\p"
	.string "I've never heard so beautiful\n"
	.string "a sound before!\p"
	.string "That bell's chime is indicative\n"
	.string "of the bearer's soul.\p"
	.string "You…\p"
	.string "You may be able to make it\n"
	.string "through the TIN TOWER.\p"
	.string "Please, do go on.$"
#endif

EcruteakTinTowerEntrance_Text_SageHearsTidalBell2:
#if GERMAN
	.string "Ah!\p"
	.string "Das Läuten der Gischtglocke!\p"
	.string "Es… ist erhaben!\p"
	.string "Das schönste Läuten,\n"
	.string "das ich je hörte!\p"
	.string "Dieser Ton sagt alles über\n"
	.string "die Seele des Trägers aus.\p"
	.string "Du…\p"
	.string "Du könntest es durch den\n"
	.string "Glockenturm schaffen.\p"
	.string "Schreite voran.$"
#else
	.string "Ah!\p"
	.string "The TIDAL BELL's chime!\p"
	.string "It… It's sublime!\p"
	.string "I've never heard so beautiful\n"
	.string "a sound before!\p"
	.string "That bell's chime is indicative\n"
	.string "of the bearer's soul.\p"
	.string "You…\p"
	.string "You may be able to make it\n"
	.string "through the TIN TOWER.\p"
	.string "Please, do go on.$"
#endif

EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
#if GERMAN
	.string "Schreite voran…$"
#else
	.string "Please, do go on.$"
#endif

EcruteakTinTowerEntrance_Text_SageDone:
#if GERMAN
	.string "Der Klang dieser Glocke zeigt die\n"
	.string "Reinheit der Seele ihres Trägers.\p"
	.string "Du… bist wahrlich würdig.$"
#else
	.string "That bell's chime is indicative of\n"
	.string "the bearer's soul.\p"
	.string "You…\n"
	.string "Truly are worthy.$"
#endif

EcruteakTinTowerEntrance_Text_WanderingSage:
#if GERMAN
	.string "Der Glockenturm da vorne ist ein\n"
	.string "neunstöckiger Turm von göttlicher\l"
	.string "Schönheit.\p"
	.string "Er beruhigt die Seelen derer, die\n"
	.string "ihn betrachten.$"
#else
	.string "The TIN TOWER ahead is a nine-\n"
	.string "tier tower of divine beauty.\p"
	.string "It soothes the soul of all who\n"
	.string "see it.$"
#endif

EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
#if GERMAN
	.string "Der Glockenturm bebt! Ein Pokémon\n"
	.string "muss auf der Spitze gelandet sein!$"
#else
	.string "The TIN TOWER shook! A POKéMON must\n"
	.string "have returned to the top!$"
#endif

EcruteakTinTowerEntrance_Text_Gramps:
#if GERMAN
	.string "Zwei Türme… Zwei Pokémon…\p"
	.string "Aber als einer niederbrannte, flogen\n"
	.string "beide Pokémon fort und kamen nie wieder\l"
	.string "zurück.$"
#else
	.string "Two towers… Two POKéMON…\p"
	.string "But when one burned down, both\n"
	.string "POKéMON flew away, never to return.$"
#endif
