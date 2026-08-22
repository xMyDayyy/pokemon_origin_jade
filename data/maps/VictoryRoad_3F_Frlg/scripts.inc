VictoryRoad_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER1
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_3F, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Text_DoubleEdgeTeach::
#if GERMAN
	.string "Du kannst stolz auf dich sein, weil du\n"
	.string "dich so wacker auf der Siegesstraße\l"
	.string "geschlagen hast.\p"
	.string "Als Anerkennung deiner Leistung möchte\n"
	.string "ich einem deiner Pokémon Risikotackle\l"
	.string "beibringen.\p"
	.string "Soll ich einem Pokémon diese Attacke\n"
	.string "beibringen?$"
#else
	.string "You should be proud of yourself,\n"
	.string "having battled your way through\l"
	.string "VICTORY ROAD so courageously.\p"
	.string "In recognition of your feat,\n"
	.string "I'll teach you DOUBLE-EDGE.\p"
	.string "Would you like me to teach that\n"
	.string "technique?$"
#endif

Text_DoubleEdgeDeclined::
#if GERMAN
	.string "Ich bringe diese Attacke einem\n"
	.string "deiner Pokémon jederzeit bei.$"
#else
	.string "I'll teach you the technique\n"
	.string "anytime.$"
#endif

Text_DoubleEdgeWhichMon::
#if GERMAN
	.string "Welches Pokémon soll Risikotackle\n"
	.string "erlernen?$"
#else
	.string "Which POKéMON should I teach\n"
	.string "DOUBLE-EDGE?$"
#endif

Text_DoubleEdgeTaught::
#if GERMAN
	.string "Mach in der Pokémon Liga so weiter!\p"
	.string "Überrumple sie und mach sie fertig!$"
#else
	.string "Keep that drive going for the\n"
	.string "POKéMON LEAGUE!\p"
	.string "Take a run at them and knock 'em\n"
	.string "out!$"
#endif

VictoryRoad_3F_Text_GeorgeIntro::
#if GERMAN
	.string "Man erzählt von einem Wunderkind!$"
#else
	.string "I heard rumors of a child prodigy.$"
#endif

VictoryRoad_3F_Text_GeorgeDefeat::
#if GERMAN
	.string "Du bist das Wunderkind!$"
#else
	.string "The rumors were true!$"
#endif

VictoryRoad_3F_Text_GeorgePostBattle::
#if GERMAN
	.string "Hast du wirklich Giovanni vom Team\n"
	.string "Rocket besiegt?$"
#else
	.string "So, it was you who beat GIOVANNI\n"
	.string "of TEAM ROCKET?$"
#endif

VictoryRoad_3F_Text_AlexaIntro::
#if GERMAN
	.string "Trainer sind geborene Kämpfer, immer\n"
	.string "auf der Suche nach starken Gegnern!$"
#else
	.string "TRAINERS live to seek stronger\n"
	.string "opponents.$"
#endif

VictoryRoad_3F_Text_AlexaDefeat::
#if GERMAN
	.string "Cool!\n"
	.string "Du bist wirklich stark!$"
#else
	.string "Oh!\n"
	.string "So strong!$"
#endif

VictoryRoad_3F_Text_AlexaPostBattle::
#if GERMAN
	.string "Je härter die Kämpfe sind, desto\n"
	.string "stärker wirst du!$"
#else
	.string "By fighting tough battles, you get\n"
	.string "stronger.$"
#endif

VictoryRoad_3F_Text_CarolineIntro::
#if GERMAN
	.string "Gleich siehst du, wie gut du bist!$"
#else
	.string "I'll show you just how good you\n"
	.string "are. Not!$"
#endif

VictoryRoad_3F_Text_CarolineDefeat::
#if GERMAN
	.string "Das darf doch nicht wahr sein!\n"
	.string "Grrr!$"
#else
	.string "I'm furious!$"
#endif

VictoryRoad_3F_Text_CarolinePostBattle::
#if GERMAN
	.string "Du hast mich in die Schranken\n"
	.string "verwiesen!$"
#else
	.string "You showed me just how good\n"
	.string "I was…$"
#endif

VictoryRoad_3F_Text_ColbyIntro::
#if GERMAN
	.string "Nur Auserwählte dürfen passieren!$"
#else
	.string "Only the chosen can pass here!$"
#endif

VictoryRoad_3F_Text_ColbyDefeat::
#if GERMAN
	.string "Ich fasse es nicht!$"
#else
	.string "I don't believe it!$"
#endif

VictoryRoad_3F_Text_ColbyPostBattle::
#if GERMAN
	.string "Die Trainer hier sind auf dem Weg\n"
	.string "zur Pokémon Liga! Sei vorsichtig!$"
#else
	.string "All TRAINERS here are headed to\n"
	.string "the POKéMON LEAGUE.\p"
	.string "Don't let down your guard.$"
#endif

VictoryRoad_3F_Text_RayIntro::
#if GERMAN
	.string "Tyro: Unser beider Bestimmung\n"
	.string "ist etwas Großes zu erreichen!$"
#else
	.string "RAY: Together, the two of us are\n"
	.string "destined for greatness!$"
#endif

VictoryRoad_3F_Text_RayDefeat::
#if GERMAN
	.string "Tyro: Lächerlich! Es kann nicht\n"
	.string "sein, was nicht sein darf!$"
#else
	.string "RAY: Ludicrous!\n"
	.string "This can't be!$"
#endif

VictoryRoad_3F_Text_RayPostBattle::
#if GERMAN
	.string "Tyro: Du hast uns besiegt! Großes\n"
	.string "ist nicht leicht zu vollbringen!$"
#else
	.string "RAY: You've beaten us.\n"
	.string "Greatness remains elusive…$"
#endif

VictoryRoad_3F_Text_RayNotEnoughMons::
#if GERMAN
	.string "Tyro: Zusammen streben wir beide\n"
	.string "nach dem Gipfel.\p"
	.string "Du musst zwei Pokémon gegen uns\n"
	.string "einsetzen!$"
#else
	.string "RAY: Together, the two of us are\n"
	.string "striving for the pinnacle.\p"
	.string "We need you to bring two POKéMON\n"
	.string "into battle with us.$"
#endif

VictoryRoad_3F_Text_TyraIntro::
#if GERMAN
	.string "Lore: Wir versuchen, gemeinsam\n"
	.string "Champs zu werden!$"
#else
	.string "TYRA: We're trying to become\n"
	.string "champions together.$"
#endif

VictoryRoad_3F_Text_TyraDefeat::
#if GERMAN
	.string "Lore: Oh, aber…!$"
#else
	.string "TYRA: Oh, but…$"
#endif

VictoryRoad_3F_Text_TyraPostBattle::
#if GERMAN
	.string "Lore: Du hast mir gezeigt, dass Kraft\n"
	.string "grenzenlose Formen haben kann.$"
#else
	.string "TYRA: You've taught me that power\n"
	.string "can be infinite in shape and form.$"
#endif

VictoryRoad_3F_Text_TyraNotEnoughMons::
#if GERMAN
	.string "Lore: Mit nur einem Pokémon kannst du\n"
	.string "nicht gegen uns antreten!$"
#else
	.string "TYRA: You can't battle with us if\n"
	.string "you have only one POKéMON.$"
#endif

@ ============================================================================
@ Kanto-Merge: Lavados sitzt in FRLG auf dem Wipfelberg, also auf den
@ stillgelegten Sevii-Inseln. In Rot/Blau stand es auf der Siegesstrasse -
@ dorthin kommt es zurueck, damit alle drei Voegel in Kanto erreichbar sind.
@ Zapdos steht im Kraftwerk, Arktos auf den Seeschauminseln.
@ ============================================================================

VictoryRoad_3F_EventScript_Moltres::
	lock
	faceplayer
	setwildbattle SPECIES_MOLTRES, 50
	waitse
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	message Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_3F_EventScript_DefeatedMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_3F_EventScript_RanFromMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_3F_EventScript_RanFromMoltres
	setflag FLAG_HIDE_MOLTRES_KANTO
	release
	end

VictoryRoad_3F_EventScript_DefeatedMoltres::
	setflag FLAG_HIDE_MOLTRES_KANTO
	goto EventScript_RemoveStaticMon
	end

VictoryRoad_3F_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto EventScript_RemoveStaticMon
	end
