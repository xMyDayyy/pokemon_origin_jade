PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
#if GERMAN
	.string "Hmmm… Kein Einziges zu finden.$"
#else
	.string "Hmmm…\n"
	.string "Not a one to be found…$"
#endif

PetalburgWoods_Text_HaveYouSeenShroomish:
#if GERMAN
	.string "Hallo, du hast nicht zufällig einige\n"
	.string "Pokémon namens Knilz hier\p"
	.string "gesehen? Ich liebe diese Pokémon.$"
#else
	.string "Hello, have you seen any POKéMON\n"
	.string "called SHROOMISH around here?\p"
	.string "I really love that POKéMON.$"
#endif

PetalburgWoods_Text_IWasGoingToAmbushYou:
#if GERMAN
	.string "Ich wollte dich eigentlich aus dem\n"
	.string "Hinterhalt angreifen, aber du trödelst\l"
	.string "wohl auf ewig im Blütenburgwald herum,\l"
	.string "oder?\p"
	.string "Das Warten machte mich ganz krank.\n"
	.string "Also, hier bin ich.$"
#else
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in PETALBURG WOODS\l"
	.string "forever, didn't you?\p"
	.string "I got sick of waiting, so here I am!$"
#endif

PetalburgWoods_Text_HandOverThosePapers:
#if GERMAN
	.string "He, du! Forscher von Devon!\p"
	.string "Gib sofort die Papiere her!$"
#else
	.string "You! DEVON RESEARCHER!\p"
	.string "Hand over those papers!$"
#endif

PetalburgWoods_Text_YouHaveToHelpMe:
#if GERMAN
	.string "Attackeee!\p"
	.string "Du bist ein Pokémon-Trainer, oder?\n"
	.string "Du musst mir bitte helfen!$"
#else
	.string "Aiyeeeh!\p"
	.string "You're a POKéMON TRAINER, aren't you?\n"
	.string "You've got to help me, please!$"
#endif

PetalburgWoods_Text_NoOneCrossesTeamAqua:
#if GERMAN
	.string "Huch. Was machst du da eigentlich???\n"
	.string "Was?!? Du schützt ihn???\p"
	.string "Niemand, der sich Team Aqua in den Weg\n"
	.string "stellt, kann auf Gnade hoffen.\l"
	.string "Niemand! \p"
	.string "Los, kämpfe gegen mich!$"
#else
	.string "Hunh? What do you think you're doing?\n"
	.string "What, you're going to protect him?\p"
	.string "No one who crosses TEAM AQUA\n"
	.string "gets any mercy, not even a kid!\p"
	.string "Come on and battle me!$"
#endif

PetalburgWoods_Text_YoureKiddingMe:
#if GERMAN
	.string "Du hast mich geleimt! Du bist stark!$"
#else
	.string "You're kidding me! You're tough!$"
#endif

PetalburgWoods_Text_YouveGotSomeNerve:
#if GERMAN
	.string "Grrr… Du hast vielleicht Nerven, dich\n"
	.string "mit Team Aqua anzulegen!\l"
	.string "Los, kämpfen wir noch einmal!\p"
	.string "Hm, das würde ich jetzt zu gerne sagen,\n"
	.string "aber ich habe keine Pokémon mehr…\p"
	.string "Außerdem sind wir, Team Aqua, auf dem\n"
	.string "Weg nach Metarost City.\p"
	.string "Für heute lasse ich dich gehen.$"
#else
	.string "Grrr… You've got some nerve\n"
	.string "meddling with TEAM AQUA!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I'm out of\n"
	.string "POKéMON…\p"
	.string "And, hey, we of TEAM AQUA are also\n"
	.string "after something in RUSTBORO.\p"
	.string "I'll let you go today!$"
#endif

PetalburgWoods_Text_ThatWasAwfullyClose:
#if GERMAN
	.string "Huuuh… Das war aber mehr als knapp!\p"
	.string "Dank dir konnte er mir diese wichtigen\n"
	.string "Papiere nicht rauben.\p"
	.string "Ich weiß! Ich gebe dir diesen\n"
	.string "Superball als Dankeschön!$"
#else
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "these important papers.\p"
	.string "I know, I'll give you a GREAT BALL as\n"
	.string "my thanks!$"
#endif

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
#if GERMAN
	.string "Hat dieser Schuft von Team Aqua nicht\n"
	.string "gesagt, dass sie irgendetwas in\l"
	.string "Metarost City erledigen wollen?$"
#else
	.string "Didn't that TEAM AQUA thug say\n"
	.string "they were after something in\l"
	.string "RUSTBORO, too?$"
#endif

PetalburgWoods_Text_ICantBeWastingTime:
#if GERMAN
	.string "Oh oh! Das ist ein Notfall!\n"
	.string "Ich darf keine Zeit verlieren!$"
#else
	.string "Uh-oh! It's a crisis!\n"
	.string "I can't be wasting time!$"
#endif

PetalburgWoods_Text_YoureLoadedWithItems:
#if GERMAN
	.string "Du bist mit Items überfrachtet.\n"
	.string "Ich kann dir den Superball nicht geben.$"
#else
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"
#endif

PetalburgWoods_Text_GoBugPokemonTeam:
#if GERMAN
	.string "Ich habe eine Menge Pokémon gefangen!\p"
	.string "Los, los, los!\n"
	.string "Mein Käfer-Pokémon-Team!$"
#else
	.string "I caught a whole bunch of POKéMON!\p"
	.string "Go, go, go!\n"
	.string "My BUG POKéMON team!$"
#endif

PetalburgWoods_Text_ICouldntWin:
#if GERMAN
	.string "Ich habe all diese Pokémon, aber ich\n"
	.string "konnte doch nicht gewinnen…$"
#else
	.string "I have all these POKéMON,\n"
	.string "but I couldn't win…$"
#endif

PetalburgWoods_Text_ImOutOfPokeBalls:
#if GERMAN
	.string "Ich habe eine Menge Pokémon gefangen.\n"
	.string "Nun habe ich keine Pokébälle mehr.$"
#else
	.string "I caught a bunch of POKéMON.\n"
	.string "Now I'm out of POKé BALLS.$"
#endif

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
#if GERMAN
	.string "Wenn du ein Käfer-Pokémon mit zur\n"
	.string "Schule bringst, bist du sofort beliebt.$"
#else
	.string "If you take BUG POKéMON to school,\n"
	.string "you get to be instantly popular!$"
#endif

PetalburgWoods_Text_CantBePopularIfILose:
#if GERMAN
	.string "Wenn ich verliere, kann ich nicht\n"
	.string "beliebt werden.$"
#else
	.string "I can't be popular if I lose.$"
#endif

PetalburgWoods_Text_PeopleRespectYou:
#if GERMAN
	.string "Hast du ein großes Käfer-Pokémon,\n"
	.string "werden die Leute dich respektieren.$"
#else
	.string "If you have a big BUG POKéMON,\n"
	.string "people respect you for it.$"
#endif

PetalburgWoods_Text_IWantRematch1:
#if GERMAN
	.string "Ich möchte wieder kämpfen, wenn meine\n"
	.string "Käfer-Pokémon stärker geworden sind.\p"
	.string "Ich trage dich in meinen PokéCom ein.$"
#else
	.string "I want a rematch when my BUG\n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéGEAR!$"
#endif

PetalburgWoods_Text_IWantRematch2:
#if GERMAN
	.string "Ich möchte wieder kämpfen, wenn meine\n"
	.string "Käfer-Pokémon stärker geworden sind.\p"
	.string "Ich trage dich in meinen PokéCom ein.$"
#else
	.string "I want a rematch when my BUG \n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéGEAR!$"
#endif

PetalburgWoods_Text_MyPokemonHaveGrown:
#if GERMAN
	.string "Meine Käfer-Pokémon sind gewachsen.\n"
	.string "Ich werde wieder beliebt sein.$"
#else
	.string "My BUG POKéMON have grown.\n"
	.string "I'll be popular again.$"
#endif

PetalburgWoods_Text_CantBePopularIfLose:
#if GERMAN
	.string "Ich werde nie beliebt, wenn ich\n"
	.string "immer verliere.$"
#else
	.string "I can't be popular if I lose.$"
#endif

PetalburgWoods_Text_IveBeenTrainingHard:
#if GERMAN
	.string "Du wirst beliebt, wenn du starke\n"
	.string "Pokémon besitzt, oder?\l"
	.string "Daher trainiere ich bis zum Umfallen.$"
#else
	.string "You get to be popular if you have\n"
	.string "strong POKéMON, right?\l"
	.string "So, I've been training hard.$"
#endif

PetalburgWoods_Text_StayOutOfTallGrass:
#if GERMAN
	.string "Hey, du!\p"
	.string "Hör mal - wenn der Wind durch die\n"
	.string "Wipfel geht, klingt der ganze Wald wie\l"
	.string "ein einziges Pokémon.\p"
	.string "Ich könnte hier stundenlang stehen.$"
#else
	.string "Yo, there!\p"
	.string "Listen - when the wind moves through\n"
	.string "the treetops, the whole forest sounds\l"
	.string "like one big POKéMON.\p"
	.string "I could stand here for hours.$"
#endif

PetalburgWoods_Text_HiddenItemsExplanation:
#if GERMAN
	.string "Manchmal liegen auf dem Boden Dinge,\n"
	.string "die einem auf Anhieb gar nicht\l"
	.string "auffallen.\p"
	.string "Daher schaue ich mich bei jedem\n"
	.string "Schritt sorgfältig um.$"
#else
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"
#endif

PetalburgWoods_Text_TryUsingThisItem:
#if GERMAN
	.string "Oh, hübsch! Das ist der Orden\n"
	.string "der Arena in Metarost City!\p"
	.string "Du siehst wie ein Trainer aus. Dann\n"
	.string "musst du dieses Item ausprobieren.$"
#else
	.string "Oh, neat!\n"
	.string "That's the BADGE from RUSTBORO GYM!\p"
	.string "You must be a TRAINER.\n"
	.string "You should try using this item.$"
#endif

PetalburgWoods_Text_MiracleSeedExplanation:
#if GERMAN
	.string "Das ist Wundersaat.\n"
	.string "Wenn ein Pokémon sie trägt, werden die\l"
	.string "Pflanzen-Attacken stärker.\p"
	.string "Neben der Wundersaat gibt es bestimmt\n"
	.string "noch andere nützliche Items, die von\l"
	.string "Pokémon getragen werden können.$"
#else
	.string "It's a MIRACLE SEED.\n"
	.string "If a POKéMON holds that item, its\l"
	.string "GRASS-type moves become stronger.\p"
	.string "Besides MIRACLE SEED, I think there are\n"
	.string "other convenient items for POKéMON\l"
	.string "to hold.$"
#endif

PetalburgWoods_Text_TrainerTipsExperience:
#if GERMAN
	.string "“Blütenburgwald\p"
	.string "Wer hier den Weg verliert, findet ihn\n"
	.string "erst im Frühling wieder.”$"
#else
	.string "“PETALBURG WOODS\p"
	.string "Lose your way in here and you will\n"
	.string "find it again come spring.”$"
#endif

PetalburgWoods_Text_TrainerTipsPP:
#if GERMAN
	.string "“Hier entlang nach Metarost City.”$"
#else
	.string "“This way to RUSTBORO CITY.”$"
#endif

