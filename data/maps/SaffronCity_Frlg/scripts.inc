SaffronCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAFFRON_CITY
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	end

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_SAFFRON_DOOR_GUARD_GRUNT, 33, 31
	return

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	applymovement LOCALID_SAFFRON_DOOR_GUARD_GRUNT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SaffronCity_Text_ImASecurityGuard
	release
	end

SaffronCity_EventScript_DoorGuardAsleep::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_SABRINA, 0
	msgbox SaffronCity_Text_GymSign
	releaseall
	end

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainSign, MSGBOX_SIGN
	end

SaffronCity_Text_MagnetTrainSign::
#if GERMAN
	.string "MAGNETZUG-BAHNHOF SAFFRONIA CITY\p"
	.string "Die schnellste Verbindung\n"
	.string "zwischen Kanto und Johto.$"
#else
	.string "SAFFRON CITY MAGNET TRAIN STATION\p"
	.string "The fastest connection between\n"
	.string "KANTO and JOHTO.$"
#endif

SaffronCity_Text_WhatDoYouWantGetLost::
#if GERMAN
	.string "Was willst du noch? Hau ab!$"
#else
	.string "What do you want?\n"
	.string "Get lost!$"
#endif

SaffronCity_Text_BossTakeTownForTeamRocket::
#if GERMAN
	.string "Der Boss hat versprochen, dass wir\n"
	.string "diese Stadt einnehmen werden.$"
#else
	.string "BOSS said he'll take this town\n"
	.string "in the name of TEAM ROCKET!$"
#endif

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
#if GERMAN
	.string "Geh aus dem Weg!\n"
	.string "Oder muss ich dir weh tun?$"
#else
	.string "Don't get defiant!\n"
	.string "Or I'll have to hurt you!$"
#endif

SaffronCity_Text_SaffronBelongsToTeamRocket::
#if GERMAN
	.string "Saffronia City gehört dem Team Rocket!$"
#else
	.string "SAFFRON belongs to TEAM ROCKET!$"
#endif

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
#if GERMAN
	.string "Ich fühle mich wunderbar, wenn ich\n"
	.string "böse bin!$"
#else
	.string "My life as a criminal makes me feel\n"
	.string "so alive!$"
#endif

SaffronCity_Text_WatchWhereYoureWalking::
#if GERMAN
	.string "Au!\n"
	.string "Pass auf, wo du hintrittst!$"
#else
	.string "Ow!\n"
	.string "Watch where you're walking!$"
#endif

SaffronCity_Text_WeCanExploitMonsAroundWorld::
#if GERMAN
	.string "Wenn wir erst die Silph Co. unter\n"
	.string "Kontrolle haben, können wir in der\l"
	.string "ganzen Welt mit Pokémon handeln!$"
#else
	.string "With SILPH under control, we can\n"
	.string "exploit POKéMON around the world!\p"
	.string "We'll get stinking rich, yeahah!$"
#endif

SaffronCity_Text_YouBeatTeamRocket::
#if GERMAN
	.string "Du hast das Team Rocket besiegt?\n"
	.string "Unglaublich!!!$"
#else
	.string "You beat TEAM ROCKET all alone?\n"
	.string "That's amazing!$"
#endif

SaffronCity_Text_SafeToGoOutAgain::
#if GERMAN
	.string "Hurra! Das Team Rocket ist fort!\n"
	.string "Jetzt fühlt man sich auf der Straße\l"
	.string "wieder sicher!$"
#else
	.string "Yeah! TEAM ROCKET is gone!\n"
	.string "It's safe to go out again!$"
#endif

SaffronCity_Text_PeopleComingBackToSaffron::
#if GERMAN
	.string "Nun kommen auch wieder Touristen\n"
	.string "nach Saffronia City!$"
#else
	.string "People fled from here in droves\n"
	.string "when those ROCKETS came.\p"
	.string "They should be flocking back to\n"
	.string "SAFFRON now.$"
#endif

SaffronCity_Text_FlewHereOnPidgeot::
#if GERMAN
	.string "Ich flog mit meinem Tauboss hierher,\n"
	.string "nachdem ich von der Silph Co. gelesen\l"
	.string "hatte!\p"
	.string "Ist schon alles vorbei?\n"
	.string "Na toll, dann habe ich wohl das Beste\l"
	.string "verpasst!$"
#else
	.string "I flew here on my PIDGEOT when\n"
	.string "I read about SILPH.\p"
	.string "It's already over?\n"
	.string "I missed the media action…$"
#endif

SaffronCity_Text_Pidgeot::
#if GERMAN
	.string "Tauboss: Tauboss!$"
#else
	.string "PIDGEOT: Bi bibii!$"
#endif

SaffronCity_Text_SawRocketBossEscaping::
#if GERMAN
	.string "Der Boss des Team Rocket ist aus dem\n"
	.string "Gebäude der Silph Co.\l"
	.string "geflohen!$"
#else
	.string "I saw the ROCKET BOSS escaping\n"
	.string "SILPH's building.$"
#endif

SaffronCity_Text_ImASecurityGuard::
#if GERMAN
	.string "Ich bin der Wächter.\p"
	.string "Verdächtige Kinder lasse ich nicht\n"
	.string "herein!$"
#else
	.string "I'm a security guard.\p"
	.string "Suspicious kids I don't allow in!$"
#endif

SaffronCity_Text_HesTakingASnooze::
#if GERMAN
	.string "...\n"
	.string "Schnarch...\p"
	.string "Ha! Er hält ein Nickerchen!$"
#else
	.string "…\n"
	.string "Snore…\p"
	.string "Hah! He's taking a snooze!$"
#endif

SaffronCity_Text_CitySign::
#if GERMAN
	.string "Saffronia City\n"
	.string "Die goldglänzende Handelsstadt!$"
#else
	.string "SAFFRON CITY\n"
	.string "Shining, Golden Land of Commerce$"
#endif

SaffronCity_Text_FightingDojo::
#if GERMAN
	.string "Kampfarena$"
#else
	.string "FIGHTING DOJO$"
#endif

SaffronCity_Text_GymSign::
#if GERMAN
	.string "Saffronia City Pokémon-Arena\n"
	.string "Arenaleiterin: Sabrina Die Herrin der\l"
	.string "Psycho-Pokémon!$"
#else
	.string "SAFFRON CITY POKéMON GYM\n"
	.string "LEADER: SABRINA\l"
	.string "The Master of PSYCHIC POKéMON!$"
#endif

SaffronCity_Text_FullHealCuresStatus::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Hyperheiler kuriert alle \n"
	.string "Verletzungen.\p"
	.string "Er ist teuer, dafür aber sehr\n"
	.string "praktisch.$"
#else
	.string "TRAINER TIPS\p"
	.string "FULL HEAL cures all ailments like\n"
	.string "burns, paralysis, poisoning,\l"
	.string "freezing, and sleep.\p"
	.string "It costs a bit more, but it's more\n"
	.string "convenient than buying other items.$"
#endif

SaffronCity_Text_GreatBallImprovedCatchRate::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Der Superball erhöht die\n"
	.string "Fangquote.\p"
	.string "Probiere ihn bei Pokémon aus, die\n"
	.string "schwer zu fangen sind!$"
#else
	.string "TRAINER TIPS\p"
	.string "The new GREAT BALL offers improved\n"
	.string "catching rates.\p"
	.string "Try it on those hard-to-catch\n"
	.string "POKéMON.$"
#endif

SaffronCity_Text_SilphCoSign::
#if GERMAN
	.string "Silph Co. Bürogebäude$"
#else
	.string "SILPH CO. OFFICE BUILDING$"
#endif

SaffronCity_Text_MrPsychicsHouse::
#if GERMAN
	.string "Psychologen-Haus$"
#else
	.string "MR. PSYCHIC'S HOUSE$"
#endif

SaffronCity_Text_SilphsLatestProduct::
#if GERMAN
	.string "Das neueste Produkt der Silph Co.!\n"
	.string "Verkaufsstart: Demnächst!$"
#else
	.string "SILPH's latest product!\n"
	.string "Release to be determined…$"
#endif

SaffronCity_Text_TrainerFanClubSign::
#if GERMAN
	.string "Pokémon Trainer-Fanclub\p"
	.string "Die Namen von Trainern sind auf\n"
	.string "dem Schild eingeritzt.$"
#else
	.string "POKéMON TRAINER FAN CLUB\p"
	.string "Many TRAINERS have scribbled their\n"
	.string "names on this sign.$"
#endif

SaffronCity_Text_HowCanClubNotRecognizeLance::
#if GERMAN
	.string "Dieser Fanclub…\n"
	.string "Niemand hier weiß Bescheid!\p"
	.string "Wie konnten sie die Genialität\n"
	.string "von Siegfried übersehen?\p"
	.string "Er verkörpert Gerechtigkeit!\n"
	.string "Er ist cool und leidenschaftlich!\l"
	.string "Siegfried ist der Größte!$"
#else
	.string "This FAN CLUB…\n"
	.string "No one here has a clue!\p"
	.string "How could they not recognize\n"
	.string "the brilliance that is LANCE?\p"
	.string "He stands for justice!\n"
	.string "He's cool, and yet passionate!\l"
	.string "He's the greatest, LANCE!$"
#endif

