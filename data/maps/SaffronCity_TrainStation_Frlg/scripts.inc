SaffronCity_TrainStation_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronStationFrlg_OnFrame
	.byte 0

SaffronStationFrlg_OnFrame::
	map_script_2 VAR_TRAIN, 1, SaffronStationFrlg_EventScript_ExitTrain
	.2byte 0

SaffronStationFrlg_EventScript_Nerd::
	msgbox SaffronMagnetTrainStationFrlg_Text_GymGuide, MSGBOX_NPC
	end
SaffronStationFrlg_EventScript_Lass::
	msgbox SaffronMagnetTrainStationFrlg_Text_Lass, MSGBOX_NPC
	end
SaffronStationFrlg_EventScript_Teacher::
	msgbox SaffronMagnetTrainStationFrlg_Text_Teacher, MSGBOX_NPC
	end

@ The train only needs the pass (radio quiz prize), see docs/origin_jade/DECISIONS.md, D-029.
SaffronStationFrlg_EventScript_Attendant::
	lock
	faceplayer
	checkitem ITEM_PASS
	goto_if_eq VAR_RESULT, TRUE, SaffronStationFrlg_EventScript_BoardTrain
	msgbox SaffronMagnetTrainStationFrlg_Text_OfficerNoRailPass, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronStationFrlg_EventScript_BoardTrain::
	msgbox SaffronMagnetTrainStationFrlg_Text_OfficerRightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAFFRON_STATION_FRLG_ATTENDANT, SaffronStationFrlg_Movement_Attendant_Move_Up
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SaffronStationFrlg_Movement_WalktoTrain
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	playse SE_EXIT
	waitse
	fadescreen FADE_TO_BLACK

	applymovement OBJ_EVENT_ID_CAMERA, SaffronStationFrlg_Movement_CameraPanUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, SaffronStationFrlg_Movement_CameraPanRight
	waitmovement 0
	delay 60

	applymovement LOCALID_SAFFRON_STATION_FRLG_TRAIN SaffronStationFrlg_Movement_SlideLeft
	applymovement OBJ_EVENT_ID_CAMERA, SaffronStationFrlg_Movement_SlideLeft
	playbgm MUS_HG_MAGNET_TRAIN, FALSE
	fadescreen FADE_FROM_BLACK
	playse SE_TRUCK_MOVE
	delay 220
	playse SE_TRUCK_STOP
	applymovement LOCALID_SAFFRON_STATION_FRLG_TRAIN SaffronStationFrlg_Movement_SlideLeft
	applymovement OBJ_EVENT_ID_CAMERA, SaffronStationFrlg_Movement_SlideLeft
	fadescreen FADE_TO_BLACK
	waitse
	special RemoveCameraObject
	setvar VAR_TRAIN, 1
	delay 60
	warp MAP_GOLDENROD_CITY_TRAIN_STATION_HNS, 19, 16
	waitstate
	delay 60
	end

SaffronStationFrlg_EventScript_ExitTrain::
	lock
	applymovement LOCALID_SAFFRON_STATION_FRLG_ATTENDANT, SaffronStationFrlg_Movement_Attendant_Move_Up
	applymovement OBJ_EVENT_ID_PLAYER, SaffronStationFrlg_Movement_ExitTrain
	waitmovement 0
	waitmovement 0
	setvar VAR_TRAIN, 0
	applymovement LOCALID_SAFFRON_STATION_FRLG_ATTENDANT, SaffronStationFrlg_Movement_Attendant_Move_Down
	waitmovement 0
	release
	end

SaffronStationFrlg_Movement_ExitTrain:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

SaffronStationFrlg_Movement_Attendant_Move_Up:
	face_up
	walk_up
	walk_left
	face_right
	step_end

SaffronStationFrlg_Movement_Attendant_Move_Down:
	walk_right
	walk_down
	step_end

SaffronStationFrlg_Movement_WalktoTrain:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

SaffronStationFrlg_Movement_CameraPanUp:
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

SaffronStationFrlg_Movement_CameraPanRight:
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	slide_right
	step_end

SaffronStationFrlg_Movement_SlideLeft:
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	slide_left
	step_end

SaffronMagnetTrainStationFrlg_Text_OfficerRightThisWay:
#if GERMAN
	.string "Darf ich bitte deinen Fahrschein\n"
	.string "sehen?\p"
	.string "Danke sehr. Hier lang, bitte.$"
#else
    .string "May I see your rail PASS, please?\p"
    .string "OK. Right this way, please.$"
#endif

SaffronMagnetTrainStationFrlg_Text_OfficerNoRailPass:
#if GERMAN
	.string "Verzeihung, aber du hast keinen\n"
	.string "Fahrschein.$"
#else
    .string "Sorry. You don't have a rail PASS.$"
#endif

SaffronMagnetTrainStationFrlg_Text_GymGuide:
#if GERMAN
	.string "Der Magnetzug ist ein Wunderwerk!\n"
	.string "Er fährt mit Strom und Magnetkraft.\p"
	.string "In Windeseile bringt er dich bis\n"
	.string "nach Dukatia City in Johto!$"
#else
	.string "The MAGNET TRAIN is a super-modern\n"
	.string "rail liner that uses electricity\p"
	.string "and magnets to attain incredible\n"
	.string "speed.\p"
	.string "It gets you to GOLDENROD CITY in\n"
	.string "JOHTO in no time!$"
#endif

SaffronMagnetTrainStationFrlg_Text_Teacher:
#if GERMAN
	.string "Bevor der Bahnhof des Magnetzugs\n"
	.string "gebaut wurde, stand hier ein Haus.\p"
	.string "Darin lebte ein kleines Mädchen,\n"
	.string "das alle Leute Nachahmerin nannten.$"
#else
	.string "Before the MAGNET TRAIN STATION\n"
	.string "was built, there was a house there.\p"
	.string "A little girl named COPYCAT used\n"
	.string "to live there.$"
#endif

SaffronMagnetTrainStationFrlg_Text_Lass:
#if GERMAN
	.string "Hi! Hast du einen Fahrschein?\p"
	.string "Ich habe einen!\p"
	.string "Wer in Saffronia City mit dem\n"
	.string "Magnetzug fährt, hat einen!$"
#else
	.string "Hi. Do you have a rail PASS?\n"
	.string "I have one.\p"
	.string "All the people in SAFFRON who ride\n"
	.string "the MAGNET TRAIN have PASSES.$"
#endif
