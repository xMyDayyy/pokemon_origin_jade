MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
#if IS_HNS
	goto_if_set FLAG_RECEIVED_HOENN_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
#else
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
#endif
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
#if IS_HNS
	setflag FLAG_RECEIVED_HOENN_BIKE
#else
	setflag FLAG_RECEIVED_BIKE
#endif
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
#if GERMAN
	.string "Nun, was haben wir denn hier?\n"
	.string "Einen höchst energetischen Kunden!\p"
	.string "Ich? Du kannst Radla zu mir sagen.\n"
	.string "Ich bin der Besitzer des Fahrrad-Shops.$"
#else
	.string "Well, well, what have we here?\n"
	.string "A most energetic customer!\p"
	.string "Me? You may call me RYDEL.\n"
	.string "I'm the owner of this cycle shop.$"
#endif

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
#if GERMAN
	.string "Radla: Deine Turbotreter…\n"
	.string "Die sehen ja wirklich schmuddelig aus…\l"
	.string "\p"
	.string "Kommst du von weit her?$"
#else
	.string "RYDEL: Your RUNNING SHOES…\n"
	.string "They're awfully filthy.\p"
	.string "Did you come from far away?$"
#endif

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
#if GERMAN
	.string "Radla: Stimmt das wirklich?\p"
	.string "Dann kannst du, glaube ich, keines\n"
	.string "meiner Fahrräder gebrauchen.$"
#else
	.string "RYDEL: Is that right?\p"
	.string "Then, I guess you have no need for\n"
	.string "any of my BIKES.$"
#endif

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
#if GERMAN
	.string "Radla: Hm, hm… … … … …\n"
	.string "… … … … … … … …\p"
	.string "Du kommst den ganzen Weg von\n"
	.string "Wurzelheim her?\p"
	.string "Meine Güte!\n"
	.string "Das ist unwahrscheinlich weit weg!\p"
	.string "Wenn du eines meiner Räder hättest,\n"
	.string "könntest du leicht überall hin und den\l"
	.string "Wind in den Haaren spüren!\p"
	.string "Ich sag dir was!\n"
	.string "Ich werde dir ein Rad geben!\p"
	.string "Oh, eine Sekunde!\p"
	.string "Ich sollte dir sagen, dass es zwei\n"
	.string "verschiedene Räder gibt!\p"
	.string "Das Eilrad und das Kunstrad!\p"
	.string "Eilräder für Leute, die den Wind in\n"
	.string "den Haaren spüren wollen!\p"
	.string "Kunsträder für Leute, die die Techniken\n"
	.string "des Radfahrens beherrschen wollen!\p"
	.string "Da ich ein richtig weiches Herz habe,\n"
	.string "darfst du dir eines aussuchen!\p"
	.string "Welches möchtest du haben?$"
#else
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from LITTLEROOT?\p"
	.string "My goodness!\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my BIKES, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!\p"
	.string "I'll tell you what!\n"
	.string "I'll give you a BIKE!\p"
	.string "Oh, wait a second!\p"
	.string "I forgot to tell you that there are\n"
	.string "two kinds of BIKES!\p"
	.string "They are the MACH BIKE and\n"
	.string "the ACRO BIKE!\p"
	.string "The MACH BIKE is for cyclists who want\n"
	.string "to feel the wind with their bodies!\p"
	.string "And an ACRO BIKE is for those who\n"
	.string "prefer technical rides!\p"
	.string "I'm a real sweetheart, so you can\n"
	.string "have whichever one you like!\p"
	.string "Which one will you choose?$"
#endif

MauvilleCity_BikeShop_Text_ChoseMachBike:
#if GERMAN
	.string "{PLAYER} wählt das Eilrad.$"
#else
	.string "{PLAYER} chose the MACH BIKE.$"
#endif

MauvilleCity_BikeShop_Text_ChoseAcroBike:
#if GERMAN
	.string "{PLAYER} wählt das Kunstrad.$"
#else
	.string "{PLAYER} chose the ACRO BIKE.$"
#endif

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
#if GERMAN
	.string "Radla: Wenn du die Räder tauschen\n"
	.string "möchtest, komm einfach wieder vorbei!$"
#else
	.string "RYDEL: If you get the urge to switch\n"
	.string "BIKES, just come see me!$"
#endif

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
#if GERMAN
	.string "Radla: Oh. Du möchtest die Räder\n"
	.string "tauschen?$"
#else
	.string "RYDEL: Oh? Were you thinking about\n"
	.string "switching BIKES?$"
#endif

MauvilleCity_BikeShop_Text_IllSwitchBikes:
#if GERMAN
	.string "Radla: Kein Problem!\n"
	.string "Ich tausche die Räder für dich aus!$"
#else
	.string "RYDEL: Okay, no problem!\n"
	.string "I'll switch BIKES for you!$"
#endif

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
#if GERMAN
	.string "{PLAYER} bekommt für das Eilrad ein\n"
	.string "Kunstrad.$"
#else
	.string "{PLAYER} got the MACH BIKE exchanged\n"
	.string "for an ACRO BIKE.$"
#endif

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
#if GERMAN
	.string "{PLAYER} bekommt für das Kunstrad ein\n"
	.string "Eilrad.$"
#else
	.string "{PLAYER} got the ACRO BIKE exchanged\n"
	.string "for a MACH BIKE.$"
#endif

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
#if GERMAN
	.string "Radla: Wunderbar!\n"
	.string "Ich freue mich, dass es dir gefällt!$"
#else
	.string "RYDEL: Good, good!\n"
	.string "I'm happy that you like it!$"
#endif

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
#if GERMAN
	.string "Oh? Was ist mit dem Rad geschehen,\n"
	.string "das ich dir gegeben habe?\p"
	.string "Ach so, du hast es in deinem PC\n"
	.string "gelagert.\p"
	.string "Nun, hol es heraus, und ich werde es mit\n"
	.string "Freuden gegen ein anderes tauschen!\p"
	.string "Möge der Wind dir stets im Rücken sein\n"
	.string "bei deinem Abenteuer!$"
#else
	.string "Oh? What happened to that BIKE\n"
	.string "I gave you?\p"
	.string "Oh, I get it, you stored it using your PC.\p"
	.string "Well, take it out of PC storage,\n"
	.string "and I'll be happy to exchange it!\p"
	.string "May the wind always be at your back\n"
	.string "on your adventure!$"
#endif

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
#if GERMAN
	.string "Ich lerne etwas über Räder, während ich\n"
	.string "hier arbeite.\p"
	.string "Wenn du eine Anleitung brauchst, wie\n"
	.string "man Rad fährt - da vorne findest du\l"
	.string "einige Handbücher.$"
#else
	.string "I'm learning about BIKES while\n"
	.string "I work here.\p"
	.string "If you need advice on how to ride your\n"
	.string "BIKE, there're a couple handbooks in\l"
	.string "the back.$"
#endif

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
#if GERMAN
	.string "Ein Handbuch zum Eilrad.\p"
	.string "Welche Seite möchtest du lesen?$"
#else
	.string "It's a handbook on the MACH BIKE.\p"
	.string "Which page do you want to read?$"
#endif

MauvilleCity_BikeShop_Text_HowToRideMachBike:
#if GERMAN
	.string "Mit Hilfe des + Steuerkreuzes lässt\n"
	.string "sich das Rad lenken.\p"
	.string "Es wird immer schneller, wenn es\n"
	.string "einmal fährt.\p"
	.string "Lass das Steuerkreuz los, um das\n"
	.string "Rad anzuhalten.\p"
	.string "Eine andere Seite lesen?$"
#else
	.string "A BIKE moves in the direction that\n"
	.string "the + Control Pad is pressed.\p"
	.string "It will speed up once it gets rolling.\p"
	.string "To stop, release the + Control Pad.\n"
	.string "The BIKE will slow to a stop.\p"
	.string "Want to read a different page?$"
#endif

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
#if GERMAN
	.string "Ein Eilrad ist sehr schnell und kann\n"
	.string "nicht schnell gestoppt werden.\p"
	.string "Das Kurvenfahren ist sehr schwierig.\p"
	.string "Lasse das + Steuerkreuz kurz los und\n"
	.string "bremse, bevor du an eine Kurve kommst.\l"
	.string "\p"
	.string "Eine andere Seite lesen?$"
#else
	.string "A MACH BIKE is speedy, but it can't\n"
	.string "stop very quickly.\p"
	.string "It gets a little tricky to get around\n"
	.string "a corner.\p"
	.string "Release the + Control Pad a little\n"
	.string "before the corner and slow down.\p"
	.string "Want to read a different page?$"
#endif

MauvilleCity_BikeShop_Text_SandySlopes:
#if GERMAN
	.string "In der ganzen Hoenn-Region gibt es\n"
	.string "sandige Gefälle.\p"
	.string "Der lose Sand erlaubt es nicht, diese\n"
	.string "Gefälle normal zu erklettern.\p"
	.string "Aber mit einem Eilrad können auch\n"
	.string "diese Gefälle gemeistert werden.\p"
	.string "Eine andere Seite lesen?$"
#else
	.string "There are small sandy slopes\n"
	.string "throughout the HOENN region.\p"
	.string "The loose, crumbly sand makes it\n"
	.string "impossible to climb normally.\p"
	.string "But if you have a MACH BIKE, you can\n"
	.string "zip up a sandy slope.\p"
	.string "Want to read a different page?$"
#endif

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
#if GERMAN
	.string "Ein Handbuch zum Kunstrad.\p"
	.string "Welche Seite möchtest du lesen?$"
#else
	.string "It's a handbook on the ACRO BIKE.\p"
	.string "Which page do you want to read?$"
#endif

MauvilleCity_BikeShop_Text_Wheelies:
#if GERMAN
	.string "Drücke während des Fahrens den\n"
	.string "B-Knopf, um das Vorderrad anzuheben.\p"
	.string "Ist das Vorderrad angehoben, können\n"
	.string "mithilfe des Steuerkreuzes Sprünge\l"
	.string "ausgeführt werden.\p"
	.string "Diese Technik nennt sich Wheelie.\p"
	.string "Eine andere Seite lesen?$"
#else
	.string "Press the B Button while riding,\n"
	.string "and the front wheel lifts up.\p"
	.string "You can zip around with the front\n"
	.string "wheel up using the + Control Pad.\p"
	.string "This technique is called a wheelie.\p"
	.string "Want to read a different page?$"
#endif

MauvilleCity_BikeShop_Text_BunnyHops:
#if GERMAN
	.string "Wird der B-Knopf gedrückt, kann auf\n"
	.string "der Stelle gehüpft werden.\p"
	.string "Diese Technik nennt sich Hoppeln.\p"
	.string "Dabei kann gleichzeitig gefahren\n"
	.string "werden.\p"
	.string "Eine andere Seite lesen?$"
#else
	.string "Keeping the B Button pressed,\n"
	.string "your BIKE can hop on the spot.\p"
	.string "This technique is called a bunny hop.\p"
	.string "You can ride while hopping, too.\p"
	.string "Want to read a different page?$"
#endif

MauvilleCity_BikeShop_Text_Jumps:
#if GERMAN
	.string "Drücke gleichzeitig den B-Knopf und\n"
	.string "das Steuerkreuz, um zu springen.\p"
	.string "Drücke das + Steuerkreuz seitlich, um\n"
	.string "einen seitlichen Sprung auszuführen.\p"
	.string "Drücke es nach hinten, um die Richtung\n"
	.string "zu ändern.\p"
	.string "Eine andere Seite lesen?$"
#else
	.string "Press the B Button and the + Control\n"
	.string "Pad at the same time to jump.\p"
	.string "Press the + Control Pad to the side\n"
	.string "to jump sideways.\p"
	.string "Press it backwards to make the BIKE\n"
	.string "change directions while jumping.\p"
	.string "Want to read a different page?$"
#endif

