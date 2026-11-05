Gate_GoldenrodCity_Route35_hns_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
#if GERMAN
	.string "Entschuldige, Kleiner!\n"
	.string "Kannst du mir einen Gefallen tun?\p"
	.string "Kannst du dieses Pokémon meinem Freund\n"
	.string "auf Route 31 bringen?\p"
	.string "Du wirst ihn sofort erkennen!$"
#else
	.string "Excuse me, kid! Can you do a guy\n"
	.string "a favor?\p"
	.string "Can you take this POKéMON with MAIL\n"
	.string "to my friend?\p"
	.string "He's on ROUTE 31.$"
#endif

Route35GoldenrodGate_Text_RandyThanks:
#if GERMAN
	.string "Das würdest du tun? Super! Vielen Dank!\p"
	.string "Mein Freund ist\n"
	.string "ein Flegel! Er schläft die ganze Zeit.\p"
	.string "Du wirst ihn sofort erkennen!$"
#else
	.string "You will? Perfect! Thanks, kid!\p"
	.string "My pal's a chubby guy who snoozes\n"
	.string "all the time.\p"
	.string "You'll recognize him right away!$"
#endif

Route35GoldenrodGate_Text_ReceivedMonWithMail:
#if GERMAN
	.string "{PLAYER} hat ein Pokémon, das einen\p"
	.string "Brief trägt, erhalten.$"
#else
	.string "{PLAYER} received a POKéMON with MAIL.$"
#endif

Route35GoldenrodGate_Text_RandyWeirdTree:
#if GERMAN
	.string "Vergiss nicht, es an die erste Stelle im\n"
	.string "Team zu tun, sobald du meinen Freund\l"
	.string "triffst!\p"
	.string "Route 31!\p"
	.string "Stimmt! Ein merkwürdiger Baum hat die\n"
	.string "Straße blockiert.\p"
	.string "Ich frage mich, ob die Straße jetzt frei\n"
	.string "ist.$"
#else
	.string "Make sure to put it at the front of\n"
	.string "your team when you find my friend!\p"
	.string "ROUTE 31!\p"
	.string "Oh, yeah. There was a weird tree\n"
	.string "blocking the road.\p"
	.string "I wonder if it's been cleared?$"
#endif

Route35GoldenrodGate_Text_CantCarryMoreMon:
#if GERMAN
	.string "Du kannst kein weiteres Pokémon mehr\n"
	.string "tragen…$"
#else
	.string "You can't carry another POKéMON…$"
#endif

Route35GoldenrodGate_Text_RandyNeverMind:
#if GERMAN
	.string "Oh… Dann geht das in Ordnung…$"
#else
	.string "Oh… Never mind, then…$"
#endif

Route35GoldenrodGate_Text_ThanksForDelivery:
#if GERMAN
	.string "Danke, Kleiner! Du hast die Nachricht\n"
	.string "für mich übergeben!\p"
	.string "Hier, eine Kleinigkeit für dich!$"
#else
	.string "Thanks, kid! You made the delivery\n"
	.string "for me!\p"
	.string "Here's something for your trouble!$"
#endif

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
#if GERMAN
	.string "Mein Freund hat geschlafen, nicht wahr?\n"
	.string "Na, was habe ich dir gesagt?$"
#else
	.string "My pal was snoozing, right? Heh,\n"
	.string "what'd I say?$"
#endif

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
#if GERMAN
	.string "Angeblich versperrt ein merkwürdiger\n"
	.string "Baum den Weg, der anfängt, sich zu\l"
	.string "winden, wenn man ihn anspricht.\p"
	.string "Es heißt außerdem, dass er rasend\n"
	.string "wurde, als ihn jemand mit Wasser aus\l"
	.string "seiner Schiggykanne begossen hat.$"
#else
	.string "A strange tree is blocking the road.\p"
	.string "It wriggles around if you talk to it.\p"
	.string "I heard it became wild when someone\n"
	.string "watered it with a SQUIRTBOTTLE.$"
#endif

Route35GoldenrodGate_Text_PokefanF_Lullaby:
#if GERMAN
	.string "Ich mag das Pokémon-Schlaflied,\n"
	.string "das im Radio gespielt wird.$"
#else
	.string "I like the POKéMON Lullaby they play\n"
	.string "on the radio.$"
#endif

Route35GoldenrodGate_Text_Fisher:
#if GERMAN
	.string "Ich frage mich, wie viele Arten\p"
	.string "von Pokémon es wohl geben mag.\p"
	.string "Vor drei Jahren hat Prof. Eich\p"
	.string "verlautbart, dass es 150 verschiedene\n"
	.string "Arten geben soll.$"
#else
	.string "I wonder how many kinds of POKéMON\n"
	.string "there are in the world.\p"
	.string "Three years ago, PROF.OAK said that\n"
	.string "there were 150 different kinds.\p"
	.string "But recently I heard there's\n"
	.string "over 400!$"
#endif
