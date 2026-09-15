DragonsDen_Shrine_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Shrine_OnFrame
	.byte 0

DragonsDen_Shrine_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 2, DragonsDen_Shrine_Trigger_ElderQuizTop
	.2byte 0

DragonsDen_Shrine_EventScript_Elder::
	lock
	faceplayer
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, DragonsDen_Shrine_EventScript_ElderChooseDratini
	msgbox DragonsDen_Shrine_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

DragonsDen_Shrine_Trigger_ElderQuizLeft::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderLeft
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_MonWalkToElderLeft
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz

DragonsDen_Shrine_Trigger_ElderQuizTop::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderTop
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_PlayerWalkToElderTop
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz

DragonsDen_Shrine_Trigger_ElderQuizRight::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, DragonsDen_Shrine_Movement_PlayerWalkToElderRight
	applymovement2 OBJ_EVENT_ID_FOLLOWER, DragonsDen_Shrine_Movement_MonWalkToElderRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto DragonsDen_Shrine_EventScript_ElderOfferQuiz


DragonsDen_Shrine_Movement_PlayerWalkToElderLeft:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_MonWalkToElderLeft:
	walk_left
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_PlayerWalkToElderTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_Movement_PlayerWalkToElderRight:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
DragonsDen_Shrine_Movement_MonWalkToElderRight:
	walk_right
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Shrine_EventScript_ElderOfferQuiz::
	msgbox DragonsDen_Shrine_Text_ElderGreeting, MSGBOX_DEFAULT
	setvar VAR_DRAGONS_DEN_QUIZ, 0
	goto DragonsDen_Shrine_EventScript_ElderQuiz1

DragonsDen_Shrine_EventScript_ElderQuiz1::
	message DragonsDen_Shrine_Text_Question1
	multichoice 20, 6, MULTI_ELDERQUIIZ1, FALSE
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz1Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz1Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz1
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz1

DragonsDen_Shrine_EventScript_ElderQuiz1Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz2

DragonsDen_Shrine_EventScript_ElderQuiz2::
	message DragonsDen_Shrine_Text_Question2
	multichoice 20, 6, MULTI_ELDERQUIIZ2, FALSE
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz2Correct
	case 1, DragonsDen_Shrine_EventScript_ElderQuiz2Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz2
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz2

DragonsDen_Shrine_EventScript_ElderQuiz2Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz3

DragonsDen_Shrine_EventScript_ElderQuiz3::
	message DragonsDen_Shrine_Text_Question3
	multichoice 20, 6, MULTI_ELDERQUIIZ3, FALSE
	switch VAR_RESULT
	case 1, DragonsDen_Shrine_EventScript_ElderQuiz3Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz3Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz3
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz3

DragonsDen_Shrine_EventScript_ElderQuiz3Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz4

DragonsDen_Shrine_EventScript_ElderQuiz4::
	message DragonsDen_Shrine_Text_Question4
	multichoice 20, 6, MULTI_ELDERQUIIZ4, FALSE
	switch VAR_RESULT
	case 0, DragonsDen_Shrine_EventScript_ElderQuiz4Correct
	case 2, DragonsDen_Shrine_EventScript_ElderQuiz4Correct
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz4
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz4

DragonsDen_Shrine_EventScript_ElderQuiz4Correct::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	goto DragonsDen_Shrine_EventScript_ElderQuiz5

DragonsDen_Shrine_EventScript_ElderQuiz5::
	message DragonsDen_Shrine_Text_Question5
	multichoice 20, 6, MULTI_ELDERQUIIZ5, FALSE
	switch VAR_RESULT
	case 2, DragonsDen_Shrine_EventScript_ElderQuizFinish
	case MULTI_B_PRESSED, DragonsDen_Shrine_EventScript_ElderQuiz5
	call DragonsDen_Shrine_EventScript_ElderWrong
	goto DragonsDen_Shrine_EventScript_ElderQuiz5

DragonsDen_Shrine_EventScript_ElderWrong::
	msgbox DragonsDen_Shrine_Text_WrongAnswer1, MSGBOX_DEFAULT
	addvar VAR_DRAGONS_DEN_QUIZ, 1
	return

DragonsDen_Shrine_EventScript_ElderQuizFinish::
	msgbox DragonsDen_Shrine_Text_RightAnswer, MSGBOX_DEFAULT
	delay 20
	msgbox DragonsDen_Shrine_Text_PassedTest, MSGBOX_DEFAULT
	closemessage
	goto DragonsDen_Shrine_EventScript_ClairEnter


DragonsDen_Shrine_Text_ElderGreeting:
#if GERMAN
	.string "Oh! Willkommen!\p"
	.string "Aber nicht doch! Du musst dich für\n"
	.string "nichts rechtfertigen! Sandra hat dich\l"
	.string "zu mir geschickt, habe ich nicht recht?\p"
	.string "Sie ist so ein eigensinniges Mädchen…\p"
	.string "Sei mir nicht böse, aber ich muss dich\n"
	.string "einem winzig kleinen Test unterziehen.\l"
	.string "Oh nein! Keine Sorge, ich werde dir nur\l"
	.string "ein paar Fragen stellen.\p"
	.string "Gut, dann fangen wir mal an…$"
#else
    .string "Hm… Good to see you here.\p"
    .string "No need to explain why you came.\n"
    .string "CLAIR sent you here, didn't she?\p"
    .string "That girl is a handful…\n"
    .string "I am sorry, but I must test you.\p"
    .string "Not to worry, you are to answer\n"
    .string "only a few questions.\l"
    .string "Ready?$"
#endif

DragonsDen_Shrine_Text_Question1:
#if GERMAN
	.string "Was bedeuten dir Pokémon?$"
#else
    .string "What are POKéMON to you?$"
#endif

DragonsDen_Shrine_Text_Question2:
#if GERMAN
	.string "Was hilft dir im Kampf zu gewinnen?$"
#else
    .string "What helps you to win battles?$"
#endif

DragonsDen_Shrine_Text_Question3:
#if GERMAN
	.string "Gegen welche Art Trainer möchtest du\n"
	.string "kämpfen?$"
#else
    .string "What kind of trainer do you wish\n"
    .string "to battle?$"
#endif

DragonsDen_Shrine_Text_Question4:
#if GERMAN
	.string "Was ist beim Trainieren von Pokémon am\n"
	.string "wichtigsten?$"
#else
    .string "What is most important for\n"
    .string "raising POKéMON?$"
#endif

DragonsDen_Shrine_Text_Question5:
#if GERMAN
	.string "Starke Pokémon. Schwache Pokémon.\p"
	.string "Was ist wichtiger?$"
#else
    .string "Strong POKéMON. Weak POKéMON.\n"
    .string "Which is more important?$"
#endif

DragonsDen_Shrine_Text_WrongAnswer1:
#if GERMAN
	.string "Was sagst du da? Ich habe dich nicht\n"
	.string "richtig verstanden…$"
#else
    .string "Hah? I didn't quite catch that…$"
#endif

DragonsDen_Shrine_Text_WrongAnswer2:
#if GERMAN
	.string "Was hast du da gerade gesagt?$"
#else
    .string "What was it you said?$"
#endif

DragonsDen_Shrine_Text_RightAnswer:
#if GERMAN
	.string "Hm, ich verstehe…$"
#else
    .string "Oh, I understand…$"
#endif

DragonsDen_Shrine_Text_PassedTest:
#if GERMAN
	.string "Hm… Ich verstehe…\p"
	.string "Du kümmerst dich von Herzen um\n"
	.string "Pokémon.\p"
	.string "Sehr löblich.\p"
	.string "Überzeugung ist wichtig!\p"
	.string "{PLAYER}, mach weiter so.\p"
	.string "Ich treffe dich dann bei der Pokémon\n"
	.string "Liga.$"
#else
    .string "Hm… I see…\p"
    .string "You care deeply for POKéMON.\p"
    .string "Very commendable.\p"
    .string "That conviction is what is\n"
    .string "important!\p"
    .string "{PLAYER}, don't lose that belief.\p"
    .string "It will see you through at the\n"
    .string "POKéMON LEAGUE.$"
#endif

DragonsDen_Shrine_EventScript_ClairEnter::
	clearflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	addobject LOCALID_DRAGONSDEN3_CLAIR
	playbgm MUS_HG_CLAIR, FALSE
	playse SE_DOOR
	delay 40
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_SOUTH
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairEnter
	waitmovement 0
	turnobject LOCALID_DRAGONSDEN3_ELDER, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_ClairYouPassed, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairBackup1
	waitmovement 0
	msgbox DragonsDen_Shrine_Text_ClairThatCantBe, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairBackup2
	waitmovement 0
	msgbox DragonsDen_Shrine_Text_ClairYoureLying, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_ELDER, DragonsDen_Shrine_Movement_ElderWalkToClair
	waitmovement 0
	turnobject LOCALID_DRAGONSDEN3_CLAIR, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_MustIInformLance, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, Common_Movement_ExclamationMark
	msgbox DragonsDen_Shrine_Text_IUnderstand, MSGBOX_DEFAULT
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairReturnToPlayer
	waitmovement 0
	msgbox DragonsDen_Shrine_Text_HereRisingBadge, MSGBOX_DEFAULT

	message DragonsDen_Shrine_Text_PlayerReceivedRisingBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DragonsDen_Shrine_Text_RisingBadgeExplanation, MSGBOX_DEFAULT
	setvar VAR_0x8004, 7
	special SetJohtoBadge
	setflag FLAG_BADGE08_GET
	@ Clair: Johto-Orden 8. Die Flag oben teilt sich Johto mit Kanto und
	@ ist nach der Kanto-Liga laengst gesetzt - gezaehlt wird in VAR_JOHTO_BADGES.
	setvar VAR_0x8004, 7
	special SetJohtoBadge
	@ Der Orden ist zugleich die Befugnis fuer Kaskade - siehe
	@ src/johto_permits.c. Die Ordensflags teilt sich Johto mit Kanto.
	setvar VAR_0x8004, PERM_WATERFALL
	special SetJohtoPermit
	addvar VAR_NUM_BADGES, 1

	applymovement2 LOCALID_DRAGONSDEN3_ELDER, DragonsDen_Shrine_Movement_ElderReturnToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_DRAGONSDEN3_CLAIR, DIR_NORTH
	msgbox DragonsDen_Shrine_Text_ElderScoldsClair, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox DragonsDen_Shrine_Text_Speechless, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_DRAGONSDEN3_CLAIR, DragonsDen_Shrine_Movement_ClairLeave
	waitmovement 0
	playse SE_EXIT
	fadedefaultbgm
	setflag FLAG_HIDE_DRAGONS_DEN_SHRINE_CLAIR
	removeobject LOCALID_DRAGONSDEN3_CLAIR
	clearflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	setvar VAR_BLACKTHORN_CITY_STATE, 3
	release
	end

DragonsDen_Shrine_Movement_ClairEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

DragonsDen_Shrine_Movement_ClairBackup1:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	step_end

DragonsDen_Shrine_Movement_ClairBackup2:
	lock_facing_direction
	walk_slow_left
	unlock_facing_direction
	step_end

DragonsDen_Shrine_Movement_ElderWalkToClair:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

DragonsDen_Shrine_Movement_ClairReturnToPlayer:
	walk_right
	walk_right
	step_end

DragonsDen_Shrine_Movement_ElderReturnToPlayer:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	face_down
	step_end

DragonsDen_Shrine_Movement_ClairLeave:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

DragonsDen_Shrine_Text_ClairYouPassed:
#if GERMAN
	.string "Na, wie hast du abgeschnitten?\p"
	.string "Warte, lass mich raten… Bei dir ist\n"
	.string "Hopfen und Malz verloren! … … … …Was! Du\l"
	.string "hast bestanden?!?$"
#else
    .string "So how did it go?\p"
    .string "I guess there's no point\n"
	.string "in asking. You did fail?\p"
    .string "..................................\p"
    .string "…What? You passed?$"
#endif

DragonsDen_Shrine_Text_ClairThatCantBe:
#if GERMAN
	.string "Das kann nicht sein!$"
#else
    .string "That can't be!$"
#endif

DragonsDen_Shrine_Text_ClairYoureLying:
#if GERMAN
	.string "Das darf doch nicht wahr sein! N-nicht\n"
	.string "einmal ich wurde von ihm als würdig\l"
	.string "anerkannt!$"
#else
    .string "You're lying!\p"
    .string "Even I haven't been approved!$"
#endif

DragonsDen_Shrine_Text_MustIInformLance:
#if GERMAN
	.string "Sandra!\p"
	.string "Dieses Kind ist eine wahre Offenbarung,\n"
	.string "was Technik und Einstellung angeht!\l"
	.string "Nun spring endlich über deinen\l"
	.string "Schatten und rücke mit dem\l"
	.string "Drachenorden heraus!\p"
	.string "Wenn du dich weigerst… sehe ich mich\n"
	.string "gezwungen, Siegfried davon zu\l"
	.string "erzählen!$"
#else
    .string "CLAIR!\p"
    .string "This child is impeccable,\n"
    .string "in skill and spirit!\p"
    .string "Admit defeat and confer the\n"
    .string "RISINGBADGE!\p"
    .string "…Or must I inform LANCE of this?$"
#endif

DragonsDen_Shrine_Text_IUnderstand:
#if GERMAN
	.string "I-in Ordnung…$"
#else
    .string "I-I understand…$"
#endif

DragonsDen_Shrine_Text_HereRisingBadge:
#if GERMAN
	.string "Hier, das ist der Drachenorden… Los,\n"
	.string "jetzt nimm ihn schon!$"
#else
    .string "Here, this is the RISINGBADGE…\p"
    .string "Hurry up! Take it!$"
#endif

DragonsDen_Shrine_Text_PlayerReceivedRisingBadge:
#if GERMAN
	.string "{PLAYER} erhält den Drachenorden!$"
#else
    .string "{PLAYER} received RISINGBADGE.$"
#endif

DragonsDen_Shrine_Text_RisingBadgeExplanation:
#if GERMAN
	.string "Mit dem Drachenorden in deinem Besitz\n"
	.string "können deine Pokémon mit der Attacke\p"
	.string "Kaskade jeden Wasserfall erklimmen…\p"
	.string "Ferner werden dich alle Pokémon als\n"
	.string "Trainer anerkennen und dir\l"
	.string "bedingungslos gehorchen.$"
#else
    .string "RISINGBADGE will enable your\n"
    .string "POKéMON to use the move for\l"
    .string "climbing waterfalls.\p"
    .string "Also, all POKéMON will recognize\n"
    .string "you as a trainer and obey your\l"
    .string "every command without question.$"
#endif

DragonsDen_Shrine_Text_ElderScoldsClair:
#if GERMAN
	.string "Sandra…\p"
	.string "Dieses Kind besitzt etwas, das dir\n"
	.string "fehlt… Denke mal in Ruhe darüber nach,\l"
	.string "was ich damit meinen könnte.$"
#else
    .string "CLAIR…\p"
    .string "Reflect upon what it is that you\n"
    .string "lack and this child has.$"
#endif

DragonsDen_Shrine_Text_Speechless:
#if GERMAN
	.string "..................................$"
#else
    .string "..................................$"
#endif

DragonsDen_Shrine_Text_ComeAgain:
#if GERMAN
	.string "Komm wieder, wenn du es dir anders\n"
	.string "überlegen solltest!$"
#else
    .string "Come again, if you so desire.$"
#endif

DragonsDen_Shrine_Text_SilverIsInTraining:
#if GERMAN
	.string "Ein Junge deines Alters ist gerade hier,\n"
	.string "um unterwiesen zu werden.\p"
	.string "Er ist ein bisschen so, wie Sandra\n"
	.string "früher war. Das besorgt mich etwas…$"
#else
    .string "A boy close to your age is in\n"
    .string "training here.\p"
    .string "He is much like CLAIR when she was\n"
    .string "younger. It is a little worrisome…$"
#endif

DragonsDen_Shrine_EventScript_Elder2::
	msgbox DragonsDen_Shrine_Text_Elder2, MSGBOX_NPC
	end

DragonsDen_Shrine_EventScript_Elder3::
	msgbox DragonsDen_Shrine_Text_Elder3, MSGBOX_NPC
	end

DragonsDen_Shrine_Text_Elder2:
#if GERMAN
	.string "Es ist schon lange her, seit jemand die\n"
	.string "Anerkennung unseres Meisters erhielt.\l"
	.string "Der letzte vor dir war Siegfried!$"
#else
    .string "It's been quite some time since a\n"
    .string "trainer has gained our MASTER's\l"
    .string "rare approval.\p"
    .string "In fact, not since Master LANCE.$"
#endif

DragonsDen_Shrine_Text_Elder3:
#if GERMAN
	.string "Kennst du Siegfried?\p"
	.string "Er ist das genaue Ebenbild unseres\n"
	.string "Meisters in seinen jungen Jahren. Sie\l"
	.string "sind aus demselben Holz geschnitzt.$"
#else
    .string "You know young Master LANCE?\p"
    .string "He looks so much like our MASTER\n"
    .string "did in his youth.\p"
    .string "It's in their blood.$"
#endif

DragonsDen_Shrine_EventScript_ElderChooseDratini::
	goto_if_eq VAR_DRAGONS_DEN_QUIZ, 0, DragonsDen_Shrine_EventScript_ElderGiveSpecialDratini
	goto DragonsDen_Shrine_EventScript_ElderGiveBasicDratini

DragonsDen_Shrine_EventScript_ElderGiveBasicDratini::
	goto_if_set FLAG_GOT_DRATINI, DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini
	msgbox DragonsDen_Shrine_Text_TakeThisDratini, MSGBOX_DEFAULT

	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRATINI
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	givemon SPECIES_DRATINI, 15
	call Common_EventScript_GiftMon

	msgbox DragonsDen_Shrine_Text_SymbolicDragon, MSGBOX_DEFAULT
	setflag FLAG_GOT_DRATINI
	release
	end

DragonsDen_Shrine_EventScript_ElderGiveSpecialDratini::
	goto_if_set FLAG_GOT_DRATINI, DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini
	msgbox DragonsDen_Shrine_Text_TakeThisDratini, MSGBOX_DEFAULT

	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DRATINI
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	givenamedmon 4
	call Common_EventScript_GiftMonNamed

	msgbox DragonsDen_Shrine_Text_SymbolicDragon, MSGBOX_DEFAULT
	setflag FLAG_GOT_DRATINI
	release
	end

DragonsDen_Shrine_EventScript_ElderAlreadyGotDratini::
	msgbox DragonsDen_Shrine_Text_ClairsGrandfather, MSGBOX_DEFAULT
	release
	end

DragonsDen_Shrine_Text_TakeThisDratini:
#if GERMAN
	.string "Hm… Schön, dass du hier bist.\p"
	.string "Du kommst zur richtigen Zeit.\p"
	.string "Ich habe etwas für dich.\p"
	.string "Nimm dieses Dratini als Zeichen meiner\n"
	.string "Wertschätzung.$"
#else
    .string "Hm… Good to see you here.\p"
    .string "Your arrival is most fortunate.\p"
    .string "I have something for you.\p"
    .string "Take this DRATINI as proof that I\n"
    .string "have recognized your worth.$"
#endif

DragonsDen_Shrine_Text_SymbolicDragon:
#if GERMAN
	.string "Drachen-Pokémon sind das\n"
	.string "Markenzeichen unseres Klans!\p"
	.string "Dir kann ich eins von ihnen anvertrauen.$"
#else
    .string "Dragon POKéMON are symbolic of our\n"
    .string "clan.\p"
    .string "You have shown that you can be\n"
    .string "entrusted with one.$"
#endif

DragonsDen_Shrine_Text_ClairsGrandfather:
#if GERMAN
	.string "Sandra scheint aus ihrer Begegnung mit\n"
	.string "dir etwas mitgenommen zu haben…\p"
	.string "Ich, ihr Großvater, danke dir dafür.$"
#else
    .string "CLAIR appears to have learned an\n"
    .string "invaluable lesson from you.\p"
    .string "I thank you as her grandfather.$"
#endif
