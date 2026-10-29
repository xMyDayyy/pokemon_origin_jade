AzaleaTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_OnFrame
	.byte 0

AzaleaTown_OnTransition::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_MapScript_Hide_Silver
	end

AzaleaTown_OnFrame::
	map_script_2 VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_EventScript_GSBall
	.2byte 0

AzaleaTown_MapScript_Hide_Silver:
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	removeobject LOCALID_AZALEA_TOWN_SILVER
	end

AzaleaTown_EventScript_Trigger:: @flagheap
	setflag FLAG_VISITED_AZALEA_TOWN
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	setflag FLAG_HIDE_KURT_2
	setflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
	setflag FLAG_HIDE_ILEX_FOREST_MASTER
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	setflag FLAG_HIDE_CELEBI
	setflag FLAG_HIDE_ILEX_FOREST_KURT
	setflag FLAG_HIDE_AZALEA_TOWN_KURT
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT


	clearflag FLAG_HIDE_ILEX_FOREST_KIMONO
	clearflag FLAG_ITEM_SLOWPOKE_WELL_RAIN_DANCE
	clearflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	clearflag FLAG_HIDE_KURT_1
	clearflag FLAG_GOT_CHARCOAL
	clearflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
	clearflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
	clearflag FLAG_MOVE_TUTOR_TAUGHT_HEADBUTT

	removeitem ITEM_HM_SURF
	setvar VAR_AZALEA_TOWN_STATE, 1
	end

AzaleaTown_EventScript_Rocket1::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Rocket2::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Gramps::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_EventScript_Gramps2
	msgbox AzaleaTown_Text_GrampsBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Gramps2::
	msgbox AzaleaTown_Text_GrampsAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Lass::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Youngster::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Slowpoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	msgbox AzaleaTown_Text_Slowpoke1, MSGBOX_DEFAULT
	waitmoncry
	release
	end


AzaleaTown_EventScript_GymSign::
	lock
	msgbox AzaleaTown_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_KurtSign::
	lock
	msgbox AzaleaTown_Text_KurtsHouseSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_KilnSign::
	lock
	msgbox AzaleaTown_Text_CharcoalKilnSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_IlexSign::
	lock
	msgbox AzaleaTown_Text_IlexForestSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_WellSign::
	lock
	msgbox AzaleaTown_Text_SlowpokeWellSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_AzaleaSign::
	lock
	msgbox AzaleaTown_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_SilverTriggerTop::
	lock
	clearflag FLAG_HIDE_AZALEA_TOWN_SILVER
	addobject LOCALID_AZALEA_TOWN_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_EnterTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox AzaleaTown_Text_RivalBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_JOHTO_STARTER_MON, 0, AzaleaTown_Silver_Battle_Cyndaquil
	call_if_eq VAR_JOHTO_STARTER_MON, 1, AzaleaTown_Silver_Battle_Totodile
	call_if_eq VAR_JOHTO_STARTER_MON, 2, AzaleaTown_Silver_Battle_Chikorita
	msgbox AzaleaTown_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_Player_LeaveTop
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_LeaveTop
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	removeobject LOCALID_AZALEA_TOWN_SILVER
	setvar VAR_AZALEA_TOWN_STATE, 6
	fadedefaultbgm
	release
	end

AzaleaTown_EventScript_SilverTriggerBot::
	lock
	clearflag FLAG_HIDE_AZALEA_TOWN_SILVER
	addobject LOCALID_AZALEA_TOWN_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_EnterBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox AzaleaTown_Text_RivalBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_JOHTO_STARTER_MON, 0, AzaleaTown_Silver_Battle_Cyndaquil
	call_if_eq VAR_JOHTO_STARTER_MON, 1, AzaleaTown_Silver_Battle_Totodile
	call_if_eq VAR_JOHTO_STARTER_MON, 2, AzaleaTown_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox AzaleaTown_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_Player_LeaveBot
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_LeaveBot
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	removeobject LOCALID_AZALEA_TOWN_SILVER
	setvar VAR_AZALEA_TOWN_STATE, 6
	fadedefaultbgm
	release
	end

AzaleaTown_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_2_HNS, AzaleaTown_Text_RivalWin
	return

AzaleaTown_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_2_HNS, AzaleaTown_Text_RivalWin
	return

AzaleaTown_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_2_HNS, AzaleaTown_Text_RivalWin
	return


AzaleaTown_EventScript_GSBall::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_PlayerGSBall
	waitmovement 0
	clearflag FLAG_HIDE_AZALEA_TOWN_KURT
	addobject LOCALID_AZALEA_TOWN_KURT_GS
	opendoor 19, 11
	waitdooranim
	waitmovement 0
	closedoor 19, 11
	waitdooranim
	applymovement LOCALID_AZALEA_TOWN_KURT_GS, AzaleaTown_Movement_Kurt2
	playse SE_M_PETAL_DANCE
	waitmovement 0
	msgbox AzaleaTown_Text_Kurt1, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	msgbox AzaleaTown_Text_Kurt2, MSGBOX_DEFAULT
	giveitem ITEM_GS_BALL
	waitse
	playse SE_M_PETAL_DANCE
	turnobject LOCALID_AZALEA_TOWN_KURT_GS, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_M_PETAL_DANCE
	waitse
	turnobject LOCALID_AZALEA_TOWN_KURT_GS, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox AzaleaTown_Text_Kurt3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AZALEA_TOWN_KURT_GS, AzaleaTown_Movement_KurtLeave
	delay 60
	opendoor 19, 11
	waitdooranim
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_TOWN_KURT
	removeobject LOCALID_AZALEA_TOWN_KURT_GS
	closedoor 19, 11
	waitdooranim
	setvar VAR_AZALEA_TOWN_STATE, 9
	release
	end

AzaleaTown_Movement_Silver_EnterTop:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

AzaleaTown_Movement_Silver_EnterBot:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

AzaleaTown_Movement_Silver_LeaveTop:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

AzaleaTown_Movement_Silver_LeaveBot:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	step_end

AzaleaTown_Movement_Player_LeaveTop:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

AzaleaTown_Movement_Player_LeaveBot:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

AzaleaTown_Movement_Kurt1:
	walk_down
	step_end

AzaleaTown_Movement_Kurt2:
	walk_down
	walk_down
	walk_down
	face_right
	delay_8
	face_left
	delay_8
	face_down
	step_end

AzaleaTown_Movement_PlayerGSBall:
	walk_down
	walk_down
	walk_down
	face_left
	delay_16
	face_right
	delay_8
	face_up
	step_end

AzaleaTown_Movement_KurtLeave:
	walk_up
	walk_up
	walk_up
	step_end

AzaleaTown_Text_RivalBefore:
#if GERMAN
	.string "{PLAYER}: Sag mal…\p"
	.string "Stimmt es eigentlich, dass Team\n"
	.string "Rocket jetzt wieder da ist?\p"
	.string "Was? Du hast diese Bande eigenhändig\n"
	.string "aufgehalten, sagst du?\p"
	.string "Erzähl mir keine Märchen! Wenn das\n"
	.string "wirklich stimmt, dann kannst du mir ja\l"
	.string "bestimmt auch eine Kostprobe deiner\l"
	.string "Fähigkeiten geben!$"
#else
	.string "…Tell me something.\p"
	.string "Is it true that TEAM ROCKET\n"
	.string "has returned?\p"
	.string "What? You beat them? Hah! Quit\n"
	.string "lying.\p"
	.string "You're not joking?\n"
	.string "Then let's see how good you are.$"
#endif

AzaleaTown_Text_RivalWin:
#if GERMAN
	.string "Hmpf! Diese Pokémon sind zu nichts zu\n"
	.string "gebrauchen.\p"
	.string "Glaube mir, du konntest nur gewinnen,\n"
	.string "weil meine Pokémon so schwach waren!$"
#else
	.string "…Humph! Useless POKéMON!\p"
	.string "Listen, you. You only won because\n"
	.string "my POKéMON were weak.$"
#endif

AzaleaTown_Text_RivalAfter:
#if GERMAN
	.string "Ich hasse die Schwachen.\p"
	.string "Pokémon, Trainer, egal wer oder was.\p"
	.string "Ich werde stark sein und die Schwachen\n"
	.string "auslöschen.\p"
	.string "Team Rocket gilt das ebenso.\p"
	.string "In Gruppen tun sie groß und hart.\p"
	.string "Doch allein sind sie schwach.\n"
	.string "Ich hasse sie alle.\p"
	.string "Bleib mir aus dem Weg. Ein Schwächling\n"
	.string "wie du ist nur Ablenkung.$"
#else
	.string "I hate the weak.\p"
	.string "POKéMON, trainers. It doesn't\n"
	.string "matter who or what.\p"
	.string "I'm going to be strong and wipe\n"
	.string "out the weak.\p"
	.string "That goes for TEAM ROCKET too.\p"
	.string "They act big and tough in a group.\p"
	.string "But get them alone, and they're weak.\n"
	.string "I hate them all.\p"
	.string "You stay out of my way. A weakling\n"
	.string "like you is only a distraction.$"
#endif

AzaleaTown_Text_RivalLoss:
#if GERMAN
	.string "Ha! Ich wusste doch, dass du vorhin nur\n"
	.string "geflunkert hast!$"
#else
	.string "…Humph! I knew you were lying.$"
#endif

AzaleaTown_Text_Rocket1:
#if GERMAN
	.string "Hier reinzugehen ist unsicher,\n"
	.string "also stehe ich Wache.\p"
	.string "Bin ich nicht ein guter Samariter?$"
#else
	.string "It's unsafe to go in there,\n"
	.string "so I'm standing guard.\p"
	.string "Aren't I a good Samaritan?$"
#endif

AzaleaTown_Text_Rocket2:
#if GERMAN
	.string "Hast du schon mal eine Flegmon-Rute\n"
	.string "gegessen? Die sollen echt lecker sein!\p"
	.string "Wenn das mal kein heißer Tipp ist!\n"
	.string "Ach ja, bin ich nicht zu gutmütig?$"
#else
	.string "Do you know about SLOWPOKETAIL?\n"
	.string "I heard it's tasty!\p"
	.string "Aren't you glad I told you that?$"
#endif

AzaleaTown_Text_GrampsBefore:
#if GERMAN
	.string "Alle Flegmon sind aus der Stadt\n"
	.string "verschwunden…\p"
	.string "Dabei dachte ich, dass man hier\n"
	.string "Flegmon-Ruten kaufen kann…$"
#else
	.string "The SLOWPOKE have disappeared\n"
	.string "from town…\p"
	.string "I heard their TAILS are being\n"
	.string "sold somewhere.$"
#endif

AzaleaTown_Text_GrampsAfter:
#if GERMAN
	.string "Die Flegmon sind wieder da!\n"
	.string "Vermutlich haben sie wieder irgendwo\l"
	.string "gefaulenzt.$"
#else
	.string "The SLOWPOKE have returned.\p"
	.string "Knowing them, they could've just\n"
	.string "been goofing off somewhere.$"
#endif

AzaleaTown_Text_Teacher:
#if GERMAN
	.string "Bist du auch hier, um Kurt zu bitten,\n"
	.string "Pokébälle für dich anzufertigen?\l"
	.string "Eine Menge Leute wollen das!$"
#else
	.string "Did you come to get KURT to make\n"
	.string "some BALLS?\p"
	.string "A lot of people do just that.$"
#endif

AzaleaTown_Text_Youngster:
#if GERMAN
	.string "Hinter Azalea City gelangst du in\n"
	.string "den sogenannten Steineichenwald.\p"
	.string "Allerdings machen es diese dürren Bäume\n"
	.string "unmöglich, dort durchzukommen.\p"
	.string "Nur die Pokémon des Köhlers könnten\n"
	.string "sie vielleicht aus dem Weg räumen!$"
#else
	.string "Cut through AZALEA and you'll be\n"
	.string "in ILEX FOREST.\p"
	.string "But these skinny trees make it\n"
	.string "impossible to get through.\p"
	.string "The CHARCOAL MAN's POKéMON\n"
	.string "can CUT down trees.$"
#endif

AzaleaTown_Text_Slowpoke1:
#if GERMAN
	.string "Flegmon: …Flegmon?$"
#else
	.string "SLOWPOKE:..........\p"
	.string "...............YAWN?$"
#endif

AzaleaTown_Text_Kurt1:
#if GERMAN
	.string "Der Steineichenwald ist gruselig!\p"
	.string "Was passiert da?$"
#else
	.string "ILEX FOREST is restless!\p"
	.string "What is going on?$"
#endif

AzaleaTown_Text_Kurt2:
#if GERMAN
	.string "{PLAYER}, hier ist dein GS-Ball!$"
#else
	.string "{PLAYER}, here's your GS BALL back!$"
#endif

AzaleaTown_Text_Kurt3:
#if GERMAN
	.string "Könntest du den Steineichenwald\n"
	.string "erkunden und herausfinden, was dort\l"
	.string "vor sich geht?$"
#else
	.string "Could you go see why ILEX FOREST\n"
	.string "is so restless?$"
#endif

AzaleaTown_Text_Sign:
#if GERMAN
	.string "Azalea City Wo Menschen und Pokémon in\n"
	.string "Harmonie leben.$"
#else
	.string "AZALEA TOWN\n"
	.string "Where People and POKéMON Live in\l"
	.string "Happy Harmony.$"
#endif

AzaleaTown_Text_KurtsHouseSign:
#if GERMAN
	.string "Kurts Haus$"
#else
	.string "KURT'S HOUSE$"
#endif

AzaleaTown_Text_GymSign:
#if GERMAN
	.string "Pokémon-Arena von Azalea City Leiter:\n"
	.string "Kai Die wandelnde Enzyklopädie für\l"
	.string "Käfer-Pokémon$"
#else
	.string "AZALEA TOWN\n"
	.string "POKéMON GYM\p"
	.string "LEADER: BUGSY\p"
	.string "The Walking Bug POKéMON\n"
	.string "Encyclopedia$"
#endif

AzaleaTown_Text_SlowpokeWellSign:
#if GERMAN
	.string "Der Flegmon-Brunnen\n"
	.string "Auch bekannt als Regenmacherquelle.\p"
	.string "Die Leute in dieser Gegend glauben,\n"
	.string "dass, wann immer ein Flegmon gähnt, bald\l"
	.string "Regen fallen wird.\p"
	.string "Alte Aufzeichnungen besagen, dass vor\n"
	.string "400 Jahren einmal ein Flegmon eine\l"
	.string "Dürre beendet haben soll, indem es\l"
	.string "gegähnt hat.$"
#else
	.string "SLOWPOKE WELL\p"
	.string "Also known as the RAINMAKER WELL.\p"
	.string "Locals believe that a SLOWPOKE's\n"
	.string "yawn summons rain.\p"
	.string "Records show that a SLOWPOKE's\n"
	.string "yawn ended a drought 400 years ago.$"
#endif

AzaleaTown_Text_CharcoalKilnSign:
#if GERMAN
	.string "Kohleofen$"
#else
	.string "CHARCOAL KILN$"
#endif

AzaleaTown_Text_IlexForestSign:
#if GERMAN
	.string "Direkt hinter dem Tor liegt\n"
	.string "der Steineichenwald.$"
#else
	.string "ILEX FOREST\p"
	.string "Enter through the gate.$"
#endif
