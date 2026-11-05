RocketHideout_B3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RocketHideout_B3F_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B3F_OnLoad
	.byte 0

RocketHideout_B3F_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout_B3F_HideGate
	call_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout_B3F_HidePetrel
	end

RocketHideout_B3F_HideGate::
	setmetatile 11, 11, 0x378, FALSE
	setmetatile 11, 12, 0x380, FALSE
	setmetatile 12, 11, 0x379, FALSE
	setmetatile 12, 12, 0x379, FALSE
	setmetatile 13, 11, 0x379, FALSE
	setmetatile 13, 12, 0x379, FALSE
	return
RocketHideout_B3F_HidePetrel::
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	return

RocketHideout_B3F_OnFrame::
	map_script_2 VAR_MAHOGANY_TOWN_STATE, 6, RocketHideout_B3F_EventScript_LancePassword
	.2byte 0

RocketHideout_B3F_EventScript_LancePassword::
	lock
	delay 55
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROCKETHIDEOUT3_LANCE
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_WalkRight1
	msgbox RocketHideout_B3F_Text_LanceGetPassword, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, RocketHideout_B3F_Movement_LanceLeave
	applymovement LOCALID_ROCKETHIDEOUT3_DRAGONITE, RocketHideout_B3F_Movement_DragoniteLeave
	waitmovement LOCALID_ROCKETHIDEOUT3_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT3_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 7
	release
	end

RocketHideout_B3F_Movement_LanceLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	delay_2
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B3F_Movement_DragoniteLeave:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	delay_8
	delay_8
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B3F_Text_LanceGetPassword:
#if GERMAN
	.string "Siegfried: Man braucht zwei Passwörter,\n"
	.string "um zum Boss zu gelangen.\p"
	.string "Diese Passwörter kennen nur wenige\n"
	.string "Rocket-Rüpel.\p"
	.string "Dieser Rocket-Rüpel hat es mir\n"
	.string "freundlicherweise verraten.\p"
	.string "{PLAYER}, lass uns die Passwörter\n"
	.string "besorgen.$"
#else
    .string "LANCE: It takes two passwords\n"
    .string "to get into the boss' quarters.\p"
    .string "Those passwords are known only\n"
    .string "to a few ROCKETS.\p"
    .string "That ROCKET there very graciously\n"
    .string "told me so.\p"
    .string "{PLAYER}, let's go get the\n"
    .string "passwords.$"
#endif

RocketHideout_B3F_EventScript_RocketKO::
	lock
	faceplayer
	msgbox RocketHideout_B3F_Text_B3FRocket, MSGBOX_DEFAULT
	release
	end

RocketHideout_B3F_Text_B3FRocket:
#if GERMAN
	.string "Urrggh… Der Typ im Umhang ist\n"
	.string "unglaublich stark…$"
#else
    .string "Urrggh… The guy in the cape is\n"
    .string "incredibly tough…$"
#endif


RocketHideout_B3F_Trigger_MurkrowStairs::
	lock
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, RocketHideout_B3F_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, RocketHideout_B3F_Movement_MurkrowStairs2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setvar VAR_MAHOGANY_TOWN_STATE, 11
	release
	end

RocketHideout_B3F_Movement_MurkrowStairs1:
	jump_in_place_right
	jump_in_place_right
	step_end

RocketHideout_B3F_Movement_MurkrowStairs2:
	jump_in_place_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B3F_Trigger_Silver::
	lock
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	addobject LOCALID_ROCKETHIDEOUT3_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout_B3F_Movement_SilverEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RocketHideout_B3F_Text_Rival, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout_B3F_Movement_SilverLeave
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	removeobject LOCALID_ROCKETHIDEOUT3_SILVER
	setvar VAR_MAHOGANY_TOWN_STATE, 8
	fadedefaultbgm
	release
	end

RocketHideout_B3F_Movement_SilverEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B3F_Movement_SilverLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RocketHideout_B3F_EventScript_Door::
	lock
	goto_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout_B3F_EventScript_DoorIsOpen
	goto_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout_B3F_EventScript_OpenDoor
	msgbox RocketHideout_B3F_Text_B3FLockedDoorNeedsPassword, MSGBOX_DEFAULT
	closemessage
	release
	end

RocketHideout_B3F_EventScript_OpenDoor::
	msgbox RocketHideout_B3F_Text_B3FLockedDoorOpenSesame, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 11, 11, 0x378, FALSE
	setmetatile 11, 12, 0x380, FALSE
	setmetatile 12, 11, 0x379, FALSE
	setmetatile 12, 12, 0x379, FALSE
	setmetatile 13, 11, 0x379, FALSE
	setmetatile 13, 12, 0x379, FALSE
	special DrawWholeMapView
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GATE
	release
	end

RocketHideout_B3F_EventScript_DoorIsOpen::
	release
	end

RocketHideout_B3F_EventScript_GruntF5::
	trainerbattle_single TRAINER_GRUNT_29_HNS, RocketHideout_B3F_Text_GruntF5Seen, RocketHideout_B3F_Text_GruntF5Beaten
	msgbox RocketHideout_B3F_Text_GruntF5After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_GRUNTF, RocketHideout_B3F_EventScript_IncrementPasswordGruntF
	end

RocketHideout_B3F_EventScript_IncrementPasswordGruntF::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_GRUNTF
	end

RocketHideout_B3F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_2_HNS, RocketHideout_B3F_Text_GruntM28Seen, RocketHideout_B3F_Text_GruntM28Beaten
	msgbox RocketHideout_B3F_Text_GruntM28After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_ETO, RocketHideout_B3F_EventScript_IncrementPasswordEto
	end

RocketHideout_B3F_EventScript_IncrementPasswordEto::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_ETO
	end

RocketHideout_B3F_EventScript_Ross::
	trainerbattle_single TRAINER_ROSS_HNS, RocketHideout_B3F_Text_ScientistRossSeen, RocketHideout_B3F_Text_ScientistRossBeaten
	msgbox RocketHideout_B3F_Text_ScientistRossAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Mitch::
	trainerbattle_single TRAINER_MITCH_HNS, RocketHideout_B3F_Text_ScientistMitchSeen, RocketHideout_B3F_Text_ScientistMitchBeaten
	msgbox RocketHideout_B3F_Text_ScientistMitchAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Item_IceHeal::
	finditem ITEM_ICE_HEAL
	end

RocketHideout_B3F_EventScript_Item_Protein::
	finditem ITEM_PROTEIN
	end

RocketHideout_B3F_EventScript_Item_FullHeal::
	finditem ITEM_FULL_HEAL
	end

RocketHideout_B3F_EventScript_Item_GuardSpec::
	finditem ITEM_GUARD_SPEC
	end

RocketHideout_B3F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

RocketHideout_B3F_Text_B3FLockedDoorNeedsPassword:
#if GERMAN
	.string "Die Tür ist verschlossen…\p"
	.string "Zum Öffnen werden zwei Passwörter\n"
	.string "benötigt.$"
#else
    .string "The door's closed…\p"
    .string "It needs two passwords to open.$"
#endif

RocketHideout_B3F_Text_B3FLockedDoorOpenSesame:
#if GERMAN
	.string "Die Tür ist verschlossen…\p"
	.string "{PLAYER} gab die beiden Passwörter ein.\p"
	.string "Die Tür öffnete sich!$"
#else
    .string "The door's closed…\p"
    .string "{PLAYER} entered the two passwords.\p"
    .string "The door opened!$"
#endif

RocketHideout_B3F_Text_Rival:
#if GERMAN
	.string "…\p"
	.string "Hab ich dir nicht gesagt, dass\n"
	.string "ich Team Rocket zerstören werde?\p"
	.string "…Sag mir, wer war der Typ im Umhang, der\n"
	.string "Drachen-Pokémon einsetzt?\p"
	.string "Meine Pokémon hatten keine Chance.\p"
	.string "Was mich ärgert, ist, was er gesagt hat…\p"
	.string "Er meinte, ich liebe und vertraue\n"
	.string "meinen Pokémon nicht genug.\p"
	.string "Es ist nicht meine Schuld, dass\n"
	.string "mein Team so schwach ist.\p"
	.string "Ich bin wütend, dass ich gegen so einen\n"
	.string "gefühlsduseligen Typen verloren habe.\p"
	.string "Doch es lässt mich verzweifeln.\p"
	.string "Mache ich etwas falsch?\p"
	.string "Kann es Liebe sein, die sein Team\n"
	.string "so stark macht?$"
#else
    .string "…\p"
    .string "Didn't I tell you that I was\n"
    .string "going to destroy TEAM ROCKET?\p"
    .string "…Tell me, who was the guy in the\n"
    .string "cape who used dragon POKéMON?\p"
    .string "My POKéMON were no match at all.\p"
    .string "It's what he said that bothers\n"
    .string "me…\p"
    .string "He told me that I don't love and\n"
    .string "trust my POKéMON enough.\p"
    .string "It's not my fault my team is so\n"
    .string "useless.\p"
    .string "I'm furious that I lost to a\n"
    .string "bleeding heart like him.\p"
    .string "But it makes me question myself.\p"
    .string "Is there something I'm doing\n"
    .string "wrong?\p"
    .string "Could it be that love made his\n"
    .string "team so powerful?$"
#endif

@=======[PETREL]==============================================================================================================================

RocketHideout_B3F_EventScript_Giovanni::
	lock
	faceplayer
	msgbox RocketHideout_B3F_Text_PetrelIntro, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_GIOVANNI, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROCKETHIDEOUT3_GIOVANNI
	msgbox RocketHideout_B3F_Text_PetrelDisbelief, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_GIOVANNI, RocketHideout_B3F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	removeobject LOCALID_ROCKETHIDEOUT3_GIOVANNI
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	addobject LOCALID_ROCKETHIDEOUT3_PETREL
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_Spin2
	waitmovement 0
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_FacingEast
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_FacingWest
	msgbox RocketHideout_B3F_Text_PetrelReveal, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_1_HNS, RocketHideout_B3F_Text_PetrelBeaten
	msgbox RocketHideout_B3F_Text_PetrelAfterBattle, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_LeaveEast
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_LeaveWest
	call_if_eq VAR_FACING, DIR_NORTH, RocketHideout_B3F_EventScript_LeaveEast
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	playse SE_EXIT
	removeobject LOCALID_ROCKETHIDEOUT3_PETREL

	applymovement LOCALID_ROCKETHIDEOUT3_MURKROW, RocketHideout_B3F_Movement_Murkrow1

	delay 120

	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_FacingEastMurkrow
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_FacingWestMurkrow

	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement LOCALID_ROCKETHIDEOUT3_MURKROW
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	msgbox RocketHideout_B3F_Text_MurkrowMimic, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROW, RocketHideout_B3F_Movement_Murkrow2
	waitmovement LOCALID_ROCKETHIDEOUT3_MURKROW

	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROW
	playse SE_EXIT
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROW
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	setvar VAR_ROCKET_PASSWORD, 3
	setvar VAR_MAHOGANY_TOWN_STATE, 9
	release
	end

RocketHideout_B3F_EventScript_FacingEastMurkrow::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement OBJ_EVENT_ID_PLAYER
	return

RocketHideout_B3F_EventScript_FacingWestMurkrow::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement OBJ_EVENT_ID_PLAYER
	return

RocketHideout_B3F_EventScript_FacingEast::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_WEST
	return

RocketHideout_B3F_EventScript_FacingWest::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_EAST
	return

RocketHideout_B3F_EventScript_FacingNorth::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_SOUTH
	return

RocketHideout_B3F_EventScript_LeaveEast::
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_LeaveEast
	waitmovement 0
	return

RocketHideout_B3F_EventScript_LeaveWest::
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_LeaveWest
	waitmovement 0
	return

RocketHideout_B3F_Movement_Murkrow1:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	jump_in_place_right
	jump_in_place_left
	jump_in_place_down
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

RocketHideout_B3F_Movement_Murkrow2:
	jump_in_place_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	step_end

RocketHideout_B3F_Movement_LeaveEast:
	lock_facing_direction
	walk_slow_right
	unlock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_right
	walk_fast_right
	step_end
RocketHideout_B3F_Movement_LeaveWest:
	lock_facing_direction
	walk_slow_left
	walk_slow_left
	unlock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B3F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end

RocketHideout_B3F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end

RocketHideout_B3F_Text_PetrelIntro:
#if GERMAN
	.string "Muhahaha, wir haben auf dich gewartet.\n"
	.string "Du bist also {PLAYER}…\p"
	.string "Ich? Du weißt nicht, wer ich bin?\n"
	.string "Ich bin Giovanni.\p"
	.string "Der majestätische Giovanni selbst!\n"
	.string "Wahahaha!$"
#else
    .string "Muhahaha, we've been waiting\n"
    .string "for you. So, you are {PLAYER}...\p"
    .string "Me? You don't know who I am?\n"
    .string "It is me, GIOVANNI.\p"
    .string "The majestic GIOVANNI himself!\n"
    .string "Wahahaha!$"
#endif

RocketHideout_B3F_Text_PetrelDisbelief:
#if GERMAN
	.string "… …Wie jetzt?\p"
	.string "Ich sehe nicht aus wie Giovanni? Wir\n"
	.string "sehen uns gar nicht ähnlich?\p"
	.string "Verflixt!!! Dabei habe ich mir doch\n"
	.string "solche Mühe gegeben und geübt!$"
#else
    .string "...Huh?\n"
    .string "I don't sound anything like\l"
    .string "GIOVANNI?\p"
    .string "I don't even look like GIOVANNI?\n"
    .string "How come? I've worked so hard\l"
    .string "to mimic him!$"
#endif

RocketHideout_B3F_Text_PetrelReveal:
#if GERMAN
	.string "Lambda: Ich bin Team Rocket-\n"
	.string "Vorstandsmitglied Lambda!\p"
	.string "Du dachtest wohl, du könntest dich in\n"
	.string "den Transmitterraum einschleichen?\p"
	.string "Aber da hast du dich verzettelt!\p"
	.string "Das Zimmer wird nämlich durch ein\n"
	.string "besonderes Passwort geschützt!\p"
	.string "Und dieses Passwort lautet: “Lang lebe\n"
	.string "Giovanni”!\p"
	.string "Hehehe. Jetzt bist du bestimmt baff,\n"
	.string "dass ich es so einfach verraten habe?\p"
	.string "Aber das macht überhaupt nichts! Denn\n"
	.string "du kannst damit nichts anfangen!\p"
	.string "Bevor du das Passwort nämlich nicht mit\n"
	.string "Meiner Stimme aufsagst, rührt die Tür\l"
	.string "sich keinen Zentimeter!$"
#else
    .string "PETREL: I am a Team Rocket\n"
    .string "Executive!\p"
    .string "You must be trying to sneak into\n"
    .string "the radio-transmitter room.\p"
    .string "Well, that's not going to happen.\n"
    .string "That room is protected with a\l"
    .string "special password.\p"
    .string "The password is “Hail GIOVANNI.”\n"
    .string "Surprised to hear it from me?\p"
    .string "Knowing the password won't help\n"
    .string "you though.\p"
    .string "The door won't open unless I say\n"
    .string "the password. It only reacts to\l"
    .string "my voice.$"
#endif

RocketHideout_B3F_Text_PetrelBeaten:
#if GERMAN
	.string "Ich… ich war völlig chancenlos…\p"
	.string "Vergib mir, großer Giovanni…$"
#else
    .string "I… I couldn't do a thing…\p"
    .string "GIOVANNI, please forgive me…$"
#endif

RocketHideout_B3F_Text_PetrelAfterBattle:
#if GERMAN
	.string "Lambda: Vor drei Jahren löste unser\n"
	.string "Anführer, der große Giovanni, Team\l"
	.string "Rocket auf und verschwand…\p"
	.string "Doch ich bin sicher, er harrt irgendwo\n"
	.string "nur auf seine Chance für ein Comeback!\p"
	.string "Muuu Ha Ha Harr!\p"
	.string "Die Niederlage gegen dich jedenfalls\n"
	.string "juckt mich überhaupt nicht!\p"
	.string "Denn ohne meine Stimme… kannst du die\n"
	.string "Tür zum Transmitterraum zu öffnen\l"
	.string "versuchen, bis du schwarz wirst!$"
#else
    .string "PETREL: Since disbanding Team\n"
    .string "Rocket three years ago, our\l"
    .string "GIOVANNI has been missing.\p"
    .string "But we're certain he's been\n"
    .string "waiting for the right time for\l"
    .string "our revival... Wahahaha!\p"
    .string "Losing to you won't change the\n"
    .string "fact that you are unable to get\l"
    .string "in the radio-transmitter room!\p"
    .string "You need my voice to unlock it!$"
#endif

RocketHideout_B3F_EventScript_Murkrow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RocketHideout_B3F_Text_MurkrowSpeak1:
#if GERMAN
	.string "Kramurx: Lang lebe Giovanni!$"
#else
    .string "MURKROW: Hail GIOVANNI.$"
#endif

RocketHideout_B3F_Text_MurkrowMimic:
#if GERMAN
	.string "Das Kramurx hat Lambdas Stimme perfekt\n"
	.string "imitiert!\p"
	.string "Könnte das etwa…$"
#else
    .string "MURKROW is mimicking\n"
    .string "the voice of PETREL!\p"
    .string "You may be able to...!?$"
#endif

RocketHideout_B3F_Text_Murkrow:
#if GERMAN
	.string "Kramurx: Lang lebe Giovanni!$"
#else
    .string "MURKROW: The password is…\p"
    .string "HAIL GIOVANNI.$"
#endif

RocketHideout_B3F_Text_GruntF5Seen:
#if GERMAN
	.string "Ob ich das Passwort weiß? Vielleicht.\p"
	.string "Aber einem Schwächling werde ich es nie\n"
	.string "verraten!$"
#else
    .string "Do I know the password?\p"
    .string "Maybe.\p"
    .string "But no weakling's going to get\n"
    .string "it!$"
#endif

RocketHideout_B3F_Text_GruntF5Beaten:
#if GERMAN
	.string "Alles klar. Halt. Ich sag’s dir.$"
#else
    .string "All right. Stop. I'll tell you.$"
#endif

RocketHideout_B3F_Text_GruntF5After:
#if GERMAN
	.string "Das Passwort für den Bossraum\n"
	.string "ist Flegmonrute.\p"
	.string "Doch ohne zwei Passwörter nützt es\n"
	.string "nichts.$"
#else
    .string "The password to the boss' room\n"
    .string "is SLOWPOKETAIL.\p"
    .string "But it's useless unless you have\n"
    .string "two passwords.$"
#endif

RocketHideout_B3F_Text_GruntM28Seen:
#if GERMAN
	.string "Hyuck-hyuck-hyuck!\p"
	.string "Ich kenne dich vom Brunnen!\p"
	.string "Willst du mich wieder herausfordern?\p"
	.string "Hah! Du bist verrückt, doch mutig!\p"
	.string "Pass auf, ich bin stärker geworden!\p"
	.string "Wenn du mich besiegst, sage ich dir\n"
	.string "ein Passwort für den Bossraum.$"
#else
    .string "Hyuck-hyuck-hyuck!\p"
    .string "I remember you from the well!\p"
    .string "You're challenging me again?\p"
    .string "Hah! You're nuts, but you have\n"
    .string "guts!\p"
    .string "I'll warn you, I got better!\p"
    .string "If you can beat me, I'll tell\l"
    .string "you a password to the boss'\n"
    .string "room!$"
#endif

RocketHideout_B3F_Text_GruntM28Beaten:
#if GERMAN
	.string "Hyuck-hyuck-hyuck! Du bist gut!$"
#else
    .string "Hyuck-hyuck-hyuck! You're good!$"
#endif

RocketHideout_B3F_Text_GruntM28After:
#if GERMAN
	.string "Hyuck-hyuck-hyuck!\p"
	.string "Das Passwort für den Bossraum…\p"
	.string "Ähm… ich glaube, es ist Rattikarl-Rute.$"
#else
    .string "Hyuck-hyuck-hyuck!\p"
    .string "The password to the boss' room…\p"
    .string "Uh…, I think it is RATICATE TAIL.$"
#endif

RocketHideout_B3F_Text_ScientistRossSeen:
#if GERMAN
	.string "Früher habe ich für Silph gearbeitet,\n"
	.string "aber nun leite ich Team Rockets\l"
	.string "Forschungen.\p"
	.string "Ein Kind wie du, das sich überall\n"
	.string "einmischt, hat einen Klaps verdient!$"
#else
    .string "I used to work for SILPH, but now\n"
    .string "I run research for TEAM ROCKET.\p"
    .string "A meddlesome child like you needs\n"
    .string "to be punished.$"
#endif

RocketHideout_B3F_Text_ScientistRossBeaten:
#if GERMAN
	.string "Nein! Nur ein kleiner taktischer Fehler…$"
#else
    .string "A mere tactical error cost me…$"
#endif

RocketHideout_B3F_Text_ScientistRossAfter:
#if GERMAN
	.string "Ein Radiosignal, das Pokémon um den\n"
	.string "Verstand bringt…\p"
	.string "Mein Experiment war ein voller Erfolg.\n"
	.string "Eine Beförderung ist mir gewiss. Diese\l"
	.string "Niederlage bedeutet gar nichts.$"
#else
    .string "A radio signal that drives\n"
    .string "POKéMON mad…\p"
    .string "My experiment is a complete\n"
    .string "success.\p"
    .string "My promotion is assured. This\n"
    .string "loss means absolutely nothing.$"
#endif

RocketHideout_B3F_Text_ScientistMitchSeen:
#if GERMAN
	.string "Mir doch egal, wenn Pokémon bei unserem\n"
	.string "Experiment Schmerzen zugefügt werden.$"
#else
    .string "I don't care that POKéMON are hurt\n"
    .string "by our experiment.$"
#endif

RocketHideout_B3F_Text_ScientistMitchBeaten:
#if GERMAN
	.string "Meine Stärke ist das Denken, nicht das\n"
	.string "Kämpfen.$"
#else
    .string "Thinking is my strong suit, not\n"
    .string "battling.$"
#endif

RocketHideout_B3F_Text_ScientistMitchAfter:
#if GERMAN
	.string "Wenn wir das Radiosignal verstärken,\n"
	.string "könnte man es landesweit empfangen…\p"
	.string "Allein der Gedanke entzückt mich!$"
#else
    .string "If we turn up the power of our\n"
    .string "radio signal for broadcast\l"
    .string "nationwide…\p"
    .string "The very thought excites me!$"
#endif
