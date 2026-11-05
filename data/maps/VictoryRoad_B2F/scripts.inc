VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
#if GERMAN
	.string "Ich habe mit meiner Familie trainiert,\n"
	.string "mit jedem einzelnen Mitglied!\l"
	.string "Ich verliere gegen niemanden!$"
#else
	.string "I trained together with my whole family,\n"
	.string "every one of us!\l"
	.string "I'm not losing to anyone!$"
#endif

VictoryRoad_B2F_Text_VitoDefeat:
#if GERMAN
	.string "Besser als meine Familie?\n"
	.string "Ist das möglich?$"
#else
	.string "Better than my family?!\n"
	.string "Is that possible?!$"
#endif

VictoryRoad_B2F_Text_VitoPostBattle:
#if GERMAN
	.string "Ich war besser als jeder andere aus\n"
	.string "meiner Familie. Ich habe nie verloren!\p"
	.string "Ich habe mein Selbstvertrauen ver-\n"
	.string "loren. Ich gehe nach Hause…$"
#else
	.string "I was better than everyone in my\n"
	.string "family. I've never lost before…\p"
	.string "I've lost my confidence…\n"
	.string "Maybe I'll go home…$"
#endif

VictoryRoad_B2F_Text_OwenIntro:
#if GERMAN
	.string "Ich habe gehört, dass sich hier ein sehr\n"
	.string "starkes Kind herumtreibt. Bist du das?$"
#else
	.string "I'd heard that there was a tough\n"
	.string "little kid around. Do they mean you?$"
#endif

VictoryRoad_B2F_Text_OwenDefeat:
#if GERMAN
	.string "Diese kleine Kröte ist echt stark!$"
#else
	.string "The little shrimp is tough!$"
#endif

VictoryRoad_B2F_Text_OwenPostBattle:
#if GERMAN
	.string "Das Gerücht sagt, das Kind käme aus\n"
	.string "Blütenburg City.$"
#else
	.string "The rumors I heard, that tough little\n"
	.string "kid is from PETALBURG CITY.$"
#endif

VictoryRoad_B2F_Text_CarolineIntro:
#if GERMAN
	.string "Du musst doch langsam mal müde werden.$"
#else
	.string "You must be getting a little tired.$"
#endif

VictoryRoad_B2F_Text_CarolineDefeat:
#if GERMAN
	.string "Keine Anzeichen von Müdigkeit…$"
#else
	.string "No signs of tiring at all!$"
#endif

VictoryRoad_B2F_Text_CarolinePostBattle:
#if GERMAN
	.string "Die Siegesstraße und die Pokémon\n"
	.string "Liga sind große und langwierige Heraus-\l"
	.string "forderungen. Werde bloß nicht müde!!!$"
#else
	.string "VICTORY ROAD and the POKéMON LEAGUE\n"
	.string "are long and grueling challenges.\l"
	.string "Beware of fatigue!$"
#endif

VictoryRoad_B2F_Text_JulieIntro:
#if GERMAN
	.string "Du solltest nicht selbstzufrieden\n"
	.string "werden, nur weil du viele Orden der\l"
	.string "Arenen besitzt.\p"
	.string "Es wird immer jemanden geben, der\n"
	.string "besser ist als du!$"
#else
	.string "You shouldn't get complacent just\n"
	.string "because you have a lot of GYM BADGES.\p"
	.string "There's always going to be someone\n"
	.string "who's better than you!$"
#endif

VictoryRoad_B2F_Text_JulieDefeat:
#if GERMAN
	.string "Du bist besser als ich!$"
#else
	.string "You're better than me!$"
#endif

VictoryRoad_B2F_Text_JuliePostBattle:
#if GERMAN
	.string "Schau dir deine Orden an - erinnere dich\n"
	.string "an die Trainer, die du getroffen hast.$"
#else
	.string "Gaze on your collected BADGES and\n"
	.string "remember the TRAINERS you've faced.$"
#endif

VictoryRoad_B2F_Text_FelixIntro:
#if GERMAN
	.string "Ich bin weit gekommen, aber die\n"
	.string "Anspannung verursacht mir\l"
	.string "Magenschmerzen…$"
#else
	.string "I've come this far, but the tension's\n"
	.string "giving me awful stomach pain…$"
#endif

VictoryRoad_B2F_Text_FelixDefeat:
#if GERMAN
	.string "Ooh… Es tut weh…$"
#else
	.string "Ooh…\n"
	.string "It hurts…$"
#endif

VictoryRoad_B2F_Text_FelixPostBattle:
#if GERMAN
	.string "Ich kann nicht anders. Hier in der Nähe\n"
	.string "der Pokémon Liga bin ich total nervös\l"
	.string "und angespannt.\p"
	.string "Ich tue so, als sei ich die Ruhe\n"
	.string "selbst.$"
#else
	.string "I can't help getting all tense knowing\n"
	.string "that I'm nearing the POKéMON LEAGUE.\p"
	.string "It's all I can do to feign calm.$"
#endif

VictoryRoad_B2F_Text_DianneIntro:
#if GERMAN
	.string "Die Elite der Elite versammelt sich in\n"
	.string "dieser Höhle.\p"
	.string "Wie findest du das?$"
#else
	.string "The elite among the elite gather in\n"
	.string "this cave.\p"
	.string "How are you finding it?$"
#endif

VictoryRoad_B2F_Text_DianneDefeat:
#if GERMAN
	.string "Nicht ein bisschen erschüttert.$"
#else
	.string "Not rattled in the least bit!$"
#endif

VictoryRoad_B2F_Text_DiannePostBattle:
#if GERMAN
	.string "Du hast echt Nerven! Das mag ich!\n"
	.string "Mach weiter so!$"
#else
	.string "You do have guts! I like that!\n"
	.string "Keep it going!$"
#endif

