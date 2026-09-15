OlivineCity_Gym_hns_MapScripts::
	.byte 0

OlivineCity_Gym_EventScript_Gent::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Gent2
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Gent2::
	msgbox OlivineCity_Gym_Text_Gent2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_TriggerRow1::
	lock
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC1
	playse SE_PIN
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
	waitmovement VAR_TEMP_0
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveLeft4
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveLeft3
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveLeft2
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveLeft1
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveLeft0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 6
	release
	end

OlivineCity_Gym_EventScript_MoveLeft0::
	turnobject VAR_TEMP_0, DIR_WEST
	return

OlivineCity_Gym_EventScript_MoveLeft1::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft2::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft3::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft4::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_Text_Gent:
#if GERMAN
	.string "So so, du bist also wirklich gekommen.\p"
	.string "Du magst der Arenaleiterin vielleicht\n"
	.string "geholfen haben, aber in der Arena gilt\l"
	.string "immer noch das Gesetz des Stärkeren!\p"
	.string "Kämpfe entweder richtig oder gar nicht!$"
#else
	.string "I knew you'd come here.\p"
	.string "Thank you for helping the GYM LEADER,\n"
	.string "but battle is a separate matter.\p"
	.string "Go for it!$"
#endif

OlivineCity_Gym_Text_Gent2:
#if GERMAN
	.string "Das war ausgezeichnet! So solltest du\n"
	.string "auf deiner Reise keine Probleme haben!\p"
	.string "Und wo du nun schon mal im Besitz von\n"
	.string "Surfer bist, solltest du auch mal am See\l"
	.string "des Zorns vorbeischauen!$"
#else
	.string "Impressive!\n"
	.string "You should continue your journey to\l"
	.string "different places.\p"
	.string "Since you can use SURF, why don't you\n"
	.string "try it on the LAKE OF RAGE?$"
#endif

OlivineCity_Gym_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Lass2
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Lass2::
	msgbox OlivineCity_Gym_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_TriggerRow2::
	lock
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC2
	playse SE_PIN
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
	waitmovement VAR_TEMP_0
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveRight0
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveRight1
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveRight2
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveRight3
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveRight4
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 7
	release
	end

OlivineCity_Gym_EventScript_MoveRight0::
	turnobject VAR_TEMP_0, DIR_EAST
	return

OlivineCity_Gym_EventScript_MoveRight1::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight2::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight3::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight4::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_Text_Lass:
#if GERMAN
	.string "Hehe! Du hast mir im Leuchtturm bereits\n"
	.string "bewiesen, wie stark du wirklich bist.\p"
	.string "Aber du wirst all deine Kraft brauchen,\n"
	.string "um im Kampf gegen Jasmin zu bestehen!\p"
	.string "…Ich hoffe, du gewinnst!$"
#else
	.string "Giggle...\n"
	.string "I know how capable you are\l"
	.string "from the LIGHTHOUSE.\p"
	.string "It's time you showed that side of\n"
	.string "yourself to JASMINE! Good luck!$"
#endif

OlivineCity_Gym_Text_Lass2:
#if GERMAN
	.string "Das war unbeschreiblich…\p"
	.string "So stark wie du bist, solltest du\n"
	.string "unbedingt weiterkämpfen!\p"
	.string "Warst du schon in Mahagonia City?$"
#else
	.string "You are amazing...\n"
	.string "You should aim even higher, since\l"
	.string "you have such potential.\p"
	.string "Have you been to MAHOGANY TOWN?$"
#endif

OlivineCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineCity_Gym_EventScript_GymGuideSick
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_GymGuideAfter
	msgbox OlivineCity_Gym_Text_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_GymGuideSick::
	msgbox OlivineCity_Gym_Text_GymGuidePreText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_GymGuideAfter::
	msgbox OlivineCity_Gym_Text_GymGuideWinText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_Text_GymGuideText:
#if GERMAN
	.string "Jasmin setzt den neu entdeckten\n"
	.string "Typ Stahl ein.\p"
	.string "Sie ist für gleich zwei Asse bekannt.\p"
	.string "Das erste ist ein Metallkäfer, der\n"
	.string "seinen Angriff steigern kann.\p"
	.string "Feuer setzt ihm zu, doch manchmal\n"
	.string "übersteht es selbst harte Treffer.\p"
	.string "Das zweite ist eine riesige\n"
	.string "Eisenschlange mit starken Attacken.\p"
	.string "Geh sie mit Vorsicht an.\p"
	.string "Sie wirkt träge, doch ich habe sie schon\n"
	.string "verblüffend schnell zuschlagen sehen.$"
#else
	.string "JASMINE uses the newly discovered\n"
	.string "STEEL-type.\p"
	.string "She's known for having not one,\n"
	.string "but two aces.\p"
	.string "The first is a metal bug that can\n"
	.string "use a technique to boost its ATTACK.\p"
	.string "While fire will hurt it, it can\n"
	.string "sometimes endure powerful blows.\p"
	.string "The second is a giant iron snake\n"
	.string "with lots of powerful moves.\p"
	.string "Approach it with caution.\p"
	.string "It may look slow, but I've seen it\n"
	.string "strike first with shocking displays\l"
	.string "of SPEED.$"
#endif

OlivineCity_Gym_Text_GymGuideWinText:
#if GERMAN
	.string "Das war großartig!\p"
	.string "Der Typ Stahl, was?\p"
	.string "Das war eine unheimliche Begegnung der\n"
	.string "unbekannten Art.$"
#else
	.string "That was awesome.\p"
	.string "The STEEL-type, huh?\p"
	.string "That was a close encounter of an\n"
	.string "unknown kind!$"
#endif

OlivineCity_Gym_Text_GymGuidePreText:
#if GERMAN
	.string "Wo Jasmin, die Arenaleiterin, ist?\p"
	.string "Dem Pokémon im Leuchtturm scheint es\n"
	.string "nicht sehr gut zu gehen, und sie sieht\l"
	.string "dort gerade nach dem Rechten.\p"
	.string "Ein wirklich starker Trainer muss neben\n"
	.string "Stärke auch Mitgefühl beweisen können.$"
#else
	.string "JASMINE, the GYM LEADER, is at the\n"
	.string "LIGHTHOUSE.\p"
	.string "She's been tending to a sick POKéMON.\p"
	.string "A strong trainer has to be\n"
	.string "compassionate.$"
#endif

OlivineCity_Gym_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Jasmine_Defeated
	msgbox OlivineCity_Gym_Text_JasmineSteelTypeIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_CianwoodCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_MahogCheckCianwood
	goto OlivineCity_Gym_EventScript_Jasmine_Battle1

OlivineCity_Gym_EventScript_JasmineVictory::
	message OlivineCity_Gym_Text_ReceivedMineralBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox OlivineCity_Gym_Text_JasmineBadgeSpeech, MSGBOX_DEFAULT
	setvar VAR_0x8004, 5
	special SetJohtoBadge
	setflag FLAG_BADGE06_GET
	@ Jasmine: Johto-Orden 6. Die Flag oben teilt sich Johto mit Kanto und
	@ ist nach der Kanto-Liga laengst gesetzt - gezaehlt wird in VAR_JOHTO_BADGES.
	setvar VAR_0x8004, 5
	special SetJohtoBadge
	setflag FLAG_DEFEATED_OLIVINE_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_IRON_TAIL
	msgbox OlivineCity_Gym_Text_JasmineIronTailSpeech, MSGBOX_DEFAULT
	setvar VAR_OLIVINE_CITY_STATE, 8
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

OlivineCity_Gym_EventScript_CianwoodCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2

OlivineCity_Gym_EventScript_MahogCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2

OlivineCity_Gym_EventScript_Jasmine_Battle1::
	trainerbattle_no_intro TRAINER_JASMINE_1_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Battle2::
	trainerbattle_no_intro TRAINER_JASMINE_1_2_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Battle3::
	trainerbattle_no_intro TRAINER_JASMINE_1_3_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_JASMINE, OlivineCity_Gym_EventScript_Jasmine_Trade
	msgbox OlivineCity_Gym_Text_JasmineGoodLuck, MSGBOX_DEFAULT
	closemessage
	release
	end


OlivineCity_Gym_Text_JasmineSteelTypeIntro:
#if GERMAN
	.string "…Danke für deine Hilfe am Leuchtturm…\p"
	.string "Aber das hier ist anders.\n"
	.string "Darf ich mich vorstellen?\p"
	.string "Ich bin Jasmin, Arenaleiterin.\p"
	.string "Ich nutze den Stahl-Typ.\p"
	.string "…Kennst du den Stahl-Typ?\p"
	.string "Er wurde erst kürzlich entdeckt.\p"
	.string "…Ähm… Soll ich anfangen?$"
#else
	.string "…Thank you for your help at the\n"
	.string "LIGHTHOUSE…\p"
	.string "But this is different.\n"
	.string "Please allow me to introduce myself.\p"
	.string "I am JASMINE, a GYM LEADER.\n"
	.string "I use the STEEL-type.\p"
	.string "…Do you know about the STEEL-type?\p"
	.string "It's a type that was only recently\n"
	.string "discovered.\p"
	.string "…Um… May I begin?$"
#endif

OlivineCity_Gym_Text_JasmineBetterTrainer:
#if GERMAN
	.string "Jasmin: Du scheinst der bessere Trainer\n"
	.string "von uns beiden zu sein.\p"
	.string "Das gilt sowohl für dein Geschick als\n"
	.string "auch für dein Feingefühl.\p"
	.string "In Übereinstimmung mit den Regeln der\n"
	.string "Liga überreiche ich dir diesen Orden!$"
#else
	.string "…You are a better trainer than me,\n"
	.string "in both skill and kindness.\p"
	.string "In accordance with LEAGUE rules,\n"
	.string "I confer upon you this BADGE.$"
#endif

OlivineCity_Gym_Text_ReceivedMineralBadge:
#if GERMAN
	.string "{PLAYER} erhält den Stahlorden!$"
#else
	.string "{PLAYER} received MINERALBADGE.$"
#endif

OlivineCity_Gym_Text_JasmineBadgeSpeech:
#if GERMAN
	.string "Stahlorden erhöht die\n"
	.string "Spezial-Verteidigung von Pokémon.\p"
	.string "…Ähm… Bitte nimm dies auch…$"
#else
	.string "MINERALBADGE raises POKéMON's \n"
	.string "SPECIAL DEFENSE.\p"
	.string "…Um… Please take this too…$"
#endif

OlivineCity_Gym_Text_JasmineIronTailSpeech:
#if GERMAN
	.string "…Damit kannst du die Attacke\n"
	.string "Eisenschweif lehren.$"
#else
	.string "…You could use that TM to teach\n"
	.string "IRON TAIL.$"
#endif

OlivineCity_Gym_Text_JasmineGoodLuck:
#if GERMAN
	.string "Jasmin: Ähm… ich weiß nicht, wie\n"
	.string "ich das am besten sagen soll, aber…\p"
	.string "Viel Glück!$"
#else
	.string "Um… I don't know how to say this,\n"
	.string "but good luck…$"
#endif

OlivineCity_Gym_Text_JasmineRematchText:
#if GERMAN
	.string "…Glückwunsch, Johto Champion.\p"
	.string "Du bist so stark geworden…\p"
	.string "Ich frage mich, ob ich mich verbessert\n"
	.string "habe.\p"
	.string "Willst du es testen?\p"
	.string "Willst du ein Rematch mit mir?$"
#else
	.string "…Congratulations, JOHTO CHAMPION.\p"
	.string "You have become so strong…\p"
	.string "I wonder if I have improved.\p"
	.string "Would you like to test that?\p"
	.string "Want to have a rematch with me?$"
#endif

OlivineCity_Gym_Text_JasmineRematchDefeatText:
#if GERMAN
	.string "…Du bist ein besserer Trainer\n"
	.string "als ich, in Können und Herz.$"
#else
	.string "…You are a better trainer than me,\n"
	.string "in both skill and kindness.$"
#endif

OlivineCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Statue2
	msgbox OlivineCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Statue2::
	msgbox OlivineCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_Text_GymStatue:
#if GERMAN
	.string "Pokémon-Arena von Oliviana City$"
#else
	.string "OLIVINE CITY POKéMON GYM$"
#endif

OlivineCity_Gym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon-Arena von Oliviana City\p"
	.string "Leiterin: Jasmin\n"
	.string "Anerkannte Trainer:\p"
	.string "{PLAYER}$"
#else
	.string "OLIVINE CITY POKéMON GYM\p"
	.string "JASMINE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif

OlivineCity_Gym_EventScript_Jasmine_Trade::
	goto_if_set FLAG_OLIVINE_GYM_NPC_TRADE_COMPLETED, OlivineCity_Gym_EventScript_JasmineTradeCompleted
	setvar VAR_0x8005, INGAME_TRADE_STEELIX
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox OlivineCity_Gym_Text_JasmineWantToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OlivineCity_Gym_EventScript_JasmineDeclineTrade
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OlivineCity_Gym_EventScript_JasmineDeclineTrade
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox OlivineCity_Gym_Text_JasmineTakeCare, MSGBOX_DEFAULT
	setflag FLAG_OLIVINE_GYM_NPC_TRADE_COMPLETED
	release
	end

OlivineCity_Gym_EventScript_JasmineDeclineTrade::
	msgbox OlivineCity_Gym_Text_JasmineDeclineTrade, MSGBOX_DEFAULT
	release
	end

OlivineCity_Gym_EventScript_JasmineTradeCompleted::
	msgbox OlivineCity_Gym_Text_JasmineTradeCompleted, MSGBOX_DEFAULT
	release
	end

OlivineCity_Gym_Text_JasmineWantToTrade:
#if GERMAN
	.string "…Um, {PLAYER}…\n"
	.string "Ich wollte dich was fragen.\p"
	.string "Ich habe dieses Stahlos aufgezogen\n"
	.string "seit es ein kleines Onix war.\p"
	.string "Aber ich glaube Rusty wäre glücklicher\n"
	.string "bei einem Trainer Wie dir. Möchtest du\l"
	.string "ein\p"
	.string "Pokémon für mein Rusty tauschen?$"
#else
	.string "…Um, {PLAYER}…\n"
	.string "I have something to ask you.\p"
	.string "I've raised this STEELIX since it\n"
	.string "was a little ONIX.\p"
	.string "But I think RUSTY would be happier\n"
	.string "with a trainer like you.\p"
	.string "Would you trade any of your\n"
	.string "POKéMON for my RUSTY?$"
#endif

OlivineCity_Gym_Text_JasmineTakeCare:
#if GERMAN
	.string "…Ich danke dir.\n"
	.string "Sei bitte nett zu Rusty…$"
#else
	.string "…Thank you.\n"
	.string "Please be kind to RUSTY…$"
#endif

OlivineCity_Gym_Text_JasmineDeclineTrade:
#if GERMAN
	.string "…Oh… schon okay.\n"
	.string "Ich verstehe…$"
#else
	.string "…Oh… That's okay.\n"
	.string "I understand…$"
#endif

OlivineCity_Gym_Text_JasmineTradeCompleted:
#if GERMAN
	.string "…Wie geht es Rusty?\n"
	.string "Ich hoffe du kümmerst dich…$"
#else
	.string "…How is RUSTY doing?\n"
	.string "I hope you're taking good care…$"
#endif
