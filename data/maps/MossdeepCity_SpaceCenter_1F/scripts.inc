MossdeepCity_SpaceCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_1F_OnTransition:
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SAILOR, 1, 9
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_WOMAN, 0, 8
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_OLD_MAN, 1, 6
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SCIENTIST_1, 3, 4
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 12, 2
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 13, 3
	end

@ Functionally unused. See comment on MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 14, 2
	end

MossdeepCity_SpaceCenter_1F_OnLoad:
	goto_if_le VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
	end

MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote::
	setmetatile 2, 5, METATILE_Facility_DataPad, TRUE
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber::
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma::
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma::
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_IS_HOENN_CHAMPION, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_IS_HOENN_CHAMPION, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Steven::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote::
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	copyobjectxytoperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT
	switch VAR_FACING
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
#ifdef BUGFIX
	case DIR_EAST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#else
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#endif
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated::
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest::
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
	release
	end

@ Functionally unused by mistake. The movement is handled anyway after the switch (see above)
@ This also means VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE can never be 3
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast::
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
	release
	end

MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

@ Functionally unused. See above
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

@ This was meant to only handle the player facing North, but by mistake(?) it also handles the player facing East
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent:
#if GERMAN
	.string "Die Rakete wird in Kürze starten.$"
#else
	.string "The rocket's launch is imminent!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber:
#if GERMAN
	.string "Die Rakete ist sicher gestartet!\n"
	.string "Das war der erfolgreiche Start Nr.\l"
	.string "{STR_VAR_1}!$"
#else
	.string "The rocket launched safely!\n"
	.string "That's successful launch no. {STR_VAR_1}!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent:
#if GERMAN
	.string "Hier sieht alles etwas marode aus,\n"
	.string "aber…\p"
	.string "Die Rakete wird in Kürze starten!$"
#else
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket's launch is imminent!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber:
#if GERMAN
	.string "Hier sieht alles etwas marode aus,\n"
	.string "trotzdem…\p"
	.string "Die Rakete ist sicher gestartet!\n"
	.string "Das war der erfolgreiche Start Nr.\l"
	.string "{STR_VAR_1}!$"
#else
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket launched safely!\n"
	.string "That's successful launch no. {STR_VAR_1}!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection:
#if GERMAN
	.string "Jeder Raketenstart verlangt\n"
	.string "sorgfältige Vorbereitungen. Die\l"
	.string "Fehler-\l"
	.string "quote darf nicht einmal 1 % betragen.\p"
	.string "Selbst wenn 99 % perfekt sind, kann 1\n"
	.string "% schon für ein Misslingen sorgen.\p"
	.string "Trotzdem versuchen wir es immer wieder.\n"
	.string "Warum? Weil es ein ewiger Traum ist.$"
#else
	.string "A rocket launch demands perfection.\n"
	.string "Not even a 1% margin of error is allowed.\p"
	.string "Even if it's 99% okay, the whole thing\n"
	.string "is useless if 1% happens to be no good.\p"
	.string "Despite that, we never stop trying.\n"
	.string "Why? It's a dream that never ends.$"
#endif

MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter:
#if GERMAN
	.string "Die Gauner von Magma haben unser\n"
	.string "Raumfahrtzentrum im Visier.\p"
	.string "Aber wir können es niemandem erlauben,\n"
	.string "den Raktenstart zu gefährden!$"
#else
	.string "Those MAGMA thugs have their sights\n"
	.string "set on our SPACE CENTER.\p"
	.string "But we can't allow anything that minor\n"
	.string "to interfere with our rocket launch!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt:
#if GERMAN
	.string "Ich schlenderte am Strand entlang, da\n"
	.string "habe ich dieses hier gefunden.\p"
	.string "Ich kann damit nichts anfangen, daher\n"
	.string "kannst du es haben.$"
#else
	.string "I was taking a stroll down the beach\n"
	.string "when I found this.\p"
	.string "It's not anything I need, so you can\n"
	.string "have it.$"
#endif

MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers:
#if GERMAN
	.string "Die Hoenn-Region ist bekannt für die\n"
	.string "Häufigkeit der Meteoriteneinschläge.$"
#else
	.string "The HOENN region has been famous for \n"
	.string "its meteor showers for a long time.$"
#endif

MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis:
#if GERMAN
	.string "Team Magma darf den Raketentreibstoff\n"
	.string "nicht in die Finger bekommen!\p"
	.string "Übrigens: Möchtest du diesen Stein\n"
	.string "haben? Den habe ich am Strand\l"
	.string "gefunden.$"
#else
	.string "TEAM MAGMA can't be allowed to steal\n"
	.string "the rocket fuel.\p"
	.string "Oh, by the way, you can have this stone\n"
	.string "I found on the beach.$"
#endif

MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma:
#if GERMAN
	.string "Wenn Team Magma in der Nähe ist, sind\n"
	.string "Spaziergänge am Strand bestimmt\l"
	.string "gefährlich.$"
#else
	.string "With TEAM MAGMA around, I guess\n"
	.string "strolls on the beach aren't safe.$"
#endif

MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace:
#if GERMAN
	.string "Einige Menschen nehmen an, dass die\n"
	.string "Pokémon aus dem Weltall kommen. Ob das\l"
	.string "stimmt?$"
#else
	.string "Some people claim that POKéMON came\n"
	.string "from space. Could it be true?$"
#endif

MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma:
#if GERMAN
	.string "Team Aqua sollte sich um Team Magma\n"
	.string "kümmern!\p"
	.string "Aber wenn sie das machen, dann haben\n"
	.string "wir hinterher ein Problem mit Team Aqua.$"
#else
	.string "TEAM AQUA should take care of\n"
	.string "TEAM MAGMA!\p"
	.string "But if they did that, TEAM AQUA will\n"
	.string "become bold and brazen, won't they?$"
#endif

MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind:
#if GERMAN
	.string "Ein gigantischer Brocken Metall durch-\n"
	.string "bricht den Himmel und fliegt ins All…\p"
	.string "Das übersteigt jede Vorstellungskraft.$"
#else
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "It boggles my mind!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream:
#if GERMAN
	.string "Ein gigantischer Brocken Metall durch-\n"
	.string "bricht den Himmel und fliegt ins All…\p"
	.string "Aber Team Magma will meinen Traum\n"
	.string "vernichten!\p"
	.string "Ich versteh das nicht.$"
#else
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "But TEAM MAGMA wants to spoil\n"
	.string "that dream of mine!\p"
	.string "I'm not having any of that!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel:
#if GERMAN
	.string "Troy: Hast du die Bekanntmachung schon\n"
	.string "gelesen, {PLAYER}{KUN}?\p"
	.string "Team Magma will sich den Raketentreib-\n"
	.string "stoff unter den Nagel reißen.\p"
	.string "Ich weiß zwar nicht, wofür sie ihn\n"
	.string "brauchen, aber das können wir ihnen\l"
	.string "nicht erlauben.\p"
	.string "Ich werde das Ganze hier noch eine\n"
	.string "Weile beobachten.\p"
	.string "Warum schaust du dich nicht in der\n"
	.string "Zwischenzeit ein wenig im Ort um?$"
#else
	.string "STEVEN: {PLAYER}{KUN}, have you read that\n"
	.string "proclamation already?\p"
	.string "TEAM MAGMA is coming after the rocket\n"
	.string "fuel on this island.\p"
	.string "I don't know what they'd need it for,\n"
	.string "but they can't be allowed to take it.\p"
	.string "I'll keep an eye on things for\n"
	.string "a while longer.\p"
	.string "In the meantime, why don't you go\n"
	.string "check out the town?$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro:
#if GERMAN
	.string "Wie angekündigt wollen wir den\n"
	.string "Raketentreibstoff haben!$"
#else
	.string "As promised, we've come for\n"
	.string "the rocket fuel!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat:
#if GERMAN
	.string "Kein Treibstoff mehr…$"
#else
	.string "Ran out of fuel…$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle:
#if GERMAN
	.string "Heb bloß nicht ab, nur weil du mich\n"
	.string "besiegt hast!$"
#else
	.string "Don't think you're on a roll just\n"
	.string "because you've beaten me!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro:
#if GERMAN
	.string "Wir warnen dich offen und ehrlich!\n"
	.string "Wir sind nicht hinterhältig!$"
#else
	.string "We gave you fair warning!\n"
	.string "There's nothing sneaky about us!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat:
#if GERMAN
	.string "Grrr…\n"
	.string "Wir sollten doch heimtückischer sein…$"
#else
	.string "Grrr…\n"
	.string "We should've used sneaky treachery…$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle:
#if GERMAN
	.string "Okay, ich habe dazugelernt. Nächstes\n"
	.string "Mal werden wir uns nicht vorher\l"
	.string "ankündigen.$"
#else
	.string "Okay, I get it already! The next time,\n"
	.string "we'll come unannounced.$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro:
#if GERMAN
	.string "Wir sind hinter dem Raketentreibstoff\n"
	.string "her, welcher im Raumfahrtzentrum\l"
	.string "gelagert wird.$"
#else
	.string "The rocket fuel the SPACE CENTER has\n"
	.string "in storage--that's what we're after.\p"
	.string "We mean to take every last bit of it!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat:
#if GERMAN
	.string "Bitte, kannst du mir etwas Treibstoff\n"
	.string "geben? Das kleinste Tröpfchen würde\l"
	.string "schon reichen.$"
#else
	.string "Please, can you spare some fuel?\n"
	.string "Even a chintzy cup will do!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle:
#if GERMAN
	.string "Was wir mit dem Raketentreibstoff\n"
	.string "vorhaben?\p"
	.string "Woher soll ich das wissen?!?\n"
	.string "Geh die Treppe hoch und frag unseren\l"
	.string "Boss.$"
#else
	.string "What are we going to do with\n"
	.string "the rocket fuel?\p"
	.string "How would I know?\n"
	.string "Ask our leader upstairs!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro:
#if GERMAN
	.string "Unser Boss hat mich angewiesen,\n"
	.string "absolut niemanden durchzulassen!$"
#else
	.string "Our leader said no one, but no one,\n"
	.string "gets past me!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat:
#if GERMAN
	.string "Ack! Ack! Aaaargh!$"
#else
	.string "Ack! Ack! Aaack!$"
#endif

MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle:
#if GERMAN
	.string "Bitte, sag unserem Boss, dass ich\n"
	.string "meinen Posten niemals verlassen habe!\p"
	.string "Ich habe ihn bis zum bitteren Ende\n"
	.string "gehalten…$"
#else
	.string "Please, tell our leader that\n"
	.string "I never abandoned my post.\l"
	.string "That I stayed to the bitter end…$"
#endif

MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice:
#if GERMAN
	.string "Das ist…\n"
	.string "Eine Ankündigung eines Diebstahls?!?\p"
	.string "“An die Belegschaft des\n"
	.string "Raumfahrtzentrums\p"
	.string "Wie geht es euch? Wir hoffen, gut.\n"
	.string "Schon bald werden wir euch einen Besuch\p"
	.string "abstatten, um euren Raketentreibstoff\n"
	.string "zu stehlen.\p"
	.string "Bitte versucht nicht, uns aufzuhalten.\n"
	.string "Wir nehmen den Treibstoff auf jeden\l"
	.string "Fall mit! Egal, was ihr unternehmt.\p"
	.string "Auf dass die Landmassen wachsen!\p"
	.string "Team Magma”$"
#else
	.string "This is…\n"
	.string "An intent-to-steal notice?\p"
	.string "“To the staff of the SPACE CENTER:\n"
	.string "How are you? We are doing fine.\p"
	.string "“We will soon visit you to take your\n"
	.string "rocket fuel.\p"
	.string "“Please don't try to stop us.\n"
	.string "We will take the fuel no matter what.\p"
	.string "“Let there be more land!\n"
	.string "                                          TEAM MAGMA”$"
#endif
