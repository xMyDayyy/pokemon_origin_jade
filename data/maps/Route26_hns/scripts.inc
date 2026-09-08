Route26_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE_HNS, Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN_HNS, Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten, Route26_EventScript_RegisterGaven
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchGaven
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterGaven::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_GavenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GAVEN_HNS
	release
	end

Route26_EventScript_RematchGaven::
	trainerbattle_rematch TRAINER_GAVEN_HNS, Route26_Text_GavenRematchIntro, Route26_Text_GavenRematchDefeat
	msgbox Route26_Text_GavenPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE_HNS, Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH_HNS, Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten, Route26_EventScript_RegisterBeth
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchBeth
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterBeth::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_BethRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BETH_HNS
	release
	end

Route26_EventScript_RematchBeth::
	trainerbattle_rematch TRAINER_BETH_HNS, Route26_Text_BethRematchIntro, Route26_Text_BethRematchDefeat
	msgbox Route26_Text_BethPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD_HNS, Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
#if GERMAN
	.string "Ich treffe die letzten Vorbereitungen\n"
	.string "für die Pokémon Liga.$"
#else
    .string "I'm making my final preparations\n"
    .string "for the POKéMON LEAGUE.$"
#endif

Route26_Text_CooltrainermJakeBeaten:
#if GERMAN
	.string "Ich habe es vermasselt!$"
#else
    .string "I blew it!$"
#endif

Route26_Text_CooltrainermJakeAfter:
#if GERMAN
	.string "Ich muss mehr trainieren, sonst gewinne\n"
	.string "ich niemals einen Ligakampf.\p"
	.string "Ich habe gehört, dass die Top Vier der\n"
	.string "Liga noch stärker sind als die\l"
	.string "Arenaleiter!$"
#else
    .string "It's going to be tough to win at\n"
    .string "the LEAGUE.\p"
    .string "I need to do some more training.\p"
    .string "I hear that the LEAGUE's ELITE\n"
    .string "FOUR are tougher than GYM LEADERS.$"
#endif

Route26_Text_CooltrainermGavenSeen:
#if GERMAN
	.string "Nur wenn du harte Kämpfe bestreitest,\n"
	.string "zeigt sich deine wahre Stärke.$"
#else
    .string "By experiencing tough battles, you\n"
    .string "gain power.$"
#endif

Route26_Text_CooltrainermGavenBeaten:
#if GERMAN
	.string "Gah! Das Leben ist noch härter!$"
#else
    .string "Gaah! Life is even tougher!$"
#endif

Route26_Text_CooltrainermGavenAfter:
#if GERMAN
	.string "Du kommst also von drüben, aus\n"
	.string "Kanto.\p"
	.string "Dann hast du die Siegesstraße hinter\n"
	.string "dir. Ich habe es nie so weit\l"
	.string "geschafft.\p"
	.string "Umso mehr freut mich der Kampf.$"
#else
	.string "So you have come over from KANTO.\p"
	.string "Then VICTORY ROAD is behind you.\n"
	.string "I never made it that far myself.\p"
	.string "All the more reason I enjoyed our\n"
	.string "battle.$"
#endif

Route26_Text_GavenRegister:
#if GERMAN
	.string "Ich habe es nie bis zur Liga\n"
	.string "geschafft.\p"
	.string "Aber gegen jemanden wie dich zu\n"
	.string "kämpfen, ist auch etwas wert.$"
#else
	.string "I never made it to the LEAGUE\n"
	.string "myself.\p"
	.string "But battling someone like you is\n"
	.string "worth something too.$"
#endif

Route26_Text_GavenRematchIntro:
#if GERMAN
	.string "Nur wenn du harte Kämpfe bestreitest,\n"
	.string "zeigt sich deine wahre Stärke.$"
#else
    .string "By experiencing tough battles, you\n"
    .string "gain power.$"
#endif

Route26_Text_GavenRematchDefeat:
#if GERMAN
    .string "Aaah! Das Leben ist noch härter!$"
#else
    .string "Gaah! Life is even tougher!$"
#endif

Route26_Text_GavenPostRematch:
#if GERMAN
	.string "Um zur Pokémon Liga zu kommen,\n"
	.string "musst du durch die Siegesstraße.\p"
	.string "Aber die Siegesstraße hat es in\n"
	.string "sich.\p"
	.string "Fast niemand wagt sich dorthin!$"
#else
    .string "To get to POKéMON LEAGUE, you have\n"
    .string "to get through VICTORY ROAD.\p"
    .string "But VICTORY ROAD is tough.\p"
    .string "Practically nobody goes there!$"
#endif

Route26_Text_CooltrainerfJoyceSeen:
#if GERMAN
	.string "Da du es bis hierher geschafft hast,\n"
	.string "musst du gut sein.\p"
	.string "Also werde auch ich in diesem Kampf\n"
	.string "alles geben!$"
#else
    .string "Since you've come this far,\n"
    .string "you must be good.\p"
    .string "I'm going to give this battle\n"
    .string "everything I've got!$"
#endif

Route26_Text_CooltrainerfJoyceBeaten:
#if GERMAN
	.string "Donnerwetter! Jetzt bin ich aber platt!$"
#else
    .string "No! I don't believe this!$"
#endif

Route26_Text_CooltrainerfJoyceAfter:
#if GERMAN
	.string "Ich habe alle acht Arenaleiter besiegt\n"
	.string "und war mir meiner Sache so sicher…\p"
	.string "Ich muss mich mehr ins Zeug legen!$"
#else
    .string "I've defeated eight GYM LEADERS,\n"
    .string "so I was feeling confident.\p"
    .string "I'll have to try harder next time.$"
#endif

Route26_Text_CooltrainerfBethSeen:
#if GERMAN
	.string "Ich habe gegen einen Trainer\n"
	.string "namens {RIVAL} verloren.\p"
	.string "Er war sehr stark, aber…\n"
	.string "Es schien, als sei er um jeden Preis auf\l"
	.string "den Sieg aus.\p"
	.string "Seine Pokémon taten mir leid.$"
#else
    .string "I lost to a trainer named {RIVAL}.\p"
    .string "He was really strong, but…\p"
    .string "It was as if he absolutely had to\n"
    .string "win at any cost.\p"
    .string "I felt sorry for his POKéMON.$"
#endif

Route26_Text_CooltrainerfBethBeaten:
#if GERMAN
	.string "Ich sag’s doch: Pokémon sind keine\n"
	.string "Kampfwerkzeuge.$"
#else
    .string "POKéMON aren't tools of war.$"
#endif

Route26_Text_CooltrainerfBethAfter:
#if GERMAN
	.string "Pokémon sind unschätzbare,\n"
	.string "lebenslange Partner.$"
#else
    .string "POKéMON are in-valuable, lifelong\n"
    .string "partners.$"
#endif

Route26_Text_BethRegister:
#if GERMAN
	.string "Pokémon sind unschätzbare,\n"
	.string "lebenslange Partner.$"
#else
    .string "POKéMON are invaluable, lifelong\n"
    .string "partners.$"
#endif

Route26_Text_BethRematchIntro:
#if GERMAN
    .string "Ich habe gegen einen Trainer namens\n"
    .string "{RIVAL} verloren.\p"
    .string "Aber gegen dich verliere ich nicht!$"
#else
    .string "I lost to a trainer named {RIVAL}.\p"
    .string "But I won't lose to you!$"
#endif

Route26_Text_BethRematchDefeat:
#if GERMAN
	.string "Ich sag’s doch: Pokémon sind keine\n"
	.string "Kampfwerkzeuge.$"
#else
    .string "POKéMON aren't tools of war.$"
#endif

Route26_Text_BethPostRematch:
#if GERMAN
	.string "Pokémon sind unschätzbare,\n"
	.string "lebenslange Partner.$"
#else
    .string "POKéMON are invaluable, lifelong\n"
    .string "partners.$"
#endif

Route26_Text_PsychicRichardSeen:
#if GERMAN
	.string "Wow, sieh dir all die Orden an! Ich bin\n"
	.string "beeindruckt.\p"
	.string "Aber mit denen alleine scheinst du dich\n"
	.string "noch nicht zufrieden zu geben, was?$"
#else
    .string "Wow, look at all those BADGES!\n"
    .string "I'm impressed.\p"
    .string "But you're not satisfied by just\n"
    .string "collecting them, right?$"
#endif

Route26_Text_PsychicRichardBeaten:
#if GERMAN
	.string "Das war ein guter Kampf!$"
#else
    .string "Good battle!$"
#endif

Route26_Text_PsychicRichardAfter:
#if GERMAN
	.string "Menschen und Pokémon wachsen beide an\n"
	.string "ihren Erfahrungen.\p"
	.string "Du darfst nicht faul und selbstgefällig\n"
	.string "werden.$"
#else
    .string "People and POKéMON grow from their\n"
    .string "experiences.\p"
    .string "Don't get lazy and complacent.$"
#endif

Route26_Text_Sign:
#if GERMAN
	.string "Route 26\p"
	.string "Pokémon Liga Empfang$"
#else
    .string "ROUTE 26\p"
    .string "POKéMON LEAGUE\n"
    .string "RECEPTION GATE$"
#endif

