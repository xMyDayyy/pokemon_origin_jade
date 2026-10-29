RocketHideout_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_OnTransition
	.byte 0

RocketHideout_B1F_OnLoad::
	call_if_not_defeated TRAINER_TEAM_ROCKET_GRUNT_12, RocketHideout_B1F_EventScript_SetBarrier
	end

RocketHideout_B1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCKET_HIDEOUT_B1F
	end

RocketHideout_B1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_8, RocketHideout_B1F_Text_Grunt1Intro, RocketHideout_B1F_Text_Grunt1Defeat
	msgbox RocketHideout_B1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_9, RocketHideout_B1F_Text_Grunt2Intro, RocketHideout_B1F_Text_Grunt2Defeat
	msgbox RocketHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_10, RocketHideout_B1F_Text_Grunt3Intro, RocketHideout_B1F_Text_Grunt3Defeat
	msgbox RocketHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_11, RocketHideout_B1F_Text_Grunt4Intro, RocketHideout_B1F_Text_Grunt4Defeat
	msgbox RocketHideout_B1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_12, RocketHideout_B1F_Text_Grunt5Intro, RocketHideout_B1F_Text_Grunt5Defeat, RocketHideout_B1F_EventScript_DefeatedGrunt5
	msgbox RocketHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_DefeatedGrunt5::
	call RocketHideout_B1F_EventScript_RemoveBarrier
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	release
	end

RocketHideout_B1F_EventScript_SetBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 21, 19, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 20, 20, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 21, 20, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B1F_EventScript_RemoveBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 19, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 20, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 20, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor, 0
	return

RocketHideout_B1F_Text_Grunt1Intro::
#if GERMAN
	.string "Wie kommst du hierher?$"
#else
	.string "Who are you?\n"
	.string "How did you get here?$"
#endif

RocketHideout_B1F_Text_Grunt1Defeat::
#if GERMAN
	.string "Autsch!\n"
	.string "Geschlagen!$"
#else
	.string "Oww!\n"
	.string "Beaten!$"
#endif

RocketHideout_B1F_Text_Grunt1PostBattle::
#if GERMAN
	.string "Willst du dich mit dem Team Rocket\n"
	.string "anlegen?$"
#else
	.string "Blast it… You're dissing TEAM\n"
	.string "ROCKET, aren't you?$"
#endif

RocketHideout_B1F_Text_Grunt2Intro::
#if GERMAN
	.string "Du hast Mut, hier hereinzuplatzen!$"
#else
	.string "You broke into TEAM ROCKET's\n"
	.string "operation? What nerve!$"
#endif

RocketHideout_B1F_Text_Grunt2Defeat::
#if GERMAN
	.string "Mist! Versagt!$"
#else
	.string "Boom!$"
#endif

RocketHideout_B1F_Text_Grunt2PostBattle::
#if GERMAN
	.string "Unsere Rache wird grauenvoll, du\n"
	.string "Rotzblag!$"
#else
	.string "You're not going to get away with\n"
	.string "this, brat!$"
#endif

RocketHideout_B1F_Text_Grunt3Intro::
#if GERMAN
	.string "Alarm!\n"
	.string "Eindringlinge!$"
#else
	.string "Intruder alert!$"
#endif

RocketHideout_B1F_Text_Grunt3Defeat::
#if GERMAN
	.string "Ich konnte ihn nicht stoppen!!!$"
#else
	.string "I can't do it!$"
#endif

RocketHideout_B1F_Text_Grunt3PostBattle::
#if GERMAN
	.string "Silph Scope?\n"
	.string "Ich weiß nicht, wovon du redest!$"
#else
	.string "SILPH SCOPE? Humph!\n"
	.string "I don't know where it is.$"
#endif

RocketHideout_B1F_Text_Grunt4Intro::
#if GERMAN
	.string "Was willst du überhaupt hier?$"
#else
	.string "Why did you come here?$"
#endif

RocketHideout_B1F_Text_Grunt4Defeat::
#if GERMAN
	.string "Das kann nicht funktionieren!$"
#else
	.string "This won't do!$"
#endif

RocketHideout_B1F_Text_Grunt4PostBattle::
#if GERMAN
	.string "O.k., O.k., ich packe aus!\n"
	.string "Benutze den Aufzug zum Boss!$"
#else
	.string "Okay, I'll talk…\n"
	.string "Take the elevator to see my BOSS.$"
#endif

RocketHideout_B1F_Text_Grunt5Intro::
#if GERMAN
	.string "Was hast du hier verloren?$"
#else
	.string "Are you lost, you little mouse?$"
#endif

RocketHideout_B1F_Text_Grunt5Defeat::
#if GERMAN
	.string "Was ist passiert?$"
#else
	.string "Why…?$"
#endif

RocketHideout_B1F_Text_Grunt5PostBattle::
#if GERMAN
	.string "Ups, die Tür ist aufgegangen!$"
#else
	.string "Uh-oh, that ruckus somehow opened\n"
	.string "the door!$"
#endif

