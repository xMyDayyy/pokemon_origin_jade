Route39_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Item_TM::
	finditem ITEM_TM_DRAIN_PUNCH
	end

Route39_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route39_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE39_SHADOW
	addobject LOCALID_R39_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE39_SHADOW
	removeobject LOCALID_R39_SHADOW
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
	delay 60

	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4

	turnobject LOCALID_R39_BAOBA DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
Route39_EventScript_ChooseLegend::
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route39_EventScript_LegendaryTriggerGold
	case 1, Route39_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
	release
	end

Route39_EventScript_BaobaMovement1::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
	waitmovement 0
	return
Route39_EventScript_BaobaMovement2::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
	waitmovement 0
	return
Route39_EventScript_BaobaMovement3::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
	waitmovement 0
	return
Route39_EventScript_BaobaMovement4::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
	waitmovement 0
	return

Route39_Movement_Baoba1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route39_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_BaobaIntro::
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
	playse MUS_HG_POKEGEAR_REGISTERED
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
	waitse
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	release
	end

Route39_Text_ChooseLegend::
#if GERMAN
	.string "Baoba: Grundgütiger! Gehört dieser\n"
	.string "Schatten zu einem Pokémon?\p"
	.string "Hast du es sehen können?\n"
	.string "Ich konnte die Farbe nicht erkennen…$"
#else
	.string "BAOBA: GOOD HEAVENS! Did that\n"
	.string "shadow belong to a POKéMON?\p"
	.string "Did you get a good look at it?\n"
	.string "I can't tell what color it was...$"
#endif

Route39_Text_BaobaIntro::
#if GERMAN
	.string "Baoba: …Sehe ich richtig?\n"
	.string "Dieses Ding, das du da bei dir trägst,\l"
	.string "ist doch ein Pokédex, oder?\p"
	.string "Ach ja, da werden Erinnerungen wach!\p"
	.string "Mein Name ist Baoba!\p"
	.string "Bis vor Kurzem habe ich noch die Safari\n"
	.string "in Fuchsania City geleitet. Aber es\l"
	.string "tauchten immer neue Parks auf und \l"
	.string "irgendwann blieb meine Safari-Zone\l"
	.string "hinter der Konkurrenz zurück.\p"
	.string "Also ergriff ich die Initiative!\n"
	.string "Ich eignete mir im Ausland einige neue\l"
	.string "Kniffe an und entschied mich, in\l"
	.string "Anemonia City eine neue Safari zu\l"
	.string "eröffnen!\p"
	.string "Dass wir zwei uns hier kennenlernen,\n"
	.string "ist bestimmt Schicksal!\p"
	.string "Wenn das mal kein guter Grund dafür ist,\n"
	.string "Telefonnummern auszutauschen, was?\p"
	.string "Wenn die Safari-Zone eröffnet wird,\n"
	.string "bist du der Erste, der davon erfährt!$"
#else
	.string "How strange...\p"
	.string "...Ohh!\n"
	.string "What you are holding is...\l"
	.string "what they call... a POKéDEX!\p"
	.string "Haven't seen one of those in ages.\p"
	.string "My name is BAOBA!\n"
	.string "I used to run a SAFARI ZONE in\l"
	.string "FUCHSIA CITY, but it was becoming\l"
	.string "out of date with new entertainment\l"
	.string "options coming out.\p"
	.string "I decided to go overseas to learn\n"
	.string "the newest technology and open a\l"
	.string "state-of-the-art SAFARI ZONE\l"
	.string "in CIANWOOD.\p"
	.string "It may be more than a coincidence\n"
	.string "that we are chatting.\p"
	.string "Why don't we register each other's\n"
	.string "numbers in the POKéGEAR?\p"
	.string "I can give you a call once the\n"
	.string "SAFARI ZONE is open before I call\l"
	.string "anyone else!$"
#endif

Route39_Text_Registered:
#if GERMAN
	.string "{PLAYER} hat Baobas Nummer im PokéCom\n"
	.string "registriert!$"
#else
	.string "{PLAYER} registered BAOBA\n"
	.string "in the POKéGEAR!$"
#endif


Route39_Text_WillCall:
#if GERMAN
	.string "Baoba: Ich gebe dir demnächst\n"
	.string "auf dem PokéCom Bescheid!$"
#else
	.string "BAOBA: I'll let you know\n"
	.string "on the POKéGEAR soon!$"
#endif

Route39_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
#if GERMAN
	.string "Dieser Schatten… war das ein\n"
	.string "riesiges Taubsi?$"
#else
	.string "That shadow... Maybe it was a giant\n"
	.string "PIDGEY?$"
#endif

Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
#if GERMAN
	.string "Miltank: Miiillltank!$"
#else
	.string "MILTANK: Mooo!$"
#endif

Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE_HNS, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
#if GERMAN
	.string "Ich war lange nicht in Oliviana City.\n"
	.string "Wie steht es mit dem Pokémon-Kampf?$"
#else
	.string "I just got back to OLIVINE.\p"
	.string "So how about a POKéMON battle?$"
#endif

Route39_Text_SailorEugeneBeaten:
#if GERMAN
	.string "Aaah!$"
#else
	.string "Awaaargh!$"
#endif

Route39_Text_SailorEugeneAfter:

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten, Route39_EventScript_RegisterDerek
	goto_if_set FLAG_DEREK_HAS_ITEM_HNS, Route39_EventScript_DerekGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route39_EventScript_RematchDerek
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RematchDerek::
	trainerbattle_rematch TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RegisterDerek::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route39_Text_DerekRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DEREK_HNS
	release
	end

Route39_EventScript_DerekGiveItem::
	msgbox Route39_Text_DerekHasItem, MSGBOX_DEFAULT
	giveitem VAR_DEREK_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route39_EventScript_DerekNoRoom
	clearflag FLAG_DEREK_HAS_ITEM_HNS
	msgbox Route39_Text_DerekGaveItem, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_DerekNoRoom::
	msgbox Route39_Text_DerekNoRoom, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
#if GERMAN
	.string "Genau der richtige Moment, um mit\n"
	.string "Pikachu anzugeben!$"
#else
	.string "This is a good time to brag\n"
	.string "about my PIKACHU!$"
#endif

Route39_Text_PokefanMDerekBeaten:
#if GERMAN
	.string "Ich hatte keine Zeit, mit Pikachu zu\n"
	.string "prahlen…$"
#else
	.string "I had no time to show off\n"
	.string "PIKACHU…$"
#endif

Route39_Text_PokefanMDerekAfter:

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH_HNS, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
#if GERMAN
	.string "Zeigst du mir dein Pokémon-Team, zeige\n"
	.string "ich dir meins! Aber nur gleichzeitig!$"
#else
	.string "Such darling POKéMON.\p"
	.string "Let's show our POKéMON\n"
	.string "together at the same time.$"
#endif

Route39_Text_PokefanFRuthBeaten:
#if GERMAN
	.string "Mir macht es nichts aus zu verlieren.$"
#else
	.string "I don't mind losing.$"
#endif

Route39_Text_PokefanFRuthAfter:
#if GERMAN
	.string "Hast du schon mal ein Baby-Pokémon\n"
	.string "gesehen?\l"
	.string "Die sind bestimmt super-süß!$"
#else
	.string "Do you know about baby\n"
	.string "POKéMON?\p"
	.string "I bet they're just adorable!$"
#endif

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN_HNS, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
#if GERMAN
	.string "Zeig doch mal, was dein Pokémon-Team\n"
	.string "so drauf hat.$"
#else
	.string "Let me see what your\n"
	.string "POKéMON are capable of.$"
#endif

Route39_Text_PsychicNormanBeaten:
#if GERMAN
	.string "Nicht schlecht! Dein Team hat viel\n"
	.string "Talent!$"
#else
	.string "Ooh, your POKéMON have\n"
	.string "potential.$"
#endif

Route39_Text_PsychicNormanAfter:
#if GERMAN
	.string "Jedes Pokémon hat unterschiedliche\n"
	.string "Fähigkeiten.\p"
	.string "Bei Menschen ist das ganz ähnlich. Jeder\n"
	.string "hat unterschiedliche Talente.$"
#else
	.string "You know how POKéMON have\n"
	.string "different abilities?\p"
	.string "People are like that too.\n"
	.string "Everyone has different\l"
	.string "potential.$"
#endif

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE_HNS, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
#if GERMAN
	.string "Du kommst gerade recht.\p"
	.string "Auf in den Kampf.$"
#else
	.string "You came at just the right\n"
	.string "time.\p"
	.string "Let's battle.$"
#endif

Route39_Text_PokefanFJaimeBeaten:
#if GERMAN
	.string "Oh, was für eine Enttäuschung.$"
#else
	.string "Oh, how disappointing…$"
#endif

Route39_Text_PokefanFJaimeAfter:
#if GERMAN
	.string "Ich habe Nachtara nachts genau hier\n"
	.string "auf Route 39 getroffen.\p"
	.string "Ich weiß nicht, warum, aber es scheint\n"
	.string "zu mögen, wenn ich hier trainiere.\p"
	.string "Hier wird es schneller zutraulich\n"
	.string "als irgendwo sonst.$"
#else
	.string "I met UMBREON at night right\n"
	.string "here on ROUTE 39.\p"
	.string "I'm not sure why, but it\n"
	.string "seems to like it when I\l"
	.string "train here.\p"
	.string "It seems to become friendlier\n"
	.string "by training here than\l"
	.string "anywhere else.$"
#endif

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
#if GERMAN
	.string "Route 39\p"
	.string "Oliviana City - Teak City$"
#else
	.string "ROUTE 39\p"
	.string "OLIVINE CITY - ECRUTEAK CITY$"
#endif

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
#if GERMAN
	.string "Kuhmuh-Farm Hier wartet immer ein Glas\n"
	.string "frische und bekömmliche Milch auf dich!$"
#else
	.string "MOOMOO FARM\p"
	.string "Enjoy Our Fresh and Tasty Milk$"
#endif

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Benutze Kopfnuss, um Pokémon aus\n"
	.string "Bäumen zu schütteln. Von jedem Baum\l"
	.string "könnte ein anderes Pokémon purzeln!\p"
	.string "Probiere Kopfnuss also an möglichst\n"
	.string "vielen verschiedenen Bäumen aus!$"
#else
	.string "TRAINER TIPS\p"
	.string "Use HEADBUTT on trees to shake\n"
	.string "POKéMON out.\p"
	.string "Different kinds of POKéMON\n"
	.string "drop out of trees.\p"
	.string "Use HEADBUTT on any tree\n"
	.string "you see!$"
#endif

Route39_Text_DerekRegister:
#if GERMAN
    .string "Ich höre mir deine Angeberei gar nicht\n"
    .string "erst an!\p"
    .string "Wir Pokémaniacs haben nämlich die\n"
    .string "Regel, Angebereien zu ignorieren!$"
#else
	.string "I'm not listening to your\n"
	.string "bragging!\p"
	.string "We POKé FANS have a policy\n"
	.string "of not listening to bragging!$"
#endif

Route39_Text_DerekHasItem:
#if GERMAN
	.string "Hey! Ich habe mein Pikachu\n"
	.string "herumgezeigt und dabei etwas gefunden.\p"
	.string "Hier, du kannst es haben!$"
#else
	.string "Hey! I was showing off my\n"
	.string "PIKACHU and found something.\p"
	.string "Here, you can have it!$"
#endif

Route39_Text_DerekGaveItem:
#if GERMAN
	.string "Pikachu ist einfach das Beste!\n"
	.string "Findest du nicht auch?$"
#else
	.string "PIKACHU is it!\n"
	.string "Don't you agree?$"
#endif

Route39_Text_DerekNoRoom:
#if GERMAN
    .string "Hm, dein Beutel ist voll.\p"
    .string "Komm wieder, wenn du Platz hast.$"
#else
	.string "Hmm, your BAG is full.\p"
	.string "Come back when you have room.$"
#endif
