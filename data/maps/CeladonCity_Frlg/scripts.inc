CeladonCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	.byte 0

CeladonCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CELADON_CITY
	end

CeladonCity_EventScript_LittleGirl::
	msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	lock
	msgbox CeladonCity_Text_GymIsGreatFullOfWomen
	release
	end

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_EventScript_SoftboiledTutor::
	goto EventScript_SoftboiledTutor
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_CELADON_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_CELADON_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_EventScript_SilphCoScientist::
	msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
	end

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_ERIKA, 0
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_Text_GotMyKoffingInCinnabar::
#if GERMAN
	.string "Ich habe Smogon auf der Zinnoberinsel\n"
	.string "gefangen!\p"
	.string "Es ist nett, doch wenn man es\n"
	.string "ärgert, atmet es Gift aus!$"
#else
	.string "I got my KOFFING in CINNABAR.\p"
	.string "It's usually nice, but it breathes\n"
	.string "poison when it's angry.$"
#endif

CeladonCity_Text_GymIsGreatFullOfWomen::
#if GERMAN
	.string "Hehe!\n"
	.string "Diese Arena ist voller Frauen...$"
#else
	.string "Heheh! This GYM is great!\n"
	.string "It's full of women!$"
#endif

CeladonCity_Text_GameCornerIsBadForCitysImage::
#if GERMAN
	.string "Die Spielhalle schadet dem Ruf\n"
	.string "unserer Stadt!$"
#else
	.string "CELADON takes pride in its efforts\n"
	.string "to keep the city beautiful.\p"
	.string "That's why the new GAME CORNER is\n"
	.string "bad for our city's image.$"
#endif

CeladonCity_Text_BlewItAllAtSlots::
#if GERMAN
	.string "Mist!\n"
	.string "Ich habe alles verspielt!\p"
	.string "Hätte ich doch meine Münzen\n"
	.string "rechtzeitig gegen einen Preis\l"
	.string "eingetauscht!$"
#else
	.string "Moan…\n"
	.string "I blew it all at the slots!\p"
	.string "I knew I should have cashed in my\n"
	.string "COINS for prizes!$"
#endif

CeladonCity_Text_MyTrustedPalPoliwrath::
#if GERMAN
	.string "Quappo ist mein bester Freund!\p"
	.string "Es entwickelte sich, als ich einem\n"
	.string "Quaputzi einen Wasserstein gab!$"
#else
	.string "This is my trusted pal, POLIWRATH.\p"
	.string "It evolved from a POLIWHIRL when\n"
	.string "I used a WATER STONE.$"
#endif

CeladonCity_Text_Poliwrath::
#if GERMAN
	.string "Quappo: Quappo! Quappo!$"
#else
	.string "POLIWRATH: Ribi ribit!$"
#endif

CeladonCity_Text_GetLostOrIllPunchYou::
#if GERMAN
	.string "Was starrst du mich so an?$"
#else
	.string "What are you staring at?\n"
	.string "Get lost, or I'll punch you.$"
#endif

CeladonCity_Text_KeepOutOfTeamRocketsWay::
#if GERMAN
	.string "Halte dich aus Team Rockets\n"
	.string "Angelegenheiten heraus!$"
#else
	.string "Keep out of TEAM ROCKET's way!$"
#endif

CeladonCity_Text_ExplainXAccuracyDireHit::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "X-Treffer erhöht die Genauigkeit\n"
	.string "von Attacken!\p"
	.string "Angriffplus erhöht die\n"
	.string "Wahrscheinlichkeit, einen Volltreffer\l"
	.string "zu landen!\p"
	.string "Diese Items kannst du im\n"
	.string "Einkaufszentrum von Prismania City\l"
	.string "kaufen!$"
#else
	.string "TRAINER TIPS\p"
	.string "X ACCURACY boosts the accuracy of\n"
	.string "techniques.\p"
	.string "DIRE HIT jacks up the likelihood\n"
	.string "of critical hits.\p"
	.string "Get your items at the CELADON\n"
	.string "DEPT. STORE!$"
#endif

CeladonCity_Text_CitySign::
#if GERMAN
	.string "Prismania City\n"
	.string "Die Stadt der Regenbogen-Träume!$"
#else
	.string "CELADON CITY\n"
	.string "The City of Rainbow Dreams$"
#endif

CeladonCity_Text_GymSign::
#if GERMAN
	.string "Prismania City Pokémon-Arena Leiterin:\n"
	.string "Erika Die Prinzessin mit dem grünen\l"
	.string "Daumen$"
#else
	.string "CELADON CITY POKéMON GYM\n"
	.string "LEADER: ERIKA\l"
	.string "The Nature-Loving Princess!$"
#endif

CeladonCity_Text_MansionSign::
#if GERMAN
	.string "Prismania-Villa$"
#else
	.string "CELADON MANSION$"
#endif

CeladonCity_Text_DeptStoreSign::
#if GERMAN
	.string "Das Prismania Einkaufszentrum\n"
	.string "Wo Träume wahr werden$"
#else
	.string "Find what you need at the\n"
	.string "CELADON DEPT. STORE!$"
#endif

CeladonCity_Text_GuardSpecProtectsFromStatus::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Megablock schützt Pokémon fünf Runden\n"
	.string "lang vor Statusveränderungen im Kampf.\p"
	.string "Besorgen kannst du dir dieses\n"
	.string "hilfreiche Item im Prismania\l"
	.string "Einkaufszentrum!$"
#else
	.string "TRAINER TIPS\p"
	.string "GUARD SPEC. protects POKéMON\n"
	.string "from status-reduction moves during\l"
	.string "battle.\p"
	.string "Get your items at the\n"
	.string "CELADON DEPT. STORE!$"
#endif

CeladonCity_Text_PrizeExchangeSign::
#if GERMAN
	.string "Wechselstube\n"
	.string "Tausche Münzen gegen Preise!$"
#else
	.string "COINS exchanged for prizes!\n"
	.string "PRIZE EXCHANGE$"
#endif

CeladonCity_Text_GameCornerSign::
#if GERMAN
	.string "Rocket Spielhalle\n"
	.string "Ein Spielplatz für Erwachsene!$"
#else
	.string "ROCKET GAME CORNER\n"
	.string "The playground for grown-ups!$"
#endif

CeladonCity_Text_ScaldedTongueOnTea::
#if GERMAN
	.string "Argh, oh…\n"
	.string "Ich habe meine Zunge verbrüht!\p"
	.string "Die nette, alte Dame in der Villa\n"
	.string "gab mir Tee.\p"
	.string "Aber er war kochend heiß!\n"
	.string "Ich muss ihn erst abkühlen, ehe ich ihn\l"
	.string "trinke!$"
#else
	.string "Aaaagh, ow…\n"
	.string "I scalded my tongue!\p"
	.string "This nice old lady in the MANSION\n"
	.string "gave me some TEA.\p"
	.string "But it was boiling hot!\n"
	.string "Gotta cool it to drink it.$"
#endif

Text_SoftboiledTeach::
#if GERMAN
	.string "Hallo!\p"
	.string "Ich kenne dich vom Sehen! Aber ich\n"
	.string "hatte bisher keine Zeit, dich\l"
	.string "anzusprechen!\p"
	.string "Glück hat uns scheinbar zusammen-\n"
	.string "gebracht.\p"
	.string "Das möchte ich feiern, indem ich einem\n"
	.string "deiner Pokémon Weichei beibringe.$"
#else
	.string "Hello, there!\p"
	.string "I've seen you about, but I never\n"
	.string "had a chance to chat.\p"
	.string "It must be good luck that brought\n"
	.string "us together finally.\p"
	.string "I'd like to celebrate by teaching\n"
	.string "you the move SOFTBOILED.$"
#endif

Text_SoftboiledDeclined::
#if GERMAN
	.string "Ich habe immer ein Auge auf dich\n"
	.string "geworfen.\p"
	.string "Hoffentlich können wir erneut\n"
	.string "plaudern.$"
#else
	.string "I'll always be keeping an eye out\n"
	.string "for you.\p"
	.string "I hope we can chat again.$"
#endif

Text_SoftboiledWhichMon::
#if GERMAN
	.string "Also, wie heißt das Pokémon, das Weichei\n"
	.string "erlernen soll?$"
#else
	.string "So, who's the POKéMON that gets\n"
	.string "the chance to learn SOFTBOILED?$"
#endif

Text_SoftboiledTaught::
#if GERMAN
	.string "Ich wünsche dir viel Glück!$"
#else
	.string "I wish you the best of luck!$"
#endif

CeladonCity_Text_SomeoneStoleSilphScope::
#if GERMAN
	.string "Oh, was soll ich tun…\p"
	.string "Jemand hat unser Silph Scope\n"
	.string "gestohlen.\p"
	.string "Der Dieb kam aus dieser Richtung.\n"
	.string "Da bin ich mir sicher.\p"
	.string "Aber ich habe ihn verloren!\n"
	.string "Wo ist er nur hin?$"
#else
	.string "Oh, what am I to do…\p"
	.string "Someone stole our SILPH SCOPE.\p"
	.string "The thief came running this way,\n"
	.string "I'm sure of it.\p"
	.string "But I lost sight of him!\n"
	.string "Where'd he go?$"
#endif

