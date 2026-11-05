SlowpokeWell_B1F_hns_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21_HNS, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22_HNS, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_HNS, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1_HNS, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE_HNS, 15, 4
	waitstate
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
#if GERMAN
	.string "Kurt: Oh, du bist es, {PLAYER}.\p"
	.string "Die Wache oben hat sofort das Weite\n"
	.string "gesucht, als ich sie zusammengeschrien\l"
	.string "habe…\p"
	.string "Aber ich bin in den Brunnen gefallen und\n"
	.string "habe mir die Hüfte geprellt.\l"
	.string "Tja, und jetzt sitze ich hier fest.\p"
	.string "Verflixt… wenn ich nur laufen könnte,\n"
	.string "würde ich diese Typen mit meinen\l"
	.string "Pokémon zu Kleinholz verarbeiten…\p"
	.string "Aber es nützt nichts, {PLAYER}!\n"
	.string "Du wirst ihnen an meiner Stelle zeigen\l"
	.string "müssen, was ein wahrer Trainer ist!$"
#else
	.string "KURT: Hey there, {PLAYER}!\p"
	.string "The guard up top took off when\n"
	.string "I shouted at him.\p"
	.string "But then I took a tumble down\n"
	.string "the WELL.\p"
	.string "I slammed down hard on my back,\n"
	.string "so I can't move.\p"
	.string "Rats! If I were fit, my POKéMON\n"
	.string "would've punished them…\p"
	.string "Ah, it can't be helped.\p"
	.string "{PLAYER}, show them how gutsy\n"
	.string "you are in my place!$"
#endif

SlowpokeWell_B1F_Text_KurtAfter:
#if GERMAN
	.string "Kurt: Gute Arbeit, {PLAYER}!\n"
	.string "Die Typen von Team Rocket haben\l"
	.string "Reißaus genommen!\p"
	.string "Meiner Hüfte geht es auch wieder\n"
	.string "besser. Lass uns gehen.$"
#else
	.string "KURT: Way to go, {PLAYER}!\p"
	.string "TEAM ROCKET has taken off.\p"
	.string "My back's better too.\n"
	.string "Let's get out of here.$"
#endif

SlowpokeWell_B1F_Text_GruntM29Seen:
#if GERMAN
	.string "Verflixt! Ich habe oben Wache gehalten,\n"
	.string "und da kam dieser halbwahnsinnige Opa.\p"
	.string "Urplötzlich gibt es einen Schrei, und er\n"
	.string "springt einfach in den Brunnenschacht.\p"
	.string "Egal. Dann reagiere ich meinen\n"
	.string "Frust eben an dir ab!$"
#else
	.string "Darn! I was standing guard up\n"
	.string "top when some old coot yelled\l"
	.string "at me.\p"
	.string "He startled me so much that\n"
	.string "I fell down here.\p"
	.string "I think I'll vent my anger by\n"
	.string "taking it out on you!$"
#endif

SlowpokeWell_B1F_Text_GruntM29Beaten:
#if GERMAN
	.string "Ach! Es hilft ja alles nichts!$"
#else
	.string "Arrgh! This is NOT my day!$"
#endif

SlowpokeWell_B1F_Text_GruntM29After:
#if GERMAN
	.string "Klar, wir hacken Flegmon-Ruten\n"
	.string "ab und verkaufen sie.\p"
	.string "Alles, was wir tun, dient dem Profit.\p"
	.string "Richtig! Wir sind Team Rocket\n"
	.string "und tun alles für Geld!$"
#else
	.string "Sure, we've been hacking the\n"
	.string "tails off SLOWPOKE and selling\l"
	.string "them.\p"
	.string "Everything we do is for profit.\p"
	.string "That's right! We're TEAM ROCKET,\n"
	.string "and we'll do anything for money!$"
#endif

SlowpokeWell_B1F_Text_ProtonSeen:
#if GERMAN
	.string "Was willst du?\p"
	.string "Wenn du unsere Arbeit störst,\n"
	.string "erwarte keine Gnade!$"
#else
	.string "What do you want?\p"
	.string "If you interrupt our work,\n"
	.string "don't expect any mercy!$"
#endif

SlowpokeWell_B1F_Text_ProtonBeaten:
#if GERMAN
	.string "Du hast dich gut geschlagen, aber warte\n"
	.string "nur bis zum nächsten Mal!$"
#else
	.string "You did OK today,\n"
	.string "but wait till next time!$"
#endif

SlowpokeWell_B1F_Text_ProtonAfter:
#if GERMAN
	.string "Lance: …Hehehe!\n"
	.string "Ja, es stimmt. Team Rocket wurde vor\l"
	.string "drei Jahren zerschlagen.\p"
	.string "Aber wir haben unsere Arbeit still\n"
	.string "und leise im Untergrund fortgesetzt.\p"
	.string "Du kannst uns vielleicht das Leben\n"
	.string "schwer machen, aber aufhalten wirst du\l"
	.string "uns niemals!\p"
	.string "Alles, was du tun kannst, ist in\n"
	.string "Schrecken auf das zu warten, was wir\l"
	.string "weiter im Schilde führen!$"
#else
	.string "Yeah, TEAM ROCKET was broken up\n"
	.string "three years ago.\p"
	.string "The boss went into hiding.\p"
	.string "But we continued our activities\n"
	.string "underground!\p"
	.string "A small obstacle like you won't be\n"
	.string "much of a problem for our mission.\p"
	.string "I advise you to be very afraid of\n"
	.string "what is to come!$"
#endif

SlowpokeWell_B1F_Text_GruntM2Seen:
#if GERMAN
	.string "Hyuck-hyuck-hyuck!\n"
	.string "Aufhören, Flegmonruten zu klauen?\p"
	.string "Du bist verrückt!\n"
	.string "Wenn wir dir gehorchen, wäre der Ruf von\l"
	.string "Team Rocket ruiniert!$"
#else
	.string "Hyuck-hyuck-hyuck!\n"
	.string "Quit taking SLOWPOKETAILS?\p"
	.string "You're nuts!\n"
	.string "If we obeyed you, TEAM ROCKET's\l"
	.string "rep would be ruined!$"
#endif

SlowpokeWell_B1F_Text_GruntM2Beaten:
#if GERMAN
	.string "Hyuck… Zu stark…$"
#else
	.string "Hyuck…\n"
	.string "Too strong…$"
#endif

SlowpokeWell_B1F_Text_GruntM2After:
#if GERMAN
	.string "Ich sehe ja ein, wir brauchen das Geld.\n"
	.string "Aber mit Flegmon-Ruten?\p"
	.string "Wir Rocket-Rüpel haben es auch nicht\n"
	.string "leicht…$"
#else
	.string "We need the money,\n"
	.string "but selling SLOWPOKETAILS?\p"
	.string "It's tough being a ROCKET GRUNT!$"
#endif

SlowpokeWell_B1F_Text_GruntF1Seen:
#if GERMAN
	.string "Aufhören, Flegmonruten zu klauen?\p"
	.string "Na, versuch doch, uns alle aufzuhalten!$"
#else
	.string "Stop taking TAILS?\p"
	.string "Yeah, just try to defeat all\n"
	.string "of us!$"
#endif

SlowpokeWell_B1F_Text_GruntF1Beaten:
#if GERMAN
	.string "Du vorlautes Balg!$"
#else
	.string "You rotten brat!$"
#endif

SlowpokeWell_B1F_Text_GruntF1After:
#if GERMAN
	.string "Flegmonruten wachsen schnell nach!\p"
	.string "Was ist falsch daran, sie zu verkaufen?$"
#else
	.string "SLOWPOKETAILS grow back fast!\p"
	.string "What's wrong with selling them?$"
#endif

SlowpokeWell_B1F_Text_SlowpokeWithMail:
#if GERMAN
	.string "Ein Flegmon mit abgetrennter Rute…\n"
	.string "Huch? Es trägt einen Brief bei sich.\p"
	.string "Willst du ihn lesen?$"
#else
	.string "A SLOWPOKE with its TAIL cut off…\p"
	.string "Huh? It has MAIL.\n"
	.string "Read it?$"
#endif

SlowpokeWell_B1F_Text_SlowpokeMail:
#if GERMAN
	.string "{PLAYER} liest den Brief.\p"
	.string "Bitte kümmere dich gut um Opa und das\n"
	.string "Flegmon, während ich weg bin.\l"
	.string "Danke, dein Papa$"
#else
	.string "{PLAYER} read the MAIL.\p"
	.string "Be good and look after the\n"
	.string "house with Grandpa and SLOWPOKE.\p"
	.string "Love, Dad$"
#endif

SlowpokeWell_B1F_Text_TaillessSlowpoke:
#if GERMAN
	.string "Ein Flegmon mit abgetrennter Rute…$"
#else
	.string "A SLOWPOKE with its TAIL cut off…$"
#endif
