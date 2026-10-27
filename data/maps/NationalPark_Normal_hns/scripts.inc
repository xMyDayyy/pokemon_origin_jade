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
	.string "Schau mal! Sieh dir meine Tasche an!\p"
	.string "Ich habe meine Lieblinge aus dem\n"
	.string "Pokédex ausgedruckt und auf meine\l"
	.string "Tasche geklebt.$"
#else
	.string "Look! Check out my bag!\p"
	.string "I printed out my favorites from my\n"
	.string "POKéDEX and stuck them on my bag.$"
#endif

NationalPark_Normal_Text_Teacher1:
#if GERMAN
	.string "Aufgepasst, bitte!\p"
	.string "…Hoppla, ich muss aufhören, ständig\n"
	.string "wie eine Lehrerin zu denken.\p"
	.string "Du bist sicher ein Pokémon-Trainer.\p"
	.string "Weil du dich so anstrengst, möchte\n"
	.string "ich dir das hier schenken.$"
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
	.string "Gib diese Flinkklaue einem Pokémon\n"
	.string "zum Tragen.\p"
	.string "Manchmal greift es dann im Kampf\n"
	.string "zuerst an.$"
#else
	.string "Let a POKéMON hold that QUICK CLAW.\p"
	.string "Sometimes it will strike first\n"
	.string "during battle.$"
#endif

NationalPark_Normal_Text_Youngster1:
#if GERMAN
	.string "Ich spiele mit Stickern, die ich aus\n"
	.string "meinem Pokédex ausgedruckt habe.$"
#else
	.string "I'm playing with stickers I printed\n"
	.string "from my POKéDEX.$"
#endif

NationalPark_Normal_Text_Youngster2:
#if GERMAN
	.string "Wenn ich gewinne, bekomme ich den\n"
	.string "Pokédex-Sticker des anderen.$"
#else
	.string "I get the other guy's POKéDEX\n"
	.string "sticker if I win.$"
#endif

NationalPark_Normal_Text_Teacher2:
#if GERMAN
	.string "Ich gehe im Park spazieren, aber\n"
	.string "nie ins Gras.\p"
	.string "Trainer wollen ja immer kämpfen…\p"
	.string "Du hast sicher schon viele Kämpfe\n"
	.string "hinter dir. Ich heile deine Pokémon.$"
#else
	.string "I take walks in the PARK, but I\n"
	.string "never go into the grass.\p"
	.string "Trainers always want to battle…\p"
	.string "You must have been in many battles.\n"
	.string "Let me heal your POKéMON for you.$"
#endif

NationalPark_Normal_Text_Persian:
#if GERMAN
	.string "Snobilikat: Fufushaa!$"
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
	.string "Die Welt der Pokémon ist tief.\p"
	.string "Es gibt noch so vieles, was wir\n"
	.string "nicht wissen.\p"
	.string "Aber ich weiß mehr als du!$"
#else
	.string "The world of POKéMON is deep.\p"
	.string "There are still lots of things we\n"
	.string "don't know.\p"
	.string "But I know more than you do!$"
#endif

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
#if GERMAN
	.string "Wa-wa-was?$"
#else
	.string "Wha-wha-what?$"
#endif

NationalPark_Normal_Text_SchoolboyJack_After:
#if GERMAN
	.string "Es gibt viel zu lernen.\p"
	.string "Zum Beispiel…\p"
	.string "Es gibt viele verschiedene TM.\p"
	.string "Getauschte Pokémon steigen\n"
	.string "schneller im Level auf.$"
#else
	.string "There is a lot to learn.\p"
	.string "For example…\p"
	.string "There are lots of different TMs.\p"
	.string "Traded POKéMON level up faster.$"
#endif

NationalPark_Normal_Text_JackRegister:
#if GERMAN
	.string "Es gibt viel zu lernen.\p"
	.string "Zum Beispiel…\p"
	.string "Es gibt viele verschiedene TM.\p"
	.string "Getauschte Pokémon steigen\n"
	.string "schneller im Level auf.$"
#else
	.string "There is a lot to learn.\p"
	.string "For example…\p"
	.string "There are lots of different TMs.\p"
	.string "Traded POKéMON level up faster.$"
#endif

NationalPark_Normal_Text_JackRematchIntro:
#if GERMAN
	.string "Seit unserem letzten Kampf habe ich\n"
	.string "viel gelernt! Los geht's!$"
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
	.string "Es gibt viel zu lernen.\p"
	.string "Zum Beispiel…\p"
	.string "Es gibt viele verschiedene TM.\p"
	.string "Getauschte Pokémon steigen\n"
	.string "schneller im Level auf.$"
#else
	.string "There is a lot to learn.\p"
	.string "For example…\p"
	.string "There are lots of different TMs.\p"
	.string "Traded POKéMON level up faster.$"
#endif

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
#if GERMAN
	.string "Meine Pokémon sind einfach zum\n"
	.string "Verlieben.\p"
	.string "Lass mich dir zeigen, wie stolz ich\n"
	.string "auf meine Lieblinge bin.$"
#else
	.string "My POKéMON are simply darling.\p"
	.string "Let me tell you how proud my\n"
	.string "darlings make me.$"
#endif

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
#if GERMAN
	.string "Beim Stolz schlage ich dich, aber…$"
#else
	.string "I can beat you in pride, but…$"
#endif

NationalPark_Normal_Text_PokefanFBeverly_After:
#if GERMAN
	.string "Ich muss sagen, deine Pokémon sind\n"
	.string "auch ziemlich niedlich.$"
#else
	.string "I must say, your POKéMON are quite\n"
	.string "cute, too.$"
#endif

NationalPark_Normal_Text_PokefanmWilliam_Seen:
#if GERMAN
	.string "Wir lieben unsere Pokémon, auch\n"
	.string "wenn sie uns nicht mögen.\p"
	.string "Das heißt es, ein Fan zu sein.$"
#else
	.string "We adore our POKéMON, even if they\n"
	.string "dislike us.\p"
	.string "That's what being a FAN is about.$"
#endif

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
#if GERMAN
	.string "M-meine Pokémon!$"
#else
	.string "M-my POKéMON!$"
#endif

NationalPark_Normal_Text_PokefanmWilliam_After:
#if GERMAN
	.string "Ich habe den Kampf verloren, aber\n"
	.string "meine Pokémon gewinnen den Preis\l"
	.string "für die Niedlichsten.$"
#else
	.string "I lost the battle, but my POKéMON\n"
	.string "win the prize for being most\l"
	.string "lovely.$"
#endif

NationalPark_Normal_Text_LassKrise_Seen:
#if GERMAN
	.string "Hallo? Warum starrst du mich so an?\p"
	.string "Oh, ein Kampf?$"
#else
	.string "Hello? Why are you staring at me?\p"
	.string "Oh, a battle?$"
#endif

NationalPark_Normal_Text_LassKrise_Beaten:
#if GERMAN
	.string "…Hmmm…$"
#else
	.string "…Hmmm…$"
#endif

NationalPark_Normal_Text_LassKrise_After:
#if GERMAN
	.string "Ich dachte, du starrst mich an,\n"
	.string "weil ich so süß bin!$"
#else
	.string "I thought you were staring at me\n"
	.string "because I'm cute!$"
#endif

NationalPark_Normal_Text_BeverlyRegister:
#if GERMAN
	.string "Ich muss sagen, deine Pokémon sind\n"
	.string "auch ziemlich niedlich.$"
#else
	.string "I must say, your POKéMON are quite\n"
	.string "cute, too.$"
#endif

NationalPark_Normal_Text_BeverlyHasItem:
#if GERMAN
	.string "Oh, hallo! Ich habe etwas für dich.\p"
	.string "Nimm es bitte als Zeichen meiner\n"
	.string "Dankbarkeit!$"
#else
	.string "Oh, hello! I have something\n"
	.string "for you.\p"
	.string "Please take it as a token of\n"
	.string "my appreciation!$"
#endif

NationalPark_Normal_Text_BeverlyGaveItem:
#if GERMAN
	.string "Meine lieben Pokémon und ich\n"
	.string "drücken dir die Daumen!$"
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
