GoldenrodCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodDeptStore5_OnTransition
	.byte 0

GoldenrodDeptStore5_OnTransition:
	special GetWeekday
	call_if_ne VAR_RESULT, WEEKDAY_SUN, GoldenrodDeptStore5_EventScript_HideReceptionist
	end

@ The TM lady is only here on Sunday, see docs/origin_jade/DECISIONS.md, D-033.
GoldenrodDeptStore5_EventScript_HideReceptionist:
	setflag FLAG_TEMP_1
	return


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_Already
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
#if GERMAN
	.string "Hallo! Oh, dein Pokémon…$"
#else
    .string "Hello. Oh, your POKéMON…$"
#endif

GoldenrodDeptStore_Text_5FReceptionistWait:
#if GERMAN
	.string "Moment, diese TM habe ich dir doch\n"
	.string "schon gegeben!$"
#else
	.string "Wait, I already gave you that TM!$"
#endif

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
#if GERMAN
	.string "Hmm…\p"
	.string "Es ist nicht schlecht, aber auch\n"
	.string "nicht gut.\p"
	.string "Du als Trainer musst dich etwas mehr\n"
	.string "anstrengen.$"
#else
	.string "Hmm…\n"
	.string "It's not bad, but it's also not good.\p"
	.string "You, as the TRAINER, need to put in\n"
	.string "some more effort.$"
#endif

GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
#if GERMAN
	.string "Es hängt sehr an dir, nicht wahr? Ein\n"
	.string "eingespieltes Team, wie ihr es seid, weiß\l"
	.string "doch bestimmt, wie man mit dieser\l"
	.string "Attacke hier umzugehen hat.$"
#else
    .string "It's very attached to you.\p"
    .string "This move should be perfect for a\n"
    .string "pair like you.$"
#endif

GoldenrodDeptStore_Text_5FLass:
#if GERMAN
	.string "Sonntags kommt eine Dame, um nach\n"
	.string "den Pokémon zu sehen.\p"
	.string "Sie verteilt sogar TM!$"
#else
	.string "On Sundays, a lady comes to\n"
	.string "check out POKéMON.\p"
	.string "She even gives away TMs!$"
#endif

GoldenrodDeptStore_Text_5FPokefanM:
#if GERMAN
	.string "Ein Pokémon, das du im Tausch erhalten\n"
	.string "hast, kannst du nicht umbenennen.\p"
	.string "Der Name spiegelt nämlich die Gefühle\n"
	.string "des Original-Trainers wider.$"
#else
    .string "You can't rename a POKéMON you get\n"
    .string "in a trade.\p"
    .string "The name is a reflection of the\n"
    .string "original trainer's feelings for it.$"
#endif

GoldenrodDeptStore_Text_Girl:
#if GERMAN
	.string "Technische Maschinen!\p"
	.string "Wie funktioniert das überhaupt?$"
#else
	.string "The lady gave me RETURN!\n"
    .string "My POKéMON must really like me!$"
#endif

GoldenrodDeptStore5_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore5_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore5_Pokemart:
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_NATURAL_GIFT
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_SOLAR_BEAM
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_FOCUS_BLAST
	pokemartlistend


GoldenrodDeptStore_Text_5FDirectory:
#if GERMAN
	.string "Rüste deine Pokémon auf.\p"
	.string "4S TM-Ecke$"
#else
    .string "Customize Your POKéMON\p"
    .string "5F TM CORNER$"
#endif
