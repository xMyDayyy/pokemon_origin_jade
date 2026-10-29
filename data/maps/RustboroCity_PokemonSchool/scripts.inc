RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
#if IS_HNS
	@ Hoenn badge 1 (Roxanne)
	setvar VAR_0x8004, 0
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
#else
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
#endif
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
#if IS_HNS
	@ Hoenn badge 1 (Roxanne)
	setvar VAR_0x8004, 0
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
#else
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
#endif
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
#if GERMAN
	.string "Auf der Tafel sind die Statusverände-\n"
	.string "rungen von Pokémon aufgelistet.$"
#else
	.string "The blackboard lists status changes\n"
	.string "that may affect POKéMON in battle.$"
#endif

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
#if GERMAN
	.string "Welches Thema möchtest du lesen?$"
#else
	.string "Which topic do you want to read?$"
#endif

RustboroCity_PokemonSchool_Text_ExplainPoison:
#if GERMAN
	.string "Wenn ein Pokémon vergiftet wurde, wird\n"
	.string "es ständig KP verlieren.\p"
	.string "Die Auswirkungen des Giftes halten\n"
	.string "auch nach dem Kampf an.\p"
	.string "Die KP eines vergifteten Pokémon\n"
	.string "werden auch unterwegs weiter sinken.\p"
	.string "Mit einem Gegengift kann das Pokémon\n"
	.string "geheilt werden.$"
#else
	.string "If a POKéMON is poisoned, it will\n"
	.string "steadily lose HP.\p"
	.string "The effects of poison remain after\n"
	.string "a battle.\p"
	.string "A poisoned POKéMON's HP will drop\n"
	.string "while it is traveling.\p"
	.string "Heal a poisoning using an ANTIDOTE.$"
#endif

RustboroCity_PokemonSchool_Text_ExplainParalysis:
#if GERMAN
	.string "Wurde ein Pokémon paralysiert, sinkt\n"
	.string "seine Initiative.\p"
	.string "Es kann passieren, dass es während des\n"
	.string "Kampfes bewegungsunfähig wird.\p"
	.string "Die Paralyse hält auch nach dem Kampf\n"
	.string "an. Heile das Pokémon mit Para-Heiler.$"
#else
	.string "If a POKéMON becomes paralyzed,\n"
	.string "its SPEED drops.\p"
	.string "It may also not be able to move while\n"
	.string "it is in battle.\p"
	.string "Paralysis remains after battle.\n"
	.string "Cure it using a PARLYZ HEAL.$"
#endif

RustboroCity_PokemonSchool_Text_ExplainSleep:
#if GERMAN
	.string "Wenn ein Pokémon einschläft, kann es\n"
	.string "nicht mehr angreifen.\p"
	.string "Das Pokémon wird vielleicht von selber\n"
	.string "wieder wach, aber wenn der Kampf endet\l"
	.string "und es noch schläft, schläft es weiter.\p"
	.string "Wecke es mit Aufwecker auf.$"
#else
	.string "If a POKéMON falls asleep, it will be\n"
	.string "unable to attack.\p"
	.string "A POKéMON may wake up on its own,\n"
	.string "but if a battle ends while it is\l"
	.string "sleeping, it will stay asleep.\p"
	.string "Wake it up using an AWAKENING.$"
#endif

RustboroCity_PokemonSchool_Text_ExplainBurn:
#if GERMAN
	.string "Eine Verbrennung senkt die Kraft des\n"
	.string "Angriffs. Die KP nehmen ständig ab.\p"
	.string "Eine Verbrennung hält auch nach dem\n"
	.string "Kampf an. Setze Feuerheiler ein!$"
#else
	.string "A burn reduces ATTACK power, and it\n"
	.string "steadily reduces the victim's HP.\p"
	.string "A burn lingers after battle.\n"
	.string "Cure a burn using a BURN HEAL.$"
#endif

RustboroCity_PokemonSchool_Text_ExplainFreeze:
#if GERMAN
	.string "Wurde ein Pokémon eingefroren, so ist\n"
	.string "es völlig hilflos.\p"
	.string "Auch nach dem Kampf hält der Zustand\n"
	.string "an. Setze dann Eisheiler ein.$"
#else
	.string "If a POKéMON is frozen, it becomes\n"
	.string "completely helpless.\p"
	.string "It will remain frozen after battle.\n"
	.string "Thaw it out using an ICE HEAL.$"
#endif

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
#if GERMAN
	.string "Schüler, die nicht aufpassen, bekommen\n"
	.string "meine Flinkklaue zu spüren.\p"
	.string "Wie du dieses Item einsetzt, zeigt, ob\n"
	.string "du ein guter Schüler bist oder nicht.$"
#else
	.string "Students who don't study get a little\n"
	.string "taste of my QUICK CLAW.\p"
	.string "Whether or not you are a good student \n"
	.string "will be evident from the way you use\l"
	.string "this item.$"
#endif

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
#if GERMAN
	.string "Ein Pokémon, das die Flinkklaue trägt,\n"
	.string "steigert seine Schnelligkeit und greift\l"
	.string "eventuell schneller an als sein Gegner.\p"
	.string "Es gibt noch viele andere Items, die von\n"
	.string "einem Pokémon getragen werden können.\p"
	.string "\p"
	.string "Du kannst also noch viel lernen.$"
#else
	.string "A POKéMON holding the QUICK CLAW will\n"
	.string "occasionally speed up and get to move\l"
	.string "before its opponent.\p"
	.string "There are many other items that are\n"
	.string "meant to be held by POKéMON.\p"
	.string "Just those alone will give you many\n"
	.string "topics to study!$"
#endif

RustboroCity_PokemonSchool_Text_TradingRightNow:
#if GERMAN
	.string "Ich tausche gerade mit meinem Freund\n"
	.string "Pokémon.$"
#else
	.string "I'm trading POKéMON with my friend\n"
	.string "right now.$"
#endif

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
#if GERMAN
	.string "Ich wollte schon immer ein Samurzel\n"
	.string "haben - und endlich habe ich eines!$"
#else
	.string "I always wanted a SEEDOT, and\n"
	.string "I'm finally getting one!$"
#endif

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
#if GERMAN
	.string "Pokémon können Items tragen, aber sie\n"
	.string "wissen nicht, was sie mit Items von\l"
	.string "Menschen wie Trank oder Gegengift\l"
	.string "machen sollen.$"
#else
	.string "POKéMON can hold items, but they\n"
	.string "don't know what to do with man-made\l"
	.string "items like POTION and ANTIDOTE.$"
#endif

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
#if GERMAN
	.string "Weißt du, wie man mit einigen Pokémon-\n"
	.string "Attacken ein Pokémon verwirren kann?\p"
	.string "Ein verwirrtes Pokémon wird manchmal\n"
	.string "sich selber verletzen, ohne es zu\l"
	.string "wollen.\p"
	.string "Aber sobald es aus dem Kampf genommen\n"
	.string "wird, ist es wieder normal.$"
#else
	.string "You know how some POKéMON moves can\n"
	.string "confuse a POKéMON?\p"
	.string "A confused POKéMON will sometimes\n"
	.string "attack itself without meaning to.\p"
	.string "But once it leaves battle, it will\n"
	.string "return to normal.$"
#endif

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
#if GERMAN
	.string "Ein Pokémon, das eine Beere trägt,\n"
	.string "wird sich selber heilen…\p"
	.string "Es gibt viele Items, die ein Pokémon\n"
	.string "tragen kann…\p"
	.string "Junge, Junge, ist das alles schwer\n"
	.string "zu merken…$"
#else
	.string "A POKéMON holding a BERRY will heal\n"
	.string "itself…\p"
	.string "There are many kinds of items that\n"
	.string "POKéMON can hold…\p"
	.string "Boy, it sure is hard taking notes\n"
	.string "down…$"
#endif

RustboroCity_PokemonSchool_Text_StudentsNotes:
#if GERMAN
	.string "Das ist das Heft eines Schülers…\p"
	.string "Pokémon werden mit Pokébällen\n"
	.string "gefangen.\p"
	.string "Bis zu sechs Pokémon können den\n"
	.string "Trainer begleiten.\p"
	.string "Ein Trainer ist jemand, der Pokémon\n"
	.string "fängt, sie aufzieht, und mit ihnen\l"
	.string "kämpft.\p"
	.string "Die Aufgabe eines Trainers ist es, die\n"
	.string "starken Trainer, die ihn in den Arenen\l"
	.string "erwarten, zu besiegen.$"
#else
	.string "It's this student's notebook…\p"
	.string "POKéMON are to be caught using\n"
	.string "POKé BALLS.\p"
	.string "Up to six POKéMON can accompany\n"
	.string "a TRAINER.\p"
	.string "A TRAINER is someone who catches\n"
	.string "POKéMON, raises them, and battles\l"
	.string "with them.\p"
	.string "A TRAINER's mission is to defeat\n"
	.string "the strong TRAINERS who await\l"
	.string "challengers in POKéMON GYMS.$"
#endif

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
#if GERMAN
	.string "Hallo! In Blütenburg sind wir uns\n"
	.string "schon über den Weg gelaufen.\p"
	.string "Vorgestellt habe ich mich da nicht -\n"
	.string "und dabei belasse ich es fürs Erste.\p"
	.string "Ich reise durch die Lande, auf der\n"
	.string "Suche nach herausragenden Trainern.\p"
	.string "Und du…\n"
	.string "du bist keiner von den Anfängern hier.\p"
	.string "Wir sehen uns wieder.$"
#else
	.string "Hello! We crossed paths in PETALBURG\n"
	.string "already.\p"
	.string "I didn't introduce myself then -\n"
	.string "and I'll keep it that way for now.\p"
	.string "I travel the land looking for\n"
	.string "outstanding TRAINERS.\p"
	.string "And you…\n"
	.string "you are no beginner.\p"
	.string "We will meet again.$"
#endif

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
#if GERMAN
	.string "???: Hmm…\p"
	.string "Ich frage mich, welches Talent-Niveau\n"
	.string "die Schüler hier haben. Das ist völlig\l"
	.string "unbekannt.$"
#else
	.string "???: Hmm…\p"
	.string "The talent levels of the students here\n"
	.string "are unknown. The potential's there.$"
#endif

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
#if GERMAN
	.string "???: Hmm…\p"
	.string "Das ist der Steinorden, oder?!?\n"
	.string "Wirklich beeindruckend, muss ich schon\l"
	.string "sagen.\p"
	.string "Ich würde dich liebend gerne mal in\n"
	.string "einem Kampf beobachten.\p"
	.string "Man kann einen Trainer, der einen Orden\n"
	.string "der Liga besitzt, immer schwer\l"
	.string "einschätzen.$"
#else
	.string "SCOTT: Oh, what's that?\p"
	.string "It's a STONE BADGE, isn't it?\n"
	.string "That's pretty impressive, I'd say.\p"
	.string "But, you know, I would've loved to see\n"
	.string "you in battle.\p"
	.string "It's hard to tell what you're like as\n"
	.string "a TRAINER from a LEAGUE BADGE.$"
#endif

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
#if GERMAN
	.string "Hallo! In Blütenburg sind wir uns\n"
	.string "schon über den Weg gelaufen.\p"
	.string "Vorgestellt habe ich mich da nicht -\n"
	.string "und dabei belasse ich es fürs Erste.\p"
	.string "Ich reise durch die Lande, auf der\n"
	.string "Suche nach herausragenden Trainern.\p"
	.string "Was ist das?\n"
	.string "Das ist der Steinorden, oder?!?\p"
	.string "Ich würde dich liebend gerne mal in\n"
	.string "einem Kampf beobachten.$"
#else
	.string "Hello! We crossed paths in PETALBURG\n"
	.string "already.\p"
	.string "I didn't introduce myself then -\n"
	.string "and I'll keep it that way for now.\p"
	.string "I travel the land looking for\n"
	.string "outstanding TRAINERS.\p"
	.string "What's that?\n"
	.string "That is the STONE BADGE, isn't it?\p"
	.string "I would dearly love to watch you\n"
	.string "battle some time.$"
#endif

