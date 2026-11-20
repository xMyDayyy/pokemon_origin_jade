Route31_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE_HNS, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten, Route31_EventScript_RegisterWade
	goto_if_set FLAG_WADE_HAS_ITEM_HNS, Route31_EventScript_WadeGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_RematchWade
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_RegisterWade::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route31_Text_WadeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WADE_HNS
	release
	end

Route31_EventScript_RematchWade::
	trainerbattle_rematch TRAINER_WADE_HNS, Route31_Text_WadeRematchIntro, Route31_Text_WadeRematchDefeat
	msgbox Route31_Text_WadePostRematch, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeGiveItem::
	msgbox Route31_Text_WadeHasItem, MSGBOX_DEFAULT
	giveitem VAR_WADE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route31_EventScript_WadeNoRoom
	clearflag FLAG_WADE_HAS_ITEM_HNS
	msgbox Route31_Text_WadeGaveItem, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeNoRoom::
	msgbox Route31_Text_WadeNoRoom, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	msgbox Route31_Text_DescribeRest, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
#if GERMAN
	.string "Hm, die Dunkelhöhle…\n"
	.string "Wenn ein Pokémon mithilfe einer Attacke\l"
	.string "da drinnen für Licht sorgen könnte,\l"
	.string "würde ich sie erforschen gehen.$"
#else
	.string "DARK CAVE…\p"
	.string "If POKéMON could light it up,\n"
	.string "I'd explore it.$"
#endif

Route31_Text_BugCatcherWade1_Seen:
#if GERMAN
	.string "Ich habe jede Menge Pokémon gefangen!\n"
	.string "Lass uns kämpfen!$"
#else
	.string "I caught a bunch of POKéMON.\n"
	.string "Let me battle with you!$"
#endif

Route31_Text_BugCatcherWade1_Beaten:
#if GERMAN
	.string "Also… irgendwas lief hier gerade\n"
	.string "mächtig schief!$"
#else
	.string "Awwwww…$"
#endif

Route31_Text_BugCatcherWade1_After:
#if GERMAN
	.string "Du kannst Pokémon fangen, auch wenn\n"
	.string "du bereits sechs bei dir trägst.\p"
	.string "Fängst du eines, wird es automatisch\n"
	.string "in deine Box im PC übertragen.$"
#else
	.string "You can catch POKéMON even if\n"
	.string "you have six with you.\p"
	.string "If you catch one, it'll go to\n"
	.string "your BOX automatically.$"
#endif

Route31_Text_SleepyMan:
#if GERMAN
	.string "Murmel, murmel, gähn…\p"
	.string "Ich bin heute auf der Suche nach\n"
	.string "Pokémon viel zu viel gelaufen.\l"
	.string "Meine Füße tun weh und ich bin müde…\p"
	.string "Wenn ich ein wildes Pokémon wäre, wäre\n"
	.string "ich jetzt leichte Beute…\l"
	.string "Gähn… zzz…$"
#else
	.string "… Hnuurg… Huh?\p"
	.string "I walked too far today looking\n"
	.string "for POKéMON.\p"
	.string "My feet hurt and I'm sleepy…\p"
	.string "If I were a wild POKéMON, I'd\n"
	.string "be easy to catch…\p"
	.string "…Zzzz…$"
#endif

Route31_Text_SleepyManGotMail:
#if GERMAN
	.string "…Zzzz… Häh?\p"
	.string "Was ist? Du hast einen Brief für mich?$"
#else
	.string "…Zzzz… Huh?\p"
	.string "What's that? You have MAIL\n"
	.string "for me?$"
#endif

Route31_Text_SleepyManFail:
	.string "…Zzzz…$"

Route31_Text_HandOverMailMon:
#if GERMAN
	.string "{PLAYER} übergibt das Pokémon,\n"
	.string "das den Brief trägt!$"
#else
	.string "{PLAYER} handed over the\n"
	.string "POKéMON holding the MAIL.$"
#endif

Route31_Text_ReadingMail:
#if GERMAN
	.string "Mal sehen…\p"
	.string "…die Dunkelhöhle führt zu einem\n"
	.string "anderen Weg…\p"
	.string "Gut zu wissen.\p"
	.string "Danke, dass du mir den Brief brachtest.\p"
	.string "Mein Freund ist ein netter Mensch,\n"
	.string "genau wie du!\p"
	.string "Ich möchte mich bei dir dafür\n"
	.string "revanchieren!\p"
	.string "Ich hab’s! Ich möchte dir das hier\n"
	.string "geben!$"
#else
	.string "Let's see…\p"
	.string "…DARK CAVE leads to another\n"
	.string "road…\p"
	.string "That's good to know.\p"
	.string "Thanks for bringing this to\n"
	.string "me.\p"
	.string "My friend's a good guy, and\n"
	.string "you're swell too!\p"
	.string "I'd like to do something good\n"
	.string "in return too!\p"
	.string "I know! I want you to have\n"
	.string "this!$"
#endif

Route31_Text_DescribeRest:
#if GERMAN
	.string "Die TM44 enthält… gähn…\n"
	.string "Zzzz…\l"
	.string "… … …\p"
	.string "…Huch! Erholung!!! Sie enthält\n"
	.string "natürlich die Attacke Erholung!\p"
	.string "Sie erlaubt deinem Pokémon, sich eine\n"
	.string "Mütze voll Schlaf zu nehmen und heilt\l"
	.string "auf diese Weise seine KP!$"
#else
	.string "...Zzz...\p"
	.string "...Umm... Rest!\p"
	.string "The phrase 'recover fast' became\n"
	.string "shortened to 'Rest,' you see?\p"
	.string "This is a move to sleep and recover\n"
	.string "some HP.$"
#endif

Route31_Text_WrongMail:
#if GERMAN
	.string "Dieser Brief scheint nicht an\n"
	.string "mich adressiert zu sein…\p"
	.string "Gähn…$"
#else
	.string "This MAIL isn't for me.$"
#endif

Route31_Text_MissingMail:
#if GERMAN
	.string "Was ist so besonders an diesem\n"
	.string "Pokémon?\p"
	.string "Es trägt keinen Brief.$"
#else
	.string "Why is this POKéMON so special?\p"
	.string "It doesn't have any MAIL.$"
#endif

Route31_Text_DeclinedToHandOverMail:
#if GERMAN
	.string "Was? Du möchtest nichts?$"
#else
	.string "What? You don't want\n"
	.string "anything?$"
#endif

Route31_Text_CantTakeLastMon:
#if GERMAN
	.string "Wenn ich dir dieses Pokémon wegnehme,\n"
	.string "womit willst du dann kämpfen?$"
#else
	.string "If I take that POKéMON from\n"
	.string "you,\p"
	.string "what are you going to use in\n"
	.string "battle?$"
#endif

Route31_Text_Youngster:
#if GERMAN
	.string "Ich habe in der Dunkelhöhle ein\n"
	.string "tolles Pokémon gefangen!\p"
	.string "Ich werde es trainieren, um später\n"
	.string "damit gegen Falk, den Arenaleiter von\l"
	.string "Viola City anzutreten!$"
#else
	.string "I found a good POKéMON in DARK\n"
	.string "CAVE.\p"
	.string "I'm going to raise it to take\n"
	.string "on FALKNER.\p"
	.string "He's the leader of VIOLET\n"
	.string "CITY's GYM.$"
#endif

Route31_Text_Sign:
#if GERMAN
	.string "Route 31\p"
	.string "Viola City - Rosalia City$"
#else
	.string "ROUTE 31\p"
	.string "VIOLET CITY - CHERRYGROVE CITY$"
#endif

Route31_Text_WadeRegister:
#if GERMAN
    .string "Du bist spitze! Ich mag dich!\p"
    .string "Ich suche hier jeden Tag nach\n"
    .string "Pokémon.\p"
    .string "Im hohen Gras finde ich alle möglichen\n"
    .string "Beeren.\p"
    .string "Wenn du möchtest, teile ich sie mit dir.$"
#else
	.string "You're awesome! I like you!\p"
	.string "I look for POKéMON here every\n"
	.string "day.\p"
	.string "When I'm in the grass, I find\n"
	.string "all kinds of BERRIES.\p"
	.string "If you'd like, I'll share\n"
	.string "some.$"
#endif

Route31_Text_WadeRematchIntro:
#if GERMAN
	.string "Ich habe schon auf dich gewartet. Los\n"
	.string "geht’s!$"
#else
	.string "I was waiting for you.\n"
	.string "Let's battle!$"
#endif

Route31_Text_WadeRematchDefeat:
#if GERMAN
	.string "Also… irgendwas lief hier gerade\n"
	.string "mächtig schief!$"
#else
	.string "Awwwww…$"
#endif

Route31_Text_WadePostRematch:
#if GERMAN
	.string "Ich melde mich, sobald ich etwas finde.\n"
	.string "Du darfst schon jetzt gespannt sein!$"
#else
	.string "You'll hear from me as soon\n"
	.string "as I find anything that you\l"
	.string "might like.$"
#endif

Route31_Text_WadeHasItem:
#if GERMAN
    .string "Hey! Ich habe nach dir gesucht!\p"
    .string "Ich habe etwas gefunden, als ich im\n"
    .string "Gras unterwegs war.\p"
    .string "Hier, du kannst es haben!$"
#else
	.string "Hey! I've been looking for\n"
	.string "you!\p"
	.string "I found something while I\n"
	.string "was in the grass.\p"
	.string "Here, you can have it!$"
#endif

Route31_Text_WadeGaveItem:
#if GERMAN
    .string "Ich sage dir Bescheid, wenn ich noch\n"
    .string "etwas finde!$"
#else
	.string "I'll let you know if I find\n"
	.string "anything else!$"
#endif

Route31_Text_WadeNoRoom:
#if GERMAN
    .string "Hm, dein Beutel scheint voll zu sein.\p"
    .string "Komm wieder, wenn du Platz hast!$"
#else
	.string "Hmm, looks like your BAG\n"
	.string "is full.\p"
	.string "Come back when you have\n"
	.string "room!$"
#endif

Route31_Text_DarkCaveSign:
#if GERMAN
	.string "Dunkelhöhle$"
#else
	.string "DARK CAVE$"
#endif
