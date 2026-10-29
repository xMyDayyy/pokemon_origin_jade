CherrygroveCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherryGrove_Pokecenter_OnTransition
	.byte 0

CherryGrove_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	end

CherryGrove_Pokecenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_Chansey::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox CherryGrove_Pokecenter_Text_Chansey, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	closemessage
	end

CherryGrove_Pokecenter_Text_Fisher:
#if GERMAN
	.string "Ich lagere hier meine Angel-Beute.\p"
	.string "Irgendwann sind es zu viele für einen\n"
	.string "Beutel.$"
#else
	.string "I keep my catch in storage here.\p"
	.string "Sooner or later there are too many\n"
	.string "for one BAG.$"
#endif

CherryGrove_Pokecenter_Text_Gentleman:
#if GERMAN
	.string "Ruhig hier, nicht wahr?\p"
	.string "In Dukatia City muss man Schlange\n"
	.string "stehen, hat man mir erzählt.$"
#else
	.string "Quiet in here, is it not?\p"
	.string "In GOLDENROD you have to queue, or\n"
	.string "so I am told.$"
#endif

CherryGrove_Pokecenter_Text_Lass:
#if GERMAN
	.string "Man sagt, ein Tunichtgut tut nichts\n"
	.string "gut,\p"
	.string "aber wer nichts tut, tut sich nicht gut!$"
#else
	.string "They say a watched pot never\n"
	.string "boils. But watching the clock\l"
	.string "in the POKéCENTER makes time fly!$"
#endif

CherryGrove_Pokecenter_Text_Chansey:
#if GERMAN
	.string "Chaneira: Chaa! Cha!$"
#else
	.string "CHANSEY: Chaan! Sii!$"
#endif
