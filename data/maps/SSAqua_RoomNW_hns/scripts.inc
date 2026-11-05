SSAqua_RoomNW_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomNW_OnTransition
	.byte 0

SSAqua_RoomNW_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 3, SSAqua_RoomNW_SetTrainerPos
    end

SSAqua_RoomNW_SetTrainerPos::
    setobjectxyperm 2, 2, 6
    setobjectxyperm 3, 4, 3
    end

SSAqua_RoomNW_EventScript_Stanly::
    lock
    faceplayer
    msgbox SSAqua_RoomNW_Text_SailorStanlySeen, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_STANLY_HNS, SSAqua_RoomNW_Text_SailorStanlyBeaten
	msgbox SSAqua_RoomNW_Text_SailorStanlyAfterBattle, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    delay 60
    playse SE_DOOR
    removeobject LOCALID_SSAQUA_SLEEPYSAILOR
    fadescreenswapbuffers FADE_FROM_BLACK
    setvar VAR_SSAQUA_STATE, 3
	release
	end

SSAqua_RoomNW_EventScript_Edward::
    trainerbattle_single TRAINER_EDWARD_HNS, SSAqua_RoomNW_Text_GentlemanEdwardSeen, SSAqua_RoomNW_Text_GentlemanEdwardBeaten
	msgbox SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNW_EventScript_Corey::
    trainerbattle_single TRAINER_COREY_HNS, SSAqua_RoomNW_Text_BurglarCoreySeen, SSAqua_RoomNW_Text_BurglarCoreyBeaten
	msgbox SSAqua_RoomNW_Text_BurglarCoreyAfterBattle, MSGBOX_AUTOCLOSE
	end


SSAqua_RoomNW_Text_SailorStanlySeen:
#if GERMAN
	.string "Ja, ich bin ein Matrose, echt!\p"
	.string "Ich habe nicht getrödelt!\p"
	.string "Die Kabine war frei, also hab ich kurz\n"
	.string "ein Nickerchen gemacht!\p"
	.string "Ach, egal! Lass uns kämpfen!$"
#else
	.string "Yeah, I'm a sailor, all right.\p"
	.string "I wasn't goofing off!\p"
	.string "This cabin was vacant, so I\n"
	.string "just took a quick nap!\p"
	.string "Ah, forget it! Let's battle!$"
#endif

SSAqua_RoomNW_Text_SailorStanlyBeaten:
#if GERMAN
	.string "Sorry! Ganz meine Schuld!$"
#else
	.string "Sorry! It's all my fault!$"
#endif

SSAqua_RoomNW_Text_SailorStanlyAfterBattle:
#if GERMAN
	.string "Als Matrose muss ich hart arbeiten.\p"
	.string "Das ist echt anstrengend!$"
#else
	.string "Being a sailor, I have to do\n"
	.string "physical labor. It's exhausting!$"
#endif

SSAqua_RoomNW_Text_GentlemanEdwardSeen:
#if GERMAN
	.string "Oh nein! Ich habe etwas sehr Wichtiges\n"
	.string "verloren.$"
#else
	.string "Oh, no. I've lost something\n"
	.string "that's very important.$"
#endif

SSAqua_RoomNW_Text_GentlemanEdwardBeaten:
#if GERMAN
	.string "Ich… ich kann es nicht finden…$"
#else
	.string "I… I can't find it…$"
#endif

SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle:
#if GERMAN
	.string "Es bringt nichts, ich gebe auf.\n"
	.string "He, du da!\l"
	.string "Du musst nicht danach suchen.\l"
	.string "Vergiss es einfach!$"
#else
	.string "I give up. You don't have to\n"
	.string "look.\p"
	.string "Just forget about it!$"
#endif

SSAqua_RoomNW_Text_BurglarCoreySeen:
#if GERMAN
	.string "Juhu!\n"
	.string "Was für ein Glück!$"
#else
	.string "Yeehaw! Lucky!$"
#endif

SSAqua_RoomNW_Text_BurglarCoreyBeaten:
#if GERMAN
	.string "Pech gehabt!\n"
	.string "Ich habe verloren!$"
#else
	.string "How unlucky! I lost!$"
#endif

SSAqua_RoomNW_Text_BurglarCoreyAfterBattle:
#if GERMAN
	.string "Ich habe hier im Zimmer eine tolle Münze\n"
	.string "gefunden.\p"
	.string "Einer der vorherigen Gäste muss sie\n"
	.string "verloren haben…$"
#else
	.string "I found a pretty coin here.\p"
	.string "Someone must have lost it…$"
#endif
