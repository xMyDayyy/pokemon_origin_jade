GoldenrodCity_BillsHouse_hns_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed
	call Common_EventScript_AskNicknameGiftPartyMon



	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
#if GERMAN
	.string "Bill: Hi, {PLAYER}!\p"
	.string "Tu uns einen Gefallen und nimm dieses\n"
	.string "Evoli.\p"
	.string "Es kam hierher, als ich an der\n"
	.string "Zeitkapsel gearbeitet habe.\p"
	.string "Jemand sollte sich darum kümmern,\n"
	.string "aber ich gehe nicht gerne raus.\p"
	.string "Wirst du für mich mit ihm spielen,\n"
	.string "{PLAYER}?$"
#else
    .string "BILL: Hi, {PLAYER}! Do us a favor and\n"
    .string "take this EEVEE.\p"
    .string "It was left in our care while\n"
    .string "I was away working on my system.\p"
    .string "Someone has to take care of it,\n"
    .string "but I don't like being outside.\p"
    .string "Can I count on you to play with it,\n"
    .string "{PLAYER}?$"
#endif

BillHouse_Text_CountingOnYou:
#if GERMAN
	.string "Bill: Ich wusste, dass du es schaffst!\n"
	.string "Noch ein kleines Stück!\p"
	.string "Du bist einzigartig!\p"
	.string "O.K., ich zähle auf dich.\p"
	.string "Pass auf dich auf!$"
#else
    .string "BILL: I knew you'd come through!\p"
    .string "Way to go! You're the real deal!\p"
    .string "OK, I'm counting on you.\p"
    .string "Take good care of it!$"
#endif

BillHouse_Text_ReceivedEevee:
#if GERMAN
	.string "{PLAYER} erhält Evoli!$"
#else
    .string "{PLAYER} received EEVEE!$"
#endif

BillHouse_Text_EeveeMayEvolve:
#if GERMAN
	.string "Bill: Prof. Lind sagt, Evoli kann sich in\n"
	.string "neue, unbekannte Arten entwickeln.$"
#else
    .string "BILL: PROF.ELM claims EEVEE may\n"
    .string "evolve in new and unknown ways.$"
#endif

BillHouse_Text_PartyFull:
#if GERMAN
	.string "Moment! Du hast keinen Platz mehr in\n"
	.string "deinem Team.$"
#else
    .string "Whoa, wait. You can't carry any\n"
    .string "more POKéMON.$"
#endif

BillHouse_Text_NoEevee:
#if GERMAN
	.string "Oh, verstehe…$"
#else
    .string "Oh… Now what to do?$"
#endif

BillHouse_Text_PopWontWork:
#if GERMAN
	.string "Bill: Mein Paps arbeitet nicht.\p"
	.string "Er geht den ganzen Tag müßig.\p"
	.string "Er fängt an, zu nerven…$"
#else
    .string "BILL: My pop, he won't work. All he\n"
    .string "does is goof off all day long.\p"
    .string "He's getting to be a real headache…$"
#endif

BillHouse_Text_MomBeforeEcruteak:
#if GERMAN
	.string "Oh, du sammelst Pokémon?\p"
	.string "Mein Sohn Bill ist ein Experte.\p"
	.string "Er wurde gerade in das Pokémon-Center\n"
	.string "von Teak City gerufen.\p"
	.string "Mein Mann ging in die Spielhalle,\p"
	.string "ohne vorher anzurufen…$"
#else
    .string "Oh, you collect POKéMON? My son\n"
    .string "BILL is an expert.\p"
    .string "He just got called to the POKéMON\n"
    .string "CENTER in ECRUTEAK CITY.\p"
    .string "My husband went off to the GAME\n"
    .string "CORNER without being called…$"
#endif

BillHouse_Text_MomAfterEcruteak:
#if GERMAN
	.string "Mein Mann war als Maniac bekannt.\p"
	.string "Bill muss nach seinem Vater kommen.$"
#else
    .string "My husband was once known as a\n"
    .string "POKéMANIAC.\p"
    .string "BILL must have taken after his\n"
    .string "father.$"
#endif

BillHouse_Text_SisterUsefulNumber:
#if GERMAN
	.string "Bist du ein Trainer?\p"
	.string "Ich habe eine nützliche Telefonnummer\n"
	.string "für dich.$"
#else
    .string "Are you a TRAINER?\p"
    .string "I've got a useful phone number\n"
    .string "for you.$"
#endif

BillHouse_Text_RecordedBillsNumber:
#if GERMAN
	.string "{PLAYER} speichert Bills Nummer.$"
#else
    .string "{PLAYER} recorded BILL's number.$"
#endif

BillHouse_Text_SisterRefusedNumber:
#if GERMAN
	.string "Mein Bruder hat das\n"
	.string "PC-PokémonLagerungs-System erfunden.\p"
	.string "Ich wollte dir gerade Bills Nummer\n"
	.string "geben…$"
#else
    .string "My brother made the PC POKéMON\n"
    .string "storage system.\p"
    .string "I was going to give you BILL's\n"
    .string "number…$"
#endif

BillHouse_Text_SisterPhoneFull:
#if GERMAN
	.string "Du kannst keine Nummern mehr\n"
	.string "speichern.$"
#else
    .string "You can't record any more numbers.$"
#endif

BillHouse_Text_SisterStorageSystem:
#if GERMAN
	.string "Mein großer Bruder Bill hat das\n"
	.string "PC-Pokémon-Lagerungssystem erfunden.$"
#else
    .string "My big brother BILL made the PC\n"
    .string "POKéMON storage system.$"
#endif
