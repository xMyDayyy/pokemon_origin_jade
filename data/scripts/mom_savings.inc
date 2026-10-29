EventScript_MomGiftCall_Item::
	lockall
	pokenavcall Mom_Text_GiftCall_Item
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Berry::
	lockall
	pokenavcall Mom_Text_GiftCall_Berry
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Decoration::
	lockall
	pokenavcall Mom_Text_GiftCall_Decoration
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

Mom_Text_GiftCall_Item:
#if GERMAN
	.string "Mama: Hallo, {PLAYER}! Wie geht\n"
	.string "es dir?\p"
	.string "Ich habe heute beim Einkaufen ein\n"
	.string "nützliches Item gefunden und es\l"
	.string "dir von deinem Geld gekauft! Tut\l"
	.string "mir leid!\p"
	.string "Ich habe es auf deinen PC\n"
	.string "übertragen. Du wirst es sicher\l"
	.string "brauchen können!\p"
	.string "Mach’s gut!$"
#else
	.string "MOM: Hi, sweetie!\p"
	.string "I bought something nice for you\n"
	.string "with your savings!\p"
	.string "I sent it to your PC. Take care!$"
#endif

Mom_Text_GiftCall_Berry:
#if GERMAN
	.string "Mama: Hallo, {PLAYER}! Wie geht\n"
	.string "es dir?\p"
	.string "Ich habe heute beim Einkaufen\n"
	.string "leckere Beeren gefunden und sie\l"
	.string "dir von deinem Geld gekauft! Tut\l"
	.string "mir leid!\p"
	.string "Ich habe sie auf deinen PC\n"
	.string "übertragen. Du wirst sie sicher\l"
	.string "brauchen können!\p"
	.string "Mach’s gut!$"
#else
	.string "MOM: Hi, sweetie!\p"
	.string "I found some nice BERRIES at the\n"
	.string "store for you!\p"
	.string "I sent them to your PC. Take\n"
	.string "care!$"
#endif

Mom_Text_GiftCall_Decoration:
#if GERMAN
	.string "Mama: Hallo, {PLAYER}! Wie geht\n"
	.string "es dir?\p"
	.string "Ich habe heute beim Einkaufen\n"
	.string "eine niedliche Poképuppe für dein\l"
	.string "Zimmer gefunden! Tut mir leid!\p"
	.string "Sieh dir die Dekorationen an,\n"
	.string "wenn du wieder zu Hause bist!\p"
	.string "Mach’s gut!$"
#else
	.string "MOM: Hi, sweetie!\p"
	.string "I bought a cute POKé DOLL for\n"
	.string "your room!\p"
	.string "Check your DECORATIONS when you\n"
	.string "come home. Take care!$"
#endif
