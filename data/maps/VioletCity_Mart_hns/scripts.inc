VioletCity_Mart_hns_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_Text_Granny:
#if GERMAN
	.string "Selbst ein schwaches Pokémon wird mit\n"
	.string "dem richtigen Training mal stark!\p"
	.string "Wichtig ist, dass du jedem Pokémon viel\n"
	.string "Zuneigung gibst!$"
#else
	.string "When you first catch a POKéMON,\n"
	.string "it may be weak.\p"
	.string "But it will eventually grow to\n"
	.string "be strong.\p"
	.string "It's important to treat POKéMON\n"
	.string "with love.$"
#endif

VioletCity_Mart_Text_CooltrainerM:
#if GERMAN
	.string "Du kannst Pokémon auch Items wie\n"
	.string "Trank oder Gegengift geben.\l"
	.string "Aber offenbar wissen sie mit\l"
	.string "künstlich hergestellten Items\l"
	.string "nichts anzufangen.$"
#else
	.string "POKéMON can hold items like\n"
	.string "POTION and ANTIDOTE.\p"
	.string "But they don't appear to know\n"
	.string "how to use man-made items.$"
#endif
