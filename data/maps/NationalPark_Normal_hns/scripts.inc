NationalPark_Normal_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition:
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
#if GERMAN
	.string "Sieh dir meine Tasche an!\p"
	.string "Ich habe meine Lieblinge aus dem\p"
	.string "Pokédex gedruckt und auf meine Tasche\n"
	.string "geklebt.$"
#else
	.string "Look! Check out my bag!\p"
	.string "I printed out my favorites from my\n"
	.string "POKéDEX and stuck them on my bag.$"
#endif

NationalPark_Normal_Text_PokefanF:
#if GERMAN
	.string "Das ist ein Brief von meiner Tochter.\n"
	.string "Das macht mir Freude.$"
#else
	.string "This is MAIL I got from my daughter.\n"
	.string "It cheers me up.$"
#endif

NationalPark_Normal_Text_Teacher1:
#if GERMAN
	.string "So, jetzt mal hergehört, Herrschaften!\p"
	.string "…Oh, Entschuldigung. Ich muss echt\n"
	.string "mal dieses Lehrergehabe loswerden.\p"
	.string "Du bist ein Pokémon-Trainer, stimmt’s?\p"
	.string "Du scheinst sehr hart zu arbeiten.\n"
	.string "Hier, nimm das als Belohnung!$"
#else
	.string "Pay attention, please!\p"
	.string "…Oops, I have to quit thinking like\n"
	.string "a teacher all the time.\p"
	.string "You must be a POKéMON trainer.\p"
	.string "Since you're working so hard, I\n"
	.string "want you to have this.$"
#endif

NationalPark_Normal_Text_Teacher1_QuickClaw:
#if GERMAN
	.string "Gib diese Flinkklaue einem deiner\n"
	.string "Pokémon, und es wird mit ihrer Hilfe im\l"
	.string "Kampf ab und zu die Initiative\l"
	.string "erhalten!$"
#else
	.string "Let a POKéMON hold that QUICK CLAW.\p"
	.string "Sometimes it will strike first\n"
	.string "during battle.$"
#endif

NationalPark_Normal_Text_Youngster1:
#if GERMAN
	.string "Ich spiele mit Stickern, die ich aus\n"
	.string "meinem Dex gedruckt habe.$"
#else
	.string "I'm playing with stickers I printed\n"
	.string "from my POKéDEX.$"
#endif

NationalPark_Normal_Text_Youngster2:
#if GERMAN
	.string "Falls ich gewinne, erhalte ich die\n"
	.string "Dex-Sticker meines Gegners.$"
#else
	.string "I get the other guy's POKéDEX sticker\n"
	.string "if I win.$"
#endif

NationalPark_Normal_Text_Teacher2:
#if GERMAN
	.string "Ich gehe oft im Park spazieren,\p"
	.string "aber ich meide das hohe Gras.\p"
	.string "Trainer möchten immer kämpfen…\p"
	.string "Du hattest sicher viele Kämpfe.\n"
	.string "Ich heile deine Pokémon.$"
#else
	.string "I take walks in the PARK, but I\n"
	.string "never go into the grass.\p"
	.string "Trainers always want to battle…\p"
	.string "You must have been in many battles.\n"
	.string "Let me heal your POKéMON for you.$"
#endif

NationalPark_Normal_Text_Persian:
#if GERMAN
	.string "Snobilikat: Snooobi, snobi!$"
#else
	.string "PERSIAN: Fufushaa!$"
#endif

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK_HNS, NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten, NationalPark_Normal_EventScript_RegisterJack
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchJack
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterJack::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_JackRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACK_HNS
	release
	end

NationalPark_Normal_EventScript_RematchJack::
	trainerbattle_rematch TRAINER_JACK_HNS, NationalPark_Normal_Text_JackRematchIntro, NationalPark_Normal_Text_JackRematchDefeat
	msgbox NationalPark_Normal_Text_JackPostRematch, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten, NationalPark_Normal_EventScript_RegisterBeverly
	goto_if_set FLAG_BEVERLY_HAS_ITEM_HNS, NationalPark_Normal_EventScript_BeverlyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchBeverly
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RematchBeverly::
	trainerbattle_rematch TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterBeverly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_BeverlyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BEVERLY_HNS
	release
	end

NationalPark_Normal_EventScript_BeverlyGiveItem::
	msgbox NationalPark_Normal_Text_BeverlyHasItem, MSGBOX_DEFAULT
	giveitem VAR_BEVERLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, NationalPark_Normal_EventScript_BeverlyNoRoom
	clearflag FLAG_BEVERLY_HAS_ITEM_HNS
	msgbox NationalPark_Normal_Text_BeverlyGaveItem, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_BeverlyNoRoom::
	msgbox NationalPark_Normal_Text_BeverlyNoRoom, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM_HNS, NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE_HNS, NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
#if GERMAN
	.string "Pokémon sind ein Fass ohne Boden.\n"
	.string "Es gibt noch viel, was wir nicht wissen.\p"
	.string "Aber ich weiß immer noch mehr über sie\n"
	.string "als du! Dass das klar ist!$"
#else
	.string "The world of POKéMON is deep.\p"
	.string "There are still lots of things we\n"
	.string "don't know.\p"
	.string "But I know more than you do!$"
#endif

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
#if GERMAN
	.string "Wa-wa-waas?$"
#else
	.string "Wha-wha-what?$"
#endif

NationalPark_Normal_Text_SchoolboyJack_After:
#if GERMAN
	.string "Es gibt noch viel zu lernen!\p"
	.string "Zum Beispiel, dass es 90 verschiedene\n"
	.string "Technische Maschinen gibt, oder dass\l"
	.string "sich Pokémon, die man im Tausch erhält,\l"
	.string "schneller entwickeln.$"
#else
	.string "There is a lot to learn.\p"
	.string "For example…\p"
	.string "There are 50 kinds of TMs.\p"
	.string "Traded POKéMON level up faster.$"
#endif

NationalPark_Normal_Text_JackRegister:
#if GERMAN
	.string "Es gibt noch viel zu lernen!\p"
	.string "Zum Beispiel, dass es 50 verschiedene\n"
	.string "Technische Maschinen gibt, oder dass\l"
	.string "sich Pokémon, die man im Tausch erhält,\l"
	.string "schneller entwickeln.$"
#else
	.string "There is a lot to learn.\p"
	.string "For example…\p"
	.string "There are 50 kinds of TMs.\p"
	.string "Traded POKéMON level up faster.$"
#endif

NationalPark_Normal_Text_JackRematchIntro:
#if GERMAN
	.string "Ich habe viel seit dem letzten\n"
	.string "Mal gelernt! Na los!$"
#else
	.string "I've learned a lot since we\n"
	.string "last battled! Let's go!$"
#endif

NationalPark_Normal_Text_JackRematchDefeat:
#if GERMAN
	.string "Wa-wa-was?$"
#else
	.string "Wha-wha-what?$"
#endif

NationalPark_Normal_Text_JackPostRematch:
#if GERMAN
	.string "Es gibt noch viel zu lernen!\p"
	.string "Zum Beispiel, dass es 50 verschiedene\n"
	.string "Technische Maschinen gibt, oder dass\l"
	.string "sich Pokémon, die man im Tausch erhält,\l"
	.string "schneller entwickeln.$"
#else
	.string "There is a lot to learn.\p"
	.string "For example…\p"
	.string "There are 50 kinds of TMs.\p"
	.string "Traded POKéMON level up faster.$"
#endif

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
#if GERMAN
	.string "Meine Pokémon sind einfach hinreißend.\p"
	.string "Ich zeige dir, wie stolz mich meine\n"
	.string "Lieblinge machen.$"
#else
	.string "My POKéMON are simply darling.\p"
	.string "Let me tell you how proud my\n"
	.string "darlings make me.$"
#endif

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
#if GERMAN
	.string "Im Kampf bin ich der Verlierer, aber in\n"
	.string "Sachen Stolz bin ich unschlagbar!$"
#else
	.string "I can beat you in pride, but…$"
#endif

NationalPark_Normal_Text_PokefanFBeverly_After:
#if GERMAN
	.string "Ich muss zugeben… dein Pokémon-\n"
	.string "Team ist auch sehr süß.$"
#else
	.string "I must say, your POKéMON are quite\n"
	.string "cute, too.$"
#endif

NationalPark_Normal_Text_PokefanmWilliam_Seen:
#if GERMAN
	.string "Wir bewundern unsere Pokémon, auch\n"
	.string "wenn sie uns nicht mögen!\l"
	.string "Das macht den wahren Pokéfan aus!$"
#else
	.string "We adore our POKéMON, even if they\n"
	.string "dislike us.\p"
	.string "That's what being a FAN is about.$"
#endif

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
#if GERMAN
	.string "M-mein Pokémon!$"
#else
	.string "M-my POKéMON!$"
#endif

NationalPark_Normal_Text_PokefanmWilliam_After:
#if GERMAN
	.string "Ich habe zwar den Kampf verloren, aber\n"
	.string "mein Pokémon gewinnt den\l"
	.string "Schönheitspreis.$"
#else
	.string "I lost the battle, but my POKéMON win\n"
	.string "the prize for being most lovely.$"
#endif

NationalPark_Normal_Text_LassKrise_Seen:
#if GERMAN
	.string "Was ist?\n"
	.string "Warum starrst du mich so an?\p"
	.string "Oh, ein Kampf?$"
#else
	.string "Hello? Why are you staring at me?\p"
	.string "Oh, a battle?$"
#endif

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "…Hmmm…$"

NationalPark_Normal_Text_LassKrise_After:
#if GERMAN
	.string "Ich dachte, du starrst mich an,\n"
	.string "weil ich so süß bin!$"
#else
	.string "I thought you were staring at me\n"
	.string "because I'm cute!$"
#endif

NationalPark_Normal_Text_Sign_RelaxationSquare:
#if GERMAN
	.string "Der Nationalpark\n"
	.string "Ein öffentlicher Ort der Erholung$"
#else
	.string "RELAXATION SQUARE\n"
	.string "NATIONAL PARK$"
#endif

NationalPark_Normal_Text_Sign_BattleNotice:
#if GERMAN
	.string "Da ist ein Flugblatt…\p"
	.string "Kämpfe sind nur im hohen Gras\n"
	.string "gestattet.\l"
	.string "- Das Büro des Wächters$"
#else
	.string "What is this notice?\p"
	.string "Please battle only in the grass.\p"
	.string "NATIONAL PARK WARDEN'S OFFICE$"
#endif

NationalPark_Normal_Text_TrainerTips:
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Möchtest du deine Briefe drucken,\n"
	.string "öffne sie und drücke Start.$"
#else
	.string "TRAINER TIPS\p"
	.string "Print out MAIL by opening it then\n"
	.string "pressing START.$"
#endif

NationalPark_Normal_Text_BeverlyRegister:
#if GERMAN
	.string "Ich muss zugeben… dein Pokémon-\n"
	.string "Team ist auch sehr süß.$"
#else
	.string "I must say, your POKéMON are quite\n"
	.string "cute, too.$"
#endif

NationalPark_Normal_Text_BeverlyHasItem:
#if GERMAN
	.string "Oh, hallo! Ich habe etwas für dich.\p"
	.string "Bitte nimm es als Zeichen meiner\n"
	.string "Dankbarkeit!$"
#else
	.string "Oh, hello! I have something\n"
	.string "for you.\p"
	.string "Please take it as a token of\n"
	.string "my appreciation!$"
#endif

NationalPark_Normal_Text_BeverlyGaveItem:
#if GERMAN
	.string "Meine Pokémon und ich werden dich\n"
	.string "anfeuern!$"
#else
	.string "My darling POKéMON and I will\n"
	.string "be cheering for you!$"
#endif

NationalPark_Normal_Text_BeverlyNoRoom:
#if GERMAN
	.string "Hmm, dein Beutel ist voll.\p"
	.string "Komm wieder, wenn du Platz hast.$"
#else
	.string "Hmm, your BAG is full.\p"
	.string "Come back when you have room.$"
#endif
