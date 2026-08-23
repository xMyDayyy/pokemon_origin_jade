SaffronCity_Dojo_Frlg_MapScripts::
	.byte 0

SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonleeBall::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_DOJO_HITMONLEE_BALL, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_HITMONLEE, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
	release
	end

SaffronCity_Dojo_EventScript_HitmonchanBall::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_DOJO_HITMONCHAN_BALL, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_HITMONCHAN, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_GiveHitmon::
	hidemonpic
	givemon VAR_TEMP_1, 25
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_ReceivedHitmonParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_ReceivedHitmonPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	call SaffronCity_Dojo_EventScript_MarkBallTaken
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_EndGiveMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	call SaffronCity_Dojo_EventScript_MarkBallTaken
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	end

SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_EndGiveMon::
	release
	end

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_Hitoshi::
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hideki::
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Aaron::
	trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Mike::
	trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichi::
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
	@ Kanto-Merge: erst wenn beide Baelle genommen sind.
	goto_if_unset FLAG_HIDE_DOJO_HITMONLEE_BALL, SaffronCity_Dojo_EventScript_MasterKoichiChoose
	goto_if_set FLAG_HIDE_DOJO_HITMONCHAN_BALL, SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
SaffronCity_Dojo_EventScript_MasterKoichiChoose::
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
	release
	end

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	release
	end

SaffronCity_Dojo_Text_MasterKoichiIntro::
#if GERMAN
	.string "Willkommen!\p"
	.string "Ich bin der Karate-meister!\n"
	.string "Ich leite diese Pokémon-Arena!\p"
	.string "Du forderst mich heraus? Also gut!\n"
	.string "Ich kenne keine Gnade!\p"
	.string "Los!$"
#else
	.string "Grunt!\p"
	.string "I am the KARATE MASTER!\n"
	.string "I am the LEADER here!\p"
	.string "You wish to challenge us?\n"
	.string "Expect no mercy!\p"
	.string "Fwaaa!$"
#endif

SaffronCity_Dojo_Text_MasterKoichiDefeat::
#if GERMAN
	.string "Arrgh!\n"
	.string "Ich wurde geschlagen!$"
#else
	.string "Hwa!\n"
	.string "Arrgh! Beaten!$"
#endif

SaffronCity_Dojo_Text_ChoosePrizedFightingMon::
#if GERMAN
	.string "Ich bin deiner Gnade unwürdig!\p"
	.string "Trotzdem flehe ich dich an, unser\n"
	.string "Emblem nicht als Trophäe mitzunehmen!\p"
	.string "Zum Ersatz gebe ich dir unsere\n"
	.string "preisgekrönten Kampf-Pokémon!\p"
	.string "Nimm sie beide mit!$"
#else
	.string "Indeed, I have lost!\p"
	.string "But, I beseech you, do not take\n"
	.string "our emblem as your trophy!\p"
	.string "In return, I will give you a prized\n"
	.string "FIGHTING POKéMON!\p"
	.string "Choose whichever one you like!$"
#endif

SaffronCity_Dojo_Text_StayAndTrainWithUs::
#if GERMAN
	.string "Hi!\p"
	.string "Bleibe doch hier und trainiere\n"
	.string "Karate mit uns!$"
#else
	.string "Grunt!\n"
	.string "Stay and train at karate with us!$"
#endif

SaffronCity_Dojo_Text_MikeIntro::
#if GERMAN
	.string "Stopp!\n"
	.string "Ziehe deine Schuhe aus!$"
#else
	.string "Hoargh!\n"
	.string "Take your shoes off!$"
#endif

SaffronCity_Dojo_Text_MikeDefeat::
#if GERMAN
	.string "Ich gebe auf!$"
#else
	.string "I give up!$"
#endif

SaffronCity_Dojo_Text_MikePostBattle::
#if GERMAN
	.string "Warte nur, bis du unseren Meister\n"
	.string "triffst!\p"
	.string "Verglichen mit ihm bin ich ein\n"
	.string "kleiner Fisch!$"
#else
	.string "You wait 'til you see our MASTER!\n"
	.string "I'm a small fry compared to him!$"
#endif

SaffronCity_Dojo_Text_HidekiIntro::
#if GERMAN
	.string "Du sollst sehr gut sein!\n"
	.string "Beweise es mir!$"
#else
	.string "I hear you're good!\n"
	.string "Show me!$"
#endif

SaffronCity_Dojo_Text_HidekiDefeat::
#if GERMAN
	.string "Schiedsrichter!\n"
	.string "1 Punkt!$"
#else
	.string "Judge!\n"
	.string "One point!$"
#endif

SaffronCity_Dojo_Text_HidekiPostBattle::
#if GERMAN
	.string "Unser Meister ist ein echter Profi!$"
#else
	.string "Our MASTER is a pro fighter.\n"
	.string "Be prepared to lose!$"
#endif

SaffronCity_Dojo_Text_AaronIntro::
#if GERMAN
	.string "Keine Herausforderung ist mir zu\n"
	.string "hart!\p"
	.string "Ich zertrümmere Steine mit bloßen\n"
	.string "Händen!$"
#else
	.string "Hiyah!\n"
	.string "I have no fear for anything tough!\p"
	.string "I shatter boulders for training\n"
	.string "every day!$"
#endif

SaffronCity_Dojo_Text_AaronDefeat::
#if GERMAN
	.string "Autsch!\n"
	.string "Ich habe eine Prellung!$"
#else
	.string "Yow!\n"
	.string "Stubbed fingers!$"
#endif

SaffronCity_Dojo_Text_AaronPostBattle::
#if GERMAN
	.string "Die einzige Sache, vor der wir uns\n"
	.string "fürchten, ist Psychokinese!$"
#else
	.string "The only thing that frightens us is\n"
	.string "psychic power!$"
#endif

SaffronCity_Dojo_Text_HitoshiIntro::
#if GERMAN
	.string "Haii-ia!\p"
	.string "Unbefugten ist der Zutritt zu\n"
	.string "unserem Kampf-dojo verboten!$"
#else
	.string "Hwaah!\p"
	.string "You're trespassing in our\n"
	.string "FIGHTING DOJO!$"
#endif

SaffronCity_Dojo_Text_HitoshiDefeat::
#if GERMAN
	.string "Uff!\n"
	.string "Ich gebe auf!$"
#else
	.string "Oof!\n"
	.string "I give up!$"
#endif

SaffronCity_Dojo_Text_HitoshiPostBattle::
#if GERMAN
	.string "Die allerbesten Kämpfer des Landes\n"
	.string "trainieren hier!$"
#else
	.string "The prime fighters across the land\n"
	.string "train here.$"
#endif

SaffronCity_Dojo_Text_YouWantHitmonlee::
#if GERMAN
	.string "Möchtest du Kicklee, das trittstarke\n"
	.string "Pokémon?$"
#else
	.string "You want the hard-kicking\n"
	.string "HITMONLEE?$"
#endif

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster::
#if GERMAN
	.string "{PLAYER} erhält {STR_VAR_1}.$"
#else
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from the KARATE MASTER.$"
#endif

SaffronCity_Dojo_Text_YouWantHitmonchan::
#if GERMAN
	.string "Möchtest du Nockchan, den Meister\n"
	.string "des Boxkampfs?$"
#else
	.string "You want the piston-punching\n"
	.string "HITMONCHAN?$"
#endif

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster2::
	.string "{PLAYER}は　カラテ　だいおう　から\n"
	.string "{STR_VAR_1}を　もらった！$"

SaffronCity_Dojo_Text_BetterNotGetGreedy::
#if GERMAN
	.string "Dieser Ball ist schon leer.$"
#else
	.string "Better not get greedy…$"
#endif

SaffronCity_Dojo_Text_EnemiesOnEverySide::
#if GERMAN
	.string "Überall Gegner!$"
#else
	.string "Enemies on every side!$"
#endif

SaffronCity_Dojo_Text_GoesAroundComesAround::
#if GERMAN
	.string "Wie die Saat, so die Ernte!$"
#else
	.string "What goes around comes around.$"
#endif

SaffronCity_Dojo_Text_FightingDojo::
#if GERMAN
	.string "Kampfarena$"
#else
	.string "FIGHTING DOJO$"
#endif

@ Setzt den Flag des Balls, der gerade genommen wurde. VAR_TEMP_1 haelt die
@ Art, die der jeweilige Ball-Skript gesetzt hat.
SaffronCity_Dojo_EventScript_MarkBallTaken::
	goto_if_eq VAR_TEMP_1, SPECIES_HITMONLEE, SaffronCity_Dojo_EventScript_MarkHitmonlee
	setflag FLAG_HIDE_DOJO_HITMONCHAN_BALL
	return

SaffronCity_Dojo_EventScript_MarkHitmonlee::
	setflag FLAG_HIDE_DOJO_HITMONLEE_BALL
	return
