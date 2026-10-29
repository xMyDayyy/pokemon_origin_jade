RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
#if !IS_HNS
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
#endif
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_HOENN_RECEIVED_POKENAV
#if IS_HNS
	@ Origin Jade: adds Mr. Stone to the PokeNav contacts.
	setflag FLAG_MET_MR_STONE
#endif
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
#if IS_HNS
	@ Origin Jade: the held Exp. Share if the key item is already in the bag.
	checkitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_3F_EventScript_GiveSmallExpShare
#endif
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
RustboroCity_DevonCorp_3F_EventScript_ReceivedExpShare::
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

#if IS_HNS
RustboroCity_DevonCorp_3F_EventScript_GiveSmallExpShare::
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto RustboroCity_DevonCorp_3F_EventScript_ReceivedExpShare
#endif

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
#if GERMAN
	.string "Ich bin Mr. Trumm, der Präsident der\n"
	.string "Devon Corporation.\p"
	.string "Ich muss etwas mit dir besprechen!\p"
	.string "Du hast unseren Mitarbeitern nicht nur\n"
	.string "einmal, sondern zweimal aus der Klemme\l"
	.string "geholfen!\p"
	.string "Du bist so außergewöhnlich, dass ich\n"
	.string "dich gerne um einen Gefallen bitten\l"
	.string "möchte.\p"
	.string "Ich weiß, dass du ein Paket zur Werft\n"
	.string "in Graphitport City bringen willst.\p"
	.string "Könntest du auf dem Weg nicht\n"
	.string "auch in Faustauhaven Halt machen?\p"
	.string "Und Troy in Faustauhaven einen Brief\n"
	.string "von mir überbringen?$"
#else
	.string "I'm MR. STONE, the PRESIDENT of\n"
	.string "the DEVON CORPORATION.\p"
	.string "I'd just got word about you!\p"
	.string "You saved our staff not just once,\n"
	.string "but twice!\p"
	.string "I have a favor to ask of an amazing\n"
	.string "person like you.\p"
	.string "I understand that you're delivering\n"
	.string "a package to SLATEPORT's SHIPYARD.\p"
	.string "Well, on the way, could you stop off in\n"
	.string "DEWFORD TOWN?\p"
	.string "I was hoping that you'd deliver a\n"
	.string "LETTER to STEVEN in DEWFORD.$"
#endif

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
#if GERMAN
	.string "Mr. Trumm: Nun, du sollst wissen, dass\n"
	.string "ich ein einflussreicher Präsident bin.\p"
	.string "Und daher weiß ich einen echten\n"
	.string "Gefallen auch zu schätzen!\p"
	.string "Hab vielen Dank für deine Hilfe!$"
#else
	.string "MR. STONE: Now, you should know that\n"
	.string "I am a great PRESIDENT.\p"
	.string "And that means I know how to value\n"
	.string "a real favor!\p"
	.string "Thank you very much for your help!$"
#endif

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
#if GERMAN
	.string "{PLAYER} erhält den PokéCom.$"
#else
	.string "{PLAYER} received a POKéGEAR.$"
#endif

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
#if GERMAN
	.string "Mr. Trumm: Ich habe übrigens gehört,\n"
	.string "dass zwei kriminelle Teams - Magma\l"
	.string "und Aqua heißen sie - überall nur\l"
	.string "Ärger bereiten.\p"
	.string "Vielleicht solltest du eine Pause\n"
	.string "einlegen, bevor du dich wieder auf den\l"
	.string "Weg machst.$"
#else
	.string "MR. STONE: By the way, I've heard\n"
	.string "that sinister criminals--MAGMA and\l"
	.string "AQUA, I believe--have been making\l"
	.string "trouble far and wide.\p"
	.string "I think it would be best if you rested\n"
	.string "up before you go on your way.$"
#endif

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
#if GERMAN
	.string "Mr. Trumm: Nun, {PLAYER}{KUN},\n"
	.string "sei vorsichtig und pass auf dich auf!$"
#else
	.string "MR. STONE: Well, then, {PLAYER}{KUN},\n"
	.string "go with caution and care!$"
#endif

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
#if GERMAN
	.string "Mr. Trumm: Ich verlasse mich auf dich!$"
#else
	.string "MR. STONE: I'm counting on you!$"
#endif

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
#if GERMAN
	.string "Mr. Trumm: Du hast meinen Brief\n"
	.string "überbracht? Herzlichen Dank!\p"
	.string "Dies ist ein Dankeschön von mir.\n"
	.string "Es wird dir als Trainer sicher helfen.$"
#else
	.string "MR. STONE: You delivered my LETTER?\n"
	.string "Thank you kindly!\p"
	.string "This is my way of thanking you.\n"
	.string "It should help you, a TRAINER.$"
#endif

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
#if GERMAN
#if IS_HNS
	@ Origin Jade: names the Kleiner EP-Teiler he gives (the EP-Teiler is a key item).
	.string "Mr. Trumm: Trägt ein Pokémon den\n"
	.string "Kleinen EP-Teiler, so erhält es in\l"
	.string "jedem Kampf Erfahrungspunkte.\p"
	.string "Auch wenn es gar nicht am Kampf\n"
	.string "teilnimmt.\p"
	.string "Ich würde sagen, der Kleine\n"
	.string "EP-Teiler ist sehr nützlich, um\l"
	.string "schwache Pokémon aufzuziehen.$"
#else
	.string "Mr. Trumm: Trägt ein Pokémon den\n"
	.string "EP-Teiler, so erhält es in jedem Kampf\l"
	.string "Erfahrungspunkte.\p"
	.string "Auch wenn es gar nicht am Kampf\n"
	.string "teilnimmt.\p"
	.string "Ich würde sagen, der EP-Teiler ist sehr\n"
	.string "nützlich, um schwache Pokémon\l"
	.string "aufzuziehen.$"
#endif
#else
	.string "MR. STONE: A POKéMON holding that\n"
	.string "EXP. SHARE will be given some of the\l"
	.string "EXP Points from battle.\p"
	.string "It will get EXP Points even if it didn't\n"
	.string "actually battle.\p"
	.string "I would say EXP. SHARE is quite useful\n"
	.string "for raising weak POKéMON.$"
#endif

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
#if GERMAN
	.string "Mr. Trumm: Schon in meiner Jugend habe\n"
	.string "ich mich voll auf die Arbeit\l"
	.string "konzentriert.\p"
	.string "Deshalb weiß ich auch nicht unbedingt,\n"
	.string "was gerade im Trend liegt.\p"
	.string "Wollen alle jungen Leute Trainer in\n"
	.string "der Pokémon Liga werden?$"
#else
	.string "MR. STONE: Since my youth, I've immersed\n"
	.string "myself in work.\p"
	.string "Consequently, I'm not familiar with\n"
	.string "trends and that sort of thing.\p"
	.string "But do young people all want to be\n"
	.string "TRAINERS in the POKéMON LEAGUE?$"
#endif

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
#if GERMAN
	.string "Dies ist die zweite Etage der Devon\n"
	.string "Corporation.\p"
	.string "Hier befindet sich das Büro des\n"
	.string "Präsidenten.\p"
	.string "Nun ja, ich kann dir gar nicht sagen, wie\n"
	.string "dankbar ich dir für deine Taten bin.\p"
	.string "Ähm… Äh, das Paket, das du uns\n"
	.string "zurückgebracht hast…\p"
	.string "Darf ich dich bitten, es zur Werft\n"
	.string "in Graphitport City zu bringen?\p"
	.string "Es wäre fürchterlich, wenn es den\n"
	.string "Dieben erneut in die Hände fallen würde.\p"
	.string "Äh… Hehehe, also, äh, kann ich auch\n"
	.string "dieses Mal wieder mit dir rechnen?\p"
	.string "Ach, da fällt mir ein… Würdest du mich\n"
	.string "einen Moment entschuldigen?$"
#else
	.string "This is the DEVON CORPORATION's\n"
	.string "third floor.\p"
	.string "Our PRESIDENT's OFFICE is on\n"
	.string "this floor.\p"
	.string "Anyway, I can't tell you how much I'm\n"
	.string "grateful for what you've done.\p"
	.string "Um… By the way, that parcel\n"
	.string "you got back for us…\p"
	.string "Could I get you to deliver that to\n"
	.string "the SHIPYARD in SLATEPORT?\p"
	.string "It would be awful if those robbers\n"
	.string "tried to take it again.\p"
	.string "Uh… Hehehe, so, uh, could I count\n"
	.string "on you to do that for me?\p"
	.string "Oh, that's right.\n"
	.string "Could you wait here a second?$"
#endif

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
#if GERMAN
	.string "Unser Präsident würde gerne kurz mit\n"
	.string "dir sprechen.\p"
	.string "Komm bitte mit mir.$"
#else
	.string "Our PRESIDENT would like to have\n"
	.string "a word with you.\p"
	.string "Please come with me.$"
#endif

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
#if GERMAN
	.string "Bitte, hier entlang.$"
#else
	.string "Please, go ahead.$"
#endif

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
#if GERMAN
	.string "Wenn du die Werft in Graphitport City\n"
	.string "besuchst, solltest du mit Kapt. Brigg\l"
	.string "sprechen.$"
#else
	.string "If you visit the SHIPYARD in SLATEPORT,\n"
	.string "you should go see CAPT. STERN.$"
#endif

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
#if GERMAN
	.string "Devons neue Produkte, der Wiederball\n"
	.string "und der Timerball, sind mittlerweile sehr\l"
	.string "populär unter den Trainern.$"
#else
	.string "DEVON's new products, the REPEAT BALL\n"
	.string "and TIMER BALL, have become hugely\l"
	.string "popular among TRAINERS.$"
#endif

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
#if GERMAN
	.string "Eine Kollektion seltener Steine und\n"
	.string "Mineralien - gesammelt vom Präsidenten.$"
#else
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by the PRESIDENT.$"
#endif

