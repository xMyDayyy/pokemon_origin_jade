MtMoon_Cave_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtMoon_Cave_MapScript_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_Cave_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMoon_Cave_OnTransition:
	callnative SetTimeBasedEncounters
	end


MtMoon_Cave_MapScript_OnFrame::
	map_script_2 VAR_PEWTER_CITY_STATE, 0, MtMoon_Cave_EventScript_Silver
	map_script_2 VAR_PEWTER_CITY_STATE, 1, MtMoon_Cave_EventScript_Silver
	.2byte 0

MtMoon_Cave_EventScript_Sign::
	msgbox MtMoon_Cave_Text_Sign, MSGBOX_SIGN
	end

MtMoon_Cave_EventScript_Silver::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	playse SE_PIN
	applymovement2 LOCALID_MTMOON_SILVER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement2 LOCALID_MTMOON_SILVER MtMoon_Cave_Movement_WalkToPlayer
	applymovement2 OBJ_EVENT_ID_PLAYER Common_Movement_WalkRight1
	waitmovement LOCALID_MTMOON_SILVER
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MtMoon_Cave_Text_Rival_Before, MSGBOX_DEFAULT
	goto_if_eq VAR_JOHTO_STARTER_MON, 0, MtMoon_Cave_EventScript_Silver_Battle_Cyndaquil
	goto_if_eq VAR_JOHTO_STARTER_MON, 1, MtMoon_Cave_EventScript_Silver_Battle_Totodile
	goto_if_eq VAR_JOHTO_STARTER_MON, 2, MtMoon_Cave_EventScript_Silver_Battle_Chikorita
	release
	end

MtMoon_Cave_EventScript_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_6_HNS, MtMoon_Cave_Text_Rival_Win
	goto MtMoon_Cave_EventScript_SilverAfterBattle

MtMoon_Cave_EventScript_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_6_HNS, MtMoon_Cave_Text_Rival_Win
	goto MtMoon_Cave_EventScript_SilverAfterBattle

MtMoon_Cave_EventScript_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_6_HNS, MtMoon_Cave_Text_Rival_Win
	goto MtMoon_Cave_EventScript_SilverAfterBattle

MtMoon_Cave_EventScript_SilverAfterBattle::
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox MtMoon_Cave_Text_Rival_After, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_MTMOON_SILVER, MtMoon_Cave_Movement_SilverLeave
	waitmovement 0
	removeobject LOCALID_MTMOON_SILVER
	setflag FLAG_HIDE_MTMOON_SILVER
	clearflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
	setvar VAR_PEWTER_CITY_STATE, 2
	fadedefaultbgm
	release
	end

MtMoon_Cave_Movement_WalkToPlayer:
	walk_left
	walk_left
	walk_left
	step_end

MtMoon_Cave_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

MtMoon_Cave_Text_Rival_Before:
#if GERMAN
	.string "… … …\p"
	.string "Es ist schon lange her, {PLAYER}.\p"
	.string "…Seit ich gegen dich verlor, mache ich\n"
	.string "mir Gedanken, was meinen Pokémon noch\l"
	.string "fehlt…\p"
	.string "Nun, wir haben eine Antwort gefunden.\p"
	.string "{PLAYER}, wir beweisen es dir!$"
#else
	.string "..................................\p"
	.string "It's been a while, {PLAYER}.\p"
	.string "…Since I lost to you, I thought about\n"
	.string "what I was lacking with my POKéMON…\p"
	.string "And we came up with an answer.\p"
	.string "{PLAYER}, now we'll show you!$"
#endif

MtMoon_Cave_Text_Rival_Win:
#if GERMAN
	.string "..................................\p"
	.string "Ich dachte ich hätte meine Pokémon so\n"
	.string "gut es irgendwie geht trainiert, zur\l"
	.string "perfektion…\p"
	.string "…Immer noch nicht genug…$"
#else
	.string "..................................\p"
	.string "I thought I raised my POKéMON to be the\n"
	.string "best they could be…\p"
	.string "…But it still wasn't enough…$"
#endif

MtMoon_Cave_Text_Rival_After:
#if GERMAN
	.string "… … …\p"
	.string "…Du hast mich fair besiegt.\p"
	.string "Das muss ich dir lassen. Wir werden uns\n"
	.string "wiedersehen.\p"
	.string "Ich werde der beste PokémonTrainer\n"
	.string "aller Zeiten sein.\p"
	.string "Und sie werden mir dabei helfen.\p"
	.string "…Hör mal, {PLAYER}.\p"
	.string "Eines Tages werde ich es dir bewei-\n"
	.string "sen. Dann besiege ich dich.$"
#else
	.string "..................................\p"
	.string "…You won, fair and square.\p"
	.string "I admit it. But this isn't the end.\p"
	.string "I'm going to be the greatest POKéMON\n"
	.string "trainer ever.\p"
	.string "Because these guys are behind me.\p"
	.string "…Listen, {PLAYER}.\p"
	.string "One of these days I'm going to prove\n"
	.string "how good I am by beating you.$"
#endif

MtMoon_Cave_Text_Rival_Loss:
#if GERMAN
	.string "… … …\p"
	.string "Ich habe meine Schuld bei dir\n"
	.string "abgegolten.\p"
	.string "Mit meinen Pokémon werde ich den Champ\n"
	.string "besiegen und weltbester Trainer\l"
	.string "werden.$"
#else
	.string "..................................\p"
	.string "I've repaid my debt to you.\p"
	.string "With my POKéMON, I'm going to beat the\n"
	.string "CHAMPION and become the world's greatest\n"
	.string "trainer.$"
#endif

MtMoon_Cave_Text_Sign:
#if GERMAN
	.string "Mondberg Vorplatz ->$"
#else
	.string "MT MOON SQUARE ->$"
#endif
