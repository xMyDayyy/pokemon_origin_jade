MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
#if GERMAN
	.string "Troy: Oh, wow, {PLAYER}{KUN}!\n"
	.string "Ich bin erstaunt, dass du mich gefunden\l"
	.string "hast!\p"
	.string "Du, äh… denkst bestimmt, ich bin nur\n"
	.string "verrückt nach Steinen, nicht wahr?\p"
	.string "Nein, das tust du bestimmt nicht.\p"
	.string "Wir haben ja schon als Team im Moosbach\n"
	.string "City Raumfahrtzentrum gekämpft.\p"
	.string "Da hast du bestimmt einen Eindruck\n"
	.string "davon gewonnen, wie gut ich bin.\p"
	.string "Okay, {PLAYER}{KUN}, wenn du dich\n"
	.string "auf eine ernsthafte Herausforderung\l"
	.string "einlässt, sei auf das Schlimmste\l"
	.string "gefasst!$"
#else
	.string "STEVEN: Oh, wow, {PLAYER}{KUN}.\n"
	.string "I'm amazed you knew where to find me.\p"
	.string "Do you, uh…maybe think of me as\n"
	.string "just a rock maniac?\p"
	.string "No, that can't be right.\p"
	.string "We battled alongside each other at\n"
	.string "the SOOTOPOLIS SPACE CENTER.\p"
	.string "You should have a very good idea\n"
	.string "about how good I am.\p"
	.string "Okay, {PLAYER}{KUN}, if you're going to mount\n"
	.string "a serious challenge, expect the worst!$"
#endif

MeteorFalls_StevensCave_Text_StevenDefeat:
#if GERMAN
	.string "Du…\p"
	.string "Ich wusste, dass du stark bist.\n"
	.string "So stark wusste ich nicht.$"
#else
	.string "You…\p"
	.string "I knew you were strong.\n"
	.string "I didn't know you were this strong.$"
#endif

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
#if GERMAN
	.string "Troy: Aber, wenn ich es recht bedenke…\p"
	.string "Schon als ich dich das erste Mal\n"
	.string "kämpfen gesehen habe, wusste ich,\l"
	.string "dass du einmal Großes erreichen\l"
	.string "wirst.\p"
	.string "Und mein Gefühl trügt mich nie!\p"
	.string "Wohin wird dein Weg dich jetzt führen?\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…\p"
	.string "Hähähähä, das kann selbst ich dir\n"
	.string "nicht sagen.$"
#else
	.string "STEVEN: Come to think of it…\p"
	.string "The first time I ever saw you battle,\n"
	.string "I knew you'd achieve great things.\p"
	.string "My predictions usually come true.\p"
	.string "And where will you go from here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, even I couldn't tell you that.$"
#endif

