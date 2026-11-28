SaffronCity_MrPsychicsHouse_Frlg_MapScripts::
	.byte 0

SaffronCity_MrPsychicsHouse_EventScript_MrPsychic::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM29_FROM_MR_PSYCHIC, SaffronCity_MrPsychicsHouse_EventScript_AlreadyGotTM29
	msgbox SaffronCity_MrPsychicsHouse_Text_YouWantedThis
	checkitemspace ITEM_TM29
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29
	giveitem_msg SaffronCity_MrPsychicsHouse_Text_ReceivedTM29FromMrPsychic, ITEM_TM29
	msgbox SaffronCity_MrPsychicsHouse_Text_ExplainTM29
	setflag FLAG_GOT_TM29_FROM_MR_PSYCHIC
	release
	end

SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29::
	msgbox SaffronCity_MrPsychicsHouse_Text_YouveNoRoom
	release
	end

SaffronCity_MrPsychicsHouse_EventScript_AlreadyGotTM29::
	msgbox SaffronCity_MrPsychicsHouse_Text_ExplainTM29
	release
	end

SaffronCity_MrPsychicsHouse_Text_YouWantedThis::
#if GERMAN
	.string "Warte!\n"
	.string "Sag kein Wort!\p"
	.string "Du suchst dies hier, oder?$"
#else
	.string "…Wait! Don't say a word!\p"
	.string "You wanted this!$"
#endif

SaffronCity_MrPsychicsHouse_Text_ReceivedTM29FromMrPsychic::
#if GERMAN
	.string "{PLAYER} erhält TM29!$"
#else
	.string "{PLAYER} received TM29\n"
	.string "from MR. PSYCHIC.$"
#endif

SaffronCity_MrPsychicsHouse_Text_ExplainTM29::
#if GERMAN
	.string "TM29 ist Psychokinese!\p"
	.string "Sie vermindert die Spezial-Fähigkeiten\n"
	.string "des Gegners.$"
#else
	.string "You already know, don't you?\n"
	.string "TM29 is PSYCHIC.\p"
	.string "It's an attack that may also lower\n"
	.string "the target's special stats.$"
#endif

SaffronCity_MrPsychicsHouse_Text_YouveNoRoom::
#if GERMAN
	.string "Heh, du kannst keine Items mehr\n"
	.string "tragen!$"
#else
	.string "Where do you plan to put this?\n"
	.string "You've no room.$"
#endif


@ Origin Jade: the Move Maniac of Two Island (Sevii is not part of the game)
@ now lives here and teaches a move for one Heart Scale.
SaffronCity_MrPsychicsHouse_EventScript_MoveManiac::
	lock
	faceplayer
	specialvar VAR_RESULT, IsRandomMovesActivated
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_MrPsychicsHouse_EventScript_Randomizer
	goto_if_set FLAG_TEMP_1, SaffronCity_MrPsychicsHouse_EventScript_AskTeachMove
	msgbox SaffronCity_MrPsychicsHouse_Text_TeachMonMoveForHeartScale
	setflag FLAG_TEMP_1
	goto SaffronCity_MrPsychicsHouse_EventScript_AskTeachMove
	end

SaffronCity_MrPsychicsHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_MrPsychicsHouse_EventScript_EndTutorMove
	msgbox SaffronCity_MrPsychicsHouse_Text_WantMeToTeachMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_MrPsychicsHouse_EventScript_EndTutorMove
	goto SaffronCity_MrPsychicsHouse_EventScript_ChooseMonToTutor
	end

SaffronCity_MrPsychicsHouse_EventScript_ChooseMonToTutor::
	msgbox SaffronCity_MrPsychicsHouse_Text_TutorWhichMon
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES
	chooseboxmon SELECT_PC_MON_MOVE_RELEARNER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SaffronCity_MrPsychicsHouse_EventScript_EndTutorMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_MrPsychicsHouse_EventScript_CantTutorEgg
	special HasMovesToRelearn
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_MrPsychicsHouse_EventScript_NoMoveToTutorMon
	goto SaffronCity_MrPsychicsHouse_EventScript_ChooseMoveToTeach
	end

SaffronCity_MrPsychicsHouse_EventScript_ChooseMoveToTeach::
	msgbox SaffronCity_MrPsychicsHouse_Text_TeachWhichMove
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, SaffronCity_MrPsychicsHouse_EventScript_ChooseMonToTutor
	removeitem ITEM_HEART_SCALE
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox SaffronCity_MrPsychicsHouse_Text_HandedOverHeartScale
	call EventScript_RestorePrevTextColor
	goto SaffronCity_MrPsychicsHouse_EventScript_EndTutorMove
	end

SaffronCity_MrPsychicsHouse_EventScript_NoMoveToTutorMon::
	msgbox SaffronCity_MrPsychicsHouse_Text_NoMoveICanTeachThatMon
	goto SaffronCity_MrPsychicsHouse_EventScript_ChooseMonToTutor
	end

SaffronCity_MrPsychicsHouse_EventScript_CantTutorEgg::
	msgbox SaffronCity_MrPsychicsHouse_Text_CantTeachAnEgg
	goto SaffronCity_MrPsychicsHouse_EventScript_ChooseMonToTutor
	end

SaffronCity_MrPsychicsHouse_EventScript_EndTutorMove::
	msgbox SaffronCity_MrPsychicsHouse_Text_NeedHeartScaleToLearnMove
	release
	end

SaffronCity_MrPsychicsHouse_Text_TeachMonMoveForHeartScale::
#if GERMAN
	.string "Ich bin der Pokémon-Attacken-\n"
	.string "Maniac!\p"
	.string "Ich kenne jede Attacke, die Pokémon\n"
	.string "beim Levelanstieg erlernen.\p"
	.string "Außerdem sammle ich Herzschuppen.\p"
	.string "Gib mir eine Herzschuppe.\p"
	.string "Dafür bringe ich einem deiner\n"
	.string "Pokémon eine Attacke bei.$"
#else
	.string "I'm the POKéMON MOVE MANIAC.\p"
	.string "I know every single move that\n"
	.string "POKéMON learn growing up.\p"
	.string "I'm also a HEART SCALE maniac.\p"
	.string "Bring me one HEART SCALE.\p"
	.string "If you do that for me, I'll teach\n"
	.string "a move to one POKéMON.$"
#endif

SaffronCity_MrPsychicsHouse_Text_WantMeToTeachMove::
#if GERMAN
	.string "Oh!\n"
	.string "Du hast ja eine Herzschuppe dabei!\p"
	.string "Soll ich einem deiner Pokémon\n"
	.string "eine Attacke beibringen?$"
#else
	.string "Oh!\n"
	.string "You have a HEART SCALE with you!\p"
	.string "Do you want me to teach a move\n"
	.string "to a POKéMON of yours?$"
#endif

SaffronCity_MrPsychicsHouse_Text_TutorWhichMon::
#if GERMAN
	.string "Welches Pokémon soll sie lernen?$"
#else
	.string "Which POKéMON needs tutoring?$"
#endif

SaffronCity_MrPsychicsHouse_Text_TeachWhichMove::
#if GERMAN
	.string "Welche Attacke soll ich es lehren?$"
#else
	.string "Which move should I teach?$"
#endif

SaffronCity_MrPsychicsHouse_Text_NoMoveICanTeachThatMon::
#if GERMAN
	.string "Tut mir leid…\p"
	.string "Anscheinend gibt es keine Attacke,\n"
	.string "die ich diesem Pokémon beibringen\l"
	.string "kann.$"
#else
	.string "Sorry…\p"
	.string "It doesn't appear as if I have a\n"
	.string "move I can teach that POKéMON.$"
#endif

SaffronCity_MrPsychicsHouse_Text_HandedOverHeartScale::
#if GERMAN
	.string "{PLAYER} übergibt eine Herzschuppe.$"
#else
	.string "{PLAYER} handed over one\n"
	.string "HEART SCALE in exchange.$"
#endif

SaffronCity_MrPsychicsHouse_Text_NeedHeartScaleToLearnMove::
#if GERMAN
	.string "Falls deine Pokémon eine Attacke\n"
	.string "lernen sollen, bring mir eine\l"
	.string "Herzschuppe!$"
#else
	.string "If your POKéMON need to learn a\n"
	.string "move, bring me a HEART SCALE.$"
#endif

SaffronCity_MrPsychicsHouse_Text_CantTeachAnEgg::
#if GERMAN
	.string "Bitte? Ich kann einem Ei nicht eine\n"
	.string "einzige Attacke beibringen!$"
#else
	.string "Hunh? There isn't a single move\n"
	.string "that I can teach an EGG.$"
#endif

@ Like the move relearner of Blackthorn City: no relearning while random moves are on.
SaffronCity_MrPsychicsHouse_EventScript_Randomizer::
	msgbox SaffronCity_MrPsychicsHouse_Text_SorryCantHelp, MSGBOX_DEFAULT
	release
	end

SaffronCity_MrPsychicsHouse_Text_SorryCantHelp:
#if GERMAN
	.string "Sorry, ich kann dir nicht helfen.$"
#else
	.string "Sorry, I can't help you.$"
#endif
