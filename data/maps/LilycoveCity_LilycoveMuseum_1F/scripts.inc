LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_1F_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_MUSEUM_1F_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MUSEUM_1F_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
#if GERMAN
	.string "Willkommen im Museum von\n"
	.string "Seegrasulb City.\p"
	.string "Bitte nimm dir die Zeit, unsere Sammlung\n"
	.string "wunderbarer Kunstwerke zum Thema\l"
	.string "Pokémon zu betrachten.$"
#else
	.string "Welcome to LILYCOVE MUSEUM.\p"
	.string "Please take the time to enjoy our\n"
	.string "collection of fantastic artwork\l"
	.string "featuring POKéMON.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
#if GERMAN
	.string "Ich bin der Kurator dieses Museums der\n"
	.string "schönen Künste.\p"
	.string "Es freut mich immer wieder, junge\n"
	.string "Menschen wie dich im Museum zu treffen.\p"
	.string "Hast du dir schon unsere Gemäldesamm-\n"
	.string "lung angesehen?$"
#else
	.string "I'm the CURATOR of this MUSEUM of\n"
	.string "fine arts.\p"
	.string "It's heartening to see someone so\n"
	.string "young as you in our MUSEUM.\p"
	.string "Have you viewed our collection of\n"
	.string "paintings already?$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
#if GERMAN
	.string "Ah, dann möchte ich dich nicht länger\n"
	.string "aufhalten. Bitte, nimm dir Zeit.$"
#else
	.string "Ah, then let me not disturb you.\n"
	.string "Please, do take your time.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
#if GERMAN
	.string "Oh? Ich glaube, du bist ein Pokémon-\n"
	.string "Trainer.\p"
	.string "Bist du auch an Gemälden interessiert?$"
#else
	.string "Oh? I do believe that you seem to\n"
	.string "be a POKéMON TRAINER.\p"
	.string "Have you an interest in paintings,\n"
	.string "too?$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
#if GERMAN
	.string "Ich verstehe…\p"
	.string "Ich fühle mich geehrt, dass du uns\n"
	.string "trotzdem besuchst.$"
#else
	.string "I see…\p"
	.string "I'm honored that you would visit\n"
	.string "us in spite of that.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
#if GERMAN
	.string "Ah, exzellent!\n"
	.string "Du magst Gemälde!\p"
	.string "Dann möchte ich dir gerne etwas\n"
	.string "zeigen.$"
#else
	.string "Ah, excellent!\n"
	.string "You do like paintings!\p"
	.string "Then, may I ask you to come with me?$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
#if GERMAN
	.string "Dies ist ein sehr altes Gemälde.\n"
	.string "Die Farbe blättert hier und da schon ab.$"
#else
	.string "It's a very old painting.\n"
	.string "The paint is peeling here and there.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
#if GERMAN
	.string "Eine merkwürdige Landschaft mit\n"
	.string "bizarren und fantastischen Details.$"
#else
	.string "It's an odd landscape with bizarre\n"
	.string "and fantastic scenery.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
#if GERMAN
	.string "Das Bildnis einer hübschen, lächelnden\n"
	.string "Frau mit einem Pokémon auf dem Schoß.$"
#else
	.string "It's a painting of a beautiful, smiling\n"
	.string "woman with a POKéMON on her lap.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
#if GERMAN
	.string "Das Bild eines legendären Pokémon aus\n"
	.string "längst vergangener Zeit.\p"
	.string "Der Künstler hat dies aus der\n"
	.string "Vorstellung heraus gemalt.$"
#else
	.string "It's a painting of a legendary POKéMON\n"
	.string "from long ago.\p"
	.string "The artist painted this from\n"
	.string "imagination.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
#if GERMAN
	.string "Pflanzen-Pokémon, die sich im\n"
	.string "Wind wiegen.\p"
	.string "Es scheint, als genießen sie das zarte\n"
	.string "Streicheln des Windes.$"
#else
	.string "It's a painting of GRASS POKéMON\n"
	.string "swaying in a breeze.\p"
	.string "They appear to be enjoying the wind's\n"
	.string "gentle caress.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
#if GERMAN
	.string "Beeren. Sie sehen äußerst delikat aus.\p"
	.string "Das Bild kann einen hungrig machen!$"
#else
	.string "It's a delicious-looking painting\n"
	.string "of BERRIES.\p"
	.string "This painting could make you hungry!$"
#endif

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
#if GERMAN
	.string "Ein Replikat einer berühmten Skulptur.\p"
	.string "Es zeigt ein antikes Vogel-Pokémon.$"
#else
	.string "It's a replica of a famous sculpture.\p"
	.string "It depicts an ancient BIRD POKéMON.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
#if GERMAN
	.string "Ein großer Pokéball, aus schwarzem\n"
	.string "Stein gehauen.\p"
	.string "In früheren Zeiten wurde er zu\n"
	.string "Festlichkeiten ausgestellt.$"
#else
	.string "It's a big POKé BALL carved from\n"
	.string "a black stone.\p"
	.string "It was apparently used in festivals\n"
	.string "in the olden days.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
#if GERMAN
	.string "Eine große Steintafel, auf der Pokémon\n"
	.string "und eng gesetzte, kleine Schrift-\l"
	.string "zeichen einer alten, unverständlichen\l"
	.string "Sprache eingraviert sind.$"
#else
	.string "It's a huge stone tablet inscribed\n"
	.string "with POKéMON and dense text in the\l"
	.string "small characters of an ancient,\l"
	.string "unreadable language.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
#if GERMAN
	.string "Hmmm…\n"
	.string "Was für großartige Werke…$"
#else
	.string "Hmmm…\n"
	.string "What works of great magnificence…$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
#if GERMAN
	.string "Die Kämpfe mit Pokémon machen schon\n"
	.string "Spaß, das gebe ich zu.\p"
	.string "Aber man darf darüber nicht seine Liebe\n"
	.string "zu den schönen Künsten vergessen.$"
#else
	.string "Battling with POKéMON is fun,\n"
	.string "I'll grant you that.\p"
	.string "But one mustn't forget our love for\n"
	.string "the fine arts.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
#if GERMAN
	.string "Dieses Kunstmuseum… Hier bekommst du\n"
	.string "viele fantastische Gemälde zu sehen.\p"
	.string "Und der Kurator ist einfach wunderbar.\p"
	.string "Unter Künstlern wie mir ist dieses\n"
	.string "Museum einfach eine Inspiration.$"
#else
	.string "This ART MUSEUM… Well, you could\n"
	.string "see many fantastic paintings.\p"
	.string "And the CURATOR is a wonderful person.\p"
	.string "Among artists like myself, this MUSEUM\n"
	.string "is an inspiration.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
#if GERMAN
	.string "Diese Frau ist hübsch!\n"
	.string "Genau wie meine Mama!$"
#else
	.string "This lady is pretty!\n"
	.string "She's like Mommy!$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
#if GERMAN
	.string "Dieses Pokémon ist anbetungswürdig!\n"
	.string "Genau wie unser kleiner Sohn!$"
#else
	.string "This POKéMON is adorable!\n"
	.string "Just like our little boy!$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
#if GERMAN
	.string "Ich habe gehört, dass das Kunstmuseum\n"
	.string "einige neue Gemälde erhalten hat.\p"
	.string "Die will ich mir natürlich sofort\n"
	.string "anschauen.\p"
	.string "Befinden sich die neuen Gemälde im\n"
	.string "zweiten Stockwerk?$"
#else
	.string "I'd heard that this ART MUSEUM got\n"
	.string "in some new paintings.\p"
	.string "So, naturally I hurried over.\p"
	.string "Are the new paintings up on\n"
	.string "the second floor?$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
#if GERMAN
	.string "In letzter Zeit war der Kurator außer-\n"
	.string "gewöhnlich gut gelaunt.\p"
	.string "Ich wette, er hat etwas Tolles erlebt.\n"
	.string "Mit Sicherheit!$"
#else
	.string "Lately, the CURATOR has been\n"
	.string "unusually cheerful.\p"
	.string "I bet something good happened for him.\n"
	.string "Definitely.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
#if GERMAN
	.string "Ich will mir hier viele große Werke\n"
	.string "an- schauen und von ihnen lernen.\p"
	.string "Ich träume davon, eines Tages hier\n"
	.string "meine eigene Ausstellung zu haben.$"
#else
	.string "I aim to see many great paintings\n"
	.string "here and learn from them.\p"
	.string "I have this dream of one day having\n"
	.string "my artwork exhibited here.$"
#endif

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
#if GERMAN
	.string "Das Kunstmuseum ist zu einem\n"
	.string "beliebten Ziel für Touristen geworden.\p"
	.string "Das ist großartig für Seegrasulb City.\n"
	.string "Nein, großartig für die ganze\l"
	.string "Hoenn-Region!\p"
	.string "Ein einziger Trainer soll all die Gemälde\n"
	.string "im oberen Stockwerk beschafft haben.$"
#else
	.string "The ART MUSEUM has become a favorite\n"
	.string "tourist destination.\p"
	.string "It's great for LILYCOVE…\n"
	.string "No, great for the HOENN region!\p"
	.string "This is what I've heard--a lone TRAINER\n"
	.string "procured all the paintings upstairs.$"
#endif

