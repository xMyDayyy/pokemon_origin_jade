CeladonCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
#if GERMAN
	.string "Oh, {PLAYER}.\n"
	.string "Ist der Brunnen heute nicht traumhaft?\p"
	.string "Wenn du erneut kämpfen willst,\n"
	.string "triff mich im Kampf-Dojo.$"
#else
    .string "Oh, {PLAYER}.\n"
	.string "Isn't the fountain lovely today?\p"
	.string "If you wish for another battle,\n"
	.string "I'll be at the FIGHTING DOJO.$"
#endif

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_EventScript_Item_Recycle::
    finditem ITEM_TM_RECYCLE
    end

CeladonCity_Text_Fisher:
#if GERMAN
	.string "Dieses Quappo ist mein Partner.\p"
	.string "Ich frage mich, ob es sich jemals\n"
	.string "in ein Frosch-Pokémon entwickeln wird.$"
#else
	.string "This POLIWRATH is my partner.\p"
	.string "I wonder if it'll ever evolve\n"
	.string "into a frog POKéMON.$"
#endif

CeladonCity_Text_Poliwrath:
#if GERMAN
	.string "Quappo: Quappo! Quappo!$"
#else
	.string "POLIWRATH: Croak!$"
#endif

CeladonCity_Text_Teacher1:
#if GERMAN
	.string "Ich habe wieder an den Spielautomaten\n"
	.string "verloren…\p"
	.string "Wir Mädchen spielen jetzt auch an den\n"
	.string "Slots.\p"
	.string "Du solltest sie auch ausprobieren.$"
#else
	.string "I lost at the slot machines again…\p"
	.string "We girls also play the slots now.\p"
	.string "You should check them out too.$"
#endif

CeladonCity_Text_Gramps1:
#if GERMAN
	.string "Sleima tauchen in letzter Zeit auf.\p"
	.string "Siehst du den Teich vor dem Haus?\n"
	.string "Dort leben jetzt Sleima.\p"
	.string "Woher sie kommen? Das ist ein ernstes\n"
	.string "Problem…$"
#else
	.string "GRIMER have been appearing lately.\p"
	.string "See that pond out in front of the\n"
	.string "house? GRIMER live there now.\p"
	.string "Where did they come from? This is\n"
	.string "a serious problem…$"
#endif

CeladonCity_Text_Gramps2:
#if GERMAN
	.string "Nihihi! Diese Arena ist großartig!\n"
	.string "Nur Mädchen dürfen hier rein!$"
#else
	.string "Nihihi! This GYM is great! Only\n"
	.string "girls are allowed here!$"
#endif

CeladonCity_Text_Youngster1:
#if GERMAN
	.string "Willst du ein Geheimnis wissen?\p"
	.string "Die Prismania-Villa hat eine versteckte\n"
	.string "Hintertür.$"
#else
	.string "Want to know a secret?\p"
	.string "CELADON MANSION has a hidden back\n"
	.string "door.$"
#endif

CeladonCity_Text_Youngster2:
#if GERMAN
	.string "Sie veranstalten einen\n"
	.string "Wettess-Wettbewerb im Restaurant.\p"
	.string "Allein beim Zuschauen fühle ich mich\n"
	.string "vollgefressen…$"
#else
	.string "They're holding an eating contest\n"
	.string "at the restaurant.\p"
	.string "Just watching them go at it makes\n"
	.string "me feel bloated…$"
#endif

CeladonCity_Text_Teacher2:
#if GERMAN
	.string "Das Prismania-Kaufhaus hat die\n"
	.string "größte und beste Auswahl an Waren.\p"
	.string "Wenn du es dort nicht bekommst,\n"
	.string "bekommst du es nirgendwo.\p"
	.string "Puh… Ich klinge wie eine Verkäuferin.$"
#else
	.string "CELADON DEPT.STORE has the biggest\n"
	.string "and best selection of merchandise.\p"
	.string "If you can't get it there, you\n"
	.string "can't get it anywhere.\p"
	.string "Gee… I sound like a sales clerk.$"
#endif

CeladonCity_Text_Lass:
#if GERMAN
	.string "Beim Gehen den Boden anzusehen\n"
	.string "wurde mir schwindelig.$"
#else
	.string "Looking at the ground while I was\n"
	.string "walking made me dizzy.$"
#endif

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
#if GERMAN
	.string "Prismania City\p"
	.string "Die Stadt der Regenbogen-Träume$"
#else
	.string "CELADON CITY\p"
	.string "The City of Rainbow Dreams$"
#endif

CeladonGym_Text_Sign:
#if GERMAN
	.string "Prismania City Pokémon-Arena Leiterin:\n"
	.string "Erika Die Prinzessin mit dem grünen\l"
	.string "Daumen$"
#else
	.string "CELADON CITY POKéMON GYM LEADER:\n"
	.string "ERIKA\p"
	.string "The Nature-Loving Princess$"
#endif

CeladonCity_Text_DeptStoreSign:
#if GERMAN
	.string "Im Einkaufszentrum von Prismania City\n"
	.string "Findest du Alles, was dein Herz begehrt!$"
#else
	.string "Find What You Need at CELADON\n"
	.string "DEPT.STORE!$"
#endif

CeladonCity_Text_MansionSign:
#if GERMAN
	.string "Prismania-Villa$"
#else
	.string "CELADON MANSION$"
#endif

CeladonCity_Text_GameCornerSign:
#if GERMAN
	.string "Der Spielplatz für Jedermann\n"
	.string "Spielhalle Prismania City$"
#else
	.string "The Playground for Everybody--\n"
	.string "CELADON GAME CORNER$"
#endif

CeladonCity_Text_TrainerTips:
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Der Megablock schützt Pokémon vor\n"
	.string "Spezialattacken wie z.B.\l"
	.string "Feuer und Wasser.\p"
	.string "Hol dir deine Items im\n"
	.string "Einkaufszentrum Prismania City!$"
#else
	.string "TRAINER TIPS\p"
	.string "GUARD SPEC. protects POKéMON\n"
	.string "against SPECIAL attacks such as\l"
	.string "FLAMETHROWER and SURF.\p"
	.string "Get your items at CELADON DEPT.\n"
	.string "STORE!$"
#endif
