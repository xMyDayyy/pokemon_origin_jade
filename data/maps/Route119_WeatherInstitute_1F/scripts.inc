Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_IS_HOENN_CHAMPION, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	@ Counts Kyogre and Groudon that cannot be met now.
	setvar VAR_0x8005, 0
	setvar VAR_0x8004, LEGENDARY_KYOGRE
	specialvar VAR_RESULT, IsLegendaryAvailable
	call_if_ne VAR_RESULT, TRUE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	setvar VAR_0x8004, LEGENDARY_GROUDON
	specialvar VAR_RESULT, IsLegendaryAvailable
	call_if_ne VAR_RESULT, TRUE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8005, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Neither can be met
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8005, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	@ Pokemon Center challenge: no rest and no heal.
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, Route119_WeatherInstitute_1F_EventScript_Bed_PokecenterChallenge
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Bed_PokecenterChallenge::
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	release
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
#if GERMAN
	.string "Der Boss hat Interesse an den \n"
	.string "Forschungen gezeigt, daher hat er uns\l"
	.string "hergeschickt.\p"
	.string "Stör uns gefälligst nicht!$"
#else
	.string "The BOSS got interested in\n"
	.string "the research they have going here,\l"
	.string "so he sent us out.\p"
	.string "You quit meddling!$"
#endif

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
#if GERMAN
	.string "So ein Mist…\n"
	.string "Besiegt… von einem Kind!$"
#else
	.string "Blast it…\n"
	.string "Blasted by a kid…$"
#endif

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
#if GERMAN
	.string "Unser Boss weiß alles.\p"
	.string "Ich bin nur ein Rüpel. Woher soll ich\n"
	.string "wissen, was er denkt?$"
#else
	.string "Our BOSS knows everything.\p"
	.string "But I'm just a GRUNT. What would I know\n"
	.string "about what he's thinking?$"
#endif

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
#if GERMAN
	.string "Wie? Was macht denn das Kind hier?$"
#else
	.string "Huh?\n"
	.string "What's a kid doing here?$"
#endif

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
#if GERMAN
	.string "Wie? Ich habe verloren?!?$"
#else
	.string "Huh?\n"
	.string "I lost?!$"
#endif

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
#if GERMAN
	.string "Oh. Ich werde mir etwas anhören müssen,\n"
	.string "weil ich gegen ein Kind verloren habe…\p"
	.string "\p"
	.string "Ich muss mich jetzt dringend hinlegen…$"
#else
	.string "Oh, no…\n"
	.string "I'll catch an earful for losing to a kid…\p"
	.string "I should just take a nap in the bed…$"
#endif

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
#if GERMAN
	.string "Als ich schlief, schlich sich jemand\n"
	.string "nach oben!$"
#else
	.string "While I was sleeping, everyone went\n"
	.string "upstairs!$"
#endif

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
#if GERMAN
	.string "Wow! Bist du aber stark!\p"
	.string "Ich wäre auch gerne ein Pokémon-\n"
	.string "Trainer wie du!$"
#else
	.string "Wow, you're really strong!\p"
	.string "I wish I could be a POKéMON TRAINER\n"
	.string "like you!$"
#endif

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
#if GERMAN
	.string "Der Professor liebt den Regen.\n"
	.string "Das ist eine Tatsache.\p"
	.string "Aber wenn es noch lange so regnet, wird\n"
	.string "das zu Problemen führen. Das ist die\l"
	.string "andere Seite der Medaille.\p"
	.string "Und daher erforscht der Professor,\n"
	.string "wie man den Regen positiv nutzen kann.$"
#else
	.string "The PROFESSOR loves rain.\n"
	.string "That's a fact.\p"
	.string "But if it keeps raining, people will be in\n"
	.string "trouble. That's another fact.\p"
	.string "And thus, the PROFESSOR is studying\n"
	.string "if the rain can be put to good use.$"
#endif

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
#if GERMAN
	.string "Im ersten Stock des Instituts\n"
	.string "untersuchen wir die Klimaveränderungen\l"
	.string "in der Hoenn-Region.\p"
	.string "Wir haben dort eine temporäre Dürre und\n"
	.string "einzelne Fälle von heftigem\l"
	.string "Niederschlag verzeichnen können.$"
#else
	.string "On the 2nd floor of the INSTITUTE,\n"
	.string "we study the weather patterns over\l"
	.string "the HOENN region.\p"
	.string "We've been noticing temporary and\n"
	.string "isolated cases of droughts and\l"
	.string "heavy rain lately…$"
#endif

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
#if GERMAN
	.string "Hallo! Dein beherztes Eingreifen hat\n"
	.string "uns gerettet!\p"
	.string "Ich verstehe nur nicht, was die Aquas\n"
	.string "von uns wollten…$"
#else
	.string "Hello!\n"
	.string "We've been saved by your actions!\p"
	.string "What I don't understand is what on\n"
	.string "earth the AQUAS were up to.$"
#endif

Route119_WeatherInstitute_1F_Text_TakeRestInBed_PokecenterChallenge:
#if GERMAN
	.string "Sorry, du machst gerade die\n"
	.string "Pokécenter-Challenge!$"
#else
	.string "Sorry, you are playing with\n"
	.string "the POKéCENTER challenge!$"
#endif

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
#if GERMAN
	.string "Da steht ein Bett…\n"
	.string "Eine Pause wäre willkommen.$"
#else
	.string "There's a bed…\n"
	.string "Let's take a rest.$"
#endif

