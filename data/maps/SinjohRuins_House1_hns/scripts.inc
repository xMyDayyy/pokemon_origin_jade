SinjohRuins_House1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SinjohRuins_Lab_OnFrame
	map_script 	MAP_SCRIPT_ON_TRANSITION, SinjohRuins_Lab_OnTransition
	.byte 0

SinjohRuins_Lab_OnTransition::
	call_if_eq VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_SetupFinalPlateScene
	end

SinjohRuins_Lab_OnFrame::
	map_script_2 VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_FinalPlateScene
	.2byte 0

@==========================Intro Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_TriggerIntroTop::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkDown1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroMid::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroBot::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkUp1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntro::
	turnobject LOCALID_PLAYER, DIR_EAST
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenSitsDown
	delay 10
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerGoesToTable
	delay 40
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkDown
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	waitmovement LOCALID_NEWSINJOH_LAB_LINGUIST
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene3, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene4, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkUp
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
SinjohRuins_Lab_EventScript_IntroChoice::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutsceneRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
	goto SinjohRuins_Lab_EventScript_IntroChoice

SinjohRuins_Lab_EventScript_IntroChoseYes::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SINJOH_STORYLINE, 6
	setvar VAR_NOBLE_SNEASLER, 1
	setvar VAR_NOBLE_OVERQWIL, 1
	setvar VAR_NOBLE_WYRDEER, 1
	setvar VAR_NOBLE_ARCANINE, 1
	setvar VAR_NOBLE_URSALUNA, 1
	setvar VAR_NOBLE_KLEAVOR, 1
	setvar VAR_NOBLE_ELECTRODE, 1
	setvar VAR_NOBLE_TYPHLOSION, 1
	release
	end

SinjohRuins_Lab_Movement_StevenMeetPlayer:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

SinjohRuins_Lab_Movement_StevenSitsDown:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

SinjohRuins_Lab_Movement_PlayerGoesToTable:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	face_left
	step_end

SinjohRuins_Lab_Movement_LinguistWalkDown:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

SinjohRuins_Lab_Movement_LinguistWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end


SinjohRuins_Lab_Text_StevenIntroCutscene1:
   	.string "STEVEN: Hm?$"

SinjohRuins_Lab_Text_StevenIntroCutscene2:
#if GERMAN
	.string "Troy: {PLAYER}!\p"
	.string "Diese Augen würde ich überall\n"
	.string "wiedererkennen.\p"
	.string "Was führt dich so weit in den Norden?\p"
	.string "…………\p"
	.string "Verstehe, die Kimono-Girls von\n"
	.string "Neu-Sinjoh haben dich geschickt, um\l"
	.string "unsere Untersuchung zu unterstützen.\p"
	.string "Dann bringe ich dich mal auf den\n"
	.string "neuesten Stand.$"
#else
	.string "STEVEN: {PLAYER}!\p"
	.string "I'd recognize those eyes anywhere.\p"
	.string "What brings you this far north?\p"
	.string ".............\p"
	.string "I see, the KIMONO GIRLS of NEW SINJOH\n"
	.string "have sent you to aid our\l"
	.string "investigation.\p"
	.string "In that case, allow me to bring you\n"
	.string "up to speed.$"
#endif

SinjohRuins_Lab_Text_StevenIntroCutscene3:
#if GERMAN
	.string "Troy: Als ich zum ersten Mal von diesen\n"
	.string "Ruinen hörte, musste ich sie mit eigenen\l"
	.string "Augen sehen.\p"
	.string "Ich habe ein Team der Devon Corp.\n"
	.string "zusammengestellt und wir sind zu einer\l"
	.string "Forschungsexpedition aufgebrochen.\p"
	.string "Wer weiß, was hier alles begraben\n"
	.string "liegt.\p"
	.string "Einiges haben wir bereits\n"
	.string "herausgefunden.$"
#else
	.string "STEVEN: When I first heard about\n"
	.string "these ruins, I had to come see\l"
	.string "them for myself.\p"
	.string "I assembled a team from DEVON CORP.\n"
	.string "and we set off on a research\l"
	.string "expedition.\p"
	.string "Who knows what we'll find buried\n"
	.string "here.\p"
	.string "We've learned quite a lot\n"
	.string "already.$"
#endif

SinjohRuins_Lab_Text_StevenIntroCutscene4:
#if GERMAN
	.string "Linguist: Die vollständige Übersetzung\n"
	.string "der Schriftzeichen rund um die Ruinen\l"
	.string "entzieht sich mir noch, aber einige\l"
	.string "Aspekte konnte ich entschlüsseln.\p"
	.string "Es gibt 17 besondere Tafeln.\p"
	.string "Sie haben eine Bedeutung für die\n"
	.string "Ruinen, doch wir haben bisher nur eine\l"
	.string "gefunden.\p"
	.string "Die übrigen sollen von Pokémon und\n"
	.string "Trainern mit gewaltigen Kräften\l"
	.string "bewacht werden.$"
#else
	.string "LINGUIST: While the full translation\n"
	.string "of the glyphs found around the ruins\l"
	.string "still eludes me, I've been able\l"
	.string "to make out some aspects.\p"
	.string "There are 17 peculiar PLATES.\p"
	.string "They have some significance\n"
	.string "to the ruins, but we've only\l"
	.string "found 1 so far.\p"
	.string "The rest are said to be guarded\n"
	.string "by POKéMON and trainers of\l"
	.string "awesome power.$"
#endif

SinjohRuins_Lab_Text_StevenIntroCutscene5:
#if GERMAN
	.string "Troy: So weit die Geschichte, {PLAYER}.\p"
	.string "Die Königlichen Pokémon, die die übrigen\n"
	.string "Tafeln bewachen, sind für mein Team\l"
	.string "leider zu stark.\p"
	.string "Und ich muss hierbleiben, um die\n"
	.string "Forschung zu leiten.\p"
	.string "Aber ich glaube, du könntest es\n"
	.string "schaffen. Hilfst du uns?$"
#else
	.string "STEVEN: That's the story, {PLAYER}.\p"
	.string "The NOBLE POKéMON that guard the\n"
	.string "remaining PLATES are too strong\l"
	.string "for my team, I'm afraid.\p"
	.string "And I need to stay here to oversee\n"
	.string "the research.\p"
	.string "But I think you could do it.\n"
	.string "Will you help us?$"
#endif

SinjohRuins_Lab_Text_StevenIntroCutscene6:
#if GERMAN
	.string "Ausgezeichnet.\p"
	.string "Laut den Schriftzeichen befinden sich\n"
	.string "die Tafeln im Besitz Königlicher\l"
	.string "Pokémon und starker Trainer in ganz\l"
	.string "Sinjoh.\p"
	.string "Ich rufe dich auf dem PokéCom an,\n"
	.string "sobald wir Neues erfahren.\p"
	.string "Danke, {PLAYER}.$"
#else
	.string "Excellent.\p"
	.string "The glyphs say the PLATES are\n"
	.string "held by NOBLE POKéMON and\l"
	.string "strong trainers across SINJOH.\p"
	.string "I'll call your POKéGEAR if we\n"
	.string "learn anything new.\p"
	.string "Thank you, {PLAYER}.$"
#endif

SinjohRuins_Lab_Text_StevenIntroCutsceneRefused:
#if GERMAN
	.string "Bist du sicher?\p"
	.string "Wer weiß, was hier alles begraben\n"
	.string "liegt.\p"
	.string "Überlegst du es dir nicht noch\n"
	.string "einmal?$"
#else
	.string "Are you sure?\p"
	.string "Who knows what we'll find buried\n"
	.string "here.\p"
	.string "Won't you reconsider?$"
#endif

@==========================Final plate Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_SetupFinalPlateScene::
	setobjectxyperm LOCALID_SINJOHRUINS_LAB_STEVEN, 4, 7
	setobjectmovementtype LOCALID_SINJOHRUINS_LAB_STEVEN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_NEWSINJOH_LAB_LINGUIST, 5, 7
	setobjectmovementtype LOCALID_NEWSINJOH_LAB_LINGUIST, MOVEMENT_TYPE_FACE_LEFT
	return

SinjohRuins_Lab_FinalPlateScene::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	turnobject LOCALID_SINJOHRUINS_LAB_STEVEN, DIR_SOUTH
	delay 30
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkDown1
	turnobject LOCALID_NEWSINJOH_LAB_LINGUIST, DIR_SOUTH
	delay 30
	msgbox SinjohRuins_Lab_Text_FinalPlateScene1, MSGBOX_DEFAULT
	closemessage
	dofieldeffectsparkle 3, 8, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 3
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	delay 200
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	msgbox SinjohRuins_Lab_Text_FinalPlateScene2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerLeaveLab
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenLeaveLab
	waitmovement 0
	waitmovement 0
	setvar VAR_SINJOH_STORYLINE, 8
	warp MAP_SINJOH_RUINS_HNS, 0
	waitstate
	end

SinjohRuins_Lab_Text_FinalPlateScene1:
#if GERMAN
	.string "Troy: {PLAYER}!\p"
	.string "Ich glaube, ich weiß, was geschehen\n"
	.string "wird, wenn wir alle 17 Tafeln\l"
	.string "zusammenbringen.\p"
	.string "Ich spüre…\n"
	.string "………………$"
#else
	.string "STEVEN: {PLAYER}!\p"
	.string "I think I know what's going to\n"
	.string "happen we bring together all 17 of\l"
	.string "the PLATES.\p"
	.string "I feel...\l"
	.string ".....................$"
#endif

SinjohRuins_Lab_Text_FinalPlateScene2:
#if GERMAN
	.string "Troy: Das muss ich mit eigenen\n"
	.string "Augen sehen!\p"
	.string "Nach draußen, {PLAYER}!$"
#else
	.string "STEVEN: I need to see this for\n"
	.string "myself!\p"
#endif

SinjohRuins_Lab_Movement_PlayerLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

SinjohRuins_Lab_Movement_StevenLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

@==========================NPC SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_Steven::
	lock
	faceplayer
	buffernumberstring STR_VAR_1, VAR_PLATECOUNTER
	goto_if_ge VAR_PLATECOUNTER, 17, SinjohRuins_Lab_EventScript_StevenAfterAllPlates
	goto_if_ge VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_StevenAfter15Plates
	goto_if_ge VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_StevenAfter12Plates
	goto_if_ge VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_StevenAfter9Plates
	goto_if_ge VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_StevenAfter6Plates
	goto_if_ge VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_StevenAfter3Plates
	msgbox SinjohRuins_Lab_Text_StevenFindPlates, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter3Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter6Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter9Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter12Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter15Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfterAllPlates::
	msgbox SinjohRuins_Lab_Text_StevenAfterAll, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_Text_StevenFindPlates:
#if GERMAN
	.string "Troy: Ah, {PLAYER}.\p"
	.string "Schon {STR_VAR_1} Tafeln.\n"
	.string "Gar nicht übel.\p"
	.string "Ich muss zugeben, ich bin gespannt, was\n"
	.string "geschieht, wenn alle beisammen sind.\p"
	.string "Nun, mal sehen, was du noch findest.$"
#else
	.string "STEVEN: Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PLATES so far.\n"
	.string "Not bad at all.\p"
	.string "I have to admit, I'm curious\n"
	.string "what will happen once they're\l"
	.string "all gathered.\p"
	.string "Well, let's see what you find.$"
#endif

SinjohRuins_Lab_Text_StevenFindPlates3:
#if GERMAN
	.string "Troy: Ah, {PLAYER}.\p"
	.string "Schon {STR_VAR_1} Tafeln.\n"
	.string "Gar nicht übel.\p"
	.string "Hast du dir die Kammer schon\n"
	.string "angesehen?\l"
	.string "Das alles ist höchst rätselhaft.$"
#else
	.string "STEVEN: Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PLATES so far.\n"
	.string "Not bad at all.\p"
	.string "Have you investigated that\n"
	.string "chamber yet?\l"
	.string "It's all quite mysterious.$"
#endif

SinjohRuins_Lab_Text_StevenFindPlates9:
#if GERMAN
	.string "Troy: Ah, {PLAYER}.\p"
	.string "Schon {STR_VAR_1} Tafeln.\n"
	.string "Du machst große Fortschritte.\p"
	.string "Die Kammern, die sich geöffnet haben,\n"
	.string "ähneln auffällig einer Reihe von\l"
	.string "Kammern in der Hoenn-Region.\p"
	.string "Auch dort war jede die Heimat eines\n"
	.string "legendären Pokémon.\p"
	.string "Doch in Hoenn wurden überhaupt nur\n"
	.string "3 entdeckt.\p"
	.string "Und hier gibt es mindestens 6.\p"
	.string "Wer weiß, was wir als Nächstes\n"
	.string "finden.$"
#else
	.string "STEVEN: Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PLATES so far.\n"
	.string "Making great progress.\p"
	.string "The chambers that have opened\n"
	.string "up bear a striking similarity\l"
	.string "to a series of chambers\l"
	.string "in the HOENN region.\p"
	.string "Each of those was also home to a\n"
	.string "legendary POKéMON.\p"
	.string "But in HOENN, only 3 were ever\n"
	.string "discovered.\p"
	.string "And here, there are at least 6.\p"
	.string "Who knows what we'll find next.$"
#endif

SinjohRuins_Lab_Text_StevenAfterAll:
#if GERMAN
	.string "Troy: {PLAYER}!\p"
	.string "Diese Expedition war das Erlebnis\n"
	.string "meines Lebens.\p"
	.string "Seit ich von diesen Ruinen gehört\n"
	.string "habe, hatte ich dieses Gefühl.\p"
	.string "Ich dachte, wir würden etwas\n"
	.string "Unglaubliches entdecken.\p"
	.string "Und meine Vorahnungen bewahrheiten\n"
	.string "sich meistens.\p"
	.string "Danke für all deine Hilfe, Champ.\p"
	.string "Wohin wird es dich als Nächstes\n"
	.string "verschlagen?\p"
	.string "Ich hoffe, wir sehen uns irgendwo\n"
	.string "wieder.$"
#else
	.string "STEVEN: {PLAYER}!\p"
	.string "This expedition has been the\n"
	.string "experience of a lifetime.\p"
	.string "Ever since I heard about these ruins,\n"
	.string "I had this feeling.\p"
	.string "I thought we would discover something\n"
	.string "amazing.\p"
	.string "And my predictions usually come true.\p"
	.string "Thank you for all your help,\n"
	.string "Champion.\p"
	.string "Where will you go from here?\p"
	.string "I hope we can meet again somewhere.$"
#endif

SinjohRuins_Lab_EventScript_Geologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_GeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_GeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Geologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_GeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_GeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Geologist:
#if GERMAN
	.string "Das Bodenradar zeigt 6 unterirdische\n"
	.string "Kammern in diesem Tal.\p"
	.string "5 davon scheinen näher an der\n"
	.string "Oberfläche zu liegen, eine ist noch\l"
	.string "tiefer vergraben.$"
#else
    .string "Ground-penetrating radar shows\n"
	.string "6 subterranean chambers in this\l"
	.string "valley.\p"
	.string "5 of them appear to be closer\n"
	.string "to the surface level, with 1\l"
	.string "buried even deeper.$"
#endif
SinjohRuins_Lab_Text_GeologistDuring:
	.string "Die ganze Zeit habe ich meine Geräte\n"
	.string "nach unten gerichtet, um den\l"
	.string "Untergrund abzubilden.\p"
	.string "Dabei hätte ich sie eindeutig nach\n"
	.string "oben richten sollen!$"
SinjohRuins_Lab_Text_GeologistAfter:
#if GERMAN
	.string "Diese Tafeln standen mit dem\n"
	.string "mächtigsten Pokémon in Verbindung??\p"
	.string "Ich wünschte, ich hätte mehr Zeit,\n"
	.string "sie zu erforschen.$"
#else
	.string "Those PLATES were related to the\n"
	.string "most powerful POKéMON??\p"
	.string "I wish I had more time to study them.$"
#endif

SinjohRuins_Lab_EventScript_Linguist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_LinguistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_LinguistDuringEvent
	msgbox SinjohRuins_Lab_Text_Linguist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistDuringEvent::
	msgbox SinjohRuins_Lab_Text_LinguistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistAfterEvent::
	msgbox SinjohRuins_Lab_Text_LinguistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Linguist:
#if GERMAN
	.string "Uff…\n"
	.string "So viele Schriftzeichen zu übersetzen…\p"
	.string "In der Hoenn-Region gibt es nichts\n"
	.string "Vergleichbares.$"
#else
    .string "Ugh....\n"
	.string "There's so many glyphs to\l"
	.string "translate..\p"
	.string "We don't have anything like this\n"
	.string "in the HOENN region.$"
#endif
SinjohRuins_Lab_Text_LinguistDuring:
	.string "Stell dir meine Überraschung vor,\n"
	.string "als ich das Schriftzeichen übersetzt\l"
	.string "habe!\p"
	.string "Ich habe es drei- und vierfach\n"
	.string "geprüft, bevor ich es Troy gesagt\l"
	.string "habe!\p"
	.string "Ich meine, wirklich - der Gott der\n"
	.string "Pokémon?\p"
	.string "Es ist unglaublich.$"
SinjohRuins_Lab_Text_LinguistAfter:
#if GERMAN
	.string "Diese Expedition war eine wahre\n"
	.string "Freude, {PLAYER}.\p"
	.string "Danke, dass du die ganze Feldarbeit\n"
	.string "übernommen hast.$"
#else
    .string "This expedition has been a\n"
	.string "joy, {PLAYER}.\p"
	.string "Thanks for taking care of all\n"
	.string "the field-work.$"
#endif

SinjohRuins_Lab_EventScript_Archaeologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Archaeologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Archaeologist:
#if GERMAN
	.string "Die Existenz einer Zivilisation in\n"
	.string "dieser Gegend verändert unser\l"
	.string "gesamtes Geschichtsverständnis.\p"
	.string "Viele der gefundenen Artefakte sind\n"
	.string "über tausend Jahre alt.\p"
	.string "Die Datierung passt zu Artefakten\n"
	.string "aus der Sinnoh-Region.\p"
	.string "Allerdings… die Flöte, die du gefunden\n"
	.string "hast, scheint weit älter zu sein.$"
#else
	.string "The existence of a civilization\n"
    .string "in this area changes our whole\l"
	.string "understanding of history.\p"
	.string "Many of the artifacts we've found\n"
	.string "are over a thousand years old.\p"
	.string "The carbon dating lines up with\n"
	.string "artifacts found in the SINNOH region.\p"
	.string "Although, that flute you found...\n"
	.string "It seems far older.$"
#endif
SinjohRuins_Lab_Text_ArchaeologistDuring:
	.string "Diese Tafeln…\n"
	.string "Die Verbindung zur Sinnoh-Region…\l"
	.string "Diese Flöte…\l"
	.string "Langsam ergibt alles einen Sinn.$"
SinjohRuins_Lab_Text_ArchaeologistAfter:
#if GERMAN
	.string "Der historische Wert dessen, was du uns\n"
	.string "hier freizulegen geholfen hast, ist gar\l"
	.string "nicht hoch genug einzuschätzen,\l"
	.string "{PLAYER}.\p"
	.string "Wirklich, vielen Dank.$"
#else
	.string "The historical value of what\n"
	.string "you've helped us unearth here\l"
	.string "cannot be overstated, \l"
	.string "{PLAYER}.\p"
	.string "Truly, thank you.$"
#endif

SinjohRuins_Lab_EventScript_Growlithe_Hisui::
    lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, 0
	msgbox SinjohRuins_Lab_Text_Growlithe_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

SinjohRuins_Lab_Text_Growlithe_Cry:
    .string "Growh owh!!$"

SinjohRuins_Lab_EventScript_GrowlithePokeball::
    msgbox SinjohRuins_Lab_Text_GrowlitheBall MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_GrowlitheBall:
#if GERMAN
	.string "Das scheint der Ball von Fukano zu\n"
	.string "sein… Besser nicht anfassen.$"
#else
    .string "This appears to be Growlithe's ball..\n"
	.string "Better leave it alone.$"
#endif

SinjohRuins_Lab_EventScript_Biologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_BiologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_BiologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Biologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_BiologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_BiologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Biologist:
#if GERMAN
	.string "Sieh dir dieses wundervolle Exemplar\n"
	.string "an!\p"
	.string "Diese Fukano-Art gleicht keiner\n"
	.string "anderen auf der ganzen Welt.\p"
	.string "Die DNS-Analyse zeigt, dass sie einen\n"
	.string "gemeinsamen Vorfahren mit den Fukano\l"
	.string "anderer Regionen teilt.\p"
	.string "Doch Wesen und Typ unterscheiden\n"
	.string "sich deutlich.\p"
	.string "Beschreibungen von Fukano in alten\n"
	.string "Sinnoh-Aufzeichnungen scheinen zu\l"
	.string "passen.\p"
	.string "Vielleicht bewohnte diese Art einst ein\n"
	.string "viel größeres Gebiet, das sich\l"
	.string "nordwärts durch das alte Sinnoh\l"
	.string "erstreckte.$"
#else
    .string "Look at this wonderful specimen!\p"
	.string "This species of GROWLITHE is unlike\n"
	.string "those found anywhere else in the\l"
	.string "world.\p"
	.string "DNA analysis reveals that it shares\n"
	.string "a common ancestor with GROWLITHE\l"
	.string "that can be found in other regions.\p"
	.string "Yet, its temperament and typing\n"
	.string "differ significantly.\p"
	.string "Descriptions of GROWLITHE found in\n"
	.string "ancient SINNOH records seem to match.\p"
	.string "Perhaps this species once occupied\n"
	.string "a much larger territory, stretching\l"
	.string "north through ancient SINNOH.$"
#endif
SinjohRuins_Lab_Text_BiologistDuring:
	.string "Wenn das Wesen am oberen Ende der\n"
	.string "Treppe wirklich der Gott aller\l"
	.string "Pokémon ist - heißt das, es ist der\l"
	.string "erste gemeinsame Vorfahre?$"
SinjohRuins_Lab_Text_BiologistAfter:
#if GERMAN
	.string "Auf dieser Expedition konnte ich so\n"
	.string "viele Daten über Regionalformen und\l"
	.string "getrennte Entwicklungslinien sammeln.\l"
	.string "Danke, {PLAYER}.$"
#else
	.string "I've been able to gather so much\n"
	.string "data on regional forms and\l"
	.string "divergent evolution from this\l"
	.string "expedition. Thank you,\l"
	.string "{PLAYER}.$"
#endif

SinjohRuins_Lab_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_HikerDuringAfter
	msgbox SinjohRuins_Lab_Text_Hiker MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_HikerDuringAfter::
	msgbox SinjohRuins_Lab_Text_HikerDuringAfter, MSGBOX_NPC
	end
SinjohRuins_Lab_Text_Hiker:
#if GERMAN
	.string "Seit zehn Jahren durchstreife ich\n"
	.string "diese Wildnis.\p"
	.string "Nein, es sind wohl schon zwanzig.\p"
	.string "Bis ich eines Tages diese großen\n"
	.string "Steinsäulen und den unheimlichen\l"
	.string "Tempel fand.\p"
	.string "Das sind die Sinjoh-Ruinen.\n"
	.string "So nennt man sie jedenfalls.\p"
	.string "Vom Dorf wusste ich damals nichts.\p"
	.string "Ich habe nur ein paar Kumpels davon\n"
	.string "erzählt. Aber so etwas spricht sich\l"
	.string "schnell herum.\p"
	.string "Ich hätte nie gedacht, dass es der\n"
	.string "Gegend so viel Aufmerksamkeit\l"
	.string "beschert.\p"
	.string "Irgendwie ein komisches Gefühl.\n"
	.string "Weißt du?$"
#else
   	.string "For ten years, I've hiked these\n"
	.string "wilds.\p"
	.string "No, make that twenty years.\p"
	.string "Until one day I found those big\n"
	.string "stone pillars and that ominous\l"
	.string "temple.\p"
	.string "That's the SINJOH RUINS.\n"
	.string "Or so I've heard.\p"
	.string "I didn't know about the town then.\p"
	.string "All I did was tell a few of my\n"
	.string "pals. But word travels fast.\p"
	.string "I never thought it would bring\n"
	.string "so much attention to the area.\p"
	.string "Makes me feel kinda funny.\n"
	.string "Y'know?$"
#endif
SinjohRuins_Lab_Text_HikerDuringAfter:
	.string "Sag es niemandem, {PLAYER},\n"
	.string "aber ich habe den Tempel auf dem\l"
	.string "Berggipfel schon gesehen, als ich\l"
	.string "diesen Ort entdeckt habe.\p"
	.string "Ich habe es für mich behalten.\p"
	.string "Ich habe schon genug über diese\n"
	.string "Ruinen ausgeplaudert.\p"
	.string "Immerhin scheint ja alles gut\n"
	.string "ausgegangen zu sein.$"

@ENVIRONMENT
SinjohRuins_Lab_EventScript_Notes1::
	msgbox SinjohRuins_Lab_Text_Note1 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes2::
	msgbox SinjohRuins_Lab_Text_Note2 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes3::
	msgbox SinjohRuins_Lab_Text_Note3 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes4::
	msgbox SinjohRuins_Lab_Text_Note4 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes5::
	msgbox SinjohRuins_Lab_Text_Note5 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes6::
	msgbox SinjohRuins_Lab_Text_Note6 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes7::
	msgbox SinjohRuins_Lab_Text_Note7 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes8::
	msgbox SinjohRuins_Lab_Text_Note8 MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_Note1:
#if GERMAN
	.string "Forschungslog 1: 3. Mai 1975\p"
	.string "Wir haben den Standort der Ruinen\n"
	.string "erreicht.\p"
	.string "Die beißende Kälte des Silberbergs\n"
	.string "ist bis hier unten zu spüren…\p"
	.string "Bald wird das Haupt-Grabungsteam den\n"
	.string "Berg durchbrochen haben…\l"
	.string "Ich kann es kaum erwarten, zu sehen,\l"
	.string "was unter unseren Füßen auf uns\l"
	.string "wartet!$"
#else
    .string "Research Log 1: May 3, 1975\p"
	.string "We've arrived at the location\n"
	.string "of the ruins.\p"
	.string "The harsh cold of Mt.Silver\n"
	.string "can be felt from all the way\l"
	.string "down here...\p"
	.string "Soon the main excavation team\n"
	.string "will make it through the mountain..\l"
	.string "I cannot wait to see what waits for us\l"
	.string "underneath our feet!$"
#endif

SinjohRuins_Lab_Text_Note2:
#if GERMAN
	.string "Forschungslog 2: 10. Mai 1975\p"
	.string "Eine Woche Graben hat rein gar\n"
	.string "nichts gebracht.\p"
	.string "Das Eis hier ist unfassbar dick und der\n"
	.string "Fels zerstört unsere Ausrüstung\l"
	.string "vollständig.\p"
	.string "Nicht einmal Machomei konnte ihm\n"
	.string "etwas anhaben.\p"
	.string "Was ist das für ein Ort?\p"
	.string "Wir müssen es herausfinden.$"
#else
    .string "Research Log 2:  May 10, 1975\p"
	.string "A week of digging has yielded\n"
	.string "no result whatsoever.\p"
	.string "The ice here is impossibly thick,\n"
	.string "and the rock just breaks our\l"
	.string "equipment entirely.\p"
	.string "Not even MACHAMP was able to\n"
	.string "make a dent.\p"
	.string "What is this place?\p"
	.string "We must find out.$"
#endif

SinjohRuins_Lab_Text_Note3:
#if GERMAN
	.string "Forschungslog 3: 14. Mai 1975\p"
	.string "Man kommt im Leben nicht voran, wenn\n"
	.string "man nur herumsteht und nichts tut.\p"
	.string "Ich bin nur ein Arbeiter.\p"
	.string "Aber ich hatte eine Idee, wie wir\n"
	.string "das Eis durchbrechen könnten.\p"
	.string "Oder besser gesagt: durchschmelzen.\p"
	.string "Wir brauchen Feuer-Pokémon, und\n"
	.string "zwar jede Menge.\p"
	.string "Aber wie bekommen wir sie den weiten\n"
	.string "Weg aus Sinnoh hierher?$"
#else
    .string "Research Log 3:  May 14, 1975\p"
	.string "You don't get ahead in life by\n"
	.string "standing by and doing nothing.\p"
	.string "I'm just a worker.\p"
	.string "But I had an idea of how we could\n"
	.string "break through the ice.\p"
	.string "Or rather, melt through it.\p"
	.string "We need FIRE-TYPE POKéMON and\n"
	.string "lots of them.\p"
	.string "But how will we get them here\n"
	.string "all the way from SINNOH?$"
#endif

SinjohRuins_Lab_Text_Note4:
#if GERMAN
	.string "Forschungslog 4: 21. Mai 1975\p"
	.string "Wir waren fleißig.\p"
	.string "Meine Idee, durch das Eis zu kommen, hat\n"
	.string "funktioniert. Nur haben wir die\l"
	.string "Feuer-Pokémon nicht von zu Hause\l"
	.string "geholt.\p"
	.string "Der Chef bestand darauf, sie vor Ort\n"
	.string "zu beschaffen.\p"
	.string "Wir fanden eine heiße Quelle bei\n"
	.string "einem Dorf in der Nähe…\p"
	.string "Und wir nahmen, was wir brauchten…\p"
	.string "Ich bin nicht stolz darauf. Aber\n"
	.string "Fortschritt verlangt manchmal Opfer.\p"
	.string "Nun denn, das Eis ist weg.\p"
	.string "Es gibt 6 Kammern und einen\n"
	.string "versiegelten Tempel in der Mitte.\p"
	.string "Die Architektur des Hauptbauwerks\n"
	.string "deutet auf das alte Celestica-Volk\l"
	.string "hin…\p"
	.string "Unsere Vorfahren. Bevor sie gen\n"
	.string "Norden zogen.\p"
	.string "Der Chef will den Tempel so schnell\n"
	.string "wie möglich offen sehen…$"
#else
    .string "Research Log 4:  May 21, 1975\p"
	.string "We've been busy.\p"
	.string "My idea worked to get us through\n"
	.string "the ice. Only we didn't get the\l"
	.string "FIRE-TYPEs from back home.\p"
	.string "The boss insisted we get them locally.\p"
	.string "We found a hot spring by a nearby\n"
	.string "village....\p"
	.string "And we took what we needed...\p"
	.string "I'm not proud of it. But sacrifices\n"
	.string "are sometimes required for progress.\p"
	.string "So, the ice is gone.\p"
	.string "There are 6 chambers, and a sealed\n"
	.string "temple in the center.\p"
	.string "The architecture of the main \n"
	.string "structure indicates it may be of the\l"
	.string "the ancient Celestica peoples...\p"
	.string "Our ancestors. Before they moved north.\p"
	.string "The boss wants that temple open as\n"
	.string "soon as possible...$"
#endif

SinjohRuins_Lab_Text_Note5:
#if GERMAN
	.string "Forschungslog 5: 2. Juni 1975\p"
	.string "Wir haben ihn geöffnet…\p"
	.string "Ich dachte, ich wäre überglücklich…\p"
	.string "Doch wir haben gute Männer in der\n"
	.string "Energieentladung verloren, die aus dem\l"
	.string "Tempel schoss.\p"
	.string "Ganz zu schweigen von den Pokémon, die\n"
	.string "uns beim Öffnen geholfen haben.\l"
	.string "Mögen sie in Frieden ruhen…\p"
	.string "………………\p"
	.string "Wie dem auch sei.\p"
	.string "Der Tempel ist offen, doch wir\n"
	.string "stehen nur vor neuen Fragen.\p"
	.string "Kein legendäres Pokémon darin.\n"
	.string "Kein Schatz.\p"
	.string "Unsere Vorräte gehen zur Neige und wir\n"
	.string "haben nichts für unsere Mühen\l"
	.string "vorzuweisen…$"
#else
    .string "Research Log 5:  June 2, 1975\p"
	.string "We managed to get it open...\p"
	.string "I thought I'd be overjoyed...\p"
	.string "But we lost good men in the blast\n"
	.string "of energy that sprung from the\l"
	.string "temple.\p"
	.string "Not to mention the POKéMON that\n"
	.string "helped us get it open.\l"
	.string "God rest their souls...\p"
	.string "........................\p"
	.string "Regardless.\p"
	.string "The temple is open, but we are\n"
	.string "only left with more questions.\p"
	.string "There is no legendary POKéMON\n"
	.string "inside. No treasure.\p"
	.string "Our supplies are starting to run\n"
	.string "out and we have nothing to show\l"
	.string "for our efforts...$"
#endif

SinjohRuins_Lab_Text_Note6:
#if GERMAN
	.string "Forschungslog 6: 10. Juni 1975\p"
	.string "Die Expedition ist beendet.\n"
	.string "Die übrigen Männer packen zusammen.\p"
	.string "Aber ich kann nicht.\p"
	.string "Ich kann diese Mission nicht aufgeben.\n"
	.string "Nicht nach allem, was wir verloren\l"
	.string "haben.\p"
	.string "Ich werde hierbleiben.$"
#else
  	.string "Research Log 6:  June 10, 1975\p"
    .string "The expedition is done.\n"
	.string "The rest of the men are packing up.\p"
	.string "But I can't.\p"
	.string "I can't abandon this mission.\n"
	.string "Not after what we've lost.\p"
	.string "I'm going to stay behind.$"
#endif

SinjohRuins_Lab_Text_Note7:
#if GERMAN
	.string "Forschungslog 7: 10. September 1975\p"
	.string "Es ist Monate her, seit wir hier\n"
	.string "ankamen. Seit ich hier ankam.\p"
	.string "Die übrigen Männer sind fort.\p"
	.string "Jetzt sind nur noch ich und die Pokémon\n"
	.string "hier, die wir als Helfer für die Arbeiten\l"
	.string "gefangen haben.\p"
	.string "Ich trainiere sie, damit sie stärker\n"
	.string "werden.\p"
	.string "Mein Tornupto allen voran.\p"
	.string "Wir müssen herausfinden, was unter\n"
	.string "dem Tempel liegt.$"
#else
  	.string "Research Log 7:  September 10, 1975\p"
	.string "It's been months since we got\n"
	.string "here. Since I got here.\p"
	.string "The rest of the men are gone.\p"
	.string "Now it's just me and the\n"
	.string "POKéMON we captured to help us\l"
	.string "with the work.\p"
	.string "I've been training them to get\n"
	.string "stronger.\p"
	.string "My TYPHLOSION, most of all.\p"
	.string "We must find out what's beneath\n"
	.string "the temple.$"
#endif

SinjohRuins_Lab_Text_Note8:
#if GERMAN
	.string "Forschungslog 8: 15. September 1975\p"
	.string "Gescheitert.\p"
	.string "………………\p"
	.string "Meine Pokémon…\p"
	.string "Gemeinsam konnten alle 6 meiner\n"
	.string "Pokémon eine Scheinwand im Tempel\l"
	.string "durchbrechen.\p"
	.string "Doch es hat dort auf uns gewartet…\p"
	.string "Etwas wie ein riesiger Titan…\p"
	.string "Die Energie, die es freisetzte, war\n"
	.string "wie beim letzten Mal.\p"
	.string "Sie wurden alle vernichtet…\p"
	.string "Und das Schlimmste: Das Ungetüm hat\n"
	.string "die Wand wieder versiegelt.\p"
	.string "Ich kann nicht nach Hause.\n"
	.string "Sie würden mich nicht mehr\l"
	.string "wiedererkennen…\p"
	.string "Dieser Ort hat mich verändert…\p"
	.string "Ich werde mit den Dorfbewohnern\n"
	.string "sprechen.\p"
	.string "Sie wissen nicht, was ich getan\n"
	.string "habe.\p"
	.string "Da die anderen Männer längst fort sind,\n"
	.string "werden sie mich für einen verirrten\l"
	.string "Wanderer halten.\p"
	.string "Für mich gibt es keinen Ort mehr\n"
	.string "außer diesem.$"
#else
  	.string "Research Log 8:  September 15, 1975\p"
	.string "Failure.\p"
	.string "......................\p"
	.string "My POKéMON....\p"
	.string "Together, all 6 of my POKéMON\n"
	.string "were able to smash through\n"
	.string "A false wall in the temple.\p"
	.string "But it was waiting for us...\p"
	.string "Something like a giant titan...\p"
	.string "The energy it released was just\n"
	.string "like what happened before.\p"
	.string "They were all destroyed...\p"
	.string "And worst of all, that beast\n"
	.string "sealed the wall back up.\p"
	.string "I can't go home.\n"
	.string "They won't recognize me anymore...\p"
	.string "This place has changed me...\p"
	.string "I'm going to talk with the\n"
	.string "villagers.\p"
	.string "They don't know what I've done.\p"
	.string "Since the other men are long\n"
	.string "gone, they'll think I'm just a\l"
	.string "lost hiker.\p"
	.string "There is no place left for me\n"
	.string "but here.$"
#endif

SinjohRuins_EventScript_DisplayCase::
    lock
	msgbox SinjohRuins_DisplayCase_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_DisplayCase_Text:
#if GERMAN
	.string "Eine Vitrine, ordentlich bestückt\n"
	.string "mit Proben und Artefakten!$"
#else
    .string "It's a display case neatly\n"
	.string "packed and lined with samples\l"
	.string "and artifacts!$"
#endif

SinjohRuins_EventScript_WallSign::
    lock
	msgbox SinjohRuins_WallSign_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_WallSign_Text:
#if GERMAN
	.string "Röntgen- und Drucklabor.$"
#else
   .string "Xray and printing lab.$"
#endif


SinjohRuins_EventScript_Artifact::
   lock
   msgbox SinjohRuins_Artifact_Text MSGBOX_DEFAULT
   release
   end

SinjohRuins_Artifact_Text:
#if GERMAN
	.string "Ein Artefakt, das im Inneren der\n"
	.string "Ruinen gefunden wurde!$"
#else
   .string "It's an artifact found from\n"
   .string "inside the ruins!$"
#endif


@==========================Unified other map SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_NoOp::
	release
	end

SinjohRuins_Lab_Text_PlayFlute:
#if GERMAN
	.string "Die Azurflöte reagiert.\n"
	.string "Willst du auf ihr spielen?$"
#else
	.string "The AZURE FLUTE is reacting.\n"
	.string "Play the flute?$"
#endif

SinjohRuins_Lab_Text_DropedItem:
#if GERMAN
	.string "Das Königliche {STR_VAR_1} ließ ein Item\n"
	.string "fallen…$"
#else
	.string "The NOBLE {STR_VAR_1} dropped\n"
	.string "an item...$"
#endif

SinjohRuins_Lab_Text_StevenName:
	.string "STEVEN$"

SinjohRuins_Lab_EventScript_3Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall3Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_6Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall6Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_9Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall9Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_12Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall12Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_15Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall15Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_16Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall16Plates
	waitmessage
	delay 30
	setvar VAR_SINJOH_STORYLINE, 7
	return

SinjohRuins_Lab_Text_StevenCall3Plates:
#if GERMAN
	.string "Troy: {PLAYER}.\p"
	.string "Wir haben gerade eine\n"
	.string "Erschütterung an den Ruinen\l"
	.string "gespürt.\p"
	.string "Keine Sorge, es geht allen gut.\p"
	.string "Es ist höchst faszinierend: Eine\n"
	.string "der unterirdischen Kammern unter\l"
	.string "den Ruinen ist aufgebrochen.\p"
	.string "Die Zeichen darin erinnern mich\n"
	.string "an etwas aus Hoenn.\p"
	.string "Komm vorbei und sieh es dir an,\n"
	.string "wenn du kannst.$"
#else
	.string "STEVEN: {PLAYER}.\p"
	.string "We felt a tremor at the ruins\n"
	.string "just now.\p"
	.string "Everyone's fine, don't worry.\p"
	.string "It's quite intriguing, one of the\n"
	.string "subterranean chambers beneath the\l"
	.string "ruins has sprung open.\p"
	.string "The markings inside remind me of\n"
	.string "something from HOENN.\p"
	.string "You should come take a look when\n"
	.string "you can.$"
#endif

SinjohRuins_Lab_Text_StevenCall6Plates:
#if GERMAN
	.string "Troy: {PLAYER}.\p"
	.string "Wie läuft die Suche?\p"
	.string "Wir hatten wieder eine\n"
	.string "Erschütterung. Diesmal hat sich\l"
	.string "eine zweite Kammer geöffnet.\p"
	.string "Ich habe unseren Geologen\n"
	.string "gebeten, seine Instrumente\l"
	.string "bereitzuhalten, falls es erneut\l"
	.string "passiert.\p"
	.string "Je tiefer wir graben… desto mehr\n"
	.string "Fragen tun sich auf.$"
#else
	.string "STEVEN: {PLAYER}.\p"
	.string "How's the search going?\p"
	.string "We had another tremor here. A\n"
	.string "second chamber opened up this\l"
	.string "time.\p"
	.string "I've asked our geologist to keep\n"
	.string "his instruments ready in case it\l"
	.string "happens again.\p"
	.string "The deeper we dig... The more\n"
	.string "questions we find.$"
#endif

SinjohRuins_Lab_Text_StevenCall9Plates:
#if GERMAN
	.string "Troy: {PLAYER}.\p"
	.string "Wieder eine Erschütterung hier an\n"
	.string "den Ruinen.\p"
	.string "Die Daten zeichnen ein\n"
	.string "faszinierendes Bild.\p"
	.string "Es war gar kein Erdbeben.\p"
	.string "Eine Art Energie hat sich im\n"
	.string "Untergrund aufgestaut und den\l"
	.string "Fels von innen aufgesprengt.\p"
	.string "Was das verursachen könnte… Ich\n"
	.string "weiß es ehrlich nicht.$"
#else
	.string "STEVEN: {PLAYER}.\p"
	.string "Another tremor here at the ruins.\p"
	.string "The data paints an intriguing\n"
	.string "picture.\p"
	.string "It wasn't an earthquake at all.\p"
	.string "Some kind of energy built up\n"
	.string "underground and cracked the rock\l"
	.string "open from the inside.\p"
	.string "What could cause that... I\n"
	.string "honestly don't know.$"
#endif

SinjohRuins_Lab_Text_StevenCall12Plates:
#if GERMAN
	.string "Troy: {PLAYER}.\p"
	.string "Wieder eine Erschütterung. Wieder\n"
	.string "öffnet sich eine Kammer.\p"
	.string "Wir können noch immer kein Muster\n"
	.string "hinter den Zeitpunkten erkennen.\p"
	.string "Sag mal, {PLAYER}… du steckst\n"
	.string "nicht etwa hinter alledem, oder?\p"
	.string "Nein, das kann nicht sein.$"
#else
	.string "STEVEN: {PLAYER}.\p"
	.string "Another tremor. Another chamber\n"
	.string "opening up.\p"
	.string "We still can't figure out the\n"
	.string "pattern behind the timing.\p"
	.string "Say, {PLAYER}... you're not doing\n"
	.string "something to cause all this, are\l"
	.string "you?\p"
	.string "No, that can't be right.$"
#endif

SinjohRuins_Lab_Text_StevenCall15Plates:
#if GERMAN
	.string "Troy: {PLAYER}.\p"
	.string "Hast du gerade eine weitere\n"
	.string "Tafel gefunden?\p"
	.string "………………\p"
	.string "Natürlich.\p"
	.string "Die legendären Pokémon, die in\n"
	.string "diesen Ruinen ruhen… sie\l"
	.string "reagieren auf dich, nicht wahr?\p"
	.string "Als wollten sie gefunden werden.\p"
	.string "Meine Vorahnungen bewahrheiten\n"
	.string "sich meistens. Ich hätte nicht an\l"
	.string "dir zweifeln sollen.$"
#else
	.string "STEVEN: {PLAYER}.\p"
	.string "Did you just find another PLATE?\p"
	.string ".................\p"
	.string "Of course.\p"
	.string "The legendary POKéMON lying in\n"
	.string "these ruins... they're responding\l"
	.string "to you, aren't they?\p"
	.string "As if they want to be found.\p"
	.string "My predictions usually come\n"
	.string "true. I should have known better\l"
	.string "than to doubt you.$"
#endif

SinjohRuins_Lab_Text_StevenCall16Plates:
#if GERMAN
	.string "Troy: {PLAYER}.\p"
	.string "Wir sind jetzt ganz nah dran.\n"
	.string "Ich kann es spüren.\p"
	.string "………………\p"
	.string "Das solltest du dir mit eigenen\n"
	.string "Augen ansehen.$"
#else
	.string "STEVEN: {PLAYER}.\p"
	.string "We're very close now. I can feel\n"
	.string "it.\p"
	.string "..................\p"
	.string "You should come see this for\n"
	.string "yourself.$"
#endif

