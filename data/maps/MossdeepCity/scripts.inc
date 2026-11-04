MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
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

MossdeepCity_Movement_ScottExitEast:
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
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
#if GERMAN
	.string "Ich habe das von Troy bekommen, weiß\n"
	.string "aber nicht, was ich damit machen soll.\p"
	.string "Ich glaube, es heißt King-Stein.\n"
	.string "Möchtest du das haben?$"
#else
	.string "I got this from STEVEN, but I don't\n"
	.string "know what it's good for.\p"
	.string "I think it's called KING'S ROCK.\n"
	.string "Do you want it?$"
#endif

MossdeepCity_Text_YouCanKeepIt:
#if GERMAN
	.string "Warum willst du das haben?\n"
	.string "Du bist komisch.\p"
	.string "Du kannst es behalten, aber erzähle\n"
	.string "es nicht Troy.$"
#else
	.string "Why would you want it?\n"
	.string "You're weird.\p"
	.string "You can keep it, but keep it a secret\n"
	.string "from STEVEN.$"
#endif

MossdeepCity_Text_StevensHouseOverThere:
#if GERMAN
	.string "Troys Haus befindet sich gleich\n"
	.string "dort drüben.$"
#else
	.string "STEVEN's house is right over there!$"
#endif

MossdeepCity_Text_WhatToDoWithWeirdRock:
#if GERMAN
	.string "Ach, du denkst das auch! Was soll man\n"
	.string "auch mit komischen Steinen anfangen?$"
#else
	.string "Yeah, you think so, too! What are you\n"
	.string "supposed to do with some weird rock?$"
#endif

MossdeepCity_Text_WailmerWatching:
#if GERMAN
	.string "In der Nähe von Moosbach City\n"
	.string "kann man wilde Wailmer sehen.\p"
	.string "Das nennt man, äh…\n"
	.string "Nennt man… äh… ähm…\p"
	.string "WAI…, WAI…, WAI…\p"
	.string "Wailmer Watching!$"
#else
	.string "Around MOSSDEEP, you can see wild\n"
	.string "WAILMER.\p"
	.string "It's called, uh…\n"
	.string "What was it now…\p"
	.string "WAI, WAI, WAI…\p"
	.string "WAILMER watching!$"
#endif

MossdeepCity_Text_SpaceCenterReceivedLetter:
#if GERMAN
	.string "Am Raumfahrtzentrum auf der Insel\n"
	.string "werden große Raketen gestartet.\p"
	.string "Dort ist vor kurzem ein Brief ange-\n"
	.string "kommen, der für Aufregung sorgte.$"
#else
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.\p"
	.string "There's been some kind of an uproar\n"
	.string "over a letter they received recently.$"
#endif

MossdeepCity_Text_SpaceCenterLaunchingRockets:
#if GERMAN
	.string "Am Raumfahrtzentrum auf der Insel\n"
	.string "werden große Raketen gestartet.$"
#else
	.string "The island's SPACE CENTER has been\n"
	.string "launching huge rockets.$"
#endif

MossdeepCity_Text_MossdeepTargetedByMagma:
#if GERMAN
	.string "Ich habe von einem Freund, einem\n"
	.string "Matrosen, gehört, dass Team Aqua sich\p"
	.string "in Seegrasulb City aufgehalten\p"
	.string "haben soll.\p"
	.string "Aber dann ist jemand gekommen und hat\n"
	.string "sie aufgemischt.\p"
	.string "Und in Moosbach City ist Team\n"
	.string "Magma.\p"
	.string "Wenn du wissen willst, was sie vorhaben,\n"
	.string "dann geh zum Raumfahrtzentrum.$"
#else
	.string "I heard from a SAILOR buddy that\n"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
	.string "I also heard that someone came along\n"
	.string "and wiped the floor with them!\p"
	.string "But MOSSDEEP here's been targeted\n"
	.string "by that TEAM MAGMA.\p"
	.string "If you want to know what they're up to,\n"
	.string "go visit the SPACE CENTER.$"
#endif

MossdeepCity_Text_FeelReliefOnLand:
#if GERMAN
	.string "Ich bin ein Matrose, daher ist das\n"
	.string "Meer sehr wichtig für mich.\p"
	.string "Aber weißt du, was? Wenn ich nach einer\n"
	.string "langen Seefahrt wieder festen Boden\p"
	.string "unter den Füßen habe, bin ich jedes\n"
	.string "Mal erleichtert.$"
#else
	.string "I'm a SAILOR, so the sea's obviously\n"
	.string "more important to me.\p"
	.string "But you know? When I get back on land\n"
	.string "after a long voyage, I do feel relief!$"
#endif

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
#if GERMAN
	.string "Wäre das nicht schön?\p"
	.string "Wenn die ganze Welt so mit Blumen und\n"
	.string "Pflanzen bewachsen wäre wie diese\l"
	.string "Insel?$"
#else
	.string "Wouldn't it be nice?\p"
	.string "If the whole world was covered in\n"
	.string "plants and flowers like this island?$"
#endif

MossdeepCity_Text_LifeNeedsSeaToLive:
#if GERMAN
	.string "Alle Lebewesen brauchen das Meer, um\n"
	.string "leben zu können, auch wenn sie an Land\l"
	.string "leben.\p"
	.string "Am Ende ihrer Reise wird aus den\n"
	.string "Lebewesen Erde und sie kehren zurück\l"
	.string "zum Land.\p"
	.string "Und das Meer steht immer in Verbindung\n"
	.string "zum Land.\p"
	.string "Genau wie dieses Ufer hier.$"
#else
	.string "All life needs the sea to live, even\n"
	.string "though it makes its home on the land.\p"
	.string "Life, having run its course, becomes\n"
	.string "soil and returns to the land.\p"
	.string "And the sea is always connected to\n"
	.string "the land.\p"
	.string "Yes, like the very shoreline here.$"
#endif

MossdeepCity_Text_SurfExhilarating:
#if GERMAN
	.string "Eine Reise auf einem Schiff ist toll.\p"
	.string "Aber das Meer auf einem Pokémon zu\n"
	.string "überqueren, das Surfer einsetzt…\p"
	.string "Das ist wirklich eine aufregende\n"
	.string "Sache. Meinst du nicht auch, Kindchen?$"
#else
	.string "A voyage on a ship is fine.\p"
	.string "But crossing the sea with POKéMON\n"
	.string "using SURF…\p"
	.string "Now that's an exhilarating trip!\n"
	.string "Wouldn't you agree, youngster?$"
#endif

MossdeepCity_Text_SpecialSpaceCenterRock:
#if GERMAN
	.string "Dieser Felsen hat eine ganz besondere\n"
	.string "Bedeutung für das Raumfahrtzentrum.\p"
	.string "Sie haben ihn hier hingesetzt als\n"
	.string "Glücksbringer für den sicheren Flug der\l"
	.string "Raketen.\p"
	.string "Wenn du dir etwas wünschst, was machst\n"
	.string "du dann? Sternschnuppen beobachten?\p"
	.string "Ich benutze ein Wunschkärtchen.\n"
	.string "Genau das mache ich.$"
#else
	.string "This rock has a special meaning to\n"
	.string "the people at the SPACE CENTER.\p"
	.string "They put it here as their wish for\n"
	.string "their rockets to fly safely.\p"
	.string "When you make a wish, what do you use?\n"
	.string "Do you wish upon a star?\p"
	.string "I use a wish tag to make it happen.\n"
	.string "That's what I do.$"
#endif

MossdeepCity_Text_ItsAWhiteRock:
#if GERMAN
	.string "Ein weißer Felsen.$"
#else
	.string "It's a white rock.$"
#endif

MossdeepCity_Text_GymSign:
#if GERMAN
	.string "Pokémon Arena von Moosbach City \n"
	.string "Leiter: Svenja & Ben\p"
	.string "“Die mystische Kombination!”$"
#else
	.string "MOSSDEEP CITY POKéMON GYM\n"
	.string "LEADERS: LIZA & TATE\p"
	.string "“The mystic combination!”$"
#endif

MossdeepCity_Text_CitySign:
#if GERMAN
	.string "Moosbach City\n"
	.string "“Unser Motto: Liebe Pokémon!”$"
#else
	.string "MOSSDEEP CITY\n"
	.string "“Our slogan: Cherish POKéMON!”$"
#endif

MossdeepCity_Text_SpaceCenterSign:
#if GERMAN
	.string "Moosbach City Raumfahrtzentrum\n"
	.string "“Der letzte Ort vor dem All.”$"
#else
	.string "MOSSDEEP SPACE CENTER\n"
	.string "“The closest place to space.”$"
#endif

MossdeepCity_Text_ScottSomethingWrongWithTown:
#if GERMAN
	.string "Scott: Geht es dir gut, {PLAYER}{KUN}?\n"
	.string "Mir geht es fantastisch!\p"
	.string "Ich habe mir sagen lassen, dass die\n"
	.string "Arenaleiter von Moosbach City sehr\l"
	.string "stark sein sollen.\p"
	.string "Davon musste ich mich einfach selbst\n"
	.string "überzeugen.\p"
	.string "Aber in dieser Stadt geht irgendetwas\n"
	.string "Merkwürdiges vor.\p"
	.string "Die Leute reden über einen Brief mit\n"
	.string "einer Warnung und dem\l"
	.string "Raumfahrtzentrum…\p"
	.string "Aber ich glaube nicht, dass mich das\n"
	.string "etwas angeht.$"
#else
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
	.string "I'm doing great!\p"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
	.string "pretty strong, so I decided to come\l"
	.string "take a look-see for myself.\p"
	.string "But there's something wrong about\n"
	.string "this town.\p"
	.string "People are going on about a warning\n"
	.string "letter and the SPACE CENTER…\p"
	.string "I don't think it concerns me in any\n"
	.string "way, though.$"
#endif

MossdeepCity_Text_SootopolisNewGymLeader:
#if GERMAN
	.string "Ahh… Ein großartiges Gefühl, wenn\n"
	.string "die Wellen über meine Füße spülen…\p"
	.string "Apropos Wellen. Kennst du die Stadt\n"
	.string "Xeneroville?\p"
	.string "Ich glaube, die Arena dort hat einen\n"
	.string "neuen Leiter.\p"
	.string "Das soll der frühere Mentor von\n"
	.string "Wassili sein.$"
#else
	.string "Ahh… It feels great letting the waves\n"
	.string "wash over my feet…\p"
	.string "Speaking of the waves, you know that\n"
	.string "island city SOOTOPOLIS?\p"
	.string "I think the GYM there had a new\n"
	.string "LEADER come in.\p"
	.string "People tell me the new LEADER once\n"
	.string "mentored WALLACE.$"
#endif

