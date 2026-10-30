AquaHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	.byte 0

AquaHideout_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_TryRemoveElectrode
	end

AquaHideout_B1F_EventScript_TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AquaHideout_B1F_OnTransition:
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode1
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode2
	end

AquaHideout_B1F_EventScript_ShowElectrode1::
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
	return

AquaHideout_B1F_EventScript_ShowElectrode2::
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
	return

AquaHideout_B1F_EventScript_Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 85
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode1
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode1::
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 85
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode2
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode2::
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, AquaHideout_B1F_Text_Grunt2Intro, AquaHideout_B1F_Text_Grunt2Defeat, AquaHideout_B1F_EventScript_Grunt2Defeated
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt2Defeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, AquaHideout_B1F_EventScript_Grunt3Defeated
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt3Defeated::
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_5, AquaHideout_B1F_Text_Grunt5Intro, AquaHideout_B1F_Text_Grunt5Defeat
	msgbox AquaHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_7, AquaHideout_B1F_Text_Grunt7Intro, AquaHideout_B1F_Text_Grunt7Defeat
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_Text_Grunt2Intro:
#if GERMAN
	.string "Wenn du das Geheimnis unseres\n"
	.string "Verstecks erfahren willst, musst du\l"
	.string "mich besiegen!$"
#else
	.string "If you want to know the secret about\n"
	.string "our HIDEOUT, you have me to beat!$"
#endif

AquaHideout_B1F_Text_Grunt2Defeat:
#if GERMAN
	.string "Ich kann anscheinend nicht gewinnen…$"
#else
	.string "I can't win at all…$"
#endif

AquaHideout_B1F_Text_Grunt2PostBattle:
#if GERMAN
	.string "Das Geheimnis unseres Verstecks?\p"
	.string "Nun, sagen wir mal soooo…\n"
	.string "Am Ende befindet sich ein U-boot!\p"
	.string "Aber, im Moment…\n"
	.string "Hehehehe…$"
#else
	.string "Our HIDEOUT's secret?\p"
	.string "Well, let's just say…\n"
	.string "There's a submarine at the far end!\p"
	.string "But, by now…\n"
	.string "Kekekeke…$"
#endif

AquaHideout_B1F_Text_Grunt3Intro:
#if GERMAN
	.string "Tankbefüllung… Okay!\n"
	.string "Proviant… Okay!\p"
	.string "Nichts anderes mehr zu tun, als eine\n"
	.string "Nervensäge aus dem Weg zu räumen.$"
#else
	.string "Fuel supply loaded A-OK!\n"
	.string "In-cruise snacks loaded A-OK!\p"
	.string "Nothing left to do but KO a pesky\n"
	.string "meddler!$"
#endif

AquaHideout_B1F_Text_Grunt3Defeat:
#if GERMAN
	.string "Das war ein Schuss vor den Bug.$"
#else
	.string "I took a serious licking!$"
#endif

AquaHideout_B1F_Text_Grunt3PostBattle:
#if GERMAN
	.string "Pah! Meine Niederlage war geplant.\p"
	.string "Ich sollte dich eh nur aufhalten!$"
#else
	.string "Humph!\n"
	.string "This was supposed to happen!\p"
	.string "My mission was to just hold you up!$"
#endif

AquaHideout_B1F_Text_Grunt5Intro:
#if GERMAN
	.string "Gääähn… Hier im Versteck Wache zu\n"
	.string "stehen, ist ermüdend. Ich muss kämpfen.$"
#else
	.string "Yawn… Keeping watch over the\n"
	.string "HIDEOUT bores me. I'll take you on.$"
#endif

AquaHideout_B1F_Text_Grunt5Defeat:
#if GERMAN
	.string "Gähn… Oh, da habe ich wohl verloren…$"
#else
	.string "Yawn…\n"
	.string "Oh, I lost…$"
#endif

AquaHideout_B1F_Text_Grunt5PostBattle:
#if GERMAN
	.string "Wenn du weiter hier herumschleichst,\n"
	.string "schnappt dich Team Aqua.$"
#else
	.string "If you scurry too much, other TEAM\n"
	.string "AQUA members might get you.$"
#endif

AquaHideout_B1F_Text_Grunt7Intro:
#if GERMAN
	.string "Hey! Du da!\p"
	.string "Was ist cooler?\n"
	.string "Die Uniform von Team Aqua oder die von\l"
	.string "Team Magma?$"
#else
	.string "Hey!\n"
	.string "You there!\p"
	.string "Which do you think is cooler?\n"
	.string "TEAM AQUA's uniform or TEAM MAGMA's?$"
#endif

AquaHideout_B1F_Text_Grunt7Defeat:
#if GERMAN
	.string "Ich habe ganz cool verloren…$"
#else
	.string "I lost in a cool way…$"
#endif

AquaHideout_B1F_Text_Grunt7PostBattle:
#if GERMAN
	.string "Hat man eine coole Uniform, sieht man\n"
	.string "auch noch klasse aus, wenn man verliert,\l"
	.string "findest du nicht?$"
#else
	.string "If you have a cool uniform, you look\n"
	.string "good even in a loss, don't you think?$"
#endif
