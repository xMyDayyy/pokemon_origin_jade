CianwoodHouse3_hns_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	@ Johto badge 1 (Falkner)
	setvar VAR_0x8004, 0
	special CheckJohtoBadge
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_KirkReturnShuckie
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
#if GERMAN
	.string "I-ich bin mit den Nerven am Ende…\p"
	.string "Irgend so ein fürchterlicher Junge in\n"
	.string "deinem Alter mit einem finsteren Blick\l"
	.string "und langen Haaren hat mir einfach meine\l"
	.string "preisgekrönten Pokémon weggenommen!\p"
	.string "Eins habe ich zwar noch übrig, aber ich\n"
	.string "habe Angst, dass er wieder zuschlägt!\p"
	.string "Du siehst stark aus! Bitte passe\n"
	.string "eine Weile auf dieses Pokémon auf!$"
#else
	.string "I, I'm in shock!\p"
	.string "A guy about your age with piercing\n"
	.string "eyes and long hair came in.\p"
	.string "He scared me into giving him my\n"
	.string "prized POKéMON!\p"
	.string "I still have one left, but what if\n"
	.string "he comes back?\p"
	.string "You look strong. Could you look\n"
	.string "after my POKéMON for a while?$"
#endif

CianwoodCity_Text_ManiacTakeCareShuckle:
#if GERMAN
	.string "V-v-vielen herzlichen Dank!\n"
	.string "Bitte pass gut darauf auf!$"
#else
	.string "Oh, thank you!\p"
	.string "Take good care of it, please!$"
#endif

CianwoodCity_Text_ManiacGotShuckle:
#if GERMAN
	.string "{PLAYER} erhält das Pokémon\n"
	.string "des Sammlers.$"
#else
	.string "{PLAYER} received a POKéMON.$"
#endif

CianwoodCity_Text_ManiacPartyFull:
#if GERMAN
	.string "In deinem Team ist kein Platz mehr.$"
#else
	.string "Your POKéMON party is full.$"
#endif

CianwoodCity_Text_ManiacIfHeComesBack:
#if GERMAN
	.string "U-u-und was soll ich dann tun, wenn er\n"
	.string "zurückkommt und wieder zuschlägt?$"
#else
	.string "Oh, no… What'll I do if he comes\n"
	.string "back?$"
#endif

CianwoodCity_Text_ManiacHowsdoing:
#if GERMAN
	.string "Wie geht es meinem Pokémon?$"
#else
	.string "Hi! How's my POKéMON?$"
#endif

CianwoodCity_Text_ManiacAskReturn:
#if GERMAN
	.string "Wie geht es meinem Pokémon?\p"
	.string "So langsam ist die Gefahr wohl gebannt.\n"
	.string "Kann ich jetzt mein Pokémon wieder\l"
	.string "zurückhaben?$"
#else
	.string "Hi! How's my POKéMON?\p"
	.string "I think I'm safe now, so may I\n"
	.string "have it back?$"
#endif

CianwoodCity_Text_ManiacThankYou:
#if GERMAN
	.string "Danke Schön$"
#else
	.string "Thank you!$"
#endif

CianwoodCity_Text_ManiacShuckleNotThere:
#if GERMAN
	.string "Hey, du hast mein Pokémon nicht\n"
	.string "bei dir.$"
#else
	.string "Hey, you don't have my POKéMON\n"
	.string "with you.$"
#endif

CianwoodCity_Text_ManiacShuckleLikesYou:
#if GERMAN
	.string "Mein Pokémon scheint dich ja richtig\n"
	.string "ins Herz geschlossen zu haben!\p"
	.string "In Ordnung, du kannst es behalten.\n"
	.string "Aber versprich mir, dass du es auch\l"
	.string "immer gut behandeln wirst!$"
#else
	.string "My POKéMON has come to like you.\p"
	.string "All right, you should keep it.\p"
	.string "But promise to be good to it!$"
#endif

CianwoodCity_Text_ManiacRobbed:
#if GERMAN
	.string "Huh, irgendwas stimmt nicht.$"
#else
	.string "Huh, something's not right.$"
#endif

CianwoodCity_Text_ManiacRobbed2:
#if GERMAN
	.string "D-d-da hätte ich mich auch gleich von\n"
	.string "diesem Jungen berauben lassen können!$"
#else
	.string "Oh, no, no… That's the same as\n"
	.string "being robbed.$"
#endif

CianwoodCity_Text_ManiacHappinessSpeech:
#if GERMAN
	.string "Für Pokémon ist es das höchste Glück,\n"
	.string "wenn sie bei jemandem sein dürfen, der\l"
	.string "sie gut behandelt.$"
#else
	.string "For POKéMON, happiness is being\n"
	.string "with a person who treats them well.$"
#endif

CianwoodCity_Text_ManiacLastMon:
#if GERMAN
	.string "Wenn ich mein Pokémon zurücknehme,\n"
	.string "was wirst du im Kampf benutzen?$"
#else
	.string "If I take my POKéMON back,\n"
	.string "what are you going to use\n"
	.string "in battle?$"
#endif


CianwoodCity_Text_ManiacReturnedMon:
#if GERMAN
	.string "{PLAYER} gab Shuckie zurück.$"
#else
	.string "{PLAYER} returned SHUCKIE.$"
#endif
