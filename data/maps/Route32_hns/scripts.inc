Route32_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route32_OnTransition:
	callnative SetTimeBasedEncounters
	special GetWeekday
	call_if_ne VAR_RESULT, WEEKDAY_FRI, Route32_EventScript_HideFrieda
	end

@ Frieda of the weekday siblings is only here on Friday, see
@ docs/origin_jade/DECISIONS.md, D-033.
Route32_EventScript_HideFrieda:
	setflag FLAG_TEMP_4
	return

Route32_EventScript_FisherJustin::
	trainerbattle_single TRAINER_JUSTIN_HNS, Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherRalph::
	trainerbattle_single TRAINER_RALPH_HNS, Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten, Route32_EventScript_RegisterRalph
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchRalph
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterRalph::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_RalphRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RALPH_HNS
	release
	end

Route32_EventScript_RematchRalph::
	trainerbattle_rematch TRAINER_RALPH_HNS, Route32_Text_RalphRematchIntro, Route32_Text_RalphRematchDefeat
	msgbox Route32_Text_RalphPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherHenry::
	trainerbattle_single TRAINER_HENRY_HNS, Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_ALBERT_HNS, Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_GORDON_HNS, Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_ROLAND_HNS, Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_PicnickerLiz::
	trainerbattle_single TRAINER_LIZ_HNS, Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten, Route32_EventScript_RegisterLiz
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchLiz
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterLiz::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_LizRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LIZ_HNS
	release
	end

Route32_EventScript_RematchLiz::
	trainerbattle_rematch TRAINER_LIZ_HNS, Route32_Text_LizRematchIntro, Route32_Text_LizRematchDefeat
	msgbox Route32_Text_LizPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdkeeperPeter::
	trainerbattle_single TRAINER_PETER_HNS, Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Roar::
	lock
	faceplayer
	checkitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_Roar2
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_Roar2::
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_SlowpokeTail_TriggerLeft::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerMid::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerRight::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_Trigger::
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end
Route32_EventScript_SlowpokeTail_Trigger2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end

Route32_EventScript_Movement_Left::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return

Route32_EventScript_Movement_Right::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return

Route32_EventScript_SlowpokeTail::
	lock
	faceplayer
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_SlowpokeTail2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	release
	end


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_POISON_BARB
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_FriedaCompleted::
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
	release
	end

Route32_EventScript_BaldingManTriggerLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerMid::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerRight::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManCheck::
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setvar VAR_VIOLET_CITY_STATE, 5
	release
	end
Route32_EventScript_BaldingManTower::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManGym::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManEgg::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end

Route32_EventScript_Item_Bullet_Seed::
    finditem ITEM_TM_BULLET_SEED
    end

Route32_EventScript_GreatBall::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_GreatBallII::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end

Route32_Movement_Turnback:
	walk_up
	step_end

Route32_Movement_StartMid:
	walk_left
	step_end

Route32_Movment_StartRight:
	walk_left
	walk_left
	step_end

Route32_Movement_SlowpokeLeft::
	step_end

Route32_Movement_SlowpokeMid::
	walk_right
	step_end

Route32_Movement_SlowpokeRight::
	walk_right
	walk_right
	step_end

Route32_Text_CooltrainerM_WhatsTheHurry:
#if GERMAN
	.string "Warte! Warum die Eile?$"
#else
	.string "Wait up!\n"
	.string "What's the hurry?$"
#endif

Route32_Text_CooltrainerM_AideIsWaiting:
#if GERMAN
	.string "Du bist {PLAYER}, nicht wahr?\n"
	.string "Ich habe einen Mann getroffen, der\l"
	.string "nach dir suchte. Er trug eine Brille…\p"
	.string "Bestimmt wartet er noch im\n"
	.string "Pokémon-Supermarkt auf dich!$"
#else
	.string "{PLAYER}, right?\n"
	.string "Some guy wearing glasses\p"
	.string "was looking for you.\p"
	.string "See for yourself. He's waiting for\n"
	.string "you at the POKéMON CENTER.$"
#endif

Route32_Text_CooltrainerM_SproutTower:
#if GERMAN
	.string "Warst du im Knofensa-Turm?\p"
	.string "Wenn du jemals nach Viola City kommst,\n"
	.string "erwartet man von dir, dass du dort\l"
	.string "trainierst.\p"
	.string "Das ist ein Muss für alle Trainer.\p"
	.string "Geh zum Knofensa-Turm!$"
#else
	.string "Have you gone to SPROUT TOWER?\n"
	.string "If you ever visit VIOLET CITY,\p"
	.string "they'll expect you to train there.\n"
	.string "That's basic for trainers.\p"
	.string "Go to SPROUT TOWER!$"
#endif

Route32_Text_CooltrainerM_VioletGym:
#if GERMAN
	.string "Warst du schon in der Pokémon-Arena?\n"
	.string "Das ist ein guter Ort für Trainer, um\l"
	.string "sich und seine Pokémon zu stählen!\p"
	.string "Das ist Trainer-Grundwissen!\n"
	.string "Schau dort mal vorbei!$"
#else
	.string "Have you gone to the POKéMON GYM?\n"
	.string "You can test your POKéMON and\p"
	.string "yourself there.\n"
	.string "It's a rite of passage for all\p"
	.string "trainers!$"
#endif

Route32_Text_CooltrainerM_HaveThisSeed:
#if GERMAN
	.string "Du hast einige gute Pokémon dabei.\n"
	.string "Sie sind bestimmt deshalb so gut, weil du\l"
	.string "sie in Viola City so hart trainiert hast.\p"
	.string "Die Pokémon-Arena war sicher ganz\n"
	.string "besonders gutes Training für sie.\p"
	.string "Hier, das ist für dich. Als kleines\n"
	.string "Andenken an Viola City.\p"
	.string "Wenn du das einem Pokémon gibst, soll\n"
	.string "angeblich die Stärke all seiner\l"
	.string "Attacken vom Typ Pflanze steigen.$"
#else
	.string "You have some good POKéMON there.\n"
	.string "It must be from the training you\p"
	.string "gave them around VIOLET CITY.\n"
	.string "The training at the GYM must have\p"
	.string "been especially helpful. As a\n"
	.string "souvenir of VIOLET CITY, take this.\p"
	.string "It increases the power of GRASS-\n"
	.string "type moves.$"
#endif

Route32_Text_CooltrainerM_Experiences:
#if GERMAN
	.string "Deine Erfahrungen aus Viola City werden\n"
	.string "dir auf deiner Reise sehr nützlich sein.$"
#else
	.string "Your experiences in VIOLET CITY\n"
	.string "should be useful for your journey.$"
#endif

Route32_Text_SlowpokeTailOffer:
#if GERMAN
	.string "Wie wär’s mit einer schmackhaften und\n"
	.string "nahrhaften Flegmon-Rute?\p"
	.string "Für dich jetzt nur 1.000.000 $!\n"
	.string "Na, wie sieht’s aus?$"
#else
	.string "How would you like to have this\n"
	.string "tasty, nutritious SLOWPOKETAIL?\p"
	.string "For you right now, just\n"
	.string "¥1,000,000!\p"
	.string "You'll want this!$"
#endif

Route32_Text_ThoughtKidsLoaded:
#if GERMAN
	.string "Pah, dein Geld reicht nicht!\p"
	.string "Und ich dachte, die Kinder von\n"
	.string "heute wären stinkreich…$"
#else
	.string "Tch! I thought kids\n"
	.string "these days were loaded…$"
#endif

Route32_Text_RefusedSlowpokeTail:
#if GERMAN
	.string "Du möchtest sie nicht?\n"
	.string "Dann mach dich vom Acker!$"
#else
	.string "You don't want it?\n"
	.string "Then scram. Shoo!$"
#endif

Route32_Text_FisherJustin_Seen:
#if GERMAN
	.string "Uah!\p"
	.string "Na toll! Jetzt hast du mich erschreckt\n"
	.string "und mein Ziel hat sich verdrückt!$"
#else
	.string "Whoa!\p"
	.string "You made me lose that fish!$"
#endif

Route32_Text_FisherJustin_Beaten:
#if GERMAN
	.string "Platsch!$"
#else
	.string "Sploosh!$"
#endif

Route32_Text_FisherJustin_After:
#if GERMAN
	.string "Ruhe, Geduld und Spucke…\p"
	.string "Im Kern kommt es beim Angeln und\n"
	.string "beim Pokémon-Kampf auf das Gleiche an.$"
#else
	.string "Calm, collected… The essence of\n"
	.string "fishing and POKéMON is the same.$"
#endif

Route32_Text_FisherRalph1_Seen:
#if GERMAN
	.string "Ich beherrsche beides, Angeln und\n"
	.string "Pokémon.\p"
	.string "Darum werde ich nicht verlieren!$"
#else
	.string "I'm really good at both\n"
	.string "fishing and POKéMON.\p"
	.string "I'm not about to lose to any kid!$"
#endif

Route32_Text_FisherRalph1_Beaten:
#if GERMAN
	.string "Tse! Ich war wohl doch zu ungeduldig.$"
#else
	.string "Tch! I tried to rush\n"
	.string "things…$"
#endif

Route32_Text_FisherRalph1_After:
#if GERMAN
	.string "Angeln ist ein Sport fürs ganze Leben.\n"
	.string "Pokémon sind Kameraden fürs Leben!$"
#else
	.string "Fishing is a lifelong\n"
	.string "passion.\p"
	.string "POKéMON are lifelong friends!$"
#endif

Route32_Text_RalphRegister:
#if GERMAN
	.string "Angeln ist ein Sport fürs ganze Leben.\n"
	.string "Pokémon sind Kameraden fürs Leben!$"
#else
	.string "Fishing is a lifelong\n"
	.string "passion.\p"
	.string "POKéMON are lifelong friends!$"
#endif

Route32_Text_RalphRematchIntro:
#if GERMAN
    .string "Ich bin sowohl im Angeln als auch mit\n"
    .string "Pokémon richtig gut.\p"
    .string "Gegen irgendein Kind verliere\n"
    .string "ich ganz bestimmt nicht!$"
#else
	.string "I'm really good at both\n"
	.string "fishing and POKéMON.\p"
	.string "I'm not about to lose to any kid!$"
#endif

Route32_Text_RalphRematchDefeat:
#if GERMAN
	.string "Tse! Ich war wohl doch zu ungeduldig.$"
#else
	.string "Tch! I tried to rush\n"
	.string "things…$"
#endif

Route32_Text_RalphPostRematch:
#if GERMAN
	.string "Angeln ist ein Sport fürs ganze Leben.\n"
	.string "Pokémon sind Kameraden fürs Leben!$"
#else
	.string "Fishing is a lifelong\n"
	.string "passion.\p"
	.string "POKéMON are lifelong friends!$"
#endif

Route32_Text_FisherHenry_Seen:
#if GERMAN
	.string "Meine Pokémon?\n"
	.string "Frisch gefangen!$"
#else
	.string "My POKéMON? Freshly caught!$"
#endif

Route32_Text_FisherHenry_Beaten:
#if GERMAN
	.string "Platscher$"
#else
	.string "SPLASH?$"
#endif

Route32_Text_FisherHenry_After:
#if GERMAN
	.string "Frisch gefangene Pokémon können\n"
	.string "gut trainierten kein Paroli bieten.$"
#else
	.string "Freshly caught POKéMON are\n"
	.string "no match for properly raised ones.$"
#endif

Route32_Text_YoungsterAlbert_Seen:
#if GERMAN
	.string "Ah, ein neues Gesicht.\n"
	.string "Du hältst dich also für stark?$"
#else
	.string "I haven't seen you around before.\n"
	.string "So you think you are pretty tough?$"
#endif

Route32_Text_YoungsterAlbert_Beaten:
#if GERMAN
	.string "Du bist aber stark!$"
#else
	.string "You're strong!$"
#endif

Route32_Text_YoungsterAlbert_After:
#if GERMAN
	.string "Ich versuche, aus meinen Lieblings-\n"
	.string "Pokémon das Beste herauszuholen.\p"
	.string "Ich verwende nicht die gleichen wie die\n"
	.string "anderen, nur weil sie als stark gelten.$"
#else
	.string "I'm going to try to be the\n"
	.string "best with my favorites.\p"
	.string "I'm not using the same tough\n"
	.string "POKéMON as everyone else.$"
#endif

Route32_Text_YoungsterGordon_Seen:
#if GERMAN
	.string "Ich habe gute Pokémon im Gras\n"
	.string "gefunden! Wir schaffen das schon!$"
#else
	.string "I found some good POKéMON\n"
	.string "in the grass!\p"
	.string "I think they'll do it for me!$"
#endif

Route32_Text_YoungsterGordon_Beaten:
#if GERMAN
	.string "Und ich dachte, ich könnte gewinnen…\n"
	.string "So kann man sich irren.$"
#else
	.string "Darn. I thought I could win.$"
#endif

Route32_Text_YoungsterGordon_After:
#if GERMAN
	.string "Im Gras findest du viele Dinge.$"
#else
	.string "The grass is full of\n"
	.string "clingy things.$"
#endif

Route32_Text_CamperRoland_Seen:
#if GERMAN
	.string "Dieser Blick…\n"
	.string "wie faszinierend.$"
#else
	.string "That glance… It's intriguing.$"
#endif

Route32_Text_CamperRoland_Beaten:
#if GERMAN
	.string "Hm. Das war enttäuschend.$"
#else
	.string "Hmmm. This is disappointing.$"
#endif

Route32_Text_CamperRoland_After:
#if GERMAN
	.string "Wenn du nicht kämpfen möchtest,\n"
	.string "solltest du Blickkontakt vermeiden.$"
#else
	.string "If you don't want to battle,\n"
	.string "just avoid eye contact.$"
#endif

Route32_Text_PicnickerLiz1_Seen:
#if GERMAN
	.string "A-ha. Ja, du weißt…\p"
	.string "Wie bitte? Kampf? Ich telefoniere.\p"
	.string "Oh, O.K. Aber mach schnell.$"
#else
	.string "Uh-huh. Yeah, and you know…\p"
	.string "Pardon? Battle? I'm on the phone.\n"
	.string "Oh, all right. But make it fast.$"
#endif

Route32_Text_PicnickerLiz1_Beaten:
#if GERMAN
	.string "Ich muss meinem Ärger Luft machen!$"
#else
	.string "Oh! I've got to relieve\n"
	.string "my anger!$"
#endif

Route32_Text_PicnickerLiz1_After:
#if GERMAN
	.string "Ich hatte einen netten Plausch.$"
#else
	.string "I was having a nice chat too.$"
#endif

Route32_Text_LizRegister:
#if GERMAN
    .string "Ich war gerade so schön am Plaudern.$"
#else
	.string "I was having a nice chat too.$"
#endif

Route32_Text_LizRematchIntro:
#if GERMAN
    .string "Aha. Ja, und weißt du…\p"
    .string "Wie bitte? Kämpfen? Ich telefoniere\n"
    .string "gerade.\p"
    .string "Na gut. Aber mach schnell.$"
#else
	.string "Uh-huh. Yeah, and you know…\p"
	.string "Pardon? Battle? I'm on the phone.\n"
	.string "Oh, all right. But make it fast.$"
#endif

Route32_Text_LizRematchDefeat:
#if GERMAN
    .string "Oh! Jetzt muss ich erst mal meinen Ärger\n"
    .string "loswerden!$"
#else
	.string "Oh! I've got to relieve\n"
	.string "my anger!$"
#endif

Route32_Text_LizPostRematch:
#if GERMAN
    .string "Ich war gerade so schön am Plaudern.$"
#else
	.string "I was having a nice chat too.$"
#endif

Route32_Text_BirdKeeperPeter_Seen:
#if GERMAN
	.string "Wow! Dieser Orden…\p"
	.string "Er ist aus Viola City!\n"
	.string "Du hast Falk besiegt?$"
#else
	.string "That BADGE! It's from VIOLET CITY!\n"
	.string "You beat FALKNER?$"
#endif

Route32_Text_BirdKeeperPeter_Beaten:
#if GERMAN
	.string "Ich kenne jetzt meine Schwächen.$"
#else
	.string "I know what my weaknesses are.$"
#endif

Route32_Text_BirdKeeperPeter_After:
#if GERMAN
	.string "Ich sollte in der Pokémon-Arena von\n"
	.string "Viola City weiter trainieren.$"
#else
	.string "I should train again at the\n"
	.string "GYM in VIOLET CITY.$"
#endif

Route32_Text_RoarIntro:
#if GERMAN
	.string "Brüüüll!\p"
	.string "Alle Leute Laufen Davon, Wenn Ich so\n"
	.string "Brülle, Aber Duuu Bist Hiergeblieben!\l"
	.string "Ich Bin zu Trääänen Gerührt!\l"
	.string "Hiiier, Nimm Das Bitte Miiiiiit!!!$"
#else
	.string "WROOOOAR! PEOPLE RUN WHEN I\n"
	.string "ROAR! BUT YOU CAME LOOKING!\p"
	.string "THAT PLEASES ME! NOW TAKE THIS!$"
#endif

Route32_Text_RoarOutro:
#if GERMAN
	.string "Brüüüll!\n"
	.string "Das ist der Brüller!\l"
	.string "Sogar Pokémon laufen davon, Wenn du ihn\l"
	.string "Einsetzt!$"
#else
	.string "WROOOOAR! IT'S ROAR!\p"
	.string "EVEN POKéMON RUN FROM A GOOD\n"
	.string "ROAR!$"
#endif

Route32_Text_MeetFrieda:
#if GERMAN
	.string "Frieda: Juchhu! Heute ist Freitag!\p"
	.string "Ich bin Frieda vom Freitag!\n"
	.string "Schön, dich zu treffen!\p"
	.string "Hier, ein Giftstich für dich!$"
#else
	.string "FRIEDA: Yahoo! It's Friday!\p"
	.string "I'm FRIEDA of Friday!\n"
	.string "Nice to meet you!\p"
	.string "Here's a POISON BARB for you!$"
#endif

Route32_Text_FriedaGaveGift:
#if GERMAN
	.string "Frieda: Gib es einem Pokémon, das\n"
	.string "über Gift-Attacken verfügt.\p"
	.string "Oh ja!\p"
	.string "Das Ding haut richtig rein!\p"
	.string "Du wirst dich wundern, wie effektiv\n"
	.string "deine Gift-Attacken werden!$"
#else
	.string "FRIEDA: Give it to a POKéMON\n"
	.string "that has POISON-type moves.\p"
	.string "Oh!\p"
	.string "It's wicked!\p"
	.string "You'll be shocked how good it\n"
	.string "makes poison moves!$"
#endif

Route32_Text_FriedaFriday:
#if GERMAN
	.string "Frieda: Hossa! Welchen Wochentag\n"
	.string "hast du am liebsten?\p"
	.string "Ich liebe Freitag.\n"
	.string "Daran gibt es keinen Zweifel!\p"
	.string "Denkst du nicht auch, dass Freitag\n"
	.string "großartig ist?$"
#else
	.string "FRIEDA: Hiya! What day do\n"
	.string "you like?\p"
	.string "I love Friday. No doubt about\n"
	.string "it!\p"
	.string "Don't you think it's great too?$"
#endif

Route32_Text_Sign1:
#if GERMAN
	.string "Route 32\p"
	.string "Viola City - Azalea City$"
#else
	.string "ROUTE 32\p"
	.string "VIOLET CITY - AZALEA TOWN$"
#endif

Route32_Text_Sign2:
#if GERMAN
	.string "Alph-Ruinen\n"
	.string "Osteingang$"
#else
	.string "RUINS OF ALPH\n"
	.string "EAST ENTRANCE$"
#endif

Route32_Text_Sign3:
#if GERMAN
	.string "Zum Einheitstunnel$"
#else
	.string "UNION CAVE\n"
	.string "AHEAD$"
#endif
