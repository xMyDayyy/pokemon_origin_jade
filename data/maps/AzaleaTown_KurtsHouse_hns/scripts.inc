AzaleaTown_KurtsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_KurtsHouse_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_KurtsHouse_OnTransition
	.byte 0

AzaleaTown_KurtsHouse_OnTransition::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup
	end

AzaleaTown_KurtsHouse_OnFrame::
	map_script_2 VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_ReturnFromWell
	.2byte 0

AzaleaTown_KurtsHouse_EventScript_KurtBefore::
	lock
	faceplayer
	msgbox KurtsHouse_Text_KurtMakingBallsMustWait, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_PlayerMove
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	setvar VAR_AZALEA_TOWN_STATE, 2
	release
	end

AzaleaTown_KurtsHouse_EventScript_PlayerMove::
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_KurtsHouse_Movement_Player
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_KURT_BEFORE, AzaleaTown_KurtsHouse_Movement_KurtWalkDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_AZALEA_TOWN_KURT_BEFORE
	setflag FLAG_HIDE_KURT_1
	setflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_KURT_2, AzaleaTown_KurtsHouse_EventScript_Girl2
	goto_if_set FLAG_HIDE_KURT_1, AzaleaTown_KurtsHouse_EventScript_Girl3
	msgbox KurtsHouse_Text_GranddaughterSlowpokeGone, MSGBOX_DEFAULT
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl2::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 3, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 4, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_KurtsHouse_EventScript_Girl4
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_Girl5
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_Girl5

	msgbox KurtsHouse_Text_GranddaughterDad, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl3::
	msgbox KurtsHouse_Text_GranddaughterLonely, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl4::
	msgbox KurtsHouse_Text_GranddaughterSlowpokeBack, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_Girl5::
	msgbox KurtsHouse_Text_GranddaughterSound, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_ReturnFromWellSetup::
	setobjectmovementtype LOCALID_AZALEA_TOWN_KURT, MOVEMENT_TYPE_FACE_DOWN
	end

AzaleaTown_KurtsHouse_EventScript_ReturnFromWell::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox KurtsHouse_Text_KurtHonoredToMakeBalls, MSGBOX_DEFAULT
	giveitem ITEM_FAST_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KurtsHouse_Text_KurtBallsFromApricorns, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	setvar VAR_AZALEA_TOWN_STATE, 4
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall::
	checkitem ITEM_GS_BALL
	goto_if_eq VAR_RESULT, TRUE, AzaleaTown_KurtsHouse_EventScript_KurtGsBall
	return

AzaleaTown_KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_KurtsHouse_EventScript_KurtGsBall2
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, AzaleaTown_KurtsHouse_EventScript_KurtGsBall3
	msgbox KurtsHouse_Text_KurtAskYouHaveAnApricorn, MSGBOX_DEFAULT
	closemessage
	call_if_unset FLAG_CAUGHT_CELEBI, AzaleaTown_KurtsHouse_EventScript_KurtCheckGSBall
AzaleaTown_KurtsHouse_EventScript_Kurt2::
	special CreateKurtBallShop
	waitstate
	goto_if_eq VAR_RESULT, FALSE, AzaleaTown_KurtsHouse_EventScript_KurtCancel
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	call_if_eq VAR_FACING, DIR_EAST, AzaleaTown_KurtsHouse_EventScript_TurnWest
	call_if_eq VAR_FACING, DIR_WEST, AzaleaTown_KurtsHouse_EventScript_TurnEast
	call_if_eq VAR_FACING, DIR_NORTH, AzaleaTown_KurtsHouse_EventScript_TurnSouth
	goto_if_eq VAR_0x8005, 1, AzaleaTown_KurtsHouse_EventScript_SingularBall
	bufferitemname STR_VAR_1, VAR_0x8004
	buffernumberstring STR_VAR_2, VAR_0x8005
	msgbox KurtsHouse_Text_KurtFinishedPlural, MSGBOX_DEFAULT
	message KurtsHouse_Text_KurtObtainedPlural
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	additem VAR_0x8004, VAR_0x8005
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_TurnSouth::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_SOUTH
	return
AzaleaTown_KurtsHouse_EventScript_TurnWest::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_WEST
	return
AzaleaTown_KurtsHouse_EventScript_TurnEast::
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_EAST
	return


AzaleaTown_KurtsHouse_EventScript_SingularBall::
	bufferitemname STR_VAR_1, VAR_0x8004
	msgbox KurtsHouse_Text_KurtFinishedSingular, MSGBOX_DEFAULT
	message KurtsHouse_Text_KurtObtainedSingular
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	additem VAR_0x8004, VAR_0x8005
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtCancel::
	closemessage
	turnobject LOCALID_AZALEA_TOWN_KURT, DIR_NORTH
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall::
	msgbox KurtsHouse_Text_KurtWhatIsThat, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_GS_BALL
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	playse SE_BANG
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Making_Ball
	waitmovement 0
	faceplayer
	msgbox KurtsHouse_Text_KurtThisBallStartedToShake, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_AZALEA_TOWN_KURT, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	waitse
	playse SE_M_PETAL_DANCE
	waitse
	applymovement LOCALID_AZALEA_TOWN_KURT, AzaleaTownKurt_Movement_Look_Around
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTownKurt_Movement_Look_Around
	waitmovement 0
	waitmovement 0
AzaleaTown_KurtsHouse_EventScript_KurtGsBall2::
	msgbox KurtsHouse_Text_Kurt_Whatwasthat, MSGBOX_DEFAULT
	setvar VAR_AZALEA_TOWN_STATE, 8
	closemessage
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGsBall3::
	msgbox KurtsHouse_Text_Forest, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox KurtsHouse_Text_BallAnyway, MSGBOX_DEFAULT
	closemessage
	goto AzaleaTown_KurtsHouse_EventScript_Kurt2
	release
	end
KurtsHouse_Text_BallAnyway:
#if GERMAN
	.string "Wie auch immer, soll ich dir ein\n"
	.string "paar Bälle machen?$"
#else
	.string "Anyway, can I make you some BALLS?$"
#endif

AzaleaTown_KurtsHouse_EventScript_OakPhoto::
	msgbox KurtsHouse_Text_OakPhoto, MSGBOX_SIGN
	closemessage
	end

AzaleaTown_KurtsHouse_EventScript_CelebiStatue::
	msgbox KurtsHouse_Text_CelebiStatue, MSGBOX_SIGN
	closemessage
	end

AzaleaTownKurt_Movement_Look_Around:
	face_left
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_down
	delay_8
	face_left
	step_end

AzaleaTownKurt_Movement_Making_Ball:
	face_up
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	delay_8
	walk_in_place_fast_up
	step_end

AzaleaTown_KurtsHouse_Movement_Player:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

AzaleaTown_KurtsHouse_Movement_KurtWalkDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

KurtsHouse_Text_KurtGetStarted:
#if GERMAN
	.string "Kurt: Ich fange jetzt an!$"
#else
	.string "KURT: I'll get started right now!$"
#endif

KurtsHouse_Text_KurtMakingBallsMustWait:
#if GERMAN
	.string "Hm? Wer bist du denn?\p"
	.string "Oh, {PLAYER} heißt du also!\n"
	.string "Bist du hier, weil du willst, dass ich ein\l"
	.string "paar Bälle für dich herstelle?\p"
	.string "Tut mir leid, aber das muss warten.\p"
	.string "Kennst du Team Rocket? Keine Sorge, du\n"
	.string "schläfst besser, wenn nicht.\l"
	.string "Ich werde mich kurz fassen.\p"
	.string "Team Rocket missbraucht unschuldige\n"
	.string "Pokémon für ihre Schandtaten.\l"
	.string "Diese Typen sind einfach das Letzte.\p"
	.string "Sie hatten sich eigentlich vor drei\n"
	.string "Jahren aufgelöst, aber nun…\p"
	.string "Na ja, genau diese Bande schneidet\n"
	.string "jetzt den Flegmon im Brunnen die Ruten\l"
	.string "ab und verdient sich damit eine goldene\l"
	.string "Nase.\p"
	.string "Aber ich gehe jetzt zu ihnen und\n"
	.string "erteile ihnen eine Lektion!\p"
	.string "Haltet durch, Flegmon!\n"
	.string "Der alte Kurt eilt euch zur Rettung!$"
#else
	.string "Hm? Who are you?\p"
	.string "{PLAYER}, eh? You want me to make\n"
	.string "some BALLS?\p"
	.string "Sorry, but that'll have to wait.\p"
	.string "Do you know TEAM ROCKET?\n"
	.string "Ah, don't worry.\p"
	.string "I'll tell you anyhow.\p"
	.string "TEAM ROCKET's an evil gang that\n"
	.string "uses POKéMON for their dirty work.\p"
	.string "They're supposed to have disbanded\n"
	.string "three years ago.\p"
	.string "Anyway, they're at the WELL,\n"
	.string "cutting off SLOWPOKETAILS to sell!\p"
	.string "So I'm going to go give them a\n"
	.string "lesson in pain!\p"
	.string "Hang on, SLOWPOKE! Old KURT\n"
	.string "is on his way!$"
#endif

KurtsHouse_Text_KurtHonoredToMakeBalls:
#if GERMAN
	.string "Kurt: Hi, {PLAYER}!\p"
	.string "Die Situation am Brunnen hast du\n"
	.string "wie ein echter Held gemeistert.\p"
	.string "Ich mag deinen Stil!\p"
	.string "Ich wäre geehrt, für jemanden wie dich\n"
	.string "Pokébälle anfertigen zu dürfen.\p"
	.string "Im Moment habe ich nur das hier,\n"
	.string "aber nimm es.$"
#else
	.string "KURT: Hi, {PLAYER}!\p"
	.string "You handled yourself like a\n"
	.string "real hero at the WELL.\p"
	.string "I like your style!\p"
	.string "I would be honored to make\n"
	.string "BALLS for a trainer like you.\p"
	.string "This is all I have now, \n"
	.string "but take it.$"
#endif

KurtsHouse_Text_KurtBallsFromApricorns:
#if GERMAN
	.string "Kurt: Ich kann aus Beeren Spezialbälle\n"
	.string "anfertigen!\p"
	.string "Pflücke überall fleißig Beeren von den\n"
	.string "Bäumen und bringe sie zu mir.\l"
	.string "Ich verarbeite sie dann zu Bällen.$"
#else
	.string "KURT: I make BALLS from BERRIES.\p"
	.string "Collect them from trees and bring\n"
	.string "'em to me.\p"
	.string "I'll make POKé BALLS out of them.$"
#endif

KurtsHouse_Text_KurtAskYouHaveAnApricorn:
#if GERMAN
	.string "Kurt: Oh, wie ich sehe, hast du ein\n"
	.string "paar Beeren mitgebracht!\p"
	.string "Na schön! Dann mache ich mich\n"
	.string "mal ans Verarbeiten!$"
#else
	.string "KURT: You have BERRIES for me?\p"
	.string "Fine! I'll turn them into POKé BALLS.$"
#endif

KurtsHouse_Text_KurtThatsALetdown:
#if GERMAN
	.string "Kurt: Ich sehe keine 5 {STR_VAR_1}!$"
#else
	.string "KURT: I don't see any {STR_VAR_1}s!$"
#endif

KurtsHouse_Text_KurtFinishedPlural:
#if GERMAN
	.string "Kurt: {PLAYER}!\n"
	.string "Deine {STR_VAR_1}e sind fertig. Hier!\p"
	.string "{PLAYER} erhält {STR_VAR_2} {STR_VAR_1}e!$"
#else
	.string "KURT: {PLAYER}!\n"
	.string "Your {STR_VAR_1}s are done. Here!\p"
	.string "{PLAYER} obtained\n"
	.string "{STR_VAR_2} {STR_VAR_1}s!$"
#endif

KurtsHouse_Text_KurtObtainedPlural:
	.string "{PLAYER} erhält\n"
	.string "{STR_VAR_2} {STR_VAR_1}e!$"

KurtsHouse_Text_KurtFinishedSingular:
#if GERMAN
	.string "Kurt: {PLAYER}!\n"
	.string "Dein {STR_VAR_1} ist fertig. Hier!\p"
	.string "{PLAYER} erhält den {STR_VAR_1}!$"
#else
	.string "KURT: {PLAYER}!\n"
	.string "Your {STR_VAR_1} is done. Here!\p"
	.string "{PLAYER} obtained\n"
	.string "the {STR_VAR_1}!$"
#endif

KurtsHouse_Text_KurtObtainedSingular:
	.string "{PLAYER} erhält\n"
	.string "den {STR_VAR_1}!$"

KurtsHouse_Text_KurtTurnedOutGreat:
#if GERMAN
	.string "Kurt: Dieses Mal habe ich mich\n"
	.string "wirklich selbst übertroffen!\p"
	.string "Versuche doch mal, ein Pokémon\n"
	.string "damit zu fangen!$"
#else
	.string "KURT: That turned out great.\p"
	.string "Try catching POKéMON with it.$"
#endif

KurtsHouse_Text_KurtWhatIsThat:
#if GERMAN
	.string "W-was ist das?\p"
	.string "Ich habe sowas noch nie gesehen.\p"
	.string "Es sieht aus wie ein Pokéball,\n"
	.string "aber es scheint etwas anderes zu sein.\p"
	.string "Lass es mich prüfen.$"
#else
	.string "Wh-what is that?\p"
	.string "I've never seen one before.\p"
	.string "It looks a like a POKé BALL, but\n"
	.string "it appears to be something else.\p"
	.string "Let me check it for you.$"
#endif

KurtsHouse_Text_KurtImCheckingItNow:
#if GERMAN
	.string "Ich prüfe es gerade.$"
#else
	.string "I'm checking it now.$"
#endif

KurtsHouse_Text_KurtAhHaISee:
#if GERMAN
	.string "Ah-ha! Verstehe! So ist das…$"
#else
	.string "Ah-ha! I see! So…$"
#endif

KurtsHouse_Text_KurtThisBallStartedToShake:
#if GERMAN
	.string "{PLAYER}!\p"
	.string "Dieser Ball hat sich bewegt, als ich ihn\n"
	.string "überprüfen wollte.\p"
	.string "Da geht etwas vor sich!$"
#else
	.string "{PLAYER}!\p"
	.string "This BALL started to shake\n"
	.string "while I was checking it.\p"
	.string "There must be something to this!$"
#endif

KurtsHouse_Text_Kurt_Whatwasthat:
#if GERMAN
	.string "Was ist das für ein Geräusch?!\p"
	.string "Lass uns draußen nachsehen!$"
#else
	.string "What was that sound?!\p"
	.string "Let's go outside to investigate!$"
#endif

KurtsHouse_Text_GranddaughterSlowpokeGone:
#if GERMAN
	.string "Die Flegmon sind verschwunden…\n"
	.string "Ob sie wohl von irgendwelchen bösen\l"
	.string "Leuten entführt wurden?$"
#else
	.string "The SLOWPOKE are gone… \n"
	.string "Were they taken away by bad people?$"
#endif

KurtsHouse_Text_GranddaughterLonely:
#if GERMAN
	.string "Wo steckt bloß mein Großvater?\n"
	.string "Ich fühle mich so alleine…$"
#else
	.string "Grandpa's gone… I'm so lonely…$"
#endif

KurtsHouse_Text_GranddaughterSlowpokeBack:
#if GERMAN
	.string "Das Flegmon, das ich von meinem Vater\n"
	.string "bekommen habe, ist wieder da!\l"
	.string "Seine Rute wächst schon wieder nach.$"
#else
	.string "The SLOWPOKE my dad gave me came back!\p"
	.string "Its TAIL is growing back too!$"
#endif

KurtsHouse_Text_GranddaughterDad:
#if GERMAN
	.string "Mein Vater arbeitet bei der Silph Co.\n"
	.string "Er ist dort an der Entwicklung neuer\l"
	.string "Pokébälle beteiligt!\p"
	.string "Ich hüte hier mit meinem Großvater\n"
	.string "und Flegmon das Haus.$"
#else
	.string "Dad works at SILPH where\n"
	.string "he studies POKé BALLS.\p"
	.string "I have to stay home\n"
	.string "with Grandpa and SLOWPOKE.$"
#endif

KurtsHouse_Text_GranddaughterHelp:
#if GERMAN
	.string "Ich muss jetzt Opa helfen!\p"
	.string "Wir machen dir einen hervorragenden\n"
	.string "Ball! Warte mal!$"
#else
	.string "I get to help Grandpa now!\p"
	.string "We'll make good BALLS\n"
	.string "for you, so please wait!$"
#endif

KurtsHouse_Text_GranddaughterFun:
#if GERMAN
	.string "Bälle anfertigen macht Spaß!$"
#else
	.string "It's fun to make BALLS!$"
#endif

KurtsHouse_Text_GranddaughterSound:
#if GERMAN
	.string "Kam dieses Geräusch aus dem\n"
	.string "Steineichenwald????$"
#else
	.string "Did that sound come from\n"
	.string "ILEX FOREST????$"
#endif

KurtsHouse_Text_Forest:
#if GERMAN
	.string "Warst du schon im Steineichenwald?\n"
	.string "Es hört sich gruselig an.$"
#else
	.string "Did you check ILEX FOREST yet?\n"
	.string "It sounds very restless.$"
#endif

KurtsHouse_Text_Slowpoke:
#if GERMAN
	.string "Flegmon: …Flegmon?$"
#else
	.string "SLOWPOKE: … Yawn?$"
#endif

KurtsHouse_Text_OakPhoto:
#if GERMAN
	.string "…Ein junger Prof. Eich?$"
#else
	.string "…A young PROF. OAK?$"
#endif

KurtsHouse_Text_CelebiStatue:
#if GERMAN
	.string "Eine Statue des Waldpatrons.$"
#else
	.string "It's a statue of the forest's\n"
	.string "protector.$"
#endif
