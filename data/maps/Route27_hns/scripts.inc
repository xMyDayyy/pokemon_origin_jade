Route27_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route27_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route27_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route27_EventScript_BaobaCall::
	setspeaker Route27_Text_BaobaName
	pokenavcall BlackthornCity_Text_BaobaCall
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_WEST_EXPANSION
    setvar VAR_ROUTE27_BAOBA_CALL, 1
	end

Route27_Text_BaobaName:
#if GERMAN
	.string "Baoba$"
#else
	.string "BAOBA$"
#endif

Route27_EventScript_FirstSteps::
    lock
    playse SE_PIN
    @ Origin Jade: FLAG_VISITED_KANTO stammt aus dem HnS-Kanon (Start in Johto).
    @ Hier startet der Spieler in Kanto; der Karten-Merge haengt an
    @ FLAG_VISITED_JOHTO und wird in Route26North_hns gesetzt. Das alte setflag
    @ steuerte nichts mehr und ist entfernt.
    applymovement2 LOCALID_ROUTE27_FATMAN, Common_Movement_ExclamationMark
    turnobject LOCALID_ROUTE27_FATMAN, DIR_WEST
    delay 30
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_1, 24, Route27_EventScript_FirstStepsWalkTop
    call_if_eq VAR_TEMP_1, 25, Route27_EventScript_FirstStepsWalkBot

    msgbox Route27_Text_FisherHey, MSGBOX_DEFAULT
    msgbox Route27_Text_FisherMessage, MSGBOX_DEFAULT
    closemessage
    turnobject LOCALID_ROUTE27_FATMAN, DIR_SOUTH

    @integrated flagheap
    setflag FLAG_HIDE_VICTORY_ROAD_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK

    clearflag FLAG_GOT_TM_SANDSTORM
    clearflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
    clearflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD

    setvar VAR_ROUTE27_STATE, 1
    release
    end

Route27_EventScript_FirstStepsWalkTop::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkTop
    waitmovement 0
    return
Route27_EventScript_FirstStepsWalkBot::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkBot
    waitmovement 0
    return

Route27_Movement_WalkTop:
    face_left
    walk_left
    step_end

Route27_Movement_WalkBot:
    walk_down
    walk_left
    step_end

Route27_EventScript_Item_Moonstone::
    finditem ITEM_MOON_STONE
    end

Route27_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

Route27_EventScript_Item_DragonClaw::
    finditem ITEM_TM_DRAGON_CLAW
    end

Route27_EventScript_Item_Destiny_Knot::
    finditem ITEM_DESTINY_KNOT
    end

Route27_EventScript_Fatman::
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
    end

Route27_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE_HNS, Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Brian::
	trainerbattle_single TRAINER_BRIAN_HNS, Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Reena::
	trainerbattle_single TRAINER_REENA_HNS, Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten, Route27_EventScript_RegisterReena
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchReena
	msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_RegisterReena::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route27_Text_ReenaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_REENA_HNS
	release
	end

Route27_EventScript_RematchReena::
	trainerbattle_rematch TRAINER_REENA_HNS, Route27_Text_ReenaRematchIntro, Route27_Text_ReenaRematchDefeat
	msgbox Route27_Text_ReenaPostRematch, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Megan::
	trainerbattle_single TRAINER_MEGAN_HNS, Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT_HNS, Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE_HNS, Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten, Route27_EventScript_RegisterJose
	goto_if_set FLAG_JOSE_HAS_ITEM_HNS, Route27_EventScript_JoseGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchJose
	msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_RegisterJose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route27_Text_JoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOSE_HNS
	release
	end

Route27_EventScript_RematchJose::
	trainerbattle_rematch TRAINER_JOSE_HNS, Route27_Text_JoseRematchIntro, Route27_Text_JoseRematchDefeat
	msgbox Route27_Text_JosePostRematch, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JoseGiveItem::
	msgbox Route27_Text_JoseHasItem, MSGBOX_DEFAULT
	giveitem VAR_JOSE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route27_EventScript_JoseNoRoom
	clearflag FLAG_JOSE_HAS_ITEM_HNS
	msgbox Route27_Text_JoseGaveItem, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JoseNoRoom::
	msgbox Route27_Text_JoseNoRoom, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Scott::
	trainerbattle_single TRAINER_SCOTT_HNS, Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_TohjoFallsSign::
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
    end

Route27_Text_FisherHey:
#if GERMAN
	.string "Hey$"
#else
    .string "Hey!$"
#endif

Route27_Text_FisherMessage:
#if GERMAN
	.string "Soll ich dir was sagen?\p"
	.string "Du hast eben den ersten Schritt in\n"
	.string "Richtung Kanto getan!\p"
	.string "Wirf mal einen Blick auf deine Karte!$"
#else
    .string "Do you know what you just did?\p"
    .string "You've taken your first step into\n"
    .string "KANTO.\p"
    .string "Check your POKéGEAR MAP and see.$"
#endif

Route27_Text_CooltrainermBlakeSeen:
#if GERMAN
	.string "Du siehst sehr stark aus.\n"
	.string "Ich will gegen dich kämpfen!$"
#else
    .string "You look pretty strong.\n"
    .string "Let me battle you!$"
#endif

Route27_Text_CooltrainermBlakeBeaten:
#if GERMAN
	.string "Juhu!$"
#else
    .string "Yow!$"
#endif

Route27_Text_CooltrainermBlakeAfter:
#if GERMAN
	.string "Wenn du das hier erfolgreich über-\n"
	.string "stehst, wirst du die Wahrheit erkennen!\p"
	.string "Entschuldigung, ich wollte nur etwas\n"
	.string "Geistreiches sagen.$"
#else
    .string "If you prevail on this harsh trek,\n"
    .string "the truth will be revealed!\p"
    .string "Heh, sorry, I just wanted to say\n"
    .string "something cool.$"
#endif

Route27_Text_CooltrainermBrianSeen:
#if GERMAN
	.string "Du bist gut, oder?$"
#else
    .string "Hm? You're good, aren't you?$"
#endif

Route27_Text_CooltrainermBrianBeaten:
#if GERMAN
	.string "Wie ich dachte!$"
#else
    .string "Just as I thought!$"
#endif

Route27_Text_CooltrainermBrianAfter:
#if GERMAN
	.string "Ein guter Trainer weiß, woran man einen\n"
	.string "guten Trainer erkennt!$"
#else
    .string "A good trainer can recognize other\n"
    .string "good trainers.$"
#endif

Route27_Text_CooltrainerfReenaSeen:
#if GERMAN
	.string "Du solltest die wilden Pokémon,\n"
	.string "die hier leben, nicht unterschätzen.$"
#else
    .string "You shouldn't underestimate the\n"
    .string "wild POKéMON in these parts.$"
#endif

Route27_Text_CooltrainerfReenaBeaten:
#if GERMAN
	.string "Oh! Du bist viel zu stark!$"
#else
    .string "Oh! You're much too strong!$"
#endif

Route27_Text_CooltrainerfReenaAfter:
#if GERMAN
	.string "Du bist nur ein Kind, aber ich\n"
	.string "unterschätze dich nicht.$"
#else
    .string "You're just a kid, but you're not\n"
    .string "to be underestimated either.$"
#endif

Route27_Text_ReenaRegister:
#if GERMAN
    .string "Du bist zwar noch jung, aber man\n"
    .string "sollte dich nicht unterschätzen.$"
#else
    .string "You're just a kid, but you're not\n"
    .string "to be underestimated either.$"
#endif

Route27_Text_ReenaRematchIntro:
#if GERMAN
    .string "Die wilden Pokémon in dieser Gegend\n"
    .string "solltest du nicht unterschätzen.$"
#else
    .string "You shouldn't underestimate the\n"
    .string "wild POKéMON in these parts.$"
#endif

Route27_Text_ReenaRematchDefeat:
#if GERMAN
    .string "Oh! Du bist viel zu stark!$"
#else
    .string "Oh! You're much too strong!$"
#endif

Route27_Text_ReenaPostRematch:
#if GERMAN
    .string "Du bist zwar noch jung, aber man\n"
    .string "sollte dich nicht unterschätzen.$"
#else
    .string "You're just a kid, but you're not\n"
    .string "to be underestimated either.$"
#endif

Route27_Text_CooltrainerfMeganSeen:
#if GERMAN
	.string "Huch! Hier kommen nur selten Menschen\n"
	.string "vorbei. Bist du hier auf Lehr- und\l"
	.string "Wanderreise?$"
#else
    .string "It's rare to see anyone come here.\p"
    .string "Are you training on your own?$"
#endif

Route27_Text_CooltrainerfMeganBeaten:
#if GERMAN
	.string "Oh! Du bist wirklich auf Zack!$"
#else
    .string "Oh! You're really strong!$"
#endif

Route27_Text_CooltrainerfMeganAfter:
#if GERMAN
	.string "Ich vergleiche entwickelte und nicht\n"
	.string "entwickelte Pokémon miteinander und\l"
	.string "erforsche so ihre Eigenschaften.\p"
	.string "Entwickelte Pokémon sind zwar stärker,\n"
	.string "aber sie erlernen erst spät Attacken.$"
#else
    .string "I'm checking out pre- and post-\n"
    .string "evolution POKéMON.\p"
    .string "Evolution really does make\n"
    .string "POKéMON stronger.\p"
    .string "But evolved forms also learn\n"
    .string "moves later on.$"
#endif

Route27_Text_PsychicGilbertSeen:
#if GERMAN
	.string "Lass mich raten, woran du jetzt denkst.\p"
	.string "Mmmmmmm…\p"
	.string "Ich weiß! Du denkst darüber nach, zur\n"
	.string "Pokémon Liga zu gehen!$"
#else
    .string "Don't say a thing!\p"
    .string "Let me guess what you're thinking.\p"
    .string "Mmmmmmm…\p"
    .string "I got it! You're on the POKéMON\n"
    .string "LEAGUE challenge!$"
#endif

Route27_Text_PsychicGilbertBeaten:
#if GERMAN
	.string "…Du bist echt die Wucht!$"
#else
    .string "You're too much!$"
#endif

Route27_Text_PsychicGilbertAfter:
#if GERMAN
	.string "Mit deinen Fähigkeiten wirst du in der\n"
	.string "Liga bestehen.\p"
	.string "Das sagt meine Vorahnung.$"
#else
    .string "With your skills, you'll do well at\n"
    .string "the LEAGUE.\p"
    .string "That's what my premonition says.$"
#endif

Route27_Text_BirdKeeperJoseSeen:
#if GERMAN
	.string "Tschilp! Tschilp! Tschiiilp!$"
#else
    .string "Tweet! Tweet! Tetweet!$"
#endif

Route27_Text_BirdKeeperJoseBeaten:
#if GERMAN
	.string "Tschilp!$"
#else
    .string "Tweet!$"
#endif

Route27_Text_BirdKeeperJoseAfter:
#if GERMAN
	.string "Vogelfänger wie ich imitieren\n"
	.string "Vogelstimmen, um dadurch unserem\l"
	.string "Pokémon-Team Befehle zu erteilen.$"
#else
    .string "BIRD KEEPERS like me mimic bird\n"
    .string "whistles to command POKéMON.$"
#endif

Route27_Text_JoseRegister:
#if GERMAN
	.string "Vogelfänger wie ich imitieren\n"
	.string "Vogelstimmen, um dadurch unserem\l"
	.string "Pokémon-Team Befehle zu erteilen.$"
#else
    .string "BIRD KEEPERS like me mimic bird\n"
    .string "whistles to command POKéMON.$"
#endif

Route27_Text_JoseRematchIntro:
#if GERMAN
	.string "Tschilp! Tschilp! Tschiiilp!$"
#else
    .string "Tweet! Tweet! Tetweet!$"
#endif

Route27_Text_JoseRematchDefeat:
#if GERMAN
	.string "Tschilp!$"
#else
    .string "Tweet!$"
#endif

Route27_Text_JosePostRematch:
#if GERMAN
	.string "Vogelfänger wie ich imitieren\n"
	.string "Vogelstimmen, um dadurch unserem\l"
	.string "Pokémon-Team Befehle zu erteilen.$"
#else
    .string "BIRD KEEPERS like me mimic bird\n"
    .string "whistles to command POKéMON.$"
#endif

Route27_Text_JoseHasItem:
#if GERMAN
    .string "Hey! Beim Beobachten der Vögel habe\n"
    .string "ich etwas Glänzendes gefunden!\p"
    .string "Hier, du kannst es haben!$"
#else
    .string "Hey! I found something\n"
    .string "shiny while bird-watching!\p"
    .string "Here, you can have it!$"
#endif

Route27_Text_JoseGaveItem:
#if GERMAN
    .string "Hier auf Route 27 finde ich die\n"
    .string "verschiedensten Dinge.\p"
    .string "Ich sage dir Bescheid, wenn ich\n"
    .string "wieder etwas finde!$"
#else
    .string "I find all sorts of things\n"
    .string "out here on ROUTE 27.\p"
    .string "I'll let you know if I find\n"
    .string "anything else!$"
#endif

Route27_Text_JoseNoRoom:
#if GERMAN
    .string "Hm, dein Beutel ist voll.\p"
    .string "Komm wieder, wenn du Platz hast.$"
#else
    .string "Hmm, your BAG is full.\p"
    .string "Come back when you have room.$"
#endif

TohjoFalls_Text_Sign:
#if GERMAN
	.string "Die Tohjo-Fälle Die Grenzlinie zwischen\n"
	.string "Kanto und Johto$"
#else
    .string "TOHJO FALLS\p"
    .string "THE LINK BETWEEN KANTO AND JOHTO$"
#endif

Route27_Text_FisherScottSeen:
#if GERMAN
	.string "Heute fühle ich mich großartig!\p"
	.string "Ich fühle mich so stark, dass ich den\n"
	.string "Liga-Champ besiegen könnte!$"
#else
    .string "I'm feeling great today!\p"
    .string "I feel like I could boot even the\n"
    .string "LEAGUE CHAMP!$"
#endif

Route27_Text_FisherScottBeaten:
#if GERMAN
	.string "Oh nein! Ich bin wohl nicht zum Kämpfen\n"
	.string "geboren!$"
#else
    .string "No! Not in this battle!$"
#endif

Route27_Text_FisherScottAfter:
#if GERMAN
	.string "Angeln und Pokémon sind sehr ähnlich.\n"
	.string "Wenn du einmal aufgibst, ist es vorbei.$"
#else
    .string "Just like in fishing, it's all over\n"
    .string "in POKéMON if you give up.$"
#endif
