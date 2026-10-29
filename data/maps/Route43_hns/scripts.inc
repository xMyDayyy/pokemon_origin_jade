Route43_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route43_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route43_EventScript_Ben::
	trainerbattle_single TRAINER_BEN_HNS, Route43_Text_PokemaniacBenSeen, Route43_Text_PokemaniacBenBeaten
	msgbox Route43_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT_HNS, Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten, Route43_EventScript_RegisterBrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchBrent
	msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterBrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_BrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BRENT_HNS
	release
	end

Route43_EventScript_RematchBrent::
	trainerbattle_rematch TRAINER_BRENT_HNS, Route43_Text_BrentRematchIntro, Route43_Text_BrentRematchDefeat
	msgbox Route43_Text_BrentPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON_HNS, Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN_HNS, Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER_HNS, Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY_HNS, Route43_Text_PicnickerTiffanySeen, Route43_Text_PicnickerTiffanyBeaten, Route43_EventScript_RegisterTiffany
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchTiffany
	msgbox Route43_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterTiffany::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_TiffanyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIFFANY_HNS
	release
	end

Route43_EventScript_RematchTiffany::
	trainerbattle_rematch TRAINER_TIFFANY_HNS, Route43_Text_TiffanyRematchIntro, Route43_Text_TiffanyRematchDefeat
	msgbox Route43_Text_TiffanyPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_PokemaniacBenSeen:
#if GERMAN
	.string "Ich liebe mein Pokémon!\p"
	.string "Deshalb will ich auch nie, nie, niemals\n"
	.string "von ihm getrennt sein!$"
#else
    .string "I love POKéMON!\p"
    .string "That's why I started--and why I'll\n"
    .string "keep on collecting POKéMON!$"
#endif

Route43_Text_PokemaniacBenBeaten:
#if GERMAN
	.string "Wie konntest du mir das antun?$"
#else
    .string "How could you do this to me?$"
#endif

Route43_Text_PokemaniacBenAfter:
#if GERMAN
	.string "Was ich außer Pokémon noch mag?\p"
	.string "…Margit aus dem Radio! Die ist bestimmt\n"
	.string "süß!$"
#else
    .string "What else do I like besides\n"
    .string "POKéMON?\p"
    .string "MARY on the radio. I bet she's\n"
    .string "cute!$"
#endif

Route43_Text_PokemaniacBrentSeen:
#if GERMAN
	.string "He! Hast du seltene Pokémon?$"
#else
    .string "Hey! Do you have any rare\n"
    .string "POKéMON?$"
#endif

Route43_Text_PokemaniacBrentBeaten:
#if GERMAN
	.string "Meine armen Pokémon-Lieblinge!$"
#else
    .string "Oh, my poor POKéMON! Darlings!$"
#endif

Route43_Text_PokemaniacBrentAfter:
#if GERMAN
	.string "Ich wäre schon froh, wenn ich nur ein\n"
	.string "einziges seltenes Pokémon hätte.$"
#else
    .string "I'd be happy just to own a single\n"
    .string "rare POKéMON.$"
#endif

Route43_Text_BrentRegister:
#if GERMAN
	.string "Ich wäre schon froh, wenn ich nur ein\n"
	.string "einziges seltenes Pokémon hätte.$"
#else
    .string "I'd be happy just to own a single\n"
    .string "rare POKéMON.$"
#endif

Route43_Text_BrentRematchIntro:
#if GERMAN
	.string "He! Hast du seltene Pokémon?$"
#else
    .string "Hey! Do you have any rare\n"
    .string "POKéMON?$"
#endif

Route43_Text_BrentRematchDefeat:
#if GERMAN
	.string "Meine armen Pokémon-Lieblinge!$"
#else
    .string "Oh, my poor POKéMON! Darlings!$"
#endif

Route43_Text_BrentPostRematch:
#if GERMAN
	.string "Ich wäre schon froh, wenn ich nur ein\n"
	.string "einziges seltenes Pokémon hätte.$"
#else
    .string "I'd be happy just to own a single\n"
    .string "rare POKéMON.$"
#endif

Route43_Text_PokemaniacRonSeen:
#if GERMAN
	.string "Stell dir mal vor!\p"
	.string "so ein Typ namens {RIVAL} hat sich\n"
	.string "über mein Pokémon lustig gemacht!\p"
	.string "Unverschämtheit!\n"
	.string "Mein Pokémon ist toll!$"
#else
    .string "Would you get this?\p"
    .string "Some {RIVAL} guy made fun of my\n"
    .string "POKéMON!\p"
    .string "Darn it! My POKéMON's great!$"
#endif

Route43_Text_PokemaniacRonBeaten:
#if GERMAN
	.string "Mein Nidoking hat sich wacker\n"
	.string "geschlagen!$"
#else
    .string "My NIDOKING did pretty right on!$"
#endif

Route43_Text_PokemaniacRonAfter:
#if GERMAN
    .string "Es ist okay, wenn Leute verschiedene\n"
    .string "Pokémon-Typen mögen.\p"
    .string "Pokémon bedeutet nicht nur, das\n"
    .string "stärkste zu haben.$"
#else
    .string "It's okay for people to like\n"
    .string "different types of POKéMON.\p"
    .string "POKéMON isn't just about having the\n"
    .string "most powerful one.$"
#endif

Route43_Text_FisherMarvinSeen:
#if GERMAN
	.string "In letzter Zeit habe ich nur Pech. Was\n"
	.string "meinst du? Ob es an meinen Items liegt?\p"
	.string "Egal! Kämpfen wir! Das hebt vielleicht\n"
	.string "meine Laune.$"
#else
    .string "I'm in a slump.\p"
    .string "Maybe it's the gear I'm using.\p"
    .string "Let's battle for a change of pace!$"
#endif

Route43_Text_FisherMarvinBeaten:
#if GERMAN
	.string "Ich habe verloren, aber ich fühle mich\n"
	.string "trotzdem besser.$"
#else
    .string "I lost, but I feel better anyway.$"
#endif

Route43_Text_FisherMarvinAfter:
#if GERMAN
    .string "Kurts Köderball ist der beste,\n"
    .string "um geangelte Pokémon zu fangen.\p"
    .string "Er ist viel effektiver als ein\n"
    .string "Hyperball.$"
#else
    .string "KURT's LURE BALL is the best for\n"
    .string "catching hooked POKéMON.\p"
    .string "It's much more effective than a\n"
    .string "ULTRA BALL.$"
#endif

Route43_Text_CamperSpencerSeen:
#if GERMAN
	.string "Man kann so viel unternehmen mit seinen\n"
	.string "Pokémon. Wir haben immer großen Spaß!$"
#else
    .string "I can do so much with my\n"
    .string "POKéMON--it's super-fun!$"
#endif

Route43_Text_CamperSpencerBeaten:
#if GERMAN
	.string "Verlieren macht überhaupt keinen Spaß…$"
#else
    .string "Losing isn't fun at all…$"
#endif

Route43_Text_CamperSpencerAfter:
#if GERMAN
	.string "Was geht da vor sich am See des Zorns?\n"
	.string "Wir wollten eigentlich dort zelten.$"
#else
    .string "What is going on at LAKE OF RAGE?\p"
    .string "We were planning to camp there.$"
#endif

Route43_Text_PicnickerTiffanySeen:
#if GERMAN
	.string "Gehst du auch zum See des Zorns? Lust\n"
	.string "auf ein kleines Spielchen?$"
#else
    .string "Are you going to LAKE OF RAGE too?\p"
    .string "Let's play for a little while!$"
#endif

Route43_Text_PicnickerTiffanyBeaten:
#if GERMAN
	.string "Das war wohl zu viel des Guten!$"
#else
    .string "I played too much!$"
#endif

Route43_Text_PicnickerTiffanyWantsPicnic:
#if GERMAN
	.string "Ich mache ein Picknick mit meinem\n"
	.string "Pokémon. Setze dich doch zu uns.$"
#else
    .string "I'm having a picnic with POKéMON.\p"
    .string "Won't you join us?$"
#endif

Route43_Text_TiffanyRegister:
#if GERMAN
	.string "Ich mache ein Picknick mit meinem\n"
	.string "Pokémon. Setze dich doch zu uns.$"
#else
    .string "I'm having a picnic with POKéMON.\p"
    .string "Won't you join us?$"
#endif

Route43_Text_TiffanyRematchIntro:
#if GERMAN
	.string "Gehst du auch zum See des Zorns? Lust\n"
	.string "auf ein kleines Spielchen?$"
#else
    .string "Are you going to LAKE OF RAGE too?\p"
    .string "Let's play for a little while!$"
#endif

Route43_Text_TiffanyRematchDefeat:
#if GERMAN
	.string "Das war wohl zu viel des Guten!$"
#else
    .string "I played too much!$"
#endif

Route43_Text_TiffanyPostRematch:
#if GERMAN
	.string "Ich mache ein Picknick mit meinem\n"
	.string "Pokémon. Setze dich doch zu uns.$"
#else
    .string "I'm having a picnic with POKéMON.\p"
    .string "Won't you join us?$"
#endif

Route43_Sign1:
#if GERMAN
	.string "Route 43\p"
	.string "See des Zorns - Mahagonia$"
#else
    .string "ROUTE 43\p"
    .string "LAKE OF RAGE - MAHOGANY TOWN$"
#endif

Route43_Sign2:
#if GERMAN
    .string "Route 43\p"
    .string "See des Zorns - Mahagonia$"
#else
    .string "ROUTE 43\p"
    .string "LAKE OF RAGE - MAHOGANY TOWN$"
#endif

Route43_TrainerTips:
#if GERMAN
	.string "Route 43\p"
	.string "Zutritt zum Kraftwerk nur mit\n"
	.string "Genehmigung.\p"
	.string "Nach Norden: Mahagonia City.$"
#else
	.string "ROUTE 43\p"
	.string "Entry to the POWER PLANT by\n"
	.string "permit only.\p"
	.string "North: MAHOGANY TOWN.$"
#endif
