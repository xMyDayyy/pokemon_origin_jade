Route44_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route44_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route44_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON_HNS, Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten, Route44_EventScript_RegisterWilton
	goto_if_set FLAG_WILTON_HAS_ITEM_HNS, Route44_EventScript_WiltonGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchWilton
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterWilton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_HNS
	release
	end

Route44_EventScript_RematchWilton::
	trainerbattle_rematch TRAINER_WILTON_HNS, Route44_Text_WiltonRematchIntro, Route44_Text_WiltonRematchDefeat
	msgbox Route44_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonGiveItem::
	msgbox Route44_Text_WiltonHasItem, MSGBOX_DEFAULT
	giveitem VAR_WILTON_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route44_EventScript_WiltonNoRoom
	clearflag FLAG_WILTON_HAS_ITEM_HNS
	msgbox Route44_Text_WiltonGaveItem, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonNoRoom::
	msgbox Route44_Text_WiltonNoRoom, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR_HNS, Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Vance::
	trainerbattle_single TRAINER_VANCE_HNS, Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten, Route44_EventScript_RegisterVance
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchVance
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterVance::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_VanceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VANCE_HNS
	release
	end

Route44_EventScript_RematchVance::
	trainerbattle_rematch TRAINER_VANCE_HNS, Route44_Text_VanceRematchIntro, Route44_Text_VanceRematchDefeat
	msgbox Route44_Text_VancePostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL_HNS, Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH_HNS, Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN_HNS, Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Cybil::
	trainerbattle_single TRAINER_CYBIL_HNS, Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_EventScript_Item_MaxRepel::
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route44_Text_FisherWilton1Seen:
#if GERMAN
	.string "Oh nein! Na, besten Dank! Jetzt ist mir\n"
	.string "das Quapsel durch die Lappen gegangen!\l"
	.string "Das schreit nach Genugtuung!$"
#else
    .string "Aack!\p"
    .string "You made me lose a POLIWAG!\n"
    .string "What are you going to do about it?$"
#endif

Route44_Text_FisherWilton1Beaten:
#if GERMAN
	.string "Mir reicht’s langsam…$"
#else
    .string "Just forget about it.$"
#endif

Route44_Text_FisherWiltonHugePoliwag:
#if GERMAN
	.string "Dieses Quapsel, das geflohen ist… Das\n"
	.string "war riesig.\p"
	.string "Ich könnte schwören, dass es 5 Meter\n"
	.string "lang war!$"
#else
    .string "That POLIWAG that got away…\n"
    .string "it was huge.\p"
    .string "I swear it must've been\n"
    .string "16 feet long!$"
#endif

Route44_Text_WiltonRegister:
#if GERMAN
    .string "Das Quaputzi, das mir entkommen ist…\n"
    .string "es war riesig.\p"
    .string "Ich schwöre, es muss über 5 Meter groß\n"
    .string "gewesen sein!$"
#else
    .string "That POLIWAG that got away…\n"
    .string "it was huge.\p"
    .string "I swear it must've been\n"
    .string "16 feet long!$"
#endif

Route44_Text_WiltonRematchIntro:
#if GERMAN
	.string "Oh nein! Na, besten Dank! Jetzt ist mir\n"
	.string "das Quapsel durch die Lappen gegangen!\l"
	.string "Das schreit nach Genugtuung!$"
#else
    .string "Aack!\p"
    .string "You made me lose a POLIWAG!\n"
    .string "What are you going to do about it?$"
#endif

Route44_Text_WiltonRematchDefeat:
#if GERMAN
	.string "Mir reicht’s langsam…$"
#else
    .string "Just forget about it.$"
#endif

Route44_Text_WiltonPostRematch:
#if GERMAN
    .string "Das Quaputzi, das mir entkommen ist…\n"
    .string "es war riesig.\p"
    .string "Ich schwöre, es muss über 5 Meter groß\n"
    .string "gewesen sein!$"
#else
    .string "That POLIWAG that got away…\n"
    .string "it was huge.\p"
    .string "I swear it must've been\n"
    .string "16 feet long!$"
#endif

Route44_Text_WiltonHasItem:
#if GERMAN
    .string "Hey! Ich habe etwas anderes als\n"
    .string "ein Pokémon an Land gezogen!\p"
    .string "Hier, du kannst es haben!$"
#else
    .string "Hey! I reeled in something\n"
    .string "other than a POKéMON!\p"
    .string "Here, you can have it!$"
#endif

Route44_Text_WiltonGaveItem:
#if GERMAN
    .string "Ich sage dir Bescheid, wenn ich\n"
    .string "noch etwas aus dem Wasser ziehe!$"
#else
    .string "I'll let you know if I\n"
    .string "fish up anything else!$"
#endif

Route44_Text_WiltonNoRoom:
#if GERMAN
    .string "Hm, dein Beutel ist voll.\p"
    .string "Komm wieder, wenn du Platz hast.$"
#else
    .string "Hmm, your BAG is full.\p"
    .string "Come back when you have room.$"
#endif

Route44_Text_FisherEdgarSeen:
#if GERMAN
	.string "Ich angele so lange, bis ich nicht mehr\n"
	.string "kann, und ich kämpfe bis zum Umfallen!\l"
	.string "So handhabe ich das mit meinen Pokémon!$"
#else
    .string "I fish until I can't anymore.\p"
    .string "I also battle until I drop.\p"
    .string "That's my relationship with my\n"
    .string "POKéMON.$"
#endif

Route44_Text_FisherEdgarBeaten:
#if GERMAN
	.string "Hmm… Irgendwas ist schiefgelaufen.$"
#else
    .string "Hmmmm… This isn't right.$"
#endif

Route44_Text_FisherEdgarAfter:
#if GERMAN
	.string "Das macht dann 100 Siege und 101\n"
	.string "verlorene Kämpfe.\p"
	.string "Ich höre besser eine Weile mit dem\n"
	.string "Kämpfen auf.$"
#else
    .string "That's 100 wins to 101 losses.\p"
    .string "I won't battle again for a while.$"
#endif

Route44_Text_BirdKeeperVance1Seen:
#if GERMAN
	.string "Hast du schon von den Legendären\n"
	.string "Vogel-Pokémon gehört?$"
#else
    .string "Do you know about the legendary\n"
    .string "bird POKéMON?$"
#endif

Route44_Text_BirdKeeperVance1Beaten:
#if GERMAN
	.string "Puh! Du machst echt keine halben\n"
	.string "Sachen.$"
#else
    .string "Whew! You're hot stuff.$"
#endif

Route44_Text_BirdKeeperVanceBirds:
#if GERMAN
	.string "Man sagt, es gebe drei Arten von\n"
	.string "Legendären Vogel-Pokémon. Arktos,\l"
	.string "Zapdos und Lavados.\p"
	.string "Aber so, wie es aussieht, gibt es noch\n"
	.string "viel mehr als nur diese drei.$"
#else
    .string "ARTICUNO, ZAPDOS and MOLTRES are\n"
    .string "the three legendary bird POKéMON.\p"
    .string "I heard there are other legendary\n"
    .string "birds, though.$"
#endif

Route44_Text_VanceRegister:
#if GERMAN
	.string "Man sagt, es gebe drei Arten von\n"
	.string "Legendären Vogel-Pokémon. Arktos,\l"
	.string "Zapdos und Lavados.\p"
	.string "Aber so, wie es aussieht, gibt es noch\n"
	.string "viel mehr als nur diese drei.$"
#else
    .string "ARTICUNO, ZAPDOS and MOLTRES are\n"
    .string "the three legendary bird POKéMON.\p"
    .string "I heard there are other legendary\n"
    .string "birds, though.$"
#endif

Route44_Text_VanceRematchIntro:
#if GERMAN
	.string "Hast du schon von den Legendären\n"
	.string "Vogel-Pokémon gehört?$"
#else
    .string "Do you know about the legendary\n"
    .string "bird POKéMON?$"
#endif

Route44_Text_VanceRematchDefeat:
#if GERMAN
	.string "Puh! Du machst echt keine halben\n"
	.string "Sachen.$"
#else
    .string "Whew! You're hot stuff.$"
#endif

Route44_Text_VancePostRematch:
#if GERMAN
	.string "Man sagt, es gebe drei Arten von\n"
	.string "Legendären Vogel-Pokémon. Arktos,\l"
	.string "Zapdos und Lavados.\p"
	.string "Aber so, wie es aussieht, gibt es noch\n"
	.string "viel mehr als nur diese drei.$"
#else
    .string "ARTICUNO, ZAPDOS and MOLTRES are\n"
    .string "the three legendary bird POKéMON.\p"
    .string "I heard there are other legendary\n"
    .string "birds, though.$"
#endif

Route44_Text_PsychicPhilSeen:
#if GERMAN
	.string "Ich werde gewinnen! Hundertprozentig!$"
#else
    .string "I'm gonna win, for sure!$"
#endif

Route44_Text_PsychicPhilBeaten:
#if GERMAN
	.string "Aaah! Eine schockierende Niederlage!$"
#else
    .string "Arrgh… That's a shocking loss…$"
#endif

Route44_Text_PsychicPhilAfter:
#if GERMAN
    .string "Es ist wichtig, von sich selbst\n"
    .string "überzeugt zu sein.$"
#else
    .string "It's important to have conviction\n"
    .string "on your side.$"
#endif

Route44_Text_PokemaniacZachSeen:
#if GERMAN
	.string "Ich tue alles, um seltene Pokémon in die\n"
	.string "Finger zu kriegen!$"
#else
    .string "I'll do anything to get my hands\n"
    .string "on rare POKéMON!$"
#endif

Route44_Text_PokemaniacZachBeaten:
#if GERMAN
	.string "Seufz… so ein tolles Pokémon-Team\n"
	.string "hätte ich auch gern!$"
#else
    .string "Oooh, your POKéMON are so\n"
    .string "appealing.$"
#endif

Route44_Text_PokemaniacZachAfter:
#if GERMAN
    .string "Wenn ein Pokémon andere Farben als\n"
    .string "üblich hat, ist es wertvoller.\p"
    .string "Was? Du meinst, das stimmt nicht?$"
#else
    .string "If a POKéMON has different colors\n"
    .string "from usual, it's more valuable.\p"
    .string "What? You mean that's not true?$"
#endif

Route44_Text_CooltrainermAllenSeen:
#if GERMAN
	.string "Man sieht schon an deinem Auftreten,\n"
	.string "dass du ein guter Trainer bist!\p"
	.string "Ich kenne mich gut mit Pokémon aus,\n"
	.string "dafür habe ich einen Blick entwickelt.$"
#else
    .string "I can tell you're a good trainer\n"
    .string "by looking at you.\p"
    .string "I'm good at POKéMON, and I can\n"
    .string "see that you are too.$"
#endif

Route44_Text_CooltrainermAllenBeaten:
#if GERMAN
	.string "Puh! Das war ja der totale Reinfall!$"
#else
    .string "Tch! It's a total loss on my part.$"
#endif

Route44_Text_CooltrainermAllenAfter:
#if GERMAN
	.string "Wow, hast du viele Orden! Kein Wunder,\n"
	.string "dass du so stark bist.\p"
	.string "Möchte wissen, ob Jens, der Arenaleiter\n"
	.string "von Teak City, noch immer trainiert? Der\l"
	.string "hat mich wirklich plattgemacht.$"
#else
    .string "Wow. You have a lot of BADGES.\p"
    .string "No wonder you're so tough.\p"
    .string "I wonder if ECRUTEAK GYM's MORTY\n"
    .string "is still in training?\p"
    .string "He really hammered me.$"
#endif

Route44_Text_CooltrainerfCybilSeen:
#if GERMAN
	.string "Du siehst sehr stark aus.\p"
	.string "Gute Trainer suchen instinktiv nach\n"
	.string "starken Gegnern.$"
#else
    .string "You look strong.\p"
    .string "Good trainers seek tough\n"
    .string "opponents instinctively.$"
#endif

Route44_Text_CooltrainerfCybilBeaten:
#if GERMAN
	.string "Nein! So geht das auf gar keinen Fall.$"
#else
    .string "Nope! This won't do at all.$"
#endif

Route44_Text_CooltrainerfCybilAfter:
#if GERMAN
	.string "Mit den Kämpfen steigt unsere\n"
	.string "Erfahrung und wir werden besser.\p"
	.string "Ich habe viele Kämpfe ausgetragen, um\n"
	.string "zu werden, was ich heute bin - ein Profi.$"
#else
    .string "We all get better by experiencing\n"
    .string "many battles.\p"
    .string "I battled a lot to become what I\n"
    .string "am today--an elite.$"
#endif

Route44_Text_Sign1:
#if GERMAN
	.string "Route 44 Eispfad voraus$"
#else
    .string "ROUTE 44\n"
    .string "ICE PATH AHEAD$"
#endif

Route44_Text_Sign2:
#if GERMAN
	.string "Route 44\p"
	.string "Mahagonia City - Ebenholz City$"
#else
    .string "ROUTE 44\p"
    .string "MAHOGANY TOWN - BLACKTHORN CITY$"
#endif

