MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
#if GERMAN
	.string "Dort trainieren wir Drachen-besitzer…\p"
	.string "Auch der Champ kommt manchmal vorbei.\n"
	.string "Verstehst du nun, dass dies ein\l"
	.string "besonderer Ort ist?$"
#else
	.string "This is where we DRAGON users do our\n"
	.string "training.\p"
	.string "The CHAMPION even visits.\n"
	.string "Now do you see how special it is here?$"
#endif

MeteorFalls_1F_2R_Text_NicolasDefeat:
#if GERMAN
	.string "Argh!\n"
	.string "Ich hätte nicht gedacht, dass du so\l"
	.string "stark bist!$"
#else
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"
#endif

MeteorFalls_1F_2R_Text_NicolasPostBattle:
#if GERMAN
	.string "Der Weg vor mir ist lang und\n"
	.string "beschwerlich.\p"
	.string "Wann werden meine Pokémon und ich\n"
	.string "zu den Besten gehören?$"
#else
	.string "The road ahead remains long and harsh.\p"
	.string "When will my POKéMON and I become\n"
	.string "the best?$"
#endif

MeteorFalls_1F_2R_Text_NicolasRegister:
#if GERMAN
	.string "Von dir möchte ich noch mehr erfahren.\n"
	.string "Ich trage dich in meinen PokéCom ein.$"
#else
	.string "I want to know more about your power.\n"
	.string "Let me register you in my POKéGEAR.$"
#endif

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
#if GERMAN
	.string "Seit wir uns das letzte Mal gesehen\n"
	.string "haben, haben wir hart trainiert\l"
	.string "verglichen mit unserem ersten Kampf.\p"
	.string "Hilf uns, herauszufinden, wie stark\n"
	.string "wir wirklich sind.$"
#else
	.string "Since we met, we have trained hard\n"
	.string "with our sights on number one.\p"
	.string "Help us see how much stronger we've\n"
	.string "become!$"
#endif

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
#if GERMAN
	.string "Argh! Wie kannst du nur so stark sein?$"
#else
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"
#endif

MeteorFalls_1F_2R_Text_NicolasPostRematch:
#if GERMAN
	.string "Du hast offenbar fleißig trainiert.\p"
	.string "Solange du stärker wirst, kann auch\n"
	.string "ich stärker werden.$"
#else
	.string "You've obviously kept up your\n"
	.string "POKéMON training.\p"
	.string "So long as you remain strong, I, too,\n"
	.string "can become stronger!$"
#endif

MeteorFalls_1F_2R_Text_JohnIntro:
#if GERMAN
	.string "Urs: Wir haben immer in trauter\n"
	.string "Zweisamkeit mit unseren Pokémon gegen\l"
	.string "andere gekämpft. Wir werden siegen!$"
#else
	.string "JOHN: We've always battled POKéMON\n"
	.string "together as a twosome.\l"
	.string "We've confidence in ourselves.$"
#endif

MeteorFalls_1F_2R_Text_JohnDefeat:
#if GERMAN
	.string "Urs: O weh.\n"
	.string "Wir haben verloren, liebstes Weib.$"
#else
	.string "JOHN: Oh, my.\n"
	.string "We've lost, dear wife.$"
#endif

MeteorFalls_1F_2R_Text_JohnPostBattle:
#if GERMAN
	.string "Urs: Wir sind seit 50 Jahren glücklich\n"
	.string "verheiratet.\p"
	.string "Und denk mal, ich habe es noch nie ge-\n"
	.string "schafft, meine Frau zu besiegen.$"
#else
	.string "JOHN: We've been married for\n"
	.string "fifty years.\p"
	.string "Come to think of it, I've yet to beat\n"
	.string "my dear wife in a battle.$"
#endif

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
#if GERMAN
	.string "Urs: Nun, was für ein junger Trainer!\p"
	.string "Möchtest du mit uns kämpfen? Wenn ja,\n"
	.string "dann musst du dir noch mehr Pokémon\l"
	.string "besorgen.$"
#else
	.string "JOHN: Well, well, what a young TRAINER!\p"
	.string "Will you battle with us? If so, you'll\n"
	.string "have to return with more POKéMON.$"
#endif

MeteorFalls_1F_2R_Text_JohnRegister:
#if GERMAN
	.string "Urs: Junger Trainer! Wenn du die Chance\n"
	.string "hast, wirst du wieder gegen uns\l"
	.string "antreten?$"
#else
	.string "JOHN: Young TRAINER, if the chance\n"
	.string "arises, will you battle with us again?$"
#endif

MeteorFalls_1F_2R_Text_JayIntro:
#if GERMAN
	.string "Evi: Wir sind seit 50 Jahren glücklich\n"
	.string "verheiratet.\p"
	.string "Das Band, das uns verbindet, kann\n"
	.string "niemand durchtrennen.$"
#else
	.string "JAY: We've been married for\n"
	.string "fifty years.\p"
	.string "The bond we share as a couple could\n"
	.string "never be broken.$"
#endif

MeteorFalls_1F_2R_Text_JayDefeat:
#if GERMAN
	.string "Evi: O weh.\n"
	.string "Wir haben verloren, mein Lieber.$"
#else
	.string "JAY: Oh, dear.\n"
	.string "We've lost, my dear husband.$"
#endif

MeteorFalls_1F_2R_Text_JayPostBattle:
#if GERMAN
	.string "Evi: 50 Jahre verheiratet…\p"
	.string "Immer wenn wir uneinig sind,\n"
	.string "entscheiden wir es mit einem\l"
	.string "Pokémon-Kampf.$"
#else
	.string "JAY: Fifty years of marriage…\p"
	.string "If we ever argued, we always settled\n"
	.string "it with a POKéMON battle…$"
#endif

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
#if GERMAN
	.string "Evi: Hmm… Bist du nicht ein bisschen\n"
	.string "zu klein für einen Trainer?\p"
	.string "Möchtest du mit uns kämpfen? Dann\n"
	.string "musst du dir noch mehr Pokémon\l"
	.string "besorgen.$"
#else
	.string "JAY: Well, well, aren't you a young\n"
	.string "TRAINER?\p"
	.string "If you'd care to battle with us, you'll\n"
	.string "have to come back with more POKéMON.$"
#endif

MeteorFalls_1F_2R_Text_JohnRematchIntro:
#if GERMAN
	.string "Urs: Wir haben immer in trauter\n"
	.string "Zweisamkeit mit unseren Pokémon gegen\l"
	.string "andere gekämpft. Wir werden siegen!$"
#else
	.string "JOHN: We've always battled POKéMON\n"
	.string "together as a twosome.\l"
	.string "We've confidence in ourselves.$"
#endif

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
#if GERMAN
	.string "Urs: O weh.\n"
	.string "Wir haben verloren, liebstes Weib.$"
#else
	.string "JOHN: Oh, my.\n"
	.string "We've lost, dear wife.$"
#endif

MeteorFalls_1F_2R_Text_JohnPostRematch:
#if GERMAN
	.string "Urs: 50 Jahre verheiratet…\p"
	.string "Rückblickend kann man sagen: Meine\n"
	.string "Frau und ich haben Tag für Tag\l"
	.string "miteinander gekämpft…$"
#else
	.string "JOHN: Married for fifty years…\p"
	.string "On reflection, the dear wife and I,\n"
	.string "we battled day in and day out…$"
#endif

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
#if GERMAN
	.string "Urs: Nun, was für ein junger Trainer!\p"
	.string "Möchtest du mit uns kämpfen? Wenn ja,\n"
	.string "dann musst du dir noch mehr Pokémon\l"
	.string "besorgen.$"
#else
	.string "JOHN: Well, well, what a young TRAINER!\p"
	.string "Will you battle with us? If so, you'll\n"
	.string "have to return with more POKéMON.$"
#endif

MeteorFalls_1F_2R_Text_JayRematchIntro:
#if GERMAN
	.string "Evi: Wir sind seit 50 Jahren verheiratet.\p"
	.string "Wir haben uns immer gegenseitig unter-\n"
	.string "stützt. Das hat uns stark gemacht.$"
#else
	.string "JAY: We've been married for\n"
	.string "fifty years.\p"
	.string "We've supported each other all that\n"
	.string "time. We've made ourselves strong.$"
#endif

MeteorFalls_1F_2R_Text_JayRematchDefeat:
#if GERMAN
	.string "Evi: O weh.\n"
	.string "Wir haben verloren, mein Lieber.$"
#else
	.string "JAY: Oh, dear.\n"
	.string "We've lost, my dear husband.$"
#endif

MeteorFalls_1F_2R_Text_JayPostRematch:
#if GERMAN
	.string "Evi: 50 Jahre verheiratet…\n"
	.string "Vieles ist in dieser Zeit passiert.\p"
	.string "Ich hoffe, wir werden noch lange unsere\n"
	.string "Erinnerungen miteinander teilen\l"
	.string "können.$"
#else
	.string "JAY: Fifty years of marriage…\n"
	.string "Many things have happened.\p"
	.string "I hope that we will continue to make\n"
	.string "happy memories together.$"
#endif

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
#if GERMAN
	.string "Evi: Hmm… Bist du nicht ein bisschen\n"
	.string "zu klein für einen Trainer?\p"
	.string "Möchtest du gegen uns kämpfen? Dann\n"
	.string "musst du dir noch mehr Pokémon\l"
	.string "besorgen.$"
#else
	.string "JAY: Well, well, aren't you a young\n"
	.string "TRAINER?\p"
	.string "If you'd care to battle with us, you'll\n"
	.string "have to come back with more POKéMON.$"
#endif

