BattleFrontier_ExchangeServiceCorner_hns_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPDecorShop1
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPDecorShop2
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPVitaminShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPHoldItemShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokeBallClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPPokeBallShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPHoldItemShop2
	waitstate
	release
	end

@ Origin Jade: gems, seeds and newer hold items.
BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk3_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPHoldItemShop3
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PowerClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPPowerShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF_hns::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns:
#if GERMAN
	.string "Hallo, dies ist die Tauschecke.\p"
	.string "Wir tauschen deine Gewinnpunkte gegen\n"
	.string "großartige Preise ein.\p"
	.string "Bitte such dir einen Preis von dieser\n"
	.string "Liste aus.$"
#else
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"
#endif

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls_hns:
#if GERMAN
	.string "Oh, die sind so hübsch.\n"
	.string "Die hätte ich auch gerne!\l"
	.string "Niedliche Kissen!\l"
	.string "Große, fluffige Puppen!\l"
	.string "Kleine, fluffige Puppen!\l"
	.string "Ich würde sie am liebsten alle nehmen!$"
#else
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"
#endif

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant_hns:
#if GERMAN
	.string "Überlass das deiner Mami!\p"
	.string "Möchtest du irgendetwas haben, werde\n"
	.string "ich alles tun, damit du es bekommst.$"
#else
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"
#endif

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher_hns:
#if GERMAN
	.string "Hätte ich nur eines dieser Items hier,\n"
	.string "würden meine Pokémon viel stärker!\p"
	.string "Mit Sicherheit! Darauf kannst du\n"
	.string "wetten! Das steht fest!$"
#else
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"
#endif

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll_hns:
#if GERMAN
	.string "Häh? Was glotzt du denn so doof?\p"
	.string "Ich mag es nicht, wie du meine\n"
	.string "Plüschpuppe anstarrst!\p"
	.string "Wenn du auch so eine haben willst,\n"
	.string "besorg dir eine! Nicht wahr, Kussilla?$"
#else
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, SMOOCHUM?$"
#endif

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord_hns:
#if GERMAN
	.string "Weißt du was?\n"
	.string "Wenn du deine Ergebnisse hier in den\p"
	.string "Kampf-Einrichtungen stetig\n"
	.string "verbesserst, geben sie dir mehr\l"
	.string "Gewinnpunkte.$"
#else
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"
#endif
