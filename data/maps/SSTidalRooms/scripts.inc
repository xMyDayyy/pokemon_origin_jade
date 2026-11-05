SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem_unless_owned ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	@ Pokemon Center challenge: no rest and no heal.
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSTidalRooms_EventScript_Bed_PokecenterChallenge
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Bed_PokecenterChallenge::
	msgbox SSTidalRooms_Text_TakeRestOnBed_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	release
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed_PokecenterChallenge:
#if GERMAN
	.string "Sorry, du machst gerade die\n"
	.string "Pokécenter-Challenge!$"
#else
	.string "Sorry, you are playing with\n"
	.string "the POKéCENTER challenge!$"
#endif

SSTidalRooms_Text_TakeRestOnBed:
#if GERMAN
	.string "Da steht ein Bett…\n"
	.string "Eine Pause wäre willkommen.$"
#else
	.string "There's a bed…\n"
	.string "Let's take a rest.$"
#endif

SSTidalRooms_Text_ColtonIntro:
#if GERMAN
	.string "Ich segle oft nach Seegrasulb City.\p"
	.string "Ich liebe es, an den Wettbewerben\n"
	.string "teilzunehmen.$"
#else
	.string "I often sail to LILYCOVE CITY.\p"
	.string "I enjoy attending CONTESTS,\n"
	.string "you see.$"
#endif

SSTidalRooms_Text_ColtonDefeat:
#if GERMAN
	.string "Das war ein wunderbarer Kampf!$"
#else
	.string "That was an enjoyable match!$"
#endif

SSTidalRooms_Text_ColtonPostBattle:
#if GERMAN
	.string "Ich bin schon ganz aufgeregt, wenn ich\n"
	.string "mir vorstelle, welche Pokémon ich im\l"
	.string "nächsten Wettbewerb sehen werde!$"
#else
	.string "I get so excited imagining what kinds\n"
	.string "of POKéMON I'll get to see in the next\l"
	.string "CONTEST. The anticipation of it thrills!$"
#endif

SSTidalRooms_Text_MicahIntro:
#if GERMAN
	.string "Sind deine Freunde stark?$"
#else
	.string "Are your friends strong?$"
#endif

SSTidalRooms_Text_MicahDefeat:
#if GERMAN
	.string "Deine Freunde sind in der Tat stark.$"
#else
	.string "Your friends are, indeed, strong.$"
#endif

SSTidalRooms_Text_MicahPostBattle:
#if GERMAN
	.string "Freunde müssen nicht unbedingt\n"
	.string "menschlich sein. Für mich sind Pokémon\l"
	.string "die besten Freunde.$"
#else
	.string "Friends need not be human.\n"
	.string "For me, POKéMON are treasured friends!$"
#endif

SSTidalRooms_Text_ThomasIntro:
#if GERMAN
	.string "Kind… Hast du an der Tür geklopft?$"
#else
	.string "Child…\n"
	.string "Did you knock on the door?$"
#endif

SSTidalRooms_Text_ThomasDefeat:
#if GERMAN
	.string "Eine Niederlage muss mit erhobenem\n"
	.string "Haupt akzeptiert werden.$"
#else
	.string "A loss is to be accepted without haste\n"
	.string "or panic.$"
#endif

SSTidalRooms_Text_ThomasPostBattle:
#if GERMAN
	.string "In jeder Situation die absolute Ruhe zu\n"
	.string "bewahren, ist die Devise des Gentleman.$"
#else
	.string "To be never ruffled in any situation is\n"
	.string "the GENTLEMAN's code of conduct.$"
#endif

SSTidalRooms_Text_JedIntro:
#if GERMAN
	.string "Uwe: Eigentlich bin ich ja schüchtern…\n"
	.string "Aber die Liebe gibt einem Kraft!$"
#else
	.string "JED: I feel a little shy about this, but…\n"
	.string "We'll show you our lovey-dovey power!$"
#endif

SSTidalRooms_Text_JedDefeat:
#if GERMAN
	.string "Uwe: Seufz…$"
#else
	.string "JED: Sigh…$"
#endif

SSTidalRooms_Text_JedPostBattle:
#if GERMAN
	.string "Uwe: Zum ersten Mal war unsere Kraft\n"
	.string "der Liebe unterlegen!\l"
	.string "Du bist ein unglaublicher Trainer!$"
#else
	.string "JED: It's the first time that our lovey-\n"
	.string "dovey power couldn't prevail!\l"
	.string "You must be an awesome TRAINER!$"
#endif

SSTidalRooms_Text_JedNotEnoughMons:
#if GERMAN
	.string "Uwe: Du hast nur ein Pokémon?\n"
	.string "Fühlt es sich nicht sehr einsam?$"
#else
	.string "JED: You only have one POKéMON?\n"
	.string "Isn't that just too lonesome?$"
#endif

SSTidalRooms_Text_LeaIntro:
#if GERMAN
	.string "Lena: Ich fühle mich etwas albern,\n"
	.string "aber… Aber die Liebe gibt mir Kraft!$"
#else
	.string "LEA: I feel a little silly, but…\n"
	.string "We'll show you our lovey-dovey power!$"
#endif

SSTidalRooms_Text_LeaDefeat:
#if GERMAN
	.string "Lena: Oh, buuuuh!$"
#else
	.string "LEA: Oh, boo!$"
#endif

SSTidalRooms_Text_LeaPostBattle:
#if GERMAN
	.string "Lena: Ich kann es einfach nicht fassen!\n"
	.string "Die Kraft unserer Liebe reichte nicht…\l"
	.string "Du bist ein unglaublicher Trainer!$"
#else
	.string "LEA: I can't believe it!\n"
	.string "Our lovey-dovey power failed…\l"
	.string "You must be an awesome TRAINER!$"
#endif

SSTidalRooms_Text_LeaNotEnoughMons:
#if GERMAN
	.string "Lena: Ich möchte kämpfen…\n"
	.string "Aber du hast nur ein Pokémon…$"
#else
	.string "LEA: I wanted to battle…\n"
	.string "But you don't even have two POKéMON…$"
#endif

SSTidalRooms_Text_GarretIntro:
#if GERMAN
	.string "Ah, du kommst gerade rechtzeitig.\p"
	.string "Ich langweile mich schrecklich.\n"
	.string "Du musst mich jetzt unterhalten.$"
#else
	.string "Ah, you've come just in time.\p"
	.string "I'm bored, you see.\n"
	.string "You may entertain me.$"
#endif

SSTidalRooms_Text_GarretDefeat:
#if GERMAN
	.string "… Das reicht.$"
#else
	.string "…That will do.$"
#endif

SSTidalRooms_Text_GarretPostBattle:
#if GERMAN
	.string "Ich muss meinen Vater unbedingt\n"
	.string "fragen, ob er mir eine Yacht schenkt.\l"
	.string "Eine Yacht für mich und meine Pokémon!$"
#else
	.string "Perhaps I shall get Father to acquire\n"
	.string "a yacht for me.\l"
	.string "A yacht for me and POKéMON!$"
#endif

SSTidalRooms_Text_NaomiIntro:
#if GERMAN
	.string "Oh, du bist so ein wunderbarer Trainer.\n"
	.string "Möchtest du eine Tasse Tee?\l"
	.string "Oder möchtest du lieber kämpfen?$"
#else
	.string "Oh, you're such an adorable TRAINER.\n"
	.string "Would you like to have tea?\l"
	.string "Or would you rather battle?$"
#endif

SSTidalRooms_Text_NaomiDefeat:
#if GERMAN
	.string "Ich verstehe.\n"
	.string "Du bist eher der aktive Typ.$"
#else
	.string "I see.\n"
	.string "You're the active sort.$"
#endif

SSTidalRooms_Text_NaomiPostBattle:
#if GERMAN
	.string "Eine Weltreise auf einem Luxusliner hat\n"
	.string "etwas für sich, das muss ich sagen…\p"
	.string "Aber auch eine Fahrt auf der Fähre\n"
	.string "durch Hoenn hat etwas.$"
#else
	.string "A world cruise on a luxury liner has its\n"
	.string "charms, I must say…\p"
	.string "But, I will admit there is an appealing\n"
	.string "side to touring HOENN by ferry.$"
#endif

SSTidalRooms_Text_NotSuspiciousTakeThis:
#if GERMAN
	.string "Äh… Hallo! Ich… Ich verhalte mich\n"
	.string "überhaupt nicht verdächtig! Äh… hier,\l"
	.string "das ist für dich! Es kostet dich nichts!\p"
	.string "Es… Ehrlich! Ich habe es nicht von\n"
	.string "jemandem Übernommen! Das würde ich nie\l"
	.string "tun! Es ist sauber! Nimm es ruhig!$"
#else
	.string "Uh… Hi! I… I'm not acting suspicious!\n"
	.string "Uh… You can have this! For free!\p"
	.string "It… Honestly, I didn't SNATCH it from\n"
	.string "someone! I'd never do such a thing!\l"
	.string "It's clean! You can use it!$"
#endif

SSTidalRooms_Text_ExplainSnatch:
#if GERMAN
	.string "Übernahme raubt die nächste Attacke\n"
	.string "eines Pokémon und setzt sie dann gegen\l"
	.string "diesen Gegner ein.$"
#else
	.string "SNATCH steals the beneficial effects\n"
	.string "of certain moves before they can be\l"
	.string "used by a foe or ally.$"
#endif

