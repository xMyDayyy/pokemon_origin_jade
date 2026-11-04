RuinsOfAlph_Outside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition:
	callnative SetTimeBasedEncounters
	end

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
#if GERMAN
	.string "Es gibt viele unterschiedliche\p"
	.string "Icognito, die wir für unsere\n"
	.string "Geheimcodes benötigen.$"
#else
	.string "QUAGSIRE: Quag Quag$"
#endif

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN_HNS, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN_HNS, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
#if GERMAN
	.string "Hm? Oh, ist das etwa ein Pokédex?\n"
	.string "Dürfte ich da mal einen Blick\l"
	.string "reinwerfen?\p"
	.string "Ist ja ein Ding. \n"
	.string "So viele unterschiedliche Pokémon…\p"
	.string "Unglaublich!\p"
	.string "Was ist das denn für ein Pokémon?\p"
	.string "Es sieht aus wie die merkwürdigen\n"
	.string "Zeichen an den Wänden der Ruinen.\p"
	.string "Falls diese Zeichen tatsächlich\n"
	.string "Pokémon sind, dann gibt es noch\l"
	.string "viel mehr davon.\p"
	.string "Ich weiß!\n"
	.string "Lass mich deinen Pokédex erweitern.\l"
	.string "Mir nach!$"
#else
	.string "Hm? That's a POKéDEX, isn't it?\n"
	.string "May I see it?\p"
	.string "There are so many kinds of\n"
	.string "POKéMON.\p"
	.string "Hm? What's this?\p"
	.string "What is this POKéMON?\p"
	.string "It looks like the strange\n"
	.string "writing on the walls of the\p"
	.string "RUINS.\p"
	.string "If those drawings are really\n"
	.string "POKéMON, there should be many\n"
	.string "more.\p"
	.string "I know! Let me upgrade your\n"
	.string "POKéDEX. Follow me.$"
#endif

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
#if GERMAN
    .string "Was willst du? Ich studiere gerade -\n"
    .string "stör mich nicht!$"
#else
	.string "What do you want? I'm studying--\n"
	.string "don't disturb me!$"
#endif

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
#if GERMAN
    .string "Sorry…\n"
    .string "Ich bin frustriert über unser\l"
    .string "mangelndes Verständnis…$"
#else
	.string "Sorry…\n"
	.string "I'm frustrated by our lack of\p"
	.string "real understanding…$"
#endif

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
#if GERMAN
    .string "Die Ruinen sind etwa 1500 Jahre alt.\p"
    .string "Niemand weiß, wer sie erbaut hat.\p"
    .string "Auch ist unklar, ob die Pokémon-\n"
    .string "Statuen eine Bedeutung haben.\p"
    .string "Alles ist ein großes Rätsel…$"
#else
	.string "The RUINS are from about 1500\n"
	.string "years ago.\p"
	.string "Nobody knows who built them.\p"
	.string "It's also not known if the POKéMON\n"
	.string "statues have any meaning.\p"
	.string "It's all one big mystery…$"
#endif

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
#if GERMAN
	.string "Hm… dies ist ein merkwürdiger Ort.$"
#else
	.string "Hmmm… This is a strange place.$"
#endif

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
#if GERMAN
    .string "…$"
#else
	.string "…$"
#endif

RuinsOfAlph_Outside_Text_PsychicNathan_After:
#if GERMAN
	.string "Ich komme oft hierher, um\n"
	.string "nachzudenken.$"
#else
	.string "I like thinking here.$"
#endif

RuinsOfAlph_Outside_Text_MysteryChamberSign:
#if GERMAN
	.string "Rätselstein Puzzlekammer$"
#else
	.string "MYSTERY STONE PANEL CHAMBER$"
#endif

RuinsOfAlph_Outside_Text_MainSign:
#if GERMAN
	.string "Alph-Ruinen\p"
	.string "Besucher jederzeit\n"
	.string "willkommen$"
#else
	.string "RUINS OF ALPH\n"
	.string "VISITORS WELCOME$"
#endif

RuinsOfAlph_Outside_Text_ResearchSign:
#if GERMAN
	.string "Alph-Ruinen Forschungszentrum\p"
	.string "Die Autorität der Alph-Ruinen$"
#else
	.string "RUINS OF ALPH RESEARCH CENTER\p"
	.string "THE AUTHORITY ON THE\n"
	.string "RUINS OF ALPH$"
#endif

RuinsOfAlph_Outside_Text_Fisher1:
#if GERMAN
	.string "Beim Erkunden der Ruinen haben wir\p"
	.string "plötzlich eine seltsame Gegenwart\n"
	.string "gespürt.\p"
	.string "Alle hatten Angst und liefen davon.\p"
	.string "Du solltest auch vorsichtig sein.$"
#else
	.string "While exploring the RUINS, we\n"
	.string "suddenly noticed an odd presence.\p"
	.string "We all got scared and ran away.\n"
	.string "You should be careful too.$"
#endif

RuinsOfAlph_Outside_Text_Fisher2:
#if GERMAN
	.string "Den Ruinen wohnt ein großes Geheimnis\n"
	.string "inne!\p"
	.string "…Ich denke…$"
#else
	.string "The RUINS hide a huge secret!\p"
	.string "…I think…$"
#endif

RuinsOfAlph_Outside_Text_Youngster1:
#if GERMAN
	.string "Es gibt viele unterschiedliche\n"
	.string "Icognito, die wir für unsere\l"
	.string "Geheimcodes benötigen.$"
#else
	.string "There are many kinds of UNOWN, so\n"
	.string "we use them for our secret codes.$"
#endif

RuinsOfAlph_Outside_Text_Youngster2:
#if GERMAN
	.string "V… O… R… A… U… S… Hmm…\p"
	.string "Wie?\p"
	.string "Ich dechiffriere diese Nachricht!$"
#else
	.string "A… H… E… A… D… Hmm…\p"
	.string "What?\p"
	.string "I'm decoding this message!$"
#endif
