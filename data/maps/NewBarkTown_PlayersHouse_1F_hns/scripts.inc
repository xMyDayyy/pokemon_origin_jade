NewBarkTown_PlayersHouse_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_PlayersHouse_1F_OnTransition
	.byte 0

NewBarkTown_PlayersHouse_1F_OnTransition::
	call_if_eq VAR_NEWBARK_TOWN_STATE, 1, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 3, NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable
	end

NewBarkTown_PlayersHouse_1F_SetMomStandingAtTable::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_LEFT

	@add to newgame later
	clearflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_MOM_VISITED
	return

@ Kanto-Merge: Das Haus gehoert nicht dem Spieler. Hier wohnt eine Frau mit
@ ihrem Sohn; der ist unterwegs und taucht spaeter im Spiel auf.
NewBarkTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	msgbox NewBarkTown_PlayersHouse_1F_Text_WomanOfTheHouse, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MovementFaceLeft
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsFriend::
	lock
	faceplayer
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomsFriend, MSGBOX_DEFAULT
	applymovement LOCALID_MOMS_FRIEND, NewBarkTown_PlayersHouse_1F_MovementFaceRight
	waitmovement 0
	release
	end

NewBarkTown_PlayersHouse_1F_MomEventScript_GoodLuck::
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	msgbox NewBarkTown_PlayersHouse_1F_Text_MomLeaving, MSGBOX_DEFAULT
	setflag FLAG_MOM_VISITED
	clearflag FLAG_HIDE_ROUTE_30_NPCS
	setvar VAR_NEWBARK_TOWN_STATE, 5
	fadedefaultbgm
	release
	end


NewBarkTown_PlayersHouse_1F_EventScript_MomsIntroTrigger1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_1F_PlayerIntroMovement1
	waitmovement 0
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro
	end

NewBarkTown_PlayersHouse_1F_EventScript_MomsIntroTrigger2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_1F_PlayerIntroMovement2
	waitmovement 0
	goto NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro
	end


NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro::
	playbgm MUS_HG_FOLLOW_ME_1, FALSE
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_MOM
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MomMovement_1
	waitmovement 0
	msgbox NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou, MSGBOX_DEFAULT
	call NewBarkTown_PlayersHouse_1F_EventScript_GivePokeGear
	call NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes
	applymovement LOCALID_MOM, NewBarkTown_PlayersHouse_1F_MomMovement_2
	waitmovement 0
	setvar VAR_NEWBARK_TOWN_STATE, 2
	setvar VAR_NEWBARKTOWN_LABSTATE, 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	setflag FLAG_VISITED_NEWBARK_TOWN

	@former flagheap location

	fadedefaultbgm
	releaseall
	end



NewBarkTown_PlayersHouse_1F_EventScript_GivePokeGear::
	playfanfare MUS_REGISTER_MATCH_CALL
	message NewBarkTown_PlayersHouse_1F_Text_ObtainedPokeGear
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_REGISTER_RIVAL_POKENAV
	msgbox NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

NewBarkTown_PlayersHouse_1F_EventScript_GiveRunningShoes::
	msgbox NewBarkTown_PlayersHouse_1F_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBarkTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

NewBarkTown_PlayersHouse_1F_PlayerIntroMovement1:
	delay_8
	walk_down
	walk_right
	walk_down
	face_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_PlayerIntroMovement2:
	delay_8
	walk_down
	face_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_MomMovement_1:
	face_right
	walk_right
	step_end

NewBarkTown_PlayersHouse_1F_MomMovement_2:
	face_left
	walk_left
	delay_8
	step_end

NewBarkTown_PlayersHouse_1F_MovementFaceRight:
	face_right
	step_end

NewBarkTown_PlayersHouse_1F_MovementFaceLeft:
	face_left
	step_end

NewBarkTown_PlayersHouse_1F_Text_ElmsLookingForYou:
#if GERMAN
	.string "Oh, {PLAYER}…! Unser Nachbar,\n"
	.string "Prof. Lind, sucht nach dir.\p"
	.string "Er will, dass du ihm bei etwas hilfst.\p"
	.string "Oh! Fast vergessen! Dein PokéCom kam\n"
	.string "fertig aus der Werkstatt.\p"
	.string "Hier, nimm ihn!$"
#else
	.string "Oh, {PLAYER}…! Our neighbor,\n"
	.string "PROF.ELM, was looking for you.\p"
	.string "He said he wanted you to do\n"
	.string "something for him.\p"
	.string "Oh! I almost forgot! Your POKéGEAR\n"
	.string "is back from the repair shop.\p"
	.string "Here you go!$"
#endif

NewBarkTown_PlayersHouse_1F_Text_ObtainedPokeGear:
#if GERMAN
	.string "{PLAYER} erhielt das PokéCom.$"
#else
	.string "{PLAYER} obtained the POKéGEAR.$"
#endif

NewBarkTown_PlayersHouse_1F_Text_ExplainPokeGear:
#if GERMAN
	.string "Mama: Telefonnummern befinden\n"
	.string "sich im Speicher.\p"
	.string "Wähle einfach einen Namen aus,\n"
	.string "um anzurufen.\p"
	.string "Wie praktisch!$"
#else
	.string "MOM: Phone numbers are stored\n"
	.string "in memory.\p"
	.string "Just choose a name you want to call.\n"
	.string "I've already registered my number.\p"
	.string "Gee, isn't that convenient?$"
#endif

NewBarkTown_PlayersHouse_1F_Text_WearTheseRunningShoes:
#if GERMAN
	.string "Oh, und vergiss nicht deine\n"
	.string "Turbotreter!$"
#else
	.string "Oh, and don't forget your\n"
	.string "RUNNING SHOES!$"
#endif

NewBarkTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes:
#if GERMAN
	.string "{PLAYER} tauschte Schuhe gegen\n"
	.string "die Turbotreter.$"
#else
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"
#endif

NewBarkTown_PlayersHouse_1F_Text_ExplainRunningShoes:
#if GERMAN
	.string "Mama: {PLAYER}, halte B gedrückt,\n"
	.string "um mit diesen Schuhen zu laufen!$"
#else
	.string "MOM: {PLAYER}, press the B Button\n"
	.string "while wearing these to run fast!$"
#endif

NewBarkTown_PlayersHouse_1F_Text_MomHurryUpElmIsWaiting:
#if GERMAN
	.string "Mama: Prof. Lind wartet auf dich.\p"
	.string "Beeil dich, Liebling!$"
#else
	.string "MOM: PROF.ELM is waiting for you.\p"
	.string "Hurry up, baby!$"
#endif

NewBarkTown_PlayersHouse_1F_Text_WomanOfTheHouse:
#if GERMAN
	.string "Oh! Entschuldige, ich habe dich\n"
	.string "nicht kommen hören.\p"
	.string "Du bist nicht von hier, oder?\n"
	.string "In Neuborkia kennt man sich.\p"
	.string "Mein Sohn ist auch unterwegs. Mit\n"
	.string "seinen Pokémon, irgendwo da\l"
	.string "draußen.\p"
	.string "Wenn du ihm begegnest, sei nicht zu\n"
	.string "hart zu ihm.$"
#else
	.string "Oh! Sorry, I did not hear you come\n"
	.string "in.\p"
	.string "You are not from here, are you?\n"
	.string "Everyone knows everyone in NEW BARK\l"
	.string "TOWN.\p"
	.string "My son is out travelling too. With\n"
	.string "his POKéMON, somewhere out there.\p"
	.string "If you run into him, go easy on him.$"
#endif

NewBarkTown_PlayersHouse_1F_Text_MomsFriend:
#if GERMAN
	.string "Oh, ein Gast! Selten hier.\p"
	.string "Ich bin nur zu Besuch. Wir kennen\n"
	.string "uns von früher.\p"
	.string "Meine Tochter will unbedingt\n"
	.string "Prof. Linds Assistentin werden.\p"
	.string "Sie liebt Pokémon wirklich sehr!$"
#else
	.string "Oh, a guest! We rarely get those.\p"
	.string "I am only visiting. We have known\n"
	.string "each other for years.\p"
	.string "My daughter is set on becoming\n"
	.string "PROF. ELM's assistant.\p"
	.string "She really does love POKéMON!$"
#endif

NewBarkTown_PlayersHouse_1F_Text_MomLeaving:
#if GERMAN
	.string "Mama: Oh, was für ein süßes Pokémon!\p"
	.string "Wo hast du es her?\p"
	.string "…\p"
	.string "Du gehst also auf ein Abenteuer…\n"
	.string "Das wird bestimmt schwierig…\p"
	.string "Pass gut auf dich auf.\p"
	.string "Pokémon sind deine Freunde.\n"
	.string "Ihr müsst als Team arbeiten.\p"
	.string "Jetzt los!\n"
	.string "Ich stehe hinter dir!$"
#else
	.string "MOM: Wow, that's a cute POKéMON.\n"
	.string "Where did you get it?\p"
	.string "…\p"
	.string "So, you're leaving on an adventure...\n"
	.string "That does sound challenging...\p"
	.string "Just be careful.\p"
	.string "POKéMON are your friends.\n"
	.string "You need to work as a team.\p"
	.string "Now, go on!\n"
	.string "I'm behind you all the way!$"
#endif
