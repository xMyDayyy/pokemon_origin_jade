Route12_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN_HNS, Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN_HNS, Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY_HNS, Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE_HNS, Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten, Route12_EventScript_RegisterKyle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_RematchKyle
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_RegisterKyle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_KyleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KYLE_HNS
	release
	end

Route12_EventScript_RematchKyle::
	trainerbattle_rematch TRAINER_KYLE_HNS, Route12_Text_KyleRematchIntro, Route12_Text_KyleRematchDefeat
	msgbox Route12_Text_KylePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_KYLE_2_HNS, Route12_EventScript_RematchKyleTryGiveItem
	end

Route12_EventScript_RematchKyleTryGiveItem::
	checkitem ITEM_BLUE_SHARD
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_BLUE_SHARD
	closemessage
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Calcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_Magikarp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route12_Text_Magikarp, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_Magikarp:
	.string "MAGIKARP: Kaaaarp.$"

Route12_Text_NewFisher:
#if GERMAN
	.string "Vorsicht, in diesem Gewässer lebt etwas\n"
	.string "Bösartiges.$"
#else
	.string "Careful, something vicious lives in\n"
	.string "these waters.$"
#endif

Route12_Text_FisherMartinSeen:
#if GERMAN
	.string "Geduld ist das Zauberwort.\n"
	.string "Das gilt fürs Angeln und für Pokémon.$"
#else
	.string "Patience is the key to both\n"
	.string "fishing and POKéMON.$"
#endif

Route12_Text_FisherMartinBeaten:
#if GERMAN
	.string "Guaah!$"
#else
	.string "Gwaaah!$"
#endif

Route12_Text_FisherMartinAfterBattle:
#if GERMAN
	.string "Ich bin wohl doch zu ungeduldig\n"
	.string "für das Angeln…$"
#else
	.string "I'm too impatient for fishing…$"
#endif

Route12_Text_FisherStephenSeen:
#if GERMAN
	.string "Solange ich beim Angeln meinem Radio\n"
	.string "lauschen kann, bin ich glücklich.$"
#else
	.string "I feel so content, fishing while\n"
	.string "listening to some tunes on my\l"
	.string "radio.$"
#endif

Route12_Text_FisherStephenBeaten:
#if GERMAN
	.string "Das blöde Radio beunruhigt mich!$"
#else
	.string "My stupid radio distracted me!$"
#endif

Route12_Text_FisherStephenAfterBattle:
#if GERMAN
	.string "Wenn du gerade in Kanto bist, senden\n"
	.string "die Radiosender aus Johto ein Spezial-\l"
	.string "programm mit zusätzlichem Lokalteil!\p"
	.string "Äußerst praktisch und vor allem\n"
	.string "hörerfreundlich, findest du nicht?$"
#else
	.string "Have you checked out KANTO's radio\n"
	.string "programs? We get a good variety\l"
	.string "here.$"
#endif

Route12_Text_FisherBarneySeen:
#if GERMAN
	.string "Was ist in unserem alltäglichen\n"
	.string "Leben am wichtigsten?$"
#else
	.string "What's most important in our\n"
	.string "everyday lives?$"
#endif

Route12_Text_FisherBarneyBeaten:
#if GERMAN
	.string "Meine Antwort hörst du, wenn wir hier\n"
	.string "fertig sind!$"
#else
	.string "The answer is coming up next!$"
#endif

Route12_Text_FisherBarneyAfterBattle:
#if GERMAN
	.string "Meiner Meinung nach ist Strom das\n"
	.string "Wichtigste in unserem Leben.\p"
	.string "Wenn dem nicht so wäre, hätten die\n"
	.string "Leute nicht so einen Aufstand gemacht,\l"
	.string "als das Kraftwerk ausfiel.$"
#else
	.string "I think electricity is the most\n"
	.string "important thing in our daily\l"
	.string "lives.\p"
	.string "If it weren't, people wouldn't\n"
	.string "have made such a fuss when the\l"
	.string "POWER PLANT went out of\l"
	.string "commission.$"
#endif

Route12_Text_KyleRegister:
#if GERMAN
	.string "Ich werde mir das merken.\n"
	.string "Gib mir deine Nummer!$"
#else
	.string "I'll remember this.\n"
	.string "Give me your number!$"
#endif

Route12_Text_KyleRematchIntro:
#if GERMAN
	.string "Hast du es vergessen?\n"
	.string "Lass sehen!$"
#else
	.string "Did you forget?\n"
	.string "Let's see!$"
#endif

Route12_Text_KyleRematchDefeat:
#if GERMAN
	.string "Du hast nicht vergessen.$"
#else
	.string "You remembered.$"
#endif

Route12_Text_KylePostRematch:
#if GERMAN
	.string "Der Nervenkitzel des Kampfes\n"
	.string "ist wie ein großer Fang!$"
#else
	.string "The thrill of battle is almost\n"
	.string "as good as a big catch!$"
#endif

Route12_Text_FisherKyleSeen:
#if GERMAN
	.string "Erinnerst du dich noch?!?$"
#else
	.string "Do you remember?$"
#endif

Route12_Text_FisherKyleBeaten:
#if GERMAN
	.string "Du erinnerst dich?!?$"
#else
	.string "You do remember?$"
#endif

Route12_Text_FisherKyleAfterBattle:
#if GERMAN
	.string "Dieses Reißen an der Angel, wenn ein\n"
	.string "Pokémon angebissen hat…\l"
	.string "Das ist das Schönste für einen Angler!$"
#else
	.string "The tug you feel on the ROD when\n"
	.string "you hook a POKéMON…\p"
	.string "That's the best feeling ever for\n"
	.string "an angler like me.$"
#endif

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
#if GERMAN
	.string "Route 12 Norden: Lavandia$"
#else
	.string "ROUTE 12\p"
	.string "NORTH TO LAVENDER TOWN$"
#endif

Route12_Text_FishingSpotSign:
#if GERMAN
	.string "Angelplatz$"
#else
	.string "FISHING SPOT$"
#endif

