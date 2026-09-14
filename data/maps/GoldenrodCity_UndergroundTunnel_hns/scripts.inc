GoldenrodCity_UndergroundTunnel_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
	.byte 0

GoldenrodCity_UndergroundTunnel_OnLoad::
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
	end

GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerBot::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end

GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerTop::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkDown1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end


GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


GoldenrodCity_UndergroundTunnel_Text_Kimono1:
#if GERMAN
	.string "Diese schwarz beklufteten Damen und\n"
	.string "Herren von Team Rocket scheinen ja\l"
	.string "sehr beschäftigt zu sein…\p"
	.string "Das hat mich neugierig gemacht. Sagt\n"
	.string "bloß, Ihr wollt sie Euch vorknöpfen?\l"
	.string "Ihr seid wirklich äußerst mutig!\p"
	.string "Wenn Ihr so weitermacht, wird\n"
	.string "das Legendäre Poké…$"
#else
	.string "Team Rocket members in black suits\n"
	.string "have been running around...\p"
	.string "I was wondering what was going on.\n"
	.string "So, you took on Team Rocket?\l"
	.string "You are impressive!\p"
	.string "You may be able to face the\n"
	.string "legendary POKé...$"
#endif

GoldenrodCity_UndergroundTunnel_Text_Kimono2:
#if GERMAN
	.string "Oh, hoho! Das habt Ihr jetzt aber\n"
	.string "nicht gehört!\p"
	.string "Wir sehen uns wieder!$"
#else
	.string "Hahaha! Never mind.\n"
	.string "I must go now.$"
#endif

GoldenrodUnderground_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC_HNS, GoldenrodUnderground_Text_SupernerdEricSeen, GoldenrodUnderground_Text_SupernerdEricBeaten
	msgbox GoldenrodUnderground_Text_SupernerdEricAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Teru::
	trainerbattle_single TRAINER_TERU_HNS, GoldenrodUnderground_Text_SupernerdTeruSeen, GoldenrodUnderground_Text_SupernerdTeruBeaten
	msgbox GoldenrodUnderground_Text_SupernerdTeruAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Issac::
	trainerbattle_single TRAINER_ISSAC_HNS, GoldenrodUnderground_Text_PokemaniacIssacSeen, GoldenrodUnderground_Text_PokemaniacIssacBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacIssacAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD_HNS, GoldenrodUnderground_Text_PokemaniacDonaldSeen, GoldenrodUnderground_Text_PokemaniacDonaldBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Brother_Haircut1::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT1_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut1
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_OlderBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut1
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut1
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut1
	removemoney 500
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother2
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_OlderBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT1_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodUnderground_EventScript_Brother_Haircut2::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT2_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut2
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_YoungerBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut2
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut2
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut2
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_YoungerBrotherLookCool
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_YoungerBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT2_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherShortOnFunds, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor::
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor
	end

GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor::
	setmetatile 12, 10, 0x2DD, FALSE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Door::
	lock
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor
	msgbox GoldenrodUnderground_Text_DoorsLocked, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor::
	msgbox GoldenrodUnderground_Text_KeyOpenedDoor, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	setmetatile 12, 10, 0x2DD, FALSE
	playse SE_BANG
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened::
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_UndergroundTunnel_EventScript_Item_CoinCase::
	finditem ITEM_COIN_CASE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_Antidote::
	finditem ITEM_ANTIDOTE
	end


GoldenrodUnderground_Text_YoungerBrotherOffer:
#if GERMAN
	.string "Willkommen im Pokémon-Salon!\p"
	.string "Ich bin der jüngere und preiswertere\n"
	.string "Coiffeur-Bruder.\p"
	.string "Ich verschönere dein Pokémon\n"
	.string "für nur ¥300.\p"
	.string "Also? Wie wär’s?$"
#else
    .string "Welcome to the POKéMON SALON!\p"
    .string "I'm the younger and less expensive\n"
    .string "of the two HAIRCUT BROTHERS.\p"
    .string "I'll spiff up your POKéMON for just\n"
    .string "¥300.\p"
    .string "So? How about it?$"
#endif

GoldenrodUnderground_Text_YoungerBrotherAskWhich:
#if GERMAN
	.string "Welches Pokémon soll ich machen?$"
#else
    .string "OK, which POKéMON should I do?$"
#endif

GoldenrodUnderground_Text_YoungerBrotherLookCool:
#if GERMAN
	.string "O.K.! Es wird cool aussehen!$"
#else
    .string "OK! I'll make it look cool!$"
#endif

GoldenrodUnderground_Text_YoungerBrotherAllDone:
#if GERMAN
	.string "Bitte schön! Fertig!$"
#else
    .string "There we go! All done!$"
#endif

GoldenrodUnderground_Text_YoungerBrotherDisappointed:
#if GERMAN
	.string "Nein? Wie schade!$"
#else
    .string "No? How disappointing!$"
#endif

GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
#if GERMAN
	.string "Du hast nicht genügend Geld.$"
#else
    .string "You're a little short on funds.$"
#endif

GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
#if GERMAN
	.string "Ich mache nur einen Haarschnitt\n"
	.string "pro Tag; für heute bin ich fertig.$"
#else
    .string "I can do only one haircut a day.\p"
    .string "Sorry, but I'm all done for today.$"
#endif



GoldenrodUnderground_Text_OlderBrotherOffer:
#if GERMAN
	.string "Willkommen!\p"
	.string "Ich leite den Pokémon-Salon!\p"
	.string "Ich bin der ältere und bessere\n"
	.string "Coiffeur-Bruder.\p"
	.string "Ich verschönere dein Pokémon\n"
	.string "für nur ¥500.\p"
	.string "Soll ich anfangen?$"
#else
    .string "Welcome!\p"
    .string "I run the POKéMON SALON!\p"
    .string "I'm the older and better of the two\n"
    .string "HAIRCUT BROTHERS.\p"
    .string "I can make your POKéMON beautiful\n"
    .string "for just ¥500.\p"
    .string "Would you like me to do that?$"
#endif

GoldenrodUnderground_Text_OlderBrotherAskWhich:
#if GERMAN
	.string "Bei welchem Pokémon soll ich Hand\n"
	.string "anlegen?$"
#else
    .string "Which POKéMON should I work on?$"
#endif

GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
#if GERMAN
	.string "Alles klar! Du wirst deinen Augen nicht\n"
	.string "trauen!$"
#else
    .string "OK! Watch it become beautiful!$"
#endif

GoldenrodUnderground_Text_OlderBrotherAllDone:
#if GERMAN
	.string "Hier! Fertig!$"
#else
    .string "There! All done!$"
#endif

GoldenrodUnderground_Text_OlderBrotherThatsAShame:
#if GERMAN
	.string "Wenn du meinst. Zu schade.$"
#else
    .string "Is that right? That's a shame!$"
#endif

GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
#if GERMAN
	.string "Du hast nicht genügend Geld.$"
#else
    .string "You'll need more money than that.$"
#endif

GoldenrodUnderground_Text_OlderBrotherOnePerDay:
#if GERMAN
	.string "Ich mache nur einen Haarschnitt\n"
	.string "pro Tag; für heute bin ich fertig.$"
#else
    .string "I do only one haircut a day.\n"
    .string "I'm done for today.$"
#endif

GoldenrodUnderground_Text_SupernerdEricSeen:
#if GERMAN
	.string "Ich wurde aus der Spielhalle geworfen.\p"
	.string "Ich wollte mit Pokémon betrügen…$"
#else
    .string "I got booted out of the GAME CORNER.\p"
    .string "I was trying to cheat using my\n"
    .string "POKéMON…$"
#endif

GoldenrodUnderground_Text_SupernerdEricBeaten:
#if GERMAN
	.string "…Grummel…$"
#else
    .string "…Grumble…$"
#endif

GoldenrodUnderground_Text_SupernerdEricAfterBattle:
#if GERMAN
	.string "Vielleicht spiele ich in Zukunft doch\n"
	.string "lieber fair…$"
#else
    .string "I guess I have to do things fair and\n"
    .string "square…$"
#endif

GoldenrodUnderground_Text_SupernerdTeruSeen:
#if GERMAN
	.string "Denkst du bei Kämpfen an Typen?\p"
	.string "Wenn du deine Vorteile kennst,\n"
	.string "wirst du besser kämpfen.$"
#else
    .string "Do you consider type alignments in\n"
    .string "battle?\p"
    .string "If you know your type advantages,\n"
    .string "you'll do better in battle.$"
#endif

GoldenrodUnderground_Text_SupernerdTeruBeaten:
#if GERMAN
	.string "Aua, aua, aua!$"
#else
    .string "Ow, ow, ow!$"
#endif

GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
#if GERMAN
	.string "Ich kenne die Typ-Vorteile.\p"
	.string "Aber ich nutze nur einen Typ.$"
#else
    .string "I know my POKéMON type alignments.\p"
    .string "But I only use one type of POKéMON.$"
#endif

GoldenrodUnderground_Text_PokemaniacIssacSeen:
#if GERMAN
	.string "Mein Pokémon kommt frisch vom\n"
	.string "Coiffeur! Ich zeige dir, wie stark es\l"
	.string "ist!$"
#else
    .string "My POKéMON just got a haircut!\p"
    .string "I'll show you how strong it is!$"
#endif

GoldenrodUnderground_Text_PokemaniacIssacBeaten:
#if GERMAN
	.string "Aaargh!$"
#else
    .string "Aiyeeee!$"
#endif

GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
#if GERMAN
	.string "Deine Pokémon werden zutraulicher,\n"
	.string "wenn du sie zum Coiffeur bringst.$"
#else
    .string "Your POKéMON will like you more if\n"
    .string "you give them haircuts.$"
#endif

GoldenrodUnderground_Text_PokemaniacDonaldSeen:
#if GERMAN
	.string "Du hast doch todsicher ein paar seltene\n"
	.string "Pokémon dabei. Zeig mal her!$"
#else
    .string "I think you have some rare POKéMON\n"
    .string "with you.\p"
    .string "Let me see them!$"
#endif

GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
#if GERMAN
	.string "Gaah! Ich verlor! Wie ärgerlich!$"
#else
    .string "Gaah! I lost! That makes me mad!$"
#endif

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
#if GERMAN
	.string "Gestern Abend beim Fahrradladen fühlte\n"
	.string "ich mich von den Dächern beobachtet…$"
#else
	.string "When I was walking near the BIKE\n"
	.string "SHOP last night, I felt like I was\l"
	.string "being watched from the rooftops...$"
#endif

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
#if GERMAN
	.string "Sammelst du für den Pokédex?\p"
	.string "Tipp: Der Wanderer auf Route 33,\n"
	.string "Tom, ist nett.\p"
	.string "Er ruft dich, wenn er seltene Pokémon\n"
	.string "sieht.$"
#else
    .string "Are you making a POKéDEX? Here's a\n"
    .string "hot tip.\p"
    .string "The HIKER on ROUTE 33, ANTHONY, is a\n"
    .string "good guy.\p"
    .string "He'll phone you if he sees any rare\n"
    .string "POKéMON.$"
#endif

GoldenrodUnderground_Text_DoorsLocked:
#if GERMAN
	.string "Die Tür ist verschlossen…$"
#else
    .string "The door's locked…$"
#endif

GoldenrodUnderground_Text_DoorIsOpen:
#if GERMAN
	.string "Die Tür ist entriegelt.$"
#else
    .string "The door is open.$"
#endif

GoldenrodUnderground_Text_KeyOpenedDoor:
#if GERMAN
	.string "Kelleröffner entriegelt die Tür.$"
#else
    .string "The BASEMENT KEY opened the door.$"
#endif

GoldenrodUnderground_Text_NoEntry:
#if GERMAN
	.string "Bis hierher und nicht weiter$"
#else
    .string "NO ENTRY BEYOND THIS POINT$"
#endif
