CeruleanCity_House1_Frlg_MapScripts::
	.byte 0

CeruleanCity_House1_EventScript_BadgeGuy::
	lock
	faceplayer
	msgbox CeruleanCity_House1_Text_BadgesHaveAmazingSecrets
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeAnotherBadge::
	message CeruleanCity_House1_Text_DescribeWhichBadge
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BADGES
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, CeruleanCity_House1_EventScript_DescribeBoulderBadge
	case 1, CeruleanCity_House1_EventScript_DescribeCascadeBadge
	case 2, CeruleanCity_House1_EventScript_DescribeThunderBadge
	case 3, CeruleanCity_House1_EventScript_DescribeRainbowBadge
	case 4, CeruleanCity_House1_EventScript_DescribeSoulBadge
	case 5, CeruleanCity_House1_EventScript_DescribeMarshBadge
	case 6, CeruleanCity_House1_EventScript_DescribeVolcanoBadge
	case 7, CeruleanCity_House1_EventScript_DescribeEarthBadge
	case 8, CeruleanCity_House1_EventScript_StopDescribingBadges
	case 127, CeruleanCity_House1_EventScript_StopDescribingBadges
	end

CeruleanCity_House1_EventScript_DescribeBoulderBadge::
	msgbox CeruleanCity_House1_Text_AttackStatFlash
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeCascadeBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv30Cut
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeThunderBadge::
	msgbox CeruleanCity_House1_Text_SpeedStatFly
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeRainbowBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv50Strength
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeSoulBadge::
	msgbox CeruleanCity_House1_Text_DefenseStatSurf
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeMarshBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv70RockSmash
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeVolcanoBadge::
	msgbox CeruleanCity_House1_Text_SpStatsWaterfall
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeEarthBadge::
	msgbox CeruleanCity_House1_Text_AllMonsWillObeyYou
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_StopDescribingBadges::
	msgbox CeruleanCity_House1_Text_ComeVisitAnytime
	release
	end

CeruleanCity_House1_Text_BadgesHaveAmazingSecrets::
#if GERMAN
	.string "Nur sehr begabte Trainer tragen\n"
	.string "Pokémon-Orden.\p"
	.string "Wie ich sehe, bist du bereits Träger\n"
	.string "eines Ordens.\p"
	.string "Die Orden sind geheimnisumwoben!$"
#else
	.string "Only skilled TRAINERS can collect\n"
	.string "POKéMON BADGES.\p"
	.string "I see you have at least one.\p"
	.string "Those BADGES have amazing secrets,\n"
	.string "did you know?$"
#endif

CeruleanCity_House1_Text_DescribeWhichBadge::
#if GERMAN
	.string "Also dann...\p"
	.string "Über welchen der acht Orden soll\n"
	.string "ich dir etwas erzählen?$"
#else
	.string "Now then…\p"
	.string "Which of the eight BADGES should\n"
	.string "I describe?$"
#endif

CeruleanCity_House1_Text_ComeVisitAnytime::
#if GERMAN
	.string "Besuche mich, wann immer du möchtest.$"
#else
	.string "Come visit me anytime you wish.$"
#endif

CeruleanCity_House1_Text_AttackStatFlash::
#if GERMAN
	.string "Die Angriffe deiner Pokémon werden ein\n"
	.string "wenig verstärkt.\p"
	.string "Außerdem kannst du jederzeit Blitz\n"
	.string "einsetzen.$"
#else
	.string "The ATTACK stat of all your\n"
	.string "POKéMON increases a little bit.\p"
	.string "It also lets you use the move\n"
	.string "FLASH outside of battle.$"
#endif

CeruleanCity_House1_Text_ObeyLv30Cut::
#if GERMAN
	.string "Mit zwei Orden folgen dir Pokémon\n"
	.string "bis Level 20!\p"
	.string "Pokémon höherer Level gehorchen\n"
	.string "dir jedoch nicht!\p"
	.string "Ferner kannst du den Zerschneider\n"
	.string "außerhalb von Kämpfen nutzen!$"
#else
	.string "POKéMON up to Lv. 30 will obey\n"
	.string "you.\p"
	.string "That includes even outsiders you\n"
	.string "obtain in trades.\p"
	.string "POKéMON of higher levels will\n"
	.string "be unruly in battle, however.\p"
	.string "It also lets you use the move\n"
	.string "CUT outside of battle.$"
#endif

CeruleanCity_House1_Text_SpeedStatFly::
#if GERMAN
	.string "Die Initiative deiner Pokémon\n"
	.string "nimmt zu.\p"
	.string "Des Weiteren ist es dir möglich, Fliegen\n"
	.string "außerhalb von Kämpfen einzusetzen.$"
#else
	.string "The SPEED stat of all your\n"
	.string "POKéMON increases a little bit.\p"
	.string "It also lets you use the move\n"
	.string "FLY outside of battle.$"
#endif

CeruleanCity_House1_Text_ObeyLv50Strength::
#if GERMAN
	.string "Mit vier Orden folgen dir Pokémon\n"
	.string "bis Level 30.\p"
	.string "Pokémon höherer Level gehorchen\n"
	.string "dir jedoch nicht!\p"
	.string "Zusätzlich kannst du außerhalb von\n"
	.string "Kämpfen Stärke einsetzen.$"
#else
	.string "POKéMON up to Lv. 50 will obey\n"
	.string "you.\p"
	.string "That includes even outsiders you\n"
	.string "obtain in trades.\p"
	.string "POKéMON of higher levels will\n"
	.string "be unruly in battle, however.\p"
	.string "It also lets you use the move\n"
	.string "STRENGTH outside of battle.$"
#endif

CeruleanCity_House1_Text_DefenseStatSurf::
#if GERMAN
	.string "Die Verteidigung deiner Pokémon\n"
	.string "wird verbessert.\p"
	.string "Ferner kannst du außerhalb von\n"
	.string "Kämpfen Surfer verwenden.$"
#else
	.string "The DEFENSE stat of all your\n"
	.string "POKéMON increases a little bit.\p"
	.string "It also lets you use the move\n"
	.string "SURF outside of battle.$"
#endif

CeruleanCity_House1_Text_ObeyLv70RockSmash::
#if GERMAN
	.string "Mit sechs Orden folgen dir Pokémon\n"
	.string "bis Level 40.\p"
	.string "Das gilt auch für getauschte\n"
	.string "Pokémon!\p"
	.string "Pokémon höherer Level gehorchen\n"
	.string "dir jedoch nicht!\p"
	.string "Du kannst den Zerschmetterer nun auch\n"
	.string "außerhalb eines Kampfes anwenden.$"
#else
	.string "POKéMON up to Lv. 70 will obey\n"
	.string "you.\p"
	.string "That includes even outsiders you\n"
	.string "obtain in trades.\p"
	.string "POKéMON of higher levels will\n"
	.string "be unruly in battle, however.\p"
	.string "It also lets you use the move\n"
	.string "ROCK SMASH outside of battle.$"
#endif

CeruleanCity_House1_Text_SpStatsWaterfall::
#if GERMAN
	.string "Der SP. ANG.- und SP. Ver.-Wert\n"
	.string "deiner Pokémon steigt geringfügig.\p"
	.string "Du kannst die Attacke Kaskade\n"
	.string "außerhalb eines Kampfes anwenden.$"
#else
	.string "The SP. ATK and SP. DEF stats of\n"
	.string "all your POKéMON rise a little bit.\p"
	.string "It also lets you use the move\n"
	.string "WATERFALL outside of battle.$"
#endif

CeruleanCity_House1_Text_AllMonsWillObeyYou::
#if GERMAN
	.string "Mit acht Orden folgen dir Pokémon\n"
	.string "bis Level 50!$"
#else
	.string "All POKéMON will obey you!$"
#endif

