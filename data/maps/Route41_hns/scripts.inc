Route41_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	call Route41_EventScript_TryOpenWhirlIslands
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

@ Ho-Oh path: the Tentacruel leave once the Lugia not chosen can be met
@ (after the first Johto title, Ho-Oh caught; see docs/origin_jade/DECISIONS.md, D-026).
Route41_EventScript_TryOpenWhirlIslands::
	goto_if_ne VAR_LUGIA_OR_HOOH, 2, Common_EventScript_NopReturn
	goto_if_unset FLAG_IS_JOHTO_CHAMPION, Common_EventScript_NopReturn
	goto_if_unset FLAG_CAUGHT_HO_OH, Common_EventScript_NopReturn
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	return

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE_HNS, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
#if GERMAN
	.string "Das Wasser ist schön warm. Ich fühle\n"
	.string "mich locker und gelenkig.\l"
	.string "Natürlich trete ich gegen dich an!$"
#else
	.string "The water's warm here.\n"
	.string "I'm loose and limber.\p"
	.string "Sure, I'll take you on!$"
#endif

Route41_Text_SwimmermCharlieBeaten:
#if GERMAN
	.string "Oje! Meine Haut ist schon ganz\n"
	.string "schrumpelig!$"
#else
	.string "Yikes! I've got prune skin!$"
#endif

Route41_Text_SwimmermCharlieAfter:
#if GERMAN
	.string "Ist es nicht entspannend, sich auf dem\n"
	.string "Wasser treiben zu lassen?$"
#else
	.string "Isn't it relaxing just floating\n"
	.string "like this?$"
#endif

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE_HNS, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
#if GERMAN
	.string "Ich bin etwas müde.\n"
	.string "Wenn ich gewinne, leihst du mir dann\l"
	.string "dein Pokémon?$"
#else
	.string "I'm a bit tired.\n"
	.string "If I win, lend me your POKéMON.$"
#endif

Route41_Text_SwimmermGeorgeBeaten:
#if GERMAN
	.string "Keuch, japs…$"
#else
	.string "Pant, pant…$"
#endif

Route41_Text_SwimmermGeorgeAfter:
#if GERMAN
	.string "Anemonia City ist noch so weit weg. Aber\n"
	.string "der Rückweg nach Oliviana City ist auch\l"
	.string "nicht viel kürzer… was soll ich tun?$"
#else
	.string "It's so far to CIANWOOD.\p"
	.string "But it's no easy return trip\n"
	.string "to OLIVINE either.\p"
	.string "What should I do?$"
#endif

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE_HNS, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
#if GERMAN
	.string "Die Inseln hinter den Strudeln bergen\n"
	.string "doch bestimmt irgendein Geheimnis!$"
#else
	.string "See those islands that are\n"
	.string "blocked by whirlpools?\p"
	.string "There just has to be a secret!$"
#endif

Route41_Text_SwimmermBerkeBeaten:
#if GERMAN
	.string "Was ist das Geheimnis deiner Stärke?$"
#else
	.string "What's the secret to your\n"
	.string "strength?$"
#endif

Route41_Text_SwimmermBerkeAfter:
#if GERMAN
	.string "Es war eine dunkle und stürmische\n"
	.string "Nacht…\p"
	.string "als ich dieses riesige Pokémon über den\n"
	.string "Inseln aufsteigen sah.\l"
	.string "Aus seinen silbernen Flügeln wehten\l"
	.string "einige Federn durch die Luft.$"
#else
	.string "It was a dark and stormy night…\p"
	.string "I saw this giant POKéMON flying\n"
	.string "from the islands.\p"
	.string "It was scattering feathers\n"
	.string "from its silver wings.$"
#endif

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK_HNS, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
#if GERMAN
	.string "Hier gibt es hohe Wellen.\n"
	.string "Da ist man schnell außer Puste.$"
#else
	.string "The waves are wild here.\p"
	.string "They tire you out while\n"
	.string "you swim.$"
#endif

Route41_Text_SwimmermKirkBeaten:
#if GERMAN
	.string "I-ich bin fix und fertig!$"
#else
	.string "I'm beat!$"
#endif

Route41_Text_SwimmermKirkAfter:
#if GERMAN
	.string "Die Strömung ist zu stark. Ich kann\n"
	.string "die Inseln nicht erreichen.$"
#else
	.string "The currents keep me from\n"
	.string "reaching that island.$"
#endif

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW_HNS, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
#if GERMAN
	.string "Versuchst du auch, die Geheimnisse\n"
	.string "der Strudelinseln zu ergründen?$"
#else
	.string "Are you seeking the secrets\n"
	.string "of WHIRL ISLANDS?$"
#endif

Route41_Text_SwimmermMathewBeaten:
#if GERMAN
	.string "Uff! Vor dir nimmt man sich besser in\n"
	.string "Acht!$"
#else
	.string "Ooh, you've got great endurance!$"
#endif

Route41_Text_SwimmermMathewAfter:
#if GERMAN
	.string "Ein Geheimnis über die Strudelinseln…\n"
	.string "drinnen ist es Stockfinster!$"
#else
	.string "A secret about WHIRL ISLANDS…\p"
	.string "It's pitch-black inside!$"
#endif

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE_HNS, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
#if GERMAN
	.string "Meine Freunde und ich sind unterwegs zu\n"
	.string "den Strudelinseln, auf Erkundungstour.$"
#else
	.string "I'm on my way to WHIRL ISLANDS.\p"
	.string "I'm going exploring with friends.$"
#endif

Route41_Text_SwimmerfKayleeBeaten:
#if GERMAN
	.string "Hmpf, na gut.$"
#else
	.string "Is that how you do it?$"
#endif

Route41_Text_SwimmerfKayleeAfter:
#if GERMAN
	.string "Tief im Inneren der Strudelinseln soll\n"
	.string "ein riesiges Pokémon hausen.\l"
	.string "Was für ein Pokémon das wohl ist?$"
#else
	.string "There's supposed to be a big\n"
	.string "POKéMON deep beneath WHIRL ISLANDS.\p"
	.string "I wonder what it could be?$"
#endif

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE_HNS, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
#if GERMAN
	.string "Du gleitest so elegant auf deinem\n"
	.string "Pokémon dahin.$"
#else
	.string "You look so elegant,\n"
	.string "riding your POKéMON.$"
#endif

Route41_Text_SwimmerfSusieBeaten:
#if GERMAN
	.string "Du bist eben einfach umwerfend!$"
#else
	.string "I'm crushed…$"
#endif

Route41_Text_SwimmerfSusieAfter:
#if GERMAN
	.string "Da gab es doch diesen Song über den\n"
	.string "Jungen, der auf einem Lapras reitet…$"
#else
	.string "Wasn't there a hit song about\n"
	.string "a boy riding a LAPRAS?$"
#endif

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE_HNS, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
#if GERMAN
	.string "Das Wetter ist so herrlich.\n"
	.string "Ich bin richtig verzückt!$"
#else
	.string "The weather is so beautiful,\n"
	.string "I'm in a daze!$"
#endif

Route41_Text_SwimmerfDeniseBeaten:
#if GERMAN
	.string "Hach!$"
#else
	.string "Ohhh!$"
#endif

Route41_Text_SwimmerfDeniseAfter:
#if GERMAN
	.string "Sonnenbrand ist sehr schlecht für\n"
	.string "die Haut.\p"
	.string "Aber ich verwende keine Sonnencreme.\n"
	.string "Ich will das Meer nicht verschmutzen.$"
#else
	.string "A sunburn is the worst for skin.\p"
	.string "But I don't use a sunblock.\p"
	.string "I won't pollute the water.$"
#endif

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA_HNS, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
#if GERMAN
	.string "Erschöpft? Halte einfach deinen Kopf\n"
	.string "über Wasser und paddle mit den Füßen.\l"
	.string "Dann bist du wieder quietschfidel!$"
#else
	.string "If you need to rest,\n"
	.string "just tread water.\p"
	.string "You'll get your wind back,\n"
	.string "so you can keep on going strong.$"
#endif

Route41_Text_SwimmerfKaraBeaten:
#if GERMAN
	.string "Ach Mann! Ich glaube, auf dich trifft\n"
	.string "quietschfidel viel eher zu!$"
#else
	.string "Oh! You have more energy than I do.$"
#endif

Route41_Text_SwimmerfKaraAfter:
#if GERMAN
	.string "Ich habe tief aus dem Inneren der\n"
	.string "Strudelinseln ein Brüllen gehört.$"
#else
	.string "I heard roars from deep inside\n"
	.string "the ISLANDS.$"
#endif

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY_HNS, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
#if GERMAN
	.string "Wenn es Nacht wird, sammeln sich\n"
	.string "Schwärme von Sterndu nahe der Küste\l"
	.string "von Oliviana City.$"
#else
	.string "At night, STARYU gather near\n"
	.string "the water's surface.$"
#endif

Route41_Text_SwimmerfWendyBeaten:
#if GERMAN
	.string "Oje…$"
#else
	.string "Oh, dear…$"
#endif

Route41_Text_SwimmerfWendyAfter:
#if GERMAN
	.string "In der Gruppe fangen Sterndu an zu\n"
	.string "leuchten. Das ist so wunderschön, dass\l"
	.string "man fast schon Angst bekommt!$"
#else
	.string "The clusters of STARYU light up\n"
	.string "at the same time.\p"
	.string "It's so beautiful, it's scary.$"
#endif

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
#if GERMAN
	.string "Tentoxa: Cruooo…$"
#else
	.string "TENTACRUEL: Cruooo...$"
#endif

Route41_Text_TentacruelAttack:
#if GERMAN
	.string "Tentoxa: Cruoooooo!$"
#else
	.string "TENTACRUEL: CRUOOOOOO!$"
#endif

Route41_Text_TentacruelHeal:
#if GERMAN
	.string "Das Tentoxa benutzt Genesung!\n"
	.string "Es ist vollständig geheilt!$"
#else
	.string "The TENTACRUEL used RECOVER!\n"
	.string "It is fully healed!$"
#endif
