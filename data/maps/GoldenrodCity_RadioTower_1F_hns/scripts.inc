GoldenrodCity_RadioTower_1F_hns_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2_HNS,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
#if GERMAN
	.string "Bianka: Hallooo!\n"
	.string "Ich heiße Bianka!\p"
	.string "Hier läuft gerade ein Quiz, bei dem man\n"
	.string "ein Radio-Modul abstauben kann! Ich\l"
	.string "selbst bin auch genau deswegen hier…\p"
	.string "Aber dieses Quiz ist echt unglaublich\n"
	.string "schwierig!$"
#else
	.string "WHITNEY: Hi!\p"
	.string "My name is WHITNEY!\p"
	.string "I heard about the QUIZ to win a\n"
	.string "RADIO, so I came here to get\l"
	.string "one...\p"
	.string "But this QUIZ is so hard!$"
#endif

RadioTower1F_Text_Whitney2::
#if GERMAN
	.string "Bianka: Wahnsinn! Du bist echt klasse!\n"
	.string "Bei Frage 3 war ich mir so sicher, dass\l"
	.string "die Antwort Aprikorken lautet!\p"
	.string "Ho-hoppla!\n"
	.string "Ich muss langsam zurück in die Arena!$"
#else
	.string "WHITNEY: Wow, you did it!\p"
	.string "I thought the answer to the third\n"
	.string "question was surely apricorns!\l"
	.string "Oops!\p"
	.string "It's time to go back to the GYM!$"
#endif

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	msgbox RadioTower1F_Text_ReceptionistNoTours, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGiveRadio::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox RadioTower1F_Text_PokegearRadio, MSGBOX_AUTOCLOSE
	waitfanfare
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
#if GERMAN
	.string "Komm Rein$"
#else
    .string "Welcome!$"
#endif

RadioTower1F_Text_ReceptionistNoTours:
#if GERMAN
	.string "Guten Tag! Leider bieten wir heute\n"
	.string "keine Führungen an.$"
#else
    .string "Hello. I'm sorry, but we're not\n"
    .string "offering any tours today.$"
#endif

RadioTower1F_Text_RadioCardWomanOfferQuiz:
#if GERMAN
	.string "Bei uns läuft momentan ein besonderes\n"
	.string "Quiz.\p"
	.string "Beantworte die fünf Fragen richtig, um\n"
	.string "ein Radio-Modul zu gewinnen.\p"
	.string "Stecke es in den Com, um überall und zu\n"
	.string "jeder Zeit Radio hören zu können.\p"
	.string "Möchtest du am Quiz teilnehmen?$"
#else
    .string "We have a special QUIZ campaign on\n"
    .string "right now.\p"
    .string "Answer five questions correctly to\n"
    .string "win a RADIO.\p"
    .string "You and your POKéMON can use it to\n"
    .string "play music anytime, anywhere.\p"
    .string "Would you like to take the QUIZ?$"
#endif

RadioTower1F_Text_QuizQuestion1:
#if GERMAN
	.string "Frage 1:\p"
	.string "Gibt es ein Pokémon, das nur am\n"
	.string "Tag erscheint?$"
#else
    .string "Question 1:\p"
    .string "Is there a POKéMON that appears only\n"
    .string "in the daytime?$"
#endif

RadioTower1F_Text_QuizQuestion2:
#if GERMAN
	.string "Richtig! Frage 2:\p"
	.string "Ist diese Aussage korrekt?\p"
	.string "Man kann im Shop keine Beere kaufen.$"
#else
    .string "Correct!\n"
    .string "Question 2:\p"
    .string "Is this statement correct?\p"
    .string "You can't buy a BERRY at a MART.$"
#endif

RadioTower1F_Text_QuizQuestion3:
#if GERMAN
	.string "Volltreffer! Frage 3:\p"
	.string "Benutzt Kurt, der Pokéball-Erbauer,\n"
	.string "Aprikoko als Zutaten?$"
#else
    .string "Bull's-eye!\n"
    .string "Question 3:\p"
    .string "KURT, the POKéBALL creator, uses\n"
	.string "apricorns as ingredients?$"
#endif

RadioTower1F_Text_QuizQuestion4:
#if GERMAN
	.string "Bis hierher gut!\n"
	.string "Frage 4:\p"
	.string "Ist Falk der Leiter von Viola City, der\n"
	.string "Vogel-Pokémon nutzt?$"
#else
    .string "So far so good!\n"
    .string "Question 4:\p"
    .string "Is FALKNER the VIOLET GYM LEADER\n"
    .string "who uses bird POKéMON?$"
#endif

RadioTower1F_Text_QuizQuestion5:
#if GERMAN
	.string "Wow! Wieder richtig!\n"
	.string "Hier die letzte Frage:\p"
	.string "Haben die Slots im Game Corner\n"
	.string "Glumanda auf den Walzen?$"
#else
    .string "Wow! Right again!\n"
    .string "Here's the final question:\p"
    .string "Do GOLDENROD GAME CORNER's slots\n"
    .string "have CHARMANDER on their reels?$"
#endif

RadioTower1F_Text_QuizWin:
#if GERMAN
	.string "Bingo! Volltreffer!\n"
	.string "Glückwunsch!\p"
	.string "Hier dein Preis: ein Radio-Modul!$"
#else
    .string "Bingo! You got it!\n"
    .string "Congratulations!\p"
    .string "Here's your prize, a RADIO CARD!$"
#endif

RadioTower1F_Text_PokegearRadio:
#if GERMAN
	.string "{PLAYER}s PokéCom kann jetzt Radio\n"
	.string "empfangen!$"
#else
    .string "{PLAYER}'s POKéGEAR can now double as\n"
    .string "a RADIO!$"
#endif

RadioTower1F_Text_TuneIn:
#if GERMAN
	.string "Wir hoffen, dir gefällt unser Programm!$"
#else
    .string "Please tune in to our RADIO shows.$"
#endif

RadioTower1F_Text_WrongAnswer:
#if GERMAN
	.string "Oh, das ist aber schade. Das war leider\n"
	.string "falsch. Versuch’s einfach noch einmal!$"
#else
    .string "Oh, dear.\n"
    .string "Sorry, but you got it wrong.\p"
    .string "Please try again!$"
#endif

RadioTower1F_Text_DeclineQuiz:
#if GERMAN
	.string "Das geht schon in Ordnung. Komme\n"
	.string "einfach wieder, wenn du Lust hast.$"
#else
    .string "Oh. I see. Please see me if you\n"
    .string "change your mind.$"
#endif

RadioTower1F_Text_Lass:
#if GERMAN
	.string "Ben ist ein großartiger DJ.\p"
	.string "Seine sonore Stimme lässt mich\n"
	.string "dahinschmelzen!$"
#else
    .string "BEN is a fabulous DJ.\p"
    .string "His sweet voice makes me melt!$"
#endif

RadioTower1F_Text_Youngster:
#if GERMAN
	.string "Ich stehe absolut auf Margit, die\n"
	.string "Co-Moderatorin beim Pokémon-Talk!\p"
	.string "…Nun ja, zumindest glaube ich das.\n"
	.string "Bisher kenne ich ja bloß ihre Stimme!$"
#else
    .string "I love MARY, from POKéMON TALK.\p"
    .string "I only know what she sounds like,\n"
    .string "though.$"
#endif

RadioTower1F_Text_GruntM3Seen:
#if GERMAN
	.string "Wir haben endlich den Radioturm\n"
	.string "übernommen!\p"
	.string "Jetzt wird jeder die wahre Macht\n"
	.string "von Team Rocket spüren!\p"
	.string "Wir zeigen dir, wie furchtbar wir\n"
	.string "sein können!$"
#else
    .string "We've finally taken over the\n"
    .string "RADIO TOWER!\p"
    .string "Now everyone will get to experience\n"
    .string "the true terror of TEAM ROCKET!\p"
    .string "We'll show you how scary we are!$"
#endif

RadioTower1F_Text_GruntM3Beaten:
#if GERMAN
	.string "Zu stark! Tut mir leid, Boss…$"
#else
    .string "Too strong! I'm sorry boss…$"
#endif

RadioTower1F_Text_GruntM3After:
#if GERMAN
	.string "Du bist zu stark.\p"
	.string "Unser Plan könnte scheitern.\n"
	.string "Ich muss die anderen warnen…$"
#else
    .string "You're too strong.\p"
    .string "Our plan could be ruined. I must\n"
    .string "warn the others…$"
#endif

RadioTower1F_Text_Directory:
#if GERMAN
	.string "EG: Rezeption 1S: Geschäftsabteilung\n"
	.string "2S: Allgemeine Angelegenheiten 3S:\l"
	.string "Produktion 4S: Büro des Intendanten$"
#else
    .string "1F RECEPTION\n"
    .string "2F SALES\p"
    .string "3F PERSONNEL\n"
    .string "4F PRODUCTION\p"
    .string "5F DIRECTOR'S OFFICE$"
#endif

RadioTower1F_Text_GotRadio:
	.string "{PLAYER} erhält das Radio-Modul\n"
	.string "für den PokéCom!$"

GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special PickLotteryCornerTicket
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
#if GERMAN
	.string "Das ist die Pokémon-Lotterie.\p"
	.string "Wenn die Nummer des Tickets mit der\n"
	.string "eines deiner Pokémon übereinstimmt,\l"
	.string "gewinnst du einen\p"
	.string "Preis.\p"
	.string "Möchtest du teilnehmen??$"
#else
	.string "This is the POKéMON LOTTERY CORNER.\p"
	.string "If the LOTO TICKET's number matches\n"
	.string "the ID number of any of your POKéMON,\l"
	.string "you will receive a fabulous gift.\p"
	.string "Would you like to draw a POKéMON\n"
	.string "LOTO TICKET?$"
#endif

GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
#if GERMAN
	.string "Bitte komm morgen wieder.$"
#else
	.string "Please come back tomorrow.$"
#endif

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
#if GERMAN
	.string "Bitte, komm bald wieder.$"
#else
	.string "Please do visit again.$"
#endif

GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
#if GERMAN
	.string "Bitte wähle ein Loto Ticket.\n"
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"
#else
	.string "Please pick a LOTO TICKET.\n"
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"
#endif

GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
#if GERMAN
	.string "Die Nummer ist {STR_VAR_1}.\p"
	.string "Ich prüfe die Nummer, ob sie mit einem\n"
	.string "deiner Pokémon übereinstimmt. Warte\l"
	.string "bitte.$"
#else
	.string "The LOTO TICKET number is {STR_VAR_1}.\p"
	.string "I need to run a check on this number\n"
	.string "to see if it matches any of your\l"
	.string "POKéMON's ID numbers. Please wait.$"
#endif

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
#if GERMAN
	.string "Herzlichen Glückwunsch!\p"
	.string "Die ID-Nummer deines {STR_VAR_1} im Team\n"
	.string "stimmt ganz oder teilweise mit der des\l"
	.string "Lottoscheins überein!$"
#else
	.string "Congratulations!\p"
	.string "The ID number of your team's\n"
	.string "{STR_VAR_1} matches your\l"
	.string "LOTO TICKET's number!$"
#endif

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
#if GERMAN
	.string "Herzlichen Glückwunsch!\p"
	.string "Die ID-Nummer deines {STR_VAR_1} in deiner\n"
	.string "PC-Box stimmt teilweise oder ganz mit\l"
	.string "der des Lottoscheins überein!$"
#else
	.string "Congratulations!\p"
	.string "The ID number of your PC-boxed\n"
	.string "{STR_VAR_1} matches your\l"
	.string "LOTO TICKET's number!$"
#endif

GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
#if GERMAN
	.string "Tut mir leid.\n"
	.string "Leider kein Treffer.$"
#else
	.string "I'm sorry.\n"
	.string "None of the numbers matched.$"
#endif

GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
#if GERMAN
	.string "Zwei Ziffern stimmen überein, daher\n"
	.string "bekommst du den dritten Preis!\l"
	.string "Du gewinnst {STR_VAR_1}!$"
#else
	.string "Two digits matched, so you win the\n"
	.string "third prize!\l"
	.string "You've won the {STR_VAR_1}!$"
#endif

GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
#if GERMAN
	.string "Drei Ziffern stimmen überein, daher\n"
	.string "bekommst du den zweiten Preis!\l"
	.string "Du gewinnst {STR_VAR_1}!$"
#else
	.string "Three digits matched, so you win the\n"
	.string "second prize!\l"
	.string "You've won the {STR_VAR_1}!$"
#endif

GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
#if GERMAN
	.string "Vier Ziffern stimmen überein, daher\n"
	.string "bekommst du den ersten Preis!\l"
	.string "Du gewinnst {STR_VAR_1}!$"
#else
	.string "Four digits matched, so you win the\n"
	.string "first prize!\l"
	.string "You've won the {STR_VAR_1}!$"
#endif

GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
#if GERMAN
	.string "Meine Güte! Alle fünf Ziffern stimmen\n"
	.string "überein!\p"
	.string "Du hast den Jackpot geknackt!\n"
	.string "Du gewinnst {STR_VAR_1}!$"
#else
	.string "Oh, my goodness, all five digits\n"
	.string "matched!\p"
	.string "You've won the jackpot prize!\n"
	.string "You've won the {STR_VAR_1}!$"
#endif

GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
#if GERMAN
	.string "Oh! Du scheinst keinen Platz dafür zu\n"
	.string "haben.\p"
	.string "Wenn du wieder Platz in deinem\n"
	.string "Beutel hast, lass es mich wissen.$"
#else
	.string "Oh?\n"
	.string "You seem to have no room for this.\p"
	.string "Please make room in your BAG and\n"
	.string "let me know.$"
#endif

GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
#if GERMAN
	.string "{PLAYER}?\n"
	.string "Ja, ich habe dich schon erwartet.\p"
	.string "Diesen Preis habe ich für dich\n"
	.string "aufbewahrt. Hier, bitte schön!$"
#else
	.string "{PLAYER}?\n"
	.string "Yes, I've been expecting you.\p"
	.string "This is the prize we've been holding\n"
	.string "for you.$"
#endif

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
#if GERMAN
	.string "Bitte, komm bald wieder.$"
#else
	.string "Please do visit again.$"
#endif


