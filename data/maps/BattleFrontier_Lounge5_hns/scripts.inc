BattleFrontier_Lounge5_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman_hns::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns::
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

BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns::
#if GERMAN
	.string "Booh!\n"
	.string "Fiesling!$"
#else
	.string "Boo!\n"
	.string "Cheapie!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow_hns::
#if GERMAN
	.string "Hmhm…\p"
	.string "Dieses hier sagt, es kämpft gern!\n"
	.string "Es kämpft sogar, wenn es viele\l"
	.string "Wehwehchen hat!$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow_hns::
#if GERMAN
	.string "Hmhm…\p"
	.string "Dieses hier sagt, es kämpft gern!\n"
	.string "Aber wenn es genug Wehwehchen hat,\l"
	.string "macht es sich Sorgen um sich selbst!$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow_hns::
#if GERMAN
	.string "Hmhm…\p"
	.string "Dieses hier sagt, es kämpft gern!\n"
	.string "Aber wenn es genug Wehwehchen hat,\l"
	.string "wird es heimtückisch!$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow_hns::
#if GERMAN
	.string "Hmhm…\p"
	.string "Dieses hier sagt, es passt auf sich auf!\n"
	.string "Aber wenn es genug Wehwehchen hat,\l"
	.string "schlägt es zurück!$"
#else
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow_hns::
#if GERMAN
	.string "Hmhm…\p"
	.string "Dieses hier sagt, es passt auf sich auf!\n"
	.string "Es macht sich Sorgen um sich selbst,\l"
	.string "egal wie viele Wehwehchen es hat!$"
#else
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself whether\l"
	.string "or not it has a lot of ouchies!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow_hns::
#if GERMAN
	.string "Hmhm…\p"
	.string "Dieses hier sagt, es passt auf sich auf!\n"
	.string "Aber wenn es genug Wehwehchen hat,\l"
	.string "wird es heimtückisch!$"
#else
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow_hns::
#if GERMAN
	.string "Hmhm…\p"
	.string "Dieses hier sagt, es ist gern\n"
	.string "heimtückisch!\l"
	.string "Aber wenn es genug Wehwehchen hat,\l"
	.string "schlägt es zurück!$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow_hns::
#if GERMAN
	.string "Hmhm…\p"
	.string "Dieses hier sagt, es ist gern\n"
	.string "heimtückisch!\l"
	.string "Aber wenn es genug Wehwehchen hat,\l"
	.string "macht es sich Sorgen um sich selbst!$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow_hns::
#if GERMAN
	.string "Hmhm…\p"
	.string "Dieses hier sagt, es ist gern\n"
	.string "heimtückisch!\l"
	.string "Es ist auch mit vielen Wehwehchen noch\l"
	.string "heimtückisch!$"
#else
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"
#endif

BattleFrontier_Lounge5_Text_NatureGirlEgg_hns::
#if GERMAN
	.string "Du bist komisch! Das ist ein Ei. Das\n"
	.string "schläft doch! Wie soll ich damit reden?!$"
#else
	.string "That's silly! An EGG is asleep!\n"
	.string "I can't talk to it!$"
#endif

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns::
#if GERMAN
	.string "Wie charmant!\n"
	.string "Diese kleine Dame hier behauptet, sie\l"
	.string "könne die Pokémon verstehen!$"
#else
	.string "How charming!\n"
	.string "That little lady claims she can\l"
	.string "understand POKéMON!$"
#endif

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns::
#if GERMAN
	.string "Ich habe das Gefühl, dies kleine\n"
	.string "Mädchen sagt profunde Dinge!$"
#else
	.string "I have this feeling that the little girl\n"
	.string "is saying something profound.$"
#endif

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns::
#if GERMAN
	.string "Ich weiß was! Ich weiß was!\p"
	.string "Das kleine Mädchen spielt ganz oft\n"
	.string "im roten Haus!$"
#else
	.string "I know something!\p"
	.string "That little girl plays at the red house\n"
	.string "a lot!$"
#endif

