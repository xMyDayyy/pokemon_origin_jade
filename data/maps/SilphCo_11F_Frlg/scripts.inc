SilphCo_11F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad::
	call_if_unset FLAG_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_AlreadyGotMasterBall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SilphCo_11F_EventScript_PresidentThanksMale
	call_if_eq VAR_RESULT, FEMALE, SilphCo_11F_EventScript_PresidentThanksFemale
	checkitemspace ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, FALSE, SilphCo_11F_EventScript_NoRoomForMasterBall
	giveitem_msg SilphCo_11F_Text_ObtainedMasterBallFromPresident, ITEM_MASTER_BALL, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_GOT_MASTER_BALL_FROM_SILPH
	release
	end

SilphCo_11F_EventScript_PresidentThanksMale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearBoy
	return

SilphCo_11F_EventScript_PresidentThanksFemale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearGirl
	return

SilphCo_11F_EventScript_NoRoomForMasterBall::
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall::
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary::
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_GiovanniTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_SILPH_CO_GIOVANNI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	call_if_eq VAR_TEMP_1, 0, SilphCo_11F_EventScript_GiovanniApproachLeft
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPH_CO_GIOVANNI
	removeobject LOCALID_SILPH_CO_11F_GRUNT1
	removeobject LOCALID_SILPH_CO_11F_GRUNT2
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_SILPH_CO_11F, 1
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	@ Origin Jade: the president takes the Card Key back. Johto's Radio Tower
	@ checks the bag for the director's Card Key.
	checkitem ITEM_CARD_KEY
	call_if_eq VAR_RESULT, TRUE, SilphCo_11F_EventScript_ReturnCardKey
	releaseall
	end

SilphCo_11F_EventScript_ReturnCardKey::
	msgbox SilphCo_11F_Text_PresidentWantsCardKey
	textcolor NPC_TEXT_COLOR_NEUTRAL
	removeitem ITEM_CARD_KEY
	msgbox SilphCo_11F_Text_ReturnedCardKey
	closemessage
	call EventScript_RestorePrevTextColor
	return

SilphCo_11F_EventScript_GiovanniApproachLeft::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement LOCALID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 0
	return

SilphCo_11F_EventScript_GiovanniApproachRight::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 0
	return

SilphCo_11F_Movement_GiovanniApproachLeft::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight::
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni::
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_right
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor::
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat
	msgbox SilphCo_11F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_Text_ThanksForSavingMeDearBoy::
#if GERMAN
	.string "Präsident: Ich danke dir für die\n"
	.string "Rettung der Silph Co.\p"
	.string "Ich werde niemals vergessen, wie du uns\n"
	.string "trotz größter Gefahren tapfer\l"
	.string "gerettet hast!\p"
	.string "Wie kann ich dir bloß meinen Dank\n"
	.string "aussprechen?\p"
	.string "Ich bin reich, ich könnte dir alles\n"
	.string "geben!\p"
	.string "Aber vielleicht ist das hier eher\n"
	.string "etwas für dich!$"
#else
	.string "PRESIDENT: Oh, dear boy!\n"
	.string "Thank you for saving SILPH.\p"
	.string "I will never forget you saved us in\n"
	.string "our moment of peril.\p"
	.string "I have to thank you in some way.\p"
	.string "Because I am rich, I can give you\n"
	.string "anything.\p"
	.string "Here, maybe this will do.$"
#endif

SilphCo_11F_Text_ThanksForSavingMeDearGirl::
#if GERMAN
	.string "Präsident: Ich danke dir für die\n"
	.string "Rettung der Silph Co.\p"
	.string "Ich werde niemals vergessen, wie du uns\n"
	.string "trotz größter Gefahren tapfer\l"
	.string "gerettet hast!\p"
	.string "Wie kann ich dir bloß meinen Dank\n"
	.string "aussprechen?\p"
	.string "Ich bin reich, ich könnte dir alles\n"
	.string "geben!\p"
	.string "Aber vielleicht ist das hier eher\n"
	.string "etwas für dich!$"
#else
	.string "PRESIDENT: Oh, dear girl!\n"
	.string "Thank you for saving SILPH.\p"
	.string "I will never forget you saved us in\n"
	.string "our moment of peril.\p"
	.string "I have to thank you in some way.\p"
	.string "Because I am rich, I can give you\n"
	.string "anything.\p"
	.string "Here, maybe this will do.$"
#endif

SilphCo_11F_Text_ObtainedMasterBallFromPresident::
#if GERMAN
	.string "{PLAYER} erhält Meisterball!$"
#else
	.string "{PLAYER} obtained a MASTER BALL\n"
	.string "from the PRESIDENT!$"
#endif

SilphCo_11F_Text_ThatsOurSecretPrototype::
#if GERMAN
	.string "Präsident: Man kann das nirgends\n"
	.string "kaufen!\p"
	.string "Es ist der streng geheime Prototyp\n"
	.string "des Meisterballs!\p"
	.string "Du kannst mit ihm jedes Pokémon\n"
	.string "Beim 1. Versuch einfangen!\p"
	.string "Wäge jedoch sorgfältig ab, wann du\n"
	.string "ihn einsetzt!$"
#else
	.string "PRESIDENT: You can't buy that\n"
	.string "anywhere.\p"
	.string "It's our secret prototype MASTER\n"
	.string "BALL.\p"
	.string "It will catch any POKéMON without\n"
	.string "fail!\p"
	.string "You should be quiet about using it,\n"
	.string "though.$"
#endif

SilphCo_11F_Text_PresidentWantsCardKey::
#if GERMAN
	.string "Präsident: Den Türöffner brauchst\n"
	.string "du jetzt nicht mehr.\l"
	.string "Gibst du ihn mir bitte zurück?$"
#else
	.string "PRESIDENT: You won't need the\n"
	.string "CARD KEY any more.\l"
	.string "Could you give it back, please?$"
#endif

SilphCo_11F_Text_ReturnedCardKey::
#if GERMAN
	.string "{PLAYER} gibt den Türöffner zurück.$"
#else
	.string "{PLAYER} returned the CARD KEY.$"
#endif

SilphCo_11F_Text_YouHaveNoRoomForThis::
#if GERMAN
	.string "Du hast keinen Platz mehr!$"
#else
	.string "You have no room for this.$"
#endif

SilphCo_11F_Text_ThanksForRescuingUs::
#if GERMAN
	.string "Sekretärin: Wir danken dir für\n"
	.string "deinen Heldenmut!\p"
	.string "Du hast uns alle gerettet!\n"
	.string "Danke!$"
#else
	.string "SECRETARY: Thank you for rescuing\n"
	.string "all of us.\p"
	.string "We, from the PRESIDENT down,\n"
	.string "are indebted to you.$"
#endif

SilphCo_11F_Text_GiovanniIntro::
#if GERMAN
	.string "Ah, {PLAYER}!\n"
	.string "So trifft man sich wieder!\p"
	.string "Ich führe gerade äußerst wichtige\n"
	.string "Verhandlungen mit dem Präsidenten.\p"
	.string "Halte dich ein für allemal aus den\n"
	.string "Geschäften Erwachsener heraus!\p"
	.string "Oder du lernst eine Welt voller\n"
	.string "Schmerzen kennen!$"
#else
	.string "Ah, {PLAYER}!\n"
	.string "So we meet again!\p"
	.string "The PRESIDENT and I are discussing\n"
	.string "a vital business proposition.\p"
	.string "Keep your nose out of grown-up\n"
	.string "matters…\p"
	.string "Or, experience a world of pain!$"
#endif

SilphCo_11F_Text_GiovanniDefeat::
#if GERMAN
	.string "Arrgh!\n"
	.string "Wieder verloren!$"
#else
	.string "Arrgh!!\n"
	.string "I lost again!?$"
#endif

SilphCo_11F_Text_GiovanniPostBattle::
#if GERMAN
	.string "Verdammter Mist!\n"
	.string "Du hast unsere Übernahme der Silph Co.\l"
	.string "vereitelt!\p"
	.string "Aber das Team Rocket wird niemals\n"
	.string "aufgeben!\p"
	.string "{PLAYER}! Vergiss nicht, dass alle\n"
	.string "Pokémon nur zum Nutzen des Team\l"
	.string "Rocket da sind!\p"
	.string "Ich muss gehen, aber meine Zeit\n"
	.string "wird kommen!$"
#else
	.string "Blast it all!\n"
	.string "You ruined our plans for SILPH!\p"
	.string "But, TEAM ROCKET will never fall!\p"
	.string "{PLAYER}! Never forget that all\n"
	.string "POKéMON exist for TEAM ROCKET!\p"
	.string "I must go, but I shall return!$"
#endif

SilphCo_11F_Text_Grunt2Intro::
#if GERMAN
	.string "Halt!\n"
	.string "Keinen Schritt weiter!$"
#else
	.string "Stop right there!\n"
	.string "Don't you move!$"
#endif

SilphCo_11F_Text_Grunt2Defeat::
#if GERMAN
	.string "Bitte!\n"
	.string "Verschone mich...$"
#else
	.string "Don't…\n"
	.string "Please!$"
#endif

SilphCo_11F_Text_Grunt2PostBattle::
#if GERMAN
	.string "Du willst also zum Boss?$"
#else
	.string "So, you want to see my BOSS?$"
#endif

SilphCo_11F_Text_Grunt1Intro::
#if GERMAN
	.string "Stopp!\n"
	.string "Hast du einen Termin beim Boss?$"
#else
	.string "Halt! Do you have an appointment\n"
	.string "with my BOSS?$"
#endif

SilphCo_11F_Text_Grunt1Defeat::
#if GERMAN
	.string "O.k.!\n"
	.string "Ich lasse dich durch!$"
#else
	.string "Gaah!\n"
	.string "Demolished!$"
#endif

SilphCo_11F_Text_Grunt1PostBattle::
#if GERMAN
	.string "Die Pokémon von unserem Boss\n"
	.string "werden dich fertig machen!$"
#else
	.string "Watch your step…\n"
	.string "My BOSS likes his POKéMON tough!$"
#endif

SilphCo_11F_Text_MonitorHasMonsOnIt::
#if GERMAN
	.string "Auf dem Monitor sind Pokémon zu\n"
	.string "sehen!$"
#else
	.string "The monitor has POKéMON on it!$"
#endif

SilphCo_11F_Text_FloorSign::
#if GERMAN
	.string "Silph Co. Hauptsitz\n"
	.string "10 Og$"
#else
	.string "SILPH CO. HEAD OFFICE\n"
	.string "11F$"
#endif

