SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	@ Origin Jade: the Devon Parts delivery comes first.
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_DockAfterDelivery
	checkitem ITEM_DEVON_PARTS
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_SternsShipyard_1F_EventScript_DockAfterDelivery
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_DockAfterDelivery::
	goto_if_set FLAG_IS_HOENN_CHAMPION, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
#if IS_HNS
	@ HnS: Hoenn badge 7 (Tate and Liza).
	setvar VAR_0x8004, 6
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
#else
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
#endif
	goto SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
#if GERMAN
	.string "Ähmm… Wenn das hierhin gehört und das\n"
	.string "dahin…\p"
	.string "Wo gehört dieses dann hin?\n"
	.string "Und was ist mit diesem Dingsbums?\p"
	.string "Aaargh! Ich werde daraus einfach nicht\n"
	.string "schlau!$"
#else
	.string "Umm… If this goes here, and that\n"
	.string "goes over there…\p"
	.string "Then where does this thing go?\n"
	.string "And what about that doohickey?\p"
	.string "Aaargh! I can't make heads or tails\n"
	.string "of this!$"
#endif

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
#if GERMAN
	.string "Hm? Hallo, ich bin Bootmar.\p"
	.string "Kapt. Brigg hat mich damit beauftragt,\n"
	.string "eine Fähre zu konstruieren.\p"
	.string "Oh! Das da…\n"
	.string "Sind das Devon-waren?\p"
	.string "Aber, ähm… Das ist ein ungünstiger\n"
	.string "Zeitpunkt…\p"
	.string "Kapt. Brigg ist irgendwohin gegangen. Er\n"
	.string "sagte, er müsse was erledigen.\p"
	.string "Kann ich dich bitten, Kapt. Brigg zu\n"
	.string "suchen und ihm das Paket zu bringen?$"
#else
	.string "Hm?\n"
	.string "Hi, I'm DOCK.\p"
	.string "CAPT. STERN commissioned me to\n"
	.string "design a ferry.\p"
	.string "Oh! That there…\n"
	.string "Are they DEVON GOODS?\p"
	.string "But, hmm…\n"
	.string "This won't do…\p"
	.string "CAPT. STERN went off somewhere.\n"
	.string "He said he had some work to do.\p"
	.string "Could I get you to go find CAPT.\n"
	.string "STERN and deliver that to him?$"
#endif

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
#if GERMAN
	.string "Bootmar: Wo könnte Kapt. Brigg wohl\n"
	.string "hingegangen sein?\p"
	.string "Kannst du bitte Kapt. Brigg suchen und\n"
	.string "ihm die Waren übergeben?$"
#else
	.string "DOCK: Where could CAPT. STERN have\n"
	.string "gone off to?\p"
	.string "Could you go find CAPT. STERN and\n"
	.string "deliver that parcel to him?$"
#endif

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
#if GERMAN
	.string "Bootmar: Der Schiffsbau ist eine\n"
	.string "Kunst. \p"
	.string "Manche Dinge lassen sich auch durch\n"
	.string "Berechnungen nicht vorhersehen.\p"
	.string "Jemand, der das Meer kennt wie seine\n"
	.string "Westentasche, müsste mir helfen…$"
#else
	.string "DOCK: Shipbuilding is an art.\p"
	.string "A lot of things can't be figured out\n"
	.string "just by calculating.\p"
	.string "I really could use advice from a veteran\n"
	.string "who knows the seas…$"
#endif

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
#if GERMAN
	.string "Bootmar: Hallo! Mr. Brack hat sich\n"
	.string "bereit erklärt, uns zu helfen.\p"
	.string "Dank dieses erfahrenen Seemannes\n"
	.string "kommen wir zügig voran.$"
#else
	.string "DOCK: Hi! MR. BRINEY's joined us to\n"
	.string "lend us his help.\p"
	.string "Thanks to the veteran sailor, the\n"
	.string "ferry is steadily coming together.$"
#endif

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
#if GERMAN
	.string "Bootmar: Die Fähre ist bald fertig!\p"
	.string "Die neue MS Tide ist ein wahres\n"
	.string "Technikwunder!\p"
	.string "Aber ich denke doch, dass wir noch\n"
	.string "einiges besser machen können.\p"
	.string "Weißt du, die technische Entwicklung\n"
	.string "wird niemals abgeschlossen sein.$"
#else
	.string "DOCK: The ferry is finally ready!\p"
	.string "The new S.S. TIDAL is truly a marvel\n"
	.string "of technology!\p"
	.string "But, I get the feeling that we can\n"
	.string "make something even better.\p"
	.string "You know, there's never an end to\n"
	.string "technology's march.$"
#endif

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
#if GERMAN
	.string "Mr. Brack: Ah, {PLAYER}{KUN}!\n"
	.string "Es ist schon lange her!\p"
	.string "Aye, seit ich dich kennen gelernt habe,\n"
	.string "bin ich wieder voller Tatendrang.\p"
	.string "Also habe ich mich entschlossen,\n"
	.string "Bootmar beim Bau der Fähre zu helfen.\l"
	.string "\p"
	.string "Aye, so wie es aussieht, wird die Fähre\n"
	.string "viele Passagiere befördern können.\p"
	.string "Aber, weißt du, Bootmar ist wirklich\n"
	.string "eine besondere Persönlichkeit.\p"
	.string "Mit seinem technischen Wissen und\n"
	.string "meiner Erfahrung auf See werden wir ein\l"
	.string "ganz besonderes Schiff bauen, aye.$"
#else
	.string "MR. BRINEY: Ah, {PLAYER}{KUN}!\n"
	.string "It's been too long!\p"
	.string "Aye, since I met you, this old sea dog's\n"
	.string "been feeling frisky!\p"
	.string "So I've decided to help DOCK make\n"
	.string "a ferry.\p"
	.string "Aye, after all, a ferry would be able\n"
	.string "to carry a lot of people.\p"
	.string "But, you know, that DOCK is really\n"
	.string "something special.\p"
	.string "With his knack for technology and\n"
	.string "my experience, I'm sure that we can\l"
	.string "build one great ship, aye!$"
#endif

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
#if GERMAN
	.string "Die Jahreszeit, das Wetter, der Mond,\n"
	.string "der vom Himmel herabstrahlt…\p"
	.string "Das sind die Bedingungen, die die See\n"
	.string "so wechselhaft machen.\p"
	.string "Ganz genau!\n"
	.string "Die See ist wie ein lebendiges Wesen!$"
#else
	.string "The seasons, the weather, where\n"
	.string "the moon sits in the sky…\p"
	.string "These and other conditions make\n"
	.string "the sea change its expression.\p"
	.string "That's right!\n"
	.string "The sea is like a living thing!$"
#endif

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
#if GERMAN
	.string "Ich werde sehr schnell seekrank.\n"
	.string "Deshalb helfe ich lieber hier aus.$"
#else
	.string "I get seasick real easily.\n"
	.string "So I get to help out here instead.$"
#endif

