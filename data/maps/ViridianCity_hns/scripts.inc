ViridianCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_OnFrame
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_OnFrame::
	map_script_2 VAR_OAK_MT_SILVER_CALL, 1, ViridianCity_EventScript_OakCall
	.2byte 0

ViridianCity_EventScript_OakCall::
	lock
	setspeaker ViridianCity_Text_OakName
	pokenavcall ViridianCity_Text_OakCall
	waitmessage
	delay 30
	setvar VAR_OAK_MT_SILVER_CALL, 2
	release
	end

ViridianCity_Text_OakName:
#if GERMAN
	.string "Oak$"
#else
	.string "OAK$"
#endif

ViridianCity_Text_OakCall:
#if GERMAN
	.string "Eich: Ah, {PLAYER}!\p"
	.string "Komm und besuche mich im Labor in\n"
	.string "Alabastia, wenn du Zeit hast.$"
#else
	.string "OAK: Ah, {PLAYER}!\p"
	.string "Come and see my at my LAB in\n"
	.string "PALLET TOWN when you get the\l"
	.string "chance.$"
#endif

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_DREAM_EATER, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisher, MSGBOX_NPC
	giveitem ITEM_TM_DREAM_EATER
	setflag FLAG_GOT_VIRIDIAN_TM_DREAM_EATER
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
#if GERMAN
	.string "Hey, du da! Krächz… warte mal!\n"
	.string "Hör mir gefälligst zu!\p"
	.string "Ich sehe vielleicht alt aus, aber als ich\n"
	.string "noch jung war, war ich eine ziemlich\l"
	.string "große Nummer mit dem Pokéball!\p"
	.string "Nimmst du mir das ab, Kurzbein?$"
#else
	.string "Hey, kid! I just had a double shot\n"
	.string "of espresso, and I am wired!\p"
	.string "I need to talk to someone, so you'll\n"
	.string "have to do!\p"
	.string "I might not look like much now, but\n"
	.string "I was an expert at catching POKéMON.\p"
	.string "Do you believe me?$"
#endif

ViridianCity_Text_CoffeeGramps_Believed:
#if GERMAN
	.string "Na eben! Was denn auch sonst?\n"
	.string "Natürlich nimmst du mir das ab!$"
#else
	.string "Good, good. Yes, I was something\n"
	.string "out of the ordinary, let me tell\l"
	.string "you!$"
#endif

ViridianCity_Text_CoffeeGramps_Doubted:
#if GERMAN
	.string "Was? Du ungezogene Rotznase!\p"
	.string "Wenn ich nur etwas jünger wäre, würde\n"
	.string "ich dir schon zeigen, wo’s langgeht!$"
#else
	.string "What? You little whelp!\p"
	.string "If I were just a bit younger, I'd\n"
	.string "show you a thing or two. Humph!$"
#endif

ViridianCity_Text_GrampsNearGym:
#if GERMAN
	.string "Bis vor Kurzem gab es in dieser\n"
	.string "Pokémon-Arena keinen Leiter…\p"
	.string "Aber jetzt hat ein junger Mann aus\n"
	.string "Alabastia den Posten übernommen.\p"
	.string "Aber er ist gerade nicht da…$"
#else
	.string "This GYM didn't have a LEADER\n"
	.string "until recently.\p"
	.string "A young man from PALLET became\n"
	.string "the LEADER, but he's often away.$"
#endif

ViridianCity_Text_GrampsNearGym_BlueReturned:
#if GERMAN
	.string "Wirst du den Arenaleiter\n"
	.string "herausfordern?\p"
	.string "Viel Glück! Du wirst es brauchen.$"
#else
	.string "Are you going to battle the\n"
	.string "LEADER?\p"
	.string "Good luck to you. You'll need it.$"
#endif

ViridianCity_Text_DreamEaterFisherNew:
	.string "Gähn!\p"
	.string "Ich bin wohl in\n"
	.string "der Sonne eingeschlafen.\p"
	.string "Was? Ich erinnere dich an Jemand?\p"
	.string "Keine Ahnung. Hier, nimm dies.$"

ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "…Zzzzz…$"

ViridianCity_Text_DreamEaterFisher:
#if GERMAN
	.string "Gähn! Ich bin in der Sonne eingenickt!\n"
	.string "Ich hatte einen ganz seltsamen Traum,\l"
	.string "in dem Traumato meine Träume frisst!\l"
	.string "…Nanu? Wo kommt denn diese TM her?\p"
	.string "Schauder…\n"
	.string "Das gefällt mir nicht!\l"
	.string "Hier, nimm du diese TM!$"
#else
	.string "Yawn!\p"
	.string "I must have dozed off in the sun.\p"
	.string "…I had this dream about a DROWZEE\n"
	.string "eating my dream. Weird, huh?\p"
	.string "Huh? What's this?\p"
	.string "Where did this TM come from?\p"
	.string "This is spooky! Here, you can have\n"
	.string "this TM.$"
#endif

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
#if GERMAN
	.string "Die TM85 enthält… die Attacke…\n"
	.string "Traum… fresser…\l"
	.string "…Schnarch…$"
#else
	.string "TM42 contains DREAM EATER…\p"
	.string "…Zzzzz…$"
#endif

ViridianCity_Text_Youngster:
#if GERMAN
	.string "Ich habe gehört, dass über den ganzen\n"
	.string "Vertania-Wald viele unsichtbare Items\l"
	.string "verstreut liegen!$"
#else
	.string "I heard that there are many items\n"
	.string "on the ground in VIRIDIAN FOREST.$"
#endif

ViridianCity_Text_Sign:
#if GERMAN
	.string "Vertania City\p"
	.string "Das Immergrüne Paradies$"
#else
	.string "VIRIDIAN CITY\p"
	.string "The Eternally Green Paradise$"
#endif

ViridianCity_Text_GymSign:
#if GERMAN
	.string "Pokémon-Arena von Vertania City\n"
	.string "Leiter: …\l"
	.string "Der Rest des Textes ist unlesbar!$"
#else
	.string "VIRIDIAN CITY POKéMON GYM\n"
	.string "LEADER: …\p"
	.string "The rest of the text is illegible…$"
#endif

ViridianCity_Text_WelcomeSign:
#if GERMAN
	.string "Willkommen in Vertania City,\n"
	.string "dem Tor zum Indigo Plateau$"
#else
	.string "WELCOME TO VIRIDIAN CITY,\p"
	.string "THE GATEWAY TO INDIGO PLATEAU$"
#endif

ViridianCity_Text_TrainerHouseSign:
#if GERMAN
	.string "Trainer-Haus\n"
	.string "Der Club, in dem die Top-Trainer kämpfen$"
#else
	.string "TRAINER HOUSE\p"
	.string "The Club for Top Trainer Battles$"
#endif
