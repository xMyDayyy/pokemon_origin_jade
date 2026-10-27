Route37_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition:
	callnative SetTimeBasedEncounters
	special GetWeekday
	call_if_ne VAR_RESULT, WEEKDAY_SUN, Route37_EventScript_HideSunny
	end

@ Sunny of the weekday siblings is only here on Sunday, see
@ docs/origin_jade/DECISIONS.md, D-033.
Route37_EventScript_HideSunny:
	setflag FLAG_TEMP_1
	return



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG_HNS, Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
#if GERMAN
	.string "Wir arbeiten immer zusammen!$"
#else
	.string "ANN: ANNE and I are in this\n"
	.string "together!$"
#endif

Route37_Text_TwinsAnnAndAnne1_Beaten:
#if GERMAN
	.string "Nn… ein wenig zu stark.$"
#else
	.string "ANN & ANNE: Nnn… A little too\n"
	.string "strong.$"
#endif

Route37_Text_TwinsAnnAndAnne1_After:
#if GERMAN
	.string "Ich weiß genau, was meine Schwester und\n"
	.string "Pokémon denken.$"
#else
	.string "ANN: I can tell what my sister and\n"
	.string "my POKéMON are thinking.$"
#endif

Route37_Text_TwinsAnnAndAnne2_Seen:
#if GERMAN
	.string "Wir arbeiten immer zusammen!$"
#else
	.string "ANNE: ANN and I are in this\n"
	.string "together!$"
#endif

Route37_Text_TwinsAnnAndAnne2_Beaten:
#if GERMAN
	.string "Nn… ein wenig zu stark.$"
#else
	.string "ANN & ANNE: Nnn… A little too\n"
	.string "strong.$"
#endif

Route37_Text_TwinsAnnAndAnne2_After:
#if GERMAN
	.string "Wir fühlen genau wie unsere Pokémon.$"
#else
	.string "ANNE: We share the same feelings as\n"
	.string "our POKéMON.$"
#endif

Route37_Text_PsychicGreg_Seen:
#if GERMAN
	.string "Pokémon können nicht agieren, wenn sie\n"
	.string "schlafen. Gleich merkst du, wie\l"
	.string "furchterregend das ist!$"
#else
	.string "POKéMON can't do a thing if they are\n"
	.string "asleep.\p"
	.string "I'll show you how scary that is!$"
#endif

Route37_Text_PsychicGreg_Beaten:
#if GERMAN
	.string "Verloren.\n"
	.string "Wie überaus betrüblich…$"
#else
	.string "I lost. That's pretty sad…$"
#endif

Route37_Text_PsychicGreg_After:
#if GERMAN
	.string "Pokémon einzuschläfern oder zu\n"
	.string "paralysieren sind gute Kampftechniken.$"
#else
	.string "Putting POKéMON to sleep or paralyz-\n"
	.string "ing them are good battle techniques.$"
#endif

Route37_Text_Sunny_Meet:
#if GERMAN
	.string "Sonnfried: Hi! Ich bin Sonnfried\n"
	.string "vom Sonntag. Heute ist Sonntag!\p"
	.string "Man sagte mir, ich soll dir das\n"
	.string "geben, wenn ich dich sehe!$"
#else
	.string "SUNNY: Hi!\p"
	.string "I'm SUNNY of Sunday, meaning it's\n"
	.string "Sunday today!\p"
	.string "I was told to give you this if I\n"
	.string "saw you!$"
#endif

Route37_Text_Sunny_GaveGift:
#if GERMAN
	.string "Sonnfried: Dieses Ding…\p"
	.string "Äh…\p"
	.string "…Was war das noch mal…\p"
	.string "…\p"
	.string "Ah! Jetzt erinnere ich mich!\p"
	.string "Gib das einem Pokémon, das Elektro-\n"
	.string "Attacken verwendet, zum Tragen.\p"
	.string "Meine Schwester Monja behauptet,\n"
	.string "das mache sie noch effektiver!$"
#else
	.string "SUNNY: That thing…\p"
	.string "Um…\p"
	.string "… What was it now…\p"
	.string "…\p"
	.string "Oh! I remember now!\p"
	.string "A POKéMON that knows electric\n"
	.string "moves should hold it.\p"
	.string "My sis MONICA said it powers up\n"
	.string "electric moves!$"
#endif

Route37_Text_Sunny_Sunday:
#if GERMAN
	.string "Sonnfried: Meine Geschwister heißen\n"
	.string "Monja, Dietlinde, Mitko, Donatus,\l"
	.string "Frieda und Samson.\p"
	.string "Sie sind alle älter als ich!$"
#else
	.string "SUNNY: My sisters and brothers are\n"
	.string "MONICA, TUSCANY, WESLEY, ARTHUR,\l"
	.string "FRIEDA and SANTOS.\p"
	.string "They're all older than me!$"
#endif

Route37_Text_Sign:
#if GERMAN
	.string "Route 37$"
#else
	.string "ROUTE 37\n"
	.string "ECRUTEAK CITY AHEAD$"
#endif
