ViridianCity_School_Frlg_MapScripts::
	.byte 0

ViridianCity_School_EventScript_Lass::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_TryingToMemorizeNotes
	closemessage
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Woman::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully
	closemessage
	applymovement LOCALID_SCHOOL_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Notebook::
	lockall
	msgbox ViridianCity_School_Text_NotebookFirstPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookSecondPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookThirdPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookFourthPage
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes
	releaseall
	end

ViridianCity_School_EventScript_StopReadingNotebook::
	releaseall
	end

ViridianCity_School_EventScript_Blackboard::
	lockall
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ChooseBlackboardTopic::
	message ViridianCity_School_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 7, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	@ Kanto-Merge: Die Eintraege der Liste lauten GIF, PAR, SLF - die
	@ Verzweigung ging von der FRLG-Reihenfolge SLF, GIF, PAR aus.
	case 0, ViridianCity_School_EventScript_ReadPoison
	case 1, ViridianCity_School_EventScript_ReadParalysis
	case 2, ViridianCity_School_EventScript_ReadSleep
	case 3, ViridianCity_School_EventScript_ReadBurn
	case 4, ViridianCity_School_EventScript_ReadFreeze
	case 5, ViridianCity_School_EventScript_ExitBlackboard
	case 127, ViridianCity_School_EventScript_ExitBlackboard
	end

ViridianCity_School_EventScript_ReadSleep::
	msgbox ViridianCity_School_Text_ExplainSleep
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadBurn::
	msgbox ViridianCity_School_Text_ExplainBurn
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadPoison::
	msgbox ViridianCity_School_Text_ExplainPoison
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadFreeze::
	msgbox ViridianCity_School_Text_ExplainFreeze
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadParalysis::
	msgbox ViridianCity_School_Text_ExplainParalysis
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ExitBlackboard::
	releaseall
	end

ViridianCity_School_Text_TryingToMemorizeNotes::
#if GERMAN
	.string "Puh! Ich versuche, meine Notizen\n"
	.string "auswendig zu lernen.$"
#else
	.string "Whew! I'm trying to memorize all my\n"
	.string "notes.$"
#endif

ViridianCity_School_Text_ReadBlackboardCarefully::
#if GERMAN
	.string "O.K.!\p"
	.string "Lies sorgfältig den Text auf der\n"
	.string "Tafel!$"
#else
	.string "Okay!\p"
	.string "Be sure to read what's on the\n"
	.string "blackboard carefully!$"
#endif

ViridianCity_School_Text_NotebookFirstPage::
#if GERMAN
	.string "Du schaust in das Notizbuch!\p"
	.string "Erste Seite...\p"
	.string "Zum Fangen von Pokémon benutzt\n"
	.string "man Pokébälle.\p"
	.string "Man kann bis zu sechs Pokémon auf\n"
	.string "einmal tragen.\p"
	.string "Pokémon Trainer ziehen Pokémon\n"
	.string "groß und trainieren sie.$"
#else
	.string "Let's check out the notebook.\p"
	.string "First page…\p"
	.string "POKé BALLS are used to catch\n"
	.string "POKéMON.\p"
	.string "Up to six POKéMON can be carried\n"
	.string "in your party.\p"
	.string "People who raise and battle\n"
	.string "with POKéMON are called TRAINERS.$"
#endif

ViridianCity_School_Text_NotebookSecondPage::
#if GERMAN
	.string "Zweite Seite...\p"
	.string "Ein Pokémon bei voller Stärke ist\n"
	.string "schwer zu fangen!\l"
	.string "Man sollte es erst schwächen.\p"
	.string "Feuer, Gift und andere Attacken\n"
	.string "wirken Wunder!$"
#else
	.string "Second page…\p"
	.string "A healthy POKéMON may be hard to\n"
	.string "catch, so weaken it first.\p"
	.string "Poison, burn, or cause another\n"
	.string "status problem to weaken it.$"
#endif

ViridianCity_School_Text_NotebookThirdPage::
#if GERMAN
	.string "Dritte Seite...\p"
	.string "Pokémon Trainer suchen einander\n"
	.string "und lassen ihre Pokémon kämpfen.\p"
	.string "In den Pokémon-Arenen finden stets\n"
	.string "Kämpfe statt.$"
#else
	.string "Third page…\p"
	.string "POKéMON TRAINERS seek others to\n"
	.string "engage in POKéMON battles.\p"
	.string "To TRAINERS, the taste of victory\n"
	.string "is sweet, indeed.\p"
	.string "Battles are constantly waged at\n"
	.string "POKéMON GYMS everywhere.$"
#endif

ViridianCity_School_Text_NotebookFourthPage::
#if GERMAN
	.string "Vierte Seite...\p"
	.string "Das Ziel jedes Pokémon Trainers ist es,\n"
	.string "die acht Leiter der Pokémon-Arenen zu\l"
	.string "besiegen.\p"
	.string "Nur dann darf er den Top Vier in\n"
	.string "der Pokémon Liga gegenübertreten!$"
#else
	.string "Fourth page…\p"
	.string "The ultimate goal for all POKéMON\n"
	.string "TRAINERS is simple.\p"
	.string "It is to defeat the top eight\n"
	.string "POKéMON GYM LEADERS.\p"
	.string "Do so to earn the right to face…\p"
	.string "The ELITE FOUR of the POKéMON\n"
	.string "LEAGUE!$"
#endif

ViridianCity_School_Text_TurnThePage::
#if GERMAN
	.string "Umblättern?$"
#else
	.string "Turn the page?$"
#endif

ViridianCity_School_Text_HeyDontLookAtMyNotes::
#if GERMAN
	.string "Mädchen: Heh!\n"
	.string "Lass die Finger von meinen Notizen!$"
#else
	.string "GIRL: Hey!\n"
	.string "Don't look at my notes!$"
#endif

ViridianCity_School_Text_BlackboardListsStatusProblems::
#if GERMAN
	.string "Die Tafel zeigt Statuswechsel der\n"
	.string "Pokémon während des Kampfes an.$"
#else
	.string "The blackboard lists POKéMON\n"
	.string "STATUS problems during battles.$"
#endif

ViridianCity_School_Text_ReadWhichTopic::
#if GERMAN
	.string "Welches Thema möchtest du lesen?$"
#else
	.string "Which topic do you want to read?$"
#endif

ViridianCity_School_Text_ExplainSleep::
#if GERMAN
	.string "Wenn ein Pokémon schläft, kann es\n"
	.string "nicht angreifen!\p"
	.string "Ein schlafendes Pokémon wacht auch\n"
	.string "nach dem Kampf nicht auf.\p"
	.string "Benutze Aufwecker, damit es aufwacht.$"
#else
	.string "A POKéMON can't attack if it's\n"
	.string "asleep.\p"
	.string "POKéMON will stay asleep even\n"
	.string "after battles.\p"
	.string "Use AWAKENING to awaken one\n"
	.string "from sleep.$"
#endif

ViridianCity_School_Text_ExplainBurn::
#if GERMAN
	.string "Eine Verbrennung vermindert Kraft\n"
	.string "und Stärke. Die KP sinken stetig.\p"
	.string "Verbrennungen dauern auch nach\n"
	.string "einem Kampf an.\p"
	.string "Man heilt sie mit Feuerheiler.$"
#else
	.string "A burn reduces ATTACK power.\n"
	.string "It also causes ongoing HP loss.\p"
	.string "A burn remains after a battle.\n"
	.string "Use BURN HEAL to cure a burn.$"
#endif

ViridianCity_School_Text_ExplainPoison::
#if GERMAN
	.string "Ein vergiftetes Pokémon verliert\n"
	.string "stetig KP.\p"
	.string "Die Wirkung des Giftes hält auch nach\n"
	.string "einem Kampf an.\l"
	.string "Gegengift heilt Vergiftungen.$"
#else
	.string "When poisoned, a POKéMON's health\n"
	.string "steadily drops.\p"
	.string "Poison lingers after battles.\n"
	.string "Use an ANTIDOTE to cure poison!$"
#endif

ViridianCity_School_Text_ExplainFreeze::
#if GERMAN
	.string "Ein eingefrorenes Pokémon ist\n"
	.string "bewegungsunfähig.\p"
	.string "Es behält auch nach dem Kampf\n"
	.string "diesen Zustand bei.\p"
	.string "Nur der Eisheiler kann es wieder\n"
	.string "auftauen!$"
#else
	.string "A frozen POKéMON becomes\n"
	.string "helplessly immobile.\p"
	.string "It stays frozen even after the\n"
	.string "battle ends.\p"
	.string "Use ICE HEAL to thaw out the\n"
	.string "suffering POKéMON.$"
#endif

ViridianCity_School_Text_ExplainParalysis::
#if GERMAN
	.string "Ein paralysiertes Pokémon verliert\n"
	.string "an Treffgenauigkeit!\p"
	.string "Die Paralyse hält auch nach einem Kampf\n"
	.string "an. Man behandelt sie mit Para-Heiler.$"
#else
	.string "Paralysis reduces SPEED and may\n"
	.string "prevent the POKéMON from moving.\p"
	.string "Paralysis remains after battles.\n"
	.string "Use PARLYZ HEAL for treatment.$"
#endif

