ViridianCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	.byte 0

ViridianCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_SetOldManBlockingRoad
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_SetOldManStandingByRoad
	call_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_SetOldManNormal
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0, ViridianCity_EventScript_TryUnlockGym
	end

ViridianCity_EventScript_SetOldManNormal::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	return

ViridianCity_EventScript_SetOldManStandingByRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	setobjectxyperm LOCALID_TUTORIAL_MAN, 24, 9
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
	return

ViridianCity_EventScript_SetOldManBlockingRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
	setobjectxyperm LOCALID_TUTORIAL_MAN, 24, 11
	setobjectxyperm LOCALID_VIRIDIAN_WOMAN, 23, 12
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

ViridianCity_EventScript_TryUnlockGym::
	goto_if_unset FLAG_BADGE02_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE04_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE07_GET, Common_EventScript_NopReturn
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
	return

ViridianCity_EventScript_GymDoorLocked::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_GymDoorsAreLocked
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_JumpDownLedge
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_JumpDownLedge::
	walk_down
	step_end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymDoor::
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
	end

ViridianCity_EventScript_Boy::
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
	end

@ Other old man, not the tutorial old man
ViridianCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1, ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs
	closemessage
	applymovement LOCALID_VIRIDIAN_OLD_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_OldManGymLeaderReturned::
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned
	release
	end

ViridianCity_EventScript_TutorialOldMan::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ViridianCity_EventScript_AskIfTeachyTVHelpful
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_TutorialCompleted
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_TutorialStart
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_TutorialNotReady
	end

ViridianCity_EventScript_AskIfTeachyTVHelpful::
	msgbox ViridianCity_Text_HowsTeachyTVHelping, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_TeachyTVNotHelpful
	msgbox ViridianCity_Text_MyGrandsonOnTheShow
	release
	end

ViridianCity_EventScript_TeachyTVNotHelpful::
	msgbox ViridianCity_Text_TooBusyForTeachyTV
	release
	end

ViridianCity_EventScript_TutorialCompleted::
	msgbox ViridianCity_Text_WeakenMonsFirstToCatch
	release
	end

ViridianCity_EventScript_TutorialStart::
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

@ Kanto-Merge: Erfahrene Spieler koennen das Tutorial ueberspringen. Der
@ Weg wird trotzdem frei und das Lehr-TV gibt es auch.
ViridianCity_EventScript_TutorialDeclined::
	msgbox ViridianCity_Text_TutorialDeclined
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	goto ViridianCity_EventScript_GiveRadio

@ Kanto-Merge: Statt des Lehrkanals gibt es das Radiomodul fuer das PokeCom.
@ Der Lehrkanal existiert in diesem Aufbau nicht - die Radiosender stehen in
@ sRadioChannels (pokenav_radio.c), und Eichs Pokemon-Talk ist der Sender mit
@ den Tipps.
ViridianCity_EventScript_GiveRadio::
	goto_if_set FLAG_ENABLE_RADIO, ViridianCity_EventScript_RadioDone
	playfanfare MUS_OBTAIN_ITEM
	message ViridianCity_Text_ReceivedRadio
	waitfanfare
	setflag FLAG_ENABLE_RADIO
	msgbox ViridianCity_Text_ExplainRadio
ViridianCity_EventScript_RadioDone::
	return

ViridianCity_Text_ReceivedRadio:
#if GERMAN
	.string "{PLAYER} erhielt das Radiomodul\n"
	.string "für das PokéCom!$"
#else
	.string "{PLAYER} received the RADIO CARD\n"
	.string "for the POKéGEAR!$"
#endif

ViridianCity_Text_ExplainRadio:
#if GERMAN
	.string "Steck das in dein PokéCom, dann\n"
	.string "hast du unterwegs Radio.\p"
	.string "Bei Professor Eichs Pokémon-Talk\n"
	.string "gibt es jede Menge Tipps.\p"
	.string "Hör da ruhig mal rein!$"
#else
	.string "Put that in your POKéGEAR and\n"
	.string "you'll have radio on the road.\p"
	.string "PROF. OAK's POKéMON TALK is full\n"
	.string "of useful tips.\p"
	.string "Give it a listen!$"
#endif

ViridianCity_Text_AskShowCatching:
#if GERMAN
	.string "Dann sollte ich es dir wohl besser\n"
	.string "zeigen!\p"
	.string "Soll ich?$"
#else
	.string "You look like you could use a\n"
	.string "demonstration.\p"
	.string "Shall I show you how to catch\n"
	.string "POKéMON?$"
#endif

ViridianCity_Text_TutorialDeclined:
#if GERMAN
	.string "Oh, du kennst dich also schon aus.\p"
	.string "Dann geh nur, der Weg ist frei.$"
#else
	.string "Oh, you know your way around already.\p"
	.string "Go right ahead then, the road is clear.$"
#endif

@ Unused
ViridianCity_EventScript_WatchToLearnBasics::
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	release
	end

@ Unused. Starts battle after the post battle text, which is odd.
ViridianCity_EventScript_TutorialUnused::
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	special StartOldManTutorialBattle
	waitstate
	release
	end

ViridianCity_EventScript_TutorialNotReady::
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	release
	end

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ViridianCity_EventScript_YoungsterExplainCaterpillars
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_EventScript_YoungsterExplainCaterpillars::
	msgbox ViridianCity_Text_ExplainCaterpieWeedle
	release
	end

ViridianCity_EventScript_YoungsterDeclineExplanation::
	msgbox ViridianCity_Text_OhOkayThen
	release
	end

ViridianCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_WomanRoadBlocked
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally
	release
	end

ViridianCity_EventScript_WomanRoadBlocked::
	msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet
	closemessage
	applymovement LOCALID_VIRIDIAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_DreamEaterTutor::
	goto EventScript_DreamEaterTutor
	end

ViridianCity_EventScript_RoadBlocked::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_WalkDown
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_WalkDown::
	walk_down
	step_end

ViridianCity_EventScript_TutorialTriggerLeft::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_TutorialTriggerRight::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_DoTutorialBattle::
	@ Kanto-Merge: Er haelt erst seine uebliche Ansprache, danach kommt die
	@ Frage. Sie sitzt hier statt in TutorialStart, weil der Kampf drei
	@ Einstiege hat - Ansprechen und zwei Lauftrigger.
	msgbox ViridianCity_Text_ShowYouHowToCatchMons
	msgbox ViridianCity_Text_AskShowCatching, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_TutorialDeclined
	closemessage
	special StartOldManTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	goto ViridianCity_EventScript_GiveRadio

ViridianCity_Text_CanCarryMonsAnywhere::
#if GERMAN
	.string "Diese Pokébälle an deinem Gürtel zeigen\n"
	.string "mir, dass du Pokémon besitzt!\p"
	.string "Es ist Klasse, dass man jederzeit\n"
	.string "Pokémon tragen und einsetzen kann,\l"
	.string "nicht wahr?$"
#else
	.string "Those POKé BALLS at your waist!\n"
	.string "You have POKéMON, don't you?\p"
	.string "It's great that you can carry and\n"
	.string "use POKéMON anytime, anywhere.$"
#endif

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
#if GERMAN
	.string "Diese Pokémon-Arena ist stets\n"
	.string "geschlossen!\p"
	.string "Ich frage mich, wer hier wohl der\n"
	.string "Arenaleiter sein mag?$"
#else
	.string "This POKéMON GYM is always closed.\p"
	.string "I wonder who the LEADER is?$"
#endif

ViridianCity_Text_ViridiansGymLeaderReturned::
#if GERMAN
	.string "Der Arenaleiter von Vertania City\n"
	.string "ist zurück!$"
#else
	.string "VIRIDIAN GYM's LEADER returned!$"
#endif

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
#if GERMAN
	.string "Möchtest du etwas über die zwei\n"
	.string "Raupen-Pokémon erfahren?$"
#else
	.string "You want to know about the two\n"
	.string "kinds of caterpillar POKéMON?$"
#endif

ViridianCity_Text_OhOkayThen::
#if GERMAN
	.string "O.K., alles klar!$"
#else
	.string "Oh, okay then!$"
#endif

ViridianCity_Text_ExplainCaterpieWeedle::
#if GERMAN
	.string "Raupy ist nicht giftig, aber Hornliu!\p"
	.string "Achte auf seinen Giftstachel!$"
#else
	.string "CATERPIE has no poison,\n"
	.string "but WEEDLE does.\p"
	.string "Watch that your POKéMON aren't\n"
	.string "stabbed by WEEDLE's POISON STING.$"
#endif

ViridianCity_Text_GrandpaHasntHadCoffeeYet::
#if GERMAN
	.string "Großvater!\n"
	.string "Sei nicht so gemein!\p"
	.string "Er hatte noch keinen Kaffee!!!$"
#else
	.string "Oh, Grandpa!\n"
	.string "Don't be so mean!\p"
	.string "I'm so sorry.\n"
	.string "He hasn't had his coffee yet.$"
#endif

ViridianCity_Text_GoShoppingInPewterOccasionally::
#if GERMAN
	.string "Wenn ich zum Einkaufen nach Marmoria\n"
	.string "City möchte, muss ich immer durch den\l"
	.string "Vertania-Wald gehen.$"
#else
	.string "I go shopping in PEWTER CITY\n"
	.string "occasionally.\p"
	.string "I have to take the winding trail in\n"
	.string "VIRIDIAN FOREST when I go.$"
#endif

ViridianCity_Text_ThisIsPrivateProperty::
#if GERMAN
	.string "Du kannst hier nicht durch!\p"
	.string "Das ist ein Privatgelände!$"
#else
	.string "I absolutely forbid you from\n"
	.string "going through here!\p"
	.string "This is private property!$"
#endif

ViridianCity_Text_ShowYouHowToCatchMons::
#if GERMAN
	.string "Nun, jetzt hatte ich meinen Kaffee und\n"
	.string "das ist alles, was ich brauche, um\l"
	.string "loszulegen!\l"
	.string "Hmm?\l"
	.string "Was ist das für eine rote Box?\p"
	.string "Ah, du arbeitest an einem Pokédex.\p"
	.string "Dann will ich dir einen Ratschlag\n"
	.string "geben.\p"
	.string "Der Pokédex wird mit jedem neu\n"
	.string "gefangenen Pokémon aktualisiert.\p"
	.string "… du weißt nicht, wie man Pokémon\n"
	.string "fängt?$"
#else
	.string "Well, now, I've had my coffee, and\n"
	.string "that's what I need to get going!\p"
	.string "Hm?\n"
	.string "What is that red box you have?\p"
	.string "Ah, so you're working on your\n"
	.string "POKéDEX.\p"
	.string "Then let me give you a word of\n"
	.string "advice.\p"
	.string "Whenever you catch a POKéMON,\n"
	.string "the POKéDEX automatically updates\l"
	.string "its data.\p"
	.string "…You don't know how to catch\n"
	.string "a POKéMON?\p"
	.string "I suppose I had better show you\n"
	.string "then!$"
#endif

ViridianCity_Text_ThatWasEducationalTakeThis::
#if GERMAN
	.string "So! Das war doch perfekter\n"
	.string "Anschauungsunterricht, oder?\p"
	.string "Und hier, nimm dies auch noch!$"
#else
	.string "There! Now tell me, that was\n"
	.string "educational, was it not?\p"
	.string "And here, take this, too.$"
#endif

ViridianCity_Text_WatchThatToLearnBasics::
#if GERMAN
	.string "Falls es etwas gibt, das du nicht\n"
	.string "verstehst, dann schau da rein!\l"
	.string "Dort erfährst du die Grundlagen über\l"
	.string "den Beruf eines Pokémon Trainers.$"
#else
	.string "If there's something you don't\n"
	.string "understand, watch that.\p"
	.string "It will teach you about the basics\n"
	.string "of being a POKéMON TRAINER.$"
#endif

ViridianCity_Text_WeakenMonsFirstToCatch::
#if GERMAN
	.string "Ahh, ich habe endlich meinen Kaffee\n"
	.string "bekommen!\l"
	.string "Aber er war zu stark. Jetzt habe ich\l"
	.string "Kopfschmerzen…\p"
	.string "Vervollständigst du zufällig einen\n"
	.string "Pokédex?\p"
	.string "Konzentriere dich zunächst darauf, das\n"
	.string "Pokémon zu schwächen, ehe du es fangen\l"
	.string "möchtest.$"
#else
	.string "Well, now, I've had my coffee, and\n"
	.string "that's what I need to get going!\p"
	.string "But I made it too strong.\n"
	.string "It gave me a headache…\p"
	.string "Incidentally, are you filling your\n"
	.string "POKéDEX?\p"
	.string "At first, focus on weakening the\n"
	.string "POKéMON before trying to catch it.$"
#endif

ViridianCity_Text_HowsTeachyTVHelping::
#if GERMAN
	.string "Ahh, ich habe endlich meinen Kaffee\n"
	.string "bekommen!\p"
	.string "Aber er war zu stark. Jetzt habe\n"
	.string "ich Kopfschmerzen…\p"
	.string "Hilft dir mein Lehrkanal?$"
#else
	.string "Well, now, I've had my coffee, and\n"
	.string "that's what I need to get going!\p"
	.string "But I made it too strong.\n"
	.string "It gave me a headache…\p"
	.string "Incidentally, is my old TEACHY TV\n"
	.string "helping you?$"
#endif

ViridianCity_Text_MyGrandsonOnTheShow::
#if GERMAN
	.string "Wahaha!\n"
	.string "Mein Enkel ist im Fernsehen!\p"
	.string "Da er den Unterricht leitet, musst du\n"
	.string "lernen.$"
#else
	.string "Wahaha!\n"
	.string "It's my grandson on the show!\p"
	.string "Since he's the one doing the\n"
	.string "teaching, you're bound to learn.$"
#endif

ViridianCity_Text_TooBusyForTeachyTV::
#if GERMAN
	.string "Hm… du hast keine Zeit, um den\n"
	.string "Lehrkanal anzuschauen…\l"
	.string "Zeit ist Geld und keines davon sollte\l"
	.string "man leichtsinnig verschwenden…$"
#else
	.string "Hm… You're too busy to not even\n"
	.string "have the time for TEACHY TV…\p"
	.string "Time is money, and neither should\n"
	.string "be ill spent…$"
#endif

ViridianCity_Text_CitySign::
#if GERMAN
	.string "Vertania City\n"
	.string "Das immergrüne Paradies!$"
#else
	.string "VIRIDIAN CITY \n"
	.string "The Eternally Green Paradise$"
#endif

ViridianCity_Text_CatchMonsForEasierBattles::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Fange Pokémon, um deine Sammlung\n"
	.string "zu erweitern!\p"
	.string "Je mehr du besitzt, desto leichter\n"
	.string "werden die Kämpfe!$"
#else
	.string "TRAINER TIPS\p"
	.string "Catch POKéMON and expand your\n"
	.string "collection.\p"
	.string "The more you have, the easier it\n"
	.string "is to battle.$"
#endif

ViridianCity_Text_MovesLimitedByPP::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Die Attacken der Pokémon werden durch\n"
	.string "ihre Angriffspunkte, AP, limitiert.\p"
	.string "Um die AP wieder aufzufüllen, musst du\n"
	.string "die Pokémon in ein Pokémon-Center\l"
	.string "bringen!$"
#else
	.string "TRAINER TIPS\p"
	.string "The battle moves of POKéMON are\n"
	.string "limited by their POWER POINTS, PP.\p"
	.string "To replenish PP, rest your tired\n"
	.string "POKéMON at a POKéMON CENTER.$"
#endif

ViridianCity_Text_GymSign::
#if GERMAN
	.string "Vertania City Pokémon-Arena$"
#else
	.string "VIRIDIAN CITY POKéMON GYM$"
#endif

ViridianCity_Text_GymDoorsAreLocked::
#if GERMAN
	.string "Die Türen der Arena sind\n"
	.string "verschlossen...$"
#else
	.string "VIRIDIAN GYM's doors are locked…$"
#endif

