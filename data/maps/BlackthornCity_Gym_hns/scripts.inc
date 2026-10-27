BlackthornCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
	.byte 0

BlackthornGym_OnLoad::
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
	end

BlackthornGym_MapScript_Var1::
	call BlackthornGym_MapScript_BuildBridge1
	end

BlackthornGym_MapScript_Var2::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	end

BlackthornGym_MapScript_Var3::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	end

BlackthornGym_MapScript_Var4::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	call BlackthornGym_MapScript_BuildBridge4
	end

BlackthornGym_TriggerBridge1::
	call BlackthornGym_MapScript_BuildBridge1
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 1
	end

BlackthornGym_MapScript_BuildBridge1::
	setmetatile 19, 47, 0x35A, FALSE
	setmetatile 19, 48, 0x35A, FALSE
	setmetatile 19, 49, 0x35A, FALSE
	setmetatile 19, 50, 0x35A, FALSE
	setmetatile 19, 51, 0x35A, FALSE
	setmetatile 19, 52, 0x35A, FALSE
	setmetatile 19, 53, 0x35A, FALSE
	setmetatile 19, 54, 0x35A, FALSE
	setmetatile 20, 47, 0x35A, FALSE
	setmetatile 20, 48, 0x35A, FALSE
	setmetatile 20, 49, 0x35A, FALSE
	setmetatile 20, 50, 0x35A, FALSE
	setmetatile 20, 51, 0x35A, FALSE
	setmetatile 20, 52, 0x35A, FALSE
	setmetatile 20, 53, 0x35A, FALSE
	setmetatile 20, 54, 0x35A, FALSE
	setmetatile 21, 47, 0x35A, FALSE
	setmetatile 21, 48, 0x35A, FALSE
	setmetatile 21, 49, 0x35A, FALSE
	setmetatile 21, 50, 0x35A, FALSE
	setmetatile 21, 51, 0x35A, FALSE
	setmetatile 21, 52, 0x35A, FALSE
	setmetatile 21, 53, 0x35A, FALSE
	setmetatile 21, 54, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge2::
	call BlackthornGym_MapScript_BuildBridge2
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 2
	end

BlackthornGym_MapScript_BuildBridge2::
	setmetatile 17, 35, 0x35A, FALSE
	setmetatile 17, 36, 0x35A, FALSE
	setmetatile 17, 37, 0x35A, FALSE
	setmetatile 17, 38, 0x35A, FALSE
	setmetatile 17, 39, 0x35A, FALSE
	setmetatile 17, 40, 0x35A, FALSE
	setmetatile 18, 35, 0x35A, FALSE
	setmetatile 18, 36, 0x35A, FALSE
	setmetatile 18, 37, 0x35A, FALSE
	setmetatile 18, 38, 0x35A, FALSE
	setmetatile 18, 39, 0x35A, FALSE
	setmetatile 18, 40, 0x35A, FALSE
	setmetatile 19, 35, 0x35A, FALSE
	setmetatile 19, 36, 0x35A, FALSE
	setmetatile 19, 37, 0x35A, FALSE
	setmetatile 19, 38, 0x35A, FALSE
	setmetatile 19, 39, 0x35A, FALSE
	setmetatile 19, 40, 0x35A, FALSE
	setmetatile 20, 32, 0x359, FALSE
	setmetatile 21, 32, 0x359, FALSE
	setmetatile 22, 32, 0x359, FALSE
	setmetatile 20, 35, 0x361, TRUE
	setmetatile 21, 35, 0x361, TRUE
	setmetatile 22, 35, 0x361, TRUE
	setmetatile 20, 33, 0x35A, FALSE
	setmetatile 20, 34, 0x35A, FALSE
	setmetatile 21, 33, 0x35A, FALSE
	setmetatile 21, 34, 0x35A, FALSE
	setmetatile 22, 33, 0x35A, FALSE
	setmetatile 22, 34, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge3::
	call BlackthornGym_MapScript_BuildBridge3
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 3
	end

BlackthornGym_MapScript_BuildBridge3::
	setmetatile 17, 26, 0x359, FALSE
	setmetatile 18, 26, 0x359, FALSE
	setmetatile 19, 26, 0x359, FALSE
	setmetatile 20, 26, 0x359, FALSE
	setmetatile 21, 26, 0x359, FALSE
	setmetatile 22, 26, 0x359, FALSE
	setmetatile 23, 26, 0x359, FALSE

	setmetatile 17, 29, 0x361, TRUE
	setmetatile 18, 29, 0x361, TRUE
	setmetatile 19, 29, 0x361, TRUE
	setmetatile 20, 29, 0x361, TRUE
	setmetatile 21, 29, 0x361, TRUE
	setmetatile 22, 29, 0x361, TRUE
	setmetatile 23, 29, 0x361, TRUE

	setmetatile 17, 27, 0x35A, FALSE
	setmetatile 17, 28, 0x35A, FALSE
	setmetatile 18, 27, 0x35A, FALSE
	setmetatile 18, 28, 0x35A, FALSE
	setmetatile 19, 27, 0x35A, FALSE
	setmetatile 19, 28, 0x35A, FALSE
	setmetatile 20, 27, 0x35A, FALSE
	setmetatile 20, 28, 0x35A, FALSE
	setmetatile 21, 27, 0x35A, FALSE
	setmetatile 21, 28, 0x35A, FALSE
	setmetatile 22, 27, 0x35A, FALSE
	setmetatile 22, 28, 0x35A, FALSE
	setmetatile 23, 27, 0x35A, FALSE
	setmetatile 23, 28, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge4::
	call BlackthornGym_MapScript_BuildBridge4
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 4
	end

BlackthornGym_MapScript_BuildBridge4::
	setmetatile 19, 11, 0x35A, FALSE
	setmetatile 19, 12, 0x35A, FALSE
	setmetatile 19, 13, 0x35A, FALSE
	setmetatile 19, 14, 0x35A, FALSE
	setmetatile 19, 15, 0x35A, FALSE
	setmetatile 20, 11, 0x35A, FALSE
	setmetatile 20, 12, 0x35A, FALSE
	setmetatile 20, 13, 0x35A, FALSE
	setmetatile 20, 14, 0x35A, FALSE
	setmetatile 20, 15, 0x35A, FALSE
	setmetatile 21, 11, 0x35A, FALSE
	setmetatile 21, 12, 0x35A, FALSE
	setmetatile 21, 13, 0x35A, FALSE
	setmetatile 21, 14, 0x35A, FALSE
	setmetatile 21, 15, 0x35A, FALSE
	return


BlackthornGym_EventScript_Cody::
	trainerbattle_single TRAINER_CODY_HNS, BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Fran::
	trainerbattle_single TRAINER_FRAN_HNS, BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL_HNS, BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_HNS, BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_HNS, BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
	end


BlackthornGym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_IS_JOHTO_CHAMPION, BlackthornGym_EventScript_ClairRematch
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_1_HNS, BlackthornGym_Text_ClairWinText
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers_hns
	setvar VAR_BLACKTHORN_CITY_STATE, 2
	closemessage
	release
	end

BlackthornGym_EventScript_ClairDuringChallenge::
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Clair_Defeated::
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_ClairAfterLeague::
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

@ Rematch after the Johto title, see docs/origin_jade/DECISIONS.md, D-032.
BlackthornGym_EventScript_ClairRematch::
	msgbox BlackthornGym_Text_ClairRematchText, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JohtoGym_EventScript_RematchDeclined
	closemessage
	trainerbattle_no_intro TRAINER_CLAIR_2_HNS, BlackthornGym_Text_ClairRematchDefeatText
	release
	end

BlackthornGym_Text_ClairIntroText:
#if GERMAN
	.string "Ich bin Sandra.\p"
	.string "Die beste Drachenmeisterin der Welt.\p"
	.string "Ich bestehe sogar gegen die Top Vier\n"
	.string "der Pokémon Liga.\p"
	.string "Willst du immer noch gegen mich\n"
	.string "antreten?\p"
	.string "…Gut. Auf geht’s!\p"
	.string "Da ich eine Arenaleiterin bin,\n"
	.string "werde ich mich nicht zurückhalten!$"
#else
    .string "I am CLAIR.\p"
    .string "The world's best dragon master.\p"
    .string "I can hold my own against even the\n"
    .string "POKéMON LEAGUE's ELITE FOUR.\p"
    .string "Do you still want to take me on?\p"
    .string "…Fine. Let's do it!\p"
    .string "As a GYM LEADER, I will use my full\n"
    .string "power against any opponent!$"
#endif

BlackthornGym_Text_ClairWinText:
#if GERMAN
	.string "Ich soll verloren haben?\p"
	.string "Ich will das einfach nicht glauben. Das\n"
	.string "muss ein Irrtum sein…$"
#else
    .string "I lost?\p"
    .string "I don't believe it. There must be\n"
    .string "some mistake…$"
#endif

BlackthornGym_Text_ClairText_GoToDragonsDen:
#if GERMAN
	.string "Ich gestehe das nicht ein.\p"
	.string "Ich, Sandra, mag verloren haben, aber du\n"
	.string "bist noch nicht reif für die Pokémon\l"
	.string "Liga.\p"
	.string "Ich weiß. Stelle dich der Drachen-\n"
	.string "Trainer-Herausforderung.\p"
	.string "Hinter dieser Arena liegt die\n"
	.string "Drachenhöhle.\p"
	.string "In deren Mitte ist ein Schrein.\n"
	.string "Gehe dorthin.\p"
	.string "Falls du dich dort beweisen kannst,\n"
	.string "werde ich dich als würdig befinden,\l"
	.string "einen Orden zu erhalten!$"
#else
    .string "I won't admit this.\p"
    .string "I may have lost, but you're still\n"
    .string "not ready for the POKéMON LEAGUE.\p"
    .string "I know. You should take the dragon-\n"
    .string "user challenge.\p"
    .string "Behind this GYM is a place called\n"
    .string "DRAGON'S DEN.\p"
    .string "There is a small shrine at its\n"
    .string "center. Go there.\p"
    .string "If you can prove that you've lost\n"
    .string "your lazy ideals, I will recognize\l"
    .string "you as a trainer worthy of a GYM\l"
    .string "BADGE!$"
#endif

BlackthornGym_Text_ClairText_TooMuchToExpect:
#if GERMAN
	.string "Was ist los?\p"
	.string "Erwarte ich etwa zu viel von dir?$"
#else
    .string "What's the matter?\p"
    .string "Is it too much to expect of you?$"
#endif

BlackthornGym_Text_ClairText_YouKeptMeWaiting:
#if GERMAN
	.string "Du hast mich warten lassen!\p"
	.string "Hier! Nimm dies!$"
#else
    .string "You've kept me waiting!\p"
    .string "Here! Take this!$"
#endif

BlackthornGym_Text_ClairText_DescribeTM:
#if GERMAN
	.string "Das enthält Drachenklaue.\p"
	.string "Du kannst selbst herausfinden,\n"
	.string "wie es funktioniert.$"
#else
    .string "That contains DRAGON CLAW.\p"
    .string "You can figure out what it does.$"
#endif

BlackthornGym_Text_ClairText_League:
#if GERMAN
	.string "Was ist los?\p"
	.string "Gehst du nicht zur Pokémon Liga?\p"
	.string "Kennst du den Weg nicht?\p"
	.string "Gehe von hier nach Neuborkia.\p"
	.string "Surfe dann nach Osten. Der Weg\n"
	.string "wird dann sehr beschwerlich.\p"
	.string "Wage es nicht, in der Pokémon\n"
	.string "Liga zu verlieren!\p"
	.string "Das würde meine Niederlage gegen\n"
	.string "dich noch schlimmer machen!\p"
	.string "Gib dein Bestes!$"
#else
    .string "What's the matter?\p"
    .string "Aren't you headed to the POKéMON\n"
    .string "LEAGUE?\p"
    .string "Don't you know where it is?\p"
    .string "From here, go to NEW BARK TOWN.\p"
    .string "Then SURF east. The route there is\n"
    .string "very tough.\p"
    .string "Don't you dare lose at the POKéMON\n"
    .string "LEAGUE!\p"
    .string "If you do, I'll feel even worse\n"
    .string "about having lost to you!\p"
    .string "Give it everything you've got.$"
#endif

BlackthornGym_Text_ClairAfterLeague:
#if GERMAN
	.string "Du hast es geschafft, huh?\p"
	.string "Du bist jetzt der Johto-Champ.$"
#else
    .string "You did it, huh?\p"
    .string "You are now the JOHTO CHAMP.$"
#endif

BlackthornGym_Text_ClairRematchText:
#if GERMAN
	.string "Du hast es also geschafft.\p"
	.string "Du bist jetzt Johto-Champion.\p"
	.string "Du hast deine Stärke bewiesen.\n"
	.string "Kannst du mich erneut besiegen?\p"
	.string "Als Drachenmeisterin werde ich mich\n"
	.string "nicht zurückhalten.\p"
	.string "Dieses Mal nicht.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
    .string "You did it, huh?\p"
    .string "You are now the JOHTO CHAMP.\p"
    .string "You've proven your strength but can\n"
    .string "you handle me again?\p"
    .string "As a Dragon Master, I won't hold\n"
    .string "back.\p"
    .string "Not this time.\p"
    .string "Want to have a rematch with me?$"
#endif

BlackthornGym_Text_ClairRematchDefeatText:
#if GERMAN
	.string "Ich habe verloren?\p"
	.string "Wieder?\p"
	.string "Ich glaube es nicht. Das muss\n"
	.string "ein Fehler sein…$"
#else
    .string "I lost?\p"
    .string "Again?\p"
    .string "I don't believe it. There must be\n"
    .string "some mistake…$"
#endif

BlackthornGym_Text_CooltrainermCodySeenText:
#if GERMAN
	.string "Ich habe gerade meine ersten\n"
	.string "Drachen-Pokémon bekommen!$"
#else
    .string "I just got access to use DRAGON-\n"
    .string "type POKéMON!$"
#endif

BlackthornGym_Text_CooltrainermCodyBeatenText:
#if GERMAN
	.string "Mist! Hätte ich bloß ein Dragoran!$"
#else
    .string "Rats! If only I had a DRAGONITE!$"
#endif

BlackthornGym_Text_CooltrainermCodyAfterBattleText:
#if GERMAN
	.string "Mitgliedern des Drachen-Clans wird erst\n"
	.string "erlaubt, Drachen zu verwenden, wenn\l"
	.string "unser Meister es erlaubt hat.$"
#else
    .string "Members of our dragon-user clan\n"
    .string "can use dragon POKéMON only after\l"
    .string "our MASTER allows it.$"
#endif

BlackthornGym_Text_CooltrainerfFranSeenText:
#if GERMAN
	.string "Ich kann einen unbekannten Trainer\n"
	.string "nicht an mir vorbeilassen!\p"
	.string "Sandra wäre sehr wütend!$"
#else
    .string "I can't allow a nameless trainer\n"
    .string "past me!\p"
    .string "CLAIR would be livid if I did!$"
#endif

BlackthornGym_Text_CooltrainerfFranBeatenText:
#if GERMAN
	.string "Awww… ich hab verloren…$"
#else
    .string "Awww… I lost…$"
#endif

BlackthornGym_Text_CooltrainerfFranAfterBattleText:
#if GERMAN
	.string "Uh-oh… Sandra wird sauer sein…$"
#else
    .string "Uh-oh… CLAIR is going to be mad…$"
#endif

BlackthornGym_Text_CooltrainermPaulSeenText:
#if GERMAN
	.string "Ist das dein erster Kampf gegen\n"
	.string "Drachen-Pokémon? Dann pass mal auf!$"
#else
    .string "Your first battle against dragons?\p"
    .string "I'll show you how tough they are!$"
#endif

BlackthornGym_Text_CooltrainermPaulBeatenText:
#if GERMAN
	.string "Mein Drachen-Pokémon hat verloren?$"
#else
    .string "My dragon POKéMON lost?$"
#endif

BlackthornGym_Text_CooltrainermPaulAfterBattleText:
#if GERMAN
	.string "Siegfried sagte dir, dass er dich noch\n"
	.string "einmal sehen will?\p"
	.string "Das kann nicht sein!$"
#else
    .string "LANCE told you that he'd like to\n"
    .string "see you again?\p"
    .string "Not a chance!$"
#endif

BlackthornGym_Text_CooltrainermMikeSeenText:
#if GERMAN
	.string "Die Chance gegen dich zu verlieren?\n"
	.string "Nicht mal ein Prozent!$"
#else
    .string "My chance of losing? Not even one\n"
    .string "percent!$"
#endif

BlackthornGym_Text_CooltrainermMikeBeatenText:
#if GERMAN
	.string "Hmmm… eigenartig.$"
#else
    .string "That's odd.$"
#endif

BlackthornGym_Text_CooltrainermMikeAfterBattleText:
#if GERMAN
	.string "Dann kenne ich ja jetzt meine\n"
	.string "Schwachstellen. Danke für den Hinweis!$"
#else
    .string "I know my short-comings now.\p"
    .string "Thanks for showing me!$"
#endif

BlackthornGym_Text_CooltrainerfLolaSeenText:
#if GERMAN
	.string "Drachen sind ehrwürdige Pokémon. Sie\n"
	.string "sind voller Lebensenergie.\p"
	.string "Wenn du es nicht ernst meinst, dann\n"
	.string "wirst du sie nicht besiegen können.$"
#else
    .string "Dragons are sacred POKéMON.\p"
    .string "They are full of life energy.\p"
    .string "If you're not serious, you won't\n"
    .string "be able to beat them.$"
#endif

BlackthornGym_Text_CooltrainerfLolaBeatenText:
#if GERMAN
	.string "He! Das war gar nicht so schlecht.$"
#else
    .string "Way to go!$"
#endif

BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
#if GERMAN
	.string "Übrigens - Drachen sind schwach gegen\n"
	.string "Drachen-Attacken.$"
#else
    .string "Dragons are weak against DRAGON-\n"
    .string "type moves.$"
#endif

BlackthornGym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_GymGuy2
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_GymGuy2::
	@ Johto badge 8 (Clair)
	setvar VAR_0x8004, 7
	special CheckJohtoBadge
	goto_if_eq VAR_RESULT, TRUE, BlackthornGym_EventScript_GymGuy3
	msgbox BlackthornGym_Text_GuideGotoDragonsDen, MSGBOX_DEFAULT
	release
	end

BlackthornGym_EventScript_GymGuy3::
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
	release
	end

BlackthornGym_Text_GuideText:
#if GERMAN
	.string "Yo! Champ in spe!\p"
	.string "Es war eine lange Reise, aber bald sind\n"
	.string "wir da! Zähle auf mich!\p"
	.string "Während Sandra zum Drachenmeister\n"
	.string "Siegfried aufsieht, hat sie es doch\l"
	.string "geschafft, ihre eigene Identität zu\l"
	.string "entwickeln, mit Drachen aus dem Wasser.\p"
	.string "Drachen sind eigentlich schwach gegen\n"
	.string "Eis-Attacken, aber du wirst Drachen-\l"
	.string "oder Feen-Attacken benötigen, wenn du\l"
	.string "gewinnen willst.\p"
	.string "Du schaffst das!$"
#else
    .string "Yo! CHAMP in making!\p"
    .string "It's been a long journey, but we\n"
    .string "are almost done! Count on me!\p"
    .string "While CLAIR looks up to the Dragon\n"
    .string "Master, LANCE, she's managed to\l"
    .string "create her own identity with a\l"
    .string "team consisting of dragons from\l"
    .string "the sea.\p"
    .string "Dragons are supposed to be\n"
    .string "weak against ICE-type moves,\l"
    .string "but you'll need some DRAGON-type\l"
	.string "or FAIRY-type moves of your own if\l"
    .string "you want to win.$"
    .string "You got this!$"
#endif

BlackthornGym_Text_GuideGotoDragonsDen:
#if GERMAN
	.string "Du warst super gegen Sandra!\p"
	.string "Sie ist leider keine gute Verliererin.\p"
	.string "Schätze, du musst zur Drachenhöhle,\n"
	.string "wenn du den Orden bekommen willst!$"
#else
	.string "You were great to beat CLAIR!\p"
    .string "She can be a bit of a sore loser,\n"
	.string "though\p"
    .string "Sounds like you need to head to the\n"
    .string "DRAGON'S DEN if you want that GYM BADGE!$"
#endif

BlackthornGym_Text_GuideWinText:
#if GERMAN
	.string "Gegen Sandra zu gewinnen ist\n"
	.string "eine Meisterleistung!\p"
	.string "Alles, was dir nun bevorsteht, ist die\n"
	.string "Pokémon Liga und Pokémon-Champion zu\l"
	.string "werden!$"
#else
    .string "You were great to beat CLAIR!\p"
    .string "All that's left is the POKéMON\n"
    .string "LEAGUE challenge.\p"
    .string "You're on the way to becoming the\n"
    .string "POKéMON CHAMPION!$"
#endif


BlackthornGym_EventScript_Statue::
	lock
	setvar VAR_0x8004, 7
	special CheckJohtoBadge
	goto_if_eq VAR_RESULT, TRUE, BlackthornGym_EventScript_Statue2
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Statue2::
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_GymStatue:
#if GERMAN
	.string "Pokémon-Arena von Ebenholz City$"
#else
	.string "BLACKTHORN CITY POKéMON GYM$"
#endif

BlackthornGym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon-Arena von Ebenholz City\p"
	.string "Leiterin: Sandra\n"
	.string "Anerkannte Trainer:\p"
	.string "{PLAYER}$"
#else
	.string "BLACKTHORN CITY POKéMON GYM\p"
	.string "CLAIR'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif
