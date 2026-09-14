Route29_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
#if GERMAN
	.string "Drücke A oder B um nicht mehr zu\n"
	.string "schauen.$"
#else
	.string "Press A or B to stop viewing.$"
#endif

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
#if GERMAN
	.string "Pokémon verstecken sich im Gras.\n"
	.string "Wer weiß, wann sie auftauchen…$"
#else
	.string "POKéMON hide in the grass.\n"
	.string "Who knows when they'll pop out…$"
#endif

Route29_Text_OldMan2:
#if GERMAN
	.string "Dich habe ich hier noch nie gesehen.\p"
	.string "Du kommst von drüben, stimmt's?\p"
	.string "Soll ich dir zeigen, wo hier was\n"
	.string "lebt?$"
#else
	.string "I have never seen you here before.\p"
	.string "You came from over there, did you\n"
	.string "not?\p"
	.string "Shall I tell you what lives around\n"
	.string "here?$"
#endif

Route29_Text_OldManExplanation:
#if GERMAN
	.string "Im hohen Gras sind vor allem\n"
	.string "Rattfratz und Tannza unterwegs.\p"
	.string "Nachts kommen Hoothoot dazu.\p"
	.string "Klingt bescheiden, ich weiß.\n"
	.string "Aber jeder fängt irgendwo an.$"
#else
	.string "The tall grass here is mostly\n"
	.string "RATTATA and SENTRET.\p"
	.string "At night the HOOTHOOT come out.\p"
	.string "Modest, I know. But everyone starts\n"
	.string "somewhere.$"
#endif

Route29_Text_OldManDeclined:
#if GERMAN
	.string "Oh… Na gut.\p"
	.string "Dann viel Glück auf dem Weg.$"
#else
	.string "Oh… Very well.\p"
	.string "Good luck on the road, then.$"
#endif

Route29_Text_Youngster:
#if GERMAN
	.string "Tag! Bist du auf der Durchreise?\p"
	.string "Hier kommt selten jemand vorbei, der\n"
	.string "nicht aus Neuborkia ist.$"
#else
	.string "Hello! Just passing through?\p"
	.string "We rarely get anyone here who is not\n"
	.string "from NEW BARK TOWN.$"
#endif

Route29_Text_Lass:
#if GERMAN
	.string "Siehst du die Stufen hier?\p"
	.string "Springen geht nur abwärts. Wer\n"
	.string "zurück will, muss außen herum.$"
#else
	.string "See these ledges?\p"
	.string "You can only jump down. Going back\n"
	.string "means walking around.$"
#endif

Route29_Text_Girl:
#if GERMAN
	.string "Ich will eine kurze Pause einlegen und\n"
	.string "speichere deshalb gerade meinen\l"
	.string "Spielstand.$"
#else
	.string "I wanted to take a break,\n"
	.string "so I saved to record my progress.$"
#endif

Route29_Text_Boy_WaitingForDay:
#if GERMAN
	.string "Ich warte hier darauf, dass es Mittag\n"
	.string "wird, weil sich manche Pokémon nur zu\l"
	.string "dieser Zeit blicken lassen.$"
#else
	.string "I'm waiting for POKéMON that\n"
	.string "appear only later in the day.$"
#endif

Route29_Text_Boy_WaitingForNight:
#if GERMAN
	.string "Ich warte hier darauf, dass es Nacht\n"
	.string "wird, weil sich manche Pokémon nur zu\l"
	.string "dieser Zeit blicken lassen.$"
#else
	.string "I'm waiting for POKéMON that\n"
	.string "appear only at night.$"
#endif

Route29_Text_MeetTuscany:
#if GERMAN
	.string "Dietlinde: Ich glaube, wir treffen\n"
	.string "uns heute zum ersten Mal?\p"
	.string "Ich bin Dietlinde aus der\n"
	.string "Wochentagsfamilie.\p"
	.string "Wenn du meinen Lieblingstag errätst,\n"
	.string "gebe ich dir eine Belohnung.$"
#else
	.string "TUSCANY: I do believe that this\n"
	.string "is the first time we've met?\p"
	.string "I'm TUSCANY of the WEEKDAY FAMILY.\p"
	.string "If you can guess my favorite day,\n"
	.string "I'll give you a reward.$"
#endif

Route29_Text_TuscanyNope:
#if GERMAN
	.string "Nicht ganz!$"
#else
	.string "Not quite!$"
#endif

Route29_Text_TuscanyGivesGift:
#if GERMAN
	.string "Ja! Da wir uns zum ersten Mal sehen,\p"
	.string "schenke ich dir einen Seidenschal.$"
#else
	.string "Yes! By way of introduction,\n"
	.string "please accept this gift, a SILK\l"
	.string "SCARF.$"
#endif

Route29_Text_TuscanyGaveGift:
#if GERMAN
	.string "Dietlinde: Findest du nicht auch,\n"
	.string "dass er ganz entzückend ist?\p"
	.string "Er verstärkt Attacken der\n"
	.string "Elementklasse Normal.\p"
	.string "Ich bin sicher, er wird dir sehr nützlich\n"
	.string "sein.$"
#else
	.string "TUSCANY: Wouldn't you agree\n"
	.string "that it is most adorable?\p"
	.string "It strengthens NORMAL-type\n"
	.string "moves.\p"
	.string "I am certain it will be of use.$"
#endif

Route29_Text_TuscanyTuesday:
#if GERMAN
	.string "Dietlinde: Bist du Monja, meiner\n"
	.string "älteren Schwester, schon begegnet?\p"
	.string "Oder meinem kleinen Bruder Mitko?\p"
	.string "Ich bin das zweite von sieben Kindern.$"
#else
	.string "TUSCANY: Have you met MONICA,\n"
	.string "my older sister?\p"
	.string "Or my younger brother, WESLEY?\p"
	.string "I am the third of seven\n"
	.string "children.$"
#endif

Route29_Text_Sign1:
#if GERMAN
	.string "Route 29\p"
	.string "Rosalia City - Neuborkia$"
#else
	.string "ROUTE 29\p"
	.string "CHERRYGROVE CITY - NEW BARK TOWN$"
#endif

