GoldenrodCity_Gym_hns_MapScripts::
	.byte 0
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE_HNS, GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET_HNS, GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA_HNS, GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA_HNS, GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1_HNS, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setvar VAR_0x8004, 2
	special SetJohtoBadge
	setflag FLAG_BADGE03_GET
	@ Whitney: Johto-Orden 3. Die Flag oben teilt sich Johto mit Kanto und
	@ ist nach der Kanto-Liga laengst gesetzt - gezaehlt wird in VAR_JOHTO_BADGES.
	setvar VAR_0x8004, 2
	special SetJohtoBadge
	@ Der Orden ist zugleich die Befugnis fuer Staerke - siehe
	@ src/johto_permits.c. Die Ordensflags teilt sich Johto mit Kanto.
	setvar VAR_0x8004, PERM_STRENGTH
	special SetJohtoPermit
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ATTRACT
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
#if GERMAN
	.string "Dukatia City Pokémon-Arena$"
#else
	.string "GOLDENROD POKéMON GYM$"
#endif

GoldenrodCity_Gym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon-Arena von Dukatia City\p"
	.string "Leiterin: Bianka\n"
	.string "Anerkannte Trainer:\p"
	.string "{PLAYER}$"
#else
	.string "GOLDENROD TOWN POKéMON GYM\p"
	.string "WHITNEY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif

GoldenrodCity_Gym_Text_WhitneyBefore:
#if GERMAN
	.string "Hi! Ich bin Bianka!\p"
	.string "Alle mochten Pokémon, also hab\n"
	.string "ich auch angefangen!\p"
	.string "Pokémon sind so niedlich!\p"
	.string "Willst du kämpfen? Pass auf, ich bin\n"
	.string "echt gut!$"
#else
    .string "Hi! I'm WHITNEY!\p"
    .string "Everyone was into POKéMON, so I got\n"
    .string "into it too!\p"
    .string "POKéMON are super-cute!\p"
    .string "You want to battle? I'm warning\n"
    .string "you- I'm good!$"
#endif

GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
#if GERMAN
	.string "Schnief…\p"
	.string "…Waaaaah! Du bist gemein!\p"
	.string "Sei nicht so ernst! Du…\n"
	.string "du Kind, du!$"
#else
    .string "Sob…\p"
    .string "…Waaaaaaah! You're mean!\p"
    .string "You shouldn't be so serious! You…\n"
    .string "you child, you!$"
#endif

GoldenrodCity_Gym_Text_WhitneyYouMeanie:
#if GERMAN
	.string "Waaaaah!\p"
	.string "Waaaaah!\p"
	.string "…Schnief, hic… …Du Gemeiner!$"
#else
    .string "Waaaaah!\p"
    .string "Waaaaah!\p"
    .string "…Snivel, hic… …You meanie!$"
#endif

GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
#if GERMAN
	.string "…Schnief…\p"
	.string "Was? Was willst du? Einen Orden?\p"
	.string "Ach, richtig. Hab ich vergessen.\n"
	.string "Hier ist der Basisorden.$"
#else
    .string "…Sniff…\p"
    .string "What? What do you want? A BADGE?\p"
    .string "Oh, right. I forgot. Here's\n"
    .string "PLAINBADGE.$"
#endif

GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
#if GERMAN
	.string "{PLAYER} erhält den Basisorden!$"
#else
    .string "{PLAYER} received PLAINBADGE.$"
#endif

GoldenrodCity_Gym_Text_WhitneyPlainBadge:
#if GERMAN
	.string "Basisorden lässt dein Pokémon Stärke\n"
	.string "auch außerhalb des Kampfes einsetzen.\p"
	.string "Erhöht auch die Verteidigung!\p"
	.string "Hier, nimm ihn auch!$"
#else
    .string "PLAINBADGE lets your POKéMON use\n"
    .string "STRENGTH outside of battle.\p"
    .string "It also boosts your POKéMON's\n"
	.string "DEFENSE.\p"
    .string "Oh, you can have this too!$"
#endif

GoldenrodCity_Gym_Text_WhitneyAttract:
#if GERMAN
	.string "Das ist Anziehung! Es nutzt den\n"
	.string "Charme eines Pokémon voll aus.\p"
	.string "Perfekt für niedliche Pokémon,\n"
	.string "so wie meine!$"
#else
    .string "It's ATTRACT! It makes full use of a\n"
    .string "POKéMON's charm.\p"
    .string "Isn't it just perfect for a cutie\n"
    .string "like me?$"
#endif

GoldenrodCity_Gym_Text_WhitneyGoodCry:
#if GERMAN
	.string "Ah, das war ein gutes Weinen!$"
#else
    .string "Ah, that was a good cry!$"
#endif

GoldenrodCity_Gym_Text_WhitneyRematch:
#if GERMAN
	.string "Hi! Du bist es!\p"
	.string "Wow, Johto Champion jetzt?\p"
	.string "Du bist echt stark!\p"
	.string "Ich will sehen, wie stark du bist.\p"
	.string "Willst du ein Rematch mit mir?$"
#else
    .string "Hi! It's you!\p"
    .string "Wow, JOHTO CHAMPION now?\p"
    .string "You really are amazing!\p"
    .string "I want to see how strong you are.\p"
    .string "Want to have a rematch with me?$"
#endif

GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
#if GERMAN
	.string "Waaaaah!\p"
	.string "Waaaaah!\p"
	.string "…Schnief, hic… …Du Gemeiner!$"
#else
    .string "Waaaaah!\p"
    .string "Waaaaah!\p"
    .string "…Snivel, hic… …You meanie!$"
#endif

GoldenrodCity_Gym_Text_LassCarrieSeen:
#if GERMAN
	.string "Lass dich nicht von dem niedlichen\n"
	.string "Aussehen meiner Pokémon täuschen.\p"
	.string "Sie können dich schlagen!$"
#else
    .string "Don't let my POKéMON's cute looks\n"
    .string "fool you.\p"
    .string "They can whip you!$"
#endif

GoldenrodCity_Gym_Text_LassCarrieBeaten:
#if GERMAN
	.string "Oh… ich dachte du wärst schwach…$"
#else
    .string "Darn… I thought you were weak…$"
#endif

GoldenrodCity_Gym_Text_LassCarrieAfter:
#if GERMAN
	.string "Denkt mein Pokémon, ich bin süß?$"
#else
    .string "Do my POKéMON think I'm cute?$"
#endif

GoldenrodCity_Gym_Text_LassBridgetSeen:
#if GERMAN
	.string "Ich mag niedliche Pokémon lieber als\n"
	.string "starke!\p"
	.string "Aber die Pokémon in meinem Team sind\n"
	.string "beides - niedlich und stark!$"
#else
    .string "I like cute POKéMON better than\n"
    .string "strong POKéMON.\p"
    .string "But I have strong and cute POKéMON!$"
#endif

GoldenrodCity_Gym_Text_LassBridgetBeaten:
#if GERMAN
	.string "Oh, nein, nein, nein!$"
#else
    .string "Oh, no, no, no!$"
#endif

GoldenrodCity_Gym_Text_LassBridgetAfter:
#if GERMAN
	.string "Ich versuche Bianka zu schlagen…\n"
	.string "Es ist deprimierend.\p"
	.string "Aber egal! Wenn ich verliere, versuche\n"
	.string "ich es beim nächsten Mal einfach\l"
	.string "härter!$"
#else
    .string "I'm trying to beat WHITNEY, but…\n"
    .string "It's depressing.\p"
    .string "I'm okay! If I lose, I'll just try\n"
    .string "harder next time!$"
#endif

GoldenrodCity_Gym_Text_BridgetWhitneyCries:
#if GERMAN
	.string "Oh je, jetzt hast du Bianka zum Weinen\n"
	.string "gebracht…\p"
	.string "Aber keine Sorge, irgendwann gibt sie\n"
	.string "schon wieder Ruhe. Sie weint immer, wenn\l"
	.string "sie verliert.$"
#else
    .string "Oh, no. You made WHITNEY cry.\p"
    .string "It's OK. She'll stop soon. She\n"
    .string "always cries when she loses.$"
#endif

GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
#if GERMAN
	.string "Oh, du musst wohl noch etwas wachsen!\n"
	.string "Du gefällst mir… Aber deshalb werde ich\l"
	.string "es dir nicht einfacher machen!$"
#else
    .string "Oh, you are a cute little trainer!\p"
    .string "I like you, but I won't hold back!$"
#endif

GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
#if GERMAN
	.string "Mal sehen… Ups, schon vorbei?$"
#else
    .string "Let's see… Oops, it's over?$"
#endif

GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
#if GERMAN
	.string "Wow, du musst gut sein, wenn du es\n"
	.string "schaffst, mich zu schlagen. Mach weiter\l"
	.string "so!$"
#else
    .string "Wow, you must be good to beat me!\n"
    .string "Keep it up!$"
#endif

GoldenrodCity_Gym_Text_BeautySamanthaSeen:
#if GERMAN
	.string "Schlag ordentlich zu, sonst werde ich\n"
	.string "es tun!$"
#else
    .string "Give it your best shot, or I'll take\n"
    .string "you down!$"
#endif

GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
#if GERMAN
	.string "Oh nein! Mauzi, bitte verzeih mir!$"
#else
    .string "No! Oh, MEOWTH, I'm so sorry!$"
#endif

GoldenrodCity_Gym_Text_BeautySamanthaAfter:
#if GERMAN
	.string "Ich habe Mauzi die unterschiedlichsten\n"
	.string "Attacken beigebracht, damit es gegen\l"
	.string "jedes Pokémon besteht.$"
#else
    .string "I taught MEOWTH moves for taking on\n"
    .string "any type…$"
#endif

GoldenrodCity_Gym_Text_GymGuide:
#if GERMAN
	.string "Yo! Champ in spe!\p"
	.string "In dieser Arena wartet Bianka,\n"
	.string "die Meisterin der Normal-Pokémon.\p"
	.string "Nimm dich vor ihrem niedlichen\n"
	.string "Team in Acht.\p"
	.string "Einige Pokémon hier haben zudem\n"
	.string "den neu entdeckten Typ Fee.\p"
	.string "Brauchst du ein Kampf- oder\n"
	.string "Gift-Pokémon, sieh auf Route 34 nach.$"
#else
    .string "Yo! CHAMP in making!\p"
    .string "This GYM is home to WHITNEY, the\n"
    .string "master of NORMAL-type POKéMON.\p"
    .string "Be cautious of her cute team.\p"
    .string "Some of the POKéMON in this gym\n"
    .string "have the newly discovered FAIRY\l"
    .string "type as well.\p"
    .string "Check ROUTE 34 if you need a\n"
    .string "FIGHTING-type or POISON-type.$"
#endif

GoldenrodCity_Gym_Text_GymGuideWin:
#if GERMAN
	.string "Du hast gewonnen?\n"
	.string "Toll! Ich war damit beschäftigt, die\l"
	.string "hübschen Damen hier zu bewundern.$"
#else
    .string "You won? Great! I was busy admiring\n"
    .string "the ladies here.$"
#endif

