DragonsDen_Cavern_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
#if GERMAN
	.string "{PLAYER}… du bist also hier.\p"
	.string "Wenn du denkst, dass du mit mir\n"
	.string "mithalten kannst, komm zum Kampf-Dojo\l"
	.string "in Saffronia City.$"
#else
    .string "{PLAYER}… So you're here.\p"
	.string "If you think you can keep up,\n"
	.string "with me, come to the FIGHTING\l"
	.string "DOJO in SAFFRON.$"
#endif

DragonsDen_Cavern_Trigger_ClairLeft::
	lock
	setflag FLAG_TEMP_HIDE_FOLLOWER
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	call DragonsDen_Cavern_EventScript_Clair
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	releaseall
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_Clair_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_PULSE
	msgbox DragonsDen_Cavern_Text_Clair_ExplainTM, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER:
	walk_fast_down
	face_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_Clair_GiveTM:
#if GERMAN
	.string "Sandra: Warte!\p"
	.string "Es tut mir leid.\n"
	.string "Hier, nimm das als Entschuldigung.$"
#else
    .string "CLAIR: WAIT!\p"
	.string "I'm sorry about this.\n"
    .string "Here, take this as my apology.$"
#endif

DragonsDen_Cavern_Text_Clair_ExplainTM:
#if GERMAN
	.string "Das ist Drachenpuls.\p"
	.string "So eine Art… ach, vergiss es!\p"
	.string "Es ist eine gewaltige Energie.\p"
	.string "Wenn du sie nicht willst, musst du sie\n"
	.string "nicht nehmen.$"
#else
    .string "DRAGON PULSE is a kind of er...\n"
	.string "never mind!\p"
	.string "It's a huge energy of some kind.\p"
	.string "If you don't want it, you don't have\n"
	.string "to take it.$"
#endif

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
#if GERMAN
	.string "Was ist los? Gehst du nicht weiter zur\n"
	.string "Pokémon-Liga?\p"
	.string "Wenn du Champion werden willst, kannst\n"
	.string "du jeden Arenaleiter noch einmal\l"
	.string "herausfordern.\p"
	.string "Geh zur Pokémon-Liga.\p"
	.string "Weißt du, wie du dorthin kommst?\p"
	.string "Von hier aus nach Neuborkia.\p"
	.string "Dann nach Osten surfen zur\n"
	.string "Pokémon-Liga.\p"
	.string "Der Weg dorthin ist sehr hart.\p"
	.string "Verlier bloß nicht in der Pokémon-\n"
	.string "Liga!\p"
	.string "Wenn doch, fühle ich mich noch\n"
	.string "schlechter, weil ich gegen dich verloren\l"
	.string "habe!\p"
	.string "Gib alles, was du hast.$"
#else
    .string "What's the matter? Aren't\n"
    .string "you going on to the POKéMON\l"
    .string "LEAGUE?\p"
    .string "After you become CHAMPION, you\n"
    .string "can rematch any GYM LEADER you\l"
    .string "want.\p"
    .string "Go to the POKéMON LEAGUE.\p"
    .string "Do you know how to get there?\p"
    .string "From here, go to NEW BARK TOWN.\p"
    .string "Then SURF east to POKéMON LEAGUE.\p"
    .string "The route there is very tough.\p"
    .string "Don't you dare lose at the POKéMON\n"
    .string "LEAGUE!\p"
    .string "If you do, I'll feel even worse\n"
    .string "about having lost to you!\p"
    .string "Give it everything you've got.$"
#endif

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN_HNS, DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA_HNS, DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
#if GERMAN
	.string "Drachen-Schrein\p"
	.string "Ein Schrein zu Ehren der Drachen-\n"
	.string "Pokémon\p"
	.string "die einst in der Drachen-Höhle\n"
	.string "lebten.$"
#else
    .string "DRAGON SHRINE\p"
    .string "A shrine honoring the dragon\n"
    .string "POKéMON\p"
    .string "said to have lived in DRAGON'S\n"
    .string "DEN.$"
#endif

DragonsDen_Cavern_Text_SilverTraining1:
#if GERMAN
	.string "… Was? {PLAYER}?\p"
	.string "…Nein, ich kämpfe jetzt nicht…\p"
	.string "Meine Pokémon sind noch nicht\n"
	.string "bereit, dich zu besiegen.\p"
	.string "Ich kann sie jetzt nicht zu sehr\n"
	.string "fordern.\p"
	.string "Disziplin ist nötig, um der größte\n"
	.string "Pokémon-Trainer zu werden…$"
#else
    .string "…\n"
    .string "What? {PLAYER}?\p"
    .string "…No, I won't battle you now…\p"
    .string "My POKéMON aren't ready to beat\n"
    .string "you.\p"
    .string "I can't push them too hard now.\p"
    .string "I have to be disciplined to become\n"
    .string "the greatest POKéMON trainer…$"
#endif

DragonsDen_Cavern_Text_SilverTraining2:
#if GERMAN
	.string "…\p"
	.string "Puh…\p"
	.string "Lern, mir aus dem Weg zu gehen…$"
#else
    .string "…\p"
    .string "Whew…\p"
    .string "Learn to stay out of my way…$"
#endif

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
#if GERMAN
	.string "Du! Was hast du hier zu suchen? Hier\n"
	.string "darf nicht einfach jeder rein!$"
#else
    .string "You! How dare you enter\n"
    .string "uninvited!$"
#endif

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
#if GERMAN
	.string "Uff! Ich bin bedient!$"
#else
    .string "S-strong!$"
#endif

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
#if GERMAN
	.string "Der Schrein hier gehört dem Meister\n"
	.string "unseres Drachen-Clans.\p"
	.string "Du darfst nicht einfach hineingehen!$"
#else
    .string "The SHRINE ahead is home to the\n"
    .string "MASTER of our dragon-user clan.\p"
    .string "You're not allowed to just go in!$"
#endif

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
#if GERMAN
	.string "He! Hier haben einfache Leute keinen\n"
	.string "Zutritt!$"
#else
    .string "You shouldn't be in here!$"
#endif

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
#if GERMAN
	.string "Mist, verloren!$"
#else
    .string "Oh yikes, I lost!$"
#endif

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
#if GERMAN
	.string "Bald bekomme ich die Erlaubnis\n"
	.string "vom Meister, Drachen zu nutzen.\p"
	.string "Dann werde ich ein bewunderter\n"
	.string "Drachen-Trainer und erhalte die\l"
	.string "Zustimmung unseres Meisters.$"
#else
    .string "Soon I'm going to get permission\n"
    .string "from our MASTER to use dragons.\p"
    .string "When I do, I'm going to become an\n"
    .string "admirable dragon trainer and gain\l"
    .string "our MASTER's approval.$"
#endif

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
#if GERMAN
	.string "Da ist ein Fremder, den wir nicht kennen.$"
#else
    .string "It's a stranger we don't know.$"
#endif

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
#if GERMAN
	.string "Jana: Aua! Das tat weh!$"
#else
    .string "Ouchies.$"
#endif

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
#if GERMAN
	.string "Jana: Es kam mir vor, als würde ich gegen\n"
	.string "Siegfried kämpfen.$"
#else
    .string "It was like having to battle\n"
    .string "LANCE.$"
#endif

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
#if GERMAN
	.string "Wer… bist du?$"
#else
    .string "Who are you?$"
#endif

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
#if GERMAN
	.string "Nana: Du Fiesling!$"
#else
    .string "Meanie.$"
#endif

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
#if GERMAN
	.string "Nana: Das verraten wir dem Meister! Der\n"
	.string "versohlt dir den Hosenboden!$"
#else
    .string "We'll tell on you.\p"
    .string "MASTER will be angry with you.$"
#endif
