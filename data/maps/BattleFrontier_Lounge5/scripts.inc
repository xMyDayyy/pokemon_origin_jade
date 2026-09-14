BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
#if GERMAN
	.string "Hihihi! Ich kann die Gedanken\n"
	.string "von Pokémon lesen!\p"
	.string "Bitte! Darf ich deine Pokémon mal\n"
	.string "sehen? Bitte, bitte, bitte, bitte…$"
#else
	.string "Ehehe!\n"
	.string "I can tell what POKéMON are thinking!\p"
	.string "Please!\n"
	.string "Can I see your POKéMON?$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
#if GERMAN
	.string "Booh!\n"
	.string "Fiesling!$"
#else
	.string "Boo!\n"
	.string "Cheapie!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
#if GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, es liebt Kämpfe!\n"
	.string "Es wird sogar kämpfen, wenn es ganz\l"
	.string "viele Autschies hat!$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
#if GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, dass es Kämpfe mag.\n"
	.string "Tut es sich im Kampf sehr weh, wird es\l"
	.string "sich um sich selbst kümmern.$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
#if GERMAN
	.string "Hmm…\p"
	.string "Dieses hier sagt, es liebt Kämpfe!\n"
	.string "Aber wenn es genug Autschies hat, wird\l"
	.string "es heimtückisch.$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
#if GERMAN
	.string "Hmm…\p"
	.string "Dieses kümmert sich um sich selbst.\n"
	.string "Aber wenn es genug Autschies hat, wird\l"
	.string "es sich wehren!$"
#else
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
#if GERMAN
	.string "Hmm…\p"
	.string "Dieses kümmert sich um sich selbst.\n"
	.string "Egal, ob es Autschies hat oder nicht.$"
#else
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself whether\l"
	.string "or not it has a lot of ouchies!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
#if GERMAN
	.string "Hmm…\p"
	.string "Dieses passt auf sich selbst auf. Hat\n"
	.string "es genug Autschies, wird es\l"
	.string "heimtückisch.$"
#else
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
#if GERMAN
	.string "Hmm…\p"
	.string "Dieses hier liebt es, sich\n"
	.string "anzuschleichen. Tut ihm aber zu viel\l"
	.string "weh, dann wird es sich wehren.$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
#if GERMAN
	.string "Hmm…\p"
	.string "Dieses hier liebt es, heimtückisch zu\n"
	.string "sein. Tut es sich im Kampf sehr weh,\l"
	.string "kümmert es sich um sich selbst.$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
#if GERMAN
	.string "Hmm…\p"
	.string "Dieses hier liebt es, heimtückisch zu\n"
	.string "sein. Auch wenn es ganz viele Autschies\l"
	.string "hat, wird es das tun.$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlEgg::
#if GERMAN
	.string "Du bist komisch! Das ist ein Ei. Das\n"
	.string "schläft doch! Wie soll ich damit reden?!$"
#else
	.string "That's silly! An EGG is asleep!\n"
	.string "I can't talk to it!$"
#endif

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
#if GERMAN
	.string "Wie charmant!\n"
	.string "Diese kleine Dame hier behauptet, sie\l"
	.string "könne die Pokémon verstehen!$"
#else
	.string "How charming!\n"
	.string "That little lady claims she can\l"
	.string "understand POKéMON!$"
#endif

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
#if GERMAN
	.string "Ich habe das Gefühl, dies kleine\n"
	.string "Mädchen sagt profunde Dinge!$"
#else
	.string "I have this feeling that the little girl\n"
	.string "is saying something profound.$"
#endif

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
#if GERMAN
	.string "Ich weiß was! Ich weiß was!\p"
	.string "Das kleine Mädchen spielt ganz oft\n"
	.string "im roten Haus!$"
#else
	.string "I know something!\p"
	.string "That little girl plays at the red house\n"
	.string "a lot!$"
#endif

