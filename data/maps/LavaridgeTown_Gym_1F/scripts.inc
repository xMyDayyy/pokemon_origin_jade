LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
#if IS_HNS
	setvar VAR_0x8004, LIC_STRENGTH
	special SetHoennLicense
#endif
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	setvar VAR_0x8004, 3
	special SetHoennBadge
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem_unless_owned ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem_unless_owned ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_COLE, TRAINER_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_AXLE, TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_KEEGAN, TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_DANIELLE, TRAINER_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_GERALD, TRAINER_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JACE, TRAINER_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JEFF, TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_ELI, TRAINER_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
#if IS_HNS
	@ Hoenn badge 4 (Flannery)
	setvar VAR_0x8004, 3
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
#else
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
#endif
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
#if IS_HNS
	@ Hoenn badge 4 (Flannery)
	setvar VAR_0x8004, 3
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
#else
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
#endif
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
#if GERMAN
	.string "Na, wie sieht es aus, auf dem Weg zum\n"
	.string "Champ, {PLAYER}?\p"
	.string "Die Arenaleiterin von Bad Lavastadt,\n"
	.string "Flavia, setzt Feuer-Pokémon ein.\p"
	.string "Ihre Leidenschaft für Pokémon brennt\n"
	.string "heißer und stärker als ein Vulkan.\p"
	.string "Komm ihr nicht zu nahe - du verbrennst\n"
	.string "dich! Lösche die Glut mit Wasser und\l"
	.string "dann besiege sie!$"
#else
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "LAVARIDGE's GYM LEADER FLANNERY\n"
	.string "uses FIRE-type POKéMON.\p"
	.string "Her passion for POKéMON burns stronger\n"
	.string "and hotter than a volcano.\p"
	.string "Don't get too close to her--you'll burn!\n"
	.string "Hose her down with water and then\l"
	.string "go for it!$"
#endif

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
#if GERMAN
	.string "Hui! Das war ein glühend heißer Kampf!$"
#else
	.string "Yow! That was a scorching-hot battle!$"
#endif

LavaridgeTown_Gym_1F_Text_ColeIntro:
#if GERMAN
	.string "Auauauauau! Hach, ist das heiß!$"
#else
	.string "Owowowowow!\n"
	.string "Yikes, it's hot!$"
#endif

LavaridgeTown_Gym_1F_Text_ColeDefeat:
#if GERMAN
	.string "Der Schweiß lief mir in die Augen…$"
#else
	.string "I'm blinded by sweat in my eyes…$"
#endif

LavaridgeTown_Gym_1F_Text_ColePostBattle:
#if GERMAN
	.string "Ein Bad im heißen Sand regt den\n"
	.string "Kreislauf an.\p"
	.string "Auch Gelenkschmerzen lassen sich damit\n"
	.string "kurieren.$"
#else
	.string "Being buried in hot sand promotes\n"
	.string "circulation.\p"
	.string "It's effective for healing pain in\n"
	.string "your joints.$"
#endif

LavaridgeTown_Gym_1F_Text_AxleIntro:
#if GERMAN
	.string "Ich versuche, Stress abzubauen.\n"
	.string "Komm her. Ich will mich abreagieren.$"
#else
	.string "I'm trying to relieve my stress.\n"
	.string "Don't come along and stress me out!$"
#endif

LavaridgeTown_Gym_1F_Text_AxleDefeat:
#if GERMAN
	.string "Ich hoffe, Flavia wird dich rösten!$"
#else
	.string "I hope FLANNERY flames you good!$"
#endif

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
#if GERMAN
	.string "Haaah… Huuuuh…\p"
	.string "Bleibt man zu lange im heißen Sand,\n"
	.string "macht einen das ganz schön fertig.$"
#else
	.string "Haaah… Whew…\p"
	.string "If you spend too much time buried in\n"
	.string "hot sand, it tuckers you out…$"
#endif

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
#if GERMAN
	.string "Du musst ganz schön müde sein.\n"
	.string "Willst du dich nicht hier im heißen Sand\l"
	.string "ausruhen?\p"
	.string "Aber du solltest wissen, dass\n"
	.string "Willenskraft ganz wichtig für einen\l"
	.string "Trainer ist.$"
#else
	.string "You must be getting tired by now.\n"
	.string "You'd like to rest in the hot sand,\l"
	.string "wouldn't you?\p"
	.string "But you should know that maintaining\n"
	.string "your willpower is an important ability\l"
	.string "for all TRAINERS.$"
#endif

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
#if GERMAN
	.string "Spiele mit Feuer und du verbrennst\n"
	.string "dich.$"
#else
	.string "Play with fire, and be burned…$"
#endif

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
#if GERMAN
	.string "Dein Können ist gut… Aber unsere\n"
	.string "Leiterin Flavia ist stark.\p"
	.string "Wenn du nicht aufpasst, verbrennst\n"
	.string "du dich ernsthaft.$"
#else
	.string "Your skill is real…\n"
	.string "But our LEADER FLANNERY is strong.\p"
	.string "If you don't watch yourself, you'll be\n"
	.string "burned seriously.$"
#endif

LavaridgeTown_Gym_1F_Text_GeraldIntro:
#if GERMAN
	.string "Kann dein Pokémon 200 Grad aushalten?$"
#else
	.string "Can your POKéMON withstand\n"
	.string "392-degree heat?$"
#endif

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
#if GERMAN
	.string "Die Hitze war nicht stark genug…$"
#else
	.string "It didn't burn hotly enough…$"
#endif

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
#if GERMAN
	.string "Die Temperatur von Magma beträgt\n"
	.string "über 200 Grad.\p"
	.string "Deine Pokémon haben mich besiegt, sie\n"
	.string "sollten auch in Magma überleben können.$"
#else
	.string "The temperature of magma is\n"
	.string "392 degrees.\p"
	.string "Your POKéMON beat me, so they should\n"
	.string "easily survive in magma.$"
#endif

LavaridgeTown_Gym_1F_Text_DanielleIntro:
#if GERMAN
	.string "Ähm… Okay, ich kämpfe mit dir.$"
#else
	.string "Um…\n"
	.string "Okay, I'll battle with you.$"
#endif

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
#if GERMAN
	.string "Oh, du bist zu stark.$"
#else
	.string "Oh, but you're too strong.$"
#endif

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
#if GERMAN
	.string "Ich will einmal so eine starke\n"
	.string "Trainerin werden wie Flavia.$"
#else
	.string "I'm going to be a pretty and strong\n"
	.string "TRAINER just like FLANNERY.$"
#endif

LavaridgeTown_Gym_B1F_Text_JaceIntro:
#if GERMAN
	.string "Komm schon! Los geht’s!\n"
	.string "Bevor ich abkühle.$"
#else
	.string "Come on, get with it!\n"
	.string "Let's go before my feelings cool!$"
#endif

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
#if GERMAN
	.string "Es ist so heiß und doch ist mein Herz\n"
	.string "von Eis umgeben…$"
#else
	.string "It's so hot, and yet my heart is\n"
	.string "clutched by ice…$"
#endif

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
#if GERMAN
	.string "Dein Kampfstil ist feurig, ich denke, du\n"
	.string "hast eine gute Chance gegen unsere\l"
	.string "Arenaleiterin.$"
#else
	.string "The way the battling spirit burns\n"
	.string "within you, you may stand a chance\l"
	.string "against our LEADER.$"
#endif

LavaridgeTown_Gym_B1F_Text_JeffIntro:
#if GERMAN
	.string "Siehst du, wie wild die Flammen\n"
	.string "züngeln? Sie bejubeln meinen Sieg!$"
#else
	.string "See how the flames blaze wildly?\n"
	.string "They flare in anticipation of my win!$"
#endif

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
#if GERMAN
	.string "Irgendwas ist da schief gelaufen.$"
#else
	.string "Something didn't go right.$"
#endif

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
#if GERMAN
	.string "Ach, was soll’s?!? Mir doch egal.\n"
	.string "Dafür kann ich barfuß über glühende\l"
	.string "Kohlen laufen. … Versuch das bloß nicht!$"
#else
	.string "Well, so what? I say so what?\n"
	.string "I can walk on hot coals barefoot!\p"
	.string "…Don't even think about trying it!$"
#endif

LavaridgeTown_Gym_B1F_Text_EliIntro:
#if GERMAN
	.string "So sehr ich die Berge auch liebe, meine\n"
	.string "Leidenschaft gehört den Vulkanen.$"
#else
	.string "As much as I love mountains,\n"
	.string "I especially love volcanoes.$"
#endif

LavaridgeTown_Gym_B1F_Text_EliDefeat:
#if GERMAN
	.string "Ich habe verloren. Ich hatte nicht\n"
	.string "einmal den Kampf unter Kontrolle.$"
#else
	.string "Well, it seems to me I lost without\n"
	.string "ever being in control.$"
#endif

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
#if GERMAN
	.string "Ich bleibe hier, weil ich Flavias\n"
	.string "Kraft bewundere.\p"
	.string "Hähähähä…$"
#else
	.string "I stay here because I became a fan\n"
	.string "of FLANNERY's power.\p"
	.string "Hehehehe.$"
#endif

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
#if GERMAN
	.string "Willkommen… Halt, warte!\p"
	.string "Hallo, du Winzling von Trainer, wie\n"
	.string "schön, dich hier zu sehen!\p"
	.string "Ich bin verantwortlich für, äh…\n"
	.string "Nein, warte.\p"
	.string "Ich bin Flavia und ich bin die Arena-\n"
	.string "leiterin hier!\p"
	.string "Äh… Du solltest mich nicht\n"
	.string "unterschätzen, nur weil ich noch nicht\l"
	.string "so lange Leiterin bin!\p"
	.string "Ich habe das Talent meines Großvaters\n"
	.string "geerbt und daher… äh… kann ich dir die\l"
	.string "heißen Attacken zeigen, die wir hier\l"
	.string "entwickelt haben!$"
#else
	.string "Welcome… No, wait.\p"
	.string "Puny TRAINER, how good to see you've\n"
	.string "made it here!\p"
	.string "I have been entrusted with the…\n"
	.string "No, wait.\p"
	.string "I am FLANNERY, and I'm the GYM\n"
	.string "LEADER here!\p"
	.string "Uh…\n"
	.string "Dare not underestimate me, though\l"
	.string "I have been LEADER only a short time!\p"
	.string "With skills inherited from my grand-\n"
	.string "father, I shall, uh…demonstrate the\l"
	.string "hot moves we have honed on this land!$"
#endif

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
#if GERMAN
	.string "Äh…\n"
	.string "Ich glaube, ich habe es übertrieben…\p"
	.string "Ich… Ich bin ja auch noch nicht lange\n"
	.string "Arenaleiterin!\p"
	.string "Ich habe zu sehr versucht, jemand zu\n"
	.string "sein, der ich gar nicht bin.\p"
	.string "Ich muss die Dinge auf meine eigene Art\n"
	.string "angehen. Sonst verwirre ich nur meine\l"
	.string "Pokémon.\p"
	.string "Danke, dass du mich das gelehrt hast!\n"
	.string "Du hast dir das hier wohl verdient!$"
#else
	.string "Oh…\n"
	.string "I guess I was trying too hard…\p"
	.string "I… I've only recently become\n"
	.string "a GYM LEADER.\p"
	.string "I tried too hard to be someone\n"
	.string "I'm not.\p"
	.string "I have to do things my natural way. If\n"
	.string "I don't, my POKéMON will be confused.\p"
	.string "Thanks for teaching me that.\n"
	.string "For that, you deserve this.$"
#endif

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
#if GERMAN
	.string "{PLAYER} erhält den Hitzeorden\n"
	.string "von Flavia.$"
#else
	.string "{PLAYER} received the HEAT BADGE\n"
	.string "from FLANNERY.$"
#endif

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
#if GERMAN
	.string "Der Hitzeorden ist der Beweis, dass\n"
	.string "du mich geschlagen hast.\p"
	.string "In Hoenn gilt er außerdem als\n"
	.string "Erlaubnis, Stärke einzusetzen.\p"
	.string "Dies ist das Zeichen meiner\n"
	.string "Anerkennung. Nimm es ruhig an!$"
#else
	.string "The HEAT BADGE is proof that you\n"
	.string "defeated me.\p"
	.string "In HOENN it also serves as your\n"
	.string "permission to use STRENGTH.\p"
	.string "This is a token of my appreciation.\n"
	.string "Don't be shy about taking it!$"
#endif

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
#if GERMAN
	.string "Die TM50 enthält Hitzekoller.\p"
	.string "Diese Attacke richtet beim Gegner\n"
	.string "großen Schaden an.\p"
	.string "Aber gleichzeitig wird der SP. ANG.\n"
	.string "des Pokémon, das die Attacke\p"
	.string "anwendet, herabgesetzt. Für längere\n"
	.string "Kämpfe ist sie daher nicht geeignet.$"
#else
	.string "That TM50 contains OVERHEAT.\p"
	.string "That move inflicts serious damage on\n"
	.string "the opponent.\p"
	.string "But it also sharply cuts the SP. ATK\n"
	.string "of the POKéMON using it. It might not\l"
	.string "be suitable for longer battles.$"
#endif

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
#if GERMAN
	.string "Arenaleiterin Flavia wurde im PokéCom\n"
	.string "eingetragen.$"
#else
	.string "Registered GYM LEADER FLANNERY\n"
	.string "in the POKéGEAR.$"
#endif

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
#if GERMAN
	.string "Deine Stärke erinnert mich an\n"
	.string "jemanden…\p"
	.string "Jetzt weiß ich’s! Du kämpfst wie Norman,\n"
	.string "der Arenaleiter von Blütenburg City.$"
#else
	.string "Your power reminds me of someone…\p"
	.string "Oh! I know! You battle like NORMAN,\n"
	.string "the GYM LEADER of PETALBURG.$"
#endif

LavaridgeTown_Gym_1F_Text_GymStatue:
#if GERMAN
	.string "Pokémon Arena von Bad Lavastadt$"
#else
	.string "LAVARIDGE TOWN POKéMON GYM$"
#endif

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon Arena von Bad Lavastadt\p"
	.string "Flavias anerkannte Trainer:\n"
	.string "{PLAYER}$"
#else
	.string "LAVARIDGE TOWN POKéMON GYM\p"
	.string "FLANNERY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
#if GERMAN
	.string "Flavia: Eine Niederlage wird mein\n"
	.string "Feuer nicht löschen.\p"
	.string "Ich liebe Pokémon.\n"
	.string "Ich liebe Kämpfe.\l"
	.string "Und… Ich liebe diese Arena!\p"
	.string "Lass uns einen ultraheißen Kampf\n"
	.string "austragen! Die Funken sollen fliegen.$"
#else
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!$"
#endif

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
#if GERMAN
	.string "Wow!\n"
	.string "Da stand einer kurz vor dem Ausbruch!$"
#else
	.string "Whew!\n"
	.string "On the verge of eruption!$"
#endif

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
#if GERMAN
	.string "Flavia: Ich habe den Kampf zwar\n"
	.string "verloren, bin aber dennoch zufrieden.\l"
	.string "\p"
	.string "Ich habe nicht oft die Gelegenheit,\n"
	.string "einen so heißen Kampf zu genießen.\p"
	.string "Das müssen wir unbedingt wiederholen!\n"
	.string "Komm bald wieder!$"
#else
	.string "FLANNERY: I lost the match,\n"
	.string "but I'm completely satisfied.\p"
	.string "It's not often I get to enjoy a battle\n"
	.string "this heated.\p"
	.string "Let's have another one like this\n"
	.string "again sometime!$"
#endif

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
#if GERMAN
	.string "Flavia: Eine Niederlage wird mein\n"
	.string "Feuer nicht löschen.\p"
	.string "Ich liebe Pokémon.\n"
	.string "Ich liebe Kämpfe.\l"
	.string "Und… Ich liebe diese Arena!\p"
	.string "Lass uns einen ultraheißen Kampf\n"
	.string "austragen! Die Funken sollen fliegen.\l"
	.string "\p"
	.string "Moment! Warte mal! Du hast ja nur ein\n"
	.string "Pokémon, das kämpfen kann, dabei!\p"
	.string "Bring das nächste Mal mindestens zwei\n"
	.string "Pokémon mit, sonst wird das nichts.$"
#else
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!\p"
	.string "Oh, wait. Do you only have one POKéMON\n"
	.string "that can battle?\p"
	.string "I hate to say this, but when you come\n"
	.string "see me, bring at least two POKéMON.$"
#endif
