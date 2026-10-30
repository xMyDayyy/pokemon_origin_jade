LakeOfRage_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	call LakeOfRage_EventScript_SetGyaradosVisibility
	special GetWeekday
	call_if_ne VAR_RESULT, WEEKDAY_WED, LakeOfRage_EventScript_HideWesley
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
	goto LakeOfRage_EventScript_SetLowTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE_HNS
	end

LakeOfRage_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_HNS
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
	random 2
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
	end

LakeOfRage_EventScript_HideLois::
	setflag FLAG_TEMP_1
	return

@ Wesley of the weekday siblings is only here on Wednesday, see
@ docs/origin_jade/DECISIONS.md, D-033.
LakeOfRage_EventScript_HideWesley:
	setflag FLAG_TEMP_2
	return

@ Red Gyarados: story battle until VAR_MAHOGANY_TOWN_STATE 2, then the legendary rules
@ (see docs/origin_jade/DECISIONS.md, D-026).
LakeOfRage_EventScript_SetGyaradosVisibility::
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 2, Common_EventScript_NopReturn
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	setvar VAR_0x8004, LEGENDARY_RED_GYARADOS
	specialvar VAR_RESULT, IsLegendaryAvailable
	goto_if_ne VAR_RESULT, TRUE, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	return

LakeOfRage_EventScript_ThunderStorm::
	setweather WEATHER_RAIN_THUNDERSTORM
	end

LakeOfRage_EventScript_Pryce::
    lock
    faceplayer
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_LAKE_PRYCE
    removeobject LOCALID_LAKE_PRYCE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_PRYCE
    release
    end

LakeOfRage_Text_Pryce:
#if GERMAN
	.string "{PLAYER}.\p"
	.string "Sogar hier hält mich die Kälte\n"
	.string "wachsam.\p"
	.string "Wenn du wieder kämpfen willst,\n"
	.string "komm zum Kampf-Dojo.$"
#else
    .string "{PLAYER}.\p"
	.string "Even here, the cold keeps me sharp.\p"
	.string "If you wish to battle again, come\n"
	.string "to the FIGHTING DOJO.$"
#endif

LakeOfRage_EventScript_Gramps::
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
	end

LakeOfRage_EventScript_Gramps2::
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
	end
LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
	end

LakeOfRage_EventScript_Nerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_ANDRE_HNS, LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND_HNS, LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON_HNS, LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_LOIS_HNS, LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Gyarados::
	lock
	faceplayer
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattleshiny SPECIES_GYARADOS, 55
	dowildbattle
	setvar VAR_0x8004, LEGENDARY_RED_GYARADOS
	special RecordLegendaryBattleOutcome
	specialvar VAR_RESULT, GetBattleOutcome
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
	fadescreenswapbuffers FADE_FROM_BLACK
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, LakeOfRage_EventScript_GyaradosGone
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_GyaradosGone
	bufferspeciesname STR_VAR_1, SPECIES_GYARADOS
	msgbox Text_MonSwamAway, MSGBOX_DEFAULT
LakeOfRage_EventScript_GyaradosGone:
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_GyaradosEnd
	@ First battle: the story goes on whatever the outcome.
	clearflag FLAG_TEMP_1
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	addobject LOCALID_LAKEOFRAGE_LANCE
	giveitem ITEM_RED_SCALE
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
	setvar VAR_MAHOGANY_TOWN_STATE, 2
LakeOfRage_EventScript_GyaradosEnd:
	release
	end

LakeOfRage_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end
LakeOfRage_EventScript_Item_Secret_Power::
    finditem ITEM_TM_SECRET_POWER
    end
LakeOfRage_EventScript_Item_Red_Flute::
	finditem ITEM_RED_FLUTE
	end

LakeOfRage_EventScript_Dragonite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
	release
	end

LakeOfRage_EventScript_Lance::
	lock
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 3
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
LakeOfRage_EventScript_LanceAccept::
	lock
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
LakeOfRage_EventScript_EndScene::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
	setvar VAR_MAHOGANY_TOWN_STATE, 4
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	release
	end

LakeOfRage_EventScript_Lance_Return::
	lock
	faceplayer
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined

LakeOfRage_EventScript_LancDeclined::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	closemessage
	release
	end


LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
	goto LakeOfRage_EventScript_EndScene

LakeOfRage_Movement_LanceLeaveNorth:
	walk_left
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeaveNorth:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_LanceLeave:
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeave:
	delay_16
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_Dragonite:
#if GERMAN
	.string "Dragoran: Draaagooo…$"
#else
	.string "DRAGONITE: Gyafooha!$"
#endif

LakeOfRage_Text_LanceForcedToEvolve:
#if GERMAN
	.string "Dieser See ist voller Garados. Aber\n"
	.string "sonst gibt es hier nichts…\p"
	.string "Die Karpador werden also gezwungen,\n"
	.string "sich zu entwickeln…$"
#else
    .string "This lake is full of GYARADOS\n"
    .string "but nothing else…\p"
    .string "So the MAGIKARP are being forced\n"
    .string "to evolve…$"
#endif

LakeOfRage_Text_LanceIntro1:
#if GERMAN
	.string "Bist du wegen der Gerüchte hier?\p"
	.string "Du bist {PLAYER}? Ich bin Siegfried,\p"
	.string "ein Trainer wie du.$"
#else
    .string "Did you come here because of\n"
    .string "the rumors?\p"
    .string "You're {PLAYER}? I'm LANCE, a\n"
    .string "trainer like you.$"
#endif

LakeOfRage_Text_LanceIntro2:
#if GERMAN
	.string "Ich hörte einige Gerüchte.\p"
	.string "Also kam ich hierher, um einige\n"
	.string "Nachforschungen anzustellen…$"
#else
    .string "This man here informed me of\n"
    .string "some rumors.\p"
    .string "So we came to investigate…$"
#endif

LakeOfRage_Text_LanceIntro3:
#if GERMAN
	.string "Ich habe gesehen, wie du kämpfst,\n"
	.string "{PLAYER}.\p"
	.string "Man kann sagen, dass du ein Trainer von\n"
	.string "bemerkenswertem Format bist.\p"
	.string "Würdest du mir bei meinen\n"
	.string "Nachforschungen helfen?$"
#else
    .string "I saw the way you battled\n"
    .string "earlier, {PLAYER}.\p"
    .string "I can tell that you're a trainer\n"
    .string "with considerable skill.\p"
    .string "If you don't mind, could you help\n"
    .string "us investigate?$"
#endif

LakeOfRage_Text_LanceRadioSignal:
#if GERMAN
	.string "Siegfried: Exzellent!\p"
	.string "Es sieht so aus, als würde jemand\p"
	.string "die Karpador im See zwingen,\n"
	.string "sich zu entwickeln.\p"
	.string "Die Ursache ist das mysteriöse\n"
	.string "Radiosignal aus Mahagonia City.\p"
	.string "Ich werde auf dich warten,\n"
	.string "{PLAYER}.$"
#else
    .string "LANCE: Excellent!\p"
    .string "It seems that the LAKE's MAGIKARP\n"
    .string "are being forced to evolve.\p"
    .string "A mysterious radio broadcast\n"
    .string "coming from MAHOGANY is the cause.\p"
    .string "We'll be waiting for you,\n"
    .string "{PLAYER}.$"
#endif

LakeOfRage_Text_LanceRefused:
#if GERMAN
	.string "Oh… Solltest du deine Meinung ändern,\n"
	.string "dann hilf mir bitte.$"
#else
    .string "Oh… Well, if you change your mind,\n"
    .string "please help us.$"
#endif

LakeOfRage_Text_LanceAskHelp:
#if GERMAN
	.string "Siegfried: Na? Wirst du mir helfen?$"
#else
    .string "LANCE: Hm? Are you going to help\n"
    .string "us?$"
#endif

LakeOfRage_Text_GyaradosCry:
#if GERMAN
	.string "Garados: Gaaar!!!$"
#else
    .string "GYARADOS: Gyashaa!$"
#endif

LakeOfRage_Text_Gramps:
#if GERMAN
	.string "Das Garados ist wütend! Das ist ein\n"
	.string "böses Omen!$"
#else
    .string "The GYARADOS are angry!\p"
    .string "It's a bad omen!$"
#endif

LakeOfRage_Text_GrampsCleared:
#if GERMAN
	.string "Haha! Die Karpador beißen ganz\n"
	.string "ausgezeichnet!$"
#else
    .string "Hahah! The MAGIKARP are biting!$"
#endif

LakeOfRage_Text_SuperNerd:
#if GERMAN
	.string "Angeblich entstand dieser See einst,\n"
	.string "nachdem ein erbostes Garados hier\l"
	.string "seinem Unmut Luft gemacht hatte.\p"
	.string "Ich frage mich, ob der ganze Rummel\n"
	.string "vielleicht etwas mit dieser Geschichte\l"
	.string "zu tun hat…$"
#else
    .string "I heard this lake was made by\n"
    .string "rampaging GYARADOS.\p"
    .string "I wonder if there is any\n"
    .string "connection to their mass outbreak\l"
    .string "now?$"
#endif

LakeOfRage_Text_CooltrainerF:
#if GERMAN
	.string "Täuschen mich meine Augen? Ich sah\n"
	.string "ein rotes Garados im See…\p"
	.string "Aber ich dachte, Garados sind blau!$"
#else
    .string "Did my eyes deceive me? I saw a\n"
    .string "red GYARADOS in the LAKE…\p"
    .string "But I thought GYARADOS were\n"
    .string "usually blue?$"
#endif


LakeOfRage_Text_FisherAndreSeen:
#if GERMAN
	.string "Gerade eben habe ich ein tolles Pokémon\n"
	.string "gefangen! Lass uns kämpfen!$"
#else
    .string "Let me battle with the POKéMON I\n"
    .string "just caught!$"
#endif

LakeOfRage_Text_FisherAndreBeaten:
#if GERMAN
	.string "Ich mag zwar ein guter Angler sein, aber\n"
	.string "als Trainer habe ich versagt…$"
#else
    .string "I might be an expert angler, but\n"
    .string "I stink as a POKéMON trainer…$"
#endif

LakeOfRage_Text_FisherAndreAfter:
#if GERMAN
	.string "Im Angeln schlägt mich niemand! Ich\n"
	.string "habe schließlich am laufenden Band\l"
	.string "neue Pokémon an der Leine!$"
#else
    .string "I won't lose as an angler! I catch\n"
    .string "POKéMON all day.$"
#endif


LakeOfRage_Text_FisherRaymondSeen:
#if GERMAN
	.string "Ich kann tun, was ich will. Ich fange\n"
	.string "immer nur die gleichen Pokémon…$"
#else
    .string "No matter what I do, all I catch\n"
    .string "are the same POKéMON…$"
#endif

LakeOfRage_Text_FisherRaymondBeaten:
#if GERMAN
	.string "Meine Schnur hat sich verheddert…$"
#else
    .string "My line's all tangled up…$"
#endif

LakeOfRage_Text_FisherRaymondAfter:
#if GERMAN
	.string "Warum kann ich keine guten Pokémon\n"
	.string "fangen?$"
#else
    .string "Why can't I catch any good\n"
    .string "POKéMON?$"
#endif

LakeOfRage_Text_CooltrainermAaronSeen:
#if GERMAN
	.string "Trifft ein Trainer auf einen anderen,\n"
	.string "so muss er ihn herausfordern.\p"
	.string "Das ist unsere Bestimmung.$"
#else
    .string "If a trainer spots another trainer,\n"
    .string "he has to make a challenge.\p"
    .string "That is our destiny.$"
#endif

LakeOfRage_Text_CooltrainermAaronBeaten:
#if GERMAN
	.string "Wow… Toller Kampf!$"
#else
    .string "Whew… Good battle.$"
#endif

LakeOfRage_Text_CooltrainermAaronAfter:
#if GERMAN
	.string "Sowohl Pokémon als auch ihre Trainer\n"
	.string "stärken durch ständiges Kämpfen\l"
	.string "sukzessiv ihre Fähigkeiten!$"
#else
    .string "POKéMON and their trainer become\n"
    .string "powerful through constant battling.$"
#endif

LakeOfRage_Text_CooltrainerfLoisSeen:
#if GERMAN
	.string "Was ist mit dem roten Garados\n"
	.string "passiert?\p"
	.string "Es ist weg?\p"
	.string "So ein Mist. War ich etwa umsonst hier?\p"
	.string "Ich weiß… kämpfen wir!$"
#else
    .string "What happened to the red\n"
    .string "GYARADOS?\p"
    .string "It's gone?\p"
    .string "Oh, darn. I came here for\n"
    .string "nothing?\p"
    .string "I know--let's battle!$"
#endif

LakeOfRage_Text_CooltrainerfLoisBeaten:
#if GERMAN
	.string "Ziemlich gut!$"
#else
    .string "Good going!$"
#endif

LakeOfRage_Text_CooltrainerfLoisAfter:
#if GERMAN
	.string "Stell dir vor, ich habe schon mal ein\n"
	.string "rosa Smettbo gesehen!$"
#else
    .string "Come to think of it, I've seen a\n"
    .string "pink BUTTERFREE.$"
#endif



LakeOfRage_EventScript_Wesley::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BLACK_BELT
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_EventScript_WesleyCompleted::
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_Text_MeetWesley:
#if GERMAN
	.string "Mitko: Na, wie geht’s dir?\p"
	.string "Heute ist Mittwoch, also bin ich\n"
	.string "hier: Mitko vom Mittwoch!\p"
	.string "Freut mich! Bitte nimm dieses\n"
	.string "Souvenir.$"
#else
	.string "WESLEY: Well, how do you do?\p"
	.string "Seeing as how it's Wednesday,\n"
	.string "I'm WESLEY of Wednesday!\p"
	.string "Pleased to meet you. Please take a\n"
	.string "souvenir.$"
#endif

LakeOfRage_Text_WesleyGaveGift:
#if GERMAN
	.string "Mitko: Schwarzgurt erhöht die\n"
	.string "Kraft von Kampf-Attacken.$"
#else
    .string "WESLEY: BLACK BELT beefs up the\n"
    .string "power of fighting moves.$"
#endif

LakeOfRage_Text_WesleyWednesday:
#if GERMAN
	.string "Mitko: Da du mich gefunden hast,\n"
	.string "musst du meine Brüder und\l"
	.string "Schwestern getroffen haben.\p"
	.string "Oder hattest du einfach nur Glück?$"
#else
    .string "WESLEY: Since you found me, you\n"
    .string "must have met my brothers and\l"
    .string "sisters.\p"
    .string "Or did you just get lucky?$"
#endif

LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
	end

LakeOfRage_Text_Sign:
#if GERMAN
	.string "See des Zorns\p"
	.string "(Auch bekannt als der Garados-See)$"
#else
    .string "LAKE OF RAGE,\n"
    .string "also known as GYARADOS LAKE.$"
#endif

LakeOfRage_Text_FishingGuruSign:
#if GERMAN
	.string "Haus des Profi-Anglers$"
#else
    .string "FISHING GURU'S HOUSE$"
#endif
