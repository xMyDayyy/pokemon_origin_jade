OlivineCity_PortOutside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	.byte 0

OlivineCity_PortOutside_EventScript_Sabrina::
    lock
    faceplayer
    msgbox OlivineCity_PortOutside_Text_Sabrina, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_OLIVINE_SABRINA
    removeobject LOCALID_OLIVINE_SABRINA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_SABRINA
    release
    end

OlivineCity_PortOutside_Text_Sabrina:
#if GERMAN
	.string "Sabrina: Aus dem blauen heraus, habe ich\n"
	.string "das Bedürfnis, das Meer zu sehen.\p"
	.string "Triff mich zum kämpfen im Dojo.$"
#else
    .string "SABRINA: Out of the blue,\n"
	.string "I get the urge to see the ocean.\p"
	.string "I'll see you at the FIGHTING\n"
	.string "DOJO.$"
#endif

@ The M.S. Aqua sails every day after her maiden voyage, see docs/origin_jade/DECISIONS.md, D-029.
OlivineCity_PortOutside_EventScript_Fisherman1::
	lock
	faceplayer
	goto_if_ge VAR_SSAQUA_STATE, 7, OlivineCity_PortOutside_EventScript_Fisherman1Sailing
	msgbox OlivineCity_PortOutside_Text_PortFisherman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_PortOutside_EventScript_Fisherman1Sailing::
	msgbox OlivineCity_PortOutside_Text_PortFisherman1Sailing, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_PortOutside_EventScript_Fisherman2::
	lock
	faceplayer
	msgbox OlivineCity_PortOutside_Text_Fisherman2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_PortOutside_Text_PortFisherman1:
#if GERMAN
	.string "Die M.S. Aqua läuft bald zu ihrer\n"
	.string "Jungfernfahrt aus.\p"
	.string "Danach soll sie jeden Tag fahren!$"
#else
	.string "The S.S.AQUA will soon set out on\n"
	.string "her maiden voyage.\p"
	.string "After that, she'll sail every day!$"
#endif

OlivineCity_PortOutside_Text_PortFisherman1Sailing:
#if GERMAN
	.string "Seit die M.S. Aqua jeden Tag fährt,\n"
	.string "beißen hier kaum noch Fische an!$"
#else
	.string "Since the S.S.AQUA started sailing\n"
	.string "every day, the fish hardly bite\l"
	.string "here anymore!$"
#endif

OlivineCity_PortOutside_Text_Fisherman2:
#if GERMAN
	.string "Frischer Fisch aufn Tisch.$"
#else
	.string "Aw yeah, I'm fishin'.$"
#endif
