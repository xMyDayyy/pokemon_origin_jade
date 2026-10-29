Route103_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	end

Route103_OnLoad:
	call_if_set FLAG_IS_HOENN_CHAMPION, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave::
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	return

Route103_EventScript_Rival::
	lockall
#if defined(POKEMON_HNS)
	goto Route103_EventScript_RivalMayHns
#endif
#if IS_HNS
	goto Route103_EventScript_RivalMay
#else
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
#endif
	end

#if defined(POKEMON_HNS)
Route103_EventScript_RivalMayHns::
	msgbox Route103_Text_MayHnsMusing, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayHnsLetsBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayHnsDefeated
	msgbox Route103_Text_MayHnsAfterBattle, MSGBOX_DEFAULT
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	goto Route103_EventScript_RivalExitHns
	end

Route103_EventScript_RivalExitHns::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitHnsFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitHnsFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitHnsFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitHnsFacingEastOrWest
	end

Route103_EventScript_RivalExitHnsFacingNorth::
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEndHns
	end

Route103_EventScript_RivalExitHnsFacingEastOrWest::
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEndHns
	end

Route103_EventScript_RivalExitHnsFacingSouth::
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEndHns
	end

Route103_EventScript_RivalEndHns::
	removeobject LOCALID_ROUTE103_RIVAL
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_Text_MayHnsMusing:
#if GERMAN
	.string "Maike: Mal sehen…\n"
	.string "Hier oben müssten doch ein paar starke\l"
	.string "Pokémon zu finden sein…$"
#else
	.string "MAY: Let's see…\n"
	.string "There should be some strong\l"
	.string "POKéMON around here…$"
#endif

Route103_Text_MayHnsLetsBattle:
#if GERMAN
	.string "Ah, du musst {PLAYER} sein!\p"
	.string "Mein Vater sagt, du seist Champion in\n"
	.string "deiner Heimat.\p"
	.string "Ich bin Maike, seine Tochter.\p"
	.string "Lass uns kämpfen - ich will wissen, wie\n"
	.string "gut du bist!$"
#else
	.string "Ah, you must be {PLAYER}!\p"
	.string "My father says you are the CHAMPION\n"
	.string "back home.\p"
	.string "I'm MAY, his daughter.\p"
	.string "Let's battle - I want to see how good\n"
	.string "you are!$"
#endif

Route103_Text_MayHnsDefeated:
#if GERMAN
	.string "Wow… Das war wohl eine Nummer zu groß\n"
	.string "für mich!$"
#else
	.string "Wow… I guess that was a\n"
	.string "little out of my league!$"
#endif

Route103_Text_MayHnsAfterBattle:
#if GERMAN
	.string "Maike: Verloren! Aber jetzt weiß ich,\n"
	.string "wo ich stehe.\p"
	.string "Du bist ab jetzt meine Messlatte.\p"
	.string "Jedes Mal, wenn wir uns wiedersehen,\n"
	.string "fordere ich dich heraus - und beim\l"
	.string "nächsten Mal komme ich näher ran.\p"
	.string "Das nehme ich mir fest vor!\p"
	.string "Warte, ich trage mich in deinem PokéCom\n"
	.string "ein - dann findest du mich jederzeit!\p"
	.string "Ich gehe zurück ins Labor.\n"
	.string "Bis bald, {PLAYER}!$"
#else
	.string "MAY: I lost! But now I know where\n"
	.string "I stand.\p"
	.string "From now on you're my benchmark.\p"
	.string "Every time we meet I will challenge\n"
	.string "you - and next time I will get\l"
	.string "closer.\p"
	.string "That's a promise to myself!\p"
	.string "Wait, I'll put myself in your POKéCOM\n"
	.string "- then you can find me any time!\p"
	.string "I'm heading back to the LAB.\n"
	.string "See you soon, {PLAYER}!$"
#endif
#endif

Route103_EventScript_RivalMay::
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
#if IS_HNS
	@ May always has Torchic (the Treecko set).
	goto Route103_EventScript_StartMayBattleTreecko
#endif
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTreecko
	case 1, Route103_EventScript_StartMayBattleTorchic
	case 2, Route103_EventScript_StartMayBattleMudkip
	end

Route103_EventScript_RivalBrendan::
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTreecko
	case 1, Route103_EventScript_StartBrendanBattleTorchic
	case 2, Route103_EventScript_StartBrendanBattleMudkip
	end

Route103_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_AfterMayBattle::
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterBrendanBattle::
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_RivalExit::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth::
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest::
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth::
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd::
	removeobject LOCALID_ROUTE103_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_Movement_RivalExitFacingNorth1:
	walk_left
	walk_down
	step_end

Route103_Movement_RivalExitFacingNorth2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth:
	delay_16
	delay_4
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

Route103_Movement_RivalExit1:
	walk_down
	step_end

Route103_Movement_RivalExit2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest:
	delay_16
	walk_in_place_faster_down
	step_end

Route103_EventScript_Boy::
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man::
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign::
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel::
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch::
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos::
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete::
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle::
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_Text_MayRoute103Pokemon:
#if GERMAN
	.string "Maike: Mal seh’n… Das Pokémon von\n"
	.string "Route 103 besitzt…$"
#else
	.string "MAY: Let's see… The POKéMON found\n"
	.string "on ROUTE 103 include…$"
#endif

Route103_Text_MayLetsBattle:
#if GERMAN
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "… Oh… Ich seh schon. Mein Vater hat\n"
	.string "dir ein Pokémon geschenkt.\p"
	.string "Wenn wir schon mal hier sind, lass uns\n"
	.string "doch kämpfen!\p"
	.string "Ich gebe dir einen Vorgeschmack auf\n"
	.string "das Leben als Trainer.$"
#else
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a POKéMON as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"
#endif

Route103_Text_MayDefeated:
#if GERMAN
	.string "Wow! Das war spitze!\n"
	.string "{PLAYER}{KUN}, du bist ein\l"
	.string "Naturtalent!$"
#else
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"
#endif

Route103_Text_MayTimeToHeadBack:
#if GERMAN
	.string "Maike: Ich glaube, ich weiß jetzt, warum\n"
	.string "mein Vater dich ausgesucht hat.\p"
	.string "Ich meine, du hast dein Pokémon erst\n"
	.string "sehr kurze Zeit und es mag dich bereits.\p"
	.string "Du wirst es einfach haben, dich mit\n"
	.string "jeder Art von Pokémon anzufreunden.\p"
	.string "Nun wird es aber Zeit, zurück ins\n"
	.string "Labor zu gehen!$"
#else
	.string "MAY: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"
#endif

Route103_Text_BrendanRoute103Pokemon:
#if GERMAN
	.string "Maike: So… Dieses und dieses leben an\n"
	.string "der Route 103…$"
#else
	.string "BRENDAN: Okay, so it's this one and\n"
	.string "that one that live on ROUTE 103…$"
#endif

Route103_Text_BrendanLetsBattle:
#if GERMAN
	.string "Hey, da ist ja {PLAYER}!\p"
	.string "… Oh ja. Mein Vater hat dir ein\n"
	.string "Pokémon geschenkt, nicht wahr?\p"
	.string "Wenn wir schon mal hier sind, lass uns\n"
	.string "doch einen kleinen Kampf austragen.\p"
	.string "Ich bringe dir bei, was ein Trainer\n"
	.string "wissen muss.$"
#else
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"
#endif

Route103_Text_BrendanDefeated:
#if GERMAN
	.string "Hey, {PLAYER}, das war gar nicht so\n"
	.string "übel.$"
#else
	.string "Huh, {PLAYER}, you're not too shabby.$"
#endif

Route103_Text_BrendanTimeToHeadBack:
#if GERMAN
	.string "Maike: Ich denke, ich habe es kapiert.\n"
	.string "Ich weiß jetzt, warum mein Vater dich\l"
	.string "ausgesucht hat.\p"
	.string "Du hast dein Pokémon noch nicht lange,\n"
	.string "und doch mag es dich schon.\p"
	.string "{PLAYER}, ich glaube, du kannst mit\n"
	.string "jedem Pokémon Freundschaft schließen.\l"
	.string "\p"
	.string "Wir sollten nun zurück zum Labor\n"
	.string "gehen.$"
#else
	.string "BRENDAN: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"
#endif

Route103_Text_ShouldHaveBroughtPotion:
#if GERMAN
	.string "Ach, hätte ich doch nur eine\n"
	.string "Surflizenz.\p"
	.string "Dann könnte ich von hier aus über das\n"
	.string "Meer abkürzen.$"
#else
	.string "Ah, if only I had a SURF LICENCE.\p"
	.string "Then I could cut across the sea from\n"
	.string "here.$"
#endif

Route103_Text_ShortcutToOldale:
#if GERMAN
	.string "Wenn du von hier das Meer überquerst,\n"
	.string "nimmst du eine Abkürzung nach\l"
	.string "Rosaltstadt.\p"
	.string "Hahaha, ist das kein praktischer Tipp?$"
#else
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"
#endif

Route103_Text_RouteSign:
#if GERMAN
	.string "Route 103\n"
	.string "{DOWN_ARROW} Rosaltstadt$"
#else
	.string "ROUTE 103\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"
#endif
