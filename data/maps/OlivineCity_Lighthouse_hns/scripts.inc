OlivineCity_Lighthouse_hns_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMSwagger::
    finditem ITEM_TM_SWAGGER
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
#if GERMAN
	.string "Die Leute kommen zum Leuchtturm, um zu\n"
	.string "trainieren.\p"
	.string "Aufgrund der vielen Trainer ist es nicht\n"
	.string "einfach, sich bis ganz nach oben\l"
	.string "vorzukämpfen.$"
#else
	.string "People train at this LIGHTHOUSE.\p"
	.string "It's not easy to climb with all\n"
	.string "the trainers waiting inside.$"
#endif

OlivineLighthouse_Text_1FPokefanF:
#if GERMAN
	.string "Früher haben Pokémon nachts die\n"
	.string "Gewässer um Oliviana City erhellt.\p"
	.string "Der Leuchtturm wurde errichtet,\n"
	.string "um diese Pokémon zu ehren.$"
#else
	.string "In the past, POKéMON used to light\n"
	.string "the sea around OLIVINE at night.\p"
	.string "The LIGHTHOUSE was built in honor\n"
	.string "of those noble POKéMON.$"
#endif

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY_HNS, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten, OlivineLighthouse_EventScript_RegisterHuey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, OlivineLighthouse_EventScript_RematchHuey
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_RegisterHuey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox OlivineLighthouse_Text_HueyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HUEY_HNS
	release
	end

OlivineLighthouse_EventScript_RematchHuey::
	trainerbattle_rematch TRAINER_HUEY_HNS, OlivineLighthouse_Text_HueyRematchIntro, OlivineLighthouse_Text_HueyRematchDefeat
	msgbox OlivineLighthouse_Text_HueyPostRematch, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED_HNS, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
#if GERMAN
	.string "Seefahrer sind immer wild auf einen\n"
	.string "guten Kampf!$"
#else
	.string "Men of the sea are always\n"
	.string "spoiling for a good fight!$"
#endif

OlivineLighthouse_Text_SailorHueyBeaten:
#if GERMAN
	.string "Uff!\n"
	.string "Der hat gesessen!$"
#else
	.string "Urf!\n"
	.string "I lose!$"
#endif

OlivineLighthouse_Text_SailorHueyAfter:
#if GERMAN
	.string "Du bist schwer auf Zack! Möchtest du\n"
	.string "mit mir die Meere unsicher machen?$"
#else
	.string "What power! How would you like\n"
	.string "to sail the seas with me?$"
#endif

OlivineLighthouse_Text_HueyRegister:
#if GERMAN
	.string "Du bist schwer auf Zack! Möchtest du\n"
	.string "mit mir die Meere unsicher machen?$"
#else
	.string "What power! How would you like\n"
	.string "to sail the seas with me?$"
#endif

OlivineLighthouse_Text_HueyRematchIntro:
#if GERMAN
	.string "Seefahrer sind immer wild auf einen\n"
	.string "guten Kampf!$"
#else
	.string "Men of the sea are always\n"
	.string "spoiling for a good fight!$"
#endif

OlivineLighthouse_Text_HueyRematchDefeat:
#if GERMAN
	.string "Uff!\n"
	.string "Der hat gesessen!$"
#else
	.string "Urf!\n"
	.string "I lose!$"
#endif

OlivineLighthouse_Text_HueyPostRematch:
#if GERMAN
	.string "Du bist schwer auf Zack! Möchtest du\n"
	.string "mit mir die Meere unsicher machen?$"
#else
	.string "What power! How would you like\n"
	.string "to sail the seas with me?$"
#endif

OlivineLighthouse_Text_GentlemanAlfredSeen:
#if GERMAN
	.string "He, du da!\n"
	.string "Wir sind hier nicht auf dem Spielplatz!$"
#else
	.string "Hm? This is no place\n"
	.string "for playing.$"
#endif

OlivineLighthouse_Text_GentlemanAlfredBeaten:
#if GERMAN
	.string "Ah! Ich sehe, du meinst es ernst.$"
#else
	.string "Ah! I can see that you're\n"
	.string "serious.$"
#endif

OlivineLighthouse_Text_GentlemanAlfredAfter:
#if GERMAN
	.string "Oben ist ein Pokémon, das den\n"
	.string "Leuchtturm erhellt.\p"
	.string "Doch es ist nun krank und lässt sich\n"
	.string "nicht normal heilen.$"
#else
	.string "Up top is a POKéMON that keeps\n"
	.string "the LIGHTHOUSE lit.\p"
	.string "But I hear that it's sick now,\n"
	.string "and can't be cured normally.$"
#endif

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO_HNS, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL_HNS, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON_HNS, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
#if GERMAN
	.string "Warum bist du hier? Willst du nur\n"
	.string "glotzen? Geh besser weg!$"
#else
	.string "Why are you here? Are you just\n"
	.string "going to gawk? I suggest you leave!$"
#endif

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
#if GERMAN
	.string "Du sorgst dich wirklich um das kranke\n"
	.string "Pokémon…$"
#else
	.string "You really are concerned about\n"
	.string "the sick POKéMON…$"
#endif

OlivineLighthouse_Text_BirdKeeperTheoAfter:
#if GERMAN
	.string "Wie zum Henker kommt man bloß da hoch?\n"
	.string "Ich will das kranke Pokémon besuchen,\l"
	.string "aber ich finde den Weg zur Spitze nicht.$"
#else
	.string "How the heck do you go up?\p"
	.string "I want to visit the sick POKéMON,\n"
	.string "but I can't get up there…$"
#endif

OlivineLighthouse_Text_SailorTerrellSeen:
#if GERMAN
	.string "Seeleute sind hart und zart in einem.\n"
	.string "Eine perfekte Mischung, wie ich meine.\l"
	.string "Wie steht es mit dir?$"
#else
	.string "Sailors are both kind and strong.\n"
	.string "How about you?$"
#endif

OlivineLighthouse_Text_SailorTerrellBeaten:
#if GERMAN
	.string "Aaah, du gehörst also auch zu den\n"
	.string "Harten und den Zarten.$"
#else
	.string "You are both kind and strong…$"
#endif

OlivineLighthouse_Text_SailorTerrellAfter:
#if GERMAN
	.string "Jedes Mal, wenn ich nach Oliviana City\n"
	.string "komme, gehe ich in die Pokémon-Arena.\p"
	.string "Aber dass der Pokémon-Typ der Arena-\n"
	.string "leiterin sich geändert hat, war mir neu.$"
#else
	.string "Every time I return to OLIVINE,\n"
	.string "I visit the GYM.\p"
	.string "The GYM LEADER’s POKéMON type\n"
	.string "changed without me noticing.$"
#endif

OlivineLighthouse_Text_GentlemanPrestonSeen:
#if GERMAN
	.string "Ich bereise die Welt, um meine Pokémon\n"
	.string "zu trainieren.\l"
	.string "Ich möchte mit dir kämpfen.$"
#else
	.string "I travel the world to train my\n"
	.string "POKéMON. I wish to battle you.$"
#endif

OlivineLighthouse_Text_GentlemanPrestonBeaten:
#if GERMAN
	.string "… Seufz…\n"
	.string "Immer noch nicht genug trainiert…$"
#else
	.string "…sigh… I must train some more…$"
#endif

OlivineLighthouse_Text_GentlemanPrestonAfter:
#if GERMAN
	.string "Jasmin war ursprünglich auf\n"
	.string "Gestein-Pokémon wie Onix spezialisiert.$"
#else
	.string "JASMINE used to use ROCK-type\n"
	.string "POKéMON like ONIX.$"
#endif

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT_HNS, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE_HNS, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
#if GERMAN
	.string "Jasmin muss krank vor Sorge um das\n"
	.string "Pokémon sein.\l"
	.string "Man sieht sie nicht einmal mehr lächeln.$"
#else
	.string "JASMINE must be worried sick about\n"
	.string "the POKéMON here.\p"
	.string "She won't even smile these days.$"
#endif

OlivineLighthouse_Text_SailorKentBeaten:
#if GERMAN
	.string "Ich habe aber gerade auch nicht viel\n"
	.string "Grund zu lachen…$"
#else
	.string "I can't manage a smile either…$"
#endif

OlivineLighthouse_Text_SailorKentAfter:
#if GERMAN
	.string "Apropos krank: Mir ist zu Ohren\n"
	.string "gekommen, dass es in Anemonia City eine\l"
	.string "gute Apotheke geben soll.$"
#else
	.string "Speaking of sick, I've heard there's\n"
	.string "a good PHARMACY in CIANWOOD.$"
#endif

OlivineLighthouse_Text_LassConnieSeen:
#if GERMAN
	.string "Jasmin leitet die Arena hier in dieser\n"
	.string "Stadt.\p"
	.string "Ich werde sie zurückholen. Besser,\n"
	.string "du stellst dich mir nicht in den Weg!$"
#else
	.string "JASMINE is this city's GYM LEADER.\p"
	.string "I mean to bring her back with me.\p"
	.string "Nobody had better get in my way!$"
#endif

OlivineLighthouse_Text_LassConnieBeaten:
#if GERMAN
	.string "Aaah! Was machst du da mit meinem\n"
	.string "Pokémon?$"
#else
	.string "Aaack! My POKéMON!$"
#endif

OlivineLighthouse_Text_LassConnieAfter:
#if GERMAN
	.string "Richtig. Jeder wäre besorgt, wenn\n"
	.string "seine Pokémon verletzt wären.\p"
	.string "Ich werde für die Pokémon hier beten,\n"
	.string "damit Jasmin zurück zur Arena kann.$"
#else
	.string "Right. Anybody would be worried if\n"
	.string "his or her own POKéMON were hurt.\p"
	.string "I'll pray for the POKéMON here, so\n"
	.string "JASMINE can come back to the GYM.$"
#endif

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST_HNS, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS_HNS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
#if GERMAN
	.string "Ich hatte vor, gegen Jasmin zu kämpfen,\n"
	.string "aber sie ist nicht da.\l"
	.string "Wie wäre es mit dir?$"
#else
	.string "I wanted to battle JASMINE, but she's\n"
	.string "not up to it now.\p"
	.string "So, how about you?$"
#endif

OlivineLighthouse_Text_SailorErnestBeaten:
#if GERMAN
	.string "Wow, du hast mich überwältigt!$"
#else
	.string "Whoa, whoa. You're overwhelming!$"
#endif

OlivineLighthouse_Text_SailorErnestAfter:
#if GERMAN
	.string "Arenaleiter müssen nicht nur stark\n"
	.string "sein. Auch Mitgefühl zeichnet sie aus.$"
#else
	.string "A GYM LEADER isn't just about being\n"
	.string "strong.\p"
	.string "A LEADER also needs to be\n"
	.string "compassionate.$"
#endif

OlivineLighthouse_Text_BirdKeeperDenisSeen:
#if GERMAN
	.string "Wir sind hier ziemlich nah am Himmel.\n"
	.string "Vogel-Pokémon sind da in ihrem Element!$"
#else
	.string "We're pretty high up here. My bird\n"
	.string "POKéMON are in prime form.$"
#endif

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
#if GERMAN
	.string "Ups…\n"
	.string "Wer hoch steigt, fällt eben auch tief.$"
#else
	.string "Oops… They crashed…$"
#endif

OlivineLighthouse_Text_BirdKeeperDenisAfter:
#if GERMAN
	.string "Meine Pokémon lernten Fliegen in\n"
	.string "Anemonia City.\p"
	.string "Da ich ein Verlierer bin, werde ich\n"
	.string "über das Meer fliegen…$"
#else
	.string "My POKéMON learned how to use FLY in\n"
	.string "CIANWOOD.\p"
	.string "Well, since I'm a loser, I'll FLY\n"
	.string "across the sea…$"
#endif

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
#if GERMAN
	.string "Jasmin: Dieses Pokémon hat immer\n"
	.string "das Meer für uns ausgeleuchtet.\p"
	.string "Aber dann…\n"
	.string "wurde es plötzlich sehr krank.\l"
	.string "Seitdem ringt es nur noch nach Luft…\p"
	.string "In Anemonia City, auf der anderen Seite\n"
	.string "des Ozeans, soll es einen wundertätigen\l"
	.string "Apotheker geben, aber…\p"
	.string "…ich kann Amphi nicht einfach\n"
	.string "hier alleine lassen…\p"
	.string "Würdest du mir einen Gefallen tun?\n"
	.string "Könntest du vielleicht für mich dort\l"
	.string "Medizin kaufen gehen?\p"
	.string "Ich halte dir auch den Eingang offen…$"
#else
	.string "JASMINE: …This POKéMON always kept\n"
	.string "the sea lit at night.\p"
	.string "…But it suddenly got sick… It's\n"
	.string "gasping for air…\p"
	.string "…I understand that there is a\n"
	.string "wonderful PHARMACY in CIANWOOD…\p"
	.string "But that's across the sea…\n"
	.string "And I can't leave AMPHY unattended…$"
#endif

OlivineLighthouse_Text_JasmineGetMedicine:
#if GERMAN
	.string "D-du tust mir doch den Gefallen, oder?\n"
	.string "Du gehst doch für mich Medizin kaufen,\l"
	.string "bitte!$"
#else
	.string "…May I ask you to get some medicine\n"
	.string "for me? Please?$"
#endif

OlivineLighthouse_Text_JasmineGetMedicine2:
#if GERMAN
	.string "In Anemonia City gibt es eine tolle\n"
	.string "Apotheke…\p"
	.string "Aber das ist über das Meer…\n"
	.string "Und Amphy kann ich nicht allein lassen…\p"
	.string "…Kannst du bitte Medizin für mich\n"
	.string "holen? Bitte?$"
#else
	.string "There is a wonderful PHARMACY\n"
	.string "in CIANWOOD…\p"
	.string "But that's across the sea…\n"
	.string "And I can't leave AMPHY unattended…\p"
	.string "…May I ask you to get some medicine\n"
	.string "for me? Please?$"
#endif

OlivineLighthouse_Text_JasmineCureAmphy:
#if GERMAN
	.string "Jasmin: …Kann Amphi mit dieser\n"
	.string "Medizin geheilt werden?$"
#else
	.string "JASMINE: …Will that medicine cure\n"
	.string "AMPHY?$"
#endif


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playfanfare MUS_HEAL
	waitfanfare
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
#if GERMAN
	.string "{PLAYER} übergab Jasmin den\n"
	.string "Geheimtrank.$"
#else
	.string "{PLAYER} handed the SECRET POTION to\n"
	.string "JASMINE.$"
#endif

OlivineLighthouse_Text_JasmineDontBeOffended:
#if GERMAN
	.string "Jasmin: Ni-nimm mir das bitte nicht übel,\n"
	.string "ja?\p"
	.string "Amphi lässt sich bloß von niemand\n"
	.string "anderem als mir füttern…$"
#else
	.string "JASMINE: …Um, please don't be\n"
	.string "offended…\p"
	.string "…AMPHY will not take anything from\n"
	.string "anyone but me…$"
#endif

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
#if GERMAN
	.string "Jasmin: …\p"
	.string "Wie geht es dir jetzt, Amphi?$"
#else
	.string "JASMINE: …\p"
	.string "AMPHY, how are you feeling?$"
#endif

OlivineLighthouse_Text_JasmineThankYou:
#if GERMAN
	.string "Jasmin: Oh, so ein Glück!\n"
	.string "Es hat wirklich geklappt!\p"
	.string "Ich bin dir ja so dankbar!\n"
	.string "Das ist alles dein Verdienst!\p"
	.string "…In Ordnung! Dann gehe ich jetzt\n"
	.string "zurück in die Arena!$"
#else
	.string "JASMINE: …Oh, I'm so relieved…\p"
	.string "This is just so wonderful…\p"
	.string "Thank you so very, very much.\p"
	.string "…I will return to the GYM…\p"
	.string "I'll also warn you, STEEL types\n"
	.string "are powerful.$"
#endif

OlivineLighthouse_Text_JasmineISee:
#if GERMAN
	.string "Jasmine: …Oh mann…\n"
	.string "…Amphy, halt durch!$"
#else
	.string "JASMINE: …I see…\n"
	.string "…AMPHY, hang on!$"
#endif

OlivineLighthouse_Text_AmphyPalPaloo:
#if GERMAN
	.string "Amphi: … …Am… pha…$"
#else
	.string "AMPHY: …\n"
	.string "…Pa… paloo…$"
#endif

OlivineLighthouse_Text_AmphyBreathingLabored:
#if GERMAN
	.string "Sein Atem ist schwer…$"
#else
	.string "Its breathing is terribly\n"
	.string "labored…$"
#endif

OlivineLighthouse_Text_AmphyPaluPalulu:
#if GERMAN
	.string "Amphi: Ampha! Ampharos!$"
#else
	.string "AMPHY: Palu! Palulu!$"
#endif


