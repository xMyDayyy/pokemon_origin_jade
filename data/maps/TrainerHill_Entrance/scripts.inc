TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_IS_HOENN_CHAMPION, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_IS_HOENN_CHAMPION, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_IS_HOENN_CHAMPION, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_IS_HOENN_CHAMPION, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
#if GERMAN
	.string "Dies ist der Trainerberg. Hier triffst\n"
	.string "du Trainer, mit denen du viele Kämpfe\l"
	.string "genießen kannst.\p"
	.string "Leider ist hier noch alles im Aufbau\n"
	.string "begriffen. Komm doch später wieder.$"
#else
	.string "This is the TRAINER HILL where\n"
	.string "you may enjoy tag battles with many\l"
	.string "TRAINERS.\p"
	.string "Unfortunately, we're still getting\n"
	.string "things ready. Please come back later!$"
#endif

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
#if GERMAN
	.string "Willkommen!\p"
	.string "Dies ist der Trainerberg. Hier triffst\n"
	.string "du Trainer, mit denen du viele Kämpfe\l"
	.string "genießen kannst.$"
#else
	.string "Welcome!\p"
	.string "This is the TRAINER HILL where\n"
	.string "you may enjoy tag battles with many\l"
	.string "TRAINERS!$"
#endif

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
#if GERMAN
	.string "Bist du zum ersten Mal hier?\p"
	.string "Bevor du dich ins Getümmel stürzt,\n"
	.string "speicher bitte dein Spiel!$"
#else
	.string "Is this your first visit here?\p"
	.string "Before you enter, please save\n"
	.string "your game.$"
#endif

TrainerHill_Entrance_Text_TrainersUpToFloorX:
#if GERMAN
	.string "Mal sehen…\n"
	.string "Die Trainer befinden sich…\p"
	.string "In den Etagen bis Etage {STR_VAR_1}.$"
#else
	.string "Let's see…\n"
	.string "The TRAINERS here now are…\p"
	.string "Up to floor no. {STR_VAR_1}.$"
#endif

TrainerHill_Entrance_Text_TrainersInEveryRoom:
#if GERMAN
	.string "Mal sehen…\n"
	.string "Die Trainer befinden sich…\p"
	.string "In jedem Raum scheint sich nun ein\n"
	.string "Trainer zu befinden.$"
#else
	.string "Let's see…\n"
	.string "The TRAINERS here now are…\p"
	.string "There appear to be TRAINERS gathered\n"
	.string "in every room.$"
#endif

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
#if GERMAN
	.string "Möchtest du die wartenden Trainer\n"
	.string "herausfordern?$"
#else
	.string "Would you like to challenge the\n"
	.string "waiting TRAINERS?$"
#endif

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
#if GERMAN
	.string "O.K.! Ich stelle die Uhr! Gib dein Bestes!\p"
	.string "Auf die Plätze…\p"
	.string "Fertig…\p"
	.string "Los!$"
#else
	.string "I will time your progress.\n"
	.string "Best of luck!\p"
	.string "On your marks…\p"
	.string "Get set…\p"
	.string "Go!$"
#endif

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
#if GERMAN
	.string "Bitte besuche uns wieder!$"
#else
	.string "Please do visit us again!$"
#endif

TrainerHill_Entrance_Text_TooBadTremendousEffort:
#if GERMAN
	.string "Das war nicht gut!\p"
	.string "Ich glaube, du hast dich beim Kampf\n"
	.string "richtig angestrengt.\p"
	.string "Bitte komme wieder und probiere es\n"
	.string "erneut!$"
#else
	.string "That was too bad.\p"
	.string "I think you put in a tremendous\n"
	.string "effort in your battling.\p"
	.string "Please come back and try again!$"
#endif

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
#if GERMAN
	.string "Ich hoffe, du strengst dich wirklich\n"
	.string "an!$"
#else
	.string "I hope you give it your best.$"
#endif

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
#if GERMAN
	.string "Tauschen die Trainer ihre Plätze, kann\n"
	.string "es hektisch werden.\p"
	.string "Um eine Panik zu vermeiden, haben wir\n"
	.string "die Rezeption hierher verlegt.\p"
	.string "Wir bitten um dein Verständnis!$"
#else
	.string "When the TRAINERS switch places,\n"
	.string "the movement can be hectic.\p"
	.string "To avoid the stampede, we moved\n"
	.string "the reception counter here.\p"
	.string "I'm sorry for the inconvenience.$"
#endif

TrainerHill_Entrance_Text_ThankYouForPlaying:
#if GERMAN
	.string "Vielen Dank für die Teilnahme!$"
#else
	.string "Thank you for playing!$"
#endif

TrainerHill_Entrance_Text_ExplainTrainerHill:
#if GERMAN
	.string "Hier im Trainerberg bieten wir dir an,\n"
	.string "“Gegen die Uhr” anzutreten.\p"
	.string "Wie lange brauchst du von hier bis zum\n"
	.string "Besitzer, der sich oben auf dem Dach\l"
	.string "befindet?\p"
	.string "Die Namen der Trainer, die es am\n"
	.string "schnellsten schaffen, werden\l"
	.string "öffentlich ausgehängt.\p"
	.string "Fordere deine Freunde heraus!\p"
	.string "Für die Kämpfe, die du auf dem Weg zum\n"
	.string "Dach bestreitest, bekommst du keine\l"
	.string "E-Punkte und auch kein Geld.$"
#else
	.string "Here at the TRAINER HILL, we conduct\n"
	.string "an event called the Time Attack.\p"
	.string "It is a race that measures how long\n"
	.string "you take to reach our owner on\l"
	.string "the rooftop from this counter.\p"
	.string "The fastest times are posted on\n"
	.string "the Time Board--try competing with\l"
	.string "your friends.\p"
	.string "In TRAINER battles along the way,\n"
	.string "neither Exp. Points nor money will\l"
	.string "be awarded.$"
#endif

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
#if GERMAN
	.string "Oh, tut mir Leid, aber du scheinst nur\n"
	.string "ein Pokémon dabeizuhaben.\p"
	.string "Für diese Veranstaltung brauchst du\n"
	.string "mindestens zwei Pokémon.$"
#else
	.string "Oh, I'm sorry, but you appear to have\n"
	.string "only one POKéMON with you.\p"
	.string "You will need at least two POKéMON\n"
	.string "to enter this event.$"
#endif

TrainerHill_Roof_Text_YouFinallyCameBravo:
#if GERMAN
	.string "Hmm…\p"
	.string "Da bist du ja endlich!\n"
	.string "Hast es also geschafft!\p"
	.string "Warte! Sag nichts!\n"
	.string "Ich weiß, warum du gekommen bist!\p"
	.string "Du wolltest mich, den Besitzer des\n"
	.string "Trainerbergs, kennen lernen, weil…\p"
	.string "Du willst mit mir in einem Team\n"
	.string "kämpfen! Jahuu!\p"
	.string "Wie? Das ist nicht der Grund?\p"
	.string "Na, egal. Ich habe dich auf dem Weg\n"
	.string "hierher beobachtet. Du bist sehr gut!$"
#else
	.string "Hm! Hm!\p"
	.string "You finally came!\n"
	.string "Yes, you have arrived!\p"
	.string "Wait! Don't say it!\n"
	.string "I know why you came all the way\l"
	.string "here by yourself!\p"
	.string "You wanted to see me, the owner\n"
	.string "of the TRAINER HILL, because…\p"
	.string "You want to form a tag team with me!\n"
	.string "Wa-hoo!\p"
	.string "…Uh?\n"
	.string "That's not it?\p"
	.string "Anyway, I watched you on your way up.\n"
	.string "Marvelous battling! Bravo, indeed!$"
#endif

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
#if GERMAN
	.string "Ein fantastischer Trainer wie du\n"
	.string "verdient ein fantastisches Geschenk!$"
#else
	.string "For a marvelous someone like you,\n"
	.string "I have the most marvelous gift!$"
#endif

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
#if GERMAN
	.string "Oh, du hast keinen Platz mehr! Na, dann\n"
	.string "komm doch einfach später mal vorbei.$"
#else
	.string "Oh, no, full up with things!\n"
	.string "You'll be back later for this!$"
#endif

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
#if GERMAN
	.string "Hey, warte mal! Bist du wirklich so\n"
	.string "fantastisch schnell hierher gekommen?\p"
	.string "Ausgezeichnet! Dabei hättest du dich\n"
	.string "doch nicht so beeilen müssen, nur um\p"
	.string "mich zu treffen! Trotzdem! Ich habe\n"
	.string "deinen Namen bereits verewigt.$"
#else
	.string "Oh, hold on here! Did you possibly get\n"
	.string "here marvelously quickly?\p"
	.string "How splendid! You needn't have\n"
	.string "hurried so to see me!\p"
	.string "That is so delightful. I'll have the Time\n"
	.string "Board at the reception updated!$"
#endif

TrainerHill_Roof_Text_YouWerentVeryQuick:
#if GERMAN
	.string "Aber… Du hast dir ja mächtig viel Zeit\n"
	.string "gelassen…$"
#else
	.string "But, oh…\n"
	.string "You weren't very quick getting here.$"
#endif

TrainerHill_Roof_Text_ArriveZippierNextTime:
#if GERMAN
	.string "Mir würde es gefallen, wenn du das\n"
	.string "nächste Mal mehr Tempo machst!\p"
	.string "Dann bin ich auch bereit, dein\n"
	.string "Teampartner zu werden!\p"
	.string "Bis dann, mein Freund!$"
#else
	.string "Perhaps it would please me more if you\n"
	.string "arrived zippier next time.\p"
	.string "Then, I should be pleased to form\n"
	.string "a tag team with you!\p"
	.string "Until we meet again, amigo!$"
#endif

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
#if GERMAN
	.string "Ich habe den Trainerberg aus einem\n"
	.string "einzigen Grund erbauen lassen!\p"
	.string "Um den geeignetsten Partner zu finden,\n"
	.string "mit dem ich ein Team bilden kann!$"
#else
	.string "I had the TRAINER HILL built for but\n"
	.string "one reason and one only!\p"
	.string "To find the most suitable partner\n"
	.string "with whom I may form a tag team!$"
#endif

TrainerHill_Entrance_Text_ChallengeTime:
#if GERMAN
	.string "{STR_VAR_1} Min.\n"
	.string "{STR_VAR_2},{STR_VAR_3} Sek.$"
#else
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"
#endif

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
#if GERMAN
	.string "Wer weiß schon, welche Trainer und\n"
	.string "Pokémon auf uns warten?\p"
	.string "Ich weiß nur eines: Ich werde alle,\n"
	.string "die mir im Weg stehen, besiegen!$"
#else
	.string "Who knows what sort of TRAINERS\n"
	.string "and POKéMON combos are ahead?\p"
	.string "All I know is that I'll knock aside\n"
	.string "anyone that stands in my way!$"
#endif

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
#if GERMAN
	.string "Ich habe gehört, Trainer kommen\n"
	.string "von überall her zum Trainerberg.\p"
	.string "Ich kann es nicht erwarten, ihnen\n"
	.string "Auge in Auge gegenüber zu stehen.\p"
	.string "Ich werde jeden besiegen, der sich mir\n"
	.string "in den Weg stellt.$"
#else
	.string "I heard tough TRAINERS come to this\n"
	.string "TRAINER HILL from all over.\p"
	.string "I can't wait to test the waters!\p"
	.string "I'll knock aside anyone that stands\n"
	.string "in my way!$"
#endif

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
#if GERMAN
	.string "Hast du die Liste mit den Zeiten da\n"
	.string "drüben gesehen?\p"
	.string "Meine Freunde und ich wollen\n"
	.string "herausfinden, wer von uns der\l"
	.string "Schnellste ist.$"
#else
	.string "Do you see the Time Board over there?\p"
	.string "My friends and I are trying to see who\n"
	.string "can reach the top in the least time.$"
#endif

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
#if GERMAN
	.string "Du weißt nicht zufällig, wann die hier\n"
	.string "eröffnen?\p"
	.string "Ich warte hier, da ich die allererste\n"
	.string "Herausforderin sein will!$"
#else
	.string "Do you know when they're opening\n"
	.string "this place up?\p"
	.string "I'm waiting here to be the first\n"
	.string "challenger ever!$"
#endif

TrainerHill_Elevator_Text_ReturnToReception:
#if GERMAN
	.string "Möchtest du zur Rezeption\n"
	.string "zurückkehren?$"
#else
	.string "Would you like to return to\n"
	.string "the reception counter?$"
#endif
