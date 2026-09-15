EcruteakCity_Gym_hns_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_HNS, SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING_HNS, SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA_HNS, MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE_HNS, MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1_HNS, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setvar VAR_0x8004, 3
	special SetJohtoBadge
	setflag FLAG_BADGE04_GET
	@ Der Orden ist zugleich die Befugnis fuer Surfer - siehe
	@ src/johto_permits.c. Die Ordensflags teilt sich Johto mit Kanto.
	setvar VAR_0x8004, PERM_SURF
	special SetJohtoPermit
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
#if GERMAN
	.string "Pokémon-Arena von Teak City$"
#else
	.string "ECRUTEAK CITY POKéMON GYM$"
#endif

EcruteakCity_Gym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon-Arena von Teak City\p"
	.string "Leiter: Jens\n"
	.string "Anerkannte Trainer:\p"
	.string "{PLAYER}$"
#else
	.string "ECRUTEAK CITY POKéMON GYM\p"
	.string "MORTY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif

MortyIntroText:
#if GERMAN
	.string "Schön, dass du gekommen bist.\p"
	.string "Hier in Teak City werden Pokémon\n"
	.string "seit jeher verehrt.\p"
	.string "Man sagt, ein regenbogenfarbenes\n"
	.string "Pokémon erscheint nur einem wahrhaftig\l"
	.string "würdigen Trainer.\p"
	.string "Ich glaubte diese Legende und\n"
	.string "trainierte hier im Verborgenen.\p"
	.string "Nun kann ich Dinge sehen, die anderen\n"
	.string "verborgen bleiben.\p"
	.string "Nur noch ein kleines Stück…\p"
	.string "Mit etwas mehr könnte ich die Zukunft\n"
	.string "sehen, in der ich dem\l"
	.string "Regenbogen-Pokémon begegne.\p"
	.string "Du wirst mir helfen, dieses Ziel zu\n"
	.string "erreichen!$"
#else
	.string "Good of you to have come.\p"
	.string "Here in ECRUTEAK, POKéMON have\n"
	.string "always been revered.\p"
	.string "It's said that a rainbow-colored\n"
	.string "POKéMON will come down to\l"
	.string "appear before a true Trainer.\p"
	.string "I believed that tale, so I've\n"
	.string "trained here in secret.\p"
	.string "As a result, I can now see what\n"
	.string "others cannot.\p"
	.string "Just a bit more...\p"
	.string "With a little more, I could see\n"
	.string "a future where I meet the\l"
	.string "rainbow-colored POKéMON.\p"
	.string "You're going to help me reach\n"
	.string "that level!$"
#endif

MortyWinLossText:
#if GERMAN
	.string "Ich bin noch nicht gut genug…\p"
	.string "In Ordnung.\n"
	.string "Dieser Orden gehört dir.$"
#else
	.string "I'm not good enough yet...\p"
	.string "All right. This BADGE is yours.$"
#endif

Text_ReceivedFogBadge:
#if GERMAN
	.string "{PLAYER} erhält den Phantomorden!$"
#else
	.string "{PLAYER} received the FOGBADGE.$"
#endif

MortyText_FogBadgeSpeech:
#if GERMAN
	.string "Mit dem Phantomorden gehorchen dir\n"
	.string "Pokémon bis Level 50.\p"
	.string "Außerdem können Pokémon, die Surfer\n"
	.string "beherrschen, es jederzeit einsetzen.\p"
	.string "Nimm auch das hier.$"
#else
	.string "With the FOGBADGE, POKéMON up\n"
	.string "to Level 50 will obey you.\p"
	.string "Also, any POKéMON that knows\n"
	.string "SURF will be able to use it\l"
	.string "anytime.\p"
	.string "I want you to have this too.$"
#endif

MortyText_ShadowBallSpeech:
#if GERMAN
	.string "Das ist Spukball.\n"
	.string "Die Attacke richtet Schaden an und\l"
	.string "kann die Sp.-Vert. senken.\p"
	.string "Nutze sie, wenn sie dir nützt.$"
#else
	.string "That's SHADOW BALL.\n"
	.string "It causes damage and may\l"
	.string "lower SP. DEF.\p"
	.string "Use it if it suits you.$"
#endif

MortyFightDoneText:
#if GERMAN
	.string "Ich verstehe…\p"
	.string "Deine Reise führte dich an ferne Orte.\p"
	.string "Du hast mehr gesehen, als ich je erleben\n"
	.string "werde.\p"
	.string "Darum beneide ich dich…$"
#else
	.string "I see...\p"
	.string "Your journey has taken you to\n"
	.string "far-off places.\p"
	.string "You've witnessed more than I\n"
	.string "ever have.\p"
	.string "I envy you for that...$"
#endif

MortyRematchText:
#if GERMAN
	.string "Ah, der Champion von Johto!\n"
	.string "Schön, dass du gekommen bist.\p"
	.string "Du hast Stärke bewiesen, doch bist du\n"
	.string "seit unserem letzten Kampf gewachsen?\p"
	.string "Ich habe seitdem mit meinen\n"
	.string "Geist-Pokémon trainiert.\p"
	.string "Mal sehen, ob du die Schatten\n"
	.string "erneut überwinden kannst.\p"
	.string "Willst du eine Revanche?$"
#else
	.string "Ah, the JOHTO CHAMPION!\n"
	.string "Good of you to come.\p"
	.string "You've shown strength and skill,\n"
	.string "but have you grown since we\l"
	.string "last battled?\p"
	.string "I've trained with my GHOST-type\n"
	.string "POKéMON ever since.\p"
	.string "Let's see if you can overcome\n"
	.string "the shadows again.\p"
	.string "Want to have a rematch?$"
#endif

Morty_RematchDefeatText:
#if GERMAN
	.string "Ich bin noch nicht gut genug…\p"
	.string "Du hast mehr gesehen, als ich je erleben\n"
	.string "werde.\p"
	.string "Darum beneide ich dich…$"
#else
	.string "I'm not good enough yet...\p"
	.string "You've witnessed more than I\n"
	.string "ever have.\p"
	.string "I envy you for that...$"
#endif

SageJeffreySeenText:
#if GERMAN
	.string "Ich habe den Frühling mit meinen\n"
	.string "Pokémon verbracht. Dann den Sommer,\l"
	.string "den Herbst und den Winter…\p"
	.string "Dann kam wieder der Frühling. Wir haben\n"
	.string "viel miteinander durchgemacht.$"
#else
	.string "I spent the spring with my\n"
	.string "POKéMON.\p"
	.string "Then summer, fall, and winter...\p"
	.string "Then spring came again.\n"
	.string "We've been together a long time.$"
#endif

SageJeffreyBeatenText:
#if GERMAN
	.string "Siege und Niederlagen…\n"
	.string "Ich kenne beides.$"
#else
	.string "Wins and losses--I've known\n"
	.string "them both.$"
#endif

SageJeffreyAfterBattleText:
#if GERMAN
	.string "Woher kommen wohl Pokémon?$"
#else
	.string "Where did POKéMON come from?$"
#endif

SagePingSeenText:
#if GERMAN
	.string "Mal sehen, ob du es schaffst,\n"
	.string "unseren Pokémon Schaden zuzufügen!$"
#else
	.string "Can you inflict any damage\n"
	.string "on our POKéMON?$"
#endif

SagePingBeatenText:
#if GERMAN
	.string "Ah! Gut gemacht!$"
#else
	.string "Ah! Well done!$"
#endif

SagePingAfterBattleText:
#if GERMAN
	.string "Wir nutzen Geist-Pokémon.\p"
	.string "Normale Attacken können ihnen\n"
	.string "nichts anhaben!$"
#else
	.string "We use GHOST-type POKéMON.\p"
	.string "No NORMAL-type attacks can\n"
	.string "harm them!$"
#endif

MediumMarthaSeenText:
#if GERMAN
	.string "G-gewonnen!$"
#else
	.string "I shall win!$"
#endif

MediumMarthaBeatenText:
#if GERMAN
	.string "V-v-verloren!$"
#else
	.string "I... I... I lost!$"
#endif

MediumMarthaAfterBattleText:
#if GERMAN
	.string "Wer am meisten gewinnen will, wird auch\n"
	.string "siegen!$"
#else
	.string "The one who wants to win the\n"
	.string "most is the one who will!$"
#endif

MediumGraceSeenText:
#if GERMAN
	.string "Verirrst du dich in unseren dunklen\n"
	.string "Gängen?\p"
	.string "Besiege mich für einen Tipp!$"
#else
	.string "Stumped by our dark corridors?\n"
	.string "Defeat me if you want a hint!$"
#endif

MediumGraceBeatenText:
#if GERMAN
	.string "W-Was?$"
#else
	.string "Wha-what?$"
#endif

MediumGraceAfterBattleText:
#if GERMAN
	.string "Gut. Ich verrate dir das Geheimnis der\n"
	.string "Schatten.\p"
	.string "Der Weg liegt direkt vor deinen Augen!$"
#else
	.string "Fine. I'll tell you the secret\n"
	.string "of the shadows.\p"
	.string "The path is right in front of\n"
	.string "your eyes!$"
#endif

EcruteakCity_GymGuideText:
#if GERMAN
	.string "Hey Champ! Fast die Hälfte ist\n"
	.string "geschafft!\p"
	.string "Die Trainer hier nutzen Geist-\n"
	.string "und Unlicht-Pokémon.\p"
	.string "Jens ist ein Meister der Geist-Pokémon,\n"
	.string "doch hüte dich vor seinem mystischen\l"
	.string "Hirsch.\p"
	.string "Man sagt, er verursacht schreckliche\n"
	.string "Albträume…$"
#else
	.string "Hey CHAMP! You're almost\n"
	.string "halfway there!\p"
	.string "Trainers here use GHOST and\n"
	.string "DARK-type POKéMON.\p"
	.string "While MORTY is a GHOST-type\n"
	.string "expert, be wary of his mystic\l"
	.string "deer.\p"
	.string "It's said to cause strange\n"
	.string "nightmares...$"
#endif

EcruteakCity_GymGuideWinText:
#if GERMAN
	.string "Wow, {PLAYER}!\n"
	.string "Du warst großartig!\p"
	.string "So großartig sogar, dass ich glatt ein\n"
	.string "bisschen Angst gekriegt und mich in\l"
	.string "eine Ecke verkrochen habe!$"
#else
	.string "Whew, {PLAYER}. You did great!\p"
	.string "I was cowering in the corner\n"
	.string "out of pure terror!$"
#endif

EcruteakCity_GymClosedText:
#if GERMAN
	.string "Jens, der Arenaleiter, ist nicht da.\p"
	.string "Tut mir leid, du musst wieder gehen.\p"
	.string "Hohohoho.$"
#else
	.string "MORTY, the GYM LEADER, is\n"
	.string "absent.\p"
	.string "Sorry, but you'll have to\n"
	.string "leave.\p"
	.string "Hohohoho.$"
#endif
