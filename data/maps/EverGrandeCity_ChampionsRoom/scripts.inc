EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	@ Origin Jade: rematch team once Hoenn's league is won.
	goto_if_set FLAG_IS_HOENN_CHAMPION, EverGrandeCity_ChampionsRoom_EventScript_Rematch
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Rematch::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	trainerbattle_rematch TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_RematchIntro, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
#if IS_HNS
	goto_if_set FLAG_IS_HOENN_CHAMPION, EverGrandeCity_ChampionsRoom_EventScript_TitleDefenceExitForHoF
#endif
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
#if IS_HNS
	@ HnS: the rival is always May.
	goto EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
#else
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
#endif
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
#if IS_HNS
	@ HnS: Hoenn champion title; registers the Elite Four and Wallace in the PokeNav.
	setflag FLAG_IS_HOENN_CHAMPION
	setflag FLAG_REGISTERED_SIDNEY
	setflag FLAG_REGISTERED_PHOEBE
	setflag FLAG_REGISTERED_GLACIA
	setflag FLAG_REGISTERED_DRAKE
	setflag FLAG_REGISTERED_WALLACE
#endif
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

#if IS_HNS
@ Repeat Hoenn titles: Wallace leads the player straight to the Hall of Fame, without the rival
@ and Prof. Birch. The first title sets the flags above. See docs/origin_jade/DECISIONS.md, D-028.
EverGrandeCity_ChampionsRoom_EventScript_TitleDefenceExitForHoF:
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end
#endif

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
#if GERMAN
	.string "Wassili: Willkommen, {PLAYER}{KUN}.\p"
	.string "Dieser Zwischenfall in Xeneroville…\n"
	.string "Das war hervorragende Arbeit - wie du\l"
	.string "die Krise dort beendet hast!\p"
	.string "Hups!\p"
	.string "Es wäre aber nicht fair zu behaupten,\n"
	.string "du hättest allein für Ordnung gesorgt.\l"
	.string "\p"
	.string "Du hast die Situation gemeistert, weil\n"
	.string "du mit deinen Pokémon\l"
	.string "zusammengearbeitet hast.\p"
	.string "Was es heißt, Pokémon großzuziehen\n"
	.string "und von ihnen zu lernen, muss ich\l"
	.string "einem Champion nicht erklären.\p"
	.string "Du hast zwei Regionen bezwungen.\n"
	.string "Aber Hoenn stellt eine eigene Frage:\p"
	.string "Nun ja!\p"
	.string "Wer kann am elegantesten in ganz\n"
	.string "Hoenn mit seinen Pokémon tanzen?\p"
	.string "Zeig es mir! Hier und jetzt!$"
#else
	.string "WALLACE: Welcome, {PLAYER}{KUN}.\p"
	.string "That incident in SOOTOPOLIS CITY…\n"
	.string "That was superb work, putting an end\l"
	.string "to that crisis all by yourself.\p"
	.string "Oops!\p"
	.string "It wouldn't be fair to say that you\n"
	.string "alone ended the crisis.\p"
	.string "You overcame that difficult situation\n"
	.string "by working as one with your POKéMON.\p"
	.string "What it means to raise POKéMON and\n"
	.string "to learn from them - I need not\l"
	.string "explain that to a CHAMPION.\p"
	.string "You have conquered two regions.\n"
	.string "But HOENN asks its own question:\p"
	.string "Now!\p"
	.string "Who can most elegantly dance with\n"
	.string "their POKéMON in HOENN?\p"
	.string "Show me right here and now!$"
#endif

EverGrandeCity_ChampionsRoom_Text_Defeat:
#if GERMAN
	.string "Ich, der Champ, wurde besiegt…\p"
	.string "Eine erstklassige Leistung!\n"
	.string "Du warst elegant, manchmal auch\l"
	.string "verzweifelt. Aber auch herrlich!\p"
	.string "Der Ruhm gehört dir, {PLAYER}{KUN}!\p"
	.string "Du bist wahrhaft ein edler Trainer!$"
#else
	.string "I, the CHAMPION, fall in defeat…\p"
	.string "That was wonderful work.\n"
	.string "You were elegant, infuriatingly so.\l"
	.string "And yet it was utterly glorious!\p"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
	.string "You are a truly noble POKéMON\n"
	.string "TRAINER!$"
#endif

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
#if GERMAN
	.string "Wassili: Die Pokémon, die du in den\n"
	.string "Kampf geschickt hast…\p"
	.string "Manchmal wirbelten sie wie eine\n"
	.string "Frühlingsbrise und dann wieder\l"
	.string "schlugen sie ein wie ein Blitz.\p"
	.string "Du hast deine Pokémon mit leichter,\n"
	.string "aber sicherer Eleganz geführt.\p"
	.string "Du hast mich mit deiner\n"
	.string "meisterhaften Vorstellung\l"
	.string "bezaubert!\p"
	.string "Du hast den ruhmreichen Gipfel der\n"
	.string "Pokémon Liga erreicht.\p"
	.string "Für die ganze Hoenn-Region rufe ich\n"
	.string "dich hiermit…$"
#else
	.string "WALLACE: The POKéMON you sent into\n"
	.string "battle…\p"
	.string "At times they danced like a spring\n"
	.string "breeze, and at times they struck\l"
	.string "like lightning.\p"
	.string "It was with light, yet surefooted,\n"
	.string "elegance that you led your POKéMON.\p"
	.string "Even I felt bedazzled by your\n"
	.string "masterful performance!\p"
	.string "You now stand at the glorious peak\n"
	.string "of the POKéMON LEAGUE.\p"
	.string "I now proclaim you to be the new\n"
	.string "HOENN region…$"
#endif

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
#if GERMAN
	.string "Maike: {PLAYER}{KUN}!\p"
	.string "Ich muss dir unbedingt einen Rat geben,\n"
	.string "bevor du gegen den Champ antrittst!$"
#else
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "Here's some advice before you challenge\n"
	.string "the CHAMPION…$"
#endif

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
#if GERMAN
	.string "Maike: Wie? Waswaswas?\p"
	.string "{PLAYER}{KUN}… Das kann nicht sein…\n"
	.string "Es ist schon vorbei?$"
#else
	.string "MAY: Huh?\n"
	.string "What, what, what?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Could it be that…\l"
	.string "It's already over?$"
#endif

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
#if GERMAN
	.string "Maike: {PLAYER}!\p"
	.string "Möchtest du nicht ein paar Tipps,\n"
	.string "bevor du den Champ herausforderst?$"
#else
	.string "BRENDAN: {PLAYER}!\p"
	.string "How would you like some advice before\n"
	.string "you challenge the CHAMPION?…$"
#endif

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
#if GERMAN
	.string "Maike: {PLAYER}!\p"
	.string "Willst du mir etwa sagen…\n"
	.string "Du hast den Champ besiegt?!?!?!$"
#else
	.string "BRENDAN: {PLAYER}…\p"
	.string "Are you trying to tell me…\n"
	.string "You've beaten the CHAMPION?$"
#endif

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
#if GERMAN
	.string "Prof. Birk: Siehst du?\n"
	.string "Was habe ich dir gesagt, {RIVAL}?\p"
	.string "Ich wusste, du brauchst dir keine\n"
	.string "Sorgen um {PLAYER}{KUN} zu machen!\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, du hast es geschafft.\p"
	.string "Als ich hörte, dass du deinen Vater in\n"
	.string "der Arena von Blütenburg City\p"
	.string "besiegt hast, wusste ich, dass du eine\n"
	.string "Chance hast…\p"
	.string "Aber, dass du dann sogar Champ\n"
	.string "geworden bist!\p"
	.string "Oh, ja!\p"
	.string "Was ist aus deinem Pokédex geworden?\n"
	.string "Lass mich mal sehen…$"
#else
	.string "PROF. BIRCH: See?\n"
	.string "What did I tell you, {RIVAL}?\p"
	.string "Didn't I tell you that you don't need\n"
	.string "to worry about {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
	.string "When I heard that you defeated your\n"
	.string "own father at the PETALBURG GYM,\l"
	.string "I thought perhaps you had a chance…\p"
	.string "But to think you've actually become\n"
	.string "the CHAMPION!\p"
	.string "Ah, yes!\p"
	.string "What became of your POKéDEX?\n"
	.string "Here, let me see.$"
#endif

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
#if GERMAN
	.string "Prof. Birk: Also, dann sage ich:\n"
	.string "Herzlichen Glückwunsch!\p"
	.string "Nun kannst du mit Stolz den letzten\n"
	.string "Raum betreten!$"
#else
	.string "PROF. BIRCH: Anyways,\n"
	.string "congratulations!\p"
	.string "Now, go proudly into the final room!$"
#endif

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
#if GERMAN
	.string "Wassili: {PLAYER}{KUN}…\p"
	.string "Nein! Lass es mich richtig\n"
	.string "ausdrücken!\p"
	.string "Neuer Champ!\p"
	.string "Komm mit mir.$"
#else
	.string "WALLACE: {PLAYER}{KUN}…\p"
	.string "No, let me rephrase that properly.\p"
	.string "The new CHAMPION!\p"
	.string "Come with me.$"
#endif

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
#if GERMAN
	.string "Wassili: Tut mir Leid, aber…\p"
	.string "Diesen Raum dürfen nur Trainer\n"
	.string "betreten, die Champs geworden sind.\p"
	.string "Warte bitte draußen mit dem Professor.$"
#else
	.string "WALLACE: I'm sorry, but…\p"
	.string "From here on, only those TRAINERS who\n"
	.string "have become CHAMPIONS may enter.\p"
	.string "You'll have to wait outside with\n"
	.string "PROF. BIRCH.$"
#endif

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
#if GERMAN
	.string "Maike: Grummel…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ich mache nur Spaß! Ist schon okay!\n"
	.string "So sind die Regeln!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Ehrlich. Herzlichen Glückwunsch!$"
#else
	.string "MAY: Groan…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "I'm just joking! That's okay!\n"
	.string "That's the rule!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Honestly, congratulations!$"
#endif

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
#if GERMAN
	.string "Maike: … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Na, wenn es die Regeln so bestimmen…\p"
	.string "{PLAYER}, das ist dein Tag!\n"
	.string "Herzlichen Glückwunsch!$"
#else
	.string "BRENDAN: Whaaaat?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "It can't be helped if that's the rule.\p"
	.string "{PLAYER}, way to go!\n"
	.string "Congratulations!$"
#endif

EverGrandeCity_ChampionsRoom_Text_RematchIntro:
#if GERMAN
	.string "Wassili: {PLAYER}!\n"
	.string "Ich habe auf dich gewartet.\p"
	.string "Ein Champion bleibt nur Champion,\n"
	.string "solange sich jemand erhebt, um ihn\l"
	.string "herauszufordern.\p"
	.string "Lass uns diesen Gipfel noch einmal\n"
	.string "gemeinsam erklimmen!$"
#else
	.string "WALLACE: {PLAYER}!\n"
	.string "I have been waiting for you.\p"
	.string "A CHAMPION remains a CHAMPION only\n"
	.string "as long as someone rises to\l"
	.string "challenge them.\p"
	.string "Let us climb this summit\n"
	.string "together once more!$"
#endif
