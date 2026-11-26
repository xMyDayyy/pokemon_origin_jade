RustboroCity_DevonCorp_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
	.byte 0

RustboroCity_DevonCorp_2F_OnTransition:
	call_if_eq VAR_HOENN_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetHoennFossilReady
	end

RustboroCity_DevonCorp_2F_EventScript_SetHoennFossilReady::
	setvar VAR_HOENN_FOSSIL_RESURRECTION_STATE, 2
	return

@ Used by the Ruins of Alph lab in Johto.
RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_BallScientist::
	lock
	faceplayer
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
	lock
	faceplayer
	goto_if_set FLAG_HOENN_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
	lock
	faceplayer
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_HOENN_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
	goto_if_eq VAR_HOENN_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	call Common_EventScript_CountFossils
	goto_if_ne VAR_0x8004, 0, RustboroCity_DevonCorp_2F_EventScript_NoticeFossil
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	goto_if_ge VAR_0x8004, 2, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	goto RustboroCity_DevonCorp_2F_EventScript_GiveFossil
	end

@ VAR_0x8005: fossil kind from Common_EventScript_CountFossils (1 Root ... 5 Old Amber).
RustboroCity_DevonCorp_2F_EventScript_GiveFossil::
	call Common_EventScript_FossilKindInfo
	bufferitemname STR_VAR_1, VAR_0x8006
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	call Common_EventScript_RemoveFossilKind
	setvar VAR_HOENN_FOSSIL_RESURRECTION_STATE, 1
	copyvar VAR_HOENN_WHICH_FOSSIL_REVIVED, VAR_0x8005
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
	copyvar VAR_0x8005, VAR_HOENN_WHICH_FOSSIL_REVIVED
	call Common_EventScript_FossilKindInfo
	goto_if_eq VAR_0x8007, SPECIES_NONE, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
	bufferspeciesname STR_VAR_2, VAR_0x8007
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	copyvar VAR_TEMP_TRANSFERRED_SPECIES, VAR_0x8007
	givemon VAR_0x8007, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilMonParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilMonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilMonParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilMonFanfare
	call Common_EventScript_AskNicknameGiftPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilMonPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilMonFanfare
	call Common_EventScript_AskNicknameGiftBoxMon
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossilMon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilMonFanfare::
	bufferspeciesname STR_VAR_2, VAR_TEMP_TRANSFERRED_SPECIES
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossilMon::
	setvar VAR_HOENN_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_HOENN_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
	waitmessage
	multichoice 17, 0, MULTI_FOSSIL_HNS, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
	case 2, RustboroCity_DevonCorp_2F_EventScript_ChooseHelixFossil
	case 3, RustboroCity_DevonCorp_2F_EventScript_ChooseDomeFossil
	case 4, RustboroCity_DevonCorp_2F_EventScript_ChooseOldAmber
	goto RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
	setvar VAR_0x8005, 1
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseFossilCheckBag
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
	setvar VAR_0x8005, 2
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseFossilCheckBag
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseHelixFossil::
	setvar VAR_0x8005, 3
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseFossilCheckBag
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseDomeFossil::
	setvar VAR_0x8005, 4
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseFossilCheckBag
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseOldAmber::
	setvar VAR_0x8005, 5
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseFossilCheckBag
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseFossilCheckBag::
	call Common_EventScript_FossilKindInfo
	checkitem VAR_0x8006
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_GiveFossil
	goto RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	end

RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
	release
	end

@ Shared by every fossil lab (Devon, Ruins of Alph, Cinnabar Island).
@ Out: VAR_0x8004 = number of fossil kinds in the bag, VAR_0x8005 = the last kind
@ found: 1 Root, 2 Claw, 3 Helix, 4 Dome, 5 Old Amber (as VAR_WHICH_FOSSIL_REVIVED).
Common_EventScript_CountFossils::
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	checkitem ITEM_ROOT_FOSSIL
	call_if_eq VAR_RESULT, TRUE, Common_EventScript_CountRootFossil
	checkitem ITEM_CLAW_FOSSIL
	call_if_eq VAR_RESULT, TRUE, Common_EventScript_CountClawFossil
	checkitem ITEM_HELIX_FOSSIL
	call_if_eq VAR_RESULT, TRUE, Common_EventScript_CountHelixFossil
	checkitem ITEM_DOME_FOSSIL
	call_if_eq VAR_RESULT, TRUE, Common_EventScript_CountDomeFossil
	checkitem ITEM_OLD_AMBER
	call_if_eq VAR_RESULT, TRUE, Common_EventScript_CountOldAmber
	return

Common_EventScript_CountRootFossil::
	addvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	return

Common_EventScript_CountClawFossil::
	addvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	return

Common_EventScript_CountHelixFossil::
	addvar VAR_0x8004, 1
	setvar VAR_0x8005, 3
	return

Common_EventScript_CountDomeFossil::
	addvar VAR_0x8004, 1
	setvar VAR_0x8005, 4
	return

Common_EventScript_CountOldAmber::
	addvar VAR_0x8004, 1
	setvar VAR_0x8005, 5
	return

@ In: VAR_0x8005 = fossil kind. Takes that fossil from the bag.
@ Plain item ids so tools/make_debug_states.py sees the fossil leave the bag.
Common_EventScript_RemoveFossilKind::
	switch VAR_0x8005
	case 1, Common_EventScript_RemoveRootFossil
	case 2, Common_EventScript_RemoveClawFossil
	case 3, Common_EventScript_RemoveHelixFossil
	case 4, Common_EventScript_RemoveDomeFossil
	case 5, Common_EventScript_RemoveOldAmber
	return

Common_EventScript_RemoveRootFossil::
	removeitem ITEM_ROOT_FOSSIL
	return

Common_EventScript_RemoveClawFossil::
	removeitem ITEM_CLAW_FOSSIL
	return

Common_EventScript_RemoveHelixFossil::
	removeitem ITEM_HELIX_FOSSIL
	return

Common_EventScript_RemoveDomeFossil::
	removeitem ITEM_DOME_FOSSIL
	return

Common_EventScript_RemoveOldAmber::
	removeitem ITEM_OLD_AMBER
	return

@ In: VAR_0x8005 = fossil kind. Out: VAR_0x8006 = item, VAR_0x8007 = species
@ (ITEM_NONE and SPECIES_NONE for an unknown kind).
Common_EventScript_FossilKindInfo::
	setvar VAR_0x8006, ITEM_NONE
	setvar VAR_0x8007, SPECIES_NONE
	switch VAR_0x8005
	case 1, Common_EventScript_FossilKindRoot
	case 2, Common_EventScript_FossilKindClaw
	case 3, Common_EventScript_FossilKindHelix
	case 4, Common_EventScript_FossilKindDome
	case 5, Common_EventScript_FossilKindAmber
	return

Common_EventScript_FossilKindRoot::
	setvar VAR_0x8006, ITEM_ROOT_FOSSIL
	setvar VAR_0x8007, SPECIES_LILEEP
	return

Common_EventScript_FossilKindClaw::
	setvar VAR_0x8006, ITEM_CLAW_FOSSIL
	setvar VAR_0x8007, SPECIES_ANORITH
	return

Common_EventScript_FossilKindHelix::
	setvar VAR_0x8006, ITEM_HELIX_FOSSIL
	setvar VAR_0x8007, SPECIES_OMANYTE
	return

Common_EventScript_FossilKindDome::
	setvar VAR_0x8006, ITEM_DOME_FOSSIL
	setvar VAR_0x8007, SPECIES_KABUTO
	return

Common_EventScript_FossilKindAmber::
	setvar VAR_0x8006, ITEM_OLD_AMBER
	setvar VAR_0x8007, SPECIES_AERODACTYL
	return

RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
	lock
	faceplayer
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
#if GERMAN
	.string "Wir wollen ein Gerät entwickeln, mit\n"
	.string "dem wir mit Pokémon reden können.\p"
	.string "Aber bisher waren wir nicht sehr\n"
	.string "erfolgreich…$"
#else
	.string "We're developing a device for talking\n"
	.string "with POKéMON.\p"
	.string "But we haven't had much success…$"
#endif

RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
#if GERMAN
	.string "Ich entwickle neue Arten von\n"
	.string "Pokébällen…\p"
	.string "Aber noch bin ich nicht sonderlich\n"
	.string "weit mit der Entwicklung gekommen…$"
#else
	.string "I'm developing new kinds of\n"
	.string "POKé BALLS…\p"
	.string "But I haven't made much headway…$"
#endif

RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
#if GERMAN
	.string "Wir haben endlich neue Pokébälle\n"
	.string "entwickelt!\p"
	.string "Mit dem Wiederball lassen sich Pokémon\n"
	.string "leichter fangen, die du vorher schon mal\l"
	.string "gefangen hattest.\p"
	.string "Mit dem Timerball lassen sich Pokémon\n"
	.string "umso leichter fangen, je länger der\l"
	.string "Kampf dauert.\p"
	.string "Beide werden voller Stolz von der\n"
	.string "Devon Corporation präsentiert.\p"
	.string "Probiere sie bitte unbedingt aus!$"
#else
	.string "We finally made new kinds of\n"
	.string "POKé BALLS!\p"
	.string "The REPEAT BALL makes it easier to\n"
	.string "catch POKéMON you've caught before.\p"
	.string "The TIMER BALL gets better at catching\n"
	.string "POKéMON the longer a battle runs.\p"
	.string "Both are proudly developed by\n"
	.string "the DEVON CORPORATION.\p"
	.string "Please give them a try!$"
#endif

RustboroCity_DevonCorp_2F_Text_IMadePokenav:
#if GERMAN
	.string "Ich habe den PokéCom entwickelt!\p"
	.string "Als Ingenieur erfüllt es mich mit Stolz,\n"
	.string "so etwas Großartiges entwickelt zu\l"
	.string "haben.$"
#else
	.string "I made the POKéGEAR!\p"
	.string "As an engineer, I feel blessed to have\n"
	.string "made something so great!$"
#endif

RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
#if GERMAN
	.string "Oh, wow!\n"
	.string "Das ist ein PokéCom!\p"
	.string "Er ist das Resultat der Wissbegierde\n"
	.string "unseres Präsidenten, der etwas über\l"
	.string "die Gefühle der Pokémon lernen möchte.$"
#else
	.string "Oh, wow!\n"
	.string "That's a POKéGEAR!\p"
	.string "It came about as a result of our\n"
	.string "PRESIDENT's desire to learn about\l"
	.string "the feelings of POKéMON.$"
#endif

RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
#if GERMAN
	.string "Ich arbeite an einer Vorrichtung, die\n"
	.string "die Träume der Pokémon visualisieren\l"
	.string "kann…\p"
	.string "Aber so richtig geht es nicht voran.$"
#else
	.string "I'm trying to develop a device that\n"
	.string "visually reproduces the dreams of\l"
	.string "POKéMON…\p"
	.string "But it's not going well.$"
#endif

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
#if GERMAN
	.string "Ich arbeite an einer Vorrichtung, die\n"
	.string "Pokémon aus Fossilien wieder zum Leben\l"
	.string "erweckt.\p"
	.string "Und… Es klappt!!!$"
#else
	.string "I've been trying to develop a device\n"
	.string "that resurrects POKéMON from fossils…\p"
	.string "And, it's working!$"
#endif

RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
#if GERMAN
	.string "Warte! Das Teil dort…\n"
	.string "Ist das ein Pokémon-Fossil?\p"
	.string "Möchtest du das Pokémon wieder zum\n"
	.string "Leben erwecken?\p"
	.string "Ich kann dir mit meiner neuesten\n"
	.string "Entwicklung, dem Fossil-Regenerator,\l"
	.string "dabei helfen.$"
#else
	.string "Wait! That thing you have there…\n"
	.string "Is that a POKéMON fossil?\p"
	.string "Would you like to bring that POKéMON\n"
	.string "back to life?\p"
	.string "I can with my newly developed\n"
	.string "FOSSIL REGENERATOR.$"
#endif

RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
#if GERMAN
	.string "Ehrlich?\p"
	.string "Devon besitzt einen hervorragenden\n"
	.string "Ruf in Sachen Technik. \l"
	.string "Das versichere ich dir!$"
#else
	.string "Oh, is that so?\p"
	.string "DEVON's technological expertise\n"
	.string "is outstanding, I tell you.$"
#endif

RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
#if GERMAN
	.string "Oh, das ist aber eine Überraschung!\n"
	.string "Du hast mehr als ein Fossil?\p"
	.string "Leider kann meine Maschine immer nur\n"
	.string "ein Pokémon regenerieren.\p"
	.string "Welches Fossil soll ich dafür\n"
	.string "verwenden?$"
#else
	.string "Oh, now that's a surprise!\n"
	.string "You have more than one fossil?\p"
	.string "Unfortunately, my machine can only\n"
	.string "regenerate one POKéMON at a time.\p"
	.string "Which fossil would you like to\n"
	.string "regenerate?$"
#endif

RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
#if GERMAN
	.string "Exzellent!\n"
	.string "Dann lass uns sofort zur Tat schreiten.\p"
	.string "{PLAYER} gibt dem Forscher von Devon\n"
	.string "{STR_VAR_1}.$"
#else
	.string "Excellent!\n"
	.string "Let's do this right away.\p"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
	.string "the DEVON RESEARCHER.$"
#endif

RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
#if GERMAN
	.string "Der Fossil-Regenerator, den ich ent-\n"
	.string "wickelt habe, ist einfach unglaublich.\p"
	.string "Aber einen Nachteil gibt es: Es dauert\n"
	.string "eine Weile, bis der Prozess\l"
	.string "abgeschlossen ist.\p"
	.string "Also, äh… Warum schaust du dich in der\n"
	.string "Zeit nicht ein wenig um?$"
#else
	.string "The FOSSIL REGENERATOR, which I made,\n"
	.string "is incredible.\p"
	.string "But it has one drawback--it takes\n"
	.string "a long time to work.\p"
	.string "So, uh… How about you go for a stroll\n"
	.string "and look around for a while?$"
#endif

RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
#if GERMAN
	.string "Danke für deine Geduld!\p"
	.string "Dein fossiles Pokémon wurde zu neuem\n"
	.string "Leben erweckt!\p"
	.string "Das Fossil war ein altertümliches\n"
	.string "Pokémon. Ein {STR_VAR_2}!$"
#else
	.string "Thanks for waiting!\p"
	.string "Your fossilized POKéMON has been\n"
	.string "brought back to life!\p"
	.string "The fossil was an ancient POKéMON.\n"
	.string "{STR_VAR_2}, it was!$"
#endif

RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
#if GERMAN
	.string "{PLAYER} erhält das {STR_VAR_2} vom\n"
	.string "Forscher von Devon.$"
#else
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the DEVON RESEARCHER.$"
#endif

@ Unused
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
#if GERMAN
	.string "Oh! Du hast zu viele Pokémon dabei.\n"
	.string "Du hast keinen Platz für dieses hier.$"
#else
	.string "Uh-oh, you've got too many POKéMON.\n"
	.string "You have no room for this one.$"
#endif

RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
#if GERMAN
	.string "Ich entwickle ein neues Feature für\n"
	.string "den PokéCom…\p"
	.string "Aber irgendwie habe ich damit\n"
	.string "Probleme…$"
#else
	.string "I'm trying to develop a new feature\n"
	.string "for the POKéGEAR…\p"
	.string "But it's not going well.$"
#endif

RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
#if GERMAN
	.string "Mh, was soll ich als Nächstes\n"
	.string "entwickeln?\p"
	.string "Unsere Firma erlaubt es uns, unsere\n"
	.string "kreativen Fantasien Wirklichkeit\l"
	.string "werden zu lassen.\p"
	.string "Als Ingenieur kann man sich nichts\n"
	.string "Besseres wünschen!$"
#else
	.string "Well, now what shall I work on\n"
	.string "developing next?\p"
	.string "Our company allows us to make our\n"
	.string "inspirations into reality.\p"
	.string "One couldn't ask for a better\n"
	.string "environment as an engineer.$"
#endif

