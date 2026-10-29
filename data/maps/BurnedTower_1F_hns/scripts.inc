BurnedTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition:
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_EUSINE
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
#if GERMAN
	.string "Eusin: Mein Name ist Eusin.\p"
	.string "Ich bin auf der Spur eines Pokémon\n"
	.string "namens Suicune.\p"
	.string "Und du bist…?\p"
	.string "{PLAYER}? Schön dich kennenzulernen!\p"
	.string "Ich habe gehört, Suicune könnte\n"
	.string "in dieser Turmruine sein, also\l"
	.string "bin ich hergekommen.\p"
	.string "Aber wo genau könnte es sein?$"
#else
	.string "EUSINE: My name's EUSINE.\p"
	.string "I'm on the trail of a POKéMON\n"
	.string "called SUICUNE.\p"
	.string "And you are...?\p"
	.string "{PLAYER}? Glad to meet you!\p"
	.string "I heard SUICUNE might be in\n"
	.string "this BURNED TOWER, so I came\l"
	.string "to check it out.\p"
	.string "But where exactly could it be?$"
#endif

BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
#if GERMAN
	.string "Eusin: Ich habe gehört, Suicune\n"
	.string "könnte in dieser Turmruine sein,\l"
	.string "also bin ich hergekommen.\p"
	.string "Aber wo genau könnte es sein?$"
#else
	.string "EUSINE: I heard SUICUNE might\n"
	.string "be in this BURNED TOWER, so I\l"
	.string "came to check it out.\p"
	.string "But where exactly could it be?$"
#endif

BurnedTower_1FMortyText:
#if GERMAN
	.string "Jens: Der Arenaleiter von Teak City\n"
	.string "muss die sogenannten legendären\l"
	.string "Pokémon\p"
	.string "Suicune, Entei und Raikou studieren.\p"
	.string "Eusin ist gekommen, also habe ich\n"
	.string "beschlossen, den Turm mit ihm zu\l"
	.string "untersuchen.$"
#else
	.string "MORTY: ECRUTEAK's GYM LEADER\n"
	.string "has to study what are said to\l"
	.string "be the legendary POKéMON--\l"
	.string "SUICUNE, ENTEI and RAIKOU.\p"
	.string "EUSINE is here, so I've\n"
	.string "decided to investigate the\l"
	.string "TOWER with him.$"
#endif

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_JOHTO_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_JOHTO_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_JOHTO_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F_HNS
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	waitstate
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
#if GERMAN
	.string "..............................\p"
	.string "…Oh, du bist es.\p"
	.string "Ich suchte nach legendären Pokémon,\n"
	.string "die angeblich hier leben.\p"
	.string "Aber hier ist nichts!\p"
	.string "Nichts, was den Aufwand hierher zu\n"
	.string "kommen rechtfertigt, absolut?\l"
	.string "Nichts!\p"
	.string "Das ist alles deine Schuld!$"
#else
	.string "..............................\p"
	.string "...Oh, it's you.\p"
	.string "I came looking for some\n"
	.string "legendary POKéMON they say\l"
	.string "roost here.\p"
	.string "But there's nothing here!\p"
	.string "Nothing, after all the effort\n"
	.string "of coming to this dump?\l"
	.string "No way!\p"
	.string "It's all your fault!$"
#endif

BurnedTowerSilver_WinText:
#if GERMAN
	.string "…Humph!\p"
	.string "Darum hasse ich es, gegen Schwächlinge\n"
	.string "anzutreten.\p"
	.string "Wie armselig.$"
#else
	.string "...Humph!\p"
	.string "I only lost because my\n"
	.string "POKéMON are incredibly weak.\p"
	.string "How pathetic.$"
#endif

BurnedTowerSilver_AfterText1:
#if GERMAN
	.string "{PLAYER}: …Ach egal.\p"
	.string "Du schaffst es sowieso nie, dir ein\n"
	.string "Legendäres Pokémon zu schnappen!$"
#else
	.string "...Aw, whatever.\p"
	.string "You'd never be able to catch\n"
	.string "a legendary POKéMON anyway.$"
#endif

BurnedTowerSilver_LossText:
#if GERMAN
	.string "…Humph!\p"
	.string "Ich hasse es, gegen Schwächlinge\n"
	.string "anzutreten. Es ist Zeitverschwendung.$"
#else
	.string "...Humph!\p"
	.string "This is why I hate battling\n"
	.string "wimps. It's a waste of time.$"
#endif

BurnedTowerSilver_AfterText2:
#if GERMAN
	.string "Humph!\p"
	.string "Was hast du dir dabei gedacht,\n"
	.string "einfach in ein Loch zu fallen?\p"
	.string "Du Genie!$"
#else
	.string "Humph!\p"
	.string "What are you doing falling\n"
	.string "into a hole? Some genius!\p"
	.string "Serves you right!$"
#endif

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD_HNS, BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO_HNS, BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
#if GERMAN
	.string "He, keine Panik, Junior!\n"
	.string "Wenn jemand weiß, wie gefährlich es ist,\l"
	.string "mit Feuer zu spielen, dann sind das wir\l"
	.string "Feuerspucker!$"
#else
	.string "Don't worry!\p"
	.string "We fire-breathers know the true\n"
	.string "power of fire better than anyone!$"
#endif
BurnedTower_Text_NardBeaten:
	.string "Danke für den heißen Kampf.$"
BurnedTower_Text_NardAfter:
#if GERMAN
	.string "Dieser Turm ist durch einen Blitzschlag\n"
	.string "abgebrannt.\p"
	.string "Dagegen sind unsere Flammen bloß heiße\n"
	.string "Luft…$"
#else
	.string "The reason this tower's burned is\n"
	.string "that it was hit by lightning.\p"
	.string "The fire I'm breathing is tiny\n"
	.string "in comparison...$"
#endif

BurnedTower_Text_RichardoSeen:
#if GERMAN
	.string "Ich übe in der Turmruine das\n"
	.string "Feuerspucken!\l"
	.string "Macht das nicht zu Hause nach, Kinder!$"
#else
	.string "I'm practicing my stealing in the\n"
	.string "BURNED TOWER! Don't try\l"
	.string "this at home!$"
#endif
BurnedTower_Text_RichardoBeaten:
	.string "Pfffffffffffffff.$"
BurnedTower_Text_RichardoAfter:
#if GERMAN
	.string "Vielleicht ist ein Leben als Verbrecher\n"
	.string "doch nichts für mich…$"
#else
	.string "Maybe a life of crime isn't for\n"
	.string "me...$"
#endif
