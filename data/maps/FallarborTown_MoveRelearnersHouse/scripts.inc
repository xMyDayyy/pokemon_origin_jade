FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	specialvar VAR_RESULT, IsRandomMovesActivated
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_Randomizer
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES @ Specifically supposed to teach level up moves
	chooseboxmon SELECT_PC_MON_MOVE_RELEARNER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	special HasMovesToRelearn
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
#if GERMAN
	.string "Ich bin der Attacken-Helfer.\p"
	.string "Ich kenne alle Attacken, die ein\n"
	.string "Pokémon lernen kann - und ich kann sie\l"
	.string "ihnen beibringen.\p"
	.string "Ich kann auch deinen Pokémon neue\n"
	.string "Attacken beibringen, wenn du magst.\p"
	.string "Als Gegenleistung hätte ich gerne eine\n"
	.string "Herzschuppe. Die sammle ich nämlich.$"
#else
	.string "I'm the MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for a HEART SCALE.\n"
	.string "I'm collecting those now.$"
#endif

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
#if GERMAN
	.string "Oh! Das ist es! Das ist ehrlich und\n"
	.string "wahrhaftig eine Herzschuppe!\p"
	.string "Lass mich raten… Ich soll einem Pokémon\n"
	.string "eine neue Attacke beibringen?!?$"
#else
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness HEART SCALE!\p"
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"
#endif

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
#if GERMAN
	.string "Welches Pokémon soll sie lernen?$"
#else
	.string "Which POKéMON needs tutoring?$"
#endif

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
#if GERMAN
	.string "Welche Attacke soll ich es lehren?$"
#else
	.string "Which move should I teach?$"
#endif

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
#if GERMAN
	.string "Tut mir Leid…\p"
	.string "Scheinbar gibt es keine Attacke, die\n"
	.string "ich diesem Pokémon beibringen kann.$"
#else
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"
#endif

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
#if GERMAN
	.string "{PLAYER} tauscht eine Herzschuppe ein.$"
#else
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"
#endif

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
#if GERMAN
	.string "Falls deine Pokémon neue Attacken\n"
	.string "lernen sollen, komm mit einer\l"
	.string "Herzschuppe wieder.$"
#else
	.string "If your POKéMON need to learn a move,\n"
	.string "come back with a HEART SCALE.$"
#endif

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
#if GERMAN
	.string "Bitte? Ich kann einem Ei nicht eine\n"
	.string "einzige Attacke beibringen!$"
#else
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an EGG.$"
#endif

@ Random moves: no relearner, like Blackthorn City and Saffron City.
FallarborTown_MoveRelearnersHouse_EventScript_Randomizer::
	msgbox FallarborTown_MoveRelearnersHouse_Text_SorryCantHelp, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_SorryCantHelp:
#if GERMAN
	.string "Sorry, ich kann dir nicht helfen.$"
#else
	.string "Sorry, I can't help you.$"
#endif
