SaffronCity_FightingDojoVIP_hns_MapScripts::
	.byte 0

SaffronCity_FightingDojoVIP_EventScript_Nurse::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSAquaRooms_EventScript_Bed_PokecenterChallenge
	msgbox SaffronCity_FightingDojoVIP_Text_Nurse1, MSGBOX_NPC
	waitmessage
	fadescreen 0x1
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen 0x0
	msgbox SaffronCity_FightingDojoVIP_Text_Nurse2, MSGBOX_NPC
	waitmessage
	release
	end

SaffronCity_FightingDojoVIP_Text_Nurse1:
	.string "Hallo! Willkommen im Trainings-Dojo!\n"
	.string "Ich heile deine Pokémon.$"

SaffronCity_FightingDojoVIP_Text_Nurse2:
	.string "Komm bald wieder!$"


SaffronCity_FightingDojoVIP_EventScript_Declined::
	closemessage
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Falkner_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Falkner_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Falkner_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Falkner_Rematch::
	trainerbattle_no_intro TRAINER_FALKNER_2_HNS, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner_PostOBC::
	trainerbattle_no_intro TRAINER_FALKNER_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Bugsy_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Bugsy_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Bugsy_Rematch::
	trainerbattle_no_intro TRAINER_BUGSY_2_HNS, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy_PostOBC::
	trainerbattle_no_intro TRAINER_BUGSY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Whitney_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Whitney_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Whitney_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Whitney_Rematch::
	trainerbattle_no_intro TRAINER_WHITNEY_2_HNS, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney_PostOBC::
	trainerbattle_no_intro TRAINER_WHITNEY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Morty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Morty_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Morty_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Morty_Rematch::
	trainerbattle_no_intro TRAINER_MORTY_2_HNS, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty_PostOBC::
	trainerbattle_no_intro TRAINER_MORTY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Chuck_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Chuck_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Chuck_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Chuck_Rematch::
	trainerbattle_no_intro TRAINER_CHUCK_2_HNS, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck_PostOBC::
	trainerbattle_no_intro TRAINER_CHUCK_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Jasmine_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Jasmine_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Jasmine_Rematch::
	trainerbattle_no_intro TRAINER_JASMINE_2_HNS, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine_PostOBC::
	trainerbattle_no_intro TRAINER_JASMINE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Pryce_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Pryce_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Pryce_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Pryce_Rematch::
	trainerbattle_no_intro TRAINER_PRYCE_2_HNS, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce_PostOBC::
	trainerbattle_no_intro TRAINER_PRYCE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Clair_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Clair_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Clair_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Clair_Rematch::
	trainerbattle_no_intro TRAINER_CLAIR_2_HNS, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair_PostOBC::
	trainerbattle_no_intro TRAINER_CLAIR_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Brock_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Brock_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Brock_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Brock_Rematch::
	trainerbattle_no_intro TRAINER_BROCK_HNS, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock_PostOBC::
	trainerbattle_no_intro TRAINER_BROCK_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Misty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Misty_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Misty_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Misty_Rematch::
	trainerbattle_no_intro TRAINER_MISTY_HNS, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty_PostOBC::
	trainerbattle_no_intro TRAINER_MISTY_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Surge_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Surge_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Surge_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Surge_Rematch::
	trainerbattle_no_intro TRAINER_LTSURGE_HNS, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge_PostOBC::
	trainerbattle_no_intro TRAINER_LTSURGE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Erika_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Erika_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Erika_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Erika_Rematch::
	trainerbattle_no_intro TRAINER_ERIKA_HNS, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika_PostOBC::
	trainerbattle_no_intro TRAINER_ERIKA_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Janine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Janine_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Janine_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Janine_Rematch::
	trainerbattle_no_intro TRAINER_JANINE_HNS, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine_PostOBC::
	trainerbattle_no_intro TRAINER_JANINE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Sabrina_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Sabrina_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Sabrina_Rematch::
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina_PostOBC::
	trainerbattle_no_intro TRAINER_SABRINA_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blaine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Blaine_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Blaine_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Blaine_Rematch::
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine_PostOBC::
	trainerbattle_no_intro TRAINER_BLAINE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blue_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	goto_if_unset FLAG_IS_KANTO_CHAMPION, SaffronCity_FightingDojoVIP_EventScript_Blue_Rematch
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SaffronCity_FightingDojoVIP_EventScript_Blue_PostOBC

SaffronCity_FightingDojoVIP_EventScript_Blue_Rematch::
	trainerbattle_no_intro TRAINER_BLUE_HNS, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue_PostOBC::
	trainerbattle_no_intro TRAINER_BLUE_POSTOBC_HNS, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

@===============MONS===============================================================================================================

SaffronCity_FightingDojoVIP_EventScript_Scizor::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SCIZOR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Scizor, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Scizor:
#if GERMAN
	.string "Scherox: Schee-Rox!$"
#else
	.string "SCIZOR: Scii-zor!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Miltank:
#if GERMAN
	.string "Miltank: MuuhHho!$"
#else
	.string "MILTANK: MooOOO!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Poliwhirl::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWHIRL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Poliwhirl, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Poliwhirl:
#if GERMAN
	.string "Quaputzi: Whirl-whirl!$"
#else
	.string "POLIWHIRL: Whirl-whirl!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Dewgong:
#if GERMAN
	.string "Jugong: Goooooong!$"
#else
	.string "DEWGONG: Goooooong!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Steelix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Steelix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Steelix:
#if GERMAN
	.string "Stahlos: GraaAaank!$"
#else
	.string "STEELIX: GraaAAANk!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Kingdra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGDRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kingdra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kingdra:
#if GERMAN
	.string "Seedraking: Draaa…$"
#else
	.string "KINGDRA: Draaa...$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Onix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ONIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Onix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Onix:
#if GERMAN
	.string "Onix: Oooonix!$"
#else
	.string "ONIX: Oooonix!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Starmie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Starmie, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Starmie:
#if GERMAN
	.string "Starmie: Hyaaa!$"
#else
	.string "STARMIE: Hyaaa!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Victreebel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VICTREEBEL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Victreebel, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Victreebel:
#if GERMAN
	.string "Sarzenia: Vreeee!$"
#else
	.string "VICTREEBEL: Vreeee!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Muk::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Muk, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Muk:
#if GERMAN
	.string "Sleimok: Muuuk…$"
#else
	.string "MUK: Muuuk...$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Kadabra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KADABRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kadabra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kadabra:
#if GERMAN
	.string "Kadabra: Kadabra!$"
#else
	.string "KADABRA: Kadabra!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Magmar::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGMAR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Magmar, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Magmar:
#if GERMAN
	.string "Magmar: Magmaaaar!$"
#else
	.string "MAGMAR: Magmaaaar!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Raichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Raichu, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Raichu:
#if GERMAN
	.string "Raichu: Rai-Chu!$"
#else
	.string "RAICHU: Rai-CHU!$"
#endif

SaffronCity_FightingDojoVIP_EventScript_Machamp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Machamp, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Machamp:
#if GERMAN
	.string "Machomei: Maa-champ!$"
#else
	.string "MACHAMP: Maa-champ!$"
#endif

SaffronCity_FightingDojo_EventScript_Chased::
	msgbox SaffronCity_FightingDojoVIP_Text_Chased, MSGBOX_NPC
	end

SaffronCity_FightingDojoVIP_Text_Chased:
#if GERMAN
	.string "Help$"
#else
	.string "Help!$"
#endif

SaffronCity_FightingDojoVIP_EvetScript_Statue::
	msgbox SaffronCity_FightingDojoVIP_Text_Statue, MSGBOX_SIGN
	end

SaffronCity_FightingDojoVIP_Text_Statue:
#if GERMAN
	.string "Kampf-Dojo VIP Lounge$"
#else
	.string "FIGHTING DOJO VIP LOUNGE$"
#endif

SaffronCity_FightingDojoVIP_Text_Falkner_Rematch:
#if GERMAN
	.string "Glückwunsch zum Sieg gegen die Elite\n"
	.string "Vier!\p"
	.string "Ich hab meine Flug-Pokémon noch härter\n"
	.string "trainiert.\p"
	.string "Kannst du die Kraft des Himmels nochmal\n"
	.string "bezwingen?$"
#else
	.string "Congratulations on defeating\n"
	.string "the ELITE 4!\p"
	.string "I've been training my\n"
	.string "FLYING-type POKéMON even harder.\p"
	.string "Think you can take on the power\n"
	.string "of the skies again?$"
#endif

SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat:
#if GERMAN
	.string "Wow… Du hast mich wieder besiegt.\p"
	.string "Ich werde noch härter trainieren, um\n"
	.string "der größte Vogelmeister zu werden!$"
#else
	.string "Wow… You beat me again.\p"
	.string "I'm going to train harder to\n"
	.string "become the greatest bird master!$"
#endif

SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch:
#if GERMAN
	.string "Wow, du bist jetzt Johto-Champion!\p"
	.string "Deine Fähigkeiten sind wirklich\n"
	.string "beeindruckend!\p"
	.string "Ich war mit meiner Forschung\n"
	.string "beschäftigt.\p"
	.string "Ich zeige dir gern meine neuen\n"
	.string "Erkenntnisse.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "Wow, you're the JOHTO CHAMPION\n"
	.string "now!\p"
	.string "Your skills are truly impressive!\p"
	.string "I've been busy with my research.\p"
	.string "I'm ready to show you my new\n"
	.string "findings.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat:
#if GERMAN
	.string "Wow, du bist wirklich ein\n"
	.string "Experten-Trainer.\p"
	.string "Meine Forschung muss wohl noch nicht\n"
	.string "vollständig sein…$"
#else
	.string "Wow, you must be an expert\n"
	.string "trainer.\p"
	.string "My research must not be\n"
	.string "complete…$"
#endif

SaffronCity_FightingDojoVIP_Text_Whitney_Rematch:
#if GERMAN
	.string "Hey! Du bist’s!\p"
	.string "Wow, jetzt Johto-champion?\p"
	.string "Du bist wirklich toll!\p"
	.string "Ich will sehen, wie stark du bist.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "Hi! It's you!\p"
	.string "Wow, JOHTO CHAMPION now?\p"
	.string "You really are amazing!\p"
	.string "I want to see how strong you are.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat:
#if GERMAN
	.string "Bianka: Buhuhuhuuu!\p"
	.string "Buhuuuu! Schluchz!\p"
	.string "…Schnüff, schnief…\n"
	.string "…Du bist ja so gemein!!!$"
#else
	.string "Waaaaah!\p"
	.string "Waaaaah!\p"
	.string "…Snivel, hic… …You meanie!$"
#endif

SaffronCity_FightingDojoVIP_Text_Morty_Rematch:
#if GERMAN
	.string "Ah, der Johto-champion!\n"
	.string "Schön, dass du da bist.\p"
	.string "Du hast Stärke und Können bewiesen,\n"
	.string "aber hast du dich seit unserem letzten\l"
	.string "Kampf verbessert?\p"
	.string "Ich hab mit meinen Geist-Pokémon\n"
	.string "trainiert.\p"
	.string "Kannst du die Schatten nochmal\n"
	.string "überwinden?\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "Ah, the JOHTO CHAMPION! Good of\n"
	.string "you to come.\p"
	.string "You've shown your strength and\n"
	.string "skill, but have you improved\l"
	.string "since our last battle?\p"
	.string "I've been training with my\n"
	.string "GHOST-type POKéMON.\p"
	.string "Let's see if you can overcome\n"
	.string "the shadows once again.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat:
#if GERMAN
	.string "Ich bin noch nicht gut genug…\p"
	.string "Du hast viel mehr erlebt als ich.\p"
	.string "Darum beneide ich dich…$"
#else
	.string "I'm not good enough yet…\p"
	.string "You have witnessed much more\n"
	.string "than I.\p"
	.string "I envy you for that…$"
#endif

SaffronCity_FightingDojoVIP_Text_Chuck_Rematch:
#if GERMAN
	.string "Wahahah! Johto-champion!\p"
	.string "Du bist zurückgekommen!\p"
	.string "Deine Fähigkeiten haben sich\n"
	.string "verbessert!\p"
	.string "Bereit zu sehen, wer stärker ist?$"
#else
	.string "WAHAHAH! JOHTO CHAMPION!\p"
	.string "You've come back for more!\p"
	.string "I see your skills have improved!\p"
	.string "Ready to see who's stronger?$"
#endif

SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat:
#if GERMAN
	.string "Was? Wie? Ich hab verloren?\n"
	.string "Schon wieder?$"
#else
	.string "Wha? Huh? I lost? Again?$"
#endif

SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch:
#if GERMAN
	.string "…Herzlichen Glückwunsch,\n"
	.string "Johto-champion.\p"
	.string "Du bist so stark geworden…\p"
	.string "Ich frage mich, ob ich mich verbessert\n"
	.string "habe.\p"
	.string "Möchtest du das testen?\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "…Congratulations, JOHTO\n"
	.string "CHAMPION.\p"
	.string "You have become so strong…\p"
	.string "I wonder if I have improved.\p"
	.string "Would you like to test that?\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat:
#if GERMAN
	.string "…Du bist ein besserer Trainer\n"
	.string "als ich,\p"
	.string "sowohl im Können als auch in der Güte.$"
#else
	.string "…You are a better trainer than\n"
	.string "me,\p"
	.string "in both skill and kindness.$"
#endif

SaffronCity_FightingDojoVIP_Text_Pryce_Rematch:
#if GERMAN
	.string "Ah, Johto-champion!\p"
	.string "Deine Fähigkeiten sind wirklich\n"
	.string "bemerkenswert.\p"
	.string "Ich bin beeindruckt.\p"
	.string "Doch auch jetzt können wir noch\n"
	.string "voneinander lernen.\p"
	.string "Ich, Preis - der Winter-Trainer - hab\n"
	.string "noch Tricks.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "Ah, JOHTO CHAMPION!\p"
	.string "Your skills are indeed\n"
	.string "remarkable.\p"
	.string "I am impressed.\p"
	.string "But even now, there is much to\n"
	.string "learn from each other.\p"
	.string "I, PRYCE--the winter trainer--\p"
	.string "still have a few tricks left.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat:
#if GERMAN
	.string "Norbert: Hm, dein Können hat mich\n"
	.string "schwer beeindruckt.\p"
	.string "Mit deinem starken Willen wirst du alle\n"
	.string "Widrigkeiten dieses Lebens mühelos\l"
	.string "überstehen.\p"
	.string "Du bist dieses Ordens würdig!$"
#else
	.string "Ah, yet again I'm impressed by\n"
	.string "your prowess.\p"
	.string "With your strong will, I know\n"
	.string "you will overcome all life's\l"
	.string "obstacles.$"
#endif

SaffronCity_FightingDojoVIP_Text_Clair_Rematch:
#if GERMAN
	.string "Du hast es also geschafft?\p"
	.string "Du bist jetzt Johto-champion.\p"
	.string "Du hast deine Stärke bewiesen, aber\n"
	.string "kannst du mich nochmal bezwingen?\p"
	.string "Als Drachenmeisterin werde ich nicht\n"
	.string "zurückhalten.\p"
	.string "Diesmal nicht.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "You did it, huh?\p"
	.string "You are now the JOHTO CHAMP.\p"
	.string "You've proven your strength but\n"
	.string "can you handle me again?\p"
	.string "As a Dragon Master, I won't hold\n"
	.string "back.\p"
	.string "Not this time.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat:
#if GERMAN
	.string "Ich soll verloren haben?\p"
	.string "Ich will das einfach nicht glauben.\n"
	.string "Das muss ein Irrtum sein…$"
#else
	.string "I lost?\p"
	.string "Again?\p"
	.string "I don't believe it. There must\n"
	.string "be some mistake…$"
#endif

SaffronCity_FightingDojoVIP_Text_Brock_Rematch:
#if GERMAN
	.string "Rocko: Hey, {PLAYER}!\p"
	.string "Ich hab gehört, du bist jetzt\n"
	.string "Kanto-champion.\p"
	.string "Das ist unglaublich!\p"
	.string "Du musst jetzt noch stärker sein.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "BROCK: Hey there, {PLAYER}!\p"
	.string "I heard you are now the KANTO\n"
	.string "CHAMPION.\p"
	.string "That's incredible!\p"
	.string "You must be even stronger now.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat:
#if GERMAN
	.string "Rocko: Deine Pokémon haben meine\n"
	.string "felsenharte Verteidigung wieder\l"
	.string "gebrochen…$"
#else
	.string "BROCK: Your POKéMON once again\n"
	.string "overcame my rock-hard defense…$"
#endif

SaffronCity_FightingDojoVIP_Text_Misty_Rematch:
#if GERMAN
	.string "Misty: Wow, du bist jetzt\n"
	.string "Kanto-champion!\p"
	.string "Toll! Du hast einen langen Weg hinter\n"
	.string "dir, {PLAYER}.\p"
	.string "Aber ich gebe nicht auf.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "MISTY: Wow, you're the KANTO\n"
	.string "CHAMPION now!\p"
	.string "That's amazing! You've come a\n"
	.string "long way, {PLAYER}.\p"
	.string "But I'm not backing down.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat:
#if GERMAN
	.string "Misty: Du bist wirklich gut…$"
#else
	.string "MISTY: You really are good…$"
#endif

SaffronCity_FightingDojoVIP_Text_Surge_Rematch:
#if GERMAN
	.string "Bob: Also, du bist jetzt\n"
	.string "Kanto-champion!\p"
	.string "Beeindruckend, Kid! Aber denk\n"
	.string "nicht, ich bin fertig!\p"
	.string "Wie wär’s mit einer Revanche?$"
#else
	.string "SURGE: So, you're now KANTO\n"
	.string "CHAMPION!\p"
	.string "Impressive work, kid! But don't\n"
	.string "think I'm done!\p"
	.string "How about we have a go again?$"
#endif

SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat:
#if GERMAN
	.string "Bob: Arrgh! Du bist immer noch genauso\n"
	.string "stark!$"
#else
	.string "SURGE: Arrrgh! You're still just\n"
	.string "as strong!$"
#endif

SaffronCity_FightingDojoVIP_Text_Erika_Rematch:
#if GERMAN
	.string "Erika: Oh, hallo.\p"
	.string "Was für eine Überraschung, Champion!\p"
	.string "Wie schön, dich wiederzusehen.\p"
	.string "Deine Reise muss sehr aufregend\n"
	.string "gewesen sein.\p"
	.string "Auch Champions mögen\n"
	.string "Herausforderungen.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "ERIKA: Oh, hello.\p"
	.string "What a surprise, CHAMPION!\p"
	.string "It's so lovely to see you again.\p"
	.string "Your journey must have been so\n"
	.string "exciting.\p"
	.string "Even champions enjoy a challenge.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat:
#if GERMAN
	.string "Erika: Niemand verliert gerne…\p"
	.string "Aber es wirkt immer anspornend, wenn\n"
	.string "man einem starken Trainer begegnet.$"
#else
	.string "ERIKA: Losing still leaves a\n"
	.string "bitter aftertaste…\p"
	.string "But knowing that there are strong\n"
	.string "trainers spurs me to do better…$"
#endif

SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch:
#if GERMAN
	.string "Sabrina: Ah, der Champion.\p"
	.string "Ich spürte deine Rückkehr.\p"
	.string "Deine Kraft ist enorm gewachsen.\p"
	.string "Selbst jetzt spüre ich deine Aura.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "SABRINA: Ah, the CHAMPION.\p"
	.string "I sensed your return.\p"
	.string "Your power has grown immensely.\p"
	.string "Even now, I feel your aura.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat:
#if GERMAN
	.string "Sabrina: Deine Liebe zu deinen Pokémon\n"
	.string "hat meine Psychokraft wieder\l"
	.string "überwältigt…$"
#else
	.string "SABRINA: Your love for your\n"
	.string "POKéMON again overwhelmed my\l"
	.string "psychic power…$"
#endif

SaffronCity_FightingDojoVIP_Text_Janine_Rematch:
#if GERMAN
	.string "Fufufufu…\p"
	.string "Wow, du hast es geschafft!\p"
	.string "Du bist jetzt Champion!\p"
	.string "Ich bin so stolz auf dich!\n"
	.string "Aber ich zeig keine Gnade.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "Fufufufu…\p"
	.string "Wow, you did it!\p"
	.string "You're the CHAMPION now!\p"
	.string "I'm so proud of you! But don't\n"
	.string "think I'll go easy on you.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat:
#if GERMAN
	.string "Janine: Du bist immer noch genauso\n"
	.string "stark!\p"
	.string "Du hast eindeutig gewonnen…$"
#else
	.string "JANINE: You're still just as\n"
	.string "tough!\p"
	.string "You definitely won…$"
#endif

SaffronCity_FightingDojoVIP_Text_Blaine_Rematch:
#if GERMAN
	.string "Pyro: Whoa!\p"
	.string "Du bist jetzt Kanto-Champion!\p"
	.string "Das ist brennend heiß!\p"
	.string "Deine Fähigkeiten sind erstklassig.\p"
	.string "Ich bin immer kampfbereit.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "BLAINE: Whoa!\p"
	.string "I see you've become the KANTO\n"
	.string "CHAMPION!\p"
	.string "That's blazing!\p"
	.string "Your skills are top-notch.\p"
	.string "I'm always up for a battle.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat:
#if GERMAN
	.string "Pyro: Deine Fähigkeiten sind wirklich\n"
	.string "feurig!\p"
	.string "Du hast meine Verteidigung\n"
	.string "niedergebrannt.$"
#else
	.string "BLAINE: Your skills are truly\n"
	.string "fiery!\p"
	.string "You've burned right through my\n"
	.string "defenses.$"
#endif

SaffronCity_FightingDojoVIP_Text_Blue_Rematch:
#if GERMAN
	.string "Blau: Na, na. Champion!\p"
	.string "Du hast einen langen Weg hinter dir.\p"
	.string "Ich hatte diesen Titel auch mal. Aber\n"
	.string "ich zeig keine Gnade.\p"
	.string "Mal sehen, ob du’s hältst.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "BLUE: Well, well. CHAMPION!\p"
	.string "Looks like you've come a long way.\p"
	.string "I used to have that title too,\n"
	.string "you know. But I won't go easy.\p"
	.string "Let's see if you can keep it up.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat:
#if GERMAN
	.string "Blau: Was?\p"
	.string "Wie hab ich schon wieder verloren?$"
#else
	.string "BLUE: What?\p"
	.string "How the heck did I lose again?$"
#endif

