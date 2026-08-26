Route25_Frlg_MapScripts::
	.byte 0

Route25_EventScript_SeaCottageSign::
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_EventScript_Man::
	msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
	end

Route25_Text_JoeyIntro::
#if GERMAN
	.string "Die Trainer der Gegend kommen zum\n"
	.string "Üben hierher!$"
#else
	.string "Local TRAINERS come here to\n"
	.string "practice.$"
#endif

Route25_Text_JoeyDefeat::
#if GERMAN
	.string "Du bist richtig gut!$"
#else
	.string "You're decent.$"
#endif

Route25_Text_JoeyPostBattle::
#if GERMAN
	.string "Jedes Pokémon hat seine Schwächen!\p"
	.string "Man sollte daher unterschiedliche\n"
	.string "Pokémon trainieren.$"
#else
	.string "All POKéMON have weaknesses.\n"
	.string "Even the strongest ones.\p"
	.string "That's why it's best to raise\n"
	.string "POKéMON of different types.$"
#endif

Route25_Text_DanIntro::
#if GERMAN
	.string "Ich habe in Orania City mit meinem Papa\n"
	.string "auf der M.s. Anne eine Party besucht!$"
#else
	.string "Dad took me to a great party on\n"
	.string "the S.S. ANNE at VERMILION CITY.$"
#endif

Route25_Text_DanDefeat::
#if GERMAN
	.string "Ich bin nicht sauer!$"
#else
	.string "I'm not mad!$"
#endif

Route25_Text_DanPostBattle::
#if GERMAN
	.string "Auf der M.s. Anne habe ich Trainer aus\n"
	.string "aller Welt gesehen!$"
#else
	.string "On the S.S. ANNE, I saw TRAINERS\n"
	.string "from around the world.$"
#endif

Route25_Text_FlintIntro::
#if GERMAN
	.string "Ich bin richtig cool!\n"
	.string "Ich habe eine Freundin!$"
#else
	.string "I'm a cool guy.\n"
	.string "I've got a girlfriend!$"
#endif

Route25_Text_FlintDefeat::
#if GERMAN
	.string "Ach, so ein Mist...$"
#else
	.string "Aww, darn…$"
#endif

Route25_Text_FlintPostBattle::
#if GERMAN
	.string "Na ja, meine Freundin wird mich\n"
	.string "aufheitern!$"
#else
	.string "Oh, well.\n"
	.string "My girlfriend will cheer me up.$"
#endif

Route25_Text_KelseyIntro::
#if GERMAN
	.string "Hallo!\n"
	.string "Mein Freund ist cool!$"
#else
	.string "Hi!\n"
	.string "My boyfriend is cool!$"
#endif

Route25_Text_KelseyDefeat::
#if GERMAN
	.string "Ich war nicht in Form!$"
#else
	.string "My conditioning isn't the best…$"
#endif

Route25_Text_KelseyPostBattle::
#if GERMAN
	.string "Ach, wäre mein Freund doch auch\n"
	.string "so toll wie du!$"
#else
	.string "I wish my boyfriend was as good\n"
	.string "as you.$"
#endif

Route25_Text_ChadIntro::
#if GERMAN
	.string "Ich wusste, dass wir miteinander\n"
	.string "kämpfen würden!$"
#else
	.string "I had this feeling…\n"
	.string "I knew I had to battle you!$"
#endif

Route25_Text_ChadDefeat::
#if GERMAN
	.string "Ich wusste auch, dass ich verlieren\n"
	.string "würde!$"
#else
	.string "I knew I'd lose, too!$"
#endif

Route25_Text_ChadPostBattle::
#if GERMAN
	.string "Wenn eines deiner Pokémon verwirrt\n"
	.string "ist, wechsle es aus!\p"
	.string "Das ist eine gute Taktik!$"
#else
	.string "If your POKéMON gets confused,\n"
	.string "switch it out.\p"
	.string "That's a good tactic.$"
#endif

Route25_Text_HaleyIntro::
#if GERMAN
	.string "Meine Freundin hat so ein süßes\n"
	.string "Pokémon! Ich bin furchtbar neidisch!$"
#else
	.string "My friend has many cute POKéMON.\n"
	.string "I'm so jealous!$"
#endif

Route25_Text_HaleyDefeat::
#if GERMAN
	.string "Ich bin nicht sauer!$"
#else
	.string "I'm not so jealous!$"
#endif

Route25_Text_HaleyPostBattle::
#if GERMAN
	.string "Du warst auf dem Mondberg?\n"
	.string "Hast du ein Piepi gefunden?$"
#else
	.string "You came from MT. MOON?\n"
	.string "May I have a CLEFAIRY?$"
#endif

Route25_Text_FranklinIntro::
#if GERMAN
	.string "Ich komme gerade vom Mondberg und\n"
	.string "bin topfit!$"
#else
	.string "I just got down from MT. MOON,\n"
	.string "but I've still got gas in the tank!$"
#endif

Route25_Text_FranklinDefeat::
#if GERMAN
	.string "Du hast schwer gekämpft!$"
#else
	.string "You worked hard!$"
#endif

Route25_Text_FranklinPostBattle::
#if GERMAN
	.string "Mist!\n"
	.string "Mich hat ein Zubat gebissen!$"
#else
	.string "Drat!\n"
	.string "A ZUBAT bit me back in that cave.$"
#endif

Route25_Text_NobIntro::
#if GERMAN
	.string "Ich bin auf dem Weg zu einem\n"
	.string "Pokémon-Sammler!$"
#else
	.string "I'm off to see a POKéMANIAC's\n"
	.string "collection at the cape.$"
#endif

Route25_Text_NobDefeat::
#if GERMAN
	.string "Du hast mich besiegt.$"
#else
	.string "You done got me, and real good,\n"
	.string "too!$"
#endif

Route25_Text_NobPostBattle::
#if GERMAN
	.string "Dieser Sammler besitzt viele seltene\n"
	.string "Pokémon.$"
#else
	.string "The POKéMANIAC sure lives up to\n"
	.string "his name.\p"
	.string "His collection includes many rare\n"
	.string "species of POKéMON.$"
#endif

Route25_Text_WayneIntro::
#if GERMAN
	.string "Du möchtest zu Bill?\n"
	.string "Aber erst wird gekämpft!$"
#else
	.string "You're going to see BILL?\n"
	.string "First, we battle!$"
#endif

Route25_Text_WayneDefeat::
#if GERMAN
	.string "Ich gebe auf!$"
#else
	.string "You're something.$"
#endif

Route25_Text_WaynePostBattle::
#if GERMAN
	.string "Der Pfad dort unten ist eine Abkürzung\n"
	.string "nach Azuria City.$"
#else
	.string "The trail below is a shortcut to\n"
	.string "CERULEAN CITY.$"
#endif

Route25_Text_SeaCottageSign::
#if GERMAN
	.string "Küstenhaus\n"
	.string "Hier wohnt Bill!$"
#else
	.string "SEA COTTAGE\n"
	.string "BILL lives here!$"
#endif

Route25_Text_MistyHighHopesAboutThisPlace::
#if GERMAN
	.string "Das Kap ist beliebt bei Pärchen.\p"
	.string "Die Arenaleiterin Misty hat hohe\n"
	.string "Erwartungen an diesen Ort.$"
#else
	.string "This cape is a famous date spot.\p"
	.string "MISTY, the GYM LEADER, has high\n"
	.string "hopes about this place.$"
#endif

Route25_Text_AreYouHereAlone::
#if GERMAN
	.string "Hallo! Bist du alleine hier?\p"
	.string "Wenn du am Kap von Azuria City bist,\n"
	.string "solltest du jemanden dabei haben.$"
#else
	.string "Hello, are you here alone?\p"
	.string "If you're out at CERULEAN's cape…\n"
	.string "Well, it should be as a couple.$"
#endif
