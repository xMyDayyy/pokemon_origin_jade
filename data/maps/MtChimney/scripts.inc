MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
.else
	hidemoneybox
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
.endif @ OW_SHOW_ITEM_DESCRIPTIONS


MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
#if GERMAN
	.string "Die Kraft, die in dem Meteoriten\n"
	.string "steckt…\p"
	.string "Wenn man die mit dieser Maschine\n"
	.string "verstärkt, würde die Aktivität des\l"
	.string "Schlotbergs enorm verstärkt…\p"
	.string "Die Energie wird tief im Krater\n"
	.string "ansteigen und…\l"
	.string "Hähähähä…$"
#else
	.string "The power contained in the METEORITE…\p"
	.string "By amplifying its power with this\n"
	.string "machine, MT. CHIMNEY's volcanic\l"
	.string "activity will instantly intensify…\p"
	.string "Its energy will grow deep inside\n"
	.string "the crater and…\l"
	.string "Fufufu…$"
#endif

MtChimney_Text_MaxieIntro:
#if GERMAN
	.string "Marc: Hm?\n"
	.string "Wer bist du denn?!?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Adrian hat sich über ein Kind beklagt,\n"
	.string "das sich in die Angelegenheiten von\l"
	.string "Team Aqua einmischt.\p"
	.string "Dieses Kind musst du sein.\p"
	.string "Hmpf! Und du glaubst, du kannst dich\n"
	.string "auch in unsere, Team Magmas\l"
	.string "Angelegenheiten einmischen?\p"
	.string "Hör gut zu. Schon lange Zeit nutzen die\n"
	.string "Lebewesen das Land, um zu wachsen und\l"
	.string "zu gedeihen.\p"
	.string "Daher ist das Land wichtiger als alles\n"
	.string "andere! Es ist die Wiege allen Lebens.\p"
	.string "Daher widmet sich Team Magma der Auf-\n"
	.string "gabe, die Landmassen zu vergrößern.\p"
	.string "So entsteht mehr Raum für Menschen\n"
	.string "und Pokémon.\p"
	.string "Für unsere Pläne brauchen wir das, was\n"
	.string "im Inneren dieses Berges schläft…\p"
	.string "Nun, mehr brauchst du nicht zu wissen.\p"
	.string "Ich kann einem sturen Kind wie dir nicht\n"
	.string "erlauben, sich uns in den Weg zu\p"
	.string "stellen. \p"
	.string "Ich werde dir zeigen, was passiert, wenn\n"
	.string "du uns aufhalten willst!$"
#else
	.string "MAXIE: Hm?\n"
	.string "Who are you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "I'd heard ARCHIE bemoaning a child\n"
	.string "who's been meddling in TEAM AQUA's\l"
	.string "affairs.\p"
	.string "It must be you he meant.\p"
	.string "Humph! So you're thinking of\n"
	.string "interfering with us, TEAM MAGMA?\p"
	.string "Now you listen.\n"
	.string "Long ago, living things used the\l"
	.string "land to live and grow.\p"
	.string "That is why land is all important!\n"
	.string "It is the cradle of all!\p"
	.string "That is why TEAM MAGMA is dedicated\n"
	.string "to the expansion of the land mass.\p"
	.string "It is for further advancement of\n"
	.string "humankind and POKéMON!\p"
	.string "And for that, we need the power of\n"
	.string "what sleeps within this mountain…\p"
	.string "Oh! There was no need for you to\n"
	.string "learn that much.\p"
	.string "But, no matter!\n"
	.string "I'll teach you the consequences of\l"
	.string "meddling in our grand design!$"
#endif

MtChimney_Text_MaxieDefeat:
#if GERMAN
	.string "Wie bitte?!?\p"
	.string "Ich, Marc, wurde ganz hinterhältig\n"
	.string "besiegt?!?$"
#else
	.string "What?!\p"
	.string "I, MAXIE, was caught off guard?!$"
#endif

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
#if GERMAN
	.string "Marc: Genug.\n"
	.string "Ich ziehe mich für den Moment zurück.\p"
	.string "Aber das ist nicht das letzte Mal, dass\n"
	.string "du Team Magma zu Gesicht bekommen\l"
	.string "hast.\p"
	.string "Hähähä…\p"
	.string "Auch ohne Meteorit… Wenn wir erst die\n"
	.string "Kugel haben… Hähähähä…$"
#else
	.string "MAXIE: But, enough.\n"
	.string "I will back off this time.\p"
	.string "But don't think that this is the last\n"
	.string "you've seen of TEAM MAGMA.\p"
	.string "Fufufu…\p"
	.string "Even without the METEORITE, if we\n"
	.string "obtain that ORB… Fufufu…$"
#endif

MtChimney_Text_TabithaIntro:
#if GERMAN
	.string "Hahahahaha!\p"
	.string "Da bist du also den weiten Weg hier\n"
	.string "hoch gelatscht.\p"
	.string "Tja, du kommst leider zu spät. Ich habe\n"
	.string "den Meteoriten aus Meteorfälle bereits\l"
	.string "bei meinem Boss abgeliefert!$"
#else
	.string "Hehehe!\p"
	.string "So you've come all the way here!\p"
	.string "But you're too late!\n"
	.string "I've already delivered the METEORITE\l"
	.string "from METEOR FALLS to the BOSS!$"
#endif

MtChimney_Text_TabithaDefeat:
#if GERMAN
	.string "Hähähä…\p"
	.string "Auch wenn ich verloren habe… Sobald\n"
	.string "unser Boss das Ding zum Leben erweckt…$"
#else
	.string "Hehehe…\p"
	.string "Even though I've lost, if our leader\n"
	.string "awakens that thing…$"
#endif

MtChimney_Text_TabithaPostBattle:
#if GERMAN
	.string "Boss, beeil dich!\n"
	.string "Gib ihm die Energie des Meteoriten!\p"
	.string "Hähähä…$"
#else
	.string "BOSS, hurry!\n"
	.string "Give it the METEORITE's energy!\p"
	.string "Hehehe…$"
#endif

MtChimney_Text_Grunt2Intro:
#if GERMAN
	.string "Wir von Team Magma setzen alles daran,\n"
	.string "zum Wohle aller zu handeln.\p"
	.string "Und wenn das Ding mehr Land schafft,\n"
	.string "gibt es auch mehr Platz zum Leben.\p"
	.string "Und jeder wäre glücklich!$"
#else
	.string "We of TEAM MAGMA are working hard for\n"
	.string "everyone's sake.\p"
	.string "Like, if that thing's power made more\n"
	.string "land, there'd be more places to live.\p"
	.string "Everyone'd be happy!$"
#endif

MtChimney_Text_Grunt2Defeat:
#if GERMAN
	.string "Bitte?\n"
	.string "Was sagst du? Ich habe verloren???$"
#else
	.string "Hunh?\n"
	.string "What do you mean I lost?$"
#endif

MtChimney_Text_Grunt2PostBattle:
#if GERMAN
	.string "Unser Boss sagt: “Jeder wird glücklich\n"
	.string "sein.”\p"
	.string "Aber warum will uns dann jeder\n"
	.string "aufhalten?$"
#else
	.string "Our BOSS says, “It will make everyone\n"
	.string "happy.”\p"
	.string "But why does everyone keep getting\n"
	.string "in our way?$"
#endif

MtChimney_Text_Grunt1Intro:
#if GERMAN
	.string "Wenn es mehr Land gibt, wäre ich in der\n"
	.string "Lage, mir ein eigenes großes Haus zu\l"
	.string "bauen!\p"
	.string "Das würde ich dann auf der erstarrten\n"
	.string "Lava bauen!$"
#else
	.string "If there were more land, I'd be able\n"
	.string "to get a big house of my own!\p"
	.string "I'm going to build it on hardened lava!$"
#endif

MtChimney_Text_Grunt1Defeat:
#if GERMAN
	.string "Mein Traum von einem großen Haus…$"
#else
	.string "My dream of a big house…$"
#endif

MtChimney_Text_Grunt1PostBattle:
#if GERMAN
	.string "Ein Kind wie du sollte sich im Meer\n"
	.string "vergnügen.$"
#else
	.string "A kid like you, you ought to be\n"
	.string "splashing about in the waves!$"
#endif

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
#if GERMAN
	.string "Dieses lästige Team Aqua… Sie\n"
	.string "versuchen alles, unsere Pläne zu\l"
	.string "vereiteln.$"
#else
	.string "That annoying TEAM AQUA…\n"
	.string "They always mess with our plans!$"
#endif

MtChimney_Text_MeteoritesPackAmazingPower:
#if GERMAN
	.string "Meteoriten stecken voller Energie.$"
#else
	.string "METEORITES pack amazing power!$"
#endif

MtChimney_Text_YouBetterNotMessWithUs:
#if GERMAN
	.string "Du gehst uns besser aus dem Weg!\p"
	.string "Wir werden das Ding zum Leben\n"
	.string "erwecken. Zum Wohle aller.$"
#else
	.string "You'd better not mess with us!\p"
	.string "We're trying to awaken that thing\n"
	.string "for the benefit of everyone!$"
#endif

MtChimney_Text_AquasNameSimilar:
#if GERMAN
	.string "Wir sind Team Magma!\p"
	.string "Sie sind Team Aqua!\p"
	.string "Ich finde es total bescheuert, dass sie\n"
	.string "einen Namen haben, der unserem ähnelt.$"
#else
	.string "We're TEAM MAGMA!\p"
	.string "They're TEAM AQUA!\p"
	.string "It totally annoys me that they'd\n"
	.string "use a name like ours!$"
#endif

MtChimney_Text_DouseThemInFire:
#if GERMAN
	.string "Yeah! Taucht sie ins Feuer!$"
#else
	.string "Yeah!\n"
	.string "Douse them in fire!$"
#endif

MtChimney_Text_KeepMakingMoreLand:
#if GERMAN
	.string "Wir werden weiter für mehr Land\n"
	.string "sorgen!$"
#else
	.string "We're going to keep making more land!$"
#endif

MtChimney_Text_Bufoh:
#if GERMAN
	.string "Hahoh!$"
#else
	.string "Bufoh!$"
#endif

MtChimney_Text_ArchieGoStopTeamMagma:
#if GERMAN
	.string "Adrian: Grrr, {PLAYER}!\n"
	.string "Ich hätte es wissen müssen. War doch\l"
	.string "klar, dass du hier auftauchst.\p"
	.string "Schau dir ruhig an, was die Fanatiker\n"
	.string "von Team Magma vorhaben!\p"
	.string "Sie wollen die Kraft des gestohlenen\n"
	.string "Meteoriten in den Vulkan geben!\p"
	.string "Und das wird den Vulkan zum Ausbruch\n"
	.string "bringen!$"
#else
	.string "ARCHIE: Grr, {PLAYER}!\n"
	.string "I should've guessed you'd show up!\p"
	.string "See for yourself what the fanatics\n"
	.string "of TEAM MAGMA are up to!\p"
	.string "They're trying to inject the stolen\n"
	.string "METEORITE's power into the volcano!\p"
	.string "Doing something like that will cause\n"
	.string "the volcano's eruption!$"
#endif

MtChimney_Text_ArchieIHaveMyHandsFull:
#if GERMAN
	.string "Adrian: Grrr…\p"
	.string "Ich möchte Marc aufhalten, aber ich\n"
	.string "kann es nicht!\p"
	.string "Nicht, wenn ich mich drei Gegnern\n"
	.string "gleichzeitig stellen muss.$"
#else
	.string "ARCHIE: Grrr…\p"
	.string "I want to stop that MAXIE,\n"
	.string "but I can't!\p"
	.string "Not when I have my hands full battling\n"
	.string "three opponents at once!$"
#endif

MtChimney_Text_ArchieThankYou:
#if GERMAN
	.string "Adrian: {PLAYER}!\n"
	.string "Danke!\p"
	.string "Mit deiner Hilfe haben wir den\n"
	.string "zerstörerischen Plan von Team Magma\l"
	.string "durchkreuzt!\p"
	.string "Aber… Du…\n"
	.string "Auf welcher Seite stehst du?\p"
	.string "Ach, das ist egal.\p"
	.string "Wir werden weiter unsere Augen\n"
	.string "aufhalten und Team Magma beobachten.\p"
	.string "{PLAYER}, wir sehen uns bestimmt\n"
	.string "wieder!$"
#else
	.string "ARCHIE: {PLAYER}!\n"
	.string "Thank you!\p"
	.string "With your help, we thwarted TEAM\n"
	.string "MAGMA's destructive plan!\p"
	.string "But… You…\n"
	.string "Whose side are you on?\p"
	.string "Ah, it doesn't matter.\p"
	.string "We will remain vigilant and keep up\n"
	.string "our pursuit of TEAM MAGMA.\p"
	.string "{PLAYER}, we shall meet again!$"
#endif

MtChimney_Text_MagmaOutnumbersUs:
#if GERMAN
	.string "Mist… Team Magma ist uns zahlenmäßig\n"
	.string "überlegen! Wir können es nicht mit ihnen\l"
	.string "aufnehmen!$"
#else
	.string "Darn… TEAM MAGMA outnumbers us!\n"
	.string "We can't keep up with them!$"
#endif

MtChimney_Text_LessHabitatForWaterPokemon:
#if GERMAN
	.string "Wenn sie die Landmassen vergrößern,\n"
	.string "gibt es weniger Lebensraum für\l"
	.string "Wasser-Pokémon!$"
#else
	.string "If they expand the land, there'll be\n"
	.string "less habitats for WATER POKéMON!$"
#endif

MtChimney_Text_MagmasNameSimilar:
#if GERMAN
	.string "Wir sind Team Aqua!\p"
	.string "Sie sind Team Magma!\p"
	.string "Ich koche über vor Wut, weil sie so\n"
	.string "einen verwirrenden Namen verwenden.$"
#else
	.string "We're TEAM AQUA!\p"
	.string "They're TEAM MAGMA!\p"
	.string "It burns me up that they'd use such\n"
	.string "a confusing name!$"
#endif

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
#if GERMAN
	.string "Lavakekse sind die Spezialität am\n"
	.string "Schlotberg.\p"
	.string "Nimm einen. Er kostet nur ¥200.$"
#else
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
	.string "specialty.\p"
	.string "Try one. It's just ¥200.$"
#endif

MtChimney_Text_ThankYouDear:
#if GERMAN
	.string "Vielen Dank, Herzchen!$"
#else
	.string "Thank you, dear!$"
#endif

MtChimney_Text_YouveNotGotTheMoney:
#if GERMAN
	.string "Oh je. Du kannst nichts kaufen, wenn\n"
	.string "du nicht genug Geld bei dir hast.$"
#else
	.string "Oh, dear. You can't buy a thing if\n"
	.string "you've not got the money.$"
#endif

MtChimney_Text_OhFineThen:
#if GERMAN
	.string "Oh, ist gut.$"
#else
	.string "Oh, fine then.$"
#endif

MtChimney_Text_MetoriteFittedOnMachine:
#if GERMAN
	.string "Ein Meteorit steckt in dieser\n"
	.string "mysteriösen Vorrichtung…\p"
	.string "Die Maschine scheint den Meteoriten\n"
	.string "mit Energie zu versorgen.$"
#else
	.string "A METEORITE is fitted on a mysterious\n"
	.string "machine…\p"
	.string "The machine seems to be storing\n"
	.string "energy in the METEORITE.$"
#endif

MtChimney_Text_RemoveTheMeteorite:
#if GERMAN
	.string "Ein Meteorit steckt in dieser\n"
	.string "mysteriösen Vorrichtung…\p"
	.string "Willst du den Meteoriten nehmen?$"
#else
	.string "A METEORITE is fitted on a mysterious\n"
	.string "machine…\p"
	.string "Do you want to remove the METEORITE?$"
#endif

MtChimney_Text_PlayerRemovedMeteorite:
#if GERMAN
	.string "{PLAYER} entfernt den Meteoriten aus\n"
	.string "der mysteriösen Vorrichtung.$"
#else
	.string "{PLAYER} removed the METEORITE from\n"
	.string "the mysterious machine.$"
#endif

MtChimney_Text_PlayerLeftMeteorite:
#if GERMAN
	.string "{PLAYER} fasst den Meteoriten nicht\n"
	.string "an.$"
#else
	.string "{PLAYER} left the METEORITE where\n"
	.string "it was.$"
#endif

MtChimney_Text_MachineMakesNoResponse:
#if GERMAN
	.string "Diese mysteriöse Vorrichtung…\n"
	.string "Sie reagiert in keiner Weise.$"
#else
	.string "This mysterious machine…\n"
	.string "It makes no response whatsoever.$"
#endif

MtChimney_Text_RouteSign:
#if GERMAN
	.string "{DOWN_ARROW} Steilpass\n"
	.string "Bad Lavastadt geradeaus$"
#else
	.string "{DOWN_ARROW} JAGGED PATH\n"
	.string "LAVARIDGE TOWN AHEAD$"
#endif

MtChimney_Text_ShelbyIntro:
#if GERMAN
	.string "Ich war bei den Heißen Quellen und habe\n"
	.string "meine müden Knochen erfrischt.\l"
	.string "Jetzt fühle ich mich richtig stark!$"
#else
	.string "I've been to the hot springs and\n"
	.string "refreshed my tired bones.\l"
	.string "Right now I'm feeling strong!$"
#endif

MtChimney_Text_ShelbyDefeat:
#if GERMAN
	.string "Oh, du meine Güte!\n"
	.string "Wer bist du denn?!?$"
#else
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"
#endif

MtChimney_Text_ShelbyPostBattle:
#if GERMAN
	.string "Nun, ich habe verloren. Ich darf mich\n"
	.string "nun nicht mehr Experte nennen, oder?$"
#else
	.string "Well, well, I've lost. I can't call\n"
	.string "myself an EXPERT now, can I?$"
#endif

MtChimney_Text_ShelbyRegister:
#if GERMAN
	.string "Danke schön, mein Kind. Das hat Spaß\n"
	.string "gemacht. So, als ob ich gegen mein\l"
	.string "Enkelkind gekämpft hätte.\p"
	.string "Komm doch bitte mal wieder vorbei.$"
#else
	.string "Thank you, child. It was fun, as if\n"
	.string "I were battling my own grandchild.\p"
	.string "Please, come see me again for\n"
	.string "a rematch.$"
#endif

MtChimney_Text_ShelbyRematchIntro:
#if GERMAN
	.string "Wenn du in deinem Herzen Platz für\n"
	.string "deine Pokémon hast, dann kannst du\l"
	.string "auch große Dinge erreichen.$"
#else
	.string "If you can mesh your heart with those\n"
	.string "of your POKéMON, why, you should be\l"
	.string "able to achieve great things.$"
#endif

MtChimney_Text_ShelbyRematchDefeat:
#if GERMAN
	.string "Oh, du meine Güte!\n"
	.string "Wer bist du denn!$"
#else
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"
#endif

MtChimney_Text_ShelbyPostRematch:
#if GERMAN
	.string "Vielleicht schlägt dein Herz im\n"
	.string "Gleichklang mit den Pokémon.$"
#else
	.string "Perhaps your heart has become one\n"
	.string "with the hearts of your POKéMON.$"
#endif

MtChimney_Text_MelissaIntro:
#if GERMAN
	.string "Ich habe Feuer in mir, Baby.\n"
	.string "Ich halt’s nicht aus! Ich muss kämpfen!$"
#else
	.string "I've got the fire in me, baby.\n"
	.string "I can't stand it! I have to battle!$"
#endif

MtChimney_Text_MelissaDefeat:
#if GERMAN
	.string "Oh, was für ein kochend heißer Kampf!$"
#else
	.string "Ooh, that was a scorching-hot match!$"
#endif

MtChimney_Text_MelissaPostBattle:
#if GERMAN
	.string "Die Hitze vom Schlotberg bringt mein\n"
	.string "Feuer in Gang.$"
#else
	.string "The heat of MT. CHIMNEY warms\n"
	.string "me up, baby!$"
#endif

MtChimney_Text_SheilaIntro:
#if GERMAN
	.string "Endlich bin ich am Schlotberg ange-\n"
	.string "kommen. Jetzt will ich kämpfen!!!$"
#else
	.string "I've finally made it to MT. CHIMNEY.\n"
	.string "I want to make my POKéMON battle!$"
#endif

MtChimney_Text_SheilaDefeat:
#if GERMAN
	.string "Wie du kämpfst…\n"
	.string "Als würde der Schlotberg ausbrechen!$"
#else
	.string "The way you battle…\n"
	.string "It's like a MT. CHIMNEY eruption!$"
#endif

MtChimney_Text_SheilaPostBattle:
#if GERMAN
	.string "Wie ich schon sagte, endlich bin ich am\n"
	.string "Schlotberg. Wäre doch blödsinnig, wenn\l"
	.string "ich nur zum Sightseeing hier wäre…\p"
	.string "Ich will ein bisschen kämpfen und\n"
	.string "Kekse als Andenken kaufen.$"
#else
	.string "Like I said, I've finally made it to\n"
	.string "MT. CHIMNEY. It would be a shame if\l"
	.string "I only do a little sightseeing…\p"
	.string "I want to get in some battles and buy\n"
	.string "COOKIES as souvenirs.$"
#endif

MtChimney_Text_ShirleyIntro:
#if GERMAN
	.string "Seit ich in den Heißen Quellen gebadet\n"
	.string "habe, fühle ich mich großartig!\l"
	.string "Ich bin sicher, ich werde gewinnen!$"
#else
	.string "Since I bathed in the hot springs,\n"
	.string "I've been feeling great!\l"
	.string "I'm sure I'm going to win!$"
#endif

MtChimney_Text_ShirleyDefeat:
#if GERMAN
	.string "Huaah!\n"
	.string "Außerhalb des Wassers ist es saukalt.$"
#else
	.string "Yowch!\n"
	.string "I'm getting a chill out of the water.$"
#endif

MtChimney_Text_ShirleyPostBattle:
#if GERMAN
	.string "Ich werde mich wieder in die Heiße\n"
	.string "Quelle setzen. Kommst du mit?\p"
	.string "Kleiner Scherz am Rande… Hähähä.$"
#else
	.string "I'll have to take another dip in the\n"
	.string "hot springs. Want to join me?\p"
	.string "Just joking!$"
#endif

MtChimney_Text_SawyerIntro:
#if GERMAN
	.string "Dies ist ein schöner Berg! Hier gibt es\n"
	.string "viele interessante Leute, die einem\l"
	.string "Gesellschaft leisten.$"
#else
	.string "This is one fine mountain! Plenty of\n"
	.string "hot people around for company!$"
#endif

MtChimney_Text_SawyerDefeat:
#if GERMAN
	.string "Oh, du bist auch ein richtiger\n"
	.string "Heißsporn.$"
#else
	.string "Oh, you're a real firebrand, too!$"
#endif

MtChimney_Text_SawyerPostBattle:
#if GERMAN
	.string "Ich glaube, ich tauche mal in den\n"
	.string "Heißen Quellen von Bad Lavastadt ab.$"
#else
	.string "I think I need a dip in LAVARIDGE\n"
	.string "HOT SPRING with the locals!$"
#endif

MtChimney_Text_SawyerRegister:
#if GERMAN
	.string "Ich mag Hitzköpfe wie dich.\n"
	.string "Ich trage dich in meinen PokéCom ein.$"
#else
	.string "I like little fireballs like you.\n"
	.string "Let me register you in my POKéGEAR.$"
#endif

MtChimney_Text_SawyerRematchIntro:
#if GERMAN
	.string "Ich freue mich, denn hier gibt es viele\n"
	.string "hitzköpfige Menschen.\l"
	.string "Ich verliere mit Sicherheit nicht.$"
#else
	.string "I'm happily surrounded by hot people\n"
	.string "around these parts. I won't lose!$"
#endif

MtChimney_Text_SawyerRematchDefeat:
#if GERMAN
	.string "Mist, du hast dich kein bisschen\n"
	.string "abgekühlt. Immer noch ein Heißsporn.$"
#else
	.string "Gosh, you're still the same\n"
	.string "firebrand as before!$"
#endif

MtChimney_Text_SawyerPostRematch:
#if GERMAN
	.string "Hier ist es wirklich sehr heiß. Und ich\n"
	.string "bin absolut zu warm angezogen für diese\l"
	.string "Gegend.$"
#else
	.string "Actually, it really is hot here.\n"
	.string "I'm overdressed for these parts.$"
#endif
