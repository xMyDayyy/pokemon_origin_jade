LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox BrendansHouse_1F_Text_ChampionVisit, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
#if GERMAN
	.string "Mutter: Siehst du, {PLAYER}?\n"
	.string "Hier ist es doch auch schön, oder nicht?$"
#else
	.string "MOM: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"
#endif

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
#if GERMAN
	.string "Die Pokémon machen für uns den Umzug,\n"
	.string "räumen alles ein und machen sauber.\l"
	.string "Das ist doch so etwas von praktisch!\p"
	.string "{PLAYER}, dein Zimmer ist oben.\n"
	.string "Schau es dir doch mal an, Spatz!\p"
	.string "Vati hat dir eine neue Uhr zur\n"
	.string "Begrüßung geschenkt.\l"
	.string "Vergiss nicht, sie einzustellen!$"
#else
	.string "The mover's POKéMON do all the work\n"
	.string "of moving us in and cleaning up after.\l"
	.string "This is so convenient!\p"
	.string "{PLAYER}, your room is upstairs.\n"
	.string "Go check it out, dear!\p"
	.string "DAD bought you a new clock to mark\n"
	.string "our move here.\l"
	.string "Don't forget to set it!$"
#endif

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
#if GERMAN
	.string "Mutter: Nun, {PLAYER}?\p"
	.string "Bist du nicht neugierig, dein neues\n"
	.string "Zimmer zu sehen?$"
#else
	.string "MOM: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing your\n"
	.string "very own room?$"
#endif

PlayersHouse_1F_Text_GoSetTheClock:
#if GERMAN
	.string "Mutter: {PLAYER}, Schatz!\p"
	.string "Stell bitte die Uhr in deinem Zimmer\n"
	.string "ein.$"
#else
	.string "MOM: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"
#endif

PlayersHouse_1F_Text_OhComeQuickly:
#if GERMAN
	.string "Mutter: Oh! {PLAYER}! {PLAYER}!\n"
	.string "Schnell! Komm schnell her!$"
#else
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Quick! Come quickly!$"
#endif

PlayersHouse_1F_Text_MaybeDadWillBeOn:
#if GERMAN
	.string "Mutter: Da! Da ist die Arena von\n"
	.string "Blütenburg City!\l"
	.string "Ich glaube, Vati ist im Fernsehen!$"
#else
	.string "MOM: Look! It's PETALBURG GYM!\n"
	.string "Maybe DAD will be on!$"
#endif

PlayersHouse_1F_Text_ItsOverWeMissedHim:
#if GERMAN
	.string "Mutter: Oh… Schon vorbei.\p"
	.string "Ich glaube, Vati war im Fernsehen und\n"
	.string "wir haben ihn verpasst. Schade!$"
#else
	.string "MOM: Oh… It's over.\p"
	.string "I think DAD was on, but we missed him.\n"
	.string "Too bad.$"
#endif

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
#if GERMAN
	.string "Ach ja.\n"
	.string "Einer von Vatis Freunden lebt hier.\p"
	.string "Prof. Birk ist sein Name.\p"
	.string "Er lebt gleich nebenan, daher solltest\n"
	.string "du hinübergehen und dich vorstellen.$"
#else
	.string "Oh, yes.\n"
	.string "One of DAD's friends lives in town.\p"
	.string "PROF. BIRCH is his name.\p"
	.string "He lives right next door, so you should\n"
	.string "go over and introduce yourself.$"
#endif

PlayersHouse_1F_Text_SeeYouHoney:
#if GERMAN
	.string "Mutter: Bis später, Spatz!$"
#else
	.string "MOM: See you, honey!$"
#endif

PlayersHouse_1F_Text_DidYouMeetProfBirch:
#if GERMAN
	.string "Mutter: Hast du dich bei Prof. Birk\n"
	.string "vorgestellt?$"
#else
	.string "MOM: Did you introduce yourself to\n"
	.string "PROF. BIRCH?$"
#endif

PlayersHouse_1F_Text_YouShouldRestABit:
#if GERMAN
	.string "Mutter: Wie geht es dir, {PLAYER}?\n"
	.string "Du siehst müde aus.\p"
	.string "Ich denke, du solltest dich etwas\n"
	.string "ausruhen.$"
#else
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"
#endif

PlayersHouse_1F_Text_TakeCareHoney:
#if GERMAN
	.string "Mutter: Pass auf dich auf, Schatz!$"
#else
	.string "MOM: Take care, honey!$"
#endif

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
#if GERMAN
	.string "Mutter: Oh! Hat Vati dir den Orden\n"
	.string "gegeben?\p"
	.string "Dann ist das hier von deiner Mutti!$"
#else
	.string "MOM: Oh? Did DAD give you that BADGE?\p"
	.string "Then here's something from your MOM!$"
#endif

PlayersHouse_1F_Text_DontPushYourselfTooHard:
#if GERMAN
	.string "Überanstreng dich nicht, Liebes.\n"
	.string "Du kannst jederzeit nach Hause kommen.\l"
	.string "\p"
	.string "Und jetzt nichts wie los, Schatz!$"
#else
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"
#endif

PlayersHouse_1F_Text_IsThatAPokenav:
#if GERMAN
	.string "Mutter: Was hast du denn da Schönes?\n"
	.string "Einen PokéCom? Den hat dir jemand von\l"
	.string "Devon gegeben?\p"
	.string "Und, Liebling? Möchtest du nicht deine\n"
	.string "Mutter ins Verzeichnis aufnehmen?\p"
	.string "… … …$"
#else
	.string "MOM: What is that, honey? A POKéGEAR?\n"
	.string "Someone from DEVON gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"
#endif

PlayersHouse_1F_Text_RegisteredMom:
#if GERMAN
	.string "Mutter wurde im PokéCom-Verzeichnis\n"
	.string "eingetragen.$"
#else
	.string "Registered MOM\n"
	.string "in the POKéGEAR.$"
#endif

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
#if GERMAN
	.string "Interviewer: Das war unsere Reportage\n"
	.string "über die Arena in Blütenburg City.$"
#else
	.string "INTERVIEWER: …We brought you this\n"
	.string "report from in front of PETALBURG GYM.$"
#endif

PlayersHouse_1F_Text_TheresAMovieOnTV:
#if GERMAN
	.string "Da läuft gerade ein Film.\p"
	.string "Zwei Männer tanzen auf riesengroßen\n"
	.string "Klaviertasten.\p"
	.string "Aber es wird Zeit aufzubrechen!$"
#else
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"
#endif

PlayersHouse_1F_Text_RunningShoesManual:
#if GERMAN
	.string "Dies ist die Bedienungsanleitung für\n"
	.string "die Turbotreter.\p"
	.string "“Halte den B-Knopf gedrückt, wenn du\n"
	.string "diese Turbotreter anhast, um zu rennen!\p"
	.string "Schlüpf in diese Turbotreter und\n"
	.string "erobere die Welt da draußen!”$"
#else
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"
#endif

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
#if GERMAN
	.string "Vater: Hm?\p"
	.string "Hey, das ist ja {PLAYER}!\p"
	.string "Du hast uns ja schon lange nicht mehr\n"
	.string "besucht… Du siehst irgendwie stärker\l"
	.string "aus.\p"
	.string "Das ist zumindest mein Eindruck. Aber\n"
	.string "dein alter Herr gibt noch nicht auf.\p"
	.string "Oh, ich habe hier etwas für dich.\n"
	.string "Das soll ich dir von einem Mr. Brack\l"
	.string "geben.$"
#else
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"
#endif

PlayersHouse_1F_Text_PortsInSlateportLilycove:
#if GERMAN
	.string "Vater: Hm, ein Ticket für eine Fähre?\n"
	.string "\p"
	.string "Ich weiß, dass es in Graphitport City\n"
	.string "und Seegrasulb City Anlegestellen für\l"
	.string "Fähren gibt.$"
#else
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"
#endif

PlayersHouse_1F_Text_BetterGetBackToGym:
#if GERMAN
	.string "Ich muss jetzt wieder in die Arena von\n"
	.string "Blütenburg City.\p"
	.string "Ich danke dir, dass du dich während\n"
	.string "meiner Abwesenheit um das Haus\l"
	.string "kümmerst.$"
#else
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"
#endif

PlayersHouse_1F_Text_DadShouldStayLonger:
#if GERMAN
	.string "Mutter: Das ist wieder typisch dein\n"
	.string "Vater…\p"
	.string "Da kommt er das erste Mal nach ewigen\n"
	.string "Zeiten nach Hause und spricht nur über\l"
	.string "Pokémon.\p"
	.string "Er sollte sich lieber ausruhen und\n"
	.string "etwas hier bleiben!$"
#else
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"
#endif

PlayersHouse_1F_Text_IsThatABreakingStory:
#if GERMAN
	.string "Mutter: Sind das Sondernachrichten?$"
#else
	.string "MOM: Is that a breaking news story?$"
#endif

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
#if GERMAN
	.string "Hier sind die Sondernachrichten.\p"
	.string "Wir haben die Meldung erhalten, dass in\n"
	.string "der Hoenn-Region ein Grssss…\l"
	.string "farbiges Pokémon gesichtet wurde.\p"
	.string "Die Identität des Pokémon konnte\n"
	.string "bisher nicht festgestellt werden.\p"
	.string "Und damit schalten wir wieder um in\n"
	.string "unser laufendes Programm.$"
#else
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"
#endif

PlayersHouse_1F_Text_WhatColorDidTheySay:
#if GERMAN
	.string "Mutter: {PLAYER}, hast du das\n"
	.string "gehört?!? \p"
	.string "Was hat der Sprecher gesagt? Welche\n"
	.string "Farbe hat das Pokémon?$"
#else
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"
#endif

PlayersHouse_1F_Text_StillUnknownPokemon:
#if GERMAN
	.string "Mutter: Also, ist das nicht unglaublich?\n"
	.string "Es gibt tatsächlich noch unbekannte\l"
	.string "Pokémon!$"
#else
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"
#endif

BrendansHouse_1F_Text_ChampionVisit:
#if GERMAN
	.string "Oh! Besuch?\p"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "Du bist {PLAYER}{KUN} aus Johto!\p"
	.string "Mein Mann hat gestern noch von dir\n"
	.string "gesprochen. Er verfolgt die Liga im\l"
	.string "Radio, jeden Abend.\p"
	.string "Setz dich doch. Ach, du willst sicher\n"
	.string "weiter - ihr Trainer habt es ja immer\l"
	.string "eilig.$"
#else
	.string "Oh! A visitor?\p"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "You're {PLAYER}{KUN} from JOHTO!\p"
	.string "My husband was talking about you\n"
	.string "just yesterday. He follows the\l"
	.string "LEAGUE on the radio every evening.\p"
	.string "Do sit down. Oh, you'll want to be\n"
	.string "off - you TRAINERS are always in\l"
	.string "a hurry.$"
#endif

@ HnS: this house belongs to Norman's family.
LittlerootTown_BrendansHouse_1F_EventScript_NormansFrau::
	goto_if_ge VAR_PETALBURG_GYM_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_NormansFrauGymOpen
	msgbox LittlerootTown_BrendansHouse_1F_Text_NormansFrau, MSGBOX_NPC
	end

LittlerootTown_BrendansHouse_1F_EventScript_NormansFrauGymOpen::
	msgbox LittlerootTown_BrendansHouse_1F_Text_NormansFrauGymOpen, MSGBOX_NPC
	end

LittlerootTown_BrendansHouse_1F_EventScript_NormansKind::
	msgbox LittlerootTown_BrendansHouse_1F_Text_NormansKind, MSGBOX_NPC
	end

LittlerootTown_BrendansHouse_1F_Text_NormansFrau:
#if GERMAN
	.string "Ah, ein Besucher! Mein Mann Norman\n"
	.string "leitet die Arena in Blütenburg City.\p"
	.string "Zurzeit ist sie geschlossen. Er baut\n"
	.string "um und kommt kaum zur Ruhe.\p"
	.string "Unser Sohn Brix ist auch mit seinen\n"
	.string "Pokémon unterwegs.$"
#else
	.string "Ah, a visitor! My husband NORMAN\n"
	.string "runs the GYM in PETALBURG CITY.\p"
	.string "It's closed at the moment. He's\n"
	.string "rebuilding it and hardly rests.\p"
	.string "Our son BRENDAN is traveling\n"
	.string "with his POKéMON, too.$"
#endif

LittlerootTown_BrendansHouse_1F_Text_NormansFrauGymOpen:
#if GERMAN
	.string "Ah, ein Besucher! Mein Mann Norman\n"
	.string "leitet die Arena in Blütenburg City.\p"
	.string "Der Umbau ist endlich fertig. Seitdem\n"
	.string "ist er gar nicht mehr zu bremsen.\p"
	.string "Wenn du ihn triffst: Sag ihm, er soll\n"
	.string "sich nicht überarbeiten!$"
#else
	.string "Ah, a visitor! My husband NORMAN\n"
	.string "runs the GYM in PETALBURG CITY.\p"
	.string "The rebuilding is finally done. There's\n"
	.string "been no stopping him since.\p"
	.string "If you meet him, tell him not to\n"
	.string "overwork himself!$"
#endif

LittlerootTown_BrendansHouse_1F_Text_NormansKind:
#if GERMAN
	.string "Papa ist der Arenaleiter von Blütenburg\n"
	.string "City! Und mein großer Bruder Brix ist\l"
	.string "auch Trainer!\p"
	.string "Wenn ich groß bin, fordere ich\n"
	.string "beide heraus - versprochen!$"
#else
	.string "Dad is the GYM LEADER of\n"
	.string "PETALBURG CITY! And my big\l"
	.string "brother BRENDAN is a TRAINER!\p"
	.string "When I'm big, I'll challenge\n"
	.string "them both - promise!$"
#endif
