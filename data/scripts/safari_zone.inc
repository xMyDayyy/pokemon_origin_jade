SafariZone_EventScript_OutOfBallsMidBattle::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKantoMidBattle
	setwarp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	end

SafariZone_EventScript_ExitKantoMidBattle::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	end

SafariZone_EventScript_Exit::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	warp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	waitstate
	end

SafariZone_EventScript_ExitKanto::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
#if GERMAN
	.string "Möchtest du die Safari-Zone jetzt\n"
	.string "verlassen?$"
#else
	.string "Would you like to exit the SAFARI\n"
	.string "ZONE right now?$"
#endif

SafariZone_Text_TimesUp:
#if GERMAN
	.string "Ding Dong! Die Zeit ist abgelaufen!\n"
	.string "Dein Safari-Spiel ist vorbei.$"
#else
	.string "Ding-dong! Time's up!\n"
	.string "Your SAFARI Game is over.$"
#endif

SafariZone_Text_OutOfBalls:
#if GERMAN
	.string "Du hast keine Safaribälle mehr.\n"
	.string "Dein Safari-Spiel ist vorbei.$"
#else
	.string "You've run out of SAFARI BALLS.\n"
	.string "Your SAFARI Game is over.$"
#endif

SafariZone_Text_PlacePokeblockOnFeeder:
#if GERMAN
	.string "Möchtest du einen {POKEBLOCK} in den\n"
	.string "{POKEBLOCK}Napf legen?$"
#else
	.string "Would you like to place a {POKEBLOCK}\n"
	.string "on the {POKEBLOCK} FEEDER?$"
#endif

SafariZone_Text_PokeblockStillHere:
#if GERMAN
	.string "Dein {STR_VAR_1} liegt immer hier.$"
#else
	.string "The {STR_VAR_1} you left\n"
	.string "before is still here.$"
#endif

SafariZone_Text_PokeblockWasPlaced:
#if GERMAN
	.string "{STR_VAR_1} wurde in den {POKEBLOCK}-\n"
	.string "Napf gelegt.$"
#else
	.string "The {STR_VAR_1} was placed\n"
	.string "on the {POKEBLOCK} FEEDER.$"
#endif

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
#if GERMAN
	.string "Willkommen in der Safari-Zone!\p"
	.string "Hier bekommst du viele Pokémon zu\n"
	.string "Gesicht, die sehr selten in der\l"
	.string "Hoenn-Region sind.\p"
	.string "Du kannst sie in ihrer ganzen Wildheit\n"
	.string "und ungezähmt in ihrer natürlichen\l"
	.string "Umgebung beobachten.\p"
	.string "Wir haben unsere Tore für die Pokémon-\n"
	.string "Trainer geöffnet.\p"
	.string "Fangt euch Pokémon. Und behaltet sie!\p"
	.string "Kommt und genießt die Welt der\n"
	.string "Safari-Zone!$"
#else
	.string "Welcome to the SAFARI ZONE!\p"
	.string "Here, you may witness many kinds of\n"
	.string "POKéMON rarely seen in this region.\p"
	.string "And, you'll see them in their wild,\n"
	.string "untamed state in natural habitats.\p"
	.string "What's more, we've thrown open the\n"
	.string "gates to POKéMON TRAINERS.\p"
	.string "You're encouraged to catch POKéMON\n"
	.string "for keeps!\p"
	.string "Come in and enjoy the SAFARI ZONE!$"
#endif

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
#if GERMAN
	.string "Willkommen in der Safari-Zone!\n"
	.string "Bist du zum ersten Mal hier?$"
#else
	.string "Welcome to the SAFARI ZONE!\n"
	.string "Is it your first time here?$"
#endif

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
#if GERMAN
	.string "Komm und genieße die Safari-Zone!$"
#else
	.string "Come in and enjoy the SAFARI ZONE!$"
#endif

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
#if GERMAN
	.string "Sobald du die Safari-Zone betrittst,\n"
	.string "stehen dir 30 Safaribälle zur\l"
	.string "Verfügung, um Pokémon zu fangen.\p"
	.string "Das Safari-Spiel ist vorbei, sobald du\n"
	.string "deine Safaribälle verbraucht oder 500\l"
	.string "Schritte gemacht hast.\p"
	.string "Komm und genieße die Safari-Zone!$"
#else
	.string "When you enter the SAFARI ZONE, you\n"
	.string "start with 30 SAFARI BALLS for\l"
	.string "catching POKéMON.\p"
	.string "The SAFARI Game is over when you run\n"
	.string "out of SAFARI BALLS, or when you've\l"
	.string "walked 500 steps.\p"
	.string "Come in and enjoy the SAFARI ZONE!$"
#endif

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
#if GERMAN
	.string "Willkommen in der Safari-Zone!\p"
	.string "Alles, was du für nur ¥500 fangen\n"
	.string "kannst! Möchtest du es probieren?$"
#else
	.string "Welcome to the SAFARI ZONE!\p"
	.string "All you can catch for just ¥500!\n"
	.string "Would you like to play a SAFARI Game?$"
#endif

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
#if GERMAN
	.string "Okay.\n"
	.string "Bitte beehre uns doch später einmal.$"
#else
	.string "Okay.\n"
	.string "Please play another time!$"
#endif

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
#if GERMAN
	.string "Du hast nicht genug Geld dabei.\n"
	.string "Tut mir Leid.$"
#else
	.string "You don't have enough money.\n"
	.string "Sorry.$"
#endif

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
#if GERMAN
	.string "Das macht dann ¥500, bitte.$"
#else
	.string "That will be ¥500, please.$"
#endif

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
#if GERMAN
	.string "Hier sind deine Safaribälle.$"
#else
	.string "Here are your SAFARI BALLS.$"
#endif

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
#if GERMAN
	.string "{PLAYER} erhält 30 Safaribälle.$"
#else
	.string "{PLAYER} received 30 SAFARI BALLS.$"
#endif

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
#if GERMAN
	.string "Wir geben dir Bescheid, wenn das Spiel\n"
	.string "vorbei ist.\p"
	.string "Bis dahin wünschen wir viel Spaß!\n"
	.string "Und auf geht’s in die Wildnis!$"
#else
	.string "We'll let you know when your game\n"
	.string "is over.\p"
	.string "So, until then, enjoy yourself, please!\n"
	.string "Off you go on your wild excursion!$"
#endif

Route121_SafariZoneEntrance_Text_PCIsFull:
#if GERMAN
	.string "Entschuldigung!\n"
	.string "Deine PC-Boxen sind voll.$"
#else
	.string "Excuse me!\n"
	.string "Your PC BOX is full.$"
#endif

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
#if GERMAN
	.string "Entschuldigung!\n"
	.string "Du besitzt keine {POKEBLOCK}Box.\p"
	.string "Dein Safari-Spiel wäre viel\n"
	.string "erfolgreicher, wenn du {POKEBLOCK}\l"
	.string "benutzen würdest.\p"
	.string "Bitte besorge dir doch eine {POKEBLOCK}Box.\p"
#if IS_HNS
	.string "Der Junge dort drüben hat vielleicht\n"
	.string "eine für dich.$"
#else
	.string "Vielleicht erhältst du in der\n"
	.string "Wettbewerbshalle von Seegrasulb City\l"
	.string "eine.$"
#endif
#else
	.string "Excuse me!\n"
	.string "You seem to be without a {POKEBLOCK} CASE.\p"
	.string "Your SAFARI Game will be much more\n"
	.string "fruitful if you use {POKEBLOCK}S.\p"
	.string "Please come back with a {POKEBLOCK} CASE.\p"
	.string "You may obtain a {POKEBLOCK} CASE from\n"
#if IS_HNS
	.string "that boy over there.$"
#else
	.string "the LILYCOVE CONTEST HALL.$"
#endif
#endif

SafariZone_South_Text_StillHaveTimeExit:
#if GERMAN
	.string "Du hast noch Zeit übrig. Möchtest du\n"
	.string "die Safari-Zone jetzt verlassen?$"
#else
	.string "You still have time left. Would you like\n"
	.string "to exit the SAFARI ZONE now?$"
#endif

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
#if GERMAN
	.string "Viel Vergnügen bei dem Rest deines\n"
	.string "wilden Abenteuers!$"
#else
	.string "Please enjoy the rest of your wild\n"
	.string "adventure!$"
#endif

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
#if GERMAN
	.string "Okay.\p"
	.string "Ich nehme die verbleibenden Safaribälle\n"
	.string "zurück.\p"
	.string "Vielen Dank für deine Teilnahme.\n"
	.string "Komm bald wieder!$"
#else
	.string "Okay.\p"
	.string "I'll take back your remaining SAFARI\n"
	.string "BALLS.\p"
	.string "Thank you for playing.\n"
	.string "We hope to see you again.$"
#endif

SafariZone_South_Text_GoodLuck:
#if GERMAN
	.string "Viel Glück!\p"
	.string "Wenn du irgendetwas brauchst, zögere\n"
	.string "nicht, mich anzusprechen!$"
#else
	.string "Good luck!\p"
	.string "If you need anything, don't hesitate\n"
	.string "to tell me, please!$"
#endif

SafariZone_South_Text_Boy:
#if GERMAN
	.string "Weißt du was?\p"
	.string "Wenn du einen {POKEBLOCK} in diese Kiste\n"
	.string "dort legst, werden Pokémon angelockt.$"
#else
	.string "Did you know?\p"
	.string "If you put a {POKEBLOCK} in that square box,\n"
	.string "POKéMON gather around.$"
#endif

SafariZone_South_Text_Man:
#if GERMAN
	.string "Ich wollte noch weiter hinein, aber\n"
	.string "ich habe mein Rad vergessen.\p"
	.string "Irgendetwas sagt mir, dass in den\n"
	.string "abgelegenen Gegenden seltene Pokémon\l"
	.string "leben.$"
#else
	.string "I want to keep going deeper, but I\n"
	.string "forgot to bring a BIKE.\p"
	.string "Something tells me that rare POKéMON\n"
	.string "live in the outlying areas.$"
#endif

SafariZone_Southwest_Text_Woman:
#if GERMAN
	.string "Manchmal, wenn ich einem Pokémon einen\n"
	.string "{POKEBLOCK} zuwerfe, ignoriert es das total.\p"
	.string "Ob Pokémon auch manche Dinge mögen\n"
	.string "und manche nicht? Wie wir Menschen?$"
#else
	.string "Sometimes, when I toss a {POKEBLOCK} at \n"
	.string "POKéMON, it gets ignored.\p"
	.string "Do POKéMON have likes and dislikes\n"
	.string "about what they eat?$"
#endif

SafariZone_Northwest_Text_Man:
#if GERMAN
	.string "Hechel… Keuch…\n"
	.string "Ich… bin hierher gekommen… aber…\p"
	.string "Ich bin erschöpft… Japs… Ich habe\n"
	.string "keine Energie, ein Pokémon zu fangen.$"
#else
	.string "Gasp… Gasp…\n"
	.string "I…made it out here…but…\p"
	.string "I'm exhausted… I don't have the\n"
	.string "energy to catch POKéMON…$"
#endif

SafariZone_North_Text_Fisherman:
#if GERMAN
	.string "Ich habe eine Mission. Ich will\n"
	.string "Wasser-Pokémon fangen, die es in Hoenn\l"
	.string "nicht gibt.\p"
	.string "Weißt du zufällig, wo hier der See ist?$"
#else
	.string "I'm on a mission to find WATER POKéMON\n"
	.string "you don't see in HOENN.\p"
	.string "Do you have any idea where the lake is?$"
#endif

SafariZone_North_Text_Man:
#if GERMAN
	.string "Ich will viele seltene Pokémon fangen\n"
	.string "und mit meinen Freunden tauschen.$"
#else
	.string "I'm going to catch a lot of rare POKéMON\n"
	.string "here and trade them with my friends!$"
#endif

SafariZone_South_Text_Youngster:
#if GERMAN
	.string "Ich habe einen {POKEBLOCK} in den {POKEBLOCK}-\n"
	.string "Napf gelegt. Er ist verschwunden.\p"
	.string "Ein Pokémon muss ihn gefuttert haben,\n"
	.string "ohne dass ich das gemerkt habe.$"
#else
	.string "I put a {POKEBLOCK} on the {POKEBLOCK} FEEDER.\n"
	.string "But it seems to have disappeared.\p"
	.string "I guess POKéMON must have eaten it\n"
	.string "without me noticing.$"
#endif

Route121_SafariZoneEntrance_Text_TrainerTip:
#if GERMAN
	.string "Tipp für Trainer in der Safari-Zone!\p"
	.string "Wirf Pokémon {POKEBLOCK} zu, dann ergreifen\n"
	.string "sie nicht so schnell die Flucht.$"
#else
	.string "SAFARI ZONE TRAINER TIP!\p"
	.string "Throw {POKEBLOCK}S at wild POKéMON to make\n"
	.string "them less likely to flee.$"
#endif

SafariZone_Southwest_Text_RestHouseSign:
#if GERMAN
	.string "Rasthaus\n"
	.string "“Erhole deine gemarterten Füße.”$"
#else
	.string "“Relieve your tired feet.”\n"
	.string "REST HOUSE$"
#endif

SafariZone_RestHouse_Text_Youngster:
#if GERMAN
	.string "Ich habe keine {POKEBLOCK}, aber ich habe\n"
	.string "trotzdem viele Pokémon gefangen.\p"
	.string "Du kannst deine Chancen erhöhen, indem\n"
	.string "du näher an das Pokémon herangehst,\l"
	.string "bevor du den Safariball wirfst.$"
#else
	.string "I don't have any {POKEBLOCK}S, but I caught\n"
	.string "a good number of POKéMON.\p"
	.string "You can improve your chances of making\n"
	.string "a catch by getting closer to them\l"
	.string "before throwing a SAFARI BALL.$"
#endif

SafariZone_RestHouse_Text_PsychicM:
#if GERMAN
	.string "Pokémon fliehen nicht so schnell, wenn\n"
	.string "man ihnen {POKEBLOCK} zuwirft.\p"
	.string "Pokémon, die von Natur aus nicht\n"
	.string "schnell fliehen, braucht man sie nicht\l"
	.string "unbedingt zuzuwerfen.$"
#else
	.string "If you use {POKEBLOCK}S, wild POKéMON won't\n"
	.string "be so quick to run away.\p"
	.string "It's not much use to give {POKEBLOCK}S to\n"
	.string "POKéMON that don't flee easily.$"
#endif

SafariZone_RestHouse_Text_FatMan:
#if GERMAN
	.string "Wird ein {POKEBLOCK} in den Napf gelegt,\n"
	.string "werden Pokémon angelockt.\p"
	.string "Ich glaube, Pokémon mit der gleichen\n"
	.string "Wesensart werden von ähnlichen\l"
	.string "{POKEBLOCK}n angezogen.$"
#else
	.string "If you put a {POKEBLOCK} on the FEEDER,\n"
	.string "POKéMON are attracted to it.\p"
	.string "I think POKéMON with the same sort of\n"
	.string "nature are drawn by a certain {POKEBLOCK}.$"
#endif

SafariZone_South_Text_AreaOffLimits1:
#if GERMAN
	.string "In diesem Gebiet finden Bauarbeiten\n"
	.string "statt. Zutritt verboten!$"
#else
	.string "This area is still under construction.\n"
	.string "It's off-limits, sorry!$"
#endif

SafariZone_Southeast_Text_ExpansionIsFinished:
#if GERMAN
	.string "Der Ausbau der Safari-Zone ist\n"
	.string "abgeschlossen.\p"
	.string "Wir hoffen, du genießt den Aufenthalt.$"
#else
	.string "The SAFARI ZONE's expansion project\n"
	.string "is finished now.\p"
	.string "We hope you will enjoy the new area.$"
#endif

SafariZone_South_Text_AreaOffLimits2:
#if GERMAN
	.string "In diesem Gebiet finden Bauarbeiten\n"
	.string "statt. Zutritt verboten!$"
#else
	.string "This area is still under construction.\n"
	.string "It's off-limits, sorry!$"
#endif

SafariZone_Southeast_Text_LittleGirl:
#if GERMAN
	.string "Wow! Huiii! Diese Pokémon habe ich noch\n"
	.string "nie vorher gesehen!$"
#else
	.string "Wow! Whee! I haven't seen any of\n"
	.string "these POKéMON before!$"
#endif

SafariZone_Southeast_Text_FatMan:
#if GERMAN
	.string "Die Pokémon in diesem Gebiet sind mir\n"
	.string "völlig unbekannt.\p"
	.string "Und ich darf diese seltenen Pokémon\n"
	.string "auch noch fangen! Ich kann mein Glück\l"
	.string "kaum fassen! Cool!$"
#else
	.string "The POKéMON in this area are all\n"
	.string "new to me.\p"
	.string "And I'm allowed to catch these rare\n"
	.string "POKéMON! Too cool!$"
#endif

SafariZone_Southeast_Text_RichBoy:
#if GERMAN
	.string "Die Pokémon in diesem Gebiet scheinen\n"
	.string "nicht aus Hoenn zu kommen.$"
#else
	.string "The POKéMON around here seem to be\n"
	.string "from somewhere other than HOENN.$"
#endif

SafariZone_Northeast_Text_Boy:
#if GERMAN
	.string "Ich habe nur noch wenige Safaribälle\n"
	.string "übrig.\p"
	.string "Mir fällt es schwer, mich zu\n"
	.string "entscheiden, welches Pokémon ich nun\l"
	.string "fangen soll.$"
#else
	.string "I only have a couple SAFARI BALLS left.\p"
	.string "I'm having a hard time trying to\n"
	.string "decide what I should catch.$"
#endif

SafariZone_Northeast_Text_Woman:
#if GERMAN
	.string "Ich habe gehört, man könne hier auf\n"
	.string "Pikachu treffen. Wo mag nur eins sein?$"
#else
	.string "I heard that you can see PIKACHU here.\n"
	.string "Where might one be?$"
#endif

SafariZone_Northeast_Text_Girl:
#if GERMAN
	.string "Schluchz heul!\n"
	.string "Ich schaffe es nicht, eines zu fangen.\p"
	.string "Ich habe mein Geld umsonst ausgegeben,\n"
	.string "wenn ich nichts fange.$"
#else
	.string "Oh, boo!\n"
	.string "I can't seem to catch anything!\p"
	.string "I'll end up wasting the admission\n"
	.string "price if I don't catch something!$"
#endif
