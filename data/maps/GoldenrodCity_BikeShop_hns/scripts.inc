GoldenrodCity_BikeShop_hns_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	@ Origin Jade: no second Bicycle if the one from Cerulean is in the bag.
	checkitem ITEM_BICYCLE
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_HasBike
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_BICYCLE
	setflag FLAG_RECEIVED_BIKE
	@ Origin Jade: Cerulean's bike shop and the Cycling Road gates check this flag.
	setflag FLAG_GOT_BICYCLE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_HasBike::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreedHasBike, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
#if GERMAN
	.string "Radfahren ist kinderleicht: Registriere\n"
	.string "das Rad einfach im Beutel, dann genügt\l"
	.string "ein Tastendruck.\p"
	.string "Wenn du schneller werden willst,\n"
	.string "musst du erst einmal anhalten!\p"
	.string "Das klingt seltsam, aber du kannst nur\n"
	.string "im Stand einen anderen Gang einlegen.\p"
	.string "Drücke im Stand die R-Taste, dann\n"
	.string "erreichst du beim nächsten Tritt viel\l"
	.string "höhere Geschwindigkeiten!$"
#else
	.string "Riding the BIKE is as simple as\n"
	.string "pressing a button if you\l"
	.string "REGISTER it from the BAG.\p"
	.string "If you need to go faster,\n"
	.string "you first need to come to a stop!\p"
	.string "That might seem like strange\n"
	.string "advice, but you can only change\l"
	.string "gears on the BIKE while stopped.\p"
	.string "Press your R button when stopped\n"
	.string "and the next time you pedal,\l"
	.string "you will reach greater speeds!$"
#endif

GoldenrodCity_BikeShop_Text_ClerkIntro:
#if GERMAN
	.string "…Seufz… Ich bin hierher gezogen, aber\n"
	.string "ich kann meine Fahrräder nicht\l"
	.string "verkaufen. Warum nur?\p"
	.string "Würdest du ein Fahrrad fahren\n"
	.string "und so Werbung machen?$"
#else
    .string "…sigh… I moved here, but I can't\n"
    .string "sell my BICYCLES. Why is that?\p"
    .string "Could you ride a BICYCLE and\n"
    .string "advertise for me?$"
#endif

GoldenrodCity_BikeShop_Text_ClerkAgreed:
#if GERMAN
	.string "Ja? Großartig!\p"
	.string "Gib mir bitte Namen und Nummer.\p"
	.string "Dann leihe ich dir ein Fahrrad.$"
#else
    .string "Really? Great!\p"
    .string "Give me your name and phone number,\n"
    .string "and I'll loan you a BICYCLE.$"
#endif

GoldenrodCity_BikeShop_Text_ClerkAgreedHasBike:
#if GERMAN
	.string "Ja? Großartig!\p"
	.string "Oh, du hast ja schon ein Fahrrad!\n"
	.string "Dann fahr damit überall herum und\l"
	.string "erzähl allen von unserem Laden!$"
#else
	.string "Really? Great!\p"
	.string "Oh, you already have a BICYCLE!\n"
	.string "Then ride it everywhere and tell\l"
	.string "everyone about our shop!$"
#endif

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
#if GERMAN
	.string "{PLAYER} leiht ein Fahrrad.$"
#else
    .string "{PLAYER} borrowed a BICYCLE.$"
#endif

GoldenrodCity_BikeShop_Text_Mainshop:
#if GERMAN
	.string "Seit wir aus Kanto hergezogen sind,\n"
	.string "läuft das Geschäft schleppend.\l"
	.string "Danke für deine Unterstützung!\p"
	.string "Zeigst du unsere patentierte\n"
	.string "Gangschaltung überall herum?\p"
	.string "Drücke einfach R, wenn du auf dem\n"
	.string "Rad stehst.\p"
	.string "Achtung! Danach wirst du schneller!$"
#else
	.string "Business has been hard to come\n"
	.string "by since we moved from KANTO.\l"
	.string "We appreciate your help!\p"
	.string "Can you make sure to show off\n"
	.string "our patented gear-changing tech?\p"
	.string "It's as simple as pressing R when\n"
	.string "you are stopped on your BIKE.\p"
	.string "Beware! You will then go faster!$"
#endif

GoldenrodCity_BikeShop_Text_Refused:
#if GERMAN
	.string "Seufz… gibt es denn keine guten\n"
	.string "Menschen mehr auf diesem Planeten?$"
#else
    .string "…sigh… Oh, for the kindness of\n"
    .string "people…$"
#endif

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
#if GERMAN
	.string "Brandneu!\p"
	.string "Erste Klasse Kompakt-Fahrräder!$"
#else
    .string "Just released!\p"
    .string "First-rate compact BICYCLES!$"
#endif

GoldenrodCity_BikeShop_Text_Bicycle:
#if GERMAN
	.string "Ein nigelnagelneues Fahrrad!$"
#else
    .string "It's a shiny new BICYCLE!$"
#endif
