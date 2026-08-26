Route24_Frlg_MapScripts::
	.byte 0

Route24_EventScript_Rocket::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ROUTE24, 1, Route24_EventScript_RocketPostBattle
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
	call Route24_EventScript_BattleRocket
	release
	end

Route24_EventScript_NoRoomForNugget::
	msgbox Route24_Text_YouDontHaveAnyRoom
	release
	end

Route24_EventScript_RocketPostBattle::
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	release
	end

Route24_EventScript_BattleRocket::
	giveitem_msg Route24_Text_ReceivedNuggetFromMysteryTrainer, ITEM_NUGGET
	message Route24_Text_JoinTeamRocket
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_ROUTE24_ROCKET
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketDefeat
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	setvar VAR_MAP_SCENE_ROUTE24, 1
	return

Route24_EventScript_NoRoomForNuggetTrigger::
	msgbox Route24_Text_YouDontHaveAnyRoom
	closemessage
	applymovement LOCALID_PLAYER, Route24_Movement_WalkDown
	waitmovement 0
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketWalkBackToPos
	release
	end

Route24_EventScript_RocketWalkBackToPos::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketWalkBackToPos
	waitmovement 0
	return


Route24_Movement_RocketWalkBackToPos::
	walk_right
	walk_in_place_faster_left
	step_end

Route24_Movement_WalkDown::
	walk_down
	step_end

Route24_Text_JustEarnedFabulousPrize::
#if GERMAN
	.string "Herzlichen Glückwunsch!\n"
	.string "Du hast alle fünf Trainer besiegt!\p"
	.string "Du hast einen großartigen Preis\n"
	.string "gewonnen!$"
#else
	.string "Congratulations! You beat our\n"
	.string "five contest TRAINERS!\p"
	.string "You just earned a fabulous prize!$"
#endif

Route24_Text_ReceivedNuggetFromMysteryTrainer::
#if GERMAN
	.string "{PLAYER} erhält ein Nugget!$"
#else
	.string "{PLAYER} received a NUGGET\n"
	.string "from the mystery TRAINER!$"
#endif

Route24_Text_YouDontHaveAnyRoom::
#if GERMAN
	.string "Du hast keinen Platz für weitere\n"
	.string "Items!$"
#else
	.string "You don't have any room!$"
#endif

Route24_Text_JoinTeamRocket::
#if GERMAN
	.string "Möchtest du auch Mitglied des Team\n"
	.string "Rocket werden?\p"
	.string "Unsere Gruppierung benutzt Pokémon\n"
	.string "für teuflische Zwecke!\p"
	.string "Möchtest du beitreten?\p"
	.string "Wirklich nicht?\p"
	.string "Komm schon, werde Mitglied!\p"
	.string "Ich empfehle dir, ein Mitglied zu\n"
	.string "werden!\p"
	.string "Ich glaube, ich sollte ein wenig\n"
	.string "Überzeugungsarbeit leisten!\p"
	.string "Dieses Angebot kannst du nicht\n"
	.string "ablehnen!$"
#else
	.string "By the way, how would you like to\n"
	.string "join TEAM ROCKET?\p"
	.string "We're a group of professional\n"
	.string "criminals specializing in POKéMON!\p"
	.string "Want to join?\p"
	.string "Are you sure?\p"
	.string "Come on, join us!\p"
	.string "I'm telling you to join!\p"
	.string "…Okay, you need convincing!\p"
	.string "I'll make you an offer you can't\n"
	.string "refuse!$"
#endif

Route24_Text_RocketDefeat::
#if GERMAN
	.string "Arrgh!\n"
	.string "Du bist gut!$"
#else
	.string "Arrgh!\n"
	.string "You are good!$"
#endif

Route24_Text_YoudBecomeTopRocketLeader::
#if GERMAN
	.string "Bei deinem Können wärst du im Team\n"
	.string "Rocket leicht die rechte Hand vom Boss!\p"
	.string "Denke darüber nach! Lass dir diese\n"
	.string "Chance nicht entgehen!$"
#else
	.string "With your ability, you'd become\n"
	.string "a top leader in TEAM ROCKET.\p"
	.string "Come on, think of the opportunity!\n"
	.string "Don't let this chance go to waste.$"
#endif

Route24_Text_ShaneIntro::
#if GERMAN
	.string "Ich habe deine Vorstellung aus dem\n"
	.string "Gras heraus beobachtet!$"
#else
	.string "I saw your feat from the grass!$"
#endif

Route24_Text_ShaneDefeat::
#if GERMAN
	.string "Ich habe wohl doch nichts gesehen!$"
#else
	.string "I thought not!$"
#endif

Route24_Text_ShanePostBattle::
#if GERMAN
	.string "Ich habe mich versteckt, weil mir die\n"
	.string "Leute auf der Brücke Angst gemacht\l"
	.string "haben!$"
#else
	.string "I hid because the people on the\n"
	.string "bridge frightened me.$"
#endif

Route24_Text_EthanIntro::
#if GERMAN
	.string "Ich bin Nr. 5!\n"
	.string "Dich mache ich platt!$"
#else
	.string "Okay! I'm No. 5!\n"
	.string "I'll stomp you!$"
#endif

Route24_Text_EthanDefeat::
#if GERMAN
	.string "Das war zu viel des Guten!$"
#else
	.string "Whoa!\n"
	.string "Too much!$"
#endif

Route24_Text_EthanPostBattle::
#if GERMAN
	.string "Ich habe alles gegeben, ich schäme\n"
	.string "mich nicht!$"
#else
	.string "I did my best. I have no regrets!$"
#endif

Route24_Text_ReliIntro::
#if GERMAN
	.string "Ich bin Nr. 4!\n"
	.string "Wirst du müde?$"
#else
	.string "I'm No. 4!\n"
	.string "Getting tired?$"
#endif

Route24_Text_ReliDefeat::
#if GERMAN
	.string "Ich habe auch verloren!$"
#else
	.string "I lost, too!$"
#endif

Route24_Text_ReliPostBattle::
#if GERMAN
	.string "Ich habe alles gegeben, ich schäme\n"
	.string "mich nicht!$"
#else
	.string "I did my best, so I've no regrets!$"
#endif

Route24_Text_TimmyIntro::
#if GERMAN
	.string "Hier kommt Nr. 3!\n"
	.string "Ich mache dir das Leben schwer!$"
#else
	.string "Here's No. 3!\n"
	.string "I won't be easy!$"
#endif

Route24_Text_TimmyDefeat::
#if GERMAN
	.string "Ah!\n"
	.string "Eiskalt erwischt!$"
#else
	.string "Ow!\n"
	.string "Stomped flat!$"
#endif

Route24_Text_TimmyPostBattle::
#if GERMAN
	.string "Ich habe alles gegeben, ich schäme\n"
	.string "mich nicht!$"
#else
	.string "I did my best. I have no regrets!$"
#endif

Route24_Text_AliIntro::
#if GERMAN
	.string "Ich bin Nr. 2!\n"
	.string "Nun wird es ernst!$"
#else
	.string "I'm second!\n"
	.string "Now it's serious!$"
#endif

Route24_Text_AliDefeat::
#if GERMAN
	.string "Wie konnte ich verlieren?$"
#else
	.string "How could I lose?$"
#endif

Route24_Text_AliPostBattle::
#if GERMAN
	.string "Ich habe alles gegeben, ich schäme\n"
	.string "mich nicht!$"
#else
	.string "I did my best. I have no regrets!$"
#endif

Route24_Text_CaleIntro::
#if GERMAN
	.string "Das hier ist die Nugget-brücke!\n"
	.string "Wenn du uns fünf Trainer besiegst,\l"
	.string "erhältst du einen wertvollen Preis!\p"
	.string "Willst du dein Glück versuchen?$"
#else
	.string "People call this the NUGGET\n"
	.string "BRIDGE!\p"
	.string "Beat us five TRAINERS and win\n"
	.string "a fabulous prize!\p"
	.string "Think you got what it takes?$"
#endif

Route24_Text_CaleDefeat::
#if GERMAN
	.string "Wow!\n"
	.string "Du bist gut!$"
#else
	.string "Whoo!\n"
	.string "Good stuff!$"
#endif

Route24_Text_CalePostBattle::
#if GERMAN
	.string "Ich habe alles gegeben, ich schäme\n"
	.string "mich nicht!$"
#else
	.string "I did my best. I have no regrets!$"
#endif

@ Nugget-Rocket. Szene liegt im noerdlichen Teil, der von Route 25 uebernommen wurde. Der Rocket steht auf
@ (19,27), die drei Spuren liegen links von ihm auf Zeile 27. Kampf und
@ Texte kommen weiter aus Route24_Frlg/scripts.inc; BattleRocket setzt
@ VAR_MAP_SCENE_ROUTE24 auf 1 und entschaerft damit auch diese Trigger.
Route24_EventScript_RocketTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 2
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTriggerRight::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	call_if_eq VAR_TEMP_1, 2, Route24_EventScript_RocketApproach2
	call_if_eq VAR_TEMP_1, 1, Route24_EventScript_RocketApproach1
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketTurn
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNuggetTrigger
	call Route24_EventScript_BattleRocket
	releaseall
	end

Route24_EventScript_RocketApproach2::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketApproach2
	waitmovement 0
	return

Route24_EventScript_RocketApproach1::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketApproach1
	waitmovement 0
	return

Route24_EventScript_RocketTurn::
	applymovement LOCALID_ROUTE24_ROCKET, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route24_Movement_RocketApproach2:
	walk_left
	walk_left
	step_end

Route24_Movement_RocketApproach1:
	walk_left
	step_end
